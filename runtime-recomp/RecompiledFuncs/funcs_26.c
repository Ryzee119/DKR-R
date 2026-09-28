#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void postrace_viewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094D28: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80094D2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80094D30: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80094D34: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80094D38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80094D3C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80094D40: jal         0x8006EA90
    // 0x80094D44: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80094D44: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094D48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80094D4C: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x80094D50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094D54: bne         $t6, $at, L_80094D70
    if (ctx->r14 != ctx->r1) {
        // 0x80094D58: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094D70;
    }
    // 0x80094D58: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80094D5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094D60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094D64: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80094D68: jal         0x80067F2C
    // 0x80094D6C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x80094D6C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_1:
L_80094D70:
    // 0x80094D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094D74: jal         0x80066894
    // 0x80094D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x80094D78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80094D7C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80094D80: lw          $s3, 0x63BC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X63BC);
    // 0x80094D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80094D88: sll         $t7, $s3, 3
    ctx->r15 = S32(ctx->r19 << 3);
    // 0x80094D8C: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80094D90: bne         $at, $zero, L_80094DA0
    if (ctx->r1 != 0) {
        // 0x80094D94: or          $s3, $t7, $zero
        ctx->r19 = ctx->r15 | 0;
            goto L_80094DA0;
    }
    // 0x80094D94: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x80094D98: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x80094D9C: subu        $s3, $t8, $s3
    ctx->r19 = SUB32(ctx->r24, ctx->r19);
L_80094DA0:
    // 0x80094DA0: lw          $t9, 0x63E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63E0);
    // 0x80094DA4: nop

    // 0x80094DA8: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80094DAC: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80094DB0: beq         $at, $zero, L_80095588
    if (ctx->r1 == 0) {
        // 0x80094DB4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80095588;
    }
    // 0x80094DB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80094DB8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80094DBC: addu        $at, $at, $t2
    gpr jr_addend_80094DC8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80094DC0: lw          $t2, -0x7AF8($at)
    ctx->r10 = ADD32(ctx->r1, -0X7AF8);
    // 0x80094DC4: nop

    // 0x80094DC8: jr          $t2
    // 0x80094DCC: nop

    switch (jr_addend_80094DC8 >> 2) {
        case 0: goto L_80094DD0; break;
        case 1: goto L_80094FB0; break;
        case 2: goto L_80095084; break;
        case 3: goto L_80095588; break;
        case 4: goto L_80095110; break;
        case 5: goto L_800951CC; break;
        default: switch_error(__func__, 0x80094DC8, 0x800E8508);
    }
    // 0x80094DCC: nop

L_80094DD0:
    // 0x80094DD0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80094DD4: lw          $s0, 0x6A94($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6A94);
    // 0x80094DD8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80094DDC: slti        $at, $s0, 0x3D
    ctx->r1 = SIGNED(ctx->r16) < 0X3D ? 1 : 0;
    // 0x80094DE0: bne         $at, $zero, L_80094DEC
    if (ctx->r1 != 0) {
        // 0x80094DE4: addiu       $s1, $s1, 0x6478
        ctx->r17 = ADD32(ctx->r17, 0X6478);
            goto L_80094DEC;
    }
    // 0x80094DE4: addiu       $s1, $s1, 0x6478
    ctx->r17 = ADD32(ctx->r17, 0X6478);
    // 0x80094DE8: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
L_80094DEC:
    // 0x80094DEC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80094DF0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80094DF4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80094DF8: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x80094DFC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80094E00: bne         $t1, $zero, L_80094E0C
    if (ctx->r9 != 0) {
        // 0x80094E04: nop
    
            goto L_80094E0C;
    }
    // 0x80094E04: nop

    // 0x80094E08: break       7
    do_break(2148093448);
L_80094E0C:
    // 0x80094E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094E10: bne         $t1, $at, L_80094E24
    if (ctx->r9 != ctx->r1) {
        // 0x80094E14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094E24;
    }
    // 0x80094E14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E18: bne         $t3, $at, L_80094E24
    if (ctx->r11 != ctx->r1) {
        // 0x80094E1C: nop
    
            goto L_80094E24;
    }
    // 0x80094E1C: nop

    // 0x80094E20: break       6
    do_break(2148093472);
L_80094E24:
    // 0x80094E24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80094E28: lw          $t7, 0x6480($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6480);
    // 0x80094E2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094E30: mflo        $t4
    ctx->r12 = lo;
    // 0x80094E34: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80094E38: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80094E3C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094E40: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80094E44: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80094E48: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x80094E4C: mflo        $t6
    ctx->r14 = lo;
    // 0x80094E50: nop

    // 0x80094E54: nop

    // 0x80094E58: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80094E5C: bne         $v1, $zero, L_80094E68
    if (ctx->r3 != 0) {
        // 0x80094E60: nop
    
            goto L_80094E68;
    }
    // 0x80094E60: nop

    // 0x80094E64: break       7
    do_break(2148093540);
L_80094E68:
    // 0x80094E68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094E6C: bne         $v1, $at, L_80094E80
    if (ctx->r3 != ctx->r1) {
        // 0x80094E70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094E80;
    }
    // 0x80094E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094E74: bne         $t6, $at, L_80094E80
    if (ctx->r14 != ctx->r1) {
        // 0x80094E78: nop
    
            goto L_80094E80;
    }
    // 0x80094E78: nop

    // 0x80094E7C: break       6
    do_break(2148093564);
L_80094E80:
    // 0x80094E80: mflo        $s2
    ctx->r18 = lo;
    // 0x80094E84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80094E88: nop

    // 0x80094E8C: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x80094E90: bne         $t1, $zero, L_80094E9C
    if (ctx->r9 != 0) {
        // 0x80094E94: nop
    
            goto L_80094E9C;
    }
    // 0x80094E94: nop

    // 0x80094E98: break       7
    do_break(2148093592);
L_80094E9C:
    // 0x80094E9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094EA0: bne         $t1, $at, L_80094EB4
    if (ctx->r9 != ctx->r1) {
        // 0x80094EA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094EB4;
    }
    // 0x80094EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094EA8: bne         $v0, $at, L_80094EB4
    if (ctx->r2 != ctx->r1) {
        // 0x80094EAC: nop
    
            goto L_80094EB4;
    }
    // 0x80094EAC: nop

    // 0x80094EB0: break       6
    do_break(2148093616);
L_80094EB4:
    // 0x80094EB4: mflo        $t8
    ctx->r24 = lo;
    // 0x80094EB8: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80094EBC: nop

    // 0x80094EC0: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094EC4: mflo        $t2
    ctx->r10 = lo;
    // 0x80094EC8: nop

    // 0x80094ECC: nop

    // 0x80094ED0: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x80094ED4: bne         $v1, $zero, L_80094EE0
    if (ctx->r3 != 0) {
        // 0x80094ED8: nop
    
            goto L_80094EE0;
    }
    // 0x80094ED8: nop

    // 0x80094EDC: break       7
    do_break(2148093660);
L_80094EE0:
    // 0x80094EE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094EE4: bne         $v1, $at, L_80094EF8
    if (ctx->r3 != ctx->r1) {
        // 0x80094EE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094EF8;
    }
    // 0x80094EE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094EEC: bne         $t2, $at, L_80094EF8
    if (ctx->r10 != ctx->r1) {
        // 0x80094EF0: nop
    
            goto L_80094EF8;
    }
    // 0x80094EF0: nop

    // 0x80094EF4: break       6
    do_break(2148093684);
L_80094EF8:
    // 0x80094EF8: mflo        $t3
    ctx->r11 = lo;
    // 0x80094EFC: subu        $t0, $t7, $t3
    ctx->r8 = SUB32(ctx->r15, ctx->r11);
    // 0x80094F00: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80094F04: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x80094F08: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80094F0C: bne         $v1, $zero, L_80094F18
    if (ctx->r3 != 0) {
        // 0x80094F10: nop
    
            goto L_80094F18;
    }
    // 0x80094F10: nop

    // 0x80094F14: break       7
    do_break(2148093716);
L_80094F18:
    // 0x80094F18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094F1C: bne         $v1, $at, L_80094F30
    if (ctx->r3 != ctx->r1) {
        // 0x80094F20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80094F30;
    }
    // 0x80094F20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80094F24: bne         $t4, $at, L_80094F30
    if (ctx->r12 != ctx->r1) {
        // 0x80094F28: nop
    
            goto L_80094F30;
    }
    // 0x80094F28: nop

    // 0x80094F2C: break       6
    do_break(2148093740);
L_80094F30:
    // 0x80094F30: mflo        $a1
    ctx->r5 = lo;
    // 0x80094F34: subu        $a3, $t5, $a1
    ctx->r7 = SUB32(ctx->r13, ctx->r5);
    // 0x80094F38: jal         0x80066940
    // 0x80094F3C: nop

    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80094F3C: nop

    after_3:
    // 0x80094F40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094F44: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80094F48: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80094F4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80094F50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80094F54: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80094F58: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80094F5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80094F60: swc1        $f4, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = ctx->f4.u32l;
    // 0x80094F64: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80094F68: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80094F6C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80094F70: addu        $t2, $s2, $t9
    ctx->r10 = ADD32(ctx->r18, ctx->r25);
    // 0x80094F74: sra         $t7, $t2, 1
    ctx->r15 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80094F78: subu        $t3, $t8, $t7
    ctx->r11 = SUB32(ctx->r24, ctx->r15);
    // 0x80094F7C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80094F80: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80094F84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80094F88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80094F8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80094F90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094F94: swc1        $f8, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->f8.u32l;
    // 0x80094F98: lwc1        $f10, -0xA68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XA68);
    // 0x80094F9C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80094FA0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80094FA4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80094FA8: b           L_80095588
    // 0x80094FAC: swc1        $f16, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f16.u32l;
        goto L_80095588;
    // 0x80094FAC: swc1        $f16, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f16.u32l;
L_80094FB0:
    // 0x80094FB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094FB4: addiu       $v0, $v0, 0xBEC
    ctx->r2 = ADD32(ctx->r2, 0XBEC);
    // 0x80094FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094FBC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80094FC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094FC4: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80094FC8: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80094FCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80094FD0:
    // 0x80094FD0: lb          $t6, 0x117($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X117);
    // 0x80094FD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80094FD8: beq         $t6, $zero, L_80095014
    if (ctx->r14 == 0) {
        // 0x80094FDC: nop
    
            goto L_80095014;
    }
    // 0x80094FDC: nop

    // 0x80094FE0: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x80094FE4: sllv        $t8, $t2, $a1
    ctx->r24 = S32(ctx->r10 << (ctx->r5 & 31));
    // 0x80094FE8: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x80094FEC: beq         $t7, $zero, L_80095014
    if (ctx->r15 == 0) {
        // 0x80094FF0: nop
    
            goto L_80095014;
    }
    // 0x80094FF0: nop

    // 0x80094FF4: multu       $s3, $v1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094FF8: subu        $t6, $t0, $s3
    ctx->r14 = SUB32(ctx->r8, ctx->r19);
    // 0x80094FFC: sb          $t6, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r14;
    // 0x80095000: mflo        $t3
    ctx->r11 = lo;
    // 0x80095004: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x80095008: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x8009500C: b           L_8009501C
    // 0x80095010: sb          $t5, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r13;
        goto L_8009501C;
    // 0x80095010: sb          $t5, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r13;
L_80095014:
    // 0x80095014: sb          $a2, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r6;
    // 0x80095018: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
L_8009501C:
    // 0x8009501C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80095020: bne         $a1, $v1, L_80094FD0
    if (ctx->r5 != ctx->r3) {
        // 0x80095024: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80094FD0;
    }
    // 0x80095024: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80095028: lb          $t2, 0x117($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X117);
    // 0x8009502C: nop

    // 0x80095030: beq         $t2, $zero, L_80095068
    if (ctx->r10 == 0) {
        // 0x80095034: nop
    
            goto L_80095068;
    }
    // 0x80095034: nop

    // 0x80095038: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x8009503C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095040: andi        $t8, $t9, 0x80
    ctx->r24 = ctx->r25 & 0X80;
    // 0x80095044: beq         $t8, $zero, L_80095068
    if (ctx->r24 == 0) {
        // 0x80095048: addiu       $v0, $v0, 0xBEC
        ctx->r2 = ADD32(ctx->r2, 0XBEC);
            goto L_80095068;
    }
    // 0x80095048: addiu       $v0, $v0, 0xBEC
    ctx->r2 = ADD32(ctx->r2, 0XBEC);
    // 0x8009504C: sra         $t7, $s3, 1
    ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
    // 0x80095050: addiu       $t3, $t7, 0x80
    ctx->r11 = ADD32(ctx->r15, 0X80);
    // 0x80095054: subu        $v1, $t0, $s3
    ctx->r3 = SUB32(ctx->r8, ctx->r19);
    // 0x80095058: sb          $t3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r11;
    // 0x8009505C: sb          $v1, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r3;
    // 0x80095060: b           L_80095588
    // 0x80095064: sb          $v1, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r3;
        goto L_80095588;
    // 0x80095064: sb          $v1, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r3;
L_80095068:
    // 0x80095068: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009506C: addiu       $v0, $v0, 0xBEC
    ctx->r2 = ADD32(ctx->r2, 0XBEC);
    // 0x80095070: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80095074: sb          $t4, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r12;
    // 0x80095078: sb          $a3, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r7;
    // 0x8009507C: b           L_80095588
    // 0x80095080: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
        goto L_80095588;
    // 0x80095080: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
L_80095084:
    // 0x80095084: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80095088: addiu       $a2, $a2, 0xDCC
    ctx->r6 = ADD32(ctx->r6, 0XDCC);
    // 0x8009508C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095090: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80095094:
    // 0x80095094: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80095098: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8009509C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x800950A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800950A4: jal         0x8009EC80
    // 0x800950A8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x800950A8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_4:
    // 0x800950AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800950B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800950B4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800950B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800950BC: beq         $v0, $zero, L_800950DC
    if (ctx->r2 == 0) {
        // 0x800950C0: nop
    
            goto L_800950DC;
    }
    // 0x800950C0: nop

    // 0x800950C4: lb          $t5, 0x72($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X72);
    // 0x800950C8: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800950CC: bne         $a0, $t5, L_800950DC
    if (ctx->r4 != ctx->r13) {
        // 0x800950D0: nop
    
            goto L_800950DC;
    }
    // 0x800950D0: nop

    // 0x800950D4: sra         $v1, $s3, 1
    ctx->r3 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800950D8: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
L_800950DC:
    // 0x800950DC: lb          $t6, 0x5A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X5A);
    // 0x800950E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800950E4: bne         $a0, $t6, L_800950F4
    if (ctx->r4 != ctx->r14) {
        // 0x800950E8: nop
    
            goto L_800950F4;
    }
    // 0x800950E8: nop

    // 0x800950EC: sra         $v1, $s3, 1
    ctx->r3 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800950F0: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
L_800950F4:
    // 0x800950F4: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800950F8: sb          $v1, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r3;
    // 0x800950FC: sb          $v1, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r3;
    // 0x80095100: bne         $a1, $s1, L_80095094
    if (ctx->r5 != ctx->r17) {
        // 0x80095104: sb          $v1, 0x2E($a2)
        MEM_B(0X2E, ctx->r6) = ctx->r3;
            goto L_80095094;
    }
    // 0x80095104: sb          $v1, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r3;
    // 0x80095108: b           L_80095588
    // 0x8009510C: nop

        goto L_80095588;
    // 0x8009510C: nop

L_80095110:
    // 0x80095110: lb          $t2, 0x117($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X117);
    // 0x80095114: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095118: beq         $t2, $zero, L_8009516C
    if (ctx->r10 == 0) {
        // 0x8009511C: addiu       $v0, $v0, 0xE4C
        ctx->r2 = ADD32(ctx->r2, 0XE4C);
            goto L_8009516C;
    }
    // 0x8009511C: addiu       $v0, $v0, 0xE4C
    ctx->r2 = ADD32(ctx->r2, 0XE4C);
    // 0x80095120: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x80095124: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80095128: andi        $t8, $t9, 0x7F
    ctx->r24 = ctx->r25 & 0X7F;
    // 0x8009512C: beq         $t8, $zero, L_80095170
    if (ctx->r24 == 0) {
        // 0x80095130: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_80095170;
    }
    // 0x80095130: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095134: multu       $s3, $v1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095138: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009513C: addiu       $v0, $v0, 0xE4C
    ctx->r2 = ADD32(ctx->r2, 0XE4C);
    // 0x80095140: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80095144: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80095148: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009514C: subu        $t5, $t0, $s3
    ctx->r13 = SUB32(ctx->r8, ctx->r19);
    // 0x80095150: sb          $a3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r7;
    // 0x80095154: sb          $t5, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r13;
    // 0x80095158: mflo        $t7
    ctx->r15 = lo;
    // 0x8009515C: sra         $t3, $t7, 2
    ctx->r11 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80095160: subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // 0x80095164: b           L_80095184
    // 0x80095168: sb          $t4, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r12;
        goto L_80095184;
    // 0x80095168: sb          $t4, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r12;
L_8009516C:
    // 0x8009516C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80095170:
    // 0x80095170: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80095174: sb          $a3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r7;
    // 0x80095178: sb          $a2, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r6;
    // 0x8009517C: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
    // 0x80095180: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_80095184:
    // 0x80095184: lb          $t6, 0x117($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X117);
    // 0x80095188: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8009518C: beq         $t6, $zero, L_800951BC
    if (ctx->r14 == 0) {
        // 0x80095190: nop
    
            goto L_800951BC;
    }
    // 0x80095190: nop

    // 0x80095194: lb          $t2, 0x58($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X58);
    // 0x80095198: sra         $t8, $s3, 1
    ctx->r24 = S32(SIGNED(ctx->r19) >> 1);
    // 0x8009519C: andi        $t9, $t2, 0x80
    ctx->r25 = ctx->r10 & 0X80;
    // 0x800951A0: beq         $t9, $zero, L_800951BC
    if (ctx->r25 == 0) {
        // 0x800951A4: addiu       $t7, $t8, 0x80
        ctx->r15 = ADD32(ctx->r24, 0X80);
            goto L_800951BC;
    }
    // 0x800951A4: addiu       $t7, $t8, 0x80
    ctx->r15 = ADD32(ctx->r24, 0X80);
    // 0x800951A8: subu        $v1, $t0, $s3
    ctx->r3 = SUB32(ctx->r8, ctx->r19);
    // 0x800951AC: sb          $t7, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r15;
    // 0x800951B0: sb          $v1, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r3;
    // 0x800951B4: b           L_80095588
    // 0x800951B8: sb          $v1, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r3;
        goto L_80095588;
    // 0x800951B8: sb          $v1, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r3;
L_800951BC:
    // 0x800951BC: sb          $t3, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r11;
    // 0x800951C0: sb          $a3, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r7;
    // 0x800951C4: b           L_80095588
    // 0x800951C8: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
        goto L_80095588;
    // 0x800951C8: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
L_800951CC:
    // 0x800951CC: jal         0x800C56D0
    // 0x800951D0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_5;
    // 0x800951D0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x800951D4: jal         0x800C5494
    // 0x800951D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_6;
    // 0x800951D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_6:
    // 0x800951DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800951E0: jal         0x800C4F7C
    // 0x800951E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x800951E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800951E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800951EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800951F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800951F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800951F8: jal         0x800C5050
    // 0x800951FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_8;
    // 0x800951FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80095200: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80095204: addiu       $s1, $s1, 0x6A98
    ctx->r17 = ADD32(ctx->r17, 0X6A98);
    // 0x80095208: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009520C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095210: beq         $t4, $zero, L_80095220
    if (ctx->r12 == 0) {
        // 0x80095214: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80095220;
    }
    // 0x80095214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095218: b           L_8009524C
    // 0x8009521C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8009524C;
    // 0x8009521C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80095220:
    // 0x80095220: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095224: lw          $t5, 0x6C1C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C1C);
    // 0x80095228: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009522C: beq         $t5, $zero, L_80095244
    if (ctx->r13 == 0) {
        // 0x80095230: nop
    
            goto L_80095244;
    }
    // 0x80095230: nop

    // 0x80095234: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80095238: lw          $s0, 0x6C24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6C24);
    // 0x8009523C: b           L_80095250
    // 0x80095240: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
        goto L_80095250;
    // 0x80095240: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_80095244:
    // 0x80095244: lw          $s0, 0x6C14($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6C14);
    // 0x80095248: nop

L_8009524C:
    // 0x8009524C: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_80095250:
    // 0x80095250: bne         $at, $zero, L_80095268
    if (ctx->r1 != 0) {
        // 0x80095254: addiu       $a3, $zero, 0x140
        ctx->r7 = ADD32(0, 0X140);
            goto L_80095268;
    }
    // 0x80095254: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x80095258: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8009525C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80095260: b           L_80095274
    // 0x80095264: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
        goto L_80095274;
    // 0x80095264: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
L_80095268:
    // 0x80095268: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8009526C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80095270: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
L_80095274:
    // 0x80095274: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80095278: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009527C: multu       $s0, $t9
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095280: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80095284: addiu       $s0, $zero, 0xC0
    ctx->r16 = ADD32(0, 0XC0);
    // 0x80095288: mflo        $s2
    ctx->r18 = lo;
    // 0x8009528C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80095290: sra         $t8, $s2, 1
    ctx->r24 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80095294: bne         $t7, $zero, L_800952A0
    if (ctx->r15 != 0) {
        // 0x80095298: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_800952A0;
    }
    // 0x80095298: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8009529C: addiu       $s0, $zero, 0xDA
    ctx->r16 = ADD32(0, 0XDA);
L_800952A0:
    // 0x800952A0: addu        $t4, $s0, $s2
    ctx->r12 = ADD32(ctx->r16, ctx->r18);
    // 0x800952A4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800952A8: subu        $t3, $s0, $s2
    ctx->r11 = SUB32(ctx->r16, ctx->r18);
    // 0x800952AC: subu        $a2, $t3, $v0
    ctx->r6 = SUB32(ctx->r11, ctx->r2);
    // 0x800952B0: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800952B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800952B8: jal         0x800C4EDC
    // 0x800952BC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_9;
    // 0x800952BC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    after_9:
    // 0x800952C0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800952C4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800952C8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800952CC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800952D0: jal         0x800C4FBC
    // 0x800952D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_10;
    // 0x800952D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x800952D8: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800952DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800952E0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800952E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800952E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800952EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800952F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800952F4: jal         0x800C5000
    // 0x800952F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_11;
    // 0x800952F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_11:
    // 0x800952FC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80095300: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095304: beq         $t8, $zero, L_80095340
    if (ctx->r24 == 0) {
        // 0x80095308: addiu       $v0, $v0, 0x6C1C
        ctx->r2 = ADD32(ctx->r2, 0X6C1C);
            goto L_80095340;
    }
    // 0x80095308: addiu       $v0, $v0, 0x6C1C
    ctx->r2 = ADD32(ctx->r2, 0X6C1C);
    // 0x8009530C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095310: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x80095314: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095318: lw          $a3, 0x1F0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1F0);
    // 0x8009531C: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80095320: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095324: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80095328: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009532C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095330: jal         0x800C5168
    // 0x80095334: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_12;
    // 0x80095334: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_12:
    // 0x80095338: b           L_80095580
    // 0x8009533C: nop

        goto L_80095580;
    // 0x8009533C: nop

L_80095340:
    // 0x80095340: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80095344: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80095348: beq         $t5, $zero, L_800953CC
    if (ctx->r13 == 0) {
        // 0x8009534C: addiu       $s1, $s1, 0x988
        ctx->r17 = ADD32(ctx->r17, 0X988);
            goto L_800953CC;
    }
    // 0x8009534C: addiu       $s1, $s1, 0x988
    ctx->r17 = ADD32(ctx->r17, 0X988);
    // 0x80095350: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80095354: lw          $t6, 0x6C24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C24);
    // 0x80095358: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x8009535C: blez        $t6, L_80095580
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80095360: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80095580;
    }
    // 0x80095360: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80095364: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80095368: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009536C:
    // 0x8009536C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095370: addiu       $v0, $v0, 0x6C1C
    ctx->r2 = ADD32(ctx->r2, 0X6C1C);
    // 0x80095374: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80095378: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009537C: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x80095380: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x80095384: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80095388: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009538C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80095390: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80095394: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095398: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009539C: jal         0x800C5168
    // 0x800953A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_13;
    // 0x800953A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x800953A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800953A8: lw          $t3, 0x6C24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6C24);
    // 0x800953AC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800953B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800953B4: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800953B8: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x800953BC: bne         $at, $zero, L_8009536C
    if (ctx->r1 != 0) {
        // 0x800953C0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8009536C;
    }
    // 0x800953C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800953C4: b           L_80095580
    // 0x800953C8: nop

        goto L_80095580;
    // 0x800953C8: nop

L_800953CC:
    // 0x800953CC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800953D0: addiu       $s2, $s2, -0x18
    ctx->r18 = ADD32(ctx->r18, -0X18);
    // 0x800953D4: beq         $t4, $zero, L_800954D0
    if (ctx->r12 == 0) {
        // 0x800953D8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800954D0;
    }
    // 0x800953D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800953DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800953E0: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x800953E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800953E8: lw          $a3, 0x210($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X210);
    // 0x800953EC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800953F0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800953F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800953F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800953FC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095400: jal         0x800C5168
    // 0x80095404: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80095404: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    after_14:
    // 0x80095408: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009540C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095410: bne         $t9, $at, L_8009541C
    if (ctx->r25 != ctx->r1) {
        // 0x80095414: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009541C;
    }
    // 0x80095414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80095418: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_8009541C:
    // 0x8009541C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095420: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80095424: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80095428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009542C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095430: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80095434: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095438: jal         0x800C5000
    // 0x8009543C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_15;
    // 0x8009543C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_15:
    // 0x80095440: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095444: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x80095448: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009544C: lw          $a3, 0x218($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X218);
    // 0x80095450: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80095454: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095458: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009545C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095460: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095464: jal         0x800C5168
    // 0x80095468: addiu       $a2, $s2, 0x1A
    ctx->r6 = ADD32(ctx->r18, 0X1A);
    render_dialogue_text(rdram, ctx);
        goto after_16;
    // 0x80095468: addiu       $a2, $s2, 0x1A
    ctx->r6 = ADD32(ctx->r18, 0X1A);
    after_16:
    // 0x8009546C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80095470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80095474: bne         $t5, $at, L_80095480
    if (ctx->r13 != ctx->r1) {
        // 0x80095478: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80095480;
    }
    // 0x80095478: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009547C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_80095480:
    // 0x80095480: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80095484: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80095488: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009548C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095490: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095494: jal         0x800C5000
    // 0x80095498: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    set_current_text_colour(rdram, ctx);
        goto after_17;
    // 0x80095498: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_17:
    // 0x8009549C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800954A0: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x800954A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800954A8: lw          $a3, 0x154($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X154);
    // 0x800954AC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800954B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800954B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800954B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800954BC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800954C0: jal         0x800C5168
    // 0x800954C4: addiu       $a2, $s2, 0x2A
    ctx->r6 = ADD32(ctx->r18, 0X2A);
    render_dialogue_text(rdram, ctx);
        goto after_18;
    // 0x800954C4: addiu       $a2, $s2, 0x2A
    ctx->r6 = ADD32(ctx->r18, 0X2A);
    after_18:
    // 0x800954C8: b           L_80095580
    // 0x800954CC: nop

        goto L_80095580;
    // 0x800954CC: nop

L_800954D0:
    // 0x800954D0: lw          $t7, 0x6C14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C14);
    // 0x800954D4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x800954D8: blez        $t7, L_80095580
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800954DC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80095580;
    }
    // 0x800954DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800954E0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800954E4: addiu       $s1, $s1, 0x6BF0
    ctx->r17 = ADD32(ctx->r17, 0X6BF0);
L_800954E8:
    // 0x800954E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800954EC: lw          $t3, 0x6A68($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A68);
    // 0x800954F0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800954F4: bne         $s0, $t3, L_80095524
    if (ctx->r16 != ctx->r11) {
        // 0x800954F8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80095524;
    }
    // 0x800954F8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800954FC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80095500: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095504: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095508: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009550C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095510: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095514: jal         0x800C5000
    // 0x80095518: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    set_current_text_colour(rdram, ctx);
        goto after_19;
    // 0x80095518: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_19:
    // 0x8009551C: b           L_80095540
    // 0x80095520: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
        goto L_80095540;
    // 0x80095520: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
L_80095524:
    // 0x80095524: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80095528: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009552C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095530: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095534: jal         0x800C5000
    // 0x80095538: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_20;
    // 0x80095538: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x8009553C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
L_80095540:
    // 0x80095540: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095544: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80095548: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009554C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80095550: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095554: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80095558: jal         0x800C5168
    // 0x8009555C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_21;
    // 0x8009555C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_21:
    // 0x80095560: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80095564: lw          $t8, 0x6C14($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C14);
    // 0x80095568: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8009556C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095570: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80095574: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80095578: bne         $at, $zero, L_800954E8
    if (ctx->r1 != 0) {
        // 0x8009557C: addu        $s2, $s2, $t9
        ctx->r18 = ADD32(ctx->r18, ctx->r25);
            goto L_800954E8;
    }
    // 0x8009557C: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
L_80095580:
    // 0x80095580: jal         0x800C55F4
    // 0x80095584: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_22;
    // 0x80095584: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
L_80095588:
    // 0x80095588: jal         0x8006DA0C
    // 0x8009558C: nop

    get_game_mode(rdram, ctx);
        goto after_23;
    // 0x8009558C: nop

    after_23:
    // 0x80095590: bne         $v0, $zero, L_80095608
    if (ctx->r2 != 0) {
        // 0x80095594: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80095608;
    }
    // 0x80095594: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095598: lw          $t7, -0xB44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB44);
    // 0x8009559C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800955A0: bne         $t7, $at, L_80095608
    if (ctx->r15 != ctx->r1) {
        // 0x800955A4: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_80095608;
    }
    // 0x800955A4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800955A8: lw          $t3, 0xFE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XFE8);
    // 0x800955AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800955B0: bne         $t3, $zero, L_8009560C
    if (ctx->r11 != 0) {
        // 0x800955B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8009560C;
    }
    // 0x800955B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800955B8: jal         0x80066818
    // 0x800955BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_24;
    // 0x800955BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x800955C0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800955C4: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800955C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800955CC: bne         $t4, $zero, L_800955E0
    if (ctx->r12 != 0) {
        // 0x800955D0: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800955E0;
    }
    // 0x800955D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800955D4: lwc1        $f18, -0x7AE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7AE0);
    // 0x800955D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800955DC: swc1        $f18, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f18.u32l;
L_800955E0:
    // 0x800955E0: lw          $t5, 0x63E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63E0);
    // 0x800955E4: nop

    // 0x800955E8: blez        $t5, L_800955FC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800955EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800955FC;
    }
    // 0x800955EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    extern void dkr_postrace_wooden_frame_draw(uint8_t*, recomp_context*); dkr_postrace_wooden_frame_draw(rdram, ctx);
    // 0x800955F0: jal         0x8009CA60
    // 0x800955F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    menu_element_render(rdram, ctx);
        goto after_25;
    // 0x800955F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x800955F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800955FC:
    // 0x800955FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095604: swc1        $f6, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f6.u32l;
L_80095608:
    // 0x80095608: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8009560C:
    // 0x8009560C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80095610: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80095614: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80095618: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8009561C: jr          $ra
    // 0x80095620: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80095620: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_tex_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011134: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80011138: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001113C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80011140: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80011144: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80011148: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001114C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80011150: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011154: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011158: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001115C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011160: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80011164: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80011168: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001116C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80011170: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80011174: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80011178: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8001117C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011180: lh          $s5, 0x50($s3)
    ctx->r21 = MEM_H(ctx->r19, 0X50);
    // 0x80011184: lw          $s4, 0x38($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X38);
    // 0x80011188: blez        $s5, L_80011238
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001118C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80011238;
    }
    // 0x8001118C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80011190: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80011194: sll         $s2, $zero, 2
    ctx->r18 = S32(0 << 2);
    // 0x80011198: blez        $t0, L_80011234
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001119C: subu        $s2, $s2, $zero
        ctx->r18 = SUB32(ctx->r18, 0);
            goto L_80011234;
    }
    // 0x8001119C: subu        $s2, $s2, $zero
    ctx->r18 = SUB32(ctx->r18, 0);
    // 0x800111A0: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x800111A4: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x800111A8: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x800111AC: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
L_800111B0:
    // 0x800111B0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800111B4: nop

    // 0x800111B8: and         $t2, $t1, $s7
    ctx->r10 = ctx->r9 & ctx->r23;
    // 0x800111BC: beq         $t2, $zero, L_80011210
    if (ctx->r10 == 0) {
        // 0x800111C0: nop
    
            goto L_80011210;
    }
    // 0x800111C0: nop

    // 0x800111C4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800111C8: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
    // 0x800111CC: beq         $fp, $v0, L_80011210
    if (ctx->r30 == ctx->r2) {
        // 0x800111D0: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80011210;
    }
    // 0x800111D0: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800111D4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800111D8: lbu         $t7, 0x7($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7);
    // 0x800111DC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800111E0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800111E4: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800111E8: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800111EC: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800111F0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800111F4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800111F8: jal         0x8007EF80
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80011200: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80011204: nop

    // 0x80011208: sra         $t1, $t9, 6
    ctx->r9 = S32(SIGNED(ctx->r25) >> 6);
    // 0x8001120C: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_80011210:
    // 0x80011210: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011214: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80011218: blez        $s5, L_80011234
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001121C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80011234;
    }
    // 0x8001121C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80011220: lh          $t2, 0x28($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X28);
    // 0x80011224: nop

    // 0x80011228: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001122C: bne         $at, $zero, L_800111B0
    if (ctx->r1 != 0) {
        // 0x80011230: nop
    
            goto L_800111B0;
    }
    // 0x80011230: nop

L_80011234:
    // 0x80011234: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80011238:
    // 0x80011238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001123C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011240: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011244: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011248: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001124C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011250: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011254: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80011258: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001125C: jr          $ra
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C913C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C9140: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C9144: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9148: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C914C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C9150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9154: jal         0x800C9A30
    // 0x800C9158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C915C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C9160: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C9164: beq         $s0, $zero, L_800C918C
    if (ctx->r16 == 0) {
        // 0x800C9168: nop
    
            goto L_800C918C;
    }
    // 0x800C9168: nop

L_800C916C:
    // 0x800C916C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C9170: jal         0x800C8760
    // 0x800C9174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C917C: jal         0x800C8790
    // 0x800C9180: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C9180: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800C9184: bne         $s1, $zero, L_800C916C
    if (ctx->r17 != 0) {
        // 0x800C9188: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C916C;
    }
    // 0x800C9188: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C918C:
    // 0x800C918C: jal         0x800C9A30
    // 0x800C9190: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C9190: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C9194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C919C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C91A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C91A4: jr          $ra
    // 0x800C91A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C91A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void hud_magnet_reticle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A7A64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7A68: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800A7A6C: nop

    // 0x800A7A70: lw          $t6, 0x140($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X140);
    // 0x800A7A74: nop

    // 0x800A7A78: beq         $t6, $zero, L_800A7B5C
    if (ctx->r14 == 0) {
        // 0x800A7A7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A7B5C;
    }
    // 0x800A7A7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7A80: jal         0x80066220
    // 0x800A7A84: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A7A84: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A7A88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A7A8C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7A90: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A7A94: nop

    // 0x800A7A98: bne         $v0, $t7, L_800A7B5C
    if (ctx->r2 != ctx->r15) {
        // 0x800A7A9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A7B5C;
    }
    // 0x800A7A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7AA0: lw          $t8, 0x140($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X140);
    // 0x800A7AA4: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A7AA8: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800A7AAC: lh          $a2, 0x226($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X226);
    // 0x800A7AB0: swc1        $f4, 0x22C($a3)
    MEM_W(0X22C, ctx->r7) = ctx->f4.u32l;
    // 0x800A7AB4: lw          $t9, 0x140($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X140);
    // 0x800A7AB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A7ABC: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800A7AC0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800A7AC4: swc1        $f6, 0x230($a3)
    MEM_W(0X230, ctx->r7) = ctx->f6.u32l;
    // 0x800A7AC8: lw          $t0, 0x140($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X140);
    // 0x800A7ACC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7AD0: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800A7AD4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7AD8: swc1        $f8, 0x234($a3)
    MEM_W(0X234, ctx->r7) = ctx->f8.u32l;
    // 0x800A7ADC: lw          $t1, 0x6CF4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6CF4);
    // 0x800A7AE0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7AE4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A7AE8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800A7AEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7AF0: beq         $v0, $zero, L_800A7B58
    if (ctx->r2 == 0) {
        // 0x800A7AF4: addiu       $a3, $a3, 0x220
        ctx->r7 = ADD32(ctx->r7, 0X220);
            goto L_800A7B58;
    }
    // 0x800A7AF4: addiu       $a3, $a3, 0x220
    ctx->r7 = ADD32(ctx->r7, 0X220);
    // 0x800A7AF8: lw          $t4, 0x6CD8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CD8);
    // 0x800A7AFC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7B00: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800A7B04: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800A7B08: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800A7B0C: jal         0x80066CDC
    // 0x800A7B10: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    viewport_main(rdram, ctx);
        goto after_1;
    // 0x800A7B10: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A7B14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7B18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7B1C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7B20: jal         0x80068408
    // 0x800A7B24: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    mtx_world_origin(rdram, ctx);
        goto after_2;
    // 0x800A7B24: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_2:
    // 0x800A7B28: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800A7B2C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800A7B30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7B34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7B38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7B3C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800A7B40: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A7B44: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7B48: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7B4C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7B50: jal         0x80068514
    // 0x800A7B54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800A7B54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_800A7B58:
    // 0x800A7B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A7B5C:
    // 0x800A7B5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A7B60: jr          $ra
    // 0x800A7B64: nop

    return;
    // 0x800A7B64: nop

;}
RECOMP_FUNC void init_point_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF024: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800AF028: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    // 0x800AF02C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800AF030: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AF034: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF038: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800AF03C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800AF040: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AF044: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800AF048: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF04C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800AF050:
    // 0x800AF050: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF054: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
    // 0x800AF058: sb          $a0, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r4;
    // 0x800AF05C: sb          $a0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r4;
    // 0x800AF060: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x800AF064: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x800AF068: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x800AF06C: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x800AF070: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x800AF074: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x800AF078: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x800AF07C: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x800AF080: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x800AF084: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AF088: sb          $a0, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r4;
    // 0x800AF08C: sb          $a0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r4;
    // 0x800AF090: sb          $a0, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r4;
    // 0x800AF094: bne         $v1, $a2, L_800AF050
    if (ctx->r3 != ctx->r6) {
        // 0x800AF098: sb          $a0, -0x1F($v0)
        MEM_B(-0X1F, ctx->r2) = ctx->r4;
            goto L_800AF050;
    }
    // 0x800AF098: sb          $a0, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r4;
    // 0x800AF09C: jr          $ra
    // 0x800AF0A0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF0A0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void init_rectangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEEB8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800AEEBC: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AEEC0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AEEC4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEEC8: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AEECC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AEED0: addiu       $v1, $v1, 0x2E74
    ctx->r3 = ADD32(ctx->r3, 0X2E74);
    // 0x800AEED4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AEED8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AEEDC:
    // 0x800AEEDC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AEEE0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AEEE4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AEEE8: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AEEEC: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800AEEF0: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800AEEF4: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800AEEF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AEEFC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AEF00: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AEF04: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AEF08: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AEF0C: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AEF10: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AEF14: bne         $at, $zero, L_800AEEDC
    if (ctx->r1 != 0) {
        // 0x800AEF18: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AEEDC;
    }
    // 0x800AEF18: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AEF1C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AEF20: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800AEF24: sh          $t4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r12;
    // 0x800AEF28: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AEF2C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800AEF30: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x800AEF34: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AEF38: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800AEF3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AEF40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AEF44: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x800AEF48: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x800AEF4C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800AEF50: sb          $t1, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r9;
    // 0x800AEF54: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x800AEF58: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AEF5C: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x800AEF60: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x800AEF64: sb          $a3, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r7;
    // 0x800AEF68: sb          $t0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r8;
    // 0x800AEF6C: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800AEF70: sb          $t6, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r14;
    // 0x800AEF74: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    // 0x800AEF78: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x800AEF7C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800AEF80: jr          $ra
    // 0x800AEF84: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AEF84: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void hud_main_battle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1C04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A1C08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A1C0C: lbu         $t7, 0x6D37($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6D37);
    // 0x800A1C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1C14: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A1C18: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A1C1C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800A1C20: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A1C24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A1C28: bne         $t7, $at, L_800A1C40
    if (ctx->r15 != ctx->r1) {
        // 0x800A1C2C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A1C40;
    }
    // 0x800A1C2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A1C30: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A1C34: nop

    // 0x800A1C38: bne         $t8, $zero, L_800A1E3C
    if (ctx->r24 != 0) {
        // 0x800A1C3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1E3C;
    }
    // 0x800A1C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1C40:
    // 0x800A1C40: jal         0x80068508
    // 0x800A1C44: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1C44: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A1C48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A1C4C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A1C50: jal         0x800A3CE4
    // 0x800A1C54: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A1C54: nop

    after_1:
    // 0x800A1C58: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A1C5C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A1C60: jal         0x800A7520
    // 0x800A1C64: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A1C64: nop

    after_2:
    // 0x800A1C68: jal         0x8001BA74
    // 0x800A1C6C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x800A1C6C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800A1C70: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1C74: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A1C78: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800A1C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A1C80: beq         $v1, $at, L_800A1C98
    if (ctx->r3 == ctx->r1) {
        // 0x800A1C84: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800A1C98;
    }
    // 0x800A1C84: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A1C88: beq         $v1, $t2, L_800A1CB4
    if (ctx->r3 == ctx->r10) {
        // 0x800A1C8C: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_800A1CB4;
    }
    // 0x800A1C8C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800A1C90: b           L_800A1E28
    // 0x800A1C94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_800A1E28;
    // 0x800A1C94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A1C98:
    // 0x800A1C98: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A1C9C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A1CA0: jal         0x800A1E48
    // 0x800A1CA4: nop

    hud_battle_portraits(rdram, ctx);
        goto after_4;
    // 0x800A1CA4: nop

    after_4:
    // 0x800A1CA8: b           L_800A1E30
    // 0x800A1CAC: nop

        goto L_800A1E30;
    // 0x800A1CAC: nop

    // 0x800A1CB0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800A1CB4:
    // 0x800A1CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A1CB8: blez        $t9, L_800A1E14
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A1CBC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800A1E14;
    }
    // 0x800A1CBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1CC0: andi        $v1, $t9, 0x3
    ctx->r3 = ctx->r25 & 0X3;
    // 0x800A1CC4: beq         $v1, $zero, L_800A1D24
    if (ctx->r3 == 0) {
        // 0x800A1CC8: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A1D24;
    }
    // 0x800A1CC8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A1CCC: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800A1CD0: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A1CD4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1CD8:
    // 0x800A1CD8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A1CDC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A1CE0: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A1CE4: nop

    // 0x800A1CE8: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A1CEC: nop

    // 0x800A1CF0: beq         $t0, $t5, L_800A1D0C
    if (ctx->r8 == ctx->r13) {
        // 0x800A1CF4: nop
    
            goto L_800A1D0C;
    }
    // 0x800A1CF4: nop

    // 0x800A1CF8: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1CFC: nop

    // 0x800A1D00: beq         $t6, $zero, L_800A1D0C
    if (ctx->r14 == 0) {
        // 0x800A1D04: nop
    
            goto L_800A1D0C;
    }
    // 0x800A1D04: nop

    // 0x800A1D08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A1D0C:
    // 0x800A1D0C: bne         $t1, $a2, L_800A1CD8
    if (ctx->r9 != ctx->r6) {
        // 0x800A1D10: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A1CD8;
    }
    // 0x800A1D10: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A1D14: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A1D18: nop

    // 0x800A1D1C: beq         $a2, $t7, L_800A1E14
    if (ctx->r6 == ctx->r15) {
        // 0x800A1D20: nop
    
            goto L_800A1E14;
    }
    // 0x800A1D20: nop

L_800A1D24:
    // 0x800A1D24: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A1D28: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800A1D2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A1D30: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A1D34: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A1D38: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1D3C:
    // 0x800A1D3C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A1D40: nop

    // 0x800A1D44: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A1D48: nop

    // 0x800A1D4C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A1D50: nop

    // 0x800A1D54: beq         $t0, $t5, L_800A1D70
    if (ctx->r8 == ctx->r13) {
        // 0x800A1D58: nop
    
            goto L_800A1D70;
    }
    // 0x800A1D58: nop

    // 0x800A1D5C: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A1D60: nop

    // 0x800A1D64: beq         $t6, $zero, L_800A1D70
    if (ctx->r14 == 0) {
        // 0x800A1D68: nop
    
            goto L_800A1D70;
    }
    // 0x800A1D68: nop

    // 0x800A1D6C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A1D70:
    // 0x800A1D70: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A1D74: nop

    // 0x800A1D78: lw          $a3, 0x64($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X64);
    // 0x800A1D7C: nop

    // 0x800A1D80: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800A1D84: nop

    // 0x800A1D88: beq         $t0, $t8, L_800A1DA4
    if (ctx->r8 == ctx->r24) {
        // 0x800A1D8C: nop
    
            goto L_800A1DA4;
    }
    // 0x800A1D8C: nop

    // 0x800A1D90: lb          $t9, 0x1D8($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A1D94: nop

    // 0x800A1D98: beq         $t9, $zero, L_800A1DA4
    if (ctx->r25 == 0) {
        // 0x800A1D9C: nop
    
            goto L_800A1DA4;
    }
    // 0x800A1D9C: nop

    // 0x800A1DA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A1DA4:
    // 0x800A1DA4: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800A1DA8: nop

    // 0x800A1DAC: lw          $a3, 0x64($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X64);
    // 0x800A1DB0: nop

    // 0x800A1DB4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A1DB8: nop

    // 0x800A1DBC: beq         $t0, $t4, L_800A1DD8
    if (ctx->r8 == ctx->r12) {
        // 0x800A1DC0: nop
    
            goto L_800A1DD8;
    }
    // 0x800A1DC0: nop

    // 0x800A1DC4: lb          $t5, 0x1D8($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A1DC8: nop

    // 0x800A1DCC: beq         $t5, $zero, L_800A1DD8
    if (ctx->r13 == 0) {
        // 0x800A1DD0: nop
    
            goto L_800A1DD8;
    }
    // 0x800A1DD0: nop

    // 0x800A1DD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A1DD8:
    // 0x800A1DD8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800A1DDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A1DE0: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A1DE4: nop

    // 0x800A1DE8: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A1DEC: nop

    // 0x800A1DF0: beq         $t0, $t7, L_800A1E0C
    if (ctx->r8 == ctx->r15) {
        // 0x800A1DF4: nop
    
            goto L_800A1E0C;
    }
    // 0x800A1DF4: nop

    // 0x800A1DF8: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A1DFC: nop

    // 0x800A1E00: beq         $t8, $zero, L_800A1E0C
    if (ctx->r24 == 0) {
        // 0x800A1E04: nop
    
            goto L_800A1E0C;
    }
    // 0x800A1E04: nop

    // 0x800A1E08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A1E0C:
    // 0x800A1E0C: bne         $a0, $t1, L_800A1D3C
    if (ctx->r4 != ctx->r9) {
        // 0x800A1E10: nop
    
            goto L_800A1D3C;
    }
    // 0x800A1E10: nop

L_800A1E14:
    // 0x800A1E14: bne         $a1, $t2, L_800A1E30
    if (ctx->r5 != ctx->r10) {
        // 0x800A1E18: nop
    
            goto L_800A1E30;
    }
    // 0x800A1E18: nop

    // 0x800A1E1C: b           L_800A1E3C
    // 0x800A1E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A1E3C;
    // 0x800A1E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1E24: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A1E28:
    // 0x800A1E28: jal         0x800A4154
    // 0x800A1E2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A1E2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
L_800A1E30:
    // 0x800A1E30: jal         0x80068508
    // 0x800A1E34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_6;
    // 0x800A1E34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800A1E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1E3C:
    // 0x800A1E3C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A1E40: jr          $ra
    // 0x800A1E44: nop

    return;
    // 0x800A1E44: nop

;}
RECOMP_FUNC void rand_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_netplay_presentation_random_range(uint8_t*, recomp_context*); if (dkr_netplay_presentation_random_range(rdram, ctx)) { return; }
    // 0x8006F94C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F950: lw          $t0, -0x2BCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BCC);
    // 0x8006F954: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F958: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8006F95C: dsll32      $t1, $t0, 31
    ctx->r9 = ctx->r8 << (31 + 32);
    // 0x8006F960: dsll        $t2, $t0, 31
    ctx->r10 = ctx->r8 << 31;
    // 0x8006F964: dsrl        $t1, $t1, 31
    ctx->r9 = ctx->r9 >> 31;
    // 0x8006F968: dsrl32      $t2, $t2, 0
    ctx->r10 = ctx->r10 >> (0 + 32);
    // 0x8006F96C: dsll32      $t3, $t0, 12
    ctx->r11 = ctx->r8 << (12 + 32);
    // 0x8006F970: or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // 0x8006F974: dsrl32      $t3, $t3, 0
    ctx->r11 = ctx->r11 >> (0 + 32);
    // 0x8006F978: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
    // 0x8006F97C: dsrl        $t3, $t1, 20
    ctx->r11 = ctx->r9 >> 20;
    // 0x8006F980: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x8006F984: xor         $t0, $t3, $t1
    ctx->r8 = ctx->r11 ^ ctx->r9;
    // 0x8006F988: sw          $t0, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->r8;
    // 0x8006F98C: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006F990: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8006F994: divu        $zero, $t0, $a1
    lo = S32(U32(ctx->r8) / U32(ctx->r5)); hi = S32(U32(ctx->r8) % U32(ctx->r5));
    // 0x8006F998: mflo        $t0
    ctx->r8 = lo;
    // 0x8006F99C: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006F9A0: add         $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006F9A4: bne         $a1, $zero, L_8006F9B0
    if (ctx->r5 != 0) {
        // 0x8006F9A8: nop
    
            goto L_8006F9B0;
    }
    // 0x8006F9A8: nop

    // 0x8006F9AC: break       7
    do_break(2147940780);
L_8006F9B0:
    // 0x8006F9B0: jr          $ra
    // 0x8006F9B4: nop

    return;
    // 0x8006F9B4: nop

;}
RECOMP_FUNC void is_player_two_in_control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E184: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E188: lb          $v0, -0x38B8($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X38B8);
    // 0x8000E18C: jr          $ra
    // 0x8000E190: nop

    return;
    // 0x8000E190: nop

;}
RECOMP_FUNC void obj_init_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003ACC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003ACC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003ACC8: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003ACCC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003ACD0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003ACD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003ACD8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003ACDC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003ACE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003ACE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003ACE8: nop

    // 0x8003ACEC: bc1f        L_8003ACFC
    if (!c1cs) {
        // 0x8003ACF0: nop
    
            goto L_8003ACFC;
    }
    // 0x8003ACF0: nop

    // 0x8003ACF4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003ACF8: nop

L_8003ACFC:
    // 0x8003ACFC: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003AD00: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8003AD04: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AD08: nop

    // 0x8003AD0C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003AD10: jal         0x80011390
    // 0x8003AD14: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x8003AD14: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    after_0:
    // 0x8003AD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AD20: jr          $ra
    // 0x8003AD24: nop

    return;
    // 0x8003AD24: nop

;}
RECOMP_FUNC void directional_lighting_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B458: sh          $zero, 0x6384($at)
    MEM_H(0X6384, ctx->r1) = 0;
    // 0x8007B45C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B460: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B464: jr          $ra
    // 0x8007B468: sh          $t6, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r14;
    return;
    // 0x8007B468: sh          $t6, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008435C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084360: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x80084364: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80084368: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008436C: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x80084370: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80084374: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80084378: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008437C: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80084380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084384: beq         $v0, $zero, L_800843AC
    if (ctx->r2 == 0) {
        // 0x80084388: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800843AC;
    }
    // 0x80084388: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008438C: blez        $v0, L_800843A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80084390: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_800843A4;
    }
    // 0x80084390: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x80084394: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80084398: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8008439C: b           L_800843AC
    // 0x800843A0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800843AC;
    // 0x800843A0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800843A4:
    // 0x800843A4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800843A8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800843AC:
    // 0x800843AC: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x800843B0: bne         $at, $zero, L_800843D0
    if (ctx->r1 != 0) {
        // 0x800843B4: slti        $at, $v0, 0x23
        ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
            goto L_800843D0;
    }
    // 0x800843B4: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x800843B8: beq         $at, $zero, L_800843D0
    if (ctx->r1 == 0) {
        // 0x800843BC: nop
    
            goto L_800843D0;
    }
    // 0x800843BC: nop

    // 0x800843C0: jal         0x800841B8
    // 0x800843C4: nop

    optionscreen_render(rdram, ctx);
        goto after_0;
    // 0x800843C4: nop

    after_0:
    // 0x800843C8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800843CC: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_800843D0:
    // 0x800843D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800843D4: lw          $t3, 0x63C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63C4);
    // 0x800843D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800843DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800843E0: bne         $t3, $zero, L_80084468
    if (ctx->r11 != 0) {
        // 0x800843E4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80084468;
    }
    // 0x800843E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800843E8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800843EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800843F0: bne         $t4, $zero, L_80084468
    if (ctx->r12 != 0) {
        // 0x800843F4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80084468;
    }
    // 0x800843F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800843F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800843FC: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x80084400: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
L_80084404:
    // 0x80084404: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80084408: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8008440C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80084410: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80084414: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80084418: jal         0x8006A554
    // 0x8008441C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008441C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80084420: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80084424: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80084428: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008442C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80084430: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80084434: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80084438: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8008443C: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x80084440: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80084444: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80084448: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008444C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80084450: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80084454: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80084458: bne         $a0, $at, L_80084404
    if (ctx->r4 != ctx->r1) {
        // 0x8008445C: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_80084404;
    }
    // 0x8008445C: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80084460: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084464: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084468:
    // 0x80084468: andi        $t7, $a2, 0x4000
    ctx->r15 = ctx->r6 & 0X4000;
    // 0x8008446C: bne         $t7, $zero, L_80084490
    if (ctx->r15 != 0) {
        // 0x80084470: andi        $v1, $a2, 0x9000
        ctx->r3 = ctx->r6 & 0X9000;
            goto L_80084490;
    }
    // 0x80084470: andi        $v1, $a2, 0x9000
    ctx->r3 = ctx->r6 & 0X9000;
    // 0x80084474: beq         $v1, $zero, L_800844D0
    if (ctx->r3 == 0) {
        // 0x80084478: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800844D0;
    }
    // 0x80084478: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008447C: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x80084480: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80084484: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80084488: bne         $t8, $at, L_800844D0
    if (ctx->r24 != ctx->r1) {
        // 0x8008448C: nop
    
            goto L_800844D0;
    }
    // 0x8008448C: nop

L_80084490:
    // 0x80084490: jal         0x80000C98
    // 0x80084494: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x80084494: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_2:
    // 0x80084498: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008449C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800844A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800844A4: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    // 0x800844A8: jal         0x800C01D8
    // 0x800844AC: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x800844AC: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_3:
    // 0x800844B0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800844B4: jal         0x80001D04
    // 0x800844B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800844B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800844BC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800844C0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800844C4: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x800844C8: b           L_80084678
    // 0x800844CC: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
        goto L_80084678;
    // 0x800844CC: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_800844D0:
    // 0x800844D0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800844D4: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x800844D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800844DC: beq         $v1, $zero, L_80084510
    if (ctx->r3 == 0) {
        // 0x800844E0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80084510;
    }
    // 0x800844E0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800844E4: bne         $at, $zero, L_80084510
    if (ctx->r1 != 0) {
        // 0x800844E8: addiu       $t2, $zero, 0x1F
        ctx->r10 = ADD32(0, 0X1F);
            goto L_80084510;
    }
    // 0x800844E8: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x800844EC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800844F0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800844F4: jal         0x80001D04
    // 0x800844F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800844F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800844FC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084500: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084504: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x80084508: b           L_80084678
    // 0x8008450C: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
        goto L_80084678;
    // 0x8008450C: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084510:
    // 0x80084510: bne         $v0, $zero, L_80084574
    if (ctx->r2 != 0) {
        // 0x80084514: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80084574;
    }
    // 0x80084514: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80084518: beq         $a3, $zero, L_80084574
    if (ctx->r7 == 0) {
        // 0x8008451C: nop
    
            goto L_80084574;
    }
    // 0x8008451C: nop

    // 0x80084520: jal         0x8009EB20
    // 0x80084524: nop

    get_language(rdram, ctx);
        goto after_6;
    // 0x80084524: nop

    after_6:
    // 0x80084528: sra         $t4, $v0, 31
    ctx->r12 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8008452C: bne         $t4, $zero, L_8008454C
    if (ctx->r12 != 0) {
        // 0x80084530: nop
    
            goto L_8008454C;
    }
    // 0x80084530: nop

    // 0x80084534: bne         $v0, $zero, L_8008454C
    if (ctx->r2 != 0) {
        // 0x80084538: nop
    
            goto L_8008454C;
    }
    // 0x80084538: nop

    // 0x8008453C: jal         0x8009EB94
    // 0x80084540: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_language(rdram, ctx);
        goto after_7;
    // 0x80084540: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80084544: b           L_80084558
    // 0x80084548: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
        goto L_80084558;
    // 0x80084548: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_8008454C:
    // 0x8008454C: jal         0x8009EB94
    // 0x80084550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_language(rdram, ctx);
        goto after_8;
    // 0x80084550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80084554: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_80084558:
    // 0x80084558: jal         0x80001D04
    // 0x8008455C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008455C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80084560: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084564: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084568: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x8008456C: b           L_80084678
    // 0x80084570: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
        goto L_80084678;
    // 0x80084570: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084574:
    // 0x80084574: bne         $v0, $at, L_80084618
    if (ctx->r2 != ctx->r1) {
        // 0x80084578: nop
    
            goto L_80084618;
    }
    // 0x80084578: nop

    // 0x8008457C: beq         $a3, $zero, L_80084618
    if (ctx->r7 == 0) {
        // 0x80084580: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80084618;
    }
    // 0x80084580: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80084584: lw          $t7, 0x644C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X644C);
    // 0x80084588: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8008458C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80084590: beq         $t9, $zero, L_800845D0
    if (ctx->r25 == 0) {
        // 0x80084594: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800845D0;
    }
    // 0x80084594: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80084598: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008459C: jal         0x80001D04
    // 0x800845A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800845A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800845A4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800845A8: jal         0x8009EABC
    // 0x800845AC: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_11;
    // 0x800845AC: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_11:
    // 0x800845B0: jal         0x800C2AF4
    // 0x800845B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_12;
    // 0x800845B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800845B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800845BC: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x800845C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800845C4: lw          $t2, 0x2DC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2DC);
    // 0x800845C8: b           L_80084604
    // 0x800845CC: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
        goto L_80084604;
    // 0x800845CC: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
L_800845D0:
    // 0x800845D0: jal         0x80001D04
    // 0x800845D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800845D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x800845D8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800845DC: jal         0x8009EA78
    // 0x800845E0: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    set_eeprom_settings_value(rdram, ctx);
        goto after_14;
    // 0x800845E0: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_14:
    // 0x800845E4: jal         0x800C2AF4
    // 0x800845E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_subtitles(rdram, ctx);
        goto after_15;
    // 0x800845E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x800845EC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800845F0: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x800845F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800845F8: lw          $t5, 0x2D8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2D8);
    // 0x800845FC: nop

    // 0x80084600: sw          $t5, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r13;
L_80084604:
    // 0x80084604: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084608: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008460C: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x80084610: b           L_80084678
    // 0x80084614: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
        goto L_80084678;
    // 0x80084614: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084618:
    // 0x80084618: bgez        $t0, L_8008463C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008461C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008463C;
    }
    // 0x8008461C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80084620: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80084624: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80084628: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8008462C: bne         $at, $zero, L_8008463C
    if (ctx->r1 != 0) {
        // 0x80084630: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008463C;
    }
    // 0x80084630: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80084634: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80084638: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8008463C:
    // 0x8008463C: blez        $t0, L_80084658
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80084640: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80084658;
    }
    // 0x80084640: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80084644: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80084648: bgez        $t8, L_80084658
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008464C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80084658;
    }
    // 0x8008464C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80084650: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80084654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084658:
    // 0x80084658: beq         $v1, $v0, L_80084678
    if (ctx->r3 == ctx->r2) {
        // 0x8008465C: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80084678;
    }
    // 0x8008465C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80084660: jal         0x80001D04
    // 0x80084664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x80084664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80084668: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008466C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084670: addiu       $a2, $a2, -0xBA0
    ctx->r6 = ADD32(ctx->r6, -0XBA0);
    // 0x80084674: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084678:
    // 0x80084678: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008467C: nop

    // 0x80084680: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80084684: bne         $at, $zero, L_800846F4
    if (ctx->r1 != 0) {
        // 0x80084688: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800846F4;
    }
    // 0x80084688: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008468C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084690: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084694: bne         $v0, $at, L_800846B8
    if (ctx->r2 != ctx->r1) {
        // 0x80084698: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800846B8;
    }
    // 0x80084698: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008469C: jal         0x80084734
    // 0x800846A0: nop

    optionscreen_free(rdram, ctx);
        goto after_17;
    // 0x800846A0: nop

    after_17:
    // 0x800846A4: jal         0x800813D0
    // 0x800846A8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x800846A8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_18:
    // 0x800846AC: b           L_80084724
    // 0x800846B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084724;
    // 0x800846B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800846B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800846B8:
    // 0x800846B8: bne         $v0, $at, L_800846D8
    if (ctx->r2 != ctx->r1) {
        // 0x800846BC: nop
    
            goto L_800846D8;
    }
    // 0x800846BC: nop

    // 0x800846C0: jal         0x80084734
    // 0x800846C4: nop

    optionscreen_free(rdram, ctx);
        goto after_19;
    // 0x800846C4: nop

    after_19:
    // 0x800846C8: jal         0x800813D0
    // 0x800846CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x800846CC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_20:
    // 0x800846D0: b           L_80084724
    // 0x800846D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084724;
    // 0x800846D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800846D8:
    // 0x800846D8: jal         0x80084734
    // 0x800846DC: nop

    optionscreen_free(rdram, ctx);
        goto after_21;
    // 0x800846DC: nop

    after_21:
    // 0x800846E0: jal         0x800813D0
    // 0x800846E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_22;
    // 0x800846E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_22:
    // 0x800846E8: b           L_80084724
    // 0x800846EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084724;
    // 0x800846EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800846F0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_800846F4:
    // 0x800846F4: beq         $at, $zero, L_8008471C
    if (ctx->r1 == 0) {
        // 0x800846F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008471C;
    }
    // 0x800846F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800846FC: jal         0x80000B28
    // 0x80084700: nop

    music_change_on(rdram, ctx);
        goto after_23;
    // 0x80084700: nop

    after_23:
    // 0x80084704: jal         0x80084734
    // 0x80084708: nop

    optionscreen_free(rdram, ctx);
        goto after_24;
    // 0x80084708: nop

    after_24:
    // 0x8008470C: jal         0x800813D0
    // 0x80084710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_25;
    // 0x80084710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80084714: b           L_80084724
    // 0x80084718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084724;
    // 0x80084718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008471C:
    // 0x8008471C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084720: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_80084724:
    // 0x80084724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008472C: jr          $ra
    // 0x80084730: nop

    return;
    // 0x80084730: nop

;}
RECOMP_FUNC void update_smokey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D820: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D824: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D828: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D82C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D830: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D834: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D838: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D83C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D840: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D844: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D848: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D84C: jal         0x8005CA78
    // 0x8005D850: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D850: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    after_0:
    // 0x8005D854: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D85C: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x8005D860: lh          $t7, 0x16A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16A);
    // 0x8005D864: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005D868: sh          $t7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r15;
    // 0x8005D86C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D870: lwc1        $f7, 0x6A50($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6A50);
    // 0x8005D874: lwc1        $f6, 0x6A54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A54);
    // 0x8005D878: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D87C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005D880: nop

    // 0x8005D884: bc1f        L_8005D8AC
    if (!c1cs) {
        // 0x8005D888: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005D8AC;
    }
    // 0x8005D888: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D88C: lwc1        $f9, 0x6A58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A58);
    // 0x8005D890: lwc1        $f8, 0x6A5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A5C);
    // 0x8005D894: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005D898: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005D89C: nop

    // 0x8005D8A0: bc1f        L_8005D8AC
    if (!c1cs) {
        // 0x8005D8A4: nop
    
            goto L_8005D8AC;
    }
    // 0x8005D8A4: nop

    // 0x8005D8A8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8005D8AC:
    // 0x8005D8AC: lb          $t9, 0x1D8($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D8B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D8B4: bne         $t9, $at, L_8005D8EC
    if (ctx->r25 != ctx->r1) {
        // 0x8005D8B8: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_8005D8EC;
    }
    // 0x8005D8B8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005D8BC: jal         0x80023568
    // 0x8005D8C0: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005D8C0: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x8005D8C4: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D8C8: beq         $v0, $zero, L_8005D8E8
    if (ctx->r2 == 0) {
        // 0x8005D8CC: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005D8E8;
    }
    // 0x8005D8CC: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005D8D0: jal         0x80021400
    // 0x8005D8D4: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005D8D4: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_2:
    // 0x8005D8D8: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D8DC: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D8E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005D8E4: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
L_8005D8E8:
    // 0x8005D8E8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
L_8005D8EC:
    // 0x8005D8EC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005D8F0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005D8F4: nop

    // 0x8005D8F8: bne         $v1, $a0, L_8005D904
    if (ctx->r3 != ctx->r4) {
        // 0x8005D8FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005D904;
    }
    // 0x8005D8FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D900: sb          $zero, -0x2A20($at)
    MEM_B(-0X2A20, ctx->r1) = 0;
L_8005D904:
    // 0x8005D904: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005D908: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005D90C: bne         $t1, $t5, L_8005D994
    if (ctx->r9 != ctx->r13) {
        // 0x8005D910: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_8005D994;
    }
    // 0x8005D910: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8005D914: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005D918: nop

    // 0x8005D91C: beq         $a0, $v0, L_8005D990
    if (ctx->r4 == ctx->r2) {
        // 0x8005D920: addiu       $t6, $v0, -0x3C
        ctx->r14 = ADD32(ctx->r2, -0X3C);
            goto L_8005D990;
    }
    // 0x8005D920: addiu       $t6, $v0, -0x3C
    ctx->r14 = ADD32(ctx->r2, -0X3C);
    // 0x8005D924: bgez        $t6, L_8005D988
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005D928: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_8005D988;
    }
    // 0x8005D928: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005D92C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005D930: lb          $t8, -0x2A1F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2A1F);
    // 0x8005D934: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005D938: bne         $t8, $zero, L_8005D964
    if (ctx->r24 != 0) {
        // 0x8005D93C: lw          $v0, 0x70($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X70);
            goto L_8005D964;
    }
    // 0x8005D93C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8005D940: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005D944: jal         0x8005CB04
    // 0x8005D948: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005D948: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005D94C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005D950: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005D954: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D958: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005D95C: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005D960: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
L_8005D964:
    // 0x8005D964: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005D968: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D96C: sb          $t3, -0x2A1F($at)
    MEM_B(-0X2A1F, ctx->r1) = ctx->r11;
    // 0x8005D970: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005D974: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8005D978: nop

    // 0x8005D97C: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005D980: b           L_8005D990
    // 0x8005D984: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8005D990;
    // 0x8005D984: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8005D988:
    // 0x8005D988: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D98C: sb          $zero, -0x2A1F($at)
    MEM_B(-0X2A1F, ctx->r1) = 0;
L_8005D990:
    // 0x8005D990: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
L_8005D994:
    // 0x8005D994: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005D998: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005D99C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D9A0: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    // 0x8005D9A4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005D9A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005D9AC: jal         0x80049794
    // 0x8005D9B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005D9B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005D9B4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005D9B8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005D9BC: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005D9C0: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D9C4: sb          $t7, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r15;
    // 0x8005D9C8: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8005D9CC: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005D9D0: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005D9D4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005D9D8: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005D9DC: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005D9E0: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005D9E4: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005D9E8: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005D9EC: nop

    // 0x8005D9F0: beq         $t3, $zero, L_8005DA94
    if (ctx->r11 == 0) {
        // 0x8005D9F4: nop
    
            goto L_8005DA94;
    }
    // 0x8005D9F4: nop

    // 0x8005D9F8: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D9FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DA00: beq         $t4, $at, L_8005DA94
    if (ctx->r12 == ctx->r1) {
        // 0x8005DA04: nop
    
            goto L_8005DA94;
    }
    // 0x8005DA04: nop

    // 0x8005DA08: jal         0x8005CB04
    // 0x8005DA0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005DA0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005DA10: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005DA14: jal         0x80001D04
    // 0x8005DA18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005DA18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005DA1C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005DA20: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005DA24: jal         0x80069F28
    // 0x8005DA28: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005DA28: nop

    after_7:
    // 0x8005DA2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DA30: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DA34: lwc1        $f1, 0x6A60($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6A60);
    // 0x8005DA38: lwc1        $f0, 0x6A64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6A64);
    // 0x8005DA3C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005DA40: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8005DA44: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DA48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DA4C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DA50: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005DA54: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8005DA58: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DA5C: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005DA60: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8005DA64: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005DA68: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DA6C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DA70: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8005DA74: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DA78: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005DA7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DA80: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005DA84: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005DA88: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DA8C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DA90: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_8005DA94:
    // 0x8005DA94: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005DA98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DA9C: beq         $t6, $zero, L_8005DB08
    if (ctx->r14 == 0) {
        // 0x8005DAA0: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005DB08;
    }
    // 0x8005DAA0: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005DAA4: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DAA8: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DAAC: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005DAB0: nop

    // 0x8005DAB4: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005DAB8: nop

    // 0x8005DABC: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005DAC0: nop

    // 0x8005DAC4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005DAC8: jal         0x800C9AD0
    // 0x8005DACC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005DACC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_8:
    // 0x8005DAD0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005DAD4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DAD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DADC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005DAE0: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DAE4: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DAE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DAEC: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005DAF0: bc1f        L_8005DB08
    if (!c1cs) {
        // 0x8005DAF4: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005DB08;
    }
    // 0x8005DAF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DAF8: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005DAFC: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x8005DB00: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8005DB04: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_8005DB08:
    // 0x8005DB08: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8005DB0C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DB10: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8005DB14: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8005DB18: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005DB1C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005DB20: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x8005DB24: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DB28: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DB2C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005DB30: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005DB34: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005DB38: addiu       $t6, $t5, -0x11
    ctx->r14 = ADD32(ctx->r13, -0X11);
    // 0x8005DB3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DB40: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005DB44: lwc1        $f19, 0x6A68($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6A68);
    // 0x8005DB48: lwc1        $f18, 0x6A6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6A6C);
    // 0x8005DB4C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DB50: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005DB54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005DB58: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8005DB5C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005DB60: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DB64: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DB68: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8005DB6C: nop

    // 0x8005DB70: bc1f        L_8005DBA0
    if (!c1cs) {
        // 0x8005DB74: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005DBA0;
    }
    // 0x8005DB74: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DB78: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005DB7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005DB80: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DB84: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005DB88: nop

    // 0x8005DB8C: bc1f        L_8005DBC8
    if (!c1cs) {
        // 0x8005DB90: nop
    
            goto L_8005DBC8;
    }
    // 0x8005DB90: nop

    // 0x8005DB94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DB98: b           L_8005DBCC
    // 0x8005DB9C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005DBCC;
    // 0x8005DB9C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DBA0:
    // 0x8005DBA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DBA4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DBA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DBAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DBB0: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8005DBB4: nop

    // 0x8005DBB8: bc1f        L_8005DBC8
    if (!c1cs) {
        // 0x8005DBBC: nop
    
            goto L_8005DBC8;
    }
    // 0x8005DBBC: nop

    // 0x8005DBC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DBC4: nop

L_8005DBC8:
    // 0x8005DBC8: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DBCC:
    // 0x8005DBCC: beq         $at, $zero, L_8005DD0C
    if (ctx->r1 == 0) {
        // 0x8005DBD0: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8005DD0C;
    }
    // 0x8005DBD0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8005DBD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DBD8: addu        $at, $at, $t7
    gpr jr_addend_8005DBE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005DBDC: lw          $t7, 0x6A70($at)
    ctx->r15 = ADD32(ctx->r1, 0X6A70);
    // 0x8005DBE0: nop

    // 0x8005DBE4: jr          $t7
    // 0x8005DBE8: nop

    switch (jr_addend_8005DBE4 >> 2) {
        case 0: goto L_8005DBEC; break;
        case 1: goto L_8005DC10; break;
        case 2: goto L_8005DC48; break;
        case 3: goto L_8005DC64; break;
        case 4: goto L_8005DCBC; break;
        case 5: goto L_8005DCE8; break;
        default: switch_error(__func__, 0x8005DBE4, 0x800E6A70);
    }
    // 0x8005DBE8: nop

L_8005DBEC:
    // 0x8005DBEC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DBF0: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DBF4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005DBF8: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005DBFC: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005DC00: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005DC04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DC08: b           L_8005DD10
    // 0x8005DC0C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005DD10;
    // 0x8005DC0C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005DC10:
    // 0x8005DC10: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DC14: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DC18: bne         $a0, $t8, L_8005DC34
    if (ctx->r4 != ctx->r24) {
        // 0x8005DC1C: nop
    
            goto L_8005DC34;
    }
    // 0x8005DC1C: nop

    // 0x8005DC20: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DC24: nop

    // 0x8005DC28: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8005DC2C: b           L_8005DD10
    // 0x8005DC30: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005DD10;
    // 0x8005DC30: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005DC34:
    // 0x8005DC34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DC38: nop

    // 0x8005DC3C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8005DC40: b           L_8005DD10
    // 0x8005DC44: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005DD10;
    // 0x8005DC44: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005DC48:
    // 0x8005DC48: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DC4C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005DC50: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005DC54: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005DC58: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DC5C: b           L_8005DD10
    // 0x8005DC60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DD10;
    // 0x8005DC60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DC64:
    // 0x8005DC64: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DC68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DC6C: bne         $t3, $at, L_8005DC98
    if (ctx->r11 != ctx->r1) {
        // 0x8005DC70: nop
    
            goto L_8005DC98;
    }
    // 0x8005DC70: nop

    // 0x8005DC74: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DC78: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DC7C: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DC80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DC84: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DC88: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005DC8C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DC90: b           L_8005DD10
    // 0x8005DC94: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DD10;
    // 0x8005DC94: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DC98:
    // 0x8005DC98: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DC9C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DCA0: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DCA4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DCA8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DCAC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DCB0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DCB4: b           L_8005DD10
    // 0x8005DCB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DD10;
    // 0x8005DCB8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DCBC:
    // 0x8005DCBC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DCC0: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DCC4: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DCC8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005DCCC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DCD0: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DCD4: sb          $t4, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r12;
    // 0x8005DCD8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DCDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DCE0: b           L_8005DD10
    // 0x8005DCE4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DD10;
    // 0x8005DCE4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DCE8:
    // 0x8005DCE8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DCEC: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DCF0: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DCF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DCF8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DCFC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DD00: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DD04: b           L_8005DD10
    // 0x8005DD08: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DD10;
    // 0x8005DD08: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DD0C:
    // 0x8005DD0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DD10:
    // 0x8005DD10: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DD14: nop

    // 0x8005DD18: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DD1C: nop

    // 0x8005DD20: bc1f        L_8005DD4C
    if (!c1cs) {
        // 0x8005DD24: nop
    
            goto L_8005DD4C;
    }
    // 0x8005DD24: nop

L_8005DD28:
    // 0x8005DD28: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005DD2C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005DD30: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DD34: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DD38: nop

    // 0x8005DD3C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DD40: nop

    // 0x8005DD44: bc1t        L_8005DD28
    if (c1cs) {
        // 0x8005DD48: nop
    
            goto L_8005DD28;
    }
    // 0x8005DD48: nop

L_8005DD4C:
    // 0x8005DD4C: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DD50: nop

    // 0x8005DD54: bc1f        L_8005DD80
    if (!c1cs) {
        // 0x8005DD58: nop
    
            goto L_8005DD80;
    }
    // 0x8005DD58: nop

L_8005DD5C:
    // 0x8005DD5C: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005DD60: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005DD64: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DD68: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DD6C: nop

    // 0x8005DD70: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DD74: nop

    // 0x8005DD78: bc1t        L_8005DD5C
    if (c1cs) {
        // 0x8005DD7C: nop
    
            goto L_8005DD5C;
    }
    // 0x8005DD7C: nop

L_8005DD80:
    // 0x8005DD80: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DD84: nop

    // 0x8005DD88: bne         $a0, $v1, L_8005DDD0
    if (ctx->r4 != ctx->r3) {
        // 0x8005DD8C: nop
    
            goto L_8005DDD0;
    }
    // 0x8005DD8C: nop

    // 0x8005DD90: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005DD94: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x8005DD98: bne         $t5, $zero, L_8005DDD0
    if (ctx->r13 != 0) {
        // 0x8005DD9C: nop
    
            goto L_8005DDD0;
    }
    // 0x8005DD9C: nop

    // 0x8005DDA0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DDA4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005DDA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005DDAC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DDB0: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DDB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DDB8: bc1f        L_8005DDD0
    if (!c1cs) {
        // 0x8005DDBC: nop
    
            goto L_8005DDD0;
    }
    // 0x8005DDBC: nop

    // 0x8005DDC0: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005DDC4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DDC8: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DDCC: nop

L_8005DDD0:
    // 0x8005DDD0: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005DDD4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DDD8: beq         $t1, $t6, L_8005DDE8
    if (ctx->r9 == ctx->r14) {
        // 0x8005DDDC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005DDE8;
    }
    // 0x8005DDDC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DDE0: bne         $v1, $zero, L_8005DF8C
    if (ctx->r3 != 0) {
        // 0x8005DDE4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005DF8C;
    }
    // 0x8005DDE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8005DDE8:
    // 0x8005DDE8: bne         $v1, $at, L_8005DE10
    if (ctx->r3 != ctx->r1) {
        // 0x8005DDEC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005DE10;
    }
    // 0x8005DDEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DDF0: lbu         $t7, 0x1CD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DDF4: nop

    // 0x8005DDF8: sb          $t7, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r15;
    // 0x8005DDFC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DE00: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DE04: b           L_8005DF90
    // 0x8005DE08: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005DF90;
    // 0x8005DE08: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005DE0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8005DE10:
    // 0x8005DE10: bne         $v1, $at, L_8005DE40
    if (ctx->r3 != ctx->r1) {
        // 0x8005DE14: nop
    
            goto L_8005DE40;
    }
    // 0x8005DE14: nop

    // 0x8005DE18: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DE1C: nop

    // 0x8005DE20: bne         $t8, $zero, L_8005DE30
    if (ctx->r24 != 0) {
        // 0x8005DE24: nop
    
            goto L_8005DE30;
    }
    // 0x8005DE24: nop

    // 0x8005DE28: b           L_8005DE34
    // 0x8005DE2C: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005DE34;
    // 0x8005DE2C: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005DE30:
    // 0x8005DE30: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005DE34:
    // 0x8005DE34: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DE38: b           L_8005DF90
    // 0x8005DE3C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005DF90;
    // 0x8005DE3C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DE40:
    // 0x8005DE40: bne         $a2, $v1, L_8005DE70
    if (ctx->r6 != ctx->r3) {
        // 0x8005DE44: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005DE70;
    }
    // 0x8005DE44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DE48: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DE4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DE50: bne         $t9, $at, L_8005DE60
    if (ctx->r25 != ctx->r1) {
        // 0x8005DE54: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005DE60;
    }
    // 0x8005DE54: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005DE58: b           L_8005DE64
    // 0x8005DE5C: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005DE64;
    // 0x8005DE5C: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005DE60:
    // 0x8005DE60: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
L_8005DE64:
    // 0x8005DE64: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DE68: b           L_8005DF90
    // 0x8005DE6C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005DF90;
    // 0x8005DE6C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DE70:
    // 0x8005DE70: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DE74: lwc1        $f7, 0x6A88($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6A88);
    // 0x8005DE78: lwc1        $f6, 0x6A8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A8C);
    // 0x8005DE7C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE80: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005DE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DE88: bc1f        L_8005DEFC
    if (!c1cs) {
        // 0x8005DE8C: nop
    
            goto L_8005DEFC;
    }
    // 0x8005DE8C: nop

    // 0x8005DE90: lwc1        $f9, 0x6A90($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A90);
    // 0x8005DE94: lwc1        $f8, 0x6A94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A94);
    // 0x8005DE98: nop

    // 0x8005DE9C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005DEA0: nop

    // 0x8005DEA4: bc1f        L_8005DEFC
    if (!c1cs) {
        // 0x8005DEA8: nop
    
            goto L_8005DEFC;
    }
    // 0x8005DEA8: nop

    // 0x8005DEAC: bne         $a0, $v1, L_8005DEEC
    if (ctx->r4 != ctx->r3) {
        // 0x8005DEB0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005DEEC;
    }
    // 0x8005DEB0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005DEB4: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005DEB8: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DEBC: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005DEC0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005DEC4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005DEC8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005DECC: nop

    // 0x8005DED0: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8005DED4: addiu       $t4, $t3, -0x11
    ctx->r12 = ADD32(ctx->r11, -0X11);
    // 0x8005DED8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8005DEDC: nop

    // 0x8005DEE0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005DEE4: b           L_8005DEF0
    // 0x8005DEE8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEF0;
    // 0x8005DEE8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DEEC:
    // 0x8005DEEC: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005DEF0:
    // 0x8005DEF0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DEF4: b           L_8005DF90
    // 0x8005DEF8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005DF90;
    // 0x8005DEF8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DEFC:
    // 0x8005DEFC: bne         $v1, $zero, L_8005DF18
    if (ctx->r3 != 0) {
        // 0x8005DF00: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005DF18;
    }
    // 0x8005DF00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DF04: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005DF08: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005DF0C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DF10: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF14: nop

L_8005DF18:
    // 0x8005DF18: bne         $v1, $at, L_8005DF8C
    if (ctx->r3 != ctx->r1) {
        // 0x8005DF1C: nop
    
            goto L_8005DF8C;
    }
    // 0x8005DF1C: nop

    // 0x8005DF20: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005DF24: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x8005DF28: beq         $t5, $zero, L_8005DF8C
    if (ctx->r13 == 0) {
        // 0x8005DF2C: nop
    
            goto L_8005DF8C;
    }
    // 0x8005DF2C: nop

    // 0x8005DF30: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DF34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005DF38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005DF3C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005DF40: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8005DF44: nop

    // 0x8005DF48: bc1f        L_8005DF8C
    if (!c1cs) {
        // 0x8005DF4C: nop
    
            goto L_8005DF8C;
    }
    // 0x8005DF4C: nop

    // 0x8005DF50: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005DF54: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF58: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x8005DF5C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005DF60: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8005DF64: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005DF68: nop

    // 0x8005DF6C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8005DF70: addiu       $t5, $t6, -0x11
    ctx->r13 = ADD32(ctx->r14, -0X11);
    // 0x8005DF74: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005DF78: nop

    // 0x8005DF7C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005DF80: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DF84: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF88: nop

L_8005DF8C:
    // 0x8005DF8C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DF90:
    // 0x8005DF90: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DF94: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8005DF98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005DF9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005DFA0: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005DFA4: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005DFA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DFAC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005DFB0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005DFB4: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005DFB8: beq         $v1, $at, L_8005E018
    if (ctx->r3 == ctx->r1) {
        // 0x8005DFBC: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005E018;
    }
    // 0x8005DFBC: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005DFC0: beq         $a0, $v1, L_8005E018
    if (ctx->r4 == ctx->r3) {
        // 0x8005DFC4: sra         $t9, $t2, 4
        ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
            goto L_8005E018;
    }
    // 0x8005DFC4: sra         $t9, $t2, 4
    ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8005DFC8: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x8005DFCC: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8005DFD0: bne         $v1, $zero, L_8005DFDC
    if (ctx->r3 != 0) {
        // 0x8005DFD4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005DFDC;
    }
    // 0x8005DFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005DFD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005DFDC:
    // 0x8005DFDC: bne         $t2, $v0, L_8005E018
    if (ctx->r10 != ctx->r2) {
        // 0x8005DFE0: nop
    
            goto L_8005E018;
    }
    // 0x8005DFE0: nop

    // 0x8005DFE4: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x8005DFE8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8005DFEC: sra         $t8, $t5, 4
    ctx->r24 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8005DFF0: bne         $t6, $t8, L_8005E018
    if (ctx->r14 != ctx->r24) {
        // 0x8005DFF4: addiu       $a0, $zero, 0x223
        ctx->r4 = ADD32(0, 0X223);
            goto L_8005E018;
    }
    // 0x8005DFF4: addiu       $a0, $zero, 0x223
    ctx->r4 = ADD32(0, 0X223);
    // 0x8005DFF8: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8005DFFC: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8005E000: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8005E004: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005E008: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005E00C: jal         0x80009558
    // 0x8005E010: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_9;
    // 0x8005E010: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x8005E014: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8005E018:
    // 0x8005E018: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005E01C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005E020: bne         $t9, $at, L_8005E064
    if (ctx->r25 != ctx->r1) {
        // 0x8005E024: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E064;
    }
    // 0x8005E024: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E028: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8005E02C: nop

    // 0x8005E030: bne         $t1, $t3, L_8005E064
    if (ctx->r9 != ctx->r11) {
        // 0x8005E034: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E064;
    }
    // 0x8005E034: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E038: jal         0x80023568
    // 0x8005E03C: nop

    func_80023568(rdram, ctx);
        goto after_10;
    // 0x8005E03C: nop

    after_10:
    // 0x8005E040: beq         $v0, $zero, L_8005E060
    if (ctx->r2 == 0) {
        // 0x8005E044: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005E060;
    }
    // 0x8005E044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E048: addiu       $t4, $zero, 0xA5
    ctx->r12 = ADD32(0, 0XA5);
    // 0x8005E04C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005E050: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E054: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005E058: jal         0x8005E204
    // 0x8005E05C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_11;
    // 0x8005E05C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_11:
L_8005E060:
    // 0x8005E060: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
L_8005E064:
    // 0x8005E064: jal         0x800AFC3C
    // 0x8005E068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8005E068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8005E06C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E070: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E074: jal         0x8005D048
    // 0x8005E078: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_13;
    // 0x8005E078: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_13:
    // 0x8005E07C: jal         0x8001BAC8
    // 0x8005E080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_14;
    // 0x8005E080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8005E084: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005E088: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E08C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005E090: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E094: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005E098: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005E09C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E0A0: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8005E0A4: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005E0A8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E0AC: jal         0x800C9AD0
    // 0x8005E0B0: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_15;
    // 0x8005E0B0: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_15:
    // 0x8005E0B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E0B8: lwc1        $f19, 0x6A98($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6A98);
    // 0x8005E0BC: lwc1        $f18, 0x6A9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6A9C);
    // 0x8005E0C0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E0C4: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005E0C8: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005E0CC: bc1f        L_8005E13C
    if (!c1cs) {
        // 0x8005E0D0: nop
    
            goto L_8005E13C;
    }
    // 0x8005E0D0: nop

    // 0x8005E0D4: jal         0x80070750
    // 0x8005E0D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x8005E0D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_16:
    // 0x8005E0DC: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8005E0E0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005E0E4: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005E0E8: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8005E0EC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005E0F0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005E0F4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005E0F8: bne         $at, $zero, L_8005E108
    if (ctx->r1 != 0) {
        // 0x8005E0FC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005E108;
    }
    // 0x8005E0FC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005E100: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E104: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E108:
    // 0x8005E108: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005E10C: beq         $at, $zero, L_8005E118
    if (ctx->r1 == 0) {
        // 0x8005E110: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005E118;
    }
    // 0x8005E110: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005E114: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E118:
    // 0x8005E118: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005E11C: bne         $at, $zero, L_8005E12C
    if (ctx->r1 != 0) {
        // 0x8005E120: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005E12C;
    }
    // 0x8005E120: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005E124: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005E128: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005E12C:
    // 0x8005E12C: beq         $at, $zero, L_8005E138
    if (ctx->r1 == 0) {
        // 0x8005E130: nop
    
            goto L_8005E138;
    }
    // 0x8005E130: nop

    // 0x8005E134: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005E138:
    // 0x8005E138: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005E13C:
    // 0x8005E13C: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E140: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005E144: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005E148: bne         $at, $zero, L_8005E178
    if (ctx->r1 != 0) {
        // 0x8005E14C: addiu       $a1, $a1, -0x2A20
        ctx->r5 = ADD32(ctx->r5, -0X2A20);
            goto L_8005E178;
    }
    // 0x8005E14C: addiu       $a1, $a1, -0x2A20
    ctx->r5 = ADD32(ctx->r5, -0X2A20);
    // 0x8005E150: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005E154: nop

    // 0x8005E158: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x8005E15C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8005E160: beq         $at, $zero, L_8005E17C
    if (ctx->r1 == 0) {
        // 0x8005E164: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8005E17C;
    }
    // 0x8005E164: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005E168: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005E16C: nop

    // 0x8005E170: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005E174: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005E178:
    // 0x8005E178: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8005E17C:
    // 0x8005E17C: nop

    // 0x8005E180: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005E184: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005E188: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005E18C: nop

    // 0x8005E190: bne         $s1, $t5, L_8005E1C0
    if (ctx->r17 != ctx->r13) {
        // 0x8005E194: nop
    
            goto L_8005E1C0;
    }
    // 0x8005E194: nop

    // 0x8005E198: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005E19C: nop

    // 0x8005E1A0: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005E1A4: beq         $t8, $zero, L_8005E1C0
    if (ctx->r24 == 0) {
        // 0x8005E1A8: nop
    
            goto L_8005E1C0;
    }
    // 0x8005E1A8: nop

    // 0x8005E1AC: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E1B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E1B4: bne         $t7, $at, L_8005E1C0
    if (ctx->r15 != ctx->r1) {
        // 0x8005E1B8: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005E1C0;
    }
    // 0x8005E1B8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005E1BC: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005E1C0:
    // 0x8005E1C0: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E1C4: nop

    // 0x8005E1C8: beq         $t3, $zero, L_8005E1EC
    if (ctx->r11 == 0) {
        // 0x8005E1CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005E1EC;
    }
    // 0x8005E1CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E1D0: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x8005E1D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E1D8: bne         $t4, $zero, L_8005E1E8
    if (ctx->r12 != 0) {
        // 0x8005E1DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005E1E8;
    }
    // 0x8005E1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E1E0: jal         0x8005CB68
    // 0x8005E1E4: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    racer_boss_finish(rdram, ctx);
        goto after_17;
    // 0x8005E1E4: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    after_17:
L_8005E1E8:
    // 0x8005E1E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005E1EC:
    // 0x8005E1EC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005E1F0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005E1F4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1F8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005E1FC: jr          $ra
    // 0x8005E200: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005E200: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800657C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800657CC: jal         0x80065754
    // 0x800657D0: nop

    static_3_80065754(rdram, ctx);
        goto after_0;
    // 0x800657D0: nop

    after_0:
    // 0x800657D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800657D8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800657DC: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x800657E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800657E4: jr          $ra
    // 0x800657E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800657E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void coss_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007088C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80070890: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070894: bgezl       $v0, L_800708A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070898: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_800708A4;
    }
    goto skip_0;
    // 0x80070898: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x8007089C: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x800708A0: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_800708A4:
    // 0x800708A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800708A8: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x800708AC: addiu       $v0, $v0, -0x2BC4
    ctx->r2 = ADD32(ctx->r2, -0X2BC4);
    // 0x800708B0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800708B4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800708B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800708BC: bgez        $a0, L_800708C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800708C0: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_800708C8;
    }
    // 0x800708C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800708C4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800708C8:
    // 0x800708C8: jr          $ra
    // 0x800708CC: nop

    return;
    // 0x800708CC: nop

;}
RECOMP_FUNC void light_update_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032C7C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80032C80: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80032C84: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80032C88: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80032C8C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80032C90: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80032C94: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80032C98: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80032C9C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80032CA0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80032CA4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80032CA8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80032CAC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80032CB0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80032CB4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80032CB8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80032CBC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80032CC0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80032CC4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80032CC8: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x80032CCC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80032CD0: lbu         $t6, 0x3D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3D);
    // 0x80032CD4: nop

    // 0x80032CD8: bne         $t6, $zero, L_80033798
    if (ctx->r14 != 0) {
        // 0x80032CDC: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80033798;
    }
    // 0x80032CDC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80032CE0: lb          $v0, 0x53($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X53);
    // 0x80032CE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032CE8: beq         $v0, $zero, L_80032D10
    if (ctx->r2 == 0) {
        // 0x80032CEC: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_80032D10;
    }
    // 0x80032CEC: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80032CF0: beq         $v0, $at, L_80032D18
    if (ctx->r2 == ctx->r1) {
        // 0x80032CF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80032D18;
    }
    // 0x80032CF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032CF8: beq         $v0, $at, L_80032D20
    if (ctx->r2 == ctx->r1) {
        // 0x80032CFC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80032D20;
    }
    // 0x80032CFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80032D00: beq         $v0, $at, L_80032D28
    if (ctx->r2 == ctx->r1) {
        // 0x80032D04: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_80032D28;
    }
    // 0x80032D04: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80032D08: b           L_80032D28
    // 0x80032D0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80032D28;
    // 0x80032D0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80032D10:
    // 0x80032D10: b           L_80032D28
    // 0x80032D14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80032D28;
    // 0x80032D14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80032D18:
    // 0x80032D18: b           L_80032D28
    // 0x80032D1C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D28;
    // 0x80032D1C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D20:
    // 0x80032D20: b           L_80032D28
    // 0x80032D24: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D28;
    // 0x80032D24: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D28:
    // 0x80032D28: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032D2C: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032D30: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032D34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D3C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80032D40: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032D44: addiu       $s1, $s1, -0x3698
    ctx->r17 = ADD32(ctx->r17, -0X3698);
    // 0x80032D48: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032D4C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80032D50: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80032D54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032D58: sh          $t8, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r24;
    // 0x80032D5C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032D60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D68: lwc1        $f8, 0x10($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032D6C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80032D70: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032D78: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032D7C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80032D80: addiu       $s7, $s7, -0x2B34
    ctx->r23 = ADD32(ctx->r23, -0X2B34);
    // 0x80032D84: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032D88: sh          $t2, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r10;
    // 0x80032D8C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032D90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D98: lwc1        $f16, 0x14($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032D9C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80032DA0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032DA4: lw          $t5, -0x36A4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X36A4);
    // 0x80032DA8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80032DAC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032DB0: blez        $t5, L_80033290
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80032DB4: sh          $t4, 0x7E($sp)
        MEM_H(0X7E, ctx->r29) = ctx->r12;
            goto L_80033290;
    }
    // 0x80032DB4: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x80032DB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032DBC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80032DC0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80032DC4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80032DC8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80032DCC: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80032DD0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80032DD4: addiu       $s3, $s3, -0x36A0
    ctx->r19 = ADD32(ctx->r19, -0X36A0);
    // 0x80032DD8: addiu       $s4, $s4, -0x2B38
    ctx->r20 = ADD32(ctx->r20, -0X2B38);
    // 0x80032DDC: addiu       $s6, $s6, -0x2B3C
    ctx->r22 = ADD32(ctx->r22, -0X2B3C);
    // 0x80032DE0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80032DE4: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80032DE8:
    // 0x80032DE8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032DEC: lw          $t6, -0x36B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36B0);
    // 0x80032DF0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80032DF4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80032DF8: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80032DFC: nop

    // 0x80032E00: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80032E04: nop

    // 0x80032E08: and         $t2, $t8, $t9
    ctx->r10 = ctx->r24 & ctx->r25;
    // 0x80032E0C: beq         $t2, $zero, L_80033278
    if (ctx->r10 == 0) {
        // 0x80032E10: nop
    
            goto L_80033278;
    }
    // 0x80032E10: nop

    // 0x80032E14: lbu         $t3, 0x4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4);
    // 0x80032E18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032E1C: bne         $t3, $at, L_80033278
    if (ctx->r11 != ctx->r1) {
        // 0x80032E20: nop
    
            goto L_80033278;
    }
    // 0x80032E20: nop

    // 0x80032E24: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x80032E28: lh          $t5, 0x50($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X50);
    // 0x80032E2C: nop

    // 0x80032E30: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80032E34: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E38: nop
    
            goto L_80033278;
    }
    // 0x80032E38: nop

    // 0x80032E3C: lh          $t6, 0x56($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X56);
    // 0x80032E40: lh          $t7, 0x80($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X80);
    // 0x80032E44: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80032E48: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E4C: nop
    
            goto L_80033278;
    }
    // 0x80032E4C: nop

    // 0x80032E50: lh          $t8, 0x52($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X52);
    // 0x80032E54: nop

    // 0x80032E58: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032E5C: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E60: nop
    
            goto L_80033278;
    }
    // 0x80032E60: nop

    // 0x80032E64: lh          $t9, 0x58($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X58);
    // 0x80032E68: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x80032E6C: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80032E70: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E74: nop
    
            goto L_80033278;
    }
    // 0x80032E74: nop

    // 0x80032E78: lh          $t3, 0x54($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X54);
    // 0x80032E7C: nop

    // 0x80032E80: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80032E84: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E88: nop
    
            goto L_80033278;
    }
    // 0x80032E88: nop

    // 0x80032E8C: lh          $t5, 0x5A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5A);
    // 0x80032E90: nop

    // 0x80032E94: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80032E98: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032E9C: nop
    
            goto L_80033278;
    }
    // 0x80032E9C: nop

    // 0x80032EA0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80032EA4: nop

    // 0x80032EA8: bne         $t6, $zero, L_80032F80
    if (ctx->r14 != 0) {
        // 0x80032EAC: nop
    
            goto L_80032F80;
    }
    // 0x80032EAC: nop

    // 0x80032EB0: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80032EB4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80032EB8: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80032EBC: bne         $at, $zero, L_80033278
    if (ctx->r1 != 0) {
        // 0x80032EC0: nop
    
            goto L_80033278;
    }
    // 0x80032EC0: nop

    // 0x80032EC4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80032EC8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80032ECC: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032ED0: mflo        $t7
    ctx->r15 = lo;
    // 0x80032ED4: addu        $t3, $t8, $t7
    ctx->r11 = ADD32(ctx->r24, ctx->r15);
    // 0x80032ED8: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80032EDC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032EE0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80032EE4: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032EE8: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80032EEC: nop

    // 0x80032EF0: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80032EF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80032EF8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80032EFC: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x80032F00: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F04: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80032F08: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F0C: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x80032F10: nop

    // 0x80032F14: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80032F18: mflo        $t6
    ctx->r14 = lo;
    // 0x80032F1C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80032F20: sw          $t3, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r11;
    // 0x80032F24: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F28: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80032F2C: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F30: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80032F34: nop

    // 0x80032F38: sra         $t8, $t2, 16
    ctx->r24 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80032F3C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032F40: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80032F44: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80032F48: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F4C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80032F50: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F54: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80032F58: nop

    // 0x80032F5C: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80032F60: mflo        $t7
    ctx->r15 = lo;
    // 0x80032F64: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x80032F68: sw          $t9, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r25;
    // 0x80032F6C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80032F70: nop

    // 0x80032F74: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80032F78: b           L_80033278
    // 0x80032F7C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_80033278;
    // 0x80032F7C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80032F80:
    // 0x80032F80: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80032F84: lwc1        $f6, 0xC($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032F88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032F8C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032F90: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x80032F94: lwc1        $f16, 0x10($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032F98: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80032F9C: nop

    // 0x80032FA0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80032FA4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x80032FA8: lwc1        $f6, 0x14($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032FAC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80032FB0: nop

    // 0x80032FB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032FB8: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
    // 0x80032FBC: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80032FC0: nop

    // 0x80032FC4: bne         $t3, $at, L_80032FD0
    if (ctx->r11 != ctx->r1) {
        // 0x80032FC8: nop
    
            goto L_80032FD0;
    }
    // 0x80032FC8: nop

    // 0x80032FCC: swc1        $f22, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f22.u32l;
L_80032FD0:
    // 0x80032FD0: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80032FD4: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80032FD8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80032FDC: lwc1        $f12, 0x0($s7)
    ctx->f12.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80032FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80032FE4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80032FE8: nop

    // 0x80032FEC: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80032FF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80032FF4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80032FF8: swc1        $f6, -0x2B40($at)
    MEM_W(-0X2B40, ctx->r1) = ctx->f6.u32l;
    // 0x80032FFC: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80033000: nop

    // 0x80033004: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80033008: nop

    // 0x8003300C: bc1f        L_80033278
    if (!c1cs) {
        // 0x80033010: nop
    
            goto L_80033278;
    }
    // 0x80033010: nop

    // 0x80033014: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x80033018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003301C: bne         $t4, $at, L_80033038
    if (ctx->r12 != ctx->r1) {
        // 0x80033020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80033038;
    }
    // 0x80033020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033024: jal         0x80033C08
    // 0x80033028: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_direction_calc(rdram, ctx);
        goto after_0;
    // 0x80033028: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003302C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80033030: b           L_8003303C
    // 0x80033034: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8003303C;
    // 0x80033034: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80033038:
    // 0x80033038: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_8003303C:
    // 0x8003303C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80033040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033044: bc1f        L_80033278
    if (!c1cs) {
        // 0x80033048: nop
    
            goto L_80033278;
    }
    // 0x80033048: nop

    // 0x8003304C: jal         0x80033A14
    // 0x80033050: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_distance_calc(rdram, ctx);
        goto after_1;
    // 0x80033050: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_1:
    // 0x80033054: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033058: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8003305C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80033060: addiu       $t0, $t0, -0x369C
    ctx->r8 = ADD32(ctx->r8, -0X369C);
    // 0x80033064: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80033068: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8003306C: bc1f        L_80033278
    if (!c1cs) {
        // 0x80033070: nop
    
            goto L_80033278;
    }
    // 0x80033070: nop

    // 0x80033074: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x80033078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003307C: lbu         $t7, 0x71($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X71);
    // 0x80033080: nop

    // 0x80033084: beq         $t7, $zero, L_80033154
    if (ctx->r15 == 0) {
        // 0x80033088: nop
    
            goto L_80033154;
    }
    // 0x80033088: nop

    // 0x8003308C: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033090: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80033094: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x80033098: nop

    // 0x8003309C: bc1f        L_800330F0
    if (!c1cs) {
        // 0x800330A0: nop
    
            goto L_800330F0;
    }
    // 0x800330A0: nop

    // 0x800330A4: jal         0x800C9AD0
    // 0x800330A8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800330A8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_2:
    // 0x800330AC: nop

    // 0x800330B0: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800330B4: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800330B8: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800330BC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800330C0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800330C4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800330C8: addiu       $t0, $t0, -0x369C
    ctx->r8 = ADD32(ctx->r8, -0X369C);
    // 0x800330CC: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800330D0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800330D4: nop

    // 0x800330D8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800330DC: swc1        $f16, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f16.u32l;
    // 0x800330E0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800330E4: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800330E8: b           L_80033100
    // 0x800330EC: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
        goto L_80033100;
    // 0x800330EC: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
L_800330F0:
    // 0x800330F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800330F4: swc1        $f26, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f26.u32l;
    // 0x800330F8: swc1        $f26, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f26.u32l;
    // 0x800330FC: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
L_80033100:
    // 0x80033100: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80033104: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80033108: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003310C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80033110: mflo        $t8
    ctx->r24 = lo;
    // 0x80033114: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80033118: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003311C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80033120: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033124: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033128: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003312C: mflo        $t2
    ctx->r10 = lo;
    // 0x80033130: addu        $t7, $t3, $t2
    ctx->r15 = ADD32(ctx->r11, ctx->r10);
    // 0x80033134: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x80033138: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003313C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80033140: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033144: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033148: mflo        $t8
    ctx->r24 = lo;
    // 0x8003314C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80033150: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
L_80033154:
    // 0x80033154: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80033158: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8003315C: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033160: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80033164: mflo        $t2
    ctx->r10 = lo;
    // 0x80033168: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x8003316C: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x80033170: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80033174: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033178: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003317C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80033180: nop

    // 0x80033184: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033188: mflo        $t3
    ctx->r11 = lo;
    // 0x8003318C: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x80033190: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80033194: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80033198: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003319C: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331A0: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x800331A4: nop

    // 0x800331A8: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800331AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800331B0: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800331B4: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x800331B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331BC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800331C0: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800331C8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800331CC: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800331D0: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800331D4: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800331D8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800331DC: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800331E0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800331E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800331E8: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x800331EC: beq         $t3, $zero, L_80033238
    if (ctx->r11 == 0) {
        // 0x800331F0: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_80033238;
    }
    // 0x800331F0: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
    // 0x800331F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800331F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800331FC: sub.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x80033200: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033204: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80033208: nop

    // 0x8003320C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80033210: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80033214: nop

    // 0x80033218: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8003321C: bne         $t3, $zero, L_80033230
    if (ctx->r11 != 0) {
        // 0x80033220: nop
    
            goto L_80033230;
    }
    // 0x80033220: nop

    // 0x80033224: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80033228: b           L_80033248
    // 0x8003322C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80033248;
    // 0x8003322C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80033230:
    // 0x80033230: b           L_80033248
    // 0x80033234: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80033248;
    // 0x80033234: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80033238:
    // 0x80033238: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8003323C: nop

    // 0x80033240: bltz        $t3, L_80033230
    if (SIGNED(ctx->r11) < 0) {
        // 0x80033244: nop
    
            goto L_80033230;
    }
    // 0x80033244: nop

L_80033248:
    // 0x80033248: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003324C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80033250: multu       $t2, $s2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033254: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x80033258: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003325C: mflo        $t9
    ctx->r25 = lo;
    // 0x80033260: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x80033264: sw          $t5, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r13;
    // 0x80033268: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003326C: nop

    // 0x80033270: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80033274: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_80033278:
    // 0x80033278: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8003327C: lw          $t3, -0x36A4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X36A4);
    // 0x80033280: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80033284: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80033288: bne         $at, $zero, L_80032DE8
    if (ctx->r1 != 0) {
        // 0x8003328C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80032DE8;
    }
    // 0x8003328C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80033290:
    // 0x80033290: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x80033294: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80033298: lbu         $t6, 0x71($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X71);
    // 0x8003329C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800332A0: addiu       $s3, $s3, -0x36A0
    ctx->r19 = ADD32(ctx->r19, -0X36A0);
    // 0x800332A4: addiu       $t0, $t0, -0x369C
    ctx->r8 = ADD32(ctx->r8, -0X369C);
    // 0x800332A8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800332AC: beq         $t6, $zero, L_800336F4
    if (ctx->r14 == 0) {
        // 0x800332B0: addiu       $s2, $zero, 0x14
        ctx->r18 = ADD32(0, 0X14);
            goto L_800336F4;
    }
    // 0x800332B0: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x800332B4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800332B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800332BC: bne         $a3, $zero, L_800332DC
    if (ctx->r7 != 0) {
        // 0x800332C0: nop
    
            goto L_800332DC;
    }
    // 0x800332C0: nop

    // 0x800332C4: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800332C8: nop

    // 0x800332CC: sb          $zero, 0x7($t9)
    MEM_B(0X7, ctx->r25) = 0;
    // 0x800332D0: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x800332D4: b           L_80033794
    // 0x800332D8: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
        goto L_80033794;
    // 0x800332D8: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
L_800332DC:
    // 0x800332DC: bne         $a3, $at, L_800333EC
    if (ctx->r7 != ctx->r1) {
        // 0x800332E0: nop
    
            goto L_800333EC;
    }
    // 0x800332E0: nop

    // 0x800332E4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800332E8: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x800332EC: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x800332F0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x800332F4: sb          $t8, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r24;
    // 0x800332F8: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800332FC: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033300: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80033304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033308: sb          $t2, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r10;
    // 0x8003330C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80033310: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033314: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80033318: nop

    // 0x8003331C: sb          $t5, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r13;
    // 0x80033320: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033324: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x80033328: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x8003332C: nop

    // 0x80033330: sb          $t7, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r15;
    // 0x80033334: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033338: nop

    // 0x8003333C: sb          $zero, 0x11($t2)
    MEM_B(0X11, ctx->r10) = 0;
    // 0x80033340: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033344: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033348: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8003334C: nop

    // 0x80033350: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033354: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033358: nop

    // 0x8003335C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033360: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033364: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033368: nop

    // 0x8003336C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80033370: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80033374: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033378: sh          $t5, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r13;
    // 0x8003337C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80033380: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033384: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80033388: nop

    // 0x8003338C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80033390: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80033394: nop

    // 0x80033398: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003339C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800333A8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800333AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333B0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800333B4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800333B8: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x800333BC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800333C0: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800333C4: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800333C8: nop

    // 0x800333CC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800333D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333D4: nop

    // 0x800333D8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800333DC: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800333E0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800333E4: b           L_80033794
    // 0x800333E8: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
        goto L_80033794;
    // 0x800333E8: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
L_800333EC:
    // 0x800333EC: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x800333F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800333F4: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x800333F8: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x800333FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80033400: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80033404: beq         $at, $zero, L_80033418
    if (ctx->r1 == 0) {
        // 0x80033408: addiu       $v1, $a2, 0x28
        ctx->r3 = ADD32(ctx->r6, 0X28);
            goto L_80033418;
    }
    // 0x80033408: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x8003340C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033410: b           L_80033418
    // 0x80033414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80033418;
    // 0x80033414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80033418:
    // 0x80033418: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x8003341C: bne         $at, $zero, L_800334A0
    if (ctx->r1 != 0) {
        // 0x80033420: addiu       $s5, $zero, 0x2
        ctx->r21 = ADD32(0, 0X2);
            goto L_800334A0;
    }
    // 0x80033420: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80033424:
    // 0x80033424: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033428: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8003342C: mflo        $t3
    ctx->r11 = lo;
    // 0x80033430: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x80033434: lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X10);
    // 0x80033438: nop

    // 0x8003343C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80033440: beq         $at, $zero, L_80033490
    if (ctx->r1 == 0) {
        // 0x80033444: nop
    
            goto L_80033490;
    }
    // 0x80033444: nop

    // 0x80033448: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003344C: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80033450: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80033454: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80033458: mflo        $t9
    ctx->r25 = lo;
    // 0x8003345C: addu        $t5, $a2, $t9
    ctx->r13 = ADD32(ctx->r6, ctx->r25);
    // 0x80033460: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x80033464: nop

    // 0x80033468: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003346C: beq         $at, $zero, L_80033490
    if (ctx->r1 == 0) {
        // 0x80033470: nop
    
            goto L_80033490;
    }
    // 0x80033470: nop

    // 0x80033474: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80033478: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8003347C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80033480: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80033484: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80033488: b           L_80033490
    // 0x8003348C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_80033490;
    // 0x8003348C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80033490:
    // 0x80033490: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80033494: slt         $at, $s5, $a3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80033498: bne         $at, $zero, L_80033424
    if (ctx->r1 != 0) {
        // 0x8003349C: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80033424;
    }
    // 0x8003349C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_800334A0:
    // 0x800334A0: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800334A4: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800334A8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x800334AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800334B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800334B4: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x800334B8: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x800334BC: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800334C0: sb          $t6, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r14;
    // 0x800334C4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800334C8: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x800334CC: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800334D0: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x800334D4: nop

    // 0x800334D8: sb          $t8, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r24;
    // 0x800334DC: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800334E0: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800334E4: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800334E8: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800334EC: mflo        $v1
    ctx->r3 = lo;
    // 0x800334F0: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x800334F4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800334F8: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x800334FC: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80033500: lw          $t8, 0x10($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X10);
    // 0x80033504: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033508: sb          $t8, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r24;
    // 0x8003350C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033510: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033514: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x80033518: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003351C: nop

    // 0x80033520: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80033524: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80033528: mflo        $a3
    ctx->r7 = lo;
    // 0x8003352C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80033530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033538: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003353C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033540: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80033544: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80033548: sh          $t9, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r25;
    // 0x8003354C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80033550: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033554: addu        $t8, $t4, $v1
    ctx->r24 = ADD32(ctx->r12, ctx->r3);
    // 0x80033558: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8003355C: nop

    // 0x80033560: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033564: mflo        $v0
    ctx->r2 = lo;
    // 0x80033568: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003356C: nop

    // 0x80033570: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80033574: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033578: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003357C: nop

    // 0x80033580: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80033584: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80033588: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003358C: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x80033590: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033594: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033598: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x8003359C: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800335A0: nop

    // 0x800335A4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800335A8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800335AC: nop

    // 0x800335B0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800335B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800335B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800335BC: nop

    // 0x800335C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800335C4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800335C8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800335CC: sh          $t4, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r12;
    // 0x800335D0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800335D4: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x800335D8: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x800335DC: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x800335E0: nop

    // 0x800335E4: sb          $t2, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r10;
    // 0x800335E8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800335EC: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x800335F0: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x800335F4: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x800335F8: nop

    // 0x800335FC: sb          $t4, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r12;
    // 0x80033600: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033604: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033608: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x8003360C: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x80033610: nop

    // 0x80033614: sb          $t2, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r10;
    // 0x80033618: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003361C: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033620: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80033624: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x80033628: nop

    // 0x8003362C: sb          $t4, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r12;
    // 0x80033630: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80033634: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033638: addu        $t3, $t7, $v0
    ctx->r11 = ADD32(ctx->r15, ctx->r2);
    // 0x8003363C: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80033640: nop

    // 0x80033644: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033648: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003364C: nop

    // 0x80033650: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033654: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033658: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003365C: nop

    // 0x80033660: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80033664: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80033668: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003366C: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
    // 0x80033670: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80033674: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x80033678: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x8003367C: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80033680: nop

    // 0x80033684: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80033688: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003368C: nop

    // 0x80033690: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80033694: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033698: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003369C: nop

    // 0x800336A0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800336A4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800336A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800336AC: sh          $t7, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r15;
    // 0x800336B0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800336B4: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800336B8: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x800336BC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800336C0: nop

    // 0x800336C4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800336C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800336CC: nop

    // 0x800336D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800336D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800336D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800336DC: nop

    // 0x800336E0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800336E4: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800336E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800336EC: b           L_80033794
    // 0x800336F0: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
        goto L_80033794;
    // 0x800336F0: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
L_800336F4:
    // 0x800336F4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800336F8: nop

    // 0x800336FC: blez        $a3, L_80033764
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80033700: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_80033764;
    }
    // 0x80033700: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80033704: bne         $at, $zero, L_80033714
    if (ctx->r1 != 0) {
        // 0x80033708: nop
    
            goto L_80033714;
    }
    // 0x80033708: nop

    // 0x8003370C: jal         0x800337E4
    // 0x80033710: nop

    light_update_ambience(rdram, ctx);
        goto after_3;
    // 0x80033710: nop

    after_3:
L_80033714:
    // 0x80033714: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033718: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x8003371C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80033720: nop

    // 0x80033724: sb          $t7, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r15;
    // 0x80033728: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8003372C: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033730: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x80033734: nop

    // 0x80033738: sb          $t6, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r14;
    // 0x8003373C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033740: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033744: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x80033748: nop

    // 0x8003374C: sb          $t4, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r12;
    // 0x80033750: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033754: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033758: lw          $t3, 0x10($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X10);
    // 0x8003375C: b           L_80033794
    // 0x80033760: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
        goto L_80033794;
    // 0x80033760: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
L_80033764:
    // 0x80033764: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033768: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8003376C: sb          $v0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r2;
    // 0x80033770: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033774: nop

    // 0x80033778: sb          $v0, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r2;
    // 0x8003377C: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033780: nop

    // 0x80033784: sb          $v0, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r2;
    // 0x80033788: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x8003378C: nop

    // 0x80033790: sb          $zero, 0x7($t4)
    MEM_B(0X7, ctx->r12) = 0;
L_80033794:
    // 0x80033794: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80033798:
    // 0x80033798: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003379C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800337A0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800337A4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800337A8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800337AC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800337B0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800337B4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800337B8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800337BC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800337C0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800337C4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800337C8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800337CC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800337D0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800337D4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800337D8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800337DC: jr          $ra
    // 0x800337E0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800337E0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AB00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000AB04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AB08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000AB0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000AB10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000AB14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000AB18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AB1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AB24: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8000AB28: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x8000AB2C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000AB30: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x8000AB34: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000AB38: bne         $t6, $zero, L_8000ABAC
    if (ctx->r14 != 0) {
        // 0x8000AB3C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB3C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8000AB40: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AB44: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8000AB48: beq         $s0, $zero, L_8000ABAC
    if (ctx->r16 == 0) {
        // 0x8000AB4C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB4C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000AB50:
    // 0x8000AB50: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8000AB54: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AB58: bne         $s3, $t7, L_8000ABA0
    if (ctx->r19 != ctx->r15) {
        // 0x8000AB5C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB5C: nop

    // 0x8000AB60: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8000AB64: nop

    // 0x8000AB68: bne         $s5, $t8, L_8000ABA0
    if (ctx->r21 != ctx->r24) {
        // 0x8000AB6C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB6C: nop

    // 0x8000AB70: beq         $s1, $zero, L_8000AB8C
    if (ctx->r17 == 0) {
        // 0x8000AB74: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_8000AB8C;
    }
    // 0x8000AB74: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x8000AB78: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8000AB7C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8000AB80: nop

    // 0x8000AB84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8000AB88: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_8000AB8C:
    // 0x8000AB8C: jal         0x800C8760
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000AB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AB98: jal         0x800C8790
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_8000ABA0:
    // 0x8000ABA0: bne         $s1, $zero, L_8000AB50
    if (ctx->r17 != 0) {
        // 0x8000ABA4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AB50;
    }
    // 0x8000ABA4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000ABA8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000ABAC:
    // 0x8000ABAC: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x8000ABB0: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x8000ABB4: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x8000ABB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABBC: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x8000ABC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABC4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000ABC8: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x8000ABCC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ABD4: jal         0x800C9AE0
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x8000ABDC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABE0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABE4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABE8: jal         0x800C9650
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8000ABF0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8000ABF4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABF8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000ABFC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8000AC00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AC04: jal         0x800C91AC
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8000AC0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000AC10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AC14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AC18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AC1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000AC20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000AC24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AC28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000AC2C: jr          $ra
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9788: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C978C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9790: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9794: beql        $t6, $zero, L_800C97F8
    if (ctx->r14 == 0) {
        // 0x800C9798: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C97F8;
    }
    goto skip_0;
    // 0x800C9798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C979C: jal         0x80065668
    // 0x800C97A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C97A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C97A4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C97A8: beq         $v0, $zero, L_800C97F4
    if (ctx->r2 == 0) {
        // 0x800C97AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C97F4;
    }
    // 0x800C97AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C97B0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C97B4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C97B8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800C97BC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C97C0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C97C4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C97C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C97CC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C97D0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C97D4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C97D8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C97DC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800C97E0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C97E4: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C97E8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C97EC: jalr        $t9
    // 0x800C97F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C97F0: nop

    after_1:
L_800C97F4:
    // 0x800C97F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C97F8:
    // 0x800C97F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C97FC: jr          $ra
    // 0x800C9800: nop

    return;
    // 0x800C9800: nop

;}
RECOMP_FUNC void update_vehicle_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF714: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800AF718: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AF71C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AF720: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AF724: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AF728: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AF72C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AF730: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AF734: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AF738: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AF73C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AF740: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800AF744: lw          $s3, 0x64($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X64);
    // 0x800AF748: lw          $s7, 0x74($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X74);
    // 0x800AF74C: lb          $fp, 0x1D6($s3)
    ctx->r30 = MEM_B(ctx->r19, 0X1D6);
    // 0x800AF750: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AF754: jal         0x80012E28
    // 0x800AF758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x800AF758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x800AF75C: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x800AF760: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800AF764: lb          $t7, 0x57($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X57);
    // 0x800AF768: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800AF76C: blez        $t7, L_800AFC04
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AF770: lui         $s4, 0x800E
        ctx->r20 = S32(0X800E << 16);
            goto L_800AFC04;
    }
    // 0x800AF770: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AF774: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AF778: addiu       $s1, $s1, 0x2D00
    ctx->r17 = ADD32(ctx->r17, 0X2D00);
    // 0x800AF77C: addiu       $s4, $s4, 0x2E84
    ctx->r20 = ADD32(ctx->r20, 0X2E84);
L_800AF780:
    // 0x800AF780: andi        $t8, $s7, 0x1
    ctx->r24 = ctx->r23 & 0X1;
    // 0x800AF784: beq         $t8, $zero, L_800AFB28
    if (ctx->r24 == 0) {
        // 0x800AF788: nop
    
            goto L_800AFB28;
    }
    // 0x800AF788: nop

    // 0x800AF78C: beq         $fp, $zero, L_800AF7B0
    if (ctx->r30 == 0) {
        // 0x800AF790: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800AF7B0;
    }
    // 0x800AF790: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AF794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AF798: beq         $fp, $at, L_800AFA00
    if (ctx->r30 == ctx->r1) {
        // 0x800AF79C: nop
    
            goto L_800AFA00;
    }
    // 0x800AF79C: nop

    // 0x800AF7A0: beq         $fp, $s6, L_800AF9B0
    if (ctx->r30 == ctx->r22) {
        // 0x800AF7A4: nop
    
            goto L_800AF9B0;
    }
    // 0x800AF7A4: nop

    // 0x800AF7A8: b           L_800AFA54
    // 0x800AF7AC: nop

        goto L_800AFA54;
    // 0x800AF7AC: nop

L_800AF7B0:
    // 0x800AF7B0: bltz        $s0, L_800AF8E4
    if (SIGNED(ctx->r16) < 0) {
        // 0x800AF7B4: slti        $at, $s0, 0xA
        ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
            goto L_800AF8E4;
    }
    // 0x800AF7B4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800AF7B8: beq         $at, $zero, L_800AF8E8
    if (ctx->r1 == 0) {
        // 0x800AF7BC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800AF8E8;
    }
    // 0x800AF7BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AF7C0: lh          $v0, 0x16E($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X16E);
    // 0x800AF7C4: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800AF7C8: bgez        $v0, L_800AF7D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AF7CC: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800AF7D4;
    }
    // 0x800AF7CC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF7D0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800AF7D4:
    // 0x800AF7D4: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x800AF7D8: blez        $v0, L_800AFA54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AF7DC: slti        $at, $v0, 0x21
        ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
            goto L_800AFA54;
    }
    // 0x800AF7DC: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x800AF7E0: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    // 0x800AF7E4: lw          $t8, 0x2CF0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2CF0);
    // 0x800AF7E8: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AF7EC: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x800AF7F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AF7F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AF7F8: addiu       $t5, $t5, 0x2EC4
    ctx->r13 = ADD32(ctx->r13, 0X2EC4);
    // 0x800AF7FC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800AF800: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800AF804: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800AF808: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AF80C: bne         $at, $zero, L_800AF818
    if (ctx->r1 != 0) {
        // 0x800AF810: addiu       $t2, $t0, 0x3
        ctx->r10 = ADD32(ctx->r8, 0X3);
            goto L_800AF818;
    }
    // 0x800AF810: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x800AF814: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800AF818:
    // 0x800AF818: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF81C: lbu         $a0, 0x14($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X14);
    // 0x800AF820: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800AF824: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800AF828: subu        $t9, $t7, $a0
    ctx->r25 = SUB32(ctx->r15, ctx->r4);
    // 0x800AF82C: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800AF830: mflo        $t6
    ctx->r14 = lo;
    // 0x800AF834: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800AF838: subu        $v1, $t1, $t8
    ctx->r3 = SUB32(ctx->r9, ctx->r24);
    // 0x800AF83C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF840: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x800AF844: mflo        $t4
    ctx->r12 = lo;
    // 0x800AF848: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800AF84C: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AF850: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800AF854: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800AF858: lbu         $a1, 0x15($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X15);
    // 0x800AF85C: nop

    // 0x800AF860: subu        $t4, $t9, $a1
    ctx->r12 = SUB32(ctx->r25, ctx->r5);
    // 0x800AF864: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF868: mflo        $t5
    ctx->r13 = lo;
    // 0x800AF86C: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AF870: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x800AF874: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800AF878: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x800AF87C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800AF880: lbu         $a2, 0x16($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X16);
    // 0x800AF884: lbu         $t6, 0x2($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X2);
    // 0x800AF888: nop

    // 0x800AF88C: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x800AF890: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF894: mflo        $t7
    ctx->r15 = lo;
    // 0x800AF898: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800AF89C: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800AF8A0: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800AF8A4: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x800AF8A8: bne         $at, $zero, L_800AF8B4
    if (ctx->r1 != 0) {
        // 0x800AF8AC: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_800AF8B4;
    }
    // 0x800AF8AC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800AF8B0: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
L_800AF8B4:
    // 0x800AF8B4: lbu         $v0, 0x17($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X17);
    // 0x800AF8B8: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x800AF8BC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800AF8C0: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x800AF8C4: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF8C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AF8CC: mflo        $t5
    ctx->r13 = lo;
    // 0x800AF8D0: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AF8D4: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800AF8D8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800AF8DC: b           L_800AFA54
    // 0x800AF8E0: sw          $t9, 0x2D00($at)
    MEM_W(0X2D00, ctx->r1) = ctx->r25;
        goto L_800AFA54;
    // 0x800AF8E0: sw          $t9, 0x2D00($at)
    MEM_W(0X2D00, ctx->r1) = ctx->r25;
L_800AF8E4:
    // 0x800AF8E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800AF8E8:
    // 0x800AF8E8: beq         $s0, $at, L_800AF910
    if (ctx->r16 == ctx->r1) {
        // 0x800AF8EC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800AF910;
    }
    // 0x800AF8EC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800AF8F0: beq         $s0, $at, L_800AF938
    if (ctx->r16 == ctx->r1) {
        // 0x800AF8F4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800AF938;
    }
    // 0x800AF8F4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800AF8F8: beq         $s0, $at, L_800AF960
    if (ctx->r16 == ctx->r1) {
        // 0x800AF8FC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800AF960;
    }
    // 0x800AF8FC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800AF900: beq         $s0, $at, L_800AF988
    if (ctx->r16 == ctx->r1) {
        // 0x800AF904: nop
    
            goto L_800AF988;
    }
    // 0x800AF904: nop

    // 0x800AF908: b           L_800AFA54
    // 0x800AF90C: nop

        goto L_800AFA54;
    // 0x800AF90C: nop

L_800AF910:
    // 0x800AF910: lbu         $v0, 0x1DE($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DE);
    // 0x800AF914: nop

    // 0x800AF918: bne         $s5, $v0, L_800AF924
    if (ctx->r21 != ctx->r2) {
        // 0x800AF91C: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AF924;
    }
    // 0x800AF91C: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AF920: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AF924:
    // 0x800AF924: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AF928: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AF92C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AF930: b           L_800AFA54
    // 0x800AF934: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFA54;
    // 0x800AF934: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AF938:
    // 0x800AF938: lbu         $v0, 0x1DF($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DF);
    // 0x800AF93C: nop

    // 0x800AF940: bne         $s5, $v0, L_800AF94C
    if (ctx->r21 != ctx->r2) {
        // 0x800AF944: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_800AF94C;
    }
    // 0x800AF944: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800AF948: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AF94C:
    // 0x800AF94C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AF950: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AF954: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AF958: b           L_800AFA54
    // 0x800AF95C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFA54;
    // 0x800AF95C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AF960:
    // 0x800AF960: lbu         $v0, 0x1DC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AF964: nop

    // 0x800AF968: bne         $s5, $v0, L_800AF974
    if (ctx->r21 != ctx->r2) {
        // 0x800AF96C: andi        $t6, $v0, 0xF
        ctx->r14 = ctx->r2 & 0XF;
            goto L_800AF974;
    }
    // 0x800AF96C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800AF970: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AF974:
    // 0x800AF974: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AF978: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800AF97C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AF980: b           L_800AFA54
    // 0x800AF984: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_800AFA54;
    // 0x800AF984: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800AF988:
    // 0x800AF988: lbu         $v0, 0x1DD($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AF98C: nop

    // 0x800AF990: bne         $s5, $v0, L_800AF99C
    if (ctx->r21 != ctx->r2) {
        // 0x800AF994: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AF99C;
    }
    // 0x800AF994: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AF998: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AF99C:
    // 0x800AF99C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AF9A0: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AF9A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AF9A8: b           L_800AFA54
    // 0x800AF9AC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFA54;
    // 0x800AF9AC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AF9B0:
    // 0x800AF9B0: bne         $s0, $zero, L_800AF9D8
    if (ctx->r16 != 0) {
        // 0x800AF9B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800AF9D8;
    }
    // 0x800AF9B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AF9B8: lbu         $t8, 0x1DC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AF9BC: nop

    // 0x800AF9C0: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800AF9C4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800AF9C8: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800AF9CC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AF9D0: b           L_800AFA54
    // 0x800AF9D4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800AFA54;
    // 0x800AF9D4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_800AF9D8:
    // 0x800AF9D8: bne         $s0, $at, L_800AFA54
    if (ctx->r16 != ctx->r1) {
        // 0x800AF9DC: nop
    
            goto L_800AFA54;
    }
    // 0x800AF9DC: nop

    // 0x800AF9E0: lbu         $t7, 0x1DD($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AF9E4: nop

    // 0x800AF9E8: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800AF9EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AF9F0: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AF9F4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AF9F8: b           L_800AFA54
    // 0x800AF9FC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFA54;
    // 0x800AF9FC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AFA00:
    // 0x800AFA00: beq         $s0, $s6, L_800AFA10
    if (ctx->r16 == ctx->r22) {
        // 0x800AFA04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AFA10;
    }
    // 0x800AFA04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFA08: bne         $s0, $at, L_800AFA54
    if (ctx->r16 != ctx->r1) {
        // 0x800AFA0C: nop
    
            goto L_800AFA54;
    }
    // 0x800AFA0C: nop

L_800AFA10:
    // 0x800AFA10: lb          $t6, 0x2($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X2);
    // 0x800AFA14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AFA18: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800AFA1C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800AFA20: addiu       $t9, $t9, 0x7C88
    ctx->r25 = ADD32(ctx->r25, 0X7C88);
    // 0x800AFA24: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800AFA28: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800AFA2C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800AFA30: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFA34: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x800AFA38: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800AFA3C: bne         $at, $zero, L_800AFA48
    if (ctx->r1 != 0) {
        // 0x800AFA40: nop
    
            goto L_800AFA48;
    }
    // 0x800AFA40: nop

    // 0x800AFA44: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_800AFA48:
    // 0x800AFA48: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800AFA4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFA50: sw          $v0, 0x2EEC($at)
    MEM_W(0X2EEC, ctx->r1) = ctx->r2;
L_800AFA54:
    // 0x800AFA54: beq         $t3, $zero, L_800AFBD8
    if (ctx->r11 == 0) {
        // 0x800AFA58: nop
    
            goto L_800AFBD8;
    }
    // 0x800AFA58: nop

    // 0x800AFA5C: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFA60: sll         $a3, $s0, 5
    ctx->r7 = S32(ctx->r16 << 5);
    // 0x800AFA64: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFA68: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFA6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFA70: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800AFA74: bne         $t6, $zero, L_800AFA9C
    if (ctx->r14 != 0) {
        // 0x800AFA78: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800AFA9C;
    }
    // 0x800AFA78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AFA7C: jal         0x800AF52C
    // 0x800AFA80: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    obj_enable_emitter(rdram, ctx);
        goto after_1;
    // 0x800AFA80: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_1:
    // 0x800AFA84: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AFA88: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFA8C: nop

    // 0x800AFA90: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFA94: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFA98: nop

L_800AFA9C:
    // 0x800AFA9C: andi        $t7, $v1, 0x4000
    ctx->r15 = ctx->r3 & 0X4000;
    // 0x800AFAA0: beq         $t7, $zero, L_800AFAC0
    if (ctx->r15 == 0) {
        // 0x800AFAA4: andi        $t9, $v1, 0x400
        ctx->r25 = ctx->r3 & 0X400;
            goto L_800AFAC0;
    }
    // 0x800AFAA4: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x800AFAA8: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800AFAAC: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    // 0x800AFAB0: jal         0x800AFE5C
    // 0x800AFAB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800AFAB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800AFAB8: b           L_800AFBDC
    // 0x800AFABC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800AFBDC;
    // 0x800AFABC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800AFAC0:
    // 0x800AFAC0: beq         $t9, $zero, L_800AFADC
    if (ctx->r25 == 0) {
        // 0x800AFAC4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AFADC;
    }
    // 0x800AFAC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFAC8: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800AFACC: jal         0x800AFE5C
    // 0x800AFAD0: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800AFAD0: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    after_3:
    // 0x800AFAD4: b           L_800AFBDC
    // 0x800AFAD8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800AFBDC;
    // 0x800AFAD8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800AFADC:
    // 0x800AFADC: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x800AFAE0: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800AFAE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFAE8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AFAEC: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x800AFAF0: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFAF4: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800AFAF8: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFAFC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800AFB00: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800AFB04: lh          $t4, 0x40($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X40);
    // 0x800AFB08: nop

    // 0x800AFB0C: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AFB10: bne         $at, $zero, L_800AFBD8
    if (ctx->r1 != 0) {
        // 0x800AFB14: nop
    
            goto L_800AFBD8;
    }
    // 0x800AFB14: nop

    // 0x800AFB18: jal         0x800AFE5C
    // 0x800AFB1C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800AFB1C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    after_4:
    // 0x800AFB20: b           L_800AFBDC
    // 0x800AFB24: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800AFBDC;
    // 0x800AFB24: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800AFB28:
    // 0x800AFB28: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFB2C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x800AFB30: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x800AFB34: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFB38: nop

    // 0x800AFB3C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800AFB40: beq         $t7, $zero, L_800AFBD8
    if (ctx->r15 == 0) {
        // 0x800AFB44: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_800AFBD8;
    }
    // 0x800AFB44: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x800AFB48: beq         $t9, $zero, L_800AFB70
    if (ctx->r25 == 0) {
        // 0x800AFB4C: andi        $t4, $v1, 0x400
        ctx->r12 = ctx->r3 & 0X400;
            goto L_800AFB70;
    }
    // 0x800AFB4C: andi        $t4, $v1, 0x400
    ctx->r12 = ctx->r3 & 0X400;
    // 0x800AFB50: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800AFB54: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800AFB58: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800AFB5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFB60: jal         0x800AF6E4
    // 0x800AFB64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800AFB64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800AFB68: b           L_800AFBB0
    // 0x800AFB6C: nop

        goto L_800AFBB0;
    // 0x800AFB6C: nop

L_800AFB70:
    // 0x800AFB70: beq         $t4, $zero, L_800AFBA8
    if (ctx->r12 == 0) {
        // 0x800AFB74: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AFBA8;
    }
    // 0x800AFB74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFB78: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800AFB7C: ori         $t6, $v1, 0x200
    ctx->r14 = ctx->r3 | 0X200;
    // 0x800AFB80: addu        $a0, $a2, $t5
    ctx->r4 = ADD32(ctx->r6, ctx->r13);
    // 0x800AFB84: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800AFB88: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800AFB8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFB90: bne         $t7, $zero, L_800AFBB0
    if (ctx->r15 != 0) {
        // 0x800AFB94: nop
    
            goto L_800AFBB0;
    }
    // 0x800AFB94: nop

    // 0x800AFB98: jal         0x800AF6E4
    // 0x800AFB9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800AFB9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800AFBA0: b           L_800AFBB0
    // 0x800AFBA4: nop

        goto L_800AFBB0;
    // 0x800AFBA4: nop

L_800AFBA8:
    // 0x800AFBA8: jal         0x800AF6E4
    // 0x800AFBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800AFBAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_800AFBB0:
    // 0x800AFBB0: beq         $s0, $s6, L_800AFBC0
    if (ctx->r16 == ctx->r22) {
        // 0x800AFBB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AFBC0;
    }
    // 0x800AFBB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFBB8: bne         $s0, $at, L_800AFBD8
    if (ctx->r16 != ctx->r1) {
        // 0x800AFBBC: nop
    
            goto L_800AFBD8;
    }
    // 0x800AFBBC: nop

L_800AFBC0:
    // 0x800AFBC0: lb          $t9, 0x2($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X2);
    // 0x800AFBC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AFBC8: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800AFBCC: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800AFBD0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800AFBD4: sh          $zero, 0x7C88($at)
    MEM_H(0X7C88, ctx->r1) = 0;
L_800AFBD8:
    // 0x800AFBD8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800AFBDC:
    // 0x800AFBDC: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800AFBE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFBE4: sw          $t6, 0x2EEC($at)
    MEM_W(0X2EEC, ctx->r1) = ctx->r14;
    // 0x800AFBE8: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x800AFBEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AFBF0: lb          $t9, 0x57($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X57);
    // 0x800AFBF4: srl         $t5, $s7, 1
    ctx->r13 = S32(U32(ctx->r23) >> 1);
    // 0x800AFBF8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AFBFC: bne         $at, $zero, L_800AF780
    if (ctx->r1 != 0) {
        // 0x800AFC00: or          $s7, $t5, $zero
        ctx->r23 = ctx->r13 | 0;
            goto L_800AF780;
    }
    // 0x800AFC00: or          $s7, $t5, $zero
    ctx->r23 = ctx->r13 | 0;
L_800AFC04:
    // 0x800AFC04: jal         0x80012F30
    // 0x800AFC08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_8;
    // 0x800AFC08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x800AFC0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AFC10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AFC14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AFC18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AFC1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AFC20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AFC24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AFC28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AFC2C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AFC30: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AFC34: jr          $ra
    // 0x800AFC38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800AFC38: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_loop_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042098: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004209C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800420A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800420A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800420A8: jal         0x8006F94C
    // 0x800420AC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800420AC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_0:
    // 0x800420B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800420B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800420B8: lw          $t6, 0x78($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X78);
    // 0x800420BC: nop

    // 0x800420C0: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800420C4: bne         $at, $zero, L_800420D4
    if (ctx->r1 != 0) {
        // 0x800420C8: nop
    
            goto L_800420D4;
    }
    // 0x800420C8: nop

    // 0x800420CC: b           L_800420D8
    // 0x800420D0: sw          $t7, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r15;
        goto L_800420D8;
    // 0x800420D0: sw          $t7, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r15;
L_800420D4:
    // 0x800420D4: sw          $zero, 0x74($a2)
    MEM_W(0X74, ctx->r6) = 0;
L_800420D8:
    // 0x800420D8: jal         0x8009C3C8
    // 0x800420DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_number_of_active_players(rdram, ctx);
        goto after_1;
    // 0x800420DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800420E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800420E4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800420E8: beq         $at, $zero, L_80042100
    if (ctx->r1 == 0) {
        // 0x800420EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80042100;
    }
    // 0x800420EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800420F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800420F4: jal         0x800AFC3C
    // 0x800420F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x800420F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x800420FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80042100:
    // 0x80042100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042104: jr          $ra
    // 0x80042108: nop

    return;
    // 0x80042108: nop

;}
RECOMP_FUNC void get_racer_objects_by_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAB0: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8001BAB4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BABC: lw          $v0, -0x5118($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5118);
    // 0x8001BAC0: jr          $ra
    // 0x8001BAC4: nop

    return;
    // 0x8001BAC4: nop

;}
RECOMP_FUNC void hud_sound_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A74EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A74F0: lhu         $t7, 0x6D7C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X6D7C);
    // 0x800A74F4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A74F8: bne         $t7, $t6, L_800A7518
    if (ctx->r15 != ctx->r14) {
        // 0x800A74FC: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800A7518;
    }
    // 0x800A74FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A7500: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7504: lw          $t8, 0x6D78($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D78);
    // 0x800A7508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A750C: bne         $a1, $t8, L_800A7518
    if (ctx->r5 != ctx->r24) {
        // 0x800A7510: nop
    
            goto L_800A7518;
    }
    // 0x800A7510: nop

    // 0x800A7514: sw          $zero, 0x6D74($at)
    MEM_W(0X6D74, ctx->r1) = 0;
L_800A7518:
    // 0x800A7518: jr          $ra
    // 0x800A751C: nop

    return;
    // 0x800A751C: nop

;}
RECOMP_FUNC void mtxf_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6EC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F6F0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F6F4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006F6F8: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F6FC: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F700: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006F704: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F708: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F70C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F710: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F714: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F718: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F71C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F720: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F724: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F728: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F72C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8006F730: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F734: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F738: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F73C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F740: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F744: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F748: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F74C: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8006F750: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F754: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F758: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F75C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F760: jr          $ra
    // 0x8006F764: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
    return;
    // 0x8006F764: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
;}
RECOMP_FUNC void is_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4CC: lbu         $v0, -0x510C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X510C);
    // 0x8000E4D0: jr          $ra
    // 0x8000E4D4: nop

    return;
    // 0x8000E4D4: nop

;}
RECOMP_FUNC void func_80018CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CE0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80018CE4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80018CE8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80018CEC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80018CF0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80018CF4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80018CF8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80018CFC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80018D00: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80018D04: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80018D08: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80018D0C: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80018D10: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80018D14: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80018D18: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80018D1C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80018D20: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80018D24: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80018D28: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80018D2C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80018D30: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80018D34: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018D38: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80018D3C: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x80018D40: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80018D44: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x80018D48: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80018D4C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80018D50: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80018D54: nop

    // 0x80018D58: bne         $t3, $zero, L_80019500
    if (ctx->r11 != 0) {
        // 0x80018D5C: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019500;
    }
    // 0x80018D5C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80018D60: jal         0x80066210
    // 0x80018D64: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80018D64: nop

    after_0:
    // 0x80018D68: bne         $v0, $zero, L_800194FC
    if (ctx->r2 != 0) {
        // 0x80018D6C: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800194FC;
    }
    // 0x80018D6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80018D70: lw          $t4, -0x51A0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X51A0);
    // 0x80018D74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018D78: lw          $t5, -0x51A4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X51A4);
    // 0x80018D7C: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x80018D80: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80018D84: beq         $at, $zero, L_8001925C
    if (ctx->r1 == 0) {
        // 0x80018D88: sll         $t8, $t4, 2
        ctx->r24 = S32(ctx->r12 << 2);
            goto L_8001925C;
    }
    // 0x80018D88: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80018D8C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80018D90: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x80018D94: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x80018D98: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80018D9C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80018DA0:
    // 0x80018DA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80018DA4: lw          $t7, -0x51A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X51A8);
    // 0x80018DA8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80018DAC: nop

    // 0x80018DB0: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80018DB4: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80018DB8: nop

    // 0x80018DBC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80018DC0: nop

    // 0x80018DC4: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80018DC8: bne         $t1, $zero, L_80019238
    if (ctx->r9 != 0) {
        // 0x80018DCC: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80018DCC: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018DD0: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80018DD4: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x80018DD8: bne         $v0, $at, L_80018F9C
    if (ctx->r2 != ctx->r1) {
        // 0x80018DDC: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80018F9C;
    }
    // 0x80018DDC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80018DE0: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80018DE4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018DE8: lwc1        $f10, 0x10($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80018DEC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018DF0: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018DF4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018DF8: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018DFC: lwc1        $f6, 0x14($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80018E00: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018E04: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018E08: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018E0C: nop

    // 0x80018E10: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018E14: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018E18: jal         0x800C9AD0
    // 0x80018E1C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80018E1C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_1:
    // 0x80018E20: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80018E24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80018E28: lhu         $t2, 0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2);
    // 0x80018E2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018E30: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80018E34: bgez        $t2, L_80018E48
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80018E38: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80018E48;
    }
    // 0x80018E38: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018E3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018E40: nop

    // 0x80018E44: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80018E48:
    // 0x80018E48: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80018E4C: nop

    // 0x80018E50: bc1f        L_80019238
    if (!c1cs) {
        // 0x80018E54: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80018E54: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018E58: sw          $v1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r3;
    // 0x80018E5C: jal         0x80001918
    // 0x80018E60: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    music_current_sequence(rdram, ctx);
        goto after_2;
    // 0x80018E60: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80018E64: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80018E68: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80018E6C: lbu         $t3, 0x1C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1C);
    // 0x80018E70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018E74: bne         $t3, $v0, L_80019234
    if (ctx->r11 != ctx->r2) {
        // 0x80018E78: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_80019234;
    }
    // 0x80018E78: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80018E7C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80018E80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018E84: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80018E88: bgez        $v0, L_80018E9C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018E8C: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80018E9C;
    }
    // 0x80018E8C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018E94: nop

    // 0x80018E98: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_80018E9C:
    // 0x80018E9C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80018EA0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80018EA4: bc1f        L_80018EB4
    if (!c1cs) {
        // 0x80018EA8: nop
    
            goto L_80018EB4;
    }
    // 0x80018EA8: nop

    // 0x80018EAC: b           L_80018F00
    // 0x80018EB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80018F00;
    // 0x80018EB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80018EB4:
    // 0x80018EB4: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x80018EB8: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80018EBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018EC0: subu        $t4, $t5, $v0
    ctx->r12 = SUB32(ctx->r13, ctx->r2);
    // 0x80018EC4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80018EC8: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018ECC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80018ED0: nop

    // 0x80018ED4: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018ED8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80018EDC: nop

    // 0x80018EE0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80018EE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018EE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018EEC: nop

    // 0x80018EF0: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80018EF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80018EF8: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80018EFC: nop

L_80018F00:
    // 0x80018F00: lbu         $v0, 0xC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XC);
    // 0x80018F04: slti        $at, $s2, 0x7B
    ctx->r1 = SIGNED(ctx->r18) < 0X7B ? 1 : 0;
    // 0x80018F08: beq         $v0, $s5, L_80018F20
    if (ctx->r2 == ctx->r21) {
        // 0x80018F0C: nop
    
            goto L_80018F20;
    }
    // 0x80018F0C: nop

    // 0x80018F10: beq         $v0, $s6, L_80018F5C
    if (ctx->r2 == ctx->r22) {
        // 0x80018F14: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F5C;
    }
    // 0x80018F14: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F18: b           L_80018F88
    // 0x80018F1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018F88;
    // 0x80018F1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F20:
    // 0x80018F20: bne         $at, $zero, L_80018F38
    if (ctx->r1 != 0) {
        // 0x80018F24: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F38;
    }
    // 0x80018F24: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F28: jal         0x80001114
    // 0x80018F2C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_3;
    // 0x80018F2C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x80018F30: b           L_80018F88
    // 0x80018F34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018F88;
    // 0x80018F34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F38:
    // 0x80018F38: subu        $a1, $fp, $s2
    ctx->r5 = SUB32(ctx->r30, ctx->r18);
    // 0x80018F3C: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80018F40: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80018F44: jal         0x80001268
    // 0x80018F48: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x80018F48: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x80018F4C: jal         0x80001170
    // 0x80018F50: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_5;
    // 0x80018F50: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x80018F54: b           L_80018F88
    // 0x80018F58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018F88;
    // 0x80018F58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F5C:
    // 0x80018F5C: jal         0x800012A8
    // 0x80018F60: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_6;
    // 0x80018F60: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_6:
    // 0x80018F64: blez        $v0, L_80018F84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80018F68: nop
    
            goto L_80018F84;
    }
    // 0x80018F68: nop

    // 0x80018F6C: jal         0x8000114C
    // 0x80018F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    music_channel_active(rdram, ctx);
        goto after_7;
    // 0x80018F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80018F74: bne         $v0, $zero, L_80018F84
    if (ctx->r2 != 0) {
        // 0x80018F78: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80018F84;
    }
    // 0x80018F78: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80018F7C: jal         0x80001268
    // 0x80018F80: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x80018F80: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_8:
L_80018F84:
    // 0x80018F84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F88:
    // 0x80018F88: bne         $s1, $s7, L_80018F00
    if (ctx->r17 != ctx->r23) {
        // 0x80018F8C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80018F00;
    }
    // 0x80018F8C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018F90: b           L_80019238
    // 0x80018F94: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
        goto L_80019238;
    // 0x80018F94: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018F98: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
L_80018F9C:
    // 0x80018F9C: bne         $v0, $at, L_80019184
    if (ctx->r2 != ctx->r1) {
        // 0x80018FA0: addiu       $at, $zero, 0x76
        ctx->r1 = ADD32(0, 0X76);
            goto L_80019184;
    }
    // 0x80018FA0: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
    // 0x80018FA4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80018FA8: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80018FAC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018FB0: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80018FB4: mul.s       $f30, $f16, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80018FB8: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018FBC: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80018FC0: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80018FC4: mul.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018FC8: lwc1        $f24, 0xC($s4)
    ctx->f24.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80018FCC: lwc1        $f26, 0x10($s4)
    ctx->f26.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80018FD0: lwc1        $f20, 0x14($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018FD4: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80018FD8: lwc1        $f28, 0x14($s4)
    ctx->f28.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80018FDC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x80018FE0: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x80018FE4: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x80018FE8: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80018FEC: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80018FF0: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80018FF4: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80018FF8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018FFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80019000: nop

    // 0x80019004: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80019008: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001900C: bc1f        L_80019034
    if (!c1cs) {
        // 0x80019010: add.s       $f2, $f10, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
            goto L_80019034;
    }
    // 0x80019010: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80019014: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80019018: sll         $v1, $s5, 24
    ctx->r3 = S32(ctx->r21 << 24);
    // 0x8001901C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80019020: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80019024: bc1f        L_80019034
    if (!c1cs) {
        // 0x80019028: nop
    
            goto L_80019034;
    }
    // 0x80019028: nop

    // 0x8001902C: b           L_8001906C
    // 0x80019030: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_8001906C;
    // 0x80019030: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80019034:
    // 0x80019034: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019038: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001903C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80019040: nop

    // 0x80019044: bc1f        L_8001906C
    if (!c1cs) {
        // 0x80019048: nop
    
            goto L_8001906C;
    }
    // 0x80019048: nop

    // 0x8001904C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80019050: nop

    // 0x80019054: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80019058: nop

    // 0x8001905C: bc1f        L_8001906C
    if (!c1cs) {
        // 0x80019060: nop
    
            goto L_8001906C;
    }
    // 0x80019060: nop

    // 0x80019064: b           L_8001906C
    // 0x80019068: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8001906C;
    // 0x80019068: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001906C:
    // 0x8001906C: beq         $v1, $zero, L_80019238
    if (ctx->r3 == 0) {
        // 0x80019070: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019070: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019074: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80019078: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x8001907C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80019080: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80019084: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80019088: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x8001908C: sub.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x80019090: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80019094: sub.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x80019098: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8001909C: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800190A0: sub.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800190A4: sub.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800190A8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800190AC: sub.s       $f14, $f28, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800190B0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800190B4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190B8: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800190BC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190C0: nop

    // 0x800190C4: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800190C8: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800190CC: mul.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800190D0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800190D4: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x800190D8: nop

    // 0x800190DC: bc1f        L_80019238
    if (!c1cs) {
        // 0x800190E0: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x800190E0: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800190E4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800190E8: nop

    // 0x800190EC: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x800190F0: nop

    // 0x800190F4: bc1f        L_80019238
    if (!c1cs) {
        // 0x800190F8: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x800190F8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800190FC: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80019100: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019104: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019108: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001910C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80019110: nop

    // 0x80019114: bc1f        L_80019238
    if (!c1cs) {
        // 0x80019118: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019118: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001911C: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80019120: nop

    // 0x80019124: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80019128: nop

    // 0x8001912C: bc1f        L_80019238
    if (!c1cs) {
        // 0x80019130: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019130: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019134: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x80019138: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001913C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019140: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019144: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80019148: nop

    // 0x8001914C: bc1f        L_80019238
    if (!c1cs) {
        // 0x80019150: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019150: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019154: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80019158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001915C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80019160: nop

    // 0x80019164: bc1f        L_80019238
    if (!c1cs) {
        // 0x80019168: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019168: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001916C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80019170: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80019174: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80019178: b           L_80019234
    // 0x8001917C: sw          $v0, -0x50A0($at)
    MEM_W(-0X50A0, ctx->r1) = ctx->r2;
        goto L_80019234;
    // 0x8001917C: sw          $v0, -0x50A0($at)
    MEM_W(-0X50A0, ctx->r1) = ctx->r2;
    // 0x80019180: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
L_80019184:
    // 0x80019184: bne         $v0, $at, L_80019238
    if (ctx->r2 != ctx->r1) {
        // 0x80019188: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019188: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001918C: lwc1        $f4, 0xC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80019190: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80019194: lwc1        $f8, 0x10($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80019198: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001919C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191A0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800191A4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800191A8: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800191AC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800191B0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191B4: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800191B8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800191BC: nop

    // 0x800191C0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800191C4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800191C8: jal         0x800C9AD0
    // 0x800191CC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x800191CC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x800191D0: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800191D4: nop

    // 0x800191D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800191DC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800191E0: nop

    // 0x800191E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800191E8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800191EC: nop

    // 0x800191F0: bc1f        L_80019238
    if (!c1cs) {
        // 0x800191F4: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x800191F4: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800191F8: jal         0x8000105C
    // 0x800191FC: nop

    music_channel_get_mask(rdram, ctx);
        goto after_10;
    // 0x800191FC: nop

    after_10:
    // 0x80019200: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x80019204: nop

    // 0x80019208: beq         $t0, $v0, L_80019238
    if (ctx->r8 == ctx->r2) {
        // 0x8001920C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x8001920C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019210: jal         0x80001918
    // 0x80019214: nop

    music_current_sequence(rdram, ctx);
        goto after_11;
    // 0x80019214: nop

    after_11:
    // 0x80019218: lbu         $t1, 0x3($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3);
    // 0x8001921C: nop

    // 0x80019220: bne         $t1, $v0, L_80019238
    if (ctx->r9 != ctx->r2) {
        // 0x80019224: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_80019238;
    }
    // 0x80019224: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019228: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x8001922C: jal         0x80001074
    // 0x80019230: nop

    music_dynamic_set(rdram, ctx);
        goto after_12;
    // 0x80019230: nop

    after_12:
L_80019234:
    // 0x80019234: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
L_80019238:
    // 0x80019238: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001923C: lw          $t8, -0x51A4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X51A4);
    // 0x80019240: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80019244: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80019248: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001924C: addiu       $t4, $t5, 0x4
    ctx->r12 = ADD32(ctx->r13, 0X4);
    // 0x80019250: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x80019254: bne         $at, $zero, L_80018DA0
    if (ctx->r1 != 0) {
        // 0x80019258: sw          $t3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r11;
            goto L_80018DA0;
    }
    // 0x80019258: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
L_8001925C:
    // 0x8001925C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80019260: lw          $t7, -0x50A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X50A0);
    // 0x80019264: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80019268: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8001926C: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x80019270: beq         $t7, $zero, L_800194FC
    if (ctx->r15 == 0) {
        // 0x80019274: addiu       $fp, $zero, 0x7F
        ctx->r30 = ADD32(0, 0X7F);
            goto L_800194FC;
    }
    // 0x80019274: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x80019278: jal         0x80001918
    // 0x8001927C: nop

    music_current_sequence(rdram, ctx);
        goto after_13;
    // 0x8001927C: nop

    after_13:
    // 0x80019280: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019284: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x80019288: lw          $t0, 0x110($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X110);
    // 0x8001928C: lbu         $t6, 0x40($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X40);
    // 0x80019290: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80019294: bne         $t6, $v0, L_800194C4
    if (ctx->r14 != ctx->r2) {
        // 0x80019298: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800194C4;
    }
    // 0x80019298: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x8001929C: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x800192A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800192A4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800192A8: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800192AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192B0: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x800192B4: lw          $t5, 0x6170($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6170);
    // 0x800192B8: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x800192BC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800192C0: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800192C4: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x800192C8: mflo        $a0
    ctx->r4 = lo;
    // 0x800192CC: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800192D0: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800192D4: beq         $at, $zero, L_800192F4
    if (ctx->r1 == 0) {
        // 0x800192D8: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800192F4;
    }
    // 0x800192D8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800192DC: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x800192E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192E4: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x800192E8: nop

    // 0x800192EC: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800192F0: nop

L_800192F4:
    // 0x800192F4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800192F8: bgez        $v0, L_80019310
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800192FC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80019310;
    }
    // 0x800192FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019300: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019308: nop

    // 0x8001930C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80019310:
    // 0x80019310: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x80019314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019318: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x8001931C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019320: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019324: bgez        $a0, L_80019338
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80019328: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80019338;
    }
    // 0x80019328: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001932C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019330: nop

    // 0x80019334: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80019338:
    // 0x80019338: nop

    // 0x8001933C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019340: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80019344: nop

    // 0x80019348: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8001934C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019350: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019354: nop

    // 0x80019358: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001935C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80019360: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80019364: slti        $at, $a1, 0xFE
    ctx->r1 = SIGNED(ctx->r5) < 0XFE ? 1 : 0;
    // 0x80019368: beq         $at, $zero, L_80019378
    if (ctx->r1 == 0) {
        // 0x8001936C: nop
    
            goto L_80019378;
    }
    // 0x8001936C: nop

    // 0x80019370: b           L_8001937C
    // 0x80019374: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
        goto L_8001937C;
    // 0x80019374: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
L_80019378:
    // 0x80019378: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
L_8001937C:
    // 0x8001937C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019380: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x80019384: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_80019388:
    // 0x80019388: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8001938C: addu        $t7, $v1, $s1
    ctx->r15 = ADD32(ctx->r3, ctx->r17);
    // 0x80019390: lb          $v0, 0x30($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X30);
    // 0x80019394: bne         $s3, $t6, L_800193A4
    if (ctx->r19 != ctx->r14) {
        // 0x80019398: sra         $t9, $v0, 2
        ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
            goto L_800193A4;
    }
    // 0x80019398: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8001939C: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800193A0: sra         $v0, $t0, 24
    ctx->r2 = S32(SIGNED(ctx->r8) >> 24);
L_800193A4:
    // 0x800193A4: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x800193A8: sll         $t5, $t2, 24
    ctx->r13 = S32(ctx->r10 << 24);
    // 0x800193AC: sra         $t4, $t5, 24
    ctx->r12 = S32(SIGNED(ctx->r13) >> 24);
    // 0x800193B0: beq         $t4, $zero, L_800193FC
    if (ctx->r12 == 0) {
        // 0x800193B4: nop
    
            goto L_800193FC;
    }
    // 0x800193B4: nop

    // 0x800193B8: beq         $t4, $s5, L_800193D8
    if (ctx->r12 == ctx->r21) {
        // 0x800193BC: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_800193D8;
    }
    // 0x800193BC: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800193C0: beq         $t4, $s6, L_80019464
    if (ctx->r12 == ctx->r22) {
        // 0x800193C4: nop
    
            goto L_80019464;
    }
    // 0x800193C4: nop

    // 0x800193C8: beq         $t4, $s4, L_80019414
    if (ctx->r12 == ctx->r20) {
        // 0x800193CC: nop
    
            goto L_80019414;
    }
    // 0x800193CC: nop

    // 0x800193D0: b           L_800194BC
    // 0x800193D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194BC;
    // 0x800193D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800193D8:
    // 0x800193D8: jal         0x80001170
    // 0x800193DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_14;
    // 0x800193DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_14:
    // 0x800193E0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800193E4: jal         0x80001268
    // 0x800193E8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_15;
    // 0x800193E8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_15:
    // 0x800193EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800193F0: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x800193F4: b           L_800194BC
    // 0x800193F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194BC;
    // 0x800193F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800193FC:
    // 0x800193FC: jal         0x80001114
    // 0x80019400: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_16;
    // 0x80019400: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_16:
    // 0x80019404: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019408: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x8001940C: b           L_800194BC
    // 0x80019410: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194BC;
    // 0x80019410: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019414:
    // 0x80019414: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80019418: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x8001941C: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80019420: bne         $at, $zero, L_80019454
    if (ctx->r1 != 0) {
        // 0x80019424: addiu       $s2, $v0, -0x7F
        ctx->r18 = ADD32(ctx->r2, -0X7F);
            goto L_80019454;
    }
    // 0x80019424: addiu       $s2, $v0, -0x7F
    ctx->r18 = ADD32(ctx->r2, -0X7F);
    // 0x80019428: andi        $t3, $s2, 0xFF
    ctx->r11 = ctx->r18 & 0XFF;
    // 0x8001942C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80019430: jal         0x80001170
    // 0x80019434: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_17;
    // 0x80019434: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_17:
    // 0x80019438: jal         0x800012A8
    // 0x8001943C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_18;
    // 0x8001943C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_18:
    // 0x80019440: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80019444: beq         $at, $zero, L_80019454
    if (ctx->r1 == 0) {
        // 0x80019448: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80019454;
    }
    // 0x80019448: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8001944C: jal         0x80001268
    // 0x80019450: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_19;
    // 0x80019450: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_19:
L_80019454:
    // 0x80019454: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019458: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x8001945C: b           L_800194BC
    // 0x80019460: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194BC;
    // 0x80019460: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019464:
    // 0x80019464: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80019468: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x8001946C: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80019470: beq         $at, $zero, L_800194A4
    if (ctx->r1 == 0) {
        // 0x80019474: subu        $s2, $fp, $v0
        ctx->r18 = SUB32(ctx->r30, ctx->r2);
            goto L_800194A4;
    }
    // 0x80019474: subu        $s2, $fp, $v0
    ctx->r18 = SUB32(ctx->r30, ctx->r2);
    // 0x80019478: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x8001947C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x80019480: jal         0x800012A8
    // 0x80019484: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_20;
    // 0x80019484: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_20:
    // 0x80019488: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001948C: beq         $at, $zero, L_800194AC
    if (ctx->r1 == 0) {
        // 0x80019490: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800194AC;
    }
    // 0x80019490: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80019494: jal         0x80001268
    // 0x80019498: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_21;
    // 0x80019498: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_21:
    // 0x8001949C: b           L_800194AC
    // 0x800194A0: nop

        goto L_800194AC;
    // 0x800194A0: nop

L_800194A4:
    // 0x800194A4: jal         0x80001114
    // 0x800194A8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_22;
    // 0x800194A8: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_22:
L_800194AC:
    // 0x800194AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800194B0: lw          $v1, -0x50A0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X50A0);
    // 0x800194B4: nop

    // 0x800194B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800194BC:
    // 0x800194BC: bne         $s1, $s7, L_80019388
    if (ctx->r17 != ctx->r23) {
        // 0x800194C0: nop
    
            goto L_80019388;
    }
    // 0x800194C0: nop

L_800194C4:
    // 0x800194C4: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x800194C8: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x800194CC: bne         $t7, $at, L_80019500
    if (ctx->r15 != ctx->r1) {
        // 0x800194D0: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019500;
    }
    // 0x800194D0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800194D4: jal         0x80001918
    // 0x800194D8: nop

    music_current_sequence(rdram, ctx);
        goto after_23;
    // 0x800194D8: nop

    after_23:
    // 0x800194DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800194E0: lw          $t6, -0x50A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50A0);
    // 0x800194E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800194E8: lbu         $t9, 0x40($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X40);
    // 0x800194EC: nop

    // 0x800194F0: bne         $t9, $v0, L_80019500
    if (ctx->r25 != ctx->r2) {
        // 0x800194F4: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019500;
    }
    // 0x800194F4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800194F8: sw          $zero, -0x50A0($at)
    MEM_W(-0X50A0, ctx->r1) = 0;
L_800194FC:
    // 0x800194FC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80019500:
    // 0x80019500: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80019504: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80019508: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001950C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019510: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80019514: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80019518: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001951C: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80019520: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80019524: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80019528: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8001952C: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80019530: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80019534: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80019538: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8001953C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80019540: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80019544: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80019548: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8001954C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80019550: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80019554: jr          $ra
    // 0x80019558: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80019558: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void osScAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007948C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80079490: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80079494: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80079498: jal         0x800C9A30
    // 0x8007949C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8007949C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800794A0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800794A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800794A8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800794AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800794B0: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x800794B4: lw          $t7, 0x260($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X260);
    // 0x800794B8: nop

    // 0x800794BC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800794C0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800794C4: nop

    // 0x800794C8: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x800794CC: jal         0x800C9A30
    // 0x800794D0: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800794D0: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    after_1:
    // 0x800794D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800794D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800794DC: jr          $ra
    // 0x800794E0: nop

    return;
    // 0x800794E0: nop

;}
RECOMP_FUNC void debug_print_float_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A03C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A040: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006A044: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A048: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006A04C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006A050: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006A054: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A058: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8006A05C: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8006A060: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006A064: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A068: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A06C: addiu       $s6, $s6, 0x7094
    ctx->r22 = ADD32(ctx->r22, 0X7094);
    // 0x8006A070: addiu       $s2, $s2, 0x708C
    ctx->r18 = ADD32(ctx->r18, 0X708C);
    // 0x8006A074: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8006A078: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8006A07C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8006A080: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_8006A084:
    // 0x8006A084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A088: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_8006A08C:
    // 0x8006A08C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006A090: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006A094: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8006A098: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8006A09C: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8006A0A0: jal         0x800C9D54
    // 0x8006A0A4: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A0A4: nop

    after_0:
    // 0x8006A0A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006A0AC: bne         $s0, $s3, L_8006A08C
    if (ctx->r16 != ctx->r19) {
        // 0x8006A0B0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A08C;
    }
    // 0x8006A0B0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A0B4: jal         0x800C9D54
    // 0x8006A0B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A0B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8006A0BC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8006A0C0: bne         $s4, $s7, L_8006A084
    if (ctx->r20 != ctx->r23) {
        // 0x8006A0C4: addiu       $s5, $s5, 0x10
        ctx->r21 = ADD32(ctx->r21, 0X10);
            goto L_8006A084;
    }
    // 0x8006A0C4: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8006A0C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A0CC: jal         0x800C9D54
    // 0x8006A0D0: addiu       $a0, $a0, 0x7098
    ctx->r4 = ADD32(ctx->r4, 0X7098);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A0D0: addiu       $a0, $a0, 0x7098
    ctx->r4 = ADD32(ctx->r4, 0X7098);
    after_2:
    // 0x8006A0D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006A0D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A0DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A0E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A0E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006A0E8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006A0EC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006A0F0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A0F4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006A0F8: jr          $ra
    // 0x8006A0FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A0FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void credits_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BCF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009BCF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009BCF8: jal         0x80000BE0
    // 0x8009BCFC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x8009BCFC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8009BD00: jal         0x800C0180
    // 0x8009BD04: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_1;
    // 0x8009BD04: nop

    after_1:
    // 0x8009BD08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009BD0C: jal         0x80066894
    // 0x8009BD10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x8009BD10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009BD14: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8009BD18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009BD1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009BD20: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009BD24: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009BD28: jal         0x80066AA8
    // 0x8009BD2C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009BD2C: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x8009BD30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BD34: jal         0x8009C4A8
    // 0x8009BD38: addiu       $a0, $a0, 0x17D8
    ctx->r4 = ADD32(ctx->r4, 0X17D8);
    menu_assetgroup_free(rdram, ctx);
        goto after_4;
    // 0x8009BD38: addiu       $a0, $a0, 0x17D8
    ctx->r4 = ADD32(ctx->r4, 0X17D8);
    after_4:
    // 0x8009BD3C: jal         0x800C422C
    // 0x8009BD40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_5;
    // 0x8009BD40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8009BD44: jal         0x8006F564
    // 0x8009BD48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_gIntDisFlag(rdram, ctx);
        goto after_6;
    // 0x8009BD48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009BD4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009BD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009BD54: jr          $ra
    // 0x8009BD58: nop

    return;
    // 0x8009BD58: nop

;}
RECOMP_FUNC void bgload_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 6U, dkr_legacy_fields, 0U); }
    // 0x800C7458: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C745C: addiu       $v1, $v1, 0x3770
    ctx->r3 = ADD32(ctx->r3, 0X3770);
    // 0x800C7460: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C7464: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800C7468: bne         $t6, $zero, L_800C7494
    if (ctx->r14 != 0) {
        // 0x800C746C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800C7494;
    }
    // 0x800C746C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7470: sw          $t7, 0x377C($at)
    MEM_W(0X377C, ctx->r1) = ctx->r15;
    // 0x800C7474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7478: sw          $a0, 0x3774($at)
    MEM_W(0X3774, ctx->r1) = ctx->r4;
    // 0x800C747C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7480: sw          $a1, 0x3778($at)
    MEM_W(0X3778, ctx->r1) = ctx->r5;
    // 0x800C7484: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C7488: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 7U, dkr_legacy_fields, 1U); }
    // 0x800C748C: jr          $ra
    // 0x800C7490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C7490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C7494:
    // 0x800C7494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 7U, dkr_legacy_fields, 0U); }
    // 0x800C7498: jr          $ra
    // 0x800C749C: nop

    return;
    // 0x800C749C: nop

;}
RECOMP_FUNC void get_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DA10: lw          $v0, 0x34EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34EC);
    // 0x8006DA14: jr          $ra
    // 0x8006DA18: nop

    return;
    // 0x8006DA18: nop

;}
RECOMP_FUNC void obj_loop_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DF10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DF14: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DF18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003DF1C: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x8003DF20: nop

    // 0x8003DF24: slti        $at, $t6, 0x32
    ctx->r1 = SIGNED(ctx->r14) < 0X32 ? 1 : 0;
    // 0x8003DF28: beq         $at, $zero, L_8003DFAC
    if (ctx->r1 == 0) {
        // 0x8003DF2C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFAC;
    }
    // 0x8003DF2C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003DF34: nop

    // 0x8003DF38: beq         $v0, $zero, L_8003DFAC
    if (ctx->r2 == 0) {
        // 0x8003DF3C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFAC;
    }
    // 0x8003DF3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF40: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x8003DF44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DF48: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DF4C: nop

    // 0x8003DF50: bne         $t8, $at, L_8003DFAC
    if (ctx->r24 != ctx->r1) {
        // 0x8003DF54: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFAC;
    }
    // 0x8003DF54: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF58: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003DF5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DF60: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8003DF64: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8003DF68: beq         $t9, $at, L_8003DFAC
    if (ctx->r25 == ctx->r1) {
        // 0x8003DF6C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFAC;
    }
    // 0x8003DF6C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF70: jal         0x80001BC0
    // 0x8003DF74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    music_jingle_play(rdram, ctx);
        goto after_0;
    // 0x8003DF74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003DF78: jal         0x8006EA90
    // 0x8003DF7C: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8003DF7C: nop

    after_1:
    // 0x8003DF80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DF84: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x8003DF88: lw          $t1, 0x78($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X78);
    // 0x8003DF8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DF90: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003DF94: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8003DF98: jal         0x8000FFB8
    // 0x8003DF9C: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DF9C: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    after_2:
    // 0x8003DFA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFA4: nop

    // 0x8003DFA8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_8003DFAC:
    // 0x8003DFAC: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x8003DFB0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8003DFB4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8003DFB8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8003DFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DFC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DFC4: jr          $ra
    // 0x8003DFC8: nop

    return;
    // 0x8003DFC8: nop

;}
RECOMP_FUNC void sprite_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AE68: lw          $v0, 0x6354($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6354);
    // 0x8007AE6C: jr          $ra
    // 0x8007AE70: nop

    return;
    // 0x8007AE70: nop

;}
RECOMP_FUNC void set_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F90C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F910: jr          $ra
    // 0x8006F914: sw          $a0, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->r4;
    return;
    // 0x8006F914: sw          $a0, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void racer_attack_handler_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053E9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80053EA8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80053EAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80053EB0: bne         $t6, $at, L_80053EC0
    if (ctx->r14 != ctx->r1) {
        // 0x80053EB4: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80053EC0;
    }
    // 0x80053EB4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80053EB8: b           L_80053ECC
    // 0x80053EBC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
        goto L_80053ECC;
    // 0x80053EBC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
L_80053EC0:
    // 0x80053EC0: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x80053EC4: nop

    // 0x80053EC8: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
L_80053ECC:
    // 0x80053ECC: lb          $v0, 0x1ED($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053ED0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053ED4: blez        $v0, L_80053F20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80053ED8: subu        $t8, $v0, $a2
        ctx->r24 = SUB32(ctx->r2, ctx->r6);
            goto L_80053F20;
    }
    // 0x80053ED8: subu        $t8, $v0, $a2
    ctx->r24 = SUB32(ctx->r2, ctx->r6);
    // 0x80053EDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80053EE0: sb          $t8, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r24;
    // 0x80053EE4: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x80053EE8: lwc1        $f6, 0x67A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67A0);
    // 0x80053EEC: lb          $t9, 0x1ED($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053EF0: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
    // 0x80053EF4: bgtz        $t9, L_80053F24
    if (SIGNED(ctx->r25) > 0) {
        // 0x80053EF8: nop
    
            goto L_80053F24;
    }
    // 0x80053EF8: nop

    // 0x80053EFC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80053F00: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x80053F04: bltz        $t0, L_80053F24
    if (SIGNED(ctx->r8) < 0) {
        // 0x80053F08: nop
    
            goto L_80053F24;
    }
    // 0x80053F08: nop

    // 0x80053F0C: jal         0x80057048
    // 0x80053F10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    racer_play_sound(rdram, ctx);
        goto after_0;
    // 0x80053F10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80053F14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053F18: b           L_80053F28
    // 0x80053F1C: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
        goto L_80053F28;
    // 0x80053F1C: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
L_80053F20:
    // 0x80053F20: sb          $zero, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = 0;
L_80053F24:
    // 0x80053F24: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
L_80053F28:
    // 0x80053F28: nop

    // 0x80053F2C: beq         $v0, $zero, L_80053F44
    if (ctx->r2 == 0) {
        // 0x80053F30: nop
    
            goto L_80053F44;
    }
    // 0x80053F30: nop

    // 0x80053F34: lh          $t1, 0x18E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X18E);
    // 0x80053F38: nop

    // 0x80053F3C: blez        $t1, L_80053F4C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80053F40: nop
    
            goto L_80053F4C;
    }
    // 0x80053F40: nop

L_80053F44:
    // 0x80053F44: b           L_80054100
    // 0x80053F48: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80054100;
    // 0x80053F48: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80053F4C:
    // 0x80053F4C: lb          $t2, 0x1ED($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053F50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053F54: beq         $t2, $zero, L_80053F60
    if (ctx->r10 == 0) {
        // 0x80053F58: nop
    
            goto L_80053F60;
    }
    // 0x80053F58: nop

    // 0x80053F5C: beq         $v0, $at, L_80054100
    if (ctx->r2 == ctx->r1) {
        // 0x80053F60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80054100;
    }
L_80053F60:
    // 0x80053F60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053F64: beq         $v0, $at, L_80053F88
    if (ctx->r2 == ctx->r1) {
        // 0x80053F68: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80053F88;
    }
    // 0x80053F68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053F6C: beq         $v0, $at, L_80053F88
    if (ctx->r2 == ctx->r1) {
        // 0x80053F70: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80053F88;
    }
    // 0x80053F70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80053F74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80053F78: jal         0x800576E0
    // 0x80053F7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_1;
    // 0x80053F7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80053F80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053F84: nop

L_80053F88:
    // 0x80053F88: lbu         $t4, 0x1C9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1C9);
    // 0x80053F8C: addiu       $t3, $zero, 0x168
    ctx->r11 = ADD32(0, 0X168);
    // 0x80053F90: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053F94: bne         $t4, $at, L_80053FA0
    if (ctx->r12 != ctx->r1) {
        // 0x80053F98: sh          $t3, 0x18C($s0)
        MEM_H(0X18C, ctx->r16) = ctx->r11;
            goto L_80053FA0;
    }
    // 0x80053F98: sh          $t3, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r11;
    // 0x80053F9C: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
L_80053FA0:
    // 0x80053FA0: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x80053FA4: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80053FA8: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80053FAC: beq         $at, $zero, L_80054100
    if (ctx->r1 == 0) {
        // 0x80053FB0: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_80054100;
    }
    // 0x80053FB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80053FB4: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80053FB8: jal         0x800570B8
    // 0x80053FBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_2;
    // 0x80053FBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80053FC0: lb          $t6, 0x187($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X187);
    // 0x80053FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053FC8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80053FCC: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80053FD0: beq         $at, $zero, L_800540FC
    if (ctx->r1 == 0) {
        // 0x80053FD4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800540FC;
    }
    // 0x80053FD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80053FD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053FDC: addu        $at, $at, $t7
    gpr jr_addend_80053FE8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80053FE0: lw          $t7, 0x67A4($at)
    ctx->r15 = ADD32(ctx->r1, 0X67A4);
    // 0x80053FE4: nop

    // 0x80053FE8: jr          $t7
    // 0x80053FEC: nop

    switch (jr_addend_80053FE8 >> 2) {
        case 0: goto L_80053FF0; break;
        case 1: goto L_8005406C; break;
        case 2: goto L_800540FC; break;
        case 3: goto L_8005408C; break;
        case 4: goto L_800540C4; break;
        case 5: goto L_80054098; break;
        default: switch_error(__func__, 0x80053FE8, 0x800E67A4);
    }
    // 0x80053FEC: nop

L_80053FF0:
    // 0x80053FF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80053FF4: sb          $t8, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r24;
    // 0x80053FF8: lb          $t9, 0x27($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X27);
    // 0x80053FFC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054000: bne         $t9, $zero, L_80054034
    if (ctx->r25 != 0) {
        // 0x80054004: nop
    
            goto L_80054034;
    }
    // 0x80054004: nop

    // 0x80054008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005400C: lui         $at, 0x4025
    ctx->r1 = S32(0X4025 << 16);
    // 0x80054010: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80054014: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80054018: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005401C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054020: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80054024: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80054028: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005402C: b           L_800540FC
    // 0x80054030: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
        goto L_800540FC;
    // 0x80054030: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
L_80054034:
    // 0x80054034: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80054038: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005403C: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80054040: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80054044: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80054048: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005404C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80054050: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80054054: nop

    // 0x80054058: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005405C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80054060: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80054064: b           L_800540FC
    // 0x80054068: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
        goto L_800540FC;
    // 0x80054068: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
L_8005406C:
    // 0x8005406C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80054070: addiu       $t1, $zero, 0x1002
    ctx->r9 = ADD32(0, 0X1002);
    // 0x80054074: sb          $t0, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r8;
    // 0x80054078: sh          $t1, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r9;
    // 0x8005407C: jal         0x80057048
    // 0x80054080: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    racer_play_sound(rdram, ctx);
        goto after_3;
    // 0x80054080: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    after_3:
    // 0x80054084: b           L_80054100
    // 0x80054088: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80054100;
    // 0x80054088: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8005408C:
    // 0x8005408C: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80054090: b           L_800540FC
    // 0x80054094: sb          $t2, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r10;
        goto L_800540FC;
    // 0x80054094: sb          $t2, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r10;
L_80054098:
    // 0x80054098: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005409C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800540A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800540A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800540A8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800540AC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800540B0: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x800540B4: sh          $t3, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r11;
    // 0x800540B8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800540BC: b           L_800540FC
    // 0x800540C0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_800540FC;
    // 0x800540C0: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_800540C4:
    // 0x800540C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800540C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800540CC: sb          $t4, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r12;
    // 0x800540D0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x800540D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800540D8: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800540DC: lwc1        $f5, 0x67C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X67C0);
    // 0x800540E0: lwc1        $f4, 0x67C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67C4);
    // 0x800540E4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800540E8: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800540EC: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    // 0x800540F0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800540F4: jal         0x80057048
    // 0x800540F8: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    racer_play_sound(rdram, ctx);
        goto after_4;
    // 0x800540F8: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    after_4:
L_800540FC:
    // 0x800540FC: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80054100:
    // 0x80054100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054108: jr          $ra
    // 0x8005410C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005410C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_level_segment_waves(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B0F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002B0F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B0FC: sb          $zero, -0x2CF8($at)
    MEM_B(-0X2CF8, ctx->r1) = 0;
    // 0x8002B100: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002B104: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002B108: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002B10C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B110: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8002B114: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B118: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002B11C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8002B120: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8002B124: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002B128: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002B12C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002B130: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002B134: mfc1        $s6, $f4
    ctx->r22 = (int32_t)ctx->f4.u32l;
    // 0x8002B138: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002B13C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B140: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B144: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002B148: cvt.w.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8002B14C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002B150: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x8002B154: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002B158: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002B15C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002B160: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002B164: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002B168: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002B16C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002B170: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002B174: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002B178: sw          $a3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r7;
    // 0x8002B17C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002B180: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8002B184: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x8002B188: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B18C: jal         0x8002A05C
    // 0x8002B190: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    get_inside_segment_count_xz(rdram, ctx);
        goto after_0;
    // 0x8002B190: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8002B194: beq         $v0, $zero, L_8002B1A8
    if (ctx->r2 == 0) {
        // 0x8002B198: sw          $v0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r2;
            goto L_8002B1A8;
    }
    // 0x8002B198: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    // 0x8002B19C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002B1A0: bne         $at, $zero, L_8002B1B0
    if (ctx->r1 != 0) {
        // 0x8002B1A4: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002B1B0;
    }
    // 0x8002B1A4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002B1A8:
    // 0x8002B1A8: b           L_8002B97C
    // 0x8002B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002B97C;
    // 0x8002B1AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B1B0:
    // 0x8002B1B0: blez        $v0, L_8002B688
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002B1B4: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8002B688;
    }
    // 0x8002B1B4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002B1B8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002B1BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B1C0: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x8002B1C4: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002B1C8: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
L_8002B1CC:
    // 0x8002B1CC: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x8002B1D0: lw          $t1, 0xB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XB0);
    // 0x8002B1D4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B1D8: lw          $t3, -0x36E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X36E8);
    // 0x8002B1DC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8002B1E0: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x8002B1E4: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x8002B1E8: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x8002B1EC: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x8002B1F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B1F4: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8002B1F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B1FC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8002B200: addu        $ra, $t6, $t7
    ctx->r31 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B204: lh          $t6, 0x6($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X6);
    // 0x8002B208: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x8002B20C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002B210: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B214: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B218: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B21C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B220: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B224: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B228: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B22C: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B230: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002B238: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B23C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B240: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B244: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002B248:
    // 0x8002B248: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002B24C: bne         $at, $zero, L_8002B26C
    if (ctx->r1 != 0) {
        // 0x8002B250: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B26C;
    }
    // 0x8002B250: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B254: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B258: bne         $at, $zero, L_8002B270
    if (ctx->r1 != 0) {
        // 0x8002B25C: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B270;
    }
    // 0x8002B25C: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B260: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B264: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B268: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B26C:
    // 0x8002B26C: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B270:
    // 0x8002B270: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B274: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B278: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B27C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B280: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8002B284: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B288: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B28C: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B290: bne         $at, $zero, L_8002B248
    if (ctx->r1 != 0) {
        // 0x8002B294: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B248;
    }
    // 0x8002B294: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B298: lh          $t0, 0x4($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X4);
    // 0x8002B29C: lh          $t6, 0xA($t2)
    ctx->r14 = MEM_H(ctx->r10, 0XA);
    // 0x8002B2A0: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B2A4: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B2A8: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B2AC: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B2B0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B2B4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B2B8: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B2BC: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B2C0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B2C4: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B2C8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B2CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002B2D0:
    // 0x8002B2D0: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B2D4: bne         $at, $zero, L_8002B2F4
    if (ctx->r1 != 0) {
        // 0x8002B2D8: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B2F4;
    }
    // 0x8002B2D8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B2DC: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B2E0: bne         $at, $zero, L_8002B2F8
    if (ctx->r1 != 0) {
        // 0x8002B2E4: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B2F8;
    }
    // 0x8002B2E4: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B2E8: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B2EC: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B2F0: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B2F4:
    // 0x8002B2F4: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B2F8:
    // 0x8002B2F8: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B2FC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B300: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B304: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B308: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B30C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B310: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B314: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B318: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002B31C: bne         $at, $zero, L_8002B33C
    if (ctx->r1 != 0) {
        // 0x8002B320: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8002B33C;
    }
    // 0x8002B320: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002B324: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B328: bne         $at, $zero, L_8002B33C
    if (ctx->r1 != 0) {
        // 0x8002B32C: nop
    
            goto L_8002B33C;
    }
    // 0x8002B32C: nop

    // 0x8002B330: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002B334: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002B338: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002B33C:
    // 0x8002B33C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B340: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002B344: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B348: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B34C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002B350: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002B354: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002B358: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B35C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B360: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B364: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002B368: bne         $at, $zero, L_8002B388
    if (ctx->r1 != 0) {
        // 0x8002B36C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8002B388;
    }
    // 0x8002B36C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002B370: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002B374: bne         $at, $zero, L_8002B388
    if (ctx->r1 != 0) {
        // 0x8002B378: nop
    
            goto L_8002B388;
    }
    // 0x8002B378: nop

    // 0x8002B37C: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002B380: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002B384: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002B388:
    // 0x8002B388: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B38C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002B390: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B394: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B398: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002B39C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002B3A0: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002B3A4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B3A8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B3AC: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B3B0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8002B3B4: bne         $at, $zero, L_8002B3D4
    if (ctx->r1 != 0) {
        // 0x8002B3B8: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8002B3D4;
    }
    // 0x8002B3B8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B3BC: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002B3C0: bne         $at, $zero, L_8002B3D4
    if (ctx->r1 != 0) {
        // 0x8002B3C4: nop
    
            goto L_8002B3D4;
    }
    // 0x8002B3C4: nop

    // 0x8002B3C8: or          $s1, $s1, $t7
    ctx->r17 = ctx->r17 | ctx->r15;
    // 0x8002B3CC: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002B3D0: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002B3D4:
    // 0x8002B3D4: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B3D8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B3DC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B3E0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002B3E4: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B3E8: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002B3EC: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002B3F0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B3F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002B3F8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B3FC: bne         $a3, $at, L_8002B2D0
    if (ctx->r7 != ctx->r1) {
        // 0x8002B400: sra         $a0, $t8, 16
        ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B2D0;
    }
    // 0x8002B400: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B404: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B408: nop

    // 0x8002B40C: blez        $a1, L_8002B66C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002B410: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B66C;
    }
    // 0x8002B410: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B414:
    // 0x8002B414: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x8002B418: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B41C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B420: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002B424: lw          $t7, -0x36E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X36E8);
    // 0x8002B428: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B42C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002B430: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002B434: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8002B438: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8002B43C: lb          $s2, 0x7($t7)
    ctx->r18 = MEM_B(ctx->r15, 0X7);
    // 0x8002B440: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x8002B444: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x8002B448: lh          $s0, 0x10($v1)
    ctx->r16 = MEM_H(ctx->r3, 0X10);
    // 0x8002B44C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8002B450: beq         $s2, $at, L_8002B478
    if (ctx->r18 == ctx->r1) {
        // 0x8002B454: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8002B478;
    }
    // 0x8002B454: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8002B458: beq         $s2, $at, L_8002B47C
    if (ctx->r18 == ctx->r1) {
        // 0x8002B45C: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B47C;
    }
    // 0x8002B45C: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B460: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8002B464: nop

    // 0x8002B468: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x8002B46C: beq         $t8, $zero, L_8002B47C
    if (ctx->r24 == 0) {
        // 0x8002B470: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B47C;
    }
    // 0x8002B470: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002B478:
    // 0x8002B478: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
L_8002B47C:
    // 0x8002B47C: beq         $at, $zero, L_8002B65C
    if (ctx->r1 == 0) {
        // 0x8002B480: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8002B65C;
    }
    // 0x8002B480: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_8002B484:
    // 0x8002B484: lw          $t6, 0x10($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X10);
    // 0x8002B488: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x8002B48C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B490: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8002B494: nop

    // 0x8002B498: and         $t6, $t8, $s1
    ctx->r14 = ctx->r24 & ctx->r17;
    // 0x8002B49C: bne         $s1, $t6, L_8002B644
    if (ctx->r17 != ctx->r14) {
        // 0x8002B4A0: nop
    
            goto L_8002B644;
    }
    // 0x8002B4A0: nop

    // 0x8002B4A4: lw          $t7, 0x4($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4);
    // 0x8002B4A8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x8002B4AC: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B4B0: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8002B4B4: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B4B8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8002B4BC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B4C0: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B4C4: lw          $a1, 0x0($ra)
    ctx->r5 = MEM_W(ctx->r31, 0X0);
    // 0x8002B4C8: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B4CC: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8002B4D0: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x8002B4D4: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B4D8: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8002B4DC: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x8002B4E0: lh          $a3, 0x4($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X4);
    // 0x8002B4E4: nop

    // 0x8002B4E8: subu        $a0, $s4, $a3
    ctx->r4 = SUB32(ctx->r20, ctx->r7);
    // 0x8002B4EC: mflo        $t6
    ctx->r14 = lo;
    // 0x8002B4F0: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x8002B4F4: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8002B4F8: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B4FC: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x8002B500: subu        $t9, $t0, $a2
    ctx->r25 = SUB32(ctx->r8, ctx->r6);
    // 0x8002B504: subu        $t6, $t1, $a3
    ctx->r14 = SUB32(ctx->r9, ctx->r7);
    // 0x8002B508: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B50C: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8002B510: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8002B514: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x8002B518: subu        $v1, $s6, $a2
    ctx->r3 = SUB32(ctx->r22, ctx->r6);
    // 0x8002B51C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B520: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B524: nop

    // 0x8002B528: nop

    // 0x8002B52C: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B530: subu        $t9, $s6, $t0
    ctx->r25 = SUB32(ctx->r22, ctx->r8);
    // 0x8002B534: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B538: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x8002B53C: subu        $t7, $t4, $t1
    ctx->r15 = SUB32(ctx->r12, ctx->r9);
    // 0x8002B540: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B544: slti        $t6, $a1, 0x0
    ctx->r14 = SIGNED(ctx->r5) < 0X0 ? 1 : 0;
    // 0x8002B548: xori        $a1, $t6, 0x1
    ctx->r5 = ctx->r14 ^ 0X1;
    // 0x8002B54C: subu        $t9, $s4, $t1
    ctx->r25 = SUB32(ctx->r20, ctx->r9);
    // 0x8002B550: subu        $t6, $t3, $t0
    ctx->r14 = SUB32(ctx->r11, ctx->r8);
    // 0x8002B554: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B558: nop

    // 0x8002B55C: nop

    // 0x8002B560: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B564: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B568: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x8002B56C: slti        $t9, $t6, 0x0
    ctx->r25 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x8002B570: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x8002B574: bne         $t9, $a1, L_8002B644
    if (ctx->r25 != ctx->r5) {
        // 0x8002B578: subu        $t8, $t4, $a3
        ctx->r24 = SUB32(ctx->r12, ctx->r7);
            goto L_8002B644;
    }
    // 0x8002B578: subu        $t8, $t4, $a3
    ctx->r24 = SUB32(ctx->r12, ctx->r7);
    // 0x8002B57C: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B580: subu        $t6, $t3, $a2
    ctx->r14 = SUB32(ctx->r11, ctx->r6);
    // 0x8002B584: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B588: nop

    // 0x8002B58C: nop

    // 0x8002B590: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B594: mflo        $t9
    ctx->r25 = lo;
    // 0x8002B598: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002B59C: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002B5A0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002B5A4: beq         $a1, $t6, L_8002B644
    if (ctx->r5 == ctx->r14) {
        // 0x8002B5A8: nop
    
            goto L_8002B644;
    }
    // 0x8002B5A8: nop

    // 0x8002B5AC: lw          $t7, 0x14($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X14);
    // 0x8002B5B0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8002B5B4: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B5B8: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8002B5BC: lw          $t6, 0x18($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X18);
    // 0x8002B5C0: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002B5C4: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B5C8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002B5CC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002B5D0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B5D4: c.eq.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d == ctx->f8.d;
    // 0x8002B5D8: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002B5DC: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002B5E0: bc1t        L_8002B644
    if (c1cs) {
        // 0x8002B5E4: nop
    
            goto L_8002B644;
    }
    // 0x8002B5E4: nop

    // 0x8002B5E8: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8002B5EC: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8002B5F0: addu        $t8, $t8, $s5
    ctx->r24 = ADD32(ctx->r24, ctx->r21);
    // 0x8002B5F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B5F8: mul.s       $f18, $f12, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8002B5FC: addiu       $t7, $t7, -0x2ED8
    ctx->r15 = ADD32(ctx->r15, -0X2ED8);
    // 0x8002B600: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B604: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B608: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002B60C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002B610: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8002B614: slti        $at, $s5, 0x14
    ctx->r1 = SIGNED(ctx->r21) < 0X14 ? 1 : 0;
    // 0x8002B618: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002B61C: sb          $s2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r18;
    // 0x8002B620: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8002B624: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8002B628: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x8002B62C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8002B630: bne         $at, $zero, L_8002B644
    if (ctx->r1 != 0) {
        // 0x8002B634: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_8002B644;
    }
    // 0x8002B634: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002B638: lh          $s7, 0x20($ra)
    ctx->r23 = MEM_H(ctx->r31, 0X20);
    // 0x8002B63C: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8002B640: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8002B644:
    // 0x8002B644: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002B648: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B64C: bne         $at, $zero, L_8002B484
    if (ctx->r1 != 0) {
        // 0x8002B650: nop
    
            goto L_8002B484;
    }
    // 0x8002B650: nop

    // 0x8002B654: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B658: nop

L_8002B65C:
    // 0x8002B65C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002B660: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002B664: bne         $at, $zero, L_8002B414
    if (ctx->r1 != 0) {
        // 0x8002B668: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B414;
    }
    // 0x8002B668: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B66C:
    // 0x8002B66C: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8002B670: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8002B674: slt         $at, $fp, $t6
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B678: bne         $at, $zero, L_8002B1CC
    if (ctx->r1 != 0) {
        // 0x8002B67C: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002B1CC;
    }
    // 0x8002B67C: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002B680: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x8002B684: nop

L_8002B688:
    // 0x8002B688: bltz        $s0, L_8002B73C
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002B68C: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8002B73C;
    }
    // 0x8002B68C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B690: lw          $t3, -0x36E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X36E8);
    // 0x8002B694: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002B698: lh          $t9, 0x1A($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1A);
    // 0x8002B69C: addiu       $t0, $t0, -0x2ED8
    ctx->r8 = ADD32(ctx->r8, -0X2ED8);
    // 0x8002B6A0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002B6A4: beq         $at, $zero, L_8002B73C
    if (ctx->r1 == 0) {
        // 0x8002B6A8: sll         $t7, $s0, 4
        ctx->r15 = S32(ctx->r16 << 4);
            goto L_8002B73C;
    }
    // 0x8002B6A8: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002B6AC: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8002B6B0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8002B6B4: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x8002B6B8: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8002B6BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B6C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002B6C4: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x8002B6C8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002B6CC: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x8002B6D0: addu        $ra, $t8, $t7
    ctx->r31 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B6D4: lb          $t9, 0x2B($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X2B);
    // 0x8002B6D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B6DC: beq         $t9, $zero, L_8002B714
    if (ctx->r25 == 0) {
        // 0x8002B6E0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8002B714;
    }
    // 0x8002B6E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B6E4: lw          $t8, -0x2C7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C7C);
    // 0x8002B6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B6EC: beq         $t8, $zero, L_8002B714
    if (ctx->r24 == 0) {
        // 0x8002B6F0: addu        $a3, $v0, $t0
        ctx->r7 = ADD32(ctx->r2, ctx->r8);
            goto L_8002B714;
    }
    // 0x8002B6F0: addu        $a3, $v0, $t0
    ctx->r7 = ADD32(ctx->r2, ctx->r8);
    // 0x8002B6F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8002B6F8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8002B6FC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B700: jal         0x800BB2F4
    // 0x8002B704: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_800BB2F4(rdram, ctx);
        goto after_1;
    // 0x8002B704: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002B708: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8002B70C: b           L_8002B738
    // 0x8002B710: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8002B738;
    // 0x8002B710: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8002B714:
    // 0x8002B714: lh          $t7, 0x38($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X38);
    // 0x8002B718: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002B71C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002B720: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B724: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002B728: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8002B72C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002B730: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8002B734: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_8002B738:
    // 0x8002B738: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8002B73C:
    // 0x8002B73C: blez        $s5, L_8002B7FC
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8002B740: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B7FC;
    }
    // 0x8002B740: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B744: andi        $a1, $s5, 0x3
    ctx->r5 = ctx->r21 & 0X3;
    // 0x8002B748: beq         $a1, $zero, L_8002B788
    if (ctx->r5 == 0) {
        // 0x8002B74C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002B788;
    }
    // 0x8002B74C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B750: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B754: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B758: addiu       $t7, $t7, -0x2ED8
    ctx->r15 = ADD32(ctx->r15, -0X2ED8);
    // 0x8002B75C: addiu       $t9, $t9, -0x2D48
    ctx->r25 = ADD32(ctx->r25, -0X2D48);
    // 0x8002B760: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002B764: sll         $t8, $zero, 4
    ctx->r24 = S32(0 << 4);
    // 0x8002B768: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B76C: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
L_8002B770:
    // 0x8002B770: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B774: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B778: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8002B77C: bne         $a0, $a3, L_8002B770
    if (ctx->r4 != ctx->r7) {
        // 0x8002B780: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B770;
    }
    // 0x8002B780: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B784: beq         $a3, $s5, L_8002B7FC
    if (ctx->r7 == ctx->r21) {
        // 0x8002B788: sll         $t6, $s5, 2
        ctx->r14 = S32(ctx->r21 << 2);
            goto L_8002B7FC;
    }
L_8002B788:
    // 0x8002B788: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8002B78C: addu        $t6, $t6, $s5
    ctx->r14 = ADD32(ctx->r14, ctx->r21);
    // 0x8002B790: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B794: addiu       $t9, $t9, -0x2E9C
    ctx->r25 = ADD32(ctx->r25, -0X2E9C);
    // 0x8002B798: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B79C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7A0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B7A4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8002B7A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B7AC: addiu       $t9, $t9, -0x2ED8
    ctx->r25 = ADD32(ctx->r25, -0X2ED8);
    // 0x8002B7B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B7B4: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B7BC: addiu       $t7, $t7, -0x2D48
    ctx->r15 = ADD32(ctx->r15, -0X2D48);
    // 0x8002B7C0: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8002B7C4: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B7C8: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x8002B7CC: addiu       $a2, $v0, 0x28
    ctx->r6 = ADD32(ctx->r2, 0X28);
    // 0x8002B7D0: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
L_8002B7D4:
    // 0x8002B7D4: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x8002B7D8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002B7DC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B7E0: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B7E4: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x8002B7E8: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8002B7EC: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8002B7F0: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8002B7F4: bne         $a0, $t0, L_8002B7D4
    if (ctx->r4 != ctx->r8) {
        // 0x8002B7F8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002B7D4;
    }
    // 0x8002B7F8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8002B7FC:
    // 0x8002B7FC: addiu       $t1, $s5, -0x1
    ctx->r9 = ADD32(ctx->r21, -0X1);
    // 0x8002B800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8002B804:
    // 0x8002B804: blez        $t1, L_8002B958
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002B808: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B958;
    }
    // 0x8002B808: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B80C: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x8002B810: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8002B814: beq         $t8, $zero, L_8002B868
    if (ctx->r24 == 0) {
        // 0x8002B818: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8002B868;
    }
    // 0x8002B818: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002B81C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B820: addiu       $t6, $t6, -0x2D48
    ctx->r14 = ADD32(ctx->r14, -0X2D48);
    // 0x8002B824: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x8002B828: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
L_8002B82C:
    // 0x8002B82C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B830: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B834: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B838: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B83C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B840: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8002B844: nop

    // 0x8002B848: bc1f        L_8002B85C
    if (!c1cs) {
        // 0x8002B84C: nop
    
            goto L_8002B85C;
    }
    // 0x8002B84C: nop

    // 0x8002B850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B854: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B858: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_8002B85C:
    // 0x8002B85C: bne         $t0, $a3, L_8002B82C
    if (ctx->r8 != ctx->r7) {
        // 0x8002B860: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B82C;
    }
    // 0x8002B860: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B864: beq         $a3, $t1, L_8002B958
    if (ctx->r7 == ctx->r9) {
        // 0x8002B868: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8002B958;
    }
L_8002B868:
    // 0x8002B868: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B86C: addiu       $t8, $t8, -0x2D48
    ctx->r24 = ADD32(ctx->r24, -0X2D48);
    // 0x8002B870: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8002B874: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8002B878: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8002B87C: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
L_8002B880:
    // 0x8002B880: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B884: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B888: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B88C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B890: nop

    // 0x8002B894: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8002B898: nop

    // 0x8002B89C: bc1f        L_8002B8B8
    if (!c1cs) {
        // 0x8002B8A0: nop
    
            goto L_8002B8B8;
    }
    // 0x8002B8A0: nop

    // 0x8002B8A4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B8A8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B8AC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B8B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8002B8B8:
    // 0x8002B8B8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x8002B8BC: nop

    // 0x8002B8C0: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8C4: nop

    // 0x8002B8C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002B8CC: nop

    // 0x8002B8D0: bc1f        L_8002B8EC
    if (!c1cs) {
        // 0x8002B8D4: nop
    
            goto L_8002B8EC;
    }
    // 0x8002B8D4: nop

    // 0x8002B8D8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B8DC: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B8E0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B8E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002B8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B8EC:
    // 0x8002B8EC: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8002B8F0: nop

    // 0x8002B8F4: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B8F8: nop

    // 0x8002B8FC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002B900: nop

    // 0x8002B904: bc1f        L_8002B920
    if (!c1cs) {
        // 0x8002B908: nop
    
            goto L_8002B920;
    }
    // 0x8002B908: nop

    // 0x8002B90C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B910: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B914: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B918: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B91C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B920:
    // 0x8002B920: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x8002B924: nop

    // 0x8002B928: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B92C: nop

    // 0x8002B930: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8002B934: nop

    // 0x8002B938: bc1f        L_8002B94C
    if (!c1cs) {
        // 0x8002B93C: nop
    
            goto L_8002B94C;
    }
    // 0x8002B93C: nop

    // 0x8002B940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B944: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B948: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
L_8002B94C:
    // 0x8002B94C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002B950: bne         $v1, $t0, L_8002B880
    if (ctx->r3 != ctx->r8) {
        // 0x8002B954: nop
    
            goto L_8002B880;
    }
    // 0x8002B954: nop

L_8002B958:
    // 0x8002B958: beq         $a2, $zero, L_8002B804
    if (ctx->r6 == 0) {
        // 0x8002B95C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8002B804;
    }
    // 0x8002B95C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002B960: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8002B964: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B968: addiu       $t6, $t6, -0x2D48
    ctx->r14 = ADD32(ctx->r14, -0X2D48);
    // 0x8002B96C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B970: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002B974: sb          $s5, -0x2CF8($at)
    MEM_B(-0X2CF8, ctx->r1) = ctx->r21;
    // 0x8002B978: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8002B97C:
    // 0x8002B97C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002B980: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002B984: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002B988: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002B98C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002B990: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002B994: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B998: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002B99C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002B9A0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002B9A4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B9A8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002B9AC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002B9B0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002B9B4: jr          $ra
    // 0x8002B9B8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002B9B8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void menu_file_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE70: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008DE74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008DE78: jal         0x8006EA90
    // 0x8008DE7C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008DE7C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DE80: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008DE84: jal         0x8008C168
    // 0x8008DE88: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008DE88: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008DE8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DE90: lw          $v0, 0x63D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D8);
    // 0x8008DE94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DE98: beq         $v0, $zero, L_8008DF78
    if (ctx->r2 == 0) {
        // 0x8008DE9C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8008DF78;
    }
    // 0x8008DE9C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008DEA0: sw          $t6, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r14;
    // 0x8008DEA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008DEA8: lw          $t7, 0x63D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63D8);
    // 0x8008DEAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008DEB0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8008DEB4: bne         $at, $zero, L_8008DF78
    if (ctx->r1 != 0) {
        // 0x8008DEB8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008DF78;
    }
    // 0x8008DEB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DEBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008DEC0: addiu       $a3, $a3, 0x6530
    ctx->r7 = ADD32(ctx->r7, 0X6530);
    // 0x8008DEC4: addiu       $v0, $v0, 0x64A0
    ctx->r2 = ADD32(ctx->r2, 0X64A0);
L_8008DEC8:
    // 0x8008DEC8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8008DECC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008DED0: lbu         $t8, 0x4B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4B);
    // 0x8008DED4: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x8008DED8: beq         $t8, $zero, L_8008DF04
    if (ctx->r24 == 0) {
        // 0x8008DEDC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008DF04;
    }
    // 0x8008DEDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008DEE0: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x8008DEE4: addiu       $t5, $zero, 0x52
    ctx->r13 = ADD32(0, 0X52);
    // 0x8008DEE8: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008DEEC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008DEF0: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    // 0x8008DEF4: sb          $t4, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r12;
    // 0x8008DEF8: sb          $t5, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r13;
    // 0x8008DEFC: b           L_8008DF58
    // 0x8008DF00: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008DF58;
    // 0x8008DF00: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008DF04:
    // 0x8008DF04: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8008DF08: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008DF0C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8008DF10: beq         $t7, $zero, L_8008DF1C
    if (ctx->r15 == 0) {
        // 0x8008DF14: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008DF1C;
    }
    // 0x8008DF14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008DF18: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008DF1C:
    // 0x8008DF1C: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008DF20: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008DF24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8008DF28: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008DF2C: nop

    // 0x8008DF30: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x8008DF34: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x8008DF38: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8008DF3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008DF40: jal         0x800976F8
    // 0x8008DF44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x8008DF44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x8008DF48: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008DF4C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8008DF50: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008DF54: nop

L_8008DF58:
    // 0x8008DF58: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8008DF5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008DF60: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8008DF64: bne         $t0, $at, L_8008DEC8
    if (ctx->r8 != ctx->r1) {
        // 0x8008DF68: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8008DEC8;
    }
    // 0x8008DF68: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8008DF6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DF70: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x8008DF74: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_8008DF78:
    // 0x8008DF78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008DF7C: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8008DF80: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008DF84: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008DF88: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008DF8C: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x8008DF90: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008DF94: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8008DF98: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008DF9C: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008DFA0: beq         $v0, $zero, L_8008DFC8
    if (ctx->r2 == 0) {
        // 0x8008DFA4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008DFC8;
    }
    // 0x8008DFA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008DFA8: blez        $v0, L_8008DFC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008DFAC: subu        $t4, $v0, $a1
        ctx->r12 = SUB32(ctx->r2, ctx->r5);
            goto L_8008DFC0;
    }
    // 0x8008DFAC: subu        $t4, $v0, $a1
    ctx->r12 = SUB32(ctx->r2, ctx->r5);
    // 0x8008DFB0: addu        $t9, $v0, $a1
    ctx->r25 = ADD32(ctx->r2, ctx->r5);
    // 0x8008DFB4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008DFB8: b           L_8008DFC8
    // 0x8008DFBC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8008DFC8;
    // 0x8008DFBC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008DFC0:
    // 0x8008DFC0: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8008DFC4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8008DFC8:
    // 0x8008DFC8: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x8008DFCC: bne         $at, $zero, L_8008DFF8
    if (ctx->r1 != 0) {
        // 0x8008DFD0: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8008DFF8;
    }
    // 0x8008DFD0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8008DFD4: beq         $at, $zero, L_8008DFF8
    if (ctx->r1 == 0) {
        // 0x8008DFD8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008DFF8;
    }
    // 0x8008DFD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008DFDC: jal         0x8008CD74
    // 0x8008DFE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    fileselect_render(rdram, ctx);
        goto after_3;
    // 0x8008DFE0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_3:
    // 0x8008DFE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008DFE8: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008DFEC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008DFF0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008DFF4: nop

L_8008DFF8:
    // 0x8008DFF8: bne         $v0, $zero, L_8008E28C
    if (ctx->r2 != 0) {
        // 0x8008DFFC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008E28C;
    }
    // 0x8008DFFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008E000: lw          $t5, 0x63D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63D8);
    // 0x8008E004: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E008: bne         $t5, $zero, L_8008E28C
    if (ctx->r13 != 0) {
        // 0x8008E00C: nop
    
            goto L_8008E28C;
    }
    // 0x8008E00C: nop

    // 0x8008E010: lw          $t6, 0x6484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6484);
    // 0x8008E014: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E018: beq         $t6, $zero, L_8008E030
    if (ctx->r14 == 0) {
        // 0x8008E01C: nop
    
            goto L_8008E030;
    }
    // 0x8008E01C: nop

    // 0x8008E020: jal         0x8008D8BC
    // 0x8008E024: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_copy(rdram, ctx);
        goto after_4;
    // 0x8008E024: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8008E028: b           L_8008E28C
    // 0x8008E02C: nop

        goto L_8008E28C;
    // 0x8008E02C: nop

L_8008E030:
    // 0x8008E030: lw          $t7, 0x6488($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6488);
    // 0x8008E034: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E038: beq         $t7, $zero, L_8008E050
    if (ctx->r15 == 0) {
        // 0x8008E03C: nop
    
            goto L_8008E050;
    }
    // 0x8008E03C: nop

    // 0x8008E040: jal         0x8008DC7C
    // 0x8008E044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_erase(rdram, ctx);
        goto after_5;
    // 0x8008E044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x8008E048: b           L_8008E28C
    // 0x8008E04C: nop

        goto L_8008E28C;
    // 0x8008E04C: nop

L_8008E050:
    // 0x8008E050: lw          $t8, 0x6CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6CC0);
    // 0x8008E054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008E058: beq         $t8, $zero, L_8008E17C
    if (ctx->r24 == 0) {
        // 0x8008E05C: nop
    
            goto L_8008E17C;
    }
    // 0x8008E05C: nop

    // 0x8008E060: jal         0x8006A554
    // 0x8008E064: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8008E064: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_6:
    // 0x8008E068: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E06C: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8008E070: beq         $t9, $zero, L_8008E0CC
    if (ctx->r25 == 0) {
        // 0x8008E074: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008E0CC;
    }
    // 0x8008E074: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E078: lw          $t4, 0xFA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XFA0);
    // 0x8008E07C: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8008E080: bne         $t4, $zero, L_8008E0CC
    if (ctx->r12 != 0) {
        // 0x8008E084: subu        $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_8008E0CC;
    }
    // 0x8008E084: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8008E088: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E08C: addiu       $t6, $t6, 0x64A0
    ctx->r14 = ADD32(ctx->r14, 0X64A0);
    // 0x8008E090: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E094: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E098: jal         0x800981E8
    // 0x8008E09C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    menu_unload_bigfont(rdram, ctx);
        goto after_7;
    // 0x8008E09C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_7:
    // 0x8008E0A0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008E0A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E0A8: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x8008E0AC: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x8008E0B0: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8008E0B4: addiu       $t9, $zero, 0x52
    ctx->r25 = ADD32(0, 0X52);
    // 0x8008E0B8: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x8008E0BC: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x8008E0C0: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x8008E0C4: b           L_8008E28C
    // 0x8008E0C8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008E28C;
    // 0x8008E0C8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008E0CC:
    // 0x8008E0CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008E0D0: jal         0x80097D10
    // 0x8008E0D4: nop

    filename_enter(rdram, ctx);
        goto after_8;
    // 0x8008E0D4: nop

    after_8:
    // 0x8008E0D8: beq         $v0, $zero, L_8008E28C
    if (ctx->r2 == 0) {
        // 0x8008E0DC: nop
    
            goto L_8008E28C;
    }
    // 0x8008E0DC: nop

    // 0x8008E0E0: jal         0x800981E8
    // 0x8008E0E4: nop

    menu_unload_bigfont(rdram, ctx);
        goto after_9;
    // 0x8008E0E4: nop

    after_9:
    // 0x8008E0E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E0EC: lw          $t4, -0xB34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB34);
    // 0x8008E0F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E0F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008E0F8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008E0FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E100: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E104: addiu       $t6, $t6, 0x64A0
    ctx->r14 = ADD32(ctx->r14, 0X64A0);
    // 0x8008E108: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x8008E10C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E110: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E114: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008E118: lw          $t7, -0xB6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB6C);
    // 0x8008E11C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E120: beq         $t7, $zero, L_8008E130
    if (ctx->r15 == 0) {
        // 0x8008E124: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8008E130;
    }
    // 0x8008E124: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8008E128: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E12C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008E130:
    // 0x8008E130: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008E134: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E138: jal         0x80097744
    // 0x8008E13C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_10;
    // 0x8008E13C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8008E140: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008E144: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E148: sw          $v0, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r2;
    // 0x8008E14C: lw          $a0, -0xB34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB34);
    // 0x8008E150: jal         0x8006EB78
    // 0x8008E154: nop

    mark_read_save_file(rdram, ctx);
        goto after_11;
    // 0x8008E154: nop

    after_11:
    // 0x8008E158: jal         0x80000C98
    // 0x8008E15C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_12;
    // 0x8008E15C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_12:
    // 0x8008E160: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E164: jal         0x800C01D8
    // 0x8008E168: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_13;
    // 0x8008E168: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_13:
    // 0x8008E16C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008E170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E174: b           L_8008E28C
    // 0x8008E178: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
        goto L_8008E28C;
    // 0x8008E178: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
L_8008E17C:
    // 0x8008E17C: jal         0x8008D5F8
    // 0x8008E180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_root(rdram, ctx);
        goto after_14;
    // 0x8008E180: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_14:
    // 0x8008E184: beq         $v0, $zero, L_8008E28C
    if (ctx->r2 == 0) {
        // 0x8008E188: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8008E28C;
    }
    // 0x8008E188: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008E18C: blez        $v0, L_8008E268
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E190: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008E268;
    }
    // 0x8008E190: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008E194: lw          $t1, -0xB34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB34);
    // 0x8008E198: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E19C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008E1A0: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8008E1A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008E1A8: addiu       $t7, $t7, 0x64A0
    ctx->r15 = ADD32(ctx->r15, 0X64A0);
    // 0x8008E1AC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8008E1B0: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8008E1B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008E1B8: beq         $t8, $zero, L_8008E1EC
    if (ctx->r24 == 0) {
        // 0x8008E1BC: addiu       $t3, $t3, 0xFB0
        ctx->r11 = ADD32(ctx->r11, 0XFB0);
            goto L_8008E1EC;
    }
    // 0x8008E1BC: addiu       $t3, $t3, 0xFB0
    ctx->r11 = ADD32(ctx->r11, 0XFB0);
    // 0x8008E1C0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008E1C4: jal         0x80001D04
    // 0x8008E1C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8008E1C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008E1CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E1D0: lw          $a0, -0xB34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB34);
    // 0x8008E1D4: jal         0x8006EB78
    // 0x8008E1D8: nop

    mark_read_save_file(rdram, ctx);
        goto after_16;
    // 0x8008E1D8: nop

    after_16:
    // 0x8008E1DC: jal         0x80000C98
    // 0x8008E1E0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_17;
    // 0x8008E1E0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_17:
    // 0x8008E1E4: b           L_8008E26C
    // 0x8008E1E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8008E26C;
    // 0x8008E1E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E1EC:
    // 0x8008E1EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E1F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E1F4: sw          $t9, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r25;
    // 0x8008E1F8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008E1FC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8008E200: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8008E204: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008E208: bne         $t4, $zero, L_8008E214
    if (ctx->r12 != 0) {
        // 0x8008E20C: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008E214;
    }
    // 0x8008E20C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008E210: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_8008E214:
    // 0x8008E214: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E218: addiu       $t6, $t6, 0x3CC
    ctx->r14 = ADD32(ctx->r14, 0X3CC);
    // 0x8008E21C: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x8008E220: addiu       $t2, $t2, 0x3FC
    ctx->r10 = ADD32(ctx->r10, 0X3FC);
    // 0x8008E224: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E228: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8008E22C: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8008E230: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x8008E234: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x8008E238: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008E23C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008E240: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x8008E244: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8008E248: addu        $a2, $t5, $t0
    ctx->r6 = ADD32(ctx->r13, ctx->r8);
    // 0x8008E24C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8008E250: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008E254: addiu       $a0, $t0, 0xBB
    ctx->r4 = ADD32(ctx->r8, 0XBB);
    // 0x8008E258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E25C: jal         0x80097874
    // 0x8008E260: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    filename_init(rdram, ctx);
        goto after_18;
    // 0x8008E260: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_18:
    // 0x8008E264: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008E268:
    // 0x8008E268: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E26C:
    // 0x8008E26C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E270: beq         $t8, $zero, L_8008E28C
    if (ctx->r24 == 0) {
        // 0x8008E274: nop
    
            goto L_8008E28C;
    }
    // 0x8008E274: nop

    // 0x8008E278: jal         0x800C01D8
    // 0x8008E27C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008E27C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_19:
    // 0x8008E280: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008E284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E288: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
L_8008E28C:
    // 0x8008E28C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E290: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x8008E294: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008E298: nop

    // 0x8008E29C: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8008E2A0: bne         $at, $zero, L_8008E3F4
    if (ctx->r1 != 0) {
        // 0x8008E2A4: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_8008E3F4;
    }
    // 0x8008E2A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E2A8: addiu       $a2, $a2, -0x268
    ctx->r6 = ADD32(ctx->r6, -0X268);
    // 0x8008E2AC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E2B0: lui         $a0, 0xFBFF
    ctx->r4 = S32(0XFBFF << 16);
    // 0x8008E2B4: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x8008E2B8: bgez        $t4, L_8008E2F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008E2BC: ori         $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 | 0XFFFF;
            goto L_8008E2F8;
    }
    // 0x8008E2BC: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8008E2C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E2C4: addiu       $a1, $a1, -0x264
    ctx->r5 = ADD32(ctx->r5, -0X264);
    // 0x8008E2C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008E2CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008E2D0: and         $t5, $v1, $a0
    ctx->r13 = ctx->r3 & ctx->r4;
    // 0x8008E2D4: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x8008E2D8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008E2DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8008E2E0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8008E2E4: nop

    // 0x8008E2E8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8008E2EC: nop

    // 0x8008E2F0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    extern void dkr_magic_code_balloon_awarded(uint8_t*, recomp_context*); dkr_magic_code_balloon_awarded(rdram, ctx);
    // 0x8008E2F4: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_8008E2F8:
    // 0x8008E2F8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E2FC: lw          $t5, -0xB44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB44);
    // 0x8008E300: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E304: xori        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 ^ 0X2;
    // 0x8008E308: addiu       $v0, $v0, -0xB40
    ctx->r2 = ADD32(ctx->r2, -0XB40);
    // 0x8008E30C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E310: beq         $t6, $zero, L_8008E320
    if (ctx->r14 == 0) {
        // 0x8008E314: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8008E320;
    }
    // 0x8008E314: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E318: jal         0x8000E1B8
    // 0x8008E31C: nop

    reset_lead_player_index(rdram, ctx);
        goto after_20;
    // 0x8008E31C: nop

    after_20:
L_8008E320:
    // 0x8008E320: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E324: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E328: sw          $t8, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r24;
    // 0x8008E32C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E330: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E334: jal         0x8008E428
    // 0x8008E338: sw          $t9, 0xFAC($at)
    MEM_W(0XFAC, ctx->r1) = ctx->r25;
    fileselect_free(rdram, ctx);
        goto after_21;
    // 0x8008E338: sw          $t9, 0xFAC($at)
    MEM_W(0XFAC, ctx->r1) = ctx->r25;
    after_21:
    // 0x8008E33C: jal         0x80000B28
    // 0x8008E340: nop

    music_change_on(rdram, ctx);
        goto after_22;
    // 0x8008E340: nop

    after_22:
    // 0x8008E344: jal         0x8006E5BC
    // 0x8008E348: nop

    init_racer_headers(rdram, ctx);
        goto after_23;
    // 0x8008E348: nop

    after_23:
    // 0x8008E34C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8008E350: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E354: sw          $zero, 0xFE8($at)
    MEM_W(0XFE8, ctx->r1) = 0;
    // 0x8008E358: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x8008E35C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E360: beq         $t4, $zero, L_8008E3C0
    if (ctx->r12 == 0) {
        // 0x8008E364: nop
    
            goto L_8008E3C0;
    }
    // 0x8008E364: nop

    // 0x8008E368: lw          $t5, -0xB6C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB6C);
    // 0x8008E36C: nop

    // 0x8008E370: beq         $t5, $zero, L_8008E388
    if (ctx->r13 == 0) {
        // 0x8008E374: nop
    
            goto L_8008E388;
    }
    // 0x8008E374: nop

    // 0x8008E378: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8008E37C: nop

    // 0x8008E380: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8008E384: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8008E388:
    // 0x8008E388: jal         0x8001E29C
    // 0x8008E38C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_24;
    // 0x8008E38C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_24:
    // 0x8008E390: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E394: lw          $a2, -0xB44($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB44);
    // 0x8008E398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008E39C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E3A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E3A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E3A8: jal         0x8009ABD8
    // 0x8008E3AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_25;
    // 0x8008E3AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_25:
    // 0x8008E3B0: jal         0x800813D0
    // 0x8008E3B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    menu_init(rdram, ctx);
        goto after_26;
    // 0x8008E3B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_26:
    // 0x8008E3B8: b           L_8008E418
    // 0x8008E3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E418;
    // 0x8008E3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E3C0:
    // 0x8008E3C0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8008E3C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E3C8: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8008E3CC: beq         $t9, $zero, L_8008E3E4
    if (ctx->r25 == 0) {
        // 0x8008E3D0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8008E3E4;
    }
    // 0x8008E3D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E3D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E3D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E3DC: b           L_8008E3E8
    // 0x8008E3E0: sw          $t4, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r12;
        goto L_8008E3E8;
    // 0x8008E3E0: sw          $t4, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r12;
L_8008E3E4:
    // 0x8008E3E4: sw          $zero, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = 0;
L_8008E3E8:
    // 0x8008E3E8: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8008E3EC: b           L_8008E41C
    // 0x8008E3F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8008E41C;
    // 0x8008E3F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E3F4:
    // 0x8008E3F4: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8008E3F8: beq         $at, $zero, L_8008E418
    if (ctx->r1 == 0) {
        // 0x8008E3FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008E418;
    }
    // 0x8008E3FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E400: jal         0x8008E428
    // 0x8008E404: nop

    fileselect_free(rdram, ctx);
        goto after_27;
    // 0x8008E404: nop

    after_27:
    // 0x8008E408: jal         0x800813D0
    // 0x8008E40C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_28;
    // 0x8008E40C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_28:
    // 0x8008E410: b           L_8008E418
    // 0x8008E414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E418;
    // 0x8008E414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E418:
    // 0x8008E418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E41C:
    // 0x8008E41C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008E420: jr          $ra
    // 0x8008E424: nop

    return;
    // 0x8008E424: nop

;}
RECOMP_FUNC void ainode_find_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC48: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001CC4C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001CC50: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x8001CC54: bne         $at, $zero, L_8001CC68
    if (ctx->r1 != 0) {
        // 0x8001CC58: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8001CC68;
    }
    // 0x8001CC58: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001CC5C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001CC60: bne         $at, $zero, L_8001CC70
    if (ctx->r1 != 0) {
        // 0x8001CC64: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001CC70;
    }
    // 0x8001CC64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001CC68:
    // 0x8001CC68: b           L_8001CD1C
    // 0x8001CC6C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD1C;
    // 0x8001CC6C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CC70:
    // 0x8001CC70: lw          $t6, -0x50FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50FC);
    // 0x8001CC74: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001CC78: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001CC7C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001CC80: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x8001CC84: bne         $v0, $zero, L_8001CC94
    if (ctx->r2 != 0) {
        // 0x8001CC88: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001CC94;
    }
    // 0x8001CC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CC8C: b           L_8001CD1C
    // 0x8001CC90: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD1C;
    // 0x8001CC90: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CC94:
    // 0x8001CC94: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8001CC98: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CC9C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8001CCA0: lb          $a3, 0x18($t0)
    ctx->r7 = MEM_B(ctx->r8, 0X18);
    // 0x8001CCA4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001CCA8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CCAC: andi        $t2, $a3, 0x3
    ctx->r10 = ctx->r7 & 0X3;
    // 0x8001CCB0: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8001CCB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001CCB8:
    // 0x8001CCB8: addu        $t3, $v1, $a3
    ctx->r11 = ADD32(ctx->r3, ctx->r7);
    // 0x8001CCBC: lbu         $v0, 0xA($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0XA);
    // 0x8001CCC0: nop

    // 0x8001CCC4: beq         $a0, $v0, L_8001CCE0
    if (ctx->r4 == ctx->r2) {
        // 0x8001CCC8: nop
    
            goto L_8001CCE0;
    }
    // 0x8001CCC8: nop

    // 0x8001CCCC: beq         $s0, $v0, L_8001CCE4
    if (ctx->r16 == ctx->r2) {
        // 0x8001CCD0: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001CCE4;
    }
    // 0x8001CCD0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CCD4: sb          $a3, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r7;
    // 0x8001CCD8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001CCDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001CCE0:
    // 0x8001CCE0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001CCE4:
    // 0x8001CCE4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CCE8: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8001CCEC: andi        $t4, $a3, 0x3
    ctx->r12 = ctx->r7 & 0X3;
    // 0x8001CCF0: bne         $at, $zero, L_8001CCB8
    if (ctx->r1 != 0) {
        // 0x8001CCF4: or          $a3, $t4, $zero
        ctx->r7 = ctx->r12 | 0;
            goto L_8001CCB8;
    }
    // 0x8001CCF4: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8001CCF8: bne         $a1, $zero, L_8001CD08
    if (ctx->r5 != 0) {
        // 0x8001CCFC: nop
    
            goto L_8001CD08;
    }
    // 0x8001CCFC: nop

    // 0x8001CD00: b           L_8001CD1C
    // 0x8001CD04: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD1C;
    // 0x8001CD04: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CD08:
    // 0x8001CD08: lb          $t5, 0x18($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X18);
    // 0x8001CD0C: nop

    // 0x8001CD10: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8001CD14: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
    // 0x8001CD18: nop

L_8001CD1C:
    // 0x8001CD1C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001CD20: jr          $ra
    // 0x8001CD24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001CD24: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void __assert_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B6F44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6F48: jr          $ra
    // 0x800B6F4C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B6F4C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void trophyround_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800983C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800983C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800983C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800983CC: jal         0x8001E29C
    // 0x800983D0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x800983D0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x800983D4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800983D8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800983DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800983E0: bne         $t6, $zero, L_800983F4
    if (ctx->r14 != 0) {
        // 0x800983E4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800983F4;
    }
    // 0x800983E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800983E8: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800983EC: b           L_800983F8
    // 0x800983F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_800983F8;
    // 0x800983F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_800983F4:
    // 0x800983F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800983F8:
    // 0x800983F8: lw          $a0, 0xFE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XFE8);
    // 0x800983FC: jal         0x8006B1D4
    // 0x80098400: nop

    level_world_id(rdram, ctx);
        goto after_1;
    // 0x80098400: nop

    after_1:
    // 0x80098404: jal         0x8006BDDC
    // 0x80098408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_2;
    // 0x80098408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8009840C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80098410: lw          $t8, 0xFE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XFE8);
    // 0x80098414: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80098418: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8009841C: lw          $t0, 0xFEC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XFEC);
    // 0x80098420: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80098424: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80098428: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8009842C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80098430: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80098434: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80098438: lb          $a0, -0x6($t3)
    ctx->r4 = MEM_B(ctx->r11, -0X6);
    // 0x8009843C: jal         0x8006BDDC
    // 0x80098440: nop

    level_name(rdram, ctx);
        goto after_3;
    // 0x80098440: nop

    after_3:
    // 0x80098444: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80098448: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009844C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80098454: jal         0x800C43CC
    // 0x80098458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_4;
    // 0x80098458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8009845C: jal         0x800C42EC
    // 0x80098460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x80098460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80098464: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80098468: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009846C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80098470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80098478: jal         0x800C4384
    // 0x8009847C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x8009847C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_6:
    // 0x80098480: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098484: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80098488: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8009848C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80098490: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80098494: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80098498: jal         0x800C4440
    // 0x8009849C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_7;
    // 0x8009849C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_7:
    // 0x800984A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800984A4: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x800984A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800984AC: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800984B0: lw          $a3, 0x118($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X118);
    // 0x800984B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800984B8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800984BC: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800984C0: jal         0x800C4440
    // 0x800984C4: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    draw_text(rdram, ctx);
        goto after_8;
    // 0x800984C4: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    after_8:
    // 0x800984C8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800984CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800984D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800984D4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800984D8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800984DC: jal         0x800C4384
    // 0x800984E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x800984E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x800984E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800984E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800984EC: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800984F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800984F4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800984F8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800984FC: jal         0x800C4440
    // 0x80098500: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80098500: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_10:
    // 0x80098504: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80098508: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8009850C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098510: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80098514: lw          $a3, 0x118($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X118);
    // 0x80098518: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009851C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80098520: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098524: jal         0x800C4440
    // 0x80098528: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80098528: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_11:
    // 0x8009852C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098530: lw          $t3, 0xFEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XFEC);
    // 0x80098534: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80098538: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x8009853C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80098540: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80098544: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80098548: lw          $a3, 0x228($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X228);
    // 0x8009854C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098550: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80098554: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80098558: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009855C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098560: jal         0x800C4440
    // 0x80098564: addiu       $a2, $a2, 0xB0
    ctx->r6 = ADD32(ctx->r6, 0XB0);
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80098564: addiu       $a2, $a2, 0xB0
    ctx->r6 = ADD32(ctx->r6, 0XB0);
    after_12:
    // 0x80098568: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009856C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098570: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80098574: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80098578: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009857C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80098580: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098584: jal         0x800C4440
    // 0x80098588: addiu       $a2, $a2, 0xD0
    ctx->r6 = ADD32(ctx->r6, 0XD0);
    draw_text(rdram, ctx);
        goto after_13;
    // 0x80098588: addiu       $a2, $a2, 0xD0
    ctx->r6 = ADD32(ctx->r6, 0XD0);
    after_13:
    // 0x8009858C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098590: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80098594: jr          $ra
    // 0x80098598: nop

    return;
    // 0x80098598: nop

;}
RECOMP_FUNC void set_render_printf_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B620C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6210: addiu       $v0, $v0, -0x7A28
    ctx->r2 = ADD32(ctx->r2, -0X7A28);
    // 0x800B6214: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6218: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B621C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6220: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B6224: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B6228: addiu       $t0, $zero, 0x81
    ctx->r8 = ADD32(0, 0X81);
    // 0x800B622C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B6230: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B6234: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6238: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B623C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B6240: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B6244: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B6248: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B624C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B6250: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B6254: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B6258: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B625C: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B6260: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B6264: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B6268: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B626C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B6270: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6274: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B6278: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B627C: nop

    // 0x800B6280: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B6284: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B6288: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B628C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B6290: nop

    // 0x800B6294: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B6298: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B629C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B62A0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B62A4: nop

    // 0x800B62A8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B62AC: jr          $ra
    // 0x800B62B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B62B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7560: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800C7564: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800C7568: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800C756C: beq         $v1, $v0, L_800C757C
    if (ctx->r3 == ctx->r2) {
        // 0x800C7570: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800C757C;
    }
    // 0x800C7570: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7574: b           L_800C7580
    // 0x800C7578: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800C7580;
    // 0x800C7578: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800C757C:
    // 0x800C757C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800C7580:
    // 0x800C7580: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C7584: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800C7588: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C758C: jr          $ra
    // 0x800C7590: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800C7590: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void watereffect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D670: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D674: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D678: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D67C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D680: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D684: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D688: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D68C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D690: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D694: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D69C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002D6A0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D6A4: nop

    // 0x8002D6A8: lh          $t7, 0x36($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X36);
    // 0x8002D6AC: nop

    // 0x8002D6B0: beq         $t7, $zero, L_8002D8B0
    if (ctx->r15 == 0) {
        // 0x8002D6B4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D8B0;
    }
    // 0x8002D6B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D6B8: lh          $t9, 0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X8);
    // 0x8002D6BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D6C0: beq         $t9, $at, L_8002D8AC
    if (ctx->r25 == ctx->r1) {
        // 0x8002D6C4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D8AC;
    }
    // 0x8002D6C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D6C8: lw          $t5, -0x4F3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F3C);
    // 0x8002D6CC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D6D0: bne         $t5, $zero, L_8002D8AC
    if (ctx->r13 != 0) {
        // 0x8002D6D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8002D8AC;
    }
    // 0x8002D6D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D6D8: lw          $t6, -0x4F38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F38);
    // 0x8002D6DC: addiu       $s0, $s0, -0x4F30
    ctx->r16 = ADD32(ctx->r16, -0X4F30);
    // 0x8002D6E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D6E4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002D6E8: lh          $s2, 0x8($a1)
    ctx->r18 = MEM_H(ctx->r5, 0X8);
    // 0x8002D6EC: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8002D6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D6F4: bne         $t9, $at, L_8002D738
    if (ctx->r25 != ctx->r1) {
        // 0x8002D6F8: addiu       $t6, $t6, 0x2
        ctx->r14 = ADD32(ctx->r14, 0X2);
            goto L_8002D738;
    }
    // 0x8002D6F8: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8002D6FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D700: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002D704: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002D708: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002D70C: jal         0x80066348
    // 0x8002D710: nop

    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002D710: nop

    after_0:
    // 0x8002D714: lui         $at, 0x4440
    ctx->r1 = S32(0X4440 << 16);
    // 0x8002D718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D71C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D720: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002D724: nop

    // 0x8002D728: bc1f        L_8002D738
    if (!c1cs) {
        // 0x8002D72C: nop
    
            goto L_8002D738;
    }
    // 0x8002D72C: nop

    // 0x8002D730: lh          $s2, 0xA($t7)
    ctx->r18 = MEM_H(ctx->r15, 0XA);
    // 0x8002D734: nop

L_8002D738:
    // 0x8002D738: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D73C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D740: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8002D744: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D748: lw          $t9, -0x2CB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2CB0);
    // 0x8002D74C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002D750: addiu       $s3, $s3, -0x2CA0
    ctx->r19 = ADD32(ctx->r19, -0X2CA0);
    // 0x8002D754: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D758: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8002D75C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002D760: lw          $t5, -0x2CE0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2CE0);
    // 0x8002D764: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002D768: addiu       $s5, $s5, -0x2CD0
    ctx->r21 = ADD32(ctx->r21, -0X2CD0);
    // 0x8002D76C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D770: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8002D774: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8002D778: lw          $t6, -0x2CC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CC8);
    // 0x8002D77C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002D780: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D784: addiu       $s6, $s6, -0x2CB8
    ctx->r22 = ADD32(ctx->r22, -0X2CB8);
    // 0x8002D788: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8002D78C: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8002D790: sll         $s1, $s2, 3
    ctx->r17 = S32(ctx->r18 << 3);
    // 0x8002D794: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002D798: beq         $at, $zero, L_8002D8AC
    if (ctx->r1 == 0) {
        // 0x8002D79C: lui         $fp, 0x400
        ctx->r30 = S32(0X400 << 16);
            goto L_8002D8AC;
    }
    // 0x8002D79C: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x8002D7A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D7A4: addiu       $s0, $s0, -0x4F60
    ctx->r16 = ADD32(ctx->r16, -0X4F60);
    // 0x8002D7A8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8002D7AC: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
L_8002D7B0:
    // 0x8002D7B0: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002D7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D7B8: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x8002D7BC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8002D7C0: jal         0x8007B4C8
    // 0x8002D7C4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x8002D7C4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_1:
    // 0x8002D7C8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002D7CC: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8002D7D0: addu        $v1, $t6, $s1
    ctx->r3 = ADD32(ctx->r14, ctx->r17);
    // 0x8002D7D4: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x8002D7D8: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x8002D7DC: multu       $a2, $s7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D7E0: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x8002D7E4: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x8002D7E8: subu        $a3, $t7, $a1
    ctx->r7 = SUB32(ctx->r15, ctx->r5);
    // 0x8002D7EC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8002D7F0: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8002D7F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D7F8: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D7FC: subu        $a0, $t8, $a2
    ctx->r4 = SUB32(ctx->r24, ctx->r6);
    // 0x8002D800: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8002D804: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8002D808: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D80C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002D810: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8002D814: addu        $t1, $t4, $s4
    ctx->r9 = ADD32(ctx->r12, ctx->r20);
    // 0x8002D818: andi        $t6, $t1, 0x6
    ctx->r14 = ctx->r9 & 0X6;
    // 0x8002D81C: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D820: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D824: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8002D828: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002D82C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8002D830: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8002D834: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002D838: or          $t5, $t9, $fp
    ctx->r13 = ctx->r25 | ctx->r30;
    // 0x8002D83C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8002D840: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002D844: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D848: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D84C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002D850: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D854: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8002D858: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8002D85C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8002D860: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D864: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D868: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8002D86C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002D870: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002D874: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002D878: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x8002D87C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002D880: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002D884: addu        $t8, $t3, $s4
    ctx->r24 = ADD32(ctx->r11, ctx->r20);
    // 0x8002D888: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002D88C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D890: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002D894: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002D898: lh          $t9, 0xA($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA);
    // 0x8002D89C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002D8A0: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002D8A4: bne         $at, $zero, L_8002D7B0
    if (ctx->r1 != 0) {
        // 0x8002D8A8: nop
    
            goto L_8002D7B0;
    }
    // 0x8002D8A8: nop

L_8002D8AC:
    // 0x8002D8AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D8B0:
    // 0x8002D8B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D8B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D8B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D8BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D8C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D8C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D8C8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D8CC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D8D0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D8D4: jr          $ra
    // 0x8002D8D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D8D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void menu_track_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F23C: jal         0x8006EA90
    // 0x8008F240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008F240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F244: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008F248: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8008F24C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F250: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F254: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8008F258: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008F25C: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8008F260: jal         0x800C73E0
    // 0x8008F264: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8008F264: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x8008F268: bne         $v0, $zero, L_8008F2B0
    if (ctx->r2 != 0) {
        // 0x8008F26C: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008F2B0;
    }
    // 0x8008F26C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F270: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x8008F274: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F278: nop

    // 0x8008F27C: beq         $v0, $zero, L_8008F2B0
    if (ctx->r2 == 0) {
        // 0x8008F280: nop
    
            goto L_8008F2B0;
    }
    // 0x8008F280: nop

    // 0x8008F284: bgez        $v0, L_8008F2A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F288: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8008F2A4;
    }
    // 0x8008F288: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008F28C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008F290: nop

    // 0x8008F294: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8008F298: b           L_8008F2B0
    // 0x8008F29C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8008F2B0;
    // 0x8008F29C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008F2A0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_8008F2A4:
    // 0x8008F2A4: nop

    // 0x8008F2A8: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8008F2AC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8008F2B0:
    // 0x8008F2B0: jal         0x8008E4EC
    // 0x8008F2B4: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008F2B4: nop

    after_2:
    // 0x8008F2B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F2BC: addiu       $a1, $a1, 0x63A0
    ctx->r5 = ADD32(ctx->r5, 0X63A0);
    // 0x8008F2C0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008F2C4: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8008F2C8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8008F2CC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8008F2D0: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8008F2D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F2D8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8008F2DC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008F2E0: lw          $a0, 0x67D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X67D0);
    // 0x8008F2E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F2E8: beq         $a0, $zero, L_8008F300
    if (ctx->r4 == 0) {
        // 0x8008F2EC: nop
    
            goto L_8008F300;
    }
    // 0x8008F2EC: nop

    // 0x8008F2F0: beq         $a0, $at, L_8008F330
    if (ctx->r4 == ctx->r1) {
        // 0x8008F2F4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008F330;
    }
    // 0x8008F2F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F2F8: b           L_8008F350
    // 0x8008F2FC: nop

        goto L_8008F350;
    // 0x8008F2FC: nop

L_8008F300:
    // 0x8008F300: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F304: jal         0x8008FF1C
    // 0x8008F308: nop

    trackmenu_render_names(rdram, ctx);
        goto after_3;
    // 0x8008F308: nop

    after_3:
    // 0x8008F30C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F310: jal         0x800904E8
    // 0x8008F314: nop

    trackmenu_track_view(rdram, ctx);
        goto after_4;
    // 0x8008F314: nop

    after_4:
    // 0x8008F318: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F31C: jal         0x80090918
    // 0x8008F320: nop

    trackmenu_input(rdram, ctx);
        goto after_5;
    // 0x8008F320: nop

    after_5:
    // 0x8008F324: b           L_8008F350
    // 0x8008F328: nop

        goto L_8008F350;
    // 0x8008F328: nop

    // 0x8008F32C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8008F330:
    // 0x8008F330: jal         0x80090ED8
    // 0x8008F334: nop

    trackmenu_timetrial_sound(rdram, ctx);
        goto after_6;
    // 0x8008F334: nop

    after_6:
    // 0x8008F338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F33C: jal         0x80090F30
    // 0x8008F340: nop

    trackmenu_setup_render(rdram, ctx);
        goto after_7;
    // 0x8008F340: nop

    after_7:
    // 0x8008F344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F348: jal         0x80092188
    // 0x8008F34C: nop

    func_80092188(rdram, ctx);
        goto after_8;
    // 0x8008F34C: nop

    after_8:
L_8008F350:
    // 0x8008F350: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F354: addiu       $v1, $v1, -0x8A0
    ctx->r3 = ADD32(ctx->r3, -0X8A0);
    // 0x8008F358: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F35C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F360: bgez        $v0, L_8008F378
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F364: sll         $t8, $t7, 1
        ctx->r24 = S32(ctx->r15 << 1);
            goto L_8008F378;
    }
    // 0x8008F364: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008F368: jal         0x80001990
    // 0x8008F36C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_volume_set(rdram, ctx);
        goto after_9;
    // 0x8008F36C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8008F370: b           L_8008F39C
    // 0x8008F374: nop

        goto L_8008F39C;
    // 0x8008F374: nop

L_8008F378:
    // 0x8008F378: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8008F37C: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x8008F380: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F384: bne         $at, $zero, L_8008F394
    if (ctx->r1 != 0) {
        // 0x8008F388: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8008F394;
    }
    // 0x8008F388: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008F38C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8008F390: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008F394:
    // 0x8008F394: jal         0x80001990
    // 0x8008F398: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_10;
    // 0x8008F398: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_10:
L_8008F39C:
    // 0x8008F39C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F3A0: lw          $v0, 0x67D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67D0);
    // 0x8008F3A4: nop

    // 0x8008F3A8: bgez        $v0, L_8008F468
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F3AC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008F468;
    }
    // 0x8008F3AC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008F3B0: jal         0x8008F534
    // 0x8008F3B4: nop

    menu_track_select_unload(rdram, ctx);
        goto after_11;
    // 0x8008F3B4: nop

    after_11:
    // 0x8008F3B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F3BC: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8008F3C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F3C4: sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
    // 0x8008F3C8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008F3CC: beq         $at, $zero, L_8008F3F0
    if (ctx->r1 == 0) {
        // 0x8008F3D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008F3F0;
    }
    // 0x8008F3D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008F3D4: bne         $v0, $at, L_8008F448
    if (ctx->r2 != ctx->r1) {
        // 0x8008F3D8: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008F448;
    }
    // 0x8008F3D8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008F3DC: lw          $t1, -0x268($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X268);
    // 0x8008F3E0: nop

    // 0x8008F3E4: sll         $t2, $t1, 7
    ctx->r10 = S32(ctx->r9 << 7);
    // 0x8008F3E8: bltz        $t2, L_8008F44C
    if (SIGNED(ctx->r10) < 0) {
        // 0x8008F3EC: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_8008F44C;
    }
    // 0x8008F3EC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F3F0:
    // 0x8008F3F0: jal         0x8009ECD0
    // 0x8008F3F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_12;
    // 0x8008F3F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_12:
    // 0x8008F3F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F3FC: beq         $v0, $zero, L_8008F408
    if (ctx->r2 == 0) {
        // 0x8008F400: nop
    
            goto L_8008F408;
    }
    // 0x8008F400: nop

    // 0x8008F404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008F408:
    // 0x8008F408: jal         0x8009ECB8
    // 0x8008F40C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_13;
    // 0x8008F40C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_13:
    // 0x8008F410: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F414: beq         $v0, $zero, L_8008F424
    if (ctx->r2 == 0) {
        // 0x8008F418: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008F424;
    }
    // 0x8008F418: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008F41C: xori        $t3, $a2, 0x3
    ctx->r11 = ctx->r6 ^ 0X3;
    // 0x8008F420: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_8008F424:
    // 0x8008F424: jal         0x8006E2E8
    // 0x8008F428: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_14;
    // 0x8008F428: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_14:
    // 0x8008F42C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F430: jal         0x8008AEB4
    // 0x8008F434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_15;
    // 0x8008F434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008F438: jal         0x800813D0
    // 0x8008F43C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008F43C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x8008F440: b           L_8008F524
    // 0x8008F444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F524;
    // 0x8008F444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F448:
    // 0x8008F448: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F44C:
    // 0x8008F44C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008F450: jal         0x8006E2E8
    // 0x8008F454: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_17;
    // 0x8008F454: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8008F458: jal         0x800813D0
    // 0x8008F45C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008F45C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_18:
    // 0x8008F460: b           L_8008F524
    // 0x8008F464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F524;
    // 0x8008F464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F468:
    // 0x8008F468: bne         $at, $zero, L_8008F51C
    if (ctx->r1 != 0) {
        // 0x8008F46C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008F51C;
    }
    // 0x8008F46C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F470: jal         0x8008F534
    // 0x8008F474: nop

    menu_track_select_unload(rdram, ctx);
        goto after_19;
    // 0x8008F474: nop

    after_19:
    // 0x8008F478: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008F47C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008F480: lw          $t5, 0x6548($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6548);
    // 0x8008F484: lw          $t4, 0x410($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X410);
    // 0x8008F488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008F48C: beq         $t4, $t5, L_8008F4C4
    if (ctx->r12 == ctx->r13) {
        // 0x8008F490: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008F4C4;
    }
    // 0x8008F490: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008F494: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008F498: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_8008F49C:
    // 0x8008F49C: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8008F4A0: addiu       $t7, $a2, 0x2
    ctx->r15 = ADD32(ctx->r6, 0X2);
    // 0x8008F4A4: addiu       $t8, $a2, 0x3
    ctx->r24 = ADD32(ctx->r6, 0X3);
    // 0x8008F4A8: sb          $a2, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r6;
    // 0x8008F4AC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8008F4B0: sb          $t8, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r24;
    // 0x8008F4B4: sb          $t7, 0x8A($v0)
    MEM_B(0X8A, ctx->r2) = ctx->r15;
    // 0x8008F4B8: sb          $t6, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r14;
    // 0x8008F4BC: bne         $a2, $v1, L_8008F49C
    if (ctx->r6 != ctx->r3) {
        // 0x8008F4C0: addiu       $v0, $v0, 0x60
        ctx->r2 = ADD32(ctx->r2, 0X60);
            goto L_8008F49C;
    }
    // 0x8008F4C0: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
L_8008F4C4:
    // 0x8008F4C4: lw          $t9, 0x69C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69C8);
    // 0x8008F4C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008F4CC: beq         $t9, $at, L_8008F4EC
    if (ctx->r25 == ctx->r1) {
        // 0x8008F4D0: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008F4EC;
    }
    // 0x8008F4D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008F4D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F4D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008F4DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F4E0: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8008F4E4: b           L_8008F524
    // 0x8008F4E8: sw          $t0, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r8;
        goto L_8008F524;
    // 0x8008F4E8: sw          $t0, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r8;
L_8008F4EC:
    // 0x8008F4EC: lw          $t1, 0x69CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X69CC);
    // 0x8008F4F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F4F4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008F4F8: sw          $t2, 0xFE8($at)
    MEM_W(0XFE8, ctx->r1) = ctx->r10;
    // 0x8008F4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F500: sb          $zero, -0xBB0($at)
    MEM_B(-0XBB0, ctx->r1) = 0;
    // 0x8008F504: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F508: sw          $zero, 0xFEC($at)
    MEM_W(0XFEC, ctx->r1) = 0;
    // 0x8008F50C: jal         0x800813D0
    // 0x8008F510: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x8008F510: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_20:
    // 0x8008F514: b           L_8008F524
    // 0x8008F518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F524;
    // 0x8008F518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F51C:
    // 0x8008F51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F520: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_8008F524:
    // 0x8008F524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F52C: jr          $ra
    // 0x8008F530: nop

    return;
    // 0x8008F530: nop

;}
RECOMP_FUNC void object_undo_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F38: bne         $t6, $at, L_80012F8C
    if (ctx->r14 != ctx->r1) {
        // 0x80012F3C: nop
    
            goto L_80012F8C;
    }
    // 0x80012F3C: nop

    // 0x80012F40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012F44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012F48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012F4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012F50: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80012F54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012F58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012F5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012F60: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80012F64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012F68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012F6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F70: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80012F74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012F78: lwc1        $f6, -0x5230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5230);
    // 0x80012F7C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80012F80: nop

    // 0x80012F84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80012F88: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_80012F8C:
    // 0x80012F8C: jr          $ra
    // 0x80012F90: nop

    return;
    // 0x80012F90: nop

;}
RECOMP_FUNC void func_8002E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E904: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8002E908: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002E90C: lw          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F3C);
    // 0x8002E910: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002E914: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002E918: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002E91C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002E920: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002E924: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002E928: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002E92C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002E930: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002E934: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002E938: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002E93C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002E940: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002E944: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002E948: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x8002E94C: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    // 0x8002E950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E954: lwc1        $f0, -0x2F24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002E958: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002E960: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002E964: lwc1        $f2, -0x2F20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x8002E968: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x8002E96C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E970: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002E974: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002E978: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002E97C: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x8002E980: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E984: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002E988: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E98C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002E990: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x8002E994: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E998: addiu       $s6, $s6, -0x4EE0
    ctx->r22 = ADD32(ctx->r22, -0X4EE0);
    // 0x8002E99C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002E9A0: addiu       $s4, $s4, -0x2F44
    ctx->r20 = ADD32(ctx->r20, -0X2F44);
    // 0x8002E9A4: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9A8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9AC: addiu       $s3, $s3, -0x4EE8
    ctx->r19 = ADD32(ctx->r19, -0X4EE8);
    // 0x8002E9B0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002E9B4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8002E9B8: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9BC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9C0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8002E9C4: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002E9C8: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x8002E9CC: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x8002E9D0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002E9D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002E9D8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002E9DC: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x8002E9E0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002E9E4: nop

    // 0x8002E9E8: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002E9EC: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x8002E9F0: lh          $a3, 0x20($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X20);
    // 0x8002E9F4: nop

    // 0x8002E9F8: blez        $a3, L_8002EEB0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8002E9FC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002EEB0;
    }
    // 0x8002E9FC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002EA00: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8002EA04: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002EA08: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8002EA0C: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA10:
    // 0x8002EA10: nop

    // 0x8002EA14: beq         $t6, $zero, L_8002EA44
    if (ctx->r14 == 0) {
        // 0x8002EA18: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA44;
    }
    // 0x8002EA18: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EA1C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA20: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA24: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA28: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EA2C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EA30: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA34: andi        $t9, $v1, 0x2000
    ctx->r25 = ctx->r3 & 0X2000;
    // 0x8002EA38: bne         $t9, $zero, L_8002EA78
    if (ctx->r25 != 0) {
        // 0x8002EA3C: nop
    
            goto L_8002EA78;
    }
    // 0x8002EA3C: nop

    // 0x8002EA40: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
L_8002EA44:
    // 0x8002EA44: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA48: bne         $t6, $zero, L_8002EE94
    if (ctx->r14 != 0) {
        // 0x8002EA4C: nop
    
            goto L_8002EE94;
    }
    // 0x8002EA4C: nop

    // 0x8002EA50: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EA54: lw          $t7, 0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XC);
    // 0x8002EA58: mflo        $t8
    ctx->r24 = lo;
    // 0x8002EA5C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EA60: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002EA64: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x8002EA68: andi        $t9, $v1, 0x6900
    ctx->r25 = ctx->r3 & 0X6900;
    // 0x8002EA6C: bne         $t9, $zero, L_8002EE94
    if (ctx->r25 != 0) {
        // 0x8002EA70: nop
    
            goto L_8002EE94;
    }
    // 0x8002EA70: nop

    // 0x8002EA74: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
L_8002EA78:
    // 0x8002EA78: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8002EA7C: lh          $s7, 0x4($v0)
    ctx->r23 = MEM_H(ctx->r2, 0X4);
    // 0x8002EA80: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x8002EA84: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002EA88: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8002EA8C: srl         $t5, $v1, 19
    ctx->r13 = S32(U32(ctx->r3) >> 19);
    // 0x8002EA90: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002EA94: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8002EA98: andi        $t9, $t5, 0x7
    ctx->r25 = ctx->r13 & 0X7;
    // 0x8002EA9C: slt         $at, $s7, $a0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002EAA0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8002EAA4: beq         $at, $zero, L_8002EE94
    if (ctx->r1 == 0) {
        // 0x8002EAA8: addu        $s1, $t7, $t8
        ctx->r17 = ADD32(ctx->r15, ctx->r24);
            goto L_8002EE94;
    }
    // 0x8002EAA8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EAAC: sll         $ra, $s7, 1
    ctx->r31 = S32(ctx->r23 << 1);
    // 0x8002EAB0: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
L_8002EAB4:
    // 0x8002EAB4: lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X10);
    // 0x8002EAB8: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x8002EABC: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x8002EAC0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EAC4: nop

    // 0x8002EAC8: and         $v0, $t8, $t9
    ctx->r2 = ctx->r24 & ctx->r25;
    // 0x8002EACC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8002EAD0: beq         $t6, $zero, L_8002EE78
    if (ctx->r14 == 0) {
        // 0x8002EAD4: andi        $t7, $v0, 0xFF00
        ctx->r15 = ctx->r2 & 0XFF00;
            goto L_8002EE78;
    }
    // 0x8002EAD4: andi        $t7, $v0, 0xFF00
    ctx->r15 = ctx->r2 & 0XFF00;
    // 0x8002EAD8: beq         $t7, $zero, L_8002EE7C
    if (ctx->r15 == 0) {
        // 0x8002EADC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EE7C;
    }
    // 0x8002EADC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EAE0: lw          $t8, 0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X4);
    // 0x8002EAE4: sll         $t9, $s7, 4
    ctx->r25 = S32(ctx->r23 << 4);
    // 0x8002EAE8: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002EAEC: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x8002EAF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002EAF4: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EAF8: lh          $t0, -0x2F32($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2F32);
    // 0x8002EAFC: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x8002EB00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002EB04: mflo        $t7
    ctx->r15 = lo;
    // 0x8002EB08: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8002EB0C: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002EB10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EB14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002EB18:
    // 0x8002EB18: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EB1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EB20: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EB24: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EB28: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EB2C: lh          $v0, 0x2($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2);
    // 0x8002EB30: nop

    // 0x8002EB34: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EB38: beq         $at, $zero, L_8002EB4C
    if (ctx->r1 == 0) {
        // 0x8002EB3C: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002EB4C;
    }
    // 0x8002EB3C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002EB40: b           L_8002EB58
    // 0x8002EB44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002EB58;
    // 0x8002EB44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002EB48: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002EB4C:
    // 0x8002EB4C: beq         $at, $zero, L_8002EB5C
    if (ctx->r1 == 0) {
        // 0x8002EB50: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8002EB5C;
    }
    // 0x8002EB50: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8002EB54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002EB58:
    // 0x8002EB58: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_8002EB5C:
    // 0x8002EB5C: bne         $at, $zero, L_8002EB18
    if (ctx->r1 != 0) {
        // 0x8002EB60: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8002EB18;
    }
    // 0x8002EB60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EB64: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002EB68: bne         $at, $zero, L_8002EE7C
    if (ctx->r1 != 0) {
        // 0x8002EB6C: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EE7C;
    }
    // 0x8002EB6C: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EB70: lh          $t8, -0x2F34($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2F34);
    // 0x8002EB74: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8002EB78: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002EB7C: bne         $at, $zero, L_8002EE78
    if (ctx->r1 != 0) {
        // 0x8002EB80: addiu       $v0, $sp, 0xD0
        ctx->r2 = ADD32(ctx->r29, 0XD0);
            goto L_8002EE78;
    }
    // 0x8002EB80: addiu       $v0, $sp, 0xD0
    ctx->r2 = ADD32(ctx->r29, 0XD0);
    // 0x8002EB84: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EB88: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EB8C: beq         $v0, $s5, L_8002EBEC
    if (ctx->r2 == ctx->r21) {
        // 0x8002EB90: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EBEC;
    }
    // 0x8002EB90: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EB94:
    // 0x8002EB94: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EB98: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EB9C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EBA0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EBA4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EBA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBAC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EBB0: swc1        $f18, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8002EBB4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EBB8: nop

    // 0x8002EBBC: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EBC0: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EBC4: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EBC8: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EBCC: sh          $s0, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r16;
    // 0x8002EBD0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EBD4: nop

    // 0x8002EBD8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EBDC: swc1        $f18, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f18.u32l;
    // 0x8002EBE0: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8002EBE4: bne         $v0, $s5, L_8002EB94
    if (ctx->r2 != ctx->r21) {
        // 0x8002EBE8: multu       $t9, $s2
        result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
            goto L_8002EB94;
    }
    // 0x8002EBE8: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8002EBEC:
    // 0x8002EBEC: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EBF0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EBF4: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002EBF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EBFC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC00: nop

    // 0x8002EC04: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC08: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC0C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002EC10: nop

    // 0x8002EC14: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002EC18: mflo        $t6
    ctx->r14 = lo;
    // 0x8002EC1C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8002EC20: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002EC24: sh          $s0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r16;
    // 0x8002EC28: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8002EC2C: nop

    // 0x8002EC30: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EC34: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8002EC38: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002EC3C: lwc1        $f14, 0xC4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002EC40: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x8002EC44: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8002EC48: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002EC4C: addiu       $t6, $sp, 0xD0
    ctx->r14 = ADD32(ctx->r29, 0XD0);
    // 0x8002EC50: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002EC54: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002EC58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002EC5C: jal         0x8002FD74
    // 0x8002EC60: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FD74(rdram, ctx);
        goto after_0;
    // 0x8002EC60: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_0:
    // 0x8002EC64: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002EC68: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002EC6C: beq         $v0, $zero, L_8002EE7C
    if (ctx->r2 == 0) {
        // 0x8002EC70: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EE7C;
    }
    // 0x8002EC70: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002EC74: lw          $t7, 0x14($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X14);
    // 0x8002EC78: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002EC7C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EC80: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x8002EC84: lw          $t7, 0x18($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X18);
    // 0x8002EC88: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8002EC8C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002EC90: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EC94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002EC98: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8002EC9C: lw          $t6, 0x18($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X18);
    // 0x8002ECA0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002ECA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002ECA8: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002ECAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ECB0: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x8002ECB4: nop

    // 0x8002ECB8: bc1t        L_8002EE7C
    if (c1cs) {
        // 0x8002ECBC: lw          $t7, 0xA4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XA4);
            goto L_8002EE7C;
    }
    // 0x8002ECBC: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8002ECC0: lwc1        $f10, -0x2F10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2F10);
    // 0x8002ECC4: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8002ECC8: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x8002ECCC: nop

    // 0x8002ECD0: bc1f        L_8002ECF0
    if (!c1cs) {
        // 0x8002ECD4: nop
    
            goto L_8002ECF0;
    }
    // 0x8002ECD4: nop

    // 0x8002ECD8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ECDC: jal         0x800304C8
    // 0x8002ECE0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_800304C8(rdram, ctx);
        goto after_1;
    // 0x8002ECE0: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_1:
    // 0x8002ECE4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ECE8: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ECEC: nop

L_8002ECF0:
    // 0x8002ECF0: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002ECF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002ECF8: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x8002ECFC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002ED00: addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // 0x8002ED04: jal         0x8002FF6C
    // 0x8002ED08: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    func_8002FF6C(rdram, ctx);
        goto after_2;
    // 0x8002ED08: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    after_2:
    // 0x8002ED0C: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8002ED10: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8002ED14: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002ED18: bne         $at, $zero, L_8002EE78
    if (ctx->r1 != 0) {
        // 0x8002ED1C: or          $t4, $v0, $zero
        ctx->r12 = ctx->r2 | 0;
            goto L_8002EE78;
    }
    // 0x8002ED1C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8002ED20: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8002ED24: lw          $t3, -0x3DD0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3DD0);
    // 0x8002ED28: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ED2C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8002ED30: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8002ED34: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002ED38: addiu       $t6, $t6, -0x3DC8
    ctx->r14 = ADD32(ctx->r14, -0X3DC8);
    // 0x8002ED3C: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002ED40: sb          $zero, 0x1($t2)
    MEM_B(0X1, ctx->r10) = 0;
    // 0x8002ED44: blez        $v0, L_8002EE44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002ED48: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002EE44;
    }
    // 0x8002ED48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002ED4C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
L_8002ED50:
    // 0x8002ED50: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002ED54: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x8002ED58: bgez        $v1, L_8002EE24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002ED5C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002EE24;
    }
    // 0x8002ED5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002ED60: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8002ED64: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8002ED68: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8002ED6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002ED70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002ED74: addiu       $t9, $t9, -0x3DC8
    ctx->r25 = ADD32(ctx->r25, -0X3DC8);
    // 0x8002ED78: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8002ED7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002ED80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002ED84: blez        $a2, L_8002EDE8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002ED88: addu        $t1, $t8, $t9
        ctx->r9 = ADD32(ctx->r24, ctx->r25);
            goto L_8002EDE8;
    }
    // 0x8002ED88: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8002ED8C: sll         $t6, $zero, 4
    ctx->r14 = S32(0 << 4);
    // 0x8002ED90: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002ED94: addu        $v1, $s6, $t6
    ctx->r3 = ADD32(ctx->r22, ctx->r14);
L_8002ED98:
    // 0x8002ED98: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002ED9C: nop

    // 0x8002EDA0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x8002EDA4: nop

    // 0x8002EDA8: bc1f        L_8002EDD0
    if (!c1cs) {
        // 0x8002EDAC: nop
    
            goto L_8002EDD0;
    }
    // 0x8002EDAC: nop

    // 0x8002EDB0: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002EDB4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EDB8: nop

    // 0x8002EDBC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8002EDC0: nop

    // 0x8002EDC4: bc1f        L_8002EDD0
    if (!c1cs) {
        // 0x8002EDC8: nop
    
            goto L_8002EDD0;
    }
    // 0x8002EDC8: nop

    // 0x8002EDCC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8002EDD0:
    // 0x8002EDD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002EDD4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002EDD8: beq         $at, $zero, L_8002EDE8
    if (ctx->r1 == 0) {
        // 0x8002EDDC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002EDE8;
    }
    // 0x8002EDDC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002EDE0: beq         $a1, $s0, L_8002ED98
    if (ctx->r5 == ctx->r16) {
        // 0x8002EDE4: nop
    
            goto L_8002ED98;
    }
    // 0x8002EDE4: nop

L_8002EDE8:
    // 0x8002EDE8: bne         $a1, $s0, L_8002EE1C
    if (ctx->r5 != ctx->r16) {
        // 0x8002EDEC: sll         $t7, $a2, 4
        ctx->r15 = S32(ctx->r6 << 4);
            goto L_8002EE1C;
    }
    // 0x8002EDEC: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002EDF0: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002EDF4: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002EDF8: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002EDFC: addu        $v1, $s6, $t7
    ctx->r3 = ADD32(ctx->r22, ctx->r15);
    // 0x8002EE00: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    // 0x8002EE04: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002EE08: sb          $a2, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r6;
    // 0x8002EE0C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8002EE10: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8002EE14: b           L_8002EE38
    // 0x8002EE18: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_8002EE38;
    // 0x8002EE18: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_8002EE1C:
    // 0x8002EE1C: b           L_8002EE38
    // 0x8002EE20: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
        goto L_8002EE38;
    // 0x8002EE20: sb          $a1, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r5;
L_8002EE24:
    // 0x8002EE24: sb          $v1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r3;
    // 0x8002EE28: lbu         $t7, 0x1($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X1);
    // 0x8002EE2C: sllv        $t9, $t8, $t0
    ctx->r25 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x8002EE30: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8002EE34: sb          $t6, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r14;
L_8002EE38:
    // 0x8002EE38: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EE3C: bne         $t0, $t4, L_8002ED50
    if (ctx->r8 != ctx->r12) {
        // 0x8002EE40: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002ED50;
    }
    // 0x8002EE40: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002EE44:
    // 0x8002EE44: sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // 0x8002EE48: sh          $t5, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r13;
    // 0x8002EE4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002EE50: lw          $v1, -0x2F18($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2F18);
    // 0x8002EE54: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x8002EE58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EE5C: bltz        $v1, L_8002EE70
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002EE60: sw          $t8, -0x3DD0($at)
        MEM_W(-0X3DD0, ctx->r1) = ctx->r24;
            goto L_8002EE70;
    }
    // 0x8002EE60: sw          $t8, -0x3DD0($at)
    MEM_W(-0X3DD0, ctx->r1) = ctx->r24;
    // 0x8002EE64: beq         $t5, $v1, L_8002EE70
    if (ctx->r13 == ctx->r3) {
        // 0x8002EE68: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002EE70;
    }
    // 0x8002EE68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EE6C: sw          $zero, -0x2F14($at)
    MEM_W(-0X2F14, ctx->r1) = 0;
L_8002EE70:
    // 0x8002EE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EE74: sw          $t5, -0x2F18($at)
    MEM_W(-0X2F18, ctx->r1) = ctx->r13;
L_8002EE78:
    // 0x8002EE78: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
L_8002EE7C:
    // 0x8002EE7C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002EE80: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002EE84: bne         $at, $zero, L_8002EAB4
    if (ctx->r1 != 0) {
        // 0x8002EE88: addiu       $ra, $ra, 0x2
        ctx->r31 = ADD32(ctx->r31, 0X2);
            goto L_8002EAB4;
    }
    // 0x8002EE88: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x8002EE8C: lh          $a3, 0x20($fp)
    ctx->r7 = MEM_H(ctx->r30, 0X20);
    // 0x8002EE90: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8002EE94:
    // 0x8002EE94: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8002EE98: nop

    // 0x8002EE9C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002EEA0: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002EEA4: bne         $at, $zero, L_8002EA10
    if (ctx->r1 != 0) {
        // 0x8002EEA8: lw          $t6, 0x158($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X158);
            goto L_8002EA10;
    }
    // 0x8002EEA8: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8002EEAC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002EEB0:
    // 0x8002EEB0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002EEB4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002EEB8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002EEBC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002EEC0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002EEC4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002EEC8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002EECC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002EED0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002EED4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002EED8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002EEDC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002EEE0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002EEE4: jr          $ra
    // 0x8002EEE8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8002EEE8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void move_particle_forward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3564: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B3568: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B356C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800B3570: addiu       $s3, $s3, 0x7C80
    ctx->r19 = ADD32(ctx->r19, 0X7C80);
    // 0x800B3574: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800B3578: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B357C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3580: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B3588: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B358C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3590: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B3594: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B3598: beq         $t6, $zero, L_800B3654
    if (ctx->r14 == 0) {
        // 0x800B359C: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B3654;
    }
    // 0x800B359C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B35A0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B35A4: addiu       $s2, $a0, 0x1C
    ctx->r18 = ADD32(ctx->r4, 0X1C);
L_800B35A8:
    // 0x800B35A8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B35AC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x800B35B0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B35B4: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x800B35B8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B35BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B35C0: jal         0x80070490
    // 0x800B35C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800B35C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800B35C8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B35CC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B35D0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B35D4: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B35D8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B35DC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B35E0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800B35E4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B35E8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B35EC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B35F0: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B35F4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B35F8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B35FC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B3600: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B3604: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3608: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B360C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B3610: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B3614: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800B3618: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B361C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3620: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B3624: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3628: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B362C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800B3630: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800B3634: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3638: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B363C: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B3640: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800B3644: nop

    // 0x800B3648: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B364C: bne         $v0, $zero, L_800B35A8
    if (ctx->r2 != 0) {
        // 0x800B3650: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B35A8;
    }
    // 0x800B3650: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B3654:
    // 0x800B3654: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3658: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B365C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B3660: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3664: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3668: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B366C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3670: jr          $ra
    // 0x800B3674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B3674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D53C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003D540: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D544: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003D548: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003D54C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D550: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003D554: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003D558: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003D55C: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003D560: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003D564: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003D568: sh          $t1, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r9;
    // 0x8003D56C: sh          $t2, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = ctx->r10;
    // 0x8003D570: jal         0x8009C30C
    // 0x8003D574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003D574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003D578: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003D57C: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x8003D580: beq         $t3, $zero, L_8003D594
    if (ctx->r11 == 0) {
        // 0x8003D584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D594;
    }
    // 0x8003D584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D588: jal         0x8000FFB8
    // 0x8003D58C: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D58C: nop

    after_1:
    // 0x8003D590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D594:
    // 0x8003D594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D598: jr          $ra
    // 0x8003D59C: nop

    return;
    // 0x8003D59C: nop

;}
RECOMP_FUNC void mempool_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80070D18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80070D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80070D24: jal         0x80070D3C
    // 0x80070D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x80070D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80070D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D34: jr          $ra
    // 0x80070D38: nop

    return;
    // 0x80070D38: nop

;}
RECOMP_FUNC void mode_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006CCF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006CCF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006CCFC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006CD00: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8006CD04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006CD08: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006CD0C: jal         0x8009C3D8
    // 0x8006CD10: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    get_active_player_count(rdram, ctx);
        goto after_0;
    // 0x8006CD10: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x8006CD14: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006CD18: nop

    // 0x8006CD1C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CD20: beq         $at, $zero, L_8006CD70
    if (ctx->r1 == 0) {
        // 0x8006CD24: nop
    
            goto L_8006CD70;
    }
    // 0x8006CD24: nop

    // 0x8006CD28: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CD2C:
    // 0x8006CD2C: jal         0x8006A528
    // 0x8006CD30: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x8006CD30: nop

    after_1:
    // 0x8006CD34: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006CD38: jal         0x8006A554
    // 0x8006CD3C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8006CD3C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    after_2:
    // 0x8006CD40: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006CD44: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CD48: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8006CD4C: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8006CD50: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8006CD54: jal         0x8009C3D8
    // 0x8006CD58: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    get_active_player_count(rdram, ctx);
        goto after_3;
    // 0x8006CD58: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    after_3:
    // 0x8006CD5C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8006CD60: nop

    // 0x8006CD64: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006CD68: bne         $at, $zero, L_8006CD2C
    if (ctx->r1 != 0) {
        // 0x8006CD6C: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_8006CD2C;
    }
    // 0x8006CD6C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_8006CD70:
    // 0x8006CD70: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CD74: lb          $t3, -0x2C8C($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2C8C);
    // 0x8006CD78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CD7C: beq         $t3, $zero, L_8006CD8C
    if (ctx->r11 == 0) {
        // 0x8006CD80: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006CD8C;
    }
    // 0x8006CD80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CD84: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x8006CD88: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
L_8006CD8C:
    // 0x8006CD8C: lb          $t6, 0x3515($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3515);
    // 0x8006CD90: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006CD94: bne         $t6, $zero, L_8006CE60
    if (ctx->r14 != 0) {
        // 0x8006CD98: nop
    
            goto L_8006CE60;
    }
    // 0x8006CD98: nop

    // 0x8006CD9C: jal         0x80010994
    // 0x8006CDA0: nop

    obj_update(rdram, ctx);
        goto after_4;
    // 0x8006CDA0: nop

    after_4:
    // 0x8006CDA4: jal         0x80066510
    // 0x8006CDA8: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_5;
    // 0x8006CDA8: nop

    after_5:
    // 0x8006CDAC: beq         $v0, $zero, L_8006CDC8
    if (ctx->r2 == 0) {
        // 0x8006CDB0: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_8006CDC8;
    }
    // 0x8006CDB0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CDB4: jal         0x8001139C
    // 0x8006CDB8: nop

    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x8006CDB8: nop

    after_6:
    // 0x8006CDBC: beq         $v0, $zero, L_8006CE44
    if (ctx->r2 == 0) {
        // 0x8006CDC0: nop
    
            goto L_8006CE44;
    }
    // 0x8006CDC0: nop

    // 0x8006CDC4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_8006CDC8:
    // 0x8006CDC8: nop

    // 0x8006CDCC: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8006CDD0: beq         $t8, $zero, L_8006CE44
    if (ctx->r24 == 0) {
        // 0x8006CDD4: nop
    
            goto L_8006CE44;
    }
    // 0x8006CDD4: nop

    // 0x8006CDD8: jal         0x8006C2F0
    // 0x8006CDDC: nop

    level_properties_get(rdram, ctx);
        goto after_7;
    // 0x8006CDDC: nop

    after_7:
    // 0x8006CDE0: bne         $v0, $zero, L_8006CE44
    if (ctx->r2 != 0) {
        // 0x8006CDE4: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8006CE44;
    }
    // 0x8006CDE4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006CDE8: lb          $t9, -0x2C70($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2C70);
    // 0x8006CDEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CDF0: bne         $t9, $zero, L_8006CE44
    if (ctx->r25 != 0) {
        // 0x8006CDF4: nop
    
            goto L_8006CE44;
    }
    // 0x8006CDF4: nop

    // 0x8006CDF8: lw          $t1, 0x34EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X34EC);
    // 0x8006CDFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006CE00: bne         $t1, $zero, L_8006CE44
    if (ctx->r9 != 0) {
        // 0x8006CE04: nop
    
            goto L_8006CE44;
    }
    // 0x8006CE04: nop

    // 0x8006CE08: lb          $t2, 0x3516($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X3516);
    // 0x8006CE0C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CE10: bne         $t2, $zero, L_8006CE44
    if (ctx->r10 != 0) {
        // 0x8006CE14: nop
    
            goto L_8006CE44;
    }
    // 0x8006CE14: nop

    // 0x8006CE18: lh          $t3, -0x2C6C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2C6C);
    // 0x8006CE1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CE20: bne         $t3, $zero, L_8006CE44
    if (ctx->r11 != 0) {
        // 0x8006CE24: addiu       $a0, $a0, -0x2C68
        ctx->r4 = ADD32(ctx->r4, -0X2C68);
            goto L_8006CE44;
    }
    // 0x8006CE24: addiu       $a0, $a0, -0x2C68
    ctx->r4 = ADD32(ctx->r4, -0X2C68);
    // 0x8006CE28: lb          $t4, 0x0($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X0);
    // 0x8006CE2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006CE30: bne         $t4, $zero, L_8006CE44
    if (ctx->r12 != 0) {
        // 0x8006CE34: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006CE44;
    }
    // 0x8006CE34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CE38: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8006CE3C: jal         0x80093A40
    // 0x8006CE40: sb          $t5, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = ctx->r13;
    menu_pause_init(rdram, ctx);
        goto after_8;
    // 0x8006CE40: sb          $t5, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = ctx->r13;
    after_8:
L_8006CE44:
    // 0x8006CE44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CE48: addiu       $a0, $a0, -0x2C68
    ctx->r4 = ADD32(ctx->r4, -0X2C68);
    // 0x8006CE4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CE50: lb          $v0, 0x3516($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3516);
    // 0x8006CE54: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006CE58: b           L_8006CE84
    // 0x8006CE5C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
        goto L_8006CE84;
    // 0x8006CE5C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006CE60:
    // 0x8006CE60: jal         0x80028FA0
    // 0x8006CE64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_9;
    // 0x8006CE64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8006CE68: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CE6C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006CE70: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CE74: lb          $v1, -0x2C68($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2C68);
    // 0x8006CE78: lb          $v0, 0x3516($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3516);
    // 0x8006CE7C: addiu       $a0, $a0, -0x2C68
    ctx->r4 = ADD32(ctx->r4, -0X2C68);
    // 0x8006CE80: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_8006CE84:
    // 0x8006CE84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CE88: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8006CE8C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8006CE90: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8006CE94: nop

    // 0x8006CE98: bgez        $t8, L_8006CEA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006CE9C: nop
    
            goto L_8006CEA4;
    }
    // 0x8006CE9C: nop

    // 0x8006CEA0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8006CEA4:
    // 0x8006CEA4: beq         $v0, $zero, L_8006CEB0
    if (ctx->r2 == 0) {
        // 0x8006CEA8: nop
    
            goto L_8006CEB0;
    }
    // 0x8006CEA8: nop

    // 0x8006CEAC: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
L_8006CEB0:
    // 0x8006CEB0: jal         0x8001004C
    // 0x8006CEB4: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8006CEB4: nop

    after_10:
    // 0x8006CEB8: jal         0x8001BF20
    // 0x8006CEBC: nop

    ainode_update(rdram, ctx);
        goto after_11;
    // 0x8006CEBC: nop

    after_11:
    // 0x8006CEC0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006CEC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CEC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CECC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CED0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006CED4: addiu       $a3, $a3, 0x1228
    ctx->r7 = ADD32(ctx->r7, 0X1228);
    // 0x8006CED8: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006CEDC: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006CEE0: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006CEE4: jal         0x80024D54
    // 0x8006CEE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_scene(rdram, ctx);
        goto after_12;
    // 0x8006CEE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_12:
    // 0x8006CEEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CEF0: lw          $t1, 0x34EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X34EC);
    // 0x8006CEF4: addiu       $at, $zero, -0x2031
    ctx->r1 = ADD32(0, -0X2031);
    // 0x8006CEF8: bne         $t1, $zero, L_8006CF08
    if (ctx->r9 != 0) {
        // 0x8006CEFC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006CF08;
    }
    // 0x8006CEFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006CF00: and         $t2, $s0, $at
    ctx->r10 = ctx->r16 & ctx->r1;
    // 0x8006CF04: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006CF08:
    // 0x8006CF08: lb          $t3, 0x3516($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X3516);
    // 0x8006CF0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CF10: beq         $t3, $zero, L_8006D024
    if (ctx->r11 == 0) {
        // 0x8006CF14: addiu       $a0, $a0, 0x11F8
        ctx->r4 = ADD32(ctx->r4, 0X11F8);
            goto L_8006D024;
    }
    // 0x8006CF14: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006CF18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CF1C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CF20: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006CF24: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006CF28: jal         0x80095728
    // 0x8006CF2C: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    menu_postrace(rdram, ctx);
        goto after_13;
    // 0x8006CF2C: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    after_13:
    // 0x8006CF30: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8006CF34: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x8006CF38: beq         $at, $zero, L_8006D024
    if (ctx->r1 == 0) {
        // 0x8006CF3C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D024;
    }
    // 0x8006CF3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006CF40: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006CF44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CF48: addu        $at, $at, $t4
    gpr jr_addend_8006CF54 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006CF4C: lw          $t4, 0x7154($at)
    ctx->r12 = ADD32(ctx->r1, 0X7154);
    // 0x8006CF50: nop

    // 0x8006CF54: jr          $t4
    // 0x8006CF58: nop

    switch (jr_addend_8006CF54 >> 2) {
        case 0: goto L_8006CF68; break;
        case 1: goto L_8006CF5C; break;
        case 2: goto L_8006D024; break;
        case 3: goto L_8006CF80; break;
        case 4: goto L_8006CF9C; break;
        case 5: goto L_8006D024; break;
        case 6: goto L_8006D024; break;
        case 7: goto L_8006CFB0; break;
        case 8: goto L_8006CFC4; break;
        case 9: goto L_8006CFD8; break;
        case 10: goto L_8006CFEC; break;
        case 11: goto L_8006D000; break;
        case 12: goto L_8006D014; break;
        default: switch_error(__func__, 0x8006CF54, 0x800E7154);
    }
    // 0x8006CF58: nop

L_8006CF5C:
    // 0x8006CF5C: ori         $t5, $s0, 0x2020
    ctx->r13 = ctx->r16 | 0X2020;
    // 0x8006CF60: b           L_8006D024
    // 0x8006CF64: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8006D024;
    // 0x8006CF64: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8006CF68:
    // 0x8006CF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CF6C: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    // 0x8006CF70: jal         0x8006D8F0
    // 0x8006CF74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8006D8F0(rdram, ctx);
        goto after_14;
    // 0x8006CF74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_14:
    // 0x8006CF78: b           L_8006D028
    // 0x8006CF7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
        goto L_8006D028;
    // 0x8006CF7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006CF80:
    // 0x8006CF80: jal         0x8006C2E4
    // 0x8006CF84: nop

    level_properties_reset(rdram, ctx);
        goto after_15;
    // 0x8006CF84: nop

    after_15:
    // 0x8006CF88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CF8C: ori         $t6, $s0, 0x30
    ctx->r14 = ctx->r16 | 0X30;
    // 0x8006CF90: sb          $zero, -0x2C70($at)
    MEM_B(-0X2C70, ctx->r1) = 0;
    // 0x8006CF94: b           L_8006D024
    // 0x8006CF98: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D024;
    // 0x8006CF98: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006CF9C:
    // 0x8006CF9C: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006CFA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006CFA4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8006CFA8: b           L_8006D024
    // 0x8006CFAC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D024;
    // 0x8006CFAC: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006CFB0:
    // 0x8006CFB0: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006CFB4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006CFB8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8006CFBC: b           L_8006D024
    // 0x8006CFC0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D024;
    // 0x8006CFC0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006CFC4:
    // 0x8006CFC4: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006CFC8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006CFCC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8006CFD0: b           L_8006D024
    // 0x8006CFD4: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D024;
    // 0x8006CFD4: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006CFD8:
    // 0x8006CFD8: ori         $t4, $s0, 0x20
    ctx->r12 = ctx->r16 | 0X20;
    // 0x8006CFDC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8006CFE0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8006CFE4: b           L_8006D024
    // 0x8006CFE8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
        goto L_8006D024;
    // 0x8006CFE8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_8006CFEC:
    // 0x8006CFEC: ori         $t6, $s0, 0x20
    ctx->r14 = ctx->r16 | 0X20;
    // 0x8006CFF0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8006CFF4: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8006CFF8: b           L_8006D024
    // 0x8006CFFC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D024;
    // 0x8006CFFC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D000:
    // 0x8006D000: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D004: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8006D008: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8006D00C: b           L_8006D024
    // 0x8006D010: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_8006D024;
    // 0x8006D010: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8006D014:
    // 0x8006D014: ori         $t1, $s0, 0x20
    ctx->r9 = ctx->r16 | 0X20;
    // 0x8006D018: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8006D01C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x8006D020: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8006D024:
    // 0x8006D024: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_8006D028:
    // 0x8006D028: jal         0x800C3440
    // 0x8006D02C: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_16;
    // 0x8006D02C: nop

    after_16:
    // 0x8006D030: jal         0x800C3400
    // 0x8006D034: nop

    textbox_visible(rdram, ctx);
        goto after_17;
    // 0x8006D034: nop

    after_17:
    // 0x8006D038: beq         $v0, $zero, L_8006D070
    if (ctx->r2 == 0) {
        // 0x8006D03C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D070;
    }
    // 0x8006D03C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D040: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D044: bne         $v0, $at, L_8006D054
    if (ctx->r2 != ctx->r1) {
        // 0x8006D048: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8006D054;
    }
    // 0x8006D048: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D04C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D050: sb          $t3, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = ctx->r11;
L_8006D054:
    // 0x8006D054: jal         0x800C3400
    // 0x8006D058: nop

    textbox_visible(rdram, ctx);
        goto after_18;
    // 0x8006D058: nop

    after_18:
    // 0x8006D05C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D060: beq         $v0, $at, L_8006D070
    if (ctx->r2 == ctx->r1) {
        // 0x8006D064: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D070;
    }
    // 0x8006D064: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D068: jal         0x800945E4
    // 0x8006D06C: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_19;
    // 0x8006D06C: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    after_19:
L_8006D070:
    extern void dkr_quick_restart_poll(uint8_t*, recomp_context*); dkr_quick_restart_poll(rdram, ctx);
    // 0x8006D070: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006D074: lb          $t4, 0x3515($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X3515);
    // 0x8006D078: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8006D07C: beq         $t4, $zero, L_8006D1C0
    if (ctx->r12 == 0) {
        // 0x8006D080: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D1C0;
    }
    // 0x8006D080: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D084: jal         0x80094170
    // 0x8006D088: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    menu_pause_loop(rdram, ctx);
        goto after_20;
    // 0x8006D088: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_20:
    // 0x8006D08C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8006D090: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x8006D094: beq         $at, $zero, L_8006D1C0
    if (ctx->r1 == 0) {
        // 0x8006D098: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D1C0;
    }
    // 0x8006D098: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D09C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006D0A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D0A4: addu        $at, $at, $t5
    gpr jr_addend_8006D0B0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8006D0A8: lw          $t5, 0x7188($at)
    ctx->r13 = ADD32(ctx->r1, 0X7188);
    // 0x8006D0AC: nop

    // 0x8006D0B0: jr          $t5
    // 0x8006D0B4: nop

    switch (jr_addend_8006D0B0 >> 2) {
        case 0: goto L_8006D0B8; break;
        case 1: goto L_8006D0C4; break;
        case 2: goto L_8006D108; break;
        case 3: goto L_8006D19C; break;
        case 4: goto L_8006D14C; break;
        case 5: goto L_8006D17C; break;
        case 6: goto L_8006D188; break;
        case 7: goto L_8006D1C0; break;
        case 8: goto L_8006D1C0; break;
        case 9: goto L_8006D1C0; break;
        case 10: goto L_8006D1C0; break;
        case 11: goto L_8006D164; break;
        default: switch_error(__func__, 0x8006D0B0, 0x800E7188);
    }
    // 0x8006D0B4: nop

L_8006D0B8:
    // 0x8006D0B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D0BC: b           L_8006D1C0
    // 0x8006D0C0: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
        goto L_8006D1C0;
    // 0x8006D0C0: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
L_8006D0C4:
    // 0x8006D0C4: jal         0x80001050
    // 0x8006D0C8: nop

    sound_clear_delayed(rdram, ctx);
        goto after_21;
    // 0x8006D0C8: nop

    after_21:
    // 0x8006D0CC: jal         0x800C314C
    // 0x8006D0D0: nop

    reset_delayed_text(rdram, ctx);
        goto after_22;
    // 0x8006D0D0: nop

    after_22:
    // 0x8006D0D4: jal         0x80023568
    // 0x8006D0D8: nop

    func_80023568(rdram, ctx);
        goto after_23;
    // 0x8006D0D8: nop

    after_23:
    // 0x8006D0DC: beq         $v0, $zero, L_8006D100
    if (ctx->r2 == 0) {
        // 0x8006D0E0: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D100;
    }
    // 0x8006D0E0: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D0E4: jal         0x8009EC80
    // 0x8006D0E8: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8006D0E8: nop

    after_24:
    // 0x8006D0EC: beq         $v0, $zero, L_8006D100
    if (ctx->r2 == 0) {
        // 0x8006D0F0: ori         $t6, $s0, 0x2020
        ctx->r14 = ctx->r16 | 0X2020;
            goto L_8006D100;
    }
    // 0x8006D0F0: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
    // 0x8006D0F4: jal         0x8006F398
    // 0x8006D0F8: nop

    swap_lead_player(rdram, ctx);
        goto after_25;
    // 0x8006D0F8: nop

    after_25:
    // 0x8006D0FC: ori         $t6, $s0, 0x2020
    ctx->r14 = ctx->r16 | 0X2020;
L_8006D100:
    // 0x8006D100: b           L_8006D1C0
    // 0x8006D104: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_8006D1C0;
    // 0x8006D104: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_8006D108:
    // 0x8006D108: jal         0x80001050
    // 0x8006D10C: nop

    sound_clear_delayed(rdram, ctx);
        goto after_26;
    // 0x8006D10C: nop

    after_26:
    // 0x8006D110: jal         0x800C314C
    // 0x8006D114: nop

    reset_delayed_text(rdram, ctx);
        goto after_27;
    // 0x8006D114: nop

    after_27:
    // 0x8006D118: jal         0x80023568
    // 0x8006D11C: nop

    func_80023568(rdram, ctx);
        goto after_28;
    // 0x8006D11C: nop

    after_28:
    // 0x8006D120: beq         $v0, $zero, L_8006D144
    if (ctx->r2 == 0) {
        // 0x8006D124: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D144;
    }
    // 0x8006D124: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D128: jal         0x8009EC80
    // 0x8006D12C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_29;
    // 0x8006D12C: nop

    after_29:
    // 0x8006D130: beq         $v0, $zero, L_8006D144
    if (ctx->r2 == 0) {
        // 0x8006D134: ori         $t7, $s0, 0x20
        ctx->r15 = ctx->r16 | 0X20;
            goto L_8006D144;
    }
    // 0x8006D134: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
    // 0x8006D138: jal         0x8006F398
    // 0x8006D13C: nop

    swap_lead_player(rdram, ctx);
        goto after_30;
    // 0x8006D13C: nop

    after_30:
    // 0x8006D140: ori         $t7, $s0, 0x20
    ctx->r15 = ctx->r16 | 0X20;
L_8006D144:
    // 0x8006D144: b           L_8006D1C0
    // 0x8006D148: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8006D1C0;
    // 0x8006D148: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8006D14C:
    // 0x8006D14C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D150: jal         0x800C314C
    // 0x8006D154: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    reset_delayed_text(rdram, ctx);
        goto after_31;
    // 0x8006D154: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_31:
    // 0x8006D158: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D15C: b           L_8006D1C0
    // 0x8006D160: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
        goto L_8006D1C0;
    // 0x8006D160: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8006D164:
    // 0x8006D164: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8006D168: jal         0x800C314C
    // 0x8006D16C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    reset_delayed_text(rdram, ctx);
        goto after_32;
    // 0x8006D16C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_32:
    // 0x8006D170: ori         $t2, $s0, 0x20
    ctx->r10 = ctx->r16 | 0X20;
    // 0x8006D174: b           L_8006D1C0
    // 0x8006D178: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
        goto L_8006D1C0;
    // 0x8006D178: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8006D17C:
    // 0x8006D17C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D180: b           L_8006D1C0
    // 0x8006D184: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
        goto L_8006D1C0;
    // 0x8006D184: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
L_8006D188:
    // 0x8006D188: jal         0x80022E18
    // 0x8006D18C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mode_end_taj_race(rdram, ctx);
        goto after_33;
    // 0x8006D18C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_33:
    // 0x8006D190: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D194: b           L_8006D1C0
    // 0x8006D198: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
        goto L_8006D1C0;
    // 0x8006D198: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
L_8006D19C:
    // 0x8006D19C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D1A0: jal         0x80001050
    // 0x8006D1A4: sb          $zero, -0x2C70($at)
    MEM_B(-0X2C70, ctx->r1) = 0;
    sound_clear_delayed(rdram, ctx);
        goto after_34;
    // 0x8006D1A4: sb          $zero, -0x2C70($at)
    MEM_B(-0X2C70, ctx->r1) = 0;
    after_34:
    // 0x8006D1A8: jal         0x800C314C
    // 0x8006D1AC: nop

    reset_delayed_text(rdram, ctx);
        goto after_35;
    // 0x8006D1AC: nop

    after_35:
    // 0x8006D1B0: jal         0x8006C2E4
    // 0x8006D1B4: nop

    level_properties_reset(rdram, ctx);
        goto after_36;
    // 0x8006D1B4: nop

    after_36:
    // 0x8006D1B8: ori         $t3, $s0, 0x30
    ctx->r11 = ctx->r16 | 0X30;
    // 0x8006D1BC: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_8006D1C0:
    // 0x8006D1C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D1C4: jal         0x80078054
    // 0x8006D1C8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    rdp_init(rdram, ctx);
        goto after_37;
    // 0x8006D1C8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_37:
    // 0x8006D1CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D1D0: jal         0x80077050
    // 0x8006D1D4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    divider_draw(rdram, ctx);
        goto after_38;
    // 0x8006D1D4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_38:
    // 0x8006D1D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D1DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D1E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D1E4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006D1E8: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006D1EC: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006D1F0: jal         0x800A8474
    // 0x8006D1F4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    hud_render_general(rdram, ctx);
        goto after_39;
    // 0x8006D1F4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_39:
    // 0x8006D1F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D1FC: jal         0x80077268
    // 0x8006D200: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    divider_clear_coverage(rdram, ctx);
        goto after_40;
    // 0x8006D200: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_40:
    // 0x8006D204: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006D208: lb          $t4, -0x2C64($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X2C64);
    // 0x8006D20C: nop

    // 0x8006D210: beq         $t4, $zero, L_8006D24C
    if (ctx->r12 == 0) {
        // 0x8006D214: nop
    
            goto L_8006D24C;
    }
    // 0x8006D214: nop

    // 0x8006D218: jal         0x800214C4
    // 0x8006D21C: nop

    func_800214C4(rdram, ctx);
        goto after_41;
    // 0x8006D21C: nop

    after_41:
    // 0x8006D220: beq         $v0, $zero, L_8006D24C
    if (ctx->r2 == 0) {
        // 0x8006D224: addiu       $t5, $zero, 0x23
        ctx->r13 = ADD32(0, 0X23);
            goto L_8006D24C;
    }
    // 0x8006D224: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x8006D228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D22C: sw          $t5, 0x34F4($at)
    MEM_W(0X34F4, ctx->r1) = ctx->r13;
    // 0x8006D230: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D234: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D238: sw          $t6, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = ctx->r14;
    // 0x8006D23C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D240: sw          $zero, 0x3504($at)
    MEM_W(0X3504, ctx->r1) = 0;
    // 0x8006D244: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D248: sb          $zero, -0x2C64($at)
    MEM_B(-0X2C64, ctx->r1) = 0;
L_8006D24C:
    // 0x8006D24C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006D250: addiu       $t0, $t0, -0x2C70
    ctx->r8 = ADD32(ctx->r8, -0X2C70);
    // 0x8006D254: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8006D258: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8006D25C: beq         $v0, $zero, L_8006D2A4
    if (ctx->r2 == 0) {
        // 0x8006D260: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D2A4;
    }
    // 0x8006D260: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D264: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8006D268: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8006D26C: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8006D270: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006D274: bgtz        $t9, L_8006D2A4
    if (SIGNED(ctx->r25) > 0) {
        // 0x8006D278: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8006D2A4;
    }
    // 0x8006D278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D27C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8006D280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006D284: jal         0x8006C1AC
    // 0x8006D288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_42;
    // 0x8006D288: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_42:
    // 0x8006D28C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8006D290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D294: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8006D298: jal         0x8006C1AC
    // 0x8006D29C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    level_properties_push(rdram, ctx);
        goto after_43;
    // 0x8006D29C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_43:
    // 0x8006D2A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006D2A4:
    // 0x8006D2A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D2A8: addiu       $a0, $a0, -0x2C6C
    ctx->r4 = ADD32(ctx->r4, -0X2C6C);
    // 0x8006D2AC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8006D2B0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8006D2B4: blez        $v0, L_8006D380
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006D2B8: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8006D380;
    }
    // 0x8006D2B8: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8006D2BC: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x8006D2C0: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8006D2C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D2C8: bgtz        $t3, L_8006D380
    if (SIGNED(ctx->r11) > 0) {
        // 0x8006D2CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006D380;
    }
    // 0x8006D2CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D2D0: lb          $v0, 0x3524($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3524);
    // 0x8006D2D4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006D2D8: beq         $v0, $at, L_8006D30C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D2DC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8006D30C;
    }
    // 0x8006D2DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006D2E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006D2E4: beq         $v0, $at, L_8006D314
    if (ctx->r2 == ctx->r1) {
        // 0x8006D2E8: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_8006D314;
    }
    // 0x8006D2E8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006D2EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006D2F0: beq         $v0, $at, L_8006D33C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D2F4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006D33C;
    }
    // 0x8006D2F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D2F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D2FC: beq         $v0, $at, L_8006D348
    if (ctx->r2 == ctx->r1) {
        // 0x8006D300: nop
    
            goto L_8006D348;
    }
    // 0x8006D300: nop

    // 0x8006D304: b           L_8006D374
    // 0x8006D308: nop

        goto L_8006D374;
    // 0x8006D308: nop

L_8006D30C:
    // 0x8006D30C: b           L_8006D374
    // 0x8006D310: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
        goto L_8006D374;
    // 0x8006D310: addiu       $s0, $zero, 0x2020
    ctx->r16 = ADD32(0, 0X2020);
L_8006D314:
    // 0x8006D314: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8006D318: jal         0x80098208
    // 0x8006D31C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    trophyround_adventure(rdram, ctx);
        goto after_44;
    // 0x8006D31C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_44:
    // 0x8006D320: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D324: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8006D328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D32C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D330: sw          $t5, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r13;
    // 0x8006D334: b           L_8006D374
    // 0x8006D338: addiu       $a0, $a0, -0x2C6C
    ctx->r4 = ADD32(ctx->r4, -0X2C6C);
        goto L_8006D374;
    // 0x8006D338: addiu       $a0, $a0, -0x2C6C
    ctx->r4 = ADD32(ctx->r4, -0X2C6C);
L_8006D33C:
    // 0x8006D33C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D340: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D344: sb          $t6, -0x2C64($at)
    MEM_B(-0X2C64, ctx->r1) = ctx->r14;
L_8006D348:
    // 0x8006D348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D34C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006D350: lb          $t8, 0x3525($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X3525);
    // 0x8006D354: sw          $t7, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = ctx->r15;
    // 0x8006D358: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D35C: sw          $t8, 0x34F4($at)
    MEM_W(0X34F4, ctx->r1) = ctx->r24;
    // 0x8006D360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D364: sw          $zero, 0x3504($at)
    MEM_W(0X3504, ctx->r1) = 0;
    // 0x8006D368: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D36C: sw          $zero, 0x3508($at)
    MEM_W(0X3508, ctx->r1) = 0;
    // 0x8006D370: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D374:
    // 0x8006D374: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D378: sb          $zero, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = 0;
    // 0x8006D37C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8006D380:
    // 0x8006D380: beq         $v1, $zero, L_8006D44C
    if (ctx->r3 == 0) {
        // 0x8006D384: nop
    
            goto L_8006D44C;
    }
    // 0x8006D384: nop

    // 0x8006D388: jal         0x8006C2F0
    // 0x8006D38C: nop

    level_properties_get(rdram, ctx);
        goto after_45;
    // 0x8006D38C: nop

    after_45:
    // 0x8006D390: beq         $v0, $zero, L_8006D560
    if (ctx->r2 == 0) {
        // 0x8006D394: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006D560;
    }
    // 0x8006D394: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D398: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D39C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D3A0: addiu       $a3, $a3, 0x3508
    ctx->r7 = ADD32(ctx->r7, 0X3508);
    // 0x8006D3A4: addiu       $a1, $a1, 0x3504
    ctx->r5 = ADD32(ctx->r5, 0X3504);
    // 0x8006D3A8: addiu       $a0, $a0, 0x34F4
    ctx->r4 = ADD32(ctx->r4, 0X34F4);
    // 0x8006D3AC: jal         0x8006C22C
    // 0x8006D3B0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_46;
    // 0x8006D3B0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_46:
    // 0x8006D3B4: jal         0x8006F42C
    // 0x8006D3B8: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_47;
    // 0x8006D3B8: nop

    after_47:
    // 0x8006D3BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D3C0: lw          $v0, 0x34F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34F4);
    // 0x8006D3C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D3C8: bgez        $v0, L_8006D438
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D3CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8006D438;
    }
    // 0x8006D3CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006D3D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D3D4: beq         $v0, $at, L_8006D3E4
    if (ctx->r2 == ctx->r1) {
        // 0x8006D3D8: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D3E4;
    }
    // 0x8006D3D8: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D3DC: bne         $v0, $at, L_8006D420
    if (ctx->r2 != ctx->r1) {
        // 0x8006D3E0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8006D420;
    }
    // 0x8006D3E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8006D3E4:
    // 0x8006D3E4: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D3E8: bne         $v0, $at, L_8006D40C
    if (ctx->r2 != ctx->r1) {
        // 0x8006D3EC: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D40C;
    }
    // 0x8006D3EC: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D3F0: jal         0x8009EC80
    // 0x8006D3F4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_48;
    // 0x8006D3F4: nop

    after_48:
    // 0x8006D3F8: beq         $v0, $zero, L_8006D40C
    if (ctx->r2 == 0) {
        // 0x8006D3FC: ori         $t9, $s0, 0x20
        ctx->r25 = ctx->r16 | 0X20;
            goto L_8006D40C;
    }
    // 0x8006D3FC: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
    // 0x8006D400: jal         0x8006F398
    // 0x8006D404: nop

    swap_lead_player(rdram, ctx);
        goto after_49;
    // 0x8006D404: nop

    after_49:
    // 0x8006D408: ori         $t9, $s0, 0x20
    ctx->r25 = ctx->r16 | 0X20;
L_8006D40C:
    // 0x8006D40C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8006D410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D414: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8006D418: b           L_8006D560
    // 0x8006D41C: sw          $t1, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r9;
        goto L_8006D560;
    // 0x8006D41C: sw          $t1, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r9;
L_8006D420:
    // 0x8006D420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D424: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8006D428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D42C: sw          $t2, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r10;
    // 0x8006D430: b           L_8006D560
    // 0x8006D434: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_8006D560;
    // 0x8006D434: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_8006D438:
    // 0x8006D438: sw          $zero, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = 0;
    // 0x8006D43C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D440: sw          $t4, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = ctx->r12;
    // 0x8006D444: b           L_8006D560
    // 0x8006D448: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8006D560;
    // 0x8006D448: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006D44C:
    // 0x8006D44C: jal         0x8006C300
    // 0x8006D450: nop

    func_8006C300(rdram, ctx);
        goto after_50;
    // 0x8006D450: nop

    after_50:
    // 0x8006D454: jal         0x8006C2F0
    // 0x8006D458: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    level_properties_get(rdram, ctx);
        goto after_51;
    // 0x8006D458: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_51:
    // 0x8006D45C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D460: beq         $v0, $zero, L_8006D560
    if (ctx->r2 == 0) {
        // 0x8006D464: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8006D560;
    }
    // 0x8006D464: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006D468: lh          $t5, -0x2C6C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2C6C);
    // 0x8006D46C: nop

    // 0x8006D470: bne         $t5, $zero, L_8006D564
    if (ctx->r13 != 0) {
        // 0x8006D474: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D564;
    }
    // 0x8006D474: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D478: jal         0x800214C4
    // 0x8006D47C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_800214C4(rdram, ctx);
        goto after_52;
    // 0x8006D47C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_52:
    // 0x8006D480: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006D484: bne         $v0, $zero, L_8006D4A8
    if (ctx->r2 != 0) {
        // 0x8006D488: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8006D4A8;
    }
    // 0x8006D488: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006D48C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8006D490: nop

    // 0x8006D494: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8006D498: beq         $t7, $zero, L_8006D564
    if (ctx->r15 == 0) {
        // 0x8006D49C: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D564;
    }
    // 0x8006D49C: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
    // 0x8006D4A0: beq         $v1, $zero, L_8006D564
    if (ctx->r3 == 0) {
        // 0x8006D4A4: andi        $t4, $s0, 0x20
        ctx->r12 = ctx->r16 & 0X20;
            goto L_8006D564;
    }
    // 0x8006D4A4: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D4A8:
    // 0x8006D4A8: beq         $v1, $zero, L_8006D4B8
    if (ctx->r3 == 0) {
        // 0x8006D4AC: nop
    
            goto L_8006D4B8;
    }
    // 0x8006D4AC: nop

    // 0x8006D4B0: jal         0x80000B28
    // 0x8006D4B4: nop

    music_change_on(rdram, ctx);
        goto after_53;
    // 0x8006D4B4: nop

    after_53:
L_8006D4B8:
    // 0x8006D4B8: jal         0x8006F42C
    // 0x8006D4BC: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_54;
    // 0x8006D4BC: nop

    after_54:
    // 0x8006D4C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D4C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D4C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D4CC: addiu       $a3, $a3, 0x3508
    ctx->r7 = ADD32(ctx->r7, 0X3508);
    // 0x8006D4D0: addiu       $a1, $a1, 0x3504
    ctx->r5 = ADD32(ctx->r5, 0X3504);
    // 0x8006D4D4: addiu       $a0, $a0, 0x34F4
    ctx->r4 = ADD32(ctx->r4, 0X34F4);
    // 0x8006D4D8: jal         0x8006C22C
    // 0x8006D4DC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    level_properties_pop(rdram, ctx);
        goto after_55;
    // 0x8006D4DC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_55:
    // 0x8006D4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D4E4: lw          $v0, 0x34F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34F4);
    // 0x8006D4E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006D4EC: bgez        $v0, L_8006D55C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D4F0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D55C;
    }
    // 0x8006D4F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D4F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D4F8: beq         $v0, $at, L_8006D508
    if (ctx->r2 == ctx->r1) {
        // 0x8006D4FC: addiu       $at, $zero, -0xA
        ctx->r1 = ADD32(0, -0XA);
            goto L_8006D508;
    }
    // 0x8006D4FC: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D500: bne         $v0, $at, L_8006D544
    if (ctx->r2 != ctx->r1) {
        // 0x8006D504: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8006D544;
    }
    // 0x8006D504: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006D508:
    // 0x8006D508: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x8006D50C: bne         $v0, $at, L_8006D530
    if (ctx->r2 != ctx->r1) {
        // 0x8006D510: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D530;
    }
    // 0x8006D510: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D514: jal         0x8009EC80
    // 0x8006D518: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_56;
    // 0x8006D518: nop

    after_56:
    // 0x8006D51C: beq         $v0, $zero, L_8006D530
    if (ctx->r2 == 0) {
        // 0x8006D520: ori         $t8, $s0, 0x20
        ctx->r24 = ctx->r16 | 0X20;
            goto L_8006D530;
    }
    // 0x8006D520: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
    // 0x8006D524: jal         0x8006F398
    // 0x8006D528: nop

    swap_lead_player(rdram, ctx);
        goto after_57;
    // 0x8006D528: nop

    after_57:
    // 0x8006D52C: ori         $t8, $s0, 0x20
    ctx->r24 = ctx->r16 | 0X20;
L_8006D530:
    // 0x8006D530: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8006D534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D538: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8006D53C: b           L_8006D560
    // 0x8006D540: sw          $t9, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r25;
        goto L_8006D560;
    // 0x8006D540: sw          $t9, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r25;
L_8006D544:
    // 0x8006D544: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D548: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8006D54C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006D550: sw          $t1, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r9;
    // 0x8006D554: b           L_8006D560
    // 0x8006D558: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
        goto L_8006D560;
    // 0x8006D558: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_8006D55C:
    // 0x8006D55C: sw          $t3, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = ctx->r11;
L_8006D560:
    // 0x8006D560: andi        $t4, $s0, 0x20
    ctx->r12 = ctx->r16 & 0X20;
L_8006D564:
    // 0x8006D564: beq         $t4, $zero, L_8006D578
    if (ctx->r12 == 0) {
        // 0x8006D568: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8006D578;
    }
    // 0x8006D568: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006D56C: lw          $t5, 0x34EC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X34EC);
    // 0x8006D570: nop

    // 0x8006D574: beq         $t5, $zero, L_8006D588
    if (ctx->r13 == 0) {
        // 0x8006D578: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006D588;
    }
L_8006D578:
    // 0x8006D578: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D57C: lw          $t6, 0x34FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X34FC);
    // 0x8006D580: nop

    // 0x8006D584: beq         $t6, $zero, L_8006D838
    if (ctx->r14 == 0) {
        // 0x8006D588: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D838;
    }
L_8006D588:
    // 0x8006D588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D58C: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    // 0x8006D590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D594: sh          $zero, -0x2C6C($at)
    MEM_H(-0X2C6C, ctx->r1) = 0;
    // 0x8006D598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D59C: jal         0x8006CC14
    // 0x8006D5A0: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_58;
    // 0x8006D5A0: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    after_58:
    // 0x8006D5A4: jal         0x8009C1A0
    // 0x8006D5A8: nop

    get_save_file_index(rdram, ctx);
        goto after_59;
    // 0x8006D5A8: nop

    after_59:
    // 0x8006D5AC: jal         0x8006EC48
    // 0x8006D5B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_60;
    // 0x8006D5B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x8006D5B4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8006D5B8: nop

    // 0x8006D5BC: beq         $t7, $zero, L_8006D70C
    if (ctx->r15 == 0) {
        // 0x8006D5C0: nop
    
            goto L_8006D70C;
    }
    // 0x8006D5C0: nop

    // 0x8006D5C4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8006D5C8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D5CC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8006D5D0: addiu       $s0, $s0, 0x3514
    ctx->r16 = ADD32(ctx->r16, 0X3514);
    // 0x8006D5D4: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x8006D5D8: beq         $at, $zero, L_8006D830
    if (ctx->r1 == 0) {
        // 0x8006D5DC: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8006D830;
    }
    // 0x8006D5DC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8006D5E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006D5E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D5E8: addu        $at, $at, $t9
    gpr jr_addend_8006D5F4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006D5EC: lw          $t9, 0x71B8($at)
    ctx->r25 = ADD32(ctx->r1, 0X71B8);
    // 0x8006D5F0: nop

    // 0x8006D5F4: jr          $t9
    // 0x8006D5F8: nop

    switch (jr_addend_8006D5F4 >> 2) {
        case 0: goto L_8006D5FC; break;
        case 1: goto L_8006D614; break;
        case 2: goto L_8006D62C; break;
        case 3: goto L_8006D644; break;
        case 4: goto L_8006D65C; break;
        case 5: goto L_8006D674; break;
        case 6: goto L_8006D6D4; break;
        case 7: goto L_8006D6F4; break;
        default: switch_error(__func__, 0x8006D5F4, 0x800E71B8);
    }
    // 0x8006D5F8: nop

L_8006D5FC:
    // 0x8006D5FC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006D600: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D604: jal         0x8006DA28
    // 0x8006D608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_61;
    // 0x8006D608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_61:
    // 0x8006D60C: b           L_8006D830
    // 0x8006D610: nop

        goto L_8006D830;
    // 0x8006D610: nop

L_8006D614:
    // 0x8006D614: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8006D618: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D61C: jal         0x8006DA28
    // 0x8006D620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_62;
    // 0x8006D620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_62:
    // 0x8006D624: b           L_8006D830
    // 0x8006D628: nop

        goto L_8006D830;
    // 0x8006D628: nop

L_8006D62C:
    // 0x8006D62C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8006D630: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D634: jal         0x8006DA28
    // 0x8006D638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_63;
    // 0x8006D638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8006D63C: b           L_8006D830
    // 0x8006D640: nop

        goto L_8006D830;
    // 0x8006D640: nop

L_8006D644:
    // 0x8006D644: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8006D648: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D64C: jal         0x8006DA28
    // 0x8006D650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_64;
    // 0x8006D650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8006D654: b           L_8006D830
    // 0x8006D658: nop

        goto L_8006D830;
    // 0x8006D658: nop

L_8006D65C:
    // 0x8006D65C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8006D660: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8006D664: jal         0x8006DA28
    // 0x8006D668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_65;
    // 0x8006D668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8006D66C: b           L_8006D830
    // 0x8006D670: nop

        goto L_8006D830;
    // 0x8006D670: nop

L_8006D674:
    // 0x8006D674: jal         0x8009ECD0
    // 0x8006D678: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_66;
    // 0x8006D678: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_66:
    // 0x8006D67C: beq         $v0, $zero, L_8006D694
    if (ctx->r2 == 0) {
        // 0x8006D680: nop
    
            goto L_8006D694;
    }
    // 0x8006D680: nop

    // 0x8006D684: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8006D688: nop

    // 0x8006D68C: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x8006D690: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8006D694:
    // 0x8006D694: jal         0x8009ECB8
    // 0x8006D698: nop

    is_tt_unlocked(rdram, ctx);
        goto after_67;
    // 0x8006D698: nop

    after_67:
    // 0x8006D69C: beq         $v0, $zero, L_8006D6B4
    if (ctx->r2 == 0) {
        // 0x8006D6A0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006D6B4;
    }
    // 0x8006D6A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006D6A4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8006D6A8: nop

    // 0x8006D6AC: xori        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 ^ 0X3;
    // 0x8006D6B0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_8006D6B4:
    // 0x8006D6B4: jal         0x8008AEB4
    // 0x8006D6B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_68;
    // 0x8006D6B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_68:
    // 0x8006D6BC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8006D6C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8006D6C4: jal         0x8006DA28
    // 0x8006D6C8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    load_menu_with_level_background(rdram, ctx);
        goto after_69;
    // 0x8006D6C8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_69:
    // 0x8006D6CC: b           L_8006D830
    // 0x8006D6D0: nop

        goto L_8006D830;
    // 0x8006D6D0: nop

L_8006D6D4:
    // 0x8006D6D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006D6D8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x8006D6DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006D6E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D6E4: jal         0x8006DA28
    // 0x8006D6E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_70;
    // 0x8006D6E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_70:
    // 0x8006D6EC: b           L_8006D830
    // 0x8006D6F0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8006D830;
    // 0x8006D6F0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8006D6F4:
    // 0x8006D6F4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006D6F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D6FC: jal         0x8006DA28
    // 0x8006D700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_71;
    // 0x8006D700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_71:
    // 0x8006D704: b           L_8006D830
    // 0x8006D708: nop

        goto L_8006D830;
    // 0x8006D708: nop

L_8006D70C:
    // 0x8006D70C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D710: lw          $t6, 0x34FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X34FC);
    // 0x8006D714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D718: bne         $t6, $at, L_8006D774
    if (ctx->r14 != ctx->r1) {
        // 0x8006D71C: andi        $t9, $s0, 0x10
        ctx->r25 = ctx->r16 & 0X10;
            goto L_8006D774;
    }
    // 0x8006D71C: andi        $t9, $s0, 0x10
    ctx->r25 = ctx->r16 & 0X10;
    // 0x8006D720: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D724: addiu       $v0, $v0, 0x1250
    ctx->r2 = ADD32(ctx->r2, 0X1250);
    // 0x8006D728: lb          $t7, 0x2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2);
    // 0x8006D72C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D730: bne         $t7, $at, L_8006D750
    if (ctx->r15 != ctx->r1) {
        // 0x8006D734: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8006D750;
    }
    // 0x8006D734: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006D738: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006D73C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D740: jal         0x8006DA28
    // 0x8006D744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_72;
    // 0x8006D744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_72:
    // 0x8006D748: b           L_8006D830
    // 0x8006D74C: nop

        goto L_8006D830;
    // 0x8006D74C: nop

L_8006D750:
    // 0x8006D750: addiu       $s0, $s0, 0x3514
    ctx->r16 = ADD32(ctx->r16, 0X3514);
    // 0x8006D754: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006D758: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8006D75C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8006D760: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D764: jal         0x8006DA28
    // 0x8006D768: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_73;
    // 0x8006D768: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_73:
    // 0x8006D76C: b           L_8006D830
    // 0x8006D770: nop

        goto L_8006D830;
    // 0x8006D770: nop

L_8006D774:
    // 0x8006D774: bne         $t9, $zero, L_8006D810
    if (ctx->r25 != 0) {
        // 0x8006D778: andi        $t1, $s0, 0x2000
        ctx->r9 = ctx->r16 & 0X2000;
            goto L_8006D810;
    }
    // 0x8006D778: andi        $t1, $s0, 0x2000
    ctx->r9 = ctx->r16 & 0X2000;
    // 0x8006D77C: bne         $t1, $zero, L_8006D7E0
    if (ctx->r9 != 0) {
        // 0x8006D780: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006D7E0;
    }
    // 0x8006D780: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D784: addiu       $v0, $v0, 0x1250
    ctx->r2 = ADD32(ctx->r2, 0X1250);
    // 0x8006D788: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x8006D78C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D790: sw          $t2, 0x34F4($at)
    MEM_W(0X34F4, ctx->r1) = ctx->r10;
    // 0x8006D794: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x8006D798: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D79C: sw          $t3, 0x3504($at)
    MEM_W(0X3504, ctx->r1) = ctx->r11;
    // 0x8006D7A0: lb          $t4, 0x1($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1);
    // 0x8006D7A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D7A8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8006D7AC: lb          $t6, 0x8($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X8);
    // 0x8006D7B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7B4: lw          $a0, 0x34F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34F4);
    // 0x8006D7B8: jal         0x8006B0AC
    // 0x8006D7BC: sw          $t6, 0x3508($at)
    MEM_W(0X3508, ctx->r1) = ctx->r14;
    leveltable_vehicle_default(rdram, ctx);
        goto after_74;
    // 0x8006D7BC: sw          $t6, 0x3508($at)
    MEM_W(0X3508, ctx->r1) = ctx->r14;
    after_74:
    // 0x8006D7C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006D7C4: lw          $t7, 0x3508($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3508);
    // 0x8006D7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7CC: bgez        $t7, L_8006D7E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006D7D0: sw          $v0, 0x3518($at)
        MEM_W(0X3518, ctx->r1) = ctx->r2;
            goto L_8006D7E0;
    }
    // 0x8006D7D0: sw          $v0, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = ctx->r2;
    // 0x8006D7D4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006D7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D7DC: sw          $t8, 0x3508($at)
    MEM_W(0X3508, ctx->r1) = ctx->r24;
L_8006D7E0:
    // 0x8006D7E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D7E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D7E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D7EC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D7F0: lw          $a3, 0x3518($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3518);
    // 0x8006D7F4: lw          $a2, 0x3504($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3504);
    // 0x8006D7F8: lw          $a1, 0x3500($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3500);
    // 0x8006D7FC: lw          $a0, 0x34F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34F4);
    // 0x8006D800: jal         0x8006CB58
    // 0x8006D804: nop

    load_level_game(rdram, ctx);
        goto after_75;
    // 0x8006D804: nop

    after_75:
    // 0x8006D808: b           L_8006D830
    // 0x8006D80C: nop

        goto L_8006D830;
    // 0x8006D80C: nop

L_8006D810:
    // 0x8006D810: jal         0x8009C1A0
    // 0x8006D814: nop

    get_save_file_index(rdram, ctx);
        goto after_76;
    // 0x8006D814: nop

    after_76:
    // 0x8006D818: jal         0x8006EC48
    // 0x8006D81C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_77;
    // 0x8006D81C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_77:
    // 0x8006D820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006D824: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006D828: jal         0x8006DA28
    // 0x8006D82C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_78;
    // 0x8006D82C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_78:
L_8006D830:
    // 0x8006D830: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D834: sw          $zero, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = 0;
L_8006D838:
    // 0x8006D838: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006D83C: lw          $t9, 0x34F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X34F8);
    // 0x8006D840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D844: beq         $t9, $zero, L_8006D898
    if (ctx->r25 == 0) {
        // 0x8006D848: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006D898;
    }
    // 0x8006D848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006D84C: jal         0x8006CC14
    // 0x8006D850: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    unload_level_game(rdram, ctx);
        goto after_79;
    // 0x8006D850: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    after_79:
    // 0x8006D854: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D858: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D85C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D860: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006D864: lw          $a3, 0x3518($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3518);
    // 0x8006D868: lw          $a2, 0x3504($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3504);
    // 0x8006D86C: lw          $a1, 0x3500($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3500);
    // 0x8006D870: lw          $a0, 0x34F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34F4);
    // 0x8006D874: jal         0x8006CB58
    // 0x8006D878: nop

    load_level_game(rdram, ctx);
        goto after_80;
    // 0x8006D878: nop

    after_80:
    // 0x8006D87C: jal         0x8009C1A0
    // 0x8006D880: nop

    get_save_file_index(rdram, ctx);
        goto after_81;
    // 0x8006D880: nop

    after_81:
    // 0x8006D884: jal         0x8006EC48
    // 0x8006D888: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_82;
    // 0x8006D888: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_82:
    // 0x8006D88C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D890: sw          $zero, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = 0;
    // 0x8006D894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006D898:
    // 0x8006D898: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006D89C: jr          $ra
    // 0x8006D8A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006D8A0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE050: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CE054: bne         $at, $zero, L_800CE134
    if (ctx->r1 != 0) {
        // 0x800CE058: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_800CE134;
    }
    // 0x800CE058: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800CE05C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800CE060: bne         $v0, $zero, L_800CE0C8
    if (ctx->r2 != 0) {
        // 0x800CE064: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_800CE0C8;
    }
    // 0x800CE064: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800CE068: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800CE06C: beq         $t8, $zero, L_800CE08C
    if (ctx->r24 == 0) {
        // 0x800CE070: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800CE08C;
    }
    // 0x800CE070: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800CE074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE078: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800CE07C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800CE080: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800CE084: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800CE088: bne         $v0, $v1, L_800CE164
    if (ctx->r2 != ctx->r3) {
        // 0x800CE08C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800CE164;
    }
L_800CE08C:
    // 0x800CE08C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE090: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE094: beq         $a3, $zero, L_800CE134
    if (ctx->r7 == 0) {
        // 0x800CE098: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE134;
    }
    // 0x800CE098: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE09C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE0A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800CE0A4:
    // 0x800CE0A4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE0A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE0AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE0B0: bne         $v0, $v1, L_800CE164
    if (ctx->r2 != ctx->r3) {
        // 0x800CE0B4: nop
    
            goto L_800CE164;
    }
    // 0x800CE0B4: nop

    // 0x800CE0B8: bnel        $a0, $a3, L_800CE0A4
    if (ctx->r4 != ctx->r7) {
        // 0x800CE0BC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800CE0A4;
    }
    goto skip_0;
    // 0x800CE0BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800CE0C0: b           L_800CE134
    // 0x800CE0C4: nop

        goto L_800CE134;
    // 0x800CE0C4: nop

L_800CE0C8:
    // 0x800CE0C8: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x800CE0CC: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x800CE0D0: beq         $a3, $zero, L_800CE0FC
    if (ctx->r7 == 0) {
        // 0x800CE0D4: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE0FC;
    }
    // 0x800CE0D4: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE0D8: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE0DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE0E0:
    // 0x800CE0E0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE0E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE0E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE0EC: bne         $v0, $v1, L_800CE164
    if (ctx->r2 != ctx->r3) {
        // 0x800CE0F0: nop
    
            goto L_800CE164;
    }
    // 0x800CE0F0: nop

    // 0x800CE0F4: bnel        $a0, $a3, L_800CE0E0
    if (ctx->r4 != ctx->r7) {
        // 0x800CE0F8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE0E0;
    }
    goto skip_1;
    // 0x800CE0F8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800CE0FC:
    // 0x800CE0FC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800CE100: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800CE104: beq         $a3, $zero, L_800CE134
    if (ctx->r7 == 0) {
        // 0x800CE108: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800CE134;
    }
    // 0x800CE108: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800CE10C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800CE110: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_800CE114:
    // 0x800CE114: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800CE118: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x800CE11C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CE120: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CE124: bne         $v0, $v1, L_800CE164
    if (ctx->r2 != ctx->r3) {
        // 0x800CE128: nop
    
            goto L_800CE164;
    }
    // 0x800CE128: nop

    // 0x800CE12C: bnel        $a0, $a3, L_800CE114
    if (ctx->r4 != ctx->r7) {
        // 0x800CE130: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_800CE114;
    }
    goto skip_2;
    // 0x800CE130: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_800CE134:
    // 0x800CE134: blez        $a2, L_800CE15C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CE138: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800CE15C;
    }
    // 0x800CE138: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800CE13C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800CE140:
    // 0x800CE140: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE144: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE148: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE14C: bne         $v0, $v1, L_800CE164
    if (ctx->r2 != ctx->r3) {
        // 0x800CE150: nop
    
            goto L_800CE164;
    }
    // 0x800CE150: nop

    // 0x800CE154: bnel        $a0, $a3, L_800CE140
    if (ctx->r4 != ctx->r7) {
        // 0x800CE158: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800CE140;
    }
    goto skip_3;
    // 0x800CE158: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800CE15C:
    // 0x800CE15C: jr          $ra
    // 0x800CE160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE164:
    // 0x800CE164: jr          $ra
    // 0x800CE168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800CE168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
