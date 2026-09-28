#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80072E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072E28: blez        $a0, L_80073064
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80072E2C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80073064;
    }
    // 0x80072E2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80072E30: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x80072E34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072E38: beq         $a0, $zero, L_80073044
    if (ctx->r4 == 0) {
        // 0x80072E3C: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_80073044;
    }
    // 0x80072E3C: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80072E40: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x80072E44: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80072E48: beq         $v1, $zero, L_80072ED0
    if (ctx->r3 == 0) {
        // 0x80072E4C: addu        $a3, $v1, $a0
        ctx->r7 = ADD32(ctx->r3, ctx->r4);
            goto L_80072ED0;
    }
    // 0x80072E4C: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x80072E50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072E54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072E58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072E5C: addiu       $t0, $t0, 0x41F4
    ctx->r8 = ADD32(ctx->r8, 0X41F4);
    // 0x80072E60: addiu       $t1, $t1, 0x41EC
    ctx->r9 = ADD32(ctx->r9, 0X41EC);
    // 0x80072E64: addiu       $t2, $t2, 0x41F0
    ctx->r10 = ADD32(ctx->r10, 0X41F0);
    // 0x80072E68: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_80072E6C:
    // 0x80072E6C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80072E70: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80072E74: bne         $a1, $zero, L_80072EA0
    if (ctx->r5 != 0) {
        // 0x80072E78: and         $t7, $a2, $v0
        ctx->r15 = ctx->r6 & ctx->r2;
            goto L_80072EA0;
    }
    // 0x80072E78: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x80072E7C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80072E80: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80072E84: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80072E88: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80072E8C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80072E90: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80072E94: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80072E98: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80072E9C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80072EA0:
    // 0x80072EA0: beq         $t7, $zero, L_80072EB8
    if (ctx->r15 == 0) {
        // 0x80072EA4: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_80072EB8;
    }
    // 0x80072EA4: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80072EA8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80072EAC: nop

    // 0x80072EB0: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80072EB4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80072EB8:
    // 0x80072EB8: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80072EBC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80072EC0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80072EC4: bne         $a3, $v1, L_80072E6C
    if (ctx->r7 != ctx->r3) {
        // 0x80072EC8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80072E6C;
    }
    // 0x80072EC8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80072ECC: beq         $v1, $zero, L_80073044
    if (ctx->r3 == 0) {
        // 0x80072ED0: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80073044;
    }
L_80072ED0:
    // 0x80072ED0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072ED4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072ED8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072EDC: addiu       $t2, $t2, 0x41F0
    ctx->r10 = ADD32(ctx->r10, 0X41F0);
    // 0x80072EE0: addiu       $t1, $t1, 0x41EC
    ctx->r9 = ADD32(ctx->r9, 0X41EC);
    // 0x80072EE4: addiu       $t0, $t0, 0x41F4
    ctx->r8 = ADD32(ctx->r8, 0X41F4);
    // 0x80072EE8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_80072EEC:
    // 0x80072EEC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80072EF0: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x80072EF4: bne         $a1, $zero, L_80072F20
    if (ctx->r5 != 0) {
        // 0x80072EF8: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80072F20;
    }
    // 0x80072EF8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80072EFC: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80072F00: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80072F04: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80072F08: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80072F0C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80072F10: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80072F14: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80072F18: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072F1C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_80072F20:
    // 0x80072F20: beq         $t9, $zero, L_80072F38
    if (ctx->r25 == 0) {
        // 0x80072F24: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80072F38;
    }
    // 0x80072F24: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80072F28: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80072F2C: nop

    // 0x80072F30: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x80072F34: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80072F38:
    // 0x80072F38: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x80072F3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072F40: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80072F44: bne         $t6, $zero, L_80072F70
    if (ctx->r14 != 0) {
        // 0x80072F48: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80072F70;
    }
    // 0x80072F48: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80072F4C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80072F50: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80072F54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80072F58: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80072F5C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80072F60: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80072F64: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80072F68: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80072F6C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80072F70:
    // 0x80072F70: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x80072F74: beq         $t7, $zero, L_80072F8C
    if (ctx->r15 == 0) {
        // 0x80072F78: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_80072F8C;
    }
    // 0x80072F78: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80072F7C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80072F80: nop

    // 0x80072F84: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80072F88: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80072F8C:
    // 0x80072F8C: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80072F90: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80072F94: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80072F98: bne         $t4, $zero, L_80072FC4
    if (ctx->r12 != 0) {
        // 0x80072F9C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80072FC4;
    }
    // 0x80072F9C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80072FA0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80072FA4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80072FA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80072FAC: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80072FB0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80072FB4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80072FB8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80072FBC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072FC0: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80072FC4:
    // 0x80072FC4: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x80072FC8: beq         $t9, $zero, L_80072FE0
    if (ctx->r25 == 0) {
        // 0x80072FCC: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80072FE0;
    }
    // 0x80072FCC: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80072FD0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80072FD4: nop

    // 0x80072FD8: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x80072FDC: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80072FE0:
    // 0x80072FE0: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x80072FE4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80072FE8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80072FEC: bne         $t6, $zero, L_80073018
    if (ctx->r14 != 0) {
        // 0x80072FF0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80073018;
    }
    // 0x80072FF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072FF4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80072FF8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80072FFC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073000: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80073004: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80073008: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8007300C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80073010: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80073014: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80073018:
    // 0x80073018: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x8007301C: beq         $t7, $zero, L_80073034
    if (ctx->r15 == 0) {
        // 0x80073020: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_80073034;
    }
    // 0x80073020: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80073024: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80073028: nop

    // 0x8007302C: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80073030: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80073034:
    // 0x80073034: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80073038: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8007303C: bne         $a0, $zero, L_80072EEC
    if (ctx->r4 != 0) {
        // 0x80073040: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80072EEC;
    }
    // 0x80073040: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80073044:
    // 0x80073044: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80073048: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007304C: addiu       $t2, $t2, 0x41F0
    ctx->r10 = ADD32(ctx->r10, 0X41F0);
    // 0x80073050: addiu       $t1, $t1, 0x41EC
    ctx->r9 = ADD32(ctx->r9, 0X41EC);
    // 0x80073054: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80073058: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8007305C: nop

    // 0x80073060: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
L_80073064:
    // 0x80073064: jr          $ra
    // 0x80073068: nop

    return;
    // 0x80073068: nop

;}
RECOMP_FUNC void menu_trophy_race_rankings_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098FD4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80098FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098FDC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80098FE0: jal         0x8006EA90
    // 0x80098FE4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098FE4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x80098FE8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098FEC: addiu       $a1, $a1, -0xB84
    ctx->r5 = ADD32(ctx->r5, -0XB84);
    // 0x80098FF0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80098FF4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80098FF8: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    // 0x80098FFC: bne         $at, $zero, L_80099020
    if (ctx->r1 != 0) {
        // 0x80099000: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80099020;
    }
    // 0x80099000: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80099004: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80099008: beq         $at, $zero, L_80099020
    if (ctx->r1 == 0) {
        // 0x8009900C: nop
    
            goto L_80099020;
    }
    // 0x8009900C: nop

    // 0x80099010: jal         0x80098EBC
    // 0x80099014: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    rankings_render_order(rdram, ctx);
        goto after_1;
    // 0x80099014: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80099018: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8009901C: nop

L_80099020:
    // 0x80099020: jal         0x8009BF20
    // 0x80099024: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x80099024: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_2:
    // 0x80099028: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009902C: lw          $v0, 0x63E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63E0);
    // 0x80099030: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80099034: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80099038: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8009903C: beq         $v0, $zero, L_8009906C
    if (ctx->r2 == 0) {
        // 0x80099040: addiu       $a1, $a1, -0xB84
        ctx->r5 = ADD32(ctx->r5, -0XB84);
            goto L_8009906C;
    }
    // 0x80099040: addiu       $a1, $a1, -0xB84
    ctx->r5 = ADD32(ctx->r5, -0XB84);
    // 0x80099044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099048: beq         $v0, $at, L_800990B8
    if (ctx->r2 == ctx->r1) {
        // 0x8009904C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800990B8;
    }
    // 0x8009904C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80099050: beq         $v0, $at, L_800990EC
    if (ctx->r2 == ctx->r1) {
        // 0x80099054: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800990EC;
    }
    // 0x80099054: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099058: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009905C: beq         $v0, $at, L_80099324
    if (ctx->r2 == ctx->r1) {
        // 0x80099060: nop
    
            goto L_80099324;
    }
    // 0x80099060: nop

    // 0x80099064: b           L_800995EC
    // 0x80099068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800995EC;
    // 0x80099068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009906C:
    // 0x8009906C: jal         0x80081F4C
    // 0x80099070: nop

    postrace_render(rdram, ctx);
        goto after_3;
    // 0x80099070: nop

    after_3:
    // 0x80099074: beq         $v0, $zero, L_800995E8
    if (ctx->r2 == 0) {
        // 0x80099078: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800995E8;
    }
    // 0x80099078: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009907C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099080: sw          $t6, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r14;
    // 0x80099084: jal         0x80098774
    // 0x80099088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80098774(rdram, ctx);
        goto after_4;
    // 0x80099088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8009908C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80099090: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80099094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80099098: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009909C: addiu       $a0, $a0, 0x1048
    ctx->r4 = ADD32(ctx->r4, 0X1048);
    // 0x800990A0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x800990A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800990A8: jal         0x80081E54
    // 0x800990AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    postrace_offsets(rdram, ctx);
        goto after_5;
    // 0x800990AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x800990B0: b           L_800995EC
    // 0x800990B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800995EC;
    // 0x800990B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800990B8:
    // 0x800990B8: jal         0x80081F4C
    // 0x800990BC: nop

    postrace_render(rdram, ctx);
        goto after_6;
    // 0x800990BC: nop

    after_6:
    // 0x800990C0: beq         $v0, $zero, L_800995E8
    if (ctx->r2 == 0) {
        // 0x800990C4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800995E8;
    }
    // 0x800990C4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800990C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800990CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800990D0: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
    // 0x800990D4: addiu       $a1, $a1, 0x1048
    ctx->r5 = ADD32(ctx->r5, 0X1048);
    // 0x800990D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800990DC: jal         0x800821EC
    // 0x800990E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_7;
    // 0x800990E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x800990E4: b           L_800995EC
    // 0x800990E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800995EC;
    // 0x800990E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800990EC:
    // 0x800990EC: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x800990F0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800990F4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800990F8: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800990FC: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x80099100: bne         $at, $zero, L_8009919C
    if (ctx->r1 != 0) {
        // 0x80099104: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_8009919C;
    }
    // 0x80099104: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80099108: addiu       $t5, $t9, -0xA
    ctx->r13 = ADD32(ctx->r25, -0XA);
    // 0x8009910C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80099110: lw          $a3, 0xFE4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XFE4);
    // 0x80099114: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099118: blez        $a3, L_80099180
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8009911C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80099180;
    }
    // 0x8009911C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80099120: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099124: addiu       $v1, $v1, 0x63F8
    ctx->r3 = ADD32(ctx->r3, 0X63F8);
    // 0x80099128: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
L_8009912C:
    // 0x8009912C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80099130: nop

    // 0x80099134: blez        $a0, L_80099170
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80099138: nop
    
            goto L_80099170;
    }
    // 0x80099138: nop

    // 0x8009913C: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099140: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80099144: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80099148: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009914C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80099150: mflo        $t7
    ctx->r15 = lo;
    // 0x80099154: addu        $v0, $t3, $t7
    ctx->r2 = ADD32(ctx->r11, ctx->r15);
    // 0x80099158: lw          $t8, 0x54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X54);
    // 0x8009915C: nop

    // 0x80099160: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80099164: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
    // 0x80099168: lw          $a3, 0xFE4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XFE4);
    // 0x8009916C: nop

L_80099170:
    // 0x80099170: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099174: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80099178: bne         $at, $zero, L_8009912C
    if (ctx->r1 != 0) {
        // 0x8009917C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8009912C;
    }
    // 0x8009917C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80099180:
    // 0x80099180: beq         $t0, $zero, L_8009919C
    if (ctx->r8 == 0) {
        // 0x80099184: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_8009919C;
    }
    // 0x80099184: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x80099188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009918C: jal         0x80001D04
    // 0x80099190: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x80099190: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_8:
    // 0x80099194: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099198: nop

L_8009919C:
    // 0x8009919C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800991A0: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x800991A4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800991A8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800991AC: lw          $t5, -0xB44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB44);
    // 0x800991B0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800991B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800991B8: blez        $t5, L_80099248
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800991BC: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80099248;
    }
    // 0x800991BC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800991C0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800991C4: addiu       $a3, $a3, 0x6464
    ctx->r7 = ADD32(ctx->r7, 0X6464);
L_800991C8:
    // 0x800991C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800991CC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800991D0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800991D4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800991D8: jal         0x8006A554
    // 0x800991DC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    input_pressed(rdram, ctx);
        goto after_9;
    // 0x800991DC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_9:
    // 0x800991E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800991E4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800991E8: lb          $v1, 0x0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X0);
    // 0x800991EC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800991F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800991F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800991F8: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x800991FC: bgez        $v1, L_80099214
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80099200: or          $t0, $t0, $v0
        ctx->r8 = ctx->r8 | ctx->r2;
            goto L_80099214;
    }
    // 0x80099200: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
    // 0x80099204: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80099208: nop

    // 0x8009920C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80099210: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80099214:
    // 0x80099214: blez        $v1, L_8009922C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80099218: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8009922C;
    }
    // 0x80099218: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009921C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80099220: nop

    // 0x80099224: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80099228: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_8009922C:
    // 0x8009922C: lw          $t5, -0xB44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB44);
    // 0x80099230: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099234: slt         $at, $a1, $t5
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80099238: bne         $at, $zero, L_800991C8
    if (ctx->r1 != 0) {
        // 0x8009923C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800991C8;
    }
    // 0x8009923C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80099240: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80099244: nop

L_80099248:
    // 0x80099248: bgez        $v0, L_80099258
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009924C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80099258;
    }
    // 0x8009924C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099250: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80099254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099258:
    // 0x80099258: lw          $v1, 0x6C14($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6C14);
    // 0x8009925C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80099260: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80099264: bne         $at, $zero, L_80099274
    if (ctx->r1 != 0) {
        // 0x80099268: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80099274;
    }
    // 0x80099268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009926C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80099270: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80099274:
    // 0x80099274: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80099278: nop

    // 0x8009927C: beq         $t7, $v0, L_800992A0
    if (ctx->r15 == ctx->r2) {
        // 0x80099280: andi        $t8, $t0, 0x9000
        ctx->r24 = ctx->r8 & 0X9000;
            goto L_800992A0;
    }
    // 0x80099280: andi        $t8, $t0, 0x9000
    ctx->r24 = ctx->r8 & 0X9000;
    // 0x80099284: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80099288: jal         0x80001D04
    // 0x8009928C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8009928C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_10:
    // 0x80099290: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80099294: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099298: nop

    // 0x8009929C: andi        $t8, $t0, 0x9000
    ctx->r24 = ctx->r8 & 0X9000;
L_800992A0:
    // 0x800992A0: beq         $t8, $zero, L_800995E8
    if (ctx->r24 == 0) {
        // 0x800992A4: addiu       $a0, $zero, -0x80
        ctx->r4 = ADD32(0, -0X80);
            goto L_800995E8;
    }
    // 0x800992A4: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    // 0x800992A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800992AC: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800992B0: jal         0x80000C98
    // 0x800992B4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    music_fade(rdram, ctx);
        goto after_11;
    // 0x800992B4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_11:
    // 0x800992B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800992BC: jal         0x800C01D8
    // 0x800992C0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x800992C0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_12:
    // 0x800992C4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800992C8: lw          $t5, 0xFE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XFE4);
    // 0x800992CC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800992D0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800992D4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800992D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800992DC: blez        $t5, L_800995E8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800992E0: sw          $t9, 0x63E0($at)
        MEM_W(0X63E0, ctx->r1) = ctx->r25;
            goto L_800995E8;
    }
    // 0x800992E0: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
    // 0x800992E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800992E8: addiu       $v1, $v1, 0x63F8
    ctx->r3 = ADD32(ctx->r3, 0X63F8);
    // 0x800992EC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800992F0:
    // 0x800992F0: lw          $t6, 0x54($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X54);
    // 0x800992F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800992F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800992FC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80099300: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x80099304: lw          $t9, 0xFE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XFE4);
    // 0x80099308: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009930C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80099310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80099314: bne         $at, $zero, L_800992F0
    if (ctx->r1 != 0) {
        // 0x80099318: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800992F0;
    }
    // 0x80099318: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8009931C: b           L_800995EC
    // 0x80099320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800995EC;
    // 0x80099320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099324:
    // 0x80099324: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80099328: nop

    // 0x8009932C: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80099330: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80099334: bne         $at, $zero, L_800995E8
    if (ctx->r1 != 0) {
        // 0x80099338: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_800995E8;
    }
    // 0x80099338: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8009933C: jal         0x80099600
    // 0x80099340: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    rankings_free(rdram, ctx);
        goto after_13;
    // 0x80099340: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_13:
    // 0x80099344: jal         0x800C5620
    // 0x80099348: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_14;
    // 0x80099348: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x8009934C: jal         0x800C5494
    // 0x80099350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_15;
    // 0x80099350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_15:
    // 0x80099354: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80099358: lw          $t8, 0xFEC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XFEC);
    // 0x8009935C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099360: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80099364: beq         $at, $zero, L_8009937C
    if (ctx->r1 == 0) {
        // 0x80099368: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_8009937C;
    }
    // 0x80099368: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009936C: jal         0x800813D0
    // 0x80099370: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x80099370: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_16:
    // 0x80099374: b           L_800995EC
    // 0x80099378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800995EC;
    // 0x80099378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009937C:
    // 0x8009937C: lw          $a3, 0xFE4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XFE4);
    // 0x80099380: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80099384: blez        $a3, L_80099434
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80099388: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80099434;
    }
    // 0x80099388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009938C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099390: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099394: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80099398: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8009939C: addiu       $t0, $t0, 0x6430
    ctx->r8 = ADD32(ctx->r8, 0X6430);
    // 0x800993A0: addiu       $t2, $t2, 0x6438
    ctx->r10 = ADD32(ctx->r10, 0X6438);
    // 0x800993A4: addiu       $a2, $a2, 0x6420
    ctx->r6 = ADD32(ctx->r6, 0X6420);
    // 0x800993A8: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
L_800993AC:
    // 0x800993AC: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800993B0: addu        $t5, $t0, $a1
    ctx->r13 = ADD32(ctx->r8, ctx->r5);
    // 0x800993B4: beq         $t9, $zero, L_80099420
    if (ctx->r25 == 0) {
        // 0x800993B8: nop
    
            goto L_80099420;
    }
    // 0x800993B8: nop

    // 0x800993BC: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800993C0: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x800993C4: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800993C8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800993CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800993D0: addu        $a0, $t3, $t7
    ctx->r4 = ADD32(ctx->r11, ctx->r15);
    // 0x800993D4: lb          $v0, 0x59($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X59);
    { extern unsigned dkr_legacy_character_cinematic_id(uint8_t*, recomp_context*, unsigned, unsigned); ctx->r2 = dkr_legacy_character_cinematic_id(rdram, ctx, (unsigned)ctx->r14, (unsigned)ctx->r2); }
    // 0x800993D8: bne         $v1, $zero, L_800993F0
    if (ctx->r3 != 0) {
        // 0x800993DC: nop
    
            goto L_800993F0;
    }
    // 0x800993DC: nop

    // 0x800993E0: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x800993E4: sb          $v0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r2;
    // 0x800993E8: b           L_80099420
    // 0x800993EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80099420;
    // 0x800993EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800993F0:
    // 0x800993F0: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800993F4: lw          $t9, 0x54($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X54);
    // 0x800993F8: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800993FC: addu        $t6, $t2, $v1
    ctx->r14 = ADD32(ctx->r10, ctx->r3);
    // 0x80099400: mflo        $t7
    ctx->r15 = lo;
    // 0x80099404: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80099408: lw          $t5, 0x54($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X54);
    // 0x8009940C: nop

    // 0x80099410: bne         $t9, $t5, L_80099420
    if (ctx->r25 != ctx->r13) {
        // 0x80099414: nop
    
            goto L_80099420;
    }
    // 0x80099414: nop

    // 0x80099418: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x8009941C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80099420:
    // 0x80099420: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099424: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80099428: bne         $at, $zero, L_800993AC
    if (ctx->r1 != 0) {
        // 0x8009942C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800993AC;
    }
    // 0x8009942C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80099430: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80099434:
    // 0x80099434: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80099438: lw          $t7, -0xB44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB44);
    // 0x8009943C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099440: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099448: bne         $t7, $at, L_8009947C
    if (ctx->r15 != ctx->r1) {
        // 0x8009944C: addiu       $t2, $t2, 0x6438
        ctx->r10 = ADD32(ctx->r10, 0X6438);
            goto L_8009947C;
    }
    // 0x8009944C: addiu       $t2, $t2, 0x6438
    ctx->r10 = ADD32(ctx->r10, 0X6438);
    // 0x80099450: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80099454: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80099458: jal         0x8009EC80
    // 0x8009945C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    is_in_two_player_adventure(rdram, ctx);
        goto after_17;
    // 0x8009945C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_17:
    // 0x80099460: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80099464: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099468: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8009946C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099470: bne         $v0, $zero, L_8009947C
    if (ctx->r2 != 0) {
        // 0x80099474: addiu       $t2, $t2, 0x6438
        ctx->r10 = ADD32(ctx->r10, 0X6438);
            goto L_8009947C;
    }
    // 0x80099474: addiu       $t2, $t2, 0x6438
    ctx->r10 = ADD32(ctx->r10, 0X6438);
    // 0x80099478: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009947C:
    // 0x8009947C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80099480: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x80099484: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80099488: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009948C: lw          $t5, -0xB48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB48);
    // 0x80099490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099494: bne         $t5, $at, L_800994C8
    if (ctx->r13 != ctx->r1) {
        // 0x80099498: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800994C8;
    }
    // 0x80099498: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009949C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800994A0: bne         $at, $zero, L_800994C0
    if (ctx->r1 != 0) {
        // 0x800994A4: addiu       $t6, $zero, 0x105
        ctx->r14 = ADD32(0, 0X105);
            goto L_800994C0;
    }
    // 0x800994A4: addiu       $t6, $zero, 0x105
    ctx->r14 = ADD32(0, 0X105);
    // 0x800994A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800994AC: jal         0x800813D0
    // 0x800994B0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    menu_init(rdram, ctx);
        goto after_18;
    // 0x800994B0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_18:
    // 0x800994B4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800994B8: b           L_80099588
    // 0x800994BC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
        goto L_80099588;
    // 0x800994BC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
L_800994C0:
    // 0x800994C0: b           L_80099584
    // 0x800994C4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_80099584;
    // 0x800994C4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_800994C8:
    // 0x800994C8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800994CC: lbu         $a0, 0x48($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X48);
    // 0x800994D0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800994D4: jal         0x8006B1D4
    // 0x800994D8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    level_world_id(rdram, ctx);
        goto after_19;
    // 0x800994D8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_19:
    // 0x800994DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800994E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800994E4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800994E8: addiu       $v1, $v1, -0xBB0
    ctx->r3 = ADD32(ctx->r3, -0XBB0);
    // 0x800994EC: sb          $v0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r2;
    // 0x800994F0: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x800994F4: nop

    // 0x800994F8: beq         $t8, $zero, L_80099588
    if (ctx->r24 == 0) {
        // 0x800994FC: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_80099588;
    }
    // 0x800994FC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80099500: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80099504: lbu         $t9, 0x49($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X49);
    // 0x80099508: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8009950C: ori         $t5, $t9, 0x200
    ctx->r13 = ctx->r25 | 0X200;
    // 0x80099510: beq         $at, $zero, L_80099584
    if (ctx->r1 == 0) {
        // 0x80099514: sw          $t5, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r13;
            goto L_80099584;
    }
    // 0x80099514: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80099518: lbu         $a1, 0x48($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X48);
    // 0x8009951C: lhu         $a0, 0xE($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0XE);
    // 0x80099520: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80099524: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80099528: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009952C: subu        $v0, $t8, $t4
    ctx->r2 = SUB32(ctx->r24, ctx->r12);
    // 0x80099530: srav        $v1, $a0, $t6
    ctx->r3 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x80099534: andi        $t7, $v1, 0x3
    ctx->r15 = ctx->r3 & 0X3;
    // 0x80099538: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8009953C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80099540: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80099544: beq         $at, $zero, L_80099584
    if (ctx->r1 == 0) {
        // 0x80099548: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80099584;
    }
    // 0x80099548: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009954C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80099550: sllv        $t6, $t5, $t6
    ctx->r14 = S32(ctx->r13 << (ctx->r14 & 31));
    // 0x80099554: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x80099558: and         $t9, $a0, $t7
    ctx->r25 = ctx->r4 & ctx->r15;
    // 0x8009955C: sllv        $t5, $v0, $a1
    ctx->r13 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x80099560: sh          $t9, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r25;
    // 0x80099564: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80099568: sh          $t6, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r14;
    // 0x8009956C: jal         0x8009C1A0
    // 0x80099570: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    get_save_file_index(rdram, ctx);
        goto after_20;
    // 0x80099570: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_20:
    // 0x80099574: jal         0x8006EC48
    // 0x80099578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_21;
    // 0x80099578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x8009957C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099580: nop

L_80099584:
    // 0x80099584: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
L_80099588:
    // 0x80099588: beq         $at, $zero, L_800995E0
    if (ctx->r1 == 0) {
        // 0x8009958C: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_800995E0;
    }
    // 0x8009958C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80099590: jal         0x8001E29C
    // 0x80099594: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    get_misc_asset(rdram, ctx);
        goto after_22;
    // 0x80099594: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_22:
    // 0x80099598: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009959C: lw          $t7, 0xFE8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XFE8);
    // 0x800995A0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800995A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800995A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800995AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800995B0: addiu       $t2, $t2, 0x6438
    ctx->r10 = ADD32(ctx->r10, 0X6438);
    // 0x800995B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800995B8: addu        $a1, $t8, $t4
    ctx->r5 = ADD32(ctx->r24, ctx->r12);
    // 0x800995BC: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800995C0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800995C4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800995C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800995CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800995D0: jal         0x8009ABD8
    // 0x800995D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_23;
    // 0x800995D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x800995D8: jal         0x800813D0
    // 0x800995DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    menu_init(rdram, ctx);
        goto after_24;
    // 0x800995DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_24:
L_800995E0:
    // 0x800995E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800995E4: sw          $zero, 0xFE8($at)
    MEM_W(0XFE8, ctx->r1) = 0;
L_800995E8:
    // 0x800995E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800995EC:
    // 0x800995EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800995F0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800995F4: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x800995F8: jr          $ra
    // 0x800995FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800995FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void void_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002581C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80025820: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025824: lw          $t6, -0x2B8C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B8C);
    // 0x80025828: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002582C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80025830: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80025834: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80025838: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8002583C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80025840: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80025844: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80025848: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002584C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80025850: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80025854: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80025858: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002585C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80025860: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80025864: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80025868: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x8002586C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80025870: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80025874: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80025878: addiu       $v1, $v1, -0x2B70
    ctx->r3 = ADD32(ctx->r3, -0X2B70);
    // 0x8002587C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80025880: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80025884: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025888: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8002588C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80025890: addiu       $t0, $t0, -0x2B80
    ctx->r8 = ADD32(ctx->r8, -0X2B80);
    // 0x80025894: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80025898: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8002589C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800258A0: addiu       $a0, $a0, -0x4F60
    ctx->r4 = ADD32(ctx->r4, -0X4F60);
    // 0x800258A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800258A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800258AC: jal         0x8007B4C8
    // 0x800258B0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800258B0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    after_0:
    // 0x800258B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800258B8: sh          $zero, -0x2B64($at)
    MEM_H(-0X2B64, ctx->r1) = 0;
    // 0x800258BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800258C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800258C4: addiu       $s0, $s0, -0x4F50
    ctx->r16 = ADD32(ctx->r16, -0X4F50);
    // 0x800258C8: sh          $zero, -0x2B62($at)
    MEM_H(-0X2B62, ctx->r1) = 0;
    // 0x800258CC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800258D0: nop

    // 0x800258D4: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x800258D8: nop

    // 0x800258DC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800258E0: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800258E4: jal         0x800707C4
    // 0x800258E8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800258E8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x800258EC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800258F0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800258F4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x800258F8: nop

    // 0x800258FC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80025900: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80025904: jal         0x800707F8
    // 0x80025908: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80025908: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_2:
    // 0x8002590C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025910: lwc1        $f15, 0x5E60($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X5E60);
    // 0x80025914: lwc1        $f14, 0x5E64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5E64);
    // 0x80025918: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x8002591C: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80025920: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025924: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80025928: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002592C: addiu       $v1, $v1, -0x2B54
    ctx->r3 = ADD32(ctx->r3, -0X2B54);
    // 0x80025930: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025934: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x80025938: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002593C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80025940: addiu       $a0, $a0, -0x2B50
    ctx->r4 = ADD32(ctx->r4, -0X2B50);
    // 0x80025944: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80025948: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8002594C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80025950: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80025954: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80025958: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002595C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80025960: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80025964: addiu       $a1, $a1, -0x2B60
    ctx->r5 = ADD32(ctx->r5, -0X2B60);
    // 0x80025968: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002596C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025970: mul.s       $f4, $f26, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x80025974: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80025978: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002597C: addiu       $a2, $a2, -0x2B5C
    ctx->r6 = ADD32(ctx->r6, -0X2B5C);
    // 0x80025980: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80025984: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80025988: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8002598C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80025990: swc1        $f26, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f26.u32l;
    // 0x80025994: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80025998: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8002599C: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800259A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800259A4: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800259A8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800259AC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800259B0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800259B4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x800259B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800259BC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800259C0: addiu       $s4, $s4, -0x36E8
    ctx->r20 = ADD32(ctx->r20, -0X36E8);
    // 0x800259C4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800259C8: blez        $t2, L_80025B70
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800259CC: swc1        $f8, -0x2B58($at)
        MEM_W(-0X2B58, ctx->r1) = ctx->f8.u32l;
            goto L_80025B70;
    }
    // 0x800259CC: swc1        $f8, -0x2B58($at)
    MEM_W(-0X2B58, ctx->r1) = ctx->f8.u32l;
    // 0x800259D0: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x800259D4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800259D8: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x800259DC: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_800259E0:
    // 0x800259E0: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800259E4: addu        $s1, $s2, $t3
    ctx->r17 = ADD32(ctx->r18, ctx->r11);
    // 0x800259E8: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800259EC: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800259F0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800259F4: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800259F8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800259FC: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80025A00: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80025A04: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80025A08: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025A0C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80025A10: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025A18: mul.s       $f0, $f18, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80025A1C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025A20: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80025A24: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80025A28: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80025A2C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80025A30: c.le.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d <= ctx->f20.d;
    // 0x80025A34: nop

    // 0x80025A38: bc1f        L_80025A44
    if (!c1cs) {
        // 0x80025A3C: nop
    
            goto L_80025A44;
    }
    // 0x80025A3C: nop

    // 0x80025A40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025A44:
    // 0x80025A44: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80025A48: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025A4C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80025A50: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025A54: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80025A58: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80025A5C: mul.s       $f12, $f26, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80025A60: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80025A64: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80025A68: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80025A6C: c.le.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d <= ctx->f20.d;
    // 0x80025A70: nop

    // 0x80025A74: bc1f        L_80025A80
    if (!c1cs) {
        // 0x80025A78: nop
    
            goto L_80025A80;
    }
    // 0x80025A78: nop

    // 0x80025A7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80025A80:
    // 0x80025A80: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80025A84: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80025A88: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025A8C: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80025A90: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025A94: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025A98: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80025A9C: mul.s       $f14, $f24, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x80025AA0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80025AA4: add.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80025AA8: add.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80025AAC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025AB0: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80025AB4: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80025AB8: bc1f        L_80025AC4
    if (!c1cs) {
        // 0x80025ABC: add.s       $f10, $f8, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
            goto L_80025AC4;
    }
    // 0x80025ABC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80025AC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80025AC4:
    // 0x80025AC4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80025AC8: c.le.d      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.d <= ctx->f20.d;
    // 0x80025ACC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80025AD0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025AD4: bc1f        L_80025AE0
    if (!c1cs) {
        // 0x80025AD8: sra         $a2, $t8, 16
        ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80025AE0;
    }
    // 0x80025AD8: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025ADC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80025AE0:
    // 0x80025AE0: addu        $t4, $a2, $t2
    ctx->r12 = ADD32(ctx->r6, ctx->r10);
    // 0x80025AE4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80025AE8: beq         $t5, $zero, L_80025B54
    if (ctx->r13 == 0) {
        // 0x80025AEC: nop
    
            goto L_80025B54;
    }
    // 0x80025AEC: nop

    // 0x80025AF0: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025AF4: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80025AF8: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025AFC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B00: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B04: mflo        $t6
    ctx->r14 = lo;
    // 0x80025B08: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80025B0C: jal         0x80026430
    // 0x80025B10: nop

    func_80026430(rdram, ctx);
        goto after_3;
    // 0x80025B10: nop

    after_3:
    // 0x80025B14: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80025B18: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025B1C: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025B20: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80025B24: mflo        $t3
    ctx->r11 = lo;
    // 0x80025B28: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80025B2C: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80025B30: nop

    // 0x80025B34: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80025B38: beq         $t6, $zero, L_80025B54
    if (ctx->r14 == 0) {
        // 0x80025B3C: nop
    
            goto L_80025B54;
    }
    // 0x80025B3C: nop

    // 0x80025B40: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025B44: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B48: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B4C: jal         0x80026070
    // 0x80025B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80026070(rdram, ctx);
        goto after_4;
    // 0x80025B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80025B54:
    // 0x80025B54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025B58: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x80025B5C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80025B60: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80025B64: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80025B68: bne         $at, $zero, L_800259E0
    if (ctx->r1 != 0) {
        // 0x80025B6C: lw          $t3, 0xC0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC0);
            goto L_800259E0;
    }
    // 0x80025B6C: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_80025B70:
    // 0x80025B70: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80025B74: addiu       $s4, $s4, -0x36E8
    ctx->r20 = ADD32(ctx->r20, -0X36E8);
    // 0x80025B78: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80025B7C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025B80: lh          $a1, 0x40($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X40);
    // 0x80025B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025B88: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025B8C: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80025B90: jal         0x80026C14
    // 0x80025B94: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    func_80026C14(rdram, ctx);
        goto after_5;
    // 0x80025B94: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    after_5:
    // 0x80025B98: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80025B9C: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025BA0: lh          $a1, 0x40($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X40);
    // 0x80025BA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025BA8: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025BAC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80025BB0: jal         0x80026C14
    // 0x80025BB4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_6;
    // 0x80025BB4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_6:
    // 0x80025BB8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025BBC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025BC0: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x80025BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025BC8: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025BCC: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80025BD0: jal         0x80026C14
    // 0x80025BD4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_80026C14(rdram, ctx);
        goto after_7;
    // 0x80025BD4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_7:
    // 0x80025BD8: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80025BDC: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025BE0: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80025BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025BE8: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025BEC: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80025BF0: jal         0x80026C14
    // 0x80025BF4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_80026C14(rdram, ctx);
        goto after_8;
    // 0x80025BF4: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_8:
    // 0x80025BF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80025BFC: addiu       $t1, $t1, -0x2B62
    ctx->r9 = ADD32(ctx->r9, -0X2B62);
    // 0x80025C00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025C04: lh          $t6, -0x2B46($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2B46);
    // 0x80025C08: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025C0C: nop

    // 0x80025C10: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80025C14: beq         $at, $zero, L_80026034
    if (ctx->r1 == 0) {
        // 0x80025C18: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80026034;
    }
    // 0x80025C18: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80025C1C: beq         $a3, $zero, L_80026030
    if (ctx->r7 == 0) {
        // 0x80025C20: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80026030;
    }
    // 0x80025C20: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80025C24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025C28: addiu       $t0, $t0, -0x2B88
    ctx->r8 = ADD32(ctx->r8, -0X2B88);
    // 0x80025C2C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025C30:
    // 0x80025C30: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025C34: blez        $a1, L_80025CA0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80025C38: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80025CA0;
    }
    // 0x80025C38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025C3C:
    // 0x80025C3C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025C40: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025C44: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025C48: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
    // 0x80025C4C: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80025C50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025C54: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80025C58: beq         $at, $zero, L_80025C8C
    if (ctx->r1 == 0) {
        // 0x80025C5C: sll         $t5, $s2, 16
        ctx->r13 = S32(ctx->r18 << 16);
            goto L_80025C8C;
    }
    // 0x80025C5C: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x80025C60: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80025C64: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80025C68: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80025C6C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80025C70: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80025C74: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80025C78: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80025C7C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025C80: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025C88: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025C8C:
    // 0x80025C8C: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80025C90: slt         $at, $s2, $a1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80025C94: bne         $at, $zero, L_80025C3C
    if (ctx->r1 != 0) {
        // 0x80025C98: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80025C3C;
    }
    // 0x80025C98: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025C9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025CA0:
    // 0x80025CA0: beq         $a2, $zero, L_80025C30
    if (ctx->r6 == 0) {
        // 0x80025CA4: nop
    
            goto L_80025C30;
    }
    // 0x80025CA4: nop

    // 0x80025CA8: blez        $a3, L_80025D34
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025CAC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80025D34;
    }
    // 0x80025CAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80025CB0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025CB4: addiu       $a1, $a1, -0x2B84
    ctx->r5 = ADD32(ctx->r5, -0X2B84);
    // 0x80025CB8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80025CBC:
    // 0x80025CBC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025CC0: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025CC4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025CC8: lb          $t2, 0x7($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X7);
    // 0x80025CCC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80025CD0: sll         $t9, $t2, 17
    ctx->r25 = S32(ctx->r10 << 17);
    // 0x80025CD4: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025CD8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80025CDC: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x80025CE0: nop

    // 0x80025CE4: bne         $a2, $t5, L_80025D10
    if (ctx->r6 != ctx->r13) {
        // 0x80025CE8: nop
    
            goto L_80025D10;
    }
    // 0x80025CE8: nop

    // 0x80025CEC: lb          $t6, 0x6($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6);
    // 0x80025CF0: nop

    // 0x80025CF4: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80025CF8: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x80025CFC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80025D00: nop

    // 0x80025D04: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x80025D08: b           L_80025D14
    // 0x80025D0C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
        goto L_80025D14;
    // 0x80025D0C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
L_80025D10:
    // 0x80025D10: sb          $s2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r18;
L_80025D14:
    // 0x80025D14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025D18: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025D1C: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x80025D20: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025D24: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025D28: bne         $at, $zero, L_80025CBC
    if (ctx->r1 != 0) {
        // 0x80025D2C: nop
    
            goto L_80025CBC;
    }
    // 0x80025D2C: nop

    // 0x80025D30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025D34:
    // 0x80025D34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80025D38: addiu       $a0, $a0, -0x2B4C
    ctx->r4 = ADD32(ctx->r4, -0X2B4C);
    // 0x80025D3C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025D40: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025D44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80025D48: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80025D4C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80025D50: lw          $t8, -0x2B80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B80);
    // 0x80025D54: lh          $s3, 0x0($t4)
    ctx->r19 = MEM_H(ctx->r12, 0X0);
    // 0x80025D58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025D5C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025D60: lw          $t6, -0x4F58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F58);
    // 0x80025D64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025D68: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80025D6C: lw          $t2, -0x2B70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B70);
    // 0x80025D70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80025D74: sw          $t8, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r24;
    // 0x80025D78: lw          $t7, -0x4F54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F54);
    // 0x80025D7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025D80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025D84: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x80025D88: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025D8C: sw          $t2, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = ctx->r10;
    // 0x80025D90: sra         $t5, $s4, 16
    ctx->r13 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025D94: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80025D98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025D9C: lw          $t4, -0x4F58($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F58);
    // 0x80025DA0: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x80025DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80025DAC: lw          $t5, -0x4F54($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F54);
    // 0x80025DB0: sw          $t4, -0x2B78($at)
    MEM_W(-0X2B78, ctx->r1) = ctx->r12;
    // 0x80025DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DB8: sw          $t5, -0x2B68($at)
    MEM_W(-0X2B68, ctx->r1) = ctx->r13;
    // 0x80025DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DC0: sh          $zero, -0x2B4A($at)
    MEM_H(-0X2B4A, ctx->r1) = 0;
    // 0x80025DC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DC8: sh          $zero, -0x2B48($at)
    MEM_H(-0X2B48, ctx->r1) = 0;
    // 0x80025DCC: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80025DD0: blez        $a3, L_80025F44
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025DD4: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_80025F44;
    }
    // 0x80025DD4: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80025DD8: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x80025DDC: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025DE0:
    // 0x80025DE0: beq         $at, $zero, L_80025ECC
    if (ctx->r1 == 0) {
        // 0x80025DE4: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025ECC;
    }
    // 0x80025DE4: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025DE8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80025DEC: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x80025DF0: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80025DF4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80025DF8: nop

    // 0x80025DFC: bne         $s4, $t7, L_80025ECC
    if (ctx->r20 != ctx->r15) {
        // 0x80025E00: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025ECC;
    }
    // 0x80025E00: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025E04:
    // 0x80025E04: lb          $t8, 0x6($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X6);
    // 0x80025E08: addu        $t3, $s1, $s0
    ctx->r11 = ADD32(ctx->r17, ctx->r16);
    // 0x80025E0C: andi        $t2, $t8, 0x2
    ctx->r10 = ctx->r24 & 0X2;
    // 0x80025E10: beq         $t2, $zero, L_80025E30
    if (ctx->r10 == 0) {
        // 0x80025E14: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80025E30;
    }
    // 0x80025E14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025E18: lb          $t9, 0x7($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X7);
    // 0x80025E1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80025E20: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80025E24: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025E28: b           L_80025E9C
    // 0x80025E2C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
        goto L_80025E9C;
    // 0x80025E2C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
L_80025E30:
    // 0x80025E30: blez        $s0, L_80025E9C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025E34: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80025E9C;
    }
    // 0x80025E34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80025E38: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025E3C:
    // 0x80025E3C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80025E40: lb          $t8, 0x7($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X7);
    // 0x80025E44: nop

    // 0x80025E48: bne         $t7, $t8, L_80025E84
    if (ctx->r15 != ctx->r24) {
        // 0x80025E4C: nop
    
            goto L_80025E84;
    }
    // 0x80025E4C: nop

    // 0x80025E50: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80025E54: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80025E58: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80025E5C: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025E60: beq         $at, $zero, L_80025E84
    if (ctx->r1 == 0) {
        // 0x80025E64: addu        $v0, $s1, $v1
        ctx->r2 = ADD32(ctx->r17, ctx->r3);
            goto L_80025E84;
    }
L_80025E64:
    // 0x80025E64: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x80025E68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025E6C: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80025E70: lb          $t3, 0x1($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1);
    // 0x80025E74: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025E78: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025E7C: bne         $at, $zero, L_80025E64
    if (ctx->r1 != 0) {
        // 0x80025E80: sb          $t3, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r11;
            goto L_80025E64;
    }
    // 0x80025E80: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80025E84:
    // 0x80025E84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025E88: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80025E8C: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80025E90: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025E94: bne         $at, $zero, L_80025E3C
    if (ctx->r1 != 0) {
        // 0x80025E98: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_80025E3C;
    }
    // 0x80025E98: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025E9C:
    // 0x80025E9C: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80025EA0: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025EA4: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025EA8: beq         $at, $zero, L_80025EC8
    if (ctx->r1 == 0) {
        // 0x80025EAC: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_80025EC8;
    }
    // 0x80025EAC: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80025EB0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80025EB4: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
    // 0x80025EB8: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x80025EBC: nop

    // 0x80025EC0: beq         $s4, $t3, L_80025E04
    if (ctx->r20 == ctx->r11) {
        // 0x80025EC4: nop
    
            goto L_80025E04;
    }
    // 0x80025EC4: nop

L_80025EC8:
    // 0x80025EC8: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025ECC:
    // 0x80025ECC: beq         $at, $zero, L_80025F3C
    if (ctx->r1 == 0) {
        // 0x80025ED0: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F3C;
    }
    // 0x80025ED0: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025ED4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025ED8: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    // 0x80025EDC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80025EE0: lh          $s3, 0x0($t6)
    ctx->r19 = MEM_H(ctx->r14, 0X0);
    // 0x80025EE4: nop

    // 0x80025EE8: beq         $s4, $s3, L_80025F3C
    if (ctx->r20 == ctx->r19) {
        // 0x80025EEC: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F3C;
    }
    // 0x80025EEC: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025EF0: mtc1        $s3, $f16
    ctx->f16.u32l = ctx->r19;
    // 0x80025EF4: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x80025EF8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025EFC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80025F00: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80025F04: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025F08: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80025F0C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80025F10: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80025F14: jal         0x80026E54
    // 0x80025F18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80026E54(rdram, ctx);
        goto after_9;
    // 0x80025F18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80025F1C: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025F20: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025F24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F28: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025F2C: lh          $a3, -0x2B62($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X2B62);
    // 0x80025F30: addiu       $t0, $t0, -0x2B88
    ctx->r8 = ADD32(ctx->r8, -0X2B88);
    // 0x80025F34: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80025F38: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F3C:
    // 0x80025F3C: bne         $at, $zero, L_80025DE0
    if (ctx->r1 != 0) {
        // 0x80025F40: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025DE0;
    }
    // 0x80025F40: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F44:
    // 0x80025F44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025F48: lh          $a2, -0x2B4A($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X2B4A);
    // 0x80025F4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80025F50: beq         $a2, $zero, L_80026018
    if (ctx->r6 == 0) {
        // 0x80025F54: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80026018;
    }
    // 0x80025F54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F58: addiu       $t0, $t0, -0x4F60
    ctx->r8 = ADD32(ctx->r8, -0X4F60);
    // 0x80025F5C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025F60: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025F64: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025F68: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80025F6C: lw          $t4, -0x2B78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B78);
    // 0x80025F70: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x80025F74: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80025F78: andi        $t6, $t5, 0x6
    ctx->r14 = ctx->r13 & 0X6;
    // 0x80025F7C: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x80025F80: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80025F84: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80025F88: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80025F8C: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80025F90: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80025F94: sll         $t2, $t8, 16
    ctx->r10 = S32(ctx->r24 << 16);
    // 0x80025F98: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x80025F9C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80025FA0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x80025FA4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80025FA8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80025FAC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025FB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80025FB4: lw          $t2, -0x2B78($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B78);
    // 0x80025FB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025FBC: addu        $t4, $t2, $a3
    ctx->r12 = ADD32(ctx->r10, ctx->r7);
    // 0x80025FC0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025FC4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025FC8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80025FCC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80025FD0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80025FD4: lh          $a1, -0x2B4A($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X2B4A);
    // 0x80025FD8: nop

    // 0x80025FDC: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80025FE0: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80025FE4: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80025FE8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x80025FEC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80025FF0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80025FF4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80025FF8: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80025FFC: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x80026000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026004: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80026008: lw          $t6, -0x2B68($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B68);
    // 0x8002600C: nop

    // 0x80026010: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x80026014: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80026018:
    // 0x80026018: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002601C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026020: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80026024: sw          $t7, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r15;
    // 0x80026028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002602C: sw          $t8, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = ctx->r24;
L_80026030:
    // 0x80026030: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80026034:
    // 0x80026034: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026038: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002603C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026040: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026044: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026048: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002604C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026050: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026054: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80026058: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8002605C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80026060: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80026064: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80026068: jr          $ra
    // 0x8002606C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8002606C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void init_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C29F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C29F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C29F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C29FC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C2A00: jal         0x80070C9C
    // 0x800C2A04: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C2A04: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    after_0:
    // 0x800C2A08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C2A0C: addiu       $v1, $v1, -0x5838
    ctx->r3 = ADD32(ctx->r3, -0X5838);
    // 0x800C2A10: addiu       $t7, $v0, 0x3C0
    ctx->r15 = ADD32(ctx->r2, 0X3C0);
    // 0x800C2A14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C2A18: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C2A1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A20: sw          $zero, -0x582C($at)
    MEM_W(-0X582C, ctx->r1) = 0;
    // 0x800C2A24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A28: sh          $zero, -0x584A($at)
    MEM_H(-0X584A, ctx->r1) = 0;
    // 0x800C2A2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A30: sh          $zero, -0x5858($at)
    MEM_H(-0X5858, ctx->r1) = 0;
    // 0x800C2A34: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800C2A38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A3C: sh          $a0, -0x5856($at)
    MEM_H(-0X5856, ctx->r1) = ctx->r4;
    // 0x800C2A40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A44: sh          $zero, -0x5846($at)
    MEM_H(-0X5846, ctx->r1) = 0;
    // 0x800C2A48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A4C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800C2A50: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800C2A54: sh          $a0, -0x5852($at)
    MEM_H(-0X5852, ctx->r1) = ctx->r4;
    // 0x800C2A58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A5C: addiu       $t8, $zero, 0x120
    ctx->r24 = ADD32(0, 0X120);
    // 0x800C2A60: bne         $t9, $zero, L_800C2A84
    if (ctx->r25 != 0) {
        // 0x800C2A64: sh          $t8, -0x584E($at)
        MEM_H(-0X584E, ctx->r1) = ctx->r24;
            goto L_800C2A84;
    }
    // 0x800C2A64: sh          $t8, -0x584E($at)
    MEM_H(-0X584E, ctx->r1) = ctx->r24;
    // 0x800C2A68: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x800C2A6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A70: sh          $t0, -0x5850($at)
    MEM_H(-0X5850, ctx->r1) = ctx->r8;
    // 0x800C2A74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A78: addiu       $t1, $zero, 0xF8
    ctx->r9 = ADD32(0, 0XF8);
    // 0x800C2A7C: b           L_800C2A9C
    // 0x800C2A80: sh          $t1, -0x584C($at)
    MEM_H(-0X584C, ctx->r1) = ctx->r9;
        goto L_800C2A9C;
    // 0x800C2A80: sh          $t1, -0x584C($at)
    MEM_H(-0X584C, ctx->r1) = ctx->r9;
L_800C2A84:
    // 0x800C2A84: addiu       $t2, $zero, 0xCA
    ctx->r10 = ADD32(0, 0XCA);
    // 0x800C2A88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A8C: sh          $t2, -0x5850($at)
    MEM_H(-0X5850, ctx->r1) = ctx->r10;
    // 0x800C2A90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2A94: addiu       $t3, $zero, 0xDE
    ctx->r11 = ADD32(0, 0XDE);
    // 0x800C2A98: sh          $t3, -0x584C($at)
    MEM_H(-0X584C, ctx->r1) = ctx->r11;
L_800C2A9C:
    // 0x800C2A9C: jal         0x800C56D0
    // 0x800C2AA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_1;
    // 0x800C2AA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2AAC: jr          $ra
    // 0x800C2AB0: nop

    return;
    // 0x800C2AB0: nop

;}
RECOMP_FUNC void func_8007CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CA68: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CA6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CA70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CA74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CA78: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007CA7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007CA80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007CA84: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007CA88: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007CA8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007CA90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CA94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CA98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CA9C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007CAA0: bltz        $a0, L_8007CAC0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CAA4: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_8007CAC0;
    }
    // 0x8007CAA4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8007CAA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CAAC: lw          $t6, 0x6354($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6354);
    // 0x8007CAB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007CAB4: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CAB8: bne         $at, $zero, L_8007CAD8
    if (ctx->r1 != 0) {
        // 0x8007CABC: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_8007CAD8;
    }
    // 0x8007CABC: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
L_8007CAC0:
    // 0x8007CAC0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007CAC4: nop

    // 0x8007CAC8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007CACC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CAD0: b           L_8007CC80
    // 0x8007CAD4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_8007CC80;
    // 0x8007CAD4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8007CAD8:
    // 0x8007CAD8: lw          $t9, 0x6348($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6348);
    // 0x8007CADC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007CAE0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8007CAE4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CAE8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8007CAEC: lw          $s2, 0x6350($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X6350);
    // 0x8007CAF0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CAF4: subu        $a3, $t1, $a2
    ctx->r7 = SUB32(ctx->r9, ctx->r6);
    // 0x8007CAF8: jal         0x80076E68
    // 0x8007CAFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CAFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8007CB00: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007CB04: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CB08: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007CB0C: beq         $at, $zero, L_8007CB34
    if (ctx->r1 == 0) {
        // 0x8007CB10: addu        $fp, $s2, $s1
        ctx->r30 = ADD32(ctx->r18, ctx->r17);
            goto L_8007CB34;
    }
    // 0x8007CB10: addu        $fp, $s2, $s1
    ctx->r30 = ADD32(ctx->r18, ctx->r17);
L_8007CB14:
    // 0x8007CB14: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CB18:
    // 0x8007CB18: nop

    // 0x8007CB1C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8007CB20: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CB24: nop

    // 0x8007CB28: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8007CB2C: b           L_8007CC80
    // 0x8007CB30: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
        goto L_8007CC80;
    // 0x8007CB30: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
L_8007CB34:
    // 0x8007CB34: lbu         $t5, 0xC($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CB38: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x8007CB3C: jal         0x8007AE74
    // 0x8007CB40: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007CB40: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_1:
    // 0x8007CB44: bne         $v0, $zero, L_8007CB58
    if (ctx->r2 != 0) {
        // 0x8007CB48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CB58;
    }
    // 0x8007CB48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007CB4C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CB50: b           L_8007CB18
    // 0x8007CB54: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
        goto L_8007CB18;
    // 0x8007CB54: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CB58:
    // 0x8007CB58: lbu         $t7, 0xC($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CB5C: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8007CB60: jal         0x8007C57C
    // 0x8007CB64: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    tex_asset_size(rdram, ctx);
        goto after_2;
    // 0x8007CB64: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8007CB68: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007CB70: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8007CB74: lh          $t0, 0x4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4);
    // 0x8007CB78: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8007CB7C: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x8007CB80: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8007CB84: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007CB88: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007CB8C: subu        $s3, $t9, $t0
    ctx->r19 = SUB32(ctx->r25, ctx->r8);
    // 0x8007CB90: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8007CB94: addu        $s5, $s3, $a1
    ctx->r21 = ADD32(ctx->r19, ctx->r5);
    // 0x8007CB98: jal         0x8007B2BC
    // 0x8007CB9C: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    tex_free(rdram, ctx);
        goto after_3;
    // 0x8007CB9C: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    after_3:
    // 0x8007CBA0: lbu         $s1, 0xC($fp)
    ctx->r17 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CBA4: lbu         $t3, 0xD($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0XD);
    // 0x8007CBA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007CBAC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007CBB0: beq         $at, $zero, L_8007CC6C
    if (ctx->r1 == 0) {
        // 0x8007CBB4: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_8007CC6C;
    }
    // 0x8007CBB4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007CBB8:
    // 0x8007CBB8: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x8007CBBC: jal         0x8007AE74
    // 0x8007CBC0: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8007CBC0: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    after_4:
    // 0x8007CBC4: beq         $v0, $zero, L_8007CB14
    if (ctx->r2 == 0) {
        // 0x8007CBC8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CB14;
    }
    // 0x8007CBC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007CBCC: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x8007CBD0: jal         0x8007C57C
    // 0x8007CBD4: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    tex_asset_size(rdram, ctx);
        goto after_5;
    // 0x8007CBD4: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    after_5:
    // 0x8007CBD8: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8007CBDC: nop

    // 0x8007CBE0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8007CBE4: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x8007CBE8: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x8007CBEC: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8007CBF0: lb          $t1, 0x4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4);
    // 0x8007CBF4: lh          $t0, 0x6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X6);
    // 0x8007CBF8: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8007CBFC: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007CC00: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007CC04: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8007CC08: beq         $at, $zero, L_8007CC14
    if (ctx->r1 == 0) {
        // 0x8007CC0C: subu        $a0, $t0, $t1
        ctx->r4 = SUB32(ctx->r8, ctx->r9);
            goto L_8007CC14;
    }
    // 0x8007CC0C: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    // 0x8007CC10: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
L_8007CC14:
    // 0x8007CC14: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8007CC18: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007CC1C: beq         $at, $zero, L_8007CC28
    if (ctx->r1 == 0) {
        // 0x8007CC20: nop
    
            goto L_8007CC28;
    }
    // 0x8007CC20: nop

    // 0x8007CC24: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_8007CC28:
    // 0x8007CC28: subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // 0x8007CC2C: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007CC30: beq         $at, $zero, L_8007CC40
    if (ctx->r1 == 0) {
        // 0x8007CC34: slt         $at, $s4, $a0
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007CC40;
    }
    // 0x8007CC34: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007CC38: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007CC3C: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
L_8007CC40:
    // 0x8007CC40: beq         $at, $zero, L_8007CC4C
    if (ctx->r1 == 0) {
        // 0x8007CC44: nop
    
            goto L_8007CC4C;
    }
    // 0x8007CC44: nop

    // 0x8007CC48: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
L_8007CC4C:
    // 0x8007CC4C: jal         0x8007B2BC
    // 0x8007CC50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    tex_free(rdram, ctx);
        goto after_6;
    // 0x8007CC50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8007CC54: lbu         $t2, 0xD($fp)
    ctx->r10 = MEM_BU(ctx->r30, 0XD);
    // 0x8007CC58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007CC5C: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007CC60: bne         $at, $zero, L_8007CBB8
    if (ctx->r1 != 0) {
        // 0x8007CC64: nop
    
            goto L_8007CBB8;
    }
    // 0x8007CC64: nop

    // 0x8007CC68: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007CC6C:
    // 0x8007CC6C: subu        $t3, $s5, $s3
    ctx->r11 = SUB32(ctx->r21, ctx->r19);
    // 0x8007CC70: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007CC74: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CC78: subu        $t5, $s4, $s6
    ctx->r13 = SUB32(ctx->r20, ctx->r22);
    // 0x8007CC7C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8007CC80:
    // 0x8007CC80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CC88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CC8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CC90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CC94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CC98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CC9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007CCA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007CCA4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007CCA8: jr          $ra
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void pausemenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093D40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80093D44: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80093D48: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80093D4C: addiu       $s3, $s3, 0x984
    ctx->r19 = ADD32(ctx->r19, 0X984);
    // 0x80093D50: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80093D54: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80093D58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80093D5C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80093D60: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80093D64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80093D68: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80093D6C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80093D70: blez        $v0, L_80093DC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093D74: addiu       $t0, $zero, 0xA0
        ctx->r8 = ADD32(0, 0XA0);
            goto L_80093DC0;
    }
    // 0x80093D74: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80093D78: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80093D7C: addiu       $s0, $s0, 0x6A40
    ctx->r16 = ADD32(ctx->r16, 0X6A40);
L_80093D80:
    // 0x80093D80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80093D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093D88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80093D8C: jal         0x800C4DA0
    // 0x80093D90: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    get_text_width(rdram, ctx);
        goto after_0;
    // 0x80093D90: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x80093D94: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80093D98: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80093D9C: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80093DA0: beq         $at, $zero, L_80093DAC
    if (ctx->r1 == 0) {
        // 0x80093DA4: nop
    
            goto L_80093DAC;
    }
    // 0x80093DA4: nop

    // 0x80093DA8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_80093DAC:
    // 0x80093DAC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80093DB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80093DB4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80093DB8: bne         $at, $zero, L_80093D80
    if (ctx->r1 != 0) {
        // 0x80093DBC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80093D80;
    }
    // 0x80093DBC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80093DC0:
    // 0x80093DC0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80093DC4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80093DC8: sll         $s1, $v0, 4
    ctx->r17 = S32(ctx->r2 << 4);
    // 0x80093DCC: bne         $t6, $zero, L_80093DDC
    if (ctx->r14 != 0) {
        // 0x80093DD0: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_80093DDC;
    }
    // 0x80093DD0: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x80093DD4: b           L_80093DE0
    // 0x80093DD8: addiu       $s2, $zero, 0x84
    ctx->r18 = ADD32(0, 0X84);
        goto L_80093DE0;
    // 0x80093DD8: addiu       $s2, $zero, 0x84
    ctx->r18 = ADD32(0, 0X84);
L_80093DDC:
    // 0x80093DDC: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_80093DE0:
    // 0x80093DE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093DE4: jal         0x800C56D0
    // 0x80093DE8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_1;
    // 0x80093DE8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x80093DEC: jal         0x800C5494
    // 0x80093DF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x80093DF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80093DF4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80093DF8: sra         $s0, $s1, 1
    ctx->r16 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80093DFC: addu        $t8, $s0, $s2
    ctx->r24 = ADD32(ctx->r16, ctx->r18);
    // 0x80093E00: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80093E04: sra         $v0, $t0, 1
    ctx->r2 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80093E08: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x80093E0C: addiu       $a3, $v0, 0xA0
    ctx->r7 = ADD32(ctx->r2, 0XA0);
    // 0x80093E10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093E14: subu        $a2, $s2, $s0
    ctx->r6 = SUB32(ctx->r18, ctx->r16);
    // 0x80093E18: jal         0x800C4EDC
    // 0x80093E1C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_3;
    // 0x80093E1C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80093E20: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80093E24: addiu       $s1, $s1, 0x98C
    ctx->r17 = ADD32(ctx->r17, 0X98C);
    // 0x80093E28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80093E2C: jal         0x8006A4F8
    // 0x80093E30: nop

    input_player_id(rdram, ctx);
        goto after_4;
    // 0x80093E30: nop

    after_4:
    // 0x80093E34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80093E38: addiu       $t1, $t1, 0x990
    ctx->r9 = ADD32(ctx->r9, 0X990);
    // 0x80093E3C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80093E40: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80093E44: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80093E48: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80093E4C: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x80093E50: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x80093E54: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093E58: jal         0x800C4FBC
    // 0x80093E5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80093E5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x80093E60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093E64: jal         0x800C4F7C
    // 0x80093E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_6;
    // 0x80093E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80093E6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093E70: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80093E74: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80093E78: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80093E7C: jal         0x800C5050
    // 0x80093E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_7;
    // 0x80093E80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80093E84: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80093E88: jal         0x8006A4F8
    // 0x80093E8C: nop

    input_player_id(rdram, ctx);
        goto after_8;
    // 0x80093E8C: nop

    after_8:
    // 0x80093E90: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80093E94: addiu       $t4, $t4, 0x9A0
    ctx->r12 = ADD32(ctx->r12, 0X9A0);
    // 0x80093E98: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80093E9C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80093EA0: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x80093EA4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80093EA8: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x80093EAC: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x80093EB0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80093EB4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80093EB8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093EBC: jal         0x800C5000
    // 0x80093EC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_current_text_colour(rdram, ctx);
        goto after_9;
    // 0x80093EC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_9:
    // 0x80093EC4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80093EC8: lw          $s4, 0x63BC($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X63BC);
    // 0x80093ECC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80093ED0: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    // 0x80093ED4: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80093ED8: bne         $at, $zero, L_80093EE8
    if (ctx->r1 != 0) {
        // 0x80093EDC: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_80093EE8;
    }
    // 0x80093EDC: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80093EE0: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x80093EE4: subu        $s4, $t8, $t7
    ctx->r20 = SUB32(ctx->r24, ctx->r15);
L_80093EE8:
    // 0x80093EE8: addiu       $s2, $s2, 0x988
    ctx->r18 = ADD32(ctx->r18, 0X988);
    // 0x80093EEC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80093EF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093EF4: beq         $t9, $zero, L_80094078
    if (ctx->r25 == 0) {
        // 0x80093EF8: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_80094078;
    }
    // 0x80093EF8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80093EFC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80093F00: lw          $t1, 0xFE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFE8);
    // 0x80093F04: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093F08: beq         $t1, $zero, L_80093F48
    if (ctx->r9 == 0) {
        // 0x80093F0C: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_80093F48;
    }
    // 0x80093F0C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80093F10: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80093F14: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80093F18: addiu       $s1, $s0, -0x1A
    ctx->r17 = ADD32(ctx->r16, -0X1A);
    // 0x80093F1C: lw          $a3, 0x208($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X208);
    // 0x80093F20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80093F24: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80093F28: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80093F2C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80093F30: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // 0x80093F34: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093F38: jal         0x800C5168
    // 0x80093F3C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    render_dialogue_text(rdram, ctx);
        goto after_10;
    // 0x80093F3C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_10:
    // 0x80093F40: b           L_80093F74
    // 0x80093F44: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
        goto L_80093F74;
    // 0x80093F44: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80093F48:
    // 0x80093F48: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80093F4C: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80093F50: addiu       $s1, $s0, -0x1A
    ctx->r17 = ADD32(ctx->r16, -0X1A);
    // 0x80093F54: lw          $a3, 0x210($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X210);
    // 0x80093F58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80093F5C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80093F60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80093F64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80093F68: jal         0x800C5168
    // 0x80093F6C: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_11;
    // 0x80093F6C: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    after_11:
    // 0x80093F70: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80093F74:
    // 0x80093F74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093F78: bne         $t8, $at, L_80093FA8
    if (ctx->r24 != ctx->r1) {
        // 0x80093F7C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80093FA8;
    }
    // 0x80093F7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093F80: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80093F84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80093F88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093F90: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093F94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80093F98: jal         0x800C5000
    // 0x80093F9C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_12;
    // 0x80093F9C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_12:
    // 0x80093FA0: b           L_80093FC4
    // 0x80093FA4: nop

        goto L_80093FC4;
    // 0x80093FA4: nop

L_80093FA8:
    // 0x80093FA8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80093FAC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80093FB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80093FB4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80093FB8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80093FBC: jal         0x800C5000
    // 0x80093FC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_13;
    // 0x80093FC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
L_80093FC4:
    // 0x80093FC4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80093FC8: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80093FCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80093FD0: lw          $a3, 0x218($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X218);
    // 0x80093FD4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80093FD8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80093FDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80093FE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80093FE4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80093FE8: jal         0x800C5168
    // 0x80093FEC: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80093FEC: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    after_14:
    // 0x80093FF0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80093FF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093FF8: bne         $t5, $at, L_80094028
    if (ctx->r13 != ctx->r1) {
        // 0x80093FFC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80094028;
    }
    // 0x80093FFC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094000: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80094004: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80094008: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009400C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094010: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094014: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094018: jal         0x800C5000
    // 0x8009401C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_15;
    // 0x8009401C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x80094020: b           L_80094044
    // 0x80094024: nop

        goto L_80094044;
    // 0x80094024: nop

L_80094028:
    // 0x80094028: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009402C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80094030: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094034: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094038: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009403C: jal         0x800C5000
    // 0x80094040: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_16;
    // 0x80094040: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
L_80094044:
    // 0x80094044: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80094048: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009404C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094050: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x80094054: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80094058: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009405C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80094060: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094064: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80094068: jal         0x800C5168
    // 0x8009406C: addiu       $a2, $s1, 0x2C
    ctx->r6 = ADD32(ctx->r17, 0X2C);
    render_dialogue_text(rdram, ctx);
        goto after_17;
    // 0x8009406C: addiu       $a2, $s1, 0x2C
    ctx->r6 = ADD32(ctx->r17, 0X2C);
    after_17:
    // 0x80094070: b           L_80094148
    // 0x80094074: nop

        goto L_80094148;
    // 0x80094074: nop

L_80094078:
    // 0x80094078: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009407C: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80094080: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80094084: lw          $a3, 0x214($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X214);
    // 0x80094088: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8009408C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80094090: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80094094: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80094098: jal         0x800C5168
    // 0x8009409C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_18;
    // 0x8009409C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_18:
    // 0x800940A0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800940A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800940A8: blez        $t6, L_80094148
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800940AC: addiu       $s2, $zero, 0x20
        ctx->r18 = ADD32(0, 0X20);
            goto L_80094148;
    }
    // 0x800940AC: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x800940B0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800940B4: addiu       $s0, $s0, 0x6A40
    ctx->r16 = ADD32(ctx->r16, 0X6A40);
L_800940B8:
    // 0x800940B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800940BC: lw          $t7, 0x6A68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A68);
    // 0x800940C0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800940C4: bne         $s1, $t7, L_800940F4
    if (ctx->r17 != ctx->r15) {
        // 0x800940C8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800940F4;
    }
    // 0x800940C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800940CC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800940D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800940D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800940D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800940DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800940E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800940E4: jal         0x800C5000
    // 0x800940E8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_19;
    // 0x800940E8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_19:
    // 0x800940EC: b           L_80094110
    // 0x800940F0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80094110;
    // 0x800940F0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800940F4:
    // 0x800940F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800940F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800940FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094100: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094104: jal         0x800C5000
    // 0x80094108: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_20;
    // 0x80094108: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x8009410C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80094110:
    // 0x80094110: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094114: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80094118: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009411C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80094120: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094124: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80094128: jal         0x800C5168
    // 0x8009412C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_21;
    // 0x8009412C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_21:
    // 0x80094130: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80094134: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80094138: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8009413C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80094140: bne         $at, $zero, L_800940B8
    if (ctx->r1 != 0) {
        // 0x80094144: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800940B8;
    }
    // 0x80094144: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_80094148:
    // 0x80094148: jal         0x800C55F4
    // 0x8009414C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_22;
    // 0x8009414C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
    // 0x80094150: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80094154: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80094158: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8009415C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80094160: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80094164: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80094168: jr          $ra
    // 0x8009416C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009416C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void trackmenu_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 12U, dkr_legacy_fields, 0U); }
    // 0x8008F00C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F010: addiu       $a1, $a1, 0x67D0
    ctx->r5 = ADD32(ctx->r5, 0X67D0);
    // 0x8008F014: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008F018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F01C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F024: beq         $v0, $at, L_8008F04C
    if (ctx->r2 == ctx->r1) {
        // 0x8008F028: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008F04C;
    }
    // 0x8008F028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F02C: beq         $v0, $zero, L_8008F04C
    if (ctx->r2 == 0) {
        // 0x8008F030: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008F04C;
    }
    // 0x8008F030: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F034: bne         $v0, $at, L_8008F04C
    if (ctx->r2 != ctx->r1) {
        // 0x8008F038: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F04C;
    }
    // 0x8008F038: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F03C: jal         0x8009C4A8
    // 0x8008F040: addiu       $a0, $a0, 0x7E8
    ctx->r4 = ADD32(ctx->r4, 0X7E8);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008F040: addiu       $a0, $a0, 0x7E8
    ctx->r4 = ADD32(ctx->r4, 0X7E8);
    after_0:
    // 0x8008F044: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F048: addiu       $a1, $a1, 0x67D0
    ctx->r5 = ADD32(ctx->r5, 0X67D0);
L_8008F04C:
    // 0x8008F04C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008F050: nop

    // 0x8008F054: bltz        $t6, L_8008F220
    if (SIGNED(ctx->r14) < 0) {
        // 0x8008F058: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_8008F220;
    }
    // 0x8008F058: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008F05C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008F060: beq         $at, $zero, L_8008F224
    if (ctx->r1 == 0) {
        // 0x8008F064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008F224;
    }
    // 0x8008F064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F068: beq         $t6, $zero, L_8008F084
    if (ctx->r14 == 0) {
        // 0x8008F06C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008F084;
    }
    // 0x8008F06C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F074: beq         $t6, $at, L_8008F0A4
    if (ctx->r14 == ctx->r1) {
        // 0x8008F078: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F0A4;
    }
    // 0x8008F078: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F07C: b           L_8008F224
    // 0x8008F080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F224;
    // 0x8008F080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F084:
    // 0x8008F084: lwc1        $f4, 0x69DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x8008F088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F08C: swc1        $f4, 0x69E8($at)
    MEM_W(0X69E8, ctx->r1) = ctx->f4.u32l;
    // 0x8008F090: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F094: lwc1        $f6, 0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x8008F098: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F09C: b           L_8008F220
    // 0x8008F0A0: swc1        $f6, 0x69EC($at)
    MEM_W(0X69EC, ctx->r1) = ctx->f6.u32l;
        goto L_8008F220;
    // 0x8008F0A0: swc1        $f6, 0x69EC($at)
    MEM_W(0X69EC, ctx->r1) = ctx->f6.u32l;
L_8008F0A4:
    // 0x8008F0A4: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x8008F0A8: jal         0x8006B0AC
    // 0x8008F0AC: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8008F0AC: nop

    after_1:
    // 0x8008F0B0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008F0B4: lw          $a2, -0xB44($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XB44);
    // 0x8008F0B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F0BC: blez        $a2, L_8008F0EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008F0C0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008F0EC;
    }
    // 0x8008F0C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F0C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008F0C8: addiu       $v1, $t7, 0x69C0
    ctx->r3 = ADD32(ctx->r15, 0X69C0);
    // 0x8008F0CC: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
    // 0x8008F0D0: addiu       $a0, $a0, 0x69C4
    ctx->r4 = ADD32(ctx->r4, 0X69C4);
L_8008F0D4:
    // 0x8008F0D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008F0D8: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8008F0DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F0E0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
    // 0x8008F0E4: bne         $at, $zero, L_8008F0D4
    if (ctx->r1 != 0) {
        // 0x8008F0E8: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_8008F0D4;
    }
    // 0x8008F0E8: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_8008F0EC:
    // 0x8008F0EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F0F0: sw          $zero, -0xB80($at)
    MEM_W(-0XB80, ctx->r1) = 0;
    // 0x8008F0F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F0F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F0FC: sw          $t8, 0x980($at)
    MEM_W(0X980, ctx->r1) = ctx->r24;
    // 0x8008F100: jal         0x8009C674
    // 0x8008F104: addiu       $a0, $a0, 0x7E8
    ctx->r4 = ADD32(ctx->r4, 0X7E8);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x8008F104: addiu       $a0, $a0, 0x7E8
    ctx->r4 = ADD32(ctx->r4, 0X7E8);
    after_2:
    // 0x8008F108: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F10C: jal         0x8009C8A4
    // 0x8008F110: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8008F110: addiu       $a0, $a0, 0x830
    ctx->r4 = ADD32(ctx->r4, 0X830);
    after_3:
    // 0x8008F114: jal         0x8008E45C
    // 0x8008F118: nop

    menu_init_vehicle_textures(rdram, ctx);
        goto after_4;
    // 0x8008F118: nop

    after_4:
    // 0x8008F11C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F120: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x8008F124: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F128: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F12C: lw          $t9, 0x90($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X90);
    // 0x8008F130: lw          $t0, 0x94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X94);
    // 0x8008F134: lw          $t1, 0x98($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X98);
    // 0x8008F138: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x8008F13C: addiu       $a0, $a0, 0x4BC
    ctx->r4 = ADD32(ctx->r4, 0X4BC);
    // 0x8008F140: addiu       $v1, $v1, 0x4A4
    ctx->r3 = ADD32(ctx->r3, 0X4A4);
    // 0x8008F144: lw          $t3, 0x7C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X7C);
    // 0x8008F148: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F14C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F150: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x8008F154: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8008F158: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8008F15C: sw          $t3, 0x4D4($at)
    MEM_W(0X4D4, ctx->r1) = ctx->r11;
    // 0x8008F160: lw          $t4, 0x78($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X78);
    // 0x8008F164: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F168: sw          $t4, 0x4E4($at)
    MEM_W(0X4E4, ctx->r1) = ctx->r12;
    // 0x8008F16C: lw          $t5, 0x84($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X84);
    // 0x8008F170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F174: sw          $t5, 0x4F4($at)
    MEM_W(0X4F4, ctx->r1) = ctx->r13;
    // 0x8008F178: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x8008F17C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F180: sw          $t6, 0x504($at)
    MEM_W(0X504, ctx->r1) = ctx->r14;
    // 0x8008F184: lw          $t7, 0x8C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8C);
    // 0x8008F188: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F18C: sw          $t7, 0x514($at)
    MEM_W(0X514, ctx->r1) = ctx->r15;
    // 0x8008F190: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x8008F194: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F198: sw          $t8, 0x524($at)
    MEM_W(0X524, ctx->r1) = ctx->r24;
    // 0x8008F19C: lw          $t9, 0xA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA0);
    // 0x8008F1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1A4: sw          $t9, 0x534($at)
    MEM_W(0X534, ctx->r1) = ctx->r25;
    // 0x8008F1A8: lw          $t0, 0xA8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA8);
    // 0x8008F1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1B0: sw          $t0, 0x544($at)
    MEM_W(0X544, ctx->r1) = ctx->r8;
    // 0x8008F1B4: lw          $t1, 0xA4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XA4);
    // 0x8008F1B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1BC: sw          $t1, 0x554($at)
    MEM_W(0X554, ctx->r1) = ctx->r9;
    // 0x8008F1C0: lw          $t2, 0xAC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAC);
    // 0x8008F1C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1C8: sw          $t2, 0x564($at)
    MEM_W(0X564, ctx->r1) = ctx->r10;
    // 0x8008F1CC: lw          $t3, 0xB0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB0);
    // 0x8008F1D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1D4: sw          $t3, 0x574($at)
    MEM_W(0X574, ctx->r1) = ctx->r11;
    // 0x8008F1D8: lw          $t4, 0xB4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XB4);
    // 0x8008F1DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1E0: sw          $t4, 0x584($at)
    MEM_W(0X584, ctx->r1) = ctx->r12;
    // 0x8008F1E4: lw          $t5, 0xB8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XB8);
    // 0x8008F1E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1EC: sw          $t5, 0x594($at)
    MEM_W(0X594, ctx->r1) = ctx->r13;
    // 0x8008F1F0: lw          $t6, 0xBC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XBC);
    // 0x8008F1F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F1F8: sw          $t6, 0x5A4($at)
    MEM_W(0X5A4, ctx->r1) = ctx->r14;
    // 0x8008F1FC: lw          $t7, 0xC0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC0);
    // 0x8008F200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F204: sw          $t7, 0x5B4($at)
    MEM_W(0X5B4, ctx->r1) = ctx->r15;
    // 0x8008F208: lw          $t8, 0xC4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC4);
    // 0x8008F20C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F210: sw          $t8, 0x5C4($at)
    MEM_W(0X5C4, ctx->r1) = ctx->r24;
    // 0x8008F214: lw          $t9, 0x178($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X178);
    // 0x8008F218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F21C: sw          $t9, 0x614($at)
    MEM_W(0X614, ctx->r1) = ctx->r25;
L_8008F220:
    // 0x8008F220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F224:
    // 0x8008F224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F228: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008F22C: jr          $ra
    // 0x8008F230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008F230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fileselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CD74: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8008CD78: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008CD7C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008CD80: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008CD84: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8008CD88: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8008CD8C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8008CD90: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8008CD94: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8008CD98: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8008CD9C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8008CDA0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8008CDA4: bne         $t6, $zero, L_8008CDB4
    if (ctx->r14 != 0) {
        // 0x8008CDA8: sw          $a0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r4;
            goto L_8008CDB4;
    }
    // 0x8008CDA8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8008CDAC: b           L_8008CDB8
    // 0x8008CDB0: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
        goto L_8008CDB8;
    // 0x8008CDB0: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_8008CDB4:
    // 0x8008CDB4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_8008CDB8:
    // 0x8008CDB8: jal         0x8009BD5C
    // 0x8008CDBC: nop

    menu_camera_centre(rdram, ctx);
        goto after_0;
    // 0x8008CDBC: nop

    after_0:
    // 0x8008CDC0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008CDC4: addiu       $s7, $s7, 0x63A0
    ctx->r23 = ADD32(ctx->r23, 0X63A0);
    // 0x8008CDC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008CDCC: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8008CDD0: jal         0x80067F2C
    // 0x8008CDD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x8008CDD4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x8008CDD8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008CDDC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008CDE0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008CDE4: lui         $s3, 0xB0E0
    ctx->r19 = S32(0XB0E0 << 16);
    // 0x8008CDE8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008CDEC: addiu       $s2, $s2, -0xB6C
    ctx->r18 = ADD32(ctx->r18, -0XB6C);
    // 0x8008CDF0: ori         $s3, $s3, 0xC0FF
    ctx->r19 = ctx->r19 | 0XC0FF;
    // 0x8008CDF4: addiu       $s5, $s5, 0x6550
    ctx->r21 = ADD32(ctx->r21, 0X6550);
    // 0x8008CDF8: addiu       $s0, $s0, 0x3CC
    ctx->r16 = ADD32(ctx->r16, 0X3CC);
    // 0x8008CDFC: addiu       $s1, $s1, 0x64A0
    ctx->r17 = ADD32(ctx->r17, 0X64A0);
    // 0x8008CE00: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
L_8008CE04:
    // 0x8008CE04: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8008CE08: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008CE0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CE10: beq         $t7, $t8, L_8008CE28
    if (ctx->r15 == ctx->r24) {
        // 0x8008CE14: nop
    
            goto L_8008CE28;
    }
    // 0x8008CE14: nop

    // 0x8008CE18: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8008CE1C: lui         $v0, 0x6A90
    ctx->r2 = S32(0X6A90 << 16);
    // 0x8008CE20: bne         $t9, $zero, L_8008CE30
    if (ctx->r25 != 0) {
        // 0x8008CE24: ori         $v0, $v0, 0x73FF
        ctx->r2 = ctx->r2 | 0X73FF;
            goto L_8008CE30;
    }
    // 0x8008CE24: ori         $v0, $v0, 0x73FF
    ctx->r2 = ctx->r2 | 0X73FF;
L_8008CE28:
    // 0x8008CE28: b           L_8008CE30
    // 0x8008CE2C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_8008CE30;
    // 0x8008CE2C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8008CE30:
    // 0x8008CE30: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008CE34: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008CE38: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x8008CE3C: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x8008CE40: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x8008CE44: lw          $t4, 0x10C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X10C);
    // 0x8008CE48: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008CE4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008CE50: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x8008CE54: subu        $a2, $s4, $t0
    ctx->r6 = SUB32(ctx->r20, ctx->r8);
    // 0x8008CE58: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008CE5C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8008CE60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008CE64: jal         0x80080580
    // 0x8008CE68: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x8008CE68: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_2:
    // 0x8008CE6C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008CE70: addiu       $t5, $t5, 0x3FC
    ctx->r13 = ADD32(ctx->r13, 0X3FC);
    // 0x8008CE74: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008CE78: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x8008CE7C: bne         $at, $zero, L_8008CE04
    if (ctx->r1 != 0) {
        // 0x8008CE80: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008CE04;
    }
    // 0x8008CE80: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8008CE84: jal         0x80080BC8
    // 0x8008CE88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x8008CE88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x8008CE8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008CE90: lw          $t6, 0x63D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63D8);
    // 0x8008CE94: nop

    // 0x8008CE98: bne         $t6, $zero, L_8008D0F8
    if (ctx->r14 != 0) {
        // 0x8008CE9C: nop
    
            goto L_8008D0F8;
    }
    // 0x8008CE9C: nop

    // 0x8008CEA0: jal         0x800C42EC
    // 0x8008CEA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_4;
    // 0x8008CEA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8008CEA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CEB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008CEB4: jal         0x800C43CC
    // 0x8008CEB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_5;
    // 0x8008CEB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8008CEBC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008CEC0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008CEC4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008CEC8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008CECC: addiu       $s3, $s3, -0x8A4
    ctx->r19 = ADD32(ctx->r19, -0X8A4);
    // 0x8008CED0: addiu       $s4, $s4, 0x3FC
    ctx->r20 = ADD32(ctx->r20, 0X3FC);
    // 0x8008CED4: addiu       $s0, $s0, 0x3CC
    ctx->r16 = ADD32(ctx->r16, 0X3CC);
    // 0x8008CED8: addiu       $s1, $s1, 0x64A0
    ctx->r17 = ADD32(ctx->r17, 0X64A0);
    // 0x8008CEDC: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8008CEE0:
    // 0x8008CEE0: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x8008CEE4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008CEE8: beq         $t7, $zero, L_8008D098
    if (ctx->r15 == 0) {
        // 0x8008CEEC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008D098;
    }
    // 0x8008CEEC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008CEF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CEF4: jal         0x8007BF1C
    // 0x8008CEF8: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x8008CEF8: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    after_6:
    // 0x8008CEFC: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008CF00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008CF04: beq         $t8, $zero, L_8008CF10
    if (ctx->r24 == 0) {
        // 0x8008CF08: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_8008CF10;
    }
    // 0x8008CF08: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8008CF0C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8008CF10:
    // 0x8008CF10: lh          $t9, 0x4($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X4);
    // 0x8008CF14: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008CF18: lh          $t1, 0x6($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X6);
    // 0x8008CF1C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008CF20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008CF24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008CF28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008CF2C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008CF30: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8008CF34: jal         0x8008CC28
    // 0x8008CF38: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    fileselect_render_element(rdram, ctx);
        goto after_7;
    // 0x8008CF38: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_7:
    // 0x8008CF3C: jal         0x80068508
    // 0x8008CF40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x8008CF40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8008CF44: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x8008CF48: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8008CF4C: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x8008CF50: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8008CF54: bne         $s5, $zero, L_8008CF60
    if (ctx->r21 != 0) {
        // 0x8008CF58: nop
    
            goto L_8008CF60;
    }
    // 0x8008CF58: nop

    // 0x8008CF5C: break       7
    do_break(2148061020);
L_8008CF60:
    // 0x8008CF60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008CF64: bne         $s5, $at, L_8008CF78
    if (ctx->r21 != ctx->r1) {
        // 0x8008CF68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008CF78;
    }
    // 0x8008CF68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008CF6C: bne         $t4, $at, L_8008CF78
    if (ctx->r12 != ctx->r1) {
        // 0x8008CF70: nop
    
            goto L_8008CF78;
    }
    // 0x8008CF70: nop

    // 0x8008CF74: break       6
    do_break(2148061044);
L_8008CF78:
    // 0x8008CF78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CF7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008CF80: mflo        $t5
    ctx->r13 = lo;
    // 0x8008CF84: sh          $t5, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r13;
    // 0x8008CF88: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8008CF8C: lh          $t7, 0xC($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XC);
    // 0x8008CF90: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008CF94: lh          $t9, 0xE($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XE);
    // 0x8008CF98: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008CF9C: addiu       $a1, $a1, -0x6
    ctx->r5 = ADD32(ctx->r5, -0X6);
    // 0x8008CFA0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008CFA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008CFA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008CFAC: jal         0x8008CC28
    // 0x8008CFB0: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    fileselect_render_element(rdram, ctx);
        goto after_9;
    // 0x8008CFB0: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_9:
    // 0x8008CFB4: lhu         $t2, 0x2($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X2);
    // 0x8008CFB8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8008CFBC: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x8008CFC0: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8008CFC4: bne         $s5, $zero, L_8008CFD0
    if (ctx->r21 != 0) {
        // 0x8008CFC8: nop
    
            goto L_8008CFD0;
    }
    // 0x8008CFC8: nop

    // 0x8008CFCC: break       7
    do_break(2148061132);
L_8008CFD0:
    // 0x8008CFD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008CFD4: bne         $s5, $at, L_8008CFE8
    if (ctx->r21 != ctx->r1) {
        // 0x8008CFD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008CFE8;
    }
    // 0x8008CFD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008CFDC: bne         $t2, $at, L_8008CFE8
    if (ctx->r10 != ctx->r1) {
        // 0x8008CFE0: nop
    
            goto L_8008CFE8;
    }
    // 0x8008CFE0: nop

    // 0x8008CFE4: break       6
    do_break(2148061156);
L_8008CFE8:
    // 0x8008CFE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008CFEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008CFF0: mfhi        $t3
    ctx->r11 = hi;
    // 0x8008CFF4: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x8008CFF8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8008CFFC: lh          $t5, 0xC($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC);
    // 0x8008D000: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8008D004: lh          $t7, 0xE($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XE);
    // 0x8008D008: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008D00C: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8008D010: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008D014: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D018: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D01C: jal         0x8008CC28
    // 0x8008D020: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    fileselect_render_element(rdram, ctx);
        goto after_10;
    // 0x8008D020: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x8008D024: jal         0x80068508
    // 0x8008D028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x8008D028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8008D02C: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008D030: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D034: sb          $v0, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r2;
    // 0x8008D038: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D03C: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x8008D040: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x8008D044: lh          $t2, 0x12($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X12);
    // 0x8008D048: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008D04C: lh          $t0, 0x10($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X10);
    // 0x8008D050: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8008D054: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008D058: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008D05C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D060: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D064: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D068: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8008D06C: jal         0x8008CC28
    // 0x8008D070: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    fileselect_render_element(rdram, ctx);
        goto after_12;
    // 0x8008D070: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_12:
    // 0x8008D074: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D07C: sb          $v0, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r2;
    // 0x8008D080: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D084: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x8008D088: jal         0x8007BF1C
    // 0x8008D08C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x8008D08C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8008D090: b           L_8008D0E4
    // 0x8008D094: nop

        goto L_8008D0E4;
    // 0x8008D094: nop

L_8008D098:
    // 0x8008D098: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D09C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D0A0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D0A4: jal         0x800C4384
    // 0x8008D0A8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x8008D0A8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_14:
    // 0x8008D0AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D0B0: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x8008D0B4: lh          $t8, 0xA($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XA);
    // 0x8008D0B8: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8008D0BC: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    // 0x8008D0C0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8008D0C4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D0C8: lw          $a3, 0x12C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X12C);
    // 0x8008D0CC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008D0D0: addu        $a2, $t0, $s6
    ctx->r6 = ADD32(ctx->r8, ctx->r22);
    // 0x8008D0D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D0D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D0DC: jal         0x800C4440
    // 0x8008D0E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008D0E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_15:
L_8008D0E4:
    // 0x8008D0E4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D0E8: addiu       $t3, $t3, 0x3FC
    ctx->r11 = ADD32(ctx->r11, 0X3FC);
    // 0x8008D0EC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008D0F0: bne         $s0, $t3, L_8008CEE0
    if (ctx->r16 != ctx->r11) {
        // 0x8008D0F4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008CEE0;
    }
    // 0x8008D0F4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8008D0F8:
    // 0x8008D0F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D0FC: lw          $v0, 0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63BC);
    // 0x8008D100: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008D104: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008D108: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x8008D10C: addiu       $s4, $s4, 0x3FC
    ctx->r20 = ADD32(ctx->r20, 0X3FC);
    // 0x8008D110: bne         $at, $zero, L_8008D120
    if (ctx->r1 != 0) {
        // 0x8008D114: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8008D120;
    }
    // 0x8008D114: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8008D118: addiu       $t5, $zero, 0x1FF
    ctx->r13 = ADD32(0, 0X1FF);
    // 0x8008D11C: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
L_8008D120:
    // 0x8008D120: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D124: jal         0x800C42EC
    // 0x8008D128: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    set_text_font(rdram, ctx);
        goto after_16;
    // 0x8008D128: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_16:
    // 0x8008D12C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D138: jal         0x800C43CC
    // 0x8008D13C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_17;
    // 0x8008D13C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x8008D140: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008D144: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D148: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D14C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D150: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D154: jal         0x800C4384
    // 0x8008D158: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x8008D158: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8008D15C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008D160: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
L_8008D164:
    // 0x8008D164: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008D168: lw          $t7, 0x6484($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6484);
    // 0x8008D16C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008D170: beq         $t7, $zero, L_8008D1C4
    if (ctx->r15 == 0) {
        // 0x8008D174: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8008D1C4;
    }
    // 0x8008D174: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008D178: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D17C: lw          $v0, 0x6494($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6494);
    // 0x8008D180: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D184: bne         $v0, $zero, L_8008D1A4
    if (ctx->r2 != 0) {
        // 0x8008D188: nop
    
            goto L_8008D1A4;
    }
    // 0x8008D188: nop

    // 0x8008D18C: lw          $t8, 0x648C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648C);
    // 0x8008D190: nop

    // 0x8008D194: bne         $s3, $t8, L_8008D1A4
    if (ctx->r19 != ctx->r24) {
        // 0x8008D198: nop
    
            goto L_8008D1A4;
    }
    // 0x8008D198: nop

    // 0x8008D19C: b           L_8008D210
    // 0x8008D1A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D210;
    // 0x8008D1A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D1A4:
    // 0x8008D1A4: blez        $v0, L_8008D210
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008D1A8: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008D210;
    }
    // 0x8008D1A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D1AC: lw          $t9, 0x6490($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6490);
    // 0x8008D1B0: nop

    // 0x8008D1B4: bne         $s3, $t9, L_8008D210
    if (ctx->r19 != ctx->r25) {
        // 0x8008D1B8: nop
    
            goto L_8008D210;
    }
    // 0x8008D1B8: nop

    // 0x8008D1BC: b           L_8008D210
    // 0x8008D1C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D210;
    // 0x8008D1C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D1C4:
    // 0x8008D1C4: lw          $t0, 0x6488($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6488);
    // 0x8008D1C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D1CC: beq         $t0, $zero, L_8008D1EC
    if (ctx->r8 == 0) {
        // 0x8008D1D0: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008D1EC;
    }
    // 0x8008D1D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D1D4: lw          $t1, 0x648C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648C);
    // 0x8008D1D8: nop

    // 0x8008D1DC: bne         $s3, $t1, L_8008D210
    if (ctx->r19 != ctx->r9) {
        // 0x8008D1E0: nop
    
            goto L_8008D210;
    }
    // 0x8008D1E0: nop

    // 0x8008D1E4: b           L_8008D210
    // 0x8008D1E8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D210;
    // 0x8008D1E8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D1EC:
    // 0x8008D1EC: lw          $t2, 0x63E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X63E0);
    // 0x8008D1F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D1F4: bne         $t2, $zero, L_8008D210
    if (ctx->r10 != 0) {
        // 0x8008D1F8: nop
    
            goto L_8008D210;
    }
    // 0x8008D1F8: nop

    // 0x8008D1FC: lw          $t3, -0xB34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB34);
    // 0x8008D200: nop

    // 0x8008D204: bne         $s3, $t3, L_8008D210
    if (ctx->r19 != ctx->r11) {
        // 0x8008D208: nop
    
            goto L_8008D210;
    }
    // 0x8008D208: nop

    // 0x8008D20C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D210:
    // 0x8008D210: beq         $s2, $zero, L_8008D274
    if (ctx->r18 == 0) {
        // 0x8008D214: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D274;
    }
    // 0x8008D214: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D218: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D21C: addiu       $t5, $t5, 0x3CC
    ctx->r13 = ADD32(ctx->r13, 0X3CC);
    // 0x8008D220: sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19 << 4);
    // 0x8008D224: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8008D228: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D22C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8008D230: or          $t0, $v0, $at
    ctx->r8 = ctx->r2 | ctx->r1;
    // 0x8008D234: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008D238: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8008D23C: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x8008D240: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8008D244: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008D248: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008D24C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8008D250: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008D254: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8008D258: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8008D25C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8008D260: addu        $a2, $t6, $s6
    ctx->r6 = ADD32(ctx->r14, ctx->r22);
    // 0x8008D264: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D268: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008D26C: jal         0x80080E90
    // 0x8008D270: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80080E90(rdram, ctx);
        goto after_19;
    // 0x8008D270: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_19:
L_8008D274:
    // 0x8008D274: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D278: lw          $t1, 0x6CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6CC0);
    // 0x8008D27C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008D280: beq         $t1, $zero, L_8008D294
    if (ctx->r9 == 0) {
        // 0x8008D284: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_8008D294;
    }
    // 0x8008D284: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x8008D288: lw          $t2, -0xB34($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB34);
    // 0x8008D28C: nop

    // 0x8008D290: beq         $s3, $t2, L_8008D318
    if (ctx->r19 == ctx->r10) {
        // 0x8008D294: subu        $t3, $t3, $s3
        ctx->r11 = SUB32(ctx->r11, ctx->r19);
            goto L_8008D318;
    }
L_8008D294:
    // 0x8008D294: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x8008D298: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D29C: addiu       $t4, $t4, 0x64A0
    ctx->r12 = ADD32(ctx->r12, 0X64A0);
    // 0x8008D2A0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008D2A4: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x8008D2A8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8008D2AC: jal         0x800977D0
    // 0x8008D2B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_20;
    // 0x8008D2B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x8008D2B4: lbu         $t5, 0x1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D2B8: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8008D2BC: bne         $t5, $zero, L_8008D2D4
    if (ctx->r13 != 0) {
        // 0x8008D2C0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008D2D4;
    }
    // 0x8008D2C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008D2C4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8008D2C8: lw          $a0, 0x3B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B0);
    // 0x8008D2CC: jal         0x800977D0
    // 0x8008D2D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_21;
    // 0x8008D2D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_21:
L_8008D2D4:
    // 0x8008D2D4: beq         $s5, $zero, L_8008D318
    if (ctx->r21 == 0) {
        // 0x8008D2D8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D318;
    }
    // 0x8008D2D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D2DC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008D2E0: addiu       $t8, $t8, 0x3CC
    ctx->r24 = ADD32(ctx->r24, 0X3CC);
    // 0x8008D2E4: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x8008D2E8: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8008D2EC: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008D2F0: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x8008D2F4: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008D2F8: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8008D2FC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D300: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8008D304: addu        $a2, $t3, $s6
    ctx->r6 = ADD32(ctx->r11, ctx->r22);
    // 0x8008D308: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D30C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8008D310: jal         0x800C4440
    // 0x8008D314: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x8008D314: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_22:
L_8008D318:
    // 0x8008D318: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008D31C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D320: bne         $s3, $at, L_8008D164
    if (ctx->r19 != ctx->r1) {
        // 0x8008D324: nop
    
            goto L_8008D164;
    }
    // 0x8008D324: nop

    // 0x8008D328: jal         0x800C42EC
    // 0x8008D32C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_23;
    // 0x8008D32C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x8008D330: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8008D334: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D33C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D344: jal         0x800C4384
    // 0x8008D348: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_24;
    // 0x8008D348: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_24:
    // 0x8008D34C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D350: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8008D354: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008D358: lw          $a3, 0x130($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X130);
    // 0x8008D35C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D360: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D364: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008D368: jal         0x800C4440
    // 0x8008D36C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    draw_text(rdram, ctx);
        goto after_25;
    // 0x8008D36C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_25:
    // 0x8008D370: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008D374: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008D378: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D37C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D380: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D384: jal         0x800C4384
    // 0x8008D388: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_26;
    // 0x8008D388: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_26:
    // 0x8008D38C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008D390: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8008D394: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8008D398: lw          $a3, 0x130($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X130);
    // 0x8008D39C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008D3A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D3A4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D3A8: jal         0x800C4440
    // 0x8008D3AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    draw_text(rdram, ctx);
        goto after_27;
    // 0x8008D3AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_27:
    // 0x8008D3B0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008D3B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D3B8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D3BC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D3C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D3C4: jal         0x800C4384
    // 0x8008D3C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_28;
    // 0x8008D3C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8008D3CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D3D0: lw          $t2, 0x6484($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6484);
    // 0x8008D3D4: addiu       $s6, $s6, 0xBB
    ctx->r22 = ADD32(ctx->r22, 0XBB);
    // 0x8008D3D8: beq         $t2, $zero, L_8008D488
    if (ctx->r10 == 0) {
        // 0x8008D3DC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008D488;
    }
    // 0x8008D3DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D3E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D3E4: lw          $v0, 0x6494($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6494);
    // 0x8008D3E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D3EC: bne         $v0, $zero, L_8008D428
    if (ctx->r2 != 0) {
        // 0x8008D3F0: nop
    
            goto L_8008D428;
    }
    // 0x8008D3F0: nop

    // 0x8008D3F4: jal         0x800C42EC
    // 0x8008D3F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_29;
    // 0x8008D3F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x8008D3FC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D400: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x8008D404: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D408: lw          $a3, 0x134($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X134);
    // 0x8008D40C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D410: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D414: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D418: jal         0x800C4440
    // 0x8008D41C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_30;
    // 0x8008D41C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_30:
    // 0x8008D420: b           L_8008D5D0
    // 0x8008D424: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008D5D0;
    // 0x8008D424: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D428:
    // 0x8008D428: bne         $v0, $at, L_8008D464
    if (ctx->r2 != ctx->r1) {
        // 0x8008D42C: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D464;
    }
    // 0x8008D42C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D430: jal         0x800C42EC
    // 0x8008D434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_31;
    // 0x8008D434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x8008D438: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D43C: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8008D440: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008D444: lw          $a3, 0x138($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X138);
    // 0x8008D448: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D44C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D450: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D454: jal         0x800C4440
    // 0x8008D458: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_32;
    // 0x8008D458: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_32:
    // 0x8008D45C: b           L_8008D5D0
    // 0x8008D460: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008D5D0;
    // 0x8008D460: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D464:
    // 0x8008D464: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D468: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D46C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D470: addiu       $a3, $a3, -0x7DCC
    ctx->r7 = ADD32(ctx->r7, -0X7DCC);
    // 0x8008D474: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D478: jal         0x800C4440
    // 0x8008D47C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_33;
    // 0x8008D47C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_33:
    // 0x8008D480: b           L_8008D5D0
    // 0x8008D484: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008D5D0;
    // 0x8008D484: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D488:
    // 0x8008D488: lw          $t8, 0x6488($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6488);
    // 0x8008D48C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D490: beq         $t8, $zero, L_8008D4FC
    if (ctx->r24 == 0) {
        // 0x8008D494: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8008D4FC;
    }
    // 0x8008D494: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008D498: lw          $t9, 0x6494($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6494);
    // 0x8008D49C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D4A0: bne         $t9, $zero, L_8008D4DC
    if (ctx->r25 != 0) {
        // 0x8008D4A4: addiu       $a1, $zero, 0xA0
        ctx->r5 = ADD32(0, 0XA0);
            goto L_8008D4DC;
    }
    // 0x8008D4A4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D4A8: jal         0x800C42EC
    // 0x8008D4AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_34;
    // 0x8008D4AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x8008D4B0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008D4B4: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8008D4B8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008D4BC: lw          $a3, 0x13C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X13C);
    // 0x8008D4C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D4C4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D4C8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D4CC: jal         0x800C4440
    // 0x8008D4D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_35;
    // 0x8008D4D0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_35:
    // 0x8008D4D4: b           L_8008D5D0
    // 0x8008D4D8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008D5D0;
    // 0x8008D4D8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D4DC:
    // 0x8008D4DC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D4E0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D4E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D4E8: addiu       $a3, $a3, -0x7DC8
    ctx->r7 = ADD32(ctx->r7, -0X7DC8);
    // 0x8008D4EC: jal         0x800C4440
    // 0x8008D4F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_36;
    // 0x8008D4F0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_36:
    // 0x8008D4F4: b           L_8008D5D0
    // 0x8008D4F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008D5D0;
    // 0x8008D4F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D4FC:
    // 0x8008D4FC: lw          $t3, 0x6CC0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6CC0);
    // 0x8008D500: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D504: bne         $t3, $zero, L_8008D5D0
    if (ctx->r11 != 0) {
        // 0x8008D508: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8008D5D0;
    }
    // 0x8008D508: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8008D50C: lw          $t4, 0x63E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63E0);
    // 0x8008D510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D514: bne         $t4, $at, L_8008D534
    if (ctx->r12 != ctx->r1) {
        // 0x8008D518: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008D534;
    }
    // 0x8008D518: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D51C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D520: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D524: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D528: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D52C: jal         0x800C4384
    // 0x8008D530: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_37;
    // 0x8008D530: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_37:
L_8008D534:
    // 0x8008D534: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D538: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8008D53C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D540: lw          $a3, 0x140($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X140);
    // 0x8008D544: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D548: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D54C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8008D550: jal         0x800C4440
    // 0x8008D554: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_38;
    // 0x8008D554: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_38:
    // 0x8008D558: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D55C: lw          $t8, 0x63E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63E0);
    // 0x8008D560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D564: bne         $t8, $at, L_8008D590
    if (ctx->r24 != ctx->r1) {
        // 0x8008D568: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008D590;
    }
    // 0x8008D568: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D56C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D570: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008D574: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008D578: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D57C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D580: jal         0x800C4384
    // 0x8008D584: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_39;
    // 0x8008D584: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_39:
    // 0x8008D588: b           L_8008D5A8
    // 0x8008D58C: nop

        goto L_8008D5A8;
    // 0x8008D58C: nop

L_8008D590:
    // 0x8008D590: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008D594: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008D598: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D59C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D5A0: jal         0x800C4384
    // 0x8008D5A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_40;
    // 0x8008D5A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
L_8008D5A8:
    // 0x8008D5A8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D5AC: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x8008D5B0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D5B4: lw          $a3, 0x144($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X144);
    // 0x8008D5B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D5BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D5C0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8008D5C4: jal         0x800C4440
    // 0x8008D5C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_41;
    // 0x8008D5C8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_41:
    // 0x8008D5CC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D5D0:
    // 0x8008D5D0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8008D5D4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8008D5D8: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8008D5DC: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8008D5E0: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8008D5E4: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8008D5E8: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8008D5EC: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8008D5F0: jr          $ra
    // 0x8008D5F4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8008D5F4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065C44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065C48: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065C4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80065C50: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065C54: nop

    // 0x80065C58: beq         $t7, $zero, L_80065D34
    if (ctx->r15 == 0) {
        // 0x80065C5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065D34;
    }
    // 0x80065C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065C60: jal         0x80065668
    // 0x80065C64: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065C64: nop

    after_0:
    // 0x80065C68: beq         $v0, $zero, L_80065D30
    if (ctx->r2 == 0) {
        // 0x80065C6C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80065D30;
    }
    // 0x80065C6C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80065C70: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80065C74: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065C78: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80065C7C: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065C80: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x80065C84: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80065C88: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80065C8C: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80065C90: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065C94: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x80065C98: lh          $t4, 0x1A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1A);
    // 0x80065C9C: nop

    // 0x80065CA0: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x80065CA4: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80065CA8: jal         0x80065BEC
    // 0x80065CAC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065CAC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80065CB0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065CB4: nop

    // 0x80065CB8: sb          $v0, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r2;
    // 0x80065CBC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80065CC0: nop

    // 0x80065CC4: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x80065CC8: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x80065CCC: nop

    // 0x80065CD0: sb          $t6, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r14;
    // 0x80065CD4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065CD8: nop

    // 0x80065CDC: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80065CE0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80065CE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80065CE8: jal         0x800657C4
    // 0x80065CEC: nop

    _timeToSamples(rdram, ctx);
        goto after_2;
    // 0x80065CEC: nop

    after_2:
    // 0x80065CF0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065CF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065CF8: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80065CFC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80065D00: nop

    // 0x80065D04: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x80065D08: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80065D0C: nop

    // 0x80065D10: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80065D14: nop

    // 0x80065D18: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80065D1C: nop

    // 0x80065D20: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065D24: nop

    // 0x80065D28: jalr        $t9
    // 0x80065D2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80065D2C: nop

    after_3:
L_80065D30:
    // 0x80065D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065D34:
    // 0x80065D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065D38: jr          $ra
    // 0x80065D3C: nop

    return;
    // 0x80065D3C: nop

;}
RECOMP_FUNC void alCSPGetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7890: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800C7894: bnel        $v1, $zero, L_800C78A8
    if (ctx->r3 != 0) {
        // 0x800C7898: lw          $t6, 0x24($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X24);
            goto L_800C78A8;
    }
    goto skip_0;
    // 0x800C7898: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x800C789C: jr          $ra
    // 0x800C78A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C78A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C78A4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
L_800C78A8:
    // 0x800C78A8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C78AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C78B0: nop

    // 0x800C78B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C78B8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C78BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C78C0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C78C4: nop

    // 0x800C78C8: jr          $ra
    // 0x800C78CC: nop

    return;
    // 0x800C78CC: nop

;}
RECOMP_FUNC void obj_loop_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035C54: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80035C58: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80035C5C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80035C60: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80035C64: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80035C68: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80035C6C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80035C70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80035C74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80035C78: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80035C7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80035C80: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x80035C84: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80035C88: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80035C8C: nop

    // 0x80035C90: ori         $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 | 0X1000;
    // 0x80035C94: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x80035C98: jal         0x8001BAC8
    // 0x80035C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80035CA0: lw          $t0, 0x4C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4C);
    // 0x80035CA4: lw          $t2, 0x78($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X78);
    // 0x80035CA8: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80035CAC: nop

    // 0x80035CB0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035CB4: beq         $at, $zero, L_80035DFC
    if (ctx->r1 == 0) {
        // 0x80035CB8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80035DFC;
    }
    // 0x80035CB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80035CBC: jal         0x8001BA74
    // 0x80035CC0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80035CC0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80035CC4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80035CC8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80035CCC: blez        $t3, L_80035DF8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80035CD0: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80035DF8;
    }
    // 0x80035CD0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80035CD4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80035CD8: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_80035CDC:
    // 0x80035CDC: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x80035CE0: nop

    // 0x80035CE4: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80035CE8: nop

    // 0x80035CEC: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035CF0: nop

    // 0x80035CF4: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x80035CF8: beq         $at, $zero, L_80035DE8
    if (ctx->r1 == 0) {
        // 0x80035CFC: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035DE8;
    }
    // 0x80035CFC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D00: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80035D04: nop

    // 0x80035D08: beq         $t5, $zero, L_80035DE8
    if (ctx->r13 == 0) {
        // 0x80035D0C: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035DE8;
    }
    // 0x80035D0C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D10: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80035D14: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80035D18: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80035D1C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035D20: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80035D24: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035D28: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035D2C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80035D30: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80035D34: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035D38: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035D3C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035D40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035D44: jal         0x800C9AD0
    // 0x80035D48: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035D48: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035D4C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80035D50: lw          $t8, 0x78($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X78);
    // 0x80035D54: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80035D58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035D5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035D60: nop

    // 0x80035D64: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035D68: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80035D6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80035D70: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80035D74: beq         $at, $zero, L_80035DE8
    if (ctx->r1 == 0) {
        // 0x80035D78: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035DE8;
    }
    // 0x80035D78: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D7C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80035D80: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80035D84: beq         $s5, $t9, L_80035DA0
    if (ctx->r21 == ctx->r25) {
        // 0x80035D88: nop
    
            goto L_80035DA0;
    }
    // 0x80035D88: nop

    // 0x80035D8C: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80035D90: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80035D94: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80035D98: jal         0x80001EA8
    // 0x80035D9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x80035D9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
L_80035DA0:
    // 0x80035DA0: jal         0x8000C8B4
    // 0x80035DA4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x80035DA4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_4:
    // 0x80035DA8: lbu         $t0, 0x20C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X20C);
    // 0x80035DAC: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80035DB0: beq         $t0, $zero, L_80035DC8
    if (ctx->r8 == 0) {
        // 0x80035DB4: sb          $s6, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r22;
            goto L_80035DC8;
    }
    // 0x80035DB4: sb          $s6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r22;
    // 0x80035DB8: lb          $t1, 0x203($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X203);
    // 0x80035DBC: nop

    // 0x80035DC0: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80035DC4: sb          $t2, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r10;
L_80035DC8:
    // 0x80035DC8: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x80035DCC: nop

    // 0x80035DD0: bne         $t3, $zero, L_80035DE8
    if (ctx->r11 != 0) {
        // 0x80035DD4: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035DE8;
    }
    // 0x80035DD4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035DD8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80035DDC: jal         0x80072348
    // 0x80035DE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_5;
    // 0x80035DE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80035DE4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_80035DE8:
    // 0x80035DE8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80035DEC: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035DF0: bne         $at, $zero, L_80035CDC
    if (ctx->r1 != 0) {
        // 0x80035DF4: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80035CDC;
    }
    // 0x80035DF4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80035DF8:
    // 0x80035DF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80035DFC:
    // 0x80035DFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80035E00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80035E04: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80035E08: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80035E0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80035E10: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80035E14: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80035E18: jr          $ra
    // 0x80035E1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80035E1C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7D0C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C7D10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7D14: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800C7D18: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C7D1C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800C7D20: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C7D24: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C7D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7D2C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_800C7D30:
    // 0x800C7D30: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800C7D34: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C7D38: beql        $t8, $zero, L_800C7D7C
    if (ctx->r24 == 0) {
        // 0x800C7D3C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C7D7C;
    }
    goto skip_0;
    // 0x800C7D3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C7D40: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x800C7D44: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C7D48: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800C7D4C: beql        $t6, $zero, L_800C7D64
    if (ctx->r14 == 0) {
        // 0x800C7D50: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_800C7D64;
    }
    goto skip_1;
    // 0x800C7D50: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x800C7D54: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x800C7D58: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800C7D5C: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800C7D60: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_800C7D64:
    // 0x800C7D64: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800C7D68: beql        $at, $zero, L_800C7D7C
    if (ctx->r1 == 0) {
        // 0x800C7D6C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C7D7C;
    }
    goto skip_2;
    // 0x800C7D6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800C7D70: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800C7D74: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800C7D78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C7D7C:
    // 0x800C7D7C: bnel        $v0, $a1, L_800C7D30
    if (ctx->r2 != ctx->r5) {
        // 0x800C7D80: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_800C7D30;
    }
    goto skip_3;
    // 0x800C7D80: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x800C7D84: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7D88: jal         0x800C7BE0
    // 0x800C7D8C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_0;
    // 0x800C7D8C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C7D90: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C7D94: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800C7D98: bne         $v0, $at, L_800C7F04
    if (ctx->r2 != ctx->r1) {
        // 0x800C7D9C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C7F04;
    }
    // 0x800C7D9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C7DA0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7DA4: jal         0x800C7BE0
    // 0x800C7DA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_1;
    // 0x800C7DA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C7DAC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C7DB0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800C7DB4: bne         $v0, $at, L_800C7E08
    if (ctx->r2 != ctx->r1) {
        // 0x800C7DB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C7E08;
    }
    // 0x800C7DB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C7DBC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C7DC0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C7DC4: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C7DC8: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800C7DCC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7DD0: jal         0x800C7BE0
    // 0x800C7DD4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_2;
    // 0x800C7DD4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800C7DD8: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800C7DDC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7DE0: jal         0x800C7BE0
    // 0x800C7DE4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_3;
    // 0x800C7DE4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800C7DE8: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800C7DEC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7DF0: jal         0x800C7BE0
    // 0x800C7DF4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_4;
    // 0x800C7DF4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800C7DF8: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800C7DFC: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C7E00: b           L_800C7FA0
    // 0x800C7E04: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_800C7FA0;
    // 0x800C7E04: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800C7E08:
    // 0x800C7E08: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800C7E0C: bnel        $v1, $at, L_800C7E48
    if (ctx->r3 != ctx->r1) {
        // 0x800C7E10: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800C7E48;
    }
    goto skip_4;
    // 0x800C7E10: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x800C7E14: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800C7E18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C7E1C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800C7E20: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800C7E24: beq         $t6, $zero, L_800C7E38
    if (ctx->r14 == 0) {
        // 0x800C7E28: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800C7E38;
    }
    // 0x800C7E28: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800C7E2C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800C7E30: b           L_800C7FA0
    // 0x800C7E34: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C7FA0;
    // 0x800C7E34: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C7E38:
    // 0x800C7E38: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C7E3C: b           L_800C7FA0
    // 0x800C7E40: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_800C7FA0;
    // 0x800C7E40: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C7E44: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800C7E48:
    // 0x800C7E48: bne         $v1, $at, L_800C7E78
    if (ctx->r3 != ctx->r1) {
        // 0x800C7E4C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C7E78;
    }
    // 0x800C7E4C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7E50: jal         0x800C7BE0
    // 0x800C7E54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_5;
    // 0x800C7E54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800C7E58: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7E5C: jal         0x800C7BE0
    // 0x800C7E60: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_6;
    // 0x800C7E60: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800C7E64: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C7E68: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C7E6C: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800C7E70: b           L_800C7FA0
    // 0x800C7E74: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C7FA0;
    // 0x800C7E74: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C7E78:
    // 0x800C7E78: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800C7E7C: bne         $v1, $at, L_800C7FA0
    if (ctx->r3 != ctx->r1) {
        // 0x800C7E80: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_800C7FA0;
    }
    // 0x800C7E80: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800C7E84: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x800C7E88: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x800C7E8C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C7E90: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C7E94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7E98: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800C7E9C: bne         $a0, $zero, L_800C7EB0
    if (ctx->r4 != 0) {
        // 0x800C7EA0: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800C7EB0;
    }
    // 0x800C7EA0: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x800C7EA4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800C7EA8: b           L_800C7EF0
    // 0x800C7EAC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800C7EF0;
    // 0x800C7EAC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C7EB0:
    // 0x800C7EB0: beq         $a0, $at, L_800C7EBC
    if (ctx->r4 == ctx->r1) {
        // 0x800C7EB4: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800C7EBC;
    }
    // 0x800C7EB4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800C7EB8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800C7EBC:
    // 0x800C7EBC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800C7EC0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800C7EC4: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800C7EC8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C7ECC: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800C7ED0: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C7ED4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C7ED8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C7EDC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800C7EE0: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800C7EE4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C7EE8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7EEC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C7EF0:
    // 0x800C7EF0: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C7EF4: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C7EF8: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800C7EFC: b           L_800C7FA0
    // 0x800C7F00: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C7FA0;
    // 0x800C7F00: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C7F04:
    // 0x800C7F04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C7F08: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800C7F0C: beq         $t9, $zero, L_800C7F34
    if (ctx->r25 == 0) {
        // 0x800C7F10: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_800C7F34;
    }
    // 0x800C7F10: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800C7F14: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C7F18: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7F1C: jal         0x800C7BE0
    // 0x800C7F20: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_7;
    // 0x800C7F20: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800C7F24: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C7F28: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C7F2C: b           L_800C7F44
    // 0x800C7F30: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_800C7F44;
    // 0x800C7F30: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_800C7F34:
    // 0x800C7F34: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800C7F38: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x800C7F3C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C7F40: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_800C7F44:
    // 0x800C7F44: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800C7F48: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800C7F4C: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800C7F50: beq         $t9, $at, L_800C7F9C
    if (ctx->r25 == ctx->r1) {
        // 0x800C7F54: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800C7F9C;
    }
    // 0x800C7F54: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800C7F58: beq         $t9, $at, L_800C7F9C
    if (ctx->r25 == ctx->r1) {
        // 0x800C7F5C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C7F9C;
    }
    // 0x800C7F5C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C7F60: jal         0x800C7BE0
    // 0x800C7F64: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_8;
    // 0x800C7F64: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800C7F68: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800C7F6C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800C7F70: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800C7F74: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x800C7F78: bne         $t8, $at, L_800C7FA0
    if (ctx->r24 != ctx->r1) {
        // 0x800C7F7C: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_800C7FA0;
    }
    // 0x800C7F7C: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C7F80: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C7F84: jal         0x800C7CA4
    // 0x800C7F88: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    static_3_800C7CA4(rdram, ctx);
        goto after_9;
    // 0x800C7F88: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x800C7F8C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C7F90: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C7F94: b           L_800C7FA0
    // 0x800C7F98: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_800C7FA0;
    // 0x800C7F98: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800C7F9C:
    // 0x800C7F9C: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_800C7FA0:
    // 0x800C7FA0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800C7FA4: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x800C7FA8: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x800C7FAC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C7FB0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800C7FB4: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x800C7FB8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800C7FBC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C7FC0: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800C7FC4: beql        $t6, $at, L_800C7FE4
    if (ctx->r14 == ctx->r1) {
        // 0x800C7FC8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C7FE4;
    }
    goto skip_5;
    // 0x800C7FC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x800C7FCC: jal         0x800C7CA4
    // 0x800C7FD0: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    static_3_800C7CA4(rdram, ctx);
        goto after_10;
    // 0x800C7FD0: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800C7FD4: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x800C7FD8: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C7FDC: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x800C7FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800C7FE4:
    // 0x800C7FE4: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x800C7FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7FEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7FF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C7FF4: jr          $ra
    // 0x800C7FF8: nop

    return;
    // 0x800C7FF8: nop

;}
RECOMP_FUNC void menu_logo_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082B88: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082B8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082B94: bne         $t6, $zero, L_80082C18
    if (ctx->r14 != 0) {
        // 0x80082B98: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80082C18;
    }
    // 0x80082B98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80082B9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082BA0: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082BA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082BA8: lwc1        $f4, -0x7C74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C74);
    // 0x80082BAC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80082BB0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80082BB4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80082BB8: bc1f        L_80082BF0
    if (!c1cs) {
        // 0x80082BBC: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80082BF0;
    }
    // 0x80082BBC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80082BC0: lw          $t8, -0xB84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB84);
    // 0x80082BC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082BC8: bne         $t8, $zero, L_80082BF4
    if (ctx->r24 != 0) {
        // 0x80082BCC: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80082BF4;
    }
    // 0x80082BCC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80082BD0: jal         0x800C01D8
    // 0x80082BD4: addiu       $a0, $a0, 0x1DE8
    ctx->r4 = ADD32(ctx->r4, 0X1DE8);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80082BD4: addiu       $a0, $a0, 0x1DE8
    ctx->r4 = ADD32(ctx->r4, 0X1DE8);
    after_0:
    // 0x80082BD8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80082BDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082BE0: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    // 0x80082BE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082BE8: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082BEC: nop

L_80082BF0:
    // 0x80082BF0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80082BF4:
    // 0x80082BF4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80082BF8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80082BFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082C00: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80082C04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082C08: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80082C0C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80082C10: b           L_80082C90
    // 0x80082C14: swc1        $f18, 0x6450($at)
    MEM_W(0X6450, ctx->r1) = ctx->f18.u32l;
        goto L_80082C90;
    // 0x80082C14: swc1        $f18, 0x6450($at)
    MEM_W(0X6450, ctx->r1) = ctx->f18.u32l;
L_80082C18:
    // 0x80082C18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082C1C: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082C20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082C24: lwc1        $f4, -0x7C70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C70);
    // 0x80082C28: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80082C2C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80082C30: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80082C34: bc1f        L_80082C70
    if (!c1cs) {
        // 0x80082C38: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_80082C70;
    }
    // 0x80082C38: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80082C3C: lw          $t1, -0xB84($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB84);
    // 0x80082C40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80082C44: bne         $t1, $zero, L_80082C70
    if (ctx->r9 != 0) {
        // 0x80082C48: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_80082C70;
    }
    // 0x80082C48: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80082C4C: jal         0x800C01D8
    // 0x80082C50: addiu       $a0, $a0, 0x1DE8
    ctx->r4 = ADD32(ctx->r4, 0X1DE8);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x80082C50: addiu       $a0, $a0, 0x1DE8
    ctx->r4 = ADD32(ctx->r4, 0X1DE8);
    after_1:
    // 0x80082C54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80082C58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082C5C: sw          $t2, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r10;
    // 0x80082C60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082C64: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082C68: nop

    // 0x80082C6C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_80082C70:
    // 0x80082C70: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80082C74: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80082C78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082C7C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80082C80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082C84: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80082C88: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80082C8C: swc1        $f18, 0x6450($at)
    MEM_W(0X6450, ctx->r1) = ctx->f18.u32l;
L_80082C90:
    // 0x80082C90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082C94: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082C98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80082C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082CA0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80082CA4: nop

    // 0x80082CA8: bc1f        L_80082CF4
    if (!c1cs) {
        // 0x80082CAC: lui         $at, 0x4021
        ctx->r1 = S32(0X4021 << 16);
            goto L_80082CF4;
    }
    // 0x80082CAC: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80082CB0: jal         0x80066894
    // 0x80082CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x80082CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80082CB8: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x80082CBC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80082CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082CC4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082CC8: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082CCC: jal         0x80066AA8
    // 0x80082CD0: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x80082CD0: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x80082CD4: jal         0x80082FAC
    // 0x80082CD8: nop

    init_title_screen_variables(rdram, ctx);
        goto after_4;
    // 0x80082CD8: nop

    after_4:
    // 0x80082CDC: jal         0x800813D0
    // 0x80082CE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_5;
    // 0x80082CE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80082CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082CE8: lwc1        $f0, 0x6450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082CEC: nop

    // 0x80082CF0: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
L_80082CF4:
    // 0x80082CF4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80082CF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80082CFC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80082D00: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80082D04: nop

    // 0x80082D08: bc1f        L_80082FA0
    if (!c1cs) {
        // 0x80082D0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80082FA0;
    }
    // 0x80082D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082D10: jal         0x800C42EC
    // 0x80082D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x80082D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80082D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082D20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082D24: jal         0x800C43CC
    // 0x80082D28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_7;
    // 0x80082D28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x80082D2C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80082D30: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80082D34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082D38: lwc1        $f10, 0x6450($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082D3C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80082D40: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80082D44: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80082D48: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x80082D4C: bc1f        L_80082DB0
    if (!c1cs) {
        // 0x80082D50: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80082DB0;
    }
    // 0x80082D50: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80082D54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80082D58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80082D5C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082D60: c.le.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d <= ctx->f0.d;
    // 0x80082D64: nop

    // 0x80082D68: bc1f        L_80082DB0
    if (!c1cs) {
        // 0x80082D6C: nop
    
            goto L_80082DB0;
    }
    // 0x80082D6C: nop

    // 0x80082D70: sub.d       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f12.d - ctx->f0.d;
    // 0x80082D74: lwc1        $f5, -0x7C68($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X7C68);
    // 0x80082D78: lwc1        $f4, -0x7C64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C64);
    // 0x80082D7C: nop

    // 0x80082D80: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80082D84: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80082D88: nop

    // 0x80082D8C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80082D90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082D94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082D98: nop

    // 0x80082D9C: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x80082DA0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80082DA4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80082DA8: b           L_80082E2C
    // 0x80082DAC: nop

        goto L_80082E2C;
    // 0x80082DAC: nop

L_80082DB0:
    // 0x80082DB0: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x80082DB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80082DB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80082DBC: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80082DC0: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80082DC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80082DC8: bc1f        L_80082E2C
    if (!c1cs) {
        // 0x80082DCC: nop
    
            goto L_80082E2C;
    }
    // 0x80082DCC: nop

    // 0x80082DD0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80082DD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80082DD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082DDC: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80082DE0: nop

    // 0x80082DE4: bc1f        L_80082E2C
    if (!c1cs) {
        // 0x80082DE8: nop
    
            goto L_80082E2C;
    }
    // 0x80082DE8: nop

    // 0x80082DEC: sub.d       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f0.d - ctx->f2.d;
    // 0x80082DF0: lwc1        $f19, -0x7C60($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7C60);
    // 0x80082DF4: lwc1        $f18, -0x7C5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7C5C);
    // 0x80082DF8: nop

    // 0x80082DFC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80082E00: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80082E04: nop

    // 0x80082E08: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80082E0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082E10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082E14: nop

    // 0x80082E18: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80082E1C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80082E20: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80082E24: b           L_80082E2C
    // 0x80082E28: nop

        goto L_80082E2C;
    // 0x80082E28: nop

L_80082E2C:
    // 0x80082E2C: beq         $v0, $zero, L_80082EFC
    if (ctx->r2 == 0) {
        // 0x80082E30: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80082EFC;
    }
    // 0x80082E30: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80082E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082E38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80082E3C: jal         0x800C4384
    // 0x80082E40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80082E40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80082E44: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80082E48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082E4C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80082E50: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80082E54: addiu       $a2, $a2, 0xD4
    ctx->r6 = ADD32(ctx->r6, 0XD4);
    // 0x80082E58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80082E5C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082E60: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, 0X1DF0);
    // 0x80082E64: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80082E68: jal         0x800C4440
    // 0x80082E6C: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x80082E6C: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    after_9:
    // 0x80082E70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082E74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80082E78: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80082E7C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80082E80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80082E84: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, 0X1DF0);
    // 0x80082E88: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80082E8C: jal         0x800C4440
    // 0x80082E90: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80082E90: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    after_10:
    // 0x80082E94: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80082E98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082E9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80082EA0: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80082EA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80082EA8: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, 0X1DF0);
    // 0x80082EAC: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80082EB0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80082EB4: jal         0x800C4440
    // 0x80082EB8: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80082EB8: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    after_11:
    // 0x80082EBC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80082EC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082EC4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80082EC8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80082ECC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082ED0: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, 0X1DF0);
    // 0x80082ED4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80082ED8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80082EDC: jal         0x800C4440
    // 0x80082EE0: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80082EE0: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    after_12:
    // 0x80082EE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082EE8: lwc1        $f8, 0x6450($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6450);
    // 0x80082EEC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80082EF0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80082EF4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80082EF8: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_80082EFC:
    // 0x80082EFC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80082F00: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80082F04: addiu       $t2, $t1, 0xD4
    ctx->r10 = ADD32(ctx->r9, 0XD4);
    // 0x80082F08: bc1f        L_80082F5C
    if (!c1cs) {
        // 0x80082F0C: sw          $t2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r10;
            goto L_80082F5C;
    }
    // 0x80082F0C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80082F10: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80082F14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80082F18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80082F1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082F20: lwc1        $f19, -0x7C58($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7C58);
    // 0x80082F24: lwc1        $f18, -0x7C54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7C54);
    // 0x80082F28: sub.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d - ctx->f0.d;
    // 0x80082F2C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80082F30: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80082F34: nop

    // 0x80082F38: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80082F3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082F40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082F44: nop

    // 0x80082F48: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80082F4C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80082F50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80082F54: b           L_80082F64
    // 0x80082F58: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_80082F64;
    // 0x80082F58: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80082F5C:
    // 0x80082F5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082F60: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80082F64:
    // 0x80082F64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80082F68: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082F6C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80082F70: jal         0x800C4384
    // 0x80082F74: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80082F74: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
    // 0x80082F78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80082F7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80082F80: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80082F84: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80082F88: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80082F8C: addiu       $a3, $a3, 0x1DF0
    ctx->r7 = ADD32(ctx->r7, 0X1DF0);
    // 0x80082F90: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80082F94: jal         0x800C4440
    // 0x80082F98: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x80082F98: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_14:
    // 0x80082F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80082FA0:
    // 0x80082FA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80082FA4: jr          $ra
    // 0x80082FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80082FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void transform_player_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E2B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E2B8: addiu       $v1, $v1, -0x52BC
    ctx->r3 = ADD32(ctx->r3, -0X52BC);
    // 0x8000E2BC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E2C4: beq         $v0, $zero, L_8000E4AC
    if (ctx->r2 == 0) {
        // 0x8000E2C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E4AC;
    }
    // 0x8000E2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E2CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000E2D0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8000E2D4: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2D8: nop

    // 0x8000E2DC: bne         $t7, $zero, L_8000E4B0
    if (ctx->r15 != 0) {
        // 0x8000E2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E4B0;
    }
    // 0x8000E2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2E4: jal         0x8006EA90
    // 0x8000E2E8: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000E2E8: nop

    after_0:
    // 0x8000E2EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000E2F0: lb          $a0, -0x52BB($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X52BB);
    // 0x8000E2F4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000E2F8: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8000E2FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8000E300: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x8000E304: beq         $at, $zero, L_8000E338
    if (ctx->r1 == 0) {
        // 0x8000E308: sb          $t8, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r24;
            goto L_8000E338;
    }
    // 0x8000E308: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E30C: lb          $t9, 0x59($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X59);
    // 0x8000E310: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8000E314: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8000E318: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000E31C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000E320: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8000E324: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E328: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8000E32C: lh          $v1, -0x3858($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X3858);
    // 0x8000E330: b           L_8000E34C
    // 0x8000E334: nop

        goto L_8000E34C;
    // 0x8000E334: nop

L_8000E338:
    // 0x8000E338: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8000E33C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E340: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8000E344: lh          $v1, -0x37FE($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X37FE);
    // 0x8000E348: nop

L_8000E34C:
    // 0x8000E34C: jal         0x8006DB14
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    set_level_default_vehicle(rdram, ctx);
        goto after_1;
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000E354: lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X22);
    // 0x8000E358: lbu         $t5, 0x2D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2D);
    // 0x8000E35C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E360: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000E364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000E368: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8000E36C: andi        $t6, $v1, 0x100
    ctx->r14 = ctx->r3 & 0X100;
    // 0x8000E370: lh          $t9, -0x52BA($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X52BA);
    // 0x8000E374: lh          $t1, -0x52B8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X52B8);
    // 0x8000E378: lh          $t0, -0x52B6($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X52B6);
    // 0x8000E37C: lh          $t2, -0x52B4($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X52B4);
    // 0x8000E380: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000E384: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8000E388: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E38C: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x8000E390: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8000E394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000E398: sb          $v1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r3;
    // 0x8000E39C: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x8000E3A0: sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // 0x8000E3A4: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x8000E3A8: jal         0x800521B8
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_2;
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    after_2:
    // 0x8000E3B0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8000E3B4: jal         0x8000EA54
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x8000E3BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E3C0: lw          $t4, -0x511C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X511C);
    // 0x8000E3C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E3CC: sw          $t3, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r11;
    // 0x8000E3D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E3D4: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x8000E3D8: lw          $t6, -0x5114($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5114);
    // 0x8000E3DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E3E0: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000E3E4: lw          $t5, -0x5118($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5118);
    // 0x8000E3E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E3EC: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000E3F0: addiu       $a1, $a1, -0x52BB
    ctx->r5 = ADD32(ctx->r5, -0X52BB);
    // 0x8000E3F4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000E3F8: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8000E3FC: nop

    // 0x8000E400: sb          $t7, 0x1D6($v1)
    MEM_B(0X1D6, ctx->r3) = ctx->r15;
    // 0x8000E404: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8000E408: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000E40C: sb          $t8, 0x1D7($v1)
    MEM_B(0X1D7, ctx->r3) = ctx->r24;
    // 0x8000E410: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000E414: nop

    // 0x8000E418: lb          $t1, 0x59($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X59);
    // 0x8000E41C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000E420: sw          $zero, 0x118($v1)
    MEM_W(0X118, ctx->r3) = 0;
    // 0x8000E424: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x8000E428: jal         0x8009C30C
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000E430: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E434: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x8000E438: beq         $t0, $zero, L_8000E454
    if (ctx->r8 == 0) {
        // 0x8000E43C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000E454;
    }
    // 0x8000E43C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E440: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E444: lwc1        $f6, 0x51AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51AC);
    // 0x8000E448: nop

    // 0x8000E44C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000E450: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8000E454:
    // 0x8000E454: jal         0x8009C30C
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_5;
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_5:
    // 0x8000E45C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E460: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x8000E464: beq         $t2, $zero, L_8000E484
    if (ctx->r10 == 0) {
        // 0x8000E468: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8000E484;
    }
    // 0x8000E468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E46C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E470: lwc1        $f16, 0x51B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X51B0);
    // 0x8000E474: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E478: nop

    // 0x8000E47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000E480: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_8000E484:
    // 0x8000E484: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8000E488: lh          $t3, -0x52B4($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X52B4);
    // 0x8000E48C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E490: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8000E494: lh          $t4, -0x52B8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X52B8);
    // 0x8000E498: nop

    // 0x8000E49C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000E4A0: nop

    // 0x8000E4A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E4A8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_8000E4AC:
    // 0x8000E4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E4B0:
    // 0x8000E4B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000E4B4: jr          $ra
    // 0x8000E4B8: nop

    return;
    // 0x8000E4B8: nop

;}
RECOMP_FUNC void waves_visibility_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8B94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8B98: sw          $zero, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = 0;
    // 0x800B8B9C: addiu       $a1, $a1, -0x5F24
    ctx->r5 = ADD32(ctx->r5, -0X5F24);
    // 0x800B8BA0: addiu       $a0, $a0, -0x5F28
    ctx->r4 = ADD32(ctx->r4, -0X5F28);
    // 0x800B8BA4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B8BA8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B8BAC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B8BB0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8BB4: addiu       $a2, $a2, 0x30D4
    ctx->r6 = ADD32(ctx->r6, 0X30D4);
    // 0x800B8BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B8BBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B8BC0: mflo        $t8
    ctx->r24 = lo;
    // 0x800B8BC4: blez        $t8, L_800B8BFC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B8BC8: nop
    
            goto L_800B8BFC;
    }
    // 0x800B8BC8: nop

L_800B8BCC:
    // 0x800B8BCC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B8BD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B8BD4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B8BD8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800B8BDC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B8BE0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800B8BE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B8BE8: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8BEC: mflo        $t3
    ctx->r11 = lo;
    // 0x800B8BF0: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B8BF4: bne         $at, $zero, L_800B8BCC
    if (ctx->r1 != 0) {
        // 0x800B8BF8: nop
    
            goto L_800B8BCC;
    }
    // 0x800B8BF8: nop

L_800B8BFC:
    // 0x800B8BFC: jr          $ra
    // 0x800B8C00: nop

    return;
    // 0x800B8C00: nop

;}
RECOMP_FUNC void debug_text_parse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B653C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B6540: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B6544: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B6548: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B654C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B6550: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B6554: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B6558: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B655C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B6560: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B6564: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B6568: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B656C: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6570: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B6574: beq         $s1, $zero, L_800B6924
    if (ctx->r17 == 0) {
        // 0x800B6578: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_800B6924;
    }
    // 0x800B6578: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x800B657C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800B6580: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x800B6584: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800B6588: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800B658C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800B6590: addiu       $s2, $s2, 0x7CAC
    ctx->r18 = ADD32(ctx->r18, 0X7CAC);
    // 0x800B6594: addiu       $s4, $s4, 0x7CAE
    ctx->r20 = ADD32(ctx->r20, 0X7CAE);
    // 0x800B6598: addiu       $s6, $s6, 0x7CB0
    ctx->r22 = ADD32(ctx->r22, 0X7CB0);
    // 0x800B659C: addiu       $s7, $s7, 0x7CB2
    ctx->r23 = ADD32(ctx->r23, 0X7CB2);
    // 0x800B65A0: addiu       $fp, $fp, 0x7CB8
    ctx->r30 = ADD32(ctx->r30, 0X7CB8);
    // 0x800B65A4: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B65A8:
    // 0x800B65A8: bne         $at, $zero, L_800B65F4
    if (ctx->r1 != 0) {
        // 0x800B65AC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B65F4;
    }
    // 0x800B65AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B65B0: slti        $at, $s1, 0x21
    ctx->r1 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x800B65B4: bne         $at, $zero, L_800B65E0
    if (ctx->r1 != 0) {
        // 0x800B65B8: addiu       $t6, $s1, -0x81
        ctx->r14 = ADD32(ctx->r17, -0X81);
            goto L_800B65E0;
    }
    // 0x800B65B8: addiu       $t6, $s1, -0x81
    ctx->r14 = ADD32(ctx->r17, -0X81);
    // 0x800B65BC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800B65C0: beq         $at, $zero, L_800B687C
    if (ctx->r1 == 0) {
        // 0x800B65C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B687C;
    }
    // 0x800B65C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B65C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B65CC: addu        $at, $at, $t6
    gpr jr_addend_800B65D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B65D0: lw          $t6, -0x71A8($at)
    ctx->r14 = ADD32(ctx->r1, -0X71A8);
    // 0x800B65D4: nop

    // 0x800B65D8: jr          $t6
    // 0x800B65DC: nop

    switch (jr_addend_800B65D8 >> 2) {
        case 0: goto L_800B6658; break;
        case 1: goto L_800B6740; break;
        case 2: goto L_800B6614; break;
        case 3: goto L_800B6634; break;
        case 4: goto L_800B66CC; break;
        default: switch_error(__func__, 0x800B65D8, 0x800E8E58);
    }
    // 0x800B65DC: nop

L_800B65E0:
    // 0x800B65E0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B65E4: beq         $s1, $at, L_800B67C4
    if (ctx->r17 == ctx->r1) {
        // 0x800B65E8: addiu       $s3, $zero, 0x6
        ctx->r19 = ADD32(0, 0X6);
            goto L_800B67C4;
    }
    // 0x800B65E8: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800B65EC: b           L_800B6880
    // 0x800B65F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6880;
    // 0x800B65F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B65F4:
    // 0x800B65F4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B65F8: beq         $s1, $at, L_800B683C
    if (ctx->r17 == ctx->r1) {
        // 0x800B65FC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800B683C;
    }
    // 0x800B65FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6600: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B6604: beq         $s1, $at, L_800B67E0
    if (ctx->r17 == ctx->r1) {
        // 0x800B6608: nop
    
            goto L_800B67E0;
    }
    // 0x800B6608: nop

    // 0x800B660C: b           L_800B6880
    // 0x800B6610: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6880;
    // 0x800B6610: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6614:
    // 0x800B6614: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6618: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B661C: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B6620: sw          $zero, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = 0;
    // 0x800B6624: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6628: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B662C: b           L_800B68A4
    // 0x800B6630: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B6630: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6634:
    // 0x800B6634: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B6638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B663C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6640: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B6644: sw          $t7, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = ctx->r15;
    // 0x800B6648: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B664C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B6650: b           L_800B68A4
    // 0x800B6654: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B6654: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6658:
    // 0x800B6658: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B665C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6660: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6664: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6668: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B666C: beq         $t8, $zero, L_800B66B0
    if (ctx->r24 == 0) {
        // 0x800B6670: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B66B0;
    }
    // 0x800B6670: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6674: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B6678: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x800B667C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800B6680: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x800B6684: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B6688: sll         $t2, $a0, 24
    ctx->r10 = S32(ctx->r4 << 24);
    // 0x800B668C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800B6690: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800B6694: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800B6698: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x800B669C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800B66A0: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x800B66A4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800B66A8: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800B66AC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_800B66B0:
    // 0x800B66B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B66B4: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B66B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B66BC: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B66C0: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B66C4: b           L_800B68A4
    // 0x800B66C8: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B66C8: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B66CC:
    // 0x800B66CC: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800B66D0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B66D4: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B66D8: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B66DC: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B66E0: bne         $t1, $zero, L_800B6724
    if (ctx->r9 != 0) {
        // 0x800B66E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B6724;
    }
    // 0x800B66E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B66E8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B66EC: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800B66F0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800B66F4: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x800B66F8: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B66FC: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B6700: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800B6704: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800B6708: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B670C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800B6710: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800B6714: andi        $t3, $a3, 0xFF
    ctx->r11 = ctx->r7 & 0XFF;
    // 0x800B6718: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B671C: or          $t2, $t1, $t3
    ctx->r10 = ctx->r9 | ctx->r11;
    // 0x800B6720: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_800B6724:
    // 0x800B6724: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6728: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B672C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6730: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B6734: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6738: b           L_800B68A4
    // 0x800B673C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B673C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6740:
    // 0x800B6740: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800B6744: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6748: bne         $t4, $zero, L_800B676C
    if (ctx->r12 != 0) {
        // 0x800B674C: nop
    
            goto L_800B676C;
    }
    // 0x800B674C: nop

    // 0x800B6750: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6754: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6758: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B675C: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6760: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6764: jal         0x800B695C
    // 0x800B6768: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_0;
    // 0x800B6768: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
L_800B676C:
    // 0x800B676C: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6770: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6774: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800B6778: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800B677C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6780: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x800B6784: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800B6788: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x800B678C: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6790: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x800B6794: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    // 0x800B6798: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x800B679C: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B67A0: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B67A4: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800B67A8: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x800B67AC: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x800B67B0: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B67B4: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B67B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B67BC: b           L_800B68A4
    // 0x800B67C0: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B67C0: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B67C4:
    // 0x800B67C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B67C8: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B67CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B67D0: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B67D4: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B67D8: b           L_800B68A4
    // 0x800B67DC: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B67DC: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B67E0:
    // 0x800B67E0: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B67E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B67E8: bne         $t8, $zero, L_800B680C
    if (ctx->r24 != 0) {
        // 0x800B67EC: nop
    
            goto L_800B680C;
    }
    // 0x800B67EC: nop

    // 0x800B67F0: lhu         $t9, 0x0($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X0);
    // 0x800B67F4: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B67F8: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B67FC: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6800: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x800B6804: jal         0x800B695C
    // 0x800B6808: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    debug_text_background(rdram, ctx);
        goto after_1;
    // 0x800B6808: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
L_800B680C:
    // 0x800B680C: jal         0x800B6F04
    // 0x800B6810: nop

    debug_text_newline(rdram, ctx);
        goto after_2;
    // 0x800B6810: nop

    after_2:
    // 0x800B6814: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6818: lhu         $t1, 0x0($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X0);
    // 0x800B681C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6820: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B6824: sh          $t1, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r9;
    // 0x800B6828: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B682C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6830: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B6834: b           L_800B68A4
    // 0x800B6838: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B68A4;
    // 0x800B6838: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B683C:
    // 0x800B683C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6840: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6844: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B6848: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B684C: bgez        $a0, L_800B6860
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800B6850: andi        $v0, $a0, 0x1F
        ctx->r2 = ctx->r4 & 0X1F;
            goto L_800B6860;
    }
    // 0x800B6850: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x800B6854: beq         $v0, $zero, L_800B6860
    if (ctx->r2 == 0) {
        // 0x800B6858: nop
    
            goto L_800B6860;
    }
    // 0x800B6858: nop

    // 0x800B685C: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_800B6860:
    // 0x800B6860: bne         $v0, $zero, L_800B6870
    if (ctx->r2 != 0) {
        // 0x800B6864: addiu       $a1, $a1, -0x10
        ctx->r5 = ADD32(ctx->r5, -0X10);
            goto L_800B6870;
    }
    // 0x800B6864: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800B6868: b           L_800B68A4
    // 0x800B686C: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
        goto L_800B68A4;
    // 0x800B686C: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
L_800B6870:
    // 0x800B6870: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800B6874: b           L_800B68A4
    // 0x800B6878: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
        goto L_800B68A4;
    // 0x800B6878: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
L_800B687C:
    // 0x800B687C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6880:
    // 0x800B6880: jal         0x800B69FC
    // 0x800B6884: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    debug_text_character(rdram, ctx);
        goto after_3;
    // 0x800B6884: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800B6888: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B688C: lhu         $a1, 0x7CD0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CD0);
    // 0x800B6890: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B6894: lw          $v1, 0x7CB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CB4);
    // 0x800B6898: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B689C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B68A0: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B68A4:
    // 0x800B68A4: beq         $v1, $zero, L_800B68C0
    if (ctx->r3 == 0) {
        // 0x800B68A8: slti        $at, $s1, 0x20
        ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
            goto L_800B68C0;
    }
    // 0x800B68A8: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800B68AC: bne         $at, $zero, L_800B68C0
    if (ctx->r1 != 0) {
        // 0x800B68B0: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_800B68C0;
    }
    // 0x800B68B0: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x800B68B4: beq         $at, $zero, L_800B68C4
    if (ctx->r1 == 0) {
        // 0x800B68B8: addu        $t4, $a0, $s3
        ctx->r12 = ADD32(ctx->r4, ctx->r19);
            goto L_800B68C4;
    }
    // 0x800B68B8: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
    // 0x800B68BC: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_800B68C0:
    // 0x800B68C0: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
L_800B68C4:
    // 0x800B68C4: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x800B68C8: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B68CC: beq         $at, $zero, L_800B6914
    if (ctx->r1 == 0) {
        // 0x800B68D0: sh          $t4, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r12;
            goto L_800B6914;
    }
    // 0x800B68D0: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
    // 0x800B68D4: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B68D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B68DC: bne         $t2, $zero, L_800B68FC
    if (ctx->r10 != 0) {
        // 0x800B68E0: nop
    
            goto L_800B68FC;
    }
    // 0x800B68E0: nop

    // 0x800B68E4: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B68E8: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B68EC: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B68F0: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B68F4: jal         0x800B695C
    // 0x800B68F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_4;
    // 0x800B68F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
L_800B68FC:
    // 0x800B68FC: jal         0x800B6F04
    // 0x800B6900: nop

    debug_text_newline(rdram, ctx);
        goto after_5;
    // 0x800B6900: nop

    after_5:
    // 0x800B6904: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6908: lhu         $t8, 0x0($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X0);
    // 0x800B690C: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x800B6910: sh          $t8, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r24;
L_800B6914:
    // 0x800B6914: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6918: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B691C: bne         $s1, $zero, L_800B65A8
    if (ctx->r17 != 0) {
        // 0x800B6920: slti        $at, $s1, 0xB
        ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
            goto L_800B65A8;
    }
    // 0x800B6920: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B6924:
    // 0x800B6924: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B6928: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B692C: subu        $v0, $s0, $t9
    ctx->r2 = SUB32(ctx->r16, ctx->r25);
    // 0x800B6930: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B6934: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B6938: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B693C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6940: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B6944: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B6948: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B694C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6950: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B6954: jr          $ra
    // 0x800B6958: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B6958: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void thread0_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B6F54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6F58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B6F5C: addiu       $t6, $t6, -0x6A20
    ctx->r14 = ADD32(ctx->r14, -0X6A20);
    // 0x800B6F60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6F64: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800B6F68: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800B6F6C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B6F70: addiu       $a2, $a2, 0x6FC4
    ctx->r6 = ADD32(ctx->r6, 0X6FC4);
    // 0x800B6F74: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    // 0x800B6F78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B6F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B6F80: jal         0x800C8850
    // 0x800B6F84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800B6F84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800B6F88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6F8C: jal         0x800C89A0
    // 0x800B6F90: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6F90: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    after_1:
    // 0x800B6F94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6F98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B6F9C: addiu       $a0, $a0, -0x6044
    ctx->r4 = ADD32(ctx->r4, -0X6044);
    // 0x800B6FA0: addiu       $v0, $v0, -0x6050
    ctx->r2 = ADD32(ctx->r2, -0X6050);
    // 0x800B6FA4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800B6FA8:
    // 0x800B6FA8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B6FAC: bne         $v0, $a0, L_800B6FA8
    if (ctx->r2 != ctx->r4) {
        // 0x800B6FB0: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800B6FA8;
    }
    // 0x800B6FB0: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800B6FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6FB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B6FBC: jr          $ra
    // 0x800B6FC0: nop

    return;
    // 0x800B6FC0: nop

;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8760: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C8764: beql        $v0, $zero, L_800C8778
    if (ctx->r2 == 0) {
        // 0x800C8768: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800C8778;
    }
    goto skip_0;
    // 0x800C8768: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800C876C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8770: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C8774: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800C8778:
    // 0x800C8778: beq         $v0, $zero, L_800C8788
    if (ctx->r2 == 0) {
        // 0x800C877C: nop
    
            goto L_800C8788;
    }
    // 0x800C877C: nop

    // 0x800C8780: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C8784: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800C8788:
    // 0x800C8788: jr          $ra
    // 0x800C878C: nop

    return;
    // 0x800C878C: nop

;}
RECOMP_FUNC void timetrial_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800599AC: lh          $v0, -0x2A54($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A54);
    // 0x800599B0: jr          $ra
    // 0x800599B4: nop

    return;
    // 0x800599B4: nop

;}
RECOMP_FUNC void clear_object_pointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C468: sb          $v0, -0x52DA($at)
    MEM_B(-0X52DA, ctx->r1) = ctx->r2;
    // 0x8000C46C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C470: sw          $zero, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = 0;
    // 0x8000C474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C478: sw          $zero, -0x52A0($at)
    MEM_W(-0X52A0, ctx->r1) = 0;
    // 0x8000C47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C480: sw          $zero, -0x5138($at)
    MEM_W(-0X5138, ctx->r1) = 0;
    // 0x8000C484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C488: sw          $zero, -0x5190($at)
    MEM_W(-0X5190, ctx->r1) = 0;
    // 0x8000C48C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C490: sw          $zero, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = 0;
    // 0x8000C494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C498: sw          $zero, -0x512C($at)
    MEM_W(-0X512C, ctx->r1) = 0;
    // 0x8000C49C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A0: sw          $zero, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = 0;
    // 0x8000C4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A8: sh          $zero, -0x5188($at)
    MEM_H(-0X5188, ctx->r1) = 0;
    // 0x8000C4AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C4B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4B4: addiu       $a1, $a1, -0x52DE
    ctx->r5 = ADD32(ctx->r5, -0X52DE);
    // 0x8000C4B8: sb          $zero, -0x52DF($at)
    MEM_B(-0X52DF, ctx->r1) = 0;
    // 0x8000C4BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C4C0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000C4C4: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x8000C4C8: addiu       $v1, $v1, -0x50FC
    ctx->r3 = ADD32(ctx->r3, -0X50FC);
    // 0x8000C4CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000C4D0:
    // 0x8000C4D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C4D4: nop

    // 0x8000C4D8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C4DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000C4E0: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x8000C4E4: bne         $at, $zero, L_8000C4D0
    if (ctx->r1 != 0) {
        // 0x8000C4E8: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8000C4D0;
    }
    // 0x8000C4E8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8000C4EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C4F0: addiu       $a0, $a0, -0x5234
    ctx->r4 = ADD32(ctx->r4, -0X5234);
    // 0x8000C4F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C4F8:
    // 0x8000C4F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8000C4FC: nop

    // 0x8000C500: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8000C504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C508: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8000C50C: bne         $at, $zero, L_8000C4F8
    if (ctx->r1 != 0) {
        // 0x8000C510: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_8000C4F8;
    }
    // 0x8000C510: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000C514: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C518: addiu       $v1, $v1, -0x500C
    ctx->r3 = ADD32(ctx->r3, -0X500C);
    // 0x8000C51C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000C520: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
L_8000C524:
    // 0x8000C524: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000C528: nop

    // 0x8000C52C: addu        $t1, $t0, $a0
    ctx->r9 = ADD32(ctx->r8, ctx->r4);
    // 0x8000C530: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000C534: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000C538: nop

    // 0x8000C53C: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x8000C540: sw          $zero, 0x40($t3)
    MEM_W(0X40, ctx->r11) = 0;
    // 0x8000C544: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000C548: nop

    // 0x8000C54C: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8000C550: sw          $zero, 0x80($t5)
    MEM_W(0X80, ctx->r13) = 0;
    // 0x8000C554: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C558: nop

    // 0x8000C55C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C560: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x8000C564: bne         $a0, $a1, L_8000C524
    if (ctx->r4 != ctx->r5) {
        // 0x8000C568: sw          $zero, 0xC0($t7)
        MEM_W(0XC0, ctx->r15) = 0;
            goto L_8000C524;
    }
    // 0x8000C568: sw          $zero, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = 0;
    // 0x8000C56C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C570: addiu       $v1, $v1, -0x50F8
    ctx->r3 = ADD32(ctx->r3, -0X50F8);
    // 0x8000C574: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000C578: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000C57C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8000C580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C584: sw          $zero, -0x51A4($at)
    MEM_W(-0X51A4, ctx->r1) = 0;
    // 0x8000C588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C58C: sw          $zero, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = 0;
    // 0x8000C590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C594: sw          $zero, -0x519C($at)
    MEM_W(-0X519C, ctx->r1) = 0;
    // 0x8000C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C59C: sw          $zero, -0x5178($at)
    MEM_W(-0X5178, ctx->r1) = 0;
    // 0x8000C5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5A4: sb          $zero, -0x522C($at)
    MEM_B(-0X522C, ctx->r1) = 0;
    // 0x8000C5A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5AC: sh          $zero, -0x5186($at)
    MEM_H(-0X5186, ctx->r1) = 0;
    // 0x8000C5B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5B4: sb          $v0, -0x5182($at)
    MEM_B(-0X5182, ctx->r1) = ctx->r2;
    // 0x8000C5B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5BC: sh          $zero, -0x5184($at)
    MEM_H(-0X5184, ctx->r1) = 0;
    // 0x8000C5C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5C4: sb          $zero, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = 0;
    // 0x8000C5C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5CC: sb          $zero, -0x510A($at)
    MEM_B(-0X510A, ctx->r1) = 0;
    // 0x8000C5D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5D4: sb          $zero, -0x5109($at)
    MEM_B(-0X5109, ctx->r1) = 0;
    // 0x8000C5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5DC: sw          $zero, -0x50A0($at)
    MEM_W(-0X50A0, ctx->r1) = 0;
    // 0x8000C5E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5E4: sb          $zero, -0x5200($at)
    MEM_B(-0X5200, ctx->r1) = 0;
    // 0x8000C5E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5EC: sb          $v0, -0x51FF($at)
    MEM_B(-0X51FF, ctx->r1) = ctx->r2;
    // 0x8000C5F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5F4: sb          $zero, -0x52AD($at)
    MEM_B(-0X52AD, ctx->r1) = 0;
    // 0x8000C5F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5FC: jr          $ra
    // 0x8000C600: sb          $zero, -0x522B($at)
    MEM_B(-0X522B, ctx->r1) = 0;
    return;
    // 0x8000C600: sb          $zero, -0x522B($at)
    MEM_B(-0X522B, ctx->r1) = 0;
;}
RECOMP_FUNC void update_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E4C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005E4C4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005E4C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005E4CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005E4D0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005E4D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005E4D8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E4DC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005E4E0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E4E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005E4E8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005E4EC: jal         0x8005CA78
    // 0x8005E4F0: addiu       $a0, $a0, -0x31C0
    ctx->r4 = ADD32(ctx->r4, -0X31C0);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005E4F0: addiu       $a0, $a0, -0x31C0
    ctx->r4 = ADD32(ctx->r4, -0X31C0);
    after_0:
    // 0x8005E4F4: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005E4F8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E4FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005E500: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005E504: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005E508: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005E50C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005E510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E514: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005E518: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005E51C: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E520: nop

    // 0x8005E524: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005E528: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005E52C: nop

    // 0x8005E530: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005E534: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005E538: nop

    // 0x8005E53C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005E540: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E544: nop

    // 0x8005E548: bne         $t5, $at, L_8005E56C
    if (ctx->r13 != ctx->r1) {
        // 0x8005E54C: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005E56C;
    }
    // 0x8005E54C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E550: jal         0x80021400
    // 0x8005E554: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005E554: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005E558: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E55C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E560: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005E564: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005E568: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005E56C:
    // 0x8005E56C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005E570: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005E574: nop

    // 0x8005E578: bne         $v1, $a0, L_8005E584
    if (ctx->r3 != ctx->r4) {
        // 0x8005E57C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005E584;
    }
    // 0x8005E57C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E580: sb          $zero, -0x2A10($at)
    MEM_B(-0X2A10, ctx->r1) = 0;
L_8005E584:
    // 0x8005E584: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005E588: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E58C: bne         $t0, $t8, L_8005E608
    if (ctx->r8 != ctx->r24) {
        // 0x8005E590: nop
    
            goto L_8005E608;
    }
    // 0x8005E590: nop

    // 0x8005E594: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005E598: nop

    // 0x8005E59C: beq         $a0, $v0, L_8005E608
    if (ctx->r4 == ctx->r2) {
        // 0x8005E5A0: addiu       $t9, $v0, -0x1E
        ctx->r25 = ADD32(ctx->r2, -0X1E);
            goto L_8005E608;
    }
    // 0x8005E5A0: addiu       $t9, $v0, -0x1E
    ctx->r25 = ADD32(ctx->r2, -0X1E);
    // 0x8005E5A4: bgez        $t9, L_8005E600
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005E5A8: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005E600;
    }
    // 0x8005E5A8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E5AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005E5B0: lb          $t3, -0x2A0F($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2A0F);
    // 0x8005E5B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E5B8: bne         $t3, $zero, L_8005E5E0
    if (ctx->r11 != 0) {
        // 0x8005E5BC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005E5E0;
    }
    // 0x8005E5BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E5C0: jal         0x8005CB04
    // 0x8005E5C4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005E5C4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_2:
    // 0x8005E5C8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E5CC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E5D0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E5D4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005E5D8: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005E5DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005E5E0:
    // 0x8005E5E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E5E4: sb          $t5, -0x2A0F($at)
    MEM_B(-0X2A0F, ctx->r1) = ctx->r13;
    // 0x8005E5E8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005E5EC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005E5F0: nop

    // 0x8005E5F4: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005E5F8: b           L_8005E608
    // 0x8005E5FC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005E608;
    // 0x8005E5FC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005E600:
    // 0x8005E600: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E604: sb          $zero, -0x2A0F($at)
    MEM_B(-0X2A0F, ctx->r1) = 0;
L_8005E608:
    // 0x8005E608: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005E60C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005E610: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005E614: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005E618: jal         0x8004F7F4
    // 0x8005E61C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005E61C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005E620: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E624: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E628: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E62C: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005E630: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005E634: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005E638: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E63C: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005E640: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005E644: nop

    // 0x8005E648: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E64C: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005E650: nop

    // 0x8005E654: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005E658: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005E65C: nop

    // 0x8005E660: beq         $t3, $zero, L_8005E6F0
    if (ctx->r11 == 0) {
        // 0x8005E664: nop
    
            goto L_8005E6F0;
    }
    // 0x8005E664: nop

    // 0x8005E668: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E66C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E670: beq         $v0, $at, L_8005E6F0
    if (ctx->r2 == ctx->r1) {
        // 0x8005E674: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8005E6F0;
    }
    // 0x8005E674: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8005E678: sb          $v0, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r2;
    // 0x8005E67C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005E680: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005E684: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005E688: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E68C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E690: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E694: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005E698: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E69C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005E6A0: jal         0x8005CB04
    // 0x8005E6A4: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005E6A4: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005E6A8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005E6AC: jal         0x80001D04
    // 0x8005E6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005E6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005E6B4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005E6B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005E6BC: jal         0x80069F28
    // 0x8005E6C0: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005E6C0: nop

    after_6:
    // 0x8005E6C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E6C8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E6CC: lwc1        $f9, 0x6AA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6AA0);
    // 0x8005E6D0: lwc1        $f8, 0x6AA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6AA4);
    // 0x8005E6D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E6D8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005E6DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E6E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E6E4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E6E8: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E6EC: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005E6F0:
    // 0x8005E6F0: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005E6F4: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005E6F8: beq         $t5, $zero, L_8005E73C
    if (ctx->r13 == 0) {
        // 0x8005E6FC: nop
    
            goto L_8005E73C;
    }
    // 0x8005E6FC: nop

    // 0x8005E700: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005E704: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005E708: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E70C: nop

    // 0x8005E710: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E714: nop

    // 0x8005E718: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E71C: nop

    // 0x8005E720: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E724: jal         0x800C9AD0
    // 0x8005E728: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005E728: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005E72C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005E730: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E734: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005E738: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005E73C:
    // 0x8005E73C: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8005E740: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E744: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005E748: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005E74C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E750: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E754: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x8005E758: nop

    // 0x8005E75C: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005E760: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005E764: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005E768: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005E76C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005E770: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005E774: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005E778: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E77C: cvt.d.s     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f2.d = CVT_D_S(ctx->f18.fl);
    // 0x8005E780: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x8005E784: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E788: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E78C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E790: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E794: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005E798: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E79C: nop

    // 0x8005E7A0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E7A4: nop

    // 0x8005E7A8: bc1f        L_8005E7D4
    if (!c1cs) {
        // 0x8005E7AC: nop
    
            goto L_8005E7D4;
    }
    // 0x8005E7AC: nop

L_8005E7B0:
    // 0x8005E7B0: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005E7B4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005E7B8: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E7BC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E7C0: nop

    // 0x8005E7C4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E7C8: nop

    // 0x8005E7CC: bc1t        L_8005E7B0
    if (c1cs) {
        // 0x8005E7D0: nop
    
            goto L_8005E7B0;
    }
    // 0x8005E7D0: nop

L_8005E7D4:
    // 0x8005E7D4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E7D8: nop

    // 0x8005E7DC: bc1f        L_8005E808
    if (!c1cs) {
        // 0x8005E7E0: nop
    
            goto L_8005E808;
    }
    // 0x8005E7E0: nop

L_8005E7E4:
    // 0x8005E7E4: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005E7E8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005E7EC: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E7F0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E7F4: nop

    // 0x8005E7F8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E7FC: nop

    // 0x8005E800: bc1t        L_8005E7E4
    if (c1cs) {
        // 0x8005E804: nop
    
            goto L_8005E7E4;
    }
    // 0x8005E804: nop

L_8005E808:
    // 0x8005E808: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005E80C: nop

    // 0x8005E810: bne         $t0, $t8, L_8005E838
    if (ctx->r8 != ctx->r24) {
        // 0x8005E814: nop
    
            goto L_8005E838;
    }
    // 0x8005E814: nop

    // 0x8005E818: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E81C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E820: bne         $t7, $at, L_8005E838
    if (ctx->r15 != ctx->r1) {
        // 0x8005E824: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8005E838;
    }
    // 0x8005E824: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005E828: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E82C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E830: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E834: nop

L_8005E838:
    // 0x8005E838: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E83C: nop

    // 0x8005E840: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E844: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E848: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E84C: nop

    // 0x8005E850: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005E854: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8005E858: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E85C: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005E860: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x8005E864: nop

    // 0x8005E868: bne         $t0, $t4, L_8005E8A8
    if (ctx->r8 != ctx->r12) {
        // 0x8005E86C: nop
    
            goto L_8005E8A8;
    }
    // 0x8005E86C: nop

    // 0x8005E870: jal         0x80023568
    // 0x8005E874: nop

    func_80023568(rdram, ctx);
        goto after_8;
    // 0x8005E874: nop

    after_8:
    // 0x8005E878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E87C: beq         $v0, $zero, L_8005E8A8
    if (ctx->r2 == 0) {
        // 0x8005E880: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8005E8A8;
    }
    // 0x8005E880: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005E884: bne         $v0, $at, L_8005E890
    if (ctx->r2 != ctx->r1) {
        // 0x8005E888: addiu       $a3, $zero, 0x110
        ctx->r7 = ADD32(0, 0X110);
            goto L_8005E890;
    }
    // 0x8005E888: addiu       $a3, $zero, 0x110
    ctx->r7 = ADD32(0, 0X110);
    // 0x8005E88C: addiu       $a3, $zero, 0x12A
    ctx->r7 = ADD32(0, 0X12A);
L_8005E890:
    // 0x8005E890: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8005E894: addiu       $t5, $zero, 0x245
    ctx->r13 = ADD32(0, 0X245);
    // 0x8005E898: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005E89C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E8A0: jal         0x8005E204
    // 0x8005E8A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    spawn_boss_hazard(rdram, ctx);
        goto after_9;
    // 0x8005E8A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_8005E8A8:
    // 0x8005E8A8: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005E8AC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005E8B0: jal         0x800AFC3C
    // 0x8005E8B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_10;
    // 0x8005E8B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8005E8B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E8BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E8C0: jal         0x8005D048
    // 0x8005E8C4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_11;
    // 0x8005E8C4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_11:
    // 0x8005E8C8: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E8CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E8D0: beq         $v0, $at, L_8005E8EC
    if (ctx->r2 == ctx->r1) {
        // 0x8005E8D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005E8EC;
    }
    // 0x8005E8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E8D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E8DC: beq         $v0, $at, L_8005E8F4
    if (ctx->r2 == ctx->r1) {
        // 0x8005E8E0: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005E8F4;
    }
    // 0x8005E8E0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005E8E4: b           L_8005E8F4
    // 0x8005E8E8: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005E8F4;
    // 0x8005E8E8: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005E8EC:
    // 0x8005E8EC: b           L_8005E8F4
    // 0x8005E8F0: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005E8F4;
    // 0x8005E8F0: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005E8F4:
    // 0x8005E8F4: jal         0x8001BAC8
    // 0x8005E8F8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_12;
    // 0x8005E8F8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_12:
    // 0x8005E8FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005E900: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E904: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005E908: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E90C: sub.s       $f20, $f10, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005E910: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005E914: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E918: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005E91C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005E920: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E924: jal         0x800C9AD0
    // 0x8005E928: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x8005E928: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_13:
    // 0x8005E92C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E930: lwc1        $f5, 0x6AA8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AA8);
    // 0x8005E934: lwc1        $f4, 0x6AAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AAC);
    // 0x8005E938: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E93C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005E940: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005E944: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005E948: bc1f        L_8005E9C4
    if (!c1cs) {
        // 0x8005E94C: nop
    
            goto L_8005E9C4;
    }
    // 0x8005E94C: nop

    // 0x8005E950: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005E954: jal         0x80070750
    // 0x8005E958: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x8005E958: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8005E95C: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8005E960: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005E964: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8005E968: subu        $v1, $v0, $t8
    ctx->r3 = SUB32(ctx->r2, ctx->r24);
    // 0x8005E96C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005E970: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005E974: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005E978: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005E97C: bne         $at, $zero, L_8005E990
    if (ctx->r1 != 0) {
        // 0x8005E980: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005E990;
    }
    // 0x8005E980: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005E984: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005E988: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E98C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E990:
    // 0x8005E990: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005E994: beq         $at, $zero, L_8005E9A0
    if (ctx->r1 == 0) {
        // 0x8005E998: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005E9A0;
    }
    // 0x8005E998: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005E99C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E9A0:
    // 0x8005E9A0: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005E9A4: beq         $at, $zero, L_8005E9B4
    if (ctx->r1 == 0) {
        // 0x8005E9A8: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005E9B4;
    }
    // 0x8005E9A8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005E9AC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005E9B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005E9B4:
    // 0x8005E9B4: beq         $at, $zero, L_8005E9C0
    if (ctx->r1 == 0) {
        // 0x8005E9B8: nop
    
            goto L_8005E9C0;
    }
    // 0x8005E9B8: nop

    // 0x8005E9BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005E9C0:
    // 0x8005E9C0: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005E9C4:
    // 0x8005E9C4: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E9C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E9CC: bne         $t7, $at, L_8005E9FC
    if (ctx->r15 != ctx->r1) {
        // 0x8005E9D0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005E9FC;
    }
    // 0x8005E9D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005E9D4: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005E9D8: nop

    // 0x8005E9DC: andi        $t2, $t9, 0x1F
    ctx->r10 = ctx->r25 & 0X1F;
    // 0x8005E9E0: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x8005E9E4: beq         $at, $zero, L_8005EA00
    if (ctx->r1 == 0) {
        // 0x8005E9E8: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005EA00;
    }
    // 0x8005E9E8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005E9EC: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005E9F0: nop

    // 0x8005E9F4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005E9F8: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005E9FC:
    // 0x8005E9FC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005EA00:
    // 0x8005EA00: addiu       $a1, $a1, -0x2A10
    ctx->r5 = ADD32(ctx->r5, -0X2A10);
    // 0x8005EA04: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005EA08: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005EA0C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005EA10: nop

    // 0x8005EA14: bne         $s1, $t5, L_8005EA44
    if (ctx->r17 != ctx->r13) {
        // 0x8005EA18: nop
    
            goto L_8005EA44;
    }
    // 0x8005EA18: nop

    // 0x8005EA1C: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005EA20: nop

    // 0x8005EA24: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005EA28: beq         $t8, $zero, L_8005EA44
    if (ctx->r24 == 0) {
        // 0x8005EA2C: nop
    
            goto L_8005EA44;
    }
    // 0x8005EA2C: nop

    // 0x8005EA30: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EA38: bne         $t7, $at, L_8005EA44
    if (ctx->r15 != ctx->r1) {
        // 0x8005EA3C: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005EA44;
    }
    // 0x8005EA3C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005EA40: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005EA44:
    // 0x8005EA44: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005EA48: nop

    // 0x8005EA4C: beq         $t2, $zero, L_8005EA70
    if (ctx->r10 == 0) {
        // 0x8005EA50: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005EA70;
    }
    // 0x8005EA50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EA54: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8005EA58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005EA5C: bne         $t3, $zero, L_8005EA6C
    if (ctx->r11 != 0) {
        // 0x8005EA60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005EA6C;
    }
    // 0x8005EA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005EA64: jal         0x8005CB68
    // 0x8005EA68: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    racer_boss_finish(rdram, ctx);
        goto after_15;
    // 0x8005EA68: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    after_15:
L_8005EA6C:
    // 0x8005EA6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005EA70:
    // 0x8005EA70: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005EA74: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005EA78: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005EA7C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005EA80: jr          $ra
    // 0x8005EA84: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005EA84: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void timetrial_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B2E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B2E4: lw          $v0, -0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X52CC);
    // 0x8001B2E8: jr          $ra
    // 0x8001B2EC: nop

    return;
    // 0x8001B2EC: nop

;}
RECOMP_FUNC void cam_reset_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066194: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80066198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006619C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800661A0: lwc1        $f6, 0x70A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70A4);
    // 0x800661A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800661A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800661AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800661B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800661B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800661B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800661BC: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x800661C0: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x800661C4: addiu       $a1, $a1, 0xD6C
    ctx->r5 = ADD32(ctx->r5, 0XD6C);
    // 0x800661C8: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    // 0x800661CC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x800661D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800661D4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800661D8: jal         0x800CC920
    // 0x800661DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800661DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800661E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800661E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800661E8: addiu       $a1, $a1, 0xFE0
    ctx->r5 = ADD32(ctx->r5, 0XFE0);
    // 0x800661EC: jal         0x8006F870
    // 0x800661F0: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x800661F0: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    after_1:
    // 0x800661F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800661F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800661FC: jr          $ra
    // 0x80066200: nop

    return;
    // 0x80066200: nop

;}
RECOMP_FUNC void read_game_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80073E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80073E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80073E28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80073E2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80073E30: jal         0x800758DC
    // 0x80073E34: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80073E34: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80073E38: beq         $v0, $zero, L_80073E5C
    if (ctx->r2 == 0) {
        // 0x80073E3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80073E5C;
    }
    // 0x80073E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073E44: jal         0x80075AEC
    // 0x80073E48: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80073E48: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x80073E4C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80073E50: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80073E54: b           L_80073F4C
    // 0x80073E58: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80073F4C;
    // 0x80073E58: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_80073E5C:
    // 0x80073E5C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80073E60: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80073E64: addiu       $a1, $a1, 0x7670
    ctx->r5 = ADD32(ctx->r5, 0X7670);
    // 0x80073E68: jal         0x800764E8
    // 0x80073E6C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80073E6C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80073E70: bne         $v0, $zero, L_80073F28
    if (ctx->r2 != 0) {
        // 0x80073E74: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073F28;
    }
    // 0x80073E74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073E78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80073E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073E80: jal         0x80076924
    // 0x80073E84: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80073E84: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80073E88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80073E8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073E90: bne         $a0, $zero, L_80073E9C
    if (ctx->r4 != 0) {
        // 0x80073E94: nop
    
            goto L_80073E9C;
    }
    // 0x80073E94: nop

    // 0x80073E98: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80073E9C:
    // 0x80073E9C: bne         $v1, $zero, L_80073F28
    if (ctx->r3 != 0) {
        // 0x80073EA0: nop
    
            goto L_80073F28;
    }
    // 0x80073EA0: nop

    // 0x80073EA4: jal         0x80070C9C
    // 0x80073EA8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80073EA8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80073EAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80073EB0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80073EB4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80073EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073EBC: jal         0x80076610
    // 0x80073EC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80073EC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80073EC4: bne         $v0, $zero, L_80073F14
    if (ctx->r2 != 0) {
        // 0x80073EC8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073F14;
    }
    // 0x80073EC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073ECC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80073ED0: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x80073ED4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80073ED8: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80073EDC: bne         $t7, $at, L_80073F14
    if (ctx->r15 != ctx->r1) {
        // 0x80073EE0: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80073F14;
    }
    // 0x80073EE0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80073EE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80073EE8: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80073EEC: jal         0x8007306C
    // 0x80073EF0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    populate_settings_from_save_data(rdram, ctx);
        goto after_6;
    // 0x80073EF0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x80073EF4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80073EF8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80073EFC: lbu         $t9, 0x4B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4B);
    // 0x80073F00: nop

    // 0x80073F04: beq         $t9, $zero, L_80073F18
    if (ctx->r25 == 0) {
        // 0x80073F08: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80073F18;
    }
    // 0x80073F08: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80073F0C: b           L_80073F14
    // 0x80073F10: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80073F14;
    // 0x80073F10: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80073F14:
    // 0x80073F14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80073F18:
    // 0x80073F18: jal         0x80071140
    // 0x80073F1C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80073F1C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80073F20: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80073F24: nop

L_80073F28:
    // 0x80073F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80073F2C: jal         0x80075AEC
    // 0x80073F30: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80073F30: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x80073F34: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80073F38: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x80073F3C: beq         $v1, $zero, L_80073F4C
    if (ctx->r3 == 0) {
        // 0x80073F40: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80073F4C;
    }
    // 0x80073F40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073F44: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80073F48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80073F4C:
    // 0x80073F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80073F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073F54: jr          $ra
    // 0x80073F58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80073F58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void try_to_collect_egg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036040: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80036044: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80036048: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003604C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80036050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80036054: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x80036058: nop

    // 0x8003605C: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x80036060: beq         $at, $zero, L_80036188
    if (ctx->r1 == 0) {
        // 0x80036064: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80036188;
    }
    // 0x80036064: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036068: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003606C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80036070: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x80036074: nop

    // 0x80036078: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003607C: nop

    // 0x80036080: bne         $a3, $t8, L_80036188
    if (ctx->r7 != ctx->r24) {
        // 0x80036084: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80036188;
    }
    // 0x80036084: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036088: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003608C: nop

    // 0x80036090: lw          $t9, 0x144($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X144);
    // 0x80036094: nop

    // 0x80036098: bne         $t9, $zero, L_80036188
    if (ctx->r25 != 0) {
        // 0x8003609C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80036188;
    }
    // 0x8003609C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360A0: sb          $a3, 0xB($a1)
    MEM_B(0XB, ctx->r5) = ctx->r7;
    // 0x800360A4: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800360A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800360AC: ori         $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 | 0X4000;
    // 0x800360B0: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800360B4: sw          $a0, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->r4;
    // 0x800360B8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800360BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800360C0: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800360C4: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x800360C8: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800360CC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800360D0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800360D4: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
    // 0x800360D8: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800360DC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800360E0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800360E4: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x800360E8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800360EC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800360F0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800360F4: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800360F8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800360FC: nop

    // 0x80036100: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80036104: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80036108: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003610C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80036110: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80036114: jal         0x8006FE74
    // 0x80036118: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80036118: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8003611C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036120: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80036124: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80036128: addiu       $t8, $s0, 0xC
    ctx->r24 = ADD32(ctx->r16, 0XC);
    // 0x8003612C: addiu       $t9, $s0, 0x10
    ctx->r25 = ADD32(ctx->r16, 0X10);
    // 0x80036130: addiu       $t0, $s0, 0x14
    ctx->r8 = ADD32(ctx->r16, 0X14);
    // 0x80036134: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80036138: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003613C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80036140: jal         0x8006F64C
    // 0x80036144: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80036144: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x80036148: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x8003614C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036150: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036154: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036158: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003615C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80036160: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80036164: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036168: nop

    // 0x8003616C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80036170: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80036174: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036178: nop

    // 0x8003617C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80036180: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80036184: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80036188:
    // 0x80036188: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003618C: jr          $ra
    // 0x80036190: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80036190: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void music_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000153C: beq         $a0, $zero, L_800015A8
    if (ctx->r4 == 0) {
        // 0x80001540: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800015A8;
    }
    // 0x80001540: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001544: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80001548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000154C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80001550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001558: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000155C: lwc1        $f16, 0x49DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X49DC);
    // 0x80001560: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001564: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001568: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000156C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001570: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80001574: nop

    // 0x80001578: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000157C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001580: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001584: nop

    // 0x80001588: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000158C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001590: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80001594: jal         0x800C79E0
    // 0x80001598: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001598: nop

    after_0:
    // 0x8000159C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800015A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800015A4: sh          $a2, 0x5D30($at)
    MEM_H(0X5D30, ctx->r1) = ctx->r6;
L_800015A8:
    // 0x800015A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800015B0: jr          $ra
    // 0x800015B4: nop

    return;
    // 0x800015B4: nop

;}
RECOMP_FUNC void obj_tick_anims(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800142B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800142BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800142C0: lw          $v0, -0x51A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A0);
    // 0x800142C4: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x800142C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800142CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800142D0: beq         $at, $zero, L_800143A0
    if (ctx->r1 == 0) {
        // 0x800142D4: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_800143A0;
    }
    // 0x800142D4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800142D8: addiu       $t2, $t2, -0x51A8
    ctx->r10 = ADD32(ctx->r10, -0X51A8);
L_800142DC:
    // 0x800142DC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800142E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800142E4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800142E8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800142EC: nop

    // 0x800142F0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800142F4: nop

    // 0x800142F8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800142FC: bne         $t9, $zero, L_80014398
    if (ctx->r25 != 0) {
        // 0x80014300: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014300: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014304: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x80014308: nop

    // 0x8001430C: lb          $t3, 0x53($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X53);
    // 0x80014310: nop

    // 0x80014314: bne         $t3, $zero, L_80014398
    if (ctx->r11 != 0) {
        // 0x80014318: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014318: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001431C: lb          $t0, 0x55($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X55);
    // 0x80014320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014324: blez        $t0, L_80014394
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80014328: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80014394;
    }
    // 0x80014328: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001432C:
    // 0x8001432C: lw          $t4, 0x68($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X68);
    // 0x80014330: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80014334: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80014338: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x8001433C: nop

    // 0x80014340: beq         $v1, $zero, L_80014380
    if (ctx->r3 == 0) {
        // 0x80014344: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80014380;
    }
    // 0x80014344: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80014348: lb          $t1, 0x20($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X20);
    // 0x8001434C: nop

    // 0x80014350: blez        $t1, L_8001437C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014354: andi        $t6, $t1, 0x3
        ctx->r14 = ctx->r9 & 0X3;
            goto L_8001437C;
    }
    // 0x80014354: andi        $t6, $t1, 0x3
    ctx->r14 = ctx->r9 & 0X3;
    // 0x80014358: sb          $t6, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r14;
    // 0x8001435C: lb          $t7, 0x20($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X20);
    // 0x80014360: nop

    // 0x80014364: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80014368: sb          $t8, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r24;
    // 0x8001436C: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x80014370: nop

    // 0x80014374: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x80014378: nop

L_8001437C:
    // 0x8001437C: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
L_80014380:
    // 0x80014380: bne         $at, $zero, L_8001432C
    if (ctx->r1 != 0) {
        // 0x80014384: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001432C;
    }
    // 0x80014384: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80014388: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001438C: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80014390: nop

L_80014394:
    // 0x80014394: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80014398:
    // 0x80014398: bne         $at, $zero, L_800142DC
    if (ctx->r1 != 0) {
        // 0x8001439C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800142DC;
    }
    // 0x8001439C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800143A0:
    // 0x800143A0: jr          $ra
    // 0x800143A4: nop

    return;
    // 0x800143A4: nop

;}
RECOMP_FUNC void func_8002125C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002125C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021264: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80021268: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x8002126C: nop

    // 0x80021270: bltz        $v0, L_800212C4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021274: nop
    
            goto L_800212C4;
    }
    // 0x80021274: nop

    // 0x80021278: lb          $t6, 0x3B($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3B);
    // 0x8002127C: nop

    // 0x80021280: beq         $v0, $t6, L_8002129C
    if (ctx->r2 == ctx->r14) {
        // 0x80021284: nop
    
            goto L_8002129C;
    }
    // 0x80021284: nop

    // 0x80021288: lbu         $t7, 0x16($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X16);
    // 0x8002128C: nop

    // 0x80021290: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x80021294: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x80021298: nop

L_8002129C:
    // 0x8002129C: sb          $v0, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r2;
    // 0x800212A0: lb          $t8, 0x17($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X17);
    // 0x800212A4: nop

    // 0x800212A8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800212AC: nop

    // 0x800212B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800212B4: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800212B8: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
    // 0x800212BC: nop

    // 0x800212C0: sb          $t9, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r25;
L_800212C4:
    // 0x800212C4: lb          $v0, 0x13($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X13);
    // 0x800212C8: nop

    // 0x800212CC: bltz        $v0, L_800212D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800212D0: nop
    
            goto L_800212D8;
    }
    // 0x800212D0: nop

    // 0x800212D4: sb          $v0, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r2;
L_800212D8:
    // 0x800212D8: lh          $a0, 0x24($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X24);
    // 0x800212DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800212E0: jal         0x8000C8B4
    // 0x800212E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800212E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800212E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800212EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800212F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800212F4: sh          $v0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r2;
    // 0x800212F8: lb          $t0, 0x2D($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X2D);
    // 0x800212FC: nop

    // 0x80021300: sb          $t0, 0x3F($a2)
    MEM_B(0X3F, ctx->r6) = ctx->r8;
    // 0x80021304: lb          $t1, 0x26($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X26);
    // 0x80021308: nop

    // 0x8002130C: sb          $t1, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r9;
    // 0x80021310: lb          $t2, 0x1F($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1F);
    // 0x80021314: nop

    // 0x80021318: sb          $t2, 0x39($a2)
    MEM_B(0X39, ctx->r6) = ctx->r10;
    // 0x8002131C: lb          $t3, 0x30($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X30);
    // 0x80021320: nop

    // 0x80021324: sb          $t3, 0x43($a2)
    MEM_B(0X43, ctx->r6) = ctx->r11;
    // 0x80021328: lbu         $t4, 0x1E($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1E);
    // 0x8002132C: nop

    // 0x80021330: sb          $t4, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r12;
    // 0x80021334: lb          $t5, 0x29($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X29);
    // 0x80021338: nop

    // 0x8002133C: sb          $t5, 0x3B($a2)
    MEM_B(0X3B, ctx->r6) = ctx->r13;
    // 0x80021340: lb          $t6, 0x2E($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X2E);
    // 0x80021344: nop

    // 0x80021348: sb          $t6, 0x40($a2)
    MEM_B(0X40, ctx->r6) = ctx->r14;
    // 0x8002134C: lb          $t7, 0x2F($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X2F);
    // 0x80021350: nop

    // 0x80021354: sb          $t7, 0x41($a2)
    MEM_B(0X41, ctx->r6) = ctx->r15;
    // 0x80021358: lb          $t8, 0x2B($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X2B);
    // 0x8002135C: nop

    // 0x80021360: sb          $t8, 0x3C($a2)
    MEM_B(0X3C, ctx->r6) = ctx->r24;
    // 0x80021364: lbu         $a0, 0x27($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X27);
    // 0x80021368: nop

    // 0x8002136C: beq         $a0, $at, L_80021384
    if (ctx->r4 == ctx->r1) {
        // 0x80021370: nop
    
            goto L_80021384;
    }
    // 0x80021370: nop

    // 0x80021374: jal         0x800C31EC
    // 0x80021378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x80021378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8002137C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021380: nop

L_80021384:
    // 0x80021384: lb          $a0, 0x2A($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X2A);
    // 0x80021388: nop

    // 0x8002138C: bltz        $a0, L_800213A4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80021390: nop
    
            goto L_800213A4;
    }
    // 0x80021390: nop

    // 0x80021394: jal         0x8001E45C
    // 0x80021398: nop

    func_8001E45C(rdram, ctx);
        goto after_2;
    // 0x80021398: nop

    after_2:
    // 0x8002139C: b           L_800213F4
    // 0x800213A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800213F4;
    // 0x800213A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800213A4:
    // 0x800213A4: lb          $a0, 0x15($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X15);
    // 0x800213A8: nop

    // 0x800213AC: bltz        $a0, L_800213C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800213B0: nop
    
            goto L_800213C4;
    }
    // 0x800213B0: nop

    // 0x800213B4: jal         0x80021400
    // 0x800213B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80021400(rdram, ctx);
        goto after_3;
    // 0x800213B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x800213BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213C0: nop

L_800213C4:
    // 0x800213C4: lb          $t9, 0x28($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X28);
    // 0x800213C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800213CC: bltz        $t9, L_800213F0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800213D0: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800213F0;
    }
    // 0x800213D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800213D4: lb          $t0, -0x52DF($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X52DF);
    // 0x800213D8: addiu       $t1, $t1, -0x52DE
    ctx->r9 = ADD32(ctx->r9, -0X52DE);
    // 0x800213DC: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x800213E0: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x800213E4: nop

    // 0x800213E8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800213EC: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_800213F0:
    // 0x800213F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800213F4:
    // 0x800213F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800213F8: jr          $ra
    // 0x800213FC: nop

    return;
    // 0x800213FC: nop

;}
RECOMP_FUNC void func_8000E558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E558: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x8000E55C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E560: bne         $v0, $zero, L_8000E570
    if (ctx->r2 != 0) {
        // 0x8000E564: addiu       $a1, $a1, -0x5168
        ctx->r5 = ADD32(ctx->r5, -0X5168);
            goto L_8000E570;
    }
    // 0x8000E564: addiu       $a1, $a1, -0x5168
    ctx->r5 = ADD32(ctx->r5, -0X5168);
    // 0x8000E568: jr          $ra
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E570:
    // 0x8000E570: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000E574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000E578: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000E57C: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E580: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E5A8;
    }
    // 0x8000E580: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E584: lw          $t6, -0x5160($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5160);
    // 0x8000E588: nop

    // 0x8000E58C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000E590: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8000E594: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E598: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E59C: nop
    
            goto L_8000E5A8;
    }
    // 0x8000E59C: nop

    // 0x8000E5A0: jr          $ra
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E5A8:
    // 0x8000E5A8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8000E5AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E5B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E5B4: bne         $at, $zero, L_8000E5E0
    if (ctx->r1 != 0) {
        // 0x8000E5B8: nop
    
            goto L_8000E5E0;
    }
    // 0x8000E5B8: nop

    // 0x8000E5BC: lw          $t9, -0x515C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X515C);
    // 0x8000E5C0: nop

    // 0x8000E5C4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000E5C8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000E5CC: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E5D0: bne         $at, $zero, L_8000E5E4
    if (ctx->r1 != 0) {
        // 0x8000E5D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E5E4;
    }
    // 0x8000E5D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E5D8: jr          $ra
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E0:
    // 0x8000E5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E4:
    // 0x8000E5E4: jr          $ra
    // 0x8000E5E8: nop

    return;
    // 0x8000E5E8: nop

;}
RECOMP_FUNC void mtxf_from_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC30: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006FC34: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8006FC38: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8006FC3C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006FC40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FC44: jal         0x80070830
    // 0x8006FC48: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x8006FC48: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x8006FC4C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006FC50: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8006FC54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006FC58: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006FC5C: jal         0x8007082C
    // 0x8006FC60: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8006FC60: nop

    after_1:
    // 0x8006FC64: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006FC68: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FC6C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8006FC70: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006FC74: jal         0x80070830
    // 0x8006FC78: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x8006FC78: nop

    after_2:
    // 0x8006FC7C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8006FC80: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FC84: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006FC88: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FC8C: jal         0x8007082C
    // 0x8006FC90: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8006FC90: nop

    after_3:
    // 0x8006FC94: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8006FC98: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FC9C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006FCA0: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8006FCA4: jal         0x80070830
    // 0x8006FCA8: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x8006FCA8: nop

    after_4:
    // 0x8006FCAC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8006FCB0: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FCB4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006FCB8: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8006FCBC: jal         0x8007082C
    // 0x8006FCC0: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x8006FCC0: nop

    after_5:
    // 0x8006FCC4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006FCC8: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8006FCCC: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8006FCD0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FCD4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8006FCD8: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x8006FCDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006FCE0: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006FCE4: nop

    // 0x8006FCE8: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FCEC: nop

    // 0x8006FCF0: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FCF4: nop

    // 0x8006FCF8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006FCFC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FD00: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FD04: nop

    // 0x8006FD08: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FD0C: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x8006FD10: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006FD14: nop

    // 0x8006FD18: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FD1C: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8006FD20: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FD24: nop

    // 0x8006FD28: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FD2C: nop

    // 0x8006FD30: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006FD34: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FD38: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FD3C: nop

    // 0x8006FD40: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FD44: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8006FD48: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FD4C: nop

    // 0x8006FD50: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FD54: nop

    // 0x8006FD58: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FD5C: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FD60: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FD64: nop

    // 0x8006FD68: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FD6C: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8006FD70: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8006FD74: nop

    // 0x8006FD78: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FD7C: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8006FD80: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FD84: nop

    // 0x8006FD88: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FD8C: nop

    // 0x8006FD90: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006FD94: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FD98: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FD9C: nop

    // 0x8006FDA0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FDA4: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
    // 0x8006FDA8: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006FDAC: nop

    // 0x8006FDB0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FDB4: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x8006FDB8: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FDBC: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8006FDC0: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x8006FDC4: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006FDC8: nop

    // 0x8006FDCC: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FDD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FDD4: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x8006FDD8: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x8006FDDC: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x8006FDE0: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x8006FDE4: sw          $t0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r8;
    // 0x8006FDE8: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8006FDEC: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x8006FDF0: sw          $t0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r8;
    // 0x8006FDF4: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8006FDF8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006FDFC: jr          $ra
    // 0x8006FE00: nop

    return;
    // 0x8006FE00: nop

;}
RECOMP_FUNC void rumble_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007257C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80072580: lbu         $t9, 0x41E4($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X41E4);
    // 0x80072584: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072588: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007258C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072590: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x80072594: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80072598: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8007259C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800725A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800725A4: beq         $t9, $zero, L_8007266C
    if (ctx->r25 == 0) {
        // 0x800725A8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8007266C;
    }
    // 0x800725A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800725AC: bltz        $t7, L_8007266C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800725B0: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_8007266C;
    }
    // 0x800725B0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800725B4: beq         $at, $zero, L_80072670
    if (ctx->r1 == 0) {
        // 0x800725B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80072670;
    }
    // 0x800725B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800725BC: jal         0x80072250
    // 0x800725C0: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800725C0: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    after_0:
    // 0x800725C4: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x800725C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800725CC: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800725D0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800725D4: addiu       $t0, $t0, 0x41E6
    ctx->r8 = ADD32(ctx->r8, 0X41E6);
    // 0x800725D8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800725DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800725E0: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800725E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800725E8: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x800725EC: addiu       $t1, $t1, 0x41E7
    ctx->r9 = ADD32(ctx->r9, 0X41E7);
    // 0x800725F0: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800725F4: nor         $t8, $t4, $zero
    ctx->r24 = ~(ctx->r12 | 0);
    // 0x800725F8: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x800725FC: mflo        $t4
    ctx->r12 = lo;
    // 0x80072600: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80072604: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80072608: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x8007260C: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x80072610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072614: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072618: lwc1        $f9, 0x77E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X77E0);
    // 0x8007261C: lwc1        $f8, 0x77E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77E4);
    // 0x80072620: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80072624: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80072628: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007262C: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x80072630: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072634: addiu       $t3, $t3, 0x41B8
    ctx->r11 = ADD32(ctx->r11, 0X41B8);
    // 0x80072638: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8007263C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80072640: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80072644: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072648: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007264C: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80072650: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x80072654: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80072658: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8007265C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80072660: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80072664: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // 0x80072668: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
L_8007266C:
    // 0x8007266C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80072670:
    // 0x80072670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072674: jr          $ra
    // 0x80072678: nop

    return;
    // 0x80072678: nop

;}
RECOMP_FUNC void render_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80012D6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80012D70: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80012D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012D78: andi        $t7, $t6, 0x5000
    ctx->r15 = ctx->r14 & 0X5000;
    // 0x80012D7C: bne         $t7, $zero, L_80012E1C
    if (ctx->r15 != 0) {
        // 0x80012D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012E1C;
    }
    // 0x80012D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    extern void dkr_presentation_object_begin(uint8_t*, recomp_context*); dkr_presentation_object_begin(rdram, ctx);
    // 0x80012D84: lh          $a1, 0x4A($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X4A);
    // 0x80012D88: jal         0x800B76B8
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80012D90: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80012D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012D98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80012D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DA0: sw          $t9, -0x5174($at)
    MEM_W(-0X5174, ctx->r1) = ctx->r25;
    // 0x80012DA4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80012DA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DB0: sw          $t1, -0x5170($at)
    MEM_W(-0X5170, ctx->r1) = ctx->r9;
    // 0x80012DB4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80012DB8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DC0: sw          $t3, -0x516C($at)
    MEM_W(-0X516C, ctx->r1) = ctx->r11;
    // 0x80012DC4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80012DC8: jal         0x8001348C
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    render_object_parts(rdram, ctx);
        goto after_1;
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_1:
    extern void dkr_presentation_object_end(uint8_t*, recomp_context*); dkr_presentation_object_end(rdram, ctx);
    // 0x80012DD0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DD4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80012DDC: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x80012DE0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80012DE4: lw          $t4, -0x5174($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5174);
    // 0x80012DE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80012DEC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80012DF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012DF4: lw          $t6, -0x5170($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5170);
    // 0x80012DF8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80012DFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80012E00: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012E04: lw          $t8, -0x516C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X516C);
    // 0x80012E08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012E0C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80012E10: jal         0x800B76B8
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    update_object_stack_trace(rdram, ctx);
        goto after_2;
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_2:
    // 0x80012E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012E1C:
    // 0x80012E1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012E20: jr          $ra
    // 0x80012E24: nop

    return;
    // 0x80012E24: nop

;}
RECOMP_FUNC void modify_panning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065BF0: lh          $v0, -0x2FB0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2FB0);
    // 0x80065BF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80065BF8: beq         $v0, $zero, L_80065C18
    if (ctx->r2 == 0) {
        // 0x80065BFC: nop
    
            goto L_80065C18;
    }
    // 0x80065BFC: nop

    // 0x80065C00: beq         $v0, $at, L_80065C2C
    if (ctx->r2 == ctx->r1) {
        // 0x80065C04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80065C2C;
    }
    // 0x80065C04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065C08: beq         $v0, $at, L_80065C20
    if (ctx->r2 == ctx->r1) {
        // 0x80065C0C: addiu       $a0, $a0, -0x40
        ctx->r4 = ADD32(ctx->r4, -0X40);
            goto L_80065C20;
    }
    // 0x80065C0C: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    // 0x80065C10: b           L_80065C30
    // 0x80065C14: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_80065C30;
    // 0x80065C14: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065C18:
    // 0x80065C18: jr          $ra
    // 0x80065C1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80065C1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80065C20:
    // 0x80065C20: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80065C24: jr          $ra
    // 0x80065C28: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
    return;
    // 0x80065C28: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
L_80065C2C:
    // 0x80065C2C: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065C30:
    // 0x80065C30: jr          $ra
    // 0x80065C34: nop

    return;
    // 0x80065C34: nop

;}
RECOMP_FUNC void func_80052988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052988: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8005298C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80052990: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80052994: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052998: lw          $t9, -0x2AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA4);
    // 0x8005299C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800529A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800529A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800529A8: bne         $t9, $at, L_800529C4
    if (ctx->r25 != ctx->r1) {
        // 0x800529AC: slti        $at, $a2, 0x3
        ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
            goto L_800529C4;
    }
    // 0x800529AC: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x800529B0: bne         $at, $zero, L_800529C4
    if (ctx->r1 != 0) {
        // 0x800529B4: nop
    
            goto L_800529C4;
    }
    // 0x800529B4: nop

    // 0x800529B8: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x800529BC: jr          $ra
    // 0x800529C0: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    return;
    // 0x800529C0: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
L_800529C4:
    // 0x800529C4: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x800529C8: nop

    // 0x800529CC: bne         $v0, $zero, L_80052A74
    if (ctx->r2 != 0) {
        // 0x800529D0: nop
    
            goto L_80052A74;
    }
    // 0x800529D0: nop

    // 0x800529D4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800529D8: nop

    // 0x800529DC: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800529E0: beq         $t0, $zero, L_80052A58
    if (ctx->r8 == 0) {
        // 0x800529E4: nop
    
            goto L_80052A58;
    }
    // 0x800529E4: nop

    // 0x800529E8: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x800529EC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800529F0: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x800529F4: bne         $at, $zero, L_80052A30
    if (ctx->r1 != 0) {
        // 0x800529F8: sll         $t6, $t5, 2
        ctx->r14 = S32(ctx->r13 << 2);
            goto L_80052A30;
    }
    // 0x800529F8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800529FC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80052A00: nop

    // 0x80052A04: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80052A08: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80052A0C: sh          $t3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r11;
    // 0x80052A10: lh          $t4, 0x18($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X18);
    // 0x80052A14: nop

    // 0x80052A18: slti        $at, $t4, 0x29
    ctx->r1 = SIGNED(ctx->r12) < 0X29 ? 1 : 0;
    // 0x80052A1C: beq         $at, $zero, L_80052B5C
    if (ctx->r1 == 0) {
        // 0x80052A20: nop
    
            goto L_80052B5C;
    }
    // 0x80052A20: nop

    // 0x80052A24: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A28: jr          $ra
    // 0x80052A2C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    return;
    // 0x80052A2C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
L_80052A30:
    // 0x80052A30: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80052A34: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x80052A38: lh          $t8, 0x18($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X18);
    // 0x80052A3C: nop

    // 0x80052A40: slti        $at, $t8, 0x28
    ctx->r1 = SIGNED(ctx->r24) < 0X28 ? 1 : 0;
    // 0x80052A44: bne         $at, $zero, L_80052B5C
    if (ctx->r1 != 0) {
        // 0x80052A48: nop
    
            goto L_80052B5C;
    }
    // 0x80052A48: nop

    // 0x80052A4C: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A50: jr          $ra
    // 0x80052A54: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    return;
    // 0x80052A54: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
L_80052A58:
    // 0x80052A58: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A5C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x80052A60: lbu         $t9, 0x1F3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052A64: nop

    // 0x80052A68: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x80052A6C: jr          $ra
    // 0x80052A70: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
    return;
    // 0x80052A70: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
L_80052A74:
    // 0x80052A74: bne         $a2, $v0, L_80052B54
    if (ctx->r6 != ctx->r2) {
        // 0x80052A78: nop
    
            goto L_80052B54;
    }
    // 0x80052A78: nop

    // 0x80052A7C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80052A80: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80052A84: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x80052A88: beq         $t1, $zero, L_80052B1C
    if (ctx->r9 == 0) {
        // 0x80052A8C: nop
    
            goto L_80052B1C;
    }
    // 0x80052A8C: nop

    // 0x80052A90: lbu         $t2, 0x1F3($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052A94: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80052A98: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80052A9C: beq         $t3, $zero, L_80052ADC
    if (ctx->r11 == 0) {
        // 0x80052AA0: nop
    
            goto L_80052ADC;
    }
    // 0x80052AA0: nop

    // 0x80052AA4: lh          $t4, 0x18($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X18);
    // 0x80052AA8: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80052AAC: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80052AB0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80052AB4: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x80052AB8: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80052ABC: nop

    // 0x80052AC0: bgtz        $t7, L_80052B5C
    if (SIGNED(ctx->r15) > 0) {
        // 0x80052AC4: nop
    
            goto L_80052B5C;
    }
    // 0x80052AC4: nop

    // 0x80052AC8: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80052ACC: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052AD0: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x80052AD4: jr          $ra
    // 0x80052AD8: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    return;
    // 0x80052AD8: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_80052ADC:
    // 0x80052ADC: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x80052AE0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80052AE4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80052AE8: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
    // 0x80052AEC: lh          $t2, 0x18($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X18);
    // 0x80052AF0: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x80052AF4: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052AF8: bne         $at, $zero, L_80052B5C
    if (ctx->r1 != 0) {
        // 0x80052AFC: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80052B5C;
    }
    // 0x80052AFC: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80052B00: bne         $t4, $zero, L_80052B5C
    if (ctx->r12 != 0) {
        // 0x80052B04: sh          $t3, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r11;
            goto L_80052B5C;
    }
    // 0x80052B04: sh          $t3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r11;
    // 0x80052B08: lbu         $t5, 0x1F3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052B0C: nop

    // 0x80052B10: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80052B14: jr          $ra
    // 0x80052B18: sb          $t6, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r14;
    return;
    // 0x80052B18: sb          $t6, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r14;
L_80052B1C:
    // 0x80052B1C: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80052B20: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80052B24: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80052B28: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80052B2C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80052B30: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80052B34: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052B38: bne         $at, $zero, L_80052B5C
    if (ctx->r1 != 0) {
        // 0x80052B3C: nop
    
            goto L_80052B5C;
    }
    // 0x80052B3C: nop

    // 0x80052B40: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80052B44: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052B48: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
    // 0x80052B4C: jr          $ra
    // 0x80052B50: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    return;
    // 0x80052B50: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_80052B54:
    // 0x80052B54: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x80052B58: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
L_80052B5C:
    // 0x80052B5C: jr          $ra
    // 0x80052B60: nop

    return;
    // 0x80052B60: nop

;}
RECOMP_FUNC void alCSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C827C: jr          $ra
    // 0x800C8280: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800C8280: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void music_volume_config_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001A40: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80001A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001A48: bne         $at, $zero, L_80001A54
    if (ctx->r1 != 0) {
        // 0x80001A4C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80001A54;
    }
    // 0x80001A4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001A50: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_80001A54:
    // 0x80001A54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001A58: addiu       $v0, $v0, -0x39AC
    ctx->r2 = ADD32(ctx->r2, -0X39AC);
    // 0x80001A5C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80001A60: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001A64: lbu         $t6, -0x39C8($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X39C8);
    // 0x80001A68: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80001A6C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001A70: lw          $t9, -0x3994($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3994);
    // 0x80001A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001A78: lwc1        $f8, -0x39B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X39B0);
    // 0x80001A7C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80001A80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001A84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80001A88: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001A8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80001A90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80001A94: nop

    // 0x80001A98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001A9C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80001AA0: nop

    // 0x80001AA4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001AA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80001AAC: nop

    // 0x80001AB0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001AB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001AB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001ABC: nop

    // 0x80001AC0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001AC4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001AC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001ACC: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001AD0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001AD4: jal         0x800C7850
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AE4: jr          $ra
    // 0x80001AE8: nop

    return;
    // 0x80001AE8: nop

;}
RECOMP_FUNC void menu_assetgroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C678: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C67C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C680: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C688: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009C68C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009C690: beq         $s2, $t6, L_8009C6C0
    if (ctx->r18 == ctx->r14) {
        // 0x8009C694: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009C6C0;
    }
    // 0x8009C694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009C698: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009C69C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009C6A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009C6A4:
    // 0x8009C6A4: jal         0x8009C6D4
    // 0x8009C6A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_load(rdram, ctx);
        goto after_0;
    // 0x8009C6A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009C6AC: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009C6B0: nop

    // 0x8009C6B4: bne         $s2, $s1, L_8009C6A4
    if (ctx->r18 != ctx->r17) {
        // 0x8009C6B8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009C6A4;
    }
    // 0x8009C6B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009C6BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009C6C0:
    // 0x8009C6C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C6C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C6C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009C6CC: jr          $ra
    // 0x8009C6D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009C6D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AEFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000AF00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AF04: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000AF08: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000AF0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000AF10: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000AF14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000AF18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000AF1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000AF20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AF24: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AF28: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000AF2C: beq         $s0, $zero, L_8000AFE4
    if (ctx->r16 == 0) {
        // 0x8000AF30: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_8000AFE4;
    }
    // 0x8000AF30: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000AF34: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x8000AF38: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_8000AF3C:
    // 0x8000AF3C: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x8000AF40: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AF44: beq         $s3, $s6, L_8000AF54
    if (ctx->r19 == ctx->r22) {
        // 0x8000AF48: nop
    
            goto L_8000AF54;
    }
    // 0x8000AF48: nop

    // 0x8000AF4C: bne         $s3, $s7, L_8000AFDC
    if (ctx->r19 != ctx->r23) {
        // 0x8000AF50: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF50: nop

L_8000AF54:
    // 0x8000AF54: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x8000AF58: nop

    // 0x8000AF5C: bne         $s2, $t6, L_8000AFDC
    if (ctx->r18 != ctx->r14) {
        // 0x8000AF60: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF60: nop

    // 0x8000AF64: lw          $t9, 0x7C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X7C);
    // 0x8000AF68: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000AF6C: jalr        $t9
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    after_0:
    // 0x8000AF74: jal         0x800C8760
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000AF7C: beq         $s1, $zero, L_8000AF98
    if (ctx->r17 == 0) {
        // 0x8000AF80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000AF98;
    }
    // 0x8000AF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AF84: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8000AF88: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000AF8C: nop

    // 0x8000AF90: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8000AF94: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_8000AF98:
    // 0x8000AF98: jal         0x800C8790
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x8000AFA0: bne         $s3, $s6, L_8000AFBC
    if (ctx->r19 != ctx->r22) {
        // 0x8000AFA4: nop
    
            goto L_8000AFBC;
    }
    // 0x8000AFA4: nop

    // 0x8000AFA8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFAC: nop

    // 0x8000AFB0: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x8000AFB4: b           L_8000AFCC
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_8000AFCC;
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
L_8000AFBC:
    // 0x8000AFBC: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFC0: nop

    // 0x8000AFC4: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x8000AFC8: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_8000AFCC:
    // 0x8000AFCC: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFD0: nop

    // 0x8000AFD4: beq         $t5, $zero, L_8000AFE8
    if (ctx->r13 == 0) {
        // 0x8000AFD8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8000AFE8;
    }
    // 0x8000AFD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFDC:
    // 0x8000AFDC: bne         $s1, $zero, L_8000AF3C
    if (ctx->r17 != 0) {
        // 0x8000AFE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AF3C;
    }
    // 0x8000AFE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000AFE4:
    // 0x8000AFE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFE8:
    // 0x8000AFE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AFEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AFF0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AFF4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AFF8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFFC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000B000: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B004: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000B008: jr          $ra
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5094: blez        $a0, L_800C50D0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5098: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C50D0;
    }
    // 0x800C5098: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C509C: beq         $at, $zero, L_800C50D0
    if (ctx->r1 == 0) {
        // 0x800C50A0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C50D0;
    }
    // 0x800C50A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C50A4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C50A8: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C50AC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C50B0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C50B4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C50B8: lh          $t8, 0x20($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X20);
    // 0x800C50BC: lh          $t0, 0x22($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X22);
    // 0x800C50C0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C50C4: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800C50C8: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x800C50CC: sh          $t1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r9;
L_800C50D0:
    // 0x800C50D0: jr          $ra
    // 0x800C50D4: nop

    return;
    // 0x800C50D4: nop

;}
RECOMP_FUNC void func_8000E5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E5EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E5F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E5F4: addiu       $t3, $t3, -0x5160
    ctx->r11 = ADD32(ctx->r11, -0X5160);
    // 0x8000E5F8: addiu       $a2, $a2, -0x5168
    ctx->r6 = ADD32(ctx->r6, -0X5168);
    // 0x8000E5FC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E600: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000E604: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8000E608: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8000E60C: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8000E610: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E614: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E618: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E61C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8000E620: addu        $t4, $t9, $a1
    ctx->r12 = ADD32(ctx->r25, ctx->r5);
    // 0x8000E624: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E628: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000E62C: bne         $at, $zero, L_8000E648
    if (ctx->r1 != 0) {
        // 0x8000E630: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_8000E648;
    }
    // 0x8000E630: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8000E634: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E638: beq         $at, $zero, L_8000E64C
    if (ctx->r1 == 0) {
        // 0x8000E63C: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000E64C;
    }
    // 0x8000E63C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000E640: b           L_8000E66C
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_8000E66C;
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000E648:
    // 0x8000E648: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8000E64C:
    // 0x8000E64C: bne         $at, $zero, L_8000E670
    if (ctx->r1 != 0) {
        // 0x8000E650: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E650: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E654: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000E658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E65C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E660: beq         $at, $zero, L_8000E670
    if (ctx->r1 == 0) {
        // 0x8000E664: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E664: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8000E66C:
    // 0x8000E66C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8000E670:
    // 0x8000E670: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x8000E674: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8000E678: addu        $a3, $sp, $t8
    ctx->r7 = ADD32(ctx->r29, ctx->r24);
    // 0x8000E67C: lw          $a3, 0x2C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E680: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000E684: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x8000E688: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000E68C: beq         $at, $zero, L_8000E6F0
    if (ctx->r1 == 0) {
        // 0x8000E690: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8000E6F0;
    }
    // 0x8000E690: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8000E694: subu        $t2, $a3, $a2
    ctx->r10 = SUB32(ctx->r7, ctx->r6);
    // 0x8000E698: andi        $t9, $t2, 0x3
    ctx->r25 = ctx->r10 & 0X3;
    // 0x8000E69C: beq         $t9, $zero, L_8000E6C0
    if (ctx->r25 == 0) {
        // 0x8000E6A0: addu        $t1, $t9, $a2
        ctx->r9 = ADD32(ctx->r25, ctx->r6);
            goto L_8000E6C0;
    }
    // 0x8000E6A0: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
L_8000E6A4:
    // 0x8000E6A4: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E6AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E6B0: bne         $t1, $a1, L_8000E6A4
    if (ctx->r9 != ctx->r5) {
        // 0x8000E6B4: sb          $t4, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r12;
            goto L_8000E6A4;
    }
    // 0x8000E6B4: sb          $t4, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r12;
    // 0x8000E6B8: beq         $a1, $a3, L_8000E6F0
    if (ctx->r5 == ctx->r7) {
        // 0x8000E6BC: nop
    
            goto L_8000E6F0;
    }
    // 0x8000E6BC: nop

L_8000E6C0:
    // 0x8000E6C0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000E6C8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000E6CC: lbu         $t6, -0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, -0X3);
    // 0x8000E6D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000E6D4: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x8000E6D8: lbu         $t7, -0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, -0X2);
    // 0x8000E6DC: nop

    // 0x8000E6E0: sb          $t7, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r15;
    // 0x8000E6E4: lbu         $t8, -0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, -0X1);
    // 0x8000E6E8: bne         $a1, $a3, L_8000E6C0
    if (ctx->r5 != ctx->r7) {
        // 0x8000E6EC: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_8000E6C0;
    }
    // 0x8000E6EC: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
L_8000E6F0:
    // 0x8000E6F0: addu        $v1, $t3, $t0
    ctx->r3 = ADD32(ctx->r11, ctx->r8);
    // 0x8000E6F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000E6F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E6FC: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x8000E700: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000E704: lw          $a2, -0x51A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X51A4);
    // 0x8000E708: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000E70C: blez        $a2, L_8000E794
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000E710: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8000E794;
    }
    // 0x8000E710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000E714: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E718: addiu       $t3, $t3, -0x51A8
    ctx->r11 = ADD32(ctx->r11, -0X51A8);
L_8000E71C:
    // 0x8000E71C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8000E720: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E724: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E728: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8000E72C: nop

    // 0x8000E730: beq         $v1, $zero, L_8000E78C
    if (ctx->r3 == 0) {
        // 0x8000E734: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E734: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E738: lw          $t1, 0x3C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X3C);
    // 0x8000E73C: nop

    // 0x8000E740: beq         $t1, $zero, L_8000E788
    if (ctx->r9 == 0) {
        // 0x8000E744: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8000E788;
    }
    // 0x8000E744: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000E748: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E74C: or          $t2, $t1, $zero
        ctx->r10 = ctx->r9 | 0;
            goto L_8000E770;
    }
    // 0x8000E74C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8000E750: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000E754: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E758: subu        $t7, $t1, $v0
        ctx->r15 = SUB32(ctx->r9, ctx->r2);
            goto L_8000E770;
    }
    // 0x8000E758: subu        $t7, $t1, $v0
    ctx->r15 = SUB32(ctx->r9, ctx->r2);
    // 0x8000E75C: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x8000E760: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E764: lw          $a2, -0x51A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X51A4);
    // 0x8000E768: b           L_8000E78C
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
        goto L_8000E78C;
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E770:
    // 0x8000E770: bne         $a0, $t2, L_8000E78C
    if (ctx->r4 != ctx->r10) {
        // 0x8000E774: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E774: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E778: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8000E77C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E780: lw          $a2, -0x51A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X51A4);
    // 0x8000E784: nop

L_8000E788:
    // 0x8000E788: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E78C:
    // 0x8000E78C: bne         $at, $zero, L_8000E71C
    if (ctx->r1 != 0) {
        // 0x8000E790: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E71C;
    }
    // 0x8000E790: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8000E794:
    // 0x8000E794: jr          $ra
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_magic_code_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C2E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009C2E8: addiu       $v1, $v1, -0x264
    ctx->r3 = ADD32(ctx->r3, -0X264);
    // 0x8009C2EC: addiu       $v0, $v0, -0x268
    ctx->r2 = ADD32(ctx->r2, -0X268);
    // 0x8009C2F0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009C2F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009C2F8: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8009C2FC: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x8009C300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C304: jr          $ra
    // 0x8009C308: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x8009C308: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void func_8002A31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_extended_frustum_begin(uint8_t*, recomp_context*); dkr_extended_frustum_begin(rdram, ctx);
    // 0x8002A31C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8002A320: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8002A324: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8002A328: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8002A32C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8002A330: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8002A334: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8002A338: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8002A33C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8002A340: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8002A344: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8002A348: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002A34C: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x8002A350: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002A354: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x8002A358: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A35C: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8002A360: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A364: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x8002A368: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A36C: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8002A370: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A374: jal         0x80069DA4
    // 0x8002A378: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x8002A378: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8002A37C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002A380: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002A384: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002A388: addiu       $s1, $s1, -0x2F08
    ctx->r17 = ADD32(ctx->r17, -0X2F08);
    // 0x8002A38C: addiu       $s0, $s0, -0x3754
    ctx->r16 = ADD32(ctx->r16, -0X3754);
    // 0x8002A390: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x8002A394: addiu       $s7, $sp, 0xBC
    ctx->r23 = ADD32(ctx->r29, 0XBC);
    // 0x8002A398: addiu       $s6, $sp, 0xC0
    ctx->r22 = ADD32(ctx->r29, 0XC0);
    // 0x8002A39C: addiu       $s5, $sp, 0xC4
    ctx->r21 = ADD32(ctx->r29, 0XC4);
    // 0x8002A3A0: addiu       $s4, $sp, 0xC8
    ctx->r20 = ADD32(ctx->r29, 0XC8);
    // 0x8002A3A4: addiu       $s3, $sp, 0xCC
    ctx->r19 = ADD32(ctx->r29, 0XCC);
L_8002A3A8:
    // 0x8002A3A8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A3AC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8002A3B0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8002A3B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002A3B8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002A3BC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8002A3C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A3C4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8002A3C8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8002A3CC: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8002A3D0: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x8002A3D4: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    // 0x8002A3D8: jal         0x8006F64C
    // 0x8002A3DC: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8002A3DC: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8002A3E0: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002A3E4: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002A3E8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002A3EC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002A3F0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8002A3F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8002A3F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A3FC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8002A400: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8002A404: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8002A408: swc1        $f14, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f14.u32l;
    // 0x8002A40C: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    // 0x8002A410: jal         0x8006F64C
    // 0x8002A414: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x8002A414: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002A418: lwc1        $f26, 0x18($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8002A41C: lwc1        $f28, 0x1C($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8002A420: lwc1        $f30, 0x20($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8002A424: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002A428: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x8002A42C: addiu       $t8, $sp, 0xAC
    ctx->r24 = ADD32(ctx->r29, 0XAC);
    // 0x8002A430: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8002A434: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8002A438: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8002A43C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8002A440: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002A444: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002A448: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A44C: swc1        $f26, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f26.u32l;
    // 0x8002A450: swc1        $f28, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f28.u32l;
    // 0x8002A454: jal         0x8006F64C
    // 0x8002A458: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8002A458: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    after_3:
    // 0x8002A45C: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8002A460: lwc1        $f30, 0xAC($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002A464: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A468: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002A46C: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A470: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002A474: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002A478: lwc1        $f28, 0xB0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8002A47C: lwc1        $f14, 0xC0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002A480: sub.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002A484: lwc1        $f26, 0xB4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8002A488: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002A48C: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002A490: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A494: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002A498: mul.s       $f6, $f28, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x8002A49C: sub.s       $f10, $f14, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f26.fl;
    // 0x8002A4A0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002A4A4: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002A4A8: sub.s       $f4, $f26, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8002A4AC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A4B0: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8002A4B4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A4B8: mul.s       $f8, $f30, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x8002A4BC: sub.s       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002A4C0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002A4C4: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002A4C8: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002A4CC: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002A4D0: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002A4D4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A4D8: mul.s       $f4, $f26, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x8002A4DC: nop

    // 0x8002A4E0: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002A4E4: add.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002A4E8: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002A4EC: nop

    // 0x8002A4F0: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002A4F4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A4F8: jal         0x800C9AD0
    // 0x8002A4FC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A4FC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_4:
    // 0x8002A500: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002A504: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A508: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A50C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A510: nop

    // 0x8002A514: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002A518: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002A51C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A520: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A524: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002A528: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002A52C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002A530: nop

    // 0x8002A534: bc1f        L_8002A554
    if (!c1cs) {
        // 0x8002A538: nop
    
            goto L_8002A554;
    }
    // 0x8002A538: nop

    // 0x8002A53C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002A540: nop

    // 0x8002A544: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8002A548: nop

    // 0x8002A54C: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002A550: nop

L_8002A554:
    // 0x8002A554: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8002A558: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A55C: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A560: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A564: mul.s       $f6, $f2, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002A568: addiu       $t9, $t9, -0x2ED8
    ctx->r25 = ADD32(ctx->r25, -0X2ED8);
    // 0x8002A56C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8002A570: swc1        $f20, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f20.u32l;
    // 0x8002A574: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002A578: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002A57C: swc1        $f22, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = ctx->f22.u32l;
    // 0x8002A580: swc1        $f24, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->f24.u32l;
    // 0x8002A584: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A588: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x8002A58C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8002A590: bne         $s1, $t9, L_8002A3A8
    if (ctx->r17 != ctx->r25) {
        // 0x8002A594: swc1        $f6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
            goto L_8002A3A8;
    }
    // 0x8002A594: swc1        $f6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8002A598: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8002A59C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A5A0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A5A4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002A5A8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A5AC: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002A5B0: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002A5B4: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002A5B8: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002A5BC: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8002A5C0: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A5C4: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8002A5C8: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A5CC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8002A5D0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8002A5D4: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8002A5D8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8002A5DC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8002A5E0: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8002A5E4: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8002A5E8: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8002A5EC: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    extern void dkr_extended_frustum_end(uint8_t*, recomp_context*); dkr_extended_frustum_end(rdram, ctx);
    // 0x8002A5F0: jr          $ra
    // 0x8002A5F4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8002A5F4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void rain_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD144: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD148: addiu       $v0, $v0, 0x2C60
    ctx->r2 = ADD32(ctx->r2, 0X2C60);
    // 0x800AD14C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800AD150: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD154: sw          $zero, 0x2C64($at)
    MEM_W(0X2C64, ctx->r1) = 0;
    // 0x800AD158: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AD15C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD160: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD164: sw          $t6, 0x2C68($at)
    MEM_W(0X2C68, ctx->r1) = ctx->r14;
    // 0x800AD168: addiu       $v1, $v1, 0x2C6C
    ctx->r3 = ADD32(ctx->r3, 0X2C6C);
    // 0x800AD16C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AD170: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD174: sw          $zero, 0x2C70($at)
    MEM_W(0X2C70, ctx->r1) = 0;
    // 0x800AD178: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AD17C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD180: sw          $t7, 0x2C74($at)
    MEM_W(0X2C74, ctx->r1) = ctx->r15;
    // 0x800AD184: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD188: sw          $zero, 0x2C78($at)
    MEM_W(0X2C78, ctx->r1) = 0;
    // 0x800AD18C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD190: sw          $zero, 0x2C7C($at)
    MEM_W(0X2C7C, ctx->r1) = 0;
    // 0x800AD194: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD198: sw          $zero, 0x2C80($at)
    MEM_W(0X2C80, ctx->r1) = 0;
    // 0x800AD19C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD1A0: sw          $zero, 0x2C84($at)
    MEM_W(0X2C84, ctx->r1) = 0;
    // 0x800AD1A4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AD1A8: lw          $t8, 0x291C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X291C);
    // 0x800AD1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD1B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD1B8: sw          $zero, 0x2C90($at)
    MEM_W(0X2C90, ctx->r1) = 0;
    // 0x800AD1BC: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x800AD1C0: jal         0x8007AE74
    // 0x800AD1C4: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AD1C4: nop

    after_0:
    // 0x800AD1C8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AD1CC: lw          $t9, 0x291C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X291C);
    // 0x800AD1D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD1D4: sw          $v0, 0x2C38($at)
    MEM_W(0X2C38, ctx->r1) = ctx->r2;
    // 0x800AD1D8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800AD1DC: jal         0x8007AE74
    // 0x800AD1E0: nop

    load_texture(rdram, ctx);
        goto after_1;
    // 0x800AD1E0: nop

    after_1:
    // 0x800AD1E4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD1E8: lw          $t0, 0x291C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X291C);
    // 0x800AD1EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD1F0: sw          $v0, 0x2C50($at)
    MEM_W(0X2C50, ctx->r1) = ctx->r2;
    // 0x800AD1F4: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x800AD1F8: jal         0x8007C12C
    // 0x800AD1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800AD1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AD200: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD208: sw          $v0, 0x2C8C($at)
    MEM_W(0X2C8C, ctx->r1) = ctx->r2;
    // 0x800AD20C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD210: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AD214: sw          $t1, 0x2C5C($at)
    MEM_W(0X2C5C, ctx->r1) = ctx->r9;
    // 0x800AD218: jr          $ra
    // 0x800AD21C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD21C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void disable_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066520: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066524: jr          $ra
    // 0x80066528: sb          $zero, 0xD14($at)
    MEM_B(0XD14, ctx->r1) = 0;
    return;
    // 0x80066528: sb          $zero, 0xD14($at)
    MEM_B(0XD14, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086A4C: lw          $t6, 0x6BD4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BD4);
    // 0x80086A50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086A54: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80086A58: lw          $t7, 0x6BE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BE4);
    // 0x80086A5C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086A60: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80086A64: blez        $a0, L_80086AF4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80086A68: cvt.s.w     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80086AF4;
    }
    // 0x80086A68: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086A6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80086A70: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086A74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086A78: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80086A7C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086A80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086A84: lwc1        $f16, -0x7BEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7BEC);
    // 0x80086A88: lw          $v1, 0x63E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63E0);
    // 0x80086A8C: lw          $v0, 0x6A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A08);
    // 0x80086A90: addiu       $a1, $a1, 0x6BDC
    ctx->r5 = ADD32(ctx->r5, 0X6BDC);
    // 0x80086A94: addiu       $a2, $a2, 0x6A00
    ctx->r6 = ADD32(ctx->r6, 0X6A00);
    // 0x80086A98: addiu       $a3, $a3, 0x6BEC
    ctx->r7 = ADD32(ctx->r7, 0X6BEC);
L_80086A9C:
    // 0x80086A9C: blez        $v0, L_80086ABC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80086AA0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80086ABC;
    }
    // 0x80086AA0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80086AA4: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80086AA8: nop

    // 0x80086AAC: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80086AB0: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086AB4: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80086AB8: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80086ABC:
    // 0x80086ABC: blez        $v1, L_80086AEC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80086AC0: nop
    
            goto L_80086AEC;
    }
    // 0x80086AC0: nop

    // 0x80086AC4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086AC8: nop

    // 0x80086ACC: blez        $t8, L_80086AEC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086AD0: nop
    
            goto L_80086AEC;
    }
    // 0x80086AD0: nop

    // 0x80086AD4: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80086AD8: nop

    // 0x80086ADC: sub.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80086AE0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086AE4: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80086AE8: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_80086AEC:
    // 0x80086AEC: bgtz        $a0, L_80086A9C
    if (SIGNED(ctx->r4) > 0) {
        // 0x80086AF0: nop
    
            goto L_80086A9C;
    }
    // 0x80086AF0: nop

L_80086AF4:
    // 0x80086AF4: jr          $ra
    // 0x80086AF8: nop

    return;
    // 0x80086AF8: nop

;}
RECOMP_FUNC void mempool_print_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071CE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071CEC: lw          $v0, 0x35C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35C0);
    // 0x80071CF0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80071CF4: beq         $v0, $a1, L_80071D28
    if (ctx->r2 == ctx->r5) {
        // 0x80071CF8: addiu       $a0, $v0, 0x1
        ctx->r4 = ADD32(ctx->r2, 0X1);
            goto L_80071D28;
    }
    // 0x80071CF8: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80071CFC: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80071D00: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80071D04: beq         $a0, $zero, L_80071D1C
    if (ctx->r4 == 0) {
        // 0x80071D08: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_80071D1C;
    }
    // 0x80071D08: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_80071D0C:
    // 0x80071D0C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80071D10: bne         $v1, $v0, L_80071D0C
    if (ctx->r3 != ctx->r2) {
        // 0x80071D14: nop
    
            goto L_80071D0C;
    }
    // 0x80071D14: nop

    // 0x80071D18: beq         $v0, $a1, L_80071D28
    if (ctx->r2 == ctx->r5) {
        // 0x80071D1C: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071D28;
    }
L_80071D1C:
    // 0x80071D1C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071D20:
    // 0x80071D20: bne         $v0, $a1, L_80071D20
    if (ctx->r2 != ctx->r5) {
        // 0x80071D24: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071D20;
    }
    // 0x80071D24: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071D28:
    // 0x80071D28: jr          $ra
    // 0x80071D2C: nop

    return;
    // 0x80071D2C: nop

;}
RECOMP_FUNC void func_80024594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024594: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80024598: lw          $t6, -0x3900($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3900);
    // 0x8002459C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800245A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800245A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800245A8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800245AC: jr          $ra
    // 0x800245B0: addiu       $v0, $v0, -0x53E0
    ctx->r2 = ADD32(ctx->r2, -0X53E0);
    return;
    // 0x800245B0: addiu       $v0, $v0, -0x53E0
    ctx->r2 = ADD32(ctx->r2, -0X53E0);
;}
RECOMP_FUNC void func_8000CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000CBF4: addiu       $t7, $t7, -0x51F8
    ctx->r15 = ADD32(ctx->r15, -0X51F8);
    // 0x8000CBF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000CBFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000CC00: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC04: nop

    // 0x8000CC08: bne         $v1, $zero, L_8000CC18
    if (ctx->r3 != 0) {
        // 0x8000CC0C: nop
    
            goto L_8000CC18;
    }
    // 0x8000CC0C: nop

    // 0x8000CC10: jr          $ra
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8000CC18:
    // 0x8000CC18: jr          $ra
    // 0x8000CC1C: nop

    return;
    // 0x8000CC1C: nop

;}
RECOMP_FUNC void menu_results_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800972A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800972AC: addiu       $v0, $v0, 0x63BC
    ctx->r2 = ADD32(ctx->r2, 0X63BC);
    // 0x800972B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800972B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800972B8: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x800972BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800972C0: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x800972C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800972C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800972CC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800972D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800972D4: jal         0x8008E4EC
    // 0x800972D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    menu_input(rdram, ctx);
        goto after_0;
    // 0x800972D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x800972DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800972E0: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x800972E4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800972E8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800972EC: bgtz        $v1, L_8009733C
    if (SIGNED(ctx->r3) > 0) {
        // 0x800972F0: addiu       $a3, $a3, 0x63D8
        ctx->r7 = ADD32(ctx->r7, 0X63D8);
            goto L_8009733C;
    }
    // 0x800972F0: addiu       $a3, $a3, 0x63D8
    ctx->r7 = ADD32(ctx->r7, 0X63D8);
    // 0x800972F4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800972F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800972FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80097300: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80097304: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x80097308: bne         $at, $zero, L_80097318
    if (ctx->r1 != 0) {
        // 0x8009730C: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80097318;
    }
    // 0x8009730C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80097310: b           L_8009733C
    // 0x80097314: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_8009733C;
    // 0x80097314: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80097318:
    // 0x80097318: bgez        $v1, L_8009733C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009731C: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8009733C;
    }
    // 0x8009731C: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80097320: bne         $at, $zero, L_8009733C
    if (ctx->r1 != 0) {
        // 0x80097324: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8009733C;
    }
    // 0x80097324: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80097328: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009732C: jal         0x80001D04
    // 0x80097330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80097330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80097334: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097338: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
L_8009733C:
    // 0x8009733C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80097340: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x80097344: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80097348: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009734C: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80097350: addiu       $a3, $a3, 0x63D8
    ctx->r7 = ADD32(ctx->r7, 0X63D8);
    // 0x80097354: beq         $at, $zero, L_800973F4
    if (ctx->r1 == 0) {
        // 0x80097358: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800973F4;
    }
    // 0x80097358: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009735C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80097360: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097364: bgtz        $t5, L_800973D0
    if (SIGNED(ctx->r13) > 0) {
        // 0x80097368: nop
    
            goto L_800973D0;
    }
    // 0x80097368: nop

    // 0x8009736C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80097370: nop

    // 0x80097374: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80097378: bne         $at, $zero, L_800973F4
    if (ctx->r1 != 0) {
        // 0x8009737C: addiu       $t6, $v0, -0x14
        ctx->r14 = ADD32(ctx->r2, -0X14);
            goto L_800973F4;
    }
    // 0x8009737C: addiu       $t6, $v0, -0x14
    ctx->r14 = ADD32(ctx->r2, -0X14);
    // 0x80097380: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80097384: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80097388: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009738C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80097390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80097394: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80097398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009739C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800973A0: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800973A4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800973A8: jal         0x80096978
    // 0x800973AC: nop

    results_render(rdram, ctx);
        goto after_2;
    // 0x800973AC: nop

    after_2:
    // 0x800973B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800973B4: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x800973B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800973BC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800973C0: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x800973C4: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x800973C8: b           L_800973F4
    // 0x800973CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800973F4;
    // 0x800973CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800973D0:
    // 0x800973D0: jal         0x80096978
    // 0x800973D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    results_render(rdram, ctx);
        goto after_3;
    // 0x800973D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x800973D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800973DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800973E0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800973E4: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x800973E8: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x800973EC: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x800973F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800973F4:
    // 0x800973F4: bne         $v1, $zero, L_80097618
    if (ctx->r3 != 0) {
        // 0x800973F8: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_80097618;
    }
    // 0x800973F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800973FC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80097400: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097404: bne         $t7, $zero, L_8009742C
    if (ctx->r15 != 0) {
        // 0x80097408: addiu       $a0, $a0, 0x988
        ctx->r4 = ADD32(ctx->r4, 0X988);
            goto L_8009742C;
    }
    // 0x80097408: addiu       $a0, $a0, 0x988
    ctx->r4 = ADD32(ctx->r4, 0X988);
    // 0x8009740C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80097410: lw          $t8, 0x67E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X67E8);
    // 0x80097414: nop

    // 0x80097418: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x8009741C: beq         $t9, $zero, L_800975C0
    if (ctx->r25 == 0) {
        // 0x80097420: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_800975C0;
    }
    // 0x80097420: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097424: b           L_800975BC
    // 0x80097428: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_800975BC;
    // 0x80097428: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_8009742C:
    // 0x8009742C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80097430: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097434: beq         $v0, $zero, L_800974EC
    if (ctx->r2 == 0) {
        // 0x80097438: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800974EC;
    }
    // 0x80097438: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009743C: lw          $v1, 0x67E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X67E8);
    // 0x80097440: nop

    // 0x80097444: andi        $t2, $v1, 0x9000
    ctx->r10 = ctx->r3 & 0X9000;
    // 0x80097448: beq         $t2, $zero, L_8009748C
    if (ctx->r10 == 0) {
        // 0x8009744C: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_8009748C;
    }
    // 0x8009744C: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x80097450: bne         $t0, $v0, L_80097480
    if (ctx->r8 != ctx->r2) {
        // 0x80097454: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80097480;
    }
    // 0x80097454: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80097458: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8009745C: jal         0x80000C98
    // 0x80097460: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x80097460: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x80097464: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097468: jal         0x800C01D8
    // 0x8009746C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x8009746C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_5:
    // 0x80097470: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80097474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097478: b           L_800975BC
    // 0x8009747C: sw          $t0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r8;
        goto L_800975BC;
    // 0x8009747C: sw          $t0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r8;
L_80097480:
    // 0x80097480: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80097484: b           L_800975BC
    // 0x80097488: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800975BC;
    // 0x80097488: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8009748C:
    // 0x8009748C: beq         $t4, $zero, L_800974A4
    if (ctx->r12 == 0) {
        // 0x80097490: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800974A4;
    }
    // 0x80097490: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097494: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80097498: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8009749C: b           L_800975BC
    // 0x800974A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800975BC;
    // 0x800974A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800974A4:
    // 0x800974A4: lh          $v1, 0x6838($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6838);
    // 0x800974A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800974AC: blez        $v1, L_800974C4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800974B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800974C4;
    }
    // 0x800974B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800974B4: bne         $v0, $at, L_800974C4
    if (ctx->r2 != ctx->r1) {
        // 0x800974B8: nop
    
            goto L_800974C4;
    }
    // 0x800974B8: nop

    // 0x800974BC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800974C0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800974C4:
    // 0x800974C4: bgez        $v1, L_800974DC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800974C8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800974DC;
    }
    // 0x800974C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800974CC: bne         $t0, $v0, L_800974DC
    if (ctx->r8 != ctx->r2) {
        // 0x800974D0: nop
    
            goto L_800974DC;
    }
    // 0x800974D0: nop

    // 0x800974D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800974D8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800974DC:
    // 0x800974DC: beq         $a1, $v0, L_800975C0
    if (ctx->r5 == ctx->r2) {
        // 0x800974E0: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_800975C0;
    }
    // 0x800974E0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800974E4: b           L_800975BC
    // 0x800974E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_800975BC;
    // 0x800974E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_800974EC:
    // 0x800974EC: lw          $t8, 0x67E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X67E8);
    // 0x800974F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800974F4: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x800974F8: beq         $t9, $zero, L_80097560
    if (ctx->r25 == 0) {
        // 0x800974FC: addiu       $a2, $a2, 0x6A68
        ctx->r6 = ADD32(ctx->r6, 0X6A68);
            goto L_80097560;
    }
    // 0x800974FC: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x80097500: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097504: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x80097508: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8009750C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80097510: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x80097514: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80097518: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8009751C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80097520: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80097524: lw          $t4, 0x6BF0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BF0);
    // 0x80097528: lw          $t6, 0x70($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X70);
    // 0x8009752C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80097530: bne         $t4, $t6, L_80097540
    if (ctx->r12 != ctx->r14) {
        // 0x80097534: nop
    
            goto L_80097540;
    }
    // 0x80097534: nop

    // 0x80097538: b           L_800975BC
    // 0x8009753C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800975BC;
    // 0x8009753C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80097540:
    // 0x80097540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097544: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80097548: jal         0x800C01D8
    // 0x8009754C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_6;
    // 0x8009754C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_6:
    // 0x80097550: jal         0x80000C98
    // 0x80097554: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_7;
    // 0x80097554: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_7:
    // 0x80097558: b           L_800975C0
    // 0x8009755C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
        goto L_800975C0;
    // 0x8009755C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_80097560:
    // 0x80097560: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097564: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80097568: lh          $v1, 0x6838($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6838);
    // 0x8009756C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80097570: bgez        $v1, L_80097598
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80097574: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80097598;
    }
    // 0x80097574: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80097578: lw          $t8, 0x6C14($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C14);
    // 0x8009757C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80097580: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80097584: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80097588: beq         $at, $zero, L_80097598
    if (ctx->r1 == 0) {
        // 0x8009758C: nop
    
            goto L_80097598;
    }
    // 0x8009758C: nop

    // 0x80097590: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80097594: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80097598:
    // 0x80097598: blez        $v1, L_800975B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009759C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800975B0;
    }
    // 0x8009759C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800975A0: blez        $v0, L_800975B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800975A4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800975B0;
    }
    // 0x800975A4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800975A8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800975AC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800975B0:
    // 0x800975B0: beq         $a1, $v0, L_800975C0
    if (ctx->r5 == ctx->r2) {
        // 0x800975B4: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_800975C0;
    }
    // 0x800975B4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800975B8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_800975BC:
    // 0x800975BC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_800975C0:
    // 0x800975C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800975C4: beq         $t4, $zero, L_800975DC
    if (ctx->r12 == 0) {
        // 0x800975C8: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800975DC;
    }
    // 0x800975C8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800975CC: jal         0x80001D04
    // 0x800975D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800975D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800975D4: b           L_800976B0
    // 0x800975D8: nop

        goto L_800976B0;
    // 0x800975D8: nop

L_800975DC:
    // 0x800975DC: beq         $t6, $zero, L_800975F4
    if (ctx->r14 == 0) {
        // 0x800975E0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800975F4;
    }
    // 0x800975E0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800975E4: jal         0x80001D04
    // 0x800975E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800975E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800975EC: b           L_800976B0
    // 0x800975F0: nop

        goto L_800976B0;
    // 0x800975F0: nop

L_800975F4:
    // 0x800975F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800975F8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800975FC: beq         $t7, $zero, L_800976B0
    if (ctx->r15 == 0) {
        // 0x80097600: nop
    
            goto L_800976B0;
    }
    // 0x80097600: nop

    // 0x80097604: jal         0x80001D04
    // 0x80097608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80097608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8009760C: b           L_800976B0
    // 0x80097610: nop

        goto L_800976B0;
    // 0x80097610: nop

    // 0x80097614: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_80097618:
    // 0x80097618: nop

    // 0x8009761C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80097620: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x80097624: bne         $at, $zero, L_800976B0
    if (ctx->r1 != 0) {
        // 0x80097628: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_800976B0;
    }
    // 0x80097628: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8009762C: jal         0x800976CC
    // 0x80097630: nop

    results_free(rdram, ctx);
        goto after_11;
    // 0x80097630: nop

    after_11:
    // 0x80097634: jal         0x800C5620
    // 0x80097638: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_12;
    // 0x80097638: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_12:
    // 0x8009763C: jal         0x800C5494
    // 0x80097640: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_13;
    // 0x80097640: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_13:
    // 0x80097644: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097648: addiu       $a2, $a2, 0x6A68
    ctx->r6 = ADD32(ctx->r6, 0X6A68);
    // 0x8009764C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80097650: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80097654: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80097658: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009765C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80097660: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80097664: lw          $v0, 0x6BF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BF0);
    // 0x80097668: lw          $t4, 0x5C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X5C);
    // 0x8009766C: nop

    // 0x80097670: bne         $v0, $t4, L_80097680
    if (ctx->r2 != ctx->r12) {
        // 0x80097674: nop
    
            goto L_80097680;
    }
    // 0x80097674: nop

    // 0x80097678: b           L_800976BC
    // 0x8009767C: addiu       $v0, $zero, 0x102
    ctx->r2 = ADD32(0, 0X102);
        goto L_800976BC;
    // 0x8009767C: addiu       $v0, $zero, 0x102
    ctx->r2 = ADD32(0, 0X102);
L_80097680:
    // 0x80097680: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x80097684: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80097688: bne         $v0, $t6, L_800976A8
    if (ctx->r2 != ctx->r14) {
        // 0x8009768C: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800976A8;
    }
    // 0x8009768C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80097690: jal         0x8006E2E8
    // 0x80097694: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_14;
    // 0x80097694: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80097698: jal         0x800813D0
    // 0x8009769C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x8009769C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_15:
    // 0x800976A0: b           L_800976BC
    // 0x800976A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800976BC;
    // 0x800976A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800976A8:
    // 0x800976A8: b           L_800976BC
    // 0x800976AC: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
        goto L_800976BC;
    // 0x800976AC: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
L_800976B0:
    // 0x800976B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800976B4: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x800976B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800976BC:
    // 0x800976BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800976C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800976C4: jr          $ra
    // 0x800976C8: nop

    return;
    // 0x800976C8: nop

;}
RECOMP_FUNC void timetrial_staff_ghost_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B3B0: lw          $t6, -0x38E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X38E8);
    // 0x8001B3B4: nop

    // 0x8001B3B8: xor         $v0, $a0, $t6
    ctx->r2 = ctx->r4 ^ ctx->r14;
    // 0x8001B3BC: jr          $ra
    // 0x8001B3C0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8001B3C0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
