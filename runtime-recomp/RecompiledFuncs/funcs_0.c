#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void input_swap_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A50C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A510: addiu       $v1, $v1, 0x1150
    ctx->r3 = ADD32(ctx->r3, 0X1150);
    // 0x8006A514: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006A518: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8006A51C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8006A520: jr          $ra
    // 0x8006A524: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x8006A524: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A40: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x800B4A44: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B4A48: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B4A4C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B4A50: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B4A54: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B4A58: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B4A5C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B4A60: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B4A64: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B4A68: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B4A6C: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B4A70: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800B4A74: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4A78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B4A7C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800B4A80: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B4A84: beq         $t6, $zero, L_800B5E48
    if (ctx->r14 == 0) {
        // 0x800B4A88: or          $t3, $a1, $zero
        ctx->r11 = ctx->r5 | 0;
            goto L_800B5E48;
    }
    // 0x800B4A88: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800B4A8C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B4A90: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800B4A94: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4A98: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B4A9C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B4AA0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B4AA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B4AA8: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B4AAC: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B4AB0: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x800B4AB4: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B4AB8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B4ABC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B4AC0:
    // 0x800B4AC0: beq         $a0, $v0, L_800B4B00
    if (ctx->r4 == ctx->r2) {
        // 0x800B4AC4: nop
    
            goto L_800B4B00;
    }
    // 0x800B4AC4: nop

    // 0x800B4AC8: beq         $a0, $v0, L_800B5E2C
    if (ctx->r4 == ctx->r2) {
        // 0x800B4ACC: nop
    
            goto L_800B5E2C;
    }
    // 0x800B4ACC: nop

    // 0x800B4AD0: beq         $v0, $zero, L_800B5E2C
    if (ctx->r2 == 0) {
        // 0x800B4AD4: nop
    
            goto L_800B5E2C;
    }
    // 0x800B4AD4: nop

L_800B4AD8:
    // 0x800B4AD8: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B4ADC: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B4AE0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B4AE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B4AE8: beq         $a0, $v1, L_800B5E2C
    if (ctx->r4 == ctx->r3) {
        // 0x800B4AEC: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B5E2C;
    }
    // 0x800B4AEC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4AF0: bne         $v1, $zero, L_800B4AD8
    if (ctx->r3 != 0) {
        // 0x800B4AF4: nop
    
            goto L_800B4AD8;
    }
    // 0x800B4AF4: nop

    // 0x800B4AF8: b           L_800B5E30
    // 0x800B4AFC: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
        goto L_800B5E30;
    // 0x800B4AFC: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B4B00:
    // 0x800B4B00: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B4B04: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4B08: bne         $a0, $v1, L_800B4B28
    if (ctx->r4 != ctx->r3) {
        // 0x800B4B0C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4B28;
    }
    // 0x800B4B0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4B10: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x800B4B14: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4B18: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B4B1C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B4B20: b           L_800B5E2C
    // 0x800B4B24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5E2C;
    // 0x800B4B24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B4B28:
    // 0x800B4B28: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B4B2C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B4B30: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B4B34: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4B38: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B4B3C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800B4B40: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800B4B44: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800B4B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B4B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4B50: beq         $v0, $at, L_800B4B78
    if (ctx->r2 == ctx->r1) {
        // 0x800B4B54: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B4B78;
    }
    // 0x800B4B54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B4B58: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B4B5C: beq         $v0, $at, L_800B4B78
    if (ctx->r2 == ctx->r1) {
        // 0x800B4B60: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_800B4B78;
    }
    // 0x800B4B60: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B4B64: beq         $v0, $at, L_800B4B78
    if (ctx->r2 == ctx->r1) {
        // 0x800B4B68: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_800B4B78;
    }
    // 0x800B4B68: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B4B6C: beq         $v0, $at, L_800B4B78
    if (ctx->r2 == ctx->r1) {
        // 0x800B4B70: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B4B78;
    }
    // 0x800B4B70: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B4B74: bne         $v0, $at, L_800B4C08
    if (ctx->r2 != ctx->r1) {
        // 0x800B4B78: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B4C08;
    }
L_800B4B78:
    // 0x800B4B78: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B4B7C:
    // 0x800B4B7C: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800B4B80: beq         $at, $zero, L_800B4BC8
    if (ctx->r1 == 0) {
        // 0x800B4B84: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B4BC8;
    }
    // 0x800B4B84: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4B88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B4B8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B4B90: addu        $at, $at, $t8
    gpr jr_addend_800B4B9C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B4B94: lw          $t8, -0x7354($at)
    ctx->r24 = ADD32(ctx->r1, -0X7354);
    // 0x800B4B98: nop

    // 0x800B4B9C: jr          $t8
    // 0x800B4BA0: nop

    switch (jr_addend_800B4B9C >> 2) {
        case 0: goto L_800B4BA4; break;
        case 1: goto L_800B4BC8; break;
        case 2: goto L_800B4BC8; break;
        case 3: goto L_800B4BBC; break;
        case 4: goto L_800B4BC8; break;
        case 5: goto L_800B4BC8; break;
        case 6: goto L_800B4BC8; break;
        case 7: goto L_800B4BC8; break;
        case 8: goto L_800B4BC8; break;
        case 9: goto L_800B4BC8; break;
        case 10: goto L_800B4BC8; break;
        case 11: goto L_800B4BAC; break;
        case 12: goto L_800B4BC8; break;
        case 13: goto L_800B4BB4; break;
        case 14: goto L_800B4BC8; break;
        case 15: goto L_800B4BC8; break;
        case 16: goto L_800B4BC4; break;
        default: switch_error(__func__, 0x800B4B9C, 0x800E8CAC);
    }
    // 0x800B4BA0: nop

L_800B4BA4:
    // 0x800B4BA4: b           L_800B4BC8
    // 0x800B4BA8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800B4BC8;
    // 0x800B4BA8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800B4BAC:
    // 0x800B4BAC: b           L_800B4BC8
    // 0x800B4BB0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800B4BC8;
    // 0x800B4BB0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800B4BB4:
    // 0x800B4BB4: b           L_800B4BC8
    // 0x800B4BB8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_800B4BC8;
    // 0x800B4BB8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B4BBC:
    // 0x800B4BBC: b           L_800B4BC8
    // 0x800B4BC0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_800B4BC8;
    // 0x800B4BC0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800B4BC4:
    // 0x800B4BC4: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
L_800B4BC8:
    // 0x800B4BC8: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B4BCC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B4BD0: beq         $v1, $at, L_800B4B78
    if (ctx->r3 == ctx->r1) {
        // 0x800B4BD4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4B78;
    }
    // 0x800B4BD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4BD8: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B4BDC: beq         $v1, $at, L_800B4B7C
    if (ctx->r3 == ctx->r1) {
        // 0x800B4BE0: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B4B7C;
    }
    // 0x800B4BE0: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B4BE4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B4BE8: beq         $v1, $at, L_800B4B7C
    if (ctx->r3 == ctx->r1) {
        // 0x800B4BEC: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B4B7C;
    }
    // 0x800B4BEC: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B4BF0: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B4BF4: beq         $v1, $at, L_800B4B7C
    if (ctx->r3 == ctx->r1) {
        // 0x800B4BF8: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B4B7C;
    }
    // 0x800B4BF8: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B4BFC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B4C00: beq         $v1, $at, L_800B4B7C
    if (ctx->r3 == ctx->r1) {
        // 0x800B4C04: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B4B7C;
    }
    // 0x800B4C04: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B4C08:
    // 0x800B4C08: beq         $s7, $zero, L_800B4C14
    if (ctx->r23 == 0) {
        // 0x800B4C0C: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_800B4C14;
    }
    // 0x800B4C0C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B4C10: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B4C14:
    // 0x800B4C14: bne         $v0, $at, L_800B4C54
    if (ctx->r2 != ctx->r1) {
        // 0x800B4C18: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B4C54;
    }
    // 0x800B4C18: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B4C1C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4C20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4C24: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B4C28: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B4C2C: lw          $t0, -0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, -0X4);
    // 0x800B4C30: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4C34: bgez        $t0, L_800B4C44
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B4C38: nop
    
            goto L_800B4C44;
    }
    // 0x800B4C38: nop

    // 0x800B4C3C: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800B4C40: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B4C44:
    // 0x800B4C44: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B4C48: b           L_800B4C94
    // 0x800B4C4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B4C94;
    // 0x800B4C4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4C50: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
L_800B4C54:
    // 0x800B4C54: bne         $at, $zero, L_800B4C94
    if (ctx->r1 != 0) {
        // 0x800B4C58: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B4C94;
    }
    // 0x800B4C58: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B4C5C: beq         $at, $zero, L_800B4C94
    if (ctx->r1 == 0) {
        // 0x800B4C60: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B4C94;
    }
    // 0x800B4C60: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B4C64:
    // 0x800B4C64: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B4C68: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x800B4C6C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B4C70: addu        $t0, $t6, $v0
    ctx->r8 = ADD32(ctx->r14, ctx->r2);
    // 0x800B4C74: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B4C78: addiu       $t0, $t0, -0x30
    ctx->r8 = ADD32(ctx->r8, -0X30);
    // 0x800B4C7C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4C80: bne         $at, $zero, L_800B4C94
    if (ctx->r1 != 0) {
        // 0x800B4C84: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4C94;
    }
    // 0x800B4C84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4C88: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B4C8C: bne         $at, $zero, L_800B4C64
    if (ctx->r1 != 0) {
        // 0x800B4C90: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B4C64;
    }
    // 0x800B4C90: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B4C94:
    // 0x800B4C94: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800B4C98: bne         $v0, $at, L_800B4D40
    if (ctx->r2 != ctx->r1) {
        // 0x800B4C9C: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_800B4D40;
    }
    // 0x800B4C9C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B4CA0: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B4CA4: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B4CA8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4CAC: bne         $v1, $at, L_800B4CE4
    if (ctx->r3 != ctx->r1) {
        // 0x800B4CB0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4CE4;
    }
    // 0x800B4CB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4CB4: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4CB8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4CBC: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B4CC0: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B4CC4: lw          $t2, -0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, -0X4);
    // 0x800B4CC8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4CCC: bgez        $t2, L_800B4CD8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B4CD0: nop
    
            goto L_800B4CD8;
    }
    // 0x800B4CD0: nop

    // 0x800B4CD4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800B4CD8:
    // 0x800B4CD8: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B4CDC: b           L_800B4D3C
    // 0x800B4CE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B4D3C;
    // 0x800B4CE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B4CE4:
    // 0x800B4CE4: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B4CE8: bne         $at, $zero, L_800B4D3C
    if (ctx->r1 != 0) {
        // 0x800B4CEC: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B4D3C;
    }
    // 0x800B4CEC: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B4CF0: beq         $at, $zero, L_800B4D3C
    if (ctx->r1 == 0) {
        // 0x800B4CF4: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B4D3C;
    }
    // 0x800B4CF4: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B4CF8: bne         $at, $zero, L_800B4D3C
    if (ctx->r1 != 0) {
        // 0x800B4CFC: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800B4D3C;
    }
    // 0x800B4CFC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B4D00: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B4D04: beq         $at, $zero, L_800B4D3C
    if (ctx->r1 == 0) {
        // 0x800B4D08: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B4D3C;
    }
    // 0x800B4D08: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B4D0C:
    // 0x800B4D0C: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B4D10: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x800B4D14: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B4D18: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800B4D1C: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B4D20: addiu       $t2, $t2, -0x30
    ctx->r10 = ADD32(ctx->r10, -0X30);
    // 0x800B4D24: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4D28: bne         $at, $zero, L_800B4D3C
    if (ctx->r1 != 0) {
        // 0x800B4D2C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4D3C;
    }
    // 0x800B4D2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4D30: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B4D34: bne         $at, $zero, L_800B4D0C
    if (ctx->r1 != 0) {
        // 0x800B4D38: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B4D0C;
    }
    // 0x800B4D38: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B4D3C:
    // 0x800B4D3C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
L_800B4D40:
    // 0x800B4D40: beq         $v0, $at, L_800B4D64
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D44: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800B4D64;
    }
    // 0x800B4D44: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B4D48: beq         $v0, $at, L_800B4D64
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D4C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800B4D64;
    }
    // 0x800B4D4C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B4D50: beq         $v0, $at, L_800B4D64
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D54: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_800B4D64;
    }
    // 0x800B4D54: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B4D58: beq         $v0, $at, L_800B4D64
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D5C: addiu       $at, $zero, 0x71
        ctx->r1 = ADD32(0, 0X71);
            goto L_800B4D64;
    }
    // 0x800B4D5C: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B4D60: bne         $v0, $at, L_800B4E04
    if (ctx->r2 != ctx->r1) {
        // 0x800B4D64: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B4E04;
    }
L_800B4D64:
    // 0x800B4D64: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B4D68:
    // 0x800B4D68: sltiu       $at, $t9, 0x26
    ctx->r1 = ctx->r25 < 0X26 ? 1 : 0;
    // 0x800B4D6C: beq         $at, $zero, L_800B4DC4
    if (ctx->r1 == 0) {
        // 0x800B4D70: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B4DC4;
    }
    // 0x800B4D70: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4D74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B4D78: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B4D7C: addu        $at, $at, $t9
    gpr jr_addend_800B4D88 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B4D80: lw          $t9, -0x7310($at)
    ctx->r25 = ADD32(ctx->r1, -0X7310);
    // 0x800B4D84: nop

    // 0x800B4D88: jr          $t9
    // 0x800B4D8C: nop

    switch (jr_addend_800B4D88 >> 2) {
        case 0: goto L_800B4DB0; break;
        case 1: goto L_800B4DC4; break;
        case 2: goto L_800B4DC4; break;
        case 3: goto L_800B4DC4; break;
        case 4: goto L_800B4DC4; break;
        case 5: goto L_800B4DC4; break;
        case 6: goto L_800B4DC4; break;
        case 7: goto L_800B4DC4; break;
        case 8: goto L_800B4DC4; break;
        case 9: goto L_800B4DC4; break;
        case 10: goto L_800B4DC4; break;
        case 11: goto L_800B4DC4; break;
        case 12: goto L_800B4DC4; break;
        case 13: goto L_800B4DC4; break;
        case 14: goto L_800B4DB8; break;
        case 15: goto L_800B4DC4; break;
        case 16: goto L_800B4DC4; break;
        case 17: goto L_800B4DC4; break;
        case 18: goto L_800B4DC4; break;
        case 19: goto L_800B4DC4; break;
        case 20: goto L_800B4DC4; break;
        case 21: goto L_800B4DC4; break;
        case 22: goto L_800B4DC4; break;
        case 23: goto L_800B4DC4; break;
        case 24: goto L_800B4DC4; break;
        case 25: goto L_800B4DC4; break;
        case 26: goto L_800B4DC4; break;
        case 27: goto L_800B4DC4; break;
        case 28: goto L_800B4D90; break;
        case 29: goto L_800B4DC4; break;
        case 30: goto L_800B4DC4; break;
        case 31: goto L_800B4DC4; break;
        case 32: goto L_800B4D98; break;
        case 33: goto L_800B4DC4; break;
        case 34: goto L_800B4DC4; break;
        case 35: goto L_800B4DC4; break;
        case 36: goto L_800B4DC4; break;
        case 37: goto L_800B4DC0; break;
        default: switch_error(__func__, 0x800B4D88, 0x800E8CF0);
    }
    // 0x800B4D8C: nop

L_800B4D90:
    // 0x800B4D90: b           L_800B4DC4
    // 0x800B4D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800B4DC4;
    // 0x800B4D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800B4D98:
    // 0x800B4D98: beq         $a1, $zero, L_800B4DA8
    if (ctx->r5 == 0) {
        // 0x800B4D9C: nop
    
            goto L_800B4DA8;
    }
    // 0x800B4D9C: nop

    // 0x800B4DA0: b           L_800B4DC4
    // 0x800B4DA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B4DC4;
    // 0x800B4DA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B4DA8:
    // 0x800B4DA8: b           L_800B4DC4
    // 0x800B4DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B4DC4;
    // 0x800B4DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B4DB0:
    // 0x800B4DB0: b           L_800B4DC4
    // 0x800B4DB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B4DC4;
    // 0x800B4DB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B4DB8:
    // 0x800B4DB8: b           L_800B4DC4
    // 0x800B4DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B4DC4;
    // 0x800B4DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B4DC0:
    // 0x800B4DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B4DC4:
    // 0x800B4DC4: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B4DC8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B4DCC: beq         $v1, $at, L_800B4D64
    if (ctx->r3 == ctx->r1) {
        // 0x800B4DD0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4D64;
    }
    // 0x800B4DD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B4DD4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B4DD8: beq         $v1, $at, L_800B4D68
    if (ctx->r3 == ctx->r1) {
        // 0x800B4DDC: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B4D68;
    }
    // 0x800B4DDC: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B4DE0: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B4DE4: beq         $v1, $at, L_800B4D68
    if (ctx->r3 == ctx->r1) {
        // 0x800B4DE8: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B4D68;
    }
    // 0x800B4DE8: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B4DEC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B4DF0: beq         $v1, $at, L_800B4D68
    if (ctx->r3 == ctx->r1) {
        // 0x800B4DF4: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B4D68;
    }
    // 0x800B4DF4: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B4DF8: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B4DFC: beq         $v1, $at, L_800B4D68
    if (ctx->r3 == ctx->r1) {
        // 0x800B4E00: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B4D68;
    }
    // 0x800B4E00: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B4E04:
    // 0x800B4E04: andi        $s3, $v1, 0xFF
    ctx->r19 = ctx->r3 & 0XFF;
    // 0x800B4E08: addiu       $t6, $s3, -0x45
    ctx->r14 = ADD32(ctx->r19, -0X45);
    // 0x800B4E0C: sltiu       $at, $t6, 0x34
    ctx->r1 = ctx->r14 < 0X34 ? 1 : 0;
    // 0x800B4E10: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B4E14: beq         $at, $zero, L_800B5E0C
    if (ctx->r1 == 0) {
        // 0x800B4E18: sb          $s3, 0x19A($sp)
        MEM_B(0X19A, ctx->r29) = ctx->r19;
            goto L_800B5E0C;
    }
    // 0x800B4E18: sb          $s3, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r19;
    // 0x800B4E1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B4E20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B4E24: addu        $at, $at, $t6
    gpr jr_addend_800B4E30 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B4E28: lw          $t6, -0x7278($at)
    ctx->r14 = ADD32(ctx->r1, -0X7278);
    // 0x800B4E2C: nop

    // 0x800B4E30: jr          $t6
    // 0x800B4E34: nop

    switch (jr_addend_800B4E30 >> 2) {
        case 0: goto L_800B52C4; break;
        case 1: goto L_800B5E0C; break;
        case 2: goto L_800B5794; break;
        case 3: goto L_800B5E0C; break;
        case 4: goto L_800B5E0C; break;
        case 5: goto L_800B5E0C; break;
        case 6: goto L_800B5E0C; break;
        case 7: goto L_800B5E0C; break;
        case 8: goto L_800B5E0C; break;
        case 9: goto L_800B5E0C; break;
        case 10: goto L_800B5E0C; break;
        case 11: goto L_800B5E0C; break;
        case 12: goto L_800B5E0C; break;
        case 13: goto L_800B5E0C; break;
        case 14: goto L_800B5E0C; break;
        case 15: goto L_800B5E0C; break;
        case 16: goto L_800B5E0C; break;
        case 17: goto L_800B5E0C; break;
        case 18: goto L_800B5E0C; break;
        case 19: goto L_800B4F84; break;
        case 20: goto L_800B5E0C; break;
        case 21: goto L_800B5E0C; break;
        case 22: goto L_800B5E0C; break;
        case 23: goto L_800B5E0C; break;
        case 24: goto L_800B5E0C; break;
        case 25: goto L_800B5E0C; break;
        case 26: goto L_800B5E0C; break;
        case 27: goto L_800B5E0C; break;
        case 28: goto L_800B5E0C; break;
        case 29: goto L_800B5E0C; break;
        case 30: goto L_800B5AC4; break;
        case 31: goto L_800B4E38; break;
        case 32: goto L_800B52C4; break;
        case 33: goto L_800B57A4; break;
        case 34: goto L_800B5794; break;
        case 35: goto L_800B5E0C; break;
        case 36: goto L_800B4E38; break;
        case 37: goto L_800B5E0C; break;
        case 38: goto L_800B5E0C; break;
        case 39: goto L_800B5E0C; break;
        case 40: goto L_800B5E0C; break;
        case 41: goto L_800B5D78; break;
        case 42: goto L_800B4F64; break;
        case 43: goto L_800B5C8C; break;
        case 44: goto L_800B5E0C; break;
        case 45: goto L_800B5E0C; break;
        case 46: goto L_800B5B48; break;
        case 47: goto L_800B5E0C; break;
        case 48: goto L_800B4F44; break;
        case 49: goto L_800B5E0C; break;
        case 50: goto L_800B5E0C; break;
        case 51: goto L_800B4FA4; break;
        default: switch_error(__func__, 0x800B4E30, 0x800E8D88);
    }
    // 0x800B4E34: nop

L_800B4E38:
    // 0x800B4E38: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4E3C: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B4E40: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B4E44: beq         $a0, $zero, L_800B4E70
    if (ctx->r4 == 0) {
        // 0x800B4E48: addiu       $ra, $sp, 0x17B
        ctx->r31 = ADD32(ctx->r29, 0X17B);
            goto L_800B4E70;
    }
    // 0x800B4E48: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
    // 0x800B4E4C: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B4E50: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B4E54: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B4E58: addiu       $s1, $t7, 0x8
    ctx->r17 = ADD32(ctx->r15, 0X8);
    // 0x800B4E5C: lw          $t8, -0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X8);
    // 0x800B4E60: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B4E64: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B4E68: b           L_800B4EEC
    // 0x800B4E6C: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
        goto L_800B4EEC;
    // 0x800B4E6C: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
L_800B4E70:
    // 0x800B4E70: beq         $a1, $zero, L_800B4E9C
    if (ctx->r5 == 0) {
        // 0x800B4E74: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B4E9C;
    }
    // 0x800B4E74: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4E78: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4E7C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B4E80: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B4E84: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B4E88: nop

    // 0x800B4E8C: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B4E90: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B4E94: b           L_800B4EEC
    // 0x800B4E98: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B4EEC;
    // 0x800B4E98: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B4E9C:
    // 0x800B4E9C: bne         $a2, $zero, L_800B4ECC
    if (ctx->r6 != 0) {
        // 0x800B4EA0: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B4ECC;
    }
    // 0x800B4EA0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4EA4: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4EA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4EAC: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B4EB0: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B4EB4: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B4EB8: nop

    // 0x800B4EBC: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B4EC0: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B4EC4: b           L_800B4EEC
    // 0x800B4EC8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B4EEC;
    // 0x800B4EC8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B4ECC:
    // 0x800B4ECC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4ED0: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B4ED4: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B4ED8: lh          $t7, -0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X2);
    // 0x800B4EDC: nop

    // 0x800B4EE0: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B4EE4: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B4EE8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B4EEC:
    // 0x800B4EEC: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B4EF0: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B4EF4: slti        $v0, $t6, 0x0
    ctx->r2 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x800B4EF8: bgtz        $v0, L_800B4F0C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B4EFC: sltiu       $at, $t7, 0x1
        ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
            goto L_800B4F0C;
    }
    // 0x800B4EFC: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800B4F00: bgtz        $t6, L_800B4F10
    if (SIGNED(ctx->r14) > 0) {
        // 0x800B4F04: andi        $t8, $v0, 0xFF
        ctx->r24 = ctx->r2 & 0XFF;
            goto L_800B4F10;
    }
    // 0x800B4F04: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800B4F08: sltiu       $v0, $t7, 0x0
    ctx->r2 = ctx->r15 < 0X0 ? 1 : 0;
L_800B4F0C:
    // 0x800B4F0C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
L_800B4F10:
    // 0x800B4F10: beq         $t8, $zero, L_800B4F30
    if (ctx->r24 == 0) {
        // 0x800B4F14: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_800B4F30;
    }
    // 0x800B4F14: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800B4F18: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800B4F1C: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800B4F20: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800B4F24: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B4F28: b           L_800B5058
    // 0x800B4F2C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
        goto L_800B5058;
    // 0x800B4F2C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
L_800B4F30:
    // 0x800B4F30: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B4F34: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B4F38: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B4F3C: b           L_800B5058
    // 0x800B4F40: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B5058;
    // 0x800B4F40: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B4F44:
    // 0x800B4F44: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4F48: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B4F4C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B4F50: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4F54: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B4F58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B4F5C: b           L_800B4FC0
    // 0x800B4F60: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B4FC0;
    // 0x800B4F60: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B4F64:
    // 0x800B4F64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4F68: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B4F6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800B4F70: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4F74: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B4F78: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B4F7C: b           L_800B4FC0
    // 0x800B4F80: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B4FC0;
    // 0x800B4F80: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B4F84:
    // 0x800B4F84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4F88: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B4F8C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B4F90: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4F94: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B4F98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B4F9C: b           L_800B4FC0
    // 0x800B4FA0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B4FC0;
    // 0x800B4FA0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B4FA4:
    // 0x800B4FA4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4FA8: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B4FAC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B4FB0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4FB4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B4FB8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B4FBC: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B4FC0:
    // 0x800B4FC0: beq         $a0, $zero, L_800B4FE8
    if (ctx->r4 == 0) {
        // 0x800B4FC4: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B4FE8;
    }
    // 0x800B4FC4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B4FC8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B4FCC: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B4FD0: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B4FD4: lw          $t6, -0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, -0X8);
    // 0x800B4FD8: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B4FDC: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B4FE0: b           L_800B5058
    // 0x800B4FE4: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B5058;
    // 0x800B4FE4: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B4FE8:
    // 0x800B4FE8: beq         $a1, $zero, L_800B5010
    if (ctx->r5 == 0) {
        // 0x800B4FEC: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B5010;
    }
    // 0x800B4FEC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B4FF0: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B4FF4: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B4FF8: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B4FFC: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B5000: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5004: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5008: b           L_800B5058
    // 0x800B500C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B5058;
    // 0x800B500C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B5010:
    // 0x800B5010: bne         $a2, $zero, L_800B503C
    if (ctx->r6 != 0) {
        // 0x800B5014: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B503C;
    }
    // 0x800B5014: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5018: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B501C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5020: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5024: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B5028: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B502C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5030: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5034: b           L_800B5058
    // 0x800B5038: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B5058;
    // 0x800B5038: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B503C:
    // 0x800B503C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5040: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5044: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B5048: lhu         $t8, -0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, -0X2);
    // 0x800B504C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5050: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5054: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B5058:
    // 0x800B5058: beq         $v1, $zero, L_800B5070
    if (ctx->r3 == 0) {
        // 0x800B505C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800B5070;
    }
    // 0x800B505C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5060: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B5064: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5068: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B506C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5070:
    // 0x800B5070: bltz        $t2, L_800B507C
    if (SIGNED(ctx->r10) < 0) {
        // 0x800B5074: addiu       $a2, $sp, 0x17C
        ctx->r6 = ADD32(ctx->r29, 0X17C);
            goto L_800B507C;
    }
    // 0x800B5074: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    // 0x800B5078: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B507C:
    // 0x800B507C: bne         $t2, $at, L_800B5088
    if (ctx->r10 != ctx->r1) {
        // 0x800B5080: xori        $t8, $s3, 0x58
        ctx->r24 = ctx->r19 ^ 0X58;
            goto L_800B5088;
    }
    // 0x800B5080: xori        $t8, $s3, 0x58
    ctx->r24 = ctx->r19 ^ 0X58;
    // 0x800B5084: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800B5088:
    // 0x800B5088: lw          $a0, 0x188($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X188);
    // 0x800B508C: lw          $a1, 0x18C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18C);
    // 0x800B5090: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B5094: sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // 0x800B5098: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B509C: sw          $a3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r7;
    // 0x800B50A0: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B50A4: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B50A8: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B50AC: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B50B0: sb          $t4, 0x1A4($sp)
    MEM_B(0X1A4, ctx->r29) = ctx->r12;
    // 0x800B50B4: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B50B8: jal         0x800B4940
    // 0x800B50BC: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    _itoa_recomp(rdram, ctx);
        goto after_0;
    // 0x800B50BC: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800B50C0: addiu       $t6, $sp, 0x17B
    ctx->r14 = ADD32(ctx->r29, 0X17B);
    // 0x800B50C4: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B50C8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B50CC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B50D0: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x800B50D4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B50D8: lw          $a3, 0x194($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X194);
    // 0x800B50DC: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B50E0: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B50E4: lbu         $t4, 0x1A4($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1A4);
    // 0x800B50E8: lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF8);
    // 0x800B50EC: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B50F0: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B50F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B50F8: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x800B50FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B5100: sltu        $a2, $zero, $fp
    ctx->r6 = 0 < ctx->r30 ? 1 : 0;
    // 0x800B5104: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B5108: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B510C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800B5110: beq         $a2, $zero, L_800B5138
    if (ctx->r6 == 0) {
        // 0x800B5114: subu        $t2, $t2, $v1
        ctx->r10 = SUB32(ctx->r10, ctx->r3);
            goto L_800B5138;
    }
    // 0x800B5114: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x800B5118: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800B511C: bne         $a3, $at, L_800B513C
    if (ctx->r7 != ctx->r1) {
        // 0x800B5120: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B513C;
    }
    // 0x800B5120: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5124: bgtz        $t2, L_800B5138
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5128: addiu       $t7, $zero, 0x30
        ctx->r15 = ADD32(0, 0X30);
            goto L_800B5138;
    }
    // 0x800B5128: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x800B512C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x800B5130: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800B5134: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5138:
    // 0x800B5138: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B513C:
    // 0x800B513C: beq         $s3, $zero, L_800B5168
    if (ctx->r19 == 0) {
        // 0x800B5140: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B5168;
    }
    // 0x800B5140: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B5144: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800B5148: beq         $s3, $zero, L_800B5168
    if (ctx->r19 == 0) {
        // 0x800B514C: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B5168;
    }
    // 0x800B514C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B5150: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800B5154:
    // 0x800B5154: slt         $v1, $zero, $t2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5158: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B515C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800B5160: bne         $v1, $zero, L_800B5154
    if (ctx->r3 != 0) {
        // 0x800B5164: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B5154;
    }
    // 0x800B5164: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B5168:
    // 0x800B5168: beq         $a2, $zero, L_800B517C
    if (ctx->r6 == 0) {
        // 0x800B516C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B517C;
    }
    // 0x800B516C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B5170: bne         $a3, $at, L_800B517C
    if (ctx->r7 != ctx->r1) {
        // 0x800B5174: nop
    
            goto L_800B517C;
    }
    // 0x800B5174: nop

    // 0x800B5178: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_800B517C:
    // 0x800B517C: bne         $s2, $zero, L_800B5194
    if (ctx->r18 != 0) {
        // 0x800B5180: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B5194;
    }
    // 0x800B5180: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5184: bne         $s5, $zero, L_800B5194
    if (ctx->r21 != 0) {
        // 0x800B5188: nop
    
            goto L_800B5194;
    }
    // 0x800B5188: nop

    // 0x800B518C: beq         $s6, $zero, L_800B5198
    if (ctx->r22 == 0) {
        // 0x800B5190: nop
    
            goto L_800B5198;
    }
    // 0x800B5190: nop

L_800B5194:
    // 0x800B5194: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5198:
    // 0x800B5198: bne         $s7, $zero, L_800B51C8
    if (ctx->r23 != 0) {
        // 0x800B519C: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B51C8;
    }
    // 0x800B519C: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B51A0: bne         $t4, $at, L_800B51C8
    if (ctx->r12 != ctx->r1) {
        // 0x800B51A4: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B51C8;
    }
    // 0x800B51A4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B51A8: beq         $v1, $zero, L_800B51C8
    if (ctx->r3 == 0) {
        // 0x800B51AC: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B51C8;
    }
    // 0x800B51AC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B51B0:
    // 0x800B51B0: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B51B4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B51B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B51BC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B51C0: bne         $v1, $zero, L_800B51B0
    if (ctx->r3 != 0) {
        // 0x800B51C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B51B0;
    }
    // 0x800B51C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B51C8:
    // 0x800B51C8: beq         $s2, $zero, L_800B51E0
    if (ctx->r18 == 0) {
        // 0x800B51CC: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B51E0;
    }
    // 0x800B51CC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B51D0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B51D4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B51D8: b           L_800B520C
    // 0x800B51DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B520C;
    // 0x800B51DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B51E0:
    // 0x800B51E0: beq         $s5, $zero, L_800B51F8
    if (ctx->r21 == 0) {
        // 0x800B51E4: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B51F8;
    }
    // 0x800B51E4: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B51E8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B51EC: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B51F0: b           L_800B520C
    // 0x800B51F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B520C;
    // 0x800B51F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B51F8:
    // 0x800B51F8: beq         $s6, $zero, L_800B520C
    if (ctx->r22 == 0) {
        // 0x800B51FC: nop
    
            goto L_800B520C;
    }
    // 0x800B51FC: nop

    // 0x800B5200: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5204: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5208: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B520C:
    // 0x800B520C: beq         $a2, $zero, L_800B5230
    if (ctx->r6 == 0) {
        // 0x800B5210: addiu       $t8, $sp, 0x17B
        ctx->r24 = ADD32(ctx->r29, 0X17B);
            goto L_800B5230;
    }
    // 0x800B5210: addiu       $t8, $sp, 0x17B
    ctx->r24 = ADD32(ctx->r29, 0X17B);
    // 0x800B5214: bne         $a3, $at, L_800B5230
    if (ctx->r7 != ctx->r1) {
        // 0x800B5218: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800B5230;
    }
    // 0x800B5218: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800B521C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5220: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5224: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5228: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B522C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
L_800B5230:
    // 0x800B5230: bne         $s7, $zero, L_800B5264
    if (ctx->r23 != 0) {
        // 0x800B5234: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B5264;
    }
    // 0x800B5234: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5238: bne         $t4, $at, L_800B5264
    if (ctx->r12 != ctx->r1) {
        // 0x800B523C: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5264;
    }
    // 0x800B523C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5240: beq         $v1, $zero, L_800B5264
    if (ctx->r3 == 0) {
        // 0x800B5244: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5264;
    }
    // 0x800B5244: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5248:
    // 0x800B5248: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800B524C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5250: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5254: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5258: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B525C: bne         $v1, $zero, L_800B5248
    if (ctx->r3 != 0) {
        // 0x800B5260: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5248;
    }
    // 0x800B5260: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5264:
    // 0x800B5264: sltu        $at, $t8, $a0
    ctx->r1 = ctx->r24 < ctx->r4 ? 1 : 0;
    // 0x800B5268: bne         $at, $zero, L_800B528C
    if (ctx->r1 != 0) {
        // 0x800B526C: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B528C;
    }
    // 0x800B526C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
L_800B5270:
    // 0x800B5270: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B5274: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B5278: sltu        $at, $ra, $a0
    ctx->r1 = ctx->r31 < ctx->r4 ? 1 : 0;
    // 0x800B527C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5280: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5284: beq         $at, $zero, L_800B5270
    if (ctx->r1 == 0) {
        // 0x800B5288: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B5270;
    }
    // 0x800B5288: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B528C:
    // 0x800B528C: beq         $s7, $zero, L_800B52B4
    if (ctx->r23 == 0) {
        // 0x800B5290: nop
    
            goto L_800B52B4;
    }
    // 0x800B5290: nop

    // 0x800B5294: beq         $v1, $zero, L_800B52B4
    if (ctx->r3 == 0) {
        // 0x800B5298: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B52B4;
    }
    // 0x800B5298: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B529C:
    // 0x800B529C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B52A0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B52A4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B52A8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B52AC: bne         $v1, $zero, L_800B529C
    if (ctx->r3 != 0) {
        // 0x800B52B0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B529C;
    }
    // 0x800B52B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B52B4:
    // 0x800B52B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B52B8: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B52BC: b           L_800B5E18
    // 0x800B52C0: nop

        goto L_800B5E18;
    // 0x800B52C0: nop

L_800B52C4:
    // 0x800B52C4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B52C8: lw          $t7, 0x2EF0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2EF0);
    // 0x800B52CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B52D0: beq         $t7, $zero, L_800B52E4
    if (ctx->r15 == 0) {
        // 0x800B52D4: addiu       $t9, $zero, 0x84
        ctx->r25 = ADD32(0, 0X84);
            goto L_800B52E4;
    }
    // 0x800B52D4: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B52D8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B52DC: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B52E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B52E4:
    // 0x800B52E4: bgez        $t2, L_800B52F0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B52E8: andi        $t6, $s1, 0x1
        ctx->r14 = ctx->r17 & 0X1;
            goto L_800B52F0;
    }
    // 0x800B52E8: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x800B52EC: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
L_800B52F0:
    // 0x800B52F0: beq         $a2, $zero, L_800B531C
    if (ctx->r6 == 0) {
        // 0x800B52F4: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B531C;
    }
    // 0x800B52F4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B52F8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B52FC: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5300: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B5304: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5308: nop

    // 0x800B530C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B5310: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B5314: b           L_800B5368
    // 0x800B5318: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
        goto L_800B5368;
    // 0x800B5318: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800B531C:
    // 0x800B531C: beq         $t6, $zero, L_800B5330
    if (ctx->r14 == 0) {
        // 0x800B5320: andi        $t7, $s1, 0x2
        ctx->r15 = ctx->r17 & 0X2;
            goto L_800B5330;
    }
    // 0x800B5320: andi        $t7, $s1, 0x2
    ctx->r15 = ctx->r17 & 0X2;
    // 0x800B5324: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5328: b           L_800B5358
    // 0x800B532C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B5358;
    // 0x800B532C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B5330:
    // 0x800B5330: beq         $t7, $zero, L_800B5344
    if (ctx->r15 == 0) {
        // 0x800B5334: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5344;
    }
    // 0x800B5334: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5338: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B533C: b           L_800B5354
    // 0x800B5340: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B5354;
    // 0x800B5340: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B5344:
    // 0x800B5344: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5348: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B534C: addiu       $s1, $t9, 0x8
    ctx->r17 = ADD32(ctx->r25, 0X8);
    // 0x800B5350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B5354:
    // 0x800B5354: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B5358:
    // 0x800B5358: lwc1        $f9, -0x8($v1)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B535C: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B5360: swc1        $f9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800B5364: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_800B5368:
    // 0x800B5368: lb          $t8, 0xD0($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XD0);
    // 0x800B536C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B5370: bgez        $t8, L_800B5390
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B5374: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800B5390;
    }
    // 0x800B5374: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5378: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B537C: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B5384: neg.d       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = -ctx->f10.d;
    // 0x800B5388: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B538C: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B5390:
    // 0x800B5390: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5394: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5398: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B539C: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B53A0: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800B53A4: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B53A8: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B53AC: bc1f        L_800B53C0
    if (!c1cs) {
        // 0x800B53B0: andi        $a0, $t2, 0x3
        ctx->r4 = ctx->r10 & 0X3;
            goto L_800B53C0;
    }
    // 0x800B53B0: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B53B4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B53B8: b           L_800B540C
    // 0x800B53BC: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
        goto L_800B540C;
    // 0x800B53BC: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
L_800B53C0:
    // 0x800B53C0: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B53C4: nop

    // 0x800B53C8: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B53CC: nop

    // 0x800B53D0: bc1f        L_800B540C
    if (!c1cs) {
        // 0x800B53D4: nop
    
            goto L_800B540C;
    }
    // 0x800B53D4: nop

    // 0x800B53D8: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B53DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B53E0: bc1f        L_800B540C
    if (!c1cs) {
        // 0x800B53E4: mov.d       $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
            goto L_800B540C;
    }
    // 0x800B53E4: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B53E8: nop

L_800B53EC:
    // 0x800B53EC: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B53F0: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B53F4: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B53F8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800B53FC: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x800B5400: nop

    // 0x800B5404: bc1t        L_800B53EC
    if (c1cs) {
        // 0x800B5408: nop
    
            goto L_800B53EC;
    }
    // 0x800B5408: nop

L_800B540C:
    // 0x800B540C: c.le.d      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.d <= ctx->f6.d;
    // 0x800B5410: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B5414: bc1f        L_800B5454
    if (!c1cs) {
        // 0x800B5418: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800B5454;
    }
    // 0x800B5418: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800B541C: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800B5420: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5424: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B5428: bc1f        L_800B5454
    if (!c1cs) {
        // 0x800B542C: mov.d       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
            goto L_800B5454;
    }
    // 0x800B542C: mov.d       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
L_800B5430:
    // 0x800B5430: mov.d       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.d = ctx->f0.d;
    // 0x800B5434: mul.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5438: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B543C: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5440: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B5444: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800B5448: nop

    // 0x800B544C: bc1t        L_800B5430
    if (c1cs) {
        // 0x800B5450: nop
    
            goto L_800B5430;
    }
    // 0x800B5450: nop

L_800B5454:
    // 0x800B5454: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B5458: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B545C: mul.d       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800B5460: beq         $s3, $zero, L_800B54C4
    if (ctx->r19 == 0) {
        // 0x800B5464: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800B54C4;
    }
    // 0x800B5464: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800B5468: beq         $a0, $zero, L_800B5480
    if (ctx->r4 == 0) {
        // 0x800B546C: addu        $v1, $a0, $t2
        ctx->r3 = ADD32(ctx->r4, ctx->r10);
            goto L_800B5480;
    }
    // 0x800B546C: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B5470:
    // 0x800B5470: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B5474: bne         $v1, $v0, L_800B5470
    if (ctx->r3 != ctx->r2) {
        // 0x800B5478: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B5470;
    }
    // 0x800B5478: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B547C: beq         $v0, $zero, L_800B54C4
    if (ctx->r2 == 0) {
        // 0x800B5480: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800B54C4;
    }
L_800B5480:
    // 0x800B5480: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B5484: beq         $v0, $zero, L_800B54AC
    if (ctx->r2 == 0) {
        // 0x800B5488: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B54AC;
    }
    // 0x800B5488: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B548C:
    // 0x800B548C: nop

    // 0x800B5490: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5494: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B5498: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B549C: nop

    // 0x800B54A0: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B54A4: bne         $v0, $zero, L_800B548C
    if (ctx->r2 != 0) {
        // 0x800B54A8: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B548C;
    }
    // 0x800B54A8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B54AC:
    // 0x800B54AC: nop

    // 0x800B54B0: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B54B4: nop

    // 0x800B54B8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B54BC: nop

    // 0x800B54C0: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B54C4:
    // 0x800B54C4: mul.d       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B54C8: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B54CC: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B54D0: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x800B54D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B54D8: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800B54DC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B54E0: c.le.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d <= ctx->f6.d;
    // 0x800B54E4: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B54E8: bc1f        L_800B54F8
    if (!c1cs) {
        // 0x800B54EC: swc1        $f7, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800B54F8;
    }
    // 0x800B54EC: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800B54F0: mov.d       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.d = ctx->f2.d;
    // 0x800B54F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800B54F8:
    // 0x800B54F8: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B54FC: bne         $v0, $zero, L_800B5514
    if (ctx->r2 != 0) {
        // 0x800B5500: xori        $a2, $a2, 0x1
        ctx->r6 = ctx->r6 ^ 0X1;
            goto L_800B5514;
    }
    // 0x800B5500: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B5504: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B5508: bne         $a0, $zero, L_800B5514
    if (ctx->r4 != 0) {
        // 0x800B550C: nop
    
            goto L_800B5514;
    }
    // 0x800B550C: nop

    // 0x800B5510: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5514:
    // 0x800B5514: bne         $s3, $zero, L_800B5520
    if (ctx->r19 != 0) {
        // 0x800B5518: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5520;
    }
    // 0x800B5518: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B551C: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5520:
    // 0x800B5520: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5524: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800B5528: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x800B552C: bne         $s7, $zero, L_800B555C
    if (ctx->r23 != 0) {
        // 0x800B5530: addiu       $a1, $a1, 0x5
        ctx->r5 = ADD32(ctx->r5, 0X5);
            goto L_800B555C;
    }
    // 0x800B5530: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x800B5534: bne         $t4, $at, L_800B555C
    if (ctx->r12 != ctx->r1) {
        // 0x800B5538: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B555C;
    }
    // 0x800B5538: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B553C: beq         $v1, $zero, L_800B555C
    if (ctx->r3 == 0) {
        // 0x800B5540: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B555C;
    }
    // 0x800B5540: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5544:
    // 0x800B5544: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5548: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B554C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5550: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5554: bne         $v1, $zero, L_800B5544
    if (ctx->r3 != 0) {
        // 0x800B5558: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5544;
    }
    // 0x800B5558: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B555C:
    // 0x800B555C: beq         $v0, $zero, L_800B5574
    if (ctx->r2 == 0) {
        // 0x800B5560: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5574;
    }
    // 0x800B5560: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5564: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5568: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B556C: b           L_800B55A0
    // 0x800B5570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B55A0;
    // 0x800B5570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5574:
    // 0x800B5574: beq         $s5, $zero, L_800B558C
    if (ctx->r21 == 0) {
        // 0x800B5578: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B558C;
    }
    // 0x800B5578: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B557C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5580: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5584: b           L_800B55A0
    // 0x800B5588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B55A0;
    // 0x800B5588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B558C:
    // 0x800B558C: beq         $s6, $zero, L_800B55A0
    if (ctx->r22 == 0) {
        // 0x800B5590: nop
    
            goto L_800B55A0;
    }
    // 0x800B5590: nop

    // 0x800B5594: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5598: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B559C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B55A0:
    // 0x800B55A0: bne         $s7, $zero, L_800B55D0
    if (ctx->r23 != 0) {
        // 0x800B55A4: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B55D0;
    }
    // 0x800B55A4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B55A8: bne         $t4, $at, L_800B55D0
    if (ctx->r12 != ctx->r1) {
        // 0x800B55AC: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B55D0;
    }
    // 0x800B55AC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B55B0: beq         $v1, $zero, L_800B55D0
    if (ctx->r3 == 0) {
        // 0x800B55B4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B55D0;
    }
    // 0x800B55B4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B55B8:
    // 0x800B55B8: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B55BC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B55C0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B55C4: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B55C8: bne         $v1, $zero, L_800B55B8
    if (ctx->r3 != 0) {
        // 0x800B55CC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B55B8;
    }
    // 0x800B55CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B55D0:
    // 0x800B55D0: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B55D4: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B55D8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B55DC: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x800B55E0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B55E4: bc1f        L_800B560C
    if (!c1cs) {
        // 0x800B55E8: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B560C;
    }
    // 0x800B55E8: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
L_800B55EC:
    // 0x800B55EC: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B55F0: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B55F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B55F8: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x800B55FC: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800B5600: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B5604: bc1t        L_800B55EC
    if (c1cs) {
        // 0x800B5608: swc1        $f5, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800B55EC;
    }
    // 0x800B5608: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B560C:
    // 0x800B560C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5610: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5614: bne         $s3, $zero, L_800B5624
    if (ctx->r19 != 0) {
        // 0x800B5618: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5624;
    }
    // 0x800B5618: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B561C: beq         $fp, $zero, L_800B5630
    if (ctx->r30 == 0) {
        // 0x800B5620: nop
    
            goto L_800B5630;
    }
    // 0x800B5620: nop

L_800B5624:
    // 0x800B5624: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5628: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B562C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5630:
    // 0x800B5630: beq         $s3, $zero, L_800B5684
    if (ctx->r19 == 0) {
        // 0x800B5634: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800B5684;
    }
    // 0x800B5634: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800B5638:
    // 0x800B5638: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B563C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5640: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5644: c.le.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d <= ctx->f6.d;
    // 0x800B5648: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B564C: bc1f        L_800B5674
    if (!c1cs) {
        // 0x800B5650: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B5674;
    }
    // 0x800B5650: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_800B5654:
    // 0x800B5654: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5658: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B565C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5660: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800B5664: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800B5668: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800B566C: bc1t        L_800B5654
    if (c1cs) {
        // 0x800B5670: swc1        $f11, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
            goto L_800B5654;
    }
    // 0x800B5670: swc1        $f11, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
L_800B5674:
    // 0x800B5674: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5678: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B567C: bgtz        $t2, L_800B5638
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5680: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5638;
    }
    // 0x800B5680: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
L_800B5684:
    // 0x800B5684: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5688: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B568C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5690: bgez        $s4, L_800B56EC
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B5694: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B56EC;
    }
    // 0x800B5694: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B5698: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x800B569C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B56A0: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B56A4: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B56A8: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B56AC: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B56B0: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B56B4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B56B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B56BC: mflo        $v1
    ctx->r3 = lo;
    // 0x800B56C0: nop

    // 0x800B56C4: nop

    // 0x800B56C8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B56CC: mfhi        $t8
    ctx->r24 = hi;
    // 0x800B56D0: addiu       $v1, $t8, 0x30
    ctx->r3 = ADD32(ctx->r24, 0X30);
    // 0x800B56D4: nop

    // 0x800B56D8: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B56DC: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B56E0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B56E4: b           L_800B572C
    // 0x800B56E8: nop

        goto L_800B572C;
    // 0x800B56E8: nop

L_800B56EC:
    // 0x800B56EC: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B56F0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800B56F4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B56F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B56FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5700: mflo        $v1
    ctx->r3 = lo;
    // 0x800B5704: nop

    // 0x800B5708: nop

    // 0x800B570C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B5710: mfhi        $t6
    ctx->r14 = hi;
    // 0x800B5714: addiu       $v1, $t6, 0x30
    ctx->r3 = ADD32(ctx->r14, 0X30);
    // 0x800B5718: nop

    // 0x800B571C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5720: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B5724: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B5728: nop

L_800B572C:
    // 0x800B572C: beq         $a2, $zero, L_800B574C
    if (ctx->r6 == 0) {
        // 0x800B5730: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800B574C;
    }
    // 0x800B5730: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800B5734: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5738: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5740: mflo        $v0
    ctx->r2 = lo;
    // 0x800B5744: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800B5748: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
L_800B574C:
    // 0x800B574C: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B5750: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5754: sb          $a0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r4;
    // 0x800B5758: beq         $s7, $zero, L_800B5784
    if (ctx->r23 == 0) {
        // 0x800B575C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800B5784;
    }
    // 0x800B575C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B5760: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5764: beq         $v1, $zero, L_800B5784
    if (ctx->r3 == 0) {
        // 0x800B5768: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5784;
    }
    // 0x800B5768: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B576C:
    // 0x800B576C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5770: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5774: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5778: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B577C: bne         $v1, $zero, L_800B576C
    if (ctx->r3 != 0) {
        // 0x800B5780: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B576C;
    }
    // 0x800B5780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5784:
    // 0x800B5784: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5788: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B578C: b           L_800B5E18
    // 0x800B5790: nop

        goto L_800B5E18;
    // 0x800B5790: nop

L_800B5794:
    // 0x800B5794: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5798: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B579C: b           L_800B5E18
    // 0x800B57A0: nop

        goto L_800B5E18;
    // 0x800B57A0: nop

L_800B57A4:
    // 0x800B57A4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B57A8: lw          $t9, 0x2EF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2EF0);
    // 0x800B57AC: mov.d       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.d = ctx->f20.d;
    // 0x800B57B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B57B4: beq         $t9, $zero, L_800B57CC
    if (ctx->r25 == 0) {
        // 0x800B57B8: mov.d       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
            goto L_800B57CC;
    }
    // 0x800B57B8: mov.d       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
    // 0x800B57BC: addiu       $t8, $zero, 0x84
    ctx->r24 = ADD32(0, 0X84);
    // 0x800B57C0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B57C4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B57C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B57CC:
    // 0x800B57CC: bgez        $t2, L_800B57DC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B57D0: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B57DC;
    }
    // 0x800B57D0: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B57D4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800B57D8: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B57DC:
    // 0x800B57DC: beq         $s3, $zero, L_800B5844
    if (ctx->r19 == 0) {
        // 0x800B57E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B5844;
    }
    // 0x800B57E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B57E4: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B57E8: beq         $a0, $zero, L_800B5800
    if (ctx->r4 == 0) {
        // 0x800B57EC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B5800;
    }
    // 0x800B57EC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B57F0:
    // 0x800B57F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B57F4: bne         $v1, $v0, L_800B57F0
    if (ctx->r3 != ctx->r2) {
        // 0x800B57F8: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B57F0;
    }
    // 0x800B57F8: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B57FC: beq         $v0, $t2, L_800B5844
    if (ctx->r2 == ctx->r10) {
        // 0x800B5800: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B5844;
    }
L_800B5800:
    // 0x800B5800: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5804: beq         $v0, $t2, L_800B582C
    if (ctx->r2 == ctx->r10) {
        // 0x800B5808: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B582C;
    }
    // 0x800B5808: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B580C:
    // 0x800B580C: nop

    // 0x800B5810: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5814: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5818: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B581C: nop

    // 0x800B5820: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5824: bne         $v0, $t2, L_800B580C
    if (ctx->r2 != ctx->r10) {
        // 0x800B5828: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B580C;
    }
    // 0x800B5828: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B582C:
    // 0x800B582C: nop

    // 0x800B5830: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5834: nop

    // 0x800B5838: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B583C: nop

    // 0x800B5840: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5844:
    // 0x800B5844: beq         $a2, $zero, L_800B5868
    if (ctx->r6 == 0) {
        // 0x800B5848: andi        $t7, $s1, 0x1
        ctx->r15 = ctx->r17 & 0X1;
            goto L_800B5868;
    }
    // 0x800B5848: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x800B584C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5850: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5854: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5858: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B585C: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5860: b           L_800B58B0
    // 0x800B5864: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
        goto L_800B58B0;
    // 0x800B5864: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_800B5868:
    // 0x800B5868: beq         $t7, $zero, L_800B587C
    if (ctx->r15 == 0) {
        // 0x800B586C: andi        $t9, $s1, 0x2
        ctx->r25 = ctx->r17 & 0X2;
            goto L_800B587C;
    }
    // 0x800B586C: andi        $t9, $s1, 0x2
    ctx->r25 = ctx->r17 & 0X2;
    // 0x800B5870: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5874: b           L_800B58A4
    // 0x800B5878: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B58A4;
    // 0x800B5878: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B587C:
    // 0x800B587C: beq         $t9, $zero, L_800B5890
    if (ctx->r25 == 0) {
        // 0x800B5880: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5890;
    }
    // 0x800B5880: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5884: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B5888: b           L_800B58A0
    // 0x800B588C: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B58A0;
    // 0x800B588C: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B5890:
    // 0x800B5890: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5894: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5898: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B589C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B58A0:
    // 0x800B58A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B58A4:
    // 0x800B58A4: lwc1        $f1, -0x8($v1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B58A8: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B58AC: nop

L_800B58B0:
    // 0x800B58B0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B58B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B58B8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B58BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B58C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B58C4: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800B58C8: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800B58CC: bc1f        L_800B58DC
    if (!c1cs) {
        // 0x800B58D0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B58DC;
    }
    // 0x800B58D0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B58D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B58D8: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_800B58DC:
    // 0x800B58DC: add.d       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f0.d + ctx->f10.d;
    // 0x800B58E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B58E4: c.le.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d <= ctx->f0.d;
    // 0x800B58E8: mov.d       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.d = ctx->f20.d;
    // 0x800B58EC: bc1f        L_800B5910
    if (!c1cs) {
        // 0x800B58F0: sltu        $a2, $zero, $a1
        ctx->r6 = 0 < ctx->r5 ? 1 : 0;
            goto L_800B5910;
    }
    // 0x800B58F0: sltu        $a2, $zero, $a1
    ctx->r6 = 0 < ctx->r5 ? 1 : 0;
L_800B58F4:
    // 0x800B58F4: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
    // 0x800B58F8: mul.d       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = MUL_D(ctx->f14.d, ctx->f18.d);
    // 0x800B58FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5900: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800B5904: nop

    // 0x800B5908: bc1t        L_800B58F4
    if (c1cs) {
        // 0x800B590C: nop
    
            goto L_800B58F4;
    }
    // 0x800B590C: nop

L_800B5910:
    // 0x800B5910: bne         $a2, $zero, L_800B5928
    if (ctx->r6 != 0) {
        // 0x800B5914: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800B5928;
    }
    // 0x800B5914: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B5918: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B591C: bne         $a0, $zero, L_800B5928
    if (ctx->r4 != 0) {
        // 0x800B5920: nop
    
            goto L_800B5928;
    }
    // 0x800B5920: nop

    // 0x800B5924: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5928:
    // 0x800B5928: bne         $s3, $zero, L_800B5934
    if (ctx->r19 != 0) {
        // 0x800B592C: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5934;
    }
    // 0x800B592C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B5930: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5934:
    // 0x800B5934: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5938: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800B593C: bne         $s7, $zero, L_800B596C
    if (ctx->r23 != 0) {
        // 0x800B5940: addu        $a1, $t7, $t2
        ctx->r5 = ADD32(ctx->r15, ctx->r10);
            goto L_800B596C;
    }
    // 0x800B5940: addu        $a1, $t7, $t2
    ctx->r5 = ADD32(ctx->r15, ctx->r10);
    // 0x800B5944: bne         $t4, $at, L_800B596C
    if (ctx->r12 != ctx->r1) {
        // 0x800B5948: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B596C;
    }
    // 0x800B5948: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B594C: beq         $v1, $zero, L_800B596C
    if (ctx->r3 == 0) {
        // 0x800B5950: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B596C;
    }
    // 0x800B5950: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5954:
    // 0x800B5954: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5958: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B595C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5960: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5964: bne         $v1, $zero, L_800B5954
    if (ctx->r3 != 0) {
        // 0x800B5968: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5954;
    }
    // 0x800B5968: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B596C:
    // 0x800B596C: beq         $a2, $zero, L_800B5984
    if (ctx->r6 == 0) {
        // 0x800B5970: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5984;
    }
    // 0x800B5970: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5974: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5978: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B597C: b           L_800B59B0
    // 0x800B5980: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B59B0;
    // 0x800B5980: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5984:
    // 0x800B5984: beq         $s5, $zero, L_800B599C
    if (ctx->r21 == 0) {
        // 0x800B5988: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B599C;
    }
    // 0x800B5988: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B598C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5990: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5994: b           L_800B59B0
    // 0x800B5998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B59B0;
    // 0x800B5998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B599C:
    // 0x800B599C: beq         $s6, $zero, L_800B59B0
    if (ctx->r22 == 0) {
        // 0x800B59A0: nop
    
            goto L_800B59B0;
    }
    // 0x800B59A0: nop

    // 0x800B59A4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B59A8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B59AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B59B0:
    // 0x800B59B0: bne         $s7, $zero, L_800B59E0
    if (ctx->r23 != 0) {
        // 0x800B59B4: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B59E0;
    }
    // 0x800B59B4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B59B8: bne         $t4, $at, L_800B59E0
    if (ctx->r12 != ctx->r1) {
        // 0x800B59BC: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B59E0;
    }
    // 0x800B59BC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B59C0: beq         $v1, $zero, L_800B59E0
    if (ctx->r3 == 0) {
        // 0x800B59C4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B59E0;
    }
    // 0x800B59C4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B59C8:
    // 0x800B59C8: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B59CC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B59D0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B59D4: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B59D8: bne         $v1, $zero, L_800B59C8
    if (ctx->r3 != 0) {
        // 0x800B59DC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B59C8;
    }
    // 0x800B59DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B59E0:
    // 0x800B59E0: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B59E4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B59E8: bc1f        L_800B5A0C
    if (!c1cs) {
        // 0x800B59EC: nop
    
            goto L_800B5A0C;
    }
    // 0x800B59EC: nop

L_800B59F0:
    // 0x800B59F0: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B59F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B59F8: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B59FC: nop

    // 0x800B5A00: bc1t        L_800B59F0
    if (c1cs) {
        // 0x800B5A04: nop
    
            goto L_800B59F0;
    }
    // 0x800B5A04: nop

    // 0x800B5A08: nop

L_800B5A0C:
    // 0x800B5A0C: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
    // 0x800B5A10: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5A14: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5A18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5A1C: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x800B5A20: nop

    // 0x800B5A24: bc1t        L_800B59E0
    if (c1cs) {
        // 0x800B5A28: nop
    
            goto L_800B59E0;
    }
    // 0x800B5A28: nop

    // 0x800B5A2C: bne         $s3, $zero, L_800B5A3C
    if (ctx->r19 != 0) {
        // 0x800B5A30: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B5A3C;
    }
    // 0x800B5A30: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800B5A34: beq         $fp, $zero, L_800B5A48
    if (ctx->r30 == 0) {
        // 0x800B5A38: nop
    
            goto L_800B5A48;
    }
    // 0x800B5A38: nop

L_800B5A3C:
    // 0x800B5A3C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5A40: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5A44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5A48:
    // 0x800B5A48: beq         $s3, $zero, L_800B5A8C
    if (ctx->r19 == 0) {
        // 0x800B5A4C: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5A8C;
    }
    // 0x800B5A4C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
L_800B5A50:
    // 0x800B5A50: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5A54: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5A58: bc1f        L_800B5A78
    if (!c1cs) {
        // 0x800B5A5C: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800B5A78;
    }
    // 0x800B5A5C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800B5A60:
    // 0x800B5A60: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B5A64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5A68: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5A6C: nop

    // 0x800B5A70: bc1t        L_800B5A60
    if (c1cs) {
        // 0x800B5A74: nop
    
            goto L_800B5A60;
    }
    // 0x800B5A74: nop

L_800B5A78:
    // 0x800B5A78: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B5A7C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5A80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5A84: bgtz        $t2, L_800B5A50
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5A88: div.d       $f2, $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
            goto L_800B5A50;
    }
    // 0x800B5A88: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
L_800B5A8C:
    // 0x800B5A8C: beq         $s7, $zero, L_800B5AB4
    if (ctx->r23 == 0) {
        // 0x800B5A90: nop
    
            goto L_800B5AB4;
    }
    // 0x800B5A90: nop

    // 0x800B5A94: beq         $v1, $zero, L_800B5AB4
    if (ctx->r3 == 0) {
        // 0x800B5A98: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5AB4;
    }
    // 0x800B5A98: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5A9C:
    // 0x800B5A9C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5AA0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5AA4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AA8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5AAC: bne         $v1, $zero, L_800B5A9C
    if (ctx->r3 != 0) {
        // 0x800B5AB0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5A9C;
    }
    // 0x800B5AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5AB4:
    // 0x800B5AB4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5AB8: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5ABC: b           L_800B5E18
    // 0x800B5AC0: nop

        goto L_800B5E18;
    // 0x800B5AC0: nop

L_800B5AC4:
    // 0x800B5AC4: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5AC8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5ACC: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B5AD0: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B5AD4: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B5AD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5ADC: sra         $t8, $t9, 31
    ctx->r24 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800B5AE0: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x800B5AE4: bne         $s7, $zero, L_800B5B0C
    if (ctx->r23 != 0) {
        // 0x800B5AE8: sw          $t9, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r25;
            goto L_800B5B0C;
    }
    // 0x800B5AE8: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B5AEC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5AF0: blez        $t0, L_800B5B10
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B5AF4: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_800B5B10;
    }
    // 0x800B5AF4: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B5AF8:
    // 0x800B5AF8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5AFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B00: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5B04: bgtz        $t0, L_800B5AF8
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B5B08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5AF8;
    }
    // 0x800B5B08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B0C:
    // 0x800B5B0C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B5B10:
    // 0x800B5B10: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5B18: beq         $s7, $zero, L_800B5B3C
    if (ctx->r23 == 0) {
        // 0x800B5B1C: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B5B3C;
    }
    // 0x800B5B1C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B5B20: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5B24: blez        $t0, L_800B5B3C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B5B28: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5B3C;
    }
L_800B5B28:
    // 0x800B5B28: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5B2C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B30: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5B34: bgtz        $t0, L_800B5B28
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B5B38: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5B28;
    }
    // 0x800B5B38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B3C:
    // 0x800B5B3C: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5B40: b           L_800B5E18
    // 0x800B5B44: nop

        goto L_800B5E18;
    // 0x800B5B44: nop

L_800B5B48:
    // 0x800B5B48: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5B4C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5B50: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5B54: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B5B58: lw          $a1, -0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X4);
    // 0x800B5B5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5B60: bne         $a1, $zero, L_800B5B94
    if (ctx->r5 != 0) {
        // 0x800B5B64: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800B5B94;
    }
    // 0x800B5B64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B5B68: beq         $t2, $at, L_800B5B7C
    if (ctx->r10 == ctx->r1) {
        // 0x800B5B6C: lui         $a1, 0x800F
        ctx->r5 = S32(0X800F << 16);
            goto L_800B5B7C;
    }
    // 0x800B5B6C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B5B70: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x800B5B74: bne         $at, $zero, L_800B5B88
    if (ctx->r1 != 0) {
        // 0x800B5B78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B5B88;
    }
    // 0x800B5B78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B5B7C:
    // 0x800B5B7C: addiu       $a1, $a1, -0x73AC
    ctx->r5 = ADD32(ctx->r5, -0X73AC);
    // 0x800B5B80: b           L_800B5BE4
    // 0x800B5B84: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_800B5BE4;
    // 0x800B5B84: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800B5B88:
    // 0x800B5B88: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B5B8C: b           L_800B5BE4
    // 0x800B5B90: addiu       $a1, $a1, -0x73B0
    ctx->r5 = ADD32(ctx->r5, -0X73B0);
        goto L_800B5BE4;
    // 0x800B5B90: addiu       $a1, $a1, -0x73B0
    ctx->r5 = ADD32(ctx->r5, -0X73B0);
L_800B5B94:
    // 0x800B5B94: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x800B5B98: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B5B9C: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B5BA0: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B5BA4: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B5BA8: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B5BAC: jal         0x800CE19C
    // 0x800B5BB0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x800B5BB0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800B5BB4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B5BB8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B5BBC: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x800B5BC0: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B5BC4: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B5BC8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B5BCC: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B5BD0: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B5BD4: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B5BD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5BDC: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B5BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B5BE4:
    // 0x800B5BE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B5BE8: beq         $t2, $at, L_800B5BFC
    if (ctx->r10 == ctx->r1) {
        // 0x800B5BEC: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800B5BFC;
    }
    // 0x800B5BEC: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B5BF0: beq         $at, $zero, L_800B5BFC
    if (ctx->r1 == 0) {
        // 0x800B5BF4: nop
    
            goto L_800B5BFC;
    }
    // 0x800B5BF4: nop

    // 0x800B5BF8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800B5BFC:
    // 0x800B5BFC: bne         $s7, $zero, L_800B5C28
    if (ctx->r23 != 0) {
        // 0x800B5C00: subu        $t0, $t0, $a0
        ctx->r8 = SUB32(ctx->r8, ctx->r4);
            goto L_800B5C28;
    }
    // 0x800B5C00: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800B5C04: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5C08: beq         $v1, $zero, L_800B5C28
    if (ctx->r3 == 0) {
        // 0x800B5C0C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5C28;
    }
    // 0x800B5C0C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5C10:
    // 0x800B5C10: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5C14: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5C18: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C1C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5C20: bne         $v1, $zero, L_800B5C10
    if (ctx->r3 != 0) {
        // 0x800B5C24: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5C10;
    }
    // 0x800B5C24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5C28:
    // 0x800B5C28: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B5C2C: beq         $v1, $zero, L_800B5C54
    if (ctx->r3 == 0) {
        // 0x800B5C30: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B5C54;
    }
    // 0x800B5C30: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B5C34:
    // 0x800B5C34: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B5C38: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B5C3C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800B5C40: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5C48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B5C4C: bne         $v1, $zero, L_800B5C34
    if (ctx->r3 != 0) {
        // 0x800B5C50: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B5C34;
    }
    // 0x800B5C50: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B5C54:
    // 0x800B5C54: beq         $s7, $zero, L_800B5C7C
    if (ctx->r23 == 0) {
        // 0x800B5C58: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5C7C;
    }
    // 0x800B5C58: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5C5C: beq         $v1, $zero, L_800B5C7C
    if (ctx->r3 == 0) {
        // 0x800B5C60: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5C7C;
    }
    // 0x800B5C60: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5C64:
    // 0x800B5C64: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5C68: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5C6C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C70: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5C74: bne         $v1, $zero, L_800B5C64
    if (ctx->r3 != 0) {
        // 0x800B5C78: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5C64;
    }
    // 0x800B5C78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5C7C:
    // 0x800B5C7C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5C80: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5C84: b           L_800B5E18
    // 0x800B5C88: nop

        goto L_800B5E18;
    // 0x800B5C88: nop

L_800B5C8C:
    // 0x800B5C8C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5C90: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5C94: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B5C98: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B5C9C: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B5CA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B5CA4: beq         $v0, $zero, L_800B5CE0
    if (ctx->r2 == 0) {
        // 0x800B5CA8: addiu       $a0, $a0, -0x73A4
        ctx->r4 = ADD32(ctx->r4, -0X73A4);
            goto L_800B5CE0;
    }
    // 0x800B5CA8: addiu       $a0, $a0, -0x73A4
    ctx->r4 = ADD32(ctx->r4, -0X73A4);
    // 0x800B5CAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5CB0: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x800B5CB4: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5CB8: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5CBC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B5CC0: sb          $t8, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r24;
    // 0x800B5CC4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800B5CC8: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5CCC: sw          $v0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r2;
    // 0x800B5CD0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B5CD4: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x800B5CD8: b           L_800B5058
    // 0x800B5CDC: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5058;
    // 0x800B5CDC: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B5CE0:
    // 0x800B5CE0: bne         $s7, $zero, L_800B5D0C
    if (ctx->r23 != 0) {
        // 0x800B5CE4: addiu       $t0, $t0, -0x5
        ctx->r8 = ADD32(ctx->r8, -0X5);
            goto L_800B5D0C;
    }
    // 0x800B5CE4: addiu       $t0, $t0, -0x5
    ctx->r8 = ADD32(ctx->r8, -0X5);
    // 0x800B5CE8: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CEC: beq         $v1, $zero, L_800B5D0C
    if (ctx->r3 == 0) {
        // 0x800B5CF0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5D0C;
    }
    // 0x800B5CF0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5CF4:
    // 0x800B5CF4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CF8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5CFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5D00: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5D04: bne         $v1, $zero, L_800B5CF4
    if (ctx->r3 != 0) {
        // 0x800B5D08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5CF4;
    }
    // 0x800B5D08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5D0C:
    // 0x800B5D0C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800B5D10: lbu         $t9, -0x73A4($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X73A4);
    // 0x800B5D14: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800B5D18: beq         $t9, $zero, L_800B5D40
    if (ctx->r25 == 0) {
        // 0x800B5D1C: addiu       $t8, $t8, -0x73A4
        ctx->r24 = ADD32(ctx->r24, -0X73A4);
            goto L_800B5D40;
    }
    // 0x800B5D1C: addiu       $t8, $t8, -0x73A4
    ctx->r24 = ADD32(ctx->r24, -0X73A4);
    // 0x800B5D20: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800B5D24: nop

L_800B5D28:
    // 0x800B5D28: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5D2C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B5D30: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5D34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5D38: bne         $v0, $zero, L_800B5D28
    if (ctx->r2 != 0) {
        // 0x800B5D3C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B5D28;
    }
    // 0x800B5D3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800B5D40:
    // 0x800B5D40: beq         $s7, $zero, L_800B5D68
    if (ctx->r23 == 0) {
        // 0x800B5D44: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5D68;
    }
    // 0x800B5D44: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5D48: beq         $v1, $zero, L_800B5D68
    if (ctx->r3 == 0) {
        // 0x800B5D4C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5D68;
    }
    // 0x800B5D4C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5D50:
    // 0x800B5D50: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5D54: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5D58: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5D5C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5D60: bne         $v1, $zero, L_800B5D50
    if (ctx->r3 != 0) {
        // 0x800B5D64: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5D50;
    }
    // 0x800B5D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5D68:
    // 0x800B5D68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5D6C: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5D70: b           L_800B5E18
    // 0x800B5D74: nop

        goto L_800B5E18;
    // 0x800B5D74: nop

L_800B5D78:
    // 0x800B5D78: beq         $a0, $zero, L_800B5DA4
    if (ctx->r4 == 0) {
        // 0x800B5D7C: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800B5DA4;
    }
    // 0x800B5D7C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5D80: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5D84: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5D88: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5D8C: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5D90: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B5D94: sra         $t8, $t1, 31
    ctx->r24 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B5D98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B5D9C: b           L_800B5E00
    // 0x800B5DA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800B5E00;
    // 0x800B5DA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800B5DA4:
    // 0x800B5DA4: beq         $a1, $zero, L_800B5DC4
    if (ctx->r5 == 0) {
        // 0x800B5DA8: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B5DC4;
    }
    // 0x800B5DA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5DAC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5DB0: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B5DB4: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B5DB8: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B5DBC: b           L_800B5E00
    // 0x800B5DC0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B5E00;
    // 0x800B5DC0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B5DC4:
    // 0x800B5DC4: bne         $a2, $zero, L_800B5DE8
    if (ctx->r6 != 0) {
        // 0x800B5DC8: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B5DE8;
    }
    // 0x800B5DC8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5DCC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5DD0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5DD4: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5DD8: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5DDC: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B5DE0: b           L_800B5E00
    // 0x800B5DE4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B5E00;
    // 0x800B5DE4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B5DE8:
    // 0x800B5DE8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5DEC: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5DF0: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B5DF4: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B5DF8: nop

    // 0x800B5DFC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_800B5E00:
    // 0x800B5E00: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5E04: b           L_800B5E18
    // 0x800B5E08: nop

        goto L_800B5E18;
    // 0x800B5E08: nop

L_800B5E0C:
    // 0x800B5E0C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5E10: lw          $v1, 0x2EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2EF0);
    // 0x800B5E14: nop

L_800B5E18:
    // 0x800B5E18: beq         $v1, $zero, L_800B5E2C
    if (ctx->r3 == 0) {
        // 0x800B5E1C: addiu       $t9, $zero, 0x83
        ctx->r25 = ADD32(0, 0X83);
            goto L_800B5E2C;
    }
    // 0x800B5E1C: addiu       $t9, $zero, 0x83
    ctx->r25 = ADD32(0, 0X83);
    // 0x800B5E20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5E24: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5E28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5E2C:
    // 0x800B5E2C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B5E30:
    // 0x800B5E30: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B5E34: bne         $v1, $zero, L_800B4AC0
    if (ctx->r3 != 0) {
        // 0x800B5E38: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B4AC0;
    }
    // 0x800B5E38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5E3C: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B5E40: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x800B5E44: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
L_800B5E48:
    // 0x800B5E48: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800B5E4C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B5E50: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B5E54: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B5E58: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B5E5C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B5E60: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B5E64: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B5E68: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B5E6C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B5E70: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B5E74: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B5E78: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B5E7C: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    // 0x800B5E80: jr          $ra
    // 0x800B5E84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800B5E84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void menu_imagegroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CA58: jr          $ra
    // 0x8009CA5C: nop

    return;
    // 0x8009CA5C: nop

;}
RECOMP_FUNC void decrease_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B46BC: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B46C0: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B46C4: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B46C8: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B46CC: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B46D0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B46D4: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x800B46D8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B46DC: beq         $at, $zero, L_800B46EC
    if (ctx->r1 == 0) {
        // 0x800B46E0: nop
    
            goto L_800B46EC;
    }
    // 0x800B46E0: nop

    // 0x800B46E4: b           L_800B46F0
    // 0x800B46E8: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B46F0;
    // 0x800B46E8: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B46EC:
    // 0x800B46EC: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B46F0:
    // 0x800B46F0: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B46F4: nop

    // 0x800B46F8: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B46FC: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B4700: nop

    // 0x800B4704: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B4708: jr          $ra
    // 0x800B470C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B470C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void hud_race_finish_multiplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6254: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A6258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A625C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800A6260: jal         0x8006BD98
    // 0x800A6264: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_0;
    // 0x800A6264: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A6268: jal         0x8009EC80
    // 0x800A626C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x800A626C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A6270: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6274: beq         $v0, $zero, L_800A639C
    if (ctx->r2 == 0) {
        // 0x800A6278: nop
    
            goto L_800A639C;
    }
    // 0x800A6278: nop

    // 0x800A627C: jal         0x8006EAB0
    // 0x800A6280: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x800A6280: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_2:
    // 0x800A6284: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6288: beq         $v0, $zero, L_800A639C
    if (ctx->r2 == 0) {
        // 0x800A628C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A639C;
    }
    // 0x800A628C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A6290: lbu         $t6, 0x7189($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7189);
    // 0x800A6294: nop

    // 0x800A6298: bne         $t6, $zero, L_800A639C
    if (ctx->r14 != 0) {
        // 0x800A629C: nop
    
            goto L_800A639C;
    }
    // 0x800A629C: nop

    // 0x800A62A0: jal         0x8000E184
    // 0x800A62A4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_player_two_in_control(rdram, ctx);
        goto after_3;
    // 0x800A62A4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_3:
    // 0x800A62A8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A62AC: beq         $v0, $zero, L_800A631C
    if (ctx->r2 == 0) {
        // 0x800A62B0: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A631C;
    }
    // 0x800A62B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A62B4: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A62B8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A62BC: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x800A62C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A62C4: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A62C8: nop

    // 0x800A62CC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A62D0: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A62D4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A62D8: nop

    // 0x800A62DC: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A62E0: nop

    // 0x800A62E4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A62E8: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A62EC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A62F0: nop

    // 0x800A62F4: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A62F8: nop

    // 0x800A62FC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A6300: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A6304: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6308: nop

    // 0x800A630C: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6310: nop

    // 0x800A6314: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A6318: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
L_800A631C:
    // 0x800A631C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6320: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A6324: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6328: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A632C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6330: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A6334: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A6338: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A633C: addiu       $v1, $v1, 0x2770
    ctx->r3 = ADD32(ctx->r3, 0X2770);
    // 0x800A6340: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A6344: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A634C: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A6350: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A6354: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6358: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A635C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6360: nop

    // 0x800A6364: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A6368: nop

    // 0x800A636C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A6370: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A6374: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6378: nop

    // 0x800A637C: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6380: nop

    // 0x800A6384: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6388: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A638C: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A6390: nop

    // 0x800A6394: sb          $t7, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r15;
    // 0x800A6398: sb          $t8, 0x7189($at)
    MEM_B(0X7189, ctx->r1) = ctx->r24;
L_800A639C:
    // 0x800A639C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A63A0: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A63A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A63A8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A63AC: lbu         $t9, 0x5FA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5FA);
    // 0x800A63B0: addiu       $v1, $v1, 0x2770
    ctx->r3 = ADD32(ctx->r3, 0X2770);
    // 0x800A63B4: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x800A63B8: beq         $at, $zero, L_800A6D9C
    if (ctx->r1 == 0) {
        // 0x800A63BC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800A6D9C;
    }
    // 0x800A63BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A63C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A63C4: addu        $at, $at, $t9
    gpr jr_addend_800A63D0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A63C8: lw          $t9, -0x78BC($at)
    ctx->r25 = ADD32(ctx->r1, -0X78BC);
    // 0x800A63CC: nop

    // 0x800A63D0: jr          $t9
    // 0x800A63D4: nop

    switch (jr_addend_800A63D0 >> 2) {
        case 0: goto L_800A63D8; break;
        case 1: goto L_800A691C; break;
        case 2: goto L_800A6BCC; break;
        case 3: goto L_800A6CA4; break;
        case 4: goto L_800A6D68; break;
        default: switch_error(__func__, 0x800A63D0, 0x800E8744);
    }
    // 0x800A63D4: nop

L_800A63D8:
    // 0x800A63D8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A63DC: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x800A63E0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800A63E4: bne         $t3, $zero, L_800A641C
    if (ctx->r11 != 0) {
        // 0x800A63E8: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A641C;
    }
    // 0x800A63E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A63EC: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
    // 0x800A63F0: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A63F4: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x800A63F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A63FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6400: jal         0x80001D04
    // 0x800A6404: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A6404: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    after_4:
    // 0x800A6408: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A640C: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A6410: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6414: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6418: nop

L_800A641C:
    // 0x800A641C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6420: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x800A6424: addiu       $t6, $zero, -0x14
    ctx->r14 = ADD32(0, -0X14);
    // 0x800A6428: beq         $v1, $zero, L_800A6444
    if (ctx->r3 == 0) {
        // 0x800A642C: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_800A6444;
    }
    // 0x800A642C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6430: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A6434: beq         $v1, $t0, L_800A6448
    if (ctx->r3 == ctx->r8) {
        // 0x800A6438: nop
    
            goto L_800A6448;
    }
    // 0x800A6438: nop

    // 0x800A643C: b           L_800A6464
    // 0x800A6440: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800A6464;
    // 0x800A6440: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800A6444:
    // 0x800A6444: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800A6448:
    // 0x800A6448: sb          $t6, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r14;
    // 0x800A644C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6450: addiu       $v1, $zero, -0xF
    ctx->r3 = ADD32(0, -0XF);
    // 0x800A6454: sb          $v1, 0x17D($t7)
    MEM_B(0X17D, ctx->r15) = ctx->r3;
    // 0x800A6458: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A645C: b           L_800A64B8
    // 0x800A6460: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
        goto L_800A64B8;
    // 0x800A6460: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
L_800A6464:
    // 0x800A6464: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6468: addiu       $t9, $zero, -0x5A
    ctx->r25 = ADD32(0, -0X5A);
    // 0x800A646C: beq         $v1, $zero, L_800A647C
    if (ctx->r3 == 0) {
        // 0x800A6470: nop
    
            goto L_800A647C;
    }
    // 0x800A6470: nop

    // 0x800A6474: bne         $a2, $v1, L_800A649C
    if (ctx->r6 != ctx->r3) {
        // 0x800A6478: addiu       $t4, $zero, 0x37
        ctx->r12 = ADD32(0, 0X37);
            goto L_800A649C;
    }
    // 0x800A6478: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
L_800A647C:
    // 0x800A647C: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A6480: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A6484: addiu       $v1, $zero, -0x55
    ctx->r3 = ADD32(0, -0X55);
    // 0x800A6488: sb          $v1, 0x17D($t2)
    MEM_B(0X17D, ctx->r10) = ctx->r3;
    // 0x800A648C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A6490: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6494: b           L_800A64B8
    // 0x800A6498: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
        goto L_800A64B8;
    // 0x800A6498: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
L_800A649C:
    // 0x800A649C: sb          $t4, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r12;
    // 0x800A64A0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A64A4: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A64A8: sb          $v1, 0x17D($t5)
    MEM_B(0X17D, ctx->r13) = ctx->r3;
    // 0x800A64AC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A64B0: nop

    // 0x800A64B4: sb          $v1, 0x2FD($t6)
    MEM_B(0X2FD, ctx->r14) = ctx->r3;
L_800A64B8:
    // 0x800A64B8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800A64BC: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    // 0x800A64C0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A64C4: nop

    // 0x800A64C8: bne         $t7, $zero, L_800A6518
    if (ctx->r15 != 0) {
        // 0x800A64CC: nop
    
            goto L_800A6518;
    }
    // 0x800A64CC: nop

    // 0x800A64D0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A64D4: nop

    // 0x800A64D8: lb          $t8, 0x5FD($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A64DC: nop

    // 0x800A64E0: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x800A64E4: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A64E8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A64EC: nop

    // 0x800A64F0: lb          $t2, 0x17D($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X17D);
    // 0x800A64F4: nop

    // 0x800A64F8: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x800A64FC: sb          $t3, 0x17D($v0)
    MEM_B(0X17D, ctx->r2) = ctx->r11;
    // 0x800A6500: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6504: nop

    // 0x800A6508: lb          $t4, 0x2FD($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A650C: nop

    // 0x800A6510: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x800A6514: sb          $t5, 0x2FD($v0)
    MEM_B(0X2FD, ctx->r2) = ctx->r13;
L_800A6518:
    // 0x800A6518: lh          $v0, 0x1AC($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A651C: nop

    // 0x800A6520: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800A6524: beq         $at, $zero, L_800A6538
    if (ctx->r1 == 0) {
        // 0x800A6528: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800A6538;
    }
    // 0x800A6528: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800A652C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6530: b           L_800A6544
    // 0x800A6534: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
        goto L_800A6544;
    // 0x800A6534: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
L_800A6538:
    // 0x800A6538: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800A653C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800A6540: sh          $t8, 0x618($t9)
    MEM_H(0X618, ctx->r25) = ctx->r24;
L_800A6544:
    // 0x800A6544: lh          $t2, 0x1AC($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6548: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A654C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800A6550: sh          $t3, 0x5F8($t4)
    MEM_H(0X5F8, ctx->r12) = ctx->r11;
    // 0x800A6554: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6558: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A655C: sb          $t0, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r8;
    // 0x800A6560: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A6564: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A6568: beq         $v0, $a2, L_800A658C
    if (ctx->r2 == ctx->r6) {
        // 0x800A656C: nop
    
            goto L_800A658C;
    }
    // 0x800A656C: nop

    // 0x800A6570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A6574: beq         $v0, $at, L_800A66C8
    if (ctx->r2 == ctx->r1) {
        // 0x800A6578: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A66C8;
    }
    // 0x800A6578: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A657C: beq         $v0, $at, L_800A66C8
    if (ctx->r2 == ctx->r1) {
        // 0x800A6580: nop
    
            goto L_800A66C8;
    }
    // 0x800A6580: nop

    // 0x800A6584: b           L_800A6828
    // 0x800A6588: nop

        goto L_800A6828;
    // 0x800A6588: nop

L_800A658C:
    // 0x800A658C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6590: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6594: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6598: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A659C: bne         $v1, $zero, L_800A65BC
    if (ctx->r3 != 0) {
        // 0x800A65A0: lui         $at, 0x4337
        ctx->r1 = S32(0X4337 << 16);
            goto L_800A65BC;
    }
    // 0x800A65A0: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A65A4: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A65A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A65AC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A65B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A65B4: b           L_800A65D0
    // 0x800A65B8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
        goto L_800A65D0;
    // 0x800A65B8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A65BC:
    // 0x800A65BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A65C0: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A65C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A65C8: nop

    // 0x800A65CC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A65D0:
    // 0x800A65D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A65D4: bne         $t6, $zero, L_800A668C
    if (ctx->r14 != 0) {
        // 0x800A65D8: nop
    
            goto L_800A668C;
    }
    // 0x800A65D8: nop

    // 0x800A65DC: lwc1        $f17, -0x78A8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X78A8);
    // 0x800A65E0: lwc1        $f16, -0x78A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78A4);
    // 0x800A65E4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800A65E8: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A65EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A65F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A65F4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800A65F8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A65FC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A6600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6604: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6608: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A660C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6610: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6614: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800A6618: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A661C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A6620: nop

    // 0x800A6624: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A6628: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A662C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6630: nop

    // 0x800A6634: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6638: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A663C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A6640: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A6644: nop

    // 0x800A6648: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A664C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A6650: nop

    // 0x800A6654: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A6658: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A665C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6660: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A6664: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A6668: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800A666C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A6670: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6674: bne         $v1, $zero, L_800A668C
    if (ctx->r3 != 0) {
        // 0x800A6678: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A668C;
    }
    // 0x800A6678: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A667C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6680: nop

    // 0x800A6684: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A6688: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A668C:
    // 0x800A668C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A6690: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6694: swc1        $f12, 0x16C($t3)
    MEM_W(0X16C, ctx->r11) = ctx->f12.u32l;
    // 0x800A6698: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A669C: nop

    // 0x800A66A0: swc1        $f0, 0x170($t4)
    MEM_W(0X170, ctx->r12) = ctx->f0.u32l;
    // 0x800A66A4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A66A8: nop

    // 0x800A66AC: swc1        $f14, 0x2EC($t5)
    MEM_W(0X2EC, ctx->r13) = ctx->f14.u32l;
    // 0x800A66B0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A66B4: nop

    // 0x800A66B8: swc1        $f2, 0x2F0($t6)
    MEM_W(0X2F0, ctx->r14) = ctx->f2.u32l;
    // 0x800A66BC: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A66C0: b           L_800A6828
    // 0x800A66C4: nop

        goto L_800A6828;
    // 0x800A66C4: nop

L_800A66C8:
    // 0x800A66C8: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A66CC: nop

    // 0x800A66D0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A66D4: beq         $at, $zero, L_800A66F0
    if (ctx->r1 == 0) {
        // 0x800A66D8: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_800A66F0;
    }
    // 0x800A66D8: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A66DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A66E0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A66E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A66E8: b           L_800A6704
    // 0x800A66EC: nop

        goto L_800A6704;
    // 0x800A66EC: nop

L_800A66F0:
    // 0x800A66F0: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A66F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A66F8: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A66FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6700: nop

L_800A6704:
    // 0x800A6704: beq         $v1, $zero, L_800A6714
    if (ctx->r3 == 0) {
        // 0x800A6708: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_800A6714;
    }
    // 0x800A6708: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800A670C: bne         $a2, $v1, L_800A6728
    if (ctx->r6 != ctx->r3) {
        // 0x800A6710: nop
    
            goto L_800A6728;
    }
    // 0x800A6710: nop

L_800A6714:
    // 0x800A6714: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6718: lui         $at, 0xC366
    ctx->r1 = S32(0XC366 << 16);
    // 0x800A671C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6720: b           L_800A6740
    // 0x800A6724: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
        goto L_800A6740;
    // 0x800A6724: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6728:
    // 0x800A6728: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800A672C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6730: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A6734: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6738: nop

    // 0x800A673C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6740:
    // 0x800A6740: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6744: bne         $t7, $zero, L_800A67F0
    if (ctx->r15 != 0) {
        // 0x800A6748: nop
    
            goto L_800A67F0;
    }
    // 0x800A6748: nop

    // 0x800A674C: lwc1        $f17, -0x78A0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X78A0);
    // 0x800A6750: lwc1        $f16, -0x789C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X789C);
    // 0x800A6754: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800A6758: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A675C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800A6760: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A6764: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6768: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A676C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6770: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6774: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800A6778: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800A677C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6780: nop

    // 0x800A6784: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6788: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A678C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6790: nop

    // 0x800A6794: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6798: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A679C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A67A0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A67A4: nop

    // 0x800A67A8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A67AC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A67B0: nop

    // 0x800A67B4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A67B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A67BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A67C0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A67C4: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A67C8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A67CC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A67D0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A67D4: beq         $at, $zero, L_800A67F0
    if (ctx->r1 == 0) {
        // 0x800A67D8: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A67F0;
    }
    // 0x800A67D8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A67DC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A67E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A67E4: nop

    // 0x800A67E8: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A67EC: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A67F0:
    // 0x800A67F0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A67F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A67F8: swc1        $f12, 0x16C($t4)
    MEM_W(0X16C, ctx->r12) = ctx->f12.u32l;
    // 0x800A67FC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6800: nop

    // 0x800A6804: swc1        $f0, 0x170($t5)
    MEM_W(0X170, ctx->r13) = ctx->f0.u32l;
    // 0x800A6808: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A680C: nop

    // 0x800A6810: swc1        $f14, 0x2EC($t6)
    MEM_W(0X2EC, ctx->r14) = ctx->f14.u32l;
    // 0x800A6814: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6818: nop

    // 0x800A681C: swc1        $f2, 0x2F0($t7)
    MEM_W(0X2F0, ctx->r15) = ctx->f2.u32l;
    // 0x800A6820: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x800A6824: nop

L_800A6828:
    // 0x800A6828: beq         $t0, $v0, L_800A6DA8
    if (ctx->r8 == ctx->r2) {
        // 0x800A682C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A6DA8;
    }
    // 0x800A682C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6830: jal         0x8006BDB0
    // 0x800A6834: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_5;
    // 0x800A6834: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A6838: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A683C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A6840: lw          $t8, 0x128($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X128);
    // 0x800A6844: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A6848: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800A684C: lb          $t9, 0x4B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6850: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6854: blez        $t9, L_800A6890
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A6858: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_800A6890;
    }
    // 0x800A6858: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A685C: lb          $a1, 0x4B($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6860: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800A6864:
    // 0x800A6864: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x800A6868: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A686C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A6870: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A6874: beq         $at, $zero, L_800A6880
    if (ctx->r1 == 0) {
        // 0x800A6878: addu        $t0, $t0, $v0
        ctx->r8 = ADD32(ctx->r8, ctx->r2);
            goto L_800A6880;
    }
    // 0x800A6878: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800A687C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800A6880:
    // 0x800A6880: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800A6884: bne         $at, $zero, L_800A6864
    if (ctx->r1 != 0) {
        // 0x800A6888: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A6864;
    }
    // 0x800A6888: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A688C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_800A6890:
    // 0x800A6890: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A6894: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A6898: jal         0x80059790
    // 0x800A689C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    get_timestamp_from_frames(rdram, ctx);
        goto after_6;
    // 0x800A689C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_6:
    // 0x800A68A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A68A4: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A68A8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A68AC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A68B0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A68B4: sb          $t3, 0x2FA($t4)
    MEM_B(0X2FA, ctx->r12) = ctx->r11;
    // 0x800A68B8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A68BC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A68C0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A68C4: sb          $t5, 0x2FB($t6)
    MEM_B(0X2FB, ctx->r14) = ctx->r13;
    // 0x800A68C8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A68CC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A68D0: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A68D4: sb          $t7, 0x2FC($t8)
    MEM_B(0X2FC, ctx->r24) = ctx->r15;
    // 0x800A68D8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800A68DC: jal         0x80059790
    // 0x800A68E0: nop

    get_timestamp_from_frames(rdram, ctx);
        goto after_7;
    // 0x800A68E0: nop

    after_7:
    // 0x800A68E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A68E8: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A68EC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A68F0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800A68F4: nop

    // 0x800A68F8: sb          $t9, 0x17A($t2)
    MEM_B(0X17A, ctx->r10) = ctx->r25;
    // 0x800A68FC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6900: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A6904: nop

    // 0x800A6908: sb          $t3, 0x17B($t4)
    MEM_B(0X17B, ctx->r12) = ctx->r11;
    // 0x800A690C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6910: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800A6914: b           L_800A6DA4
    // 0x800A6918: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
        goto L_800A6DA4;
    // 0x800A6918: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
L_800A691C:
    // 0x800A691C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800A6920: lb          $a1, 0x5FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A6924: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A6928: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A692C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6930: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A6934: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x800A6938: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x800A693C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A6940: lwc1        $f2, 0x5EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A6944: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A694C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A6950: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A6954: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800A6958: bc1f        L_800A6968
    if (!c1cs) {
        // 0x800A695C: addiu       $t2, $a1, 0xA0
        ctx->r10 = ADD32(ctx->r5, 0XA0);
            goto L_800A6968;
    }
    // 0x800A695C: addiu       $t2, $a1, 0xA0
    ctx->r10 = ADD32(ctx->r5, 0XA0);
    // 0x800A6960: b           L_800A69A0
    // 0x800A6964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A69A0;
    // 0x800A6964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6968:
    // 0x800A6968: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A696C: nop

    // 0x800A6970: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6974: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A6978: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A697C: nop

    // 0x800A6980: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A6984: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6988: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A698C: nop

    // 0x800A6990: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6994: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A6998: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A699C: nop

L_800A69A0:
    // 0x800A69A0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A69A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A69A8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A69AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A69B0: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A69B4: swc1        $f6, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A69B8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A69BC: nop

    // 0x800A69C0: lwc1        $f8, 0x60C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A69C4: nop

    // 0x800A69C8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A69CC: swc1        $f10, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f10.u32l;
    // 0x800A69D0: lbu         $t4, 0x6D37($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X6D37);
    // 0x800A69D4: nop

    // 0x800A69D8: beq         $t0, $t4, L_800A6AF0
    if (ctx->r8 == ctx->r12) {
        // 0x800A69DC: nop
    
            goto L_800A6AF0;
    }
    // 0x800A69DC: nop

    // 0x800A69E0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A69E4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A69E8: lb          $a1, 0x17D($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17D);
    // 0x800A69EC: lwc1        $f0, 0x16C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A69F0: addu        $t5, $a1, $a0
    ctx->r13 = ADD32(ctx->r5, ctx->r4);
    // 0x800A69F4: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x800A69F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A69FC: addiu       $t7, $a1, 0xA0
    ctx->r15 = ADD32(ctx->r5, 0XA0);
    // 0x800A6A00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6A04: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800A6A08: nop

    // 0x800A6A0C: bc1f        L_800A6A1C
    if (!c1cs) {
        // 0x800A6A10: nop
    
            goto L_800A6A1C;
    }
    // 0x800A6A10: nop

    // 0x800A6A14: b           L_800A6A54
    // 0x800A6A18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6A54;
    // 0x800A6A18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6A1C:
    // 0x800A6A1C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A6A20: nop

    // 0x800A6A24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6A28: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6A2C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6A30: nop

    // 0x800A6A34: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6A38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6A3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6A40: nop

    // 0x800A6A44: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6A48: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6A4C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A6A50: nop

L_800A6A54:
    // 0x800A6A54: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A6A58: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A6A5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6A60: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6A64: swc1        $f4, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f4.u32l;
    // 0x800A6A68: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A6C: nop

    // 0x800A6A70: lb          $a1, 0x2FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A6A74: lwc1        $f2, 0x2EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6A78: subu        $t9, $a1, $a0
    ctx->r25 = SUB32(ctx->r5, ctx->r4);
    // 0x800A6A7C: addiu       $t2, $t9, 0xA0
    ctx->r10 = ADD32(ctx->r25, 0XA0);
    // 0x800A6A80: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6A84: addiu       $t3, $a1, 0xA0
    ctx->r11 = ADD32(ctx->r5, 0XA0);
    // 0x800A6A88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6A8C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800A6A90: nop

    // 0x800A6A94: bc1f        L_800A6AA4
    if (!c1cs) {
        // 0x800A6A98: nop
    
            goto L_800A6AA4;
    }
    // 0x800A6A98: nop

    // 0x800A6A9C: b           L_800A6ADC
    // 0x800A6AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6ADC;
    // 0x800A6AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6AA4:
    // 0x800A6AA4: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A6AA8: nop

    // 0x800A6AAC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6AB0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A6AB4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A6AB8: nop

    // 0x800A6ABC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A6AC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6AC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6AC8: nop

    // 0x800A6ACC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A6AD0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6AD4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A6AD8: nop

L_800A6ADC:
    // 0x800A6ADC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A6AE0: nop

    // 0x800A6AE4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6AE8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800A6AEC: swc1        $f6, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f6.u32l;
L_800A6AF0:
    // 0x800A6AF0: beq         $a2, $zero, L_800A6BBC
    if (ctx->r6 == 0) {
        // 0x800A6AF4: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A6BBC;
    }
    // 0x800A6AF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A6AF8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6AFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6B00: sb          $a2, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r6;
    // 0x800A6B04: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6B08: addiu       $t6, $zero, -0x78
    ctx->r14 = ADD32(0, -0X78);
    // 0x800A6B0C: sb          $t6, 0x5FB($t7)
    MEM_B(0X5FB, ctx->r15) = ctx->r14;
    // 0x800A6B10: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A6B14: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A6B18: sb          $zero, 0x5FC($t8)
    MEM_B(0X5FC, ctx->r24) = 0;
    // 0x800A6B1C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A6B20: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6B24: bne         $t9, $zero, L_800A6BBC
    if (ctx->r25 != 0) {
        // 0x800A6B28: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A6BBC;
    }
    // 0x800A6B28: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A6B2C: bne         $t2, $at, L_800A6B98
    if (ctx->r10 != ctx->r1) {
        // 0x800A6B30: nop
    
            goto L_800A6B98;
    }
    // 0x800A6B30: nop

    // 0x800A6B34: lh          $v1, 0x1AC($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6B38: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    // 0x800A6B3C: beq         $v1, $t0, L_800A6B5C
    if (ctx->r3 == ctx->r8) {
        // 0x800A6B40: nop
    
            goto L_800A6B5C;
    }
    // 0x800A6B40: nop

    // 0x800A6B44: beq         $v1, $a2, L_800A6B5C
    if (ctx->r3 == ctx->r6) {
        // 0x800A6B48: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A6B5C;
    }
    // 0x800A6B48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A6B4C: beq         $v1, $at, L_800A6B70
    if (ctx->r3 == ctx->r1) {
        // 0x800A6B50: addiu       $a0, $zero, 0x14C
        ctx->r4 = ADD32(0, 0X14C);
            goto L_800A6B70;
    }
    // 0x800A6B50: addiu       $a0, $zero, 0x14C
    ctx->r4 = ADD32(0, 0X14C);
    // 0x800A6B54: b           L_800A6B84
    // 0x800A6B58: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
        goto L_800A6B84;
    // 0x800A6B58: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
L_800A6B5C:
    // 0x800A6B5C: jal         0x80001D04
    // 0x800A6B60: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A6B60: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_8:
    // 0x800A6B64: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6B68: b           L_800A6BBC
    // 0x800A6B6C: nop

        goto L_800A6BBC;
    // 0x800A6B6C: nop

L_800A6B70:
    // 0x800A6B70: jal         0x80001D04
    // 0x800A6B74: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A6B74: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A6B78: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6B7C: b           L_800A6BBC
    // 0x800A6B80: nop

        goto L_800A6BBC;
    // 0x800A6B80: nop

L_800A6B84:
    // 0x800A6B84: jal         0x80001D04
    // 0x800A6B88: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A6B88: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_10:
    // 0x800A6B8C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6B90: b           L_800A6BBC
    // 0x800A6B94: nop

        goto L_800A6BBC;
    // 0x800A6B94: nop

L_800A6B98:
    // 0x800A6B98: jal         0x8001B640
    // 0x800A6B9C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    timetrial_ghost_staff(rdram, ctx);
        goto after_11;
    // 0x800A6B9C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_11:
    // 0x800A6BA0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6BA4: bne         $v0, $zero, L_800A6BBC
    if (ctx->r2 != 0) {
        // 0x800A6BA8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A6BBC;
    }
    // 0x800A6BA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A6BAC: jal         0x800A6DB4
    // 0x800A6BB0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    hud_time_trial_message(rdram, ctx);
        goto after_12;
    // 0x800A6BB0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_12:
    // 0x800A6BB4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6BB8: nop

L_800A6BBC:
    // 0x800A6BBC: jal         0x800A5F18
    // 0x800A6BC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_13;
    // 0x800A6BC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x800A6BC4: b           L_800A6DA8
    // 0x800A6BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6DA8;
    // 0x800A6BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6BCC:
    // 0x800A6BCC: lb          $t3, 0x5FB($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A6BD0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A6BD4: addiu       $t7, $zero, -0x78
    ctx->r15 = ADD32(0, -0X78);
    // 0x800A6BD8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A6BDC: sb          $t5, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r13;
    // 0x800A6BE0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A6BE8: lb          $t6, 0x5FB($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A6BEC: nop

    // 0x800A6BF0: slti        $at, $t6, 0x78
    ctx->r1 = SIGNED(ctx->r14) < 0X78 ? 1 : 0;
    // 0x800A6BF4: bne         $at, $zero, L_800A6C20
    if (ctx->r1 != 0) {
        // 0x800A6BF8: nop
    
            goto L_800A6C20;
    }
    // 0x800A6BF8: nop

    // 0x800A6BFC: sb          $t7, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r15;
    // 0x800A6C00: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6C04: nop

    // 0x800A6C08: lb          $t8, 0x5FC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A6C0C: nop

    // 0x800A6C10: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800A6C14: sb          $t9, 0x5FC($v0)
    MEM_B(0X5FC, ctx->r2) = ctx->r25;
    // 0x800A6C18: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6C1C: nop

L_800A6C20:
    // 0x800A6C20: lb          $t2, 0x5FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A6C24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6C28: bne         $a2, $t2, L_800A6C94
    if (ctx->r6 != ctx->r10) {
        // 0x800A6C2C: nop
    
            goto L_800A6C94;
    }
    // 0x800A6C2C: nop

    // 0x800A6C30: lbu         $t3, 0x6D37($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6D37);
    // 0x800A6C34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A6C38: beq         $t0, $t3, L_800A6C68
    if (ctx->r8 == ctx->r11) {
        // 0x800A6C3C: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_800A6C68;
    }
    // 0x800A6C3C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800A6C40: jal         0x8009EC80
    // 0x800A6C44: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_in_two_player_adventure(rdram, ctx);
        goto after_14;
    // 0x800A6C44: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_14:
    // 0x800A6C48: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6C4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6C50: beq         $v0, $zero, L_800A6C88
    if (ctx->r2 == 0) {
        // 0x800A6C54: addiu       $t1, $t1, 0x6CDC
        ctx->r9 = ADD32(ctx->r9, 0X6CDC);
            goto L_800A6C88;
    }
    // 0x800A6C54: addiu       $t1, $t1, 0x6CDC
    ctx->r9 = ADD32(ctx->r9, 0X6CDC);
    // 0x800A6C58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6C5C: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A6C60: nop

    // 0x800A6C64: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_800A6C68:
    // 0x800A6C68: sb          $t4, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r12;
    // 0x800A6C6C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A6C70: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6C74: jal         0x80001D04
    // 0x800A6C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A6C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A6C7C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6C80: b           L_800A6C94
    // 0x800A6C84: nop

        goto L_800A6C94;
    // 0x800A6C84: nop

L_800A6C88:
    // 0x800A6C88: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6C8C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800A6C90: sb          $t5, 0x5FA($t6)
    MEM_B(0X5FA, ctx->r14) = ctx->r13;
L_800A6C94:
    // 0x800A6C94: jal         0x800A5F18
    // 0x800A6C98: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_16;
    // 0x800A6C98: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x800A6C9C: b           L_800A6DA8
    // 0x800A6CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6DA8;
    // 0x800A6CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6CA4:
    // 0x800A6CA4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6CA8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A6CAC: bne         $t7, $at, L_800A6CBC
    if (ctx->r15 != ctx->r1) {
        // 0x800A6CB0: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_800A6CBC;
    }
    // 0x800A6CB0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800A6CB4: b           L_800A6D58
    // 0x800A6CB8: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
        goto L_800A6D58;
    // 0x800A6CB8: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
L_800A6CBC:
    // 0x800A6CBC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800A6CC0: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A6CC4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A6CC8: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800A6CCC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A6CD0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800A6CD4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800A6CD8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A6CDC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6CE0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800A6CE4: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A6CE8: swc1        $f4, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f4.u32l;
    // 0x800A6CEC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6CF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6CF4: lwc1        $f6, 0x60C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A6CF8: nop

    // 0x800A6CFC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A6D00: swc1        $f8, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6D04: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D08: nop

    // 0x800A6D0C: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A6D10: nop

    // 0x800A6D14: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800A6D18: nop

    // 0x800A6D1C: bc1f        L_800A6D30
    if (!c1cs) {
        // 0x800A6D20: nop
    
            goto L_800A6D30;
    }
    // 0x800A6D20: nop

    // 0x800A6D24: sb          $t3, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r11;
    // 0x800A6D28: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D2C: nop

L_800A6D30:
    // 0x800A6D30: lwc1        $f6, 0x16C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6D34: nop

    // 0x800A6D38: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A6D3C: swc1        $f8, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f8.u32l;
    // 0x800A6D40: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D44: nop

    // 0x800A6D48: lwc1        $f10, 0x2EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6D4C: nop

    // 0x800A6D50: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A6D54: swc1        $f4, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f4.u32l;
L_800A6D58:
    // 0x800A6D58: jal         0x800A5F18
    // 0x800A6D5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_17;
    // 0x800A6D5C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_17:
    // 0x800A6D60: b           L_800A6DA8
    // 0x800A6D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6DA8;
    // 0x800A6D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6D68:
    // 0x800A6D68: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A6D6C: lb          $t5, 0xC($v1)
    ctx->r13 = MEM_B(ctx->r3, 0XC);
    // 0x800A6D70: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800A6D74: bne         $t4, $t5, L_800A6D84
    if (ctx->r12 != ctx->r13) {
        // 0x800A6D78: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A6D84;
    }
    // 0x800A6D78: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A6D7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A6D80: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_800A6D84:
    // 0x800A6D84: sb          $t7, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r15;
    // 0x800A6D88: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D8C: jal         0x800A5F18
    // 0x800A6D90: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    hud_finish_position(rdram, ctx);
        goto after_18;
    // 0x800A6D90: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    after_18:
    // 0x800A6D94: b           L_800A6DA8
    // 0x800A6D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6DA8;
    // 0x800A6D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6D9C:
    // 0x800A6D9C: jal         0x800A5F18
    // 0x800A6DA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_19;
    // 0x800A6DA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
L_800A6DA4:
    // 0x800A6DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6DA8:
    // 0x800A6DA8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800A6DAC: jr          $ra
    // 0x800A6DB0: nop

    return;
    // 0x800A6DB0: nop

;}
RECOMP_FUNC void trackbg_render_gradient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800289B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800289BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800289C0: lw          $v0, -0x36E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E4);
    // 0x800289C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800289C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800289CC: lbu         $t6, 0xC1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC1);
    // 0x800289D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800289D4: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    // 0x800289D8: lbu         $t7, 0xC2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC2);
    // 0x800289DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800289E0: sb          $t7, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r15;
    // 0x800289E4: lbu         $t8, 0xC3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC3);
    // 0x800289E8: lw          $v1, -0x4F58($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F58);
    // 0x800289EC: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x800289F0: lbu         $t9, 0xBE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XBE);
    // 0x800289F4: lw          $a3, -0x4F54($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4F54);
    // 0x800289F8: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
    // 0x800289FC: lbu         $t6, 0xBF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XBF);
    // 0x80028A00: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80028A04: sb          $t6, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r14;
    // 0x80028A08: lbu         $t7, 0xC0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC0);
    // 0x80028A0C: addiu       $s0, $s0, -0x4F60
    ctx->r16 = ADD32(ctx->r16, -0X4F60);
    // 0x80028A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A14: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028A18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80028A1C: jal         0x8007B3D0
    // 0x80028A20: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80028A20: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80028A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028A2C: jal         0x8007B4C8
    // 0x80028A30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x80028A30: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80028A34: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028A38: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80028A3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028A40: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x80028A44: andi        $t9, $a1, 0x6
    ctx->r25 = ctx->r5 & 0X6;
    // 0x80028A48: ori         $t6, $t9, 0x18
    ctx->r14 = ctx->r25 | 0X18;
    // 0x80028A4C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028A50: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80028A54: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80028A58: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028A5C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028A60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028A64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80028A68: ori         $t6, $t9, 0x50
    ctx->r14 = ctx->r25 | 0X50;
    // 0x80028A6C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028A70: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80028A74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028A78: lui         $t8, 0x510
    ctx->r24 = S32(0X510 << 16);
    // 0x80028A7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028A80: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80028A84: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x80028A88: addu        $t9, $a3, $t0
    ctx->r25 = ADD32(ctx->r7, ctx->r8);
    // 0x80028A8C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80028A90: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028A94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028A98: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80028A9C: addiu       $s0, $zero, -0x96
    ctx->r16 = ADD32(0, -0X96);
    // 0x80028AA0: bne         $t6, $zero, L_80028AB4
    if (ctx->r14 != 0) {
        // 0x80028AA4: addiu       $a0, $zero, 0x96
        ctx->r4 = ADD32(0, 0X96);
            goto L_80028AB4;
    }
    // 0x80028AA4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80028AA8: addiu       $s0, $zero, -0xB4
    ctx->r16 = ADD32(0, -0XB4);
    // 0x80028AAC: b           L_80028AB4
    // 0x80028AB0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
        goto L_80028AB4;
    // 0x80028AB0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
L_80028AB4:
    // 0x80028AB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028AB8: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    // 0x80028ABC: jal         0x80066210
    // 0x80028AC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80028AC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80028AC4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028AC8: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    // 0x80028ACC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80028AD4: bne         $v0, $at, L_80028AF4
    if (ctx->r2 != ctx->r1) {
        // 0x80028AD8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80028AF4;
    }
    // 0x80028AD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80028ADC: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80028AE0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028AE4: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80028AE8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80028AEC: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80028AF0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
L_80028AF4:
    // 0x80028AF4: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80028AF8: lbu         $t2, 0x2E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2E);
    // 0x80028AFC: lbu         $t3, 0x2D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028B00: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80028B04: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x80028B08: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80028B0C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80028B10: sh          $s0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r16;
    // 0x80028B14: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x80028B18: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80028B1C: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x80028B20: sh          $s0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r16;
    // 0x80028B24: sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // 0x80028B28: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    // 0x80028B2C: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x80028B30: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x80028B34: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x80028B38: lbu         $ra, 0x2A($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X2A);
    // 0x80028B3C: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80028B40: lbu         $t4, 0x2C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2C);
    // 0x80028B44: sh          $a2, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r6;
    // 0x80028B48: sh          $t0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r8;
    // 0x80028B4C: sb          $a1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r5;
    // 0x80028B50: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x80028B54: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80028B58: sb          $a1, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r5;
    // 0x80028B5C: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x80028B60: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80028B64: sb          $a1, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r5;
    // 0x80028B68: sb          $t2, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r10;
    // 0x80028B6C: sb          $t3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r11;
    // 0x80028B70: sb          $ra, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r31;
    // 0x80028B74: sb          $ra, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r31;
    // 0x80028B78: sb          $t5, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r13;
    // 0x80028B7C: sb          $t5, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r13;
    // 0x80028B80: sb          $t4, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r12;
    // 0x80028B84: sb          $t4, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r12;
    // 0x80028B88: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80028B8C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80028B90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80028B94: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80028B98: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80028B9C: sb          $t0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r8;
    // 0x80028BA0: sb          $t1, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r9;
    // 0x80028BA4: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x80028BA8: sh          $zero, 0x4($a3)
    MEM_H(0X4, ctx->r7) = 0;
    // 0x80028BAC: sh          $zero, 0x6($a3)
    MEM_H(0X6, ctx->r7) = 0;
    // 0x80028BB0: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x80028BB4: sh          $zero, 0xA($a3)
    MEM_H(0XA, ctx->r7) = 0;
    // 0x80028BB8: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x80028BBC: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x80028BC0: sb          $a2, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r6;
    // 0x80028BC4: sb          $t9, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r25;
    // 0x80028BC8: sb          $t0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r8;
    // 0x80028BCC: sb          $t1, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r9;
    // 0x80028BD0: sh          $zero, 0x14($a3)
    MEM_H(0X14, ctx->r7) = 0;
    // 0x80028BD4: sh          $zero, 0x16($a3)
    MEM_H(0X16, ctx->r7) = 0;
    // 0x80028BD8: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x80028BDC: sh          $zero, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = 0;
    // 0x80028BE0: sh          $zero, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = 0;
    // 0x80028BE4: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    extern void dkr_widen_gradient_sky(uint8_t*, recomp_context*); dkr_widen_gradient_sky(rdram, ctx);
    // 0x80028BE8: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x80028BEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028BF4: sw          $v1, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r3;
    // 0x80028BF8: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80028BFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028C04: sw          $a3, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = ctx->r7;
    // 0x80028C08: jr          $ra
    // 0x80028C0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80028C0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_loop_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035260: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80035264: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80035268: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8003526C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035270: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80035274: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80035278: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003527C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80035280: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x80035284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035288: bne         $t6, $zero, L_800352A8
    if (ctx->r14 != 0) {
        // 0x8003528C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800352A8;
    }
    // 0x8003528C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035290: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035294: lwc1        $f9, 0x6010($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6010);
    // 0x80035298: lwc1        $f8, 0x6014($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6014);
    // 0x8003529C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800352A0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800352A4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800352A8:
    // 0x800352A8: lb          $v0, 0xB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB);
    // 0x800352AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800352B0: beq         $v0, $zero, L_800352DC
    if (ctx->r2 == 0) {
        // 0x800352B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800352DC;
    }
    // 0x800352B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800352B8: beq         $v0, $at, L_800352EC
    if (ctx->r2 == ctx->r1) {
        // 0x800352BC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800352EC;
    }
    // 0x800352BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800352C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800352C4: beq         $v0, $at, L_8003553C
    if (ctx->r2 == ctx->r1) {
        // 0x800352C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8003553C;
    }
    // 0x800352C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800352CC: beq         $v0, $at, L_800355F4
    if (ctx->r2 == ctx->r1) {
        // 0x800352D0: nop
    
            goto L_800355F4;
    }
    // 0x800352D0: nop

    // 0x800352D4: b           L_80035630
    // 0x800352D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035630;
    // 0x800352D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800352DC:
    // 0x800352DC: jal         0x80036040
    // 0x800352E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    try_to_collect_egg(rdram, ctx);
        goto after_0;
    // 0x800352E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800352E4: b           L_80035630
    // 0x800352E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035630;
    // 0x800352E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800352EC:
    // 0x800352EC: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800352F0: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800352F4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800352F8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800352FC: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x80035300: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80035304: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80035308: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003530C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80035310: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035314: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80035318: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003531C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80035320: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80035324: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80035328: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003532C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80035330: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80035334: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035338: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003533C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80035340: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80035344: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80035348: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8003534C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80035350: jal         0x80031130
    // 0x80035354: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_1;
    // 0x80035354: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80035358: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003535C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80035360: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80035364: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80035368: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x8003536C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80035370: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80035374: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80035378: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8003537C: jal         0x80031600
    // 0x80035380: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    resolve_collisions(rdram, ctx);
        goto after_2;
    // 0x80035380: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    after_2:
    // 0x80035384: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035388: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003538C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80035390: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80035394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035398: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003539C: lwc1        $f3, 0x6018($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6018);
    // 0x800353A0: lwc1        $f2, 0x601C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X601C);
    // 0x800353A4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800353A8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800353AC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800353B0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800353B4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800353B8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800353BC: nop

    // 0x800353C0: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800353C4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800353C8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800353CC: nop

    // 0x800353D0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800353D4: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800353D8: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800353DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800353E0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800353E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800353E8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x800353EC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800353F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800353F4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800353F8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800353FC: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x80035400: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80035404: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80035408: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003540C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80035410: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80035414: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035418: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003541C: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80035420: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80035424: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80035428: mul.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8003542C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80035430: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035434: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80035438: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003543C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80035440: lwc1        $f16, 0x6024($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6024);
    // 0x80035444: lwc1        $f17, 0x6020($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6020);
    // 0x80035448: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8003544C: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80035450: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80035454: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035458: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003545C: nop

    // 0x80035460: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80035464: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80035468: bc1t        L_80035490
    if (c1cs) {
        // 0x8003546C: swc1        $f4, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
            goto L_80035490;
    }
    // 0x8003546C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80035470: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80035474: lb          $t2, 0x33($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X33);
    // 0x80035478: beq         $t1, $zero, L_800354AC
    if (ctx->r9 == 0) {
        // 0x8003547C: slti        $at, $t2, 0x5
        ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
            goto L_800354AC;
    }
    // 0x8003547C: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80035480: bne         $at, $zero, L_80035490
    if (ctx->r1 != 0) {
        // 0x80035484: slti        $at, $t2, 0xA
        ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
            goto L_80035490;
    }
    // 0x80035484: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80035488: bne         $at, $zero, L_800354B0
    if (ctx->r1 != 0) {
        // 0x8003548C: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800354B0;
    }
    // 0x8003548C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80035490:
    // 0x80035490: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80035494: nop

    // 0x80035498: beq         $v0, $zero, L_800354A4
    if (ctx->r2 == 0) {
        // 0x8003549C: nop
    
            goto L_800354A4;
    }
    // 0x8003549C: nop

    // 0x800354A0: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_800354A4:
    // 0x800354A4: jal         0x8000FFB8
    // 0x800354A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800354A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800354AC:
    // 0x800354AC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800354B0:
    // 0x800354B0: lb          $t4, 0x33($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X33);
    // 0x800354B4: beq         $t3, $zero, L_800354D4
    if (ctx->r11 == 0) {
        // 0x800354B8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800354D4;
    }
    // 0x800354B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800354BC: bne         $t4, $at, L_800354D8
    if (ctx->r12 != ctx->r1) {
        // 0x800354C0: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_800354D8;
    }
    // 0x800354C0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800354C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800354C8: sb          $zero, 0xB($s1)
    MEM_B(0XB, ctx->r17) = 0;
    // 0x800354CC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800354D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_800354D4:
    // 0x800354D4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_800354D8:
    // 0x800354D8: lb          $t6, 0x33($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X33);
    // 0x800354DC: beq         $t5, $zero, L_8003562C
    if (ctx->r13 == 0) {
        // 0x800354E0: slti        $at, $t6, 0x6
        ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
            goto L_8003562C;
    }
    // 0x800354E0: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x800354E4: bne         $at, $zero, L_8003562C
    if (ctx->r1 != 0) {
        // 0x800354E8: slti        $at, $t6, 0xA
        ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
            goto L_8003562C;
    }
    // 0x800354E8: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x800354EC: beq         $at, $zero, L_8003562C
    if (ctx->r1 == 0) {
        // 0x800354F0: addiu       $t7, $t6, -0x6
        ctx->r15 = ADD32(ctx->r14, -0X6);
            goto L_8003562C;
    }
    // 0x800354F0: addiu       $t7, $t6, -0x6
    ctx->r15 = ADD32(ctx->r14, -0X6);
    // 0x800354F4: sb          $t7, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r15;
    // 0x800354F8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800354FC: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035500: jal         0x8001BAC8
    // 0x80035504: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    get_racer_object(rdram, ctx);
        goto after_4;
    // 0x80035504: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    after_4:
    // 0x80035508: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003550C: beq         $v0, $zero, L_8003552C
    if (ctx->r2 == 0) {
        // 0x80035510: addiu       $t1, $zero, 0x258
        ctx->r9 = ADD32(0, 0X258);
            goto L_8003552C;
    }
    // 0x80035510: addiu       $t1, $zero, 0x258
    ctx->r9 = ADD32(0, 0X258);
    // 0x80035514: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x80035518: nop

    // 0x8003551C: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x80035520: nop

    // 0x80035524: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80035528: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_8003552C:
    // 0x8003552C: sh          $t1, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r9;
    // 0x80035530: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80035534: b           L_8003562C
    // 0x80035538: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8003562C;
    // 0x80035538: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003553C:
    // 0x8003553C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x80035540: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035544: subu        $t3, $t2, $a1
    ctx->r11 = SUB32(ctx->r10, ctx->r5);
    // 0x80035548: jal         0x8001BAC8
    // 0x8003554C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003554C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    after_5:
    // 0x80035550: beq         $v0, $zero, L_80035564
    if (ctx->r2 == 0) {
        // 0x80035554: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80035564;
    }
    // 0x80035554: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80035558: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003555C: nop

    // 0x80035560: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
L_80035564:
    // 0x80035564: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x80035568: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8003556C: bgtz        $v1, L_800355A0
    if (SIGNED(ctx->r3) > 0) {
        // 0x80035570: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_800355A0;
    }
    // 0x80035570: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80035574: beq         $v0, $zero, L_8003558C
    if (ctx->r2 == 0) {
        // 0x80035578: nop
    
            goto L_8003558C;
    }
    // 0x80035578: nop

    // 0x8003557C: lb          $t4, 0x193($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X193);
    // 0x80035580: nop

    // 0x80035584: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80035588: sb          $t5, 0x193($a2)
    MEM_B(0X193, ctx->r6) = ctx->r13;
L_8003558C:
    // 0x8003558C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80035590: sb          $t6, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r14;
    // 0x80035594: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x80035598: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x8003559C: nop

L_800355A0:
    // 0x800355A0: slti        $at, $v1, 0x21C
    ctx->r1 = SIGNED(ctx->r3) < 0X21C ? 1 : 0;
    // 0x800355A4: beq         $at, $zero, L_800355C8
    if (ctx->r1 == 0) {
        // 0x800355A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800355C8;
    }
    // 0x800355A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800355AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800355B0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x800355B4: jal         0x80036040
    // 0x800355B8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    try_to_collect_egg(rdram, ctx);
        goto after_6;
    // 0x800355B8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_6:
    // 0x800355BC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800355C0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800355C4: nop

L_800355C8:
    // 0x800355C8: beq         $a3, $zero, L_80035630
    if (ctx->r7 == 0) {
        // 0x800355CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035630;
    }
    // 0x800355CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800355D0: lb          $t8, 0xB($s1)
    ctx->r24 = MEM_B(ctx->r17, 0XB);
    // 0x800355D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800355D8: beq         $t8, $at, L_80035630
    if (ctx->r24 == ctx->r1) {
        // 0x800355DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035630;
    }
    // 0x800355DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800355E0: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x800355E4: nop

    // 0x800355E8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800355EC: b           L_8003562C
    // 0x800355F0: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
        goto L_8003562C;
    // 0x800355F0: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_800355F4:
    // 0x800355F4: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x800355F8: jal         0x8001BAC8
    // 0x800355FC: nop

    get_racer_object(rdram, ctx);
        goto after_7;
    // 0x800355FC: nop

    after_7:
    // 0x80035600: beq         $v0, $zero, L_80035628
    if (ctx->r2 == 0) {
        // 0x80035604: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_80035628;
    }
    // 0x80035604: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80035608: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003560C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80035610: lb          $t1, 0x193($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X193);
    // 0x80035614: nop

    // 0x80035618: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8003561C: bne         $at, $zero, L_80035628
    if (ctx->r1 != 0) {
        // 0x80035620: nop
    
            goto L_80035628;
    }
    // 0x80035620: nop

    // 0x80035624: sb          $t2, 0x1D8($a2)
    MEM_B(0X1D8, ctx->r6) = ctx->r10;
L_80035628:
    // 0x80035628: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_8003562C:
    // 0x8003562C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80035630:
    // 0x80035630: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80035634: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80035638: jr          $ra
    // 0x8003563C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8003563C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A9F8: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x8000A9FC: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8000AA00: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8000AA04: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA08: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AA0C: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x8000AA10: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000AA14: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000AA18: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x8000AA1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000AA20: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000AA24: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x8000AA28: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x8000AA2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA30: nop

    // 0x8000AA34: nop

    // 0x8000AA38: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA3C: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x8000AA40: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA44: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x8000AA48: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000AA4C: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA50: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA54: nop

    // 0x8000AA58: nop

    // 0x8000AA5C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA60: mflo        $a2
    ctx->r6 = lo;
    // 0x8000AA64: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x8000AA68: nop

    // 0x8000AA6C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA70: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA74: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x8000AA78: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8000AA7C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000AA80: jr          $ra
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void apply_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003093C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80030940: addiu       $t1, $t1, -0x4F60
    ctx->r9 = ADD32(ctx->r9, -0X4F60);
    // 0x80030944: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80030948: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8003094C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80030950: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80030954: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80030958: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8003095C: addiu       $t9, $t9, -0x2C78
    ctx->r25 = ADD32(ctx->r25, -0X2C78);
    // 0x80030960: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80030964: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x80030968: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8003096C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80030970: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80030974: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80030978: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8003097C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80030980: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x80030984: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80030988: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003098C: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80030990: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80030994: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80030998: or          $t2, $t5, $t9
    ctx->r10 = ctx->r13 | ctx->r25;
    // 0x8003099C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800309A0: or          $t8, $t2, $t7
    ctx->r24 = ctx->r10 | ctx->r15;
    // 0x800309A4: ori         $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 | 0XFF;
    // 0x800309A8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800309AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800309B0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800309B4: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800309B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800309BC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800309C0: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x800309C4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800309C8: lw          $a3, 0xC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0XC);
    // 0x800309CC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x800309D0: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800309D4: negu        $t7, $t4
    ctx->r15 = SUB32(0, ctx->r12);
    // 0x800309D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800309DC: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800309E0: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800309E4: sra         $t2, $t6, 16
    ctx->r10 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800309E8: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x800309EC: addu        $t5, $t8, $at
    ctx->r13 = ADD32(ctx->r24, ctx->r1);
    // 0x800309F0: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x800309F4: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x800309F8: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x800309FC: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x80030A00: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80030A04: bne         $t0, $zero, L_80030A10
    if (ctx->r8 != 0) {
        // 0x80030A08: nop
    
            goto L_80030A10;
    }
    // 0x80030A08: nop

    // 0x80030A0C: break       7
    do_break(2147682828);
L_80030A10:
    // 0x80030A10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A14: bne         $t0, $at, L_80030A28
    if (ctx->r8 != ctx->r1) {
        // 0x80030A18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A28;
    }
    // 0x80030A18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A1C: bne         $t5, $at, L_80030A28
    if (ctx->r13 != ctx->r1) {
        // 0x80030A20: nop
    
            goto L_80030A28;
    }
    // 0x80030A20: nop

    // 0x80030A24: break       6
    do_break(2147682852);
L_80030A28:
    // 0x80030A28: mflo        $t9
    ctx->r25 = lo;
    // 0x80030A2C: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80030A30: nop

    // 0x80030A34: div         $zero, $t4, $t0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r8)));
    // 0x80030A38: bne         $t0, $zero, L_80030A44
    if (ctx->r8 != 0) {
        // 0x80030A3C: nop
    
            goto L_80030A44;
    }
    // 0x80030A3C: nop

    // 0x80030A40: break       7
    do_break(2147682880);
L_80030A44:
    // 0x80030A44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A48: bne         $t0, $at, L_80030A5C
    if (ctx->r8 != ctx->r1) {
        // 0x80030A4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A5C;
    }
    // 0x80030A4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A50: bne         $t4, $at, L_80030A5C
    if (ctx->r12 != ctx->r1) {
        // 0x80030A54: nop
    
            goto L_80030A5C;
    }
    // 0x80030A54: nop

    // 0x80030A58: break       6
    do_break(2147682904);
L_80030A5C:
    // 0x80030A5C: mflo        $t6
    ctx->r14 = lo;
    // 0x80030A60: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80030A64: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x80030A68: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80030A6C: jr          $ra
    // 0x80030A70: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    return;
    // 0x80030A70: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ADF4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8000ADF8: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADFC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000AE00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AE04: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000AE08: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x8000AE0C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE10: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8000AE14: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE18: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x8000AE1C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE20: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8000AE24: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE28: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x8000AE2C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE30: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8000AE34: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE38: sb          $v1, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r3;
    // 0x8000AE3C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE40: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8000AE44: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE48: sb          $v1, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r3;
    // 0x8000AE4C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AE54: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE58: sb          $t7, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r15;
    // 0x8000AE5C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000AE64: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE68: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
    // 0x8000AE6C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE70: nop

    // 0x8000AE74: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE78: sh          $t2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r10;
    // 0x8000AE7C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE80: nop

    // 0x8000AE84: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE88: jr          $ra
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void reset_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C50D8: blez        $a0, L_800C5104
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C50DC: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5104;
    }
    // 0x800C50DC: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C50E0: beq         $at, $zero, L_800C5104
    if (ctx->r1 == 0) {
        // 0x800C50E4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5104;
    }
    // 0x800C50E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C50E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C50EC: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C50F0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C50F4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C50F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C50FC: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x800C5100: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
L_800C5104:
    // 0x800C5104: jr          $ra
    // 0x800C5108: nop

    return;
    // 0x800C5108: nop

;}
RECOMP_FUNC void init_line_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEF88: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AEF8C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AEF90: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AEF94: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x800AEF98: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AEF9C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AEFA0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800AEFA4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800AEFA8: nop

    // 0x800AEFAC: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800AEFB0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AEFB4: nop

    // 0x800AEFB8: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // 0x800AEFBC: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x800AEFC0: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x800AEFC4: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x800AEFC8: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x800AEFCC: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x800AEFD0: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    // 0x800AEFD4: sb          $v1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r3;
    // 0x800AEFD8: sb          $v1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r3;
    // 0x800AEFDC: sb          $v1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r3;
    // 0x800AEFE0: sb          $v1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r3;
    // 0x800AEFE4: sb          $v1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r3;
    // 0x800AEFE8: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x800AEFEC: sb          $v1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r3;
    // 0x800AEFF0: sb          $v1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r3;
    // 0x800AEFF4: sb          $v1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r3;
    // 0x800AEFF8: sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
    // 0x800AEFFC: sb          $v1, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r3;
    // 0x800AF000: sb          $v1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r3;
    // 0x800AF004: sb          $v1, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r3;
    // 0x800AF008: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800AF00C: sb          $v1, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r3;
    // 0x800AF010: sb          $v1, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r3;
    // 0x800AF014: sb          $v1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r3;
    // 0x800AF018: sb          $v1, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r3;
    // 0x800AF01C: jr          $ra
    // 0x800AF020: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF020: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void coss_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007082C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80070830: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070834: bgezl       $v0, L_80070844
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070838: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_80070844;
    }
    goto skip_0;
    // 0x80070838: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x8007083C: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x80070840: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_80070844:
    // 0x80070844: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070848: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x8007084C: addiu       $v0, $v0, -0x2BC4
    ctx->r2 = ADD32(ctx->r2, -0X2BC4);
    // 0x80070850: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070854: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x80070858: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8007085C: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x80070860: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070864: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80070868: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007086C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80070870: mflo        $t2
    ctx->r10 = lo;
    // 0x80070874: srl         $t2, $t2, 3
    ctx->r10 = S32(U32(ctx->r10) >> 3);
    // 0x80070878: bgez        $a0, L_80070884
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007087C: addu        $v0, $v0, $t2
        ctx->r2 = ADD32(ctx->r2, ctx->r10);
            goto L_80070884;
    }
    // 0x8007087C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070880: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80070884:
    // 0x80070884: jr          $ra
    // 0x80070888: nop

    return;
    // 0x80070888: nop

;}
RECOMP_FUNC void hud_finish_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5F18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A5F1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5F20: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A5F24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A5F28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A5F2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F34: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F38: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5F3C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5F40: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5F44: jal         0x800AA600
    // 0x800A5F48: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A5F48: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    after_0:
    // 0x800A5F4C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5F50: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A5F54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5F58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5F5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5F60: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5F64: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5F68: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5F6C: jal         0x800AA600
    // 0x800A5F70: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A5F70: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    after_1:
    // 0x800A5F74: jal         0x8006BD98
    // 0x800A5F78: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x800A5F78: nop

    after_2:
    // 0x800A5F7C: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x800A5F80: bne         $t6, $zero, L_800A6248
    if (ctx->r14 != 0) {
        // 0x800A5F84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6248;
    }
    // 0x800A5F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5F88: jal         0x8009EC80
    // 0x800A5F8C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_3;
    // 0x800A5F8C: nop

    after_3:
    // 0x800A5F90: bne         $v0, $zero, L_800A6248
    if (ctx->r2 != 0) {
        // 0x800A5F94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6248;
    }
    // 0x800A5F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5F98: jal         0x8001BA74
    // 0x800A5F9C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    get_racer_objects(rdram, ctx);
        goto after_4;
    // 0x800A5F9C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800A5FA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A5FA4: lbu         $t7, 0x6D37($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6D37);
    // 0x800A5FA8: nop

    // 0x800A5FAC: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A5FB0: bne         $at, $zero, L_800A6248
    if (ctx->r1 != 0) {
        // 0x800A5FB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6248;
    }
    // 0x800A5FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5FB8: jal         0x8009EC80
    // 0x800A5FBC: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x800A5FBC: nop

    after_5:
    // 0x800A5FC0: beq         $v0, $zero, L_800A5FD8
    if (ctx->r2 == 0) {
        // 0x800A5FC4: nop
    
            goto L_800A5FD8;
    }
    // 0x800A5FC4: nop

    // 0x800A5FC8: jal         0x8006EAB0
    // 0x800A5FCC: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_6;
    // 0x800A5FCC: nop

    after_6:
    // 0x800A5FD0: bne         $v0, $zero, L_800A6248
    if (ctx->r2 != 0) {
        // 0x800A5FD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6248;
    }
    // 0x800A5FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A5FD8:
    // 0x800A5FD8: jal         0x800C42EC
    // 0x800A5FDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x800A5FDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A5FE0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A5FE4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A5FE8: lh          $t0, 0x1AC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1AC);
    // 0x800A5FEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5FF0: beq         $t8, $t0, L_800A61D4
    if (ctx->r24 == ctx->r8) {
        // 0x800A5FF4: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_800A61D4;
    }
    // 0x800A5FF4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A5FF8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A5FFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A6000: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800A6004: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800A6008: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A600C: jal         0x800C4384
    // 0x800A6010: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x800A6010: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800A6014: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6018: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A601C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A6020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6024: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6028: lwc1        $f16, 0x170($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A602C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A6030: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6034: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A6038: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A603C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A6040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6048: addiu       $a3, $a3, -0x7978
    ctx->r7 = ADD32(ctx->r7, -0X7978);
    // 0x800A604C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6050: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A6054: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A6058: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A605C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6060: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A6064: nop

    // 0x800A6068: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A606C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6070: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6074: nop

    // 0x800A6078: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A607C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A6080: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A6084: jal         0x800C4440
    // 0x800A6088: nop

    draw_text(rdram, ctx);
        goto after_9;
    // 0x800A6088: nop

    after_9:
    // 0x800A608C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A6090: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6094: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A6098: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A609C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A60A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A60A4: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A60A8: lwc1        $f8, 0x170($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A60AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A60B0: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x800A60B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A60B8: lb          $a2, 0x17A($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X17A);
    // 0x800A60BC: lb          $a3, 0x17B($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17B);
    // 0x800A60C0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A60C4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A60C8: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A60CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A60D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A60D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A60D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A60DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A60E0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A60E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    extern void dkr_hud_timer_select(uint8_t*, recomp_context*, int); dkr_hud_timer_select(rdram, ctx, 2);
    // 0x800A60E8: jal         0x800A7FBC
    // 0x800A60EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_10;
    // 0x800A60EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_10:
    // 0x800A60F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A60F4: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A60F8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A60FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6100: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6104: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6108: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A610C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6110: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A6114: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A6118: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A611C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6120: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6124: addiu       $a3, $a3, -0x7970
    ctx->r7 = ADD32(ctx->r7, -0X7970);
    // 0x800A6128: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A612C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A6130: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A6134: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6138: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A613C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6140: nop

    // 0x800A6144: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6148: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A614C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6150: nop

    // 0x800A6154: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6158: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800A615C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6160: jal         0x800C4440
    // 0x800A6164: nop

    draw_text(rdram, ctx);
        goto after_11;
    // 0x800A6164: nop

    after_11:
    // 0x800A6168: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A616C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6170: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A6174: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A6178: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A617C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6180: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6184: lwc1        $f4, 0x2F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6188: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A618C: lb          $t2, 0x2FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X2FC);
    // 0x800A6190: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A6194: lb          $a2, 0x2FA($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2FA);
    // 0x800A6198: lb          $a3, 0x2FB($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X2FB);
    // 0x800A619C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A61A0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A61A4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A61A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A61AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A61B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A61B4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A61B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A61BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A61C0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    extern void dkr_hud_timer_select(uint8_t*, recomp_context*, int); dkr_hud_timer_select(rdram, ctx, 2);
    // 0x800A61C4: jal         0x800A7FBC
    // 0x800A61C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    hud_timer_render(rdram, ctx);
        goto after_12;
    // 0x800A61C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_12:
    // 0x800A61CC: b           L_800A6248
    // 0x800A61D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A6248;
    // 0x800A61D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A61D4:
    // 0x800A61D4: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A61D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A61DC: lwc1        $f8, 0x16C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A61E0: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A61E4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A61E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A61EC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A61F0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A61F4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A61F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A61FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6200: addiu       $a3, $a3, -0x796C
    ctx->r7 = ADD32(ctx->r7, -0X796C);
    // 0x800A6204: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A6208: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A620C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6210: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A6214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6218: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A621C: nop

    // 0x800A6220: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A6224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A622C: nop

    // 0x800A6230: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6234: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800A6238: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A623C: jal         0x800C4440
    // 0x800A6240: nop

    draw_text(rdram, ctx);
        goto after_13;
    // 0x800A6240: nop

    after_13:
    // 0x800A6244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6248:
    // 0x800A6248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A624C: jr          $ra
    // 0x800A6250: nop

    return;
    // 0x800A6250: nop

;}
RECOMP_FUNC void menu_asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C6D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009C6D8: addiu       $t0, $t0, -0x8B0
    ctx->r8 = ADD32(ctx->r8, -0X8B0);
    // 0x8009C6DC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8009C6E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009C6E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C6E8: bne         $a2, $zero, L_8009C784
    if (ctx->r6 != 0) {
        // 0x8009C6EC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8009C784;
    }
    // 0x8009C6EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009C6F0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8009C6F4: jal         0x80076C58
    // 0x8009C6F8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8009C6F8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8009C6FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009C700: addiu       $a1, $a1, -0x8AC
    ctx->r5 = ADD32(ctx->r5, -0X8AC);
    // 0x8009C704: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8009C708: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009C70C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009C710: addiu       $t0, $t0, -0x8B0
    ctx->r8 = ADD32(ctx->r8, -0X8B0);
    // 0x8009C714: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8009C718: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8009C71C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009C720: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009C724: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009C728: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009C72C: beq         $a0, $t8, L_8009C75C
    if (ctx->r4 == ctx->r24) {
        // 0x8009C730: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8009C75C;
    }
    // 0x8009C730: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8009C734: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009C738:
    // 0x8009C738: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8009C73C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009C740: nop

    // 0x8009C744: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8009C748: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8009C74C: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8009C750: nop

    // 0x8009C754: bne         $a0, $t3, L_8009C738
    if (ctx->r4 != ctx->r11) {
        // 0x8009C758: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8009C738;
    }
    // 0x8009C758: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009C75C:
    // 0x8009C75C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C760: blez        $v1, L_8009C784
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009C764: sh          $zero, -0x8A8($at)
        MEM_H(-0X8A8, ctx->r1) = 0;
            goto L_8009C784;
    }
    // 0x8009C764: sh          $zero, -0x8A8($at)
    MEM_H(-0X8A8, ctx->r1) = 0;
    // 0x8009C768: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009C76C: addiu       $v0, $t4, 0x6750
    ctx->r2 = ADD32(ctx->r12, 0X6750);
    // 0x8009C770: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8009C774:
    // 0x8009C774: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009C778: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8009C77C: bne         $at, $zero, L_8009C774
    if (ctx->r1 != 0) {
        // 0x8009C780: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8009C774;
    }
    // 0x8009C780: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
L_8009C784:
    // 0x8009C784: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009C788: addiu       $t5, $t5, 0x6750
    ctx->r13 = ADD32(ctx->r13, 0X6750);
    // 0x8009C78C: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x8009C790: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8009C794: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8009C798: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8009C79C: bne         $t8, $zero, L_8009C894
    if (ctx->r24 != 0) {
        // 0x8009C7A0: addu        $t1, $a2, $t9
        ctx->r9 = ADD32(ctx->r6, ctx->r25);
            goto L_8009C894;
    }
    // 0x8009C7A0: addu        $t1, $a2, $t9
    ctx->r9 = ADD32(ctx->r6, ctx->r25);
    // 0x8009C7A4: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009C7A8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009C7AC: andi        $t2, $v0, 0xC000
    ctx->r10 = ctx->r2 & 0XC000;
    // 0x8009C7B0: bne         $t2, $at, L_8009C7DC
    if (ctx->r10 != ctx->r1) {
        // 0x8009C7B4: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_8009C7DC;
    }
    // 0x8009C7B4: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x8009C7B8: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009C7BC: jal         0x8007AE74
    // 0x8009C7C0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8009C7C0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8009C7C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009C7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C7CC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8009C7D0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8009C7D4: b           L_8009C874
    // 0x8009C7D8: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
        goto L_8009C874;
    // 0x8009C7D8: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
L_8009C7DC:
    // 0x8009C7DC: beq         $t4, $zero, L_8009C80C
    if (ctx->r12 == 0) {
        // 0x8009C7E0: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_8009C80C;
    }
    // 0x8009C7E0: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x8009C7E4: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009C7E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009C7EC: jal         0x8007C12C
    // 0x8009C7F0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x8009C7F0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8009C7F4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009C7F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C7FC: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8009C800: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009C804: b           L_8009C874
    // 0x8009C808: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
        goto L_8009C874;
    // 0x8009C808: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
L_8009C80C:
    // 0x8009C80C: beq         $t6, $zero, L_8009C854
    if (ctx->r14 == 0) {
        // 0x8009C810: andi        $a0, $v0, 0x3FFF
        ctx->r4 = ctx->r2 & 0X3FFF;
            goto L_8009C854;
    }
    // 0x8009C810: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009C814: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8009C818: sb          $v0, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r2;
    // 0x8009C81C: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8009C820: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8009C824: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8009C828: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8009C82C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009C830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009C834: jal         0x8000EA54
    // 0x8009C838: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8009C838: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_3:
    // 0x8009C83C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009C840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C844: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8009C848: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009C84C: b           L_8009C874
    // 0x8009C850: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
        goto L_8009C874;
    // 0x8009C850: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
L_8009C854:
    // 0x8009C854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009C858: jal         0x8005F99C
    // 0x8009C85C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    object_model_init(rdram, ctx);
        goto after_4;
    // 0x8009C85C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009C860: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009C864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C868: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8009C86C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009C870: sw          $v0, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r2;
L_8009C874:
    // 0x8009C874: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8009C878: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009C87C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009C880: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x8009C884: lh          $t4, -0x8A8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X8A8);
    // 0x8009C888: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C88C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009C890: sh          $t5, -0x8A8($at)
    MEM_H(-0X8A8, ctx->r1) = ctx->r13;
L_8009C894:
    // 0x8009C894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009C89C: jr          $ra
    // 0x8009C8A0: nop

    return;
    // 0x8009C8A0: nop

;}
RECOMP_FUNC void func_800BFE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFE98: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BFE9C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BFEA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BFEA4: addiu       $t0, $t0, 0x3194
    ctx->r8 = ADD32(ctx->r8, 0X3194);
    // 0x800BFEA8: addiu       $t1, $t1, 0x3190
    ctx->r9 = ADD32(ctx->r9, 0X3190);
    // 0x800BFEAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFEB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFEB4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
L_800BFEB8:
    // 0x800BFEB8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800BFEBC: nop

    // 0x800BFEC0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x800BFEC4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800BFEC8: nop

    // 0x800BFECC: beq         $t7, $zero, L_800BFF08
    if (ctx->r15 == 0) {
        // 0x800BFED0: nop
    
            goto L_800BFF08;
    }
    // 0x800BFED0: nop

    // 0x800BFED4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BFED8: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x800BFEDC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800BFEE0: lw          $t3, 0x1C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X1C);
    // 0x800BFEE4: lhu         $t4, 0x1A($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X1A);
    // 0x800BFEE8: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFEEC: mflo        $a1
    ctx->r5 = lo;
    // 0x800BFEF0: srl         $t5, $a1, 4
    ctx->r13 = S32(U32(ctx->r5) >> 4);
    // 0x800BFEF4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BFEF8: sh          $t6, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r14;
    // 0x800BFEFC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BFF00: nop

    // 0x800BFF04: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
L_800BFF08:
    // 0x800BFF08: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800BFF0C: nop

    // 0x800BFF10: beq         $t8, $zero, L_800BFF4C
    if (ctx->r24 == 0) {
        // 0x800BFF14: nop
    
            goto L_800BFF4C;
    }
    // 0x800BFF14: nop

    // 0x800BFF18: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BFF1C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800BFF20: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x800BFF24: lw          $t4, 0x5C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X5C);
    // 0x800BFF28: lhu         $t5, 0x5A($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X5A);
    // 0x800BFF2C: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFF30: mflo        $a1
    ctx->r5 = lo;
    // 0x800BFF34: srl         $t6, $a1, 4
    ctx->r14 = S32(U32(ctx->r5) >> 4);
    // 0x800BFF38: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BFF3C: sh          $t7, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r15;
    // 0x800BFF40: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BFF44: nop

    // 0x800BFF48: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
L_800BFF4C:
    // 0x800BFF4C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800BFF50: nop

    // 0x800BFF54: beq         $t9, $zero, L_800BFF90
    if (ctx->r25 == 0) {
        // 0x800BFF58: nop
    
            goto L_800BFF90;
    }
    // 0x800BFF58: nop

    // 0x800BFF5C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800BFF60: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800BFF64: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800BFF68: lw          $t5, 0x9C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C);
    // 0x800BFF6C: lhu         $t6, 0x9A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X9A);
    // 0x800BFF70: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFF74: mflo        $a1
    ctx->r5 = lo;
    // 0x800BFF78: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x800BFF7C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFF80: sh          $t8, 0x9A($a2)
    MEM_H(0X9A, ctx->r6) = ctx->r24;
    // 0x800BFF84: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BFF88: nop

    // 0x800BFF8C: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
L_800BFF90:
    // 0x800BFF90: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800BFF94: nop

    // 0x800BFF98: beq         $t3, $zero, L_800BFFC8
    if (ctx->r11 == 0) {
        // 0x800BFF9C: nop
    
            goto L_800BFFC8;
    }
    // 0x800BFF9C: nop

    // 0x800BFFA0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800BFFA4: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800BFFA8: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800BFFAC: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x800BFFB0: lhu         $t7, 0xDA($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XDA);
    // 0x800BFFB4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFFB8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BFFBC: srl         $t8, $a1, 4
    ctx->r24 = S32(U32(ctx->r5) >> 4);
    // 0x800BFFC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BFFC4: sh          $t9, 0xDA($a2)
    MEM_H(0XDA, ctx->r6) = ctx->r25;
L_800BFFC8:
    // 0x800BFFC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BFFCC: bne         $v0, $t2, L_800BFEB8
    if (ctx->r2 != ctx->r10) {
        // 0x800BFFD0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800BFEB8;
    }
    // 0x800BFFD0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800BFFD4: jr          $ra
    // 0x800BFFD8: nop

    return;
    // 0x800BFFD8: nop

;}
RECOMP_FUNC void snow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC0C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AC0CC: addiu       $t1, $t1, 0x7BB0
    ctx->r9 = ADD32(ctx->r9, 0X7BB0);
    // 0x800AC0D0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC0D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AC0D8: blez        $t6, L_800AC214
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AC0DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AC214;
    }
    // 0x800AC0DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AC0E0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AC0E4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC0E8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AC0EC: addiu       $t2, $t2, 0x28D4
    ctx->r10 = ADD32(ctx->r10, 0X28D4);
    // 0x800AC0F0: addiu       $t4, $t4, 0x28D8
    ctx->r12 = ADD32(ctx->r12, 0X28D8);
    // 0x800AC0F4: addiu       $t5, $t5, 0x7BB8
    ctx->r13 = ADD32(ctx->r13, 0X7BB8);
    // 0x800AC0F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC0FC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_800AC100:
    // 0x800AC100: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC104: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AC108: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC10C: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC110: nop

    // 0x800AC114: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC118: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x800AC11C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC120: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC124: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AC128: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC12C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC130: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC134: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AC138: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC13C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC140: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x800AC144: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC148: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC14C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AC150: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC154: lw          $t8, 0x18($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X18);
    // 0x800AC158: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800AC15C: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC160: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC164: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800AC168: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC16C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800AC170: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC174: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC178: lw          $t8, 0x1C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1C);
    // 0x800AC17C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC180: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800AC184: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800AC188: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800AC18C: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x800AC190: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800AC194: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x800AC198: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC19C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC1A0: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC1A4: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800AC1A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC1AC: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC1B0: lw          $t8, 0x20($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X20);
    // 0x800AC1B4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC1B8: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC1BC: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800AC1C0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC1C4: nop

    // 0x800AC1C8: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC1CC: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC1D0: nop

    // 0x800AC1D4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800AC1D8: sb          $t8, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r24;
    // 0x800AC1DC: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800AC1E0: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x800AC1E4: addu        $a1, $t9, $a0
    ctx->r5 = ADD32(ctx->r25, ctx->r4);
    // 0x800AC1E8: lbu         $a3, 0xF($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC1EC: nop

    // 0x800AC1F0: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AC1F4: bne         $at, $zero, L_800AC200
    if (ctx->r1 != 0) {
        // 0x800AC1F8: subu        $t7, $a3, $t0
        ctx->r15 = SUB32(ctx->r7, ctx->r8);
            goto L_800AC200;
    }
    // 0x800AC1F8: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x800AC1FC: sb          $t7, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r15;
L_800AC200:
    // 0x800AC200: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC204: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AC208: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AC20C: bne         $at, $zero, L_800AC100
    if (ctx->r1 != 0) {
        // 0x800AC210: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800AC100;
    }
    // 0x800AC210: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_800AC214:
    // 0x800AC214: jr          $ra
    // 0x800AC218: nop

    return;
    // 0x800AC218: nop

;}
RECOMP_FUNC void unset_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013548: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001354C: nop

    // 0x80013550: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80013554: bne         $t7, $zero, L_800135B0
    if (ctx->r15 != 0) {
        // 0x80013558: nop
    
            goto L_800135B0;
    }
    // 0x80013558: nop

    // 0x8001355C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80013560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013564: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80013568: nop

    // 0x8001356C: bne         $t9, $at, L_800135B0
    if (ctx->r25 != ctx->r1) {
        // 0x80013570: nop
    
            goto L_800135B0;
    }
    // 0x80013570: nop

    // 0x80013574: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80013578: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001357C: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80013580: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80013584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80013588: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001358C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80013590: lwc1        $f16, 0x7C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80013594: nop

    // 0x80013598: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001359C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800135A0: lwc1        $f6, 0x80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X80);
    // 0x800135A4: nop

    // 0x800135A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800135AC: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
L_800135B0:
    // 0x800135B0: jr          $ra
    // 0x800135B4: nop

    return;
    // 0x800135B4: nop

;}
RECOMP_FUNC void obj_init_property_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E30: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80023E34: sltiu       $at, $t6, 0x74
    ctx->r1 = ctx->r14 < 0X74 ? 1 : 0;
    // 0x80023E38: beq         $at, $zero, L_80023F40
    if (ctx->r1 == 0) {
        // 0x80023E3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80023F40;
    }
    // 0x80023E3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023E40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80023E44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023E48: addu        $at, $at, $t6
    gpr jr_addend_80023E54 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80023E4C: lw          $t6, 0x5A3C($at)
    ctx->r14 = ADD32(ctx->r1, 0X5A3C);
    // 0x80023E50: nop

    // 0x80023E54: jr          $t6
    // 0x80023E58: nop

    switch (jr_addend_80023E54 >> 2) {
        case 0: goto L_80023E5C; break;
        case 1: goto L_80023E64; break;
        case 2: goto L_80023F40; break;
        case 3: goto L_80023F40; break;
        case 4: goto L_80023E6C; break;
        case 5: goto L_80023F40; break;
        case 6: goto L_80023F14; break;
        case 7: goto L_80023F40; break;
        case 8: goto L_80023F40; break;
        case 9: goto L_80023F40; break;
        case 10: goto L_80023F40; break;
        case 11: goto L_80023E74; break;
        case 12: goto L_80023F14; break;
        case 13: goto L_80023E7C; break;
        case 14: goto L_80023F40; break;
        case 15: goto L_80023F40; break;
        case 16: goto L_80023E84; break;
        case 17: goto L_80023F14; break;
        case 18: goto L_80023F40; break;
        case 19: goto L_80023F40; break;
        case 20: goto L_80023F40; break;
        case 21: goto L_80023F40; break;
        case 22: goto L_80023F40; break;
        case 23: goto L_80023E9C; break;
        case 24: goto L_80023F40; break;
        case 25: goto L_80023F14; break;
        case 26: goto L_80023F40; break;
        case 27: goto L_80023F40; break;
        case 28: goto L_80023F40; break;
        case 29: goto L_80023F14; break;
        case 30: goto L_80023EA4; break;
        case 31: goto L_80023EAC; break;
        case 32: goto L_80023F40; break;
        case 33: goto L_80023F40; break;
        case 34: goto L_80023F40; break;
        case 35: goto L_80023F14; break;
        case 36: goto L_80023F40; break;
        case 37: goto L_80023EBC; break;
        case 38: goto L_80023EC4; break;
        case 39: goto L_80023ECC; break;
        case 40: goto L_80023F14; break;
        case 41: goto L_80023F40; break;
        case 42: goto L_80023F40; break;
        case 43: goto L_80023F40; break;
        case 44: goto L_80023ED4; break;
        case 45: goto L_80023F40; break;
        case 46: goto L_80023F40; break;
        case 47: goto L_80023EDC; break;
        case 48: goto L_80023F24; break;
        case 49: goto L_80023EEC; break;
        case 50: goto L_80023F24; break;
        case 51: goto L_80023F14; break;
        case 52: goto L_80023F40; break;
        case 53: goto L_80023EF4; break;
        case 54: goto L_80023F14; break;
        case 55: goto L_80023EEC; break;
        case 56: goto L_80023F14; break;
        case 57: goto L_80023F40; break;
        case 58: goto L_80023F40; break;
        case 59: goto L_80023F40; break;
        case 60: goto L_80023F24; break;
        case 61: goto L_80023F2C; break;
        case 62: goto L_80023EE4; break;
        case 63: goto L_80023EAC; break;
        case 64: goto L_80023F40; break;
        case 65: goto L_80023F40; break;
        case 66: goto L_80023EB4; break;
        case 67: goto L_80023F14; break;
        case 68: goto L_80023F40; break;
        case 69: goto L_80023E8C; break;
        case 70: goto L_80023F40; break;
        case 71: goto L_80023E8C; break;
        case 72: goto L_80023F40; break;
        case 73: goto L_80023EFC; break;
        case 74: goto L_80023F40; break;
        case 75: goto L_80023F40; break;
        case 76: goto L_80023E84; break;
        case 77: goto L_80023F14; break;
        case 78: goto L_80023F14; break;
        case 79: goto L_80023EEC; break;
        case 80: goto L_80023F0C; break;
        case 81: goto L_80023F1C; break;
        case 82: goto L_80023F40; break;
        case 83: goto L_80023EEC; break;
        case 84: goto L_80023F40; break;
        case 85: goto L_80023EEC; break;
        case 86: goto L_80023F40; break;
        case 87: goto L_80023EAC; break;
        case 88: goto L_80023F40; break;
        case 89: goto L_80023F40; break;
        case 90: goto L_80023F04; break;
        case 91: goto L_80023F40; break;
        case 92: goto L_80023F14; break;
        case 93: goto L_80023F40; break;
        case 94: goto L_80023EFC; break;
        case 95: goto L_80023E8C; break;
        case 96: goto L_80023E8C; break;
        case 97: goto L_80023F14; break;
        case 98: goto L_80023EFC; break;
        case 99: goto L_80023EFC; break;
        case 100: goto L_80023E94; break;
        case 101: goto L_80023E94; break;
        case 102: goto L_80023E94; break;
        case 103: goto L_80023E94; break;
        case 104: goto L_80023F40; break;
        case 105: goto L_80023F40; break;
        case 106: goto L_80023F40; break;
        case 107: goto L_80023F14; break;
        case 108: goto L_80023F34; break;
        case 109: goto L_80023EAC; break;
        case 110: goto L_80023E7C; break;
        case 111: goto L_80023F40; break;
        case 112: goto L_80023F40; break;
        case 113: goto L_80023F3C; break;
        case 114: goto L_80023EEC; break;
        case 115: goto L_80023F14; break;
        default: switch_error(__func__, 0x80023E54, 0x800E5A3C);
    }
    // 0x80023E58: nop

L_80023E5C:
    // 0x80023E5C: jr          $ra
    // 0x80023E60: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x80023E60: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_80023E64:
    // 0x80023E64: jr          $ra
    // 0x80023E68: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x80023E68: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80023E6C:
    // 0x80023E6C: jr          $ra
    // 0x80023E70: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x80023E70: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80023E74:
    // 0x80023E74: jr          $ra
    // 0x80023E78: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023E78: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023E7C:
    // 0x80023E7C: jr          $ra
    // 0x80023E80: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023E80: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023E84:
    // 0x80023E84: jr          $ra
    // 0x80023E88: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023E88: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023E8C:
    // 0x80023E8C: jr          $ra
    // 0x80023E90: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    return;
    // 0x80023E90: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
L_80023E94:
    // 0x80023E94: jr          $ra
    // 0x80023E98: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    return;
    // 0x80023E98: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80023E9C:
    // 0x80023E9C: jr          $ra
    // 0x80023EA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80023EA0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80023EA4:
    // 0x80023EA4: jr          $ra
    // 0x80023EA8: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023EA8: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023EAC:
    // 0x80023EAC: jr          $ra
    // 0x80023EB0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EB0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EB4:
    // 0x80023EB4: jr          $ra
    // 0x80023EB8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023EB8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023EBC:
    // 0x80023EBC: jr          $ra
    // 0x80023EC0: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    return;
    // 0x80023EC0: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
L_80023EC4:
    // 0x80023EC4: jr          $ra
    // 0x80023EC8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EC8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023ECC:
    // 0x80023ECC: jr          $ra
    // 0x80023ED0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023ED0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023ED4:
    // 0x80023ED4: jr          $ra
    // 0x80023ED8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023ED8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EDC:
    // 0x80023EDC: jr          $ra
    // 0x80023EE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023EE0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023EE4:
    // 0x80023EE4: jr          $ra
    // 0x80023EE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023EE8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023EEC:
    // 0x80023EEC: jr          $ra
    // 0x80023EF0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023EF0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023EF4:
    // 0x80023EF4: jr          $ra
    // 0x80023EF8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023EF8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023EFC:
    // 0x80023EFC: jr          $ra
    // 0x80023F00: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    return;
    // 0x80023F00: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
L_80023F04:
    // 0x80023F04: jr          $ra
    // 0x80023F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023F0C:
    // 0x80023F0C: jr          $ra
    // 0x80023F10: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x80023F10: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80023F14:
    // 0x80023F14: jr          $ra
    // 0x80023F18: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80023F18: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80023F1C:
    // 0x80023F1C: jr          $ra
    // 0x80023F20: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023F20: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F24:
    // 0x80023F24: jr          $ra
    // 0x80023F28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80023F28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80023F2C:
    // 0x80023F2C: jr          $ra
    // 0x80023F30: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023F30: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023F34:
    // 0x80023F34: jr          $ra
    // 0x80023F38: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F38: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F3C:
    // 0x80023F3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80023F40:
    // 0x80023F40: jr          $ra
    // 0x80023F44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80023F44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void render_object_parts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001348C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013490: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013494: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013498: jal         0x80012F94
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    set_temp_model_transforms(rdram, ctx);
        goto after_0;
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800134A0: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800134A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800134A8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800134AC: beq         $t7, $zero, L_800134DC
    if (ctx->r15 == 0) {
        // 0x800134B0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800134DC;
    }
    // 0x800134B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800134B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800134B8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800134BC: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x800134C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800134C4: addiu       $a3, $a3, -0x516C
    ctx->r7 = ADD32(ctx->r7, -0X516C);
    // 0x800134C8: addiu       $a2, $a2, -0x5170
    ctx->r6 = ADD32(ctx->r6, -0X5170);
    // 0x800134CC: jal         0x800B3740
    // 0x800134D0: addiu       $a1, $a1, -0x5174
    ctx->r5 = ADD32(ctx->r5, -0X5174);
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800134D0: addiu       $a1, $a1, -0x5174
    ctx->r5 = ADD32(ctx->r5, -0X5174);
    after_1:
    // 0x800134D4: b           L_80013530
    // 0x800134D8: nop

        goto L_80013530;
    // 0x800134D8: nop

L_800134DC:
    // 0x800134DC: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800134E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800134E4: lb          $v0, 0x53($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X53);
    // 0x800134E8: nop

    // 0x800134EC: bne         $v0, $zero, L_80013504
    if (ctx->r2 != 0) {
        // 0x800134F0: nop
    
            goto L_80013504;
    }
    // 0x800134F0: nop

    // 0x800134F4: jal         0x800120C8
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_model(rdram, ctx);
        goto after_2;
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800134FC: b           L_80013530
    // 0x80013500: nop

        goto L_80013530;
    // 0x80013500: nop

L_80013504:
    // 0x80013504: bne         $v0, $at, L_80013520
    if (ctx->r2 != ctx->r1) {
        // 0x80013508: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80013520;
    }
    // 0x80013508: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001350C: jal         0x80011C94
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_billboard(rdram, ctx);
        goto after_3;
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80013514: b           L_80013530
    // 0x80013518: nop

        goto L_80013530;
    // 0x80013518: nop

    // 0x8001351C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80013520:
    // 0x80013520: bne         $v0, $at, L_80013530
    if (ctx->r2 != ctx->r1) {
        // 0x80013524: nop
    
            goto L_80013530;
    }
    // 0x80013524: nop

    // 0x80013528: jal         0x80011AD0
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_misc(rdram, ctx);
        goto after_4;
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80013530:
    // 0x80013530: jal         0x80013548
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    unset_temp_model_transforms(rdram, ctx);
        goto after_5;
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80013538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001353C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013540: jr          $ra
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80026070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026070: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80026074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026078: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002607C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80026080: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80026084: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80026088: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002608C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80026090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026094: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80026098: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8002609C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800260A0: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x800260A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800260A8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800260AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800260B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800260B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800260B8: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x800260BC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800260C0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800260C4: addiu       $t3, $sp, 0x80
    ctx->r11 = ADD32(ctx->r29, 0X80);
    // 0x800260C8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800260CC: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x800260D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800260D4: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x800260D8: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x800260DC: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x800260E0: nop

    // 0x800260E4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800260E8: nop

    // 0x800260EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800260F0: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800260F4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x800260F8: nop

    // 0x800260FC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80026100: nop

    // 0x80026104: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026108: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002610C: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x80026110: nop

    // 0x80026114: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80026118: nop

    // 0x8002611C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026120: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x80026124: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80026128: nop

    // 0x8002612C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026130: nop

    // 0x80026134: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026138: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002613C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80026140: nop

    // 0x80026144: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026148: nop

    // 0x8002614C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026150: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
L_80026154:
    // 0x80026154: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026158: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x8002615C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026160: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x80026164: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80026168: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002616C: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x80026170: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80026174: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80026178: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002617C: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x80026180: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80026184: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80026188: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8002618C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80026190: c.le.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d <= ctx->f2.d;
    // 0x80026194: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80026198: bc1f        L_800261A4
    if (!c1cs) {
        // 0x8002619C: nop
    
            goto L_800261A4;
    }
    // 0x8002619C: nop

    // 0x800261A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800261A4:
    // 0x800261A4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800261A8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800261AC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800261B0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800261B4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800261B8: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800261BC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x800261C0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800261C4: bne         $at, $zero, L_80026154
    if (ctx->r1 != 0) {
        // 0x800261C8: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80026154;
    }
    // 0x800261C8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800261CC: beq         $t9, $zero, L_8002641C
    if (ctx->r25 == 0) {
        // 0x800261D0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8002641C;
    }
    // 0x800261D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800261D4: beq         $t9, $at, L_8002641C
    if (ctx->r25 == ctx->r1) {
        // 0x800261D8: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002641C;
    }
    // 0x800261D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800261DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800261E0: addiu       $ra, $sp, 0x4C
    ctx->r31 = ADD32(ctx->r29, 0X4C);
    // 0x800261E4: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
L_800261E8:
    // 0x800261E8: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x800261EC: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x800261F0: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x800261F4: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800261F8: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800261FC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80026200: bne         $at, $zero, L_8002620C
    if (ctx->r1 != 0) {
        // 0x80026204: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_8002620C;
    }
    // 0x80026204: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80026208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002620C:
    // 0x8002620C: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80026210: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80026214: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80026218: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002621C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80026220: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80026224: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026228: beq         $t9, $t8, L_800262A0
    if (ctx->r25 == ctx->r24) {
        // 0x8002622C: addu        $t7, $t1, $v0
        ctx->r15 = ADD32(ctx->r9, ctx->r2);
            goto L_800262A0;
    }
    // 0x8002622C: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80026230: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80026234: addu        $t9, $t1, $v1
    ctx->r25 = ADD32(ctx->r9, ctx->r3);
    // 0x80026238: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8002623C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026240: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80026244: sub.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80026248: addu        $t8, $t3, $v0
    ctx->r24 = ADD32(ctx->r11, ctx->r2);
    // 0x8002624C: div.s       $f14, $f12, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80026250: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026254: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026258: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8002625C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80026260: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x80026264: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x80026268: addu        $t9, $t2, $v0
    ctx->r25 = ADD32(ctx->r10, ctx->r2);
    // 0x8002626C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80026270: addu        $t6, $ra, $a0
    ctx->r14 = ADD32(ctx->r31, ctx->r4);
    // 0x80026274: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80026278: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8002627C: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80026280: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026284: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80026288: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002628C: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80026290: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026294: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80026298: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8002629C: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
L_800262A0:
    // 0x800262A0: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800262A4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800262A8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800262AC: bne         $at, $zero, L_800261E8
    if (ctx->r1 != 0) {
        // 0x800262B0: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_800261E8;
    }
    // 0x800262B0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800262B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800262B8: bne         $t0, $at, L_8002641C
    if (ctx->r8 != ctx->r1) {
        // 0x800262BC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002641C;
    }
    // 0x800262BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800262C0: lwc1        $f0, -0x2B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x800262C4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800262C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800262CC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800262D0: lwc1        $f2, -0x2B60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x800262D4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800262D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800262DC: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800262E0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800262E4: lwc1        $f12, -0x2B58($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x800262E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800262EC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800262F0: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800262F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800262F8: add.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800262FC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80026300: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80026304: add.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80026308: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002630C: nop

    // 0x80026310: bc1f        L_80026324
    if (!c1cs) {
        // 0x80026314: nop
    
            goto L_80026324;
    }
    // 0x80026314: nop

    // 0x80026318: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8002631C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x80026320: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80026324:
    // 0x80026324: lwc1        $f13, 0x5E68($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X5E68);
    // 0x80026328: lwc1        $f12, 0x5E6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5E6C);
    // 0x8002632C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80026330: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80026334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026338: bc1t        L_8002641C
    if (c1cs) {
        // 0x8002633C: swc1        $f18, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
            goto L_8002641C;
    }
    // 0x8002633C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80026340: lwc1        $f15, 0x5E70($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X5E70);
    // 0x80026344: lwc1        $f14, 0x5E74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5E74);
    // 0x80026348: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8002634C: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x80026350: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80026354: bc1t        L_8002641C
    if (c1cs) {
        // 0x80026358: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8002641C;
    }
    // 0x80026358: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8002635C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x80026360: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80026364: bc1f        L_80026378
    if (!c1cs) {
        // 0x80026368: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80026378;
    }
    // 0x80026368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002636C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80026370: nop

    // 0x80026374: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_80026378:
    // 0x80026378: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x8002637C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80026380: bc1f        L_80026394
    if (!c1cs) {
        // 0x80026384: nop
    
            goto L_80026394;
    }
    // 0x80026384: nop

    // 0x80026388: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002638C: nop

    // 0x80026390: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_80026394:
    // 0x80026394: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80026398: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002639C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800263A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263A8: lw          $t8, -0x36E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X36E8);
    // 0x800263AC: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800263B0: lh          $a1, 0x40($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X40);
    // 0x800263B4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800263B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800263BC: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x800263C0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800263C4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800263C8: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800263CC: jal         0x80026C14
    // 0x800263D0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x800263D0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800263D4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800263D8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800263DC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800263E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263E8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800263EC: lw          $t7, -0x36E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X36E8);
    // 0x800263F0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800263F4: lh          $a1, 0x40($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X40);
    // 0x800263F8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800263FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026400: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80026404: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80026408: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002640C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026410: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026414: jal         0x80026C14
    // 0x80026418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026418: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8002641C:
    // 0x8002641C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026420: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80026424: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80026428: jr          $ra
    // 0x8002642C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002642C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void menu_boot_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800884F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800884FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088500: jal         0x800C01D8
    // 0x80088504: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80088504: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_0:
    // 0x80088508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008850C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088510: jal         0x80077B34
    // 0x80088514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x80088514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80088518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008851C: jal         0x8009C674
    // 0x80088520: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80088520: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    after_2:
    // 0x80088524: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80088528: lh          $t6, -0x83C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X83C);
    // 0x8008852C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088530: addiu       $a0, $a0, 0x6550
    ctx->r4 = ADD32(ctx->r4, 0X6550);
    // 0x80088534: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80088538: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008853C: lh          $t0, -0x83A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X83A);
    // 0x80088540: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80088544: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80088548: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008854C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80088550: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80088554: lh          $t4, -0x838($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X838);
    // 0x80088558: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8008855C: sw          $t9, -0x824($at)
    MEM_W(-0X824, ctx->r1) = ctx->r25;
    // 0x80088560: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80088564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088568: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008856C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80088570: sw          $t3, -0x81C($at)
    MEM_W(-0X81C, ctx->r1) = ctx->r11;
    // 0x80088574: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80088578: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008857C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80088580: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088584: addiu       $a1, $a1, -0x826
    ctx->r5 = ADD32(ctx->r5, -0X826);
    // 0x80088588: addiu       $v0, $v0, -0x836
    ctx->r2 = ADD32(ctx->r2, -0X836);
    // 0x8008858C: addiu       $v1, $v1, -0x80C
    ctx->r3 = ADD32(ctx->r3, -0X80C);
    // 0x80088590: sw          $t7, -0x814($at)
    MEM_W(-0X814, ctx->r1) = ctx->r15;
L_80088594:
    // 0x80088594: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80088598: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x8008859C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800885A0: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800885A4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800885A8: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x800885AC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800885B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800885B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800885B8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800885BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800885C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800885C4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800885C8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800885CC: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800885D0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800885D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800885D8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800885DC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800885E0: sw          $t5, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r13;
    // 0x800885E4: sw          $t3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r11;
    // 0x800885E8: bne         $v0, $a1, L_80088594
    if (ctx->r2 != ctx->r5) {
        // 0x800885EC: sw          $t9, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r25;
            goto L_80088594;
    }
    // 0x800885EC: sw          $t9, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r25;
    // 0x800885F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800885F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800885F8: sw          $zero, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = 0;
    // 0x800885FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088600: sw          $zero, 0x6C18($at)
    MEM_W(0X6C18, ctx->r1) = 0;
    // 0x80088604: jr          $ra
    // 0x80088608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80088608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_jingle_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C08: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001C0C: lbu         $v1, 0x5D05($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D05);
    // 0x80001C10: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001C14: beq         $v1, $zero, L_80001C4C
    if (ctx->r3 == 0) {
        // 0x80001C18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80001C4C;
    }
    // 0x80001C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001C1C: lbu         $t6, -0x39BC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X39BC);
    // 0x80001C20: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001C24: beq         $t6, $zero, L_80001C4C
    if (ctx->r14 == 0) {
        // 0x80001C28: nop
    
            goto L_80001C4C;
    }
    // 0x80001C28: nop

    // 0x80001C2C: lw          $t7, -0x39CC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X39CC);
    // 0x80001C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001C34: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80001C38: nop

    // 0x80001C3C: bne         $t8, $at, L_80001C4C
    if (ctx->r24 != ctx->r1) {
        // 0x80001C40: nop
    
            goto L_80001C4C;
    }
    // 0x80001C40: nop

    // 0x80001C44: jr          $ra
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001C4C:
    // 0x80001C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001C50: sb          $zero, -0x39BC($at)
    MEM_B(-0X39BC, ctx->r1) = 0;
    // 0x80001C54: jr          $ra
    // 0x80001C58: nop

    return;
    // 0x80001C58: nop

;}
RECOMP_FUNC void func_800BBE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBE08: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BBE0C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BBE10: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BBE14: lh          $a2, 0x1A($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1A);
    // 0x800BBE18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BBE1C: blez        $a2, L_800BBEAC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BBE20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BBEAC;
    }
    // 0x800BBE20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BBE24: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BBE28: sll         $t7, $zero, 6
    ctx->r15 = S32(0 << 6);
    // 0x800BBE2C: lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
    // 0x800BBE30: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x800BBE34: ori         $s0, $s0, 0x2000
    ctx->r16 = ctx->r16 | 0X2000;
    // 0x800BBE38: ori         $s1, $s1, 0x2100
    ctx->r17 = ctx->r17 | 0X2100;
    // 0x800BBE3C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800BBE40: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BBE44:
    // 0x800BBE44: bne         $v0, $zero, L_800BBE94
    if (ctx->r2 != 0) {
        // 0x800BBE48: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800BBE94;
    }
    // 0x800BBE48: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BBE4C: lh          $t2, 0x20($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X20);
    // 0x800BBE50: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800BBE54: blez        $t2, L_800BBE94
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BBE58: subu        $t4, $t4, $zero
        ctx->r12 = SUB32(ctx->r12, 0);
            goto L_800BBE94;
    }
    // 0x800BBE58: subu        $t4, $t4, $zero
    ctx->r12 = SUB32(ctx->r12, 0);
    // 0x800BBE5C: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    // 0x800BBE60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BBE64: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
L_800BBE68:
    // 0x800BBE68: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x800BBE6C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800BBE70: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x800BBE74: bne         $s0, $t9, L_800BBE80
    if (ctx->r16 != ctx->r25) {
        // 0x800BBE78: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800BBE80;
    }
    // 0x800BBE78: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800BBE7C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800BBE80:
    // 0x800BBE80: bne         $v0, $zero, L_800BBE94
    if (ctx->r2 != 0) {
        // 0x800BBE84: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800BBE94;
    }
    // 0x800BBE84: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800BBE88: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BBE8C: bne         $at, $zero, L_800BBE68
    if (ctx->r1 != 0) {
        // 0x800BBE90: nop
    
            goto L_800BBE68;
    }
    // 0x800BBE90: nop

L_800BBE94:
    // 0x800BBE94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BBE98: bne         $v0, $zero, L_800BBEAC
    if (ctx->r2 != 0) {
        // 0x800BBE9C: addiu       $t0, $t0, 0x44
        ctx->r8 = ADD32(ctx->r8, 0X44);
            goto L_800BBEAC;
    }
    // 0x800BBE9C: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BBEA0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BBEA4: bne         $at, $zero, L_800BBE44
    if (ctx->r1 != 0) {
        // 0x800BBEA8: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800BBE44;
    }
    // 0x800BBEA8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BBEAC:
    // 0x800BBEAC: bne         $v0, $zero, L_800BBEBC
    if (ctx->r2 != 0) {
        // 0x800BBEB0: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_800BBEBC;
    }
    // 0x800BBEB0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800BBEB4: b           L_800BBEBC
    // 0x800BBEB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800BBEBC;
    // 0x800BBEB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BBEBC:
    // 0x800BBEBC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BBEC0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BBEC4: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800BBEC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BBECC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800BBED0: lh          $t8, 0x6($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X6);
    // 0x800BBED4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BBED8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBEDC: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x800BBEE0: sw          $t6, -0x5F58($at)
    MEM_W(-0X5F58, ctx->r1) = ctx->r14;
    // 0x800BBEE4: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BBEE8: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x800BBEEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBEF0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BBEF4: sw          $t9, -0x5F54($at)
    MEM_W(-0X5F54, ctx->r1) = ctx->r25;
    // 0x800BBEF8: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800BBEFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF00: sw          $t6, -0x5F50($at)
    MEM_W(-0X5F50, ctx->r1) = ctx->r14;
    // 0x800BBF04: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x800BBF08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF0C: sw          $t7, -0x5F4C($at)
    MEM_W(-0X5F4C, ctx->r1) = ctx->r15;
    // 0x800BBF10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF14: sw          $v0, -0x5F84($at)
    MEM_W(-0X5F84, ctx->r1) = ctx->r2;
    // 0x800BBF18: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800BBF1C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800BBF20: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BBF24: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BBF28: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BBF2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF30: sw          $t9, -0x5F80($at)
    MEM_W(-0X5F80, ctx->r1) = ctx->r25;
    // 0x800BBF34: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800BBF38: lui         $at, 0x7000
    ctx->r1 = S32(0X7000 << 16);
    // 0x800BBF3C: and         $t8, $a3, $at
    ctx->r24 = ctx->r7 & ctx->r1;
    // 0x800BBF40: srl         $t6, $t8, 28
    ctx->r14 = S32(U32(ctx->r24) >> 28);
    // 0x800BBF44: blez        $t6, L_800BBF64
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BBF48: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800BBF64;
    }
    // 0x800BBF48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBF4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBF50: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBF54: lw          $t8, 0x70($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X70);
    // 0x800BBF58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BBF5C: b           L_800BBF68
    // 0x800BBF60: sw          $t8, 0x3180($at)
    MEM_W(0X3180, ctx->r1) = ctx->r24;
        goto L_800BBF68;
    // 0x800BBF60: sw          $t8, 0x3180($at)
    MEM_W(0X3180, ctx->r1) = ctx->r24;
L_800BBF64:
    // 0x800BBF64: sw          $zero, 0x3180($at)
    MEM_W(0X3180, ctx->r1) = 0;
L_800BBF68:
    // 0x800BBF68: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BBF6C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BBF70: jr          $ra
    // 0x800BBF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BBF74: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void tex_animate_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_presentation_random_begin(uint8_t*, recomp_context*); dkr_netplay_presentation_random_begin(rdram, ctx);
    // 0x8007EF80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007EF84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007EF88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007EF8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007EF90: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007EF94: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x8007EF98: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007EF9C: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8007EFA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007EFA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007EFA8: and         $t2, $v0, $t0
    ctx->r10 = ctx->r2 & ctx->r8;
    // 0x8007EFAC: bgez        $v1, L_8007F09C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007EFB0: and         $t1, $v0, $at
        ctx->r9 = ctx->r2 & ctx->r1;
            goto L_8007F09C;
    }
    // 0x8007EFB0: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8007EFB4: bne         $t1, $zero, L_8007EFF0
    if (ctx->r9 != 0) {
        // 0x8007EFB8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007EFF0;
    }
    // 0x8007EFB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007EFBC: jal         0x8006F94C
    // 0x8007EFC0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8007EFC0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_0:
    // 0x8007EFC4: slti        $at, $v0, 0x3DA
    ctx->r1 = SIGNED(ctx->r2) < 0X3DA ? 1 : 0;
    // 0x8007EFC8: bne         $at, $zero, L_8007F1D4
    if (ctx->r1 != 0) {
        // 0x8007EFCC: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F1D4;
    }
    // 0x8007EFCC: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007EFD0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007EFD4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007EFD8: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007EFDC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007EFE0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007EFE4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007EFE8: b           L_8007F1D4
    // 0x8007EFEC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_8007F1D4;
    // 0x8007EFEC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007EFF0:
    // 0x8007EFF0: bne         $t2, $zero, L_8007F064
    if (ctx->r10 != 0) {
        // 0x8007EFF4: nop
    
            goto L_8007F064;
    }
    // 0x8007EFF4: nop

    // 0x8007EFF8: lhu         $t4, 0x14($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X14);
    // 0x8007EFFC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8007F000: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F004: mflo        $t5
    ctx->r13 = lo;
    // 0x8007F008: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007F00C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007F010: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F014: nop

    // 0x8007F018: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F01C: bne         $at, $zero, L_8007F1D4
    if (ctx->r1 != 0) {
        // 0x8007F020: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_8007F1D4;
    }
    // 0x8007F020: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8007F024: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8007F028: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007F02C: bgez        $t9, L_8007F050
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007F030: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8007F050;
    }
    // 0x8007F030: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F034: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F038: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8007F03C: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F040: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F044: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007F048: b           L_8007F1D4
    // 0x8007F04C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8007F1D4;
    // 0x8007F04C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8007F050:
    // 0x8007F050: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F054: nop

    // 0x8007F058: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8007F05C: b           L_8007F1D4
    // 0x8007F060: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F1D4;
    // 0x8007F060: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F064:
    // 0x8007F064: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F068: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F06C: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F070: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F074: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F078: subu        $t3, $t8, $t4
    ctx->r11 = SUB32(ctx->r24, ctx->r12);
    // 0x8007F07C: bgez        $t3, L_8007F1D4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007F080: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_8007F1D4;
    }
    // 0x8007F080: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007F084: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F088: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F08C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F090: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8007F094: b           L_8007F1D4
    // 0x8007F098: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F1D4;
    // 0x8007F098: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F09C:
    // 0x8007F09C: beq         $t1, $zero, L_8007F14C
    if (ctx->r9 == 0) {
        // 0x8007F0A0: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F14C;
    }
    // 0x8007F0A0: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007F0A4: bne         $t2, $zero, L_8007F0C8
    if (ctx->r10 != 0) {
        // 0x8007F0A8: ori         $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 | 0XFFFF;
            goto L_8007F0C8;
    }
    // 0x8007F0A8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007F0AC: lhu         $t8, 0x14($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F0B0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8007F0B4: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F0B8: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F0BC: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8007F0C0: b           L_8007F0E0
    // 0x8007F0C4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8007F0E0;
    // 0x8007F0C4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8007F0C8:
    // 0x8007F0C8: lhu         $t6, 0x14($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F0CC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8007F0D0: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F0D4: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F0D8: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8007F0DC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8007F0E0:
    // 0x8007F0E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F0E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007F0E8: bgez        $v0, L_8007F10C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F0EC: negu        $t9, $v0
        ctx->r25 = SUB32(0, ctx->r2);
            goto L_8007F10C;
    }
    // 0x8007F0EC: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8007F0F0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F0F4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8007F0F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F0FC: and         $t3, $t4, $a1
    ctx->r11 = ctx->r12 & ctx->r5;
    // 0x8007F100: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8007F104: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F108: nop

L_8007F10C:
    // 0x8007F10C: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F110: nop

    // 0x8007F114: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F118: bne         $at, $zero, L_8007F13C
    if (ctx->r1 != 0) {
        // 0x8007F11C: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_8007F13C;
    }
    // 0x8007F11C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8007F120: subu        $t5, $t6, $v0
    ctx->r13 = SUB32(ctx->r14, ctx->r2);
    // 0x8007F124: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007F128: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F12C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8007F130: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F134: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8007F138: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007F13C:
    // 0x8007F13C: bne         $a0, $zero, L_8007F0E0
    if (ctx->r4 != 0) {
        // 0x8007F140: nop
    
            goto L_8007F0E0;
    }
    // 0x8007F140: nop

    // 0x8007F144: b           L_8007F1D8
    // 0x8007F148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F1D8;
    // 0x8007F148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F14C:
    // 0x8007F14C: bne         $t2, $zero, L_8007F1A0
    if (ctx->r10 != 0) {
        // 0x8007F150: nop
    
            goto L_8007F1A0;
    }
    // 0x8007F150: nop

    // 0x8007F154: lhu         $t3, 0x14($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F158: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8007F15C: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F160: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F164: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8007F168: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8007F16C: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F170: nop

    // 0x8007F174: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F178: bne         $at, $zero, L_8007F1D4
    if (ctx->r1 != 0) {
        // 0x8007F17C: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F1D4;
    }
    // 0x8007F17C: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
L_8007F180:
    // 0x8007F180: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F184: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F188: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007F18C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F190: beq         $at, $zero, L_8007F180
    if (ctx->r1 == 0) {
        // 0x8007F194: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F180;
    }
    // 0x8007F194: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F198: b           L_8007F1D8
    // 0x8007F19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F1D8;
    // 0x8007F19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F1A0:
    // 0x8007F1A0: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F1A4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F1A8: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F1AC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007F1B0: subu        $v0, $t8, $t3
    ctx->r2 = SUB32(ctx->r24, ctx->r11);
    // 0x8007F1B4: bgez        $v0, L_8007F1D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F1B8: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_8007F1D4;
    }
    // 0x8007F1B8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8007F1BC:
    // 0x8007F1BC: lhu         $t6, 0x12($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F1C0: nop

    // 0x8007F1C4: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x8007F1C8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007F1CC: bltz        $t5, L_8007F1BC
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007F1D0: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8007F1BC;
    }
    // 0x8007F1D0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8007F1D4:
    // 0x8007F1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F1D8:
    extern void dkr_netplay_presentation_random_end(uint8_t*, recomp_context*); dkr_netplay_presentation_random_end(rdram, ctx);
    // 0x8007F1D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007F1DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007F1E0: jr          $ra
    // 0x8007F1E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F1E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_loop_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800370D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800370D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800370DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800370E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800370E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800370E8: jal         0x80066210
    // 0x800370EC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800370EC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_0:
    // 0x800370F0: blez        $v0, L_80037108
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800370F4: nop
    
            goto L_80037108;
    }
    // 0x800370F4: nop

    // 0x800370F8: jal         0x8000FFB8
    // 0x800370FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x800370FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80037100: b           L_80037568
    // 0x80037104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80037568;
    // 0x80037104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037108:
    // 0x80037108: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003710C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80037110: lbu         $v1, 0xFD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037114: nop

    // 0x80037118: beq         $v1, $zero, L_80037188
    if (ctx->r3 == 0) {
        // 0x8003711C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80037188;
    }
    // 0x8003711C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80037120: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80037124: nop

    // 0x80037128: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003712C: bne         $at, $zero, L_80037154
    if (ctx->r1 != 0) {
        // 0x80037130: nop
    
            goto L_80037154;
    }
    // 0x80037130: nop

    // 0x80037134: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80037138: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003713C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037140: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x80037144: sb          $t6, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r14;
    // 0x80037148: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003714C: b           L_80037180
    // 0x80037150: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
        goto L_80037180;
    // 0x80037150: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80037154:
    // 0x80037154: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80037158: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003715C: bgez        $v1, L_80037174
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037160: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80037174;
    }
    // 0x80037160: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037164: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80037168: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003716C: nop

    // 0x80037170: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80037174:
    // 0x80037174: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80037178: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
    // 0x8003717C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80037180:
    // 0x80037180: b           L_80037278
    // 0x80037184: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
        goto L_80037278;
    // 0x80037184: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_80037188:
    // 0x80037188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003718C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80037190: jal         0x8006F94C
    // 0x80037194: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80037194: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80037198: bne         $v0, $zero, L_80037278
    if (ctx->r2 != 0) {
        // 0x8003719C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80037278;
    }
    // 0x8003719C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800371A0: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x800371A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800371A8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800371AC: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x800371B0: nop

    // 0x800371B4: bc1f        L_8003727C
    if (!c1cs) {
        // 0x800371B8: lw          $a1, 0x74($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X74);
            goto L_8003727C;
    }
    // 0x800371B8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800371BC: jal         0x8006F94C
    // 0x800371C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800371C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x800371C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800371C8: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x800371CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800371D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800371D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800371D8: sb          $v0, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r2;
    // 0x800371DC: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800371E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800371E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800371E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800371EC: jal         0x8006F94C
    // 0x800371F0: nop

    rand_range(rdram, ctx);
        goto after_4;
    // 0x800371F0: nop

    after_4:
    // 0x800371F4: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800371F8: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800371FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80037200: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80037204: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80037208: lwc1        $f8, 0x10C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8003720C: nop

    // 0x80037210: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80037214: nop

    // 0x80037218: bc1f        L_80037238
    if (!c1cs) {
        // 0x8003721C: nop
    
            goto L_80037238;
    }
    // 0x8003721C: nop

    // 0x80037220: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80037224: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037228: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003722C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037230: b           L_8003724C
    // 0x80037234: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
        goto L_8003724C;
    // 0x80037234: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_80037238:
    // 0x80037238: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003723C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037240: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037244: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80037248: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_8003724C:
    // 0x8003724C: lbu         $t8, 0xFD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037250: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037254: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80037258: bgez        $t8, L_8003726C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003725C: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8003726C;
    }
    // 0x8003725C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80037260: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037264: nop

    // 0x80037268: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003726C:
    // 0x8003726C: nop

    // 0x80037270: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80037274: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_80037278:
    // 0x80037278: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
L_8003727C:
    // 0x8003727C: lh          $t0, 0x100($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X100);
    // 0x80037280: lh          $t9, 0xFE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XFE);
    // 0x80037284: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037288: mflo        $t1
    ctx->r9 = lo;
    // 0x8003728C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80037290: sh          $t2, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r10;
    // 0x80037294: lh          $t3, 0xFE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XFE);
    // 0x80037298: nop

    // 0x8003729C: sll         $t4, $t3, 17
    ctx->r12 = S32(ctx->r11 << 17);
    // 0x800372A0: jal         0x800707C4
    // 0x800372A4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800372A4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_5:
    // 0x800372A8: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800372AC: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x800372B0: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800372B4: jal         0x800707F8
    // 0x800372B8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800372B8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x800372BC: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800372C0: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x800372C4: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800372C8: jal         0x800707C4
    // 0x800372CC: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x800372CC: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x800372D0: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x800372D4: jal         0x800707F8
    // 0x800372D8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x800372D8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800372DC: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800372E0: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800372E4: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800372E8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800372EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800372F0: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800372F4: nop

    // 0x800372F8: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800372FC: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80037300: lwc1        $f6, 0x108($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80037304: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80037308: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8003730C: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80037310: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80037314: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037318: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8003731C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80037320: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80037324: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80037328: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003732C: nop

    // 0x80037330: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80037334: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80037338: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003733C: nop

    // 0x80037340: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80037344: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80037348: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x8003734C: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80037350: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x80037354: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80037358: jal         0x80011560
    // 0x8003735C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_9;
    // 0x8003735C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x80037360: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80037364: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80037368: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8003736C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80037370: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80037374: jal         0x80011570
    // 0x80037378: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_10;
    // 0x80037378: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8003737C: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80037380: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80037384: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80037388: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003738C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80037390: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80037394: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80037398: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x8003739C: jal         0x800C9AD0
    // 0x800373A0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800373A0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    after_11:
    // 0x800373A4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800373A8: jal         0x800C9AD0
    // 0x800373AC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800373AC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800373B0: lui         $at, 0x44C0
    ctx->r1 = S32(0X44C0 << 16);
    // 0x800373B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800373B8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800373BC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800373C0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800373C4: lh          $t8, 0x106($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X106);
    // 0x800373C8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800373CC: nop

    // 0x800373D0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800373D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800373D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800373DC: nop

    // 0x800373E0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800373E4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800373E8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800373EC: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x800373F0: sh          $t0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r8;
    // 0x800373F4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800373F8: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800373FC: jal         0x80070750
    // 0x80037400: nop

    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x80037400: nop

    after_13:
    // 0x80037404: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80037408: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003740C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80037410: jal         0x80070750
    // 0x80037414: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x80037414: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_14:
    // 0x80037418: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8003741C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80037420: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x80037424: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80037428: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8003742C: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x80037430: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80037434: beq         $at, $zero, L_8003745C
    if (ctx->r1 == 0) {
        // 0x80037438: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8003745C;
    }
    // 0x80037438: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8003743C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80037440: nop

    // 0x80037444: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037448: mflo        $t3
    ctx->r11 = lo;
    // 0x8003744C: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80037450: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80037454: b           L_80037470
    // 0x80037458: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
        goto L_80037470;
    // 0x80037458: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
L_8003745C:
    // 0x8003745C: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037460: mflo        $t8
    ctx->r24 = lo;
    // 0x80037464: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80037468: subu        $t0, $v1, $t7
    ctx->r8 = SUB32(ctx->r3, ctx->r15);
    // 0x8003746C: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
L_80037470:
    // 0x80037470: lbu         $t9, 0xFC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XFC);
    // 0x80037474: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80037478: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x8003747C: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80037480: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80037484: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80037488: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8003748C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80037490: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80037494: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80037498: addu        $v1, $s0, $t5
    ctx->r3 = ADD32(ctx->r16, ctx->r13);
    // 0x8003749C: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
    // 0x800374A0: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800374A4: lh          $a0, 0x106($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X106);
    // 0x800374A8: jal         0x80070830
    // 0x800374AC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    sins_s16(rdram, ctx);
        goto after_15;
    // 0x800374AC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_15:
    // 0x800374B0: sra         $s1, $v0, 3
    ctx->r17 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800374B4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800374B8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800374BC: jal         0x800707F8
    // 0x800374C0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    coss_f(rdram, ctx);
        goto after_16;
    // 0x800374C0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_16:
    // 0x800374C4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800374C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800374CC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800374D0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800374D4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800374D8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800374DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800374E0: nop

    // 0x800374E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800374E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800374EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800374F0: nop

    // 0x800374F4: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800374F8: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x800374FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80037500: jal         0x800707C4
    // 0x80037504: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x80037504: nop

    after_17:
    // 0x80037508: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8003750C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037510: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80037514: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80037518: lh          $t1, 0x14($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X14);
    // 0x8003751C: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
    // 0x80037520: lh          $t4, 0x1E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1E);
    // 0x80037524: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037528: lh          $t6, 0x22($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X22);
    // 0x8003752C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80037530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037538: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003753C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037540: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80037544: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80037548: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003754C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80037550: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80037554: sh          $t9, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r25;
    // 0x80037558: sh          $t3, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r11;
    // 0x8003755C: sh          $t5, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r13;
    // 0x80037560: sh          $t8, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r24;
    // 0x80037564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037568:
    // 0x80037568: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003756C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80037570: jr          $ra
    // 0x80037574: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80037574: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void lensflare_override_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACF98: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800ACF9C: addiu       $a3, $a3, 0x2A88
    ctx->r7 = ADD32(ctx->r7, 0X2A88);
    // 0x800ACFA0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800ACFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACFA8: blez        $a1, L_800ACFE4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800ACFAC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ACFE4;
    }
    // 0x800ACFAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ACFB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800ACFB4: addiu       $t7, $t7, 0x7C40
    ctx->r15 = ADD32(ctx->r15, 0X7C40);
    // 0x800ACFB8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800ACFBC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_800ACFC0:
    // 0x800ACFC0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800ACFC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ACFC8: bne         $a0, $t8, L_800ACFD4
    if (ctx->r4 != ctx->r24) {
        // 0x800ACFCC: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800ACFD4;
    }
    // 0x800ACFCC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800ACFD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACFD4:
    // 0x800ACFD4: beq         $at, $zero, L_800ACFE4
    if (ctx->r1 == 0) {
        // 0x800ACFD8: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800ACFE4;
    }
    // 0x800ACFD8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800ACFDC: beq         $v0, $zero, L_800ACFC0
    if (ctx->r2 == 0) {
        // 0x800ACFE0: nop
    
            goto L_800ACFC0;
    }
    // 0x800ACFE0: nop

L_800ACFE4:
    // 0x800ACFE4: beq         $v0, $zero, L_800AD028
    if (ctx->r2 == 0) {
        // 0x800ACFE8: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_800AD028;
    }
    // 0x800ACFE8: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800ACFEC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ACFF0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800ACFF4: beq         $at, $zero, L_800AD028
    if (ctx->r1 == 0) {
        // 0x800ACFF8: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_800AD028;
    }
    // 0x800ACFF8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800ACFFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AD000: addiu       $t1, $t1, 0x7C40
    ctx->r9 = ADD32(ctx->r9, 0X7C40);
    // 0x800AD004: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800AD008: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800AD00C: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x800AD010: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
L_800AD014:
    // 0x800AD014: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x800AD018: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AD01C: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800AD020: bne         $at, $zero, L_800AD014
    if (ctx->r1 != 0) {
        // 0x800AD024: sw          $t3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r11;
            goto L_800AD014;
    }
    // 0x800AD024: sw          $t3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r11;
L_800AD028:
    // 0x800AD028: jr          $ra
    // 0x800AD02C: nop

    return;
    // 0x800AD02C: nop

;}
RECOMP_FUNC void reset_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1BC: sb          $zero, -0x38C4($at)
    MEM_B(-0X38C4, ctx->r1) = 0;
    // 0x8000E1C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1C4: jr          $ra
    // 0x8000E1C8: sb          $zero, -0x38C0($at)
    MEM_B(-0X38C0, ctx->r1) = 0;
    return;
    // 0x8000E1C8: sb          $zero, -0x38C0($at)
    MEM_B(-0X38C0, ctx->r1) = 0;
;}
RECOMP_FUNC void menu_save_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80085274: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085278: sw          $v0, 0x6A6C($at)
    MEM_W(0X6A6C, ctx->r1) = ctx->r2;
    // 0x8008527C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085280: sw          $zero, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = 0;
    // 0x80085284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085288: sw          $v0, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r2;
    // 0x8008528C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085290: sw          $v0, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r2;
    // 0x80085294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085298: sh          $zero, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = 0;
    // 0x8008529C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852A0: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x800852A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800852A8: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x800852AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800852B4: sw          $v0, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r2;
    // 0x800852B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800852BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852C0: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x800852C4: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x800852C8: jal         0x80070C9C
    // 0x800852CC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800852CC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800852D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852D4: sw          $v0, 0x6A64($at)
    MEM_W(0X6A64, ctx->r1) = ctx->r2;
    // 0x800852D8: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    // 0x800852DC: jal         0x80070C9C
    // 0x800852E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800852E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800852E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800852E8: addiu       $v1, $v1, 0x6A0C
    ctx->r3 = ADD32(ctx->r3, 0X6A0C);
    // 0x800852EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800852F0: addiu       $t7, $v0, 0x500
    ctx->r15 = ADD32(ctx->r2, 0X500);
    // 0x800852F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852F8: sw          $t7, 0x6A04($at)
    MEM_W(0X6A04, ctx->r1) = ctx->r15;
    // 0x800852FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085300: sw          $zero, 0x6A08($at)
    MEM_W(0X6A08, ctx->r1) = 0;
    // 0x80085304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085308: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008530C: sw          $zero, 0x6BD4($at)
    MEM_W(0X6BD4, ctx->r1) = 0;
    // 0x80085310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085314: swc1        $f0, 0x6BDC($at)
    MEM_W(0X6BDC, ctx->r1) = ctx->f0.u32l;
    // 0x80085318: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008531C: sw          $zero, 0x6A00($at)
    MEM_W(0X6A00, ctx->r1) = 0;
    // 0x80085320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085324: sw          $zero, 0x6BE4($at)
    MEM_W(0X6BE4, ctx->r1) = 0;
    // 0x80085328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008532C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085330: addiu       $a0, $a0, -0x388
    ctx->r4 = ADD32(ctx->r4, -0X388);
    // 0x80085334: jal         0x8009C674
    // 0x80085338: swc1        $f0, 0x6BEC($at)
    MEM_W(0X6BEC, ctx->r1) = ctx->f0.u32l;
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80085338: swc1        $f0, 0x6BEC($at)
    MEM_W(0X6BEC, ctx->r1) = ctx->f0.u32l;
    after_2:
    // 0x8008533C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085340: jal         0x8009C8A4
    // 0x80085344: addiu       $a0, $a0, -0x354
    ctx->r4 = ADD32(ctx->r4, -0X354);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x80085344: addiu       $a0, $a0, -0x354
    ctx->r4 = ADD32(ctx->r4, -0X354);
    after_3:
    // 0x80085348: jal         0x8007FFEC
    // 0x8008534C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x8008534C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x80085350: jal         0x800C4170
    // 0x80085354: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x80085354: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80085358: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008535C: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x80085360: lw          $t8, 0x11C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X11C);
    // 0x80085364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085368: sw          $t8, -0x3F0($at)
    MEM_W(-0X3F0, ctx->r1) = ctx->r24;
    // 0x8008536C: lw          $t9, 0x120($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X120);
    // 0x80085370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085374: sw          $t9, -0x3E0($at)
    MEM_W(-0X3E0, ctx->r1) = ctx->r25;
    // 0x80085378: lw          $t0, 0x12C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X12C);
    // 0x8008537C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085380: sw          $t0, -0x3D0($at)
    MEM_W(-0X3D0, ctx->r1) = ctx->r8;
    // 0x80085384: lw          $t1, 0x128($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X128);
    // 0x80085388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008538C: sw          $t1, -0x3C0($at)
    MEM_W(-0X3C0, ctx->r1) = ctx->r9;
    // 0x80085390: lw          $t2, 0x124($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X124);
    // 0x80085394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085398: sw          $t2, -0x3B0($at)
    MEM_W(-0X3B0, ctx->r1) = ctx->r10;
    // 0x8008539C: lw          $t3, 0x118($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X118);
    // 0x800853A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800853A4: jal         0x8008E4B0
    // 0x800853A8: sw          $t3, -0x3A0($at)
    MEM_W(-0X3A0, ctx->r1) = ctx->r11;
    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x800853A8: sw          $t3, -0x3A0($at)
    MEM_W(-0X3A0, ctx->r1) = ctx->r11;
    after_6:
    // 0x800853AC: jal         0x8006EBA8
    // 0x800853B0: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_7;
    // 0x800853B0: nop

    after_7:
    // 0x800853B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800853B8: jal         0x800C01D8
    // 0x800853BC: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x800853BC: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_8:
    // 0x800853C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800853C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800853C8: jr          $ra
    // 0x800853CC: nop

    return;
    // 0x800853CC: nop

;}
RECOMP_FUNC void transition_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0494: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0498: addiu       $v1, $v1, 0x31A4
    ctx->r3 = ADD32(ctx->r3, 0X31A4);
    // 0x800C049C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C04A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C04A4: beq         $v0, $zero, L_800C04BC
    if (ctx->r2 == 0) {
        // 0x800C04A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C04BC;
    }
    // 0x800C04A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C04AC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C04B0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C04B4: b           L_800C04CC
    // 0x800C04B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800C04CC;
    // 0x800C04B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C04BC:
    // 0x800C04BC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800C04C0: bne         $at, $zero, L_800C04CC
    if (ctx->r1 != 0) {
        // 0x800C04C4: nop
    
            goto L_800C04CC;
    }
    // 0x800C04C4: nop

    // 0x800C04C8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C04CC:
    // 0x800C04CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C04D0: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
    // 0x800C04D4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C04D8: nop

    // 0x800C04DC: beq         $t7, $zero, L_800C05B8
    if (ctx->r15 == 0) {
        // 0x800C04E0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C05B8;
    }
    // 0x800C04E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C04E4: lhu         $v0, 0x31B0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X31B0);
    // 0x800C04E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C04EC: bne         $v0, $zero, L_800C04F8
    if (ctx->r2 != 0) {
        // 0x800C04F0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800C04F8;
    }
    // 0x800C04F0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C04F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800C04F8:
    // 0x800C04F8: bne         $v0, $zero, L_800C0524
    if (ctx->r2 != 0) {
        // 0x800C04FC: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800C0524;
    }
    // 0x800C04FC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C0500: lhu         $t9, 0x31B4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X31B4);
    // 0x800C0504: nop

    // 0x800C0508: bne         $t9, $zero, L_800C0524
    if (ctx->r25 != 0) {
        // 0x800C050C: nop
    
            goto L_800C0524;
    }
    // 0x800C050C: nop

    // 0x800C0510: jal         0x800C0724
    // 0x800C0514: nop

    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C0514: nop

    after_0:
    // 0x800C0518: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C051C: b           L_800C05B8
    // 0x800C0520: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
        goto L_800C05B8;
    // 0x800C0520: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
L_800C0524:
    // 0x800C0524: blez        $v0, L_800C0540
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C0528: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C0540;
    }
    // 0x800C0528: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C052C: addiu       $v0, $v0, 0x31D0
    ctx->r2 = ADD32(ctx->r2, 0X31D0);
    // 0x800C0530: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800C0534: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C0538: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x800C053C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800C0540:
    // 0x800C0540: lw          $t3, -0x58D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X58D0);
    // 0x800C0544: nop

    // 0x800C0548: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x800C054C: beq         $at, $zero, L_800C05B8
    if (ctx->r1 == 0) {
        // 0x800C0550: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800C05B8;
    }
    // 0x800C0550: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C0554: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0558: addu        $at, $at, $t3
    gpr jr_addend_800C0564 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C055C: lw          $t3, -0x6D14($at)
    ctx->r11 = ADD32(ctx->r1, -0X6D14);
    // 0x800C0560: nop

    // 0x800C0564: jr          $t3
    // 0x800C0568: nop

    switch (jr_addend_800C0564 >> 2) {
        case 0: goto L_800C056C; break;
        case 1: goto L_800C0580; break;
        case 2: goto L_800C0580; break;
        case 3: goto L_800C0594; break;
        case 4: goto L_800C0580; break;
        case 5: goto L_800C0580; break;
        case 6: goto L_800C05A8; break;
        default: switch_error(__func__, 0x800C0564, 0x800E92EC);
    }
    // 0x800C0568: nop

L_800C056C:
    // 0x800C056C: jal         0x800C0834
    // 0x800C0570: nop

    transition_update_fullscreen(rdram, ctx);
        goto after_1;
    // 0x800C0570: nop

    after_1:
    // 0x800C0574: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0578: b           L_800C05B8
    // 0x800C057C: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
        goto L_800C05B8;
    // 0x800C057C: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
L_800C0580:
    // 0x800C0580: jal         0x800C1130
    // 0x800C0584: nop

    transition_update_shape(rdram, ctx);
        goto after_2;
    // 0x800C0584: nop

    after_2:
    // 0x800C0588: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C058C: b           L_800C05B8
    // 0x800C0590: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
        goto L_800C05B8;
    // 0x800C0590: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
L_800C0594:
    // 0x800C0594: jal         0x800C1EE8
    // 0x800C0598: nop

    transition_update_circle(rdram, ctx);
        goto after_3;
    // 0x800C0598: nop

    after_3:
    // 0x800C059C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C05A0: b           L_800C05B8
    // 0x800C05A4: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
        goto L_800C05B8;
    // 0x800C05A4: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
L_800C05A8:
    // 0x800C05A8: jal         0x800C27A0
    // 0x800C05AC: nop

    transition_update_blank(rdram, ctx);
        goto after_4;
    // 0x800C05AC: nop

    after_4:
    // 0x800C05B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C05B4: addiu       $v1, $v1, 0x31AC
    ctx->r3 = ADD32(ctx->r3, 0X31AC);
L_800C05B8:
    // 0x800C05B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C05BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C05C0: jr          $ra
    // 0x800C05C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C05C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void osPfsReFormat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_virtual_pak_reformat(uint8_t*, recomp_context*); ctx->r2 = dkr_virtual_pak_reformat(rdram, ctx); return;
    // 0x800CFF90: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800CFF94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CFF98: sw          $a0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r4;
    // 0x800CFF9C: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x800CFFA0: jal         0x800CD650
    // 0x800CFFA4: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x800CFFA4: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CFFA8: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800CFFAC: jal         0x800CEDD4
    // 0x800CFFB0: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    __osPfsGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x800CFFB0: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    after_1:
    // 0x800CFFB4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800CFFB8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CFFBC: beq         $t6, $zero, L_800CFFCC
    if (ctx->r14 == 0) {
        // 0x800CFFC0: nop
    
            goto L_800CFFCC;
    }
    // 0x800CFFC0: nop

    // 0x800CFFC4: b           L_800D0380
    // 0x800CFFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800D0380;
    // 0x800CFFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800CFFCC:
    // 0x800CFFCC: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800CFFD0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CFFD4: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800CFFD8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800CFFDC: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800CFFE0: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800CFFE4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800CFFE8: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800CFFEC: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800CFFF0: jal         0x800CD694
    // 0x800CFFF4: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x800CFFF4: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_2:
    // 0x800CFFF8: jal         0x800D5964
    // 0x800CFFFC: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osGetId_recomp(rdram, ctx);
        goto after_3;
    // 0x800CFFFC: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_3:
    // 0x800D0000: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0004: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800D0008: beq         $t4, $zero, L_800D0018
    if (ctx->r12 == 0) {
        // 0x800D000C: nop
    
            goto L_800D0018;
    }
    // 0x800D000C: nop

    // 0x800D0010: b           L_800D0380
    // 0x800D0014: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800D0380;
    // 0x800D0014: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800D0018:
    // 0x800D0018: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D001C: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x800D0020: beq         $t6, $zero, L_800D004C
    if (ctx->r14 == 0) {
        // 0x800D0024: nop
    
            goto L_800D004C;
    }
    // 0x800D0024: nop

    // 0x800D0028: sb          $zero, 0x65($t5)
    MEM_B(0X65, ctx->r13) = 0;
    // 0x800D002C: jal         0x800D5FDC
    // 0x800D0030: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D0030: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_4:
    // 0x800D0034: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0038: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D003C: beq         $t8, $zero, L_800D004C
    if (ctx->r24 == 0) {
        // 0x800D0040: nop
    
            goto L_800D004C;
    }
    // 0x800D0040: nop

    // 0x800D0044: b           L_800D0380
    // 0x800D0048: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D0380;
    // 0x800D0048: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D004C:
    // 0x800D004C: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D0050:
    // 0x800D0050: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0054: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x800D0058: sb          $zero, 0x28($t7)
    MEM_B(0X28, ctx->r15) = 0;
    // 0x800D005C: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0060: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800D0064: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x800D0068: bne         $at, $zero, L_800D0050
    if (ctx->r1 != 0) {
        // 0x800D006C: sw          $t1, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r9;
            goto L_800D0050;
    }
    // 0x800D006C: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    // 0x800D0070: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D0074: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D0078: lw          $t3, 0x50($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X50);
    // 0x800D007C: blez        $t3, L_800D00E0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D0080: nop
    
            goto L_800D00E0;
    }
    // 0x800D0080: nop

L_800D0084:
    // 0x800D0084: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D0088: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D008C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0090: lw          $t6, 0x5C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X5C);
    // 0x800D0094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D0098: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D009C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800D00A0: jal         0x800CD8F0
    // 0x800D00A4: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_5;
    // 0x800D00A4: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    after_5:
    // 0x800D00A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D00AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D00B0: beq         $t8, $zero, L_800D00C0
    if (ctx->r24 == 0) {
        // 0x800D00B4: nop
    
            goto L_800D00C0;
    }
    // 0x800D00B4: nop

    // 0x800D00B8: b           L_800D0380
    // 0x800D00BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D0380;
    // 0x800D00BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D00C0:
    // 0x800D00C0: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D00C4: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D00C8: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D00CC: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800D00D0: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x800D00D4: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D00D8: bne         $at, $zero, L_800D0084
    if (ctx->r1 != 0) {
        // 0x800D00DC: nop
    
            goto L_800D0084;
    }
    // 0x800D00DC: nop

L_800D00E0:
    // 0x800D00E0: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D00E4: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D00E8: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D00EC: blez        $t3, L_800D0124
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D00F0: nop
    
            goto L_800D0124;
    }
    // 0x800D00F0: nop

L_800D00F4:
    // 0x800D00F4: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D00F8: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D00FC: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D0100: sh          $zero, 0x48($t5)
    MEM_H(0X48, ctx->r13) = 0;
    // 0x800D0104: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0108: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D010C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D0110: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0114: lw          $t7, 0x60($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X60);
    // 0x800D0118: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D011C: bne         $at, $zero, L_800D00F4
    if (ctx->r1 != 0) {
        // 0x800D0120: nop
    
            goto L_800D00F4;
    }
    // 0x800D0120: nop

L_800D0124:
    // 0x800D0124: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800D0128: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x800D012C: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D0130: beq         $at, $zero, L_800D0160
    if (ctx->r1 == 0) {
        // 0x800D0134: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D0160;
    }
    // 0x800D0134: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
L_800D0138:
    // 0x800D0138: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D013C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D0140: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D0144: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D0148: sh          $t3, 0x48($t5)
    MEM_H(0X48, ctx->r13) = ctx->r11;
    // 0x800D014C: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0150: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800D0154: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D0158: bne         $at, $zero, L_800D0138
    if (ctx->r1 != 0) {
        // 0x800D015C: sw          $t0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r8;
            goto L_800D0138;
    }
    // 0x800D015C: sw          $t0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r8;
L_800D0160:
    // 0x800D0160: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800D0164: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D0168: lw          $t7, 0x60($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X60);
    // 0x800D016C: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
    // 0x800D0170: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x800D0174: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800D0178: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800D017C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x800D0180: jal         0x800D52F0
    // 0x800D0184: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    __osSumcalc(rdram, ctx);
        goto after_6;
    // 0x800D0184: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    after_6:
    // 0x800D0188: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x800D018C: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
    // 0x800D0190: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800D0194: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D0198: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D019C:
    // 0x800D019C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D01A0: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D01A4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D01A8: lw          $t8, 0x54($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X54);
    // 0x800D01AC: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800D01B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D01B4: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D01B8: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D01BC: addu        $a3, $t9, $t1
    ctx->r7 = ADD32(ctx->r25, ctx->r9);
    // 0x800D01C0: jal         0x800CD8F0
    // 0x800D01C4: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_7;
    // 0x800D01C4: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_7:
    // 0x800D01C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D01CC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D01D0: beq         $t2, $zero, L_800D01E0
    if (ctx->r10 == 0) {
        // 0x800D01D4: nop
    
            goto L_800D01E0;
    }
    // 0x800D01D4: nop

    // 0x800D01D8: b           L_800D0380
    // 0x800D01DC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D0380;
    // 0x800D01DC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D01E0:
    // 0x800D01E0: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D01E4: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x800D01E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D01EC: lw          $t4, 0x58($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X58);
    // 0x800D01F0: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x800D01F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D01F8: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D01FC: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0200: addu        $a3, $t6, $t5
    ctx->r7 = ADD32(ctx->r14, ctx->r13);
    // 0x800D0204: jal         0x800CD8F0
    // 0x800D0208: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x800D0208: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    after_8:
    // 0x800D020C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0210: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D0214: beq         $t8, $zero, L_800D0224
    if (ctx->r24 == 0) {
        // 0x800D0218: nop
    
            goto L_800D0224;
    }
    // 0x800D0218: nop

    // 0x800D021C: b           L_800D0380
    // 0x800D0220: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D0380;
    // 0x800D0220: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0224:
    // 0x800D0224: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0228: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D022C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D0230: bne         $at, $zero, L_800D019C
    if (ctx->r1 != 0) {
        // 0x800D0234: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D019C;
    }
    // 0x800D0234: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0238: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D023C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D0240: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
    // 0x800D0244: lbu         $t7, 0x64($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X64);
    // 0x800D0248: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800D024C: bne         $at, $zero, L_800D037C
    if (ctx->r1 != 0) {
        // 0x800D0250: nop
    
            goto L_800D037C;
    }
    // 0x800D0250: nop

L_800D0254:
    // 0x800D0254: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D0258: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
L_800D025C:
    // 0x800D025C: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0260: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D0264: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D0268: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x800D026C: sh          $t3, 0x48($t8)
    MEM_H(0X48, ctx->r24) = ctx->r11;
    // 0x800D0270: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0274: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D0278: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D027C: bne         $at, $zero, L_800D025C
    if (ctx->r1 != 0) {
        // 0x800D0280: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D025C;
    }
    // 0x800D0280: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0284: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800D0288: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D028C: jal         0x800D52F0
    // 0x800D0290: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    __osSumcalc(rdram, ctx);
        goto after_9;
    // 0x800D0290: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    after_9:
    // 0x800D0294: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800D0298: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800D029C: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D02A0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800D02A4: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D02A8:
    // 0x800D02A8: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D02AC: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D02B0: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D02B4: lw          $t4, 0x54($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X54);
    // 0x800D02B8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D02BC: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x800D02C0: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x800D02C4: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800D02C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D02CC: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D02D0: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D02D4: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x800D02D8: jal         0x800CD8F0
    // 0x800D02DC: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_10;
    // 0x800D02DC: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    after_10:
    // 0x800D02E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D02E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800D02E8: beq         $t1, $zero, L_800D02F8
    if (ctx->r9 == 0) {
        // 0x800D02EC: nop
    
            goto L_800D02F8;
    }
    // 0x800D02EC: nop

    // 0x800D02F0: b           L_800D0380
    // 0x800D02F4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800D0380;
    // 0x800D02F4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800D02F8:
    // 0x800D02F8: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D02FC: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0300: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0304: lw          $t7, 0x58($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X58);
    // 0x800D0308: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800D030C: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x800D0310: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x800D0314: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x800D0318: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D031C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0320: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0324: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x800D0328: jal         0x800CD8F0
    // 0x800D032C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_11;
    // 0x800D032C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    after_11:
    // 0x800D0330: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0334: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800D0338: beq         $t9, $zero, L_800D0348
    if (ctx->r25 == 0) {
        // 0x800D033C: nop
    
            goto L_800D0348;
    }
    // 0x800D033C: nop

    // 0x800D0340: b           L_800D0380
    // 0x800D0344: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D0380;
    // 0x800D0344: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D0348:
    // 0x800D0348: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800D034C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D0350: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x800D0354: bne         $at, $zero, L_800D02A8
    if (ctx->r1 != 0) {
        // 0x800D0358: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D02A8;
    }
    // 0x800D0358: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
    // 0x800D035C: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0360: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D0364: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D0368: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
    // 0x800D036C: lbu         $t3, 0x64($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X64);
    // 0x800D0370: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D0374: bne         $at, $zero, L_800D0254
    if (ctx->r1 != 0) {
        // 0x800D0378: nop
    
            goto L_800D0254;
    }
    // 0x800D0378: nop

L_800D037C:
    // 0x800D037C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D0380:
    // 0x800D0380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0384: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x800D0388: jr          $ra
    // 0x800D038C: nop

    return;
    // 0x800D038C: nop

;}
RECOMP_FUNC void timetrial_init_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B4FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B504: sb          $zero, -0x38C8($at)
    MEM_B(-0X38C8, ctx->r1) = 0;
    // 0x8001B508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B50C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B510: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B518: jal         0x8006EA90
    // 0x8001B51C: sb          $zero, -0x38CC($at)
    MEM_B(-0X38CC, ctx->r1) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8001B51C: sb          $zero, -0x38CC($at)
    MEM_B(-0X38CC, ctx->r1) = 0;
    after_0:
    // 0x8001B520: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8001B524: jal         0x8006B0AC
    // 0x8001B528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8001B528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001B52C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B530: lh          $t6, -0x517E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X517E);
    // 0x8001B534: nop

    // 0x8001B538: bne         $v0, $t6, L_8001B62C
    if (ctx->r2 != ctx->r14) {
        // 0x8001B53C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B62C;
    }
    // 0x8001B53C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B540: jal         0x8001E29C
    // 0x8001B544: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8001B544: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8001B548: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8001B54C: jal         0x8001E29C
    // 0x8001B550: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8001B550: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001B554: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001B558: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B55C: lb          $t7, 0x0($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X0);
    // 0x8001B560: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8001B564: beq         $a3, $t7, L_8001B594
    if (ctx->r7 == ctx->r15) {
        // 0x8001B568: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B594;
    }
    // 0x8001B568: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B56C: lb          $t8, 0x0($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X0);
    // 0x8001B570: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8001B574: beq         $s0, $t8, L_8001B598
    if (ctx->r16 == ctx->r24) {
        // 0x8001B578: addu        $t9, $t0, $a2
        ctx->r25 = ADD32(ctx->r8, ctx->r6);
            goto L_8001B598;
    }
    // 0x8001B578: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B57C:
    // 0x8001B57C: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001B580: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B584: beq         $a3, $a1, L_8001B594
    if (ctx->r7 == ctx->r5) {
        // 0x8001B588: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B594;
    }
    // 0x8001B588: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B58C: bne         $s0, $a1, L_8001B57C
    if (ctx->r16 != ctx->r5) {
        // 0x8001B590: nop
    
            goto L_8001B57C;
    }
    // 0x8001B590: nop

L_8001B594:
    // 0x8001B594: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B598:
    // 0x8001B598: lb          $t1, 0x0($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X0);
    // 0x8001B59C: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8001B5A0: beq         $a3, $t1, L_8001B628
    if (ctx->r7 == ctx->r9) {
        // 0x8001B5A4: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_8001B628;
    }
    // 0x8001B5A4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001B5A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B5AC: lh          $t6, -0x517E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X517E);
    // 0x8001B5B0: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8001B5B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001B5B8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8001B5BC: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B5C0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001B5C4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001B5C8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8001B5CC: nop

    // 0x8001B5D0: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B5D4: bne         $at, $zero, L_8001B62C
    if (ctx->r1 != 0) {
        // 0x8001B5D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B62C;
    }
    // 0x8001B5D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B5DC: jal         0x8009EB08
    // 0x8001B5E0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    get_eeprom_settings(rdram, ctx);
        goto after_4;
    // 0x8001B5E0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001B5E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B5E8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8001B5EC: sllv        $t5, $t6, $a2
    ctx->r13 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8001B5F0: sra         $t8, $t5, 31
    ctx->r24 = S32(SIGNED(ctx->r13) >> 31);
    // 0x8001B5F4: and         $t2, $v0, $t8
    ctx->r10 = ctx->r2 & ctx->r24;
    // 0x8001B5F8: bne         $t2, $zero, L_8001B610
    if (ctx->r10 != 0) {
        // 0x8001B5FC: and         $t3, $v1, $t5
        ctx->r11 = ctx->r3 & ctx->r13;
            goto L_8001B610;
    }
    // 0x8001B5FC: and         $t3, $v1, $t5
    ctx->r11 = ctx->r3 & ctx->r13;
    // 0x8001B600: bne         $t3, $zero, L_8001B610
    if (ctx->r11 != 0) {
        // 0x8001B604: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001B610;
    }
    // 0x8001B604: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B608: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B60C: sb          $t7, -0x38C8($at)
    MEM_B(-0X38C8, ctx->r1) = ctx->r15;
L_8001B610:
    // 0x8001B610: jal         0x8001B2F0
    // 0x8001B614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_load_staff_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001B618: bne         $v0, $zero, L_8001B628
    if (ctx->r2 != 0) {
        // 0x8001B61C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8001B628;
    }
    // 0x8001B61C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B620: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B624: sb          $t1, -0x38CC($at)
    MEM_B(-0X38CC, ctx->r1) = ctx->r9;
L_8001B628:
    // 0x8001B628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B62C:
    // 0x8001B62C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B630: lbu         $v0, -0x38CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X38CC);
    // 0x8001B634: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B638: jr          $ra
    // 0x8001B63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001B63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D54: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80024D58: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80024D5C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80024D60: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80024D64: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80024D68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80024D6C: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80024D70: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80024D74: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80024D78: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x80024D7C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80024D80: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024D84: addiu       $s1, $s1, -0x4F60
    ctx->r17 = ADD32(ctx->r17, -0X4F60);
    // 0x80024D88: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80024D8C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024D90: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024D94: addiu       $s2, $s2, -0x4F5C
    ctx->r18 = ADD32(ctx->r18, -0X4F5C);
    // 0x80024D98: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80024D9C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80024DA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DA4: sw          $t3, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r11;
    // 0x80024DA8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80024DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DB0: sw          $t5, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = ctx->r13;
    // 0x80024DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80024DBC: sw          $t6, -0x4F24($at)
    MEM_W(-0X4F24, ctx->r1) = ctx->r14;
    // 0x80024DC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DC4: sw          $zero, -0x4F3C($at)
    MEM_W(-0X4F3C, ctx->r1) = 0;
    // 0x80024DC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DCC: sw          $zero, -0x4F40($at)
    MEM_W(-0X4F40, ctx->r1) = 0;
    // 0x80024DD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DD8: lw          $a0, -0x2C84($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C84);
    // 0x80024DDC: jal         0x8006652C
    // 0x80024DE0: sw          $zero, -0x4F44($at)
    MEM_W(-0X4F44, ctx->r1) = 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80024DE0: sw          $zero, -0x4F44($at)
    MEM_W(-0X4F44, ctx->r1) = 0;
    after_0:
    // 0x80024DE4: jal         0x8006EAA0
    // 0x80024DE8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x80024DE8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80024DEC: beq         $v0, $zero, L_80024DFC
    if (ctx->r2 == 0) {
        // 0x80024DF0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80024DFC;
    }
    // 0x80024DF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80024DF4: b           L_80024E08
    // 0x80024DF8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_80024E08;
    // 0x80024DF8: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_80024DFC:
    // 0x80024DFC: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E00: nop

    // 0x80024E04: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
L_80024E08:
    // 0x80024E08: lw          $t8, -0x2C7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C7C);
    // 0x80024E0C: nop

    // 0x80024E10: beq         $t8, $zero, L_80024E28
    if (ctx->r24 == 0) {
        // 0x80024E14: lw          $a2, 0xA0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XA0);
            goto L_80024E28;
    }
    // 0x80024E14: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E18: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80024E1C: jal         0x800B9C18
    // 0x80024E20: nop

    waves_update(rdram, ctx);
        goto after_2;
    // 0x80024E20: nop

    after_2:
    // 0x80024E24: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
L_80024E28:
    // 0x80024E28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024E2C: jal         0x8002D8DC
    // 0x80024E30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    shadow_update(rdram, ctx);
        goto after_3;
    // 0x80024E30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80024E34: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024E38: lw          $v1, -0x36E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X36E4);
    // 0x80024E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024E40: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
L_80024E44:
    // 0x80024E44: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x80024E48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024E4C: beq         $a0, $at, L_80024E70
    if (ctx->r4 == ctx->r1) {
        // 0x80024E50: nop
    
            goto L_80024E70;
    }
    // 0x80024E50: nop

    // 0x80024E54: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024E58: jal         0x8007F24C
    // 0x80024E5C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    update_colour_cycle(rdram, ctx);
        goto after_4;
    // 0x80024E5C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x80024E60: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024E64: lw          $v1, -0x36E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X36E4);
    // 0x80024E68: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80024E6C: nop

L_80024E70:
    // 0x80024E70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80024E74: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80024E78: bne         $at, $zero, L_80024E44
    if (ctx->r1 != 0) {
        // 0x80024E7C: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_80024E44;
    }
    // 0x80024E7C: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80024E80: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x80024E84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024E88: beq         $a0, $at, L_80024EA8
    if (ctx->r4 == ctx->r1) {
        // 0x80024E8C: nop
    
            goto L_80024EA8;
    }
    // 0x80024E8C: nop

    // 0x80024E90: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024E94: jal         0x8007F460
    // 0x80024E98: nop

    update_pulsating_light_data(rdram, ctx);
        goto after_5;
    // 0x80024E98: nop

    after_5:
    // 0x80024E9C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024EA0: lw          $v1, -0x36E4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X36E4);
    // 0x80024EA4: nop

L_80024EA8:
    // 0x80024EA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024EAC: addiu       $a0, $a0, -0x4F20
    ctx->r4 = ADD32(ctx->r4, -0X4F20);
    // 0x80024EB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80024EB4: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80024EB8: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024EBC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024EC0: bne         $v0, $at, L_80024EE0
    if (ctx->r2 != ctx->r1) {
        // 0x80024EC4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80024EE0;
    }
    // 0x80024EC4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024EC8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80024ECC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024ED0: sw          $t1, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r9;
    // 0x80024ED4: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024ED8: nop

    // 0x80024EDC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80024EE0:
    // 0x80024EE0: beq         $v0, $at, L_80024EF4
    if (ctx->r2 == ctx->r1) {
        // 0x80024EE4: nop
    
            goto L_80024EF4;
    }
    // 0x80024EE4: nop

    // 0x80024EE8: lb          $t2, 0xBD($v1)
    ctx->r10 = MEM_B(ctx->r3, 0XBD);
    // 0x80024EEC: nop

    // 0x80024EF0: beq         $t2, $zero, L_80024EFC
    if (ctx->r10 == 0) {
        // 0x80024EF4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80024EFC;
    }
L_80024EF4:
    // 0x80024EF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024EF8: sw          $t1, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r9;
L_80024EFC:
    // 0x80024EFC: lb          $t3, 0x49($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X49);
    // 0x80024F00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024F04: bne         $t3, $at, L_80024F9C
    if (ctx->r11 != ctx->r1) {
        // 0x80024F08: nop
    
            goto L_80024F9C;
    }
    // 0x80024F08: nop

    // 0x80024F0C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x80024F10: lb          $t7, 0xA2($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA2);
    // 0x80024F14: lw          $t4, 0xA4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA4);
    // 0x80024F18: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024F1C: lbu         $t0, 0x0($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X0);
    // 0x80024F20: lh          $t6, 0xA8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA8);
    // 0x80024F24: sll         $t5, $t0, 9
    ctx->r13 = S32(ctx->r8 << 9);
    // 0x80024F28: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x80024F2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024F30: addiu       $v0, $v0, -0x36E4
    ctx->r2 = ADD32(ctx->r2, -0X36E4);
    // 0x80024F34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80024F38: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80024F3C: addiu       $a2, $a2, -0x4EF0
    ctx->r6 = ADD32(ctx->r6, -0X4EF0);
    // 0x80024F40: addiu       $a1, $a1, -0x4EEC
    ctx->r5 = ADD32(ctx->r5, -0X4EEC);
    // 0x80024F44: mflo        $t8
    ctx->r24 = lo;
    // 0x80024F48: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80024F4C: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x80024F50: sh          $t2, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r10;
    // 0x80024F54: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80024F58: nop

    // 0x80024F5C: lb          $t7, 0xA3($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA3);
    // 0x80024F60: lw          $t3, 0xA4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA4);
    // 0x80024F64: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024F68: lbu         $t0, 0x1($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X1);
    // 0x80024F6C: lh          $t5, 0xAA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XAA);
    // 0x80024F70: sll         $t4, $t0, 9
    ctx->r12 = S32(ctx->r8 << 9);
    // 0x80024F74: addiu       $t0, $t4, -0x1
    ctx->r8 = ADD32(ctx->r12, -0X1);
    // 0x80024F78: mflo        $t6
    ctx->r14 = lo;
    // 0x80024F7C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80024F80: and         $t9, $t8, $t0
    ctx->r25 = ctx->r24 & ctx->r8;
    // 0x80024F84: sh          $t9, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r25;
    // 0x80024F88: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80024F8C: nop

    // 0x80024F90: lw          $a0, 0xA4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XA4);
    // 0x80024F94: jal         0x8007EF80
    // 0x80024F98: nop

    tex_animate_texture(rdram, ctx);
        goto after_6;
    // 0x80024F98: nop

    after_6:
L_80024F9C:
    // 0x80024F9C: jal         0x8009C30C
    // 0x80024FA0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    get_filtered_cheats(rdram, ctx);
        goto after_7;
    // 0x80024FA0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    after_7:
    // 0x80024FA4: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80024FA8: beq         $t3, $zero, L_80024FB8
    if (ctx->r11 == 0) {
        // 0x80024FAC: lui         $t7, 0xA000
        ctx->r15 = S32(0XA000 << 16);
            goto L_80024FB8;
    }
    // 0x80024FAC: lui         $t7, 0xA000
    ctx->r15 = S32(0XA000 << 16);
    // 0x80024FB0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80024FB4: sb          $t4, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r12;
L_80024FB8:
    // 0x80024FB8: lui         $t5, 0xAC29
    ctx->r13 = S32(0XAC29 << 16);
    // 0x80024FBC: lui         $at, 0xAC29
    ctx->r1 = S32(0XAC29 << 16);
    // 0x80024FC0: beq         $t5, $at, L_80024FCC
    if (ctx->r13 == ctx->r1) {
        // 0x80024FC4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80024FCC;
    }
    // 0x80024FC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80024FC8: sb          $t6, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r14;
L_80024FCC:
    // 0x80024FCC: jal         0x8007B3D0
    // 0x80024FD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x80024FD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80024FD4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80024FD8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80024FDC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80024FE0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80024FE4: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80024FE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80024FEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024FF0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80024FF4: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x80024FF8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80024FFC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025000: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025004: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025008: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002500C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025010: lui         $t5, 0xF900
    ctx->r13 = S32(0XF900 << 16);
    // 0x80025014: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025018: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002501C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80025020: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80025024: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025028: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002502C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80025030: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025034: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80025038: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002503C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80025040: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80025044: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025048: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8002504C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80025050: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80025054: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80025058: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002505C: jal         0x800AD40C
    // 0x80025060: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rain_fog(rdram, ctx);
        goto after_9;
    // 0x80025060: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_9:
    // 0x80025064: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80025068: jal         0x80030838
    // 0x8002506C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    update_fog(rdram, ctx);
        goto after_10;
    // 0x8002506C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80025070: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80025074: jal         0x800AF404
    // 0x80025078: nop

    scroll_particle_textures(rdram, ctx);
        goto after_11;
    // 0x80025078: nop

    after_11:
    // 0x8002507C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80025080: lw          $t5, -0x36E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X36E8);
    // 0x80025084: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80025088: lh          $t6, 0x1E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X1E);
    // 0x8002508C: nop

    // 0x80025090: blez        $t6, L_800250A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80025094: nop
    
            goto L_800250A0;
    }
    // 0x80025094: nop

    // 0x80025098: jal         0x80027E24
    // 0x8002509C: nop

    track_tex_anim(rdram, ctx);
        goto after_12;
    // 0x8002509C: nop

    after_12:
L_800250A0:
    // 0x800250A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800250A4: addiu       $s0, $s0, -0x4F4C
    ctx->r16 = ADD32(ctx->r16, -0X4F4C);
    // 0x800250A8: slt         $at, $zero, $s3
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800250AC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800250B0: beq         $at, $zero, L_800252AC
    if (ctx->r1 == 0) {
        // 0x800250B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800252AC;
    }
    // 0x800250B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800250B8:
    // 0x800250B8: bne         $v0, $zero, L_800250E0
    if (ctx->r2 != 0) {
        // 0x800250BC: lb          $t9, 0x83($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X83);
            goto L_800250E0;
    }
    // 0x800250BC: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x800250C0: jal         0x8000E184
    // 0x800250C4: nop

    is_player_two_in_control(rdram, ctx);
        goto after_13;
    // 0x800250C4: nop

    after_13:
    // 0x800250C8: beq         $v0, $zero, L_800250DC
    if (ctx->r2 == 0) {
        // 0x800250CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800250DC;
    }
    // 0x800250CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800250D0: bne         $s3, $at, L_800250DC
    if (ctx->r19 != ctx->r1) {
        // 0x800250D4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800250DC;
    }
    // 0x800250D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800250D8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800250DC:
    // 0x800250DC: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
L_800250E0:
    // 0x800250E0: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x800250E4: beq         $t9, $zero, L_80025104
    if (ctx->r25 == 0) {
        // 0x800250E8: nop
    
            goto L_80025104;
    }
    // 0x800250E8: nop

    // 0x800250EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800250F0: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x800250F4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800250F8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800250FC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025100: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025104:
    // 0x80025104: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80025108: jal         0x8003093C
    // 0x8002510C: nop

    apply_fog(rdram, ctx);
        goto after_14;
    // 0x8002510C: nop

    after_14:
    // 0x80025110: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025114: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025118: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002511C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025124: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025128: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002512C: jal         0x800665E8
    // 0x80025130: nop

    set_active_camera(rdram, ctx);
        goto after_15;
    // 0x80025130: nop

    after_15:
    extern void dkr_split_screen_viewport_fill(uint8_t*, recomp_context*); dkr_split_screen_viewport_fill(rdram, ctx);
    // 0x80025134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025138: jal         0x80066CDC
    // 0x8002513C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_16;
    // 0x8002513C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x80025140: jal         0x8002A31C
    // 0x80025144: nop

    func_8002A31C(rdram, ctx);
        goto after_17;
    // 0x80025144: nop

    after_17:
    // 0x80025148: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x8002514C: beq         $at, $zero, L_8002519C
    if (ctx->r1 == 0) {
        // 0x80025150: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002519C;
    }
    // 0x80025150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025158: jal         0x80068408
    // 0x8002515C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_18;
    // 0x8002515C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x80025160: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80025164: lw          $t6, -0x36E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36E4);
    // 0x80025168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002516C: lb          $t8, 0x49($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X49);
    // 0x80025170: nop

    // 0x80025174: bne         $t8, $at, L_8002518C
    if (ctx->r24 != ctx->r1) {
        // 0x80025178: nop
    
            goto L_8002518C;
    }
    // 0x80025178: nop

    // 0x8002517C: jal         0x80028050
    // 0x80025180: nop

    trackbg_render_flashy(rdram, ctx);
        goto after_19;
    // 0x80025180: nop

    after_19:
    // 0x80025184: b           L_800251C8
    // 0x80025188: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_800251C8;
    // 0x80025188: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8002518C:
    // 0x8002518C: jal         0x80028C10
    // 0x80025190: nop

    skydome_render(rdram, ctx);
        goto after_20;
    // 0x80025190: nop

    after_20:
    // 0x80025194: b           L_800251C8
    // 0x80025198: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_800251C8;
    // 0x80025198: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8002519C:
    // 0x8002519C: jal         0x8006807C
    // 0x800251A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_21;
    // 0x800251A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x800251A4: jal         0x800289B8
    // 0x800251A8: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_22;
    // 0x800251A8: nop

    after_22:
    // 0x800251AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251B0: jal         0x80067D3C
    // 0x800251B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_23;
    // 0x800251B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    extern void dkr_split_screen_world_aspect_begin(uint8_t*, recomp_context*); dkr_split_screen_world_aspect_begin(rdram, ctx);
    // 0x800251B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251BC: jal         0x80068408
    // 0x800251C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_24;
    // 0x800251C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x800251C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800251C8:
    // 0x800251C8: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800251CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800251D0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800251D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800251D8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800251DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800251E0: jal         0x80028CD0
    // 0x800251E4: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_25;
    // 0x800251E4: nop

    after_25:
    // 0x800251E8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800251EC: jal         0x800AB308
    // 0x800251F0: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_26;
    // 0x800251F0: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_26:
    // 0x800251F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800251F8: lw          $t3, -0x36E4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X36E4);
    // 0x800251FC: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x80025200: lh          $t4, 0x90($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X90);
    // 0x80025204: nop

    // 0x80025208: blez        $t4, L_80025238
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002520C: nop
    
            goto L_80025238;
    }
    // 0x8002520C: nop

    // 0x80025210: beq         $at, $zero, L_80025238
    if (ctx->r1 == 0) {
        // 0x80025214: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80025238;
    }
    // 0x80025214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025218: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8002521C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025220: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025224: addiu       $a3, $a3, -0x4F54
    ctx->r7 = ADD32(ctx->r7, -0X4F54);
    // 0x80025228: addiu       $a2, $a2, -0x4F58
    ctx->r6 = ADD32(ctx->r6, -0X4F58);
    // 0x8002522C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025230: jal         0x800ABE68
    // 0x80025234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    weather_update(rdram, ctx);
        goto after_27;
    // 0x80025234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_27:
L_80025238:
    // 0x80025238: jal         0x80069D20
    // 0x8002523C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_28;
    // 0x8002523C: nop

    after_28:
    // 0x80025240: jal         0x800AD030
    // 0x80025244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_29;
    // 0x80025244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x80025248: jal         0x80069D20
    // 0x8002524C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_30;
    // 0x8002524C: nop

    after_30:
    // 0x80025250: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025254: addiu       $a2, $a2, -0x4F58
    ctx->r6 = ADD32(ctx->r6, -0X4F58);
    // 0x80025258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002525C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025260: jal         0x800ACA20
    // 0x80025264: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_31;
    // 0x80025264: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_31:
    extern void dkr_split_screen_world_aspect_end(uint8_t*, recomp_context*); dkr_split_screen_world_aspect_end(rdram, ctx);
    // 0x80025268: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002526C: jal         0x8001BB18
    // 0x80025270: nop

    get_racer_object_by_port(rdram, ctx);
        goto after_32;
    // 0x80025270: nop

    after_32:
    // 0x80025274: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80025278: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002527C: addiu       $a2, $a2, -0x4F58
    ctx->r6 = ADD32(ctx->r6, -0X4F58);
    // 0x80025280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025284: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025288: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8002528C: jal         0x800A01A0
    // 0x80025290: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    hud_render_player(rdram, ctx);
        goto after_33;
    // 0x80025290: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_33:
    // 0x80025294: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80025298: nop

    // 0x8002529C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800252A0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800252A4: bne         $at, $zero, L_800250B8
    if (ctx->r1 != 0) {
        // 0x800252A8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800250B8;
    }
    // 0x800252A8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800252AC:
    // 0x800252AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800252B0: bne         $s3, $at, L_80025464
    if (ctx->r19 != ctx->r1) {
        // 0x800252B4: nop
    
            goto L_80025464;
    }
    // 0x800252B4: nop

    // 0x800252B8: jal         0x8006BD98
    // 0x800252BC: nop

    level_type(rdram, ctx);
        goto after_34;
    // 0x800252BC: nop

    after_34:
    // 0x800252C0: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800252C4: beq         $v0, $at, L_80025464
    if (ctx->r2 == ctx->r1) {
        // 0x800252C8: nop
    
            goto L_80025464;
    }
    // 0x800252C8: nop

    // 0x800252CC: jal         0x8006BD98
    // 0x800252D0: nop

    level_type(rdram, ctx);
        goto after_35;
    // 0x800252D0: nop

    after_35:
    // 0x800252D4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800252D8: beq         $v0, $at, L_80025464
    if (ctx->r2 == ctx->r1) {
        // 0x800252DC: nop
    
            goto L_80025464;
    }
    // 0x800252DC: nop

    // 0x800252E0: jal         0x8006BD98
    // 0x800252E4: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x800252E4: nop

    after_36:
    // 0x800252E8: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800252EC: beq         $v0, $at, L_80025464
    if (ctx->r2 == ctx->r1) {
        // 0x800252F0: nop
    
            goto L_80025464;
    }
    // 0x800252F0: nop

    // 0x800252F4: jal         0x800A8458
    // 0x800252F8: nop

    hud_setting(rdram, ctx);
        goto after_37;
    // 0x800252F8: nop

    after_37:
    // 0x800252FC: bne         $v0, $zero, L_80025450
    if (ctx->r2 != 0) {
        // 0x80025300: nop
    
            goto L_80025450;
    }
    // 0x80025300: nop

    // 0x80025304: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x80025308: nop

    // 0x8002530C: beq         $t9, $zero, L_80025330
    if (ctx->r25 == 0) {
        // 0x80025310: nop
    
            goto L_80025330;
    }
    // 0x80025310: nop

    // 0x80025314: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025318: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8002531C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025320: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025324: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025328: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8002532C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025330:
    // 0x80025330: jal         0x8003093C
    // 0x80025334: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    apply_fog(rdram, ctx);
        goto after_38;
    // 0x80025334: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x80025338: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002533C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025340: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025344: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025348: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002534C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025350: jal         0x800665E8
    // 0x80025354: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    set_active_camera(rdram, ctx);
        goto after_39;
    // 0x80025354: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_39:
    // 0x80025358: jal         0x80066520
    // 0x8002535C: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_40;
    // 0x8002535C: nop

    after_40:
    // 0x80025360: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80025364: jal         0x800278E8
    // 0x80025368: nop

    ttcam_update(rdram, ctx);
        goto after_41;
    // 0x80025368: nop

    after_41:
    extern void dkr_split_screen_viewport_fill(uint8_t*, recomp_context*); dkr_split_screen_viewport_fill(rdram, ctx);
    // 0x8002536C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025370: jal         0x80066CDC
    // 0x80025374: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_42;
    // 0x80025374: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_42:
    // 0x80025378: jal         0x8002A31C
    // 0x8002537C: nop

    func_8002A31C(rdram, ctx);
        goto after_43;
    // 0x8002537C: nop

    after_43:
    // 0x80025380: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025384: jal         0x8006807C
    // 0x80025388: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_44;
    // 0x80025388: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_44:
    // 0x8002538C: jal         0x800289B8
    // 0x80025390: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_45;
    // 0x80025390: nop

    after_45:
    // 0x80025394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025398: jal         0x80067D3C
    // 0x8002539C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_46;
    // 0x8002539C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_46:
    extern void dkr_split_screen_world_aspect_begin(uint8_t*, recomp_context*); dkr_split_screen_world_aspect_begin(rdram, ctx);
    // 0x800253A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253A4: jal         0x80068408
    // 0x800253A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_47;
    // 0x800253A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_47:
    // 0x800253AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800253B0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800253B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800253B8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800253BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800253C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800253C4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800253C8: jal         0x80028CD0
    // 0x800253CC: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_48;
    // 0x800253CC: nop

    after_48:
    // 0x800253D0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800253D4: jal         0x800AB308
    // 0x800253D8: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_49;
    // 0x800253D8: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_49:
    // 0x800253DC: jal         0x80069D20
    // 0x800253E0: nop

    cam_get_active_camera(rdram, ctx);
        goto after_50;
    // 0x800253E0: nop

    after_50:
    // 0x800253E4: jal         0x800AD030
    // 0x800253E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_51;
    // 0x800253E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x800253EC: jal         0x80069D20
    // 0x800253F0: nop

    cam_get_active_camera(rdram, ctx);
        goto after_52;
    // 0x800253F0: nop

    after_52:
    // 0x800253F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800253F8: addiu       $a2, $a2, -0x4F58
    ctx->r6 = ADD32(ctx->r6, -0X4F58);
    // 0x800253FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025400: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025404: jal         0x800ACA20
    // 0x80025408: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_53;
    // 0x80025408: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_53:
    extern void dkr_split_screen_world_aspect_end(uint8_t*, recomp_context*); dkr_split_screen_world_aspect_end(rdram, ctx);
    // 0x8002540C: jal         0x800C42EC
    // 0x80025410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_54;
    // 0x80025410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80025414: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80025418: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8002541C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025420: bne         $t9, $zero, L_80025434
    if (ctx->r25 != 0) {
        // 0x80025424: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_80025434;
    }
    // 0x80025424: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80025428: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // 0x8002542C: b           L_8002543C
    // 0x80025430: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
        goto L_8002543C;
    // 0x80025430: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
L_80025434:
    // 0x80025434: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80025438: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
L_8002543C:
    // 0x8002543C: addiu       $a3, $a3, 0x5DF0
    ctx->r7 = ADD32(ctx->r7, 0X5DF0);
    // 0x80025440: jal         0x800C4440
    // 0x80025444: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    draw_text(rdram, ctx);
        goto after_55;
    // 0x80025444: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_55:
    // 0x80025448: b           L_80025464
    // 0x8002544C: nop

        goto L_80025464;
    // 0x8002544C: nop

L_80025450:
    // 0x80025450: jal         0x800665E8
    // 0x80025454: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    set_active_camera(rdram, ctx);
        goto after_56;
    // 0x80025454: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_56:
    // 0x80025458: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8002545C: jal         0x800278E8
    // 0x80025460: nop

    ttcam_update(rdram, ctx);
        goto after_57;
    // 0x80025460: nop

    after_57:
L_80025464:
    // 0x80025464: jal         0x800682AC
    // 0x80025468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_reset(rdram, ctx);
        goto after_58;
    // 0x80025468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_58:
    // 0x8002546C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025470: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80025474: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025478: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8002547C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025480: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80025484: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025488: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8002548C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80025490: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80025494: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025498: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x8002549C: addiu       $a1, $a1, -0x4F38
    ctx->r5 = ADD32(ctx->r5, -0X4F38);
    // 0x800254A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800254A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800254A8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800254AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800254B0: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800254B4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800254B8: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x800254BC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800254C0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800254C4: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x800254C8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800254CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800254D0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800254D4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800254D8: lw          $t7, -0x4F58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F58);
    // 0x800254DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800254E0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x800254E4: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x800254E8: lw          $t5, -0x4F54($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F54);
    // 0x800254EC: nop

    // 0x800254F0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800254F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800254F8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800254FC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80025500: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80025504: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80025508: jr          $ra
    // 0x8002550C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002550C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void update_particle_texture_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2FBC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B2FC0: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800B2FC4: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2FC8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B2FCC: bne         $t6, $at, L_800B2FF0
    if (ctx->r14 != ctx->r1) {
        // 0x800B2FD0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800B2FF0;
    }
    // 0x800B2FD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B2FD4: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x800B2FD8: nop

    // 0x800B2FDC: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B2FE0: nop

    // 0x800B2FE4: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800B2FE8: b           L_800B3008
    // 0x800B2FEC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800B3008;
    // 0x800B2FEC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800B2FF0:
    // 0x800B2FF0: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x800B2FF4: nop

    // 0x800B2FF8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800B2FFC: nop

    // 0x800B3000: lhu         $a1, 0x12($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X12);
    // 0x800B3004: nop

L_800B3008:
    // 0x800B3008: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x800B300C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800B3010: addiu       $t4, $t4, 0x7C80
    ctx->r12 = ADD32(ctx->r12, 0X7C80);
    // 0x800B3014: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x800B3018: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B301C: slt         $t7, $zero, $t3
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B3020: andi        $a2, $a3, 0x1
    ctx->r6 = ctx->r7 & 0X1;
    // 0x800B3024: andi        $t0, $a3, 0x2
    ctx->r8 = ctx->r7 & 0X2;
    // 0x800B3028: andi        $t1, $a3, 0x4
    ctx->r9 = ctx->r7 & 0X4;
    // 0x800B302C: beq         $t7, $zero, L_800B3134
    if (ctx->r15 == 0) {
        // 0x800B3030: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_800B3134;
    }
    // 0x800B3030: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x800B3034: addiu       $s0, $zero, -0x9
    ctx->r16 = ADD32(0, -0X9);
    // 0x800B3038: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
L_800B303C:
    // 0x800B303C: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B3040: lh          $t3, 0x1A($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X1A);
    // 0x800B3044: bne         $t2, $zero, L_800B30BC
    if (ctx->r10 != 0) {
        // 0x800B3048: subu        $t6, $a3, $t3
        ctx->r14 = SUB32(ctx->r7, ctx->r11);
            goto L_800B30BC;
    }
    // 0x800B3048: subu        $t6, $a3, $t3
    ctx->r14 = SUB32(ctx->r7, ctx->r11);
    // 0x800B304C: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x800B3050: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x800B3054: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B3058: nop

    // 0x800B305C: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B3060: bne         $at, $zero, L_800B3118
    if (ctx->r1 != 0) {
        // 0x800B3064: nop
    
            goto L_800B3118;
    }
    // 0x800B3064: nop

    // 0x800B3068: beq         $t0, $zero, L_800B3090
    if (ctx->r8 == 0) {
        // 0x800B306C: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B3090;
    }
    // 0x800B306C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800B3070: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B3074: subu        $t6, $t9, $a3
    ctx->r14 = SUB32(ctx->r25, ctx->r7);
    // 0x800B3078: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B307C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800B3080: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B3084: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B3088: b           L_800B3118
    // 0x800B308C: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3118;
    // 0x800B308C: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B3090:
    // 0x800B3090: beq         $t1, $zero, L_800B30A4
    if (ctx->r9 == 0) {
        // 0x800B3094: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_800B30A4;
    }
    // 0x800B3094: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B3098: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x800B309C: b           L_800B3118
    // 0x800B30A0: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3118;
    // 0x800B30A0: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B30A4:
    // 0x800B30A4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B30A8: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B30AC: and         $t9, $t8, $t5
    ctx->r25 = ctx->r24 & ctx->r13;
    // 0x800B30B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B30B4: b           L_800B3118
    // 0x800B30B8: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3118;
    // 0x800B30B8: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B30BC:
    // 0x800B30BC: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x800B30C0: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B30C4: nop

    // 0x800B30C8: bgez        $a3, L_800B3118
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800B30CC: nop
    
            goto L_800B3118;
    }
    // 0x800B30CC: nop

    // 0x800B30D0: beq         $t1, $zero, L_800B3104
    if (ctx->r9 == 0) {
        // 0x800B30D4: nop
    
            goto L_800B3104;
    }
    // 0x800B30D4: nop

    // 0x800B30D8: beq         $a2, $zero, L_800B30FC
    if (ctx->r6 == 0) {
        // 0x800B30DC: addu        $t6, $a3, $a1
        ctx->r14 = ADD32(ctx->r7, ctx->r5);
            goto L_800B30FC;
    }
    // 0x800B30DC: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x800B30E0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B30E4: negu        $t7, $a3
    ctx->r15 = SUB32(0, ctx->r7);
    // 0x800B30E8: and         $t9, $t8, $s0
    ctx->r25 = ctx->r24 & ctx->r16;
    // 0x800B30EC: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B30F0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B30F4: b           L_800B3118
    // 0x800B30F8: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3118;
    // 0x800B30F8: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B30FC:
    // 0x800B30FC: b           L_800B3118
    // 0x800B3100: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3118;
    // 0x800B3100: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B3104:
    // 0x800B3104: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x800B3108: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800B310C: and         $t8, $t7, $t5
    ctx->r24 = ctx->r15 & ctx->r13;
    // 0x800B3110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3114: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
L_800B3118:
    // 0x800B3118: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800B311C: nop

    // 0x800B3120: slt         $t3, $v1, $t9
    ctx->r11 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B3124: beq         $t3, $zero, L_800B3134
    if (ctx->r11 == 0) {
        // 0x800B3128: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B3134;
    }
    // 0x800B3128: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B312C: bne         $v0, $zero, L_800B303C
    if (ctx->r2 != 0) {
        // 0x800B3130: nop
    
            goto L_800B303C;
    }
    // 0x800B3130: nop

L_800B3134:
    // 0x800B3134: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800B3138: jr          $ra
    // 0x800B313C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B313C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void menu_adventure_track_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093600: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80093604: lw          $t6, 0x63E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63E0);
    // 0x80093608: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009360C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093610: bgez        $t6, L_80093630
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80093614: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80093630;
    }
    // 0x80093614: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80093618: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009361C: lw          $v0, -0xB3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB3C);
    // 0x80093620: nop

    // 0x80093624: ori         $t7, $v0, 0x80
    ctx->r15 = ctx->r2 | 0X80;
    // 0x80093628: b           L_800939FC
    // 0x8009362C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800939FC;
    // 0x8009362C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80093630:
    // 0x80093630: jal         0x8006EA90
    // 0x80093634: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80093634: nop

    after_0:
    // 0x80093638: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009363C: lw          $t9, -0xB3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB3C);
    // 0x80093640: lw          $t8, 0x4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4C);
    // 0x80093644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80093648: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8009364C: lb          $a0, 0x2($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X2);
    // 0x80093650: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80093654: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80093658: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8009365C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80093660: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80093664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093668: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8009366C: beq         $t4, $zero, L_80093678
    if (ctx->r12 == 0) {
        // 0x80093670: andi        $t5, $v1, 0x4
        ctx->r13 = ctx->r3 & 0X4;
            goto L_80093678;
    }
    // 0x80093670: andi        $t5, $v1, 0x4
    ctx->r13 = ctx->r3 & 0X4;
    // 0x80093674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80093678:
    // 0x80093678: beq         $t5, $zero, L_80093684
    if (ctx->r13 == 0) {
        // 0x8009367C: nop
    
            goto L_80093684;
    }
    // 0x8009367C: nop

    // 0x80093680: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80093684:
    // 0x80093684: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80093688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009368C: jal         0x8006B14C
    // 0x80093690: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    leveltable_type(rdram, ctx);
        goto after_1;
    // 0x80093690: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80093694: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80093698: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x8009369C: beq         $t6, $zero, L_800936A8
    if (ctx->r14 == 0) {
        // 0x800936A0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800936A8;
    }
    // 0x800936A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800936A4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_800936A8:
    // 0x800936A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800936AC: jal         0x8000E4C8
    // 0x800936B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    is_time_trial_enabled(rdram, ctx);
        goto after_2;
    // 0x800936B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x800936B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800936B8: bne         $v0, $zero, L_800936F8
    if (ctx->r2 != 0) {
        // 0x800936BC: nop
    
            goto L_800936F8;
    }
    // 0x800936BC: nop

    // 0x800936C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800936C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800936C8: bne         $t8, $at, L_800936F8
    if (ctx->r24 != ctx->r1) {
        // 0x800936CC: nop
    
            goto L_800936F8;
    }
    // 0x800936CC: nop

    // 0x800936D0: lbu         $v0, 0x48($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X48);
    // 0x800936D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800936D8: beq         $v0, $at, L_800936F0
    if (ctx->r2 == ctx->r1) {
        // 0x800936DC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800936F0;
    }
    // 0x800936DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800936E0: lhu         $t9, 0xC($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XC);
    // 0x800936E4: sllv        $t1, $t0, $v0
    ctx->r9 = S32(ctx->r8 << (ctx->r2 & 31));
    // 0x800936E8: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800936EC: beq         $t2, $zero, L_800936F8
    if (ctx->r10 == 0) {
        // 0x800936F0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800936F8;
    }
L_800936F0:
    // 0x800936F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800936F4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_800936F8:
    // 0x800936F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800936FC: addiu       $v0, $v0, 0x63BC
    ctx->r2 = ADD32(ctx->r2, 0X63BC);
    // 0x80093700: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80093704: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80093708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009370C: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80093710: andi        $t6, $t5, 0x3F
    ctx->r14 = ctx->r13 & 0X3F;
    // 0x80093714: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80093718: jal         0x80092E94
    // 0x8009371C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    adventuretrack_render(rdram, ctx);
        goto after_3;
    // 0x8009371C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_3:
    // 0x80093720: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80093724: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093728: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8009372C: beq         $at, $zero, L_80093744
    if (ctx->r1 == 0) {
        // 0x80093730: nop
    
            goto L_80093744;
    }
    // 0x80093730: nop

    // 0x80093734: jal         0x8006B0AC
    // 0x80093738: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_4;
    // 0x80093738: nop

    after_4:
    // 0x8009373C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093740: sb          $v0, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r2;
L_80093744:
    // 0x80093744: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80093748: lb          $v1, 0x69C0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X69C0);
    // 0x8009374C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093750: jal         0x8006B0F8
    // 0x80093754: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_5;
    // 0x80093754: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x80093758: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8009375C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80093760: jal         0x8008E4EC
    // 0x80093764: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    menu_input(rdram, ctx);
        goto after_6;
    // 0x80093764: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80093768: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009376C: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x80093770: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80093774: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80093778: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009377C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093780: bne         $v0, $zero, L_80093970
    if (ctx->r2 != 0) {
        // 0x80093784: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80093970;
    }
    // 0x80093784: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80093788: addiu       $a3, $a3, 0x63E0
    ctx->r7 = ADD32(ctx->r7, 0X63E0);
    // 0x8009378C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80093790: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80093794: bne         $t8, $zero, L_800937B4
    if (ctx->r24 != 0) {
        // 0x80093798: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800937B4;
    }
    // 0x80093798: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009379C: bne         $t0, $zero, L_800937B4
    if (ctx->r8 != 0) {
        // 0x800937A0: nop
    
            goto L_800937B4;
    }
    // 0x800937A0: nop

    // 0x800937A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800937A8: nop

    // 0x800937AC: beq         $t9, $zero, L_8009386C
    if (ctx->r25 == 0) {
        // 0x800937B0: nop
    
            goto L_8009386C;
    }
    // 0x800937B0: nop

L_800937B4:
    // 0x800937B4: lw          $v0, 0x67D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67D8);
    // 0x800937B8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800937BC: andi        $t1, $v0, 0x9000
    ctx->r9 = ctx->r2 & 0X9000;
    // 0x800937C0: beq         $t1, $zero, L_80093808
    if (ctx->r9 == 0) {
        // 0x800937C4: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_80093808;
    }
    // 0x800937C4: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x800937C8: beq         $t2, $zero, L_800937E4
    if (ctx->r10 == 0) {
        // 0x800937CC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800937E4;
    }
    // 0x800937CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800937D0: jal         0x800C31EC
    // 0x800937D4: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x800937D4: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_7:
    // 0x800937D8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800937DC: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x800937E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_800937E4:
    // 0x800937E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800937E8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800937EC: jal         0x800C01D8
    // 0x800937F0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x800937F0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_8:
    // 0x800937F4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800937F8: jal         0x80001D04
    // 0x800937FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800937FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80093800: b           L_800939F0
    // 0x80093804: nop

        goto L_800939F0;
    // 0x80093804: nop

L_80093808:
    // 0x80093808: beq         $t4, $zero, L_800939F0
    if (ctx->r12 == 0) {
        // 0x8009380C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800939F0;
    }
    // 0x8009380C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80093810: jal         0x80001D04
    // 0x80093814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80093814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80093818: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8009381C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80093820: bne         $t5, $zero, L_80093834
    if (ctx->r13 != 0) {
        // 0x80093824: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80093834;
    }
    // 0x80093824: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80093828: beq         $t6, $zero, L_80093864
    if (ctx->r14 == 0) {
        // 0x8009382C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80093864;
    }
    // 0x8009382C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093830: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80093834:
    // 0x80093834: nop

    // 0x80093838: beq         $t7, $zero, L_80093848
    if (ctx->r15 == 0) {
        // 0x8009383C: nop
    
            goto L_80093848;
    }
    // 0x8009383C: nop

    // 0x80093840: jal         0x800C31EC
    // 0x80093844: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_11;
    // 0x80093844: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_11:
L_80093848:
    // 0x80093848: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009384C: jal         0x800C01D8
    // 0x80093850: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80093850: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_12:
    // 0x80093854: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80093858: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009385C: b           L_800939F0
    // 0x80093860: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
        goto L_800939F0;
    // 0x80093860: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
L_80093864:
    // 0x80093864: b           L_800939F0
    // 0x80093868: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
        goto L_800939F0;
    // 0x80093868: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
L_8009386C:
    // 0x8009386C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093870: lw          $v0, 0x67D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67D8);
    // 0x80093874: nop

    // 0x80093878: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x8009387C: beq         $t0, $zero, L_800938AC
    if (ctx->r8 == 0) {
        // 0x80093880: andi        $t1, $v0, 0x9000
        ctx->r9 = ctx->r2 & 0X9000;
            goto L_800938AC;
    }
    // 0x80093880: andi        $t1, $v0, 0x9000
    ctx->r9 = ctx->r2 & 0X9000;
    // 0x80093884: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80093888: jal         0x80001D04
    // 0x8009388C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x8009388C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80093890: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093894: jal         0x800C01D8
    // 0x80093898: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_14;
    // 0x80093898: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_14:
    // 0x8009389C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800938A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800938A4: b           L_800939F0
    // 0x800938A8: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
        goto L_800939F0;
    // 0x800938A8: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
L_800938AC:
    // 0x800938AC: beq         $t1, $zero, L_800938CC
    if (ctx->r9 == 0) {
        // 0x800938B0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800938CC;
    }
    // 0x800938B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800938B4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800938B8: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x800938BC: jal         0x80001D04
    // 0x800938C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800938C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800938C4: b           L_800939F0
    // 0x800938C8: nop

        goto L_800939F0;
    // 0x800938C8: nop

L_800938CC:
    // 0x800938CC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800938D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800938D4: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800938D8: bne         $at, $zero, L_800939F0
    if (ctx->r1 != 0) {
        // 0x800938DC: nop
    
            goto L_800939F0;
    }
    // 0x800938DC: nop

    // 0x800938E0: lh          $v0, 0x6830($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6830);
    // 0x800938E4: nop

    // 0x800938E8: blez        $v0, L_80093910
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800938EC: nop
    
            goto L_80093910;
    }
    // 0x800938EC: nop

L_800938F0:
    // 0x800938F0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800938F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800938F8: sllv        $t5, $t4, $v1
    ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x800938FC: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x80093900: bne         $t6, $zero, L_80093910
    if (ctx->r14 != 0) {
        // 0x80093904: nop
    
            goto L_80093910;
    }
    // 0x80093904: nop

    // 0x80093908: bgez        $v1, L_800938F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009390C: nop
    
            goto L_800938F0;
    }
    // 0x8009390C: nop

L_80093910:
    // 0x80093910: bgez        $v0, L_80093938
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80093914: nop
    
            goto L_80093938;
    }
    // 0x80093914: nop

L_80093918:
    // 0x80093918: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009391C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093920: sllv        $t8, $t7, $v1
    ctx->r24 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x80093924: and         $t0, $t8, $a0
    ctx->r8 = ctx->r24 & ctx->r4;
    // 0x80093928: bne         $t0, $zero, L_80093938
    if (ctx->r8 != 0) {
        // 0x8009392C: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80093938;
    }
    // 0x8009392C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80093930: bne         $at, $zero, L_80093918
    if (ctx->r1 != 0) {
        // 0x80093934: nop
    
            goto L_80093918;
    }
    // 0x80093934: nop

L_80093938:
    // 0x80093938: bltz        $v1, L_80093948
    if (SIGNED(ctx->r3) < 0) {
        // 0x8009393C: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80093948;
    }
    // 0x8009393C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80093940: bne         $at, $zero, L_8009394C
    if (ctx->r1 != 0) {
        // 0x80093944: nop
    
            goto L_8009394C;
    }
    // 0x80093944: nop

L_80093948:
    // 0x80093948: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8009394C:
    // 0x8009394C: beq         $v1, $a1, L_800939F0
    if (ctx->r3 == ctx->r5) {
        // 0x80093950: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800939F0;
    }
    // 0x80093950: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80093954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093958: jal         0x80001D04
    // 0x8009395C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x8009395C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_16:
    // 0x80093960: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80093964: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093968: b           L_800939F0
    // 0x8009396C: sb          $v1, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r3;
        goto L_800939F0;
    // 0x8009396C: sb          $v1, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r3;
L_80093970:
    // 0x80093970: bgez        $v0, L_80093990
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80093974: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80093990;
    }
    // 0x80093974: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80093978: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8009397C: nop

    // 0x80093980: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x80093984: b           L_8009399C
    // 0x80093988: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_8009399C;
    // 0x80093988: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x8009398C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_80093990:
    // 0x80093990: nop

    // 0x80093994: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80093998: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8009399C:
    // 0x8009399C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800939A0: nop

    // 0x800939A4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800939A8: beq         $at, $zero, L_800939B8
    if (ctx->r1 == 0) {
        // 0x800939AC: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800939B8;
    }
    // 0x800939AC: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800939B0: beq         $at, $zero, L_800939F0
    if (ctx->r1 == 0) {
        // 0x800939B4: nop
    
            goto L_800939F0;
    }
    // 0x800939B4: nop

L_800939B8:
    // 0x800939B8: jal         0x80093A0C
    // 0x800939BC: nop

    adventuretrack_free(rdram, ctx);
        goto after_17;
    // 0x800939BC: nop

    after_17:
    // 0x800939C0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800939C4: lw          $t4, -0xB84($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB84);
    // 0x800939C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800939CC: blez        $t4, L_800939E8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800939D0: nop
    
            goto L_800939E8;
    }
    // 0x800939D0: nop

    // 0x800939D4: lw          $v0, -0xB3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB3C);
    // 0x800939D8: nop

    // 0x800939DC: ori         $t5, $v0, 0x80
    ctx->r13 = ctx->r2 | 0X80;
    // 0x800939E0: b           L_800939FC
    // 0x800939E4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800939FC;
    // 0x800939E4: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800939E8:
    // 0x800939E8: b           L_800939FC
    // 0x800939EC: addiu       $v0, $zero, 0x103
    ctx->r2 = ADD32(0, 0X103);
        goto L_800939FC;
    // 0x800939EC: addiu       $v0, $zero, 0x103
    ctx->r2 = ADD32(0, 0X103);
L_800939F0:
    // 0x800939F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800939F4: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x800939F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800939FC:
    // 0x800939FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80093A04: jr          $ra
    // 0x80093A08: nop

    return;
    // 0x80093A08: nop

;}
RECOMP_FUNC void void_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025510: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80025514: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025518: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002551C: addiu       $t1, $t1, -0x2B46
    ctx->r9 = ADD32(ctx->r9, -0X2B46);
    // 0x80025520: addiu       $a2, $a2, -0x2B44
    ctx->r6 = ADD32(ctx->r6, -0X2B44);
    // 0x80025524: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025528: addiu       $t6, $zero, 0xAF
    ctx->r14 = ADD32(0, 0XAF);
    // 0x8002552C: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80025530: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80025534: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002553C: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
    // 0x80025540: bne         $at, $zero, L_80025558
    if (ctx->r1 != 0) {
        // 0x80025544: sh          $t7, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r15;
            goto L_80025558;
    }
    // 0x80025544: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80025548: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8002554C: nop

    // 0x80025550: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80025554: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80025558:
    // 0x80025558: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x8002555C: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x80025560: sll         $a3, $t0, 2
    ctx->r7 = S32(ctx->r8 << 2);
    // 0x80025564: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80025568: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x8002556C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80025570: sll         $t6, $t0, 5
    ctx->r14 = S32(ctx->r8 << 5);
    // 0x80025574: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x80025578: addiu       $t3, $t2, 0x30
    ctx->r11 = ADD32(ctx->r10, 0X30);
    // 0x8002557C: addiu       $a3, $t5, 0xC8
    ctx->r7 = ADD32(ctx->r13, 0XC8);
    // 0x80025580: addiu       $t0, $t6, 0xA0
    ctx->r8 = ADD32(ctx->r14, 0XA0);
    // 0x80025584: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80025588: addiu       $t4, $v1, 0x5
    ctx->r12 = ADD32(ctx->r3, 0X5);
    // 0x8002558C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80025590: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80025594: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80025598: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8002559C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800255A0: jal         0x80070C9C
    // 0x800255A4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800255A4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    after_0:
    // 0x800255A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800255AC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800255B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800255B4: addu        $t2, $a3, $t0
    ctx->r10 = ADD32(ctx->r7, ctx->r8);
    // 0x800255B8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800255BC: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800255C0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800255C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800255C8: addiu       $a2, $a2, -0x2B8C
    ctx->r6 = ADD32(ctx->r6, -0X2B8C);
    // 0x800255CC: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800255D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800255D4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800255D8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800255DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800255E0: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x800255E4: jal         0x80070C9C
    // 0x800255E8: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800255E8: nop

    after_1:
    // 0x800255EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800255F0: addiu       $a0, $a0, -0x36DC
    ctx->r4 = ADD32(ctx->r4, -0X36DC);
    // 0x800255F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800255F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800255FC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80025600: addiu       $a2, $a2, -0x2B8C
    ctx->r6 = ADD32(ctx->r6, -0X2B8C);
    // 0x80025604: beq         $v0, $zero, L_800257B8
    if (ctx->r2 == 0) {
        // 0x80025608: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800257B8;
    }
    // 0x80025608: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002560C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80025610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025614: sw          $v0, -0x2B88($at)
    MEM_W(-0X2B88, ctx->r1) = ctx->r2;
    // 0x80025618: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002561C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025620: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x80025624: sw          $v1, -0x2B84($at)
    MEM_W(-0X2B84, ctx->r1) = ctx->r3;
    // 0x80025628: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8002562C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80025630: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80025634: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80025638: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002563C: blez        $s0, L_800257B8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025640: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800257B8;
    }
    // 0x80025640: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025644: andi        $t1, $s0, 0x3
    ctx->r9 = ctx->r16 & 0X3;
    // 0x80025648: beq         $t1, $zero, L_800256A4
    if (ctx->r9 == 0) {
        // 0x8002564C: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_800256A4;
    }
    // 0x8002564C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80025650: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
L_80025654:
    // 0x80025654: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025658: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002565C: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025660: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x80025664: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025668: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8002566C: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025670: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x80025674: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025678: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8002567C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025680: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x80025684: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025688: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8002568C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025690: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x80025694: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025698: bne         $a1, $a0, L_80025654
    if (ctx->r5 != ctx->r4) {
        // 0x8002569C: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_80025654;
    }
    // 0x8002569C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800256A0: beq         $a0, $s0, L_800257B8
    if (ctx->r4 == ctx->r16) {
        // 0x800256A4: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_800257B8;
    }
L_800256A4:
    // 0x800256A4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800256A8: sll         $a1, $s0, 4
    ctx->r5 = S32(ctx->r16 << 4);
L_800256AC:
    // 0x800256AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800256B0: nop

    // 0x800256B4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256B8: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800256BC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800256C0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256C4: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800256C8: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x800256CC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800256D0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800256D8: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x800256DC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800256E0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800256E8: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x800256EC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800256F0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256F4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256F8: sw          $v1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r3;
    // 0x800256FC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025700: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025704: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025708: sw          $v1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r3;
    // 0x8002570C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025710: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025714: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025718: sw          $v1, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r3;
    // 0x8002571C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025720: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025724: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025728: sw          $v1, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r3;
    // 0x8002572C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025730: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025734: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025738: sw          $v1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r3;
    // 0x8002573C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025740: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025744: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025748: sw          $v1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r3;
    // 0x8002574C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025750: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025754: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025758: sw          $v1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r3;
    // 0x8002575C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025760: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025764: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025768: sw          $v1, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r3;
    // 0x8002576C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025770: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025774: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025778: sw          $v1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r3;
    // 0x8002577C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025780: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025784: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025788: sw          $v1, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r3;
    // 0x8002578C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025790: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025794: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025798: sw          $v1, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r3;
    // 0x8002579C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800257A0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257A4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800257A8: sw          $v1, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r3;
    // 0x800257AC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800257B0: bne         $v0, $a1, L_800256AC
    if (ctx->r2 != ctx->r5) {
        // 0x800257B4: addu        $v1, $v1, $a3
        ctx->r3 = ADD32(ctx->r3, ctx->r7);
            goto L_800256AC;
    }
    // 0x800257B4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
L_800257B8:
    // 0x800257B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800257BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800257C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800257C4: sb          $zero, -0x2B4C($at)
    MEM_B(-0X2B4C, ctx->r1) = 0;
    // 0x800257C8: jr          $ra
    // 0x800257CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800257CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_drumstick_unlock_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D8A4: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8006D8A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006D8AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D8B0: sb          $t6, -0x2C70($at)
    MEM_B(-0X2C70, ctx->r1) = ctx->r14;
    // 0x8006D8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D8B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D8BC: jal         0x800945E4
    // 0x8006D8C0: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_0;
    // 0x8006D8C0: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    after_0:
    // 0x8006D8C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006D8C8: jal         0x800C01D8
    // 0x8006D8CC: addiu       $a0, $a0, -0x2BF8
    ctx->r4 = ADD32(ctx->r4, -0X2BF8);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006D8CC: addiu       $a0, $a0, -0x2BF8
    ctx->r4 = ADD32(ctx->r4, -0X2BF8);
    after_1:
    // 0x8006D8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D8D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D8D8: jr          $ra
    // 0x8006D8DC: nop

    return;
    // 0x8006D8DC: nop

;}
RECOMP_FUNC void get_active_player_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C3D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C3E0: jal         0x8006BDB0
    // 0x8009C3E4: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x8009C3E4: nop

    after_0:
    // 0x8009C3E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C3EC: lw          $t6, -0xB40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB40);
    // 0x8009C3F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C3F4: beq         $t6, $zero, L_8009C42C
    if (ctx->r14 == 0) {
        // 0x8009C3F8: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C42C;
    }
    // 0x8009C3F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C3FC: lw          $t7, -0xB48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB48);
    // 0x8009C400: nop

    // 0x8009C404: bne         $t7, $zero, L_8009C42C
    if (ctx->r15 != 0) {
        // 0x8009C408: nop
    
            goto L_8009C42C;
    }
    // 0x8009C408: nop

    // 0x8009C40C: lb          $v1, 0x4C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X4C);
    // 0x8009C410: nop

    // 0x8009C414: beq         $v1, $zero, L_8009C424
    if (ctx->r3 == 0) {
        // 0x8009C418: andi        $t8, $v1, 0x40
        ctx->r24 = ctx->r3 & 0X40;
            goto L_8009C424;
    }
    // 0x8009C418: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x8009C41C: beq         $t8, $zero, L_8009C42C
    if (ctx->r24 == 0) {
        // 0x8009C420: nop
    
            goto L_8009C42C;
    }
    // 0x8009C420: nop

L_8009C424:
    // 0x8009C424: b           L_8009C438
    // 0x8009C428: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8009C438;
    // 0x8009C428: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8009C42C:
    // 0x8009C42C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C430: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8009C434: nop

L_8009C438:
    // 0x8009C438: jr          $ra
    // 0x8009C43C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009C43C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void write_controller_pak_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800766D4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800766D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800766DC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800766E0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800766E4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800766E8: jal         0x800758DC
    // 0x800766EC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800766EC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x800766F0: beq         $v0, $zero, L_80076710
    if (ctx->r2 == 0) {
        // 0x800766F4: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_80076710;
    }
    // 0x800766F4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800766F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800766FC: jal         0x80075AEC
    // 0x80076700: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076700: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x80076704: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076708: b           L_80076918
    // 0x8007670C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80076918;
    // 0x8007670C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076710:
    // 0x80076710: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80076714: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80076718: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8007671C: beq         $v0, $zero, L_8007672C
    if (ctx->r2 == 0) {
        // 0x80076720: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8007672C;
    }
    // 0x80076720: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80076724: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x80076728: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_8007672C:
    // 0x8007672C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80076730: jal         0x80076A38
    // 0x80076734: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    string_to_font_codes(rdram, ctx);
        goto after_2;
    // 0x80076734: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x80076738: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8007673C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80076740: jal         0x80076A38
    // 0x80076744: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_3;
    // 0x80076744: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80076748: jal         0x8009EB20
    // 0x8007674C: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x8007674C: nop

    after_4:
    // 0x80076750: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80076754: bne         $v0, $at, L_8007676C
    if (ctx->r2 != ctx->r1) {
        // 0x80076758: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_8007676C;
    }
    // 0x80076758: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8007675C: lui         $t6, 0x4E44
    ctx->r14 = S32(0X4E44 << 16);
    // 0x80076760: ori         $t6, $t6, 0x594A
    ctx->r14 = ctx->r14 | 0X594A;
    // 0x80076764: b           L_80076790
    // 0x80076768: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_80076790;
    // 0x80076768: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_8007676C:
    // 0x8007676C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80076770: lui         $t9, 0x4E44
    ctx->r25 = S32(0X4E44 << 16);
    // 0x80076774: bne         $t7, $zero, L_8007678C
    if (ctx->r15 != 0) {
        // 0x80076778: ori         $t9, $t9, 0x5945
        ctx->r25 = ctx->r25 | 0X5945;
            goto L_8007678C;
    }
    // 0x80076778: ori         $t9, $t9, 0x5945
    ctx->r25 = ctx->r25 | 0X5945;
    // 0x8007677C: lui         $t8, 0x4E44
    ctx->r24 = S32(0X4E44 << 16);
    // 0x80076780: ori         $t8, $t8, 0x5950
    ctx->r24 = ctx->r24 | 0X5950;
    // 0x80076784: b           L_80076790
    // 0x80076788: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80076790;
    // 0x80076788: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8007678C:
    // 0x8007678C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80076790:
    // 0x80076790: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076794: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80076798: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8007679C: jal         0x800764E8
    // 0x800767A0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_5;
    // 0x800767A0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800767A4: bne         $v0, $zero, L_800767D4
    if (ctx->r2 != 0) {
        // 0x800767A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800767D4;
    }
    // 0x800767A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800767AC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800767B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800767B4: beq         $v0, $at, L_80076868
    if (ctx->r2 == ctx->r1) {
        // 0x800767B8: nop
    
            goto L_80076868;
    }
    // 0x800767B8: nop

    // 0x800767BC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800767C0: nop

    // 0x800767C4: beq         $v0, $t0, L_80076868
    if (ctx->r2 == ctx->r8) {
        // 0x800767C8: nop
    
            goto L_80076868;
    }
    // 0x800767C8: nop

    // 0x800767CC: b           L_80076868
    // 0x800767D0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076868;
    // 0x800767D0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800767D4:
    // 0x800767D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800767D8: bne         $v0, $at, L_80076868
    if (ctx->r2 != ctx->r1) {
        // 0x800767DC: nop
    
            goto L_80076868;
    }
    // 0x800767DC: nop

    // 0x800767E0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800767E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800767E8: beq         $t1, $at, L_800767F8
    if (ctx->r9 == ctx->r1) {
        // 0x800767EC: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800767F8;
    }
    // 0x800767EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800767F0: b           L_80076868
    // 0x800767F4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076868;
    // 0x800767F4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800767F8:
    // 0x800767F8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800767FC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80076800: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80076804: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80076808: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007680C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80076810: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80076814: addiu       $t4, $t4, 0x4018
    ctx->r12 = ADD32(ctx->r12, 0X4018);
    // 0x80076818: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8007681C: addiu       $t5, $sp, 0x3C
    ctx->r13 = ADD32(ctx->r29, 0X3C);
    // 0x80076820: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80076824: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80076828: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007682C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076830: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x80076834: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x80076838: jal         0x800D1040
    // 0x8007683C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_6;
    // 0x8007683C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80076840: bne         $v0, $zero, L_80076850
    if (ctx->r2 != 0) {
        // 0x80076844: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80076850;
    }
    // 0x80076844: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80076848: b           L_80076868
    // 0x8007684C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076868;
    // 0x8007684C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076850:
    // 0x80076850: beq         $v0, $at, L_80076860
    if (ctx->r2 == ctx->r1) {
        // 0x80076854: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80076860;
    }
    // 0x80076854: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80076858: bne         $v0, $at, L_80076868
    if (ctx->r2 != ctx->r1) {
        // 0x8007685C: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076868;
    }
    // 0x8007685C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076860:
    // 0x80076860: b           L_80076868
    // 0x80076864: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076868;
    // 0x80076864: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076868:
    // 0x80076868: bne         $v1, $zero, L_80076900
    if (ctx->r3 != 0) {
        // 0x8007686C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80076900;
    }
    // 0x8007686C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80076870: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80076874: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076878: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007687C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80076880: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80076884: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80076888: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007688C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80076890: addiu       $t0, $t0, 0x4018
    ctx->r8 = ADD32(ctx->r8, 0X4018);
    // 0x80076894: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80076898: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8007689C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800768A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800768A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800768A8: jal         0x800CEFDC
    // 0x800768AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_7;
    // 0x800768AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_7:
    // 0x800768B0: bne         $v0, $zero, L_800768C0
    if (ctx->r2 != 0) {
        // 0x800768B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800768C0;
    }
    // 0x800768B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800768B8: b           L_80076900
    // 0x800768BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076900;
    // 0x800768BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800768C0:
    // 0x800768C0: beq         $v0, $at, L_800768D0
    if (ctx->r2 == ctx->r1) {
        // 0x800768C4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800768D0;
    }
    // 0x800768C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800768C8: bne         $v0, $at, L_800768DC
    if (ctx->r2 != ctx->r1) {
        // 0x800768CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800768DC;
    }
    // 0x800768CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768D0:
    // 0x800768D0: b           L_80076900
    // 0x800768D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80076900;
    // 0x800768D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800768D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800768DC:
    // 0x800768DC: bne         $v0, $at, L_800768F0
    if (ctx->r2 != ctx->r1) {
        // 0x800768E0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800768F0;
    }
    // 0x800768E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800768E4: b           L_80076900
    // 0x800768E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80076900;
    // 0x800768E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800768EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800768F0:
    // 0x800768F0: bne         $v0, $at, L_80076900
    if (ctx->r2 != ctx->r1) {
        // 0x800768F4: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076900;
    }
    // 0x800768F4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x800768F8: b           L_80076900
    // 0x800768FC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076900;
    // 0x800768FC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076900:
    // 0x80076900: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076904: jal         0x80075AEC
    // 0x80076908: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80076908: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_8:
    // 0x8007690C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076910: nop

    // 0x80076914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076918:
    // 0x80076918: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007691C: jr          $ra
    // 0x80076920: nop

    return;
    // 0x80076920: nop

;}
RECOMP_FUNC void ainode_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D1B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001D1B4: jr          $ra
    // 0x8001D1B8: sw          $t6, -0x50F0($at)
    MEM_W(-0X50F0, ctx->r1) = ctx->r14;
    return;
    // 0x8001D1B8: sw          $t6, -0x50F0($at)
    MEM_W(-0X50F0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8001F3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F3CC: addiu       $v0, $v0, -0x522C
    ctx->r2 = ADD32(ctx->r2, -0X522C);
    // 0x8001F3D0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001F3D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F3D8: beq         $a0, $t6, L_8001F3E4
    if (ctx->r4 == ctx->r14) {
        // 0x8001F3DC: nop
    
            goto L_8001F3E4;
    }
    // 0x8001F3DC: nop

    // 0x8001F3E0: sh          $zero, -0x5188($at)
    MEM_H(-0X5188, ctx->r1) = 0;
L_8001F3E4:
    // 0x8001F3E4: jr          $ra
    // 0x8001F3E8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8001F3E8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mtxs_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA78: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FA7C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FA80: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FA84: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FA88: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FA8C: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FA90: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FA94: nop

    // 0x8006FA98: nop

    // 0x8006FA9C: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FAA0: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FAA4: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FAA8: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FAAC: nop

    // 0x8006FAB0: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FAB4: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x8006FAB8: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FABC: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FAC0: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FAC4: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FAC8: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FACC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FAD0: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FAD4: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FAD8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FADC: nop

    // 0x8006FAE0: nop

    // 0x8006FAE4: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FAE8: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FAEC: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FAF0: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FAF4: nop

    // 0x8006FAF8: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FAFC: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8006FB00: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FB04: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FB08: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FB0C: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FB10: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FB14: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FB18: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB1C: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FB20: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FB24: nop

    // 0x8006FB28: nop

    // 0x8006FB2C: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB30: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FB34: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FB38: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FB3C: nop

    // 0x8006FB40: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB44: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x8006FB48: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FB4C: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FB50: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FB54: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FB58: jr          $ra
    // 0x8006FB5C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FB5C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void obj_init_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DFCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DFD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DFD4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DFD8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DFDC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DFE0: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DFE4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8003DFE8: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8003DFEC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DFF0: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003DFF4: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003DFF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DFFC: jal         0x8009C30C
    // 0x8003E000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003E000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E004: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E008: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E00C: sll         $t2, $v0, 14
    ctx->r10 = S32(ctx->r2 << 14);
    // 0x8003E010: bgez        $t2, L_8003E020
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003E014: andi        $t3, $v0, 0x8000
        ctx->r11 = ctx->r2 & 0X8000;
            goto L_8003E020;
    }
    // 0x8003E014: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8003E018: b           L_8003E068
    // 0x8003E01C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
        goto L_8003E068;
    // 0x8003E01C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
L_8003E020:
    // 0x8003E020: beq         $t3, $zero, L_8003E034
    if (ctx->r11 == 0) {
        // 0x8003E024: sll         $t5, $v0, 15
        ctx->r13 = S32(ctx->r2 << 15);
            goto L_8003E034;
    }
    // 0x8003E024: sll         $t5, $v0, 15
    ctx->r13 = S32(ctx->r2 << 15);
    // 0x8003E028: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003E02C: b           L_8003E068
    // 0x8003E030: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
        goto L_8003E068;
    // 0x8003E030: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
L_8003E034:
    // 0x8003E034: bgez        $t5, L_8003E048
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E038: sll         $t7, $v0, 13
        ctx->r15 = S32(ctx->r2 << 13);
            goto L_8003E048;
    }
    // 0x8003E038: sll         $t7, $v0, 13
    ctx->r15 = S32(ctx->r2 << 13);
    // 0x8003E03C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E040: b           L_8003E068
    // 0x8003E044: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
        goto L_8003E068;
    // 0x8003E044: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
L_8003E048:
    // 0x8003E048: bgez        $t7, L_8003E05C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003E04C: sll         $t9, $v0, 12
        ctx->r25 = S32(ctx->r2 << 12);
            goto L_8003E05C;
    }
    // 0x8003E04C: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x8003E050: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003E054: b           L_8003E068
    // 0x8003E058: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
        goto L_8003E068;
    // 0x8003E058: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
L_8003E05C:
    // 0x8003E05C: bgez        $t9, L_8003E068
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8003E060: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003E068;
    }
    // 0x8003E060: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003E064: sb          $t0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r8;
L_8003E068:
    // 0x8003E068: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003E06C: nop

    // 0x8003E070: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x8003E074: bne         $at, $zero, L_8003E080
    if (ctx->r1 != 0) {
        // 0x8003E078: nop
    
            goto L_8003E080;
    }
    // 0x8003E078: nop

    // 0x8003E07C: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
L_8003E080:
    // 0x8003E080: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x8003E084: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E088: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003E08C: nop

    // 0x8003E090: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003E094: bne         $at, $zero, L_8003E0A0
    if (ctx->r1 != 0) {
        // 0x8003E098: nop
    
            goto L_8003E0A0;
    }
    // 0x8003E098: nop

    // 0x8003E09C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003E0A0:
    // 0x8003E0A0: lbu         $t5, 0x9($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X9);
    // 0x8003E0A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003E0A8: sb          $t5, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r13;
    // 0x8003E0AC: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E0B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003E0B4: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x8003E0B8: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x8003E0BC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003E0C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003E0C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E0C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E0CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003E0D0: nop

    // 0x8003E0D4: bc1f        L_8003E0E4
    if (!c1cs) {
        // 0x8003E0D8: nop
    
            goto L_8003E0E4;
    }
    // 0x8003E0D8: nop

    // 0x8003E0DC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003E0E0: nop

L_8003E0E4:
    // 0x8003E0E4: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003E0E8: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x8003E0EC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E0F0: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8003E0F4: nop

    // 0x8003E0F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003E0FC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8003E100: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E104: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8003E108: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003E10C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003E110: jal         0x8009C30C
    // 0x8003E114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x8003E114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003E118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E11C: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x8003E120: beq         $t0, $zero, L_8003E134
    if (ctx->r8 == 0) {
        // 0x8003E124: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E134;
    }
    // 0x8003E124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E128: jal         0x8000FFB8
    // 0x8003E12C: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003E12C: nop

    after_2:
    // 0x8003E130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E134:
    // 0x8003E134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E138: jr          $ra
    // 0x8003E13C: nop

    return;
    // 0x8003E13C: nop

;}
RECOMP_FUNC void erase_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007431C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074324: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80074328: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007432C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80074330: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80074334: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074338: jal         0x8006A100
    // 0x8007433C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x8007433C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80074340: jal         0x800CE210
    // 0x80074344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074348: beq         $v0, $zero, L_800744C0
    if (ctx->r2 == 0) {
        // 0x8007434C: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_800744C0;
    }
    // 0x8007434C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80074350: jal         0x8006B224
    // 0x80074354: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_2;
    // 0x80074354: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80074358: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8007435C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80074360: blez        $t6, L_80074394
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80074364: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80074394;
    }
    // 0x80074364: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80074368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007436C:
    // 0x8007436C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80074370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074374: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80074378: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8007437C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80074380: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80074384: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80074388: bne         $at, $zero, L_8007436C
    if (ctx->r1 != 0) {
        // 0x8007438C: nop
    
            goto L_8007436C;
    }
    // 0x8007438C: nop

    // 0x80074390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074394:
    // 0x80074394: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80074398: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8007439C: blez        $t0, L_800743D0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800743A0: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800743D0;
    }
    // 0x800743A0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800743A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800743A8:
    // 0x800743A8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800743AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800743B0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800743B4: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x800743B8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800743BC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800743C0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800743C4: bne         $at, $zero, L_800743A8
    if (ctx->r1 != 0) {
        // 0x800743C8: nop
    
            goto L_800743A8;
    }
    // 0x800743C8: nop

    // 0x800743CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800743D0:
    // 0x800743D0: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x800743D4: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x800743D8: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x800743DC: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x800743E0: beq         $s2, $zero, L_80074404
    if (ctx->r18 == 0) {
        // 0x800743E4: sb          $t4, 0x4B($s1)
        MEM_B(0X4B, ctx->r17) = ctx->r12;
            goto L_80074404;
    }
    // 0x800743E4: sb          $t4, 0x4B($s1)
    MEM_B(0X4B, ctx->r17) = ctx->r12;
    // 0x800743E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800743EC: beq         $s2, $at, L_8007440C
    if (ctx->r18 == ctx->r1) {
        // 0x800743F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007440C;
    }
    // 0x800743F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800743F4: beq         $s2, $at, L_80074414
    if (ctx->r18 == ctx->r1) {
        // 0x800743F8: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_80074414;
    }
    // 0x800743F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800743FC: b           L_80074414
    // 0x80074400: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
        goto L_80074414;
    // 0x80074400: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_80074404:
    // 0x80074404: b           L_80074414
    // 0x80074408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80074414;
    // 0x80074408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8007440C:
    // 0x8007440C: b           L_80074414
    // 0x80074410: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
        goto L_80074414;
    // 0x80074410: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
L_80074414:
    // 0x80074414: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074418: jal         0x80070C9C
    // 0x8007441C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007441C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_3:
    // 0x80074420: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80074424: b           L_80074450
    // 0x80074428: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80074450;
    // 0x80074428: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007442C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074430: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x80074434: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80074438:
    // 0x80074438: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007443C: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80074440: bne         $a1, $s0, L_80074438
    if (ctx->r5 != ctx->r16) {
        // 0x80074444: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80074438;
    }
    // 0x80074444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80074448: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8007444C: beq         $s0, $at, L_80074478
    if (ctx->r16 == ctx->r1) {
        // 0x80074450: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80074478;
    }
L_80074450:
    // 0x80074450: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80074454: sll         $a1, $s2, 3
    ctx->r5 = S32(ctx->r18 << 3);
    // 0x80074458: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
L_8007445C:
    // 0x8007445C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80074460: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80074464: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80074468: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x8007446C: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80074470: bne         $s0, $a1, L_8007445C
    if (ctx->r16 != ctx->r5) {
        // 0x80074474: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8007445C;
    }
    // 0x80074474: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80074478:
    // 0x80074478: jal         0x8006EAC0
    // 0x8007447C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x8007447C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x80074480: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80074484: bne         $v0, $zero, L_800744B8
    if (ctx->r2 != 0) {
        // 0x80074488: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800744B8;
    }
    // 0x80074488: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007448C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
L_80074490:
    // 0x80074490: jal         0x8006A100
    // 0x80074494: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x80074494: nop

    after_5:
    // 0x80074498: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x8007449C: addu        $a2, $t5, $s3
    ctx->r6 = ADD32(ctx->r13, ctx->r19);
    // 0x800744A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800744A4: jal         0x800CE580
    // 0x800744A8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x800744A8: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x800744AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800744B0: bne         $s0, $s2, L_80074490
    if (ctx->r16 != ctx->r18) {
        // 0x800744B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80074490;
    }
    // 0x800744B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800744B8:
    // 0x800744B8: jal         0x80071140
    // 0x800744BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800744BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_800744C0:
    // 0x800744C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800744C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800744C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800744CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800744D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800744D4: jr          $ra
    // 0x800744D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800744D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_init_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038B78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038B88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038B8C: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80038B90: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80038B94: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x80038B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038B9C: lb          $a1, 0x55($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X55);
    // 0x80038BA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80038BA4: jal         0x8006F94C
    // 0x80038BA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80038BA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x80038BAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80038BB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038BB4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80038BB8: sb          $v0, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r2;
    // 0x80038BBC: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80038BC0: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80038BC4: lb          $v1, 0x8($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X8);
    // 0x80038BC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80038BCC: beq         $v1, $zero, L_80038BE0
    if (ctx->r3 == 0) {
        // 0x80038BD0: sll         $t9, $v1, 8
        ctx->r25 = S32(ctx->r3 << 8);
            goto L_80038BE0;
    }
    // 0x80038BD0: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x80038BD4: andi        $t0, $t9, 0xFF00
    ctx->r8 = ctx->r25 & 0XFF00;
    // 0x80038BD8: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80038BDC: sw          $t1, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r9;
L_80038BE0:
    // 0x80038BE0: sw          $t2, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r10;
    // 0x80038BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038BEC: jr          $ra
    // 0x80038BF0: nop

    return;
    // 0x80038BF0: nop

;}
RECOMP_FUNC void cheatmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896A4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800896A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800896AC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800896B0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800896B4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800896B8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800896BC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800896C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800896C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800896C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800896CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800896D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800896D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800896D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800896DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800896E0: jal         0x800C43CC
    // 0x800896E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x800896E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800896E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800896EC: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800896F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800896F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800896F8: jal         0x800C5B58
    // 0x800896FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x800896FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x80089700: jal         0x800C42EC
    // 0x80089704: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80089704: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80089708: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008970C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008971C: jal         0x800C4384
    // 0x80089720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80089720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80089724: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80089728: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8008972C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089730: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80089734: lw          $a3, 0x44($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X44);
    // 0x80089738: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008973C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089740: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80089744: jal         0x800C4440
    // 0x80089748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80089748: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x8008974C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089750: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089754: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089758: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008975C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089760: jal         0x800C4384
    // 0x80089764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80089764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80089768: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008976C: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x80089770: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089774: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089778: lw          $a3, 0x44($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X44);
    // 0x8008977C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089780: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089784: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80089788: jal         0x800C4440
    // 0x8008978C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8008978C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x80089790: addiu       $s3, $zero, 0x41
    ctx->r19 = ADD32(0, 0X41);
    // 0x80089794: jal         0x800C42EC
    // 0x80089798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80089798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8008979C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800897A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800897A4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800897A8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800897AC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800897B0: jal         0x800C4384
    // 0x800897B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x800897B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800897B8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800897BC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800897C0: addiu       $s5, $s5, 0x6C42
    ctx->r21 = ADD32(ctx->r21, 0X6C42);
    // 0x800897C4: addiu       $s6, $s6, 0x6C40
    ctx->r22 = ADD32(ctx->r22, 0X6C40);
    // 0x800897C8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800897CC: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x800897D0: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_800897D4:
    // 0x800897D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800897D8: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_800897DC:
    // 0x800897DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800897E0: lh          $t4, 0x6C46($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C46);
    // 0x800897E4: nop

    // 0x800897E8: bne         $s7, $t4, L_8008984C
    if (ctx->r23 != ctx->r12) {
        // 0x800897EC: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_8008984C;
    }
    // 0x800897EC: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x800897F0: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x800897F4: nop

    // 0x800897F8: bne         $s0, $t5, L_8008984C
    if (ctx->r16 != ctx->r13) {
        // 0x800897FC: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_8008984C;
    }
    // 0x800897FC: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x80089800: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x80089804: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80089808: bne         $fp, $t6, L_80089848
    if (ctx->r30 != ctx->r14) {
        // 0x8008980C: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80089848;
    }
    // 0x8008980C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80089810: lw          $s2, 0x63BC($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X63BC);
    // 0x80089814: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089818: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x8008981C: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80089820: bne         $at, $zero, L_80089830
    if (ctx->r1 != 0) {
        // 0x80089824: or          $s2, $t7, $zero
        ctx->r18 = ctx->r15 | 0;
            goto L_80089830;
    }
    // 0x80089824: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80089828: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x8008982C: subu        $s2, $t8, $t7
    ctx->r18 = SUB32(ctx->r24, ctx->r15);
L_80089830:
    // 0x80089830: sra         $t9, $s2, 1
    ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80089834: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80089838: addiu       $a3, $t9, 0x80
    ctx->r7 = ADD32(ctx->r25, 0X80);
    // 0x8008983C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089840: jal         0x800C4384
    // 0x80089844: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x80089844: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_9:
L_80089848:
    // 0x80089848: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
L_8008984C:
    // 0x8008984C: beq         $at, $zero, L_80089880
    if (ctx->r1 == 0) {
        // 0x80089850: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089880;
    }
    // 0x80089850: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089854: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089858: sb          $s3, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r19;
    // 0x8008985C: sb          $zero, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = 0;
    // 0x80089860: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089864: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089868: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008986C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80089870: jal         0x800C4440
    // 0x80089874: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80089874: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_10:
    // 0x80089878: b           L_800898D4
    // 0x8008987C: nop

        goto L_800898D4;
    // 0x8008987C: nop

L_80089880:
    // 0x80089880: bne         $s0, $s7, L_800898B4
    if (ctx->r16 != ctx->r23) {
        // 0x80089884: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800898B4;
    }
    // 0x80089884: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008988C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80089890: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089894: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089898: addiu       $a3, $a3, -0x7DF0
    ctx->r7 = ADD32(ctx->r7, -0X7DF0);
    // 0x8008989C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800898A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800898A4: jal         0x800C4440
    // 0x800898A8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x800898A8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x800898AC: b           L_800898D4
    // 0x800898B0: nop

        goto L_800898D4;
    // 0x800898B0: nop

L_800898B4:
    // 0x800898B4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800898B8: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800898BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800898C0: addiu       $a3, $a3, -0x7DEC
    ctx->r7 = ADD32(ctx->r7, -0X7DEC);
    // 0x800898C4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800898C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800898CC: jal         0x800C4440
    // 0x800898D0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_12;
    // 0x800898D0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
L_800898D4:
    // 0x800898D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800898D8: lh          $t5, 0x6C46($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C46);
    // 0x800898DC: nop

    // 0x800898E0: bne         $s7, $t5, L_8008991C
    if (ctx->r23 != ctx->r13) {
        // 0x800898E4: nop
    
            goto L_8008991C;
    }
    // 0x800898E4: nop

    // 0x800898E8: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x800898EC: nop

    // 0x800898F0: bne         $s0, $t6, L_8008991C
    if (ctx->r16 != ctx->r14) {
        // 0x800898F4: nop
    
            goto L_8008991C;
    }
    // 0x800898F4: nop

    // 0x800898F8: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x800898FC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089900: bne         $fp, $t7, L_8008991C
    if (ctx->r30 != ctx->r15) {
        // 0x80089904: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008991C;
    }
    // 0x80089904: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089908: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008990C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089910: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089914: jal         0x800C4384
    // 0x80089918: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80089918: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
L_8008991C:
    // 0x8008991C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80089920: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80089924: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80089928: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x8008992C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80089930: bne         $s0, $at, L_800897DC
    if (ctx->r16 != ctx->r1) {
        // 0x80089934: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_800897DC;
    }
    // 0x80089934: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80089938: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8008993C: slti        $at, $fp, 0x4
    ctx->r1 = SIGNED(ctx->r30) < 0X4 ? 1 : 0;
    // 0x80089940: bne         $at, $zero, L_800897D4
    if (ctx->r1 != 0) {
        // 0x80089944: addiu       $s4, $s4, 0x16
        ctx->r20 = ADD32(ctx->r20, 0X16);
            goto L_800897D4;
    }
    // 0x80089944: addiu       $s4, $s4, 0x16
    ctx->r20 = ADD32(ctx->r20, 0X16);
    // 0x80089948: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008994C: lw          $s2, 0x63BC($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X63BC);
    // 0x80089950: nop

    // 0x80089954: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x80089958: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x8008995C: bne         $at, $zero, L_8008996C
    if (ctx->r1 != 0) {
        // 0x80089960: or          $s2, $t1, $zero
        ctx->r18 = ctx->r9 | 0;
            goto L_8008996C;
    }
    // 0x80089960: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x80089964: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x80089968: subu        $s2, $t2, $t1
    ctx->r18 = SUB32(ctx->r10, ctx->r9);
L_8008996C:
    // 0x8008996C: jal         0x800C42EC
    // 0x80089970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80089970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80089974: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x80089978: addiu       $s6, $s6, 0x300
    ctx->r22 = ADD32(ctx->r22, 0X300);
    // 0x8008997C: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80089980: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089984: addiu       $s3, $zero, 0xA4
    ctx->r19 = ADD32(0, 0XA4);
    // 0x80089988: bne         $t3, $zero, L_80089994
    if (ctx->r11 != 0) {
        // 0x8008998C: addiu       $s4, $zero, 0x10
        ctx->r20 = ADD32(0, 0X10);
            goto L_80089994;
    }
    // 0x8008998C: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80089990: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
L_80089994:
    // 0x80089994: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089998: lw          $t4, -0x260($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X260);
    // 0x8008999C: sll         $t5, $fp, 2
    ctx->r13 = S32(ctx->r30 << 2);
    // 0x800899A0: beq         $t4, $zero, L_80089A2C
    if (ctx->r12 == 0) {
        // 0x800899A4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80089A2C;
    }
    // 0x800899A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800899A8: addiu       $t6, $t6, -0x260
    ctx->r14 = ADD32(ctx->r14, -0X260);
    // 0x800899AC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800899B0: addiu       $s5, $s5, 0x63E0
    ctx->r21 = ADD32(ctx->r21, 0X63E0);
    // 0x800899B4: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
L_800899B8:
    // 0x800899B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800899BC: lh          $t7, 0x6C46($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6C46);
    // 0x800899C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800899C4: bne         $fp, $t7, L_800899E0
    if (ctx->r30 != ctx->r15) {
        // 0x800899C8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800899E0;
    }
    // 0x800899C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800899CC: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800899D0: nop

    // 0x800899D4: bne         $t8, $zero, L_800899E4
    if (ctx->r24 != 0) {
        // 0x800899D8: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_800899E4;
    }
    // 0x800899D8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800899DC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_800899E0:
    // 0x800899E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_800899E4:
    // 0x800899E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800899E8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800899EC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800899F0: jal         0x800C4384
    // 0x800899F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x800899F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
    // 0x800899F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800899FC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80089A00: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089A04: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089A08: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089A0C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089A10: jal         0x800C4440
    // 0x80089A14: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80089A14: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x80089A18: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80089A1C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089A20: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80089A24: bne         $t2, $zero, L_800899B8
    if (ctx->r10 != 0) {
        // 0x80089A28: addu        $s3, $s3, $s4
        ctx->r19 = ADD32(ctx->r19, ctx->r20);
            goto L_800899B8;
    }
    // 0x80089A28: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_80089A2C:
    // 0x80089A2C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089A30: addiu       $s5, $s5, 0x63E0
    ctx->r21 = ADD32(ctx->r21, 0X63E0);
    // 0x80089A34: jal         0x800C42EC
    // 0x80089A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80089A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80089A3C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089A40: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089A44: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089A48: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089A4C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089A50: jal         0x800C4384
    // 0x80089A54: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80089A54: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_18:
    // 0x80089A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089A60: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089A64: jal         0x800C43CC
    // 0x80089A68: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_background_colour(rdram, ctx);
        goto after_19;
    // 0x80089A68: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_19:
    // 0x80089A6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089A70: lh          $v0, 0x6C46($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6C46);
    // 0x80089A74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089A78: bne         $v0, $at, L_80089AFC
    if (ctx->r2 != ctx->r1) {
        // 0x80089A7C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80089AFC;
    }
    // 0x80089A7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80089A80: lh          $t0, 0x6C4C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C4C);
    // 0x80089A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089A88: bne         $t0, $at, L_80089AC0
    if (ctx->r8 != ctx->r1) {
        // 0x80089A8C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80089AC0;
    }
    // 0x80089A8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089A90: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089A94: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x80089A98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089A9C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80089AA0: lw          $a3, 0x48($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X48);
    // 0x80089AA4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089AA8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089AAC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089AB0: jal         0x800C4440
    // 0x80089AB4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_20;
    // 0x80089AB4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_20:
    // 0x80089AB8: b           L_80089B60
    // 0x80089ABC: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089B60;
    // 0x80089ABC: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089AC0:
    // 0x80089AC0: lw          $v0, 0x6C30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C30);
    // 0x80089AC4: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80089AC8: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x80089ACC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80089AD0: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80089AD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089AD8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80089ADC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089AE0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089AE4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089AE8: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80089AEC: jal         0x800C4440
    // 0x80089AF0: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80089AF0: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    after_21:
    // 0x80089AF4: b           L_80089B60
    // 0x80089AF8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089B60;
    // 0x80089AF8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089AFC:
    // 0x80089AFC: bne         $s7, $v0, L_80089B30
    if (ctx->r23 != ctx->r2) {
        // 0x80089B00: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80089B30;
    }
    // 0x80089B00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80089B04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089B08: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80089B0C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089B10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089B14: addiu       $a3, $a3, 0x6C58
    ctx->r7 = ADD32(ctx->r7, 0X6C58);
    // 0x80089B18: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089B1C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089B20: jal         0x800C4440
    // 0x80089B24: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x80089B24: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_22:
    // 0x80089B28: b           L_80089B60
    // 0x80089B2C: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089B60;
    // 0x80089B2C: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089B30:
    // 0x80089B30: bne         $v0, $at, L_80089B5C
    if (ctx->r2 != ctx->r1) {
        // 0x80089B34: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089B5C;
    }
    // 0x80089B34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089B38: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80089B3C: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80089B40: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089B44: lw          $a3, 0x4C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4C);
    // 0x80089B48: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089B4C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089B50: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089B54: jal         0x800C4440
    // 0x80089B58: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_23;
    // 0x80089B58: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_23:
L_80089B5C:
    // 0x80089B5C: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089B60:
    // 0x80089B60: nop

    // 0x80089B64: beq         $t4, $zero, L_80089C8C
    if (ctx->r12 == 0) {
        // 0x80089B68: nop
    
            goto L_80089C8C;
    }
    // 0x80089B68: nop

    // 0x80089B6C: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x80089B70: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089B74: bne         $t5, $zero, L_80089B84
    if (ctx->r13 != 0) {
        // 0x80089B78: addiu       $s3, $zero, 0x78
        ctx->r19 = ADD32(0, 0X78);
            goto L_80089B84;
    }
    // 0x80089B78: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x80089B7C: b           L_80089B84
    // 0x80089B80: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
        goto L_80089B84;
    // 0x80089B80: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
L_80089B84:
    // 0x80089B84: jal         0x800C5494
    // 0x80089B88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_24;
    // 0x80089B88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_24:
    // 0x80089B8C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089B90: jal         0x800C4F7C
    // 0x80089B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_25;
    // 0x80089B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80089B98: addiu       $t6, $s3, 0x1C
    ctx->r14 = ADD32(ctx->r19, 0X1C);
    // 0x80089B9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089BA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089BA4: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80089BA8: addiu       $a2, $s3, -0x1C
    ctx->r6 = ADD32(ctx->r19, -0X1C);
    // 0x80089BAC: jal         0x800C4EDC
    // 0x80089BB0: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_26;
    // 0x80089BB0: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_26:
    // 0x80089BB4: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80089BB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80089BBC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089BC8: jal         0x800C4FBC
    // 0x80089BCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_27;
    // 0x80089BCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_27:
    // 0x80089BD0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80089BD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80089BD8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_80089BDC:
    // 0x80089BDC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089BE0: bne         $fp, $zero, L_80089BF4
    if (ctx->r30 != 0) {
        // 0x80089BE4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80089BF4;
    }
    // 0x80089BE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80089BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089BEC: b           L_80089C08
    // 0x80089BF0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_80089C08;
    // 0x80089BF0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_80089BF4:
    // 0x80089BF4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80089BF8: nop

    // 0x80089BFC: bne         $fp, $t8, L_80089C0C
    if (ctx->r30 != ctx->r24) {
        // 0x80089C00: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80089C0C;
    }
    // 0x80089C00: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089C04: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80089C08:
    // 0x80089C08: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80089C0C:
    // 0x80089C0C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80089C10: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089C14: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089C18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80089C1C: jal         0x800C5000
    // 0x80089C20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    set_current_text_colour(rdram, ctx);
        goto after_28;
    // 0x80089C20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_28:
    // 0x80089C24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089C28: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x80089C2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80089C30: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80089C34: lw          $a3, 0x250($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X250);
    // 0x80089C38: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80089C3C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80089C40: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089C44: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089C48: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089C4C: jal         0x800C5168
    // 0x80089C50: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x80089C50: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_29:
    // 0x80089C54: beq         $fp, $zero, L_80089C64
    if (ctx->r30 == 0) {
        // 0x80089C58: nop
    
            goto L_80089C64;
    }
    // 0x80089C58: nop

    // 0x80089C5C: b           L_80089C68
    // 0x80089C60: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
        goto L_80089C68;
    // 0x80089C60: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_80089C64:
    // 0x80089C64: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
L_80089C68:
    // 0x80089C68: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089C6C: bne         $fp, $s4, L_80089BDC
    if (ctx->r30 != ctx->r20) {
        // 0x80089C70: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80089BDC;
    }
    // 0x80089C70: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80089C74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089C78: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089C80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089C84: jal         0x800C5B58
    // 0x80089C88: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_30;
    // 0x80089C88: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_30:
L_80089C8C:
    // 0x80089C8C: jal         0x8009C30C
    // 0x80089C90: nop

    get_filtered_cheats(rdram, ctx);
        goto after_31;
    // 0x80089C90: nop

    after_31:
    // 0x80089C94: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80089C98: bgez        $t5, L_80089CAC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80089C9C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80089CAC;
    }
    // 0x80089C9C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80089CA0: jal         0x8008AD44
    // 0x80089CA4: nop

    cheatmenu_checksum(rdram, ctx);
        goto after_32;
    // 0x80089CA4: nop

    after_32:
    // 0x80089CA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80089CAC:
    // 0x80089CAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089CB0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80089CB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80089CB8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80089CBC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80089CC0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80089CC4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80089CC8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80089CCC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80089CD0: jr          $ra
    // 0x80089CD4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80089CD4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void get_character_id_from_slot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C228: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C22C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C230: lb          $v0, 0x63F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X63F0);
    // 0x8009C234: jr          $ra
    // 0x8009C238: nop

    return;
    // 0x8009C238: nop

;}
RECOMP_FUNC void model_anim_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800619F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800619F8: jr          $ra
    // 0x800619FC: sw          $a0, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r4;
    return;
    // 0x800619FC: sw          $a0, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void input_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A554: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A558: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A55C: lbu         $t6, 0x1150($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1150);
    // 0x8006A560: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A564: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A568: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A56C: lhu         $v0, 0x1140($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1140);
    // 0x8006A570: jr          $ra
    // 0x8006A574: nop

    return;
    // 0x8006A574: nop

;}
RECOMP_FUNC void cam_get_cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069D7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069D80: lb          $t6, 0xD14($t6)
    ctx->r14 = MEM_B(ctx->r14, 0XD14);
    // 0x80069D84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069D88: beq         $t6, $zero, L_80069D9C
    if (ctx->r14 == 0) {
        // 0x80069D8C: addiu       $v0, $v0, 0xAC0
        ctx->r2 = ADD32(ctx->r2, 0XAC0);
            goto L_80069D9C;
    }
    // 0x80069D8C: addiu       $v0, $v0, 0xAC0
    ctx->r2 = ADD32(ctx->r2, 0XAC0);
    // 0x80069D90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069D94: jr          $ra
    // 0x80069D98: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
    return;
    // 0x80069D98: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
L_80069D9C:
    // 0x80069D9C: jr          $ra
    // 0x80069DA0: nop

    return;
    // 0x80069DA0: nop

;}
