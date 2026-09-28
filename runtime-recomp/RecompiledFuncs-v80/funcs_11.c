#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80060AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060AC8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80060ACC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80060AD0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80060AD4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80060AD8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80060ADC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80060AE0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80060AE4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80060AE8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80060AEC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060AF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80060AF4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80060AF8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80060AFC: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80060B00: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80060B04: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80060B08: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80060B0C: blez        $t0, L_80060C24
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80060B10: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80060C24;
    }
    // 0x80060B10: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80060B14: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80060B18: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_80060B1C:
    // 0x80060B1C: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x80060B20: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80060B24: nop

    // 0x80060B28: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80060B2C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x80060B30: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060B34: lh          $s2, 0x2($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X2);
    // 0x80060B38: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x80060B3C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80060B40: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80060B44: andi        $t1, $t9, 0x200
    ctx->r9 = ctx->r25 & 0X200;
    // 0x80060B48: beq         $t1, $zero, L_80060B58
    if (ctx->r9 == 0) {
        // 0x80060B4C: lw          $t3, 0x70($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X70);
            goto L_80060B58;
    }
    // 0x80060B4C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80060B50: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x80060B54: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
L_80060B58:
    // 0x80060B58: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
    // 0x80060B5C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060B60: beq         $at, $zero, L_80060C08
    if (ctx->r1 == 0) {
        // 0x80060B64: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80060C08;
    }
    // 0x80060B64: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060B68:
    // 0x80060B68: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80060B6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060B70: beq         $s4, $t4, L_80060BEC
    if (ctx->r20 == ctx->r12) {
        // 0x80060B74: addiu       $s0, $s1, 0x1
        ctx->r16 = ADD32(ctx->r17, 0X1);
            goto L_80060BEC;
    }
L_80060B74:
    // 0x80060B74: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80060B78: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80060B7C: bne         $at, $zero, L_80060B88
    if (ctx->r1 != 0) {
        // 0x80060B80: or          $t0, $s0, $zero
        ctx->r8 = ctx->r16 | 0;
            goto L_80060B88;
    }
    // 0x80060B80: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80060B84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80060B88:
    // 0x80060B88: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80060B8C: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x80060B90: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80060B94: addu        $t9, $v0, $t0
    ctx->r25 = ADD32(ctx->r2, ctx->r8);
    // 0x80060B98: lbu         $t1, 0x1($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X1);
    // 0x80060B9C: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x80060BA0: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060BA4: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x80060BA8: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x80060BAC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80060BB0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80060BB4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80060BB8: jal         0x80060C58
    // 0x80060BBC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    func_80060C58(rdram, ctx);
        goto after_0;
    // 0x80060BBC: addu        $a3, $t8, $s2
    ctx->r7 = ADD32(ctx->r24, ctx->r18);
    after_0:
    // 0x80060BC0: beq         $v0, $zero, L_80060BE4
    if (ctx->r2 == 0) {
        // 0x80060BC4: nop
    
            goto L_80060BE4;
    }
    // 0x80060BC4: nop

    // 0x80060BC8: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80060BCC: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80060BD0: sw          $s1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r17;
    // 0x80060BD4: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80060BD8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80060BDC: b           L_80060C28
    // 0x80060BE0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_80060C28;
    // 0x80060BE0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80060BE4:
    // 0x80060BE4: bne         $s0, $s7, L_80060B74
    if (ctx->r16 != ctx->r23) {
        // 0x80060BE8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80060B74;
    }
    // 0x80060BE8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80060BEC:
    // 0x80060BEC: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80060BF0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060BF4: bne         $s4, $t5, L_80060B68
    if (ctx->r20 != ctx->r13) {
        // 0x80060BF8: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_80060B68;
    }
    // 0x80060BF8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80060BFC: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80060C00: nop

    // 0x80060C04: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80060C08:
    // 0x80060C08: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80060C0C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80060C10: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060C14: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80060C18: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80060C1C: bne         $at, $zero, L_80060B1C
    if (ctx->r1 != 0) {
        // 0x80060C20: sw          $t7, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r15;
            goto L_80060B1C;
    }
    // 0x80060C20: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_80060C24:
    // 0x80060C24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80060C28:
    // 0x80060C28: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80060C2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80060C30: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80060C34: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80060C38: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80060C3C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80060C40: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80060C44: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80060C48: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80060C4C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80060C50: jr          $ra
    // 0x80060C54: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80060C54: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void particle_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9C4: lw          $v0, -0x519C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X519C);
    // 0x8000E9C8: jr          $ra
    // 0x8000E9CC: nop

    return;
    // 0x8000E9CC: nop

;}
RECOMP_FUNC void find_active_pool_slot_colours(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800718A4: addiu       $sp, $sp, -0x238
    ctx->r29 = ADD32(ctx->r29, -0X238);
    // 0x800718A8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800718AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800718B0: addiu       $a0, $sp, 0x138
    ctx->r4 = ADD32(ctx->r29, 0X138);
    // 0x800718B4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800718B8: addiu       $v1, $sp, 0x138
    ctx->r3 = ADD32(ctx->r29, 0X138);
L_800718BC:
    // 0x800718BC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800718C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800718C4: sw          $zero, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = 0;
    // 0x800718C8: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800718CC: sw          $zero, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = 0;
    // 0x800718D0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800718D4: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x800718D8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800718DC: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800718E0: bne         $a1, $v1, L_800718BC
    if (ctx->r5 != ctx->r3) {
        // 0x800718E4: sw          $zero, -0x10($a1)
        MEM_W(-0X10, ctx->r5) = 0;
            goto L_800718BC;
    }
    // 0x800718E4: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x800718E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800718EC: lw          $a0, 0x35C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X35C0);
    // 0x800718F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800718F4: blez        $a0, L_800719E4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800718F8: addiu       $a1, $t6, 0x3580
        ctx->r5 = ADD32(ctx->r14, 0X3580);
            goto L_800719E4;
    }
    // 0x800718F8: addiu       $a1, $t6, 0x3580
    ctx->r5 = ADD32(ctx->r14, 0X3580);
    // 0x800718FC: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80071900: addu        $t2, $t7, $a1
    ctx->r10 = ADD32(ctx->r15, ctx->r5);
    // 0x80071904: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x80071908: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8007190C: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80071910: addiu       $t3, $sp, 0x138
    ctx->r11 = ADD32(ctx->r29, 0X138);
L_80071914:
    // 0x80071914: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80071918: nop

    // 0x8007191C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80071920:
    // 0x80071920: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80071924: nop

    // 0x80071928: beq         $t8, $zero, L_800719AC
    if (ctx->r24 == 0) {
        // 0x8007192C: nop
    
            goto L_800719AC;
    }
    // 0x8007192C: nop

    // 0x80071930: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80071934: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80071938: beq         $a2, $zero, L_800719AC
    if (ctx->r6 == 0) {
        // 0x8007193C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800719AC;
    }
    // 0x8007193C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80071940: beq         $a2, $t9, L_8007197C
    if (ctx->r6 == ctx->r25) {
        // 0x80071944: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8007197C;
    }
    // 0x80071944: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80071948: beq         $t9, $zero, L_80071980
    if (ctx->r25 == 0) {
        // 0x8007194C: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071980;
    }
    // 0x8007194C: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071950:
    // 0x80071950: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80071954: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071958: beq         $at, $zero, L_8007197C
    if (ctx->r1 == 0) {
        // 0x8007195C: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_8007197C;
    }
    // 0x8007195C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80071960: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x80071964: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80071968: nop

    // 0x8007196C: beq         $a3, $a2, L_80071980
    if (ctx->r7 == ctx->r6) {
        // 0x80071970: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071980;
    }
    // 0x80071970: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071974: bne         $a2, $zero, L_80071950
    if (ctx->r6 != 0) {
        // 0x80071978: nop
    
            goto L_80071950;
    }
    // 0x80071978: nop

L_8007197C:
    // 0x8007197C: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071980:
    // 0x80071980: beq         $at, $zero, L_800719A8
    if (ctx->r1 == 0) {
        // 0x80071984: sll         $a2, $t0, 2
        ctx->r6 = S32(ctx->r8 << 2);
            goto L_800719A8;
    }
    // 0x80071984: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x80071988: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x8007198C: sw          $a3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r7;
    // 0x80071990: addu        $t1, $t4, $a2
    ctx->r9 = ADD32(ctx->r12, ctx->r6);
    // 0x80071994: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80071998: nop

    // 0x8007199C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800719A0: b           L_800719AC
    // 0x800719A4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_800719AC;
    // 0x800719A4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_800719A8:
    // 0x800719A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800719AC:
    // 0x800719AC: lh          $a3, 0xC($v1)
    ctx->r7 = MEM_H(ctx->r3, 0XC);
    // 0x800719B0: nop

    // 0x800719B4: beq         $a3, $t5, L_800719CC
    if (ctx->r7 == ctx->r13) {
        // 0x800719B8: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800719CC;
    }
    // 0x800719B8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800719BC: multu       $a3, $s0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800719C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800719C4: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x800719C8: nop

L_800719CC:
    // 0x800719CC: bne         $a2, $t5, L_80071920
    if (ctx->r6 != ctx->r13) {
        // 0x800719D0: nop
    
            goto L_80071920;
    }
    // 0x800719D0: nop

    // 0x800719D4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800719D8: sltu        $at, $a1, $t2
    ctx->r1 = ctx->r5 < ctx->r10 ? 1 : 0;
    // 0x800719DC: bne         $at, $zero, L_80071914
    if (ctx->r1 != 0) {
        // 0x800719E0: nop
    
            goto L_80071914;
    }
    // 0x800719E0: nop

L_800719E4:
    // 0x800719E4: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800719E8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800719EC: beq         $t8, $zero, L_80071A1C
    if (ctx->r24 == 0) {
        // 0x800719F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80071A1C;
    }
    // 0x800719F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800719F4: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x800719F8: addiu       $t7, $sp, 0x138
    ctx->r15 = ADD32(ctx->r29, 0X138);
    // 0x800719FC: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x80071A00: addiu       $v1, $sp, 0x238
    ctx->r3 = ADD32(ctx->r29, 0X238);
L_80071A04:
    // 0x80071A04: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80071A08: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80071A0C: beq         $t6, $zero, L_80071A1C
    if (ctx->r14 == 0) {
        // 0x80071A10: nop
    
            goto L_80071A1C;
    }
    // 0x80071A10: nop

    // 0x80071A14: bne         $a0, $v1, L_80071A04
    if (ctx->r4 != ctx->r3) {
        // 0x80071A18: nop
    
            goto L_80071A04;
    }
    // 0x80071A18: nop

L_80071A1C:
    // 0x80071A1C: jr          $ra
    // 0x80071A20: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
    return;
    // 0x80071A20: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
;}
RECOMP_FUNC void move_dialogue_box_to_front(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5428: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C542C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5430: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C5434: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5438: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C543C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5440: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x800C5444: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x800C5448: beq         $a2, $zero, L_800C5474
    if (ctx->r6 == 0) {
        // 0x800C544C: nop
    
            goto L_800C5474;
    }
    // 0x800C544C: nop

    // 0x800C5450: beq         $a2, $a1, L_800C5474
    if (ctx->r6 == ctx->r5) {
        // 0x800C5454: nop
    
            goto L_800C5474;
    }
    // 0x800C5454: nop

L_800C5458:
    // 0x800C5458: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x800C545C: lw          $a2, 0x1C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1C);
    // 0x800C5460: nop

    // 0x800C5464: beq         $a2, $zero, L_800C5474
    if (ctx->r6 == 0) {
        // 0x800C5468: nop
    
            goto L_800C5474;
    }
    // 0x800C5468: nop

    // 0x800C546C: bne         $a2, $a1, L_800C5458
    if (ctx->r6 != ctx->r5) {
        // 0x800C5470: nop
    
            goto L_800C5458;
    }
    // 0x800C5470: nop

L_800C5474:
    // 0x800C5474: beq         $a2, $zero, L_800C548C
    if (ctx->r6 == 0) {
        // 0x800C5478: nop
    
            goto L_800C548C;
    }
    // 0x800C5478: nop

    // 0x800C547C: lw          $t8, 0x1C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1C);
    // 0x800C5480: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C5484: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C5488: sb          $t9, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r25;
L_800C548C:
    // 0x800C548C: jr          $ra
    // 0x800C5490: nop

    return;
    // 0x800C5490: nop

;}
RECOMP_FUNC void light_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032218: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003221C: jr          $ra
    // 0x80032220: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x80032220: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D52F0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D52F4: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800D52F8: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800D52FC: blez        $a1, L_800D5340
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D5300: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800D5340;
    }
    // 0x800D5300: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800D5304:
    // 0x800D5304: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800D5308: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800D530C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800D5310: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D5314: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800D5318: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D531C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D5320: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800D5324: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800D5328: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D532C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800D5330: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800D5334: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800D5338: bne         $at, $zero, L_800D5304
    if (ctx->r1 != 0) {
        // 0x800D533C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800D5304;
    }
    // 0x800D533C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800D5340:
    // 0x800D5340: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800D5344: jr          $ra
    // 0x800D5348: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D5348: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_id_valid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010028: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001002C: lw          $t6, -0x5148($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5148);
    // 0x80010030: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80010034: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010038: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001003C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80010040: lw          $t0, -0x5298($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5298);
    // 0x80010044: jr          $ra
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    return;
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
;}
RECOMP_FUNC void func_8005250C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005250C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052510: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052514: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052518: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005251C: lb          $t6, 0x173($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X173);
    // 0x80052520: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80052524: blez        $t6, L_80052564
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80052528: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80052564;
    }
    // 0x80052528: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8005252C: jal         0x8001E29C
    // 0x80052530: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80052530: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052534: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052538: nop

    // 0x8005253C: lb          $t7, 0x172($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X172);
    // 0x80052540: lb          $t9, 0x174($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X174);
    // 0x80052544: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80052548: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005254C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80052550: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80052554: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80052558: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8005255C: lb          $v1, 0x0($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X0);
    // 0x80052560: nop

L_80052564:
    // 0x80052564: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80052568: lw          $t3, -0x2AD4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD4);
    // 0x8005256C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052570: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x80052574: beq         $t4, $zero, L_80052590
    if (ctx->r12 == 0) {
        // 0x80052578: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80052590;
    }
    // 0x80052578: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8005257C: beq         $v1, $at, L_80052590
    if (ctx->r3 == ctx->r1) {
        // 0x80052580: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80052590;
    }
    // 0x80052580: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80052584: beq         $v1, $at, L_80052590
    if (ctx->r3 == ctx->r1) {
        // 0x80052588: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_80052590;
    }
    // 0x80052588: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005258C: sb          $t5, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r13;
L_80052590:
    // 0x80052590: lb          $t6, 0x1D3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D3);
    // 0x80052594: nop

    // 0x80052598: beq         $t6, $zero, L_800525B0
    if (ctx->r14 == 0) {
        // 0x8005259C: nop
    
            goto L_800525B0;
    }
    // 0x8005259C: nop

    // 0x800525A0: lbu         $t7, 0x1F3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800525A4: nop

    // 0x800525A8: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x800525AC: sb          $t9, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r25;
L_800525B0:
    // 0x800525B0: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800525B4: nop

    // 0x800525B8: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x800525BC: beq         $t0, $zero, L_80052618
    if (ctx->r8 == 0) {
        // 0x800525C0: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80052618;
    }
    // 0x800525C0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800525C4: lw          $t1, -0x3468($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3468);
    // 0x800525C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800525CC: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x800525D0: beq         $at, $zero, L_80052614
    if (ctx->r1 == 0) {
        // 0x800525D4: nop
    
            goto L_80052614;
    }
    // 0x800525D4: nop

    // 0x800525D8: lw          $t2, -0x2AA4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AA4);
    // 0x800525DC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800525E0: bltz        $t2, L_80052604
    if (SIGNED(ctx->r10) < 0) {
        // 0x800525E4: nop
    
            goto L_80052604;
    }
    // 0x800525E4: nop

    // 0x800525E8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800525EC: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x800525F0: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x800525F4: nop

    // 0x800525F8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800525FC: b           L_80052614
    // 0x80052600: sw          $t5, 0x74($t3)
    MEM_W(0X74, ctx->r11) = ctx->r13;
        goto L_80052614;
    // 0x80052600: sw          $t5, 0x74($t3)
    MEM_W(0X74, ctx->r11) = ctx->r13;
L_80052604:
    // 0x80052604: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80052608: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8005260C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80052610: sw          $t9, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r25;
L_80052614:
    // 0x80052614: sb          $t8, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r24;
L_80052618:
    // 0x80052618: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005261C: lw          $t0, -0x2AC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC0);
    // 0x80052620: nop

    // 0x80052624: beq         $t0, $zero, L_80052634
    if (ctx->r8 == 0) {
        // 0x80052628: nop
    
            goto L_80052634;
    }
    // 0x80052628: nop

    // 0x8005262C: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    // 0x80052630: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
L_80052634:
    // 0x80052634: lb          $t1, 0x1D8($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1D8);
    // 0x80052638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005263C: bne         $t1, $at, L_8005264C
    if (ctx->r9 != ctx->r1) {
        // 0x80052640: nop
    
            goto L_8005264C;
    }
    // 0x80052640: nop

    // 0x80052644: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052648: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_8005264C:
    // 0x8005264C: lbu         $t2, 0x1F2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1F2);
    // 0x80052650: nop

    // 0x80052654: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x80052658: beq         $at, $zero, L_80052978
    if (ctx->r1 == 0) {
        // 0x8005265C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80052978;
    }
    // 0x8005265C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80052660: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052664: addu        $at, $at, $t2
    gpr jr_addend_80052670 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80052668: lw          $t2, 0x66D0($at)
    ctx->r10 = ADD32(ctx->r1, 0X66D0);
    // 0x8005266C: nop

    // 0x80052670: jr          $t2
    // 0x80052674: nop

    switch (jr_addend_80052670 >> 2) {
        case 0: goto L_80052678; break;
        case 1: goto L_80052978; break;
        case 2: goto L_80052978; break;
        case 3: goto L_800527AC; break;
        case 4: goto L_8005280C; break;
        case 5: goto L_80052858; break;
        case 6: goto L_800528A4; break;
        case 7: goto L_80052910; break;
        default: switch_error(__func__, 0x80052670, 0x800E66D0);
    }
    // 0x80052674: nop

L_80052678:
    // 0x80052678: lh          $t4, 0x1A2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X1A2);
    // 0x8005267C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052680: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80052684: sra         $t3, $t5, 8
    ctx->r11 = S32(SIGNED(ctx->r13) >> 8);
    // 0x80052688: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005268C: lwc1        $f8, -0x2A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x80052690: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80052694: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80052698: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8005269C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800526A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800526A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800526A8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800526AC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800526B0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800526B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800526B8: nop

    // 0x800526BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800526C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800526C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800526C8: nop

    // 0x800526CC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800526D0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800526D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800526D8: subu        $v1, $t9, $v1
    ctx->r3 = SUB32(ctx->r25, ctx->r3);
    // 0x800526DC: bgez        $v1, L_800526E8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800526E0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800526E8;
    }
    // 0x800526E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800526E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800526E8:
    // 0x800526E8: slti        $at, $v1, 0x4A
    ctx->r1 = SIGNED(ctx->r3) < 0X4A ? 1 : 0;
    // 0x800526EC: bne         $at, $zero, L_800526F8
    if (ctx->r1 != 0) {
        // 0x800526F0: nop
    
            goto L_800526F8;
    }
    // 0x800526F0: nop

    // 0x800526F4: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
L_800526F8:
    // 0x800526F8: lh          $a2, 0x18($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X18);
    // 0x800526FC: nop

    // 0x80052700: subu        $a0, $v1, $a2
    ctx->r4 = SUB32(ctx->r3, ctx->r6);
    // 0x80052704: blez        $a0, L_80052720
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80052708: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80052720;
    }
    // 0x80052708: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005270C: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x80052710: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052714: beq         $at, $zero, L_80052720
    if (ctx->r1 == 0) {
        // 0x80052718: nop
    
            goto L_80052720;
    }
    // 0x80052718: nop

    // 0x8005271C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80052720:
    // 0x80052720: bgez        $a0, L_80052750
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80052724: addu        $t1, $a2, $v1
        ctx->r9 = ADD32(ctx->r6, ctx->r3);
            goto L_80052750;
    }
    // 0x80052724: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
    // 0x80052728: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005272C: nop

    // 0x80052730: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x80052734: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x80052738: subu        $v1, $t0, $at
    ctx->r3 = SUB32(ctx->r8, ctx->r1);
    // 0x8005273C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80052740: beq         $at, $zero, L_80052750
    if (ctx->r1 == 0) {
        // 0x80052744: addu        $t1, $a2, $v1
        ctx->r9 = ADD32(ctx->r6, ctx->r3);
            goto L_80052750;
    }
    // 0x80052744: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
    // 0x80052748: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8005274C: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
L_80052750:
    // 0x80052750: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x80052754: sb          $zero, 0x3B($t2)
    MEM_B(0X3B, ctx->r10) = 0;
    // 0x80052758: lbu         $v0, 0x1F3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1F3);
    // 0x8005275C: nop

    // 0x80052760: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x80052764: beq         $t4, $zero, L_80052774
    if (ctx->r12 == 0) {
        // 0x80052768: andi        $t3, $v0, 0xFFFB
        ctx->r11 = ctx->r2 & 0XFFFB;
            goto L_80052774;
    }
    // 0x80052768: andi        $t3, $v0, 0xFFFB
    ctx->r11 = ctx->r2 & 0XFFFB;
    // 0x8005276C: sb          $t5, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r13;
    // 0x80052770: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
L_80052774:
    // 0x80052774: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052778: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005277C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80052780: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80052784: nop

    // 0x80052788: bc1f        L_8005297C
    if (!c1cs) {
        // 0x8005278C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005297C;
    }
    // 0x8005278C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052790: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x80052794: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80052798: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8005279C: beq         $t9, $zero, L_8005297C
    if (ctx->r25 == 0) {
        // 0x800527A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005297C;
    }
    // 0x800527A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800527A4: b           L_80052978
    // 0x800527A8: sb          $t6, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r14;
        goto L_80052978;
    // 0x800527A8: sb          $t6, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r14;
L_800527AC:
    // 0x800527AC: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800527B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800527B4: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x800527B8: beq         $t0, $zero, L_800527C4
    if (ctx->r8 == 0) {
        // 0x800527BC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800527C4;
    }
    // 0x800527BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800527C0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800527C4:
    // 0x800527C4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800527C8: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800527CC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800527D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800527D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800527D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800527DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800527E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800527E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800527E8: jal         0x80052988
    // 0x800527EC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_80052988(rdram, ctx);
        goto after_1;
    // 0x800527EC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_1:
    // 0x800527F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800527F4: nop

    // 0x800527F8: lbu         $t5, 0x1F3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800527FC: nop

    // 0x80052800: andi        $t3, $t5, 0xFFFB
    ctx->r11 = ctx->r13 & 0XFFFB;
    // 0x80052804: b           L_80052978
    // 0x80052808: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
        goto L_80052978;
    // 0x80052808: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
L_8005280C:
    // 0x8005280C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80052810: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052814: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80052818: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005281C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80052820: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80052824: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80052828: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005282C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80052830: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052834: jal         0x80052988
    // 0x80052838: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80052988(rdram, ctx);
        goto after_2;
    // 0x80052838: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_2:
    // 0x8005283C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052840: nop

    // 0x80052844: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052848: nop

    // 0x8005284C: andi        $t0, $t8, 0xFFF7
    ctx->r8 = ctx->r24 & 0XFFF7;
    // 0x80052850: b           L_80052978
    // 0x80052854: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
        goto L_80052978;
    // 0x80052854: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
L_80052858:
    // 0x80052858: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8005285C: lw          $t1, -0x2AD8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AD8);
    // 0x80052860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052864: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x80052868: beq         $t2, $zero, L_80052874
    if (ctx->r10 == 0) {
        // 0x8005286C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80052874;
    }
    // 0x8005286C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80052870: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80052874:
    // 0x80052874: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80052878: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8005287C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80052880: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80052884: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80052888: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8005288C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052890: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80052894: jal         0x80052988
    // 0x80052898: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_80052988(rdram, ctx);
        goto after_3;
    // 0x80052898: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_3:
    // 0x8005289C: b           L_8005297C
    // 0x800528A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005297C;
    // 0x800528A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800528A4:
    // 0x800528A4: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800528A8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800528AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800528B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800528B4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800528B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800528BC: bc1f        L_800528E0
    if (!c1cs) {
        // 0x800528C0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800528E0;
    }
    // 0x800528C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800528C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800528C8: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x800528CC: nop

    // 0x800528D0: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x800528D4: beq         $t9, $zero, L_800528E4
    if (ctx->r25 == 0) {
        // 0x800528D8: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_800528E4;
    }
    // 0x800528D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800528DC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800528E0:
    // 0x800528E0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_800528E4:
    // 0x800528E4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800528E8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800528EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800528F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800528F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800528F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800528FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80052900: jal         0x80052988
    // 0x80052904: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80052988(rdram, ctx);
        goto after_4;
    // 0x80052904: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_4:
    // 0x80052908: b           L_8005297C
    // 0x8005290C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005297C;
    // 0x8005290C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052910:
    // 0x80052910: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80052914: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052918: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x8005291C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80052920: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80052924: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052928: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8005292C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052930: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80052934: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052938: jal         0x80052988
    // 0x8005293C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_80052988(rdram, ctx);
        goto after_5;
    // 0x8005293C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_5:
    // 0x80052940: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052944: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052948: lbu         $t5, 0x1F2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F2);
    // 0x8005294C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80052950: bne         $t5, $zero, L_80052978
    if (ctx->r13 != 0) {
        // 0x80052954: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80052978;
    }
    // 0x80052954: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052958: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005295C: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x80052960: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80052964: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80052968: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005296C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80052970: jal         0x80052988
    // 0x80052974: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80052988(rdram, ctx);
        goto after_6;
    // 0x80052974: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_6:
L_80052978:
    // 0x80052978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005297C:
    // 0x8005297C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052980: jr          $ra
    // 0x80052984: nop

    return;
    // 0x80052984: nop

;}
RECOMP_FUNC void func_80017978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017978: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001797C: lw          $a2, -0x500C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X500C);
    // 0x80017980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017984: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_80017988:
    // 0x80017988: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x8001798C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80017990: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017994: bne         $t7, $zero, L_800179B4
    if (ctx->r15 != 0) {
        // 0x80017998: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_800179B4;
    }
    // 0x80017998: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001799C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800179A0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800179A4: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x800179A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800179AC: jr          $ra
    // 0x800179B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800179B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800179B4:
    // 0x800179B4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800179B8: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800179BC: bne         $at, $zero, L_80017988
    if (ctx->r1 != 0) {
        // 0x800179C0: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_80017988;
    }
    // 0x800179C0: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179C8: jr          $ra
    // 0x800179CC: nop

    return;
    // 0x800179CC: nop

;}
RECOMP_FUNC void hud_init_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F034: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8009F038: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009F03C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009F040: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009F044: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009F048: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009F04C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009F050: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009F054: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009F058: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009F05C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009F060: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8009F064: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8009F068: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8009F06C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8009F070: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8009F074: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8009F078: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8009F07C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8009F080: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009F084: jal         0x8006BD98
    // 0x8009F088: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    level_type(rdram, ctx);
        goto after_0;
    // 0x8009F088: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8009F08C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F090: beq         $t4, $v0, L_8009F0A4
    if (ctx->r12 == ctx->r2) {
        // 0x8009F094: lui         $s0, 0x8000
        ctx->r16 = S32(0X8000 << 16);
            goto L_8009F0A4;
    }
    // 0x8009F094: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8009F098: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009F09C: bne         $v0, $at, L_8009F0BC
    if (ctx->r2 != ctx->r1) {
        // 0x8009F0A0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8009F0BC;
    }
    // 0x8009F0A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
L_8009F0A4:
    // 0x8009F0A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F0A8: sw          $zero, 0x6D24($at)
    MEM_W(0X6D24, ctx->r1) = 0;
    // 0x8009F0AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F0B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009F0B4: b           L_8009F10C
    // 0x8009F0B8: sb          $t6, 0x6D34($at)
    MEM_B(0X6D34, ctx->r1) = ctx->r14;
        goto L_8009F10C;
    // 0x8009F0B8: sb          $t6, 0x6D34($at)
    MEM_B(0X6D34, ctx->r1) = ctx->r14;
L_8009F0BC:
    // 0x8009F0BC: lw          $t7, 0x6D0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D0C);
    // 0x8009F0C0: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8009F0C4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8009F0C8: beq         $at, $zero, L_8009F0EC
    if (ctx->r1 == 0) {
        // 0x8009F0CC: addiu       $t9, $zero, 0xC8
        ctx->r25 = ADD32(0, 0XC8);
            goto L_8009F0EC;
    }
    // 0x8009F0CC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8009F0D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F0D4: sw          $t8, 0x6D24($at)
    MEM_W(0X6D24, ctx->r1) = ctx->r24;
    // 0x8009F0D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F0DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F0E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F0E4: b           L_8009F104
    // 0x8009F0E8: swc1        $f4, 0x6D30($at)
    MEM_W(0X6D30, ctx->r1) = ctx->f4.u32l;
        goto L_8009F104;
    // 0x8009F0E8: swc1        $f4, 0x6D30($at)
    MEM_W(0X6D30, ctx->r1) = ctx->f4.u32l;
L_8009F0EC:
    // 0x8009F0EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F0F0: sw          $t9, 0x6D24($at)
    MEM_W(0X6D24, ctx->r1) = ctx->r25;
    // 0x8009F0F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F0F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F0FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F100: swc1        $f6, 0x6D30($at)
    MEM_W(0X6D30, ctx->r1) = ctx->f6.u32l;
L_8009F104:
    // 0x8009F104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F108: sb          $zero, 0x6D34($at)
    MEM_B(0X6D34, ctx->r1) = 0;
L_8009F10C:
    // 0x8009F10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F110: sh          $zero, 0x6D2C($at)
    MEM_H(0X6D2C, ctx->r1) = 0;
    // 0x8009F114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F118: sb          $zero, 0x6CD4($at)
    MEM_B(0X6CD4, ctx->r1) = 0;
    // 0x8009F11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F120: sb          $zero, 0x6D36($at)
    MEM_B(0X6D36, ctx->r1) = 0;
    // 0x8009F124: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F128: sb          $zero, 0x6D38($at)
    MEM_B(0X6D38, ctx->r1) = 0;
    // 0x8009F12C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F130: sb          $zero, 0x6D35($at)
    MEM_B(0X6D35, ctx->r1) = 0;
    // 0x8009F134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F138: addiu       $s0, $s0, 0x300
    ctx->r16 = ADD32(ctx->r16, 0X300);
    // 0x8009F13C: sb          $zero, 0x6CD0($at)
    MEM_B(0X6CD0, ctx->r1) = 0;
    // 0x8009F140: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8009F144: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x8009F148: bne         $t6, $zero, L_8009F160
    if (ctx->r14 != 0) {
        // 0x8009F14C: addiu       $a0, $zero, 0x78
        ctx->r4 = ADD32(0, 0X78);
            goto L_8009F160;
    }
    // 0x8009F14C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8009F150: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8009F154: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F158: b           L_8009F16C
    // 0x8009F15C: sb          $t7, 0x718B($at)
    MEM_B(0X718B, ctx->r1) = ctx->r15;
        goto L_8009F16C;
    // 0x8009F15C: sb          $t7, 0x718B($at)
    MEM_B(0X718B, ctx->r1) = ctx->r15;
L_8009F160:
    // 0x8009F160: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x8009F164: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F168: sb          $t8, 0x718B($at)
    MEM_B(0X718B, ctx->r1) = ctx->r24;
L_8009F16C:
    // 0x8009F16C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F170: sb          $zero, 0x6CD1($at)
    MEM_B(0X6CD1, ctx->r1) = 0;
    // 0x8009F174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F178: sb          $zero, 0x6CD2($at)
    MEM_B(0X6CD2, ctx->r1) = 0;
    // 0x8009F17C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F180: sb          $zero, 0x6CD5($at)
    MEM_B(0X6CD5, ctx->r1) = 0;
    // 0x8009F184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F188: sb          $zero, 0x7189($at)
    MEM_B(0X7189, ctx->r1) = 0;
    // 0x8009F18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F190: sw          $t9, 0x6D4C($at)
    MEM_W(0X6D4C, ctx->r1) = ctx->r25;
    // 0x8009F194: jal         0x8006F94C
    // 0x8009F198: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009F198: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    after_1:
    // 0x8009F19C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F1A0: jal         0x8000E158
    // 0x8009F1A4: sw          $v0, 0x6D50($at)
    MEM_W(0X6D50, ctx->r1) = ctx->r2;
    is_race_started_by_player_two(rdram, ctx);
        goto after_2;
    // 0x8009F1A4: sw          $v0, 0x6D50($at)
    MEM_W(0X6D50, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009F1A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F1AC: sb          $v0, 0x718A($at)
    MEM_B(0X718A, ctx->r1) = ctx->r2;
    // 0x8009F1B0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8009F1B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F1B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009F1BC: addiu       $a0, $a0, 0x7190
    ctx->r4 = ADD32(ctx->r4, 0X7190);
    // 0x8009F1C0: addiu       $v1, $v1, 0x718C
    ctx->r3 = ADD32(ctx->r3, 0X718C);
    // 0x8009F1C4: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x8009F1C8: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x8009F1CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009F1D0: bne         $t8, $zero, L_8009F1EC
    if (ctx->r24 != 0) {
        // 0x8009F1D4: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009F1EC;
    }
    // 0x8009F1D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F1D8: addiu       $t6, $t7, 0x1E
    ctx->r14 = ADD32(ctx->r15, 0X1E);
    // 0x8009F1DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F1E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F1E4: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8009F1E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009F1EC:
    // 0x8009F1EC: jal         0x8001B640
    // 0x8009F1F0: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_3;
    // 0x8009F1F0: nop

    after_3:
    // 0x8009F1F4: bne         $v0, $zero, L_8009F208
    if (ctx->r2 != 0) {
        // 0x8009F1F8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009F208;
    }
    // 0x8009F1F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F1FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F200: b           L_8009F214
    // 0x8009F204: sb          $zero, 0x6D71($at)
    MEM_B(0X6D71, ctx->r1) = 0;
        goto L_8009F214;
    // 0x8009F204: sb          $zero, 0x6D71($at)
    MEM_B(0X6D71, ctx->r1) = 0;
L_8009F208:
    // 0x8009F208: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009F20C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F210: sb          $t9, 0x6D71($at)
    MEM_B(0X6D71, ctx->r1) = ctx->r25;
L_8009F214:
    // 0x8009F214: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F218: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x8009F21C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F220: beq         $v0, $at, L_8009F230
    if (ctx->r2 == ctx->r1) {
        // 0x8009F224: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_8009F230;
    }
    // 0x8009F224: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8009F228: b           L_8009F234
    // 0x8009F22C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
        goto L_8009F234;
    // 0x8009F22C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_8009F230:
    // 0x8009F230: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8009F234:
    // 0x8009F234: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8009F238: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009F23C: blez        $t7, L_8009FFA4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009F240: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8009FFA4;
    }
    // 0x8009F240: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009F244: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x8009F248: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8009F24C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8009F250: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8009F254: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8009F258: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8009F25C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009F260: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8009F264: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8009F268: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009F26C: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8009F270: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009F274: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F278: addiu       $t8, $t8, 0x6CE0
    ctx->r24 = ADD32(ctx->r24, 0X6CE0);
    // 0x8009F27C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009F280: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009F284: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009F288: lwc1        $f15, -0x7958($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X7958);
    // 0x8009F28C: lwc1        $f14, -0x7954($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7954);
    // 0x8009F290: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F294: addiu       $a1, $a1, 0x6CDC
    ctx->r5 = ADD32(ctx->r5, 0X6CDC);
    // 0x8009F298: addiu       $t1, $t1, 0x6CF0
    ctx->r9 = ADD32(ctx->r9, 0X6CF0);
    // 0x8009F29C: addiu       $s0, $s0, 0x25C4
    ctx->r16 = ADD32(ctx->r16, 0X25C4);
    // 0x8009F2A0: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8009F2A4: addiu       $fp, $zero, 0x36
    ctx->r30 = ADD32(0, 0X36);
    // 0x8009F2A8: addiu       $s7, $zero, 0x1C
    ctx->r23 = ADD32(0, 0X1C);
    // 0x8009F2AC: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x8009F2B0: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x8009F2B4: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // 0x8009F2B8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8009F2BC: addiu       $s2, $zero, 0x760
    ctx->r18 = ADD32(0, 0X760);
    // 0x8009F2C0: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x8009F2C4: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x8009F2C8: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8009F2CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009F2D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8009F2D4: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
L_8009F2D8:
    // 0x8009F2D8: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F2DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F2E0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8009F2E4: addiu       $v0, $v0, 0x1E64
    ctx->r2 = ADD32(ctx->r2, 0X1E64);
    // 0x8009F2E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F2EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_8009F2F0:
    // 0x8009F2F0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F2F4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009F2F8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F2FC: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x8009F300: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F304: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009F308: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F30C: swc1        $f10, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f10.u32l;
    // 0x8009F310: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F314: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009F318: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F31C: swc1        $f4, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f4.u32l;
    // 0x8009F320: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F324: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F328: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F32C: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8009F330: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F334: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F338: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F33C: sh          $t7, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r15;
    // 0x8009F340: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F344: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8009F348: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F34C: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8009F350: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F354: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F358: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F35C: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8009F360: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F364: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8009F368: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F36C: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x8009F370: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F374: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x8009F378: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F37C: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x8009F380: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F384: lb          $t9, 0x1A($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1A);
    // 0x8009F388: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F38C: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x8009F390: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F394: lb          $t7, 0x1B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1B);
    // 0x8009F398: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F39C: sb          $t7, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r15;
    // 0x8009F3A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F3A4: lb          $t6, 0x1C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C);
    // 0x8009F3A8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F3AC: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x8009F3B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F3B4: lb          $t9, 0x1D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D);
    // 0x8009F3B8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009F3BC: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F3C0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009F3C4: bne         $v0, $s0, L_8009F2F0
    if (ctx->r2 != ctx->r16) {
        // 0x8009F3C8: sb          $t9, 0x1D($t6)
        MEM_B(0X1D, ctx->r14) = ctx->r25;
            goto L_8009F2F0;
    }
    // 0x8009F3C8: sb          $t9, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r25;
    // 0x8009F3CC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F3D0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8009F3D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F3D8: sb          $t7, 0x5DC($t8)
    MEM_B(0X5DC, ctx->r24) = ctx->r15;
    // 0x8009F3DC: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x8009F3E0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8009F3E4: bne         $t4, $v1, L_8009F5F8
    if (ctx->r12 != ctx->r3) {
        // 0x8009F3E8: nop
    
            goto L_8009F5F8;
    }
    // 0x8009F3E8: nop

    // 0x8009F3EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009F3F0: addiu       $v0, $v1, 0x25C4
    ctx->r2 = ADD32(ctx->r3, 0X25C4);
    // 0x8009F3F4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F3F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009F3FC: beq         $t2, $t9, L_8009F4FC
    if (ctx->r10 == ctx->r25) {
        // 0x8009F400: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_8009F4FC;
    }
    // 0x8009F400: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F404: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009F408: addiu       $t6, $t6, 0x25C4
    ctx->r14 = ADD32(ctx->r14, 0X25C4);
    // 0x8009F40C: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8009F410: nop

L_8009F414:
    // 0x8009F414: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009F418: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F41C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8009F420: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009F424: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F428: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009F42C: swc1        $f10, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f10.u32l;
    // 0x8009F430: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009F434: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F438: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8009F43C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8009F440: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x8009F444: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009F448: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8009F44C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009F450: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8009F454: nop

    // 0x8009F458: andi        $t6, $t8, 0xC000
    ctx->r14 = ctx->r24 & 0XC000;
    // 0x8009F45C: bne         $t0, $t6, L_8009F4A8
    if (ctx->r8 != ctx->r14) {
        // 0x8009F460: nop
    
            goto L_8009F4A8;
    }
    // 0x8009F460: nop

    // 0x8009F464: bne         $a3, $zero, L_8009F488
    if (ctx->r7 != 0) {
        // 0x8009F468: nop
    
            goto L_8009F488;
    }
    // 0x8009F468: nop

    // 0x8009F46C: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F470: nop

    // 0x8009F474: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009F478: nop

    // 0x8009F47C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F480: b           L_8009F4EC
    // 0x8009F484: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009F4EC;
    // 0x8009F484: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009F488:
    // 0x8009F488: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009F48C: nop

    // 0x8009F490: addiu       $t8, $t9, 0x6C
    ctx->r24 = ADD32(ctx->r25, 0X6C);
    // 0x8009F494: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009F498: nop

    // 0x8009F49C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F4A0: b           L_8009F4EC
    // 0x8009F4A4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
        goto L_8009F4EC;
    // 0x8009F4A4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009F4A8:
    // 0x8009F4A8: bne         $a3, $zero, L_8009F4D0
    if (ctx->r7 != 0) {
        // 0x8009F4AC: nop
    
            goto L_8009F4D0;
    }
    // 0x8009F4AC: nop

    // 0x8009F4B0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009F4B4: nop

    // 0x8009F4B8: addiu       $t7, $t6, 0x3C
    ctx->r15 = ADD32(ctx->r14, 0X3C);
    // 0x8009F4BC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009F4C0: nop

    // 0x8009F4C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F4C8: b           L_8009F4EC
    // 0x8009F4CC: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009F4EC;
    // 0x8009F4CC: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009F4D0:
    // 0x8009F4D0: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009F4D4: nop

    // 0x8009F4D8: addiu       $t8, $t9, -0x30
    ctx->r24 = ADD32(ctx->r25, -0X30);
    // 0x8009F4DC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009F4E0: nop

    // 0x8009F4E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F4E8: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009F4EC:
    // 0x8009F4EC: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8009F4F0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8009F4F4: bne         $t2, $a0, L_8009F414
    if (ctx->r10 != ctx->r4) {
        // 0x8009F4F8: nop
    
            goto L_8009F414;
    }
    // 0x8009F4F8: nop

L_8009F4FC:
    // 0x8009F4FC: lwc1        $f4, -0x7948($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7948);
    // 0x8009F500: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F504: lui         $at, 0x4377
    ctx->r1 = S32(0X4377 << 16);
    // 0x8009F508: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x8009F50C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F510: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F514: swc1        $f0, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f0.u32l;
    // 0x8009F518: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F51C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8009F520: swc1        $f6, 0x40C($t9)
    MEM_W(0X40C, ctx->r25) = ctx->f6.u32l;
    // 0x8009F524: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F52C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F530: swc1        $f8, 0x410($t8)
    MEM_W(0X410, ctx->r24) = ctx->f8.u32l;
    // 0x8009F534: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F538: lwc1        $f10, -0x7944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7944);
    // 0x8009F53C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009F540: swc1        $f10, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f10.u32l;
    // 0x8009F544: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F54C: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x8009F550: swc1        $f4, 0x670($t7)
    MEM_W(0X670, ctx->r15) = ctx->f4.u32l;
    // 0x8009F554: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F55C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009F560: swc1        $f6, 0x68C($t9)
    MEM_W(0X68C, ctx->r25) = ctx->f6.u32l;
    // 0x8009F564: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F56C: lui         $at, 0x4384
    ctx->r1 = S32(0X4384 << 16);
    // 0x8009F570: swc1        $f8, 0x690($t8)
    MEM_W(0X690, ctx->r24) = ctx->f8.u32l;
    // 0x8009F574: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F578: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F57C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8009F580: swc1        $f10, 0x6AC($t6)
    MEM_W(0X6AC, ctx->r14) = ctx->f10.u32l;
    // 0x8009F584: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F58C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F590: swc1        $f4, 0x6B0($t7)
    MEM_W(0X6B0, ctx->r15) = ctx->f4.u32l;
    // 0x8009F594: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F598: lwc1        $f6, -0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7940);
    // 0x8009F59C: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009F5A0: swc1        $f6, 0x6CC($t9)
    MEM_W(0X6CC, ctx->r25) = ctx->f6.u32l;
    // 0x8009F5A4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F5A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F5AC: lui         $at, 0x4389
    ctx->r1 = S32(0X4389 << 16);
    // 0x8009F5B0: swc1        $f8, 0x6D0($t8)
    MEM_W(0X6D0, ctx->r24) = ctx->f8.u32l;
    // 0x8009F5B4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F5B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009F5BC: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009F5C0: swc1        $f10, 0x6EC($t6)
    MEM_W(0X6EC, ctx->r14) = ctx->f10.u32l;
    // 0x8009F5C4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F5C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F5CC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009F5D0: swc1        $f4, 0x6F0($t7)
    MEM_W(0X6F0, ctx->r15) = ctx->f4.u32l;
    // 0x8009F5D4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F5D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F5DC: swc1        $f0, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f0.u32l;
    // 0x8009F5E0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F5E4: nop

    // 0x8009F5E8: sb          $t8, 0x5DC($t6)
    MEM_B(0X5DC, ctx->r14) = ctx->r24;
    // 0x8009F5EC: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x8009F5F0: b           L_8009F7BC
    // 0x8009F5F4: nop

        goto L_8009F7BC;
    // 0x8009F5F4: nop

L_8009F5F8:
    // 0x8009F5F8: beq         $t3, $v1, L_8009F604
    if (ctx->r11 == ctx->r3) {
        // 0x8009F5FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009F604;
    }
    // 0x8009F5FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F600: bne         $v1, $at, L_8009F7BC
    if (ctx->r3 != ctx->r1) {
        // 0x8009F604: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8009F7BC;
    }
L_8009F604:
    // 0x8009F604: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009F608: addiu       $v0, $a0, 0x2684
    ctx->r2 = ADD32(ctx->r4, 0X2684);
    // 0x8009F60C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009F610: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009F614: beq         $t2, $t7, L_8009F7BC
    if (ctx->r10 == ctx->r15) {
        // 0x8009F618: addiu       $t9, $t9, 0x2684
        ctx->r25 = ADD32(ctx->r25, 0X2684);
            goto L_8009F7BC;
    }
    // 0x8009F618: addiu       $t9, $t9, 0x2684
    ctx->r25 = ADD32(ctx->r25, 0X2684);
    // 0x8009F61C: lh          $v1, 0x0($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X0);
    // 0x8009F620: nop

L_8009F624:
    // 0x8009F624: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F628: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8009F62C: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8009F630: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x8009F634: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8009F638: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8009F63C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009F640: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x8009F644: nop

    // 0x8009F648: andi        $t7, $t9, 0xC000
    ctx->r15 = ctx->r25 & 0XC000;
    // 0x8009F64C: bne         $t0, $t7, L_8009F6F8
    if (ctx->r8 != ctx->r15) {
        // 0x8009F650: nop
    
            goto L_8009F6F8;
    }
    // 0x8009F650: nop

    // 0x8009F654: beq         $a3, $zero, L_8009F664
    if (ctx->r7 == 0) {
        // 0x8009F658: nop
    
            goto L_8009F664;
    }
    // 0x8009F658: nop

    // 0x8009F65C: bne         $a3, $t3, L_8009F680
    if (ctx->r7 != ctx->r11) {
        // 0x8009F660: nop
    
            goto L_8009F680;
    }
    // 0x8009F660: nop

L_8009F664:
    // 0x8009F664: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8009F668: nop

    // 0x8009F66C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009F670: nop

    // 0x8009F674: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F678: b           L_8009F69C
    // 0x8009F67C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009F69C;
    // 0x8009F67C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009F680:
    // 0x8009F680: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009F684: nop

    // 0x8009F688: addiu       $t9, $t6, 0xA0
    ctx->r25 = ADD32(ctx->r14, 0XA0);
    // 0x8009F68C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8009F690: nop

    // 0x8009F694: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009F698: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009F69C:
    // 0x8009F69C: beq         $a3, $zero, L_8009F6AC
    if (ctx->r7 == 0) {
        // 0x8009F6A0: nop
    
            goto L_8009F6AC;
    }
    // 0x8009F6A0: nop

    // 0x8009F6A4: bne         $a3, $t4, L_8009F6D0
    if (ctx->r7 != ctx->r12) {
        // 0x8009F6A8: nop
    
            goto L_8009F6D0;
    }
    // 0x8009F6A8: nop

L_8009F6AC:
    // 0x8009F6AC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F6B0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009F6B4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009F6B8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F6BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F6C0: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8009F6C4: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8009F6C8: b           L_8009F7A0
    // 0x8009F6CC: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
        goto L_8009F7A0;
    // 0x8009F6CC: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
L_8009F6D0:
    // 0x8009F6D0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009F6D4: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009F6D8: addiu       $t8, $t6, 0x6C
    ctx->r24 = ADD32(ctx->r14, 0X6C);
    // 0x8009F6DC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009F6E0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F6E4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009F6E8: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x8009F6EC: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8009F6F0: b           L_8009F7A0
    // 0x8009F6F4: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
        goto L_8009F7A0;
    // 0x8009F6F4: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
L_8009F6F8:
    // 0x8009F6F8: beq         $a3, $zero, L_8009F708
    if (ctx->r7 == 0) {
        // 0x8009F6FC: nop
    
            goto L_8009F708;
    }
    // 0x8009F6FC: nop

    // 0x8009F700: bne         $a3, $t3, L_8009F728
    if (ctx->r7 != ctx->r11) {
        // 0x8009F704: nop
    
            goto L_8009F728;
    }
    // 0x8009F704: nop

L_8009F708:
    // 0x8009F708: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009F70C: nop

    // 0x8009F710: addiu       $t9, $t7, -0x50
    ctx->r25 = ADD32(ctx->r15, -0X50);
    // 0x8009F714: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009F718: nop

    // 0x8009F71C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F720: b           L_8009F744
    // 0x8009F724: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009F744;
    // 0x8009F724: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009F728:
    // 0x8009F728: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009F72C: nop

    // 0x8009F730: addiu       $t8, $t6, 0x50
    ctx->r24 = ADD32(ctx->r14, 0X50);
    // 0x8009F734: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009F738: nop

    // 0x8009F73C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009F740: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009F744:
    // 0x8009F744: beq         $a3, $zero, L_8009F754
    if (ctx->r7 == 0) {
        // 0x8009F748: nop
    
            goto L_8009F754;
    }
    // 0x8009F748: nop

    // 0x8009F74C: bne         $a3, $t4, L_8009F77C
    if (ctx->r7 != ctx->r12) {
        // 0x8009F750: nop
    
            goto L_8009F77C;
    }
    // 0x8009F750: nop

L_8009F754:
    // 0x8009F754: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F758: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009F75C: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x8009F760: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009F764: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F768: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F76C: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8009F770: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009F774: b           L_8009F7A0
    // 0x8009F778: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
        goto L_8009F7A0;
    // 0x8009F778: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
L_8009F77C:
    // 0x8009F77C: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009F780: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F784: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8009F788: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009F78C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F790: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009F794: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x8009F798: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009F79C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
L_8009F7A0:
    // 0x8009F7A0: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8009F7A4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009F7A8: bne         $t2, $v1, L_8009F624
    if (ctx->r10 != ctx->r3) {
        // 0x8009F7AC: nop
    
            goto L_8009F624;
    }
    // 0x8009F7AC: nop

    // 0x8009F7B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F7B4: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x8009F7B8: nop

L_8009F7BC:
    // 0x8009F7BC: beq         $v1, $zero, L_8009F8D8
    if (ctx->r3 == 0) {
        // 0x8009F7C0: nop
    
            goto L_8009F8D8;
    }
    // 0x8009F7C0: nop

    // 0x8009F7C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009F7C8:
    // 0x8009F7C8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F7CC: nop

    // 0x8009F7D0: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F7D4: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x8009F7D8: nop

    // 0x8009F7DC: bne         $t5, $v0, L_8009F7EC
    if (ctx->r13 != ctx->r2) {
        // 0x8009F7E0: nop
    
            goto L_8009F7EC;
    }
    // 0x8009F7E0: nop

    // 0x8009F7E4: b           L_8009F8C0
    // 0x8009F7E8: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
        goto L_8009F8C0;
    // 0x8009F7E8: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
L_8009F7EC:
    // 0x8009F7EC: bne         $s3, $v0, L_8009F7FC
    if (ctx->r19 != ctx->r2) {
        // 0x8009F7F0: nop
    
            goto L_8009F7FC;
    }
    // 0x8009F7F0: nop

    // 0x8009F7F4: b           L_8009F8C0
    // 0x8009F7F8: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
        goto L_8009F8C0;
    // 0x8009F7F8: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
L_8009F7FC:
    // 0x8009F7FC: bne         $s5, $v0, L_8009F80C
    if (ctx->r21 != ctx->r2) {
        // 0x8009F800: nop
    
            goto L_8009F80C;
    }
    // 0x8009F800: nop

    // 0x8009F804: b           L_8009F8C0
    // 0x8009F808: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
        goto L_8009F8C0;
    // 0x8009F808: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
L_8009F80C:
    // 0x8009F80C: bne         $ra, $v0, L_8009F81C
    if (ctx->r31 != ctx->r2) {
        // 0x8009F810: nop
    
            goto L_8009F81C;
    }
    // 0x8009F810: nop

    // 0x8009F814: b           L_8009F8C0
    // 0x8009F818: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
        goto L_8009F8C0;
    // 0x8009F818: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
L_8009F81C:
    // 0x8009F81C: bne         $fp, $v0, L_8009F840
    if (ctx->r30 != ctx->r2) {
        // 0x8009F820: nop
    
            goto L_8009F840;
    }
    // 0x8009F820: nop

    // 0x8009F824: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009F828: nop

    // 0x8009F82C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009F830: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8009F834: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009F838: b           L_8009F8C0
    // 0x8009F83C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
        goto L_8009F8C0;
    // 0x8009F83C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009F840:
    // 0x8009F840: beq         $v1, $zero, L_8009F8C0
    if (ctx->r3 == 0) {
        // 0x8009F844: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8009F8C0;
    }
    // 0x8009F844: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8009F848: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F84C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8009F8C0;
    }
    // 0x8009F84C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8009F850: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F854: addiu       $at, $zero, 0x4A0
        ctx->r1 = ADD32(0, 0X4A0);
            goto L_8009F8C0;
    }
    // 0x8009F854: addiu       $at, $zero, 0x4A0
    ctx->r1 = ADD32(0, 0X4A0);
    // 0x8009F858: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F85C: addiu       $at, $zero, 0x5E0
        ctx->r1 = ADD32(0, 0X5E0);
            goto L_8009F8C0;
    }
    // 0x8009F85C: addiu       $at, $zero, 0x5E0
    ctx->r1 = ADD32(0, 0X5E0);
    // 0x8009F860: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F864: addiu       $at, $zero, 0x600
        ctx->r1 = ADD32(0, 0X600);
            goto L_8009F8C0;
    }
    // 0x8009F864: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8009F868: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F86C: addiu       $at, $zero, 0x60
        ctx->r1 = ADD32(0, 0X60);
            goto L_8009F8C0;
    }
    // 0x8009F86C: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8009F870: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F874: addiu       $at, $zero, 0x640
        ctx->r1 = ADD32(0, 0X640);
            goto L_8009F8C0;
    }
    // 0x8009F874: addiu       $at, $zero, 0x640
    ctx->r1 = ADD32(0, 0X640);
    // 0x8009F878: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F87C: addiu       $at, $zero, 0x660
        ctx->r1 = ADD32(0, 0X660);
            goto L_8009F8C0;
    }
    // 0x8009F87C: addiu       $at, $zero, 0x660
    ctx->r1 = ADD32(0, 0X660);
    // 0x8009F880: beq         $v1, $at, L_8009F8C0
    if (ctx->r3 == ctx->r1) {
        // 0x8009F884: slti        $at, $v1, 0x680
        ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
            goto L_8009F8C0;
    }
    // 0x8009F884: slti        $at, $v1, 0x680
    ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
    // 0x8009F888: bne         $at, $zero, L_8009F8A8
    if (ctx->r1 != 0) {
        // 0x8009F88C: slti        $at, $v1, 0x700
        ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
            goto L_8009F8A8;
    }
    // 0x8009F88C: slti        $at, $v1, 0x700
    ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
    // 0x8009F890: beq         $at, $zero, L_8009F8A8
    if (ctx->r1 == 0) {
        // 0x8009F894: addiu       $at, $zero, 0x380
        ctx->r1 = ADD32(0, 0X380);
            goto L_8009F8A8;
    }
    // 0x8009F894: addiu       $at, $zero, 0x380
    ctx->r1 = ADD32(0, 0X380);
    // 0x8009F898: beq         $v1, $at, L_8009F8A8
    if (ctx->r3 == ctx->r1) {
        // 0x8009F89C: addiu       $at, $zero, 0x120
        ctx->r1 = ADD32(0, 0X120);
            goto L_8009F8A8;
    }
    // 0x8009F89C: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x8009F8A0: bne         $v1, $at, L_8009F8C0
    if (ctx->r3 != ctx->r1) {
        // 0x8009F8A4: nop
    
            goto L_8009F8C0;
    }
    // 0x8009F8A4: nop

L_8009F8A8:
    // 0x8009F8A8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009F8AC: nop

    // 0x8009F8B0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009F8B4: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8009F8B8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009F8BC: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009F8C0:
    // 0x8009F8C0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009F8C4: bne         $v1, $s2, L_8009F7C8
    if (ctx->r3 != ctx->r18) {
        // 0x8009F8C8: nop
    
            goto L_8009F7C8;
    }
    // 0x8009F8C8: nop

    // 0x8009F8CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F8D0: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x8009F8D4: nop

L_8009F8D8:
    // 0x8009F8D8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8DC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8009F8E0: bne         $at, $zero, L_8009F9A0
    if (ctx->r1 != 0) {
        // 0x8009F8E4: nop
    
            goto L_8009F9A0;
    }
    // 0x8009F8E4: nop

    // 0x8009F8E8: swc1        $f22, 0x3C8($a0)
    MEM_W(0X3C8, ctx->r4) = ctx->f22.u32l;
    // 0x8009F8EC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8F0: nop

    // 0x8009F8F4: swc1        $f22, 0x3E8($t7)
    MEM_W(0X3E8, ctx->r15) = ctx->f22.u32l;
    // 0x8009F8F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8FC: nop

    // 0x8009F900: swc1        $f22, 0x3A8($t8)
    MEM_W(0X3A8, ctx->r24) = ctx->f22.u32l;
    // 0x8009F904: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F908: nop

    // 0x8009F90C: swc1        $f22, 0x188($t6)
    MEM_W(0X188, ctx->r14) = ctx->f22.u32l;
    // 0x8009F910: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F914: nop

    // 0x8009F918: swc1        $f22, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->f22.u32l;
    // 0x8009F91C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F920: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x8009F924: swc1        $f22, 0x468($t7)
    MEM_W(0X468, ctx->r15) = ctx->f22.u32l;
    // 0x8009F928: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F92C: nop

    // 0x8009F930: swc1        $f22, 0x488($t8)
    MEM_W(0X488, ctx->r24) = ctx->f22.u32l;
    // 0x8009F934: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F938: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x8009F93C: swc1        $f22, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->f22.u32l;
    // 0x8009F940: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F944: nop

    // 0x8009F948: sh          $t9, 0x3C6($t7)
    MEM_H(0X3C6, ctx->r15) = ctx->r25;
    // 0x8009F94C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F950: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8009F954: sh          $t8, 0x3E6($t6)
    MEM_H(0X3E6, ctx->r14) = ctx->r24;
    // 0x8009F958: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F95C: addiu       $t8, $zero, 0x25
    ctx->r24 = ADD32(0, 0X25);
    // 0x8009F960: sh          $t9, 0x3A6($t7)
    MEM_H(0X3A6, ctx->r15) = ctx->r25;
    // 0x8009F964: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F968: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8009F96C: sh          $t8, 0x186($t6)
    MEM_H(0X186, ctx->r14) = ctx->r24;
    // 0x8009F970: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F974: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8009F978: sh          $t9, 0x1A6($t7)
    MEM_H(0X1A6, ctx->r15) = ctx->r25;
    // 0x8009F97C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F980: addiu       $t9, $zero, 0x2C
    ctx->r25 = ADD32(0, 0X2C);
    // 0x8009F984: sh          $t8, 0x466($t6)
    MEM_H(0X466, ctx->r14) = ctx->r24;
    // 0x8009F988: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F98C: addiu       $t8, $zero, 0x2A
    ctx->r24 = ADD32(0, 0X2A);
    // 0x8009F990: sh          $t9, 0x486($t7)
    MEM_H(0X486, ctx->r15) = ctx->r25;
    // 0x8009F994: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009F998: b           L_8009F9B0
    // 0x8009F99C: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
        goto L_8009F9B0;
    // 0x8009F99C: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
L_8009F9A0:
    // 0x8009F9A0: sb          $t4, 0x5D($a0)
    MEM_B(0X5D, ctx->r4) = ctx->r12;
    // 0x8009F9A4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F9A8: nop

    // 0x8009F9AC: sb          $t4, 0x37D($t9)
    MEM_B(0X37D, ctx->r25) = ctx->r12;
L_8009F9B0:
    // 0x8009F9B0: jal         0x8000E4D8
    // 0x8009F9B4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_4;
    // 0x8009F9B4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009F9B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009F9BC: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8009F9C0: beq         $v0, $zero, L_8009FAD0
    if (ctx->r2 == 0) {
        // 0x8009F9C4: addiu       $a1, $a1, 0x6CDC
        ctx->r5 = ADD32(ctx->r5, 0X6CDC);
            goto L_8009FAD0;
    }
    // 0x8009F9C4: addiu       $a1, $a1, 0x6CDC
    ctx->r5 = ADD32(ctx->r5, 0X6CDC);
    // 0x8009F9C8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009F9CC: nop

    // 0x8009F9D0: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8009F9D4: nop

    // 0x8009F9D8: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009F9DC: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8009F9E0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009F9E4: nop

    // 0x8009F9E8: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8009F9EC: nop

    // 0x8009F9F0: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009F9F4: swc1        $f4, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f4.u32l;
    // 0x8009F9F8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009F9FC: nop

    // 0x8009FA00: lwc1        $f6, 0x12C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x8009FA04: nop

    // 0x8009FA08: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FA0C: swc1        $f8, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FA10: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA14: nop

    // 0x8009FA18: lwc1        $f10, 0x38C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x8009FA1C: nop

    // 0x8009FA20: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FA24: swc1        $f4, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FA28: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA2C: nop

    // 0x8009FA30: lwc1        $f6, 0x36C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x8009FA34: nop

    // 0x8009FA38: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FA3C: swc1        $f8, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FA40: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA44: nop

    // 0x8009FA48: lwc1        $f10, 0x24C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x8009FA4C: nop

    // 0x8009FA50: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FA54: swc1        $f4, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FA58: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA5C: nop

    // 0x8009FA60: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8009FA64: nop

    // 0x8009FA68: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FA6C: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FA70: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA74: nop

    // 0x8009FA78: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8009FA7C: nop

    // 0x8009FA80: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FA84: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x8009FA88: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA8C: nop

    // 0x8009FA90: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8009FA94: nop

    // 0x8009FA98: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FA9C: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FAA0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAA4: nop

    // 0x8009FAA8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8009FAAC: nop

    // 0x8009FAB0: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FAB4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FAB8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FABC: nop

    // 0x8009FAC0: lwc1        $f6, 0x20C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x8009FAC4: nop

    // 0x8009FAC8: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FACC: swc1        $f8, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f8.u32l;
L_8009FAD0:
    // 0x8009FAD0: jal         0x8006BD98
    // 0x8009FAD4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    level_type(rdram, ctx);
        goto after_5;
    // 0x8009FAD4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_5:
    // 0x8009FAD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009FADC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009FAE0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009FAE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009FAE8: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8009FAEC: addiu       $a1, $a1, 0x6CDC
    ctx->r5 = ADD32(ctx->r5, 0X6CDC);
    // 0x8009FAF0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009FAF4: beq         $v0, $at, L_8009FB10
    if (ctx->r2 == ctx->r1) {
        // 0x8009FAF8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009FB10;
    }
    // 0x8009FAF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009FAFC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8009FB00: beq         $v0, $at, L_8009FC1C
    if (ctx->r2 == ctx->r1) {
        // 0x8009FB04: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_8009FC1C;
    }
    // 0x8009FB04: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009FB08: b           L_8009FD20
    // 0x8009FB0C: nop

        goto L_8009FD20;
    // 0x8009FB0C: nop

L_8009FB10:
    // 0x8009FB10: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB14: nop

    // 0x8009FB18: lwc1        $f10, 0xEC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8009FB1C: nop

    // 0x8009FB20: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8009FB24: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x8009FB28: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB2C: nop

    // 0x8009FB30: lwc1        $f6, 0x10C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8009FB34: nop

    // 0x8009FB38: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8009FB3C: swc1        $f8, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FB40: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB44: nop

    // 0x8009FB48: lwc1        $f10, 0x12C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x8009FB4C: nop

    // 0x8009FB50: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8009FB54: swc1        $f4, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FB58: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB5C: nop

    // 0x8009FB60: lwc1        $f6, 0x38C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x8009FB64: nop

    // 0x8009FB68: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8009FB6C: swc1        $f8, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FB70: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB74: nop

    // 0x8009FB78: lwc1        $f10, 0x36C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x8009FB7C: nop

    // 0x8009FB80: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8009FB84: swc1        $f4, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FB88: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB8C: nop

    // 0x8009FB90: lwc1        $f6, 0x24C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x8009FB94: nop

    // 0x8009FB98: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8009FB9C: swc1        $f8, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FBA0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBA4: nop

    // 0x8009FBA8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8009FBAC: nop

    // 0x8009FBB0: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8009FBB4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FBB8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBBC: nop

    // 0x8009FBC0: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8009FBC4: nop

    // 0x8009FBC8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8009FBCC: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FBD0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBD4: nop

    // 0x8009FBD8: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8009FBDC: nop

    // 0x8009FBE0: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8009FBE4: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x8009FBE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBEC: nop

    // 0x8009FBF0: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8009FBF4: nop

    // 0x8009FBF8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8009FBFC: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FC00: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FC04: nop

    // 0x8009FC08: lwc1        $f10, 0x20C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x8009FC0C: nop

    // 0x8009FC10: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8009FC14: b           L_8009FD20
    // 0x8009FC18: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
        goto L_8009FD20;
    // 0x8009FC18: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
L_8009FC1C:
    // 0x8009FC1C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009FC20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009FC24: bne         $t7, $zero, L_8009FC44
    if (ctx->r15 != 0) {
        // 0x8009FC28: nop
    
            goto L_8009FC44;
    }
    // 0x8009FC28: nop

    // 0x8009FC2C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FC30: nop

    // 0x8009FC34: lwc1        $f6, 0x410($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X410);
    // 0x8009FC38: nop

    // 0x8009FC3C: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8009FC40: swc1        $f8, 0x410($a0)
    MEM_W(0X410, ctx->r4) = ctx->f8.u32l;
L_8009FC44:
    // 0x8009FC44: lbu         $v0, 0x6D37($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D37);
    // 0x8009FC48: nop

    // 0x8009FC4C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8009FC50: bne         $at, $zero, L_8009FC78
    if (ctx->r1 != 0) {
        // 0x8009FC54: nop
    
            goto L_8009FC78;
    }
    // 0x8009FC54: nop

    // 0x8009FC58: beq         $a3, $zero, L_8009FC68
    if (ctx->r7 == 0) {
        // 0x8009FC5C: nop
    
            goto L_8009FC68;
    }
    // 0x8009FC5C: nop

    // 0x8009FC60: bne         $a3, $t3, L_8009FC70
    if (ctx->r7 != ctx->r11) {
        // 0x8009FC64: nop
    
            goto L_8009FC70;
    }
    // 0x8009FC64: nop

L_8009FC68:
    // 0x8009FC68: b           L_8009FC8C
    // 0x8009FC6C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_8009FC8C;
    // 0x8009FC6C: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8009FC70:
    // 0x8009FC70: b           L_8009FC8C
    // 0x8009FC74: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_8009FC8C;
    // 0x8009FC74: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
L_8009FC78:
    // 0x8009FC78: bne         $t4, $v0, L_8009FC8C
    if (ctx->r12 != ctx->r2) {
        // 0x8009FC7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009FC8C;
    }
    // 0x8009FC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009FC80: b           L_8009FC8C
    // 0x8009FC84: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_8009FC8C;
    // 0x8009FC84: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // 0x8009FC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009FC8C:
    // 0x8009FC8C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8009FC90: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FC94: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FC98: lwc1        $f4, 0x36C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x8009FC9C: nop

    // 0x8009FCA0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009FCA4: swc1        $f6, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f6.u32l;
    // 0x8009FCA8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCAC: nop

    // 0x8009FCB0: lwc1        $f8, 0xEC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8009FCB4: nop

    // 0x8009FCB8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8009FCBC: swc1        $f10, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f10.u32l;
    // 0x8009FCC0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCC4: nop

    // 0x8009FCC8: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8009FCCC: nop

    // 0x8009FCD0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009FCD4: swc1        $f6, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f6.u32l;
    // 0x8009FCD8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCDC: nop

    // 0x8009FCE0: lwc1        $f8, 0x12C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x8009FCE4: nop

    // 0x8009FCE8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8009FCEC: swc1        $f10, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f10.u32l;
    // 0x8009FCF0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCF4: nop

    // 0x8009FCF8: lwc1        $f4, 0x38C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x8009FCFC: nop

    // 0x8009FD00: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009FD04: swc1        $f6, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f6.u32l;
    // 0x8009FD08: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FD0C: nop

    // 0x8009FD10: lwc1        $f8, 0x24C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x8009FD14: nop

    // 0x8009FD18: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8009FD1C: swc1        $f10, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f10.u32l;
L_8009FD20:
    // 0x8009FD20: jal         0x8002341C
    // 0x8009FD24: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x8009FD24: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_6:
    // 0x8009FD28: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8009FD2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009FD30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FD34: lwc1        $f13, -0x7918($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, -0X7918);
    // 0x8009FD38: lwc1        $f12, -0x7914($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7914);
    // 0x8009FD3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FD40: lwc1        $f15, -0x7910($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X7910);
    // 0x8009FD44: lwc1        $f14, -0x790C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X790C);
    // 0x8009FD48: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8009FD4C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009FD50: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009FD54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009FD58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009FD5C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8009FD60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009FD64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009FD68: addiu       $t1, $t1, 0x6CF0
    ctx->r9 = ADD32(ctx->r9, 0X6CF0);
    // 0x8009FD6C: addiu       $a1, $a1, 0x6CDC
    ctx->r5 = ADD32(ctx->r5, 0X6CDC);
    // 0x8009FD70: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
    // 0x8009FD74: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8009FD78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009FD7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009FD80: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8009FD84: beq         $v0, $zero, L_8009FE04
    if (ctx->r2 == 0) {
        // 0x8009FD88: addiu       $ra, $zero, 0x12
        ctx->r31 = ADD32(0, 0X12);
            goto L_8009FE04;
    }
    // 0x8009FD88: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x8009FD8C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FD90: nop

    // 0x8009FD94: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8009FD98: nop

    // 0x8009FD9C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8009FDA0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8009FDA4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FDA8: nop

    // 0x8009FDAC: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8009FDB0: nop

    // 0x8009FDB4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8009FDB8: swc1        $f10, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f10.u32l;
    // 0x8009FDBC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FDC0: nop

    // 0x8009FDC4: lwc1        $f4, 0xAC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8009FDC8: nop

    // 0x8009FDCC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8009FDD0: swc1        $f6, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f6.u32l;
    // 0x8009FDD4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FDD8: nop

    // 0x8009FDDC: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8009FDE0: nop

    // 0x8009FDE4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8009FDE8: swc1        $f10, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f10.u32l;
    // 0x8009FDEC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FDF0: nop

    // 0x8009FDF4: lwc1        $f4, 0x20C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x8009FDF8: nop

    // 0x8009FDFC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8009FE00: swc1        $f6, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f6.u32l;
L_8009FE04:
    // 0x8009FE04: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8009FE08: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8009FE0C: nop

    // 0x8009FE10: bne         $t8, $zero, L_8009FF60
    if (ctx->r24 != 0) {
        // 0x8009FE14: nop
    
            goto L_8009FF60;
    }
    // 0x8009FE14: nop

    // 0x8009FE18: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009FE20: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_8009FE24:
    // 0x8009FE24: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009FE28: nop

    // 0x8009FE2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8009FE30: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8009FE34: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8009FE38: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8009FE3C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE40: nop

    // 0x8009FE44: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8009FE48: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009FE4C: nop

    // 0x8009FE50: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8009FE54: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8009FE58: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE5C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8009FE60: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8009FE64: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8009FE68: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009FE6C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009FE70: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8009FE74: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8009FE78: slti        $at, $v1, 0x760
    ctx->r1 = SIGNED(ctx->r3) < 0X760 ? 1 : 0;
    // 0x8009FE7C: andi        $t9, $t7, 0xC000
    ctx->r25 = ctx->r15 & 0XC000;
    // 0x8009FE80: bne         $t0, $t9, L_8009FEA0
    if (ctx->r8 != ctx->r25) {
        // 0x8009FE84: nop
    
            goto L_8009FEA0;
    }
    // 0x8009FE84: nop

    // 0x8009FE88: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009FE8C: nop

    // 0x8009FE90: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8009FE94: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8009FE98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE9C: nop

L_8009FEA0:
    // 0x8009FEA0: bne         $at, $zero, L_8009FE24
    if (ctx->r1 != 0) {
        // 0x8009FEA4: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8009FE24;
    }
    // 0x8009FEA4: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8009FEA8: addiu       $v0, $a0, 0x4E0
    ctx->r2 = ADD32(ctx->r4, 0X4E0);
    // 0x8009FEAC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009FEB0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x8009FEB4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8009FEB8: sll         $v1, $a2, 5
    ctx->r3 = S32(ctx->r6 << 5);
    // 0x8009FEBC: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8009FEC0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEC4: nop

    // 0x8009FEC8: lwc1        $f4, 0x510($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X510);
    // 0x8009FECC: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x8009FED0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8009FED4: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x8009FED8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEDC: nop

    // 0x8009FEE0: lwc1        $f8, 0x530($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X530);
    // 0x8009FEE4: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x8009FEE8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8009FEEC: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x8009FEF0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEF4: nop

    // 0x8009FEF8: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x8009FEFC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009FF00: nop

    // 0x8009FF04: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8009FF08: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8009FF0C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF10: nop

    // 0x8009FF14: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8009FF18: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8009FF1C: nop

    // 0x8009FF20: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8009FF24: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x8009FF28: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF2C: nop

    // 0x8009FF30: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8009FF34: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8009FF38: nop

    // 0x8009FF3C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8009FF40: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x8009FF44: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF48: nop

    // 0x8009FF4C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8009FF50: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8009FF54: nop

    // 0x8009FF58: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8009FF5C: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
L_8009FF60:
    // 0x8009FF60: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF64: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009FF68: swc1        $f22, 0x268($t8)
    MEM_W(0X268, ctx->r24) = ctx->f22.u32l;
    // 0x8009FF6C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF70: nop

    // 0x8009FF74: sh          $ra, 0x286($t6)
    MEM_H(0X286, ctx->r14) = ctx->r31;
    // 0x8009FF78: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF7C: nop

    // 0x8009FF80: sh          $t5, 0x2A6($t7)
    MEM_H(0X2A6, ctx->r15) = ctx->r13;
    // 0x8009FF84: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF88: nop

    // 0x8009FF8C: sh          $t5, 0x2C6($t9)
    MEM_H(0X2C6, ctx->r25) = ctx->r13;
    // 0x8009FF90: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009FF94: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8009FF98: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x8009FF9C: bne         $a3, $t7, L_8009F2D8
    if (ctx->r7 != ctx->r15) {
        // 0x8009FFA0: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8009F2D8;
    }
    // 0x8009FFA0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_8009FFA4:
    // 0x8009FFA4: jal         0x8006BD98
    // 0x8009FFA8: nop

    level_type(rdram, ctx);
        goto after_7;
    // 0x8009FFA8: nop

    after_7:
    // 0x8009FFAC: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x8009FFB0: beq         $t9, $zero, L_8009FFD4
    if (ctx->r25 == 0) {
        // 0x8009FFB4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8009FFD4;
    }
    // 0x8009FFB4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009FFB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009FFBC: addiu       $v0, $v0, 0x27A4
    ctx->r2 = ADD32(ctx->r2, 0X27A4);
    // 0x8009FFC0: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8009FFC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009FFC8: sb          $t8, 0x27A8($at)
    MEM_B(0X27A8, ctx->r1) = ctx->r24;
    // 0x8009FFCC: b           L_8009FFE4
    // 0x8009FFD0: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
        goto L_8009FFE4;
    // 0x8009FFD0: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_8009FFD4:
    // 0x8009FFD4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009FFD8: lb          $t6, 0x27A8($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X27A8);
    // 0x8009FFDC: addiu       $v0, $v0, 0x27A4
    ctx->r2 = ADD32(ctx->r2, 0X27A4);
    // 0x8009FFE0: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_8009FFE4:
    // 0x8009FFE4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8009FFE8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8009FFEC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009FFF0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8009FFF4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009FFF8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8009FFFC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A0000: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800A0004: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A0008: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800A000C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A0010: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800A0014: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800A0018: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800A001C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800A0020: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800A0024: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800A0028: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800A002C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800A0030: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800A0034: jr          $ra
    // 0x800A0038: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A0038: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void obj_shade_fancy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D6E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D6E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D6EC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D6F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D6F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001D6F8: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x8001D6FC: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8001D700: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001D704: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D708: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001D70C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001D710: blez        $t0, L_8001D774
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001D714: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001D774;
    }
    // 0x8001D714: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D718: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8001D71C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001D720: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8001D724:
    // 0x8001D724: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D728: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001D72C: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x8001D730: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001D734: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001D738: mflo        $t6
    ctx->r14 = lo;
    // 0x8001D73C: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D740: lbu         $t7, 0x6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X6);
    // 0x8001D744: nop

    // 0x8001D748: beq         $a0, $t7, L_8001D754
    if (ctx->r4 == ctx->r15) {
        // 0x8001D74C: nop
    
            goto L_8001D754;
    }
    // 0x8001D74C: nop

    // 0x8001D750: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8001D754:
    // 0x8001D754: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8001D758: nop

    // 0x8001D75C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001D760: beq         $t9, $zero, L_8001D76C
    if (ctx->r25 == 0) {
        // 0x8001D764: nop
    
            goto L_8001D76C;
    }
    // 0x8001D764: nop

    // 0x8001D768: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8001D76C:
    // 0x8001D76C: bne         $at, $zero, L_8001D724
    if (ctx->r1 != 0) {
        // 0x8001D770: nop
    
            goto L_8001D724;
    }
    // 0x8001D770: nop

L_8001D774:
    // 0x8001D774: beq         $a3, $zero, L_8001D7DC
    if (ctx->r7 == 0) {
        // 0x8001D778: nop
    
            goto L_8001D7DC;
    }
    // 0x8001D778: nop

    // 0x8001D77C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x8001D780: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D784: lbu         $t5, 0x71($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X71);
    // 0x8001D788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D78C: beq         $t5, $zero, L_8001D7C8
    if (ctx->r13 == 0) {
        // 0x8001D790: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8001D7C8;
    }
    // 0x8001D790: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D794: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D79C: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D7A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D7A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D7A8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001D7AC: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8001D7B0: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8001D7B4: jal         0x8001D80C
    // 0x8001D7B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    calc_dynamic_lighting_for_object_1(rdram, ctx);
        goto after_0;
    // 0x8001D7B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D7BC: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D7C0: b           L_8001D7DC
    // 0x8001D7C4: nop

        goto L_8001D7DC;
    // 0x8001D7C4: nop

L_8001D7C8:
    // 0x8001D7C8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8001D7CC: jal         0x80024744
    // 0x8001D7D0: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    calc_dynamic_lighting_for_object_2(rdram, ctx);
        goto after_1;
    // 0x8001D7D0: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D7D4: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D7D8: nop

L_8001D7DC:
    // 0x8001D7DC: beq         $t1, $zero, L_8001D7FC
    if (ctx->r9 == 0) {
        // 0x8001D7E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D7FC;
    }
    // 0x8001D7E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D7E4: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8001D7E8: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x8001D7EC: lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X0);
    // 0x8001D7F0: jal         0x8001DD54
    // 0x8001D7F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    calc_env_mapping_for_object(rdram, ctx);
        goto after_2;
    // 0x8001D7F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8001D7F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D7FC:
    // 0x8001D7FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D800: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D804: jr          $ra
    // 0x8001D808: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001D808: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_file_extension(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073C5C: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80073C60: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80073C64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80073C68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80073C6C: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80073C70: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x80073C74: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80073C78: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80073C7C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80073C80: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80073C84: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80073C88: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80073C8C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80073C90: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80073C94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80073C98: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80073C9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073CA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80073CA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073CA8: addiu       $a2, $sp, 0x100
    ctx->r6 = ADD32(ctx->r29, 0X100);
    // 0x80073CAC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80073CB0: jal         0x80075E60
    // 0x80073CB4: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    get_controller_pak_file_list(rdram, ctx);
        goto after_0;
    // 0x80073CB4: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    after_0:
    // 0x80073CB8: bne         $v0, $zero, L_80073DE8
    if (ctx->r2 != 0) {
        // 0x80073CBC: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80073DE8;
    }
    // 0x80073CBC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80073CC0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80073CC4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80073CC8: addiu       $s7, $s7, 0x7640
    ctx->r23 = ADD32(ctx->r23, 0X7640);
    // 0x80073CCC: addiu       $fp, $fp, 0x7630
    ctx->r30 = ADD32(ctx->r30, 0X7630);
    // 0x80073CD0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80073CD4: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x80073CD8: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x80073CDC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80073CE0: addiu       $s5, $sp, 0x140
    ctx->r21 = ADD32(ctx->r29, 0X140);
L_80073CE4:
    // 0x80073CE4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80073CE8: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x80073CEC: beq         $t8, $zero, L_80073D78
    if (ctx->r24 == 0) {
        // 0x80073CF0: nop
    
            goto L_80073D78;
    }
    // 0x80073CF0: nop

    // 0x80073CF4: bne         $t9, $s6, L_80073D24
    if (ctx->r25 != ctx->r22) {
        // 0x80073CF8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80073D24;
    }
    // 0x80073CF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80073CFC: jal         0x800CE19C
    // 0x80073D00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80073D00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80073D04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073D08: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80073D0C: jal         0x800CE050
    // 0x80073D10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _bcmp(rdram, ctx);
        goto after_2;
    // 0x80073D10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80073D14: beq         $v0, $zero, L_80073D48
    if (ctx->r2 == 0) {
        // 0x80073D18: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073D48;
    }
    // 0x80073D18: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
    // 0x80073D1C: b           L_80073D7C
    // 0x80073D20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80073D7C;
    // 0x80073D20: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073D24:
    // 0x80073D24: jal         0x800CE19C
    // 0x80073D28: addiu       $a0, $a0, 0x7660
    ctx->r4 = ADD32(ctx->r4, 0X7660);
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x80073D28: addiu       $a0, $a0, 0x7660
    ctx->r4 = ADD32(ctx->r4, 0X7660);
    after_3:
    // 0x80073D2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073D30: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80073D34: addiu       $a1, $a1, 0x7650
    ctx->r5 = ADD32(ctx->r5, 0X7650);
    // 0x80073D38: jal         0x800CE050
    // 0x80073D3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _bcmp(rdram, ctx);
        goto after_4;
    // 0x80073D3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80073D40: bne         $v0, $zero, L_80073D78
    if (ctx->r2 != 0) {
        // 0x80073D44: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073D78;
    }
    // 0x80073D44: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
L_80073D48:
    // 0x80073D48: lw          $t0, 0xC0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XC0);
    // 0x80073D4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80073D50: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80073D54: nop

    // 0x80073D58: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073D5C: beq         $at, $zero, L_80073D6C
    if (ctx->r1 == 0) {
        // 0x80073D60: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073D6C;
    }
    // 0x80073D60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073D64: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80073D68: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
L_80073D6C:
    // 0x80073D6C: addiu       $t1, $v1, 0x1F
    ctx->r9 = ADD32(ctx->r3, 0X1F);
    // 0x80073D70: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80073D74: or          $s1, $s1, $t3
    ctx->r17 = ctx->r17 | ctx->r11;
L_80073D78:
    // 0x80073D78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073D7C:
    // 0x80073D7C: bne         $s0, $s5, L_80073CE4
    if (ctx->r16 != ctx->r21) {
        // 0x80073D80: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80073CE4;
    }
    // 0x80073D80: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80073D84: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80073D88: lw          $v0, 0x148($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X148);
    // 0x80073D8C: bne         $s4, $at, L_80073DA0
    if (ctx->r20 != ctx->r1) {
        // 0x80073D90: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80073DA0;
    }
    // 0x80073D90: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80073D94: b           L_80073DE0
    // 0x80073D98: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
        goto L_80073DE0;
    // 0x80073D98: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
    // 0x80073D9C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_80073DA0:
    // 0x80073DA0: bne         $s4, $at, L_80073DD8
    if (ctx->r20 != ctx->r1) {
        // 0x80073DA4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80073DD8;
    }
    // 0x80073DA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073DA8: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
L_80073DAC:
    // 0x80073DAC: andi        $t4, $s1, 0x1
    ctx->r12 = ctx->r17 & 0X1;
    // 0x80073DB0: beq         $t4, $zero, L_80073DE0
    if (ctx->r12 == 0) {
        // 0x80073DB4: sra         $t5, $s1, 1
        ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80073DE0;
    }
    // 0x80073DB4: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80073DB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80073DBC: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80073DC0: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x80073DC4: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80073DC8: bne         $at, $zero, L_80073DAC
    if (ctx->r1 != 0) {
        // 0x80073DCC: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_80073DAC;
    }
    // 0x80073DCC: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80073DD0: b           L_80073DE4
    // 0x80073DD4: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
        goto L_80073DE4;
    // 0x80073DD4: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80073DD8:
    // 0x80073DD8: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x80073DDC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80073DE0:
    // 0x80073DE0: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80073DE4:
    // 0x80073DE4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_80073DE8:
    // 0x80073DE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80073DEC: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80073DF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80073DF4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80073DF8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80073DFC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80073E00: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80073E04: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80073E08: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80073E0C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80073E10: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80073E14: jr          $ra
    // 0x80073E18: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x80073E18: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void viewport_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800682AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800682B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800682B4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800682B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800682BC: sw          $t6, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r14;
    // 0x800682C0: jal         0x8007A520
    // 0x800682C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800682C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800682C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800682CC: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800682D0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800682D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800682D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800682DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800682E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800682E4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800682E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800682EC: lw          $t9, -0x2F6C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2F6C);
    // 0x800682F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800682F4: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x800682F8: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x800682FC: bne         $t2, $zero, L_800683D4
    if (ctx->r10 != 0) {
        // 0x80068300: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_800683D4;
    }
    // 0x80068300: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80068304: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068308: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x8006830C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80068310: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80068314: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80068318: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006831C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80068320: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x80068324: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80068328: bgez        $t5, L_80068340
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006832C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80068340;
    }
    // 0x8006832C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80068330: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80068334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068338: nop

    // 0x8006833C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80068340:
    // 0x80068340: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80068344: addiu       $t2, $t0, -0x1
    ctx->r10 = ADD32(ctx->r8, -0X1);
    // 0x80068348: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006834C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80068350: nop

    // 0x80068354: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80068358: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006835C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068360: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80068364: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80068368: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8006836C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80068370: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80068374: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80068378: bgez        $t2, L_8006838C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006837C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006838C;
    }
    // 0x8006837C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80068380: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068384: nop

    // 0x80068388: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8006838C:
    // 0x8006838C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80068390: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80068394: srl         $a1, $t1, 1
    ctx->r5 = S32(U32(ctx->r9) >> 1);
    // 0x80068398: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8006839C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800683A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800683A4: srl         $a2, $t0, 1
    ctx->r6 = S32(U32(ctx->r8) >> 1);
    // 0x800683A8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800683AC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800683B0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800683B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800683B8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800683BC: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800683C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800683C4: jal         0x80068158
    // 0x800683C8: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    viewport_rsp_set(rdram, ctx);
        goto after_1;
    // 0x800683C8: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    after_1:
    // 0x800683CC: b           L_800683F8
    // 0x800683D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800683F8;
    // 0x800683D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800683D4:
    // 0x800683D4: jal         0x80067A3C
    // 0x800683D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x800683D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x800683DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800683E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800683E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800683E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800683EC: jal         0x80068158
    // 0x800683F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_3;
    // 0x800683F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x800683F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800683F8:
    // 0x800683F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800683FC: sw          $zero, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = 0;
    // 0x80068400: jr          $ra
    // 0x80068404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void race_check_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019808: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8001980C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80019810: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80019814: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80019818: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001981C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80019820: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80019824: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80019828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001982C: jal         0x8006BDB0
    // 0x80019830: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80019830: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019834: jal         0x8006EA90
    // 0x80019838: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x80019838: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001983C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80019840: sh          $zero, 0x88($sp)
    MEM_H(0X88, ctx->r29) = 0;
    // 0x80019844: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x80019848: lb          $v1, 0x4C($ra)
    ctx->r3 = MEM_B(ctx->r31, 0X4C);
    // 0x8001984C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80019850: beq         $v1, $zero, L_80019EDC
    if (ctx->r3 == 0) {
        // 0x80019854: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019EDC;
    }
    // 0x80019854: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80019858: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001985C: beq         $v1, $at, L_80019EDC
    if (ctx->r3 == ctx->r1) {
        // 0x80019860: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80019EDC;
    }
    // 0x80019860: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80019864: beq         $v1, $at, L_80019EDC
    if (ctx->r3 == ctx->r1) {
        // 0x80019868: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_80019EDC;
    }
    // 0x80019868: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x8001986C: beq         $t6, $zero, L_8001A7B0
    if (ctx->r14 == 0) {
        // 0x80019870: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_8001A7B0;
    }
    // 0x80019870: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80019874: bne         $v1, $at, L_80019898
    if (ctx->r3 != ctx->r1) {
        // 0x80019878: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80019898;
    }
    // 0x80019878: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001987C: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x80019880: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x80019884: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80019888: jal         0x80045128
    // 0x8001988C: nop

    racer_update_eggs(rdram, ctx);
        goto after_2;
    // 0x8001988C: nop

    after_2:
    // 0x80019890: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80019894: nop

L_80019898:
    // 0x80019898: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001989C: lw          $t7, -0x524C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X524C);
    // 0x800198A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800198A4: bne         $t7, $zero, L_8001A7B0
    if (ctx->r15 != 0) {
        // 0x800198A8: addiu       $t3, $t3, -0x511C
        ctx->r11 = ADD32(ctx->r11, -0X511C);
            goto L_8001A7B0;
    }
    // 0x800198A8: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x800198AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800198B0: addiu       $s2, $s2, -0x5110
    ctx->r18 = ADD32(ctx->r18, -0X5110);
    // 0x800198B4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800198B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800198BC: blez        $a3, L_80019A58
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800198C0: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80019A58;
    }
    // 0x800198C0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800198C4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800198C8: addiu       $s1, $s1, -0x5240
    ctx->r17 = ADD32(ctx->r17, -0X5240);
    // 0x800198CC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800198D0: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800198D4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800198D8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_800198DC:
    // 0x800198DC: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800198E0: nop

    // 0x800198E4: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x800198E8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800198EC: nop

    // 0x800198F0: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800198F4: nop

    // 0x800198F8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800198FC: lb          $t8, 0x4C($ra)
    ctx->r24 = MEM_B(ctx->r31, 0X4C);
    // 0x80019900: nop

    // 0x80019904: bne         $t1, $t8, L_800199CC
    if (ctx->r9 != ctx->r24) {
        // 0x80019908: nop
    
            goto L_800199CC;
    }
    // 0x80019908: nop

    // 0x8001990C: lb          $t9, 0x185($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X185);
    // 0x80019910: nop

    // 0x80019914: bgtz        $t9, L_800199CC
    if (SIGNED(ctx->r25) > 0) {
        // 0x80019918: nop
    
            goto L_800199CC;
    }
    // 0x80019918: nop

    // 0x8001991C: lb          $t6, 0x1D8($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X1D8);
    // 0x80019920: nop

    // 0x80019924: bne         $t6, $zero, L_800199CC
    if (ctx->r14 != 0) {
        // 0x80019928: nop
    
            goto L_800199CC;
    }
    // 0x80019928: nop

    // 0x8001992C: sb          $s4, 0x1D8($t7)
    MEM_B(0X1D8, ctx->r15) = ctx->r20;
    // 0x80019930: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80019934: nop

    // 0x80019938: sb          $zero, 0x173($t7)
    MEM_B(0X173, ctx->r15) = 0;
    // 0x8001993C: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80019940: nop

    // 0x80019944: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x80019948: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001994C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80019950: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80019954: jal         0x80006AC8
    // 0x80019958: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    racer_sound_free(rdram, ctx);
        goto after_3;
    // 0x80019958: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8001995C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019960: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x80019964: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80019968: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001996C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80019970: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80019974: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80019978: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001997C: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x80019980: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019984: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x80019988: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x8001998C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80019990: nop

    // 0x80019994: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80019998: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001999C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800199A0: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x800199A4: nop

    // 0x800199A8: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x800199AC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800199B0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800199B4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800199B8: sh          $t8, 0x1AC($t9)
    MEM_H(0X1AC, ctx->r25) = ctx->r24;
    // 0x800199BC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800199C0: nop

    // 0x800199C4: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800199C8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_800199CC:
    // 0x800199CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800199D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800199D4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800199D8: lb          $v1, 0x1D8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1D8);
    // 0x800199DC: beq         $s5, $t8, L_80019A0C
    if (ctx->r21 == ctx->r24) {
        // 0x800199E0: nop
    
            goto L_80019A0C;
    }
    // 0x800199E0: nop

    // 0x800199E4: beq         $v1, $zero, L_80019A00
    if (ctx->r3 == 0) {
        // 0x800199E8: lh          $t6, 0x8A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X8A);
            goto L_80019A00;
    }
    // 0x800199E8: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x800199EC: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x800199F0: nop

    // 0x800199F4: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800199F8: sh          $t7, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r15;
    // 0x800199FC: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
L_80019A00:
    // 0x80019A00: nop

    // 0x80019A04: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80019A08: sh          $t8, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r24;
L_80019A0C:
    // 0x80019A0C: beq         $v1, $zero, L_80019A44
    if (ctx->r3 == 0) {
        // 0x80019A10: nop
    
            goto L_80019A44;
    }
    // 0x80019A10: nop

    // 0x80019A14: lh          $t6, 0x1AC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1AC);
    // 0x80019A18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80019A1C: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x80019A20: bne         $t6, $zero, L_80019A44
    if (ctx->r14 != 0) {
        // 0x80019A24: sra         $s3, $t9, 16
        ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
            goto L_80019A44;
    }
    // 0x80019A24: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80019A28: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019A2C: nop

    // 0x80019A30: sh          $t8, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = ctx->r24;
    // 0x80019A34: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80019A38: nop

    // 0x80019A3C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80019A40: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_80019A44:
    // 0x80019A44: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019A48: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80019A4C: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019A50: bne         $at, $zero, L_800198DC
    if (ctx->r1 != 0) {
        // 0x80019A54: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800198DC;
    }
    // 0x80019A54: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80019A58:
    // 0x80019A58: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019A5C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019A60: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80019A64: addiu       $s1, $s1, -0x5240
    ctx->r17 = ADD32(ctx->r17, -0X5240);
    // 0x80019A68: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019A6C: beq         $t1, $t6, L_80019A7C
    if (ctx->r9 == ctx->r14) {
        // 0x80019A70: addiu       $s5, $zero, -0x1
        ctx->r21 = ADD32(0, -0X1);
            goto L_80019A7C;
    }
    // 0x80019A70: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80019A74: bgtz        $s3, L_80019AB8
    if (SIGNED(ctx->r19) > 0) {
        // 0x80019A78: nop
    
            goto L_80019AB8;
    }
    // 0x80019A78: nop

L_80019A7C:
    // 0x80019A7C: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x80019A80: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x80019A84: bne         $t8, $s4, L_80019A98
    if (ctx->r24 != ctx->r20) {
        // 0x80019A88: lh          $t7, 0x8A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X8A);
            goto L_80019A98;
    }
    // 0x80019A88: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
    // 0x80019A8C: beq         $t9, $s4, L_80019AB8
    if (ctx->r25 == ctx->r20) {
        // 0x80019A90: nop
    
            goto L_80019AB8;
    }
    // 0x80019A90: nop

    // 0x80019A94: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
L_80019A98:
    // 0x80019A98: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x80019A9C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80019AA0: bne         $at, $zero, L_80019AAC
    if (ctx->r1 != 0) {
        // 0x80019AA4: slt         $at, $t6, $t7
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_80019AAC;
    }
    // 0x80019AA4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80019AA8: beq         $at, $zero, L_80019AB8
    if (ctx->r1 == 0) {
        // 0x80019AAC: slti        $at, $s3, 0x3
        ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
            goto L_80019AB8;
    }
L_80019AAC:
    // 0x80019AAC: slti        $at, $s3, 0x3
    ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x80019AB0: bne         $at, $zero, L_8001A7B0
    if (ctx->r1 != 0) {
        // 0x80019AB4: nop
    
            goto L_8001A7B0;
    }
    // 0x80019AB4: nop

L_80019AB8:
    // 0x80019AB8: blez        $a3, L_80019BC0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019ABC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80019BC0;
    }
    // 0x80019ABC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019AC0: addiu       $v1, $sp, 0x5C
    ctx->r3 = ADD32(ctx->r29, 0X5C);
    // 0x80019AC4: addu        $a0, $a3, $v1
    ctx->r4 = ADD32(ctx->r7, ctx->r3);
    // 0x80019AC8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80019ACC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80019AD0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80019AD4: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
L_80019AD8:
    // 0x80019AD8: lb          $t9, 0x4C($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X4C);
    // 0x80019ADC: nop

    // 0x80019AE0: bne         $t1, $t9, L_80019B04
    if (ctx->r9 != ctx->r25) {
        // 0x80019AE4: nop
    
            goto L_80019B04;
    }
    // 0x80019AE4: nop

    // 0x80019AE8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80019AEC: nop

    // 0x80019AF0: lb          $t7, 0x185($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X185);
    // 0x80019AF4: nop

    // 0x80019AF8: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80019AFC: b           L_80019B80
    // 0x80019B00: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_80019B80;
    // 0x80019B00: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80019B04:
    // 0x80019B04: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80019B08: nop

    // 0x80019B0C: lb          $t9, 0x193($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X193);
    // 0x80019B10: nop

    // 0x80019B14: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80019B18: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019B1C: nop

    // 0x80019B20: bne         $a2, $t6, L_80019B80
    if (ctx->r6 != ctx->r14) {
        // 0x80019B24: nop
    
            goto L_80019B80;
    }
    // 0x80019B24: nop

    // 0x80019B28: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80019B2C: nop

    // 0x80019B30: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B34: mflo        $t8
    ctx->r24 = lo;
    // 0x80019B38: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80019B3C: lb          $t9, 0x1CF($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1CF);
    // 0x80019B40: nop

    // 0x80019B44: beq         $t9, $zero, L_80019B60
    if (ctx->r25 == 0) {
        // 0x80019B48: nop
    
            goto L_80019B60;
    }
    // 0x80019B48: nop

    // 0x80019B4C: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x80019B50: nop

    // 0x80019B54: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80019B58: b           L_80019B80
    // 0x80019B5C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_80019B80;
    // 0x80019B5C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80019B60:
    // 0x80019B60: lw          $t8, 0x144($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X144);
    // 0x80019B64: nop

    // 0x80019B68: beq         $t8, $zero, L_80019B80
    if (ctx->r24 == 0) {
        // 0x80019B6C: nop
    
            goto L_80019B80;
    }
    // 0x80019B6C: nop

    // 0x80019B70: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x80019B74: nop

    // 0x80019B78: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80019B7C: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_80019B80:
    // 0x80019B80: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019B84: nop

    // 0x80019B88: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80019B8C: bne         $at, $zero, L_80019BA0
    if (ctx->r1 != 0) {
        // 0x80019B90: nop
    
            goto L_80019BA0;
    }
    // 0x80019B90: nop

    // 0x80019B94: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80019B98: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019B9C: nop

L_80019BA0:
    // 0x80019BA0: bgez        $v0, L_80019BAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019BA4: nop
    
            goto L_80019BAC;
    }
    // 0x80019BA4: nop

    // 0x80019BA8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80019BAC:
    // 0x80019BAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80019BB0: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80019BB4: bne         $at, $zero, L_80019AD8
    if (ctx->r1 != 0) {
        // 0x80019BB8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019AD8;
    }
    // 0x80019BB8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019BBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019BC0:
    // 0x80019BC0: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x80019BC4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
L_80019BC8:
    // 0x80019BC8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019BCC: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80019BD0: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x80019BD4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019BD8: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019BDC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80019BE0: blez        $a3, L_80019C44
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019BE4: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80019C44;
    }
    // 0x80019BE4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019BE8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80019BEC:
    // 0x80019BEC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80019BF0: addu        $t7, $a2, $s0
    ctx->r15 = ADD32(ctx->r6, ctx->r16);
    // 0x80019BF4: lb          $t6, 0x1D8($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X1D8);
    // 0x80019BF8: nop

    // 0x80019BFC: bne         $t6, $zero, L_80019C30
    if (ctx->r14 != 0) {
        // 0x80019C00: nop
    
            goto L_80019C30;
    }
    // 0x80019C00: nop

    // 0x80019C04: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x80019C08: nop

    // 0x80019C0C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80019C10: bne         $at, $zero, L_80019C30
    if (ctx->r1 != 0) {
        // 0x80019C14: nop
    
            goto L_80019C30;
    }
    // 0x80019C14: nop

    // 0x80019C18: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80019C1C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80019C20: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019C24: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019C28: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019C2C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80019C30:
    // 0x80019C30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019C34: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019C38: bne         $at, $zero, L_80019BEC
    if (ctx->r1 != 0) {
        // 0x80019C3C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019BEC;
    }
    // 0x80019C3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019C40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019C44:
    // 0x80019C44: beq         $a0, $s5, L_80019CA0
    if (ctx->r4 == ctx->r21) {
        // 0x80019C48: nop
    
            goto L_80019CA0;
    }
    // 0x80019C48: nop

    // 0x80019C4C: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019C50: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80019C54: bne         $t1, $t6, L_80019C7C
    if (ctx->r9 != ctx->r14) {
        // 0x80019C58: addu        $v0, $t0, $t9
        ctx->r2 = ADD32(ctx->r8, ctx->r25);
            goto L_80019C7C;
    }
    // 0x80019C58: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80019C5C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80019C60: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019C64: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x80019C68: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80019C6C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80019C70: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x80019C74: b           L_80019C8C
    // 0x80019C78: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
        goto L_80019C8C;
    // 0x80019C78: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
L_80019C7C:
    // 0x80019C7C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019C80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80019C84: nop

    // 0x80019C88: sh          $t8, 0x1AC($t6)
    MEM_H(0X1AC, ctx->r14) = ctx->r24;
L_80019C8C:
    // 0x80019C8C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80019C90: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80019C94: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80019C98: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80019C9C: sb          $s4, 0x1D8($t8)
    MEM_B(0X1D8, ctx->r24) = ctx->r20;
L_80019CA0:
    // 0x80019CA0: bne         $a0, $s5, L_80019BC8
    if (ctx->r4 != ctx->r21) {
        // 0x80019CA4: nop
    
            goto L_80019BC8;
    }
    // 0x80019CA4: nop

    // 0x80019CA8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80019CAC: addiu       $s3, $s3, -0x38BC
    ctx->r19 = ADD32(ctx->r19, -0X38BC);
    // 0x80019CB0: jal         0x8009C2D0
    // 0x80019CB4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_4;
    // 0x80019CB4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_4:
    // 0x80019CB8: bne         $v0, $zero, L_80019D4C
    if (ctx->r2 != 0) {
        // 0x80019CBC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D4C;
    }
    // 0x80019CBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019CC0: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80019CC4: nop

    // 0x80019CC8: lh          $t7, 0x1AC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1AC);
    // 0x80019CCC: nop

    // 0x80019CD0: beq         $s4, $t7, L_80019D00
    if (ctx->r20 == ctx->r15) {
        // 0x80019CD4: nop
    
            goto L_80019D00;
    }
    // 0x80019CD4: nop

    // 0x80019CD8: jal         0x8009EC80
    // 0x80019CDC: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x80019CDC: nop

    after_5:
    // 0x80019CE0: beq         $v0, $zero, L_80019D4C
    if (ctx->r2 == 0) {
        // 0x80019CE4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D4C;
    }
    // 0x80019CE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019CE8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80019CEC: nop

    // 0x80019CF0: lh          $t8, 0x1AC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X1AC);
    // 0x80019CF4: nop

    // 0x80019CF8: bne         $s4, $t8, L_80019D4C
    if (ctx->r20 != ctx->r24) {
        // 0x80019CFC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D4C;
    }
    // 0x80019CFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D00:
    // 0x80019D00: lbu         $t7, 0x49($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X49);
    // 0x80019D04: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x80019D08: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80019D0C: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x80019D10: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80019D14: nop

    // 0x80019D18: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80019D1C: bne         $t8, $zero, L_80019D48
    if (ctx->r24 != 0) {
        // 0x80019D20: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_80019D48;
    }
    // 0x80019D20: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x80019D24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80019D28: lbu         $s0, 0x16($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X16);
    // 0x80019D2C: nop

    // 0x80019D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019D34: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80019D38: bne         $at, $zero, L_80019D44
    if (ctx->r1 != 0) {
        // 0x80019D3C: nop
    
            goto L_80019D44;
    }
    // 0x80019D3C: nop

    // 0x80019D40: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80019D44:
    // 0x80019D44: sb          $s0, 0x16($s6)
    MEM_B(0X16, ctx->r22) = ctx->r16;
L_80019D48:
    // 0x80019D48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D4C:
    // 0x80019D4C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_80019D50:
    // 0x80019D50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019D54: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x80019D58: sb          $s5, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r21;
    // 0x80019D5C: bne         $at, $zero, L_80019D50
    if (ctx->r1 != 0) {
        // 0x80019D60: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019D50;
    }
    // 0x80019D60: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019D64: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80019D68: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80019D6C: blez        $t6, L_80019DCC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80019D70: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019DCC;
    }
    // 0x80019D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019D74: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019D78: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
L_80019D7C:
    // 0x80019D7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80019D80: nop

    // 0x80019D84: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80019D88: nop

    // 0x80019D8C: beq         $s5, $t9, L_80019DA8
    if (ctx->r21 == ctx->r25) {
        // 0x80019D90: nop
    
            goto L_80019DA8;
    }
    // 0x80019D90: nop

    // 0x80019D94: lh          $t8, 0x1AC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019D98: nop

    // 0x80019D9C: bne         $s4, $t8, L_80019DA8
    if (ctx->r20 != ctx->r24) {
        // 0x80019DA0: nop
    
            goto L_80019DA8;
    }
    // 0x80019DA0: nop

    // 0x80019DA4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
L_80019DA8:
    // 0x80019DA8: lh          $t7, 0x1AC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019DAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019DB0: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80019DB4: sb          $t6, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r14;
    // 0x80019DB8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80019DBC: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019DC0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80019DC4: bne         $at, $zero, L_80019D7C
    if (ctx->r1 != 0) {
        // 0x80019DC8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80019D7C;
    }
    // 0x80019DC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80019DCC:
    // 0x80019DCC: jal         0x80000B34
    // 0x80019DD0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    music_play(rdram, ctx);
        goto after_6;
    // 0x80019DD0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_6:
    // 0x80019DD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80019DD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019DDC: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019DE0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
L_80019DE4:
    // 0x80019DE4: lb          $t8, 0x5A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5A);
    // 0x80019DE8: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80019DEC: bne         $s5, $t8, L_80019DFC
    if (ctx->r21 != ctx->r24) {
        // 0x80019DF0: nop
    
            goto L_80019DFC;
    }
    // 0x80019DF0: nop

    // 0x80019DF4: sb          $a1, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r5;
    // 0x80019DF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80019DFC:
    // 0x80019DFC: bne         $v1, $a0, L_80019DE4
    if (ctx->r3 != ctx->r4) {
        // 0x80019E00: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019DE4;
    }
    // 0x80019E00: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019E04: jal         0x8009EC80
    // 0x80019E08: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_7;
    // 0x80019E08: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_7:
    // 0x80019E0C: beq         $v0, $zero, L_80019E30
    if (ctx->r2 == 0) {
        // 0x80019E10: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80019E30;
    }
    // 0x80019E10: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80019E14: lb          $t7, 0x72($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X72);
    // 0x80019E18: lb          $t6, 0x5A($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X5A);
    // 0x80019E1C: nop

    // 0x80019E20: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80019E24: beq         $at, $zero, L_80019E30
    if (ctx->r1 == 0) {
        // 0x80019E28: nop
    
            goto L_80019E30;
    }
    // 0x80019E28: nop

    // 0x80019E2C: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_80019E30:
    // 0x80019E30: bne         $s0, $zero, L_80019EA4
    if (ctx->r16 != 0) {
        // 0x80019E34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80019EA4;
    }
    // 0x80019E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019E38: jal         0x8009EC80
    // 0x80019E3C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x80019E3C: nop

    after_8:
    // 0x80019E40: beq         $v0, $zero, L_80019E94
    if (ctx->r2 == 0) {
        // 0x80019E44: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019E94;
    }
    // 0x80019E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019E48: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x80019E4C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80019E50: beq         $t9, $zero, L_80019E7C
    if (ctx->r25 == 0) {
        // 0x80019E54: nop
    
            goto L_80019E7C;
    }
    // 0x80019E54: nop

    // 0x80019E58: jal         0x8006F398
    // 0x80019E5C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_9;
    // 0x80019E5C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_9:
    // 0x80019E60: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80019E64: lb          $t8, -0x38C4($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X38C4);
    // 0x80019E68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019E6C: beq         $t8, $zero, L_80019E94
    if (ctx->r24 == 0) {
        // 0x80019E70: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019E94;
    }
    // 0x80019E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019E74: b           L_80019E90
    // 0x80019E78: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
        goto L_80019E90;
    // 0x80019E78: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
L_80019E7C:
    // 0x80019E7C: lb          $t7, -0x38C4($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X38C4);
    // 0x80019E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019E84: beq         $t7, $zero, L_80019E94
    if (ctx->r15 == 0) {
        // 0x80019E88: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019E94;
    }
    // 0x80019E88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019E8C: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
L_80019E90:
    // 0x80019E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80019E94:
    // 0x80019E94: jal         0x80094688
    // 0x80019E98: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_10;
    // 0x80019E98: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_10:
    // 0x80019E9C: b           L_80019ED0
    // 0x80019EA0: nop

        goto L_80019ED0;
    // 0x80019EA0: nop

L_80019EA4:
    // 0x80019EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019EA8: jal         0x8006C1AC
    // 0x80019EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x80019EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80019EB0: lbu         $a3, 0x16($s6)
    ctx->r7 = MEM_BU(ctx->r22, 0X16);
    // 0x80019EB4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80019EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019EBC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80019EC0: jal         0x8006C1AC
    // 0x80019EC4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x80019EC4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_12:
    // 0x80019EC8: jal         0x8001A8D4
    // 0x80019ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_13;
    // 0x80019ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
L_80019ED0:
    // 0x80019ED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80019ED4: b           L_8001A7B0
    // 0x80019ED8: sw          $s4, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = ctx->r20;
        goto L_8001A7B0;
    // 0x80019ED8: sw          $s4, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = ctx->r20;
L_80019EDC:
    // 0x80019EDC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80019EE0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80019EE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019EE8: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80019EEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019EF0: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x80019EF4: addiu       $s2, $s2, -0x5110
    ctx->r18 = ADD32(ctx->r18, -0X5110);
    // 0x80019EF8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80019EFC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_80019F00:
    // 0x80019F00: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80019F04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80019F08: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x80019F0C: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80019F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019F14: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80019F18: nop

    // 0x80019F1C: lh          $t4, 0x1AA($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X1AA);
    // 0x80019F20: nop

L_80019F24:
    // 0x80019F24: beq         $a1, $s0, L_80019FB4
    if (ctx->r5 == ctx->r16) {
        // 0x80019F28: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80019FB4;
    }
    // 0x80019F28: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80019F2C: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80019F30: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80019F34: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x80019F38: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80019F3C: bne         $t9, $zero, L_80019F5C
    if (ctx->r25 != 0) {
        // 0x80019F40: nop
    
            goto L_80019F5C;
    }
    // 0x80019F40: nop

    // 0x80019F44: lb          $t8, 0x1D8($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D8);
    // 0x80019F48: nop

    // 0x80019F4C: beq         $t8, $zero, L_80019F5C
    if (ctx->r24 == 0) {
        // 0x80019F50: nop
    
            goto L_80019F5C;
    }
    // 0x80019F50: nop

    // 0x80019F54: b           L_80019FB4
    // 0x80019F58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FB4;
    // 0x80019F58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019F5C:
    // 0x80019F5C: lh          $v1, 0x190($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X190);
    // 0x80019F60: lh          $a0, 0x190($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X190);
    // 0x80019F64: nop

    // 0x80019F68: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019F6C: beq         $at, $zero, L_80019F7C
    if (ctx->r1 == 0) {
        // 0x80019F70: nop
    
            goto L_80019F7C;
    }
    // 0x80019F70: nop

    // 0x80019F74: b           L_80019FB4
    // 0x80019F78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FB4;
    // 0x80019F78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019F7C:
    // 0x80019F7C: bne         $a0, $v1, L_80019FB4
    if (ctx->r4 != ctx->r3) {
        // 0x80019F80: nop
    
            goto L_80019FB4;
    }
    // 0x80019F80: nop

    // 0x80019F84: lh          $v1, 0x1A8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A8);
    // 0x80019F88: lh          $a0, 0x1A8($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X1A8);
    // 0x80019F8C: nop

    // 0x80019F90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019F94: beq         $at, $zero, L_80019FA0
    if (ctx->r1 == 0) {
        // 0x80019F98: nop
    
            goto L_80019FA0;
    }
    // 0x80019F98: nop

    // 0x80019F9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FA0:
    // 0x80019FA0: bne         $v1, $a0, L_80019FB4
    if (ctx->r3 != ctx->r4) {
        // 0x80019FA4: slt         $at, $s0, $a1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80019FB4;
    }
    // 0x80019FA4: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80019FA8: beq         $at, $zero, L_80019FB4
    if (ctx->r1 == 0) {
        // 0x80019FAC: nop
    
            goto L_80019FB4;
    }
    // 0x80019FAC: nop

    // 0x80019FB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FB4:
    // 0x80019FB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80019FB8: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019FBC: bne         $at, $zero, L_80019F24
    if (ctx->r1 != 0) {
        // 0x80019FC0: nop
    
            goto L_80019F24;
    }
    // 0x80019FC0: nop

    // 0x80019FC4: sh          $a2, 0x1AA($t0)
    MEM_H(0X1AA, ctx->r8) = ctx->r6;
    // 0x80019FC8: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x80019FCC: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x80019FD0: nop

    // 0x80019FD4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80019FD8: beq         $at, $zero, L_8001A03C
    if (ctx->r1 == 0) {
        // 0x80019FDC: nop
    
            goto L_8001A03C;
    }
    // 0x80019FDC: nop

    // 0x80019FE0: lh          $v0, 0x1AA($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X1AA);
    // 0x80019FE4: nop

    // 0x80019FE8: bne         $t4, $v0, L_8001A038
    if (ctx->r12 != ctx->r2) {
        // 0x80019FEC: nop
    
            goto L_8001A038;
    }
    // 0x80019FEC: nop

    // 0x80019FF0: lh          $v1, 0x1B0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X1B0);
    // 0x80019FF4: nop

    // 0x80019FF8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80019FFC: beq         $at, $zero, L_8001A01C
    if (ctx->r1 == 0) {
        // 0x8001A000: nop
    
            goto L_8001A01C;
    }
    // 0x8001A000: nop

    // 0x8001A004: lb          $t9, 0x1D6($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D6);
    // 0x8001A008: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A00C: beq         $t9, $at, L_8001A03C
    if (ctx->r25 == ctx->r1) {
        // 0x8001A010: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8001A03C;
    }
    // 0x8001A010: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8001A014: b           L_8001A03C
    // 0x8001A018: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
        goto L_8001A03C;
    // 0x8001A018: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
L_8001A01C:
    // 0x8001A01C: lh          $t7, 0x1AE($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1AE);
    // 0x8001A020: nop

    // 0x8001A024: beq         $t7, $v0, L_8001A03C
    if (ctx->r15 == ctx->r2) {
        // 0x8001A028: nop
    
            goto L_8001A03C;
    }
    // 0x8001A028: nop

    // 0x8001A02C: sh          $t5, 0x1B2($t0)
    MEM_H(0X1B2, ctx->r8) = ctx->r13;
    // 0x8001A030: b           L_8001A03C
    // 0x8001A034: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
        goto L_8001A03C;
    // 0x8001A034: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
L_8001A038:
    // 0x8001A038: sh          $zero, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = 0;
L_8001A03C:
    // 0x8001A03C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A040: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A044: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A048: bne         $at, $zero, L_80019F00
    if (ctx->r1 != 0) {
        // 0x8001A04C: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_80019F00;
    }
    // 0x8001A04C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A050: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A054: addiu       $s1, $s1, -0x5240
    ctx->r17 = ADD32(ctx->r17, -0X5240);
    // 0x8001A058: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A05C: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8001A060: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8001A064:
    // 0x8001A064: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A068: nop

    // 0x8001A06C: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8001A070: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8001A074: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x8001A078: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x8001A07C: nop

    // 0x8001A080: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x8001A084: nop

    // 0x8001A088: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A08C: bne         $at, $zero, L_8001A130
    if (ctx->r1 != 0) {
        // 0x8001A090: nop
    
            goto L_8001A130;
    }
    // 0x8001A090: nop

    // 0x8001A094: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A098: nop

    // 0x8001A09C: bne         $t9, $zero, L_8001A130
    if (ctx->r25 != 0) {
        // 0x8001A0A0: nop
    
            goto L_8001A130;
    }
    // 0x8001A0A0: nop

    // 0x8001A0A4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A0A8: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A0AC: jal         0x8006DA0C
    // 0x8001A0B0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    get_game_mode(rdram, ctx);
        goto after_14;
    // 0x8001A0B0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_14:
    // 0x8001A0B4: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A0B8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A0BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A0C0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A0C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A0C8: beq         $v0, $at, L_8001A130
    if (ctx->r2 == ctx->r1) {
        // 0x8001A0CC: addiu       $t3, $t3, -0x511C
        ctx->r11 = ADD32(ctx->r11, -0X511C);
            goto L_8001A130;
    }
    // 0x8001A0CC: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x8001A0D0: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A0D4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001A0D8: nop

    // 0x8001A0DC: sh          $t8, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r24;
    // 0x8001A0E0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A0E4: nop

    // 0x8001A0E8: bne         $s4, $v0, L_8001A12C
    if (ctx->r20 != ctx->r2) {
        // 0x8001A0EC: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8001A12C;
    }
    // 0x8001A0EC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001A0F0: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8001A0F4: addiu       $a0, $zero, 0x23C
    ctx->r4 = ADD32(0, 0X23C);
    // 0x8001A0F8: bne         $s5, $t7, L_8001A128
    if (ctx->r21 != ctx->r15) {
        // 0x8001A0FC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001A128;
    }
    // 0x8001A0FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A100: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A104: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A108: jal         0x80001D04
    // 0x8001A10C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8001A10C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_15:
    // 0x8001A110: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A114: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A118: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A11C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A120: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A124: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
L_8001A128:
    // 0x8001A128: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_8001A12C:
    // 0x8001A12C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_8001A130:
    // 0x8001A130: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A134: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8001A138: lb          $v0, 0x1D8($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A13C: beq         $s5, $t9, L_8001A170
    if (ctx->r21 == ctx->r25) {
        // 0x8001A140: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_8001A170;
    }
    // 0x8001A140: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8001A144: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A148: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A14C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001A150: beq         $v0, $zero, L_8001A184
    if (ctx->r2 == 0) {
        // 0x8001A154: sh          $t7, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r15;
            goto L_8001A184;
    }
    // 0x8001A154: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x8001A158: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A15C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8001A160: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A164: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x8001A168: b           L_8001A184
    // 0x8001A16C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8001A184;
    // 0x8001A16C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
L_8001A170:
    // 0x8001A170: beq         $v0, $zero, L_8001A184
    if (ctx->r2 == 0) {
        // 0x8001A174: nop
    
            goto L_8001A184;
    }
    // 0x8001A174: nop

    // 0x8001A178: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A17C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8001A180: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
L_8001A184:
    // 0x8001A184: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A188: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001A18C: bne         $at, $zero, L_8001A064
    if (ctx->r1 != 0) {
        // 0x8001A190: nop
    
            goto L_8001A064;
    }
    // 0x8001A190: nop

    // 0x8001A194: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A19C: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A1A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A1A4:
    // 0x8001A1A4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A1A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A1AC: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x8001A1B0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001A1B4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A1B8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A1BC: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A1C0: bne         $at, $zero, L_8001A1A4
    if (ctx->r1 != 0) {
        // 0x8001A1C4: nop
    
            goto L_8001A1A4;
    }
    // 0x8001A1C4: nop

    // 0x8001A1C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A1CC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A1D0:
    // 0x8001A1D0: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A1D4: nop

    // 0x8001A1D8: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x8001A1DC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001A1E0: nop

    // 0x8001A1E4: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x8001A1E8: nop

    // 0x8001A1EC: lb          $t7, 0x1D8($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A1F0: nop

    // 0x8001A1F4: beq         $t7, $zero, L_8001A208
    if (ctx->r15 == 0) {
        // 0x8001A1F8: nop
    
            goto L_8001A208;
    }
    // 0x8001A1F8: nop

    // 0x8001A1FC: lh          $a2, 0x1AC($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AC);
    // 0x8001A200: b           L_8001A214
    // 0x8001A204: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_8001A214;
    // 0x8001A204: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A208:
    // 0x8001A208: lh          $a2, 0x1AA($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AA);
    // 0x8001A20C: nop

    // 0x8001A210: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A214:
    // 0x8001A214: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001A218: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001A21C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8001A220: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001A224: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A228: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A22C: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A230: bne         $at, $zero, L_8001A1D0
    if (ctx->r1 != 0) {
        // 0x8001A234: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A1D0;
    }
    // 0x8001A234: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A238: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A23C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A240:
    // 0x8001A240: blez        $a3, L_8001A29C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A244: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001A29C;
    }
    // 0x8001A244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A248: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001A24C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001A250: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8001A254: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001A258: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001A25C: nop

    // 0x8001A260: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_8001A264:
    // 0x8001A264: addu        $t7, $v1, $t8
    ctx->r15 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A268: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A26C: nop

    // 0x8001A270: bne         $t6, $v0, L_8001A28C
    if (ctx->r14 != ctx->r2) {
        // 0x8001A274: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A28C;
    }
    // 0x8001A274: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A278: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A27C: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A280: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001A284: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A288: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A28C:
    // 0x8001A28C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A290: bne         $at, $zero, L_8001A264
    if (ctx->r1 != 0) {
        // 0x8001A294: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8001A264;
    }
    // 0x8001A294: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001A298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A29C:
    // 0x8001A29C: bne         $a0, $zero, L_8001A300
    if (ctx->r4 != 0) {
        // 0x8001A2A0: nop
    
            goto L_8001A300;
    }
    // 0x8001A2A0: nop

    // 0x8001A2A4: blez        $a3, L_8001A300
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A2A8: nop
    
            goto L_8001A300;
    }
    // 0x8001A2A8: nop

L_8001A2AC:
    // 0x8001A2AC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A2B0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8001A2B4: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A2B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A2BC: nop

    // 0x8001A2C0: bne         $t6, $zero, L_8001A2F0
    if (ctx->r14 != 0) {
        // 0x8001A2C4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A2F0;
    }
    // 0x8001A2C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A2C8: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A2CC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001A2D0: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A2D4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A2D8: nop

    // 0x8001A2DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001A2E0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A2E4: nop

    // 0x8001A2E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A2EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A2F0:
    // 0x8001A2F0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A2F4: bne         $at, $zero, L_8001A2AC
    if (ctx->r1 != 0) {
        // 0x8001A2F8: nop
    
            goto L_8001A2AC;
    }
    // 0x8001A2F8: nop

    // 0x8001A2FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A300:
    // 0x8001A300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A304: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A308: bne         $at, $zero, L_8001A240
    if (ctx->r1 != 0) {
        // 0x8001A30C: nop
    
            goto L_8001A240;
    }
    // 0x8001A30C: nop

    // 0x8001A310: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001A314:
    // 0x8001A314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A318: jal         0x8006A554
    // 0x8001A31C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8001A31C: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    after_16:
    // 0x8001A320: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8001A324: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A328: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8001A32C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A330: addiu       $t3, $t3, -0x511C
    ctx->r11 = ADD32(ctx->r11, -0X511C);
    // 0x8001A334: bne         $at, $zero, L_8001A314
    if (ctx->r1 != 0) {
        // 0x8001A338: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_8001A314;
    }
    // 0x8001A338: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8001A33C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001A340: lb          $t9, -0x510A($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X510A);
    // 0x8001A344: lh          $t8, 0x88($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X88);
    // 0x8001A348: beq         $t9, $zero, L_8001A368
    if (ctx->r25 == 0) {
        // 0x8001A34C: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001A368;
    }
    // 0x8001A34C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001A350: beq         $t8, $zero, L_8001A368
    if (ctx->r24 == 0) {
        // 0x8001A354: nop
    
            goto L_8001A368;
    }
    // 0x8001A354: nop

    // 0x8001A358: jal         0x80022E18
    // 0x8001A35C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mode_end_taj_race(rdram, ctx);
        goto after_17;
    // 0x8001A35C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8001A360: b           L_8001A7B4
    // 0x8001A364: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8001A7B4;
    // 0x8001A364: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A368:
    // 0x8001A368: lb          $t7, -0x52C4($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52C4);
    // 0x8001A36C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A370: beq         $t7, $zero, L_8001A3CC
    if (ctx->r15 == 0) {
        // 0x8001A374: nop
    
            goto L_8001A3CC;
    }
    // 0x8001A374: nop

    // 0x8001A378: beq         $s3, $zero, L_8001A3CC
    if (ctx->r19 == 0) {
        // 0x8001A37C: nop
    
            goto L_8001A3CC;
    }
    // 0x8001A37C: nop

    // 0x8001A380: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A384: nop

    // 0x8001A388: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A38C: nop

    // 0x8001A390: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A394: nop

    // 0x8001A398: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A39C: nop

    // 0x8001A3A0: bne         $t8, $zero, L_8001A7B4
    if (ctx->r24 != 0) {
        // 0x8001A3A4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7B4;
    }
    // 0x8001A3A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A3A8: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A3AC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3B0: nop

    // 0x8001A3B4: sh          $t7, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r15;
    // 0x8001A3B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3BC: nop

    // 0x8001A3C0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A3C4: b           L_8001A7B0
    // 0x8001A3C8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_8001A7B0;
    // 0x8001A3C8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8001A3CC:
    // 0x8001A3CC: lw          $t8, -0x524C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X524C);
    // 0x8001A3D0: nop

    // 0x8001A3D4: bne         $t8, $zero, L_8001A7B4
    if (ctx->r24 != 0) {
        // 0x8001A3D8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7B4;
    }
    // 0x8001A3D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A3DC: jal         0x8009EC80
    // 0x8001A3E0: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_18;
    // 0x8001A3E0: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    after_18:
    // 0x8001A3E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A3E8: beq         $v0, $zero, L_8001A42C
    if (ctx->r2 == 0) {
        // 0x8001A3EC: addiu       $t1, $t1, -0x5118
        ctx->r9 = ADD32(ctx->r9, -0X5118);
            goto L_8001A42C;
    }
    // 0x8001A3EC: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A3F0: lh          $t7, 0x88($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88);
    // 0x8001A3F4: nop

    // 0x8001A3F8: blez        $t7, L_8001A430
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001A3FC: lh          $t6, 0x88($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X88);
            goto L_8001A430;
    }
    // 0x8001A3FC: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A400: jal         0x8009962C
    // 0x8001A404: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_19;
    // 0x8001A404: nop

    after_19:
    // 0x8001A408: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A40C: bne         $v0, $zero, L_8001A42C
    if (ctx->r2 != 0) {
        // 0x8001A410: addiu       $t1, $t1, -0x5118
        ctx->r9 = ADD32(ctx->r9, -0X5118);
            goto L_8001A42C;
    }
    // 0x8001A410: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A414: jal         0x8001A7D8
    // 0x8001A418: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_20;
    // 0x8001A418: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001A41C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A420: beq         $v0, $zero, L_8001A42C
    if (ctx->r2 == 0) {
        // 0x8001A424: addiu       $t1, $t1, -0x5118
        ctx->r9 = ADD32(ctx->r9, -0X5118);
            goto L_8001A42C;
    }
    // 0x8001A424: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A428: sb          $s4, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r20;
L_8001A42C:
    // 0x8001A42C: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
L_8001A430:
    // 0x8001A430: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A434: nop

    // 0x8001A438: beq         $t6, $t9, L_8001A470
    if (ctx->r14 == ctx->r25) {
        // 0x8001A43C: slti        $at, $t9, 0x2
        ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
            goto L_8001A470;
    }
    // 0x8001A43C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8001A440: bne         $at, $zero, L_8001A464
    if (ctx->r1 != 0) {
        // 0x8001A444: lb          $t6, 0x5B($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A464;
    }
    // 0x8001A444: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A448: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8001A44C: nop

    // 0x8001A450: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8001A454: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A458: beq         $at, $zero, L_8001A474
    if (ctx->r1 == 0) {
        // 0x8001A45C: lh          $t9, 0x88($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X88);
            goto L_8001A474;
    }
    // 0x8001A45C: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x8001A460: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
L_8001A464:
    // 0x8001A464: nop

    // 0x8001A468: beq         $t6, $zero, L_8001A7B4
    if (ctx->r14 == 0) {
        // 0x8001A46C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7B4;
    }
    // 0x8001A46C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A470:
    // 0x8001A470: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
L_8001A474:
    // 0x8001A474: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A478: nop

    // 0x8001A47C: beq         $t9, $t8, L_8001A524
    if (ctx->r25 == ctx->r24) {
        // 0x8001A480: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A524;
    }
    // 0x8001A480: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A484: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A488:
    // 0x8001A488: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A48C: nop

    // 0x8001A490: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A494: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A498: nop

    // 0x8001A49C: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A4A0: nop

    // 0x8001A4A4: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A4A8: nop

    // 0x8001A4AC: bne         $t8, $zero, L_8001A510
    if (ctx->r24 != 0) {
        // 0x8001A4B0: nop
    
            goto L_8001A510;
    }
    // 0x8001A4B0: nop

    // 0x8001A4B4: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x8001A4B8: nop

    // 0x8001A4BC: bltz        $a0, L_8001A4F0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001A4C0: nop
    
            goto L_8001A4F0;
    }
    // 0x8001A4C0: nop

    // 0x8001A4C4: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A4C8: jal         0x800665E8
    // 0x8001A4CC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    set_active_camera(rdram, ctx);
        goto after_21;
    // 0x8001A4CC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_21:
    // 0x8001A4D0: jal         0x80069CFC
    // 0x8001A4D4: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_22;
    // 0x8001A4D4: nop

    after_22:
    // 0x8001A4D8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A4DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A4E0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A4E4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001A4E8: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A4EC: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
L_8001A4F0:
    // 0x8001A4F0: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A4F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A4F8: nop

    // 0x8001A4FC: sh          $t6, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r14;
    // 0x8001A500: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001A504: nop

    // 0x8001A508: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8001A50C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_8001A510:
    // 0x8001A510: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001A514: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A518: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A51C: bne         $at, $zero, L_8001A488
    if (ctx->r1 != 0) {
        // 0x8001A520: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A488;
    }
    // 0x8001A520: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001A524:
    // 0x8001A524: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x8001A528: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x8001A52C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x8001A530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A534: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8001A538: beq         $t6, $zero, L_8001A554
    if (ctx->r14 == 0) {
        // 0x8001A53C: lui         $t8, 0xB000
        ctx->r24 = S32(0XB000 << 16);
            goto L_8001A554;
    }
    // 0x8001A53C: lui         $t8, 0xB000
    ctx->r24 = S32(0XB000 << 16);
L_8001A540:
    // 0x8001A540: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A544: nop

    // 0x8001A548: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8001A54C: bne         $t9, $zero, L_8001A540
    if (ctx->r25 != 0) {
        // 0x8001A550: nop
    
            goto L_8001A540;
    }
    // 0x8001A550: nop

L_8001A554:
    // 0x8001A554: addiu       $t7, $zero, 0x6C07
    ctx->r15 = ADD32(0, 0X6C07);
    // 0x8001A558: addiu       $at, $zero, 0x6C07
    ctx->r1 = ADD32(0, 0X6C07);
    // 0x8001A55C: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8001A560: beq         $t6, $at, L_8001A574
    if (ctx->r14 == ctx->r1) {
        // 0x8001A564: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001A574;
    }
    // 0x8001A564: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A568: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A56C: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A570: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8001A574:
    // 0x8001A574: lbu         $t8, -0x510B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X510B);
    // 0x8001A578: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8001A57C: bne         $t8, $zero, L_8001A5D8
    if (ctx->r24 != 0) {
        // 0x8001A580: addiu       $s3, $s3, -0x38BC
        ctx->r19 = ADD32(ctx->r19, -0X38BC);
            goto L_8001A5D8;
    }
    // 0x8001A580: addiu       $s3, $s3, -0x38BC
    ctx->r19 = ADD32(ctx->r19, -0X38BC);
    // 0x8001A584: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A588: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A58C: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8001A590:
    // 0x8001A590: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A594: nop

    // 0x8001A598: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A59C: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A5A0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A5A4: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A5A8: nop

    // 0x8001A5AC: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8001A5B0: nop

    // 0x8001A5B4: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A5B8: mflo        $t8
    ctx->r24 = lo;
    // 0x8001A5BC: addu        $t7, $s6, $t8
    ctx->r15 = ADD32(ctx->r22, ctx->r24);
    // 0x8001A5C0: sb          $s0, 0x5A($t7)
    MEM_B(0X5A, ctx->r15) = ctx->r16;
    // 0x8001A5C4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A5C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A5CC: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A5D0: bne         $at, $zero, L_8001A590
    if (ctx->r1 != 0) {
        // 0x8001A5D4: nop
    
            goto L_8001A590;
    }
    // 0x8001A5D4: nop

L_8001A5D8:
    // 0x8001A5D8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8001A5DC: jal         0x8009EC80
    // 0x8001A5E0: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    is_in_two_player_adventure(rdram, ctx);
        goto after_23;
    // 0x8001A5E0: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    after_23:
    // 0x8001A5E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A5E8: beq         $v0, $zero, L_8001A60C
    if (ctx->r2 == 0) {
        // 0x8001A5EC: addiu       $t1, $t1, -0x5118
        ctx->r9 = ADD32(ctx->r9, -0X5118);
            goto L_8001A60C;
    }
    // 0x8001A5EC: addiu       $t1, $t1, -0x5118
    ctx->r9 = ADD32(ctx->r9, -0X5118);
    // 0x8001A5F0: lb          $t9, 0x72($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X72);
    // 0x8001A5F4: lb          $t8, 0x5A($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X5A);
    // 0x8001A5F8: nop

    // 0x8001A5FC: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001A600: beq         $at, $zero, L_8001A60C
    if (ctx->r1 == 0) {
        // 0x8001A604: nop
    
            goto L_8001A60C;
    }
    // 0x8001A604: nop

    // 0x8001A608: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_8001A60C:
    // 0x8001A60C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A610: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A614: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A618: addiu       $s1, $s1, -0x523C
    ctx->r17 = ADD32(ctx->r17, -0X523C);
    // 0x8001A61C: lw          $t0, 0x64($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X64);
    // 0x8001A620: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8001A624: lbu         $t9, 0x4A($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X4A);
    // 0x8001A628: nop

    // 0x8001A62C: beq         $s4, $t9, L_8001A648
    if (ctx->r20 == ctx->r25) {
        // 0x8001A630: nop
    
            goto L_8001A648;
    }
    // 0x8001A630: nop

    // 0x8001A634: jal         0x8009EC80
    // 0x8001A638: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8001A638: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    after_24:
    // 0x8001A63C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A640: beq         $v0, $zero, L_8001A67C
    if (ctx->r2 == 0) {
        // 0x8001A644: nop
    
            goto L_8001A67C;
    }
    // 0x8001A644: nop

L_8001A648:
    // 0x8001A648: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8001A64C: nop

    // 0x8001A650: beq         $s5, $t8, L_8001A67C
    if (ctx->r21 == ctx->r24) {
        // 0x8001A654: nop
    
            goto L_8001A67C;
    }
    // 0x8001A654: nop

    // 0x8001A658: jal         0x8009C2D0
    // 0x8001A65C: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8001A65C: nop

    after_25:
    // 0x8001A660: bne         $v0, $zero, L_8001A67C
    if (ctx->r2 != 0) {
        // 0x8001A664: nop
    
            goto L_8001A67C;
    }
    // 0x8001A664: nop

    // 0x8001A668: jal         0x8009962C
    // 0x8001A66C: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_26;
    // 0x8001A66C: nop

    after_26:
    // 0x8001A670: bne         $v0, $zero, L_8001A67C
    if (ctx->r2 != 0) {
        // 0x8001A674: nop
    
            goto L_8001A67C;
    }
    // 0x8001A674: nop

    // 0x8001A678: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_8001A67C:
    // 0x8001A67C: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8001A680: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A684: beq         $t7, $zero, L_8001A6A0
    if (ctx->r15 == 0) {
        // 0x8001A688: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A6A0;
    }
    // 0x8001A688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A68C: bne         $t6, $zero, L_8001A6A4
    if (ctx->r14 != 0) {
        // 0x8001A690: lb          $t9, 0x5B($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A6A4;
    }
    // 0x8001A690: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A694: jal         0x8001A7D8
    // 0x8001A698: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_27;
    // 0x8001A698: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_27:
    // 0x8001A69C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8001A6A0:
    // 0x8001A6A0: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
L_8001A6A4:
    // 0x8001A6A4: nop

    // 0x8001A6A8: beq         $t9, $zero, L_8001A6BC
    if (ctx->r25 == 0) {
        // 0x8001A6AC: lb          $t8, 0x5A($sp)
        ctx->r24 = MEM_B(ctx->r29, 0X5A);
            goto L_8001A6BC;
    }
    // 0x8001A6AC: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
    // 0x8001A6B0: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // 0x8001A6B4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8001A6B8: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
L_8001A6BC:
    // 0x8001A6BC: nop

    // 0x8001A6C0: beq         $t8, $zero, L_8001A6D0
    if (ctx->r24 == 0) {
        // 0x8001A6C4: nop
    
            goto L_8001A6D0;
    }
    // 0x8001A6C4: nop

    // 0x8001A6C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A6CC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8001A6D0:
    // 0x8001A6D0: bne         $s0, $zero, L_8001A744
    if (ctx->r16 != 0) {
        // 0x8001A6D4: nop
    
            goto L_8001A744;
    }
    // 0x8001A6D4: nop

    // 0x8001A6D8: jal         0x8009EC80
    // 0x8001A6DC: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_28;
    // 0x8001A6DC: nop

    after_28:
    // 0x8001A6E0: beq         $v0, $zero, L_8001A730
    if (ctx->r2 == 0) {
        // 0x8001A6E4: nop
    
            goto L_8001A730;
    }
    // 0x8001A6E4: nop

    // 0x8001A6E8: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8001A6EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001A6F0: beq         $t7, $zero, L_8001A71C
    if (ctx->r15 == 0) {
        // 0x8001A6F4: nop
    
            goto L_8001A71C;
    }
    // 0x8001A6F4: nop

    // 0x8001A6F8: jal         0x8006F398
    // 0x8001A6FC: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_29;
    // 0x8001A6FC: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_29:
    // 0x8001A700: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001A704: lb          $t6, -0x38C4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X38C4);
    // 0x8001A708: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A70C: beq         $t6, $zero, L_8001A730
    if (ctx->r14 == 0) {
        // 0x8001A710: nop
    
            goto L_8001A730;
    }
    // 0x8001A710: nop

    // 0x8001A714: b           L_8001A730
    // 0x8001A718: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
        goto L_8001A730;
    // 0x8001A718: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
L_8001A71C:
    // 0x8001A71C: lb          $t9, -0x38C4($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X38C4);
    // 0x8001A720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A724: beq         $t9, $zero, L_8001A730
    if (ctx->r25 == 0) {
        // 0x8001A728: nop
    
            goto L_8001A730;
    }
    // 0x8001A728: nop

    // 0x8001A72C: sb          $s4, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = ctx->r20;
L_8001A730:
    // 0x8001A730: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x8001A734: jal         0x80094688
    // 0x8001A738: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_30;
    // 0x8001A738: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_30:
    // 0x8001A73C: b           L_8001A794
    // 0x8001A740: nop

        goto L_8001A794;
    // 0x8001A740: nop

L_8001A744:
    // 0x8001A744: lbu         $t7, 0x48($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A748: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8001A74C: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001A750: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8001A754: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001A758: nop

    // 0x8001A75C: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8001A760: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001A764: lbu         $t8, 0x48($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A768: nop

    // 0x8001A76C: beq         $t8, $zero, L_8001A78C
    if (ctx->r24 == 0) {
        // 0x8001A770: nop
    
            goto L_8001A78C;
    }
    // 0x8001A770: nop

    // 0x8001A774: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8001A778: nop

    // 0x8001A77C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001A780: nop

    // 0x8001A784: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A788: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8001A78C:
    // 0x8001A78C: jal         0x8001A8D4
    // 0x8001A790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_31;
    // 0x8001A790: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
L_8001A794:
    // 0x8001A794: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A798: jal         0x8009C3C8
    // 0x8001A79C: sw          $s5, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = ctx->r21;
    get_number_of_active_players(rdram, ctx);
        goto after_32;
    // 0x8001A79C: sw          $s5, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = ctx->r21;
    after_32:
    // 0x8001A7A0: bne         $v0, $s4, L_8001A7B4
    if (ctx->r2 != ctx->r20) {
        // 0x8001A7A4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7B4;
    }
    // 0x8001A7A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A7A8: jal         0x8001AE64
    // 0x8001A7AC: nop

    race_finish_time_trial(rdram, ctx);
        goto after_33;
    // 0x8001A7AC: nop

    after_33:
L_8001A7B0:
    // 0x8001A7B0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A7B4:
    // 0x8001A7B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A7B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A7BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A7C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A7C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7C8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A7CC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A7D0: jr          $ra
    // 0x8001A7D4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001A7D4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void texrect_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_hud_rect_begin(uint8_t*, recomp_context*, int); dkr_hud_rect_begin(rdram, ctx, 0);
    // 0x80078AB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80078ABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078AC0: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80078AC4: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80078AC8: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80078ACC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80078AD0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80078AD4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80078AD8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80078ADC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80078AE0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80078AE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078AE8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078AEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078AF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078AF4: addiu       $t8, $t8, -0x19D8
    ctx->r24 = ADD32(ctx->r24, -0X19D8);
    // 0x80078AF8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80078AFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078B00: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078B04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078B08: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80078B0C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80078B10: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078B14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80078B18: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x80078B1C: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x80078B20: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80078B24: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80078B28: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078B2C: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078B30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078B34: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80078B38: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80078B3C: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80078B40: sll         $fp, $a2, 2
    ctx->r30 = S32(ctx->r6 << 2);
    // 0x80078B44: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80078B48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078B4C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80078B50: sll         $ra, $a3, 2
    ctx->r31 = S32(ctx->r7 << 2);
    // 0x80078B54: beq         $t0, $zero, L_80078C9C
    if (ctx->r8 == 0) {
        // 0x80078B58: or          $t2, $a1, $zero
        ctx->r10 = ctx->r5 | 0;
            goto L_80078C9C;
    }
    // 0x80078B58: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80078B5C: lui         $s7, 0x400
    ctx->r23 = S32(0X400 << 16);
    // 0x80078B60: ori         $s7, $s7, 0x400
    ctx->r23 = ctx->r23 | 0X400;
    // 0x80078B64: lui         $s6, 0xB200
    ctx->r22 = S32(0XB200 << 16);
    // 0x80078B68: lui         $s5, 0xB300
    ctx->r21 = S32(0XB300 << 16);
    // 0x80078B6C: lui         $s4, 0xE400
    ctx->r20 = S32(0XE400 << 16);
    // 0x80078B70: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80078B74: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
L_80078B78:
    // 0x80078B78: lh          $t6, 0x4($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X4);
    // 0x80078B7C: lh          $t9, 0x6($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X6);
    // 0x80078B80: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078B84: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80078B88: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078B8C: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x80078B90: addu        $a2, $t8, $fp
    ctx->r6 = ADD32(ctx->r24, ctx->r30);
    // 0x80078B94: addu        $a3, $t7, $ra
    ctx->r7 = ADD32(ctx->r15, ctx->r31);
    // 0x80078B98: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078B9C: addu        $t3, $t8, $a2
    ctx->r11 = ADD32(ctx->r24, ctx->r6);
    // 0x80078BA0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078BA4: blez        $t3, L_80078C8C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80078BA8: addu        $t4, $t7, $a3
        ctx->r12 = ADD32(ctx->r15, ctx->r7);
            goto L_80078C8C;
    }
    // 0x80078BA8: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x80078BAC: blez        $t4, L_80078C8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80078BB0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80078C8C;
    }
    // 0x80078BB0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80078BB4: bgez        $a2, L_80078BC8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80078BB8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80078BC8;
    }
    // 0x80078BB8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80078BBC: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x80078BC0: negu        $t5, $t5
    ctx->r13 = SUB32(0, ctx->r13);
    // 0x80078BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80078BC8:
    // 0x80078BC8: bgez        $a3, L_80078BDC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80078BCC: nop
    
            goto L_80078BDC;
    }
    // 0x80078BCC: nop

    // 0x80078BD0: sll         $s1, $a3, 3
    ctx->r17 = S32(ctx->r7 << 3);
    // 0x80078BD4: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x80078BD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80078BDC:
    // 0x80078BDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078BE0: nop

    // 0x80078BE4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078BE8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078BEC: lh          $a0, 0xA($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XA);
    // 0x80078BF0: nop

    // 0x80078BF4: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80078BF8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80078BFC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80078C00: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80078C04: or          $t7, $t9, $s2
    ctx->r15 = ctx->r25 | ctx->r18;
    // 0x80078C08: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80078C0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80078C10: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80078C14: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80078C18: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80078C1C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80078C20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078C24: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80078C28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80078C2C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078C30: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80078C34: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x80078C38: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80078C3C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80078C40: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80078C44: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80078C48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80078C4C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80078C50: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80078C54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078C58: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x80078C5C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078C60: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078C64: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x80078C68: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80078C6C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80078C70: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80078C74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078C78: nop

    // 0x80078C7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078C80: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078C84: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80078C88: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
L_80078C8C:
    // 0x80078C8C: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x80078C90: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80078C94: bne         $t0, $zero, L_80078B78
    if (ctx->r8 != 0) {
        // 0x80078C98: nop
    
            goto L_80078B78;
    }
    // 0x80078C98: nop

L_80078C9C:
    // 0x80078C9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078CA0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80078CA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80078CA8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80078CAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80078CB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80078CB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078CB8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80078CBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078CC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078CC4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80078CC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078CCC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078CD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80078CD4: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80078CD8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80078CDC: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80078CE0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80078CE4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80078CE8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80078CEC: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80078CF0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80078CF4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    extern void dkr_hud_rect_end(uint8_t*, recomp_context*); dkr_hud_rect_end(rdram, ctx);
    // 0x80078CF8: jr          $ra
    // 0x80078CFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80078CFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void dialogue_npc_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF68: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009CF6C: addiu       $t6, $t6, -0xB1C
    ctx->r14 = ADD32(ctx->r14, -0XB1C);
    // 0x8009CF70: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8009CF74: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8009CF78: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009CF7C: bne         $t7, $zero, L_8009CFA8
    if (ctx->r15 != 0) {
        // 0x8009CF80: addiu       $t8, $t8, -0xB19
        ctx->r24 = ADD32(ctx->r24, -0XB19);
            goto L_8009CFA8;
    }
    // 0x8009CF80: addiu       $t8, $t8, -0xB19
    ctx->r24 = ADD32(ctx->r24, -0XB19);
    // 0x8009CF84: beq         $v0, $t8, L_8009CF9C
    if (ctx->r2 == ctx->r24) {
        // 0x8009CF88: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009CF9C;
    }
    // 0x8009CF88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009CF8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CF90: sb          $zero, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = 0;
    // 0x8009CF94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CF98: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
L_8009CF9C:
    // 0x8009CF9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CFA0: sb          $v1, -0xB20($at)
    MEM_B(-0XB20, ctx->r1) = ctx->r3;
    // 0x8009CFA4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8009CFA8:
    // 0x8009CFA8: jr          $ra
    // 0x8009CFAC: nop

    return;
    // 0x8009CFAC: nop

;}
RECOMP_FUNC void obj_init_dynamic_lighting_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800381E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800381E4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800381E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800381EC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800381F0: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800381F4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800381F8: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800381FC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038200: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038204: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80038208: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003820C: jr          $ra
    // 0x80038210: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038210: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void begin_lighthouse_rocket_cutscene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F29C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F2A0: lh          $t6, -0x2C6C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2C6C);
    // 0x8006F2A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F2A8: bne         $t6, $zero, L_8006F328
    if (ctx->r14 != 0) {
        // 0x8006F2AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F328;
    }
    // 0x8006F2AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F2B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F2B4: lw          $v0, 0x3510($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3510);
    // 0x8006F2B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006F2BC: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x8006F2C0: nop

    // 0x8006F2C4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8006F2C8: bne         $t8, $at, L_8006F32C
    if (ctx->r24 != ctx->r1) {
        // 0x8006F2CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F32C;
    }
    // 0x8006F2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F2D0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8006F2D4: nop

    // 0x8006F2D8: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8006F2DC: bne         $t9, $zero, L_8006F32C
    if (ctx->r25 != 0) {
        // 0x8006F2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F32C;
    }
    // 0x8006F2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F2E4: lhu         $t0, 0xC($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XC);
    // 0x8006F2E8: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x8006F2EC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8006F2F0: beq         $t1, $zero, L_8006F328
    if (ctx->r9 == 0) {
        // 0x8006F2F4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F328;
    }
    // 0x8006F2F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F2F8: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8006F2FC: jal         0x800C01D8
    // 0x8006F300: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F300: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    after_0:
    // 0x8006F304: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8006F308: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F30C: sh          $t3, -0x2C6C($at)
    MEM_H(-0X2C6C, ctx->r1) = ctx->r11;
    // 0x8006F310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F314: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x8006F318: sb          $t4, 0x3525($at)
    MEM_B(0X3525, ctx->r1) = ctx->r12;
    // 0x8006F31C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F320: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8006F324: sb          $t5, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = ctx->r13;
L_8006F328:
    // 0x8006F328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F32C:
    // 0x8006F32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F330: jr          $ra
    // 0x8006F334: nop

    return;
    // 0x8006F334: nop

;}
RECOMP_FUNC void music_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001990: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001994: addiu       $v0, $v0, -0x39C8
    ctx->r2 = ADD32(ctx->r2, -0X39C8);
    // 0x80001998: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000199C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x800019A0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800019A4: lw          $t7, -0x39AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X39AC);
    // 0x800019A8: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800019AC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800019B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800019B4: lw          $t9, -0x3994($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3994);
    // 0x800019B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800019BC: lwc1        $f8, -0x39B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X39B0);
    // 0x800019C0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800019C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800019C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800019CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800019D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800019D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800019D8: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800019DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800019E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800019E4: nop

    // 0x800019E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800019EC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800019F0: nop

    // 0x800019F4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800019F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800019FC: nop

    // 0x80001A00: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001A04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001A0C: nop

    // 0x80001A10: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001A14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001A18: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001A1C: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001A20: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001A24: jal         0x800C7850
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001A34: jr          $ra
    // 0x80001A38: nop

    return;
    // 0x80001A38: nop

;}
RECOMP_FUNC void obj_loop_frog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800422F0: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x800422F4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800422F8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800422FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042300: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80042304: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80042308: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004230C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80042310: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80042314: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80042318: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8004231C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80042320: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80042324: bne         $t6, $zero, L_80042344
    if (ctx->r14 != 0) {
        // 0x80042328: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80042344;
    }
    // 0x80042328: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004232C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042330: lwc1        $f9, 0x6250($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6250);
    // 0x80042334: lwc1        $f8, 0x6254($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6254);
    // 0x80042338: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8004233C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80042340: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80042344:
    // 0x80042344: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80042348: nop

    // 0x8004234C: lbu         $t7, 0x14($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X14);
    // 0x80042350: nop

    // 0x80042354: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80042358: beq         $at, $zero, L_80042974
    if (ctx->r1 == 0) {
        // 0x8004235C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80042974;
    }
    // 0x8004235C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80042360: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042364: addu        $at, $at, $t7
    gpr jr_addend_80042370 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80042368: lw          $t7, 0x6258($at)
    ctx->r15 = ADD32(ctx->r1, 0X6258);
    // 0x8004236C: nop

    // 0x80042370: jr          $t7
    // 0x80042374: nop

    switch (jr_addend_80042370 >> 2) {
        case 0: goto L_80042378; break;
        case 1: goto L_800426B8; break;
        case 2: goto L_80042898; break;
        case 3: goto L_800428E8; break;
        case 4: goto L_8004292C; break;
        default: switch_error(__func__, 0x80042370, 0x800E6258);
    }
    // 0x80042374: nop

L_80042378:
    // 0x80042378: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    // 0x8004237C: lb          $v0, 0x19($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X19);
    // 0x80042380: lui         $a3, 0x42C0
    ctx->r7 = S32(0X42C0 << 16);
    // 0x80042384: blez        $v0, L_80042394
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042388: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80042394;
    }
    // 0x80042388: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004238C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x80042390: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
L_80042394:
    // 0x80042394: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042398: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004239C: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800423A0: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800423A4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800423A8: sw          $a1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r5;
    // 0x800423AC: jal         0x80016DE8
    // 0x800423B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x800423B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x800423B4: lw          $a1, 0x114($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X114);
    // 0x800423B8: blez        $v0, L_800424F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800423BC: nop
    
            goto L_800424F4;
    }
    // 0x800423BC: nop

    // 0x800423C0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800423C4: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800423C8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800423CC: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800423D0: lb          $t2, 0x19($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X19);
    // 0x800423D4: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800423D8: lwc1        $f18, 0x10($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X10);
    // 0x800423DC: lwc1        $f4, 0x14($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800423E0: sub.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800423E4: sub.s       $f14, $f12, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800423E8: bgtz        $t2, L_800424A4
    if (SIGNED(ctx->r10) > 0) {
        // 0x800423EC: sub.s       $f22, $f2, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_800424A4;
    }
    // 0x800423EC: sub.s       $f22, $f2, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800423F0: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800423F4: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x800423F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800423FC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80042400: nop

    // 0x80042404: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80042408: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004240C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80042410: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80042414: nop

    // 0x80042418: bc1f        L_800424A4
    if (!c1cs) {
        // 0x8004241C: nop
    
            goto L_800424A4;
    }
    // 0x8004241C: nop

    // 0x80042420: lbu         $t3, 0x15($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X15);
    // 0x80042424: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80042428: beq         $t3, $zero, L_8004247C
    if (ctx->r11 == 0) {
        // 0x8004242C: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_8004247C;
    }
    // 0x8004242C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80042430: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042434: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80042438: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004243C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80042440: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80042444: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    // 0x80042448: jal         0x80009558
    // 0x8004244C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8004244C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80042450: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80042454: jal         0x8009EA78
    // 0x80042458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_eeprom_settings_value(rdram, ctx);
        goto after_2;
    // 0x80042458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8004245C: jal         0x8009C2E0
    // 0x80042460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_3;
    // 0x80042460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80042464: jal         0x8006D8A4
    // 0x80042468: nop

    set_drumstick_unlock_transition(rdram, ctx);
        goto after_4;
    // 0x80042468: nop

    after_4:
    // 0x8004246C: jal         0x8000FFB8
    // 0x80042470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_5;
    // 0x80042470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80042474: b           L_80042978
    // 0x80042478: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80042978;
    // 0x80042478: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8004247C:
    // 0x8004247C: sb          $t5, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r13;
    // 0x80042480: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042484: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80042488: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004248C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80042490: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80042494: jal         0x80009558
    // 0x80042498: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_6;
    // 0x80042498: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8004249C: b           L_80042548
    // 0x800424A0: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
        goto L_80042548;
    // 0x800424A0: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
L_800424A4:
    // 0x800424A4: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x800424A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800424AC: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    // 0x800424B0: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x800424B4: beq         $t7, $zero, L_800424D4
    if (ctx->r15 == 0) {
        // 0x800424B8: swc1        $f6, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
            goto L_800424D4;
    }
    // 0x800424B8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800424BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800424C0: lwc1        $f10, 0x626C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X626C);
    // 0x800424C4: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800424C8: nop

    // 0x800424CC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800424D0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
L_800424D4:
    // 0x800424D4: jal         0x80070750
    // 0x800424D8: neg.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = -ctx->f22.fl;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x800424D8: neg.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = -ctx->f22.fl;
    after_7:
    // 0x800424DC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800424E0: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x800424E4: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x800424E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800424EC: b           L_80042544
    // 0x800424F0: sw          $t9, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r25;
        goto L_80042544;
    // 0x800424F0: sw          $t9, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r25;
L_800424F4:
    // 0x800424F4: lh          $t0, 0x16($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X16);
    // 0x800424F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800424FC: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80042500: sh          $t1, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r9;
    // 0x80042504: lh          $t2, 0x16($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X16);
    // 0x80042508: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8004250C: bgez        $t2, L_80042544
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80042510: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_80042544;
    }
    // 0x80042510: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80042514: jal         0x8006F94C
    // 0x80042518: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    rand_range(rdram, ctx);
        goto after_8;
    // 0x80042518: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    after_8:
    // 0x8004251C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80042520: addiu       $a0, $zero, -0x4000
    ctx->r4 = ADD32(0, -0X4000);
    // 0x80042524: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80042528: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    // 0x8004252C: jal         0x8006F94C
    // 0x80042530: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    rand_range(rdram, ctx);
        goto after_9;
    // 0x80042530: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80042534: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80042538: nop

    // 0x8004253C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80042540: sh          $t5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r13;
L_80042544:
    // 0x80042544: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
L_80042548:
    // 0x80042548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004254C: beq         $t6, $zero, L_80042974
    if (ctx->r14 == 0) {
        // 0x80042550: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80042974;
    }
    // 0x80042550: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80042554:
    // 0x80042554: lh          $a0, 0x1A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A);
    // 0x80042558: sw          $v1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r3;
    // 0x8004255C: jal         0x800707C4
    // 0x80042560: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_10;
    // 0x80042560: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    after_10:
    // 0x80042564: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80042568: lh          $a0, 0x1A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A);
    // 0x8004256C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80042570: jal         0x800707F8
    // 0x80042574: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    coss_f(rdram, ctx);
        goto after_11;
    // 0x80042574: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x80042578: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8004257C: lw          $v0, 0x108($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X108);
    // 0x80042580: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80042584: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80042588: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x8004258C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80042590: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80042594: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x80042598: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004259C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800425A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800425A4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800425A8: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800425AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800425B0: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800425B4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800425B8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800425BC: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800425C0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800425C4: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800425C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800425CC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800425D0: nop

    // 0x800425D4: bc1f        L_800425E4
    if (!c1cs) {
        // 0x800425D8: nop
    
            goto L_800425E4;
    }
    // 0x800425D8: nop

    // 0x800425DC: b           L_800425F4
    // 0x800425E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800425F4;
    // 0x800425E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800425E4:
    // 0x800425E4: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x800425E8: nop

    // 0x800425EC: addiu       $t8, $t7, 0x4000
    ctx->r24 = ADD32(ctx->r15, 0X4000);
    // 0x800425F0: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
L_800425F4:
    // 0x800425F4: beq         $at, $zero, L_80042604
    if (ctx->r1 == 0) {
        // 0x800425F8: nop
    
            goto L_80042604;
    }
    // 0x800425F8: nop

    // 0x800425FC: beq         $v1, $zero, L_80042554
    if (ctx->r3 == 0) {
        // 0x80042600: nop
    
            goto L_80042554;
    }
    // 0x80042600: nop

L_80042604:
    // 0x80042604: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042608: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004260C: bne         $v1, $zero, L_80042638
    if (ctx->r3 != 0) {
        // 0x80042610: nop
    
            goto L_80042638;
    }
    // 0x80042610: nop

    // 0x80042614: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80042618: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004261C: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80042620: jal         0x80070750
    // 0x80042624: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x80042624: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    after_12:
    // 0x80042628: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x8004262C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80042630: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042634: nop

L_80042638:
    // 0x80042638: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    // 0x8004263C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x80042640: beq         $t9, $zero, L_80042670
    if (ctx->r25 == 0) {
        // 0x80042644: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_80042670;
    }
    // 0x80042644: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80042648: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004264C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042650: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80042654: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80042658: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004265C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80042660: jal         0x80009558
    // 0x80042664: addiu       $a0, $zero, 0x1A4
    ctx->r4 = ADD32(0, 0X1A4);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_13;
    // 0x80042664: addiu       $a0, $zero, 0x1A4
    ctx->r4 = ADD32(0, 0X1A4);
    after_13:
    // 0x80042668: b           L_8004268C
    // 0x8004266C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8004268C;
    // 0x8004266C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80042670:
    // 0x80042670: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80042674: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042678: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004267C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80042680: jal         0x80009558
    // 0x80042684: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x80042684: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_14:
    // 0x80042688: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8004268C:
    // 0x8004268C: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x80042690: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042694: lh          $t4, 0x1A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A);
    // 0x80042698: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8004269C: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800426A0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800426A4: sb          $t3, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r11;
    // 0x800426A8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800426AC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800426B0: b           L_80042974
    // 0x800426B4: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
        goto L_80042974;
    // 0x800426B4: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
L_800426B8:
    // 0x800426B8: lb          $t6, 0x18($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X18);
    // 0x800426BC: lb          $v0, 0x19($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X19);
    // 0x800426C0: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x800426C4: blez        $v0, L_800426D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800426C8: sb          $t7, 0x18($s0)
        MEM_B(0X18, ctx->r16) = ctx->r15;
            goto L_800426D4;
    }
    // 0x800426C8: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x800426CC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800426D0: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
L_800426D4:
    // 0x800426D4: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x800426D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800426DC: bgez        $v1, L_800426F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800426E0: addiu       $a1, $zero, 0x12C
        ctx->r5 = ADD32(0, 0X12C);
            goto L_800426F8;
    }
    // 0x800426E0: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x800426E4: jal         0x8006F94C
    // 0x800426E8: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    rand_range(rdram, ctx);
        goto after_15;
    // 0x800426E8: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    after_15:
    // 0x800426EC: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // 0x800426F0: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x800426F4: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
L_800426F8:
    // 0x800426F8: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800426FC: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80042700: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80042704: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80042708: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8004270C: mflo        $t2
    ctx->r10 = lo;
    // 0x80042710: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x80042714: lb          $t3, 0x18($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18);
    // 0x80042718: nop

    // 0x8004271C: sll         $t4, $t3, 26
    ctx->r12 = S32(ctx->r11 << 26);
    // 0x80042720: jal         0x800707F8
    // 0x80042724: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_16;
    // 0x80042724: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_16:
    // 0x80042728: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004272C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80042730: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80042734: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80042738: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004273C: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80042740: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x80042744: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80042748: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004274C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80042750: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80042754: nop

    // 0x80042758: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004275C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80042760: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80042764: nop

    // 0x80042768: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004276C: jal         0x80011560
    // 0x80042770: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_17;
    // 0x80042770: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    after_17:
    // 0x80042774: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80042778: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8004277C: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80042780: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80042784: jal         0x80011570
    // 0x80042788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_18;
    // 0x80042788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x8004278C: lh          $a0, 0x2E($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2E);
    // 0x80042790: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042794: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x80042798: jal         0x8002BAB0
    // 0x8004279C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    collision_get_y(rdram, ctx);
        goto after_19;
    // 0x8004279C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x800427A0: beq         $v0, $zero, L_800427C4
    if (ctx->r2 == 0) {
        // 0x800427A4: nop
    
            goto L_800427C4;
    }
    // 0x800427A4: nop

    // 0x800427A8: jal         0x80011560
    // 0x800427AC: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_20;
    // 0x800427AC: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    after_20:
    // 0x800427B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800427B4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800427B8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800427BC: jal         0x80011570
    // 0x800427C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_21;
    // 0x800427C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
L_800427C4:
    // 0x800427C4: lb          $t6, 0x19($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X19);
    // 0x800427C8: nop

    // 0x800427CC: bgtz        $t6, L_80042978
    if (SIGNED(ctx->r14) > 0) {
        // 0x800427D0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80042978;
    }
    // 0x800427D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800427D4: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x800427D8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x800427DC: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x800427E0: bne         $at, $zero, L_800427F4
    if (ctx->r1 != 0) {
        // 0x800427E4: addiu       $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_800427F4;
    }
    // 0x800427E4: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x800427E8: slti        $at, $v1, 0x1B
    ctx->r1 = SIGNED(ctx->r3) < 0X1B ? 1 : 0;
    // 0x800427EC: bne         $at, $zero, L_80042978
    if (ctx->r1 != 0) {
        // 0x800427F0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80042978;
    }
    // 0x800427F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800427F4:
    // 0x800427F4: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800427F8: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800427FC: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x80042800: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80042804: jal         0x80016DE8
    // 0x80042808: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    obj_dist_racer(rdram, ctx);
        goto after_22;
    // 0x80042808: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x8004280C: beq         $v0, $zero, L_80042978
    if (ctx->r2 == 0) {
        // 0x80042810: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80042978;
    }
    // 0x80042810: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80042814: lbu         $t8, 0x15($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15);
    // 0x80042818: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8004281C: beq         $t8, $zero, L_80042870
    if (ctx->r24 == 0) {
        // 0x80042820: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_80042870;
    }
    // 0x80042820: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80042824: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042828: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004282C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042830: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80042834: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042838: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004283C: jal         0x80009558
    // 0x80042840: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_23;
    // 0x80042840: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_23:
    // 0x80042844: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80042848: jal         0x8009EA78
    // 0x8004284C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_eeprom_settings_value(rdram, ctx);
        goto after_24;
    // 0x8004284C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80042850: jal         0x8009C2E0
    // 0x80042854: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_25;
    // 0x80042854: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_25:
    // 0x80042858: jal         0x8006D8A4
    // 0x8004285C: nop

    set_drumstick_unlock_transition(rdram, ctx);
        goto after_26;
    // 0x8004285C: nop

    after_26:
    // 0x80042860: jal         0x8000FFB8
    // 0x80042864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_27;
    // 0x80042864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80042868: b           L_80042978
    // 0x8004286C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80042978;
    // 0x8004286C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80042870:
    // 0x80042870: sb          $t0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r8;
    // 0x80042874: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042878: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004287C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042880: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80042884: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80042888: jal         0x80009558
    // 0x8004288C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_28;
    // 0x8004288C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_28:
    // 0x80042890: b           L_80042978
    // 0x80042894: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80042978;
    // 0x80042894: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80042898:
    // 0x80042898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004289C: lwc1        $f0, 0x6270($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6270);
    // 0x800428A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800428A4: lwc1        $f18, 0x6274($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6274);
    // 0x800428A8: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800428AC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800428B0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800428B4: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x800428B8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800428BC: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x800428C0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800428C4: nop

    // 0x800428C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800428CC: nop

    // 0x800428D0: bc1f        L_80042978
    if (!c1cs) {
        // 0x800428D4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80042978;
    }
    // 0x800428D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800428D8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x800428DC: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x800428E0: b           L_80042974
    // 0x800428E4: sh          $t3, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r11;
        goto L_80042974;
    // 0x800428E4: sh          $t3, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r11;
L_800428E8:
    // 0x800428E8: lh          $t4, 0x16($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16);
    // 0x800428EC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800428F0: subu        $t5, $t4, $a1
    ctx->r13 = SUB32(ctx->r12, ctx->r5);
    // 0x800428F4: sh          $t5, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r13;
    // 0x800428F8: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x800428FC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x80042900: bgez        $t6, L_80042974
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80042904: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80042974;
    }
    // 0x80042904: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80042908: sb          $t7, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r15;
    // 0x8004290C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042910: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80042914: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042918: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004291C: jal         0x80009558
    // 0x80042920: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_29;
    // 0x80042920: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_29:
    // 0x80042924: b           L_80042978
    // 0x80042928: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80042978;
    // 0x80042928: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8004292C:
    // 0x8004292C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042930: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80042934: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80042938: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8004293C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80042940: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042944: bc1f        L_80042960
    if (!c1cs) {
        // 0x80042948: nop
    
            goto L_80042960;
    }
    // 0x80042948: nop

    // 0x8004294C: swc1        $f12, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f12.u32l;
    // 0x80042950: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x80042954: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x80042958: b           L_80042974
    // 0x8004295C: sb          $t9, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r25;
        goto L_80042974;
    // 0x8004295C: sb          $t9, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r25;
L_80042960:
    // 0x80042960: lwc1        $f10, 0x6278($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6278);
    // 0x80042964: nop

    // 0x80042968: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004296C: add.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80042970: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_80042974:
    // 0x80042974: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80042978:
    // 0x80042978: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8004297C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80042980: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80042984: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80042988: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8004298C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80042990: jr          $ra
    // 0x80042994: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x80042994: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void delete_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800762C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800762CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800762D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800762D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800762D8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800762DC: jal         0x800758DC
    // 0x800762E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800762E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x800762E4: beq         $v0, $zero, L_80076300
    if (ctx->r2 == 0) {
        // 0x800762E8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80076300;
    }
    // 0x800762E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800762EC: jal         0x80075AEC
    // 0x800762F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x800762F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800762F4: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800762F8: b           L_80076374
    // 0x800762FC: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
        goto L_80076374;
    // 0x800762FC: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
L_80076300:
    // 0x80076300: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80076304: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80076308: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007630C: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80076310: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80076314: sll         $s1, $s0, 30
    ctx->r17 = S32(ctx->r16 << 30);
    // 0x80076318: addiu       $t9, $t9, 0x4018
    ctx->r25 = ADD32(ctx->r25, 0X4018);
    // 0x8007631C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80076320: ori         $t7, $s1, 0x9
    ctx->r15 = ctx->r17 | 0X9;
    // 0x80076324: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80076328: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8007632C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80076330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80076334: jal         0x800D0580
    // 0x80076338: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x80076338: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8007633C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076340: bne         $v0, $zero, L_80076368
    if (ctx->r2 != 0) {
        // 0x80076344: addiu       $a3, $sp, 0x3E
        ctx->r7 = ADD32(ctx->r29, 0X3E);
            goto L_80076368;
    }
    // 0x80076344: addiu       $a3, $sp, 0x3E
    ctx->r7 = ADD32(ctx->r29, 0X3E);
    // 0x80076348: lhu         $a1, 0x38($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X38);
    // 0x8007634C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80076350: addiu       $t0, $sp, 0x3A
    ctx->r8 = ADD32(ctx->r29, 0X3A);
    // 0x80076354: jal         0x800D0870
    // 0x80076358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_3;
    // 0x80076358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x8007635C: bne         $v0, $zero, L_80076368
    if (ctx->r2 != 0) {
        // 0x80076360: nop
    
            goto L_80076368;
    }
    // 0x80076360: nop

    // 0x80076364: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80076368:
    // 0x80076368: jal         0x80075AEC
    // 0x8007636C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x8007636C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80076370: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80076374:
    // 0x80076374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80076378: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007637C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80076380: jr          $ra
    // 0x80076384: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80076384: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064638: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006463C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064644: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80064648: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006464C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064650: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80064654: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80064658: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006465C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80064660: beq         $at, $zero, L_8006466C
    if (ctx->r1 == 0) {
        // 0x80064664: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_8006466C;
    }
    // 0x80064664: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x80064668: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8006466C:
    // 0x8006466C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80064670: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80064674: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80064678: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x8006467C: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x80064680: beq         $at, $zero, L_80064774
    if (ctx->r1 == 0) {
        // 0x80064684: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80064774;
    }
    // 0x80064684: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80064688: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8006468C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x80064690: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80064694: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80064698: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8006469C: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800646A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800646A4: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800646A8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800646AC: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x800646B0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800646B4: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800646B8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800646BC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800646C0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800646C4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800646C8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800646CC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800646D0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800646D4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800646D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800646DC: jal         0x800C8CF0
    // 0x800646E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800646E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800646E4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800646E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800646EC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800646F0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800646F4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800646F8: lui         $t5, 0x800
    ctx->r13 = S32(0X800 << 16);
    // 0x800646FC: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80064700: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80064704: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80064708: subu        $t3, $a3, $t0
    ctx->r11 = SUB32(ctx->r7, ctx->r8);
    // 0x8006470C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80064710: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80064714: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80064718: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8006471C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80064720: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80064724: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064728: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006472C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064730: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80064734: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80064738: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8006473C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064740: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x80064744: jal         0x800C8CF0
    // 0x80064748: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80064748: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006474C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80064750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80064754: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064758: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006475C: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x80064760: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80064764: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80064768: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006476C: b           L_800647BC
    // 0x80064770: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800647BC;
    // 0x80064770: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80064774:
    // 0x80064774: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x80064778: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8006477C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80064780: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x80064784: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x80064788: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8006478C: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x80064790: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x80064794: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80064798: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8006479C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800647A0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800647A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800647A8: jal         0x800C8CF0
    // 0x800647AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800647AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800647B0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800647B4: nop

    // 0x800647B8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800647BC:
    // 0x800647BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800647C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800647C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800647C8: jr          $ra
    // 0x800647CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800647CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void hud_sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7440: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A7444: lw          $t6, 0x6D40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D40);
    // 0x800A7448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A744C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7450: bne         $t6, $zero, L_800A7474
    if (ctx->r14 != 0) {
        // 0x800A7454: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800A7474;
    }
    // 0x800A7454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A7458: jal         0x8006EAA0
    // 0x800A745C: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A745C: nop

    after_0:
    // 0x800A7460: bne         $v0, $zero, L_800A7474
    if (ctx->r2 != 0) {
        // 0x800A7464: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A7474;
    }
    // 0x800A7464: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7468: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x800A746C: jal         0x80001D04
    // 0x800A7470: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A7470: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_1:
L_800A7474:
    // 0x800A7474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A747C: jr          $ra
    // 0x800A7480: nop

    return;
    // 0x800A7480: nop

;}
RECOMP_FUNC void func_80065A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_audio_voice_guard(uint8_t*, recomp_context*); if (dkr_audio_voice_guard(rdram, ctx)) { return; }
    // 0x80065A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065A84: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065A90: lbu         $v0, 0xDC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XDC);
    // 0x80065A94: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x80065A98: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80065A9C: beq         $t6, $v0, L_80065B10
    if (ctx->r14 == ctx->r2) {
        // 0x80065AA0: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80065B10;
    }
    // 0x80065AA0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80065AA4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80065AA8: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80065AAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065AB0: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80065AB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065AB8: addiu       $a2, $a3, 0x8C
    ctx->r6 = ADD32(ctx->r7, 0X8C);
    // 0x80065ABC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80065AC0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065AC4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80065AC8: jal         0x800659D4
    // 0x80065ACC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    alAuxBusParam(rdram, ctx);
        goto after_0;
    // 0x80065ACC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80065AD0: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80065AD4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80065AD8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80065ADC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80065AE0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065AE4: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x80065AE8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80065AEC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80065AF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065AF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065AF8: jal         0x800659D4
    // 0x80065AFC: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    alAuxBusParam(rdram, ctx);
        goto after_1;
    // 0x80065AFC: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    after_1:
    // 0x80065B00: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80065B04: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065B08: nop

    // 0x80065B0C: sb          $t4, 0xDC($t5)
    MEM_B(0XDC, ctx->r13) = ctx->r12;
L_80065B10:
    // 0x80065B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065B18: jr          $ra
    // 0x80065B1C: nop

    return;
    // 0x80065B1C: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4944: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D4948: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D494C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D4950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D4954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D4958: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800D495C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800D4960: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800D4964:
    // 0x800D4964: bnel        $v0, $zero, L_800D4978
    if (ctx->r2 != 0) {
        // 0x800D4968: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800D4978;
    }
    goto skip_0;
    // 0x800D4968: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800D496C: b           L_800D4978
    // 0x800D4970: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800D4978;
    // 0x800D4970: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800D4974: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800D4978:
    // 0x800D4978: bnel        $v0, $a0, L_800D498C
    if (ctx->r2 != ctx->r4) {
        // 0x800D497C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800D498C;
    }
    goto skip_1;
    // 0x800D497C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800D4980: b           L_800D498C
    // 0x800D4984: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800D498C;
    // 0x800D4984: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800D4988: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800D498C:
    // 0x800D498C: bnel        $v0, $a1, L_800D49A0
    if (ctx->r2 != ctx->r5) {
        // 0x800D4990: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800D49A0;
    }
    goto skip_2;
    // 0x800D4990: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800D4994: b           L_800D49A0
    // 0x800D4998: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800D49A0;
    // 0x800D4998: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800D499C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800D49A0:
    // 0x800D49A0: bnel        $v0, $a2, L_800D49B4
    if (ctx->r2 != ctx->r6) {
        // 0x800D49A4: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800D49B4;
    }
    goto skip_3;
    // 0x800D49A4: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800D49A8: b           L_800D49B4
    // 0x800D49AC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800D49B4;
    // 0x800D49AC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800D49B0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800D49B4:
    // 0x800D49B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D49B8: bne         $v0, $a3, L_800D4964
    if (ctx->r2 != ctx->r7) {
        // 0x800D49BC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800D4964;
    }
    // 0x800D49BC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D49C0: jr          $ra
    // 0x800D49C4: nop

    return;
    // 0x800D49C4: nop

;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000AC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000AC40: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x8000AC44: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000AC48: beq         $a3, $zero, L_8000ACD0
    if (ctx->r7 == 0) {
        // 0x8000AC4C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8000ACD0;
    }
    // 0x8000AC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000AC50: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8000AC54:
    // 0x8000AC54: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8000AC58: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x8000AC5C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000AC60: bne         $a0, $t7, L_8000ACC8
    if (ctx->r4 != ctx->r15) {
        // 0x8000AC64: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_8000ACC8;
    }
    // 0x8000AC64: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8000AC68: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x8000AC6C: nop

    // 0x8000AC70: bne         $a1, $t8, L_8000ACC8
    if (ctx->r5 != ctx->r24) {
        // 0x8000AC74: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8000ACC8;
    }
    // 0x8000AC74: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000AC78: beq         $at, $zero, L_8000ACC0
    if (ctx->r1 == 0) {
        // 0x8000AC7C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000ACC0;
    }
    // 0x8000AC7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000AC80: beq         $v0, $zero, L_8000AC98
    if (ctx->r2 == 0) {
        // 0x8000AC84: nop
    
            goto L_8000AC98;
    }
    // 0x8000AC84: nop

    // 0x8000AC88: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000AC8C: nop

    // 0x8000AC90: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8000AC94: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
L_8000AC98:
    // 0x8000AC98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000AC9C: jal         0x800C8760
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    after_0:
    // 0x8000ACA4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8000ACA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000ACAC: jal         0x800C8790
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_1:
    // 0x8000ACB4: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x8000ACB8: b           L_8000ACD4
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000ACD4;
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACC0:
    // 0x8000ACC0: b           L_8000ACD0
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8000ACD0;
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8000ACC8:
    // 0x8000ACC8: bne         $v0, $zero, L_8000AC54
    if (ctx->r2 != 0) {
        // 0x8000ACCC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8000AC54;
    }
    // 0x8000ACCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000ACD0:
    // 0x8000ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACD4:
    // 0x8000ACD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000ACD8: jr          $ra
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void directional_lighting_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B43C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B444: sh          $v0, 0x6384($at)
    MEM_H(0X6384, ctx->r1) = ctx->r2;
    // 0x8007B448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B44C: jr          $ra
    // 0x8007B450: sh          $v0, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r2;
    return;
    // 0x8007B450: sh          $v0, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void obj_table_ids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001001C: lw          $v0, -0x5144($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5144);
    // 0x80010020: jr          $ra
    // 0x80010024: nop

    return;
    // 0x80010024: nop

;}
RECOMP_FUNC void rendermode_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B3D4: sw          $zero, 0x637C($at)
    MEM_W(0X637C, ctx->r1) = 0;
    // 0x8007B3D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B3DC: sw          $zero, 0x6374($at)
    MEM_W(0X6374, ctx->r1) = 0;
    // 0x8007B3E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B3E4: sh          $zero, 0x6380($at)
    MEM_H(0X6380, ctx->r1) = 0;
    // 0x8007B3E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B3EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B3F0: sh          $t6, 0x6382($at)
    MEM_H(0X6382, ctx->r1) = ctx->r14;
    // 0x8007B3F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B3F8: sw          $zero, 0x6378($at)
    MEM_W(0X6378, ctx->r1) = 0;
    // 0x8007B3FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B400: sh          $zero, 0x6384($at)
    MEM_H(0X6384, ctx->r1) = 0;
    // 0x8007B404: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B408: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007B40C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007B410: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B414: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007B418: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007B41C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B420: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8007B424: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007B428: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B42C: addiu       $t1, $zero, 0x205
    ctx->r9 = ADD32(0, 0X205);
    // 0x8007B430: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007B434: jr          $ra
    // 0x8007B438: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x8007B438: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void menu_imagegroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C8A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C8A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C8AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C8B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C8B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C8B8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009C8BC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009C8C0: beq         $s2, $t6, L_8009C8F0
    if (ctx->r18 == ctx->r14) {
        // 0x8009C8C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009C8F0;
    }
    // 0x8009C8C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009C8C8: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009C8CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009C8D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009C8D4:
    // 0x8009C8D4: jal         0x8009C904
    // 0x8009C8D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_image_load(rdram, ctx);
        goto after_0;
    // 0x8009C8D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009C8DC: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009C8E0: nop

    // 0x8009C8E4: bne         $s2, $s1, L_8009C8D4
    if (ctx->r18 != ctx->r17) {
        // 0x8009C8E8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009C8D4;
    }
    // 0x8009C8E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009C8EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009C8F0:
    // 0x8009C8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C8F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C8F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C8FC: jr          $ra
    // 0x8009C900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009C900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sndp_set_param(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_scale_sound_effect_volume(uint8_t*, recomp_context*); dkr_scale_sound_effect_volume(rdram, ctx);
    // 0x800049F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800049FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004A00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80004A04: sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // 0x80004A08: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80004A0C: beq         $a0, $zero, L_80004A2C
    if (ctx->r4 == 0) {
        // 0x80004A10: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80004A2C;
    }
    // 0x80004A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004A18: lw          $a0, -0x3944($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3944);
    // 0x80004A1C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80004A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004A24: jal         0x800C91AC
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_80004A2C:
    // 0x80004A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004A34: jr          $ra
    // 0x80004A38: nop

    return;
    // 0x80004A38: nop

;}
RECOMP_FUNC void func_80054FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054FD0: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x80054FD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80054FD8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80054FDC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80054FE0: sw          $a2, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r6;
    // 0x80054FE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054FE8: lwc1        $f0, -0x2B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B10);
    // 0x80054FEC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80054FF0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80054FF4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80054FF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80054FFC: bc1f        L_80055010
    if (!c1cs) {
        // 0x80055000: nop
    
            goto L_80055010;
    }
    // 0x80055000: nop

    // 0x80055004: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80055008: jal         0x8002ACC8
    // 0x8005500C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_collision_mode(rdram, ctx);
        goto after_0;
    // 0x8005500C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_80055010:
    // 0x80055010: sh          $zero, 0x130($sp)
    MEM_H(0X130, ctx->r29) = 0;
    // 0x80055014: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80055018: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005501C: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80055020: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80055024: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80055028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005502C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80055030: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    // 0x80055034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80055038: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x8005503C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x80055040: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055044: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80055048: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x8005504C: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055050: nop

    // 0x80055054: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80055058: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005505C: jal         0x8006FC30
    // 0x80055060: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x80055060: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    after_1:
    // 0x80055064: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80055068: lw          $v1, -0x2A98($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2A98);
    // 0x8005506C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80055070: addiu       $t1, $sp, 0x134
    ctx->r9 = ADD32(ctx->r29, 0X134);
    // 0x80055074: addiu       $t2, $sp, 0x138
    ctx->r10 = ADD32(ctx->r29, 0X138);
    // 0x80055078: addiu       $t3, $sp, 0x13C
    ctx->r11 = ADD32(ctx->r29, 0X13C);
    // 0x8005507C: addiu       $t4, $sp, 0xE0
    ctx->r12 = ADD32(ctx->r29, 0XE0);
    // 0x80055080: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_80055084:
    // 0x80055084: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80055088: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8005508C: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x80055090: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80055094: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80055098: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8005509C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800550A0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x800550A4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800550A8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800550AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800550B0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800550B4: jal         0x8006F64C
    // 0x800550B8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800550B8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    after_2:
    // 0x800550BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800550C0: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800550C4: lw          $t9, -0x2A98($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2A98);
    // 0x800550C8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800550CC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800550D0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800550D4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800550D8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800550DC: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x800550E0: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800550E4: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x800550E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800550EC: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800550F0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800550F4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800550F8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800550FC: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
    // 0x80055100: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80055104: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80055108: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8005510C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80055110: bne         $at, $zero, L_80055084
    if (ctx->r1 != 0) {
        // 0x80055114: swc1        $f6, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->f6.u32l;
            goto L_80055084;
    }
    // 0x80055114: swc1        $f6, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80055118: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005511C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80055120: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80055124: addiu       $t0, $t0, -0x2AB4
    ctx->r8 = ADD32(ctx->r8, -0X2AB4);
    // 0x80055128: addiu       $v1, $v1, -0x2AB8
    ctx->r3 = ADD32(ctx->r3, -0X2AB8);
    // 0x8005512C: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x80055130: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80055134: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80055138: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005513C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055140: bne         $t7, $at, L_80055158
    if (ctx->r15 != ctx->r1) {
        // 0x80055144: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80055158;
    }
    // 0x80055144: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80055148: lb          $t8, 0x1D7($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005514C: nop

    // 0x80055150: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80055154: beq         $at, $zero, L_8005519C
    if (ctx->r1 == 0) {
        // 0x80055158: addiu       $t9, $sp, 0x134
        ctx->r25 = ADD32(ctx->r29, 0X134);
            goto L_8005519C;
    }
L_80055158:
    // 0x80055158: addiu       $t9, $sp, 0x134
    ctx->r25 = ADD32(ctx->r29, 0X134);
    // 0x8005515C: addiu       $t5, $sp, 0xE0
    ctx->r13 = ADD32(ctx->r29, 0XE0);
    // 0x80055160: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80055164: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80055168: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005516C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80055170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055174: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80055178: addiu       $a2, $sp, 0x190
    ctx->r6 = ADD32(ctx->r29, 0X190);
    // 0x8005517C: jal         0x80017248
    // 0x80055180: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    collision_objectmodel(rdram, ctx);
        goto after_3;
    // 0x80055180: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    after_3:
    // 0x80055184: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80055188: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005518C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055190: addiu       $t0, $t0, -0x2AB4
    ctx->r8 = ADD32(ctx->r8, -0X2AB4);
    // 0x80055194: addiu       $v1, $v1, -0x2AB8
    ctx->r3 = ADD32(ctx->r3, -0X2AB8);
    // 0x80055198: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8005519C:
    // 0x8005519C: andi        $t7, $t1, 0x80
    ctx->r15 = ctx->r9 & 0X80;
    // 0x800551A0: beq         $t7, $zero, L_800552A0
    if (ctx->r15 == 0) {
        // 0x800551A4: addiu       $a1, $s0, 0xD8
        ctx->r5 = ADD32(ctx->r16, 0XD8);
            goto L_800552A0;
    }
    // 0x800551A4: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x800551A8: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x800551AC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800551B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800551B4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800551B8: lwc1        $f6, 0x13C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800551BC: swc1        $f4, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f4.u32l;
    // 0x800551C0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800551C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800551C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800551CC: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800551D0: swc1        $f10, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f10.u32l;
    // 0x800551D4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800551D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800551DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800551E0: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800551E4: swc1        $f8, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f8.u32l;
    // 0x800551E8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800551EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800551F0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800551F4: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800551F8: swc1        $f6, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f6.u32l;
    // 0x800551FC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055200: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055204: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055208: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8005520C: swc1        $f4, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f4.u32l;
    // 0x80055210: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80055214: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055218: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005521C: lwc1        $f4, 0x158($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80055220: swc1        $f10, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f10.u32l;
    // 0x80055224: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005522C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055230: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x80055234: swc1        $f8, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f8.u32l;
    // 0x80055238: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005523C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055240: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055244: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055248: swc1        $f6, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f6.u32l;
    // 0x8005524C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80055250: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80055254: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055258: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005525C: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80055260: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80055264: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80055268: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x8005526C: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80055270: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80055274: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80055278: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8005527C: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x80055280: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055284: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80055288: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005528C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80055290: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055294: sh          $t8, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r24;
    // 0x80055298: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8005529C: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
L_800552A0:
    // 0x800552A0: beq         $t1, $zero, L_8005531C
    if (ctx->r9 == 0) {
        // 0x800552A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005531C;
    }
    // 0x800552A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800552A8: lwc1        $f8, 0x138($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800552AC: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800552B0: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800552B4: lwc1        $f4, 0x150($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800552B8: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800552BC: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x800552C0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800552C4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800552C8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800552CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800552D0: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
    // 0x800552D4: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800552D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800552DC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800552E0: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800552E4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800552E8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800552EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800552F0: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    // 0x800552F4: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800552F8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800552FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80055300: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80055304: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x80055308: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8005530C: nop

    // 0x80055310: bc1f        L_8005531C
    if (!c1cs) {
        // 0x80055314: nop
    
            goto L_8005531C;
    }
    // 0x80055314: nop

    // 0x80055318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005531C:
    // 0x8005531C: lb          $a3, 0x1D6($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055320: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x80055324: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80055328: sb          $v0, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r2;
    // 0x8005532C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80055330: jal         0x80031130
    // 0x80055334: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    generate_collision_candidates(rdram, ctx);
        goto after_4;
    // 0x80055334: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    after_4:
    // 0x80055338: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8005533C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80055340: addiu       $t6, $sp, 0x190
    ctx->r14 = ADD32(ctx->r29, 0X190);
    // 0x80055344: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x80055348: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005534C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80055350: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80055354: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80055358: jal         0x80031600
    // 0x8005535C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    resolve_collisions(rdram, ctx);
        goto after_5;
    // 0x8005535C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x80055360: sb          $v0, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r2;
    // 0x80055364: addiu       $a0, $sp, 0x180
    ctx->r4 = ADD32(ctx->r29, 0X180);
    // 0x80055368: addiu       $a1, $sp, 0x178
    ctx->r5 = ADD32(ctx->r29, 0X178);
    // 0x8005536C: jal         0x8002ACD4
    // 0x80055370: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    get_collision_normal(rdram, ctx);
        goto after_6;
    // 0x80055370: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    after_6:
    // 0x80055374: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x80055378: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005537C: beq         $v0, $zero, L_80055584
    if (ctx->r2 == 0) {
        // 0x80055380: sw          $v0, 0x184($sp)
        MEM_W(0X184, ctx->r29) = ctx->r2;
            goto L_80055584;
    }
    // 0x80055380: sw          $v0, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r2;
    // 0x80055384: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80055388: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005538C: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80055390: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x80055394: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80055398: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x8005539C: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800553A0: jal         0x80070750
    // 0x800553A4: nop

    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x800553A4: nop

    after_7:
    // 0x800553A8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800553AC: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800553B0: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x800553B4: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800553B8: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800553BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800553C0: slti        $at, $t6, 0x2000
    ctx->r1 = SIGNED(ctx->r14) < 0X2000 ? 1 : 0;
    // 0x800553C4: beq         $at, $zero, L_800553D4
    if (ctx->r1 == 0) {
        // 0x800553C8: slti        $at, $t6, -0x1FFF
        ctx->r1 = SIGNED(ctx->r14) < -0X1FFF ? 1 : 0;
            goto L_800553D4;
    }
    // 0x800553C8: slti        $at, $t6, -0x1FFF
    ctx->r1 = SIGNED(ctx->r14) < -0X1FFF ? 1 : 0;
    // 0x800553CC: beq         $at, $zero, L_800553E0
    if (ctx->r1 == 0) {
        // 0x800553D0: nop
    
            goto L_800553E0;
    }
    // 0x800553D0: nop

L_800553D4:
    // 0x800553D4: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x800553D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800553DC: bne         $t7, $at, L_80055584
    if (ctx->r15 != ctx->r1) {
        // 0x800553E0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80055584;
    }
L_800553E0:
    // 0x800553E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800553E4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800553E8: lwc1        $f7, 0x6838($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6838);
    // 0x800553EC: lwc1        $f6, 0x683C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X683C);
    // 0x800553F0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800553F4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800553F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800553FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80055400: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80055404: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80055408: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005540C: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x80055410: bc1f        L_80055420
    if (!c1cs) {
        // 0x80055414: nop
    
            goto L_80055420;
    }
    // 0x80055414: nop

    // 0x80055418: neg.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = -ctx->f10.fl;
    // 0x8005541C: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
L_80055420:
    // 0x80055420: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055424: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80055428: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005542C: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80055430: nop

    // 0x80055434: bc1f        L_80055474
    if (!c1cs) {
        // 0x80055438: nop
    
            goto L_80055474;
    }
    // 0x80055438: nop

    // 0x8005543C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80055440: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80055444: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80055448: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x8005544C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x80055450: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80055454: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80055458: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8005545C: jal         0x80072424
    // 0x80055460: nop

    rumble_set_fade(rdram, ctx);
        goto after_8;
    // 0x80055460: nop

    after_8:
    // 0x80055464: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055468: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x8005546C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055470: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_80055474:
    // 0x80055474: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80055478: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005547C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80055480: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
    // 0x80055484: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80055488: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8005548C: bc1f        L_80055584
    if (!c1cs) {
        // 0x80055490: nop
    
            goto L_80055584;
    }
    // 0x80055490: nop

    // 0x80055494: lbu         $t8, 0x1F3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F3);
    // 0x80055498: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005549C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800554A0: sb          $t9, 0x1F3($s0)
    MEM_B(0X1F3, ctx->r16) = ctx->r25;
    // 0x800554A4: lw          $t5, -0x2AA4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AA4);
    // 0x800554A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800554AC: beq         $t5, $at, L_800554C8
    if (ctx->r13 == ctx->r1) {
        // 0x800554B0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800554C8;
    }
    // 0x800554B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800554B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800554B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800554BC: lw          $t6, -0x2AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AF8);
    // 0x800554C0: nop

    // 0x800554C4: swc1        $f6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f6.u32l;
L_800554C8:
    // 0x800554C8: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800554CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800554D0: beq         $t8, $at, L_80055508
    if (ctx->r24 == ctx->r1) {
        // 0x800554D4: sb          $t7, 0x1D2($s0)
        MEM_B(0X1D2, ctx->r16) = ctx->r15;
            goto L_80055508;
    }
    // 0x800554D4: sb          $t7, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r15;
    // 0x800554D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800554DC: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x800554E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800554E4: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    // 0x800554E8: jal         0x800570B8
    // 0x800554EC: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    play_random_character_voice(rdram, ctx);
        goto after_9;
    // 0x800554EC: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    after_9:
    // 0x800554F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800554F4: jal         0x80057048
    // 0x800554F8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    racer_play_sound(rdram, ctx);
        goto after_10;
    // 0x800554F8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_10:
    // 0x800554FC: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x80055500: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055504: nop

L_80055508:
    // 0x80055508: lbu         $t9, 0x1EF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1EF);
    // 0x8005550C: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055514: ori         $t5, $t9, 0x4
    ctx->r13 = ctx->r25 | 0X4;
    // 0x80055518: bne         $t6, $at, L_80055540
    if (ctx->r14 != ctx->r1) {
        // 0x8005551C: sb          $t5, 0x1EF($s0)
        MEM_B(0X1EF, ctx->r16) = ctx->r13;
            goto L_80055540;
    }
    // 0x8005551C: sb          $t5, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r13;
    // 0x80055520: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055524: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80055528: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005552C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80055530: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80055534: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80055538: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8005553C: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
L_80055540:
    // 0x80055540: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80055544: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055548: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005554C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80055550: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x80055554: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055558: lwc1        $f4, 0x17C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8005555C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80055560: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055564: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80055568: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
    // 0x8005556C: lwc1        $f6, 0x6844($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6844);
    // 0x80055570: lwc1        $f7, 0x6840($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6840);
    // 0x80055574: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x80055578: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005557C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80055580: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_80055584:
    // 0x80055584: lb          $t7, 0x5F($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X5F);
    // 0x80055588: nop

    // 0x8005558C: beq         $t7, $zero, L_80055608
    if (ctx->r15 == 0) {
        // 0x80055590: nop
    
            goto L_80055608;
    }
    // 0x80055590: nop

    // 0x80055594: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x80055598: nop

    // 0x8005559C: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800555A0: bne         $at, $zero, L_80055608
    if (ctx->r1 != 0) {
        // 0x800555A4: nop
    
            goto L_80055608;
    }
    // 0x800555A4: nop

    // 0x800555A8: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800555AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800555B0: beq         $t9, $at, L_800555EC
    if (ctx->r25 == ctx->r1) {
        // 0x800555B4: nop
    
            goto L_800555EC;
    }
    // 0x800555B4: nop

    // 0x800555B8: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x800555BC: nop

    // 0x800555C0: bne         $t5, $zero, L_800555EC
    if (ctx->r13 != 0) {
        // 0x800555C4: nop
    
            goto L_800555EC;
    }
    // 0x800555C4: nop

    // 0x800555C8: lh          $t6, 0x18E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18E);
    // 0x800555CC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x800555D0: bgtz        $t6, L_800555EC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800555D4: addiu       $a1, $s0, 0x20
        ctx->r5 = ADD32(ctx->r16, 0X20);
            goto L_800555EC;
    }
    // 0x800555D4: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x800555D8: jal         0x80001D04
    // 0x800555DC: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x800555DC: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    after_11:
    // 0x800555E0: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800555E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800555E8: nop

L_800555EC:
    // 0x800555EC: lb          $t7, 0x1ED($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1ED);
    // 0x800555F0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800555F4: bne         $t7, $zero, L_80055604
    if (ctx->r15 != 0) {
        // 0x800555F8: addiu       $t9, $zero, 0x3C
        ctx->r25 = ADD32(0, 0X3C);
            goto L_80055604;
    }
    // 0x800555F8: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x800555FC: b           L_80055608
    // 0x80055600: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
        goto L_80055608;
    // 0x80055600: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
L_80055604:
    // 0x80055604: sb          $t9, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r25;
L_80055608:
    // 0x80055608: lb          $t5, 0x1E3($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E3);
    // 0x8005560C: sb          $t1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r9;
    // 0x80055610: or          $t6, $t5, $t1
    ctx->r14 = ctx->r13 | ctx->r9;
    // 0x80055614: sb          $t6, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r14;
    // 0x80055618: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x8005561C: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x80055620: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80055624: beq         $t7, $zero, L_8005563C
    if (ctx->r15 == 0) {
        // 0x80055628: addiu       $v1, $sp, 0x134
        ctx->r3 = ADD32(ctx->r29, 0X134);
            goto L_8005563C;
    }
    // 0x80055628: addiu       $v1, $sp, 0x134
    ctx->r3 = ADD32(ctx->r29, 0X134);
    // 0x8005562C: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x80055630: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055634: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80055638: sb          $t9, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r25;
L_8005563C:
    // 0x8005563C: sll         $t5, $v0, 30
    ctx->r13 = S32(ctx->r2 << 30);
    // 0x80055640: bgez        $t5, L_80055658
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80055644: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80055658;
    }
    // 0x80055644: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80055648: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005564C: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055650: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80055654: sb          $t7, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r15;
L_80055658:
    // 0x80055658: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x8005565C: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x80055660: beq         $t9, $zero, L_80055678
    if (ctx->r25 == 0) {
        // 0x80055664: or          $t1, $t8, $zero
        ctx->r9 = ctx->r24 | 0;
            goto L_80055678;
    }
    // 0x80055664: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80055668: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005566C: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055670: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80055674: sb          $t6, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r14;
L_80055678:
    // 0x80055678: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x8005567C: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x80055680: beq         $t8, $zero, L_80055698
    if (ctx->r24 == 0) {
        // 0x80055684: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80055698;
    }
    // 0x80055684: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80055688: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005568C: nop

    // 0x80055690: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80055694: sb          $t5, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r13;
L_80055698:
    // 0x80055698: addiu       $a0, $sp, 0x164
    ctx->r4 = ADD32(ctx->r29, 0X164);
L_8005569C:
    // 0x8005569C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800556A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800556A4: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800556A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800556AC: bne         $at, $zero, L_8005569C
    if (ctx->r1 != 0) {
        // 0x800556B0: swc1        $f4, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
            goto L_8005569C;
    }
    // 0x800556B0: swc1        $f4, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
    // 0x800556B4: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800556B8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800556BC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
L_800556C0:
    // 0x800556C0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x800556C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800556C8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800556CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800556D0: bne         $at, $zero, L_800556C0
    if (ctx->r1 != 0) {
        // 0x800556D4: sb          $t6, 0x1DB($v1)
        MEM_B(0X1DB, ctx->r3) = ctx->r14;
            goto L_800556C0;
    }
    // 0x800556D4: sb          $t6, 0x1DB($v1)
    MEM_B(0X1DB, ctx->r3) = ctx->r14;
    // 0x800556D8: swc1        $f16, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f16.u32l;
    // 0x800556DC: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
    // 0x800556E0: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x800556E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800556E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800556EC:
    // 0x800556EC: lwc1        $f6, 0xD8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x800556F0: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800556F4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800556F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800556FC: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055700: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80055704: lwc1        $f4, 0xDC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x80055708: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8005570C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055710: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055714: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x80055718: lwc1        $f10, 0xE0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x8005571C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80055720: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055724: bne         $at, $zero, L_800556EC
    if (ctx->r1 != 0) {
        // 0x80055728: swc1        $f6, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
            goto L_800556EC;
    }
    // 0x80055728: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8005572C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80055730: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055734: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055738: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005573C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80055740: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055744: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x80055748: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005574C: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x80055750: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80055754: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80055758: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8005575C: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80055760: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80055764: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80055768: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005576C: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x80055770: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80055774: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80055778: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x8005577C: nop

    // 0x80055780: negu        $t5, $t9
    ctx->r13 = SUB32(0, ctx->r25);
    // 0x80055784: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x80055788: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x8005578C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80055790: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80055794: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x80055798: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005579C: nop

    // 0x800557A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800557A4: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800557A8: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800557AC: nop

    // 0x800557B0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800557B4: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x800557B8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800557BC: nop

    // 0x800557C0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800557C4: jal         0x8006FE74
    // 0x800557C8: swc1        $f8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_12;
    // 0x800557C8: swc1        $f8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f8.u32l;
    after_12:
    // 0x800557CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800557D0: addiu       $t0, $sp, 0x11C
    ctx->r8 = ADD32(ctx->r29, 0X11C);
    // 0x800557D4: addiu       $t1, $sp, 0x108
    ctx->r9 = ADD32(ctx->r29, 0X108);
    // 0x800557D8: addiu       $v1, $sp, 0xF4
    ctx->r3 = ADD32(ctx->r29, 0XF4);
L_800557DC:
    // 0x800557DC: lw          $a1, 0xD8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD8);
    // 0x800557E0: lw          $a2, 0xDC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC);
    // 0x800557E4: lw          $a3, 0xE0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE0);
    // 0x800557E8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800557EC: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800557F0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800557F4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800557F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800557FC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80055800: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80055804: jal         0x8006F64C
    // 0x80055808: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtxf_transform_point(rdram, ctx);
        goto after_13;
    // 0x80055808: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_13:
    // 0x8005580C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80055810: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80055814: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80055818: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005581C: addiu       $t8, $sp, 0x104
    ctx->r24 = ADD32(ctx->r29, 0X104);
    // 0x80055820: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055824: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80055828: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005582C: bne         $v1, $t8, L_800557DC
    if (ctx->r3 != ctx->r24) {
        // 0x80055830: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_800557DC;
    }
    // 0x80055830: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80055834: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055838: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005583C: beq         $t9, $at, L_80055960
    if (ctx->r25 == ctx->r1) {
        // 0x80055840: nop
    
            goto L_80055960;
    }
    // 0x80055840: nop

    // 0x80055844: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80055848: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8005584C: lwc1        $f6, 0xF8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80055850: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80055854: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055858: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8005585C: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80055860: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x80055864: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80055868: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x8005586C: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055870: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x80055874: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80055878: swc1        $f16, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f16.u32l;
    // 0x8005587C: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80055880: jal         0x80070750
    // 0x80055884: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x80055884: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    after_14:
    // 0x80055888: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005588C: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x80055890: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x80055894: lb          $t7, 0x1D2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D2);
    // 0x80055898: sll         $v1, $t5, 16
    ctx->r3 = S32(ctx->r13 << 16);
    // 0x8005589C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800558A0: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800558A4: bne         $a1, $t7, L_800558D0
    if (ctx->r5 != ctx->r15) {
        // 0x800558A8: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800558D0;
    }
    // 0x800558A8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800558AC: sll         $v0, $t5, 16
    ctx->r2 = S32(ctx->r13 << 16);
    // 0x800558B0: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800558B4: blez        $t8, L_800558C4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800558B8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800558C4;
    }
    // 0x800558B8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800558BC: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800558C0: sh          $t9, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r25;
L_800558C4:
    // 0x800558C4: bgez        $v0, L_800558D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800558C8: addiu       $t5, $zero, -0x800
        ctx->r13 = ADD32(0, -0X800);
            goto L_800558D0;
    }
    // 0x800558C8: addiu       $t5, $zero, -0x800
    ctx->r13 = ADD32(0, -0X800);
    // 0x800558CC: sh          $t5, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r13;
L_800558D0:
    // 0x800558D0: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x800558D4: nop

    // 0x800558D8: beq         $t6, $zero, L_800558EC
    if (ctx->r14 == 0) {
        // 0x800558DC: slti        $at, $v1, 0x1F5
        ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
            goto L_800558EC;
    }
    // 0x800558DC: slti        $at, $v1, 0x1F5
    ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
    // 0x800558E0: lh          $v1, 0x19C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X19C);
    // 0x800558E4: nop

    // 0x800558E8: slti        $at, $v1, 0x1F5
    ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
L_800558EC:
    // 0x800558EC: beq         $at, $zero, L_800558FC
    if (ctx->r1 == 0) {
        // 0x800558F0: slti        $at, $v1, -0x1F4
        ctx->r1 = SIGNED(ctx->r3) < -0X1F4 ? 1 : 0;
            goto L_800558FC;
    }
    // 0x800558F0: slti        $at, $v1, -0x1F4
    ctx->r1 = SIGNED(ctx->r3) < -0X1F4 ? 1 : 0;
    // 0x800558F4: beq         $at, $zero, L_8005592C
    if (ctx->r1 == 0) {
        // 0x800558F8: lh          $t8, 0x130($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X130);
            goto L_8005592C;
    }
    // 0x800558F8: lh          $t8, 0x130($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X130);
L_800558FC:
    // 0x800558FC: lw          $t7, 0x10C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10C);
    // 0x80055900: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x80055904: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055908: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x8005590C: mflo        $t8
    ctx->r24 = lo;
    // 0x80055910: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80055914: sw          $t9, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r25;
    // 0x80055918: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005591C: mflo        $t6
    ctx->r14 = lo;
    // 0x80055920: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80055924: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
    // 0x80055928: lh          $t8, 0x130($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X130);
L_8005592C:
    // 0x8005592C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x80055930: beq         $t8, $zero, L_8005593C
    if (ctx->r24 == 0) {
        // 0x80055934: sll         $t5, $t9, 18
        ctx->r13 = S32(ctx->r25 << 18);
            goto L_8005593C;
    }
    // 0x80055934: sll         $t5, $t9, 18
    ctx->r13 = S32(ctx->r25 << 18);
    // 0x80055938: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
L_8005593C:
    // 0x8005593C: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x80055940: sra         $t8, $v1, 2
    ctx->r24 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80055944: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80055948: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x8005594C: lh          $t6, 0x1A2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A2);
    // 0x80055950: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x80055954: nop

    // 0x80055958: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8005595C: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
L_80055960:
    // 0x80055960: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80055964: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80055968: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8005596C: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80055970: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80055974: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80055978: swc1        $f12, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f12.u32l;
    // 0x8005597C: jal         0x80070750
    // 0x80055980: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_15;
    // 0x80055980: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x80055984: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x80055988: nop

    // 0x8005598C: bne         $t8, $zero, L_800559A4
    if (ctx->r24 != 0) {
        // 0x80055990: nop
    
            goto L_800559A4;
    }
    // 0x80055990: nop

    // 0x80055994: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x80055998: addiu       $t6, $v0, -0x4000
    ctx->r14 = ADD32(ctx->r2, -0X4000);
    // 0x8005599C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800559A0: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
L_800559A4:
    // 0x800559A4: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800559A8: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800559AC: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800559B0: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800559B4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800559B8: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800559BC: swc1        $f12, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f12.u32l;
    // 0x800559C0: jal         0x80070750
    // 0x800559C4: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x800559C4: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x800559C8: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x800559CC: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x800559D0: bne         $t8, $zero, L_800559E8
    if (ctx->r24 != 0) {
        // 0x800559D4: nop
    
            goto L_800559E8;
    }
    // 0x800559D4: nop

    // 0x800559D8: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x800559DC: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x800559E0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800559E4: sh          $t8, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r24;
L_800559E8:
    // 0x800559E8: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x800559EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800559F0: beq         $v0, $at, L_80055A70
    if (ctx->r2 == ctx->r1) {
        // 0x800559F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055A70;
    }
    // 0x800559F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800559F8: beq         $v0, $at, L_80055A70
    if (ctx->r2 == ctx->r1) {
        // 0x800559FC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80055A70;
    }
    // 0x800559FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055A00: beq         $v0, $at, L_80055A70
    if (ctx->r2 == ctx->r1) {
        // 0x80055A04: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80055A70;
    }
    // 0x80055A04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055A08: beq         $v0, $at, L_80055A74
    if (ctx->r2 == ctx->r1) {
        // 0x80055A0C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055A74;
    }
    // 0x80055A0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055A10: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055A14: addiu       $t9, $zero, 0x3400
    ctx->r25 = ADD32(0, 0X3400);
    // 0x80055A18: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055A1C: bne         $at, $zero, L_80055A30
    if (ctx->r1 != 0) {
        // 0x80055A20: addiu       $t6, $zero, -0x3400
        ctx->r14 = ADD32(0, -0X3400);
            goto L_80055A30;
    }
    // 0x80055A20: addiu       $t6, $zero, -0x3400
    ctx->r14 = ADD32(0, -0X3400);
    // 0x80055A24: sh          $t9, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r25;
    // 0x80055A28: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055A2C: nop

L_80055A30:
    // 0x80055A30: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055A34: beq         $at, $zero, L_80055A40
    if (ctx->r1 == 0) {
        // 0x80055A38: addiu       $t5, $zero, 0x3400
        ctx->r13 = ADD32(0, 0X3400);
            goto L_80055A40;
    }
    // 0x80055A38: addiu       $t5, $zero, 0x3400
    ctx->r13 = ADD32(0, 0X3400);
    // 0x80055A3C: sh          $t6, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r14;
L_80055A40:
    // 0x80055A40: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80055A44: addiu       $t7, $zero, -0x3400
    ctx->r15 = ADD32(0, -0X3400);
    // 0x80055A48: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055A4C: bne         $at, $zero, L_80055A64
    if (ctx->r1 != 0) {
        // 0x80055A50: slti        $at, $v0, -0x3400
        ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
            goto L_80055A64;
    }
    // 0x80055A50: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055A54: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x80055A58: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80055A5C: nop

    // 0x80055A60: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
L_80055A64:
    // 0x80055A64: beq         $at, $zero, L_80055A74
    if (ctx->r1 == 0) {
        // 0x80055A68: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055A74;
    }
    // 0x80055A68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055A6C: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
L_80055A70:
    // 0x80055A70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80055A74:
    // 0x80055A74: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80055A78: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80055A7C: jr          $ra
    // 0x80055A80: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    return;
    // 0x80055A80: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
;}
RECOMP_FUNC void alCSPGetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C79A4: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C79A8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C79AC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C79B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C79B4: jr          $ra
    // 0x800C79B8: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
    return;
    // 0x800C79B8: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
;}
RECOMP_FUNC void sndp_stop_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000499C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049A0: jal         0x800048D8
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800049A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049B0: jr          $ra
    // 0x800049B4: nop

    return;
    // 0x800049B4: nop

;}
RECOMP_FUNC void obj_init_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C1E0: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x8003C1E4: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003C1E8: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003C1EC: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8003C1F0: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8003C1F4: lb          $t9, 0xE($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XE);
    // 0x8003C1F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003C1FC: sb          $t9, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r25;
    // 0x8003C200: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x8003C204: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C208: sb          $t0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r8;
    // 0x8003C20C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003C210: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8003C214: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003C218: lbu         $t1, 0xA($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XA);
    // 0x8003C21C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003C220: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
    // 0x8003C224: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x8003C228: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C22C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x8003C230: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x8003C234: nop

    // 0x8003C238: andi        $t4, $t3, 0x3F
    ctx->r12 = ctx->r11 & 0X3F;
    // 0x8003C23C: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003C240: sw          $t5, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r13;
    // 0x8003C244: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x8003C248: nop

    // 0x8003C24C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003C250: nop

    // 0x8003C254: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C258: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C25C: nop

    // 0x8003C260: bc1f        L_8003C270
    if (!c1cs) {
        // 0x8003C264: nop
    
            goto L_8003C270;
    }
    // 0x8003C264: nop

    // 0x8003C268: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C26C: nop

L_8003C270:
    // 0x8003C270: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003C274: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003C278: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C27C: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8003C280: addiu       $t9, $zero, 0x21
    ctx->r25 = ADD32(0, 0X21);
    // 0x8003C284: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003C288: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8003C28C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003C290: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8003C294: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    // 0x8003C298: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C29C: nop

    // 0x8003C2A0: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
    // 0x8003C2A4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2A8: nop

    // 0x8003C2AC: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    // 0x8003C2B0: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2B4: nop

    // 0x8003C2B8: sb          $zero, 0x12($t5)
    MEM_B(0X12, ctx->r13) = 0;
    // 0x8003C2BC: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8003C2C0: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003C2C4: lb          $t8, 0x55($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X55);
    // 0x8003C2C8: nop

    // 0x8003C2CC: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003C2D0: bne         $at, $zero, L_8003C2DC
    if (ctx->r1 != 0) {
        // 0x8003C2D4: nop
    
            goto L_8003C2DC;
    }
    // 0x8003C2D4: nop

    // 0x8003C2D8: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003C2DC:
    // 0x8003C2DC: jr          $ra
    // 0x8003C2E0: nop

    return;
    // 0x8003C2E0: nop

;}
RECOMP_FUNC void get_eeprom_settings_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA70: jr          $ra
    // 0x8009EA74: addiu       $v0, $v0, 0x6448
    ctx->r2 = ADD32(ctx->r2, 0X6448);
    return;
    // 0x8009EA74: addiu       $v0, $v0, 0x6448
    ctx->r2 = ADD32(ctx->r2, 0X6448);
;}
RECOMP_FUNC void timetrial_swap_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059984: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059988: lb          $t6, -0x2A64($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A64);
    // 0x8005998C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059990: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80059994: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80059998: sb          $t8, -0x2A63($at)
    MEM_B(-0X2A63, ctx->r1) = ctx->r24;
    // 0x8005999C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599A0: jr          $ra
    // 0x800599A4: sh          $a0, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r4;
    return;
    // 0x800599A4: sh          $a0, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800647D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800647D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800647D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800647DC: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800647E0: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800647E4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800647E8: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800647EC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800647F0: lui         $t1, 0xB00
    ctx->r9 = S32(0XB00 << 16);
    // 0x800647F4: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x800647F8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800647FC: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x80064800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064804: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80064808: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006480C: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80064810: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80064814: jal         0x800C8CF0
    // 0x80064818: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064818: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8006481C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80064820: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80064824: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x80064828: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8006482C: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80064830: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80064834: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80064838: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8006483C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80064840: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80064844: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80064848: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8006484C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80064850: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80064854: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80064858: jal         0x800C8CF0
    // 0x8006485C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8006485C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80064860: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80064864: nop

    // 0x80064868: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8006486C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80064870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064878: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8006487C: jr          $ra
    // 0x80064880: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064880: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void music_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C98: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80000C9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CA0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80000CA4: sw          $zero, 0x5D38($at)
    MEM_W(0X5D38, ctx->r1) = 0;
    // 0x80000CA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000CAC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80000CB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CB4: jr          $ra
    // 0x80000CB8: sw          $t7, 0x5D3C($at)
    MEM_W(0X5D3C, ctx->r1) = ctx->r15;
    return;
    // 0x80000CB8: sw          $t7, 0x5D3C($at)
    MEM_W(0X5D3C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void dummy_80079810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079810: jr          $ra
    // 0x80079814: nop

    return;
    // 0x80079814: nop

;}
RECOMP_FUNC void set_textbox_display_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3144: jr          $ra
    // 0x800C3148: sh          $a0, 0x3674($at)
    MEM_H(0X3674, ctx->r1) = ctx->r4;
    return;
    // 0x800C3148: sh          $a0, 0x3674($at)
    MEM_H(0X3674, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void align16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071850: andi        $v1, $a0, 0xF
    ctx->r3 = ctx->r4 & 0XF;
    // 0x80071854: blez        $v1, L_80071864
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071858: nop
    
            goto L_80071864;
    }
    // 0x80071858: nop

    // 0x8007185C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071860: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80071864:
    // 0x80071864: jr          $ra
    // 0x80071868: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071868: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800113BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113C0: lw          $v0, -0x5244($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5244);
    // 0x800113C4: jr          $ra
    // 0x800113C8: nop

    return;
    // 0x800113C8: nop

;}
RECOMP_FUNC void menu_trophy_race_rankings_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098A24: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80098A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098A2C: jal         0x8006EA90
    // 0x80098A30: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098A30: nop

    after_0:
    // 0x80098A34: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80098A38: jal         0x8001E29C
    // 0x80098A3C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80098A3C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80098A40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098A44: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x80098A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098A4C: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80098A50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098A54: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80098A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098A5C: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x80098A60: jal         0x8009BE5C
    // 0x80098A64: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    reset_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x80098A64: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80098A68: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098A6C: jal         0x8009C674
    // 0x80098A70: addiu       $a0, $a0, 0x1024
    ctx->r4 = ADD32(ctx->r4, 0X1024);
    menu_assetgroup_load(rdram, ctx);
        goto after_3;
    // 0x80098A70: addiu       $a0, $a0, 0x1024
    ctx->r4 = ADD32(ctx->r4, 0X1024);
    after_3:
    // 0x80098A74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098A78: jal         0x8009C8A4
    // 0x80098A7C: addiu       $a0, $a0, 0x1040
    ctx->r4 = ADD32(ctx->r4, 0X1040);
    menu_imagegroup_load(rdram, ctx);
        goto after_4;
    // 0x80098A7C: addiu       $a0, $a0, 0x1040
    ctx->r4 = ADD32(ctx->r4, 0X1040);
    after_4:
    // 0x80098A80: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098A84: addiu       $v1, $v1, 0xFEC
    ctx->r3 = ADD32(ctx->r3, 0XFEC);
    // 0x80098A88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80098A8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098A90: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098A94: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80098A98: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80098A9C: addiu       $a1, $a1, 0xFE8
    ctx->r5 = ADD32(ctx->r5, 0XFE8);
    // 0x80098AA0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80098AA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098AA8: sw          $v0, 0xFF0($at)
    MEM_W(0XFF0, ctx->r1) = ctx->r2;
    // 0x80098AAC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_80098AB0:
    // 0x80098AB0: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80098AB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80098AB8: beq         $at, $zero, L_80098AE8
    if (ctx->r1 == 0) {
        // 0x80098ABC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80098AE8;
    }
    // 0x80098ABC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80098AC0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80098AC4: nop

    // 0x80098AC8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80098ACC: mflo        $t8
    ctx->r24 = lo;
    // 0x80098AD0: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80098AD4: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80098AD8: lb          $t6, -0x6($t5)
    ctx->r14 = MEM_B(ctx->r13, -0X6);
    // 0x80098ADC: nop

    // 0x80098AE0: beq         $a0, $t6, L_80098AB0
    if (ctx->r4 == ctx->r14) {
        // 0x80098AE4: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80098AB0;
    }
    // 0x80098AE4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_80098AE8:
    // 0x80098AE8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80098AEC: beq         $at, $zero, L_80098B24
    if (ctx->r1 == 0) {
        // 0x80098AF0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80098B24;
    }
    // 0x80098AF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80098AF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80098AF8: lw          $v0, -0xB60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB60);
    // 0x80098AFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80098B00: lw          $t7, 0x188($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X188);
    // 0x80098B04: addiu       $v1, $v1, 0x6BF0
    ctx->r3 = ADD32(ctx->r3, 0X6BF0);
    // 0x80098B08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80098B0C: lw          $t8, 0x204($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X204);
    // 0x80098B10: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80098B14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098B18: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80098B1C: b           L_80098B44
    // 0x80098B20: sw          $t9, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r25;
        goto L_80098B44;
    // 0x80098B20: sw          $t9, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r25;
L_80098B24:
    // 0x80098B24: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80098B28: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80098B2C: addiu       $v1, $v1, 0x6BF0
    ctx->r3 = ADD32(ctx->r3, 0X6BF0);
    // 0x80098B30: lw          $t6, 0x244($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X244);
    // 0x80098B34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80098B38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098B3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80098B40: sw          $t7, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r15;
L_80098B44:
    // 0x80098B44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098B48: sw          $zero, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = 0;
    // 0x80098B4C: jal         0x80094604
    // 0x80098B50: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    menu_racer_portraits(rdram, ctx);
        goto after_5;
    // 0x80098B50: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_5:
    // 0x80098B54: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098B58: addiu       $t3, $t3, -0xB44
    ctx->r11 = ADD32(ctx->r11, -0XB44);
    // 0x80098B5C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80098B60: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80098B64: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80098B68: bne         $at, $zero, L_80098B7C
    if (ctx->r1 != 0) {
        // 0x80098B6C: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80098B7C;
    }
    // 0x80098B6C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80098B70: addiu       $t4, $t4, 0xFE4
    ctx->r12 = ADD32(ctx->r12, 0XFE4);
    // 0x80098B74: b           L_80098BD4
    // 0x80098B78: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
        goto L_80098BD4;
    // 0x80098B78: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80098B7C:
    // 0x80098B7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80098B80: beq         $v0, $at, L_80098BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80098B84: nop
    
            goto L_80098BA0;
    }
    // 0x80098B84: nop

    // 0x80098B88: jal         0x8009EC80
    // 0x80098B8C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    is_in_two_player_adventure(rdram, ctx);
        goto after_6;
    // 0x80098B8C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_6:
    // 0x80098B90: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80098B94: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098B98: beq         $v0, $zero, L_80098BC4
    if (ctx->r2 == 0) {
        // 0x80098B9C: addiu       $t3, $t3, -0xB44
        ctx->r11 = ADD32(ctx->r11, -0XB44);
            goto L_80098BC4;
    }
    // 0x80098B9C: addiu       $t3, $t3, -0xB44
    ctx->r11 = ADD32(ctx->r11, -0XB44);
L_80098BA0:
    // 0x80098BA0: jal         0x8009C440
    // 0x80098BA4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    get_multiplayer_racer_count(rdram, ctx);
        goto after_7;
    // 0x80098BA4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_7:
    // 0x80098BA8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80098BAC: addiu       $t4, $t4, 0xFE4
    ctx->r12 = ADD32(ctx->r12, 0XFE4);
    // 0x80098BB0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80098BB4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098BB8: addiu       $t3, $t3, -0xB44
    ctx->r11 = ADD32(ctx->r11, -0XB44);
    // 0x80098BBC: b           L_80098BD4
    // 0x80098BC0: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
        goto L_80098BD4;
    // 0x80098BC0: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80098BC4:
    // 0x80098BC4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80098BC8: addiu       $t4, $t4, 0xFE4
    ctx->r12 = ADD32(ctx->r12, 0XFE4);
    // 0x80098BCC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80098BD0: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80098BD4:
    // 0x80098BD4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80098BD8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80098BDC: blez        $a1, L_80098C50
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80098BE0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80098C50;
    }
    // 0x80098BE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098BE4: addiu       $a0, $a0, 0x6428
    ctx->r4 = ADD32(ctx->r4, 0X6428);
    // 0x80098BE8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80098BEC:
    // 0x80098BEC: blez        $a1, L_80098C3C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80098BF0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80098C3C;
    }
    // 0x80098BF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80098BF4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80098BF8:
    // 0x80098BF8: lb          $t9, 0x5A($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X5A);
    // 0x80098BFC: addu        $t5, $a0, $t0
    ctx->r13 = ADD32(ctx->r4, ctx->r8);
    // 0x80098C00: bne         $t0, $t9, L_80098C2C
    if (ctx->r8 != ctx->r25) {
        // 0x80098C04: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80098C2C;
    }
    // 0x80098C04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80098C08: sb          $a3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r7;
    // 0x80098C0C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80098C10: addiu       $t6, $t6, 0x6418
    ctx->r14 = ADD32(ctx->r14, 0X6418);
    // 0x80098C14: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80098C18: beq         $at, $zero, L_80098C28
    if (ctx->r1 == 0) {
        // 0x80098C1C: addu        $v0, $t0, $t6
        ctx->r2 = ADD32(ctx->r8, ctx->r14);
            goto L_80098C28;
    }
    // 0x80098C1C: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80098C20: b           L_80098C2C
    // 0x80098C24: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80098C2C;
    // 0x80098C24: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80098C28:
    // 0x80098C28: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80098C2C:
    // 0x80098C2C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80098C30: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80098C34: bne         $at, $zero, L_80098BF8
    if (ctx->r1 != 0) {
        // 0x80098C38: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80098BF8;
    }
    // 0x80098C38: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_80098C3C:
    // 0x80098C3C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80098C40: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80098C44: bne         $at, $zero, L_80098BEC
    if (ctx->r1 != 0) {
        // 0x80098C48: nop
    
            goto L_80098BEC;
    }
    // 0x80098C48: nop

    // 0x80098C4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80098C50:
    // 0x80098C50: blez        $a1, L_80098C98
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80098C54: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80098C98;
    }
    // 0x80098C54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80098C58: addiu       $v0, $t8, 0x63F8
    ctx->r2 = ADD32(ctx->r24, 0X63F8);
    // 0x80098C5C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80098C60: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098C64: addiu       $a0, $a0, 0x1004
    ctx->r4 = ADD32(ctx->r4, 0X1004);
    // 0x80098C68: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80098C6C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80098C70:
    // 0x80098C70: lb          $t5, 0x5A($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X5A);
    // 0x80098C74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80098C78: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80098C7C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80098C80: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80098C84: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80098C88: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80098C8C: bne         $at, $zero, L_80098C70
    if (ctx->r1 != 0) {
        // 0x80098C90: sw          $t9, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r25;
            goto L_80098C70;
    }
    // 0x80098C90: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x80098C94: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80098C98:
    // 0x80098C98: blez        $a1, L_80098CE4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80098C9C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80098CE4;
    }
    // 0x80098C9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80098CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098CA4: addiu       $a0, $a0, 0x6430
    ctx->r4 = ADD32(ctx->r4, 0X6430);
    // 0x80098CA8: addiu       $v0, $v0, 0x63F8
    ctx->r2 = ADD32(ctx->r2, 0X63F8);
    // 0x80098CAC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80098CB0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
L_80098CB4:
    // 0x80098CB4: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x80098CB8: lw          $t5, 0x54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X54);
    // 0x80098CBC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80098CC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80098CC4: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80098CC8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x80098CCC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80098CD0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80098CD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80098CD8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80098CDC: bne         $at, $zero, L_80098CB4
    if (ctx->r1 != 0) {
        // 0x80098CE0: sw          $t6, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r14;
            goto L_80098CB4;
    }
    // 0x80098CE0: sw          $t6, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r14;
L_80098CE4:
    // 0x80098CE4: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x80098CE8: blez        $t0, L_80098DE0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80098CEC: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80098DE0;
    }
    // 0x80098CEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80098CF0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80098CF4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80098CF8: addiu       $t1, $t1, 0x6430
    ctx->r9 = ADD32(ctx->r9, 0X6430);
L_80098CFC:
    // 0x80098CFC: blez        $t0, L_80098DCC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80098D00: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80098DCC;
    }
    // 0x80098D00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80098D04: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x80098D08: beq         $v0, $zero, L_80098D44
    if (ctx->r2 == 0) {
        // 0x80098D0C: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80098D44;
    }
    // 0x80098D0C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80098D10: beq         $at, $zero, L_80098D40
    if (ctx->r1 == 0) {
        // 0x80098D14: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80098D40;
    }
    // 0x80098D14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80098D18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80098D1C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80098D20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80098D24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80098D28: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80098D2C: lbu         $t7, 0x6431($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6431);
    // 0x80098D30: lbu         $v0, 0x6430($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6430);
    // 0x80098D34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098D38: sb          $t7, 0x6430($at)
    MEM_B(0X6430, ctx->r1) = ctx->r15;
    // 0x80098D3C: sb          $v0, 0x6431($at)
    MEM_B(0X6431, ctx->r1) = ctx->r2;
L_80098D40:
    // 0x80098D40: beq         $a3, $t0, L_80098DCC
    if (ctx->r7 == ctx->r8) {
        // 0x80098D44: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_80098DCC;
    }
L_80098D44:
    // 0x80098D44: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80098D48: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x80098D4C: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x80098D50: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80098D54: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_80098D58:
    // 0x80098D58: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80098D5C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80098D60: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x80098D64: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80098D68: beq         $at, $zero, L_80098D8C
    if (ctx->r1 == 0) {
        // 0x80098D6C: nop
    
            goto L_80098D8C;
    }
    // 0x80098D6C: nop

    // 0x80098D70: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80098D74: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x80098D78: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80098D7C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80098D80: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80098D84: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x80098D88: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_80098D8C:
    // 0x80098D8C: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x80098D90: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x80098D94: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80098D98: beq         $at, $zero, L_80098DB8
    if (ctx->r1 == 0) {
        // 0x80098D9C: nop
    
            goto L_80098DB8;
    }
    // 0x80098D9C: nop

    // 0x80098DA0: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80098DA4: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80098DA8: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80098DAC: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80098DB0: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80098DB4: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
L_80098DB8:
    // 0x80098DB8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80098DBC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80098DC0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80098DC4: bne         $a3, $t0, L_80098D58
    if (ctx->r7 != ctx->r8) {
        // 0x80098DC8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80098D58;
    }
    // 0x80098DC8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80098DCC:
    // 0x80098DCC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80098DD0: bgtz        $t0, L_80098CFC
    if (SIGNED(ctx->r8) > 0) {
        // 0x80098DD4: nop
    
            goto L_80098CFC;
    }
    // 0x80098DD4: nop

    // 0x80098DD8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80098DDC: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
L_80098DE0:
    // 0x80098DE0: jal         0x8009EC80
    // 0x80098DE4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x80098DE4: nop

    after_8:
    // 0x80098DE8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098DEC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80098DF0: addiu       $t4, $t4, 0xFE4
    ctx->r12 = ADD32(ctx->r12, 0XFE4);
    // 0x80098DF4: addiu       $t3, $t3, -0xB44
    ctx->r11 = ADD32(ctx->r11, -0XB44);
    // 0x80098DF8: beq         $v0, $zero, L_80098E08
    if (ctx->r2 == 0) {
        // 0x80098DFC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80098E08;
    }
    // 0x80098DFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80098E00: b           L_80098E10
    // 0x80098E04: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80098E10;
    // 0x80098E04: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80098E08:
    // 0x80098E08: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80098E0C: nop

L_80098E10:
    // 0x80098E10: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80098E14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098E18: blez        $a1, L_80098E5C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80098E1C: addiu       $a0, $a0, 0x6430
        ctx->r4 = ADD32(ctx->r4, 0X6430);
            goto L_80098E5C;
    }
    // 0x80098E1C: addiu       $a0, $a0, 0x6430
    ctx->r4 = ADD32(ctx->r4, 0X6430);
    // 0x80098E20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80098E24: addiu       $v0, $t7, 0x6420
    ctx->r2 = ADD32(ctx->r15, 0X6420);
    // 0x80098E28: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
L_80098E2C:
    // 0x80098E2C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80098E30: nop

    // 0x80098E34: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80098E38: beq         $at, $zero, L_80098E48
    if (ctx->r1 == 0) {
        // 0x80098E3C: nop
    
            goto L_80098E48;
    }
    // 0x80098E3C: nop

    // 0x80098E40: b           L_80098E4C
    // 0x80098E44: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80098E4C;
    // 0x80098E44: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80098E48:
    // 0x80098E48: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80098E4C:
    // 0x80098E4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80098E50: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80098E54: bne         $at, $zero, L_80098E2C
    if (ctx->r1 != 0) {
        // 0x80098E58: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80098E2C;
    }
    // 0x80098E58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80098E5C:
    // 0x80098E5C: jal         0x800C4170
    // 0x80098E60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_9;
    // 0x80098E60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x80098E64: jal         0x80000BE0
    // 0x80098E68: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_10;
    // 0x80098E68: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_10:
    // 0x80098E6C: jal         0x80000B34
    // 0x80098E70: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_11;
    // 0x80098E70: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_11:
    // 0x80098E74: jal         0x80000C98
    // 0x80098E78: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_12;
    // 0x80098E78: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_12:
    // 0x80098E7C: jal         0x80098774
    // 0x80098E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80098774(rdram, ctx);
        goto after_13;
    // 0x80098E80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80098E84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80098E88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80098E8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098E90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80098E94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80098E98: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x80098E9C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80098EA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80098EA4: jal         0x80081E54
    // 0x80098EA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    postrace_offsets(rdram, ctx);
        goto after_14;
    // 0x80098EA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_14:
    // 0x80098EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098EB0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80098EB4: jr          $ra
    // 0x80098EB8: nop

    return;
    // 0x80098EB8: nop

;}
RECOMP_FUNC void obj_init_lighthouse_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003572C: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035730: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035734: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035738: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003573C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035740: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035744: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035748: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003574C: nop

    // 0x80035750: bc1f        L_80035760
    if (!c1cs) {
        // 0x80035754: nop
    
            goto L_80035760;
    }
    // 0x80035754: nop

    // 0x80035758: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003575C: nop

L_80035760:
    // 0x80035760: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035764: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035768: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x8003576C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035770: nop

    // 0x80035774: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035778: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8003577C: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x80035780: nop

    // 0x80035784: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035788: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x8003578C: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x80035790: nop

    // 0x80035794: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035798: bne         $at, $zero, L_800357A4
    if (ctx->r1 != 0) {
        // 0x8003579C: nop
    
            goto L_800357A4;
    }
    // 0x8003579C: nop

    // 0x800357A0: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_800357A4:
    // 0x800357A4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x800357A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800357AC: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x800357B0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800357B4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800357B8: sb          $t5, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r13;
    // 0x800357BC: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800357C0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800357C4: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x800357C8: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800357CC: jr          $ra
    // 0x800357D0: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    return;
    // 0x800357D0: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
;}
RECOMP_FUNC void rankings_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009960C: jal         0x8009C4A8
    // 0x80099610: addiu       $a0, $a0, 0x1024
    ctx->r4 = ADD32(ctx->r4, 0X1024);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80099610: addiu       $a0, $a0, 0x1024
    ctx->r4 = ADD32(ctx->r4, 0X1024);
    after_0:
    // 0x80099614: jal         0x800C422C
    // 0x80099618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x80099618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8009961C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099624: jr          $ra
    // 0x80099628: nop

    return;
    // 0x80099628: nop

;}
RECOMP_FUNC void render_epc_lock_up_display(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7810: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B7814: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B7818: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B781C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B7820: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B7824: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B7828: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B782C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B7830: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B7834: addiu       $t7, $t7, 0x302C
    ctx->r15 = ADD32(ctx->r15, 0X302C);
    // 0x800B7838: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800B783C: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x800B7840: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800B7844: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800B7848: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800B784C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B7850: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800B7854: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B7858: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800B785C: jal         0x800B635C
    // 0x800B7860: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x800B7860: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    after_0:
    // 0x800B7864: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7868: addiu       $v1, $v1, 0x3024
    ctx->r3 = ADD32(ctx->r3, 0X3024);
    // 0x800B786C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B7870: nop

    // 0x800B7874: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800B7878: beq         $at, $zero, L_800B7CE8
    if (ctx->r1 == 0) {
        // 0x800B787C: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800B7CE8;
    }
    // 0x800B787C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800B7880: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B7884: addu        $at, $at, $t1
    gpr jr_addend_800B7890 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800B7888: lw          $t1, -0x6EC4($at)
    ctx->r9 = ADD32(ctx->r1, -0X6EC4);
    // 0x800B788C: nop

    // 0x800B7890: jr          $t1
    // 0x800B7894: nop

    switch (jr_addend_800B7890 >> 2) {
        case 0: goto L_800B7898; break;
        case 1: goto L_800B7C18; break;
        case 2: goto L_800B7C18; break;
        case 3: goto L_800B7C18; break;
        case 4: goto L_800B7C70; break;
        case 5: goto L_800B7CE4; break;
        default: switch_error(__func__, 0x800B7890, 0x800E913C);
    }
    // 0x800B7894: nop

L_800B7898:
    // 0x800B7898: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B789C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B78A0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B78A4: addiu       $v1, $v1, -0x6800
    ctx->r3 = ADD32(ctx->r3, -0X6800);
    // 0x800B78A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B78AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B78B0: lwc1        $f4, 0x130($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X130);
    // 0x800B78B4: lwc1        $f8, 0x134($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X134);
    // 0x800B78B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B78BC: lwc1        $f16, 0x138($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X138);
    // 0x800B78C0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B78C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B78C8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800B78CC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B78D0: lw          $t6, 0x120($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X120);
    // 0x800B78D4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B78D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B78DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B78E0: addiu       $v0, $v0, -0x6050
    ctx->r2 = ADD32(ctx->r2, -0X6050);
    // 0x800B78E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B78E8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B78EC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B78F0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800B78F4: nop

    // 0x800B78F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B78FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B7900: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B7904: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7908: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B790C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B7910: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B7914: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B7918: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B791C: bne         $t6, $at, L_800B79DC
    if (ctx->r14 != ctx->r1) {
        // 0x800B7920: sw          $t8, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r24;
            goto L_800B79DC;
    }
    // 0x800B7920: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800B7924: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7928: lw          $a1, -0x66E4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66E4);
    // 0x800B792C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7930: jal         0x800B5EDC
    // 0x800B7934: addiu       $a0, $a0, -0x70E8
    ctx->r4 = ADD32(ctx->r4, -0X70E8);
    render_printf(rdram, ctx);
        goto after_1;
    // 0x800B7934: addiu       $a0, $a0, -0x70E8
    ctx->r4 = ADD32(ctx->r4, -0X70E8);
    after_1:
    // 0x800B7938: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B793C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7940: lw          $a2, -0x67BC($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X67BC);
    // 0x800B7944: lw          $a1, -0x67C4($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X67C4);
    // 0x800B7948: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B794C: jal         0x800B5EDC
    // 0x800B7950: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    render_printf(rdram, ctx);
        goto after_2;
    // 0x800B7950: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    after_2:
    // 0x800B7954: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7958: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B795C: addiu       $s5, $s5, -0x70BC
    ctx->r21 = ADD32(ctx->r21, -0X70BC);
    // 0x800B7960: addiu       $s0, $s0, -0x6050
    ctx->r16 = ADD32(ctx->r16, -0X6050);
    // 0x800B7964: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7968: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B796C:
    // 0x800B796C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7970: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800B7974: beq         $s4, $a2, L_800B79A8
    if (ctx->r20 == ctx->r6) {
        // 0x800B7978: nop
    
            goto L_800B79A8;
    }
    // 0x800B7978: nop

    // 0x800B797C: bne         $s3, $zero, L_800B7998
    if (ctx->r19 != 0) {
        // 0x800B7980: addu        $s1, $s2, $t7
        ctx->r17 = ADD32(ctx->r18, ctx->r15);
            goto L_800B7998;
    }
    // 0x800B7980: addu        $s1, $s2, $t7
    ctx->r17 = ADD32(ctx->r18, ctx->r15);
    // 0x800B7984: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7988: jal         0x800B5EDC
    // 0x800B798C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_3;
    // 0x800B798C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x800B7990: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7994: nop

L_800B7998:
    // 0x800B7998: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B799C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B79A0: jal         0x800B5EDC
    // 0x800B79A4: addiu       $a0, $a0, -0x70B0
    ctx->r4 = ADD32(ctx->r4, -0X70B0);
    render_printf(rdram, ctx);
        goto after_4;
    // 0x800B79A4: addiu       $a0, $a0, -0x70B0
    ctx->r4 = ADD32(ctx->r4, -0X70B0);
    after_4:
L_800B79A8:
    // 0x800B79A8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B79AC: addiu       $t4, $t4, -0x6044
    ctx->r12 = ADD32(ctx->r12, -0X6044);
    // 0x800B79B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B79B4: bne         $s0, $t4, L_800B796C
    if (ctx->r16 != ctx->r12) {
        // 0x800B79B8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B796C;
    }
    // 0x800B79B8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B79BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B79C0: jal         0x800B5EDC
    // 0x800B79C4: addiu       $a0, $a0, -0x70A8
    ctx->r4 = ADD32(ctx->r4, -0X70A8);
    render_printf(rdram, ctx);
        goto after_5;
    // 0x800B79C4: addiu       $a0, $a0, -0x70A8
    ctx->r4 = ADD32(ctx->r4, -0X70A8);
    after_5:
    // 0x800B79C8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B79CC: jal         0x800B5EDC
    // 0x800B79D0: addiu       $a0, $a0, -0x70A4
    ctx->r4 = ADD32(ctx->r4, -0X70A4);
    render_printf(rdram, ctx);
        goto after_6;
    // 0x800B79D0: addiu       $a0, $a0, -0x70A4
    ctx->r4 = ADD32(ctx->r4, -0X70A4);
    after_6:
    // 0x800B79D4: b           L_800B7CEC
    // 0x800B79D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B7CEC;
    // 0x800B79D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B79DC:
    // 0x800B79DC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B79E0: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x800B79E4: jal         0x800B5EDC
    // 0x800B79E8: addiu       $a0, $a0, -0x7094
    ctx->r4 = ADD32(ctx->r4, -0X7094);
    render_printf(rdram, ctx);
        goto after_7;
    // 0x800B79E8: addiu       $a0, $a0, -0x7094
    ctx->r4 = ADD32(ctx->r4, -0X7094);
    after_7:
    // 0x800B79EC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B79F0: lw          $a1, -0x66E4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66E4);
    // 0x800B79F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B79F8: jal         0x800B5EDC
    // 0x800B79FC: addiu       $a0, $a0, -0x707C
    ctx->r4 = ADD32(ctx->r4, -0X707C);
    render_printf(rdram, ctx);
        goto after_8;
    // 0x800B79FC: addiu       $a0, $a0, -0x707C
    ctx->r4 = ADD32(ctx->r4, -0X707C);
    after_8:
    // 0x800B7A00: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7A04: lw          $a1, -0x66E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66E0);
    // 0x800B7A08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7A0C: jal         0x800B5EDC
    // 0x800B7A10: addiu       $a0, $a0, -0x706C
    ctx->r4 = ADD32(ctx->r4, -0X706C);
    render_printf(rdram, ctx);
        goto after_9;
    // 0x800B7A10: addiu       $a0, $a0, -0x706C
    ctx->r4 = ADD32(ctx->r4, -0X706C);
    after_9:
    // 0x800B7A14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7A18: lw          $a1, -0x66E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66E8);
    // 0x800B7A1C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7A20: jal         0x800B5EDC
    // 0x800B7A24: addiu       $a0, $a0, -0x705C
    ctx->r4 = ADD32(ctx->r4, -0X705C);
    render_printf(rdram, ctx);
        goto after_10;
    // 0x800B7A24: addiu       $a0, $a0, -0x705C
    ctx->r4 = ADD32(ctx->r4, -0X705C);
    after_10:
    // 0x800B7A28: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7A2C: lw          $a1, -0x66DC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X66DC);
    // 0x800B7A30: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7A34: jal         0x800B5EDC
    // 0x800B7A38: addiu       $a0, $a0, -0x704C
    ctx->r4 = ADD32(ctx->r4, -0X704C);
    render_printf(rdram, ctx);
        goto after_11;
    // 0x800B7A38: addiu       $a0, $a0, -0x704C
    ctx->r4 = ADD32(ctx->r4, -0X704C);
    after_11:
    // 0x800B7A3C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7A40: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B7A44: addiu       $s5, $s5, -0x7038
    ctx->r21 = ADD32(ctx->r21, -0X7038);
    // 0x800B7A48: addiu       $s0, $s0, -0x6050
    ctx->r16 = ADD32(ctx->r16, -0X6050);
    // 0x800B7A4C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7A50: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B7A54:
    // 0x800B7A54: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7A58: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x800B7A5C: beq         $s4, $a2, L_800B7A90
    if (ctx->r20 == ctx->r6) {
        // 0x800B7A60: nop
    
            goto L_800B7A90;
    }
    // 0x800B7A60: nop

    // 0x800B7A64: bne         $s3, $zero, L_800B7A80
    if (ctx->r19 != 0) {
        // 0x800B7A68: addu        $s1, $s2, $t5
        ctx->r17 = ADD32(ctx->r18, ctx->r13);
            goto L_800B7A80;
    }
    // 0x800B7A68: addu        $s1, $s2, $t5
    ctx->r17 = ADD32(ctx->r18, ctx->r13);
    // 0x800B7A6C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7A70: jal         0x800B5EDC
    // 0x800B7A74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x800B7A74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x800B7A78: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7A7C: nop

L_800B7A80:
    // 0x800B7A80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7A84: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B7A88: jal         0x800B5EDC
    // 0x800B7A8C: addiu       $a0, $a0, -0x702C
    ctx->r4 = ADD32(ctx->r4, -0X702C);
    render_printf(rdram, ctx);
        goto after_13;
    // 0x800B7A8C: addiu       $a0, $a0, -0x702C
    ctx->r4 = ADD32(ctx->r4, -0X702C);
    after_13:
L_800B7A90:
    // 0x800B7A90: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7A94: addiu       $t9, $t9, -0x6044
    ctx->r25 = ADD32(ctx->r25, -0X6044);
    // 0x800B7A98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7A9C: bne         $s0, $t9, L_800B7A54
    if (ctx->r16 != ctx->r25) {
        // 0x800B7AA0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B7A54;
    }
    // 0x800B7AA0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B7AA4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7AA8: jal         0x800B5EDC
    // 0x800B7AAC: addiu       $a0, $a0, -0x7024
    ctx->r4 = ADD32(ctx->r4, -0X7024);
    render_printf(rdram, ctx);
        goto after_14;
    // 0x800B7AAC: addiu       $a0, $a0, -0x7024
    ctx->r4 = ADD32(ctx->r4, -0X7024);
    after_14:
    // 0x800B7AB0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7AB4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7AB8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7ABC: lw          $a3, -0x67CC($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X67CC);
    // 0x800B7AC0: lw          $a2, -0x67D4($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X67D4);
    // 0x800B7AC4: lw          $a1, -0x67DC($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X67DC);
    // 0x800B7AC8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7ACC: jal         0x800B5EDC
    // 0x800B7AD0: addiu       $a0, $a0, -0x7020
    ctx->r4 = ADD32(ctx->r4, -0X7020);
    render_printf(rdram, ctx);
        goto after_15;
    // 0x800B7AD0: addiu       $a0, $a0, -0x7020
    ctx->r4 = ADD32(ctx->r4, -0X7020);
    after_15:
    // 0x800B7AD4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7AD8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7ADC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7AE0: lw          $a3, -0x67B4($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X67B4);
    // 0x800B7AE4: lw          $a2, -0x67BC($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X67BC);
    // 0x800B7AE8: lw          $a1, -0x67C4($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X67C4);
    // 0x800B7AEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7AF0: jal         0x800B5EDC
    // 0x800B7AF4: addiu       $a0, $a0, -0x7000
    ctx->r4 = ADD32(ctx->r4, -0X7000);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x800B7AF4: addiu       $a0, $a0, -0x7000
    ctx->r4 = ADD32(ctx->r4, -0X7000);
    after_16:
    // 0x800B7AF8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7AFC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7B00: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7B04: lw          $a3, -0x679C($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X679C);
    // 0x800B7B08: lw          $a2, -0x67A4($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X67A4);
    // 0x800B7B0C: lw          $a1, -0x67AC($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X67AC);
    // 0x800B7B10: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7B14: jal         0x800B5EDC
    // 0x800B7B18: addiu       $a0, $a0, -0x6FE0
    ctx->r4 = ADD32(ctx->r4, -0X6FE0);
    render_printf(rdram, ctx);
        goto after_17;
    // 0x800B7B18: addiu       $a0, $a0, -0x6FE0
    ctx->r4 = ADD32(ctx->r4, -0X6FE0);
    after_17:
    // 0x800B7B1C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7B20: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7B24: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7B28: lw          $a3, -0x6784($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X6784);
    // 0x800B7B2C: lw          $a2, -0x678C($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X678C);
    // 0x800B7B30: lw          $a1, -0x6794($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X6794);
    // 0x800B7B34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7B38: jal         0x800B5EDC
    // 0x800B7B3C: addiu       $a0, $a0, -0x6FC0
    ctx->r4 = ADD32(ctx->r4, -0X6FC0);
    render_printf(rdram, ctx);
        goto after_18;
    // 0x800B7B3C: addiu       $a0, $a0, -0x6FC0
    ctx->r4 = ADD32(ctx->r4, -0X6FC0);
    after_18:
    // 0x800B7B40: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7B44: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7B48: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7B4C: lw          $a3, -0x676C($t5)
    ctx->r7 = MEM_W(ctx->r13, -0X676C);
    // 0x800B7B50: lw          $a2, -0x6774($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X6774);
    // 0x800B7B54: lw          $a1, -0x677C($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X677C);
    // 0x800B7B58: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7B5C: jal         0x800B5EDC
    // 0x800B7B60: addiu       $a0, $a0, -0x6FA0
    ctx->r4 = ADD32(ctx->r4, -0X6FA0);
    render_printf(rdram, ctx);
        goto after_19;
    // 0x800B7B60: addiu       $a0, $a0, -0x6FA0
    ctx->r4 = ADD32(ctx->r4, -0X6FA0);
    after_19:
    // 0x800B7B64: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7B68: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7B6C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7B70: lw          $a3, -0x6754($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X6754);
    // 0x800B7B74: lw          $a2, -0x675C($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X675C);
    // 0x800B7B78: lw          $a1, -0x6764($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X6764);
    // 0x800B7B7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7B80: jal         0x800B5EDC
    // 0x800B7B84: addiu       $a0, $a0, -0x6F80
    ctx->r4 = ADD32(ctx->r4, -0X6F80);
    render_printf(rdram, ctx);
        goto after_20;
    // 0x800B7B84: addiu       $a0, $a0, -0x6F80
    ctx->r4 = ADD32(ctx->r4, -0X6F80);
    after_20:
    // 0x800B7B88: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7B8C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7B90: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7B94: lw          $a3, -0x673C($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X673C);
    // 0x800B7B98: lw          $a2, -0x6744($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X6744);
    // 0x800B7B9C: lw          $a1, -0x674C($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X674C);
    // 0x800B7BA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7BA4: jal         0x800B5EDC
    // 0x800B7BA8: addiu       $a0, $a0, -0x6F60
    ctx->r4 = ADD32(ctx->r4, -0X6F60);
    render_printf(rdram, ctx);
        goto after_21;
    // 0x800B7BA8: addiu       $a0, $a0, -0x6F60
    ctx->r4 = ADD32(ctx->r4, -0X6F60);
    after_21:
    // 0x800B7BAC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7BB0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7BB4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7BB8: lw          $a3, -0x6724($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X6724);
    // 0x800B7BBC: lw          $a2, -0x672C($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X672C);
    // 0x800B7BC0: lw          $a1, -0x6734($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X6734);
    // 0x800B7BC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7BC8: jal         0x800B5EDC
    // 0x800B7BCC: addiu       $a0, $a0, -0x6F40
    ctx->r4 = ADD32(ctx->r4, -0X6F40);
    render_printf(rdram, ctx);
        goto after_22;
    // 0x800B7BCC: addiu       $a0, $a0, -0x6F40
    ctx->r4 = ADD32(ctx->r4, -0X6F40);
    after_22:
    // 0x800B7BD0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7BD4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7BD8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7BDC: lw          $a3, -0x670C($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X670C);
    // 0x800B7BE0: lw          $a2, -0x6714($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X6714);
    // 0x800B7BE4: lw          $a1, -0x671C($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X671C);
    // 0x800B7BE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7BEC: jal         0x800B5EDC
    // 0x800B7BF0: addiu       $a0, $a0, -0x6F20
    ctx->r4 = ADD32(ctx->r4, -0X6F20);
    render_printf(rdram, ctx);
        goto after_23;
    // 0x800B7BF0: addiu       $a0, $a0, -0x6F20
    ctx->r4 = ADD32(ctx->r4, -0X6F20);
    after_23:
    // 0x800B7BF4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7BF8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7BFC: lw          $a2, -0x66FC($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X66FC);
    // 0x800B7C00: lw          $a1, -0x6704($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X6704);
    // 0x800B7C04: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7C08: jal         0x800B5EDC
    // 0x800B7C0C: addiu       $a0, $a0, -0x6F00
    ctx->r4 = ADD32(ctx->r4, -0X6F00);
    render_printf(rdram, ctx);
        goto after_24;
    // 0x800B7C0C: addiu       $a0, $a0, -0x6F00
    ctx->r4 = ADD32(ctx->r4, -0X6F00);
    after_24:
    // 0x800B7C10: b           L_800B7CEC
    // 0x800B7C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B7CEC;
    // 0x800B7C14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7C18:
    // 0x800B7C18: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B7C1C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B7C20: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800B7C24: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x800B7C28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7C2C: addiu       $t5, $t5, -0x6650
    ctx->r13 = ADD32(ctx->r13, -0X6650);
    // 0x800B7C30: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800B7C34: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B7C38: addiu       $s1, $s1, -0x6EE8
    ctx->r17 = ADD32(ctx->r17, -0X6EE8);
    // 0x800B7C3C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x800B7C40: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B7C44: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_800B7C48:
    // 0x800B7C48: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800B7C4C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800B7C50: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800B7C54: jal         0x800B5EDC
    // 0x800B7C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    render_printf(rdram, ctx);
        goto after_25;
    // 0x800B7C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800B7C5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B7C60: bne         $s4, $s5, L_800B7C48
    if (ctx->r20 != ctx->r21) {
        // 0x800B7C64: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B7C48;
    }
    // 0x800B7C64: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7C68: b           L_800B7CEC
    // 0x800B7C6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B7CEC;
    // 0x800B7C6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7C70:
    // 0x800B7C70: sll         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2 << 7);
    // 0x800B7C74: addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // 0x800B7C78: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7C7C: addiu       $t9, $t9, -0x6450
    ctx->r25 = ADD32(ctx->r25, -0X6450);
    // 0x800B7C80: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800B7C84: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x800B7C88: addiu       $s2, $s2, -0x6ED0
    ctx->r18 = ADD32(ctx->r18, -0X6ED0);
    // 0x800B7C8C: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7C90: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B7C94: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x800B7C98: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_800B7C9C:
    // 0x800B7C9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7CA0: jal         0x800B5EDC
    // 0x800B7CA4: addiu       $a0, $a0, -0x6ED4
    ctx->r4 = ADD32(ctx->r4, -0X6ED4);
    render_printf(rdram, ctx);
        goto after_26;
    // 0x800B7CA4: addiu       $a0, $a0, -0x6ED4
    ctx->r4 = ADD32(ctx->r4, -0X6ED4);
    after_26:
    // 0x800B7CA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B7CAC:
    // 0x800B7CAC: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x800B7CB0: jal         0x800B5EDC
    // 0x800B7CB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_27;
    // 0x800B7CB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_27:
    // 0x800B7CB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B7CBC: bne         $s0, $s3, L_800B7CAC
    if (ctx->r16 != ctx->r19) {
        // 0x800B7CC0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800B7CAC;
    }
    // 0x800B7CC0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800B7CC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7CC8: jal         0x800B5EDC
    // 0x800B7CCC: addiu       $a0, $a0, -0x6EC8
    ctx->r4 = ADD32(ctx->r4, -0X6EC8);
    render_printf(rdram, ctx);
        goto after_28;
    // 0x800B7CCC: addiu       $a0, $a0, -0x6EC8
    ctx->r4 = ADD32(ctx->r4, -0X6EC8);
    after_28:
    // 0x800B7CD0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B7CD4: bne         $s4, $s5, L_800B7C9C
    if (ctx->r20 != ctx->r21) {
        // 0x800B7CD8: nop
    
            goto L_800B7C9C;
    }
    // 0x800B7CD8: nop

    // 0x800B7CDC: b           L_800B7CEC
    // 0x800B7CE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B7CEC;
    // 0x800B7CE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7CE4:
    // 0x800B7CE4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B7CE8:
    // 0x800B7CE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7CEC:
    // 0x800B7CEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B7CF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B7CF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7CF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B7CFC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B7D00: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B7D04: jr          $ra
    // 0x800B7D08: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B7D08: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void race_postrace_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D8E0: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x8006D8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D8E8: jr          $ra
    // 0x8006D8EC: sb          $t6, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = ctx->r14;
    return;
    // 0x8006D8EC: sb          $t6, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mark_write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ECE4: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006ECE8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ECEC: nop

    // 0x8006ECF0: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x8006ECF4: jr          $ra
    // 0x8006ECF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ECF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void __osSetHWIntrRoutine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D47F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D47F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D47F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D47FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D4800: jal         0x800D2560
    // 0x800D4804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800D4804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D4808: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D480C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800D4814: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D4818: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D481C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D4820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4824: jal         0x800D2580
    // 0x800D4828: sw          $t6, 0x48A0($at)
    MEM_W(0X48A0, ctx->r1) = ctx->r14;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4828: sw          $t6, 0x48A0($at)
    MEM_W(0X48A0, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D482C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D4838: jr          $ra
    // 0x800D483C: nop

    return;
    // 0x800D483C: nop

;}
