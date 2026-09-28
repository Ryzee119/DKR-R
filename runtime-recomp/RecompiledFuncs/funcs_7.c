#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void racer_attack_handler_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048C84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048C88: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80048C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048C90: bne         $t6, $at, L_80048CA0
    if (ctx->r14 != ctx->r1) {
        // 0x80048C94: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80048CA0;
    }
    // 0x80048C94: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80048C98: b           L_80048CA8
    // 0x80048C9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80048CA8;
    // 0x80048C9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80048CA0:
    // 0x80048CA0: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x80048CA4: nop

L_80048CA8:
    // 0x80048CA8: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x80048CAC: nop

    // 0x80048CB0: beq         $v0, $zero, L_80048CC8
    if (ctx->r2 == 0) {
        // 0x80048CB4: nop
    
            goto L_80048CC8;
    }
    // 0x80048CB4: nop

    // 0x80048CB8: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x80048CBC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80048CC0: blez        $t7, L_80048CD0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80048CC4: nop
    
            goto L_80048CD0;
    }
    // 0x80048CC4: nop

L_80048CC8:
    // 0x80048CC8: b           L_80048E54
    // 0x80048CCC: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80048E54;
    // 0x80048CCC: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80048CD0:
    // 0x80048CD0: beq         $v0, $at, L_80048CF4
    if (ctx->r2 == ctx->r1) {
        // 0x80048CD4: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80048CF4;
    }
    // 0x80048CD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048CD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80048CDC: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x80048CE0: jal         0x800576E0
    // 0x80048CE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_0;
    // 0x80048CE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80048CE8: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x80048CEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80048CF0: nop

L_80048CF4:
    // 0x80048CF4: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80048CF8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80048CFC: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80048D00: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x80048D04: jal         0x800570B8
    // 0x80048D08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x80048D08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80048D0C: lb          $t8, 0x187($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X187);
    // 0x80048D10: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x80048D14: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80048D18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80048D1C: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80048D20: beq         $at, $zero, L_80048E50
    if (ctx->r1 == 0) {
        // 0x80048D24: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80048E50;
    }
    // 0x80048D24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80048D28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048D2C: addu        $at, $at, $t9
    gpr jr_addend_80048D38 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80048D30: lw          $t9, 0x646C($at)
    ctx->r25 = ADD32(ctx->r1, 0X646C);
    // 0x80048D34: nop

    // 0x80048D38: jr          $t9
    // 0x80048D3C: nop

    switch (jr_addend_80048D38 >> 2) {
        case 0: goto L_80048D40; break;
        case 1: goto L_80048D40; break;
        case 2: goto L_80048E50; break;
        case 3: goto L_80048DAC; break;
        case 4: goto L_80048E18; break;
        case 5: goto L_80048DB8; break;
        default: switch_error(__func__, 0x80048D38, 0x800E646C);
    }
    // 0x80048D3C: nop

L_80048D40:
    // 0x80048D40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80048D44: bne         $v1, $zero, L_80048D68
    if (ctx->r3 != 0) {
        // 0x80048D48: sb          $t0, 0x1F1($s0)
        MEM_B(0X1F1, ctx->r16) = ctx->r8;
            goto L_80048D68;
    }
    // 0x80048D48: sb          $t0, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r8;
    // 0x80048D4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048D50: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80048D54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048D58: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80048D5C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80048D60: b           L_80048E50
    // 0x80048D64: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
        goto L_80048E50;
    // 0x80048D64: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
L_80048D68:
    // 0x80048D68: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80048D6C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80048D70: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80048D74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048D78: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80048D7C: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80048D80: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80048D84: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80048D88: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80048D8C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80048D90: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80048D94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048D98: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x80048D9C: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80048DA0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80048DA4: b           L_80048E50
    // 0x80048DA8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_80048E50;
    // 0x80048DA8: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_80048DAC:
    // 0x80048DAC: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80048DB0: b           L_80048E50
    // 0x80048DB4: sb          $t1, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r9;
        goto L_80048E50;
    // 0x80048DB4: sb          $t1, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r9;
L_80048DB8:
    // 0x80048DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048DBC: lwc1        $f1, 0x6488($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6488);
    // 0x80048DC0: lwc1        $f0, 0x648C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X648C);
    // 0x80048DC4: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80048DC8: sh          $t2, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r10;
    // 0x80048DCC: lwc1        $f16, 0x1C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80048DD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80048DD4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80048DD8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80048DDC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80048DE0: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80048DE4: nop

    // 0x80048DE8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80048DEC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80048DF0: bc1f        L_80048DFC
    if (!c1cs) {
        // 0x80048DF4: swc1        $f6, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
            goto L_80048DFC;
    }
    // 0x80048DF4: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80048DF8: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
L_80048DFC:
    // 0x80048DFC: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80048E00: nop

    // 0x80048E04: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80048E08: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80048E0C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80048E10: b           L_80048E50
    // 0x80048E14: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
        goto L_80048E50;
    // 0x80048E14: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_80048E18:
    // 0x80048E18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80048E1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80048E20: sb          $t3, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r11;
    // 0x80048E24: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80048E28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048E2C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80048E30: lwc1        $f11, 0x6490($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6490);
    // 0x80048E34: lwc1        $f10, 0x6494($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6494);
    // 0x80048E38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80048E3C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80048E40: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    // 0x80048E44: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80048E48: jal         0x80057048
    // 0x80048E4C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x80048E4C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    after_2:
L_80048E50:
    // 0x80048E50: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80048E54:
    // 0x80048E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048E58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048E5C: jr          $ra
    // 0x80048E60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80048E60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_number_of_active_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C3C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C3CC: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8009C3D0: jr          $ra
    // 0x8009C3D4: nop

    return;
    // 0x8009C3D4: nop

;}
RECOMP_FUNC void transition_render_barndoor_vert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C14DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C14E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C14E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C14E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C14EC: jal         0x8007B3D0
    // 0x800C14F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C14F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C14F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C14F8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C14FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1500: addiu       $t8, $t8, 0x3648
    ctx->r24 = ADD32(ctx->r24, 0X3648);
    // 0x800C1504: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1508: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C150C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1510: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C1514: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1518: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C151C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1520: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C1524: addiu       $a3, $a3, 0x31D0
    ctx->r7 = ADD32(ctx->r7, 0X31D0);
    // 0x800C1528: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C152C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1530: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C1534: addiu       $t1, $t1, 0x31C0
    ctx->r9 = ADD32(ctx->r9, 0X31C0);
    // 0x800C1538: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C153C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1540: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C1544: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1548: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C154C: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1550: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C1554: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1558: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C155C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1560: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C1564: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1568: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C156C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1570: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C1574: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C1578: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C157C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C1580: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C1584: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C1588: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C158C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1590: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C1594: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C1598: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C159C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C15A0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C15A4: nop

    // 0x800C15A8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C15AC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C15B0: lw          $t6, 0x31C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31C8);
    // 0x800C15B4: nop

    // 0x800C15B8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C15BC: jal         0x8007B3D0
    // 0x800C15C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C15C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C15C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C15C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C15CC: jr          $ra
    // 0x800C15D0: nop

    return;
    // 0x800C15D0: nop

;}
RECOMP_FUNC void input_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A1C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006A1CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006A1D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A1D4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8006A1D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A1DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006A1E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006A1E4: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    // 0x8006A1E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8006A1EC: jal         0x800C8BB0
    // 0x8006A1F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A1F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006A1F4: bne         $v0, $zero, L_8006A36C
    if (ctx->r2 != 0) {
        // 0x8006A1F8: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006A36C;
    }
    // 0x8006A1F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A1FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A200: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A204: addiu       $v1, $v1, 0x1128
    ctx->r3 = ADD32(ctx->r3, 0X1128);
    // 0x8006A208: addiu       $v0, $v0, 0x1110
    ctx->r2 = ADD32(ctx->r2, 0X1110);
    // 0x8006A20C: addiu       $a2, $a2, 0x1128
    ctx->r6 = ADD32(ctx->r6, 0X1128);
L_8006A210:
    // 0x8006A210: lwl         $at, 0x0($v0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r2, 0X0);
    // 0x8006A214: lwr         $at, 0x3($v0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r2, 0X3);
    // 0x8006A218: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006A21C: swl         $at, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r1);
    // 0x8006A220: swr         $at, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r1);
    // 0x8006A224: lhu         $at, -0x2($v0)
    ctx->r1 = MEM_HU(ctx->r2, -0X2);
    // 0x8006A228: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8006A22C: sh          $at, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r1;
    // 0x8006A230: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8006A234: bne         $at, $zero, L_8006A210
    if (ctx->r1 != 0) {
        // 0x8006A238: nop
    
            goto L_8006A210;
    }
    // 0x8006A238: nop

    // 0x8006A23C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A240: jal         0x800CD0A4
    // 0x8006A244: addiu       $a0, $a0, 0x1110
    ctx->r4 = ADD32(ctx->r4, 0X1110);
    osContGetReadData_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A244: addiu       $a0, $a0, 0x1110
    ctx->r4 = ADD32(ctx->r4, 0X1110);
    after_1:
    // 0x8006A248: beq         $s2, $zero, L_8006A358
    if (ctx->r18 == 0) {
        // 0x8006A24C: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_8006A358;
    }
    // 0x8006A24C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8006A250: jal         0x8006EA90
    // 0x8006A254: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8006A254: nop

    after_2:
    // 0x8006A258: andi        $v1, $s2, 0x3
    ctx->r3 = ctx->r18 & 0X3;
    // 0x8006A25C: beq         $v1, $zero, L_8006A270
    if (ctx->r3 == 0) {
        // 0x8006A260: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_8006A270;
    }
    // 0x8006A260: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006A264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006A268: jal         0x800745D0
    // 0x8006A26C: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    read_eeprom_data(rdram, ctx);
        goto after_3;
    // 0x8006A26C: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_3:
L_8006A270:
    // 0x8006A270: andi        $t8, $s2, 0x8
    ctx->r24 = ctx->r18 & 0X8;
    // 0x8006A274: beq         $t8, $zero, L_8006A2AC
    if (ctx->r24 == 0) {
        // 0x8006A278: andi        $t9, $s2, 0x4
        ctx->r25 = ctx->r18 & 0X4;
            goto L_8006A2AC;
    }
    // 0x8006A278: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x8006A27C: jal         0x8009C490
    // 0x8006A280: nop

    get_all_save_files_ptr(rdram, ctx);
        goto after_4;
    // 0x8006A280: nop

    after_4:
    // 0x8006A284: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A288: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8006A28C:
    // 0x8006A28C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006A290: jal         0x80074204
    // 0x8006A294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    read_save_file(rdram, ctx);
        goto after_5;
    // 0x8006A294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006A298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006A29C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006A2A0: bne         $s0, $at, L_8006A28C
    if (ctx->r16 != ctx->r1) {
        // 0x8006A2A4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A28C;
    }
    // 0x8006A2A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A2A8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
L_8006A2AC:
    // 0x8006A2AC: beq         $t9, $zero, L_8006A2C4
    if (ctx->r25 == 0) {
        // 0x8006A2B0: sra         $a0, $s2, 8
        ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
            goto L_8006A2C4;
    }
    // 0x8006A2B0: sra         $a0, $s2, 8
    ctx->r4 = S32(SIGNED(ctx->r18) >> 8);
    // 0x8006A2B4: andi        $t4, $a0, 0x3
    ctx->r12 = ctx->r4 & 0X3;
    // 0x8006A2B8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A2BC: jal         0x80074204
    // 0x8006A2C0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    read_save_file(rdram, ctx);
        goto after_6;
    // 0x8006A2C0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_6:
L_8006A2C4:
    // 0x8006A2C4: andi        $v0, $s2, 0x30
    ctx->r2 = ctx->r18 & 0X30;
    // 0x8006A2C8: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006A2CC: beq         $t5, $zero, L_8006A2E4
    if (ctx->r13 == 0) {
        // 0x8006A2D0: andi        $t6, $s2, 0x40
        ctx->r14 = ctx->r18 & 0X40;
            goto L_8006A2E4;
    }
    // 0x8006A2D0: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
    // 0x8006A2D4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A2D8: jal         0x800746F0
    // 0x8006A2DC: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    write_eeprom_data(rdram, ctx);
        goto after_7;
    // 0x8006A2DC: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_7:
    // 0x8006A2E0: andi        $t6, $s2, 0x40
    ctx->r14 = ctx->r18 & 0X40;
L_8006A2E4:
    // 0x8006A2E4: beq         $t6, $zero, L_8006A2FC
    if (ctx->r14 == 0) {
        // 0x8006A2E8: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A2FC;
    }
    // 0x8006A2E8: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A2EC: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x8006A2F0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A2F4: jal         0x800744DC
    // 0x8006A2F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    write_save_data(rdram, ctx);
        goto after_8;
    // 0x8006A2F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_8:
L_8006A2FC:
    // 0x8006A2FC: andi        $t8, $s2, 0x80
    ctx->r24 = ctx->r18 & 0X80;
    // 0x8006A300: beq         $t8, $zero, L_8006A318
    if (ctx->r24 == 0) {
        // 0x8006A304: sra         $a0, $s2, 10
        ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
            goto L_8006A318;
    }
    // 0x8006A304: sra         $a0, $s2, 10
    ctx->r4 = S32(SIGNED(ctx->r18) >> 10);
    // 0x8006A308: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x8006A30C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A310: jal         0x8007431C
    // 0x8006A314: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    erase_save_file(rdram, ctx);
        goto after_9;
    // 0x8006A314: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
L_8006A318:
    // 0x8006A318: andi        $t4, $s2, 0x100
    ctx->r12 = ctx->r18 & 0X100;
    // 0x8006A31C: beq         $t4, $zero, L_8006A338
    if (ctx->r12 == 0) {
        // 0x8006A320: andi        $t5, $s2, 0x200
        ctx->r13 = ctx->r18 & 0X200;
            goto L_8006A338;
    }
    // 0x8006A320: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
    // 0x8006A324: jal         0x8009EA6C
    // 0x8006A328: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_10;
    // 0x8006A328: nop

    after_10:
    // 0x8006A32C: jal         0x80074874
    // 0x8006A330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    read_eeprom_settings(rdram, ctx);
        goto after_11;
    // 0x8006A330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006A334: andi        $t5, $s2, 0x200
    ctx->r13 = ctx->r18 & 0X200;
L_8006A338:
    // 0x8006A338: beq         $t5, $zero, L_8006A354
    if (ctx->r13 == 0) {
        // 0x8006A33C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8006A354;
    }
    // 0x8006A33C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006A340: jal         0x8009EA6C
    // 0x8006A344: nop

    get_eeprom_settings_pointer(rdram, ctx);
        goto after_12;
    // 0x8006A344: nop

    after_12:
    // 0x8006A348: jal         0x8007497C
    // 0x8006A34C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    write_eeprom_settings(rdram, ctx);
        goto after_13;
    // 0x8006A34C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8006A350: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8006A354:
    // 0x8006A354: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_8006A358:
    // 0x8006A358: jal         0x80072718
    // 0x8006A35C: nop

    rumble_update(rdram, ctx);
        goto after_14;
    // 0x8006A35C: nop

    after_14:
    extern void dkr_netplay_resolve_authored_input_frame(uint8_t*, recomp_context*); dkr_netplay_resolve_authored_input_frame(rdram, ctx);
    // 0x8006A360: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A364: jal         0x800CCFE0
    // 0x8006A368: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_15;
    // 0x8006A368: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    after_15:
L_8006A36C:
    // 0x8006A36C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006A370: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8006A374: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A378: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A37C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A380: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006A384: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006A388: lhu         $t1, -0x2CFC($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2CFC);
    // 0x8006A38C: lw          $t2, -0x2D00($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D00);
    // 0x8006A390: addiu       $t3, $t3, 0x1150
    ctx->r11 = ADD32(ctx->r11, 0X1150);
    // 0x8006A394: addiu       $a3, $a3, 0x1148
    ctx->r7 = ADD32(ctx->r7, 0X1148);
    // 0x8006A398: addiu       $t0, $t0, 0x1140
    ctx->r8 = ADD32(ctx->r8, 0X1140);
    // 0x8006A39C: addiu       $v0, $v0, 0x1110
    ctx->r2 = ADD32(ctx->r2, 0X1110);
    // 0x8006A3A0: addiu       $a2, $a2, 0x1128
    ctx->r6 = ADD32(ctx->r6, 0X1128);
L_8006A3A4:
    // 0x8006A3A4: beq         $t2, $zero, L_8006A3B0
    if (ctx->r10 == 0) {
        // 0x8006A3A8: nop
    
            goto L_8006A3B0;
    }
    // 0x8006A3A8: nop

    // 0x8006A3AC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8006A3B0:
    // 0x8006A3B0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8006A3B4: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8006A3B8: nop

    // 0x8006A3BC: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A3C0: and         $t6, $v1, $a1
    ctx->r14 = ctx->r3 & ctx->r5;
    // 0x8006A3C4: and         $t8, $a0, $a1
    ctx->r24 = ctx->r4 & ctx->r5;
    // 0x8006A3C8: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A3CC: and         $t9, $t8, $t1
    ctx->r25 = ctx->r24 & ctx->r9;
    // 0x8006A3D0: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006A3D4: beq         $t2, $zero, L_8006A3E0
    if (ctx->r10 == 0) {
        // 0x8006A3D8: sh          $t9, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r25;
            goto L_8006A3E0;
    }
    // 0x8006A3D8: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8006A3DC: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_8006A3E0:
    // 0x8006A3E0: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8006A3E4: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x8006A3E8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8006A3EC: xor         $a1, $v1, $a0
    ctx->r5 = ctx->r3 ^ ctx->r4;
    // 0x8006A3F0: and         $t4, $v1, $a1
    ctx->r12 = ctx->r3 & ctx->r5;
    // 0x8006A3F4: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8006A3F8: and         $t7, $t6, $t1
    ctx->r15 = ctx->r14 & ctx->r9;
    // 0x8006A3FC: and         $t5, $t4, $t1
    ctx->r13 = ctx->r12 & ctx->r9;
    // 0x8006A400: sh          $t5, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r13;
    // 0x8006A404: sh          $t7, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r15;
    // 0x8006A408: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8006A40C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8006A410: bne         $a3, $t3, L_8006A3A4
    if (ctx->r7 != ctx->r11) {
        // 0x8006A414: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8006A3A4;
    }
    // 0x8006A414: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8006A418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A41C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8006A420: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A424: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A428: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A42C: jr          $ra
    // 0x8006A430: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006A430: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void load_sprite_info(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C8E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C8E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C8E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C8EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C8F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007C8F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007C8F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007C8FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007C900: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007C904: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007C908: bltz        $a0, L_8007C928
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C90C: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8007C928;
    }
    // 0x8007C90C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007C910: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C914: lw          $t6, 0x6354($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6354);
    // 0x8007C918: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C91C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C920: bne         $at, $zero, L_8007C94C
    if (ctx->r1 != 0) {
        // 0x8007C924: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_8007C94C;
    }
    // 0x8007C924: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_8007C928:
    // 0x8007C928: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007C92C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C930: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007C934: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8007C938: nop

    // 0x8007C93C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007C940: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007C944: b           L_8007CA48
    // 0x8007C948: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_8007CA48;
    // 0x8007C948: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8007C94C:
    // 0x8007C94C: lw          $t0, 0x6348($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6348);
    // 0x8007C950: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007C954: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8007C958: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C95C: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8007C960: lw          $s3, 0x6350($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X6350);
    // 0x8007C964: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007C968: subu        $a3, $t2, $a2
    ctx->r7 = SUB32(ctx->r10, ctx->r6);
    // 0x8007C96C: jal         0x80076E68
    // 0x8007C970: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007C970: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x8007C974: lbu         $t3, 0xC($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC);
    // 0x8007C978: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8007C97C: jal         0x8007AE74
    // 0x8007C980: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007C980: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8007C984: beq         $v0, $zero, L_8007C928
    if (ctx->r2 == 0) {
        // 0x8007C988: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8007C928;
    }
    // 0x8007C988: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007C98C: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x8007C990: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8007C994: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8007C998: jal         0x8007B2BC
    // 0x8007C99C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x8007C99C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_2:
    // 0x8007C9A0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8007C9A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8007C9A8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007C9AC: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007C9B0: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x8007C9B4: blez        $v1, L_8007CA20
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007C9B8: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_8007CA20;
    }
    // 0x8007C9B8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007C9BC:
    // 0x8007C9BC: lbu         $s0, 0xC($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0XC);
    // 0x8007C9C0: lbu         $t8, 0xD($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XD);
    // 0x8007C9C4: nop

    // 0x8007C9C8: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007C9CC: beq         $at, $zero, L_8007CA0C
    if (ctx->r1 == 0) {
        // 0x8007C9D0: nop
    
            goto L_8007CA0C;
    }
    // 0x8007C9D0: nop

L_8007C9D4:
    // 0x8007C9D4: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8007C9D8: jal         0x8007C57C
    // 0x8007C9DC: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    tex_asset_size(rdram, ctx);
        goto after_3;
    // 0x8007C9DC: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_3:
    // 0x8007C9E0: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8007C9E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C9E8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8007C9EC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8007C9F0: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x8007C9F4: nop

    // 0x8007C9F8: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007C9FC: bne         $at, $zero, L_8007C9D4
    if (ctx->r1 != 0) {
        // 0x8007CA00: nop
    
            goto L_8007C9D4;
    }
    // 0x8007CA00: nop

    // 0x8007CA04: lh          $v1, 0x2($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X2);
    // 0x8007CA08: nop

L_8007CA0C:
    // 0x8007CA0C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CA10: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007CA14: bne         $at, $zero, L_8007C9BC
    if (ctx->r1 != 0) {
        // 0x8007CA18: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007C9BC;
    }
    // 0x8007CA18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007CA1C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_8007CA20:
    // 0x8007CA20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CA24: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x8007CA28: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8007CA2C: lh          $t4, 0x4($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X4);
    // 0x8007CA30: nop

    // 0x8007CA34: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007CA38: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007CA3C: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x8007CA40: nop

    // 0x8007CA44: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_8007CA48:
    // 0x8007CA48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CA4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CA50: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CA54: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CA58: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CA5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CA60: jr          $ra
    // 0x8007CA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007CA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void objFreeAssets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F64C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F650: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F654: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000F658: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000F65C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F660: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F664: bne         $a2, $zero, L_8000F6B0
    if (ctx->r6 != 0) {
        // 0x8000F668: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000F6B0;
    }
    // 0x8000F668: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F66C: blez        $a1, L_8000F73C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000F670: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F670: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F674: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F678:
    // 0x8000F678: lw          $t6, 0x68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X68);
    // 0x8000F67C: nop

    // 0x8000F680: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F684: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000F688: nop

    // 0x8000F68C: beq         $v0, $zero, L_8000F69C
    if (ctx->r2 == 0) {
        // 0x8000F690: nop
    
            goto L_8000F69C;
    }
    // 0x8000F690: nop

    // 0x8000F694: jal         0x8005FF40
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_0;
    // 0x8000F698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
L_8000F69C:
    // 0x8000F69C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6A0: bne         $s1, $s2, L_8000F678
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F678;
    }
    // 0x8000F6A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6A8: b           L_8000F740
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F6B0:
    // 0x8000F6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000F6B4: bne         $a2, $at, L_8000F700
    if (ctx->r6 != ctx->r1) {
        // 0x8000F6B8: nop
    
            goto L_8000F700;
    }
    // 0x8000F6B8: nop

    // 0x8000F6BC: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F6C0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F6C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F6C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F6C8:
    // 0x8000F6C8: lw          $t8, 0x68($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X68);
    // 0x8000F6CC: nop

    // 0x8000F6D0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8000F6D4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F6D8: nop

    // 0x8000F6DC: beq         $v0, $zero, L_8000F6EC
    if (ctx->r2 == 0) {
        // 0x8000F6E0: nop
    
            goto L_8000F6EC;
    }
    // 0x8000F6E0: nop

    // 0x8000F6E4: jal         0x8007B2BC
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x8000F6E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_8000F6EC:
    // 0x8000F6EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F6F0: bne         $s1, $s2, L_8000F6C8
    if (ctx->r17 != ctx->r18) {
        // 0x8000F6F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F6C8;
    }
    // 0x8000F6F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F6F8: b           L_8000F740
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8000F740;
    // 0x8000F6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F700:
    // 0x8000F700: blez        $s2, L_8000F73C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000F704: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000F73C;
    }
    // 0x8000F704: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000F708: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000F70C:
    // 0x8000F70C: lw          $t0, 0x68($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X68);
    // 0x8000F710: nop

    // 0x8000F714: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8000F718: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8000F71C: nop

    // 0x8000F720: beq         $v0, $zero, L_8000F730
    if (ctx->r2 == 0) {
        // 0x8000F724: nop
    
            goto L_8000F730;
    }
    // 0x8000F724: nop

    // 0x8000F728: jal         0x8007CCB0
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000F72C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_8000F730:
    // 0x8000F730: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000F734: bne         $s1, $s2, L_8000F70C
    if (ctx->r17 != ctx->r18) {
        // 0x8000F738: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F70C;
    }
    // 0x8000F738: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F73C:
    // 0x8000F73C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000F740:
    // 0x8000F740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F748: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F74C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F750: jr          $ra
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000F754: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mempool_slot_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007164C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80071650: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071654: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071658: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x8007165C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80071660: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80071664: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80071668: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8007166C: mflo        $t8
    ctx->r24 = lo;
    // 0x80071670: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    // 0x80071674: lh          $a2, 0xC($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XC);
    // 0x80071678: lh          $t0, 0xA($a3)
    ctx->r8 = MEM_H(ctx->r7, 0XA);
    // 0x8007167C: beq         $a2, $t3, L_800716F4
    if (ctx->r6 == ctx->r11) {
        // 0x80071680: sh          $zero, 0x8($a3)
        MEM_H(0X8, ctx->r7) = 0;
            goto L_800716F4;
    }
    // 0x80071680: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x80071684: multu       $a2, $t2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071688: mflo        $t9
    ctx->r25 = lo;
    // 0x8007168C: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x80071690: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x80071694: nop

    // 0x80071698: bne         $t4, $zero, L_800716F4
    if (ctx->r12 != 0) {
        // 0x8007169C: nop
    
            goto L_800716F4;
    }
    // 0x8007169C: nop

    // 0x800716A0: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x800716A4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800716A8: nop

    // 0x800716AC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800716B0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800716B4: lh          $t1, 0xC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XC);
    // 0x800716B8: nop

    // 0x800716BC: beq         $t1, $t3, L_800716D4
    if (ctx->r9 == ctx->r11) {
        // 0x800716C0: sh          $t1, 0xC($a3)
        MEM_H(0XC, ctx->r7) = ctx->r9;
            goto L_800716D4;
    }
    // 0x800716C0: sh          $t1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r9;
    // 0x800716C4: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800716C8: mflo        $t8
    ctx->r24 = lo;
    // 0x800716CC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800716D0: sh          $a1, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r5;
L_800716D4:
    // 0x800716D4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800716D8: nop

    // 0x800716DC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800716E0: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800716E4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800716E8: mflo        $t7
    ctx->r15 = lo;
    // 0x800716EC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800716F0: sh          $a2, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r6;
L_800716F4:
    // 0x800716F4: beq         $t0, $t3, L_8007176C
    if (ctx->r8 == ctx->r11) {
        // 0x800716F8: nop
    
            goto L_8007176C;
    }
    // 0x800716F8: nop

    // 0x800716FC: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071700: mflo        $t9
    ctx->r25 = lo;
    // 0x80071704: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x80071708: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x8007170C: nop

    // 0x80071710: bne         $t4, $zero, L_8007176C
    if (ctx->r12 != 0) {
        // 0x80071714: nop
    
            goto L_8007176C;
    }
    // 0x80071714: nop

    // 0x80071718: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007171C: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80071720: nop

    // 0x80071724: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80071728: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007172C: lh          $t1, 0xC($a3)
    ctx->r9 = MEM_H(ctx->r7, 0XC);
    // 0x80071730: nop

    // 0x80071734: beq         $t1, $t3, L_8007174C
    if (ctx->r9 == ctx->r11) {
        // 0x80071738: sh          $t1, 0xC($a0)
        MEM_H(0XC, ctx->r4) = ctx->r9;
            goto L_8007174C;
    }
    // 0x80071738: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x8007173C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071740: mflo        $t8
    ctx->r24 = lo;
    // 0x80071744: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80071748: sh          $t0, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r8;
L_8007174C:
    // 0x8007174C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80071750: nop

    // 0x80071754: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80071758: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007175C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80071760: mflo        $t7
    ctx->r15 = lo;
    // 0x80071764: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80071768: sh          $a1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r5;
L_8007176C:
    // 0x8007176C: jr          $ra
    // 0x80071770: nop

    return;
    // 0x80071770: nop

;}
RECOMP_FUNC void s32_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C580C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C5810: bgez        $a1, L_800C5828
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5814: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C5828;
    }
    // 0x800C5814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C5818: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x800C581C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800C5820: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5824: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800C5828:
    // 0x800C5828: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C582C: lw          $a3, 0x36EC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X36EC);
    // 0x800C5830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C5834: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5838: bne         $at, $zero, L_800C5890
    if (ctx->r1 != 0) {
        // 0x800C583C: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5890;
    }
    // 0x800C583C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5840: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5844: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5848: bne         $a3, $zero, L_800C5854
    if (ctx->r7 != 0) {
        // 0x800C584C: nop
    
            goto L_800C5854;
    }
    // 0x800C584C: nop

    // 0x800C5850: break       7
    do_break(2148292688);
L_800C5854:
    // 0x800C5854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5858: bne         $a3, $at, L_800C586C
    if (ctx->r7 != ctx->r1) {
        // 0x800C585C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C586C;
    }
    // 0x800C585C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5860: bne         $a1, $at, L_800C586C
    if (ctx->r5 != ctx->r1) {
        // 0x800C5864: nop
    
            goto L_800C586C;
    }
    // 0x800C5864: nop

    // 0x800C5868: break       6
    do_break(2148292712);
L_800C586C:
    // 0x800C586C: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5870: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5874: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5878: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C587C: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5880: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5884: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5888: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C588C: nop

L_800C5890:
    // 0x800C5890: beq         $v1, $zero, L_800C58A0
    if (ctx->r3 == 0) {
        // 0x800C5894: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_800C58A0;
    }
    // 0x800C5894: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C5898: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C589C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C58A0:
    // 0x800C58A0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C58A4: addiu       $t5, $t5, 0x36EC
    ctx->r13 = ADD32(ctx->r13, 0X36EC);
    // 0x800C58A8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C58AC: addiu       $t4, $t4, 0x3710
    ctx->r12 = ADD32(ctx->r12, 0X3710);
    // 0x800C58B0: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
L_800C58B4:
    // 0x800C58B4: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800C58B8: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C58BC: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C58C0: bne         $at, $zero, L_800C5918
    if (ctx->r1 != 0) {
        // 0x800C58C4: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800C5918;
    }
    // 0x800C58C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C58C8: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800C58CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C58D0: bne         $a2, $zero, L_800C58DC
    if (ctx->r6 != 0) {
        // 0x800C58D4: nop
    
            goto L_800C58DC;
    }
    // 0x800C58D4: nop

    // 0x800C58D8: break       7
    do_break(2148292824);
L_800C58DC:
    // 0x800C58DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C58E0: bne         $a2, $at, L_800C58F4
    if (ctx->r6 != ctx->r1) {
        // 0x800C58E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C58F4;
    }
    // 0x800C58E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C58E8: bne         $a1, $at, L_800C58F4
    if (ctx->r5 != ctx->r1) {
        // 0x800C58EC: nop
    
            goto L_800C58F4;
    }
    // 0x800C58EC: nop

    // 0x800C58F0: break       6
    do_break(2148292848);
L_800C58F4:
    // 0x800C58F4: mflo        $a3
    ctx->r7 = lo;
    // 0x800C58F8: addiu       $t1, $a3, 0x30
    ctx->r9 = ADD32(ctx->r7, 0X30);
    // 0x800C58FC: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x800C5900: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5904: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x800C5908: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x800C590C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C5910: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x800C5914: nop

L_800C5918:
    // 0x800C5918: beq         $v1, $zero, L_800C5928
    if (ctx->r3 == 0) {
        // 0x800C591C: nop
    
            goto L_800C5928;
    }
    // 0x800C591C: nop

    // 0x800C5920: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5924: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5928:
    // 0x800C5928: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C592C: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5930: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5934: bne         $at, $zero, L_800C598C
    if (ctx->r1 != 0) {
        // 0x800C5938: nop
    
            goto L_800C598C;
    }
    // 0x800C5938: nop

    // 0x800C593C: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5940: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5944: bne         $a3, $zero, L_800C5950
    if (ctx->r7 != 0) {
        // 0x800C5948: nop
    
            goto L_800C5950;
    }
    // 0x800C5948: nop

    // 0x800C594C: break       7
    do_break(2148292940);
L_800C5950:
    // 0x800C5950: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5954: bne         $a3, $at, L_800C5968
    if (ctx->r7 != ctx->r1) {
        // 0x800C5958: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5968;
    }
    // 0x800C5958: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C595C: bne         $a1, $at, L_800C5968
    if (ctx->r5 != ctx->r1) {
        // 0x800C5960: nop
    
            goto L_800C5968;
    }
    // 0x800C5960: nop

    // 0x800C5964: break       6
    do_break(2148292964);
L_800C5968:
    // 0x800C5968: mflo        $t3
    ctx->r11 = lo;
    // 0x800C596C: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5970: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800C5974: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5978: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800C597C: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5980: mflo        $t8
    ctx->r24 = lo;
    // 0x800C5984: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // 0x800C5988: nop

L_800C598C:
    // 0x800C598C: beq         $v1, $zero, L_800C599C
    if (ctx->r3 == 0) {
        // 0x800C5990: nop
    
            goto L_800C599C;
    }
    // 0x800C5990: nop

    // 0x800C5994: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5998: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C599C:
    // 0x800C599C: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x800C59A0: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C59A4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C59A8: bne         $at, $zero, L_800C5A00
    if (ctx->r1 != 0) {
        // 0x800C59AC: nop
    
            goto L_800C5A00;
    }
    // 0x800C59AC: nop

    // 0x800C59B0: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C59B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C59B8: bne         $a3, $zero, L_800C59C4
    if (ctx->r7 != 0) {
        // 0x800C59BC: nop
    
            goto L_800C59C4;
    }
    // 0x800C59BC: nop

    // 0x800C59C0: break       7
    do_break(2148293056);
L_800C59C4:
    // 0x800C59C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C59C8: bne         $a3, $at, L_800C59DC
    if (ctx->r7 != ctx->r1) {
        // 0x800C59CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C59DC;
    }
    // 0x800C59CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C59D0: bne         $a1, $at, L_800C59DC
    if (ctx->r5 != ctx->r1) {
        // 0x800C59D4: nop
    
            goto L_800C59DC;
    }
    // 0x800C59D4: nop

    // 0x800C59D8: break       6
    do_break(2148293080);
L_800C59DC:
    // 0x800C59DC: mflo        $t3
    ctx->r11 = lo;
    // 0x800C59E0: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C59E4: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x800C59E8: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C59EC: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800C59F0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C59F4: mflo        $t5
    ctx->r13 = lo;
    // 0x800C59F8: subu        $a1, $a1, $t5
    ctx->r5 = SUB32(ctx->r5, ctx->r13);
    // 0x800C59FC: nop

L_800C5A00:
    // 0x800C5A00: beq         $v1, $zero, L_800C5A10
    if (ctx->r3 == 0) {
        // 0x800C5A04: nop
    
            goto L_800C5A10;
    }
    // 0x800C5A04: nop

    // 0x800C5A08: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5A0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5A10:
    // 0x800C5A10: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C5A14: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800C5A18: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5A1C: bne         $at, $zero, L_800C5A74
    if (ctx->r1 != 0) {
        // 0x800C5A20: addiu       $t1, $zero, 0x30
        ctx->r9 = ADD32(0, 0X30);
            goto L_800C5A74;
    }
    // 0x800C5A20: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800C5A24: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x800C5A28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C5A2C: bne         $a3, $zero, L_800C5A38
    if (ctx->r7 != 0) {
        // 0x800C5A30: nop
    
            goto L_800C5A38;
    }
    // 0x800C5A30: nop

    // 0x800C5A34: break       7
    do_break(2148293172);
L_800C5A38:
    // 0x800C5A38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5A3C: bne         $a3, $at, L_800C5A50
    if (ctx->r7 != ctx->r1) {
        // 0x800C5A40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5A50;
    }
    // 0x800C5A40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5A44: bne         $a1, $at, L_800C5A50
    if (ctx->r5 != ctx->r1) {
        // 0x800C5A48: nop
    
            goto L_800C5A50;
    }
    // 0x800C5A48: nop

    // 0x800C5A4C: break       6
    do_break(2148293196);
L_800C5A50:
    // 0x800C5A50: mflo        $t3
    ctx->r11 = lo;
    // 0x800C5A54: addiu       $t1, $t3, 0x30
    ctx->r9 = ADD32(ctx->r11, 0X30);
    // 0x800C5A58: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x800C5A5C: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5A60: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800C5A64: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x800C5A68: mflo        $t7
    ctx->r15 = lo;
    // 0x800C5A6C: subu        $a1, $a1, $t7
    ctx->r5 = SUB32(ctx->r5, ctx->r15);
    // 0x800C5A70: nop

L_800C5A74:
    // 0x800C5A74: beq         $v1, $zero, L_800C5A84
    if (ctx->r3 == 0) {
        // 0x800C5A78: nop
    
            goto L_800C5A84;
    }
    // 0x800C5A78: nop

    // 0x800C5A7C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800C5A80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C5A84:
    // 0x800C5A84: bne         $t0, $t4, L_800C58B4
    if (ctx->r8 != ctx->r12) {
        // 0x800C5A88: nop
    
            goto L_800C58B4;
    }
    // 0x800C5A88: nop

    // 0x800C5A8C: addiu       $t9, $a1, 0x30
    ctx->r25 = ADD32(ctx->r5, 0X30);
    // 0x800C5A90: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800C5A94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C5A98: jr          $ra
    // 0x800C5A9C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800C5A9C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void set_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F568: jr          $ra
    // 0x8006F56C: sb          $a0, -0x2BD0($at)
    MEM_B(-0X2BD0, ctx->r1) = ctx->r4;
    return;
    // 0x8006F56C: sb          $a0, -0x2BD0($at)
    MEM_B(-0X2BD0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void trackmenu_timetrial_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090ED8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80090EDC: lw          $t6, 0x63E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63E0);
    // 0x80090EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090EEC: bne         $t6, $at, L_80090F20
    if (ctx->r14 != ctx->r1) {
        // 0x80090EF0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80090F20;
    }
    // 0x80090EF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090EF4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80090EF8: lw          $t7, 0x414($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X414);
    // 0x80090EFC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80090F00: bne         $t7, $zero, L_80090F20
    if (ctx->r15 != 0) {
        // 0x80090F04: addiu       $a1, $a1, 0x6840
        ctx->r5 = ADD32(ctx->r5, 0X6840);
            goto L_80090F20;
    }
    // 0x80090F04: addiu       $a1, $a1, 0x6840
    ctx->r5 = ADD32(ctx->r5, 0X6840);
    // 0x80090F08: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80090F0C: nop

    // 0x80090F10: bne         $t8, $zero, L_80090F24
    if (ctx->r24 != 0) {
        // 0x80090F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80090F24;
    }
    // 0x80090F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090F18: jal         0x80001D04
    // 0x80090F1C: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80090F1C: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
    after_0:
L_80090F20:
    // 0x80090F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80090F24:
    // 0x80090F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090F28: jr          $ra
    // 0x80090F2C: nop

    return;
    // 0x80090F2C: nop

;}
RECOMP_FUNC void particle_free_dummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE2D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AE2DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AE2E0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AE2E4: addiu       $s3, $s3, 0x2E60
    ctx->r19 = ADD32(ctx->r19, 0X2E60);
    // 0x800AE2E8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE2EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE2F0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AE2F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AE2F8: beq         $a0, $zero, L_800AE358
    if (ctx->r4 == 0) {
        // 0x800AE2FC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800AE358;
    }
    // 0x800AE2FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AE300: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AE304: addiu       $s2, $s2, 0x2E64
    ctx->r18 = ADD32(ctx->r18, 0X2E64);
    // 0x800AE308: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AE30C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AE310: blez        $t6, L_800AE34C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AE314: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AE34C;
    }
    // 0x800AE314: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AE318:
    // 0x800AE318: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AE31C: nop

    // 0x800AE320: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800AE324: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800AE328: jal         0x8007CCB0
    // 0x800AE32C: nop

    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800AE32C: nop

    after_0:
    // 0x800AE330: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AE334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AE338: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AE33C: bne         $at, $zero, L_800AE318
    if (ctx->r1 != 0) {
        // 0x800AE340: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800AE318;
    }
    // 0x800AE340: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800AE344: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800AE348: nop

L_800AE34C:
    // 0x800AE34C: jal         0x80071140
    // 0x800AE350: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE350: nop

    after_1:
    // 0x800AE354: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800AE358:
    // 0x800AE358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AE35C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE360: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE364: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE368: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AE36C: jr          $ra
    // 0x800AE370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AE370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void cpak_free_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80076168: lw          $a0, -0x1BC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1BC0);
    // 0x8007616C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076170: beq         $a0, $zero, L_80076180
    if (ctx->r4 == 0) {
        // 0x80076174: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80076180;
    }
    // 0x80076174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076178: jal         0x80071140
    // 0x8007617C: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8007617C: nop

    after_0:
L_80076180:
    // 0x80076180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80076188: sw          $zero, -0x1BC0($at)
    MEM_W(-0X1BC0, ctx->r1) = 0;
    // 0x8007618C: jr          $ra
    // 0x80076190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80076190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_loop_levelname(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042A90: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80042A94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80042A98: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80042A9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80042AA0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80042AA4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80042AA8: jal         0x8001BB18
    // 0x80042AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object_by_port(rdram, ctx);
        goto after_0;
    // 0x80042AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80042AB0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80042AB4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80042AB8: beq         $v0, $zero, L_80042CC4
    if (ctx->r2 == 0) {
        // 0x80042ABC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042CC4;
    }
    // 0x80042ABC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042AC0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80042AC4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80042AC8: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80042ACC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80042AD0: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80042AD4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80042AD8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80042ADC: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x80042AE0: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x80042AE4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80042AE8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80042AEC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80042AF0: nop

    // 0x80042AF4: bc1f        L_80042B34
    if (!c1cs) {
        // 0x80042AF8: nop
    
            goto L_80042B34;
    }
    // 0x80042AF8: nop

    // 0x80042AFC: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x80042B00: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80042B04: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80042B08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80042B0C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80042B10: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B14: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80042B18: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80042B1C: bne         $at, $zero, L_80042B60
    if (ctx->r1 != 0) {
        // 0x80042B20: nop
    
            goto L_80042B60;
    }
    // 0x80042B20: nop

    // 0x80042B24: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80042B28: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B2C: b           L_80042B60
    // 0x80042B30: nop

        goto L_80042B60;
    // 0x80042B30: nop

L_80042B34:
    // 0x80042B34: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80042B38: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x80042B3C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80042B40: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80042B44: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B48: nop

    // 0x80042B4C: bgez        $v0, L_80042B60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042B50: nop
    
            goto L_80042B60;
    }
    // 0x80042B50: nop

    // 0x80042B54: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80042B58: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x80042B5C: nop

L_80042B60:
    // 0x80042B60: blez        $v0, L_80042CC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042B64: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80042CC4;
    }
    // 0x80042B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80042B68: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80042B6C: jal         0x8006BDDC
    // 0x80042B70: nop

    level_name(rdram, ctx);
        goto after_1;
    // 0x80042B70: nop

    after_1:
    // 0x80042B74: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80042B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042B80: jal         0x800C4DA0
    // 0x80042B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_2;
    // 0x80042B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80042B88: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80042B8C: sra         $t3, $v1, 1
    ctx->r11 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80042B90: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80042B94: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80042B98: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80042B9C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80042BA0: addiu       $t6, $t3, 0xA0
    ctx->r14 = ADD32(ctx->r11, 0XA0);
    // 0x80042BA4: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80042BA8: bne         $t7, $zero, L_80042BC4
    if (ctx->r15 != 0) {
        // 0x80042BAC: sw          $t6, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r14;
            goto L_80042BC4;
    }
    // 0x80042BAC: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80042BB0: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x80042BB4: addiu       $t9, $zero, 0xF8
    ctx->r25 = ADD32(0, 0XF8);
    // 0x80042BB8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80042BBC: b           L_80042BD4
    // 0x80042BC0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80042BD4;
    // 0x80042BC0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80042BC4:
    // 0x80042BC4: addiu       $t0, $zero, 0xCA
    ctx->r8 = ADD32(0, 0XCA);
    // 0x80042BC8: addiu       $t1, $zero, 0xDE
    ctx->r9 = ADD32(0, 0XDE);
    // 0x80042BCC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80042BD0: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80042BD4:
    // 0x80042BD4: jal         0x800C5494
    // 0x80042BD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80042BD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80042BDC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80042BE0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80042BE4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80042BE8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80042BEC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042BF0: jal         0x800C4EDC
    // 0x80042BF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_4;
    // 0x80042BF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_4:
    // 0x80042BF8: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x80042BFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C00: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80042C04: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80042C08: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x80042C0C: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80042C10: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80042C14: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80042C18: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80042C1C: jal         0x800C4FBC
    // 0x80042C20: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80042C20: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_5:
    // 0x80042C24: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042C2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80042C30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80042C34: jal         0x800C5050
    // 0x80042C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x80042C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80042C3C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C40: jal         0x800C4F7C
    // 0x80042C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x80042C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80042C48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80042C4C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x80042C50: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042C54: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80042C58: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80042C5C: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80042C60: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80042C64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80042C68: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80042C6C: jal         0x800C5000
    // 0x80042C70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_8;
    // 0x80042C70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x80042C74: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80042C78: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80042C7C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80042C80: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80042C84: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x80042C88: subu        $a2, $t2, $t3
    ctx->r6 = SUB32(ctx->r10, ctx->r11);
    // 0x80042C8C: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80042C90: sra         $t1, $a1, 1
    ctx->r9 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80042C94: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80042C98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80042C9C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80042CA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80042CA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80042CA8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80042CAC: addiu       $a2, $t4, 0x2
    ctx->r6 = ADD32(ctx->r12, 0X2);
    // 0x80042CB0: jal         0x800C5168
    // 0x80042CB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x80042CB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x80042CB8: jal         0x800C55F4
    // 0x80042CBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    open_dialogue_box(rdram, ctx);
        goto after_10;
    // 0x80042CBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_10:
    // 0x80042CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80042CC4:
    // 0x80042CC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80042CC8: jr          $ra
    // 0x80042CCC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80042CCC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void set_menu_id_if_option_equal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D33C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D340: addiu       $v0, $v0, 0x64E2
    ctx->r2 = ADD32(ctx->r2, 0X64E2);
    // 0x8009D344: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D348: nop

    // 0x8009D34C: bne         $a0, $t6, L_8009D358
    if (ctx->r4 != ctx->r14) {
        // 0x8009D350: nop
    
            goto L_8009D358;
    }
    // 0x8009D350: nop

    // 0x8009D354: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_8009D358:
    // 0x8009D358: jr          $ra
    // 0x8009D35C: nop

    return;
    // 0x8009D35C: nop

;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065B2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065B30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065B34: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065B38: nop

    // 0x80065B3C: beq         $t7, $zero, L_80065BBC
    if (ctx->r15 == 0) {
        // 0x80065B40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065BBC;
    }
    // 0x80065B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B44: jal         0x80065668
    // 0x80065B48: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065B48: nop

    after_0:
    // 0x80065B4C: beq         $v0, $zero, L_80065BB8
    if (ctx->r2 == 0) {
        // 0x80065B50: addiu       $t4, $zero, 0xC
        ctx->r12 = ADD32(0, 0XC);
            goto L_80065BB8;
    }
    // 0x80065B50: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80065B54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80065B58: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065B5C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80065B60: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065B64: lw          $t2, 0xD8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XD8);
    // 0x80065B68: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x80065B6C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80065B70: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80065B74: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80065B78: jal         0x80065BEC
    // 0x80065B7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065B7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80065B80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065B84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065B88: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80065B8C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065B90: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065B94: nop

    // 0x80065B98: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80065B9C: nop

    // 0x80065BA0: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80065BA4: nop

    // 0x80065BA8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065BAC: nop

    // 0x80065BB0: jalr        $t9
    // 0x80065BB4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80065BB4: nop

    after_2:
L_80065BB8:
    // 0x80065BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065BBC:
    // 0x80065BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065BC0: jr          $ra
    // 0x80065BC4: nop

    return;
    // 0x80065BC4: nop

;}
RECOMP_FUNC void material_set_no_tex_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B4C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B4CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B4D0: jal         0x8007B4E8
    // 0x8007B4D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8007B4D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8007B4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B4E0: jr          $ra
    // 0x8007B4E4: nop

    return;
    // 0x8007B4E4: nop

;}
RECOMP_FUNC void slowly_change_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030DE0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80030DE4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80030DE8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80030DEC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80030DF0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80030DF4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80030DF8: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030DFC: beq         $at, $zero, L_80030E10
    if (ctx->r1 == 0) {
        // 0x80030E00: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_80030E10;
    }
    // 0x80030E00: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030E04: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80030E08: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80030E0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80030E10:
    // 0x80030E10: slti        $at, $s0, 0x400
    ctx->r1 = SIGNED(ctx->r16) < 0X400 ? 1 : 0;
    // 0x80030E14: bne         $at, $zero, L_80030E20
    if (ctx->r1 != 0) {
        // 0x80030E18: subu        $t6, $t6, $a0
        ctx->r14 = SUB32(ctx->r14, ctx->r4);
            goto L_80030E20;
    }
    // 0x80030E18: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030E1C: addiu       $s0, $zero, 0x3FF
    ctx->r16 = ADD32(0, 0X3FF);
L_80030E20:
    // 0x80030E20: addiu       $v0, $s0, -0x5
    ctx->r2 = ADD32(ctx->r16, -0X5);
    // 0x80030E24: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030E28: bne         $at, $zero, L_80030E34
    if (ctx->r1 != 0) {
        // 0x80030E2C: sll         $t6, $t6, 3
        ctx->r14 = S32(ctx->r14 << 3);
            goto L_80030E34;
    }
    // 0x80030E2C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030E30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80030E34:
    // 0x80030E34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80030E38: addiu       $t7, $t7, -0x2C78
    ctx->r15 = ADD32(ctx->r15, -0X2C78);
    // 0x80030E3C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030E40: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80030E44: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80030E48: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80030E4C: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x80030E50: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80030E54: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030E58: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80030E5C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030E60: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030E64: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030E68: sb          $a1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r5;
    // 0x80030E6C: sb          $a2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r6;
    // 0x80030E70: sb          $a3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r7;
    // 0x80030E74: sh          $s1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r17;
    // 0x80030E78: sh          $s0, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r16;
    // 0x80030E7C: bne         $v1, $zero, L_80030E88
    if (ctx->r3 != 0) {
        // 0x80030E80: nop
    
            goto L_80030E88;
    }
    // 0x80030E80: nop

    // 0x80030E84: break       7
    do_break(2147683972);
L_80030E88:
    // 0x80030E88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030E8C: bne         $v1, $at, L_80030EA0
    if (ctx->r3 != ctx->r1) {
        // 0x80030E90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030EA0;
    }
    // 0x80030E90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030E94: bne         $t0, $at, L_80030EA0
    if (ctx->r8 != ctx->r1) {
        // 0x80030E98: nop
    
            goto L_80030EA0;
    }
    // 0x80030E98: nop

    // 0x80030E9C: break       6
    do_break(2147683996);
L_80030EA0:
    // 0x80030EA0: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80030EA4: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80030EA8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030EAC: mflo        $t1
    ctx->r9 = lo;
    // 0x80030EB0: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x80030EB4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80030EB8: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x80030EBC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80030EC0: bne         $v1, $zero, L_80030ECC
    if (ctx->r3 != 0) {
        // 0x80030EC4: nop
    
            goto L_80030ECC;
    }
    // 0x80030EC4: nop

    // 0x80030EC8: break       7
    do_break(2147684040);
L_80030ECC:
    // 0x80030ECC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030ED0: bne         $v1, $at, L_80030EE4
    if (ctx->r3 != ctx->r1) {
        // 0x80030ED4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030EE4;
    }
    // 0x80030ED4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030ED8: bne         $t4, $at, L_80030EE4
    if (ctx->r12 != ctx->r1) {
        // 0x80030EDC: nop
    
            goto L_80030EE4;
    }
    // 0x80030EDC: nop

    // 0x80030EE0: break       6
    do_break(2147684064);
L_80030EE4:
    // 0x80030EE4: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80030EE8: mflo        $t5
    ctx->r13 = lo;
    // 0x80030EEC: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x80030EF0: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80030EF4: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x80030EF8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80030EFC: bne         $v1, $zero, L_80030F08
    if (ctx->r3 != 0) {
        // 0x80030F00: nop
    
            goto L_80030F08;
    }
    // 0x80030F00: nop

    // 0x80030F04: break       7
    do_break(2147684100);
L_80030F08:
    // 0x80030F08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F0C: bne         $v1, $at, L_80030F20
    if (ctx->r3 != ctx->r1) {
        // 0x80030F10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F20;
    }
    // 0x80030F10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F14: bne         $t8, $at, L_80030F20
    if (ctx->r24 != ctx->r1) {
        // 0x80030F18: nop
    
            goto L_80030F20;
    }
    // 0x80030F18: nop

    // 0x80030F1C: break       6
    do_break(2147684124);
L_80030F20:
    // 0x80030F20: mflo        $t9
    ctx->r25 = lo;
    // 0x80030F24: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030F28: nop

    // 0x80030F2C: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x80030F30: bne         $v1, $zero, L_80030F3C
    if (ctx->r3 != 0) {
        // 0x80030F34: nop
    
            goto L_80030F3C;
    }
    // 0x80030F34: nop

    // 0x80030F38: break       7
    do_break(2147684152);
L_80030F3C:
    // 0x80030F3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F40: bne         $v1, $at, L_80030F54
    if (ctx->r3 != ctx->r1) {
        // 0x80030F44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F54;
    }
    // 0x80030F44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F48: bne         $t2, $at, L_80030F54
    if (ctx->r10 != ctx->r1) {
        // 0x80030F4C: nop
    
            goto L_80030F54;
    }
    // 0x80030F4C: nop

    // 0x80030F50: break       6
    do_break(2147684176);
L_80030F54:
    // 0x80030F54: mflo        $t3
    ctx->r11 = lo;
    // 0x80030F58: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x80030F5C: nop

    // 0x80030F60: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80030F64: bne         $v1, $zero, L_80030F70
    if (ctx->r3 != 0) {
        // 0x80030F68: nop
    
            goto L_80030F70;
    }
    // 0x80030F68: nop

    // 0x80030F6C: break       7
    do_break(2147684204);
L_80030F70:
    // 0x80030F70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030F74: bne         $v1, $at, L_80030F88
    if (ctx->r3 != ctx->r1) {
        // 0x80030F78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030F88;
    }
    // 0x80030F78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030F7C: bne         $t6, $at, L_80030F88
    if (ctx->r14 != ctx->r1) {
        // 0x80030F80: nop
    
            goto L_80030F88;
    }
    // 0x80030F80: nop

    // 0x80030F84: break       6
    do_break(2147684228);
L_80030F88:
    // 0x80030F88: mflo        $t7
    ctx->r15 = lo;
    // 0x80030F8C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80030F90: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80030F94: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80030F98: jr          $ra
    // 0x80030F9C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80030F9C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void leveltable_world(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B190: bltz        $a0, L_8006B1C8
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006B194: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B1C8;
    }
    // 0x8006B194: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B198: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006B19C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B1A0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B1A4: beq         $at, $zero, L_8006B1C8
    if (ctx->r1 == 0) {
        // 0x8006B1A8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B1C8;
    }
    // 0x8006B1A8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B1AC: lw          $t7, 0x117C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X117C);
    // 0x8006B1B0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B1B4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B1B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B1BC: lb          $v0, 0x0($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X0);
    // 0x8006B1C0: jr          $ra
    // 0x8006B1C4: nop

    return;
    // 0x8006B1C4: nop

L_8006B1C8:
    // 0x8006B1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B1CC: jr          $ra
    // 0x8006B1D0: nop

    return;
    // 0x8006B1D0: nop

;}
RECOMP_FUNC void mtx_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80067F30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067F38: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80067F3C: jal         0x8007A520
    // 0x80067F40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80067F40: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80067F44: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x80067F48: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80067F4C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80067F50: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80067F54: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80067F58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80067F5C: jal         0x8006F870
    // 0x80067F60: addiu       $a0, $a0, -0x2D48
    ctx->r4 = ADD32(ctx->r4, -0X2D48);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x80067F60: addiu       $a0, $a0, -0x2D48
    ctx->r4 = ADD32(ctx->r4, -0X2D48);
    after_1:
    // 0x80067F64: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80067F68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80067F6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80067F70: addiu       $t4, $t4, 0xCE4
    ctx->r12 = ADD32(ctx->r12, 0XCE4);
    // 0x80067F74: sw          $t8, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r24;
    // 0x80067F78: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80067F7C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80067F80: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80067F84: addiu       $t3, $t3, -0x2EB8
    ctx->r11 = ADD32(ctx->r11, -0X2EB8);
    // 0x80067F88: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x80067F8C: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x80067F90: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80067F94: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80067F98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80067F9C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80067FA0: sh          $t6, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r14;
    // 0x80067FA4: sh          $t6, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r14;
    // 0x80067FA8: sh          $t6, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r14;
    // 0x80067FAC: sh          $t8, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r24;
    // 0x80067FB0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80067FB4: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x80067FB8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80067FBC: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80067FC0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80067FC4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80067FC8: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80067FCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80067FD0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80067FD4: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80067FD8: ori         $at, $at, 0x50
    ctx->r1 = ctx->r1 | 0X50;
    // 0x80067FDC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80067FE0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80067FE4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80067FE8: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x80067FEC: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80067FF0: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80067FF4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80067FF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80067FFC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80068000: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068004: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80068008: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8006800C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80068010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068014: addiu       $t5, $t9, 0x40
    ctx->r13 = ADD32(ctx->r25, 0X40);
    // 0x80068018: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006801C: sw          $zero, 0xD1C($at)
    MEM_W(0XD1C, ctx->r1) = 0;
    // 0x80068020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068024: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80068028: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006802C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80068030: sw          $zero, 0xD08($at)
    MEM_W(0XD08, ctx->r1) = 0;
    // 0x80068034: addiu       $v0, $v0, -0x2D48
    ctx->r2 = ADD32(ctx->r2, -0X2D48);
    // 0x80068038: addiu       $v1, $v1, 0xF20
    ctx->r3 = ADD32(ctx->r3, 0XF20);
    // 0x8006803C: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
L_80068040:
    // 0x80068040: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80068044: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80068048: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006804C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80068050: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80068054: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80068058: swc1        $f4, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8006805C: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x80068060: swc1        $f8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80068064: bne         $v0, $a0, L_80068040
    if (ctx->r2 != ctx->r4) {
        // 0x80068068: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80068040;
    }
    // 0x80068068: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8006806C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068074: jr          $ra
    // 0x80068078: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80068078: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void model_anim_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061A00: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80061A04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80061A08: lw          $t6, -0x29C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X29C8);
    // 0x80061A0C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80061A10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80061A14: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80061A18: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80061A1C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80061A20: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80061A24: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80061A28: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80061A2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061A30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061A34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061A38: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80061A3C: lh          $s0, 0x0($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X0);
    // 0x80061A40: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80061A44: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80061A48: bne         $s0, $v1, L_80061A5C
    if (ctx->r16 != ctx->r3) {
        // 0x80061A4C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80061A5C;
    }
    // 0x80061A4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80061A50: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x80061A54: b           L_80061BDC
    // 0x80061A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80061BDC;
    // 0x80061A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061A5C:
    // 0x80061A5C: lw          $v0, -0x29C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29C0);
    // 0x80061A60: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061A64: beq         $v0, $zero, L_80061A80
    if (ctx->r2 == 0) {
        // 0x80061A68: ori         $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 | 0XFF;
            goto L_80061A80;
    }
    // 0x80061A68: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80061A6C: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x80061A70: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061A74: beq         $at, $zero, L_80061A84
    if (ctx->r1 == 0) {
        // 0x80061A78: subu        $t8, $v1, $s0
        ctx->r24 = SUB32(ctx->r3, ctx->r16);
            goto L_80061A84;
    }
    // 0x80061A78: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
    // 0x80061A7C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80061A80:
    // 0x80061A80: subu        $t8, $v1, $s0
    ctx->r24 = SUB32(ctx->r3, ctx->r16);
L_80061A84:
    // 0x80061A84: sh          $t8, 0x48($s5)
    MEM_H(0X48, ctx->r21) = ctx->r24;
    // 0x80061A88: lh          $a0, 0x48($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X48);
    // 0x80061A8C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80061A90: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x80061A94: jal         0x80070D10
    // 0x80061A98: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80061A98: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80061A9C: bne         $v0, $zero, L_80061AAC
    if (ctx->r2 != 0) {
        // 0x80061AA0: sw          $v0, 0x44($s5)
        MEM_W(0X44, ctx->r21) = ctx->r2;
            goto L_80061AAC;
    }
    // 0x80061AA0: sw          $v0, 0x44($s5)
    MEM_W(0X44, ctx->r21) = ctx->r2;
    // 0x80061AA4: b           L_80061BDC
    // 0x80061AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BDC;
    // 0x80061AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061AAC:
    // 0x80061AAC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80061AB0: sll         $s4, $s0, 2
    ctx->r20 = S32(ctx->r16 << 2);
    // 0x80061AB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061AB8:
    // 0x80061AB8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80061ABC: lw          $t0, -0x29C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X29C4);
    // 0x80061AC0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80061AC4: addu        $v0, $t0, $s4
    ctx->r2 = ADD32(ctx->r8, ctx->r20);
    // 0x80061AC8: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x80061ACC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80061AD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80061AD4: jal         0x800C61DC
    // 0x80061AD8: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x80061AD8: subu        $s3, $t1, $s2
    ctx->r19 = SUB32(ctx->r9, ctx->r18);
    after_1:
    // 0x80061ADC: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x80061AE0: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80061AE4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80061AE8: jal         0x80070D10
    // 0x80061AEC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x80061AEC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x80061AF0: lw          $t2, 0x44($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X44);
    // 0x80061AF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80061AF8: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80061AFC: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80061B00: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061B04: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80061B08: addu        $t4, $a0, $s1
    ctx->r12 = ADD32(ctx->r4, ctx->r17);
    // 0x80061B0C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80061B10: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80061B14: bne         $v1, $zero, L_80061B68
    if (ctx->r3 != 0) {
        // 0x80061B18: addu        $t7, $v1, $s6
        ctx->r15 = ADD32(ctx->r3, ctx->r22);
            goto L_80061B68;
    }
    // 0x80061B18: addu        $t7, $v1, $s6
    ctx->r15 = ADD32(ctx->r3, ctx->r22);
    // 0x80061B1C: blez        $fp, L_80061B54
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80061B20: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80061B54;
    }
    // 0x80061B20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80061B24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061B28:
    // 0x80061B28: lw          $t5, 0x44($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X44);
    // 0x80061B2C: nop

    // 0x80061B30: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80061B34: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80061B38: jal         0x80071140
    // 0x80061B3C: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80061B3C: nop

    after_3:
    // 0x80061B40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80061B44: bne         $s0, $fp, L_80061B28
    if (ctx->r16 != ctx->r30) {
        // 0x80061B48: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80061B28;
    }
    // 0x80061B48: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061B4C: lw          $a0, 0x44($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X44);
    // 0x80061B50: nop

L_80061B54:
    // 0x80061B54: jal         0x80071140
    // 0x80061B58: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80061B58: nop

    after_4:
    // 0x80061B5C: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
    // 0x80061B60: b           L_80061BDC
    // 0x80061B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80061BDC;
    // 0x80061B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061B68:
    // 0x80061B68: subu        $s0, $t7, $s3
    ctx->r16 = SUB32(ctx->r15, ctx->r19);
    // 0x80061B6C: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80061B70: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    // 0x80061B74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80061B78: jal         0x80076E68
    // 0x80061B7C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    asset_load(rdram, ctx);
        goto after_5;
    // 0x80061B7C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_5:
    // 0x80061B80: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x80061B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061B88: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80061B8C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80061B90: jal         0x800C6218
    // 0x80061B94: nop

    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x80061B94: nop

    after_6:
    // 0x80061B98: lw          $t1, 0x44($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X44);
    // 0x80061B9C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80061BA0: addu        $v1, $t1, $s1
    ctx->r3 = ADD32(ctx->r9, ctx->r17);
    // 0x80061BA4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80061BA8: slt         $at, $s4, $s7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80061BAC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80061BB0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80061BB4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80061BB8: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x80061BBC: nop

    // 0x80061BC0: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
    // 0x80061BC4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80061BC8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80061BCC: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80061BD0: bne         $at, $zero, L_80061AB8
    if (ctx->r1 != 0) {
        // 0x80061BD4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_80061AB8;
    }
    // 0x80061BD4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061BDC:
    // 0x80061BDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80061BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061BE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80061BE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80061BEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80061BF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80061BF4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80061BF8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80061BFC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80061C00: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80061C04: jr          $ra
    // 0x80061C08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80061C08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void gzip_inflate_stored(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6F34: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C6F38: lw          $t5, -0x552C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X552C);
    // 0x800C6F3C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C6F40: lw          $t4, -0x5530($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5530);
    // 0x800C6F44: andi        $t0, $t5, 0x7
    ctx->r8 = ctx->r13 & 0X7;
    // 0x800C6F48: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C6F4C: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C6F50: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800C6F54: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C6F58: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C6F5C: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C6F60: lw          $t7, 0x3768($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3768);
    // 0x800C6F64: beq         $at, $zero, L_800C6F88
    if (ctx->r1 == 0) {
        // 0x800C6F68: lw          $t6, 0x376C($t6)
        ctx->r14 = MEM_W(ctx->r14, 0X376C);
            goto L_800C6F88;
    }
    // 0x800C6F68: lw          $t6, 0x376C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X376C);
L_800C6F6C:
    // 0x800C6F6C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6F70: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C6F74: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C6F78: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C6F7C: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6F80: bne         $at, $zero, L_800C6F6C
    if (ctx->r1 != 0) {
        // 0x800C6F84: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C6F6C;
    }
    // 0x800C6F84: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C6F88:
    // 0x800C6F88: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C6F8C: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800C6F90: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x800C6F94: beq         $at, $zero, L_800C6FB8
    if (ctx->r1 == 0) {
        // 0x800C6F98: srlv        $t4, $t4, $t0
        ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
            goto L_800C6FB8;
    }
    // 0x800C6F98: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
L_800C6F9C:
    // 0x800C6F9C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6FA0: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C6FA4: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C6FA8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800C6FAC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6FB0: bne         $at, $zero, L_800C6F9C
    if (ctx->r1 != 0) {
        // 0x800C6FB4: or          $t4, $t4, $v0
        ctx->r12 = ctx->r12 | ctx->r2;
            goto L_800C6F9C;
    }
    // 0x800C6FB4: or          $t4, $t4, $v0
    ctx->r12 = ctx->r12 | ctx->r2;
L_800C6FB8:
    // 0x800C6FB8: andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // 0x800C6FBC: srlv        $t4, $t4, $t0
    ctx->r12 = S32(U32(ctx->r12) >> (ctx->r8 & 31));
    // 0x800C6FC0: beq         $v0, $zero, L_800C6FEC
    if (ctx->r2 == 0) {
        // 0x800C6FC4: sub         $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_800C6FEC;
    }
    // 0x800C6FC4: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800C6FC8: sub         $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
L_800C6FCC:
    // 0x800C6FCC: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6FD0: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C6FD4: addi        $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C6FD8: addi        $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C6FDC: bne         $v0, $zero, L_800C6FCC
    if (ctx->r2 != 0) {
        // 0x800C6FE0: sb          $t2, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r10;
            goto L_800C6FCC;
    }
    // 0x800C6FE0: sb          $t2, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r10;
    // 0x800C6FE4: beq         $t1, $zero, L_800C701C
    if (ctx->r9 == 0) {
        // 0x800C6FE8: nop
    
            goto L_800C701C;
    }
    // 0x800C6FE8: nop

L_800C6FEC:
    // 0x800C6FEC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6FF0: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x800C6FF4: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C6FF8: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C6FFC: lbu         $v1, -0x3($t7)
    ctx->r3 = MEM_BU(ctx->r15, -0X3);
    // 0x800C7000: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x800C7004: sb          $v1, -0x3($t6)
    MEM_B(-0X3, ctx->r14) = ctx->r3;
    // 0x800C7008: lbu         $t2, -0x2($t7)
    ctx->r10 = MEM_BU(ctx->r15, -0X2);
    // 0x800C700C: sb          $t2, -0x2($t6)
    MEM_B(-0X2, ctx->r14) = ctx->r10;
    // 0x800C7010: lbu         $t3, -0x1($t7)
    ctx->r11 = MEM_BU(ctx->r15, -0X1);
    // 0x800C7014: bne         $t1, $zero, L_800C6FEC
    if (ctx->r9 != 0) {
        // 0x800C7018: sb          $t3, -0x1($t6)
        MEM_B(-0X1, ctx->r14) = ctx->r11;
            goto L_800C6FEC;
    }
    // 0x800C7018: sb          $t3, -0x1($t6)
    MEM_B(-0X1, ctx->r14) = ctx->r11;
L_800C701C:
    // 0x800C701C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7020: sw          $t7, 0x3768($at)
    MEM_W(0X3768, ctx->r1) = ctx->r15;
    // 0x800C7024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7028: sw          $t6, 0x376C($at)
    MEM_W(0X376C, ctx->r1) = ctx->r14;
    // 0x800C702C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7030: sw          $t4, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r12;
    // 0x800C7034: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7038: jr          $ra
    // 0x800C703C: sw          $t5, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = ctx->r13;
    return;
    // 0x800C703C: sw          $t5, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = ctx->r13;
;}
RECOMP_FUNC void postrace_music_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094C14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094C18: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x80094C1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094C20: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80094C24: addiu       $a1, $a1, 0x6A94
    ctx->r5 = ADD32(ctx->r5, 0X6A94);
    // 0x80094C28: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80094C2C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80094C30: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80094C34: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80094C38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80094C3C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80094C40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80094C44: lw          $v0, 0x63D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D8);
    // 0x80094C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094C4C: bltz        $v0, L_80094D18
    if (SIGNED(ctx->r2) < 0) {
        // 0x80094C50: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80094D18;
    }
    // 0x80094C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094C54: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80094C58: lw          $v1, -0xBA0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XBA0);
    // 0x80094C5C: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80094C60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094C64: beq         $v1, $zero, L_80094C80
    if (ctx->r3 == 0) {
        // 0x80094C68: sw          $t1, 0x63D8($at)
        MEM_W(0X63D8, ctx->r1) = ctx->r9;
            goto L_80094C80;
    }
    // 0x80094C68: sw          $t1, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r9;
    // 0x80094C6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094C70: beq         $v1, $at, L_80094CB8
    if (ctx->r3 == ctx->r1) {
        // 0x80094C74: nop
    
            goto L_80094CB8;
    }
    // 0x80094C74: nop

    // 0x80094C78: b           L_80094CF0
    // 0x80094C7C: nop

        goto L_80094CF0;
    // 0x80094C7C: nop

L_80094C80:
    // 0x80094C80: jal         0x8000C8B4
    // 0x80094C84: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x80094C84: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    after_0:
    // 0x80094C88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80094C8C: lw          $t2, 0x63D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X63D8);
    // 0x80094C90: nop

    // 0x80094C94: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80094C98: beq         $at, $zero, L_80094CF0
    if (ctx->r1 == 0) {
        // 0x80094C9C: nop
    
            goto L_80094CF0;
    }
    // 0x80094C9C: nop

    // 0x80094CA0: jal         0x80000C98
    // 0x80094CA4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    music_fade(rdram, ctx);
        goto after_1;
    // 0x80094CA4: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    after_1:
    // 0x80094CA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80094CAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094CB0: b           L_80094CF0
    // 0x80094CB4: sw          $t3, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = ctx->r11;
        goto L_80094CF0;
    // 0x80094CB4: sw          $t3, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = ctx->r11;
L_80094CB8:
    // 0x80094CB8: jal         0x8000C8B4
    // 0x80094CBC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x80094CBC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_2:
    // 0x80094CC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80094CC4: lw          $t4, 0x63D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63D8);
    // 0x80094CC8: nop

    // 0x80094CCC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80094CD0: beq         $at, $zero, L_80094CF0
    if (ctx->r1 == 0) {
        // 0x80094CD4: nop
    
            goto L_80094CF0;
    }
    // 0x80094CD4: nop

    // 0x80094CD8: jal         0x80000BE0
    // 0x80094CDC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x80094CDC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x80094CE0: jal         0x80000B34
    // 0x80094CE4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_4;
    // 0x80094CE4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_4:
    // 0x80094CE8: jal         0x80000C98
    // 0x80094CEC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_5;
    // 0x80094CEC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_5:
L_80094CF0:
    // 0x80094CF0: jal         0x8000C8B4
    // 0x80094CF4: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x80094CF4: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_6:
    // 0x80094CF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094CFC: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x80094D00: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80094D04: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80094D08: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80094D0C: beq         $at, $zero, L_80094D1C
    if (ctx->r1 == 0) {
        // 0x80094D10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80094D1C;
    }
    // 0x80094D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094D14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80094D18:
    // 0x80094D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094D1C:
    // 0x80094D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094D20: jr          $ra
    // 0x80094D24: nop

    return;
    // 0x80094D24: nop

;}
RECOMP_FUNC void model_init_normals(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060EA8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80060EAC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060EB0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060EB4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060EB8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060EBC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060EC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060EC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060EC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060ECC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060ED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060ED4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80060ED8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80060EDC: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80060EE0: lh          $v1, 0x28($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X28);
    // 0x80060EE4: lw          $ra, 0x38($a0)
    ctx->r31 = MEM_W(ctx->r4, 0X38);
    // 0x80060EE8: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x80060EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80060EF0: blez        $v1, L_80060F60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80060EF4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80060F60;
    }
    // 0x80060EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060EF8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
L_80060EFC:
    // 0x80060EFC: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060F00: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80060F04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80060F08: mflo        $t7
    ctx->r15 = lo;
    // 0x80060F0C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80060F10: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80060F14: nop

    // 0x80060F18: bne         $t8, $at, L_80060F34
    if (ctx->r24 != ctx->r1) {
        // 0x80060F1C: nop
    
            goto L_80060F34;
    }
    // 0x80060F1C: nop

    // 0x80060F20: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060F24: nop

    // 0x80060F28: andi        $t6, $t9, 0x8000
    ctx->r14 = ctx->r25 & 0X8000;
    // 0x80060F2C: beq         $t6, $zero, L_80060F50
    if (ctx->r14 == 0) {
        // 0x80060F30: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80060F50;
    }
    // 0x80060F30: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80060F34:
    // 0x80060F34: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80060F38: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80060F3C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80060F40: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
    // 0x80060F44: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80060F48: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80060F4C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80060F50:
    // 0x80060F50: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80060F54: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060F58: bne         $at, $zero, L_80060EFC
    if (ctx->r1 != 0) {
        // 0x80060F5C: nop
    
            goto L_80060EFC;
    }
    // 0x80060F5C: nop

L_80060F60:
    // 0x80060F60: blez        $a3, L_800619B8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80060F64: lui         $a1, 0xFF7F
        ctx->r5 = S32(0XFF7F << 16);
            goto L_800619B8;
    }
    // 0x80060F64: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80060F68: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80060F6C: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80060F70: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80060F74: lw          $s3, 0x4($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X4);
    // 0x80060F78: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x80060F7C: lh          $a0, 0x26($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X26);
    // 0x80060F80: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80060F84: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80060F88: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80060F8C: sll         $a0, $t8, 2
    ctx->r4 = S32(ctx->r24 << 2);
    // 0x80060F90: jal         0x80070D10
    // 0x80060F94: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80060F94: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    after_0:
    // 0x80060F98: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x80060F9C: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80060FA0: bne         $v0, $zero, L_80060FB0
    if (ctx->r2 != 0) {
        // 0x80060FA4: sw          $v0, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r2;
            goto L_80060FB0;
    }
    // 0x80060FA4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80060FA8: b           L_800619BC
    // 0x80060FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800619BC;
    // 0x80060FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060FB0:
    // 0x80060FB0: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x80060FB4: subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // 0x80060FB8: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80060FBC: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80060FC0: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80060FC4: jal         0x80070D10
    // 0x80060FC8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80060FC8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_1:
    // 0x80060FCC: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80060FD0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80060FD4: bne         $v0, $zero, L_80060FF0
    if (ctx->r2 != 0) {
        // 0x80060FD8: sw          $v0, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r2;
            goto L_80060FF0;
    }
    // 0x80060FD8: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80060FDC: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80060FE0: jal         0x80071140
    // 0x80060FE4: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060FE4: nop

    after_2:
    // 0x80060FE8: b           L_800619BC
    // 0x80060FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800619BC;
    // 0x80060FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060FF0:
    // 0x80060FF0: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x80060FF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060FF8: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x80060FFC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x80061000: blez        $v1, L_80061230
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80061004: addiu       $s6, $sp, 0x70
        ctx->r22 = ADD32(ctx->r29, 0X70);
            goto L_80061230;
    }
    // 0x80061004: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
    // 0x80061008: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8006100C: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x80061010: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80061014:
    // 0x80061014: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061018: mflo        $t7
    ctx->r15 = lo;
    // 0x8006101C: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80061020: lh          $s5, 0x4($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X4);
    // 0x80061024: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80061028: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x8006102C: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80061030: beq         $at, $zero, L_80061218
    if (ctx->r1 == 0) {
        // 0x80061034: nop
    
            goto L_80061218;
    }
    // 0x80061034: nop

    // 0x80061038: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8006103C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
L_80061040:
    // 0x80061040: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80061044: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061048: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8006104C:
    // 0x8006104C: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x80061050: lbu         $t6, 0x1($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X1);
    // 0x80061054: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80061058: addu        $a2, $t6, $s4
    ctx->r6 = ADD32(ctx->r14, ctx->r20);
    // 0x8006105C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80061060: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061064: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061068: addu        $t8, $s6, $v0
    ctx->r24 = ADD32(ctx->r22, ctx->r2);
    // 0x8006106C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061070: mflo        $t7
    ctx->r15 = lo;
    // 0x80061074: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x80061078: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8006107C: addu        $t7, $s7, $v0
    ctx->r15 = ADD32(ctx->r23, ctx->r2);
    // 0x80061080: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80061084: nop

    // 0x80061088: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006108C: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x80061090: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80061094: addu        $t8, $fp, $v0
    ctx->r24 = ADD32(ctx->r30, ctx->r2);
    // 0x80061098: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8006109C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800610A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800610A4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800610A8: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800610AC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800610B0: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x800610B4: nop

    // 0x800610B8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800610BC: nop

    // 0x800610C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800610C4: bne         $at, $zero, L_8006104C
    if (ctx->r1 != 0) {
        // 0x800610C8: swc1        $f18, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
            goto L_8006104C;
    }
    // 0x800610C8: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x800610CC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800610D0: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800610D4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800610D8: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800610DC: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800610E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800610E4: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800610E8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800610EC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800610F0: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800610F4: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800610F8: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800610FC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80061100: mflo        $t8
    ctx->r24 = lo;
    // 0x80061104: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80061108: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x8006110C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061110: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80061114: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80061118: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006111C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80061120: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80061124: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80061128: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006112C: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80061130: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061134: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80061138: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006113C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80061140: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80061144: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80061148: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8006114C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80061150: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80061154: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80061158: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006115C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80061160: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80061164: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80061168: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8006116C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061170: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80061174: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80061178: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8006117C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80061180: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80061184: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80061188: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006118C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80061190: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061194: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061198: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006119C: nop

    // 0x800611A0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800611A4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800611A8: jal         0x800C9AD0
    // 0x800611AC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800611AC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x800611B0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800611B4: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x800611B8: bc1t        L_800611E8
    if (c1cs) {
        // 0x800611BC: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_800611E8;
    }
    // 0x800611BC: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800611C0: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800611C4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800611C8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800611CC: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800611D0: nop

    // 0x800611D4: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800611D8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800611DC: div.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800611E0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800611E4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_800611E8:
    // 0x800611E8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800611EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800611F0: lh          $t8, 0x10($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X10);
    // 0x800611F4: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x800611F8: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800611FC: slt         $at, $s5, $t8
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061200: bne         $at, $zero, L_80061040
    if (ctx->r1 != 0) {
        // 0x80061204: lw          $t8, 0xB0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB0);
            goto L_80061040;
    }
    // 0x80061204: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80061208: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8006120C: nop

    // 0x80061210: lh          $v1, 0x28($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X28);
    // 0x80061214: nop

L_80061218:
    // 0x80061218: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006121C: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x80061220: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061224: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061228: bne         $at, $zero, L_80061014
    if (ctx->r1 != 0) {
        // 0x8006122C: nop
    
            goto L_80061014;
    }
    // 0x8006122C: nop

L_80061230:
    // 0x80061230: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80061234: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80061238: lh          $a0, 0x24($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X24);
    // 0x8006123C: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061240: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061244: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80061248: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8006124C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80061250: jal         0x80070D10
    // 0x80061254: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x80061254: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    after_4:
    // 0x80061258: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x8006125C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061260: bne         $v0, $zero, L_80061288
    if (ctx->r2 != 0) {
        // 0x80061264: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_80061288;
    }
    // 0x80061264: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80061268: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8006126C: jal         0x80071140
    // 0x80061270: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80061270: nop

    after_5:
    // 0x80061274: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80061278: jal         0x80071140
    // 0x8006127C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006127C: nop

    after_6:
    // 0x80061280: b           L_800619BC
    // 0x80061284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800619BC;
    // 0x80061284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061288:
    // 0x80061288: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8006128C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80061290: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x80061294: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80061298: blez        $v1, L_80061634
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006129C: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_80061634;
    }
    // 0x8006129C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800612A0: addiu       $s0, $zero, 0xFE
    ctx->r16 = ADD32(0, 0XFE);
L_800612A4:
    // 0x800612A4: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800612A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800612AC: addu        $t8, $ra, $t6
    ctx->r24 = ADD32(ctx->r31, ctx->r14);
    // 0x800612B0: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800612B4: lh          $t7, 0xE($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XE);
    // 0x800612B8: lh          $t3, 0x2($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X2);
    // 0x800612BC: nop

    // 0x800612C0: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800612C4: beq         $at, $zero, L_8006161C
    if (ctx->r1 == 0) {
        // 0x800612C8: nop
    
            goto L_8006161C;
    }
    // 0x800612C8: nop

    // 0x800612CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800612D0:
    // 0x800612D0: nop

    // 0x800612D4: lbu         $t4, 0x6($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X6);
    // 0x800612D8: nop

    // 0x800612DC: slti        $at, $t4, 0xFE
    ctx->r1 = SIGNED(ctx->r12) < 0XFE ? 1 : 0;
    // 0x800612E0: beq         $at, $zero, L_80061444
    if (ctx->r1 == 0) {
        // 0x800612E4: nop
    
            goto L_80061444;
    }
    // 0x800612E4: nop

    // 0x800612E8: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800612EC: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x800612F0: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800612F4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800612F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800612FC: mflo        $t9
    ctx->r25 = lo;
    // 0x80061300: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x80061304: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80061308: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x8006130C: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80061310: bltz        $s1, L_80061414
    if (SIGNED(ctx->r17) < 0) {
        // 0x80061314: nop
    
            goto L_80061414;
    }
    // 0x80061314: nop

L_80061318:
    // 0x80061318: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006131C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061320: addu        $a3, $ra, $t7
    ctx->r7 = ADD32(ctx->r31, ctx->r15);
    // 0x80061324: lbu         $t6, 0x6($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6);
    // 0x80061328: nop

    // 0x8006132C: bne         $t4, $t6, L_800613F4
    if (ctx->r12 != ctx->r14) {
        // 0x80061330: nop
    
            goto L_800613F4;
    }
    // 0x80061330: nop

    // 0x80061334: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x80061338: bne         $a1, $s1, L_80061348
    if (ctx->r5 != ctx->r17) {
        // 0x8006133C: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80061348;
    }
    // 0x8006133C: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061340: bne         $at, $zero, L_80061364
    if (ctx->r1 != 0) {
        // 0x80061344: nop
    
            goto L_80061364;
    }
    // 0x80061344: nop

L_80061348:
    // 0x80061348: beq         $a1, $s1, L_800613F4
    if (ctx->r5 == ctx->r17) {
        // 0x8006134C: nop
    
            goto L_800613F4;
    }
    // 0x8006134C: nop

    // 0x80061350: lh          $t8, 0xE($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XE);
    // 0x80061354: nop

    // 0x80061358: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006135C: beq         $at, $zero, L_800613F4
    if (ctx->r1 == 0) {
        // 0x80061360: nop
    
            goto L_800613F4;
    }
    // 0x80061360: nop

L_80061364:
    // 0x80061364: bgez        $a2, L_800613F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061368: nop
    
            goto L_800613F4;
    }
    // 0x80061368: nop

L_8006136C:
    // 0x8006136C: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061370: mflo        $t9
    ctx->r25 = lo;
    // 0x80061374: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x80061378: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x8006137C: nop

    // 0x80061380: bne         $t0, $t7, L_800613B0
    if (ctx->r8 != ctx->r15) {
        // 0x80061384: nop
    
            goto L_800613B0;
    }
    // 0x80061384: nop

    // 0x80061388: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8006138C: nop

    // 0x80061390: bne         $t1, $t6, L_800613B0
    if (ctx->r9 != ctx->r14) {
        // 0x80061394: nop
    
            goto L_800613B0;
    }
    // 0x80061394: nop

    // 0x80061398: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x8006139C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800613A0: bne         $t2, $t8, L_800613B0
    if (ctx->r10 != ctx->r24) {
        // 0x800613A4: addu        $t7, $v0, $t9
        ctx->r15 = ADD32(ctx->r2, ctx->r25);
            goto L_800613B0;
    }
    // 0x800613A4: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800613A8: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x800613AC: nop

L_800613B0:
    // 0x800613B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800613B4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800613B8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800613BC: bne         $a1, $s1, L_800613D0
    if (ctx->r5 != ctx->r17) {
        // 0x800613C0: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800613D0;
    }
    // 0x800613C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800613C4: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800613C8: bne         $at, $zero, L_800613EC
    if (ctx->r1 != 0) {
        // 0x800613CC: nop
    
            goto L_800613EC;
    }
    // 0x800613CC: nop

L_800613D0:
    // 0x800613D0: beq         $a1, $s1, L_800613F4
    if (ctx->r5 == ctx->r17) {
        // 0x800613D4: nop
    
            goto L_800613F4;
    }
    // 0x800613D4: nop

    // 0x800613D8: lh          $t9, 0xE($a3)
    ctx->r25 = MEM_H(ctx->r7, 0XE);
    // 0x800613DC: nop

    // 0x800613E0: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800613E4: beq         $at, $zero, L_800613F4
    if (ctx->r1 == 0) {
        // 0x800613E8: nop
    
            goto L_800613F4;
    }
    // 0x800613E8: nop

L_800613EC:
    // 0x800613EC: bltz        $a2, L_8006136C
    if (SIGNED(ctx->r6) < 0) {
        // 0x800613F0: nop
    
            goto L_8006136C;
    }
    // 0x800613F0: nop

L_800613F4:
    // 0x800613F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800613F8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800613FC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061400: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061404: bne         $at, $zero, L_80061414
    if (ctx->r1 != 0) {
        // 0x80061408: nop
    
            goto L_80061414;
    }
    // 0x80061408: nop

    // 0x8006140C: bltz        $a2, L_80061318
    if (SIGNED(ctx->r6) < 0) {
        // 0x80061410: nop
    
            goto L_80061318;
    }
    // 0x80061410: nop

L_80061414:
    // 0x80061414: bgez        $a2, L_80061438
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061418: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_80061438;
    }
    // 0x80061418: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8006141C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80061420: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80061424: sh          $s6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r22;
    // 0x80061428: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8006142C: sll         $t7, $s6, 16
    ctx->r15 = S32(ctx->r22 << 16);
    // 0x80061430: b           L_800615EC
    // 0x80061434: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
        goto L_800615EC;
    // 0x80061434: sra         $s6, $t7, 16
    ctx->r22 = S32(SIGNED(ctx->r15) >> 16);
L_80061438:
    // 0x80061438: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8006143C: b           L_800615EC
    // 0x80061440: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
        goto L_800615EC;
    // 0x80061440: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
L_80061444:
    // 0x80061444: bne         $s0, $t4, L_80061464
    if (ctx->r16 != ctx->r12) {
        // 0x80061448: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_80061464;
    }
    // 0x80061448: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8006144C: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80061450: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x80061454: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80061458: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006145C: b           L_800615EC
    // 0x80061460: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_800615EC;
    // 0x80061460: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_80061464:
    // 0x80061464: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80061468: nop

    // 0x8006146C: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80061470: nop

    // 0x80061474: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x80061478: beq         $t8, $zero, L_800615E4
    if (ctx->r24 == 0) {
        // 0x8006147C: sll         $t8, $t3, 1
        ctx->r24 = S32(ctx->r11 << 1);
            goto L_800615E4;
    }
    // 0x8006147C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80061480: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061484: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x80061488: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006148C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80061490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061494: mflo        $t7
    ctx->r15 = lo;
    // 0x80061498: addu        $v1, $s3, $t7
    ctx->r3 = ADD32(ctx->r19, ctx->r15);
    // 0x8006149C: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800614A0: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x800614A4: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800614A8: bltz        $s1, L_800615B0
    if (SIGNED(ctx->r17) < 0) {
        // 0x800614AC: nop
    
            goto L_800615B0;
    }
    // 0x800614AC: nop

L_800614B0:
    // 0x800614B0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800614B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800614B8: addu        $a3, $ra, $t6
    ctx->r7 = ADD32(ctx->r31, ctx->r14);
    // 0x800614BC: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800614C0: nop

    // 0x800614C4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800614C8: beq         $t9, $zero, L_80061590
    if (ctx->r25 == 0) {
        // 0x800614CC: nop
    
            goto L_80061590;
    }
    // 0x800614CC: nop

    // 0x800614D0: lh          $a0, 0x2($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2);
    // 0x800614D4: bne         $a1, $s1, L_800614E4
    if (ctx->r5 != ctx->r17) {
        // 0x800614D8: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800614E4;
    }
    // 0x800614D8: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800614DC: bne         $at, $zero, L_80061500
    if (ctx->r1 != 0) {
        // 0x800614E0: nop
    
            goto L_80061500;
    }
    // 0x800614E0: nop

L_800614E4:
    // 0x800614E4: beq         $a1, $s1, L_80061590
    if (ctx->r5 == ctx->r17) {
        // 0x800614E8: nop
    
            goto L_80061590;
    }
    // 0x800614E8: nop

    // 0x800614EC: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x800614F0: nop

    // 0x800614F4: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800614F8: beq         $at, $zero, L_80061590
    if (ctx->r1 == 0) {
        // 0x800614FC: nop
    
            goto L_80061590;
    }
    // 0x800614FC: nop

L_80061500:
    // 0x80061500: bgez        $a2, L_80061590
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80061504: nop
    
            goto L_80061590;
    }
    // 0x80061504: nop

L_80061508:
    // 0x80061508: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006150C: mflo        $t6
    ctx->r14 = lo;
    // 0x80061510: addu        $v1, $s3, $t6
    ctx->r3 = ADD32(ctx->r19, ctx->r14);
    // 0x80061514: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80061518: nop

    // 0x8006151C: bne         $t0, $t8, L_8006154C
    if (ctx->r8 != ctx->r24) {
        // 0x80061520: nop
    
            goto L_8006154C;
    }
    // 0x80061520: nop

    // 0x80061524: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80061528: nop

    // 0x8006152C: bne         $t1, $t9, L_8006154C
    if (ctx->r9 != ctx->r25) {
        // 0x80061530: nop
    
            goto L_8006154C;
    }
    // 0x80061530: nop

    // 0x80061534: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80061538: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8006153C: bne         $t2, $t7, L_8006154C
    if (ctx->r10 != ctx->r15) {
        // 0x80061540: addu        $t8, $v0, $t6
        ctx->r24 = ADD32(ctx->r2, ctx->r14);
            goto L_8006154C;
    }
    // 0x80061540: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80061544: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x80061548: nop

L_8006154C:
    // 0x8006154C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80061550: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80061554: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061558: bne         $a1, $s1, L_8006156C
    if (ctx->r5 != ctx->r17) {
        // 0x8006155C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8006156C;
    }
    // 0x8006155C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80061560: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061564: bne         $at, $zero, L_80061588
    if (ctx->r1 != 0) {
        // 0x80061568: nop
    
            goto L_80061588;
    }
    // 0x80061568: nop

L_8006156C:
    // 0x8006156C: beq         $a1, $s1, L_80061590
    if (ctx->r5 == ctx->r17) {
        // 0x80061570: nop
    
            goto L_80061590;
    }
    // 0x80061570: nop

    // 0x80061574: lh          $t6, 0xE($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XE);
    // 0x80061578: nop

    // 0x8006157C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80061580: beq         $at, $zero, L_80061590
    if (ctx->r1 == 0) {
        // 0x80061584: nop
    
            goto L_80061590;
    }
    // 0x80061584: nop

L_80061588:
    // 0x80061588: bltz        $a2, L_80061508
    if (SIGNED(ctx->r6) < 0) {
        // 0x8006158C: nop
    
            goto L_80061508;
    }
    // 0x8006158C: nop

L_80061590:
    // 0x80061590: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80061594: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80061598: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006159C: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800615A0: bne         $at, $zero, L_800615B0
    if (ctx->r1 != 0) {
        // 0x800615A4: nop
    
            goto L_800615B0;
    }
    // 0x800615A4: nop

    // 0x800615A8: bltz        $a2, L_800614B0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800615AC: nop
    
            goto L_800614B0;
    }
    // 0x800615AC: nop

L_800615B0:
    // 0x800615B0: bgez        $a2, L_800615D4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800615B4: sll         $t7, $t3, 1
        ctx->r15 = S32(ctx->r11 << 1);
            goto L_800615D4;
    }
    // 0x800615B4: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800615B8: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x800615BC: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x800615C0: sh          $s6, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r22;
    // 0x800615C4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800615C8: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x800615CC: b           L_800615EC
    // 0x800615D0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
        goto L_800615EC;
    // 0x800615D0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
L_800615D4:
    // 0x800615D4: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x800615D8: b           L_800615EC
    // 0x800615DC: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
        goto L_800615EC;
    // 0x800615DC: sh          $a2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r6;
    // 0x800615E0: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
L_800615E4:
    // 0x800615E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800615E8: sh          $s4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r20;
L_800615EC:
    // 0x800615EC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800615F0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800615F4: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x800615F8: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x800615FC: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80061600: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061604: bne         $at, $zero, L_800612D0
    if (ctx->r1 != 0) {
        // 0x80061608: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800612D0;
    }
    // 0x80061608: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8006160C: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x80061610: nop

    // 0x80061614: lh          $v1, 0x28($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X28);
    // 0x80061618: nop

L_8006161C:
    // 0x8006161C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80061620: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x80061624: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061628: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006162C: bne         $at, $zero, L_800612A4
    if (ctx->r1 != 0) {
        // 0x80061630: nop
    
            goto L_800612A4;
    }
    // 0x80061630: nop

L_80061634:
    // 0x80061634: sll         $a0, $s6, 2
    ctx->r4 = S32(ctx->r22 << 2);
    // 0x80061638: subu        $a0, $a0, $s6
    ctx->r4 = SUB32(ctx->r4, ctx->r22);
    // 0x8006163C: lui         $a1, 0xFF7F
    ctx->r5 = S32(0XFF7F << 16);
    // 0x80061640: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80061644: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80061648: jal         0x80070D10
    // 0x8006164C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    mempool_alloc(rdram, ctx);
        goto after_7;
    // 0x8006164C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_7:
    // 0x80061650: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80061654: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061658: bne         $v0, $zero, L_80061688
    if (ctx->r2 != 0) {
        // 0x8006165C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80061688;
    }
    // 0x8006165C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80061660: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80061664: jal         0x80071140
    // 0x80061668: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x80061668: nop

    after_8:
    // 0x8006166C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80061670: jal         0x80071140
    // 0x80061674: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x80061674: nop

    after_9:
    // 0x80061678: jal         0x80071140
    // 0x8006167C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x8006167C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x80061680: b           L_800619BC
    // 0x80061684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800619BC;
    // 0x80061684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061688:
    // 0x80061688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006168C: blez        $s6, L_800616C0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80061690: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800616C0;
    }
    // 0x80061690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80061694:
    // 0x80061694: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061698: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006169C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800616A0: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800616A4: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800616A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800616AC: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800616B0: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x800616B4: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x800616B8: bne         $at, $zero, L_80061694
    if (ctx->r1 != 0) {
        // 0x800616BC: swc1        $f20, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
            goto L_80061694;
    }
    // 0x800616BC: swc1        $f20, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f20.u32l;
L_800616C0:
    // 0x800616C0: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x800616C4: nop

    // 0x800616C8: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x800616CC: nop

    // 0x800616D0: blez        $v1, L_80061810
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800616D4: nop
    
            goto L_80061810;
    }
    // 0x800616D4: nop

L_800616D8:
    // 0x800616D8: multu       $s1, $t5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800616DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800616E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800616E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800616E8: addu        $t0, $ra, $t9
    ctx->r8 = ADD32(ctx->r31, ctx->r25);
    // 0x800616EC: lbu         $t7, 0x6($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X6);
    // 0x800616F0: nop

    // 0x800616F4: bne         $t7, $at, L_80061710
    if (ctx->r15 != ctx->r1) {
        // 0x800616F8: nop
    
            goto L_80061710;
    }
    // 0x800616F8: nop

    // 0x800616FC: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x80061700: nop

    // 0x80061704: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x80061708: beq         $t8, $zero, L_80061800
    if (ctx->r24 == 0) {
        // 0x8006170C: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061800;
    }
    // 0x8006170C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061710:
    // 0x80061710: lh          $s5, 0x4($t0)
    ctx->r21 = MEM_H(ctx->r8, 0X4);
    // 0x80061714: lh          $t9, 0x10($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X10);
    // 0x80061718: lh          $s4, 0x2($t0)
    ctx->r20 = MEM_H(ctx->r8, 0X2);
    // 0x8006171C: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061720: beq         $at, $zero, L_80061800
    if (ctx->r1 == 0) {
        // 0x80061724: sll         $t8, $s1, 16
        ctx->r24 = S32(ctx->r17 << 16);
            goto L_80061800;
    }
    // 0x80061724: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x80061728: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8006172C: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x80061730: nop

    // 0x80061734: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
L_80061738:
    // 0x80061738: addu        $a0, $t1, $t7
    ctx->r4 = ADD32(ctx->r9, ctx->r15);
    // 0x8006173C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80061740: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
L_80061744:
    // 0x80061744: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x80061748: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006174C: addu        $a2, $t8, $s4
    ctx->r6 = ADD32(ctx->r24, ctx->r20);
    // 0x80061750: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80061754: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061758: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8006175C: addu        $t8, $s7, $t6
    ctx->r24 = ADD32(ctx->r23, ctx->r14);
    // 0x80061760: lh          $a2, 0x0($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X0);
    // 0x80061764: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80061768: bltz        $a2, L_800617C4
    if (SIGNED(ctx->r6) < 0) {
        // 0x8006176C: sra         $a3, $t6, 16
        ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800617C4;
    }
    // 0x8006176C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80061770: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061774: mflo        $t9
    ctx->r25 = lo;
    // 0x80061778: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x8006177C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80061780: multu       $s5, $t5
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061784: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80061788: mflo        $t7
    ctx->r15 = lo;
    // 0x8006178C: addu        $s0, $a1, $t7
    ctx->r16 = ADD32(ctx->r5, ctx->r15);
    // 0x80061790: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061794: nop

    // 0x80061798: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8006179C: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800617A0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800617A4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800617A8: nop

    // 0x800617AC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800617B0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800617B4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800617B8: nop

    // 0x800617BC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800617C0: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_800617C4:
    // 0x800617C4: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800617C8: bne         $at, $zero, L_80061744
    if (ctx->r1 != 0) {
        // 0x800617CC: addu        $t6, $a0, $a3
        ctx->r14 = ADD32(ctx->r4, ctx->r7);
            goto L_80061744;
    }
    // 0x800617CC: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
    // 0x800617D0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800617D4: lh          $v1, 0x10($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X10);
    // 0x800617D8: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x800617DC: sra         $s5, $t9, 16
    ctx->r21 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800617E0: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800617E4: bne         $at, $zero, L_80061738
    if (ctx->r1 != 0) {
        // 0x800617E8: sll         $t7, $s5, 4
        ctx->r15 = S32(ctx->r21 << 4);
            goto L_80061738;
    }
    // 0x800617E8: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x800617EC: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800617F0: nop

    // 0x800617F4: lh          $v1, 0x28($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X28);
    // 0x800617F8: nop

    // 0x800617FC: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
L_80061800:
    // 0x80061800: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061804: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80061808: bne         $at, $zero, L_800616D8
    if (ctx->r1 != 0) {
        // 0x8006180C: nop
    
            goto L_800616D8;
    }
    // 0x8006180C: nop

L_80061810:
    // 0x80061810: blez        $s6, L_800618B0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80061814: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800618B0;
    }
    // 0x80061814: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80061818:
    // 0x80061818: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006181C: mflo        $t7
    ctx->r15 = lo;
    // 0x80061820: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x80061824: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80061828: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006182C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80061830: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061834: sh          $a3, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r7;
    // 0x80061838: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006183C: nop

    // 0x80061840: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80061844: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80061848: jal         0x800C9AD0
    // 0x8006184C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x8006184C: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_11:
    // 0x80061850: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80061854: lh          $a3, 0x98($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X98);
    // 0x80061858: bc1t        L_80061894
    if (c1cs) {
        // 0x8006185C: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_80061894;
    }
    // 0x8006185C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80061860: lui         $at, 0x3900
    ctx->r1 = S32(0X3900 << 16);
    // 0x80061864: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061868: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006186C: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80061870: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80061874: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80061878: div.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006187C: nop

    // 0x80061880: div.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80061884: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80061888: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006188C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80061890: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80061894:
    // 0x80061894: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80061898: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8006189C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800618A0: slt         $at, $a3, $s6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800618A4: bne         $at, $zero, L_80061818
    if (ctx->r1 != 0) {
        // 0x800618A8: nop
    
            goto L_80061818;
    }
    // 0x800618A8: nop

    // 0x800618AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800618B0:
    // 0x800618B0: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800618B4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800618B8: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x800618BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800618C0: blez        $a1, L_80061994
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800618C4: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80061994;
    }
    // 0x800618C4: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800618C8: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_800618CC:
    // 0x800618CC: addu        $t7, $s7, $t9
    ctx->r15 = ADD32(ctx->r23, ctx->r25);
    // 0x800618D0: lh          $a2, 0x0($t7)
    ctx->r6 = MEM_H(ctx->r15, 0X0);
    // 0x800618D4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800618D8: bltz        $a2, L_80061984
    if (SIGNED(ctx->r6) < 0) {
        // 0x800618DC: sll         $t9, $a3, 16
        ctx->r25 = S32(ctx->r7 << 16);
            goto L_80061984;
    }
    // 0x800618DC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800618E0: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800618E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800618E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800618EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800618F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800618F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800618F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800618FC: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x80061900: nop

    // 0x80061904: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061908: mflo        $t8
    ctx->r24 = lo;
    // 0x8006190C: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x80061910: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80061914: nop

    // 0x80061918: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006191C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061920: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80061924: nop

    // 0x80061928: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006192C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80061930: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80061934: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80061938: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006193C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80061940: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80061944: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80061948: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006194C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80061950: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80061954: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80061958: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006195C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80061960: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80061964: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80061968: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006196C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80061970: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80061974: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80061978: lh          $a1, 0x24($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X24);
    // 0x8006197C: nop

    // 0x80061980: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
L_80061984:
    // 0x80061984: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061988: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006198C: bne         $at, $zero, L_800618CC
    if (ctx->r1 != 0) {
        // 0x80061990: sll         $t9, $a3, 1
        ctx->r25 = S32(ctx->r7 << 1);
            goto L_800618CC;
    }
    // 0x80061990: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
L_80061994:
    // 0x80061994: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80061998: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8006199C: jal         0x80071140
    // 0x800619A0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x800619A0: sw          $t1, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->r9;
    after_12:
    // 0x800619A4: jal         0x80071140
    // 0x800619A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800619A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x800619AC: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x800619B0: jal         0x80071140
    // 0x800619B4: nop

    mempool_free(rdram, ctx);
        goto after_14;
    // 0x800619B4: nop

    after_14:
L_800619B8:
    // 0x800619B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800619BC:
    // 0x800619BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800619C0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800619C4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800619C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800619CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800619D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800619D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800619D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800619DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800619E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800619E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800619E8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800619EC: jr          $ra
    // 0x800619F0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800619F0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void set_course_finish_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A7D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001A7DC: lw          $t6, -0x5118($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5118);
    // 0x8001A7E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A7E4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001A7E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001A7EC: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x8001A7F0: addiu       $v1, $v1, -0x523C
    ctx->r3 = ADD32(ctx->r3, -0X523C);
    // 0x8001A7F4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8001A7F8: nop

    // 0x8001A7FC: bne         $t8, $at, L_8001A80C
    if (ctx->r24 != ctx->r1) {
        // 0x8001A800: nop
    
            goto L_8001A80C;
    }
    // 0x8001A800: nop

    // 0x8001A804: jr          $ra
    // 0x8001A808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A80C:
    // 0x8001A80C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8001A810: lbu         $t0, 0x49($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A814: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8001A818: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001A81C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001A820: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001A824: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001A828: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x8001A82C: bne         $t4, $zero, L_8001A86C
    if (ctx->r12 != 0) {
        // 0x8001A830: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8001A86C;
    }
    // 0x8001A830: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001A834: lbu         $t5, -0x510B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X510B);
    // 0x8001A838: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001A83C: bne         $t5, $zero, L_8001A8C4
    if (ctx->r13 != 0) {
        // 0x8001A840: nop
    
            goto L_8001A8C4;
    }
    // 0x8001A840: nop

    // 0x8001A844: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001A848: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A84C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001A850: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8001A854: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x8001A858: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8001A85C: nop

    // 0x8001A860: ori         $t1, $t9, 0x2
    ctx->r9 = ctx->r25 | 0X2;
    // 0x8001A864: b           L_8001A8C4
    // 0x8001A868: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8001A8C4;
    // 0x8001A868: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8001A86C:
    // 0x8001A86C: lb          $t2, -0x51FD($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X51FD);
    // 0x8001A870: nop

    // 0x8001A874: beq         $t2, $zero, L_8001A8C4
    if (ctx->r10 == 0) {
        // 0x8001A878: nop
    
            goto L_8001A8C4;
    }
    // 0x8001A878: nop

    // 0x8001A87C: lb          $t3, 0x202($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X202);
    // 0x8001A880: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A884: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x8001A888: bne         $at, $zero, L_8001A8C4
    if (ctx->r1 != 0) {
        // 0x8001A88C: nop
    
            goto L_8001A8C4;
    }
    // 0x8001A88C: nop

    // 0x8001A890: lbu         $t4, -0x510B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X510B);
    // 0x8001A894: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001A898: bne         $t4, $zero, L_8001A8C4
    if (ctx->r12 != 0) {
        // 0x8001A89C: nop
    
            goto L_8001A8C4;
    }
    // 0x8001A89C: nop

    // 0x8001A8A0: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8001A8A4: lbu         $t8, 0x49($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X49);
    // 0x8001A8A8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001A8AC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8001A8B0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A8B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8001A8B8: nop

    // 0x8001A8BC: ori         $t9, $t0, 0x4
    ctx->r25 = ctx->r8 | 0X4;
    // 0x8001A8C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001A8C4:
    // 0x8001A8C4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001A8C8: nop

    // 0x8001A8CC: jr          $ra
    // 0x8001A8D0: nop

    return;
    // 0x8001A8D0: nop

;}
RECOMP_FUNC void func_80080E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080E90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80080E94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80080E98: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80080E9C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80080EA0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80080EA4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80080EA8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80080EAC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80080EB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80080EB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80080EB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080EBC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80080EC0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80080EC4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80080EC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80080ECC: addiu       $t8, $t8, 0x1C70
    ctx->r24 = ADD32(ctx->r24, 0X1C70);
    // 0x80080ED0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80080ED4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80080ED8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80080EDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80080EE0: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x80080EE4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80080EE8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80080EEC: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080EF0: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080EF4: addiu       $t7, $t7, 0x1CC0
    ctx->r15 = ADD32(ctx->r15, 0X1CC0);
    // 0x80080EF8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80080EFC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80080F00: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80080F04: lw          $fp, 0x54($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X54);
    // 0x80080F08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80080F0C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80080F10: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80080F14: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80080F18: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80080F1C: lui         $s1, 0xF600
    ctx->r17 = S32(0XF600 << 16);
L_80080F20:
    // 0x80080F20: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80080F24: addiu       $t6, $t6, 0x1DC8
    ctx->r14 = ADD32(ctx->r14, 0X1DC8);
    // 0x80080F28: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x80080F2C: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x80080F30: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80080F34: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x80080F38: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x80080F3C: lh          $ra, 0x6($v0)
    ctx->r31 = MEM_H(ctx->r2, 0X6);
    // 0x80080F40: or          $t1, $s5, $zero
    ctx->r9 = ctx->r21 | 0;
    // 0x80080F44: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80080F48: beq         $s4, $zero, L_80080F88
    if (ctx->r20 == 0) {
        // 0x80080F4C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80080F88;
    }
    // 0x80080F4C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80080F50: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80080F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80080F58: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
    // 0x80080F5C: beq         $s4, $at, L_80080F9C
    if (ctx->r20 == ctx->r1) {
        // 0x80080F60: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_80080F9C;
    }
    // 0x80080F60: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80080F64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80080F68: beq         $s4, $at, L_80080FBC
    if (ctx->r20 == ctx->r1) {
        // 0x80080F6C: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80080FBC;
    }
    // 0x80080F6C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80080F70: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80080F74: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x80080F78: addiu       $a3, $s5, 0x1
    ctx->r7 = ADD32(ctx->r21, 0X1);
    // 0x80080F7C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80080F80: b           L_80080FCC
    // 0x80080F84: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_80080FCC;
    // 0x80080F84: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_80080F88:
    // 0x80080F88: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80080F8C: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80080F90: addiu       $t0, $s3, 0x1
    ctx->r8 = ADD32(ctx->r19, 0X1);
    // 0x80080F94: b           L_80080FCC
    // 0x80080F98: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
        goto L_80080FCC;
    // 0x80080F98: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_80080F9C:
    // 0x80080F9C: addu        $t1, $s5, $s6
    ctx->r9 = ADD32(ctx->r21, ctx->r22);
    // 0x80080FA0: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80080FA4: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80080FA8: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x80080FAC: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80080FB0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80080FB4: b           L_80080FCC
    // 0x80080FB8: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
        goto L_80080FCC;
    // 0x80080FB8: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_80080FBC:
    // 0x80080FBC: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80080FC0: addu        $a3, $s5, $s6
    ctx->r7 = ADD32(ctx->r21, ctx->r22);
    // 0x80080FC4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80080FC8: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_80080FCC:
    // 0x80080FCC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80080FD0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80080FD4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80080FD8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80080FDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80080FE0: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80080FE4: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80080FE8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80080FEC: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80080FF0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80080FF4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80080FF8: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80080FFC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80081000: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80081004: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80081008: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8008100C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80081010: blez        $s2, L_8008119C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80081014: sw          $t9, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r25;
            goto L_8008119C;
    }
    // 0x80081014: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80081018: andi        $v0, $s2, 0x1
    ctx->r2 = ctx->r18 & 0X1;
    // 0x8008101C: beq         $v0, $zero, L_800810A4
    if (ctx->r2 == 0) {
        // 0x80081020: nop
    
            goto L_800810A4;
    }
    // 0x80081020: nop

    // 0x80081024: bltz        $a3, L_80081090
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081028: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80081090;
    }
    // 0x80081028: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008102C: bltz        $t0, L_80081090
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081030: andi        $t6, $a3, 0x3FF
        ctx->r14 = ctx->r7 & 0X3FF;
            goto L_80081090;
    }
    // 0x80081030: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x80081034: bgez        $t1, L_80081044
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081038: sll         $t8, $t6, 14
        ctx->r24 = S32(ctx->r14 << 14);
            goto L_80081044;
    }
    // 0x80081038: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8008103C: b           L_80081048
    // 0x80081040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081048;
    // 0x80081040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80081044:
    // 0x80081044: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081048:
    // 0x80081048: bgez        $a2, L_80081058
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008104C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80081058;
    }
    // 0x8008104C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081050: b           L_80081058
    // 0x80081054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80081058;
    // 0x80081054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80081058:
    // 0x80081058: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8008105C: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x80081060: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80081064: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80081068: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x8008106C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80081070: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80081074: andi        $t6, $a0, 0x3FF
    ctx->r14 = ctx->r4 & 0X3FF;
    // 0x80081078: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x8008107C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081080: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80081084: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80081088: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8008108C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80081090:
    // 0x80081090: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80081094: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x80081098: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x8008109C: beq         $t2, $s2, L_8008119C
    if (ctx->r10 == ctx->r18) {
        // 0x800810A0: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_8008119C;
    }
    // 0x800810A0: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_800810A4:
    // 0x800810A4: bltz        $a3, L_80081110
    if (SIGNED(ctx->r7) < 0) {
        // 0x800810A8: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80081110;
    }
    // 0x800810A8: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800810AC: bltz        $t0, L_80081110
    if (SIGNED(ctx->r8) < 0) {
        // 0x800810B0: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_80081110;
    }
    // 0x800810B0: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800810B4: bgez        $t1, L_800810C4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800810B8: sll         $t8, $t9, 14
        ctx->r24 = S32(ctx->r25 << 14);
            goto L_800810C4;
    }
    // 0x800810B8: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800810BC: b           L_800810C8
    // 0x800810C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800810C8;
    // 0x800810C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800810C4:
    // 0x800810C4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_800810C8:
    // 0x800810C8: bgez        $a2, L_800810D8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800810CC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800810D8;
    }
    // 0x800810CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800810D0: b           L_800810D8
    // 0x800810D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800810D8;
    // 0x800810D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800810D8:
    // 0x800810D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800810DC: or          $t7, $t8, $s1
    ctx->r15 = ctx->r24 | ctx->r17;
    // 0x800810E0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800810E4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800810E8: andi        $t6, $t0, 0x3FF
    ctx->r14 = ctx->r8 & 0X3FF;
    // 0x800810EC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800810F0: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800810F4: andi        $t9, $a0, 0x3FF
    ctx->r25 = ctx->r4 & 0X3FF;
    // 0x800810F8: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x800810FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081100: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80081104: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80081108: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8008110C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80081110:
    // 0x80081110: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80081114: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80081118: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008111C: bltz        $a3, L_80081188
    if (SIGNED(ctx->r7) < 0) {
        // 0x80081120: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_80081188;
    }
    // 0x80081120: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
    // 0x80081124: bltz        $t0, L_80081188
    if (SIGNED(ctx->r8) < 0) {
        // 0x80081128: andi        $t7, $a3, 0x3FF
        ctx->r15 = ctx->r7 & 0X3FF;
            goto L_80081188;
    }
    // 0x80081128: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x8008112C: bgez        $t1, L_8008113C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80081130: sll         $t8, $t7, 14
        ctx->r24 = S32(ctx->r15 << 14);
            goto L_8008113C;
    }
    // 0x80081130: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80081134: b           L_80081140
    // 0x80081138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80081140;
    // 0x80081138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008113C:
    // 0x8008113C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80081140:
    // 0x80081140: bgez        $a2, L_80081150
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80081144: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80081150;
    }
    // 0x80081144: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80081148: b           L_80081150
    // 0x8008114C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80081150;
    // 0x8008114C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80081150:
    // 0x80081150: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80081154: or          $t6, $t8, $s1
    ctx->r14 = ctx->r24 | ctx->r17;
    // 0x80081158: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8008115C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80081160: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x80081164: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80081168: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8008116C: andi        $t7, $a0, 0x3FF
    ctx->r15 = ctx->r4 & 0X3FF;
    // 0x80081170: andi        $t9, $a1, 0x3FF
    ctx->r25 = ctx->r5 & 0X3FF;
    // 0x80081174: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081178: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008117C: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80081180: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80081184: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80081188:
    // 0x80081188: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x8008118C: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x80081190: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80081194: bne         $t2, $s2, L_800810A4
    if (ctx->r10 != ctx->r18) {
        // 0x80081198: addu        $t0, $t0, $ra
        ctx->r8 = ADD32(ctx->r8, ctx->r31);
            goto L_800810A4;
    }
    // 0x80081198: addu        $t0, $t0, $ra
    ctx->r8 = ADD32(ctx->r8, ctx->r31);
L_8008119C:
    // 0x8008119C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800811A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800811A4: bne         $s4, $at, L_80080F20
    if (ctx->r20 != ctx->r1) {
        // 0x800811A8: nop
    
            goto L_80080F20;
    }
    // 0x800811A8: nop

    // 0x800811AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800811B0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800811B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800811B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800811BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800811C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800811C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800811C8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800811CC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800811D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800811D4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800811D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800811DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800811E0: jal         0x8007B3D0
    // 0x800811E4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800811E4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    after_0:
    // 0x800811E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800811EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800811F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800811F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800811F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800811FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081200: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081204: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80081208: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008120C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80081210: jr          $ra
    // 0x80081214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80081214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void update_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009BF24: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009BF28: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009BF2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009BF30: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009BF34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009BF38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009BF3C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009BF40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009BF44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009BF48: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009BF4C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009BF50: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009BF54: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009BF58: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009BF5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009BF60: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009BF64: addiu       $s7, $s7, 0x6464
    ctx->r23 = ADD32(ctx->r23, 0X6464);
    // 0x8009BF68: addiu       $s6, $s6, 0x645C
    ctx->r22 = ADD32(ctx->r22, 0X645C);
    // 0x8009BF6C: addiu       $s3, $s3, 0x646C
    ctx->r19 = ADD32(ctx->r19, 0X646C);
    // 0x8009BF70: addiu       $s2, $s2, 0x6468
    ctx->r18 = ADD32(ctx->r18, 0X6468);
    // 0x8009BF74: addiu       $s1, $s1, 0x6458
    ctx->r17 = ADD32(ctx->r17, 0X6458);
    // 0x8009BF78: addiu       $s0, $s0, 0x6454
    ctx->r16 = ADD32(ctx->r16, 0X6454);
    // 0x8009BF7C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009BF80: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
L_8009BF84:
    // 0x8009BF84: jal         0x8006A59C
    // 0x8009BF88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_x(rdram, ctx);
        goto after_0;
    // 0x8009BF88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8009BF8C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8009BF90: jal         0x8006A5E0
    // 0x8009BF94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    input_clamp_stick_y(rdram, ctx);
        goto after_1;
    // 0x8009BF94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8009BF98: slti        $at, $s4, -0x23
    ctx->r1 = SIGNED(ctx->r20) < -0X23 ? 1 : 0;
    // 0x8009BF9C: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x8009BFA0: beq         $at, $zero, L_8009BFC4
    if (ctx->r1 == 0) {
        // 0x8009BFA4: sb          $zero, 0x0($s7)
        MEM_B(0X0, ctx->r23) = 0;
            goto L_8009BFC4;
    }
    // 0x8009BFA4: sb          $zero, 0x0($s7)
    MEM_B(0X0, ctx->r23) = 0;
    // 0x8009BFA8: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8009BFAC: nop

    // 0x8009BFB0: slti        $at, $t6, -0x23
    ctx->r1 = SIGNED(ctx->r14) < -0X23 ? 1 : 0;
    // 0x8009BFB4: bne         $at, $zero, L_8009BFC8
    if (ctx->r1 != 0) {
        // 0x8009BFB8: slti        $at, $s4, 0x24
        ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
            goto L_8009BFC8;
    }
    // 0x8009BFB8: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
    // 0x8009BFBC: sb          $fp, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r30;
    // 0x8009BFC0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009BFC4:
    // 0x8009BFC4: slti        $at, $s4, 0x24
    ctx->r1 = SIGNED(ctx->r20) < 0X24 ? 1 : 0;
L_8009BFC8:
    // 0x8009BFC8: bne         $at, $zero, L_8009BFEC
    if (ctx->r1 != 0) {
        // 0x8009BFCC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8009BFEC;
    }
    // 0x8009BFCC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8009BFD0: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8009BFD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009BFD8: slti        $at, $t7, 0x24
    ctx->r1 = SIGNED(ctx->r15) < 0X24 ? 1 : 0;
    // 0x8009BFDC: beq         $at, $zero, L_8009BFF0
    if (ctx->r1 == 0) {
        // 0x8009BFE0: slti        $at, $v0, -0x23
        ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
            goto L_8009BFF0;
    }
    // 0x8009BFE0: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009BFE4: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x8009BFE8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009BFEC:
    // 0x8009BFEC: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
L_8009BFF0:
    // 0x8009BFF0: beq         $at, $zero, L_8009C014
    if (ctx->r1 == 0) {
        // 0x8009BFF4: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_8009C014;
    }
    // 0x8009BFF4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009BFF8: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8009BFFC: nop

    // 0x8009C000: slti        $at, $t9, -0x23
    ctx->r1 = SIGNED(ctx->r25) < -0X23 ? 1 : 0;
    // 0x8009C004: bne         $at, $zero, L_8009C018
    if (ctx->r1 != 0) {
        // 0x8009C008: slti        $at, $v0, 0x24
        ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
            goto L_8009C018;
    }
    // 0x8009C008: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C00C: sb          $fp, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r30;
    // 0x8009C010: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C014:
    // 0x8009C014: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
L_8009C018:
    // 0x8009C018: bne         $at, $zero, L_8009C03C
    if (ctx->r1 != 0) {
        // 0x8009C01C: nop
    
            goto L_8009C03C;
    }
    // 0x8009C01C: nop

    // 0x8009C020: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8009C024: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009C028: slti        $at, $t0, 0x24
    ctx->r1 = SIGNED(ctx->r8) < 0X24 ? 1 : 0;
    // 0x8009C02C: beq         $at, $zero, L_8009C03C
    if (ctx->r1 == 0) {
        // 0x8009C030: nop
    
            goto L_8009C03C;
    }
    // 0x8009C030: nop

    // 0x8009C034: sb          $t1, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r9;
    // 0x8009C038: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C03C:
    // 0x8009C03C: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // 0x8009C040: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8009C044: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8009C048: slti        $at, $v1, -0x23
    ctx->r1 = SIGNED(ctx->r3) < -0X23 ? 1 : 0;
    // 0x8009C04C: beq         $at, $zero, L_8009C06C
    if (ctx->r1 == 0) {
        // 0x8009C050: slti        $at, $v1, 0x24
        ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
            goto L_8009C06C;
    }
    // 0x8009C050: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x8009C054: lb          $t2, 0x0($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X0);
    // 0x8009C058: nop

    // 0x8009C05C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8009C060: b           L_8009C08C
    // 0x8009C064: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
        goto L_8009C08C;
    // 0x8009C064: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
    // 0x8009C068: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
L_8009C06C:
    // 0x8009C06C: bne         $at, $zero, L_8009C088
    if (ctx->r1 != 0) {
        // 0x8009C070: nop
    
            goto L_8009C088;
    }
    // 0x8009C070: nop

    // 0x8009C074: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x8009C078: nop

    // 0x8009C07C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009C080: b           L_8009C08C
    // 0x8009C084: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
        goto L_8009C08C;
    // 0x8009C084: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
L_8009C088:
    // 0x8009C088: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C08C:
    // 0x8009C08C: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8009C090: nop

    // 0x8009C094: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8009C098: bne         $at, $zero, L_8009C0A8
    if (ctx->r1 != 0) {
        // 0x8009C09C: nop
    
            goto L_8009C0A8;
    }
    // 0x8009C09C: nop

    // 0x8009C0A0: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8009C0A4: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8009C0A8:
    // 0x8009C0A8: sb          $s4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r20;
    // 0x8009C0AC: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8009C0B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009C0B4: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8009C0B8: beq         $at, $zero, L_8009C0D4
    if (ctx->r1 == 0) {
        // 0x8009C0BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8009C0D4;
    }
    // 0x8009C0BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009C0C0: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x8009C0C4: nop

    // 0x8009C0C8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8009C0CC: b           L_8009C0F8
    // 0x8009C0D0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
        goto L_8009C0F8;
    // 0x8009C0D0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
L_8009C0D4:
    // 0x8009C0D4: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8009C0D8: bne         $at, $zero, L_8009C0F4
    if (ctx->r1 != 0) {
        // 0x8009C0DC: nop
    
            goto L_8009C0F4;
    }
    // 0x8009C0DC: nop

    // 0x8009C0E0: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x8009C0E4: nop

    // 0x8009C0E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009C0EC: b           L_8009C0F8
    // 0x8009C0F0: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_8009C0F8;
    // 0x8009C0F0: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_8009C0F4:
    // 0x8009C0F4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8009C0F8:
    // 0x8009C0F8: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x8009C0FC: nop

    // 0x8009C100: slti        $at, $t1, 0x10
    ctx->r1 = SIGNED(ctx->r9) < 0X10 ? 1 : 0;
    // 0x8009C104: bne         $at, $zero, L_8009C118
    if (ctx->r1 != 0) {
        // 0x8009C108: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8009C118;
    }
    // 0x8009C108: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009C10C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8009C110: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8009C114: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8009C118:
    // 0x8009C118: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8009C11C: bne         $s5, $at, L_8009BF84
    if (ctx->r21 != ctx->r1) {
        // 0x8009C120: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8009BF84;
    }
    // 0x8009C120: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009C124: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C128: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C12C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C130: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C134: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009C138: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009C13C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009C140: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009C144: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009C148: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009C14C: jr          $ra
    // 0x8009C150: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8009C150: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void light_update_ambience(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800337E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800337E8: addiu       $t2, $t2, -0x3698
    ctx->r10 = ADD32(ctx->r10, -0X3698);
    // 0x800337EC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800337F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800337F4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800337F8: bne         $at, $zero, L_80033A0C
    if (ctx->r1 != 0) {
        // 0x800337FC: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80033A0C;
    }
    // 0x800337FC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80033800: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80033804: addiu       $t3, $t3, -0x36A0
    ctx->r11 = ADD32(ctx->r11, -0X36A0);
    // 0x80033808: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8003380C:
    // 0x8003380C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033810: nop

    // 0x80033814: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x80033818: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    // 0x8003381C: nop

    // 0x80033820: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x80033824: bne         $at, $zero, L_800339F8
    if (ctx->r1 != 0) {
        // 0x80033828: nop
    
            goto L_800339F8;
    }
    // 0x80033828: nop

    // 0x8003382C: lw          $a3, 0x10($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X10);
    // 0x80033830: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80033834: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80033838: bne         $at, $zero, L_800338E4
    if (ctx->r1 != 0) {
        // 0x8003383C: sll         $t7, $a3, 16
        ctx->r15 = S32(ctx->r7 << 16);
            goto L_800338E4;
    }
    // 0x8003383C: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80033840: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80033844: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x80033848: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8003384C: bne         $a3, $zero, L_80033858
    if (ctx->r7 != 0) {
        // 0x80033850: nop
    
            goto L_80033858;
    }
    // 0x80033850: nop

    // 0x80033854: break       7
    do_break(2147694676);
L_80033858:
    // 0x80033858: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003385C: bne         $a3, $at, L_80033870
    if (ctx->r7 != ctx->r1) {
        // 0x80033860: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80033870;
    }
    // 0x80033860: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033864: bne         $t7, $at, L_80033870
    if (ctx->r15 != ctx->r1) {
        // 0x80033868: nop
    
            goto L_80033870;
    }
    // 0x80033868: nop

    // 0x8003386C: break       6
    do_break(2147694700);
L_80033870:
    // 0x80033870: mflo        $t0
    ctx->r8 = lo;
    // 0x80033874: nop

    // 0x80033878: nop

    // 0x8003387C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033880: mflo        $t9
    ctx->r25 = lo;
    // 0x80033884: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033888: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8003388C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80033890: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033894: nop

    // 0x80033898: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x8003389C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800338A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800338A4: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338A8: mflo        $t5
    ctx->r13 = lo;
    // 0x800338AC: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800338B0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800338B4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800338B8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800338BC: nop

    // 0x800338C0: addu        $t5, $v1, $a0
    ctx->r13 = ADD32(ctx->r3, ctx->r4);
    // 0x800338C4: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x800338C8: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800338CC: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800338D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800338D4: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800338D8: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x800338DC: b           L_80033998
    // 0x800338E0: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
        goto L_80033998;
    // 0x800338E0: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
L_800338E4:
    // 0x800338E4: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x800338E8: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800338EC: bne         $a2, $zero, L_800338F8
    if (ctx->r6 != 0) {
        // 0x800338F0: nop
    
            goto L_800338F8;
    }
    // 0x800338F0: nop

    // 0x800338F4: break       7
    do_break(2147694836);
L_800338F8:
    // 0x800338F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800338FC: bne         $a2, $at, L_80033910
    if (ctx->r6 != ctx->r1) {
        // 0x80033900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80033910;
    }
    // 0x80033900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033904: bne         $t7, $at, L_80033910
    if (ctx->r15 != ctx->r1) {
        // 0x80033908: nop
    
            goto L_80033910;
    }
    // 0x80033908: nop

    // 0x8003390C: break       6
    do_break(2147694860);
L_80033910:
    // 0x80033910: mflo        $t0
    ctx->r8 = lo;
    // 0x80033914: nop

    // 0x80033918: nop

    // 0x8003391C: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033920: mflo        $t9
    ctx->r25 = lo;
    // 0x80033924: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033928: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x8003392C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80033930: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033934: nop

    // 0x80033938: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8003393C: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80033940: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033944: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80033948: mflo        $t8
    ctx->r24 = lo;
    // 0x8003394C: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80033950: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80033954: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80033958: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8003395C: nop

    // 0x80033960: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80033964: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x80033968: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003396C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80033970: mflo        $t5
    ctx->r13 = lo;
    // 0x80033974: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80033978: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8003397C: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80033980: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80033984: nop

    // 0x80033988: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x8003398C: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x80033990: nop

    // 0x80033994: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
L_80033998:
    // 0x80033998: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8003399C: nop

    // 0x800339A0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x800339A4: nop

    // 0x800339A8: slti        $at, $t8, 0x100
    ctx->r1 = SIGNED(ctx->r24) < 0X100 ? 1 : 0;
    // 0x800339AC: bne         $at, $zero, L_800339C0
    if (ctx->r1 != 0) {
        // 0x800339B0: nop
    
            goto L_800339C0;
    }
    // 0x800339B0: nop

    // 0x800339B4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800339B8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339BC: nop

L_800339C0:
    // 0x800339C0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800339C4: nop

    // 0x800339C8: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x800339CC: bne         $at, $zero, L_800339E0
    if (ctx->r1 != 0) {
        // 0x800339D0: nop
    
            goto L_800339E0;
    }
    // 0x800339D0: nop

    // 0x800339D4: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x800339D8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800339DC: nop

L_800339E0:
    // 0x800339E0: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800339E4: nop

    // 0x800339E8: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x800339EC: bne         $at, $zero, L_800339F8
    if (ctx->r1 != 0) {
        // 0x800339F0: nop
    
            goto L_800339F8;
    }
    // 0x800339F0: nop

    // 0x800339F4: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
L_800339F8:
    // 0x800339F8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800339FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80033A00: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033A04: bne         $at, $zero, L_8003380C
    if (ctx->r1 != 0) {
        // 0x80033A08: addiu       $a0, $a0, 0x14
        ctx->r4 = ADD32(ctx->r4, 0X14);
            goto L_8003380C;
    }
    // 0x80033A08: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_80033A0C:
    // 0x80033A0C: jr          $ra
    // 0x80033A10: nop

    return;
    // 0x80033A10: nop

;}
RECOMP_FUNC void sndp_set_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003160: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80003164: bne         $at, $zero, L_80003170
    if (ctx->r1 != 0) {
        // 0x80003168: nop
    
            goto L_80003170;
    }
    // 0x80003168: nop

    // 0x8000316C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_80003170:
    // 0x80003170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003174: jr          $ra
    // 0x80003178: sw          $a0, -0x3940($at)
    MEM_W(-0X3940, ctx->r1) = ctx->r4;
    return;
    // 0x80003178: sw          $a0, -0x3940($at)
    MEM_W(-0X3940, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void strcat_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4744: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4748: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B474C: beq         $t6, $zero, L_800B4764
    if (ctx->r14 == 0) {
        // 0x800B4750: nop
    
            goto L_800B4764;
    }
    // 0x800B4750: nop

L_800B4754:
    // 0x800B4754: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4758: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B475C: bne         $t7, $zero, L_800B4754
    if (ctx->r15 != 0) {
        // 0x800B4760: nop
    
            goto L_800B4754;
    }
    // 0x800B4760: nop

L_800B4764:
    // 0x800B4764: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4768: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B476C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4770: beq         $v0, $zero, L_800B478C
    if (ctx->r2 == 0) {
        // 0x800B4774: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B478C;
    }
    // 0x800B4774: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4778:
    // 0x800B4778: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B477C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4780: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4784: bne         $v0, $zero, L_800B4778
    if (ctx->r2 != 0) {
        // 0x800B4788: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4778;
    }
    // 0x800B4788: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B478C:
    // 0x800B478C: jr          $ra
    // 0x800B4790: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4790: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void copy_viewports_to_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066610: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80066614: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80066618: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8006661C: addiu       $s7, $s7, -0x2ECC
    ctx->r23 = ADD32(ctx->r23, -0X2ECC);
    // 0x80066620: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80066624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80066628: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006662C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80066630: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80066634: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80066638: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8006663C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80066640: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80066644: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80066648: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006664C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80066650: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80066654: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80066658: addiu       $s0, $s0, -0x2F9C
    ctx->r16 = ADD32(ctx->r16, -0X2F9C);
    // 0x8006665C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80066660: addiu       $fp, $zero, -0x2
    ctx->r30 = ADD32(0, -0X2);
L_80066664:
    // 0x80066664: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80066668: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x8006666C: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x80066670: beq         $t9, $zero, L_80066688
    if (ctx->r25 == 0) {
        // 0x80066674: andi        $t1, $v1, 0x2
        ctx->r9 = ctx->r3 & 0X2;
            goto L_80066688;
    }
    // 0x80066674: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x80066678: and         $t0, $v1, $fp
    ctx->r8 = ctx->r3 & ctx->r30;
    // 0x8006667C: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80066680: b           L_80066698
    // 0x80066684: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80066698;
    // 0x80066684: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80066688:
    // 0x80066688: beq         $t1, $zero, L_80066698
    if (ctx->r9 == 0) {
        // 0x8006668C: ori         $t2, $v1, 0x1
        ctx->r10 = ctx->r3 | 0X1;
            goto L_80066698;
    }
    // 0x8006668C: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x80066690: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x80066694: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80066698:
    // 0x80066698: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x8006669C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800666A0: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800666A4: beq         $t4, $zero, L_800667D8
    if (ctx->r12 == 0) {
        // 0x800666A8: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800667D8;
    }
    // 0x800666A8: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800666AC: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x800666B0: bne         $t5, $zero, L_800666D8
    if (ctx->r13 != 0) {
        // 0x800666B4: andi        $t2, $v1, 0x10
        ctx->r10 = ctx->r3 & 0X10;
            goto L_800666D8;
    }
    // 0x800666B4: andi        $t2, $v1, 0x10
    ctx->r10 = ctx->r3 & 0X10;
    // 0x800666B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800666BC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800666C0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800666C4: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800666C8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800666CC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800666D0: b           L_800666E8
    // 0x800666D4: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
        goto L_800666E8;
    // 0x800666D4: addu        $s5, $t7, $t0
    ctx->r21 = ADD32(ctx->r15, ctx->r8);
L_800666D8:
    // 0x800666D8: lw          $s5, 0x10($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X10);
    // 0x800666DC: nop

    // 0x800666E0: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x800666E4: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
L_800666E8:
    // 0x800666E8: bne         $t2, $zero, L_80066710
    if (ctx->r10 != 0) {
        // 0x800666EC: andi        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 & 0X20;
            goto L_80066710;
    }
    // 0x800666EC: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x800666F0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800666F4: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800666F8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800666FC: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80066700: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80066704: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80066708: b           L_80066720
    // 0x8006670C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
        goto L_80066720;
    // 0x8006670C: addu        $s4, $t3, $t8
    ctx->r20 = ADD32(ctx->r11, ctx->r24);
L_80066710:
    // 0x80066710: lw          $s4, 0x14($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X14);
    // 0x80066714: nop

    // 0x80066718: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8006671C: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
L_80066720:
    // 0x80066720: bne         $t7, $zero, L_80066748
    if (ctx->r15 != 0) {
        // 0x80066724: andi        $t5, $v1, 0x40
        ctx->r13 = ctx->r3 & 0X40;
            goto L_80066748;
    }
    // 0x80066724: andi        $t5, $v1, 0x40
    ctx->r13 = ctx->r3 & 0X40;
    // 0x80066728: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8006672C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80066730: nop

    // 0x80066734: subu        $s1, $t0, $t1
    ctx->r17 = SUB32(ctx->r8, ctx->r9);
    // 0x80066738: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006673C: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    // 0x80066740: b           L_80066758
    // 0x80066744: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
        goto L_80066758;
    // 0x80066744: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
L_80066748:
    // 0x80066748: lw          $s1, 0x18($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X18);
    // 0x8006674C: nop

    // 0x80066750: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x80066754: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80066758:
    // 0x80066758: bne         $t5, $zero, L_80066780
    if (ctx->r13 != 0) {
        // 0x8006675C: nop
    
            goto L_80066780;
    }
    // 0x8006675C: nop

    // 0x80066760: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80066764: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80066768: nop

    // 0x8006676C: subu        $s2, $t6, $t3
    ctx->r18 = SUB32(ctx->r14, ctx->r11);
    // 0x80066770: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80066774: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x80066778: b           L_80066790
    // 0x8006677C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_80066790;
    // 0x8006677C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_80066780:
    // 0x80066780: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x80066784: nop

    // 0x80066788: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x8006678C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80066790:
    // 0x80066790: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80066794: nop

    // 0x80066798: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8006679C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800667A0: addu        $s3, $s6, $t0
    ctx->r19 = ADD32(ctx->r22, ctx->r8);
    // 0x800667A4: jal         0x8009C30C
    // 0x800667A8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800667A8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    after_0:
    // 0x800667AC: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800667B0: beq         $t1, $zero, L_800667BC
    if (ctx->r9 == 0) {
        // 0x800667B4: sll         $t2, $s3, 4
        ctx->r10 = S32(ctx->r19 << 4);
            goto L_800667BC;
    }
    // 0x800667B4: sll         $t2, $s3, 4
    ctx->r10 = S32(ctx->r19 << 4);
    // 0x800667B8: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
L_800667BC:
    // 0x800667BC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800667C0: addiu       $t4, $t4, -0x2EB8
    ctx->r12 = ADD32(ctx->r12, -0X2EB8);
    // 0x800667C4: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x800667C8: sh          $s5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r21;
    // 0x800667CC: sh          $s4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r20;
    // 0x800667D0: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x800667D4: sh          $s2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r18;
L_800667D8:
    // 0x800667D8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800667DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800667E0: bne         $s6, $at, L_80066664
    if (ctx->r22 != ctx->r1) {
        // 0x800667E4: addiu       $s0, $s0, 0x34
        ctx->r16 = ADD32(ctx->r16, 0X34);
            goto L_80066664;
    }
    // 0x800667E4: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x800667E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800667EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800667F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800667F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800667F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800667FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80066800: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80066804: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80066808: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006680C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80066810: jr          $ra
    // 0x80066814: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80066814: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8002B9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B9BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002B9C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B9C4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8002B9C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002B9CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002B9D0: beq         $a2, $zero, L_8002B9F0
    if (ctx->r6 == 0) {
        // 0x8002B9D4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8002B9F0;
    }
    // 0x8002B9D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002B9D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002B9DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B9E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002B9E4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002B9E8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002B9EC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002B9F0:
    // 0x8002B9F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002B9F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002B9F8: lh          $a0, 0x2E($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2E);
    // 0x8002B9FC: nop

    // 0x8002BA00: bltz        $a0, L_8002BA24
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BA04: nop
    
            goto L_8002BA24;
    }
    // 0x8002BA04: nop

    // 0x8002BA08: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x8002BA0C: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8002BA10: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BA14: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8002BA18: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BA1C: bne         $at, $zero, L_8002BA2C
    if (ctx->r1 != 0) {
        // 0x8002BA20: nop
    
            goto L_8002BA2C;
    }
    // 0x8002BA20: nop

L_8002BA24:
    // 0x8002BA24: b           L_8002BAA0
    // 0x8002BA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002BAA0;
    // 0x8002BA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BA2C:
    // 0x8002BA2C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002BA30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002BA34: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8002BA38: lb          $t0, 0x2B($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X2B);
    // 0x8002BA3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002BA40: beq         $t0, $zero, L_8002BA88
    if (ctx->r8 == 0) {
        // 0x8002BA44: nop
    
            goto L_8002BA88;
    }
    // 0x8002BA44: nop

    // 0x8002BA48: lw          $t1, -0x2C7C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C7C);
    // 0x8002BA4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002BA50: beq         $t1, $zero, L_8002BA88
    if (ctx->r9 == 0) {
        // 0x8002BA54: nop
    
            goto L_8002BA88;
    }
    // 0x8002BA54: nop

    // 0x8002BA58: bne         $a3, $at, L_8002BA88
    if (ctx->r7 != ctx->r1) {
        // 0x8002BA5C: nop
    
            goto L_8002BA88;
    }
    // 0x8002BA5C: nop

    // 0x8002BA60: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002BA64: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002BA68: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8002BA6C: lw          $a2, 0x14($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X14);
    // 0x8002BA70: jal         0x800BB2F4
    // 0x8002BA74: nop

    func_800BB2F4(rdram, ctx);
        goto after_0;
    // 0x8002BA74: nop

    after_0:
    // 0x8002BA78: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002BA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BA80: b           L_8002BAA0
    // 0x8002BA84: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
        goto L_8002BAA0;
    // 0x8002BA84: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
L_8002BA88:
    // 0x8002BA88: lh          $t4, 0x38($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X38);
    // 0x8002BA8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002BA90: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002BA94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BA98: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002BA9C: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
L_8002BAA0:
    // 0x8002BAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BAA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BAA8: jr          $ra
    // 0x8002BAAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002BAAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_gIntDisFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F570: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F574: jr          $ra
    // 0x8006F578: lbu         $v0, -0x2BD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2BD0);
    return;
    // 0x8006F578: lbu         $v0, -0x2BD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2BD0);
;}
RECOMP_FUNC void music_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B2C: jr          $ra
    // 0x80000B30: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    return;
    // 0x80000B30: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
;}
RECOMP_FUNC void racer_sound_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006ACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80006AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80006AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006ADC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80006AE0: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80006AE4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80006AE8: lw          $a1, 0x118($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X118);
    // 0x80006AEC: addiu       $s2, $s2, -0x63C8
    ctx->r18 = ADD32(ctx->r18, -0X63C8);
    // 0x80006AF0: beq         $a1, $zero, L_80006BE4
    if (ctx->r5 == 0) {
        // 0x80006AF4: sw          $a1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r5;
            goto L_80006BE4;
    }
    // 0x80006AF4: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // 0x80006AF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80006AFC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80006B00: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
L_80006B04:
    // 0x80006B04: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x80006B08: nop

    // 0x80006B0C: beq         $a0, $zero, L_80006B34
    if (ctx->r4 == 0) {
        // 0x80006B10: nop
    
            goto L_80006B34;
    }
    // 0x80006B10: nop

    // 0x80006B14: jal         0x8000488C
    // 0x80006B18: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80006B18: nop

    after_0:
    // 0x80006B1C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80006B20: nop

    // 0x80006B24: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80006B28: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x80006B2C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B30: nop

L_80006B34:
    // 0x80006B34: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80006B38: bne         $s0, $s1, L_80006B04
    if (ctx->r16 != ctx->r17) {
        // 0x80006B3C: addu        $t9, $a1, $s0
        ctx->r25 = ADD32(ctx->r5, ctx->r16);
            goto L_80006B04;
    }
    // 0x80006B3C: addu        $t9, $a1, $s0
    ctx->r25 = ADD32(ctx->r5, ctx->r16);
    // 0x80006B40: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x80006B44: nop

    // 0x80006B48: beq         $a0, $zero, L_80006B6C
    if (ctx->r4 == 0) {
        // 0x80006B4C: nop
    
            goto L_80006B6C;
    }
    // 0x80006B4C: nop

    // 0x80006B50: jal         0x8000488C
    // 0x80006B54: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x80006B54: nop

    after_1:
    // 0x80006B58: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80006B5C: nop

    // 0x80006B60: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x80006B64: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B68: nop

L_80006B6C:
    // 0x80006B6C: lw          $a0, 0xA8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XA8);
    // 0x80006B70: nop

    // 0x80006B74: beq         $a0, $zero, L_80006B98
    if (ctx->r4 == 0) {
        // 0x80006B78: nop
    
            goto L_80006B98;
    }
    // 0x80006B78: nop

    // 0x80006B7C: jal         0x8000488C
    // 0x80006B80: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80006B80: nop

    after_2:
    // 0x80006B84: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80006B88: nop

    // 0x80006B8C: sw          $zero, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = 0;
    // 0x80006B90: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80006B94: nop

L_80006B98:
    // 0x80006B98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006B9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80006BA0: addiu       $v1, $v1, -0x63C8
    ctx->r3 = ADD32(ctx->r3, -0X63C8);
    // 0x80006BA4: addiu       $v0, $v0, -0x63D0
    ctx->r2 = ADD32(ctx->r2, -0X63D0);
L_80006BA8:
    // 0x80006BA8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80006BAC: nop

    // 0x80006BB0: bne         $a1, $t4, L_80006BBC
    if (ctx->r5 != ctx->r12) {
        // 0x80006BB4: nop
    
            goto L_80006BBC;
    }
    // 0x80006BB4: nop

    // 0x80006BB8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80006BBC:
    // 0x80006BBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80006BC0: bne         $v0, $v1, L_80006BA8
    if (ctx->r2 != ctx->r3) {
        // 0x80006BC4: nop
    
            goto L_80006BA8;
    }
    // 0x80006BC4: nop

    // 0x80006BC8: jal         0x80071140
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80006BCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80006BD0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80006BD4: nop

    // 0x80006BD8: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x80006BDC: nop

    // 0x80006BE0: sw          $zero, 0x118($t6)
    MEM_W(0X118, ctx->r14) = 0;
L_80006BE4:
    // 0x80006BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006BEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006BF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80006BF4: jr          $ra
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void charselect_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A458: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A45C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006A460: addiu       $a2, $a2, 0x1150
    ctx->r6 = ADD32(ctx->r6, 0X1150);
    // 0x8006A464: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006A468: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8006A46C:
    // 0x8006A46C: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006A470: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A474: beq         $t6, $zero, L_8006A484
    if (ctx->r14 == 0) {
        // 0x8006A478: nop
    
            goto L_8006A484;
    }
    // 0x8006A478: nop

    // 0x8006A47C: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x8006A480: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A484:
    // 0x8006A484: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006A488: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006A48C: bne         $at, $zero, L_8006A46C
    if (ctx->r1 != 0) {
        // 0x8006A490: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006A46C;
    }
    // 0x8006A490: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006A494: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006A498: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8006A49C: bne         $t8, $zero, L_8006A4AC
    if (ctx->r24 != 0) {
        // 0x8006A4A0: addu        $t9, $a2, $v0
        ctx->r25 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A4AC;
    }
    // 0x8006A4A0: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A4A4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8006A4A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A4AC:
    // 0x8006A4AC: lb          $t0, 0x1($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X1);
    // 0x8006A4B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006A4B4: bne         $t0, $zero, L_8006A4C4
    if (ctx->r8 != 0) {
        // 0x8006A4B8: addu        $t2, $a2, $v0
        ctx->r10 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A4C4;
    }
    // 0x8006A4B8: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A4BC: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x8006A4C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A4C4:
    // 0x8006A4C4: lb          $t3, 0x2($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X2);
    // 0x8006A4C8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8006A4CC: bne         $t3, $zero, L_8006A4DC
    if (ctx->r11 != 0) {
        // 0x8006A4D0: addu        $t5, $a2, $v0
        ctx->r13 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A4DC;
    }
    // 0x8006A4D0: addu        $t5, $a2, $v0
    ctx->r13 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A4D4: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x8006A4D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006A4DC:
    // 0x8006A4DC: lb          $t6, 0x3($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X3);
    // 0x8006A4E0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006A4E4: bne         $t6, $zero, L_8006A4F0
    if (ctx->r14 != 0) {
        // 0x8006A4E8: addu        $t8, $a2, $v0
        ctx->r24 = ADD32(ctx->r6, ctx->r2);
            goto L_8006A4F0;
    }
    // 0x8006A4E8: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x8006A4EC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_8006A4F0:
    // 0x8006A4F0: jr          $ra
    // 0x8006A4F4: nop

    return;
    // 0x8006A4F4: nop

;}
RECOMP_FUNC void timetrial_load_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800599BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800599C0: lb          $v1, -0x2A64($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2A64);
    // 0x800599C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800599C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800599CC: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800599D0: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800599D4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800599D8: lw          $t2, -0x2A70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2A70);
    // 0x800599DC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800599E0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800599E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800599E8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800599EC: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800599F0: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x800599F4: addiu       $t0, $sp, 0x2E
    ctx->r8 = ADD32(ctx->r29, 0X2E);
    // 0x800599F8: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800599FC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80059A00: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80059A04: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80059A08: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80059A0C: jal         0x80074B34
    // 0x80059A10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80074B34(rdram, ctx);
        goto after_0;
    // 0x80059A10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80059A14: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80059A18: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80059A1C: beq         $t3, $zero, L_80059A58
    if (ctx->r11 == 0) {
        // 0x80059A20: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80059A58;
    }
    // 0x80059A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80059A24: bne         $v0, $zero, L_80059A50
    if (ctx->r2 != 0) {
        // 0x80059A28: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80059A50;
    }
    // 0x80059A28: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80059A2C: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80059A30: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x80059A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A38: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80059A3C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80059A40: sh          $t4, -0x2A60($at)
    MEM_H(-0X2A60, ctx->r1) = ctx->r12;
    // 0x80059A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A48: b           L_80059A58
    // 0x80059A4C: sh          $t6, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r14;
        goto L_80059A58;
    // 0x80059A4C: sh          $t6, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r14;
L_80059A50:
    // 0x80059A50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059A54: sh          $t7, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r15;
L_80059A58:
    // 0x80059A58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059A5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80059A60: jr          $ra
    // 0x80059A64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80059A64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void log_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007FA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007FA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007FAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007FB0: sub.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80007FB4: lwc1        $f19, 0x4CF8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X4CF8);
    // 0x80007FB8: add.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80007FBC: lwc1        $f18, 0x4CFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4CFC);
    // 0x80007FC0: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80007FC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80007FC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80007FCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007FD4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80007FD8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80007FDC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80007FE0: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80007FE4: nop

    // 0x80007FE8: bc1f        L_8000802C
    if (!c1cs) {
        // 0x80007FEC: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8000802C;
    }
    // 0x80007FEC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80007FF0: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80007FF4: nop

L_80007FF8:
    // 0x80007FF8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007FFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80008000: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008004: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80008008: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8000800C: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80008010: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80008014: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80008018: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000801C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80008020: nop

    // 0x80008024: bc1t        L_80007FF8
    if (c1cs) {
        // 0x80008028: nop
    
            goto L_80007FF8;
    }
    // 0x80008028: nop

L_8000802C:
    // 0x8000802C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008030: nop

    // 0x80008034: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80008038: jr          $ra
    // 0x8000803C: nop

    return;
    // 0x8000803C: nop

;}
RECOMP_FUNC void get_time_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073C54: jr          $ra
    // 0x80073C58: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    return;
    // 0x80073C58: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
;}
RECOMP_FUNC void racer_play_sound_after_delay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800570A4: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800570A8: nop

    // 0x800570AC: sh          $a1, 0x20E($v0)
    MEM_H(0X20E, ctx->r2) = ctx->r5;
    // 0x800570B0: jr          $ra
    // 0x800570B4: sb          $a2, 0x210($v0)
    MEM_B(0X210, ctx->r2) = ctx->r6;
    return;
    // 0x800570B4: sb          $a2, 0x210($v0)
    MEM_B(0X210, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void sound_get_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001728: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000172C: addiu       $v1, $v1, 0x5D1C
    ctx->r3 = ADD32(ctx->r3, 0X5D1C);
    // 0x80001730: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80001734: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80001738: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x8000173C: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80001740: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001744: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80001748: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8000174C: nop

    // 0x80001750: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x80001754: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80001758: nop

    // 0x8000175C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80001760: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80001764: nop

    // 0x80001768: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8000176C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80001770: nop

    // 0x80001774: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80001778: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x8000177C: jr          $ra
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
    return;
    // 0x80001780: sb          $t5, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r13;
;}
RECOMP_FUNC void track_tex_anim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027E24: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80027E28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027E2C: lw          $a1, -0x36E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36E8);
    // 0x80027E30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80027E34: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80027E38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80027E3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80027E40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80027E44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80027E48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80027E4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80027E50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80027E54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80027E58: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80027E5C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80027E60: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027E64: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80027E68: blez        $v0, L_80027F94
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80027E6C: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80027F94;
    }
    // 0x80027E6C: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80027E70: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80027E74: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80027E78: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_80027E7C:
    // 0x80027E7C: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027E80: lw          $s5, 0xC($s6)
    ctx->r21 = MEM_W(ctx->r22, 0XC);
    // 0x80027E84: blez        $v1, L_80027F7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80027E88: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80027F7C;
    }
    // 0x80027E88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80027E8C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80027E90: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_80027E94:
    // 0x80027E94: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80027E98: nop

    // 0x80027E9C: and         $t7, $t6, $s7
    ctx->r15 = ctx->r14 & ctx->r23;
    // 0x80027EA0: beq         $t7, $zero, L_80027F60
    if (ctx->r15 == 0) {
        // 0x80027EA4: nop
    
            goto L_80027F60;
    }
    // 0x80027EA4: nop

    // 0x80027EA8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80027EAC: nop

    // 0x80027EB0: beq         $fp, $v0, L_80027F60
    if (ctx->r30 == ctx->r2) {
        // 0x80027EB4: nop
    
            goto L_80027F60;
    }
    // 0x80027EB4: nop

    // 0x80027EB8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80027EBC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80027EC0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80027EC4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80027EC8: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80027ECC: lhu         $t1, 0x12($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X12);
    // 0x80027ED0: nop

    // 0x80027ED4: beq         $t1, $at, L_80027F60
    if (ctx->r9 == ctx->r1) {
        // 0x80027ED8: nop
    
            goto L_80027F60;
    }
    // 0x80027ED8: nop

    // 0x80027EDC: lhu         $t2, 0x14($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X14);
    // 0x80027EE0: nop

    // 0x80027EE4: beq         $t2, $zero, L_80027F60
    if (ctx->r10 == 0) {
        // 0x80027EE8: nop
    
            goto L_80027F60;
    }
    // 0x80027EE8: nop

    // 0x80027EEC: lbu         $t3, 0x7($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7);
    // 0x80027EF0: addu        $a1, $s2, $s5
    ctx->r5 = ADD32(ctx->r18, ctx->r21);
    // 0x80027EF4: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80027EF8: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80027EFC: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80027F00: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80027F04: sll         $t6, $t5, 0
    ctx->r14 = S32(ctx->r13 << 0);
    // 0x80027F08: bgez        $t6, L_80027F3C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80027F0C: or          $a2, $s4, $zero
        ctx->r6 = ctx->r20 | 0;
            goto L_80027F3C;
    }
    // 0x80027F0C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F10: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x80027F14: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80027F18: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80027F1C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80027F20: jal         0x8007EF80
    // 0x80027F24: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x80027F24: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80027F28: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80027F2C: nop

    // 0x80027F30: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x80027F34: b           L_80027F44
    // 0x80027F38: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
        goto L_80027F44;
    // 0x80027F38: sb          $t1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r9;
L_80027F3C:
    // 0x80027F3C: jal         0x8007EF80
    // 0x80027F40: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_1;
    // 0x80027F40: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
L_80027F44:
    // 0x80027F44: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80027F48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80027F4C: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x80027F50: sb          $t4, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r12;
    // 0x80027F54: lh          $v1, 0x20($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X20);
    // 0x80027F58: lw          $a1, -0x36E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36E8);
    // 0x80027F5C: nop

L_80027F60:
    // 0x80027F60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027F64: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80027F68: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80027F6C: bne         $at, $zero, L_80027E94
    if (ctx->r1 != 0) {
        // 0x80027F70: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80027E94;
    }
    // 0x80027F70: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80027F74: lh          $v0, 0x1A($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A);
    // 0x80027F78: nop

L_80027F7C:
    // 0x80027F7C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80027F80: addiu       $s6, $s6, 0x44
    ctx->r22 = ADD32(ctx->r22, 0X44);
    // 0x80027F84: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80027F88: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80027F8C: bne         $at, $zero, L_80027E7C
    if (ctx->r1 != 0) {
        // 0x80027F90: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_80027E7C;
    }
    // 0x80027F90: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_80027F94:
    // 0x80027F94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80027F98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80027F9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80027FA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80027FA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80027FA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80027FAC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80027FB0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80027FB4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80027FB8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80027FBC: jr          $ra
    // 0x80027FC0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80027FC0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_pause_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093A40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80093A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093A48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80093A4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80093A50: jal         0x80072298
    // 0x80093A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x80093A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80093A58: jal         0x8006EA90
    // 0x80093A5C: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x80093A5C: nop

    after_1:
    // 0x80093A60: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80093A64: addiu       $s1, $s1, 0x98C
    ctx->r17 = ADD32(ctx->r17, 0X98C);
    // 0x80093A68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80093A6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80093A70: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80093A74: jal         0x8009C3D8
    // 0x80093A78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    get_active_player_count(rdram, ctx);
        goto after_2;
    // 0x80093A78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x80093A7C: blez        $v0, L_80093AD0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093A80: nop
    
            goto L_80093AD0;
    }
    // 0x80093A80: nop

    // 0x80093A84: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80093A88: nop

    // 0x80093A8C: bgez        $t7, L_80093AD0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80093A90: nop
    
            goto L_80093AD0;
    }
    // 0x80093A90: nop

L_80093A94:
    // 0x80093A94: jal         0x8006A528
    // 0x80093A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_held(rdram, ctx);
        goto after_3;
    // 0x80093A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80093A9C: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x80093AA0: beq         $t8, $zero, L_80093AAC
    if (ctx->r24 == 0) {
        // 0x80093AA4: nop
    
            goto L_80093AAC;
    }
    // 0x80093AA4: nop

    // 0x80093AA8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
L_80093AAC:
    // 0x80093AAC: jal         0x8009C3D8
    // 0x80093AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    get_active_player_count(rdram, ctx);
        goto after_4;
    // 0x80093AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x80093AB4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80093AB8: beq         $at, $zero, L_80093AD0
    if (ctx->r1 == 0) {
        // 0x80093ABC: nop
    
            goto L_80093AD0;
    }
    // 0x80093ABC: nop

    // 0x80093AC0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80093AC4: nop

    // 0x80093AC8: bltz        $t9, L_80093A94
    if (SIGNED(ctx->r25) < 0) {
        // 0x80093ACC: nop
    
            goto L_80093A94;
    }
    // 0x80093ACC: nop

L_80093AD0:
    // 0x80093AD0: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80093AD4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093AD8: bgez        $t0, L_80093AE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80093ADC: addiu       $a1, $a1, 0x984
        ctx->r5 = ADD32(ctx->r5, 0X984);
            goto L_80093AE4;
    }
    // 0x80093ADC: addiu       $a1, $a1, 0x984
    ctx->r5 = ADD32(ctx->r5, 0X984);
    // 0x80093AE0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80093AE4:
    // 0x80093AE4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093AE8: addiu       $a2, $a2, -0xB60
    ctx->r6 = ADD32(ctx->r6, -0XB60);
    // 0x80093AEC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80093AF0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80093AF4: lw          $t1, 0x188($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X188);
    // 0x80093AF8: addiu       $s1, $s1, 0x6A40
    ctx->r17 = ADD32(ctx->r17, 0X6A40);
    // 0x80093AFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80093B00: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80093B04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80093B08: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80093B0C: lw          $t2, 0xFE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XFE8);
    // 0x80093B10: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80093B14: bne         $t2, $zero, L_80093CE4
    if (ctx->r10 != 0) {
        // 0x80093B18: nop
    
            goto L_80093CE4;
    }
    // 0x80093B18: nop

    // 0x80093B1C: lbu         $a0, 0x49($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X49);
    // 0x80093B20: jal         0x8006B14C
    // 0x80093B24: nop

    leveltable_type(rdram, ctx);
        goto after_5;
    // 0x80093B24: nop

    after_5:
    // 0x80093B28: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80093B2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093B30: lbu         $t5, 0x48($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X48);
    // 0x80093B34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093B38: addiu       $a2, $a2, -0xB60
    ctx->r6 = ADD32(ctx->r6, -0XB60);
    // 0x80093B3C: addiu       $a1, $a1, 0x984
    ctx->r5 = ADD32(ctx->r5, 0X984);
    // 0x80093B40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80093B44: bne         $t5, $zero, L_80093B90
    if (ctx->r13 != 0) {
        // 0x80093B48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80093B90;
    }
    // 0x80093B48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80093B4C: jal         0x8002341C
    // 0x80093B50: nop

    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x80093B50: nop

    after_6:
    // 0x80093B54: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80093B58: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093B5C: addiu       $a2, $a2, -0xB60
    ctx->r6 = ADD32(ctx->r6, -0XB60);
    // 0x80093B60: addiu       $a1, $a1, 0x984
    ctx->r5 = ADD32(ctx->r5, 0X984);
    // 0x80093B64: beq         $v0, $zero, L_80093B90
    if (ctx->r2 == 0) {
        // 0x80093B68: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80093B90;
    }
    // 0x80093B68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80093B6C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80093B70: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80093B74: lw          $t7, 0x200($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X200);
    // 0x80093B78: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80093B7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093B80: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80093B84: lw          $v0, -0xB48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB48);
    // 0x80093B88: b           L_80093C88
    // 0x80093B8C: nop

        goto L_80093C88;
    // 0x80093B8C: nop

L_80093B90:
    // 0x80093B90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80093B94: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80093B98: lbu         $t0, 0x48($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X48);
    // 0x80093B9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093BA0: blez        $t0, L_80093C50
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80093BA4: nop
    
            goto L_80093C50;
    }
    // 0x80093BA4: nop

    // 0x80093BA8: beq         $s0, $at, L_80093C50
    if (ctx->r16 == ctx->r1) {
        // 0x80093BAC: andi        $t1, $s0, 0x40
        ctx->r9 = ctx->r16 & 0X40;
            goto L_80093C50;
    }
    // 0x80093BAC: andi        $t1, $s0, 0x40
    ctx->r9 = ctx->r16 & 0X40;
    // 0x80093BB0: beq         $t1, $zero, L_80093BFC
    if (ctx->r9 == 0) {
        // 0x80093BB4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80093BFC;
    }
    // 0x80093BB4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093BB8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80093BBC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80093BC0: lw          $t2, 0x1FC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1FC);
    // 0x80093BC4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80093BC8: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x80093BCC: lw          $t3, -0xB48($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB48);
    // 0x80093BD0: nop

    // 0x80093BD4: bne         $t3, $zero, L_80093BE8
    if (ctx->r11 != 0) {
        // 0x80093BD8: nop
    
            goto L_80093BE8;
    }
    // 0x80093BD8: nop

    // 0x80093BDC: lw          $t4, 0x64($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X64);
    // 0x80093BE0: b           L_80093BF4
    // 0x80093BE4: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
        goto L_80093BF4;
    // 0x80093BE4: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
L_80093BE8:
    // 0x80093BE8: lw          $t5, 0x60($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X60);
    // 0x80093BEC: nop

    // 0x80093BF0: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
L_80093BF4:
    // 0x80093BF4: b           L_80093C44
    // 0x80093BF8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_80093C44;
    // 0x80093BF8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80093BFC:
    // 0x80093BFC: bne         $s0, $zero, L_80093C44
    if (ctx->r16 != 0) {
        // 0x80093C00: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80093C44;
    }
    // 0x80093C00: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80093C04: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80093C08: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80093C0C: lw          $t7, 0x1F8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1F8);
    // 0x80093C10: nop

    // 0x80093C14: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80093C18: lw          $t8, -0xB48($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB48);
    // 0x80093C1C: nop

    // 0x80093C20: bne         $t8, $zero, L_80093C34
    if (ctx->r24 != 0) {
        // 0x80093C24: nop
    
            goto L_80093C34;
    }
    // 0x80093C24: nop

    // 0x80093C28: lw          $t9, 0x64($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X64);
    // 0x80093C2C: b           L_80093C40
    // 0x80093C30: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
        goto L_80093C40;
    // 0x80093C30: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_80093C34:
    // 0x80093C34: lw          $t0, 0x60($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X60);
    // 0x80093C38: nop

    // 0x80093C3C: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_80093C40:
    // 0x80093C40: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80093C44:
    // 0x80093C44: lw          $v0, -0xB48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB48);
    // 0x80093C48: b           L_80093C88
    // 0x80093C4C: nop

        goto L_80093C88;
    // 0x80093C4C: nop

L_80093C50:
    // 0x80093C50: lw          $v0, -0xB48($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB48);
    // 0x80093C54: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80093C58: bne         $v0, $zero, L_80093C88
    if (ctx->r2 != 0) {
        // 0x80093C5C: nop
    
            goto L_80093C88;
    }
    // 0x80093C5C: nop

    // 0x80093C60: bne         $s0, $at, L_80093C88
    if (ctx->r16 != ctx->r1) {
        // 0x80093C64: nop
    
            goto L_80093C88;
    }
    // 0x80093C64: nop

    // 0x80093C68: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80093C6C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80093C70: lw          $t2, 0x1F8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1F8);
    // 0x80093C74: nop

    // 0x80093C78: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x80093C7C: lw          $t3, 0x64($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X64);
    // 0x80093C80: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80093C84: sw          $t3, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r11;
L_80093C88:
    // 0x80093C88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80093C8C: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80093C90: bne         $a3, $v0, L_80093CC4
    if (ctx->r7 != ctx->r2) {
        // 0x80093C94: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80093CC4;
    }
    // 0x80093C94: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80093C98: lw          $t5, -0xB44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB44);
    // 0x80093C9C: nop

    // 0x80093CA0: bne         $a3, $t5, L_80093CC4
    if (ctx->r7 != ctx->r13) {
        // 0x80093CA4: nop
    
            goto L_80093CC4;
    }
    // 0x80093CA4: nop

    // 0x80093CA8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80093CAC: lw          $t6, 0x68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X68);
    // 0x80093CB0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80093CB4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80093CB8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80093CBC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80093CC0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_80093CC4:
    // 0x80093CC4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80093CC8: lw          $t0, 0x20C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20C);
    // 0x80093CCC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80093CD0: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80093CD4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80093CD8: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x80093CDC: b           L_80093D00
    // 0x80093CE0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_80093D00;
    // 0x80093CE0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80093CE4:
    // 0x80093CE4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80093CE8: lw          $t4, 0x204($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X204);
    // 0x80093CEC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80093CF0: addu        $t7, $s1, $t5
    ctx->r15 = ADD32(ctx->r17, ctx->r13);
    // 0x80093CF4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80093CF8: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80093CFC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80093D00:
    // 0x80093D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093D04: sw          $zero, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = 0;
    // 0x80093D08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093D0C: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80093D10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093D14: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80093D18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093D1C: sw          $a3, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r7;
    // 0x80093D20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093D24: jal         0x8009BE5C
    // 0x80093D28: sw          $zero, 0x988($at)
    MEM_W(0X988, ctx->r1) = 0;
    reset_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x80093D28: sw          $zero, 0x988($at)
    MEM_W(0X988, ctx->r1) = 0;
    after_7:
    // 0x80093D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093D30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80093D34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80093D38: jr          $ra
    // 0x80093D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80093D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menu_postrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095728: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009572C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80095730: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80095734: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80095738: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8009573C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80095740: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80095744: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80095748: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8009574C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80095750: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80095754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095758: sw          $t7, 0x63A0($at)
    MEM_W(0X63A0, ctx->r1) = ctx->r15;
    // 0x8009575C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80095760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095764: sw          $t9, 0x63A8($at)
    MEM_W(0X63A8, ctx->r1) = ctx->r25;
    // 0x80095768: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8009576C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095770: jal         0x8006EA90
    // 0x80095774: sw          $t5, 0x63AC($at)
    MEM_W(0X63AC, ctx->r1) = ctx->r13;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80095774: sw          $t5, 0x63AC($at)
    MEM_W(0X63AC, ctx->r1) = ctx->r13;
    after_0:
    // 0x80095778: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8009577C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80095780: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80095784: bne         $t6, $zero, L_800957A0
    if (ctx->r14 != 0) {
        // 0x80095788: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800957A0;
    }
    // 0x80095788: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009578C: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80095790: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80095794: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80095798: b           L_800957A8
    // 0x8009579C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800957A8;
    // 0x8009579C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800957A0:
    // 0x800957A0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800957A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800957A8:
    // 0x800957A8: lw          $t2, -0xB44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB44);
    // 0x800957AC: jal         0x8009EC80
    // 0x800957B0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x800957B0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_1:
    // 0x800957B4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800957B8: beq         $v0, $zero, L_800957C4
    if (ctx->r2 == 0) {
        // 0x800957BC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800957C4;
    }
    // 0x800957BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800957C0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800957C4:
    // 0x800957C4: lw          $t9, 0x6A90($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A90);
    // 0x800957C8: nop

    // 0x800957CC: beq         $t9, $zero, L_80095828
    if (ctx->r25 == 0) {
        // 0x800957D0: nop
    
            goto L_80095828;
    }
    // 0x800957D0: nop

    // 0x800957D4: jal         0x8001B780
    // 0x800957D8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    has_ghost_to_save(rdram, ctx);
        goto after_2;
    // 0x800957D8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_2:
    // 0x800957DC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800957E0: beq         $v0, $zero, L_80095824
    if (ctx->r2 == 0) {
        // 0x800957E4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80095824;
    }
    // 0x800957E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800957E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800957EC: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
    // 0x800957F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800957F4: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x800957F8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800957FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095800: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80095804: addiu       $t5, $t5, 0x6BF0
    ctx->r13 = ADD32(ctx->r13, 0X6BF0);
    // 0x80095808: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8009580C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80095810: sw          $t6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r14;
    // 0x80095814: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x80095818: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8009581C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80095820: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80095824:
    // 0x80095824: sw          $zero, 0x6A90($at)
    MEM_W(0X6A90, ctx->r1) = 0;
L_80095828:
    // 0x80095828: jal         0x80094A5C
    // 0x8009582C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    postrace_load(rdram, ctx);
        goto after_3;
    // 0x8009582C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_3:
    // 0x80095830: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095834: jal         0x80094C14
    // 0x80095838: nop

    postrace_music_fade(rdram, ctx);
        goto after_4;
    // 0x80095838: nop

    after_4:
    // 0x8009583C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80095840: lw          $t9, -0xB84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB84);
    // 0x80095844: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095848: slti        $at, $t9, 0x14
    ctx->r1 = SIGNED(ctx->r25) < 0X14 ? 1 : 0;
    // 0x8009584C: beq         $at, $zero, L_80095888
    if (ctx->r1 == 0) {
        // 0x80095850: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80095888;
    }
    // 0x80095850: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80095854: lb          $t4, 0x6C28($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6C28);
    // 0x80095858: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009585C: bne         $t4, $zero, L_8009588C
    if (ctx->r12 != 0) {
        // 0x80095860: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8009588C;
    }
    // 0x80095860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095864: lw          $t5, 0x6C54($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C54);
    // 0x80095868: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8009586C: bgez        $t5, L_800958A4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80095870: nop
    
            goto L_800958A4;
    }
    // 0x80095870: nop

    // 0x80095874: jal         0x80094D28
    // 0x80095878: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    postrace_viewport(rdram, ctx);
        goto after_5;
    // 0x80095878: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_5:
    // 0x8009587C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095880: b           L_800958A4
    // 0x80095884: nop

        goto L_800958A4;
    // 0x80095884: nop

L_80095888:
    // 0x80095888: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8009588C:
    // 0x8009588C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80095894: jal         0x80078170
    // 0x80095898: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    bgdraw_texture_init(rdram, ctx);
        goto after_6;
    // 0x80095898: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_6:
    // 0x8009589C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800958A0: nop

L_800958A4:
    // 0x800958A4: jal         0x8009BF20
    // 0x800958A8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    update_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x800958A8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_7:
    // 0x800958AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800958B0: lw          $t6, 0x63C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C4);
    // 0x800958B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800958B8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800958BC: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
    // 0x800958C0: bne         $t6, $zero, L_80095914
    if (ctx->r14 != 0) {
        // 0x800958C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80095914;
    }
    // 0x800958C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800958C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800958CC: lw          $t7, 0x6C54($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C54);
    // 0x800958D0: nop

    // 0x800958D4: bgez        $t7, L_80095914
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800958D8: nop
    
            goto L_80095914;
    }
    // 0x800958D8: nop

    // 0x800958DC: blez        $t2, L_80095914
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800958E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80095914;
    }
    // 0x800958E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800958E4:
    // 0x800958E4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800958E8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800958EC: jal         0x8006A554
    // 0x800958F0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    input_pressed(rdram, ctx);
        goto after_8;
    // 0x800958F0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_8:
    // 0x800958F4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800958F8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800958FC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80095900: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095904: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80095908: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
    // 0x8009590C: bne         $a0, $t2, L_800958E4
    if (ctx->r4 != ctx->r10) {
        // 0x80095910: or          $v1, $v1, $v0
        ctx->r3 = ctx->r3 | ctx->r2;
            goto L_800958E4;
    }
    // 0x80095910: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80095914:
    // 0x80095914: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80095918: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x8009591C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80095920: nop

    // 0x80095924: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80095928: beq         $at, $zero, L_80096714
    if (ctx->r1 == 0) {
        // 0x8009592C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80096714;
    }
    // 0x8009592C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80095930: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80095934: addu        $at, $at, $t8
    gpr jr_addend_80095940 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80095938: lw          $t8, -0x7AB8($at)
    ctx->r24 = ADD32(ctx->r1, -0X7AB8);
    // 0x8009593C: nop

    // 0x80095940: jr          $t8
    // 0x80095944: nop

    switch (jr_addend_80095940 >> 2) {
        case 0: goto L_80095948; break;
        case 1: goto L_80095964; break;
        case 2: goto L_80095B34; break;
        case 3: goto L_80095D30; break;
        case 4: goto L_80095D50; break;
        case 5: goto L_80095EA8; break;
        case 6: goto L_80095EC8; break;
        case 7: goto L_800964AC; break;
        case 8: goto L_800964DC; break;
        default: switch_error(__func__, 0x80095940, 0x800E8548);
    }
    // 0x80095944: nop

L_80095948:
    // 0x80095948: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8009594C: beq         $t9, $zero, L_80096714
    if (ctx->r25 == 0) {
        // 0x80095950: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80096714;
    }
    // 0x80095950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80095954: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x80095958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009595C: b           L_80096714
    // 0x80095960: sw          $zero, 0x6A94($at)
    MEM_W(0X6A94, ctx->r1) = 0;
        goto L_80096714;
    // 0x80095960: sw          $zero, 0x6A94($at)
    MEM_W(0X6A94, ctx->r1) = 0;
L_80095964:
    // 0x80095964: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80095968: lw          $t4, 0x6A94($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A94);
    // 0x8009596C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095970: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x80095974: beq         $at, $zero, L_80095988
    if (ctx->r1 == 0) {
        // 0x80095978: nop
    
            goto L_80095988;
    }
    // 0x80095978: nop

    // 0x8009597C: andi        $t5, $v1, 0x9000
    ctx->r13 = ctx->r3 & 0X9000;
    // 0x80095980: beq         $t5, $zero, L_80096714
    if (ctx->r13 == 0) {
        // 0x80095984: nop
    
            goto L_80096714;
    }
    // 0x80095984: nop

L_80095988:
    // 0x80095988: lw          $v0, 0x6478($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6478);
    // 0x8009598C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80095990: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80095994: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80095998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009599C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800959A0: bne         $v1, $zero, L_800959AC
    if (ctx->r3 != 0) {
        // 0x800959A4: nop
    
            goto L_800959AC;
    }
    // 0x800959A4: nop

    // 0x800959A8: break       7
    do_break(2148096424);
L_800959AC:
    // 0x800959AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800959B0: bne         $v1, $at, L_800959C4
    if (ctx->r3 != ctx->r1) {
        // 0x800959B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800959C4;
    }
    // 0x800959B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800959B8: bne         $t6, $at, L_800959C4
    if (ctx->r14 != ctx->r1) {
        // 0x800959BC: nop
    
            goto L_800959C4;
    }
    // 0x800959BC: nop

    // 0x800959C0: break       6
    do_break(2148096448);
L_800959C4:
    // 0x800959C4: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x800959C8: mflo        $t7
    ctx->r15 = lo;
    // 0x800959CC: subu        $a2, $v0, $t7
    ctx->r6 = SUB32(ctx->r2, ctx->r15);
    // 0x800959D0: nop

    // 0x800959D4: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800959D8: bne         $v1, $zero, L_800959E4
    if (ctx->r3 != 0) {
        // 0x800959DC: nop
    
            goto L_800959E4;
    }
    // 0x800959DC: nop

    // 0x800959E0: break       7
    do_break(2148096480);
L_800959E4:
    // 0x800959E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800959E8: bne         $v1, $at, L_800959FC
    if (ctx->r3 != ctx->r1) {
        // 0x800959EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800959FC;
    }
    // 0x800959EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800959F0: bne         $v0, $at, L_800959FC
    if (ctx->r2 != ctx->r1) {
        // 0x800959F4: nop
    
            goto L_800959FC;
    }
    // 0x800959F4: nop

    // 0x800959F8: break       6
    do_break(2148096504);
L_800959FC:
    // 0x800959FC: mflo        $t8
    ctx->r24 = lo;
    // 0x80095A00: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80095A04: jal         0x80066940
    // 0x80095A08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    viewport_menu_set(rdram, ctx);
        goto after_9;
    // 0x80095A08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_9:
    // 0x80095A0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095A10: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80095A14: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80095A18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80095A1C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80095A20: swc1        $f4, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = ctx->f4.u32l;
    // 0x80095A24: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80095A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095A2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095A30: swc1        $f6, 0x90($t5)
    MEM_W(0X90, ctx->r13) = ctx->f6.u32l;
    // 0x80095A34: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80095A38: lwc1        $f8, -0xA68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XA68);
    // 0x80095A3C: nop

    // 0x80095A40: swc1        $f8, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f8.u32l;
    // 0x80095A44: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80095A48: nop

    // 0x80095A4C: lbu         $a0, 0x49($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X49);
    // 0x80095A50: jal         0x8006B14C
    // 0x80095A54: nop

    leveltable_type(rdram, ctx);
        goto after_10;
    // 0x80095A54: nop

    after_10:
    // 0x80095A58: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x80095A5C: beq         $t8, $zero, L_80095A70
    if (ctx->r24 == 0) {
        // 0x80095A60: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_80095A70;
    }
    // 0x80095A60: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80095A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095A68: b           L_80096714
    // 0x80095A6C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
        goto L_80096714;
    // 0x80095A6C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80095A70:
    // 0x80095A70: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80095A74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095A78: lb          $t4, 0x117($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X117);
    // 0x80095A7C: addiu       $a0, $a0, 0xBEC
    ctx->r4 = ADD32(ctx->r4, 0XBEC);
    // 0x80095A80: bne         $t4, $zero, L_80095AC8
    if (ctx->r12 != 0) {
        // 0x80095A84: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80095AC8;
    }
    // 0x80095A84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095A88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095A8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095A90: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80095A94: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80095A98: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095A9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095AA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095AA4: addiu       $a0, $a0, 0xCEC
    ctx->r4 = ADD32(ctx->r4, 0XCEC);
    // 0x80095AA8: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095AAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80095AB0: jal         0x80081E54
    // 0x80095AB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    postrace_offsets(rdram, ctx);
        goto after_11;
    // 0x80095AB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_11:
    // 0x80095AB8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80095ABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095AC0: b           L_80096714
    // 0x80095AC4: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
        goto L_80096714;
    // 0x80095AC4: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
L_80095AC8:
    // 0x80095AC8: lb          $t8, 0x114($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X114);
    // 0x80095ACC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095AD0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80095AD4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80095AD8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80095ADC: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x80095AE0: addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // 0x80095AE4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80095AE8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80095AEC: addiu       $t4, $v0, 0x12
    ctx->r12 = ADD32(ctx->r2, 0X12);
    // 0x80095AF0: addiu       $t5, $v0, 0x14
    ctx->r13 = ADD32(ctx->r2, 0X14);
    // 0x80095AF4: addiu       $t6, $v0, 0x16
    ctx->r14 = ADD32(ctx->r2, 0X16);
    // 0x80095AF8: addiu       $t7, $v0, 0x10
    ctx->r15 = ADD32(ctx->r2, 0X10);
    // 0x80095AFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095B00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095B04: sw          $t4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r12;
    // 0x80095B08: sw          $t5, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r13;
    // 0x80095B0C: sw          $t6, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->r14;
    // 0x80095B10: sw          $t7, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->r15;
    // 0x80095B14: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095B18: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80095B1C: jal         0x80081E54
    // 0x80095B20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    postrace_offsets(rdram, ctx);
        goto after_12;
    // 0x80095B20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_12:
    // 0x80095B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80095B28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095B2C: b           L_80096714
    // 0x80095B30: sw          $a2, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r6;
        goto L_80096714;
    // 0x80095B30: sw          $a2, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r6;
L_80095B34:
    // 0x80095B34: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095B38: jal         0x80081F4C
    // 0x80095B3C: nop

    postrace_render(rdram, ctx);
        goto after_13;
    // 0x80095B3C: nop

    after_13:
    // 0x80095B40: beq         $v0, $zero, L_80096714
    if (ctx->r2 == 0) {
        // 0x80095B44: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80096714;
    }
    // 0x80095B44: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80095B48: lw          $t4, 0xFE8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XFE8);
    // 0x80095B4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80095B50: beq         $t4, $zero, L_80095B7C
    if (ctx->r12 == 0) {
        // 0x80095B54: nop
    
            goto L_80095B7C;
    }
    // 0x80095B54: nop

    // 0x80095B58: jal         0x80000C98
    // 0x80095B5C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_14;
    // 0x80095B5C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_14:
    // 0x80095B60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095B64: jal         0x800C01D8
    // 0x80095B68: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x80095B68: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_15:
    // 0x80095B6C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80095B70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095B74: b           L_80096714
    // 0x80095B78: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
        goto L_80096714;
    // 0x80095B78: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
L_80095B7C:
    // 0x80095B7C: lb          $t6, 0x117($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X117);
    // 0x80095B80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095B84: beq         $t6, $zero, L_80095CF4
    if (ctx->r14 == 0) {
        // 0x80095B88: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80095CF4;
    }
    // 0x80095B88: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80095B8C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80095B90: lb          $t7, 0x69C0($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X69C0);
    // 0x80095B94: lbu         $t4, 0x49($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X49);
    // 0x80095B98: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80095B9C: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80095BA0: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x80095BA4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80095BA8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80095BAC: addiu       $v1, $v1, 0xE4C
    ctx->r3 = ADD32(ctx->r3, 0XE4C);
    // 0x80095BB0: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80095BB4: sw          $t6, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r14;
    // 0x80095BB8: lbu         $t8, 0x49($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X49);
    // 0x80095BBC: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80095BC0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x80095BC4: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x80095BC8: sw          $t9, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r25;
    // 0x80095BCC: lbu         $t6, 0x49($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X49);
    // 0x80095BD0: lw          $t5, 0x30($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X30);
    // 0x80095BD4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80095BD8: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x80095BDC: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x80095BE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095BE4: addiu       $a1, $a1, 0x6390
    ctx->r5 = ADD32(ctx->r5, 0X6390);
    // 0x80095BE8: jal         0x800976F8
    // 0x80095BEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_16;
    // 0x80095BEC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_16:
    // 0x80095BF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80095BF4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80095BF8: lb          $t4, 0x69C0($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X69C0);
    // 0x80095BFC: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x80095C00: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80095C04: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80095C08: lw          $t5, 0x18($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X18);
    // 0x80095C0C: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80095C10: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x80095C14: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x80095C18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095C1C: addiu       $a1, $a1, 0x6394
    ctx->r5 = ADD32(ctx->r5, 0X6394);
    // 0x80095C20: jal         0x800976F8
    // 0x80095C24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_17;
    // 0x80095C24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x80095C28: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80095C2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095C30: lb          $t9, 0x58($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X58);
    // 0x80095C34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095C38: beq         $t9, $zero, L_80095CC0
    if (ctx->r25 == 0) {
        // 0x80095C3C: addiu       $a0, $a0, 0xE4C
        ctx->r4 = ADD32(ctx->r4, 0XE4C);
            goto L_80095CC0;
    }
    // 0x80095C3C: addiu       $a0, $a0, 0xE4C
    ctx->r4 = ADD32(ctx->r4, 0XE4C);
    // 0x80095C40: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80095C44: lw          $t8, -0xB48($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB48);
    // 0x80095C48: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80095C4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095C50: bne         $t8, $zero, L_80095C80
    if (ctx->r24 != 0) {
        // 0x80095C54: sw          $t6, 0x63E0($at)
        MEM_W(0X63E0, ctx->r1) = ctx->r14;
            goto L_80095C80;
    }
    // 0x80095C54: sw          $t6, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r14;
    // 0x80095C58: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80095C5C: lw          $t5, 0xFAC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XFAC);
    // 0x80095C60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80095C64: beq         $t5, $zero, L_80095C80
    if (ctx->r13 == 0) {
        // 0x80095C68: addiu       $a1, $a1, 0xFA8
        ctx->r5 = ADD32(ctx->r5, 0XFA8);
            goto L_80095C80;
    }
    // 0x80095C68: addiu       $a1, $a1, 0xFA8
    ctx->r5 = ADD32(ctx->r5, 0XFA8);
    // 0x80095C6C: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80095C70: jal         0x800976F8
    // 0x80095C74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_18;
    // 0x80095C74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_18:
    // 0x80095C78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095C7C: sw          $zero, 0xFAC($at)
    MEM_W(0XFAC, ctx->r1) = 0;
L_80095C80:
    // 0x80095C80: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80095C84: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095C88: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80095C8C: addiu       $t4, $t4, 0xFA8
    ctx->r12 = ADD32(ctx->r12, 0XFA8);
    // 0x80095C90: addiu       $t7, $t7, 0xFA4
    ctx->r15 = ADD32(ctx->r15, 0XFA4);
    // 0x80095C94: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80095C98: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80095C9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80095CA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095CA4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80095CA8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80095CAC: addiu       $a0, $v0, 0xC4
    ctx->r4 = ADD32(ctx->r2, 0XC4);
    // 0x80095CB0: jal         0x80097874
    // 0x80095CB4: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    filename_init(rdram, ctx);
        goto after_19;
    // 0x80095CB4: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    after_19:
    // 0x80095CB8: b           L_80096714
    // 0x80095CBC: nop

        goto L_80096714;
    // 0x80095CBC: nop

L_80095CC0:
    // 0x80095CC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095CC4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80095CC8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80095CCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095CD0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095CD4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095CD8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80095CDC: jal         0x80081E54
    // 0x80095CE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    postrace_offsets(rdram, ctx);
        goto after_20;
    // 0x80095CE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_20:
    // 0x80095CE4: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80095CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095CEC: b           L_80096714
    // 0x80095CF0: sw          $v1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r3;
        goto L_80096714;
    // 0x80095CF0: sw          $v1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r3;
L_80095CF4:
    // 0x80095CF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095CF8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80095CFC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80095D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095D04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095D08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095D0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095D10: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
    // 0x80095D14: addiu       $a0, $a0, 0xCEC
    ctx->r4 = ADD32(ctx->r4, 0XCEC);
    // 0x80095D18: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095D1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80095D20: jal         0x80081E54
    // 0x80095D24: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    postrace_offsets(rdram, ctx);
        goto after_21;
    // 0x80095D24: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_21:
    // 0x80095D28: b           L_80096714
    // 0x80095D2C: nop

        goto L_80096714;
    // 0x80095D2C: nop

L_80095D30:
    // 0x80095D30: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095D34: jal         0x80081F4C
    // 0x80095D38: nop

    postrace_render(rdram, ctx);
        goto after_22;
    // 0x80095D38: nop

    after_22:
    // 0x80095D3C: beq         $v0, $zero, L_80096714
    if (ctx->r2 == 0) {
        // 0x80095D40: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_80096714;
    }
    // 0x80095D40: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80095D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095D48: b           L_80096714
    // 0x80095D4C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
        goto L_80096714;
    // 0x80095D4C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80095D50:
    // 0x80095D50: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095D54: jal         0x80097D10
    // 0x80095D58: nop

    filename_enter(rdram, ctx);
        goto after_23;
    // 0x80095D58: nop

    after_23:
    // 0x80095D5C: beq         $v0, $zero, L_80096714
    if (ctx->r2 == 0) {
        // 0x80095D60: nop
    
            goto L_80096714;
    }
    // 0x80095D60: nop

    // 0x80095D64: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80095D68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095D6C: lb          $v0, 0x58($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X58);
    // 0x80095D70: addiu       $a0, $a0, 0xFA8
    ctx->r4 = ADD32(ctx->r4, 0XFA8);
    // 0x80095D74: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80095D78: beq         $t8, $zero, L_80095DF8
    if (ctx->r24 == 0) {
        // 0x80095D7C: andi        $t6, $v0, 0x80
        ctx->r14 = ctx->r2 & 0X80;
            goto L_80095DF8;
    }
    // 0x80095D7C: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80095D80: jal         0x80097744
    // 0x80095D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_24;
    // 0x80095D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x80095D88: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80095D8C: addiu       $a3, $a3, 0x69C0
    ctx->r7 = ADD32(ctx->r7, 0X69C0);
    // 0x80095D90: lb          $t5, 0x0($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X0);
    // 0x80095D94: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80095D98: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80095D9C: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x80095DA0: addu        $t4, $v1, $t7
    ctx->r12 = ADD32(ctx->r3, ctx->r15);
    // 0x80095DA4: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x80095DA8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80095DAC: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x80095DB0: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    // 0x80095DB4: lb          $t7, 0x0($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X0);
    // 0x80095DB8: lbu         $t8, 0x49($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X49);
    // 0x80095DBC: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80095DC0: addu        $t6, $v1, $t4
    ctx->r14 = ADD32(ctx->r3, ctx->r12);
    // 0x80095DC4: lw          $t9, 0x18($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X18);
    // 0x80095DC8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80095DCC: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80095DD0: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    // 0x80095DD4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095DD8: addiu       $a1, $a1, 0x6394
    ctx->r5 = ADD32(ctx->r5, 0X6394);
    // 0x80095DDC: jal         0x800976F8
    // 0x80095DE0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_25;
    // 0x80095DE0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_25:
    // 0x80095DE4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80095DE8: nop

    // 0x80095DEC: lb          $v0, 0x58($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X58);
    // 0x80095DF0: nop

    // 0x80095DF4: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
L_80095DF8:
    // 0x80095DF8: beq         $t6, $zero, L_80095E68
    if (ctx->r14 == 0) {
        // 0x80095DFC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80095E68;
    }
    // 0x80095DFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095E00: addiu       $a0, $a0, 0xFA8
    ctx->r4 = ADD32(ctx->r4, 0XFA8);
    // 0x80095E04: jal         0x80097744
    // 0x80095E08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_26;
    // 0x80095E08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_26:
    // 0x80095E0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80095E10: addiu       $a3, $a3, 0x69C0
    ctx->r7 = ADD32(ctx->r7, 0X69C0);
    // 0x80095E14: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x80095E18: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80095E1C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80095E20: lbu         $t4, 0x49($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X49);
    // 0x80095E24: addu        $t5, $v1, $t9
    ctx->r13 = ADD32(ctx->r3, ctx->r25);
    // 0x80095E28: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x80095E2C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80095E30: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80095E34: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x80095E38: lb          $t9, 0x0($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X0);
    // 0x80095E3C: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x80095E40: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80095E44: addu        $t4, $v1, $t5
    ctx->r12 = ADD32(ctx->r3, ctx->r13);
    // 0x80095E48: lw          $t7, 0x30($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X30);
    // 0x80095E4C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80095E50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80095E54: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x80095E58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095E5C: addiu       $a1, $a1, 0x6390
    ctx->r5 = ADD32(ctx->r5, 0X6390);
    // 0x80095E60: jal         0x800976F8
    // 0x80095E64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_27;
    // 0x80095E64: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_27:
L_80095E68:
    // 0x80095E68: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80095E6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80095E70: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80095E74: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80095E78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80095E7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80095E80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80095E84: addiu       $a0, $a0, 0xE4C
    ctx->r4 = ADD32(ctx->r4, 0XE4C);
    // 0x80095E88: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80095E8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80095E90: jal         0x80081E54
    // 0x80095E94: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    postrace_offsets(rdram, ctx);
        goto after_28;
    // 0x80095E94: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_28:
    // 0x80095E98: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80095E9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095EA0: b           L_80096714
    // 0x80095EA4: sw          $v1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r3;
        goto L_80096714;
    // 0x80095EA4: sw          $v1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r3;
L_80095EA8:
    // 0x80095EA8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80095EAC: jal         0x80081F4C
    // 0x80095EB0: nop

    postrace_render(rdram, ctx);
        goto after_29;
    // 0x80095EB0: nop

    after_29:
    // 0x80095EB4: beq         $v0, $zero, L_80096714
    if (ctx->r2 == 0) {
        // 0x80095EB8: addiu       $t6, $zero, 0x6
        ctx->r14 = ADD32(0, 0X6);
            goto L_80096714;
    }
    // 0x80095EB8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80095EBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095EC0: b           L_80096714
    // 0x80095EC4: sw          $t6, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r14;
        goto L_80096714;
    // 0x80095EC4: sw          $t6, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r14;
L_80095EC8:
    // 0x80095EC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095ECC: addiu       $a1, $a1, 0x6A98
    ctx->r5 = ADD32(ctx->r5, 0X6A98);
    // 0x80095ED0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80095ED4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095ED8: beq         $v0, $zero, L_80095FC0
    if (ctx->r2 == 0) {
        // 0x80095EDC: addiu       $a0, $a0, 0x6C1C
        ctx->r4 = ADD32(ctx->r4, 0X6C1C);
            goto L_80095FC0;
    }
    // 0x80095EDC: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x80095EE0: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80095EE4: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80095EE8: bne         $at, $zero, L_80096454
    if (ctx->r1 != 0) {
        // 0x80095EEC: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80096454;
    }
    // 0x80095EEC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80095EF0: jal         0x80000968
    // 0x80095EF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sound_volume_change(rdram, ctx);
        goto after_30;
    // 0x80095EF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_30:
    // 0x80095EF8: jal         0x8001B738
    // 0x80095EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_31;
    // 0x80095EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80095F00: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80095F04: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x80095F08: bne         $v1, $t9, L_80095F1C
    if (ctx->r3 != ctx->r25) {
        // 0x80095F0C: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80095F1C;
    }
    // 0x80095F0C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80095F10: jal         0x8001B738
    // 0x80095F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_32;
    // 0x80095F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x80095F18: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80095F1C:
    // 0x80095F1C: jal         0x80000968
    // 0x80095F20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sound_volume_change(rdram, ctx);
        goto after_33;
    // 0x80095F20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_33:
    // 0x80095F24: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80095F28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095F2C: beq         $t5, $zero, L_80095F48
    if (ctx->r13 == 0) {
        // 0x80095F30: addiu       $t1, $t1, 0x6C14
        ctx->r9 = ADD32(ctx->r9, 0X6C14);
            goto L_80095F48;
    }
    // 0x80095F30: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
    // 0x80095F34: jal         0x80095624
    // 0x80095F38: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    postrace_message(rdram, ctx);
        goto after_34;
    // 0x80095F38: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_34:
    // 0x80095F3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80095F40: b           L_80095FB4
    // 0x80095F44: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
        goto L_80095FB4;
    // 0x80095F44: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
L_80095F48:
    // 0x80095F48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095F4C: addiu       $a0, $a0, 0x6C1C
    ctx->r4 = ADD32(ctx->r4, 0X6C1C);
    // 0x80095F50: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80095F54: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095F58: addiu       $t7, $t7, 0xA04
    ctx->r15 = ADD32(ctx->r15, 0XA04);
    // 0x80095F5C: bne         $t6, $t7, L_80095F78
    if (ctx->r14 != ctx->r15) {
        // 0x80095F60: nop
    
            goto L_80095F78;
    }
    // 0x80095F60: nop

    // 0x80095F64: jal         0x80095624
    // 0x80095F68: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    postrace_message(rdram, ctx);
        goto after_35;
    // 0x80095F68: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_35:
    // 0x80095F6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80095F70: b           L_80095F7C
    // 0x80095F74: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
        goto L_80095F7C;
    // 0x80095F74: addiu       $t1, $t1, 0x6C14
    ctx->r9 = ADD32(ctx->r9, 0X6C14);
L_80095F78:
    // 0x80095F78: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80095F7C:
    // 0x80095F7C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80095F80: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x80095F84: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80095F88: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x80095F8C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80095F90: lw          $t9, 0x70($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X70);
    // 0x80095F94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095F98: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80095F9C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80095FA0: sw          $t9, 0x6BF0($at)
    MEM_W(0X6BF0, ctx->r1) = ctx->r25;
    // 0x80095FA4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80095FA8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80095FAC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80095FB0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80095FB4:
    // 0x80095FB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095FB8: b           L_80096454
    // 0x80095FBC: sw          $zero, 0x6A98($at)
    MEM_W(0X6A98, ctx->r1) = 0;
        goto L_80096454;
    // 0x80095FBC: sw          $zero, 0x6A98($at)
    MEM_W(0X6A98, ctx->r1) = 0;
L_80095FC0:
    // 0x80095FC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80095FC4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80095FC8: beq         $v0, $zero, L_80096018
    if (ctx->r2 == 0) {
        // 0x80095FCC: addiu       $t0, $t0, 0x988
        ctx->r8 = ADD32(ctx->r8, 0X988);
            goto L_80096018;
    }
    // 0x80095FCC: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x80095FD0: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x80095FD4: beq         $t8, $zero, L_80096004
    if (ctx->r24 == 0) {
        // 0x80095FD8: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_80096004;
    }
    // 0x80095FD8: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x80095FDC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80095FE0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80095FE4: addiu       $t9, $t9, 0xA04
    ctx->r25 = ADD32(ctx->r25, 0XA04);
    // 0x80095FE8: bne         $v0, $t9, L_80095FFC
    if (ctx->r2 != ctx->r25) {
        // 0x80095FEC: sw          $t5, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r13;
            goto L_80095FFC;
    }
    // 0x80095FEC: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80095FF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80095FF4: b           L_80096454
    // 0x80095FF8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
        goto L_80096454;
    // 0x80095FF8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
L_80095FFC:
    // 0x80095FFC: b           L_80096454
    // 0x80096000: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80096454;
    // 0x80096000: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80096004:
    // 0x80096004: beq         $t4, $zero, L_80096454
    if (ctx->r12 == 0) {
        // 0x80096008: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80096454;
    }
    // 0x80096008: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009600C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80096010: b           L_80096454
    // 0x80096014: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
        goto L_80096454;
    // 0x80096014: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
L_80096018:
    // 0x80096018: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8009601C: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x80096020: beq         $v0, $zero, L_80096208
    if (ctx->r2 == 0) {
        // 0x80096024: andi        $t9, $v1, 0x9000
        ctx->r25 = ctx->r3 & 0X9000;
            goto L_80096208;
    }
    // 0x80096024: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x80096028: beq         $t7, $zero, L_80096074
    if (ctx->r15 == 0) {
        // 0x8009602C: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_80096074;
    }
    // 0x8009602C: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x80096030: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80096034: bne         $a3, $v0, L_80096068
    if (ctx->r7 != ctx->r2) {
        // 0x80096038: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80096068;
    }
    // 0x80096038: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009603C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80096040: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80096044: jal         0x80000C98
    // 0x80096048: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_36;
    // 0x80096048: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_36:
    // 0x8009604C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096050: jal         0x800C01D8
    // 0x80096054: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_37;
    // 0x80096054: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_37:
    // 0x80096058: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8009605C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096060: b           L_80096454
    // 0x80096064: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
        goto L_80096454;
    // 0x80096064: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
L_80096068:
    // 0x80096068: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8009606C: b           L_80096454
    // 0x80096070: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80096454;
    // 0x80096070: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80096074:
    // 0x80096074: beq         $t4, $zero, L_8009608C
    if (ctx->r12 == 0) {
        // 0x80096078: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_8009608C;
    }
    // 0x80096078: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8009607C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80096080: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80096084: b           L_80096454
    // 0x80096088: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80096454;
    // 0x80096088: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8009608C:
    // 0x8009608C: blez        $t2, L_800961F8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80096090: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800961F8;
    }
    // 0x80096090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096094: andi        $v1, $t2, 0x3
    ctx->r3 = ctx->r10 & 0X3;
    // 0x80096098: beq         $v1, $zero, L_800960F8
    if (ctx->r3 == 0) {
        // 0x8009609C: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800960F8;
    }
    // 0x8009609C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800960A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800960A4: addiu       $t7, $t7, 0x6464
    ctx->r15 = ADD32(ctx->r15, 0X6464);
    // 0x800960A8: addu        $a1, $zero, $t7
    ctx->r5 = ADD32(0, ctx->r15);
    // 0x800960AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800960B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800960B4:
    // 0x800960B4: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x800960B8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800960BC: blez        $v1, L_800960D4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800960C0: nop
    
            goto L_800960D4;
    }
    // 0x800960C0: nop

    // 0x800960C4: bne         $a2, $v0, L_800960D4
    if (ctx->r6 != ctx->r2) {
        // 0x800960C8: nop
    
            goto L_800960D4;
    }
    // 0x800960C8: nop

    // 0x800960CC: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800960D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800960D4:
    // 0x800960D4: bgez        $v1, L_800960EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800960D8: nop
    
            goto L_800960EC;
    }
    // 0x800960D8: nop

    // 0x800960DC: bne         $a3, $v0, L_800960EC
    if (ctx->r7 != ctx->r2) {
        // 0x800960E0: nop
    
            goto L_800960EC;
    }
    // 0x800960E0: nop

    // 0x800960E4: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800960E8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800960EC:
    // 0x800960EC: bne         $t1, $a0, L_800960B4
    if (ctx->r9 != ctx->r4) {
        // 0x800960F0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800960B4;
    }
    // 0x800960F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800960F4: beq         $a0, $t2, L_800961F8
    if (ctx->r4 == ctx->r10) {
        // 0x800960F8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800961F8;
    }
L_800960F8:
    // 0x800960F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800960FC: addiu       $t8, $t8, 0x6464
    ctx->r24 = ADD32(ctx->r24, 0X6464);
    // 0x80096100: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x80096104: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x80096108: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8009610C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80096110:
    // 0x80096110: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80096114: nop

    // 0x80096118: blez        $v1, L_80096130
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009611C: nop
    
            goto L_80096130;
    }
    // 0x8009611C: nop

    // 0x80096120: bne         $a2, $v0, L_80096130
    if (ctx->r6 != ctx->r2) {
        // 0x80096124: nop
    
            goto L_80096130;
    }
    // 0x80096124: nop

    // 0x80096128: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x8009612C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80096130:
    // 0x80096130: bgez        $v1, L_80096148
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096134: nop
    
            goto L_80096148;
    }
    // 0x80096134: nop

    // 0x80096138: bne         $a3, $v0, L_80096148
    if (ctx->r7 != ctx->r2) {
        // 0x8009613C: nop
    
            goto L_80096148;
    }
    // 0x8009613C: nop

    // 0x80096140: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x80096144: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80096148:
    // 0x80096148: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x8009614C: nop

    // 0x80096150: blez        $v1, L_80096168
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096154: nop
    
            goto L_80096168;
    }
    // 0x80096154: nop

    // 0x80096158: bne         $a2, $v0, L_80096168
    if (ctx->r6 != ctx->r2) {
        // 0x8009615C: nop
    
            goto L_80096168;
    }
    // 0x8009615C: nop

    // 0x80096160: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x80096164: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80096168:
    // 0x80096168: bgez        $v1, L_80096180
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009616C: nop
    
            goto L_80096180;
    }
    // 0x8009616C: nop

    // 0x80096170: bne         $a3, $v0, L_80096180
    if (ctx->r7 != ctx->r2) {
        // 0x80096174: nop
    
            goto L_80096180;
    }
    // 0x80096174: nop

    // 0x80096178: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x8009617C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80096180:
    // 0x80096180: lb          $v1, 0x2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X2);
    // 0x80096184: nop

    // 0x80096188: blez        $v1, L_800961A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009618C: nop
    
            goto L_800961A0;
    }
    // 0x8009618C: nop

    // 0x80096190: bne         $a2, $v0, L_800961A0
    if (ctx->r6 != ctx->r2) {
        // 0x80096194: nop
    
            goto L_800961A0;
    }
    // 0x80096194: nop

    // 0x80096198: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x8009619C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800961A0:
    // 0x800961A0: bgez        $v1, L_800961B8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800961A4: nop
    
            goto L_800961B8;
    }
    // 0x800961A4: nop

    // 0x800961A8: bne         $a3, $v0, L_800961B8
    if (ctx->r7 != ctx->r2) {
        // 0x800961AC: nop
    
            goto L_800961B8;
    }
    // 0x800961AC: nop

    // 0x800961B0: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800961B4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800961B8:
    // 0x800961B8: lb          $v1, 0x3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X3);
    // 0x800961BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800961C0: blez        $v1, L_800961D8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800961C4: nop
    
            goto L_800961D8;
    }
    // 0x800961C4: nop

    // 0x800961C8: bne         $a2, $v0, L_800961D8
    if (ctx->r6 != ctx->r2) {
        // 0x800961CC: nop
    
            goto L_800961D8;
    }
    // 0x800961CC: nop

    // 0x800961D0: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800961D4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800961D8:
    // 0x800961D8: bgez        $v1, L_800961F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800961DC: nop
    
            goto L_800961F0;
    }
    // 0x800961DC: nop

    // 0x800961E0: bne         $a3, $v0, L_800961F0
    if (ctx->r7 != ctx->r2) {
        // 0x800961E4: nop
    
            goto L_800961F0;
    }
    // 0x800961E4: nop

    // 0x800961E8: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x800961EC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800961F0:
    // 0x800961F0: bne         $a1, $t1, L_80096110
    if (ctx->r5 != ctx->r9) {
        // 0x800961F4: nop
    
            goto L_80096110;
    }
    // 0x800961F4: nop

L_800961F8:
    // 0x800961F8: beq         $t3, $v0, L_80096454
    if (ctx->r11 == ctx->r2) {
        // 0x800961FC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80096454;
    }
    // 0x800961FC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096200: b           L_80096454
    // 0x80096204: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
        goto L_80096454;
    // 0x80096204: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80096208:
    // 0x80096208: beq         $t9, $zero, L_80096290
    if (ctx->r25 == 0) {
        // 0x8009620C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_80096290;
    }
    // 0x8009620C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096210: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096214: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x80096218: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8009621C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096220: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80096224: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80096228: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009622C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096230: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80096234: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80096238: lw          $v1, 0x6BF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6BF0);
    // 0x8009623C: lw          $t8, 0x6C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6C);
    // 0x80096240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80096244: bne         $v1, $t8, L_80096254
    if (ctx->r3 != ctx->r24) {
        // 0x80096248: nop
    
            goto L_80096254;
    }
    // 0x80096248: nop

    // 0x8009624C: b           L_80096454
    // 0x80096250: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
        goto L_80096454;
    // 0x80096250: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
L_80096254:
    // 0x80096254: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x80096258: nop

    // 0x8009625C: bne         $v1, $t5, L_8009626C
    if (ctx->r3 != ctx->r13) {
        // 0x80096260: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8009626C;
    }
    // 0x80096260: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80096264: b           L_80096454
    // 0x80096268: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
        goto L_80096454;
    // 0x80096268: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
L_8009626C:
    // 0x8009626C: jal         0x80000C98
    // 0x80096270: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_38;
    // 0x80096270: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_38:
    // 0x80096274: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096278: jal         0x800C01D8
    // 0x8009627C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_39;
    // 0x8009627C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_39:
    // 0x80096280: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80096284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096288: b           L_80096454
    // 0x8009628C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
        goto L_80096454;
    // 0x8009628C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80096290:
    // 0x80096290: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x80096294: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80096298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009629C: blez        $t2, L_80096448
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800962A0: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80096448;
    }
    // 0x800962A0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800962A4: andi        $v1, $t2, 0x3
    ctx->r3 = ctx->r10 & 0X3;
    // 0x800962A8: beq         $v1, $zero, L_80096310
    if (ctx->r3 == 0) {
        // 0x800962AC: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80096310;
    }
    // 0x800962AC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800962B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800962B4: addiu       $t4, $t4, 0x6464
    ctx->r12 = ADD32(ctx->r12, 0X6464);
    // 0x800962B8: addu        $a1, $zero, $t4
    ctx->r5 = ADD32(0, ctx->r12);
L_800962BC:
    // 0x800962BC: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x800962C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800962C4: bgez        $v1, L_800962EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800962C8: nop
    
            goto L_800962EC;
    }
    // 0x800962C8: nop

    // 0x800962CC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800962D0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800962D4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800962D8: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800962DC: beq         $at, $zero, L_800962EC
    if (ctx->r1 == 0) {
        // 0x800962E0: nop
    
            goto L_800962EC;
    }
    // 0x800962E0: nop

    // 0x800962E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800962E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800962EC:
    // 0x800962EC: blez        $v1, L_80096304
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800962F0: nop
    
            goto L_80096304;
    }
    // 0x800962F0: nop

    // 0x800962F4: blez        $v0, L_80096304
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800962F8: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80096304;
    }
    // 0x800962F8: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800962FC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80096300: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80096304:
    // 0x80096304: bne         $a3, $a0, L_800962BC
    if (ctx->r7 != ctx->r4) {
        // 0x80096308: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800962BC;
    }
    // 0x80096308: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009630C: beq         $a0, $t2, L_80096448
    if (ctx->r4 == ctx->r10) {
        // 0x80096310: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80096448;
    }
L_80096310:
    // 0x80096310: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80096314: addiu       $t9, $t9, 0x6464
    ctx->r25 = ADD32(ctx->r25, 0X6464);
    // 0x80096318: addu        $a1, $a0, $t9
    ctx->r5 = ADD32(ctx->r4, ctx->r25);
    // 0x8009631C: addu        $a3, $t2, $t9
    ctx->r7 = ADD32(ctx->r10, ctx->r25);
L_80096320:
    // 0x80096320: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80096324: nop

    // 0x80096328: bgez        $v1, L_80096350
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009632C: nop
    
            goto L_80096350;
    }
    // 0x8009632C: nop

    // 0x80096330: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80096334: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80096338: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8009633C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80096340: beq         $at, $zero, L_80096350
    if (ctx->r1 == 0) {
        // 0x80096344: nop
    
            goto L_80096350;
    }
    // 0x80096344: nop

    // 0x80096348: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8009634C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80096350:
    // 0x80096350: blez        $v1, L_80096368
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80096354: nop
    
            goto L_80096368;
    }
    // 0x80096354: nop

    // 0x80096358: blez        $v0, L_80096368
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009635C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80096368;
    }
    // 0x8009635C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80096360: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80096364: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80096368:
    // 0x80096368: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x8009636C: nop

    // 0x80096370: bgez        $v1, L_80096398
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096374: nop
    
            goto L_80096398;
    }
    // 0x80096374: nop

    // 0x80096378: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8009637C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80096380: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x80096384: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80096388: beq         $at, $zero, L_80096398
    if (ctx->r1 == 0) {
        // 0x8009638C: nop
    
            goto L_80096398;
    }
    // 0x8009638C: nop

    // 0x80096390: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80096394: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80096398:
    // 0x80096398: blez        $v1, L_800963B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009639C: nop
    
            goto L_800963B0;
    }
    // 0x8009639C: nop

    // 0x800963A0: blez        $v0, L_800963B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800963A4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800963B0;
    }
    // 0x800963A4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800963A8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800963AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800963B0:
    // 0x800963B0: lb          $v1, 0x2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X2);
    // 0x800963B4: nop

    // 0x800963B8: bgez        $v1, L_800963E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800963BC: nop
    
            goto L_800963E0;
    }
    // 0x800963BC: nop

    // 0x800963C0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800963C4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800963C8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800963CC: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800963D0: beq         $at, $zero, L_800963E0
    if (ctx->r1 == 0) {
        // 0x800963D4: nop
    
            goto L_800963E0;
    }
    // 0x800963D4: nop

    // 0x800963D8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800963DC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800963E0:
    // 0x800963E0: blez        $v1, L_800963F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800963E4: nop
    
            goto L_800963F8;
    }
    // 0x800963E4: nop

    // 0x800963E8: blez        $v0, L_800963F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800963EC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800963F8;
    }
    // 0x800963EC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800963F0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800963F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800963F8:
    // 0x800963F8: lb          $v1, 0x3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X3);
    // 0x800963FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80096400: bgez        $v1, L_80096428
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80096404: nop
    
            goto L_80096428;
    }
    // 0x80096404: nop

    // 0x80096408: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8009640C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80096410: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80096414: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80096418: beq         $at, $zero, L_80096428
    if (ctx->r1 == 0) {
        // 0x8009641C: nop
    
            goto L_80096428;
    }
    // 0x8009641C: nop

    // 0x80096420: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80096424: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80096428:
    // 0x80096428: blez        $v1, L_80096440
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009642C: nop
    
            goto L_80096440;
    }
    // 0x8009642C: nop

    // 0x80096430: blez        $v0, L_80096440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096434: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80096440;
    }
    // 0x80096434: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80096438: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8009643C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80096440:
    // 0x80096440: bne         $a1, $a3, L_80096320
    if (ctx->r5 != ctx->r7) {
        // 0x80096444: nop
    
            goto L_80096320;
    }
    // 0x80096444: nop

L_80096448:
    // 0x80096448: beq         $t3, $v0, L_80096454
    if (ctx->r11 == ctx->r2) {
        // 0x8009644C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80096454;
    }
    // 0x8009644C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80096450: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_80096454:
    // 0x80096454: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80096458: nop

    // 0x8009645C: beq         $t9, $zero, L_80096474
    if (ctx->r25 == 0) {
        // 0x80096460: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80096474;
    }
    // 0x80096460: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80096464: jal         0x80001D04
    // 0x80096468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_40;
    // 0x80096468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x8009646C: b           L_80096714
    // 0x80096470: nop

        goto L_80096714;
    // 0x80096470: nop

L_80096474:
    // 0x80096474: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80096478: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8009647C: beq         $t4, $zero, L_80096494
    if (ctx->r12 == 0) {
        // 0x80096480: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80096494;
    }
    // 0x80096480: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80096484: jal         0x80001D04
    // 0x80096488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_41;
    // 0x80096488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x8009648C: b           L_80096714
    // 0x80096490: nop

        goto L_80096714;
    // 0x80096490: nop

L_80096494:
    // 0x80096494: beq         $t6, $zero, L_80096714
    if (ctx->r14 == 0) {
        // 0x80096498: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80096714;
    }
    // 0x80096498: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009649C: jal         0x80001D04
    // 0x800964A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_42;
    // 0x800964A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x800964A4: b           L_80096714
    // 0x800964A8: nop

        goto L_80096714;
    // 0x800964A8: nop

L_800964AC:
    // 0x800964AC: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x800964B0: beq         $t7, $zero, L_80096714
    if (ctx->r15 == 0) {
        // 0x800964B4: nop
    
            goto L_80096714;
    }
    // 0x800964B4: nop

    // 0x800964B8: jal         0x80000C98
    // 0x800964BC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_43;
    // 0x800964BC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_43:
    // 0x800964C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800964C4: jal         0x800C01D8
    // 0x800964C8: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_44;
    // 0x800964C8: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_44:
    // 0x800964CC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800964D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800964D4: b           L_80096714
    // 0x800964D8: sw          $t8, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r24;
        goto L_80096714;
    // 0x800964D8: sw          $t8, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r24;
L_800964DC:
    // 0x800964DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800964E0: lw          $t5, -0xB84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB84);
    // 0x800964E4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800964E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800964EC: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x800964F0: sw          $t4, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r12;
    // 0x800964F4: slti        $at, $t4, 0x1F
    ctx->r1 = SIGNED(ctx->r12) < 0X1F ? 1 : 0;
    // 0x800964F8: bne         $at, $zero, L_80096714
    if (ctx->r1 != 0) {
        // 0x800964FC: nop
    
            goto L_80096714;
    }
    // 0x800964FC: nop

    // 0x80096500: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80096504: nop

    // 0x80096508: lb          $t6, 0x117($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X117);
    // 0x8009650C: nop

    // 0x80096510: beq         $t6, $zero, L_8009655C
    if (ctx->r14 == 0) {
        // 0x80096514: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8009655C;
    }
    // 0x80096514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096518: lb          $v0, 0x58($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X58);
    // 0x8009651C: nop

    // 0x80096520: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x80096524: beq         $t7, $zero, L_80096548
    if (ctx->r15 == 0) {
        // 0x80096528: andi        $t5, $v0, 0x80
        ctx->r13 = ctx->r2 & 0X80;
            goto L_80096548;
    }
    // 0x80096528: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
    // 0x8009652C: jal         0x8006EBC4
    // 0x80096530: nop

    mark_to_write_flap_times(rdram, ctx);
        goto after_45;
    // 0x80096530: nop

    after_45:
    // 0x80096534: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80096538: nop

    // 0x8009653C: lb          $v0, 0x58($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X58);
    // 0x80096540: nop

    // 0x80096544: andi        $t5, $v0, 0x80
    ctx->r13 = ctx->r2 & 0X80;
L_80096548:
    // 0x80096548: beq         $t5, $zero, L_8009655C
    if (ctx->r13 == 0) {
        // 0x8009654C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8009655C;
    }
    // 0x8009654C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096550: jal         0x8006EBE0
    // 0x80096554: nop

    mark_to_write_course_times(rdram, ctx);
        goto after_46;
    // 0x80096554: nop

    after_46:
    // 0x80096558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8009655C:
    // 0x8009655C: jal         0x80066894
    // 0x80096560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_47;
    // 0x80096560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80096564: jal         0x80096790
    // 0x80096568: nop

    postrace_free(rdram, ctx);
        goto after_48;
    // 0x80096568: nop

    after_48:
    // 0x8009656C: jal         0x800C5620
    // 0x80096570: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_49;
    // 0x80096570: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_49:
    // 0x80096574: jal         0x800C5494
    // 0x80096578: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_50;
    // 0x80096578: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_50:
    // 0x8009657C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096580: lb          $v0, 0x6C28($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6C28);
    // 0x80096584: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80096588: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8009658C: bne         $at, $zero, L_80096600
    if (ctx->r1 != 0) {
        // 0x80096590: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80096600;
    }
    // 0x80096590: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80096594: bne         $v0, $at, L_800965CC
    if (ctx->r2 != ctx->r1) {
        // 0x80096598: nop
    
            goto L_800965CC;
    }
    // 0x80096598: nop

    // 0x8009659C: jal         0x8001E29C
    // 0x800965A0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_51;
    // 0x800965A0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_51:
    // 0x800965A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800965A8: lb          $a1, 0x6C28($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6C28);
    // 0x800965AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800965B0: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x800965B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800965B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800965BC: jal         0x8009ABD8
    // 0x800965C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_52;
    // 0x800965C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_52:
    // 0x800965C4: b           L_800965F8
    // 0x800965C8: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
        goto L_800965F8;
    // 0x800965C8: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
L_800965CC:
    // 0x800965CC: jal         0x8001E29C
    // 0x800965D0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_53;
    // 0x800965D0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_53:
    // 0x800965D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800965D8: lb          $a1, 0x6C28($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X6C28);
    // 0x800965DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800965E0: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800965E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800965E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800965EC: jal         0x8009ABD8
    // 0x800965F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_54;
    // 0x800965F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_54:
    // 0x800965F4: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
L_800965F8:
    // 0x800965F8: b           L_80096714
    // 0x800965FC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096714;
    // 0x800965FC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80096600:
    // 0x80096600: lw          $t4, 0xFE8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XFE8);
    // 0x80096604: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80096608: beq         $t4, $zero, L_80096618
    if (ctx->r12 == 0) {
        // 0x8009660C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80096618;
    }
    // 0x8009660C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80096610: b           L_80096714
    // 0x80096614: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_80096714;
    // 0x80096614: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_80096618:
    // 0x80096618: lw          $t7, -0xB44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB44);
    // 0x8009661C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096620: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80096624: bne         $at, $zero, L_80096638
    if (ctx->r1 != 0) {
        // 0x80096628: addiu       $a2, $a2, 0x6A68
        ctx->r6 = ADD32(ctx->r6, 0X6A68);
            goto L_80096638;
    }
    // 0x80096628: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x8009662C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80096630: b           L_80096714
    // 0x80096634: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80096714;
    // 0x80096634: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80096638:
    // 0x80096638: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8009663C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096640: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80096644: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80096648: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8009664C: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80096650: lw          $v1, 0x6BF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6BF0);
    // 0x80096654: lw          $t4, 0x5C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X5C);
    // 0x80096658: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009665C: bne         $v1, $t4, L_800966C8
    if (ctx->r3 != ctx->r12) {
        // 0x80096660: nop
    
            goto L_800966C8;
    }
    // 0x80096660: nop

    // 0x80096664: lw          $t6, -0xB48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB48);
    // 0x80096668: nop

    // 0x8009666C: bne         $t6, $zero, L_800966C0
    if (ctx->r14 != 0) {
        // 0x80096670: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800966C0;
    }
    // 0x80096670: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80096674: jal         0x8006EB14
    // 0x80096678: nop

    get_ingame_map_id(rdram, ctx);
        goto after_55;
    // 0x80096678: nop

    after_55:
    // 0x8009667C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80096680: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80096684: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80096688: lh          $t8, 0x758($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X758);
    // 0x8009668C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80096690: beq         $t8, $at, L_800966C0
    if (ctx->r24 == ctx->r1) {
        // 0x80096694: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800966C0;
    }
    // 0x80096694: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80096698: jal         0x8006EB14
    // 0x8009669C: nop

    get_ingame_map_id(rdram, ctx);
        goto after_56;
    // 0x8009669C: nop

    after_56:
    // 0x800966A0: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800966A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800966A8: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800966AC: lhu         $a0, 0x758($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X758);
    // 0x800966B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800966B4: jal         0x80000FDC
    // 0x800966B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_57;
    // 0x800966B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_57:
    // 0x800966BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_800966C0:
    // 0x800966C0: b           L_80096714
    // 0x800966C4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096714;
    // 0x800966C4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800966C8:
    // 0x800966C8: lw          $t4, 0x60($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X60);
    // 0x800966CC: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800966D0: bne         $v1, $t4, L_800966E0
    if (ctx->r3 != ctx->r12) {
        // 0x800966D4: nop
    
            goto L_800966E0;
    }
    // 0x800966D4: nop

    // 0x800966D8: b           L_80096714
    // 0x800966DC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_80096714;
    // 0x800966DC: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_800966E0:
    // 0x800966E0: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x800966E4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800966E8: bne         $v1, $t7, L_800966F8
    if (ctx->r3 != ctx->r15) {
        // 0x800966EC: nop
    
            goto L_800966F8;
    }
    // 0x800966EC: nop

    // 0x800966F0: b           L_80096714
    // 0x800966F4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80096714;
    // 0x800966F4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800966F8:
    // 0x800966F8: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x800966FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80096700: bne         $v1, $t5, L_80096710
    if (ctx->r3 != ctx->r13) {
        // 0x80096704: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_80096710;
    }
    // 0x80096704: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80096708: b           L_80096714
    // 0x8009670C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
        goto L_80096714;
    // 0x8009670C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80096710:
    // 0x80096710: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80096714:
    // 0x80096714: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096718: lw          $v0, 0x63C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63C4);
    // 0x8009671C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80096720: blez        $v0, L_80096750
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096724: nop
    
            goto L_80096750;
    }
    // 0x80096724: nop

    // 0x80096728: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009672C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096730: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x80096734: sw          $t7, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r15;
    // 0x80096738: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009673C: lw          $t8, 0x63C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C4);
    // 0x80096740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096744: bgez        $t8, L_80096750
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80096748: nop
    
            goto L_80096750;
    }
    // 0x80096748: nop

    // 0x8009674C: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_80096750:
    // 0x80096750: lw          $t5, 0x63A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63A0);
    // 0x80096754: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80096758: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009675C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80096760: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80096764: lw          $t4, 0x63A8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63A8);
    // 0x80096768: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009676C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80096770: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80096774: lw          $t7, 0x63AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63AC);
    // 0x80096778: nop

    // 0x8009677C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80096780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80096784: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80096788: jr          $ra
    // 0x8009678C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8009678C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sndp_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004520: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004524: addiu       $v0, $v0, -0x3950
    ctx->r2 = ADD32(ctx->r2, -0X3950);
    // 0x80004528: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000452C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004530: bne         $a0, $t6, L_80004544
    if (ctx->r4 != ctx->r14) {
        // 0x80004534: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80004544;
    }
    // 0x80004534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004538: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000453C: nop

    // 0x80004540: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80004544:
    // 0x80004544: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80004548: nop

    // 0x8000454C: bne         $a0, $t8, L_80004560
    if (ctx->r4 != ctx->r24) {
        // 0x80004550: nop
    
            goto L_80004560;
    }
    // 0x80004550: nop

    // 0x80004554: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80004558: nop

    // 0x8000455C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80004560:
    // 0x80004560: jal         0x800C8760
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80004564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80004568: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000456C: addiu       $v0, $v0, -0x3950
    ctx->r2 = ADD32(ctx->r2, -0X3950);
    // 0x80004570: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80004574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80004578: beq         $v1, $zero, L_8000459C
    if (ctx->r3 == 0) {
        // 0x8000457C: nop
    
            goto L_8000459C;
    }
    // 0x8000457C: nop

    // 0x80004580: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80004584: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80004588: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8000458C: nop

    // 0x80004590: sw          $a0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r4;
    // 0x80004594: b           L_800045A8
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
        goto L_800045A8;
    // 0x80004598: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_8000459C:
    // 0x8000459C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800045A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800045A4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_800045A8:
    // 0x800045A8: lbu         $t1, 0x3E($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3E);
    // 0x800045AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800045B0: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800045B4: beq         $t2, $zero, L_800045CC
    if (ctx->r10 == 0) {
        // 0x800045B8: addiu       $v0, $v0, -0x393C
        ctx->r2 = ADD32(ctx->r2, -0X393C);
            goto L_800045CC;
    }
    // 0x800045B8: addiu       $v0, $v0, -0x393C
    ctx->r2 = ADD32(ctx->r2, -0X393C);
    // 0x800045BC: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800045C0: nop

    // 0x800045C4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800045C8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_800045CC:
    // 0x800045CC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800045D0: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
    // 0x800045D4: beq         $v0, $zero, L_800045F8
    if (ctx->r2 == 0) {
        // 0x800045D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800045F8;
    }
    // 0x800045D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800045DC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800045E0: nop

    // 0x800045E4: bne         $a0, $t5, L_800045F0
    if (ctx->r4 != ctx->r13) {
        // 0x800045E8: nop
    
            goto L_800045F0;
    }
    // 0x800045E8: nop

    // 0x800045EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800045F0:
    // 0x800045F0: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800045F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800045F8:
    // 0x800045F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800045FC: jr          $ra
    // 0x80004600: nop

    return;
    // 0x80004600: nop

;}
RECOMP_FUNC void render_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B58: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x800C5B5C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800C5B60: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5B64: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C5B68: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800C5B6C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C5B70: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5B74: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C5B78: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800C5B7C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800C5B80: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C5B84: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C5B88: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C5B8C: sw          $a2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r6;
    // 0x800C5B90: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5B94: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C5B98: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C5B9C: beq         $t8, $zero, L_800C5DF4
    if (ctx->r24 == 0) {
        // 0x800C5BA0: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800C5DF4;
    }
    // 0x800C5BA0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C5BA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C5BA8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C5BAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C5BB0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C5BB4: addiu       $t3, $t3, 0x3690
    ctx->r11 = ADD32(ctx->r11, 0X3690);
    // 0x800C5BB8: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800C5BBC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C5BC0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C5BC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C5BC8: lui         $t5, 0x702
    ctx->r13 = S32(0X702 << 16);
    // 0x800C5BCC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C5BD0: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C5BD4: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C5BD8: addiu       $t6, $t6, 0x36D8
    ctx->r14 = ADD32(ctx->r14, 0X36D8);
    // 0x800C5BDC: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800C5BE0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C5BE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C5BE8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C5BEC: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C5BF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800C5BF4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800C5BF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C5BFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C5C00: lh          $t1, 0x4($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X4);
    // 0x800C5C04: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C5C08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5C0C: subu        $t9, $t0, $t1
    ctx->r25 = SUB32(ctx->r8, ctx->r9);
    // 0x800C5C10: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800C5C14: bne         $at, $zero, L_800C5C38
    if (ctx->r1 != 0) {
        // 0x800C5C18: addiu       $a1, $t1, -0x2
        ctx->r5 = ADD32(ctx->r9, -0X2);
            goto L_800C5C38;
    }
    // 0x800C5C18: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    // 0x800C5C1C: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C5C20: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C5C24: addiu       $a3, $t1, 0x2
    ctx->r7 = ADD32(ctx->r9, 0X2);
    // 0x800C5C28: subu        $t2, $v0, $s0
    ctx->r10 = SUB32(ctx->r2, ctx->r16);
    // 0x800C5C2C: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800C5C30: beq         $at, $zero, L_800C5C5C
    if (ctx->r1 == 0) {
        // 0x800C5C34: addiu       $a2, $s0, 0x2
        ctx->r6 = ADD32(ctx->r16, 0X2);
            goto L_800C5C5C;
    }
    // 0x800C5C34: addiu       $a2, $s0, 0x2
    ctx->r6 = ADD32(ctx->r16, 0X2);
L_800C5C38:
    // 0x800C5C38: lh          $t3, 0xA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XA);
    // 0x800C5C3C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C5C40: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x800C5C44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C5C48: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C5C4C: jal         0x800C5AA0
    // 0x800C5C50: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_0;
    // 0x800C5C50: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    after_0:
    // 0x800C5C54: b           L_800C5CEC
    // 0x800C5C58: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_800C5CEC;
    // 0x800C5C58: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C5C5C:
    // 0x800C5C5C: addiu       $t5, $v0, -0x2
    ctx->r13 = ADD32(ctx->r2, -0X2);
    // 0x800C5C60: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C5C64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5C68: jal         0x800C5AA0
    // 0x800C5C6C: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_1;
    // 0x800C5C6C: addiu       $a1, $t1, -0x2
    ctx->r5 = ADD32(ctx->r9, -0X2);
    after_1:
    // 0x800C5C70: lh          $s0, 0x6($s1)
    ctx->r16 = MEM_H(ctx->r17, 0X6);
    // 0x800C5C74: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C5C78: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C5C7C: addiu       $t6, $s0, 0x2
    ctx->r14 = ADD32(ctx->r16, 0X2);
    // 0x800C5C80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C5C84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5C88: addiu       $a2, $s0, -0x2
    ctx->r6 = ADD32(ctx->r16, -0X2);
    // 0x800C5C8C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C5C90: jal         0x800C5AA0
    // 0x800C5C94: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_2;
    // 0x800C5C94: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_2:
    // 0x800C5C98: lh          $t0, 0x8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X8);
    // 0x800C5C9C: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C5CA0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x800C5CA4: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x800C5CA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C5CAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5CB0: addiu       $a1, $t0, -0x2
    ctx->r5 = ADD32(ctx->r8, -0X2);
    // 0x800C5CB4: addiu       $a3, $t0, 0x2
    ctx->r7 = ADD32(ctx->r8, 0X2);
    // 0x800C5CB8: jal         0x800C5AA0
    // 0x800C5CBC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_3;
    // 0x800C5CBC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_3:
    // 0x800C5CC0: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x800C5CC4: lh          $a1, 0x4($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X4);
    // 0x800C5CC8: lh          $a3, 0x8($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X8);
    // 0x800C5CCC: addiu       $t9, $v0, 0x2
    ctx->r25 = ADD32(ctx->r2, 0X2);
    // 0x800C5CD0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C5CD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5CD8: addiu       $a2, $v0, -0x2
    ctx->r6 = ADD32(ctx->r2, -0X2);
    // 0x800C5CDC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C5CE0: jal         0x800C5AA0
    // 0x800C5CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    render_fill_rectangle(rdram, ctx);
        goto after_4;
    // 0x800C5CE4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x800C5CE8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_800C5CEC:
    // 0x800C5CEC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C5CF0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C5CF4: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x800C5CF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C5CFC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C5D00: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C5D04: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800C5D08: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800C5D0C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x800C5D10: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C5D14: lbu         $t7, 0x10($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X10);
    // 0x800C5D18: lbu         $t2, 0x11($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X11);
    // 0x800C5D1C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800C5D20: lbu         $t6, 0x12($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X12);
    // 0x800C5D24: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800C5D28: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x800C5D2C: lbu         $t8, 0x13($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X13);
    // 0x800C5D30: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C5D34: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800C5D38: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x800C5D3C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C5D40: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C5D44: lb          $t5, 0x3710($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X3710);
    // 0x800C5D48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C5D4C: bltz        $t5, L_800C5DDC
    if (SIGNED(ctx->r13) < 0) {
        // 0x800C5D50: addiu       $s0, $t6, 0x3710
        ctx->r16 = ADD32(ctx->r14, 0X3710);
            goto L_800C5DDC;
    }
    // 0x800C5D50: addiu       $s0, $t6, 0x3710
    ctx->r16 = ADD32(ctx->r14, 0X3710);
    // 0x800C5D54: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800C5D58: nop

L_800C5D5C:
    // 0x800C5D5C: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x800C5D60: lb          $t7, 0x1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1);
    // 0x800C5D64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5D68: beq         $t7, $zero, L_800C5D80
    if (ctx->r15 == 0) {
        // 0x800C5D6C: addu        $a1, $v0, $t4
        ctx->r5 = ADD32(ctx->r2, ctx->r12);
            goto L_800C5D80;
    }
    // 0x800C5D6C: addu        $a1, $v0, $t4
    ctx->r5 = ADD32(ctx->r2, ctx->r12);
    // 0x800C5D70: lb          $t2, 0x2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X2);
    // 0x800C5D74: lh          $t9, 0xA($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XA);
    // 0x800C5D78: b           L_800C5D90
    // 0x800C5D7C: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
        goto L_800C5D90;
    // 0x800C5D7C: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
L_800C5D80:
    // 0x800C5D80: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800C5D84: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x800C5D88: nop

    // 0x800C5D8C: addu        $a2, $t8, $t3
    ctx->r6 = ADD32(ctx->r24, ctx->r11);
L_800C5D90:
    // 0x800C5D90: lh          $t5, 0x8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X8);
    // 0x800C5D94: lb          $t6, 0x3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3);
    // 0x800C5D98: subu        $a3, $t5, $v0
    ctx->r7 = SUB32(ctx->r13, ctx->r2);
    // 0x800C5D9C: beq         $t6, $zero, L_800C5DB4
    if (ctx->r14 == 0) {
        // 0x800C5DA0: nop
    
            goto L_800C5DB4;
    }
    // 0x800C5DA0: nop

    // 0x800C5DA4: lb          $t4, 0x4($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X4);
    // 0x800C5DA8: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800C5DAC: b           L_800C5DC4
    // 0x800C5DB0: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
        goto L_800C5DC4;
    // 0x800C5DB0: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
L_800C5DB4:
    // 0x800C5DB4: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x800C5DB8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x800C5DBC: nop

    // 0x800C5DC0: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
L_800C5DC4:
    // 0x800C5DC4: jal         0x800C5AA0
    // 0x800C5DC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_fill_rectangle(rdram, ctx);
        goto after_5;
    // 0x800C5DC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800C5DCC: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x800C5DD0: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x800C5DD4: bgez        $v0, L_800C5D5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800C5DD8: nop
    
            goto L_800C5D5C;
    }
    // 0x800C5DD8: nop

L_800C5DDC:
    // 0x800C5DDC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C5DE0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C5DE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C5DE8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800C5DEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C5DF0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800C5DF4:
    // 0x800C5DF4: beq         $s2, $zero, L_800C5E4C
    if (ctx->r18 == 0) {
        // 0x800C5DF8: nop
    
            goto L_800C5E4C;
    }
    // 0x800C5DF8: nop

    // 0x800C5DFC: lw          $t5, 0x188($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X188);
    // 0x800C5E00: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C5E04: beq         $t5, $zero, L_800C5E4C
    if (ctx->r13 == 0) {
        // 0x800C5E08: addiu       $s0, $s0, 0x36E8
        ctx->r16 = ADD32(ctx->r16, 0X36E8);
            goto L_800C5E4C;
    }
    // 0x800C5E08: addiu       $s0, $s0, 0x36E8
    ctx->r16 = ADD32(ctx->r16, 0X36E8);
    // 0x800C5E0C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C5E10: nop

    // 0x800C5E14: bne         $t6, $zero, L_800C5E30
    if (ctx->r14 != 0) {
        // 0x800C5E18: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800C5E30;
    }
    // 0x800C5E18: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800C5E1C: jal         0x8009E9A0
    // 0x800C5E20: nop

    dialogue_open_stub(rdram, ctx);
        goto after_6;
    // 0x800C5E20: nop

    after_6:
    // 0x800C5E24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C5E28: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800C5E2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800C5E30:
    // 0x800C5E30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C5E34: lw          $a3, 0x188($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X188);
    // 0x800C5E38: sb          $t7, -0x580C($at)
    MEM_B(-0X580C, ctx->r1) = ctx->r15;
    // 0x800C5E3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C5E40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C5E44: jal         0x8009E9B0
    // 0x800C5E48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    dialogue_ortho(rdram, ctx);
        goto after_7;
    // 0x800C5E48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
L_800C5E4C:
    // 0x800C5E4C: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
    // 0x800C5E50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5E54: beq         $s0, $zero, L_800C5F40
    if (ctx->r16 == 0) {
        // 0x800C5E58: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800C5F40;
    }
    // 0x800C5E58: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C5E5C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C5E60: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
L_800C5E64:
    // 0x800C5E64: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800C5E68: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x800C5E6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C5E70: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x800C5E74: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x800C5E78: lh          $t5, 0xE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE);
    // 0x800C5E7C: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x800C5E80: nop

    // 0x800C5E84: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C5E88: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x800C5E8C: lbu         $t4, 0x10($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X10);
    // 0x800C5E90: nop

    // 0x800C5E94: sb          $t4, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r12;
    // 0x800C5E98: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800C5E9C: nop

    // 0x800C5EA0: sb          $t7, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r15;
    // 0x800C5EA4: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x800C5EA8: nop

    // 0x800C5EAC: sb          $t2, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r10;
    // 0x800C5EB0: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800C5EB4: nop

    // 0x800C5EB8: sb          $t9, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r25;
    // 0x800C5EBC: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x800C5EC0: nop

    // 0x800C5EC4: sb          $t8, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r24;
    // 0x800C5EC8: lbu         $t3, 0x15($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X15);
    // 0x800C5ECC: nop

    // 0x800C5ED0: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x800C5ED4: lbu         $t5, 0x16($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X16);
    // 0x800C5ED8: nop

    // 0x800C5EDC: sb          $t5, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r13;
    // 0x800C5EE0: lbu         $t6, 0x17($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17);
    // 0x800C5EE4: nop

    // 0x800C5EE8: sb          $t6, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r14;
    // 0x800C5EEC: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    // 0x800C5EF0: nop

    // 0x800C5EF4: sb          $t4, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r12;
    // 0x800C5EF8: lbu         $t7, 0x19($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X19);
    // 0x800C5EFC: nop

    // 0x800C5F00: sb          $t7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r15;
    // 0x800C5F04: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x800C5F08: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800C5F0C: jal         0x800C5F60
    // 0x800C5F10: nop

    parse_string_with_number(rdram, ctx);
        goto after_8;
    // 0x800C5F10: nop

    after_8:
    // 0x800C5F14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C5F18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C5F1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800C5F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C5F24: jal         0x800C45A4
    // 0x800C5F28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    render_text_string(rdram, ctx);
        goto after_9;
    // 0x800C5F28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x800C5F2C: lw          $s0, 0x1C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1C);
    // 0x800C5F30: nop

    // 0x800C5F34: bne         $s0, $zero, L_800C5E64
    if (ctx->r16 != 0) {
        // 0x800C5F38: nop
    
            goto L_800C5E64;
    }
    // 0x800C5F38: nop

    // 0x800C5F3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800C5F40:
    // 0x800C5F40: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C5F44: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C5F48: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C5F4C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F50: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F54: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800C5F58: jr          $ra
    // 0x800C5F5C: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x800C5F5C: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void trackmenu_set_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800828BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800828C0: jal         0x8006EA90
    // 0x800828C4: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x800828C4: nop

    after_0:
    // 0x800828C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800828CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800828D0: jal         0x8006B224
    // 0x800828D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    level_count(rdram, ctx);
        goto after_1;
    // 0x800828D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x800828D8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800828DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800828E0: blez        $t6, L_80082964
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800828E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082964;
    }
    // 0x800828E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800828E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800828EC: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x800828F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800828F4:
    // 0x800828F4: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800828F8: nop

    // 0x800828FC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80082900: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x80082904: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80082908:
    // 0x80082908: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8008290C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x80082910: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80082914: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80082918: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008291C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80082920: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80082924: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80082928: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8008292C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80082930: nop

    // 0x80082934: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x80082938: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008293C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80082940: nop

    // 0x80082944: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80082948: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8008294C: bne         $at, $zero, L_80082908
    if (ctx->r1 != 0) {
        // 0x80082950: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_80082908;
    }
    // 0x80082950: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80082954: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80082958: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008295C: bne         $a1, $t2, L_800828F4
    if (ctx->r5 != ctx->r10) {
        // 0x80082960: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800828F4;
    }
    // 0x80082960: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80082964:
    // 0x80082964: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80082968: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008296C: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x80082970: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80082974: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x80082978: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x8008297C: addiu       $v1, $v1, 0x653C
    ctx->r3 = ADD32(ctx->r3, 0X653C);
    // 0x80082980: addiu       $v0, $v0, 0x6530
    ctx->r2 = ADD32(ctx->r2, 0X6530);
L_80082984:
    // 0x80082984: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80082988: lhu         $t3, 0xE($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0XE);
    // 0x8008298C: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80082990: lhu         $t0, 0x8($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X8);
    // 0x80082994: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80082998: sh          $t6, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r14;
    // 0x8008299C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800829A0: lhu         $t1, 0xC($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XC);
    // 0x800829A4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x800829A8: lw          $t5, 0x10($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X10);
    // 0x800829AC: or          $t9, $t0, $t8
    ctx->r25 = ctx->r8 | ctx->r24;
    // 0x800829B0: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x800829B4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800829B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800829BC: lhu         $t4, 0xC($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0XC);
    // 0x800829C0: nop

    // 0x800829C4: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800829C8: sh          $t3, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r11;
    // 0x800829CC: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800829D0: nop

    // 0x800829D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800829D8: nop

    // 0x800829DC: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x800829E0: bne         $v0, $v1, L_80082984
    if (ctx->r2 != ctx->r3) {
        // 0x800829E4: sw          $t0, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r8;
            goto L_80082984;
    }
    // 0x800829E4: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    // 0x800829E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800829EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800829F0: jr          $ra
    // 0x800829F4: nop

    return;
    // 0x800829F4: nop

;}
RECOMP_FUNC void alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ED00: addiu       $v0, $v0, 0x350C
    ctx->r2 = ADD32(ctx->r2, 0X350C);
    // 0x8006ED04: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ED08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006ED0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006ED10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006ED14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006ED18: beq         $a0, $t6, L_8006EF10
    if (ctx->r4 == ctx->r14) {
        // 0x8006ED1C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8006EF10;
    }
    // 0x8006ED1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006ED20: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8006ED24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006ED28: jal         0x800710B0
    // 0x8006ED2C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006ED2C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006ED30: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006ED34: addiu       $s1, $s1, 0x11F0
    ctx->r17 = ADD32(ctx->r17, 0X11F0);
    // 0x8006ED38: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006ED3C: jal         0x80071140
    // 0x8006ED40: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8006ED40: nop

    after_1:
    // 0x8006ED44: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006ED48: jal         0x80071140
    // 0x8006ED4C: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006ED4C: nop

    after_2:
    // 0x8006ED50: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8006ED54: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8006ED58: addiu       $t8, $t8, -0x2C20
    ctx->r24 = ADD32(ctx->r24, -0X2C20);
    // 0x8006ED5C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006ED60: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006ED64: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8006ED68: addiu       $t9, $t9, -0x2C50
    ctx->r25 = ADD32(ctx->r25, -0X2C50);
    // 0x8006ED6C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8006ED70: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006ED74: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006ED78: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006ED7C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006ED80: addiu       $t5, $t5, -0x2C40
    ctx->r13 = ADD32(ctx->r13, -0X2C40);
    // 0x8006ED84: addiu       $t4, $t4, -0x2C30
    ctx->r12 = ADD32(ctx->r12, -0X2C30);
    // 0x8006ED88: addu        $a3, $t7, $t4
    ctx->r7 = ADD32(ctx->r15, ctx->r12);
    // 0x8006ED8C: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x8006ED90: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8006ED94: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8006ED98: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x8006ED9C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006EDA0: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8006EDA4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8006EDA8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006EDAC: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8006EDB0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8006EDB4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8006EDB8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8006EDBC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8006EDC0: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // 0x8006EDC4: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006EDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006EDCC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8006EDD0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006EDD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006EDD8: jal         0x80070EF8
    // 0x8006EDDC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    mempool_alloc_fixed(rdram, ctx);
        goto after_3;
    // 0x8006EDDC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_3:
    // 0x8006EDE0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006EDE4: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8006EDE8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006EDEC: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8006EDF0: jal         0x80070EF8
    // 0x8006EDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_4;
    // 0x8006EDF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006EDF8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006EDFC: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8006EE00: beq         $s0, $zero, L_8006EE10
    if (ctx->r16 == 0) {
        // 0x8006EE04: nop
    
            goto L_8006EE10;
    }
    // 0x8006EE04: nop

    // 0x8006EE08: bne         $v0, $zero, L_8006EE54
    if (ctx->r2 != 0) {
        // 0x8006EE0C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8006EE54;
    }
    // 0x8006EE0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8006EE10:
    // 0x8006EE10: beq         $s0, $zero, L_8006EE24
    if (ctx->r16 == 0) {
        // 0x8006EE14: nop
    
            goto L_8006EE24;
    }
    // 0x8006EE14: nop

    // 0x8006EE18: jal         0x80071140
    // 0x8006EE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006EE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006EE20: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8006EE24:
    // 0x8006EE24: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006EE28: nop

    // 0x8006EE2C: beq         $a1, $zero, L_8006EE40
    if (ctx->r5 == 0) {
        // 0x8006EE30: nop
    
            goto L_8006EE40;
    }
    // 0x8006EE30: nop

    // 0x8006EE34: jal         0x80071140
    // 0x8006EE38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006EE38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x8006EE3C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_8006EE40:
    // 0x8006EE40: jal         0x8006EFDC
    // 0x8006EE44: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_7;
    // 0x8006EE44: nop

    after_7:
    // 0x8006EE48: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8006EE4C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8006EE50: nop

L_8006EE54:
    // 0x8006EE54: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8006EE58: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8006EE5C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8006EE60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EE64: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8006EE68: addu        $t4, $v1, $s0
    ctx->r12 = ADD32(ctx->r3, ctx->r16);
    // 0x8006EE6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006EE70: sw          $t4, 0x1200($at)
    MEM_W(0X1200, ctx->r1) = ctx->r12;
    // 0x8006EE74: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006EE78: addiu       $t2, $t2, 0x1200
    ctx->r10 = ADD32(ctx->r10, 0X1200);
    // 0x8006EE7C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8006EE80: sll         $a3, $a2, 6
    ctx->r7 = S32(ctx->r6 << 6);
    // 0x8006EE84: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8006EE88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EE8C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006EE90: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006EE94: sw          $t8, 0x1220($at)
    MEM_W(0X1220, ctx->r1) = ctx->r24;
    // 0x8006EE98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8006EE9C: addiu       $t3, $t3, 0x1220
    ctx->r11 = ADD32(ctx->r11, 0X1220);
    // 0x8006EEA0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8006EEA4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006EEA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEAC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8006EEB0: sw          $t4, 0x1210($at)
    MEM_W(0X1210, ctx->r1) = ctx->r12;
    // 0x8006EEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEB8: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x8006EEBC: sw          $t6, 0x1204($at)
    MEM_W(0X1204, ctx->r1) = ctx->r14;
    // 0x8006EEC0: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8006EEC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEC8: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8006EECC: sw          $t8, 0x1224($at)
    MEM_W(0X1224, ctx->r1) = ctx->r24;
    // 0x8006EED0: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8006EED4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EED8: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x8006EEDC: sw          $t5, 0x1214($at)
    MEM_W(0X1214, ctx->r1) = ctx->r13;
    // 0x8006EEE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEE4: sw          $v0, 0x3528($at)
    MEM_W(0X3528, ctx->r1) = ctx->r2;
    // 0x8006EEE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEEC: sw          $a2, 0x352C($at)
    MEM_W(0X352C, ctx->r1) = ctx->r6;
    // 0x8006EEF0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006EEF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EEF8: sw          $t0, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r8;
    // 0x8006EEFC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8006EF00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EF04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006EF08: jal         0x800710B0
    // 0x8006EF0C: sw          $t6, 0x3534($at)
    MEM_W(0X3534, ctx->r1) = ctx->r14;
    mempool_free_timer(rdram, ctx);
        goto after_8;
    // 0x8006EF0C: sw          $t6, 0x3534($at)
    MEM_W(0X3534, ctx->r1) = ctx->r14;
    after_8:
L_8006EF10:
    // 0x8006EF10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006EF14: lw          $v1, 0x34E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X34E8);
    // 0x8006EF18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006EF1C: addiu       $s1, $s1, 0x11F0
    ctx->r17 = ADD32(ctx->r17, 0X11F0);
    // 0x8006EF20: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8006EF24: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8006EF28: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8006EF2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006EF30: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006EF34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006EF38: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8006EF3C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006EF40: lw          $t5, 0x1200($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1200);
    // 0x8006EF44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006EF48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EF4C: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8006EF50: lw          $t4, 0x1220($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1220);
    // 0x8006EF54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006EF58: sw          $t5, 0x1208($at)
    MEM_W(0X1208, ctx->r1) = ctx->r13;
    // 0x8006EF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EF60: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006EF64: lw          $t6, 0x1210($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1210);
    // 0x8006EF68: sw          $t4, 0x1228($at)
    MEM_W(0X1228, ctx->r1) = ctx->r12;
    // 0x8006EF6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EF70: sw          $t6, 0x1218($at)
    MEM_W(0X1218, ctx->r1) = ctx->r14;
    // 0x8006EF74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006EF78: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x8006EF7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006EF80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8006EF84: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006EF88: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006EF8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006EF90: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006EF94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006EF98: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8006EF9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006EFA0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006EFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EFA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006EFAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006EFB0: jr          $ra
    // 0x8006EFB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006EFB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alCSPSetChlPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C78E4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C78E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C78EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C78F0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C78F4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C78F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C78FC: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7900: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800C7904: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7908: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C790C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7910: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7914: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7918: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C791C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7920: jal         0x800C91AC
    // 0x800C7924: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7924: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C792C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7930: jr          $ra
    // 0x800C7934: nop

    return;
    // 0x800C7934: nop

;}
RECOMP_FUNC void func_80080BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080BC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80080BCC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80080BD0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80080BD4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80080BD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80080BDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80080BE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80080BE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80080BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080BEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80080BF0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80080BF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080BF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80080BFC: addiu       $t8, $t8, 0x1C70
    ctx->r24 = ADD32(ctx->r24, 0X1C70);
    // 0x80080C00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80080C04: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80080C08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080C0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80080C10: lw          $t1, 0x1DB8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1DB8);
    // 0x80080C14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80080C18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80080C1C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80080C20: blez        $t1, L_80080E1C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80080C24: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80080E1C;
    }
    // 0x80080C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80080C28: lui         $s6, 0xE
    ctx->r22 = S32(0XE << 16);
    // 0x80080C2C: lui         $s1, 0xE
    ctx->r17 = S32(0XE << 16);
    // 0x80080C30: lui         $ra, 0x702
    ctx->r31 = S32(0X702 << 16);
    // 0x80080C34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80080C38: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80080C3C: addiu       $t2, $t2, 0x1DB4
    ctx->r10 = ADD32(ctx->r10, 0X1DB4);
    // 0x80080C40: addiu       $t3, $t3, 0x6C2C
    ctx->r11 = ADD32(ctx->r11, 0X6C2C);
    // 0x80080C44: ori         $ra, $ra, 0x10
    ctx->r31 = ctx->r31 | 0X10;
    // 0x80080C48: addiu       $s1, $s1, 0x1CB0
    ctx->r17 = ADD32(ctx->r17, 0X1CB0);
    // 0x80080C4C: addiu       $s6, $s6, 0x1CA0
    ctx->r22 = ADD32(ctx->r22, 0X1CA0);
    // 0x80080C50: lui         $s5, 0x500
    ctx->r21 = S32(0X500 << 16);
    // 0x80080C54: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
    // 0x80080C58: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x80080C5C: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x80080C60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80080C64: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
L_80080C68:
    // 0x80080C68: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80080C6C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80080C70: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x80080C74: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80080C78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080C7C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80080C80: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80080C84: nop

    // 0x80080C88: bne         $t6, $zero, L_80080E0C
    if (ctx->r14 != 0) {
        // 0x80080C8C: nop
    
            goto L_80080E0C;
    }
    // 0x80080C8C: nop

    // 0x80080C90: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80080C94: nop

    // 0x80080C98: beq         $v1, $zero, L_80080D10
    if (ctx->r3 == 0) {
        // 0x80080C9C: nop
    
            goto L_80080D10;
    }
    // 0x80080C9C: nop

    // 0x80080CA0: beq         $t0, $s0, L_80080CC0
    if (ctx->r8 == ctx->r16) {
        // 0x80080CA4: nop
    
            goto L_80080CC0;
    }
    // 0x80080CA4: nop

    // 0x80080CA8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080CAC: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80080CB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080CB4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80080CB8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80080CBC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80080CC0:
    // 0x80080CC0: beq         $t5, $v1, L_80080D30
    if (ctx->r13 == ctx->r3) {
        // 0x80080CC4: nop
    
            goto L_80080D30;
    }
    // 0x80080CC4: nop

    // 0x80080CC8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080CCC: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x80080CD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080CD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80080CD8: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x80080CDC: nop

    // 0x80080CE0: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80080CE4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80080CE8: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80080CEC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80080CF0: or          $t8, $t6, $s2
    ctx->r24 = ctx->r14 | ctx->r18;
    // 0x80080CF4: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80080CF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080CFC: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80080D00: nop

    // 0x80080D04: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80080D08: b           L_80080D30
    // 0x80080D0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80080D30;
    // 0x80080D0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80080D10:
    // 0x80080D10: beq         $t0, $zero, L_80080D30
    if (ctx->r8 == 0) {
        // 0x80080D14: nop
    
            goto L_80080D30;
    }
    // 0x80080D14: nop

    // 0x80080D18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080D1C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80080D20: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80080D24: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80080D28: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80080D2C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_80080D30:
    // 0x80080D30: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080D34: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x80080D38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080D3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80080D40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080D44: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80080D48: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080D4C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80080D50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080D54: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80080D58: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80080D5C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x80080D60: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80080D64: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80080D68: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080D6C: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80080D70: nop

    // 0x80080D74: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80080D78: andi        $t8, $t6, 0x6
    ctx->r24 = ctx->r14 & 0X6;
    // 0x80080D7C: ori         $t9, $t8, 0x98
    ctx->r25 = ctx->r24 | 0X98;
    // 0x80080D80: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x80080D84: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80080D88: or          $t8, $t6, $s4
    ctx->r24 = ctx->r14 | ctx->r20;
    // 0x80080D8C: ori         $t9, $t8, 0x170
    ctx->r25 = ctx->r24 | 0X170;
    // 0x80080D90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080D94: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80080D98: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80080D9C: sll         $t6, $a3, 5
    ctx->r14 = S32(ctx->r7 << 5);
    // 0x80080DA0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080DA4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80080DA8: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80080DAC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80080DB0: ori         $t6, $t0, 0x90
    ctx->r14 = ctx->r8 | 0X90;
    // 0x80080DB4: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80080DB8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80080DBC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80080DC0: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80080DC4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080DC8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80080DCC: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80080DD0: or          $t7, $t8, $s5
    ctx->r15 = ctx->r24 | ctx->r21;
    // 0x80080DD4: ori         $t6, $t7, 0xA0
    ctx->r14 = ctx->r15 | 0XA0;
    // 0x80080DD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080DDC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80080DE0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80080DE4: sll         $t8, $a3, 5
    ctx->r24 = S32(ctx->r7 << 5);
    // 0x80080DE8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80080DEC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80080DF0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80080DF4: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80080DF8: nop

    // 0x80080DFC: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80080E00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80080E04: lw          $t1, 0x1DB8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1DB8);
    // 0x80080E08: nop

L_80080E0C:
    // 0x80080E0C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80080E10: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80080E14: bne         $at, $zero, L_80080C68
    if (ctx->r1 != 0) {
        // 0x80080E18: nop
    
            goto L_80080C68;
    }
    // 0x80080E18: nop

L_80080E1C:
    // 0x80080E1C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80080E20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080E24: addiu       $t2, $t2, 0x1DB4
    ctx->r10 = ADD32(ctx->r10, 0X1DB4);
    // 0x80080E28: sw          $zero, 0x1DB8($at)
    MEM_W(0X1DB8, ctx->r1) = 0;
    // 0x80080E2C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80080E30: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80080E34: subu        $t8, $s0, $t9
    ctx->r24 = SUB32(ctx->r16, ctx->r25);
    // 0x80080E38: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80080E3C: jal         0x8007B3D0
    // 0x80080E40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80080E40: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80080E44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80080E48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080E4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80080E50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80080E54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80080E58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80080E5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80080E60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80080E64: jr          $ra
    // 0x80080E68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80080E68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_init_attachpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F99C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F9A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F9A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F9A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F9AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F9B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F9B8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000F9BC: lw          $s3, 0x60($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X60);
    // 0x8000F9C0: lb          $v0, 0x56($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X56);
    // 0x8000F9C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F9C8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000F9D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000F9D4: blez        $v0, L_8000FA20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F9D8: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_8000FA20;
    }
    // 0x8000F9D8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8000F9DC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000F9E0:
    // 0x8000F9E0: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8000F9E4: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8000F9E8: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8000F9EC: nop

    // 0x8000F9F0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000F9F4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000F9F8: jal         0x8000FD54
    // 0x8000F9FC: nop

    obj_spawn_attachment(rdram, ctx);
        goto after_0;
    // 0x8000F9FC: nop

    after_0:
    // 0x8000FA00: bne         $v0, $zero, L_8000FA0C
    if (ctx->r2 != 0) {
        // 0x8000FA04: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_8000FA0C;
    }
    // 0x8000FA04: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8000FA08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8000FA0C:
    // 0x8000FA0C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA10: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA14: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA18: bne         $at, $zero, L_8000F9E0
    if (ctx->r1 != 0) {
        // 0x8000FA1C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000F9E0;
    }
    // 0x8000FA1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA20:
    // 0x8000FA20: beq         $s4, $zero, L_8000FA90
    if (ctx->r20 == 0) {
        // 0x8000FA24: nop
    
            goto L_8000FA90;
    }
    // 0x8000FA24: nop

    // 0x8000FA28: blez        $v0, L_8000FA88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000FA2C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000FA88;
    }
    // 0x8000FA2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000FA30: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_8000FA34:
    // 0x8000FA34: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x8000FA38: nop

    // 0x8000FA3C: beq         $s0, $zero, L_8000FA78
    if (ctx->r16 == 0) {
        // 0x8000FA40: nop
    
            goto L_8000FA78;
    }
    // 0x8000FA40: nop

    // 0x8000FA44: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000FA4C: lb          $a1, 0x55($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X55);
    // 0x8000FA50: lb          $a2, 0x53($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X53);
    // 0x8000FA54: jal         0x8000F648
    // 0x8000FA58: nop

    objFreeAssets(rdram, ctx);
        goto after_1;
    // 0x8000FA58: nop

    after_1:
    // 0x8000FA5C: lh          $a0, 0x2C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2C);
    // 0x8000FA60: jal         0x8000C844
    // 0x8000FA64: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FA64: nop

    after_2:
    // 0x8000FA68: jal         0x80071140
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8000FA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000FA70: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8000FA74: nop

L_8000FA78:
    // 0x8000FA78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000FA7C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000FA80: bne         $at, $zero, L_8000FA34
    if (ctx->r1 != 0) {
        // 0x8000FA84: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000FA34;
    }
    // 0x8000FA84: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000FA88:
    // 0x8000FA88: b           L_8000FAA4
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000FAA4;
    // 0x8000FA8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000FA90:
    // 0x8000FA90: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8000FA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FA98: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8000FA9C: nop

    // 0x8000FAA0: sw          $t4, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r12;
L_8000FAA4:
    // 0x8000FAA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FAA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FAAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FAB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FAB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FAB8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FABC: jr          $ra
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000FAC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
