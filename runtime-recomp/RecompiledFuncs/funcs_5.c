#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void input_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006A438: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A43C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006A440: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006A444: sb          $t8, 0x1153($at)
    MEM_B(0X1153, ctx->r1) = ctx->r24;
    // 0x8006A448: sb          $t7, 0x1152($at)
    MEM_B(0X1152, ctx->r1) = ctx->r15;
    // 0x8006A44C: sb          $t6, 0x1151($at)
    MEM_B(0X1151, ctx->r1) = ctx->r14;
    // 0x8006A450: jr          $ra
    // 0x8006A454: sb          $zero, 0x1150($at)
    MEM_B(0X1150, ctx->r1) = 0;
    return;
    // 0x8006A454: sb          $zero, 0x1150($at)
    MEM_B(0X1150, ctx->r1) = 0;
;}
RECOMP_FUNC void alCSPSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8560: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8568: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800C856C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8570: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8574: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8578: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C857C: jal         0x800C91AC
    // 0x800C8580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8588: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C858C: jr          $ra
    // 0x800C8590: nop

    return;
    // 0x800C8590: nop

;}
RECOMP_FUNC void set_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2AF8: jr          $ra
    // 0x800C2AFC: sw          $a0, 0x3680($at)
    MEM_W(0X3680, ctx->r1) = ctx->r4;
    return;
    // 0x800C2AFC: sw          $a0, 0x3680($at)
    MEM_W(0X3680, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void debug_print_fixed_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80069F68: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80069F6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80069F70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80069F74: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80069F78: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80069F7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80069F80: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80069F84: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80069F88: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80069F8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80069F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80069F94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80069F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069F9C: addiu       $fp, $fp, 0x7084
    ctx->r30 = ADD32(ctx->r30, 0X7084);
    // 0x80069FA0: addiu       $s4, $s4, 0x707C
    ctx->r20 = ADD32(ctx->r20, 0X707C);
    // 0x80069FA4: addiu       $s3, $s3, 0x7078
    ctx->r19 = ADD32(ctx->r19, 0X7078);
    // 0x80069FA8: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x80069FAC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80069FB0: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
L_80069FB4:
    // 0x80069FB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80069FB8: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_80069FBC:
    // 0x80069FBC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80069FC0: jal         0x800C9D54
    // 0x80069FC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80069FC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80069FC8: lh          $a1, 0x20($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X20);
    // 0x80069FCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80069FD0: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80069FD4: jal         0x800C9D54
    // 0x80069FD8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80069FD8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x80069FDC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80069FE0: bne         $s1, $s5, L_80069FBC
    if (ctx->r17 != ctx->r21) {
        // 0x80069FE4: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80069FBC;
    }
    // 0x80069FE4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80069FE8: jal         0x800C9D54
    // 0x80069FEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80069FEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x80069FF0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80069FF4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80069FF8: bne         $s6, $at, L_80069FB4
    if (ctx->r22 != ctx->r1) {
        // 0x80069FFC: addiu       $s7, $s7, 0x8
        ctx->r23 = ADD32(ctx->r23, 0X8);
            goto L_80069FB4;
    }
    // 0x80069FFC: addiu       $s7, $s7, 0x8
    ctx->r23 = ADD32(ctx->r23, 0X8);
    // 0x8006A000: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A004: jal         0x800C9D54
    // 0x8006A008: addiu       $a0, $a0, 0x7088
    ctx->r4 = ADD32(ctx->r4, 0X7088);
    rmonPrintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A008: addiu       $a0, $a0, 0x7088
    ctx->r4 = ADD32(ctx->r4, 0X7088);
    after_3:
    // 0x8006A00C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006A014: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A018: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006A01C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006A020: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006A024: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A028: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006A02C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006A030: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006A034: jr          $ra
    // 0x8006A038: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8006A038: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void rankings_render_order(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098EBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80098EC0: addiu       $v0, $v0, 0x63BC
    ctx->r2 = ADD32(ctx->r2, 0X63BC);
    // 0x80098EC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80098EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098ECC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80098ED0: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80098ED4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80098ED8: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80098EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098EE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80098EE4: bne         $at, $zero, L_80098EF4
    if (ctx->r1 != 0) {
        // 0x80098EE8: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80098EF4;
    }
    // 0x80098EE8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80098EEC: addiu       $t4, $zero, 0x1FF
    ctx->r12 = ADD32(0, 0X1FF);
    // 0x80098EF0: subu        $a2, $t4, $t9
    ctx->r6 = SUB32(ctx->r12, ctx->r25);
L_80098EF4:
    // 0x80098EF4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80098EF8: lw          $t1, 0xFE4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFE4);
    // 0x80098EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80098F00: blez        $t1, L_80098F94
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80098F04: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80098F94;
    }
    // 0x80098F04: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80098F08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098F0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80098F10: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098F14: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80098F18: lw          $t2, -0xB44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB44);
    // 0x80098F1C: addiu       $a3, $a3, 0x6418
    ctx->r7 = ADD32(ctx->r7, 0X6418);
    // 0x80098F20: addiu       $t0, $t0, 0x6420
    ctx->r8 = ADD32(ctx->r8, 0X6420);
    // 0x80098F24: addiu       $t3, $t3, 0x63E0
    ctx->r11 = ADD32(ctx->r11, 0X63E0);
    // 0x80098F28: addiu       $a1, $a1, 0x1088
    ctx->r5 = ADD32(ctx->r5, 0X1088);
L_80098F2C:
    // 0x80098F2C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80098F30: beq         $at, $zero, L_80098F78
    if (ctx->r1 == 0) {
        // 0x80098F34: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80098F78;
    }
    // 0x80098F34: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80098F38: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80098F3C: addu        $t5, $a3, $a0
    ctx->r13 = ADD32(ctx->r7, ctx->r4);
    // 0x80098F40: bne         $v1, $zero, L_80098F58
    if (ctx->r3 != 0) {
        // 0x80098F44: nop
    
            goto L_80098F58;
    }
    // 0x80098F44: nop

    // 0x80098F48: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80098F4C: nop

    // 0x80098F50: bne         $t6, $zero, L_80098F70
    if (ctx->r14 != 0) {
        // 0x80098F54: nop
    
            goto L_80098F70;
    }
    // 0x80098F54: nop

L_80098F58:
    // 0x80098F58: beq         $v1, $zero, L_80098F78
    if (ctx->r3 == 0) {
        // 0x80098F5C: addu        $t7, $t0, $a0
        ctx->r15 = ADD32(ctx->r8, ctx->r4);
            goto L_80098F78;
    }
    // 0x80098F5C: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
    // 0x80098F60: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80098F64: nop

    // 0x80098F68: beq         $t8, $zero, L_80098F78
    if (ctx->r24 == 0) {
        // 0x80098F6C: nop
    
            goto L_80098F78;
    }
    // 0x80098F6C: nop

L_80098F70:
    // 0x80098F70: sra         $v0, $a2, 1
    ctx->r2 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80098F74: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
L_80098F78:
    // 0x80098F78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80098F7C: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80098F80: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x80098F84: sb          $v0, -0x54($a1)
    MEM_B(-0X54, ctx->r5) = ctx->r2;
    // 0x80098F88: sb          $v0, -0x53($a1)
    MEM_B(-0X53, ctx->r5) = ctx->r2;
    // 0x80098F8C: bne         $at, $zero, L_80098F2C
    if (ctx->r1 != 0) {
        // 0x80098F90: sb          $v0, -0x52($a1)
        MEM_B(-0X52, ctx->r5) = ctx->r2;
            goto L_80098F2C;
    }
    // 0x80098F90: sb          $v0, -0x52($a1)
    MEM_B(-0X52, ctx->r5) = ctx->r2;
L_80098F94:
    // 0x80098F94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80098F98: addiu       $t3, $t3, 0x63E0
    ctx->r11 = ADD32(ctx->r11, 0X63E0);
    // 0x80098F9C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80098FA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80098FA4: beq         $v0, $at, L_80098FB4
    if (ctx->r2 == ctx->r1) {
        // 0x80098FA8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80098FB4;
    }
    // 0x80098FA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80098FAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80098FB0: bne         $v0, $at, L_80098FC4
    if (ctx->r2 != ctx->r1) {
        // 0x80098FB4: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80098FC4;
    }
L_80098FB4:
    // 0x80098FB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098FB8: addiu       $a1, $a1, 0x1048
    ctx->r5 = ADD32(ctx->r5, 0X1048);
    // 0x80098FBC: jal         0x800821EC
    // 0x80098FC0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_0;
    // 0x80098FC0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
L_80098FC4:
    // 0x80098FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098FCC: jr          $ra
    // 0x80098FD0: nop

    return;
    // 0x80098FD0: nop

;}
RECOMP_FUNC void alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9AE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C9AE4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800C9AE8: jr          $ra
    // 0x800C9AEC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x800C9AEC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void obj_init_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80036C34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80036C38: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80036C3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80036C40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036C44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80036C48: lbu         $t6, 0xE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XE);
    // 0x80036C4C: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x80036C50: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80036C54: sh          $t7, 0x100($s0)
    MEM_H(0X100, ctx->r16) = ctx->r15;
    // 0x80036C58: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x80036C5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80036C60: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80036C64: sh          $t9, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r25;
    // 0x80036C68: lhu         $t0, 0x8($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X8);
    // 0x80036C6C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80036C70: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80036C74: bgez        $t0, L_80036C8C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80036C78: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80036C8C;
    }
    // 0x80036C78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80036C7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036C80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036C84: nop

    // 0x80036C88: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80036C8C:
    // 0x80036C8C: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x80036C90: lbu         $t1, 0xA($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XA);
    // 0x80036C94: nop

    // 0x80036C98: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80036C9C: bgez        $t1, L_80036CB4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80036CA0: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80036CB4;
    }
    // 0x80036CA0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036CA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036CA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036CAC: nop

    // 0x80036CB0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80036CB4:
    // 0x80036CB4: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
    // 0x80036CB8: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x80036CBC: nop

    // 0x80036CC0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80036CC4: nop

    // 0x80036CC8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80036CCC: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x80036CD0: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x80036CD4: nop

    // 0x80036CD8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80036CDC: nop

    // 0x80036CE0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80036CE4: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x80036CE8: lh          $t4, 0x6($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X6);
    // 0x80036CEC: nop

    // 0x80036CF0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80036CF4: nop

    // 0x80036CF8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80036CFC: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x80036D00: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80036D04: nop

    // 0x80036D08: bne         $t5, $zero, L_80036D44
    if (ctx->r13 != 0) {
        // 0x80036D0C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80036D44;
    }
    // 0x80036D0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D10: jal         0x8006F94C
    // 0x80036D14: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80036D14: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x80036D18: sh          $v0, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r2;
    // 0x80036D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D20: jal         0x8006F94C
    // 0x80036D24: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80036D24: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x80036D28: sh          $v0, 0x102($s0)
    MEM_H(0X102, ctx->r16) = ctx->r2;
    // 0x80036D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036D30: jal         0x8006F94C
    // 0x80036D34: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80036D34: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_2:
    // 0x80036D38: sh          $v0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r2;
    // 0x80036D3C: b           L_80036D54
    // 0x80036D40: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
        goto L_80036D54;
    // 0x80036D40: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
L_80036D44:
    // 0x80036D44: lh          $t7, 0x104($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X104);
    // 0x80036D48: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80036D4C: sh          $t6, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r14;
    // 0x80036D50: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_80036D54:
    // 0x80036D54: lh          $t8, 0xFE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XFE);
    // 0x80036D58: nop

    // 0x80036D5C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80036D60: jal         0x800707C4
    // 0x80036D64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80036D64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_3:
    // 0x80036D68: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036D6C: nop

    // 0x80036D70: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80036D74: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80036D78: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x80036D7C: jal         0x800707F8
    // 0x80036D80: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80036D80: nop

    after_4:
    // 0x80036D84: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80036D88: nop

    // 0x80036D8C: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80036D90: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80036D94: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036D98: jal         0x800707C4
    // 0x80036D9C: nop

    sins_f(rdram, ctx);
        goto after_5;
    // 0x80036D9C: nop

    after_5:
    // 0x80036DA0: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80036DA4: jal         0x800707F8
    // 0x80036DA8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80036DA8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80036DAC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80036DB0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80036DB4: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80036DB8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80036DBC: lwc1        $f18, 0x108($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80036DC0: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80036DC4: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x80036DC8: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80036DCC: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036DD0: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80036DD4: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80036DD8: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036DDC: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x80036DE0: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80036DE4: jal         0x80011560
    // 0x80036DE8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_7;
    // 0x80036DE8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80036DEC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80036DF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80036DF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80036DF8: jal         0x80011570
    // 0x80036DFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    move_object(rdram, ctx);
        goto after_8;
    // 0x80036DFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80036E00: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80036E04: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036E08: bne         $t1, $zero, L_80036ED0
    if (ctx->r9 != 0) {
        // 0x80036E0C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80036ED0;
    }
    // 0x80036E0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036E10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80036E14: addiu       $a0, $a0, -0x35B0
    ctx->r4 = ADD32(ctx->r4, -0X35B0);
    // 0x80036E18: addiu       $v0, $v0, -0x3630
    ctx->r2 = ADD32(ctx->r2, -0X3630);
L_80036E1C:
    // 0x80036E1C: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80036E20: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80036E24: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80036E28: lbu         $t3, -0xF($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0XF);
    // 0x80036E2C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80036E30: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x80036E34: lbu         $t4, -0xE($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0XE);
    // 0x80036E38: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80036E3C: sb          $t4, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r12;
    // 0x80036E40: lbu         $t5, -0xD($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0XD);
    // 0x80036E44: bne         $at, $zero, L_80036E1C
    if (ctx->r1 != 0) {
        // 0x80036E48: sb          $t5, -0xD($v1)
        MEM_B(-0XD, ctx->r3) = ctx->r13;
            goto L_80036E1C;
    }
    // 0x80036E48: sb          $t5, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r13;
    // 0x80036E4C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80036E50: addiu       $v1, $v1, -0x3658
    ctx->r3 = ADD32(ctx->r3, -0X3658);
    // 0x80036E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036E58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80036E5C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036E60: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80036E64:
    // 0x80036E64: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80036E68: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80036E6C: sh          $t6, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r14;
    // 0x80036E70: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80036E74: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80036E78: sh          $t7, 0x78($v0)
    MEM_H(0X78, ctx->r2) = ctx->r15;
    // 0x80036E7C: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80036E80: sb          $a0, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r4;
    // 0x80036E84: sb          $a0, 0x7D($v0)
    MEM_B(0X7D, ctx->r2) = ctx->r4;
    // 0x80036E88: sb          $a0, 0x7E($v0)
    MEM_B(0X7E, ctx->r2) = ctx->r4;
    // 0x80036E8C: sb          $a0, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = ctx->r4;
    // 0x80036E90: sh          $t8, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = ctx->r24;
    // 0x80036E94: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80036E98: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80036E9C: sh          $t9, 0xB2($v0)
    MEM_H(0XB2, ctx->r2) = ctx->r25;
    // 0x80036EA0: lh          $t0, -0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, -0X4);
    // 0x80036EA4: nop

    // 0x80036EA8: sh          $t0, 0xB4($v0)
    MEM_H(0XB4, ctx->r2) = ctx->r8;
    // 0x80036EAC: lh          $t1, -0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X2);
    // 0x80036EB0: sb          $a0, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r4;
    // 0x80036EB4: sb          $a0, 0xB9($v0)
    MEM_B(0XB9, ctx->r2) = ctx->r4;
    // 0x80036EB8: sb          $a0, 0xBA($v0)
    MEM_B(0XBA, ctx->r2) = ctx->r4;
    // 0x80036EBC: sb          $a0, 0xBB($v0)
    MEM_B(0XBB, ctx->r2) = ctx->r4;
    // 0x80036EC0: bne         $a2, $a1, L_80036E64
    if (ctx->r6 != ctx->r5) {
        // 0x80036EC4: sh          $t1, 0xB6($v0)
        MEM_H(0XB6, ctx->r2) = ctx->r9;
            goto L_80036E64;
    }
    // 0x80036EC4: sh          $t1, 0xB6($v0)
    MEM_H(0XB6, ctx->r2) = ctx->r9;
    // 0x80036EC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80036ECC: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
L_80036ED0:
    // 0x80036ED0: lbu         $t3, 0xC($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0XC);
    // 0x80036ED4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80036ED8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80036EDC: bgez        $t3, L_80036EF4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80036EE0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80036EF4;
    }
    // 0x80036EE0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036EE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80036EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036EEC: nop

    // 0x80036EF0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80036EF4:
    // 0x80036EF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036EF8: lwc1        $f18, 0x6048($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6048);
    // 0x80036EFC: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x80036F00: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80036F04: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80036F08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80036F10: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80036F14: lbu         $v0, 0xB($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XB);
    // 0x80036F18: lb          $t5, 0x55($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X55);
    // 0x80036F1C: addiu       $a2, $a2, -0x35B0
    ctx->r6 = ADD32(ctx->r6, -0X35B0);
    // 0x80036F20: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80036F24: beq         $at, $zero, L_80036F44
    if (ctx->r1 == 0) {
        // 0x80036F28: nop
    
            goto L_80036F44;
    }
    // 0x80036F28: nop

    // 0x80036F2C: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x80036F30: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80036F34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80036F38: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80036F3C: b           L_80036F58
    // 0x80036F40: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
        goto L_80036F58;
    // 0x80036F40: sw          $t9, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r25;
L_80036F44:
    // 0x80036F44: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80036F48: nop

    // 0x80036F4C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80036F50: nop

    // 0x80036F54: sw          $t1, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r9;
L_80036F58:
    // 0x80036F58: lw          $v0, 0xF8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XF8);
    // 0x80036F5C: nop

    // 0x80036F60: beq         $v0, $zero, L_80036F8C
    if (ctx->r2 == 0) {
        // 0x80036F64: nop
    
            goto L_80036F8C;
    }
    // 0x80036F64: nop

    // 0x80036F68: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80036F6C: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80036F70: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80036F74: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80036F78: sll         $t2, $a0, 5
    ctx->r10 = S32(ctx->r4 << 5);
    // 0x80036F7C: sll         $t3, $a1, 5
    ctx->r11 = S32(ctx->r5 << 5);
    // 0x80036F80: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80036F84: b           L_80036F8C
    // 0x80036F88: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80036F8C;
    // 0x80036F88: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80036F8C:
    // 0x80036F8C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80036F90: addiu       $v0, $v0, -0x3630
    ctx->r2 = ADD32(ctx->r2, -0X3630);
L_80036F94:
    // 0x80036F94: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x80036F98: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80036F9C: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FA0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80036FA4: mflo        $t5
    ctx->r13 = lo;
    // 0x80036FA8: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x80036FAC: sh          $t6, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r14;
    // 0x80036FB0: lh          $t7, -0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X1A);
    // 0x80036FB4: nop

    // 0x80036FB8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FBC: mflo        $t8
    ctx->r24 = lo;
    // 0x80036FC0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x80036FC4: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x80036FC8: lh          $t0, -0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X18);
    // 0x80036FCC: nop

    // 0x80036FD0: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FD4: mflo        $t1
    ctx->r9 = lo;
    // 0x80036FD8: sra         $t2, $t1, 2
    ctx->r10 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80036FDC: sh          $t2, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r10;
    // 0x80036FE0: lh          $t3, -0x16($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X16);
    // 0x80036FE4: nop

    // 0x80036FE8: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036FEC: mflo        $t4
    ctx->r12 = lo;
    // 0x80036FF0: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80036FF4: sh          $t5, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r13;
    // 0x80036FF8: lh          $t6, -0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X14);
    // 0x80036FFC: nop

    // 0x80037000: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037004: mflo        $t7
    ctx->r15 = lo;
    // 0x80037008: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8003700C: sh          $t8, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r24;
    // 0x80037010: lh          $t9, -0x12($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X12);
    // 0x80037014: nop

    // 0x80037018: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003701C: mflo        $t0
    ctx->r8 = lo;
    // 0x80037020: sra         $t1, $t0, 2
    ctx->r9 = S32(SIGNED(ctx->r8) >> 2);
    // 0x80037024: sh          $t1, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r9;
    // 0x80037028: lh          $t2, -0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, -0XC);
    // 0x8003702C: nop

    // 0x80037030: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037034: mflo        $t3
    ctx->r11 = lo;
    // 0x80037038: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8003703C: sh          $t4, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r12;
    // 0x80037040: lh          $t5, -0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XA);
    // 0x80037044: nop

    // 0x80037048: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003704C: mflo        $t6
    ctx->r14 = lo;
    // 0x80037050: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80037054: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x80037058: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8003705C: nop

    // 0x80037060: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037064: mflo        $t9
    ctx->r25 = lo;
    // 0x80037068: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8003706C: sh          $t0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r8;
    // 0x80037070: lh          $t1, -0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X6);
    // 0x80037074: nop

    // 0x80037078: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003707C: mflo        $t2
    ctx->r10 = lo;
    // 0x80037080: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80037084: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x80037088: lh          $t4, -0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X4);
    // 0x8003708C: nop

    // 0x80037090: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037094: mflo        $t5
    ctx->r13 = lo;
    // 0x80037098: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8003709C: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x800370A0: lh          $t7, -0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X2);
    // 0x800370A4: nop

    // 0x800370A8: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800370AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800370B0: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800370B4: bne         $v0, $a2, L_80036F94
    if (ctx->r2 != ctx->r6) {
        // 0x800370B8: sh          $t9, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r25;
            goto L_80036F94;
    }
    // 0x800370B8: sh          $t9, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r25;
    // 0x800370BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800370C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800370C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800370C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800370CC: jr          $ra
    // 0x800370D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800370D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void spawn_boss_hazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E204: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8005E208: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8005E20C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8005E210: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8005E214: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8005E218: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005E21C: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8005E220: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005E224: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005E228: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E22C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8005E230: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8005E234: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005E238: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8005E23C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8005E240: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005E244: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E248: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8005E24C: jal         0x8000E988
    // 0x8005E250: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x8005E250: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_0:
    // 0x8005E254: andi        $t7, $s0, 0x100
    ctx->r15 = ctx->r16 & 0X100;
    // 0x8005E258: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005E25C: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8005E260: sb          $s0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r16;
    // 0x8005E264: sb          $t9, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r25;
    // 0x8005E268: lwc1        $f6, 0x38($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X38);
    // 0x8005E26C: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E270: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E274: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E278: lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X98);
    // 0x8005E27C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8005E280: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E284: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8005E288: nop

    // 0x8005E28C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8005E290: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E294: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E298: nop

    // 0x8005E29C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005E2A0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8005E2A4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8005E2A8: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x8005E2AC: lwc1        $f6, 0x3C($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X3C);
    // 0x8005E2B0: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E2B4: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E2B8: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005E2BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E2C0: nop

    // 0x8005E2C4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E2C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E2CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E2D0: nop

    // 0x8005E2D4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005E2D8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005E2DC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E2E0: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8005E2E4: lwc1        $f6, 0x40($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X40);
    // 0x8005E2E8: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E2EC: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005E2F0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E2F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8005E2F8: nop

    // 0x8005E2FC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8005E300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E308: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005E30C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005E310: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8005E314: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8005E318: blez        $t6, L_8005E47C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005E31C: sh          $t5, 0x6A($sp)
        MEM_H(0X6A, ctx->r29) = ctx->r13;
            goto L_8005E47C;
    }
    // 0x8005E31C: sh          $t5, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r13;
    // 0x8005E320: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005E324: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005E328: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
L_8005E32C:
    // 0x8005E32C: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8005E330: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8005E334: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x8005E338: nop

    // 0x8005E33C: bne         $t7, $at, L_8005E46C
    if (ctx->r15 != ctx->r1) {
        // 0x8005E340: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E46C;
    }
    // 0x8005E340: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E344: lw          $s2, 0x3C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X3C);
    // 0x8005E348: lb          $t8, 0x193($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X193);
    // 0x8005E34C: lb          $v0, 0x8($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X8);
    // 0x8005E350: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005E354: beq         $t9, $v0, L_8005E364
    if (ctx->r25 == ctx->r2) {
        // 0x8005E358: nop
    
            goto L_8005E364;
    }
    // 0x8005E358: nop

    // 0x8005E35C: bne         $v0, $zero, L_8005E46C
    if (ctx->r2 != 0) {
        // 0x8005E360: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_8005E46C;
    }
    // 0x8005E360: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E364:
    // 0x8005E364: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E368: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005E36C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005E370: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8005E374: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005E378: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E37C: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8005E380: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E384: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005E388: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E38C: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E390: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E394: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8005E398: jal         0x800C9AD0
    // 0x8005E39C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8005E39C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x8005E3A0: lb          $t0, 0x9($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X9);
    // 0x8005E3A4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E3A8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8005E3AC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8005E3B0: nop

    // 0x8005E3B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005E3B8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005E3BC: mul.d       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x8005E3C0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8005E3C4: nop

    // 0x8005E3C8: bc1f        L_8005E464
    if (!c1cs) {
        // 0x8005E3CC: nop
    
            goto L_8005E464;
    }
    // 0x8005E3CC: nop

    // 0x8005E3D0: lw          $t2, 0x78($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X78);
    // 0x8005E3D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005E3D8: bne         $t2, $zero, L_8005E468
    if (ctx->r10 != 0) {
        // 0x8005E3DC: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_8005E468;
    }
    // 0x8005E3DC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005E3E0: sw          $t3, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r11;
    // 0x8005E3E4: jal         0x8000EA54
    // 0x8005E3E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8005E3E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8005E3EC: beq         $v0, $zero, L_8005E468
    if (ctx->r2 == 0) {
        // 0x8005E3F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8005E468;
    }
    // 0x8005E3F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005E3F4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8005E3F8: lwc1        $f18, 0x1C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8005E3FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E400: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    // 0x8005E404: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x8005E408: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005E40C: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x8005E410: lwc1        $f10, 0x24($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8005E414: sw          $s1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r17;
    // 0x8005E418: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x8005E41C: lb          $t4, 0xA($s2)
    ctx->r12 = MEM_B(ctx->r18, 0XA);
    // 0x8005E420: andi        $s4, $fp, 0xFFFF
    ctx->r20 = ctx->r30 & 0XFFFF;
    // 0x8005E424: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005E428: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005E42C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005E430: jal         0x8006F94C
    // 0x8005E434: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8005E434: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    after_3:
    // 0x8005E438: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8005E43C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8005E440: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8005E444: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x8005E448: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8005E44C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005E450: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005E454: jal         0x80009558
    // 0x8005E458: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_4;
    // 0x8005E458: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    after_4:
    // 0x8005E45C: b           L_8005E46C
    // 0x8005E460: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
        goto L_8005E46C;
    // 0x8005E460: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E464:
    // 0x8005E464: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
L_8005E468:
    // 0x8005E468: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_8005E46C:
    // 0x8005E46C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8005E470: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005E474: bne         $at, $zero, L_8005E32C
    if (ctx->r1 != 0) {
        // 0x8005E478: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8005E32C;
    }
    // 0x8005E478: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_8005E47C:
    // 0x8005E47C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005E480: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005E484: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005E488: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005E48C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E490: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005E494: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8005E498: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8005E49C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4A0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005E4A4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8005E4A8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8005E4AC: jr          $ra
    // 0x8005E4B0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8005E4B0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void vec3s_rotate_rpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800701E4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800701E8: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800701EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800701F0: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x800701F4: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x800701F8: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x800701FC: jal         0x80070830
    // 0x80070200: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x80070200: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x80070204: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x80070208: jal         0x8007082C
    // 0x8007020C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8007020C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_1:
    // 0x80070210: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070214: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070218: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007021C: mflo        $t0
    ctx->r8 = lo;
    // 0x80070220: nop

    // 0x80070224: nop

    // 0x80070228: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007022C: mflo        $t1
    ctx->r9 = lo;
    // 0x80070230: nop

    // 0x80070234: nop

    // 0x80070238: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007023C: mflo        $t3
    ctx->r11 = lo;
    // 0x80070240: sub         $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80070244: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80070248: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007024C: mflo        $t4
    ctx->r12 = lo;
    // 0x80070250: add         $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80070254: jal         0x80070830
    // 0x80070258: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x80070258: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x8007025C: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x80070260: jal         0x8007082C
    // 0x80070264: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x80070264: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_3:
    // 0x80070268: mult        $t4, $t6
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007026C: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80070270: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070274: mflo        $t0
    ctx->r8 = lo;
    // 0x80070278: nop

    // 0x8007027C: nop

    // 0x80070280: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070284: mflo        $t1
    ctx->r9 = lo;
    // 0x80070288: nop

    // 0x8007028C: nop

    // 0x80070290: mult        $t4, $t7
    result = S64(S32(ctx->r12)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070294: mflo        $t4
    ctx->r12 = lo;
    // 0x80070298: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8007029C: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800702A0: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800702A4: mflo        $t5
    ctx->r13 = lo;
    // 0x800702A8: add         $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x800702AC: jal         0x80070830
    // 0x800702B0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    sins_s16(rdram, ctx);
        goto after_4;
    // 0x800702B0: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    after_4:
    // 0x800702B4: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
    // 0x800702B8: jal         0x8007082C
    // 0x800702BC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    coss_s16(rdram, ctx);
        goto after_5;
    // 0x800702BC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_5:
    // 0x800702C0: mult        $t3, $t6
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800702C4: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x800702C8: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x800702CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800702D0: nop

    // 0x800702D4: nop

    // 0x800702D8: mult        $t5, $t6
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800702DC: mflo        $t1
    ctx->r9 = lo;
    // 0x800702E0: nop

    // 0x800702E4: nop

    // 0x800702E8: mult        $t3, $t7
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800702EC: mflo        $t3
    ctx->r11 = lo;
    // 0x800702F0: add         $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800702F4: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800702F8: mult        $t5, $t7
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800702FC: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80070300: mflo        $t5
    ctx->r13 = lo;
    // 0x80070304: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80070308: sra         $t5, $t5, 16
    ctx->r13 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8007030C: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80070310: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070314: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070318: jr          $ra
    // 0x8007031C: nop

    return;
    // 0x8007031C: nop

;}
RECOMP_FUNC void process_onscreen_textbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3444: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3448: lb          $t6, 0x3670($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3670);
    // 0x800C344C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3450: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C3454: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3458: beq         $t6, $zero, L_800C3550
    if (ctx->r14 == 0) {
        // 0x800C345C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800C3550;
    }
    // 0x800C345C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3460: jal         0x8006EAA0
    // 0x800C3464: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800C3464: nop

    after_0:
    // 0x800C3468: bne         $v0, $zero, L_800C34A0
    if (ctx->r2 != 0) {
        // 0x800C346C: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_800C34A0;
    }
    // 0x800C346C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C3470: addiu       $s0, $s0, 0x3678
    ctx->r16 = ADD32(ctx->r16, 0X3678);
    // 0x800C3474: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C3478: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C347C: blez        $v0, L_800C34A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C3480: subu        $t8, $v0, $t7
        ctx->r24 = SUB32(ctx->r2, ctx->r15);
            goto L_800C34A0;
    }
    // 0x800C3480: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x800C3484: bgtz        $t8, L_800C34A0
    if (SIGNED(ctx->r24) > 0) {
        // 0x800C3488: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800C34A0;
    }
    // 0x800C3488: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C348C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C3490: lw          $a0, 0x367C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X367C);
    // 0x800C3494: jal         0x800C31EC
    // 0x800C3498: nop

    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800C3498: nop

    after_1:
    // 0x800C349C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800C34A0:
    // 0x800C34A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C34A4: jal         0x800C2F1C
    // 0x800C34A8: nop

    process_subtitles(rdram, ctx);
        goto after_2;
    // 0x800C34A8: nop

    after_2:
    // 0x800C34AC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C34B0: lbu         $t0, -0x5877($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5877);
    // 0x800C34B4: nop

    // 0x800C34B8: beq         $t0, $zero, L_800C3554
    if (ctx->r8 == 0) {
        // 0x800C34BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C3554;
    }
    // 0x800C34BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C34C0: jal         0x8005A3B0
    // 0x800C34C4: nop

    disable_racer_input(rdram, ctx);
        goto after_3;
    // 0x800C34C4: nop

    after_3:
    // 0x800C34C8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C34CC: addiu       $s1, $s1, -0x587A
    ctx->r17 = ADD32(ctx->r17, -0X587A);
    // 0x800C34D0: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x800C34D4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C34D8: beq         $v0, $zero, L_800C3548
    if (ctx->r2 == 0) {
        // 0x800C34DC: addiu       $s0, $s0, -0x587B
        ctx->r16 = ADD32(ctx->r16, -0X587B);
            goto L_800C3548;
    }
    // 0x800C34DC: addiu       $s0, $s0, -0x587B
    ctx->r16 = ADD32(ctx->r16, -0X587B);
    // 0x800C34E0: lb          $t1, 0x0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X0);
    // 0x800C34E4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C34E8: nop

    // 0x800C34EC: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800C34F0: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800C34F4: lb          $t4, 0x0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X0);
    // 0x800C34F8: nop

    // 0x800C34FC: bgez        $t4, L_800C3538
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C3500: nop
    
            goto L_800C3538;
    }
    // 0x800C3500: nop

L_800C3504:
    // 0x800C3504: jal         0x8000C8B4
    // 0x800C3508: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x800C3508: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x800C350C: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x800C3510: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x800C3514: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3518: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800C351C: lb          $t9, 0x0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X0);
    // 0x800C3520: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C3524: bltz        $t9, L_800C3504
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C3528: sb          $t8, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r24;
            goto L_800C3504;
    }
    // 0x800C3528: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800C352C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3530: lb          $v0, -0x587A($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X587A);
    // 0x800C3534: nop

L_800C3538:
    // 0x800C3538: bgtz        $v0, L_800C3548
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C353C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C3548;
    }
    // 0x800C353C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C3540: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3544: sb          $t0, -0x587C($at)
    MEM_B(-0X587C, ctx->r1) = ctx->r8;
L_800C3548:
    // 0x800C3548: jal         0x8009CFEC
    // 0x800C354C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    npc_dialogue_loop(rdram, ctx);
        goto after_5;
    // 0x800C354C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
L_800C3550:
    // 0x800C3550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C3554:
    // 0x800C3554: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C3558: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C355C: jr          $ra
    // 0x800C3560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4C20: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D4C24: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D4C28: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4C2C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D4C30: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800D4C34: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800D4C38: beq         $at, $zero, L_800D4CA0
    if (ctx->r1 == 0) {
        // 0x800D4C3C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D4CA0;
    }
    // 0x800D4C3C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D4C40: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800D4C44: bne         $at, $zero, L_800D4C98
    if (ctx->r1 != 0) {
        // 0x800D4C48: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800D4C98;
    }
    // 0x800D4C48: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800D4C4C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D4C50: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D4C54: addiu       $v1, $v1, -0x67F0
    ctx->r3 = ADD32(ctx->r3, -0X67F0);
    // 0x800D4C58: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800D4C5C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800D4C60: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D4C64: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D4C68: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800D4C6C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D4C70: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800D4C74: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800D4C78: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D4C7C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800D4C80: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D4C84: nop

    // 0x800D4C88: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800D4C8C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800D4C90: jr          $ra
    // 0x800D4C94: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800D4C94: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800D4C98:
    // 0x800D4C98: jr          $ra
    // 0x800D4C9C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800D4C9C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800D4CA0:
    // 0x800D4CA0: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800D4CA4: beq         $at, $zero, L_800D4DB8
    if (ctx->r1 == 0) {
        // 0x800D4CA8: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800D4DB8;
    }
    // 0x800D4CA8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4CAC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D4CB0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4CB4: ldc1        $f10, -0x67C8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X67C8);
    // 0x800D4CB8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800D4CBC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800D4CC0: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800D4CC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D4CC8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D4CCC: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800D4CD0: nop

    // 0x800D4CD4: bc1fl       L_800D4D04
    if (!c1cs) {
        // 0x800D4CD8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800D4D04;
    }
    goto skip_0;
    // 0x800D4CD8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800D4CDC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D4CE0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D4CE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D4CE8: nop

    // 0x800D4CEC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800D4CF0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800D4CF4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D4CF8: b           L_800D4D20
    // 0x800D4CFC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800D4D20;
    // 0x800D4CFC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800D4D00: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800D4D04:
    // 0x800D4D04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D4D08: nop

    // 0x800D4D0C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800D4D10: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D4D14: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D4D18: nop

    // 0x800D4D1C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800D4D20:
    // 0x800D4D20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4D24: ldc1        $f18, -0x67C0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X67C0);
    // 0x800D4D28: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800D4D2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4D30: ldc1        $f6, -0x67B8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X67B8);
    // 0x800D4D34: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D4D38: addiu       $v1, $v1, -0x67F0
    ctx->r3 = ADD32(ctx->r3, -0X67F0);
    // 0x800D4D3C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800D4D40: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800D4D44: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800D4D48: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D4D4C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D4D50: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800D4D54: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800D4D58: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800D4D5C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D4D60: nop

    // 0x800D4D64: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D4D68: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800D4D6C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800D4D70: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800D4D74: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800D4D78: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D4D7C: bne         $t9, $zero, L_800D4D9C
    if (ctx->r25 != 0) {
        // 0x800D4D80: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800D4D9C;
    }
    // 0x800D4D80: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800D4D84: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D4D88: nop

    // 0x800D4D8C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800D4D90: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D4D94: jr          $ra
    // 0x800D4D98: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D4D98: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D4D9C:
    // 0x800D4D9C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D4DA0: nop

    // 0x800D4DA4: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D4DA8: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800D4DAC: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800D4DB0: jr          $ra
    // 0x800D4DB4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D4DB4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D4DB8:
    // 0x800D4DB8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800D4DBC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4DC0: bc1t        L_800D4DD4
    if (c1cs) {
        // 0x800D4DC4: nop
    
            goto L_800D4DD4;
    }
    // 0x800D4DC4: nop

    // 0x800D4DC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D4DCC: jr          $ra
    // 0x800D4DD0: lwc1        $f0, -0x6740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6740);
    return;
    // 0x800D4DD0: lwc1        $f0, -0x6740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6740);
L_800D4DD4:
    // 0x800D4DD4: lwc1        $f0, -0x67B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X67B0);
    // 0x800D4DD8: jr          $ra
    // 0x800D4DDC: nop

    return;
    // 0x800D4DDC: nop

;}
RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065494: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80065498: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8006549C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800654A0: lw          $s2, 0x3780($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3780);
    // 0x800654A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800654A8: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800654AC: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800654B0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800654B4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800654B8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800654BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800654C0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800654C4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800654C8: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x800654CC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800654D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800654D4: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800654D8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800654DC: bne         $t6, $zero, L_800654F0
    if (ctx->r14 != 0) {
        // 0x800654E0: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800654F0;
    }
    // 0x800654E0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800654E4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800654E8: b           L_8006563C
    // 0x800654EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006563C;
    // 0x800654EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800654F0:
    // 0x800654F0: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x800654F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800654F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800654FC: jal         0x800657EC
    // 0x80065500: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    static_3_800657EC(rdram, ctx);
        goto after_0;
    // 0x80065500: sw          $s1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r17;
    after_0:
    // 0x80065504: lw          $t8, 0x20($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X20);
    // 0x80065508: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8006550C: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80065510: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80065514: beq         $at, $zero, L_80065584
    if (ctx->r1 == 0) {
        // 0x80065518: addiu       $s1, $zero, -0x10
        ctx->r17 = ADD32(0, -0X10);
            goto L_80065584;
    }
    // 0x80065518: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
L_8006551C:
    // 0x8006551C: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80065520: nop

    // 0x80065524: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x80065528: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8006552C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80065530: nop

    // 0x80065534: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065538: nop

    // 0x8006553C: jalr        $t9
    // 0x80065540: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80065540: nop

    after_1:
    // 0x80065544: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065548: jal         0x80065754
    // 0x8006554C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    static_3_80065754(rdram, ctx);
        goto after_2;
    // 0x8006554C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80065550: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80065554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065558: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8006555C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80065560: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80065564: jal         0x800657EC
    // 0x80065568: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    static_3_800657EC(rdram, ctx);
        goto after_3;
    // 0x80065568: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    after_3:
    // 0x8006556C: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x80065570: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80065574: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x80065578: slt         $at, $t7, $s3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8006557C: bne         $at, $zero, L_8006551C
    if (ctx->r1 != 0) {
        // 0x80065580: nop
    
            goto L_8006551C;
    }
    // 0x80065580: nop

L_80065584:
    // 0x80065584: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x80065588: addiu       $s1, $zero, -0x10
    ctx->r17 = ADD32(0, -0X10);
    // 0x8006558C: and         $t0, $t8, $s1
    ctx->r8 = ctx->r24 & ctx->r17;
    // 0x80065590: blez        $s3, L_8006561C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80065594: sw          $t0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r8;
            goto L_8006561C;
    }
    // 0x80065594: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x80065598: addiu       $s7, $sp, 0x62
    ctx->r23 = ADD32(ctx->r29, 0X62);
    // 0x8006559C: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800655A0:
    // 0x800655A0: lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X48);
    // 0x800655A4: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800655A8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800655AC: beq         $at, $zero, L_800655BC
    if (ctx->r1 == 0) {
        // 0x800655B0: nop
    
            goto L_800655BC;
    }
    // 0x800655B0: nop

    // 0x800655B4: b           L_800655BC
    // 0x800655B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800655BC;
    // 0x800655B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800655BC:
    // 0x800655BC: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800655C0: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800655C4: lw          $s1, 0x38($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X38);
    // 0x800655C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800655CC: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800655D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800655D4: jalr        $t9
    // 0x800655D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800655D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800655DC: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x800655E0: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x800655E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800655E8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800655EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800655F0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800655F4: jalr        $t9
    // 0x800655F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800655F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800655FC: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x80065600: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x80065604: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80065608: addu        $t3, $t5, $s0
    ctx->r11 = ADD32(ctx->r13, ctx->r16);
    // 0x8006560C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80065610: addu        $s5, $s5, $t4
    ctx->r21 = ADD32(ctx->r21, ctx->r12);
    // 0x80065614: bgtz        $s3, L_800655A0
    if (SIGNED(ctx->r19) > 0) {
        // 0x80065618: sw          $t3, 0x20($s2)
        MEM_W(0X20, ctx->r18) = ctx->r11;
            goto L_800655A0;
    }
    // 0x80065618: sw          $t3, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r11;
L_8006561C:
    // 0x8006561C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80065620: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80065624: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x80065628: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8006562C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80065630: jal         0x800656BC
    // 0x80065634: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_6;
    // 0x80065634: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_6:
    // 0x80065638: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8006563C:
    // 0x8006563C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065640: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80065644: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80065648: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8006564C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80065650: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80065654: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80065658: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8006565C: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80065660: jr          $ra
    // 0x80065664: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80065664: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void cam_set_zoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066060: bltz        $a0, L_80066090
    if (SIGNED(ctx->r4) < 0) {
        // 0x80066064: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066090;
    }
    // 0x80066064: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066068: beq         $at, $zero, L_80066090
    if (ctx->r1 == 0) {
        // 0x8006606C: sll         $t6, $a0, 4
        ctx->r14 = S32(ctx->r4 << 4);
            goto L_80066090;
    }
    // 0x8006606C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80066070: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066074: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80066078: sb          $a1, -0x2D08($at)
    MEM_B(-0X2D08, ctx->r1) = ctx->r5;
    // 0x8006607C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066080: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066088: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006608C: sb          $a1, 0xAFB($at)
    MEM_B(0XAFB, ctx->r1) = ctx->r5;
L_80066090:
    // 0x80066090: jr          $ra
    // 0x80066094: nop

    return;
    // 0x80066094: nop

;}
RECOMP_FUNC void sndp_stop_all_retrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049C0: jal         0x800048D8
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049C4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800049C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049D0: jr          $ra
    // 0x800049D4: nop

    return;
    // 0x800049D4: nop

;}
RECOMP_FUNC void postrace_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094A5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094A60: addiu       $v1, $v1, 0x6C54
    ctx->r3 = ADD32(ctx->r3, 0X6C54);
    // 0x80094A64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80094A68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094A6C: bltz        $v0, L_80094C04
    if (SIGNED(ctx->r2) < 0) {
        // 0x80094A70: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80094C04;
    }
    // 0x80094A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094A74: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80094A78: beq         $at, $zero, L_80094A8C
    if (ctx->r1 == 0) {
        // 0x80094A7C: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80094A8C;
    }
    // 0x80094A7C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80094A80: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80094A84: b           L_80094C04
    // 0x80094A88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80094C04;
    // 0x80094A88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80094A8C:
    // 0x80094A8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094A90: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80094A94: lh          $a0, 0xA10($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XA10);
    // 0x80094A98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094A9C: bne         $a0, $at, L_80094BE8
    if (ctx->r4 != ctx->r1) {
        // 0x80094AA0: nop
    
            goto L_80094BE8;
    }
    // 0x80094AA0: nop

    // 0x80094AA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094AA8: jal         0x8009C8A4
    // 0x80094AAC: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    menu_imagegroup_load(rdram, ctx);
        goto after_0;
    // 0x80094AAC: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    after_0:
    // 0x80094AB0: jal         0x80094604
    // 0x80094AB4: nop

    menu_racer_portraits(rdram, ctx);
        goto after_1;
    // 0x80094AB4: nop

    after_1:
    // 0x80094AB8: jal         0x8006EA90
    // 0x80094ABC: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x80094ABC: nop

    after_2:
    // 0x80094AC0: lb          $t8, 0x114($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X114);
    // 0x80094AC4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80094AC8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80094ACC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80094AD0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80094AD4: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80094AD8: lb          $t3, 0x59($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X59);
    // 0x80094ADC: addiu       $a1, $a1, 0xAF0
    ctx->r5 = ADD32(ctx->r5, 0XAF0);
    // 0x80094AE0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80094AE4: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    { extern uint32_t dkr_legacy_character_portrait_lookup(uint8_t*, recomp_context*, uint32_t); uint32_t cell = dkr_legacy_character_portrait_lookup(rdram, ctx, (uint32_t)ctx->r10); if (cell) ctx->r13 = (int32_t)cell; }
    // 0x80094AE8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80094AEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094AF0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80094AF4: jal         0x8000E4C8
    // 0x80094AF8: sw          $t6, 0xC00($at)
    MEM_W(0XC00, ctx->r1) = ctx->r14;
    is_time_trial_enabled(rdram, ctx);
        goto after_3;
    // 0x80094AF8: sw          $t6, 0xC00($at)
    MEM_W(0XC00, ctx->r1) = ctx->r14;
    after_3:
    // 0x80094AFC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80094B00: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80094B04: bne         $v0, $zero, L_80094BD8
    if (ctx->r2 != 0) {
        // 0x80094B08: addiu       $a1, $a1, 0xAF0
        ctx->r5 = ADD32(ctx->r5, 0XAF0);
            goto L_80094BD8;
    }
    // 0x80094B08: addiu       $a1, $a1, 0xAF0
    ctx->r5 = ADD32(ctx->r5, 0XAF0);
    // 0x80094B0C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094B10: addiu       $a2, $a2, 0xDCC
    ctx->r6 = ADD32(ctx->r6, 0XDCC);
    // 0x80094B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094B18: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // 0x80094B1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80094B20:
    // 0x80094B20: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80094B24:
    // 0x80094B24: lb          $t7, 0x5A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5A);
    // 0x80094B28: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80094B2C: bne         $a0, $t7, L_80094B50
    if (ctx->r4 != ctx->r15) {
        // 0x80094B30: sll         $t4, $a0, 5
        ctx->r12 = S32(ctx->r4 << 5);
            goto L_80094B50;
    }
    // 0x80094B30: sll         $t4, $a0, 5
    ctx->r12 = S32(ctx->r4 << 5);
    // 0x80094B34: lb          $t8, 0x59($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X59);
    // 0x80094B38: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80094B3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80094B40: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    { extern uint32_t dkr_legacy_character_portrait_lookup(uint8_t*, recomp_context*, uint32_t); uint32_t cell = dkr_legacy_character_portrait_lookup(rdram, ctx, (uint32_t)ctx->r2); if (cell) ctx->r10 = (int32_t)cell; }
    // 0x80094B44: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80094B48: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x80094B4C: sw          $t3, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r11;
L_80094B50:
    // 0x80094B50: bne         $v1, $a3, L_80094B24
    if (ctx->r3 != ctx->r7) {
        // 0x80094B54: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80094B24;
    }
    // 0x80094B54: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80094B58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80094B5C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80094B60: bne         $at, $zero, L_80094B20
    if (ctx->r1 != 0) {
        // 0x80094B64: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80094B20;
    }
    // 0x80094B64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80094B68: jal         0x8009EC80
    // 0x80094B6C: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x80094B6C: nop

    after_4:
    // 0x80094B70: beq         $v0, $zero, L_80094BD8
    if (ctx->r2 == 0) {
        // 0x80094B74: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80094BD8;
    }
    // 0x80094B74: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80094B78: lw          $t7, 0xD40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD40);
    // 0x80094B7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B80: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80094B84: sw          $t7, 0xD20($at)
    MEM_W(0XD20, ctx->r1) = ctx->r15;
    // 0x80094B88: lw          $t8, 0xD60($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD60);
    // 0x80094B8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80094B90: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80094B94: addiu       $v1, $v1, 0xCEC
    ctx->r3 = ADD32(ctx->r3, 0XCEC);
    // 0x80094B98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094B9C: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x80094BA0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x80094BA4: sw          $t8, 0xD40($at)
    MEM_W(0XD40, ctx->r1) = ctx->r24;
    // 0x80094BA8: lw          $t5, 0x94($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X94);
    // 0x80094BAC: lw          $t3, 0xB4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB4);
    // 0x80094BB0: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80094BB4: lw          $t2, 0x54($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X54);
    // 0x80094BB8: sw          $t5, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r13;
    // 0x80094BBC: sw          $t3, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r11;
    // 0x80094BC0: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
    // 0x80094BC4: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x80094BC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80094BCC: addiu       $v0, $v0, 0x6850
    ctx->r2 = ADD32(ctx->r2, 0X6850);
    // 0x80094BD0: sw          $v0, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r2;
    // 0x80094BD4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80094BD8:
    // 0x80094BD8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80094BDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094BE0: b           L_80094C04
    // 0x80094BE4: sw          $t6, 0x6C54($at)
    MEM_W(0X6C54, ctx->r1) = ctx->r14;
        goto L_80094C04;
    // 0x80094BE4: sw          $t6, 0x6C54($at)
    MEM_W(0X6C54, ctx->r1) = ctx->r14;
L_80094BE8:
    // 0x80094BE8: jal         0x8009C6D4
    // 0x80094BEC: nop

    menu_asset_load(rdram, ctx);
        goto after_5;
    // 0x80094BEC: nop

    after_5:
    // 0x80094BF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80094BF4: lw          $t7, 0x6C54($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C54);
    // 0x80094BF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094BFC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80094C00: sw          $t8, 0x6C54($at)
    MEM_W(0X6C54, ctx->r1) = ctx->r24;
L_80094C04:
    // 0x80094C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094C08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80094C0C: jr          $ra
    // 0x80094C10: nop

    return;
    // 0x80094C10: nop

;}
RECOMP_FUNC void interrupts_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F53C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F540: lb          $t0, -0x2BD0($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2BD0);
    // 0x8006F544: beq         $t0, $zero, L_8006F55C
    if (ctx->r8 == 0) {
        // 0x8006F548: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F55C;
    }
    // 0x8006F548: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F54C: or          $t0, $t0, $a0
    ctx->r8 = ctx->r8 | ctx->r4;
    // 0x8006F550: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x8006F554: nop

    // 0x8006F558: nop

L_8006F55C:
    // 0x8006F55C: jr          $ra
    // 0x8006F560: nop

    return;
    // 0x8006F560: nop

;}
RECOMP_FUNC void obj_init_midifadepoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80041E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041E88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80041E8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80041E90: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x80041E94: lhu         $t6, 0xA($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XA);
    // 0x80041E98: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80041E9C: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x80041EA0: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x80041EA4: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x80041EA8: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80041EAC: lbu         $t8, 0x1C($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1C);
    // 0x80041EB0: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x80041EB4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80041EB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80041EBC: beq         $at, $zero, L_80041ECC
    if (ctx->r1 == 0) {
        // 0x80041EC0: sb          $t8, 0x1C($a2)
        MEM_B(0X1C, ctx->r6) = ctx->r24;
            goto L_80041ECC;
    }
    // 0x80041EC0: sb          $t8, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r24;
    // 0x80041EC4: addiu       $t0, $v0, 0xA
    ctx->r8 = ADD32(ctx->r2, 0XA);
    // 0x80041EC8: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
L_80041ECC:
    // 0x80041ECC: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80041ED0: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80041ED4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80041ED8: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80041EDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80041EE0: sb          $t1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r9;
    // 0x80041EE4: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x80041EE8: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
    // 0x80041EEC: sb          $t2, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r10;
    // 0x80041EF0: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80041EF4: addiu       $v1, $s0, 0x3
    ctx->r3 = ADD32(ctx->r16, 0X3);
    // 0x80041EF8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80041EFC: sb          $t3, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r11;
L_80041F00:
    // 0x80041F00: lbu         $t4, 0xC($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XC);
    // 0x80041F04: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80041F08: sb          $t4, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r12;
    // 0x80041F0C: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x80041F10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80041F14: sb          $t5, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r13;
    // 0x80041F18: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x80041F1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80041F20: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x80041F24: lbu         $t7, 0xB($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XB);
    // 0x80041F28: bne         $a0, $a1, L_80041F00
    if (ctx->r4 != ctx->r5) {
        // 0x80041F2C: sb          $t7, 0xB($v0)
        MEM_B(0XB, ctx->r2) = ctx->r15;
            goto L_80041F00;
    }
    // 0x80041F2C: sb          $t7, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r15;
    // 0x80041F30: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x80041F34: nop

    // 0x80041F38: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x80041F3C: nop

    // 0x80041F40: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80041F44: nop

    // 0x80041F48: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80041F4C: nop

    // 0x80041F50: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x80041F54: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80041F58: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80041F5C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80041F60: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041F64: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x80041F68: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80041F6C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041F70: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80041F74: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80041F78: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041F7C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041F80: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041F84: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80041F88: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80041F8C: jal         0x800C9AD0
    // 0x80041F90: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80041F90: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80041F94: lhu         $t2, 0x8($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X8);
    // 0x80041F98: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80041F9C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80041FA0: bgez        $t2, L_80041FB8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80041FA4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80041FB8;
    }
    // 0x80041FA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041FA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041FAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041FB0: nop

    // 0x80041FB4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80041FB8:
    // 0x80041FB8: nop

    // 0x80041FBC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80041FC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041FC4: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x80041FC8: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
    // 0x80041FCC: nop

    // 0x80041FD0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80041FD4: bgez        $t3, L_80041FE8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80041FD8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80041FE8;
    }
    // 0x80041FD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041FDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041FE0: nop

    // 0x80041FE4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80041FE8:
    // 0x80041FE8: nop

    // 0x80041FEC: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80041FF0: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80041FF4: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80041FF8: nop

    // 0x80041FFC: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x80042000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042004: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80042008: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004200C: jr          $ra
    // 0x80042010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80042010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mode_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DCF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DCFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DD00: lb          $t6, 0x3514($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3514);
    // 0x8006DD04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006DD08: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    // 0x8006DD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006DD14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006DD18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006DD1C: bne         $t6, $zero, L_8006DD40
    if (ctx->r14 != 0) {
        // 0x8006DD20: sb          $zero, 0x3516($at)
        MEM_B(0X3516, ctx->r1) = 0;
            goto L_8006DD40;
    }
    // 0x8006DD20: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    // 0x8006DD24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DD28: lw          $t7, 0x34F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X34F0);
    // 0x8006DD2C: nop

    // 0x8006DD30: beq         $t7, $zero, L_8006DD44
    if (ctx->r15 == 0) {
        // 0x8006DD34: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8006DD44;
    }
    // 0x8006DD34: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8006DD38: jal         0x8006DC58
    // 0x8006DD3C: nop

    update_menu_scene(rdram, ctx);
        goto after_0;
    // 0x8006DD3C: nop

    after_0:
L_8006DD40:
    // 0x8006DD40: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8006DD44:
    // 0x8006DD44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006DD48: addiu       $s0, $s0, 0x11F8
    ctx->r16 = ADD32(ctx->r16, 0X11F8);
    // 0x8006DD4C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DD50: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DD54: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DD58: addiu       $a3, $a3, 0x1228
    ctx->r7 = ADD32(ctx->r7, 0X1228);
    // 0x8006DD5C: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006DD60: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006DD64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006DD68: jal         0x800815A4
    // 0x8006DD6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    menu_loop(rdram, ctx);
        goto after_1;
    // 0x8006DD6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    extern void dkr_custom_tracks_auto_boot(uint8_t*, recomp_context*); dkr_custom_tracks_auto_boot(rdram, ctx);
    // 0x8006DD70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006DD74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD78: sw          $t9, 0x34F0($at)
    MEM_W(0X34F0, ctx->r1) = ctx->r25;
    // 0x8006DD7C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006DD80: bne         $v0, $at, L_8006DD94
    if (ctx->r2 != ctx->r1) {
        // 0x8006DD84: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_8006DD94;
    }
    // 0x8006DD84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8006DD88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD8C: b           L_8006E2D8
    // 0x8006DD90: sw          $zero, 0x34F0($at)
    MEM_W(0X34F0, ctx->r1) = 0;
        goto L_8006E2D8;
    // 0x8006DD90: sw          $zero, 0x34F0($at)
    MEM_W(0X34F0, ctx->r1) = 0;
L_8006DD94:
    // 0x8006DD94: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8006DD98: beq         $v0, $v1, L_8006DE90
    if (ctx->r2 == ctx->r3) {
        // 0x8006DD9C: andi        $t4, $v0, 0x200
        ctx->r12 = ctx->r2 & 0X200;
            goto L_8006DE90;
    }
    // 0x8006DD9C: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x8006DDA0: beq         $t4, $zero, L_8006DE90
    if (ctx->r12 == 0) {
        // 0x8006DDA4: nop
    
            goto L_8006DE90;
    }
    // 0x8006DDA4: nop

    // 0x8006DDA8: jal         0x8006DBE4
    // 0x8006DDAC: nop

    unload_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006DDAC: nop

    after_2:
    // 0x8006DDB0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006DDB4: lw          $t5, 0x34E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X34E8);
    // 0x8006DDB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DDBC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006DDC0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006DDC4: lw          $t7, 0x11F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F0);
    // 0x8006DDC8: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006DDCC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006DDD0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006DDD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006DDD8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006DDDC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006DDE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006DDE4: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006DDE8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006DDEC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006DDF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006DDF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006DDF8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DDFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006DE00: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006DE04: andi        $a0, $t6, 0x7F
    ctx->r4 = ctx->r14 & 0X7F;
    // 0x8006DE08: jal         0x8006B0AC
    // 0x8006DE0C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x8006DE0C: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    after_3:
    // 0x8006DE10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006DE14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006DE18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006DE1C: addiu       $t3, $t3, 0x3508
    ctx->r11 = ADD32(ctx->r11, 0X3508);
    // 0x8006DE20: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006DE24: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006DE28: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006DE2C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006DE30: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006DE34: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8006DE38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DE3C: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006DE40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DE44: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    // 0x8006DE48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DE4C: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    // 0x8006DE50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006DE54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006DE58: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006DE5C: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006DE60: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006DE64: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006DE68: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006DE6C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006DE70: jal         0x8006CB58
    // 0x8006DE74: nop

    load_level_game(rdram, ctx);
        goto after_4;
    // 0x8006DE74: nop

    after_4:
    // 0x8006DE78: jal         0x8009C1A0
    // 0x8006DE7C: nop

    get_save_file_index(rdram, ctx);
        goto after_5;
    // 0x8006DE7C: nop

    after_5:
    // 0x8006DE80: jal         0x8006EC48
    // 0x8006DE84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_6;
    // 0x8006DE84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006DE88: b           L_8006E2DC
    // 0x8006DE8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006DE8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006DE90:
    // 0x8006DE90: beq         $v0, $v1, L_8006E0F8
    if (ctx->r2 == ctx->r3) {
        // 0x8006DE94: andi        $t9, $v0, 0x100
        ctx->r25 = ctx->r2 & 0X100;
            goto L_8006E0F8;
    }
    // 0x8006DE94: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x8006DE98: beq         $t9, $zero, L_8006E0FC
    if (ctx->r25 == 0) {
        // 0x8006DE9C: andi        $t4, $v0, 0x80
        ctx->r12 = ctx->r2 & 0X80;
            goto L_8006E0FC;
    }
    // 0x8006DE9C: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x8006DEA0: jal         0x8006CC14
    // 0x8006DEA4: nop

    unload_level_game(rdram, ctx);
        goto after_7;
    // 0x8006DEA4: nop

    after_7:
    // 0x8006DEA8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DEAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DEB0: sb          $zero, 0x3515($at)
    MEM_B(0X3515, ctx->r1) = 0;
    // 0x8006DEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DEB8: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x8006DEBC: sb          $zero, 0x3516($at)
    MEM_B(0X3516, ctx->r1) = 0;
    // 0x8006DEC0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006DEC4: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x8006DEC8: beq         $at, $zero, L_8006E0E0
    if (ctx->r1 == 0) {
        // 0x8006DECC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8006E0E0;
    }
    // 0x8006DECC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006DED0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006DED4: addu        $at, $at, $t6
    gpr jr_addend_8006DEE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006DED8: lw          $t6, 0x71D8($at)
    ctx->r14 = ADD32(ctx->r1, 0X71D8);
    // 0x8006DEDC: nop

    // 0x8006DEE0: jr          $t6
    // 0x8006DEE4: nop

    switch (jr_addend_8006DEE0 >> 2) {
        case 0: goto L_8006DF70; break;
        case 1: goto L_8006E00C; break;
        case 2: goto L_8006E054; break;
        case 3: goto L_8006E0E0; break;
        case 4: goto L_8006DEE8; break;
        case 5: goto L_8006E0E0; break;
        case 6: goto L_8006E0E0; break;
        case 7: goto L_8006E0E0; break;
        case 8: goto L_8006E0E0; break;
        case 9: goto L_8006E0E0; break;
        case 10: goto L_8006E0E0; break;
        case 11: goto L_8006E0E0; break;
        case 12: goto L_8006E0E0; break;
        case 13: goto L_8006DF00; break;
        default: switch_error(__func__, 0x8006DEE0, 0x800E71D8);
    }
    // 0x8006DEE4: nop

L_8006DEE8:
    // 0x8006DEE8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8006DEEC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DEF0: jal         0x8006DA28
    // 0x8006DEF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_menu_with_level_background(rdram, ctx);
        goto after_8;
    // 0x8006DEF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x8006DEF8: b           L_8006E2DC
    // 0x8006DEFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006DEFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006DF00:
    // 0x8006DF00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006DF04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006DF08: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006DF0C: addiu       $t3, $t3, 0x3508
    ctx->r11 = ADD32(ctx->r11, 0X3508);
    // 0x8006DF10: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006DF14: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006DF18: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006DF1C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006DF20: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006DF24: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8006DF28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DF2C: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006DF30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006DF34: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006DF38: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006DF3C: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006DF40: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006DF44: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006DF48: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006DF4C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006DF50: jal         0x8006CB58
    // 0x8006DF54: nop

    load_level_game(rdram, ctx);
        goto after_9;
    // 0x8006DF54: nop

    after_9:
    // 0x8006DF58: jal         0x8009C1A0
    // 0x8006DF5C: nop

    get_save_file_index(rdram, ctx);
        goto after_10;
    // 0x8006DF5C: nop

    after_10:
    // 0x8006DF60: jal         0x8006EC48
    // 0x8006DF64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_11;
    // 0x8006DF64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8006DF68: b           L_8006E2DC
    // 0x8006DF6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006DF6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006DF70:
    // 0x8006DF70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DF74: addiu       $a1, $a1, 0x1250
    ctx->r5 = ADD32(ctx->r5, 0X1250);
    // 0x8006DF78: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8006DF7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006DF80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006DF84: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006DF88: addiu       $t3, $t3, 0x3508
    ctx->r11 = ADD32(ctx->r11, 0X3508);
    // 0x8006DF8C: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006DF90: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006DF94: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006DF98: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8006DF9C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8006DFA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DFA4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006DFA8: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006DFAC: lb          $v0, 0xF($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XF);
    // 0x8006DFB0: lb          $v1, 0x1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1);
    // 0x8006DFB4: bltz        $v0, L_8006DFC0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006DFB8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8006DFC0;
    }
    // 0x8006DFB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006DFBC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_8006DFC0:
    // 0x8006DFC0: addu        $t4, $a1, $v1
    ctx->r12 = ADD32(ctx->r5, ctx->r3);
    // 0x8006DFC4: lb          $v0, 0x8($t4)
    ctx->r2 = MEM_B(ctx->r12, 0X8);
    // 0x8006DFC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006DFCC: bltz        $v0, L_8006DFD8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006DFD0: addiu       $v1, $v1, 0x3500
        ctx->r3 = ADD32(ctx->r3, 0X3500);
            goto L_8006DFD8;
    }
    // 0x8006DFD0: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006DFD4: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_8006DFD8:
    // 0x8006DFD8: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006DFDC: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006DFE0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006DFE4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006DFE8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006DFEC: jal         0x8006CB58
    // 0x8006DFF0: nop

    load_level_game(rdram, ctx);
        goto after_12;
    // 0x8006DFF0: nop

    after_12:
    // 0x8006DFF4: jal         0x8009C1A0
    // 0x8006DFF8: nop

    get_save_file_index(rdram, ctx);
        goto after_13;
    // 0x8006DFF8: nop

    after_13:
    // 0x8006DFFC: jal         0x8006EC48
    // 0x8006E000: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_14;
    // 0x8006E000: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8006E004: b           L_8006E2DC
    // 0x8006E008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006E008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E00C:
    // 0x8006E00C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E010: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006E014: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E018: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E01C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E020: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E024: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006E028: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006E02C: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006E030: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006E034: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E038: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E03C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E040: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8006E044: jal         0x8006CB58
    // 0x8006E048: nop

    load_level_game(rdram, ctx);
        goto after_15;
    // 0x8006E048: nop

    after_15:
    // 0x8006E04C: b           L_8006E2DC
    // 0x8006E050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006E050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E054:
    // 0x8006E054: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E058: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E05C: addiu       $a1, $a1, 0x1250
    ctx->r5 = ADD32(ctx->r5, 0X1250);
    // 0x8006E060: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006E064: lb          $t7, 0x1($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1);
    // 0x8006E068: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006E06C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8006E070: lb          $t6, 0xF($a1)
    ctx->r14 = MEM_B(ctx->r5, 0XF);
    // 0x8006E074: lb          $t9, 0x8($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X8);
    // 0x8006E078: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E07C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E080: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E084: addiu       $t3, $t3, 0x3508
    ctx->r11 = ADD32(ctx->r11, 0X3508);
    // 0x8006E088: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006E08C: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006E090: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8006E094: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8006E098: jal         0x8006B0AC
    // 0x8006E09C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    leveltable_vehicle_default(rdram, ctx);
        goto after_16;
    // 0x8006E09C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    after_16:
    // 0x8006E0A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E0A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E0A8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E0AC: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006E0B0: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006E0B4: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006E0B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E0BC: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006E0C0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8006E0C4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E0C8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E0CC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8006E0D0: jal         0x8006CB58
    // 0x8006E0D4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_17;
    // 0x8006E0D4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x8006E0D8: b           L_8006E2DC
    // 0x8006E0DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006E0DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E0E0:
    // 0x8006E0E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E0E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006E0E8: jal         0x8006DA28
    // 0x8006E0EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_menu_with_level_background(rdram, ctx);
        goto after_18;
    // 0x8006E0EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x8006E0F0: b           L_8006E2DC
    // 0x8006E0F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8006E2DC;
    // 0x8006E0F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E0F8:
    // 0x8006E0F8: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
L_8006E0FC:
    // 0x8006E0FC: beq         $t4, $zero, L_8006E21C
    if (ctx->r12 == 0) {
        // 0x8006E100: nop
    
            goto L_8006E21C;
    }
    // 0x8006E100: nop

    // 0x8006E104: beq         $v0, $v1, L_8006E21C
    if (ctx->r2 == ctx->r3) {
        // 0x8006E108: nop
    
            goto L_8006E21C;
    }
    // 0x8006E108: nop

    // 0x8006E10C: jal         0x8006DBE4
    // 0x8006E110: nop

    unload_level_menu(rdram, ctx);
        goto after_19;
    // 0x8006E110: nop

    after_19:
    // 0x8006E114: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E118: lw          $t5, 0x34E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X34E8);
    // 0x8006E11C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E120: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006E124: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006E128: lw          $t7, 0x11F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F0);
    // 0x8006E12C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E130: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006E134: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8006E138: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E13C: lui         $t9, 0xE900
    ctx->r25 = S32(0XE900 << 16);
    // 0x8006E140: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8006E144: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8006E148: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E14C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006E150: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006E154: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8006E158: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E15C: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006E160: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006E164: addiu       $a1, $a1, 0x1250
    ctx->r5 = ADD32(ctx->r5, 0X1250);
    // 0x8006E168: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8006E16C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E170: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006E174: andi        $t6, $t2, 0x7F
    ctx->r14 = ctx->r10 & 0X7F;
    // 0x8006E178: sb          $t6, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r14;
    // 0x8006E17C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8006E180: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8006E184: lb          $t8, 0x2($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2);
    // 0x8006E188: lb          $t9, 0x4($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X4);
    // 0x8006E18C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E190: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006E194: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E198: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8006E19C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8006E1A0: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006E1A4: lb          $t4, 0xC($v1)
    ctx->r12 = MEM_B(ctx->r3, 0XC);
    // 0x8006E1A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006E1AC: addiu       $t3, $t3, 0x3508
    ctx->r11 = ADD32(ctx->r11, 0X3508);
    // 0x8006E1B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006E1B4: jal         0x8009C250
    // 0x8006E1B8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    get_player_selected_vehicle(rdram, ctx);
        goto after_20;
    // 0x8006E1B8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    after_20:
    // 0x8006E1BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E1C0: addiu       $s0, $s0, 0x3510
    ctx->r16 = ADD32(ctx->r16, 0X3510);
    // 0x8006E1C4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E1C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006E1CC: lbu         $t6, 0x4A($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X4A);
    // 0x8006E1D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006E1D4: addiu       $t1, $t1, 0x3504
    ctx->r9 = ADD32(ctx->r9, 0X3504);
    // 0x8006E1D8: addiu       $t0, $t0, 0x34F4
    ctx->r8 = ADD32(ctx->r8, 0X34F4);
    // 0x8006E1DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E1E0: addiu       $v1, $v1, 0x3500
    ctx->r3 = ADD32(ctx->r3, 0X3500);
    // 0x8006E1E4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006E1E8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x8006E1EC: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8006E1F0: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8006E1F4: jal         0x8006CB58
    // 0x8006E1F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    load_level_game(rdram, ctx);
        goto after_21;
    // 0x8006E1F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x8006E1FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006E200: lw          $t8, 0x351C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X351C);
    // 0x8006E204: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E208: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E20C: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006E210: sw          $zero, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = 0;
    // 0x8006E214: b           L_8006E2D8
    // 0x8006E218: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
        goto L_8006E2D8;
    // 0x8006E218: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8006E21C:
    // 0x8006E21C: blez        $v0, L_8006E2DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006E220: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E2DC;
    }
    // 0x8006E220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E224: jal         0x8006DBE4
    // 0x8006E228: nop

    unload_level_menu(rdram, ctx);
        goto after_22;
    // 0x8006E228: nop

    after_22:
    // 0x8006E22C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E230: lw          $t9, 0x34E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X34E8);
    // 0x8006E234: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006E238: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006E23C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8006E240: lw          $t5, 0x11F0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11F0);
    // 0x8006E244: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x8006E248: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8006E24C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8006E250: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8006E254: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8006E258: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8006E25C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006E260: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8006E264: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006E268: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006E26C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E270: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006E274: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006E278: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E27C: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x8006E280: sw          $zero, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = 0;
    // 0x8006E284: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006E288: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E28C: jal         0x8006CAE4
    // 0x8006E290: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_next_ingame_level(rdram, ctx);
        goto after_23;
    // 0x8006E290: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_23:
    // 0x8006E294: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E298: addiu       $s0, $s0, 0x3510
    ctx->r16 = ADD32(ctx->r16, 0X3510);
    // 0x8006E29C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E2A0: nop

    // 0x8006E2A4: lbu         $t5, 0x4B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X4B);
    // 0x8006E2A8: nop

    // 0x8006E2AC: beq         $t5, $zero, L_8006E2DC
    if (ctx->r13 == 0) {
        // 0x8006E2B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E2DC;
    }
    // 0x8006E2B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E2B4: jal         0x8009C2D0
    // 0x8006E2B8: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_24;
    // 0x8006E2B8: nop

    after_24:
    // 0x8006E2BC: bne         $v0, $zero, L_8006E2DC
    if (ctx->r2 != 0) {
        // 0x8006E2C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006E2DC;
    }
    // 0x8006E2C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006E2C4: jal         0x80000B28
    // 0x8006E2C8: nop

    music_change_on(rdram, ctx);
        goto after_25;
    // 0x8006E2C8: nop

    after_25:
    // 0x8006E2CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E2D0: nop

    // 0x8006E2D4: sb          $zero, 0x4B($t6)
    MEM_B(0X4B, ctx->r14) = 0;
L_8006E2D8:
    // 0x8006E2D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006E2DC:
    // 0x8006E2DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006E2E0: jr          $ra
    // 0x8006E2E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006E2E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5EDC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B5EE0: lw          $t6, -0x7A28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7A28);
    // 0x800B5EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B5EE8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B5EEC: addiu       $t7, $t7, 0x7CD8
    ctx->r15 = ADD32(ctx->r15, 0X7CD8);
    // 0x800B5EF0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B5EF4: slti        $at, $t8, 0x801
    ctx->r1 = SIGNED(ctx->r24) < 0X801 ? 1 : 0;
    // 0x800B5EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5EFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B5F00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B5F04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B5F08: bne         $at, $zero, L_800B5F18
    if (ctx->r1 != 0) {
        // 0x800B5F0C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800B5F18;
    }
    // 0x800B5F0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B5F10: b           L_800B5F68
    // 0x800B5F14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B5F68;
    // 0x800B5F14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B5F18:
    // 0x800B5F18: jal         0x800B4A08
    // 0x800B5F1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B5F1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800B5F20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B5F24: lw          $a0, -0x7A28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A28);
    // 0x800B5F28: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B5F2C: jal         0x800B4A40
    // 0x800B5F30: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B5F30: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800B5F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B5F38: jal         0x800B4A08
    // 0x800B5F3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B5F3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800B5F40: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800B5F44: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B5F48: blez        $v1, L_800B5F64
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B5F4C: addiu       $v0, $v0, -0x7A28
        ctx->r2 = ADD32(ctx->r2, -0X7A28);
            goto L_800B5F64;
    }
    // 0x800B5F4C: addiu       $v0, $v0, -0x7A28
    ctx->r2 = ADD32(ctx->r2, -0X7A28);
    // 0x800B5F50: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B5F54: nop

    // 0x800B5F58: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B5F5C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B5F60: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B5F64:
    // 0x800B5F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5F68:
    // 0x800B5F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5F6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5F70: jr          $ra
    // 0x800B5F74: nop

    return;
    // 0x800B5F74: nop

;}
RECOMP_FUNC void func_80080580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080580: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80080584: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80080588: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8008058C: addiu       $fp, $fp, 0x1DB8
    ctx->r30 = ADD32(ctx->r30, 0X1DB8);
    // 0x80080590: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80080594: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080598: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8008059C: lw          $t6, 0x6C2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C2C);
    // 0x800805A0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800805A4: lw          $t7, 0x1DB4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1DB4);
    // 0x800805A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800805AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800805B0: lw          $s3, 0xE0($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XE0);
    // 0x800805B4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800805B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800805BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800805C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800805C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800805C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800805CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800805D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800805D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800805D8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800805DC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800805E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800805E4: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800805E8: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800805EC: beq         $s3, $zero, L_80080808
    if (ctx->r19 == 0) {
        // 0x800805F0: sw          $s3, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->r19;
            goto L_80080808;
    }
    // 0x800805F0: sw          $s3, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r19;
    // 0x800805F4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800805F8: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x800805FC: lw          $a1, 0x1DC0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1DC0);
    // 0x80080600: subu        $t9, $a3, $t3
    ctx->r25 = SUB32(ctx->r7, ctx->r11);
    // 0x80080604: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080608: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008060C: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080610: lw          $a2, 0x1DC4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1DC4);
    // 0x80080614: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080618: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // 0x8008061C: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x80080620: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080624: addiu       $v0, $v0, 0x1CF0
    ctx->r2 = ADD32(ctx->r2, 0X1CF0);
    // 0x80080628: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8008062C: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80080630: mflo        $t7
    ctx->r15 = lo;
    // 0x80080634: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80080638: nop

    // 0x8008063C: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080640: subu        $t9, $t5, $t4
    ctx->r25 = SUB32(ctx->r13, ctx->r12);
    // 0x80080644: mflo        $t6
    ctx->r14 = lo;
    // 0x80080648: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x8008064C: nop

    // 0x80080650: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080654: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x80080658: mflo        $t8
    ctx->r24 = lo;
    // 0x8008065C: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80080660: nop

    // 0x80080664: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080668: mflo        $t7
    ctx->r15 = lo;
    // 0x8008066C: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x80080670: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80080674: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080678: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x8008067C: lw          $t7, 0x6C2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C2C);
    // 0x80080680: mflo        $t6
    ctx->r14 = lo;
    // 0x80080684: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80080688: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8008068C: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080690: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080694: lw          $t9, 0x1DB4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1DB4);
    // 0x80080698: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8008069C: mflo        $t8
    ctx->r24 = lo;
    // 0x800806A0: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x800806A4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800806A8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800806AC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800806B0: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x800806B4: nop

L_800806B8:
    // 0x800806B8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800806BC: addiu       $ra, $ra, 0x2
    ctx->r31 = ADD32(ctx->r31, 0X2);
    // 0x800806C0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800806C4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800806C8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800806CC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800806D0: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800806D4: lbu         $t9, -0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XB);
    // 0x800806D8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800806DC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800806E0: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800806E4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800806E8: nop

    // 0x800806EC: sh          $t6, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r14;
    // 0x800806F0: lbu         $t9, -0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XA);
    // 0x800806F4: nop

    // 0x800806F8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800806FC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080700: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080704: nop

    // 0x80080708: sh          $t6, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r14;
    // 0x8008070C: lbu         $t9, -0x9($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X9);
    // 0x80080710: nop

    // 0x80080714: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080718: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x8008071C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080720: nop

    // 0x80080724: sh          $t6, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r14;
    // 0x80080728: lbu         $t9, -0x8($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X8);
    // 0x8008072C: nop

    // 0x80080730: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080734: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080738: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8008073C: nop

    // 0x80080740: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x80080744: lbu         $t9, -0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X7);
    // 0x80080748: nop

    // 0x8008074C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080750: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80080754: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080758: nop

    // 0x8008075C: sh          $t6, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r14;
    // 0x80080760: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80080764: nop

    // 0x80080768: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8008076C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80080770: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080774: nop

    // 0x80080778: sh          $t6, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r14;
    // 0x8008077C: lbu         $t9, -0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X5);
    // 0x80080780: nop

    // 0x80080784: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80080788: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x8008078C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080790: nop

    // 0x80080794: sh          $t6, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r14;
    // 0x80080798: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x8008079C: nop

    // 0x800807A0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800807A4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800807A8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800807AC: nop

    // 0x800807B0: sh          $t6, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r14;
    // 0x800807B4: lbu         $t9, -0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X3);
    // 0x800807B8: nop

    // 0x800807BC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800807C0: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800807C4: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800807C8: nop

    // 0x800807CC: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x800807D0: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800807D4: nop

    // 0x800807D8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800807DC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800807E0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800807E4: nop

    // 0x800807E8: sh          $t6, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r14;
    // 0x800807EC: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800807F0: nop

    // 0x800807F4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800807F8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800807FC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80080800: bne         $ra, $a2, L_800806B8
    if (ctx->r31 != ctx->r6) {
        // 0x80080804: sh          $t6, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r14;
            goto L_800806B8;
    }
    // 0x80080804: sh          $t6, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r14;
L_80080808:
    // 0x80080808: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8008080C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080810: sra         $s3, $a0, 24
    ctx->r19 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80080814: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80080818: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8008081C: sra         $s4, $a0, 16
    ctx->r20 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80080820: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80080824: andi        $t8, $s4, 0xFF
    ctx->r24 = ctx->r20 & 0XFF;
    // 0x80080828: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x8008082C: sra         $s5, $a0, 8
    ctx->r21 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80080830: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x80080834: lw          $t6, 0x6C2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C2C);
    // 0x80080838: andi        $t7, $s5, 0xFF
    ctx->r15 = ctx->r21 & 0XFF;
    // 0x8008083C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80080840: lw          $t9, 0x1DB4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1DB4);
    // 0x80080844: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x80080848: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8008084C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80080850: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080854: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80080858: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008085C: lw          $t3, 0xD4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD4);
    // 0x80080860: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80080864: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x80080868: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8008086C: addiu       $v1, $v1, 0x1D2C
    ctx->r3 = ADD32(ctx->r3, 0X1D2C);
    // 0x80080870: addiu       $t2, $t2, 0x1D7C
    ctx->r10 = ADD32(ctx->r10, 0X1D7C);
    // 0x80080874: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080878: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8008087C: andi        $s6, $a0, 0xFF
    ctx->r22 = ctx->r4 & 0XFF;
L_80080880:
    // 0x80080880: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x80080884: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80080888: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008088C: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80080890: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80080894: slti        $at, $ra, 0x5
    ctx->r1 = SIGNED(ctx->r31) < 0X5 ? 1 : 0;
    // 0x80080898: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x8008089C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800808A0: mflo        $a1
    ctx->r5 = lo;
    // 0x800808A4: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800808A8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800808AC: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800808B0: lh          $t6, -0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, -0X2);
    // 0x800808B4: mflo        $a2
    ctx->r6 = lo;
    // 0x800808B8: sra         $t8, $a2, 8
    ctx->r24 = S32(SIGNED(ctx->r6) >> 8);
    // 0x800808BC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800808C0: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800808C4: mflo        $a3
    ctx->r7 = lo;
    // 0x800808C8: sra         $t7, $a3, 8
    ctx->r15 = S32(SIGNED(ctx->r7) >> 8);
    // 0x800808CC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800808D0: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800808D4: mflo        $t0
    ctx->r8 = lo;
    // 0x800808D8: sra         $t8, $t0, 8
    ctx->r24 = S32(SIGNED(ctx->r8) >> 8);
    // 0x800808DC: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_800808E0:
    // 0x800808E0: sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
    // 0x800808E4: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x800808E8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800808EC: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800808F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800808F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800808F8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800808FC: mflo        $t6
    ctx->r14 = lo;
    // 0x80080900: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080904: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080908: lb          $t9, -0x3($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X3);
    // 0x8008090C: lh          $t7, -0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, -0XA);
    // 0x80080910: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080914: sh          $s2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r18;
    // 0x80080918: lh          $t9, -0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X8);
    // 0x8008091C: mflo        $t6
    ctx->r14 = lo;
    // 0x80080920: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080924: sh          $t8, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r24;
    // 0x80080928: lb          $t7, -0x2($v1)
    ctx->r15 = MEM_B(ctx->r3, -0X2);
    // 0x8008092C: nop

    // 0x80080930: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80080934: mflo        $t6
    ctx->r14 = lo;
    // 0x80080938: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8008093C: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080940: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x80080944: lh          $t7, -0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X8);
    // 0x80080948: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008094C: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x80080950: sb          $a1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r5;
    // 0x80080954: sb          $a2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r6;
    // 0x80080958: sb          $a3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r7;
    // 0x8008095C: sb          $t0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r8;
    // 0x80080960: mflo        $t6
    ctx->r14 = lo;
    // 0x80080964: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80080968: bne         $a0, $t1, L_800808E0
    if (ctx->r4 != ctx->r9) {
        // 0x8008096C: sh          $t8, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r24;
            goto L_800808E0;
    }
    // 0x8008096C: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x80080970: bne         $at, $zero, L_80080880
    if (ctx->r1 != 0) {
        // 0x80080974: nop
    
            goto L_80080880;
    }
    // 0x80080974: nop

    // 0x80080978: beq         $s7, $zero, L_80080B68
    if (ctx->r23 == 0) {
        // 0x8008097C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80080B68;
    }
    // 0x8008097C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80080980: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80080984: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080988: addiu       $t0, $t0, 0x6C2C
    ctx->r8 = ADD32(ctx->r8, 0X6C2C);
    // 0x8008098C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080990: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80080994: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80080998: addiu       $a3, $a3, 0x1DB4
    ctx->r7 = ADD32(ctx->r7, 0X1DB4);
    // 0x8008099C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800809A0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800809A4: lw          $a2, 0xE0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE0);
    // 0x800809A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800809AC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800809B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800809B4: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x800809B8: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800809BC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800809C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800809C4: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x800809C8: addiu       $t9, $t9, 0x1C70
    ctx->r25 = ADD32(ctx->r25, 0X1C70);
    // 0x800809CC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800809D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800809D4: beq         $a2, $zero, L_80080A48
    if (ctx->r6 == 0) {
        // 0x800809D8: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_80080A48;
    }
    // 0x800809D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800809DC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800809E0: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x800809E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800809E8: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x800809EC: lui         $t8, 0xE
    ctx->r24 = S32(0XE << 16);
    // 0x800809F0: addiu       $t8, $t8, 0x1CB0
    ctx->r24 = ADD32(ctx->r24, 0X1CB0);
    // 0x800809F4: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800809F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800809FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80080A00: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080A04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80080A08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80080A0C: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
    // 0x80080A10: lh          $a1, 0xA($a2)
    ctx->r5 = MEM_H(ctx->r6, 0XA);
    // 0x80080A14: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080A18: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80080A1C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80080A20: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x80080A24: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80080A28: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80080A2C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80080A30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080A34: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80080A38: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80080A3C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80080A40: b           L_80080A74
    // 0x80080A44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80080A74;
    // 0x80080A44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80080A48:
    // 0x80080A48: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080A4C: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x80080A50: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80080A54: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80080A58: lui         $t9, 0xE
    ctx->r25 = S32(0XE << 16);
    // 0x80080A5C: addiu       $t9, $t9, 0x1CA0
    ctx->r25 = ADD32(ctx->r25, 0X1CA0);
    // 0x80080A60: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80080A64: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80080A68: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80080A6C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80080A70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80080A74:
    // 0x80080A74: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080A78: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80080A7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080A80: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080A84: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080A88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080A8C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080A90: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80080A94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80080A98: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x80080A9C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080AA0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80080AA4: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080AA8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80080AAC: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x80080AB0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80080AB4: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80080AB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80080ABC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80080AC0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80080AC4: andi        $t9, $t6, 0x6
    ctx->r25 = ctx->r14 & 0X6;
    // 0x80080AC8: ori         $t7, $t9, 0x98
    ctx->r15 = ctx->r25 | 0X98;
    // 0x80080ACC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80080AD0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80080AD4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80080AD8: ori         $t7, $t9, 0x170
    ctx->r15 = ctx->r25 | 0X170;
    // 0x80080ADC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80080AE0: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80080AE4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80080AE8: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x80080AEC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80080AF0: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80080AF4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80080AF8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80080AFC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80080B00: ori         $t9, $ra, 0x90
    ctx->r25 = ctx->r31 | 0X90;
    // 0x80080B04: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80080B08: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80080B0C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80080B10: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80080B14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80080B18: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80080B1C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80080B20: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80080B24: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80080B28: ori         $t9, $t8, 0xA0
    ctx->r25 = ctx->r24 | 0XA0;
    // 0x80080B2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80080B30: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80080B34: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80080B38: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80080B3C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080B40: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80080B44: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80080B48: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80080B4C: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80080B50: nop

    // 0x80080B54: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80080B58: jal         0x8007B3D0
    // 0x80080B5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80080B5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x80080B60: b           L_80080B90
    // 0x80080B64: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
        goto L_80080B90;
    // 0x80080B64: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080B68:
    // 0x80080B68: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80080B6C: lw          $t6, 0x6C2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C2C);
    // 0x80080B70: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x80080B74: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80080B78: lw          $t8, 0x1DB4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1DB4);
    // 0x80080B7C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80080B80: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80080B84: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80080B88: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x80080B8C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
L_80080B90:
    // 0x80080B90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80080B94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80080B98: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x80080B9C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80080BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080BA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80080BA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80080BAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80080BB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80080BB4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80080BB8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80080BBC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80080BC0: jr          $ra
    // 0x80080BC4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80080BC4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void obj_loop_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AE50: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8003AE54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003AE58: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8003AE5C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8003AE60: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8003AE64: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8003AE68: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8003AE6C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8003AE70: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003AE74: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003AE78: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003AE7C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8003AE80: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003AE84: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8003AE88: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8003AE8C: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003AE90: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003AE94: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8003AE98: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003AE9C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8003AEA0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003AEA4: beq         $at, $zero, L_8003B01C
    if (ctx->r1 == 0) {
        // 0x8003AEA8: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_8003B01C;
    }
    // 0x8003AEA8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8003AEAC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003AEB0: jal         0x8001BA74
    // 0x8003AEB4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003AEB4: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003AEB8: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003AEBC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003AEC0: blez        $t8, L_8003B01C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003AEC4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_8003B01C;
    }
    // 0x8003AEC4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8003AEC8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003AECC: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8003AED0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8003AED4:
    // 0x8003AED4: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x8003AED8: lbu         $t9, 0x14($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AEDC: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003AEE0: nop

    // 0x8003AEE4: lb          $t0, 0x1D6($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X1D6);
    // 0x8003AEE8: nop

    // 0x8003AEEC: beq         $t9, $t0, L_8003B00C
    if (ctx->r25 == ctx->r8) {
        // 0x8003AEF0: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B00C;
    }
    // 0x8003AEF0: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AEF4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AEF8: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8003AEFC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AF00: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003AF04: lwc1        $f16, 0x10($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8003AF08: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003AF0C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003AF10: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF14: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8003AF18: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003AF1C: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003AF20: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003AF24: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003AF28: jal         0x800C9AD0
    // 0x8003AF2C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003AF2C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x8003AF30: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003AF34: nop

    // 0x8003AF38: bc1f        L_8003B00C
    if (!c1cs) {
        // 0x8003AF3C: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B00C;
    }
    // 0x8003AF3C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF40: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003AF44: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AF48: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003AF4C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003AF50: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003AF54: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003AF58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003AF5C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003AF60: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003AF64: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003AF68: nop

    // 0x8003AF6C: bc1f        L_8003B00C
    if (!c1cs) {
        // 0x8003AF70: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_8003B00C;
    }
    // 0x8003AF70: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003AF74: sb          $zero, 0x1E0($s1)
    MEM_B(0X1E0, ctx->r17) = 0;
    // 0x8003AF78: lbu         $v0, 0x14($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AF7C: nop

    // 0x8003AF80: bne         $v0, $zero, L_8003AF94
    if (ctx->r2 != 0) {
        // 0x8003AF84: nop
    
            goto L_8003AF94;
    }
    // 0x8003AF84: nop

    // 0x8003AF88: lb          $t1, 0x1D7($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D7);
    // 0x8003AF8C: b           L_8003AF98
    // 0x8003AF90: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
        goto L_8003AF98;
    // 0x8003AF90: sb          $t1, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r9;
L_8003AF94:
    // 0x8003AF94: sb          $v0, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r2;
L_8003AF98:
    // 0x8003AF98: lbu         $t2, 0x14($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X14);
    // 0x8003AF9C: nop

    // 0x8003AFA0: bne         $s6, $t2, L_8003AFFC
    if (ctx->r22 != ctx->r10) {
        // 0x8003AFA4: nop
    
            goto L_8003AFFC;
    }
    // 0x8003AFA4: nop

    // 0x8003AFA8: lb          $t3, 0x1D8($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X1D8);
    // 0x8003AFAC: nop

    // 0x8003AFB0: bne         $t3, $zero, L_8003AFC4
    if (ctx->r11 != 0) {
        // 0x8003AFB4: nop
    
            goto L_8003AFC4;
    }
    // 0x8003AFB4: nop

    // 0x8003AFB8: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8003AFBC: jal         0x80072348
    // 0x8003AFC0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_2;
    // 0x8003AFC0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_8003AFC4:
    // 0x8003AFC4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AFC8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AFCC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AFD0: jal         0x8001C524
    // 0x8003AFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_3;
    // 0x8003AFD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8003AFD8: beq         $v0, $s7, L_8003AFF0
    if (ctx->r2 == ctx->r23) {
        // 0x8003AFDC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003AFF0;
    }
    // 0x8003AFDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003AFE0: jal         0x8001D214
    // 0x8003AFE4: nop

    ainode_get(rdram, ctx);
        goto after_4;
    // 0x8003AFE4: nop

    after_4:
    // 0x8003AFE8: b           L_8003AFF4
    // 0x8003AFEC: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
        goto L_8003AFF4;
    // 0x8003AFEC: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
L_8003AFF0:
    // 0x8003AFF0: sw          $zero, 0x158($s1)
    MEM_W(0X158, ctx->r17) = 0;
L_8003AFF4:
    // 0x8003AFF4: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x8003AFF8: sh          $zero, 0x19A($s1)
    MEM_H(0X19A, ctx->r17) = 0;
L_8003AFFC:
    // 0x8003AFFC: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x8003B000: nop

    // 0x8003B004: sh          $t4, 0x198($s1)
    MEM_H(0X198, ctx->r17) = ctx->r12;
    // 0x8003B008: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
L_8003B00C:
    // 0x8003B00C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8003B010: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8003B014: bne         $at, $zero, L_8003AED4
    if (ctx->r1 != 0) {
        // 0x8003B018: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8003AED4;
    }
    // 0x8003B018: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8003B01C:
    // 0x8003B01C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003B020: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003B024: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8003B028: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003B02C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003B030: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003B034: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003B038: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B03C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8003B040: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003B044: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8003B048: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B04C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8003B050: jr          $ra
    // 0x8003B054: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003B054: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void is_adventure_two_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009EC64: lw          $t7, 0x644C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X644C);
    // 0x8009EC68: jr          $ra
    // 0x8009EC6C: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
    return;
    // 0x8009EC6C: andi        $v0, $t7, 0x1
    ctx->r2 = ctx->r15 & 0X1;
;}
RECOMP_FUNC void create_point_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0698: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B069C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B06A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B06A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B06A8: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B06AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B06B0: lw          $t6, 0x2CF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CF0);
    // 0x800B06B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B06B8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B06BC: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x800B06C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B06C4: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800B06C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B06CC: beq         $t0, $at, L_800B06DC
    if (ctx->r8 == ctx->r1) {
        // 0x800B06D0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B06DC;
    }
    // 0x800B06D0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B06D4: b           L_800B0B9C
    // 0x800B06D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0B9C;
    // 0x800B06D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B06DC:
    // 0x800B06DC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800B06E0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B06E4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B06E8: jal         0x800B1CB8
    // 0x800B06EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B06EC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B06F0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B06F4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B06F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B06FC: bne         $v0, $zero, L_800B070C
    if (ctx->r2 != 0) {
        // 0x800B0700: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B070C;
    }
    // 0x800B0700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B0704: b           L_800B0B9C
    // 0x800B0708: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B0B9C;
    // 0x800B0708: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B070C:
    // 0x800B070C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800B0710: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B0714: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B0718: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B071C: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B0720: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x800B0724: nop

    // 0x800B0728: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B072C: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x800B0730: nop

    // 0x800B0734: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B0738: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800B073C: sw          $a2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r6;
    // 0x800B0740: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x800B0744: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0748: lwc1        $f6, 0x50($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800B074C: andi        $t3, $t5, 0x800
    ctx->r11 = ctx->r13 & 0X800;
    // 0x800B0750: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0754: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0758: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B075C: lwc1        $f16, 0x54($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800B0760: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800B0764: nop

    // 0x800B0768: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B076C: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B0770: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800B0774: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B0778: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B077C: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B0780: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x800B0784: nop

    // 0x800B0788: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B078C: lbu         $t9, 0x15($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X15);
    // 0x800B0790: nop

    // 0x800B0794: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B0798: lbu         $t0, 0x16($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X16);
    // 0x800B079C: nop

    // 0x800B07A0: sb          $t0, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r8;
    // 0x800B07A4: lbu         $t1, 0x17($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X17);
    // 0x800B07A8: beq         $t3, $zero, L_800B0804
    if (ctx->r11 == 0) {
        // 0x800B07AC: sb          $t1, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r9;
            goto L_800B0804;
    }
    // 0x800B07AC: sb          $t1, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r9;
    // 0x800B07B0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800B07B4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B07B8: lw          $a0, 0x54($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X54);
    // 0x800B07BC: nop

    // 0x800B07C0: beq         $a0, $zero, L_800B0804
    if (ctx->r4 == 0) {
        // 0x800B07C4: nop
    
            goto L_800B0804;
    }
    // 0x800B07C4: nop

    // 0x800B07C8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B07CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B07D0: nop

    // 0x800B07D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B07D8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B07DC: nop

    // 0x800B07E0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B07E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B07E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B07EC: nop

    // 0x800B07F0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B07F4: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800B07F8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B07FC: b           L_800B080C
    // 0x800B0800: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
        goto L_800B080C;
    // 0x800B0800: sh          $t7, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r15;
L_800B0804:
    // 0x800B0804: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800B0808: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B080C:
    // 0x800B080C: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x800B0810: nop

    // 0x800B0814: sh          $t8, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r24;
    // 0x800B0818: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B081C: nop

    // 0x800B0820: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x800B0824: beq         $t0, $zero, L_800B0838
    if (ctx->r8 == 0) {
        // 0x800B0828: nop
    
            goto L_800B0838;
    }
    // 0x800B0828: nop

    // 0x800B082C: lh          $t1, 0xA($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XA);
    // 0x800B0830: b           L_800B0848
    // 0x800B0834: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
        goto L_800B0848;
    // 0x800B0834: sh          $t1, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r9;
L_800B0838:
    // 0x800B0838: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800B083C: nop

    // 0x800B0840: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B0844: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
L_800B0848:
    // 0x800B0848: lbu         $t4, 0xC($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XC);
    // 0x800B084C: nop

    // 0x800B0850: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B0854: beq         $at, $zero, L_800B0894
    if (ctx->r1 == 0) {
        // 0x800B0858: nop
    
            goto L_800B0894;
    }
    // 0x800B0858: nop

    // 0x800B085C: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B0860: nop

    // 0x800B0864: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B0868: beq         $t7, $zero, L_800B0884
    if (ctx->r15 == 0) {
        // 0x800B086C: nop
    
            goto L_800B0884;
    }
    // 0x800B086C: nop

    // 0x800B0870: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B0874: nop

    // 0x800B0878: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B087C: b           L_800B0894
    // 0x800B0880: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B0894;
    // 0x800B0880: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B0884:
    // 0x800B0884: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B0888: nop

    // 0x800B088C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x800B0890: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_800B0894:
    // 0x800B0894: lh          $a1, 0x60($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X60);
    // 0x800B0898: lh          $a0, 0x3A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X3A);
    // 0x800B089C: nop

    // 0x800B08A0: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B08A4: beq         $at, $zero, L_800B08F8
    if (ctx->r1 == 0) {
        // 0x800B08A8: subu        $t7, $a0, $a1
        ctx->r15 = SUB32(ctx->r4, ctx->r5);
            goto L_800B08F8;
    }
    // 0x800B08A8: subu        $t7, $a0, $a1
    ctx->r15 = SUB32(ctx->r4, ctx->r5);
    // 0x800B08AC: lbu         $t1, 0xD($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XD);
    // 0x800B08B0: lh          $t3, 0x5C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5C);
    // 0x800B08B4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B08B8: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800B08BC: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x800B08C0: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B08C4: bne         $t7, $zero, L_800B08D0
    if (ctx->r15 != 0) {
        // 0x800B08C8: nop
    
            goto L_800B08D0;
    }
    // 0x800B08C8: nop

    // 0x800B08CC: break       7
    do_break(2148206796);
L_800B08D0:
    // 0x800B08D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B08D4: bne         $t7, $at, L_800B08E8
    if (ctx->r15 != ctx->r1) {
        // 0x800B08D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B08E8;
    }
    // 0x800B08D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B08DC: bne         $t5, $at, L_800B08E8
    if (ctx->r13 != ctx->r1) {
        // 0x800B08E0: nop
    
            goto L_800B08E8;
    }
    // 0x800B08E0: nop

    // 0x800B08E4: break       6
    do_break(2148206820);
L_800B08E8:
    // 0x800B08E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800B08EC: sh          $t6, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r14;
    // 0x800B08F0: b           L_800B0900
    // 0x800B08F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_800B0900;
    // 0x800B08F4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B08F8:
    // 0x800B08F8: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B08FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_800B0900:
    // 0x800B0900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0904: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0908: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B090C: jal         0x800B03C0
    // 0x800B0910: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    setup_particle_position(rdram, ctx);
        goto after_1;
    // 0x800B0910: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B0914: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0918: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B091C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B0920: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B0924: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0928: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800B092C: beq         $t9, $zero, L_800B0958
    if (ctx->r25 == 0) {
        // 0x800B0930: nop
    
            goto L_800B0958;
    }
    // 0x800B0930: nop

    // 0x800B0934: lh          $t0, 0x44($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X44);
    // 0x800B0938: nop

    // 0x800B093C: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x800B0940: lh          $t1, 0x46($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X46);
    // 0x800B0944: nop

    // 0x800B0948: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x800B094C: lh          $t3, 0x48($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X48);
    // 0x800B0950: b           L_800B0994
    // 0x800B0954: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
        goto L_800B0994;
    // 0x800B0954: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
L_800B0958:
    // 0x800B0958: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x800B095C: lh          $t4, 0x44($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X44);
    // 0x800B0960: nop

    // 0x800B0964: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800B0968: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x800B096C: lh          $t6, 0x46($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X46);
    // 0x800B0970: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800B0974: nop

    // 0x800B0978: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B097C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B0980: lh          $t0, 0x48($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X48);
    // 0x800B0984: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800B0988: nop

    // 0x800B098C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B0990: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
L_800B0994:
    // 0x800B0994: lh          $t3, 0x4A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4A);
    // 0x800B0998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B099C: sh          $t3, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r11;
    // 0x800B09A0: lh          $t2, 0x4C($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4C);
    // 0x800B09A4: nop

    // 0x800B09A8: sh          $t2, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r10;
    // 0x800B09AC: lh          $t4, 0x4E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X4E);
    // 0x800B09B0: nop

    // 0x800B09B4: sh          $t4, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r12;
    // 0x800B09B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B09BC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B09C0: jal         0x800B0010
    // 0x800B09C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    setup_particle_velocity(rdram, ctx);
        goto after_2;
    // 0x800B09C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800B09C8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B09CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B09D0: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x800B09D4: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800B09D8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B09DC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B09E0: lwc1        $f18, 0x2E2C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2E2C);
    // 0x800B09E4: lbu         $t9, 0x39($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X39);
    // 0x800B09E8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B09EC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B09F0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B09F4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B09F8: bne         $t9, $at, L_800B0A40
    if (ctx->r25 != ctx->r1) {
        // 0x800B09FC: swc1        $f18, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
            goto L_800B0A40;
    }
    // 0x800B09FC: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x800B0A00: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0A04: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0A08: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B0A0C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0A10: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800B0A14: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800B0A18: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B0A1C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0A20: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B0A24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B0A28: jal         0x800C9AD0
    // 0x800B0A2C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B0A2C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x800B0A30: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0A34: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B0A38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B0A3C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B0A40:
    // 0x800B0A40: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0A44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0A48: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800B0A4C: beq         $t0, $zero, L_800B0A84
    if (ctx->r8 == 0) {
        // 0x800B0A50: andi        $t6, $v0, 0x8
        ctx->r14 = ctx->r2 & 0X8;
            goto L_800B0A84;
    }
    // 0x800B0A50: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x800B0A54: lh          $t1, 0x10($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X10);
    // 0x800B0A58: lh          $t3, 0x1C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1C);
    // 0x800B0A5C: lh          $t4, 0x12($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X12);
    // 0x800B0A60: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B0A64: sh          $t2, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r10;
    // 0x800B0A68: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B0A6C: nop

    // 0x800B0A70: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B0A74: sh          $t7, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r15;
    // 0x800B0A78: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800B0A7C: nop

    // 0x800B0A80: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
L_800B0A84:
    // 0x800B0A84: beq         $t6, $zero, L_800B0AB0
    if (ctx->r14 == 0) {
        // 0x800B0A88: nop
    
            goto L_800B0AB0;
    }
    // 0x800B0A88: nop

    // 0x800B0A8C: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x800B0A90: lh          $t9, 0x2A($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2A);
    // 0x800B0A94: lh          $t1, 0x16($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X16);
    // 0x800B0A98: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800B0A9C: sh          $t0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r8;
    // 0x800B0AA0: lh          $t3, 0x2C($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2C);
    // 0x800B0AA4: nop

    // 0x800B0AA8: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x800B0AAC: sh          $t2, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r10;
L_800B0AB0:
    // 0x800B0AB0: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x800B0AB4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800B0AB8: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x800B0ABC: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x800B0AC0: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x800B0AC4: bne         $a0, $at, L_800B0AD4
    if (ctx->r4 != ctx->r1) {
        // 0x800B0AC8: nop
    
            goto L_800B0AD4;
    }
    // 0x800B0AC8: nop

    // 0x800B0ACC: b           L_800B0B68
    // 0x800B0AD0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800B0B68;
    // 0x800B0AD0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800B0AD4:
    // 0x800B0AD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0AD8: jal         0x8007AE74
    // 0x800B0ADC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x800B0ADC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B0AE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B0AE4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0AE8: beq         $v0, $zero, L_800B0B68
    if (ctx->r2 == 0) {
        // 0x800B0AEC: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_800B0B68;
    }
    // 0x800B0AEC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B0AF0: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B0AF4: nop

    // 0x800B0AF8: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B0AFC: beq         $t6, $zero, L_800B0B3C
    if (ctx->r14 == 0) {
        // 0x800B0B00: nop
    
            goto L_800B0B3C;
    }
    // 0x800B0B00: nop

    // 0x800B0B04: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B0B08: nop

    // 0x800B0B0C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B0B10: beq         $t9, $zero, L_800B0B2C
    if (ctx->r25 == 0) {
        // 0x800B0B14: nop
    
            goto L_800B0B2C;
    }
    // 0x800B0B14: nop

    // 0x800B0B18: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800B0B1C: nop

    // 0x800B0B20: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x800B0B24: b           L_800B0B3C
    // 0x800B0B28: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
        goto L_800B0B3C;
    // 0x800B0B28: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
L_800B0B2C:
    // 0x800B0B2C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B0B30: nop

    // 0x800B0B34: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800B0B38: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B0B3C:
    // 0x800B0B3C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B0B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0B44: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B0B48: bne         $t5, $at, L_800B0B68
    if (ctx->r13 != ctx->r1) {
        // 0x800B0B4C: nop
    
            goto L_800B0B68;
    }
    // 0x800B0B4C: nop

    // 0x800B0B50: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B0B54: nop

    // 0x800B0B58: lhu         $t6, 0x12($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X12);
    // 0x800B0B5C: nop

    // 0x800B0B60: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800B0B64: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800B0B68:
    // 0x800B0B68: sb          $zero, 0x75($s0)
    MEM_B(0X75, ctx->r16) = 0;
    // 0x800B0B6C: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x800B0B70: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
    // 0x800B0B74: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x800B0B78: sb          $t0, 0x76($s0)
    MEM_B(0X76, ctx->r16) = ctx->r8;
    // 0x800B0B7C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B0B80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B0B84: bne         $t1, $zero, L_800B0B9C
    if (ctx->r9 != 0) {
        // 0x800B0B88: nop
    
            goto L_800B0B9C;
    }
    // 0x800B0B88: nop

    // 0x800B0B8C: jal         0x800B2040
    // 0x800B0B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_5;
    // 0x800B0B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B0B94: b           L_800B0B9C
    // 0x800B0B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0B9C;
    // 0x800B0B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0B9C:
    // 0x800B0B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0BA4: jr          $ra
    // 0x800B0BA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B0BA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void read_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007487C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074880: jal         0x8006A100
    // 0x80074884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074888: jal         0x800CE210
    // 0x8007488C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007488C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074890: bne         $v0, $zero, L_800748A0
    if (ctx->r2 != 0) {
        // 0x80074894: nop
    
            goto L_800748A0;
    }
    // 0x80074894: nop

    // 0x80074898: b           L_8007496C
    // 0x8007489C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007496C;
    // 0x8007489C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800748A0:
    // 0x800748A0: jal         0x8006A100
    // 0x800748A4: nop

    si_mesg(rdram, ctx);
        goto after_2;
    // 0x800748A4: nop

    after_2:
    // 0x800748A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800748AC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800748B0: jal         0x800CE280
    // 0x800748B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_3;
    // 0x800748B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x800748B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800748BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800748C0: jal         0x8007480C
    // 0x800748C4: nop

    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x800748C4: nop

    after_4:
    // 0x800748C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800748CC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800748D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800748D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800748D8: jal         0x800CEA60
    // 0x800748DC: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ull_rshift_recomp(rdram, ctx);
        goto after_5;
    // 0x800748DC: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x800748E0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800748E4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800748E8: beq         $t6, $v1, L_80074968
    if (ctx->r14 == ctx->r3) {
        // 0x800748EC: lui         $t9, 0x300
        ctx->r25 = S32(0X300 << 16);
            goto L_80074968;
    }
    // 0x800748EC: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x800748F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800748F4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800748F8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800748FC: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x80074900: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074904: jal         0x800CEB04
    // 0x80074908: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_6;
    // 0x80074908: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_6:
    // 0x8007490C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80074910: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074918: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8007491C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074920: jal         0x800CEA60
    // 0x80074924: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_7;
    // 0x80074924: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_7:
    // 0x80074928: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8007492C: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80074930: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074934: jal         0x8007480C
    // 0x80074938: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_8;
    // 0x80074938: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_8:
    // 0x8007493C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80074940: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80074944: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074948: jal         0x800CEB04
    // 0x8007494C: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_9;
    // 0x8007494C: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_9:
    // 0x80074950: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80074954: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80074958: or          $t2, $t0, $v0
    ctx->r10 = ctx->r8 | ctx->r2;
    // 0x8007495C: or          $t3, $t1, $v1
    ctx->r11 = ctx->r9 | ctx->r3;
    // 0x80074960: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80074964: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_80074968:
    // 0x80074968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007496C:
    // 0x8007496C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074974: jr          $ra
    // 0x80074978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bgdraw_chequer_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078778: sra         $t7, $a0, 24
    ctx->r15 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8007877C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078780: sb          $t7, 0x5F30($at)
    MEM_B(0X5F30, ctx->r1) = ctx->r15;
    // 0x80078784: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078788: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007878C: sb          $t9, 0x5F31($at)
    MEM_B(0X5F31, ctx->r1) = ctx->r25;
    // 0x80078790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078794: sra         $t1, $a0, 8
    ctx->r9 = S32(SIGNED(ctx->r4) >> 8);
    // 0x80078798: sb          $t1, 0x5F32($at)
    MEM_B(0X5F32, ctx->r1) = ctx->r9;
    // 0x8007879C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787A0: sb          $a0, 0x5F33($at)
    MEM_B(0X5F33, ctx->r1) = ctx->r4;
    // 0x800787A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787A8: sra         $t4, $a1, 24
    ctx->r12 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800787AC: sb          $t4, 0x5F34($at)
    MEM_B(0X5F34, ctx->r1) = ctx->r12;
    // 0x800787B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787B4: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800787B8: sb          $t6, 0x5F35($at)
    MEM_B(0X5F35, ctx->r1) = ctx->r14;
    // 0x800787BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787C0: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800787C4: sb          $t8, 0x5F36($at)
    MEM_B(0X5F36, ctx->r1) = ctx->r24;
    // 0x800787C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787CC: sb          $a1, 0x5F37($at)
    MEM_B(0X5F37, ctx->r1) = ctx->r5;
    // 0x800787D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787D4: sw          $a2, 0x5F38($at)
    MEM_W(0X5F38, ctx->r1) = ctx->r6;
    // 0x800787D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800787DC: sw          $a3, 0x5F3C($at)
    MEM_W(0X5F3C, ctx->r1) = ctx->r7;
    // 0x800787E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800787E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800787E8: jr          $ra
    // 0x800787EC: sw          $t0, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = ctx->r8;
    return;
    // 0x800787EC: sw          $t0, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void filename_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097878: sw          $a0, 0xF90($at)
    MEM_W(0XF90, ctx->r1) = ctx->r4;
    // 0x8009787C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097880: sw          $a1, 0xF94($at)
    MEM_W(0XF94, ctx->r1) = ctx->r5;
    // 0x80097884: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097888: sw          $a2, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = ctx->r6;
    // 0x8009788C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097894: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097898: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009789C: sw          $a3, 0xF9C($at)
    MEM_W(0XF9C, ctx->r1) = ctx->r7;
    // 0x800978A0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800978A4: addiu       $v0, $v0, 0x6C6C
    ctx->r2 = ADD32(ctx->r2, 0X6C6C);
    // 0x800978A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800978AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800978B0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800978B4: sw          $t8, 0x6C74($at)
    MEM_W(0X6C74, ctx->r1) = ctx->r24;
    // 0x800978B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800978BC: sw          $t9, 0x6C78($at)
    MEM_W(0X6C78, ctx->r1) = ctx->r25;
    // 0x800978C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800978C4: sw          $zero, 0xFA0($at)
    MEM_W(0XFA0, ctx->r1) = 0;
    // 0x800978C8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800978CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800978D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800978D4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800978D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800978DC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800978E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800978E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800978E8: swc1        $f6, 0x6C50($at)
    MEM_W(0X6C50, ctx->r1) = ctx->f6.u32l;
    // 0x800978EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800978F0: sw          $zero, 0x6C48($at)
    MEM_W(0X6C48, ctx->r1) = 0;
    // 0x800978F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800978F8: sw          $zero, 0x6C3C($at)
    MEM_W(0X6C3C, ctx->r1) = 0;
    // 0x800978FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097900: jal         0x800C4170
    // 0x80097904: sw          $zero, 0x6C34($at)
    MEM_W(0X6C34, ctx->r1) = 0;
    load_font(rdram, ctx);
        goto after_0;
    // 0x80097904: sw          $zero, 0x6C34($at)
    MEM_W(0X6C34, ctx->r1) = 0;
    after_0:
    // 0x80097908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009790C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097910: jr          $ra
    // 0x80097914: nop

    return;
    // 0x80097914: nop

;}
RECOMP_FUNC void obj_init_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003588C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035894: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035898: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003589C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800358A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800358A4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800358A8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800358AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800358B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800358B4: nop

    // 0x800358B8: bc1f        L_800358C8
    if (!c1cs) {
        // 0x800358BC: nop
    
            goto L_800358C8;
    }
    // 0x800358BC: nop

    // 0x800358C0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800358C4: nop

L_800358C8:
    // 0x800358C8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800358CC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800358D0: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x800358D4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800358D8: nop

    // 0x800358DC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800358E0: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800358E4: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800358E8: nop

    // 0x800358EC: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800358F0: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800358F4: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x800358F8: nop

    // 0x800358FC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035900: bne         $at, $zero, L_8003590C
    if (ctx->r1 != 0) {
        // 0x80035904: nop
    
            goto L_8003590C;
    }
    // 0x80035904: nop

    // 0x80035908: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003590C:
    // 0x8003590C: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80035910: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80035914: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80035918: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003591C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80035920: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80035924: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035928: nop

    // 0x8003592C: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80035930: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035934: nop

    // 0x80035938: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003593C: jal         0x8009C30C
    // 0x80035940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035948: sll         $t9, $v0, 10
    ctx->r25 = S32(ctx->r2 << 10);
    // 0x8003594C: bgez        $t9, L_80035960
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80035950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035960;
    }
    // 0x80035950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035954: jal         0x8000FFB8
    // 0x80035958: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035958: nop

    after_1:
    // 0x8003595C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035960:
    // 0x80035960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035964: jr          $ra
    // 0x80035968: nop

    return;
    // 0x80035968: nop

;}
RECOMP_FUNC void music_enabled_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001878: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000187C: addiu       $v0, $v0, -0x39C0
    ctx->r2 = ADD32(ctx->r2, -0X39C0);
    // 0x80001880: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80001884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001888: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8000188C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001890: beq         $t7, $t6, L_800018C0
    if (ctx->r15 == ctx->r14) {
        // 0x80001894: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800018C0;
    }
    // 0x80001894: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001898: beq         $t6, $zero, L_800018B8
    if (ctx->r14 == 0) {
        // 0x8000189C: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_800018B8;
    }
    // 0x8000189C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800018A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800018A4: lbu         $a0, 0x5D04($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5D04);
    // 0x800018A8: jal         0x80000B34
    // 0x800018AC: nop

    music_play(rdram, ctx);
        goto after_0;
    // 0x800018AC: nop

    after_0:
    // 0x800018B0: b           L_800018C4
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800018C4;
    // 0x800018B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018B8:
    // 0x800018B8: jal         0x80001844
    // 0x800018BC: nop

    music_stop(rdram, ctx);
        goto after_1;
    // 0x800018BC: nop

    after_1:
L_800018C0:
    // 0x800018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800018C4:
    // 0x800018C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800018C8: jr          $ra
    // 0x800018CC: nop

    return;
    // 0x800018CC: nop

;}
RECOMP_FUNC void func_8006D8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D8F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D8F4: lw          $t6, 0x34EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X34EC);
    // 0x8006D8F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D8FC: beq         $t6, $at, L_8006D960
    if (ctx->r14 == ctx->r1) {
        // 0x8006D900: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006D960;
    }
    // 0x8006D900: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006D904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006D908: addiu       $a0, $a0, 0x1250
    ctx->r4 = ADD32(ctx->r4, 0X1250);
    // 0x8006D90C: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x8006D910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D914: sw          $t7, 0x34F4($at)
    MEM_W(0X34F4, ctx->r1) = ctx->r15;
    // 0x8006D918: lb          $v1, 0xF($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XF);
    // 0x8006D91C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006D920: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D924: addiu       $a2, $a2, 0x3508
    ctx->r6 = ADD32(ctx->r6, 0X3508);
    // 0x8006D928: addiu       $a1, $a1, 0x3504
    ctx->r5 = ADD32(ctx->r5, 0X3504);
    // 0x8006D92C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006D930: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x8006D934: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8006D938: bltz        $v1, L_8006D944
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006D93C: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8006D944;
    }
    // 0x8006D93C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8006D940: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8006D944:
    // 0x8006D944: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x8006D948: lb          $v1, 0x8($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X8);
    // 0x8006D94C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006D950: bltz        $v1, L_8006D95C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006D954: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8006D95C;
    }
    // 0x8006D954: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D958: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006D95C:
    // 0x8006D95C: sw          $t0, 0x34F8($at)
    MEM_W(0X34F8, ctx->r1) = ctx->r8;
L_8006D960:
    // 0x8006D960: jr          $ra
    // 0x8006D964: nop

    return;
    // 0x8006D964: nop

;}
RECOMP_FUNC void hud_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA600: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800AA604: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AA608: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800AA60C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800AA610: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800AA614: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    extern void dkr_hud_element_begin(uint8_t*, recomp_context*); dkr_hud_element_begin(rdram, ctx);
    // 0x800AA618: lh          $t0, 0x6($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X6);
    // 0x800AA61C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800AA620: lw          $v1, 0x6CF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CF0);
    // 0x800AA624: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800AA628: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800AA62C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AA630: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AA634: andi        $v0, $t8, 0xC000
    ctx->r2 = ctx->r24 & 0XC000;
    // 0x800AA638: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800AA63C: bne         $t2, $v0, L_800AA65C
    if (ctx->r10 != ctx->r2) {
        // 0x800AA640: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800AA65C;
    }
    // 0x800AA640: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800AA644: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA648: lb          $t3, 0x6CD0($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6CD0);
    // 0x800AA64C: nop

    // 0x800AA650: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800AA654: b           L_800AA66C
    // 0x800AA658: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
        goto L_800AA66C;
    // 0x800AA658: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
L_800AA65C:
    // 0x800AA65C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA660: lb          $t5, 0x6CD0($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X6CD0);
    // 0x800AA664: nop

    // 0x800AA668: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800AA66C:
    // 0x800AA66C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA670: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AA674: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AA678: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800AA67C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AA680: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AA684: nop

    // 0x800AA688: bne         $t9, $zero, L_800AA7B4
    if (ctx->r25 != 0) {
        // 0x800AA68C: nop
    
            goto L_800AA7B4;
    }
    // 0x800AA68C: nop

    // 0x800AA690: bne         $t2, $v0, L_800AA6D0
    if (ctx->r10 != ctx->r2) {
        // 0x800AA694: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_800AA6D0;
    }
    // 0x800AA694: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AA698: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AA69C: nop

    // 0x800AA6A0: andi        $t3, $a0, 0x3FFF
    ctx->r11 = ctx->r4 & 0X3FFF;
    // 0x800AA6A4: jal         0x8007AE74
    // 0x800AA6A8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AA6A8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x800AA6AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA6B0: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AA6B4: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AA6B8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800AA6BC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AA6C0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA6C4: b           L_800AA798
    // 0x800AA6C8: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
        goto L_800AA798;
    // 0x800AA6C8: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AA6CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_800AA6D0:
    // 0x800AA6D0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AA6D4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800AA6D8: beq         $t9, $zero, L_800AA708
    if (ctx->r25 == 0) {
        // 0x800AA6DC: andi        $a0, $t8, 0x3FFF
        ctx->r4 = ctx->r24 & 0X3FFF;
            goto L_800AA708;
    }
    // 0x800AA6DC: andi        $a0, $t8, 0x3FFF
    ctx->r4 = ctx->r24 & 0X3FFF;
    // 0x800AA6E0: jal         0x8007C12C
    // 0x800AA6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_1;
    // 0x800AA6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800AA6E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA6EC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AA6F0: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AA6F4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AA6F8: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800AA6FC: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800AA700: b           L_800AA798
    // 0x800AA704: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AA798;
    // 0x800AA704: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AA708:
    // 0x800AA708: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x800AA70C: beq         $t9, $zero, L_800AA770
    if (ctx->r25 == 0) {
        // 0x800AA710: or          $t8, $t7, $zero
        ctx->r24 = ctx->r15 | 0;
            goto L_800AA770;
    }
    // 0x800AA710: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800AA714: sb          $t8, 0x9C($sp)
    MEM_B(0X9C, ctx->r29) = ctx->r24;
    // 0x800AA718: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800AA71C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800AA720: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x800AA724: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800AA728: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x800AA72C: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800AA730: andi        $t9, $t6, 0x100
    ctx->r25 = ctx->r14 & 0X100;
    // 0x800AA734: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AA738: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x800AA73C: sb          $t8, 0x9D($sp)
    MEM_B(0X9D, ctx->r29) = ctx->r24;
    // 0x800AA740: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x800AA744: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x800AA748: jal         0x8000EA54
    // 0x800AA74C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x800AA74C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AA750: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA754: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AA758: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AA75C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AA760: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800AA764: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AA768: b           L_800AA798
    // 0x800AA76C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800AA798;
    // 0x800AA76C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800AA770:
    // 0x800AA770: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AA774: jal         0x8005F99C
    // 0x800AA778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    object_model_init(rdram, ctx);
        goto after_3;
    // 0x800AA778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800AA77C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA780: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800AA784: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AA788: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AA78C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AA790: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AA794: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800AA798:
    // 0x800AA798: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AA79C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AA7A0: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AA7A4: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800AA7A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    if (ctx->r15 == 0) { extern void dkr_hud_asset_load_failed(uint8_t*, recomp_context*); dkr_hud_asset_load_failed(rdram, ctx); }
    // 0x800AA7AC: nop

    // 0x800AA7B0: beq         $t7, $zero, L_800AAFC0
    if (ctx->r15 == 0) {
        // 0x800AA7B4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AAFC0;
    }
L_800AA7B4:
    // 0x800AA7B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA7B8: lw          $t9, 0x6CD8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CD8);
    // 0x800AA7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA7C0: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800AA7C4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800AA7C8: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x800AA7CC: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800AA7D0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800AA7D4: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AA7D8: sw          $t5, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r13;
    // 0x800AA7DC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AA7E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA7E4: sw          $t6, 0x6D00($at)
    MEM_W(0X6D00, ctx->r1) = ctx->r14;
    // 0x800AA7E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800AA7EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA7F0: sw          $t9, 0x6D04($at)
    MEM_W(0X6D04, ctx->r1) = ctx->r25;
    // 0x800AA7F4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AA7F8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AA7FC: beq         $t0, $at, L_800AA884
    if (ctx->r8 == ctx->r1) {
        // 0x800AA800: ori         $t2, $zero, 0xC000
        ctx->r10 = 0 | 0XC000;
            goto L_800AA884;
    }
    // 0x800AA800: ori         $t2, $zero, 0xC000
    ctx->r10 = 0 | 0XC000;
    // 0x800AA804: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AA808: beq         $t0, $at, L_800AA85C
    if (ctx->r8 == ctx->r1) {
        // 0x800AA80C: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AA85C;
    }
    // 0x800AA80C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AA810: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AA814: beq         $t0, $at, L_800AA85C
    if (ctx->r8 == ctx->r1) {
        // 0x800AA818: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AA85C;
    }
    // 0x800AA818: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AA81C: bne         $at, $zero, L_800AA828
    if (ctx->r1 != 0) {
        // 0x800AA820: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AA828;
    }
    // 0x800AA820: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AA824: bne         $at, $zero, L_800AA85C
    if (ctx->r1 != 0) {
        // 0x800AA828: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AA85C;
    }
L_800AA828:
    // 0x800AA828: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AA82C: beq         $t0, $at, L_800AA85C
    if (ctx->r8 == ctx->r1) {
        // 0x800AA830: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800AA85C;
    }
    // 0x800AA830: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA834: lb          $t8, 0x6CD3($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6CD3);
    // 0x800AA838: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800AA83C: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x800AA840: beq         $t3, $zero, L_800AA85C
    if (ctx->r11 == 0) {
        // 0x800AA844: nop
    
            goto L_800AA85C;
    }
    // 0x800AA844: nop

    // 0x800AA848: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800AA84C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AA850: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA854: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AA858: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AA85C:
    // 0x800AA85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA860: lw          $t6, 0x6D28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D28);
    // 0x800AA864: lw          $t4, 0x6D24($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D24);
    // 0x800AA868: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AA86C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA870: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AA874: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AA878: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA87C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AA880: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_800AA884:
    // 0x800AA884: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA888: lw          $t9, 0x6CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CF0);
    // 0x800AA88C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800AA890: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800AA894: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800AA898: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AA89C: andi        $t5, $v0, 0xC000
    ctx->r13 = ctx->r2 & 0XC000;
    // 0x800AA8A0: bne         $t2, $t5, L_800AADA4
    if (ctx->r10 != ctx->r13) {
        // 0x800AA8A4: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800AADA4;
    }
    // 0x800AA8A4: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800AA8A8: bne         $at, $zero, L_800AAB00
    if (ctx->r1 != 0) {
        // 0x800AA8AC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AAB00;
    }
    // 0x800AA8AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA8B0: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AA8B4: beq         $at, $zero, L_800AAB00
    if (ctx->r1 == 0) {
        // 0x800AA8B8: lui         $a0, 0x8000
        ctx->r4 = S32(0X8000 << 16);
            goto L_800AAB00;
    }
    // 0x800AA8B8: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AA8BC: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AA8C0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AA8C4: bne         $a0, $zero, L_800AA8EC
    if (ctx->r4 != 0) {
        // 0x800AA8C8: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800AA8EC;
    }
    // 0x800AA8C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AA8CC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AA8D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA8D4: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800AA8D8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AA8DC: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800AA8E0: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800AA8E4: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x800AA8E8: nop

L_800AA8EC:
    // 0x800AA8EC: lb          $t4, 0x6CD3($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6CD3);
    // 0x800AA8F0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AA8F4: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x800AA8F8: beq         $t6, $zero, L_800AA974
    if (ctx->r14 == 0) {
        // 0x800AA8FC: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_800AA974;
    }
    // 0x800AA8FC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AA900: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AA904: lb          $t7, 0x6CD0($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6CD0);
    // 0x800AA908: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA90C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AA910: lbu         $t9, 0x718B($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X718B);
    // 0x800AA914: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA918: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AA91C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AA920: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AA924: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AA928: bgez        $t9, L_800AA93C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AA92C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800AA93C;
    }
    // 0x800AA92C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AA930: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA934: nop

    // 0x800AA938: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800AA93C:
    // 0x800AA93C: nop

    // 0x800AA940: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AA944: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800AA948: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA94C: nop

    // 0x800AA950: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AA954: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA958: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA95C: nop

    // 0x800AA960: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AA964: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AA968: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA96C: b           L_800AA978
    // 0x800AA970: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
        goto L_800AA978;
    // 0x800AA970: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AA974:
    // 0x800AA974: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AA978:
    // 0x800AA978: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AA97C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AA980: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AA984: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AA988: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AA98C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA990: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AA994: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AA998: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA99C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA9A0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AA9A4: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AA9A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AA9AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AA9B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800AA9B4: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AA9B8: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800AA9BC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AA9C0: nop

    // 0x800AA9C4: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AA9C8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA9CC: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800AA9D0: nop

    // 0x800AA9D4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AA9D8: sh          $t3, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r11;
    // 0x800AA9DC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AA9E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA9E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA9E8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AA9EC: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800AA9F0: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AA9F4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AA9F8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AA9FC: bne         $a0, $zero, L_800AAAB0
    if (ctx->r4 != 0) {
        // 0x800AAA00: sh          $t4, 0x8E($sp)
        MEM_H(0X8E, ctx->r29) = ctx->r12;
            goto L_800AAAB0;
    }
    // 0x800AAA00: sh          $t4, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r12;
    // 0x800AAA04: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800AAA08: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x800AAA0C: bne         $t6, $at, L_800AAA78
    if (ctx->r14 != ctx->r1) {
        // 0x800AAA10: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAA78;
    }
    // 0x800AAA10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAA14: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AAA18: bne         $v1, $at, L_800AAA28
    if (ctx->r3 != ctx->r1) {
        // 0x800AAA1C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAA28;
    }
    // 0x800AAA1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAA20: b           L_800AAA30
    // 0x800AAA24: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_800AAA30;
    // 0x800AAA24: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_800AAA28:
    // 0x800AAA28: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800AAA2C: or          $v0, $v1, $at
    ctx->r2 = ctx->r3 | ctx->r1;
L_800AAA30:
    // 0x800AAA30: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800AAA34: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800AAA38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AAA3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AAA40: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AAA44: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AAA48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AAA4C: lwc1        $f8, -0x7828($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7828);
    // 0x800AAA50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAA54: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AAA58: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AAA5C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAA60: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAA64: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800AAA68: jal         0x80078D00
    // 0x800AAA6C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_4;
    // 0x800AAA6C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x800AAA70: b           L_800AAAD4
    // 0x800AAA74: nop

        goto L_800AAAD4;
    // 0x800AAA74: nop

L_800AAA78:
    // 0x800AAA78: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800AAA7C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800AAA80: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800AAA84: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800AAA88: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800AAA8C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AAA90: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAA94: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800AAA98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAA9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AAAA0: jal         0x80078AB8
    // 0x800AAAA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x800AAAA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800AAAA8: b           L_800AAAD4
    // 0x800AAAAC: nop

        goto L_800AAAD4;
    // 0x800AAAAC: nop

L_800AAAB0:
    // 0x800AAAB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAAB4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800AAAB8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800AAABC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800AAAC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800AAAC4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAAC8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AAACC: jal         0x80078AB8
    // 0x800AAAD0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    texrect_draw(rdram, ctx);
        goto after_6;
    // 0x800AAAD0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_6:
L_800AAAD4:
    // 0x800AAAD4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800AAAD8: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800AAADC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800AAAE0: bne         $t7, $zero, L_800AAF00
    if (ctx->r15 != 0) {
        // 0x800AAAE4: nop
    
            goto L_800AAF00;
    }
    // 0x800AAAE4: nop

    // 0x800AAAE8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAAEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AAAF0: nop

    // 0x800AAAF4: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AAAF8: b           L_800AAF00
    // 0x800AAAFC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
        goto L_800AAF00;
    // 0x800AAAFC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
L_800AAB00:
    // 0x800AAB00: lb          $t9, 0x6CD5($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6CD5);
    // 0x800AAB04: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800AAB08: beq         $t9, $zero, L_800AABAC
    if (ctx->r25 == 0) {
        // 0x800AAB0C: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_800AABAC;
    }
    // 0x800AAB0C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800AAB10: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800AAB14: nop

    // 0x800AAB18: bne         $t8, $zero, L_800AABAC
    if (ctx->r24 != 0) {
        // 0x800AAB1C: nop
    
            goto L_800AABAC;
    }
    // 0x800AAB1C: nop

    // 0x800AAB20: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800AAB24: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AAB28: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    { extern uint32_t dkr_legacy_character_hud_lookup(uint8_t*, recomp_context*, uint32_t, uint32_t); uint32_t cell = dkr_legacy_character_hud_lookup(rdram, ctx, (uint32_t)ctx->r29 + 0xB8U, (uint32_t)ctx->r16); if (cell) ctx->r12 = (int32_t)cell; }
    // 0x800AAB2C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AAB30: lh          $t6, 0x18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18);
    // 0x800AAB34: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800AAB38: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x800AAB3C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAB40: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800AAB44: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800AAB48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AAB4C: lwc1        $f19, -0x7820($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7820);
    // 0x800AAB50: lwc1        $f18, -0x781C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X781C);
    // 0x800AAB54: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AAB58: lw          $t8, 0x2834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2834);
    // 0x800AAB5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AAB60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAB64: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAB68: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800AAB6C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AAB70: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AAB74: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800AAB78: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AAB7C: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AAB80: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800AAB84: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800AAB88: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AAB8C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800AAB90: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800AAB94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800AAB98: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800AAB9C: jal         0x80078D00
    // 0x800AABA0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_7;
    // 0x800AABA0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800AABA4: b           L_800AAF04
    // 0x800AABA8: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AAF04;
    // 0x800AABA8: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AABAC:
    // 0x800AABAC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AABB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800AABB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AABB8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800AABBC: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800AABC0: nop

    // 0x800AABC4: bc1f        L_800AAD24
    if (!c1cs) {
        // 0x800AABC8: nop
    
            goto L_800AAD24;
    }
    // 0x800AABC8: nop

    // 0x800AABCC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AABD0: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800AABD4: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    { extern uint32_t dkr_legacy_character_hud_lookup(uint8_t*, recomp_context*, uint32_t, uint32_t); uint32_t cell = dkr_legacy_character_hud_lookup(rdram, ctx, (uint32_t)ctx->r29 + 0xB8U, (uint32_t)ctx->r16); if (cell) ctx->r14 = (int32_t)cell; }
    // 0x800AABD8: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x800AABDC: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x800AABE0: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x800AABE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AABE8: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AABEC: lw          $v0, 0x2834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2834);
    // 0x800AABF0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800AABF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AABF8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AABFC: addiu       $a1, $a1, 0x7180
    ctx->r5 = ADD32(ctx->r5, 0X7180);
    // 0x800AAC00: addiu       $t5, $t5, 0x6D80
    ctx->r13 = ADD32(ctx->r13, 0X6D80);
    // 0x800AAC04: mflo        $t8
    ctx->r24 = lo;
    // 0x800AAC08: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800AAC0C: bne         $v0, $at, L_800AAC7C
    if (ctx->r2 != ctx->r1) {
        // 0x800AAC10: nop
    
            goto L_800AAC7C;
    }
    // 0x800AAC10: nop

    // 0x800AAC14: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800AAC18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AAC1C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800AAC20: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x800AAC24: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AAC28: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800AAC2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAC30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAC34: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAC38: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800AAC3C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AAC40: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AAC44: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AAC48: nop

    // 0x800AAC4C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AAC50: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800AAC54: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AAC58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAC5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAC60: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAC64: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800AAC68: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAC6C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AAC70: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AAC74: b           L_800AAF00
    // 0x800AAC78: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
        goto L_800AAF00;
    // 0x800AAC78: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
L_800AAC7C:
    // 0x800AAC7C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AAC80: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AAC84: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AAC88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAC8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAC90: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAC94: srl         $t7, $v0, 24
    ctx->r15 = S32(U32(ctx->r2) >> 24);
    // 0x800AAC98: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AAC9C: srl         $t8, $v0, 16
    ctx->r24 = S32(U32(ctx->r2) >> 16);
    // 0x800AACA0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AACA4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800AACA8: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800AACAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AACB0: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x800AACB4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AACB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AACBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AACC0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AACC4: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x800AACC8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AACCC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800AACD0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AACD4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AACD8: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x800AACDC: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800AACE0: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800AACE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AACE8: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800AACEC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AACF0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800AACF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800AACF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AACFC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AAD00: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800AAD04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AAD08: jal         0x80078AB8
    // 0x800AAD0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x800AAD0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800AAD10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAD14: jal         0x8007B3D0
    // 0x800AAD18: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rendermode_reset(rdram, ctx);
        goto after_9;
    // 0x800AAD18: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_9:
    // 0x800AAD1C: b           L_800AAF04
    // 0x800AAD20: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AAF04;
    // 0x800AAD20: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AAD24:
    // 0x800AAD24: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AAD28: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AAD2C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    { extern uint32_t dkr_legacy_character_hud_lookup(uint8_t*, recomp_context*, uint32_t, uint32_t); uint32_t cell = dkr_legacy_character_hud_lookup(rdram, ctx, (uint32_t)ctx->r29 + 0xB8U, (uint32_t)ctx->r16); if (cell) ctx->r24 = (int32_t)cell; }
    // 0x800AAD30: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800AAD34: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800AAD38: lh          $t5, 0x16($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X16);
    // 0x800AAD3C: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x800AAD40: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAD44: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x800AAD48: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800AAD4C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AAD50: lw          $t6, 0x2834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2834);
    // 0x800AAD54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AAD58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAD5C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAD60: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800AAD64: mflo        $t4
    ctx->r12 = lo;
    // 0x800AAD68: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800AAD6C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800AAD70: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AAD74: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x800AAD78: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800AAD7C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AAD80: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AAD84: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800AAD88: jal         0x80078D00
    // 0x800AAD8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x800AAD8C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800AAD90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAD94: jal         0x8007B3D0
    // 0x800AAD98: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x800AAD98: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_11:
    // 0x800AAD9C: b           L_800AAF04
    // 0x800AADA0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AAF04;
    // 0x800AADA0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AADA4:
    // 0x800AADA4: beq         $t9, $zero, L_800AAE28
    if (ctx->r25 == 0) {
        // 0x800AADA8: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_800AAE28;
    }
    // 0x800AADA8: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800AADAC: jal         0x80069D20
    // 0x800AADB0: nop

    cam_get_active_camera(rdram, ctx);
        goto after_12;
    // 0x800AADB0: nop

    after_12:
    // 0x800AADB4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AADB8: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800AADBC: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800AADC0: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AADC4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AADC8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x800AADCC: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800AADD0: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800AADD4: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800AADD8: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800AADDC: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800AADE0: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x800AADE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AADE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AADEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AADF0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800AADF4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800AADF8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AADFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800AAE00: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800AAE04: jal         0x80068BF4
    // 0x800AAE08: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    render_ortho_triangle_image(rdram, ctx);
        goto after_13;
    // 0x800AAE08: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_13:
    // 0x800AAE0C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAE10: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800AAE14: lh          $t5, 0x4($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X4);
    // 0x800AAE18: nop

    // 0x800AAE1C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800AAE20: b           L_800AAF00
    // 0x800AAE24: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
        goto L_800AAF00;
    // 0x800AAE24: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800AAE28:
    // 0x800AAE28: beq         $t6, $zero, L_800AAEA8
    if (ctx->r14 == 0) {
        // 0x800AAE2C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800AAEA8;
    }
    // 0x800AAE2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAE30: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AAE34: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800AAE38: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800AAE3C: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800AAE40: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800AAE44: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800AAE48: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x800AAE4C: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800AAE50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAE54: sh          $t5, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r13;
    // 0x800AAE58: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x800AAE5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AAE60: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x800AAE64: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAE68: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AAE6C: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x800AAE70: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAE74: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800AAE78: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800AAE7C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AAE80: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800AAE84: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x800AAE88: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AAE8C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAE90: sb          $zero, 0x3A($a3)
    MEM_B(0X3A, ctx->r7) = 0;
    // 0x800AAE94: sb          $t6, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r14;
    // 0x800AAE98: jal         0x80012D5C
    // 0x800AAE9C: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    render_object(rdram, ctx);
        goto after_14;
    // 0x800AAE9C: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    after_14:
    // 0x800AAEA0: b           L_800AAF04
    // 0x800AAEA4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
        goto L_800AAF04;
    // 0x800AAEA4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AAEA8:
    // 0x800AAEA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AAEAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AAEB0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800AAEB4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800AAEB8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AAEBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800AAEC0: jal         0x80069484
    // 0x800AAEC4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_15;
    // 0x800AAEC4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x800AAEC8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AAECC: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800AAED0: addiu       $t1, $t1, 0x6CF4
    ctx->r9 = ADD32(ctx->r9, 0X6CF4);
    // 0x800AAED4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800AAED8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800AAEDC: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800AAEE0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800AAEE4: nop

    // 0x800AAEE8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AAEEC: jal         0x800AAFD0
    // 0x800AAEF0: nop

    hud_draw_model(rdram, ctx);
        goto after_16;
    // 0x800AAEF0: nop

    after_16:
    // 0x800AAEF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AAEF8: jal         0x80069A40
    // 0x800AAEFC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    mtx_pop(rdram, ctx);
        goto after_17;
    // 0x800AAEFC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_17:
L_800AAF00:
    // 0x800AAF00: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
L_800AAF04:
    // 0x800AAF04: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800AAF08: beq         $t0, $at, L_800AAF90
    if (ctx->r8 == ctx->r1) {
        // 0x800AAF0C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800AAF90;
    }
    // 0x800AAF0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AAF10: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800AAF14: beq         $t0, $at, L_800AAF68
    if (ctx->r8 == ctx->r1) {
        // 0x800AAF18: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800AAF68;
    }
    // 0x800AAF18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAF1C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800AAF20: beq         $t0, $at, L_800AAF68
    if (ctx->r8 == ctx->r1) {
        // 0x800AAF24: slti        $at, $t0, 0x2F
        ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
            goto L_800AAF68;
    }
    // 0x800AAF24: slti        $at, $t0, 0x2F
    ctx->r1 = SIGNED(ctx->r8) < 0X2F ? 1 : 0;
    // 0x800AAF28: bne         $at, $zero, L_800AAF34
    if (ctx->r1 != 0) {
        // 0x800AAF2C: slti        $at, $t0, 0x36
        ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
            goto L_800AAF34;
    }
    // 0x800AAF2C: slti        $at, $t0, 0x36
    ctx->r1 = SIGNED(ctx->r8) < 0X36 ? 1 : 0;
    // 0x800AAF30: bne         $at, $zero, L_800AAF68
    if (ctx->r1 != 0) {
        // 0x800AAF34: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800AAF68;
    }
L_800AAF34:
    // 0x800AAF34: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800AAF38: beq         $t0, $at, L_800AAF68
    if (ctx->r8 == ctx->r1) {
        // 0x800AAF3C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800AAF68;
    }
    // 0x800AAF3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AAF40: lb          $t5, 0x6CD3($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X6CD3);
    // 0x800AAF44: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800AAF48: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x800AAF4C: beq         $t4, $zero, L_800AAF68
    if (ctx->r12 == 0) {
        // 0x800AAF50: nop
    
            goto L_800AAF68;
    }
    // 0x800AAF50: nop

    // 0x800AAF54: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800AAF58: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AAF5C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AAF60: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AAF64: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800AAF68:
    // 0x800AAF68: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AAF6C: lw          $t7, 0x6D28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D28);
    // 0x800AAF70: lw          $t9, 0x6D24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D24);
    // 0x800AAF74: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AAF78: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800AAF7C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800AAF80: nop

    // 0x800AAF84: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AAF88: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AAF8C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_800AAF90:
    // 0x800AAF90: lw          $t3, 0x6CFC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6CFC);
    // 0x800AAF94: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAF98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AAF9C: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800AAFA0: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800AAFA4: lw          $t4, 0x6D00($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D00);
    // 0x800AAFA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AAFAC: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800AAFB0: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800AAFB4: lw          $t9, 0x6D04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D04);
    // 0x800AAFB8: nop

    // 0x800AAFBC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_800AAFC0:
    extern void dkr_hud_element_end(uint8_t*, recomp_context*); dkr_hud_element_end(rdram, ctx);
    // 0x800AAFC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AAFC4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AAFC8: jr          $ra
    // 0x800AAFCC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800AAFCC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void memset_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B490C: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4910: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B4918: beq         $v1, $zero, L_800B4938
    if (ctx->r3 == 0) {
        // 0x800B491C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B4938;
    }
    // 0x800B491C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800B4920:
    // 0x800B4920: sltiu       $v1, $a2, 0x1
    ctx->r3 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800B4924: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800B4928: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B492C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800B4930: bne         $v1, $zero, L_800B4920
    if (ctx->r3 != 0) {
        // 0x800B4934: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800B4920;
    }
    // 0x800B4934: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800B4938:
    // 0x800B4938: jr          $ra
    // 0x800B493C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800B493C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void obj_init_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039168: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x8003916C: jal         0x80011390
    // 0x80039170: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x80039170: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    after_0:
    // 0x80039174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003917C: jr          $ra
    // 0x80039180: nop

    return;
    // 0x80039180: nop

;}
RECOMP_FUNC void charselect_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; if (dkr_legacy_character_menu(rdram, ctx, 5U, dkr_character_menu_fields)) return; }
    // 0x8008BFE8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008BFEC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8008BFF0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8008BFF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008BFF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008BFFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008C000: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8008C004: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8008C008: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8008C00C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008C010: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8008C014: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8008C018: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008C01C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008C020: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C024: blez        $a2, L_8008C0C0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008C028: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8008C0C0;
    }
    // 0x8008C028: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8008C02C: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8008C030: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8008C034: beq         $s7, $t6, L_8008C0C0
    if (ctx->r23 == ctx->r14) {
        // 0x8008C038: lui         $s5, 0x40
        ctx->r21 = S32(0X40 << 16);
            goto L_8008C0C0;
    }
    // 0x8008C038: lui         $s5, 0x40
    ctx->r21 = S32(0X40 << 16);
    // 0x8008C03C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C040: addiu       $s2, $s2, 0x63E8
    ctx->r18 = ADD32(ctx->r18, 0X63E8);
L_8008C044:
    // 0x8008C044: jal         0x8009C30C
    // 0x8008C048: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8008C048: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8008C04C: and         $t7, $v0, $s5
    ctx->r15 = ctx->r2 & ctx->r21;
    // 0x8008C050: bne         $t7, $zero, L_8008C0A0
    if (ctx->r15 != 0) {
        // 0x8008C054: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008C0A0;
    }
    // 0x8008C054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008C058:
    // 0x8008C058: beq         $v0, $s4, L_8008C07C
    if (ctx->r2 == ctx->r20) {
        // 0x8008C05C: addu        $t8, $s2, $v0
        ctx->r24 = ADD32(ctx->r18, ctx->r2);
            goto L_8008C07C;
    }
    // 0x8008C05C: addu        $t8, $s2, $v0
    ctx->r24 = ADD32(ctx->r18, ctx->r2);
    // 0x8008C060: addu        $t0, $s3, $s1
    ctx->r8 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C064: lb          $t1, 0x0($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X0);
    // 0x8008C068: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x8008C06C: nop

    // 0x8008C070: bne         $t9, $t1, L_8008C07C
    if (ctx->r25 != ctx->r9) {
        // 0x8008C074: nop
    
            goto L_8008C07C;
    }
    // 0x8008C074: nop

    // 0x8008C078: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8008C07C:
    // 0x8008C07C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C080: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008C084: beq         $at, $zero, L_8008C094
    if (ctx->r1 == 0) {
        // 0x8008C088: nop
    
            goto L_8008C094;
    }
    // 0x8008C088: nop

    // 0x8008C08C: beq         $s0, $zero, L_8008C058
    if (ctx->r16 == 0) {
        // 0x8008C090: nop
    
            goto L_8008C058;
    }
    // 0x8008C090: nop

L_8008C094:
    // 0x8008C094: beq         $s0, $zero, L_8008C0A0
    if (ctx->r16 == 0) {
        // 0x8008C098: nop
    
            goto L_8008C0A0;
    }
    // 0x8008C098: nop

    // 0x8008C09C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8008C0A0:
    // 0x8008C0A0: beq         $s0, $zero, L_8008C0C0
    if (ctx->r16 == 0) {
        // 0x8008C0A4: slt         $at, $s1, $s6
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8008C0C0;
    }
    // 0x8008C0A4: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8008C0A8: beq         $at, $zero, L_8008C0C0
    if (ctx->r1 == 0) {
        // 0x8008C0AC: addu        $t2, $s3, $s1
        ctx->r10 = ADD32(ctx->r19, ctx->r17);
            goto L_8008C0C0;
    }
    // 0x8008C0AC: addu        $t2, $s3, $s1
    ctx->r10 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C0B0: lb          $t3, 0x0($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X0);
    // 0x8008C0B4: nop

    // 0x8008C0B8: bne         $s7, $t3, L_8008C044
    if (ctx->r23 != ctx->r11) {
        // 0x8008C0BC: nop
    
            goto L_8008C044;
    }
    // 0x8008C0BC: nop

L_8008C0C0:
    // 0x8008C0C0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008C0C4: bne         $s0, $zero, L_8008C0F0
    if (ctx->r16 != 0) {
        // 0x8008C0C8: addiu       $s2, $s2, 0x63E8
        ctx->r18 = ADD32(ctx->r18, 0X63E8);
            goto L_8008C0F0;
    }
    // 0x8008C0C8: addiu       $s2, $s2, 0x63E8
    ctx->r18 = ADD32(ctx->r18, 0X63E8);
    // 0x8008C0CC: addu        $t4, $s3, $s1
    ctx->r12 = ADD32(ctx->r19, ctx->r17);
    // 0x8008C0D0: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008C0D4: addu        $t6, $s2, $s4
    ctx->r14 = ADD32(ctx->r18, ctx->r20);
    // 0x8008C0D8: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8008C0DC: lhu         $a0, 0x46($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X46);
    // 0x8008C0E0: jal         0x80001D04
    // 0x8008C0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C0E8: b           L_8008C100
    // 0x8008C0EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8008C100;
    // 0x8008C0EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C0F0:
    // 0x8008C0F0: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x8008C0F4: jal         0x80001D04
    // 0x8008C0F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008C0F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008C0FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8008C100:
    // 0x8008C100: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008C104: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008C108: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C10C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008C110: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8008C114: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8008C118: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C11C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8008C120: jr          $ra
    // 0x8008C124: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008C124: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C76A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C76A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C76AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C76B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C76B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C76B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C76BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C76C0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800C76C4: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C76C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C76CC: bne         $t6, $at, L_800C7788
    if (ctx->r14 != ctx->r1) {
        // 0x800C76D0: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C7788;
    }
    // 0x800C76D0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C76D4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x800C76D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C76DC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C76E0: blez        $t7, L_800C7788
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C76E4: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C7788;
    }
    // 0x800C76E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C76E8: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
L_800C76EC:
    // 0x800C76EC: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C76F0: beq         $t9, $zero, L_800C7770
    if (ctx->r25 == 0) {
        // 0x800C76F4: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C7770;
    }
    // 0x800C76F4: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C76F8: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C76FC: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C7700: bnel        $t6, $zero, L_800C7774
    if (ctx->r14 != 0) {
        // 0x800C7704: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7774;
    }
    goto skip_0;
    // 0x800C7704: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x800C7708: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x800C770C: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C7710: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C7714: beq         $v0, $zero, L_800C772C
    if (ctx->r2 == 0) {
        // 0x800C7718: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C772C;
    }
    // 0x800C7718: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C771C: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C7720: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7724: jal         0x800C75B0
    // 0x800C7728: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_3_800C75B0(rdram, ctx);
        goto after_0;
    // 0x800C7728: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C772C:
    // 0x800C772C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x800C7730: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C7734: blezl       $t8, L_800C7774
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C7738: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_800C7774;
    }
    goto skip_1;
    // 0x800C7738: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x800C773C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
L_800C7740:
    // 0x800C7740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7744: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C7748: beq         $a0, $zero, L_800C7758
    if (ctx->r4 == 0) {
        // 0x800C774C: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C7758;
    }
    // 0x800C774C: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C7750: jal         0x800C75B0
    // 0x800C7754: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_3_800C75B0(rdram, ctx);
        goto after_1;
    // 0x800C7754: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C7758:
    // 0x800C7758: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800C775C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C7760: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C7764: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C7768: bnel        $at, $zero, L_800C7740
    if (ctx->r1 != 0) {
        // 0x800C776C: lw          $t9, 0xC($t3)
        ctx->r25 = MEM_W(ctx->r11, 0XC);
            goto L_800C7740;
    }
    goto skip_2;
    // 0x800C776C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    skip_2:
L_800C7770:
    // 0x800C7770: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_800C7774:
    // 0x800C7774: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C7778: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C777C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7780: bnel        $at, $zero, L_800C76EC
    if (ctx->r1 != 0) {
        // 0x800C7784: lw          $t8, 0x4($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X4);
            goto L_800C76EC;
    }
    goto skip_3;
    // 0x800C7784: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    skip_3:
L_800C7788:
    // 0x800C7788: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C778C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7790: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7794: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C7798: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C779C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C77A0: jr          $ra
    // 0x800C77A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C77A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C718: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C71C: lw          $t6, -0x51B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51B4);
    // 0x8000C720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000C72C: addu        $v1, $t6, $a0
    ctx->r3 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C730: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8000C734: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000C738: beq         $a1, $zero, L_8000C768
    if (ctx->r5 == 0) {
        // 0x8000C73C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8000C768;
    }
    // 0x8000C73C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C740: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8000C744: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8000C748: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000C74C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C750: lw          $t9, -0x51B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X51B8);
    // 0x8000C754: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000C758: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C75C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8000C760: b           L_8000C838
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000C838;
    // 0x8000C764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C768:
    // 0x8000C768: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8000C76C: lw          $t4, -0x529C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X529C);
    // 0x8000C770: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8000C774: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C778: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8000C77C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8000C780: lw          $a0, -0x5198($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5198);
    // 0x8000C784: subu        $a1, $t5, $a2
    ctx->r5 = SUB32(ctx->r13, ctx->r6);
    // 0x8000C788: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8000C78C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8000C790: jal         0x80070E90
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_pool(rdram, ctx);
        goto after_0;
    // 0x8000C794: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C798: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000C79C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8000C7A0: beq         $v0, $zero, L_8000C828
    if (ctx->r2 == 0) {
        // 0x8000C7A4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000C828;
    }
    // 0x8000C7A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C7A8: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8000C7AC: jal         0x80076E68
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8000C7B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000C7B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C7B8: nop

    // 0x8000C7BC: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8000C7C0: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x8000C7C4: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x8000C7C8: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x8000C7CC: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x8000C7D0: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000C7D4: addu        $t0, $a1, $t8
    ctx->r8 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C7D8: addu        $t1, $a1, $t9
    ctx->r9 = ADD32(ctx->r5, ctx->r25);
    // 0x8000C7DC: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C7E0: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8000C7E4: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x8000C7E8: sw          $t0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r8;
    // 0x8000C7EC: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x8000C7F0: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x8000C7F4: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8000C7F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C7FC: lw          $t6, -0x51B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51B8);
    // 0x8000C800: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000C804: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000C808: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000C80C: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x8000C810: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000C814: lw          $t9, -0x51B4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X51B4);
    // 0x8000C818: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000C81C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000C820: b           L_8000C830
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
        goto L_8000C830;
    // 0x8000C824: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
L_8000C828:
    // 0x8000C828: b           L_8000C834
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C834;
    // 0x8000C82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C830:
    // 0x8000C830: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000C834:
    // 0x8000C834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C838:
    // 0x8000C838: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000C83C: jr          $ra
    // 0x8000C840: nop

    return;
    // 0x8000C840: nop

;}
RECOMP_FUNC void update_player_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DE38: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8004DE3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004DE40: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004DE44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004DE48: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004DE4C: jal         0x80066210
    // 0x8004DE50: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004DE50: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004DE54: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004DE58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004DE5C: sw          $t6, -0x3468($at)
    MEM_W(-0X3468, ctx->r1) = ctx->r14;
    // 0x8004DE60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE64: jal         0x8001139C
    // 0x8004DE68: sb          $zero, -0x2A7F($at)
    MEM_B(-0X2A7F, ctx->r1) = 0;
    get_race_countdown(rdram, ctx);
        goto after_1;
    // 0x8004DE68: sb          $zero, -0x2A7F($at)
    MEM_B(-0X2A7F, ctx->r1) = 0;
    after_1:
    // 0x8004DE6C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004DE70: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004DE74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE78: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8004DE7C: sw          $v0, -0x2AC0($at)
    MEM_W(-0X2AC0, ctx->r1) = ctx->r2;
    // 0x8004DE80: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004DE84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004DE88: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8004DE8C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DE90: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004DE94: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8004DE98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004DE9C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DEA0: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x8004DEA4: bc1f        L_8004DEB8
    if (!c1cs) {
        // 0x8004DEA8: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_8004DEB8;
    }
    // 0x8004DEA8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004DEAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004DEB0: nop

    // 0x8004DEB4: swc1        $f14, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f14.u32l;
L_8004DEB8:
    // 0x8004DEB8: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004DEBC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004DEC0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DEC4: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004DEC8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004DECC: bc1f        L_8004DED8
    if (!c1cs) {
        // 0x8004DED0: lui         $at, 0xC049
        ctx->r1 = S32(0XC049 << 16);
            goto L_8004DED8;
    }
    // 0x8004DED0: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8004DED4: swc1        $f14, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f14.u32l;
L_8004DED8:
    // 0x8004DED8: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004DEDC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8004DEE0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DEE4: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DEE8: nop

    // 0x8004DEEC: bc1f        L_8004DEF8
    if (!c1cs) {
        // 0x8004DEF0: nop
    
            goto L_8004DEF8;
    }
    // 0x8004DEF0: nop

    // 0x8004DEF4: swc1        $f14, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f14.u32l;
L_8004DEF8:
    // 0x8004DEF8: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004DEFC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004DF00: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF04: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004DF08: nop

    // 0x8004DF0C: bc1f        L_8004DF20
    if (!c1cs) {
        // 0x8004DF10: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_8004DF20;
    }
    // 0x8004DF10: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8004DF14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004DF18: nop

    // 0x8004DF1C: swc1        $f12, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f12.u32l;
L_8004DF20:
    // 0x8004DF20: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004DF24: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8004DF28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DF2C: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004DF30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004DF34: bc1f        L_8004DF40
    if (!c1cs) {
        // 0x8004DF38: lui         $at, 0xBFF0
        ctx->r1 = S32(0XBFF0 << 16);
            goto L_8004DF40;
    }
    // 0x8004DF38: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x8004DF3C: swc1        $f12, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f12.u32l;
L_8004DF40:
    // 0x8004DF40: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004DF44: nop

    // 0x8004DF48: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF4C: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004DF50: nop

    // 0x8004DF54: bc1f        L_8004DF60
    if (!c1cs) {
        // 0x8004DF58: nop
    
            goto L_8004DF60;
    }
    // 0x8004DF58: nop

    // 0x8004DF5C: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
L_8004DF60:
    // 0x8004DF60: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004DF64: nop

    // 0x8004DF68: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DF6C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8004DF70: nop

    // 0x8004DF74: bc1f        L_8004DF80
    if (!c1cs) {
        // 0x8004DF78: nop
    
            goto L_8004DF80;
    }
    // 0x8004DF78: nop

    // 0x8004DF7C: swc1        $f14, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f14.u32l;
L_8004DF80:
    // 0x8004DF80: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004DF84: nop

    // 0x8004DF88: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DF8C: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004DF90: nop

    // 0x8004DF94: bc1f        L_8004DFA0
    if (!c1cs) {
        // 0x8004DF98: nop
    
            goto L_8004DFA0;
    }
    // 0x8004DF98: nop

    // 0x8004DF9C: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
L_8004DFA0:
    // 0x8004DFA0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004DFA4: nop

    // 0x8004DFA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DFAC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004DFB0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004DFB4: bc1f        L_8004DFC0
    if (!c1cs) {
        // 0x8004DFB8: nop
    
            goto L_8004DFC0;
    }
    // 0x8004DFB8: nop

    // 0x8004DFBC: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
L_8004DFC0:
    // 0x8004DFC0: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004DFC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004DFC8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004DFCC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004DFD0: nop

    // 0x8004DFD4: bc1f        L_8004DFE0
    if (!c1cs) {
        // 0x8004DFD8: nop
    
            goto L_8004DFE0;
    }
    // 0x8004DFD8: nop

    // 0x8004DFDC: swc1        $f12, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f12.u32l;
L_8004DFE0:
    // 0x8004DFE0: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004DFE4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004DFE8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004DFEC: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8004DFF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004DFF4: bc1f        L_8004E014
    if (!c1cs) {
        // 0x8004DFF8: nop
    
            goto L_8004E014;
    }
    // 0x8004DFF8: nop

    // 0x8004DFFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E000: nop

    // 0x8004E004: swc1        $f10, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f10.u32l;
    // 0x8004E008: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004E00C: nop

    // 0x8004E010: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_8004E014:
    // 0x8004E014: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E018: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004E01C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E020: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8004E024: nop

    // 0x8004E028: bc1f        L_8004E03C
    if (!c1cs) {
        // 0x8004E02C: nop
    
            goto L_8004E03C;
    }
    // 0x8004E02C: nop

    // 0x8004E030: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E034: nop

    // 0x8004E038: swc1        $f8, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f8.u32l;
L_8004E03C:
    // 0x8004E03C: lbu         $t7, 0x1FE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E044: bne         $t7, $at, L_8004E050
    if (ctx->r15 != ctx->r1) {
        // 0x8004E048: nop
    
            goto L_8004E050;
    }
    // 0x8004E048: nop

    // 0x8004E04C: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004E050:
    // 0x8004E050: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8004E054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E058: bne         $t8, $zero, L_8004E074
    if (ctx->r24 != 0) {
        // 0x8004E05C: nop
    
            goto L_8004E074;
    }
    // 0x8004E05C: nop

    // 0x8004E060: lwc1        $f5, 0x6590($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6590);
    // 0x8004E064: lwc1        $f4, 0x6594($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6594);
    // 0x8004E068: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004E06C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004E070: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
L_8004E074:
    // 0x8004E074: lb          $t9, 0x1F6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1F6);
    // 0x8004E078: nop

    // 0x8004E07C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x8004E080: sb          $t0, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r8;
    // 0x8004E084: lb          $t1, 0x1F6($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1F6);
    // 0x8004E088: nop

    // 0x8004E08C: bgez        $t1, L_8004E098
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8004E090: nop
    
            goto L_8004E098;
    }
    // 0x8004E090: nop

    // 0x8004E094: sb          $zero, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = 0;
L_8004E098:
    // 0x8004E098: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8004E09C: lb          $v0, 0x201($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X201);
    // 0x8004E0A0: nop

    // 0x8004E0A4: blez        $v0, L_8004E0B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E0A8: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_8004E0B4;
    }
    // 0x8004E0A8: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x8004E0AC: b           L_8004E0B8
    // 0x8004E0B0: sb          $t2, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r10;
        goto L_8004E0B8;
    // 0x8004E0B0: sb          $t2, 0x201($s0)
    MEM_B(0X201, ctx->r16) = ctx->r10;
L_8004E0B4:
    // 0x8004E0B4: sb          $zero, 0x201($s0)
    MEM_B(0X201, ctx->r16) = 0;
L_8004E0B8:
    // 0x8004E0B8: jal         0x8006BDB0
    // 0x8004E0BC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    level_header(rdram, ctx);
        goto after_2;
    // 0x8004E0BC: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8004E0C0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8004E0C4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004E0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E0CC: swc1        $f8, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = ctx->f8.u32l;
    // 0x8004E0D0: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004E0D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E0D8: bne         $v1, $at, L_8004E0FC
    if (ctx->r3 != ctx->r1) {
        // 0x8004E0DC: sb          $zero, 0x20C($s0)
        MEM_B(0X20C, ctx->r16) = 0;
            goto L_8004E0FC;
    }
    // 0x8004E0DC: sb          $zero, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = 0;
    // 0x8004E0E0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E0E4: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8004E0E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E0EC: jal         0x8005A6F0
    // 0x8004E0F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_AI_racer(rdram, ctx);
        goto after_3;
    // 0x8004E0F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8004E0F4: b           L_8004F76C
    // 0x8004E0F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8004F76C;
    // 0x8004E0F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004E0FC:
    // 0x8004E0FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004E100: lw          $t3, -0x2AC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC0);
    // 0x8004E104: nop

    // 0x8004E108: bne         $t3, $zero, L_8004E168
    if (ctx->r11 != 0) {
        // 0x8004E10C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004E168;
    }
    // 0x8004E10C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004E110: bne         $v1, $zero, L_8004E168
    if (ctx->r3 != 0) {
        // 0x8004E114: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004E168;
    }
    // 0x8004E114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004E118: jal         0x8009C30C
    // 0x8004E11C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8004E11C: nop

    after_4:
    // 0x8004E120: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x8004E124: beq         $t4, $zero, L_8004E164
    if (ctx->r12 == 0) {
        // 0x8004E128: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8004E164;
    }
    // 0x8004E128: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004E12C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E130: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004E134: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E138: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E13C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8004E140: swc1        $f9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x8004E144: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E148: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8004E14C: mfc1        $a2, $f5
    ctx->r6 = (int32_t)ctx->f_odd[(5 - 1) * 2];
    // 0x8004E150: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E154: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8004E158: swc1        $f5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8004E15C: jal         0x800B5EDC
    // 0x8004E160: addiu       $a0, $a0, 0x6280
    ctx->r4 = ADD32(ctx->r4, 0X6280);
    render_printf(rdram, ctx);
        goto after_5;
    // 0x8004E160: addiu       $a0, $a0, 0x6280
    ctx->r4 = ADD32(ctx->r4, 0X6280);
    after_5:
L_8004E164:
    // 0x8004E164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8004E168:
    // 0x8004E168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004E16C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E170: jal         0x800B62B4
    // 0x8004E174: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_6;
    // 0x8004E174: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_6:
    // 0x8004E178: jal         0x8002341C
    // 0x8004E17C: nop

    is_taj_challenge(rdram, ctx);
        goto after_7;
    // 0x8004E17C: nop

    after_7:
    // 0x8004E180: beq         $v0, $zero, L_8004E18C
    if (ctx->r2 == 0) {
        // 0x8004E184: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E18C;
    }
    // 0x8004E184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E188: sh          $zero, -0x2A7A($at)
    MEM_H(-0X2A7A, ctx->r1) = 0;
L_8004E18C:
    // 0x8004E18C: jal         0x8006DA0C
    // 0x8004E190: nop

    get_game_mode(rdram, ctx);
        goto after_8;
    // 0x8004E190: nop

    after_8:
    // 0x8004E194: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004E198: lw          $t5, -0x2AC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC0);
    // 0x8004E19C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8004E1A0: bne         $t5, $zero, L_8004E1E4
    if (ctx->r13 != 0) {
        // 0x8004E1A4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8004E1E4;
    }
    // 0x8004E1A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004E1A8: addiu       $v0, $v0, -0x2ABC
    ctx->r2 = ADD32(ctx->r2, -0X2ABC);
    // 0x8004E1AC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004E1B0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004E1B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E1B8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004E1BC: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8004E1C0: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E1C4: bc1f        L_8004E1D8
    if (!c1cs) {
        // 0x8004E1C8: nop
    
            goto L_8004E1D8;
    }
    // 0x8004E1C8: nop

    // 0x8004E1CC: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8004E1D0: b           L_8004E1F8
    // 0x8004E1D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_8004E1F8;
    // 0x8004E1D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_8004E1D8:
    // 0x8004E1D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E1DC: b           L_8004E1F8
    // 0x8004E1E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_8004E1F8;
    // 0x8004E1E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8004E1E4:
    // 0x8004E1E4: addiu       $a0, $zero, -0x3C
    ctx->r4 = ADD32(0, -0X3C);
    // 0x8004E1E8: jal         0x8006F94C
    // 0x8004E1EC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x8004E1EC: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_9:
    // 0x8004E1F0: addiu       $t6, $v0, 0x78
    ctx->r14 = ADD32(ctx->r2, 0X78);
    // 0x8004E1F4: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
L_8004E1F8:
    // 0x8004E1F8: lh          $v0, 0x18C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18C);
    // 0x8004E1FC: nop

    // 0x8004E200: blez        $v0, L_8004E21C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E204: nop
    
            goto L_8004E21C;
    }
    // 0x8004E204: nop

    // 0x8004E208: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E20C: nop

    // 0x8004E210: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8004E214: b           L_8004E220
    // 0x8004E218: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
        goto L_8004E220;
    // 0x8004E218: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
L_8004E21C:
    // 0x8004E21C: sh          $zero, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = 0;
L_8004E220:
    // 0x8004E220: jal         0x8001E29C
    // 0x8004E224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    get_misc_asset(rdram, ctx);
        goto after_10;
    // 0x8004E224: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_10:
    // 0x8004E228: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004E22C: addiu       $a1, $a1, -0x2A9C
    ctx->r5 = ADD32(ctx->r5, -0X2A9C);
    // 0x8004E230: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8004E234: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x8004E238: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E23C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8004E240: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8004E244: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8004E248: lwc1        $f5, 0x6598($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6598);
    // 0x8004E24C: lwc1        $f4, 0x659C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X659C);
    // 0x8004E250: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E254: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004E258: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E25C: addiu       $v1, $v1, -0x2A94
    ctx->r3 = ADD32(ctx->r3, -0X2A94);
    // 0x8004E260: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004E264: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8004E268: lh          $t3, 0x204($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X204);
    // 0x8004E26C: nop

    // 0x8004E270: blez        $t3, L_8004E284
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004E274: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004E284;
    }
    // 0x8004E274: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E278: lwc1        $f10, 0x65A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65A0);
    // 0x8004E27C: nop

    // 0x8004E280: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_8004E284:
    // 0x8004E284: jal         0x8001E29C
    // 0x8004E288: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x8004E288: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_11:
    // 0x8004E28C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004E290: addiu       $a1, $a1, -0x2A9C
    ctx->r5 = ADD32(ctx->r5, -0X2A9C);
    // 0x8004E294: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8004E298: lb          $t5, 0x3($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X3);
    // 0x8004E29C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E2A0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8004E2A4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8004E2A8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8004E2AC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8004E2B0: jal         0x8001E29C
    // 0x8004E2B4: swc1        $f4, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f4.u32l;
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8004E2B4: swc1        $f4, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->f4.u32l;
    after_12:
    // 0x8004E2B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E2BC: sw          $v0, -0x2A9C($at)
    MEM_W(-0X2A9C, ctx->r1) = ctx->r2;
    // 0x8004E2C0: lb          $t0, 0x3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X3);
    // 0x8004E2C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004E2C8: lw          $t8, -0x2A9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A9C);
    // 0x8004E2CC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004E2D0: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8004E2D4: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004E2D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E2DC: swc1        $f6, -0x2A8C($at)
    MEM_W(-0X2A8C, ctx->r1) = ctx->f6.u32l;
    // 0x8004E2E0: lbu         $a0, 0x1FE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E2E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E2E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E2EC: bne         $a0, $at, L_8004E334
    if (ctx->r4 != ctx->r1) {
        // 0x8004E2F0: addiu       $v1, $v1, -0x2A94
        ctx->r3 = ADD32(ctx->r3, -0X2A94);
            goto L_8004E334;
    }
    // 0x8004E2F0: addiu       $v1, $v1, -0x2A94
    ctx->r3 = ADD32(ctx->r3, -0X2A94);
    // 0x8004E2F4: lbu         $t2, 0x1FF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E2F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8004E2FC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8004E300: bgez        $t2, L_8004E314
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8004E304: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8004E314;
    }
    // 0x8004E304: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004E308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E30C: nop

    // 0x8004E310: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8004E314:
    // 0x8004E314: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8004E318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E31C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E320: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004E324: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004E328: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8004E32C: lbu         $a0, 0x1FE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E330: nop

L_8004E334:
    // 0x8004E334: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004E338: bne         $a0, $at, L_8004E3A0
    if (ctx->r4 != ctx->r1) {
        // 0x8004E33C: nop
    
            goto L_8004E3A0;
    }
    // 0x8004E33C: nop

    // 0x8004E340: lbu         $t3, 0x1FF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E344: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E348: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8004E34C: bgez        $t3, L_8004E364
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8004E350: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8004E364;
    }
    // 0x8004E350: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004E354: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8004E358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004E35C: nop

    // 0x8004E360: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8004E364:
    // 0x8004E364: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E368: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004E36C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004E370: nop

    // 0x8004E374: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004E378: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004E37C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8004E380: lh          $t5, 0x204($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X204);
    // 0x8004E384: nop

    // 0x8004E388: blez        $t5, L_8004E3A0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004E38C: nop
    
            goto L_8004E3A0;
    }
    // 0x8004E38C: nop

    // 0x8004E390: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004E394: nop

    // 0x8004E398: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8004E39C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_8004E3A0:
    // 0x8004E3A0: lbu         $t4, 0x1FE($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004E3A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004E3A8: bne         $t4, $at, L_8004E468
    if (ctx->r12 != ctx->r1) {
        // 0x8004E3AC: nop
    
            goto L_8004E468;
    }
    // 0x8004E3AC: nop

    // 0x8004E3B0: lbu         $t6, 0x1FF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E3B4: nop

    // 0x8004E3B8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8004E3BC: jal         0x800707C4
    // 0x8004E3C0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    sins_f(rdram, ctx);
        goto after_13;
    // 0x8004E3C0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_13:
    // 0x8004E3C4: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E3C8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E3CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004E3D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004E3D4: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E3D8: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004E3DC: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004E3E0: cvt.d.s     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f14.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E3E4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E3E8: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8004E3EC: lbu         $t8, 0x1FF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1FF);
    // 0x8004E3F0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E3F4: mul.d       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8004E3F8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004E3FC: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8004E400: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004E404: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8004E408: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8004E40C: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004E410: swc1        $f6, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f6.u32l;
    // 0x8004E414: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8004E418: jal         0x800707F8
    // 0x8004E41C: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
    coss_f(rdram, ctx);
        goto after_14;
    // 0x8004E41C: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
    after_14:
    // 0x8004E420: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E424: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E428: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004E42C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004E430: lwc1        $f2, 0x88($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004E434: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004E438: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E43C: lwc1        $f9, 0x50($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004E440: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8004E444: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004E448: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E44C: mul.d       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8004E450: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8004E454: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8004E458: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x8004E45C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8004E460: b           L_8004E4C4
    // 0x8004E464: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
        goto L_8004E4C4;
    // 0x8004E464: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
L_8004E468:
    // 0x8004E468: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004E46C: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x8004E470: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004E474: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004E478: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8004E47C: mul.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x8004E480: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8004E484: nop

    // 0x8004E488: cvt.d.s     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f14.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E48C: mul.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x8004E490: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004E494: nop

    // 0x8004E498: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8004E49C: sub.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d - ctx->f8.d;
    // 0x8004E4A0: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x8004E4A4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004E4A8: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8004E4AC: mul.d       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8004E4B0: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x8004E4B4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004E4B8: swc1        $f4, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f4.u32l;
    // 0x8004E4BC: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8004E4C0: swc1        $f15, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(15 - 1) * 2];
L_8004E4C4:
    // 0x8004E4C4: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8004E4C8: nop

    // 0x8004E4CC: lbu         $a0, 0x5C($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X5C);
    // 0x8004E4D0: jal         0x8001E29C
    // 0x8004E4D4: nop

    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8004E4D4: nop

    after_15:
    // 0x8004E4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E4DC: sw          $v0, -0x2A9C($at)
    MEM_W(-0X2A9C, ctx->r1) = ctx->r2;
    // 0x8004E4E0: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x8004E4E4: nop

    // 0x8004E4E8: lbu         $a0, 0x5D($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X5D);
    // 0x8004E4EC: jal         0x8001E29C
    // 0x8004E4F0: nop

    get_misc_asset(rdram, ctx);
        goto after_16;
    // 0x8004E4F0: nop

    after_16:
    // 0x8004E4F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E4F8: sw          $v0, -0x2A98($at)
    MEM_W(-0X2A98, ctx->r1) = ctx->r2;
    // 0x8004E4FC: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004E500: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004E504: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004E508: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004E50C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E510: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8004E514: nop

    // 0x8004E518: bc1f        L_8004E558
    if (!c1cs) {
        // 0x8004E51C: nop
    
            goto L_8004E558;
    }
    // 0x8004E51C: nop

    // 0x8004E520: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004E524: nop

    // 0x8004E528: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8004E52C: beq         $at, $zero, L_8004E554
    if (ctx->r1 == 0) {
        // 0x8004E530: nop
    
            goto L_8004E554;
    }
    // 0x8004E530: nop

    // 0x8004E534: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004E538: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004E53C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004E540: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004E544: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8004E548: nop

    // 0x8004E54C: bc1t        L_8004E558
    if (c1cs) {
        // 0x8004E550: nop
    
            goto L_8004E558;
    }
    // 0x8004E550: nop

L_8004E554:
    // 0x8004E554: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004E558:
    // 0x8004E558: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004E55C: nop

    // 0x8004E560: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x8004E564: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004E568: nop

    // 0x8004E56C: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8004E570: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004E574: nop

    // 0x8004E578: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8004E57C: lh          $v0, 0x1B2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1B2);
    // 0x8004E580: nop

    // 0x8004E584: blez        $v0, L_8004E5B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E588: nop
    
            goto L_8004E5B0;
    }
    // 0x8004E588: nop

    // 0x8004E58C: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E590: nop

    // 0x8004E594: subu        $t6, $v0, $t4
    ctx->r14 = SUB32(ctx->r2, ctx->r12);
    // 0x8004E598: sh          $t6, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r14;
    // 0x8004E59C: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x8004E5A0: nop

    // 0x8004E5A4: bgez        $t7, L_8004E5B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8004E5A8: nop
    
            goto L_8004E5B0;
    }
    // 0x8004E5A8: nop

    // 0x8004E5AC: sh          $zero, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = 0;
L_8004E5B0:
    // 0x8004E5B0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004E5B4: jal         0x800665E8
    // 0x8004E5B8: nop

    set_active_camera(rdram, ctx);
        goto after_17;
    // 0x8004E5B8: nop

    after_17:
    // 0x8004E5BC: jal         0x80069CFC
    // 0x8004E5C0: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_18;
    // 0x8004E5C0: nop

    after_18:
    // 0x8004E5C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E5C8: sw          $v0, -0x2AF8($at)
    MEM_W(-0X2AF8, ctx->r1) = ctx->r2;
    // 0x8004E5CC: lb          $t0, 0x1E7($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E7);
    // 0x8004E5D0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004E5D4: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8004E5D8: sb          $t8, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r24;
    // 0x8004E5DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E5E0: sw          $t9, -0x2AA4($at)
    MEM_W(-0X2AA4, ctx->r1) = ctx->r25;
    // 0x8004E5E4: lb          $t1, 0x1D8($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004E5E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004E5EC: beq         $a3, $t1, L_8004E604
    if (ctx->r7 == ctx->r9) {
        // 0x8004E5F0: nop
    
            goto L_8004E604;
    }
    // 0x8004E5F0: nop

    // 0x8004E5F4: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8004E5F8: nop

    // 0x8004E5FC: bne         $t2, $a3, L_8004E628
    if (ctx->r10 != ctx->r7) {
        // 0x8004E600: nop
    
            goto L_8004E628;
    }
    // 0x8004E600: nop

L_8004E604:
    // 0x8004E604: lh          $t5, 0x18E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18E);
    // 0x8004E608: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8004E60C: slti        $at, $t5, 0x6
    ctx->r1 = SIGNED(ctx->r13) < 0X6 ? 1 : 0;
    // 0x8004E610: sb          $a3, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r7;
    // 0x8004E614: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
    // 0x8004E618: bne         $at, $zero, L_8004E628
    if (ctx->r1 != 0) {
        // 0x8004E61C: sb          $zero, 0x1C9($s0)
        MEM_B(0X1C9, ctx->r16) = 0;
            goto L_8004E628;
    }
    // 0x8004E61C: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x8004E620: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8004E624: sh          $t4, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r12;
L_8004E628:
    // 0x8004E628: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004E62C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E630: beq         $v1, $at, L_8004E6F4
    if (ctx->r3 == ctx->r1) {
        // 0x8004E634: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8004E6F4;
    }
    // 0x8004E634: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E638: lw          $t6, 0x108($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X108);
    // 0x8004E63C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E640: bne         $t6, $zero, L_8004E6E0
    if (ctx->r14 != 0) {
        // 0x8004E644: nop
    
            goto L_8004E6E0;
    }
    // 0x8004E644: nop

    // 0x8004E648: jal         0x8000E158
    // 0x8004E64C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    is_race_started_by_player_two(rdram, ctx);
        goto after_19;
    // 0x8004E64C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    after_19:
    // 0x8004E650: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E654: beq         $v0, $zero, L_8004E660
    if (ctx->r2 == 0) {
        // 0x8004E658: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8004E660;
    }
    // 0x8004E658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004E65C: subu        $a2, $t7, $a2
    ctx->r6 = SUB32(ctx->r15, ctx->r6);
L_8004E660:
    // 0x8004E660: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004E664: jal         0x8006A59C
    // 0x8004E668: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    input_clamp_stick_x(rdram, ctx);
        goto after_20;
    // 0x8004E668: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_20:
    // 0x8004E66C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E670: jal         0x8009C30C
    // 0x8004E674: sw          $v0, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r2;
    get_filtered_cheats(rdram, ctx);
        goto after_21;
    // 0x8004E674: sw          $v0, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r2;
    after_21:
    // 0x8004E678: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E67C: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x8004E680: beq         $t0, $zero, L_8004E69C
    if (ctx->r8 == 0) {
        // 0x8004E684: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004E69C;
    }
    // 0x8004E684: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004E688: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004E68C: lw          $t8, -0x2ACC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2ACC);
    // 0x8004E690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E694: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8004E698: sw          $t9, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r25;
L_8004E69C:
    // 0x8004E69C: jal         0x8006A5E0
    // 0x8004E6A0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    input_clamp_stick_y(rdram, ctx);
        goto after_22;
    // 0x8004E6A0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_22:
    // 0x8004E6A4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6AC: jal         0x8006A528
    // 0x8004E6B0: sw          $v0, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r2;
    input_held(rdram, ctx);
        goto after_23;
    // 0x8004E6B0: sw          $v0, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r2;
    after_23:
    // 0x8004E6B4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6BC: jal         0x8006A554
    // 0x8004E6C0: sw          $v0, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_24;
    // 0x8004E6C0: sw          $v0, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r2;
    after_24:
    // 0x8004E6C4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8004E6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6CC: jal         0x8006A578
    // 0x8004E6D0: sw          $v0, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = ctx->r2;
    input_released(rdram, ctx);
        goto after_25;
    // 0x8004E6D0: sw          $v0, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = ctx->r2;
    after_25:
    // 0x8004E6D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E6D8: b           L_8004E700
    // 0x8004E6DC: sw          $v0, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = ctx->r2;
        goto L_8004E700;
    // 0x8004E6DC: sw          $v0, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = ctx->r2;
L_8004E6E0:
    // 0x8004E6E0: jal         0x8005A424
    // 0x8004E6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_enter_door(rdram, ctx);
        goto after_26;
    // 0x8004E6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8004E6E8: b           L_8004E700
    // 0x8004E6EC: nop

        goto L_8004E700;
    // 0x8004E6EC: nop

    // 0x8004E6F0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8004E6F4:
    // 0x8004E6F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E6F8: jal         0x80044170
    // 0x8004E6FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_AI_pathing_inputs(rdram, ctx);
        goto after_27;
    // 0x8004E6FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_27:
L_8004E700:
    // 0x8004E700: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004E704: lw          $t1, -0x2AD8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AD8);
    // 0x8004E708: nop

    // 0x8004E70C: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8004E710: bne         $t2, $zero, L_8004E71C
    if (ctx->r10 != 0) {
        // 0x8004E714: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004E71C;
    }
    // 0x8004E714: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004E718: sb          $t3, 0x20C($s0)
    MEM_B(0X20C, ctx->r16) = ctx->r11;
L_8004E71C:
    // 0x8004E71C: jal         0x80066510
    // 0x8004E720: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_28;
    // 0x8004E720: nop

    after_28:
    // 0x8004E724: bne         $v0, $zero, L_8004E778
    if (ctx->r2 != 0) {
        // 0x8004E728: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004E778;
    }
    // 0x8004E728: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004E72C: lw          $t5, -0x2AC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC0);
    // 0x8004E730: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004E734: beq         $t5, $at, L_8004E778
    if (ctx->r13 == ctx->r1) {
        // 0x8004E738: nop
    
            goto L_8004E778;
    }
    // 0x8004E738: nop

    // 0x8004E73C: lbu         $t4, 0x1F1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004E740: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004E744: bne         $t4, $zero, L_8004E778
    if (ctx->r12 != 0) {
        // 0x8004E748: nop
    
            goto L_8004E778;
    }
    // 0x8004E748: nop

    // 0x8004E74C: lb          $t6, -0x2A7C($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2A7C);
    // 0x8004E750: nop

    // 0x8004E754: bne         $t6, $zero, L_8004E778
    if (ctx->r14 != 0) {
        // 0x8004E758: nop
    
            goto L_8004E778;
    }
    // 0x8004E758: nop

    // 0x8004E75C: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x8004E760: nop

    // 0x8004E764: bne         $t7, $zero, L_8004E778
    if (ctx->r15 != 0) {
        // 0x8004E768: nop
    
            goto L_8004E778;
    }
    // 0x8004E768: nop

    // 0x8004E76C: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8004E770: nop

    // 0x8004E774: blez        $v0, L_8004E7A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E778: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E7A8;
    }
L_8004E778:
    // 0x8004E778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E77C: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x8004E780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E784: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8004E788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E78C: sw          $zero, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = 0;
    // 0x8004E790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E794: sw          $zero, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = 0;
    // 0x8004E798: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E79C: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x8004E7A0: lh          $v0, 0x204($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X204);
    // 0x8004E7A4: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
L_8004E7A8:
    // 0x8004E7A8: blez        $v0, L_8004E810
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E7AC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004E810;
    }
    // 0x8004E7AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E7B0: lwc1        $f0, 0x65A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65A4);
    // 0x8004E7B4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E7B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004E7BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004E7C0: subu        $t8, $v0, $t0
    ctx->r24 = SUB32(ctx->r2, ctx->r8);
    // 0x8004E7C4: sh          $t8, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r24;
    // 0x8004E7C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004E7CC: lwc1        $f10, 0x65A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65A8);
    // 0x8004E7D0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004E7D4: nop

    // 0x8004E7D8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8004E7DC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8004E7E0: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004E7E4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004E7E8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004E7EC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004E7F0: nop

    // 0x8004E7F4: bc1f        L_8004E800
    if (!c1cs) {
        // 0x8004E7F8: swc1        $f6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
            goto L_8004E800;
    }
    // 0x8004E7F8: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004E7FC: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_8004E800:
    // 0x8004E800: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004E804: nop

    // 0x8004E808: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004E80C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
L_8004E810:
    // 0x8004E810: lh          $v0, 0x206($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X206);
    // 0x8004E814: nop

    // 0x8004E818: blez        $v0, L_8004E834
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E81C: nop
    
            goto L_8004E834;
    }
    // 0x8004E81C: nop

    // 0x8004E820: sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
    // 0x8004E824: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E828: nop

    // 0x8004E82C: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x8004E830: sh          $t1, 0x206($s0)
    MEM_H(0X206, ctx->r16) = ctx->r9;
L_8004E834:
    // 0x8004E834: lh          $v0, 0x18A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18A);
    // 0x8004E838: nop

    // 0x8004E83C: blez        $v0, L_8004E894
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004E840: nop
    
            goto L_8004E894;
    }
    // 0x8004E840: nop

    // 0x8004E844: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E848: andi        $a2, $v0, 0xF
    ctx->r6 = ctx->r2 & 0XF;
    // 0x8004E84C: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x8004E850: sh          $t3, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r11;
    // 0x8004E854: lh          $t5, 0x18A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18A);
    // 0x8004E858: addiu       $a0, $zero, -0x50
    ctx->r4 = ADD32(0, -0X50);
    // 0x8004E85C: andi        $t4, $t5, 0xF
    ctx->r12 = ctx->r13 & 0XF;
    // 0x8004E860: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004E864: beq         $at, $zero, L_8004E878
    if (ctx->r1 == 0) {
        // 0x8004E868: nop
    
            goto L_8004E878;
    }
    // 0x8004E868: nop

    // 0x8004E86C: jal         0x8006F94C
    // 0x8004E870: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    rand_range(rdram, ctx);
        goto after_29;
    // 0x8004E870: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_29:
    // 0x8004E874: sb          $v0, 0x1D1($s0)
    MEM_B(0X1D1, ctx->r16) = ctx->r2;
L_8004E878:
    // 0x8004E878: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004E87C: lw          $t6, -0x2ACC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2ACC);
    // 0x8004E880: lb          $t7, 0x1D1($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D1);
    // 0x8004E884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E888: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8004E88C: b           L_8004E898
    // 0x8004E890: sw          $t0, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r8;
        goto L_8004E898;
    // 0x8004E890: sw          $t0, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r8;
L_8004E894:
    // 0x8004E894: sh          $zero, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = 0;
L_8004E898:
    // 0x8004E898: lb          $t8, 0x175($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X175);
    // 0x8004E89C: nop

    // 0x8004E8A0: beq         $t8, $zero, L_8004E8B8
    if (ctx->r24 == 0) {
        // 0x8004E8A4: nop
    
            goto L_8004E8B8;
    }
    // 0x8004E8A4: nop

    // 0x8004E8A8: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E8AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E8B0: jal         0x80056E2C
    // 0x8004E8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_activate_magnet(rdram, ctx);
        goto after_30;
    // 0x8004E8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_30:
L_8004E8B8:
    // 0x8004E8B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E8BC: lw          $v1, -0x2AC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AC0);
    // 0x8004E8C0: nop

    // 0x8004E8C4: beq         $v1, $zero, L_8004E908
    if (ctx->r3 == 0) {
        // 0x8004E8C8: nop
    
            goto L_8004E908;
    }
    // 0x8004E8C8: nop

    // 0x8004E8CC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8004E8D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004E8D4: lb          $v0, 0x4C($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4C);
    // 0x8004E8D8: nop

    // 0x8004E8DC: beq         $v0, $zero, L_8004E8F0
    if (ctx->r2 == 0) {
        // 0x8004E8E0: nop
    
            goto L_8004E8F0;
    }
    // 0x8004E8E0: nop

    // 0x8004E8E4: beq         $v0, $at, L_8004E8F0
    if (ctx->r2 == ctx->r1) {
        // 0x8004E8E8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8004E8F0;
    }
    // 0x8004E8E8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004E8EC: bne         $v0, $at, L_8004E908
    if (ctx->r2 != ctx->r1) {
        // 0x8004E8F0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004E908;
    }
L_8004E8F0:
    // 0x8004E8F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E8F4: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x8004E8F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E8FC: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8004E900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E904: sw          $zero, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = 0;
L_8004E908:
    // 0x8004E908: bne         $v1, $zero, L_8004E97C
    if (ctx->r3 != 0) {
        // 0x8004E90C: nop
    
            goto L_8004E97C;
    }
    // 0x8004E90C: nop

    // 0x8004E910: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8004E914: lb          $t1, 0x194($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X194);
    // 0x8004E918: lb          $t3, 0x4B($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X4B);
    // 0x8004E91C: nop

    // 0x8004E920: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8004E924: beq         $at, $zero, L_8004E97C
    if (ctx->r1 == 0) {
        // 0x8004E928: nop
    
            goto L_8004E97C;
    }
    // 0x8004E928: nop

    // 0x8004E92C: jal         0x8000C8B4
    // 0x8004E930: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_31;
    // 0x8004E930: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_31:
    // 0x8004E934: lb          $t5, 0x194($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X194);
    // 0x8004E938: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004E93C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8004E940: addu        $v1, $s0, $t4
    ctx->r3 = ADD32(ctx->r16, ctx->r12);
    // 0x8004E944: lw          $a0, 0x128($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X128);
    // 0x8004E948: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8004E94C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004E950: beq         $at, $zero, L_8004E960
    if (ctx->r1 == 0) {
        // 0x8004E954: addu        $t7, $a0, $a1
        ctx->r15 = ADD32(ctx->r4, ctx->r5);
            goto L_8004E960;
    }
    // 0x8004E954: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8004E958: b           L_8004E97C
    // 0x8004E95C: sw          $t7, 0x128($v1)
    MEM_W(0X128, ctx->r3) = ctx->r15;
        goto L_8004E97C;
    // 0x8004E95C: sw          $t7, 0x128($v1)
    MEM_W(0X128, ctx->r3) = ctx->r15;
L_8004E960:
    // 0x8004E960: jal         0x8000C8B4
    // 0x8004E964: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_32;
    // 0x8004E964: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_32:
    // 0x8004E968: lb          $t0, 0x194($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X194);
    // 0x8004E96C: nop

    // 0x8004E970: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8004E974: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x8004E978: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
L_8004E97C:
    // 0x8004E97C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004E980: lw          $t2, -0x2AA4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AA4);
    // 0x8004E984: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004E988: beq         $t2, $at, L_8004E9A0
    if (ctx->r10 == ctx->r1) {
        // 0x8004E98C: nop
    
            goto L_8004E9A0;
    }
    // 0x8004E98C: nop

    // 0x8004E990: jal         0x80069CFC
    // 0x8004E994: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_33;
    // 0x8004E994: nop

    after_33:
    // 0x8004E998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004E99C: sw          $v0, -0x2AF8($at)
    MEM_W(-0X2AF8, ctx->r1) = ctx->r2;
L_8004E9A0:
    // 0x8004E9A0: lh          $a0, 0x2E($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2E);
    // 0x8004E9A4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004E9A8: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8004E9AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8004E9B0: jal         0x8002B0F4
    // 0x8004E9B4: addiu       $a3, $a3, -0x2A50
    ctx->r7 = ADD32(ctx->r7, -0X2A50);
    get_level_segment_waves(rdram, ctx);
        goto after_34;
    // 0x8004E9B4: addiu       $a3, $a3, -0x2A50
    ctx->r7 = ADD32(ctx->r7, -0X2A50);
    after_34:
    // 0x8004E9B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E9BC: addiu       $v1, $v1, -0x2A52
    ctx->r3 = ADD32(ctx->r3, -0X2A52);
    // 0x8004E9C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004E9C4: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8004E9C8: nop

    // 0x8004E9CC: beq         $a0, $zero, L_8004EA34
    if (ctx->r4 == 0) {
        // 0x8004E9D0: nop
    
            goto L_8004EA34;
    }
    // 0x8004E9D0: nop

    // 0x8004E9D4: blez        $a0, L_8004EA34
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004E9D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004EA34;
    }
    // 0x8004E9D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004E9DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004E9E0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8004E9E4: lw          $v1, -0x2A50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2A50);
    // 0x8004E9E8: addiu       $a3, $a3, -0x2B10
    ctx->r7 = ADD32(ctx->r7, -0X2B10);
    // 0x8004E9EC: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8004E9F0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_8004E9F4:
    // 0x8004E9F4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004E9F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8004E9FC: lb          $t1, 0x10($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X10);
    // 0x8004EA00: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004EA04: bne         $a2, $t1, L_8004EA2C
    if (ctx->r6 != ctx->r9) {
        // 0x8004EA08: nop
    
            goto L_8004EA2C;
    }
    // 0x8004EA08: nop

    // 0x8004EA0C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8004EA10: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004EA14: nop

    // 0x8004EA18: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8004EA1C: nop

    // 0x8004EA20: bc1f        L_8004EA2C
    if (!c1cs) {
        // 0x8004EA24: nop
    
            goto L_8004EA2C;
    }
    // 0x8004EA24: nop

    // 0x8004EA28: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8004EA2C:
    // 0x8004EA2C: bne         $at, $zero, L_8004E9F4
    if (ctx->r1 != 0) {
        // 0x8004EA30: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8004E9F4;
    }
    // 0x8004EA30: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8004EA34:
    // 0x8004EA34: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004EA38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EA3C: beq         $t3, $at, L_8004EB50
    if (ctx->r11 == ctx->r1) {
        // 0x8004EA40: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004EB50;
    }
    // 0x8004EA40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004EA44: lwc1        $f10, 0x65AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65AC);
    // 0x8004EA48: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004EA4C: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x8004EA50: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EA54: addiu       $a2, $a2, -0x2B08
    ctx->r6 = ADD32(ctx->r6, -0X2B08);
    // 0x8004EA58: jal         0x8002AD08
    // 0x8004EA5C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    get_wave_properties(rdram, ctx);
        goto after_35;
    // 0x8004EA5C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_35:
    // 0x8004EA60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004EA64: addiu       $v1, $v1, -0x2AFC
    ctx->r3 = ADD32(ctx->r3, -0X2AFC);
    // 0x8004EA68: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004EA6C: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8004EA70: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EA74: beq         $t5, $zero, L_8004EAC8
    if (ctx->r13 == 0) {
        // 0x8004EA78: nop
    
            goto L_8004EAC8;
    }
    // 0x8004EA78: nop

    // 0x8004EA7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EA80: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EA84: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EA88: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004EA8C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8004EA90: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004EA94: nop

    // 0x8004EA98: bc1f        L_8004EABC
    if (!c1cs) {
        // 0x8004EA9C: nop
    
            goto L_8004EABC;
    }
    // 0x8004EA9C: nop

    // 0x8004EAA0: sb          $t4, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r12;
    // 0x8004EAA4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EAA8: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EAAC: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8004EAB0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004EAB4: b           L_8004EAF4
    // 0x8004EAB8: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
        goto L_8004EAF4;
    // 0x8004EAB8: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
L_8004EABC:
    // 0x8004EABC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004EAC0: b           L_8004EAF4
    // 0x8004EAC4: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
        goto L_8004EAF4;
    // 0x8004EAC4: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
L_8004EAC8:
    // 0x8004EAC8: lb          $v0, 0x1E5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EACC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EAD0: blez        $v0, L_8004EAE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004EAD4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8004EAE8;
    }
    // 0x8004EAD4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8004EAD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004EADC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EAE0: b           L_8004EAF4
    // 0x8004EAE4: sb          $t6, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r14;
        goto L_8004EAF4;
    // 0x8004EAE4: sb          $t6, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r14;
L_8004EAE8:
    // 0x8004EAE8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004EAEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004EAF0: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_8004EAF4:
    // 0x8004EAF4: lb          $t7, 0x1E5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EAF8: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8004EAFC: blez        $t7, L_8004EB38
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004EB00: nop
    
            goto L_8004EB38;
    }
    // 0x8004EB00: nop

    // 0x8004EB04: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004EB08: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8004EB0C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8004EB10: nop

    // 0x8004EB14: bc1f        L_8004EB38
    if (!c1cs) {
        // 0x8004EB18: nop
    
            goto L_8004EB38;
    }
    // 0x8004EB18: nop

    // 0x8004EB1C: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8004EB20: nop

    // 0x8004EB24: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x8004EB28: nop

    // 0x8004EB2C: ori         $t8, $t0, 0x10
    ctx->r24 = ctx->r8 | 0X10;
    // 0x8004EB30: b           L_8004EB50
    // 0x8004EB34: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
        goto L_8004EB50;
    // 0x8004EB34: sh          $t8, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r24;
L_8004EB38:
    // 0x8004EB38: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8004EB3C: nop

    // 0x8004EB40: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x8004EB44: nop

    // 0x8004EB48: andi        $t2, $t9, 0xFFEF
    ctx->r10 = ctx->r25 & 0XFFEF;
    // 0x8004EB4C: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
L_8004EB50:
    // 0x8004EB50: jal         0x8002ACC8
    // 0x8004EB54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_collision_mode(rdram, ctx);
        goto after_36;
    // 0x8004EB54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x8004EB58: lbu         $t1, 0x1D6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1D6);
    // 0x8004EB5C: nop

    // 0x8004EB60: sltiu       $at, $t1, 0xE
    ctx->r1 = ctx->r9 < 0XE ? 1 : 0;
    // 0x8004EB64: beq         $at, $zero, L_8004ED88
    if (ctx->r1 == 0) {
        // 0x8004EB68: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8004ED88;
    }
    // 0x8004EB68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004EB6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004EB70: addu        $at, $at, $t1
    gpr jr_addend_8004EB7C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8004EB74: lw          $t1, 0x65B0($at)
    ctx->r9 = ADD32(ctx->r1, 0X65B0);
    // 0x8004EB78: nop

    // 0x8004EB7C: jr          $t1
    // 0x8004EB80: nop

    switch (jr_addend_8004EB7C >> 2) {
        case 0: goto L_8004EB84; break;
        case 1: goto L_8004EBBC; break;
        case 2: goto L_8004EBD8; break;
        case 3: goto L_8004EBF4; break;
        case 4: goto L_8004EBA0; break;
        case 5: goto L_8004EC10; break;
        case 6: goto L_8004EC50; break;
        case 7: goto L_8004EC90; break;
        case 8: goto L_8004EC90; break;
        case 9: goto L_8004ED88; break;
        case 10: goto L_8004EBF4; break;
        case 11: goto L_8004ECD0; break;
        case 12: goto L_8004ED10; break;
        case 13: goto L_8004ED50; break;
        default: switch_error(__func__, 0x8004EB7C, 0x800E65B0);
    }
    // 0x8004EB80: nop

L_8004EB84:
    // 0x8004EB84: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EB88: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EB8C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EB90: jal         0x8004F7F4
    // 0x8004EB94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004F7F4(rdram, ctx);
        goto after_37;
    // 0x8004EB94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_37:
    // 0x8004EB98: b           L_8004ED8C
    // 0x8004EB9C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EB9C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBA0:
    // 0x8004EBA0: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBA4: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EBAC: jal         0x8004CC20
    // 0x8004EBB0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8004CC20(rdram, ctx);
        goto after_38;
    // 0x8004EBB0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_38:
    // 0x8004EBB4: b           L_8004ED8C
    // 0x8004EBB8: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EBB8: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBBC:
    // 0x8004EBBC: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBC0: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBC4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EBC8: jal         0x80046524
    // 0x8004EBCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80046524(rdram, ctx);
        goto after_39;
    // 0x8004EBCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_39:
    // 0x8004EBD0: b           L_8004ED8C
    // 0x8004EBD4: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EBD4: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBD8:
    // 0x8004EBD8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBDC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBE0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EBE4: jal         0x80049794
    // 0x8004EBE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_40;
    // 0x8004EBE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_40:
    // 0x8004EBEC: b           L_8004ED8C
    // 0x8004EBF0: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EBF0: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EBF4:
    // 0x8004EBF4: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EBF8: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EBFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC00: jal         0x8004D95C
    // 0x8004EC04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_carpet(rdram, ctx);
        goto after_41;
    // 0x8004EC04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_41:
    // 0x8004EC08: b           L_8004ED8C
    // 0x8004EC0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EC0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC10:
    // 0x8004EC10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004EC14: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004EC18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004EC1C: addiu       $t4, $t4, -0x2AC0
    ctx->r12 = ADD32(ctx->r12, -0X2AC0);
    // 0x8004EC20: addiu       $t5, $t5, -0x2AD4
    ctx->r13 = ADD32(ctx->r13, -0X2AD4);
    // 0x8004EC24: addiu       $t3, $t3, -0x2AD8
    ctx->r11 = ADD32(ctx->r11, -0X2AD8);
    // 0x8004EC28: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC2C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004EC34: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004EC38: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8004EC3C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC40: jal         0x8005C364
    // 0x8004EC44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_tricky(rdram, ctx);
        goto after_42;
    // 0x8004EC44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_42:
    // 0x8004EC48: b           L_8004ED8C
    // 0x8004EC4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EC4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC50:
    // 0x8004EC50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004EC54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004EC58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004EC5C: addiu       $t0, $t0, -0x2AC0
    ctx->r8 = ADD32(ctx->r8, -0X2AC0);
    // 0x8004EC60: addiu       $t7, $t7, -0x2AD4
    ctx->r15 = ADD32(ctx->r15, -0X2AD4);
    // 0x8004EC64: addiu       $t6, $t6, -0x2AD8
    ctx->r14 = ADD32(ctx->r14, -0X2AD8);
    // 0x8004EC68: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EC6C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004EC70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004EC74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004EC78: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8004EC7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004EC80: jal         0x8005D0D0
    // 0x8004EC84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_bluey(rdram, ctx);
        goto after_43;
    // 0x8004EC84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_43:
    // 0x8004EC88: b           L_8004ED8C
    // 0x8004EC8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004EC8C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004EC90:
    // 0x8004EC90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004EC94: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004EC98: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004EC9C: addiu       $t2, $t2, -0x2AC0
    ctx->r10 = ADD32(ctx->r10, -0X2AC0);
    // 0x8004ECA0: addiu       $t9, $t9, -0x2ACC
    ctx->r25 = ADD32(ctx->r25, -0X2ACC);
    // 0x8004ECA4: addiu       $t8, $t8, -0x2AD8
    ctx->r24 = ADD32(ctx->r24, -0X2AD8);
    // 0x8004ECA8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ECAC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ECB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004ECB4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8004ECB8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8004ECBC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ECC0: jal         0x8005D820
    // 0x8004ECC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_smokey(rdram, ctx);
        goto after_44;
    // 0x8004ECC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_44:
    // 0x8004ECC8: b           L_8004ED8C
    // 0x8004ECCC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004ECCC: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ECD0:
    // 0x8004ECD0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004ECD4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004ECD8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004ECDC: addiu       $t5, $t5, -0x2AC0
    ctx->r13 = ADD32(ctx->r13, -0X2AC0);
    // 0x8004ECE0: addiu       $t3, $t3, -0x2AD4
    ctx->r11 = ADD32(ctx->r11, -0X2AD4);
    // 0x8004ECE4: addiu       $t1, $t1, -0x2AD8
    ctx->r9 = ADD32(ctx->r9, -0X2AD8);
    // 0x8004ECE8: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ECEC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ECF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8004ECF4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8004ECF8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004ECFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED00: jal         0x8005E4C0
    // 0x8004ED04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_bubbler(rdram, ctx);
        goto after_45;
    // 0x8004ED04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_45:
    // 0x8004ED08: b           L_8004ED8C
    // 0x8004ED0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004ED0C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED10:
    // 0x8004ED10: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004ED14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004ED18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004ED1C: addiu       $t7, $t7, -0x2AC0
    ctx->r15 = ADD32(ctx->r15, -0X2AC0);
    // 0x8004ED20: addiu       $t6, $t6, -0x2AD4
    ctx->r14 = ADD32(ctx->r14, -0X2AD4);
    // 0x8004ED24: addiu       $t4, $t4, -0x2AD8
    ctx->r12 = ADD32(ctx->r12, -0X2AD8);
    // 0x8004ED28: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ED2C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ED30: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004ED34: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004ED38: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8004ED3C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED40: jal         0x8005EA90
    // 0x8004ED44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_wizpig(rdram, ctx);
        goto after_46;
    // 0x8004ED44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_46:
    // 0x8004ED48: b           L_8004ED8C
    // 0x8004ED4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
        goto L_8004ED8C;
    // 0x8004ED4C: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED50:
    // 0x8004ED50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004ED54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004ED58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004ED5C: addiu       $t9, $t9, -0x2AC0
    ctx->r25 = ADD32(ctx->r25, -0X2AC0);
    // 0x8004ED60: addiu       $t8, $t8, -0x2AD4
    ctx->r24 = ADD32(ctx->r24, -0X2AD4);
    // 0x8004ED64: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
    // 0x8004ED68: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8004ED6C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8004ED70: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004ED74: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8004ED78: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8004ED7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8004ED80: jal         0x8005F310
    // 0x8004ED84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    update_rocket(rdram, ctx);
        goto after_47;
    // 0x8004ED84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_47:
L_8004ED88:
    // 0x8004ED88: lb          $t2, 0x175($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X175);
L_8004ED8C:
    // 0x8004ED8C: nop

    // 0x8004ED90: bne         $t2, $zero, L_8004EDB8
    if (ctx->r10 != 0) {
        // 0x8004ED94: lw          $t1, 0x7C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X7C);
            goto L_8004EDB8;
    }
    // 0x8004ED94: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8004ED98: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x8004ED9C: nop

    // 0x8004EDA0: beq         $a0, $zero, L_8004EDB8
    if (ctx->r4 == 0) {
        // 0x8004EDA4: lw          $t1, 0x7C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X7C);
            goto L_8004EDB8;
    }
    // 0x8004EDA4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EDA8: jal         0x8000488C
    // 0x8004EDAC: nop

    sndp_stop(rdram, ctx);
        goto after_48;
    // 0x8004EDAC: nop

    after_48:
    // 0x8004EDB0: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8004EDB4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
L_8004EDB8:
    // 0x8004EDB8: nop

    // 0x8004EDBC: lb          $v0, 0x4A($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X4A);
    // 0x8004EDC0: nop

    // 0x8004EDC4: beq         $v0, $zero, L_8004EE0C
    if (ctx->r2 == 0) {
        // 0x8004EDC8: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_8004EE0C;
    }
    // 0x8004EDC8: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8004EDCC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004EDD0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004EDD4: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004EDD8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004EDDC: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x8004EDE0: bc1f        L_8004EDF4
    if (!c1cs) {
        // 0x8004EDE4: nop
    
            goto L_8004EDF4;
    }
    // 0x8004EDE4: nop

    // 0x8004EDE8: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8004EDEC: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004EDF0: nop

L_8004EDF4:
    // 0x8004EDF4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8004EDF8: nop

    // 0x8004EDFC: bc1f        L_8004EE0C
    if (!c1cs) {
        // 0x8004EE00: lw          $t3, 0xA4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XA4);
            goto L_8004EE0C;
    }
    // 0x8004EE00: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8004EE04: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
    // 0x8004EE08: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
L_8004EE0C:
    // 0x8004EE0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EE10: bne         $t3, $at, L_8004EE24
    if (ctx->r11 != ctx->r1) {
        // 0x8004EE14: nop
    
            goto L_8004EE24;
    }
    // 0x8004EE14: nop

    // 0x8004EE18: jal         0x8000E148
    // 0x8004EE1C: nop

    racetype_demo(rdram, ctx);
        goto after_49;
    // 0x8004EE1C: nop

    after_49:
    // 0x8004EE20: beq         $v0, $zero, L_8004EE40
    if (ctx->r2 == 0) {
        // 0x8004EE24: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8004EE40;
    }
L_8004EE24:
    // 0x8004EE24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004EE28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004EE2C: lw          $a2, -0x2AD8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2AD8);
    // 0x8004EE30: lw          $a1, -0x2AD4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2AD4);
    // 0x8004EE34: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8004EE38: jal         0x800050D0
    // 0x8004EE3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    racer_sound_update(rdram, ctx);
        goto after_50;
    // 0x8004EE3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
L_8004EE40:
    // 0x8004EE40: lwc1        $f6, 0xA8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004EE44: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004EE48: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8004EE4C: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004EE50: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x8004EE54: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8004EE58: addiu       $t5, $s0, 0xA8
    ctx->r13 = ADD32(ctx->r16, 0XA8);
    // 0x8004EE5C: addiu       $t4, $s0, 0x1C8
    ctx->r12 = ADD32(ctx->r16, 0X1C8);
    // 0x8004EE60: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8004EE64: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004EE68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004EE6C: jal         0x800185E4
    // 0x8004EE70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_51;
    // 0x8004EE70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x8004EE74: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x8004EE78: bne         $v0, $at, L_8004EE94
    if (ctx->r2 != ctx->r1) {
        // 0x8004EE7C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8004EE94;
    }
    // 0x8004EE7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004EE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004EE84: jal         0x8005C270
    // 0x8004EE88: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    racer_update_progress(rdram, ctx);
        goto after_52;
    // 0x8004EE88: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    after_52:
    // 0x8004EE8C: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004EE90: nop

L_8004EE94:
    // 0x8004EE94: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004EE98: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8004EE9C: jal         0x8001BA1C
    // 0x8004EEA0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    find_next_checkpoint_node(rdram, ctx);
        goto after_53;
    // 0x8004EEA0: sw          $a2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r6;
    after_53:
    // 0x8004EEA4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004EEA8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8004EEAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EEB0: bne         $t6, $at, L_8004EEE8
    if (ctx->r14 != ctx->r1) {
        // 0x8004EEB4: nop
    
            goto L_8004EEE8;
    }
    // 0x8004EEB4: nop

    // 0x8004EEB8: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EEBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004EEC0: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x8004EEC4: lb          $t8, 0x36($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X36);
    // 0x8004EEC8: nop

    // 0x8004EECC: bne         $t8, $at, L_8004EEE8
    if (ctx->r24 != ctx->r1) {
        // 0x8004EED0: nop
    
            goto L_8004EEE8;
    }
    // 0x8004EED0: nop

    // 0x8004EED4: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004EED8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004EEDC: beq         $t9, $zero, L_8004EEE8
    if (ctx->r25 == 0) {
        // 0x8004EEE0: nop
    
            goto L_8004EEE8;
    }
    // 0x8004EEE0: nop

    // 0x8004EEE4: sb          $t2, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r10;
L_8004EEE8:
    // 0x8004EEE8: lb          $t1, 0x1CA($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EEEC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004EEF0: addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // 0x8004EEF4: lb          $t5, 0x36($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X36);
    // 0x8004EEF8: nop

    // 0x8004EEFC: bne         $t5, $at, L_8004EF1C
    if (ctx->r13 != ctx->r1) {
        // 0x8004EF00: nop
    
            goto L_8004EF1C;
    }
    // 0x8004EF00: nop

    // 0x8004EF04: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EF08: nop

    // 0x8004EF0C: lb          $t6, 0x4B($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X4B);
    // 0x8004EF10: nop

    // 0x8004EF14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004EF18: sb          $t7, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r15;
L_8004EF1C:
    // 0x8004EF1C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8004EF20: bne         $a2, $zero, L_8004F180
    if (ctx->r6 != 0) {
        // 0x8004EF24: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8004F180;
    }
    // 0x8004EF24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EF28: bne         $v1, $at, L_8004EF50
    if (ctx->r3 != ctx->r1) {
        // 0x8004EF2C: nop
    
            goto L_8004EF50;
    }
    // 0x8004EF2C: nop

    // 0x8004EF30: lb          $t0, 0x1CA($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1CA);
    // 0x8004EF34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004EF38: addu        $t8, $v0, $t0
    ctx->r24 = ADD32(ctx->r2, ctx->r8);
    // 0x8004EF3C: lb          $t9, 0x36($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X36);
    // 0x8004EF40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004EF44: bne         $t9, $at, L_8004EF50
    if (ctx->r25 != ctx->r1) {
        // 0x8004EF48: nop
    
            goto L_8004EF50;
    }
    // 0x8004EF48: nop

    // 0x8004EF4C: sb          $t2, 0x1C8($s0)
    MEM_B(0X1C8, ctx->r16) = ctx->r10;
L_8004EF50:
    // 0x8004EF50: jal         0x8001BA64
    // 0x8004EF54: nop

    get_checkpoint_count(rdram, ctx);
        goto after_54;
    // 0x8004EF54: nop

    after_54:
    // 0x8004EF58: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8004EF5C: lb          $t1, 0x192($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X192);
    // 0x8004EF60: nop

    // 0x8004EF64: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8004EF68: sb          $t3, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r11;
    // 0x8004EF6C: lb          $t5, 0x192($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X192);
    // 0x8004EF70: nop

    // 0x8004EF74: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004EF78: bne         $at, $zero, L_8004F008
    if (ctx->r1 != 0) {
        // 0x8004EF7C: nop
    
            goto L_8004F008;
    }
    // 0x8004EF7C: nop

    // 0x8004EF80: lh          $t4, 0x190($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X190);
    // 0x8004EF84: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x8004EF88: blez        $t4, L_8004EFA8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004EF8C: nop
    
            goto L_8004EFA8;
    }
    // 0x8004EF8C: nop

    // 0x8004EF90: lb          $v0, 0x193($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X193);
    // 0x8004EF94: nop

    // 0x8004EF98: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8004EF9C: beq         $at, $zero, L_8004EFA8
    if (ctx->r1 == 0) {
        // 0x8004EFA0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8004EFA8;
    }
    // 0x8004EFA0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8004EFA4: sb          $t6, 0x193($s0)
    MEM_B(0X193, ctx->r16) = ctx->r14;
L_8004EFA8:
    // 0x8004EFA8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004EFAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004EFB0: beq         $t7, $at, L_8004F008
    if (ctx->r15 == ctx->r1) {
        // 0x8004EFB4: nop
    
            goto L_8004F008;
    }
    // 0x8004EFB4: nop

    // 0x8004EFB8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8004EFBC: lb          $t9, 0x193($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X193);
    // 0x8004EFC0: lb          $t8, 0x4B($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X4B);
    // 0x8004EFC4: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8004EFC8: bne         $t8, $t2, L_8004F008
    if (ctx->r24 != ctx->r10) {
        // 0x8004EFCC: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8004F008;
    }
    // 0x8004EFCC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004EFD0: lbu         $t1, -0x2A80($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2A80);
    // 0x8004EFD4: nop

    // 0x8004EFD8: bne         $t1, $zero, L_8004F008
    if (ctx->r9 != 0) {
        // 0x8004EFDC: nop
    
            goto L_8004F008;
    }
    // 0x8004EFDC: nop

    // 0x8004EFE0: jal         0x8006BD98
    // 0x8004EFE4: nop

    level_type(rdram, ctx);
        goto after_55;
    // 0x8004EFE4: nop

    after_55:
    // 0x8004EFE8: bne         $v0, $zero, L_8004F008
    if (ctx->r2 != 0) {
        // 0x8004EFEC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004F008;
    }
    // 0x8004EFEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004EFF0: lwc1        $f12, 0x65E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X65E8);
    // 0x8004EFF4: jal         0x800014BC
    // 0x8004EFF8: nop

    music_tempo_set_relative(rdram, ctx);
        goto after_56;
    // 0x8004EFF8: nop

    after_56:
    // 0x8004EFFC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004F000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F004: sb          $t3, -0x2A80($at)
    MEM_B(-0X2A80, ctx->r1) = ctx->r11;
L_8004F008:
    // 0x8004F008: jal         0x8002341C
    // 0x8004F00C: nop

    is_taj_challenge(rdram, ctx);
        goto after_57;
    // 0x8004F00C: nop

    after_57:
    // 0x8004F010: beq         $v0, $zero, L_8004F144
    if (ctx->r2 == 0) {
        // 0x8004F014: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004F144;
    }
    // 0x8004F014: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004F018: lw          $t5, -0x2AA4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AA4);
    // 0x8004F01C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F020: beq         $t5, $at, L_8004F148
    if (ctx->r13 == ctx->r1) {
        // 0x8004F024: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F148;
    }
    // 0x8004F024: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F028: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8004F02C: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8004F030: jal         0x8001BA1C
    // 0x8004F034: nop

    find_next_checkpoint_node(rdram, ctx);
        goto after_58;
    // 0x8004F034: nop

    after_58:
    // 0x8004F038: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F03C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8004F040: bne         $t4, $zero, L_8004F08C
    if (ctx->r12 != 0) {
        // 0x8004F044: addiu       $t6, $zero, 0x86
        ctx->r14 = ADD32(0, 0X86);
            goto L_8004F08C;
    }
    // 0x8004F044: addiu       $t6, $zero, 0x86
    ctx->r14 = ADD32(0, 0X86);
    // 0x8004F048: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8004F04C: sh          $zero, 0x66($sp)
    MEM_H(0X66, ctx->r29) = 0;
    // 0x8004F050: sh          $zero, 0x68($sp)
    MEM_H(0X68, ctx->r29) = 0;
    // 0x8004F054: sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // 0x8004F058: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
    // 0x8004F05C: sb          $t7, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r15;
    // 0x8004F060: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8004F064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004F068: jal         0x8000EA54
    // 0x8004F06C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    spawn_object(rdram, ctx);
        goto after_59;
    // 0x8004F06C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_59:
    // 0x8004F070: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x8004F074: beq         $v0, $zero, L_8004F08C
    if (ctx->r2 == 0) {
        // 0x8004F078: sw          $v0, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r2;
            goto L_8004F08C;
    }
    // 0x8004F078: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x8004F07C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004F080: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F084: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8004F088: sb          $t9, 0x39($t8)
    MEM_B(0X39, ctx->r24) = ctx->r25;
L_8004F08C:
    // 0x8004F08C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F090: nop

    // 0x8004F094: beq         $v0, $zero, L_8004F148
    if (ctx->r2 == 0) {
        // 0x8004F098: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F148;
    }
    // 0x8004F098: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F09C: lw          $t2, 0x28($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X28);
    // 0x8004F0A0: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8004F0A4: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8004F0A8: nop

    // 0x8004F0AC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8004F0B0: lw          $t1, 0x28($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X28);
    // 0x8004F0B4: lw          $t3, 0x15C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0B8: lwc1        $f10, 0x10($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8004F0BC: nop

    // 0x8004F0C0: swc1        $f10, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f10.u32l;
    // 0x8004F0C4: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004F0C8: nop

    // 0x8004F0CC: bne         $t5, $zero, L_8004F0F4
    if (ctx->r13 != 0) {
        // 0x8004F0D0: nop
    
            goto L_8004F0F4;
    }
    // 0x8004F0D0: nop

    // 0x8004F0D4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004F0DC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004F0E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F0E4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8004F0E8: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x8004F0EC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x8004F0F0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_8004F0F4:
    // 0x8004F0F4: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    // 0x8004F0F8: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F0FC: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8004F100: nop

    // 0x8004F104: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x8004F108: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x8004F10C: lw          $t9, 0x15C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F110: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x8004F114: nop

    // 0x8004F118: sh          $t0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r8;
    // 0x8004F11C: lw          $t8, 0x28($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X28);
    // 0x8004F120: lw          $t1, 0x15C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F124: lh          $t2, 0x2($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X2);
    // 0x8004F128: nop

    // 0x8004F12C: sh          $t2, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r10;
    // 0x8004F130: lw          $t3, 0x28($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X28);
    // 0x8004F134: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F138: lh          $t5, 0x2E($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X2E);
    // 0x8004F13C: nop

    // 0x8004F140: sh          $t5, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r13;
L_8004F144:
    // 0x8004F144: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
L_8004F148:
    // 0x8004F148: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8004F14C: lb          $t7, 0x4B($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X4B);
    // 0x8004F150: lh          $v0, 0x190($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X190);
    // 0x8004F154: addiu       $t0, $t7, 0x3
    ctx->r8 = ADD32(ctx->r15, 0X3);
    // 0x8004F158: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F15C: addiu       $t1, $zero, 0x2710
    ctx->r9 = ADD32(0, 0X2710);
    // 0x8004F160: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8004F164: mflo        $t8
    ctx->r24 = lo;
    // 0x8004F168: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8004F16C: beq         $at, $zero, L_8004F178
    if (ctx->r1 == 0) {
        // 0x8004F170: nop
    
            goto L_8004F178;
    }
    // 0x8004F170: nop

    // 0x8004F174: sh          $t2, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r10;
L_8004F178:
    // 0x8004F178: b           L_8004F1B0
    // 0x8004F17C: sh          $t1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r9;
        goto L_8004F1B0;
    // 0x8004F17C: sh          $t1, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r9;
L_8004F180:
    // 0x8004F180: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F184: bne         $v1, $at, L_8004F1AC
    if (ctx->r3 != ctx->r1) {
        // 0x8004F188: nop
    
            goto L_8004F1AC;
    }
    // 0x8004F188: nop

    // 0x8004F18C: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004F190: lwc1        $f8, 0xA8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8004F194: nop

    // 0x8004F198: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004F19C: nop

    // 0x8004F1A0: bc1f        L_8004F1AC
    if (!c1cs) {
        // 0x8004F1A4: nop
    
            goto L_8004F1AC;
    }
    // 0x8004F1A4: nop

    // 0x8004F1A8: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
L_8004F1AC:
    // 0x8004F1AC: sh          $a2, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r6;
L_8004F1B0:
    // 0x8004F1B0: jal         0x8002341C
    // 0x8004F1B4: nop

    is_taj_challenge(rdram, ctx);
        goto after_60;
    // 0x8004F1B4: nop

    after_60:
    // 0x8004F1B8: beq         $v0, $zero, L_8004F208
    if (ctx->r2 == 0) {
        // 0x8004F1BC: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F208;
    }
    // 0x8004F1BC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F1C0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8004F1C4: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F1C8: beq         $v0, $zero, L_8004F1E0
    if (ctx->r2 == 0) {
        // 0x8004F1CC: nop
    
            goto L_8004F1E0;
    }
    // 0x8004F1CC: nop

    // 0x8004F1D0: lh          $t3, 0x18($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X18);
    // 0x8004F1D4: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8004F1D8: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8004F1DC: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
L_8004F1E0:
    // 0x8004F1E0: lh          $v0, 0x1BA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1BA);
    // 0x8004F1E4: nop

    // 0x8004F1E8: slti        $at, $v0, 0x191
    ctx->r1 = SIGNED(ctx->r2) < 0X191 ? 1 : 0;
    // 0x8004F1EC: beq         $at, $zero, L_8004F1FC
    if (ctx->r1 == 0) {
        // 0x8004F1F0: slti        $at, $v0, -0x190
        ctx->r1 = SIGNED(ctx->r2) < -0X190 ? 1 : 0;
            goto L_8004F1FC;
    }
    // 0x8004F1F0: slti        $at, $v0, -0x190
    ctx->r1 = SIGNED(ctx->r2) < -0X190 ? 1 : 0;
    // 0x8004F1F4: beq         $at, $zero, L_8004F208
    if (ctx->r1 == 0) {
        // 0x8004F1F8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F208;
    }
    // 0x8004F1F8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_8004F1FC:
    // 0x8004F1FC: jal         0x80022E18
    // 0x8004F200: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mode_end_taj_race(rdram, ctx);
        goto after_61;
    // 0x8004F200: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_61:
    // 0x8004F204: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_8004F208:
    // 0x8004F208: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x8004F20C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8004F210: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8004F214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F218: jal         0x80018CE0
    // 0x8004F21C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80018CE0(rdram, ctx);
        goto after_62;
    // 0x8004F21C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_62:
    // 0x8004F220: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F228: jal         0x80059208
    // 0x8004F22C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80059208(rdram, ctx);
        goto after_63;
    // 0x8004F22C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_63:
    // 0x8004F230: lb          $t0, 0x1D8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004F234: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F238: bne         $t0, $at, L_8004F258
    if (ctx->r8 != ctx->r1) {
        // 0x8004F23C: nop
    
            goto L_8004F258;
    }
    // 0x8004F23C: nop

    // 0x8004F240: lb          $v0, 0x1D9($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D9);
    // 0x8004F244: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F248: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8004F24C: beq         $at, $zero, L_8004F258
    if (ctx->r1 == 0) {
        // 0x8004F250: addu        $t8, $v0, $t9
        ctx->r24 = ADD32(ctx->r2, ctx->r25);
            goto L_8004F258;
    }
    // 0x8004F250: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x8004F254: sb          $t8, 0x1D9($s0)
    MEM_B(0X1D9, ctx->r16) = ctx->r24;
L_8004F258:
    // 0x8004F258: lb          $a2, 0x188($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X188);
    // 0x8004F25C: nop

    // 0x8004F260: blez        $a2, L_8004F270
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004F264: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004F270;
    }
    // 0x8004F264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F268: jal         0x800576E0
    // 0x8004F26C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    drop_bananas(rdram, ctx);
        goto after_64;
    // 0x8004F26C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_64:
L_8004F270:
    // 0x8004F270: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004F274: lw          $t2, -0x2AA4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AA4);
    // 0x8004F278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004F27C: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x8004F280: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x8004F284: jal         0x80057A40
    // 0x8004F288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    update_player_camera(rdram, ctx);
        goto after_65;
    // 0x8004F288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_65:
    // 0x8004F28C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F290: sb          $zero, -0x2A7D($at)
    MEM_B(-0X2A7D, ctx->r1) = 0;
    // 0x8004F294: lw          $t1, 0x148($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X148);
    // 0x8004F298: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004F29C: beq         $t1, $zero, L_8004F2B4
    if (ctx->r9 == 0) {
        // 0x8004F2A0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8004F2B4;
    }
    // 0x8004F2A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004F2A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004F2A8: sw          $zero, 0x148($s0)
    MEM_W(0X148, ctx->r16) = 0;
    // 0x8004F2AC: swc1        $f14, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f14.u32l;
    // 0x8004F2B0: swc1        $f14, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f14.u32l;
L_8004F2B4:
    // 0x8004F2B4: lwc1        $f12, 0x90($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X90);
    // 0x8004F2B8: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F2BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004F2C0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8004F2C4: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8004F2C8: bc1f        L_8004F2DC
    if (!c1cs) {
        // 0x8004F2CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004F2DC;
    }
    // 0x8004F2CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F2D0: lwc1        $f2, 0x65EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65EC);
    // 0x8004F2D4: b           L_8004F2EC
    // 0x8004F2D8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
        goto L_8004F2EC;
    // 0x8004F2D8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8004F2DC:
    // 0x8004F2DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F2E0: lwc1        $f2, 0x65F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65F0);
    // 0x8004F2E4: nop

    // 0x8004F2E8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8004F2EC:
    // 0x8004F2EC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004F2F0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F2F4: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8004F2F8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8004F2FC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004F300: lwc1        $f5, 0x50($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004F304: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8004F308: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8004F30C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8004F310: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004F314: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x8004F318: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8004F31C: bc1f        L_8004F33C
    if (!c1cs) {
        // 0x8004F320: swc1        $f4, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
            goto L_8004F33C;
    }
    // 0x8004F320: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    // 0x8004F324: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F328: nop

    // 0x8004F32C: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x8004F330: nop

    // 0x8004F334: bc1t        L_8004F364
    if (c1cs) {
        // 0x8004F338: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004F364;
    }
    // 0x8004F338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004F33C:
    // 0x8004F33C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8004F340: nop

    // 0x8004F344: bc1f        L_8004F370
    if (!c1cs) {
        // 0x8004F348: nop
    
            goto L_8004F370;
    }
    // 0x8004F348: nop

    // 0x8004F34C: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004F350: nop

    // 0x8004F354: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8004F358: nop

    // 0x8004F35C: bc1f        L_8004F370
    if (!c1cs) {
        // 0x8004F360: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004F370;
    }
    // 0x8004F360: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004F364:
    // 0x8004F364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F368: swc1        $f12, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f12.u32l;
    // 0x8004F36C: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
L_8004F370:
    // 0x8004F370: lh          $v1, 0x16A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X16A);
    // 0x8004F374: lh          $t5, 0x16C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X16C);
    // 0x8004F378: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F37C: subu        $t3, $t5, $v1
    ctx->r11 = SUB32(ctx->r13, ctx->r3);
    // 0x8004F380: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F384: mflo        $a2
    ctx->r6 = lo;
    // 0x8004F388: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8004F38C: slti        $at, $t6, 0x801
    ctx->r1 = SIGNED(ctx->r14) < 0X801 ? 1 : 0;
    // 0x8004F390: bne         $at, $zero, L_8004F39C
    if (ctx->r1 != 0) {
        // 0x8004F394: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8004F39C;
    }
    // 0x8004F394: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8004F398: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8004F39C:
    // 0x8004F39C: slti        $at, $a2, -0x800
    ctx->r1 = SIGNED(ctx->r6) < -0X800 ? 1 : 0;
    // 0x8004F3A0: beq         $at, $zero, L_8004F3AC
    if (ctx->r1 == 0) {
        // 0x8004F3A4: nop
    
            goto L_8004F3AC;
    }
    // 0x8004F3A4: nop

    // 0x8004F3A8: addiu       $a2, $zero, -0x800
    ctx->r6 = ADD32(0, -0X800);
L_8004F3AC:
    // 0x8004F3AC: lh          $v0, -0x34AC($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X34AC);
    // 0x8004F3B0: nop

    // 0x8004F3B4: beq         $v0, $zero, L_8004F3C4
    if (ctx->r2 == 0) {
        // 0x8004F3B8: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_8004F3C4;
    }
    // 0x8004F3B8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x8004F3BC: b           L_8004F3CC
    // 0x8004F3C0: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
        goto L_8004F3CC;
    // 0x8004F3C0: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
L_8004F3C4:
    // 0x8004F3C4: addu        $t0, $v1, $a2
    ctx->r8 = ADD32(ctx->r3, ctx->r6);
    // 0x8004F3C8: sh          $t0, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r8;
L_8004F3CC:
    // 0x8004F3CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004F3D0: lw          $v0, -0x2AD4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD4);
    // 0x8004F3D4: nop

    // 0x8004F3D8: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8004F3DC: beq         $t9, $zero, L_8004F400
    if (ctx->r25 == 0) {
        // 0x8004F3E0: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8004F400;
    }
    // 0x8004F3E0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8004F3E4: lb          $t8, 0x1EB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1EB);
    // 0x8004F3E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004F3EC: beq         $t8, $zero, L_8004F400
    if (ctx->r24 == 0) {
        // 0x8004F3F0: nop
    
            goto L_8004F400;
    }
    // 0x8004F3F0: nop

    // 0x8004F3F4: sb          $t2, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = ctx->r10;
    // 0x8004F3F8: b           L_8004F40C
    // 0x8004F3FC: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
        goto L_8004F40C;
    // 0x8004F3FC: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
L_8004F400:
    // 0x8004F400: beq         $v0, $zero, L_8004F40C
    if (ctx->r2 == 0) {
        // 0x8004F404: addiu       $t1, $zero, 0x16
        ctx->r9 = ADD32(0, 0X16);
            goto L_8004F40C;
    }
    // 0x8004F404: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x8004F408: sb          $t1, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r9;
L_8004F40C:
    // 0x8004F40C: lb          $v0, 0x1EB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1EB);
    // 0x8004F410: nop

    // 0x8004F414: blez        $v0, L_8004F430
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F418: nop
    
            goto L_8004F430;
    }
    // 0x8004F418: nop

    // 0x8004F41C: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F420: nop

    // 0x8004F424: subu        $t3, $v0, $t5
    ctx->r11 = SUB32(ctx->r2, ctx->r13);
    // 0x8004F428: b           L_8004F434
    // 0x8004F42C: sb          $t3, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r11;
        goto L_8004F434;
    // 0x8004F42C: sb          $t3, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = ctx->r11;
L_8004F430:
    // 0x8004F430: sb          $zero, 0x1EB($s0)
    MEM_B(0X1EB, ctx->r16) = 0;
L_8004F434:
    // 0x8004F434: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F438: nop

    // 0x8004F43C: blez        $v0, L_8004F4F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F440: slti        $at, $v0, 0x3D
        ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
            goto L_8004F4F8;
    }
    // 0x8004F440: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8004F444: bne         $at, $zero, L_8004F4B4
    if (ctx->r1 != 0) {
        // 0x8004F448: nop
    
            goto L_8004F4B4;
    }
    // 0x8004F448: nop

    // 0x8004F44C: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8004F450: nop

    // 0x8004F454: beq         $a0, $zero, L_8004F47C
    if (ctx->r4 == 0) {
        // 0x8004F458: nop
    
            goto L_8004F47C;
    }
    // 0x8004F458: nop

    // 0x8004F45C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F460: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F464: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F468: jal         0x800096D8
    // 0x8004F46C: nop

    audspat_point_set_position(rdram, ctx);
        goto after_66;
    // 0x8004F46C: nop

    after_66:
    // 0x8004F470: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F474: b           L_8004F4D8
    // 0x8004F478: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
        goto L_8004F4D8;
    // 0x8004F478: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F47C:
    // 0x8004F47C: lw          $t4, 0x118($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X118);
    // 0x8004F480: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8004F484: beq         $t4, $zero, L_8004F4D4
    if (ctx->r12 == 0) {
        // 0x8004F488: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8004F4D4;
    }
    // 0x8004F488: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004F48C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F490: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F494: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F498: addiu       $t7, $s0, 0x17C
    ctx->r15 = ADD32(ctx->r16, 0X17C);
    // 0x8004F49C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004F4A0: jal         0x80009558
    // 0x8004F4A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_67;
    // 0x8004F4A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_67:
    // 0x8004F4A8: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F4AC: b           L_8004F4D8
    // 0x8004F4B0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
        goto L_8004F4D8;
    // 0x8004F4B0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F4B4:
    // 0x8004F4B4: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8004F4B8: nop

    // 0x8004F4BC: beq         $a0, $zero, L_8004F4D8
    if (ctx->r4 == 0) {
        // 0x8004F4C0: lw          $t0, 0xB4($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XB4);
            goto L_8004F4D8;
    }
    // 0x8004F4C0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F4C4: jal         0x800096F8
    // 0x8004F4C8: nop

    audspat_point_stop(rdram, ctx);
        goto after_68;
    // 0x8004F4C8: nop

    after_68:
    // 0x8004F4CC: lh          $v0, 0x18E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F4D0: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8004F4D4:
    // 0x8004F4D4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
L_8004F4D8:
    // 0x8004F4D8: nop

    // 0x8004F4DC: subu        $t9, $v0, $t0
    ctx->r25 = SUB32(ctx->r2, ctx->r8);
    // 0x8004F4E0: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
    // 0x8004F4E4: lh          $t8, 0x18E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18E);
    // 0x8004F4E8: nop

    // 0x8004F4EC: bgtz        $t8, L_8004F4F8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8004F4F0: nop
    
            goto L_8004F4F8;
    }
    // 0x8004F4F0: nop

    // 0x8004F4F4: sb          $zero, 0x189($s0)
    MEM_B(0X189, ctx->r16) = 0;
L_8004F4F8:
    // 0x8004F4F8: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x8004F4FC: nop

    // 0x8004F500: beq         $a0, $zero, L_8004F51C
    if (ctx->r4 == 0) {
        // 0x8004F504: nop
    
            goto L_8004F51C;
    }
    // 0x8004F504: nop

    // 0x8004F508: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F50C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F510: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F514: jal         0x800096D8
    // 0x8004F518: nop

    audspat_point_set_position(rdram, ctx);
        goto after_69;
    // 0x8004F518: nop

    after_69:
L_8004F51C:
    // 0x8004F51C: jal         0x8000E4D8
    // 0x8004F520: nop

    is_in_time_trial(rdram, ctx);
        goto after_70;
    // 0x8004F520: nop

    after_70:
    // 0x8004F524: beq         $v0, $zero, L_8004F554
    if (ctx->r2 == 0) {
        // 0x8004F528: nop
    
            goto L_8004F554;
    }
    // 0x8004F528: nop

    // 0x8004F52C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8004F530: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004F534: bne         $t2, $zero, L_8004F554
    if (ctx->r10 != 0) {
        // 0x8004F538: nop
    
            goto L_8004F554;
    }
    // 0x8004F538: nop

    // 0x8004F53C: lw          $t1, -0x2AC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC0);
    // 0x8004F540: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F544: bne         $t1, $zero, L_8004F554
    if (ctx->r9 != 0) {
        // 0x8004F548: nop
    
            goto L_8004F554;
    }
    // 0x8004F548: nop

    // 0x8004F54C: jal         0x80059BF0
    // 0x8004F550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    timetrial_ghost_write(rdram, ctx);
        goto after_71;
    // 0x8004F550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_71:
L_8004F554:
    // 0x8004F554: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8004F558: nop

    // 0x8004F55C: beq         $a0, $zero, L_8004F578
    if (ctx->r4 == 0) {
        // 0x8004F560: nop
    
            goto L_8004F578;
    }
    // 0x8004F560: nop

    // 0x8004F564: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F568: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F56C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F570: jal         0x800096D8
    // 0x8004F574: nop

    audspat_point_set_position(rdram, ctx);
        goto after_72;
    // 0x8004F574: nop

    after_72:
L_8004F578:
    // 0x8004F578: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004F57C: sb          $zero, -0x2A7C($at)
    MEM_B(-0X2A7C, ctx->r1) = 0;
    // 0x8004F580: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F584: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004F588: beq         $v0, $zero, L_8004F680
    if (ctx->r2 == 0) {
        // 0x8004F58C: nop
    
            goto L_8004F680;
    }
    // 0x8004F58C: nop

    // 0x8004F590: lw          $t5, -0x2AC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC0);
    // 0x8004F594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004F598: bne         $t5, $zero, L_8004F684
    if (ctx->r13 != 0) {
        // 0x8004F59C: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_8004F684;
    }
    // 0x8004F59C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004F5A0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004F5A4: jal         0x8001E29C
    // 0x8004F5A8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    get_misc_asset(rdram, ctx);
        goto after_73;
    // 0x8004F5A8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    after_73:
    // 0x8004F5AC: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x8004F5B0: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F5B4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8004F5B8: lb          $t6, 0x0($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X0);
    // 0x8004F5BC: lw          $t7, 0x150($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X150);
    // 0x8004F5C0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8004F5C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F5C8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004F5CC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8004F5D0: swc1        $f4, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f4.u32l;
    // 0x8004F5D4: lw          $t0, 0x150($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X150);
    // 0x8004F5D8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004F5DC: nop

    // 0x8004F5E0: swc1        $f10, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f10.u32l;
    // 0x8004F5E4: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004F5E8: lwc1        $f6, 0x65F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65F4);
    // 0x8004F5EC: lw          $t9, 0x150($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X150);
    // 0x8004F5F0: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004F5F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004F5F8: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x8004F5FC: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8004F600: lwc1        $f6, 0x65FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65FC);
    // 0x8004F604: lwc1        $f7, 0x65F8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X65F8);
    // 0x8004F608: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004F60C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8004F610: nop

    // 0x8004F614: bc1t        L_8004F630
    if (c1cs) {
        // 0x8004F618: nop
    
            goto L_8004F630;
    }
    // 0x8004F618: nop

    // 0x8004F61C: jal         0x8009C30C
    // 0x8004F620: nop

    get_filtered_cheats(rdram, ctx);
        goto after_74;
    // 0x8004F620: nop

    after_74:
    // 0x8004F624: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8004F628: beq         $t8, $zero, L_8004F648
    if (ctx->r24 == 0) {
        // 0x8004F62C: nop
    
            goto L_8004F648;
    }
    // 0x8004F62C: nop

L_8004F630:
    // 0x8004F630: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F634: nop

    // 0x8004F638: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x8004F63C: nop

    // 0x8004F640: ori         $t1, $t2, 0x4000
    ctx->r9 = ctx->r10 | 0X4000;
    // 0x8004F644: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
L_8004F648:
    // 0x8004F648: lw          $v0, 0x150($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X150);
    // 0x8004F64C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004F650: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004F654: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004F658: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004F65C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004F660: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8004F664: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004F668: bc1f        L_8004F67C
    if (!c1cs) {
        // 0x8004F66C: nop
    
            goto L_8004F67C;
    }
    // 0x8004F66C: nop

    // 0x8004F670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F674: nop

    // 0x8004F678: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_8004F67C:
    // 0x8004F67C: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
L_8004F680:
    // 0x8004F680: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
L_8004F684:
    // 0x8004F684: sb          $t5, 0x1FE($s0)
    MEM_B(0X1FE, ctx->r16) = ctx->r13;
    // 0x8004F688: jal         0x8004F77C
    // 0x8004F68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_racer_tail_lights(rdram, ctx);
        goto after_75;
    // 0x8004F68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x8004F690: lhu         $t3, 0x20E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F694: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8004F698: beq         $t3, $zero, L_8004F714
    if (ctx->r11 == 0) {
        // 0x8004F69C: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_8004F714;
    }
    // 0x8004F69C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x8004F6A0: lbu         $v0, 0x210($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X210);
    // 0x8004F6A4: nop

    // 0x8004F6A8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F6AC: beq         $at, $zero, L_8004F6BC
    if (ctx->r1 == 0) {
        // 0x8004F6B0: subu        $t6, $v0, $t4
        ctx->r14 = SUB32(ctx->r2, ctx->r12);
            goto L_8004F6BC;
    }
    // 0x8004F6B0: subu        $t6, $v0, $t4
    ctx->r14 = SUB32(ctx->r2, ctx->r12);
    // 0x8004F6B4: b           L_8004F710
    // 0x8004F6B8: sb          $t6, 0x210($s0)
    MEM_B(0X210, ctx->r16) = ctx->r14;
        goto L_8004F710;
    // 0x8004F6B8: sb          $t6, 0x210($s0)
    MEM_B(0X210, ctx->r16) = ctx->r14;
L_8004F6BC:
    // 0x8004F6BC: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004F6C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F6C4: bne         $t7, $at, L_8004F6F4
    if (ctx->r15 != ctx->r1) {
        // 0x8004F6C8: sb          $zero, 0x210($s0)
        MEM_B(0X210, ctx->r16) = 0;
            goto L_8004F6F4;
    }
    // 0x8004F6C8: sb          $zero, 0x210($s0)
    MEM_B(0X210, ctx->r16) = 0;
    // 0x8004F6CC: lhu         $a0, 0x20E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F6D0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F6D4: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F6D8: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F6DC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8004F6E0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004F6E4: jal         0x80009558
    // 0x8004F6E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_76;
    // 0x8004F6E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_76:
    // 0x8004F6EC: b           L_8004F710
    // 0x8004F6F0: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
        goto L_8004F710;
    // 0x8004F6F0: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
L_8004F6F4:
    // 0x8004F6F4: lhu         $a0, 0x20E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X20E);
    // 0x8004F6F8: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004F6FC: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004F700: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004F704: jal         0x80001EA8
    // 0x8004F708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_77;
    // 0x8004F708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_77:
    // 0x8004F70C: sh          $zero, 0x20E($s0)
    MEM_H(0X20E, ctx->r16) = 0;
L_8004F710:
    // 0x8004F710: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_8004F714:
    // 0x8004F714: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8004F718: lb          $v0, 0x4C($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4C);
    // 0x8004F71C: nop

    // 0x8004F720: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8004F724: beq         $t8, $zero, L_8004F748
    if (ctx->r24 == 0) {
        // 0x8004F728: nop
    
            goto L_8004F748;
    }
    // 0x8004F728: nop

    // 0x8004F72C: beq         $v0, $at, L_8004F748
    if (ctx->r2 == ctx->r1) {
        // 0x8004F730: nop
    
            goto L_8004F748;
    }
    // 0x8004F730: nop

    // 0x8004F734: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004F738: jal         0x8001C418
    // 0x8004F73C: nop

    obj_elevation(rdram, ctx);
        goto after_78;
    // 0x8004F73C: nop

    after_78:
    // 0x8004F740: b           L_8004F74C
    // 0x8004F744: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
        goto L_8004F74C;
    // 0x8004F744: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
L_8004F748:
    // 0x8004F748: sb          $zero, 0x212($s0)
    MEM_B(0X212, ctx->r16) = 0;
L_8004F74C:
    // 0x8004F74C: lb          $v0, 0x193($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X193);
    // 0x8004F750: lb          $t2, 0x194($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X194);
    // 0x8004F754: nop

    // 0x8004F758: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F75C: beq         $at, $zero, L_8004F76C
    if (ctx->r1 == 0) {
        // 0x8004F760: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004F76C;
    }
    // 0x8004F760: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F764: sb          $v0, 0x194($s0)
    MEM_B(0X194, ctx->r16) = ctx->r2;
    // 0x8004F768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004F76C:
    // 0x8004F76C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004F770: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004F774: jr          $ra
    // 0x8004F778: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8004F778: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void align_text_in_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C54EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C54F0: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C54F4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C54F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C54FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800C5500: beq         $a1, $zero, L_800C55EC
    if (ctx->r5 == 0) {
        // 0x800C5504: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C55EC;
    }
    // 0x800C5504: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5508: lbu         $v1, 0x19($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X19);
    // 0x800C550C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C5510: beq         $v1, $at, L_800C55EC
    if (ctx->r3 == ctx->r1) {
        // 0x800C5514: sll         $t8, $v1, 10
        ctx->r24 = S32(ctx->r3 << 10);
            goto L_800C55EC;
    }
    // 0x800C5514: sll         $t8, $v1, 10
    ctx->r24 = S32(ctx->r3 << 10);
    // 0x800C5518: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C551C: lw          $a2, 0x10($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X10);
    // 0x800C5520: lw          $t9, -0x581C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X581C);
    // 0x800C5524: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C5528: beq         $a2, $at, L_800C55E4
    if (ctx->r6 == ctx->r1) {
        // 0x800C552C: addu        $a0, $t8, $t9
        ctx->r4 = ADD32(ctx->r24, ctx->r25);
            goto L_800C55E4;
    }
    // 0x800C552C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800C5530: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C5534: beq         $a2, $at, L_800C554C
    if (ctx->r6 == ctx->r1) {
        // 0x800C5538: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C554C;
    }
    // 0x800C5538: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C553C: beq         $a2, $at, L_800C5564
    if (ctx->r6 == ctx->r1) {
        // 0x800C5540: nop
    
            goto L_800C5564;
    }
    // 0x800C5540: nop

    // 0x800C5544: b           L_800C55C8
    // 0x800C5548: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C55C8;
    // 0x800C5548: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C554C:
    // 0x800C554C: lhu         $t0, 0x22($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5550: nop

    // 0x800C5554: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C5558: mflo        $a3
    ctx->r7 = lo;
    // 0x800C555C: b           L_800C55C8
    // 0x800C5560: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
        goto L_800C55C8;
    // 0x800C5560: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C5564:
    // 0x800C5564: lhu         $v1, 0x22($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X22);
    // 0x800C5568: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x800C556C: nop

    // 0x800C5570: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800C5574: bne         $v1, $zero, L_800C5580
    if (ctx->r3 != 0) {
        // 0x800C5578: nop
    
            goto L_800C5580;
    }
    // 0x800C5578: nop

    // 0x800C557C: break       7
    do_break(2148291964);
L_800C5580:
    // 0x800C5580: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C5584: bne         $v1, $at, L_800C5598
    if (ctx->r3 != ctx->r1) {
        // 0x800C5588: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C5598;
    }
    // 0x800C5588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C558C: bne         $t1, $at, L_800C5598
    if (ctx->r9 != ctx->r1) {
        // 0x800C5590: nop
    
            goto L_800C5598;
    }
    // 0x800C5590: nop

    // 0x800C5594: break       6
    do_break(2148291988);
L_800C5598:
    // 0x800C5598: mflo        $t2
    ctx->r10 = lo;
    // 0x800C559C: nop

    // 0x800C55A0: nop

    // 0x800C55A4: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C55A8: mflo        $t3
    ctx->r11 = lo;
    // 0x800C55AC: nop

    // 0x800C55B0: nop

    // 0x800C55B4: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C55B8: mflo        $a3
    ctx->r7 = lo;
    // 0x800C55BC: nop

    // 0x800C55C0: nop

    // 0x800C55C4: lh          $t4, 0xC($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XC);
L_800C55C8:
    // 0x800C55C8: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C55CC: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x800C55D0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C55D4: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800C55D8: sh          $t6, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r14;
    // 0x800C55DC: jr          $ra
    // 0x800C55E0: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
    return;
    // 0x800C55E0: sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
L_800C55E4:
    // 0x800C55E4: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800C55E8: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
L_800C55EC:
    // 0x800C55EC: jr          $ra
    // 0x800C55F0: nop

    return;
    // 0x800C55F0: nop

;}
RECOMP_FUNC void create_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0BAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B0BB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0BB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B0BB8: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B0BBC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B0BC0: lw          $t6, 0x2CF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CF0);
    // 0x800B0BC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B0BC8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B0BCC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B0BD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0BD4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800B0BD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0BDC: beq         $t2, $at, L_800B0BEC
    if (ctx->r10 == ctx->r1) {
        // 0x800B0BE0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800B0BEC;
    }
    // 0x800B0BE0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B0BE4: b           L_800B1120
    // 0x800B0BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1120;
    // 0x800B0BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0BEC:
    // 0x800B0BEC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800B0BF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B0BF4: lw          $t1, 0x9C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X9C);
    // 0x800B0BF8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B0BFC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B0C00: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800B0C04: jal         0x800B1CB8
    // 0x800B0C08: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B0C08: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_0:
    // 0x800B0C0C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800B0C10: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0C14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B0C18: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B0C1C: bne         $v0, $zero, L_800B0C2C
    if (ctx->r2 != 0) {
        // 0x800B0C20: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B0C2C;
    }
    // 0x800B0C20: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B0C24: b           L_800B1120
    // 0x800B0C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B1120;
    // 0x800B0C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0C2C:
    // 0x800B0C2C: lh          $t3, 0x2E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2E);
    // 0x800B0C30: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800B0C34: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x800B0C38: sh          $t3, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r11;
    // 0x800B0C3C: lbu         $t5, 0x1($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1);
    // 0x800B0C40: nop

    // 0x800B0C44: sb          $t5, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r13;
    // 0x800B0C48: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x800B0C4C: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800B0C50: sw          $a2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r6;
    // 0x800B0C54: sw          $t7, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r15;
    // 0x800B0C58: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B0C5C: lwc1        $f6, 0x50($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X50);
    // 0x800B0C60: nop

    // 0x800B0C64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B0C68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B0C6C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800B0C70: lwc1        $f16, 0x54($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800B0C74: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800B0C78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B0C7C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B0C80: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800B0C84: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x800B0C88: sb          $zero, 0x38($v0)
    MEM_B(0X38, ctx->r2) = 0;
    // 0x800B0C8C: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x800B0C90: sh          $t6, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r14;
    // 0x800B0C94: lw          $v1, 0x2D00($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2D00);
    // 0x800B0C98: nop

    // 0x800B0C9C: beq         $v1, $zero, L_800B0CAC
    if (ctx->r3 == 0) {
        // 0x800B0CA0: nop
    
            goto L_800B0CAC;
    }
    // 0x800B0CA0: nop

    // 0x800B0CA4: b           L_800B0CD0
    // 0x800B0CA8: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
        goto L_800B0CD0;
    // 0x800B0CA8: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
L_800B0CAC:
    // 0x800B0CAC: lbu         $t8, 0x14($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X14);
    // 0x800B0CB0: nop

    // 0x800B0CB4: sb          $t8, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r24;
    // 0x800B0CB8: lbu         $t9, 0x15($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X15);
    // 0x800B0CBC: nop

    // 0x800B0CC0: sb          $t9, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r25;
    // 0x800B0CC4: lbu         $t2, 0x16($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X16);
    // 0x800B0CC8: nop

    // 0x800B0CCC: sb          $t2, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r10;
L_800B0CD0:
    // 0x800B0CD0: lw          $t4, 0x40($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X40);
    // 0x800B0CD4: lbu         $t3, 0x17($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X17);
    // 0x800B0CD8: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B0CDC: beq         $t5, $zero, L_800B0D30
    if (ctx->r13 == 0) {
        // 0x800B0CE0: sb          $t3, 0x6F($v0)
        MEM_B(0X6F, ctx->r2) = ctx->r11;
            goto L_800B0D30;
    }
    // 0x800B0CE0: sb          $t3, 0x6F($v0)
    MEM_B(0X6F, ctx->r2) = ctx->r11;
    // 0x800B0CE4: lw          $v1, 0x54($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X54);
    // 0x800B0CE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B0CEC: beq         $v1, $zero, L_800B0D30
    if (ctx->r3 == 0) {
        // 0x800B0CF0: nop
    
            goto L_800B0D30;
    }
    // 0x800B0CF0: nop

    // 0x800B0CF4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B0CF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0CFC: nop

    // 0x800B0D00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B0D04: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B0D08: nop

    // 0x800B0D0C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B0D10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0D14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0D18: nop

    // 0x800B0D1C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B0D20: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800B0D24: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B0D28: b           L_800B0D38
    // 0x800B0D2C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
        goto L_800B0D38;
    // 0x800B0D2C: sh          $t6, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r14;
L_800B0D30:
    // 0x800B0D30: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800B0D34: sh          $t8, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r24;
L_800B0D38:
    // 0x800B0D38: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x800B0D3C: nop

    // 0x800B0D40: sh          $t9, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r25;
    // 0x800B0D44: lbu         $t2, 0xC($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0XC);
    // 0x800B0D48: nop

    // 0x800B0D4C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800B0D50: sh          $t3, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r11;
    // 0x800B0D54: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B0D58: nop

    // 0x800B0D5C: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x800B0D60: beq         $at, $zero, L_800B0DA0
    if (ctx->r1 == 0) {
        // 0x800B0D64: nop
    
            goto L_800B0DA0;
    }
    // 0x800B0D64: nop

    // 0x800B0D68: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x800B0D6C: nop

    // 0x800B0D70: andi        $t7, $t5, 0x1000
    ctx->r15 = ctx->r13 & 0X1000;
    // 0x800B0D74: beq         $t7, $zero, L_800B0D90
    if (ctx->r15 == 0) {
        // 0x800B0D78: nop
    
            goto L_800B0D90;
    }
    // 0x800B0D78: nop

    // 0x800B0D7C: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x800B0D80: nop

    // 0x800B0D84: ori         $t8, $t6, 0x100
    ctx->r24 = ctx->r14 | 0X100;
    // 0x800B0D88: b           L_800B0DA0
    // 0x800B0D8C: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
        goto L_800B0DA0;
    // 0x800B0D8C: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
L_800B0D90:
    // 0x800B0D90: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800B0D94: nop

    // 0x800B0D98: ori         $t2, $t9, 0x80
    ctx->r10 = ctx->r25 | 0X80;
    // 0x800B0D9C: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
L_800B0DA0:
    // 0x800B0DA0: lh          $a0, 0x60($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X60);
    // 0x800B0DA4: lh          $v1, 0x3A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3A);
    // 0x800B0DA8: nop

    // 0x800B0DAC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B0DB0: beq         $at, $zero, L_800B0E04
    if (ctx->r1 == 0) {
        // 0x800B0DB4: nop
    
            goto L_800B0E04;
    }
    // 0x800B0DB4: nop

    // 0x800B0DB8: lbu         $t3, 0xD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XD);
    // 0x800B0DBC: lbu         $t4, 0xC($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XC);
    // 0x800B0DC0: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800B0DC4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800B0DC8: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800B0DCC: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x800B0DD0: bne         $t6, $zero, L_800B0DDC
    if (ctx->r14 != 0) {
        // 0x800B0DD4: nop
    
            goto L_800B0DDC;
    }
    // 0x800B0DD4: nop

    // 0x800B0DD8: break       7
    do_break(2148208088);
L_800B0DDC:
    // 0x800B0DDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0DE0: bne         $t6, $at, L_800B0DF4
    if (ctx->r14 != ctx->r1) {
        // 0x800B0DE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B0DF4;
    }
    // 0x800B0DE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B0DE8: bne         $t7, $at, L_800B0DF4
    if (ctx->r15 != ctx->r1) {
        // 0x800B0DEC: nop
    
            goto L_800B0DF4;
    }
    // 0x800B0DEC: nop

    // 0x800B0DF0: break       6
    do_break(2148208112);
L_800B0DF4:
    // 0x800B0DF4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B0DF8: sh          $t8, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r24;
    // 0x800B0DFC: b           L_800B0E0C
    // 0x800B0E00: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
        goto L_800B0E0C;
    // 0x800B0E00: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B0E04:
    // 0x800B0E04: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x800B0E08: lh          $t9, 0x18($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X18);
L_800B0E0C:
    // 0x800B0E0C: lh          $t2, 0x1A($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X1A);
    // 0x800B0E10: lh          $t3, 0x1C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1C);
    // 0x800B0E14: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800B0E18: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800B0E1C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B0E20: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B0E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0E28: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800B0E2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B0E30: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800B0E34: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B0E38: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800B0E3C: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    // 0x800B0E40: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800B0E44: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B0E48: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B0E4C: jal         0x80070320
    // 0x800B0E50: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B0E50: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800B0E54: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0E58: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0E5C: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B0E60: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B0E64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B0E68: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B0E6C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B0E70: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x800B0E74: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B0E78: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B0E7C: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B0E80: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B0E84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B0E88: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x800B0E8C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B0E90: nop

    // 0x800B0E94: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B0E98: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800B0E9C: sb          $zero, 0x68($a3)
    MEM_B(0X68, ctx->r7) = 0;
    // 0x800B0EA0: sb          $zero, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = 0;
    // 0x800B0EA4: sb          $v0, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r2;
    // 0x800B0EA8: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x800B0EAC: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x800B0EB0: sh          $t4, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r12;
    // 0x800B0EB4: lh          $a0, 0x4($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X4);
    // 0x800B0EB8: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800B0EBC: bne         $v0, $a0, L_800B0ECC
    if (ctx->r2 != ctx->r4) {
        // 0x800B0EC0: nop
    
            goto L_800B0ECC;
    }
    // 0x800B0EC0: nop

    // 0x800B0EC4: b           L_800B0F78
    // 0x800B0EC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800B0F78;
    // 0x800B0EC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B0ECC:
    // 0x800B0ECC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B0ED0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x800B0ED4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B0ED8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B0EDC: jal         0x8007AE74
    // 0x800B0EE0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B0EE0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_2:
    // 0x800B0EE4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0EE8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0EEC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B0EF0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800B0EF4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B0EF8: beq         $v0, $zero, L_800B0F78
    if (ctx->r2 == 0) {
        // 0x800B0EFC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B0F78;
    }
    // 0x800B0EFC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B0F00: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800B0F04: nop

    // 0x800B0F08: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800B0F0C: beq         $t6, $zero, L_800B0F4C
    if (ctx->r14 == 0) {
        // 0x800B0F10: nop
    
            goto L_800B0F4C;
    }
    // 0x800B0F10: nop

    // 0x800B0F14: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x800B0F18: nop

    // 0x800B0F1C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800B0F20: beq         $t9, $zero, L_800B0F3C
    if (ctx->r25 == 0) {
        // 0x800B0F24: nop
    
            goto L_800B0F3C;
    }
    // 0x800B0F24: nop

    // 0x800B0F28: lh          $t2, 0x6($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X6);
    // 0x800B0F2C: nop

    // 0x800B0F30: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B0F34: b           L_800B0F4C
    // 0x800B0F38: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
        goto L_800B0F4C;
    // 0x800B0F38: sh          $t3, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r11;
L_800B0F3C:
    // 0x800B0F3C: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    // 0x800B0F40: nop

    // 0x800B0F44: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x800B0F48: sh          $t5, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r13;
L_800B0F4C:
    // 0x800B0F4C: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x800B0F50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0F54: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x800B0F58: bne         $t6, $at, L_800B0F78
    if (ctx->r14 != ctx->r1) {
        // 0x800B0F5C: nop
    
            goto L_800B0F78;
    }
    // 0x800B0F5C: nop

    // 0x800B0F60: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B0F64: nop

    // 0x800B0F68: lhu         $t9, 0x12($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X12);
    // 0x800B0F6C: nop

    // 0x800B0F70: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800B0F74: sh          $t2, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r10;
L_800B0F78:
    // 0x800B0F78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B0F7C: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800B0F80: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B0F84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0F88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0F8C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B0F90: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B0F94: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B0F98: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800B0F9C: nop

    // 0x800B0FA0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B0FA4: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x800B0FA8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B0FAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0FB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0FB4: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800B0FB8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B0FBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B0FC0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B0FC4: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B0FC8: nop

    // 0x800B0FCC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B0FD0: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x800B0FD4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B0FD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B0FDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B0FE0: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800B0FE4: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B0FE8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B0FEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B0FF0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B0FF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B0FF8: beq         $t1, $at, L_800B1094
    if (ctx->r9 == ctx->r1) {
        // 0x800B0FFC: sh          $t2, 0x4($t3)
        MEM_H(0X4, ctx->r11) = ctx->r10;
            goto L_800B1094;
    }
    // 0x800B0FFC: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x800B1000: lh          $t4, 0x1E($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1004: nop

    // 0x800B1008: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B100C: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x800B1010: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B1014: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1018: nop

    // 0x800B101C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1020: bne         $at, $zero, L_800B1038
    if (ctx->r1 != 0) {
        // 0x800B1024: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800B1038;
    }
    // 0x800B1024: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800B1028: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B102C: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1030: nop

    // 0x800B1034: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
L_800B1038:
    // 0x800B1038: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x800B103C: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x800B1040: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B1044: nop

    // 0x800B1048: sb          $t9, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r25;
    // 0x800B104C: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1050: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800B1054: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B1058: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800B105C: lbu         $t7, 0x15($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X15);
    // 0x800B1060: nop

    // 0x800B1064: sb          $t7, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r15;
    // 0x800B1068: lh          $t8, 0x1E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1E);
    // 0x800B106C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B1070: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B1074: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800B1078: lbu         $t3, 0x16($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X16);
    // 0x800B107C: nop

    // 0x800B1080: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B1084: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B1088: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B108C: b           L_800B10D4
    // 0x800B1090: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
        goto L_800B10D4;
    // 0x800B1090: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B1094:
    // 0x800B1094: lbu         $t6, 0x6C($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X6C);
    // 0x800B1098: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B109C: nop

    // 0x800B10A0: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800B10A4: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B10A8: lbu         $t9, 0x6D($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6D);
    // 0x800B10AC: nop

    // 0x800B10B0: sb          $t9, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r25;
    // 0x800B10B4: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B10B8: lbu         $t3, 0x6E($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X6E);
    // 0x800B10BC: nop

    // 0x800B10C0: sb          $t3, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r11;
    // 0x800B10C4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B10C8: lbu         $t5, 0x6($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6);
    // 0x800B10CC: nop

    // 0x800B10D0: sb          $t5, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r13;
L_800B10D4:
    // 0x800B10D4: lhu         $t6, 0xA($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0XA);
    // 0x800B10D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800B10DC: srl         $t8, $t6, 10
    ctx->r24 = S32(U32(ctx->r14) >> 10);
    // 0x800B10E0: sb          $t8, 0x6A($a3)
    MEM_B(0X6A, ctx->r7) = ctx->r24;
    // 0x800B10E4: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800B10E8: nop

    // 0x800B10EC: sll         $t2, $t9, 22
    ctx->r10 = S32(ctx->r25 << 22);
    // 0x800B10F0: srl         $t3, $t2, 26
    ctx->r11 = S32(U32(ctx->r10) >> 26);
    // 0x800B10F4: sb          $t3, 0x6B($a3)
    MEM_B(0X6B, ctx->r7) = ctx->r11;
    // 0x800B10F8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B10FC: nop

    // 0x800B1100: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800B1104: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B1108: nop

    // 0x800B110C: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x800B1110: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B1114: nop

    // 0x800B1118: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x800B111C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
L_800B1120:
    // 0x800B1120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B1124: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B1128: jr          $ra
    // 0x800B112C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B112C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7570: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800D7574: mflo        $v0
    ctx->r2 = lo;
    // 0x800D7578: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D757C: bne         $a2, $zero, L_800D7588
    if (ctx->r6 != 0) {
        // 0x800D7580: nop
    
            goto L_800D7588;
    }
    // 0x800D7580: nop

    // 0x800D7584: break       7
    do_break(2148365700);
L_800D7588:
    // 0x800D7588: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D758C: bne         $a2, $at, L_800D75A0
    if (ctx->r6 != ctx->r1) {
        // 0x800D7590: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D75A0;
    }
    // 0x800D7590: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D7594: bne         $a1, $at, L_800D75A0
    if (ctx->r5 != ctx->r1) {
        // 0x800D7598: nop
    
            goto L_800D75A0;
    }
    // 0x800D7598: nop

    // 0x800D759C: break       6
    do_break(2148365724);
L_800D75A0:
    // 0x800D75A0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D75A4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D75A8: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800D75AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800D75B0: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800D75B4: bgez        $v0, L_800D75D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D75B8: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D75D8;
    }
    // 0x800D75B8: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D75BC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D75C0: blez        $v1, L_800D75D8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D75C4: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D75D8;
    }
    // 0x800D75C4: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D75C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D75CC: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D75D0: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D75D4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800D75D8:
    // 0x800D75D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800D75DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D75E0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800D75E4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800D75E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800D75EC: jr          $ra
    // 0x800D75F0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800D75F0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void mempool_free_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071278: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007127C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071280: jal         0x800715EC
    // 0x80071284: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mempool_get_pool(rdram, ctx);
        goto after_0;
    // 0x80071284: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071288: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8007128C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071290: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80071294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80071298: lw          $v1, 0x3588($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3588);
    // 0x8007129C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800712A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800712A4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800712A8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800712AC:
    // 0x800712AC: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800712B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800712B4: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800712B8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800712BC: nop

    // 0x800712C0: bne         $a0, $t8, L_800712F4
    if (ctx->r4 != ctx->r24) {
        // 0x800712C4: nop
    
            goto L_800712F4;
    }
    // 0x800712C4: nop

    // 0x800712C8: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x800712CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800712D0: beq         $v1, $at, L_800712E0
    if (ctx->r3 == ctx->r1) {
        // 0x800712D4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800712E0;
    }
    // 0x800712D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800712D8: bne         $v1, $at, L_80071308
    if (ctx->r3 != ctx->r1) {
        // 0x800712DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80071308;
    }
    // 0x800712DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800712E0:
    // 0x800712E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800712E4: jal         0x8007164C
    // 0x800712E8: nop

    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x800712E8: nop

    after_1:
    // 0x800712EC: b           L_80071308
    // 0x800712F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80071308;
    // 0x800712F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800712F4:
    // 0x800712F4: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x800712F8: nop

    // 0x800712FC: bne         $a1, $a3, L_800712AC
    if (ctx->r5 != ctx->r7) {
        // 0x80071300: nop
    
            goto L_800712AC;
    }
    // 0x80071300: nop

    // 0x80071304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071308:
    // 0x80071308: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007130C: jr          $ra
    // 0x80071310: nop

    return;
    // 0x80071310: nop

;}
RECOMP_FUNC void update_camera_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058F44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80058F48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058F4C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058F50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058F54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058F5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80058F60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80058F64: lw          $v1, -0x2AF8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AF8);
    // 0x80058F68: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80058F6C: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058F70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80058F74: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80058F78: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058F7C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80058F80: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80058F84: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80058F88: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058F8C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80058F90: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80058F94: nop

    // 0x80058F98: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80058F9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058FA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058FA4: nop

    // 0x80058FA8: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80058FAC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80058FB0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80058FB4: nop

    // 0x80058FB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80058FBC: nop

    // 0x80058FC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80058FC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058FC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058FCC: nop

    // 0x80058FD0: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80058FD4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80058FD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80058FDC: jal         0x8007066C
    // 0x80058FE0: nop

    atan2s(rdram, ctx);
        goto after_0;
    // 0x80058FE0: nop

    after_0:
    // 0x80058FE4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80058FE8: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80058FEC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80058FF0: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x80058FF4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80058FF8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80058FFC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80059000: subu        $t1, $t9, $a0
    ctx->r9 = SUB32(ctx->r25, ctx->r4);
    // 0x80059004: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80059008: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005900C: mflo        $t3
    ctx->r11 = lo;
    // 0x80059010: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80059014: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80059018: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8005901C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80059020: nop

    // 0x80059024: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x80059028: nop

    // 0x8005902C: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059030: mflo        $t6
    ctx->r14 = lo;
    // 0x80059034: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80059038: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x8005903C: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80059040: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80059044: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80059048: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8005904C: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80059050: lwc1        $f14, 0x3C($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x80059054: jal         0x80029F18
    // 0x80059058: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_1;
    // 0x80059058: nop

    after_1:
    // 0x8005905C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80059060: addiu       $a3, $a3, -0x2AF8
    ctx->r7 = ADD32(ctx->r7, -0X2AF8);
    // 0x80059064: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80059068: nop

    // 0x8005906C: sh          $v0, 0x34($t1)
    MEM_H(0X34, ctx->r9) = ctx->r2;
    // 0x80059070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059078: jr          $ra
    // 0x8005907C: nop

    return;
    // 0x8005907C: nop

;}
RECOMP_FUNC void obj_loop_weather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040820: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80040824: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040828: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004082C: jal         0x80066220
    // 0x80040830: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x80040830: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80040834: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80040838: jal         0x8001BA74
    // 0x8004083C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x8004083C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80040840: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80040844: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80040848: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8004084C: beq         $a1, $zero, L_8004091C
    if (ctx->r5 == 0) {
        // 0x80040850: addiu       $a0, $a1, -0x1
        ctx->r4 = ADD32(ctx->r5, -0X1);
            goto L_8004091C;
    }
    // 0x80040850: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x80040854: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80040858: addu        $a3, $t6, $v0
    ctx->r7 = ADD32(ctx->r14, ctx->r2);
    // 0x8004085C: addiu       $v1, $v0, -0x4
    ctx->r3 = ADD32(ctx->r2, -0X4);
L_80040860:
    // 0x80040860: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80040864: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80040868: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x8004086C: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80040870: beq         $at, $zero, L_80040888
    if (ctx->r1 == 0) {
        // 0x80040874: nop
    
            goto L_80040888;
    }
    // 0x80040874: nop

    // 0x80040878: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8004087C: nop

    // 0x80040880: bne         $a2, $t7, L_80040860
    if (ctx->r6 != ctx->r15) {
        // 0x80040884: nop
    
            goto L_80040860;
    }
    // 0x80040884: nop

L_80040888:
    // 0x80040888: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8004088C: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80040890: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80040894: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80040898: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8004089C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800408A0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800408A4: lwc1        $f12, 0x78($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X78);
    // 0x800408A8: lw          $v1, 0x3C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X3C);
    // 0x800408AC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800408B0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800408B4: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x800408B8: nop

    // 0x800408BC: bc1f        L_80040920
    if (!c1cs) {
        // 0x800408C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80040920;
    }
    // 0x800408C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800408C4: lbu         $t2, 0x10($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X10);
    // 0x800408C8: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x800408CC: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800408D0: lbu         $t3, 0x11($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X11);
    // 0x800408D4: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x800408D8: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    // 0x800408DC: lh          $a2, 0xE($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XE);
    // 0x800408E0: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x800408E4: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x800408E8: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x800408EC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800408F0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800408F4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800408F8: mflo        $a3
    ctx->r7 = lo;
    // 0x800408FC: nop

    // 0x80040900: nop

    // 0x80040904: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040908: mflo        $t4
    ctx->r12 = lo;
    // 0x8004090C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80040910: lh          $t5, 0x12($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X12);
    // 0x80040914: jal         0x800ABC5C
    // 0x80040918: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    weather_set(rdram, ctx);
        goto after_2;
    // 0x80040918: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
L_8004091C:
    // 0x8004091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80040920:
    // 0x80040920: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80040924: jr          $ra
    // 0x80040928: nop

    return;
    // 0x80040928: nop

;}
RECOMP_FUNC void bgdraw_chequer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_chequer_background_stretch_begin(uint8_t*, recomp_context*); dkr_chequer_background_stretch_begin(rdram, ctx);
    // 0x800787FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80078800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80078804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078808: jal         0x8007A520
    // 0x8007880C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x8007880C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80078810: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078814: andi        $ra, $t6, 0xFFFF
    ctx->r31 = ctx->r14 & 0XFFFF;
    // 0x80078818: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8007881C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078820: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078824: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078828: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8007882C: addiu       $t6, $t6, -0x1A20
    ctx->r14 = ADD32(ctx->r14, -0X1A20);
    // 0x80078830: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80078834: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078838: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007883C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078840: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078844: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078848: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007884C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078850: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078854: lbu         $t6, 0x5F30($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X5F30);
    // 0x80078858: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007885C: lbu         $t9, 0x5F31($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5F31);
    // 0x80078860: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078864: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078868: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007886C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078870: lbu         $t7, 0x5F32($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X5F32);
    // 0x80078874: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x80078878: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x8007887C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80078880: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80078884: lbu         $t8, 0x5F33($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5F33);
    // 0x80078888: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x8007888C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078890: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80078894: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80078898: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8007889C: blez        $t7, L_80078968
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800788A0: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80078968;
    }
    // 0x800788A0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800788A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800788A8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800788AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800788B0: lw          $a2, 0x5F38($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5F38);
    // 0x800788B4: addiu       $a3, $a3, 0x5F38
    ctx->r7 = ADD32(ctx->r7, 0X5F38);
    // 0x800788B8: addiu       $t1, $t1, 0x5F3C
    ctx->r9 = ADD32(ctx->r9, 0X5F3C);
    // 0x800788BC: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
L_800788C0:
    // 0x800788C0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800788C4: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x800788C8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800788CC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800788D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800788D4: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800788D8: beq         $at, $zero, L_8007894C
    if (ctx->r1 == 0) {
        // 0x800788DC: nop
    
            goto L_8007894C;
    }
    // 0x800788DC: nop

L_800788E0:
    // 0x800788E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800788E4: nop

    // 0x800788E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800788EC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800788F0: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800788F4: nop

    // 0x800788F8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800788FC: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80078900: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078904: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x80078908: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x8007890C: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x80078910: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x80078914: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80078918: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8007891C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80078920: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80078924: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078928: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007892C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078930: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078934: nop

    // 0x80078938: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8007893C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80078940: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078944: bne         $at, $zero, L_800788E0
    if (ctx->r1 != 0) {
        // 0x80078948: nop
    
            goto L_800788E0;
    }
    // 0x80078948: nop

L_8007894C:
    // 0x8007894C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078950: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078954: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80078958: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8007895C: bne         $at, $zero, L_800788C0
    if (ctx->r1 != 0) {
        // 0x80078960: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_800788C0;
    }
    // 0x80078960: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80078964: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80078968:
    // 0x80078968: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007896C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80078970: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078974: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078978: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007897C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078980: lbu         $t6, 0x5F34($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X5F34);
    // 0x80078984: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80078988: lbu         $t8, 0x5F35($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X5F35);
    // 0x8007898C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80078990: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80078994: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80078998: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007899C: lbu         $t7, 0x5F36($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X5F36);
    // 0x800789A0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800789A4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800789A8: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800789AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800789B0: lbu         $t9, 0x5F37($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X5F37);
    // 0x800789B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800789B8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800789BC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800789C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800789C4: addiu       $t1, $t1, 0x5F3C
    ctx->r9 = ADD32(ctx->r9, 0X5F3C);
    // 0x800789C8: addiu       $a3, $a3, 0x5F38
    ctx->r7 = ADD32(ctx->r7, 0X5F38);
    // 0x800789CC: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x800789D0: blez        $t7, L_80078A84
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800789D4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80078A84;
    }
    // 0x800789D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800789D8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800789DC: nop

L_800789E0:
    // 0x800789E0: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800789E4: andi        $a1, $t0, 0x3FF
    ctx->r5 = ctx->r8 & 0X3FF;
    // 0x800789E8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800789EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800789F0: mflo        $v0
    ctx->r2 = lo;
    // 0x800789F4: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800789F8: beq         $at, $zero, L_80078A6C
    if (ctx->r1 == 0) {
        // 0x800789FC: nop
    
            goto L_80078A6C;
    }
    // 0x800789FC: nop

L_80078A00:
    // 0x80078A00: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078A04: nop

    // 0x80078A08: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078A0C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078A10: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80078A14: nop

    // 0x80078A18: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80078A1C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80078A20: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80078A24: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80078A28: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80078A2C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80078A30: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80078A34: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078A38: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80078A3C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80078A40: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80078A44: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80078A48: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078A4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078A50: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80078A54: nop

    // 0x80078A58: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80078A5C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80078A60: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80078A64: bne         $at, $zero, L_80078A00
    if (ctx->r1 != 0) {
        // 0x80078A68: nop
    
            goto L_80078A00;
    }
    // 0x80078A68: nop

L_80078A6C:
    // 0x80078A6C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80078A70: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x80078A74: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80078A78: slt         $at, $t0, $ra
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x80078A7C: bne         $at, $zero, L_800789E0
    if (ctx->r1 != 0) {
        // 0x80078A80: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_800789E0;
    }
    // 0x80078A80: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
L_80078A84:
    // 0x80078A84: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80078A88: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078A8C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078A90: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078A94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078A98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    extern void dkr_chequer_background_stretch_end(uint8_t*, recomp_context*); dkr_chequer_background_stretch_end(rdram, ctx);
    // 0x80078A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078AA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078AA4: jr          $ra
    // 0x80078AA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80078AA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A7C4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A7CC: beq         $v1, $zero, L_8000A844
    if (ctx->r3 == 0) {
        // 0x8000A7D0: addiu       $a2, $a1, -0x4
        ctx->r6 = ADD32(ctx->r5, -0X4);
            goto L_8000A844;
    }
    // 0x8000A7D0: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
L_8000A7D4:
    // 0x8000A7D4: bne         $v1, $a2, L_8000A830
    if (ctx->r3 != ctx->r6) {
        // 0x8000A7D8: nop
    
            goto L_8000A830;
    }
    // 0x8000A7D8: nop

    // 0x8000A7DC: beq         $v0, $zero, L_8000A7F0
    if (ctx->r2 == 0) {
        // 0x8000A7E0: nop
    
            goto L_8000A7F0;
    }
    // 0x8000A7E0: nop

    // 0x8000A7E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7E8: b           L_8000A7FC
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_8000A7FC;
    // 0x8000A7EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000A7F0:
    // 0x8000A7F0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000A7F4: nop

    // 0x8000A7F8: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_8000A7FC:
    // 0x8000A7FC: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x8000A800: nop

    // 0x8000A804: bne         $v1, $t8, L_8000A810
    if (ctx->r3 != ctx->r24) {
        // 0x8000A808: nop
    
            goto L_8000A810;
    }
    // 0x8000A808: nop

    // 0x8000A80C: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
L_8000A810:
    // 0x8000A810: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A814: nop

    // 0x8000A818: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000A81C: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A820: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x8000A824: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000A828: jr          $ra
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
    return;
    // 0x8000A82C: sb          $t1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r9;
L_8000A830:
    // 0x8000A830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A834: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A838: nop

    // 0x8000A83C: bne         $v1, $zero, L_8000A7D4
    if (ctx->r3 != 0) {
        // 0x8000A840: nop
    
            goto L_8000A7D4;
    }
    // 0x8000A840: nop

L_8000A844:
    // 0x8000A844: jr          $ra
    // 0x8000A848: nop

    return;
    // 0x8000A848: nop

;}
RECOMP_FUNC void hud_silver_coins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A47A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A47A4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800A47A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A47AC: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800A47B0: addiu       $fp, $fp, 0x6CDC
    ctx->r30 = ADD32(ctx->r30, 0X6CDC);
    // 0x800A47B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A47B8: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A47BC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A47C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A47C4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800A47C8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800A47CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800A47D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A47D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A47D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A47DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A47E0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800A47E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A47E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A47EC: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A47F0: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800A47F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A47F8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800A47FC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4800: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4804: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A4808: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A480C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A4810: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A4814: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4818: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A481C: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A4820: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800A4824: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A4828: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A482C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4830: lwc1        $f16, 0x5D0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X5D0);
    // 0x800A4834: addiu       $s5, $s5, 0x6D04
    ctx->r21 = ADD32(ctx->r21, 0X6D04);
    // 0x800A4838: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A483C: addiu       $s4, $s4, 0x6D00
    ctx->r20 = ADD32(ctx->r20, 0X6D00);
    // 0x800A4840: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800A4844: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A4848: addiu       $s3, $s3, 0x6CFC
    ctx->r19 = ADD32(ctx->r19, 0X6CFC);
    // 0x800A484C: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800A4850: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A4854: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x800A4858: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800A485C:
    // 0x800A485C: lb          $t1, 0x202($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X202);
    // 0x800A4860: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A4864: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4868: bne         $at, $zero, L_800A4878
    if (ctx->r1 != 0) {
        // 0x800A486C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800A4878;
    }
    // 0x800A486C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A4870: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4874: sw          $s2, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r18;
L_800A4878:
    // 0x800A4878: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800A487C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800A4880: jal         0x800AA600
    // 0x800A4884: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4884: addiu       $a3, $s1, 0x5C0
    ctx->r7 = ADD32(ctx->r17, 0X5C0);
    after_0:
    // 0x800A4888: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A488C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A4890: lb          $t2, 0x5DC($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X5DC);
    // 0x800A4894: lwc1        $f4, 0x5D0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X5D0);
    // 0x800A4898: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A489C: nop

    // 0x800A48A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A48A4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800A48A8: bne         $s0, $s7, L_800A485C
    if (ctx->r16 != ctx->r23) {
        // 0x800A48AC: swc1        $f10, 0x5D0($s1)
        MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
            goto L_800A485C;
    }
    // 0x800A48AC: swc1        $f10, 0x5D0($s1)
    MEM_W(0X5D0, ctx->r17) = ctx->f10.u32l;
    // 0x800A48B0: lb          $t3, 0x202($s6)
    ctx->r11 = MEM_B(ctx->r22, 0X202);
    // 0x800A48B4: nop

    // 0x800A48B8: bne         $s7, $t3, L_800A4930
    if (ctx->r23 != ctx->r11) {
        // 0x800A48BC: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4930;
    }
    // 0x800A48BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A48C0: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A48C4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A48C8: lb          $v0, 0x5DB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A48CC: nop

    // 0x800A48D0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800A48D4: beq         $at, $zero, L_800A48E8
    if (ctx->r1 == 0) {
        // 0x800A48D8: addu        $t5, $v0, $t4
        ctx->r13 = ADD32(ctx->r2, ctx->r12);
            goto L_800A48E8;
    }
    // 0x800A48D8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800A48DC: sb          $t5, 0x5DB($s1)
    MEM_B(0X5DB, ctx->r17) = ctx->r13;
    // 0x800A48E0: lw          $s1, 0x0($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X0);
    // 0x800A48E4: nop

L_800A48E8:
    // 0x800A48E8: lb          $t6, 0x5DA($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X5DA);
    // 0x800A48EC: nop

    // 0x800A48F0: bne         $t6, $zero, L_800A4930
    if (ctx->r14 != 0) {
        // 0x800A48F4: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4930;
    }
    // 0x800A48F4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A48F8: lb          $t7, 0x5DB($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X5DB);
    // 0x800A48FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4900: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A4904: bne         $at, $zero, L_800A492C
    if (ctx->r1 != 0) {
        // 0x800A4908: addiu       $a1, $a1, 0x6D40
        ctx->r5 = ADD32(ctx->r5, 0X6D40);
            goto L_800A492C;
    }
    // 0x800A4908: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A490C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A4910: sb          $t8, 0x5DA($s1)
    MEM_B(0X5DA, ctx->r17) = ctx->r24;
    // 0x800A4914: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A4918: nop

    // 0x800A491C: bne         $t9, $zero, L_800A4930
    if (ctx->r25 != 0) {
        // 0x800A4920: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800A4930;
    }
    // 0x800A4920: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A4924: jal         0x80001D04
    // 0x800A4928: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A4928: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_1:
L_800A492C:
    // 0x800A492C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_800A4930:
    // 0x800A4930: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800A4934: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A4938: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x800A493C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4940: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A4944: swc1        $f18, 0x5D0($t1)
    MEM_W(0X5D0, ctx->r9) = ctx->f18.u32l;
    // 0x800A4948: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A494C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800A4950: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800A4954: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800A4958: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800A495C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A4960: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A4964: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A4968: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A496C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A4970: sw          $t2, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r10;
    // 0x800A4974: jr          $ra
    // 0x800A4978: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A4978: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80017A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A18: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80017A1C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017A20: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017A24: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017A28: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017A2C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017A30: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017A34: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017A38: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017A3C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017A40: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017A44: swc1        $f31, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80017A48: swc1        $f30, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f30.u32l;
    // 0x80017A4C: swc1        $f29, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80017A50: swc1        $f28, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f28.u32l;
    // 0x80017A54: swc1        $f27, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80017A58: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x80017A5C: swc1        $f25, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80017A60: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80017A64: swc1        $f23, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017A68: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x80017A6C: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017A70: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80017A74: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x80017A78: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x80017A7C: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x80017A80: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x80017A84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80017A88: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80017A8C: blez        $a1, L_80017E10
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80017A90: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80017E10;
    }
    // 0x80017A90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017A94: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x80017A98: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80017A9C: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80017AA0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80017AA4: lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X138);
    // 0x80017AA8: lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X13C);
    // 0x80017AAC: lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X140);
    // 0x80017AB0: lw          $fp, 0x130($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X130);
    // 0x80017AB4: lw          $ra, 0x134($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X134);
    // 0x80017AB8: lw          $s5, 0x148($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X148);
    // 0x80017ABC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80017AC0: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80017AC4:
    // 0x80017AC4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80017AC8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80017ACC: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017AD0: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80017AD4: lwc1        $f30, 0x0($s3)
    ctx->f30.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80017AD8: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x80017ADC: lwc1        $f10, 0x14C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80017AE0: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80017AE4: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80017AE8: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80017AEC: lwc1        $f20, 0x0($fp)
    ctx->f20.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80017AF0: lwc1        $f22, 0x0($ra)
    ctx->f22.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80017AF4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80017AF8: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    // 0x80017AFC: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017B00: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80017B04: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_80017B08:
    // 0x80017B08: blez        $t3, L_80017DA8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017B0C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80017DA8;
    }
    // 0x80017B0C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017B10: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x80017B14: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x80017B18: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
L_80017B1C:
    // 0x80017B1C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80017B20: lwc1        $f28, 0xA4($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017B24: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017B28: lwc1        $f20, 0x9C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017B2C: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80017B30: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80017B34: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80017B38: lwc1        $f18, 0xC0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017B3C: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80017B40: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80017B44: lwc1        $f26, 0x4($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017B48: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017B4C: mul.s       $f14, $f26, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x80017B50: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017B54: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017B58: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x80017B5C: mul.s       $f4, $f16, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x80017B60: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017B64: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x80017B68: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017B6C: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017B70: add.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017B74: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80017B78: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017B7C: mul.s       $f14, $f26, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80017B80: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80017B84: swc1        $f10, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f10.u32l;
    // 0x80017B88: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017B8C: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80017B90: add.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017B94: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017B98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017B9C: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80017BA0: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80017BA4: lwc1        $f10, 0x560C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X560C);
    // 0x80017BA8: swc1        $f28, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f28.u32l;
    // 0x80017BAC: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80017BB0: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x80017BB4: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80017BB8: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80017BBC: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80017BC0: lwc1        $f11, 0x5608($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5608);
    // 0x80017BC4: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80017BC8: c.le.d      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.d <= ctx->f14.d;
    // 0x80017BCC: sub.s       $f22, $f12, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80017BD0: bc1f        L_80017D88
    if (!c1cs) {
        // 0x80017BD4: swc1        $f8, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
            goto L_80017D88;
    }
    // 0x80017BD4: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x80017BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017BDC: lwc1        $f9, 0x5610($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5610);
    // 0x80017BE0: lwc1        $f8, 0x5614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5614);
    // 0x80017BE4: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80017BE8: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80017BEC: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80017BF0: bc1f        L_80017D88
    if (!c1cs) {
        // 0x80017BF4: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80017D88;
    }
    // 0x80017BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80017BF8: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80017BFC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80017C00: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80017C04: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x80017C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017C0C: sub.s       $f28, $f6, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017C10: bc1t        L_80017C24
    if (c1cs) {
        // 0x80017C14: sub.s       $f14, $f30, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
            goto L_80017C24;
    }
    // 0x80017C14: sub.s       $f14, $f30, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x80017C18: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80017C1C: b           L_80017C2C
    // 0x80017C20: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_80017C2C;
    // 0x80017C20: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_80017C24:
    // 0x80017C24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80017C28: nop

L_80017C2C:
    // 0x80017C2C: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80017C30: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017C34: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017C38: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80017C3C: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80017C40: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017C44: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017C48: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    // 0x80017C4C: mul.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80017C50: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017C54: add.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f6.fl;
L_80017C58:
    // 0x80017C58: lhu         $t8, 0x2($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X2);
    // 0x80017C5C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80017C60: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80017C64: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80017C68: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017C6C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80017C70: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80017C74: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80017C78: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80017C7C: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80017C80: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80017C84: nop

    // 0x80017C88: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80017C8C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017C90: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017C94: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80017C98: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80017C9C: nop

    // 0x80017CA0: bc1f        L_80017CAC
    if (!c1cs) {
        // 0x80017CA4: nop
    
            goto L_80017CAC;
    }
    // 0x80017CA4: nop

    // 0x80017CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80017CAC:
    // 0x80017CAC: beq         $at, $zero, L_80017CBC
    if (ctx->r1 == 0) {
        // 0x80017CB0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80017CBC;
    }
    // 0x80017CB0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80017CB4: beq         $a2, $a3, L_80017C58
    if (ctx->r6 == ctx->r7) {
        // 0x80017CB8: nop
    
            goto L_80017C58;
    }
    // 0x80017CB8: nop

L_80017CBC:
    // 0x80017CBC: beq         $a2, $zero, L_80017D88
    if (ctx->r6 == 0) {
        // 0x80017CC0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80017D88;
    }
    // 0x80017CC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80017CC4: lwc1        $f9, 0x5618($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5618);
    // 0x80017CC8: lwc1        $f8, 0x561C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X561C);
    // 0x80017CCC: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x80017CD0: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80017CD4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80017CD8: bc1f        L_80017D04
    if (!c1cs) {
        // 0x80017CDC: addu        $v0, $s5, $s1
        ctx->r2 = ADD32(ctx->r21, ctx->r17);
            goto L_80017D04;
    }
    // 0x80017CDC: addu        $v0, $s5, $s1
    ctx->r2 = ADD32(ctx->r21, ctx->r17);
    // 0x80017CE0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80017CE4: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80017CE8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80017CEC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80017CF0: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80017CF4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80017CF8: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80017CFC: b           L_80017D34
    // 0x80017D00: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
        goto L_80017D34;
    // 0x80017D00: div.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
L_80017D04:
    // 0x80017D04: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80017D08: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D0C: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80017D10: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80017D14: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80017D18: mul.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80017D1C: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80017D20: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017D24: mul.s       $f8, $f22, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80017D28: sub.s       $f30, $f30, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f10.fl;
    // 0x80017D2C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80017D30: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_80017D34:
    // 0x80017D34: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80017D38: slti        $at, $t4, 0xB
    ctx->r1 = SIGNED(ctx->r12) < 0XB ? 1 : 0;
    // 0x80017D3C: bne         $at, $zero, L_80017D5C
    if (ctx->r1 != 0) {
        // 0x80017D40: nop
    
            goto L_80017D5C;
    }
    // 0x80017D40: nop

    // 0x80017D44: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017D48: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017D4C: lwc1        $f30, 0xA0($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017D50: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017D54: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80017D58: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
L_80017D5C:
    // 0x80017D5C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80017D60: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80017D64: nop

    // 0x80017D68: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x80017D6C: swc1        $f30, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f30.u32l;
    // 0x80017D70: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80017D74: nop

    // 0x80017D78: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80017D7C: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80017D80: nop

    // 0x80017D84: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_80017D88:
    // 0x80017D88: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80017D8C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80017D90: bne         $at, $zero, L_80017B1C
    if (ctx->r1 != 0) {
        // 0x80017D94: nop
    
            goto L_80017B1C;
    }
    // 0x80017D94: nop

    // 0x80017D98: lwc1        $f22, 0x9C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80017D9C: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80017DA0: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80017DA4: nop

L_80017DA8:
    // 0x80017DA8: bne         $t5, $zero, L_80017B08
    if (ctx->r13 != 0) {
        // 0x80017DAC: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80017B08;
    }
    // 0x80017DAC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80017DB0: blez        $t4, L_80017DE0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80017DB4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80017DE0;
    }
    // 0x80017DB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80017DB8: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80017DBC: nop

    // 0x80017DC0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80017DC4: nop

    // 0x80017DC8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80017DCC: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80017DD0: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80017DD4: nop

    // 0x80017DD8: or          $t6, $t9, $s6
    ctx->r14 = ctx->r25 | ctx->r22;
    // 0x80017DDC: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
L_80017DE0:
    // 0x80017DE0: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80017DE4: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80017DE8: sll         $t8, $s6, 1
    ctx->r24 = S32(ctx->r22 << 1);
    // 0x80017DEC: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80017DF0: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80017DF4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017DF8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017DFC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017E00: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80017E04: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80017E08: bne         $s1, $t6, L_80017AC4
    if (ctx->r17 != ctx->r14) {
        // 0x80017E0C: or          $s6, $t8, $zero
        ctx->r22 = ctx->r24 | 0;
            goto L_80017AC4;
    }
    // 0x80017E0C: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
L_80017E10:
    // 0x80017E10: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80017E14: lw          $v0, 0xF8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF8);
    // 0x80017E18: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x80017E1C: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80017E20: lwc1        $f23, 0x10($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80017E24: lwc1        $f22, 0x14($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017E28: lwc1        $f25, 0x18($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017E2C: lwc1        $f24, 0x1C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80017E30: lwc1        $f27, 0x20($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80017E34: lwc1        $f26, 0x24($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80017E38: lwc1        $f29, 0x28($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80017E3C: lwc1        $f28, 0x2C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80017E40: lwc1        $f31, 0x30($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80017E44: lwc1        $f30, 0x34($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80017E48: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80017E4C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80017E50: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80017E54: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80017E58: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80017E5C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80017E60: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80017E64: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80017E68: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80017E6C: jr          $ra
    // 0x80017E70: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x80017E70: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void sndp_set_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80004608: beq         $a0, $zero, L_80004614
    if (ctx->r4 == 0) {
        // 0x8000460C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_80004614;
    }
    // 0x8000460C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80004610: sb          $t6, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r14;
L_80004614:
    // 0x80004614: jr          $ra
    // 0x80004618: nop

    return;
    // 0x80004618: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AA0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C7AA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C7AA8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C7AAC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C7AB0: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800C7AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7AB8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C7ABC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C7AC0: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x800C7AC4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C7AC8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7ACC: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800C7AD0:
    // 0x800C7AD0: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x800C7AD4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C7AD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C7ADC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800C7AE0: lw          $t1, 0x58($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X58);
    // 0x800C7AE4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C7AE8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C7AEC: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800C7AF0: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800C7AF4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C7AF8: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800C7AFC: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800C7B00: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800C7B04: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800C7B08: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800C7B0C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800C7B10: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800C7B14: lw          $t6, 0x54($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X54);
    // 0x800C7B18: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800C7B1C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800C7B20: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800C7B24: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800C7B28: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800C7B2C: lw          $t9, 0xB4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XB4);
    // 0x800C7B30: bne         $v0, $a0, L_800C7AD0
    if (ctx->r2 != ctx->r4) {
        // 0x800C7B34: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800C7AD0;
    }
    // 0x800C7B34: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800C7B38: jr          $ra
    // 0x800C7B3C: nop

    return;
    // 0x800C7B3C: nop

;}
RECOMP_FUNC void menu_cinematic_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ACFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009AD00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009AD04: lw          $t6, 0x63C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C4);
    // 0x8009AD08: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8009AD0C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8009AD10: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8009AD14: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8009AD18: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8009AD1C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8009AD20: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8009AD24: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009AD28: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8009AD2C: bne         $t6, $zero, L_8009AD68
    if (ctx->r14 != 0) {
        // 0x8009AD30: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8009AD68;
    }
    // 0x8009AD30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009AD34: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009AD38: addiu       $s1, $s1, -0xB44
    ctx->r17 = ADD32(ctx->r17, -0XB44);
    // 0x8009AD3C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009AD40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009AD44: blez        $t7, L_8009AD68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009AD48: nop
    
            goto L_8009AD68;
    }
    // 0x8009AD48: nop

L_8009AD4C:
    // 0x8009AD4C: jal         0x8006A554
    // 0x8009AD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8009AD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009AD54: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009AD58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009AD5C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009AD60: bne         $at, $zero, L_8009AD4C
    if (ctx->r1 != 0) {
        // 0x8009AD64: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009AD4C;
    }
    // 0x8009AD64: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_8009AD68:
    // 0x8009AD68: jal         0x800214C4
    // 0x8009AD6C: nop

    func_800214C4(rdram, ctx);
        goto after_1;
    // 0x8009AD6C: nop

    after_1:
    // 0x8009AD70: beq         $v0, $zero, L_8009ADE4
    if (ctx->r2 == 0) {
        // 0x8009AD74: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009ADE4;
    }
    // 0x8009AD74: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AD78: addiu       $v1, $v1, 0x67EC
    ctx->r3 = ADD32(ctx->r3, 0X67EC);
    // 0x8009AD7C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009AD80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009AD84: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x8009AD88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8009AD8C: lb          $a0, 0x0($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X0);
    // 0x8009AD90: nop

    // 0x8009AD94: bltz        $a0, L_8009ADB4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009AD98: nop
    
            goto L_8009ADB4;
    }
    // 0x8009AD98: nop

    // 0x8009AD9C: lb          $a1, 0x1($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X1);
    // 0x8009ADA0: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8009ADA4: jal         0x8006E2E8
    // 0x8009ADA8: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009ADA8: nop

    after_2:
    // 0x8009ADAC: b           L_8009ADE4
    // 0x8009ADB0: nop

        goto L_8009ADE4;
    // 0x8009ADB0: nop

L_8009ADB4:
    // 0x8009ADB4: lw          $t1, 0x684C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X684C);
    // 0x8009ADB8: nop

    // 0x8009ADBC: beq         $t1, $zero, L_8009ADCC
    if (ctx->r9 == 0) {
        // 0x8009ADC0: nop
    
            goto L_8009ADCC;
    }
    // 0x8009ADC0: nop

    // 0x8009ADC4: jal         0x80000B18
    // 0x8009ADC8: nop

    music_change_off(rdram, ctx);
        goto after_3;
    // 0x8009ADC8: nop

    after_3:
L_8009ADCC:
    // 0x8009ADCC: jal         0x8009AF18
    // 0x8009ADD0: nop

    cinematic_free(rdram, ctx);
        goto after_4;
    // 0x8009ADD0: nop

    after_4:
    // 0x8009ADD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009ADD8: lw          $v0, 0x6824($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6824);
    // 0x8009ADDC: b           L_8009AEF4
    // 0x8009ADE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009AEF4;
    // 0x8009ADE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009ADE4:
    // 0x8009ADE4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009ADE8: addiu       $s0, $s0, 0x683C
    ctx->r16 = ADD32(ctx->r16, 0X683C);
    // 0x8009ADEC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009ADF0: andi        $t3, $s2, 0x9000
    ctx->r11 = ctx->r18 & 0X9000;
    // 0x8009ADF4: beq         $t2, $zero, L_8009AE18
    if (ctx->r10 == 0) {
        // 0x8009ADF8: nop
    
            goto L_8009AE18;
    }
    // 0x8009ADF8: nop

    // 0x8009ADFC: beq         $t3, $zero, L_8009AE18
    if (ctx->r11 == 0) {
        // 0x8009AE00: nop
    
            goto L_8009AE18;
    }
    // 0x8009AE00: nop

    // 0x8009AE04: jal         0x8009AF18
    // 0x8009AE08: nop

    cinematic_free(rdram, ctx);
        goto after_5;
    // 0x8009AE08: nop

    after_5:
    // 0x8009AE0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AE10: b           L_8009AEF4
    // 0x8009AE14: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009AEF4;
    // 0x8009AE14: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009AE18:
    // 0x8009AE18: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AE1C: addiu       $s0, $s0, 0x6844
    ctx->r16 = ADD32(ctx->r16, 0X6844);
    // 0x8009AE20: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8009AE24: nop

    // 0x8009AE28: beq         $t4, $zero, L_8009AE4C
    if (ctx->r12 == 0) {
        // 0x8009AE2C: andi        $t5, $s2, 0x4000
        ctx->r13 = ctx->r18 & 0X4000;
            goto L_8009AE4C;
    }
    // 0x8009AE2C: andi        $t5, $s2, 0x4000
    ctx->r13 = ctx->r18 & 0X4000;
    // 0x8009AE30: beq         $t5, $zero, L_8009AE4C
    if (ctx->r13 == 0) {
        // 0x8009AE34: nop
    
            goto L_8009AE4C;
    }
    // 0x8009AE34: nop

    // 0x8009AE38: jal         0x8009AF18
    // 0x8009AE3C: nop

    cinematic_free(rdram, ctx);
        goto after_6;
    // 0x8009AE3C: nop

    after_6:
    // 0x8009AE40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AE44: b           L_8009AEF4
    // 0x8009AE48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8009AEF4;
    // 0x8009AE48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009AE4C:
    // 0x8009AE4C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009AE50: addiu       $s3, $s3, 0x6804
    ctx->r19 = ADD32(ctx->r19, 0X6804);
    // 0x8009AE54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8009AE58: nop

    // 0x8009AE5C: beq         $v0, $zero, L_8009AEE4
    if (ctx->r2 == 0) {
        // 0x8009AE60: nop
    
            goto L_8009AEE4;
    }
    // 0x8009AE60: nop

    // 0x8009AE64: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009AE68: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8009AE6C: beq         $s4, $t6, L_8009AEE4
    if (ctx->r20 == ctx->r14) {
        // 0x8009AE70: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009AEE4;
    }
    // 0x8009AE70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009AE74: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009AE78: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8009AE7C: lb          $s1, 0x0($v0)
    ctx->r17 = MEM_B(ctx->r2, 0X0);
    // 0x8009AE80: addiu       $s5, $s5, 0x63A0
    ctx->r21 = ADD32(ctx->r21, 0X63A0);
    // 0x8009AE84: addiu       $s6, $s6, 0xAF0
    ctx->r22 = ADD32(ctx->r22, 0XAF0);
    // 0x8009AE88: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x8009AE8C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009AE90:
    // 0x8009AE90: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    { extern uint32_t dkr_legacy_character_cinematic_portrait(uint8_t*, recomp_context*, unsigned); uint32_t cell = dkr_legacy_character_cinematic_portrait(rdram, ctx, (unsigned)ctx->r17); if (cell) ctx->r24 = (int32_t)cell; }
    // 0x8009AE94: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8009AE98: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009AE9C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009AEA0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009AEA4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009AEA8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009AEAC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009AEB0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009AEB4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009AEB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8009AEBC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8009AEC0: jal         0x80078AB8
    // 0x8009AEC4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    texrect_draw(rdram, ctx);
        goto after_7;
    // 0x8009AEC4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_7:
    // 0x8009AEC8: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8009AECC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009AED0: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8009AED4: lb          $s1, 0x0($t4)
    ctx->r17 = MEM_B(ctx->r12, 0X0);
    // 0x8009AED8: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8009AEDC: bne         $s4, $s1, L_8009AE90
    if (ctx->r20 != ctx->r17) {
        // 0x8009AEE0: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8009AE90;
    }
    // 0x8009AEE0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
L_8009AEE4:
    // 0x8009AEE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AEE8: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8009AEEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009AEF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8009AEF4:
    // 0x8009AEF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009AEF8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8009AEFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8009AF00: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8009AF04: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8009AF08: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8009AF0C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8009AF10: jr          $ra
    // 0x8009AF14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009AF14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000A8D4: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x8000A8D8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8000A8DC: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8000A8E0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8000A8E4: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8000A8E8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000A8EC: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000A8F0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8000A8F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000A8F8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8000A8FC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8000A900: andi        $s0, $a2, 0xFF
    ctx->r16 = ctx->r6 & 0XFF;
    // 0x8000A904: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x8000A908: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A90C: blez        $t0, L_8000A9E8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000A910: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000A9E8;
    }
    // 0x8000A910: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000A914: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8000A918: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A91C:
    // 0x8000A91C: bgez        $a1, L_8000A92C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000A920: sra         $t4, $a1, 1
        ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8000A92C;
    }
    // 0x8000A920: sra         $t4, $a1, 1
    ctx->r12 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8000A924: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8000A928: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_8000A92C:
    // 0x8000A92C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000A930: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000A934: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x8000A938: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000A93C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8000A940: nop

    // 0x8000A944: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x8000A948: nop

    // 0x8000A94C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A950: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A954: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A954: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A958: lbu         $t7, 0x3($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A95C: nop

    // 0x8000A960: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A964: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A968: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A968: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A96C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000A974: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000A978: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A97C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A97C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A980: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x8000A984: nop

    // 0x8000A988: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000A98C: bne         $at, $zero, L_8000A9A0
    if (ctx->r1 != 0) {
        // 0x8000A990: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8000A9A0;
    }
    // 0x8000A990: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000A994: b           L_8000A9EC
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8000A9EC;
    // 0x8000A998: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000A99C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_8000A9A0:
    // 0x8000A9A0: bne         $at, $zero, L_8000A9D0
    if (ctx->r1 != 0) {
        // 0x8000A9A4: nop
    
            goto L_8000A9D0;
    }
    // 0x8000A9A4: nop

    // 0x8000A9A8: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8000A9AC: nop

    // 0x8000A9B0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000A9B4: beq         $at, $zero, L_8000A9D8
    if (ctx->r1 == 0) {
        // 0x8000A9B8: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9B8: nop

    // 0x8000A9BC: lbu         $t4, 0x3($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X3);
    // 0x8000A9C0: nop

    // 0x8000A9C4: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000A9C8: bne         $at, $zero, L_8000A9D8
    if (ctx->r1 != 0) {
        // 0x8000A9CC: nop
    
            goto L_8000A9D8;
    }
    // 0x8000A9CC: nop

L_8000A9D0:
    // 0x8000A9D0: b           L_8000A9DC
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_8000A9DC;
    // 0x8000A9D4: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
L_8000A9D8:
    // 0x8000A9D8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_8000A9DC:
    // 0x8000A9DC: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000A9E0: beq         $at, $zero, L_8000A91C
    if (ctx->r1 == 0) {
        // 0x8000A9E4: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_8000A91C;
    }
    // 0x8000A9E4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_8000A9E8:
    // 0x8000A9E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A9EC:
    // 0x8000A9EC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8000A9F0: jr          $ra
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000A9F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
