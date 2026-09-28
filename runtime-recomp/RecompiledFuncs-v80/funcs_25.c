#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void update_tricky(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C364: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005C368: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005C36C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005C370: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005C374: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005C378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005C37C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005C380: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005C384: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005C388: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005C38C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005C390: jal         0x8005CA78
    // 0x8005C394: addiu       $a0, $a0, -0x3220
    ctx->r4 = ADD32(ctx->r4, -0X3220);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005C394: addiu       $a0, $a0, -0x3220
    ctx->r4 = ADD32(ctx->r4, -0X3220);
    after_0:
    // 0x8005C398: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005C39C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C3A0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005C3A4: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005C3A8: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005C3AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C3B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005C3B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C3B8: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005C3BC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005C3C0: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C3C4: nop

    // 0x8005C3C8: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005C3CC: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005C3D0: nop

    // 0x8005C3D4: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005C3D8: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005C3DC: nop

    // 0x8005C3E0: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005C3E4: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C3E8: nop

    // 0x8005C3EC: bne         $t5, $at, L_8005C410
    if (ctx->r13 != ctx->r1) {
        // 0x8005C3F0: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005C410;
    }
    // 0x8005C3F0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C3F4: jal         0x80021400
    // 0x8005C3F8: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005C3F8: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005C3FC: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C400: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C404: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005C408: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005C40C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005C410:
    // 0x8005C410: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005C414: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005C418: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C41C: bne         $t0, $t8, L_8005C494
    if (ctx->r8 != ctx->r24) {
        // 0x8005C420: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005C494;
    }
    // 0x8005C420: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005C424: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005C428: beq         $v0, $at, L_8005C494
    if (ctx->r2 == ctx->r1) {
        // 0x8005C42C: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005C494;
    }
    // 0x8005C42C: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005C430: bgez        $t9, L_8005C48C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005C434: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005C48C;
    }
    // 0x8005C434: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C438: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005C43C: lb          $t3, -0x2A34($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2A34);
    // 0x8005C440: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C444: bne         $t3, $zero, L_8005C46C
    if (ctx->r11 != 0) {
        // 0x8005C448: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005C46C;
    }
    // 0x8005C448: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C44C: jal         0x8005CB04
    // 0x8005C450: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005C450: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005C454: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C458: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C45C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C460: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005C464: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005C468: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005C46C:
    // 0x8005C46C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C470: sb          $t5, -0x2A34($at)
    MEM_B(-0X2A34, ctx->r1) = ctx->r13;
    // 0x8005C474: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005C478: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005C47C: nop

    // 0x8005C480: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005C484: b           L_8005C494
    // 0x8005C488: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005C494;
    // 0x8005C488: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005C48C:
    // 0x8005C48C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C490: sb          $zero, -0x2A34($at)
    MEM_B(-0X2A34, ctx->r1) = 0;
L_8005C494:
    // 0x8005C494: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005C498: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005C49C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005C4A0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005C4A4: jal         0x8004F7F4
    // 0x8005C4A8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005C4A8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005C4AC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C4B0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C4B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C4B8: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005C4BC: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005C4C0: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005C4C4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C4C8: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005C4CC: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005C4D0: nop

    // 0x8005C4D4: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005C4D8: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005C4DC: nop

    // 0x8005C4E0: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005C4E4: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005C4E8: nop

    // 0x8005C4EC: beq         $t3, $zero, L_8005C578
    if (ctx->r11 == 0) {
        // 0x8005C4F0: nop
    
            goto L_8005C578;
    }
    // 0x8005C4F0: nop

    // 0x8005C4F4: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C4F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C4FC: beq         $a1, $v1, L_8005C578
    if (ctx->r5 == ctx->r3) {
        // 0x8005C500: lui         $at, 0x401E
        ctx->r1 = S32(0X401E << 16);
            goto L_8005C578;
    }
    // 0x8005C500: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005C504: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005C508: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005C50C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005C510: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C514: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C518: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005C51C: sb          $a1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r5;
    // 0x8005C520: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005C528: jal         0x8005CB04
    // 0x8005C52C: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005C52C: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005C530: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005C534: jal         0x80001D04
    // 0x8005C538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005C538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005C53C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005C540: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005C544: jal         0x80069F28
    // 0x8005C548: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005C548: nop

    after_6:
    // 0x8005C54C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C550: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C554: lwc1        $f9, 0x6A10($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A10);
    // 0x8005C558: lwc1        $f8, 0x6A14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A14);
    // 0x8005C55C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C560: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005C564: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C568: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C56C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005C570: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C574: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005C578:
    // 0x8005C578: lw          $t4, 0x148($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X148);
    // 0x8005C57C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C580: beq         $t4, $zero, L_8005C5C8
    if (ctx->r12 == 0) {
        // 0x8005C584: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005C5C8;
    }
    // 0x8005C584: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005C588: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005C58C: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005C590: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C594: nop

    // 0x8005C598: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C59C: nop

    // 0x8005C5A0: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005C5A4: nop

    // 0x8005C5A8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005C5AC: jal         0x800C9AD0
    // 0x8005C5B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005C5B0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005C5B4: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005C5B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C5BC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005C5C0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C5C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8005C5C8:
    // 0x8005C5C8: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x8005C5CC: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C5D0: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8005C5D4: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8005C5D8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005C5DC: nop

    // 0x8005C5E0: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8005C5E4: nop

    // 0x8005C5E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005C5EC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005C5F0: nop

    // 0x8005C5F4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005C5F8: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005C5FC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8005C600: beq         $a1, $v1, L_8005C6F0
    if (ctx->r5 == ctx->r3) {
        // 0x8005C604: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005C6F0;
    }
    // 0x8005C604: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005C608: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C60C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005C610: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C614: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C618: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8005C61C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005C620: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005C624: bc1f        L_8005C668
    if (!c1cs) {
        // 0x8005C628: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005C668;
    }
    // 0x8005C628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C62C: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005C630: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C634: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C638: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005C63C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005C640: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C644: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C648: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C64C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005C650: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005C654: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C658: sub.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d - ctx->f6.d;
    // 0x8005C65C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C660: b           L_8005C710
    // 0x8005C664: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C710;
    // 0x8005C664: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C668:
    // 0x8005C668: lwc1        $f9, 0x6A18($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A18);
    // 0x8005C66C: lwc1        $f8, 0x6A1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A1C);
    // 0x8005C670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C674: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005C678: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005C67C: bc1t        L_8005C6A0
    if (c1cs) {
        // 0x8005C680: nop
    
            goto L_8005C6A0;
    }
    // 0x8005C680: nop

    // 0x8005C684: lwc1        $f11, 0x6A20($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A20);
    // 0x8005C688: lwc1        $f10, 0x6A24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A24);
    // 0x8005C68C: nop

    // 0x8005C690: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005C694: nop

    // 0x8005C698: bc1f        L_8005C6CC
    if (!c1cs) {
        // 0x8005C69C: nop
    
            goto L_8005C6CC;
    }
    // 0x8005C69C: nop

L_8005C6A0:
    // 0x8005C6A0: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005C6A4: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C6A8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C6AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C6B0: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005C6B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005C6B8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C6BC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005C6C0: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005C6C4: b           L_8005C710
    // 0x8005C6C8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005C710;
    // 0x8005C6C8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005C6CC:
    // 0x8005C6CC: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005C6D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C6D4: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C6D8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C6DC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C6E0: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005C6E4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C6E8: b           L_8005C710
    // 0x8005C6EC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C710;
    // 0x8005C6EC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C6F0:
    // 0x8005C6F0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C6F4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C6F8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C6FC: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8005C700: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C704: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005C708: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005C70C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005C710:
    // 0x8005C710: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C714: nop

    // 0x8005C718: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C71C: nop

    // 0x8005C720: bc1f        L_8005C74C
    if (!c1cs) {
        // 0x8005C724: nop
    
            goto L_8005C74C;
    }
    // 0x8005C724: nop

L_8005C728:
    // 0x8005C728: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005C72C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005C730: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C734: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C738: nop

    // 0x8005C73C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C740: nop

    // 0x8005C744: bc1t        L_8005C728
    if (c1cs) {
        // 0x8005C748: nop
    
            goto L_8005C728;
    }
    // 0x8005C748: nop

L_8005C74C:
    // 0x8005C74C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C750: nop

    // 0x8005C754: bc1f        L_8005C780
    if (!c1cs) {
        // 0x8005C758: nop
    
            goto L_8005C780;
    }
    // 0x8005C758: nop

L_8005C75C:
    // 0x8005C75C: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005C760: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005C764: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C768: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C76C: nop

    // 0x8005C770: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C774: nop

    // 0x8005C778: bc1t        L_8005C75C
    if (c1cs) {
        // 0x8005C77C: nop
    
            goto L_8005C75C;
    }
    // 0x8005C77C: nop

L_8005C780:
    // 0x8005C780: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005C784: nop

    // 0x8005C788: bne         $t0, $t6, L_8005C7B4
    if (ctx->r8 != ctx->r14) {
        // 0x8005C78C: nop
    
            goto L_8005C7B4;
    }
    // 0x8005C78C: nop

    // 0x8005C790: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C794: nop

    // 0x8005C798: bne         $a1, $t7, L_8005C7B4
    if (ctx->r5 != ctx->r15) {
        // 0x8005C79C: nop
    
            goto L_8005C7B4;
    }
    // 0x8005C79C: nop

    // 0x8005C7A0: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005C7A4: nop

    // 0x8005C7A8: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005C7AC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C7B0: nop

L_8005C7B4:
    // 0x8005C7B4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005C7B8: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    // 0x8005C7BC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005C7C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005C7C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005C7C8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8005C7CC: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005C7D0: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C7D4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8005C7D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C7DC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005C7E0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005C7E4: bne         $t4, $at, L_8005C818
    if (ctx->r12 != ctx->r1) {
        // 0x8005C7E8: sh          $t3, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r11;
            goto L_8005C818;
    }
    // 0x8005C7E8: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005C7EC: lh          $a2, 0x54($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X54);
    // 0x8005C7F0: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005C7F4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005C7F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C7FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005C800: jal         0x800113CC
    // 0x8005C804: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_8;
    // 0x8005C804: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_8:
    // 0x8005C808: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8005C80C: nop

    // 0x8005C810: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8005C814: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_8005C818:
    // 0x8005C818: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005C81C: jal         0x800AFC3C
    // 0x8005C820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x8005C820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8005C824: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005C82C: jal         0x8005D048
    // 0x8005C830: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005C830: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_10:
    // 0x8005C834: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C83C: beq         $v0, $at, L_8005C858
    if (ctx->r2 == ctx->r1) {
        // 0x8005C840: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005C858;
    }
    // 0x8005C840: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005C848: beq         $v0, $at, L_8005C860
    if (ctx->r2 == ctx->r1) {
        // 0x8005C84C: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005C860;
    }
    // 0x8005C84C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005C850: b           L_8005C860
    // 0x8005C854: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005C860;
    // 0x8005C854: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005C858:
    // 0x8005C858: b           L_8005C860
    // 0x8005C85C: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005C860;
    // 0x8005C85C: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005C860:
    // 0x8005C860: jal         0x8001BAC8
    // 0x8005C864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_11;
    // 0x8005C864: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8005C868: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005C86C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005C870: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005C874: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005C878: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005C87C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005C880: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005C884: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005C888: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005C88C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005C890: jal         0x800C9AD0
    // 0x8005C894: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x8005C894: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_12:
    // 0x8005C898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C89C: lwc1        $f9, 0x6A28($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A28);
    // 0x8005C8A0: lwc1        $f8, 0x6A2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A2C);
    // 0x8005C8A4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005C8A8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005C8AC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005C8B0: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005C8B4: bc1f        L_8005C930
    if (!c1cs) {
        // 0x8005C8B8: nop
    
            goto L_8005C930;
    }
    // 0x8005C8B8: nop

    // 0x8005C8BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005C8C0: jal         0x80070750
    // 0x8005C8C4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x8005C8C4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_13:
    // 0x8005C8C8: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x8005C8CC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005C8D0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005C8D4: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x8005C8D8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005C8DC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005C8E0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005C8E4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005C8E8: bne         $at, $zero, L_8005C8FC
    if (ctx->r1 != 0) {
        // 0x8005C8EC: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005C8FC;
    }
    // 0x8005C8EC: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005C8F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005C8F4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005C8F8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005C8FC:
    // 0x8005C8FC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005C900: beq         $at, $zero, L_8005C90C
    if (ctx->r1 == 0) {
        // 0x8005C904: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005C90C;
    }
    // 0x8005C904: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005C908: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005C90C:
    // 0x8005C90C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005C910: beq         $at, $zero, L_8005C920
    if (ctx->r1 == 0) {
        // 0x8005C914: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005C920;
    }
    // 0x8005C914: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005C918: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005C91C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005C920:
    // 0x8005C920: beq         $at, $zero, L_8005C92C
    if (ctx->r1 == 0) {
        // 0x8005C924: nop
    
            goto L_8005C92C;
    }
    // 0x8005C924: nop

    // 0x8005C928: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005C92C:
    // 0x8005C92C: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005C930:
    // 0x8005C930: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C938: bne         $t2, $at, L_8005C968
    if (ctx->r10 != ctx->r1) {
        // 0x8005C93C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8005C968;
    }
    // 0x8005C93C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005C940: lb          $t3, 0x1E7($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005C944: nop

    // 0x8005C948: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x8005C94C: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8005C950: beq         $at, $zero, L_8005C96C
    if (ctx->r1 == 0) {
        // 0x8005C954: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005C96C;
    }
    // 0x8005C954: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005C958: lh          $t5, 0x16C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X16C);
    // 0x8005C95C: nop

    // 0x8005C960: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005C964: sh          $t6, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r14;
L_8005C968:
    // 0x8005C968: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005C96C:
    // 0x8005C96C: addiu       $v0, $v0, -0x2A40
    ctx->r2 = ADD32(ctx->r2, -0X2A40);
    // 0x8005C970: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005C974: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005C978: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005C97C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005C980: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005C984: bc1f        L_8005C99C
    if (!c1cs) {
        // 0x8005C988: lui         $at, 0x4079
        ctx->r1 = S32(0X4079 << 16);
            goto L_8005C99C;
    }
    // 0x8005C988: lui         $at, 0x4079
    ctx->r1 = S32(0X4079 << 16);
    // 0x8005C98C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8005C990: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005C994: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005C998: nop

L_8005C99C:
    // 0x8005C99C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005C9A0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005C9A4: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005C9A8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8005C9AC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005C9B0: nop

    // 0x8005C9B4: bc1f        L_8005C9F4
    if (!c1cs) {
        // 0x8005C9B8: nop
    
            goto L_8005C9F4;
    }
    // 0x8005C9B8: nop

    // 0x8005C9BC: jal         0x800C018C
    // 0x8005C9C0: nop

    check_fadeout_transition(rdram, ctx);
        goto after_14;
    // 0x8005C9C0: nop

    after_14:
    // 0x8005C9C4: bne         $v0, $zero, L_8005C9E4
    if (ctx->r2 != 0) {
        // 0x8005C9C8: nop
    
            goto L_8005C9E4;
    }
    // 0x8005C9C8: nop

    // 0x8005C9CC: jal         0x8009EC80
    // 0x8005C9D0: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_15;
    // 0x8005C9D0: nop

    after_15:
    // 0x8005C9D4: beq         $v0, $zero, L_8005C9E4
    if (ctx->r2 == 0) {
        // 0x8005C9D8: nop
    
            goto L_8005C9E4;
    }
    // 0x8005C9D8: nop

    // 0x8005C9DC: jal         0x8006F398
    // 0x8005C9E0: nop

    swap_lead_player(rdram, ctx);
        goto after_16;
    // 0x8005C9E0: nop

    after_16:
L_8005C9E4:
    // 0x8005C9E4: jal         0x8006F140
    // 0x8005C9E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005C9E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8005C9EC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005C9F0: nop

L_8005C9F4:
    // 0x8005C9F4: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005C9F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005C9FC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8005CA00: addiu       $a1, $a1, -0x2A3C
    ctx->r5 = ADD32(ctx->r5, -0X2A3C);
    // 0x8005CA04: bne         $s1, $t7, L_8005CA34
    if (ctx->r17 != ctx->r15) {
        // 0x8005CA08: nop
    
            goto L_8005CA34;
    }
    // 0x8005CA08: nop

    // 0x8005CA0C: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8005CA10: nop

    // 0x8005CA14: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8005CA18: beq         $t9, $zero, L_8005CA34
    if (ctx->r25 == 0) {
        // 0x8005CA1C: nop
    
            goto L_8005CA34;
    }
    // 0x8005CA1C: nop

    // 0x8005CA20: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005CA24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CA28: bne         $t2, $at, L_8005CA34
    if (ctx->r10 != ctx->r1) {
        // 0x8005CA2C: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005CA34;
    }
    // 0x8005CA2C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005CA30: sb          $t3, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r11;
L_8005CA34:
    // 0x8005CA34: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005CA38: nop

    // 0x8005CA3C: beq         $t4, $zero, L_8005CA60
    if (ctx->r12 == 0) {
        // 0x8005CA40: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005CA60;
    }
    // 0x8005CA40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CA44: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8005CA48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005CA4C: bne         $t5, $zero, L_8005CA5C
    if (ctx->r13 != 0) {
        // 0x8005CA50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005CA5C;
    }
    // 0x8005CA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CA54: jal         0x8005CB68
    // 0x8005CA58: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    racer_boss_finish(rdram, ctx);
        goto after_18;
    // 0x8005CA58: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    after_18:
L_8005CA5C:
    // 0x8005CA5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005CA60:
    // 0x8005CA60: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005CA64: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005CA68: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005CA6C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005CA70: jr          $ra
    // 0x8005CA74: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005CA74: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void set_collision_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ACCC: jr          $ra
    // 0x8002ACD0: sw          $a0, -0x4F0C($at)
    MEM_W(-0X4F0C, ctx->r1) = ctx->r4;
    return;
    // 0x8002ACD0: sw          $a0, -0x4F0C($at)
    MEM_W(-0X4F0C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void charselect_pick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4C8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008B4CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B4D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B4D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B4D8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008B4DC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008B4E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B4E4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B4E8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B4EC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B4F0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B4F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B4F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B500: addiu       $s4, $s4, 0x67D8
    ctx->r20 = ADD32(ctx->r20, 0X67D8);
    // 0x8008B504: addiu       $s1, $s1, 0x63D4
    ctx->r17 = ADD32(ctx->r17, 0X63D4);
    // 0x8008B508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008B50C:
    // 0x8008B50C: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8008B510: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8008B514: beq         $t6, $zero, L_8008B528
    if (ctx->r14 == 0) {
        // 0x8008B518: addu        $t8, $s4, $t7
        ctx->r24 = ADD32(ctx->r20, ctx->r15);
            goto L_8008B528;
    }
    // 0x8008B518: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8008B51C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B520: nop

    // 0x8008B524: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
L_8008B528:
    // 0x8008B528: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B52C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B530: bne         $at, $zero, L_8008B50C
    if (ctx->r1 != 0) {
        // 0x8008B534: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008B50C;
    }
    // 0x8008B534: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B538: andi        $t0, $v0, 0x9000
    ctx->r8 = ctx->r2 & 0X9000;
    // 0x8008B53C: beq         $t0, $zero, L_8008B65C
    if (ctx->r8 == 0) {
        // 0x8008B540: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008B65C;
    }
    // 0x8008B540: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B544: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8008B548: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B54C: jal         0x8006EBA8
    // 0x8008B550: sw          $s2, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r18;
    mark_read_all_save_files(rdram, ctx);
        goto after_0;
    // 0x8008B550: sw          $s2, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r18;
    after_0:
    // 0x8008B554: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B558: jal         0x800C01D8
    // 0x8008B55C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008B55C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_1:
    // 0x8008B560: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B564: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8008B568: addiu       $v0, $v0, 0x67D8
    ctx->r2 = ADD32(ctx->r2, 0X67D8);
    // 0x8008B56C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008B570:
    // 0x8008B570: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008B574: nop

    // 0x8008B578: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x8008B57C: beq         $t2, $zero, L_8008B588
    if (ctx->r10 == 0) {
        // 0x8008B580: nop
    
            goto L_8008B588;
    }
    // 0x8008B580: nop

    // 0x8008B584: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8008B588:
    // 0x8008B588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B58C: slti        $t3, $s0, 0x4
    ctx->r11 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B590: slti        $t4, $s1, 0x0
    ctx->r12 = SIGNED(ctx->r17) < 0X0 ? 1 : 0;
    // 0x8008B594: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8008B598: bne         $t5, $zero, L_8008B570
    if (ctx->r13 != 0) {
        // 0x8008B59C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8008B570;
    }
    // 0x8008B59C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008B5A0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008B5A4: addiu       $s7, $s7, 0x6808
    ctx->r23 = ADD32(ctx->r23, 0X6808);
    // 0x8008B5A8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8008B5AC: addu        $s0, $s7, $t6
    ctx->r16 = ADD32(ctx->r23, ctx->r14);
    // 0x8008B5B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008B5B4: nop

    // 0x8008B5B8: beq         $a0, $zero, L_8008B5C8
    if (ctx->r4 == 0) {
        // 0x8008B5BC: nop
    
            goto L_8008B5C8;
    }
    // 0x8008B5BC: nop

    // 0x8008B5C0: jal         0x8000488C
    // 0x8008B5C4: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8008B5C4: nop

    after_2:
L_8008B5C8:
    // 0x8008B5C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008B5CC: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8008B5D0: lb          $t8, 0x63E8($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X63E8);
    // 0x8008B5D4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008B5D8: addiu       $fp, $fp, 0x63CC
    ctx->r30 = ADD32(ctx->r30, 0X63CC);
    // 0x8008B5DC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008B5E0: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008B5E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008B5E8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8008B5EC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008B5F0: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x8008B5F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008B5F8: addiu       $a0, $a0, 0x19E
    ctx->r4 = ADD32(ctx->r4, 0X19E);
    // 0x8008B5FC: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8008B600: jal         0x80001D04
    // 0x8008B604: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008B604: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x8008B608: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B60C: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8008B610: nop

    // 0x8008B614: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008B618: beq         $at, $zero, L_8008B64C
    if (ctx->r1 == 0) {
        // 0x8008B61C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008B64C;
    }
    // 0x8008B61C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008B620: bne         $at, $zero, L_8008B638
    if (ctx->r1 != 0) {
        // 0x8008B624: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008B638;
    }
    // 0x8008B624: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B628: lw          $t2, -0x268($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X268);
    // 0x8008B62C: nop

    // 0x8008B630: sll         $t3, $t2, 7
    ctx->r11 = S32(ctx->r10 << 7);
    // 0x8008B634: bgez        $t3, L_8008B64C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8008B638: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008B64C;
    }
L_8008B638:
    // 0x8008B638: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008B63C: lw          $t4, -0x30($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X30);
    // 0x8008B640: nop

    // 0x8008B644: bne         $s2, $t4, L_8008B72C
    if (ctx->r18 != ctx->r12) {
        // 0x8008B648: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8008B72C;
    }
    // 0x8008B648: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008B64C:
    // 0x8008B64C: jal         0x80000C98
    // 0x8008B650: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x8008B650: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x8008B654: b           L_8008B72C
    // 0x8008B658: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8008B72C;
    // 0x8008B658: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008B65C:
    // 0x8008B65C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008B660: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008B664: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008B668: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008B66C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008B670: addiu       $s3, $s3, -0xB80
    ctx->r19 = ADD32(ctx->r19, -0XB80);
    // 0x8008B674: addiu       $s5, $s5, 0x63DC
    ctx->r21 = ADD32(ctx->r21, 0X63DC);
    // 0x8008B678: addiu       $s7, $s7, 0x6808
    ctx->r23 = ADD32(ctx->r23, 0X6808);
    // 0x8008B67C: addiu       $fp, $fp, 0x63CC
    ctx->r30 = ADD32(ctx->r30, 0X63CC);
    // 0x8008B680: addiu       $s1, $s1, 0x63D4
    ctx->r17 = ADD32(ctx->r17, 0X63D4);
    // 0x8008B684: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8008B688:
    // 0x8008B688: lb          $t5, 0x0($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X0);
    // 0x8008B68C: addu        $v1, $s5, $s0
    ctx->r3 = ADD32(ctx->r21, ctx->r16);
    // 0x8008B690: beq         $t5, $zero, L_8008B71C
    if (ctx->r13 == 0) {
        // 0x8008B694: nop
    
            goto L_8008B71C;
    }
    // 0x8008B694: nop

    // 0x8008B698: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008B69C: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8008B6A0: beq         $t6, $zero, L_8008B71C
    if (ctx->r14 == 0) {
        // 0x8008B6A4: addu        $t8, $s4, $v0
        ctx->r24 = ADD32(ctx->r20, ctx->r2);
            goto L_8008B71C;
    }
    // 0x8008B6A4: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8008B6A8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8008B6AC: addu        $a1, $s7, $v0
    ctx->r5 = ADD32(ctx->r23, ctx->r2);
    // 0x8008B6B0: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8008B6B4: beq         $t9, $zero, L_8008B71C
    if (ctx->r25 == 0) {
        // 0x8008B6B8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008B71C;
    }
    // 0x8008B6B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008B6BC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8008B6C0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008B6C4: addiu       $t2, $t2, 0x63E8
    ctx->r10 = ADD32(ctx->r10, 0X63E8);
    // 0x8008B6C8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008B6CC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8008B6D0: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8008B6D4: beq         $a0, $zero, L_8008B6EC
    if (ctx->r4 == 0) {
        // 0x8008B6D8: addu        $s2, $s0, $t2
        ctx->r18 = ADD32(ctx->r16, ctx->r10);
            goto L_8008B6EC;
    }
    // 0x8008B6D8: addu        $s2, $s0, $t2
    ctx->r18 = ADD32(ctx->r16, ctx->r10);
    // 0x8008B6DC: jal         0x8000488C
    // 0x8008B6E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_5;
    // 0x8008B6E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_5:
    // 0x8008B6E4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008B6E8: nop

L_8008B6EC:
    // 0x8008B6EC: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008B6F0: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8008B6F4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8008B6F8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008B6FC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8008B700: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8008B704: lh          $a0, 0xC($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XC);
    // 0x8008B708: nop

    // 0x8008B70C: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008B710: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8008B714: jal         0x80001D04
    // 0x8008B718: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008B718: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
L_8008B71C:
    // 0x8008B71C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B720: bne         $s0, $s6, L_8008B688
    if (ctx->r16 != ctx->r22) {
        // 0x8008B724: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008B688;
    }
    // 0x8008B724: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B728: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008B72C:
    // 0x8008B72C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B730: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B734: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B738: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B73C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B740: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B744: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008B748: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008B74C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008B750: jr          $ra
    // 0x8008B754: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008B754: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void bgdraw_primcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077B38: sb          $a0, -0x1B50($at)
    MEM_B(-0X1B50, ctx->r1) = ctx->r4;
    // 0x80077B3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077B40: sb          $a1, -0x1B4C($at)
    MEM_B(-0X1B4C, ctx->r1) = ctx->r5;
    // 0x80077B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077B48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80077B4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80077B50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80077B54: jr          $ra
    // 0x80077B58: sb          $a2, -0x1B48($at)
    MEM_B(-0X1B48, ctx->r1) = ctx->r6;
    return;
    // 0x80077B58: sb          $a2, -0x1B48($at)
    MEM_B(-0X1B48, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void bootscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800887C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800887CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800887D0: jal         0x8009C4A8
    // 0x800887D4: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x800887D4: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    after_0:
    // 0x800887D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800887DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800887E0: jr          $ra
    // 0x800887E4: nop

    return;
    // 0x800887E4: nop

;}
RECOMP_FUNC void handle_car_steering(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053478: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8005347C: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x80053480: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80053484: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80053488: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x8005348C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053490: bc1f        L_800534A0
    if (!c1cs) {
        // 0x80053494: nop
    
            goto L_800534A0;
    }
    // 0x80053494: nop

    // 0x80053498: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8005349C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800534A0:
    // 0x800534A0: lwc1        $f5, 0x6750($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6750);
    // 0x800534A4: lwc1        $f4, 0x6754($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6754);
    // 0x800534A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800534AC: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800534B0: nop

    // 0x800534B4: bc1f        L_800534C8
    if (!c1cs) {
        // 0x800534B8: nop
    
            goto L_800534C8;
    }
    // 0x800534B8: nop

    // 0x800534BC: lwc1        $f0, 0x6758($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6758);
    // 0x800534C0: nop

    // 0x800534C4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800534C8:
    // 0x800534C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800534CC: lwc1        $f7, 0x6760($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6760);
    // 0x800534D0: lwc1        $f6, 0x6764($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6764);
    // 0x800534D4: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x800534D8: sub.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d - ctx->f6.d;
    // 0x800534DC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800534E0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800534E4: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x800534E8: nop

    // 0x800534EC: bc1f        L_800534FC
    if (!c1cs) {
        // 0x800534F0: nop
    
            goto L_800534FC;
    }
    // 0x800534F0: nop

    // 0x800534F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800534F8: nop

L_800534FC:
    // 0x800534FC: lb          $t6, 0x1E6($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1E6);
    // 0x80053500: nop

    // 0x80053504: beq         $t6, $zero, L_80053548
    if (ctx->r14 == 0) {
        // 0x80053508: nop
    
            goto L_80053548;
    }
    // 0x80053508: nop

    // 0x8005350C: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x80053510: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80053514: nop

    // 0x80053518: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8005351C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80053520: nop

    // 0x80053524: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80053528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005352C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80053530: nop

    // 0x80053534: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80053538: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8005353C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80053540: b           L_80053580
    // 0x80053544: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
        goto L_80053580;
    // 0x80053544: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
L_80053548:
    // 0x80053548: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005354C: nop

    // 0x80053550: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80053554: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80053558: nop

    // 0x8005355C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80053560: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80053564: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80053568: nop

    // 0x8005356C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80053570: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80053574: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80053578: nop

    // 0x8005357C: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
L_80053580:
    // 0x80053580: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80053584: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053588: addiu       $v1, $v1, -0x2AAC
    ctx->r3 = ADD32(ctx->r3, -0X2AAC);
    // 0x8005358C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80053590: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80053594: mflo        $t1
    ctx->r9 = lo;
    // 0x80053598: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8005359C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800535A0: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800535A4: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x800535A8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800535AC: nop

    // 0x800535B0: bc1f        L_800535BC
    if (!c1cs) {
        // 0x800535B4: nop
    
            goto L_800535BC;
    }
    // 0x800535B4: nop

    // 0x800535B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800535BC:
    // 0x800535BC: jr          $ra
    // 0x800535C0: nop

    return;
    // 0x800535C0: nop

;}
RECOMP_FUNC void fb_mode_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A4E0: lw          $t6, 0x62CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62CC);
    // 0x8007A4E4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007A4E8: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A4EC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007A4F0: addiu       $t9, $t9, -0x1884
    ctx->r25 = ADD32(ctx->r25, -0X1884);
    // 0x8007A4F4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8007A4F8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8007A4FC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8007A500: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A504: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A508: sw          $t0, 0x62B0($at)
    MEM_W(0X62B0, ctx->r1) = ctx->r8;
    // 0x8007A50C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8007A510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A514: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A518: jr          $ra
    // 0x8007A51C: sw          $t1, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = ctx->r9;
    return;
    // 0x8007A51C: sw          $t1, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void mempool_free_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800710B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800710B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800710B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800710BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800710C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800710C4: jal         0x8006F510
    // 0x800710C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800710C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x800710CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800710D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800710D4: bne         $s0, $zero, L_8007111C
    if (ctx->r16 != 0) {
        // 0x800710D8: sw          $s0, 0x3DCC($at)
        MEM_W(0X3DCC, ctx->r1) = ctx->r16;
            goto L_8007111C;
    }
    // 0x800710D8: sw          $s0, 0x3DCC($at)
    MEM_W(0X3DCC, ctx->r1) = ctx->r16;
    // 0x800710DC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800710E0: addiu       $s1, $s1, 0x3DC8
    ctx->r17 = ADD32(ctx->r17, 0X3DC8);
    // 0x800710E4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800710E8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800710EC: blez        $s0, L_8007111C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800710F0: addiu       $s2, $s2, 0x35C8
        ctx->r18 = ADD32(ctx->r18, 0X35C8);
            goto L_8007111C;
    }
    // 0x800710F0: addiu       $s2, $s2, 0x35C8
    ctx->r18 = ADD32(ctx->r18, 0X35C8);
    // 0x800710F4: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_800710F8:
    // 0x800710F8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800710FC: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80071100: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80071104: jal         0x80071278
    // 0x80071108: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071108: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_1:
    // 0x8007110C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80071110: nop

    // 0x80071114: bgtz        $s0, L_800710F8
    if (SIGNED(ctx->r16) > 0) {
        // 0x80071118: addiu       $v0, $s0, -0x1
        ctx->r2 = ADD32(ctx->r16, -0X1);
            goto L_800710F8;
    }
    // 0x80071118: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_8007111C:
    // 0x8007111C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80071120: jal         0x8006F53C
    // 0x80071124: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x80071124: nop

    after_2:
    // 0x80071128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007112C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071130: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071134: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071138: jr          $ra
    // 0x8007113C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007113C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sound_reverb_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002630: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002634: lbu         $t7, 0x5D04($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5D04);
    // 0x80002638: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8000263C: lw          $t6, 0x5D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D1C);
    // 0x80002640: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80002644: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80002648: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000264C: lbu         $v0, 0x2($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X2);
    // 0x80002650: jr          $ra
    // 0x80002654: nop

    return;
    // 0x80002654: nop

;}
RECOMP_FUNC void transition_render_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0A14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C0A18: jal         0x8007A520
    // 0x800C0A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C0A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C0A20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C0A24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0A28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0A2C: addiu       $t8, $t8, 0x31D8
    ctx->r24 = ADD32(ctx->r24, 0X31D8);
    // 0x800C0A30: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C0A34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0A38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C0A3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C0A40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0A44: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0A48: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0A4C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C0A50: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C0A54: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0A58: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C0A5C: lbu         $t6, -0x58CB($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X58CB);
    // 0x800C0A60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C0A64: lbu         $t3, -0x58CC($t2)
    ctx->r11 = MEM_BU(ctx->r10, -0X58CC);
    // 0x800C0A68: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C0A6C: lbu         $t1, -0x58CA($t9)
    ctx->r9 = MEM_BU(ctx->r25, -0X58CA);
    // 0x800C0A70: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C0A74: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0A78: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800C0A7C: lbu         $t6, -0x58C9($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X58C9);
    // 0x800C0A80: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800C0A84: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800C0A88: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800C0A8C: or          $t4, $t3, $t6
    ctx->r12 = ctx->r11 | ctx->r14;
    // 0x800C0A90: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800C0A94: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0A98: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x800C0A9C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C0AA0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C0AA4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C0AA8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C0AAC: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x800C0AB0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800C0AB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C0AB8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0ABC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C0AC0: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x800C0AC4: sll         $t3, $t5, 14
    ctx->r11 = S32(ctx->r13 << 14);
    // 0x800C0AC8: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C0ACC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C0AD0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C0AD4: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x800C0AD8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C0ADC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C0AE0: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800C0AE4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C0AE8: jal         0x8007B3D0
    // 0x800C0AEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C0AEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C0AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0AF8: jr          $ra
    // 0x800C0AFC: nop

    return;
    // 0x800C0AFC: nop

;}
RECOMP_FUNC void audspat_reverb_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009AB4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80009AB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009ABC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009AC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009AC4: addiu       $t8, $t8, -0x5928
    ctx->r24 = ADD32(ctx->r24, -0X5928);
    // 0x80009AC8: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x80009ACC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009AD0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009AD4: lb          $a3, 0xB8($v0)
    ctx->r7 = MEM_B(ctx->r2, 0XB8);
    // 0x80009AD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009ADC: bgtz        $a3, L_80009AEC
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009AE0: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009AEC;
    }
    // 0x80009AE0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009AE4: jr          $ra
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009AEC:
    // 0x80009AEC: blez        $a3, L_80009B70
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009AF0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009B70;
    }
    // 0x80009AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009AF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009AF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009B00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009B08: lwc1        $f3, 0x4F20($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X4F20);
    // 0x80009B0C: lwc1        $f2, 0x4F24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4F24);
    // 0x80009B10: lb          $a1, 0xB8($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XB8);
    // 0x80009B14: nop

L_80009B18:
    // 0x80009B18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009B1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009B20: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009B24: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009B28: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009B2C: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B30: nop
    
            goto L_80009B64;
    }
    // 0x80009B30: nop

    // 0x80009B34: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009B38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009B3C: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009B40: nop

    // 0x80009B44: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B48: nop
    
            goto L_80009B64;
    }
    // 0x80009B48: nop

    // 0x80009B4C: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009B50: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009B54: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009B58: nop

    // 0x80009B5C: bc1f        L_80009B68
    if (!c1cs) {
        // 0x80009B60: nop
    
            goto L_80009B68;
    }
    // 0x80009B60: nop

L_80009B64:
    // 0x80009B64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009B68:
    // 0x80009B68: bne         $at, $zero, L_80009B18
    if (ctx->r1 != 0) {
        // 0x80009B6C: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009B18;
    }
    // 0x80009B6C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009B70:
    // 0x80009B70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009B74: jr          $ra
    // 0x80009B78: nop

    return;
    // 0x80009B78: nop

;}
RECOMP_FUNC void scroll_particle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF404: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF408: addiu       $t0, $t0, 0x2E28
    ctx->r8 = ADD32(ctx->r8, 0X2E28);
    // 0x800AF40C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800AF410: sll         $t7, $a0, 6
    ctx->r15 = S32(ctx->r4 << 6);
    // 0x800AF414: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF418: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800AF41C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800AF420: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF424: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF428: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF42C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800AF430: addiu       $v1, $v1, 0x2D58
    ctx->r3 = ADD32(ctx->r3, 0X2D58);
    // 0x800AF434: addiu       $a3, $a3, 0x2D58
    ctx->r7 = ADD32(ctx->r7, 0X2D58);
    // 0x800AF438: addiu       $a2, $a2, 0x2D08
    ctx->r6 = ADD32(ctx->r6, 0X2D08);
L_800AF43C:
    // 0x800AF43C: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x800AF440: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x800AF444: lh          $t5, 0x4($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X4);
    // 0x800AF448: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800AF44C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800AF450: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AF454: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AF458: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AF45C: sh          $t2, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = ctx->r10;
    // 0x800AF460: sh          $t4, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r12;
    // 0x800AF464: sh          $t6, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r14;
    // 0x800AF468: bne         $at, $zero, L_800AF43C
    if (ctx->r1 != 0) {
        // 0x800AF46C: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_800AF43C;
    }
    // 0x800AF46C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800AF470: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AF474: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF478: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF47C: addiu       $v1, $v1, 0x2DF8
    ctx->r3 = ADD32(ctx->r3, 0X2DF8);
    // 0x800AF480: addiu       $a2, $a2, 0x2DF8
    ctx->r6 = ADD32(ctx->r6, 0X2DF8);
    // 0x800AF484: addiu       $a0, $a0, 0x2D78
    ctx->r4 = ADD32(ctx->r4, 0X2D78);
L_800AF488:
    // 0x800AF488: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800AF48C: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x800AF490: lh          $t2, 0x4($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X4);
    // 0x800AF494: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AF498: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AF49C: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
    // 0x800AF4A0: sh          $t1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r9;
    // 0x800AF4A4: lh          $t1, 0xC($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XC);
    // 0x800AF4A8: lh          $t8, 0xA($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XA);
    // 0x800AF4AC: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x800AF4B0: lh          $t6, 0x8($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X8);
    // 0x800AF4B4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AF4B8: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x800AF4BC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AF4C0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800AF4C4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800AF4C8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800AF4CC: lh          $t3, 0xE($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XE);
    // 0x800AF4D0: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800AF4D4: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x800AF4D8: sh          $t9, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r25;
    // 0x800AF4DC: sh          $t2, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r10;
    // 0x800AF4E0: lh          $t2, 0x16($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X16);
    // 0x800AF4E4: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800AF4E8: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800AF4EC: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800AF4F0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AF4F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800AF4F8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AF4FC: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AF500: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AF504: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AF508: sh          $t8, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r24;
    // 0x800AF50C: sh          $t6, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r14;
    // 0x800AF510: sh          $t1, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r9;
    // 0x800AF514: sh          $t3, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r11;
    // 0x800AF518: sh          $t4, -0x16($a0)
    MEM_H(-0X16, ctx->r4) = ctx->r12;
    // 0x800AF51C: bne         $a0, $v1, L_800AF488
    if (ctx->r4 != ctx->r3) {
        // 0x800AF520: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_800AF488;
    }
    // 0x800AF520: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800AF524: jr          $ra
    // 0x800AF528: nop

    return;
    // 0x800AF528: nop

;}
RECOMP_FUNC void race_transition_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A8F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A8F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A8FC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001A900: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A904: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A908: jal         0x8006F388
    // 0x8001A90C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_0;
    // 0x8001A90C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001A910: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A914: addiu       $s0, $s0, -0x52B2
    ctx->r16 = ADD32(ctx->r16, -0X52B2);
    // 0x8001A918: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8001A91C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001A920: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001A924: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8001A928: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8001A92C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8001A930: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8001A934: bgtz        $t8, L_8001A940
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001A938: nop
    
            goto L_8001A940;
    }
    // 0x8001A938: nop

    // 0x8001A93C: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_8001A940:
    // 0x8001A940: bne         $at, $zero, L_8001A964
    if (ctx->r1 != 0) {
        // 0x8001A944: nop
    
            goto L_8001A964;
    }
    // 0x8001A944: nop

    // 0x8001A948: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8001A94C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001A950: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x8001A954: beq         $at, $zero, L_8001A964
    if (ctx->r1 == 0) {
        // 0x8001A958: nop
    
            goto L_8001A964;
    }
    // 0x8001A958: nop

    // 0x8001A95C: jal         0x800C01D8
    // 0x8001A960: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8001A960: addiu       $a0, $a0, -0x37A8
    ctx->r4 = ADD32(ctx->r4, -0X37A8);
    after_1:
L_8001A964:
    // 0x8001A964: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A968: lb          $v0, -0x52B0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52B0);
    // 0x8001A96C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8001A970: bne         $v0, $zero, L_8001AB38
    if (ctx->r2 != 0) {
        // 0x8001A974: nop
    
            goto L_8001AB38;
    }
    // 0x8001A974: nop

    // 0x8001A978: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8001A97C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A980: bne         $t2, $at, L_8001AB38
    if (ctx->r10 != ctx->r1) {
        // 0x8001A984: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_8001AB38;
    }
    // 0x8001A984: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A988: addiu       $s1, $s1, -0x5110
    ctx->r17 = ADD32(ctx->r17, -0X5110);
    // 0x8001A98C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8001A990: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A994: blez        $t3, L_8001AA3C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001A998: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001AA3C;
    }
    // 0x8001A998: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001A99C:
    // 0x8001A99C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A9A0: lw          $t4, -0x511C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X511C);
    // 0x8001A9A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A9A8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8001A9AC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001A9B0: nop

    // 0x8001A9B4: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x8001A9B8: nop

    // 0x8001A9BC: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001A9C0: sw          $zero, 0x140($a1)
    MEM_W(0X140, ctx->r5) = 0;
    // 0x8001A9C4: beq         $t7, $at, L_8001A9E0
    if (ctx->r15 == ctx->r1) {
        // 0x8001A9C8: nop
    
            goto L_8001A9E0;
    }
    // 0x8001A9C8: nop

    // 0x8001A9CC: lh          $t8, 0x1AC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X1AC);
    // 0x8001A9D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001A9D4: bne         $t8, $at, L_8001A9E0
    if (ctx->r24 != ctx->r1) {
        // 0x8001A9D8: nop
    
            goto L_8001A9E0;
    }
    // 0x8001A9D8: nop

    // 0x8001A9DC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_8001A9E0:
    // 0x8001A9E0: lw          $a0, 0x178($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X178);
    // 0x8001A9E4: nop

    // 0x8001A9E8: beq         $a0, $zero, L_8001AA08
    if (ctx->r4 == 0) {
        // 0x8001A9EC: nop
    
            goto L_8001AA08;
    }
    // 0x8001A9EC: nop

    // 0x8001A9F0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001A9F4: jal         0x8000488C
    // 0x8001A9F8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001A9F8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x8001A9FC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA00: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AA04: nop

L_8001AA08:
    // 0x8001AA08: lw          $a0, 0x17C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X17C);
    // 0x8001AA0C: nop

    // 0x8001AA10: beq         $a0, $zero, L_8001AA28
    if (ctx->r4 == 0) {
        // 0x8001AA14: nop
    
            goto L_8001AA28;
    }
    // 0x8001AA14: nop

    // 0x8001AA18: jal         0x800096F8
    // 0x8001AA1C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x8001AA1C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8001AA20: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA24: nop

L_8001AA28:
    // 0x8001AA28: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AA30: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001AA34: bne         $at, $zero, L_8001A99C
    if (ctx->r1 != 0) {
        // 0x8001AA38: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001A99C;
    }
    // 0x8001AA38: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8001AA3C:
    // 0x8001AA3C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8001AA40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AA44: lw          $v0, -0x511C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X511C);
    // 0x8001AA48: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8001AA4C: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8001AA50: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001AA54: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8001AA58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001AA5C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001AA60: lw          $t4, -0x511C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X511C);
    // 0x8001AA64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AA68: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8001AA6C: sw          $a2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r6;
    // 0x8001AA70: lw          $t6, -0x511C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X511C);
    // 0x8001AA74: nop

    // 0x8001AA78: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001AA7C: jal         0x80006AC8
    // 0x8001AA80: nop

    racer_sound_free(rdram, ctx);
        goto after_4;
    // 0x8001AA80: nop

    after_4:
    // 0x8001AA84: jal         0x800A0B74
    // 0x8001AA88: nop

    hud_audio_init(rdram, ctx);
        goto after_5;
    // 0x8001AA88: nop

    after_5:
    // 0x8001AA8C: jal         0x8003F0D0
    // 0x8001AA90: nop

    reset_rocket_sound_timer(rdram, ctx);
        goto after_6;
    // 0x8001AA90: nop

    after_6:
    // 0x8001AA94: jal         0x800049D8
    // 0x8001AA98: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_7;
    // 0x8001AA98: nop

    after_7:
    // 0x8001AA9C: jal         0x8009EC80
    // 0x8001AAA0: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x8001AAA0: nop

    after_8:
    // 0x8001AAA4: beq         $v0, $zero, L_8001AB18
    if (ctx->r2 == 0) {
        // 0x8001AAA8: nop
    
            goto L_8001AB18;
    }
    // 0x8001AAA8: nop

    // 0x8001AAAC: jal         0x800249E0
    // 0x8001AAB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_scene_viewport_num(rdram, ctx);
        goto after_9;
    // 0x8001AAB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8001AAB4: jal         0x8006652C
    // 0x8001AAB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_10;
    // 0x8001AAB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8001AABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001AAC0: lw          $t7, -0x511C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X511C);
    // 0x8001AAC4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AAC8: addiu       $a3, $a3, -0x5114
    ctx->r7 = ADD32(ctx->r7, -0X5114);
    // 0x8001AACC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8001AAD0: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001AAD4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001AAD8: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001AADC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8001AAE0: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8001AAE4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8001AAE8: addiu       $t0, $t0, -0x38BC
    ctx->r8 = ADD32(ctx->r8, -0X38BC);
    // 0x8001AAEC: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x8001AAF0: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8001AAF4: nop

    // 0x8001AAF8: beq         $t9, $zero, L_8001AB18
    if (ctx->r25 == 0) {
        // 0x8001AAFC: nop
    
            goto L_8001AB18;
    }
    // 0x8001AAFC: nop

    // 0x8001AB00: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8001AB04: jal         0x8006F398
    // 0x8001AB08: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    swap_lead_player(rdram, ctx);
        goto after_11;
    // 0x8001AB08: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8001AB0C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AB10: nop

    // 0x8001AB14: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001AB18:
    // 0x8001AB18: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8001AB1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB20: addiu       $a3, $a3, -0x52AF
    ctx->r7 = ADD32(ctx->r7, -0X52AF);
    // 0x8001AB24: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001AB28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AB2C: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
    // 0x8001AB30: sb          $t2, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r10;
    // 0x8001AB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001AB38:
    // 0x8001AB38: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001AB3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AB40: bne         $v0, $at, L_8001AC98
    if (ctx->r2 != ctx->r1) {
        // 0x8001AB44: addiu       $s1, $s1, -0x5110
        ctx->r17 = ADD32(ctx->r17, -0X5110);
            goto L_8001AC98;
    }
    // 0x8001AB44: addiu       $s1, $s1, -0x5110
    ctx->r17 = ADD32(ctx->r17, -0X5110);
    // 0x8001AB48: jal         0x800AB1D4
    // 0x8001AB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_12;
    // 0x8001AB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8001AB50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB54: addiu       $a3, $a3, -0x52AF
    ctx->r7 = ADD32(ctx->r7, -0X52AF);
    // 0x8001AB58: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AB5C: nop

    // 0x8001AB60: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8001AB64: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x8001AB68: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001AB6C: nop

    // 0x8001AB70: blez        $a2, L_8001AC8C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001AB74: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8001AC8C;
    }
    // 0x8001AB74: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001AB78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001AB7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001AB80: blez        $a0, L_8001ABD8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001AB84: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001ABD8;
    }
    // 0x8001AB84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001AB88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001AB8C: lw          $t5, -0x511C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X511C);
    // 0x8001AB90: addiu       $a1, $a1, -0x5118
    ctx->r5 = ADD32(ctx->r5, -0X5118);
    // 0x8001AB94: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001AB98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001AB9C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ABA0: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001ABA4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001ABA8: nop

    // 0x8001ABAC: beq         $t8, $v1, L_8001ABD8
    if (ctx->r24 == ctx->r3) {
        // 0x8001ABB0: nop
    
            goto L_8001ABD8;
    }
    // 0x8001ABB0: nop

L_8001ABB4:
    // 0x8001ABB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001ABB8: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001ABBC: beq         $at, $zero, L_8001ABD8
    if (ctx->r1 == 0) {
        // 0x8001ABC0: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8001ABD8;
    }
    // 0x8001ABC0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8001ABC4: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8001ABC8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001ABCC: nop

    // 0x8001ABD0: bne         $t2, $v1, L_8001ABB4
    if (ctx->r10 != ctx->r3) {
        // 0x8001ABD4: nop
    
            goto L_8001ABB4;
    }
    // 0x8001ABD4: nop

L_8001ABD8:
    // 0x8001ABD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001ABDC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001ABE0: beq         $at, $zero, L_8001AC30
    if (ctx->r1 == 0) {
        // 0x8001ABE4: addiu       $a1, $a1, -0x5118
        ctx->r5 = ADD32(ctx->r5, -0X5118);
            goto L_8001AC30;
    }
    // 0x8001ABE4: addiu       $a1, $a1, -0x5118
    ctx->r5 = ADD32(ctx->r5, -0X5118);
    // 0x8001ABE8: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x8001ABEC: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001ABF0: beq         $at, $zero, L_8001AC30
    if (ctx->r1 == 0) {
        // 0x8001ABF4: sll         $v1, $s0, 2
        ctx->r3 = S32(ctx->r16 << 2);
            goto L_8001AC30;
    }
    // 0x8001ABF4: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
L_8001ABF8:
    // 0x8001ABF8: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8001ABFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AC00: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8001AC04: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8001AC08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001AC0C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001AC10: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001AC14: nop

    // 0x8001AC18: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001AC1C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001AC20: bne         $at, $zero, L_8001ABF8
    if (ctx->r1 != 0) {
        // 0x8001AC24: nop
    
            goto L_8001ABF8;
    }
    // 0x8001AC24: nop

    // 0x8001AC28: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC2C: nop

L_8001AC30:
    // 0x8001AC30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001AC34: lw          $t8, -0x511C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X511C);
    // 0x8001AC38: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001AC3C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8001AC40: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001AC44: jal         0x8000FFB8
    // 0x8001AC48: nop

    free_object(rdram, ctx);
        goto after_13;
    // 0x8001AC48: nop

    after_13:
    // 0x8001AC4C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AC50: addiu       $a3, $a3, -0x52AF
    ctx->r7 = ADD32(ctx->r7, -0X52AF);
    // 0x8001AC54: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001AC5C: lw          $t2, -0x511C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X511C);
    // 0x8001AC60: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001AC64: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8001AC68: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8001AC6C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001AC70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AC74: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001AC78: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001AC7C: lb          $v0, -0x52B0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52B0);
    // 0x8001AC80: b           L_8001AC9C
    // 0x8001AC84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_8001AC9C;
    // 0x8001AC84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001AC88: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8001AC8C:
    // 0x8001AC8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AC90: sb          $t8, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r24;
    // 0x8001AC94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001AC98:
    // 0x8001AC98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8001AC9C:
    // 0x8001AC9C: bne         $v0, $at, L_8001ACF8
    if (ctx->r2 != ctx->r1) {
        // 0x8001ACA0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8001ACF8;
    }
    // 0x8001ACA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001ACA4: lw          $t9, -0x511C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X511C);
    // 0x8001ACA8: nop

    // 0x8001ACAC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001ACB0: nop

    // 0x8001ACB4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001ACB8: jal         0x800230D0
    // 0x8001ACBC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_800230D0(rdram, ctx);
        goto after_14;
    // 0x8001ACBC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8001ACC0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001ACC4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001ACC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001ACCC: sb          $zero, 0x1D8($a1)
    MEM_B(0X1D8, ctx->r5) = 0;
    // 0x8001ACD0: sb          $t1, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r9;
    // 0x8001ACD4: jal         0x8001E45C
    // 0x8001ACD8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8001E45C(rdram, ctx);
        goto after_15;
    // 0x8001ACD8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_15:
    // 0x8001ACDC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001ACE0: addiu       $s0, $s0, -0x5238
    ctx->r16 = ADD32(ctx->r16, -0X5238);
    // 0x8001ACE4: jal         0x8001E93C
    // 0x8001ACE8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8001E93C(rdram, ctx);
        goto after_16;
    // 0x8001ACE8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_16:
    // 0x8001ACEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001ACF0: lb          $v0, -0x52B0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52B0);
    // 0x8001ACF4: nop

L_8001ACF8:
    // 0x8001ACF8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001ACFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001AD00: bne         $v0, $at, L_8001AD34
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD04: addiu       $s0, $s0, -0x5238
        ctx->r16 = ADD32(ctx->r16, -0X5238);
            goto L_8001AD34;
    }
    // 0x8001AD04: addiu       $s0, $s0, -0x5238
    ctx->r16 = ADD32(ctx->r16, -0X5238);
    // 0x8001AD08: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AD0C: jal         0x800C01D8
    // 0x8001AD10: addiu       $a0, $a0, -0x37A0
    ctx->r4 = ADD32(ctx->r4, -0X37A0);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x8001AD10: addiu       $a0, $a0, -0x37A0
    ctx->r4 = ADD32(ctx->r4, -0X37A0);
    after_17:
    // 0x8001AD14: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001AD18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AD1C: sb          $t3, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r11;
    // 0x8001AD20: jal         0x80028FA0
    // 0x8001AD24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_18;
    // 0x8001AD24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x8001AD28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AD2C: lb          $v0, -0x52B0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52B0);
    // 0x8001AD30: nop

L_8001AD34:
    // 0x8001AD34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001AD38: bne         $v0, $at, L_8001AE34
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE34;
    }
    // 0x8001AD3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD40: jal         0x80028FA0
    // 0x8001AD44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_19;
    // 0x8001AD44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8001AD48: jal         0x8005A3B0
    // 0x8001AD4C: nop

    disable_racer_input(rdram, ctx);
        goto after_20;
    // 0x8001AD4C: nop

    after_20:
    // 0x8001AD50: jal         0x8006BD98
    // 0x8001AD54: nop

    level_type(rdram, ctx);
        goto after_21;
    // 0x8001AD54: nop

    after_21:
    // 0x8001AD58: andi        $t2, $v0, 0x40
    ctx->r10 = ctx->r2 & 0X40;
    // 0x8001AD5C: bne         $t2, $zero, L_8001ADAC
    if (ctx->r10 != 0) {
        // 0x8001AD60: lui         $t4, 0x8000
        ctx->r12 = S32(0X8000 << 16);
            goto L_8001ADAC;
    }
    // 0x8001AD60: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8001AD64: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8001AD68: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001AD6C: bne         $t4, $zero, L_8001AD7C
    if (ctx->r12 != 0) {
        // 0x8001AD70: addiu       $v0, $zero, 0x21C
        ctx->r2 = ADD32(0, 0X21C);
            goto L_8001AD7C;
    }
    // 0x8001AD70: addiu       $v0, $zero, 0x21C
    ctx->r2 = ADD32(0, 0X21C);
    // 0x8001AD74: b           L_8001AD7C
    // 0x8001AD78: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
        goto L_8001AD7C;
    // 0x8001AD78: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
L_8001AD7C:
    // 0x8001AD7C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001AD80: nop

    // 0x8001AD84: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001AD88: sltu        $at, $t7, $v0
    ctx->r1 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x8001AD8C: beq         $at, $zero, L_8001ADA4
    if (ctx->r1 == 0) {
        // 0x8001AD90: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_8001ADA4;
    }
    // 0x8001AD90: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8001AD94: jal         0x800AB194
    // 0x8001AD98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    minimap_fade(rdram, ctx);
        goto after_22;
    // 0x8001AD98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x8001AD9C: b           L_8001ADAC
    // 0x8001ADA0: nop

        goto L_8001ADAC;
    // 0x8001ADA0: nop

L_8001ADA4:
    // 0x8001ADA4: jal         0x800AB1D4
    // 0x8001ADA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_23;
    // 0x8001ADA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_23:
L_8001ADAC:
    // 0x8001ADAC: jal         0x8006A554
    // 0x8001ADB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_24;
    // 0x8001ADB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8001ADB4: jal         0x8006EA90
    // 0x8001ADB8: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    get_settings(rdram, ctx);
        goto after_25;
    // 0x8001ADB8: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    after_25:
    // 0x8001ADBC: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8001ADC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001ADC4: sll         $t1, $t9, 13
    ctx->r9 = S32(ctx->r25 << 13);
    // 0x8001ADC8: bltz        $t1, L_8001ADD4
    if (SIGNED(ctx->r9) < 0) {
        // 0x8001ADCC: nop
    
            goto L_8001ADD4;
    }
    // 0x8001ADCC: nop

    // 0x8001ADD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001ADD4:
    // 0x8001ADD4: jal         0x800214C4
    // 0x8001ADD8: nop

    func_800214C4(rdram, ctx);
        goto after_26;
    // 0x8001ADD8: nop

    after_26:
    // 0x8001ADDC: bne         $v0, $zero, L_8001ADFC
    if (ctx->r2 != 0) {
        // 0x8001ADE0: nop
    
            goto L_8001ADFC;
    }
    // 0x8001ADE0: nop

    // 0x8001ADE4: beq         $s0, $zero, L_8001AE34
    if (ctx->r16 == 0) {
        // 0x8001ADE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE34;
    }
    // 0x8001ADE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ADEC: jal         0x800C018C
    // 0x8001ADF0: nop

    check_fadeout_transition(rdram, ctx);
        goto after_27;
    // 0x8001ADF0: nop

    after_27:
    // 0x8001ADF4: bne         $v0, $zero, L_8001AE34
    if (ctx->r2 != 0) {
        // 0x8001ADF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE34;
    }
    // 0x8001ADF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001ADFC:
    // 0x8001ADFC: beq         $s0, $zero, L_8001AE0C
    if (ctx->r16 == 0) {
        // 0x8001AE00: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8001AE0C;
    }
    // 0x8001AE00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AE04: jal         0x800C01D8
    // 0x8001AE08: addiu       $a0, $a0, -0x3908
    ctx->r4 = ADD32(ctx->r4, -0X3908);
    transition_begin(rdram, ctx);
        goto after_28;
    // 0x8001AE08: addiu       $a0, $a0, -0x3908
    ctx->r4 = ADD32(ctx->r4, -0X3908);
    after_28:
L_8001AE0C:
    // 0x8001AE0C: jal         0x8006F140
    // 0x8001AE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    level_transition_begin(rdram, ctx);
        goto after_29;
    // 0x8001AE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_29:
    // 0x8001AE14: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AE18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AE1C: sb          $t3, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r11;
    // 0x8001AE20: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    // 0x8001AE24: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8001AE28: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8001AE2C: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
    // 0x8001AE30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001AE34:
    // 0x8001AE34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001AE3C: jr          $ra
    // 0x8001AE40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001AE40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void render_3d_misc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011AD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011AD8: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x80011ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011AE0: beq         $v0, $at, L_80011BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80011AE4: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011BB4;
    }
    // 0x80011AE4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AE8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80011AEC: beq         $v0, $at, L_80011B10
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80011B10;
    }
    // 0x80011AF0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80011AF4: beq         $v0, $at, L_80011B58
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF8: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011B58;
    }
    // 0x80011AF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AFC: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80011B00: beq         $v0, $at, L_80011C38
    if (ctx->r2 == ctx->r1) {
        // 0x80011B04: nop
    
            goto L_80011C38;
    }
    // 0x80011B04: nop

    // 0x80011B08: b           L_80011C88
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B10:
    // 0x80011B10: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80011B14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80011B18: bltz        $t6, L_80011C84
    if (SIGNED(ctx->r14) < 0) {
        // 0x80011B1C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80011C84;
    }
    // 0x80011B1C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80011B20: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B28: lw          $a1, 0x20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X20);
    // 0x80011B2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80011B30: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x80011B34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011B38: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80011B3C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80011B40: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011B44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80011B48: jal         0x80011960
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    render_misc_model(rdram, ctx);
        goto after_0;
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80011B50: b           L_80011C88
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B58:
    // 0x80011B58: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B5C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80011B60: lbu         $t0, 0xFC($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011B64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80011B68: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80011B6C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80011B70: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80011B74: lw          $t4, 0xF8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XF8);
    // 0x80011B78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80011B7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80011B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011B88: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80011B8C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80011B90: addu        $a1, $a3, $t2
    ctx->r5 = ADD32(ctx->r7, ctx->r10);
    // 0x80011B94: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011B98: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80011B9C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011BA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80011BA4: jal         0x80011960
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    render_misc_model(rdram, ctx);
        goto after_1;
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80011BAC: b           L_80011C88
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011BB4:
    // 0x80011BB4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80011BB8: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011BBC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80011BC0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80011BC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80011BC8: bgez        $t7, L_80011BE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80011BCC: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80011BE0;
    }
    // 0x80011BCC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011BD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80011BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80011BD8: nop

    // 0x80011BDC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80011BE0:
    // 0x80011BE0: lbu         $t8, 0xFC($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011BE8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80011BEC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80011BF0: lwc1        $f16, 0x5550($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5550);
    // 0x80011BF4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80011BF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80011BFC: lw          $t2, 0xF8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XF8);
    // 0x80011C00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80011C04: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80011C08: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80011C0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80011C10: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    // 0x80011C14: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80011C18: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80011C1C: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011C20: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80011C24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011C28: jal         0x80011960
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    render_misc_model(rdram, ctx);
        goto after_2;
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x80011C30: b           L_80011C88
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C38:
    // 0x80011C38: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x80011C3C: nop

    // 0x80011C40: beq         $t4, $zero, L_80011C88
    if (ctx->r12 == 0) {
        // 0x80011C44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011C48: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80011C4C: nop

    // 0x80011C50: lbu         $t5, 0x70($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X70);
    // 0x80011C54: nop

    // 0x80011C58: bgtz        $t5, L_80011C7C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80011C5C: nop
    
            goto L_80011C7C;
    }
    // 0x80011C5C: nop

    // 0x80011C60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80011C64: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80011C68: nop

    // 0x80011C6C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80011C70: nop

    // 0x80011C74: bc1f        L_80011C88
    if (!c1cs) {
        // 0x80011C78: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C7C:
    // 0x80011C7C: jal         0x800135B8
    // 0x80011C80: nop

    func_800135B8(rdram, ctx);
        goto after_3;
    // 0x80011C80: nop

    after_3:
L_80011C84:
    // 0x80011C84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C88:
    // 0x80011C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011C8C: jr          $ra
    // 0x80011C90: nop

    return;
    // 0x80011C90: nop

;}
RECOMP_FUNC void func_8004CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CC20: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004CC24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004CC28: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004CC2C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004CC30: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8004CC34: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8004CC38: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    // 0x8004CC3C: lw          $a1, 0x17C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X17C);
    // 0x8004CC40: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8004CC44: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004CC48: sh          $zero, 0x18E($a3)
    MEM_H(0X18E, ctx->r7) = 0;
    // 0x8004CC4C: beq         $a1, $zero, L_8004CC60
    if (ctx->r5 == 0) {
        // 0x8004CC50: sb          $zero, 0x189($a3)
        MEM_B(0X189, ctx->r7) = 0;
            goto L_8004CC60;
    }
    // 0x8004CC50: sb          $zero, 0x189($a3)
    MEM_B(0X189, ctx->r7) = 0;
    // 0x8004CC54: jal         0x800096F8
    // 0x8004CC58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_0;
    // 0x8004CC58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8004CC5C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8004CC60:
    // 0x8004CC60: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004CC64: nop

    // 0x8004CC68: bne         $v0, $zero, L_8004CC88
    if (ctx->r2 != 0) {
        // 0x8004CC6C: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_8004CC88;
    }
    // 0x8004CC6C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8004CC70: sb          $t6, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r14;
    // 0x8004CC74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CC78: jal         0x80057048
    // 0x8004CC7C: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    racer_play_sound(rdram, ctx);
        goto after_1;
    // 0x8004CC7C: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    after_1:
    // 0x8004CC80: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004CC84: nop

L_8004CC88:
    // 0x8004CC88: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004CC8C: beq         $at, $zero, L_8004CC9C
    if (ctx->r1 == 0) {
        // 0x8004CC90: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8004CC9C;
    }
    // 0x8004CC90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8004CC94: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8004CC98: sb          $t7, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r15;
L_8004CC9C:
    // 0x8004CC9C: jal         0x8002ACC8
    // 0x8004CCA0: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    set_collision_mode(rdram, ctx);
        goto after_2;
    // 0x8004CCA0: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    after_2:
    // 0x8004CCA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCA8: sh          $zero, -0x2AB0($at)
    MEM_H(-0X2AB0, ctx->r1) = 0;
    // 0x8004CCAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCB0: sw          $zero, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = 0;
    // 0x8004CCB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCB8: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    // 0x8004CCBC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CCC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004CCC4: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x8004CCC8: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CCCC: lw          $t8, -0x2ACC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2ACC);
    // 0x8004CCD0: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8004CCD4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CCD8: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x8004CCDC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x8004CCE0: lb          $a0, 0x1E1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CCE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004CCE8: subu        $v1, $t8, $a0
    ctx->r3 = SUB32(ctx->r24, ctx->r4);
    // 0x8004CCEC: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CCF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004CCF4: mflo        $v0
    ctx->r2 = lo;
    // 0x8004CCF8: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004CCFC: beq         $v1, $zero, L_8004CD24
    if (ctx->r3 == 0) {
        // 0x8004CD00: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8004CD24;
    }
    // 0x8004CD00: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8004CD04: bne         $t9, $zero, L_8004CD28
    if (ctx->r25 != 0) {
        // 0x8004CD08: addu        $t3, $a0, $a2
        ctx->r11 = ADD32(ctx->r4, ctx->r6);
            goto L_8004CD28;
    }
    // 0x8004CD08: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x8004CD0C: blez        $v1, L_8004CD18
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004CD10: nop
    
            goto L_8004CD18;
    }
    // 0x8004CD10: nop

    // 0x8004CD14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8004CD18:
    // 0x8004CD18: bgez        $v1, L_8004CD28
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004CD1C: addu        $t3, $a0, $a2
        ctx->r11 = ADD32(ctx->r4, ctx->r6);
            goto L_8004CD28;
    }
    // 0x8004CD1C: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x8004CD20: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004CD24:
    // 0x8004CD24: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
L_8004CD28:
    // 0x8004CD28: sb          $t3, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r11;
    // 0x8004CD2C: lw          $t4, -0x2AC8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AC8);
    // 0x8004CD30: lb          $a3, 0x1E8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E8);
    // 0x8004CD34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CD38: subu        $v1, $t4, $a3
    ctx->r3 = SUB32(ctx->r12, ctx->r7);
    // 0x8004CD3C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CD40: mflo        $v0
    ctx->r2 = lo;
    // 0x8004CD44: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004CD48: beq         $v1, $zero, L_8004CD70
    if (ctx->r3 == 0) {
        // 0x8004CD4C: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8004CD70;
    }
    // 0x8004CD4C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8004CD50: bne         $t5, $zero, L_8004CD74
    if (ctx->r13 != 0) {
        // 0x8004CD54: addu        $t6, $a3, $a2
        ctx->r14 = ADD32(ctx->r7, ctx->r6);
            goto L_8004CD74;
    }
    // 0x8004CD54: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
    // 0x8004CD58: blez        $v1, L_8004CD64
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004CD5C: nop
    
            goto L_8004CD64;
    }
    // 0x8004CD5C: nop

    // 0x8004CD60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8004CD64:
    // 0x8004CD64: bgez        $v1, L_8004CD74
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004CD68: addu        $t6, $a3, $a2
        ctx->r14 = ADD32(ctx->r7, ctx->r6);
            goto L_8004CD74;
    }
    // 0x8004CD68: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
    // 0x8004CD6C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004CD70:
    // 0x8004CD70: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
L_8004CD74:
    // 0x8004CD74: sb          $t6, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r14;
    // 0x8004CD78: sh          $zero, 0x160($s0)
    MEM_H(0X160, ctx->r16) = 0;
    // 0x8004CD7C: sh          $zero, 0x162($s0)
    MEM_H(0X162, ctx->r16) = 0;
    // 0x8004CD80: jal         0x800575EC
    // 0x8004CD84: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
    func_800575EC(rdram, ctx);
        goto after_3;
    // 0x8004CD84: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
    after_3:
    // 0x8004CD88: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8004CD8C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004CD90: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x8004CD94: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8004CD98: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004CD9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CDA0: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x8004CDA4: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x8004CDA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004CDAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004CDB0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004CDB4: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8004CDB8: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004CDBC: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8004CDC0: sh          $t9, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r25;
    // 0x8004CDC4: jal         0x8006FC30
    // 0x8004CDC8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_4;
    // 0x8004CDC8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_4:
    // 0x8004CDCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CDD0: addiu       $t3, $s0, 0x44
    ctx->r11 = ADD32(ctx->r16, 0X44);
    // 0x8004CDD4: addiu       $t4, $s0, 0x48
    ctx->r12 = ADD32(ctx->r16, 0X48);
    // 0x8004CDD8: addiu       $t5, $s0, 0x4C
    ctx->r13 = ADD32(ctx->r16, 0X4C);
    // 0x8004CDDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004CDE0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004CDE4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004CDE8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8004CDEC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004CDF0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004CDF4: jal         0x8006F64C
    // 0x8004CDF8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_5;
    // 0x8004CDF8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x8004CDFC: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8004CE00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CE04: sw          $t6, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r14;
    // 0x8004CE08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CE0C: jal         0x800535C4
    // 0x8004CE10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_6;
    // 0x8004CE10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8004CE14: jal         0x80053664
    // 0x8004CE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_7;
    // 0x8004CE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004CE1C: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x8004CE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CE24: jal         0x80053750
    // 0x8004CE28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_8;
    // 0x8004CE28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8004CE2C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8004CE30: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CE34: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x8004CE38: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004CE3C: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8004CE40: bgez        $v0, L_8004CE50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004CE44: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8004CE50;
    }
    // 0x8004CE44: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8004CE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004CE4C: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8004CE50:
    // 0x8004CE50: bne         $at, $zero, L_8004CE5C
    if (ctx->r1 != 0) {
        // 0x8004CE54: nop
    
            goto L_8004CE5C;
    }
    // 0x8004CE54: nop

    // 0x8004CE58: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8004CE5C:
    // 0x8004CE5C: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8004CE60: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004CE64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004CE68: beq         $t0, $t9, L_8004CE7C
    if (ctx->r8 == ctx->r25) {
        // 0x8004CE6C: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_8004CE7C;
    }
    // 0x8004CE6C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8004CE70: lb          $a3, 0x1E1($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CE74: b           L_8004CFCC
    // 0x8004CE78: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
        goto L_8004CFCC;
    // 0x8004CE78: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
L_8004CE7C:
    // 0x8004CE7C: lw          $a1, 0x158($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X158);
    // 0x8004CE80: nop

    // 0x8004CE84: beq         $a1, $zero, L_8004CFC8
    if (ctx->r5 == 0) {
        // 0x8004CE88: nop
    
            goto L_8004CFC8;
    }
    // 0x8004CE88: nop

    // 0x8004CE8C: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CE90: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CE94: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CE98: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004CE9C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CEA0: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004CEA4: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004CEA8: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8004CEAC: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CEB0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004CEB4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004CEB8: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x8004CEBC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004CEC0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004CEC4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004CEC8: jal         0x800C9AD0
    // 0x8004CECC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8004CECC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x8004CED0: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x8004CED4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004CED8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004CEDC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004CEE0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004CEE4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8004CEE8: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8004CEEC: bc1f        L_8004CF58
    if (!c1cs) {
        // 0x8004CEF0: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8004CF58;
    }
    // 0x8004CEF0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004CEF4: lw          $a2, 0x64($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X64);
    // 0x8004CEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004CEFC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
L_8004CF00:
    // 0x8004CF00: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
    // 0x8004CF04: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004CF08: nop

    // 0x8004CF0C: beq         $a0, $zero, L_8004CF34
    if (ctx->r4 == 0) {
        // 0x8004CF10: nop
    
            goto L_8004CF34;
    }
    // 0x8004CF10: nop

    // 0x8004CF14: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004CF18: nop

    // 0x8004CF1C: beq         $t4, $a0, L_8004CF38
    if (ctx->r12 == ctx->r4) {
        // 0x8004CF20: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004CF38;
    }
    // 0x8004CF20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004CF24: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
    // 0x8004CF28: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004CF2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004CF30: sw          $t5, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r13;
L_8004CF34:
    // 0x8004CF34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004CF38:
    // 0x8004CF38: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004CF3C: bne         $at, $zero, L_8004CF00
    if (ctx->r1 != 0) {
        // 0x8004CF40: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8004CF00;
    }
    // 0x8004CF40: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8004CF44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004CF48: beq         $v0, $at, L_8004CFC8
    if (ctx->r2 == ctx->r1) {
        // 0x8004CF4C: nop
    
            goto L_8004CFC8;
    }
    // 0x8004CF4C: nop

    // 0x8004CF50: b           L_8004CFC8
    // 0x8004CF54: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
        goto L_8004CFC8;
    // 0x8004CF54: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
L_8004CF58:
    // 0x8004CF58: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004CF5C: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CF60: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004CF64: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8004CF68: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CF6C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CF70: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8004CF74: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8004CF78: nop

    // 0x8004CF7C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004CF80: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8004CF84: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8004CF88: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8004CF8C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004CF90: add.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8004CF94: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004CF98: nop

    // 0x8004CF9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004CFA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004CFA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004CFA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004CFAC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8004CFB0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8004CFB4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004CFB8: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x8004CFBC: mflo        $a3
    ctx->r7 = lo;
    // 0x8004CFC0: nop

    // 0x8004CFC4: nop

L_8004CFC8:
    // 0x8004CFC8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
L_8004CFCC:
    // 0x8004CFCC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004CFD0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004CFD4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004CFD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004CFDC: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8004CFE0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004CFE4: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8004CFE8: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004CFEC: div.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8004CFF0: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004CFF4: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004CFF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004CFFC: addiu       $t1, $t1, -0x2AA4
    ctx->r9 = ADD32(ctx->r9, -0X2AA4);
    // 0x8004D000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004D004: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004D008: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D00C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8004D010: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D014: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004D018: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004D01C: nop

    // 0x8004D020: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D024: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004D028: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004D02C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004D030: nop

    // 0x8004D034: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004D038: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004D03C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004D040: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8004D044: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D048: bne         $t0, $t8, L_8004D058
    if (ctx->r8 != ctx->r24) {
        // 0x8004D04C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004D058;
    }
    // 0x8004D04C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D050: lwc1        $f2, 0x6580($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6580);
    // 0x8004D054: nop

L_8004D058:
    // 0x8004D058: lh          $t9, 0x19A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X19A);
    // 0x8004D05C: nop

    // 0x8004D060: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004D064: sh          $t3, 0x19A($s0)
    MEM_H(0X19A, ctx->r16) = ctx->r11;
    // 0x8004D068: lh          $t4, 0x19A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X19A);
    // 0x8004D06C: nop

    // 0x8004D070: slti        $at, $t4, 0x259
    ctx->r1 = SIGNED(ctx->r12) < 0X259 ? 1 : 0;
    // 0x8004D074: bne         $at, $zero, L_8004D0A0
    if (ctx->r1 != 0) {
        // 0x8004D078: nop
    
            goto L_8004D0A0;
    }
    // 0x8004D078: nop

    // 0x8004D07C: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D080: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004D084: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8004D088: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004D08C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004D090: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004D094: bltz        $t6, L_8004D0A0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8004D098: nop
    
            goto L_8004D0A0;
    }
    // 0x8004D098: nop

    // 0x8004D09C: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
L_8004D0A0:
    // 0x8004D0A0: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004D0A4: nop

    // 0x8004D0A8: bne         $t8, $zero, L_8004D0F0
    if (ctx->r24 != 0) {
        // 0x8004D0AC: nop
    
            goto L_8004D0F0;
    }
    // 0x8004D0AC: nop

    // 0x8004D0B0: lb          $t9, 0x1E0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004D0B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D0B8: lwc1        $f2, 0x6584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6584);
    // 0x8004D0BC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004D0C0: sb          $t3, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r11;
    // 0x8004D0C4: lb          $t4, 0x1E0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004D0C8: nop

    // 0x8004D0CC: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x8004D0D0: bne         $at, $zero, L_8004D0F4
    if (ctx->r1 != 0) {
        // 0x8004D0D4: nop
    
            goto L_8004D0F4;
    }
    // 0x8004D0D4: nop

    // 0x8004D0D8: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D0DC: nop

    // 0x8004D0E0: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8004D0E4: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004D0E8: b           L_8004D0F4
    // 0x8004D0EC: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
        goto L_8004D0F4;
    // 0x8004D0EC: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_8004D0F0:
    // 0x8004D0F0: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_8004D0F4:
    // 0x8004D0F4: lh          $v1, 0x1A0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004D0F8: lh          $t6, 0x198($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X198);
    // 0x8004D0FC: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x8004D100: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004D104: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8004D108: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004D10C: bne         $at, $zero, L_8004D11C
    if (ctx->r1 != 0) {
        // 0x8004D110: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D11C;
    }
    // 0x8004D110: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D114: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D118: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004D11C:
    // 0x8004D11C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004D120: beq         $at, $zero, L_8004D12C
    if (ctx->r1 == 0) {
        // 0x8004D124: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D12C;
    }
    // 0x8004D124: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D128: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004D12C:
    // 0x8004D12C: slti        $at, $v0, 0x1001
    ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    // 0x8004D130: beq         $at, $zero, L_8004D144
    if (ctx->r1 == 0) {
        // 0x8004D134: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8004D144;
    }
    // 0x8004D134: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8004D138: slti        $at, $v0, -0x1000
    ctx->r1 = SIGNED(ctx->r2) < -0X1000 ? 1 : 0;
    // 0x8004D13C: beq         $at, $zero, L_8004D14C
    if (ctx->r1 == 0) {
        // 0x8004D140: nop
    
            goto L_8004D14C;
    }
    // 0x8004D140: nop

L_8004D144:
    // 0x8004D144: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D148: nop

L_8004D14C:
    // 0x8004D14C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004D150: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8004D154: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004D158: sh          $t9, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r25;
    // 0x8004D15C: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
    // 0x8004D160: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D164: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D168: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004D16C: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D170: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x8004D174: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004D178: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004D17C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004D180: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004D184: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004D188: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004D18C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8004D190: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D194: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004D198: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D19C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004D1A0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004D1A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D1A8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004D1AC: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004D1B0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004D1B4: nop

    // 0x8004D1B8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004D1BC: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8004D1C0: lwc1        $f16, 0x20($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D1C4: nop

    // 0x8004D1C8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004D1CC: sub.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f8.d - ctx->f4.d;
    // 0x8004D1D0: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8004D1D4: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004D1D8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D1DC: nop

    // 0x8004D1E0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004D1E4: mul.d       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8004D1E8: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D1EC: nop

    // 0x8004D1F0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004D1F4: sub.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d - ctx->f18.d;
    // 0x8004D1F8: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8004D1FC: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8004D200: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004D204: nop

    // 0x8004D208: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004D20C: mul.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8004D210: sub.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d - ctx->f6.d;
    // 0x8004D214: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8004D218: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8004D21C: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004D220: lwc1        $f18, 0x6588($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6588);
    // 0x8004D224: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D228: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D22C: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8004D230: bc1f        L_8004D23C
    if (!c1cs) {
        // 0x8004D234: nop
    
            goto L_8004D23C;
    }
    // 0x8004D234: nop

    // 0x8004D238: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D23C:
    // 0x8004D23C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004D240: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D244: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D248: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D24C: lwc1        $f12, 0x658C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X658C);
    // 0x8004D250: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D254: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D258: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D25C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004D260: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004D264: nop

    // 0x8004D268: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D26C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004D270: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D274: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D278: nop

    // 0x8004D27C: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D280: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004D284: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D288: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004D28C: nop

    // 0x8004D290: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D294: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D298: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8004D29C: bc1f        L_8004D2A8
    if (!c1cs) {
        // 0x8004D2A0: nop
    
            goto L_8004D2A8;
    }
    // 0x8004D2A0: nop

    // 0x8004D2A4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D2A8:
    // 0x8004D2A8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004D2AC: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D2B0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D2B4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D2B8: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D2BC: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D2C0: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8004D2C4: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004D2C8: nop

    // 0x8004D2CC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D2D0: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004D2D4: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D2D8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004D2DC: nop

    // 0x8004D2E0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D2E4: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8004D2E8: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D2EC: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8004D2F0: nop

    // 0x8004D2F4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D2F8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D2FC: mul.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8004D300: bc1f        L_8004D30C
    if (!c1cs) {
        // 0x8004D304: nop
    
            goto L_8004D30C;
    }
    // 0x8004D304: nop

    // 0x8004D308: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D30C:
    // 0x8004D30C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004D310: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D314: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D318: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D31C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004D320: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D324: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D328: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D32C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004D330: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D334: nop

    // 0x8004D338: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D33C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004D340: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D344: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004D348: nop

    // 0x8004D34C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D350: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004D354: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D358: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8004D35C: lw          $t3, -0x2AAC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AAC);
    // 0x8004D360: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004D364: lh          $t7, 0x1A0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004D368: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8004D36C: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8004D370: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8004D374: sh          $t6, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r14;
    // 0x8004D378: lh          $t8, 0x1A2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004D37C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004D380: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D384: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x8004D388: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004D38C: lw          $t3, -0x2AA8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AA8);
    // 0x8004D390: lh          $t7, 0x1A4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004D394: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x8004D398: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8004D39C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8004D3A0: sh          $t6, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r14;
    // 0x8004D3A4: lh          $t8, 0x1A6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004D3A8: lwc1        $f2, 0xDC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004D3AC: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D3B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D3B4: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D3B8: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x8004D3BC: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004D3C0: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
    // 0x8004D3C4: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D3C8: nop

    // 0x8004D3CC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004D3D0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8004D3D4: mul.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8004D3D8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004D3DC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004D3E0: jal         0x80011570
    // 0x8004D3E4: nop

    move_object(rdram, ctx);
        goto after_10;
    // 0x8004D3E4: nop

    after_10:
    // 0x8004D3E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004D3EC: addiu       $t1, $t1, -0x2AA4
    ctx->r9 = ADD32(ctx->r9, -0X2AA4);
    // 0x8004D3F0: beq         $v0, $zero, L_8004D40C
    if (ctx->r2 == 0) {
        // 0x8004D3F4: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8004D40C;
    }
    // 0x8004D3F4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004D3F8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8004D3FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004D400: beq         $t0, $t3, L_8004D40C
    if (ctx->r8 == ctx->r11) {
        // 0x8004D404: nop
    
            goto L_8004D40C;
    }
    // 0x8004D404: nop

    // 0x8004D408: sb          $t4, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r12;
L_8004D40C:
    // 0x8004D40C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8004D410: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D414: bne         $t0, $t5, L_8004D434
    if (ctx->r8 != ctx->r13) {
        // 0x8004D418: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004D434;
    }
    // 0x8004D418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D41C: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D424: jal         0x80055A84
    // 0x8004D428: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_11;
    // 0x8004D428: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8004D42C: b           L_8004D440
    // 0x8004D430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8004D440;
    // 0x8004D430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004D434:
    // 0x8004D434: jal         0x80054FD0
    // 0x8004D438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_12;
    // 0x8004D438: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8004D43C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004D440:
    // 0x8004D440: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D444: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004D448: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004D44C: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004D450: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004D454: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004D458: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004D45C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004D460: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004D464: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004D468: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8004D46C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004D470: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x8004D474: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8004D478: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004D47C: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004D480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D484: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004D488: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004D48C: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004D490: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8004D494: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x8004D498: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004D49C: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004D4A0: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x8004D4A4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8004D4A8: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004D4AC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004D4B0: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8004D4B4: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x8004D4B8: swc1        $f14, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f14.u32l;
    // 0x8004D4BC: swc1        $f14, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f14.u32l;
    // 0x8004D4C0: swc1        $f14, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f14.u32l;
    // 0x8004D4C4: jal         0x8006FE74
    // 0x8004D4C8: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_13;
    // 0x8004D4C8: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    after_13:
    // 0x8004D4CC: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8004D4D0: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8004D4D4: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8004D4D8: addiu       $t3, $s0, 0x30
    ctx->r11 = ADD32(ctx->r16, 0X30);
    // 0x8004D4DC: addiu       $t4, $s0, 0x34
    ctx->r12 = ADD32(ctx->r16, 0X34);
    // 0x8004D4E0: addiu       $t5, $s0, 0x2C
    ctx->r13 = ADD32(ctx->r16, 0X2C);
    // 0x8004D4E4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004D4E8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8004D4EC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004D4F0: jal         0x8006F64C
    // 0x8004D4F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x8004D4F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_14:
    // 0x8004D4F8: lw          $a3, 0xDC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XDC);
    // 0x8004D4FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D500: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004D504: jal         0x800580B4
    // 0x8004D508: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    second_racer_camera_update(rdram, ctx);
        goto after_15;
    // 0x8004D508: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_15:
    // 0x8004D50C: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8004D510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D514: beq         $v0, $zero, L_8004D564
    if (ctx->r2 == 0) {
        // 0x8004D518: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D564;
    }
    // 0x8004D518: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D51C: lb          $t6, 0x1D7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D520: nop

    // 0x8004D524: bne         $t6, $zero, L_8004D564
    if (ctx->r14 != 0) {
        // 0x8004D528: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D564;
    }
    // 0x8004D528: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D52C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8004D530: nop

    // 0x8004D534: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8004D538: bne         $at, $zero, L_8004D564
    if (ctx->r1 != 0) {
        // 0x8004D53C: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D564;
    }
    // 0x8004D53C: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D540: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8004D544: nop

    // 0x8004D548: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8004D54C: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x8004D550: nop

    // 0x8004D554: lw          $a1, 0x10($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X10);
    // 0x8004D558: nop

    // 0x8004D55C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8004D560: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
L_8004D564:
    // 0x8004D564: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004D568: beq         $t9, $zero, L_8004D580
    if (ctx->r25 == 0) {
        // 0x8004D56C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004D580;
    }
    // 0x8004D56C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D570: lb          $t3, 0x1D7($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D574: jal         0x800230D0
    // 0x8004D578: sb          $t3, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r11;
    func_800230D0(rdram, ctx);
        goto after_16;
    // 0x8004D578: sb          $t3, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r11;
    after_16:
    // 0x8004D57C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004D580:
    // 0x8004D580: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004D584: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004D588: jr          $ra
    // 0x8004D58C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8004D58C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void unload_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C422C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4230: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4234: lw          $t6, -0x5820($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5820);
    // 0x800C4238: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C423C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C4240: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C4244: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C4248: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C424C: beq         $at, $zero, L_800C42D0
    if (ctx->r1 == 0) {
        // 0x800C4250: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C42D0;
    }
    // 0x800C4250: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C4254: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4258: lw          $t8, -0x581C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X581C);
    // 0x800C425C: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C4260: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4264: lbu         $v0, 0x28($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X28);
    // 0x800C4268: nop

    // 0x800C426C: blez        $v0, L_800C42D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C4270: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800C42D0;
    }
    // 0x800C4270: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800C4274: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800C4278: bne         $t0, $zero, L_800C42D0
    if (ctx->r8 != 0) {
        // 0x800C427C: sb          $t9, 0x28($s2)
        MEM_B(0X28, ctx->r18) = ctx->r25;
            goto L_800C42D0;
    }
    // 0x800C427C: sb          $t9, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r25;
    // 0x800C4280: lh          $t1, 0x40($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X40);
    // 0x800C4284: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C4288: beq         $s3, $t1, L_800C42D0
    if (ctx->r19 == ctx->r9) {
        // 0x800C428C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800C42D0;
    }
    // 0x800C428C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C4290: sll         $t2, $zero, 2
    ctx->r10 = S32(0 << 2);
    // 0x800C4294: addu        $s0, $s2, $t2
    ctx->r16 = ADD32(ctx->r18, ctx->r10);
L_800C4298:
    // 0x800C4298: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x800C429C: jal         0x8007B2BC
    // 0x800C42A0: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800C42A0: nop

    after_0:
    // 0x800C42A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C42A8: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800C42AC: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x800C42B0: beq         $at, $zero, L_800C42D0
    if (ctx->r1 == 0) {
        // 0x800C42B4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C42D0;
    }
    // 0x800C42B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C42B8: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800C42BC: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x800C42C0: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x800C42C4: nop

    // 0x800C42C8: bne         $s3, $t5, L_800C4298
    if (ctx->r19 != ctx->r13) {
        // 0x800C42CC: nop
    
            goto L_800C4298;
    }
    // 0x800C42CC: nop

L_800C42D0:
    // 0x800C42D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C42D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C42D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C42DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C42E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C42E4: jr          $ra
    // 0x800C42E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C42E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void savemenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B9C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80085BA0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80085BA4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80085BA8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80085BAC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80085BB0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80085BB4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80085BB8: jal         0x8007A520
    // 0x80085BBC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80085BBC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80085BC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80085BC4: lw          $v1, 0x63E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63E0);
    // 0x80085BC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80085BCC: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80085BD0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80085BD4: addu        $at, $at, $t6
    gpr jr_addend_80085BF0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80085BD8: lw          $t6, -0x7C20($at)
    ctx->r14 = ADD32(ctx->r1, -0X7C20);
    // 0x80085BDC: andi        $s4, $v0, 0xFFFF
    ctx->r20 = ctx->r2 & 0XFFFF;
    // 0x80085BE0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80085BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085BE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80085BEC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80085BF0: jr          $t6
    // 0x80085BF4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    switch (jr_addend_80085BF0 >> 2) {
        case 0: goto L_80085C30; break;
        case 1: goto L_80085BF8; break;
        case 2: goto L_80085BF8; break;
        case 3: goto L_80085C00; break;
        case 4: goto L_80085C00; break;
        case 5: goto L_80085C08; break;
        case 6: goto L_80085C14; break;
        case 7: goto L_80085C24; break;
        default: switch_error(__func__, 0x80085BF0, 0x800E83E0);
    }
    // 0x80085BF4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80085BF8:
    // 0x80085BF8: b           L_80085C30
    // 0x80085BFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80085C30;
    // 0x80085BFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80085C00:
    // 0x80085C00: b           L_80085C30
    // 0x80085C04: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80085C30;
    // 0x80085C04: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80085C08:
    // 0x80085C08: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80085C0C: b           L_80085C30
    // 0x80085C10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80085C30;
    // 0x80085C10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80085C14:
    // 0x80085C14: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80085C18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80085C1C: b           L_80085C30
    // 0x80085C20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80085C30;
    // 0x80085C20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80085C24:
    // 0x80085C24: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80085C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80085C2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80085C30:
    // 0x80085C30: andi        $t7, $v1, 0x8
    ctx->r15 = ctx->r3 & 0X8;
    // 0x80085C34: beq         $t7, $zero, L_80085C40
    if (ctx->r15 == 0) {
        // 0x80085C38: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80085C40;
    }
    // 0x80085C38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085C3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80085C40:
    // 0x80085C40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085C44: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80085C48: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085C4C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80085C50: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80085C54: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80085C58: jal         0x80067F2C
    // 0x80085C5C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x80085C5C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x80085C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085C68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085C6C: jal         0x800C43CC
    // 0x80085C70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x80085C70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80085C74: jal         0x800C42EC
    // 0x80085C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_3;
    // 0x80085C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80085C7C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80085C80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085C84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085C90: jal         0x800C4384
    // 0x80085C94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80085C94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x80085C98: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085C9C: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x80085CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085CA4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80085CA8: lw          $a3, 0x294($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X294);
    // 0x80085CAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80085CB0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085CB4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80085CB8: jal         0x800C4440
    // 0x80085CBC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80085CBC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_5:
    // 0x80085CC0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80085CC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085CC8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085CCC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80085CD0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085CD4: jal         0x800C4384
    // 0x80085CD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x80085CD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80085CDC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80085CE0: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x80085CE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085CE8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80085CEC: lw          $a3, 0x294($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X294);
    // 0x80085CF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085CF4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085CF8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80085CFC: jal         0x800C4440
    // 0x80085D00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_7;
    // 0x80085D00: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_7:
    // 0x80085D04: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80085D08: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80085D0C: beq         $t6, $zero, L_80085D8C
    if (ctx->r14 == 0) {
        // 0x80085D10: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80085D8C;
    }
    // 0x80085D10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80085D14: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80085D18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80085D1C: bne         $t7, $zero, L_80085D2C
    if (ctx->r15 != 0) {
        // 0x80085D20: lui         $s1, 0x800E
        ctx->r17 = S32(0X800E << 16);
            goto L_80085D2C;
    }
    // 0x80085D20: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80085D24: b           L_80085D30
    // 0x80085D28: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
        goto L_80085D30;
    // 0x80085D28: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
L_80085D2C:
    // 0x80085D2C: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
L_80085D30:
    // 0x80085D30: lw          $t8, 0x63BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63BC);
    // 0x80085D34: addiu       $s1, $s1, 0x43C
    ctx->r17 = ADD32(ctx->r17, 0X43C);
    // 0x80085D38: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x80085D3C: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80085D40: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
L_80085D44:
    // 0x80085D44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085D48: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80085D4C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80085D50: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80085D54: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80085D58: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80085D5C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80085D60: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80085D64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085D68: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085D6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80085D70: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80085D74: jal         0x80078AB8
    // 0x80085D78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x80085D78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x80085D7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80085D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085D84: bne         $s2, $at, L_80085D44
    if (ctx->r18 != ctx->r1) {
        // 0x80085D88: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80085D44;
    }
    // 0x80085D88: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80085D8C:
    // 0x80085D8C: beq         $s3, $zero, L_80085EB8
    if (ctx->r19 == 0) {
        // 0x80085D90: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80085EB8;
    }
    // 0x80085D90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085D94: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80085D98: lwc1        $f0, 0x6BDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6BDC);
    // 0x80085D9C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80085DA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80085DA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80085DA8: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x80085DAC: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80085DB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80085DB4: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x80085DB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80085DBC: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x80085DC0: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80085DC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80085DC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80085DCC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80085DD0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80085DD4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80085DD8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80085DDC: nop

    // 0x80085DE0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80085DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80085DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80085DEC: nop

    // 0x80085DF0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80085DF4: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80085DF8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80085DFC: subu        $v0, $t2, $t9
    ctx->r2 = SUB32(ctx->r10, ctx->r25);
    // 0x80085E00: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085E04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80085E08: beq         $at, $zero, L_80085E6C
    if (ctx->r1 == 0) {
        // 0x80085E0C: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_80085E6C;
    }
    // 0x80085E0C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80085E10: lw          $t3, 0x6A08($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A08);
    // 0x80085E14: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80085E18: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80085E1C: beq         $at, $zero, L_80085E6C
    if (ctx->r1 == 0) {
        // 0x80085E20: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80085E6C;
    }
    // 0x80085E20: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80085E24: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80085E28: addiu       $s3, $s3, 0x6A0C
    ctx->r19 = ADD32(ctx->r19, 0X6A0C);
L_80085E2C:
    // 0x80085E2C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80085E30: sll         $t4, $s0, 4
    ctx->r12 = S32(ctx->r16 << 4);
    // 0x80085E34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80085E38: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80085E3C: jal         0x800853D0
    // 0x80085E40: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    savemenu_render_element(rdram, ctx);
        goto after_9;
    // 0x80085E40: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_9:
    // 0x80085E44: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x80085E48: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085E4C: beq         $at, $zero, L_80085E6C
    if (ctx->r1 == 0) {
        // 0x80085E50: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80085E6C;
    }
    // 0x80085E50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80085E54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80085E58: lw          $t6, 0x6A08($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A08);
    // 0x80085E5C: nop

    // 0x80085E60: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80085E64: bne         $at, $zero, L_80085E2C
    if (ctx->r1 != 0) {
        // 0x80085E68: nop
    
            goto L_80085E2C;
    }
    // 0x80085E68: nop

L_80085E6C:
    // 0x80085E6C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80085E70: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80085E74: addiu       $s3, $s3, 0x6A0C
    ctx->r19 = ADD32(ctx->r19, 0X6A0C);
    // 0x80085E78: blez        $s1, L_80085EB8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80085E7C: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80085EB8;
    }
    // 0x80085E7C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80085E80: blez        $s2, L_80085EBC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80085E84: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80085EBC;
    }
    // 0x80085E84: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_80085E88:
    // 0x80085E88: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80085E8C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80085E90: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x80085E94: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x80085E98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80085E9C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80085EA0: jal         0x800853D0
    // 0x80085EA4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    savemenu_render_element(rdram, ctx);
        goto after_10;
    // 0x80085EA4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x80085EA8: blez        $s1, L_80085EBC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80085EAC: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80085EBC;
    }
    // 0x80085EAC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80085EB0: bgtz        $s0, L_80085E88
    if (SIGNED(ctx->r16) > 0) {
        // 0x80085EB4: nop
    
            goto L_80085E88;
    }
    // 0x80085EB4: nop

L_80085EB8:
    // 0x80085EB8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_80085EBC:
    // 0x80085EBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085EC0: beq         $t2, $zero, L_80085FE0
    if (ctx->r10 == 0) {
        // 0x80085EC4: nop
    
            goto L_80085FE0;
    }
    // 0x80085EC4: nop

    // 0x80085EC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80085ECC: lwc1        $f0, 0x6BEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6BEC);
    // 0x80085ED0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80085ED4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80085ED8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80085EDC: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x80085EE0: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80085EE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80085EE8: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80085EEC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80085EF0: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80085EF4: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x80085EF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80085EFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80085F00: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80085F04: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80085F08: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80085F0C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80085F10: nop

    // 0x80085F14: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80085F18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80085F1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80085F20: nop

    // 0x80085F24: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80085F28: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80085F2C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80085F30: subu        $s1, $t5, $t4
    ctx->r17 = SUB32(ctx->r13, ctx->r12);
    // 0x80085F34: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085F38: beq         $at, $zero, L_80085F94
    if (ctx->r1 == 0) {
        // 0x80085F3C: sw          $s1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r17;
            goto L_80085F94;
    }
    // 0x80085F3C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80085F40: lw          $t7, 0x6A00($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A00);
    // 0x80085F44: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80085F48: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80085F4C: beq         $at, $zero, L_80085F94
    if (ctx->r1 == 0) {
        // 0x80085F50: addiu       $s3, $s3, 0x6A04
        ctx->r19 = ADD32(ctx->r19, 0X6A04);
            goto L_80085F94;
    }
    // 0x80085F50: addiu       $s3, $s3, 0x6A04
    ctx->r19 = ADD32(ctx->r19, 0X6A04);
L_80085F54:
    // 0x80085F54: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80085F58: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x80085F5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80085F60: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80085F64: jal         0x800853D0
    // 0x80085F68: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    savemenu_render_element(rdram, ctx);
        goto after_11;
    // 0x80085F68: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    after_11:
    // 0x80085F6C: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x80085F70: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80085F74: beq         $at, $zero, L_80085F94
    if (ctx->r1 == 0) {
        // 0x80085F78: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80085F94;
    }
    // 0x80085F78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80085F7C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085F80: lw          $t9, 0x6A00($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A00);
    // 0x80085F84: nop

    // 0x80085F88: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80085F8C: bne         $at, $zero, L_80085F54
    if (ctx->r1 != 0) {
        // 0x80085F90: nop
    
            goto L_80085F54;
    }
    // 0x80085F90: nop

L_80085F94:
    // 0x80085F94: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80085F98: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80085F9C: addiu       $s3, $s3, 0x6A04
    ctx->r19 = ADD32(ctx->r19, 0X6A04);
    // 0x80085FA0: blez        $s1, L_80085FE0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80085FA4: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80085FE0;
    }
    // 0x80085FA4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80085FA8: blez        $s2, L_80085FE0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80085FAC: nop
    
            goto L_80085FE0;
    }
    // 0x80085FAC: nop

L_80085FB0:
    // 0x80085FB0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80085FB4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80085FB8: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x80085FBC: sll         $t5, $s0, 4
    ctx->r13 = S32(ctx->r16 << 4);
    // 0x80085FC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80085FC4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80085FC8: jal         0x800853D0
    // 0x80085FCC: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    savemenu_render_element(rdram, ctx);
        goto after_12;
    // 0x80085FCC: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    after_12:
    // 0x80085FD0: blez        $s1, L_80085FE0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80085FD4: nop
    
            goto L_80085FE0;
    }
    // 0x80085FD4: nop

    // 0x80085FD8: bgtz        $s0, L_80085FB0
    if (SIGNED(ctx->r16) > 0) {
        // 0x80085FDC: nop
    
            goto L_80085FB0;
    }
    // 0x80085FDC: nop

L_80085FE0:
    // 0x80085FE0: jal         0x800C42EC
    // 0x80085FE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_13;
    // 0x80085FE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80085FE8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80085FEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085FF0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085FF4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80085FF8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085FFC: jal         0x800C4384
    // 0x80086000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x80086000: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80086004: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80086008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008600C: beq         $t7, $zero, L_80086030
    if (ctx->r15 == 0) {
        // 0x80086010: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80086030;
    }
    // 0x80086010: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80086014: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80086018: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008601C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80086020: addiu       $a3, $a3, -0x7DF8
    ctx->r7 = ADD32(ctx->r7, -0X7DF8);
    // 0x80086024: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086028: jal         0x800C4440
    // 0x8008602C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008602C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_15:
L_80086030:
    // 0x80086030: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086034: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086038: beq         $t2, $zero, L_80086060
    if (ctx->r10 == 0) {
        // 0x8008603C: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80086060;
    }
    // 0x8008603C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80086040: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80086044: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x80086048: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8008604C: lw          $a3, 0x1F0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X1F0);
    // 0x80086050: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086054: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086058: jal         0x800C4440
    // 0x8008605C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8008605C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_16:
L_80086060:
    // 0x80086060: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80086064: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086068: beq         $t5, $zero, L_80086080
    if (ctx->r13 == 0) {
        // 0x8008606C: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80086080;
    }
    // 0x8008606C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80086070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80086074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086078: jal         0x800C5B58
    // 0x8008607C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_17;
    // 0x8008607C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_17:
L_80086080:
    // 0x80086080: jal         0x80080E6C
    // 0x80086084: nop

    menu_geometry_end(rdram, ctx);
        goto after_18;
    // 0x80086084: nop

    after_18:
    // 0x80086088: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008608C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80086090: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80086094: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80086098: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008609C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800860A0: jr          $ra
    // 0x800860A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800860A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void cam_get_viewport_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066210: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066214: lw          $v0, 0xCE0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XCE0);
    // 0x80066218: jr          $ra
    // 0x8006621C: nop

    return;
    // 0x8006621C: nop

;}
RECOMP_FUNC void func_80074AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074AA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074AB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074AB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80074AB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80074ABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80074AC0: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80074AC4: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80074AC8: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80074ACC: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80074AD0: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x80074AD4: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x80074AD8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074AE0: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80074AE4: sll         $a2, $t7, 2
    ctx->r6 = S32(ctx->r15 << 2);
    // 0x80074AE8: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80074AEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074AF0: subu        $a2, $a2, $t7
    ctx->r6 = SUB32(ctx->r6, ctx->r15);
    // 0x80074AF4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80074AF8: jal         0x800C9DA0
    // 0x80074AFC: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    _bcopy(rdram, ctx);
        goto after_0;
    // 0x80074AFC: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80074B00: jal         0x80074A4C
    // 0x80074B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_1;
    // 0x80074B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80074B08: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80074B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074B10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074B14: jr          $ra
    // 0x80074B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void menu_image_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C904: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009C908: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009C90C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009C910: addiu       $s1, $s1, -0x8A4
    ctx->r17 = ADD32(ctx->r17, -0X8A4);
    // 0x8009C914: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8009C918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C91C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8009C920: bne         $a2, $zero, L_8009C940
    if (ctx->r6 != 0) {
        // 0x8009C924: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8009C940;
    }
    // 0x8009C924: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009C928: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8009C92C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8009C930: jal         0x80070C9C
    // 0x8009C934: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8009C934: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    after_0:
    // 0x8009C938: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009C93C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8009C940:
    // 0x8009C940: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009C944: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C948: addiu       $t7, $t7, -0xAF0
    ctx->r15 = ADD32(ctx->r15, -0XAF0);
    // 0x8009C94C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x8009C950: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8009C954: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8009C958: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x8009C95C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8009C960: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009C964: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x8009C968: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8009C96C: sh          $t0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r8;
    // 0x8009C970: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009C974: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x8009C978: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8009C97C: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x8009C980: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009C984: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009C988: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x8009C98C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8009C990: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x8009C994: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009C998: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009C99C: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8009C9A0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8009C9A4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009C9A8: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8009C9AC: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x8009C9B0: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009C9B4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009C9B8: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8009C9BC: addu        $t3, $t4, $s0
    ctx->r11 = ADD32(ctx->r12, ctx->r16);
    // 0x8009C9C0: swc1        $f8, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f8.u32l;
    // 0x8009C9C4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8009C9C8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009C9CC: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8009C9D0: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x8009C9D4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009C9D8: lh          $t6, 0x18($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X18);
    // 0x8009C9DC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8009C9E0: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x8009C9E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009C9E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C9EC: jal         0x8006F94C
    // 0x8009C9F0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009C9F0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_1:
    // 0x8009C9F4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009C9F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C9FC: addu        $t0, $t1, $s0
    ctx->r8 = ADD32(ctx->r9, ctx->r16);
    // 0x8009CA00: sb          $v0, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r2;
    // 0x8009CA04: jal         0x8006F94C
    // 0x8009CA08: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8009CA08: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8009CA0C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8009CA10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CA14: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x8009CA18: sb          $v0, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r2;
    // 0x8009CA1C: jal         0x8006F94C
    // 0x8009CA20: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8009CA20: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8009CA24: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009CA28: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009CA2C: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x8009CA30: sb          $v0, 0x1C($t5)
    MEM_B(0X1C, ctx->r13) = ctx->r2;
    // 0x8009CA34: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009CA38: lb          $t7, 0x1D($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D);
    // 0x8009CA3C: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8009CA40: sb          $t7, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r15;
    // 0x8009CA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CA48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8009CA4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8009CA50: jr          $ra
    // 0x8009CA54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009CA54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void allocate_object_model_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F858: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005F85C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005F860: jal         0x80070C9C
    // 0x8005F864: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8005F864: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    after_0:
    // 0x8005F868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F86C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005F870: sw          $v0, -0x29DC($at)
    MEM_W(-0X29DC, ctx->r1) = ctx->r2;
    // 0x8005F874: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005F878: jal         0x80070C9C
    // 0x8005F87C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8005F87C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_1:
    // 0x8005F880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F884: sw          $v0, -0x29D8($at)
    MEM_W(-0X29D8, ctx->r1) = ctx->r2;
    // 0x8005F888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F88C: sw          $zero, -0x29D4($at)
    MEM_W(-0X29D4, ctx->r1) = 0;
    // 0x8005F890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F894: sw          $zero, -0x29CC($at)
    MEM_W(-0X29CC, ctx->r1) = 0;
    // 0x8005F898: jal         0x80076C58
    // 0x8005F89C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8005F89C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8005F8A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F8A4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005F8A8: addiu       $a3, $a3, -0x29E0
    ctx->r7 = ADD32(ctx->r7, -0X29E0);
    // 0x8005F8AC: addiu       $a1, $a1, -0x29D0
    ctx->r5 = ADD32(ctx->r5, -0X29D0);
    // 0x8005F8B0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8005F8B4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8005F8B8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8005F8BC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005F8C0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005F8C4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005F8C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005F8CC: beq         $a2, $t8, L_8005F8F4
    if (ctx->r6 == ctx->r24) {
        // 0x8005F8D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005F8F4;
    }
    // 0x8005F8D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005F8D4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005F8D8:
    // 0x8005F8D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005F8DC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005F8E0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005F8E4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005F8E8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8005F8EC: bne         $a2, $t2, L_8005F8D8
    if (ctx->r6 != ctx->r10) {
        // 0x8005F8F0: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8005F8D8;
    }
    // 0x8005F8F0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005F8F4:
    // 0x8005F8F4: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8005F8F8: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005F8FC: jal         0x80076C58
    // 0x8005F900: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8005F900: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x8005F904: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F908: sw          $v0, -0x29C8($at)
    MEM_W(-0X29C8, ctx->r1) = ctx->r2;
    // 0x8005F90C: jal         0x80076C58
    // 0x8005F910: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8005F910: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_4:
    // 0x8005F914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F918: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005F91C: sw          $v0, -0x29C4($at)
    MEM_W(-0X29C4, ctx->r1) = ctx->r2;
    // 0x8005F920: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005F924: jal         0x80070C9C
    // 0x8005F928: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8005F928: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    after_5:
    // 0x8005F92C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F930: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005F934: lw          $a1, -0x315C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X315C);
    // 0x8005F938: sw          $v0, -0x29BC($at)
    MEM_W(-0X29BC, ctx->r1) = ctx->r2;
    // 0x8005F93C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F940: sw          $zero, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = 0;
    // 0x8005F944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F948: blez        $a1, L_8005F970
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005F94C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005F970;
    }
    // 0x8005F94C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005F950: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8005F954: addiu       $v0, $v0, 0x4D54
    ctx->r2 = ADD32(ctx->r2, 0X4D54);
L_8005F958:
    // 0x8005F958: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F95C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005F960: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005F964: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005F968: bne         $at, $zero, L_8005F958
    if (ctx->r1 != 0) {
        // 0x8005F96C: addu        $a0, $a0, $t5
        ctx->r4 = ADD32(ctx->r4, ctx->r13);
            goto L_8005F958;
    }
    // 0x8005F96C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
L_8005F970:
    // 0x8005F970: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005F974: lw          $t6, -0x3160($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3160);
    // 0x8005F978: nop

    // 0x8005F97C: beq         $a0, $t6, L_8005F990
    if (ctx->r4 == ctx->r14) {
        // 0x8005F980: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005F990;
    }
    // 0x8005F980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F984: jal         0x8005C25C
    // 0x8005F988: nop

    drm_vehicle_traction(rdram, ctx);
        goto after_6;
    // 0x8005F988: nop

    after_6:
    // 0x8005F98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005F990:
    // 0x8005F990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F994: jr          $ra
    // 0x8005F998: nop

    return;
    // 0x8005F998: nop

;}
RECOMP_FUNC void check_for_controller_pak_errors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008832C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80088330: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80088334: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80088338: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008833C: addiu       $a3, $a3, 0x6BC8
    ctx->r7 = ADD32(ctx->r7, 0X6BC8);
    // 0x80088340: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80088344: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80088348: addiu       $t6, $t6, 0x6A34
    ctx->r14 = ADD32(ctx->r14, 0X6A34);
    // 0x8008834C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80088350: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80088354: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80088358: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008835C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80088360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088364: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80088368: addiu       $t0, $t0, -0x34C
    ctx->r8 = ADD32(ctx->r8, -0X34C);
    // 0x8008836C: addiu       $t1, $t1, -0xB60
    ctx->r9 = ADD32(ctx->r9, -0XB60);
    // 0x80088370: addiu       $t3, $t3, 0x6A38
    ctx->r11 = ADD32(ctx->r11, 0X6A38);
    // 0x80088374: addiu       $t4, $t4, 0x6A60
    ctx->r12 = ADD32(ctx->r12, 0X6A60);
    // 0x80088378: addiu       $s1, $s1, 0x6A3C
    ctx->r17 = ADD32(ctx->r17, 0X6A3C);
    // 0x8008837C: addu        $a0, $zero, $t6
    ctx->r4 = ADD32(0, ctx->r14);
    // 0x80088380: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80088384: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80088388: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008838C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80088390: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80088394:
    // 0x80088394: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80088398: nop

    // 0x8008839C: beq         $t7, $zero, L_800883FC
    if (ctx->r15 == 0) {
        // 0x800883A0: addu        $t8, $t3, $v1
        ctx->r24 = ADD32(ctx->r11, ctx->r3);
            goto L_800883FC;
    }
    // 0x800883A0: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
    // 0x800883A4: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800883A8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800883AC: lw          $t8, 0x100($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X100);
    // 0x800883B0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800883B4: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x800883B8: lw          $t9, 0x100($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X100);
    // 0x800883BC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800883C0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x800883C4: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x800883C8: nop

    // 0x800883CC: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x800883D0: lw          $t9, 0x17C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X17C);
    // 0x800883D4: nop

    // 0x800883D8: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x800883DC: lw          $t6, 0x28C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28C);
    // 0x800883E0: nop

    // 0x800883E4: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
    // 0x800883E8: lw          $t7, 0x290($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X290);
    // 0x800883EC: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800883F0: b           L_800884C8
    // 0x800883F4: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
        goto L_800884C8;
    // 0x800883F4: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
    // 0x800883F8: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
L_800883FC:
    // 0x800883FC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80088400: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    // 0x80088404: beq         $t9, $zero, L_80088470
    if (ctx->r25 == 0) {
        // 0x80088408: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_80088470;
    }
    // 0x80088408: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x8008840C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80088410: nop

    // 0x80088414: bne         $t6, $zero, L_80088470
    if (ctx->r14 != 0) {
        // 0x80088418: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_80088470;
    }
    // 0x80088418: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x8008841C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088420: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80088424: lw          $t7, 0x260($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X260);
    // 0x80088428: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x8008842C: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x80088430: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x80088434: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80088438: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x8008843C: lw          $t7, 0x158($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X158);
    // 0x80088440: nop

    // 0x80088444: sw          $t7, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r15;
    // 0x80088448: lw          $t8, 0x110($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X110);
    // 0x8008844C: nop

    // 0x80088450: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
    // 0x80088454: lw          $t9, 0x188($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X188);
    // 0x80088458: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x8008845C: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x80088460: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x80088464: b           L_800884C8
    // 0x80088468: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
        goto L_800884C8;
    // 0x80088468: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
    // 0x8008846C: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80088470:
    // 0x80088470: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80088474: nop

    // 0x80088478: beq         $t7, $zero, L_800884C8
    if (ctx->r15 == 0) {
        // 0x8008847C: nop
    
            goto L_800884C8;
    }
    // 0x8008847C: nop

    // 0x80088480: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088484: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80088488: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x8008848C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80088490: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x80088494: lw          $t9, 0x260($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X260);
    // 0x80088498: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8008849C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x800884A0: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x800884A4: nop

    // 0x800884A8: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x800884AC: lw          $t9, 0x2E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2E0);
    // 0x800884B0: nop

    // 0x800884B4: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x800884B8: lw          $t6, 0x2E4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2E4);
    // 0x800884BC: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x800884C0: sw          $s2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r18;
    // 0x800884C4: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
L_800884C8:
    // 0x800884C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800884CC: bgtz        $v1, L_800884DC
    if (SIGNED(ctx->r3) > 0) {
        // 0x800884D0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800884DC;
    }
    // 0x800884D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800884D4: beq         $v0, $zero, L_80088394
    if (ctx->r2 == 0) {
        // 0x800884D8: nop
    
            goto L_80088394;
    }
    // 0x800884D8: nop

L_800884DC:
    // 0x800884DC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800884E0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800884E4: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800884E8: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800884EC: jr          $ra
    // 0x800884F0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800884F0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void set_animated_texture_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B46C: blez        $a1, L_8007B4C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B470: nop
    
            goto L_8007B4C0;
    }
    // 0x8007B470: nop

    // 0x8007B474: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8007B478: nop

    // 0x8007B47C: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x8007B480: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B484: beq         $at, $zero, L_8007B4A8
    if (ctx->r1 == 0) {
        // 0x8007B488: sra         $t0, $v0, 8
        ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
            goto L_8007B4A8;
    }
    // 0x8007B488: sra         $t0, $v0, 8
    ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8007B48C: lh          $t8, 0x16($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X16);
    // 0x8007B490: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B494: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B498: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B49C: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8007B4A0: jr          $ra
    // 0x8007B4A4: nop

    return;
    // 0x8007B4A4: nop

L_8007B4A8:
    // 0x8007B4A8: lh          $t2, 0x16($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X16);
    // 0x8007B4AC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007B4B0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B4B4: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B4B8: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B4BC: nop

L_8007B4C0:
    // 0x8007B4C0: jr          $ra
    // 0x8007B4C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8007B4C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void obj_loop_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DD14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DD18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DD1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003DD20: jal         0x8006C19C
    // 0x8003DD24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    race_is_adventure_2P(rdram, ctx);
        goto after_0;
    // 0x8003DD24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DD28: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DD2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DD30: beq         $v0, $zero, L_8003DD48
    if (ctx->r2 == 0) {
        // 0x8003DD34: nop
    
            goto L_8003DD48;
    }
    // 0x8003DD34: nop

    // 0x8003DD38: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DD40: bne         $a1, $at, L_8003DD60
    if (ctx->r5 != ctx->r1) {
        // 0x8003DD44: nop
    
            goto L_8003DD60;
    }
    // 0x8003DD44: nop

L_8003DD48:
    // 0x8003DD48: bne         $v0, $zero, L_8003DE40
    if (ctx->r2 != 0) {
        // 0x8003DD4C: nop
    
            goto L_8003DE40;
    }
    // 0x8003DD4C: nop

    // 0x8003DD50: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD54: nop

    // 0x8003DD58: bne         $a1, $zero, L_8003DE40
    if (ctx->r5 != 0) {
        // 0x8003DD5C: nop
    
            goto L_8003DE40;
    }
    // 0x8003DD5C: nop

L_8003DD60:
    // 0x8003DD60: lw          $v0, 0x4C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4C);
    // 0x8003DD64: nop

    // 0x8003DD68: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003DD6C: nop

    // 0x8003DD70: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003DD74: beq         $at, $zero, L_8003DE30
    if (ctx->r1 == 0) {
        // 0x8003DD78: nop
    
            goto L_8003DE30;
    }
    // 0x8003DD78: nop

    // 0x8003DD7C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003DD80: nop

    // 0x8003DD84: beq         $v1, $zero, L_8003DE30
    if (ctx->r3 == 0) {
        // 0x8003DD88: nop
    
            goto L_8003DE30;
    }
    // 0x8003DD88: nop

    // 0x8003DD8C: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003DD90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DD94: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DD98: nop

    // 0x8003DD9C: bne         $t8, $at, L_8003DE30
    if (ctx->r24 != ctx->r1) {
        // 0x8003DDA0: nop
    
            goto L_8003DE30;
    }
    // 0x8003DDA0: nop

    // 0x8003DDA4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003DDA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DDAC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8003DDB0: nop

    // 0x8003DDB4: beq         $a0, $at, L_8003DE30
    if (ctx->r4 == ctx->r1) {
        // 0x8003DDB8: nop
    
            goto L_8003DE30;
    }
    // 0x8003DDB8: nop

    // 0x8003DDBC: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x8003DDC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003DDC4: bne         $t9, $zero, L_8003DE30
    if (ctx->r25 != 0) {
        // 0x8003DDC8: sllv        $v1, $t0, $a0
        ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
            goto L_8003DE30;
    }
    // 0x8003DDC8: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x8003DDCC: and         $t1, $a1, $v1
    ctx->r9 = ctx->r5 & ctx->r3;
    // 0x8003DDD0: bne         $t1, $zero, L_8003DE30
    if (ctx->r9 != 0) {
        // 0x8003DDD4: or          $t2, $a1, $v1
        ctx->r10 = ctx->r5 | ctx->r3;
            goto L_8003DE30;
    }
    // 0x8003DDD4: or          $t2, $a1, $v1
    ctx->r10 = ctx->r5 | ctx->r3;
    // 0x8003DDD8: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8003DDDC: sw          $t2, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r10;
    // 0x8003DDE0: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
    // 0x8003DDE4: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8003DDE8: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x8003DDEC: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8003DDF0: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8003DDF4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8003DDF8: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003DDFC: lb          $a0, 0x202($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003DE04: addiu       $a0, $a0, 0x2B
    ctx->r4 = ADD32(ctx->r4, 0X2B);
    // 0x8003DE08: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8003DE0C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8003DE10: jal         0x80001BC0
    // 0x8003DE14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    music_jingle_play(rdram, ctx);
        goto after_1;
    // 0x8003DE14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DE18: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003DE1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DE20: lb          $t0, 0x202($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE24: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DE28: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003DE2C: sb          $t1, 0x202($v0)
    MEM_B(0X202, ctx->r2) = ctx->r9;
L_8003DE30:
    // 0x8003DE30: lh          $t2, 0x18($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X18);
    // 0x8003DE34: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8003DE38: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8003DE3C: sh          $t6, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r14;
L_8003DE40:
    // 0x8003DE40: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003DE44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003DE48: blez        $v0, L_8003DE64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003DE4C: subu        $t5, $v0, $a3
        ctx->r13 = SUB32(ctx->r2, ctx->r7);
            goto L_8003DE64;
    }
    // 0x8003DE4C: subu        $t5, $v0, $a3
    ctx->r13 = SUB32(ctx->r2, ctx->r7);
    // 0x8003DE50: sw          $t5, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r13;
    // 0x8003DE54: sw          $t4, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r12;
    // 0x8003DE58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8003DE5C: jal         0x800AFC3C
    // 0x8003DE60: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x8003DE60: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
L_8003DE64:
    // 0x8003DE64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DE68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DE6C: jr          $ra
    // 0x8003DE70: nop

    return;
    // 0x8003DE70: nop

;}
RECOMP_FUNC void obj_init_audioreverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004001C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040020: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040024: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80040028: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8004002C: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x80040030: nop

    // 0x80040034: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80040038: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8004003C: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x80040040: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
    // 0x80040044: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x80040048: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x8004004C: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x80040050: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x80040054: lh          $t1, 0x4($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X4);
    // 0x80040058: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8004005C: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x80040060: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80040064: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80040068: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x8004006C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80040070: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80040074: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80040078: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8004007C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040080: jal         0x80009968
    // 0x80040084: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    audspat_reverb_add_vertex(rdram, ctx);
        goto after_0;
    // 0x80040084: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80040088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004008C: jal         0x8000FFB8
    // 0x80040090: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80040090: nop

    after_1:
    // 0x80040094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80040098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004009C: jr          $ra
    // 0x800400A0: nop

    return;
    // 0x800400A0: nop

;}
RECOMP_FUNC void hud_time_trial_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6E30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A6E34: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A6E38: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A6E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6E44: lbu         $t6, 0x1DA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1DA);
    // 0x800A6E48: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A6E4C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800A6E50: beq         $at, $zero, L_800A717C
    if (ctx->r1 == 0) {
        // 0x800A6E54: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A717C;
    }
    // 0x800A6E54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6E58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6E5C: addu        $at, $at, $t6
    gpr jr_addend_800A6E68 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A6E60: lw          $t6, -0x7898($at)
    ctx->r14 = ADD32(ctx->r1, -0X7898);
    // 0x800A6E64: nop

    // 0x800A6E68: jr          $t6
    // 0x800A6E6C: nop

    switch (jr_addend_800A6E68 >> 2) {
        case 0: goto L_800A6E70; break;
        case 1: goto L_800A6F3C; break;
        case 2: goto L_800A7014; break;
        case 3: goto L_800A70D4; break;
        case 4: goto L_800A7158; break;
        default: switch_error(__func__, 0x800A6E68, 0x800E8768);
    }
    // 0x800A6E6C: nop

L_800A6E70:
    // 0x800A6E70: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A6E74: addiu       $v1, $v1, 0x2770
    ctx->r3 = ADD32(ctx->r3, 0X2770);
    // 0x800A6E78: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x800A6E7C: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800A6E80: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A6E84: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x800A6E88: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800A6E8C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6E94: jal         0x80001D04
    // 0x800A6E98: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A6E98: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    after_0:
    // 0x800A6E9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6EA0: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x800A6EA4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A6EA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A6EAC: beq         $v1, $zero, L_800A6EBC
    if (ctx->r3 == 0) {
        // 0x800A6EB0: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A6EBC;
    }
    // 0x800A6EB0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A6EB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A6EB8: bne         $v1, $at, L_800A6EDC
    if (ctx->r3 != ctx->r1) {
        // 0x800A6EBC: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_800A6EDC;
    }
L_800A6EBC:
    // 0x800A6EBC: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A6EC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6EC4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A6EC8: nop

    // 0x800A6ECC: swc1        $f4, 0x1CC($t9)
    MEM_W(0X1CC, ctx->r25) = ctx->f4.u32l;
    // 0x800A6ED0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A6ED4: b           L_800A6F2C
    // 0x800A6ED8: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
        goto L_800A6F2C;
    // 0x800A6ED8: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
L_800A6EDC:
    // 0x800A6EDC: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A6EE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A6EE4: beq         $v0, $zero, L_800A6EF4
    if (ctx->r2 == 0) {
        // 0x800A6EE8: addiu       $t2, $zero, -0x50
        ctx->r10 = ADD32(0, -0X50);
            goto L_800A6EF4;
    }
    // 0x800A6EE8: addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // 0x800A6EEC: bne         $v0, $at, L_800A6F10
    if (ctx->r2 != ctx->r1) {
        // 0x800A6EF0: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_800A6F10;
    }
    // 0x800A6EF0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
L_800A6EF4:
    // 0x800A6EF4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A6EF8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A6EFC: sb          $t2, 0x1DD($t3)
    MEM_B(0X1DD, ctx->r11) = ctx->r10;
    // 0x800A6F00: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A6F04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6F08: b           L_800A6F2C
    // 0x800A6F0C: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
        goto L_800A6F2C;
    // 0x800A6F0C: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
L_800A6F10:
    // 0x800A6F10: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A6F14: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6F18: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
    // 0x800A6F1C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A6F20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A6F24: nop

    // 0x800A6F28: swc1        $f8, 0x1CC($t7)
    MEM_W(0X1CC, ctx->r15) = ctx->f8.u32l;
L_800A6F2C:
    // 0x800A6F2C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A6F30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A6F34: b           L_800A717C
    // 0x800A6F38: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
        goto L_800A717C;
    // 0x800A6F38: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
L_800A6F3C:
    // 0x800A6F3C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A6F40: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A6F44: lb          $a0, 0x1DD($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A6F48: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A6F4C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A6F50: subu        $t1, $a0, $v1
    ctx->r9 = SUB32(ctx->r4, ctx->r3);
    // 0x800A6F54: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A6F58: lwc1        $f0, 0x1CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A6F5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6F60: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A6F64: nop

    // 0x800A6F68: bc1f        L_800A6F88
    if (!c1cs) {
        // 0x800A6F6C: nop
    
            goto L_800A6F88;
    }
    // 0x800A6F6C: nop

    // 0x800A6F70: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A6F74: nop

    // 0x800A6F78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A6F7C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800A6F80: b           L_800A6FE8
    // 0x800A6F84: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
        goto L_800A6FE8;
    // 0x800A6F84: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
L_800A6F88:
    // 0x800A6F88: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800A6F8C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A6F90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6F94: addiu       $t4, $zero, -0x78
    ctx->r12 = ADD32(0, -0X78);
    // 0x800A6F98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A6F9C: swc1        $f10, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A6FA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A6FA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A6FA8: sb          $t2, 0x1DA($t3)
    MEM_B(0X1DA, ctx->r11) = ctx->r10;
    // 0x800A6FAC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A6FB0: nop

    // 0x800A6FB4: sb          $t4, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r12;
    // 0x800A6FB8: lw          $t6, 0x6D40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D40);
    // 0x800A6FBC: nop

    // 0x800A6FC0: bne         $t6, $zero, L_800A6FE8
    if (ctx->r14 != 0) {
        // 0x800A6FC4: nop
    
            goto L_800A6FE8;
    }
    // 0x800A6FC4: nop

    // 0x800A6FC8: lbu         $t7, 0x6D71($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6D71);
    // 0x800A6FCC: nop

    // 0x800A6FD0: bne         $t7, $zero, L_800A6FE8
    if (ctx->r15 != 0) {
        // 0x800A6FD4: nop
    
            goto L_800A6FE8;
    }
    // 0x800A6FD4: nop

    // 0x800A6FD8: jal         0x800A6DB4
    // 0x800A6FDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    hud_time_trial_message(rdram, ctx);
        goto after_1;
    // 0x800A6FDC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800A6FE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A6FE4: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
L_800A6FE8:
    // 0x800A6FE8: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A6FEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6FF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A6FF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A6FF8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A6FFC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7000: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7004: jal         0x800AA600
    // 0x800A7008: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A7008: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    after_2:
    // 0x800A700C: b           L_800A7180
    // 0x800A7010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7180;
    // 0x800A7010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7014:
    // 0x800A7014: lb          $t8, 0x1DB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A7018: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800A701C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800A7020: sb          $t9, 0x1DB($v0)
    MEM_B(0X1DB, ctx->r2) = ctx->r25;
    // 0x800A7024: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7028: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A702C: lb          $t1, 0x1DB($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A7030: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A7034: slti        $at, $t1, 0x78
    ctx->r1 = SIGNED(ctx->r9) < 0X78 ? 1 : 0;
    // 0x800A7038: bne         $at, $zero, L_800A70AC
    if (ctx->r1 != 0) {
        // 0x800A703C: nop
    
            goto L_800A70AC;
    }
    // 0x800A703C: nop

    // 0x800A7040: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A7044: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x800A7048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A704C: beq         $v1, $zero, L_800A705C
    if (ctx->r3 == 0) {
        // 0x800A7050: addiu       $t3, $zero, 0x38
        ctx->r11 = ADD32(0, 0X38);
            goto L_800A705C;
    }
    // 0x800A7050: addiu       $t3, $zero, 0x38
    ctx->r11 = ADD32(0, 0X38);
    // 0x800A7054: bne         $v1, $at, L_800A7068
    if (ctx->r3 != ctx->r1) {
        // 0x800A7058: nop
    
            goto L_800A7068;
    }
    // 0x800A7058: nop

L_800A705C:
    // 0x800A705C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7060: b           L_800A7098
    // 0x800A7064: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
        goto L_800A7098;
    // 0x800A7064: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
L_800A7068:
    // 0x800A7068: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A706C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7070: beq         $v0, $zero, L_800A7080
    if (ctx->r2 == 0) {
        // 0x800A7074: addiu       $t5, $zero, 0x38
        ctx->r13 = ADD32(0, 0X38);
            goto L_800A7080;
    }
    // 0x800A7074: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
    // 0x800A7078: bne         $v0, $at, L_800A708C
    if (ctx->r2 != ctx->r1) {
        // 0x800A707C: nop
    
            goto L_800A708C;
    }
    // 0x800A707C: nop

L_800A7080:
    // 0x800A7080: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A7084: b           L_800A7098
    // 0x800A7088: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
        goto L_800A7098;
    // 0x800A7088: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
L_800A708C:
    // 0x800A708C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A7090: addiu       $t7, $zero, -0x28
    ctx->r15 = ADD32(0, -0X28);
    // 0x800A7094: sb          $t7, 0x1DD($t8)
    MEM_B(0X1DD, ctx->r24) = ctx->r15;
L_800A7098:
    // 0x800A7098: jal         0x80001D04
    // 0x800A709C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A709C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800A70A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A70A4: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A70A8: nop

L_800A70AC:
    // 0x800A70AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A70B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A70B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A70B8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A70BC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A70C0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A70C4: jal         0x800AA600
    // 0x800A70C8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A70C8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_4:
    // 0x800A70CC: b           L_800A7180
    // 0x800A70D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7180;
    // 0x800A70D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A70D4:
    // 0x800A70D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800A70D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800A70DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A70E0: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800A70E4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800A70E8: lwc1        $f16, 0x1CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A70EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A70F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A70F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A70F8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A70FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7100: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A7104: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7108: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A710C: lb          $t1, 0x1DD($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A7110: lwc1        $f8, 0x1CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A7114: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A7118: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A711C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7120: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7124: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7128: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800A712C: nop

    // 0x800A7130: bc1f        L_800A7148
    if (!c1cs) {
        // 0x800A7134: nop
    
            goto L_800A7148;
    }
    // 0x800A7134: nop

    // 0x800A7138: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A713C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7140: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A7144: nop

L_800A7148:
    // 0x800A7148: jal         0x800AA600
    // 0x800A714C: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A714C: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_5:
    // 0x800A7150: b           L_800A7180
    // 0x800A7154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7180;
    // 0x800A7154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7158:
    // 0x800A7158: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A715C: addiu       $v1, $v1, 0x2770
    ctx->r3 = ADD32(ctx->r3, 0X2770);
    // 0x800A7160: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A7164: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x800A7168: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800A716C: sb          $t4, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r12;
    // 0x800A7170: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A7174: nop

    // 0x800A7178: sb          $zero, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = 0;
L_800A717C:
    // 0x800A717C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7180:
    // 0x800A7180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7184: jr          $ra
    // 0x800A7188: nop

    return;
    // 0x800A7188: nop

;}
RECOMP_FUNC void debug_text_newline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B6F08: lw          $t6, 0x7CBC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CBC);
    // 0x800B6F0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B6F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6F14: addiu       $v0, $v0, 0x7CAE
    ctx->r2 = ADD32(ctx->r2, 0X7CAE);
    // 0x800B6F18: sh          $t6, 0x7CAC($at)
    MEM_H(0X7CAC, ctx->r1) = ctx->r14;
    // 0x800B6F1C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800B6F20: nop

    // 0x800B6F24: addiu       $t8, $t7, 0xB
    ctx->r24 = ADD32(ctx->r15, 0XB);
    // 0x800B6F28: jr          $ra
    // 0x800B6F2C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B6F2C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_800BDC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDC80: addiu       $sp, $sp, -0x370
    ctx->r29 = ADD32(ctx->r29, -0X370);
    // 0x800BDC84: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BDC88: lw          $t6, 0x317C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X317C);
    // 0x800BDC8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BDC90: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDC94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BDC98: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800BDC9C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BDCA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BDCA4: lwc1        $f4, -0x5F48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BDCA8: addiu       $a3, $a3, -0x6038
    ctx->r7 = ADD32(ctx->r7, -0X6038);
    // 0x800BDCAC: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BDCB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BDCB4: lwc1        $f6, -0x5F44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F44);
    // 0x800BDCB8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BDCBC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BDCC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BDCC4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800BDCC8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BDCCC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BDCD0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BDCD4: mflo        $t0
    ctx->r8 = lo;
    // 0x800BDCD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BDCDC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800BDCE0: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800BDCE4: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800BDCE8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BDCEC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BDCF0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BDCF4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BDCF8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BDCFC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BDD00: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BDD04: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800BDD08: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BDD0C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BDD10: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BDD14: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BDD18: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BDD1C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BDD20: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BDD24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BDD28: sw          $a1, 0x374($sp)
    MEM_W(0X374, ctx->r29) = ctx->r5;
    // 0x800BDD2C: sw          $a2, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r6;
    // 0x800BDD30: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BDD34: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800BDD38: beq         $t7, $zero, L_800BDD84
    if (ctx->r15 == 0) {
        // 0x800BDD3C: div.s       $f24, $f10, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
            goto L_800BDD84;
    }
    // 0x800BDD3C: div.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BDD40: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800BDD44: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BDD48: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x800BDD4C: cvt.d.s     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f28.d = CVT_D_S(ctx->f4.fl);
    // 0x800BDD50: mul.d       $f28, $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f30.d); 
    ctx->f28.d = MUL_D(ctx->f28.d, ctx->f30.d);
    // 0x800BDD54: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800BDD58: cvt.d.s     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f26.d = CVT_D_S(ctx->f6.fl);
    // 0x800BDD5C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BDD60: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BDD64: mul.d       $f30, $f26, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f30.d); 
    ctx->f30.d = MUL_D(ctx->f26.d, ctx->f30.d);
    // 0x800BDD68: cvt.s.d     $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.d); 
    ctx->f4.fl = CVT_S_D(ctx->f28.d);
    // 0x800BDD6C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BDD70: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BDD74: sw          $t9, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r25;
    // 0x800BDD78: cvt.s.d     $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.d); 
    ctx->f4.fl = CVT_S_D(ctx->f30.d);
    // 0x800BDD7C: b           L_800BDD90
    // 0x800BDD80: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
        goto L_800BDD90;
    // 0x800BDD80: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
L_800BDD84:
    // 0x800BDD84: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800BDD88: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800BDD8C: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
L_800BDD90:
    // 0x800BDD90: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800BDD94: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x800BDD98: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BDD9C: lw          $t4, 0x30D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30D8);
    // 0x800BDDA0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BDDA4: sw          $t3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r11;
    // 0x800BDDA8: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    // 0x800BDDAC: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800BDDB0: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BDDB4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BDDB8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800BDDBC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BDDC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BDDC4: lwc1        $f14, 0x380($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X380);
    // 0x800BDDC8: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BDDCC: lwc1        $f16, 0x384($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X384);
    // 0x800BDDD0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BDDD4: lwc1        $f18, 0x388($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X388);
    // 0x800BDDD8: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BDDDC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800BDDE0: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800BDDE4: sub.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BDDE8: bc1f        L_800BDDF8
    if (!c1cs) {
        // 0x800BDDEC: sub.s       $f18, $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
            goto L_800BDDF8;
    }
    // 0x800BDDEC: sub.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800BDDF0: b           L_800BDE2C
    // 0x800BDDF4: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
        goto L_800BDE2C;
    // 0x800BDDF4: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
L_800BDDF8:
    // 0x800BDDF8: nop

    // 0x800BDDFC: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BDE00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BDE04: nop

    // 0x800BDE08: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BDE0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BDE10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BDE14: nop

    // 0x800BDE18: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BDE1C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800BDE20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BDE24: sw          $t8, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r24;
    // 0x800BDE28: nop

L_800BDE2C:
    // 0x800BDE2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BDE30: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BDE34: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800BDE38: nop

    // 0x800BDE3C: bc1f        L_800BDE50
    if (!c1cs) {
        // 0x800BDE40: nop
    
            goto L_800BDE50;
    }
    // 0x800BDE40: nop

    // 0x800BDE44: b           L_800BDE80
    // 0x800BDE48: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
        goto L_800BDE80;
    // 0x800BDE48: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
    // 0x800BDE4C: nop

L_800BDE50:
    // 0x800BDE50: div.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800BDE54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BDE58: nop

    // 0x800BDE5C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BDE60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BDE64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BDE68: nop

    // 0x800BDE6C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BDE70: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800BDE74: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BDE78: sw          $t2, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r10;
    // 0x800BDE7C: nop

L_800BDE80:
    // 0x800BDE80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BDE84: lwc1        $f8, -0x5F60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5F60);
    // 0x800BDE88: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BDE8C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x800BDE90: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BDE94: bc1f        L_800BDEA8
    if (!c1cs) {
        // 0x800BDE98: nop
    
            goto L_800BDEA8;
    }
    // 0x800BDE98: nop

    // 0x800BDE9C: b           L_800BDED8
    // 0x800BDEA0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
        goto L_800BDED8;
    // 0x800BDEA0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
    // 0x800BDEA4: nop

L_800BDEA8:
    // 0x800BDEA8: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800BDEAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BDEB0: nop

    // 0x800BDEB4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BDEB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BDEBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BDEC0: nop

    // 0x800BDEC4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BDEC8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BDECC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BDED0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BDED4: sw          $t6, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r14;
L_800BDED8:
    // 0x800BDED8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BDEDC: lwc1        $f8, -0x5F5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x800BDEE0: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BDEE4: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x800BDEE8: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BDEEC: bc1f        L_800BDF00
    if (!c1cs) {
        // 0x800BDEF0: nop
    
            goto L_800BDF00;
    }
    // 0x800BDEF0: nop

    // 0x800BDEF4: b           L_800BDF30
    // 0x800BDEF8: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
        goto L_800BDF30;
    // 0x800BDEF8: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
    // 0x800BDEFC: nop

L_800BDF00:
    // 0x800BDF00: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BDF04: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BDF08: nop

    // 0x800BDF0C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BDF10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BDF14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BDF18: nop

    // 0x800BDF1C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BDF20: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BDF24: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BDF28: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BDF2C: sw          $t2, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r10;
L_800BDF30:
    // 0x800BDF30: lh          $t3, 0x12($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X12);
    // 0x800BDF34: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BDF38: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BDF3C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800BDF40: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDF44: bne         $at, $zero, L_800BDF5C
    if (ctx->r1 != 0) {
        // 0x800BDF48: nop
    
            goto L_800BDF5C;
    }
    // 0x800BDF48: nop

L_800BDF4C:
    // 0x800BDF4C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800BDF50: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDF54: beq         $at, $zero, L_800BDF4C
    if (ctx->r1 == 0) {
        // 0x800BDF58: nop
    
            goto L_800BDF4C;
    }
    // 0x800BDF58: nop

L_800BDF5C:
    // 0x800BDF5C: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800BDF60: lw          $t6, 0x364($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X364);
    // 0x800BDF64: lw          $t7, 0x364($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X364);
    // 0x800BDF68: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800BDF6C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDF70: bne         $at, $zero, L_800BDF8C
    if (ctx->r1 != 0) {
        // 0x800BDF74: lw          $t8, 0x354($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X354);
            goto L_800BDF8C;
    }
    // 0x800BDF74: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BDF78:
    // 0x800BDF78: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800BDF7C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDF80: beq         $at, $zero, L_800BDF78
    if (ctx->r1 == 0) {
        // 0x800BDF84: nop
    
            goto L_800BDF78;
    }
    // 0x800BDF84: nop

    // 0x800BDF88: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BDF8C:
    // 0x800BDF8C: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x800BDF90: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BDF94: bne         $at, $zero, L_800BE170
    if (ctx->r1 != 0) {
        // 0x800BDF98: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800BE170;
    }
    // 0x800BDF98: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800BDF9C: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BDFA0: lw          $t9, 0x368($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X368);
    // 0x800BDFA4: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDFA8: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x800BDFAC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800BDFB0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800BDFB4: addiu       $fp, $fp, 0x3040
    ctx->r30 = ADD32(ctx->r30, 0X3040);
    // 0x800BDFB8: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800BDFBC: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BDFC0: sw          $v1, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r3;
    // 0x800BDFC4: sw          $s0, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r16;
    // 0x800BDFC8: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800BDFCC: mflo        $t4
    ctx->r12 = lo;
    // 0x800BDFD0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BDFD4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800BDFD8:
    // 0x800BDFD8: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BDFDC: lw          $t3, 0x358($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X358);
    // 0x800BDFE0: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDFE4: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDFE8: sll         $t2, $s7, 1
    ctx->r10 = S32(ctx->r23 << 1);
    // 0x800BDFEC: addiu       $t4, $sp, 0xD8
    ctx->r12 = ADD32(ctx->r29, 0XD8);
    // 0x800BDFF0: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BDFF4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800BDFF8: addu        $s3, $t2, $t4
    ctx->r19 = ADD32(ctx->r10, ctx->r12);
    // 0x800BDFFC: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800BE000: addiu       $s5, $t3, 0x1
    ctx->r21 = ADD32(ctx->r11, 0X1);
    // 0x800BE004: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800BE008: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE00C: addu        $s2, $t7, $v1
    ctx->r18 = ADD32(ctx->r15, ctx->r3);
    // 0x800BE010: bne         $at, $zero, L_800BE138
    if (ctx->r1 != 0) {
        // 0x800BE014: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800BE138;
    }
L_800BE014:
    // 0x800BE014: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE018: lw          $t5, 0x3044($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3044);
    // 0x800BE01C: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800BE020: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x800BE024: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BE028: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800BE02C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800BE030: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800BE034: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800BE038: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800BE03C: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800BE040: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BE044: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800BE048: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800BE04C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BE050: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE054: lw          $t5, 0x3188($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3188);
    // 0x800BE058: mul.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BE05C: blez        $t5, L_800BE090
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BE060: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800BE090;
    }
    // 0x800BE060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BE064: lw          $a0, 0x370($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X370);
    // 0x800BE068: jal         0x800BEFC4
    // 0x800BE06C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BE06C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x800BE070: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BE074: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BE078: lw          $t8, 0x30D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30D8);
    // 0x800BE07C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE080: addiu       $a3, $a3, -0x6038
    ctx->r7 = ADD32(ctx->r7, -0X6038);
    // 0x800BE084: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BE088: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800BE08C: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
L_800BE090:
    // 0x800BE090: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BE094: lw          $t9, 0x3178($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3178);
    // 0x800BE098: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BE09C: addu        $t7, $t9, $s4
    ctx->r15 = ADD32(ctx->r25, ctx->r20);
    // 0x800BE0A0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BE0A4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE0A8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BE0AC: beq         $at, $zero, L_800BE0D0
    if (ctx->r1 == 0) {
        // 0x800BE0B0: nop
    
            goto L_800BE0D0;
    }
    // 0x800BE0B0: nop

    // 0x800BE0B4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BE0B8: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BE0BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE0C0: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BE0C4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BE0C8: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BE0CC: nop

L_800BE0D0:
    // 0x800BE0D0: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BE0D4: lh          $t2, 0x6($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X6);
    // 0x800BE0D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BE0DC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800BE0E0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BE0E4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BE0E8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BE0EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE0F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE0F4: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE0F8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE0FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BE100: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BE104: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BE108: addu        $t6, $t2, $t8
    ctx->r14 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE10C: bne         $at, $zero, L_800BE11C
    if (ctx->r1 != 0) {
        // 0x800BE110: sh          $t6, -0x2($s3)
        MEM_H(-0X2, ctx->r19) = ctx->r14;
            goto L_800BE11C;
    }
    // 0x800BE110: sh          $t6, -0x2($s3)
    MEM_H(-0X2, ctx->r19) = ctx->r14;
    // 0x800BE114: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x800BE118: subu        $s2, $s2, $a0
    ctx->r18 = SUB32(ctx->r18, ctx->r4);
L_800BE11C:
    // 0x800BE11C: bne         $s5, $s1, L_800BE014
    if (ctx->r21 != ctx->r17) {
        // 0x800BE120: nop
    
            goto L_800BE014;
    }
    // 0x800BE120: nop

    // 0x800BE124: lw          $t0, 0x368($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X368);
    // 0x800BE128: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE12C: lw          $v1, 0x350($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X350);
    // 0x800BE130: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BE134: nop

L_800BE138:
    // 0x800BE138: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE13C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE140: bne         $at, $zero, L_800BE14C
    if (ctx->r1 != 0) {
        // 0x800BE144: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800BE14C;
    }
    // 0x800BE144: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800BE148: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_800BE14C:
    // 0x800BE14C: lw          $t9, 0x36C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE150: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BE154: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800BE158: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800BE15C: bne         $t7, $s6, L_800BDFD8
    if (ctx->r15 != ctx->r22) {
        // 0x800BE160: sw          $v0, 0x34C($sp)
        MEM_W(0X34C, ctx->r29) = ctx->r2;
            goto L_800BDFD8;
    }
    // 0x800BE160: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BE164: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BE168: lw          $s6, 0x364($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X364);
    // 0x800BE16C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800BE170:
    // 0x800BE170: lw          $t8, 0x364($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X364);
    // 0x800BE174: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE178: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BE17C: lw          $t4, 0x358($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X358);
    // 0x800BE180: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE184: lw          $t3, 0x368($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X368);
    // 0x800BE188: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BE18C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800BE190: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800BE194: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
    // 0x800BE198: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE19C: nop

    // 0x800BE1A0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE1A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE1A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE1AC: nop

    // 0x800BE1B0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BE1B4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BE1B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE1BC: lw          $t6, 0x354($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X354);
    // 0x800BE1C0: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x800BE1C4: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800BE1C8: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BE1CC: beq         $at, $zero, L_800BE5F0
    if (ctx->r1 == 0) {
        // 0x800BE1D0: sra         $a1, $t5, 16
        ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
            goto L_800BE5F0;
    }
    // 0x800BE1D0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE1D4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BE1D8: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE1DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE1E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BE1E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE1E8: nop

    // 0x800BE1EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE1F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE1F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE1F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE1FC: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800BE200: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800BE204: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800BE208: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE20C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800BE210: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800BE214: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
L_800BE218:
    // 0x800BE218: addiu       $v0, $s6, 0x1
    ctx->r2 = ADD32(ctx->r22, 0X1);
    // 0x800BE21C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BE220: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE224: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE228: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE22C: lw          $t2, 0x30D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30D8);
    // 0x800BE230: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BE234: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE238: nop

    // 0x800BE23C: addu        $a2, $t2, $t8
    ctx->r6 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE240: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE244: lh          $t4, 0x8($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X8);
    // 0x800BE248: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE24C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE250: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE254: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BE258: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BE25C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BE260: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE264: addu        $fp, $t4, $t7
    ctx->r30 = ADD32(ctx->r12, ctx->r15);
    // 0x800BE268: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800BE26C: lw          $t7, 0x358($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X358);
    // 0x800BE270: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BE274: addu        $s3, $t8, $t6
    ctx->r19 = ADD32(ctx->r24, ctx->r14);
    // 0x800BE278: sll         $t5, $fp, 16
    ctx->r13 = S32(ctx->r30 << 16);
    // 0x800BE27C: sll         $t3, $s3, 16
    ctx->r11 = S32(ctx->r19 << 16);
    // 0x800BE280: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE284: sra         $fp, $t5, 16
    ctx->r30 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE288: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800BE28C: beq         $at, $zero, L_800BE5D8
    if (ctx->r1 == 0) {
        // 0x800BE290: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800BE5D8;
    }
    // 0x800BE290: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800BE294: lw          $t9, 0x364($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X364);
    // 0x800BE298: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE29C: subu        $a2, $s6, $t9
    ctx->r6 = SUB32(ctx->r22, ctx->r25);
    // 0x800BE2A0: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE2A4: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x800BE2A8: lw          $t5, 0x374($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X374);
    // 0x800BE2AC: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x800BE2B0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800BE2B4: addu        $s0, $t5, $t2
    ctx->r16 = ADD32(ctx->r13, ctx->r10);
    // 0x800BE2B8: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x800BE2BC: subu        $t8, $t4, $t4
    ctx->r24 = SUB32(ctx->r12, ctx->r12);
    // 0x800BE2C0: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800BE2C4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BE2C8: addiu       $t3, $sp, 0xD8
    ctx->r11 = ADD32(ctx->r29, 0XD8);
    // 0x800BE2CC: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE2D0: mflo        $a3
    ctx->r7 = lo;
    // 0x800BE2D4: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE2D8: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x800BE2DC: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE2E0: mul.s       $f26, $f0, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BE2E4: negu        $at, $t4
    ctx->r1 = SUB32(0, ctx->r12);
    // 0x800BE2E8: sll         $t3, $at, 1
    ctx->r11 = S32(ctx->r1 << 1);
    // 0x800BE2EC: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800BE2F0: addu        $s4, $v0, $t5
    ctx->r20 = ADD32(ctx->r2, ctx->r13);
    // 0x800BE2F4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800BE2F8: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE2FC: addiu       $t5, $sp, 0xD8
    ctx->r13 = ADD32(ctx->r29, 0XD8);
    // 0x800BE300: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x800BE304: mul.s       $f28, $f26, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800BE308: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x800BE30C: mflo        $t0
    ctx->r8 = lo;
    // 0x800BE310: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800BE314: addu        $s5, $v0, $t8
    ctx->r21 = ADD32(ctx->r2, ctx->r24);
    // 0x800BE318: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
L_800BE31C:
    // 0x800BE31C: addiu       $s6, $s1, 0x1
    ctx->r22 = ADD32(ctx->r17, 0X1);
    // 0x800BE320: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x800BE324: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE328: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE32C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE330: lw          $t2, 0x30D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30D8);
    // 0x800BE334: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BE338: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE33C: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE340: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800BE344: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE348: lh          $t4, 0x4($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X4);
    // 0x800BE34C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE350: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE354: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE358: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x800BE35C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE360: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE364: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BE368: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE36C: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x800BE370: sll         $t2, $s2, 16
    ctx->r10 = S32(ctx->r18 << 16);
    // 0x800BE374: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800BE378: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE37C: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x800BE380: nop

    // 0x800BE384: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800BE388: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x800BE38C: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x800BE390: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800BE394: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800BE398: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800BE39C: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    // 0x800BE3A0: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800BE3A4: subu        $t2, $v0, $t5
    ctx->r10 = SUB32(ctx->r2, ctx->r13);
    // 0x800BE3A8: subu        $t4, $v0, $t9
    ctx->r12 = SUB32(ctx->r2, ctx->r25);
    // 0x800BE3AC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BE3B0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BE3B4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE3B8: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE3BC: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE3C0: mul.s       $f20, $f4, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE3C4: sh          $a1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r5;
    // 0x800BE3C8: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BE3CC: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BE3D0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE3D4: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BE3D8: mul.s       $f22, $f10, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BE3DC: nop

    // 0x800BE3E0: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BE3E4: nop

    // 0x800BE3E8: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BE3EC: add.s       $f4, $f8, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BE3F0: jal         0x800C9AD0
    // 0x800BE3F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE3F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800BE3F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BE3FC: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BE400: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BE404: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BE408: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BE40C: bc1f        L_800BE488
    if (!c1cs) {
        // 0x800BE410: nop
    
            goto L_800BE488;
    }
    // 0x800BE410: nop

    // 0x800BE414: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BE418: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x800BE41C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x800BE420: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800BE424: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE428: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BE42C: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BE430: nop

    // 0x800BE434: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BE438: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BE43C: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BE440: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BE444: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BE448: lh          $t6, -0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X14);
    // 0x800BE44C: lh          $t3, -0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X12);
    // 0x800BE450: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800BE454: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800BE458: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE45C: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
    // 0x800BE460: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE464: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE468: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BE46C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BE470: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BE474: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE478: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BE47C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BE480: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800BE484: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_800BE488:
    // 0x800BE488: sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // 0x800BE48C: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE490: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE494: lh          $t4, 0x2($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X2);
    // 0x800BE498: nop

    // 0x800BE49C: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x800BE4A0: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x800BE4A4: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800BE4A8: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
    // 0x800BE4AC: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x800BE4B0: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800BE4B4: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x800BE4B8: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x800BE4BC: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE4C0: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x800BE4C4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BE4C8: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE4CC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE4D0: sh          $fp, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r30;
    // 0x800BE4D4: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE4D8: subu        $t3, $t6, $v0
    ctx->r11 = SUB32(ctx->r14, ctx->r2);
    // 0x800BE4DC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BE4E0: mul.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BE4E4: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE4E8: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BE4EC: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BE4F0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE4F4: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BE4F8: mul.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BE4FC: nop

    // 0x800BE500: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BE504: nop

    // 0x800BE508: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BE50C: add.s       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BE510: jal         0x800C9AD0
    // 0x800BE514: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800BE514: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_2:
    // 0x800BE518: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BE51C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BE520: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BE524: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BE528: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BE52C: bc1f        L_800BE5AC
    if (!c1cs) {
        // 0x800BE530: sll         $s3, $s2, 16
        ctx->r19 = S32(ctx->r18 << 16);
            goto L_800BE5AC;
    }
    // 0x800BE530: sll         $s3, $s2, 16
    ctx->r19 = S32(ctx->r18 << 16);
    // 0x800BE534: nop

    // 0x800BE538: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BE53C: lw          $t9, 0x378($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X378);
    // 0x800BE540: sll         $t4, $s7, 4
    ctx->r12 = S32(ctx->r23 << 4);
    // 0x800BE544: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800BE548: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE54C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BE550: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BE554: nop

    // 0x800BE558: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BE55C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BE560: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BE564: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BE568: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BE56C: lh          $t5, -0x14($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X14);
    // 0x800BE570: lh          $t2, -0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X12);
    // 0x800BE574: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800BE578: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BE57C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE580: lh          $t7, -0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X10);
    // 0x800BE584: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BE588: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE58C: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BE590: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BE594: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BE598: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE59C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BE5A0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BE5A4: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800BE5A8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_800BE5AC:
    // 0x800BE5AC: lw          $t6, 0x358($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X358);
    // 0x800BE5B0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800BE5B4: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x800BE5B8: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x800BE5BC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x800BE5C0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800BE5C4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800BE5C8: bne         $s6, $t6, L_800BE31C
    if (ctx->r22 != ctx->r14) {
        // 0x800BE5CC: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800BE31C;
    }
    // 0x800BE5CC: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800BE5D0: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE5D4: nop

L_800BE5D8:
    // 0x800BE5D8: lw          $t9, 0x354($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X354);
    // 0x800BE5DC: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x800BE5E0: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800BE5E4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800BE5E8: bne         $v0, $t9, L_800BE218
    if (ctx->r2 != ctx->r25) {
        // 0x800BE5EC: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_800BE218;
    }
    // 0x800BE5EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800BE5F0:
    // 0x800BE5F0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800BE5F4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800BE5F8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800BE5FC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BE600: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BE604: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BE608: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BE60C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BE610: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BE614: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BE618: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BE61C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BE620: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BE624: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800BE628: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BE62C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BE630: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BE634: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BE638: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BE63C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BE640: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE644: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BE648: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800BE64C: jr          $ra
    // 0x800BE650: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
    return;
    // 0x800BE650: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D7474: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D7478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D747C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D7480: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D7484: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D7488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D748C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D7490: jal         0x800CEB6C
    // 0x800D7494: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7494: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D7498: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D749C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800D74A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D74A4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D74A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D74AC: jal         0x800CEBC8
    // 0x800D74B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800D74B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800D74B4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800D74B8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D74BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800D74C0: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800D74C4: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800D74C8: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800D74CC: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800D74D0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D74D4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D74D8: bgtz        $t0, L_800D7538
    if (SIGNED(ctx->r8) > 0) {
        // 0x800D74DC: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800D7538;
    }
    // 0x800D74DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D74E0: bltz        $t0, L_800D74F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x800D74E4: nop
    
            goto L_800D74F0;
    }
    // 0x800D74E4: nop

    // 0x800D74E8: b           L_800D753C
    // 0x800D74EC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800D753C;
    // 0x800D74EC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D74F0:
    // 0x800D74F0: bltzl       $t8, L_800D753C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D74F4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D753C;
    }
    goto skip_0;
    // 0x800D74F4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800D74F8: bgtz        $t8, L_800D7508
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D74FC: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_800D7508;
    }
    // 0x800D74FC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800D7500: beql        $t9, $zero, L_800D753C
    if (ctx->r25 == 0) {
        // 0x800D7504: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D753C;
    }
    goto skip_1;
    // 0x800D7504: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_800D7508:
    // 0x800D7508: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D750C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D7510: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800D7514: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800D7518: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x800D751C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800D7520: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800D7524: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x800D7528: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D752C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D7530: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D7534: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800D7538:
    // 0x800D7538: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D753C:
    // 0x800D753C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D7540: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800D7544: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800D7548: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800D754C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D7550: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800D7554: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800D7558: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800D755C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D7560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7564: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D7568: jr          $ra
    // 0x800D756C: nop

    return;
    // 0x800D756C: nop

;}
RECOMP_FUNC void racer_special_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C2F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C2F8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C2FC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8005C300: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8005C304: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C308: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8005C30C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8005C310: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C314: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C318: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8005C31C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C324: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8005C328: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x8005C32C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005C330: nop

    // 0x8005C334: swc1        $f6, -0x2A40($at)
    MEM_W(-0X2A40, ctx->r1) = ctx->f6.u32l;
    // 0x8005C338: lw          $t2, 0x118($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X118);
    // 0x8005C33C: nop

    // 0x8005C340: beq         $t2, $zero, L_8005C354
    if (ctx->r10 == 0) {
        // 0x8005C344: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005C354;
    }
    // 0x8005C344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C348: jal         0x80006AC8
    // 0x8005C34C: nop

    racer_sound_free(rdram, ctx);
        goto after_0;
    // 0x8005C34C: nop

    after_0:
    // 0x8005C350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005C354:
    // 0x8005C354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C358: sb          $zero, -0x2A3C($at)
    MEM_B(-0X2A3C, ctx->r1) = 0;
    // 0x8005C35C: jr          $ra
    // 0x8005C360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005C360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800753D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800753D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800753DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800753E0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800753E4: jal         0x800758DC
    // 0x800753E8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800753E8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x800753EC: beq         $v0, $zero, L_8007540C
    if (ctx->r2 == 0) {
        // 0x800753F0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8007540C;
    }
    // 0x800753F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800753F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800753F8: jal         0x80075AEC
    // 0x800753FC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x800753FC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075400: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80075404: b           L_800756C8
    // 0x80075408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800756C8;
    // 0x80075408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007540C:
    // 0x8007540C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075410: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80075414: addiu       $a2, $a2, 0x77B4
    ctx->r6 = ADD32(ctx->r6, 0X77B4);
    // 0x80075418: addiu       $a1, $a1, 0x77A4
    ctx->r5 = ADD32(ctx->r5, 0X77A4);
    // 0x8007541C: jal         0x800764E8
    // 0x80075420: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80075420: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80075424: bne         $v0, $zero, L_800756AC
    if (ctx->r2 != 0) {
        // 0x80075428: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800756AC;
    }
    // 0x80075428: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007542C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075430: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80075434: jal         0x80076924
    // 0x80075438: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80075438: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8007543C: beq         $v0, $zero, L_8007545C
    if (ctx->r2 == 0) {
        // 0x80075440: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8007545C;
    }
    // 0x80075440: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075444: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075448: jal         0x80075AEC
    // 0x8007544C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x8007544C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x80075450: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80075454: b           L_800756C8
    // 0x80075458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800756C8;
    // 0x80075458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007545C:
    // 0x8007545C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80075460: jal         0x80070C9C
    // 0x80075464: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80075464: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_5:
    // 0x80075468: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007546C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80075470: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80075474: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80075478: jal         0x80076610
    // 0x8007547C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_6;
    // 0x8007547C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x80075480: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075484: jal         0x80075AEC
    // 0x80075488: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x80075488: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_7:
    // 0x8007548C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075490: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80075494: bne         $v1, $zero, L_80075694
    if (ctx->r3 != 0) {
        // 0x80075498: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_80075694;
    }
    // 0x80075498: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x8007549C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800754A0: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x800754A4: bne         $t7, $at, L_80075680
    if (ctx->r15 != ctx->r1) {
        // 0x800754A8: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80075680;
    }
    // 0x800754A8: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x800754AC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800754B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800754B4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800754B8: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x800754BC: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800754C0: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x800754C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800754C8: subu        $a3, $t9, $t2
    ctx->r7 = SUB32(ctx->r25, ctx->r10);
    // 0x800754CC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800754D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800754D4: jal         0x80070C9C
    // 0x800754D8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800754D8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x800754DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800754E0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800754E4: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x800754E8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800754EC: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x800754F0: lh          $a2, 0x2($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X2);
    // 0x800754F4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800754F8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800754FC: jal         0x800C9DA0
    // 0x80075500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bcopy(rdram, ctx);
        goto after_9;
    // 0x80075500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80075504: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075508: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007550C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80075510: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80075514: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80075518: beq         $t0, $at, L_80075558
    if (ctx->r8 == ctx->r1) {
        // 0x8007551C: slti        $at, $t0, 0x6
        ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
            goto L_80075558;
    }
    // 0x8007551C: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x80075520: lh          $v0, 0x6($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X6);
    // 0x80075524: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80075528: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8007552C: lh          $t7, 0x1A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1A);
    // 0x80075530: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80075534: addu        $a1, $t5, $a3
    ctx->r5 = ADD32(ctx->r13, ctx->r7);
    // 0x80075538: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8007553C: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x80075540: jal         0x800C9DA0
    // 0x80075544: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    _bcopy(rdram, ctx);
        goto after_10;
    // 0x80075544: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    after_10:
    // 0x80075548: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8007554C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075550: nop

    // 0x80075554: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
L_80075558:
    // 0x80075558: beq         $at, $zero, L_80075640
    if (ctx->r1 == 0) {
        // 0x8007555C: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80075640;
    }
    // 0x8007555C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80075560: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80075564: subu        $a2, $a1, $t0
    ctx->r6 = SUB32(ctx->r5, ctx->r8);
    // 0x80075568: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x8007556C: beq         $t8, $zero, L_800755B4
    if (ctx->r24 == 0) {
        // 0x80075570: addu        $a0, $t8, $t0
        ctx->r4 = ADD32(ctx->r24, ctx->r8);
            goto L_800755B4;
    }
    // 0x80075570: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x80075574: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80075578: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8007557C: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x80075580: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80075584:
    // 0x80075584: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x80075588: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x8007558C: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    // 0x80075590: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80075594: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x80075598: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8007559C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800755A0: sb          $t9, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r25;
    // 0x800755A4: bne         $a0, $v1, L_80075584
    if (ctx->r4 != ctx->r3) {
        // 0x800755A8: sb          $t2, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = ctx->r10;
            goto L_80075584;
    }
    // 0x800755A8: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
    // 0x800755AC: beq         $v1, $a1, L_80075644
    if (ctx->r3 == ctx->r5) {
        // 0x800755B0: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_80075644;
    }
    // 0x800755B0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_800755B4:
    // 0x800755B4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800755B8: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x800755BC: addu        $v0, $t1, $t5
    ctx->r2 = ADD32(ctx->r9, ctx->r13);
    // 0x800755C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800755C4:
    // 0x800755C4: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x800755C8: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800755CC: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800755D0: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x800755D4: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800755D8: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800755DC: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x800755E0: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x800755E4: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800755E8: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x800755EC: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
    // 0x800755F0: sb          $t3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r11;
    // 0x800755F4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800755F8: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x800755FC: lbu         $t8, 0xD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XD);
    // 0x80075600: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x80075604: lbu         $t3, 0x11($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X11);
    // 0x80075608: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x8007560C: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x80075610: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80075614: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80075618: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x8007561C: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80075620: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    // 0x80075624: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80075628: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007562C: sb          $t8, -0x7($v0)
    MEM_B(-0X7, ctx->r2) = ctx->r24;
    // 0x80075630: sb          $t7, -0x8($v0)
    MEM_B(-0X8, ctx->r2) = ctx->r15;
    // 0x80075634: sb          $t3, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r11;
    // 0x80075638: bne         $v1, $a1, L_800755C4
    if (ctx->r3 != ctx->r5) {
        // 0x8007563C: sb          $t2, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r10;
            goto L_800755C4;
    }
    // 0x8007563C: sb          $t2, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r10;
L_80075640:
    // 0x80075640: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_80075644:
    // 0x80075644: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80075648: addiu       $v0, $t1, 0x4
    ctx->r2 = ADD32(ctx->r9, 0X4);
    // 0x8007564C: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x80075650: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80075654: sh          $t7, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r15;
    // 0x80075658: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007565C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80075660: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075664: addiu       $a3, $a3, 0x77C8
    ctx->r7 = ADD32(ctx->r7, 0X77C8);
    // 0x80075668: addiu       $a2, $a2, 0x77B8
    ctx->r6 = ADD32(ctx->r6, 0X77B8);
    // 0x8007566C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80075670: jal         0x800766D4
    // 0x80075674: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_11;
    // 0x80075674: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_11:
    // 0x80075678: b           L_80075680
    // 0x8007567C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80075680;
    // 0x8007567C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80075680:
    // 0x80075680: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80075684: jal         0x80071140
    // 0x80075688: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x80075688: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_12:
    // 0x8007568C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075690: nop

L_80075694:
    // 0x80075694: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80075698: jal         0x80071140
    // 0x8007569C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x8007569C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_13:
    // 0x800756A0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800756A4: b           L_800756C4
    // 0x800756A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800756C4;
    // 0x800756A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800756AC:
    // 0x800756AC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756B0: jal         0x80075AEC
    // 0x800756B4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_14;
    // 0x800756B4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_14:
    // 0x800756B8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800756BC: nop

    // 0x800756C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800756C4:
    // 0x800756C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800756C8:
    // 0x800756C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800756CC: jr          $ra
    // 0x800756D0: nop

    return;
    // 0x800756D0: nop

;}
RECOMP_FUNC void allocate_object_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF90: lwc1        $f12, 0x514C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X514C);
    // 0x8000BF94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BF98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BFA0: lwc1        $f14, 0x5150($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5150);
    // 0x8000BFA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000BFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000BFAC: jal         0x8001D258
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    set_world_shading(rdram, ctx);
        goto after_0;
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    after_0:
    // 0x8000BFB4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000BFB8: ori         $a0, $a0, 0x5800
    ctx->r4 = ctx->r4 | 0X5800;
    // 0x8000BFBC: jal         0x80070B78
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    mempool_new_sub(rdram, ctx);
        goto after_1;
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x8000BFC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFC8: sw          $v0, -0x5198($at)
    MEM_W(-0X5198, ctx->r1) = ctx->r2;
    // 0x8000BFCC: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8000BFD0: jal         0x80070C9C
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8000BFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFDC: sw          $v0, -0x513C($at)
    MEM_W(-0X513C, ctx->r1) = ctx->r2;
    // 0x8000BFE0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000BFE4: jal         0x80070C9C
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000BFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFF0: sw          $v0, -0x5194($at)
    MEM_W(-0X5194, ctx->r1) = ctx->r2;
    // 0x8000BFF4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000BFF8: jal         0x80070C9C
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_4:
    // 0x8000C000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C004: sw          $v0, -0x518C($at)
    MEM_W(-0X518C, ctx->r1) = ctx->r2;
    // 0x8000C008: addiu       $a0, $zero, 0xE10
    ctx->r4 = ADD32(0, 0XE10);
    // 0x8000C00C: jal         0x80070C9C
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8000C014: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C018: sw          $v0, -0x5134($at)
    MEM_W(-0X5134, ctx->r1) = ctx->r2;
    // 0x8000C01C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000C020: jal         0x80070C9C
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_6:
    // 0x8000C028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C02C: sw          $v0, -0x5124($at)
    MEM_W(-0X5124, ctx->r1) = ctx->r2;
    // 0x8000C030: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C034: jal         0x80070C9C
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_7:
    // 0x8000C03C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C040: sw          $v0, -0x511C($at)
    MEM_W(-0X511C, ctx->r1) = ctx->r2;
    // 0x8000C044: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C048: jal         0x80070C9C
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_8:
    // 0x8000C050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C054: sw          $v0, -0x5114($at)
    MEM_W(-0X5114, ctx->r1) = ctx->r2;
    // 0x8000C058: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C05C: jal         0x80070C9C
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_9:
    // 0x8000C064: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C068: sw          $v0, -0x5118($at)
    MEM_W(-0X5118, ctx->r1) = ctx->r2;
    // 0x8000C06C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000C070: jal         0x80070C9C
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_10:
    // 0x8000C078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C07C: sw          $v0, -0x50FC($at)
    MEM_W(-0X50FC, ctx->r1) = ctx->r2;
    // 0x8000C080: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8000C084: jal         0x80070C9C
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_11:
    // 0x8000C08C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C090: sw          $v0, -0x5234($at)
    MEM_W(-0X5234, ctx->r1) = ctx->r2;
    // 0x8000C094: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8000C098: jal         0x80070C9C
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_12:
    // 0x8000C0A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0A4: sw          $v0, -0x500C($at)
    MEM_W(-0X500C, ctx->r1) = ctx->r2;
    // 0x8000C0A8: jal         0x80076C58
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_13:
    // 0x8000C0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0B4: sw          $v0, -0x5148($at)
    MEM_W(-0X5148, ctx->r1) = ctx->r2;
    // 0x8000C0B8: jal         0x80076F30
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_size(rdram, ctx);
        goto after_14;
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_14:
    // 0x8000C0C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C0C4: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8000C0C8: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x8000C0CC: addiu       $a0, $a0, -0x5144
    ctx->r4 = ADD32(ctx->r4, -0X5144);
    // 0x8000C0D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000C0D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C0D8: lw          $a1, -0x5148($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5148);
    // 0x8000C0DC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8000C0E0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C0E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8000C0E8: nop

    // 0x8000C0EC: bne         $t0, $zero, L_8000C110
    if (ctx->r8 != 0) {
        // 0x8000C0F0: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C110;
    }
    // 0x8000C0F0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C0F4:
    // 0x8000C0F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8000C0F8: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C0FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C100: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8000C104: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C108: beq         $t4, $zero, L_8000C0F4
    if (ctx->r12 == 0) {
        // 0x8000C10C: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C0F4;
    }
    // 0x8000C10C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C110:
    // 0x8000C110: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C114: jal         0x80070C9C
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_15:
    // 0x8000C11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C120: sw          $v0, -0x52A8($at)
    MEM_W(-0X52A8, ctx->r1) = ctx->r2;
    // 0x8000C124: jal         0x80076C58
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    asset_table_load(rdram, ctx);
        goto after_16;
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_16:
    // 0x8000C12C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C130: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C134: addiu       $a2, $a2, -0x5298
    ctx->r6 = ADD32(ctx->r6, -0X5298);
    // 0x8000C138: addiu       $a1, $a1, -0x529C
    ctx->r5 = ADD32(ctx->r5, -0X529C);
    // 0x8000C13C: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x8000C140: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C144: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C148: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000C14C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000C150: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C158: beq         $a3, $t7, L_8000C180
    if (ctx->r7 == ctx->r15) {
        // 0x8000C15C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C180;
    }
    // 0x8000C15C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C160: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C164:
    // 0x8000C164: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C168: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8000C16C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8000C170: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C174: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8000C178: bne         $a3, $t1, L_8000C164
    if (ctx->r7 != ctx->r9) {
        // 0x8000C17C: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8000C164;
    }
    // 0x8000C17C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C180:
    // 0x8000C180: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8000C184: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8000C188: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8000C18C: jal         0x80070C9C
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_17:
    // 0x8000C194: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C19C: sw          $v0, -0x51B8($at)
    MEM_W(-0X51B8, ctx->r1) = ctx->r2;
    // 0x8000C1A0: addiu       $a2, $a2, -0x5298
    ctx->r6 = ADD32(ctx->r6, -0X5298);
    // 0x8000C1A4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1A8: jal         0x80070C9C
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_18;
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_18:
    // 0x8000C1B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C1B4: addiu       $a2, $a2, -0x5298
    ctx->r6 = ADD32(ctx->r6, -0X5298);
    // 0x8000C1B8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C1C0: addiu       $a0, $a0, -0x51B4
    ctx->r4 = ADD32(ctx->r4, -0X51B4);
    // 0x8000C1C4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000C1C8: blez        $t4, L_8000C1F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000C1CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C1F4;
    }
    // 0x8000C1CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C1D0:
    // 0x8000C1D0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8000C1D4: nop

    // 0x8000C1D8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000C1DC: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8000C1E0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C1E8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000C1EC: bne         $at, $zero, L_8000C1D0
    if (ctx->r1 != 0) {
        // 0x8000C1F0: nop
    
            goto L_8000C1D0;
    }
    // 0x8000C1F0: nop

L_8000C1F4:
    // 0x8000C1F4: jal         0x80076C58
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    asset_table_load(rdram, ctx);
        goto after_19;
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_19:
    // 0x8000C1FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C200: sw          $v0, -0x5294($at)
    MEM_W(-0X5294, ctx->r1) = ctx->r2;
    // 0x8000C204: jal         0x80076C58
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    asset_table_load(rdram, ctx);
        goto after_20;
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_20:
    // 0x8000C20C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C210: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C214: addiu       $a1, $a1, -0x5290
    ctx->r5 = ADD32(ctx->r5, -0X5290);
    // 0x8000C218: addiu       $a0, $a0, -0x5260
    ctx->r4 = ADD32(ctx->r4, -0X5260);
    // 0x8000C21C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x8000C220: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C224: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000C228: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8000C22C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C230: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C234: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C238: beq         $a3, $t0, L_8000C260
    if (ctx->r7 == ctx->r8) {
        // 0x8000C23C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C260;
    }
    // 0x8000C23C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C240: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C244:
    // 0x8000C244: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000C248: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8000C24C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C250: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000C254: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C258: bne         $a3, $t4, L_8000C244
    if (ctx->r7 != ctx->r12) {
        // 0x8000C25C: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_8000C244;
    }
    // 0x8000C25C: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C260:
    // 0x8000C260: lw          $v0, 0x104($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X104);
    // 0x8000C264: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8000C268: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C26C: lw          $t6, -0x5294($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5294);
    // 0x8000C270: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x8000C274: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8000C278: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000C27C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000C280: jal         0x8000C2D8
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    decrypt_magic_codes(rdram, ctx);
        goto after_21;
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_21:
    // 0x8000C288: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C28C: jal         0x80070C9C
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_22;
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_22:
    // 0x8000C294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C298: sw          $v0, -0x51A8($at)
    MEM_W(-0X51A8, ctx->r1) = ctx->r2;
    // 0x8000C29C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A0: sb          $zero, -0x523C($at)
    MEM_B(-0X523C, ctx->r1) = 0;
    // 0x8000C2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A8: sb          $zero, -0x510C($at)
    MEM_B(-0X510C, ctx->r1) = 0;
    // 0x8000C2AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2B0: sb          $zero, -0x510B($at)
    MEM_B(-0X510B, ctx->r1) = 0;
    // 0x8000C2B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C2B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000C2BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2C0: jal         0x8000C460
    // 0x8000C2C4: swc1        $f4, -0x5258($at)
    MEM_W(-0X5258, ctx->r1) = ctx->f4.u32l;
    clear_object_pointers(rdram, ctx);
        goto after_23;
    // 0x8000C2C4: swc1        $f4, -0x5258($at)
    MEM_W(-0X5258, ctx->r1) = ctx->f4.u32l;
    after_23:
    // 0x8000C2C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C2CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C2D0: jr          $ra
    // 0x8000C2D4: nop

    return;
    // 0x8000C2D4: nop

;}
RECOMP_FUNC void osScGetCmdQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079574: jr          $ra
    // 0x80079578: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    return;
    // 0x80079578: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
;}
RECOMP_FUNC void has_ghost_to_save(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B780: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B784: lbu         $v0, -0x38D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X38D0);
    // 0x8001B788: jr          $ra
    // 0x8001B78C: nop

    return;
    // 0x8001B78C: nop

;}
RECOMP_FUNC void savemenu_load_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862C4: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800862C8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800862CC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800862D0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800862D4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800862D8: addiu       $s2, $s2, 0x6A08
    ctx->r18 = ADD32(ctx->r18, 0X6A08);
    // 0x800862DC: lw          $s6, 0x653C($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X653C);
    // 0x800862E0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800862E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800862E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800862EC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800862F0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800862F4: sw          $zero, 0x6BD4($at)
    MEM_W(0X6BD4, ctx->r1) = 0;
    // 0x800862F8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800862FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086304: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80086308: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008630C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80086310: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80086314: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80086318: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008631C: addiu       $s4, $s4, 0x6A0C
    ctx->r20 = ADD32(ctx->r20, 0X6A0C);
    // 0x80086320: addiu       $s1, $s1, 0x6530
    ctx->r17 = ADD32(ctx->r17, 0X6530);
    // 0x80086324: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80086328: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008632C: swc1        $f4, 0x6BDC($at)
    MEM_W(0X6BDC, ctx->r1) = ctx->f4.u32l;
L_80086330:
    // 0x80086330: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80086334: nop

    // 0x80086338: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x8008633C: nop

    // 0x80086340: bne         $t7, $zero, L_800863CC
    if (ctx->r15 != 0) {
        // 0x80086344: nop
    
            goto L_800863CC;
    }
    // 0x80086344: nop

    // 0x80086348: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8008634C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80086350: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80086354: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80086358: sb          $s3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r19;
    // 0x8008635C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80086360: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80086364: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086368: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8008636C: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    // 0x80086370: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80086374: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086378: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8008637C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80086380: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x80086384: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80086388: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x8008638C: sb          $t8, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r24;
    // 0x80086390: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80086394: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80086398: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8008639C: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800863A0: jal         0x80073C4C
    // 0x800863A4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800863A4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    after_0:
    // 0x800863A8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800863AC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800863B0: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x800863B4: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800863B8: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // 0x800863BC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800863C0: nop

    // 0x800863C4: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x800863C8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_800863CC:
    // 0x800863CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800863D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800863D4: bne         $s0, $at, L_80086330
    if (ctx->r16 != ctx->r1) {
        // 0x800863D8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80086330;
    }
    // 0x800863D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800863DC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800863E0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800863E4: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x800863E8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800863EC: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x800863F0: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x800863F4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800863F8: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800863FC: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x80086400: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80086404: jal         0x80073C54
    // 0x80086408: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    get_time_data_file_size(rdram, ctx);
        goto after_1;
    // 0x80086408: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    after_1:
    // 0x8008640C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086410: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086414: sll         $t1, $t7, 4
    ctx->r9 = S32(ctx->r15 << 4);
    // 0x80086418: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8008641C: sw          $v0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r2;
    // 0x80086420: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086424: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80086428: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8008642C: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x80086430: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80086434: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80086438: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8008643C: sb          $t4, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r12;
    // 0x80086440: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086444: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80086448: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8008644C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80086450: lw          $s0, 0x6A64($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6A64);
    // 0x80086454: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086458: addiu       $fp, $sp, 0xB4
    ctx->r30 = ADD32(ctx->r29, 0XB4);
L_8008645C:
    // 0x8008645C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80086460: lw          $t2, 0x6A18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A18);
    // 0x80086464: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80086468: beq         $t2, $zero, L_8008679C
    if (ctx->r10 == 0) {
        // 0x8008646C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008679C;
    }
    // 0x8008646C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086470: sw          $zero, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = 0;
    // 0x80086474: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_80086478:
    // 0x80086478: addiu       $t6, $sp, 0xA4
    ctx->r14 = ADD32(ctx->r29, 0XA4);
    // 0x8008647C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80086480: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80086484: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086488: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8008648C: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x80086490: jal         0x80075E60
    // 0x80086494: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x80086494: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x80086498: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8008649C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800864A0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800864A4: bne         $v1, $at, L_800864B8
    if (ctx->r3 != ctx->r1) {
        // 0x800864A8: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800864B8;
    }
    // 0x800864A8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800864AC: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x800864B0: bne         $at, $zero, L_80086478
    if (ctx->r1 != 0) {
        // 0x800864B4: addiu       $t8, $sp, 0x60
        ctx->r24 = ADD32(ctx->r29, 0X60);
            goto L_80086478;
    }
    // 0x800864B4: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_800864B8:
    // 0x800864B8: bne         $v0, $zero, L_80086728
    if (ctx->r2 != 0) {
        // 0x800864BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086728;
    }
    // 0x800864BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800864C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800864C4: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
L_800864C8:
    // 0x800864C8: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x800864CC: nop

    // 0x800864D0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800864D4: bne         $at, $zero, L_80086704
    if (ctx->r1 != 0) {
        // 0x800864D8: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_80086704;
    }
    // 0x800864D8: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800864DC: beq         $at, $zero, L_80086704
    if (ctx->r1 == 0) {
        // 0x800864E0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80086704;
    }
    // 0x800864E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800864E4: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    // 0x800864E8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800864EC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800864F0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800864F4: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x800864F8: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x800864FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80086500: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80086504: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x80086508: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8008650C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80086510: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086514: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x80086518: sb          $zero, 0x6($t3)
    MEM_B(0X6, ctx->r11) = 0;
    // 0x8008651C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086520: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80086524: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80086528: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x8008652C: sb          $s3, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r19;
    // 0x80086530: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086534: sll         $a3, $s3, 2
    ctx->r7 = S32(ctx->r19 << 2);
    // 0x80086538: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8008653C: addu        $t5, $sp, $a3
    ctx->r13 = ADD32(ctx->r29, ctx->r7);
    // 0x80086540: lw          $t5, 0x60($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X60);
    // 0x80086544: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80086548: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8008654C: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80086550: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x80086554: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086558: bne         $v1, $at, L_80086614
    if (ctx->r3 != ctx->r1) {
        // 0x8008655C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80086614;
    }
    // 0x8008655C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086560: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x80086564: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80086568: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    // 0x8008656C: jal         0x80073E1C
    // 0x80086570: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_3;
    // 0x80086570: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
    // 0x80086574: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086578: bne         $v0, $zero, L_80086600
    if (ctx->r2 != 0) {
        // 0x8008657C: nop
    
            goto L_80086600;
    }
    // 0x8008657C: nop

    // 0x80086580: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086584: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086588: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x8008658C: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80086590: sw          $s0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r16;
    // 0x80086594: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80086598: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8008659C: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x800865A0: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x800865A4: sb          $t8, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r24;
    // 0x800865A8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800865AC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800865B0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800865B4: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800865B8: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800865BC: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x800865C0: sb          $t5, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r13;
    // 0x800865C4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800865C8: lw          $t1, 0x10($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X10);
    // 0x800865CC: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800865D0: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x800865D4: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800865D8: sltu        $t8, $zero, $t2
    ctx->r24 = 0 < ctx->r10 ? 1 : 0;
    // 0x800865DC: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800865E0: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x800865E4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800865E8: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800865EC: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x800865F0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800865F4: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x800865F8: b           L_800866F4
    // 0x800865FC: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
        goto L_800866F4;
    // 0x800865FC: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
L_80086600:
    // 0x80086600: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80086604: nop

    // 0x80086608: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x8008660C: b           L_800866F4
    // 0x80086610: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
        goto L_800866F4;
    // 0x80086610: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80086614:
    // 0x80086614: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80086618: beq         $v1, $at, L_80086628
    if (ctx->r3 == ctx->r1) {
        // 0x8008661C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80086628;
    }
    // 0x8008661C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086620: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086624: bne         $v1, $at, L_800866F4
    if (ctx->r3 != ctx->r1) {
        // 0x80086628: addiu       $t8, $sp, 0xF4
        ctx->r24 = ADD32(ctx->r29, 0XF4);
            goto L_800866F4;
    }
L_80086628:
    // 0x80086628: addiu       $t8, $sp, 0xF4
    ctx->r24 = ADD32(ctx->r29, 0XF4);
    // 0x8008662C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086630: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80086634: bne         $v1, $at, L_80086640
    if (ctx->r3 != ctx->r1) {
        // 0x80086638: addu        $s1, $fp, $a3
        ctx->r17 = ADD32(ctx->r30, ctx->r7);
            goto L_80086640;
    }
    // 0x80086638: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x8008663C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80086640:
    // 0x80086640: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086644: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086648: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x8008664C: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x80086650: sw          $s0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r16;
    // 0x80086654: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80086658: nop

    // 0x8008665C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x80086660: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x80086664: nop

    // 0x80086668: beq         $v1, $zero, L_80086690
    if (ctx->r3 == 0) {
        // 0x8008666C: nop
    
            goto L_80086690;
    }
    // 0x8008666C: nop

L_80086670:
    // 0x80086670: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x80086674: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80086678: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008667C: addu        $t3, $t6, $v0
    ctx->r11 = ADD32(ctx->r14, ctx->r2);
    // 0x80086680: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x80086684: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086688: bne         $v1, $zero, L_80086670
    if (ctx->r3 != 0) {
        // 0x8008668C: nop
    
            goto L_80086670;
    }
    // 0x8008668C: nop

L_80086690:
    // 0x80086690: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80086694: nop

    // 0x80086698: beq         $a0, $zero, L_800866EC
    if (ctx->r4 == 0) {
        // 0x8008669C: nop
    
            goto L_800866EC;
    }
    // 0x8008669C: nop

    // 0x800866A0: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800866A4: addiu       $t1, $zero, 0x2E
    ctx->r9 = ADD32(0, 0X2E);
    // 0x800866A8: beq         $t8, $zero, L_800866EC
    if (ctx->r24 == 0) {
        // 0x800866AC: nop
    
            goto L_800866EC;
    }
    // 0x800866AC: nop

    // 0x800866B0: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x800866B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800866B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800866BC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800866C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800866C4: beq         $t9, $zero, L_800866EC
    if (ctx->r25 == 0) {
        // 0x800866C8: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_800866EC;
    }
    // 0x800866C8: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_800866CC:
    // 0x800866CC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800866D0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800866D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800866D8: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x800866DC: lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X0);
    // 0x800866E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800866E4: bne         $v1, $zero, L_800866CC
    if (ctx->r3 != 0) {
        // 0x800866E8: nop
    
            goto L_800866CC;
    }
    // 0x800866E8: nop

L_800866EC:
    // 0x800866EC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800866F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800866F4:
    // 0x800866F4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800866F8: nop

    // 0x800866FC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80086700: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80086704:
    // 0x80086704: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80086708: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8008670C: bne         $s3, $at, L_800864C8
    if (ctx->r19 != ctx->r1) {
        // 0x80086710: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800864C8;
    }
    // 0x80086710: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80086714: jal         0x80076164
    // 0x80086718: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    cpak_free_files(rdram, ctx);
        goto after_4;
    // 0x80086718: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    after_4:
    // 0x8008671C: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086720: b           L_8008679C
    // 0x80086724: nop

        goto L_8008679C;
    // 0x80086724: nop

L_80086728:
    // 0x80086728: bne         $v1, $at, L_8008676C
    if (ctx->r3 != ctx->r1) {
        // 0x8008672C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008676C;
    }
    // 0x8008672C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80086730: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086734: lw          $t3, 0x6A18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A18);
    // 0x80086738: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008673C: bgez        $t3, L_80086748
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80086740: sw          $t6, 0x6A14($at)
        MEM_W(0X6A14, ctx->r1) = ctx->r14;
            goto L_80086748;
    }
    // 0x80086740: sw          $t6, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = ctx->r14;
    // 0x80086744: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086748:
    // 0x80086748: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008674C: lw          $t8, 0x6A6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A6C);
    // 0x80086750: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086754: beq         $t8, $zero, L_8008679C
    if (ctx->r24 == 0) {
        // 0x80086758: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008679C;
    }
    // 0x80086758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008675C: sw          $t1, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = ctx->r9;
    // 0x80086760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086764: b           L_8008679C
    // 0x80086768: sw          $zero, 0x6A6C($at)
    MEM_W(0X6A6C, ctx->r1) = 0;
        goto L_8008679C;
    // 0x80086768: sw          $zero, 0x6A6C($at)
    MEM_W(0X6A6C, ctx->r1) = 0;
L_8008676C:
    // 0x8008676C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086770: bne         $v1, $at, L_80086780
    if (ctx->r3 != ctx->r1) {
        // 0x80086774: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80086780;
    }
    // 0x80086774: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086778: b           L_8008679C
    // 0x8008677C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8008679C;
    // 0x8008677C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086780:
    // 0x80086780: lw          $t9, 0x6A18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A18);
    // 0x80086784: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80086788: bgez        $t9, L_8008679C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8008678C: nop
    
            goto L_8008679C;
    }
    // 0x8008678C: nop

    // 0x80086790: bne         $v1, $at, L_8008679C
    if (ctx->r3 != ctx->r1) {
        // 0x80086794: nop
    
            goto L_8008679C;
    }
    // 0x80086794: nop

    // 0x80086798: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8008679C:
    // 0x8008679C: beq         $s7, $zero, L_8008645C
    if (ctx->r23 == 0) {
        // 0x800867A0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8008645C;
    }
    // 0x800867A0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800867A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800867A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800867AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800867B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800867B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800867B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800867BC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800867C0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800867C4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800867C8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800867CC: jr          $ra
    // 0x800867D0: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800867D0: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void sndp_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004384: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000438C: addiu       $v1, $v1, -0x3950
    ctx->r3 = ADD32(ctx->r3, -0X3950);
    // 0x80004390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004394: lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X8);
    // 0x80004398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000439C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800043A0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800043A4: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x800043A8: beq         $s0, $zero, L_8000450C
    if (ctx->r16 == 0) {
        // 0x800043AC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000450C;
    }
    // 0x800043AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800043B0: jal         0x800C9A30
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800043B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800043BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800043C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043C4: addiu       $v1, $v1, -0x3950
    ctx->r3 = ADD32(ctx->r3, -0X3950);
    // 0x800043C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800043CC: jal         0x800C8760
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    after_1:
    // 0x800043D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043D8: addiu       $v1, $v1, -0x3950
    ctx->r3 = ADD32(ctx->r3, -0X3950);
    // 0x800043DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800043E0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800043E4: beq         $v0, $zero, L_80004408
    if (ctx->r2 == 0) {
        // 0x800043E8: nop
    
            goto L_80004408;
    }
    // 0x800043E8: nop

    // 0x800043EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800043F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800043F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800043F8: nop

    // 0x800043FC: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x80004400: b           L_80004418
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
        goto L_80004418;
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_80004408:
    // 0x80004408: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000440C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80004410: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80004414: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
L_80004418:
    // 0x80004418: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000441C: jal         0x800C9A30
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80004424: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004428: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000442C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80004430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80004434: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x80004438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000443C: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80004440: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80004444: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    // 0x80004448: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8000444C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80004450: sb          $a1, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r5;
    // 0x80004454: sb          $t1, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r9;
    // 0x80004458: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8000445C: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    // 0x80004460: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80004464: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x80004468: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8000446C: andi        $t5, $t3, 0xF0
    ctx->r13 = ctx->r11 & 0XF0;
    // 0x80004470: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80004474: beq         $t6, $zero, L_800044AC
    if (ctx->r14 == 0) {
        // 0x80004478: sb          $t5, 0x3E($s0)
        MEM_B(0X3E, ctx->r16) = ctx->r13;
            goto L_800044AC;
    }
    // 0x80004478: sb          $t5, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r13;
    // 0x8000447C: lbu         $a0, 0x4($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X4);
    // 0x80004480: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80004484: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80004488: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8000448C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004490: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80004494: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004498: jal         0x800C99E0
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    after_3:
    // 0x800044A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044A4: b           L_800044E0
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_800044E0;
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044AC:
    // 0x800044AC: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    // 0x800044B0: lb          $t0, 0x5($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X5);
    // 0x800044B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800044B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800044BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800044C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800044C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800044C8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800044CC: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    // 0x800044D0: jal         0x800C99E0
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800044D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044DC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044E0:
    // 0x800044E0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800044E4: beq         $a1, $at, L_800044FC
    if (ctx->r5 == ctx->r1) {
        // 0x800044E8: addiu       $t3, $zero, 0x40
        ctx->r11 = ADD32(0, 0X40);
            goto L_800044FC;
    }
    // 0x800044E8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800044EC: lbu         $t1, 0x3E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X3E);
    // 0x800044F0: nop

    // 0x800044F4: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800044F8: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
L_800044FC:
    // 0x800044FC: addiu       $t4, $zero, 0x7FFF
    ctx->r12 = ADD32(0, 0X7FFF);
    // 0x80004500: sb          $zero, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = 0;
    // 0x80004504: sb          $t3, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r11;
    // 0x80004508: sh          $t4, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r12;
L_8000450C:
    // 0x8000450C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004510: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80004514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004518: jr          $ra
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void update_rocket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F310: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005F314: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005F318: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F31C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005F320: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F324: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8005F328: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005F32C: addiu       $a0, $a0, -0x3180
    ctx->r4 = ADD32(ctx->r4, -0X3180);
    // 0x8005F330: jal         0x8005CA78
    // 0x8005F334: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005F334: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005F338: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F33C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F340: sb          $zero, 0x1EC($a3)
    MEM_B(0X1EC, ctx->r7) = 0;
    // 0x8005F344: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F348: lwc1        $f6, 0x6B04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B04);
    // 0x8005F34C: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005F350: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8005F354: lwc1        $f7, 0x6B00($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6B00);
    // 0x8005F358: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005F35C: lh          $t8, 0x16A($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X16A);
    // 0x8005F360: nop

    // 0x8005F364: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005F368: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8005F36C: nop

    // 0x8005F370: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F374: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005F378: nop

    // 0x8005F37C: bc1f        L_8005F3A4
    if (!c1cs) {
        // 0x8005F380: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F3A4;
    }
    // 0x8005F380: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F384: lwc1        $f9, 0x6B08($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6B08);
    // 0x8005F388: lwc1        $f8, 0x6B0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6B0C);
    // 0x8005F38C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005F390: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005F394: nop

    // 0x8005F398: bc1f        L_8005F3A4
    if (!c1cs) {
        // 0x8005F39C: nop
    
            goto L_8005F3A4;
    }
    // 0x8005F39C: nop

    // 0x8005F3A0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005F3A4:
    // 0x8005F3A4: lb          $t2, 0x1D8($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F3A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F3AC: bne         $t2, $at, L_8005F3EC
    if (ctx->r10 != ctx->r1) {
        // 0x8005F3B0: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_8005F3EC;
    }
    // 0x8005F3B0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F3B4: jal         0x80023568
    // 0x8005F3B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005F3B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005F3BC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F3C0: beq         $v0, $zero, L_8005F3E8
    if (ctx->r2 == 0) {
        // 0x8005F3C4: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005F3E8;
    }
    // 0x8005F3C4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005F3C8: jal         0x80021400
    // 0x8005F3CC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005F3CC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005F3D0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F3D4: nop

    // 0x8005F3D8: lb          $t3, 0x1D8($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F3DC: nop

    // 0x8005F3E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F3E4: sb          $t4, 0x1D8($a3)
    MEM_B(0X1D8, ctx->r7) = ctx->r12;
L_8005F3E8:
    // 0x8005F3E8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
L_8005F3EC:
    // 0x8005F3EC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F3F0: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8005F3F4: nop

    // 0x8005F3F8: bne         $t0, $at, L_8005F404
    if (ctx->r8 != ctx->r1) {
        // 0x8005F3FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005F404;
    }
    // 0x8005F3FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F400: sb          $zero, -0x29F0($at)
    MEM_B(-0X29F0, ctx->r1) = 0;
L_8005F404:
    // 0x8005F404: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x8005F408: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F40C: bne         $v1, $t5, L_8005F48C
    if (ctx->r3 != ctx->r13) {
        // 0x8005F410: sb          $zero, 0x1F5($a3)
        MEM_B(0X1F5, ctx->r7) = 0;
            goto L_8005F48C;
    }
    // 0x8005F410: sb          $zero, 0x1F5($a3)
    MEM_B(0X1F5, ctx->r7) = 0;
    // 0x8005F414: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005F418: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F41C: beq         $v0, $at, L_8005F48C
    if (ctx->r2 == ctx->r1) {
        // 0x8005F420: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005F48C;
    }
    // 0x8005F420: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005F424: bgez        $t6, L_8005F484
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005F428: sw          $t6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r14;
            goto L_8005F484;
    }
    // 0x8005F428: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005F42C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005F430: lb          $t8, -0x29EF($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X29EF);
    // 0x8005F434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F438: bne         $t8, $zero, L_8005F460
    if (ctx->r24 != 0) {
        // 0x8005F43C: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005F460;
    }
    // 0x8005F43C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005F440: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F444: jal         0x8005CB04
    // 0x8005F448: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005F448: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8005F44C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F450: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F454: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F458: nop

    // 0x8005F45C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005F460:
    // 0x8005F460: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005F464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F468: sb          $t9, -0x29EF($at)
    MEM_B(-0X29EF, ctx->r1) = ctx->r25;
    // 0x8005F46C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005F470: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8005F474: nop

    // 0x8005F478: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x8005F47C: b           L_8005F48C
    // 0x8005F480: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8005F48C;
    // 0x8005F480: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8005F484:
    // 0x8005F484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F488: sb          $zero, -0x29EF($at)
    MEM_B(-0X29EF, ctx->r1) = 0;
L_8005F48C:
    // 0x8005F48C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8005F490: sb          $t4, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r12;
    // 0x8005F494: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005F498: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005F49C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8005F4A0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F4A4: jal         0x80049794
    // 0x8005F4A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005F4A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8005F4AC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F4B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F4B4: lb          $t5, 0x1D7($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D7);
    // 0x8005F4B8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F4BC: sb          $t5, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r13;
    // 0x8005F4C0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8005F4C4: nop

    // 0x8005F4C8: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8005F4CC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F4D0: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005F4D4: nop

    // 0x8005F4D8: sh          $t7, 0x16A($a3)
    MEM_H(0X16A, ctx->r7) = ctx->r15;
    // 0x8005F4DC: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005F4E0: nop

    // 0x8005F4E4: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8005F4E8: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F4EC: nop

    // 0x8005F4F0: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F4F4: lb          $t2, 0x187($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X187);
    // 0x8005F4F8: nop

    // 0x8005F4FC: beq         $t2, $zero, L_8005F5A4
    if (ctx->r10 == 0) {
        // 0x8005F500: nop
    
            goto L_8005F5A4;
    }
    // 0x8005F500: nop

    // 0x8005F504: lb          $t3, 0x3B($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F508: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F50C: beq         $t3, $at, L_8005F5A4
    if (ctx->r11 == ctx->r1) {
        // 0x8005F510: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005F5A4;
    }
    // 0x8005F510: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005F514: jal         0x8005CB04
    // 0x8005F518: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005F518: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8005F51C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005F520: jal         0x80001D04
    // 0x8005F524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005F524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005F528: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005F52C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F530: jal         0x80069F28
    // 0x8005F534: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005F534: nop

    after_7:
    // 0x8005F538: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F53C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F540: lwc1        $f1, 0x6B10($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6B10);
    // 0x8005F544: lwc1        $f0, 0x6B14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B14);
    // 0x8005F548: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F54C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F550: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F554: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F558: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F55C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F560: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F564: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005F568: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F56C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8005F570: sb          $t4, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r12;
    // 0x8005F574: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005F578: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F57C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005F584: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8005F588: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F58C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8005F590: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005F594: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F598: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005F59C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005F5A0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_8005F5A4:
    // 0x8005F5A4: lw          $t5, 0x148($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X148);
    // 0x8005F5A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F5AC: beq         $t5, $zero, L_8005F61C
    if (ctx->r13 == 0) {
        // 0x8005F5B0: sb          $zero, 0x187($a3)
        MEM_B(0X187, ctx->r7) = 0;
            goto L_8005F61C;
    }
    // 0x8005F5B0: sb          $zero, 0x187($a3)
    MEM_B(0X187, ctx->r7) = 0;
    // 0x8005F5B4: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F5B8: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F5BC: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005F5C0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F5C4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005F5C8: nop

    // 0x8005F5CC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005F5D0: nop

    // 0x8005F5D4: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005F5D8: jal         0x800C9AD0
    // 0x8005F5DC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005F5DC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005F5E0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005F5E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005F5E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005F5EC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005F5F0: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005F5F4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F5F8: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005F5FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F600: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F604: bc1f        L_8005F61C
    if (!c1cs) {
        // 0x8005F608: swc1        $f2, 0x2C($a3)
        MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
            goto L_8005F61C;
    }
    // 0x8005F608: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x8005F60C: swc1        $f18, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f18.u32l;
    // 0x8005F610: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8005F614: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8005F618: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_8005F61C:
    // 0x8005F61C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F620: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F624: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F628: add.d       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f12.d + ctx->f12.d;
    // 0x8005F62C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F630: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F634: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F638: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8005F63C: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x8005F640: lb          $t8, 0x3B($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F644: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005F648: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005F64C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005F650: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F654: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8005F658: nop

    // 0x8005F65C: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005F660: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005F664: nop

    // 0x8005F668: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005F66C: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005F670: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8005F674: nop

    // 0x8005F678: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005F67C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F680: nop

    // 0x8005F684: bc1f        L_8005F6B0
    if (!c1cs) {
        // 0x8005F688: nop
    
            goto L_8005F6B0;
    }
    // 0x8005F688: nop

L_8005F68C:
    // 0x8005F68C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F690: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
    // 0x8005F694: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F698: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F69C: nop

    // 0x8005F6A0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F6A4: nop

    // 0x8005F6A8: bc1t        L_8005F68C
    if (c1cs) {
        // 0x8005F6AC: nop
    
            goto L_8005F68C;
    }
    // 0x8005F6AC: nop

L_8005F6B0:
    // 0x8005F6B0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F6B4: nop

    // 0x8005F6B8: bc1f        L_8005F6E4
    if (!c1cs) {
        // 0x8005F6BC: nop
    
            goto L_8005F6E4;
    }
    // 0x8005F6BC: nop

L_8005F6C0:
    // 0x8005F6C0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F6C4: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8005F6C8: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F6CC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F6D0: nop

    // 0x8005F6D4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F6D8: nop

    // 0x8005F6DC: bc1t        L_8005F6C0
    if (c1cs) {
        // 0x8005F6E0: nop
    
            goto L_8005F6C0;
    }
    // 0x8005F6E0: nop

L_8005F6E4:
    // 0x8005F6E4: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F6E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F6EC: bne         $t6, $at, L_8005F714
    if (ctx->r14 != ctx->r1) {
        // 0x8005F6F0: nop
    
            goto L_8005F714;
    }
    // 0x8005F6F0: nop

    // 0x8005F6F4: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F6F8: nop

    // 0x8005F6FC: bne         $v1, $t8, L_8005F714
    if (ctx->r3 != ctx->r24) {
        // 0x8005F700: nop
    
            goto L_8005F714;
    }
    // 0x8005F700: nop

    // 0x8005F704: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8005F708: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F70C: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F710: nop

L_8005F714:
    // 0x8005F714: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005F718: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F71C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005F720: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F724: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F72C: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005F730: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8005F734: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005F738: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F73C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F740: jal         0x800AF714
    // 0x8005F744: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    update_vehicle_particles(rdram, ctx);
        goto after_9;
    // 0x8005F744: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_9:
    // 0x8005F748: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F750: jal         0x8005D048
    // 0x8005F754: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005F754: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_10:
    // 0x8005F758: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005F75C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F760: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005F764: nop

    // 0x8005F768: beq         $t3, $at, L_8005F7CC
    if (ctx->r11 == ctx->r1) {
        // 0x8005F76C: nop
    
            goto L_8005F7CC;
    }
    // 0x8005F76C: nop

    // 0x8005F770: jal         0x8000BF44
    // 0x8005F774: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    racerfx_get_boost(rdram, ctx);
        goto after_11;
    // 0x8005F774: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_11:
    // 0x8005F778: beq         $v0, $zero, L_8005F7CC
    if (ctx->r2 == 0) {
        // 0x8005F77C: nop
    
            goto L_8005F7CC;
    }
    // 0x8005F77C: nop

    // 0x8005F780: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8005F784: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8005F788: beq         $v1, $zero, L_8005F7CC
    if (ctx->r3 == 0) {
        // 0x8005F78C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8005F7CC;
    }
    // 0x8005F78C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005F790: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005F794: lbu         $t4, 0x72($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X72);
    // 0x8005F798: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F79C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005F7A0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F7A4: sb          $t6, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r14;
    // 0x8005F7A8: sb          $t8, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r24;
    // 0x8005F7AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F7B0: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
    // 0x8005F7B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005F7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F7BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8005F7C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005F7C4: jal         0x8000B750
    // 0x8005F7C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8000B750(rdram, ctx);
        goto after_12;
    // 0x8005F7C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
L_8005F7CC:
    // 0x8005F7CC: jal         0x8001BAC8
    // 0x8005F7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005F7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005F7D4: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F7D8: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8005F7DC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F7E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F7E4: bne         $s0, $t9, L_8005F814
    if (ctx->r16 != ctx->r25) {
        // 0x8005F7E8: addiu       $a1, $a1, -0x29F0
        ctx->r5 = ADD32(ctx->r5, -0X29F0);
            goto L_8005F814;
    }
    // 0x8005F7E8: addiu       $a1, $a1, -0x29F0
    ctx->r5 = ADD32(ctx->r5, -0X29F0);
    // 0x8005F7EC: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F7F0: nop

    // 0x8005F7F4: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F7F8: beq         $t3, $zero, L_8005F814
    if (ctx->r11 == 0) {
        // 0x8005F7FC: nop
    
            goto L_8005F814;
    }
    // 0x8005F7FC: nop

    // 0x8005F800: lb          $t4, 0x3B($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F808: bne         $t4, $at, L_8005F814
    if (ctx->r12 != ctx->r1) {
        // 0x8005F80C: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8005F814;
    }
    // 0x8005F80C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8005F810: sb          $t5, 0x187($a3)
    MEM_B(0X187, ctx->r7) = ctx->r13;
L_8005F814:
    // 0x8005F814: lb          $t6, 0x1D8($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F818: nop

    // 0x8005F81C: beq         $t6, $zero, L_8005F840
    if (ctx->r14 == 0) {
        // 0x8005F820: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F840;
    }
    // 0x8005F820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F824: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8005F828: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F82C: bne         $t8, $zero, L_8005F83C
    if (ctx->r24 != 0) {
        // 0x8005F830: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8005F83C;
    }
    // 0x8005F830: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005F834: jal         0x8005CB68
    // 0x8005F838: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    racer_boss_finish(rdram, ctx);
        goto after_14;
    // 0x8005F838: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    after_14:
L_8005F83C:
    // 0x8005F83C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F840:
    // 0x8005F840: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005F844: jr          $ra
    // 0x8005F848: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F848: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E70: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034E74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80034E78: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034E7C: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80034E80: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80034E84: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80034E88: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80034E8C: nop

    // 0x80034E90: sll         $t2, $t1, 10
    ctx->r10 = S32(ctx->r9 << 10);
    // 0x80034E94: jr          $ra
    // 0x80034E98: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    return;
    // 0x80034E98: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_8001F450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F458: jr          $ra
    // 0x8001F45C: sb          $t6, -0x52AD($at)
    MEM_B(-0X52AD, ctx->r1) = ctx->r14;
    return;
    // 0x8001F45C: sb          $t6, -0x52AD($at)
    MEM_B(-0X52AD, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void update_car_velocity_offground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80052D80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052D84: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80052D88: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80052D8C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80052D90: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x80052D94: lbu         $t6, 0x1FE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80052D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052D9C: bne         $t6, $at, L_80052DBC
    if (ctx->r14 != ctx->r1) {
        // 0x80052DA0: nop
    
            goto L_80052DBC;
    }
    // 0x80052DA0: nop

    // 0x80052DA4: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80052DA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052DAC: bne         $t7, $at, L_80052DBC
    if (ctx->r15 != ctx->r1) {
        // 0x80052DB0: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_80052DBC;
    }
    // 0x80052DB0: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80052DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052DB8: sw          $t8, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r24;
L_80052DBC:
    // 0x80052DBC: lbu         $t9, 0x1F0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1F0);
    // 0x80052DC0: nop

    // 0x80052DC4: beq         $t9, $zero, L_80052E58
    if (ctx->r25 == 0) {
        // 0x80052DC8: nop
    
            goto L_80052E58;
    }
    // 0x80052DC8: nop

    // 0x80052DCC: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80052DD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052DD4: beq         $t0, $at, L_80052DE8
    if (ctx->r8 == ctx->r1) {
        // 0x80052DD8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80052DE8;
    }
    // 0x80052DD8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80052DDC: lb          $v1, 0x1E1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052DE0: b           L_80052DF4
    // 0x80052DE4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
        goto L_80052DF4;
    // 0x80052DE4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80052DE8:
    // 0x80052DE8: lw          $v1, -0x2ACC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2ACC);
    // 0x80052DEC: nop

    // 0x80052DF0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80052DF4:
    // 0x80052DF4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80052DF8: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x80052DFC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80052E00: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052E04: lh          $a0, 0x1A4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X1A4);
    // 0x80052E08: lh          $t6, 0x1A0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1A0);
    // 0x80052E0C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80052E10: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80052E14: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80052E18: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80052E1C: mflo        $t3
    ctx->r11 = lo;
    // 0x80052E20: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80052E24: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80052E28: bne         $at, $zero, L_80052E3C
    if (ctx->r1 != 0) {
        // 0x80052E2C: sh          $t7, 0x1A0($a1)
        MEM_H(0X1A0, ctx->r5) = ctx->r15;
            goto L_80052E3C;
    }
    // 0x80052E2C: sh          $t7, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r15;
    // 0x80052E30: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80052E34: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80052E38: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80052E3C:
    // 0x80052E3C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80052E40: beq         $at, $zero, L_80052E4C
    if (ctx->r1 == 0) {
        // 0x80052E44: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80052E4C;
    }
    // 0x80052E44: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80052E48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80052E4C:
    // 0x80052E4C: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80052E50: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80052E54: sh          $t9, 0x1A4($a1)
    MEM_H(0X1A4, ctx->r5) = ctx->r25;
L_80052E58:
    // 0x80052E58: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80052E5C: nop

    // 0x80052E60: beq         $v0, $zero, L_80052E78
    if (ctx->r2 == 0) {
        // 0x80052E64: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052E78;
    }
    // 0x80052E64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052E68: jal         0x8000488C
    // 0x80052E6C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80052E6C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052E70: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052E74: nop

L_80052E78:
    // 0x80052E78: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80052E7C: nop

    // 0x80052E80: beq         $v0, $zero, L_80052E98
    if (ctx->r2 == 0) {
        // 0x80052E84: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052E98;
    }
    // 0x80052E84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052E88: jal         0x8000488C
    // 0x80052E8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x80052E8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_1:
    // 0x80052E90: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052E94: nop

L_80052E98:
    // 0x80052E98: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80052E9C: nop

    // 0x80052EA0: beq         $v0, $zero, L_80052EB8
    if (ctx->r2 == 0) {
        // 0x80052EA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052EB8;
    }
    // 0x80052EA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052EA8: jal         0x8000488C
    // 0x80052EAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80052EAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_2:
    // 0x80052EB0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052EB4: nop

L_80052EB8:
    // 0x80052EB8: lbu         $v0, 0x1FE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80052EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052EC0: beq         $v0, $at, L_80052ED0
    if (ctx->r2 == ctx->r1) {
        // 0x80052EC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80052ED0;
    }
    // 0x80052EC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052EC8: bne         $v0, $at, L_80052EDC
    if (ctx->r2 != ctx->r1) {
        // 0x80052ECC: nop
    
            goto L_80052EDC;
    }
    // 0x80052ECC: nop

L_80052ED0:
    // 0x80052ED0: lb          $t0, 0x1E1($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052ED4: nop

    // 0x80052ED8: sb          $t0, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r8;
L_80052EDC:
    // 0x80052EDC: lwc1        $f6, 0xC0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80052EE0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80052EE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80052EE8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80052EEC: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x80052EF0: nop

    // 0x80052EF4: bc1t        L_80053084
    if (c1cs) {
        // 0x80052EF8: nop
    
            goto L_80053084;
    }
    // 0x80052EF8: nop

    // 0x80052EFC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80052F00: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80052F04: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80052F08: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80052F0C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052F10: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80052F14: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80052F18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80052F1C: bc1f        L_80052F38
    if (!c1cs) {
        // 0x80052F20: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80052F38;
    }
    // 0x80052F20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052F24: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80052F28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80052F2C: nop

    // 0x80052F30: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
    // 0x80052F34: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
L_80052F38:
    // 0x80052F38: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80052F3C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80052F40: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80052F44: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80052F48: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80052F4C: bc1f        L_80052F60
    if (!c1cs) {
        // 0x80052F50: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80052F60;
    }
    // 0x80052F50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80052F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80052F58: nop

    // 0x80052F5C: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
L_80052F60:
    // 0x80052F60: lb          $t3, 0x1E1($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052F64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80052F68: sb          $t3, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r11;
    // 0x80052F6C: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x80052F70: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80052F74: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x80052F78: beq         $t4, $zero, L_80052FAC
    if (ctx->r12 == 0) {
        // 0x80052F7C: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_80052FAC;
    }
    // 0x80052F7C: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80052F80: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052F84: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80052F88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052F8C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80052F90: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x80052F94: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80052F98: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80052F9C: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x80052FA0: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x80052FA4: nop

    // 0x80052FA8: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
L_80052FAC:
    // 0x80052FAC: beq         $t6, $zero, L_80052FE8
    if (ctx->r14 == 0) {
        // 0x80052FB0: nop
    
            goto L_80052FE8;
    }
    // 0x80052FB0: nop

    // 0x80052FB4: lw          $t5, -0x2AC8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC8);
    // 0x80052FB8: nop

    // 0x80052FBC: slti        $at, $t5, -0x19
    ctx->r1 = SIGNED(ctx->r13) < -0X19 ? 1 : 0;
    // 0x80052FC0: beq         $at, $zero, L_80052FE8
    if (ctx->r1 == 0) {
        // 0x80052FC4: nop
    
            goto L_80052FE8;
    }
    // 0x80052FC4: nop

    // 0x80052FC8: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052FCC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80052FD0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80052FD4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80052FD8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80052FDC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80052FE0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80052FE4: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80052FE8:
    // 0x80052FE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052FEC: sb          $t7, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r15;
    // 0x80052FF0: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80052FF4: lwc1        $f1, 0x66F8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X66F8);
    // 0x80052FF8: lwc1        $f0, 0x66FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X66FC);
    // 0x80052FFC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80053000: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80053004: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053008: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005300C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80053010: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80053014: mul.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80053018: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005301C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80053020: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80053024: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80053028: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8005302C: addiu       $a2, $a2, -0x2B08
    ctx->r6 = ADD32(ctx->r6, -0X2B08);
    // 0x80053030: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80053034: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80053038: lwc1        $f16, 0x6704($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6704);
    // 0x8005303C: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80053040: lwc1        $f17, 0x6700($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6700);
    // 0x80053044: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053048: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8005304C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80053050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80053054: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80053058: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x8005305C: lw          $t0, -0x2ACC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2ACC);
    // 0x80053060: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80053064: lb          $a3, -0x2AFC($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2AFC);
    // 0x80053068: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005306C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80053070: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80053074: jal         0x800494E0
    // 0x80053078: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    rotate_racer_in_water(rdram, ctx);
        goto after_3;
    // 0x80053078: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x8005307C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80053080: nop

L_80053084:
    // 0x80053084: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x80053088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005308C: bne         $t1, $at, L_800530A0
    if (ctx->r9 != ctx->r1) {
        // 0x80053090: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800530A0;
    }
    // 0x80053090: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80053094: lb          $t2, 0x1E1($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1E1);
    // 0x80053098: nop

    // 0x8005309C: sb          $t2, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r10;
L_800530A0:
    // 0x800530A0: lb          $v0, 0x1D3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1D3);
    // 0x800530A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800530A8: blez        $v0, L_800530C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800530AC: addiu       $a2, $a2, -0x2AAC
        ctx->r6 = ADD32(ctx->r6, -0X2AAC);
            goto L_800530C4;
    }
    // 0x800530AC: addiu       $a2, $a2, -0x2AAC
    ctx->r6 = ADD32(ctx->r6, -0X2AAC);
    // 0x800530B0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800530B4: nop

    // 0x800530B8: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x800530BC: b           L_800530C8
    // 0x800530C0: sb          $t4, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r12;
        goto L_800530C8;
    // 0x800530C0: sb          $t4, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r12;
L_800530C4:
    // 0x800530C4: sb          $zero, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = 0;
L_800530C8:
    // 0x800530C8: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800530CC: lb          $v0, 0x1E8($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1E8);
    // 0x800530D0: lwc1        $f9, 0x6708($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6708);
    // 0x800530D4: lwc1        $f8, 0x670C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X670C);
    // 0x800530D8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800530DC: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800530E0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800530E4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800530E8: bc1f        L_80053108
    if (!c1cs) {
        // 0x800530EC: sll         $v0, $t6, 1
        ctx->r2 = S32(ctx->r14 << 1);
            goto L_80053108;
    }
    // 0x800530EC: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
    // 0x800530F0: lb          $v0, 0x1E1($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1E1);
    // 0x800530F4: nop

    // 0x800530F8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800530FC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80053100: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80053104: sll         $v0, $t5, 1
    ctx->r2 = S32(ctx->r13 << 1);
L_80053108:
    // 0x80053108: lh          $t7, 0x1A0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X1A0);
    // 0x8005310C: lw          $t0, 0x110($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X110);
    // 0x80053110: subu        $t9, $t7, $v0
    ctx->r25 = SUB32(ctx->r15, ctx->r2);
    // 0x80053114: sh          $t9, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r25;
    // 0x80053118: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8005311C: lb          $t1, 0x1D3($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1D3);
    // 0x80053120: lui         $at, 0xC034
    ctx->r1 = S32(0XC034 << 16);
    // 0x80053124: beq         $t1, $zero, L_80053164
    if (ctx->r9 == 0) {
        // 0x80053128: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80053164;
    }
    // 0x80053128: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005312C: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053130: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80053134: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053138: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8005313C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80053140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053144: bc1f        L_80053164
    if (!c1cs) {
        // 0x80053148: nop
    
            goto L_80053164;
    }
    // 0x80053148: nop

    // 0x8005314C: lwc1        $f5, 0x6710($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6710);
    // 0x80053150: lwc1        $f4, 0x6714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6714);
    // 0x80053154: nop

    // 0x80053158: sub.d       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f0.d - ctx->f4.d;
    // 0x8005315C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80053160: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
L_80053164:
    // 0x80053164: lw          $v1, -0x2AC8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AC8);
    // 0x80053168: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8005316C: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x80053170: beq         $at, $zero, L_80053184
    if (ctx->r1 == 0) {
        // 0x80053174: slti        $at, $v1, -0x31
        ctx->r1 = SIGNED(ctx->r3) < -0X31 ? 1 : 0;
            goto L_80053184;
    }
    // 0x80053174: slti        $at, $v1, -0x31
    ctx->r1 = SIGNED(ctx->r3) < -0X31 ? 1 : 0;
    // 0x80053178: bne         $at, $zero, L_80053184
    if (ctx->r1 != 0) {
        // 0x8005317C: nop
    
            goto L_80053184;
    }
    // 0x8005317C: nop

    // 0x80053180: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80053184:
    // 0x80053184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053188: lwc1        $f16, 0x20($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8005318C: lwc1        $f19, 0x6718($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6718);
    // 0x80053190: lwc1        $f18, 0x671C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X671C);
    // 0x80053194: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80053198: mul.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8005319C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800531A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800531A4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800531A8: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800531AC: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800531B0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800531B4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
    // 0x800531B8: lbu         $t3, 0x1F1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1F1);
    // 0x800531BC: lwc1        $f2, -0x2A94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x800531C0: bne         $t3, $zero, L_800531D8
    if (ctx->r11 != 0) {
        // 0x800531C4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800531D8;
    }
    // 0x800531C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800531C8: lbu         $t4, 0x1F0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1F0);
    // 0x800531CC: nop

    // 0x800531D0: beq         $t4, $zero, L_80053214
    if (ctx->r12 == 0) {
        // 0x800531D4: nop
    
            goto L_80053214;
    }
    // 0x800531D4: nop

L_800531D8:
    // 0x800531D8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800531DC: lh          $t6, 0x160($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X160);
    // 0x800531E0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800531E4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800531E8: sll         $t7, $t7, 8
    ctx->r15 = S32(ctx->r15 << 8);
    // 0x800531EC: lwc1        $f2, 0x6720($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6720);
    // 0x800531F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800531F4: sh          $t8, 0x160($a1)
    MEM_H(0X160, ctx->r5) = ctx->r24;
    // 0x800531F8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800531FC: lh          $t9, 0x162($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X162);
    // 0x80053200: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80053204: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80053208: sll         $t1, $t1, 9
    ctx->r9 = S32(ctx->r9 << 9);
    // 0x8005320C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80053210: sh          $t2, 0x162($a1)
    MEM_H(0X162, ctx->r5) = ctx->r10;
L_80053214:
    // 0x80053214: lbu         $v0, 0x1FE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80053218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005321C: beq         $v0, $at, L_80053228
    if (ctx->r2 == ctx->r1) {
        // 0x80053220: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80053228;
    }
    // 0x80053220: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053224: bne         $v0, $at, L_800532B4
    if (ctx->r2 != ctx->r1) {
        // 0x80053228: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800532B4;
    }
L_80053228:
    // 0x80053228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005322C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80053230: lwc1        $f1, 0x6728($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6728);
    // 0x80053234: lwc1        $f0, 0x672C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X672C);
    // 0x80053238: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005323C: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80053240: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053244: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x80053248: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005324C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80053250: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80053254: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80053258: swc1        $f8, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f8.u32l;
    // 0x8005325C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80053260: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x80053264: bne         $at, $zero, L_8005328C
    if (ctx->r1 != 0) {
        // 0x80053268: sb          $t3, 0x33($sp)
        MEM_B(0X33, ctx->r29) = ctx->r11;
            goto L_8005328C;
    }
    // 0x80053268: sb          $t3, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r11;
    // 0x8005326C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053270: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053274: lwc1        $f17, 0x6730($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6730);
    // 0x80053278: lwc1        $f16, 0x6734($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6734);
    // 0x8005327C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80053280: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x80053284: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80053288: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
L_8005328C:
    // 0x8005328C: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x80053290: beq         $at, $zero, L_800532B4
    if (ctx->r1 == 0) {
        // 0x80053294: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800532B4;
    }
    // 0x80053294: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053298: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8005329C: lwc1        $f9, 0x6738($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6738);
    // 0x800532A0: lwc1        $f8, 0x673C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X673C);
    // 0x800532A4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800532A8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800532AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800532B0: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_800532B4:
    // 0x800532B4: lb          $t4, 0x33($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X33);
    // 0x800532B8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800532BC: beq         $t4, $zero, L_80053314
    if (ctx->r12 == 0) {
        // 0x800532C0: slti        $at, $v1, 0x33
        ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
            goto L_80053314;
    }
    // 0x800532C0: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x800532C4: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x800532C8: sb          $zero, 0x1E6($a1)
    MEM_B(0X1E6, ctx->r5) = 0;
    // 0x800532CC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800532D0: lw          $v0, 0x10C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10C);
    // 0x800532D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800532D8: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800532DC: mflo        $t7
    ctx->r15 = lo;
    // 0x800532E0: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800532E4: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x800532E8: sw          $t0, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->r8;
    // 0x800532EC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800532F0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800532F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800532F8: jal         0x80053478
    // 0x800532FC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    handle_car_steering(rdram, ctx);
        goto after_4;
    // 0x800532FC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_4:
    // 0x80053300: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80053304: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80053308: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005330C: b           L_80053354
    // 0x80053310: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
        goto L_80053354;
    // 0x80053310: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
L_80053314:
    // 0x80053314: bne         $at, $zero, L_80053330
    if (ctx->r1 != 0) {
        // 0x80053318: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053330;
    }
    // 0x80053318: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005331C: lwc1        $f7, 0x6740($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6740);
    // 0x80053320: lwc1        $f6, 0x6744($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6744);
    // 0x80053324: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053328: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005332C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80053330:
    // 0x80053330: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x80053334: beq         $at, $zero, L_80053350
    if (ctx->r1 == 0) {
        // 0x80053338: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053350;
    }
    // 0x80053338: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005333C: lwc1        $f17, 0x6748($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6748);
    // 0x80053340: lwc1        $f16, 0x674C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X674C);
    // 0x80053344: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80053348: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8005334C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80053350:
    // 0x80053350: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
L_80053354:
    // 0x80053354: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80053358: beq         $t9, $zero, L_80053378
    if (ctx->r25 == 0) {
        // 0x8005335C: sll         $t1, $v1, 6
        ctx->r9 = S32(ctx->r3 << 6);
            goto L_80053378;
    }
    // 0x8005335C: sll         $t1, $v1, 6
    ctx->r9 = S32(ctx->r3 << 6);
    // 0x80053360: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80053364: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80053368: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005336C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053370: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80053374: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80053378:
    // 0x80053378: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8005337C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80053380: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    // 0x80053384: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80053388: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8005338C: subu        $v0, $t2, $t4
    ctx->r2 = SUB32(ctx->r10, ctx->r12);
    // 0x80053390: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80053394: bne         $at, $zero, L_800533A4
    if (ctx->r1 != 0) {
        // 0x80053398: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800533A4;
    }
    // 0x80053398: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005339C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800533A0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800533A4:
    // 0x800533A4: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800533A8: beq         $at, $zero, L_800533B4
    if (ctx->r1 == 0) {
        // 0x800533AC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800533B4;
    }
    // 0x800533AC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800533B0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800533B4:
    // 0x800533B4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800533B8: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800533BC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800533C0: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x800533C4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800533C8: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800533CC: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800533D0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800533D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800533D8: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x800533DC: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800533E0: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x800533E4: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x800533E8: nop

    // 0x800533EC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800533F0: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x800533F4: nop

    // 0x800533F8: bc1f        L_80053460
    if (!c1cs) {
        // 0x800533FC: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_80053460;
    }
    // 0x800533FC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80053400: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80053404: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80053408: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8005340C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80053410: mul.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80053414: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80053418: nop

    // 0x8005341C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80053420: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80053424: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80053428: nop

    // 0x8005342C: cvt.w.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_D(ctx->f6.d);
    // 0x80053430: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80053434: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80053438: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x8005343C: beq         $at, $zero, L_8005344C
    if (ctx->r1 == 0) {
        // 0x80053440: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8005344C;
    }
    // 0x80053440: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x80053444: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80053448: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
L_8005344C:
    // 0x8005344C: bne         $at, $zero, L_80053458
    if (ctx->r1 != 0) {
        // 0x80053450: nop
    
            goto L_80053458;
    }
    // 0x80053450: nop

    // 0x80053454: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80053458:
    // 0x80053458: sb          $v1, 0x1E0($a1)
    MEM_B(0X1E0, ctx->r5) = ctx->r3;
    // 0x8005345C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_80053460:
    // 0x80053460: nop

    // 0x80053464: sw          $zero, 0x74($t0)
    MEM_W(0X74, ctx->r8) = 0;
    // 0x80053468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005346C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80053470: jr          $ra
    // 0x80053474: nop

    return;
    // 0x80053474: nop

;}
RECOMP_FUNC void timetrial_save_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B73C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B740: jal         0x800599A8
    // 0x8001B744: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B744: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B748: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B74C: lh          $t6, -0x38DC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X38DC);
    // 0x8001B750: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8001B754: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8001B758: lh          $a3, -0x38D4($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X38D4);
    // 0x8001B75C: lh          $a2, -0x38D8($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X38D8);
    // 0x8001B760: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001B764: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B768: jal         0x80059B7C
    // 0x8001B76C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    timetrial_write_player_ghost(rdram, ctx);
        goto after_1;
    // 0x8001B76C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8001B770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B778: jr          $ra
    // 0x8001B77C: nop

    return;
    // 0x8001B77C: nop

;}
RECOMP_FUNC void weather_clip_planes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB308: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AB30C: addiu       $v0, $v0, 0x7BF8
    ctx->r2 = ADD32(ctx->r2, 0X7BF8);
    // 0x800AB310: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800AB314: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800AB318: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AB31C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800AB320: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AB324: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AB328: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB32C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AB330: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AB334: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AB338: beq         $at, $zero, L_800AB34C
    if (ctx->r1 == 0) {
        // 0x800AB33C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800AB34C;
    }
    // 0x800AB33C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AB340: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800AB344: jr          $ra
    // 0x800AB348: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    return;
    // 0x800AB348: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_800AB34C:
    // 0x800AB34C: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800AB350: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x800AB354: jr          $ra
    // 0x800AB358: nop

    return;
    // 0x800AB358: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77A8: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800C77AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C77B0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C77B4: blez        $t6, L_800C77E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C77B8: nop
    
            goto L_800C77E0;
    }
    // 0x800C77B8: nop

    // 0x800C77BC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800C77C0:
    // 0x800C77C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C77C4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C77C8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C77CC: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C77D0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800C77D4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C77D8: bnel        $at, $zero, L_800C77C0
    if (ctx->r1 != 0) {
        // 0x800C77DC: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800C77C0;
    }
    goto skip_0;
    // 0x800C77DC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_800C77E0:
    // 0x800C77E0: jr          $ra
    // 0x800C77E4: nop

    return;
    // 0x800C77E4: nop

;}
RECOMP_FUNC void toggle_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E194: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E198: addiu       $v0, $v0, -0x38C4
    ctx->r2 = ADD32(ctx->r2, -0X38C4);
    // 0x8000E19C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000E1A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E1A4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000E1A8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000E1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1B0: jr          $ra
    // 0x8000E1B4: sb          $zero, -0x38C0($at)
    MEM_B(-0X38C0, ctx->r1) = 0;
    return;
    // 0x8000E1B4: sb          $zero, -0x38C0($at)
    MEM_B(-0X38C0, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853D0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800853D4: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x800853D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800853DC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800853E0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800853E4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800853E8: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x800853EC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800853F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800853F4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800853F8: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x800853FC: beq         $at, $zero, L_80085828
    if (ctx->r1 == 0) {
        // 0x80085400: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80085828;
    }
    // 0x80085400: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085404: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80085408: addu        $at, $at, $t8
    gpr jr_addend_80085414 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008540C: lw          $t8, -0x7C48($at)
    ctx->r24 = ADD32(ctx->r1, -0X7C48);
    // 0x80085410: nop

    // 0x80085414: jr          $t8
    // 0x80085418: nop

    switch (jr_addend_80085414 >> 2) {
        case 0: goto L_8008541C; break;
        case 1: goto L_8008553C; break;
        case 2: goto L_80085574; break;
        case 3: goto L_80085690; break;
        case 4: goto L_800856DC; break;
        case 5: goto L_80085728; break;
        case 6: goto L_80085828; break;
        case 7: goto L_80085774; break;
        case 8: goto L_800857C0; break;
        case 9: goto L_800857F0; break;
        default: switch_error(__func__, 0x80085414, 0x800E83B8);
    }
    // 0x80085418: nop

L_8008541C:
    // 0x8008541C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085420: addiu       $t9, $t9, -0x3F0
    ctx->r25 = ADD32(ctx->r25, -0X3F0);
    // 0x80085424: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80085428: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8008542C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80085430: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80085434: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80085438: lw          $v0, 0x6530($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6530);
    // 0x8008543C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085440: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x80085444: lw          $t0, 0x665C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X665C);
    // 0x80085448: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x8008544C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085450: bne         $t3, $zero, L_80085510
    if (ctx->r11 != 0) {
        // 0x80085454: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80085510;
    }
    // 0x80085454: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80085458: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x8008545C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80085460: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80085464: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80085468: jal         0x800976F8
    // 0x8008546C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_0;
    // 0x8008546C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80085470: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80085474: jal         0x800977D0
    // 0x80085478: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    filename_trim(rdram, ctx);
        goto after_1;
    // 0x80085478: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x8008547C: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x80085480: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085484: lbu         $t5, 0x6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6);
    // 0x80085488: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008548C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80085490: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80085494: lw          $v0, 0x6530($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6530);
    // 0x80085498: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8008549C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800854A0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800854A4: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800854A8: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800854AC: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x800854B0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800854B4: bne         $a0, $zero, L_800854C0
    if (ctx->r4 != 0) {
        // 0x800854B8: nop
    
            goto L_800854C0;
    }
    // 0x800854B8: nop

    // 0x800854BC: break       7
    do_break(2148029628);
L_800854C0:
    // 0x800854C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800854C4: bne         $a0, $at, L_800854D8
    if (ctx->r4 != ctx->r1) {
        // 0x800854C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800854D8;
    }
    // 0x800854C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800854CC: bne         $v1, $at, L_800854D8
    if (ctx->r3 != ctx->r1) {
        // 0x800854D0: nop
    
            goto L_800854D8;
    }
    // 0x800854D0: nop

    // 0x800854D4: break       6
    do_break(2148029652);
L_800854D8:
    // 0x800854D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800854DC: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800854E0: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800854E4: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800854E8: mflo        $t2
    ctx->r10 = lo;
    // 0x800854EC: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800854F0: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x800854F4: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800854F8: nop

    // 0x800854FC: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80085500: beq         $t5, $zero, L_80085524
    if (ctx->r13 == 0) {
        // 0x80085504: nop
    
            goto L_80085524;
    }
    // 0x80085504: nop

    // 0x80085508: b           L_80085524
    // 0x8008550C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085524;
    // 0x8008550C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085510:
    // 0x80085510: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085514: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80085518: lw          $t7, 0x3B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3B0);
    // 0x8008551C: nop

    // 0x80085520: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_80085524:
    // 0x80085524: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085528: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8008552C: nop

    // 0x80085530: lw          $t9, 0x1DC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1DC);
    // 0x80085534: b           L_80085858
    // 0x80085538: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085858;
    // 0x80085538: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8008553C:
    // 0x8008553C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085540: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085544: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80085548: addiu       $t2, $t2, -0x3E0
    ctx->r10 = ADD32(ctx->r10, -0X3E0);
    // 0x8008554C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085550: lw          $t3, 0x1E0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1E0);
    // 0x80085554: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085558: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8008555C: lw          $t4, 0x1DC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1DC);
    // 0x80085560: lw          $t0, 0x665C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X665C);
    // 0x80085564: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x80085568: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x8008556C: b           L_80085858
    // 0x80085570: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085858;
    // 0x80085570: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_80085574:
    // 0x80085574: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085578: addiu       $t5, $t5, -0x3F0
    ctx->r13 = ADD32(ctx->r13, -0X3F0);
    // 0x8008557C: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80085580: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80085584: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80085588: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008558C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085590: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085594: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80085598: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8008559C: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x800855A0: lw          $t1, -0x534($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X534);
    // 0x800855A4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x800855A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800855AC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800855B0: jal         0x800976F8
    // 0x800855B4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x800855B4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800855B8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800855BC: lw          $a2, 0x1E10($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1E10);
    // 0x800855C0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800855C4: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800855C8: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800855CC: beq         $t8, $zero, L_800855F8
    if (ctx->r24 == 0) {
        // 0x800855D0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800855F8;
    }
    // 0x800855D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800855D4: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x800855D8: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x800855DC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_800855E0:
    // 0x800855E0: sb          $a0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r4;
    // 0x800855E4: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x800855E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800855EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800855F0: bne         $a0, $zero, L_800855E0
    if (ctx->r4 != 0) {
        // 0x800855F4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800855E0;
    }
    // 0x800855F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800855F8:
    // 0x800855F8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800855FC: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x80085600: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80085604: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80085608: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x8008560C: sb          $t4, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r12;
    // 0x80085610: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80085614: sb          $t3, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r11;
    // 0x80085618: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x8008561C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085620: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80085624: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085628: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8008562C: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x80085630: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80085634: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80085638: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x8008563C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80085640: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x80085644: bne         $a0, $zero, L_80085650
    if (ctx->r4 != 0) {
        // 0x80085648: nop
    
            goto L_80085650;
    }
    // 0x80085648: nop

    // 0x8008564C: break       7
    do_break(2148030028);
L_80085650:
    // 0x80085650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085654: bne         $a0, $at, L_80085668
    if (ctx->r4 != ctx->r1) {
        // 0x80085658: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80085668;
    }
    // 0x80085658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008565C: bne         $v1, $at, L_80085668
    if (ctx->r3 != ctx->r1) {
        // 0x80085660: nop
    
            goto L_80085668;
    }
    // 0x80085660: nop

    // 0x80085664: break       6
    do_break(2148030052);
L_80085668:
    // 0x80085668: mflo        $t2
    ctx->r10 = lo;
    // 0x8008566C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80085670: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80085674: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x80085678: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x8008567C: nop

    // 0x80085680: beq         $t4, $zero, L_8008585C
    if (ctx->r12 == 0) {
        // 0x80085684: lw          $a1, 0x84($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X84);
            goto L_8008585C;
    }
    // 0x80085684: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085688: b           L_80085858
    // 0x8008568C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085858;
    // 0x8008568C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085690:
    // 0x80085690: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085694: addiu       $t5, $t5, -0x3E0
    ctx->r13 = ADD32(ctx->r13, -0X3E0);
    // 0x80085698: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8008569C: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x800856A0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800856A4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800856A8: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x800856AC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800856B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800856B4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800856B8: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800856BC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800856C0: lw          $t4, 0x158($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X158);
    // 0x800856C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800856C8: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800856CC: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x800856D0: lw          $t1, -0x534($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X534);
    // 0x800856D4: b           L_80085858
    // 0x800856D8: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085858;
    // 0x800856D8: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800856DC:
    // 0x800856DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800856E0: addiu       $t6, $t6, -0x3D0
    ctx->r14 = ADD32(ctx->r14, -0X3D0);
    // 0x800856E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800856E8: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x800856EC: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800856F0: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x800856F4: lw          $t7, 0x1E4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1E4);
    // 0x800856F8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800856FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085700: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80085704: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80085708: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8008570C: lw          $t2, 0x158($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X158);
    // 0x80085710: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085714: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80085718: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x8008571C: lw          $t1, -0x534($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X534);
    // 0x80085720: b           L_80085858
    // 0x80085724: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
        goto L_80085858;
    // 0x80085724: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
L_80085728:
    // 0x80085728: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008572C: addiu       $t3, $t3, -0x3C0
    ctx->r11 = ADD32(ctx->r11, -0X3C0);
    // 0x80085730: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085734: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085738: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008573C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80085740: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80085744: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80085748: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008574C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80085750: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80085754: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80085758: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x8008575C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085760: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80085764: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x80085768: lw          $t1, -0x534($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X534);
    // 0x8008576C: b           L_80085858
    // 0x80085770: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085858;
    // 0x80085770: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_80085774:
    // 0x80085774: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085778: addiu       $t2, $t2, -0x3B0
    ctx->r10 = ADD32(ctx->r10, -0X3B0);
    // 0x8008577C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085780: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80085784: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085788: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x8008578C: lw          $t4, 0x1E8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1E8);
    // 0x80085790: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80085794: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085798: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x8008579C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800857A0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800857A4: lw          $t7, 0x158($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X158);
    // 0x800857A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800857AC: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800857B0: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x800857B4: lw          $t1, -0x534($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X534);
    // 0x800857B8: b           L_80085858
    // 0x800857BC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_80085858;
    // 0x800857BC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_800857C0:
    // 0x800857C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800857C4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800857C8: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x800857CC: addiu       $t8, $t8, -0x3D0
    ctx->r24 = ADD32(ctx->r24, -0X3D0);
    // 0x800857D0: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800857D4: lw          $t2, 0x1EC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1EC);
    // 0x800857D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800857DC: lw          $t0, 0x6664($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6664);
    // 0x800857E0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800857E4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800857E8: b           L_80085858
    // 0x800857EC: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
        goto L_80085858;
    // 0x800857EC: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
L_800857F0:
    // 0x800857F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800857F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800857F8: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x800857FC: addiu       $t3, $t3, -0x3F0
    ctx->r11 = ADD32(ctx->r11, -0X3F0);
    // 0x80085800: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085804: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x80085808: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008580C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085810: lw          $t6, 0x1DC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1DC);
    // 0x80085814: lw          $t0, 0x665C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X665C);
    // 0x80085818: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x8008581C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085820: b           L_80085858
    // 0x80085824: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
        goto L_80085858;
    // 0x80085824: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
L_80085828:
    // 0x80085828: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008582C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085830: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x80085834: addiu       $t5, $t5, -0x3A0
    ctx->r13 = ADD32(ctx->r13, -0X3A0);
    // 0x80085838: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8008583C: lw          $t8, 0x144($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X144);
    // 0x80085840: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085844: lui         $t1, 0x8080
    ctx->r9 = S32(0X8080 << 16);
    // 0x80085848: lw          $t0, 0x6664($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6664);
    // 0x8008584C: ori         $t1, $t1, 0x80FF
    ctx->r9 = ctx->r9 | 0X80FF;
    // 0x80085850: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80085854: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_80085858:
    // 0x80085858: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
L_8008585C:
    // 0x8008585C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80085860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085864: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80085868: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8008586C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80085870: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085874: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80085878: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008587C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085880: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085884: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x80085888: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008588C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80085890: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x80085894: jal         0x80080580
    // 0x80085898: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    func_80080580(rdram, ctx);
        goto after_3;
    // 0x80085898: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    after_3:
    // 0x8008589C: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x800858A0: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x800858A4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x800858A8: bne         $v1, $zero, L_800858B4
    if (ctx->r3 != 0) {
        // 0x800858AC: addiu       $t7, $t5, 0xC
        ctx->r15 = ADD32(ctx->r13, 0XC);
            goto L_800858B4;
    }
    // 0x800858AC: addiu       $t7, $t5, 0xC
    ctx->r15 = ADD32(ctx->r13, 0XC);
    // 0x800858B0: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
L_800858B4:
    // 0x800858B4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800858B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800858BC: beq         $v0, $at, L_800858F8
    if (ctx->r2 == ctx->r1) {
        // 0x800858C0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800858F8;
    }
    // 0x800858C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800858C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800858C8: bne         $v0, $at, L_80085A0C
    if (ctx->r2 != ctx->r1) {
        // 0x800858CC: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085A0C;
    }
    // 0x800858CC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800858D0: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x800858D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800858D8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800858DC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x800858E0: lw          $t9, 0x6530($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6530);
    // 0x800858E4: nop

    // 0x800858E8: lbu         $t3, 0x4B($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X4B);
    // 0x800858EC: nop

    // 0x800858F0: bne         $t3, $zero, L_80085A0C
    if (ctx->r11 != 0) {
        // 0x800858F4: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085A0C;
    }
    // 0x800858F4: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_800858F8:
    // 0x800858F8: bne         $v1, $zero, L_80085908
    if (ctx->r3 != 0) {
        // 0x800858FC: addiu       $a1, $zero, 0x78
        ctx->r5 = ADD32(0, 0X78);
            goto L_80085908;
    }
    // 0x800858FC: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80085900: b           L_80085908
    // 0x80085904: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
        goto L_80085908;
    // 0x80085904: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
L_80085908:
    // 0x80085908: jal         0x80068508
    // 0x8008590C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x8008590C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80085910: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80085914: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80085918: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008591C: subu        $v0, $a1, $t4
    ctx->r2 = SUB32(ctx->r5, ctx->r12);
    // 0x80085920: addiu       $t6, $v0, -0x31
    ctx->r14 = ADD32(ctx->r2, -0X31);
    // 0x80085924: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80085928: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x8008592C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80085930: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80085934: addiu       $t8, $v0, -0x18
    ctx->r24 = ADD32(ctx->r2, -0X18);
    // 0x80085938: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
    // 0x8008593C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80085940: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80085944: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80085948: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008594C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80085950: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80085954: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x80085958: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8008595C: jal         0x8007BF1C
    // 0x80085960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x80085960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80085964: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80085968: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008596C: addiu       $t4, $t3, -0x85
    ctx->r12 = ADD32(ctx->r11, -0X85);
    // 0x80085970: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80085974: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80085978: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008597C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80085980: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085984: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x80085988: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8008598C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80085990: jal         0x8009CA60
    // 0x80085994: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80085994: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    after_6:
    // 0x80085998: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8008599C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800859A0: addiu       $t2, $t8, -0x7D
    ctx->r10 = ADD32(ctx->r24, -0X7D);
    // 0x800859A4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800859A8: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x800859AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800859B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800859B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800859B8: swc1        $f6, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f6.u32l;
    // 0x800859BC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800859C0: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800859C4: jal         0x8009CA60
    // 0x800859C8: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x800859C8: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    after_7:
    // 0x800859CC: jal         0x8007BF1C
    // 0x800859D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800859D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800859D4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800859D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800859DC: addiu       $t5, $t6, -0x80
    ctx->r13 = ADD32(ctx->r14, -0X80);
    // 0x800859E0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800859E4: lw          $t7, -0x8A4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X8A4);
    // 0x800859E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800859EC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800859F0: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x800859F4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800859F8: jal         0x8009CA60
    // 0x800859FC: nop

    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x800859FC: nop

    after_9:
    // 0x80085A00: jal         0x80068508
    // 0x80085A04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x80085A04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80085A08: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_80085A0C:
    // 0x80085A0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085A10: beq         $t2, $zero, L_80085A50
    if (ctx->r10 == 0) {
        // 0x80085A14: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80085A50;
    }
    // 0x80085A14: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085A18: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80085A1C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80085A20: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80085A24: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80085A28: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80085A2C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80085A30: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80085A34: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80085A38: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80085A3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085A40: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80085A44: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x80085A48: jal         0x80078AB8
    // 0x80085A4C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80085A4C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_11:
L_80085A50:
    // 0x80085A50: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80085A54: nop

    // 0x80085A58: beq         $t5, $zero, L_80085AF4
    if (ctx->r13 == 0) {
        // 0x80085A5C: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_80085AF4;
    }
    // 0x80085A5C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80085A60: jal         0x800C42EC
    // 0x80085A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_12;
    // 0x80085A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80085A68: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80085A6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085A70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085A7C: jal         0x800C4384
    // 0x80085A80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80085A80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x80085A84: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085A88: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085A8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085A90: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085A94: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80085A98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085A9C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085AA0: addiu       $a1, $a1, 0x51
    ctx->r5 = ADD32(ctx->r5, 0X51);
    // 0x80085AA4: jal         0x800C4440
    // 0x80085AA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x80085AA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_14:
    // 0x80085AAC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80085AB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80085AB4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085AB8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80085ABC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085AC0: jal         0x800C4384
    // 0x80085AC4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80085AC4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_15:
    // 0x80085AC8: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085ACC: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085AD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085AD4: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085AD8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80085ADC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085AE0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085AE4: addiu       $a1, $a1, 0x4F
    ctx->r5 = ADD32(ctx->r5, 0X4F);
    // 0x80085AE8: jal         0x800C4440
    // 0x80085AEC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80085AEC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_16:
    // 0x80085AF0: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
L_80085AF4:
    // 0x80085AF4: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x80085AF8: beq         $t3, $zero, L_80085B8C
    if (ctx->r11 == 0) {
        // 0x80085AFC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80085B8C;
    }
    // 0x80085AFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80085B00: jal         0x800C42EC
    // 0x80085B04: addiu       $s0, $s0, 0x4F
    ctx->r16 = ADD32(ctx->r16, 0X4F);
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80085B04: addiu       $s0, $s0, 0x4F
    ctx->r16 = ADD32(ctx->r16, 0X4F);
    after_17:
    // 0x80085B08: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80085B0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80085B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085B18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085B1C: jal         0x800C4384
    // 0x80085B20: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80085B20: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x80085B24: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085B28: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085B2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085B30: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085B34: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085B38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085B3C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085B40: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x80085B44: jal         0x800C4440
    // 0x80085B48: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    draw_text(rdram, ctx);
        goto after_19;
    // 0x80085B48: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_19:
    // 0x80085B4C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80085B50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085B54: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085B58: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80085B5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085B60: jal         0x800C4384
    // 0x80085B64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_20;
    // 0x80085B64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_20:
    // 0x80085B68: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085B6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085B70: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085B74: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80085B78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085B7C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80085B80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80085B84: jal         0x800C4440
    // 0x80085B88: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80085B88: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    after_21:
L_80085B8C:
    // 0x80085B8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085B90: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80085B94: jr          $ra
    // 0x80085B98: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80085B98: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void material_set_blinking_lights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BA5C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007BA60: beq         $a3, $zero, L_8007BA98
    if (ctx->r7 == 0) {
        // 0x8007BA64: sw          $a2, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r6;
            goto L_8007BA98;
    }
    // 0x8007BA64: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8007BA68: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007BA6C: nop

    // 0x8007BA70: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007BA74: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007BA78: beq         $at, $zero, L_8007BA98
    if (ctx->r1 == 0) {
        // 0x8007BA7C: nop
    
            goto L_8007BA98;
    }
    // 0x8007BA7C: nop

    // 0x8007BA80: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007BA84: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007BA88: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BA8C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007BA90: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007BA94: nop

L_8007BA98:
    // 0x8007BA98: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8007BA9C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8007BAA0: bne         $t7, $at, L_8007BC70
    if (ctx->r15 != ctx->r1) {
        // 0x8007BAA4: lui         $a2, 0xB700
        ctx->r6 = S32(0XB700 << 16);
            goto L_8007BC70;
    }
    // 0x8007BAA4: lui         $a2, 0xB700
    ctx->r6 = S32(0XB700 << 16);
    // 0x8007BAA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BAAC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BAB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BAB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BAB8: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BABC: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007BAC0: addiu       $t6, $t9, 0x20
    ctx->r14 = ADD32(ctx->r25, 0X20);
    // 0x8007BAC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BAC8: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BACC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BAD0: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007BAD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BAD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BADC: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BAE0: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007BAE4: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BAE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BAEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BAF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BAF4: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007BAF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BAFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BB00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BB04: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BB08: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB0C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007BB10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BB14: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BB18: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007BB1C: ori         $t8, $t8, 0xF080
    ctx->r24 = ctx->r24 | 0XF080;
    // 0x8007BB20: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BB24: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007BB28: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB2C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007BB30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BB34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BB38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BB3C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BB40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB44: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x8007BB48: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8007BB4C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BB50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BB54: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8007BB58: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x8007BB5C: ori         $t7, $t7, 0x2100
    ctx->r15 = ctx->r15 | 0X2100;
    // 0x8007BB60: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BB64: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8007BB68: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8007BB6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB70: lui         $t9, 0x10F
    ctx->r25 = S32(0X10F << 16);
    // 0x8007BB74: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8007BB78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BB7C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BB80: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BB84: ori         $t9, $t9, 0xC03C
    ctx->r25 = ctx->r25 | 0XC03C;
    // 0x8007BB88: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007BB8C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8007BB90: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007BB94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB98: addu        $t6, $a1, $t1
    ctx->r14 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BB9C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BBA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BBA4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BBA8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007BBAC: addiu       $t9, $t6, 0x820
    ctx->r25 = ADD32(ctx->r14, 0X820);
    // 0x8007BBB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BBB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBB8: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8007BBBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BBC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BBC4: ori         $t6, $t6, 0x60
    ctx->r14 = ctx->r14 | 0X60;
    // 0x8007BBC8: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BBCC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BBD0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BBD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBD8: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8007BBDC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BBE0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BBE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BBE8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BBEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBF0: ori         $t6, $t6, 0xF080
    ctx->r14 = ctx->r14 | 0XF080;
    // 0x8007BBF4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007BBF8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BBFC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BC00: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BC04: nop

    // 0x8007BC08: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8007BC0C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007BC10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC14: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BC18: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007BC1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BC20: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BC24: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007BC28: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007BC2C: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007BC30: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007BC34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC38: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BC3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BC40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BC44: ori         $t8, $t8, 0x2000
    ctx->r24 = ctx->r24 | 0X2000;
    // 0x8007BC48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BC4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BC50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC54: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x8007BC58: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BC5C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BC60: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x8007BC64: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BC68: b           L_8007BE50
    // 0x8007BC6C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007BE50;
    // 0x8007BC6C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007BC70:
    // 0x8007BC70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC74: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BC78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BC7C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BC80: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BC84: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007BC88: addiu       $t7, $t9, 0x20
    ctx->r15 = ADD32(ctx->r25, 0X20);
    // 0x8007BC8C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BC90: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BC94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC98: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007BC9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BCA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BCA4: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BCA8: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007BCAC: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x8007BCB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BCB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BCB8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCBC: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007BCC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BCC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BCC8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BCCC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BCD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCD4: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007BCD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BCDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BCE0: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007BCE4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007BCE8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007BCEC: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007BCF0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BCF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCF8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007BCFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007BD00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BD04: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BD08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BD0C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BD10: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007BD14: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007BD18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD1C: lui         $t7, 0x101
    ctx->r15 = S32(0X101 << 16);
    // 0x8007BD20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007BD24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BD28: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BD2C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007BD30: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x8007BD34: ori         $t8, $t8, 0x1100
    ctx->r24 = ctx->r24 | 0X1100;
    // 0x8007BD38: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007BD3C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007BD40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD44: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007BD48: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007BD4C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BD50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BD54: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8007BD58: lui         $t7, 0x107
    ctx->r15 = S32(0X107 << 16);
    // 0x8007BD5C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8007BD60: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8007BD64: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007BD68: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007BD6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD70: addu        $t8, $a1, $t1
    ctx->r24 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BD74: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BD78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BD7C: addiu       $t7, $t8, 0x820
    ctx->r15 = ADD32(ctx->r24, 0X820);
    // 0x8007BD80: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BD84: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BD88: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD8C: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8007BD90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BD94: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BD98: ori         $t8, $t8, 0x4050
    ctx->r24 = ctx->r24 | 0X4050;
    // 0x8007BD9C: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007BDA0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BDA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BDA8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BDAC: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007BDB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BDB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BDB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BDBC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BDC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BDC4: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007BDC8: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8007BDCC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BDD0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BDD4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007BDD8: nop

    // 0x8007BDDC: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8007BDE0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007BDE4: nop

    // 0x8007BDE8: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8007BDEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BDF0: nop

    // 0x8007BDF4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8007BDF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BDFC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BE00: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007BE04: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x8007BE08: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8007BE0C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007BE10: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8007BE14: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8007BE18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE1C: ori         $t6, $t6, 0x4050
    ctx->r14 = ctx->r14 | 0X4050;
    // 0x8007BE20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BE24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BE28: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x8007BE2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BE30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BE34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE38: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x8007BE3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BE40: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BE44: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007BE48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BE4C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007BE50:
    // 0x8007BE50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007BE58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BE5C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BE60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BE64: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BE68: sw          $zero, 0x637C($at)
    MEM_W(0X637C, ctx->r1) = 0;
    // 0x8007BE6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE70: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x8007BE74: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BE78: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BE7C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007BE80: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x8007BE84: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8007BE88: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BE8C: beq         $t9, $zero, L_8007BEB0
    if (ctx->r25 == 0) {
        // 0x8007BE90: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_8007BEB0;
    }
    // 0x8007BE90: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007BE94: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007BE9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BEA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BEA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BEA8: b           L_8007BECC
    // 0x8007BEAC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8007BECC;
    // 0x8007BEAC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_8007BEB0:
    // 0x8007BEB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BEB4: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007BEB8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BEBC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BEC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BEC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BEC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007BECC:
    // 0x8007BECC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007BED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007BED4: sh          $t8, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r24;
    // 0x8007BED8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007BEDC: sw          $zero, 0x6374($at)
    MEM_W(0X6374, ctx->r1) = 0;
    // 0x8007BEE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BEE4: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007BEE8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BEEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BEF0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BEF4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007BEF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007BEFC: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8007BF00: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x8007BF04: addiu       $t7, $t7, -0xE58
    ctx->r15 = ADD32(ctx->r15, -0XE58);
    // 0x8007BF08: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BF0C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BF10: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8007BF14: jr          $ra
    // 0x8007BF18: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    return;
    // 0x8007BF18: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void minimap_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB1AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AB1B0: lbu         $t6, 0x718B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X718B);
    // 0x800AB1B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1B8: sb          $t6, 0x6CD0($at)
    MEM_B(0X6CD0, ctx->r1) = ctx->r14;
    // 0x800AB1BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1C0: jr          $ra
    // 0x800AB1C4: sb          $a0, 0x6CD3($at)
    MEM_B(0X6CD3, ctx->r1) = ctx->r4;
    return;
    // 0x800AB1C4: sb          $a0, 0x6CD3($at)
    MEM_B(0X6CD3, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_inside_segment_count_xyz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A138: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002A13C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A140: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A144: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A148: lh          $s0, 0x2A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X2A);
    // 0x8002A14C: lh          $s1, 0x2E($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2E);
    // 0x8002A150: lh          $s2, 0x32($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X32);
    // 0x8002A154: lw          $t0, -0x36E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X36E8);
    // 0x8002A158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002A15C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002A160: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002A164: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002A168: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8002A16C: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8002A170: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002A174: addiu       $a1, $t7, -0x4
    ctx->r5 = ADD32(ctx->r15, -0X4);
    // 0x8002A178: addiu       $a2, $t9, -0x4
    ctx->r6 = ADD32(ctx->r25, -0X4);
    // 0x8002A17C: addiu       $a3, $t4, -0x4
    ctx->r7 = ADD32(ctx->r12, -0X4);
    // 0x8002A180: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A184: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002A188: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002A18C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A190: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8002A194: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002A198: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8002A19C: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002A1A0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002A1A4: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8002A1A8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002A1AC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8002A1B0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002A1B4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A1B8: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002A1BC: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002A1C0: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002A1C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A1C8: blez        $t1, L_8002A280
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002A1CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002A280;
    }
    // 0x8002A1CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A1D0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002A1D4:
    // 0x8002A1D4: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8002A1D8: nop

    // 0x8002A1DC: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    // 0x8002A1E0: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8002A1E4: nop

    // 0x8002A1E8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002A1EC: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A1F0: nop
    
            goto L_8002A270;
    }
    // 0x8002A1F0: nop

    // 0x8002A1F4: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x8002A1F8: nop

    // 0x8002A1FC: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002A200: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A204: nop
    
            goto L_8002A270;
    }
    // 0x8002A204: nop

    // 0x8002A208: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x8002A20C: nop

    // 0x8002A210: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A214: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A218: nop
    
            goto L_8002A270;
    }
    // 0x8002A218: nop

    // 0x8002A21C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8002A220: nop

    // 0x8002A224: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002A228: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A22C: nop
    
            goto L_8002A270;
    }
    // 0x8002A22C: nop

    // 0x8002A230: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x8002A234: nop

    // 0x8002A238: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002A23C: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A240: nop
    
            goto L_8002A270;
    }
    // 0x8002A240: nop

    // 0x8002A244: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8002A248: nop

    // 0x8002A24C: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002A250: bne         $at, $zero, L_8002A270
    if (ctx->r1 != 0) {
        // 0x8002A254: nop
    
            goto L_8002A270;
    }
    // 0x8002A254: nop

    // 0x8002A258: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8002A25C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A260: lw          $t0, -0x36E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X36E8);
    // 0x8002A264: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A268: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A26C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8002A270:
    // 0x8002A270: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A274: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002A278: bne         $at, $zero, L_8002A1D4
    if (ctx->r1 != 0) {
        // 0x8002A27C: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002A1D4;
    }
    // 0x8002A27C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_8002A280:
    // 0x8002A280: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A284: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A288: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002A28C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002A290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A294: jr          $ra
    // 0x8002A298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A298: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void render_global_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C510C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5110: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5114: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5118: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C511C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C5120: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C5128: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C512C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5130: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C5134: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5138: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C513C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C5140: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5144: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800C5148: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800C514C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C5150: jal         0x800C5168
    // 0x800C5154: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_0;
    // 0x800C5154: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800C5158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C515C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C5160: jr          $ra
    // 0x800C5164: nop

    return;
    // 0x800C5164: nop

;}
RECOMP_FUNC void fb_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A7E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007A7EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A7F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007A7F4: addiu       $t6, $t6, 0x62C0
    ctx->r14 = ADD32(ctx->r14, 0X62C0);
    // 0x8007A7F8: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8007A7FC: addu        $s0, $a1, $t6
    ctx->r16 = ADD32(ctx->r5, ctx->r14);
    // 0x8007A800: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8007A804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A808: beq         $a2, $zero, L_8007A82C
    if (ctx->r6 == 0) {
        // 0x8007A80C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8007A82C;
    }
    // 0x8007A80C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007A810: jal         0x80071538
    // 0x8007A814: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    mempool_locked_unset(rdram, ctx);
        goto after_0;
    // 0x8007A814: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007A818: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007A81C: jal         0x80071140
    // 0x8007A820: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007A820: nop

    after_1:
    // 0x8007A824: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A828: nop

L_8007A82C:
    // 0x8007A82C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A830: lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X62CC);
    // 0x8007A834: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007A838: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x8007A83C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8007A840: addiu       $t0, $t0, -0x1884
    ctx->r8 = ADD32(ctx->r8, -0X1884);
    // 0x8007A844: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8007A848: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007A84C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007A850: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8007A854: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8007A858: addiu       $t7, $t7, 0x62B0
    ctx->r15 = ADD32(ctx->r15, 0X62B0);
    // 0x8007A85C: addiu       $t2, $t2, 0x62B8
    ctx->r10 = ADD32(ctx->r10, 0X62B8);
    // 0x8007A860: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x8007A864: addu        $a3, $a1, $t2
    ctx->r7 = ADD32(ctx->r5, ctx->r10);
    // 0x8007A868: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007A86C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x8007A870: bne         $at, $zero, L_8007A8D8
    if (ctx->r1 != 0) {
        // 0x8007A874: sw          $t3, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r11;
            goto L_8007A8D8;
    }
    // 0x8007A874: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8007A878: lui         $a0, 0x9
    ctx->r4 = S32(0X9 << 16);
    // 0x8007A87C: ori         $a0, $a0, 0x6030
    ctx->r4 = ctx->r4 | 0X6030;
    // 0x8007A880: jal         0x80070C9C
    // 0x8007A884: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8007A884: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007A888: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A88C: addiu       $v1, $v1, -0x1890
    ctx->r3 = ADD32(ctx->r3, -0X1890);
    // 0x8007A890: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007A894: addiu       $t4, $v0, 0x3F
    ctx->r12 = ADD32(ctx->r2, 0X3F);
    // 0x8007A898: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007A89C: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007A8A0: bne         $t6, $zero, L_8007A964
    if (ctx->r14 != 0) {
        // 0x8007A8A4: sw          $t5, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r13;
            goto L_8007A964;
    }
    // 0x8007A8A4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8007A8A8: lui         $a0, 0x9
    ctx->r4 = S32(0X9 << 16);
    // 0x8007A8AC: ori         $a0, $a0, 0x6030
    ctx->r4 = ctx->r4 | 0X6030;
    // 0x8007A8B0: jal         0x80070C9C
    // 0x8007A8B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007A8B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8007A8B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A8BC: addiu       $v1, $v1, -0x1890
    ctx->r3 = ADD32(ctx->r3, -0X1890);
    // 0x8007A8C0: addiu       $t8, $v0, 0x3F
    ctx->r24 = ADD32(ctx->r2, 0X3F);
    // 0x8007A8C4: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007A8C8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8007A8CC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007A8D0: b           L_8007A964
    // 0x8007A8D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8007A964;
    // 0x8007A8D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8007A8D8:
    // 0x8007A8D8: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8007A8DC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8007A8E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007A8E4: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A8E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8007A8EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8007A8F0: mflo        $a0
    ctx->r4 = lo;
    // 0x8007A8F4: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8007A8F8: jal         0x80070C9C
    // 0x8007A8FC: addiu       $a0, $t2, 0x30
    ctx->r4 = ADD32(ctx->r10, 0X30);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8007A8FC: addiu       $a0, $t2, 0x30
    ctx->r4 = ADD32(ctx->r10, 0X30);
    after_4:
    // 0x8007A900: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A904: addiu       $v1, $v1, -0x1890
    ctx->r3 = ADD32(ctx->r3, -0X1890);
    // 0x8007A908: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8007A90C: addiu       $t3, $v0, 0x3F
    ctx->r11 = ADD32(ctx->r2, 0X3F);
    // 0x8007A910: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007A914: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007A918: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007A91C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007A920: bne         $t5, $zero, L_8007A964
    if (ctx->r13 != 0) {
        // 0x8007A924: sw          $t4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r12;
            goto L_8007A964;
    }
    // 0x8007A924: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8007A928: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8007A92C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8007A930: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007A934: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A938: mflo        $a0
    ctx->r4 = lo;
    // 0x8007A93C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x8007A940: jal         0x80070C9C
    // 0x8007A944: addiu       $a0, $t8, 0x30
    ctx->r4 = ADD32(ctx->r24, 0X30);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8007A944: addiu       $a0, $t8, 0x30
    ctx->r4 = ADD32(ctx->r24, 0X30);
    after_5:
    // 0x8007A948: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007A94C: addiu       $v1, $v1, -0x1890
    ctx->r3 = ADD32(ctx->r3, -0X1890);
    // 0x8007A950: addiu       $t0, $v0, 0x3F
    ctx->r8 = ADD32(ctx->r2, 0X3F);
    // 0x8007A954: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007A958: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8007A95C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007A960: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8007A964:
    // 0x8007A964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A968: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007A96C: jr          $ra
    // 0x8007A970: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007A970: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
