#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void osScRemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800794E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800794E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800794EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800794F0: lw          $v1, 0x260($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X260);
    // 0x800794F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800794F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800794FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80079500: jal         0x800C9A30
    // 0x80079504: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80079504: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80079508: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007950C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80079510: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80079514: beq         $v1, $zero, L_8007955C
    if (ctx->r3 == 0) {
        // 0x80079518: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8007955C;
    }
    // 0x80079518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007951C:
    // 0x8007951C: bne         $v1, $a1, L_80079548
    if (ctx->r3 != ctx->r5) {
        // 0x80079520: nop
    
            goto L_80079548;
    }
    // 0x80079520: nop

    // 0x80079524: beq         $a2, $zero, L_80079538
    if (ctx->r6 == 0) {
        // 0x80079528: nop
    
            goto L_80079538;
    }
    // 0x80079528: nop

    // 0x8007952C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80079530: b           L_8007955C
    // 0x80079534: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
        goto L_8007955C;
    // 0x80079534: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80079538:
    // 0x80079538: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8007953C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80079540: b           L_8007955C
    // 0x80079544: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
        goto L_8007955C;
    // 0x80079544: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
L_80079548:
    // 0x80079548: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007954C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x80079550: nop

    // 0x80079554: bne         $v1, $zero, L_8007951C
    if (ctx->r3 != 0) {
        // 0x80079558: nop
    
            goto L_8007951C;
    }
    // 0x80079558: nop

L_8007955C:
    // 0x8007955C: jal         0x800C9A30
    // 0x80079560: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80079560: nop

    after_1:
    // 0x80079564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007956C: jr          $ra
    // 0x80079570: nop

    return;
    // 0x80079570: nop

;}
RECOMP_FUNC void check_if_inside_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029DE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029DE4: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x80029DE8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80029DEC: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x80029DF0: nop

    // 0x80029DF4: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029DF8: bne         $at, $zero, L_80029E08
    if (ctx->r1 != 0) {
        // 0x80029DFC: nop
    
            goto L_80029E08;
    }
    // 0x80029DFC: nop

    // 0x80029E00: jr          $ra
    // 0x80029E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80029E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029E08:
    // 0x80029E08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029E0C: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80029E10: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029E14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E1C: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80029E20: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029E24: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80029E28: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80029E2C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80029E30: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80029E34: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80029E38: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80029E3C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80029E40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80029E4C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029E50: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80029E54: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80029E58: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80029E5C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80029E60: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029E64: addiu       $t4, $t3, 0x19
    ctx->r12 = ADD32(ctx->r11, 0X19);
    // 0x80029E68: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029E6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E74: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80029E78: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029E7C: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029E80: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80029E84: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029E88: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029E8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029F10;
    }
    // 0x80029E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029E90: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80029E94: nop

    // 0x80029E98: addiu       $t6, $t5, -0x19
    ctx->r14 = ADD32(ctx->r13, -0X19);
    // 0x80029E9C: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029EA0: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029EA4: nop
    
            goto L_80029F10;
    }
    // 0x80029EA4: nop

    // 0x80029EA8: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80029EAC: nop

    // 0x80029EB0: addiu       $t8, $t7, 0x19
    ctx->r24 = ADD32(ctx->r15, 0X19);
    // 0x80029EB4: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029EB8: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029EBC: nop
    
            goto L_80029F10;
    }
    // 0x80029EBC: nop

    // 0x80029EC0: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80029EC4: nop

    // 0x80029EC8: addiu       $t1, $t9, -0x19
    ctx->r9 = ADD32(ctx->r25, -0X19);
    // 0x80029ECC: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029ED0: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029ED4: nop
    
            goto L_80029F10;
    }
    // 0x80029ED4: nop

    // 0x80029ED8: lh          $t2, 0x8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8);
    // 0x80029EDC: nop

    // 0x80029EE0: addiu       $t3, $t2, 0x19
    ctx->r11 = ADD32(ctx->r10, 0X19);
    // 0x80029EE4: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80029EE8: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029EEC: nop
    
            goto L_80029F10;
    }
    // 0x80029EEC: nop

    // 0x80029EF0: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80029EF4: nop

    // 0x80029EF8: addiu       $t5, $t4, -0x19
    ctx->r13 = ADD32(ctx->r12, -0X19);
    // 0x80029EFC: slt         $at, $t5, $a3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80029F00: beq         $at, $zero, L_80029F10
    if (ctx->r1 == 0) {
        // 0x80029F04: nop
    
            goto L_80029F10;
    }
    // 0x80029F04: nop

    // 0x80029F08: jr          $ra
    // 0x80029F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80029F0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80029F10:
    // 0x80029F10: jr          $ra
    // 0x80029F14: nop

    return;
    // 0x80029F14: nop

;}
RECOMP_FUNC void is_bridge_raised(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2EC: bltz        $a0, L_8001E338
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E2F0: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E338;
    }
    // 0x8001E2F0: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E2F4: beq         $at, $zero, L_8001E338
    if (ctx->r1 == 0) {
        // 0x8001E2F8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E338;
    }
    // 0x8001E2F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E2FC: lw          $t6, -0x5234($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5234);
    // 0x8001E300: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001E304: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E308: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8001E30C: nop

    // 0x8001E310: blez        $v1, L_8001E330
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E314: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8001E330;
    }
    // 0x8001E314: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8001E318: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8001E31C: lw          $t8, -0x5234($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5234);
    // 0x8001E320: nop

    // 0x8001E324: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8001E328: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001E32C: nop

L_8001E330:
    // 0x8001E330: jr          $ra
    // 0x8001E334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001E334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E338:
    // 0x8001E338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E33C: jr          $ra
    // 0x8001E340: nop

    return;
    // 0x8001E340: nop

;}
RECOMP_FUNC void alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C981C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9820: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9824: beql        $t6, $zero, L_800C9898
    if (ctx->r14 == 0) {
        // 0x800C9828: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9898;
    }
    goto skip_0;
    // 0x800C9828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C982C: jal         0x80065668
    // 0x800C9830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9830: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9834: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9838: beq         $v0, $zero, L_800C9894
    if (ctx->r2 == 0) {
        // 0x800C983C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9894;
    }
    // 0x800C983C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9840: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9844: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9848: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C984C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9850: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9854: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9858: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C985C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9860: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800C9864: bgez        $v1, L_800C9874
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C9868: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800C9874;
    }
    // 0x800C9868: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800C986C: b           L_800C9878
    // 0x800C9870: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800C9878;
    // 0x800C9870: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800C9874:
    // 0x800C9874: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C9878:
    // 0x800C9878: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C987C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800C9880: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9884: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800C9888: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C988C: jalr        $t9
    // 0x800C9890: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9890: nop

    after_1:
L_800C9894:
    // 0x800C9894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9898:
    // 0x800C9898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C989C: jr          $ra
    // 0x800C98A0: nop

    return;
    // 0x800C98A0: nop

;}
RECOMP_FUNC void homing_rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EDD8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8003EDDC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003EDE0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8003EDE4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8003EDE8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003EDEC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003EDF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003EDF4: beq         $v0, $zero, L_8003F07C
    if (ctx->r2 == 0) {
        // 0x8003EDF8: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8003F07C;
    }
    // 0x8003EDF8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8003EDFC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003EE00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003EE04: lh          $t6, 0x1BA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BA);
    // 0x8003EE08: lwc1        $f13, 0x61F8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X61F8);
    // 0x8003EE0C: lwc1        $f12, 0x61FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X61FC);
    // 0x8003EE10: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8003EE14: sh          $t7, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r15;
    // 0x8003EE18: lh          $t8, 0x1BC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1BC);
    // 0x8003EE1C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8003EE20: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8003EE24: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x8003EE28: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003EE2C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003EE30: nop

    // 0x8003EE34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003EE38: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8003EE3C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003EE40: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003EE44: nop

    // 0x8003EE48: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003EE4C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EE50: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8003EE54: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003EE58: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003EE5C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003EE60: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003EE64: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8003EE68: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EE6C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EE70: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8003EE74: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003EE78: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8003EE7C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003EE80: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003EE84: nop

    // 0x8003EE88: bc1f        L_8003EEAC
    if (!c1cs) {
        // 0x8003EE8C: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8003EEAC;
    }
    // 0x8003EE8C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8003EE90: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003EE94: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x8003EE98: nop

    // 0x8003EE9C: bc1f        L_8003EEAC
    if (!c1cs) {
        // 0x8003EEA0: nop
    
            goto L_8003EEAC;
    }
    // 0x8003EEA0: nop

    // 0x8003EEA4: b           L_8003F0BC
    // 0x8003EEA8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8003F0BC;
    // 0x8003EEA8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8003EEAC:
    // 0x8003EEAC: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8003EEB0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x8003EEB4: jal         0x800C9AD0
    // 0x8003EEB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003EEB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_0:
    // 0x8003EEBC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003EEC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EEC4: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x8003EEC8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003EECC: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EED0: bc1f        L_8003EF58
    if (!c1cs) {
        // 0x8003EED4: swc1        $f0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
            goto L_8003EF58;
    }
    // 0x8003EED4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8003EED8: lb          $a1, 0x19($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X19);
    // 0x8003EEDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EEE0: beq         $a1, $at, L_8003EF5C
    if (ctx->r5 == ctx->r1) {
        // 0x8003EEE4: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_8003EF5C;
    }
    // 0x8003EEE4: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003EEE8: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x8003EEEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003EEF0: bne         $t2, $zero, L_8003EF58
    if (ctx->r10 != 0) {
        // 0x8003EEF4: addiu       $t4, $sp, 0x68
        ctx->r12 = ADD32(ctx->r29, 0X68);
            goto L_8003EF58;
    }
    // 0x8003EEF4: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x8003EEF8: lh          $t3, 0x16($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X16);
    // 0x8003EEFC: lbu         $a2, 0x1C8($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1C8);
    // 0x8003EF00: lh          $a3, 0x14($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X14);
    // 0x8003EF04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003EF08: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003EF0C: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8003EF10: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8003EF14: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8003EF18: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8003EF1C: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8003EF20: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003EF24: jal         0x8001955C
    // 0x8003EF28: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    homing_rocket_get_next_direction(rdram, ctx);
        goto after_1;
    // 0x8003EF28: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003EF2C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8003EF30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003EF34: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EF38: jal         0x80070750
    // 0x8003EF3C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EF3C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_2:
    // 0x8003EF40: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF44: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8003EF48: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003EF4C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8003EF50: b           L_8003EF6C
    // 0x8003EF54: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_8003EF6C;
    // 0x8003EF54: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_8003EF58:
    // 0x8003EF58: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
L_8003EF5C:
    // 0x8003EF5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EF60: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x8003EF64: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x8003EF68: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8003EF6C:
    // 0x8003EF6C: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EF70: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EF74: jal         0x80070750
    // 0x8003EF78: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8003EF78: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003EF7C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003EF80: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003EF84: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x8003EF88: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x8003EF8C: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x8003EF90: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8003EF94: subu        $v1, $a2, $t2
    ctx->r3 = SUB32(ctx->r6, ctx->r10);
    // 0x8003EF98: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF9C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8003EFA0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003EFA4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8003EFA8: bne         $at, $zero, L_8003EFB8
    if (ctx->r1 != 0) {
        // 0x8003EFAC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003EFB8;
    }
    // 0x8003EFAC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003EFB0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003EFB4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003EFB8:
    // 0x8003EFB8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003EFBC: beq         $at, $zero, L_8003EFC8
    if (ctx->r1 == 0) {
        // 0x8003EFC0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003EFC8;
    }
    // 0x8003EFC0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003EFC4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003EFC8:
    // 0x8003EFC8: beq         $t3, $zero, L_8003F038
    if (ctx->r11 == 0) {
        // 0x8003EFCC: slti        $at, $v1, 0x6001
        ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
            goto L_8003F038;
    }
    // 0x8003EFCC: slti        $at, $v1, 0x6001
    ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
    // 0x8003EFD0: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8003EFD4: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003EFD8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003EFDC: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8003EFE0: mflo        $t4
    ctx->r12 = lo;
    // 0x8003EFE4: srav        $t5, $t4, $t1
    ctx->r13 = S32(SIGNED(ctx->r12) >> (ctx->r9 & 31));
    // 0x8003EFE8: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8003EFEC: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8003EFF0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003EFF4: nop

    // 0x8003EFF8: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8003EFFC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003F000: bne         $at, $zero, L_8003F010
    if (ctx->r1 != 0) {
        // 0x8003F004: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003F010;
    }
    // 0x8003F004: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003F008: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003F00C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F010:
    // 0x8003F010: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003F014: beq         $at, $zero, L_8003F020
    if (ctx->r1 == 0) {
        // 0x8003F018: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003F020;
    }
    // 0x8003F018: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003F01C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F020:
    // 0x8003F020: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F024: mflo        $t9
    ctx->r25 = lo;
    // 0x8003F028: srav        $t2, $t9, $t1
    ctx->r10 = S32(SIGNED(ctx->r25) >> (ctx->r9 & 31));
    // 0x8003F02C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003F030: b           L_8003F07C
    // 0x8003F034: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_8003F07C;
    // 0x8003F034: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_8003F038:
    // 0x8003F038: beq         $at, $zero, L_8003F048
    if (ctx->r1 == 0) {
        // 0x8003F03C: slti        $at, $v1, -0x6000
        ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
            goto L_8003F048;
    }
    // 0x8003F03C: slti        $at, $v1, -0x6000
    ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
    // 0x8003F040: beq         $at, $zero, L_8003F060
    if (ctx->r1 == 0) {
        // 0x8003F044: nop
    
            goto L_8003F060;
    }
    // 0x8003F044: nop

L_8003F048:
    // 0x8003F048: lw          $t4, 0x4C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F04C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F050: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8003F054: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F058: nop

    // 0x8003F05C: sb          $t5, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r13;
L_8003F060:
    // 0x8003F060: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003F064: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8003F068: jal         0x80070750
    // 0x8003F06C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8003F06C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003F070: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8003F074: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8003F078: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
L_8003F07C:
    // 0x8003F07C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F080: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003F084: jal         0x8003F0F8
    // 0x8003F088: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_5;
    // 0x8003F088: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    after_5:
    // 0x8003F08C: jal         0x8009C3C8
    // 0x8003F090: nop

    get_number_of_active_players(rdram, ctx);
        goto after_6;
    // 0x8003F090: nop

    after_6:
    // 0x8003F094: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8003F098: beq         $at, $zero, L_8003F0C0
    if (ctx->r1 == 0) {
        // 0x8003F09C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8003F0C0;
    }
    // 0x8003F09C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003F0A0: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8003F0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F0A8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8003F0AC: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x8003F0B0: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8003F0B4: jal         0x800AFC3C
    // 0x8003F0B8: nop

    obj_spawn_particle(rdram, ctx);
        goto after_7;
    // 0x8003F0B8: nop

    after_7:
L_8003F0BC:
    // 0x8003F0BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003F0C0:
    // 0x8003F0C0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F0C4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8003F0C8: jr          $ra
    // 0x8003F0CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003F0CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void vi_refresh_rate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AB34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007AB38: lw          $t6, 0x6170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6170);
    // 0x8007AB3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007AB40: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8007AB44: lbu         $t7, 0x6309($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6309);
    // 0x8007AB48: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AB4C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8007AB50: bgez        $t7, L_8007AB68
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007AB54: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007AB68;
    }
    // 0x8007AB54: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AB58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007AB5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007AB60: nop

    // 0x8007AB64: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8007AB68:
    // 0x8007AB68: nop

    // 0x8007AB6C: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007AB70: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007AB74: nop

    // 0x8007AB78: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8007AB7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007AB80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007AB84: nop

    // 0x8007AB88: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007AB8C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8007AB90: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007AB94: jr          $ra
    // 0x8007AB98: nop

    return;
    // 0x8007AB98: nop

;}
RECOMP_FUNC void begin_level_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F338: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F33C: lh          $t6, -0x2C6C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2C6C);
    // 0x8006F340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F344: bne         $t6, $zero, L_8006F378
    if (ctx->r14 != 0) {
        // 0x8006F348: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F378;
    }
    // 0x8006F348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F350: sb          $a0, 0x3525($at)
    MEM_B(0X3525, ctx->r1) = ctx->r4;
    // 0x8006F354: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F358: jal         0x800C01D8
    // 0x8006F35C: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F35C: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    after_0:
    // 0x8006F360: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F368: sh          $t7, -0x2C6C($at)
    MEM_H(-0X2C6C, ctx->r1) = ctx->r15;
    // 0x8006F36C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F370: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8006F374: sb          $t8, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = ctx->r24;
L_8006F378:
    // 0x8006F378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F37C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F380: jr          $ra
    // 0x8006F384: nop

    return;
    // 0x8006F384: nop

;}
RECOMP_FUNC void obj_loop_animcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038710: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80038714: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003871C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038720: jal         0x8001F460
    // 0x80038724: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038724: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80038728: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003872C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80038730: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038734: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x80038738: bne         $v0, $zero, L_800387B0
    if (ctx->r2 != 0) {
        // 0x8003873C: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_800387B0;
    }
    // 0x8003873C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80038740: jal         0x80066210
    // 0x80038744: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80038744: nop

    after_1:
    // 0x80038748: bne         $v0, $zero, L_8003876C
    if (ctx->r2 != 0) {
        // 0x8003874C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8003876C;
    }
    // 0x8003874C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80038750: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80038754: nop

    // 0x80038758: lb          $a0, 0x44($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X44);
    // 0x8003875C: jal         0x800210CC
    // 0x80038760: nop

    func_800210CC(rdram, ctx);
        goto after_2;
    // 0x80038760: nop

    after_2:
    // 0x80038764: b           L_8003876C
    // 0x80038768: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8003876C;
    // 0x80038768: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003876C:
    // 0x8003876C: beq         $v1, $zero, L_800387B0
    if (ctx->r3 == 0) {
        // 0x80038770: ori         $t2, $zero, 0x8000
        ctx->r10 = 0 | 0X8000;
            goto L_800387B0;
    }
    // 0x80038770: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x80038774: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80038778: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8003877C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80038780: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038784: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038788: lb          $a0, 0x30($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X30);
    // 0x8003878C: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x80038790: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80038794: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80038798: nop

    // 0x8003879C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800387A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800387A4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800387A8: jal         0x80066488
    // 0x800387AC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    write_to_object_render_stack(rdram, ctx);
        goto after_3;
    // 0x800387AC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
L_800387B0:
    // 0x800387B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800387B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800387B8: jr          $ra
    // 0x800387BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800387BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_all_save_files_ptr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C490: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C494: jr          $ra
    // 0x8009C498: addiu       $v0, $v0, 0x6530
    ctx->r2 = ADD32(ctx->r2, 0X6530);
    return;
    // 0x8009C498: addiu       $v0, $v0, 0x6530
    ctx->r2 = ADD32(ctx->r2, 0X6530);
;}
RECOMP_FUNC void set_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4384: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C4388: addiu       $v0, $v0, -0x5818
    ctx->r2 = ADD32(ctx->r2, -0X5818);
    // 0x800C438C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C4390: nop

    // 0x800C4394: sb          $a0, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r4;
    // 0x800C4398: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C439C: nop

    // 0x800C43A0: sb          $a1, 0x15($t7)
    MEM_B(0X15, ctx->r15) = ctx->r5;
    // 0x800C43A4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C43A8: nop

    // 0x800C43AC: sb          $a2, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r6;
    // 0x800C43B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C43B4: nop

    // 0x800C43B8: sb          $a3, 0x17($t9)
    MEM_B(0X17, ctx->r25) = ctx->r7;
    // 0x800C43BC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800C43C0: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800C43C4: jr          $ra
    // 0x800C43C8: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
    return;
    // 0x800C43C8: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void free_message_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2AB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2AC0: lw          $a0, -0x5838($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5838);
    // 0x800C2AC4: jal         0x80071140
    // 0x800C2AC8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C2AC8: nop

    after_0:
    // 0x800C2ACC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2AD0: sh          $zero, -0x584A($at)
    MEM_H(-0X584A, ctx->r1) = 0;
    // 0x800C2AD4: jal         0x800C5620
    // 0x800C2AD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_1;
    // 0x800C2AD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2ADC: jal         0x800C5494
    // 0x800C2AE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x800C2AE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x800C2AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2AEC: jr          $ra
    // 0x800C2AF0: nop

    return;
    // 0x800C2AF0: nop

;}
RECOMP_FUNC void func_80059208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059208: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8005920C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059210: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80059214: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80059218: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005921C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80059220: jal         0x8001BA64
    // 0x80059224: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x80059224: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80059228: beq         $v0, $zero, L_80059780
    if (ctx->r2 == 0) {
        // 0x8005922C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80059780;
    }
    // 0x8005922C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059230: jal         0x8006BD88
    // 0x80059234: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059234: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    after_1:
    // 0x80059238: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8005923C: bne         $v0, $zero, L_80059264
    if (ctx->r2 != 0) {
        // 0x80059240: nop
    
            goto L_80059264;
    }
    // 0x80059240: nop

    // 0x80059244: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x80059248: nop

    // 0x8005924C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80059250: bne         $at, $zero, L_80059264
    if (ctx->r1 != 0) {
        // 0x80059254: nop
    
            goto L_80059264;
    }
    // 0x80059254: nop

    // 0x80059258: sb          $zero, 0x193($s1)
    MEM_B(0X193, ctx->r17) = 0;
    // 0x8005925C: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x80059260: sh          $zero, 0x190($s1)
    MEM_H(0X190, ctx->r17) = 0;
L_80059264:
    // 0x80059264: lwc1        $f6, 0xA8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x80059268: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005926C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80059270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059274: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80059278: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8005927C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059280: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80059284: lwc1        $f17, 0x6920($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6920);
    // 0x80059288: lwc1        $f16, 0x6924($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6924);
    // 0x8005928C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80059290: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x80059294: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x80059298: bc1f        L_80059350
    if (!c1cs) {
        // 0x8005929C: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80059350;
    }
    // 0x8005929C: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800592A0: sb          $t7, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r15;
    // 0x800592A4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592A8: nop

    // 0x800592AC: bgez        $a0, L_800592CC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800592B0: nop
    
            goto L_800592CC;
    }
    // 0x800592B0: nop

    // 0x800592B4: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x800592B8: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800592BC: blez        $v0, L_800592CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800592C0: sb          $t8, 0x192($s1)
        MEM_B(0X192, ctx->r17) = ctx->r24;
            goto L_800592CC;
    }
    // 0x800592C0: sb          $t8, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r24;
    // 0x800592C4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800592C8: sb          $t9, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r25;
L_800592CC:
    // 0x800592CC: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x800592D0: nop

    // 0x800592D4: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x800592D8: bne         $at, $zero, L_800592E4
    if (ctx->r1 != 0) {
        // 0x800592DC: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800592E4;
    }
    // 0x800592DC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800592E0: sh          $t1, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r9;
L_800592E4:
    // 0x800592E4: lbu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1C8);
    // 0x800592E8: nop

    // 0x800592EC: beq         $t2, $zero, L_80059780
    if (ctx->r10 == 0) {
        // 0x800592F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80059780;
    }
    // 0x800592F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800592F4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592F8: jal         0x8001BA00
    // 0x800592FC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    get_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x800592FC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_2:
    // 0x80059300: lb          $t3, 0x3A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3A);
    // 0x80059304: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059308: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005930C: bne         $s0, $t3, L_80059318
    if (ctx->r16 != ctx->r11) {
        // 0x80059310: nop
    
            goto L_80059318;
    }
    // 0x80059310: nop

    // 0x80059314: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059318:
    // 0x80059318: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005931C: nop

    // 0x80059320: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80059324: bgez        $a0, L_80059330
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80059328: nop
    
            goto L_80059330;
    }
    // 0x80059328: nop

    // 0x8005932C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
L_80059330:
    // 0x80059330: jal         0x8001BA00
    // 0x80059334: nop

    get_checkpoint_node(rdram, ctx);
        goto after_3;
    // 0x80059334: nop

    after_3:
    // 0x80059338: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x8005933C: nop

    // 0x80059340: bne         $s0, $t4, L_80059780
    if (ctx->r16 != ctx->r12) {
        // 0x80059344: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80059780;
    }
    // 0x80059344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059348: b           L_8005977C
    // 0x8005934C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
        goto L_8005977C;
    // 0x8005934C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059350:
    // 0x80059350: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80059354: nop

    // 0x80059358: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8005935C: nop

    // 0x80059360: bc1f        L_80059370
    if (!c1cs) {
        // 0x80059364: nop
    
            goto L_80059370;
    }
    // 0x80059364: nop

    // 0x80059368: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8005936C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80059370:
    // 0x80059370: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80059374: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80059378: swc1        $f3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x8005937C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80059380: jal         0x8001BA1C
    // 0x80059384: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x80059384: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_4:
    // 0x80059388: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x8005938C: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059390: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80059394: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80059398: bgez        $s0, L_800593A8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8005939C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800593A8;
    }
    // 0x8005939C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800593A0: addiu       $s0, $t0, -0x1
    ctx->r16 = ADD32(ctx->r8, -0X1);
    // 0x800593A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800593A8:
    // 0x800593A8: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800593AC: jal         0x8001BA00
    // 0x800593B0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    get_checkpoint_node(rdram, ctx);
        goto after_5;
    // 0x800593B0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800593B4: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800593B8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800593BC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800593C0: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800593C4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800593C8: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800593CC: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // 0x800593D0: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    // 0x800593D4: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x800593D8: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800593DC: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800593E0: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x800593E4: nop

    // 0x800593E8: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x800593EC: bgez        $s0, L_800593F8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800593F0: nop
    
            goto L_800593F8;
    }
    // 0x800593F0: nop

    // 0x800593F4: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
L_800593F8:
    // 0x800593F8: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x800593FC: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x80059400: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80059404: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80059408: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8005940C: jal         0x8001BA1C
    // 0x80059410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_6;
    // 0x80059410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80059414: lh          $t5, 0x1BA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1BA);
    // 0x80059418: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005941C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80059420: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80059424: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059428: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005942C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80059430: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80059434: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059438: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8005943C: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059440: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059444: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x80059448: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005944C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80059450: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80059454: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80059458: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8005945C: lh          $t6, 0x1BC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1BC);
    // 0x80059460: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80059464: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80059468: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005946C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80059470: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80059474: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80059478: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8005947C: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80059480: lh          $t7, 0x1BA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X1BA);
    // 0x80059484: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80059488: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005948C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80059490: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80059494: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059498: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005949C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800594A0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800594A4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800594A8: bne         $s0, $t0, L_800594B4
    if (ctx->r16 != ctx->r8) {
        // 0x800594AC: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_800594B4;
    }
    // 0x800594AC: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800594B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800594B4:
    // 0x800594B4: bne         $at, $zero, L_800593F8
    if (ctx->r1 != 0) {
        // 0x800594B8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800593F8;
    }
    // 0x800594B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800594BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800594C0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800594C4: lwc1        $f1, 0x28($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800594C8: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800594CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800594D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800594D4: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800594D8: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800594DC: bc1f        L_800594F4
    if (!c1cs) {
        // 0x800594E0: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_800594F4;
    }
    // 0x800594E0: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800594E4: sub.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d - ctx->f2.d;
    // 0x800594E8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800594EC: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800594F0: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
L_800594F4:
    // 0x800594F4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800594F8: jal         0x8002263C
    // 0x800594FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x800594FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80059500: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80059504: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80059508: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8005950C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059510: jal         0x8002263C
    // 0x80059514: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    cubic_spline_interpolation(rdram, ctx);
        goto after_8;
    // 0x80059514: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_8:
    // 0x80059518: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8005951C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80059520: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80059524: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059528: jal         0x8002263C
    // 0x8005952C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_9;
    // 0x8005952C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x80059530: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059534: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059538: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005953C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80059540: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80059544: jal         0x800C9AD0
    // 0x80059548: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x80059548: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_10:
    // 0x8005954C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059550: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059554: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80059558: nop

    // 0x8005955C: bc1t        L_80059588
    if (c1cs) {
        // 0x80059560: nop
    
            goto L_80059588;
    }
    // 0x80059560: nop

    // 0x80059564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059568: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005956C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80059570: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059574: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80059578: nop

    // 0x8005957C: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80059580: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80059584: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
L_80059588:
    // 0x80059588: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8005958C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059590: jal         0x80070750
    // 0x80059594: nop

    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x80059594: nop

    after_11:
    // 0x80059598: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005959C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800595A0: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x800595A4: subu        $a0, $v0, $t1
    ctx->r4 = SUB32(ctx->r2, ctx->r9);
    // 0x800595A8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800595AC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800595B0: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800595B4: bne         $at, $zero, L_800595C4
    if (ctx->r1 != 0) {
        // 0x800595B8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800595C4;
    }
    // 0x800595B8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800595BC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800595C0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800595C4:
    // 0x800595C4: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x800595C8: beq         $at, $zero, L_800595D4
    if (ctx->r1 == 0) {
        // 0x800595CC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800595D4;
    }
    // 0x800595CC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800595D0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800595D4:
    // 0x800595D4: slti        $at, $a0, 0x4001
    ctx->r1 = SIGNED(ctx->r4) < 0X4001 ? 1 : 0;
    // 0x800595D8: beq         $at, $zero, L_800595E8
    if (ctx->r1 == 0) {
        // 0x800595DC: slti        $at, $a0, -0x4000
        ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
            goto L_800595E8;
    }
    // 0x800595DC: slti        $at, $a0, -0x4000
    ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
    // 0x800595E0: beq         $at, $zero, L_80059628
    if (ctx->r1 == 0) {
        // 0x800595E4: nop
    
            goto L_80059628;
    }
    // 0x800595E4: nop

L_800595E8:
    // 0x800595E8: lbu         $v0, 0x1FC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1FC);
    // 0x800595EC: nop

    // 0x800595F0: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800595F4: beq         $at, $zero, L_8005962C
    if (ctx->r1 == 0) {
        // 0x800595F8: nop
    
            goto L_8005962C;
    }
    // 0x800595F8: nop

    // 0x800595FC: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80059600: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80059604: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80059608: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005960C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80059610: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x80059614: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x80059618: bc1f        L_8005962C
    if (!c1cs) {
        // 0x8005961C: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_8005962C;
    }
    // 0x8005961C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80059620: b           L_8005962C
    // 0x80059624: sb          $t3, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r11;
        goto L_8005962C;
    // 0x80059624: sb          $t3, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r11;
L_80059628:
    // 0x80059628: sb          $zero, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = 0;
L_8005962C:
    // 0x8005962C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059630: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059634: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80059638: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005963C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80059640: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80059644: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x80059648: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005964C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059650: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80059654: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x80059658: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005965C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80059660: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80059664: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80059668: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8005966C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80059670: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80059674: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80059678: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005967C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80059680: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80059684: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80059688: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005968C: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80059690: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059694: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80059698: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005969C: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800596A0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800596A4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800596A8: bc1f        L_800596B4
    if (!c1cs) {
        // 0x800596AC: nop
    
            goto L_800596B4;
    }
    // 0x800596AC: nop

    // 0x800596B0: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
L_800596B4:
    // 0x800596B4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800596B8: nop

    // 0x800596BC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800596C0: nop

    // 0x800596C4: bc1f        L_800596D0
    if (!c1cs) {
        // 0x800596C8: nop
    
            goto L_800596D0;
    }
    // 0x800596C8: nop

    // 0x800596CC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
L_800596D0:
    // 0x800596D0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800596D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800596D8: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800596DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800596E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800596E4: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800596E8: lh          $t4, 0x1BA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1BA);
    // 0x800596EC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800596F0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800596F4: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800596F8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800596FC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80059700: sh          $t7, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r15;
    // 0x80059704: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80059708: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005970C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80059710: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80059714: nop

    // 0x80059718: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8005971C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80059720: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80059724: bc1f        L_80059730
    if (!c1cs) {
        // 0x80059728: nop
    
            goto L_80059730;
    }
    // 0x80059728: nop

    // 0x8005972C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_80059730:
    // 0x80059730: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059734: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80059738: nop

    // 0x8005973C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80059740: nop

    // 0x80059744: bc1f        L_80059750
    if (!c1cs) {
        // 0x80059748: nop
    
            goto L_80059750;
    }
    // 0x80059748: nop

    // 0x8005974C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_80059750:
    // 0x80059750: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059754: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80059758: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8005975C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059760: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059764: lh          $t8, 0x1BC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1BC);
    // 0x80059768: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8005976C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80059770: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059774: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80059778: sh          $t2, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r10;
L_8005977C:
    // 0x8005977C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80059780:
    // 0x80059780: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80059784: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80059788: jr          $ra
    // 0x8005978C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8005978C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void light_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032424: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80032428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003242C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032430: lw          $a3, 0xC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XC);
    // 0x80032434: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80032438: beq         $a3, $zero, L_800324C4
    if (ctx->r7 == 0) {
        // 0x8003243C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800324C4;
    }
    // 0x8003243C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80032440: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80032444: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x80032448: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x8003244C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80032450: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80032454: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80032458: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003245C: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x80032460: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80032464: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80032468: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003246C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80032470: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x80032474: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80032478: jal         0x80070320
    // 0x8003247C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x8003247C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80032480: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032484: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80032488: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x8003248C: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80032490: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80032494: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80032498: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003249C: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800324A0: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800324A4: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800324A8: nop

    // 0x800324AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800324B0: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x800324B4: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800324B8: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
    // 0x800324BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800324C0: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_800324C4:
    // 0x800324C4: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x800324C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800324CC: beq         $a1, $zero, L_80032688
    if (ctx->r5 == 0) {
        // 0x800324D0: nop
    
            goto L_80032688;
    }
    // 0x800324D0: nop

    // 0x800324D4: lhu         $t9, 0x4C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4C);
    // 0x800324D8: lhu         $v0, 0x4A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4A);
    // 0x800324DC: addu        $t4, $t9, $s0
    ctx->r12 = ADD32(ctx->r25, ctx->r16);
    // 0x800324E0: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800324E4: sh          $t4, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r12;
    // 0x800324E8: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800324EC: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
    // 0x800324F0: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // 0x800324F4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800324F8: bne         $at, $zero, L_8003254C
    if (ctx->r1 != 0) {
        // 0x800324FC: nop
    
            goto L_8003254C;
    }
    // 0x800324FC: nop

L_80032500:
    // 0x80032500: lhu         $t9, 0x48($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X48);
    // 0x80032504: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80032508: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8003250C: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x80032510: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032514: sh          $t7, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r15;
    // 0x80032518: beq         $at, $zero, L_8003252C
    if (ctx->r1 == 0) {
        // 0x8003251C: sh          $t8, 0x4A($a2)
        MEM_H(0X4A, ctx->r6) = ctx->r24;
            goto L_8003252C;
    }
    // 0x8003251C: sh          $t8, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r24;
    // 0x80032520: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x80032524: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80032528: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
L_8003252C:
    // 0x8003252C: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80032530: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80032534: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80032538: lhu         $a0, 0x4C($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4C);
    // 0x8003253C: nop

    // 0x80032540: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032544: beq         $at, $zero, L_80032500
    if (ctx->r1 == 0) {
        // 0x80032548: nop
    
            goto L_80032500;
    }
    // 0x80032548: nop

L_8003254C:
    // 0x8003254C: lhu         $t7, 0x48($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X48);
    // 0x80032550: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80032554: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80032558: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003255C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80032560: beq         $at, $zero, L_80032578
    if (ctx->r1 == 0) {
        // 0x80032564: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80032578;
    }
    // 0x80032564: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80032568: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8003256C: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x80032570: b           L_8003257C
    // 0x80032574: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
        goto L_8003257C;
    // 0x80032574: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
L_80032578:
    // 0x80032578: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8003257C:
    // 0x8003257C: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80032580: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80032584: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x80032588: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8003258C: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x80032590: bne         $t5, $zero, L_8003259C
    if (ctx->r13 != 0) {
        // 0x80032594: nop
    
            goto L_8003259C;
    }
    // 0x80032594: nop

    // 0x80032598: break       7
    do_break(2147689880);
L_8003259C:
    // 0x8003259C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800325A0: bne         $t5, $at, L_800325B4
    if (ctx->r13 != ctx->r1) {
        // 0x800325A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800325B4;
    }
    // 0x800325A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800325A8: bne         $t6, $at, L_800325B4
    if (ctx->r14 != ctx->r1) {
        // 0x800325AC: nop
    
            goto L_800325B4;
    }
    // 0x800325AC: nop

    // 0x800325B0: break       6
    do_break(2147689904);
L_800325B4:
    // 0x800325B4: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x800325B8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800325BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800325C0: nop

    // 0x800325C4: nop

    // 0x800325C8: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800325CC: mflo        $t9
    ctx->r25 = lo;
    // 0x800325D0: nop

    // 0x800325D4: nop

    // 0x800325D8: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800325DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800325E0: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x800325E4: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x800325E8: lbu         $t7, 0x1($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1);
    // 0x800325EC: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x800325F0: nop

    // 0x800325F4: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x800325F8: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800325FC: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80032600: mflo        $t9
    ctx->r25 = lo;
    // 0x80032604: nop

    // 0x80032608: nop

    // 0x8003260C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032610: mflo        $t4
    ctx->r12 = lo;
    // 0x80032614: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032618: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
    // 0x8003261C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x80032620: lbu         $t1, 0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2);
    // 0x80032624: nop

    // 0x80032628: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x8003262C: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032630: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80032634: mflo        $t9
    ctx->r25 = lo;
    // 0x80032638: nop

    // 0x8003263C: nop

    // 0x80032640: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032644: mflo        $t4
    ctx->r12 = lo;
    // 0x80032648: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8003264C: sw          $t5, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r13;
    // 0x80032650: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x80032654: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80032658: nop

    // 0x8003265C: subu        $t8, $t7, $t2
    ctx->r24 = SUB32(ctx->r15, ctx->r10);
    // 0x80032660: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032664: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x80032668: mflo        $t9
    ctx->r25 = lo;
    // 0x8003266C: nop

    // 0x80032670: nop

    // 0x80032674: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032678: mflo        $t4
    ctx->r12 = lo;
    // 0x8003267C: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032680: b           L_800327E8
    // 0x80032684: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
        goto L_800327E8;
    // 0x80032684: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
L_80032688:
    // 0x80032688: lhu         $v1, 0x3C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3C);
    // 0x8003268C: nop

    // 0x80032690: beq         $v1, $zero, L_800326E0
    if (ctx->r3 == 0) {
        // 0x80032694: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800326E0;
    }
    // 0x80032694: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032698: beq         $at, $zero, L_800326C4
    if (ctx->r1 == 0) {
        // 0x8003269C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800326C4;
    }
    // 0x8003269C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800326A0: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x800326A4: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800326A8: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326AC: subu        $t6, $v1, $s0
    ctx->r14 = SUB32(ctx->r3, ctx->r16);
    // 0x800326B0: sh          $t6, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = ctx->r14;
    // 0x800326B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800326B8: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x800326BC: b           L_800326E0
    // 0x800326C0: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
        goto L_800326E0;
    // 0x800326C0: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
L_800326C4:
    // 0x800326C4: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x800326C8: lw          $t5, 0x1C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1C);
    // 0x800326CC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326D0: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x800326D4: mflo        $t7
    ctx->r15 = lo;
    // 0x800326D8: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800326DC: sw          $t9, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r25;
L_800326E0:
    // 0x800326E0: lhu         $v1, 0x3E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3E);
    // 0x800326E4: nop

    // 0x800326E8: beq         $v1, $zero, L_80032738
    if (ctx->r3 == 0) {
        // 0x800326EC: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032738;
    }
    // 0x800326EC: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800326F0: beq         $at, $zero, L_8003271C
    if (ctx->r1 == 0) {
        // 0x800326F4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003271C;
    }
    // 0x800326F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800326F8: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x800326FC: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
    // 0x80032700: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032704: subu        $t7, $v1, $s0
    ctx->r15 = SUB32(ctx->r3, ctx->r16);
    // 0x80032708: sh          $t7, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = ctx->r15;
    // 0x8003270C: mflo        $t8
    ctx->r24 = lo;
    // 0x80032710: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80032714: b           L_80032738
    // 0x80032718: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
        goto L_80032738;
    // 0x80032718: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
L_8003271C:
    // 0x8003271C: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80032720: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x80032724: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032728: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x8003272C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032730: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80032734: sw          $t8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r24;
L_80032738:
    // 0x80032738: lhu         $v1, 0x40($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X40);
    // 0x8003273C: nop

    // 0x80032740: beq         $v1, $zero, L_80032790
    if (ctx->r3 == 0) {
        // 0x80032744: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032790;
    }
    // 0x80032744: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032748: beq         $at, $zero, L_80032774
    if (ctx->r1 == 0) {
        // 0x8003274C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80032774;
    }
    // 0x8003274C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032750: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x80032754: lw          $t5, 0x24($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X24);
    // 0x80032758: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003275C: subu        $t4, $v1, $s0
    ctx->r12 = SUB32(ctx->r3, ctx->r16);
    // 0x80032760: sh          $t4, 0x40($a2)
    MEM_H(0X40, ctx->r6) = ctx->r12;
    // 0x80032764: mflo        $t6
    ctx->r14 = lo;
    // 0x80032768: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x8003276C: b           L_80032790
    // 0x80032770: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
        goto L_80032790;
    // 0x80032770: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
L_80032774:
    // 0x80032774: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x80032778: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x8003277C: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032780: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x80032784: mflo        $t5
    ctx->r13 = lo;
    // 0x80032788: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8003278C: sw          $t6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r14;
L_80032790:
    // 0x80032790: lhu         $v1, 0x42($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X42);
    // 0x80032794: nop

    // 0x80032798: beq         $v1, $zero, L_800327E8
    if (ctx->r3 == 0) {
        // 0x8003279C: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800327E8;
    }
    // 0x8003279C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800327A0: beq         $at, $zero, L_800327CC
    if (ctx->r1 == 0) {
        // 0x800327A4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800327CC;
    }
    // 0x800327A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800327A8: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800327AC: lw          $t9, 0x28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X28);
    // 0x800327B0: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327B4: subu        $t5, $v1, $s0
    ctx->r13 = SUB32(ctx->r3, ctx->r16);
    // 0x800327B8: sh          $t5, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r13;
    // 0x800327BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800327C0: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800327C4: b           L_800327E8
    // 0x800327C8: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
        goto L_800327E8;
    // 0x800327C8: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
L_800327CC:
    // 0x800327CC: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800327D0: lw          $t6, 0x28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X28);
    // 0x800327D4: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327D8: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x800327DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800327E0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800327E4: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
L_800327E8:
    // 0x800327E8: lhu         $v1, 0x78($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X78);
    // 0x800327EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800327F0: beq         $v1, $zero, L_8003286C
    if (ctx->r3 == 0) {
        // 0x800327F4: nop
    
            goto L_8003286C;
    }
    // 0x800327F4: nop

    // 0x800327F8: bne         $v1, $at, L_8003281C
    if (ctx->r3 != ctx->r1) {
        // 0x800327FC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003281C;
    }
    // 0x800327FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032800: lh          $t5, 0x74($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X74);
    // 0x80032804: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032808: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003280C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032810: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x80032814: b           L_80032868
    // 0x80032818: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
        goto L_80032868;
    // 0x80032818: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
L_8003281C:
    // 0x8003281C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032820: beq         $at, $zero, L_8003284C
    if (ctx->r1 == 0) {
        // 0x80032824: nop
    
            goto L_8003284C;
    }
    // 0x80032824: nop

    // 0x80032828: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x8003282C: lh          $t9, 0x70($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X70);
    // 0x80032830: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032834: subu        $t4, $v0, $s0
    ctx->r12 = SUB32(ctx->r2, ctx->r16);
    // 0x80032838: sh          $t4, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r12;
    // 0x8003283C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032840: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80032844: b           L_80032868
    // 0x80032848: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
        goto L_80032868;
    // 0x80032848: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
L_8003284C:
    // 0x8003284C: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x80032850: lh          $t6, 0x70($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X70);
    // 0x80032854: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032858: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x8003285C: mflo        $t9
    ctx->r25 = lo;
    // 0x80032860: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x80032864: sh          $t5, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r13;
L_80032868:
    // 0x80032868: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_8003286C:
    // 0x8003286C: lhu         $v1, 0x7A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X7A);
    // 0x80032870: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80032874: beq         $v1, $zero, L_800328F0
    if (ctx->r3 == 0) {
        // 0x80032878: nop
    
            goto L_800328F0;
    }
    // 0x80032878: nop

    // 0x8003287C: bne         $v1, $at, L_800328A0
    if (ctx->r3 != ctx->r1) {
        // 0x80032880: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800328A0;
    }
    // 0x80032880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032884: lh          $t4, 0x76($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X76);
    // 0x80032888: lh          $t8, 0x72($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X72);
    // 0x8003288C: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032890: mflo        $t7
    ctx->r15 = lo;
    // 0x80032894: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80032898: b           L_800328EC
    // 0x8003289C: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
        goto L_800328EC;
    // 0x8003289C: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
L_800328A0:
    // 0x800328A0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800328A4: beq         $at, $zero, L_800328D0
    if (ctx->r1 == 0) {
        // 0x800328A8: nop
    
            goto L_800328D0;
    }
    // 0x800328A8: nop

    // 0x800328AC: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x800328B0: lh          $t9, 0x72($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X72);
    // 0x800328B4: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328B8: subu        $t7, $v0, $s0
    ctx->r15 = SUB32(ctx->r2, ctx->r16);
    // 0x800328BC: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x800328C0: mflo        $t4
    ctx->r12 = lo;
    // 0x800328C4: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800328C8: b           L_800328EC
    // 0x800328CC: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
        goto L_800328EC;
    // 0x800328CC: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
L_800328D0:
    // 0x800328D0: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x800328D4: lh          $t6, 0x72($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X72);
    // 0x800328D8: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328DC: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x800328E0: mflo        $t9
    ctx->r25 = lo;
    // 0x800328E4: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x800328E8: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
L_800328EC:
    // 0x800328EC: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_800328F0:
    // 0x800328F0: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x800328F4: nop

    // 0x800328F8: beq         $t8, $zero, L_80032BA0
    if (ctx->r24 == 0) {
        // 0x800328FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80032BA0;
    }
    // 0x800328FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032900: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80032904: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032908: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8003290C: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032910: addiu       $s0, $a2, 0x7C
    ctx->r16 = ADD32(ctx->r6, 0X7C);
    // 0x80032914: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032918: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003291C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032920: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032924: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032928: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003292C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032930: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032934: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80032938: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8003293C: sh          $t5, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r13;
    // 0x80032940: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032944: nop

    // 0x80032948: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003294C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032950: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032954: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032958: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003295C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80032960: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032964: bne         $t4, $at, L_800329D0
    if (ctx->r12 != ctx->r1) {
        // 0x80032968: sh          $t9, 0x56($a2)
        MEM_H(0X56, ctx->r6) = ctx->r25;
            goto L_800329D0;
    }
    // 0x80032968: sh          $t9, 0x56($a2)
    MEM_H(0X56, ctx->r6) = ctx->r25;
    // 0x8003296C: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80032970: nop

    // 0x80032974: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032978: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003297C: nop

    // 0x80032980: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80032984: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032988: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003298C: nop

    // 0x80032990: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032994: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80032998: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8003299C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800329A0: sh          $t7, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r15;
    // 0x800329A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800329A8: nop

    // 0x800329AC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800329B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329B8: nop

    // 0x800329BC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800329C0: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800329C4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800329C8: b           L_80032A38
    // 0x800329CC: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
        goto L_80032A38;
    // 0x800329CC: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
L_800329D0:
    // 0x800329D0: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800329D4: lwc1        $f0, 0x60($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X60);
    // 0x800329D8: nop

    // 0x800329DC: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800329E0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800329E4: nop

    // 0x800329E8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800329EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329F4: nop

    // 0x800329F8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800329FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032A00: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80032A04: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032A08: sh          $t4, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r12;
    // 0x80032A0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80032A10: nop

    // 0x80032A14: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80032A18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A20: nop

    // 0x80032A24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032A28: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80032A2C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80032A30: sh          $t7, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r15;
    // 0x80032A34: nop

L_80032A38:
    // 0x80032A38: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80032A3C: nop

    // 0x80032A40: bne         $t5, $zero, L_80032AB0
    if (ctx->r13 != 0) {
        // 0x80032A44: nop
    
            goto L_80032AB0;
    }
    // 0x80032A44: nop

    // 0x80032A48: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032A4C: lwc1        $f0, 0x64($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80032A50: nop

    // 0x80032A54: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032A58: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032A5C: nop

    // 0x80032A60: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032A64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A6C: nop

    // 0x80032A70: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032A74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032A78: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032A7C: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032A80: sh          $t9, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r25;
    // 0x80032A84: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80032A88: nop

    // 0x80032A8C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80032A90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A98: nop

    // 0x80032A9C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032AA0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80032AA4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80032AA8: b           L_80032B18
    // 0x80032AAC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
        goto L_80032B18;
    // 0x80032AAC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
L_80032AB0:
    // 0x80032AB0: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032AB4: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032AB8: nop

    // 0x80032ABC: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032AC0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032AC4: nop

    // 0x80032AC8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032ACC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032AD4: nop

    // 0x80032AD8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032ADC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032AE0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80032AE4: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032AE8: sh          $t5, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r13;
    // 0x80032AEC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032AF0: nop

    // 0x80032AF4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032AF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032B00: nop

    // 0x80032B04: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032B08: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032B0C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032B10: sh          $t9, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r25;
    // 0x80032B14: nop

L_80032B18:
    // 0x80032B18: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80032B1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032B20: bne         $t4, $at, L_80032B98
    if (ctx->r12 != ctx->r1) {
        // 0x80032B24: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80032B98;
    }
    // 0x80032B24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80032B28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032B2C: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032B30: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
    // 0x80032B34: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x80032B38: lh          $t7, 0x72($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X72);
    // 0x80032B3C: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80032B40: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80032B44: jal         0x80070490
    // 0x80032B48: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    vec3f_rotate_py(rdram, ctx);
        goto after_1;
    // 0x80032B48: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    after_1:
    // 0x80032B4C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80032B54: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x80032B58: nop

    // 0x80032B5C: beq         $a3, $zero, L_80032B74
    if (ctx->r7 == 0) {
        // 0x80032B60: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032B74;
    }
    // 0x80032B60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032B64: jal         0x80070320
    // 0x80032B68: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_2;
    // 0x80032B68: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_2:
    // 0x80032B6C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032B70: nop

L_80032B74:
    // 0x80032B74: lwc1        $f4, 0x7C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x80032B78: lwc1        $f8, 0x80($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X80);
    // 0x80032B7C: lwc1        $f16, 0x84($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80032B80: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80032B84: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80032B88: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80032B8C: swc1        $f6, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->f6.u32l;
    // 0x80032B90: swc1        $f10, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->f10.u32l;
    // 0x80032B94: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
L_80032B98:
    // 0x80032B98: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80032B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80032BA0:
    // 0x80032BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032BA4: jr          $ra
    // 0x80032BA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80032BA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alCSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8284: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C8288: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C828C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8290: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C8294: ldc1        $f6, -0x6B50($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6B50);
    // 0x800C8298: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C829C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C82A0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C82A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C82A8: bgez        $t7, L_800C82C0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C82AC: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800C82C0;
    }
    // 0x800C82AC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800C82B0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C82B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C82B8: nop

    // 0x800C82BC: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800C82C0:
    // 0x800C82C0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800C82C4: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800C82C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C82CC: bgez        $a2, L_800C82E4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C82D0: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_800C82E4;
    }
    // 0x800C82D0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800C82D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C82D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C82DC: nop

    // 0x800C82E0: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_800C82E4:
    // 0x800C82E4: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800C82E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C82EC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C82F0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C82F4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C82F8: nop

    // 0x800C82FC: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C8300: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8304: nop

    // 0x800C8308: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C830C: beql        $v0, $zero, L_800C8368
    if (ctx->r2 == 0) {
        // 0x800C8310: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800C8368;
    }
    goto skip_0;
    // 0x800C8310: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800C8314: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C8318: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C831C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8320: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C8324: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800C8328: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C832C: nop

    // 0x800C8330: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800C8334: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8338: nop

    // 0x800C833C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C8340: bnel        $v0, $zero, L_800C835C
    if (ctx->r2 != 0) {
        // 0x800C8344: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C835C;
    }
    goto skip_1;
    // 0x800C8344: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x800C8348: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C834C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C8350: jr          $ra
    // 0x800C8354: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800C8354: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800C8358: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_800C835C:
    // 0x800C835C: jr          $ra
    // 0x800C8360: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C8360: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C8364: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800C8368:
    // 0x800C8368: nop

    // 0x800C836C: bltzl       $v0, L_800C835C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C8370: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C835C;
    }
    goto skip_2;
    // 0x800C8370: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800C8374: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C8378: jr          $ra
    // 0x800C837C: nop

    return;
    // 0x800C837C: nop

;}
RECOMP_FUNC void func_800135B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800135B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800135BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800135C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800135C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800135C8: lw          $s0, 0x7C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X7C);
    // 0x800135CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800135D0: sra         $t6, $s0, 28
    ctx->r14 = S32(SIGNED(ctx->r16) >> 28);
    // 0x800135D4: andi        $s0, $t6, 0xF
    ctx->r16 = ctx->r14 & 0XF;
    // 0x800135D8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800135DC: lbu         $v0, -0x4FB8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB8);
    // 0x800135E0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800135E4: beq         $v0, $zero, L_80013600
    if (ctx->r2 == 0) {
        // 0x800135E8: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80013600;
    }
    // 0x800135E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800135EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800135F0: beq         $v0, $at, L_80013608
    if (ctx->r2 == ctx->r1) {
        // 0x800135F4: addiu       $v1, $s1, 0x24
        ctx->r3 = ADD32(ctx->r17, 0X24);
            goto L_80013608;
    }
    // 0x800135F4: addiu       $v1, $s1, 0x24
    ctx->r3 = ADD32(ctx->r17, 0X24);
    // 0x800135F8: b           L_80013608
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
        goto L_80013608;
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
L_80013600:
    // 0x80013600: b           L_80013608
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
        goto L_80013608;
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80013608:
    // 0x80013608: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001360C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80013610: jal         0x8001E29C
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    after_0:
    // 0x80013618: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001361C: addiu       $t8, $t8, -0x4FA8
    ctx->r24 = ADD32(ctx->r24, -0X4FA8);
    // 0x80013620: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    // 0x80013624: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80013628: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8001362C: sll         $t4, $t9, 7
    ctx->r12 = S32(ctx->r25 << 7);
    // 0x80013630: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80013634: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80013638: lw          $a0, 0x78($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X78);
    // 0x8001363C: jal         0x80012E28
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    object_do_player_tumble(rdram, ctx);
        goto after_1;
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80013644: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80013648: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001364C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80013650: addiu       $s0, $s0, -0x5174
    ctx->r16 = ADD32(ctx->r16, -0X5174);
    // 0x80013654: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013658: lw          $a2, 0x78($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X78);
    // 0x8001365C: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80013660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013664: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80013668: jal         0x80069484
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80013670: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80013674: nop

    // 0x80013678: lw          $a0, 0x78($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X78);
    // 0x8001367C: jal         0x80012F30
    // 0x80013680: nop

    object_undo_player_tumble(rdram, ctx);
        goto after_3;
    // 0x80013680: nop

    after_3:
    // 0x80013684: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80013688: nop

    // 0x8001368C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013690: nop

    // 0x80013694: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80013698: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001369C: nop

    // 0x800136A0: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800136A4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800136A8: nop

    // 0x800136AC: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x800136B0: lbu         $t9, 0x72($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X72);
    // 0x800136B4: nop

    // 0x800136B8: sll         $t4, $t9, 28
    ctx->r12 = S32(ctx->r25 << 28);
    // 0x800136BC: jal         0x800707F8
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
    // 0x800136C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800136C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800136CC: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800136D0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800136D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800136D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800136DC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800136E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800136E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800136E8: addiu       $a2, $a2, -0x516C
    ctx->r6 = ADD32(ctx->r6, -0X516C);
    // 0x800136EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800136F0: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x800136F4: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x800136F8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800136FC: beq         $at, $zero, L_80013714
    if (ctx->r1 == 0) {
        // 0x80013700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80013714;
    }
    // 0x80013700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013704: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80013708: nop

    // 0x8001370C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80013710: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80013714:
    // 0x80013714: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013718: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001371C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013720: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80013724: beq         $t8, $zero, L_80013740
    if (ctx->r24 == 0) {
        // 0x80013728: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80013740;
    }
    // 0x80013728: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8001372C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013730: lwc1        $f18, 0x5568($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5568);
    // 0x80013734: nop

    // 0x80013738: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001373C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80013740:
    // 0x80013740: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013744: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x80013748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001374C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80013750: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013754: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x80013758: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8001375C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80013760: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80013764: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013768: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x8001376C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013770: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013774: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80013778: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001377C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80013780: addiu       $t5, $zero, 0x10A
    ctx->r13 = ADD32(0, 0X10A);
    // 0x80013784: lw          $t4, 0x78($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X78);
    // 0x80013788: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001378C: jal         0x80068514
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x80013794: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x80013798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001379C: bne         $t6, $at, L_8001388C
    if (ctx->r14 != ctx->r1) {
        // 0x800137A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001388C;
    }
    // 0x800137A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800137A4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800137A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800137AC: lw          $a1, 0x7C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X7C);
    // 0x800137B0: jal         0x8007B4E8
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800137B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800137BC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800137C0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x800137C4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800137C8: beq         $t9, $zero, L_800137D8
    if (ctx->r25 == 0) {
        // 0x800137CC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800137D8;
    }
    // 0x800137CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800137D0: b           L_800137DC
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800137DC;
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800137D8:
    // 0x800137D8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800137DC:
    // 0x800137DC: lw          $v1, 0x7C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X7C);
    // 0x800137E0: lw          $a0, -0x4FF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4FF8);
    // 0x800137E4: sra         $t7, $v1, 14
    ctx->r15 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800137E8: andi        $t8, $t7, 0x3FFF
    ctx->r24 = ctx->r15 & 0X3FFF;
    // 0x800137EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800137F0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800137F4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800137F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800137FC: lw          $t6, -0x38B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X38B4);
    // 0x80013800: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80013804: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80013808: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001380C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80013810: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80013814: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013818: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    // 0x8001381C: andi        $t5, $v1, 0x3FFF
    ctx->r13 = ctx->r3 & 0X3FFF;
    // 0x80013820: lw          $t4, -0x38AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X38AC);
    // 0x80013824: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013828: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8001382C: andi        $t6, $a2, 0x6
    ctx->r14 = ctx->r6 & 0X6;
    // 0x80013830: ori         $t9, $t6, 0x40
    ctx->r25 = ctx->r14 | 0X40;
    // 0x80013834: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013838: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x8001383C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80013840: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80013844: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013848: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8001384C: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80013850: ori         $t8, $t7, 0xAA
    ctx->r24 = ctx->r15 | 0XAA;
    // 0x80013854: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013858: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8001385C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013860: ori         $t9, $t2, 0x70
    ctx->r25 = ctx->r10 | 0X70;
    // 0x80013864: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013868: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001386C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013870: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013874: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80013878: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8001387C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80013880: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x80013884: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80013888: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8001388C:
    // 0x8001388C: jal         0x80069A40
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_7;
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80013894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001389C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800138A0: jr          $ra
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80053750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053750: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80053754: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80053758: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8005375C: beq         $v0, $zero, L_80053E94
    if (ctx->r2 == 0) {
        // 0x80053760: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80053E94;
    }
    // 0x80053760: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80053764: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80053768: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005376C: bne         $v1, $at, L_80053798
    if (ctx->r3 != ctx->r1) {
        // 0x80053770: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80053798;
    }
    // 0x80053770: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80053774: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80053778: addiu       $a3, $zero, 0x4000
    ctx->r7 = ADD32(0, 0X4000);
    // 0x8005377C: sh          $a3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r7;
    // 0x80053780: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80053784: nop

    // 0x80053788: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x8005378C: nop

    // 0x80053790: sh          $a3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r7;
    // 0x80053794: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80053798:
    // 0x80053798: bne         $at, $zero, L_80053E94
    if (ctx->r1 != 0) {
        // 0x8005379C: nop
    
            goto L_80053E94;
    }
    // 0x8005379C: nop

    // 0x800537A0: lwc1        $f0, 0x2C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800537A4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800537A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800537AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800537B0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800537B4: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x800537B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800537BC: bc1f        L_800537D0
    if (!c1cs) {
        // 0x800537C0: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_800537D0;
    }
    // 0x800537C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800537C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800537C8: nop

    // 0x800537CC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800537D0:
    // 0x800537D0: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x800537D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800537D8: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800537DC: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800537E0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800537E4: bc1f        L_800537F4
    if (!c1cs) {
        // 0x800537E8: nop
    
            goto L_800537F4;
    }
    // 0x800537E8: nop

    // 0x800537EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800537F0: nop

L_800537F4:
    // 0x800537F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800537F8: lwc1        $f6, 0xB8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB8);
    // 0x800537FC: lwc1        $f3, 0x6788($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6788);
    // 0x80053800: lwc1        $f2, 0x678C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X678C);
    // 0x80053804: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053808: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8005380C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053810: bc1f        L_8005383C
    if (!c1cs) {
        // 0x80053814: nop
    
            goto L_8005383C;
    }
    // 0x80053814: nop

    // 0x80053818: lwc1        $f10, 0xB4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XB4);
    // 0x8005381C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053820: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80053824: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80053828: nop

    // 0x8005382C: bc1f        L_8005383C
    if (!c1cs) {
        // 0x80053830: nop
    
            goto L_8005383C;
    }
    // 0x80053830: nop

    // 0x80053834: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053838: nop

L_8005383C:
    // 0x8005383C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80053840: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80053844: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80053848: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005384C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053850: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80053854: lwc1        $f6, 0xB0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053858: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005385C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053860: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80053864: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x80053868: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8005386C: swc1        $f6, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f6.u32l;
    // 0x80053870: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053874: nop

    // 0x80053878: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x8005387C: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80053880: nop

    // 0x80053884: bc1f        L_80053A24
    if (!c1cs) {
        // 0x80053888: nop
    
            goto L_80053A24;
    }
    // 0x80053888: nop

L_8005388C:
    // 0x8005388C: sub.d       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f12.d - ctx->f16.d;
    // 0x80053890: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80053894: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80053898: swc1        $f4, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f4.u32l;
    // 0x8005389C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_800538A0:
    // 0x800538A0: bne         $at, $zero, L_800538B0
    if (ctx->r1 != 0) {
        // 0x800538A4: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800538B0;
    }
    // 0x800538A4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800538A8: beq         $v0, $zero, L_80053950
    if (ctx->r2 == 0) {
        // 0x800538AC: nop
    
            goto L_80053950;
    }
    // 0x800538AC: nop

L_800538B0:
    // 0x800538B0: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800538B4: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x800538B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800538BC: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x800538C0: beq         $t0, $zero, L_800538D4
    if (ctx->r8 == 0) {
        // 0x800538C4: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800538D4;
    }
    // 0x800538C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800538C8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800538CC: beq         $at, $zero, L_800538DC
    if (ctx->r1 == 0) {
        // 0x800538D0: nop
    
            goto L_800538DC;
    }
    // 0x800538D0: nop

L_800538D4:
    // 0x800538D4: bne         $t0, $zero, L_80053950
    if (ctx->r8 != 0) {
        // 0x800538D8: nop
    
            goto L_80053950;
    }
    // 0x800538D8: nop

L_800538DC:
    // 0x800538DC: lw          $t2, 0x78($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X78);
    // 0x800538E0: nop

    // 0x800538E4: beq         $t2, $zero, L_80053928
    if (ctx->r10 == 0) {
        // 0x800538E8: nop
    
            goto L_80053928;
    }
    // 0x800538E8: nop

    // 0x800538EC: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x800538F0: nop

    // 0x800538F4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800538F8: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
    // 0x800538FC: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x80053900: nop

    // 0x80053904: bgez        $t5, L_80053950
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80053908: nop
    
            goto L_80053950;
    }
    // 0x80053908: nop

    // 0x8005390C: lw          $t6, 0x40($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X40);
    // 0x80053910: nop

    // 0x80053914: lb          $t7, 0x55($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X55);
    // 0x80053918: nop

    // 0x8005391C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80053920: b           L_80053950
    // 0x80053924: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
        goto L_80053950;
    // 0x80053924: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
L_80053928:
    // 0x80053928: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x8005392C: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80053930: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80053934: sb          $t2, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r10;
    // 0x80053938: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x8005393C: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80053940: nop

    // 0x80053944: bne         $t4, $t5, L_80053950
    if (ctx->r12 != ctx->r13) {
        // 0x80053948: nop
    
            goto L_80053950;
    }
    // 0x80053948: nop

    // 0x8005394C: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053950:
    // 0x80053950: blez        $v1, L_80053960
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80053954: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_80053960;
    }
    // 0x80053954: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80053958: beq         $v0, $zero, L_800539FC
    if (ctx->r2 == 0) {
        // 0x8005395C: nop
    
            goto L_800539FC;
    }
    // 0x8005395C: nop

L_80053960:
    // 0x80053960: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80053964: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053968: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005396C: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x80053970: beq         $t0, $zero, L_80053980
    if (ctx->r8 == 0) {
        // 0x80053974: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80053980;
    }
    // 0x80053974: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053978: beq         $at, $zero, L_80053988
    if (ctx->r1 == 0) {
        // 0x8005397C: nop
    
            goto L_80053988;
    }
    // 0x8005397C: nop

L_80053980:
    // 0x80053980: bne         $t0, $zero, L_800539FC
    if (ctx->r8 != 0) {
        // 0x80053984: nop
    
            goto L_800539FC;
    }
    // 0x80053984: nop

L_80053988:
    // 0x80053988: lw          $t9, 0x78($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X78);
    // 0x8005398C: nop

    // 0x80053990: beq         $t9, $zero, L_800539D4
    if (ctx->r25 == 0) {
        // 0x80053994: nop
    
            goto L_800539D4;
    }
    // 0x80053994: nop

    // 0x80053998: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x8005399C: nop

    // 0x800539A0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800539A4: sb          $t3, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r11;
    // 0x800539A8: lb          $t4, 0x3A($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X3A);
    // 0x800539AC: nop

    // 0x800539B0: bgez        $t4, L_800539FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800539B4: nop
    
            goto L_800539FC;
    }
    // 0x800539B4: nop

    // 0x800539B8: lw          $t5, 0x40($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X40);
    // 0x800539BC: nop

    // 0x800539C0: lb          $t6, 0x55($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X55);
    // 0x800539C4: nop

    // 0x800539C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800539CC: b           L_800539FC
    // 0x800539D0: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
        goto L_800539FC;
    // 0x800539D0: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
L_800539D4:
    // 0x800539D4: lb          $t8, 0x3A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X3A);
    // 0x800539D8: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x800539DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800539E0: sb          $t9, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r25;
    // 0x800539E4: lb          $t4, 0x3A($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X3A);
    // 0x800539E8: lb          $t3, 0x55($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X55);
    // 0x800539EC: nop

    // 0x800539F0: bne         $t3, $t4, L_800539FC
    if (ctx->r11 != ctx->r12) {
        // 0x800539F4: nop
    
            goto L_800539FC;
    }
    // 0x800539F4: nop

    // 0x800539F8: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_800539FC:
    // 0x800539FC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053A00: bne         $v1, $t1, L_800538A0
    if (ctx->r3 != ctx->r9) {
        // 0x80053A04: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800538A0;
    }
    // 0x80053A04: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053A08: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053A0C: nop

    // 0x80053A10: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x80053A14: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80053A18: nop

    // 0x80053A1C: bc1t        L_8005388C
    if (c1cs) {
        // 0x80053A20: nop
    
            goto L_8005388C;
    }
    // 0x80053A20: nop

L_80053A24:
    // 0x80053A24: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80053A28: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80053A2C: bc1f        L_80053BCC
    if (!c1cs) {
        // 0x80053A30: nop
    
            goto L_80053BCC;
    }
    // 0x80053A30: nop

L_80053A34:
    // 0x80053A34: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80053A38: add.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
    // 0x80053A3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80053A40: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80053A44: swc1        $f8, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f8.u32l;
    // 0x80053A48: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_80053A4C:
    // 0x80053A4C: bne         $at, $zero, L_80053A5C
    if (ctx->r1 != 0) {
        // 0x80053A50: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80053A5C;
    }
    // 0x80053A50: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80053A54: beq         $v0, $zero, L_80053AFC
    if (ctx->r2 == 0) {
        // 0x80053A58: nop
    
            goto L_80053AFC;
    }
    // 0x80053A58: nop

L_80053A5C:
    // 0x80053A5C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x80053A60: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053A64: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80053A68: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80053A6C: beq         $t0, $zero, L_80053A80
    if (ctx->r8 == 0) {
        // 0x80053A70: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80053A80;
    }
    // 0x80053A70: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80053A74: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80053A78: beq         $at, $zero, L_80053A88
    if (ctx->r1 == 0) {
        // 0x80053A7C: nop
    
            goto L_80053A88;
    }
    // 0x80053A7C: nop

L_80053A80:
    // 0x80053A80: bne         $t0, $zero, L_80053AFC
    if (ctx->r8 != 0) {
        // 0x80053A84: nop
    
            goto L_80053AFC;
    }
    // 0x80053A84: nop

L_80053A88:
    // 0x80053A88: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x80053A8C: nop

    // 0x80053A90: bne         $t8, $zero, L_80053AD4
    if (ctx->r24 != 0) {
        // 0x80053A94: nop
    
            goto L_80053AD4;
    }
    // 0x80053A94: nop

    // 0x80053A98: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053A9C: nop

    // 0x80053AA0: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80053AA4: sb          $t2, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r10;
    // 0x80053AA8: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x80053AAC: nop

    // 0x80053AB0: bgez        $t3, L_80053AFC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80053AB4: nop
    
            goto L_80053AFC;
    }
    // 0x80053AB4: nop

    // 0x80053AB8: lw          $t4, 0x40($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X40);
    // 0x80053ABC: nop

    // 0x80053AC0: lb          $t5, 0x55($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X55);
    // 0x80053AC4: nop

    // 0x80053AC8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80053ACC: b           L_80053AFC
    // 0x80053AD0: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
        goto L_80053AFC;
    // 0x80053AD0: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
L_80053AD4:
    // 0x80053AD4: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80053AD8: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053ADC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80053AE0: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
    // 0x80053AE4: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x80053AE8: lb          $t2, 0x55($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X55);
    // 0x80053AEC: nop

    // 0x80053AF0: bne         $t2, $t3, L_80053AFC
    if (ctx->r10 != ctx->r11) {
        // 0x80053AF4: nop
    
            goto L_80053AFC;
    }
    // 0x80053AF4: nop

    // 0x80053AF8: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053AFC:
    // 0x80053AFC: blez        $v1, L_80053B0C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80053B00: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80053B0C;
    }
    // 0x80053B00: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80053B04: beq         $v0, $zero, L_80053BA8
    if (ctx->r2 == 0) {
        // 0x80053B08: nop
    
            goto L_80053BA8;
    }
    // 0x80053B08: nop

L_80053B0C:
    // 0x80053B0C: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053B10: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053B14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80053B18: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x80053B1C: beq         $t0, $zero, L_80053B2C
    if (ctx->r8 == 0) {
        // 0x80053B20: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80053B2C;
    }
    // 0x80053B20: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053B24: beq         $at, $zero, L_80053B34
    if (ctx->r1 == 0) {
        // 0x80053B28: nop
    
            goto L_80053B34;
    }
    // 0x80053B28: nop

L_80053B2C:
    // 0x80053B2C: bne         $t0, $zero, L_80053BA8
    if (ctx->r8 != 0) {
        // 0x80053B30: nop
    
            goto L_80053BA8;
    }
    // 0x80053B30: nop

L_80053B34:
    // 0x80053B34: lw          $t7, 0x78($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X78);
    // 0x80053B38: nop

    // 0x80053B3C: bne         $t7, $zero, L_80053B80
    if (ctx->r15 != 0) {
        // 0x80053B40: nop
    
            goto L_80053B80;
    }
    // 0x80053B40: nop

    // 0x80053B44: lb          $t8, 0x3A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B48: nop

    // 0x80053B4C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80053B50: sb          $t9, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r25;
    // 0x80053B54: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B58: nop

    // 0x80053B5C: bgez        $t2, L_80053BA8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80053B60: nop
    
            goto L_80053BA8;
    }
    // 0x80053B60: nop

    // 0x80053B64: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80053B68: nop

    // 0x80053B6C: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80053B70: nop

    // 0x80053B74: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80053B78: b           L_80053BA8
    // 0x80053B7C: sb          $t5, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r13;
        goto L_80053BA8;
    // 0x80053B7C: sb          $t5, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r13;
L_80053B80:
    // 0x80053B80: lb          $t6, 0x3A($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B84: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x80053B88: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80053B8C: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
    // 0x80053B90: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B94: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x80053B98: nop

    // 0x80053B9C: bne         $t9, $t2, L_80053BA8
    if (ctx->r25 != ctx->r10) {
        // 0x80053BA0: nop
    
            goto L_80053BA8;
    }
    // 0x80053BA0: nop

    // 0x80053BA4: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053BA8:
    // 0x80053BA8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053BAC: bne         $v1, $t1, L_80053A4C
    if (ctx->r3 != ctx->r9) {
        // 0x80053BB0: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80053A4C;
    }
    // 0x80053BB0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053BB4: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053BB8: nop

    // 0x80053BBC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80053BC0: nop

    // 0x80053BC4: bc1t        L_80053A34
    if (c1cs) {
        // 0x80053BC8: nop
    
            goto L_80053A34;
    }
    // 0x80053BC8: nop

L_80053BCC:
    // 0x80053BCC: lb          $t3, 0x1FB($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053BD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80053BD4: beq         $t3, $zero, L_80053C84
    if (ctx->r11 == 0) {
        // 0x80053BD8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053C84;
    }
    // 0x80053BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053BE0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80053BE4:
    // 0x80053BE4: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053BE8: nop

    // 0x80053BEC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053BF0: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x80053BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80053BF8: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80053BFC: nop

    // 0x80053C00: beq         $t6, $zero, L_80053C44
    if (ctx->r14 == 0) {
        // 0x80053C04: nop
    
            goto L_80053C44;
    }
    // 0x80053C04: nop

    // 0x80053C08: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C0C: nop

    // 0x80053C10: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80053C14: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
    // 0x80053C18: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C1C: nop

    // 0x80053C20: bgez        $t9, L_80053C6C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80053C24: nop
    
            goto L_80053C6C;
    }
    // 0x80053C24: nop

    // 0x80053C28: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053C2C: nop

    // 0x80053C30: lb          $t3, 0x55($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X55);
    // 0x80053C34: nop

    // 0x80053C38: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80053C3C: b           L_80053C6C
    // 0x80053C40: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
        goto L_80053C6C;
    // 0x80053C40: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
L_80053C44:
    // 0x80053C44: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C48: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x80053C4C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80053C50: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
    // 0x80053C54: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C58: lb          $t8, 0x55($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X55);
    // 0x80053C5C: nop

    // 0x80053C60: bne         $t8, $t9, L_80053C6C
    if (ctx->r24 != ctx->r25) {
        // 0x80053C64: nop
    
            goto L_80053C6C;
    }
    // 0x80053C64: nop

    // 0x80053C68: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053C6C:
    // 0x80053C6C: bne         $v0, $v1, L_80053BE4
    if (ctx->r2 != ctx->r3) {
        // 0x80053C70: nop
    
            goto L_80053BE4;
    }
    // 0x80053C70: nop

    // 0x80053C74: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80053C78: nop

    // 0x80053C7C: ori         $t3, $t2, 0xC00
    ctx->r11 = ctx->r10 | 0XC00;
    // 0x80053C80: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
L_80053C84:
    // 0x80053C84: lwc1        $f19, 0x6790($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6790);
    // 0x80053C88: lwc1        $f18, 0x6794($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6794);
    // 0x80053C8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053C90: lwc1        $f17, 0x6798($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6798);
    // 0x80053C94: lwc1        $f16, 0x679C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X679C);
    // 0x80053C98: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80053C9C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80053CA0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80053CA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80053CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053CAC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80053CB0:
    // 0x80053CB0: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053CB4: lb          $t6, 0x1E3($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1E3);
    // 0x80053CB8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053CBC: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x80053CC0: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x80053CC4: bne         $t7, $zero, L_80053D30
    if (ctx->r15 != 0) {
        // 0x80053CC8: sll         $t3, $a3, 1
        ctx->r11 = S32(ctx->r7 << 1);
            goto L_80053D30;
    }
    // 0x80053CC8: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x80053CCC: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053CD0: nop

    // 0x80053CD4: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80053CD8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80053CDC: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80053CE0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80053CE4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80053CE8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053CEC: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80053CF0: lb          $t8, 0x1E5($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1E5);
    // 0x80053CF4: nop

    // 0x80053CF8: beq         $t8, $zero, L_80053D78
    if (ctx->r24 == 0) {
        // 0x80053CFC: nop
    
            goto L_80053D78;
    }
    // 0x80053CFC: nop

    // 0x80053D00: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053D04: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053D08: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80053D0C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053D10: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053D14: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80053D18: sub.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f6.d - ctx->f0.d;
    // 0x80053D1C: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80053D20: add.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d + ctx->f8.d;
    // 0x80053D24: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D28: b           L_80053D78
    // 0x80053D2C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
        goto L_80053D78;
    // 0x80053D2C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
L_80053D30:
    // 0x80053D30: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053D34: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053D38: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053D3C: mul.d       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x80053D40: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053D44: nop

    // 0x80053D48: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053D4C: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x80053D50: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D54: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80053D58: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80053D5C: nop

    // 0x80053D60: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80053D64: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80053D68: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80053D6C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80053D70: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D74: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
L_80053D78:
    // 0x80053D78: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053D7C: lb          $t6, 0x1E3($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1E3);
    // 0x80053D80: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053D84: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80053D88: and         $t7, $t6, $t3
    ctx->r15 = ctx->r14 & ctx->r11;
    // 0x80053D8C: bne         $t7, $zero, L_80053DF8
    if (ctx->r15 != 0) {
        // 0x80053D90: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_80053DF8;
    }
    // 0x80053D90: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80053D94: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053D98: nop

    // 0x80053D9C: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80053DA0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053DA4: mul.d       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80053DA8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80053DAC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80053DB0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053DB4: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80053DB8: lb          $t8, 0x1E5($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1E5);
    // 0x80053DBC: nop

    // 0x80053DC0: beq         $t8, $zero, L_80053E44
    if (ctx->r24 == 0) {
        // 0x80053DC4: sll         $t3, $a3, 1
        ctx->r11 = S32(ctx->r7 << 1);
            goto L_80053E44;
    }
    // 0x80053DC4: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x80053DC8: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053DCC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053DD0: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80053DD4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053DD8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053DDC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80053DE0: sub.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f10.d - ctx->f0.d;
    // 0x80053DE4: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80053DE8: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x80053DEC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053DF0: b           L_80053E40
    // 0x80053DF4: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
        goto L_80053E40;
    // 0x80053DF4: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
L_80053DF8:
    // 0x80053DF8: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053DFC: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053E00: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053E04: mul.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x80053E08: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053E0C: nop

    // 0x80053E10: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053E14: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x80053E18: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053E1C: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80053E20: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80053E24: nop

    // 0x80053E28: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80053E2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053E30: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80053E34: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80053E38: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053E3C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
L_80053E40:
    // 0x80053E40: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
L_80053E44:
    // 0x80053E44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80053E48: bne         $v0, $v1, L_80053CB0
    if (ctx->r2 != ctx->r3) {
        // 0x80053E4C: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_80053CB0;
    }
    // 0x80053E4C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80053E50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80053E54: addiu       $v0, $v0, -0x2ACC
    ctx->r2 = ADD32(ctx->r2, -0X2ACC);
    // 0x80053E58: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80053E5C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80053E60: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053E64: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053E68: nop

    // 0x80053E6C: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    // 0x80053E70: mflo        $t6
    ctx->r14 = lo;
    // 0x80053E74: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80053E78: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80053E7C: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80053E80: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053E84: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    // 0x80053E88: mflo        $t9
    ctx->r25 = lo;
    // 0x80053E8C: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80053E90: nop

L_80053E94:
    // 0x80053E94: jr          $ra
    // 0x80053E98: nop

    return;
    // 0x80053E98: nop

;}
RECOMP_FUNC void func_80050A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A28: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80050A2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050A30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80050A34: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80050A38: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80050A3C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x80050A40: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80050A44: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80050A48: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80050A4C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80050A50: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80050A54: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80050A58: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80050A5C: bc1f        L_80050A74
    if (!c1cs) {
        // 0x80050A60: swc1        $f4, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
            goto L_80050A74;
    }
    // 0x80050A60: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80050A64: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80050A68: nop

    // 0x80050A6C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050A70: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_80050A74:
    // 0x80050A74: swc1        $f14, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f14.u32l;
    // 0x80050A78: swc1        $f14, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f14.u32l;
    // 0x80050A7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050A80: lh          $t6, -0x2A7A($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2A7A);
    // 0x80050A84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050A88: bne         $t6, $zero, L_80050B90
    if (ctx->r14 != 0) {
        // 0x80050A8C: addiu       $t0, $t0, -0x2AD8
        ctx->r8 = ADD32(ctx->r8, -0X2AD8);
            goto L_80050B90;
    }
    // 0x80050A8C: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
    // 0x80050A90: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x80050A94: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80050A98: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80050A9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80050AA0: lb          $t9, -0x3250($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3250);
    // 0x80050AA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050AA8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80050AAC: lwc1        $f7, 0x6638($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6638);
    // 0x80050AB0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80050AB4: lwc1        $f6, 0x663C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X663C);
    // 0x80050AB8: lwc1        $f10, 0xA0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80050ABC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80050AC0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80050AC4: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80050AC8: lwc1        $f6, 0xA4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80050ACC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80050AD0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80050AD4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050AD8: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80050ADC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80050AE0: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x80050AE4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80050AE8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80050AEC: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80050AF0: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    // 0x80050AF4: lw          $v1, 0x60($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X60);
    // 0x80050AF8: nop

    // 0x80050AFC: beq         $v1, $zero, L_80050B88
    if (ctx->r3 == 0) {
        // 0x80050B00: nop
    
            goto L_80050B88;
    }
    // 0x80050B00: nop

    // 0x80050B04: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80050B08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80050B0C: blez        $t2, L_80050B88
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80050B10: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80050B88;
    }
    // 0x80050B10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050B14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80050B18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80050B1C:
    // 0x80050B1C: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80050B20: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80050B24: div.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80050B28: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80050B2C: addu        $t3, $v1, $a0
    ctx->r11 = ADD32(ctx->r3, ctx->r4);
    // 0x80050B30: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x80050B34: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80050B38: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80050B3C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80050B40: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80050B44: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80050B48: nop

    // 0x80050B4C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050B50: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80050B54: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80050B58: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80050B5C: nop

    // 0x80050B60: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80050B64: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80050B68: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80050B6C: lw          $v1, 0x60($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X60);
    // 0x80050B70: nop

    // 0x80050B74: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80050B78: nop

    // 0x80050B7C: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80050B80: bne         $at, $zero, L_80050B1C
    if (ctx->r1 != 0) {
        // 0x80050B84: nop
    
            goto L_80050B1C;
    }
    // 0x80050B84: nop

L_80050B88:
    // 0x80050B88: b           L_80050BA0
    // 0x80050B8C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80050BA0;
    // 0x80050B8C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_80050B90:
    // 0x80050B90: swc1        $f14, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f14.u32l;
    // 0x80050B94: swc1        $f14, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f14.u32l;
    // 0x80050B98: swc1        $f14, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f14.u32l;
    // 0x80050B9C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_80050BA0:
    // 0x80050BA0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050BA4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80050BA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050BAC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80050BB0: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x80050BB4: nop

    // 0x80050BB8: bc1f        L_80050BE4
    if (!c1cs) {
        // 0x80050BBC: nop
    
            goto L_80050BE4;
    }
    // 0x80050BBC: nop

    // 0x80050BC0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80050BC4: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80050BC8: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80050BCC: beq         $t6, $zero, L_80050BDC
    if (ctx->r14 == 0) {
        // 0x80050BD0: nop
    
            goto L_80050BDC;
    }
    // 0x80050BD0: nop

    // 0x80050BD4: b           L_80050C00
    // 0x80050BD8: sb          $t7, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r15;
        goto L_80050C00;
    // 0x80050BD8: sb          $t7, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r15;
L_80050BDC:
    // 0x80050BDC: b           L_80050C00
    // 0x80050BE0: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
        goto L_80050C00;
    // 0x80050BE0: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050BE4:
    // 0x80050BE4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80050BE8: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x80050BEC: nop

    // 0x80050BF0: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80050BF4: bne         $t9, $zero, L_80050C00
    if (ctx->r25 != 0) {
        // 0x80050BF8: nop
    
            goto L_80050C00;
    }
    // 0x80050BF8: nop

    // 0x80050BFC: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050C00:
    // 0x80050C00: lb          $v0, 0x1FB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1FB);
    // 0x80050C04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050C08: blez        $v0, L_80050C24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050C0C: addiu       $t0, $t0, -0x2AD8
        ctx->r8 = ADD32(ctx->r8, -0X2AD8);
            goto L_80050C24;
    }
    // 0x80050C0C: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
    // 0x80050C10: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80050C14: nop

    // 0x80050C18: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80050C1C: b           L_80050C28
    // 0x80050C20: sb          $t3, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r11;
        goto L_80050C28;
    // 0x80050C20: sb          $t3, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r11;
L_80050C24:
    // 0x80050C24: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050C28:
    // 0x80050C28: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80050C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050C30: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80050C34: lwc1        $f5, 0x6640($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6640);
    // 0x80050C38: lwc1        $f4, 0x6644($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6644);
    // 0x80050C3C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80050C40: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80050C44: nop

    // 0x80050C48: bc1f        L_80050D6C
    if (!c1cs) {
        // 0x80050C4C: nop
    
            goto L_80050D6C;
    }
    // 0x80050C4C: nop

    // 0x80050C50: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050C54: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80050C58: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80050C5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80050C60: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80050C64: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80050C68: nop

    // 0x80050C6C: bc1f        L_80050C9C
    if (!c1cs) {
        // 0x80050C70: nop
    
            goto L_80050C9C;
    }
    // 0x80050C70: nop

    // 0x80050C74: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x80050C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80050C7C: bne         $t4, $zero, L_80050C9C
    if (ctx->r12 != 0) {
        // 0x80050C80: nop
    
            goto L_80050C9C;
    }
    // 0x80050C80: nop

    // 0x80050C84: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80050C88: jal         0x80072348
    // 0x80050C8C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    rumble_set(rdram, ctx);
        goto after_0;
    // 0x80050C8C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_0:
    // 0x80050C90: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050C94: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80050C98: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_80050C9C:
    // 0x80050C9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050CA0: lw          $t6, -0x2AA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AA4);
    // 0x80050CA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050CA8: bltz        $t6, L_80050D20
    if (SIGNED(ctx->r14) < 0) {
        // 0x80050CAC: sw          $t5, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r13;
            goto L_80050D20;
    }
    // 0x80050CAC: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80050CB0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80050CB4: lw          $t7, -0x3468($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3468);
    // 0x80050CB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050CBC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80050CC0: beq         $at, $zero, L_80050D1C
    if (ctx->r1 == 0) {
        // 0x80050CC4: nop
    
            goto L_80050D1C;
    }
    // 0x80050CC4: nop

    // 0x80050CC8: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050CCC: nop

    // 0x80050CD0: blez        $a0, L_80050CEC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050CD4: nop
    
            goto L_80050CEC;
    }
    // 0x80050CD4: nop

    // 0x80050CD8: lw          $t8, 0x74($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X74);
    // 0x80050CDC: nop

    // 0x80050CE0: ori         $t9, $t8, 0x1400
    ctx->r25 = ctx->r24 | 0X1400;
    // 0x80050CE4: b           L_80050D20
    // 0x80050CE8: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
        goto L_80050D20;
    // 0x80050CE8: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
L_80050CEC:
    // 0x80050CEC: bgez        $a0, L_80050D08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80050CF0: nop
    
            goto L_80050D08;
    }
    // 0x80050CF0: nop

    // 0x80050CF4: lw          $t2, 0x74($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X74);
    // 0x80050CF8: nop

    // 0x80050CFC: ori         $t3, $t2, 0x2800
    ctx->r11 = ctx->r10 | 0X2800;
    // 0x80050D00: b           L_80050D20
    // 0x80050D04: sw          $t3, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r11;
        goto L_80050D20;
    // 0x80050D04: sw          $t3, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r11;
L_80050D08:
    // 0x80050D08: lw          $t4, 0x74($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X74);
    // 0x80050D0C: nop

    // 0x80050D10: ori         $t5, $t4, 0x3000
    ctx->r13 = ctx->r12 | 0X3000;
    // 0x80050D14: b           L_80050D20
    // 0x80050D18: sw          $t5, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r13;
        goto L_80050D20;
    // 0x80050D18: sw          $t5, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r13;
L_80050D1C:
    // 0x80050D1C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_80050D20:
    // 0x80050D20: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x80050D24: addiu       $a0, $zero, -0x19
    ctx->r4 = ADD32(0, -0X19);
    // 0x80050D28: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80050D2C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80050D30: beq         $at, $zero, L_80050D50
    if (ctx->r1 == 0) {
        // 0x80050D34: addiu       $a1, $zero, 0x19
        ctx->r5 = ADD32(0, 0X19);
            goto L_80050D50;
    }
    // 0x80050D34: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80050D38: jal         0x8006F94C
    // 0x80050D3C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80050D3C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_1:
    // 0x80050D40: sb          $v0, 0x1D1($s0)
    MEM_B(0X1D1, ctx->r16) = ctx->r2;
    // 0x80050D44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050D48: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80050D4C: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_80050D50:
    // 0x80050D50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050D54: addiu       $t1, $t1, -0x2ACC
    ctx->r9 = ADD32(ctx->r9, -0X2ACC);
    // 0x80050D58: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80050D5C: lb          $t2, 0x1D1($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D1);
    // 0x80050D60: nop

    // 0x80050D64: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80050D68: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80050D6C:
    // 0x80050D6C: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050D70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050D74: bne         $a0, $zero, L_80050DF8
    if (ctx->r4 != 0) {
        // 0x80050D78: addiu       $t1, $t1, -0x2ACC
        ctx->r9 = ADD32(ctx->r9, -0X2ACC);
            goto L_80050DF8;
    }
    // 0x80050D78: addiu       $t1, $t1, -0x2ACC
    ctx->r9 = ADD32(ctx->r9, -0X2ACC);
    // 0x80050D7C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050D80: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050D84: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80050D88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050D8C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80050D90: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80050D94: nop

    // 0x80050D98: bc1f        L_80050DF8
    if (!c1cs) {
        // 0x80050D9C: nop
    
            goto L_80050DF8;
    }
    // 0x80050D9C: nop

    // 0x80050DA0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80050DA4: nop

    // 0x80050DA8: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80050DAC: beq         $t5, $zero, L_80050DF8
    if (ctx->r13 == 0) {
        // 0x80050DB0: nop
    
            goto L_80050DF8;
    }
    // 0x80050DB0: nop

    // 0x80050DB4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80050DB8: nop

    // 0x80050DBC: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80050DC0: beq         $at, $zero, L_80050DD0
    if (ctx->r1 == 0) {
        // 0x80050DC4: slti        $at, $v0, -0x32
        ctx->r1 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
            goto L_80050DD0;
    }
    // 0x80050DC4: slti        $at, $v0, -0x32
    ctx->r1 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
    // 0x80050DC8: beq         $at, $zero, L_80050DF8
    if (ctx->r1 == 0) {
        // 0x80050DCC: nop
    
            goto L_80050DF8;
    }
    // 0x80050DCC: nop

L_80050DD0:
    // 0x80050DD0: blez        $v0, L_80050DEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050DD4: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80050DEC;
    }
    // 0x80050DD4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80050DD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050DDC: sb          $t6, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = ctx->r14;
    // 0x80050DE0: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050DE4: b           L_80050DF8
    // 0x80050DE8: nop

        goto L_80050DF8;
    // 0x80050DE8: nop

L_80050DEC:
    // 0x80050DEC: sb          $t7, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = ctx->r15;
    // 0x80050DF0: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050DF4: nop

L_80050DF8:
    // 0x80050DF8: beq         $a0, $zero, L_80050F08
    if (ctx->r4 == 0) {
        // 0x80050DFC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80050F08;
    }
    // 0x80050DFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050E00: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80050E04: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80050E08: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80050E0C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80050E10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80050E14: ori         $t3, $t9, 0x4000
    ctx->r11 = ctx->r25 | 0X4000;
    // 0x80050E18: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80050E1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80050E20: lw          $t6, -0x3468($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3468);
    // 0x80050E24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050E28: addiu       $t4, $zero, -0x46
    ctx->r12 = ADD32(0, -0X46);
    // 0x80050E2C: sw          $t4, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r12;
    // 0x80050E30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050E34: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80050E38: beq         $at, $zero, L_80050E54
    if (ctx->r1 == 0) {
        // 0x80050E3C: sw          $t5, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r13;
            goto L_80050E54;
    }
    // 0x80050E3C: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80050E40: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80050E44: nop

    // 0x80050E48: ori         $t8, $t7, 0x3C00
    ctx->r24 = ctx->r15 | 0X3C00;
    // 0x80050E4C: b           L_80050E5C
    // 0x80050E50: sw          $t8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r24;
        goto L_80050E5C;
    // 0x80050E50: sw          $t8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r24;
L_80050E54:
    // 0x80050E54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80050E58: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_80050E5C:
    // 0x80050E5C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80050E60: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050E64: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80050E68: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80050E6C: sll         $t3, $t3, 9
    ctx->r11 = S32(ctx->r11 << 9);
    // 0x80050E70: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050E74: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050E78: nop

    // 0x80050E7C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80050E80: mflo        $t4
    ctx->r12 = lo;
    // 0x80050E84: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80050E88: blez        $a0, L_80050EB8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050E8C: sh          $t5, 0x1A2($s0)
        MEM_H(0X1A2, ctx->r16) = ctx->r13;
            goto L_80050EB8;
    }
    // 0x80050E8C: sh          $t5, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r13;
    // 0x80050E90: lh          $t6, 0x1A2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050E94: nop

    // 0x80050E98: bgez        $t6, L_80050EDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80050E9C: nop
    
            goto L_80050EDC;
    }
    // 0x80050E9C: nop

    // 0x80050EA0: bltz        $v1, L_80050EDC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80050EA4: addiu       $t7, $zero, 0x7FFF
        ctx->r15 = ADD32(0, 0X7FFF);
            goto L_80050EDC;
    }
    // 0x80050EA4: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80050EA8: sb          $zero, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = 0;
    // 0x80050EAC: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050EB0: b           L_80050EDC
    // 0x80050EB4: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
        goto L_80050EDC;
    // 0x80050EB4: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
L_80050EB8:
    // 0x80050EB8: lh          $t8, 0x1A2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050EBC: nop

    // 0x80050EC0: blez        $t8, L_80050EDC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80050EC4: nop
    
            goto L_80050EDC;
    }
    // 0x80050EC4: nop

    // 0x80050EC8: bgtz        $a2, L_80050EDC
    if (SIGNED(ctx->r6) > 0) {
        // 0x80050ECC: addiu       $t9, $zero, -0x8000
        ctx->r25 = ADD32(0, -0X8000);
            goto L_80050EDC;
    }
    // 0x80050ECC: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x80050ED0: sb          $zero, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = 0;
    // 0x80050ED4: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050ED8: sh          $t9, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r25;
L_80050EDC:
    // 0x80050EDC: bne         $a0, $zero, L_80050F08
    if (ctx->r4 != 0) {
        // 0x80050EE0: nop
    
            goto L_80050F08;
    }
    // 0x80050EE0: nop

    // 0x80050EE4: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050EE8: lh          $t2, 0x1A0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A0);
    // 0x80050EEC: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050EF0: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80050EF4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80050EF8: sh          $t3, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r11;
    // 0x80050EFC: sh          $zero, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = 0;
    // 0x80050F00: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80050F04: sh          $v1, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r3;
L_80050F08:
    // 0x80050F08: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050F0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050F10: beq         $a0, $zero, L_80050F78
    if (ctx->r4 == 0) {
        // 0x80050F14: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80050F78;
    }
    // 0x80050F14: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80050F18: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x80050F1C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80050F20: bltz        $t4, L_80050F78
    if (SIGNED(ctx->r12) < 0) {
        // 0x80050F24: nop
    
            goto L_80050F78;
    }
    // 0x80050F24: nop

    // 0x80050F28: lw          $t5, -0x3468($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3468);
    // 0x80050F2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050F30: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80050F34: beq         $at, $zero, L_80050F74
    if (ctx->r1 == 0) {
        // 0x80050F38: nop
    
            goto L_80050F74;
    }
    // 0x80050F38: nop

    // 0x80050F3C: blez        $a0, L_80050F58
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050F40: nop
    
            goto L_80050F58;
    }
    // 0x80050F40: nop

    // 0x80050F44: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x80050F48: nop

    // 0x80050F4C: ori         $t7, $t6, 0x1400
    ctx->r15 = ctx->r14 | 0X1400;
    // 0x80050F50: b           L_80050F68
    // 0x80050F54: sw          $t7, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r15;
        goto L_80050F68;
    // 0x80050F54: sw          $t7, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r15;
L_80050F58:
    // 0x80050F58: lw          $t8, 0x74($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X74);
    // 0x80050F5C: nop

    // 0x80050F60: ori         $t9, $t8, 0x2800
    ctx->r25 = ctx->r24 | 0X2800;
    // 0x80050F64: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
L_80050F68:
    // 0x80050F68: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050F6C: b           L_80050F78
    // 0x80050F70: nop

        goto L_80050F78;
    // 0x80050F70: nop

L_80050F74:
    // 0x80050F74: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80050F78:
    // 0x80050F78: bne         $a0, $zero, L_80050FF0
    if (ctx->r4 != 0) {
        // 0x80050F7C: nop
    
            goto L_80050FF0;
    }
    // 0x80050F7C: nop

    // 0x80050F80: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80050F84: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80050F88: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80050F8C: beq         $t4, $zero, L_80050FF0
    if (ctx->r12 == 0) {
        // 0x80050F90: nop
    
            goto L_80050FF0;
    }
    // 0x80050F90: nop

    // 0x80050F94: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050F98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80050F9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050FA0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80050FA4: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80050FA8: nop

    // 0x80050FAC: bc1f        L_80050FF0
    if (!c1cs) {
        // 0x80050FB0: nop
    
            goto L_80050FF0;
    }
    // 0x80050FB0: nop

    // 0x80050FB4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80050FB8: nop

    // 0x80050FBC: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80050FC0: beq         $at, $zero, L_80050FD0
    if (ctx->r1 == 0) {
        // 0x80050FC4: slti        $at, $v0, -0xF
        ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
            goto L_80050FD0;
    }
    // 0x80050FC4: slti        $at, $v0, -0xF
    ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
    // 0x80050FC8: beq         $at, $zero, L_80050FF0
    if (ctx->r1 == 0) {
        // 0x80050FCC: nop
    
            goto L_80050FF0;
    }
    // 0x80050FCC: nop

L_80050FD0:
    // 0x80050FD0: bgez        $v0, L_80050FE4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050FD4: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80050FE4;
    }
    // 0x80050FD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80050FD8: sb          $t5, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r13;
    // 0x80050FDC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80050FE0: nop

L_80050FE4:
    // 0x80050FE4: blez        $v0, L_80050FF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050FE8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80050FF0;
    }
    // 0x80050FE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050FEC: sb          $t6, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r14;
L_80050FF0:
    // 0x80050FF0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050FF4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80050FF8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80050FFC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80051000: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80051004: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80051008: bc1f        L_80051014
    if (!c1cs) {
        // 0x8005100C: nop
    
            goto L_80051014;
    }
    // 0x8005100C: nop

    // 0x80051010: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_80051014:
    // 0x80051014: jal         0x80057220
    // 0x80051018: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    handle_racer_top_speed(rdram, ctx);
        goto after_2;
    // 0x80051018: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005101C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80051020: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x80051024: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80051028: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8005102C: beq         $t8, $zero, L_80051094
    if (ctx->r24 == 0) {
        // 0x80051030: nop
    
            goto L_80051094;
    }
    // 0x80051030: nop

    // 0x80051034: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80051038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005103C: beq         $a0, $zero, L_80051094
    if (ctx->r4 == 0) {
        // 0x80051040: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80051094;
    }
    // 0x80051040: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80051044: lwc1        $f9, 0x6648($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6648);
    // 0x80051048: lwc1        $f8, 0x664C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X664C);
    // 0x8005104C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80051050: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80051054: lw          $t9, -0x2ACC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2ACC);
    // 0x80051058: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x8005105C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80051060: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80051064: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80051068: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8005106C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80051070: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x80051074: bne         $at, $zero, L_80051080
    if (ctx->r1 != 0) {
        // 0x80051078: swc1        $f18, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
            goto L_80051080;
    }
    // 0x80051078: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8005107C: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_80051080:
    // 0x80051080: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x80051084: beq         $at, $zero, L_800510A0
    if (ctx->r1 == 0) {
        // 0x80051088: nop
    
            goto L_800510A0;
    }
    // 0x80051088: nop

    // 0x8005108C: b           L_800510A4
    // 0x80051090: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
        goto L_800510A4;
    // 0x80051090: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_80051094:
    // 0x80051094: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x80051098: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x8005109C: nop

L_800510A0:
    // 0x800510A0: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_800510A4:
    // 0x800510A4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800510A8: sll         $t4, $a0, 13
    ctx->r12 = S32(ctx->r4 << 13);
    // 0x800510AC: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x800510B0: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800510B4: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x800510B8: nop

    // 0x800510BC: slti        $at, $v1, 0x1801
    ctx->r1 = SIGNED(ctx->r3) < 0X1801 ? 1 : 0;
    // 0x800510C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800510C4: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800510C8: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800510CC: beq         $at, $zero, L_80051104
    if (ctx->r1 == 0) {
        // 0x800510D0: sw          $t9, 0x10C($s0)
        MEM_W(0X10C, ctx->r16) = ctx->r25;
            goto L_80051104;
    }
    // 0x800510D0: sw          $t9, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r25;
    // 0x800510D4: slti        $at, $v1, -0x1800
    ctx->r1 = SIGNED(ctx->r3) < -0X1800 ? 1 : 0;
    // 0x800510D8: bne         $at, $zero, L_80051108
    if (ctx->r1 != 0) {
        // 0x800510DC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051108;
    }
    // 0x800510DC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800510E0: bne         $a0, $zero, L_80051108
    if (ctx->r4 != 0) {
        // 0x800510E4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051108;
    }
    // 0x800510E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800510E8: lb          $t2, 0x1FA($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1FA);
    // 0x800510EC: nop

    // 0x800510F0: bne         $t2, $zero, L_80051108
    if (ctx->r10 != 0) {
        // 0x800510F4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051108;
    }
    // 0x800510F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800510F8: lb          $t3, 0x1FB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1FB);
    // 0x800510FC: nop

    // 0x80051100: beq         $t3, $zero, L_8005122C
    if (ctx->r11 == 0) {
        // 0x80051104: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005122C;
    }
L_80051104:
    // 0x80051104: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80051108:
    // 0x80051108: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8005110C: lb          $t5, 0x1FB($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1FB);
    // 0x80051110: nop

    // 0x80051114: beq         $t5, $zero, L_80051140
    if (ctx->r13 == 0) {
        // 0x80051118: nop
    
            goto L_80051140;
    }
    // 0x80051118: nop

    // 0x8005111C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051120: nop

    // 0x80051124: bne         $t6, $zero, L_80051140
    if (ctx->r14 != 0) {
        // 0x80051128: nop
    
            goto L_80051140;
    }
    // 0x80051128: nop

    // 0x8005112C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051130: jal         0x80072348
    // 0x80051134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    rumble_set(rdram, ctx);
        goto after_3;
    // 0x80051134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80051138: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x8005113C: nop

L_80051140:
    // 0x80051140: bgez        $v1, L_80051168
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80051144: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_80051168;
    }
    // 0x80051144: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80051148: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005114C: nop

    // 0x80051150: lw          $t7, 0x74($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X74);
    // 0x80051154: nop

    // 0x80051158: ori         $t8, $t7, 0x1400
    ctx->r24 = ctx->r15 | 0X1400;
    // 0x8005115C: b           L_8005117C
    // 0x80051160: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
        goto L_8005117C;
    // 0x80051160: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
    // 0x80051164: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
L_80051168:
    // 0x80051168: nop

    // 0x8005116C: lw          $t2, 0x74($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X74);
    // 0x80051170: nop

    // 0x80051174: ori         $t3, $t2, 0x2800
    ctx->r11 = ctx->r10 | 0X2800;
    // 0x80051178: sw          $t3, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r11;
L_8005117C:
    // 0x8005117C: lb          $t4, 0x1E6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E6);
    // 0x80051180: nop

    // 0x80051184: bne         $t4, $zero, L_800511AC
    if (ctx->r12 != 0) {
        // 0x80051188: nop
    
            goto L_800511AC;
    }
    // 0x80051188: nop

    // 0x8005118C: lb          $t5, 0x1FA($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1FA);
    // 0x80051190: nop

    // 0x80051194: bne         $t5, $zero, L_800511AC
    if (ctx->r13 != 0) {
        // 0x80051198: nop
    
            goto L_800511AC;
    }
    // 0x80051198: nop

    // 0x8005119C: lb          $t6, 0x1FB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1FB);
    // 0x800511A0: nop

    // 0x800511A4: beq         $t6, $zero, L_8005120C
    if (ctx->r14 == 0) {
        // 0x800511A8: nop
    
            goto L_8005120C;
    }
    // 0x800511A8: nop

L_800511AC:
    // 0x800511AC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800511B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800511B4: bne         $v0, $zero, L_800511D8
    if (ctx->r2 != 0) {
        // 0x800511B8: addiu       $t7, $s0, 0x10
        ctx->r15 = ADD32(ctx->r16, 0X10);
            goto L_800511D8;
    }
    // 0x800511B8: addiu       $t7, $s0, 0x10
    ctx->r15 = ADD32(ctx->r16, 0X10);
    // 0x800511BC: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800511C0: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x800511C4: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x800511C8: jal         0x80001EA8
    // 0x800511CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    sound_play_spatial(rdram, ctx);
        goto after_4;
    // 0x800511CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x800511D0: b           L_800511F0
    // 0x800511D4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_800511F0;
    // 0x800511D4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_800511D8:
    // 0x800511D8: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800511DC: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x800511E0: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x800511E4: jal         0x80009B7C
    // 0x800511E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    audspat_calculate_echo(rdram, ctx);
        goto after_5;
    // 0x800511E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800511EC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_800511F0:
    // 0x800511F0: nop

    // 0x800511F4: beq         $v0, $zero, L_80051204
    if (ctx->r2 == 0) {
        // 0x800511F8: nop
    
            goto L_80051204;
    }
    // 0x800511F8: nop

    // 0x800511FC: jal         0x8000488C
    // 0x80051200: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_6;
    // 0x80051200: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
L_80051204:
    // 0x80051204: b           L_8005125C
    // 0x80051208: nop

        goto L_8005125C;
    // 0x80051208: nop

L_8005120C:
    // 0x8005120C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80051210: nop

    // 0x80051214: beq         $v0, $zero, L_8005125C
    if (ctx->r2 == 0) {
        // 0x80051218: nop
    
            goto L_8005125C;
    }
    // 0x80051218: nop

    // 0x8005121C: jal         0x8000488C
    // 0x80051220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_7;
    // 0x80051220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80051224: b           L_8005125C
    // 0x80051228: nop

        goto L_8005125C;
    // 0x80051228: nop

L_8005122C:
    // 0x8005122C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80051230: nop

    // 0x80051234: beq         $v0, $zero, L_80051244
    if (ctx->r2 == 0) {
        // 0x80051238: nop
    
            goto L_80051244;
    }
    // 0x80051238: nop

    // 0x8005123C: jal         0x8000488C
    // 0x80051240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_8;
    // 0x80051240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
L_80051244:
    // 0x80051244: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80051248: nop

    // 0x8005124C: beq         $v0, $zero, L_8005125C
    if (ctx->r2 == 0) {
        // 0x80051250: nop
    
            goto L_8005125C;
    }
    // 0x80051250: nop

    // 0x80051254: jal         0x8000488C
    // 0x80051258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_9;
    // 0x80051258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
L_8005125C:
    // 0x8005125C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80051260: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x80051264: lb          $v1, 0x1E1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E1);
    // 0x80051268: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x8005126C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80051270: beq         $t8, $zero, L_8005127C
    if (ctx->r24 == 0) {
        // 0x80051274: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8005127C;
    }
    // 0x80051274: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80051278: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_8005127C:
    // 0x8005127C: beq         $v0, $zero, L_80051298
    if (ctx->r2 == 0) {
        // 0x80051280: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051298;
    }
    // 0x80051280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051284: lb          $t2, 0x1E6($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1E6);
    // 0x80051288: nop

    // 0x8005128C: beq         $t2, $zero, L_80051298
    if (ctx->r10 == 0) {
        // 0x80051290: nop
    
            goto L_80051298;
    }
    // 0x80051290: nop

    // 0x80051294: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
L_80051298:
    // 0x80051298: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005129C: lwc1        $f5, 0x6650($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6650);
    // 0x800512A0: lwc1        $f4, 0x6654($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6654);
    // 0x800512A4: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x800512A8: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800512AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800512B0: bc1f        L_800512C8
    if (!c1cs) {
        // 0x800512B4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800512C8;
    }
    // 0x800512B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800512B8: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800512BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800512C0: nop

    // 0x800512C4: nop

L_800512C8:
    // 0x800512C8: lwc1        $f9, 0x6658($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6658);
    // 0x800512CC: lwc1        $f8, 0x665C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X665C);
    // 0x800512D0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800512D4: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x800512D8: nop

    // 0x800512DC: bc1f        L_800512F4
    if (!c1cs) {
        // 0x800512E0: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800512F4;
    }
    // 0x800512E0: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800512E4: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800512E8: mflo        $v0
    ctx->r2 = lo;
    // 0x800512EC: nop

    // 0x800512F0: nop

L_800512F4:
    // 0x800512F4: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800512F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800512FC: lwc1        $f10, -0x2A90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x80051300: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80051304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051308: mflo        $v0
    ctx->r2 = lo;
    // 0x8005130C: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80051310: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80051314: nop

    // 0x80051318: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005131C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80051320: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80051324: nop

    // 0x80051328: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8005132C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051330: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80051334: nop

    // 0x80051338: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005133C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80051340: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80051344: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80051348: jal         0x80053478
    // 0x8005134C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    handle_car_steering(rdram, ctx);
        goto after_10;
    // 0x8005134C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    after_10:
    // 0x80051350: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051354: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80051358: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005135C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051360: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80051364: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80051368: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005136C: bc1f        L_80051438
    if (!c1cs) {
        // 0x80051370: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80051438;
    }
    // 0x80051370: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80051374: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80051378: lw          $v0, -0x2AAC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AAC);
    // 0x8005137C: nop

    // 0x80051380: slti        $at, $v0, 0x1401
    ctx->r1 = SIGNED(ctx->r2) < 0X1401 ? 1 : 0;
    // 0x80051384: beq         $at, $zero, L_800513A4
    if (ctx->r1 == 0) {
        // 0x80051388: nop
    
            goto L_800513A4;
    }
    // 0x80051388: nop

    // 0x8005138C: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80051390: slti        $at, $v0, -0x1400
    ctx->r1 = SIGNED(ctx->r2) < -0X1400 ? 1 : 0;
    // 0x80051394: beq         $a0, $zero, L_800513E4
    if (ctx->r4 == 0) {
        // 0x80051398: nop
    
            goto L_800513E4;
    }
    // 0x80051398: nop

    // 0x8005139C: blez        $v0, L_800513E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800513A0: nop
    
            goto L_800513E4;
    }
    // 0x800513A0: nop

L_800513A4:
    // 0x800513A4: lb          $a2, 0x1E7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E7);
    // 0x800513A8: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800513AC: andi        $t2, $a2, 0x7
    ctx->r10 = ctx->r6 & 0X7;
    // 0x800513B0: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800513B4: bne         $at, $zero, L_800513C0
    if (ctx->r1 != 0) {
        // 0x800513B8: or          $a2, $t2, $zero
        ctx->r6 = ctx->r10 | 0;
            goto L_800513C0;
    }
    // 0x800513B8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800513BC: subu        $a2, $t3, $t2
    ctx->r6 = SUB32(ctx->r11, ctx->r10);
L_800513C0:
    // 0x800513C0: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800513C4: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x800513C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800513CC: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x800513D0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800513D4: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x800513D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800513DC: b           L_80051438
    // 0x800513E0: sw          $t4, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r12;
        goto L_80051438;
    // 0x800513E0: sw          $t4, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r12;
L_800513E4:
    // 0x800513E4: bne         $at, $zero, L_800513FC
    if (ctx->r1 != 0) {
        // 0x800513E8: nop
    
            goto L_800513FC;
    }
    // 0x800513E8: nop

    // 0x800513EC: beq         $a0, $zero, L_80051438
    if (ctx->r4 == 0) {
        // 0x800513F0: nop
    
            goto L_80051438;
    }
    // 0x800513F0: nop

    // 0x800513F4: bgez        $v0, L_80051438
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800513F8: nop
    
            goto L_80051438;
    }
    // 0x800513F8: nop

L_800513FC:
    // 0x800513FC: lb          $a2, 0x1E7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E7);
    // 0x80051400: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80051404: andi        $t5, $a2, 0x7
    ctx->r13 = ctx->r6 & 0X7;
    // 0x80051408: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8005140C: bne         $at, $zero, L_80051418
    if (ctx->r1 != 0) {
        // 0x80051410: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_80051418;
    }
    // 0x80051410: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80051414: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
L_80051418:
    // 0x80051418: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8005141C: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80051420: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051424: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x80051428: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005142C: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x80051430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80051434: sw          $t8, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r24;
L_80051438:
    // 0x80051438: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005143C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80051440: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80051444: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005144C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_80051450:
    // 0x80051450: lbu         $t2, 0x1DC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1DC);
    // 0x80051454: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80051458: beq         $t2, $at, L_8005153C
    if (ctx->r10 == ctx->r1) {
        // 0x8005145C: nop
    
            goto L_8005153C;
    }
    // 0x8005145C: nop

    // 0x80051460: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80051464: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80051468: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x8005146C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051470: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80051474: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051478: jal         0x8009C30C
    // 0x8005147C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_11;
    // 0x8005147C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x80051480: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80051484: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80051488: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8005148C: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x80051490: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051494: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80051498: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005149C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800514A0: sll         $t3, $v0, 8
    ctx->r11 = S32(ctx->r2 << 8);
    // 0x800514A4: bgez        $t3, L_800514C0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800514A8: addiu       $a3, $a3, -0x3464
        ctx->r7 = ADD32(ctx->r7, -0X3464);
            goto L_800514C0;
    }
    // 0x800514A8: addiu       $a3, $a3, -0x3464
    ctx->r7 = ADD32(ctx->r7, -0X3464);
    // 0x800514AC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800514B0: lbu         $v0, 0x1DC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DC);
    // 0x800514B4: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800514B8: b           L_800514DC
    // 0x800514BC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_800514DC;
    // 0x800514BC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_800514C0:
    // 0x800514C0: lbu         $v0, 0x1DC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DC);
    // 0x800514C4: nop

    // 0x800514C8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800514CC: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x800514D0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800514D4: nop

    // 0x800514D8: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_800514DC:
    // 0x800514DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800514E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800514E4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800514E8: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x800514EC: lwc1        $f6, -0x3418($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3418);
    // 0x800514F0: lw          $t5, -0x33CC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X33CC);
    // 0x800514F4: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800514F8: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800514FC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80051500: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80051504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051508: beq         $at, $zero, L_80051514
    if (ctx->r1 == 0) {
        // 0x8005150C: add.s       $f16, $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
            goto L_80051514;
    }
    // 0x8005150C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80051510: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_80051514:
    // 0x80051514: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80051518: bne         $a0, $at, L_80051530
    if (ctx->r4 != ctx->r1) {
        // 0x8005151C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80051530;
    }
    // 0x8005151C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051520: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80051524: sll         $t7, $t0, 24
    ctx->r15 = S32(ctx->r8 << 24);
    // 0x80051528: sra         $t0, $t7, 24
    ctx->r8 = S32(SIGNED(ctx->r15) >> 24);
    // 0x8005152C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80051530:
    // 0x80051530: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80051534: nop

    // 0x80051538: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8005153C:
    // 0x8005153C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80051540: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80051544: bne         $at, $zero, L_80051450
    if (ctx->r1 != 0) {
        // 0x80051548: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80051450;
    }
    // 0x80051548: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005154C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051550: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80051554: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80051558: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8005155C: nop

    // 0x80051560: bc1f        L_80051574
    if (!c1cs) {
        // 0x80051564: nop
    
            goto L_80051574;
    }
    // 0x80051564: nop

    // 0x80051568: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8005156C: nop

    // 0x80051570: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
L_80051574:
    // 0x80051574: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80051578: nop

    // 0x8005157C: bne         $t2, $zero, L_800515B4
    if (ctx->r10 != 0) {
        // 0x80051580: nop
    
            goto L_800515B4;
    }
    // 0x80051580: nop

    // 0x80051584: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x80051588: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8005158C: beq         $t3, $zero, L_800515B4
    if (ctx->r11 == 0) {
        // 0x80051590: nop
    
            goto L_800515B4;
    }
    // 0x80051590: nop

    // 0x80051594: bne         $t1, $at, L_800515B4
    if (ctx->r9 != ctx->r1) {
        // 0x80051598: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800515B4;
    }
    // 0x80051598: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005159C: lw          $t9, -0x2AD4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AD4);
    // 0x800515A0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800515A4: andi        $t4, $t9, 0x2000
    ctx->r12 = ctx->r25 & 0X2000;
    // 0x800515A8: beq         $t4, $zero, L_800515B4
    if (ctx->r12 == 0) {
        // 0x800515AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800515B4;
    }
    // 0x800515AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800515B0: sb          $t5, -0x2A7E($at)
    MEM_B(-0X2A7E, ctx->r1) = ctx->r13;
L_800515B4:
    // 0x800515B4: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800515B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800515BC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800515C0: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800515C4: nop

    // 0x800515C8: bc1t        L_800515DC
    if (c1cs) {
        // 0x800515CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800515DC;
    }
    // 0x800515CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800515D0: lwc1        $f14, 0x6660($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6660);
    // 0x800515D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800515D8: nop

L_800515DC:
    // 0x800515DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800515E0: bne         $t1, $at, L_8005164C
    if (ctx->r9 != ctx->r1) {
        // 0x800515E4: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005164C;
    }
    // 0x800515E4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800515E8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800515EC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800515F0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800515F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800515F8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800515FC: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80051600: nop

    // 0x80051604: bc1f        L_8005164C
    if (!c1cs) {
        // 0x80051608: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005164C;
    }
    // 0x80051608: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8005160C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051614: bne         $t6, $zero, L_8005164C
    if (ctx->r14 != 0) {
        // 0x80051618: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005164C;
    }
    // 0x80051618: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8005161C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051620: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80051624: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051628: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005162C: jal         0x80072348
    // 0x80051630: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    rumble_set(rdram, ctx);
        goto after_12;
    // 0x80051630: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    after_12:
    // 0x80051634: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x80051638: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8005163C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051640: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80051644: nop

    // 0x80051648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8005164C:
    // 0x8005164C: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x80051650: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051654: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051658: jal         0x8001E29C
    // 0x8005165C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8005165C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80051660: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80051664: lw          $t7, -0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA4);
    // 0x80051668: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005166C: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x80051670: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051674: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051678: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005167C: beq         $v1, $t7, L_80051720
    if (ctx->r3 == ctx->r15) {
        // 0x80051680: nop
    
            goto L_80051720;
    }
    // 0x80051680: nop

    // 0x80051684: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051688: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005168C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051690: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051694: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80051698: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005169C: nop

    // 0x800516A0: bc1t        L_80051720
    if (c1cs) {
        // 0x800516A4: nop
    
            goto L_80051720;
    }
    // 0x800516A4: nop

    // 0x800516A8: lb          $t8, 0x1E6($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E6);
    // 0x800516AC: nop

    // 0x800516B0: bne         $t8, $zero, L_80051720
    if (ctx->r24 != 0) {
        // 0x800516B4: nop
    
            goto L_80051720;
    }
    // 0x800516B4: nop

    // 0x800516B8: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x800516BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800516C0: bne         $t2, $zero, L_80051720
    if (ctx->r10 != 0) {
        // 0x800516C4: nop
    
            goto L_80051720;
    }
    // 0x800516C4: nop

    // 0x800516C8: lw          $t3, -0x2ACC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2ACC);
    // 0x800516CC: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x800516D0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800516D4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800516D8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800516DC: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800516E0: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800516E4: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800516E8: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800516EC: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800516F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800516F4: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800516F8: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800516FC: bne         $v1, $t6, L_80051720
    if (ctx->r3 != ctx->r14) {
        // 0x80051700: swc1        $f10, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
            goto L_80051720;
    }
    // 0x80051700: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80051704: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80051708: lwc1        $f19, 0x6668($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6668);
    // 0x8005170C: lwc1        $f18, 0x666C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X666C);
    // 0x80051710: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80051714: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80051718: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8005171C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80051720:
    // 0x80051720: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051724: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80051728: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005172C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051730: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x80051734: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051738: nop

    // 0x8005173C: bc1f        L_800517F4
    if (!c1cs) {
        // 0x80051740: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800517F4;
    }
    // 0x80051740: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80051744: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051748: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005174C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80051750: add.d       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f2.d + ctx->f18.d;
    // 0x80051754: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051758: neg.d       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = -ctx->f6.d;
    // 0x8005175C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80051760: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80051764: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x80051768: c.lt.d      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.d < ctx->f8.d;
    // 0x8005176C: nop

    // 0x80051770: bc1f        L_80051784
    if (!c1cs) {
        // 0x80051774: nop
    
            goto L_80051784;
    }
    // 0x80051774: nop

    // 0x80051778: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005177C: nop

    // 0x80051780: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
L_80051784:
    // 0x80051784: lw          $t7, -0x2AAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AAC);
    // 0x80051788: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005178C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80051790: nop

    // 0x80051794: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80051798: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005179C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800517A0: nop

    // 0x800517A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800517A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800517AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800517B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800517B4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800517B8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800517BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800517C0: sw          $t2, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r10;
    // 0x800517C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800517C8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800517CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800517D0: lwc1        $f19, 0x6670($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6670);
    // 0x800517D4: lwc1        $f18, 0x6674($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6674);
    // 0x800517D8: sub.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d - ctx->f12.d;
    // 0x800517DC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800517E0: nop

    // 0x800517E4: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800517E8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800517EC: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x800517F0: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_800517F4:
    // 0x800517F4: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800517F8: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x800517FC: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80051800: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80051804: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051808: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005180C: jal         0x800707F8
    // 0x80051810: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_14;
    // 0x80051810: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    after_14:
    // 0x80051814: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051818: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x8005181C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80051820: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051824: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051828: bc1f        L_80051834
    if (!c1cs) {
        // 0x8005182C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80051834;
    }
    // 0x8005182C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80051830: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80051834:
    // 0x80051834: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80051838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005183C: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80051840: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80051844: beq         $t0, $zero, L_80051894
    if (ctx->r8 == 0) {
        // 0x80051848: sb          $t1, -0x2A7F($at)
        MEM_B(-0X2A7F, ctx->r1) = ctx->r9;
            goto L_80051894;
    }
    // 0x80051848: sb          $t1, -0x2A7F($at)
    MEM_B(-0X2A7F, ctx->r1) = ctx->r9;
    // 0x8005184C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80051850: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x80051854: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051858: jal         0x8001E29C
    // 0x8005185C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8005185C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x80051860: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x80051864: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80051868: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8005186C: addu        $t9, $v0, $t3
    ctx->r25 = ADD32(ctx->r2, ctx->r11);
    // 0x80051870: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80051874: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051878: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8005187C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051880: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051884: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80051888: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x8005188C: b           L_800518CC
    // 0x80051890: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_800518CC;
    // 0x80051890: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_80051894:
    // 0x80051894: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80051898: bne         $t1, $at, L_800518CC
    if (ctx->r9 != ctx->r1) {
        // 0x8005189C: nop
    
            goto L_800518CC;
    }
    // 0x8005189C: nop

    // 0x800518A0: lbu         $t4, 0x1EF($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1EF);
    // 0x800518A4: addiu       $a1, $zero, 0x138
    ctx->r5 = ADD32(0, 0X138);
    // 0x800518A8: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x800518AC: sb          $t5, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r13;
    // 0x800518B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800518B4: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800518B8: jal         0x80057048
    // 0x800518BC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    racer_play_sound(rdram, ctx);
        goto after_16;
    // 0x800518BC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_16:
    // 0x800518C0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800518C4: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800518C8: nop

L_800518CC:
    // 0x800518CC: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x800518D0: nop

    // 0x800518D4: bne         $t6, $zero, L_8005194C
    if (ctx->r14 != 0) {
        // 0x800518D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005194C;
    }
    // 0x800518D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800518DC: bne         $t1, $at, L_8005194C
    if (ctx->r9 != ctx->r1) {
        // 0x800518E0: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8005194C;
    }
    // 0x800518E0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x800518E4: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x800518E8: jal         0x8000C8B4
    // 0x800518EC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_17;
    // 0x800518EC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_17:
    // 0x800518F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800518F4: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x800518F8: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
    // 0x800518FC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80051900: jal         0x80057048
    // 0x80051904: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    racer_play_sound(rdram, ctx);
        goto after_18;
    // 0x80051904: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    after_18:
    // 0x80051908: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8005190C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80051910: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80051914: jal         0x800570B8
    // 0x80051918: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_19;
    // 0x80051918: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_19:
    // 0x8005191C: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051920: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051924: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051928: bne         $t8, $zero, L_8005194C
    if (ctx->r24 != 0) {
        // 0x8005192C: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_8005194C;
    }
    // 0x8005192C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80051930: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051934: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051938: jal         0x80072348
    // 0x8005193C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    rumble_set(rdram, ctx);
        goto after_20;
    // 0x8005193C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_20:
    // 0x80051940: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051944: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051948: nop

L_8005194C:
    // 0x8005194C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051950: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80051954: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80051958: nop

    // 0x8005195C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80051960: nop

    // 0x80051964: bc1f        L_800519A4
    if (!c1cs) {
        // 0x80051968: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800519A4;
    }
    // 0x80051968: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8005196C: lw          $t2, -0x2AD8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AD8);
    // 0x80051970: nop

    // 0x80051974: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x80051978: bne         $t3, $zero, L_800519A4
    if (ctx->r11 != 0) {
        // 0x8005197C: nop
    
            goto L_800519A4;
    }
    // 0x8005197C: nop

    // 0x80051980: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051984: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80051988: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005198C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80051990: nop

    // 0x80051994: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80051998: sub.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8005199C: b           L_800519B8
    // 0x800519A0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_800519B8;
    // 0x800519A0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_800519A4:
    // 0x800519A4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800519A8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800519AC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800519B0: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800519B4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_800519B8:
    // 0x800519B8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800519BC: nop

    // 0x800519C0: beq         $t9, $zero, L_800519E4
    if (ctx->r25 == 0) {
        // 0x800519C4: nop
    
            goto L_800519E4;
    }
    // 0x800519C4: nop

    // 0x800519C8: lbu         $v0, 0x1EE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EE);
    // 0x800519CC: nop

    // 0x800519D0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800519D4: beq         $at, $zero, L_800519E8
    if (ctx->r1 == 0) {
        // 0x800519D8: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_800519E8;
    }
    // 0x800519D8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800519DC: b           L_800519E8
    // 0x800519E0: sb          $t4, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = ctx->r12;
        goto L_800519E8;
    // 0x800519E0: sb          $t4, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = ctx->r12;
L_800519E4:
    // 0x800519E4: sb          $zero, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = 0;
L_800519E8:
    // 0x800519E8: jal         0x80066210
    // 0x800519EC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    cam_get_viewport_layout(rdram, ctx);
        goto after_21;
    // 0x800519EC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_21:
    // 0x800519F0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800519F4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800519F8: beq         $at, $zero, L_80051B28
    if (ctx->r1 == 0) {
        // 0x800519FC: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_80051B28;
    }
    // 0x800519FC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80051A00: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80051A04: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80051A08: beq         $t5, $zero, L_80051A30
    if (ctx->r13 == 0) {
        // 0x80051A0C: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051A30;
    }
    // 0x80051A0C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051A10: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051A14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051A18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051A1C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80051A20: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x80051A24: nop

    // 0x80051A28: bc1t        L_80051A48
    if (c1cs) {
        // 0x80051A2C: nop
    
            goto L_80051A48;
    }
    // 0x80051A2C: nop

L_80051A30:
    // 0x80051A30: bne         $t6, $zero, L_80051A48
    if (ctx->r14 != 0) {
        // 0x80051A34: nop
    
            goto L_80051A48;
    }
    // 0x80051A34: nop

    // 0x80051A38: lb          $t7, 0x1FB($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1FB);
    // 0x80051A3C: nop

    // 0x80051A40: beq         $t7, $zero, L_80051AA8
    if (ctx->r15 == 0) {
        // 0x80051A44: nop
    
            goto L_80051AA8;
    }
    // 0x80051A44: nop

L_80051A48:
    // 0x80051A48: lbu         $v0, 0x1DE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DE);
    // 0x80051A4C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051A50: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051A54: beq         $at, $zero, L_80051A78
    if (ctx->r1 == 0) {
        // 0x80051A58: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80051A78;
    }
    // 0x80051A58: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80051A5C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80051A60: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80051A64: lw          $t3, -0x330C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X330C);
    // 0x80051A68: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80051A6C: nop

    // 0x80051A70: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80051A74: sw          $t9, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r25;
L_80051A78:
    // 0x80051A78: lbu         $v0, 0x1DF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DF);
    // 0x80051A7C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051A80: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051A84: beq         $at, $zero, L_80051AA8
    if (ctx->r1 == 0) {
        // 0x80051A88: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80051AA8;
    }
    // 0x80051A88: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80051A8C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80051A90: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80051A94: lw          $t6, -0x330C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X330C);
    // 0x80051A98: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x80051A9C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80051AA0: or          $t2, $t4, $t7
    ctx->r10 = ctx->r12 | ctx->r15;
    // 0x80051AA4: sw          $t2, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r10;
L_80051AA8:
    // 0x80051AA8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051AAC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051AB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051AB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051AB8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80051ABC: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80051AC0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051AC4: bc1f        L_80051B28
    if (!c1cs) {
        // 0x80051AC8: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_80051B28;
    }
    // 0x80051AC8: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80051ACC: lbu         $v0, 0x1DE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DE);
    // 0x80051AD0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80051AD4: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051AD8: beq         $at, $zero, L_80051AF8
    if (ctx->r1 == 0) {
        // 0x80051ADC: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80051AF8;
    }
    // 0x80051ADC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80051AE0: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80051AE4: lw          $t9, -0x32C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X32C0);
    // 0x80051AE8: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80051AEC: nop

    // 0x80051AF0: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x80051AF4: sw          $t5, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r13;
L_80051AF8:
    // 0x80051AF8: lbu         $v0, 0x1DF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DF);
    // 0x80051AFC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80051B00: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051B04: beq         $at, $zero, L_80051B24
    if (ctx->r1 == 0) {
        // 0x80051B08: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_80051B24;
    }
    // 0x80051B08: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80051B0C: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80051B10: lw          $t7, -0x32C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X32C0);
    // 0x80051B14: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x80051B18: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80051B1C: or          $t3, $t6, $t2
    ctx->r11 = ctx->r14 | ctx->r10;
    // 0x80051B20: sw          $t3, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r11;
L_80051B24:
    // 0x80051B24: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
L_80051B28:
    // 0x80051B28: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80051B2C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80051B30: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80051B34: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051B38: lw          $t1, -0x3380($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3380);
    // 0x80051B3C: bne         $v0, $zero, L_80051B84
    if (ctx->r2 != 0) {
        // 0x80051B40: nop
    
            goto L_80051B84;
    }
    // 0x80051B40: nop

    // 0x80051B44: beq         $t1, $zero, L_80051B84
    if (ctx->r9 == 0) {
        // 0x80051B48: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051B84;
    }
    // 0x80051B48: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051B4C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051B50: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80051B54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051B58: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80051B5C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80051B60: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80051B64: bc1f        L_80051B84
    if (!c1cs) {
        // 0x80051B68: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_80051B84;
    }
    // 0x80051B68: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80051B6C: jal         0x80001D04
    // 0x80051B70: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x80051B70: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_22:
    // 0x80051B74: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051B78: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80051B7C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051B80: nop

L_80051B84:
    // 0x80051B84: beq         $v0, $zero, L_80051BC8
    if (ctx->r2 == 0) {
        // 0x80051B88: nop
    
            goto L_80051BC8;
    }
    // 0x80051B88: nop

    // 0x80051B8C: beq         $t1, $zero, L_80051BB0
    if (ctx->r9 == 0) {
        // 0x80051B90: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051BB0;
    }
    // 0x80051B90: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051B94: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051B98: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80051B9C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051BA0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80051BA4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80051BA8: nop

    // 0x80051BAC: bc1f        L_80051BC8
    if (!c1cs) {
        // 0x80051BB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80051BC8;
    }
L_80051BB0:
    // 0x80051BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051BB4: jal         0x8000488C
    // 0x80051BB8: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    sndp_stop(rdram, ctx);
        goto after_23;
    // 0x80051BB8: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_23:
    // 0x80051BBC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051BC0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051BC4: nop

L_80051BC8:
    // 0x80051BC8: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051BCC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051BD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80051BD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051BD8: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80051BDC: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80051BE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80051BE4: bc1f        L_80051C68
    if (!c1cs) {
        // 0x80051BE8: nop
    
            goto L_80051C68;
    }
    // 0x80051BE8: nop

    // 0x80051BEC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80051BF0: nop

    // 0x80051BF4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80051BF8: bne         $at, $zero, L_80051C68
    if (ctx->r1 != 0) {
        // 0x80051BFC: nop
    
            goto L_80051C68;
    }
    // 0x80051BFC: nop

    // 0x80051C00: lb          $t5, 0x1E7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E7);
    // 0x80051C04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80051C08: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80051C0C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80051C10: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051C14: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80051C18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051C1C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80051C20: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80051C24: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80051C28: lwc1        $f8, 0xA0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80051C2C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051C30: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80051C34: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80051C38: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C3C: lwc1        $f8, 0xA4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80051C40: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80051C44: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C48: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80051C4C: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80051C50: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80051C54: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80051C58: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C5C: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80051C60: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80051C64: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
L_80051C68:
    // 0x80051C68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051C6C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80051C70: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80051C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80051C78: bc1f        L_80051C84
    if (!c1cs) {
        // 0x80051C7C: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_80051C84;
    }
    // 0x80051C7C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80051C80: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80051C84:
    // 0x80051C84: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80051C88: nop

    // 0x80051C8C: bc1f        L_80051C98
    if (!c1cs) {
        // 0x80051C90: nop
    
            goto L_80051C98;
    }
    // 0x80051C90: nop

    // 0x80051C94: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80051C98:
    // 0x80051C98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80051C9C: lw          $t6, -0x2A9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A9C);
    // 0x80051CA0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80051CA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051CA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80051CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80051CB0: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80051CB4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051CB8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80051CBC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80051CC0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80051CC4: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80051CC8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80051CCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051CD0: addu        $v1, $t6, $t2
    ctx->r3 = ADD32(ctx->r14, ctx->r10);
    // 0x80051CD4: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80051CD8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80051CDC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80051CE0: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80051CE4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80051CE8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80051CEC: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80051CF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051CF4: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x80051CF8: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80051CFC: lwc1        $f19, 0x6678($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6678);
    // 0x80051D00: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80051D04: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80051D08: lwc1        $f18, 0x667C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X667C);
    // 0x80051D0C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80051D10: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80051D14: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80051D18: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80051D1C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80051D20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051D24: mul.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80051D28: blez        $t3, L_80051D84
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80051D2C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80051D84;
    }
    // 0x80051D2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80051D30: lw          $t8, -0x2AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC0);
    // 0x80051D34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051D38: bne         $t8, $zero, L_80051D7C
    if (ctx->r24 != 0) {
        // 0x80051D3C: nop
    
            goto L_80051D7C;
    }
    // 0x80051D3C: nop

    // 0x80051D40: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80051D44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051D48: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x80051D4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80051D50: c.eq.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d == ctx->f18.d;
    // 0x80051D54: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80051D58: bc1t        L_80051D68
    if (c1cs) {
        // 0x80051D5C: swc1        $f8, 0xB4($s0)
        MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
            goto L_80051D68;
    }
    // 0x80051D5C: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
    // 0x80051D60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80051D64: nop

L_80051D68:
    // 0x80051D68: lb          $t9, 0x1D3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D3);
    // 0x80051D6C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80051D70: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051D74: subu        $t4, $t9, $t5
    ctx->r12 = SUB32(ctx->r25, ctx->r13);
    // 0x80051D78: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
L_80051D7C:
    // 0x80051D7C: b           L_80051D90
    // 0x80051D80: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_80051D90;
    // 0x80051D80: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80051D84:
    // 0x80051D84: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051D88: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80051D8C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80051D90:
    // 0x80051D90: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051D94: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051D98: nop

    // 0x80051D9C: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051DA0: nop

    // 0x80051DA4: bc1f        L_80051E8C
    if (!c1cs) {
        // 0x80051DA8: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_80051E8C;
    }
    // 0x80051DA8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80051DAC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80051DB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80051DB4: nop

    // 0x80051DB8: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x80051DBC: nop

    // 0x80051DC0: bc1f        L_80051E8C
    if (!c1cs) {
        // 0x80051DC4: nop
    
            goto L_80051E8C;
    }
    // 0x80051DC4: nop

    // 0x80051DC8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80051DCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051DD0: bne         $t7, $at, L_80051DE4
    if (ctx->r15 != ctx->r1) {
        // 0x80051DD4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80051DE4;
    }
    // 0x80051DD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80051DD8: lb          $t6, 0x214($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X214);
    // 0x80051DDC: nop

    // 0x80051DE0: beq         $t6, $zero, L_80051E8C
    if (ctx->r14 == 0) {
        // 0x80051DE4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051E8C;
    }
L_80051DE4:
    // 0x80051DE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051DE8: lwc1        $f9, 0x6680($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6680);
    // 0x80051DEC: lwc1        $f8, 0x6684($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6684);
    // 0x80051DF0: sub.d       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f16.d - ctx->f2.d;
    // 0x80051DF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80051DF8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80051DFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80051E00: bne         $t1, $at, L_80051E20
    if (ctx->r9 != ctx->r1) {
        // 0x80051E04: cvt.s.d     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
            goto L_80051E20;
    }
    // 0x80051E04: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80051E08: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80051E0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051E10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051E14: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80051E18: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80051E1C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80051E20:
    // 0x80051E20: lw          $t2, -0x2AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC8);
    // 0x80051E24: nop

    // 0x80051E28: slti        $at, $t2, -0x19
    ctx->r1 = SIGNED(ctx->r10) < -0X19 ? 1 : 0;
    // 0x80051E2C: beq         $at, $zero, L_80051E8C
    if (ctx->r1 == 0) {
        // 0x80051E30: nop
    
            goto L_80051E8C;
    }
    // 0x80051E30: nop

    // 0x80051E34: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x80051E38: nop

    // 0x80051E3C: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x80051E40: bne         $t3, $zero, L_80051E8C
    if (ctx->r11 != 0) {
        // 0x80051E44: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_80051E8C;
    }
    // 0x80051E44: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x80051E48: beq         $t8, $zero, L_80051E8C
    if (ctx->r24 == 0) {
        // 0x80051E4C: nop
    
            goto L_80051E8C;
    }
    // 0x80051E4C: nop

    // 0x80051E50: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x80051E54: nop

    // 0x80051E58: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80051E5C: bne         $at, $zero, L_80051E78
    if (ctx->r1 != 0) {
        // 0x80051E60: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051E78;
    }
    // 0x80051E60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051E64: lwc1        $f11, 0x6688($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6688);
    // 0x80051E68: lwc1        $f10, 0x668C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X668C);
    // 0x80051E6C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80051E70: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80051E74: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
L_80051E78:
    // 0x80051E78: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80051E7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051E80: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80051E84: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051E88: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
L_80051E8C:
    // 0x80051E8C: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80051E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051E94: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80051E98: lwc1        $f5, 0x6690($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6690);
    // 0x80051E9C: lwc1        $f4, 0x6694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6694);
    // 0x80051EA0: lwc1        $f8, 0xB4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80051EA4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80051EA8: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80051EAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051EB0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80051EB4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80051EB8: sub.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80051EBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051EC0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80051EC4: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051EC8: lwc1        $f4, 0x669C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X669C);
    // 0x80051ECC: lwc1        $f5, 0x6698($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6698);
    // 0x80051ED0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80051ED4: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051ED8: nop

    // 0x80051EDC: bc1f        L_80051F14
    if (!c1cs) {
        // 0x80051EE0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051F14;
    }
    // 0x80051EE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051EE4: lwc1        $f7, 0x66A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X66A0);
    // 0x80051EE8: lwc1        $f6, 0x66A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X66A4);
    // 0x80051EEC: nop

    // 0x80051EF0: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x80051EF4: nop

    // 0x80051EF8: bc1f        L_80051F14
    if (!c1cs) {
        // 0x80051EFC: nop
    
            goto L_80051F14;
    }
    // 0x80051EFC: nop

    // 0x80051F00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051F04: nop

    // 0x80051F08: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80051F0C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F10: nop

L_80051F14:
    // 0x80051F14: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80051F18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80051F1C: bc1f        L_80051F54
    if (!c1cs) {
        // 0x80051F20: nop
    
            goto L_80051F54;
    }
    // 0x80051F20: nop

    // 0x80051F24: add.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80051F28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051F2C: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80051F30: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F34: nop

    // 0x80051F38: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80051F3C: nop

    // 0x80051F40: bc1f        L_80051F84
    if (!c1cs) {
        // 0x80051F44: nop
    
            goto L_80051F84;
    }
    // 0x80051F44: nop

    // 0x80051F48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051F4C: b           L_80051F84
    // 0x80051F50: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_80051F84;
    // 0x80051F50: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80051F54:
    // 0x80051F54: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80051F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051F5C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80051F60: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F64: nop

    // 0x80051F68: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80051F6C: nop

    // 0x80051F70: bc1f        L_80051F84
    if (!c1cs) {
        // 0x80051F74: nop
    
            goto L_80051F84;
    }
    // 0x80051F74: nop

    // 0x80051F78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051F7C: nop

    // 0x80051F80: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_80051F84:
    // 0x80051F84: lwc1        $f14, -0x2A94($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x80051F88: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80051F8C: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80051F90: mul.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80051F94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80051F98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051F9C: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80051FA0: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
    // 0x80051FA4: lh          $t5, -0x2A7A($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2A7A);
    // 0x80051FA8: nop

    // 0x80051FAC: beq         $t5, $zero, L_80051FBC
    if (ctx->r13 == 0) {
        // 0x80051FB0: nop
    
            goto L_80051FBC;
    }
    // 0x80051FB0: nop

    // 0x80051FB4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80051FB8: nop

L_80051FBC:
    // 0x80051FBC: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80051FC0: lwc1        $f9, 0x66A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66A8);
    // 0x80051FC4: lwc1        $f8, 0x66AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66AC);
    // 0x80051FC8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80051FCC: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80051FD0: nop

    // 0x80051FD4: bc1f        L_800520D4
    if (!c1cs) {
        // 0x80051FD8: nop
    
            goto L_800520D4;
    }
    // 0x80051FD8: nop

    // 0x80051FDC: lb          $t4, 0x1D7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D7);
    // 0x80051FE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80051FE4: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80051FE8: beq         $at, $zero, L_800520D4
    if (ctx->r1 == 0) {
        // 0x80051FEC: nop
    
            goto L_800520D4;
    }
    // 0x80051FEC: nop

    // 0x80051FF0: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x80051FF4: nop

    // 0x80051FF8: bne         $t7, $zero, L_800520D4
    if (ctx->r15 != 0) {
        // 0x80051FFC: nop
    
            goto L_800520D4;
    }
    // 0x80051FFC: nop

    // 0x80052000: lwc1        $f12, 0x9C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80052004: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80052008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005200C: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80052010: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80052014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052018: bc1f        L_8005209C
    if (!c1cs) {
        // 0x8005201C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8005209C;
    }
    // 0x8005201C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80052020: lwc1        $f11, 0x66B0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X66B0);
    // 0x80052024: lwc1        $f10, 0x66B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66B4);
    // 0x80052028: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005202C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80052030: sub.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d - ctx->f10.d;
    // 0x80052034: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80052038: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8005203C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80052040: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80052044: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x80052048: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005204C: bc1f        L_80052060
    if (!c1cs) {
        // 0x80052050: nop
    
            goto L_80052060;
    }
    // 0x80052050: nop

    // 0x80052054: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80052058: nop

    // 0x8005205C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80052060:
    // 0x80052060: lwc1        $f5, 0x66B8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X66B8);
    // 0x80052064: lwc1        $f4, 0x66BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X66BC);
    // 0x80052068: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005206C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80052070: nop

    // 0x80052074: bc1f        L_80052084
    if (!c1cs) {
        // 0x80052078: nop
    
            goto L_80052084;
    }
    // 0x80052078: nop

    // 0x8005207C: lwc1        $f2, 0x66C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X66C0);
    // 0x80052080: nop

L_80052084:
    // 0x80052084: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80052088: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005208C: nop

    // 0x80052090: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80052094: b           L_800520A8
    // 0x80052098: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
        goto L_800520A8;
    // 0x80052098: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_8005209C:
    // 0x8005209C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800520A0: nop

    // 0x800520A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_800520A8:
    // 0x800520A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800520AC: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800520B0: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800520B4: nop

    // 0x800520B8: div.s       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800520BC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800520C0: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800520C4: nop

    // 0x800520C8: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800520CC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800520D0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_800520D4:
    // 0x800520D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800520D8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800520DC: lwc1        $f11, 0x66C8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X66C8);
    // 0x800520E0: lwc1        $f10, 0x66CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66CC);
    // 0x800520E4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800520E8: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800520EC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800520F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800520F4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800520F8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800520FC: add.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f0.d + ctx->f18.d;
    // 0x80052100: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80052104: lb          $t6, 0x1E1($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E1);
    // 0x80052108: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005210C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80052110: sb          $t6, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r14;
    // 0x80052114: lb          $t3, 0x1E0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E0);
    // 0x80052118: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x8005211C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80052120: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80052124: lw          $t2, -0x2AAC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AAC);
    // 0x80052128: beq         $t3, $zero, L_80052178
    if (ctx->r11 == 0) {
        // 0x8005212C: sw          $t2, 0x110($s0)
        MEM_W(0X110, ctx->r16) = ctx->r10;
            goto L_80052178;
    }
    // 0x8005212C: sw          $t2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->r10;
    // 0x80052130: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80052134: lw          $t8, -0x2AA4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AA4);
    // 0x80052138: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005213C: beq         $t8, $at, L_8005217C
    if (ctx->r24 == ctx->r1) {
        // 0x80052140: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005217C;
    }
    // 0x80052140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052144: lbu         $v0, 0x1DC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DC);
    // 0x80052148: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005214C: beq         $v0, $at, L_80052178
    if (ctx->r2 == ctx->r1) {
        // 0x80052150: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_80052178;
    }
    // 0x80052150: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80052154: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80052158: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8005215C: lhu         $t5, -0x3334($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X3334);
    // 0x80052160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052164: sh          $t5, -0x2AB0($at)
    MEM_H(-0X2AB0, ctx->r1) = ctx->r13;
    // 0x80052168: lb          $t4, 0x1E0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E0);
    // 0x8005216C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052170: sh          $t4, -0x2AAE($at)
    MEM_H(-0X2AAE, ctx->r1) = ctx->r12;
    // 0x80052174: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_80052178:
    // 0x80052178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005217C:
    // 0x8005217C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80052180: jr          $ra
    // 0x80052184: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80052184: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void start_reading_controller_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075AF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075AF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80075AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075AFC: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x80075B00: jal         0x800CCFE0
    // 0x80075B04: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80075B04: nop

    after_0:
    // 0x80075B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075B10: jr          $ra
    // 0x80075B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80075B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4840: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D4844: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4848: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D484C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4854: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D4858: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D485C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4860: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4864:
    // 0x800D4864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4868: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800D486C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D4870: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4874: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D4878: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D487C: beq         $a0, $t3, L_800D48E4
    if (ctx->r4 == ctx->r11) {
        // 0x800D4880: nop
    
            goto L_800D48E4;
    }
    // 0x800D4880: nop

L_800D4884:
    // 0x800D4884: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4888: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D488C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4890: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4894: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D4898: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D489C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D48A0: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D48A4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D48A8: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D48AC: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D48B0: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D48B4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D48B8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D48BC: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D48C0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D48C4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D48C8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D48CC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D48D0: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D48D4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D48D8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D48DC: bne         $a0, $t3, L_800D4884
    if (ctx->r4 != ctx->r11) {
        // 0x800D48E0: nop
    
            goto L_800D4884;
    }
    // 0x800D48E0: nop

L_800D48E4:
    // 0x800D48E4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D48E8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D48EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D48F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D48F4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D48F8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D48FC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D4900: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D4904: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D4908: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D490C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D4910: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4914: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D4918: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D491C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D4920: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D4924: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D4928: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D492C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4930: bne         $a2, $t4, L_800D4864
    if (ctx->r6 != ctx->r12) {
        // 0x800D4934: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800D4864;
    }
    // 0x800D4934: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D4938: jr          $ra
    // 0x800D493C: nop

    return;
    // 0x800D493C: nop

;}
RECOMP_FUNC void do_nothing_func_80011364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011364: jr          $ra
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void menu_button_uvs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080518: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8008051C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080520: nop

    // 0x80080524: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080528: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008052C: nop

    // 0x80080530: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80080534: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80080538: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008053C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080540: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80080544: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80080548: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8008054C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80080550: sw          $t7, 0x1DC0($at)
    MEM_W(0X1DC0, ctx->r1) = ctx->r15;
    // 0x80080554: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80080558: nop

    // 0x8008055C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80080560: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80080564: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80080568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008056C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80080570: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80080574: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80080578: jr          $ra
    // 0x8008057C: sw          $t9, 0x1DC4($at)
    MEM_W(0X1DC4, ctx->r1) = ctx->r25;
    return;
    // 0x8008057C: sw          $t9, 0x1DC4($at)
    MEM_W(0X1DC4, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void is_controller_missing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F4CC: lw          $t6, -0x2C7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C7C);
    // 0x8006F4D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006F4D4: bne         $t6, $at, L_8006F4E4
    if (ctx->r14 != ctx->r1) {
        // 0x8006F4D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006F4E4;
    }
    // 0x8006F4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006F4DC: jr          $ra
    // 0x8006F4E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006F4E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F4E4:
    // 0x8006F4E4: jr          $ra
    // 0x8006F4E8: nop

    return;
    // 0x8006F4E8: nop

;}
RECOMP_FUNC void ainode_register(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C48C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001C490: lw          $a1, -0x50FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X50FC);
    // 0x8001C494: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C498: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8001C49C:
    // 0x8001C49C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001C4A0: nop

    // 0x8001C4A4: bne         $t6, $zero, L_8001C4B8
    if (ctx->r14 != 0) {
        // 0x8001C4A8: nop
    
            goto L_8001C4B8;
    }
    // 0x8001C4A8: nop

    // 0x8001C4AC: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8001C4B0: jr          $ra
    // 0x8001C4B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C4B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001C4B8:
    // 0x8001C4B8: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8001C4BC: nop

    // 0x8001C4C0: bne         $t7, $zero, L_8001C4D4
    if (ctx->r15 != 0) {
        // 0x8001C4C4: nop
    
            goto L_8001C4D4;
    }
    // 0x8001C4C4: nop

    // 0x8001C4C8: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8001C4CC: jr          $ra
    // 0x8001C4D0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x8001C4D0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8001C4D4:
    // 0x8001C4D4: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8001C4D8: nop

    // 0x8001C4DC: bne         $t8, $zero, L_8001C4F0
    if (ctx->r24 != 0) {
        // 0x8001C4E0: nop
    
            goto L_8001C4F0;
    }
    // 0x8001C4E0: nop

    // 0x8001C4E4: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x8001C4E8: jr          $ra
    // 0x8001C4EC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8001C4EC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_8001C4F0:
    // 0x8001C4F0: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8001C4F4: nop

    // 0x8001C4F8: bne         $t9, $zero, L_8001C50C
    if (ctx->r25 != 0) {
        // 0x8001C4FC: nop
    
            goto L_8001C50C;
    }
    // 0x8001C4FC: nop

    // 0x8001C500: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
    // 0x8001C504: jr          $ra
    // 0x8001C508: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x8001C508: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_8001C50C:
    // 0x8001C50C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C510: bne         $v1, $v0, L_8001C49C
    if (ctx->r3 != ctx->r2) {
        // 0x8001C514: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8001C49C;
    }
    // 0x8001C514: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8001C518: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001C51C: jr          $ra
    // 0x8001C520: nop

    return;
    // 0x8001C520: nop

;}
RECOMP_FUNC void alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9658: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C965C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C9660: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C9664: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800C9668: beql        $t7, $zero, L_800C96E0
    if (ctx->r15 == 0) {
        // 0x800C966C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C96E0;
    }
    goto skip_0;
    // 0x800C966C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9670: jal         0x80065668
    // 0x800C9674: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9674: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9678: beq         $v0, $zero, L_800C96DC
    if (ctx->r2 == 0) {
        // 0x800C967C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800C96DC;
    }
    // 0x800C967C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C9680: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C9684: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800C9688: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800C968C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800C9690: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800C9694: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800C9698: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800C969C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C96A0: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800C96A4: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800C96A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C96AC: jal         0x800657C4
    // 0x800C96B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800C96B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800C96B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C96B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C96BC: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800C96C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C96C4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C96C8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800C96CC: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800C96D0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C96D4: jalr        $t9
    // 0x800C96D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C96D8: nop

    after_2:
L_800C96DC:
    // 0x800C96DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C96E0:
    // 0x800C96E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C96E4: jr          $ra
    // 0x800C96E8: nop

    return;
    // 0x800C96E8: nop

;}
RECOMP_FUNC void func_80083098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083098: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008309C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800830A0: lw          $v0, 0x68E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68E0);
    // 0x800830A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800830A8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800830AC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800830B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800830B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800830B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800830BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800830C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800830C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800830C8: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x800830CC: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x800830D0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800830D4: beq         $at, $zero, L_80083514
    if (ctx->r1 == 0) {
        // 0x800830D8: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_80083514;
    }
    // 0x800830D8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800830DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800830E0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800830E4: addiu       $v1, $v1, 0x68D8
    ctx->r3 = ADD32(ctx->r3, 0X68D8);
    // 0x800830E8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800830EC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800830F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800830F4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800830F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800830FC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80083100: addiu       $t7, $t7, -0x7C4
    ctx->r15 = ADD32(ctx->r15, -0X7C4);
    // 0x80083104: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083108: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8008310C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80083110: jal         0x800C42EC
    // 0x80083114: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x80083114: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80083118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008311C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083124: jal         0x800C43CC
    // 0x80083128: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x80083128: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008312C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80083130: addiu       $s2, $s2, -0x60C
    ctx->r18 = ADD32(ctx->r18, -0X60C);
    // 0x80083134: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80083138: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008313C: blez        $a0, L_80083250
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80083140: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80083250;
    }
    // 0x80083140: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083144: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083148: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8008314C: addiu       $s5, $s5, -0x608
    ctx->r21 = ADD32(ctx->r21, -0X608);
    // 0x80083150: addiu       $s6, $s6, 0x63A0
    ctx->r22 = ADD32(ctx->r22, 0X63A0);
    // 0x80083154: addiu       $s0, $s0, 0x6878
    ctx->r16 = ADD32(ctx->r16, 0X6878);
    // 0x80083158: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_8008315C:
    // 0x8008315C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80083160: nop

    // 0x80083164: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083168: mflo        $t0
    ctx->r8 = lo;
    // 0x8008316C: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x80083170: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80083174: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80083178: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x8008317C: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x80083180: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x80083184: jal         0x800C4384
    // 0x80083188: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80083188: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x8008318C: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x80083190: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x80083194: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80083198: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008319C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800831A0: jal         0x800C4440
    // 0x800831A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_3;
    // 0x800831A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x800831A8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800831AC: nop

    // 0x800831B0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800831B4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800831B8: bne         $at, $zero, L_80083238
    if (ctx->r1 != 0) {
        // 0x800831BC: sw          $t3, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r11;
            goto L_80083238;
    }
    // 0x800831BC: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800831C0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800831C4: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x800831C8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800831CC: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800831D0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800831D4: beq         $at, $zero, L_80083244
    if (ctx->r1 == 0) {
        // 0x800831D8: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80083244;
    }
    // 0x800831D8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800831DC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800831E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800831E4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800831E8: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800831EC: addiu       $t8, $t8, 0x6878
    ctx->r24 = ADD32(ctx->r24, 0X6878);
    // 0x800831F0: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800831F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800831F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800831FC: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80083200: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80083204:
    // 0x80083204: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80083208: lh          $t2, 0x10($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X10);
    // 0x8008320C: lh          $t3, 0x12($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X12);
    // 0x80083210: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x80083214: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80083218: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008321C: sw          $t1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r9;
    // 0x80083220: sh          $t2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r10;
    // 0x80083224: sh          $t3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r11;
    // 0x80083228: bne         $at, $zero, L_80083204
    if (ctx->r1 != 0) {
        // 0x8008322C: sw          $t4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r12;
            goto L_80083204;
    }
    // 0x8008322C: sw          $t4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r12;
    // 0x80083230: b           L_80083248
    // 0x80083234: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80083248;
    // 0x80083234: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083238:
    // 0x80083238: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008323C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083240: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80083244:
    // 0x80083244: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083248:
    // 0x80083248: bne         $at, $zero, L_8008315C
    if (ctx->r1 != 0) {
        // 0x8008324C: nop
    
            goto L_8008315C;
    }
    // 0x8008324C: nop

L_80083250:
    // 0x80083250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083254: lwc1        $f16, 0x68D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X68D8);
    // 0x80083258: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8008325C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083260: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80083264: addiu       $s6, $s6, 0x63A0
    ctx->r22 = ADD32(ctx->r22, 0X63A0);
    // 0x80083268: bc1f        L_80083494
    if (!c1cs) {
        // 0x8008326C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80083494;
    }
    // 0x8008326C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083270: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80083274: nop

    // 0x80083278: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x8008327C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80083280: nop

    // 0x80083284: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80083288: nop

    // 0x8008328C: bc1f        L_8008333C
    if (!c1cs) {
        // 0x80083290: nop
    
            goto L_8008333C;
    }
    // 0x80083290: nop

    // 0x80083294: lwc1        $f12, 0x14($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80083298: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8008329C: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800832A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800832A4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800832A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800832AC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800832B0: nop

    // 0x800832B4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800832B8: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800832BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800832C0: nop

    // 0x800832C4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800832C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800832CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800832D0: nop

    // 0x800832D4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800832D8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800832DC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800832E0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800832E4: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800832E8: lwc1        $f14, 0x18($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800832EC: nop

    // 0x800832F0: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800832F4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800832F8: nop

    // 0x800832FC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083300: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80083304: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80083308: nop

    // 0x8008330C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80083310: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083314: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083318: nop

    // 0x8008331C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083320: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80083324: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80083328: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8008332C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80083330: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80083334: b           L_80083494
    // 0x80083338: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
        goto L_80083494;
    // 0x80083338: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_8008333C:
    // 0x8008333C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80083340: nop

    // 0x80083344: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80083348: nop

    // 0x8008334C: bc1f        L_800833B8
    if (!c1cs) {
        // 0x80083350: nop
    
            goto L_800833B8;
    }
    // 0x80083350: nop

    // 0x80083354: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80083358: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8008335C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80083360: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083364: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083368: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008336C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80083370: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80083374: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80083378: nop

    // 0x8008337C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80083380: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80083384: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80083388: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008338C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083390: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083394: nop

    // 0x80083398: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008339C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800833A0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800833A4: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800833A8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800833AC: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800833B0: b           L_80083494
    // 0x800833B4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
        goto L_80083494;
    // 0x800833B4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800833B8:
    // 0x800833B8: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800833BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800833C0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800833C4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800833C8: addiu       $v0, $v0, 0x68E0
    ctx->r2 = ADD32(ctx->r2, 0X68E0);
    // 0x800833CC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800833D0: nop

    // 0x800833D4: bc1f        L_80083484
    if (!c1cs) {
        // 0x800833D8: nop
    
            goto L_80083484;
    }
    // 0x800833D8: nop

    // 0x800833DC: lwc1        $f12, 0x1C($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x800833E0: lwc1        $f8, 0x24($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800833E4: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800833E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800833EC: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800833F0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800833F4: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800833F8: nop

    // 0x800833FC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083400: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80083404: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80083408: nop

    // 0x8008340C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80083410: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083414: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083418: nop

    // 0x8008341C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083420: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80083424: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80083428: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008342C: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80083430: lwc1        $f14, 0x20($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083434: nop

    // 0x80083438: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8008343C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80083440: nop

    // 0x80083444: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80083448: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8008344C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80083450: nop

    // 0x80083454: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80083458: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008345C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083460: nop

    // 0x80083464: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80083468: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8008346C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80083470: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x80083474: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80083478: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8008347C: b           L_80083494
    // 0x80083480: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_80083494;
    // 0x80083480: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_80083484:
    // 0x80083484: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80083488: nop

    // 0x8008348C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80083490: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80083494:
    // 0x80083494: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80083498: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008349C: beq         $t7, $zero, L_80083514
    if (ctx->r15 == 0) {
        // 0x800834A0: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80083514;
    }
    // 0x800834A0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800834A4: beq         $at, $zero, L_800834E8
    if (ctx->r1 == 0) {
        // 0x800834A8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800834E8;
    }
    // 0x800834A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800834AC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800834B0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800834B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800834B8: addiu       $t8, $t8, 0x6878
    ctx->r24 = ADD32(ctx->r24, 0X6878);
    // 0x800834BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800834C0: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800834C4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800834C8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800834CC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800834D0: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x800834D4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800834D8: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800834DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800834E0: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x800834E4: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
L_800834E8:
    // 0x800834E8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800834EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800834F0: jal         0x800C4384
    // 0x800834F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x800834F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_4:
    // 0x800834F8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800834FC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80083500: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80083504: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80083508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008350C: jal         0x800C4440
    // 0x80083510: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80083510: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_5:
L_80083514:
    // 0x80083514: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80083518: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008351C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80083520: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80083524: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80083528: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008352C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80083530: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80083534: jr          $ra
    // 0x80083538: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80083538: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8000: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C8004: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C8008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C800C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C8010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8014: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8018: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C801C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C8020: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C8024: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800C8028: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C802C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C8030: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C8034: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C8038: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C803C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C8040: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800C8044: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800C8048: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800C804C:
    // 0x800C804C: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800C8050: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800C8054: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800C8058: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800C805C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C8060: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800C8064: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800C8068: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800C806C: beq         $v0, $zero, L_800C8098
    if (ctx->r2 == 0) {
        // 0x800C8070: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800C8098;
    }
    // 0x800C8070: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800C8074: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800C8078: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800C807C: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C8080: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C8084: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800C8088: jal         0x800C7CA4
    // 0x800C808C: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    static_3_800C7CA4(rdram, ctx);
        goto after_0;
    // 0x800C808C: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800C8090: b           L_800C809C
    // 0x800C8094: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800C809C;
    // 0x800C8094: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800C8098:
    // 0x800C8098: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800C809C:
    // 0x800C809C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C80A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C80A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C80A8: bne         $t5, $s3, L_800C804C
    if (ctx->r13 != ctx->r19) {
        // 0x800C80AC: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800C804C;
    }
    // 0x800C80AC: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800C80B0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800C80B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C80B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C80BC: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800C80C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C80C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C80C8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C80CC: bgez        $t7, L_800C80E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C80D0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C80E0;
    }
    // 0x800C80D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C80D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C80D8: nop

    // 0x800C80DC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C80E0:
    // 0x800C80E0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800C80E4: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800C80E8: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800C80EC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800C80F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C80F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C80F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C80FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C8100: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8108: jr          $ra
    // 0x800C810C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C810C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_new_sub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070B80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80070B84: jal         0x8006F510
    // 0x80070B88: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070B88: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80070B8C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80070B90: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80070B94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80070B98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80070B9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80070BA0: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80070BA4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80070BA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80070BAC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80070BB0: jal         0x80070C9C
    // 0x80070BB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80070BB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80070BB8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80070BBC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80070BC0: jal         0x80070BE4
    // 0x80070BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_init(rdram, ctx);
        goto after_2;
    // 0x80070BC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80070BC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80070BCC: jal         0x8006F53C
    // 0x80070BD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80070BD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80070BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070BD8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070BDC: jr          $ra
    // 0x80070BE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80070BE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D4B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D4BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001D4C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001D4C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D4C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D4CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D4D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D4D4: sh          $a3, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r7;
    // 0x8001D4D8: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x8001D4DC: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x8001D4E0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001D4E4: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x8001D4E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D4EC: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8001D4F0: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x8001D4F4: lui         $at, 0xC680
    ctx->r1 = S32(0XC680 << 16);
    // 0x8001D4F8: sh          $t9, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r25;
    // 0x8001D4FC: lh          $t0, 0x46($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X46);
    // 0x8001D500: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x8001D504: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D508: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001D50C: sh          $a3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D510: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D514: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D518: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001D51C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8001D520: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8001D524: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x8001D528: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x8001D52C: jal         0x80070320
    // 0x8001D530: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x8001D530: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8001D534: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D538: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D53C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D540: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001D544: nop

    // 0x8001D548: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001D54C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D550: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D554: nop

    // 0x8001D558: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D55C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8001D560: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001D564: sh          $t3, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r11;
    // 0x8001D568: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001D56C: nop

    // 0x8001D570: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8001D574: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001D578: nop

    // 0x8001D57C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8001D580: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D584: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D588: nop

    // 0x8001D58C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001D590: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8001D594: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8001D598: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x8001D59C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D5A0: sb          $zero, 0x18($a2)
    MEM_B(0X18, ctx->r6) = 0;
    // 0x8001D5A4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D5A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D5AC: sb          $zero, 0x19($a2)
    MEM_B(0X19, ctx->r6) = 0;
    // 0x8001D5B0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D5B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D5B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D5BC: sb          $zero, 0x1A($a2)
    MEM_B(0X1A, ctx->r6) = 0;
    // 0x8001D5C0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D5C4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8001D5C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D5CC: sh          $t7, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r15;
    // 0x8001D5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D5D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D5D8: jr          $ra
    // 0x8001D5DC: nop

    return;
    // 0x8001D5DC: nop

;}
RECOMP_FUNC void update_perspective_and_envmap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030FA8: jal         0x80069D20
    // 0x80030FAC: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80030FAC: nop

    after_0:
    // 0x80030FB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80030FB4: jal         0x80031018
    // 0x80030FB8: sw          $v0, -0x4F50($at)
    MEM_W(-0X4F50, ctx->r1) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_1;
    // 0x80030FB8: sw          $v0, -0x4F50($at)
    MEM_W(-0X4F50, ctx->r1) = ctx->r2;
    after_1:
    // 0x80030FBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80030FC0: addiu       $v0, $v0, -0x2B98
    ctx->r2 = ADD32(ctx->r2, -0X2B98);
    // 0x80030FC4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80030FC8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80030FCC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80030FD0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80030FD4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80030FD8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80030FDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80030FE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80030FE4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80030FE8: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80030FEC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80030FF0: nop

    // 0x80030FF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80030FF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80030FFC: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80031000: jal         0x8001D5E0
    // 0x80031004: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_2;
    // 0x80031004: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_2:
    // 0x80031008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003100C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031010: jr          $ra
    // 0x80031014: nop

    return;
    // 0x80031014: nop

;}
RECOMP_FUNC void rain_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD4B0: jr          $ra
    // 0x800AD4B4: sw          $a0, 0x2C6C($at)
    MEM_W(0X2C6C, ctx->r1) = ctx->r4;
    return;
    // 0x800AD4B4: sw          $a0, 0x2C6C($at)
    MEM_W(0X2C6C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_loop_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C2E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003C2E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003C2EC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003C2F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003C2F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003C2F8: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x8003C2FC: jal         0x8006EA90
    // 0x8003C300: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C300: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x8003C304: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003C308: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x8003C30C: nop

    // 0x8003C310: bne         $t6, $zero, L_8003C330
    if (ctx->r14 != 0) {
        // 0x8003C314: nop
    
            goto L_8003C330;
    }
    // 0x8003C314: nop

    // 0x8003C318: lbu         $t7, 0x16($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C31C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003C320: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003C324: lb          $t8, -0x356C($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X356C);
    // 0x8003C328: b           L_8003C348
    // 0x8003C32C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
        goto L_8003C348;
    // 0x8003C32C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
L_8003C330:
    // 0x8003C330: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C334: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C338: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003C33C: lb          $t0, -0x3564($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X3564);
    // 0x8003C340: nop

    // 0x8003C344: sb          $t0, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r8;
L_8003C348:
    // 0x8003C348: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C34C: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C350: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003C354: nop

    // 0x8003C358: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003C35C: beq         $at, $zero, L_8003C46C
    if (ctx->r1 == 0) {
        // 0x8003C360: nop
    
            goto L_8003C46C;
    }
    // 0x8003C360: nop

    // 0x8003C364: lbu         $t3, 0x16($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C368: nop

    // 0x8003C36C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8003C370: bne         $at, $zero, L_8003C394
    if (ctx->r1 != 0) {
        // 0x8003C374: nop
    
            goto L_8003C394;
    }
    // 0x8003C374: nop

    // 0x8003C378: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C37C: nop

    // 0x8003C380: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8003C384: nop

    // 0x8003C388: slti        $at, $t5, 0x2F
    ctx->r1 = SIGNED(ctx->r13) < 0X2F ? 1 : 0;
    // 0x8003C38C: beq         $at, $zero, L_8003C46C
    if (ctx->r1 == 0) {
        // 0x8003C390: nop
    
            goto L_8003C46C;
    }
    // 0x8003C390: nop

L_8003C394:
    // 0x8003C394: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003C398: nop

    // 0x8003C39C: beq         $v0, $zero, L_8003C46C
    if (ctx->r2 == 0) {
        // 0x8003C3A0: nop
    
            goto L_8003C46C;
    }
    // 0x8003C3A0: nop

    // 0x8003C3A4: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x8003C3A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C3AC: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8003C3B0: nop

    // 0x8003C3B4: bne         $t7, $at, L_8003C46C
    if (ctx->r15 != ctx->r1) {
        // 0x8003C3B8: nop
    
            goto L_8003C46C;
    }
    // 0x8003C3B8: nop

    // 0x8003C3BC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003C3C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8003C3C4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8003C3C8: nop

    // 0x8003C3CC: beq         $a0, $t8, L_8003C458
    if (ctx->r4 == ctx->r24) {
        // 0x8003C3D0: nop
    
            goto L_8003C458;
    }
    // 0x8003C3D0: nop

    // 0x8003C3D4: lw          $t9, 0x5C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C3D8: nop

    // 0x8003C3DC: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8003C3E0: nop

    // 0x8003C3E4: bne         $v0, $t0, L_8003C458
    if (ctx->r2 != ctx->r8) {
        // 0x8003C3E8: nop
    
            goto L_8003C458;
    }
    // 0x8003C3E8: nop

    // 0x8003C3EC: lb          $t1, 0x13($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X13);
    // 0x8003C3F0: nop

    // 0x8003C3F4: beq         $a0, $t1, L_8003C454
    if (ctx->r4 == ctx->r9) {
        // 0x8003C3F8: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C454;
    }
    // 0x8003C3F8: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C3FC: jal         0x800C3400
    // 0x8003C400: nop

    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003C400: nop

    after_1:
    // 0x8003C404: bne         $v0, $zero, L_8003C454
    if (ctx->r2 != 0) {
        // 0x8003C408: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C454;
    }
    // 0x8003C408: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C40C: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x8003C410: nop

    // 0x8003C414: bne         $t2, $zero, L_8003C454
    if (ctx->r10 != 0) {
        // 0x8003C418: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C454;
    }
    // 0x8003C418: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C41C: jal         0x80000C98
    // 0x8003C420: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003C420: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_2:
    // 0x8003C424: addiu       $t3, $zero, 0x8C
    ctx->r11 = ADD32(0, 0X8C);
    // 0x8003C428: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8003C42C: jal         0x80000C38
    // 0x8003C430: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003C430: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x8003C434: jal         0x80001BC0
    // 0x8003C438: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_4;
    // 0x8003C438: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8003C43C: lb          $a0, 0x13($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X13);
    // 0x8003C440: nop

    // 0x8003C444: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x8003C448: jal         0x800C31EC
    // 0x8003C44C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    set_current_text(rdram, ctx);
        goto after_5;
    // 0x8003C44C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x8003C450: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
L_8003C454:
    // 0x8003C454: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
L_8003C458:
    // 0x8003C458: jal         0x800C3400
    // 0x8003C45C: nop

    textbox_visible(rdram, ctx);
        goto after_6;
    // 0x8003C45C: nop

    after_6:
    // 0x8003C460: beq         $v0, $zero, L_8003C46C
    if (ctx->r2 == 0) {
        // 0x8003C464: addiu       $t6, $zero, 0x12C
        ctx->r14 = ADD32(0, 0X12C);
            goto L_8003C46C;
    }
    // 0x8003C464: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8003C468: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8003C46C:
    // 0x8003C46C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8003C470: nop

    // 0x8003C474: beq         $t7, $zero, L_8003C4BC
    if (ctx->r15 == 0) {
        // 0x8003C478: nop
    
            goto L_8003C4BC;
    }
    // 0x8003C478: nop

    // 0x8003C47C: jal         0x80001C08
    // 0x8003C480: nop

    music_jingle_playing(rdram, ctx);
        goto after_7;
    // 0x8003C480: nop

    after_7:
    // 0x8003C484: bne         $v0, $zero, L_8003C4BC
    if (ctx->r2 != 0) {
        // 0x8003C488: nop
    
            goto L_8003C4BC;
    }
    // 0x8003C488: nop

    // 0x8003C48C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C490: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003C494: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003C498: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C49C: beq         $at, $zero, L_8003C4AC
    if (ctx->r1 == 0) {
        // 0x8003C4A0: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C4AC;
    }
    // 0x8003C4A0: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C4A4: b           L_8003C4BC
    // 0x8003C4A8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
        goto L_8003C4BC;
    // 0x8003C4A8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
L_8003C4AC:
    // 0x8003C4AC: jal         0x80000C98
    // 0x8003C4B0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    music_fade(rdram, ctx);
        goto after_8;
    // 0x8003C4B0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    after_8:
    // 0x8003C4B4: jal         0x80000C38
    // 0x8003C4B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x8003C4B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
L_8003C4BC:
    // 0x8003C4BC: lh          $v0, 0xC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC);
    // 0x8003C4C0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C4C4: blez        $v0, L_8003C4D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003C4C8: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C4D4;
    }
    // 0x8003C4C8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C4CC: b           L_8003C4D8
    // 0x8003C4D0: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
        goto L_8003C4D8;
    // 0x8003C4D0: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
L_8003C4D4:
    // 0x8003C4D4: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
L_8003C4D8:
    // 0x8003C4D8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C4DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003C4E0: lbu         $t1, 0x16($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X16);
    // 0x8003C4E4: nop

    // 0x8003C4E8: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003C4EC: bne         $at, $zero, L_8003C548
    if (ctx->r1 != 0) {
        // 0x8003C4F0: nop
    
            goto L_8003C548;
    }
    // 0x8003C4F0: nop

    // 0x8003C4F4: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C4F8: lbu         $t4, 0x12($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C4FC: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x8003C500: nop

    // 0x8003C504: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003C508: beq         $at, $zero, L_8003C548
    if (ctx->r1 == 0) {
        // 0x8003C50C: nop
    
            goto L_8003C548;
    }
    // 0x8003C50C: nop

    // 0x8003C510: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8003C514: nop

    // 0x8003C518: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8003C51C: nop

    // 0x8003C520: slti        $at, $t6, 0x2F
    ctx->r1 = SIGNED(ctx->r14) < 0X2F ? 1 : 0;
    // 0x8003C524: bne         $at, $zero, L_8003C548
    if (ctx->r1 != 0) {
        // 0x8003C528: nop
    
            goto L_8003C548;
    }
    // 0x8003C528: nop

    // 0x8003C52C: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C530: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8003C534: nop

    // 0x8003C538: subu        $v0, $v1, $t7
    ctx->r2 = SUB32(ctx->r3, ctx->r15);
    // 0x8003C53C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8003C540: b           L_8003C560
    // 0x8003C544: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8003C560;
    // 0x8003C544: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8003C548:
    // 0x8003C548: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C54C: lw          $t1, 0x78($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X78);
    // 0x8003C550: nop

    // 0x8003C554: subu        $v0, $v1, $t1
    ctx->r2 = SUB32(ctx->r3, ctx->r9);
    // 0x8003C558: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8003C55C: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
L_8003C560:
    // 0x8003C560: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003C564: sll         $t0, $t4, 16
    ctx->r8 = S32(ctx->r12 << 16);
    // 0x8003C568: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8003C56C: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003C570: bne         $at, $zero, L_8003C580
    if (ctx->r1 != 0) {
        // 0x8003C574: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003C580;
    }
    // 0x8003C574: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003C578: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003C57C: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003C580:
    // 0x8003C580: beq         $at, $zero, L_8003C590
    if (ctx->r1 == 0) {
        // 0x8003C584: subu        $t6, $v1, $v0
        ctx->r14 = SUB32(ctx->r3, ctx->r2);
            goto L_8003C590;
    }
    // 0x8003C584: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C588: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003C58C: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
L_8003C590:
    // 0x8003C590: bne         $v0, $zero, L_8003C59C
    if (ctx->r2 != 0) {
        // 0x8003C594: sh          $t6, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r14;
            goto L_8003C59C;
    }
    // 0x8003C594: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8003C598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8003C59C:
    // 0x8003C59C: beq         $a0, $zero, L_8003C5D8
    if (ctx->r4 == 0) {
        // 0x8003C5A0: nop
    
            goto L_8003C5D8;
    }
    // 0x8003C5A0: nop

    // 0x8003C5A4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8003C5A8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003C5AC: bne         $t7, $zero, L_8003C5F4
    if (ctx->r15 != 0) {
        // 0x8003C5B0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8003C5F4;
    }
    // 0x8003C5B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C5B4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003C5B8: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003C5BC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003C5C0: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x8003C5C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003C5C8: jal         0x80009558
    // 0x8003C5CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_10;
    // 0x8003C5CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_10:
    // 0x8003C5D0: b           L_8003C5F8
    // 0x8003C5D4: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
        goto L_8003C5F8;
    // 0x8003C5D4: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C5D8:
    // 0x8003C5D8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8003C5DC: nop

    // 0x8003C5E0: beq         $v0, $zero, L_8003C5F4
    if (ctx->r2 == 0) {
        // 0x8003C5E4: nop
    
            goto L_8003C5F4;
    }
    // 0x8003C5E4: nop

    // 0x8003C5E8: jal         0x800096F8
    // 0x8003C5EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_11;
    // 0x8003C5EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8003C5F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8003C5F4:
    // 0x8003C5F4: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C5F8:
    // 0x8003C5F8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8003C5FC: sb          $t1, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r9;
    // 0x8003C600: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C604: nop

    // 0x8003C608: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8003C60C: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C610: nop

    // 0x8003C614: lh          $t4, 0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X14);
    // 0x8003C618: nop

    // 0x8003C61C: andi        $t0, $t4, 0xFFF7
    ctx->r8 = ctx->r12 & 0XFFF7;
    // 0x8003C620: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8003C624: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C628: nop

    // 0x8003C62C: sw          $zero, 0x100($t5)
    MEM_W(0X100, ctx->r13) = 0;
    // 0x8003C630: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C634: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003C638: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C63C: jr          $ra
    // 0x8003C640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003C640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void cam_move_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069B70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069B74: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80069B78: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069B7C: addiu       $s2, $s2, 0xCE4
    ctx->r18 = ADD32(ctx->r18, 0XCE4);
    // 0x80069B80: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80069B84: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80069B88: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x80069B8C: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069B90: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069B94: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80069B98: addiu       $s1, $s1, 0xAC0
    ctx->r17 = ADD32(ctx->r17, 0XAC0);
    // 0x80069B9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069BA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069BA4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80069BA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80069BAC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80069BB0: mflo        $t7
    ctx->r15 = lo;
    // 0x80069BB4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80069BB8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x80069BBC: jal         0x800707F8
    // 0x80069BC0: nop

    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069BC0: nop

    after_0:
    // 0x80069BC4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80069BC8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069BCC: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069BD0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069BD4: mflo        $t0
    ctx->r8 = lo;
    // 0x80069BD8: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x80069BDC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069BE0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069BE4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80069BE8: jal         0x800707C4
    // 0x80069BEC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069BEC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80069BF0: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80069BF4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069BF8: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069BFC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80069C00: mflo        $t2
    ctx->r10 = lo;
    // 0x80069C04: addu        $s0, $s1, $t2
    ctx->r16 = ADD32(ctx->r17, ctx->r10);
    // 0x80069C08: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069C0C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069C10: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80069C14: jal         0x800707C4
    // 0x80069C18: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80069C18: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80069C1C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80069C20: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069C24: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069C28: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069C2C: mflo        $t4
    ctx->r12 = lo;
    // 0x80069C30: addu        $s0, $s1, $t4
    ctx->r16 = ADD32(ctx->r17, ctx->r12);
    // 0x80069C34: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069C38: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069C3C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80069C40: jal         0x800707F8
    // 0x80069C44: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x80069C44: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80069C48: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80069C4C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069C50: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069C54: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80069C58: mflo        $t6
    ctx->r14 = lo;
    // 0x80069C5C: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x80069C60: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069C64: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069C68: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069C6C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80069C70: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80069C74: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80069C78: jal         0x80029F18
    // 0x80069C7C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x80069C7C: nop

    after_4:
    // 0x80069C80: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80069C84: nop

    // 0x80069C88: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069C8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80069C90: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80069C94: sh          $v0, 0x34($t9)
    MEM_H(0X34, ctx->r25) = ctx->r2;
    // 0x80069C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069C9C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80069CA0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80069CA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80069CA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069CAC: jr          $ra
    // 0x80069CB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069CB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void racer_AI_pathing_inputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044178: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004417C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80044180: jal         0x8006BD98
    // 0x80044184: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_0;
    // 0x80044184: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004418C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80044190: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80044194: beq         $v0, $at, L_800441B8
    if (ctx->r2 == ctx->r1) {
        // 0x80044198: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800441B8;
    }
    // 0x80044198: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8004419C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800441A0: beq         $v0, $at, L_800441B8
    if (ctx->r2 == ctx->r1) {
        // 0x800441A4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_800441B8;
    }
    // 0x800441A4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800441A8: beq         $v0, $at, L_800441DC
    if (ctx->r2 == ctx->r1) {
        // 0x800441AC: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_800441DC;
    }
    // 0x800441AC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800441B0: b           L_800441FC
    // 0x800441B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_800441FC;
    // 0x800441B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_800441B8:
    // 0x800441B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800441BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800441C0: jal         0x8004447C
    // 0x800441C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    racer_ai_challenge(rdram, ctx);
        goto after_1;
    // 0x800441C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800441C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800441CC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800441D0: b           L_80044218
    // 0x800441D4: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
        goto L_80044218;
    // 0x800441D4: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
    // 0x800441D8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_800441DC:
    // 0x800441DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800441E0: jal         0x800452A0
    // 0x800441E4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    racer_ai_eggs(rdram, ctx);
        goto after_2;
    // 0x800441E4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800441E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800441EC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800441F0: b           L_80044218
    // 0x800441F4: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
        goto L_80044218;
    // 0x800441F4: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
    // 0x800441F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_800441FC:
    // 0x800441FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044200: jal         0x80045C48
    // 0x80044204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80045C48(rdram, ctx);
        goto after_3;
    // 0x80044204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80044208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004420C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044210: nop

    // 0x80044214: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
L_80044218:
    // 0x80044218: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004421C: bne         $t6, $zero, L_80044268
    if (ctx->r14 != 0) {
        // 0x80044220: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_80044268;
    }
    // 0x80044220: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80044224: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80044228: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004422C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044230: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80044234: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80044238: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8004423C: bc1f        L_80044268
    if (!c1cs) {
        // 0x80044240: nop
    
            goto L_80044268;
    }
    // 0x80044240: nop

    // 0x80044244: lb          $t7, 0x215($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X215);
    // 0x80044248: nop

    // 0x8004424C: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80044250: sb          $t8, 0x215($a1)
    MEM_B(0X215, ctx->r5) = ctx->r24;
    // 0x80044254: lb          $t9, 0x215($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X215);
    // 0x80044258: nop

    // 0x8004425C: bgez        $t9, L_80044268
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80044260: nop
    
            goto L_80044268;
    }
    // 0x80044260: nop

    // 0x80044264: sb          $zero, 0x215($a1)
    MEM_B(0X215, ctx->r5) = 0;
L_80044268:
    // 0x80044268: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8004426C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80044270: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80044274: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80044278: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8004427C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80044280: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x80044284: bc1f        L_80044374
    if (!c1cs) {
        // 0x80044288: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_80044374;
    }
    // 0x80044288: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x8004428C: bne         $v0, $zero, L_80044370
    if (ctx->r2 != 0) {
        // 0x80044290: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80044370;
    }
    // 0x80044290: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80044294: lw          $t0, -0x2AC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC0);
    // 0x80044298: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004429C: bne         $t0, $zero, L_80044374
    if (ctx->r8 != 0) {
        // 0x800442A0: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_80044374;
    }
    // 0x800442A0: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800442A8: lwc1        $f6, -0x2ABC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x800442AC: nop

    // 0x800442B0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800442B4: nop

    // 0x800442B8: bc1f        L_80044374
    if (!c1cs) {
        // 0x800442BC: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_80044374;
    }
    // 0x800442BC: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442C0: lb          $t1, 0x1E2($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1E2);
    // 0x800442C4: nop

    // 0x800442C8: beq         $t1, $zero, L_80044374
    if (ctx->r9 == 0) {
        // 0x800442CC: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_80044374;
    }
    // 0x800442CC: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442D0: lb          $t2, 0x215($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X215);
    // 0x800442D4: nop

    // 0x800442D8: bne         $t2, $zero, L_80044374
    if (ctx->r10 != 0) {
        // 0x800442DC: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_80044374;
    }
    // 0x800442DC: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442E0: lb          $t3, 0x213($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X213);
    // 0x800442E4: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x800442E8: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800442EC: sb          $t4, 0x213($a1)
    MEM_B(0X213, ctx->r5) = ctx->r12;
    // 0x800442F0: lb          $t5, 0x213($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X213);
    // 0x800442F4: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x800442F8: slti        $at, $t5, 0x3D
    ctx->r1 = SIGNED(ctx->r13) < 0X3D ? 1 : 0;
    // 0x800442FC: bne         $at, $zero, L_80044364
    if (ctx->r1 != 0) {
        // 0x80044300: andi        $t8, $a3, 0x40
        ctx->r24 = ctx->r7 & 0X40;
            goto L_80044364;
    }
    // 0x80044300: andi        $t8, $a3, 0x40
    ctx->r24 = ctx->r7 & 0X40;
    // 0x80044304: sb          $zero, 0x213($a1)
    MEM_B(0X213, ctx->r5) = 0;
    // 0x80044308: sb          $t6, 0x214($a1)
    MEM_B(0X214, ctx->r5) = ctx->r14;
    // 0x8004430C: bne         $t8, $zero, L_8004432C
    if (ctx->r24 != 0) {
        // 0x80044310: sb          $t7, 0x215($a1)
        MEM_B(0X215, ctx->r5) = ctx->r15;
            goto L_8004432C;
    }
    // 0x80044310: sb          $t7, 0x215($a1)
    MEM_B(0X215, ctx->r5) = ctx->r15;
    // 0x80044314: lb          $t9, 0x1CA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1CA);
    // 0x80044318: nop

    // 0x8004431C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80044320: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80044324: b           L_80044364
    // 0x80044328: sb          $t1, 0x1CA($a1)
    MEM_B(0X1CA, ctx->r5) = ctx->r9;
        goto L_80044364;
    // 0x80044328: sb          $t1, 0x1CA($a1)
    MEM_B(0X1CA, ctx->r5) = ctx->r9;
L_8004432C:
    // 0x8004432C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80044330: beq         $a3, $at, L_80044340
    if (ctx->r7 == ctx->r1) {
        // 0x80044334: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_80044340;
    }
    // 0x80044334: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80044338: bne         $a3, $at, L_80044364
    if (ctx->r7 != ctx->r1) {
        // 0x8004433C: nop
    
            goto L_80044364;
    }
    // 0x8004433C: nop

L_80044340:
    // 0x80044340: lbu         $a0, 0x1CE($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1CE);
    // 0x80044344: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044348: beq         $a0, $at, L_80044364
    if (ctx->r4 == ctx->r1) {
        // 0x8004434C: nop
    
            goto L_80044364;
    }
    // 0x8004434C: nop

    // 0x80044350: jal         0x8001D214
    // 0x80044354: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    ainode_get(rdram, ctx);
        goto after_4;
    // 0x80044354: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80044358: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004435C: nop

    // 0x80044360: sw          $v0, 0x154($a1)
    MEM_W(0X154, ctx->r5) = ctx->r2;
L_80044364:
    // 0x80044364: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x80044368: b           L_80044394
    // 0x8004436C: nop

        goto L_80044394;
    // 0x8004436C: nop

L_80044370:
    // 0x80044370: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
L_80044374:
    // 0x80044374: sb          $t2, 0x214($a1)
    MEM_B(0X214, ctx->r5) = ctx->r10;
    // 0x80044378: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x8004437C: sb          $zero, 0x213($a1)
    MEM_B(0X213, ctx->r5) = 0;
    // 0x80044380: bgez        $v0, L_80044394
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80044384: nop
    
            goto L_80044394;
    }
    // 0x80044384: nop

    // 0x80044388: sb          $zero, 0x214($a1)
    MEM_B(0X214, ctx->r5) = 0;
    // 0x8004438C: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x80044390: nop

L_80044394:
    // 0x80044394: beq         $v0, $zero, L_800443E0
    if (ctx->r2 == 0) {
        // 0x80044398: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800443E0;
    }
    // 0x80044398: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004439C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800443A0: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x800443A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800443A8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800443AC: addiu       $v1, $v1, -0x2ACC
    ctx->r3 = ADD32(ctx->r3, -0X2ACC);
    // 0x800443B0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800443B4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800443B8: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800443BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800443C0: addiu       $a0, $a0, -0x2AC8
    ctx->r4 = ADD32(ctx->r4, -0X2AC8);
    // 0x800443C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800443C8: addiu       $t7, $zero, -0x32
    ctx->r15 = ADD32(0, -0X32);
    // 0x800443CC: ori         $t9, $t6, 0x4000
    ctx->r25 = ctx->r14 | 0X4000;
    // 0x800443D0: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800443D4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800443D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800443DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800443E0:
    // 0x800443E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800443E4: addiu       $v1, $v1, -0x2ACC
    ctx->r3 = ADD32(ctx->r3, -0X2ACC);
    // 0x800443E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800443EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800443F0: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x800443F4: bne         $at, $zero, L_80044404
    if (ctx->r1 != 0) {
        // 0x800443F8: addiu       $a0, $a0, -0x2AC8
        ctx->r4 = ADD32(ctx->r4, -0X2AC8);
            goto L_80044404;
    }
    // 0x800443F8: addiu       $a0, $a0, -0x2AC8
    ctx->r4 = ADD32(ctx->r4, -0X2AC8);
    // 0x800443FC: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x80044400: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80044404:
    // 0x80044404: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x80044408: beq         $at, $zero, L_80044414
    if (ctx->r1 == 0) {
        // 0x8004440C: addiu       $t1, $zero, -0x4B
        ctx->r9 = ADD32(0, -0X4B);
            goto L_80044414;
    }
    // 0x8004440C: addiu       $t1, $zero, -0x4B
    ctx->r9 = ADD32(0, -0X4B);
    // 0x80044410: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80044414:
    // 0x80044414: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80044418: addiu       $t3, $zero, -0x4B
    ctx->r11 = ADD32(0, -0X4B);
    // 0x8004441C: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x80044420: bne         $at, $zero, L_80044434
    if (ctx->r1 != 0) {
        // 0x80044424: slti        $at, $v0, -0x4B
        ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
            goto L_80044434;
    }
    // 0x80044424: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x80044428: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x8004442C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80044430: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
L_80044434:
    // 0x80044434: beq         $at, $zero, L_80044444
    if (ctx->r1 == 0) {
        // 0x80044438: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044444;
    }
    // 0x80044438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004443C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80044440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044444:
    // 0x80044444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044448: jr          $ra
    // 0x8004444C: nop

    return;
    // 0x8004444C: nop

;}
RECOMP_FUNC void obj_loop_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003763C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80037640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037644: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80037648: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003764C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80037650: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80037654: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037658: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8003765C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80037660: jal         0x8001BAAC
    // 0x80037664: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    get_racer_objects_by_position(rdram, ctx);
        goto after_0;
    // 0x80037664: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80037668: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8003766C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80037670: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x80037674: nop

    // 0x80037678: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003767C: beq         $at, $zero, L_800376D0
    if (ctx->r1 == 0) {
        // 0x80037680: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800376D0;
    }
    // 0x80037680: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80037684: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80037688: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8003768C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037690: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x80037694: nop

    // 0x80037698: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x8003769C: nop

    // 0x800376A0: bne         $t1, $at, L_800376C8
    if (ctx->r9 != ctx->r1) {
        // 0x800376A4: sll         $t4, $v1, 7
        ctx->r12 = S32(ctx->r3 << 7);
            goto L_800376C8;
    }
    // 0x800376A4: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
    // 0x800376A8: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x800376AC: nop

    // 0x800376B0: andi        $t3, $t2, 0xBFFF
    ctx->r11 = ctx->r10 & 0XBFFF;
    // 0x800376B4: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    // 0x800376B8: sw          $a1, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r5;
    // 0x800376BC: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x800376C0: nop

    // 0x800376C4: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
L_800376C8:
    // 0x800376C8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800376CC: sh          $t4, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r12;
L_800376D0:
    // 0x800376D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800376D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800376D8: jr          $ra
    // 0x800376DC: nop

    return;
    // 0x800376DC: nop

;}
RECOMP_FUNC void rdp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007805C: jal         0x8007A520
    // 0x80078060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80078064: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80078068: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8007806C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078070: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80078074: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078078: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x8007807C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80078080: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80078084: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x80078088: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007808C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80078090: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078094: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x80078098: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8007809C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800780A0: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x800780A4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800780A8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800780AC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800780B0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800780B4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800780B8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800780BC: addiu       $t7, $t7, -0x1AE0
    ctx->r15 = ADD32(ctx->r15, -0X1AE0);
    // 0x800780C0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800780C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800780C8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800780CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800780D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800780D4: jr          $ra
    // 0x800780D8: nop

    return;
    // 0x800780D8: nop

;}
RECOMP_FUNC void block_boundbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A2DC: bltz        $a0, L_8002A300
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A2E0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A300;
    }
    // 0x8002A2E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A2E4: lw          $v1, -0x36E8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X36E8);
    // 0x8002A2E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8002A2EC: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A2F0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8002A2F4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A2F8: beq         $at, $zero, L_8002A308
    if (ctx->r1 == 0) {
        // 0x8002A2FC: nop
    
            goto L_8002A308;
    }
    // 0x8002A2FC: nop

L_8002A300:
    // 0x8002A300: jr          $ra
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A308:
    // 0x8002A308: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8002A30C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A310: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A314: jr          $ra
    // 0x8002A318: nop

    return;
    // 0x8002A318: nop

;}
RECOMP_FUNC void func_8000E898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E898: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E89C: addiu       $t7, $t7, -0x5160
    ctx->r15 = ADD32(ctx->r15, -0X5160);
    // 0x8000E8A0: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x8000E8A4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E8A8: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8000E8AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E8B0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8000E8B4: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8000E8B8: lw          $t8, -0x5168($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5168);
    // 0x8000E8BC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E8C0: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x8000E8C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E8C8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000E8CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000E8D0: blez        $t6, L_8000E940
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000E8D4: addu        $v1, $t0, $t8
        ctx->r3 = ADD32(ctx->r8, ctx->r24);
            goto L_8000E940;
    }
    // 0x8000E8D4: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E8D8: andi        $t0, $t6, 0x3
    ctx->r8 = ctx->r14 & 0X3;
    // 0x8000E8DC: beq         $t0, $zero, L_8000E908
    if (ctx->r8 == 0) {
        // 0x8000E8E0: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_8000E908;
    }
    // 0x8000E8E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8000E8E4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8000E8E8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8000E8EC:
    // 0x8000E8EC: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E8F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000E8F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E8F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E8FC: bne         $a1, $t1, L_8000E8EC
    if (ctx->r5 != ctx->r9) {
        // 0x8000E900: sb          $t2, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r10;
            goto L_8000E8EC;
    }
    // 0x8000E900: sb          $t2, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r10;
    // 0x8000E904: beq         $t1, $v0, L_8000E940
    if (ctx->r9 == ctx->r2) {
        // 0x8000E908: addu        $a2, $v1, $t1
        ctx->r6 = ADD32(ctx->r3, ctx->r9);
            goto L_8000E940;
    }
L_8000E908:
    // 0x8000E908: addu        $a2, $v1, $t1
    ctx->r6 = ADD32(ctx->r3, ctx->r9);
    // 0x8000E90C: addu        $a3, $a0, $t1
    ctx->r7 = ADD32(ctx->r4, ctx->r9);
L_8000E910:
    // 0x8000E910: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E914: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8000E918: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8000E91C: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x8000E920: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000E924: sb          $t4, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = ctx->r12;
    // 0x8000E928: lbu         $t5, 0x2($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2);
    // 0x8000E92C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E930: sb          $t5, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r13;
    // 0x8000E934: lbu         $t6, -0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, -0X1);
    // 0x8000E938: bne         $t1, $v0, L_8000E910
    if (ctx->r9 != ctx->r2) {
        // 0x8000E93C: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E910;
    }
    // 0x8000E93C: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
L_8000E940:
    // 0x8000E940: jr          $ra
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80049794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049794: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80049798: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004979C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800497A0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800497A4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800497A8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800497AC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800497B0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800497B4: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800497B8: jal         0x8000E138
    // 0x800497BC: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    func_8000E138(rdram, ctx);
        goto after_0;
    // 0x800497BC: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    after_0:
    // 0x800497C0: beq         $v0, $zero, L_800497E4
    if (ctx->r2 == 0) {
        // 0x800497C4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800497E4;
    }
    // 0x800497C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800497C8: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800497CC: lwc1        $f9, 0x64A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X64A8);
    // 0x800497D0: lwc1        $f8, 0x64AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64AC);
    // 0x800497D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800497D8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800497DC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800497E0: swc1        $f18, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f18.u32l;
L_800497E4:
    // 0x800497E4: sb          $zero, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = 0;
    // 0x800497E8: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x800497EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800497F0: blez        $t6, L_80049808
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800497F4: nop
    
            goto L_80049808;
    }
    // 0x800497F4: nop

    // 0x800497F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800497FC: nop

    // 0x80049800: swc1        $f14, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f14.u32l;
    // 0x80049804: swc1        $f14, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f14.u32l;
L_80049808:
    // 0x80049808: lbu         $t7, 0x1FE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004980C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80049810: bne         $t7, $at, L_8004983C
    if (ctx->r15 != ctx->r1) {
        // 0x80049814: nop
    
            goto L_8004983C;
    }
    // 0x80049814: nop

    // 0x80049818: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004981C: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    // 0x80049820: bne         $t8, $zero, L_8004983C
    if (ctx->r24 != 0) {
        // 0x80049824: nop
    
            goto L_8004983C;
    }
    // 0x80049824: nop

    // 0x80049828: jal         0x80001D04
    // 0x8004982C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8004982C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80049830: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80049834: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80049838: sb          $t9, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r25;
L_8004983C:
    // 0x8004983C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80049840: lw          $t3, -0x2AA4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AA4);
    // 0x80049844: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80049848: beq         $t1, $t3, L_80049ADC
    if (ctx->r9 == ctx->r11) {
        // 0x8004984C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80049ADC;
    }
    // 0x8004984C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80049850: lb          $t4, 0x1D7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D7);
    // 0x80049854: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80049858: beq         $t4, $at, L_80049ADC
    if (ctx->r12 == ctx->r1) {
        // 0x8004985C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80049ADC;
    }
    // 0x8004985C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80049860: lb          $v0, -0x2A52($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2A52);
    // 0x80049864: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049868: beq         $v0, $zero, L_80049ADC
    if (ctx->r2 == 0) {
        // 0x8004986C: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80049ADC;
    }
    // 0x8004986C: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80049870: bltz        $v1, L_800498DC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80049874: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800498DC;
    }
    // 0x80049874: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80049878: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004987C: lw          $t5, -0x2A50($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2A50);
    // 0x80049880: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80049884: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80049888: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8004988C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80049890: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049894: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049898: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8004989C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800498A0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800498A4: nop

    // 0x800498A8: bc1f        L_800498DC
    if (!c1cs) {
        // 0x800498AC: nop
    
            goto L_800498DC;
    }
    // 0x800498AC: nop

L_800498B0:
    // 0x800498B0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800498B4: bltz        $a0, L_800498DC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800498B8: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800498DC;
    }
    // 0x800498B8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800498BC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800498C0: nop

    // 0x800498C4: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800498C8: nop

    // 0x800498CC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800498D0: nop

    // 0x800498D4: bc1t        L_800498B0
    if (c1cs) {
        // 0x800498D8: nop
    
            goto L_800498B0;
    }
    // 0x800498D8: nop

L_800498DC:
    // 0x800498DC: lw          $t9, -0x2A50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2A50);
    // 0x800498E0: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x800498E4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800498E8: bne         $a0, $v1, L_800498F8
    if (ctx->r4 != ctx->r3) {
        // 0x800498EC: addu        $v0, $t9, $a1
        ctx->r2 = ADD32(ctx->r25, ctx->r5);
            goto L_800498F8;
    }
    // 0x800498EC: addu        $v0, $t9, $a1
    ctx->r2 = ADD32(ctx->r25, ctx->r5);
    // 0x800498F0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800498F4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_800498F8:
    // 0x800498F8: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x800498FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80049900: lwc1        $f2, 0x0($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80049904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049908: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8004990C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80049910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049914: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80049918: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004991C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80049920: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049924: bc1f        L_80049930
    if (!c1cs) {
        // 0x80049928: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_80049930;
    }
    // 0x80049928: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8004992C: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_80049930:
    // 0x80049930: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049934: nop

    // 0x80049938: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004993C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80049940: nop

    // 0x80049944: bc1f        L_80049950
    if (!c1cs) {
        // 0x80049948: nop
    
            goto L_80049950;
    }
    // 0x80049948: nop

    // 0x8004994C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80049950:
    // 0x80049950: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80049954: nop

    // 0x80049958: bc1f        L_80049980
    if (!c1cs) {
        // 0x8004995C: nop
    
            goto L_80049980;
    }
    // 0x8004995C: nop

    // 0x80049960: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80049964: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049968: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8004996C: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80049970: nop

    // 0x80049974: bc1f        L_80049980
    if (!c1cs) {
        // 0x80049978: nop
    
            goto L_80049980;
    }
    // 0x80049978: nop

    // 0x8004997C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80049980:
    // 0x80049980: lb          $t4, 0x1E6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E6);
    // 0x80049984: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80049988: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004998C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049990: bne         $t4, $zero, L_800499C8
    if (ctx->r12 != 0) {
        // 0x80049994: lui         $at, 0x4218
        ctx->r1 = S32(0X4218 << 16);
            goto L_800499C8;
    }
    // 0x80049994: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80049998: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004999C: nop

    // 0x800499A0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800499A4: nop

    // 0x800499A8: bc1f        L_800499C8
    if (!c1cs) {
        // 0x800499AC: nop
    
            goto L_800499C8;
    }
    // 0x800499AC: nop

    // 0x800499B0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800499B4: c.le.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d <= ctx->f4.d;
    // 0x800499B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800499BC: bc1f        L_800499C8
    if (!c1cs) {
        // 0x800499C0: nop
    
            goto L_800499C8;
    }
    // 0x800499C0: nop

    // 0x800499C4: sb          $t5, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r13;
L_800499C8:
    // 0x800499C8: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x800499CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800499D0: beq         $v0, $at, L_80049A10
    if (ctx->r2 == ctx->r1) {
        // 0x800499D4: nop
    
            goto L_80049A10;
    }
    // 0x800499D4: nop

    // 0x800499D8: beq         $t1, $v0, L_80049A10
    if (ctx->r9 == ctx->r2) {
        // 0x800499DC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80049A10;
    }
    // 0x800499DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800499E0: lw          $t6, -0x2A50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A50);
    // 0x800499E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800499E8: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800499EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800499F0: lwc1        $f11, 0x64B0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X64B0);
    // 0x800499F4: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800499F8: lwc1        $f10, 0x64B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64B4);
    // 0x800499FC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80049A00: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80049A04: nop

    // 0x80049A08: bc1f        L_80049A18
    if (!c1cs) {
        // 0x80049A0C: nop
    
            goto L_80049A18;
    }
    // 0x80049A0C: nop

L_80049A10:
    // 0x80049A10: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x80049A14: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_80049A18:
    // 0x80049A18: lb          $t9, 0x1E6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E6);
    // 0x80049A1C: nop

    // 0x80049A20: beq         $t9, $zero, L_80049AE0
    if (ctx->r25 == 0) {
        // 0x80049A24: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80049AE0;
    }
    // 0x80049A24: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80049A28: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80049A2C: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x80049A30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049A34: bc1t        L_80049A54
    if (c1cs) {
        // 0x80049A38: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80049A54;
    }
    // 0x80049A38: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049A3C: addiu       $t0, $t0, -0x2AC8
    ctx->r8 = ADD32(ctx->r8, -0X2AC8);
    // 0x80049A40: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80049A44: nop

    // 0x80049A48: slti        $at, $t3, -0xA
    ctx->r1 = SIGNED(ctx->r11) < -0XA ? 1 : 0;
    // 0x80049A4C: beq         $at, $zero, L_80049A64
    if (ctx->r1 == 0) {
        // 0x80049A50: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80049A64;
    }
    // 0x80049A50: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049A54:
    // 0x80049A54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049A58: addiu       $t0, $t0, -0x2AC8
    ctx->r8 = ADD32(ctx->r8, -0X2AC8);
    // 0x80049A5C: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x80049A60: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049A64:
    // 0x80049A64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049A68: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80049A6C: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80049A70: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80049A74: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80049A78: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80049A7C: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049A80: bc1f        L_80049A90
    if (!c1cs) {
        // 0x80049A84: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80049A90;
    }
    // 0x80049A84: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049A88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049A8C: nop

L_80049A90:
    // 0x80049A90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049A94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049A98: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80049A9C: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80049AA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049AA4: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049AA8: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80049AAC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049AB0: nop

    // 0x80049AB4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049AB8: nop

    // 0x80049ABC: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80049AC0: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80049AC4: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80049AC8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80049ACC: nop

    // 0x80049AD0: blez        $v0, L_80049ADC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049AD4: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80049ADC;
    }
    // 0x80049AD4: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80049AD8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_80049ADC:
    // 0x80049ADC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049AE0:
    // 0x80049AE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049AE8: sh          $zero, -0x2AB0($at)
    MEM_H(-0X2AB0, ctx->r1) = 0;
    // 0x80049AEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049AF0: sw          $zero, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = 0;
    // 0x80049AF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049AF8: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    // 0x80049AFC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80049B00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049B04: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80049B08: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049B0C: addiu       $t0, $t0, -0x2AC8
    ctx->r8 = ADD32(ctx->r8, -0X2AC8);
    // 0x80049B10: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x80049B14: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80049B18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049B1C: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
    // 0x80049B20: lb          $t5, 0x1E0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E0);
    // 0x80049B24: nop

    // 0x80049B28: beq         $t5, $zero, L_80049B3C
    if (ctx->r13 == 0) {
        // 0x80049B2C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80049B3C;
    }
    // 0x80049B2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049B30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80049B34: b           L_80049B44
    // 0x80049B38: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
        goto L_80049B44;
    // 0x80049B38: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
L_80049B3C:
    // 0x80049B3C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80049B40: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
L_80049B44:
    // 0x80049B44: lw          $t6, -0x2ACC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2ACC);
    // 0x80049B48: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049B4C: subu        $v0, $t6, $a1
    ctx->r2 = SUB32(ctx->r14, ctx->r5);
    // 0x80049B50: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80049B54: nop

    // 0x80049B58: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80049B5C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049B60: nop

    // 0x80049B64: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80049B68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80049B6C: nop

    // 0x80049B70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80049B74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049B78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049B7C: nop

    // 0x80049B80: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80049B84: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80049B88: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80049B8C: beq         $v0, $zero, L_80049BB4
    if (ctx->r2 == 0) {
        // 0x80049B90: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80049BB4;
    }
    // 0x80049B90: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80049B94: bne         $a0, $zero, L_80049BB8
    if (ctx->r4 != 0) {
        // 0x80049B98: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_80049BB8;
    }
    // 0x80049B98: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x80049B9C: blez        $v0, L_80049BA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049BA0: nop
    
            goto L_80049BA8;
    }
    // 0x80049BA0: nop

    // 0x80049BA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80049BA8:
    // 0x80049BA8: bgez        $v0, L_80049BB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80049BAC: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_80049BB8;
    }
    // 0x80049BAC: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x80049BB0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80049BB4:
    // 0x80049BB4: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
L_80049BB8:
    // 0x80049BB8: sb          $t8, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r24;
    // 0x80049BBC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80049BC0: lb          $a3, 0x1E8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E8);
    // 0x80049BC4: lwc1        $f6, 0xFC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049BC8: subu        $v0, $t9, $a3
    ctx->r2 = SUB32(ctx->r25, ctx->r7);
    // 0x80049BCC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80049BD0: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x80049BD4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80049BD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80049BDC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80049BE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80049BE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049BE8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80049BEC: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80049BF0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80049BF4: nop

    // 0x80049BF8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80049BFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049C00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049C04: nop

    // 0x80049C08: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80049C0C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80049C10: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80049C14: beq         $v0, $zero, L_80049C3C
    if (ctx->r2 == 0) {
        // 0x80049C18: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80049C3C;
    }
    // 0x80049C18: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80049C1C: bne         $a0, $zero, L_80049C40
    if (ctx->r4 != 0) {
        // 0x80049C20: addu        $t4, $a3, $v1
        ctx->r12 = ADD32(ctx->r7, ctx->r3);
            goto L_80049C40;
    }
    // 0x80049C20: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x80049C24: blez        $v0, L_80049C30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049C28: nop
    
            goto L_80049C30;
    }
    // 0x80049C28: nop

    // 0x80049C2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80049C30:
    // 0x80049C30: bgez        $v0, L_80049C40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80049C34: addu        $t4, $a3, $v1
        ctx->r12 = ADD32(ctx->r7, ctx->r3);
            goto L_80049C40;
    }
    // 0x80049C34: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x80049C38: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80049C3C:
    // 0x80049C3C: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
L_80049C40:
    // 0x80049C40: sb          $t4, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r12;
    // 0x80049C44: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x80049C48: sb          $t2, 0xA2($sp)
    MEM_B(0XA2, ctx->r29) = ctx->r10;
    // 0x80049C4C: jal         0x80055EC0
    // 0x80049C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    handle_racer_items(rdram, ctx);
        goto after_2;
    // 0x80049C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80049C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049C58: jal         0x800535C4
    // 0x80049C5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_3;
    // 0x80049C5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80049C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049C64: jal         0x8004C140
    // 0x80049C68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_plane(rdram, ctx);
        goto after_4;
    // 0x80049C68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80049C6C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80049C70: lw          $t5, -0x2AA4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AA4);
    // 0x80049C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80049C78: beq         $t5, $at, L_80049C98
    if (ctx->r13 == ctx->r1) {
        // 0x80049C7C: nop
    
            goto L_80049C98;
    }
    // 0x80049C7C: nop

    // 0x80049C80: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x80049C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049C88: jal         0x800521C4
    // 0x80049C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_5;
    // 0x80049C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80049C90: b           L_80049CA0
    // 0x80049C94: nop

        goto L_80049CA0;
    // 0x80049C94: nop

L_80049C98:
    // 0x80049C98: jal         0x8005234C
    // 0x80049C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    slowly_reset_head_angle(rdram, ctx);
        goto after_6;
    // 0x80049C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80049CA0:
    // 0x80049CA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049CA4: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x80049CA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049CAC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80049CB0: beq         $t7, $zero, L_80049D18
    if (ctx->r15 == 0) {
        // 0x80049CB4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049D18;
    }
    // 0x80049CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049CB8: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049CBC: lwc1        $f5, 0x64B8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X64B8);
    // 0x80049CC0: lwc1        $f4, 0x64BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64BC);
    // 0x80049CC4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80049CC8: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80049CCC: lwc1        $f10, 0xB4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049CD0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80049CD4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80049CD8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80049CDC: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80049CE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049CE4: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80049CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049CEC: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x80049CF0: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049CF4: nop

    // 0x80049CF8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80049CFC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80049D00: nop

    // 0x80049D04: bc1f        L_80049D70
    if (!c1cs) {
        // 0x80049D08: nop
    
            goto L_80049D70;
    }
    // 0x80049D08: nop

    // 0x80049D0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049D10: b           L_80049D70
    // 0x80049D14: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
        goto L_80049D70;
    // 0x80049D14: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
L_80049D18:
    // 0x80049D18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049D1C: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049D20: lwc1        $f7, 0x64C0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X64C0);
    // 0x80049D24: lwc1        $f6, 0x64C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64C4);
    // 0x80049D28: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80049D2C: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80049D30: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D34: nop

    // 0x80049D38: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80049D3C: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x80049D40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049D44: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80049D48: swc1        $f18, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f18.u32l;
    // 0x80049D4C: lwc1        $f6, 0xB4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D50: nop

    // 0x80049D54: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80049D58: nop

    // 0x80049D5C: bc1f        L_80049D70
    if (!c1cs) {
        // 0x80049D60: nop
    
            goto L_80049D70;
    }
    // 0x80049D60: nop

    // 0x80049D64: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80049D68: nop

    // 0x80049D6C: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
L_80049D70:
    // 0x80049D70: lw          $t8, 0x108($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X108);
    // 0x80049D74: nop

    // 0x80049D78: beq         $t8, $zero, L_80049D8C
    if (ctx->r24 == 0) {
        // 0x80049D7C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80049D8C;
    }
    // 0x80049D7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80049D80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049D84: nop

    // 0x80049D88: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
L_80049D8C:
    // 0x80049D8C: lw          $t9, -0x2AD8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AD8);
    // 0x80049D90: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D94: andi        $t3, $t9, 0x4000
    ctx->r11 = ctx->r25 & 0X4000;
    // 0x80049D98: beq         $t3, $zero, L_80049E7C
    if (ctx->r11 == 0) {
        // 0x80049D9C: swc1        $f18, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
            goto L_80049E7C;
    }
    // 0x80049D9C: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x80049DA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80049DA4: lw          $t4, -0x2AC8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AC8);
    // 0x80049DA8: nop

    // 0x80049DAC: slti        $at, $t4, -0x28
    ctx->r1 = SIGNED(ctx->r12) < -0X28 ? 1 : 0;
    // 0x80049DB0: bne         $at, $zero, L_80049DD0
    if (ctx->r1 != 0) {
        // 0x80049DB4: nop
    
            goto L_80049DD0;
    }
    // 0x80049DB4: nop

    // 0x80049DB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049DBC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049DC0: nop

    // 0x80049DC4: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80049DC8: nop

    // 0x80049DCC: bc1f        L_80049E7C
    if (!c1cs) {
        // 0x80049DD0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049E7C;
    }
L_80049DD0:
    // 0x80049DD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049DD4: lwc1        $f11, 0x64C8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X64C8);
    // 0x80049DD8: lwc1        $f10, 0x64CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64CC);
    // 0x80049DDC: lwc1        $f4, 0xB8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049DE0: mul.d       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80049DE4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80049DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049DEC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049DF0: add.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d + ctx->f18.d;
    // 0x80049DF4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80049DF8: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x80049DFC: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049E00: lwc1        $f10, 0x64D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64D4);
    // 0x80049E04: lwc1        $f11, 0x64D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X64D0);
    // 0x80049E08: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80049E0C: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x80049E10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80049E14: bc1f        L_80049E28
    if (!c1cs) {
        // 0x80049E18: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049E28;
    }
    // 0x80049E18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049E1C: lwc1        $f6, 0x64D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64D8);
    // 0x80049E20: nop

    // 0x80049E24: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
L_80049E28:
    // 0x80049E28: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049E2C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80049E30: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80049E34: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80049E38: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80049E3C: nop

    // 0x80049E40: bc1f        L_80049E70
    if (!c1cs) {
        // 0x80049E44: nop
    
            goto L_80049E70;
    }
    // 0x80049E44: nop

    // 0x80049E48: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80049E4C: nop

    // 0x80049E50: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80049E54: bne         $at, $zero, L_80049E70
    if (ctx->r1 != 0) {
        // 0x80049E58: nop
    
            goto L_80049E70;
    }
    // 0x80049E58: nop

    // 0x80049E5C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80049E60: jal         0x80072348
    // 0x80049E64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    rumble_set(rdram, ctx);
        goto after_7;
    // 0x80049E64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80049E68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049E6C: nop

L_80049E70:
    // 0x80049E70: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049E74: b           L_80049ECC
    // 0x80049E78: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
        goto L_80049ECC;
    // 0x80049E78: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
L_80049E7C:
    // 0x80049E7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049E80: lwc1        $f5, 0x64E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X64E0);
    // 0x80049E84: lwc1        $f4, 0x64E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64E4);
    // 0x80049E88: lwc1        $f18, 0xB8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049E8C: mul.d       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80049E90: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80049E94: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049E98: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80049E9C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80049EA0: swc1        $f18, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
    // 0x80049EA4: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049EA8: nop

    // 0x80049EAC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80049EB0: nop

    // 0x80049EB4: bc1f        L_80049EC8
    if (!c1cs) {
        // 0x80049EB8: nop
    
            goto L_80049EC8;
    }
    // 0x80049EB8: nop

    // 0x80049EBC: swc1        $f12, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f12.u32l;
    // 0x80049EC0: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049EC4: nop

L_80049EC8:
    // 0x80049EC8: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
L_80049ECC:
    // 0x80049ECC: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80049ED0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80049ED4: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80049ED8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80049EDC: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80049EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049EE8: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80049EEC: swc1        $f12, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f12.u32l;
    // 0x80049EF0: swc1        $f12, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f12.u32l;
    // 0x80049EF4: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x80049EF8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049EFC: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80049F00: jal         0x8006FC30
    // 0x80049F04: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_8;
    // 0x80049F04: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_8:
    // 0x80049F08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049F0C: addiu       $t8, $s0, 0x38
    ctx->r24 = ADD32(ctx->r16, 0X38);
    // 0x80049F10: addiu       $t9, $s0, 0x3C
    ctx->r25 = ADD32(ctx->r16, 0X3C);
    // 0x80049F14: addiu       $t3, $s0, 0x40
    ctx->r11 = ADD32(ctx->r16, 0X40);
    // 0x80049F18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80049F1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80049F20: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80049F24: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80049F28: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80049F2C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049F30: jal         0x8006F64C
    // 0x80049F34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_9;
    // 0x80049F34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x80049F38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049F3C: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x80049F40: addiu       $t5, $s0, 0x54
    ctx->r13 = ADD32(ctx->r16, 0X54);
    // 0x80049F44: addiu       $t6, $s0, 0x58
    ctx->r14 = ADD32(ctx->r16, 0X58);
    // 0x80049F48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80049F4C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80049F50: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80049F54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80049F58: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80049F5C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049F60: jal         0x8006F64C
    // 0x80049F64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_10;
    // 0x80049F64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x80049F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049F6C: addiu       $t7, $s0, 0x44
    ctx->r15 = ADD32(ctx->r16, 0X44);
    // 0x80049F70: addiu       $t8, $s0, 0x48
    ctx->r24 = ADD32(ctx->r16, 0X48);
    // 0x80049F74: addiu       $t9, $s0, 0x4C
    ctx->r25 = ADD32(ctx->r16, 0X4C);
    // 0x80049F78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80049F7C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80049F80: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80049F84: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80049F88: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80049F8C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049F90: jal         0x8006F64C
    // 0x80049F94: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_11;
    // 0x80049F94: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80049F98: lw          $t3, 0x148($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X148);
    // 0x80049F9C: nop

    // 0x80049FA0: bne         $t3, $zero, L_80049FB8
    if (ctx->r11 != 0) {
        // 0x80049FA4: nop
    
            goto L_80049FB8;
    }
    // 0x80049FA4: nop

    // 0x80049FA8: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80049FAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80049FB0: jal         0x8004C0A0
    // 0x80049FB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    apply_plane_tilt_anim(rdram, ctx);
        goto after_12;
    // 0x80049FB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
L_80049FB8:
    // 0x80049FB8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80049FBC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80049FC0: bne         $v1, $v0, L_80049FE4
    if (ctx->r3 != ctx->r2) {
        // 0x80049FC4: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80049FE4;
    }
    // 0x80049FC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80049FC8: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x80049FCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049FD0: beq         $v1, $t4, L_80049FE4
    if (ctx->r3 == ctx->r12) {
        // 0x80049FD4: nop
    
            goto L_80049FE4;
    }
    // 0x80049FD4: nop

    // 0x80049FD8: lwc1        $f6, 0x64E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X64E8);
    // 0x80049FDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049FE0: swc1        $f6, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f6.u32l;
L_80049FE4:
    // 0x80049FE4: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80049FE8: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80049FEC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80049FF0: lwc1        $f14, 0x20($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80049FF4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80049FF8: nop

    // 0x80049FFC: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004A000: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004A004: jal         0x800C9AD0
    // 0x8004A008: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x8004A008: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_13:
    // 0x8004A00C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A010: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8004A014: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004A018: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8004A01C: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A020: sub.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d - ctx->f14.d;
    // 0x8004A024: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8004A028: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8004A02C: bne         $at, $zero, L_8004A054
    if (ctx->r1 != 0) {
        // 0x8004A030: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_8004A054;
    }
    // 0x8004A030: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8004A034: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8004A038: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004A03C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A040: sub.d       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = ctx->f10.d - ctx->f14.d;
    // 0x8004A044: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A048: nop

    // 0x8004A04C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8004A050: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
L_8004A054:
    // 0x8004A054: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004A058: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004A05C: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8004A060: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004A064: bc1f        L_8004A070
    if (!c1cs) {
        // 0x8004A068: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004A070;
    }
    // 0x8004A068: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004A06C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_8004A070:
    // 0x8004A070: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A074: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A078: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004A07C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A080: bc1f        L_8004A094
    if (!c1cs) {
        // 0x8004A084: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004A094;
    }
    // 0x8004A084: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A088: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A08C: nop

    // 0x8004A090: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_8004A094:
    // 0x8004A094: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A098: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A09C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004A0A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004A0A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A0A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A0AC: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8004A0B0: lwc1        $f8, -0x2B10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B10);
    // 0x8004A0B4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004A0B8: sb          $zero, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = 0;
    // 0x8004A0BC: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004A0C0: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8004A0C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A0C8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A0CC: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004A0D0: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004A0D4: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A0D8: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x8004A0DC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004A0E0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004A0E4: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x8004A0E8: beq         $at, $zero, L_8004A178
    if (ctx->r1 == 0) {
        // 0x8004A0EC: cvt.s.d     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
            goto L_8004A178;
    }
    // 0x8004A0EC: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A0F0: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8004A0F4: bne         $at, $zero, L_8004A178
    if (ctx->r1 != 0) {
        // 0x8004A0F8: nop
    
            goto L_8004A178;
    }
    // 0x8004A0F8: nop

    // 0x8004A0FC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8004A100: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8004A104: bc1f        L_8004A178
    if (!c1cs) {
        // 0x8004A108: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8004A178;
    }
    // 0x8004A108: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004A10C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A114: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8004A118: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A11C: nop

    // 0x8004A120: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x8004A124: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A128: addiu       $t1, $t1, -0x2AC8
    ctx->r9 = ADD32(ctx->r9, -0X2AC8);
    // 0x8004A12C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004A130: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A134: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A138: slti        $at, $t6, -0x14
    ctx->r1 = SIGNED(ctx->r14) < -0X14 ? 1 : 0;
    // 0x8004A13C: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x8004A140: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8004A144: beq         $at, $zero, L_8004A150
    if (ctx->r1 == 0) {
        // 0x8004A148: cvt.s.d     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
            goto L_8004A150;
    }
    // 0x8004A148: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x8004A14C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_8004A150:
    // 0x8004A150: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x8004A154: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A158: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A15C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8004A160: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8004A164: bc1f        L_8004A174
    if (!c1cs) {
        // 0x8004A168: nop
    
            goto L_8004A174;
    }
    // 0x8004A168: nop

    // 0x8004A16C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A170: nop

L_8004A174:
    // 0x8004A174: sb          $t8, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = ctx->r24;
L_8004A178:
    // 0x8004A178: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A17C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A180: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A184: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8004A188: addiu       $t1, $t1, -0x2AC8
    ctx->r9 = ADD32(ctx->r9, -0X2AC8);
    // 0x8004A18C: bc1f        L_8004A198
    if (!c1cs) {
        // 0x8004A190: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8004A198;
    }
    // 0x8004A190: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8004A194: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8004A198:
    // 0x8004A198: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A19C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A1A0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004A1A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A1A8: bc1f        L_8004A1B4
    if (!c1cs) {
        // 0x8004A1AC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8004A1B4;
    }
    // 0x8004A1AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8004A1B0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8004A1B4:
    // 0x8004A1B4: add.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8004A1B8: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8004A1BC: nop

    // 0x8004A1C0: bc1f        L_8004A1D4
    if (!c1cs) {
        // 0x8004A1C4: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8004A1D4;
    }
    // 0x8004A1C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004A1C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A1CC: nop

    // 0x8004A1D0: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
L_8004A1D4:
    // 0x8004A1D4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8004A1D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A1DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A1E0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8004A1E4: nop

    // 0x8004A1E8: bc1f        L_8004A1F4
    if (!c1cs) {
        // 0x8004A1EC: nop
    
            goto L_8004A1F4;
    }
    // 0x8004A1EC: nop

    // 0x8004A1F0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8004A1F4:
    // 0x8004A1F4: lwc1        $f2, 0x64EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X64EC);
    // 0x8004A1F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A1FC: lwc1        $f12, 0x64F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F0);
    // 0x8004A200: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004A204: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A208: lwc1        $f16, 0x64F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64F4);
    // 0x8004A20C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004A210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A218: lw          $t3, -0x2A9C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2A9C);
    // 0x8004A21C: cvt.w.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8004A220: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A224: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8004A228: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004A22C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A230: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8004A234: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A238: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A23C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A240: sub.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8004A244: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8004A248: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A24C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004A250: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8004A254: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004A258: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A25C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8004A260: swc1        $f2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f2.u32l;
    // 0x8004A264: swc1        $f12, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f12.u32l;
    // 0x8004A268: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x8004A26C: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A270: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004A274: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A278: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x8004A27C: beq         $t5, $zero, L_8004A500
    if (ctx->r13 == 0) {
        // 0x8004A280: cvt.s.d     $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
            goto L_8004A500;
    }
    // 0x8004A280: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A284: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x8004A288: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    // 0x8004A28C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004A290: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004A294: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A298: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8004A29C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8004A2A0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8004A2A4:
    // 0x8004A2A4: lbu         $v0, 0x1DC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1DC);
    // 0x8004A2A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004A2AC: beq         $a0, $v0, L_8004A2C0
    if (ctx->r4 == ctx->r2) {
        // 0x8004A2B0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8004A2C0;
    }
    // 0x8004A2B0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004A2B4: beq         $at, $zero, L_8004A2C0
    if (ctx->r1 == 0) {
        // 0x8004A2B8: nop
    
            goto L_8004A2C0;
    }
    // 0x8004A2B8: nop

    // 0x8004A2BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8004A2C0:
    // 0x8004A2C0: bne         $t0, $a2, L_8004A2A4
    if (ctx->r8 != ctx->r6) {
        // 0x8004A2C4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004A2A4;
    }
    // 0x8004A2C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004A2C8: bne         $a1, $a2, L_8004A2D4
    if (ctx->r5 != ctx->r6) {
        // 0x8004A2CC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004A2D4;
    }
    // 0x8004A2CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004A2D0: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
L_8004A2D4:
    // 0x8004A2D4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004A2D8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004A2DC: bne         $t6, $zero, L_8004A304
    if (ctx->r14 != 0) {
        // 0x8004A2E0: nop
    
            goto L_8004A304;
    }
    // 0x8004A2E0: nop

    // 0x8004A2E4: bne         $a1, $at, L_8004A304
    if (ctx->r5 != ctx->r1) {
        // 0x8004A2E8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004A304;
    }
    // 0x8004A2E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004A2EC: lw          $t7, -0x2AD4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD4);
    // 0x8004A2F0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8004A2F4: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x8004A2F8: beq         $t8, $zero, L_8004A304
    if (ctx->r24 == 0) {
        // 0x8004A2FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004A304;
    }
    // 0x8004A2FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A300: sb          $t9, -0x2A7E($at)
    MEM_B(-0X2A7E, ctx->r1) = ctx->r25;
L_8004A304:
    // 0x8004A304: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x8004A308: nop

    // 0x8004A30C: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x8004A310: beq         $t4, $zero, L_8004A360
    if (ctx->r12 == 0) {
        // 0x8004A314: nop
    
            goto L_8004A360;
    }
    // 0x8004A314: nop

    // 0x8004A318: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8004A31C: nop

    // 0x8004A320: slti        $at, $t5, -0x28
    ctx->r1 = SIGNED(ctx->r13) < -0X28 ? 1 : 0;
    // 0x8004A324: bne         $at, $zero, L_8004A360
    if (ctx->r1 != 0) {
        // 0x8004A328: nop
    
            goto L_8004A360;
    }
    // 0x8004A328: nop

    // 0x8004A32C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A330: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004A334: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A338: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A33C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A340: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8004A344: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004A348: bc1f        L_8004A360
    if (!c1cs) {
        // 0x8004A34C: nop
    
            goto L_8004A360;
    }
    // 0x8004A34C: nop

    // 0x8004A350: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A354: nop

    // 0x8004A358: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8004A35C: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
L_8004A360:
    // 0x8004A360: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004A364: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A368: bne         $t6, $zero, L_8004A404
    if (ctx->r14 != 0) {
        // 0x8004A36C: nop
    
            goto L_8004A404;
    }
    // 0x8004A36C: nop

    // 0x8004A370: bne         $a1, $at, L_8004A404
    if (ctx->r5 != ctx->r1) {
        // 0x8004A374: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8004A404;
    }
    // 0x8004A374: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8004A378: swc1        $f1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x8004A37C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8004A380: jal         0x8000C8B4
    // 0x8004A384: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_14;
    // 0x8004A384: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x8004A388: lbu         $t8, 0x20C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004A38C: lwc1        $f1, 0x48($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8004A390: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004A394: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A398: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004A39C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004A3A0: beq         $t8, $zero, L_8004A3B8
    if (ctx->r24 == 0) {
        // 0x8004A3A4: sb          $t7, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r15;
            goto L_8004A3B8;
    }
    // 0x8004A3A4: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
    // 0x8004A3A8: lb          $t9, 0x203($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X203);
    // 0x8004A3AC: nop

    // 0x8004A3B0: ori         $t3, $t9, 0x4
    ctx->r11 = ctx->r25 | 0X4;
    // 0x8004A3B4: sb          $t3, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r11;
L_8004A3B8:
    // 0x8004A3B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A3BC: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x8004A3C0: swc1        $f1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x8004A3C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8004A3C8: jal         0x80057048
    // 0x8004A3CC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    racer_play_sound(rdram, ctx);
        goto after_15;
    // 0x8004A3CC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x8004A3D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A3D4: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004A3D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004A3DC: jal         0x800570B8
    // 0x8004A3E0: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_16;
    // 0x8004A3E0: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_16:
    // 0x8004A3E4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004A3E8: jal         0x80072348
    // 0x8004A3EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_17;
    // 0x8004A3EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x8004A3F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A3F4: lwc1        $f1, 0x48($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8004A3F8: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004A3FC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A400: addiu       $t1, $t1, -0x2AC8
    ctx->r9 = ADD32(ctx->r9, -0X2AC8);
L_8004A404:
    // 0x8004A404: lb          $t4, 0x1D6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A408: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004A40C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8004A410: bne         $at, $zero, L_8004A474
    if (ctx->r1 != 0) {
        // 0x8004A414: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8004A474;
    }
    // 0x8004A414: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004A418: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A41C: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x8004A420: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A424: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A428: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A42C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8004A430: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004A434: bc1f        L_8004A474
    if (!c1cs) {
        // 0x8004A438: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004A474;
    }
    // 0x8004A438: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A43C: lwc1        $f9, 0x64F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X64F8);
    // 0x8004A440: lwc1        $f8, 0x64FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64FC);
    // 0x8004A444: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A448: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8004A44C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A450: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004A454: lwc1        $f9, 0x6500($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6500);
    // 0x8004A458: lwc1        $f8, 0x6504($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6504);
    // 0x8004A45C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004A460: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A464: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8004A468: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x8004A46C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004A470: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
L_8004A474:
    // 0x8004A474: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004A478: lw          $t5, -0x2AD8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD8);
    // 0x8004A47C: nop

    // 0x8004A480: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x8004A484: beq         $t6, $zero, L_8004A4A4
    if (ctx->r14 == 0) {
        // 0x8004A488: nop
    
            goto L_8004A4A4;
    }
    // 0x8004A488: nop

    // 0x8004A48C: lw          $t7, -0x3468($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3468);
    // 0x8004A490: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004A494: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8004A498: beq         $at, $zero, L_8004A4A4
    if (ctx->r1 == 0) {
        // 0x8004A49C: nop
    
            goto L_8004A4A4;
    }
    // 0x8004A49C: nop

    // 0x8004A4A0: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_8004A4A4:
    // 0x8004A4A4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8004A4A8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A4AC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8004A4B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A4B4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004A4B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A4BC: nop

    // 0x8004A4C0: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x8004A4C4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8004A4C8: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8004A4CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8004A4D0: nop

    // 0x8004A4D4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8004A4D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A4DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A4E0: nop

    // 0x8004A4E4: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x8004A4E8: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8004A4EC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004A4F0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8004A4F4: blez        $t4, L_8004A504
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004A4F8: lb          $t5, 0xA3($sp)
        ctx->r13 = MEM_B(ctx->r29, 0XA3);
            goto L_8004A504;
    }
    // 0x8004A4F8: lb          $t5, 0xA3($sp)
    ctx->r13 = MEM_B(ctx->r29, 0XA3);
    // 0x8004A4FC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8004A500:
    // 0x8004A500: lb          $t5, 0xA3($sp)
    ctx->r13 = MEM_B(ctx->r29, 0XA3);
L_8004A504:
    // 0x8004A504: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A508: bne         $t5, $zero, L_8004A548
    if (ctx->r13 != 0) {
        // 0x8004A50C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8004A548;
    }
    // 0x8004A50C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004A510: lui         $at, 0x4590
    ctx->r1 = S32(0X4590 << 16);
    // 0x8004A514: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A518: nop

    // 0x8004A51C: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8004A520: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004A524: nop

    // 0x8004A528: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004A52C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A530: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A534: nop

    // 0x8004A538: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004A53C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004A540: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8004A544: nop

L_8004A548:
    // 0x8004A548: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004A54C: bne         $at, $zero, L_8004A558
    if (ctx->r1 != 0) {
        // 0x8004A550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004A558;
    }
    // 0x8004A550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004A554: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004A558:
    // 0x8004A558: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004A55C: bne         $v0, $at, L_8004A56C
    if (ctx->r2 != ctx->r1) {
        // 0x8004A560: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8004A56C;
    }
    // 0x8004A560: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A564: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004A568: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004A56C:
    // 0x8004A56C: sll         $a3, $t0, 16
    ctx->r7 = S32(ctx->r8 << 16);
    // 0x8004A570: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8004A574: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A578: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8004A57C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8004A580: jal         0x80050850
    // 0x8004A584: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_18;
    // 0x8004A584: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x8004A588: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004A58C: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A590: bne         $v0, $zero, L_8004A5B4
    if (ctx->r2 != 0) {
        // 0x8004A594: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004A5B4;
    }
    // 0x8004A594: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004A598: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8004A59C: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x8004A5A0: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x8004A5A4: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
    // 0x8004A5A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A5AC: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004A5B0: nop

L_8004A5B4:
    // 0x8004A5B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A5B8: bne         $v0, $at, L_8004A5C8
    if (ctx->r2 != ctx->r1) {
        // 0x8004A5BC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004A5C8;
    }
    // 0x8004A5BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A5C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A5C4: nop

L_8004A5C8:
    // 0x8004A5C8: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004A5CC: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8004A5D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A5D4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004A5D8: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8004A5DC: nop

    // 0x8004A5E0: bc1t        L_8004A668
    if (c1cs) {
        // 0x8004A5E4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8004A668;
    }
    // 0x8004A5E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004A5E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A5EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A5F0: addiu       $t3, $zero, -0x3C
    ctx->r11 = ADD32(0, -0X3C);
    // 0x8004A5F4: sw          $t3, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r11;
    // 0x8004A5F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004A5FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A600: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004A604: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8004A608: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8004A60C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A610: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8004A614: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8004A618: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004A61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A620: bc1f        L_8004A634
    if (!c1cs) {
        // 0x8004A624: nop
    
            goto L_8004A634;
    }
    // 0x8004A624: nop

    // 0x8004A628: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004A62C: nop

    // 0x8004A630: nop

L_8004A634:
    // 0x8004A634: div.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004A638: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8004A63C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004A640: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A644: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004A648: sub.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004A64C: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A650: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8004A654: nop

    // 0x8004A658: bc1f        L_8004A668
    if (!c1cs) {
        // 0x8004A65C: nop
    
            goto L_8004A668;
    }
    // 0x8004A65C: nop

    // 0x8004A660: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A664: nop

L_8004A668:
    // 0x8004A668: lw          $t4, -0x2AC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AC0);
    // 0x8004A66C: nop

    // 0x8004A670: beq         $t4, $zero, L_8004A680
    if (ctx->r12 == 0) {
        // 0x8004A674: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004A680;
    }
    // 0x8004A674: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004A678: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A67C: nop

L_8004A680:
    // 0x8004A680: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004A684: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004A688: bne         $t5, $at, L_8004A6B8
    if (ctx->r13 != ctx->r1) {
        // 0x8004A68C: nop
    
            goto L_8004A6B8;
    }
    // 0x8004A68C: nop

    // 0x8004A690: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8004A694: nop

    // 0x8004A698: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004A69C: beq         $at, $zero, L_8004A6B0
    if (ctx->r1 == 0) {
        // 0x8004A6A0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004A6B0;
    }
    // 0x8004A6A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A6A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A6A8: b           L_8004A6B8
    // 0x8004A6AC: nop

        goto L_8004A6B8;
    // 0x8004A6AC: nop

L_8004A6B0:
    // 0x8004A6B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004A6B4: nop

L_8004A6B8:
    // 0x8004A6B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A6BC: lwc1        $f10, -0x2A94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x8004A6C0: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004A6C4: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8004A6C8: sub.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x8004A6CC: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004A6D0: lbu         $t7, 0x1F5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004A6D4: nop

    // 0x8004A6D8: beq         $t7, $zero, L_8004A854
    if (ctx->r15 == 0) {
        // 0x8004A6DC: nop
    
            goto L_8004A854;
    }
    // 0x8004A6DC: nop

    // 0x8004A6E0: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004A6E4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004A6E8: bne         $t8, $zero, L_8004A854
    if (ctx->r24 != 0) {
        // 0x8004A6EC: nop
    
            goto L_8004A854;
    }
    // 0x8004A6EC: nop

    // 0x8004A6F0: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x8004A6F4: lh          $v1, 0x1A0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004A6F8: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x8004A6FC: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004A700: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004A704: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x8004A708: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x8004A70C: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x8004A710: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004A714: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A718: bne         $at, $zero, L_8004A728
    if (ctx->r1 != 0) {
        // 0x8004A71C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004A728;
    }
    // 0x8004A71C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004A720: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A724: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004A728:
    // 0x8004A728: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004A72C: beq         $at, $zero, L_8004A738
    if (ctx->r1 == 0) {
        // 0x8004A730: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004A738;
    }
    // 0x8004A730: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004A734: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004A738:
    // 0x8004A738: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004A73C: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x8004A740: mflo        $t6
    ctx->r14 = lo;
    // 0x8004A744: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8004A748: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8004A74C: beq         $at, $zero, L_8004A760
    if (ctx->r1 == 0) {
        // 0x8004A750: sh          $t8, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r24;
            goto L_8004A760;
    }
    // 0x8004A750: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    // 0x8004A754: slti        $at, $v0, -0x3FF
    ctx->r1 = SIGNED(ctx->r2) < -0X3FF ? 1 : 0;
    // 0x8004A758: beq         $at, $zero, L_8004A770
    if (ctx->r1 == 0) {
        // 0x8004A75C: nop
    
            goto L_8004A770;
    }
    // 0x8004A75C: nop

L_8004A760:
    // 0x8004A760: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004A764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A768: bne         $t9, $at, L_8004A804
    if (ctx->r25 != ctx->r1) {
        // 0x8004A76C: nop
    
            goto L_8004A804;
    }
    // 0x8004A76C: nop

L_8004A770:
    // 0x8004A770: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8004A774: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A778: beq         $t3, $at, L_8004A7B4
    if (ctx->r11 == ctx->r1) {
        // 0x8004A77C: addiu       $a0, $zero, 0x107
        ctx->r4 = ADD32(0, 0X107);
            goto L_8004A7B4;
    }
    // 0x8004A77C: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x8004A780: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004A784: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004A788: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004A78C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004A790: jal         0x80001EA8
    // 0x8004A794: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x8004A794: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
    // 0x8004A798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A79C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004A7A0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004A7A4: jal         0x800570B8
    // 0x8004A7A8: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_20;
    // 0x8004A7A8: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_20:
    // 0x8004A7AC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A7B0: nop

L_8004A7B4:
    // 0x8004A7B4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8004A7B8: jal         0x8000C8B4
    // 0x8004A7BC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_21;
    // 0x8004A7BC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_21:
    // 0x8004A7C0: lbu         $t5, 0x20C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004A7C4: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A7C8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8004A7CC: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004A7D0: beq         $t5, $zero, L_8004A7E8
    if (ctx->r13 == 0) {
        // 0x8004A7D4: sb          $t4, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r12;
            goto L_8004A7E8;
    }
    // 0x8004A7D4: sb          $t4, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r12;
    // 0x8004A7D8: lb          $t6, 0x203($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X203);
    // 0x8004A7DC: nop

    // 0x8004A7E0: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8004A7E4: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
L_8004A7E8:
    // 0x8004A7E8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004A7EC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004A7F0: jal         0x80072348
    // 0x8004A7F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_22;
    // 0x8004A7F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_22:
    // 0x8004A7F8: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A7FC: b           L_8004A854
    // 0x8004A800: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
        goto L_8004A854;
    // 0x8004A800: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
L_8004A804:
    // 0x8004A804: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004A808: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8004A80C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004A810: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A814: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004A818: mul.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8004A81C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004A820: nop

    // 0x8004A824: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A828: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004A82C: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004A830: mul.d       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8004A834: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004A838: nop

    // 0x8004A83C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A840: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8004A844: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A848: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004A84C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8004A850: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
L_8004A854:
    // 0x8004A854: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004A858: nop

    // 0x8004A85C: beq         $t8, $zero, L_8004AA64
    if (ctx->r24 == 0) {
        // 0x8004A860: nop
    
            goto L_8004AA64;
    }
    // 0x8004A860: nop

    // 0x8004A864: lbu         $t9, 0x1F1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004A868: lh          $a0, 0x162($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X162);
    // 0x8004A86C: bne         $t9, $zero, L_8004A878
    if (ctx->r25 != 0) {
        // 0x8004A870: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004A878;
    }
    // 0x8004A870: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004A874: sb          $t3, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r11;
L_8004A878:
    // 0x8004A878: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A87C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004A880: bne         $t4, $zero, L_8004A898
    if (ctx->r12 != 0) {
        // 0x8004A884: nop
    
            goto L_8004A898;
    }
    // 0x8004A884: nop

    // 0x8004A888: lbu         $t5, 0x1F1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004A88C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A890: bne         $t5, $at, L_8004A928
    if (ctx->r13 != ctx->r1) {
        // 0x8004A894: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_8004A928;
    }
    // 0x8004A894: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004A898:
    // 0x8004A898: sb          $t6, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r14;
    // 0x8004A89C: lw          $v0, 0xF8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A8A0: lh          $t8, 0x162($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X162);
    // 0x8004A8A4: lh          $v1, 0x164($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X164);
    // 0x8004A8A8: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x8004A8AC: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8004A8B0: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x8004A8B4: sh          $t9, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r25;
    // 0x8004A8B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8004A8BC: blez        $t3, L_8004A8D4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004A8C0: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8004A8D4;
    }
    // 0x8004A8C0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004A8C4: bgtz        $t0, L_8004A8D8
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004A8C8: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_8004A8D8;
    }
    // 0x8004A8C8: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A8CC: b           L_8004A8DC
    // 0x8004A8D0: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
        goto L_8004A8DC;
    // 0x8004A8D0: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
L_8004A8D4:
    // 0x8004A8D4: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_8004A8D8:
    // 0x8004A8D8: sh          $t4, 0x164($s0)
    MEM_H(0X164, ctx->r16) = ctx->r12;
L_8004A8DC:
    // 0x8004A8DC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A8E0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8004A8E4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A8E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A8EC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A8F0: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8004A8F4: nop

    // 0x8004A8F8: bc1f        L_8004A918
    if (!c1cs) {
        // 0x8004A8FC: nop
    
            goto L_8004A918;
    }
    // 0x8004A8FC: nop

    // 0x8004A900: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A904: nop

    // 0x8004A908: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8004A90C: bne         $at, $zero, L_8004A918
    if (ctx->r1 != 0) {
        // 0x8004A910: nop
    
            goto L_8004A918;
    }
    // 0x8004A910: nop

    // 0x8004A914: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
L_8004A918:
    // 0x8004A918: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A91C: b           L_8004A93C
    // 0x8004A920: nop

        goto L_8004A93C;
    // 0x8004A920: nop

    // 0x8004A924: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004A928:
    // 0x8004A928: lh          $t6, 0x164($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X164);
    // 0x8004A92C: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x8004A930: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8004A934: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A938: sh          $t9, 0x164($s0)
    MEM_H(0X164, ctx->r16) = ctx->r25;
L_8004A93C:
    // 0x8004A93C: beq         $v1, $zero, L_8004A9C8
    if (ctx->r3 == 0) {
        // 0x8004A940: slti        $at, $a0, 0x6001
        ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
            goto L_8004A9C8;
    }
    // 0x8004A940: slti        $at, $a0, 0x6001
    ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
    // 0x8004A944: bne         $at, $zero, L_8004A960
    if (ctx->r1 != 0) {
        // 0x8004A948: slti        $at, $a0, -0x5FFF
        ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
            goto L_8004A960;
    }
    // 0x8004A948: slti        $at, $a0, -0x5FFF
    ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
    // 0x8004A94C: lh          $t3, 0x162($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X162);
    // 0x8004A950: nop

    // 0x8004A954: slti        $at, $t3, 0x6001
    ctx->r1 = SIGNED(ctx->r11) < 0X6001 ? 1 : 0;
    // 0x8004A958: bne         $at, $zero, L_8004A990
    if (ctx->r1 != 0) {
        // 0x8004A95C: slti        $at, $a0, -0x5FFF
        ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
            goto L_8004A990;
    }
    // 0x8004A95C: slti        $at, $a0, -0x5FFF
    ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
L_8004A960:
    // 0x8004A960: bne         $at, $zero, L_8004A97C
    if (ctx->r1 != 0) {
        // 0x8004A964: nop
    
            goto L_8004A97C;
    }
    // 0x8004A964: nop

    // 0x8004A968: lh          $t4, 0x162($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X162);
    // 0x8004A96C: nop

    // 0x8004A970: slti        $at, $t4, -0x5FFF
    ctx->r1 = SIGNED(ctx->r12) < -0X5FFF ? 1 : 0;
    // 0x8004A974: bne         $at, $zero, L_8004A990
    if (ctx->r1 != 0) {
        // 0x8004A978: nop
    
            goto L_8004A990;
    }
    // 0x8004A978: nop

L_8004A97C:
    // 0x8004A97C: blez        $a0, L_8004A9C8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004A980: nop
    
            goto L_8004A9C8;
    }
    // 0x8004A980: nop

    // 0x8004A984: lh          $t5, 0x162($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X162);
    // 0x8004A988: nop

    // 0x8004A98C: bgtz        $t5, L_8004A9C8
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004A990: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004A9C8;
    }
L_8004A990:
    // 0x8004A990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A994: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8004A998: jal         0x80057048
    // 0x8004A99C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    racer_play_sound(rdram, ctx);
        goto after_23;
    // 0x8004A99C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_23:
    // 0x8004A9A0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004A9A4: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A9A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A9AC: beq         $t7, $at, L_8004A9C8
    if (ctx->r15 == ctx->r1) {
        // 0x8004A9B0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8004A9C8;
    }
    // 0x8004A9B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004A9B4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004A9B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A9BC: lw          $t6, -0x2AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AF8);
    // 0x8004A9C0: nop

    // 0x8004A9C4: swc1        $f6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f6.u32l;
L_8004A9C8:
    // 0x8004A9C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004A9CC: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x8004A9D0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004A9D4: ori         $at, $at, 0x5FFF
    ctx->r1 = ctx->r1 | 0X5FFF;
    // 0x8004A9D8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8004A9DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A9E0: sw          $t9, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r25;
    // 0x8004A9E4: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A9E8: lb          $t3, 0x1DB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004A9EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004A9F0: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x8004A9F4: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
    // 0x8004A9F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004A9FC: lb          $t5, 0x1DB($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004AA00: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x8004AA04: bgtz        $t5, L_8004AA14
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004AA08: swc1        $f18, 0xB8($s0)
        MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
            goto L_8004AA14;
    }
    // 0x8004AA08: swc1        $f18, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
    // 0x8004AA0C: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004AA10: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004AA14:
    // 0x8004AA14: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004AA18: ori         $t6, $zero, 0xD800
    ctx->r14 = 0 | 0XD800;
    // 0x8004AA1C: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x8004AA20: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8004AA24: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004AA28: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004AA2C: bne         $at, $zero, L_8004AA3C
    if (ctx->r1 != 0) {
        // 0x8004AA30: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004AA3C;
    }
    // 0x8004AA30: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004AA34: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004AA38: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004AA3C:
    // 0x8004AA3C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004AA40: beq         $at, $zero, L_8004AA4C
    if (ctx->r1 == 0) {
        // 0x8004AA44: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004AA4C;
    }
    // 0x8004AA44: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004AA48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004AA4C:
    // 0x8004AA4C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AA50: mflo        $t8
    ctx->r24 = lo;
    // 0x8004AA54: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8004AA58: addu        $t3, $v1, $t9
    ctx->r11 = ADD32(ctx->r3, ctx->r25);
    // 0x8004AA5C: b           L_8004B32C
    // 0x8004AA60: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
        goto L_8004B32C;
    // 0x8004AA60: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
L_8004AA64:
    // 0x8004AA64: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004AA68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004AA6C: beq         $v0, $at, L_8004AA80
    if (ctx->r2 == ctx->r1) {
        // 0x8004AA70: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8004AA80;
    }
    // 0x8004AA70: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8004AA74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AA78: bne         $v0, $at, L_8004AB3C
    if (ctx->r2 != ctx->r1) {
        // 0x8004AA7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004AB3C;
    }
    // 0x8004AA7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8004AA80:
    // 0x8004AA80: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AA84: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8004AA88: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8004AA8C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AA90: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AA94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004AA98: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004AA9C: mflo        $t6
    ctx->r14 = lo;
    // 0x8004AAA0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8004AAA4: sh          $t7, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r15;
    // 0x8004AAA8: lwc1        $f4, 0x6508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6508);
    // 0x8004AAAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004AAB0: bne         $v0, $at, L_8004AAF8
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAB4: swc1        $f4, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
            goto L_8004AAF8;
    }
    // 0x8004AAB4: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x8004AAB8: blez        $v1, L_8004AAC4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004AABC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8004AAC4;
    }
    // 0x8004AABC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004AAC0: sb          $t8, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r24;
L_8004AAC4:
    // 0x8004AAC4: bgez        $t0, L_8004B32C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AAC8: nop
    
            goto L_8004B32C;
    }
    // 0x8004AAC8: nop

    // 0x8004AACC: lh          $t9, 0x1A4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AAD0: nop

    // 0x8004AAD4: bltz        $t9, L_8004B32C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8004AAD8: nop
    
            goto L_8004B32C;
    }
    // 0x8004AAD8: nop

    // 0x8004AADC: lb          $t3, 0x1D4($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AAE0: nop

    // 0x8004AAE4: beq         $t3, $zero, L_8004B32C
    if (ctx->r11 == 0) {
        // 0x8004AAE8: nop
    
            goto L_8004B32C;
    }
    // 0x8004AAE8: nop

    // 0x8004AAEC: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AAF0: b           L_8004B32C
    // 0x8004AAF4: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
        goto L_8004B32C;
    // 0x8004AAF4: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
L_8004AAF8:
    // 0x8004AAF8: bgez        $t0, L_8004AB04
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AAFC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8004AB04;
    }
    // 0x8004AAFC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004AB00: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
L_8004AB04:
    // 0x8004AB04: blez        $t0, L_8004B32C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004AB08: nop
    
            goto L_8004B32C;
    }
    // 0x8004AB08: nop

    // 0x8004AB0C: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AB10: nop

    // 0x8004AB14: bgtz        $t5, L_8004B32C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004AB18: nop
    
            goto L_8004B32C;
    }
    // 0x8004AB18: nop

    // 0x8004AB1C: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AB20: nop

    // 0x8004AB24: beq         $t6, $zero, L_8004B32C
    if (ctx->r14 == 0) {
        // 0x8004AB28: nop
    
            goto L_8004B32C;
    }
    // 0x8004AB28: nop

    // 0x8004AB2C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AB30: b           L_8004B32C
    // 0x8004AB34: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
        goto L_8004B32C;
    // 0x8004AB34: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
    // 0x8004AB38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8004AB3C:
    // 0x8004AB3C: beq         $v0, $at, L_8004AB4C
    if (ctx->r2 == ctx->r1) {
        // 0x8004AB40: addiu       $a1, $zero, -0x2
        ctx->r5 = ADD32(0, -0X2);
            goto L_8004AB4C;
    }
    // 0x8004AB40: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8004AB44: bne         $a1, $v0, L_8004AD74
    if (ctx->r5 != ctx->r2) {
        // 0x8004AB48: nop
    
            goto L_8004AD74;
    }
    // 0x8004AB48: nop

L_8004AB4C:
    // 0x8004AB4C: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004AB50: lb          $t7, 0x1D5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D5);
    // 0x8004AB54: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004AB58: bne         $t7, $zero, L_8004AB80
    if (ctx->r15 != 0) {
        // 0x8004AB5C: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8004AB80;
    }
    // 0x8004AB5C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004AB60: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8004AB64: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AB68: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8004AB6C: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x8004AB70: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AB74: mflo        $t3
    ctx->r11 = lo;
    // 0x8004AB78: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8004AB7C: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
L_8004AB80:
    // 0x8004AB80: lw          $t5, -0x2AD8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD8);
    // 0x8004AB84: nop

    // 0x8004AB88: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8004AB8C: bne         $t6, $zero, L_8004AB98
    if (ctx->r14 != 0) {
        // 0x8004AB90: nop
    
            goto L_8004AB98;
    }
    // 0x8004AB90: nop

    // 0x8004AB94: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004AB98:
    // 0x8004AB98: lb          $v0, 0x1D5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D5);
    // 0x8004AB9C: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8004ABA0: blez        $v0, L_8004ABB0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004ABA4: subu        $t8, $v0, $t7
        ctx->r24 = SUB32(ctx->r2, ctx->r15);
            goto L_8004ABB0;
    }
    // 0x8004ABA4: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8004ABA8: b           L_8004ABB4
    // 0x8004ABAC: sb          $t8, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r24;
        goto L_8004ABB4;
    // 0x8004ABAC: sb          $t8, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r24;
L_8004ABB0:
    // 0x8004ABB0: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004ABB4:
    // 0x8004ABB4: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004ABB8: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004ABBC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004ABC0: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004ABC4: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004ABC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004ABCC: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004ABD0: mflo        $t3
    ctx->r11 = lo;
    // 0x8004ABD4: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8004ABD8: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x8004ABDC: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004ABE0: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004ABE4: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004ABE8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004ABEC: nop

    // 0x8004ABF0: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004ABF4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004ABF8: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004ABFC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004AC00: nop

    // 0x8004AC04: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004AC08: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004AC0C: lb          $t6, 0x1E0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004AC10: nop

    // 0x8004AC14: bne         $t6, $at, L_8004ACC8
    if (ctx->r14 != ctx->r1) {
        // 0x8004AC18: nop
    
            goto L_8004ACC8;
    }
    // 0x8004AC18: nop

    // 0x8004AC1C: blez        $t0, L_8004AC28
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004AC20: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8004AC28;
    }
    // 0x8004AC20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004AC24: sb          $t7, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r15;
L_8004AC28:
    // 0x8004AC28: bgez        $t0, L_8004AC90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AC2C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004AC90;
    }
    // 0x8004AC2C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC30: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004AC34: nop

    // 0x8004AC38: bltz        $t8, L_8004AC90
    if (SIGNED(ctx->r24) < 0) {
        // 0x8004AC3C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004AC90;
    }
    // 0x8004AC3C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC40: lb          $t9, 0x1D4($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AC44: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004AC48: beq         $t9, $zero, L_8004AC90
    if (ctx->r25 == 0) {
        // 0x8004AC4C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004AC90;
    }
    // 0x8004AC4C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC50: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AC54: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004AC58: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004AC5C: jal         0x8000C8B4
    // 0x8004AC60: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_24;
    // 0x8004AC60: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    after_24:
    // 0x8004AC64: lbu         $t3, 0x20C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004AC68: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004AC6C: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004AC70: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004AC74: beq         $t3, $zero, L_8004AC8C
    if (ctx->r11 == 0) {
        // 0x8004AC78: sb          $zero, 0x203($s0)
        MEM_B(0X203, ctx->r16) = 0;
            goto L_8004AC8C;
    }
    // 0x8004AC78: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    // 0x8004AC7C: lb          $t4, 0x203($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X203);
    // 0x8004AC80: nop

    // 0x8004AC84: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8004AC88: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_8004AC8C:
    // 0x8004AC8C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
L_8004AC90:
    // 0x8004AC90: bne         $at, $zero, L_8004B32C
    if (ctx->r1 != 0) {
        // 0x8004AC94: nop
    
            goto L_8004B32C;
    }
    // 0x8004AC94: nop

    // 0x8004AC98: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8004AC9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004ACA0: slti        $at, $t6, -0x4000
    ctx->r1 = SIGNED(ctx->r14) < -0X4000 ? 1 : 0;
    // 0x8004ACA4: beq         $at, $zero, L_8004B32C
    if (ctx->r1 == 0) {
        // 0x8004ACA8: nop
    
            goto L_8004B32C;
    }
    // 0x8004ACA8: nop

    // 0x8004ACAC: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x8004ACB0: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8004ACB4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004ACB8: beq         $t8, $zero, L_8004B32C
    if (ctx->r24 == 0) {
        // 0x8004ACBC: nop
    
            goto L_8004B32C;
    }
    // 0x8004ACBC: nop

    // 0x8004ACC0: b           L_8004B32C
    // 0x8004ACC4: sb          $t9, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r25;
        goto L_8004B32C;
    // 0x8004ACC4: sb          $t9, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r25;
L_8004ACC8:
    // 0x8004ACC8: bgez        $t0, L_8004ACD4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004ACCC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004ACD4;
    }
    // 0x8004ACCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004ACD0: sb          $t3, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r11;
L_8004ACD4:
    // 0x8004ACD4: blez        $t0, L_8004AD3C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004ACD8: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD3C;
    }
    // 0x8004ACD8: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004ACDC: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x8004ACE0: nop

    // 0x8004ACE4: bgtz        $t4, L_8004AD3C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8004ACE8: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD3C;
    }
    // 0x8004ACE8: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004ACEC: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004ACF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004ACF4: beq         $t5, $zero, L_8004AD3C
    if (ctx->r13 == 0) {
        // 0x8004ACF8: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD3C;
    }
    // 0x8004ACF8: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004ACFC: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AD00: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004AD04: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004AD08: jal         0x8000C8B4
    // 0x8004AD0C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_25;
    // 0x8004AD0C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    after_25:
    // 0x8004AD10: lbu         $t6, 0x20C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004AD14: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004AD18: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004AD1C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004AD20: beq         $t6, $zero, L_8004AD38
    if (ctx->r14 == 0) {
        // 0x8004AD24: sb          $zero, 0x203($s0)
        MEM_B(0X203, ctx->r16) = 0;
            goto L_8004AD38;
    }
    // 0x8004AD24: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    // 0x8004AD28: lb          $t7, 0x203($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X203);
    // 0x8004AD2C: nop

    // 0x8004AD30: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8004AD34: sb          $t8, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r24;
L_8004AD38:
    // 0x8004AD38: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
L_8004AD3C:
    // 0x8004AD3C: beq         $at, $zero, L_8004B32C
    if (ctx->r1 == 0) {
        // 0x8004AD40: nop
    
            goto L_8004B32C;
    }
    // 0x8004AD40: nop

    // 0x8004AD44: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x8004AD48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004AD4C: slti        $at, $t9, 0x4001
    ctx->r1 = SIGNED(ctx->r25) < 0X4001 ? 1 : 0;
    // 0x8004AD50: bne         $at, $zero, L_8004B32C
    if (ctx->r1 != 0) {
        // 0x8004AD54: nop
    
            goto L_8004B32C;
    }
    // 0x8004AD54: nop

    // 0x8004AD58: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x8004AD5C: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8004AD60: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8004AD64: beq         $t4, $zero, L_8004B32C
    if (ctx->r12 == 0) {
        // 0x8004AD68: nop
    
            goto L_8004B32C;
    }
    // 0x8004AD68: nop

    // 0x8004AD6C: b           L_8004B32C
    // 0x8004AD70: sb          $t5, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r13;
        goto L_8004B32C;
    // 0x8004AD70: sb          $t5, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r13;
L_8004AD74:
    // 0x8004AD74: lb          $a0, 0x1E1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004AD78: sb          $zero, 0xA1($sp)
    MEM_B(0XA1, ctx->r29) = 0;
    // 0x8004AD7C: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004AD80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004AD84: beq         $v1, $zero, L_8004ADB4
    if (ctx->r3 == 0) {
        // 0x8004AD88: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_8004ADB4;
    }
    // 0x8004AD88: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8004AD8C: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x8004AD90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004AD94: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8004AD98: beq         $t6, $zero, L_8004ADA4
    if (ctx->r14 == 0) {
        // 0x8004AD9C: and         $t8, $v0, $at
        ctx->r24 = ctx->r2 & ctx->r1;
            goto L_8004ADA4;
    }
    // 0x8004AD9C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8004ADA0: sb          $t7, 0xA1($sp)
    MEM_B(0XA1, ctx->r29) = ctx->r15;
L_8004ADA4:
    // 0x8004ADA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004ADA8: sw          $t8, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r24;
    // 0x8004ADAC: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004ADB0: nop

L_8004ADB4:
    // 0x8004ADB4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004ADB8: beq         $at, $zero, L_8004AFC8
    if (ctx->r1 == 0) {
        // 0x8004ADBC: nop
    
            goto L_8004AFC8;
    }
    // 0x8004ADBC: nop

    // 0x8004ADC0: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004ADC4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8004ADC8: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x8004ADCC: bne         $at, $zero, L_8004ADEC
    if (ctx->r1 != 0) {
        // 0x8004ADD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004ADEC;
    }
    // 0x8004ADD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004ADD4: addiu       $a0, $v1, -0x3000
    ctx->r4 = ADD32(ctx->r3, -0X3000);
    // 0x8004ADD8: slti        $at, $a0, 0x1001
    ctx->r1 = SIGNED(ctx->r4) < 0X1001 ? 1 : 0;
    // 0x8004ADDC: bne         $at, $zero, L_8004AE10
    if (ctx->r1 != 0) {
        // 0x8004ADE0: nop
    
            goto L_8004AE10;
    }
    // 0x8004ADE0: nop

    // 0x8004ADE4: b           L_8004AE10
    // 0x8004ADE8: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
        goto L_8004AE10;
    // 0x8004ADE8: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
L_8004ADEC:
    // 0x8004ADEC: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x8004ADF0: beq         $at, $zero, L_8004AE10
    if (ctx->r1 == 0) {
        // 0x8004ADF4: nop
    
            goto L_8004AE10;
    }
    // 0x8004ADF4: nop

    // 0x8004ADF8: addiu       $a0, $v1, 0x3000
    ctx->r4 = ADD32(ctx->r3, 0X3000);
    // 0x8004ADFC: slti        $at, $a0, -0x1000
    ctx->r1 = SIGNED(ctx->r4) < -0X1000 ? 1 : 0;
    // 0x8004AE00: beq         $at, $zero, L_8004AE10
    if (ctx->r1 == 0) {
        // 0x8004AE04: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_8004AE10;
    }
    // 0x8004AE04: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004AE08: addiu       $a0, $zero, -0x1000
    ctx->r4 = ADD32(0, -0X1000);
    // 0x8004AE0C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_8004AE10:
    // 0x8004AE10: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004AE14: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8004AE18: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004AE1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004AE20: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004AE24: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004AE28: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004AE2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004AE30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004AE34: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x8004AE38: nop

    // 0x8004AE3C: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8004AE40: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004AE44: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8004AE48: sub.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d - ctx->f18.d;
    // 0x8004AE4C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004AE50: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8004AE54: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004AE58: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004AE5C: nop

    // 0x8004AE60: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004AE64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004AE68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004AE6C: nop

    // 0x8004AE70: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004AE74: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004AE78: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004AE7C: beq         $t4, $zero, L_8004AEB4
    if (ctx->r12 == 0) {
        // 0x8004AE80: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_8004AEB4;
    }
    // 0x8004AE80: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AE84: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x8004AE88: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8004AE8C: ori         $t6, $t5, 0xC0
    ctx->r14 = ctx->r13 | 0XC0;
    // 0x8004AE90: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
    // 0x8004AE94: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AE98: lh          $t4, 0x1A4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AE9C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEA0: mflo        $t9
    ctx->r25 = lo;
    // 0x8004AEA4: sra         $t3, $t9, 1
    ctx->r11 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004AEA8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8004AEAC: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004AEB0: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004AEB4:
    // 0x8004AEB4: lh          $t6, 0x1A4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AEB8: multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEBC: mflo        $t8
    ctx->r24 = lo;
    // 0x8004AEC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004AEC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8004AEC8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004AECC: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004AED0: subu        $t3, $t6, $t4
    ctx->r11 = SUB32(ctx->r14, ctx->r12);
    // 0x8004AED4: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x8004AED8: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AEDC: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AEE0: lbu         $t6, 0x1F5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004AEE4: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEE8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004AEEC: mflo        $t7
    ctx->r15 = lo;
    // 0x8004AEF0: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8004AEF4: subu        $t9, $v1, $t8
    ctx->r25 = SUB32(ctx->r3, ctx->r24);
    // 0x8004AEF8: bne         $t6, $zero, L_8004B054
    if (ctx->r14 != 0) {
        // 0x8004AEFC: sh          $t9, 0x1A4($s0)
        MEM_H(0X1A4, ctx->r16) = ctx->r25;
            goto L_8004B054;
    }
    // 0x8004AEFC: sh          $t9, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r25;
    // 0x8004AF00: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x8004AF04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AF08: beq         $t4, $at, L_8004AFA0
    if (ctx->r12 == ctx->r1) {
        // 0x8004AF0C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8004AFA0;
    }
    // 0x8004AF0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004AF10: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004AF14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004AF18: bne         $t3, $zero, L_8004AFA0
    if (ctx->r11 != 0) {
        // 0x8004AF1C: nop
    
            goto L_8004AFA0;
    }
    // 0x8004AF1C: nop

    // 0x8004AF20: lh          $t0, 0x1A4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AF24: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x8004AF28: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x8004AF2C: sra         $t5, $t0, 6
    ctx->r13 = S32(SIGNED(ctx->r8) >> 6);
    // 0x8004AF30: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x8004AF34: beq         $t7, $zero, L_8004AF4C
    if (ctx->r15 == 0) {
        // 0x8004AF38: or          $t0, $t5, $zero
        ctx->r8 = ctx->r13 | 0;
            goto L_8004AF4C;
    }
    // 0x8004AF38: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8004AF3C: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x8004AF40: beq         $t8, $zero, L_8004AF4C
    if (ctx->r24 == 0) {
        // 0x8004AF44: nop
    
            goto L_8004AF4C;
    }
    // 0x8004AF44: nop

    // 0x8004AF48: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
L_8004AF4C:
    // 0x8004AF4C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8004AF50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004AF54: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004AF58: lwc1        $f8, -0x2A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x8004AF5C: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AF60: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004AF64: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004AF68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004AF6C: nop

    // 0x8004AF70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004AF74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004AF78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004AF7C: nop

    // 0x8004AF80: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004AF84: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004AF88: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004AF8C: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AF90: mflo        $t7
    ctx->r15 = lo;
    // 0x8004AF94: subu        $t8, $t4, $t7
    ctx->r24 = SUB32(ctx->r12, ctx->r15);
    // 0x8004AF98: b           L_8004B054
    // 0x8004AF9C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
        goto L_8004B054;
    // 0x8004AF9C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
L_8004AFA0:
    // 0x8004AFA0: lw          $t0, -0x2ACC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2ACC);
    // 0x8004AFA4: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AFA8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004AFAC: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AFB0: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004AFB4: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8004AFB8: mflo        $t4
    ctx->r12 = lo;
    // 0x8004AFBC: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x8004AFC0: b           L_8004B054
    // 0x8004AFC4: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
        goto L_8004B054;
    // 0x8004AFC4: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
L_8004AFC8:
    // 0x8004AFC8: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AFCC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004AFD0: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8004AFD4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8004AFD8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004AFDC: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AFE0: bne         $at, $zero, L_8004AFF4
    if (ctx->r1 != 0) {
        // 0x8004AFE4: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_8004AFF4;
    }
    // 0x8004AFE4: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8004AFE8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004AFEC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004AFF0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004AFF4:
    // 0x8004AFF4: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004AFF8: beq         $at, $zero, L_8004B004
    if (ctx->r1 == 0) {
        // 0x8004AFFC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004B004;
    }
    // 0x8004AFFC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004B000: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004B004:
    // 0x8004B004: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B008: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004B00C: mflo        $t9
    ctx->r25 = lo;
    // 0x8004B010: sra         $t3, $t9, 4
    ctx->r11 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8004B014: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x8004B018: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004B01C: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x8004B020: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B024: andi        $t4, $t6, 0x10
    ctx->r12 = ctx->r14 & 0X10;
    // 0x8004B028: beq         $t4, $zero, L_8004B040
    if (ctx->r12 == 0) {
        // 0x8004B02C: nop
    
            goto L_8004B040;
    }
    // 0x8004B02C: nop

    // 0x8004B030: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8004B034: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8004B038: b           L_8004B040
    // 0x8004B03C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
        goto L_8004B040;
    // 0x8004B03C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
L_8004B040:
    // 0x8004B040: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B044: lh          $t7, 0x1A0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004B048: mflo        $t3
    ctx->r11 = lo;
    // 0x8004B04C: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x8004B050: sh          $t5, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r13;
L_8004B054:
    // 0x8004B054: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B058: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x8004B05C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004B060: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8004B064: beq         $t6, $zero, L_8004B08C
    if (ctx->r14 == 0) {
        // 0x8004B068: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8004B08C;
    }
    // 0x8004B068: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8004B06C: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B070: nop

    // 0x8004B074: beq         $t4, $zero, L_8004B08C
    if (ctx->r12 == 0) {
        // 0x8004B078: nop
    
            goto L_8004B08C;
    }
    // 0x8004B078: nop

    // 0x8004B07C: lbu         $t8, 0x1F5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004B080: nop

    // 0x8004B084: beq         $t8, $zero, L_8004B108
    if (ctx->r24 == 0) {
        // 0x8004B088: nop
    
            goto L_8004B108;
    }
    // 0x8004B088: nop

L_8004B08C:
    // 0x8004B08C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8004B090: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B094: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B098: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B09C: lwc1        $f5, 0x6510($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6510);
    // 0x8004B0A0: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B0A4: lwc1        $f4, 0x6514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6514);
    // 0x8004B0A8: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B0AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B0B0: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8004B0B4: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004B0B8: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B0BC: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B0C0: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B0C4: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B0C8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004B0CC: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004B0D0: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B0D4: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B0D8: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B0DC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B0E0: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004B0E4: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B0E8: nop

    // 0x8004B0EC: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B0F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B0F4: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8004B0F8: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x8004B0FC: nop

    // 0x8004B100: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8004B104: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8004B108:
    // 0x8004B108: lw          $t7, -0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA4);
    // 0x8004B10C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004B110: lw          $t0, -0x2AC8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC8);
    // 0x8004B114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B118: beq         $t7, $at, L_8004B138
    if (ctx->r15 == ctx->r1) {
        // 0x8004B11C: nop
    
            goto L_8004B138;
    }
    // 0x8004B11C: nop

    // 0x8004B120: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004B124: nop

    // 0x8004B128: bne         $t3, $zero, L_8004B138
    if (ctx->r11 != 0) {
        // 0x8004B12C: nop
    
            goto L_8004B138;
    }
    // 0x8004B12C: nop

    // 0x8004B130: lb          $t0, 0x1E8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E8);
    // 0x8004B134: nop

L_8004B138:
    // 0x8004B138: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B13C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004B140: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B144: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B148: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8004B14C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8004B150: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004B154: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B158: bc1f        L_8004B16C
    if (!c1cs) {
        // 0x8004B15C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004B16C;
    }
    // 0x8004B15C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B160: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B164: nop

    // 0x8004B168: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8004B16C:
    // 0x8004B16C: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x8004B170: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004B174: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B178: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x8004B17C: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B180: bc1f        L_8004B194
    if (!c1cs) {
        // 0x8004B184: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_8004B194;
    }
    // 0x8004B184: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8004B188: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B18C: nop

    // 0x8004B190: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8004B194:
    // 0x8004B194: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x8004B198: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004B19C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8004B1A0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x8004B1A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004B1A8: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B1AC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B1B0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004B1B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8004B1B8: nop

    // 0x8004B1BC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8004B1C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004B1C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004B1C8: nop

    // 0x8004B1CC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004B1D0: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8004B1D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8004B1D8: bne         $v0, $zero, L_8004B22C
    if (ctx->r2 != 0) {
        // 0x8004B1DC: nop
    
            goto L_8004B22C;
    }
    // 0x8004B1DC: nop

    // 0x8004B1E0: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004B1E4: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8004B1E8: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B1EC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004B1F0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8004B1F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004B1F8: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004B1FC: mflo        $t8
    ctx->r24 = lo;
    // 0x8004B200: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8004B204: subu        $t7, $v1, $t9
    ctx->r15 = SUB32(ctx->r3, ctx->r25);
    // 0x8004B208: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x8004B20C: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B210: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004B214: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B218: mflo        $t6
    ctx->r14 = lo;
    // 0x8004B21C: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8004B220: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x8004B224: b           L_8004B270
    // 0x8004B228: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
        goto L_8004B270;
    // 0x8004B228: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
L_8004B22C:
    // 0x8004B22C: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004B230: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8004B234: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B238: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x8004B23C: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x8004B240: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8004B244: mflo        $t5
    ctx->r13 = lo;
    // 0x8004B248: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004B24C: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x8004B250: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x8004B254: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B258: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x8004B25C: multu       $t4, $t9
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B260: mflo        $t7
    ctx->r15 = lo;
    // 0x8004B264: sra         $t3, $t7, 1
    ctx->r11 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8004B268: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x8004B26C: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_8004B270:
    // 0x8004B270: lb          $t8, 0x1EC($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1EC);
    // 0x8004B274: nop

    // 0x8004B278: beq         $t8, $zero, L_8004B32C
    if (ctx->r24 == 0) {
        // 0x8004B27C: nop
    
            goto L_8004B32C;
    }
    // 0x8004B27C: nop

    // 0x8004B280: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B284: sb          $zero, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = 0;
    // 0x8004B288: bne         $t4, $zero, L_8004B32C
    if (ctx->r12 != 0) {
        // 0x8004B28C: lui         $at, 0xC01A
        ctx->r1 = S32(0XC01A << 16);
            goto L_8004B32C;
    }
    // 0x8004B28C: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x8004B290: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B294: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B298: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B29C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004B2A0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004B2A4: nop

    // 0x8004B2A8: bc1f        L_8004B32C
    if (!c1cs) {
        // 0x8004B2AC: nop
    
            goto L_8004B32C;
    }
    // 0x8004B2AC: nop

    // 0x8004B2B0: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004B2B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B2B8: bne         $t9, $zero, L_8004B32C
    if (ctx->r25 != 0) {
        // 0x8004B2BC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004B32C;
    }
    // 0x8004B2BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004B2C0: lw          $v0, -0x2ACC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2ACC);
    // 0x8004B2C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8004B2C8: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8004B2CC: bne         $at, $zero, L_8004B2E4
    if (ctx->r1 != 0) {
        // 0x8004B2D0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8004B2E4;
    }
    // 0x8004B2D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004B2D4: sb          $t7, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r15;
    // 0x8004B2D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B2DC: lw          $v0, -0x2ACC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2ACC);
    // 0x8004B2E0: nop

L_8004B2E4:
    // 0x8004B2E4: slti        $at, $v0, -0x28
    ctx->r1 = SIGNED(ctx->r2) < -0X28 ? 1 : 0;
    // 0x8004B2E8: beq         $at, $zero, L_8004B2F4
    if (ctx->r1 == 0) {
        // 0x8004B2EC: nop
    
            goto L_8004B2F4;
    }
    // 0x8004B2EC: nop

    // 0x8004B2F0: sb          $t5, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r13;
L_8004B2F4:
    // 0x8004B2F4: lw          $t3, -0x2AC8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC8);
    // 0x8004B2F8: nop

    // 0x8004B2FC: slti        $at, $t3, 0x29
    ctx->r1 = SIGNED(ctx->r11) < 0X29 ? 1 : 0;
    // 0x8004B300: bne         $at, $zero, L_8004B310
    if (ctx->r1 != 0) {
        // 0x8004B304: nop
    
            goto L_8004B310;
    }
    // 0x8004B304: nop

    // 0x8004B308: b           L_8004B324
    // 0x8004B30C: sb          $a1, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r5;
        goto L_8004B324;
    // 0x8004B30C: sb          $a1, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r5;
L_8004B310:
    // 0x8004B310: lb          $t6, 0x1E0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B314: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8004B318: bne         $t6, $zero, L_8004B324
    if (ctx->r14 != 0) {
        // 0x8004B31C: nop
    
            goto L_8004B324;
    }
    // 0x8004B31C: nop

    // 0x8004B320: sb          $t8, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r24;
L_8004B324:
    // 0x8004B324: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x8004B328: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004B32C:
    // 0x8004B32C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004B330: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x8004B334: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B338: beq         $t4, $at, L_8004B378
    if (ctx->r12 == ctx->r1) {
        // 0x8004B33C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004B378;
    }
    // 0x8004B33C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004B340: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B348: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B34C: nop

    // 0x8004B350: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004B354: nop

    // 0x8004B358: bc1f        L_8004B37C
    if (!c1cs) {
        // 0x8004B35C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004B37C;
    }
    // 0x8004B35C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004B360: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x8004B364: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8004B368: andi        $t9, $v0, 0xC0
    ctx->r25 = ctx->r2 & 0XC0;
    // 0x8004B36C: beq         $t9, $at, L_8004B378
    if (ctx->r25 == ctx->r1) {
        // 0x8004B370: ori         $t7, $v0, 0xC
        ctx->r15 = ctx->r2 | 0XC;
            goto L_8004B378;
    }
    // 0x8004B370: ori         $t7, $v0, 0xC
    ctx->r15 = ctx->r2 | 0XC;
    // 0x8004B374: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_8004B378:
    // 0x8004B378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_8004B37C:
    // 0x8004B37C: jal         0x80057220
    // 0x8004B380: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_26;
    // 0x8004B380: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_26:
    // 0x8004B384: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004B388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B38C: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8004B390: lwc1        $f9, 0x6518($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6518);
    // 0x8004B394: lwc1        $f8, 0x651C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X651C);
    // 0x8004B398: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004B39C: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8004B3A0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004B3A4: blez        $v0, L_8004B3F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004B3A8: cvt.s.d     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
            goto L_8004B3F0;
    }
    // 0x8004B3A8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8004B3AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B3B0: lw          $t5, -0x2AC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC0);
    // 0x8004B3B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004B3B8: bne         $t5, $zero, L_8004B3F4
    if (ctx->r13 != 0) {
        // 0x8004B3BC: nop
    
            goto L_8004B3F4;
    }
    // 0x8004B3BC: nop

    // 0x8004B3C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B3C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B3C8: swc1        $f18, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f18.u32l;
    // 0x8004B3CC: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B3D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004B3D4: subu        $t6, $v0, $t3
    ctx->r14 = SUB32(ctx->r2, ctx->r11);
    // 0x8004B3D8: sb          $t6, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r14;
    // 0x8004B3DC: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8004B3E0: nop

    // 0x8004B3E4: ori         $t4, $t8, 0xC0
    ctx->r12 = ctx->r24 | 0XC0;
    // 0x8004B3E8: b           L_8004B3F4
    // 0x8004B3EC: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
        goto L_8004B3F4;
    // 0x8004B3EC: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
L_8004B3F0:
    // 0x8004B3F0: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
L_8004B3F4:
    // 0x8004B3F4: lbu         $t9, 0x1F5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004B3F8: nop

    // 0x8004B3FC: bne         $t9, $zero, L_8004B8A0
    if (ctx->r25 != 0) {
        // 0x8004B400: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004B8A0;
    }
    // 0x8004B400: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004B404: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x8004B408: nop

    // 0x8004B40C: bne         $t7, $zero, L_8004B8A0
    if (ctx->r15 != 0) {
        // 0x8004B410: nop
    
            goto L_8004B8A0;
    }
    // 0x8004B410: nop

    // 0x8004B414: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B418: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004B41C: bne         $t5, $zero, L_8004B45C
    if (ctx->r13 != 0) {
        // 0x8004B420: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B45C;
    }
    // 0x8004B420: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B424: lwc1        $f9, 0x6520($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6520);
    // 0x8004B428: lwc1        $f8, 0x6524($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6524);
    // 0x8004B42C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B430: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8004B434: nop

    // 0x8004B438: bc1f        L_8004B45C
    if (!c1cs) {
        // 0x8004B43C: nop
    
            goto L_8004B45C;
    }
    // 0x8004B43C: nop

    // 0x8004B440: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004B444: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B448: beq         $t3, $at, L_8004B45C
    if (ctx->r11 == ctx->r1) {
        // 0x8004B44C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B45C;
    }
    // 0x8004B44C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B450: lwc1        $f0, 0x6528($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6528);
    // 0x8004B454: nop

    // 0x8004B458: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
L_8004B45C:
    // 0x8004B45C: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004B460: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004B464: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8004B468: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B46C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B470: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004B474: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B478: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004B47C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004B480: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B484: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B488: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B48C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004B490: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004B494: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B498: nop

    // 0x8004B49C: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B4A0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B4A4: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004B4A8: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B4AC: nop

    // 0x8004B4B0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8004B4B4: beq         $at, $zero, L_8004B4F0
    if (ctx->r1 == 0) {
        // 0x8004B4B8: nop
    
            goto L_8004B4F0;
    }
    // 0x8004B4B8: nop

    // 0x8004B4BC: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B4C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004B4C4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004B4C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B4CC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004B4D0: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8004B4D4: nop

    // 0x8004B4D8: bc1t        L_8004B4F0
    if (c1cs) {
        // 0x8004B4DC: nop
    
            goto L_8004B4F0;
    }
    // 0x8004B4DC: nop

    // 0x8004B4E0: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004B4E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B4E8: bne         $t6, $at, L_8004B568
    if (ctx->r14 != ctx->r1) {
        // 0x8004B4EC: nop
    
            goto L_8004B568;
    }
    // 0x8004B4EC: nop

L_8004B4F0:
    // 0x8004B4F0: bne         $v1, $zero, L_8004B50C
    if (ctx->r3 != 0) {
        // 0x8004B4F4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004B50C;
    }
    // 0x8004B4F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B4F8: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004B4FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B500: nop

    // 0x8004B504: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004B508: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
L_8004B50C:
    // 0x8004B50C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B510: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B514: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004B518: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8004B51C: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004B520: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B524: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004B528: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B52C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B530: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004B534: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B538: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B53C: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B540: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B544: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004B548: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004B54C: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B550: nop

    // 0x8004B554: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B558: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004B55C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004B560: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B564: nop

L_8004B568:
    // 0x8004B568: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004B56C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004B570: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8004B574: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B578: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B57C: bc1f        L_8004B588
    if (!c1cs) {
        // 0x8004B580: nop
    
            goto L_8004B588;
    }
    // 0x8004B580: nop

    // 0x8004B584: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8004B588:
    // 0x8004B588: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8004B58C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8004B590: bc1f        L_8004B5C8
    if (!c1cs) {
        // 0x8004B594: nop
    
            goto L_8004B5C8;
    }
    // 0x8004B594: nop

    // 0x8004B598: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x8004B59C: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8004B5A0: andi        $t4, $t8, 0x8000
    ctx->r12 = ctx->r24 & 0X8000;
    // 0x8004B5A4: bne         $t4, $zero, L_8004B5C8
    if (ctx->r12 != 0) {
        // 0x8004B5A8: nop
    
            goto L_8004B5C8;
    }
    // 0x8004B5A8: nop

    // 0x8004B5AC: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004B5B0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004B5B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B5B8: nop

    // 0x8004B5BC: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004B5C0: b           L_8004B5D4
    // 0x8004B5C4: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
        goto L_8004B5D4;
    // 0x8004B5C4: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
L_8004B5C8:
    // 0x8004B5C8: mul.s       $f20, $f12, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8004B5CC: nop

    // 0x8004B5D0: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
L_8004B5D4:
    // 0x8004B5D4: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B5D8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B5DC: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B5E0: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8004B5E4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004B5E8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B5EC: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B5F0: mul.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B5F4: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8004B5F8: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004B5FC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B600: nop

    // 0x8004B604: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B608: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B60C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B610: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004B614: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004B618: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8004B61C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004B620: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004B624: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8004B628: mul.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004B62C: bc1f        L_8004B638
    if (!c1cs) {
        // 0x8004B630: nop
    
            goto L_8004B638;
    }
    // 0x8004B630: nop

    // 0x8004B634: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8004B638:
    // 0x8004B638: mul.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004B63C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B640: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B644: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B648: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8004B64C: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B650: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004B654: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8004B658: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B65C: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B660: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8004B664: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004B668: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B66C: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B670: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B674: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004B678: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004B67C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B680: nop

    // 0x8004B684: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B688: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004B68C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004B690: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B694: nop

    // 0x8004B698: beq         $v0, $at, L_8004B6A4
    if (ctx->r2 == ctx->r1) {
        // 0x8004B69C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8004B6A4;
    }
    // 0x8004B69C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B6A0: bne         $v0, $at, L_8004B7DC
    if (ctx->r2 != ctx->r1) {
        // 0x8004B6A4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B7DC;
    }
L_8004B6A4:
    // 0x8004B6A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B6A8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B6AC: lwc1        $f11, 0x6530($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6530);
    // 0x8004B6B0: lwc1        $f10, 0x6534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6534);
    // 0x8004B6B4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8004B6B8: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8004B6BC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004B6C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004B6C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B6C8: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B6CC: mul.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8004B6D0: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8004B6D4: jal         0x800707F8
    // 0x8004B6D8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_27;
    // 0x8004B6D8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_27:
    // 0x8004B6DC: lb          $t9, 0x1E0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B6E0: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B6E4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8004B6E8: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B6EC: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B6F0: nop

    // 0x8004B6F4: slti        $at, $v1, 0x4001
    ctx->r1 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
    // 0x8004B6F8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B6FC: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B700: beq         $at, $zero, L_8004B70C
    if (ctx->r1 == 0) {
        // 0x8004B704: slti        $at, $v1, -0x4000
        ctx->r1 = SIGNED(ctx->r3) < -0X4000 ? 1 : 0;
            goto L_8004B70C;
    }
    // 0x8004B704: slti        $at, $v1, -0x4000
    ctx->r1 = SIGNED(ctx->r3) < -0X4000 ? 1 : 0;
    // 0x8004B708: beq         $at, $zero, L_8004B720
    if (ctx->r1 == 0) {
        // 0x8004B70C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004B720;
    }
L_8004B70C:
    // 0x8004B70C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B714: nop

    // 0x8004B718: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8004B71C: nop

L_8004B720:
    // 0x8004B720: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B724: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B728: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B72C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B730: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8004B734: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B738: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B73C: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B740: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B744: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8004B748: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004B74C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B750: nop

    // 0x8004B754: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B758: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004B75C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004B760: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B764: jal         0x800707C4
    // 0x8004B768: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    sins_f(rdram, ctx);
        goto after_28;
    // 0x8004B768: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_28:
    // 0x8004B76C: lb          $t7, 0x1E0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B770: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B774: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8004B778: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B77C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004B780: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B784: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B788: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B78C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B790: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B794: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B798: mul.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8004B79C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B7A0: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B7A4: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B7A8: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B7AC: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8004B7B0: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004B7B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B7B8: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B7BC: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B7C0: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B7C4: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004B7C8: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B7CC: nop

    // 0x8004B7D0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B7D4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004B7D8: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
L_8004B7DC:
    // 0x8004B7DC: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8004B7E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B7E4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B7E8: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8004B7EC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004B7F0: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8004B7F4: mul.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004B7F8: bc1f        L_8004B804
    if (!c1cs) {
        // 0x8004B7FC: nop
    
            goto L_8004B804;
    }
    // 0x8004B7FC: nop

    // 0x8004B800: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8004B804:
    // 0x8004B804: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8004B808: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B80C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B810: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B814: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8004B818: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B81C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B820: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8004B824: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B828: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B82C: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004B830: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8004B834: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B838: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B83C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B840: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004B844: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004B848: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B84C: nop

    // 0x8004B850: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B854: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004B858: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004B85C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B860: lwc1        $f4, 0x653C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X653C);
    // 0x8004B864: lwc1        $f5, 0x6538($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6538);
    // 0x8004B868: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004B86C: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8004B870: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004B874: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004B878: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8004B87C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004B880: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x8004B884: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004B888: nop

    // 0x8004B88C: mul.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8004B890: sub.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f0.d - ctx->f18.d;
    // 0x8004B894: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004B898: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8004B89C: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
L_8004B8A0:
    // 0x8004B8A0: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B8A4: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8004B8A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B8AC: lw          $t5, -0x2AAC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AAC);
    // 0x8004B8B0: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004B8B4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004B8B8: subu        $t3, $t5, $v0
    ctx->r11 = SUB32(ctx->r13, ctx->r2);
    // 0x8004B8BC: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8004B8C0: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8004B8C4: sh          $t8, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r24;
    // 0x8004B8C8: lh          $t9, 0x1A2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004B8CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B8D0: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x8004B8D4: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x8004B8D8: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004B8DC: lw          $t5, -0x2AA8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AA8);
    // 0x8004B8E0: lh          $t4, 0x1A4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B8E4: subu        $t3, $t5, $v1
    ctx->r11 = SUB32(ctx->r13, ctx->r3);
    // 0x8004B8E8: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8004B8EC: addu        $t8, $v1, $t6
    ctx->r24 = ADD32(ctx->r3, ctx->r14);
    // 0x8004B8F0: sh          $t8, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r24;
    // 0x8004B8F4: lh          $t9, 0x1A6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004B8F8: nop

    // 0x8004B8FC: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x8004B900: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x8004B904: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8004B908: nop

    // 0x8004B90C: beq         $t5, $zero, L_8004B92C
    if (ctx->r13 == 0) {
        // 0x8004B910: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004B92C;
    }
    // 0x8004B910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004B914: lwc1        $f8, -0x2A88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A88);
    // 0x8004B918: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004B91C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B920: lwc1        $f6, -0x2A84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A84);
    // 0x8004B924: nop

    // 0x8004B928: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_8004B92C:
    // 0x8004B92C: lw          $t3, 0x148($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X148);
    // 0x8004B930: nop

    // 0x8004B934: bne         $t3, $zero, L_8004BABC
    if (ctx->r11 != 0) {
        // 0x8004B938: lw          $a2, 0xFC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XFC);
            goto L_8004BABC;
    }
    // 0x8004B938: lw          $a2, 0xFC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XFC);
    // 0x8004B93C: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004B940: lwc1        $f20, 0x1C($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B944: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B948: beq         $t6, $zero, L_8004B98C
    if (ctx->r14 == 0) {
        // 0x8004B94C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8004B98C;
    }
    // 0x8004B94C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004B950: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8004B954: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004B958: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004B95C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004B960: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B964: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8004B968: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004B96C: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8004B970: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8004B974: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x8004B978: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004B97C: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8004B980: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B984: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x8004B988: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_8004B98C:
    // 0x8004B98C: lb          $t8, -0x2A7C($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2A7C);
    // 0x8004B990: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004B994: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004B998: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004B99C: beq         $t8, $zero, L_8004BA48
    if (ctx->r24 == 0) {
        // 0x8004B9A0: nop
    
            goto L_8004BA48;
    }
    // 0x8004B9A0: nop

    // 0x8004B9A4: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004B9A8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004B9AC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004B9B0: bc1t        L_8004B9D0
    if (c1cs) {
        // 0x8004B9B4: nop
    
            goto L_8004B9D0;
    }
    // 0x8004B9B4: nop

    // 0x8004B9B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B9BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B9C0: nop

    // 0x8004B9C4: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004B9C8: nop

    // 0x8004B9CC: bc1f        L_8004B9EC
    if (!c1cs) {
        // 0x8004B9D0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B9EC;
    }
L_8004B9D0:
    // 0x8004B9D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B9D4: lwc1        $f19, 0x6540($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6540);
    // 0x8004B9D8: lwc1        $f18, 0x6544($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6544);
    // 0x8004B9DC: nop

    // 0x8004B9E0: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8004B9E4: b           L_8004B9F4
    // 0x8004B9E8: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
        goto L_8004B9F4;
    // 0x8004B9E8: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
L_8004B9EC:
    // 0x8004B9EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004B9F0: nop

L_8004B9F4:
    // 0x8004B9F4: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8004B9F8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004B9FC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004BA00: bc1t        L_8004BA20
    if (c1cs) {
        // 0x8004BA04: nop
    
            goto L_8004BA20;
    }
    // 0x8004BA04: nop

    // 0x8004BA08: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004BA0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004BA10: nop

    // 0x8004BA14: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8004BA18: nop

    // 0x8004BA1C: bc1f        L_8004BA3C
    if (!c1cs) {
        // 0x8004BA20: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004BA3C;
    }
L_8004BA20:
    // 0x8004BA20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004BA24: lwc1        $f7, 0x6548($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6548);
    // 0x8004BA28: lwc1        $f6, 0x654C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X654C);
    // 0x8004BA2C: nop

    // 0x8004BA30: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004BA34: b           L_8004BA58
    // 0x8004BA38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
        goto L_8004BA58;
    // 0x8004BA38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8004BA3C:
    // 0x8004BA3C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004BA40: b           L_8004BA5C
    // 0x8004BA44: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
        goto L_8004BA5C;
    // 0x8004BA44: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
L_8004BA48:
    // 0x8004BA48: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004BA4C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004BA50: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8004BA54: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_8004BA58:
    // 0x8004BA58: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
L_8004BA5C:
    // 0x8004BA5C: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004BA60: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004BA64: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    // 0x8004BA68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BA6C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004BA70: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004BA74: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004BA78: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8004BA7C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8004BA80: jal         0x80011570
    // 0x8004BA84: nop

    move_object(rdram, ctx);
        goto after_29;
    // 0x8004BA84: nop

    after_29:
    // 0x8004BA88: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BA8C: beq         $v0, $zero, L_8004BAA8
    if (ctx->r2 == 0) {
        // 0x8004BA90: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004BAA8;
    }
    // 0x8004BA90: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004BA94: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x8004BA98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BA9C: beq         $t4, $at, L_8004BAA8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BAA0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8004BAA8;
    }
    // 0x8004BAA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004BAA4: sb          $t9, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r25;
L_8004BAA8:
    // 0x8004BAA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004BAAC: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x8004BAB0: b           L_8004BAE0
    // 0x8004BAB4: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
        goto L_8004BAE0;
    // 0x8004BAB4: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BAB8: lw          $a2, 0xFC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XFC);
L_8004BABC:
    // 0x8004BABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BAC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BAC4: jal         0x80050754
    // 0x8004BAC8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    racer_approach_object(rdram, ctx);
        goto after_30;
    // 0x8004BAC8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_30:
    // 0x8004BACC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004BAD0: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x8004BAD4: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BAD8: nop

    // 0x8004BADC: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
L_8004BAE0:
    // 0x8004BAE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BAE4: bne         $v0, $at, L_8004BB44
    if (ctx->r2 != ctx->r1) {
        // 0x8004BAE8: lw          $a2, 0xF8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XF8);
            goto L_8004BB44;
    }
    // 0x8004BAE8: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BAEC: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004BAF0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8004BAF4: bne         $t7, $at, L_8004BB0C
    if (ctx->r15 != ctx->r1) {
        // 0x8004BAF8: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004BB0C;
    }
    // 0x8004BAF8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004BAFC: lw          $t5, -0x2AC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC0);
    // 0x8004BB00: nop

    // 0x8004BB04: beq         $t5, $zero, L_8004BB34
    if (ctx->r13 == 0) {
        // 0x8004BB08: nop
    
            goto L_8004BB34;
    }
    // 0x8004BB08: nop

L_8004BB0C:
    // 0x8004BB0C: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BB10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BB18: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8004BB1C: jal         0x80055A84
    // 0x8004BB20: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_31;
    // 0x8004BB20: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_31:
    // 0x8004BB24: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004BB28: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BB2C: b           L_8004BB64
    // 0x8004BB30: nop

        goto L_8004BB64;
    // 0x8004BB30: nop

L_8004BB34:
    // 0x8004BB34: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x8004BB38: b           L_8004BB64
    // 0x8004BB3C: sb          $zero, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = 0;
        goto L_8004BB64;
    // 0x8004BB3C: sb          $zero, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = 0;
    // 0x8004BB40: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
L_8004BB44:
    // 0x8004BB44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BB4C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8004BB50: jal         0x80054FD0
    // 0x8004BB54: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    func_80054FD0(rdram, ctx);
        goto after_32;
    // 0x8004BB54: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_32:
    // 0x8004BB58: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004BB5C: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BB60: nop

L_8004BB64:
    // 0x8004BB64: bne         $t0, $zero, L_8004BBBC
    if (ctx->r8 != 0) {
        // 0x8004BB68: nop
    
            goto L_8004BBBC;
    }
    // 0x8004BB68: nop

    // 0x8004BB6C: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BB70: nop

    // 0x8004BB74: beq         $t3, $zero, L_8004BBBC
    if (ctx->r11 == 0) {
        // 0x8004BB78: nop
    
            goto L_8004BBBC;
    }
    // 0x8004BB78: nop

    // 0x8004BB7C: lb          $t6, 0x1DB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004BB80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB84: beq         $t6, $zero, L_8004BBBC
    if (ctx->r14 == 0) {
        // 0x8004BB88: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_8004BBBC;
    }
    // 0x8004BB88: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8004BB8C: jal         0x80057048
    // 0x8004BB90: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    racer_play_sound(rdram, ctx);
        goto after_33;
    // 0x8004BB90: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_33:
    // 0x8004BB94: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8004BB98: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BB9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BBA0: beq         $t8, $at, L_8004BBBC
    if (ctx->r24 == ctx->r1) {
        // 0x8004BBA4: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004BBBC;
    }
    // 0x8004BBA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004BBA8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004BBAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BBB0: lw          $t4, -0x2AF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AF8);
    // 0x8004BBB4: nop

    // 0x8004BBB8: swc1        $f4, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f4.u32l;
L_8004BBBC:
    // 0x8004BBBC: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004BBC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004BBC4: beq         $v0, $zero, L_8004BBF4
    if (ctx->r2 == 0) {
        // 0x8004BBC8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8004BBF4;
    }
    // 0x8004BBC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BBCC: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BBD0: nop

    // 0x8004BBD4: subu        $t7, $v0, $t9
    ctx->r15 = SUB32(ctx->r2, ctx->r25);
    // 0x8004BBD8: sb          $t7, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r15;
    // 0x8004BBDC: lb          $t5, 0x1D2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004BBE0: nop

    // 0x8004BBE4: bgez        $t5, L_8004BC54
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004BBE8: nop
    
            goto L_8004BC54;
    }
    // 0x8004BBE8: nop

    // 0x8004BBEC: b           L_8004BC54
    // 0x8004BBF0: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_8004BC54;
    // 0x8004BBF0: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_8004BBF4:
    // 0x8004BBF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BBF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BBFC: lwc1        $f6, 0xFC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8004BC00: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004BC04: div.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004BC08: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8004BC0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004BC10: lwc1        $f8, -0x2AB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x8004BC14: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004BC18: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8004BC1C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004BC20: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004BC24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004BC28: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004BC2C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004BC30: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004BC34: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004BC38: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004BC3C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004BC40: lwc1        $f4, -0x2AB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x8004BC44: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004BC48: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004BC4C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004BC50: nop

L_8004BC54:
    // 0x8004BC54: lw          $t3, -0x2AC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC0);
    // 0x8004BC58: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004BC5C: bne         $t3, $at, L_8004BC74
    if (ctx->r11 != ctx->r1) {
        // 0x8004BC60: addiu       $a1, $a1, -0x2AF0
        ctx->r5 = ADD32(ctx->r5, -0X2AF0);
            goto L_8004BC74;
    }
    // 0x8004BC60: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x8004BC64: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8004BC68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BC6C: nop

    // 0x8004BC70: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
L_8004BC74:
    // 0x8004BC74: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8004BC78: swc1        $f20, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f20.u32l;
    // 0x8004BC7C: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x8004BC80: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x8004BC84: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8004BC88: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x8004BC8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004BC90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BC94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004BC98: negu        $t9, $t4
    ctx->r25 = SUB32(0, ctx->r12);
    // 0x8004BC9C: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x8004BCA0: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004BCA4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8004BCA8: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCAC: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCB0: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCB4: jal         0x8006FE74
    // 0x8004BCB8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_34;
    // 0x8004BCB8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_34:
    // 0x8004BCBC: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8004BCC0: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8004BCC4: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8004BCC8: addiu       $t7, $s0, 0x30
    ctx->r15 = ADD32(ctx->r16, 0X30);
    // 0x8004BCCC: addiu       $t5, $s0, 0x34
    ctx->r13 = ADD32(ctx->r16, 0X34);
    // 0x8004BCD0: addiu       $t3, $s0, 0x2C
    ctx->r11 = ADD32(ctx->r16, 0X2C);
    // 0x8004BCD4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8004BCD8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004BCDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8004BCE0: jal         0x8006F64C
    // 0x8004BCE4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtxf_transform_point(rdram, ctx);
        goto after_35;
    // 0x8004BCE4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_35:
    // 0x8004BCE8: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x8004BCEC: nop

    // 0x8004BCF0: beq         $v1, $zero, L_8004BD40
    if (ctx->r3 == 0) {
        // 0x8004BCF4: nop
    
            goto L_8004BD40;
    }
    // 0x8004BCF4: nop

    // 0x8004BCF8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BCFC: nop

    // 0x8004BD00: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004BD04: bne         $at, $zero, L_8004BD40
    if (ctx->r1 != 0) {
        // 0x8004BD08: nop
    
            goto L_8004BD40;
    }
    // 0x8004BD08: nop

    // 0x8004BD0C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8004BD10: addiu       $t8, $zero, 0x4000
    ctx->r24 = ADD32(0, 0X4000);
    // 0x8004BD14: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x8004BD18: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x8004BD1C: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8004BD20: sb          $t9, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r25;
    // 0x8004BD24: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8004BD28: lb          $t3, 0x3A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3A);
    // 0x8004BD2C: lb          $t5, 0x55($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X55);
    // 0x8004BD30: nop

    // 0x8004BD34: bne         $t5, $t3, L_8004BD40
    if (ctx->r13 != ctx->r11) {
        // 0x8004BD38: nop
    
            goto L_8004BD40;
    }
    // 0x8004BD38: nop

    // 0x8004BD3C: sb          $zero, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = 0;
L_8004BD40:
    // 0x8004BD40: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x8004BD44: nop

    // 0x8004BD48: beq         $v1, $zero, L_8004BEC8
    if (ctx->r3 == 0) {
        // 0x8004BD4C: nop
    
            goto L_8004BEC8;
    }
    // 0x8004BD4C: nop

    // 0x8004BD50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BD54: nop

    // 0x8004BD58: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004BD5C: bne         $at, $zero, L_8004BEC8
    if (ctx->r1 != 0) {
        // 0x8004BD60: nop
    
            goto L_8004BEC8;
    }
    // 0x8004BD60: nop

    // 0x8004BD64: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BD68: lb          $t4, 0xA2($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA2);
    // 0x8004BD6C: bne         $t8, $zero, L_8004BD7C
    if (ctx->r24 != 0) {
        // 0x8004BD70: nop
    
            goto L_8004BD7C;
    }
    // 0x8004BD70: nop

    // 0x8004BD74: beq         $t4, $zero, L_8004BE38
    if (ctx->r12 == 0) {
        // 0x8004BD78: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8004BE38;
    }
    // 0x8004BD78: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8004BD7C:
    // 0x8004BD7C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8004BD80: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004BD84: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BD88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004BD8C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8004BD90: nop

    // 0x8004BD94: bc1f        L_8004BDB8
    if (!c1cs) {
        // 0x8004BD98: nop
    
            goto L_8004BDB8;
    }
    // 0x8004BD98: nop

    // 0x8004BD9C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004BDA0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004BDA4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004BDA8: sub.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d - ctx->f8.d;
    // 0x8004BDAC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004BDB0: b           L_8004BDC4
    // 0x8004BDB4: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
        goto L_8004BDC4;
    // 0x8004BDB4: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
L_8004BDB8:
    // 0x8004BDB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004BDBC: nop

    // 0x8004BDC0: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
L_8004BDC4:
    // 0x8004BDC4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8004BDC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004BDCC: andi        $t7, $t9, 0xBFFF
    ctx->r15 = ctx->r25 & 0XBFFF;
    // 0x8004BDD0: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8004BDD4: lw          $t5, 0x60($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X60);
    // 0x8004BDD8: addiu       $v1, $zero, -0x4001
    ctx->r3 = ADD32(0, -0X4001);
    // 0x8004BDDC: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x8004BDE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004BDE4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BDE8: nop

    // 0x8004BDEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004BDF0: nop

    // 0x8004BDF4: bc1f        L_8004BE18
    if (!c1cs) {
        // 0x8004BDF8: nop
    
            goto L_8004BE18;
    }
    // 0x8004BDF8: nop

    // 0x8004BDFC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004BE00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004BE04: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004BE08: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x8004BE0C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8004BE10: b           L_8004BE24
    // 0x8004BE14: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
        goto L_8004BE24;
    // 0x8004BE14: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
L_8004BE18:
    // 0x8004BE18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004BE1C: nop

    // 0x8004BE20: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
L_8004BE24:
    // 0x8004BE24: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8004BE28: nop

    // 0x8004BE2C: and         $t6, $t3, $v1
    ctx->r14 = ctx->r11 & ctx->r3;
    // 0x8004BE30: b           L_8004BEC8
    // 0x8004BE34: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
        goto L_8004BEC8;
    // 0x8004BE34: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
L_8004BE38:
    // 0x8004BE38: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8004BE3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BE40: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BE44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BE48: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004BE4C: nop

    // 0x8004BE50: bc1f        L_8004BE6C
    if (!c1cs) {
        // 0x8004BE54: nop
    
            goto L_8004BE6C;
    }
    // 0x8004BE54: nop

    // 0x8004BE58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BE5C: nop

    // 0x8004BE60: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004BE64: b           L_8004BE7C
    // 0x8004BE68: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
        goto L_8004BE7C;
    // 0x8004BE68: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
L_8004BE6C:
    // 0x8004BE6C: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8004BE70: nop

    // 0x8004BE74: ori         $t4, $t8, 0x4000
    ctx->r12 = ctx->r24 | 0X4000;
    // 0x8004BE78: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
L_8004BE7C:
    // 0x8004BE7C: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x8004BE80: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004BE84: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004BE88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004BE8C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BE90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BE94: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004BE98: nop

    // 0x8004BE9C: bc1f        L_8004BEB8
    if (!c1cs) {
        // 0x8004BEA0: nop
    
            goto L_8004BEB8;
    }
    // 0x8004BEA0: nop

    // 0x8004BEA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BEA8: nop

    // 0x8004BEAC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004BEB0: b           L_8004BEC8
    // 0x8004BEB4: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
        goto L_8004BEC8;
    // 0x8004BEB4: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
L_8004BEB8:
    // 0x8004BEB8: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8004BEBC: nop

    // 0x8004BEC0: ori         $t5, $t7, 0x4000
    ctx->r13 = ctx->r15 | 0X4000;
    // 0x8004BEC4: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
L_8004BEC8:
    // 0x8004BEC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004BECC: lw          $t3, -0x2AA4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AA4);
    // 0x8004BED0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BED4: beq         $t3, $at, L_8004BFF0
    if (ctx->r11 == ctx->r1) {
        // 0x8004BED8: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BED8: nop

    // 0x8004BEDC: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004BEE0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004BEE4: bne         $t6, $zero, L_8004BFF0
    if (ctx->r14 != 0) {
        // 0x8004BEE8: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BEE8: nop

    // 0x8004BEEC: lw          $t8, -0x3468($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3468);
    // 0x8004BEF0: nop

    // 0x8004BEF4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8004BEF8: beq         $at, $zero, L_8004BFF0
    if (ctx->r1 == 0) {
        // 0x8004BEFC: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BEFC: nop

    // 0x8004BF00: jal         0x8001E29C
    // 0x8004BF04: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_36;
    // 0x8004BF04: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_36:
    // 0x8004BF08: lb          $t0, 0x203($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X203);
    // 0x8004BF0C: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x8004BF10: andi        $t7, $t0, 0x4
    ctx->r15 = ctx->r8 & 0X4;
    // 0x8004BF14: sra         $t5, $t7, 2
    ctx->r13 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8004BF18: addiu       $t0, $t5, 0x9
    ctx->r8 = ADD32(ctx->r13, 0X9);
    // 0x8004BF1C: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8004BF20: sll         $t9, $t4, 7
    ctx->r25 = S32(ctx->r12 << 7);
    // 0x8004BF24: bne         $at, $zero, L_8004BF70
    if (ctx->r1 != 0) {
        // 0x8004BF28: addu        $v1, $t9, $v0
        ctx->r3 = ADD32(ctx->r25, ctx->r2);
            goto L_8004BF70;
    }
    // 0x8004BF28: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8004BF2C: lbu         $t3, 0x70($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X70);
    // 0x8004BF30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004BF34: bgtz        $t3, L_8004BF5C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8004BF38: nop
    
            goto L_8004BF5C;
    }
    // 0x8004BF38: nop

    // 0x8004BF3C: lwc1        $f10, 0x74($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004BF40: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004BF44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004BF48: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004BF4C: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8004BF50: nop

    // 0x8004BF54: bc1f        L_8004BFF0
    if (!c1cs) {
        // 0x8004BF58: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BF58: nop

L_8004BF5C:
    // 0x8004BF5C: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8004BF60: sllv        $t4, $t8, $t0
    ctx->r12 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x8004BF64: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x8004BF68: b           L_8004BFF0
    // 0x8004BF6C: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
        goto L_8004BFF0;
    // 0x8004BF6C: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
L_8004BF70:
    // 0x8004BF70: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8004BF74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004BF78: bne         $v0, $at, L_8004BFBC
    if (ctx->r2 != ctx->r1) {
        // 0x8004BF7C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8004BFBC;
    }
    // 0x8004BF7C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004BF80: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004BF84: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004BF88: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004BF8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004BF90: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004BF94: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004BF98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004BF9C: bc1f        L_8004BFBC
    if (!c1cs) {
        // 0x8004BFA0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8004BFBC;
    }
    // 0x8004BFA0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004BFA4: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8004BFA8: sllv        $t3, $t5, $t0
    ctx->r11 = S32(ctx->r13 << (ctx->r8 & 31));
    // 0x8004BFAC: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8004BFB0: b           L_8004BFF0
    // 0x8004BFB4: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_8004BFF0;
    // 0x8004BFB4: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
    // 0x8004BFB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004BFBC:
    // 0x8004BFBC: beq         $at, $zero, L_8004BFF0
    if (ctx->r1 == 0) {
        // 0x8004BFC0: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BFC0: nop

    // 0x8004BFC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004BFC8: lwc1        $f18, 0x74($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004BFCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004BFD0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8004BFD4: nop

    // 0x8004BFD8: bc1f        L_8004BFF0
    if (!c1cs) {
        // 0x8004BFDC: nop
    
            goto L_8004BFF0;
    }
    // 0x8004BFDC: nop

    // 0x8004BFE0: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8004BFE4: sllv        $t9, $t4, $t0
    ctx->r25 = S32(ctx->r12 << (ctx->r8 & 31));
    // 0x8004BFE8: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x8004BFEC: sw          $t5, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r13;
L_8004BFF0:
    // 0x8004BFF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004BFF4: lw          $t7, -0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA4);
    // 0x8004BFF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BFFC: bne         $t7, $at, L_8004C008
    if (ctx->r15 != ctx->r1) {
        // 0x8004C000: nop
    
            goto L_8004C008;
    }
    // 0x8004C000: nop

    // 0x8004C004: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_8004C008:
    // 0x8004C008: lb          $t3, 0x201($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X201);
    // 0x8004C00C: nop

    // 0x8004C010: bne         $t3, $zero, L_8004C01C
    if (ctx->r11 != 0) {
        // 0x8004C014: nop
    
            goto L_8004C01C;
    }
    // 0x8004C014: nop

    // 0x8004C018: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_8004C01C:
    // 0x8004C01C: lb          $t8, 0x1D7($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004C020: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x8004C024: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8004C028: beq         $at, $zero, L_8004C03C
    if (ctx->r1 == 0) {
        // 0x8004C02C: lb          $t4, 0xA1($sp)
        ctx->r12 = MEM_B(ctx->r29, 0XA1);
            goto L_8004C03C;
    }
    // 0x8004C02C: lb          $t4, 0xA1($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA1);
    // 0x8004C030: jal         0x800AF714
    // 0x8004C034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_37;
    // 0x8004C034: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x8004C038: lb          $t4, 0xA1($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA1);
L_8004C03C:
    // 0x8004C03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C040: beq         $t4, $zero, L_8004C060
    if (ctx->r12 == 0) {
        // 0x8004C044: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004C060;
    }
    // 0x8004C044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004C048: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004C04C: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x8004C050: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004C054: nop

    // 0x8004C058: ori         $t9, $t6, 0x10
    ctx->r25 = ctx->r14 | 0X10;
    // 0x8004C05C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8004C060:
    // 0x8004C060: lw          $a3, 0xFC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XFC);
    // 0x8004C064: jal         0x800580B4
    // 0x8004C068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    second_racer_camera_update(rdram, ctx);
        goto after_38;
    // 0x8004C068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x8004C06C: lb          $t5, 0x5F($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5F);
    // 0x8004C070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C074: beq         $t5, $zero, L_8004C088
    if (ctx->r13 == 0) {
        // 0x8004C078: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8004C088;
    }
    // 0x8004C078: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004C07C: jal         0x800230D0
    // 0x8004C080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_39;
    // 0x8004C080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_39:
    // 0x8004C084: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8004C088:
    // 0x8004C088: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8004C08C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004C090: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8004C094: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8004C098: jr          $ra
    // 0x8004C09C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x8004C09C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80063A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063A9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063AA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063AA4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063AA8: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063AAC: addiu       $t8, $zero, 0x5F
    ctx->r24 = ADD32(0, 0X5F);
    // 0x80063AB0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063AB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063AB8: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063ABC: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063AC0: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063AC4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063AC8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063ACC: jal         0x800C91AC
    // 0x80063AD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063AD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063AD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063ADC: jr          $ra
    // 0x80063AE0: nop

    return;
    // 0x80063AE0: nop

;}
RECOMP_FUNC void drm_validate_dmem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006EFBC: jr          $ra
    // 0x8006EFC0: nop

    return;
    // 0x8006EFC0: nop

    // 0x8006EFC4: beq         $t7, $at, L_8006EFD4
    if (ctx->r15 == ctx->r1) {
        // 0x8006EFC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006EFD4;
    }
    // 0x8006EFC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006EFCC: jr          $ra
    // 0x8006EFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006EFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006EFD4:
    // 0x8006EFD4: jr          $ra
    // 0x8006EFD8: nop

    return;
    // 0x8006EFD8: nop

;}
RECOMP_FUNC void func_80073588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073588: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007358C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80073590: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x80073594: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80073598: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007359C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800735A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800735A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800735A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800735AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800735B0: jal         0x8006E770
    // 0x800735B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x800735B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800735B8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800735BC: jal         0x8006B224
    // 0x800735C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    level_count(rdram, ctx);
        goto after_1;
    // 0x800735C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x800735C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800735C8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800735CC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800735D0: beq         $t8, $zero, L_80073724
    if (ctx->r24 == 0) {
        // 0x800735D4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80073724;
    }
    // 0x800735D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800735D8: sw          $t9, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r25;
    // 0x800735DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800735E0: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x800735E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800735E8: sw          $zero, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = 0;
    // 0x800735EC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800735F0: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x800735F4: addiu       $v0, $t9, 0x2
    ctx->r2 = ADD32(ctx->r25, 0X2);
L_800735F8:
    // 0x800735F8: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800735FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073600: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x80073604: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073608: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x8007360C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073610: bne         $at, $zero, L_800735F8
    if (ctx->r1 != 0) {
        // 0x80073614: sra         $s0, $t1, 16
        ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
            goto L_800735F8;
    }
    // 0x80073614: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073618: jal         0x80072C54
    // 0x8007361C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_2;
    // 0x8007361C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80073620: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80073624: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80073628: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8007362C: bne         $t4, $zero, L_80073728
    if (ctx->r12 != 0) {
        // 0x80073630: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073728;
    }
    // 0x80073630: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80073634: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80073638: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007363C: blez        $t5, L_80073728
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80073640: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073728;
    }
    // 0x80073640: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80073644:
    // 0x80073644: jal         0x8006B14C
    // 0x80073648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x80073648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8007364C: bne         $v0, $zero, L_80073714
    if (ctx->r2 != 0) {
        // 0x80073650: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_80073714;
    }
    // 0x80073650: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80073654: jal         0x8006B0F8
    // 0x80073658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_4;
    // 0x80073658: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8007365C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80073660: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80073664: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80073668: beq         $t9, $zero, L_800736A0
    if (ctx->r25 == 0) {
        // 0x8007366C: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_800736A0;
    }
    // 0x8007366C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80073670: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073674: jal         0x80072C54
    // 0x80073678: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_5;
    // 0x80073678: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_5:
    // 0x8007367C: lw          $t0, 0x24($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X24);
    // 0x80073680: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073684: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80073688: jal         0x80072C54
    // 0x8007368C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_6;
    // 0x8007368C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_6:
    // 0x80073690: lw          $t2, 0x18($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X18);
    // 0x80073694: nop

    // 0x80073698: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8007369C: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_800736A0:
    // 0x800736A0: andi        $t4, $s2, 0x2
    ctx->r12 = ctx->r18 & 0X2;
    // 0x800736A4: beq         $t4, $zero, L_800736D8
    if (ctx->r12 == 0) {
        // 0x800736A8: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_800736D8;
    }
    // 0x800736A8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736AC: jal         0x80072C54
    // 0x800736B0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_7;
    // 0x800736B0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_7:
    // 0x800736B4: lw          $t5, 0x28($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X28);
    // 0x800736B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736BC: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800736C0: jal         0x80072C54
    // 0x800736C4: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_8;
    // 0x800736C4: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    after_8:
    // 0x800736C8: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x800736CC: nop

    // 0x800736D0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800736D4: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
L_800736D8:
    // 0x800736D8: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x800736DC: beq         $t9, $zero, L_80073710
    if (ctx->r25 == 0) {
        // 0x800736E0: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073710;
    }
    // 0x800736E0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736E4: jal         0x80072C54
    // 0x800736E8: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_9;
    // 0x800736E8: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_9:
    // 0x800736EC: lw          $t0, 0x2C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C);
    // 0x800736F0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800736F4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800736F8: jal         0x80072C54
    // 0x800736FC: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_10;
    // 0x800736FC: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_10:
    // 0x80073700: lw          $t2, 0x20($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X20);
    // 0x80073704: nop

    // 0x80073708: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8007370C: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_80073710:
    // 0x80073710: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_80073714:
    // 0x80073714: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073718: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007371C: bne         $at, $zero, L_80073644
    if (ctx->r1 != 0) {
        // 0x80073720: nop
    
            goto L_80073644;
    }
    // 0x80073720: nop

L_80073724:
    // 0x80073724: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80073728:
    // 0x80073728: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007372C: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80073730: beq         $t6, $zero, L_80073888
    if (ctx->r14 == 0) {
        // 0x80073734: addiu       $t8, $t7, 0xC0
        ctx->r24 = ADD32(ctx->r15, 0XC0);
            goto L_80073888;
    }
    // 0x80073734: addiu       $t8, $t7, 0xC0
    ctx->r24 = ADD32(ctx->r15, 0XC0);
    // 0x80073738: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007373C: sw          $t8, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r24;
    // 0x80073740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073744: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007374C: sw          $zero, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = 0;
    // 0x80073750: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073754: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80073758: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_8007375C:
    // 0x8007375C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80073760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073764: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80073768: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x8007376C: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x80073770: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073774: bne         $at, $zero, L_8007375C
    if (ctx->r1 != 0) {
        // 0x80073778: sra         $s0, $t0, 16
        ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8007375C;
    }
    // 0x80073778: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8007377C: jal         0x80072C54
    // 0x80073780: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_11;
    // 0x80073780: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x80073784: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80073788: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8007378C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80073790: bne         $t3, $zero, L_8007388C
    if (ctx->r11 != 0) {
        // 0x80073794: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007388C;
    }
    // 0x80073794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80073798: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8007379C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800737A0: blez        $t4, L_8007388C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800737A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007388C;
    }
    // 0x800737A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800737A8:
    // 0x800737A8: jal         0x8006B14C
    // 0x800737AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x800737AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800737B0: bne         $v0, $zero, L_80073878
    if (ctx->r2 != 0) {
        // 0x800737B4: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80073878;
    }
    // 0x800737B4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800737B8: jal         0x8006B0F8
    // 0x800737BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x800737BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800737C0: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800737C4: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800737C8: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800737CC: beq         $t8, $zero, L_80073804
    if (ctx->r24 == 0) {
        // 0x800737D0: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_80073804;
    }
    // 0x800737D0: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800737D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800737D8: jal         0x80072C54
    // 0x800737DC: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_14;
    // 0x800737DC: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_14:
    // 0x800737E0: lw          $t9, 0x3C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X3C);
    // 0x800737E4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800737E8: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x800737EC: jal         0x80072C54
    // 0x800737F0: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_15;
    // 0x800737F0: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_15:
    // 0x800737F4: lw          $t1, 0x30($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X30);
    // 0x800737F8: nop

    // 0x800737FC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073800: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073804:
    // 0x80073804: andi        $t3, $s2, 0x2
    ctx->r11 = ctx->r18 & 0X2;
    // 0x80073808: beq         $t3, $zero, L_8007383C
    if (ctx->r11 == 0) {
        // 0x8007380C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8007383C;
    }
    // 0x8007380C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073810: jal         0x80072C54
    // 0x80073814: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_16;
    // 0x80073814: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_16:
    // 0x80073818: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    // 0x8007381C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073820: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073824: jal         0x80072C54
    // 0x80073828: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_17;
    // 0x80073828: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    after_17:
    // 0x8007382C: lw          $t6, 0x34($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X34);
    // 0x80073830: nop

    // 0x80073834: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073838: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
L_8007383C:
    // 0x8007383C: andi        $t8, $s2, 0x4
    ctx->r24 = ctx->r18 & 0X4;
    // 0x80073840: beq         $t8, $zero, L_80073874
    if (ctx->r24 == 0) {
        // 0x80073844: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073874;
    }
    // 0x80073844: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073848: jal         0x80072C54
    // 0x8007384C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_18;
    // 0x8007384C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_18:
    // 0x80073850: lw          $t9, 0x44($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X44);
    // 0x80073854: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073858: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8007385C: jal         0x80072C54
    // 0x80073860: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_19;
    // 0x80073860: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_19:
    // 0x80073864: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x80073868: nop

    // 0x8007386C: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073870: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073874:
    // 0x80073874: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80073878:
    // 0x80073878: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007387C: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073880: bne         $at, $zero, L_800737A8
    if (ctx->r1 != 0) {
        // 0x80073884: nop
    
            goto L_800737A8;
    }
    // 0x80073884: nop

L_80073888:
    // 0x80073888: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007388C:
    // 0x8007388C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80073890: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80073894: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80073898: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007389C: jr          $ra
    // 0x800738A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800738A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void charselect_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B758: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008B75C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008B760: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008B764: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008B768: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008B76C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008B770: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008B774: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008B778: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B77C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008B780: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008B784: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008B788: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008B78C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008B790: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008B794: addiu       $fp, $fp, 0x63CC
    ctx->r30 = ADD32(ctx->r30, 0X63CC);
    // 0x8008B798: addiu       $s7, $s7, -0xB80
    ctx->r23 = ADD32(ctx->r23, -0XB80);
    // 0x8008B79C: addiu       $s6, $s6, 0x63E8
    ctx->r22 = ADD32(ctx->r22, 0X63E8);
    // 0x8008B7A0: addiu       $s0, $s0, 0x63C0
    ctx->r16 = ADD32(ctx->r16, 0X63C0);
    // 0x8008B7A4: addiu       $s3, $zero, 0xE
    ctx->r19 = ADD32(0, 0XE);
    // 0x8008B7A8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8008B7AC: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x8008B7B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008B7B4:
    // 0x8008B7B4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8008B7B8: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008B7BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008B7C0: beq         $t6, $zero, L_8008BAF8
    if (ctx->r14 == 0) {
        // 0x8008B7C4: addiu       $t7, $t7, 0x63DC
        ctx->r15 = ADD32(ctx->r15, 0X63DC);
            goto L_8008BAF8;
    }
    // 0x8008B7C4: addiu       $t7, $t7, 0x63DC
    ctx->r15 = ADD32(ctx->r15, 0X63DC);
    // 0x8008B7C8: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
    // 0x8008B7CC: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    // 0x8008B7D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008B7D4: addiu       $t8, $t8, 0x67D8
    ctx->r24 = ADD32(ctx->r24, 0X67D8);
    // 0x8008B7D8: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
    // 0x8008B7DC: beq         $t9, $zero, L_8008B858
    if (ctx->r25 == 0) {
        // 0x8008B7E0: addu        $v0, $a2, $t8
        ctx->r2 = ADD32(ctx->r6, ctx->r24);
            goto L_8008B858;
    }
    // 0x8008B7E0: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8008B7E4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8008B7E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008B7EC: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8008B7F0: beq         $t1, $zero, L_8008BAF8
    if (ctx->r9 == 0) {
        // 0x8008B7F4: addiu       $t4, $t4, 0x6808
        ctx->r12 = ADD32(ctx->r12, 0X6808);
            goto L_8008BAF8;
    }
    // 0x8008B7F4: addiu       $t4, $t4, 0x6808
    ctx->r12 = ADD32(ctx->r12, 0X6808);
    // 0x8008B7F8: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x8008B7FC: addu        $s1, $a2, $t4
    ctx->r17 = ADD32(ctx->r6, ctx->r12);
    // 0x8008B800: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008B804: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8008B808: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8008B80C: sw          $t3, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r11;
    // 0x8008B810: beq         $a0, $zero, L_8008B820
    if (ctx->r4 == 0) {
        // 0x8008B814: addu        $s2, $s6, $s4
        ctx->r18 = ADD32(ctx->r22, ctx->r20);
            goto L_8008B820;
    }
    // 0x8008B814: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008B818: jal         0x8000488C
    // 0x8008B81C: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8008B81C: nop

    after_0:
L_8008B820:
    // 0x8008B820: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008B824: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8008B828: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B82C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008B830: mflo        $t7
    ctx->r15 = lo;
    // 0x8008B834: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8008B838: lh          $a0, 0xC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC);
    // 0x8008B83C: nop

    // 0x8008B840: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008B844: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8008B848: jal         0x80001D04
    // 0x8008B84C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008B84C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x8008B850: b           L_8008BAFC
    // 0x8008B854: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BAFC;
    // 0x8008B854: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008B858:
    // 0x8008B858: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8008B85C: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008B860: andi        $t0, $v1, 0x4000
    ctx->r8 = ctx->r3 & 0X4000;
    // 0x8008B864: beq         $t0, $zero, L_8008B958
    if (ctx->r8 == 0) {
        // 0x8008B868: andi        $t8, $v1, 0x9000
        ctx->r24 = ctx->r3 & 0X9000;
            goto L_8008B958;
    }
    // 0x8008B868: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x8008B86C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008B870: lw          $t1, -0xB44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB44);
    // 0x8008B874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B878: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8008B87C: sw          $t2, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r10;
    // 0x8008B880: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008B884: lw          $a2, -0xB44($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB44);
    // 0x8008B888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B88C: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x8008B890: blez        $a2, L_8008B92C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008B894: sb          $zero, 0x63D4($at)
        MEM_B(0X63D4, ctx->r1) = 0;
            goto L_8008B92C;
    }
    // 0x8008B894: sb          $zero, 0x63D4($at)
    MEM_B(0X63D4, ctx->r1) = 0;
    // 0x8008B898: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008B89C: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008B8A0: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B8A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008B8A8: lb          $t3, 0x63B4($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X63B4);
    // 0x8008B8AC: mflo        $t6
    ctx->r14 = lo;
    // 0x8008B8B0: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x8008B8B4: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x8008B8B8: nop

    // 0x8008B8BC: bne         $t3, $t7, L_8008B930
    if (ctx->r11 != ctx->r15) {
        // 0x8008B8C0: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8008B930;
    }
    // 0x8008B8C0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8008B8C4: lb          $t8, 0x1($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1);
    // 0x8008B8C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B8CC: bgtz        $t8, L_8008B92C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008B8D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008B92C;
    }
    // 0x8008B8D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008B8D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008B8D8: addiu       $t9, $t9, 0x63D4
    ctx->r25 = ADD32(ctx->r25, 0X63D4);
    // 0x8008B8DC: addu        $v0, $zero, $t9
    ctx->r2 = ADD32(0, ctx->r25);
L_8008B8E0:
    // 0x8008B8E0: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x8008B8E4: addu        $t1, $s6, $v1
    ctx->r9 = ADD32(ctx->r22, ctx->r3);
    // 0x8008B8E8: beq         $t0, $zero, L_8008B914
    if (ctx->r8 == 0) {
        // 0x8008B8EC: nop
    
            goto L_8008B914;
    }
    // 0x8008B8EC: nop

    // 0x8008B8F0: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8008B8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008B8F8: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B8FC: mflo        $t4
    ctx->r12 = lo;
    // 0x8008B900: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x8008B904: lh          $t5, 0xC($t6)
    ctx->r13 = MEM_H(ctx->r14, 0XC);
    // 0x8008B908: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008B90C: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
    // 0x8008B910: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8008B914:
    // 0x8008B914: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008B918: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8008B91C: beq         $at, $zero, L_8008B92C
    if (ctx->r1 == 0) {
        // 0x8008B920: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008B92C;
    }
    // 0x8008B920: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B924: beq         $a0, $zero, L_8008B8E0
    if (ctx->r4 == 0) {
        // 0x8008B928: nop
    
            goto L_8008B8E0;
    }
    // 0x8008B928: nop

L_8008B92C:
    // 0x8008B92C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8008B930:
    // 0x8008B930: bgtz        $a2, L_8008BAF8
    if (SIGNED(ctx->r6) > 0) {
        // 0x8008B934: sb          $t3, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r11;
            goto L_8008BAF8;
    }
    // 0x8008B934: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x8008B938: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008B93C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B940: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B944: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
    // 0x8008B948: jal         0x800C01D8
    // 0x8008B94C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008B94C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_2:
    // 0x8008B950: b           L_8008BAFC
    // 0x8008B954: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BAFC;
    // 0x8008B954: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008B958:
    // 0x8008B958: beq         $t8, $zero, L_8008B9C4
    if (ctx->r24 == 0) {
        // 0x8008B95C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008B9C4;
    }
    // 0x8008B95C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008B960: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008B964: addiu       $t2, $t2, 0x6808
    ctx->r10 = ADD32(ctx->r10, 0X6808);
    // 0x8008B968: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008B96C: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x8008B970: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008B974: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008B978: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8008B97C: beq         $a0, $zero, L_8008B98C
    if (ctx->r4 == 0) {
        // 0x8008B980: sw          $t1, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r9;
            goto L_8008B98C;
    }
    // 0x8008B980: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x8008B984: jal         0x8000488C
    // 0x8008B988: nop

    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x8008B988: nop

    after_3:
L_8008B98C:
    // 0x8008B98C: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008B990: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x8008B994: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008B99C: mflo        $t5
    ctx->r13 = lo;
    // 0x8008B9A0: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x8008B9A4: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x8008B9A8: nop

    // 0x8008B9AC: addiu       $a0, $a0, 0x87
    ctx->r4 = ADD32(ctx->r4, 0X87);
    // 0x8008B9B0: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x8008B9B4: jal         0x80001D04
    // 0x8008B9B8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008B9B8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x8008B9BC: b           L_8008BAFC
    // 0x8008B9C0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BAFC;
    // 0x8008B9C0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008B9C4:
    // 0x8008B9C4: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008B9C8: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x8008B9CC: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B9D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B9D4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008B9D8: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008B9DC: lh          $a0, 0x6830($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6830);
    // 0x8008B9E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008B9E4: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008B9E8: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x8008B9EC: mflo        $v0
    ctx->r2 = lo;
    // 0x8008B9F0: addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
    // 0x8008B9F4: blez        $a0, L_8008BA24
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008B9F8: nop
    
            goto L_8008BA24;
    }
    // 0x8008B9F8: nop

    // 0x8008B9FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BA00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BA04: jal         0x8008BFE8
    // 0x8008BA08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    charselect_move(rdram, ctx);
        goto after_5;
    // 0x8008BA08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_5:
    // 0x8008BA0C: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BA10: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BA14: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8008BA18: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8008BA1C: b           L_8008BAD4
    // 0x8008BA20: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
        goto L_8008BAD4;
    // 0x8008BA20: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
L_8008BA24:
    // 0x8008BA24: bgez        $a0, L_8008BA5C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BA28: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8008BA5C;
    }
    // 0x8008BA28: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008BA2C: addiu       $t1, $zero, 0x15C
    ctx->r9 = ADD32(0, 0X15C);
    // 0x8008BA30: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008BA34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BA38: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x8008BA3C: jal         0x8008BFE8
    // 0x8008BA40: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_6;
    // 0x8008BA40: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_6:
    // 0x8008BA44: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BA48: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BA4C: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8008BA50: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008BA54: b           L_8008BAD4
    // 0x8008BA58: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
        goto L_8008BAD4;
    // 0x8008BA58: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
L_8008BA5C:
    // 0x8008BA5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BA60: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008BA64: lh          $a0, 0x6818($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6818);
    // 0x8008BA68: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BA6C: bgez        $a0, L_8008BAA0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BA70: addiu       $a3, $zero, 0xEC
        ctx->r7 = ADD32(0, 0XEC);
            goto L_8008BAA0;
    }
    // 0x8008BA70: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008BA74: addiu       $t6, $zero, 0x15C
    ctx->r14 = ADD32(0, 0X15C);
    // 0x8008BA78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008BA7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BA80: jal         0x8008BFE8
    // 0x8008BA84: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    charselect_move(rdram, ctx);
        goto after_7;
    // 0x8008BA84: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_7:
    // 0x8008BA88: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BA8C: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BA90: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008BA94: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8008BA98: b           L_8008BAD4
    // 0x8008BA9C: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
        goto L_8008BAD4;
    // 0x8008BA9C: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
L_8008BAA0:
    // 0x8008BAA0: blez        $a0, L_8008BAD4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008BAA4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8008BAD4;
    }
    // 0x8008BAA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BAA8: addiu       $t5, $zero, 0x15C
    ctx->r13 = ADD32(0, 0X15C);
    // 0x8008BAAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008BAB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BAB4: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x8008BAB8: jal         0x8008BFE8
    // 0x8008BABC: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_8;
    // 0x8008BABC: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_8:
    // 0x8008BAC0: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BAC4: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BAC8: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8008BACC: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8008BAD0: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
L_8008BAD4:
    // 0x8008BAD4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8008BAD8: lh          $v1, 0xC($t7)
    ctx->r3 = MEM_H(ctx->r15, 0XC);
    // 0x8008BADC: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8008BAE0: nop

    // 0x8008BAE4: beq         $t8, $v1, L_8008BAFC
    if (ctx->r24 == ctx->r3) {
        // 0x8008BAE8: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_8008BAFC;
    }
    // 0x8008BAE8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008BAEC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8008BAF0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008BAF4: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
L_8008BAF8:
    // 0x8008BAF8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BAFC:
    // 0x8008BAFC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008BB00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008BB04: bne         $s4, $at, L_8008B7B4
    if (ctx->r20 != ctx->r1) {
        // 0x8008BB08: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008B7B4;
    }
    // 0x8008BB08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BB0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008BB10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008BB14: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008BB18: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008BB1C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BB20: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008BB24: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008BB28: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008BB2C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008BB30: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008BB34: jr          $ra
    // 0x8008BB38: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BB38: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _loadBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800644A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800644A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800644A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800644AC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800644B0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800644B4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800644B8: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800644BC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800644C0: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800644C4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800644C8: beq         $at, $zero, L_800644D4
    if (ctx->r1 == 0) {
        // 0x800644CC: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_800644D4;
    }
    // 0x800644CC: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x800644D0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_800644D4:
    // 0x800644D4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800644D8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800644DC: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800644E0: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x800644E4: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x800644E8: beq         $at, $zero, L_800645C8
    if (ctx->r1 == 0) {
        // 0x800644EC: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800645C8;
    }
    // 0x800644EC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800644F0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800644F4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800644F8: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x800644FC: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80064500: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80064504: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064508: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8006450C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80064510: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80064514: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x80064518: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006451C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80064520: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80064524: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80064528: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006452C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80064530: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80064534: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80064538: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006453C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80064540: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064544: jal         0x800C8CF0
    // 0x80064548: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064548: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006454C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80064550: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064554: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80064558: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8006455C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80064560: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80064564: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x80064568: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8006456C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064570: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80064574: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80064578: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006457C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064580: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80064584: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80064588: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006458C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80064590: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80064594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064598: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x8006459C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800645A0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800645A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800645A8: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800645AC: jal         0x800C8CF0
    // 0x800645B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800645B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800645B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800645B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800645BC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800645C0: b           L_80064614
    // 0x800645C4: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_80064614;
    // 0x800645C4: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_800645C8:
    // 0x800645C8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800645CC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800645D0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800645D4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800645D8: addiu       $s0, $t6, 0x8
    ctx->r16 = ADD32(ctx->r14, 0X8);
    // 0x800645DC: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x800645E0: sw          $a3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r7;
    // 0x800645E4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800645E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800645EC: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x800645F0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800645F4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800645F8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800645FC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064600: jal         0x800C8CF0
    // 0x80064604: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064604: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80064608: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8006460C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064610: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80064614:
    // 0x80064614: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064618: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006461C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80064620: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80064624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064628: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8006462C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064630: jr          $ra
    // 0x80064634: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064634: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void enable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0170: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0174: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0178: jr          $ra
    // 0x800C017C: sw          $t6, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = ctx->r14;
    return;
    // 0x800C017C: sw          $t6, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void path_update_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001136C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80011370: lw          $t6, -0x5254($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5254);
    // 0x80011374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011378: beq         $t6, $zero, L_80011388
    if (ctx->r14 == 0) {
        // 0x8001137C: nop
    
            goto L_80011388;
    }
    // 0x8001137C: nop

    // 0x80011380: jr          $ra
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011388:
    // 0x80011388: jr          $ra
    // 0x8001138C: nop

    return;
    // 0x8001138C: nop

;}
RECOMP_FUNC void load_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4170: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4174: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4178: lw          $t6, -0x5820($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5820);
    // 0x800C417C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4180: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C4184: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C4188: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C418C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C4190: beq         $at, $zero, L_800C4210
    if (ctx->r1 == 0) {
        // 0x800C4194: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C4210;
    }
    // 0x800C4194: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C4198: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C419C: lw          $t8, -0x581C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X581C);
    // 0x800C41A0: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C41A4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C41A8: lbu         $t9, 0x28($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X28);
    // 0x800C41AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C41B0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C41B4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C41B8: bne         $t1, $at, L_800C4210
    if (ctx->r9 != ctx->r1) {
        // 0x800C41BC: sb          $t0, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r8;
            goto L_800C4210;
    }
    // 0x800C41BC: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x800C41C0: lh          $t2, 0x40($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X40);
    // 0x800C41C4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C41C8: beq         $s3, $t2, L_800C4210
    if (ctx->r19 == ctx->r10) {
        // 0x800C41CC: sll         $s0, $zero, 1
        ctx->r16 = S32(0 << 1);
            goto L_800C4210;
    }
    // 0x800C41CC: sll         $s0, $zero, 1
    ctx->r16 = S32(0 << 1);
    // 0x800C41D0: addu        $s1, $v0, $s0
    ctx->r17 = ADD32(ctx->r2, ctx->r16);
    // 0x800C41D4: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800C41D8: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C41DC: addu        $s2, $v0, $t3
    ctx->r18 = ADD32(ctx->r2, ctx->r11);
L_800C41E0:
    // 0x800C41E0: jal         0x8007AE74
    // 0x800C41E4: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800C41E4: nop

    after_0:
    // 0x800C41E8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C41EC: slti        $at, $s0, 0x40
    ctx->r1 = SIGNED(ctx->r16) < 0X40 ? 1 : 0;
    // 0x800C41F0: sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // 0x800C41F4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C41F8: beq         $at, $zero, L_800C4210
    if (ctx->r1 == 0) {
        // 0x800C41FC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800C4210;
    }
    // 0x800C41FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C4200: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C4204: nop

    // 0x800C4208: bne         $s3, $a0, L_800C41E0
    if (ctx->r19 != ctx->r4) {
        // 0x800C420C: nop
    
            goto L_800C41E0;
    }
    // 0x800C420C: nop

L_800C4210:
    // 0x800C4210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4218: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C421C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4220: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4224: jr          $ra
    // 0x800C4228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4228: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D78: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80037D7C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80037D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037D84: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80037D88: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80037D8C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80037D90: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80037D94: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80037D98: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80037D9C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80037DA0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80037DA4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80037DA8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80037DAC: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80037DB0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80037DB4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80037DB8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80037DBC: jal         0x8001F460
    // 0x80037DC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037DC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80037DC4: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80037DC8: nop

    // 0x80037DCC: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80037DD0: nop

    // 0x80037DD4: beq         $v1, $zero, L_800380BC
    if (ctx->r3 == 0) {
        // 0x80037DD8: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380BC;
    }
    // 0x80037DD8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037DDC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80037DE0: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x80037DE4: blez        $v0, L_80037DF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037DE8: subu        $t7, $v0, $s1
        ctx->r15 = SUB32(ctx->r2, ctx->r17);
            goto L_80037DF4;
    }
    // 0x80037DE8: subu        $t7, $v0, $s1
    ctx->r15 = SUB32(ctx->r2, ctx->r17);
    // 0x80037DEC: b           L_80037DF8
    // 0x80037DF0: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
        goto L_80037DF8;
    // 0x80037DF0: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
L_80037DF4:
    // 0x80037DF4: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80037DF8:
    // 0x80037DF8: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x80037DFC: nop

    // 0x80037E00: beq         $t8, $zero, L_800380BC
    if (ctx->r24 == 0) {
        // 0x80037E04: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380BC;
    }
    // 0x80037E04: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E08: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80037E0C: nop

    // 0x80037E10: bne         $t9, $zero, L_800380BC
    if (ctx->r25 != 0) {
        // 0x80037E14: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380BC;
    }
    // 0x80037E14: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E18: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80037E1C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80037E20: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80037E24: beq         $t2, $zero, L_800380B8
    if (ctx->r10 == 0) {
        // 0x80037E28: addiu       $a0, $sp, 0xCC
        ctx->r4 = ADD32(ctx->r29, 0XCC);
            goto L_800380B8;
    }
    // 0x80037E28: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037E2C: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80037E30: jal         0x8006FC30
    // 0x80037E34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x80037E34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80037E38: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80037E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037E40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037E44: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80037E48: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x80037E4C: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x80037E50: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80037E54: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80037E58: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x80037E5C: sh          $t4, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r12;
    // 0x80037E60: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80037E64: sh          $zero, 0x70($sp)
    MEM_H(0X70, ctx->r29) = 0;
    // 0x80037E68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80037E6C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80037E70: jal         0x8006FC30
    // 0x80037E74: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80037E74: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    after_2:
    // 0x80037E78: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80037E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80037E80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80037E84: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80037E88: blez        $t6, L_800380B8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80037E8C: addiu       $fp, $sp, 0x84
        ctx->r30 = ADD32(ctx->r29, 0X84);
            goto L_800380B8;
    }
    // 0x80037E8C: addiu       $fp, $sp, 0x84
    ctx->r30 = ADD32(ctx->r29, 0X84);
    // 0x80037E90: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80037E94: addiu       $s7, $sp, 0x114
    ctx->r23 = ADD32(ctx->r29, 0X114);
    // 0x80037E98: addiu       $s6, $sp, 0x118
    ctx->r22 = ADD32(ctx->r29, 0X118);
    // 0x80037E9C: addiu       $s5, $sp, 0x11C
    ctx->r21 = ADD32(ctx->r29, 0X11C);
    // 0x80037EA0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80037EA4:
    // 0x80037EA4: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80037EA8: nop

    // 0x80037EAC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80037EB0: lb          $v1, 0x0($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X0);
    // 0x80037EB4: nop

    // 0x80037EB8: bltz        $v1, L_8003809C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80037EBC: nop
    
            goto L_8003809C;
    }
    // 0x80037EBC: nop

    // 0x80037EC0: lh          $t9, 0x18($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X18);
    // 0x80037EC4: nop

    // 0x80037EC8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80037ECC: beq         $at, $zero, L_8003809C
    if (ctx->r1 == 0) {
        // 0x80037ED0: nop
    
            goto L_8003809C;
    }
    // 0x80037ED0: nop

    // 0x80037ED4: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80037ED8: nop

    // 0x80037EDC: beq         $t0, $zero, L_8003809C
    if (ctx->r8 == 0) {
        // 0x80037EE0: nop
    
            goto L_8003809C;
    }
    // 0x80037EE0: nop

    // 0x80037EE4: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x80037EE8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80037EEC: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80037EF0: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80037EF4: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037EF8: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037EFC: mflo        $t4
    ctx->r12 = lo;
    // 0x80037F00: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80037F04: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80037F08: nop

    // 0x80037F0C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80037F10: nop

    // 0x80037F14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037F18: swc1        $f8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f8.u32l;
    // 0x80037F1C: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80037F20: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80037F24: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80037F28: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80037F2C: lw          $a1, 0x11C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X11C);
    // 0x80037F30: multu       $t1, $s2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F34: mflo        $t2
    ctx->r10 = lo;
    // 0x80037F38: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80037F3C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80037F40: nop

    // 0x80037F44: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80037F48: nop

    // 0x80037F4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80037F50: swc1        $f16, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f16.u32l;
    // 0x80037F54: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x80037F58: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80037F5C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80037F60: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80037F64: lw          $a2, 0x118($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X118);
    // 0x80037F68: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F6C: mflo        $t1
    ctx->r9 = lo;
    // 0x80037F70: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x80037F74: lh          $t2, 0x4($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X4);
    // 0x80037F78: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80037F7C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80037F80: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80037F84: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80037F88: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80037F8C: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
    // 0x80037F90: lw          $a3, 0x114($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X114);
    // 0x80037F94: jal         0x8006F64C
    // 0x80037F98: nop

    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80037F98: nop

    after_3:
    // 0x80037F9C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80037FA0: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80037FA4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80037FA8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037FAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037FB0: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80037FB4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037FB8: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80037FBC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80037FC0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80037FC4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80037FC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80037FCC: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x80037FD0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80037FD4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037FD8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037FDC: sb          $t1, 0x85($sp)
    MEM_B(0X85, ctx->r29) = ctx->r9;
    // 0x80037FE0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80037FE4: sb          $t7, 0x84($sp)
    MEM_B(0X84, ctx->r29) = ctx->r15;
    // 0x80037FE8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80037FEC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80037FF0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80037FF4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80037FF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80037FFC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80038000: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038004: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80038008: sh          $t4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r12;
    // 0x8003800C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80038010: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
    // 0x80038014: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80038018: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003801C: jal         0x8000EA54
    // 0x80038020: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x80038020: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    after_4:
    // 0x80038024: beq         $v0, $zero, L_8003809C
    if (ctx->r2 == 0) {
        // 0x80038028: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8003809C;
    }
    // 0x80038028: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003802C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80038030: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80038034: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80038038: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8003803C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80038040: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80038044: sw          $t8, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r24;
    // 0x80038048: negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // 0x8003804C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80038050: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80038054: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80038058: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003805C: addiu       $t9, $v0, 0x1C
    ctx->r25 = ADD32(ctx->r2, 0X1C);
    // 0x80038060: addiu       $t5, $v0, 0x20
    ctx->r13 = ADD32(ctx->r2, 0X20);
    // 0x80038064: addiu       $t1, $v0, 0x24
    ctx->r9 = ADD32(ctx->r2, 0X24);
    // 0x80038068: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003806C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80038070: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80038074: jal         0x8006F64C
    // 0x80038078: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtxf_transform_point(rdram, ctx);
        goto after_5;
    // 0x80038078: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x8003807C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80038080: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80038084: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80038088: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003808C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80038090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80038094: jal         0x80009558
    // 0x80038098: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_6;
    // 0x80038098: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    after_6:
L_8003809C:
    // 0x8003809C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800380A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800380A4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800380A8: nop

    // 0x800380AC: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800380B0: bne         $at, $zero, L_80037EA4
    if (ctx->r1 != 0) {
        // 0x800380B4: nop
    
            goto L_80037EA4;
    }
    // 0x800380B4: nop

L_800380B8:
    // 0x800380B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800380BC:
    // 0x800380BC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800380C0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800380C4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800380C8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800380CC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800380D0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800380D4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800380D8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800380DC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800380E0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800380E4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800380E8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800380EC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800380F0: jr          $ra
    // 0x800380F4: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800380F4: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void obj_loop_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037CF0: jal         0x8001F460
    // 0x80037CF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037CF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80037CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037D00: jr          $ra
    // 0x80037D04: nop

    return;
    // 0x80037D04: nop

;}
RECOMP_FUNC void obj_loop_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038A78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038A80: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80038A84: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80038A88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80038A8C: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x80038A90: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x80038A94: nop

    // 0x80038A98: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80038A9C: bne         $at, $zero, L_80038ABC
    if (ctx->r1 != 0) {
        // 0x80038AA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038ABC;
    }
    // 0x80038AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038AA4: jal         0x8000FFB8
    // 0x80038AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038AAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038AB0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80038AB4: sh          $t0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r8;
    // 0x80038AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038ABC:
    // 0x80038ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038AC0: jr          $ra
    // 0x80038AC4: nop

    return;
    // 0x80038AC4: nop

;}
RECOMP_FUNC void get_cached_texture_by_slot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B380: bltz        $a0, L_8007B39C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007B384: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B39C;
    }
    // 0x8007B384: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B388: lw          $t6, 0x6330($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6330);
    // 0x8007B38C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B390: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B394: bne         $at, $zero, L_8007B3A4
    if (ctx->r1 != 0) {
        // 0x8007B398: nop
    
            goto L_8007B3A4;
    }
    // 0x8007B398: nop

L_8007B39C:
    // 0x8007B39C: jr          $ra
    // 0x8007B3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B3A4:
    // 0x8007B3A4: lw          $t7, 0x6328($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6328);
    // 0x8007B3A8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007B3AC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B3B0: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007B3B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B3B8: bne         $v1, $at, L_8007B3C8
    if (ctx->r3 != ctx->r1) {
        // 0x8007B3BC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007B3C8;
    }
    // 0x8007B3BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007B3C0: jr          $ra
    // 0x8007B3C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007B3C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B3C8:
    // 0x8007B3C8: jr          $ra
    // 0x8007B3CC: nop

    return;
    // 0x8007B3CC: nop

;}
