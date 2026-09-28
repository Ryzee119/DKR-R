#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void leveltable_non_challenge_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B018: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B01C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B020: bltz        $t7, L_8006B048
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006B024: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006B048;
    }
    // 0x8006B024: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B028: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8006B02C: beq         $at, $zero, L_8006B048
    if (ctx->r1 == 0) {
        // 0x8006B030: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_8006B048;
    }
    // 0x8006B030: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006B034: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B038: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006B03C: lw          $v0, 0x1180($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1180);
    // 0x8006B040: jr          $ra
    // 0x8006B044: nop

    return;
    // 0x8006B044: nop

L_8006B048:
    // 0x8006B048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B04C: jr          $ra
    // 0x8006B050: nop

    return;
    // 0x8006B050: nop

;}
RECOMP_FUNC void _bcopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9DA0: beq         $a2, $zero, L_800C9E0C
    if (ctx->r6 == 0) {
        // 0x800C9DA4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800C9E0C;
    }
    // 0x800C9DA4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C9DA8: beq         $a0, $a1, L_800C9E0C
    if (ctx->r4 == ctx->r5) {
        // 0x800C9DAC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800C9E0C;
    }
    // 0x800C9DAC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800C9DB0: bnel        $at, $zero, L_800C9DD4
    if (ctx->r1 != 0) {
        // 0x800C9DB4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800C9DD4;
    }
    goto skip_0;
    // 0x800C9DB4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800C9DB8: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800C9DBC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C9DC0: beql        $at, $zero, L_800C9DD4
    if (ctx->r1 == 0) {
        // 0x800C9DC4: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800C9DD4;
    }
    goto skip_1;
    // 0x800C9DC4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800C9DC8: b           L_800C9F38
    // 0x800C9DCC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800C9F38;
    // 0x800C9DCC: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800C9DD0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800C9DD4:
    // 0x800C9DD4: bne         $at, $zero, L_800C9DEC
    if (ctx->r1 != 0) {
        // 0x800C9DD8: nop
    
            goto L_800C9DEC;
    }
    // 0x800C9DD8: nop

    // 0x800C9DDC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800C9DE0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800C9DE4: beq         $v0, $v1, L_800C9E14
    if (ctx->r2 == ctx->r3) {
        // 0x800C9DE8: nop
    
            goto L_800C9E14;
    }
    // 0x800C9DE8: nop

L_800C9DEC:
    // 0x800C9DEC: beq         $a2, $zero, L_800C9E0C
    if (ctx->r6 == 0) {
        // 0x800C9DF0: nop
    
            goto L_800C9E0C;
    }
    // 0x800C9DF0: nop

    // 0x800C9DF4: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800C9DF8:
    // 0x800C9DF8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800C9DFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C9E00: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C9E04: bne         $a0, $v1, L_800C9DF8
    if (ctx->r4 != ctx->r3) {
        // 0x800C9E08: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800C9DF8;
    }
    // 0x800C9E08: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800C9E0C:
    // 0x800C9E0C: jr          $ra
    // 0x800C9E10: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800C9E10: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800C9E14:
    // 0x800C9E14: beq         $v0, $zero, L_800C9E78
    if (ctx->r2 == 0) {
        // 0x800C9E18: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C9E78;
    }
    // 0x800C9E18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C9E1C: beq         $v0, $at, L_800C9E5C
    if (ctx->r2 == ctx->r1) {
        // 0x800C9E20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C9E5C;
    }
    // 0x800C9E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C9E24: beql        $v0, $at, L_800C9E48
    if (ctx->r2 == ctx->r1) {
        // 0x800C9E28: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800C9E48;
    }
    goto skip_2;
    // 0x800C9E28: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800C9E2C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800C9E30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C9E34: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C9E38: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800C9E3C: b           L_800C9E78
    // 0x800C9E40: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800C9E78;
    // 0x800C9E40: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800C9E44: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800C9E48:
    // 0x800C9E48: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800C9E4C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800C9E50: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800C9E54: b           L_800C9E78
    // 0x800C9E58: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800C9E78;
    // 0x800C9E58: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800C9E5C:
    // 0x800C9E5C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800C9E60: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800C9E64: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C9E68: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800C9E6C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800C9E70: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800C9E74: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800C9E78:
    // 0x800C9E78: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800C9E7C: bnel        $at, $zero, L_800C9ED8
    if (ctx->r1 != 0) {
        // 0x800C9E80: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800C9ED8;
    }
    goto skip_3;
    // 0x800C9E80: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800C9E84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C9E88: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800C9E8C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800C9E90: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800C9E94: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800C9E98: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C9E9C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800C9EA0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800C9EA4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800C9EA8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800C9EAC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800C9EB0: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800C9EB4: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800C9EB8: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800C9EBC: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800C9EC0: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800C9EC4: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800C9EC8: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800C9ECC: b           L_800C9E78
    // 0x800C9ED0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800C9E78;
    // 0x800C9ED0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800C9ED4:
    // 0x800C9ED4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800C9ED8:
    // 0x800C9ED8: bnel        $at, $zero, L_800C9F14
    if (ctx->r1 != 0) {
        // 0x800C9EDC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800C9F14;
    }
    goto skip_4;
    // 0x800C9EDC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800C9EE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C9EE4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800C9EE8: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800C9EEC: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800C9EF0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800C9EF4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800C9EF8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800C9EFC: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800C9F00: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800C9F04: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800C9F08: b           L_800C9ED4
    // 0x800C9F0C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800C9ED4;
    // 0x800C9F0C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800C9F10:
    // 0x800C9F10: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800C9F14:
    // 0x800C9F14: bne         $at, $zero, L_800C9DEC
    if (ctx->r1 != 0) {
        // 0x800C9F18: nop
    
            goto L_800C9DEC;
    }
    // 0x800C9F18: nop

    // 0x800C9F1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C9F20: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C9F24: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C9F28: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800C9F2C: b           L_800C9F10
    // 0x800C9F30: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800C9F10;
    // 0x800C9F30: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800C9F34: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800C9F38:
    // 0x800C9F38: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800C9F3C: bne         $at, $zero, L_800C9F54
    if (ctx->r1 != 0) {
        // 0x800C9F40: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800C9F54;
    }
    // 0x800C9F40: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800C9F44: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800C9F48: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800C9F4C: beq         $v0, $v1, L_800C9F84
    if (ctx->r2 == ctx->r3) {
        // 0x800C9F50: nop
    
            goto L_800C9F84;
    }
    // 0x800C9F50: nop

L_800C9F54:
    // 0x800C9F54: beq         $a2, $zero, L_800C9E0C
    if (ctx->r6 == 0) {
        // 0x800C9F58: nop
    
            goto L_800C9E0C;
    }
    // 0x800C9F58: nop

    // 0x800C9F5C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C9F60: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C9F64: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800C9F68:
    // 0x800C9F68: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800C9F6C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C9F70: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C9F74: bne         $a0, $v1, L_800C9F68
    if (ctx->r4 != ctx->r3) {
        // 0x800C9F78: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800C9F68;
    }
    // 0x800C9F78: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800C9F7C: jr          $ra
    // 0x800C9F80: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800C9F80: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800C9F84:
    // 0x800C9F84: beq         $v0, $zero, L_800C9FE8
    if (ctx->r2 == 0) {
        // 0x800C9F88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C9FE8;
    }
    // 0x800C9F88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C9F8C: beq         $v0, $at, L_800C9FCC
    if (ctx->r2 == ctx->r1) {
        // 0x800C9F90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C9FCC;
    }
    // 0x800C9F90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C9F94: beql        $v0, $at, L_800C9FB8
    if (ctx->r2 == ctx->r1) {
        // 0x800C9F98: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800C9FB8;
    }
    goto skip_5;
    // 0x800C9F98: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800C9F9C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800C9FA0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C9FA4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C9FA8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800C9FAC: b           L_800C9FE8
    // 0x800C9FB0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800C9FE8;
    // 0x800C9FB0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800C9FB4: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800C9FB8:
    // 0x800C9FB8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800C9FBC: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800C9FC0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800C9FC4: b           L_800C9FE8
    // 0x800C9FC8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800C9FE8;
    // 0x800C9FC8: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800C9FCC:
    // 0x800C9FCC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800C9FD0: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800C9FD4: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800C9FD8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800C9FDC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800C9FE0: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800C9FE4: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800C9FE8:
    // 0x800C9FE8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800C9FEC: bnel        $at, $zero, L_800CA048
    if (ctx->r1 != 0) {
        // 0x800C9FF0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA048;
    }
    goto skip_6;
    // 0x800C9FF0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800C9FF4: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800C9FF8: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800C9FFC: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA000: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA004: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800CA008: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800CA00C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800CA010: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800CA014: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800CA018: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800CA01C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CA020: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800CA024: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800CA028: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800CA02C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800CA030: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800CA034: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CA038: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800CA03C: b           L_800C9FE8
    // 0x800CA040: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800C9FE8;
    // 0x800CA040: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800CA044:
    // 0x800CA044: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA048:
    // 0x800CA048: bnel        $at, $zero, L_800CA084
    if (ctx->r1 != 0) {
        // 0x800CA04C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CA084;
    }
    goto skip_7;
    // 0x800CA04C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800CA050: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA054: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CA058: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA05C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA060: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CA064: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800CA068: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CA06C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800CA070: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800CA074: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CA078: b           L_800CA044
    // 0x800CA07C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800CA044;
    // 0x800CA07C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800CA080:
    // 0x800CA080: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CA084:
    // 0x800CA084: bne         $at, $zero, L_800C9F54
    if (ctx->r1 != 0) {
        // 0x800CA088: nop
    
            goto L_800C9F54;
    }
    // 0x800CA088: nop

    // 0x800CA08C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA090: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800CA094: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800CA098: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CA09C: b           L_800CA080
    // 0x800CA0A0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800CA080;
    // 0x800CA0A0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void obj_loop_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034860: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80034864: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80034868: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003486C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80034870: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80034874: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80034878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003487C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80034880: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80034884: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80034888: bne         $t7, $zero, L_800348A8
    if (ctx->r15 != 0) {
        // 0x8003488C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800348A8;
    }
    // 0x8003488C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80034890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034894: lwc1        $f9, 0x5FF8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5FF8);
    // 0x80034898: lwc1        $f8, 0x5FFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5FFC);
    // 0x8003489C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800348A0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800348A4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800348A8:
    // 0x800348A8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800348AC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800348B0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800348B4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800348B8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x800348BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800348C0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800348C4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800348C8: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800348CC: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800348D0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800348D4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800348D8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800348DC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800348E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800348E4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800348E8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800348EC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800348F0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800348F4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800348F8: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x800348FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80034900: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80034904: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80034908: jal         0x80031130
    // 0x8003490C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_0;
    // 0x8003490C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80034910: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80034914: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034918: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x8003491C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80034920: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80034924: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80034928: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8003492C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80034930: jal         0x80031600
    // 0x80034934: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    resolve_collisions(rdram, ctx);
        goto after_1;
    // 0x80034934: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    after_1:
    // 0x80034938: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8003493C: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034940: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80034944: beq         $t1, $zero, L_80034998
    if (ctx->r9 == 0) {
        // 0x80034948: nop
    
            goto L_80034998;
    }
    // 0x80034948: nop

    // 0x8003494C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80034950: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034954: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034958: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003495C: nop

    // 0x80034960: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80034964: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80034968: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003496C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034970: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80034974: nop

    // 0x80034978: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003497C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80034980: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80034984: nop

    // 0x80034988: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003498C: nop

    // 0x80034990: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80034994: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_80034998:
    // 0x80034998: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003499C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800349A0: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800349A4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800349A8: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x800349AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800349B0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800349B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800349B8: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800349BC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800349C0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800349C4: jal         0x80011570
    // 0x800349C8: nop

    move_object(rdram, ctx);
        goto after_2;
    // 0x800349C8: nop

    after_2:
    // 0x800349CC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800349D0: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x800349D4: beq         $t2, $zero, L_80034A10
    if (ctx->r10 == 0) {
        // 0x800349D8: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034A10;
    }
    // 0x800349D8: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800349DC: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800349E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800349E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800349E8: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800349EC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800349F0: lwc1        $f4, 0x6000($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6000);
    // 0x800349F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800349F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800349FC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034A00: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80034A04: jal         0x8003FC44
    // 0x80034A08: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_3;
    // 0x80034A08: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80034A0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A10:
    // 0x80034A10: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80034A14: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80034A18: blez        $v0, L_80034A28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80034A1C: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_80034A28;
    }
    // 0x80034A1C: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80034A20: b           L_80034A2C
    // 0x80034A24: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
        goto L_80034A2C;
    // 0x80034A24: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
L_80034A28:
    // 0x80034A28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A2C:
    // 0x80034A2C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80034A30: nop

    // 0x80034A34: lbu         $t5, 0x13($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13);
    // 0x80034A38: nop

    // 0x80034A3C: slti        $at, $t5, 0x50
    ctx->r1 = SIGNED(ctx->r13) < 0X50 ? 1 : 0;
    // 0x80034A40: beq         $at, $zero, L_80034AD0
    if (ctx->r1 == 0) {
        // 0x80034A44: nop
    
            goto L_80034AD0;
    }
    // 0x80034A44: nop

    // 0x80034A48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034A4C: nop

    // 0x80034A50: beq         $v0, $zero, L_80034AD0
    if (ctx->r2 == 0) {
        // 0x80034A54: nop
    
            goto L_80034AD0;
    }
    // 0x80034A54: nop

    // 0x80034A58: lh          $t6, 0x48($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X48);
    // 0x80034A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034A60: bne         $a0, $t6, L_80034AD0
    if (ctx->r4 != ctx->r14) {
        // 0x80034A64: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_80034AD0;
    }
    // 0x80034A64: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034A68: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80034A6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034A70: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80034A74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034A78: beq         $t7, $at, L_80034A84
    if (ctx->r15 == ctx->r1) {
        // 0x80034A7C: addiu       $t9, $zero, 0x11
        ctx->r25 = ADD32(0, 0X11);
            goto L_80034A84;
    }
    // 0x80034A7C: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x80034A80: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
L_80034A84:
    // 0x80034A84: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80034A88: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80034A8C: beq         $v0, $zero, L_80034A98
    if (ctx->r2 == 0) {
        // 0x80034A90: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034A98;
    }
    // 0x80034A90: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80034A94: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_80034A98:
    // 0x80034A98: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034A9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034AA0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034AA4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034AA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80034AAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034AB0: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x80034AB4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80034AB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80034ABC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80034AC0: jal         0x8003FC44
    // 0x80034AC4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_4;
    // 0x80034AC4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80034AC8: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034ACC: nop

L_80034AD0:
    // 0x80034AD0: beq         $t0, $zero, L_80034AE4
    if (ctx->r8 == 0) {
        // 0x80034AD4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034AE4;
    }
    // 0x80034AD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034AD8: jal         0x8000FFB8
    // 0x80034ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_5;
    // 0x80034ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80034AE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034AE4:
    // 0x80034AE4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034AE8: jr          $ra
    // 0x80034AEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80034AEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void level_properties_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C2E8: jr          $ra
    // 0x8006C2EC: sh          $zero, -0x2CD8($at)
    MEM_H(-0X2CD8, ctx->r1) = 0;
    return;
    // 0x8006C2EC: sh          $zero, -0x2CD8($at)
    MEM_H(-0X2CD8, ctx->r1) = 0;
;}
RECOMP_FUNC void reset_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EA5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006EA60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EA64: lw          $a0, 0x3510($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3510);
    // 0x8006EA68: jal         0x8006E770
    // 0x8006EA6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x8006EA6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8006EA70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006EA74: lw          $a0, 0x3510($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3510);
    // 0x8006EA78: jal         0x8006E994
    // 0x8006EA7C: nop

    clear_game_progress(rdram, ctx);
        goto after_1;
    // 0x8006EA7C: nop

    after_1:
    // 0x8006EA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EA88: jr          $ra
    // 0x8006EA8C: nop

    return;
    // 0x8006EA8C: nop

;}
RECOMP_FUNC void update_wizpig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005EA94: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005EA98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005EA9C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005EAA0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005EAA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005EAA8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005EAAC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005EAB0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005EAB4: jal         0x8005CA78
    // 0x8005EAB8: addiu       $a0, $a0, -0x31A0
    ctx->r4 = ADD32(ctx->r4, -0X31A0);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005EAB8: addiu       $a0, $a0, -0x31A0
    ctx->r4 = ADD32(ctx->r4, -0X31A0);
    after_0:
    // 0x8005EABC: sb          $zero, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = 0;
    // 0x8005EAC0: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EAC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EAC8: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005EACC: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8005EAD0: lwc1        $f7, 0x6AB0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6AB0);
    // 0x8005EAD4: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005EAD8: lh          $t8, 0x16A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16A);
    // 0x8005EADC: lwc1        $f6, 0x6AB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6AB4);
    // 0x8005EAE0: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005EAE4: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EAE8: nop

    // 0x8005EAEC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005EAF0: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005EAF4: nop

    // 0x8005EAF8: bc1f        L_8005EB20
    if (!c1cs) {
        // 0x8005EAFC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005EB20;
    }
    // 0x8005EAFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EB00: lwc1        $f9, 0x6AB8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6AB8);
    // 0x8005EB04: lwc1        $f8, 0x6ABC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6ABC);
    // 0x8005EB08: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005EB0C: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005EB10: nop

    // 0x8005EB14: bc1f        L_8005EB20
    if (!c1cs) {
        // 0x8005EB18: nop
    
            goto L_8005EB20;
    }
    // 0x8005EB18: nop

    // 0x8005EB1C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005EB20:
    // 0x8005EB20: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005EB24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EB28: bne         $t2, $at, L_8005EB5C
    if (ctx->r10 != ctx->r1) {
        // 0x8005EB2C: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005EB5C;
    }
    // 0x8005EB2C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EB30: jal         0x80023568
    // 0x8005EB34: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005EB34: nop

    after_1:
    // 0x8005EB38: beq         $v0, $zero, L_8005EB5C
    if (ctx->r2 == 0) {
        // 0x8005EB3C: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005EB5C;
    }
    // 0x8005EB3C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EB40: jal         0x80021400
    // 0x8005EB44: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005EB44: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005EB48: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005EB4C: nop

    // 0x8005EB50: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005EB54: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
    // 0x8005EB58: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_8005EB5C:
    // 0x8005EB5C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005EB60: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8005EB64: nop

    // 0x8005EB68: bne         $t1, $a0, L_8005EB74
    if (ctx->r9 != ctx->r4) {
        // 0x8005EB6C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005EB74;
    }
    // 0x8005EB6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EB70: sb          $zero, -0x2A00($at)
    MEM_B(-0X2A00, ctx->r1) = 0;
L_8005EB74:
    // 0x8005EB74: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005EB78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005EB7C: bne         $t0, $t5, L_8005EBF8
    if (ctx->r8 != ctx->r13) {
        // 0x8005EB80: sb          $zero, 0x1F5($s0)
        MEM_B(0X1F5, ctx->r16) = 0;
            goto L_8005EBF8;
    }
    // 0x8005EB80: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
    // 0x8005EB84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005EB88: nop

    // 0x8005EB8C: beq         $a0, $v0, L_8005EBF8
    if (ctx->r4 == ctx->r2) {
        // 0x8005EB90: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005EBF8;
    }
    // 0x8005EB90: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005EB94: bgez        $t6, L_8005EBF0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005EB98: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8005EBF0;
    }
    // 0x8005EB98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005EB9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005EBA0: lb          $t8, -0x29FF($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X29FF);
    // 0x8005EBA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005EBA8: bne         $t8, $zero, L_8005EBCC
    if (ctx->r24 != 0) {
        // 0x8005EBAC: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005EBCC;
    }
    // 0x8005EBAC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005EBB0: jal         0x8005CB04
    // 0x8005EBB4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005EBB4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x8005EBB8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EBBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EBC0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005EBC4: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005EBC8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005EBCC:
    // 0x8005EBCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005EBD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EBD4: sb          $t2, -0x29FF($at)
    MEM_B(-0X29FF, ctx->r1) = ctx->r10;
    // 0x8005EBD8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005EBDC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005EBE0: nop

    // 0x8005EBE4: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x8005EBE8: b           L_8005EBF8
    // 0x8005EBEC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8005EBF8;
    // 0x8005EBEC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005EBF0:
    // 0x8005EBF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005EBF4: sb          $zero, -0x29FF($at)
    MEM_B(-0X29FF, ctx->r1) = 0;
L_8005EBF8:
    // 0x8005EBF8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8005EBFC: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8005EC00: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005EC04: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005EC08: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EC0C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005EC10: jal         0x80049794
    // 0x8005EC14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005EC14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005EC18: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EC1C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EC20: lb          $t6, 0x1D7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005EC24: nop

    // 0x8005EC28: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005EC2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005EC30: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005EC34: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005EC38: nop

    // 0x8005EC3C: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
    // 0x8005EC40: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005EC44: nop

    // 0x8005EC48: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005EC4C: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005EC50: nop

    // 0x8005EC54: sh          $t9, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r25;
    // 0x8005EC58: lb          $t2, 0x187($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X187);
    // 0x8005EC5C: nop

    // 0x8005EC60: beq         $t2, $zero, L_8005ED00
    if (ctx->r10 == 0) {
        // 0x8005EC64: nop
    
            goto L_8005ED00;
    }
    // 0x8005EC64: nop

    // 0x8005EC68: lb          $t3, 0x3B($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EC6C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005EC70: beq         $t3, $at, L_8005ED00
    if (ctx->r11 == ctx->r1) {
        // 0x8005EC74: nop
    
            goto L_8005ED00;
    }
    // 0x8005EC74: nop

    // 0x8005EC78: jal         0x8005CB04
    // 0x8005EC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005EC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005EC80: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005EC84: jal         0x80001D04
    // 0x8005EC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005EC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005EC8C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005EC90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EC94: jal         0x80069F28
    // 0x8005EC98: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005EC98: nop

    after_7:
    // 0x8005EC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ECA0: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005ECA4: lwc1        $f1, 0x6AC0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6AC0);
    // 0x8005ECA8: lwc1        $f0, 0x6AC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6AC4);
    // 0x8005ECAC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005ECB0: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005ECB4: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005ECB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005ECBC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005ECC0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005ECC4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005ECC8: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005ECCC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005ECD0: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8005ECD4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005ECD8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005ECDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005ECE0: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8005ECE4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005ECE8: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005ECEC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005ECF0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005ECF4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005ECF8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005ECFC: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_8005ED00:
    // 0x8005ED00: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005ED04: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005ED08: beq         $t5, $zero, L_8005ED70
    if (ctx->r13 == 0) {
        // 0x8005ED0C: nop
    
            goto L_8005ED70;
    }
    // 0x8005ED0C: nop

    // 0x8005ED10: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005ED14: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005ED18: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005ED1C: nop

    // 0x8005ED20: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005ED24: nop

    // 0x8005ED28: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005ED2C: nop

    // 0x8005ED30: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005ED34: jal         0x800C9AD0
    // 0x8005ED38: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005ED38: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005ED3C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005ED40: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005ED44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005ED48: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005ED4C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005ED50: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005ED54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005ED58: bc1f        L_8005ED70
    if (!c1cs) {
        // 0x8005ED5C: swc1        $f2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
            goto L_8005ED70;
    }
    // 0x8005ED5C: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005ED60: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005ED64: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8005ED68: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8005ED6C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
L_8005ED70:
    // 0x8005ED70: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005ED74: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005ED78: jal         0x8001BA1C
    // 0x8005ED7C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005ED7C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    after_9:
    // 0x8005ED80: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005ED84: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x8005ED88: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005ED8C: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005ED90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005ED94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005ED98: bne         $t1, $t8, L_8005EDAC
    if (ctx->r9 != ctx->r24) {
        // 0x8005ED9C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005EDAC;
    }
    // 0x8005ED9C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005EDA0: sll         $a2, $t1, 16
    ctx->r6 = S32(ctx->r9 << 16);
    // 0x8005EDA4: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005EDA8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8005EDAC:
    // 0x8005EDAC: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x8005EDB0: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005EDB4: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8005EDB8: sh          $t3, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r11;
    // 0x8005EDBC: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x8005EDC0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EDC4: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005EDC8: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8005EDCC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005EDD0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EDD4: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005EDD8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8005EDDC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8005EDE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005EDE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EDE8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005EDEC: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005EDF0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005EDF4: lwc1        $f5, 0x6AC8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AC8);
    // 0x8005EDF8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005EDFC: lwc1        $f4, 0x6ACC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ACC);
    // 0x8005EE00: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8005EE04: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005EE08: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8005EE0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005EE10: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EE14: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005EE18: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x8005EE1C: nop

    // 0x8005EE20: bc1f        L_8005EE50
    if (!c1cs) {
        // 0x8005EE24: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005EE50;
    }
    // 0x8005EE24: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EE28: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005EE2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005EE30: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EE34: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005EE38: nop

    // 0x8005EE3C: bc1f        L_8005EE78
    if (!c1cs) {
        // 0x8005EE40: nop
    
            goto L_8005EE78;
    }
    // 0x8005EE40: nop

    // 0x8005EE44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EE48: b           L_8005EE7C
    // 0x8005EE4C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005EE7C;
    // 0x8005EE4C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005EE50:
    // 0x8005EE50: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EE54: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005EE58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005EE5C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EE60: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005EE64: nop

    // 0x8005EE68: bc1f        L_8005EE78
    if (!c1cs) {
        // 0x8005EE6C: nop
    
            goto L_8005EE78;
    }
    // 0x8005EE6C: nop

    // 0x8005EE70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EE74: nop

L_8005EE78:
    // 0x8005EE78: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005EE7C:
    // 0x8005EE7C: beq         $at, $zero, L_8005EFBC
    if (ctx->r1 == 0) {
        // 0x8005EE80: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_8005EFBC;
    }
    // 0x8005EE80: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8005EE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EE88: addu        $at, $at, $t3
    gpr jr_addend_8005EE94 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8005EE8C: lw          $t3, 0x6AD0($at)
    ctx->r11 = ADD32(ctx->r1, 0X6AD0);
    // 0x8005EE90: nop

    // 0x8005EE94: jr          $t3
    // 0x8005EE98: nop

    switch (jr_addend_8005EE94 >> 2) {
        case 0: goto L_8005EE9C; break;
        case 1: goto L_8005EEC0; break;
        case 2: goto L_8005EEF8; break;
        case 3: goto L_8005EF14; break;
        case 4: goto L_8005EF6C; break;
        case 5: goto L_8005EF98; break;
        default: switch_error(__func__, 0x8005EE94, 0x800E6AD0);
    }
    // 0x8005EE98: nop

L_8005EE9C:
    // 0x8005EE9C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EEA0: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8005EEA4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005EEA8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005EEAC: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005EEB0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005EEB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005EEB8: b           L_8005EFC0
    // 0x8005EEBC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005EFC0;
    // 0x8005EEBC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005EEC0:
    // 0x8005EEC0: lbu         $t4, 0x1CD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005EEC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005EEC8: bne         $a0, $t4, L_8005EEE4
    if (ctx->r4 != ctx->r12) {
        // 0x8005EECC: nop
    
            goto L_8005EEE4;
    }
    // 0x8005EECC: nop

    // 0x8005EED0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EED4: nop

    // 0x8005EED8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8005EEDC: b           L_8005EFC0
    // 0x8005EEE0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005EFC0;
    // 0x8005EEE0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005EEE4:
    // 0x8005EEE4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EEE8: nop

    // 0x8005EEEC: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8005EEF0: b           L_8005EFC0
    // 0x8005EEF4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005EFC0;
    // 0x8005EEF4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005EEF8:
    // 0x8005EEF8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EEFC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005EF00: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8005EF04: sb          $t5, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r13;
    // 0x8005EF08: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005EF0C: b           L_8005EFC0
    // 0x8005EF10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005EFC0;
    // 0x8005EF10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005EF14:
    // 0x8005EF14: lbu         $t6, 0x1CD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005EF18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005EF1C: bne         $t6, $at, L_8005EF48
    if (ctx->r14 != ctx->r1) {
        // 0x8005EF20: nop
    
            goto L_8005EF48;
    }
    // 0x8005EF20: nop

    // 0x8005EF24: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EF28: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005EF2C: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005EF30: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005EF34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005EF38: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005EF3C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8005EF40: b           L_8005EFC0
    // 0x8005EF44: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005EFC0;
    // 0x8005EF44: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005EF48:
    // 0x8005EF48: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EF4C: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005EF50: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8005EF54: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005EF58: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005EF5C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005EF60: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005EF64: b           L_8005EFC0
    // 0x8005EF68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005EFC0;
    // 0x8005EF68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005EF6C:
    // 0x8005EF6C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EF70: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005EF74: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8005EF78: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005EF7C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005EF80: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005EF84: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005EF88: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EF8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005EF90: b           L_8005EFC0
    // 0x8005EF94: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005EFC0;
    // 0x8005EF94: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005EF98:
    // 0x8005EF98: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EF9C: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005EFA0: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8005EFA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005EFA8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EFAC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005EFB0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005EFB4: b           L_8005EFC0
    // 0x8005EFB8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005EFC0;
    // 0x8005EFB8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005EFBC:
    // 0x8005EFBC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005EFC0:
    // 0x8005EFC0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EFC4: nop

    // 0x8005EFC8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005EFCC: nop

    // 0x8005EFD0: bc1f        L_8005EFFC
    if (!c1cs) {
        // 0x8005EFD4: nop
    
            goto L_8005EFFC;
    }
    // 0x8005EFD4: nop

L_8005EFD8:
    // 0x8005EFD8: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005EFDC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005EFE0: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005EFE4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005EFE8: nop

    // 0x8005EFEC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005EFF0: nop

    // 0x8005EFF4: bc1t        L_8005EFD8
    if (c1cs) {
        // 0x8005EFF8: nop
    
            goto L_8005EFD8;
    }
    // 0x8005EFF8: nop

L_8005EFFC:
    // 0x8005EFFC: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F000: nop

    // 0x8005F004: bc1f        L_8005F030
    if (!c1cs) {
        // 0x8005F008: nop
    
            goto L_8005F030;
    }
    // 0x8005F008: nop

L_8005F00C:
    // 0x8005F00C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F010: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005F014: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005F018: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F01C: nop

    // 0x8005F020: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F024: nop

    // 0x8005F028: bc1t        L_8005F00C
    if (c1cs) {
        // 0x8005F02C: nop
    
            goto L_8005F00C;
    }
    // 0x8005F02C: nop

L_8005F030:
    // 0x8005F030: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F034: nop

    // 0x8005F038: bne         $a0, $v1, L_8005F058
    if (ctx->r4 != ctx->r3) {
        // 0x8005F03C: nop
    
            goto L_8005F058;
    }
    // 0x8005F03C: nop

    // 0x8005F040: beq         $a2, $zero, L_8005F058
    if (ctx->r6 == 0) {
        // 0x8005F044: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8005F058;
    }
    // 0x8005F044: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F048: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F04C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F050: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F054: nop

L_8005F058:
    // 0x8005F058: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F05C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F060: beq         $t0, $t8, L_8005F070
    if (ctx->r8 == ctx->r24) {
        // 0x8005F064: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005F070;
    }
    // 0x8005F064: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005F068: bne         $v1, $zero, L_8005F1E4
    if (ctx->r3 != 0) {
        // 0x8005F06C: nop
    
            goto L_8005F1E4;
    }
    // 0x8005F06C: nop

L_8005F070:
    // 0x8005F070: bne         $v1, $at, L_8005F094
    if (ctx->r3 != ctx->r1) {
        // 0x8005F074: nop
    
            goto L_8005F094;
    }
    // 0x8005F074: nop

    // 0x8005F078: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F07C: nop

    // 0x8005F080: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005F084: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F088: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F08C: b           L_8005F1E8
    // 0x8005F090: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F1E8;
    // 0x8005F090: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F094:
    // 0x8005F094: bne         $t1, $v1, L_8005F0C4
    if (ctx->r9 != ctx->r3) {
        // 0x8005F098: nop
    
            goto L_8005F0C4;
    }
    // 0x8005F098: nop

    // 0x8005F09C: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F0A0: nop

    // 0x8005F0A4: bne         $t2, $zero, L_8005F0B4
    if (ctx->r10 != 0) {
        // 0x8005F0A8: nop
    
            goto L_8005F0B4;
    }
    // 0x8005F0A8: nop

    // 0x8005F0AC: b           L_8005F0B8
    // 0x8005F0B0: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F0B8;
    // 0x8005F0B0: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F0B4:
    // 0x8005F0B4: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F0B8:
    // 0x8005F0B8: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F0BC: b           L_8005F1E8
    // 0x8005F0C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F1E8;
    // 0x8005F0C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F0C4:
    // 0x8005F0C4: bne         $a3, $v1, L_8005F0F4
    if (ctx->r7 != ctx->r3) {
        // 0x8005F0C8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F0F4;
    }
    // 0x8005F0C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F0CC: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F0D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F0D4: bne         $t3, $at, L_8005F0E4
    if (ctx->r11 != ctx->r1) {
        // 0x8005F0D8: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F0E4;
    }
    // 0x8005F0D8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F0DC: b           L_8005F0E8
    // 0x8005F0E0: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F0E8;
    // 0x8005F0E0: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F0E4:
    // 0x8005F0E4: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
L_8005F0E8:
    // 0x8005F0E8: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F0EC: b           L_8005F1E8
    // 0x8005F0F0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F1E8;
    // 0x8005F0F0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F0F4:
    // 0x8005F0F4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005F0F8: lwc1        $f11, 0x6AE8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6AE8);
    // 0x8005F0FC: lwc1        $f10, 0x6AEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6AEC);
    // 0x8005F100: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8005F104: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005F108: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F10C: bc1f        L_8005F180
    if (!c1cs) {
        // 0x8005F110: nop
    
            goto L_8005F180;
    }
    // 0x8005F110: nop

    // 0x8005F114: lwc1        $f5, 0x6AF0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AF0);
    // 0x8005F118: lwc1        $f4, 0x6AF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AF4);
    // 0x8005F11C: nop

    // 0x8005F120: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005F124: nop

    // 0x8005F128: bc1f        L_8005F180
    if (!c1cs) {
        // 0x8005F12C: nop
    
            goto L_8005F180;
    }
    // 0x8005F12C: nop

    // 0x8005F130: bne         $a0, $v1, L_8005F170
    if (ctx->r4 != ctx->r3) {
        // 0x8005F134: nop
    
            goto L_8005F170;
    }
    // 0x8005F134: nop

    // 0x8005F138: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F13C: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F140: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005F144: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005F148: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005F14C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005F150: nop

    // 0x8005F154: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005F158: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005F15C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8005F160: nop

    // 0x8005F164: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005F168: b           L_8005F174
    // 0x8005F16C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005F174;
    // 0x8005F16C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005F170:
    // 0x8005F170: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F174:
    // 0x8005F174: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F178: b           L_8005F1E8
    // 0x8005F17C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F1E8;
    // 0x8005F17C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F180:
    // 0x8005F180: bne         $v1, $zero, L_8005F198
    if (ctx->r3 != 0) {
        // 0x8005F184: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005F198;
    }
    // 0x8005F184: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F188: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F18C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F190: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F194: nop

L_8005F198:
    // 0x8005F198: bne         $v1, $at, L_8005F1E4
    if (ctx->r3 != ctx->r1) {
        // 0x8005F19C: nop
    
            goto L_8005F1E4;
    }
    // 0x8005F19C: nop

    // 0x8005F1A0: bne         $a2, $zero, L_8005F1E4
    if (ctx->r6 != 0) {
        // 0x8005F1A4: nop
    
            goto L_8005F1E4;
    }
    // 0x8005F1A4: nop

    // 0x8005F1A8: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F1AC: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1B0: lw          $t4, 0x44($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X44);
    // 0x8005F1B4: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x8005F1B8: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F1BC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005F1C0: nop

    // 0x8005F1C4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005F1C8: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005F1CC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8005F1D0: nop

    // 0x8005F1D4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005F1D8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005F1DC: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1E0: nop

L_8005F1E4:
    // 0x8005F1E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F1E8:
    // 0x8005F1E8: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005F1EC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005F1F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F1F4: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8005F1F8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F1FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F200: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005F204: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005F208: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005F20C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8005F210: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005F214: bne         $a0, $v1, L_8005F238
    if (ctx->r4 != ctx->r3) {
        // 0x8005F218: sh          $t4, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r12;
            goto L_8005F238;
    }
    // 0x8005F218: sh          $t4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r12;
    // 0x8005F21C: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F220: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005F224: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005F228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F22C: jal         0x800113CC
    // 0x8005F230: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005F230: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005F234: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005F238:
    // 0x8005F238: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005F23C: nop

    // 0x8005F240: bne         $t0, $t7, L_8005F274
    if (ctx->r8 != ctx->r15) {
        // 0x8005F244: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_8005F274;
    }
    // 0x8005F244: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F248: jal         0x80023568
    // 0x8005F24C: nop

    func_80023568(rdram, ctx);
        goto after_11;
    // 0x8005F24C: nop

    after_11:
    // 0x8005F250: beq         $v0, $zero, L_8005F270
    if (ctx->r2 == 0) {
        // 0x8005F254: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005F270;
    }
    // 0x8005F254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F258: addiu       $t8, $zero, 0xA5
    ctx->r24 = ADD32(0, 0XA5);
    // 0x8005F25C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005F260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F264: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005F268: jal         0x8005E204
    // 0x8005F26C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_12;
    // 0x8005F26C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_12:
L_8005F270:
    // 0x8005F270: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_8005F274:
    // 0x8005F274: jal         0x800AFC3C
    // 0x8005F278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_13;
    // 0x8005F278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8005F27C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F280: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F284: jal         0x8005D048
    // 0x8005F288: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_14;
    // 0x8005F288: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_14:
    // 0x8005F28C: jal         0x8001BAC8
    // 0x8005F290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_15;
    // 0x8005F290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8005F294: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F298: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x8005F29C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F2A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F2A4: bne         $s1, $t9, L_8005F2D4
    if (ctx->r17 != ctx->r25) {
        // 0x8005F2A8: addiu       $a1, $a1, -0x2A00
        ctx->r5 = ADD32(ctx->r5, -0X2A00);
            goto L_8005F2D4;
    }
    // 0x8005F2A8: addiu       $a1, $a1, -0x2A00
    ctx->r5 = ADD32(ctx->r5, -0X2A00);
    // 0x8005F2AC: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F2B0: nop

    // 0x8005F2B4: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F2B8: beq         $t3, $zero, L_8005F2D4
    if (ctx->r11 == 0) {
        // 0x8005F2BC: nop
    
            goto L_8005F2D4;
    }
    // 0x8005F2BC: nop

    // 0x8005F2C0: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F2C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F2C8: bne         $t6, $at, L_8005F2D4
    if (ctx->r14 != ctx->r1) {
        // 0x8005F2CC: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F2D4;
    }
    // 0x8005F2CC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F2D0: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005F2D4:
    // 0x8005F2D4: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005F2D8: nop

    // 0x8005F2DC: beq         $t5, $zero, L_8005F300
    if (ctx->r13 == 0) {
        // 0x8005F2E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F300;
    }
    // 0x8005F2E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F2E4: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005F2E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F2EC: bne         $t7, $zero, L_8005F2FC
    if (ctx->r15 != 0) {
        // 0x8005F2F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005F2FC;
    }
    // 0x8005F2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F2F4: jal         0x8005CB68
    // 0x8005F2F8: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005F2F8: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005F2FC:
    // 0x8005F2FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F300:
    // 0x8005F300: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F304: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005F308: jr          $ra
    // 0x8005F30C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F30C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void level_name(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; if (dkr_legacy_track_menu(rdram, ctx, 9U, dkr_legacy_fields, 0U)) return; }
    // 0x8006BDDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006BDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BDE4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006BDE8: bltz        $a0, L_8006BE08
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006BDEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006BE08;
    }
    // 0x8006BDEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006BDF0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BDF4: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006BDF8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006BDFC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006BE00: bne         $at, $zero, L_8006BE10
    if (ctx->r1 != 0) {
        // 0x8006BE04: nop
    
            goto L_8006BE10;
    }
    // 0x8006BE04: nop

L_8006BE08:
    // 0x8006BE08: b           L_8006BEEC
    // 0x8006BE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006BEEC;
    // 0x8006BE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006BE10:
    // 0x8006BE10: lw          $t7, 0x116C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X116C);
    // 0x8006BE14: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8006BE18: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006BE1C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8006BE20: sb          $v1, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r3;
    // 0x8006BE24: jal         0x8009EB20
    // 0x8006BE28: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_language(rdram, ctx);
        goto after_0;
    // 0x8006BE28: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006BE2C: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
    // 0x8006BE30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BE34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006BE38: beq         $v0, $at, L_8006BE58
    if (ctx->r2 == ctx->r1) {
        // 0x8006BE3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006BE58;
    }
    // 0x8006BE3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006BE40: beq         $v0, $at, L_8006BE88
    if (ctx->r2 == ctx->r1) {
        // 0x8006BE44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006BE88;
    }
    // 0x8006BE44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006BE48: beq         $v0, $at, L_8006BEBC
    if (ctx->r2 == ctx->r1) {
        // 0x8006BE4C: nop
    
            goto L_8006BEBC;
    }
    // 0x8006BE4C: nop

    // 0x8006BE50: b           L_8006BEEC
    // 0x8006BE54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006BEEC;
    // 0x8006BE54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006BE58:
    // 0x8006BE58: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BE5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006BE60: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BE64: beq         $t0, $zero, L_8006BE78
    if (ctx->r8 == 0) {
        // 0x8006BE68: nop
    
            goto L_8006BE78;
    }
    // 0x8006BE68: nop

    // 0x8006BE6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006BE70: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8006BE74: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8006BE78:
    // 0x8006BE78: blez        $v1, L_8006BE58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006BE7C: nop
    
            goto L_8006BE58;
    }
    // 0x8006BE7C: nop

    // 0x8006BE80: b           L_8006BEEC
    // 0x8006BE84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006BEEC;
    // 0x8006BE84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006BE88:
    // 0x8006BE88: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BE8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006BE90: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BE94: beq         $t2, $zero, L_8006BEAC
    if (ctx->r10 == 0) {
        // 0x8006BE98: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8006BEAC;
    }
    // 0x8006BE98: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006BE9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006BEA0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8006BEA4: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8006BEA8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_8006BEAC:
    // 0x8006BEAC: bne         $at, $zero, L_8006BE88
    if (ctx->r1 != 0) {
        // 0x8006BEB0: nop
    
            goto L_8006BE88;
    }
    // 0x8006BEB0: nop

    // 0x8006BEB4: b           L_8006BEEC
    // 0x8006BEB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006BEEC;
    // 0x8006BEB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006BEBC:
    // 0x8006BEBC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BEC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006BEC4: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BEC8: beq         $t4, $zero, L_8006BEE0
    if (ctx->r12 == 0) {
        // 0x8006BECC: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8006BEE0;
    }
    // 0x8006BECC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8006BED0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006BED4: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8006BED8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8006BEDC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_8006BEE0:
    // 0x8006BEE0: bne         $at, $zero, L_8006BEBC
    if (ctx->r1 != 0) {
        // 0x8006BEE4: nop
    
            goto L_8006BEBC;
    }
    // 0x8006BEE4: nop

    // 0x8006BEE8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006BEEC:
    // 0x8006BEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006BEF4: jr          $ra
    // 0x8006BEF8: nop

    return;
    // 0x8006BEF8: nop

;}
RECOMP_FUNC void second_racer_camera_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800580B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800580B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800580BC: lw          $t6, -0x2AA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AA4);
    // 0x800580C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800580C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800580C8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800580CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800580D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800580D4: beq         $t6, $at, L_800581D8
    if (ctx->r14 == ctx->r1) {
        // 0x800580D8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_800581D8;
    }
    // 0x800580D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800580DC: lb          $t7, 0x1D8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D8);
    // 0x800580E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800580E4: beq         $t7, $at, L_800581D8
    if (ctx->r15 == ctx->r1) {
        // 0x800580E8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800581D8;
    }
    // 0x800580E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800580EC: addiu       $v1, $v1, -0x2AF8
    ctx->r3 = ADD32(ctx->r3, -0X2AF8);
    // 0x800580F0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800580F4: nop

    // 0x800580F8: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x800580FC: nop

    // 0x80058100: beq         $a2, $t9, L_800581DC
    if (ctx->r6 == ctx->r25) {
        // 0x80058104: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800581DC;
    }
    // 0x80058104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058108: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005810C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80058110: jal         0x80057A40
    // 0x80058114: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    update_player_camera(rdram, ctx);
        goto after_0;
    // 0x80058114: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80058118: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005811C: addiu       $v1, $v1, -0x2AF8
    ctx->r3 = ADD32(ctx->r3, -0X2AF8);
    // 0x80058120: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80058124: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80058128: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005812C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80058130: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80058134: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058138: nop

    // 0x8005813C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80058140: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80058144: nop

    // 0x80058148: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8005814C: sh          $a3, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r7;
    // 0x80058150: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80058154: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80058158: jal         0x80057A40
    // 0x8005815C: nop

    update_player_camera(rdram, ctx);
        goto after_1;
    // 0x8005815C: nop

    after_1:
    // 0x80058160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058164: lw          $t0, -0x2AC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC0);
    // 0x80058168: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005816C: bne         $t0, $zero, L_800581D8
    if (ctx->r8 != 0) {
        // 0x80058170: addiu       $v1, $v1, -0x2AF8
        ctx->r3 = ADD32(ctx->r3, -0X2AF8);
            goto L_800581D8;
    }
    // 0x80058170: addiu       $v1, $v1, -0x2AF8
    ctx->r3 = ADD32(ctx->r3, -0X2AF8);
    // 0x80058174: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80058178: lb          $t1, -0x2A7E($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2A7E);
    // 0x8005817C: nop

    // 0x80058180: bne         $t1, $zero, L_800581DC
    if (ctx->r9 != 0) {
        // 0x80058184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800581DC;
    }
    // 0x80058184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058188: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005818C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80058190: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80058194: nop

    // 0x80058198: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005819C: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x800581A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800581A4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800581A8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800581AC: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800581B0: nop

    // 0x800581B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800581B8: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800581BC: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x800581C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800581C4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800581C8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800581CC: nop

    // 0x800581D0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800581D4: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
L_800581D8:
    // 0x800581D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800581DC:
    // 0x800581DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800581E0: jr          $ra
    // 0x800581E4: nop

    return;
    // 0x800581E4: nop

;}
RECOMP_FUNC void get_misc_asset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E29C: bltz        $a0, L_8001E2B8
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E2A0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E2B8;
    }
    // 0x8001E2A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E2A4: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x8001E2A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E2AC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001E2B0: bne         $at, $zero, L_8001E2C8
    if (ctx->r1 != 0) {
        // 0x8001E2B4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8001E2C8;
    }
    // 0x8001E2B4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_8001E2B8:
    // 0x8001E2B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E2BC: lw          $v0, -0x5294($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5294);
    // 0x8001E2C0: jr          $ra
    // 0x8001E2C4: nop

    return;
    // 0x8001E2C4: nop

L_8001E2C8:
    // 0x8001E2C8: lw          $t7, -0x5290($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5290);
    // 0x8001E2CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001E2D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E2D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001E2D8: lw          $t2, -0x5294($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5294);
    // 0x8001E2DC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001E2E0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001E2E4: jr          $ra
    // 0x8001E2E8: nop

    return;
    // 0x8001E2E8: nop

;}
RECOMP_FUNC void alCSPPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C85A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C85A8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800C85AC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C85B0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C85B4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C85B8: jal         0x800C91AC
    // 0x800C85BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C85BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C85C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C85C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C85C8: jr          $ra
    // 0x800C85CC: nop

    return;
    // 0x800C85CC: nop

;}
RECOMP_FUNC void obj_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9B4: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x8000E9B8: jr          $ra
    // 0x8000E9BC: nop

    return;
    // 0x8000E9BC: nop

;}
RECOMP_FUNC void update_colour_cycle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F24C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F254: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F258: bne         $at, $zero, L_8007F40C
    if (ctx->r1 != 0) {
        // 0x8007F25C: nop
    
            goto L_8007F40C;
    }
    // 0x8007F25C: nop

    // 0x8007F260: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8007F264: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8007F268: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F26C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F270: bne         $at, $zero, L_8007F28C
    if (ctx->r1 != 0) {
        // 0x8007F274: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_8007F28C;
    }
    // 0x8007F274: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8007F278:
    // 0x8007F278: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F27C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F280: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007F284: beq         $at, $zero, L_8007F278
    if (ctx->r1 == 0) {
        // 0x8007F288: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8007F278;
    }
    // 0x8007F288: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007F28C:
    // 0x8007F28C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8007F290: nop

    // 0x8007F294: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8007F298: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F29C: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8007F2A0: nop

    // 0x8007F2A4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F2A8: bne         $at, $zero, L_8007F2F8
    if (ctx->r1 != 0) {
        // 0x8007F2AC: nop
    
            goto L_8007F2F8;
    }
    // 0x8007F2AC: nop

L_8007F2B0:
    // 0x8007F2B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F2B4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8007F2B8: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F2BC: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007F2C0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8007F2C4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F2C8: bne         $at, $zero, L_8007F2D8
    if (ctx->r1 != 0) {
        // 0x8007F2CC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8007F2D8;
    }
    // 0x8007F2CC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8007F2D0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F2D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007F2D8:
    // 0x8007F2D8: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8007F2DC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007F2E0: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    // 0x8007F2E4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8007F2E8: nop

    // 0x8007F2EC: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F2F0: beq         $at, $zero, L_8007F2B0
    if (ctx->r1 == 0) {
        // 0x8007F2F4: nop
    
            goto L_8007F2B0;
    }
    // 0x8007F2F4: nop

L_8007F2F8:
    // 0x8007F2F8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007F2FC: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x8007F300: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007F304: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007F308: bne         $at, $zero, L_8007F314
    if (ctx->r1 != 0) {
        // 0x8007F30C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8007F314;
    }
    // 0x8007F30C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007F310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8007F314:
    // 0x8007F314: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8007F318: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F31C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8007F320: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8007F324: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007F328: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x8007F32C: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F330: lbu         $t0, 0x14($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X14);
    // 0x8007F334: lbu         $t4, 0x14($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X14);
    // 0x8007F338: lbu         $t6, 0x15($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X15);
    // 0x8007F33C: subu        $t9, $t4, $t0
    ctx->r25 = SUB32(ctx->r12, ctx->r8);
    // 0x8007F340: lbu         $t1, 0x15($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X15);
    // 0x8007F344: lbu         $t2, 0x16($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X16);
    // 0x8007F348: lbu         $t3, 0x17($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X17);
    // 0x8007F34C: bne         $t8, $zero, L_8007F358
    if (ctx->r24 != 0) {
        // 0x8007F350: nop
    
            goto L_8007F358;
    }
    // 0x8007F350: nop

    // 0x8007F354: break       7
    do_break(2148004692);
L_8007F358:
    // 0x8007F358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F35C: bne         $t8, $at, L_8007F370
    if (ctx->r24 != ctx->r1) {
        // 0x8007F360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F370;
    }
    // 0x8007F360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F364: bne         $t7, $at, L_8007F370
    if (ctx->r15 != ctx->r1) {
        // 0x8007F368: nop
    
            goto L_8007F370;
    }
    // 0x8007F368: nop

    // 0x8007F36C: break       6
    do_break(2148004716);
L_8007F370:
    // 0x8007F370: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8007F374: lbu         $t7, 0x16($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X16);
    // 0x8007F378: nop

    // 0x8007F37C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007F380: lbu         $t8, 0x17($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X17);
    // 0x8007F384: nop

    // 0x8007F388: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8007F38C: mflo        $a1
    ctx->r5 = lo;
    // 0x8007F390: nop

    // 0x8007F394: nop

    // 0x8007F398: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F39C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F3A0: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8007F3A4: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8007F3A8: sb          $t8, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r24;
    // 0x8007F3AC: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8007F3B0: nop

    // 0x8007F3B4: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x8007F3B8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F3BC: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F3C0: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8007F3C4: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8007F3C8: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x8007F3CC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F3D0: nop

    // 0x8007F3D4: subu        $t7, $t6, $t2
    ctx->r15 = SUB32(ctx->r14, ctx->r10);
    // 0x8007F3D8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F3DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8007F3E0: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x8007F3E4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8007F3E8: sb          $t6, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r14;
    // 0x8007F3EC: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007F3F0: nop

    // 0x8007F3F4: subu        $t8, $t7, $t3
    ctx->r24 = SUB32(ctx->r15, ctx->r11);
    // 0x8007F3F8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F3FC: mflo        $t9
    ctx->r25 = lo;
    // 0x8007F400: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8007F404: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007F408: sb          $t7, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r15;
L_8007F40C:
    // 0x8007F40C: jr          $ra
    // 0x8007F410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void handle_menu_joystick_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D26C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D270: lb          $v0, 0x6464($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6464);
    // 0x8009D274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D278: bgez        $v0, L_8009D2A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D27C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009D2A8;
    }
    // 0x8009D27C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D280: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D284: addiu       $v0, $v0, 0x64D8
    ctx->r2 = ADD32(ctx->r2, 0X64D8);
    // 0x8009D288: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D28C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D290: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D294: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D298: jal         0x80001D04
    // 0x8009D29C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8009D29C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009D2A0: b           L_8009D2CC
    // 0x8009D2A4: nop

        goto L_8009D2CC;
    // 0x8009D2A4: nop

L_8009D2A8:
    // 0x8009D2A8: blez        $v0, L_8009D2CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009D2AC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8009D2CC;
    }
    // 0x8009D2AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009D2B0: lb          $t8, 0x64D8($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X64D8);
    // 0x8009D2B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D2B8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8009D2BC: sb          $t9, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = ctx->r25;
    // 0x8009D2C0: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D2C4: jal         0x80001D04
    // 0x8009D2C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8009D2C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8009D2CC:
    // 0x8009D2CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D2D0: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009D2D4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D2D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009D2DC: bgez        $v0, L_8009D2FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D2E0: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8009D2FC;
    }
    // 0x8009D2E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009D2E4: lb          $t0, 0x6504($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6504);
    // 0x8009D2E8: nop

    // 0x8009D2EC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8009D2F0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8009D2F4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D2F8: nop

L_8009D2FC:
    // 0x8009D2FC: lb          $t2, 0x6504($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6504);
    // 0x8009D300: nop

    // 0x8009D304: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009D308: bne         $at, $zero, L_8009D318
    if (ctx->r1 != 0) {
        // 0x8009D30C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009D318;
    }
    // 0x8009D30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D310: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009D314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009D318:
    // 0x8009D318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D31C: jr          $ra
    // 0x8009D320: nop

    return;
    // 0x8009D320: nop

;}
RECOMP_FUNC void get_contpak_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E0B4: lw          $t6, -0x52C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X52C8);
    // 0x8000E0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E0BC: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8000E0C0: beq         $at, $zero, L_8000E114
    if (ctx->r1 == 0) {
        // 0x8000E0C4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E114;
    }
    // 0x8000E0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E0C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E0CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E0D0: addu        $at, $at, $t6
    gpr jr_addend_8000E0DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E0D4: lw          $t6, 0x5188($at)
    ctx->r14 = ADD32(ctx->r1, 0X5188);
    // 0x8000E0D8: nop

    // 0x8000E0DC: jr          $t6
    // 0x8000E0E0: nop

    switch (jr_addend_8000E0DC >> 2) {
        case 0: goto L_8000E104; break;
        case 1: goto L_8000E0E4; break;
        case 2: goto L_8000E0F4; break;
        case 3: goto L_8000E0F4; break;
        case 4: goto L_8000E0FC; break;
        case 5: goto L_8000E104; break;
        case 6: goto L_8000E0FC; break;
        case 7: goto L_8000E0EC; break;
        case 8: goto L_8000E104; break;
        default: switch_error(__func__, 0x8000E0DC, 0x800E5188);
    }
    // 0x8000E0E0: nop

L_8000E0E4:
    // 0x8000E0E4: b           L_8000E118
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E118;
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E0EC:
    // 0x8000E0EC: b           L_8000E118
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E118;
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E0F4:
    // 0x8000E0F4: b           L_8000E118
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8000E118;
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000E0FC:
    // 0x8000E0FC: b           L_8000E118
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000E118;
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000E104:
    // 0x8000E104: jal         0x80059E20
    // 0x8000E108: nop

    timetrial_ghost_full(rdram, ctx);
        goto after_0;
    // 0x8000E108: nop

    after_0:
    // 0x8000E10C: b           L_8000E11C
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000E11C;
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E114:
    // 0x8000E114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E118:
    // 0x8000E118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E11C:
    // 0x8000E11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E120: jr          $ra
    // 0x8000E124: nop

    return;
    // 0x8000E124: nop

;}
RECOMP_FUNC void menu_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CA60: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CA64: addiu       $t3, $t3, -0x8A4
    ctx->r11 = ADD32(ctx->r11, -0X8A4);
    // 0x8009CA68: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009CA6C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8009CA70: sll         $t0, $a0, 5
    ctx->r8 = S32(ctx->r4 << 5);
    // 0x8009CA74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CA78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009CA7C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009CA80: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8009CA84: lh          $a1, 0x6($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X6);
    // 0x8009CA88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009CA8C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8009CA90: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8009CA94: lw          $t2, 0x6550($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6550);
    // 0x8009CA98: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009CA9C: beq         $t2, $zero, L_8009CD70
    if (ctx->r10 == 0) {
        // 0x8009CAA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CD70;
    }
    // 0x8009CAA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CAA4: lw          $t9, -0x8B0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X8B0);
    // 0x8009CAA8: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x8009CAAC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8009CAB0: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009CAB4: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CAB8: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x8009CABC: beq         $t6, $at, L_8009CD6C
    if (ctx->r14 == ctx->r1) {
        // 0x8009CAC0: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_8009CD6C;
    }
    // 0x8009CAC0: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8009CAC4: beq         $t7, $zero, L_8009CB64
    if (ctx->r15 == 0) {
        // 0x8009CAC8: andi        $t5, $v0, 0x8000
        ctx->r13 = ctx->r2 & 0X8000;
            goto L_8009CB64;
    }
    // 0x8009CAC8: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x8009CACC: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009CAD0: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8009CAD4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8009CAD8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009CADC: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8009CAE0: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8009CAE4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009CAE8: sh          $t5, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r13;
    // 0x8009CAEC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009CAF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009CAF4: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x8009CAF8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009CAFC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009CB00: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8009CB04: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009CB08: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8009CB0C: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009CB10: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009CB14: addiu       $a0, $s0, 0x63A0
    ctx->r4 = ADD32(ctx->r16, 0X63A0);
    // 0x8009CB18: swc1        $f8, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f8.u32l;
    // 0x8009CB1C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009CB20: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009CB24: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8009CB28: lw          $t7, -0xB98($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB98);
    // 0x8009CB2C: addiu       $a2, $a2, 0x63AC
    ctx->r6 = ADD32(ctx->r6, 0X63AC);
    // 0x8009CB30: bne         $t7, $zero, L_8009CB50
    if (ctx->r15 != 0) {
        // 0x8009CB34: addiu       $a1, $a1, 0x63A8
        ctx->r5 = ADD32(ctx->r5, 0X63A8);
            goto L_8009CB50;
    }
    // 0x8009CB34: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8009CB38: lb          $t8, 0x1D($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D);
    // 0x8009CB3C: nop

    // 0x8009CB40: sh          $t8, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r24;
    // 0x8009CB44: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8009CB48: nop

    // 0x8009CB4C: sb          $t9, 0x3A($t2)
    MEM_B(0X3A, ctx->r10) = ctx->r25;
L_8009CB50:
    // 0x8009CB50: lw          $t4, -0x89C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X89C);
    // 0x8009CB54: jal         0x80012D5C
    // 0x8009CB58: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    render_object(rdram, ctx);
        goto after_0;
    // 0x8009CB58: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    after_0:
    // 0x8009CB5C: b           L_8009CD70
    // 0x8009CB60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8009CD70;
    // 0x8009CB60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CB64:
    // 0x8009CB64: beq         $t5, $zero, L_8009CC38
    if (ctx->r13 == 0) {
        // 0x8009CB68: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009CC38;
    }
    // 0x8009CB68: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009CB6C: addiu       $s0, $s0, 0x63A0
    ctx->r16 = ADD32(ctx->r16, 0X63A0);
    // 0x8009CB70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CB74: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009CB78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CB7C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009CB80: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009CB84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CB88: lbu         $t9, -0xB5C($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0XB5C);
    // 0x8009CB8C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009CB90: lbu         $t6, -0xB58($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0XB58);
    // 0x8009CB94: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x8009CB98: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8009CB9C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8009CBA0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009CBA4: lbu         $t5, -0xB54($t9)
    ctx->r13 = MEM_BU(ctx->r25, -0XB54);
    // 0x8009CBA8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009CBAC: lw          $t7, -0x89C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X89C);
    // 0x8009CBB0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8009CBB4: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x8009CBB8: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8009CBBC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x8009CBC0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009CBC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CBC8: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8009CBCC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CBD0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009CBD4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8009CBD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009CBDC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CBE0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009CBE4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009CBE8: lw          $t8, -0xB4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB4C);
    // 0x8009CBEC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8009CBF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009CBF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009CBF8: sll         $t9, $t4, 5
    ctx->r25 = S32(ctx->r12 << 5);
    // 0x8009CBFC: addiu       $a2, $a2, 0x63AC
    ctx->r6 = ADD32(ctx->r6, 0X63AC);
    // 0x8009CC00: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8009CC04: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009CC08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009CC0C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009CC10: jal         0x80068BF4
    // 0x8009CC14: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    render_ortho_triangle_image(rdram, ctx);
        goto after_1;
    // 0x8009CC14: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    after_1:
    // 0x8009CC18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CC1C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009CC20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CC24: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009CC28: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8009CC2C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009CC30: b           L_8009CD6C
    // 0x8009CC34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8009CD6C;
    // 0x8009CC34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8009CC38:
    // 0x8009CC38: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009CC3C: addiu       $t1, $t1, -0x89C
    ctx->r9 = ADD32(ctx->r9, -0X89C);
    // 0x8009CC40: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8009CC44: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009CC48: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8009CC4C: beq         $at, $zero, L_8009CC88
    if (ctx->r1 == 0) {
        // 0x8009CC50: addiu       $a1, $a1, 0x63A8
        ctx->r5 = ADD32(ctx->r5, 0X63A8);
            goto L_8009CC88;
    }
    // 0x8009CC50: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8009CC54: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009CC58: addiu       $s0, $s0, 0x63A0
    ctx->r16 = ADD32(ctx->r16, 0X63A0);
    // 0x8009CC5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CC60: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8009CC64: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8009CC68: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009CC6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009CC70: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009CC74: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009CC78: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8009CC7C: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x8009CC80: b           L_8009CCAC
    // 0x8009CC84: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_8009CCAC;
    // 0x8009CC84: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_8009CC88:
    // 0x8009CC88: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009CC8C: addiu       $s0, $s0, 0x63A0
    ctx->r16 = ADD32(ctx->r16, 0X63A0);
    // 0x8009CC90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CC94: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8009CC98: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009CC9C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009CCA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009CCA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009CCA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8009CCAC:
    // 0x8009CCAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CCB0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8009CCB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009CCB8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009CCBC: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x8009CCC0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009CCC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009CCC8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009CCCC: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8009CCD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009CCD4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009CCD8: lw          $a3, -0xBAC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XBAC);
    // 0x8009CCDC: sll         $t5, $t9, 5
    ctx->r13 = S32(ctx->r25 << 5);
    // 0x8009CCE0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8009CCE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009CCE8: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x8009CCEC: jal         0x80069484
    // 0x8009CCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8009CCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8009CCF4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CCF8: addiu       $t3, $t3, -0x8A4
    ctx->r11 = ADD32(ctx->r11, -0X8A4);
    // 0x8009CCFC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009CD00: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8009CD04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009CD08: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8009CD0C: lh          $t4, 0x6($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X6);
    // 0x8009CD10: nop

    // 0x8009CD14: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8009CD18: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8009CD1C: lw          $v0, 0x6550($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6550);
    // 0x8009CD20: nop

    // 0x8009CD24: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009CD28: jal         0x8009CD7C
    // 0x8009CD2C: nop

    render_track_selection_viewport_border(rdram, ctx);
        goto after_3;
    // 0x8009CD2C: nop

    after_3:
    // 0x8009CD30: jal         0x80069A40
    // 0x8009CD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_4;
    // 0x8009CD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009CD38: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009CD3C: lw          $t5, -0x89C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X89C);
    // 0x8009CD40: nop

    // 0x8009CD44: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x8009CD48: beq         $at, $zero, L_8009CD70
    if (ctx->r1 == 0) {
        // 0x8009CD4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CD70;
    }
    // 0x8009CD4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CD50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009CD54: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8009CD58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009CD5C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009CD60: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009CD64: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009CD68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8009CD6C:
    // 0x8009CD6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CD70:
    // 0x8009CD70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009CD74: jr          $ra
    // 0x8009CD78: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009CD78: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800228DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800228E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800228E4: jr          $ra
    // 0x800228E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800228E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_collision_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001709C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800170A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800170A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800170A8: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x800170AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800170B0: lbu         $t6, 0x104($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X104);
    // 0x800170B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800170B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800170BC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800170C0: sb          $t8, 0x104($s0)
    MEM_B(0X104, ctx->r16) = ctx->r24;
    // 0x800170C4: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x800170C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800170CC: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800170D0: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x800170D4: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x800170D8: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x800170DC: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800170E0: sh          $t5, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r13;
    // 0x800170E4: lh          $t6, 0x4($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X4);
    // 0x800170E8: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800170EC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800170F0: sh          $t7, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r15;
    // 0x800170F4: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800170F8: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800170FC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80017100: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017104: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80017108: addu        $a0, $s0, $t1
    ctx->r4 = ADD32(ctx->r16, ctx->r9);
    // 0x8001710C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80017110: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80017114: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80017118: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x8001711C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80017120: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80017124: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x80017128: jal         0x8006FE74
    // 0x8001712C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x8001712C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x80017130: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80017134: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80017138: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8001713C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80017140: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80017144: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80017148: nop

    // 0x8001714C: div.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f12.d, ctx->f8.d);
    // 0x80017150: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80017154: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017158: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001715C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017160: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x80017164: addiu       $v1, $sp, 0x6C
    ctx->r3 = ADD32(ctx->r29, 0X6C);
    // 0x80017168: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8001716C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80017170: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80017174:
    // 0x80017174: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80017178: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8001717C: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80017180: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80017184: bne         $v0, $v1, L_80017174
    if (ctx->r2 != ctx->r3) {
        // 0x80017188: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_80017174;
    }
    // 0x80017188: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001718C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80017190: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80017194: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80017198: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8001719C: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x800171A0: jal         0x8006F768
    // 0x800171A4: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800171A4: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800171A8: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800171AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800171B0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800171B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800171B8: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x800171BC: nop

    // 0x800171C0: div.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800171C4: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800171C8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800171CC: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800171D0: nop

    // 0x800171D4: sh          $t8, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r24;
    // 0x800171D8: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x800171DC: nop

    // 0x800171E0: sh          $t9, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r25;
    // 0x800171E4: lh          $t0, 0x4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X4);
    // 0x800171E8: nop

    // 0x800171EC: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x800171F0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800171F4: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800171F8: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800171FC: nop

    // 0x80017200: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017204: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80017208: nop

    // 0x8001720C: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80017210: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80017214: nop

    // 0x80017218: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x8001721C: lbu         $t1, 0x104($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X104);
    // 0x80017220: nop

    // 0x80017224: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x80017228: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8001722C: jal         0x8006FC30
    // 0x80017230: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80017230: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    after_2:
    // 0x80017234: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    // 0x80017238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001723C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017240: jr          $ra
    // 0x80017244: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80017244: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void audspat_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008174: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008178: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000817C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008180: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80008184: addiu       $v1, $v1, -0x63B4
    ctx->r3 = ADD32(ctx->r3, -0X63B4);
    // 0x80008188: lw          $a0, -0x63B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63B8);
    // 0x8000818C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80008190: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80008194: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80008198: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000819C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800081A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800081A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800081A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800081AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800081B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800081B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800081B8: beq         $at, $zero, L_800081F4
    if (ctx->r1 == 0) {
        // 0x800081BC: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800081F4;
    }
    // 0x800081BC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800081C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800081C4: addiu       $a1, $a1, -0x63B0
    ctx->r5 = ADD32(ctx->r5, -0X63B0);
L_800081C8:
    // 0x800081C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800081CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800081D0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800081D4: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800081D8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800081DC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x800081E0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800081E4: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x800081E8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x800081EC: bne         $at, $zero, L_800081C8
    if (ctx->r1 != 0) {
        // 0x800081F0: sb          $t1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r9;
            goto L_800081C8;
    }
    // 0x800081F0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_800081F4:
    // 0x800081F4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800081F8: addiu       $s4, $s4, -0x3920
    ctx->r20 = ADD32(ctx->r20, -0X3920);
    // 0x800081FC: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
    // 0x80008200: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80008204: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80008208: blez        $t3, L_8000825C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000820C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000825C;
    }
    // 0x8000820C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80008210: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80008214: addiu       $s2, $s2, -0x63BC
    ctx->r18 = ADD32(ctx->r18, -0X63BC);
    // 0x80008218: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000821C:
    // 0x8000821C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80008220: nop

    // 0x80008224: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80008228: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000822C: nop

    // 0x80008230: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80008234: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80008238: beq         $a0, $zero, L_80008248
    if (ctx->r4 == 0) {
        // 0x8000823C: nop
    
            goto L_80008248;
    }
    // 0x8000823C: nop

    // 0x80008240: jal         0x8000488C
    // 0x80008244: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80008244: nop

    after_0:
L_80008248:
    // 0x80008248: lhu         $t6, 0x0($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X0);
    // 0x8000824C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80008250: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80008254: bne         $at, $zero, L_8000821C
    if (ctx->r1 != 0) {
        // 0x80008258: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000821C;
    }
    // 0x80008258: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000825C:
    // 0x8000825C: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80008260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008264: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80008268: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000826C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80008270: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80008274: lwc1        $f20, 0x4F10($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X4F10);
    // 0x80008278: addiu       $s5, $s5, -0x5920
    ctx->r21 = ADD32(ctx->r21, -0X5920);
    // 0x8000827C: addiu       $s3, $s3, -0x63A0
    ctx->r19 = ADD32(ctx->r19, -0X63A0);
    // 0x80008280: addiu       $s2, $s2, -0x63A4
    ctx->r18 = ADD32(ctx->r18, -0X63A4);
    // 0x80008284: addiu       $s1, $s1, -0x63A8
    ctx->r17 = ADD32(ctx->r17, -0X63A8);
    // 0x80008288: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000828C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80008290: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_80008294:
    // 0x80008294: lw          $a0, 0x178($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X178);
    // 0x80008298: sw          $zero, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = 0;
    // 0x8000829C: beq         $a0, $zero, L_800082D8
    if (ctx->r4 == 0) {
        // 0x800082A0: nop
    
            goto L_800082D8;
    }
    // 0x800082A0: nop

    // 0x800082A4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800082A8: nop

    // 0x800082AC: bne         $v0, $zero, L_800082C4
    if (ctx->r2 != 0) {
        // 0x800082B0: nop
    
            goto L_800082C4;
    }
    // 0x800082B0: nop

    // 0x800082B4: jal         0x8000488C
    // 0x800082B8: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x800082B8: nop

    after_1:
    // 0x800082BC: b           L_800082D8
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
        goto L_800082D8;
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082C4:
    // 0x800082C4: bne         $s6, $v0, L_800082D4
    if (ctx->r22 != ctx->r2) {
        // 0x800082C8: nop
    
            goto L_800082D4;
    }
    // 0x800082C8: nop

    // 0x800082CC: jal         0x800018E0
    // 0x800082D0: nop

    music_jingle_stop(rdram, ctx);
        goto after_2;
    // 0x800082D0: nop

    after_2:
L_800082D4:
    // 0x800082D4: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082D8:
    // 0x800082D8: sb          $s4, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = ctx->r20;
    // 0x800082DC: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x800082E0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800082E4: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x800082E8: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800082EC: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800082F0: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800082F4: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800082F8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800082FC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80008300:
    // 0x80008300: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008304: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x80008308: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8000830C: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x80008310: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008314: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008318: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8000831C: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x80008320: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x80008324: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008328: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8000832C: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x80008330: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008334: bne         $v1, $s0, L_80008300
    if (ctx->r3 != ctx->r16) {
        // 0x80008338: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_80008300;
    }
    // 0x80008338: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x8000833C: addiu       $s3, $s3, 0x180
    ctx->r19 = ADD32(ctx->r19, 0X180);
    // 0x80008340: sltu        $at, $s3, $s5
    ctx->r1 = ctx->r19 < ctx->r21 ? 1 : 0;
    // 0x80008344: addiu       $s1, $s1, 0x180
    ctx->r17 = ADD32(ctx->r17, 0X180);
    // 0x80008348: bne         $at, $zero, L_80008294
    if (ctx->r1 != 0) {
        // 0x8000834C: addiu       $s2, $s2, 0x180
        ctx->r18 = ADD32(ctx->r18, 0X180);
            goto L_80008294;
    }
    // 0x8000834C: addiu       $s2, $s2, 0x180
    ctx->r18 = ADD32(ctx->r18, 0X180);
    // 0x80008350: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008354: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008358: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8000835C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80008360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80008364: addiu       $t0, $t0, -0x53E0
    ctx->r8 = ADD32(ctx->r8, -0X53E0);
    // 0x80008368: addiu       $a3, $a3, -0x5920
    ctx->r7 = ADD32(ctx->r7, -0X5920);
    // 0x8000836C: addiu       $a2, $a2, -0x5924
    ctx->r6 = ADD32(ctx->r6, -0X5924);
    // 0x80008370: addiu       $a1, $a1, -0x5928
    ctx->r5 = ADD32(ctx->r5, -0X5928);
    // 0x80008374: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80008378:
    // 0x80008378: sb          $s4, 0xB8($a1)
    MEM_B(0XB8, ctx->r5) = ctx->r20;
    // 0x8000837C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80008380: swc1        $f0, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = ctx->f0.u32l;
    // 0x80008384: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x80008388: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000838C: swc1        $f20, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f20.u32l;
    // 0x80008390: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008394: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008398: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x8000839C: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083A0: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083A4: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800083A8: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800083AC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800083B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800083B4:
    // 0x800083B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800083B8: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083BC: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083C0: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x800083C4: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x800083C8: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x800083CC: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x800083D0: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x800083D4: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083D8: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083DC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800083E0: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x800083E4: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083E8: bne         $v1, $a0, L_800083B4
    if (ctx->r3 != ctx->r4) {
        // 0x800083EC: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_800083B4;
    }
    // 0x800083EC: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083F0: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    // 0x800083F4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x800083F8: bne         $a3, $t0, L_80008378
    if (ctx->r7 != ctx->r8) {
        // 0x800083FC: addiu       $a2, $a2, 0xC0
        ctx->r6 = ADD32(ctx->r6, 0XC0);
            goto L_80008378;
    }
    // 0x800083FC: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x80008400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80008404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008408: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000840C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80008410: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008414: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80008418: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000841C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80008420: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80008424: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80008428: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000842C: sb          $zero, -0x53E8($at)
    MEM_B(-0X53E8, ctx->r1) = 0;
    // 0x80008430: jr          $ra
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void light_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032210: jr          $ra
    // 0x80032214: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032214: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void generate_collision_candidates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031130: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80031134: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80031138: lui         $t1, 0xFFFE
    ctx->r9 = S32(0XFFFE << 16);
    // 0x8003113C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80031140: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80031144: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80031148: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003114C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80031150: ori         $t0, $t0, 0x86A0
    ctx->r8 = ctx->r8 | 0X86A0;
    // 0x80031154: ori         $t1, $t1, 0x7960
    ctx->r9 = ctx->r9 | 0X7960;
    // 0x80031158: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8003115C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031160: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031164: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x80031168: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
    // 0x8003116C: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x80031170: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x80031174: beq         $a0, $zero, L_8003124C
    if (ctx->r4 == 0) {
        // 0x80031178: or          $s6, $a3, $zero
        ctx->r22 = ctx->r7 | 0;
            goto L_8003124C;
    }
    // 0x80031178: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8003117C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80031180: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80031184: add         $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x80031188: add         $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
L_8003118C:
    // 0x8003118C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031190: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031194: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031198: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8003119C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800311A0: trunc.w.s   $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800311A4: mfc1        $t0, $f0
    ctx->r8 = (int32_t)ctx->f0.u32l;
    // 0x800311A8: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800311AC: mfc1        $t1, $f2
    ctx->r9 = (int32_t)ctx->f2.u32l;
    // 0x800311B0: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800311B4: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800311B8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800311BC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800311C0: beql        $at, $zero, L_800311D0
    if (ctx->r1 == 0) {
        // 0x800311C4: slt         $at, $t0, $s5
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800311D0;
    }
    goto skip_0;
    // 0x800311C4: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    skip_0:
    // 0x800311C8: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x800311CC: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
L_800311D0:
    // 0x800311D0: beql        $at, $zero, L_800311E0
    if (ctx->r1 == 0) {
        // 0x800311D4: slt         $at, $s2, $t1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800311E0;
    }
    goto skip_1;
    // 0x800311D4: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x800311D8: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x800311DC: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
L_800311E0:
    // 0x800311E0: beql        $at, $zero, L_800311F0
    if (ctx->r1 == 0) {
        // 0x800311E4: slt         $at, $t1, $s3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800311F0;
    }
    goto skip_2;
    // 0x800311E4: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
    skip_2:
    // 0x800311E8: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x800311EC: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
L_800311F0:
    // 0x800311F0: beql        $at, $zero, L_80031200
    if (ctx->r1 == 0) {
        // 0x800311F4: slt         $at, $s4, $t2
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80031200;
    }
    goto skip_3;
    // 0x800311F4: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800311F8: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800311FC: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
L_80031200:
    // 0x80031200: beql        $at, $zero, L_80031210
    if (ctx->r1 == 0) {
        // 0x80031204: slt         $at, $t2, $s5
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80031210;
    }
    goto skip_4;
    // 0x80031204: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
    skip_4:
    // 0x80031208: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x8003120C: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
L_80031210:
    // 0x80031210: beql        $at, $zero, L_80031220
    if (ctx->r1 == 0) {
        // 0x80031214: slt         $at, $s2, $t3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80031220;
    }
    goto skip_5;
    // 0x80031214: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    skip_5:
    // 0x80031218: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x8003121C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
L_80031220:
    // 0x80031220: beql        $at, $zero, L_80031230
    if (ctx->r1 == 0) {
        // 0x80031224: slt         $at, $t3, $s3
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80031230;
    }
    goto skip_6;
    // 0x80031224: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    skip_6:
    // 0x80031228: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x8003122C: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
L_80031230:
    // 0x80031230: beql        $at, $zero, L_80031240
    if (ctx->r1 == 0) {
        // 0x80031234: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80031240;
    }
    goto skip_7;
    // 0x80031234: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    skip_7:
    // 0x80031238: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8003123C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_80031240:
    // 0x80031240: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031244: bne         $at, $zero, L_8003118C
    if (ctx->r1 != 0) {
        // 0x80031248: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_8003118C;
    }
    // 0x80031248: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_8003124C:
    // 0x8003124C: addiu       $s5, $s5, -0x14
    ctx->r21 = ADD32(ctx->r21, -0X14);
    // 0x80031250: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x80031254: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80031258: addiu       $s3, $s3, -0x14
    ctx->r19 = ADD32(ctx->r19, -0X14);
    // 0x8003125C: beq         $at, $zero, L_80031270
    if (ctx->r1 == 0) {
        // 0x80031260: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_80031270;
    }
    // 0x80031260: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80031264: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
    // 0x80031268: or          $s5, $s4, $zero
    ctx->r21 = ctx->r20 | 0;
    // 0x8003126C: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
L_80031270:
    // 0x80031270: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80031274: beq         $at, $zero, L_80031288
    if (ctx->r1 == 0) {
        // 0x80031278: nop
    
            goto L_80031288;
    }
    // 0x80031278: nop

    // 0x8003127C: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
    // 0x80031280: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80031284: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_80031288:
    // 0x80031288: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003128C: lw          $t0, -0x36E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X36E8);
    // 0x80031290: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80031294: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80031298: lh          $t7, 0x1A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1A);
    // 0x8003129C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800312A0: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x800312A4: beq         $t7, $zero, L_80031334
    if (ctx->r15 == 0) {
        // 0x800312A8: lw          $t6, 0x4($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X4);
            goto L_80031334;
    }
    // 0x800312A8: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
L_800312AC:
    // 0x800312AC: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x800312B0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800312B4: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800312B8: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800312BC: bne         $at, $zero, L_80031324
    if (ctx->r1 != 0) {
        // 0x800312C0: addiu       $v1, $v1, -0x5
        ctx->r3 = ADD32(ctx->r3, -0X5);
            goto L_80031324;
    }
    // 0x800312C0: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // 0x800312C4: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800312C8: bnel        $at, $zero, L_80031328
    if (ctx->r1 != 0) {
        // 0x800312CC: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031328;
    }
    goto skip_8;
    // 0x800312CC: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_8:
    // 0x800312D0: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x800312D4: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x800312D8: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x800312DC: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800312E0: bne         $at, $zero, L_80031324
    if (ctx->r1 != 0) {
        // 0x800312E4: addiu       $t1, $t1, -0x5
        ctx->r9 = ADD32(ctx->r9, -0X5);
            goto L_80031324;
    }
    // 0x800312E4: addiu       $t1, $t1, -0x5
    ctx->r9 = ADD32(ctx->r9, -0X5);
    // 0x800312E8: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800312EC: bnel        $at, $zero, L_80031328
    if (ctx->r1 != 0) {
        // 0x800312F0: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031328;
    }
    goto skip_9;
    // 0x800312F0: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_9:
    // 0x800312F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800312F8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800312FC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80031300: jal         0x800314DC
    // 0x80031304: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x80031304: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x80031308: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8003130C: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x80031310: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80031314: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80031318: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8003131C: beq         $t8, $at, L_80031334
    if (ctx->r24 == ctx->r1) {
        // 0x80031320: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80031334;
    }
    // 0x80031320: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80031324:
    // 0x80031324: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
L_80031328:
    // 0x80031328: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8003132C: bne         $t7, $zero, L_800312AC
    if (ctx->r15 != 0) {
        // 0x80031330: addiu       $t6, $t6, 0x44
        ctx->r14 = ADD32(ctx->r14, 0X44);
            goto L_800312AC;
    }
    // 0x80031330: addiu       $t6, $t6, 0x44
    ctx->r14 = ADD32(ctx->r14, 0X44);
L_80031334:
    // 0x80031334: beq         $t8, $zero, L_800314A8
    if (ctx->r24 == 0) {
        // 0x80031338: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800314A8;
    }
    // 0x80031338: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003133C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031340: lw          $a0, -0x36E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36E8);
    // 0x80031344: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80031348: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003134C: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80031350: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80031354: lw          $s2, -0x2C90($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X2C90);
    // 0x80031358: lw          $t9, -0x2C8C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C8C);
    // 0x8003135C: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80031360: add         $t8, $s1, $t8
    ctx->r24 = ADD32(ctx->r17, ctx->r24);
    // 0x80031364: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_80031368:
    // 0x80031368: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8003136C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80031370: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80031374: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80031378: and         $v0, $t7, $at
    ctx->r2 = ctx->r15 & ctx->r1;
    // 0x8003137C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80031380: lh          $t0, 0x20($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X20);
    // 0x80031384: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x80031388: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003138C: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80031390: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80031394: add         $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x80031398: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8003139C: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800313A0: add         $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800313A4: addiu       $t4, $t5, 0xC
    ctx->r12 = ADD32(ctx->r13, 0XC);
L_800313A8:
    // 0x800313A8: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800313AC: andi        $v0, $t0, 0x200
    ctx->r2 = ctx->r8 & 0X200;
    // 0x800313B0: bne         $v0, $zero, L_80031488
    if (ctx->r2 != 0) {
        // 0x800313B4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80031488;
    }
    // 0x800313B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800313B8: bnel        $s6, $at, L_800313D0
    if (ctx->r22 != ctx->r1) {
        // 0x800313BC: lbu         $v1, 0x0($t5)
        ctx->r3 = MEM_BU(ctx->r13, 0X0);
            goto L_800313D0;
    }
    goto skip_10;
    // 0x800313BC: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    skip_10:
    // 0x800313C0: andi        $v0, $t0, 0x100
    ctx->r2 = ctx->r8 & 0X100;
    // 0x800313C4: bnel        $v0, $zero, L_8003148C
    if (ctx->r2 != 0) {
        // 0x800313C8: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_8003148C;
    }
    goto skip_11;
    // 0x800313C8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_11:
    // 0x800313CC: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
L_800313D0:
    // 0x800313D0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800313D4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800313D8: beql        $v1, $at, L_8003141C
    if (ctx->r3 == ctx->r1) {
        // 0x800313DC: lh          $t0, 0x4($t5)
        ctx->r8 = MEM_H(ctx->r13, 0X4);
            goto L_8003141C;
    }
    goto skip_12;
    // 0x800313DC: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    skip_12:
    // 0x800313E0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800313E4: add         $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800313E8: lb          $t2, 0x7($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X7);
    // 0x800313EC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800313F0: beq         $t2, $at, L_80031488
    if (ctx->r10 == ctx->r1) {
        // 0x800313F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80031488;
    }
    // 0x800313F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800313F8: bne         $s6, $at, L_80031408
    if (ctx->r22 != ctx->r1) {
        // 0x800313FC: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80031408;
    }
    // 0x800313FC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80031400: beql        $t2, $at, L_8003148C
    if (ctx->r10 == ctx->r1) {
        // 0x80031404: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_8003148C;
    }
    goto skip_13;
    // 0x80031404: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_13:
L_80031408:
    // 0x80031408: beq         $s6, $zero, L_80031418
    if (ctx->r22 == 0) {
        // 0x8003140C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80031418;
    }
    // 0x8003140C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80031410: beql        $t2, $at, L_8003148C
    if (ctx->r10 == ctx->r1) {
        // 0x80031414: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_8003148C;
    }
    goto skip_14;
    // 0x80031414: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_14:
L_80031418:
    // 0x80031418: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
L_8003141C:
    // 0x8003141C: lh          $t1, 0x4($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X4);
    // 0x80031420: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80031424: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80031428: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8003142C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80031430: sll         $v1, $t0, 3
    ctx->r3 = S32(ctx->r8 << 3);
    // 0x80031434: add         $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    // 0x80031438: add         $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8003143C: add         $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
L_80031440:
    // 0x80031440: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80031444: and         $t0, $t0, $t6
    ctx->r8 = ctx->r8 & ctx->r14;
    // 0x80031448: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8003144C: beq         $v0, $zero, L_80031478
    if (ctx->r2 == 0) {
        // 0x80031450: andi        $v1, $t0, 0xFF00
        ctx->r3 = ctx->r8 & 0XFF00;
            goto L_80031478;
    }
    // 0x80031450: andi        $v1, $t0, 0xFF00
    ctx->r3 = ctx->r8 & 0XFF00;
    // 0x80031454: beql        $v1, $zero, L_8003147C
    if (ctx->r3 == 0) {
        // 0x80031458: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8003147C;
    }
    goto skip_15;
    // 0x80031458: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_15:
    // 0x8003145C: sw          $a3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r7;
    // 0x80031460: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80031464: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x80031468: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
    // 0x8003146C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80031470: beq         $s3, $at, L_800314A8
    if (ctx->r19 == ctx->r1) {
        // 0x80031474: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800314A8;
    }
    // 0x80031474: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
L_80031478:
    // 0x80031478: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8003147C:
    // 0x8003147C: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80031480: bne         $at, $zero, L_80031440
    if (ctx->r1 != 0) {
        // 0x80031484: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80031440;
    }
    // 0x80031484: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80031488:
    // 0x80031488: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
L_8003148C:
    // 0x8003148C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80031490: bne         $at, $zero, L_800313A8
    if (ctx->r1 != 0) {
        // 0x80031494: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800313A8;
    }
    // 0x80031494: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80031498: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8003149C: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800314A0: bne         $at, $zero, L_80031368
    if (ctx->r1 != 0) {
        // 0x800314A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80031368;
    }
    // 0x800314A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800314A8:
    // 0x800314A8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800314AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800314B0: sw          $s3, -0x2C88($at)
    MEM_W(-0X2C88, ctx->r1) = ctx->r19;
    // 0x800314B4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800314B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800314BC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800314C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800314C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800314C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800314CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800314D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800314D4: jr          $ra
    // 0x800314D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800314D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008415C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084164: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80084168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008416C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084170: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084174: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80084178: jal         0x800C01D8
    // 0x8008417C: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008417C: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_0:
    // 0x80084180: jal         0x800C4170
    // 0x80084184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_1;
    // 0x80084184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80084188: jal         0x800C42EC
    // 0x8008418C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x8008418C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80084190: jal         0x80000BE0
    // 0x80084194: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x80084194: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x80084198: jal         0x80000B34
    // 0x8008419C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_4;
    // 0x8008419C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_4:
    // 0x800841A0: jal         0x80000B18
    // 0x800841A4: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x800841A4: nop

    after_5:
    // 0x800841A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800841AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800841B0: jr          $ra
    // 0x800841B4: nop

    return;
    // 0x800841B4: nop

;}
RECOMP_FUNC void obj_loop_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389B8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800389BC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800389C0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800389C4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800389C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800389CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800389D0: bne         $t6, $zero, L_800389F0
    if (ctx->r14 != 0) {
        // 0x800389D4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800389F0;
    }
    // 0x800389D4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800389D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800389DC: lwc1        $f9, 0x6050($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6050);
    // 0x800389E0: lwc1        $f8, 0x6054($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6054);
    // 0x800389E4: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800389E8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800389EC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800389F0:
    // 0x800389F0: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800389F4: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800389F8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800389FC: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80038A00: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038A04: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80038A08: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80038A0C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038A10: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80038A14: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80038A18: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80038A1C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038A20: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80038A24: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038A28: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80038A2C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038A30: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80038A34: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038A38: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80038A3C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038A40: bne         $at, $zero, L_80038A5C
    if (ctx->r1 != 0) {
        // 0x80038A44: swc1        $f8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
            goto L_80038A5C;
    }
    // 0x80038A44: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80038A48: jal         0x8000FFB8
    // 0x80038A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038A50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038A54: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038A58: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038A5C:
    // 0x80038A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038A64: jr          $ra
    // 0x80038A68: nop

    return;
    // 0x80038A68: nop

;}
RECOMP_FUNC void func_8001F3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F3BC: lb          $v0, -0x522C($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X522C);
    // 0x8001F3C0: jr          $ra
    // 0x8001F3C4: nop

    return;
    // 0x8001F3C4: nop

;}
RECOMP_FUNC void snow_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC21C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800AC220: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AC224: lw          $v0, 0x7C1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C1C);
    // 0x800AC228: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AC22C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800AC230: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800AC234: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AC238: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AC23C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AC240: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AC244: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AC248: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AC24C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AC250: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AC254: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AC258: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800AC25C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AC260: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AC264: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AC268: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC26C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AC270: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AC274: addiu       $s4, $s4, 0x2908
    ctx->r20 = ADD32(ctx->r20, 0X2908);
    // 0x800AC278: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC27C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800AC280: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC284: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC288: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC28C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AC290: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC294: lw          $t9, 0x7BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7BB4);
    // 0x800AC298: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC29C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AC2A0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800AC2A4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AC2A8: lw          $s1, 0x2904($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X2904);
    // 0x800AC2AC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800AC2B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC2B4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AC2B8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC2BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC2C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC2C4: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800AC2C8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC2CC: addiu       $fp, $fp, 0x7C20
    ctx->r30 = ADD32(ctx->r30, 0X7C20);
    // 0x800AC2D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC2D4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AC2D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC2DC: addiu       $s7, $s7, 0x28D4
    ctx->r23 = ADD32(ctx->r23, 0X28D4);
    // 0x800AC2E0: addiu       $s6, $s6, 0x7BF8
    ctx->r22 = ADD32(ctx->r22, 0X7BF8);
    // 0x800AC2E4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AC2E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC2EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC2F0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC2F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC2F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC2FC: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800AC300: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC304: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800AC308: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800AC30C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC310: blez        $t9, L_800AC56C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AC314: addiu       $s5, $sp, 0x64
        ctx->r21 = ADD32(ctx->r29, 0X64);
            goto L_800AC56C;
    }
    // 0x800AC314: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x800AC318: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AC31C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AC320: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800AC324: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800AC328: addiu       $s0, $s0, 0x28D8
    ctx->r16 = ADD32(ctx->r16, 0X28D8);
L_800AC32C:
    // 0x800AC32C: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AC330: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800AC334: addu        $v0, $t1, $s3
    ctx->r2 = ADD32(ctx->r9, ctx->r19);
    // 0x800AC338: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AC33C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800AC340: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800AC344: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x800AC348: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800AC34C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC350: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AC354: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800AC358: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC35C: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800AC360: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800AC364: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC368: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800AC36C: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800AC370: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800AC374: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800AC378: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AC37C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC380: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800AC384: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800AC388: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC38C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800AC390: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800AC394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC398: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800AC39C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AC3A0: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800AC3A4: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800AC3A8: nop

    // 0x800AC3AC: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x800AC3B0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800AC3B4: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800AC3B8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800AC3BC: nop

    // 0x800AC3C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC3C4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC3C8: jal         0x8006F6EC
    // 0x800AC3CC: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_dir(rdram, ctx);
        goto after_0;
    // 0x800AC3CC: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800AC3D0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AC3D4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AC3D8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AC3DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC3E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC3E4: lh          $t5, 0x0($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X0);
    // 0x800AC3E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC3EC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800AC3F0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AC3F4: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800AC3F8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800AC3FC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AC400: beq         $at, $zero, L_800AC554
    if (ctx->r1 == 0) {
        // 0x800AC404: sh          $t4, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r12;
            goto L_800AC554;
    }
    // 0x800AC404: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC408: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x800AC40C: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC410: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC414: beq         $at, $zero, L_800AC554
    if (ctx->r1 == 0) {
        // 0x800AC418: nop
    
            goto L_800AC554;
    }
    // 0x800AC418: nop

    // 0x800AC41C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC420: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC424: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC428: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC42C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC430: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800AC434: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC438: lh          $t2, 0x24($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X24);
    // 0x800AC43C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC440: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AC444: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800AC448: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC44C: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x800AC450: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC45C: subu        $t5, $t4, $t2
    ctx->r13 = SUB32(ctx->r12, ctx->r10);
    // 0x800AC460: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC464: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800AC468: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC46C: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x800AC470: sh          $t5, -0x28($s1)
    MEM_H(-0X28, ctx->r17) = ctx->r13;
    // 0x800AC474: lh          $t7, 0x26($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X26);
    // 0x800AC478: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x800AC47C: nop

    // 0x800AC480: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800AC484: sh          $t9, -0x26($s1)
    MEM_H(-0X26, ctx->r17) = ctx->r25;
    // 0x800AC488: lh          $t1, 0x74($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X74);
    // 0x800AC48C: nop

    // 0x800AC490: sh          $t1, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r9;
    // 0x800AC494: lh          $t3, 0x24($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X24);
    // 0x800AC498: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x800AC49C: nop

    // 0x800AC4A0: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800AC4A4: sh          $t4, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r12;
    // 0x800AC4A8: lh          $t5, 0x26($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X26);
    // 0x800AC4AC: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x800AC4B0: nop

    // 0x800AC4B4: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800AC4B8: sh          $t6, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r14;
    // 0x800AC4BC: lh          $t7, 0x74($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X74);
    // 0x800AC4C0: nop

    // 0x800AC4C4: sh          $t7, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = ctx->r15;
    // 0x800AC4C8: lh          $t1, 0x24($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X24);
    // 0x800AC4CC: lh          $t9, 0x70($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X70);
    // 0x800AC4D0: nop

    // 0x800AC4D4: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x800AC4D8: sh          $t8, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r24;
    // 0x800AC4DC: lh          $t4, 0x26($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X26);
    // 0x800AC4E0: lh          $t3, 0x72($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X72);
    // 0x800AC4E4: nop

    // 0x800AC4E8: subu        $t2, $t3, $t4
    ctx->r10 = SUB32(ctx->r11, ctx->r12);
    // 0x800AC4EC: sh          $t2, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r10;
    // 0x800AC4F0: lh          $t5, 0x74($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X74);
    // 0x800AC4F4: nop

    // 0x800AC4F8: sh          $t5, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r13;
    // 0x800AC4FC: lh          $t7, 0x24($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X24);
    // 0x800AC500: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x800AC504: nop

    // 0x800AC508: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800AC50C: sh          $t9, -0xA($s1)
    MEM_H(-0XA, ctx->r17) = ctx->r25;
    // 0x800AC510: lh          $t8, 0x26($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X26);
    // 0x800AC514: lh          $t1, 0x72($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X72);
    // 0x800AC518: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AC51C: subu        $t3, $t1, $t8
    ctx->r11 = SUB32(ctx->r9, ctx->r24);
    // 0x800AC520: sh          $t3, -0x8($s1)
    MEM_H(-0X8, ctx->r17) = ctx->r11;
    // 0x800AC524: lh          $t4, 0x74($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X74);
    // 0x800AC528: nop

    // 0x800AC52C: sh          $t4, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r12;
    // 0x800AC530: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800AC534: nop

    // 0x800AC538: addiu       $t5, $t2, 0x4
    ctx->r13 = ADD32(ctx->r10, 0X4);
    // 0x800AC53C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800AC540: lw          $t6, 0x2910($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2910);
    // 0x800AC544: sra         $t9, $t5, 2
    ctx->r25 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800AC548: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AC54C: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x800AC550: sh          $s2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r18;
L_800AC554:
    // 0x800AC554: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AC558: lw          $t3, 0x7BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7BB4);
    // 0x800AC55C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AC560: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AC564: bne         $at, $zero, L_800AC32C
    if (ctx->r1 != 0) {
        // 0x800AC568: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_800AC32C;
    }
    // 0x800AC568: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_800AC56C:
    // 0x800AC56C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800AC570: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AC574: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AC578: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AC57C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AC580: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AC584: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC588: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800AC58C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800AC590: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800AC594: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800AC598: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800AC59C: jr          $ra
    // 0x800AC5A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800AC5A0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87B4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C87B8: lw          $t6, 0x3780($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3780);
    // 0x800C87BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C87C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C87C4: beql        $t6, $zero, L_800C87E0
    if (ctx->r14 == 0) {
        // 0x800C87C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C87E0;
    }
    goto skip_0;
    // 0x800C87C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C87CC: jal         0x800D2C60
    // 0x800C87D0: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800C87D0: nop

    after_0:
    // 0x800C87D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C87D8: sw          $zero, 0x3780($at)
    MEM_W(0X3780, ctx->r1) = 0;
    // 0x800C87DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C87E0:
    // 0x800C87E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87E4: jr          $ra
    // 0x800C87E8: nop

    return;
    // 0x800C87E8: nop

;}
RECOMP_FUNC void camera_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663DC: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x800663E0: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800663E4: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800663E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800663EC: lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XCE4);
    // 0x800663F0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800663F4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800663F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800663FC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80066400: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066404: addiu       $t7, $t7, 0xAC0
    ctx->r15 = ADD32(ctx->r15, 0XAC0);
    // 0x80066408: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8006640C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80066410: mflo        $t8
    ctx->r24 = lo;
    // 0x80066414: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066418: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8006641C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066420: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80066424: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066428: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8006642C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066430: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80066434: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80066438: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8006643C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066440: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x80066444: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x80066448: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8006644C: mflo        $t1
    ctx->r9 = lo;
    // 0x80066450: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80066454: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x80066458: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006645C: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x80066460: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x80066464: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x80066468: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8006646C: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80066470: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80066474: mflo        $t3
    ctx->r11 = lo;
    // 0x80066478: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8006647C: lbu         $t4, -0x2D08($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2D08);
    // 0x80066480: jr          $ra
    // 0x80066484: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
    return;
    // 0x80066484: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void move_particle_attached_to_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3240: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B3244: lw          $v0, 0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C80);
    // 0x800B3248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B324C: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3254: beq         $v1, $zero, L_800B32AC
    if (ctx->r3 == 0) {
        // 0x800B3258: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B32AC;
    }
    // 0x800B3258: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B325C: lh          $a1, 0x62($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X62);
    // 0x800B3260: lh          $a2, 0x64($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X64);
    // 0x800B3264: lh          $a3, 0x66($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X66);
    // 0x800B3268: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B326C: nop

L_800B3270:
    // 0x800B3270: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B3274: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B3278: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800B327C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3280: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3284: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B3288: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B328C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800B3290: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x800B3294: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B3298: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x800B329C: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800B32A0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800B32A4: bne         $v1, $zero, L_800B3270
    if (ctx->r3 != 0) {
        // 0x800B32A8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B3270;
    }
    // 0x800B32A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B32AC:
    // 0x800B32AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B32B0: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800B32B4: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800B32B8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B32BC: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B32C0: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800B32C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B32C8: jal         0x80070320
    // 0x800B32CC: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B32CC: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800B32D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B32D4: nop

    // 0x800B32D8: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B32DC: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B32E0: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B32E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B32E8: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B32EC: lwc1        $f18, 0x54($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B32F0: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B32F4: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B32F8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B32FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3300: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3304: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3308: beq         $v0, $zero, L_800B3348
    if (ctx->r2 == 0) {
        // 0x800B330C: swc1        $f4, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
            goto L_800B3348;
    }
    // 0x800B330C: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800B3310: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3314: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3318: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B331C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3320: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3324: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B3328: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B332C: nop

    // 0x800B3330: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3334: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800B3338: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B333C: nop

    // 0x800B3340: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3344: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_800B3348:
    // 0x800B3348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B334C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3350: jr          $ra
    // 0x800B3354: nop

    return;
    // 0x800B3354: nop

;}
RECOMP_FUNC void hud_audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0B74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0B78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A0B7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A0B80: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A0B84: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800A0B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0B8C: addiu       $s1, $s1, 0x2790
    ctx->r17 = ADD32(ctx->r17, 0X2790);
    // 0x800A0B90: addiu       $s0, $s0, 0x2770
    ctx->r16 = ADD32(ctx->r16, 0X2770);
L_800A0B94:
    // 0x800A0B94: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800A0B98: nop

    // 0x800A0B9C: beq         $a0, $zero, L_800A0BB4
    if (ctx->r4 == 0) {
        // 0x800A0BA0: nop
    
            goto L_800A0BB4;
    }
    // 0x800A0BA0: nop

    // 0x800A0BA4: jal         0x8000488C
    // 0x800A0BA8: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x800A0BA8: nop

    after_0:
    // 0x800A0BAC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A0BB0: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A0BB4:
    // 0x800A0BB4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A0BB8: bne         $s0, $s1, L_800A0B94
    if (ctx->r16 != ctx->r17) {
        // 0x800A0BBC: nop
    
            goto L_800A0B94;
    }
    // 0x800A0BBC: nop

    // 0x800A0BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A0BC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A0BC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A0BCC: jr          $ra
    // 0x800A0BD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A0BD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_world_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D25C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D260: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D264: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D268: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x8001D26C: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x8001D270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D274: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D278: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001D27C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D280: addiu       $a0, $a0, -0x50D0
    ctx->r4 = ADD32(ctx->r4, -0X50D0);
    // 0x8001D284: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001D288: jal         0x8001D4B4
    // 0x8001D28C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D28C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001D290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D298: jr          $ra
    // 0x8001D29C: nop

    return;
    // 0x8001D29C: nop

;}
RECOMP_FUNC void music_tempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800015BC: lh          $v0, 0x5D30($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5D30);
    // 0x800015C0: jr          $ra
    // 0x800015C4: nop

    return;
    // 0x800015C4: nop

;}
RECOMP_FUNC void func_80046524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046524: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80046528: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004652C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80046530: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80046534: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80046538: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004653C: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x80046540: jal         0x8000E138
    // 0x80046544: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    func_8000E138(rdram, ctx);
        goto after_0;
    // 0x80046544: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80046548: beq         $v0, $zero, L_80046570
    if (ctx->r2 == 0) {
        // 0x8004654C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80046570;
    }
    // 0x8004654C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046554: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80046558: lwc1        $f9, 0x63A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X63A8);
    // 0x8004655C: lwc1        $f8, 0x63AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X63AC);
    // 0x80046560: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80046564: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80046568: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004656C: swc1        $f4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f4.u32l;
L_80046570:
    // 0x80046570: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
    // 0x80046574: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80046578: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004657C: bltz        $t6, L_800465AC
    if (SIGNED(ctx->r14) < 0) {
        // 0x80046580: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800465AC;
    }
    // 0x80046580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046584: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80046588: lw          $t7, -0x3468($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3468);
    // 0x8004658C: nop

    // 0x80046590: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80046594: beq         $at, $zero, L_800465B0
    if (ctx->r1 == 0) {
        // 0x80046598: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_800465B0;
    }
    // 0x80046598: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004659C: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800465A0: nop

    // 0x800465A4: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800465A8: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
L_800465AC:
    // 0x800465AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_800465B0:
    // 0x800465B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800465B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800465B8: sh          $zero, -0x2AB0($at)
    MEM_H(-0X2AB0, ctx->r1) = 0;
    // 0x800465BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800465C0: sw          $zero, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = 0;
    // 0x800465C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800465C8: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    // 0x800465CC: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800465D0: lh          $t2, -0x2A7A($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X2A7A);
    // 0x800465D4: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    // 0x800465D8: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800465DC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800465E0: swc1        $f8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f8.u32l;
    // 0x800465E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800465E8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800465EC: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x800465F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800465F4: swc1        $f10, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f10.u32l;
    // 0x800465F8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800465FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80046600: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80046604: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046608: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004660C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80046610: lw          $t3, -0x2AA4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AA4);
    // 0x80046614: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80046618: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004661C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80046620: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80046624: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80046628: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x8004662C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80046630: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80046634: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80046638: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004663C: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x80046640: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80046644: nop

    // 0x80046648: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8004664C: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80046650: nop

    // 0x80046654: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80046658: beq         $t3, $at, L_8004666C
    if (ctx->r11 == ctx->r1) {
        // 0x8004665C: swc1        $f8, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
            goto L_8004666C;
    }
    // 0x8004665C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x80046660: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x80046664: nop

    // 0x80046668: beq         $t4, $zero, L_80046678
    if (ctx->r12 == 0) {
        // 0x8004666C: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_80046678;
    }
L_8004666C:
    // 0x8004666C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80046670: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80046674: nop

L_80046678:
    // 0x80046678: lb          $t0, 0x1E1($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004667C: lw          $t5, -0x2ACC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2ACC);
    // 0x80046680: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80046684: subu        $v1, $t5, $t0
    ctx->r3 = SUB32(ctx->r13, ctx->r8);
    // 0x80046688: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8004668C: nop

    // 0x80046690: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80046694: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80046698: nop

    // 0x8004669C: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800466A0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800466A4: nop

    // 0x800466A8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800466AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800466B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800466B4: nop

    // 0x800466B8: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800466BC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800466C0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800466C4: beq         $v1, $zero, L_800466EC
    if (ctx->r3 == 0) {
        // 0x800466C8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800466EC;
    }
    // 0x800466C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800466CC: bne         $v0, $zero, L_800466F0
    if (ctx->r2 != 0) {
        // 0x800466D0: addu        $t7, $t0, $a3
        ctx->r15 = ADD32(ctx->r8, ctx->r7);
            goto L_800466F0;
    }
    // 0x800466D0: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
    // 0x800466D4: blez        $v1, L_800466E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800466D8: nop
    
            goto L_800466E0;
    }
    // 0x800466D8: nop

    // 0x800466DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800466E0:
    // 0x800466E0: bgez        $v1, L_800466F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800466E4: addu        $t7, $t0, $a3
        ctx->r15 = ADD32(ctx->r8, ctx->r7);
            goto L_800466F0;
    }
    // 0x800466E4: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
    // 0x800466E8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_800466EC:
    // 0x800466EC: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
L_800466F0:
    // 0x800466F0: sb          $t7, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r15;
    // 0x800466F4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x800466F8: jal         0x80055EC0
    // 0x800466FC: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    handle_racer_items(rdram, ctx);
        goto after_1;
    // 0x800466FC: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80046700: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046704: jal         0x800535C4
    // 0x80046708: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_2;
    // 0x80046708: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004670C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046710: jal         0x80048C7C
    // 0x80046714: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_hovercraft(rdram, ctx);
        goto after_3;
    // 0x80046714: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80046718: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004671C: lw          $t8, -0x2AA4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AA4);
    // 0x80046720: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046724: beq         $t8, $at, L_80046744
    if (ctx->r24 == ctx->r1) {
        // 0x80046728: nop
    
            goto L_80046744;
    }
    // 0x80046728: nop

    // 0x8004672C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046734: jal         0x800521C4
    // 0x80046738: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_4;
    // 0x80046738: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8004673C: b           L_8004674C
    // 0x80046740: nop

        goto L_8004674C;
    // 0x80046740: nop

L_80046744:
    // 0x80046744: jal         0x8005234C
    // 0x80046748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    slowly_reset_head_angle(rdram, ctx);
        goto after_5;
    // 0x80046748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8004674C:
    // 0x8004674C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80046750: lw          $t9, -0x2AD8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AD8);
    // 0x80046754: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80046758: andi        $t2, $t9, 0x8000
    ctx->r10 = ctx->r25 & 0X8000;
    // 0x8004675C: beq         $t2, $zero, L_800467D8
    if (ctx->r10 == 0) {
        // 0x80046760: nop
    
            goto L_800467D8;
    }
    // 0x80046760: nop

    // 0x80046764: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80046768: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004676C: lwc1        $f11, 0x63B0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X63B0);
    // 0x80046770: lwc1        $f10, 0x63B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X63B4);
    // 0x80046774: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80046778: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8004677C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80046780: swc1        $f9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x80046784: lwc1        $f4, 0xB4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80046788: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004678C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80046790: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80046794: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80046798: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004679C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800467A0: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x800467A4: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800467A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800467AC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800467B0: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800467B4: nop

    // 0x800467B8: bc1f        L_80046840
    if (!c1cs) {
        // 0x800467BC: nop
    
            goto L_80046840;
    }
    // 0x800467BC: nop

    // 0x800467C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800467C4: nop

    // 0x800467C8: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x800467CC: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800467D0: b           L_80046844
    // 0x800467D4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80046844;
    // 0x800467D4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
L_800467D8:
    // 0x800467D8: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800467DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800467E0: lwc1        $f7, 0x63B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X63B8);
    // 0x800467E4: lwc1        $f6, 0x63BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X63BC);
    // 0x800467E8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800467EC: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x800467F0: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800467F4: swc1        $f9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800467F8: lwc1        $f4, 0xB4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800467FC: nop

    // 0x80046800: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80046804: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80046808: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004680C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80046810: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x80046814: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80046818: nop

    // 0x8004681C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80046820: nop

    // 0x80046824: bc1f        L_80046840
    if (!c1cs) {
        // 0x80046828: nop
    
            goto L_80046840;
    }
    // 0x80046828: nop

    // 0x8004682C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046830: nop

    // 0x80046834: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x80046838: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x8004683C: nop

L_80046840:
    // 0x80046840: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
L_80046844:
    // 0x80046844: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046848: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004684C: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80046850: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80046854: bc1f        L_80046878
    if (!c1cs) {
        // 0x80046858: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80046878;
    }
    // 0x80046858: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004685C: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x80046860: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046864: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80046868: beq         $t4, $zero, L_80046878
    if (ctx->r12 == 0) {
        // 0x8004686C: nop
    
            goto L_80046878;
    }
    // 0x8004686C: nop

    // 0x80046870: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80046874: nop

L_80046878:
    // 0x80046878: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004687C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046880: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80046884: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80046888: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004688C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046890: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80046894: nop

    // 0x80046898: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004689C: swc1        $f12, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f12.u32l;
    // 0x800468A0: lw          $t5, 0x108($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X108);
    // 0x800468A4: nop

    // 0x800468A8: beq         $t5, $zero, L_800468BC
    if (ctx->r13 == 0) {
        // 0x800468AC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800468BC;
    }
    // 0x800468AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800468B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800468B4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800468B8: swc1        $f6, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f6.u32l;
L_800468BC:
    // 0x800468BC: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800468C0: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x800468C4: lw          $a0, -0x2AD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AD8);
    // 0x800468C8: bc1f        L_800468EC
    if (!c1cs) {
        // 0x800468CC: andi        $t6, $a0, 0x4000
        ctx->r14 = ctx->r4 & 0X4000;
            goto L_800468EC;
    }
    // 0x800468CC: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x800468D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800468D4: lwc1        $f7, 0x63C0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X63C0);
    // 0x800468D8: lwc1        $f6, 0x63C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X63C4);
    // 0x800468DC: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800468E0: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800468E4: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800468E8: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
L_800468EC:
    // 0x800468EC: beq         $t6, $zero, L_800469AC
    if (ctx->r14 == 0) {
        // 0x800468F0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800469AC;
    }
    // 0x800468F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800468F4: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x800468F8: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800468FC: slti        $at, $t7, -0x28
    ctx->r1 = SIGNED(ctx->r15) < -0X28 ? 1 : 0;
    // 0x80046900: bne         $at, $zero, L_8004691C
    if (ctx->r1 != 0) {
        // 0x80046904: nop
    
            goto L_8004691C;
    }
    // 0x80046904: nop

    // 0x80046908: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004690C: nop

    // 0x80046910: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80046914: nop

    // 0x80046918: bc1f        L_800469AC
    if (!c1cs) {
        // 0x8004691C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800469AC;
    }
L_8004691C:
    // 0x8004691C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046920: lwc1        $f5, 0x63C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X63C8);
    // 0x80046924: lwc1        $f4, 0x63CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63CC);
    // 0x80046928: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004692C: lwc1        $f10, 0xB8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046930: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80046934: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80046938: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004693C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80046940: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80046944: swc1        $f10, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f10.u32l;
    // 0x80046948: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8004694C: lwc1        $f6, 0x63D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X63D4);
    // 0x80046950: lwc1        $f7, 0x63D0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X63D0);
    // 0x80046954: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80046958: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8004695C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046960: bc1f        L_80046974
    if (!c1cs) {
        // 0x80046964: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80046974;
    }
    // 0x80046964: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046968: lwc1        $f10, 0x63D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X63D8);
    // 0x8004696C: nop

    // 0x80046970: swc1        $f10, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f10.u32l;
L_80046974:
    // 0x80046974: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046978: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8004697C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80046980: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80046984: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80046988: nop

    // 0x8004698C: bc1f        L_800469A0
    if (!c1cs) {
        // 0x80046990: nop
    
            goto L_800469A0;
    }
    // 0x80046990: nop

    // 0x80046994: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80046998: jal         0x80072348
    // 0x8004699C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    rumble_set(rdram, ctx);
        goto after_6;
    // 0x8004699C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
L_800469A0:
    // 0x800469A0: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800469A4: b           L_80046A0C
    // 0x800469A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_80046A0C;
    // 0x800469A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800469AC:
    // 0x800469AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800469B0: lwc1        $f9, 0x63E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X63E0);
    // 0x800469B4: lwc1        $f8, 0x63E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X63E4);
    // 0x800469B8: lwc1        $f11, 0x50($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800469BC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800469C0: lwc1        $f4, 0xB8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800469C4: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800469C8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800469CC: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800469D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800469D4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800469D8: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x800469DC: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800469E0: nop

    // 0x800469E4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800469E8: nop

    // 0x800469EC: bc1f        L_80046A0C
    if (!c1cs) {
        // 0x800469F0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80046A0C;
    }
    // 0x800469F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800469F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800469F8: nop

    // 0x800469FC: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
    // 0x80046A00: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046A04: nop

    // 0x80046A08: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80046A0C:
    // 0x80046A0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046A10: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80046A14: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80046A18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046A1C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80046A20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046A24: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80046A28: nop

    // 0x80046A2C: div.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80046A30: swc1        $f12, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f12.u32l;
    // 0x80046A34: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046A38: nop

    // 0x80046A3C: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80046A40: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80046A44: nop

    // 0x80046A48: bc1f        L_80046A68
    if (!c1cs) {
        // 0x80046A4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80046A68;
    }
    // 0x80046A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046A50: lwc1        $f11, 0x63E8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X63E8);
    // 0x80046A54: lwc1        $f10, 0x63EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X63EC);
    // 0x80046A58: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80046A5C: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80046A60: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046A64: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_80046A68:
    // 0x80046A68: lbu         $t8, 0x1F5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80046A6C: nop

    // 0x80046A70: beq         $t8, $zero, L_80046BD8
    if (ctx->r24 == 0) {
        // 0x80046A74: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80046BD8;
    }
    // 0x80046A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046A78: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x80046A7C: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x80046A80: lh          $v0, 0x1A0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A0);
    // 0x80046A84: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x80046A88: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
    // 0x80046A8C: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x80046A90: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x80046A94: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x80046A98: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80046A9C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80046AA0: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x80046AA4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80046AA8: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x80046AAC: bne         $at, $zero, L_80046ABC
    if (ctx->r1 != 0) {
        // 0x80046AB0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80046ABC;
    }
    // 0x80046AB0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046AB4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046AB8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046ABC:
    // 0x80046ABC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80046AC0: beq         $at, $zero, L_80046ACC
    if (ctx->r1 == 0) {
        // 0x80046AC4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80046ACC;
    }
    // 0x80046AC4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046AC8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046ACC:
    // 0x80046ACC: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046AD0: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80046AD4: mflo        $t5
    ctx->r13 = lo;
    // 0x80046AD8: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80046ADC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80046AE0: beq         $at, $zero, L_80046AF4
    if (ctx->r1 == 0) {
        // 0x80046AE4: sh          $t7, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r15;
            goto L_80046AF4;
    }
    // 0x80046AE4: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
    // 0x80046AE8: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80046AEC: beq         $at, $zero, L_80046B04
    if (ctx->r1 == 0) {
        // 0x80046AF0: nop
    
            goto L_80046B04;
    }
    // 0x80046AF0: nop

L_80046AF4:
    // 0x80046AF4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80046AF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046AFC: bne         $t8, $at, L_80046B84
    if (ctx->r24 != ctx->r1) {
        // 0x80046B00: nop
    
            goto L_80046B84;
    }
    // 0x80046B00: nop

L_80046B04:
    // 0x80046B04: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80046B08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046B0C: beq         $t9, $at, L_80046B3C
    if (ctx->r25 == ctx->r1) {
        // 0x80046B10: addiu       $a0, $zero, 0x107
        ctx->r4 = ADD32(0, 0X107);
            goto L_80046B3C;
    }
    // 0x80046B10: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80046B14: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80046B18: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80046B1C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80046B20: jal         0x80001EA8
    // 0x80046B24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_7;
    // 0x80046B24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80046B28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046B2C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80046B30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80046B34: jal         0x800570B8
    // 0x80046B38: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_8;
    // 0x80046B38: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_8:
L_80046B3C:
    // 0x80046B3C: jal         0x8000C8B4
    // 0x80046B40: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    normalise_time(rdram, ctx);
        goto after_9;
    // 0x80046B40: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_9:
    // 0x80046B44: lbu         $t3, 0x20C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20C);
    // 0x80046B48: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80046B4C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80046B50: beq         $t3, $zero, L_80046B68
    if (ctx->r11 == 0) {
        // 0x80046B54: sb          $t2, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r10;
            goto L_80046B68;
    }
    // 0x80046B54: sb          $t2, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r10;
    // 0x80046B58: lb          $t4, 0x203($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X203);
    // 0x80046B5C: nop

    // 0x80046B60: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80046B64: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_80046B68:
    // 0x80046B68: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80046B6C: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
    // 0x80046B70: jal         0x80072348
    // 0x80046B74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_10;
    // 0x80046B74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x80046B78: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046B7C: b           L_80046BDC
    // 0x80046B80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80046BDC;
    // 0x80046B80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80046B84:
    // 0x80046B84: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80046B88: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80046B8C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80046B90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046B94: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046B98: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046B9C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80046BA0: nop

    // 0x80046BA4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046BA8: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80046BAC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046BB0: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046BB4: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x80046BB8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046BBC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046BC0: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046BC4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80046BC8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046BCC: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x80046BD0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046BD4: nop

L_80046BD8:
    // 0x80046BD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80046BDC:
    // 0x80046BDC: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80046BE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046BE8: bc1f        L_80046BF4
    if (!c1cs) {
        // 0x80046BEC: lui         $at, 0x402C
        ctx->r1 = S32(0X402C << 16);
            goto L_80046BF4;
    }
    // 0x80046BEC: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80046BF0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80046BF4:
    // 0x80046BF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80046BF8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80046BFC: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80046C00: nop

    // 0x80046C04: bc1f        L_80046C14
    if (!c1cs) {
        // 0x80046C08: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_80046C14;
    }
    // 0x80046C08: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80046C0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80046C10: nop

L_80046C14:
    // 0x80046C14: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80046C18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046C1C: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046C20: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80046C24: bne         $t6, $zero, L_80046C40
    if (ctx->r14 != 0) {
        // 0x80046C28: lw          $a1, 0x128($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X128);
            goto L_80046C40;
    }
    // 0x80046C28: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80046C2C: lb          $t7, 0x1D5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D5);
    // 0x80046C30: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80046C34: beq         $t7, $zero, L_80046C5C
    if (ctx->r15 == 0) {
        // 0x80046C38: lui         $at, 0x4580
        ctx->r1 = S32(0X4580 << 16);
            goto L_80046C5C;
    }
    // 0x80046C38: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x80046C3C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
L_80046C40:
    // 0x80046C40: lh          $a2, 0x160($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X160);
    // 0x80046C44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80046C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046C4C: jal         0x80050850
    // 0x80046C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_11;
    // 0x80046C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80046C54: b           L_80046CAC
    // 0x80046C58: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
        goto L_80046CAC;
    // 0x80046C58: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
L_80046C5C:
    // 0x80046C5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046C60: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80046C64: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80046C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046C6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046C70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80046C74: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80046C78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80046C7C: nop

    // 0x80046C80: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80046C84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80046C88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80046C8C: nop

    // 0x80046C90: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80046C94: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80046C98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80046C9C: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80046CA0: jal         0x80050850
    // 0x80046CA4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_12;
    // 0x80046CA4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    after_12:
    // 0x80046CA8: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
L_80046CAC:
    // 0x80046CAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046CB0: beq         $t3, $zero, L_80046CF4
    if (ctx->r11 == 0) {
        // 0x80046CB4: nop
    
            goto L_80046CF4;
    }
    // 0x80046CB4: nop

    // 0x80046CB8: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046CBC: nop

    // 0x80046CC0: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80046CC4: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80046CC8: sh          $t5, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r13;
    // 0x80046CCC: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046CD0: nop

    // 0x80046CD4: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80046CD8: beq         $at, $zero, L_80046CEC
    if (ctx->r1 == 0) {
        // 0x80046CDC: slti        $at, $v0, -0xF
        ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
            goto L_80046CEC;
    }
    // 0x80046CDC: slti        $at, $v0, -0xF
    ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
    // 0x80046CE0: bne         $at, $zero, L_80046CEC
    if (ctx->r1 != 0) {
        // 0x80046CE4: nop
    
            goto L_80046CEC;
    }
    // 0x80046CE4: nop

    // 0x80046CE8: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_80046CEC:
    // 0x80046CEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046CF0: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
L_80046CF4:
    // 0x80046CF4: lb          $v0, 0x1DB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046CF8: nop

    // 0x80046CFC: blez        $v0, L_80046D34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046D00: nop
    
            goto L_80046D34;
    }
    // 0x80046D00: nop

    // 0x80046D04: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046D08: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D0C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80046D10: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x80046D14: sb          $t7, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r15;
    // 0x80046D18: lb          $t8, 0x1D4($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D1C: nop

    // 0x80046D20: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x80046D24: bne         $at, $zero, L_80046DCC
    if (ctx->r1 != 0) {
        // 0x80046D28: nop
    
            goto L_80046DCC;
    }
    // 0x80046D28: nop

    // 0x80046D2C: b           L_80046DCC
    // 0x80046D30: sb          $t9, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r25;
        goto L_80046DCC;
    // 0x80046D30: sb          $t9, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r25;
L_80046D34:
    // 0x80046D34: bgez        $v0, L_80046D6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80046D38: nop
    
            goto L_80046D6C;
    }
    // 0x80046D38: nop

    // 0x80046D3C: lb          $t2, 0x1D4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D40: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x80046D44: addiu       $t6, $zero, -0xA
    ctx->r14 = ADD32(0, -0XA);
    // 0x80046D48: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80046D4C: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
    // 0x80046D50: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D54: nop

    // 0x80046D58: slti        $at, $t5, -0xA
    ctx->r1 = SIGNED(ctx->r13) < -0XA ? 1 : 0;
    // 0x80046D5C: beq         $at, $zero, L_80046DCC
    if (ctx->r1 == 0) {
        // 0x80046D60: nop
    
            goto L_80046DCC;
    }
    // 0x80046D60: nop

    // 0x80046D64: b           L_80046DCC
    // 0x80046D68: sb          $t6, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r14;
        goto L_80046DCC;
    // 0x80046D68: sb          $t6, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r14;
L_80046D6C:
    // 0x80046D6C: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D70: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80046D74: bgez        $v1, L_80046D9C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046D78: addu        $t8, $v1, $t7
        ctx->r24 = ADD32(ctx->r3, ctx->r15);
            goto L_80046D9C;
    }
    // 0x80046D78: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80046D7C: sb          $t8, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r24;
    // 0x80046D80: lb          $t9, 0x1D4($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80046D88: blez        $t9, L_80046DCC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80046D8C: nop
    
            goto L_80046DCC;
    }
    // 0x80046D8C: nop

    // 0x80046D90: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x80046D94: b           L_80046DCC
    // 0x80046D98: sb          $t2, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r10;
        goto L_80046DCC;
    // 0x80046D98: sb          $t2, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r10;
L_80046D9C:
    // 0x80046D9C: blez        $v1, L_80046DCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046DA0: nop
    
            goto L_80046DCC;
    }
    // 0x80046DA0: nop

    // 0x80046DA4: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x80046DA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80046DAC: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x80046DB0: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
    // 0x80046DB4: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046DB8: nop

    // 0x80046DBC: bgez        $t5, L_80046DCC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80046DC0: nop
    
            goto L_80046DCC;
    }
    // 0x80046DC0: nop

    // 0x80046DC4: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x80046DC8: sb          $t6, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r14;
L_80046DCC:
    // 0x80046DCC: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x80046DD0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046DD4: beq         $a1, $zero, L_80046E1C
    if (ctx->r5 == 0) {
        // 0x80046DD8: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80046E1C;
    }
    // 0x80046DD8: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80046DDC: beq         $at, $zero, L_80046E1C
    if (ctx->r1 == 0) {
        // 0x80046DE0: nop
    
            goto L_80046E1C;
    }
    // 0x80046DE0: nop

    // 0x80046DE4: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80046DE8: nop

    // 0x80046DEC: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046DF0: mflo        $t7
    ctx->r15 = lo;
    // 0x80046DF4: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80046DF8: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x80046DFC: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
    // 0x80046E00: lh          $a1, 0x1A4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A4);
    // 0x80046E04: nop

    // 0x80046E08: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046E0C: mflo        $t2
    ctx->r10 = lo;
    // 0x80046E10: sra         $t3, $t2, 6
    ctx->r11 = S32(SIGNED(ctx->r10) >> 6);
    // 0x80046E14: subu        $t4, $a1, $t3
    ctx->r12 = SUB32(ctx->r5, ctx->r11);
    // 0x80046E18: sh          $t4, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r12;
L_80046E1C:
    // 0x80046E1C: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046E20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80046E24: beq         $v1, $zero, L_80046F2C
    if (ctx->r3 == 0) {
        // 0x80046E28: addiu       $a1, $a1, -0x2AF0
        ctx->r5 = ADD32(ctx->r5, -0X2AF0);
            goto L_80046F2C;
    }
    // 0x80046E28: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80046E2C: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046E30: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
    // 0x80046E34: blez        $v1, L_80046E98
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046E38: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80046E98;
    }
    // 0x80046E38: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80046E3C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80046E40: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E48: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E4C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E50: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80046E54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E58: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E5C: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046E60: slti        $at, $v0, -0x1000
    ctx->r1 = SIGNED(ctx->r2) < -0X1000 ? 1 : 0;
    // 0x80046E64: mflo        $t6
    ctx->r14 = lo;
    // 0x80046E68: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80046E6C: beq         $at, $zero, L_80046E98
    if (ctx->r1 == 0) {
        // 0x80046E70: sh          $t7, 0x160($s0)
        MEM_H(0X160, ctx->r16) = ctx->r15;
            goto L_80046E98;
    }
    // 0x80046E70: sh          $t7, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r15;
    // 0x80046E74: lh          $t8, 0x160($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X160);
    // 0x80046E78: nop

    // 0x80046E7C: slti        $at, $t8, -0x1000
    ctx->r1 = SIGNED(ctx->r24) < -0X1000 ? 1 : 0;
    // 0x80046E80: bne         $at, $zero, L_80046E98
    if (ctx->r1 != 0) {
        // 0x80046E84: nop
    
            goto L_80046E98;
    }
    // 0x80046E84: nop

    // 0x80046E88: lb          $t9, 0x1DB($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046E8C: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046E90: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80046E94: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
L_80046E98:
    // 0x80046E98: bgez        $v1, L_80046F00
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046E9C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80046F00;
    }
    // 0x80046E9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046EA0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80046EA4: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046EA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EAC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046EB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EB4: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80046EB8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EBC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046EC0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046EC4: lh          $t3, 0x160($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X160);
    // 0x80046EC8: slti        $at, $t0, 0x1001
    ctx->r1 = SIGNED(ctx->r8) < 0X1001 ? 1 : 0;
    // 0x80046ECC: mflo        $t5
    ctx->r13 = lo;
    // 0x80046ED0: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x80046ED4: bne         $at, $zero, L_80046F00
    if (ctx->r1 != 0) {
        // 0x80046ED8: sh          $t6, 0x160($s0)
        MEM_H(0X160, ctx->r16) = ctx->r14;
            goto L_80046F00;
    }
    // 0x80046ED8: sh          $t6, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r14;
    // 0x80046EDC: lh          $t7, 0x160($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X160);
    // 0x80046EE0: nop

    // 0x80046EE4: slti        $at, $t7, 0x1001
    ctx->r1 = SIGNED(ctx->r15) < 0X1001 ? 1 : 0;
    // 0x80046EE8: beq         $at, $zero, L_80046F00
    if (ctx->r1 == 0) {
        // 0x80046EEC: nop
    
            goto L_80046F00;
    }
    // 0x80046EEC: nop

    // 0x80046EF0: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046EF4: nop

    // 0x80046EF8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80046EFC: sb          $t9, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r25;
L_80046F00:
    // 0x80046F00: lw          $t2, -0x2AD8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AD8);
    // 0x80046F04: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046F08: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80046F0C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80046F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F14: sw          $t4, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r12;
    // 0x80046F18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F1C: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x80046F20: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
    // 0x80046F24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F28: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
L_80046F2C:
    // 0x80046F2C: lbu         $t3, 0x1F1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1F1);
    // 0x80046F30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046F34: beq         $t3, $zero, L_80046F6C
    if (ctx->r11 == 0) {
        // 0x80046F38: addiu       $a0, $sp, 0x68
        ctx->r4 = ADD32(ctx->r29, 0X68);
            goto L_80046F6C;
    }
    // 0x80046F38: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80046F3C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80046F40: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80046F44: lh          $t5, 0x160($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X160);
    // 0x80046F48: lh          $t8, 0x162($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X162);
    // 0x80046F4C: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80046F50: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80046F54: sll         $t6, $t6, 8
    ctx->r14 = S32(ctx->r14 << 8);
    // 0x80046F58: sll         $t9, $t9, 9
    ctx->r25 = S32(ctx->r25 << 9);
    // 0x80046F5C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80046F60: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80046F64: sh          $t7, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r15;
    // 0x80046F68: sh          $t2, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r10;
L_80046F6C:
    // 0x80046F6C: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80046F70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046F74: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x80046F78: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x80046F7C: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80046F80: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80046F84: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80046F88: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80046F8C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80046F90: jal         0x8006FC30
    // 0x80046F94: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    mtxf_from_transform(rdram, ctx);
        goto after_13;
    // 0x80046F94: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    after_13:
    // 0x80046F98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046F9C: addiu       $t5, $s0, 0x38
    ctx->r13 = ADD32(ctx->r16, 0X38);
    // 0x80046FA0: addiu       $t6, $s0, 0x3C
    ctx->r14 = ADD32(ctx->r16, 0X3C);
    // 0x80046FA4: addiu       $t7, $s0, 0x40
    ctx->r15 = ADD32(ctx->r16, 0X40);
    // 0x80046FA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80046FAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80046FB0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80046FB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80046FB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80046FBC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80046FC0: jal         0x8006F64C
    // 0x80046FC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x80046FC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_14:
    // 0x80046FC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046FCC: addiu       $t8, $s0, 0x44
    ctx->r24 = ADD32(ctx->r16, 0X44);
    // 0x80046FD0: addiu       $t9, $s0, 0x48
    ctx->r25 = ADD32(ctx->r16, 0X48);
    // 0x80046FD4: addiu       $t2, $s0, 0x4C
    ctx->r10 = ADD32(ctx->r16, 0X4C);
    // 0x80046FD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80046FDC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80046FE0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80046FE4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80046FE8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80046FEC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80046FF0: jal         0x8006F64C
    // 0x80046FF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_15;
    // 0x80046FF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_15:
    // 0x80046FF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046FFC: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x80047000: addiu       $t3, $s0, 0x54
    ctx->r11 = ADD32(ctx->r16, 0X54);
    // 0x80047004: addiu       $t5, $s0, 0x58
    ctx->r13 = ADD32(ctx->r16, 0X58);
    // 0x80047008: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004700C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80047010: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80047014: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80047018: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004701C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80047020: jal         0x8006F64C
    // 0x80047024: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_16;
    // 0x80047024: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80047028: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8004702C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047030: bne         $t6, $zero, L_8004706C
    if (ctx->r14 != 0) {
        // 0x80047034: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8004706C;
    }
    // 0x80047034: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80047038: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8004703C: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x80047040: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80047044: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80047048: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8004704C: bgez        $v0, L_8004705C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047050: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8004705C;
    }
    // 0x80047050: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x80047054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047058: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8004705C:
    // 0x8004705C: bne         $at, $zero, L_80047068
    if (ctx->r1 != 0) {
        // 0x80047060: nop
    
            goto L_80047068;
    }
    // 0x80047060: nop

    // 0x80047064: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_80047068:
    // 0x80047068: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_8004706C:
    // 0x8004706C: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80047070: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80047074: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80047078: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004707C: bc1f        L_80047088
    if (!c1cs) {
        // 0x80047080: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80047088;
    }
    // 0x80047080: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80047084: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_80047088:
    // 0x80047088: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004708C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80047090: bc1f        L_8004709C
    if (!c1cs) {
        // 0x80047094: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8004709C;
    }
    // 0x80047094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80047098: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_8004709C:
    // 0x8004709C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800470A0: lw          $t2, -0x2A9C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2A9C);
    // 0x800470A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800470A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800470AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800470B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800470B4: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800470B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800470BC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800470C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800470C4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800470C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800470CC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800470D0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800470D4: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x800470D8: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800470DC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800470E0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800470E4: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800470E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800470EC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800470F0: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800470F4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800470F8: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    // 0x800470FC: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80047100: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80047104: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80047108: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004710C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80047110: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80047114: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047118: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004711C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80047120: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80047124: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047128: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004712C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80047130: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047134: nop

    // 0x80047138: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8004713C: bne         $at, $zero, L_80047180
    if (ctx->r1 != 0) {
        // 0x80047140: nop
    
            goto L_80047180;
    }
    // 0x80047140: nop

    // 0x80047144: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80047148: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004714C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047154: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80047158: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8004715C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80047160: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x80047164: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047168: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x8004716C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80047170: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x80047174: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80047178: b           L_80047198
    // 0x8004717C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
        goto L_80047198;
    // 0x8004717C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_80047180:
    // 0x80047180: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80047184: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80047188: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004718C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80047190: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80047194: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_80047198:
    // 0x80047198: lw          $t5, -0x2AA4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AA4);
    // 0x8004719C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800471A0: beq         $t5, $at, L_800471C4
    if (ctx->r13 == ctx->r1) {
        // 0x800471A4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_800471C4;
    }
    // 0x800471A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800471A8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x800471AC: nop

    // 0x800471B0: bne         $t6, $zero, L_800471C4
    if (ctx->r14 != 0) {
        // 0x800471B4: nop
    
            goto L_800471C4;
    }
    // 0x800471B4: nop

    // 0x800471B8: lb          $t0, 0x1E1($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E1);
    // 0x800471BC: b           L_800471D0
    // 0x800471C0: nop

        goto L_800471D0;
    // 0x800471C0: nop

L_800471C4:
    // 0x800471C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800471C8: lw          $t0, -0x2ACC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2ACC);
    // 0x800471CC: nop

L_800471D0:
    // 0x800471D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800471D4: lwc1        $f2, 0x63F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X63F0);
    // 0x800471D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800471DC: swc1        $f2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f2.u32l;
    // 0x800471E0: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800471E4: lwc1        $f5, 0x63F8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X63F8);
    // 0x800471E8: lwc1        $f4, 0x63FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63FC);
    // 0x800471EC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800471F0: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800471F4: lwc1        $f11, 0x50($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800471F8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800471FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80047200: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80047204: sub.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d - ctx->f8.d;
    // 0x80047208: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004720C: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80047210: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x80047214: nop

    // 0x80047218: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x8004721C: beq         $t8, $zero, L_8004726C
    if (ctx->r24 == 0) {
        // 0x80047220: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8004726C;
    }
    // 0x80047220: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80047224: lw          $t9, -0x2AC8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC8);
    // 0x80047228: nop

    // 0x8004722C: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x80047230: bne         $at, $zero, L_80047270
    if (ctx->r1 != 0) {
        // 0x80047234: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_80047270;
    }
    // 0x80047234: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x80047238: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004723C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80047240: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047244: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047248: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004724C: c.le.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d <= ctx->f8.d;
    // 0x80047250: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80047254: bc1f        L_80047270
    if (!c1cs) {
        // 0x80047258: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_80047270;
    }
    // 0x80047258: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x8004725C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047260: nop

    // 0x80047264: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80047268: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
L_8004726C:
    // 0x8004726C: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
L_80047270:
    // 0x80047270: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x80047274: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047278: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004727C: lw          $v0, -0x2AC8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AC8);
    // 0x80047280: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80047284: mflo        $t4
    ctx->r12 = lo;
    // 0x80047288: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8004728C: nop

    // 0x80047290: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80047294: bgez        $v0, L_80047308
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047298: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80047308;
    }
    // 0x80047298: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8004729C: negu        $t3, $v0
    ctx->r11 = SUB32(0, ctx->r2);
    // 0x800472A0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800472A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800472A8: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800472AC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800472B0: lui         $at, 0x405C
    ctx->r1 = S32(0X405C << 16);
    // 0x800472B4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800472B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800472BC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x800472C0: nop

    // 0x800472C4: div.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x800472C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800472CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800472D0: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800472D4: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x800472D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800472DC: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800472E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800472E4: lwc1        $f11, 0x6400($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6400);
    // 0x800472E8: lwc1        $f10, 0x6404($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6404);
    // 0x800472EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800472F0: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x800472F4: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x800472F8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800472FC: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80047300: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80047304: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80047308:
    // 0x80047308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004730C: lwc1        $f4, -0x2A90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x80047310: lh          $t5, 0x1A0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047314: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80047318: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004731C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80047320: nop

    // 0x80047324: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80047328: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004732C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047330: nop

    // 0x80047334: cvt.w.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80047338: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8004733C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80047340: subu        $t2, $t5, $t9
    ctx->r10 = SUB32(ctx->r13, ctx->r25);
    // 0x80047344: bne         $t4, $zero, L_800473B0
    if (ctx->r12 != 0) {
        // 0x80047348: sh          $t2, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r10;
            goto L_800473B0;
    }
    // 0x80047348: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
    // 0x8004734C: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80047350: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80047354: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047358: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004735C: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x80047360: nop

    // 0x80047364: bc1f        L_800473B0
    if (!c1cs) {
        // 0x80047368: nop
    
            goto L_800473B0;
    }
    // 0x80047368: nop

    // 0x8004736C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047370: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047374: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x80047378: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8004737C: nop

    // 0x80047380: bc1f        L_80047398
    if (!c1cs) {
        // 0x80047384: nop
    
            goto L_80047398;
    }
    // 0x80047384: nop

    // 0x80047388: lb          $t3, 0x1E0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004738C: nop

    // 0x80047390: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x80047394: sb          $t6, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r14;
L_80047398:
    // 0x80047398: lb          $t7, 0x1E0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004739C: nop

    // 0x800473A0: slti        $at, $t7, 0x1A
    ctx->r1 = SIGNED(ctx->r15) < 0X1A ? 1 : 0;
    // 0x800473A4: bne         $at, $zero, L_800473B0
    if (ctx->r1 != 0) {
        // 0x800473A8: nop
    
            goto L_800473B0;
    }
    // 0x800473A8: nop

    // 0x800473AC: sb          $t8, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r24;
L_800473B0:
    // 0x800473B0: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x800473B4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800473B8:
    // 0x800473B8: lbu         $v0, 0x1DC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1DC);
    // 0x800473BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800473C0: beq         $a0, $v0, L_800473F0
    if (ctx->r4 == ctx->r2) {
        // 0x800473C4: slt         $at, $t1, $v0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800473F0;
    }
    // 0x800473C4: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800473C8: beq         $at, $zero, L_800473DC
    if (ctx->r1 == 0) {
        // 0x800473CC: nop
    
            goto L_800473DC;
    }
    // 0x800473CC: nop

    // 0x800473D0: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x800473D4: sra         $t5, $t1, 24
    ctx->r13 = S32(SIGNED(ctx->r9) >> 24);
    // 0x800473D8: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
L_800473DC:
    // 0x800473DC: bne         $a2, $v0, L_800473F4
    if (ctx->r6 != ctx->r2) {
        // 0x800473E0: slti        $at, $t0, 0x4
        ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
            goto L_800473F4;
    }
    // 0x800473E0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800473E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800473E8: sll         $t9, $a3, 24
    ctx->r25 = S32(ctx->r7 << 24);
    // 0x800473EC: sra         $a3, $t9, 24
    ctx->r7 = S32(SIGNED(ctx->r25) >> 24);
L_800473F0:
    // 0x800473F0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
L_800473F4:
    // 0x800473F4: bne         $at, $zero, L_800473B8
    if (ctx->r1 != 0) {
        // 0x800473F8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800473B8;
    }
    // 0x800473F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800473FC: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80047400: nop

    // 0x80047404: bne         $t4, $zero, L_8004743C
    if (ctx->r12 != 0) {
        // 0x80047408: nop
    
            goto L_8004743C;
    }
    // 0x80047408: nop

    // 0x8004740C: beq         $a1, $zero, L_8004743C
    if (ctx->r5 == 0) {
        // 0x80047410: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8004743C;
    }
    // 0x80047410: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80047414: bne         $t1, $at, L_8004743C
    if (ctx->r9 != ctx->r1) {
        // 0x80047418: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004743C;
    }
    // 0x80047418: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004741C: lw          $t3, -0x2AD4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD4);
    // 0x80047420: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80047424: andi        $t6, $t3, 0x2000
    ctx->r14 = ctx->r11 & 0X2000;
    // 0x80047428: beq         $t6, $zero, L_8004743C
    if (ctx->r14 == 0) {
        // 0x8004742C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004743C;
    }
    // 0x8004742C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047430: sb          $t7, -0x2A7E($at)
    MEM_B(-0X2A7E, ctx->r1) = ctx->r15;
    // 0x80047434: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047438: nop

L_8004743C:
    // 0x8004743C: bne         $a1, $zero, L_80047460
    if (ctx->r5 != 0) {
        // 0x80047440: nop
    
            goto L_80047460;
    }
    // 0x80047440: nop

    // 0x80047444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047448: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004744C: nop

    // 0x80047450: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80047454: nop

    // 0x80047458: bc1f        L_80047598
    if (!c1cs) {
        // 0x8004745C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80047598;
    }
    // 0x8004745C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80047460:
    // 0x80047460: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x80047464: nop

    // 0x80047468: beq         $v0, $zero, L_80047598
    if (ctx->r2 == 0) {
        // 0x8004746C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80047598;
    }
    // 0x8004746C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047470: beq         $a1, $zero, L_800474EC
    if (ctx->r5 == 0) {
        // 0x80047474: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800474EC;
    }
    // 0x80047474: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80047478: lw          $t8, -0x2AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC0);
    // 0x8004747C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80047480: beq         $t8, $at, L_8004752C
    if (ctx->r24 == ctx->r1) {
        // 0x80047484: nop
    
            goto L_8004752C;
    }
    // 0x80047484: nop

    // 0x80047488: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8004748C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80047490: beq         $t5, $at, L_8004752C
    if (ctx->r13 == ctx->r1) {
        // 0x80047494: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8004752C;
    }
    // 0x80047494: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80047498: bne         $at, $zero, L_8004752C
    if (ctx->r1 != 0) {
        // 0x8004749C: addiu       $a0, $zero, 0xAE
        ctx->r4 = ADD32(0, 0XAE);
            goto L_8004752C;
    }
    // 0x8004749C: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x800474A0: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    // 0x800474A4: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x800474A8: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x800474AC: jal         0x80001D04
    // 0x800474B0: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    sound_play(rdram, ctx);
        goto after_17;
    // 0x800474B0: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x800474B4: lb          $a2, 0x1E0($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E0);
    // 0x800474B8: lw          $a1, 0x21C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X21C);
    // 0x800474BC: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800474C0: addiu       $a2, $t9, 0x32
    ctx->r6 = ADD32(ctx->r25, 0X32);
    // 0x800474C4: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x800474C8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800474CC: jal         0x80001FB8
    // 0x800474D0: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    sound_volume_set_relative(rdram, ctx);
        goto after_18;
    // 0x800474D0: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    after_18:
    // 0x800474D4: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x800474D8: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x800474DC: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800474E0: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x800474E4: b           L_80047530
    // 0x800474E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_80047530;
    // 0x800474E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_800474EC:
    // 0x800474EC: lw          $t4, 0x148($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X148);
    // 0x800474F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800474F4: bne         $t4, $zero, L_8004752C
    if (ctx->r12 != 0) {
        // 0x800474F8: addiu       $a1, $zero, 0xAF
        ctx->r5 = ADD32(0, 0XAF);
            goto L_8004752C;
    }
    // 0x800474F8: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x800474FC: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x80047500: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x80047504: jal         0x80057048
    // 0x80047508: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_19;
    // 0x80047508: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x8004750C: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x80047510: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x80047514: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x80047518: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8004751C: ori         $t6, $t3, 0x30
    ctx->r14 = ctx->r11 | 0X30;
    // 0x80047520: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
    // 0x80047524: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x80047528: nop

L_8004752C:
    // 0x8004752C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_80047530:
    // 0x80047530: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80047534: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004753C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047540: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80047544: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80047548: nop

    // 0x8004754C: bc1f        L_80047590
    if (!c1cs) {
        // 0x80047550: nop
    
            goto L_80047590;
    }
    // 0x80047550: nop

    // 0x80047554: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x80047558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004755C: bne         $t7, $zero, L_80047590
    if (ctx->r15 != 0) {
        // 0x80047560: nop
    
            goto L_80047590;
    }
    // 0x80047560: nop

    // 0x80047564: lwc1        $f11, 0x6408($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6408);
    // 0x80047568: lwc1        $f10, 0x640C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X640C);
    // 0x8004756C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80047570: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80047574: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80047578: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004757C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047580: nop

    // 0x80047584: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x80047588: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004758C: swc1        $f10, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
L_80047590:
    // 0x80047590: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x80047594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80047598:
    // 0x80047598: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004759C: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x800475A0: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x800475A4: jal         0x80057220
    // 0x800475A8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_20;
    // 0x800475A8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x800475AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800475B0: lwc1        $f9, 0x6410($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6410);
    // 0x800475B4: lwc1        $f8, 0x6414($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6414);
    // 0x800475B8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800475BC: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800475C0: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800475C4: lb          $v1, 0x1D3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D3);
    // 0x800475C8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800475CC: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x800475D0: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800475D4: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x800475D8: blez        $v1, L_80047640
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800475DC: cvt.s.d     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
            goto L_80047640;
    }
    // 0x800475DC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x800475E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800475E4: lw          $v0, -0x2AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AC0);
    // 0x800475E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800475EC: bne         $v0, $zero, L_80047650
    if (ctx->r2 != 0) {
        // 0x800475F0: nop
    
            goto L_80047650;
    }
    // 0x800475F0: nop

    // 0x800475F4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800475F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800475FC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80047600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047604: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047608: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8004760C: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80047610: bc1t        L_80047624
    if (c1cs) {
        // 0x80047614: swc1        $f10, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
            goto L_80047624;
    }
    // 0x80047614: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80047618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004761C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80047620: nop

L_80047624:
    // 0x80047624: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x80047628: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004762C: subu        $t5, $v1, $t8
    ctx->r13 = SUB32(ctx->r3, ctx->r24);
    // 0x80047630: sb          $t5, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r13;
    // 0x80047634: lw          $v0, -0x2AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AC0);
    // 0x80047638: b           L_80047650
    // 0x8004763C: nop

        goto L_80047650;
    // 0x8004763C: nop

L_80047640:
    // 0x80047640: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80047644: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80047648: lw          $v0, -0x2AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AC0);
    // 0x8004764C: nop

L_80047650:
    // 0x80047650: beq         $v0, $zero, L_80047660
    if (ctx->r2 == 0) {
        // 0x80047654: nop
    
            goto L_80047660;
    }
    // 0x80047654: nop

    // 0x80047658: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004765C: nop

L_80047660:
    // 0x80047660: beq         $a3, $zero, L_800476AC
    if (ctx->r7 == 0) {
        // 0x80047664: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_800476AC;
    }
    // 0x80047664: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80047668: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x8004766C: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x80047670: jal         0x8001E29C
    // 0x80047674: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    get_misc_asset(rdram, ctx);
        goto after_21;
    // 0x80047674: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x80047678: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x8004767C: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80047680: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80047684: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80047688: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8004768C: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047690: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80047694: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047698: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x8004769C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800476A0: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x800476A4: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800476A8: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_800476AC:
    // 0x800476AC: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x800476B0: nop

    // 0x800476B4: bne         $t4, $zero, L_8004772C
    if (ctx->r12 != 0) {
        // 0x800476B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004772C;
    }
    // 0x800476B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800476BC: bne         $t1, $at, L_8004772C
    if (ctx->r9 != ctx->r1) {
        // 0x800476C0: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8004772C;
    }
    // 0x800476C0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x800476C4: jal         0x8000C8B4
    // 0x800476C8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_22;
    // 0x800476C8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x800476CC: lbu         $t6, 0x20C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20C);
    // 0x800476D0: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800476D4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800476D8: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x800476DC: beq         $t6, $zero, L_800476F4
    if (ctx->r14 == 0) {
        // 0x800476E0: sb          $t3, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r11;
            goto L_800476F4;
    }
    // 0x800476E0: sb          $t3, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r11;
    // 0x800476E4: lb          $t7, 0x203($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X203);
    // 0x800476E8: nop

    // 0x800476EC: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x800476F0: sb          $t8, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r24;
L_800476F4:
    // 0x800476F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800476F8: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x800476FC: jal         0x80057048
    // 0x80047700: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_23;
    // 0x80047700: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x80047704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047708: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004770C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80047710: jal         0x800570B8
    // 0x80047714: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_24;
    // 0x80047714: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_24:
    // 0x80047718: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004771C: jal         0x80072348
    // 0x80047720: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_25;
    // 0x80047720: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x80047724: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047728: nop

L_8004772C:
    // 0x8004772C: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047730: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047734: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80047738: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x8004773C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80047740: jal         0x800C9AD0
    // 0x80047744: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_26;
    // 0x80047744: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_26:
    // 0x80047748: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004774C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80047750: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047754: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80047758: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004775C: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047760: bc1f        L_80047960
    if (!c1cs) {
        // 0x80047764: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80047960;
    }
    // 0x80047764: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80047768: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004776C: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047770: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80047774: jal         0x80070750
    // 0x80047778: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_27;
    // 0x80047778: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    after_27:
    // 0x8004777C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80047780: lwc1        $f2, 0xD0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80047784: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    // 0x80047788: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8004778C: sh          $t5, 0x168($s0)
    MEM_H(0X168, ctx->r16) = ctx->r13;
    // 0x80047790: lh          $t9, 0x168($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X168);
    // 0x80047794: lh          $a0, 0x196($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X196);
    // 0x80047798: subu        $t2, $a1, $t9
    ctx->r10 = SUB32(ctx->r5, ctx->r25);
    // 0x8004779C: andi        $t4, $t2, 0xFFFF
    ctx->r12 = ctx->r10 & 0XFFFF;
    // 0x800477A0: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x800477A4: ori         $t1, $zero, 0x8001
    ctx->r9 = 0 | 0X8001;
    // 0x800477A8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
    // 0x800477AC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800477B0: bne         $at, $zero, L_800477C4
    if (ctx->r1 != 0) {
        // 0x800477B4: cvt.d.s     $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
            goto L_800477C4;
    }
    // 0x800477B4: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x800477B8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800477BC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800477C0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800477C4:
    // 0x800477C4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800477C8: beq         $at, $zero, L_800477D4
    if (ctx->r1 == 0) {
        // 0x800477CC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800477D4;
    }
    // 0x800477CC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800477D0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800477D4:
    // 0x800477D4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800477D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800477DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800477E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800477E4: sub.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d - ctx->f6.d;
    // 0x800477E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800477EC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800477F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800477F4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800477F8: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800477FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047800: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80047804: bc1f        L_80047814
    if (!c1cs) {
        // 0x80047808: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80047814;
    }
    // 0x80047808: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004780C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80047810: nop

L_80047814:
    // 0x80047814: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80047818: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004781C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80047820: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047824: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80047828: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8004782C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047834: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80047838: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x8004783C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047840: lh          $v0, 0x1A0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047844: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80047848: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8004784C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80047850: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80047854: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80047858: nop

    // 0x8004785C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80047860: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047864: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047868: nop

    // 0x8004786C: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x80047870: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80047874: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80047878: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004787C: mflo        $t7
    ctx->r15 = lo;
    // 0x80047880: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80047884: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80047888: sh          $t5, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r13;
    // 0x8004788C: lh          $t9, 0x196($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X196);
    // 0x80047890: nop

    // 0x80047894: subu        $t2, $a1, $t9
    ctx->r10 = SUB32(ctx->r5, ctx->r25);
    // 0x80047898: subu        $v1, $t2, $t4
    ctx->r3 = SUB32(ctx->r10, ctx->r12);
    // 0x8004789C: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800478A0: bne         $at, $zero, L_800478B0
    if (ctx->r1 != 0) {
        // 0x800478A4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800478B0;
    }
    // 0x800478A4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800478A8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800478AC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800478B0:
    // 0x800478B0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800478B4: beq         $at, $zero, L_800478C0
    if (ctx->r1 == 0) {
        // 0x800478B8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800478C0;
    }
    // 0x800478B8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800478BC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800478C0:
    // 0x800478C0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800478C4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800478C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800478CC: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800478D0: nop

    // 0x800478D4: bc1f        L_800478EC
    if (!c1cs) {
        // 0x800478D8: nop
    
            goto L_800478EC;
    }
    // 0x800478D8: nop

    // 0x800478DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800478E0: nop

    // 0x800478E4: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x800478E8: nop

L_800478EC:
    // 0x800478EC: div.d       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f12.d, ctx->f0.d);
    // 0x800478F0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800478F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800478F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800478FC: lw          $a0, -0x2AD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AD8);
    // 0x80047900: nop

    // 0x80047904: andi        $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 & 0X8000;
    // 0x80047908: andi        $t7, $a0, 0x10
    ctx->r15 = ctx->r4 & 0X10;
    // 0x8004790C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80047910: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80047914: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80047918: nop

    // 0x8004791C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80047920: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047924: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047928: nop

    // 0x8004792C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80047930: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80047934: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80047938: bne         $t6, $zero, L_80047948
    if (ctx->r14 != 0) {
        // 0x8004793C: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_80047948;
    }
    // 0x8004793C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80047940: beq         $t7, $zero, L_8004794C
    if (ctx->r15 == 0) {
        // 0x80047944: nop
    
            goto L_8004794C;
    }
    // 0x80047944: nop

L_80047948:
    // 0x80047948: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8004794C:
    // 0x8004794C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047950: mflo        $t5
    ctx->r13 = lo;
    // 0x80047954: sra         $t9, $t5, 7
    ctx->r25 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80047958: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x8004795C: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
L_80047960:
    // 0x80047960: lh          $a0, 0x196($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X196);
    // 0x80047964: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047968: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8004796C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80047970: subu        $t3, $a1, $t4
    ctx->r11 = SUB32(ctx->r5, ctx->r12);
    // 0x80047974: ori         $t1, $zero, 0x8001
    ctx->r9 = 0 | 0X8001;
    // 0x80047978: subu        $v1, $t3, $t6
    ctx->r3 = SUB32(ctx->r11, ctx->r14);
    // 0x8004797C: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x80047980: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80047984: bne         $at, $zero, L_80047994
    if (ctx->r1 != 0) {
        // 0x80047988: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80047994;
    }
    // 0x80047988: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004798C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80047990: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80047994:
    // 0x80047994: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80047998: beq         $at, $zero, L_800479A4
    if (ctx->r1 == 0) {
        // 0x8004799C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800479A4;
    }
    // 0x8004799C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800479A0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800479A4:
    // 0x800479A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800479A8: lui         $at, 0x3FFC
    ctx->r1 = S32(0X3FFC << 16);
    // 0x800479AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800479B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800479B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800479B8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800479BC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800479C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800479C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800479C8: lbu         $t2, 0x1F5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F5);
    // 0x800479CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800479D0: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800479D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800479D8: nop

    // 0x800479DC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800479E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800479E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800479E8: nop

    // 0x800479EC: cvt.w.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_D(ctx->f10.d);
    // 0x800479F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800479F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800479F8: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800479FC: mflo        $t8
    ctx->r24 = lo;
    // 0x80047A00: sra         $t5, $t8, 6
    ctx->r13 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80047A04: addu        $t9, $a0, $t5
    ctx->r25 = ADD32(ctx->r4, ctx->r13);
    // 0x80047A08: bne         $t2, $zero, L_80047E8C
    if (ctx->r10 != 0) {
        // 0x80047A0C: sh          $t9, 0x196($s0)
        MEM_H(0X196, ctx->r16) = ctx->r25;
            goto L_80047E8C;
    }
    // 0x80047A0C: sh          $t9, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r25;
    // 0x80047A10: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80047A14: lw          $t4, -0x2AA4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AA4);
    // 0x80047A18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80047A1C: bne         $t4, $at, L_80047B00
    if (ctx->r12 != ctx->r1) {
        // 0x80047A20: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80047B00;
    }
    // 0x80047A20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80047A24: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x80047A28: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80047A2C: bne         $t3, $zero, L_80047B00
    if (ctx->r11 != 0) {
        // 0x80047A30: nop
    
            goto L_80047B00;
    }
    // 0x80047A30: nop

    // 0x80047A34: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80047A38: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80047A3C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047A40: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80047A44: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80047A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047A4C: lwc1        $f9, 0x6418($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6418);
    // 0x80047A50: lwc1        $f8, 0x641C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X641C);
    // 0x80047A54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047A58: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80047A5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80047A60: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80047A64: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80047A68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047A6C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80047A70: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80047A74: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80047A78: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80047A7C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80047A80: bc1f        L_80047A8C
    if (!c1cs) {
        // 0x80047A84: nop
    
            goto L_80047A8C;
    }
    // 0x80047A84: nop

    // 0x80047A88: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_80047A8C:
    // 0x80047A8C: lwc1        $f9, 0x6420($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6420);
    // 0x80047A90: lwc1        $f8, 0x6424($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6424);
    // 0x80047A94: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80047A98: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80047A9C: nop

    // 0x80047AA0: bc1f        L_80047AB8
    if (!c1cs) {
        // 0x80047AA4: nop
    
            goto L_80047AB8;
    }
    // 0x80047AA4: nop

    // 0x80047AA8: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x80047AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047AB0: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80047AB4: sw          $t7, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r15;
L_80047AB8:
    // 0x80047AB8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047ABC: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047AC0: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80047AC4: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047AC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80047ACC: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x80047AD0: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047AD4: nop

    // 0x80047AD8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80047ADC: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047AE0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80047AE4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80047AE8: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047AEC: nop

    // 0x80047AF0: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80047AF4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80047AF8: b           L_80047BE0
    // 0x80047AFC: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
        goto L_80047BE0;
    // 0x80047AFC: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
L_80047B00:
    // 0x80047B00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047B04: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80047B08: lwc1        $f7, 0x6428($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6428);
    // 0x80047B0C: lwc1        $f6, 0x642C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X642C);
    // 0x80047B10: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80047B14: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80047B18: lw          $a0, -0x2AD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AD8);
    // 0x80047B1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047B20: andi        $t8, $a0, 0x10
    ctx->r24 = ctx->r4 & 0X10;
    // 0x80047B24: beq         $t8, $zero, L_80047BE0
    if (ctx->r24 == 0) {
        // 0x80047B28: cvt.s.d     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
            goto L_80047BE0;
    }
    // 0x80047B28: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80047B2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80047B30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047B34: lw          $v0, -0x2ACC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2ACC);
    // 0x80047B38: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80047B3C: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    // 0x80047B40: bne         $at, $zero, L_80047B74
    if (ctx->r1 != 0) {
        // 0x80047B44: andi        $t5, $a0, 0x4000
        ctx->r13 = ctx->r4 & 0X4000;
            goto L_80047B74;
    }
    // 0x80047B44: andi        $t5, $a0, 0x4000
    ctx->r13 = ctx->r4 & 0X4000;
    // 0x80047B48: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80047B4C: beq         $at, $zero, L_80047B74
    if (ctx->r1 == 0) {
        // 0x80047B50: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80047B74;
    }
    // 0x80047B50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047B54: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047B58: lwc1        $f9, 0x6430($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6430);
    // 0x80047B5C: lwc1        $f8, 0x6434($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6434);
    // 0x80047B60: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80047B64: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047B68: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80047B6C: b           L_80047BC8
    // 0x80047B70: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
        goto L_80047BC8;
    // 0x80047B70: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
L_80047B74:
    // 0x80047B74: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x80047B78: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047B7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047B80: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047B84: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80047B88: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x80047B8C: bc1t        L_80047BAC
    if (c1cs) {
        // 0x80047B90: nop
    
            goto L_80047BAC;
    }
    // 0x80047B90: nop

    // 0x80047B94: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80047B98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047B9C: nop

    // 0x80047BA0: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80047BA4: nop

    // 0x80047BA8: bc1f        L_80047BC8
    if (!c1cs) {
        // 0x80047BAC: lui         $at, 0x3FF8
        ctx->r1 = S32(0X3FF8 << 16);
            goto L_80047BC8;
    }
L_80047BAC:
    // 0x80047BAC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80047BB0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047BB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047BB8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80047BBC: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80047BC0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80047BC4: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
L_80047BC8:
    // 0x80047BC8: beq         $t5, $zero, L_80047BE0
    if (ctx->r13 == 0) {
        // 0x80047BCC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80047BE0;
    }
    // 0x80047BCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047BD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047BD4: nop

    // 0x80047BD8: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80047BDC: nop

L_80047BE0:
    // 0x80047BE0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80047BE4: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047BE8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047BEC: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047BF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047BF4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80047BF8: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047BFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80047C00: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80047C04: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047C08: nop

    // 0x80047C0C: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047C10: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047C14: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047C18: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x80047C1C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047C20: nop

    // 0x80047C24: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047C28: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047C2C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047C30: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047C34: nop

    // 0x80047C38: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80047C3C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80047C40: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047C44: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047C48: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80047C4C: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80047C50: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x80047C54: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047C58: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047C5C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047C60: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047C64: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80047C68: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80047C6C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047C70: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047C74: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047C78: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80047C7C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80047C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047C84: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x80047C88: div.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80047C8C: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047C90: nop

    // 0x80047C94: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047C98: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80047C9C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047CA0: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047CA4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047CA8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80047CAC: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80047CB0: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047CB4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047CB8: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047CBC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80047CC0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80047CC4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80047CC8: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047CCC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047CD0: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047CD4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80047CD8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80047CDC: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047CE0: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047CE4: nop

    // 0x80047CE8: beq         $t9, $zero, L_80047DB0
    if (ctx->r25 == 0) {
        // 0x80047CEC: nop
    
            goto L_80047DB0;
    }
    // 0x80047CEC: nop

    // 0x80047CF0: lb          $t2, -0x2A7C($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2A7C);
    // 0x80047CF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80047CF8: bne         $t2, $zero, L_80047DB0
    if (ctx->r10 != 0) {
        // 0x80047CFC: nop
    
            goto L_80047DB0;
    }
    // 0x80047CFC: nop

    // 0x80047D00: lw          $t4, -0x2AC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AC0);
    // 0x80047D04: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80047D08: bne         $t4, $zero, L_80047DB0
    if (ctx->r12 != 0) {
        // 0x80047D0C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80047DB0;
    }
    // 0x80047D0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047D10: lwc1        $f6, -0x2A94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x80047D14: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80047D18: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047D1C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047D20: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047D24: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80047D28: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80047D2C: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80047D30: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80047D34: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047D38: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80047D3C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047D40: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80047D44: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80047D48: nop

    // 0x80047D4C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047D50: nop

    // 0x80047D54: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047D58: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047D5C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80047D60: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80047D64: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x80047D68: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047D6C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047D70: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80047D74: nop

    // 0x80047D78: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80047D7C: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047D80: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80047D84: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80047D88: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80047D8C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047D90: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047D94: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80047D98: nop

    // 0x80047D9C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80047DA0: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047DA4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80047DA8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80047DAC: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_80047DB0:
    // 0x80047DB0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80047DB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047DB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047DBC: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80047DC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047DC4: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80047DC8: bc1f        L_80047DD4
    if (!c1cs) {
        // 0x80047DCC: nop
    
            goto L_80047DD4;
    }
    // 0x80047DCC: nop

    // 0x80047DD0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80047DD4:
    // 0x80047DD4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80047DD8: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80047DDC: bc1f        L_80047E14
    if (!c1cs) {
        // 0x80047DE0: nop
    
            goto L_80047E14;
    }
    // 0x80047DE0: nop

    // 0x80047DE4: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x80047DE8: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80047DEC: andi        $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 & 0X8000;
    // 0x80047DF0: bne         $t6, $zero, L_80047E14
    if (ctx->r14 != 0) {
        // 0x80047DF4: nop
    
            goto L_80047E14;
    }
    // 0x80047DF4: nop

    // 0x80047DF8: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80047DFC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80047E00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047E04: nop

    // 0x80047E08: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80047E0C: b           L_80047E20
    // 0x80047E10: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
        goto L_80047E20;
    // 0x80047E10: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
L_80047E14:
    // 0x80047E14: mul.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80047E18: nop

    // 0x80047E1C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
L_80047E20:
    // 0x80047E20: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047E24: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047E28: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047E2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047E30: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047E34: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80047E38: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047E3C: nop

    // 0x80047E40: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047E44: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047E48: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047E4C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x80047E50: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047E54: nop

    // 0x80047E58: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047E5C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047E60: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047E64: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x80047E68: nop

    // 0x80047E6C: beq         $t7, $zero, L_80047E8C
    if (ctx->r15 == 0) {
        // 0x80047E70: nop
    
            goto L_80047E8C;
    }
    // 0x80047E70: nop

    // 0x80047E74: lwc1        $f6, -0x2A88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A88);
    // 0x80047E78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047E7C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80047E80: lwc1        $f8, -0x2A84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A84);
    // 0x80047E84: nop

    // 0x80047E88: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
L_80047E8C:
    // 0x80047E8C: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x80047E90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80047E94: lw          $t8, -0x2AAC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AAC);
    // 0x80047E98: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x80047E9C: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047EA0: subu        $t5, $t8, $v0
    ctx->r13 = SUB32(ctx->r24, ctx->r2);
    // 0x80047EA4: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80047EA8: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80047EAC: sh          $t2, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r10;
    // 0x80047EB0: lh          $t3, 0x1A2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A2);
    // 0x80047EB4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80047EB8: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80047EBC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x80047EC0: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x80047EC4: lw          $t7, -0x2AA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA8);
    // 0x80047EC8: lh          $t2, 0x1A4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A4);
    // 0x80047ECC: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80047ED0: sra         $t5, $t8, 3
    ctx->r13 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80047ED4: addu        $t9, $v1, $t5
    ctx->r25 = ADD32(ctx->r3, ctx->r13);
    // 0x80047ED8: sh          $t9, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r25;
    // 0x80047EDC: lh          $t4, 0x1A6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A6);
    // 0x80047EE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80047EE4: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80047EE8: sh          $t3, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r11;
    // 0x80047EEC: lb          $a0, 0x1D2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1D2);
    // 0x80047EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047EF4: blez        $a0, L_80047F04
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80047EF8: subu        $t6, $a0, $t0
        ctx->r14 = SUB32(ctx->r4, ctx->r8);
            goto L_80047F04;
    }
    // 0x80047EF8: subu        $t6, $a0, $t0
    ctx->r14 = SUB32(ctx->r4, ctx->r8);
    // 0x80047EFC: b           L_80047F08
    // 0x80047F00: sb          $t6, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r14;
        goto L_80047F08;
    // 0x80047F00: sb          $t6, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r14;
L_80047F04:
    // 0x80047F04: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_80047F08:
    // 0x80047F08: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047F0C: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80047F10: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047F14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047F18: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047F1C: lwc1        $f2, 0xE8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80047F20: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047F24: lwc1        $f14, 0xE4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80047F28: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x80047F2C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047F30: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80047F34: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047F38: bne         $t7, $zero, L_800480A0
    if (ctx->r15 != 0) {
        // 0x80047F3C: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_800480A0;
    }
    // 0x80047F3C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80047F40: lb          $t8, 0x1D2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D2);
    // 0x80047F44: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047F48: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047F4C: beq         $t8, $zero, L_80047F64
    if (ctx->r24 == 0) {
        // 0x80047F50: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80047F64;
    }
    // 0x80047F50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80047F54: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x80047F58: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80047F5C: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80047F60: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_80047F64:
    // 0x80047F64: lb          $t5, -0x2A7C($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2A7C);
    // 0x80047F68: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80047F6C: beq         $t5, $zero, L_80048028
    if (ctx->r13 == 0) {
        // 0x80047F70: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80048028;
    }
    // 0x80047F70: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80047F74: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047F78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047F7C: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80047F80: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80047F84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047F88: bc1t        L_80047FA8
    if (c1cs) {
        // 0x80047F8C: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_80047FA8;
    }
    // 0x80047F8C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80047F90: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80047F94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047F98: nop

    // 0x80047F9C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80047FA0: nop

    // 0x80047FA4: bc1f        L_80047FC4
    if (!c1cs) {
        // 0x80047FA8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80047FC4;
    }
L_80047FA8:
    // 0x80047FA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FAC: lwc1        $f11, 0x6438($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6438);
    // 0x80047FB0: lwc1        $f10, 0x643C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X643C);
    // 0x80047FB4: nop

    // 0x80047FB8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80047FBC: b           L_80047FCC
    // 0x80047FC0: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
        goto L_80047FCC;
    // 0x80047FC0: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_80047FC4:
    // 0x80047FC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80047FC8: nop

L_80047FCC:
    // 0x80047FCC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80047FD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047FD4: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80047FD8: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80047FDC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80047FE0: bc1t        L_80048000
    if (c1cs) {
        // 0x80047FE4: nop
    
            goto L_80048000;
    }
    // 0x80047FE4: nop

    // 0x80047FE8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80047FEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047FF0: nop

    // 0x80047FF4: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80047FF8: nop

    // 0x80047FFC: bc1f        L_8004801C
    if (!c1cs) {
        // 0x80048000: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004801C;
    }
L_80048000:
    // 0x80048000: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048004: lwc1        $f11, 0x6440($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6440);
    // 0x80048008: lwc1        $f10, 0x6444($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6444);
    // 0x8004800C: nop

    // 0x80048010: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80048014: b           L_80048044
    // 0x80048018: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_80048044;
    // 0x80048018: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_8004801C:
    // 0x8004801C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80048020: b           L_80048048
    // 0x80048024: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
        goto L_80048048;
    // 0x80048024: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
L_80048028:
    // 0x80048028: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004802C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80048030: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80048034: nop

    // 0x80048038: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004803C: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80048040: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_80048044:
    // 0x80048044: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
L_80048048:
    // 0x80048048: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004804C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80048050: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x80048054: swc1        $f2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f2.u32l;
    // 0x80048058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004805C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80048060: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80048064: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80048068: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004806C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80048070: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80048074: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80048078: jal         0x80011570
    // 0x8004807C: nop

    move_object(rdram, ctx);
        goto after_28;
    // 0x8004807C: nop

    after_28:
    // 0x80048080: beq         $v0, $zero, L_800480C0
    if (ctx->r2 == 0) {
        // 0x80048084: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800480C0;
    }
    // 0x80048084: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80048088: lw          $t9, -0x2AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA4);
    // 0x8004808C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048090: beq         $t9, $at, L_800480C0
    if (ctx->r25 == ctx->r1) {
        // 0x80048094: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800480C0;
    }
    // 0x80048094: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80048098: b           L_800480C0
    // 0x8004809C: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
        goto L_800480C0;
    // 0x8004809C: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
L_800480A0:
    // 0x800480A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800480A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800480A8: lw          $a2, 0x12C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X12C);
    // 0x800480AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800480B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800480B4: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x800480B8: jal         0x80050754
    // 0x800480BC: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    racer_approach_object(rdram, ctx);
        goto after_29;
    // 0x800480BC: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    after_29:
L_800480C0:
    // 0x800480C0: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800480C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800480C8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800480CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800480D0: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800480D4: mul.d       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800480D8: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800480DC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800480E0: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x800480E4: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x800480E8: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x800480EC: sub.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d - ctx->f10.d;
    // 0x800480F0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800480F4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800480F8: swc1        $f8, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
    // 0x800480FC: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048104: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80048108: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004810C: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80048110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048114: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80048118: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004811C: swc1        $f10, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f10.u32l;
    // 0x80048120: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80048124: lwc1        $f8, 0x644C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X644C);
    // 0x80048128: lwc1        $f9, 0x6448($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6448);
    // 0x8004812C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80048130: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80048134: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048138: bc1f        L_80048158
    if (!c1cs) {
        // 0x8004813C: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_80048158;
    }
    // 0x8004813C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048140: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048144: nop

    // 0x80048148: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    // 0x8004814C: lwc1        $f10, 0xD4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80048150: nop

    // 0x80048154: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
L_80048158:
    // 0x80048158: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004815C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80048160: bc1f        L_80048174
    if (!c1cs) {
        // 0x80048164: nop
    
            goto L_80048174;
    }
    // 0x80048164: nop

    // 0x80048168: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004816C: nop

    // 0x80048170: swc1        $f8, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f8.u32l;
L_80048174:
    // 0x80048174: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048178: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004817C: lwc1        $f6, 0x6450($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80048180: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x80048184: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x80048188: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004818C: jal         0x8002AD08
    // 0x80048190: swc1        $f14, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f14.u32l;
    get_wave_properties(rdram, ctx);
        goto after_30;
    // 0x80048190: swc1        $f14, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f14.u32l;
    after_30:
    // 0x80048194: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x80048198: sll         $t3, $v0, 24
    ctx->r11 = S32(ctx->r2 << 24);
    // 0x8004819C: sra         $t6, $t3, 24
    ctx->r14 = S32(SIGNED(ctx->r11) >> 24);
    // 0x800481A0: sra         $t4, $a3, 24
    ctx->r12 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800481A4: lwc1        $f14, 0x114($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800481A8: beq         $t6, $zero, L_80048240
    if (ctx->r14 == 0) {
        // 0x800481AC: or          $a3, $t4, $zero
        ctx->r7 = ctx->r12 | 0;
            goto L_80048240;
    }
    // 0x800481AC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x800481B0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800481B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800481B8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800481BC: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x800481C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800481C4: bc1f        L_800481D0
    if (!c1cs) {
        // 0x800481C8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800481D0;
    }
    // 0x800481C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800481CC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_800481D0:
    // 0x800481D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800481D4: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x800481D8: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800481DC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800481E0: bc1f        L_800481F4
    if (!c1cs) {
        // 0x800481E4: nop
    
            goto L_800481F4;
    }
    // 0x800481E4: nop

    // 0x800481E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800481EC: nop

    // 0x800481F0: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
L_800481F4:
    // 0x800481F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800481F8: lwc1        $f9, 0x6458($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6458);
    // 0x800481FC: lwc1        $f8, 0x645C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X645C);
    // 0x80048200: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048204: mul.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x80048208: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8004820C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80048210: sub.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80048214: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80048218: nop

    // 0x8004821C: bc1f        L_80048234
    if (!c1cs) {
        // 0x80048220: nop
    
            goto L_80048234;
    }
    // 0x80048220: nop

    // 0x80048224: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80048228: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    // 0x8004822C: b           L_80048240
    // 0x80048230: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
        goto L_80048240;
    // 0x80048230: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
L_80048234:
    // 0x80048234: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048238: nop

    // 0x8004823C: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
L_80048240:
    // 0x80048240: lb          $v0, 0x1E5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E5);
    // 0x80048244: nop

    // 0x80048248: blez        $v0, L_80048258
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004824C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80048258;
    }
    // 0x8004824C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80048250: b           L_80048264
    // 0x80048254: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
        goto L_80048264;
    // 0x80048254: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
L_80048258:
    // 0x80048258: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004825C: nop

    // 0x80048260: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_80048264:
    // 0x80048264: lb          $t5, 0x1E5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E5);
    // 0x80048268: nop

    // 0x8004826C: blez        $t5, L_800482AC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80048270: nop
    
            goto L_800482AC;
    }
    // 0x80048270: nop

    // 0x80048274: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80048278: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004827C: add.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80048280: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80048284: nop

    // 0x80048288: bc1f        L_800482AC
    if (!c1cs) {
        // 0x8004828C: nop
    
            goto L_800482AC;
    }
    // 0x8004828C: nop

    // 0x80048290: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x80048294: nop

    // 0x80048298: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x8004829C: nop

    // 0x800482A0: ori         $t2, $t9, 0x10
    ctx->r10 = ctx->r25 | 0X10;
    // 0x800482A4: b           L_800482C4
    // 0x800482A8: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
        goto L_800482C4;
    // 0x800482A8: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
L_800482AC:
    // 0x800482AC: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800482B0: nop

    // 0x800482B4: lh          $t4, 0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X14);
    // 0x800482B8: nop

    // 0x800482BC: andi        $t3, $t4, 0xFFEF
    ctx->r11 = ctx->r12 & 0XFFEF;
    // 0x800482C0: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
L_800482C4:
    // 0x800482C4: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800482C8: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800482CC: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800482D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800482D4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800482D8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800482DC: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x800482E0: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800482E4: nop

    // 0x800482E8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800482EC: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x800482F0: nop

    // 0x800482F4: bc1f        L_80048354
    if (!c1cs) {
        // 0x800482F8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80048354;
    }
    // 0x800482F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800482FC: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x80048300: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80048304: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80048308: beq         $t7, $zero, L_80048324
    if (ctx->r15 == 0) {
        // 0x8004830C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048324;
    }
    // 0x8004830C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048310: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80048314: lw          $t0, -0x2ACC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2ACC);
    // 0x80048318: nop

    // 0x8004831C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x80048320: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_80048324:
    // 0x80048324: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004832C: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80048330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048334: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x80048338: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8004833C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80048340: jal         0x800494E0
    // 0x80048344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    rotate_racer_in_water(rdram, ctx);
        goto after_31;
    // 0x80048344: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_31:
    // 0x80048348: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004834C: nop

    // 0x80048350: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80048354:
    // 0x80048354: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80048358: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004835C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80048360: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80048364: nop

    // 0x80048368: bc1f        L_800483B8
    if (!c1cs) {
        // 0x8004836C: nop
    
            goto L_800483B8;
    }
    // 0x8004836C: nop

    // 0x80048370: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80048374: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048378: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8004837C: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80048380: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80048384: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80048388: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004838C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048390: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x80048394: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80048398: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004839C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800483A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800483A4: sub.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d - ctx->f0.d;
    // 0x800483A8: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800483AC: add.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d + ctx->f8.d;
    // 0x800483B0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800483B4: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_800483B8:
    // 0x800483B8: lw          $t9, -0x2AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA4);
    // 0x800483BC: lb          $t0, 0x1D2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D2);
    // 0x800483C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800483C4: bne         $t9, $at, L_80048400
    if (ctx->r25 != ctx->r1) {
        // 0x800483C8: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80048400;
    }
    // 0x800483C8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x800483CC: jal         0x80023568
    // 0x800483D0: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    func_80023568(rdram, ctx);
        goto after_32;
    // 0x800483D0: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_32:
    // 0x800483D4: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800483D8: bne         $v0, $zero, L_800483FC
    if (ctx->r2 != 0) {
        // 0x800483DC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800483FC;
    }
    // 0x800483DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800483E0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x800483E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800483E8: jal         0x80055A84
    // 0x800483EC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_33;
    // 0x800483EC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_33:
    // 0x800483F0: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800483F4: b           L_80048418
    // 0x800483F8: nop

        goto L_80048418;
    // 0x800483F8: nop

L_800483FC:
    // 0x800483FC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_80048400:
    // 0x80048400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048404: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048408: jal         0x80054FD0
    // 0x8004840C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    func_80054FD0(rdram, ctx);
        goto after_34;
    // 0x8004840C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_34:
    // 0x80048410: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80048414: nop

L_80048418:
    // 0x80048418: bne         $t0, $zero, L_80048434
    if (ctx->r8 != 0) {
        // 0x8004841C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80048434;
    }
    // 0x8004841C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048420: lb          $t2, 0x1D2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D2);
    // 0x80048424: nop

    // 0x80048428: beq         $t2, $zero, L_80048434
    if (ctx->r10 == 0) {
        // 0x8004842C: nop
    
            goto L_80048434;
    }
    // 0x8004842C: nop

    // 0x80048430: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80048434:
    // 0x80048434: sb          $t0, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r8;
    // 0x80048438: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8004843C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048440: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80048444: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80048448: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8004844C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80048450: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80048454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048458: lwc1        $f10, -0x2AB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x8004845C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80048460: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80048464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048468: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8004846C: addiu       $v1, $v1, -0x3468
    ctx->r3 = ADD32(ctx->r3, -0X3468);
    // 0x80048470: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80048474: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80048478: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004847C: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80048480: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80048484: lwc1        $f6, -0x2AB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x80048488: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004848C: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x80048490: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80048494: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048498: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004849C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800484A0: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x800484A4: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800484A8: nop

    // 0x800484AC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800484B0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800484B4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x800484B8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800484BC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800484C0: lwc1        $f8, 0x6464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6464);
    // 0x800484C4: lwc1        $f9, 0x6460($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6460);
    // 0x800484C8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800484CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800484D0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800484D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800484D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800484DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800484E0: add.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d + ctx->f10.d;
    // 0x800484E4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800484E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800484EC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800484F0: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x800484F4: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800484F8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800484FC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048500: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80048504: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80048508: bc1f        L_8004854C
    if (!c1cs) {
        // 0x8004850C: nop
    
            goto L_8004854C;
    }
    // 0x8004850C: nop

    // 0x80048510: lb          $t4, 0x1FB($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048514: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80048518: bne         $t4, $zero, L_8004854C
    if (ctx->r12 != 0) {
        // 0x8004851C: nop
    
            goto L_8004854C;
    }
    // 0x8004851C: nop

    // 0x80048520: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048524: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048528: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004852C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80048530: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80048534: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048538: bc1f        L_8004854C
    if (!c1cs) {
        // 0x8004853C: nop
    
            goto L_8004854C;
    }
    // 0x8004853C: nop

    // 0x80048540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048544: nop

    // 0x80048548: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_8004854C:
    // 0x8004854C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80048550: nop

    // 0x80048554: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80048558: beq         $at, $zero, L_800485F4
    if (ctx->r1 == 0) {
        // 0x8004855C: nop
    
            goto L_800485F4;
    }
    // 0x8004855C: nop

    // 0x80048560: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x80048564: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80048568: lb          $t7, 0x57($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X57);
    // 0x8004856C: nop

    // 0x80048570: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x80048574: bne         $at, $zero, L_800485F4
    if (ctx->r1 != 0) {
        // 0x80048578: nop
    
            goto L_800485F4;
    }
    // 0x80048578: nop

    // 0x8004857C: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x80048580: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80048584: andi        $t5, $t8, 0x8010
    ctx->r13 = ctx->r24 & 0X8010;
    // 0x80048588: bne         $t5, $at, L_800485D0
    if (ctx->r13 != ctx->r1) {
        // 0x8004858C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800485D0;
    }
    // 0x8004858C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80048590: lw          $v0, -0x2ACC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2ACC);
    // 0x80048594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048598: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8004859C: bne         $at, $zero, L_800485B0
    if (ctx->r1 != 0) {
        // 0x800485A0: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_800485B0;
    }
    // 0x800485A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800485A4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800485A8: bne         $at, $zero, L_800485D4
    if (ctx->r1 != 0) {
        // 0x800485AC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_800485D4;
    }
    // 0x800485AC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_800485B0:
    // 0x800485B0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x800485B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800485B8: sll         $t9, $a2, 10
    ctx->r25 = S32(ctx->r6 << 10);
    // 0x800485BC: jal         0x800B4668
    // 0x800485C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    increase_emitter_opacity(rdram, ctx);
        goto after_35;
    // 0x800485C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_35:
    // 0x800485C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800485C8: b           L_800485F4
    // 0x800485CC: addiu       $v1, $v1, -0x3468
    ctx->r3 = ADD32(ctx->r3, -0X3468);
        goto L_800485F4;
    // 0x800485CC: addiu       $v1, $v1, -0x3468
    ctx->r3 = ADD32(ctx->r3, -0X3468);
L_800485D0:
    // 0x800485D0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_800485D4:
    // 0x800485D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800485D8: sll         $t2, $a2, 9
    ctx->r10 = S32(ctx->r6 << 9);
    // 0x800485DC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800485E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800485E4: jal         0x800B46BC
    // 0x800485E8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    decrease_emitter_opacity(rdram, ctx);
        goto after_36;
    // 0x800485E8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_36:
    // 0x800485EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800485F0: addiu       $v1, $v1, -0x3468
    ctx->r3 = ADD32(ctx->r3, -0X3468);
L_800485F4:
    // 0x800485F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800485F8: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x800485FC: nop

    // 0x80048600: bltz        $v0, L_80048760
    if (SIGNED(ctx->r2) < 0) {
        // 0x80048604: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80048760;
    }
    // 0x80048604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048608: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004860C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80048610: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048614: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048618: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8004861C: nop

    // 0x80048620: bc1f        L_80048760
    if (!c1cs) {
        // 0x80048624: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80048760;
    }
    // 0x80048624: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048628: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004862C: nop

    // 0x80048630: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80048634: beq         $at, $zero, L_8004870C
    if (ctx->r1 == 0) {
        // 0x80048638: nop
    
            goto L_8004870C;
    }
    // 0x80048638: nop

    // 0x8004863C: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048640: lwc1        $f12, 0x20($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048644: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80048648: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004864C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80048650: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80048654: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80048658: nop

    // 0x8004865C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80048660: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80048664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048668: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8004866C: add.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80048670: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80048674: nop

    // 0x80048678: bc1f        L_80048700
    if (!c1cs) {
        // 0x8004867C: nop
    
            goto L_80048700;
    }
    // 0x8004867C: nop

    // 0x80048680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048684: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80048688: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8004868C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048690: bc1f        L_800486A8
    if (!c1cs) {
        // 0x80048694: nop
    
            goto L_800486A8;
    }
    // 0x80048694: nop

    // 0x80048698: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x8004869C: nop

    // 0x800486A0: ori         $t6, $t3, 0xC
    ctx->r14 = ctx->r11 | 0XC;
    // 0x800486A4: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
L_800486A8:
    // 0x800486A8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800486AC: nop

    // 0x800486B0: bc1f        L_800486C8
    if (!c1cs) {
        // 0x800486B4: nop
    
            goto L_800486C8;
    }
    // 0x800486B4: nop

    // 0x800486B8: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x800486BC: nop

    // 0x800486C0: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x800486C4: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_800486C8:
    // 0x800486C8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800486CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800486D0: bne         $t5, $at, L_80048700
    if (ctx->r13 != ctx->r1) {
        // 0x800486D4: lui         $at, 0x4124
        ctx->r1 = S32(0X4124 << 16);
            goto L_80048700;
    }
    // 0x800486D4: lui         $at, 0x4124
    ctx->r1 = S32(0X4124 << 16);
    // 0x800486D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800486DC: nop

    // 0x800486E0: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800486E4: nop

    // 0x800486E8: bc1f        L_80048700
    if (!c1cs) {
        // 0x800486EC: nop
    
            goto L_80048700;
    }
    // 0x800486EC: nop

    // 0x800486F0: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x800486F4: nop

    // 0x800486F8: ori         $t2, $t9, 0x40
    ctx->r10 = ctx->r25 | 0X40;
    // 0x800486FC: sw          $t2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r10;
L_80048700:
    // 0x80048700: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x80048704: b           L_80048760
    // 0x80048708: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80048760;
    // 0x80048708: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8004870C:
    // 0x8004870C: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80048710: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048714: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048718: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8004871C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048720: bc1f        L_80048730
    if (!c1cs) {
        // 0x80048724: nop
    
            goto L_80048730;
    }
    // 0x80048724: nop

    // 0x80048728: b           L_80048734
    // 0x8004872C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80048734;
    // 0x8004872C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
L_80048730:
    // 0x80048730: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80048734:
    // 0x80048734: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80048738: nop

    // 0x8004873C: bc1f        L_80048760
    if (!c1cs) {
        // 0x80048740: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80048760;
    }
    // 0x80048740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048744: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x80048748: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004874C: ori         $t3, $t4, 0xC
    ctx->r11 = ctx->r12 | 0XC;
    // 0x80048750: sw          $t3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r11;
    // 0x80048754: lw          $v0, -0x2AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA4);
    // 0x80048758: nop

    // 0x8004875C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80048760:
    // 0x80048760: beq         $v0, $at, L_8004887C
    if (ctx->r2 == ctx->r1) {
        // 0x80048764: nop
    
            goto L_8004887C;
    }
    // 0x80048764: nop

    // 0x80048768: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004876C: nop

    // 0x80048770: bne         $t6, $zero, L_8004887C
    if (ctx->r14 != 0) {
        // 0x80048774: nop
    
            goto L_8004887C;
    }
    // 0x80048774: nop

    // 0x80048778: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8004877C: nop

    // 0x80048780: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80048784: beq         $at, $zero, L_8004887C
    if (ctx->r1 == 0) {
        // 0x80048788: nop
    
            goto L_8004887C;
    }
    // 0x80048788: nop

    // 0x8004878C: jal         0x8001E29C
    // 0x80048790: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_37;
    // 0x80048790: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_37:
    // 0x80048794: lb          $t0, 0x203($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X203);
    // 0x80048798: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x8004879C: andi        $t9, $t0, 0x4
    ctx->r25 = ctx->r8 & 0X4;
    // 0x800487A0: sra         $t2, $t9, 2
    ctx->r10 = S32(SIGNED(ctx->r25) >> 2);
    // 0x800487A4: addiu       $t0, $t2, 0xA
    ctx->r8 = ADD32(ctx->r10, 0XA);
    // 0x800487A8: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x800487AC: sll         $t5, $t8, 7
    ctx->r13 = S32(ctx->r24 << 7);
    // 0x800487B0: bne         $at, $zero, L_800487FC
    if (ctx->r1 != 0) {
        // 0x800487B4: addu        $v1, $t5, $v0
        ctx->r3 = ADD32(ctx->r13, ctx->r2);
            goto L_800487FC;
    }
    // 0x800487B4: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800487B8: lbu         $t4, 0x70($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X70);
    // 0x800487BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800487C0: bgtz        $t4, L_800487E8
    if (SIGNED(ctx->r12) > 0) {
        // 0x800487C4: nop
    
            goto L_800487E8;
    }
    // 0x800487C4: nop

    // 0x800487C8: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x800487CC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800487D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800487D4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800487D8: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x800487DC: nop

    // 0x800487E0: bc1f        L_8004887C
    if (!c1cs) {
        // 0x800487E4: nop
    
            goto L_8004887C;
    }
    // 0x800487E4: nop

L_800487E8:
    // 0x800487E8: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x800487EC: sllv        $t7, $t6, $t0
    ctx->r15 = S32(ctx->r14 << (ctx->r8 & 31));
    // 0x800487F0: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800487F4: b           L_8004887C
    // 0x800487F8: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_8004887C;
    // 0x800487F8: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_800487FC:
    // 0x800487FC: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80048800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048804: bne         $v0, $at, L_80048848
    if (ctx->r2 != ctx->r1) {
        // 0x80048808: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80048848;
    }
    // 0x80048808: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004880C: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80048810: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80048814: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048818: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004881C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048820: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80048824: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80048828: bc1f        L_80048848
    if (!c1cs) {
        // 0x8004882C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80048848;
    }
    // 0x8004882C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80048830: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x80048834: sllv        $t2, $t9, $t0
    ctx->r10 = S32(ctx->r25 << (ctx->r8 & 31));
    // 0x80048838: or          $t4, $t5, $t2
    ctx->r12 = ctx->r13 | ctx->r10;
    // 0x8004883C: b           L_8004887C
    // 0x80048840: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
        goto L_8004887C;
    // 0x80048840: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
    // 0x80048844: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80048848:
    // 0x80048848: beq         $at, $zero, L_8004887C
    if (ctx->r1 == 0) {
        // 0x8004884C: nop
    
            goto L_8004887C;
    }
    // 0x8004884C: nop

    // 0x80048850: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048854: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80048858: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004885C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80048860: nop

    // 0x80048864: bc1f        L_8004887C
    if (!c1cs) {
        // 0x80048868: nop
    
            goto L_8004887C;
    }
    // 0x80048868: nop

    // 0x8004886C: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x80048870: sllv        $t7, $t3, $t0
    ctx->r15 = S32(ctx->r11 << (ctx->r8 & 31));
    // 0x80048874: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80048878: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_8004887C:
    // 0x8004887C: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
    // 0x80048880: nop

    // 0x80048884: bne         $t9, $zero, L_80048898
    if (ctx->r25 != 0) {
        // 0x80048888: lw          $t5, 0x128($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X128);
            goto L_80048898;
    }
    // 0x80048888: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x8004888C: b           L_800488E4
    // 0x80048890: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
        goto L_800488E4;
    // 0x80048890: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x80048894: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
L_80048898:
    // 0x80048898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004889C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800488A0: lwc1        $f10, -0x2A94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x800488A4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800488A8: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800488AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800488B0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800488B4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800488B8: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x800488BC: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800488C0: jal         0x800AF714
    // 0x800488C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    update_vehicle_particles(rdram, ctx);
        goto after_38;
    // 0x800488C4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x800488C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800488CC: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800488D0: lwc1        $f8, -0x2A94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x800488D4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800488D8: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800488DC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800488E0: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
L_800488E4:
    // 0x800488E4: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x800488E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800488EC: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x800488F0: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x800488F4: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x800488F8: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x800488FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048900: negu        $t6, $t3
    ctx->r14 = SUB32(0, ctx->r11);
    // 0x80048904: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    // 0x80048908: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x8004890C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048910: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048914: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048918: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004891C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80048920: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x80048924: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80048928: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8004892C: swc1        $f10, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f10.u32l;
    // 0x80048930: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80048934: jal         0x8006FE74
    // 0x80048938: swc1        $f6, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f6.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_39;
    // 0x80048938: swc1        $f6, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f6.u32l;
    after_39:
    // 0x8004893C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80048940: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80048944: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80048948: addiu       $t9, $s0, 0x30
    ctx->r25 = ADD32(ctx->r16, 0X30);
    // 0x8004894C: addiu       $t5, $s0, 0x34
    ctx->r13 = ADD32(ctx->r16, 0X34);
    // 0x80048950: addiu       $t2, $s0, 0x2C
    ctx->r10 = ADD32(ctx->r16, 0X2C);
    // 0x80048954: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80048958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004895C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80048960: jal         0x8006F64C
    // 0x80048964: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    mtxf_transform_point(rdram, ctx);
        goto after_40;
    // 0x80048964: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_40:
    // 0x80048968: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004896C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048970: bne         $t4, $zero, L_80048A20
    if (ctx->r12 != 0) {
        // 0x80048974: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80048A20;
    }
    // 0x80048974: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80048978: lb          $t3, 0x1E5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004897C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80048980: bne         $t3, $zero, L_80048A20
    if (ctx->r11 != 0) {
        // 0x80048984: ori         $at, $zero, 0x8001
        ctx->r1 = 0 | 0X8001;
            goto L_80048A20;
    }
    // 0x80048984: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80048988: lw          $t0, -0x2AC8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC8);
    // 0x8004898C: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80048990: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80048994: sll         $t6, $t0, 6
    ctx->r14 = S32(ctx->r8 << 6);
    // 0x80048998: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8004899C: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800489A0: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x800489A4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800489A8: bne         $at, $zero, L_800489B8
    if (ctx->r1 != 0) {
        // 0x800489AC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800489B8;
    }
    // 0x800489AC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800489B0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800489B4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800489B8:
    // 0x800489B8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800489BC: beq         $at, $zero, L_800489C8
    if (ctx->r1 == 0) {
        // 0x800489C0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800489C8;
    }
    // 0x800489C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800489C4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800489C8:
    // 0x800489C8: sra         $t9, $v1, 2
    ctx->r25 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800489CC: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x800489D0: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x800489D4: lh          $a1, 0x1A4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A4);
    // 0x800489D8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800489DC: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800489E0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800489E4: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800489E8: lw          $t2, 0x128($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X128);
    // 0x800489EC: bne         $at, $zero, L_800489FC
    if (ctx->r1 != 0) {
        // 0x800489F0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800489FC;
    }
    // 0x800489F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800489F4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800489F8: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800489FC:
    // 0x800489FC: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80048A00: beq         $at, $zero, L_80048A0C
    if (ctx->r1 == 0) {
        // 0x80048A04: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80048A0C;
    }
    // 0x80048A04: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048A08: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80048A0C:
    // 0x80048A0C: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048A10: mflo        $v0
    ctx->r2 = lo;
    // 0x80048A14: sra         $t4, $v0, 4
    ctx->r12 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80048A18: addu        $t3, $a1, $t4
    ctx->r11 = ADD32(ctx->r5, ctx->r12);
    // 0x80048A1C: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
L_80048A20:
    // 0x80048A20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80048A24: lw          $t6, -0x2AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC0);
    // 0x80048A28: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80048A2C: beq         $t6, $zero, L_80048A4C
    if (ctx->r14 == 0) {
        // 0x80048A30: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048A4C;
    }
    // 0x80048A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048A34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80048A38: lw          $t7, -0x2AD4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD4);
    // 0x80048A3C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80048A40: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80048A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048A48: sw          $t8, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = ctx->r24;
L_80048A4C:
    // 0x80048A4C: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048A50: nop

    // 0x80048A54: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80048A58: nop

    // 0x80048A5C: bc1f        L_80048A74
    if (!c1cs) {
        // 0x80048A60: nop
    
            goto L_80048A74;
    }
    // 0x80048A60: nop

    // 0x80048A64: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x80048A68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80048A6C: bne         $t9, $at, L_80048A78
    if (ctx->r25 != ctx->r1) {
        // 0x80048A70: nop
    
            goto L_80048A78;
    }
    // 0x80048A70: nop

L_80048A74:
    // 0x80048A74: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80048A78:
    // 0x80048A78: lw          $t5, -0x2AD4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD4);
    // 0x80048A7C: nop

    // 0x80048A80: andi        $t2, $t5, 0x10
    ctx->r10 = ctx->r13 & 0X10;
    // 0x80048A84: beq         $t2, $zero, L_80048BB0
    if (ctx->r10 == 0) {
        // 0x80048A88: nop
    
            goto L_80048BB0;
    }
    // 0x80048A88: nop

    // 0x80048A8C: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048A90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048A94: nop

    // 0x80048A98: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80048A9C: nop

    // 0x80048AA0: bc1t        L_80048ABC
    if (c1cs) {
        // 0x80048AA4: nop
    
            goto L_80048ABC;
    }
    // 0x80048AA4: nop

    // 0x80048AA8: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x80048AAC: nop

    // 0x80048AB0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80048AB4: bne         $at, $zero, L_80048BB0
    if (ctx->r1 != 0) {
        // 0x80048AB8: nop
    
            goto L_80048BB0;
    }
    // 0x80048AB8: nop

L_80048ABC:
    // 0x80048ABC: lb          $t3, 0x1FB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048AC0: nop

    // 0x80048AC4: bne         $t3, $zero, L_80048BB0
    if (ctx->r11 != 0) {
        // 0x80048AC8: nop
    
            goto L_80048BB0;
    }
    // 0x80048AC8: nop

    // 0x80048ACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048AD0: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x80048AD4: c.eq.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl == ctx->f12.fl;
    // 0x80048AD8: nop

    // 0x80048ADC: bc1t        L_80048B40
    if (c1cs) {
        // 0x80048AE0: nop
    
            goto L_80048B40;
    }
    // 0x80048AE0: nop

    // 0x80048AE4: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048AE8: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x80048AEC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048AF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048AF4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048AF8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80048AFC: lui         $at, 0x4016
    ctx->r1 = S32(0X4016 << 16);
    // 0x80048B00: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80048B04: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048B08: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80048B0C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048B14: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80048B18: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80048B1C: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x80048B20: bc1f        L_80048B68
    if (!c1cs) {
        // 0x80048B24: nop
    
            goto L_80048B68;
    }
    // 0x80048B24: nop

    // 0x80048B28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048B2C: nop

    // 0x80048B30: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80048B34: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B38: b           L_80048B68
    // 0x80048B3C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
        goto L_80048B68;
    // 0x80048B3C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_80048B40:
    // 0x80048B40: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B44: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80048B48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048B4C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80048B50: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80048B54: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80048B58: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80048B5C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B60: nop

    // 0x80048B64: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_80048B68:
    // 0x80048B68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048B6C: lwc1        $f8, -0x2A94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x80048B70: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x80048B74: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048B78: nop

    // 0x80048B7C: div.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80048B80: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80048B84: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80048B88: nop

    // 0x80048B8C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80048B90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048B94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048B98: nop

    // 0x80048B9C: cvt.w.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80048BA0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80048BA4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80048BA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80048BAC: sb          $t8, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r24;
L_80048BB0:
    // 0x80048BB0: lb          $v0, 0x1FB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048BB4: lw          $t9, 0x128($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X128);
    // 0x80048BB8: blez        $v0, L_80048BCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048BBC: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80048BCC;
    }
    // 0x80048BBC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80048BC0: subu        $t5, $v0, $t9
    ctx->r13 = SUB32(ctx->r2, ctx->r25);
    // 0x80048BC4: b           L_80048BD0
    // 0x80048BC8: sb          $t5, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r13;
        goto L_80048BD0;
    // 0x80048BC8: sb          $t5, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r13;
L_80048BCC:
    // 0x80048BCC: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80048BD0:
    // 0x80048BD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048BD4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80048BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048BDC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80048BE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80048BE4: bc1f        L_80048BF8
    if (!c1cs) {
        // 0x80048BE8: nop
    
            goto L_80048BF8;
    }
    // 0x80048BE8: nop

    // 0x80048BEC: lwc1        $f4, 0x6468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6468);
    // 0x80048BF0: nop

    // 0x80048BF4: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_80048BF8:
    // 0x80048BF8: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x80048BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048C00: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80048C04: nop

    // 0x80048C08: bne         $t2, $at, L_80048C48
    if (ctx->r10 != ctx->r1) {
        // 0x80048C0C: lw          $a3, 0x12C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X12C);
            goto L_80048C48;
    }
    // 0x80048C0C: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x80048C10: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80048C14: lw          $t4, -0x2ACC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2ACC);
    // 0x80048C18: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
    // 0x80048C1C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80048C20: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80048C24: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    // 0x80048C28: lb          $t9, 0x3A($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3A);
    // 0x80048C2C: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80048C30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80048C34: addiu       $t6, $t3, 0x4000
    ctx->r14 = ADD32(ctx->r11, 0X4000);
    // 0x80048C38: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80048C3C: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80048C40: sb          $t5, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r13;
    // 0x80048C44: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
L_80048C48:
    // 0x80048C48: jal         0x800580B4
    // 0x80048C4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    second_racer_camera_update(rdram, ctx);
        goto after_41;
    // 0x80048C4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_41:
    // 0x80048C50: lb          $t2, 0x67($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X67);
    // 0x80048C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048C58: beq         $t2, $zero, L_80048C6C
    if (ctx->r10 == 0) {
        // 0x80048C5C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80048C6C;
    }
    // 0x80048C5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80048C60: jal         0x800230D0
    // 0x80048C64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_42;
    // 0x80048C64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_42:
    // 0x80048C68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80048C6C:
    // 0x80048C6C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80048C70: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80048C74: jr          $ra
    // 0x80048C78: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80048C78: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void timetrial_reset_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059944: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059948: lb          $t6, -0x2A63($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A63);
    // 0x8005994C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059950: addiu       $v1, $v1, -0x2A64
    ctx->r3 = ADD32(ctx->r3, -0X2A64);
    // 0x80059954: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80059958: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8005995C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059960: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80059964: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80059968: sh          $zero, -0x2A60($at)
    MEM_H(-0X2A60, ctx->r1) = 0;
    // 0x8005996C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059970: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80059974: sh          $zero, -0x2A58($at)
    MEM_H(-0X2A58, ctx->r1) = 0;
    // 0x80059978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005997C: jr          $ra
    // 0x80059980: sh          $zero, -0x2A62($at)
    MEM_H(-0X2A62, ctx->r1) = 0;
    return;
    // 0x80059980: sh          $zero, -0x2A62($at)
    MEM_H(-0X2A62, ctx->r1) = 0;
;}
RECOMP_FUNC void render_sprite_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068514: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80068518: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8006851C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80068520: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80068524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068528: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8006852C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068530: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068534: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068538: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006853C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80068540: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80068544: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80068548: beq         $t8, $zero, L_8006889C
    if (ctx->r24 == 0) {
        // 0x8006854C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_8006889C;
    }
    // 0x8006854C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80068550: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80068554: lw          $v0, 0xD20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD20);
    // 0x80068558: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006855C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80068560: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068564: lwc1        $f4, 0xD28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XD28);
    // 0x80068568: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8006856C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068570: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80068574: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068578: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8006857C: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068580: lwc1        $f10, 0xD40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD40);
    // 0x80068584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068588: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8006858C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068590: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80068594: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068598: lwc1        $f6, 0xD58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD58);
    // 0x8006859C: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800685A0: jal         0x800707C4
    // 0x800685A4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800685A4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    after_0:
    // 0x800685A8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800685AC: jal         0x800707F8
    // 0x800685B0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800685B0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800685B4: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800685B8: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800685BC: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800685C0: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800685C4: mul.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800685C8: nop

    // 0x800685CC: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800685D0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800685D4: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800685D8: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800685DC: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800685E0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800685E4: nop

    // 0x800685E8: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800685EC: jal         0x800C9AD0
    // 0x800685F0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800685F0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_2:
    // 0x800685F4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800685F8: jal         0x80070750
    // 0x800685FC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x800685FC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x80068600: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068604: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80068608: jal         0x80070750
    // 0x8006860C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8006860C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x80068610: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80068614: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80068618: jal         0x80070830
    // 0x8006861C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    sins_s16(rdram, ctx);
        goto after_5;
    // 0x8006861C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x80068620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80068624: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80068628: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8006862C: sra         $t3, $v1, 8
    ctx->r11 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80068630: bc1f        L_80068650
    if (!c1cs) {
        // 0x80068634: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80068650;
    }
    // 0x80068634: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80068638: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8006863C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80068640: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80068644: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80068648: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x8006864C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80068650:
    // 0x80068650: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068654: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80068658: jal         0x80070750
    // 0x8006865C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    arctan2_f(rdram, ctx);
        goto after_6;
    // 0x8006865C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_6:
    // 0x80068660: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80068664: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80068668: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006866C: bne         $at, $zero, L_8006867C
    if (ctx->r1 != 0) {
        // 0x80068670: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006867C;
    }
    // 0x80068670: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80068674: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80068678: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
L_8006867C:
    // 0x8006867C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068680: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80068684: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80068688: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006868C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80068690: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x80068694: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80068698: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006869C: mflo        $v1
    ctx->r3 = lo;
    // 0x800686A0: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800686A4: bne         $at, $zero, L_800686BC
    if (ctx->r1 != 0) {
        // 0x800686A8: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800686BC;
    }
    // 0x800686A8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800686AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800686B0: subu        $s2, $t2, $t9
    ctx->r18 = SUB32(ctx->r10, ctx->r25);
    // 0x800686B4: addu        $v1, $t7, $at
    ctx->r3 = ADD32(ctx->r15, ctx->r1);
    // 0x800686B8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800686BC:
    // 0x800686BC: lw          $v0, 0xD20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD20);
    // 0x800686C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800686C4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800686C8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800686CC: lwc1        $f6, 0xD28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD28);
    // 0x800686D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800686D4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800686D8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800686DC: lwc1        $f10, 0xD40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD40);
    // 0x800686E0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800686E4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800686E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800686EC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800686F0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800686F4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800686F8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800686FC: lwc1        $f6, 0xD58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD58);
    // 0x80068700: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80068704: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068708: sll         $t3, $s2, 1
    ctx->r11 = S32(ctx->r18 << 1);
    // 0x8006870C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80068710: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80068714: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80068718: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006871C: jal         0x800C9AD0
    // 0x80068720: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80068720: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_7:
    // 0x80068724: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80068728: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8006872C: jal         0x80070750
    // 0x80068730: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_8;
    // 0x80068730: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_8:
    // 0x80068734: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068738: addiu       $a1, $a1, 0xCF0
    ctx->r5 = ADD32(ctx->r5, 0XCF0);
    // 0x8006873C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068740: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80068744: jal         0x80070750
    // 0x80068748: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_9;
    // 0x80068748: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    after_9:
    // 0x8006874C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068750: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80068754: addiu       $a1, $a1, 0xCF0
    ctx->r5 = ADD32(ctx->r5, 0XCF0);
    // 0x80068758: negu        $t5, $v0
    ctx->r13 = SUB32(0, ctx->r2);
    // 0x8006875C: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x80068760: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x80068764: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80068768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006876C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80068770: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068774: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x80068778: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x8006877C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80068780: nop

    // 0x80068784: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x80068788: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006878C: jal         0x8006FC30
    // 0x80068790: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_10;
    // 0x80068790: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    after_10:
    // 0x80068794: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068798: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x8006879C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800687A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800687A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800687A8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800687AC: addiu       $t3, $t3, 0xD70
    ctx->r11 = ADD32(ctx->r11, 0XD70);
    // 0x800687B0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    extern void dkr_vehicle_part_matrix_identity(uint8_t*, recomp_context*); dkr_vehicle_part_matrix_identity(rdram, ctx);
    // 0x800687B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800687B8: addiu       $s0, $s0, 0x1060
    ctx->r16 = ADD32(ctx->r16, 0X1060);
    // 0x800687BC: lw          $a1, -0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X4);
    // 0x800687C0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800687C4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800687C8: jal         0x8006F768
    // 0x800687CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_11;
    // 0x800687CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800687D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800687D4: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x800687D8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800687DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800687E0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800687E4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x800687E8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800687EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800687F0: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    // 0x800687F4: jal         0x8006F768
    // 0x800687F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_12;
    // 0x800687F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800687FC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80068800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068804: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80068808: jal         0x8006F870
    // 0x8006880C: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_13;
    // 0x8006880C: nop

    after_13:
    // 0x80068810: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068814: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x80068818: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8006881C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068820: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80068824: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068828: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006882C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068830: sw          $t7, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r15;
    // 0x80068834: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068838: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x8006883C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068840: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068844: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80068848: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8006884C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068850: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068854: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80068858: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8006885C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068860: lui         $a1, 0xE
    ctx->r5 = S32(0XE << 16);
    // 0x80068864: addiu       $t8, $t6, 0x40
    ctx->r24 = ADD32(ctx->r14, 0X40);
    // 0x80068868: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8006886C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068870: addiu       $t9, $a1, -0x2EC8
    ctx->r25 = ADD32(ctx->r5, -0X2EC8);
    // 0x80068874: andi        $t2, $t9, 0x6
    ctx->r10 = ctx->r25 & 0X6;
    // 0x80068878: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8006887C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068880: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80068884: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068888: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8006888C: ori         $t5, $t4, 0x1A
    ctx->r13 = ctx->r12 | 0X1A;
    // 0x80068890: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068894: b           L_80068AC0
    // 0x80068898: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80068AC0;
    // 0x80068898: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8006889C:
    // 0x8006889C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800688A0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800688A4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800688A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800688AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800688B0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800688B4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800688B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800688BC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800688C0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800688C4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800688C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800688CC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800688D0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800688D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800688D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800688DC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800688E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800688E4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800688E8: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x800688EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800688F0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800688F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800688F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800688FC: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80068900: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068904: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068908: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006890C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80068910: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x80068914: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80068918: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x8006891C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068920: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x80068924: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x80068928: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    extern void dkr_billboard_interpolation_begin(uint8_t*, recomp_context*); dkr_billboard_interpolation_begin(rdram, ctx);
    // 0x8006892C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068930: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068934: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068938: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8006893C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068940: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068944: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80068948: andi        $t7, $t8, 0x6
    ctx->r15 = ctx->r24 & 0X6;
    // 0x8006894C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80068950: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80068954: ori         $t3, $t2, 0x1A
    ctx->r11 = ctx->r10 | 0X1A;
    // 0x80068958: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8006895C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068960: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80068964: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80068968: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8006896C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068970: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068974: addiu       $t8, $t6, 0xA
    ctx->r24 = ADD32(ctx->r14, 0XA);
    // 0x80068978: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8006897C: lb          $t7, 0xD14($t7)
    ctx->r15 = MEM_B(ctx->r15, 0XD14);
    // 0x80068980: nop

    // 0x80068984: bne         $t7, $zero, L_800689BC
    if (ctx->r15 != 0) {
        // 0x80068988: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800689BC;
    }
    // 0x80068988: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006898C: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x80068990: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80068994: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x80068998: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8006899C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800689A0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800689A4: lh          $t3, 0xAC4($t3)
    ctx->r11 = MEM_H(ctx->r11, 0XAC4);
    // 0x800689A8: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800689AC: nop

    // 0x800689B0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800689B4: b           L_800689EC
    // 0x800689B8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_800689EC;
    // 0x800689B8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_800689BC:
    // 0x800689BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800689C0: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800689C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800689C8: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800689CC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800689D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800689D4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800689D8: lh          $t7, 0xBD4($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XBD4);
    // 0x800689DC: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x800689E0: nop

    // 0x800689E4: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x800689E8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_800689EC:
    // 0x800689EC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800689F0: lh          $s2, 0x18($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X18);
    // 0x800689F4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800689F8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800689FC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80068A00: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80068A04: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x80068A08: lw          $a3, 0x6174($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6174);
    // 0x80068A0C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80068A10: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80068A14: jal         0x80070130
    // 0x80068A18: nop

    mtxf_billboard(rdram, ctx);
        goto after_14;
    // 0x80068A18: nop

    after_14:
    // 0x80068A1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A20: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x80068A24: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068A28: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80068A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068A30: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80068A34: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068A38: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x80068A3C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80068A40: jal         0x8006F870
    // 0x80068A44: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_15;
    // 0x80068A44: nop

    after_15:
    // 0x80068A48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A4C: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x80068A50: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80068A54: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80068A58: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80068A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068A60: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80068A64: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068A68: sw          $t2, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r10;
    // 0x80068A6C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068A70: lui         $t6, 0x180
    ctx->r14 = S32(0X180 << 16);
    // 0x80068A74: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80068A78: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80068A7C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80068A80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80068A84: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80068A88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068A8C: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80068A90: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068A94: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80068A98: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80068A9C: addiu       $t3, $t9, 0x40
    ctx->r11 = ADD32(ctx->r25, 0X40);
    // 0x80068AA0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80068AA4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068AA8: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x80068AAC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068AB0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068AB4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80068AB8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068ABC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80068AC0:
    // 0x80068AC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068AC4: lw          $t6, 0xD0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD0C);
    // 0x80068AC8: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80068ACC: bne         $t6, $zero, L_80068AF4
    if (ctx->r14 != 0) {
        // 0x80068AD0: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80068AF4;
    }
    // 0x80068AD0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80068AD4: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068AD8: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80068ADC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80068AE0: nop

    // 0x80068AE4: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068AE8: mflo        $s2
    ctx->r18 = lo;
    // 0x80068AEC: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x80068AF0: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80068AF4:
    // 0x80068AF4: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80068AF8: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068AFC: andi        $t2, $t3, 0x4
    ctx->r10 = ctx->r11 & 0X4;
    // 0x80068B00: beq         $t2, $zero, L_80068B0C
    if (ctx->r10 == 0) {
        // 0x80068B04: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80068B0C;
    }
    // 0x80068B04: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80068B08: ori         $v0, $t3, 0x1
    ctx->r2 = ctx->r11 | 0X1;
L_80068B0C:
    // 0x80068B0C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80068B10: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80068B14: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80068B18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80068B1C: jal         0x8007BF34
    // 0x80068B20: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    material_load_simple(rdram, ctx);
        goto after_16;
    // 0x80068B20: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    after_16:
    // 0x80068B24: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80068B28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068B2C: andi        $t7, $t8, 0x100
    ctx->r15 = ctx->r24 & 0X100;
    // 0x80068B30: bne         $t7, $zero, L_80068B54
    if (ctx->r15 != 0) {
        // 0x80068B34: addiu       $t0, $t0, 0xD1C
        ctx->r8 = ADD32(ctx->r8, 0XD1C);
            goto L_80068B54;
    }
    // 0x80068B34: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x80068B38: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068B3C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80068B40: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80068B44: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80068B48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80068B4C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80068B50: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80068B54:
    // 0x80068B54: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068B58: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80068B5C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068B60: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068B64: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80068B68: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x80068B6C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068B70: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x80068B74: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80068B78: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068B7C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80068B80: ori         $t5, $t5, 0xA
    ctx->r13 = ctx->r13 | 0XA;
    // 0x80068B84: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80068B88: bne         $t3, $zero, L_80068B98
    if (ctx->r11 != 0) {
        // 0x80068B8C: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_80068B98;
    }
    // 0x80068B8C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068B90: b           L_80068B9C
    // 0x80068B94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80068B9C;
    // 0x80068B94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80068B98:
    // 0x80068B98: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80068B9C:
    // 0x80068B9C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068BA0: sll         $t6, $s2, 6
    ctx->r14 = S32(ctx->r18 << 6);
    // 0x80068BA4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068BA8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068BAC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80068BB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068BB4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068BB8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80068BBC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80068BC0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80068BC4: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80068BC8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80068BCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    extern void dkr_vehicle_part_interpolation_end(uint8_t*, recomp_context*); dkr_vehicle_part_interpolation_end(rdram, ctx);
    // 0x80068BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80068BD4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80068BD8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80068BDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068BE0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80068BE4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80068BE8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80068BEC: jr          $ra
    // 0x80068BF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80068BF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void dialogue_race_defeat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D9F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D9F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D9FC: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x8009DA00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009DA04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DA08: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009DA0C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009DA10: jal         0x800C4EDC
    // 0x8009DA14: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009DA14: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009DA18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DA1C: jal         0x800C4F7C
    // 0x8009DA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009DA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009DA24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009DA28: jal         0x8006A554
    // 0x8009DA2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009DA2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009DA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DA34: sb          $zero, 0x6504($at)
    MEM_B(0X6504, ctx->r1) = 0;
    // 0x8009DA38: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009DA3C: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8009DA40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DA44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009DA48: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009DA4C: lw          $a3, 0xC4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC4);
    // 0x8009DA50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009DA54: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009DA58: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009DA5C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009DA60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DA64: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DA68: jal         0x800C5168
    // 0x8009DA6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009DA6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009DA70: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009DA74: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8009DA78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DA7C: lw          $a3, 0xC8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC8);
    // 0x8009DA80: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009DA84: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009DA88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009DA8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DA90: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DA94: jal         0x800C5168
    // 0x8009DA98: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009DA98: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_4:
    // 0x8009DA9C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DAA0: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009DAA4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8009DAA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DAAC: sb          $t3, 0x650E($at)
    MEM_B(0X650E, ctx->r1) = ctx->r11;
    // 0x8009DAB0: lw          $a0, 0x5C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X5C);
    // 0x8009DAB4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DAB8: jal         0x8009D1B8
    // 0x8009DABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009DABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009DAC0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009DAC4: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009DAC8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DACC: lw          $a0, 0xCC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XCC);
    // 0x8009DAD0: jal         0x8009D1B8
    // 0x8009DAD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009DAD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009DAD8: jal         0x8009D26C
    // 0x8009DADC: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_7;
    // 0x8009DADC: nop

    after_7:
    // 0x8009DAE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8009DAE4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009DAE8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8009DAEC: beq         $t7, $zero, L_8009DB30
    if (ctx->r15 == 0) {
        // 0x8009DAF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009DB30;
    }
    // 0x8009DAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DAF4: jal         0x80001D04
    // 0x8009DAF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009DAF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009DAFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009DB00: lb          $v0, 0x6516($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6516);
    // 0x8009DB04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009DB08: beq         $v0, $zero, L_8009DB20
    if (ctx->r2 == 0) {
        // 0x8009DB0C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009DB20;
    }
    // 0x8009DB0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009DB10: beq         $v0, $at, L_8009DB28
    if (ctx->r2 == ctx->r1) {
        // 0x8009DB14: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8009DB28;
    }
    // 0x8009DB14: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009DB18: b           L_8009DB30
    // 0x8009DB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DB30;
    // 0x8009DB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DB20:
    // 0x8009DB20: b           L_8009DB2C
    // 0x8009DB24: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_8009DB2C;
    // 0x8009DB24: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8009DB28:
    // 0x8009DB28: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8009DB2C:
    // 0x8009DB2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DB30:
    // 0x8009DB30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009DB34: jr          $ra
    // 0x8009DB38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009DB38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EB0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EB10: lw          $v1, 0x644C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X644C);
    // 0x8009EB14: lw          $v0, 0x6448($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6448);
    // 0x8009EB18: jr          $ra
    // 0x8009EB1C: nop

    return;
    // 0x8009EB1C: nop

;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9420: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9428: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C942C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800C9430: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800C9434: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9438: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C943C: beq         $a3, $zero, L_800C9474
    if (ctx->r7 == 0) {
        // 0x800C9440: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C9474;
    }
    // 0x800C9440: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9444: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9448: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C944C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C9450: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9454: jal         0x800C8760
    // 0x800C9458: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C9458: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800C945C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C9460: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C9464: jal         0x800C8790
    // 0x800C9468: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C9468: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800C946C: b           L_800C94F4
    // 0x800C9470: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C94F4;
    // 0x800C9470: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C9474:
    // 0x800C9474: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C9478: beq         $a3, $zero, L_800C94AC
    if (ctx->r7 == 0) {
        // 0x800C947C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800C94AC;
    }
    // 0x800C947C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9480: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9484: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C9488: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C948C: jal         0x800C8760
    // 0x800C9490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9490: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800C9494: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C9498: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C949C: jal         0x800C8790
    // 0x800C94A0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C94A0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C94A4: b           L_800C94F4
    // 0x800C94A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C94F4;
    // 0x800C94A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C94AC:
    // 0x800C94AC: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C94B0: beql        $a3, $zero, L_800C94F8
    if (ctx->r7 == 0) {
        // 0x800C94B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C94F8;
    }
    goto skip_0;
    // 0x800C94B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C94B8: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800C94BC:
    // 0x800C94BC: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800C94C0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C94C4: bnel        $at, $zero, L_800C94EC
    if (ctx->r1 != 0) {
        // 0x800C94C8: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C94EC;
    }
    goto skip_1;
    // 0x800C94C8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800C94CC: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800C94D0: bnel        $t1, $zero, L_800C94EC
    if (ctx->r9 != 0) {
        // 0x800C94D4: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C94EC;
    }
    goto skip_2;
    // 0x800C94D4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800C94D8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C94DC: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C94E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C94E4: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800C94E8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800C94EC:
    // 0x800C94EC: bnel        $a3, $zero, L_800C94BC
    if (ctx->r7 != 0) {
        // 0x800C94F0: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800C94BC;
    }
    goto skip_3;
    // 0x800C94F0: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800C94F4:
    // 0x800C94F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C94F8:
    // 0x800C94F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C94FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9500: jr          $ra
    // 0x800C9504: nop

    return;
    // 0x800C9504: nop

;}
RECOMP_FUNC void atan2s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007066C: or          $t0, $a0, $a1
    ctx->r8 = ctx->r4 | ctx->r5;
    // 0x80070670: bne         $zero, $t0, L_80070680
    if (0 != ctx->r8) {
        // 0x80070674: nop
    
            goto L_80070680;
    }
    // 0x80070674: nop

    // 0x80070678: jr          $ra
    // 0x8007067C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x8007067C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_80070680:
    // 0x80070680: bltz        $a0, L_80070698
    if (SIGNED(ctx->r4) < 0) {
        // 0x80070684: nop
    
            goto L_80070698;
    }
    // 0x80070684: nop

    // 0x80070688: bltzl       $a1, L_800706B8
    if (SIGNED(ctx->r5) < 0) {
        // 0x8007068C: negu        $a1, $a1
        ctx->r5 = SUB32(0, ctx->r5);
            goto L_800706B8;
    }
    goto skip_0;
    // 0x8007068C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    skip_0:
    // 0x80070690: j           L_800706C8
    // 0x80070694: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_800706C8;
    // 0x80070694: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_80070698:
    // 0x80070698: bltz        $a1, L_800706A8
    if (SIGNED(ctx->r5) < 0) {
        // 0x8007069C: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800706A8;
    }
    // 0x8007069C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800706A0: j           L_800706BC
    // 0x800706A4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
        goto L_800706BC;
    // 0x800706A4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
L_800706A8:
    // 0x800706A8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800706AC: j           L_800706C8
    // 0x800706B0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
        goto L_800706C8;
    // 0x800706B0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800706B4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800706B8:
    // 0x800706B8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_800706BC:
    // 0x800706BC: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
    // 0x800706C0: xor         $a1, $a0, $a1
    ctx->r5 = ctx->r4 ^ ctx->r5;
    // 0x800706C4: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
L_800706C8:
    // 0x800706C8: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x800706CC: bltzl       $t0, L_80070718
    if (SIGNED(ctx->r8) < 0) {
        // 0x800706D0: dsll        $t0, $a0, 11
        ctx->r8 = ctx->r4 << 11;
            goto L_80070718;
    }
    goto skip_1;
    // 0x800706D0: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
    skip_1:
    // 0x800706D4: dsll        $t0, $a1, 11
    ctx->r8 = ctx->r5 << 11;
    // 0x800706D8: ddivu       $zero, $t0, $a0
    DDIVU(U64(ctx->r8), U64(ctx->r4), &lo, &hi);
    // 0x800706DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800706E0: addiu       $t1, $t1, -0x23C2
    ctx->r9 = ADD32(ctx->r9, -0X23C2);
    // 0x800706E4: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x800706E8: bne         $a0, $zero, L_800706F4
    if (ctx->r4 != 0) {
        // 0x800706EC: nop
    
            goto L_800706F4;
    }
    // 0x800706EC: nop

    // 0x800706F0: break       7
    do_break(2147944176);
L_800706F4:
    // 0x800706F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800706F8: mflo        $t0
    ctx->r8 = lo;
    // 0x800706FC: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x80070700: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070704: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070708: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x8007070C: jr          $ra
    // 0x80070710: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80070710: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80070714: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
L_80070718:
    // 0x80070718: ddivu       $zero, $t0, $a1
    DDIVU(U64(ctx->r8), U64(ctx->r5), &lo, &hi);
    // 0x8007071C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070720: addiu       $t1, $t1, -0x23C2
    ctx->r9 = ADD32(ctx->r9, -0X23C2);
    // 0x80070724: bne         $a1, $zero, L_80070730
    if (ctx->r5 != 0) {
        // 0x80070728: nop
    
            goto L_80070730;
    }
    // 0x80070728: nop

    // 0x8007072C: break       7
    do_break(2147944236);
L_80070730:
    // 0x80070730: mflo        $t0
    ctx->r8 = lo;
    // 0x80070734: mflo        $t0
    ctx->r8 = lo;
    // 0x80070738: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x8007073C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070740: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070744: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80070748: jr          $ra
    // 0x8007074C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8007074C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
;}
RECOMP_FUNC void obj_loop_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CEA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CEA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CEAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CEB0: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEB4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003CEB8: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CEBC: nop

    // 0x8003CEC0: slti        $at, $t6, 0x2D
    ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
    // 0x8003CEC4: beq         $at, $zero, L_8003CEEC
    if (ctx->r1 == 0) {
        // 0x8003CEC8: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8003CEEC;
    }
    // 0x8003CEC8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003CECC: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003CED0: jal         0x8001E344
    // 0x8003CED4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    start_bridge_timer(rdram, ctx);
        goto after_0;
    // 0x8003CED4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003CED8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003CEDC: nop

    // 0x8003CEE0: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003CEE4: nop

    // 0x8003CEE8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
L_8003CEEC:
    // 0x8003CEEC: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x8003CEF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CEF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CEF8: jr          $ra
    // 0x8003CEFC: nop

    return;
    // 0x8003CEFC: nop

;}
RECOMP_FUNC void find_non_car_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1D0: lb          $v0, -0x51FE($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X51FE);
    // 0x8000E1D4: jr          $ra
    // 0x8000E1D8: nop

    return;
    // 0x8000E1D8: nop

;}
RECOMP_FUNC void menu_dialogue_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800945B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800945B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800945B8: jal         0x80072298
    // 0x800945BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x800945BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800945C0: jal         0x800C5620
    // 0x800945C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_1;
    // 0x800945C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x800945C8: jal         0x800C5494
    // 0x800945CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x800945CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x800945D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800945D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800945D8: sw          $zero, 0x984($at)
    MEM_W(0X984, ctx->r1) = 0;
    // 0x800945DC: jr          $ra
    // 0x800945E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800945E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_filtered_cheats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C30C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C314: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C318: lw          $t6, -0xB48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB48);
    // 0x8009C31C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009C320: lw          $s0, -0x268($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X268);
    // 0x8009C324: beq         $t6, $zero, L_8009C338
    if (ctx->r14 == 0) {
        // 0x8009C328: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009C338;
    }
    // 0x8009C328: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C32C: jal         0x8000E4C8
    // 0x8009C330: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_0;
    // 0x8009C330: nop

    after_0:
    // 0x8009C334: beq         $v0, $zero, L_8009C348
    if (ctx->r2 == 0) {
        // 0x8009C338: lui         $at, 0x1B40
        ctx->r1 = S32(0X1B40 << 16);
            goto L_8009C348;
    }
L_8009C338:
    // 0x8009C338: lui         $at, 0x1B40
    ctx->r1 = S32(0X1B40 << 16);
    // 0x8009C33C: ori         $at, $at, 0x133
    ctx->r1 = ctx->r1 | 0X133;
    // 0x8009C340: and         $t7, $s0, $at
    ctx->r15 = ctx->r16 & ctx->r1;
    // 0x8009C344: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8009C348:
    // 0x8009C348: jal         0x8006B240
    // 0x8009C34C: nop

    level_is_race(rdram, ctx);
        goto after_1;
    // 0x8009C34C: nop

    after_1:
    // 0x8009C350: bne         $v0, $zero, L_8009C360
    if (ctx->r2 != 0) {
        // 0x8009C354: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_8009C360;
    }
    // 0x8009C354: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8009C358: and         $t8, $s0, $at
    ctx->r24 = ctx->r16 & ctx->r1;
    // 0x8009C35C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8009C360:
    // 0x8009C360: jal         0x8006EA90
    // 0x8009C364: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009C364: nop

    after_2:
    // 0x8009C368: lbu         $a0, 0x49($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X49);
    // 0x8009C36C: jal         0x8006B14C
    // 0x8009C370: nop

    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x8009C370: nop

    after_3:
    // 0x8009C374: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x8009C378: beq         $t9, $zero, L_8009C390
    if (ctx->r25 == 0) {
        // 0x8009C37C: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009C390;
    }
    // 0x8009C37C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009C380: lui         $at, 0xFFF0
    ctx->r1 = S32(0XFFF0 << 16);
    // 0x8009C384: ori         $at, $at, 0x677F
    ctx->r1 = ctx->r1 | 0X677F;
    // 0x8009C388: and         $t0, $s0, $at
    ctx->r8 = ctx->r16 & ctx->r1;
    // 0x8009C38C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_8009C390:
    // 0x8009C390: lw          $t1, -0xB6C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB6C);
    // 0x8009C394: nop

    // 0x8009C398: beq         $t1, $zero, L_8009C3B8
    if (ctx->r9 == 0) {
        // 0x8009C39C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009C3B8;
    }
    // 0x8009C39C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C3A0: jal         0x8006B240
    // 0x8009C3A4: nop

    level_is_race(rdram, ctx);
        goto after_4;
    // 0x8009C3A4: nop

    after_4:
    // 0x8009C3A8: beq         $v0, $zero, L_8009C3B4
    if (ctx->r2 == 0) {
        // 0x8009C3AC: ori         $t2, $s0, 0x4
        ctx->r10 = ctx->r16 | 0X4;
            goto L_8009C3B4;
    }
    // 0x8009C3AC: ori         $t2, $s0, 0x4
    ctx->r10 = ctx->r16 | 0X4;
    // 0x8009C3B0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8009C3B4:
    // 0x8009C3B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009C3B8:
    // 0x8009C3B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8009C3BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C3C0: jr          $ra
    // 0x8009C3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009C3C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void racerfx_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B020: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000B024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000B028: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x8000B02C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000B030: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000B034: addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // 0x8000B038: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000B03C: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x8000B040: sll         $s0, $a1, 4
    ctx->r16 = S32(ctx->r5 << 4);
    // 0x8000B044: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000B048: addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    // 0x8000B04C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000B050: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000B054: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8000B058: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8000B05C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8000B060: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8000B064: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8000B068: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B06C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000B070: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000B074: jal         0x80070C9C
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8000B07C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B080: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000B084: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x8000B088: addiu       $a1, $a1, -0x38B4
    ctx->r5 = ADD32(ctx->r5, -0X38B4);
    // 0x8000B08C: addiu       $v1, $v1, -0x38AC
    ctx->r3 = ADD32(ctx->r3, -0X38AC);
    // 0x8000B090: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x8000B094: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x8000B098: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B09C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B0A0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8000B0A4: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000B0A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0AC: sw          $s3, -0x5008($at)
    MEM_W(-0X5008, ctx->r1) = ctx->r19;
    // 0x8000B0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0B4: sw          $zero, -0x5004($at)
    MEM_W(-0X5004, ctx->r1) = 0;
    // 0x8000B0B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0BC: sw          $s2, -0x5000($at)
    MEM_W(-0X5000, ctx->r1) = ctx->r18;
    // 0x8000B0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0C4: sw          $zero, -0x4FFC($at)
    MEM_W(-0X4FFC, ctx->r1) = 0;
    // 0x8000B0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0CC: sw          $zero, -0x4FF8($at)
    MEM_W(-0X4FF8, ctx->r1) = 0;
    // 0x8000B0D0: jal         0x8001E29C
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B0D8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B0DC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000B0E0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000B0E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8000B0E8: addiu       $s3, $s3, -0x4F98
    ctx->r19 = ADD32(ctx->r19, -0X4F98);
    // 0x8000B0EC: addiu       $s1, $s1, -0x4FE0
    ctx->r17 = ADD32(ctx->r17, -0X4FE0);
    // 0x8000B0F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000B0F4: addiu       $s7, $sp, 0x58
    ctx->r23 = ADD32(ctx->r29, 0X58);
    // 0x8000B0F8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8000B0FC:
    // 0x8000B0FC: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x8000B100: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8000B104: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x8000B108: sb          $t4, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r12;
    // 0x8000B10C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B110: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B114: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B118: sb          $s2, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r18;
    // 0x8000B11C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B120: jal         0x8000EA54
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8000B128: beq         $v0, $zero, L_8000B198
    if (ctx->r2 == 0) {
        // 0x8000B12C: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8000B198;
    }
    // 0x8000B12C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000B130: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8000B134: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000B138: sll         $t7, $s2, 7
    ctx->r15 = S32(ctx->r18 << 7);
    // 0x8000B13C: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000B140: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000B144: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
    // 0x8000B148: lh          $a0, 0x6C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6C);
    // 0x8000B14C: addiu       $t8, $t8, -0x4FF0
    ctx->r24 = ADD32(ctx->r24, -0X4FF0);
    // 0x8000B150: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    // 0x8000B154: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x8000B158: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8000B15C: jal         0x8007C12C
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_3;
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8000B164: lh          $a0, 0x6E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6E);
    // 0x8000B168: jal         0x8007AE74
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    after_4:
    // 0x8000B170: sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
    // 0x8000B174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B178: jal         0x8006F94C
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_5:
    // 0x8000B180: sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // 0x8000B184: sb          $zero, 0x73($s0)
    MEM_B(0X73, ctx->r16) = 0;
    // 0x8000B188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B18C: jal         0x8006F94C
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
    // 0x8000B194: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
L_8000B198:
    // 0x8000B198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000B19C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8000B1A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000B1A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000B1A8: bne         $at, $zero, L_8000B0FC
    if (ctx->r1 != 0) {
        // 0x8000B1AC: sb          $s6, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r22;
            goto L_8000B0FC;
    }
    // 0x8000B1AC: sb          $s6, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r22;
    // 0x8000B1B0: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000B1B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1B8: addiu       $t0, $zero, 0x8D
    ctx->r8 = ADD32(0, 0X8D);
    // 0x8000B1BC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8000B1C0: sw          $t9, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->r25;
    // 0x8000B1C4: sb          $t0, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r8;
    // 0x8000B1C8: sb          $t1, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r9;
    // 0x8000B1CC: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B1D0: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B1D4: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B1D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B1DC: jal         0x8000EA54
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_7;
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8000B1E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000B1EC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B1F0: sw          $v0, -0x38A4($at)
    MEM_W(-0X38A4, ctx->r1) = ctx->r2;
    // 0x8000B1F4: addiu       $s1, $s1, -0x4F60
    ctx->r17 = ADD32(ctx->r17, -0X4F60);
    // 0x8000B1F8: addiu       $s0, $s0, -0x4F88
    ctx->r16 = ADD32(ctx->r16, -0X4F88);
L_8000B1FC:
    // 0x8000B1FC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000B200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B204: jal         0x8006F94C
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_8:
    // 0x8000B20C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x8000B210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B214: jal         0x8006F94C
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_9:
    // 0x8000B21C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B220: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8000B224: bne         $s0, $s1, L_8000B1FC
    if (ctx->r16 != ctx->r17) {
        // 0x8000B228: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8000B1FC;
    }
    // 0x8000B228: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x8000B22C: addiu       $t2, $zero, 0x1B
    ctx->r10 = ADD32(0, 0X1B);
    // 0x8000B230: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8000B234: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x8000B238: sb          $t3, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r11;
    // 0x8000B23C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B240: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B244: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B24C: jal         0x8000EA54
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_10;
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8000B254: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B25C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000B260: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000B264: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B268: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000B26C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000B270: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000B274: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B278: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8000B27C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8000B280: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8000B284: sw          $v0, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = ctx->r2;
    // 0x8000B288: jr          $ra
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void cheatmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A4CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A4D0: jal         0x800C422C
    // 0x8008A4D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008A4D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A4E0: jr          $ra
    // 0x8008A4E4: nop

    return;
    // 0x8008A4E4: nop

;}
RECOMP_FUNC void is_tt_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ECB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009ECBC: lw          $v0, -0x268($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X268);
    // 0x8009ECC0: nop

    // 0x8009ECC4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8009ECC8: jr          $ra
    // 0x8009ECCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009ECCC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_taj_create_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022CFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022D00: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80022D04: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80022D08: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80022D0C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80022D10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022D14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022D18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022D1C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022D20: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80022D24: jal         0x8006EA90
    // 0x80022D28: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80022D28: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80022D2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022D30: lw          $t0, -0x51A4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X51A4);
    // 0x80022D34: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022D38: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80022D3C: blez        $t0, L_80022E00
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80022D40: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80022E00;
    }
    // 0x80022D40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80022D44: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80022D48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80022D4C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80022D50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022D54: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x80022D58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022D5C: addiu       $t2, $zero, 0x4D
    ctx->r10 = ADD32(0, 0X4D);
L_80022D60:
    // 0x80022D60: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80022D64: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80022D68: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80022D6C: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80022D70: nop

    // 0x80022D74: lh          $t8, 0x48($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X48);
    // 0x80022D78: nop

    // 0x80022D7C: bne         $t2, $t8, L_80022DF8
    if (ctx->r10 != ctx->r24) {
        // 0x80022D80: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022DF8;
    }
    // 0x80022D80: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022D84: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x80022D88: nop

    // 0x80022D8C: beq         $a0, $zero, L_80022DF8
    if (ctx->r4 == 0) {
        // 0x80022D90: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022DF8;
    }
    // 0x80022D90: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022D94: lb          $a1, 0xA($a0)
    ctx->r5 = MEM_B(ctx->r4, 0XA);
    // 0x80022D98: nop

    // 0x80022D9C: blez        $a1, L_80022DF8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80022DA0: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022DF8;
    }
    // 0x80022DA0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DA4: lhu         $a0, 0x14($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X14);
    // 0x80022DA8: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x80022DAC: beq         $a0, $zero, L_80022DF4
    if (ctx->r4 == 0) {
        // 0x80022DB0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80022DF4;
    }
    // 0x80022DB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80022DB4: sllv        $t4, $t3, $t9
    ctx->r12 = S32(ctx->r11 << (ctx->r25 & 31));
    // 0x80022DB8: and         $t5, $a0, $t4
    ctx->r13 = ctx->r4 & ctx->r12;
    // 0x80022DBC: beq         $t5, $zero, L_80022DF8
    if (ctx->r13 == 0) {
        // 0x80022DC0: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022DF8;
    }
    // 0x80022DC0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DC4: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80022DC8: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80022DCC: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x80022DD0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80022DD4: swc1        $f20, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f20.u32l;
    // 0x80022DD8: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x80022DDC: sh          $s0, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r16;
    // 0x80022DE0: sw          $zero, 0x78($v1)
    MEM_W(0X78, ctx->r3) = 0;
    // 0x80022DE4: sb          $zero, 0x39($v1)
    MEM_B(0X39, ctx->r3) = 0;
    // 0x80022DE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022DEC: lw          $t0, -0x51A4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X51A4);
    // 0x80022DF0: nop

L_80022DF4:
    // 0x80022DF4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
L_80022DF8:
    // 0x80022DF8: bne         $at, $zero, L_80022D60
    if (ctx->r1 != 0) {
        // 0x80022DFC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80022D60;
    }
    // 0x80022DFC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80022E00:
    // 0x80022E00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022E04: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022E08: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022E0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022E10: jr          $ra
    // 0x80022E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034E9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80034EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034EA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034EAC: jal         0x8006EA90
    // 0x80034EB0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80034EB0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034EB4: jal         0x8006BDB0
    // 0x80034EB8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x80034EB8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80034EBC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80034EC0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034EC4: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80034EC8: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80034ECC: nop

    // 0x80034ED0: bne         $t7, $zero, L_80034F78
    if (ctx->r15 != 0) {
        // 0x80034ED4: nop
    
            goto L_80034F78;
    }
    // 0x80034ED4: nop

    // 0x80034ED8: lb          $a0, 0x4C($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X4C);
    // 0x80034EDC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80034EE0: beq         $a0, $at, L_80034F78
    if (ctx->r4 == ctx->r1) {
        // 0x80034EE4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80034F78;
    }
    // 0x80034EE4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80034EE8: beq         $a0, $at, L_80034F78
    if (ctx->r4 == ctx->r1) {
        // 0x80034EEC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80034F78;
    }
    // 0x80034EEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034EF0: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80034EF4: lbu         $t0, 0x48($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X48);
    // 0x80034EF8: lhu         $t9, 0xE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XE);
    // 0x80034EFC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80034F00: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80034F04: srav        $t3, $t9, $t2
    ctx->r11 = S32(SIGNED(ctx->r25) >> (ctx->r10 & 31));
    // 0x80034F08: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80034F0C: beq         $t4, $zero, L_80034F78
    if (ctx->r12 == 0) {
        // 0x80034F10: addiu       $t5, $zero, 0x80
        ctx->r13 = ADD32(0, 0X80);
            goto L_80034F78;
    }
    // 0x80034F10: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80034F14: sb          $t5, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r13;
    // 0x80034F18: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F1C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80034F20: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80034F24: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80034F28: sh          $t7, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r15;
    // 0x80034F2C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80034F34: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80034F38: nop

    // 0x80034F3C: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // 0x80034F40: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F44: nop

    // 0x80034F48: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80034F4C: sb          $t2, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r10;
    // 0x80034F50: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80034F54: jal         0x8000EA54
    // 0x80034F58: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x80034F58: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    after_2:
    // 0x80034F5C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034F60: beq         $v0, $zero, L_80034F78
    if (ctx->r2 == 0) {
        // 0x80034F64: nop
    
            goto L_80034F78;
    }
    // 0x80034F64: nop

    // 0x80034F68: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80034F6C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80034F70: nop

    // 0x80034F74: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80034F78:
    // 0x80034F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034F7C: lwc1        $f4, 0x6004($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6004);
    // 0x80034F80: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x80034F84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034F88: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x80034F8C: lw          $t5, 0x54($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X54);
    // 0x80034F90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034F94: swc1        $f6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f6.u32l;
    // 0x80034F98: jal         0x8001BAC8
    // 0x80034F9C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80034F9C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_3:
    // 0x80034FA0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FA4: beq         $v0, $zero, L_80035220
    if (ctx->r2 == 0) {
        // 0x80034FA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035220;
    }
    // 0x80034FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034FAC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034FB0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034FB4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034FB8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034FBC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80034FC0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80034FC4: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80034FC8: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80034FCC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80034FD0: jal         0x800C9AD0
    // 0x80034FD4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80034FD4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x80034FD8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FDC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034FE0: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    // 0x80034FE4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80034FE8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80034FEC: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80034FF0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80034FF4: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80034FF8: slti        $t9, $t1, 0x8
    ctx->r25 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80034FFC: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80035000: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80035004: beq         $t9, $zero, L_80035020
    if (ctx->r25 == 0) {
        // 0x80035008: ori         $t6, $v0, 0x800
        ctx->r14 = ctx->r2 | 0X800;
            goto L_80035020;
    }
    // 0x80035008: ori         $t6, $v0, 0x800
    ctx->r14 = ctx->r2 | 0X800;
    // 0x8003500C: addiu       $t3, $a0, 0x6
    ctx->r11 = ADD32(ctx->r4, 0X6);
    // 0x80035010: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80035014: and         $t6, $t5, $t6
    ctx->r14 = ctx->r13 & ctx->r14;
    // 0x80035018: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8003501C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80035020:
    // 0x80035020: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x80035024: nop

    // 0x80035028: bne         $t8, $zero, L_800350C8
    if (ctx->r24 != 0) {
        // 0x8003502C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_800350C8;
    }
    // 0x8003502C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035030: jal         0x800C3400
    // 0x80035034: nop

    textbox_visible(rdram, ctx);
        goto after_5;
    // 0x80035034: nop

    after_5:
    // 0x80035038: bne         $v0, $zero, L_800350C8
    if (ctx->r2 != 0) {
        // 0x8003503C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_800350C8;
    }
    // 0x8003503C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035040: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x80035044: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035048: lw          $t1, 0x100($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X100);
    // 0x8003504C: nop

    // 0x80035050: beq         $t1, $zero, L_800350C4
    if (ctx->r9 == 0) {
        // 0x80035054: nop
    
            goto L_800350C4;
    }
    // 0x80035054: nop

    // 0x80035058: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x8003505C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80035060: bne         $t9, $zero, L_800350C8
    if (ctx->r25 != 0) {
        // 0x80035064: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_800350C8;
    }
    // 0x80035064: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035068: beq         $t2, $zero, L_80035090
    if (ctx->r10 == 0) {
        // 0x8003506C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80035090;
    }
    // 0x8003506C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035070: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
    // 0x80035074: addiu       $a0, $zero, 0x12F
    ctx->r4 = ADD32(0, 0X12F);
    // 0x80035078: jal         0x80001D04
    // 0x8003507C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8003507C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80035080: jal         0x800A3870
    // 0x80035084: nop

    hud_speedometre_reset(rdram, ctx);
        goto after_7;
    // 0x80035084: nop

    after_7:
    // 0x80035088: b           L_800350C8
    // 0x8003508C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
        goto L_800350C8;
    // 0x8003508C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80035090:
    // 0x80035090: jal         0x800C31EC
    // 0x80035094: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_current_text(rdram, ctx);
        goto after_8;
    // 0x80035094: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
    // 0x80035098: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8003509C: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x800350A0: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x800350A4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800350A8: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x800350AC: jal         0x80000C38
    // 0x800350B0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x800350B0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    after_9:
    // 0x800350B4: jal         0x80000C98
    // 0x800350B8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_10;
    // 0x800350B8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_10:
    // 0x800350BC: jal         0x80001BC0
    // 0x800350C0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_11;
    // 0x800350C0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_11:
L_800350C4:
    // 0x800350C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_800350C8:
    // 0x800350C8: nop

    // 0x800350CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800350D0: nop

    // 0x800350D4: beq         $t7, $zero, L_80035124
    if (ctx->r15 == 0) {
        // 0x800350D8: nop
    
            goto L_80035124;
    }
    // 0x800350D8: nop

    // 0x800350DC: jal         0x80001C08
    // 0x800350E0: nop

    music_jingle_playing(rdram, ctx);
        goto after_12;
    // 0x800350E0: nop

    after_12:
    // 0x800350E4: bne         $v0, $zero, L_80035124
    if (ctx->r2 != 0) {
        // 0x800350E8: nop
    
            goto L_80035124;
    }
    // 0x800350E8: nop

    // 0x800350EC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800350F0: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800350F4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800350F8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800350FC: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80035100: beq         $at, $zero, L_80035114
    if (ctx->r1 == 0) {
        // 0x80035104: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80035114;
    }
    // 0x80035104: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80035108: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8003510C: b           L_80035124
    // 0x80035110: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
        goto L_80035124;
    // 0x80035110: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80035114:
    // 0x80035114: jal         0x80000C98
    // 0x80035118: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    music_fade(rdram, ctx);
        goto after_13;
    // 0x80035118: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_13:
    // 0x8003511C: jal         0x80000C38
    // 0x80035120: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_14;
    // 0x80035120: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_14:
L_80035124:
    // 0x80035124: lw          $t2, 0x5C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X5C);
    // 0x80035128: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003512C: lw          $t4, 0x100($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X100);
    // 0x80035130: nop

    // 0x80035134: bne         $t4, $zero, L_80035158
    if (ctx->r12 != 0) {
        // 0x80035138: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80035158;
    }
    // 0x80035138: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x8003513C: jal         0x800C3400
    // 0x80035140: nop

    textbox_visible(rdram, ctx);
        goto after_15;
    // 0x80035140: nop

    after_15:
    // 0x80035144: beq         $v0, $zero, L_80035160
    if (ctx->r2 == 0) {
        // 0x80035148: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035160;
    }
    // 0x80035148: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003514C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035150: nop

    // 0x80035154: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80035158:
    // 0x80035158: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8003515C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80035160:
    // 0x80035160: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80035164: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x80035168: nop

    // 0x8003516C: blez        $v0, L_8003517C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80035170: subu        $t5, $v0, $t6
        ctx->r13 = SUB32(ctx->r2, ctx->r14);
            goto L_8003517C;
    }
    // 0x80035170: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x80035174: b           L_80035180
    // 0x80035178: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
        goto L_80035180;
    // 0x80035178: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
L_8003517C:
    // 0x8003517C: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_80035180:
    // 0x80035180: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80035184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80035188: bne         $t7, $at, L_800351F0
    if (ctx->r15 != ctx->r1) {
        // 0x8003518C: nop
    
            goto L_800351F0;
    }
    // 0x8003518C: nop

    // 0x80035190: jal         0x800AB1AC
    // 0x80035194: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_opacity_set(rdram, ctx);
        goto after_16;
    // 0x80035194: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80035198: jal         0x800AB1D4
    // 0x8003519C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_17;
    // 0x8003519C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800351A0: jal         0x8009CFEC
    // 0x800351A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    npc_dialogue_loop(rdram, ctx);
        goto after_18;
    // 0x800351A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_18:
    // 0x800351A8: beq         $v0, $zero, L_800351E8
    if (ctx->r2 == 0) {
        // 0x800351AC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800351E8;
    }
    // 0x800351AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800351B0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800351B4: jal         0x8009CF68
    // 0x800351B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    dialogue_npc_finish(rdram, ctx);
        goto after_19;
    // 0x800351B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_19:
    // 0x800351BC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800351C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800351C4: bne         $v1, $at, L_800351E0
    if (ctx->r3 != ctx->r1) {
        // 0x800351C8: nop
    
            goto L_800351E0;
    }
    // 0x800351C8: nop

    // 0x800351CC: jal         0x8006F254
    // 0x800351D0: nop

    begin_trophy_race_teleport(rdram, ctx);
        goto after_20;
    // 0x800351D0: nop

    after_20:
    // 0x800351D4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800351D8: b           L_800351E8
    // 0x800351DC: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
        goto L_800351E8;
    // 0x800351DC: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
L_800351E0:
    // 0x800351E0: jal         0x800AB1D4
    // 0x800351E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_21;
    // 0x800351E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
L_800351E8:
    // 0x800351E8: jal         0x8005A3B0
    // 0x800351EC: nop

    disable_racer_input(rdram, ctx);
        goto after_22;
    // 0x800351EC: nop

    after_22:
L_800351F0:
    // 0x800351F0: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x800351F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800351F8: sw          $zero, 0x100($t1)
    MEM_W(0X100, ctx->r9) = 0;
    // 0x800351FC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80035200: nop

    // 0x80035204: beq         $t8, $zero, L_80035220
    if (ctx->r24 == 0) {
        // 0x80035208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035220;
    }
    // 0x80035208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003520C: lwc1        $f8, 0x6008($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6008);
    // 0x80035210: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80035214: nop

    // 0x80035218: swc1        $f8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f8.u32l;
    // 0x8003521C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035220:
    // 0x80035220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035224: jr          $ra
    // 0x80035228: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035228: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mempool_alloc_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E90: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80070E94: lw          $a3, 0x35C0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X35C0);
    // 0x80070E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070E9C: beq         $a3, $zero, L_80070EE4
    if (ctx->r7 == 0) {
        // 0x80070EA0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80070EE4;
    }
    // 0x80070EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070EA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80070EA8: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x80070EAC: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80070EB0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_80070EB4:
    // 0x80070EB4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80070EB8: nop

    // 0x80070EBC: bne         $a0, $t8, L_80070ED8
    if (ctx->r4 != ctx->r24) {
        // 0x80070EC0: nop
    
            goto L_80070ED8;
    }
    // 0x80070EC0: nop

    // 0x80070EC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80070EC8: jal         0x80070D3C
    // 0x80070ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x80070ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80070ED0: b           L_80070EEC
    // 0x80070ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80070EEC;
    // 0x80070ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80070ED8:
    // 0x80070ED8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80070EDC: bne         $a3, $zero, L_80070EB4
    if (ctx->r7 != 0) {
        // 0x80070EE0: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_80070EB4;
    }
    // 0x80070EE0: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80070EE4:
    // 0x80070EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80070EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80070EEC:
    // 0x80070EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070EF0: jr          $ra
    // 0x80070EF4: nop

    return;
    // 0x80070EF4: nop

;}
RECOMP_FUNC void obj_init_wavegenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800409A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800409A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800409AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800409B0: jal         0x800BF524
    // 0x800409B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    wavegen_add(rdram, ctx);
        goto after_0;
    // 0x800409B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800409B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800409BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800409C0: jr          $ra
    // 0x800409C4: nop

    return;
    // 0x800409C4: nop

;}
RECOMP_FUNC void init_controller_paks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075B18: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80075B1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80075B20: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80075B24: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80075B28: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80075B2C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80075B30: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80075B34: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075B38: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80075B3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075B40: jal         0x8006A100
    // 0x80075B44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80075B44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80075B48: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80075B4C: addiu       $s4, $s4, 0x4010
    ctx->r20 = ADD32(ctx->r20, 0X4010);
    // 0x80075B50: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80075B54: jal         0x8001E29C
    // 0x80075B58: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80075B58: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_1:
    // 0x80075B5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075B60: sw          $v0, 0x41E0($at)
    MEM_W(0X41E0, ctx->r1) = ctx->r2;
    // 0x80075B64: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80075B68: addiu       $v1, $v1, 0x41E7
    ctx->r3 = ADD32(ctx->r3, 0X41E7);
    // 0x80075B6C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80075B70: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80075B74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075B78: sb          $t7, 0x41E6($at)
    MEM_B(0X41E6, ctx->r1) = ctx->r15;
    // 0x80075B7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075B80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075B84: sb          $t8, 0x41E4($at)
    MEM_B(0X41E4, ctx->r1) = ctx->r24;
    // 0x80075B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075B8C: sw          $zero, 0x41E8($at)
    MEM_W(0X41E8, ctx->r1) = 0;
    // 0x80075B90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80075B94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80075B98: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80075B9C: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80075BA0: sw          $t9, -0x1B74($at)
    MEM_W(-0X1B74, ctx->r1) = ctx->r25;
    // 0x80075BA4: addiu       $s6, $s6, -0x1B78
    ctx->r22 = ADD32(ctx->r22, -0X1B78);
    // 0x80075BA8: addiu       $s5, $s5, 0x41E5
    ctx->r21 = ADD32(ctx->r21, 0X41E5);
    // 0x80075BAC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075BB0: sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // 0x80075BB4: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x80075BB8: jal         0x800CD290
    // 0x80075BBC: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x80075BBC: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    after_2:
    // 0x80075BC0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80075BC4: addiu       $s1, $s1, 0x41B8
    ctx->r17 = ADD32(ctx->r17, 0X41B8);
    // 0x80075BC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075BCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80075BD0: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80075BD4: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_80075BD8:
    // 0x80075BD8: lbu         $t2, 0x4E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4E);
    // 0x80075BDC: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80075BE0: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x80075BE4: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x80075BE8: sh          $s7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r23;
    // 0x80075BEC: sh          $s7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r23;
    // 0x80075BF0: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80075BF4: beq         $t3, $zero, L_80075C8C
    if (ctx->r11 == 0) {
        // 0x80075BF8: sh          $t1, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r9;
            goto L_80075C8C;
    }
    // 0x80075BF8: sh          $t1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r9;
    // 0x80075BFC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80075C00: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80075C04: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80075C08: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80075C0C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80075C10: addiu       $t5, $t5, 0x4018
    ctx->r13 = ADD32(ctx->r13, 0X4018);
    // 0x80075C14: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80075C18: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x80075C1C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075C24: jal         0x800CED20
    // 0x80075C28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80075C28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80075C2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075C30: bne         $v0, $at, L_80075C44
    if (ctx->r2 != ctx->r1) {
        // 0x80075C34: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075C44;
    }
    // 0x80075C34: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075C38: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C3C: jal         0x800CED20
    // 0x80075C40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80075C40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
L_80075C44:
    // 0x80075C44: bne         $v0, $zero, L_80075C60
    if (ctx->r2 != 0) {
        // 0x80075C48: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80075C60;
    }
    // 0x80075C48: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80075C4C: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x80075C50: nop

    // 0x80075C54: or          $t7, $t6, $s3
    ctx->r15 = ctx->r14 | ctx->r19;
    // 0x80075C58: b           L_80075C8C
    // 0x80075C5C: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
        goto L_80075C8C;
    // 0x80075C5C: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
L_80075C60:
    // 0x80075C60: bne         $v0, $at, L_80075C8C
    if (ctx->r2 != ctx->r1) {
        // 0x80075C64: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075C8C;
    }
    // 0x80075C64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075C68: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075C6C: jal         0x800720DC
    // 0x80075C70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075C70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80075C74: bne         $v0, $zero, L_80075C90
    if (ctx->r2 != 0) {
        // 0x80075C78: sll         $v1, $s3, 1
        ctx->r3 = S32(ctx->r19 << 1);
            goto L_80075C90;
    }
    // 0x80075C78: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x80075C7C: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x80075C80: nop

    // 0x80075C84: or          $t9, $t8, $s3
    ctx->r25 = ctx->r24 | ctx->r19;
    // 0x80075C88: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
L_80075C8C:
    // 0x80075C8C: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
L_80075C90:
    // 0x80075C90: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80075C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075C98: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80075C9C: bne         $s0, $fp, L_80075BD8
    if (ctx->r16 != ctx->r30) {
        // 0x80075CA0: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_80075BD8;
    }
    // 0x80075CA0: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80075CA4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075CA8: jal         0x800CCFE0
    // 0x80075CAC: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x80075CAC: nop

    after_6:
    extern void dkr_refresh_combined_accessories(uint8_t*, recomp_context*); dkr_refresh_combined_accessories(rdram, ctx);
    // 0x80075CB0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80075CB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075CB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075CBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075CC0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075CC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075CC8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80075CCC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075CD0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075CD4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075CD8: jr          $ra
    // 0x80075CDC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80075CDC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gfxtask_run_rdp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077AAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077AB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077AB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80077ABC: jal         0x800D18A0
    // 0x80077AC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077AC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077AC4: jal         0x800D18D0
    // 0x80077AC8: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x80077AC8: nop

    after_1:
    // 0x80077ACC: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80077AD0: beq         $t6, $zero, L_80077AF0
    if (ctx->r14 == 0) {
        // 0x80077AD4: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80077AF0;
    }
    // 0x80077AD4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077AD8:
    // 0x80077AD8: jal         0x800D18D0
    // 0x80077ADC: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x80077ADC: nop

    after_2:
    // 0x80077AE0: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80077AE4: bne         $t7, $zero, L_80077AD8
    if (ctx->r15 != 0) {
        // 0x80077AE8: nop
    
            goto L_80077AD8;
    }
    // 0x80077AE8: nop

    // 0x80077AEC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077AF0:
    // 0x80077AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80077AF4: jal         0x800D18E0
    // 0x80077AF8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80077AF8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_3:
    // 0x80077AFC: jal         0x800D18D0
    // 0x80077B00: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x80077B00: nop

    after_4:
    // 0x80077B04: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80077B08: beq         $t9, $zero, L_80077B28
    if (ctx->r25 == 0) {
        // 0x80077B0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80077B28;
    }
    // 0x80077B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077B10:
    // 0x80077B10: jal         0x800D18D0
    // 0x80077B14: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_5;
    // 0x80077B14: nop

    after_5:
    // 0x80077B18: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80077B1C: bne         $t0, $zero, L_80077B10
    if (ctx->r8 != 0) {
        // 0x80077B20: nop
    
            goto L_80077B10;
    }
    // 0x80077B20: nop

    // 0x80077B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077B28:
    // 0x80077B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077B2C: jr          $ra
    // 0x80077B30: nop

    return;
    // 0x80077B30: nop

;}
