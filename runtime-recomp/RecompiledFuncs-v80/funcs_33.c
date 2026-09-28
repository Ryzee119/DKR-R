#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_audio_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C74: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084C78: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x80084C7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80084C80: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084C84: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x80084C88: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80084C8C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80084C90: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80084C94: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80084C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80084C9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80084CA0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80084CA4: beq         $v0, $zero, L_80084CCC
    if (ctx->r2 == 0) {
        // 0x80084CA8: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80084CCC;
    }
    // 0x80084CA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80084CAC: blez        $v0, L_80084CC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80084CB0: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_80084CC4;
    }
    // 0x80084CB0: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x80084CB4: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80084CB8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80084CBC: b           L_80084CCC
    // 0x80084CC0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80084CCC;
    // 0x80084CC0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80084CC4:
    // 0x80084CC4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80084CC8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80084CCC:
    // 0x80084CCC: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80084CD0: bne         $at, $zero, L_80084CF0
    if (ctx->r1 != 0) {
        // 0x80084CD4: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80084CF0;
    }
    // 0x80084CD4: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80084CD8: beq         $at, $zero, L_80084CF0
    if (ctx->r1 == 0) {
        // 0x80084CDC: nop
    
            goto L_80084CF0;
    }
    // 0x80084CDC: nop

    // 0x80084CE0: jal         0x80084854
    // 0x80084CE4: nop

    func_80084854(rdram, ctx);
        goto after_0;
    // 0x80084CE4: nop

    after_0:
    // 0x80084CE8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084CEC: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80084CF0:
    // 0x80084CF0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80084CF4: lw          $t3, 0x63C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63C4);
    // 0x80084CF8: nop

    // 0x80084CFC: bne         $t3, $zero, L_800851B0
    if (ctx->r11 != 0) {
        // 0x80084D00: nop
    
            goto L_800851B0;
    }
    // 0x80084D00: nop

    // 0x80084D04: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80084D08: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80084D0C: bne         $t4, $zero, L_800851B0
    if (ctx->r12 != 0) {
        // 0x80084D10: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800851B0;
    }
    // 0x80084D10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80084D14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084D18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084D1C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80084D20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084D24: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x80084D28: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
    // 0x80084D2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80084D30:
    // 0x80084D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80084D34: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80084D38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80084D3C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80084D40: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80084D44: jal         0x8006A554
    // 0x80084D48: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80084D48: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80084D4C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80084D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80084D54: or          $t6, $t5, $v0
    ctx->r14 = ctx->r13 | ctx->r2;
    // 0x80084D58: jal         0x8006A59C
    // 0x80084D5C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    input_clamp_stick_x(rdram, ctx);
        goto after_2;
    // 0x80084D5C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_2:
    // 0x80084D60: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80084D64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80084D68: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80084D6C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80084D70: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80084D74: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80084D78: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x80084D7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80084D80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80084D84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084D88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80084D8C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80084D90: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80084D94: bne         $s0, $at, L_80084D30
    if (ctx->r16 != ctx->r1) {
        // 0x80084D98: addu        $a3, $a3, $t8
        ctx->r7 = ADD32(ctx->r7, ctx->r24);
            goto L_80084D30;
    }
    // 0x80084D98: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x80084D9C: bgez        $a2, L_80084DB8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80084DA0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80084DB8;
    }
    // 0x80084DA0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084DA4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x80084DA8: blez        $a2, L_80084DCC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80084DAC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80084DCC;
    }
    // 0x80084DAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80084DB0: b           L_80084DC8
    // 0x80084DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80084DC8;
    // 0x80084DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80084DB8:
    // 0x80084DB8: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    // 0x80084DBC: bgez        $a2, L_80084DCC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80084DC0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80084DCC;
    }
    // 0x80084DC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80084DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80084DC8:
    // 0x80084DC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80084DCC:
    // 0x80084DCC: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80084DD0: andi        $t2, $a0, 0x9000
    ctx->r10 = ctx->r4 & 0X9000;
    // 0x80084DD4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80084DD8: beq         $t2, $zero, L_80084DFC
    if (ctx->r10 == 0) {
        // 0x80084DDC: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80084DFC;
    }
    // 0x80084DDC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80084DE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80084DE4: lh          $t4, 0x6C46($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X6C46);
    // 0x80084DE8: addiu       $v1, $v1, 0x63E0
    ctx->r3 = ADD32(ctx->r3, 0X63E0);
    // 0x80084DEC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80084DF0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80084DF4: beq         $t3, $t5, L_80084E14
    if (ctx->r11 == ctx->r13) {
        // 0x80084DF8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80084E14;
    }
    // 0x80084DF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80084DFC:
    // 0x80084DFC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80084E00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084E04: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80084E08: beq         $t7, $zero, L_80084E50
    if (ctx->r15 == 0) {
        // 0x80084E0C: addiu       $v1, $v1, 0x63E0
        ctx->r3 = ADD32(ctx->r3, 0X63E0);
            goto L_80084E50;
    }
    // 0x80084E0C: addiu       $v1, $v1, 0x63E0
    ctx->r3 = ADD32(ctx->r3, 0X63E0);
    // 0x80084E10: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80084E14:
    // 0x80084E14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084E18: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084E1C: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
    // 0x80084E20: jal         0x800C01D8
    // 0x80084E24: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80084E24: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_3:
    // 0x80084E28: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084E2C: lw          $t9, 0x63D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63D8);
    // 0x80084E30: nop

    // 0x80084E34: bltz        $t9, L_80084E48
    if (SIGNED(ctx->r25) < 0) {
        // 0x80084E38: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80084E48;
    }
    // 0x80084E38: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80084E3C: jal         0x80000C98
    // 0x80084E40: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x80084E40: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x80084E44: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80084E48:
    // 0x80084E48: b           L_80085100
    // 0x80084E4C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80085100;
    // 0x80084E4C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80084E50:
    // 0x80084E50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084E54: lh          $v0, 0x6C46($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6C46);
    // 0x80084E58: bgez        $a3, L_80084E88
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80084E5C: nop
    
            goto L_80084E88;
    }
    // 0x80084E5C: nop

    // 0x80084E60: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80084E64: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80084E68: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x80084E6C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80084E70: beq         $at, $zero, L_80084E88
    if (ctx->r1 == 0) {
        // 0x80084E74: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80084E88;
    }
    // 0x80084E74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80084E78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084E7C: sh          $t5, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = ctx->r13;
    // 0x80084E80: b           L_80085100
    // 0x80084E84: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085100;
    // 0x80084E84: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_80084E88:
    // 0x80084E88: blez        $a3, L_80084EAC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80084E8C: nop
    
            goto L_80084EAC;
    }
    // 0x80084E8C: nop

    // 0x80084E90: blez        $v0, L_80084EAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80084E94: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80084EAC;
    }
    // 0x80084E94: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80084E98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084E9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80084EA0: sh          $t7, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = ctx->r15;
    // 0x80084EA4: b           L_80085100
    // 0x80084EA8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80085100;
    // 0x80084EA8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80084EAC:
    // 0x80084EAC: bne         $v0, $zero, L_80084F34
    if (ctx->r2 != 0) {
        // 0x80084EB0: nop
    
            goto L_80084F34;
    }
    // 0x80084EB0: nop

    // 0x80084EB4: beq         $t0, $zero, L_80084F34
    if (ctx->r8 == 0) {
        // 0x80084EB8: nop
    
            goto L_80084F34;
    }
    // 0x80084EB8: nop

    // 0x80084EBC: bgez        $t0, L_80084EE0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80084EC0: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80084EE0;
    }
    // 0x80084EC0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084EC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084EC8: addiu       $v0, $v0, -0x538
    ctx->r2 = ADD32(ctx->r2, -0X538);
    // 0x80084ECC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80084ED0: nop

    // 0x80084ED4: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80084ED8: b           L_80084EF4
    // 0x80084EDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_80084EF4;
    // 0x80084EDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80084EE0:
    // 0x80084EE0: addiu       $v0, $v0, -0x538
    ctx->r2 = ADD32(ctx->r2, -0X538);
    // 0x80084EE4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80084EE8: nop

    // 0x80084EEC: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80084EF0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80084EF4:
    // 0x80084EF4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80084EF8: nop

    // 0x80084EFC: bgez        $a0, L_80084F10
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80084F00: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80084F10;
    }
    // 0x80084F00: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80084F04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80084F08: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80084F0C: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80084F10:
    // 0x80084F10: bne         $at, $zero, L_80084F20
    if (ctx->r1 != 0) {
        // 0x80084F14: nop
    
            goto L_80084F20;
    }
    // 0x80084F14: nop

    // 0x80084F18: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80084F1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80084F20:
    // 0x80084F20: jal         0x80065BD0
    // 0x80084F24: nop

    set_stereo_pan_mode(rdram, ctx);
        goto after_5;
    // 0x80084F24: nop

    after_5:
    // 0x80084F28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80084F2C: b           L_80085100
    // 0x80084F30: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085100;
    // 0x80084F30: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_80084F34:
    // 0x80084F34: beq         $a2, $zero, L_80085054
    if (ctx->r6 == 0) {
        // 0x80084F38: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80085054;
    }
    // 0x80084F38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80084F3C: beq         $v0, $at, L_80084F48
    if (ctx->r2 == ctx->r1) {
        // 0x80084F40: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80084F48;
    }
    // 0x80084F40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084F44: bne         $v0, $at, L_80085054
    if (ctx->r2 != ctx->r1) {
        // 0x80084F48: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80085054;
    }
L_80084F48:
    // 0x80084F48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80084F4C: bne         $v0, $at, L_80084F9C
    if (ctx->r2 != ctx->r1) {
        // 0x80084F50: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80084F9C;
    }
    // 0x80084F50: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80084F54: addiu       $v1, $v1, -0x540
    ctx->r3 = ADD32(ctx->r3, -0X540);
    // 0x80084F58: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80084F5C: nop

    // 0x80084F60: addu        $v0, $t7, $a2
    ctx->r2 = ADD32(ctx->r15, ctx->r6);
    // 0x80084F64: bgez        $v0, L_80084F78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80084F68: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80084F78;
    }
    // 0x80084F68: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80084F6C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80084F70: b           L_80084F8C
    // 0x80084F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084F8C;
    // 0x80084F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084F78:
    // 0x80084F78: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80084F7C: bne         $at, $zero, L_80084F8C
    if (ctx->r1 != 0) {
        // 0x80084F80: nop
    
            goto L_80084F8C;
    }
    // 0x80084F80: nop

    // 0x80084F84: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80084F88: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80084F8C:
    // 0x80084F8C: jal         0x80003160
    // 0x80084F90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_set_global_volume(rdram, ctx);
        goto after_6;
    // 0x80084F90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80084F94: b           L_80085100
    // 0x80084F98: nop

        goto L_80085100;
    // 0x80084F98: nop

L_80084F9C:
    // 0x80084F9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084FA0: bne         $v0, $at, L_80085100
    if (ctx->r2 != ctx->r1) {
        // 0x80084FA4: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80085100;
    }
    // 0x80084FA4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80084FA8: addiu       $v1, $v1, -0x53C
    ctx->r3 = ADD32(ctx->r3, -0X53C);
    // 0x80084FAC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80084FB0: nop

    // 0x80084FB4: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x80084FB8: bgez        $v0, L_80084FCC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80084FBC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80084FCC;
    }
    // 0x80084FBC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80084FC0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80084FC4: b           L_80084FE0
    // 0x80084FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084FE0;
    // 0x80084FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084FCC:
    // 0x80084FCC: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80084FD0: bne         $at, $zero, L_80084FE0
    if (ctx->r1 != 0) {
        // 0x80084FD4: nop
    
            goto L_80084FE0;
    }
    // 0x80084FD4: nop

    // 0x80084FD8: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80084FDC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80084FE0:
    // 0x80084FE0: jal         0x80001A3C
    // 0x80084FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    music_volume_config_set(rdram, ctx);
        goto after_7;
    // 0x80084FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80084FE8: jal         0x800015C8
    // 0x80084FEC: nop

    music_is_playing(rdram, ctx);
        goto after_8;
    // 0x80084FEC: nop

    after_8:
    // 0x80084FF0: bne         $v0, $zero, L_80085100
    if (ctx->r2 != 0) {
        // 0x80084FF4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80085100;
    }
    // 0x80084FF4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80084FF8: lw          $t5, 0x63D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63D8);
    // 0x80084FFC: nop

    // 0x80085000: bltz        $t5, L_8008502C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80085004: nop
    
            goto L_8008502C;
    }
    // 0x80085004: nop

    // 0x80085008: jal         0x80000B28
    // 0x8008500C: nop

    music_change_on(rdram, ctx);
        goto after_9;
    // 0x8008500C: nop

    after_9:
    // 0x80085010: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80085014: addiu       $s0, $s0, -0x544
    ctx->r16 = ADD32(ctx->r16, -0X544);
    // 0x80085018: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x8008501C: jal         0x80000B34
    // 0x80085020: nop

    music_play(rdram, ctx);
        goto after_10;
    // 0x80085020: nop

    after_10:
    // 0x80085024: b           L_80085100
    // 0x80085028: nop

        goto L_80085100;
    // 0x80085028: nop

L_8008502C:
    // 0x8008502C: jal         0x80000B28
    // 0x80085030: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x80085030: nop

    after_11:
    // 0x80085034: jal         0x80000BE0
    // 0x80085038: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x80085038: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x8008503C: jal         0x80000B34
    // 0x80085040: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_13;
    // 0x80085040: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_13:
    // 0x80085044: jal         0x80000B18
    // 0x80085048: nop

    music_change_off(rdram, ctx);
        goto after_14;
    // 0x80085048: nop

    after_14:
    // 0x8008504C: b           L_80085100
    // 0x80085050: nop

        goto L_80085100;
    // 0x80085050: nop

L_80085054:
    // 0x80085054: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80085058: nop

    // 0x8008505C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80085060: bne         $at, $zero, L_80085100
    if (ctx->r1 != 0) {
        // 0x80085064: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80085100;
    }
    // 0x80085064: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085068: bne         $v0, $at, L_80085100
    if (ctx->r2 != ctx->r1) {
        // 0x8008506C: nop
    
            goto L_80085100;
    }
    // 0x8008506C: nop

    // 0x80085070: bgez        $t0, L_80085098
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80085074: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_80085098;
    }
    // 0x80085074: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80085078: addiu       $s0, $s0, -0x544
    ctx->r16 = ADD32(ctx->r16, -0X544);
    // 0x8008507C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80085080: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80085084: blez        $v1, L_80085098
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80085088: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80085098;
    }
    // 0x80085088: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8008508C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80085090: b           L_800850D0
    // 0x80085094: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_800850D0;
    // 0x80085094: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80085098:
    // 0x80085098: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008509C: blez        $t0, L_800850D0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800850A0: addiu       $s0, $s0, -0x544
        ctx->r16 = ADD32(ctx->r16, -0X544);
            goto L_800850D0;
    }
    // 0x800850A0: addiu       $s0, $s0, -0x544
    ctx->r16 = ADD32(ctx->r16, -0X544);
    // 0x800850A4: jal         0x80002110
    // 0x800850A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    music_sequence_count(rdram, ctx);
        goto after_15;
    // 0x800850A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_15:
    // 0x800850AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800850B0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800850B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800850B8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800850BC: beq         $at, $zero, L_800850D0
    if (ctx->r1 == 0) {
        // 0x800850C0: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_800850D0;
    }
    // 0x800850C0: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800850C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800850C8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800850CC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
L_800850D0:
    // 0x800850D0: beq         $a0, $zero, L_80085100
    if (ctx->r4 == 0) {
        // 0x800850D4: nop
    
            goto L_80085100;
    }
    // 0x800850D4: nop

    // 0x800850D8: jal         0x80000B28
    // 0x800850DC: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x800850DC: nop

    after_16:
    // 0x800850E0: jal         0x80000BE0
    // 0x800850E4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_17;
    // 0x800850E4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_17:
    // 0x800850E8: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x800850EC: jal         0x80000B34
    // 0x800850F0: nop

    music_play(rdram, ctx);
        goto after_18;
    // 0x800850F0: nop

    after_18:
    // 0x800850F4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800850F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800850FC: sw          $t3, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r11;
L_80085100:
    // 0x80085100: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80085104: lh          $t5, 0x6C46($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X6C46);
    // 0x80085108: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008510C: bne         $t5, $at, L_8008513C
    if (ctx->r13 != ctx->r1) {
        // 0x80085110: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008513C;
    }
    // 0x80085110: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085114: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085118: addiu       $a1, $a1, 0x69FC
    ctx->r5 = ADD32(ctx->r5, 0X69FC);
    // 0x8008511C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80085120: nop

    // 0x80085124: bne         $t6, $zero, L_8008515C
    if (ctx->r14 != 0) {
        // 0x80085128: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8008515C;
    }
    // 0x80085128: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8008512C: jal         0x80001D04
    // 0x80085130: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    sound_play(rdram, ctx);
        goto after_19;
    // 0x80085130: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    after_19:
    // 0x80085134: b           L_8008515C
    // 0x80085138: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_8008515C;
    // 0x80085138: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_8008513C:
    // 0x8008513C: addiu       $a1, $a1, 0x69FC
    ctx->r5 = ADD32(ctx->r5, 0X69FC);
    // 0x80085140: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80085144: nop

    // 0x80085148: beq         $a0, $zero, L_8008515C
    if (ctx->r4 == 0) {
        // 0x8008514C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_8008515C;
    }
    // 0x8008514C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085150: jal         0x8000488C
    // 0x80085154: nop

    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x80085154: nop

    after_20:
    // 0x80085158: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_8008515C:
    // 0x8008515C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085160: bne         $t7, $at, L_80085178
    if (ctx->r15 != ctx->r1) {
        // 0x80085164: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80085178;
    }
    // 0x80085164: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80085168: jal         0x80001D04
    // 0x8008516C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x8008516C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80085170: b           L_800851B0
    // 0x80085174: nop

        goto L_800851B0;
    // 0x80085174: nop

L_80085178:
    // 0x80085178: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8008517C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085180: bne         $t8, $at, L_80085198
    if (ctx->r24 != ctx->r1) {
        // 0x80085184: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80085198;
    }
    // 0x80085184: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80085188: jal         0x80001D04
    // 0x8008518C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x8008518C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80085190: b           L_800851B0
    // 0x80085194: nop

        goto L_800851B0;
    // 0x80085194: nop

L_80085198:
    // 0x80085198: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8008519C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800851A0: bne         $t9, $at, L_800851B0
    if (ctx->r25 != ctx->r1) {
        // 0x800851A4: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800851B0;
    }
    // 0x800851A4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800851A8: jal         0x80001D04
    // 0x800851AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x800851AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_800851B0:
    // 0x800851B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800851B4: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x800851B8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800851BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800851C0: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x800851C4: beq         $at, $zero, L_800851E4
    if (ctx->r1 == 0) {
        // 0x800851C8: nop
    
            goto L_800851E4;
    }
    // 0x800851C8: nop

    // 0x800851CC: jal         0x800851FC
    // 0x800851D0: nop

    soundoptions_free(rdram, ctx);
        goto after_24;
    // 0x800851D0: nop

    after_24:
    // 0x800851D4: jal         0x800813D0
    // 0x800851D8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_25;
    // 0x800851D8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_25:
    // 0x800851DC: b           L_800851EC
    // 0x800851E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800851EC;
    // 0x800851E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800851E4:
    // 0x800851E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800851E8: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_800851EC:
    // 0x800851EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800851F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800851F4: jr          $ra
    // 0x800851F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800851F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void obj_init_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800389B0: jr          $ra
    // 0x800389B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800389B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_spawn_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AFC40: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AFC44: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AFC48: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AFC4C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AFC50: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AFC54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AFC58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AFC5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AFC60: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800AFC64: lw          $s5, 0x74($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X74);
    // 0x800AFC68: lb          $a3, 0x57($t6)
    ctx->r7 = MEM_B(ctx->r14, 0X57);
    // 0x800AFC6C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AFC70: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800AFC74: blez        $a3, L_800AFE34
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800AFC78: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800AFE34;
    }
    // 0x800AFC78: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800AFC7C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800AFC80:
    // 0x800AFC80: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFC84: andi        $t7, $s5, 0x1
    ctx->r15 = ctx->r21 & 0X1;
    // 0x800AFC88: beq         $t7, $zero, L_800AFD54
    if (ctx->r15 == 0) {
        // 0x800AFC8C: addu        $v1, $a2, $s4
        ctx->r3 = ADD32(ctx->r6, ctx->r20);
            goto L_800AFD54;
    }
    // 0x800AFC8C: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800AFC90: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800AFC94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFC98: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800AFC9C: bne         $t8, $zero, L_800AFCC4
    if (ctx->r24 != 0) {
        // 0x800AFCA0: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_800AFCC4;
    }
    // 0x800AFCA0: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x800AFCA4: jal         0x800AF52C
    // 0x800AFCA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_enable_emitter(rdram, ctx);
        goto after_0;
    // 0x800AFCA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800AFCAC: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFCB0: nop

    // 0x800AFCB4: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800AFCB8: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800AFCBC: nop

    // 0x800AFCC0: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
L_800AFCC4:
    // 0x800AFCC4: beq         $t9, $zero, L_800AFCE4
    if (ctx->r25 == 0) {
        // 0x800AFCC8: andi        $t1, $v0, 0x400
        ctx->r9 = ctx->r2 & 0X400;
            goto L_800AFCE4;
    }
    // 0x800AFCC8: andi        $t1, $v0, 0x400
    ctx->r9 = ctx->r2 & 0X400;
    // 0x800AFCCC: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x800AFCD0: addu        $a1, $a2, $t0
    ctx->r5 = ADD32(ctx->r6, ctx->r8);
    // 0x800AFCD4: jal         0x800AFE5C
    // 0x800AFCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_1;
    // 0x800AFCD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800AFCDC: b           L_800AFD44
    // 0x800AFCE0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800AFD44;
    // 0x800AFCE0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800AFCE4:
    // 0x800AFCE4: beq         $t1, $zero, L_800AFD00
    if (ctx->r9 == 0) {
        // 0x800AFCE8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AFD00;
    }
    // 0x800AFCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFCEC: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800AFCF0: jal         0x800AFE5C
    // 0x800AFCF4: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800AFCF4: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    after_2:
    // 0x800AFCF8: b           L_800AFD44
    // 0x800AFCFC: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800AFD44;
    // 0x800AFCFC: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800AFD00:
    // 0x800AFD00: lh          $t3, 0xA($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XA);
    // 0x800AFD04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFD08: addu        $t4, $t3, $s6
    ctx->r12 = ADD32(ctx->r11, ctx->r22);
    // 0x800AFD0C: sh          $t4, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r12;
    // 0x800AFD10: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFD14: sll         $t8, $s3, 5
    ctx->r24 = S32(ctx->r19 << 5);
    // 0x800AFD18: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800AFD1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AFD20: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800AFD24: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x800AFD28: nop

    // 0x800AFD2C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AFD30: bne         $at, $zero, L_800AFD40
    if (ctx->r1 != 0) {
        // 0x800AFD34: nop
    
            goto L_800AFD40;
    }
    // 0x800AFD34: nop

    // 0x800AFD38: jal         0x800AFE5C
    // 0x800AFD3C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800AFD3C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    after_3:
L_800AFD40:
    // 0x800AFD40: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800AFD44:
    // 0x800AFD44: nop

    // 0x800AFD48: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800AFD4C: b           L_800AFE20
    // 0x800AFD50: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800AFE20;
    // 0x800AFD50: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800AFD54:
    // 0x800AFD54: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800AFD58: nop

    // 0x800AFD5C: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x800AFD60: beq         $t0, $zero, L_800AFE1C
    if (ctx->r8 == 0) {
        // 0x800AFD64: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_800AFE1C;
    }
    // 0x800AFD64: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x800AFD68: beq         $t1, $zero, L_800AFDC0
    if (ctx->r9 == 0) {
        // 0x800AFD6C: andi        $t4, $v0, 0x400
        ctx->r12 = ctx->r2 & 0X400;
            goto L_800AFDC0;
    }
    // 0x800AFD6C: andi        $t4, $v0, 0x400
    ctx->r12 = ctx->r2 & 0X400;
    // 0x800AFD70: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800AFD74: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x800AFD78: lbu         $s0, 0x6($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X6);
    // 0x800AFD7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AFD80: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x800AFD84: bgez        $s0, L_800AFD90
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800AFD88: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AFD90;
    }
    // 0x800AFD88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFD8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AFD90:
    // 0x800AFD90: jal         0x800AFE5C
    // 0x800AFD94: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800AFD94: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    after_4:
    // 0x800AFD98: bne         $s0, $zero, L_800AFDAC
    if (ctx->r16 != 0) {
        // 0x800AFD9C: sb          $s0, 0x6($s1)
        MEM_B(0X6, ctx->r17) = ctx->r16;
            goto L_800AFDAC;
    }
    // 0x800AFD9C: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    // 0x800AFDA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFDA4: jal         0x800AF6E4
    // 0x800AFDA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800AFDA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
L_800AFDAC:
    // 0x800AFDAC: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x800AFDB0: nop

    // 0x800AFDB4: lb          $a3, 0x57($t3)
    ctx->r7 = MEM_B(ctx->r11, 0X57);
    // 0x800AFDB8: b           L_800AFE20
    // 0x800AFDBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800AFE20;
    // 0x800AFDBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800AFDC0:
    // 0x800AFDC0: beq         $t4, $zero, L_800AFE04
    if (ctx->r12 == 0) {
        // 0x800AFDC4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800AFE04;
    }
    // 0x800AFDC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFDC8: sll         $t6, $s3, 5
    ctx->r14 = S32(ctx->r19 << 5);
    // 0x800AFDCC: ori         $t5, $v0, 0x200
    ctx->r13 = ctx->r2 | 0X200;
    // 0x800AFDD0: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x800AFDD4: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x800AFDD8: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800AFDDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFDE0: bne         $t7, $zero, L_800AFDF0
    if (ctx->r15 != 0) {
        // 0x800AFDE4: nop
    
            goto L_800AFDF0;
    }
    // 0x800AFDE4: nop

    // 0x800AFDE8: jal         0x800AF6E4
    // 0x800AFDEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800AFDEC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800AFDF0:
    // 0x800AFDF0: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800AFDF4: nop

    // 0x800AFDF8: lb          $a3, 0x57($t8)
    ctx->r7 = MEM_B(ctx->r24, 0X57);
    // 0x800AFDFC: b           L_800AFE20
    // 0x800AFE00: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800AFE20;
    // 0x800AFE00: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800AFE04:
    // 0x800AFE04: jal         0x800AF6E4
    // 0x800AFE08: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800AFE08: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800AFE0C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800AFE10: nop

    // 0x800AFE14: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800AFE18: nop

L_800AFE1C:
    // 0x800AFE1C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800AFE20:
    // 0x800AFE20: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800AFE24: srl         $t0, $s5, 1
    ctx->r8 = S32(U32(ctx->r21) >> 1);
    // 0x800AFE28: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800AFE2C: bne         $at, $zero, L_800AFC80
    if (ctx->r1 != 0) {
        // 0x800AFE30: or          $s5, $t0, $zero
        ctx->r21 = ctx->r8 | 0;
            goto L_800AFC80;
    }
    // 0x800AFE30: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
L_800AFE34:
    // 0x800AFE34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AFE38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AFE3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AFE40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AFE44: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AFE48: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AFE4C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AFE50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AFE54: jr          $ra
    // 0x800AFE58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AFE58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_loop_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E638: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E63C: nop

    // 0x8003E640: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8003E644: nop

    // 0x8003E648: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8003E64C: beq         $at, $zero, L_8003E684
    if (ctx->r1 == 0) {
        // 0x8003E650: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003E684;
    }
    // 0x8003E650: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003E654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E658: addu        $at, $at, $t6
    gpr jr_addend_8003E664 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003E65C: lw          $t6, 0x61C0($at)
    ctx->r14 = ADD32(ctx->r1, 0X61C0);
    // 0x8003E660: nop

    // 0x8003E664: jr          $t6
    // 0x8003E668: nop

    switch (jr_addend_8003E664 >> 2) {
        case 0: goto L_8003E66C; break;
        case 1: goto L_8003E66C; break;
        case 2: goto L_8003E67C; break;
        case 3: goto L_8003E67C; break;
        case 4: goto L_8003E684; break;
        case 5: goto L_8003E684; break;
        case 6: goto L_8003E684; break;
        case 7: goto L_8003E684; break;
        case 8: goto L_8003E684; break;
        case 9: goto L_8003E684; break;
        case 10: goto L_8003E67C; break;
        case 11: goto L_8003E67C; break;
        default: switch_error(__func__, 0x8003E664, 0x800E61C0);
    }
    // 0x8003E668: nop

L_8003E66C:
    // 0x8003E66C: jal         0x8003E694
    // 0x8003E670: nop

    weapon_projectile(rdram, ctx);
        goto after_0;
    // 0x8003E670: nop

    after_0:
    // 0x8003E674: b           L_8003E688
    // 0x8003E678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003E688;
    // 0x8003E678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E67C:
    // 0x8003E67C: jal         0x8003F2E8
    // 0x8003E680: nop

    weapon_trap(rdram, ctx);
        goto after_1;
    // 0x8003E680: nop

    after_1:
L_8003E684:
    // 0x8003E684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E688:
    // 0x8003E688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E68C: jr          $ra
    // 0x8003E690: nop

    return;
    // 0x8003E690: nop

;}
RECOMP_FUNC void menu_title_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008353C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083540: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083544: sw          $t6, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = ctx->r14;
    // 0x80083548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008354C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083550: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80083554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008355C: jal         0x8009C154
    // 0x80083560: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    reset_character_id_slots(rdram, ctx);
        goto after_0;
    // 0x80083560: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    after_0:
    // 0x80083564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083568: sw          $zero, -0xB34($at)
    MEM_W(-0XB34, ctx->r1) = 0;
    // 0x8008356C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083570: sw          $zero, -0xBA4($at)
    MEM_W(-0XBA4, ctx->r1) = 0;
    // 0x80083574: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083578: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008357C: jal         0x8006A434
    // 0x80083580: sw          $t7, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r15;
    input_assign_players(rdram, ctx);
        goto after_1;
    // 0x80083580: sw          $t7, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r15;
    after_1:
    // 0x80083584: jal         0x80000B34
    // 0x80083588: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    music_play(rdram, ctx);
        goto after_2;
    // 0x80083588: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8008358C: jal         0x80001AEC
    // 0x80083590: nop

    music_volume(rdram, ctx);
        goto after_3;
    // 0x80083590: nop

    after_3:
    // 0x80083594: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80083598: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008359C: sw          $v0, -0x8A0($at)
    MEM_W(-0X8A0, ctx->r1) = ctx->r2;
    // 0x800835A0: addiu       $v1, $v1, -0xBA8
    ctx->r3 = ADD32(ctx->r3, -0XBA8);
    // 0x800835A4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800835A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800835AC: beq         $t8, $zero, L_800835C4
    if (ctx->r24 == 0) {
        // 0x800835B0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800835C4;
    }
    // 0x800835B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800835B4: sw          $zero, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = 0;
    // 0x800835B8: b           L_800835CC
    // 0x800835BC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800835CC;
    // 0x800835BC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800835C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800835C4:
    // 0x800835C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800835C8: sw          $t9, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = ctx->r25;
L_800835CC:
    // 0x800835CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800835D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800835D4: swc1        $f4, 0x6870($at)
    MEM_W(0X6870, ctx->r1) = ctx->f4.u32l;
    // 0x800835D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800835DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800835E0: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x800835E4: jal         0x8009C674
    // 0x800835E8: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    menu_assetgroup_load(rdram, ctx);
        goto after_4;
    // 0x800835E8: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    after_4:
    // 0x800835EC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800835F0: lh          $t0, -0x83C($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X83C);
    // 0x800835F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800835F8: addiu       $a0, $a0, 0x6550
    ctx->r4 = ADD32(ctx->r4, 0X6550);
    // 0x800835FC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80083600: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083604: lh          $t4, -0x83A($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X83A);
    // 0x80083608: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8008360C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80083610: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083614: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083618: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008361C: lh          $t8, -0x838($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X838);
    // 0x80083620: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083624: sw          $t3, -0x824($at)
    MEM_W(-0X824, ctx->r1) = ctx->r11;
    // 0x80083628: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008362C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083630: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80083634: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80083638: sw          $t7, -0x81C($at)
    MEM_W(-0X81C, ctx->r1) = ctx->r15;
    // 0x8008363C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80083640: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80083644: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083648: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008364C: addiu       $a1, $a1, -0x826
    ctx->r5 = ADD32(ctx->r5, -0X826);
    // 0x80083650: addiu       $v0, $v0, -0x836
    ctx->r2 = ADD32(ctx->r2, -0X836);
    // 0x80083654: addiu       $v1, $v1, -0x80C
    ctx->r3 = ADD32(ctx->r3, -0X80C);
    // 0x80083658: sw          $t1, -0x814($at)
    MEM_W(-0X814, ctx->r1) = ctx->r9;
L_8008365C:
    // 0x8008365C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80083660: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80083664: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80083668: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008366C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80083670: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x80083674: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x80083678: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008367C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80083680: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80083684: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80083688: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8008368C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80083690: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80083694: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083698: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008369C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800836A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800836A4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800836A8: sw          $t9, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r25;
    // 0x800836AC: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x800836B0: bne         $v0, $a1, L_8008365C
    if (ctx->r2 != ctx->r5) {
        // 0x800836B4: sw          $t3, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r11;
            goto L_8008365C;
    }
    // 0x800836B4: sw          $t3, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r11;
    // 0x800836B8: jal         0x80000BE0
    // 0x800836BC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    music_voicelimit_set(rdram, ctx);
        goto after_5;
    // 0x800836BC: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_5:
    // 0x800836C0: jal         0x800660C0
    // 0x800836C4: nop

    cam_shake_off(rdram, ctx);
        goto after_6;
    // 0x800836C4: nop

    after_6:
    // 0x800836C8: jal         0x800C42EC
    // 0x800836CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x800836CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800836D0: jal         0x800C4170
    // 0x800836D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x800836D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x800836D8: jal         0x80000890
    // 0x800836DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_reset(rdram, ctx);
        goto after_9;
    // 0x800836DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800836E0: jal         0x8000E4BC
    // 0x800836E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x800836E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x800836E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800836EC: sw          $zero, 0x6864($at)
    MEM_W(0X6864, ctx->r1) = 0;
    // 0x800836F0: jal         0x8001E29C
    // 0x800836F4: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x800836F4: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_11:
    // 0x800836F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800836FC: addiu       $a0, $a0, 0x6874
    ctx->r4 = ADD32(ctx->r4, 0X6874);
    // 0x80083700: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80083704: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x80083708: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008370C: addiu       $a2, $a2, 0x6868
    ctx->r6 = ADD32(ctx->r6, 0X6868);
    // 0x80083710: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083714: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80083718: bne         $a1, $at, L_8008372C
    if (ctx->r5 != ctx->r1) {
        // 0x8008371C: sh          $zero, 0x0($a2)
        MEM_H(0X0, ctx->r6) = 0;
            goto L_8008372C;
    }
    // 0x8008371C: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80083720: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x80083724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083728: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_8008372C:
    // 0x8008372C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80083730: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80083734: jal         0x8006E2E8
    // 0x80083738: nop

    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x80083738: nop

    after_12:
    // 0x8008373C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80083740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083744: swc1        $f6, 0x68D8($at)
    MEM_W(0X68D8, ctx->r1) = ctx->f6.u32l;
    // 0x80083748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008374C: sw          $zero, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = 0;
    // 0x80083750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083754: sw          $zero, 0x68DC($at)
    MEM_W(0X68DC, ctx->r1) = 0;
    // 0x80083758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008375C: sw          $zero, -0x60C($at)
    MEM_W(-0X60C, ctx->r1) = 0;
    // 0x80083760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083768: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x8008376C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083770: sw          $zero, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = 0;
    // 0x80083774: jr          $ra
    // 0x80083778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80083778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DC64: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DC68: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DC6C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DC70: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DC74: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DC78: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DC7C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DC80: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DC84: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DC88: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DC8C: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DC90: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003DC94: jal         0x8009C2D0
    // 0x8003DC98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DC98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DC9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCA0: bne         $v0, $zero, L_8003DCE0
    if (ctx->r2 != 0) {
        // 0x8003DCA4: nop
    
            goto L_8003DCE0;
    }
    // 0x8003DCA4: nop

    // 0x8003DCA8: jal         0x8000E1DC
    // 0x8003DCAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DCAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DCB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCB4: beq         $v0, $zero, L_8003DCDC
    if (ctx->r2 == 0) {
        // 0x8003DCB8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DCDC;
    }
    // 0x8003DCB8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DCBC: jal         0x8009EC70
    // 0x8003DCC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DCC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DCC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCC8: bne         $v0, $zero, L_8003DCDC
    if (ctx->r2 != 0) {
        // 0x8003DCCC: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DCDC;
    }
    // 0x8003DCCC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DCD0: b           L_8003DCE0
    // 0x8003DCD4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DCE0;
    // 0x8003DCD4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DCD8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8003DCDC:
    // 0x8003DCDC: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
L_8003DCE0:
    // 0x8003DCE0: lw          $t3, 0x78($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X78);
    // 0x8003DCE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DCE8: bne         $t3, $at, L_8003DD08
    if (ctx->r11 != ctx->r1) {
        // 0x8003DCEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DD08;
    }
    // 0x8003DCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DCF0: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8003DCF4: nop

    // 0x8003DCF8: ori         $t5, $t4, 0x600
    ctx->r13 = ctx->r12 | 0X600;
    // 0x8003DCFC: jal         0x8000FFB8
    // 0x8003DD00: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DD00: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    after_3:
    // 0x8003DD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DD08:
    // 0x8003DD08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DD0C: jr          $ra
    // 0x8003DD10: nop

    return;
    // 0x8003DD10: nop

;}
RECOMP_FUNC void despawn_player_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F0: sw          $a0, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = ctx->r4;
    // 0x8000E1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000E1FC: sb          $t6, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = ctx->r14;
    // 0x8000E200: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000E204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E208: sb          $a1, -0x52BB($at)
    MEM_B(-0X52BB, ctx->r1) = ctx->r5;
    // 0x8000E20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000E214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E21C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E220: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000E224: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E228: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000E22C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000E230: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000E234: nop

    // 0x8000E238: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000E23C: sh          $t8, -0x52BA($at)
    MEM_H(-0X52BA, ctx->r1) = ctx->r24;
    // 0x8000E240: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000E244: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E248: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E24C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000E250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E254: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000E258: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000E25C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000E260: nop

    // 0x8000E264: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E268: sh          $t0, -0x52B8($at)
    MEM_H(-0X52B8, ctx->r1) = ctx->r8;
    // 0x8000E26C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000E270: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E274: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E278: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000E27C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000E284: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000E288: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E28C: sh          $t2, -0x52B6($at)
    MEM_H(-0X52B6, ctx->r1) = ctx->r10;
    // 0x8000E290: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8000E294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E298: jal         0x8000FFB8
    // 0x8000E29C: sh          $t3, -0x52B4($at)
    MEM_H(-0X52B4, ctx->r1) = ctx->r11;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8000E29C: sh          $t3, -0x52B4($at)
    MEM_H(-0X52B4, ctx->r1) = ctx->r11;
    after_0:
    // 0x8000E2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E2A8: sw          $zero, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = 0;
    // 0x8000E2AC: jr          $ra
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void __mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A71C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000A728: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A72C: lbu         $t9, 0x70($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X70);
    // 0x8000A730: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A734: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A738: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8000A73C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A740: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A744: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8000A748: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A74C: beq         $at, $zero, L_8000A75C
    if (ctx->r1 == 0) {
        // 0x8000A750: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8000A75C;
    }
    // 0x8000A750: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000A754: jr          $ra
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A75C:
    // 0x8000A75C: beq         $v1, $zero, L_8000A7BC
    if (ctx->r3 == 0) {
        // 0x8000A760: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000A7BC;
    }
    // 0x8000A760: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A764: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000A768: nop

    // 0x8000A76C: sw          $t1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r9;
    // 0x8000A770: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A774: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x8000A778: nop

    // 0x8000A77C: bne         $t2, $zero, L_8000A78C
    if (ctx->r10 != 0) {
        // 0x8000A780: nop
    
            goto L_8000A78C;
    }
    // 0x8000A780: nop

    // 0x8000A784: b           L_8000A798
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_8000A798;
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
L_8000A78C:
    // 0x8000A78C: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x8000A790: nop

    // 0x8000A794: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
L_8000A798:
    // 0x8000A798: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x8000A79C: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x8000A7A0: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x8000A7A4: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x8000A7A8: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
    // 0x8000A7AC: lbu         $t4, 0x71($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A7B0: nop

    // 0x8000A7B4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A7B8: sb          $t5, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r13;
L_8000A7BC:
    // 0x8000A7BC: jr          $ra
    // 0x8000A7C0: nop

    return;
    // 0x8000A7C0: nop

;}
RECOMP_FUNC void handle_racer_head_turning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800521C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800521C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800521CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800521D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800521D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800521D8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800521DC: jal         0x80023568
    // 0x800521E0: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    func_80023568(rdram, ctx);
        goto after_0;
    // 0x800521E0: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    after_0:
    // 0x800521E4: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x800521E8: beq         $v0, $zero, L_8005221C
    if (ctx->r2 == 0) {
        // 0x800521EC: nop
    
            goto L_8005221C;
    }
    // 0x800521EC: nop

    // 0x800521F0: jal         0x8001BAC8
    // 0x800521F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800521F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800521F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800521FC: lui         $a3, 0x481C
    ctx->r7 = S32(0X481C << 16);
    // 0x80052200: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80052204: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052208: jal         0x80052388
    // 0x8005220C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    turn_head_towards_object(rdram, ctx);
        goto after_2;
    // 0x8005220C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80052210: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x80052214: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80052218: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8005221C:
    // 0x8005221C: bne         $v1, $zero, L_8005226C
    if (ctx->r3 != 0) {
        // 0x80052220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005226C;
    }
    // 0x80052220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80052228: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8005222C: jal         0x8001B7A8
    // 0x80052230: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_3;
    // 0x80052230: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_3:
    // 0x80052234: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x80052238: beq         $v0, $zero, L_8005226C
    if (ctx->r2 == 0) {
        // 0x8005223C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8005226C;
    }
    // 0x8005223C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80052240: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052244: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x80052248: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005224C: bne         $t7, $zero, L_8005226C
    if (ctx->r15 != 0) {
        // 0x80052250: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8005226C;
    }
    // 0x80052250: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052254: lui         $a3, 0x481C
    ctx->r7 = S32(0X481C << 16);
    // 0x80052258: jal         0x80052388
    // 0x8005225C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    turn_head_towards_object(rdram, ctx);
        goto after_4;
    // 0x8005225C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    after_4:
    // 0x80052260: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x80052264: sra         $t8, $v1, 24
    ctx->r24 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80052268: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8005226C:
    // 0x8005226C: bne         $v1, $zero, L_800522BC
    if (ctx->r3 != 0) {
        // 0x80052270: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800522BC;
    }
    // 0x80052270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052274: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80052278: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8005227C: jal         0x8001B7A8
    // 0x80052280: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_5;
    // 0x80052280: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_5:
    // 0x80052284: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x80052288: beq         $v0, $zero, L_800522BC
    if (ctx->r2 == 0) {
        // 0x8005228C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800522BC;
    }
    // 0x8005228C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80052290: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80052294: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x80052298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005229C: bne         $t9, $zero, L_800522BC
    if (ctx->r25 != 0) {
        // 0x800522A0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800522BC;
    }
    // 0x800522A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800522A4: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800522A8: jal         0x80052388
    // 0x800522AC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    turn_head_towards_object(rdram, ctx);
        goto after_6;
    // 0x800522AC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    after_6:
    // 0x800522B0: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x800522B4: sra         $t0, $v1, 24
    ctx->r8 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800522B8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800522BC:
    // 0x800522BC: bne         $v1, $zero, L_80052340
    if (ctx->r3 != 0) {
        // 0x800522C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80052340;
    }
    // 0x800522C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800522C4: lb          $t1, 0x1E7($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1E7);
    // 0x800522C8: addiu       $t4, $zero, 0x2800
    ctx->r12 = ADD32(0, 0X2800);
    // 0x800522CC: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x800522D0: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800522D4: beq         $at, $zero, L_8005233C
    if (ctx->r1 == 0) {
        // 0x800522D8: lui         $at, 0x44A0
        ctx->r1 = S32(0X44A0 << 16);
            goto L_8005233C;
    }
    // 0x800522D8: lui         $at, 0x44A0
    ctx->r1 = S32(0X44A0 << 16);
    // 0x800522DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800522E0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800522E4: nop

    // 0x800522E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800522EC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800522F0: nop

    // 0x800522F4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800522F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800522FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80052300: nop

    // 0x80052304: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80052308: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005230C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80052310: bgez        $a1, L_80052320
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80052314: slti        $at, $a1, 0x2801
        ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
            goto L_80052320;
    }
    // 0x80052314: slti        $at, $a1, 0x2801
    ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
    // 0x80052318: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x8005231C: slti        $at, $a1, 0x2801
    ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
L_80052320:
    // 0x80052320: bne         $at, $zero, L_80052330
    if (ctx->r1 != 0) {
        // 0x80052324: subu        $a1, $t4, $a1
        ctx->r5 = SUB32(ctx->r12, ctx->r5);
            goto L_80052330;
    }
    // 0x80052324: subu        $a1, $t4, $a1
    ctx->r5 = SUB32(ctx->r12, ctx->r5);
    // 0x80052328: addiu       $a1, $zero, 0x2800
    ctx->r5 = ADD32(0, 0X2800);
    // 0x8005232C: subu        $a1, $t4, $a1
    ctx->r5 = SUB32(ctx->r12, ctx->r5);
L_80052330:
    // 0x80052330: jal         0x8006F94C
    // 0x80052334: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x80052334: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_7:
    // 0x80052338: sh          $v0, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r2;
L_8005233C:
    // 0x8005233C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80052340:
    // 0x80052340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052344: jr          $ra
    // 0x80052348: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80052348: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE170: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CE174: beq         $a2, $zero, L_800CE194
    if (ctx->r6 == 0) {
        // 0x800CE178: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800CE194;
    }
    // 0x800CE178: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800CE17C:
    // 0x800CE17C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800CE180: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CE184: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CE188: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE18C: bne         $a2, $zero, L_800CE17C
    if (ctx->r6 != 0) {
        // 0x800CE190: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800CE17C;
    }
    // 0x800CE190: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_800CE194:
    // 0x800CE194: jr          $ra
    // 0x800CE198: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800CE198: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8008F618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 16U, dkr_legacy_fields, 0U); }
    // 0x8008F618: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008F61C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008F620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008F624: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008F628: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8008F62C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008F630: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008F634: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008F638: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008F63C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008F640: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008F644: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008F648: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008F64C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008F654: jal         0x80066894
    // 0x8008F658: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    camDisableUserView(rdram, ctx);
        goto after_0;
    // 0x8008F658: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    after_0:
    // 0x8008F65C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008F660: jal         0x80066230
    // 0x8008F664: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    camera_init_tracks_menu(rdram, ctx);
        goto after_1;
    // 0x8008F664: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8008F668: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008F66C: jal         0x80067F2C
    // 0x8008F670: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x8008F670: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8008F674: jal         0x8007B3D0
    // 0x8008F678: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rendermode_reset(rdram, ctx);
        goto after_3;
    // 0x8008F678: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x8008F67C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008F680: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008F684: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008F688: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8008F68C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8008F690: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008F694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F698: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008F69C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8008F6A0: lwc1        $f4, 0x69DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x8008F6A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008F6A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008F6AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008F6B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F6B4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008F6B8: lwc1        $f8, 0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x8008F6BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008F6C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008F6C4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8008F6C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008F6CC: addiu       $t2, $t2, 0x6480
    ctx->r10 = ADD32(ctx->r10, 0X6480);
    // 0x8008F6D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8008F6D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008F6D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008F6DC: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8008F6E0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008F6E4: sra         $t6, $t0, 3
    ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8008F6E8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008F6EC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8008F6F0: div         $zero, $a3, $t6
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r14)));
    // 0x8008F6F4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8008F6F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008F6FC: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008F700: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008F704: addiu       $ra, $ra, 0x6478
    ctx->r31 = ADD32(ctx->r31, 0X6478);
    // 0x8008F708: addiu       $t1, $t1, 0x840
    ctx->r9 = ADD32(ctx->r9, 0X840);
    // 0x8008F70C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008F710: bne         $t0, $zero, L_8008F71C
    if (ctx->r8 != 0) {
        // 0x8008F714: nop
    
            goto L_8008F71C;
    }
    // 0x8008F714: nop

    // 0x8008F718: break       7
    do_break(2148071192);
L_8008F71C:
    // 0x8008F71C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F720: bne         $t0, $at, L_8008F734
    if (ctx->r8 != ctx->r1) {
        // 0x8008F724: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008F734;
    }
    // 0x8008F724: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008F728: bne         $a3, $at, L_8008F734
    if (ctx->r7 != ctx->r1) {
        // 0x8008F72C: nop
    
            goto L_8008F734;
    }
    // 0x8008F72C: nop

    // 0x8008F730: break       6
    do_break(2148071216);
L_8008F734:
    // 0x8008F734: mflo        $s7
    ctx->r23 = lo;
    // 0x8008F738: slti        $at, $s7, 0x2A
    ctx->r1 = SIGNED(ctx->r23) < 0X2A ? 1 : 0;
    // 0x8008F73C: bne         $at, $zero, L_8008F74C
    if (ctx->r1 != 0) {
        // 0x8008F740: nop
    
            goto L_8008F74C;
    }
    // 0x8008F740: nop

    // 0x8008F744: b           L_8008FA24
    // 0x8008F748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008FA24;
    // 0x8008F748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008F74C:
    // 0x8008F74C: multu       $s7, $t0
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F750: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008F754: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8008F758: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8008F75C: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8008F760: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8008F764: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008F768: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8008F76C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8008F770: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008F774: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8008F778: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008F77C: mflo        $t7
    ctx->r15 = lo;
    // 0x8008F780: subu        $a3, $a3, $t7
    ctx->r7 = SUB32(ctx->r7, ctx->r15);
    // 0x8008F784: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008F788: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8008F78C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008F790: addu        $s4, $t8, $a3
    ctx->r20 = ADD32(ctx->r24, ctx->r7);
    // 0x8008F794: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008F798: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8008F79C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008F7A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008F7A4: lw          $a2, 0x6924($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6924);
    // 0x8008F7A8: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F7AC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8008F7B0: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x8008F7B4: addu        $s2, $s2, $t7
    ctx->r18 = ADD32(ctx->r18, ctx->r15);
    // 0x8008F7B8: lw          $s1, 0x968($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X968);
    // 0x8008F7BC: lw          $s2, 0x970($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X970);
    // 0x8008F7C0: slt         $at, $t8, $s7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8008F7C4: beq         $at, $zero, L_8008F7E8
    if (ctx->r1 == 0) {
        // 0x8008F7C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008F7E8;
    }
    // 0x8008F7C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008F7CC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008F7D0: addiu       $s0, $s0, 0x840
    ctx->r16 = ADD32(ctx->r16, 0X840);
L_8008F7D4:
    // 0x8008F7D4: lbu         $t9, 0x5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X5);
    // 0x8008F7D8: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x8008F7DC: slt         $at, $t9, $s7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8008F7E0: bne         $at, $zero, L_8008F7D4
    if (ctx->r1 != 0) {
        // 0x8008F7E4: addiu       $s0, $s0, 0x5
        ctx->r16 = ADD32(ctx->r16, 0X5);
            goto L_8008F7D4;
    }
    // 0x8008F7E4: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
L_8008F7E8:
    // 0x8008F7E8: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x8008F7EC: addu        $s0, $t1, $v1
    ctx->r16 = ADD32(ctx->r9, ctx->r3);
    // 0x8008F7F0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8008F7F4: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008F7F8: bne         $at, $zero, L_8008FA18
    if (ctx->r1 != 0) {
        // 0x8008F7FC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FA18;
    }
    // 0x8008F7FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F800: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x8008F804: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8008F808: slti        $at, $a3, 0x2A
    ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
    // 0x8008F80C: beq         $at, $zero, L_8008FA18
    if (ctx->r1 == 0) {
        // 0x8008F810: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FA18;
    }
    // 0x8008F810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F814: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8008F818: nop

L_8008F81C:
    // 0x8008F81C: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x8008F820: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008F824: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008F828: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8008F82C: lw          $a1, 0x730($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X730);
    // 0x8008F830: sh          $s4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r20;
    // 0x8008F834: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x8008F838: sh          $s4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r20;
    // 0x8008F83C: sb          $t6, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r14;
    // 0x8008F840: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8008F844: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x8008F848: sb          $t7, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r15;
    // 0x8008F84C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8008F850: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x8008F854: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8008F858: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x8008F85C: sh          $t6, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r14;
    // 0x8008F860: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x8008F864: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8008F868: sb          $t7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r15;
    // 0x8008F86C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8008F870: or          $t1, $s2, $zero
    ctx->r9 = ctx->r18 | 0;
    // 0x8008F874: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8008F878: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x8008F87C: sh          $t6, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r14;
    // 0x8008F880: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x8008F884: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x8008F888: sb          $t7, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r15;
    // 0x8008F88C: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x8008F890: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008F894: beq         $a1, $zero, L_8008F8C8
    if (ctx->r5 == 0) {
        // 0x8008F898: addu        $a2, $a2, $t8
        ctx->r6 = ADD32(ctx->r6, ctx->r24);
            goto L_8008F8C8;
    }
    // 0x8008F898: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8008F89C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8008F8A0: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8008F8A4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8008F8A8: lbu         $fp, 0x1($a1)
    ctx->r30 = MEM_BU(ctx->r5, 0X1);
    // 0x8008F8AC: and         $s3, $t6, $t5
    ctx->r19 = ctx->r14 & ctx->r13;
    // 0x8008F8B0: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8008F8B4: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8008F8B8: sll         $t6, $fp, 5
    ctx->r14 = S32(ctx->r30 << 5);
    // 0x8008F8BC: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
    // 0x8008F8C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008F8C4: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
L_8008F8C8:
    // 0x8008F8C8: addiu       $v0, $s3, 0x2800
    ctx->r2 = ADD32(ctx->r19, 0X2800);
    // 0x8008F8CC: sh          $s3, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r19;
    // 0x8008F8D0: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x8008F8D4: sh          $s3, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r19;
    // 0x8008F8D8: sh          $fp, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r30;
    // 0x8008F8DC: sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // 0x8008F8E0: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x8008F8E4: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x8008F8E8: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
    // 0x8008F8EC: sh          $s3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r19;
    // 0x8008F8F0: sh          $fp, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r30;
    // 0x8008F8F4: sh          $v0, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r2;
    // 0x8008F8F8: sh          $fp, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r30;
    // 0x8008F8FC: beq         $a1, $zero, L_8008F90C
    if (ctx->r5 == 0) {
        // 0x8008F900: addiu       $s2, $s2, 0x20
        ctx->r18 = ADD32(ctx->r18, 0X20);
            goto L_8008F90C;
    }
    // 0x8008F900: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x8008F904: b           L_8008F910
    // 0x8008F908: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_8008F910;
    // 0x8008F908: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8008F90C:
    // 0x8008F90C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8008F910:
    // 0x8008F910: addiu       $at, $zero, 0x1FE
    ctx->r1 = ADD32(0, 0X1FE);
    // 0x8008F914: bne         $a2, $at, L_8008F924
    if (ctx->r6 != ctx->r1) {
        // 0x8008F918: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8008F924;
    }
    // 0x8008F918: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008F91C: b           L_8008F92C
    // 0x8008F920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8008F92C;
    // 0x8008F920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8008F924:
    // 0x8008F924: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x8008F928: ori         $a2, $a2, 0x100
    ctx->r6 = ctx->r6 | 0X100;
L_8008F92C:
    // 0x8008F92C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008F930: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008F934: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8008F938: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x8008F93C: jal         0x8007B4E8
    // 0x8008F940: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    material_set(rdram, ctx);
        goto after_4;
    // 0x8008F940: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    after_4:
    // 0x8008F944: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    extern void dkr_track_select_background_cover(uint8_t*, recomp_context*); dkr_track_select_background_cover(rdram, ctx);
    // 0x8008F948: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8008F94C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008F950: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    // 0x8008F954: andi        $t8, $a0, 0x6
    ctx->r24 = ctx->r4 & 0X6;
    // 0x8008F958: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008F95C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008F960: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8008F964: ori         $t9, $t8, 0x18
    ctx->r25 = ctx->r24 | 0X18;
    // 0x8008F968: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8008F96C: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8008F970: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8008F974: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8008F978: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8008F97C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8008F980: ori         $t9, $t8, 0x50
    ctx->r25 = ctx->r24 | 0X50;
    // 0x8008F984: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008F988: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8008F98C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008F990: ori         $t7, $s5, 0x10
    ctx->r15 = ctx->r21 | 0X10;
    // 0x8008F994: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8008F998: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008F99C: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8008F9A0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8008F9A4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8008F9A8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8008F9AC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8008F9B0: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x8008F9B4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008F9B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008F9BC: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x8008F9C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008F9C4: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008F9C8: addiu       $ra, $ra, 0x6478
    ctx->r31 = ADD32(ctx->r31, 0X6478);
    // 0x8008F9CC: beq         $s7, $a3, L_8008F9E4
    if (ctx->r23 == ctx->r7) {
        // 0x8008F9D0: addiu       $t2, $t2, 0x6480
        ctx->r10 = ADD32(ctx->r10, 0X6480);
            goto L_8008F9E4;
    }
    // 0x8008F9D0: addiu       $t2, $t2, 0x6480
    ctx->r10 = ADD32(ctx->r10, 0X6480);
    // 0x8008F9D4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8008F9D8: nop

    // 0x8008F9DC: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8008F9E0: subu        $s4, $s4, $t6
    ctx->r20 = SUB32(ctx->r20, ctx->r14);
L_8008F9E4:
    // 0x8008F9E4: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x8008F9E8: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8008F9EC: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8008F9F0: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008F9F4: bne         $at, $zero, L_8008FA14
    if (ctx->r1 != 0) {
        // 0x8008F9F8: slti        $at, $a3, 0x2A
        ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
            goto L_8008FA14;
    }
    // 0x8008F9F8: slti        $at, $a3, 0x2A
    ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
    // 0x8008F9FC: beq         $at, $zero, L_8008FA14
    if (ctx->r1 == 0) {
        // 0x8008FA00: slti        $at, $t4, 0x40
        ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
            goto L_8008FA14;
    }
    // 0x8008FA00: slti        $at, $t4, 0x40
    ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
    // 0x8008FA04: bne         $at, $zero, L_8008F81C
    if (ctx->r1 != 0) {
        // 0x8008FA08: nop
    
            goto L_8008F81C;
    }
    // 0x8008FA08: nop

    // 0x8008FA0C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8008FA10: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
L_8008FA14:
    // 0x8008FA14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008FA18:
    // 0x8008FA18: jal         0x80066818
    // 0x8008FA1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_5;
    // 0x8008FA1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8008FA20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008FA24:
    // 0x8008FA24: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008FA28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008FA2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FA30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008FA34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008FA38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008FA3C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008FA40: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008FA44: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008FA48: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 17U, dkr_legacy_fields, 0U); }
    // 0x8008FA4C: jr          $ra
    // 0x8008FA50: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008FA50: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void charselect_new_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B358: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008B35C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B360: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B364: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B368: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B36C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B374: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B378: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B37C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B380: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B384: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B388: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008B38C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008B390: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008B394: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008B398: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B39C: addiu       $s7, $s7, 0x63CC
    ctx->r23 = ADD32(ctx->r23, 0X63CC);
    // 0x8008B3A0: addiu       $s5, $s5, 0x67D8
    ctx->r21 = ADD32(ctx->r21, 0X67D8);
    // 0x8008B3A4: addiu       $s4, $s4, -0xB44
    ctx->r20 = ADD32(ctx->r20, -0XB44);
    // 0x8008B3A8: addiu       $s3, $s3, 0x63C0
    ctx->r19 = ADD32(ctx->r19, 0X63C0);
    // 0x8008B3AC: addiu       $s2, $s2, 0x63D4
    ctx->r18 = ADD32(ctx->r18, 0X63D4);
    // 0x8008B3B0: addiu       $s0, $s0, 0x63E8
    ctx->r16 = ADD32(ctx->r16, 0X63E8);
    // 0x8008B3B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008B3B8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8008B3BC: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
L_8008B3C0:
    // 0x8008B3C0: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008B3C4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8008B3C8: bne         $t6, $zero, L_8008B488
    if (ctx->r14 != 0) {
        // 0x8008B3CC: addu        $t8, $s5, $t7
        ctx->r24 = ADD32(ctx->r21, ctx->r15);
            goto L_8008B488;
    }
    // 0x8008B3CC: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8008B3D0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B3D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8008B3D8: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x8008B3DC: beq         $t0, $zero, L_8008B488
    if (ctx->r8 == 0) {
        // 0x8008B3E0: addu        $a3, $s0, $s1
        ctx->r7 = ADD32(ctx->r16, ctx->r17);
            goto L_8008B488;
    }
    // 0x8008B3E0: addu        $a3, $s0, $s1
    ctx->r7 = ADD32(ctx->r16, ctx->r17);
L_8008B3E4:
    // 0x8008B3E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008B3E8: addiu       $t1, $t1, 0x63D4
    ctx->r9 = ADD32(ctx->r9, 0X63D4);
    // 0x8008B3EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008B3F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008B3F4: addu        $v1, $zero, $t1
    ctx->r3 = ADD32(0, ctx->r9);
    // 0x8008B3F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B3FC:
    // 0x8008B3FC: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8008B400: addu        $t3, $s0, $v0
    ctx->r11 = ADD32(ctx->r16, ctx->r2);
    // 0x8008B404: beq         $t2, $zero, L_8008B420
    if (ctx->r10 == 0) {
        // 0x8008B408: nop
    
            goto L_8008B420;
    }
    // 0x8008B408: nop

    // 0x8008B40C: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B410: nop

    // 0x8008B414: bne         $a2, $t4, L_8008B420
    if (ctx->r6 != ctx->r12) {
        // 0x8008B418: nop
    
            goto L_8008B420;
    }
    // 0x8008B418: nop

    // 0x8008B41C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008B420:
    // 0x8008B420: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B424: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008B428: beq         $at, $zero, L_8008B438
    if (ctx->r1 == 0) {
        // 0x8008B42C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008B438;
    }
    // 0x8008B42C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008B430: bne         $a0, $zero, L_8008B3FC
    if (ctx->r4 != 0) {
        // 0x8008B434: nop
    
            goto L_8008B3FC;
    }
    // 0x8008B434: nop

L_8008B438:
    // 0x8008B438: beq         $a0, $zero, L_8008B3E4
    if (ctx->r4 == 0) {
        // 0x8008B43C: nop
    
            goto L_8008B3E4;
    }
    // 0x8008B43C: nop

    // 0x8008B440: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x8008B444: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x8008B448: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8008B44C: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B450: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008B454: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008B458: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x8008B45C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008B460: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8008B464: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008B468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B46C: mflo        $t9
    ctx->r25 = lo;
    // 0x8008B470: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008B474: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8008B478: sh          $zero, 0x2($s3)
    MEM_H(0X2, ctx->r19) = 0;
    // 0x8008B47C: sb          $t2, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r10;
    // 0x8008B480: jal         0x80001D04
    // 0x8008B484: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8008B484: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    after_0:
L_8008B488:
    // 0x8008B488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B48C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008B490: bne         $s1, $at, L_8008B3C0
    if (ctx->r17 != ctx->r1) {
        // 0x8008B494: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8008B3C0;
    }
    // 0x8008B494: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008B498: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B49C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B4A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B4A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B4A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B4AC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B4B0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B4B4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008B4B8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008B4BC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008B4C0: jr          $ra
    // 0x8008B4C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008B4C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void savemenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087EC0: jal         0x800C422C
    // 0x80087EC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80087EC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80087EC8: jal         0x8007FF88
    // 0x80087ECC: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x80087ECC: nop

    after_1:
    // 0x80087ED0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087ED4: jal         0x8009C4A8
    // 0x80087ED8: addiu       $a0, $a0, -0x388
    ctx->r4 = ADD32(ctx->r4, -0X388);
    menu_assetgroup_free(rdram, ctx);
        goto after_2;
    // 0x80087ED8: addiu       $a0, $a0, -0x388
    ctx->r4 = ADD32(ctx->r4, -0X388);
    after_2:
    // 0x80087EDC: jal         0x800C5494
    // 0x80087EE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80087EE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80087EE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80087EE8: lw          $a0, 0x6A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A0C);
    // 0x80087EEC: jal         0x80071140
    // 0x80087EF0: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80087EF0: nop

    after_4:
    // 0x80087EF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80087EF8: lw          $a0, 0x6A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A64);
    // 0x80087EFC: jal         0x80071140
    // 0x80087F00: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80087F00: nop

    after_5:
    // 0x80087F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087F0C: jr          $ra
    // 0x80087F10: nop

    return;
    // 0x80087F10: nop

;}
RECOMP_FUNC void update_menu_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DC5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DC60: jal         0x800C73E0
    // 0x8006DC64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bgload_active(rdram, ctx);
        goto after_0;
    // 0x8006DC64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006DC68: bne         $v0, $zero, L_8006DCEC
    if (ctx->r2 != 0) {
        // 0x8006DC6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006DCEC;
    }
    // 0x8006DC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DC70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DC74: jal         0x80010994
    // 0x8006DC78: nop

    obj_update(rdram, ctx);
        goto after_1;
    // 0x8006DC78: nop

    after_1:
    // 0x8006DC7C: jal         0x8001004C
    // 0x8006DC80: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_2;
    // 0x8006DC80: nop

    after_2:
    // 0x8006DC84: jal         0x8001BF20
    // 0x8006DC88: nop

    ainode_update(rdram, ctx);
        goto after_3;
    // 0x8006DC88: nop

    after_3:
    // 0x8006DC8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006DC90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DC94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DC98: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DC9C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DCA0: addiu       $a3, $a3, 0x1228
    ctx->r7 = ADD32(ctx->r7, 0X1228);
    // 0x8006DCA4: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006DCA8: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006DCAC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006DCB0: jal         0x80024D54
    // 0x8006DCB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_scene(rdram, ctx);
        goto after_4;
    // 0x8006DCB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006DCB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DCBC: jal         0x800C3440
    // 0x8006DCC0: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_5;
    // 0x8006DCC0: nop

    after_5:
    // 0x8006DCC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DCC8: jal         0x80078054
    // 0x8006DCCC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    rdp_init(rdram, ctx);
        goto after_6;
    // 0x8006DCCC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_6:
    // 0x8006DCD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DCD4: jal         0x80077050
    // 0x8006DCD8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    divider_draw(rdram, ctx);
        goto after_7;
    // 0x8006DCD8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_7:
    // 0x8006DCDC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DCE0: jal         0x80077268
    // 0x8006DCE4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    divider_clear_coverage(rdram, ctx);
        goto after_8;
    // 0x8006DCE4: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_8:
    // 0x8006DCE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006DCEC:
    // 0x8006DCEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DCF0: jr          $ra
    // 0x8006DCF4: nop

    return;
    // 0x8006DCF4: nop

;}
RECOMP_FUNC void checkpoint_is_passed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800185E4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800185E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800185EC: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x800185F0: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x800185F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800185F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800185FC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018600: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80018604: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80018608: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8001860C: bne         $v0, $zero, L_8001861C
    if (ctx->r2 != 0) {
        // 0x80018610: sw          $a2, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r6;
            goto L_8001861C;
    }
    // 0x80018610: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80018614: b           L_80018C58
    // 0x80018618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80018C58;
    // 0x80018618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001861C:
    // 0x8001861C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80018620: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80018624: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018628: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001862C: lw          $a2, -0x5134($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5134);
    // 0x80018630: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80018634: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80018638: mflo        $t1
    ctx->r9 = lo;
    // 0x8001863C: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x80018640: beq         $t7, $zero, L_80018650
    if (ctx->r15 == 0) {
        // 0x80018644: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80018650;
    }
    // 0x80018644: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80018648: b           L_80018660
    // 0x8001864C: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
        goto L_80018660;
    // 0x8001864C: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
L_80018650:
    // 0x80018650: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018654: mflo        $t8
    ctx->r24 = lo;
    // 0x80018658: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    // 0x8001865C: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
L_80018660:
    // 0x80018660: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80018664: nop

    // 0x80018668: beq         $v1, $zero, L_800186B0
    if (ctx->r3 == 0) {
        // 0x8001866C: nop
    
            goto L_800186B0;
    }
    // 0x8001866C: nop

    // 0x80018670: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x80018674: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80018678: beq         $t2, $v0, L_80018690
    if (ctx->r10 == ctx->r2) {
        // 0x8001867C: nop
    
            goto L_80018690;
    }
    // 0x8001867C: nop

    // 0x80018680: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018684: mflo        $t4
    ctx->r12 = lo;
    // 0x80018688: addu        $a1, $t4, $a2
    ctx->r5 = ADD32(ctx->r12, ctx->r6);
    // 0x8001868C: nop

L_80018690:
    // 0x80018690: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x80018694: nop

    // 0x80018698: beq         $t2, $v0, L_800186B0
    if (ctx->r10 == ctx->r2) {
        // 0x8001869C: nop
    
            goto L_800186B0;
    }
    // 0x8001869C: nop

    // 0x800186A0: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186A4: mflo        $t5
    ctx->r13 = lo;
    // 0x800186A8: addu        $a0, $t5, $a2
    ctx->r4 = ADD32(ctx->r13, ctx->r6);
    // 0x800186AC: nop

L_800186B0:
    // 0x800186B0: bne         $v1, $zero, L_80018778
    if (ctx->r3 != 0) {
        // 0x800186B4: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_80018778;
    }
    // 0x800186B4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800186B8: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x800186BC: nop

    // 0x800186C0: bne         $t2, $t6, L_80018778
    if (ctx->r10 != ctx->r14) {
        // 0x800186C4: nop
    
            goto L_80018778;
    }
    // 0x800186C4: nop

    // 0x800186C8: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x800186CC: nop

    // 0x800186D0: beq         $t2, $v0, L_80018778
    if (ctx->r10 == ctx->r2) {
        // 0x800186D4: nop
    
            goto L_80018778;
    }
    // 0x800186D4: nop

    // 0x800186D8: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186DC: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800186E0: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800186E4: mflo        $t7
    ctx->r15 = lo;
    // 0x800186E8: addu        $v1, $t7, $a2
    ctx->r3 = ADD32(ctx->r15, ctx->r6);
    // 0x800186EC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800186F0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800186F4: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800186F8: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800186FC: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80018700: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80018704: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018708: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001870C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80018710: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80018714: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80018718: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8001871C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80018720: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80018724: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018728: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001872C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80018730: jal         0x800C9AD0
    // 0x80018734: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018734: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_0:
    // 0x80018738: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001873C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80018740: lh          $t8, 0x2C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2C);
    // 0x80018744: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80018748: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8001874C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80018750: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018754: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80018758: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001875C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80018760: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80018764: bc1f        L_80018778
    if (!c1cs) {
        // 0x80018768: nop
    
            goto L_80018778;
    }
    // 0x80018768: nop

    // 0x8001876C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80018770: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80018774: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_80018778:
    // 0x80018778: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001877C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80018780: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80018784: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80018788: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001878C: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80018790: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80018794: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80018798: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001879C: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187A0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800187A4: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800187A8: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800187AC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800187B0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800187B4: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800187B8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800187BC: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800187C0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800187C4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800187C8: jal         0x800C9AD0
    // 0x800187CC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800187CC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_1:
    // 0x800187D0: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800187D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800187D8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800187DC: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x800187E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800187E4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800187E8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800187EC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800187F0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800187F4: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800187F8: bc1f        L_8001882C
    if (!c1cs) {
        // 0x800187FC: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_8001882C;
    }
    // 0x800187FC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80018800: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018808: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001880C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018810: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018814: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018818: nop

    // 0x8001881C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80018820: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80018824: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80018828: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_8001882C:
    // 0x8001882C: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018830: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018834: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018838: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001883C: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018840: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018844: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018848: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001884C: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80018850: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018854: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018858: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001885C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018860: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018864: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018868: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8001886C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80018870: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80018874: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80018878: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001887C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018880: nop

    // 0x80018884: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80018888: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001888C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018890: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80018894: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x80018898: nop

    // 0x8001889C: div.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800188A0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800188A4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800188A8: nop

    // 0x800188AC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800188B0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800188B4: nop

    // 0x800188B8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800188BC: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800188C0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800188C4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800188C8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800188CC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800188D0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800188D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800188D8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800188DC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800188E0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800188E4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800188E8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800188EC: nop

    // 0x800188F0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800188F4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800188F8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800188FC: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018900: nop

    // 0x80018904: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018908: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001890C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018910: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018914: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80018918: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001891C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018920: nop

    // 0x80018924: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80018928: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8001892C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018930: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018934: nop

    // 0x80018938: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001893C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80018940: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80018944: nop

    // 0x80018948: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001894C: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018950: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80018954: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x80018958: nop

    // 0x8001895C: bc1t        L_8001896C
    if (c1cs) {
        // 0x80018960: nop
    
            goto L_8001896C;
    }
    // 0x80018960: nop

    // 0x80018964: b           L_80018974
    // 0x80018968: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_80018974;
    // 0x80018968: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_8001896C:
    // 0x8001896C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018970: nop

L_80018974:
    // 0x80018974: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80018978: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x8001897C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018980: bne         $v1, $t9, L_800189E8
    if (ctx->r3 != ctx->r25) {
        // 0x80018984: nop
    
            goto L_800189E8;
    }
    // 0x80018984: nop

    // 0x80018988: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x8001898C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80018990: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80018994: nop

    // 0x80018998: bne         $t2, $t4, L_800189E8
    if (ctx->r10 != ctx->r12) {
        // 0x8001899C: nop
    
            goto L_800189E8;
    }
    // 0x8001899C: nop

    // 0x800189A0: lwc1        $f7, 0x5620($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5620);
    // 0x800189A4: lwc1        $f6, 0x5624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5624);
    // 0x800189A8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800189AC: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x800189B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189B4: bc1f        L_800189C4
    if (!c1cs) {
        // 0x800189B8: nop
    
            goto L_800189C4;
    }
    // 0x800189B8: nop

    // 0x800189BC: b           L_80018C58
    // 0x800189C0: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C58;
    // 0x800189C0: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_800189C4:
    // 0x800189C4: lwc1        $f5, 0x5628($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5628);
    // 0x800189C8: lwc1        $f4, 0x562C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X562C);
    // 0x800189CC: nop

    // 0x800189D0: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800189D4: nop

    // 0x800189D8: bc1f        L_800189E8
    if (!c1cs) {
        // 0x800189DC: nop
    
            goto L_800189E8;
    }
    // 0x800189DC: nop

    // 0x800189E0: b           L_80018C58
    // 0x800189E4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C58;
    // 0x800189E4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_800189E8:
    // 0x800189E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800189EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800189F0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x800189F4: nop

    // 0x800189F8: bc1f        L_80018C18
    if (!c1cs) {
        // 0x800189FC: nop
    
            goto L_80018C18;
    }
    // 0x800189FC: nop

    // 0x80018A00: beq         $t3, $zero, L_80018A14
    if (ctx->r11 == 0) {
        // 0x80018A04: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80018A14;
    }
    // 0x80018A04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80018A08: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80018A0C: b           L_80018A28
    // 0x80018A10: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_80018A28;
    // 0x80018A10: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_80018A14:
    // 0x80018A14: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80018A18: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80018A1C: bne         $t2, $t7, L_80018A28
    if (ctx->r10 != ctx->r15) {
        // 0x80018A20: nop
    
            goto L_80018A28;
    }
    // 0x80018A20: nop

    // 0x80018A24: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_80018A28:
    // 0x80018A28: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018A2C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80018A30: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018A34: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018A38: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80018A3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80018A40: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018A44: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80018A48: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018A4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018A50: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018A54: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80018A58: nop

    // 0x80018A5C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80018A60: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018A64: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018A68: add.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018A6C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80018A70: nop

    // 0x80018A74: bc1f        L_80018C0C
    if (!c1cs) {
        // 0x80018A78: nop
    
            goto L_80018C0C;
    }
    // 0x80018A78: nop

    // 0x80018A7C: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80018A80: nop

    // 0x80018A84: bne         $v1, $t9, L_80018AA4
    if (ctx->r3 != ctx->r25) {
        // 0x80018A88: nop
    
            goto L_80018AA4;
    }
    // 0x80018A88: nop

    // 0x80018A8C: lbu         $v1, 0x3B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3B);
    // 0x80018A90: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x80018A94: beq         $v1, $zero, L_80018AA4
    if (ctx->r3 == 0) {
        // 0x80018A98: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_80018AA4;
    }
    // 0x80018A98: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80018A9C: sb          $v1, 0x1F8($v0)
    MEM_B(0X1F8, ctx->r2) = ctx->r3;
    // 0x80018AA0: sb          $t4, 0x1F9($v0)
    MEM_B(0X1F9, ctx->r2) = ctx->r12;
L_80018AA4:
    // 0x80018AA4: lw          $t5, -0x5130($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5130);
    // 0x80018AA8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80018AAC: bne         $t0, $t5, L_80018AB8
    if (ctx->r8 != ctx->r13) {
        // 0x80018AB0: addiu       $t1, $t1, 0x3C
        ctx->r9 = ADD32(ctx->r9, 0X3C);
            goto L_80018AB8;
    }
    // 0x80018AB0: addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // 0x80018AB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80018AB8:
    // 0x80018AB8: lw          $t6, -0x5134($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5134);
    // 0x80018ABC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018AC0: addu        $a1, $t1, $t6
    ctx->r5 = ADD32(ctx->r9, ctx->r14);
    // 0x80018AC4: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018AC8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018ACC: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80018AD0: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018AD4: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018AD8: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018ADC: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80018AE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018AE4: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018AE8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018AEC: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018AF0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018AF4: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018AF8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018AFC: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80018B00: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80018B04: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B08: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80018B0C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B10: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018B14: nop

    // 0x80018B18: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80018B1C: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018B20: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018B24: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B28: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x80018B2C: nop

    // 0x80018B30: div.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80018B34: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B38: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018B3C: nop

    // 0x80018B40: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B44: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018B48: nop

    // 0x80018B4C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80018B50: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018B54: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80018B58: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80018B5C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80018B60: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80018B64: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018B68: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80018B6C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80018B70: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80018B74: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018B78: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80018B7C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018B80: nop

    // 0x80018B84: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80018B88: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018B8C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018B90: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018B94: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80018B98: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018B9C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018BA0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018BA4: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80018BA8: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80018BAC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018BB0: nop

    // 0x80018BB4: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80018BB8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80018BBC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018BC0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80018BC4: nop

    // 0x80018BC8: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018BCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018BD0: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018BD4: nop

    // 0x80018BD8: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80018BDC: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018BE0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80018BE4: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80018BE8: nop

    // 0x80018BEC: bc1t        L_80018BFC
    if (c1cs) {
        // 0x80018BF0: nop
    
            goto L_80018BFC;
    }
    // 0x80018BF0: nop

    // 0x80018BF4: b           L_80018C04
    // 0x80018BF8: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_80018C04;
    // 0x80018BF8: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_80018BFC:
    // 0x80018BFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018C00: nop

L_80018C04:
    // 0x80018C04: b           L_80018C58
    // 0x80018C08: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
        goto L_80018C58;
    // 0x80018C08: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_80018C0C:
    // 0x80018C0C: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80018C10: b           L_80018C58
    // 0x80018C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018C58;
    // 0x80018C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018C18:
    // 0x80018C18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018C1C: nop

    // 0x80018C20: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80018C24: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80018C28: nop

    // 0x80018C2C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80018C30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018C34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018C38: nop

    // 0x80018C3C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80018C40: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80018C44: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80018C48: bne         $v0, $zero, L_80018C54
    if (ctx->r2 != 0) {
        // 0x80018C4C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80018C54;
    }
    // 0x80018C4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80018C50: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80018C54:
    // 0x80018C54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80018C58:
    // 0x80018C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018C5C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80018C60: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80018C64: jr          $ra
    // 0x80018C68: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80018C68: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void reformat_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075DCC: jal         0x800758DC
    // 0x80075DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075DD4: beq         $v0, $zero, L_80075DEC
    if (ctx->r2 == 0) {
        // 0x80075DD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075DEC;
    }
    // 0x80075DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075DDC: beq         $v0, $at, L_80075DEC
    if (ctx->r2 == ctx->r1) {
        // 0x80075DE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80075DEC;
    }
    // 0x80075DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075DE4: bne         $v0, $at, L_80075E44
    if (ctx->r2 != ctx->r1) {
        // 0x80075DE8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80075E44;
    }
    // 0x80075DE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075DEC:
    // 0x80075DEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80075DF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80075DF4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80075DF8: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80075DFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80075E00: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80075E04: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80075E08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80075E0C: lw          $a1, 0x4010($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4010);
    // 0x80075E10: addiu       $t7, $t7, 0x4018
    ctx->r15 = ADD32(ctx->r15, 0X4018);
    // 0x80075E14: jal         0x800CFF90
    // 0x80075E18: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    osPfsReFormat(rdram, ctx);
        goto after_1;
    // 0x80075E18: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80075E1C: bne         $v0, $zero, L_80075E2C
    if (ctx->r2 != 0) {
        // 0x80075E20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075E2C;
    }
    // 0x80075E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075E24: b           L_80075E44
    // 0x80075E28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80075E44;
    // 0x80075E28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80075E2C:
    // 0x80075E2C: bne         $v0, $at, L_80075E3C
    if (ctx->r2 != ctx->r1) {
        // 0x80075E30: nop
    
            goto L_80075E3C;
    }
    // 0x80075E30: nop

    // 0x80075E34: b           L_80075E44
    // 0x80075E38: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_80075E44;
    // 0x80075E38: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80075E3C:
    // 0x80075E3C: b           L_80075E44
    // 0x80075E40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80075E44;
    // 0x80075E40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80075E44:
    // 0x80075E44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80075E48: jal         0x80075AEC
    // 0x80075E4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x80075E4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80075E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075E54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80075E58: jr          $ra
    // 0x80075E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80075E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800214E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800214E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800214E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800214EC: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x800214F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800214F4: lb          $t6, 0x3A($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X3A);
    // 0x800214F8: nop

    // 0x800214FC: beq         $t6, $zero, L_80021514
    if (ctx->r14 == 0) {
        // 0x80021500: nop
    
            goto L_80021514;
    }
    // 0x80021500: nop

    // 0x80021504: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80021508: nop

    // 0x8002150C: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80021510: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80021514:
    // 0x80021514: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021518: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002151C: bne         $v1, $v0, L_80021530
    if (ctx->r3 != ctx->r2) {
        // 0x80021520: nop
    
            goto L_80021530;
    }
    // 0x80021520: nop

    // 0x80021524: lb          $v0, 0x3A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X3A);
    // 0x80021528: b           L_800215F4
    // 0x8002152C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800215F4;
    // 0x8002152C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021530:
    // 0x80021530: bltz        $v0, L_80021544
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021534: subu        $t9, $v0, $a1
        ctx->r25 = SUB32(ctx->r2, ctx->r5);
            goto L_80021544;
    }
    // 0x80021534: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x80021538: sh          $t9, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r25;
    // 0x8002153C: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021540: nop

L_80021544:
    // 0x80021544: bne         $v1, $v0, L_80021558
    if (ctx->r3 != ctx->r2) {
        // 0x80021548: addiu       $t0, $zero, -0x2
        ctx->r8 = ADD32(0, -0X2);
            goto L_80021558;
    }
    // 0x80021548: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x8002154C: sh          $t0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r8;
    // 0x80021550: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021554: nop

L_80021558:
    // 0x80021558: bgtz        $v0, L_800215EC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002155C: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800215EC;
    }
    // 0x8002155C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80021560: lh          $t1, 0x6($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X6);
    // 0x80021564: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80021568: ori         $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 | 0X4000;
    // 0x8002156C: sh          $t2, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r10;
    // 0x80021570: lh          $a1, -0x5188($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X5188);
    // 0x80021574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021578: blez        $a1, L_800215CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002157C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800215CC;
    }
    // 0x8002157C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80021580: lw          $a0, -0x518C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X518C);
    // 0x80021584: lh          $v1, 0x28($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X28);
    // 0x80021588: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8002158C: nop

    // 0x80021590: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x80021594: nop

    // 0x80021598: beq         $v1, $t4, L_800215CC
    if (ctx->r3 == ctx->r12) {
        // 0x8002159C: nop
    
            goto L_800215CC;
    }
    // 0x8002159C: nop

L_800215A0:
    // 0x800215A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800215A4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800215A8: beq         $at, $zero, L_800215CC
    if (ctx->r1 == 0) {
        // 0x800215AC: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_800215CC;
    }
    // 0x800215AC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800215B0: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800215B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800215B8: nop

    // 0x800215BC: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800215C0: nop

    // 0x800215C4: bne         $v1, $t8, L_800215A0
    if (ctx->r3 != ctx->r24) {
        // 0x800215C8: nop
    
            goto L_800215A0;
    }
    // 0x800215C8: nop

L_800215CC:
    // 0x800215CC: lw          $t9, -0x518C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X518C);
    // 0x800215D0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800215D4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800215D8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800215DC: jal         0x8001EFA4
    // 0x800215E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_0;
    // 0x800215E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800215E4: b           L_800215F0
    // 0x800215E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800215F0;
    // 0x800215E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800215EC:
    // 0x800215EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800215F0:
    // 0x800215F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800215F4:
    // 0x800215F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800215F8: jr          $ra
    // 0x800215FC: nop

    return;
    // 0x800215FC: nop

;}
RECOMP_FUNC void menu_caution_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C3B4: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8008C3B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C3BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C3C0: sw          $t6, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r14;
    // 0x8008C3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C3C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C3CC: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008C3D0: jal         0x800C4170
    // 0x8008C3D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008C3D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C3D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C3DC: jal         0x800C01D8
    // 0x8008C3E0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008C3E0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_1:
    // 0x8008C3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C3E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C3EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C3F0: sw          $t7, -0xB68($at)
    MEM_W(-0XB68, ctx->r1) = ctx->r15;
    // 0x8008C3F4: jr          $ra
    // 0x8008C3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C3F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void light_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032C6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80032C70: lw          $v0, -0x36A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36A4);
    // 0x80032C74: jr          $ra
    // 0x80032C78: nop

    return;
    // 0x80032C78: nop

;}
RECOMP_FUNC void alRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB714: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CB718: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CB71C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CB720: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CB724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CB728: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800CB72C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CB730: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CB734: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CB738: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CB73C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800CB740: bne         $a2, $zero, L_800CB750
    if (ctx->r6 != 0) {
        // 0x800CB744: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800CB750;
    }
    // 0x800CB744: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800CB748: b           L_800CBAA4
    // 0x800CB74C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800CBAA4;
    // 0x800CB74C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800CB750:
    // 0x800CB750: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800CB754: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800CB758: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800CB75C: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800CB760: beql        $at, $zero, L_800CB974
    if (ctx->r1 == 0) {
        // 0x800CB764: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CB974;
    }
    goto skip_0;
    // 0x800CB764: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800CB768: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800CB76C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800CB770: beql        $t7, $zero, L_800CB974
    if (ctx->r15 == 0) {
        // 0x800CB774: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CB974;
    }
    goto skip_1;
    // 0x800CB774: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800CB778: blez        $s2, L_800CB7F4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800CB77C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800CB7F4;
    }
    // 0x800CB77C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CB780: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CB784: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CB788: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CB78C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CB790: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CB794: jalr        $t9
    // 0x800CB798: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CB798: nop

    after_0:
    // 0x800CB79C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CB7A0: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CB7A4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CB7A8: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800CB7AC: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800CB7B0: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800CB7B4: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800CB7B8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CB7BC: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800CB7C0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800CB7C4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CB7C8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CB7CC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800CB7D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CB7D4: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800CB7D8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CB7DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CB7E0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800CB7E4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800CB7E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CB7EC: b           L_800CB7F8
    // 0x800CB7F0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CB7F8;
    // 0x800CB7F0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CB7F4:
    // 0x800CB7F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CB7F8:
    // 0x800CB7F8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800CB7FC: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CB800: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800CB804: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800CB808: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800CB80C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800CB810: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CB814: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800CB818: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800CB81C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CB820: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800CB824: beq         $at, $zero, L_800CB94C
    if (ctx->r1 == 0) {
        // 0x800CB828: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800CB94C;
    }
    // 0x800CB828: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800CB82C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800CB830:
    // 0x800CB830: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CB834: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800CB838: beq         $v0, $at, L_800CB84C
    if (ctx->r2 == ctx->r1) {
        // 0x800CB83C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800CB84C;
    }
    // 0x800CB83C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800CB840: beq         $v0, $zero, L_800CB84C
    if (ctx->r2 == 0) {
        // 0x800CB844: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800CB84C;
    }
    // 0x800CB844: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800CB848: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800CB84C:
    // 0x800CB84C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800CB850: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800CB854: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800CB858: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800CB85C: beq         $at, $zero, L_800CB86C
    if (ctx->r1 == 0) {
        // 0x800CB860: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800CB86C;
    }
    // 0x800CB860: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CB864: b           L_800CB86C
    // 0x800CB868: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800CB86C;
    // 0x800CB868: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800CB86C:
    // 0x800CB86C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CB870: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CB874: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800CB878: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800CB87C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CB880: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CB884: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CB888: jalr        $t9
    // 0x800CB88C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB88C: nop

    after_1:
    // 0x800CB890: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB894: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800CB898: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB89C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800CB8A0: beq         $v1, $zero, L_800CB8B4
    if (ctx->r3 == 0) {
        // 0x800CB8A4: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800CB8B4;
    }
    // 0x800CB8A4: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800CB8A8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800CB8AC: b           L_800CB8B8
    // 0x800CB8B0: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800CB8B8;
    // 0x800CB8B0: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800CB8B4:
    // 0x800CB8B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CB8B8:
    // 0x800CB8B8: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800CB8BC: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800CB8C0: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800CB8C4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CB8C8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800CB8CC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CB8D0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CB8D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CB8D8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800CB8DC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800CB8E0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CB8E4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800CB8E8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800CB8EC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800CB8F0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800CB8F4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CB8F8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CB8FC: bne         $a1, $zero, L_800CB908
    if (ctx->r5 != 0) {
        // 0x800CB900: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800CB908;
    }
    // 0x800CB900: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CB904: beq         $a2, $zero, L_800CB940
    if (ctx->r6 == 0) {
        // 0x800CB908: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800CB940;
    }
L_800CB908:
    // 0x800CB908: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800CB90C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CB910: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CB914: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800CB918: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800CB91C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CB920: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CB924: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800CB928: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800CB92C: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800CB930: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800CB934: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800CB938: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800CB93C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CB940:
    // 0x800CB940: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CB944: bnel        $at, $zero, L_800CB830
    if (ctx->r1 != 0) {
        // 0x800CB948: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800CB830;
    }
    goto skip_2;
    // 0x800CB948: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800CB94C:
    // 0x800CB94C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800CB950: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CB954: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800CB958: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800CB95C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CB960: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800CB964: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800CB968: b           L_800CBAA4
    // 0x800CB96C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CBAA4;
    // 0x800CB96C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CB970: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800CB974:
    // 0x800CB974: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CB978: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800CB97C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CB980: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800CB984: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800CB988: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800CB98C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800CB990: bgezl       $s2, L_800CB9A0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800CB994: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800CB9A0;
    }
    goto skip_3;
    // 0x800CB994: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800CB998: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CB99C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800CB9A0:
    // 0x800CB9A0: beql        $at, $zero, L_800CB9B0
    if (ctx->r1 == 0) {
        // 0x800CB9A4: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800CB9B0;
    }
    goto skip_4;
    // 0x800CB9A4: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800CB9A8: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800CB9AC: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800CB9B0:
    // 0x800CB9B0: beql        $at, $zero, L_800CBA64
    if (ctx->r1 == 0) {
        // 0x800CB9B4: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800CBA64;
    }
    goto skip_5;
    // 0x800CB9B4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800CB9B8: blez        $s3, L_800CBA38
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800CB9BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CBA38;
    }
    // 0x800CB9BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CB9C0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CB9C4: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800CB9C8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800CB9CC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CB9D0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CB9D4: jalr        $t9
    // 0x800CB9D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CB9D8: nop

    after_2:
    // 0x800CB9DC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CB9E0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CB9E4: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CB9E8: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800CB9EC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CB9F0: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800CB9F4: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800CB9F8: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800CB9FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBA00: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CBA04: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CBA08: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800CBA0C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CBA10: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800CBA14: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBA18: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBA1C: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800CBA20: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CBA24: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800CBA28: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CBA2C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CBA30: b           L_800CBA38
    // 0x800CBA34: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CBA38;
    // 0x800CBA34: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBA38:
    // 0x800CBA38: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800CBA3C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800CBA40: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800CBA44: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800CBA48: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CBA4C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800CBA50: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800CBA54: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800CBA58: b           L_800CBA64
    // 0x800CBA5C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800CBA64;
    // 0x800CBA5C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800CBA60: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800CBA64:
    // 0x800CBA64: beq         $s2, $zero, L_800CBAA0
    if (ctx->r18 == 0) {
        // 0x800CBA68: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800CBAA0;
    }
    // 0x800CBA68: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800CBA6C: bgez        $v1, L_800CBA78
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CBA70: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800CBA78;
    }
    // 0x800CBA70: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBA74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CBA78:
    // 0x800CBA78: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800CBA7C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBA80: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBA84: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800CBA88: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CBA8C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CBA90: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CBA94: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800CBA98: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800CBA9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBAA0:
    // 0x800CBAA0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800CBAA4:
    // 0x800CBAA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CBAA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CBAAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CBAB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CBAB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CBAB8: jr          $ra
    // 0x800CBABC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800CBABC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void obj_loop_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039204: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80039208: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8003920C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80039210: blez        $v0, L_8003922C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039214: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_8003922C;
    }
    // 0x80039214: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80039218: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8003921C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80039220: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80039224: b           L_80039230
    // 0x80039228: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80039230;
    // 0x80039228: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8003922C:
    // 0x8003922C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_80039230:
    // 0x80039230: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80039234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039238: jal         0x8001F460
    // 0x8003923C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x8003923C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80039240: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80039244: addiu       $t9, $zero, 0xAD
    ctx->r25 = ADD32(0, 0XAD);
    // 0x80039248: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003924C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039254: jal         0x800113CC
    // 0x80039258: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_1;
    // 0x80039258: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_1:
    // 0x8003925C: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x80039260: nop

    // 0x80039264: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80039268: nop

    // 0x8003926C: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x80039270: beq         $at, $zero, L_800392AC
    if (ctx->r1 == 0) {
        // 0x80039274: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800392AC;
    }
    // 0x80039274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80039278: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x8003927C: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x80039280: bne         $t2, $zero, L_800392A8
    if (ctx->r10 != 0) {
        // 0x80039284: addiu       $a0, $zero, 0x23B
        ctx->r4 = ADD32(0, 0X23B);
            goto L_800392A8;
    }
    // 0x80039284: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    // 0x80039288: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003928C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80039290: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80039294: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x80039298: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003929C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800392A0: jal         0x80009558
    // 0x800392A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x800392A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
L_800392A8:
    // 0x800392A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800392AC:
    // 0x800392AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800392B0: jr          $ra
    // 0x800392B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800392B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void savemenu_input_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087734: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80087738: lw          $a2, 0x63BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X63BC);
    // 0x8008773C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087740: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80087744: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80087748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008774C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087750: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80087754: bne         $at, $zero, L_80087764
    if (ctx->r1 != 0) {
        // 0x80087758: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80087764;
    }
    // 0x80087758: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8008775C: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80087760: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_80087764:
    // 0x80087764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087768: addiu       $t1, $t1, 0x63E0
    ctx->r9 = ADD32(ctx->r9, 0X63E0);
    // 0x8008776C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087770: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80087774: addiu       $a1, $a1, 0x6A74
    ctx->r5 = ADD32(ctx->r5, 0X6A74);
    // 0x80087778: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008777C: andi        $t8, $t0, 0x7
    ctx->r24 = ctx->r8 & 0X7;
    // 0x80087780: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80087784: blez        $a0, L_800877D8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80087788: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800877D8;
    }
    // 0x80087788: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008778C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087790: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087794: addiu       $a3, $a3, 0x6A78
    ctx->r7 = ADD32(ctx->r7, 0X6A78);
    // 0x80087798: addiu       $v0, $v0, 0x6A80
    ctx->r2 = ADD32(ctx->r2, 0X6A80);
L_8008779C:
    // 0x8008779C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800877A0: nop

    // 0x800877A4: bne         $v1, $t9, L_800877B8
    if (ctx->r3 != ctx->r25) {
        // 0x800877A8: nop
    
            goto L_800877B8;
    }
    // 0x800877A8: nop

    // 0x800877AC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800877B0: b           L_800877C4
    // 0x800877B4: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
        goto L_800877C4;
    // 0x800877B4: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
L_800877B8:
    // 0x800877B8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800877BC: nop

    // 0x800877C0: sb          $zero, 0x13($t3)
    MEM_B(0X13, ctx->r11) = 0;
L_800877C4:
    // 0x800877C4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800877C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800877CC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800877D0: bne         $at, $zero, L_8008779C
    if (ctx->r1 != 0) {
        // 0x800877D4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8008779C;
    }
    // 0x800877D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800877D8:
    // 0x800877D8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800877DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800877E0: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x800877E4: bne         $t5, $zero, L_8008780C
    if (ctx->r13 != 0) {
        // 0x800877E8: addiu       $a3, $a3, 0x6A78
        ctx->r7 = ADD32(ctx->r7, 0X6A78);
            goto L_8008780C;
    }
    // 0x800877E8: addiu       $a3, $a3, 0x6A78
    ctx->r7 = ADD32(ctx->r7, 0X6A78);
    // 0x800877EC: andi        $v0, $t4, 0x9000
    ctx->r2 = ctx->r12 & 0X9000;
    // 0x800877F0: beq         $v0, $zero, L_800879C4
    if (ctx->r2 == 0) {
        // 0x800877F4: nop
    
            goto L_800879C4;
    }
    // 0x800877F4: nop

    // 0x800877F8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800877FC: nop

    // 0x80087800: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087804: bne         $t7, $a0, L_800879C4
    if (ctx->r15 != ctx->r4) {
        // 0x80087808: nop
    
            goto L_800879C4;
    }
    // 0x80087808: nop

L_8008780C:
    // 0x8008780C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087814: jal         0x80001D04
    // 0x80087818: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087818: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8008781C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087820: addiu       $t1, $t1, 0x63E0
    ctx->r9 = ADD32(ctx->r9, 0X63E0);
    // 0x80087824: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80087828: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008782C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80087830: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80087834: beq         $t0, $zero, L_80087868
    if (ctx->r8 == 0) {
        // 0x80087838: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80087868;
    }
    // 0x80087838: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8008783C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087840: beq         $t0, $at, L_8008788C
    if (ctx->r8 == ctx->r1) {
        // 0x80087844: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8008788C;
    }
    // 0x80087844: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80087848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8008784C: beq         $t0, $v0, L_80087900
    if (ctx->r8 == ctx->r2) {
        // 0x80087850: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80087900;
    }
    // 0x80087850: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80087854: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087858: beq         $t0, $at, L_80087974
    if (ctx->r8 == ctx->r1) {
        // 0x8008785C: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80087974;
    }
    // 0x8008785C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80087860: b           L_80087B54
    // 0x80087864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087B54;
    // 0x80087864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087868:
    // 0x80087868: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008786C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80087870: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80087874: bne         $t3, $zero, L_80087B50
    if (ctx->r11 != 0) {
        // 0x80087878: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087B50;
    }
    // 0x80087878: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008787C: sw          $t5, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r13;
    // 0x80087880: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087884: b           L_80087B50
    // 0x80087888: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087B50;
    // 0x80087888: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_8008788C:
    // 0x8008788C: lw          $t6, -0x524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X524);
    // 0x80087890: nop

    // 0x80087894: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80087898: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8008789C: beq         $at, $zero, L_800878F0
    if (ctx->r1 == 0) {
        // 0x800878A0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800878F0;
    }
    // 0x800878A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800878A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800878A8: addu        $at, $at, $t7
    gpr jr_addend_800878B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800878AC: lw          $t7, -0x7BC0($at)
    ctx->r15 = ADD32(ctx->r1, -0X7BC0);
    // 0x800878B0: nop

    // 0x800878B4: jr          $t7
    // 0x800878B8: nop

    switch (jr_addend_800878B4 >> 2) {
        case 0: goto L_800878D4; break;
        case 1: goto L_800878D4; break;
        case 2: goto L_800878D4; break;
        case 3: goto L_800878F0; break;
        case 4: goto L_800878BC; break;
        case 5: goto L_800878F0; break;
        case 6: goto L_800878E0; break;
        case 7: goto L_800878F0; break;
        case 8: goto L_800878D4; break;
        default: switch_error(__func__, 0x800878B4, 0x800E8440);
    }
    // 0x800878B8: nop

L_800878BC:
    // 0x800878BC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800878C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800878C4: sw          $t8, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r24;
    // 0x800878C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800878CC: b           L_80087B50
    // 0x800878D0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_80087B50;
    // 0x800878D0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800878D4:
    // 0x800878D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800878D8: b           L_80087B50
    // 0x800878DC: sw          $zero, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = 0;
        goto L_80087B50;
    // 0x800878DC: sw          $zero, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = 0;
L_800878E0:
    // 0x800878E0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800878E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800878E8: b           L_80087B50
    // 0x800878EC: sw          $t2, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r10;
        goto L_80087B50;
    // 0x800878EC: sw          $t2, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r10;
L_800878F0:
    // 0x800878F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800878F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800878F8: b           L_80087B50
    // 0x800878FC: sw          $t3, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r11;
        goto L_80087B50;
    // 0x800878FC: sw          $t3, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r11;
L_80087900:
    // 0x80087900: lw          $t5, -0x524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X524);
    // 0x80087904: nop

    // 0x80087908: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x8008790C: sltiu       $at, $t4, 0x9
    ctx->r1 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x80087910: beq         $at, $zero, L_80087964
    if (ctx->r1 == 0) {
        // 0x80087914: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80087964;
    }
    // 0x80087914: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087918: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008791C: addu        $at, $at, $t4
    gpr jr_addend_80087928 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80087920: lw          $t4, -0x7B9C($at)
    ctx->r12 = ADD32(ctx->r1, -0X7B9C);
    // 0x80087924: nop

    // 0x80087928: jr          $t4
    // 0x8008792C: nop

    switch (jr_addend_80087928 >> 2) {
        case 0: goto L_80087930; break;
        case 1: goto L_80087948; break;
        case 2: goto L_80087948; break;
        case 3: goto L_80087964; break;
        case 4: goto L_80087930; break;
        case 5: goto L_80087964; break;
        case 6: goto L_80087954; break;
        case 7: goto L_80087964; break;
        case 8: goto L_80087948; break;
        default: switch_error(__func__, 0x80087928, 0x800E8464);
    }
    // 0x8008792C: nop

L_80087930:
    // 0x80087930: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80087934: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087938: sw          $t6, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r14;
    // 0x8008793C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80087940: b           L_80087B50
    // 0x80087944: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80087B50;
    // 0x80087944: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80087948:
    // 0x80087948: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008794C: b           L_80087B50
    // 0x80087950: sw          $zero, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = 0;
        goto L_80087B50;
    // 0x80087950: sw          $zero, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = 0;
L_80087954:
    // 0x80087954: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80087958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008795C: b           L_80087B50
    // 0x80087960: sw          $t8, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r24;
        goto L_80087B50;
    // 0x80087960: sw          $t8, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r24;
L_80087964:
    // 0x80087964: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087968: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008796C: b           L_80087B50
    // 0x80087970: sw          $t9, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r25;
        goto L_80087B50;
    // 0x80087970: sw          $t9, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r25;
L_80087974:
    // 0x80087974: lw          $t2, -0x524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X524);
    // 0x80087978: nop

    // 0x8008797C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80087980: sltiu       $at, $t3, 0xA
    ctx->r1 = ctx->r11 < 0XA ? 1 : 0;
    // 0x80087984: beq         $at, $zero, L_80087B50
    if (ctx->r1 == 0) {
        // 0x80087988: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80087B50;
    }
    // 0x80087988: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008798C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087990: addu        $at, $at, $t3
    gpr jr_addend_8008799C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80087994: lw          $t3, -0x7B78($at)
    ctx->r11 = ADD32(ctx->r1, -0X7B78);
    // 0x80087998: nop

    // 0x8008799C: jr          $t3
    // 0x800879A0: nop

    switch (jr_addend_8008799C >> 2) {
        case 0: goto L_800879A4; break;
        case 1: goto L_800879A4; break;
        case 2: goto L_800879A4; break;
        case 3: goto L_80087B50; break;
        case 4: goto L_800879A4; break;
        case 5: goto L_80087B50; break;
        case 6: goto L_800879A4; break;
        case 7: goto L_80087B50; break;
        case 8: goto L_800879BC; break;
        case 9: goto L_800879BC; break;
        default: switch_error(__func__, 0x8008799C, 0x800E8488);
    }
    // 0x800879A0: nop

L_800879A4:
    // 0x800879A4: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800879A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800879AC: sw          $t5, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r13;
    // 0x800879B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800879B4: b           L_80087B50
    // 0x800879B8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087B50;
    // 0x800879B8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_800879BC:
    // 0x800879BC: b           L_80087B50
    // 0x800879C0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_80087B50;
    // 0x800879C0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800879C4:
    // 0x800879C4: beq         $v0, $zero, L_80087AD0
    if (ctx->r2 == 0) {
        // 0x800879C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80087AD0;
    }
    // 0x800879C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800879CC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800879D0: jal         0x80001D04
    // 0x800879D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800879D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x800879D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800879DC: addiu       $t1, $t1, 0x63E0
    ctx->r9 = ADD32(ctx->r9, 0X63E0);
    // 0x800879E0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800879E4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800879E8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800879EC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800879F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800879F4: lw          $v0, -0x524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X524);
    // 0x800879F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800879FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087A00: beq         $v0, $at, L_80087A68
    if (ctx->r2 == ctx->r1) {
        // 0x80087A04: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80087A68;
    }
    // 0x80087A04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087A08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80087A0C: beq         $v0, $at, L_80087A2C
    if (ctx->r2 == ctx->r1) {
        // 0x80087A10: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087A2C;
    }
    // 0x80087A10: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087A14: beq         $v0, $at, L_80087AA8
    if (ctx->r2 == ctx->r1) {
        // 0x80087A18: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80087AA8;
    }
    // 0x80087A18: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80087A1C: beq         $v0, $at, L_80087A68
    if (ctx->r2 == ctx->r1) {
        // 0x80087A20: nop
    
            goto L_80087A68;
    }
    // 0x80087A20: nop

    // 0x80087A24: b           L_80087B54
    // 0x80087A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087B54;
    // 0x80087A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087A2C:
    // 0x80087A2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087A30: lw          $a0, -0x520($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X520);
    // 0x80087A34: jal         0x80075DC4
    // 0x80087A38: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    reformat_controller_pak(rdram, ctx);
        goto after_2;
    // 0x80087A38: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80087A3C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A40: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087A44: bne         $t0, $v0, L_80087A58
    if (ctx->r8 != ctx->r2) {
        // 0x80087A48: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087A58;
    }
    // 0x80087A48: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087A4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A50: b           L_80087B50
    // 0x80087A54: sw          $zero, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = 0;
        goto L_80087B50;
    // 0x80087A54: sw          $zero, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = 0;
L_80087A58:
    // 0x80087A58: bne         $t0, $at, L_80087B50
    if (ctx->r8 != ctx->r1) {
        // 0x80087A5C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087B50;
    }
    // 0x80087A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A60: b           L_80087B50
    // 0x80087A64: sw          $zero, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = 0;
        goto L_80087B50;
    // 0x80087A64: sw          $zero, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = 0;
L_80087A68:
    // 0x80087A68: lw          $a0, -0x520($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X520);
    // 0x80087A6C: jal         0x80075D38
    // 0x80087A70: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    repair_controller_pak(rdram, ctx);
        goto after_3;
    // 0x80087A70: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_3:
    // 0x80087A74: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087A7C: bne         $t0, $v0, L_80087A94
    if (ctx->r8 != ctx->r2) {
        // 0x80087A80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80087A94;
    }
    // 0x80087A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087A84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087A88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A8C: b           L_80087B50
    // 0x80087A90: sw          $t8, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r24;
        goto L_80087B50;
    // 0x80087A90: sw          $t8, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r24;
L_80087A94:
    // 0x80087A94: bne         $t0, $at, L_80087B50
    if (ctx->r8 != ctx->r1) {
        // 0x80087A98: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80087B50;
    }
    // 0x80087A98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087A9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087AA0: b           L_80087B50
    // 0x80087AA4: sw          $t9, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r25;
        goto L_80087B50;
    // 0x80087AA4: sw          $t9, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r25;
L_80087AA8:
    // 0x80087AA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087AAC: bne         $t0, $v0, L_80087AC4
    if (ctx->r8 != ctx->r2) {
        // 0x80087AB0: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80087AC4;
    }
    // 0x80087AB0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80087AB4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80087AB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087ABC: b           L_80087B50
    // 0x80087AC0: sw          $t2, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r10;
        goto L_80087B50;
    // 0x80087AC0: sw          $t2, 0x6A1C($at)
    MEM_W(0X6A1C, ctx->r1) = ctx->r10;
L_80087AC4:
    // 0x80087AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087AC8: b           L_80087B50
    // 0x80087ACC: sw          $t3, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r11;
        goto L_80087B50;
    // 0x80087ACC: sw          $t3, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r11;
L_80087AD0:
    // 0x80087AD0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80087AD4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80087AD8: bgez        $t5, L_80087B18
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80087ADC: nop
    
            goto L_80087B18;
    }
    // 0x80087ADC: nop

    // 0x80087AE0: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80087AE4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80087AE8: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80087AEC: beq         $at, $zero, L_80087B18
    if (ctx->r1 == 0) {
        // 0x80087AF0: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087B18;
    }
    // 0x80087AF0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087AF4: jal         0x80001D04
    // 0x80087AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80087AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80087AFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087B00: addiu       $a3, $a3, 0x6A78
    ctx->r7 = ADD32(ctx->r7, 0X6A78);
    // 0x80087B04: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80087B08: nop

    // 0x80087B0C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80087B10: b           L_80087B50
    // 0x80087B14: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80087B50;
    // 0x80087B14: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80087B18:
    // 0x80087B18: blez        $t9, L_80087B54
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80087B1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087B54;
    }
    // 0x80087B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B20: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80087B24: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087B28: blez        $t2, L_80087B54
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80087B2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087B54;
    }
    // 0x80087B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B30: jal         0x80001D04
    // 0x80087B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80087B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80087B38: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087B3C: addiu       $a3, $a3, 0x6A78
    ctx->r7 = ADD32(ctx->r7, 0X6A78);
    // 0x80087B40: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80087B44: nop

    // 0x80087B48: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x80087B4C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80087B50:
    // 0x80087B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087B54:
    // 0x80087B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087B58: jr          $ra
    // 0x80087B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void onscreen_ai_racer_physics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A84: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80055A88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055A8C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80055A90: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80055A94: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80055A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055A9C: lwc1        $f0, -0x2B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B10);
    // 0x80055AA0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80055AA4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80055AA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80055AAC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80055AB0: bc1f        L_80055ABC
    if (!c1cs) {
        // 0x80055AB4: nop
    
            goto L_80055ABC;
    }
    // 0x80055AB4: nop

    // 0x80055AB8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
L_80055ABC:
    // 0x80055ABC: jal         0x8001E29C
    // 0x80055AC0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80055AC0: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x80055AC4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80055AC8: sb          $t6, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r14;
    // 0x80055ACC: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x80055AD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80055AD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055AD8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80055ADC: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80055AE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055AE4: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80055AE8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055AEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80055AF0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80055AF4: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055AF8: nop

    // 0x80055AFC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80055B00: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055B04: swc1        $f0, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f0.u32l;
    // 0x80055B08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055B0C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055B10: swc1        $f0, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f0.u32l;
    // 0x80055B14: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80055B18: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80055B1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055B20: bne         $t1, $at, L_80055B3C
    if (ctx->r9 != ctx->r1) {
        // 0x80055B24: addiu       $t3, $sp, 0x48
        ctx->r11 = ADD32(ctx->r29, 0X48);
            goto L_80055B3C;
    }
    // 0x80055B24: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x80055B28: lb          $t2, 0x1D7($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D7);
    // 0x80055B2C: nop

    // 0x80055B30: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80055B34: beq         $at, $zero, L_80055B68
    if (ctx->r1 == 0) {
        // 0x80055B38: addiu       $t3, $sp, 0x48
        ctx->r11 = ADD32(ctx->r29, 0X48);
            goto L_80055B68;
    }
    // 0x80055B38: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
L_80055B3C:
    // 0x80055B3C: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x80055B40: addiu       $t5, $sp, 0x3F
    ctx->r13 = ADD32(ctx->r29, 0X3F);
    // 0x80055B44: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80055B48: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80055B4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80055B50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80055B58: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80055B5C: jal         0x80017248
    // 0x80055B60: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    collision_objectmodel(rdram, ctx);
        goto after_1;
    // 0x80055B60: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    after_1:
    // 0x80055B64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80055B68:
    // 0x80055B68: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x80055B6C: beq         $t6, $zero, L_80055BA8
    if (ctx->r14 == 0) {
        // 0x80055B70: addiu       $a1, $s0, 0xD8
        ctx->r5 = ADD32(ctx->r16, 0XD8);
            goto L_80055BA8;
    }
    // 0x80055B70: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x80055B74: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80055B78: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055B7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055B80: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80055B84: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80055B88: swc1        $f10, -0x2AB8($at)
    MEM_W(-0X2AB8, ctx->r1) = ctx->f10.u32l;
    // 0x80055B8C: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055B90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055B94: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055B98: swc1        $f8, -0x2AB4($at)
    MEM_W(-0X2AB4, ctx->r1) = ctx->f8.u32l;
    // 0x80055B9C: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80055BA0: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80055BA4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80055BA8:
    // 0x80055BA8: beq         $v1, $zero, L_80055BE4
    if (ctx->r3 == 0) {
        // 0x80055BAC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80055BE4;
    }
    // 0x80055BAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80055BB0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80055BB4: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055BB8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80055BBC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80055BC0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80055BC4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80055BC8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80055BCC: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80055BD0: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80055BD4: nop

    // 0x80055BD8: bc1f        L_80055BE4
    if (!c1cs) {
        // 0x80055BDC: nop
    
            goto L_80055BE4;
    }
    // 0x80055BDC: nop

    // 0x80055BE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80055BE4:
    // 0x80055BE4: lb          $a3, 0x1D6($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055BE8: sb          $t0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r8;
    // 0x80055BEC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80055BF0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80055BF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80055BF8: jal         0x80031130
    // 0x80055BFC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x80055BFC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80055C00: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80055C04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055C08: addiu       $t9, $sp, 0x74
    ctx->r25 = ADD32(ctx->r29, 0X74);
    // 0x80055C0C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055C10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80055C14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80055C18: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80055C1C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80055C20: jal         0x80031600
    // 0x80055C24: addiu       $a3, $sp, 0x3F
    ctx->r7 = ADD32(ctx->r29, 0X3F);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x80055C24: addiu       $a3, $sp, 0x3F
    ctx->r7 = ADD32(ctx->r29, 0X3F);
    after_3:
    // 0x80055C28: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80055C2C: lb          $t0, 0x3E($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X3E);
    // 0x80055C30: sb          $v0, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r2;
    // 0x80055C34: lb          $t1, 0x1E3($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055C38: sb          $v1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r3;
    // 0x80055C3C: or          $t2, $t1, $v1
    ctx->r10 = ctx->r9 | ctx->r3;
    // 0x80055C40: sb          $t2, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r10;
    // 0x80055C44: lb          $t3, 0x1E3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055C48: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x80055C4C: beq         $t3, $zero, L_80055C64
    if (ctx->r11 == 0) {
        // 0x80055C50: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80055C64;
    }
    // 0x80055C50: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80055C54: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80055C58: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80055C5C: sb          $t4, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r12;
    // 0x80055C60: sb          $t5, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r13;
L_80055C64:
    // 0x80055C64: beq         $t0, $zero, L_80055C98
    if (ctx->r8 == 0) {
        // 0x80055C68: addiu       $v0, $sp, 0x48
        ctx->r2 = ADD32(ctx->r29, 0X48);
            goto L_80055C98;
    }
    // 0x80055C68: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80055C6C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80055C70: nop

    // 0x80055C74: beq         $t6, $zero, L_80055C9C
    if (ctx->r14 == 0) {
        // 0x80055C78: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_80055C9C;
    }
    // 0x80055C78: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80055C7C: lb          $t7, 0x1ED($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1ED);
    // 0x80055C80: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80055C84: bne         $t7, $zero, L_80055C94
    if (ctx->r15 != 0) {
        // 0x80055C88: addiu       $t9, $zero, 0x3C
        ctx->r25 = ADD32(0, 0X3C);
            goto L_80055C94;
    }
    // 0x80055C88: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80055C8C: b           L_80055C98
    // 0x80055C90: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
        goto L_80055C98;
    // 0x80055C90: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
L_80055C94:
    // 0x80055C94: sb          $t9, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r25;
L_80055C98:
    // 0x80055C98: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
L_80055C9C:
    // 0x80055C9C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80055CA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80055CA4: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80055CA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055CAC: bne         $at, $zero, L_80055C9C
    if (ctx->r1 != 0) {
        // 0x80055CB0: swc1        $f8, 0xD4($v1)
        MEM_W(0XD4, ctx->r3) = ctx->f8.u32l;
            goto L_80055C9C;
    }
    // 0x80055CB0: swc1        $f8, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->f8.u32l;
    // 0x80055CB4: lb          $t1, 0x3F($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X3F);
    // 0x80055CB8: lwc1        $f10, 0xD8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80055CBC: sb          $t1, 0x1DC($s0)
    MEM_B(0X1DC, ctx->r16) = ctx->r9;
    // 0x80055CC0: lb          $t2, 0x3F($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3F);
    // 0x80055CC4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80055CC8: sb          $t2, 0x1DD($s0)
    MEM_B(0X1DD, ctx->r16) = ctx->r10;
    // 0x80055CCC: lb          $t3, 0x3F($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X3F);
    // 0x80055CD0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80055CD4: sb          $t3, 0x1DE($s0)
    MEM_B(0X1DE, ctx->r16) = ctx->r11;
    // 0x80055CD8: lb          $t4, 0x3F($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X3F);
    // 0x80055CDC: nop

    // 0x80055CE0: sb          $t4, 0x1DF($s0)
    MEM_B(0X1DF, ctx->r16) = ctx->r12;
    // 0x80055CE4: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80055CE8: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80055CEC: nop

    // 0x80055CF0: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x80055CF4: lwc1        $f6, 0xE0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80055CF8: nop

    // 0x80055CFC: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80055D00: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80055D04: nop

    // 0x80055D08: beq         $t5, $zero, L_80055E24
    if (ctx->r13 == 0) {
        // 0x80055D0C: nop
    
            goto L_80055E24;
    }
    // 0x80055D0C: nop

    // 0x80055D10: jal         0x8002ACD4
    // 0x80055D14: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    get_collision_normal(rdram, ctx);
        goto after_4;
    // 0x80055D14: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x80055D18: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80055D1C: nop

    // 0x80055D20: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80055D24: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80055D28: jal         0x800707C4
    // 0x80055D2C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80055D2C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_5:
    // 0x80055D30: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80055D34: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80055D38: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80055D3C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80055D40: jal         0x800707F8
    // 0x80055D44: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80055D44: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_6:
    // 0x80055D48: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80055D4C: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80055D50: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80055D54: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80055D58: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80055D5C: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80055D60: nop

    // 0x80055D64: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80055D68: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055D6C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80055D70: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055D74: jal         0x80070750
    // 0x80055D78: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x80055D78: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80055D7C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80055D80: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80055D84: negu        $v1, $t1
    ctx->r3 = SUB32(0, ctx->r9);
    // 0x80055D88: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80055D8C: beq         $at, $zero, L_80055DA0
    if (ctx->r1 == 0) {
        // 0x80055D90: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_80055DA0;
    }
    // 0x80055D90: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80055D94: bne         $at, $zero, L_80055DA0
    if (ctx->r1 != 0) {
        // 0x80055D98: nop
    
            goto L_80055DA0;
    }
    // 0x80055D98: nop

    // 0x80055D9C: sh          $v1, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r3;
L_80055DA0:
    // 0x80055DA0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80055DA4: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80055DA8: jal         0x80070750
    // 0x80055DAC: nop

    arctan2_f(rdram, ctx);
        goto after_8;
    // 0x80055DAC: nop

    after_8:
    // 0x80055DB0: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80055DB4: sra         $t2, $v1, 16
    ctx->r10 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80055DB8: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
    // 0x80055DBC: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80055DC0: beq         $at, $zero, L_80055DD4
    if (ctx->r1 == 0) {
        // 0x80055DC4: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_80055DD4;
    }
    // 0x80055DC4: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80055DC8: bne         $at, $zero, L_80055DD4
    if (ctx->r1 != 0) {
        // 0x80055DCC: nop
    
            goto L_80055DD4;
    }
    // 0x80055DCC: nop

    // 0x80055DD0: sh          $v1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r3;
L_80055DD4:
    // 0x80055DD4: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055DD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055DDC: bne         $t3, $at, L_80055E24
    if (ctx->r11 != ctx->r1) {
        // 0x80055DE0: nop
    
            goto L_80055E24;
    }
    // 0x80055DE0: nop

    // 0x80055DE4: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055DE8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80055DEC: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80055DF0: subu        $v0, $v1, $t4
    ctx->r2 = SUB32(ctx->r3, ctx->r12);
    // 0x80055DF4: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80055DF8: bne         $at, $zero, L_80055E08
    if (ctx->r1 != 0) {
        // 0x80055DFC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80055E08;
    }
    // 0x80055DFC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80055E00: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80055E04: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80055E08:
    // 0x80055E08: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80055E0C: beq         $at, $zero, L_80055E18
    if (ctx->r1 == 0) {
        // 0x80055E10: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80055E18;
    }
    // 0x80055E10: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80055E14: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80055E18:
    // 0x80055E18: sra         $t5, $v0, 2
    ctx->r13 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80055E1C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80055E20: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_80055E24:
    // 0x80055E24: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055E28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055E2C: beq         $v0, $at, L_80055EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055EAC;
    }
    // 0x80055E30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055E34: beq         $v0, $at, L_80055EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E38: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80055EAC;
    }
    // 0x80055E38: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055E3C: beq         $v0, $at, L_80055EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E40: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80055EAC;
    }
    // 0x80055E40: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055E44: beq         $v0, $at, L_80055EB0
    if (ctx->r2 == ctx->r1) {
        // 0x80055E48: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055EB0;
    }
    // 0x80055E48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055E4C: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055E50: addiu       $t7, $zero, 0x3400
    ctx->r15 = ADD32(0, 0X3400);
    // 0x80055E54: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055E58: bne         $at, $zero, L_80055E6C
    if (ctx->r1 != 0) {
        // 0x80055E5C: addiu       $t8, $zero, -0x3400
        ctx->r24 = ADD32(0, -0X3400);
            goto L_80055E6C;
    }
    // 0x80055E5C: addiu       $t8, $zero, -0x3400
    ctx->r24 = ADD32(0, -0X3400);
    // 0x80055E60: sh          $t7, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r15;
    // 0x80055E64: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055E68: nop

L_80055E6C:
    // 0x80055E6C: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055E70: beq         $at, $zero, L_80055E7C
    if (ctx->r1 == 0) {
        // 0x80055E74: addiu       $t9, $zero, 0x3400
        ctx->r25 = ADD32(0, 0X3400);
            goto L_80055E7C;
    }
    // 0x80055E74: addiu       $t9, $zero, 0x3400
    ctx->r25 = ADD32(0, 0X3400);
    // 0x80055E78: sh          $t8, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r24;
L_80055E7C:
    // 0x80055E7C: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055E80: addiu       $t1, $zero, -0x3400
    ctx->r9 = ADD32(0, -0X3400);
    // 0x80055E84: slti        $at, $a0, 0x3401
    ctx->r1 = SIGNED(ctx->r4) < 0X3401 ? 1 : 0;
    // 0x80055E88: bne         $at, $zero, L_80055EA0
    if (ctx->r1 != 0) {
        // 0x80055E8C: slti        $at, $a0, -0x3400
        ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
            goto L_80055EA0;
    }
    // 0x80055E8C: slti        $at, $a0, -0x3400
    ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
    // 0x80055E90: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
    // 0x80055E94: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055E98: nop

    // 0x80055E9C: slti        $at, $a0, -0x3400
    ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
L_80055EA0:
    // 0x80055EA0: beq         $at, $zero, L_80055EB0
    if (ctx->r1 == 0) {
        // 0x80055EA4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055EB0;
    }
    // 0x80055EA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055EA8: sh          $t1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r9;
L_80055EAC:
    // 0x80055EAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80055EB0:
    // 0x80055EB0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80055EB4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80055EB8: jr          $ra
    // 0x80055EBC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80055EBC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void get_collision_candidate_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ACA4: lw          $t6, -0x2C88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C88);
    // 0x8002ACA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002ACAC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002ACB0: lw          $t7, -0x2C90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C90);
    // 0x8002ACB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002ACB8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8002ACBC: lw          $t8, -0x2C8C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C8C);
    // 0x8002ACC0: jr          $ra
    // 0x8002ACC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    return;
    // 0x8002ACC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void play_random_character_voice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_presentation_random_begin(uint8_t*, recomp_context*); dkr_netplay_presentation_random_begin(rdram, ctx);
    // 0x800570B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800570BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800570C0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800570C4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800570C8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800570CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800570D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800570D4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800570D8: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x800570DC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800570E0: lw          $t7, 0x108($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X108);
    // 0x800570E4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800570E8: bne         $t7, $zero, L_80057204
    if (ctx->r15 != 0) {
        // 0x800570EC: andi        $t8, $a3, 0x80
        ctx->r24 = ctx->r7 & 0X80;
            goto L_80057204;
    }
    // 0x800570EC: andi        $t8, $a3, 0x80
    ctx->r24 = ctx->r7 & 0X80;
    // 0x800570F0: beq         $t8, $zero, L_80057104
    if (ctx->r24 == 0) {
        // 0x800570F4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80057104;
    }
    // 0x800570F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800570F8: lw          $t9, -0x2AA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AA4);
    // 0x800570FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057100: beq         $t9, $at, L_80057204
    if (ctx->r25 == ctx->r1) {
        // 0x80057104: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80057204;
    }
L_80057104:
    // 0x80057104: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057108: bne         $s0, $at, L_8005713C
    if (ctx->r16 != ctx->r1) {
        // 0x8005710C: nop
    
            goto L_8005713C;
    }
    // 0x8005710C: nop

    // 0x80057110: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x80057114: nop

    // 0x80057118: beq         $a0, $zero, L_8005713C
    if (ctx->r4 == 0) {
        // 0x8005711C: nop
    
            goto L_8005713C;
    }
    // 0x8005711C: nop

    // 0x80057120: lhu         $t1, 0x2A($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X2A);
    // 0x80057124: nop

    // 0x80057128: beq         $s3, $t1, L_8005713C
    if (ctx->r19 == ctx->r9) {
        // 0x8005712C: nop
    
            goto L_8005713C;
    }
    // 0x8005712C: nop

    // 0x80057130: jal         0x800096F8
    // 0x80057134: nop

    audspat_point_stop(rdram, ctx);
        goto after_0;
    // 0x80057134: nop

    after_0:
    // 0x80057138: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_8005713C:
    // 0x8005713C: lw          $t2, 0x24($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X24);
    // 0x80057140: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057144: bne         $t2, $zero, L_80057208
    if (ctx->r10 != 0) {
        // 0x80057148: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80057208;
    }
    // 0x80057148: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005714C: bne         $s0, $at, L_80057164
    if (ctx->r16 != ctx->r1) {
        // 0x80057150: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80057164;
    }
    // 0x80057150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057154: jal         0x8006F94C
    // 0x80057158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80057158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8005715C: beq         $v0, $zero, L_80057208
    if (ctx->r2 == 0) {
        // 0x80057160: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80057208;
    }
    // 0x80057160: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80057164:
    // 0x80057164: sh          $s3, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r19;
    // 0x80057168: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8005716C: lb          $t3, 0x3($s2)
    ctx->r11 = MEM_B(ctx->r18, 0X3);
    // 0x80057170: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80057174: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80057178: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005717C: jal         0x8006F94C
    // 0x80057180: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80057180: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    after_2:
    // 0x80057184: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x80057188: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005718C: mflo        $t4
    ctx->r12 = lo;
    // 0x80057190: addu        $v1, $t4, $s3
    ctx->r3 = ADD32(ctx->r12, ctx->r19);
    // 0x80057194: blez        $s1, L_800571CC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80057198: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800571CC;
    }
    // 0x80057198: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8005719C: lhu         $t5, 0x28($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X28);
    // 0x800571A0: nop

    // 0x800571A4: bne         $v1, $t5, L_800571CC
    if (ctx->r3 != ctx->r13) {
        // 0x800571A8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800571CC;
    }
    // 0x800571A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800571AC:
    // 0x800571AC: jal         0x8006F94C
    // 0x800571B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800571B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800571B4: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800571B8: lhu         $t7, 0x28($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X28);
    // 0x800571BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800571C0: addu        $t0, $t6, $s3
    ctx->r8 = ADD32(ctx->r14, ctx->r19);
    // 0x800571C4: beq         $t0, $t7, L_800571AC
    if (ctx->r8 == ctx->r15) {
        // 0x800571C8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800571AC;
    }
    // 0x800571C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800571CC:
    // 0x800571CC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800571D0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800571D4: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    // 0x800571D8: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x800571DC: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x800571E0: addiu       $t1, $s2, 0x24
    ctx->r9 = ADD32(ctx->r18, 0X24);
    // 0x800571E4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800571E8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800571EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    { extern unsigned dkr_legacy_character_race_sound(uint8_t*, recomp_context*, uint32_t, unsigned); ctx->r8 = dkr_legacy_character_race_sound(rdram, ctx, (uint32_t)ctx->r18, (unsigned)ctx->r8); }
    // 0x800571F0: jal         0x80009558
    // 0x800571F4: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_4;
    // 0x800571F4: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    after_4:
    // 0x800571F8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800571FC: nop

    // 0x80057200: sh          $t0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r8;
L_80057204:
    // 0x80057204: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80057208:
    extern void dkr_netplay_presentation_random_end(uint8_t*, recomp_context*); dkr_netplay_presentation_random_end(rdram, ctx);
    // 0x80057208: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005720C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80057210: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80057214: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80057218: jr          $ra
    // 0x8005721C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005721C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void unset_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EABC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EAC0: addiu       $v0, $v0, 0x6448
    ctx->r2 = ADD32(ctx->r2, 0X6448);
    // 0x8009EAC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009EAC8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009EACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EAD0: nor         $t0, $a0, $zero
    ctx->r8 = ~(ctx->r4 | 0);
    // 0x8009EAD4: nor         $t1, $a1, $zero
    ctx->r9 = ~(ctx->r5 | 0);
    // 0x8009EAD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EADC: and         $t2, $t6, $t0
    ctx->r10 = ctx->r14 & ctx->r8;
    // 0x8009EAE0: and         $t3, $t7, $t1
    ctx->r11 = ctx->r15 & ctx->r9;
    // 0x8009EAE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EAE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EAEC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009EAF0: jal         0x8006ECE0
    // 0x8009EAF4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009EAF4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009EAF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EAFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EB00: jr          $ra
    // 0x8009EB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009EB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void sndp_stop_all_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049E0: jal         0x800048D8
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x800049E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049F0: jr          $ra
    // 0x800049F4: nop

    return;
    // 0x800049F4: nop

;}
RECOMP_FUNC void traverse_segments_bsp_tree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029AF8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80029AFC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80029B00: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80029B04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029B08: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80029B0C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80029B10: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80029B14: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80029B18: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029B1C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029B20: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80029B24: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80029B28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029B2C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80029B30: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80029B34: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80029B38: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80029B3C: addiu       $fp, $fp, -0x36E8
    ctx->r30 = ADD32(ctx->r30, -0X36E8);
    // 0x80029B40: addiu       $s7, $s7, -0x4F50
    ctx->r23 = ADD32(ctx->r23, -0X4F50);
    // 0x80029B44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80029B48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_80029B4C:
    // 0x80029B4C: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80029B50: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80029B54: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029B58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029B5C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80029B60: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80029B64: nop

    // 0x80029B68: bne         $v0, $zero, L_80029BA0
    if (ctx->r2 != 0) {
        // 0x80029B6C: nop
    
            goto L_80029BA0;
    }
    // 0x80029B6C: nop

    // 0x80029B70: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80029B74: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80029B78: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80029B7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029B80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029B84: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80029B88: nop

    // 0x80029B8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029B90: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80029B94: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80029B98: b           L_80029C08
    // 0x80029B9C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C08;
    // 0x80029B9C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029BA0:
    // 0x80029BA0: bne         $v0, $at, L_80029BD8
    if (ctx->r2 != ctx->r1) {
        // 0x80029BA4: nop
    
            goto L_80029BD8;
    }
    // 0x80029BA4: nop

    // 0x80029BA8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029BAC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80029BB0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029BB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BBC: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80029BC0: nop

    // 0x80029BC4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029BC8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80029BCC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029BD0: b           L_80029C08
    // 0x80029BD4: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C08;
    // 0x80029BD4: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029BD8:
    // 0x80029BD8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80029BDC: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80029BE0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80029BE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BEC: lwc1        $f16, 0x14($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80029BF0: nop

    // 0x80029BF4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029BF8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80029BFC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80029C00: nop

    // 0x80029C04: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029C08:
    // 0x80029C08: nop

    // 0x80029C0C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80029C10: beq         $at, $zero, L_80029C84
    if (ctx->r1 == 0) {
        // 0x80029C14: nop
    
            goto L_80029C84;
    }
    // 0x80029C14: nop

    // 0x80029C18: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80029C1C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029C20: beq         $s6, $a0, L_80029C48
    if (ctx->r22 == ctx->r4) {
        // 0x80029C24: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029C48;
    }
    // 0x80029C24: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029C28: lbu         $a2, 0x5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5);
    // 0x80029C2C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029C30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029C34: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80029C38: jal         0x80029AF8
    // 0x80029C3C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_0;
    // 0x80029C3C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x80029C40: b           L_80029C54
    // 0x80029C44: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
        goto L_80029C54;
    // 0x80029C44: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C48:
    // 0x80029C48: jal         0x80029D14
    // 0x80029C4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_1;
    // 0x80029C4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80029C50: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C54:
    // 0x80029C54: nop

    // 0x80029C58: beq         $s6, $a0, L_80029C6C
    if (ctx->r22 == ctx->r4) {
        // 0x80029C5C: nop
    
            goto L_80029C6C;
    }
    // 0x80029C5C: nop

    // 0x80029C60: lbu         $s4, 0x5($s0)
    ctx->r20 = MEM_BU(ctx->r16, 0X5);
    // 0x80029C64: b           L_80029B4C
    // 0x80029C68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
        goto L_80029B4C;
    // 0x80029C68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_80029C6C:
    // 0x80029C6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80029C70: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029C74: jal         0x80029D14
    // 0x80029C78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_2;
    // 0x80029C78: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80029C7C: b           L_80029CE8
    // 0x80029C80: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80029CE8;
    // 0x80029C80: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029C84:
    // 0x80029C84: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80029C88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029C8C: beq         $s6, $a0, L_80029CB0
    if (ctx->r22 == ctx->r4) {
        // 0x80029C90: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029CB0;
    }
    // 0x80029C90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029C94: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80029C98: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029C9C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029CA0: jal         0x80029AF8
    // 0x80029CA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x80029CA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80029CA8: b           L_80029CBC
    // 0x80029CAC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
        goto L_80029CBC;
    // 0x80029CAC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CB0:
    // 0x80029CB0: jal         0x80029D14
    // 0x80029CB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_4;
    // 0x80029CB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80029CB8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CBC:
    // 0x80029CBC: nop

    // 0x80029CC0: beq         $s6, $a0, L_80029CD4
    if (ctx->r22 == ctx->r4) {
        // 0x80029CC4: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_80029CD4;
    }
    // 0x80029CC4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029CC8: lbu         $s5, 0x5($s0)
    ctx->r21 = MEM_BU(ctx->r16, 0X5);
    // 0x80029CCC: b           L_80029B4C
    // 0x80029CD0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80029B4C;
    // 0x80029CD0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80029CD4:
    // 0x80029CD4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80029CD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029CDC: jal         0x80029D14
    // 0x80029CE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_5;
    // 0x80029CE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80029CE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029CE8:
    // 0x80029CE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029CEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029CF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029CF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029CF8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029CFC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029D00: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80029D04: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80029D08: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80029D0C: jr          $ra
    // 0x80029D10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80029D10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _ldexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB288: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CB28C: beq         $a2, $zero, L_800CB2BC
    if (ctx->r6 == 0) {
        // 0x800CB290: nop
    
            goto L_800CB2BC;
    }
    // 0x800CB290: nop

    // 0x800CB294: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB298: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800CB29C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800CB2A0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CB2A4: nop

    // 0x800CB2A8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800CB2AC: nop

    // 0x800CB2B0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CB2B4: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800CB2B8: nop

L_800CB2BC:
    // 0x800CB2BC: b           L_800CB2CC
    // 0x800CB2C0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB2CC;
    // 0x800CB2C0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800CB2C4: b           L_800CB2CC
    // 0x800CB2C8: nop

        goto L_800CB2CC;
    // 0x800CB2C8: nop

L_800CB2CC:
    // 0x800CB2CC: jr          $ra
    // 0x800CB2D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CB2D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void input_released(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A578: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A57C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A580: lbu         $t6, 0x1150($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1150);
    // 0x8006A584: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A588: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A58C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A590: lhu         $v0, 0x1148($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1148);
    // 0x8006A594: jr          $ra
    // 0x8006A598: nop

    return;
    // 0x8006A598: nop

;}
RECOMP_FUNC void func_80016748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016748: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8001674C: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80016750: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80016754: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80016758: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8001675C: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80016760: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80016764: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80016768: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8001676C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80016770: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80016774: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80016778: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x8001677C: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80016780: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x80016784: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016788: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8001678C: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016790: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80016794: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016798: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8001679C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800167A0: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800167A4: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x800167A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800167AC: beq         $t6, $zero, L_80016B64
    if (ctx->r14 == 0) {
        // 0x800167B0: or          $s5, $a1, $zero
        ctx->r21 = ctx->r5 | 0;
            goto L_80016B64;
    }
    // 0x800167B0: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800167B4: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x800167B8: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800167BC: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800167C0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800167C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800167C8: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800167CC: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x800167D0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800167D4: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800167D8: nop

    // 0x800167DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800167E0: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800167E4: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x800167E8: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800167EC: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800167F0: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800167F4: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800167F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800167FC: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80016800: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016804: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016808: nop

    // 0x8001680C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80016810: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80016814: jal         0x800C9AD0
    // 0x80016818: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016818: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_0:
    // 0x8001681C: lwc1        $f18, 0x3C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x80016820: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80016824: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x80016828: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8001682C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80016830: add.d       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f16.d + ctx->f30.d;
    // 0x80016834: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x80016838: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8001683C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80016840: nop

    // 0x80016844: bc1t        L_80016B68
    if (c1cs) {
        // 0x80016848: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_80016B68;
    }
    // 0x80016848: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8001684C: lw          $s6, 0x4C($s0)
    ctx->r22 = MEM_W(ctx->r16, 0X4C);
    // 0x80016850: lw          $s4, 0x4C($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X4C);
    // 0x80016854: jal         0x8006FC30
    // 0x80016858: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x80016858: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x8001685C: lh          $t8, 0x20($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X20);
    // 0x80016860: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80016864: blez        $t8, L_80016B64
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80016868: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80016B64;
    }
    // 0x80016868: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001686C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80016870: lwc1        $f29, 0x55F8($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X55F8);
    // 0x80016874: lwc1        $f28, 0x55FC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X55FC);
    // 0x80016878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001687C: lwc1        $f27, 0x5600($at)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r1, 0X5600);
    // 0x80016880: lwc1        $f26, 0x5604($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5604);
    // 0x80016884: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80016888: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
L_8001688C:
    // 0x8001688C: lw          $t0, 0x1C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C);
    // 0x80016890: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x80016894: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80016898: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8001689C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800168A0: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168A4: mflo        $t3
    ctx->r11 = lo;
    // 0x800168A8: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800168AC: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800168B0: nop

    // 0x800168B4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800168B8: nop

    // 0x800168BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800168C0: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800168C4: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x800168C8: lw          $t6, 0x44($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X44);
    // 0x800168CC: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800168D0: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x800168D4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800168D8: multu       $t0, $s7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168DC: mflo        $t1
    ctx->r9 = lo;
    // 0x800168E0: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x800168E4: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x800168E8: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x800168EC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800168F0: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
    // 0x800168F4: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800168F8: addiu       $t1, $sp, 0xA8
    ctx->r9 = ADD32(ctx->r29, 0XA8);
    // 0x800168FC: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80016900: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x80016904: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x80016908: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x8001690C: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80016910: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x80016914: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016918: mflo        $t8
    ctx->r24 = lo;
    // 0x8001691C: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80016920: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x80016924: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80016928: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001692C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80016930: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016934: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80016938: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x8001693C: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80016940: jal         0x8006F64C
    // 0x80016944: nop

    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x80016944: nop

    after_2:
    // 0x80016948: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x8001694C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80016950: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80016954: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80016958: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001695C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80016960: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80016964: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80016968: nop

    // 0x8001696C: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80016970: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016974: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80016978: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001697C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80016980: mul.d       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f30.d);
    // 0x80016984: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80016988: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8001698C: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x80016990: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016994: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x80016998: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001699C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800169A0: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800169A4: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800169A8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800169AC: nop

    // 0x800169B0: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800169B4: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800169B8: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800169BC: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800169C0: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800169C4: jal         0x800C9AD0
    // 0x800169C8: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800169C8: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_3:
    // 0x800169CC: lb          $t3, 0x10($s4)
    ctx->r11 = MEM_B(ctx->r20, 0X10);
    // 0x800169D0: nop

    // 0x800169D4: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800169D8: nop

    // 0x800169DC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800169E0: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x800169E4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800169E8: nop

    // 0x800169EC: bc1f        L_80016B50
    if (!c1cs) {
        // 0x800169F0: nop
    
            goto L_80016B50;
    }
    // 0x800169F0: nop

    // 0x800169F4: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x800169F8: nop

    // 0x800169FC: bc1f        L_80016B50
    if (!c1cs) {
        // 0x80016A00: nop
    
            goto L_80016B50;
    }
    // 0x80016A00: nop

    // 0x80016A04: sub.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80016A08: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016A0C: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80016A10: lh          $t8, 0x14($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X14);
    // 0x80016A14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016A18: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x80016A1C: sh          $t0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r8;
    // 0x80016A20: lh          $t6, 0x14($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X14);
    // 0x80016A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016A28: ori         $t1, $t6, 0x8
    ctx->r9 = ctx->r14 | 0X8;
    // 0x80016A2C: sh          $t1, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r9;
    // 0x80016A30: sw          $s5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r21;
    // 0x80016A34: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x80016A38: sb          $zero, 0x13($s6)
    MEM_B(0X13, ctx->r22) = 0;
    // 0x80016A3C: div.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016A40: sb          $zero, 0x13($s4)
    MEM_B(0X13, ctx->r20) = 0;
    // 0x80016A44: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016A48: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016A4C: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016A50: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80016A54: nop

    // 0x80016A58: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80016A5C: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x80016A60: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80016A64: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x80016A68: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016A6C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016A70: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016A74: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016A78: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016A7C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80016A80: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016A84: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x80016A88: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80016A8C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80016A90: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016A94: nop

    // 0x80016A98: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016A9C: bne         $t2, $at, L_80016B50
    if (ctx->r10 != ctx->r1) {
        // 0x80016AA0: swc1        $f10, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
            goto L_80016B50;
    }
    // 0x80016AA0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80016AA4: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80016AA8: nop

    // 0x80016AAC: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80016AB0: nop

    // 0x80016AB4: bne         $t9, $zero, L_80016AC8
    if (ctx->r25 != 0) {
        // 0x80016AB8: nop
    
            goto L_80016AC8;
    }
    // 0x80016AB8: nop

    // 0x80016ABC: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80016AC0: jal         0x80072348
    // 0x80016AC4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x80016AC4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_4:
L_80016AC8:
    // 0x80016AC8: lb          $t4, 0x1D6($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1D6);
    // 0x80016ACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016AD0: bne         $t4, $at, L_80016B10
    if (ctx->r12 != ctx->r1) {
        // 0x80016AD4: nop
    
            goto L_80016B10;
    }
    // 0x80016AD4: nop

    // 0x80016AD8: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x80016ADC: c.lt.d      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.d < ctx->f6.d;
    // 0x80016AE0: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016AE4: bc1f        L_80016B50
    if (!c1cs) {
        // 0x80016AE8: nop
    
            goto L_80016B50;
    }
    // 0x80016AE8: nop

    // 0x80016AEC: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016AF0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016AF4: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80016AF8: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80016AFC: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B00: nop

    // 0x80016B04: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80016B08: b           L_80016B50
    // 0x80016B0C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80016B50;
    // 0x80016B0C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80016B10:
    // 0x80016B10: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80016B14: c.lt.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d < ctx->f18.d;
    // 0x80016B18: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016B1C: bc1f        L_80016B50
    if (!c1cs) {
        // 0x80016B20: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80016B50;
    }
    // 0x80016B20: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80016B24: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016B28: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016B2C: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80016B30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016B34: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80016B38: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B3C: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016B40: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80016B44: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80016B48: swc1        $f16, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f16.u32l;
    // 0x80016B4C: swc1        $f24, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f24.u32l;
L_80016B50:
    // 0x80016B50: lh          $t5, 0x20($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X20);
    // 0x80016B54: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // 0x80016B58: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80016B5C: bne         $at, $zero, L_8001688C
    if (ctx->r1 != 0) {
        // 0x80016B60: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001688C;
    }
    // 0x80016B60: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016B64:
    // 0x80016B64: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_80016B68:
    // 0x80016B68: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016B6C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016B70: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016B74: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016B78: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80016B7C: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80016B80: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80016B84: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80016B88: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x80016B8C: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80016B90: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x80016B94: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80016B98: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80016B9C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80016BA0: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80016BA4: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80016BA8: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80016BAC: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80016BB0: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80016BB4: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80016BB8: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80016BBC: jr          $ra
    // 0x80016BC0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80016BC0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void copy_framebuffer_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066C8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80066C90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80066C94: jal         0x8007A520
    // 0x80066C98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80066C98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066C9C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80066CA0: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80066CA4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80066CA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80066CAC: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066CB0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80066CB4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80066CB8: nop

    // 0x80066CBC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80066CC0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80066CC4: nop

    // 0x80066CC8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80066CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CD4: jr          $ra
    // 0x80066CD8: nop

    return;
    // 0x80066CD8: nop

;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D04E0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D04E4: bne         $at, $zero, L_800D055C
    if (ctx->r1 != 0) {
        // 0x800D04E8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D055C;
    }
    // 0x800D04E8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D04EC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D04F0: beq         $v1, $zero, L_800D0500
    if (ctx->r3 == 0) {
        // 0x800D04F4: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D0500;
    }
    // 0x800D04F4: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D04F8: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D04FC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D0500:
    // 0x800D0500: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D0504: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0508: beq         $a3, $zero, L_800D053C
    if (ctx->r7 == 0) {
        // 0x800D050C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D053C;
    }
    // 0x800D050C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D0510: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0514:
    // 0x800D0514: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D0518: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D051C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D0520: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D0524: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D0528: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D052C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D0530: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D0534: bne         $a0, $a3, L_800D0514
    if (ctx->r4 != ctx->r7) {
        // 0x800D0538: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0514;
    }
    // 0x800D0538: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D053C:
    // 0x800D053C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D0540: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0544: beq         $a3, $zero, L_800D055C
    if (ctx->r7 == 0) {
        // 0x800D0548: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D055C;
    }
    // 0x800D0548: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D054C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0550:
    // 0x800D0550: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D0554: bne         $a0, $a3, L_800D0550
    if (ctx->r4 != ctx->r7) {
        // 0x800D0558: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0550;
    }
    // 0x800D0558: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D055C:
    // 0x800D055C: blez        $a1, L_800D0574
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D0560: nop
    
            goto L_800D0574;
    }
    // 0x800D0560: nop

    // 0x800D0564: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D0568:
    // 0x800D0568: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D056C: bne         $a0, $a1, L_800D0568
    if (ctx->r4 != ctx->r5) {
        // 0x800D0570: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D0568;
    }
    // 0x800D0570: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D0574:
    // 0x800D0574: jr          $ra
    // 0x800D0578: nop

    return;
    // 0x800D0578: nop

;}
RECOMP_FUNC void open_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C55F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C55F8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C55FC: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C5600: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5604: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5608: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C560C: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5610: nop

    // 0x800C5614: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x800C5618: jr          $ra
    // 0x800C561C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C561C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void audspat_point_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800096FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009700: lw          $v0, -0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63BC);
    // 0x80009704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000970C: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
L_80009710:
    // 0x80009710: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80009714: nop

    // 0x80009718: bne         $a0, $t6, L_80009730
    if (ctx->r4 != ctx->r14) {
        // 0x8000971C: nop
    
            goto L_80009730;
    }
    // 0x8000971C: nop

    // 0x80009720: jal         0x8000A2E8
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    audspat_point_stop_by_index(rdram, ctx);
        goto after_0;
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80009728: b           L_80009740
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009740;
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009730:
    // 0x80009730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80009734: bne         $a1, $v1, L_80009710
    if (ctx->r5 != ctx->r3) {
        // 0x80009738: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80009710;
    }
    // 0x80009738: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009740:
    // 0x80009740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009744: jr          $ra
    // 0x80009748: nop

    return;
    // 0x80009748: nop

;}
RECOMP_FUNC void func_80016500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016500: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80016504: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001650C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80016510: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80016514: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80016518: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8001651C: lb          $t6, 0x1D6($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D6);
    // 0x80016520: lh          $v0, 0x1A0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A0);
    // 0x80016524: bne         $t6, $zero, L_80016554
    if (ctx->r14 != 0) {
        // 0x80016528: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016554;
    }
    // 0x80016528: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8001652C: lb          $t7, 0x1E6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1E6);
    // 0x80016530: nop

    // 0x80016534: beq         $t7, $zero, L_80016554
    if (ctx->r15 == 0) {
        // 0x80016538: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016554;
    }
    // 0x80016538: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8001653C: lw          $t8, 0x10C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10C);
    // 0x80016540: nop

    // 0x80016544: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80016548: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001654C: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80016550: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80016554:
    // 0x80016554: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80016558: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8001655C: jal         0x800707F8
    // 0x80016560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80016560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016564: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80016568: jal         0x800707C4
    // 0x8001656C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x8001656C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80016570: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80016574: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016578: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8001657C: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x80016580: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80016584: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x80016588: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001658C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016590: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80016594: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x80016598: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8001659C: nop

    // 0x800165A0: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800165A4: lwc1        $f8, 0x24($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800165A8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800165AC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800165B0: nop

    // 0x800165B4: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800165B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800165BC: beq         $t5, $at, L_80016738
    if (ctx->r13 == ctx->r1) {
        // 0x800165C0: swc1        $f18, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
            goto L_80016738;
    }
    // 0x800165C0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800165C4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800165C8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800165CC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x800165D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800165D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800165D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800165DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800165E0: nop

    // 0x800165E4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800165E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800165EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800165F0: nop

    // 0x800165F4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800165F8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800165FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80016600: bgez        $v0, L_8001660C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80016604: nop
    
            goto L_8001660C;
    }
    // 0x80016604: nop

    // 0x80016608: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8001660C:
    // 0x8001660C: addiu       $v0, $v0, 0x23
    ctx->r2 = ADD32(ctx->r2, 0X23);
    // 0x80016610: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80016614: bne         $at, $zero, L_80016620
    if (ctx->r1 != 0) {
        // 0x80016618: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_80016620;
    }
    // 0x80016618: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x8001661C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80016620:
    // 0x80016620: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016624: addiu       $a1, $s0, 0x220
    ctx->r5 = ADD32(ctx->r16, 0X220);
    // 0x80016628: bne         $v1, $zero, L_80016658
    if (ctx->r3 != 0) {
        // 0x8001662C: nop
    
            goto L_80016658;
    }
    // 0x8001662C: nop

    // 0x80016630: jal         0x80001D04
    // 0x80016634: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80016634: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x80016638: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8001663C: lw          $a1, 0x220($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X220);
    // 0x80016640: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80016644: jal         0x80001FB8
    // 0x80016648: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    sound_volume_set_relative(rdram, ctx);
        goto after_3;
    // 0x80016648: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x8001664C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016650: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016654: nop

L_80016658:
    // 0x80016658: bne         $v1, $zero, L_8001669C
    if (ctx->r3 != 0) {
        // 0x8001665C: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_8001669C;
    }
    // 0x8001665C: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x80016660: bne         $at, $zero, L_800166A0
    if (ctx->r1 != 0) {
        // 0x80016664: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_800166A0;
    }
    // 0x80016664: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x80016668: lb          $t7, 0x1D8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D8);
    // 0x8001666C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80016670: bne         $t7, $zero, L_8001668C
    if (ctx->r15 != 0) {
        // 0x80016674: nop
    
            goto L_8001668C;
    }
    // 0x80016674: nop

    // 0x80016678: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001667C: jal         0x80072348
    // 0x80016680: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x80016680: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_4:
    // 0x80016684: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016688: nop

L_8001668C:
    // 0x8001668C: lbu         $t8, 0x1F3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F3);
    // 0x80016690: nop

    // 0x80016694: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80016698: sb          $t9, 0x1F3($s0)
    MEM_B(0X1F3, ctx->r16) = ctx->r25;
L_8001669C:
    // 0x8001669C: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
L_800166A0:
    // 0x800166A0: bne         $at, $zero, L_800166B8
    if (ctx->r1 != 0) {
        // 0x800166A4: addiu       $a1, $zero, 0x1C2
        ctx->r5 = ADD32(0, 0X1C2);
            goto L_800166B8;
    }
    // 0x800166A4: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x800166A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800166AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800166B0: jal         0x800570B8
    // 0x800166B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    play_random_character_voice(rdram, ctx);
        goto after_5;
    // 0x800166B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
L_800166B8:
    // 0x800166B8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800166BC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800166C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800166C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800166C8: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800166CC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800166D0: nop

    // 0x800166D4: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800166D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800166DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800166E0: nop

    // 0x800166E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800166E8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800166EC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800166F0: bgez        $v1, L_80016700
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800166F4: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80016700;
    }
    // 0x800166F4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800166F8: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800166FC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80016700:
    // 0x80016700: bne         $at, $zero, L_8001670C
    if (ctx->r1 != 0) {
        // 0x80016704: nop
    
            goto L_8001670C;
    }
    // 0x80016704: nop

    // 0x80016708: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8001670C:
    // 0x8001670C: sb          $t1, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r9;
    // 0x80016710: jal         0x800665E8
    // 0x80016714: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_6;
    // 0x80016714: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80016718: jal         0x80069D20
    // 0x8001671C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_7;
    // 0x8001671C: nop

    after_7:
    // 0x80016720: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80016724: nop

    // 0x80016728: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8001672C: nop

    // 0x80016730: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80016734: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
L_80016738:
    // 0x80016738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001673C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016740: jr          $ra
    // 0x80016744: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80016744: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_wave_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AD0C: lb          $v0, -0x2CF8($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2CF8);
    // 0x8002AD10: beq         $a2, $zero, L_8002AD30
    if (ctx->r6 == 0) {
        // 0x8002AD14: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002AD30;
    }
    // 0x8002AD14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AD18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002AD1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002AD20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002AD24: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD28: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD2C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002AD30:
    // 0x8002AD30: blez        $v0, L_8002AE44
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AD34: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002AE44;
    }
    // 0x8002AD34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002AD38: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8002AD3C: beq         $t1, $zero, L_8002AD8C
    if (ctx->r9 == 0) {
        // 0x8002AD40: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8002AD8C;
    }
    // 0x8002AD40: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8002AD44: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AD48: addiu       $t7, $t7, -0x2D48
    ctx->r15 = ADD32(ctx->r15, -0X2D48);
    // 0x8002AD4C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002AD50: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AD54: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AD58: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
L_8002AD5C:
    // 0x8002AD5C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8002AD60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002AD64: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002AD68: nop

    // 0x8002AD6C: beq         $t3, $t2, L_8002AD7C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AD70: nop
    
            goto L_8002AD7C;
    }
    // 0x8002AD70: nop

    // 0x8002AD74: bne         $t4, $t2, L_8002AD80
    if (ctx->r12 != ctx->r10) {
        // 0x8002AD78: nop
    
            goto L_8002AD80;
    }
    // 0x8002AD78: nop

L_8002AD7C:
    // 0x8002AD7C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AD80:
    // 0x8002AD80: bne         $a3, $v1, L_8002AD5C
    if (ctx->r7 != ctx->r3) {
        // 0x8002AD84: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8002AD5C;
    }
    // 0x8002AD84: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8002AD88: beq         $v1, $v0, L_8002AE44
    if (ctx->r3 == ctx->r2) {
        // 0x8002AD8C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AE44;
    }
L_8002AD8C:
    // 0x8002AD8C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002AD90: addiu       $t5, $t5, -0x2D48
    ctx->r13 = ADD32(ctx->r13, -0X2D48);
    // 0x8002AD94: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002AD98: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8002AD9C: addu        $t0, $t6, $t5
    ctx->r8 = ADD32(ctx->r14, ctx->r13);
    // 0x8002ADA0: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8002ADA4: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002ADA8: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
L_8002ADAC:
    // 0x8002ADAC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8002ADB0: nop

    // 0x8002ADB4: lb          $t2, 0x10($t7)
    ctx->r10 = MEM_B(ctx->r15, 0X10);
    // 0x8002ADB8: nop

    // 0x8002ADBC: beq         $t3, $t2, L_8002ADCC
    if (ctx->r11 == ctx->r10) {
        // 0x8002ADC0: nop
    
            goto L_8002ADCC;
    }
    // 0x8002ADC0: nop

    // 0x8002ADC4: bne         $t4, $t2, L_8002ADD0
    if (ctx->r12 != ctx->r10) {
        // 0x8002ADC8: nop
    
            goto L_8002ADD0;
    }
    // 0x8002ADC8: nop

L_8002ADCC:
    // 0x8002ADCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002ADD0:
    // 0x8002ADD0: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8002ADD4: nop

    // 0x8002ADD8: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002ADDC: nop

    // 0x8002ADE0: beq         $t3, $t2, L_8002ADF0
    if (ctx->r11 == ctx->r10) {
        // 0x8002ADE4: nop
    
            goto L_8002ADF0;
    }
    // 0x8002ADE4: nop

    // 0x8002ADE8: bne         $t4, $t2, L_8002ADF4
    if (ctx->r12 != ctx->r10) {
        // 0x8002ADEC: nop
    
            goto L_8002ADF4;
    }
    // 0x8002ADEC: nop

L_8002ADF0:
    // 0x8002ADF0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002ADF4:
    // 0x8002ADF4: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002ADF8: nop

    // 0x8002ADFC: lb          $v1, 0x10($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X10);
    // 0x8002AE00: nop

    // 0x8002AE04: beq         $t3, $v1, L_8002AE14
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE08: nop
    
            goto L_8002AE14;
    }
    // 0x8002AE08: nop

    // 0x8002AE0C: bne         $t4, $v1, L_8002AE18
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE10: nop
    
            goto L_8002AE18;
    }
    // 0x8002AE10: nop

L_8002AE14:
    // 0x8002AE14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE18:
    // 0x8002AE18: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8002AE1C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8002AE20: lb          $v1, 0x10($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X10);
    // 0x8002AE24: nop

    // 0x8002AE28: beq         $t3, $v1, L_8002AE38
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE2C: nop
    
            goto L_8002AE38;
    }
    // 0x8002AE2C: nop

    // 0x8002AE30: bne         $t4, $v1, L_8002AE3C
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE34: nop
    
            goto L_8002AE3C;
    }
    // 0x8002AE34: nop

L_8002AE38:
    // 0x8002AE38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE3C:
    // 0x8002AE3C: bne         $t0, $a3, L_8002ADAC
    if (ctx->r8 != ctx->r7) {
        // 0x8002AE40: nop
    
            goto L_8002ADAC;
    }
    // 0x8002AE40: nop

L_8002AE44:
    // 0x8002AE44: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002AE48: bne         $a0, $zero, L_8002AE58
    if (ctx->r4 != 0) {
        // 0x8002AE4C: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_8002AE58;
    }
    // 0x8002AE4C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AE50: jr          $ra
    // 0x8002AE54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002AE54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AE58:
    // 0x8002AE58: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8002AE5C: blez        $v0, L_8002B070
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AE60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002B070;
    }
    // 0x8002AE60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AE64: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8002AE68: beq         $t0, $zero, L_8002AEF4
    if (ctx->r8 == 0) {
        // 0x8002AE6C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AEF4;
    }
    // 0x8002AE6C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002AE70: lw          $t5, -0x2D48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D48);
    // 0x8002AE74: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AE78: lb          $v1, 0x10($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X10);
    // 0x8002AE7C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AE80: beq         $t3, $v1, L_8002AE90
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE84: nop
    
            goto L_8002AE90;
    }
    // 0x8002AE84: nop

    // 0x8002AE88: bne         $t4, $v1, L_8002AEF0
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE8C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AEF0;
    }
    // 0x8002AE8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AE90:
    // 0x8002AE90: lw          $t7, -0x2D48($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D48);
    // 0x8002AE94: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AE98: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002AE9C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AEA0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AEA4: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x8002AEA8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AEAC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AEB0: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8002AEB4: nop

    // 0x8002AEB8: bc1f        L_8002AEF0
    if (!c1cs) {
        // 0x8002AEBC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AEF0;
    }
    // 0x8002AEBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002AEC0: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002AEC4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AEC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AECC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AED0: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8002AED4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AED8: bc1t        L_8002AEE8
    if (c1cs) {
        // 0x8002AEDC: nop
    
            goto L_8002AEE8;
    }
    // 0x8002AEDC: nop

    // 0x8002AEE0: bne         $a0, $at, L_8002AEF0
    if (ctx->r4 != ctx->r1) {
        // 0x8002AEE4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AEF0;
    }
    // 0x8002AEE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AEE8:
    // 0x8002AEE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002AEEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AEF0:
    // 0x8002AEF0: beq         $v1, $v0, L_8002B070
    if (ctx->r3 == ctx->r2) {
        // 0x8002AEF4: lui         $at, 0x4039
        ctx->r1 = S32(0X4039 << 16);
            goto L_8002B070;
    }
L_8002AEF4:
    // 0x8002AEF4: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AEF8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AEFC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8002AF00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002AF04: addiu       $t9, $t9, -0x2D48
    ctx->r25 = ADD32(ctx->r25, -0X2D48);
    // 0x8002AF08: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8002AF0C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002AF10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AF14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002AF18: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8002AF1C:
    // 0x8002AF1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002AF20: nop

    // 0x8002AF24: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002AF28: nop

    // 0x8002AF2C: beq         $t3, $t2, L_8002AF3C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AF30: nop
    
            goto L_8002AF3C;
    }
    // 0x8002AF30: nop

    // 0x8002AF34: bne         $t4, $t2, L_8002AF90
    if (ctx->r12 != ctx->r10) {
        // 0x8002AF38: nop
    
            goto L_8002AF90;
    }
    // 0x8002AF38: nop

L_8002AF3C:
    // 0x8002AF3C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AF40: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AF44: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AF48: add.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f16.d + ctx->f2.d;
    // 0x8002AF4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AF50: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8002AF54: nop

    // 0x8002AF58: bc1f        L_8002AFC4
    if (!c1cs) {
        // 0x8002AF5C: nop
    
            goto L_8002AFC4;
    }
    // 0x8002AF5C: nop

    // 0x8002AF60: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002AF64: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AF68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AF6C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AF70: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8002AF74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AF78: bc1t        L_8002AF88
    if (c1cs) {
        // 0x8002AF7C: nop
    
            goto L_8002AF88;
    }
    // 0x8002AF7C: nop

    // 0x8002AF80: bne         $a0, $at, L_8002AFC4
    if (ctx->r4 != ctx->r1) {
        // 0x8002AF84: nop
    
            goto L_8002AFC4;
    }
    // 0x8002AF84: nop

L_8002AF88:
    // 0x8002AF88: b           L_8002AFC4
    // 0x8002AF8C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8002AFC4;
    // 0x8002AF8C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8002AF90:
    // 0x8002AF90: bltz        $a3, L_8002AFC4
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002AF94: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002AFC4;
    }
    // 0x8002AF94: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002AF98: bne         $at, $zero, L_8002AFC4
    if (ctx->r1 != 0) {
        // 0x8002AF9C: nop
    
            goto L_8002AFC4;
    }
    // 0x8002AF9C: nop

    // 0x8002AFA0: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AFA4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AFA8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AFAC: sub.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f4.d - ctx->f14.d;
    // 0x8002AFB0: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8002AFB4: nop

    // 0x8002AFB8: bc1f        L_8002AFC4
    if (!c1cs) {
        // 0x8002AFBC: nop
    
            goto L_8002AFC4;
    }
    // 0x8002AFBC: nop

    // 0x8002AFC0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002AFC4:
    // 0x8002AFC4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8002AFC8: nop

    // 0x8002AFCC: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002AFD0: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AFD4: beq         $t3, $t2, L_8002AFE4
    if (ctx->r11 == ctx->r10) {
        // 0x8002AFD8: nop
    
            goto L_8002AFE4;
    }
    // 0x8002AFD8: nop

    // 0x8002AFDC: bne         $t4, $t2, L_8002B034
    if (ctx->r12 != ctx->r10) {
        // 0x8002AFE0: nop
    
            goto L_8002B034;
    }
    // 0x8002AFE0: nop

L_8002AFE4:
    // 0x8002AFE4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002AFE8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8002AFEC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AFF0: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AFF4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8002AFF8: nop

    // 0x8002AFFC: bc1f        L_8002B064
    if (!c1cs) {
        // 0x8002B000: nop
    
            goto L_8002B064;
    }
    // 0x8002B000: nop

    // 0x8002B004: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002B008: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002B00C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B010: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002B014: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002B018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B01C: bc1t        L_8002B02C
    if (c1cs) {
        // 0x8002B020: nop
    
            goto L_8002B02C;
    }
    // 0x8002B020: nop

    // 0x8002B024: bne         $a0, $at, L_8002B064
    if (ctx->r4 != ctx->r1) {
        // 0x8002B028: nop
    
            goto L_8002B064;
    }
    // 0x8002B028: nop

L_8002B02C:
    // 0x8002B02C: b           L_8002B064
    // 0x8002B030: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
        goto L_8002B064;
    // 0x8002B030: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
L_8002B034:
    // 0x8002B034: bltz        $a3, L_8002B064
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002B038: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002B064;
    }
    // 0x8002B038: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002B03C: bne         $at, $zero, L_8002B064
    if (ctx->r1 != 0) {
        // 0x8002B040: nop
    
            goto L_8002B064;
    }
    // 0x8002B040: nop

    // 0x8002B044: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B048: sub.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f18.d - ctx->f14.d;
    // 0x8002B04C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002B050: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002B054: nop

    // 0x8002B058: bc1f        L_8002B064
    if (!c1cs) {
        // 0x8002B05C: nop
    
            goto L_8002B064;
    }
    // 0x8002B05C: nop

    // 0x8002B060: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002B064:
    // 0x8002B064: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8002B068: bne         $v1, $v0, L_8002AF1C
    if (ctx->r3 != ctx->r2) {
        // 0x8002B06C: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8002AF1C;
    }
    // 0x8002B06C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_8002B070:
    // 0x8002B070: bgez        $a3, L_8002B080
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002B074: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_8002B080;
    }
    // 0x8002B074: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B078: jr          $ra
    // 0x8002B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B080:
    // 0x8002B080: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002B084: addiu       $t5, $t5, -0x2D48
    ctx->r13 = ADD32(ctx->r13, -0X2D48);
    // 0x8002B088: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x8002B08C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002B090: nop

    // 0x8002B094: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002B098: beq         $a2, $zero, L_8002B0DC
    if (ctx->r6 == 0) {
        // 0x8002B09C: swc1        $f16, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
            goto L_8002B0DC;
    }
    // 0x8002B09C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8002B0A0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0A4: nop

    // 0x8002B0A8: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002B0AC: nop

    // 0x8002B0B0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8002B0B4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0B8: nop

    // 0x8002B0BC: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002B0C0: nop

    // 0x8002B0C4: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8002B0C8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0CC: nop

    // 0x8002B0D0: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8002B0D4: nop

    // 0x8002B0D8: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
L_8002B0DC:
    // 0x8002B0DC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0E0: nop

    // 0x8002B0E4: lb          $v0, 0x10($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X10);
    // 0x8002B0E8: nop

    // 0x8002B0EC: jr          $ra
    // 0x8002B0F0: nop

    return;
    // 0x8002B0F0: nop

;}
RECOMP_FUNC void obj_init_silvercoin_adv2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DBA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DBA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DBAC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBB0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DBB4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DBB8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBBC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DBC0: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DBC4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBC8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DBCC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DBD0: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003DBD4: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DBD8: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8003DBDC: jal         0x8009C2D0
    // 0x8003DBE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DBE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DBE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DBE8: bne         $v0, $zero, L_8003DC28
    if (ctx->r2 != 0) {
        // 0x8003DBEC: nop
    
            goto L_8003DC28;
    }
    // 0x8003DBEC: nop

    // 0x8003DBF0: jal         0x8000E1DC
    // 0x8003DBF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DBF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DBF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DBFC: beq         $v0, $zero, L_8003DC24
    if (ctx->r2 == 0) {
        // 0x8003DC00: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC24;
    }
    // 0x8003DC00: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC04: jal         0x8009EC70
    // 0x8003DC08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DC08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DC0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC10: beq         $v0, $zero, L_8003DC24
    if (ctx->r2 == 0) {
        // 0x8003DC14: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC24;
    }
    // 0x8003DC14: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC18: b           L_8003DC28
    // 0x8003DC1C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DC28;
    // 0x8003DC1C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DC20: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8003DC24:
    // 0x8003DC24: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
L_8003DC28:
    // 0x8003DC28: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8003DC2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DC30: bne         $t4, $at, L_8003DC50
    if (ctx->r12 != ctx->r1) {
        // 0x8003DC34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DC50;
    }
    // 0x8003DC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DC38: lh          $t5, 0x6($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X6);
    // 0x8003DC3C: nop

    // 0x8003DC40: ori         $t6, $t5, 0x600
    ctx->r14 = ctx->r13 | 0X600;
    // 0x8003DC44: jal         0x8000FFB8
    // 0x8003DC48: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DC48: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    after_3:
    // 0x8003DC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DC50:
    // 0x8003DC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DC54: jr          $ra
    // 0x8003DC58: nop

    return;
    // 0x8003DC58: nop

;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE19C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE1A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CE1A4: beq         $t6, $zero, L_800CE1BC
    if (ctx->r14 == 0) {
        // 0x800CE1A8: nop
    
            goto L_800CE1BC;
    }
    // 0x800CE1A8: nop

    // 0x800CE1AC: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_800CE1B0:
    // 0x800CE1B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE1B4: bnel        $t7, $zero, L_800CE1B0
    if (ctx->r15 != 0) {
        // 0x800CE1B8: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_800CE1B0;
    }
    goto skip_0;
    // 0x800CE1B8: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_800CE1BC:
    // 0x800CE1BC: jr          $ra
    // 0x800CE1C0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x800CE1C0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void get_current_viewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066220: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066224: lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XCE4);
    // 0x80066228: jr          $ra
    // 0x8006622C: nop

    return;
    // 0x8006622C: nop

;}
RECOMP_FUNC void find_next_subtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2D6C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C2D70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2D74: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C2D78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C2D7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C2D80: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C2D84: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C2D88: addiu       $s1, $s1, -0x5830
    ctx->r17 = ADD32(ctx->r17, -0X5830);
    // 0x800C2D8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C2D90: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2D94: addiu       $s4, $s4, -0x5854
    ctx->r20 = ADD32(ctx->r20, -0X5854);
    // 0x800C2D98: addiu       $s3, $s3, -0x5848
    ctx->r19 = ADD32(ctx->r19, -0X5848);
    // 0x800C2D9C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C2DA0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C2DA4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C2DA8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C2DAC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C2DB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C2DB4: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x800C2DB8: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800C2DBC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2DC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C2DC4: beq         $v0, $zero, L_800C2ED8
    if (ctx->r2 == 0) {
        // 0x800C2DC8: addiu       $fp, $zero, 0xA
        ctx->r30 = ADD32(0, 0XA);
            goto L_800C2ED8;
    }
    // 0x800C2DC8: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800C2DCC: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C2DD0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C2DD4: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C2DD8: addiu       $s5, $s5, -0x5846
    ctx->r21 = ADD32(ctx->r21, -0X5846);
    // 0x800C2DDC: addiu       $s6, $s6, -0x5840
    ctx->r22 = ADD32(ctx->r22, -0X5840);
    // 0x800C2DE0: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x800C2DE4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C2DE8:
    // 0x800C2DE8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C2DEC: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800C2DF0: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x800C2DF4: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x800C2DF8: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800C2DFC: nop

    // 0x800C2E00: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2E04: mflo        $a0
    ctx->r4 = lo;
    // 0x800C2E08: jal         0x8000C8B4
    // 0x800C2E0C: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800C2E0C: nop

    after_0:
    // 0x800C2E10: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800C2E14: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x800C2E18: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800C2E1C: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C2E20: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2E24: nop

    // 0x800C2E28: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
L_800C2E2C:
    // 0x800C2E2C: beq         $t2, $zero, L_800C2E40
    if (ctx->r10 == 0) {
        // 0x800C2E30: addiu       $t4, $s0, 0x1
        ctx->r12 = ADD32(ctx->r16, 0X1);
            goto L_800C2E40;
    }
    // 0x800C2E30: addiu       $t4, $s0, 0x1
    ctx->r12 = ADD32(ctx->r16, 0X1);
    // 0x800C2E34: addiu       $t3, $s0, 0x2
    ctx->r11 = ADD32(ctx->r16, 0X2);
    // 0x800C2E38: b           L_800C2E44
    // 0x800C2E3C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_800C2E44;
    // 0x800C2E3C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_800C2E40:
    // 0x800C2E40: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_800C2E44:
    // 0x800C2E44: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C2E48: nop

    // 0x800C2E4C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2E50: nop

    // 0x800C2E54: bne         $v1, $zero, L_800C2E2C
    if (ctx->r3 != 0) {
        // 0x800C2E58: andi        $t2, $v1, 0x80
        ctx->r10 = ctx->r3 & 0X80;
            goto L_800C2E2C;
    }
    // 0x800C2E58: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
    // 0x800C2E5C: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x800C2E60: addiu       $t7, $s0, 0x1
    ctx->r15 = ADD32(ctx->r16, 0X1);
    // 0x800C2E64: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C2E68: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
    // 0x800C2E6C: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C2E70: nop

    // 0x800C2E74: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800C2E78: bne         $at, $zero, L_800C2E84
    if (ctx->r1 != 0) {
        // 0x800C2E7C: nop
    
            goto L_800C2E84;
    }
    // 0x800C2E7C: nop

    // 0x800C2E80: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C2E84:
    // 0x800C2E84: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C2E88: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C2E8C: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C2E90: bne         $fp, $v0, L_800C2EAC
    if (ctx->r30 != ctx->r2) {
        // 0x800C2E94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C2EAC;
    }
    // 0x800C2E94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C2E98: addiu       $s0, $t7, 0x1
    ctx->r16 = ADD32(ctx->r15, 0X1);
    // 0x800C2E9C: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C2EA0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2EA4: b           L_800C2EC8
    // 0x800C2EA8: nop

        goto L_800C2EC8;
    // 0x800C2EA8: nop

L_800C2EAC:
    // 0x800C2EAC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800C2EB0: bne         $v1, $at, L_800C2EC8
    if (ctx->r3 != ctx->r1) {
        // 0x800C2EB4: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_800C2EC8;
    }
    // 0x800C2EB4: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x800C2EB8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C2EBC: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800C2EC0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C2EC4: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800C2EC8:
    // 0x800C2EC8: beq         $v0, $zero, L_800C2ED8
    if (ctx->r2 == 0) {
        // 0x800C2ECC: nop
    
            goto L_800C2ED8;
    }
    // 0x800C2ECC: nop

    // 0x800C2ED0: beq         $s2, $zero, L_800C2DE8
    if (ctx->r18 == 0) {
        // 0x800C2ED4: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C2DE8;
    }
    // 0x800C2ED4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C2ED8:
    // 0x800C2ED8: lh          $t0, 0x0($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X0);
    // 0x800C2EDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C2EE0: blez        $t0, L_800C2EEC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800C2EE4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C2EEC;
    }
    // 0x800C2EE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2EE8: sh          $t1, -0x584A($at)
    MEM_H(-0X584A, ctx->r1) = ctx->r9;
L_800C2EEC:
    // 0x800C2EEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2EF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2EF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C2EFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C2F00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C2F04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2F08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C2F0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C2F10: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C2F14: jr          $ra
    // 0x800C2F18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C2F18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void level_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_runtime_scene_reset(uint8_t*, recomp_context*); extern void dkr_presentation_scene_begin(uint8_t*, recomp_context*); dkr_runtime_scene_reset(rdram, ctx); dkr_presentation_scene_begin(rdram, ctx); extern void dkr_legacy_scene_begin(uint8_t*, recomp_context*); dkr_legacy_scene_begin(rdram, ctx);
    // 0x8006B250: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006B254: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006B258: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8006B25C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8006B260: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006B264: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8006B268: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006B26C: jal         0x80072708
    // 0x8006B270: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x8006B270: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006B274: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8006B278: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B27C: bne         $t6, $v0, L_8006B28C
    if (ctx->r14 != ctx->r2) {
        // 0x8006B280: lw          $t7, 0x64($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X64);
            goto L_8006B28C;
    }
    // 0x8006B280: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006B284: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B288: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
L_8006B28C:
    // 0x8006B28C: nop

    // 0x8006B290: bne         $t7, $v0, L_8006B2A4
    if (ctx->r15 != ctx->r2) {
        // 0x8006B294: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006B2A4;
    }
    // 0x8006B294: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B298: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8006B29C: b           L_8006B2A8
    // 0x8006B2A0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
        goto L_8006B2A8;
    // 0x8006B2A0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
L_8006B2A4:
    // 0x8006B2A4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_8006B2A8:
    // 0x8006B2A8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8006B2AC: nop

    // 0x8006B2B0: bne         $t9, $zero, L_8006B2CC
    if (ctx->r25 != 0) {
        // 0x8006B2B4: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B2CC;
    }
    // 0x8006B2B4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006B2B8: jal         0x8000318C
    // 0x8006B2BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_1;
    // 0x8006B2BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8006B2C0: b           L_8006B2F0
    // 0x8006B2C4: nop

        goto L_8006B2F0;
    // 0x8006B2C4: nop

    // 0x8006B2C8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_8006B2CC:
    // 0x8006B2CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B2D0: bne         $t2, $at, L_8006B2E8
    if (ctx->r10 != ctx->r1) {
        // 0x8006B2D4: nop
    
            goto L_8006B2E8;
    }
    // 0x8006B2D4: nop

    // 0x8006B2D8: jal         0x8000318C
    // 0x8006B2DC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_2;
    // 0x8006B2DC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_2:
    // 0x8006B2E0: b           L_8006B2F0
    // 0x8006B2E4: nop

        goto L_8006B2F0;
    // 0x8006B2E4: nop

L_8006B2E8:
    // 0x8006B2E8: jal         0x8000318C
    // 0x8006B2EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_3;
    // 0x8006B2EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
L_8006B2F0:
    // 0x8006B2F0: jal         0x8006EA90
    // 0x8006B2F4: nop

    get_settings(rdram, ctx);
        goto after_4;
    // 0x8006B2F4: nop

    after_4:
    // 0x8006B2F8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8006B2FC: jal         0x80076C58
    // 0x8006B300: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_5;
    // 0x8006B300: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_5:
    // 0x8006B304: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006B308: addiu       $t1, $t1, 0x1160
    ctx->r9 = ADD32(ctx->r9, 0X1160);
    // 0x8006B30C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8006B310: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8006B314: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8006B318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B31C: beq         $t0, $t3, L_8006B334
    if (ctx->r8 == ctx->r11) {
        // 0x8006B320: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006B334;
    }
    // 0x8006B320: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006B324:
    // 0x8006B324: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8006B328: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B32C: bne         $t0, $t4, L_8006B324
    if (ctx->r8 != ctx->r12) {
        // 0x8006B330: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006B324;
    }
    // 0x8006B330: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006B334:
    // 0x8006B334: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8006B338: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006B33C: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006B340: bne         $at, $zero, L_8006B34C
    if (ctx->r1 != 0) {
        // 0x8006B344: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006B34C;
    }
    // 0x8006B344: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B348: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8006B34C:
    // 0x8006B34C: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8006B350: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B354: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8006B358: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006B35C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B360: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8006B364: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8006B368: subu        $a0, $t7, $s0
    ctx->r4 = SUB32(ctx->r15, ctx->r16);
    // 0x8006B36C: jal         0x80070C9C
    // 0x8006B370: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8006B370: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_6:
    // 0x8006B374: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006B378: addiu       $s1, $s1, 0x1168
    ctx->r17 = ADD32(ctx->r17, 0X1168);
    // 0x8006B37C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B380: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B384: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B388: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B38C: jal         0x80076E68
    // 0x8006B390: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8006B390: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8006B394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B398: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B39C: sb          $zero, -0x2CD0($at)
    MEM_B(-0X2CD0, ctx->r1) = 0;
    // 0x8006B3A0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B3A4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8006B3A8: lb          $t2, 0x4C($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X4C);
    // 0x8006B3AC: nop

    // 0x8006B3B0: bne         $t2, $zero, L_8006B3C0
    if (ctx->r10 != 0) {
        // 0x8006B3B4: nop
    
            goto L_8006B3C0;
    }
    // 0x8006B3B4: nop

    // 0x8006B3B8: jal         0x8006C2E4
    // 0x8006B3BC: nop

    level_properties_reset(rdram, ctx);
        goto after_8;
    // 0x8006B3BC: nop

    after_8:
L_8006B3C0:
    // 0x8006B3C0: jal         0x8006C2F0
    // 0x8006B3C4: nop

    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8006B3C4: nop

    after_9:
    // 0x8006B3C8: bne         $v0, $zero, L_8006B630
    if (ctx->r2 != 0) {
        // 0x8006B3CC: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8006B630;
    }
    // 0x8006B3CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006B3D0: lh          $t3, -0x2CD4($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2CD4);
    // 0x8006B3D4: nop

    // 0x8006B3D8: bne         $t3, $zero, L_8006B634
    if (ctx->r11 != 0) {
        // 0x8006B3DC: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B634;
    }
    // 0x8006B3DC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B3E0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B3E4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B3E8: lb          $t4, 0x4C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B3EC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B3F0: bne         $t4, $at, L_8006B4EC
    if (ctx->r12 != ctx->r1) {
        // 0x8006B3F4: nop
    
            goto L_8006B4EC;
    }
    // 0x8006B3F4: nop

    // 0x8006B3F8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8006B3FC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006B400: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B404: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006B408: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8006B40C: beq         $a0, $zero, L_8006B420
    if (ctx->r4 == 0) {
        // 0x8006B410: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006B420;
    }
    // 0x8006B410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B414: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B418: bne         $a0, $at, L_8006B428
    if (ctx->r4 != ctx->r1) {
        // 0x8006B41C: andi        $v1, $s0, 0x1
        ctx->r3 = ctx->r16 & 0X1;
            goto L_8006B428;
    }
    // 0x8006B41C: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B420:
    // 0x8006B420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B424: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B428:
    // 0x8006B428: beq         $v1, $zero, L_8006B43C
    if (ctx->r3 == 0) {
        // 0x8006B42C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_8006B43C;
    }
    // 0x8006B42C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B430: beq         $v0, $zero, L_8006B4EC
    if (ctx->r2 == 0) {
        // 0x8006B434: nop
    
            goto L_8006B4EC;
    }
    // 0x8006B434: nop

    // 0x8006B438: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_8006B43C:
    // 0x8006B43C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B440: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B444: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B448: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006B44C: jal         0x8006C1AC
    // 0x8006B450: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    level_properties_push(rdram, ctx);
        goto after_10;
    // 0x8006B450: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_10:
    // 0x8006B454: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006B458: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006B45C: lbu         $t2, 0x48($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X48);
    // 0x8006B460: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x8006B464: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8006B468: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B46C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B470: and         $t5, $t9, $t4
    ctx->r13 = ctx->r25 & ctx->r12;
    // 0x8006B474: beq         $t5, $zero, L_8006B488
    if (ctx->r13 == 0) {
        // 0x8006B478: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8006B488;
    }
    // 0x8006B478: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006B47C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8006B480: b           L_8006B48C
    // 0x8006B484: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_8006B48C;
    // 0x8006B484: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006B488:
    // 0x8006B488: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006B48C:
    // 0x8006B48C: beq         $v0, $zero, L_8006B4A8
    if (ctx->r2 == 0) {
        // 0x8006B490: nop
    
            goto L_8006B4A8;
    }
    // 0x8006B490: nop

    // 0x8006B494: beq         $v1, $zero, L_8006B4A8
    if (ctx->r3 == 0) {
        // 0x8006B498: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_8006B4A8;
    }
    // 0x8006B498: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B49C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006B4A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B4A4: sb          $t8, -0x2CD0($at)
    MEM_B(-0X2CD0, ctx->r1) = ctx->r24;
L_8006B4A8:
    // 0x8006B4A8: jal         0x8001E29C
    // 0x8006B4AC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x8006B4AC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_11:
    // 0x8006B4B0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8006B4B4: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8006B4B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006B4BC: beq         $a1, $t3, L_8006B4D8
    if (ctx->r5 == ctx->r11) {
        // 0x8006B4C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006B4D8;
    }
    // 0x8006B4C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006B4C4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8006B4C8:
    // 0x8006B4C8: lb          $t2, 0x2($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X2);
    // 0x8006B4CC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006B4D0: bne         $a1, $t2, L_8006B4C8
    if (ctx->r5 != ctx->r10) {
        // 0x8006B4D4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8006B4C8;
    }
    // 0x8006B4D4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8006B4D8:
    // 0x8006B4D8: addu        $t9, $s0, $v0
    ctx->r25 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B4DC: lb          $t4, 0x1($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X1);
    // 0x8006B4E0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8006B4E4: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B4E8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
L_8006B4EC:
    // 0x8006B4EC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B4F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B4F4: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B4F8: nop

    // 0x8006B4FC: bne         $a1, $at, L_8006B5B0
    if (ctx->r5 != ctx->r1) {
        // 0x8006B500: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B5B0;
    }
    // 0x8006B500: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B504: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B508: nop

    // 0x8006B50C: blez        $a0, L_8006B5AC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B510: slti        $at, $a0, 0x5
        ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
            goto L_8006B5AC;
    }
    // 0x8006B510: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8006B514: beq         $at, $zero, L_8006B5B0
    if (ctx->r1 == 0) {
        // 0x8006B518: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B5B0;
    }
    // 0x8006B518: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B51C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8006B520: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B524: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x8006B528: sllv        $t3, $t8, $a0
    ctx->r11 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x8006B52C: and         $t2, $t7, $t3
    ctx->r10 = ctx->r15 & ctx->r11;
    // 0x8006B530: beq         $t2, $zero, L_8006B5AC
    if (ctx->r10 == 0) {
        // 0x8006B534: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8006B5AC;
    }
    // 0x8006B534: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006B538: lw          $t5, 0x10($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X10);
    // 0x8006B53C: addiu       $t9, $a0, 0x1F
    ctx->r25 = ADD32(ctx->r4, 0X1F);
    // 0x8006B540: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x8006B544: sllv        $v0, $t4, $t9
    ctx->r2 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8006B548: and         $t8, $t5, $v0
    ctx->r24 = ctx->r13 & ctx->r2;
    // 0x8006B54C: bne         $t8, $zero, L_8006B5B0
    if (ctx->r24 != 0) {
        // 0x8006B550: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B5B0;
    }
    // 0x8006B550: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B554: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B558: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B55C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B560: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B564: jal         0x8006C1AC
    // 0x8006B568: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8006B568: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_12:
    // 0x8006B56C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006B570: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006B574: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8006B578: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B57C: or          $t3, $t7, $v0
    ctx->r11 = ctx->r15 | ctx->r2;
    // 0x8006B580: jal         0x8001E29C
    // 0x8006B584: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8006B584: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    after_13:
    // 0x8006B588: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B58C: lb          $t4, -0x1($t2)
    ctx->r12 = MEM_B(ctx->r10, -0X1);
    // 0x8006B590: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B594: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006B598: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8006B59C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8006B5A0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B5A4: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B5A8: nop

L_8006B5AC:
    // 0x8006B5AC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8006B5B0:
    // 0x8006B5B0: bne         $a1, $at, L_8006B634
    if (ctx->r5 != ctx->r1) {
        // 0x8006B5B4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B634;
    }
    // 0x8006B5B4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B5B8: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8006B5BC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B5C0: bne         $t6, $zero, L_8006B634
    if (ctx->r14 != 0) {
        // 0x8006B5C4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B634;
    }
    // 0x8006B5C4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B5C8: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x8006B5CC: nop

    // 0x8006B5D0: andi        $t7, $t8, 0x2000
    ctx->r15 = ctx->r24 & 0X2000;
    // 0x8006B5D4: bne         $t7, $zero, L_8006B634
    if (ctx->r15 != 0) {
        // 0x8006B5D8: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B634;
    }
    // 0x8006B5D8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B5DC: lbu         $t3, 0x17($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X17);
    // 0x8006B5E0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B5E4: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8006B5E8: bne         $at, $zero, L_8006B634
    if (ctx->r1 != 0) {
        // 0x8006B5EC: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B634;
    }
    // 0x8006B5EC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B5F0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B5F4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B5F8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B5FC: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B600: jal         0x8006C1AC
    // 0x8006B604: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8006B604: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    after_14:
    // 0x8006B608: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006B60C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B610: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8006B614: nop

    // 0x8006B618: ori         $t4, $t2, 0x2000
    ctx->r12 = ctx->r10 | 0X2000;
    // 0x8006B61C: jal         0x8001E29C
    // 0x8006B620: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8006B620: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    after_15:
    // 0x8006B624: lb          $t9, 0x4($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4);
    // 0x8006B628: nop

    // 0x8006B62C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8006B630:
    // 0x8006B630: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8006B634:
    // 0x8006B634: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B638: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B63C: beq         $t6, $t8, L_8006B698
    if (ctx->r14 == ctx->r24) {
        // 0x8006B640: sh          $zero, -0x2CD4($at)
        MEM_H(-0X2CD4, ctx->r1) = 0;
            goto L_8006B698;
    }
    // 0x8006B640: sh          $zero, -0x2CD4($at)
    MEM_H(-0X2CD4, ctx->r1) = 0;
    // 0x8006B644: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B648: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006B64C: jal         0x80071140
    // 0x8006B650: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8006B650: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_16:
    // 0x8006B654: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006B658: lw          $t5, 0x1160($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1160);
    // 0x8006B65C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8006B660: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B664: addu        $v0, $t5, $t3
    ctx->r2 = ADD32(ctx->r13, ctx->r11);
    // 0x8006B668: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B66C: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8006B670: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B674: subu        $a0, $t2, $s0
    ctx->r4 = SUB32(ctx->r10, ctx->r16);
    // 0x8006B678: jal         0x80070C9C
    // 0x8006B67C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8006B67C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_17:
    // 0x8006B680: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B684: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B688: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B68C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B690: jal         0x80076E68
    // 0x8006B694: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_18;
    // 0x8006B694: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
L_8006B698:
    // 0x8006B698: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006B69C: lw          $a0, 0x1160($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1160);
    // 0x8006B6A0: jal         0x80071140
    // 0x8006B6A4: nop

    mempool_free(rdram, ctx);
        goto after_19;
    // 0x8006B6A4: nop

    after_19:
    // 0x8006B6A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B6AC: jal         0x8006BFC8
    // 0x8006B6B0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    aitable_init(rdram, ctx);
        goto after_20;
    // 0x8006B6B0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_20:
    // 0x8006B6B4: jal         0x8000CBC0
    // 0x8006B6B8: nop

    func_8000CBC0(rdram, ctx);
        goto after_21;
    // 0x8006B6B8: nop

    after_21:
    // 0x8006B6BC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006B6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B6C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B6C8: sw          $t4, 0x1164($at)
    MEM_W(0X1164, ctx->r1) = ctx->r12;
L_8006B6CC:
    // 0x8006B6CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B6D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B6D4: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006B6D8: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8006B6DC: nop

    // 0x8006B6E0: beq         $a0, $at, L_8006B724
    if (ctx->r4 == ctx->r1) {
        // 0x8006B6E4: nop
    
            goto L_8006B724;
    }
    // 0x8006B6E4: nop

    // 0x8006B6E8: jal         0x8001E29C
    // 0x8006B6EC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_22;
    // 0x8006B6EC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_22:
    // 0x8006B6F0: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B6F4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006B6F8: nop

    // 0x8006B6FC: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B700: sw          $v0, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->r2;
    // 0x8006B704: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006B708: nop

    // 0x8006B70C: addu        $t3, $t5, $v1
    ctx->r11 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B710: lw          $a0, 0x74($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X74);
    // 0x8006B714: jal         0x8007F1E8
    // 0x8006B718: nop

    func_8007F1E8(rdram, ctx);
        goto after_23;
    // 0x8006B718: nop

    after_23:
    // 0x8006B71C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B720: nop

L_8006B724:
    // 0x8006B724: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006B728: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x8006B72C: bne         $at, $zero, L_8006B6CC
    if (ctx->r1 != 0) {
        // 0x8006B730: nop
    
            goto L_8006B6CC;
    }
    // 0x8006B730: nop

    // 0x8006B734: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8006B738: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8006B73C: bne         $t2, $at, L_8006B7A4
    if (ctx->r10 != ctx->r1) {
        // 0x8006B740: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B740: nop

    // 0x8006B744: jal         0x8009962C
    // 0x8006B748: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_24;
    // 0x8006B748: nop

    after_24:
    // 0x8006B74C: beq         $v0, $zero, L_8006B774
    if (ctx->r2 == 0) {
        // 0x8006B750: nop
    
            goto L_8006B774;
    }
    // 0x8006B750: nop

    // 0x8006B754: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006B758: nop

    // 0x8006B75C: lb          $t9, 0x4C($t4)
    ctx->r25 = MEM_B(ctx->r12, 0X4C);
    // 0x8006B760: nop

    // 0x8006B764: bne         $t9, $zero, L_8006B7A4
    if (ctx->r25 != 0) {
        // 0x8006B768: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B768: nop

    // 0x8006B76C: b           L_8006B7A4
    // 0x8006B770: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
        goto L_8006B7A4;
    // 0x8006B770: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B774:
    // 0x8006B774: jal         0x8009C2D0
    // 0x8006B778: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8006B778: nop

    after_25:
    // 0x8006B77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B780: bne         $v0, $at, L_8006B7A4
    if (ctx->r2 != ctx->r1) {
        // 0x8006B784: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B784: nop

    // 0x8006B788: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006B78C: nop

    // 0x8006B790: lb          $t8, 0x4C($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4C);
    // 0x8006B794: nop

    // 0x8006B798: bne         $t8, $zero, L_8006B7A4
    if (ctx->r24 != 0) {
        // 0x8006B79C: nop
    
            goto L_8006B7A4;
    }
    // 0x8006B79C: nop

    // 0x8006B7A0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B7A4:
    // 0x8006B7A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B7A8: nop

    // 0x8006B7AC: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B7B0: nop

    // 0x8006B7B4: beq         $a1, $zero, L_8006B7C0
    if (ctx->r5 == 0) {
        // 0x8006B7B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006B7C0;
    }
    // 0x8006B7B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B7BC: bne         $a1, $at, L_8006B7D0
    if (ctx->r5 != ctx->r1) {
        // 0x8006B7C0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006B7D0;
    }
L_8006B7C0:
    // 0x8006B7C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006B7C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B7C8: b           L_8006B7D8
    // 0x8006B7CC: sw          $t7, -0x2CE4($at)
    MEM_W(-0X2CE4, ctx->r1) = ctx->r15;
        goto L_8006B7D8;
    // 0x8006B7CC: sw          $t7, -0x2CE4($at)
    MEM_W(-0X2CE4, ctx->r1) = ctx->r15;
L_8006B7D0:
    // 0x8006B7D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B7D4: sw          $zero, -0x2CE4($at)
    MEM_W(-0X2CE4, ctx->r1) = 0;
L_8006B7D8:
    // 0x8006B7D8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8006B7DC: nop

    // 0x8006B7E0: beq         $t5, $zero, L_8006B804
    if (ctx->r13 == 0) {
        // 0x8006B7E4: nop
    
            goto L_8006B804;
    }
    // 0x8006B7E4: nop

    // 0x8006B7E8: lb          $t3, 0x4C($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B7EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006B7F0: beq         $t3, $at, L_8006B804
    if (ctx->r11 == ctx->r1) {
        // 0x8006B7F4: addiu       $t2, $zero, 0x6
        ctx->r10 = ADD32(0, 0X6);
            goto L_8006B804;
    }
    // 0x8006B7F4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8006B7F8: sb          $t2, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r10;
    // 0x8006B7FC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B800: nop

L_8006B804:
    // 0x8006B804: lbu         $a0, 0xB3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB3);
    // 0x8006B808: jal         0x80000BE0
    // 0x8006B80C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_26;
    // 0x8006B80C: nop

    after_26:
    // 0x8006B810: jal         0x80000CBC
    // 0x8006B814: nop

    music_volume_reset(rdram, ctx);
        goto after_27;
    // 0x8006B814: nop

    after_27:
    // 0x8006B818: jal         0x80031BB8
    // 0x8006B81C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    lights_init(rdram, ctx);
        goto after_28;
    // 0x8006B81C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_28:
    // 0x8006B820: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B824: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006B828: bltz        $t4, L_8006B84C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8006B82C: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_8006B84C;
    }
    // 0x8006B82C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8006B830: beq         $at, $zero, L_8006B84C
    if (ctx->r1 == 0) {
        // 0x8006B834: nop
    
            goto L_8006B84C;
    }
    // 0x8006B834: nop

    // 0x8006B838: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B83C: nop

    // 0x8006B840: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8006B844: lb          $s0, 0x4F($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X4F);
    // 0x8006B848: nop

L_8006B84C:
    // 0x8006B84C: jal         0x80017E74
    // 0x8006B850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_taj_challenge_type(rdram, ctx);
        goto after_29;
    // 0x8006B850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8006B854: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006B858: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006B85C: lb          $a0, 0x0($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X0);
    // 0x8006B860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B864: lbu         $s0, 0x48($v1)
    ctx->r16 = MEM_BU(ctx->r3, 0X48);
    // 0x8006B868: beq         $a0, $at, L_8006B878
    if (ctx->r4 == ctx->r1) {
        // 0x8006B86C: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_8006B878;
    }
    // 0x8006B86C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006B870: sb          $a0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r4;
    // 0x8006B874: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_8006B878:
    // 0x8006B878: bne         $s0, $zero, L_8006B8A4
    if (ctx->r16 != 0) {
        // 0x8006B87C: sb          $t7, 0x49($v1)
        MEM_B(0X49, ctx->r3) = ctx->r15;
            goto L_8006B8A4;
    }
    // 0x8006B87C: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x8006B880: lbu         $t5, 0x48($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X48);
    // 0x8006B884: nop

    // 0x8006B888: blez        $t5, L_8006B8A4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8006B88C: nop
    
            goto L_8006B8A4;
    }
    // 0x8006B88C: nop

    // 0x8006B890: jal         0x8006DB2C
    // 0x8006B894: nop

    get_level_default_vehicle(rdram, ctx);
        goto after_30;
    // 0x8006B894: nop

    after_30:
    // 0x8006B898: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B89C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006B8A0: sb          $v0, -0x2CEC($at)
    MEM_B(-0X2CEC, ctx->r1) = ctx->r2;
L_8006B8A4:
    // 0x8006B8A4: lbu         $t3, 0x48($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X48);
    // 0x8006B8A8: nop

    // 0x8006B8AC: bne         $t3, $zero, L_8006B8D4
    if (ctx->r11 != 0) {
        // 0x8006B8B0: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006B8D4;
    }
    // 0x8006B8B0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B8B4: blez        $s0, L_8006B8D0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006B8B8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8006B8D0;
    }
    // 0x8006B8B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B8BC: lb          $v0, -0x2CEC($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2CEC);
    // 0x8006B8C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B8C4: beq         $v0, $at, L_8006B8D4
    if (ctx->r2 == ctx->r1) {
        // 0x8006B8C8: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006B8D4;
    }
    // 0x8006B8C8: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B8CC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
L_8006B8D0:
    // 0x8006B8D0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
L_8006B8D4:
    // 0x8006B8D4: jal         0x8006DB20
    // 0x8006B8D8: nop

    set_vehicle_id_for_menu(rdram, ctx);
        goto after_31;
    // 0x8006B8D8: nop

    after_31:
    // 0x8006B8DC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006B8E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B8E4: lb          $t9, 0x4C($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4C);
    // 0x8006B8E8: nop

    // 0x8006B8EC: bne         $t9, $at, L_8006B9E0
    if (ctx->r25 != ctx->r1) {
        // 0x8006B8F0: nop
    
            goto L_8006B9E0;
    }
    // 0x8006B8F0: nop

    // 0x8006B8F4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006B8F8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8006B8FC: lbu         $a0, 0x48($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X48);
    // 0x8006B900: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B904: blez        $a0, L_8006B9E0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B908: addiu       $t4, $a0, 0x1F
        ctx->r12 = ADD32(ctx->r4, 0X1F);
            goto L_8006B9E0;
    }
    // 0x8006B908: addiu       $t4, $a0, 0x1F
    ctx->r12 = ADD32(ctx->r4, 0X1F);
    // 0x8006B90C: bne         $a0, $at, L_8006B964
    if (ctx->r4 != ctx->r1) {
        // 0x8006B910: sllv        $s0, $t6, $t4
        ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
            goto L_8006B964;
    }
    // 0x8006B910: sllv        $s0, $t6, $t4
    ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
    // 0x8006B914: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8006B918: nop

    // 0x8006B91C: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x8006B920: nop

    // 0x8006B924: slti        $at, $t7, 0x2F
    ctx->r1 = SIGNED(ctx->r15) < 0X2F ? 1 : 0;
    // 0x8006B928: bne         $at, $zero, L_8006B9E0
    if (ctx->r1 != 0) {
        // 0x8006B92C: nop
    
            goto L_8006B9E0;
    }
    // 0x8006B92C: nop

    // 0x8006B930: lbu         $t5, 0x16($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X16);
    // 0x8006B934: nop

    // 0x8006B938: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8006B93C: bne         $at, $zero, L_8006B9E0
    if (ctx->r1 != 0) {
        // 0x8006B940: nop
    
            goto L_8006B9E0;
    }
    // 0x8006B940: nop

    // 0x8006B944: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006B948: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006B94C: and         $t3, $v0, $s0
    ctx->r11 = ctx->r2 & ctx->r16;
    // 0x8006B950: bne         $t3, $zero, L_8006B9E0
    if (ctx->r11 != 0) {
        // 0x8006B954: or          $t2, $v0, $s0
        ctx->r10 = ctx->r2 | ctx->r16;
            goto L_8006B9E0;
    }
    // 0x8006B954: or          $t2, $v0, $s0
    ctx->r10 = ctx->r2 | ctx->r16;
    // 0x8006B958: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8006B95C: b           L_8006B9E0
    // 0x8006B960: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
        goto L_8006B9E0;
    // 0x8006B960: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006B964:
    // 0x8006B964: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8006B968: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8006B96C: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8006B970: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
    // 0x8006B974: nop

    // 0x8006B978: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006B97C: bne         $at, $zero, L_8006B9BC
    if (ctx->r1 != 0) {
        // 0x8006B980: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8006B9BC;
    }
    // 0x8006B980: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8006B984: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006B988: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006B98C: and         $t7, $v0, $s0
    ctx->r15 = ctx->r2 & ctx->r16;
    // 0x8006B990: bne         $t7, $zero, L_8006B9B8
    if (ctx->r15 != 0) {
        // 0x8006B994: or          $t5, $v0, $s0
        ctx->r13 = ctx->r2 | ctx->r16;
            goto L_8006B9B8;
    }
    // 0x8006B994: or          $t5, $v0, $s0
    ctx->r13 = ctx->r2 | ctx->r16;
    // 0x8006B998: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006B99C: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8006B9A0: lbu         $t9, 0x48($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X48);
    // 0x8006B9A4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006B9A8: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8006B9AC: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8006B9B0: lh          $v1, 0x0($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X0);
    // 0x8006B9B4: nop

L_8006B9B8:
    // 0x8006B9B8: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_8006B9BC:
    // 0x8006B9BC: bne         $at, $zero, L_8006B9E0
    if (ctx->r1 != 0) {
        // 0x8006B9C0: sll         $t8, $s0, 5
        ctx->r24 = S32(ctx->r16 << 5);
            goto L_8006B9E0;
    }
    // 0x8006B9C0: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8006B9C4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006B9C8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006B9CC: and         $t7, $v0, $t8
    ctx->r15 = ctx->r2 & ctx->r24;
    // 0x8006B9D0: bne         $t7, $zero, L_8006B9E0
    if (ctx->r15 != 0) {
        // 0x8006B9D4: or          $t5, $v0, $t8
        ctx->r13 = ctx->r2 | ctx->r24;
            goto L_8006B9E0;
    }
    // 0x8006B9D4: or          $t5, $v0, $t8
    ctx->r13 = ctx->r2 | ctx->r24;
    // 0x8006B9D8: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006B9DC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_8006B9E0:
    // 0x8006B9E0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B9E4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006B9E8: lb          $a1, 0x4C($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X4C);
    // 0x8006B9EC: beq         $t2, $zero, L_8006BA00
    if (ctx->r10 == 0) {
        // 0x8006B9F0: nop
    
            goto L_8006BA00;
    }
    // 0x8006B9F0: nop

    // 0x8006B9F4: bne         $a1, $zero, L_8006BA00
    if (ctx->r5 != 0) {
        // 0x8006B9F8: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_8006BA00;
    }
    // 0x8006B9F8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8006B9FC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006BA00:
    // 0x8006BA00: beq         $a1, $zero, L_8006BA10
    if (ctx->r5 == 0) {
        // 0x8006BA04: andi        $t4, $a1, 0x40
        ctx->r12 = ctx->r5 & 0X40;
            goto L_8006BA10;
    }
    // 0x8006BA04: andi        $t4, $a1, 0x40
    ctx->r12 = ctx->r5 & 0X40;
    // 0x8006BA08: beq         $t4, $zero, L_8006BA38
    if (ctx->r12 == 0) {
        // 0x8006BA0C: nop
    
            goto L_8006BA38;
    }
    // 0x8006BA0C: nop

L_8006BA10:
    // 0x8006BA10: jal         0x8009EC80
    // 0x8006BA14: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_32;
    // 0x8006BA14: nop

    after_32:
    // 0x8006BA18: beq         $v0, $zero, L_8006BA38
    if (ctx->r2 == 0) {
        // 0x8006BA1C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006BA38;
    }
    // 0x8006BA1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BA20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA24: sb          $t8, -0x2CE8($at)
    MEM_B(-0X2CE8, ctx->r1) = ctx->r24;
    // 0x8006BA28: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA2C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006BA30: b           L_8006BA48
    // 0x8006BA34: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_8006BA48;
    // 0x8006BA34: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006BA38:
    // 0x8006BA38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA3C: sb          $zero, -0x2CE8($at)
    MEM_B(-0X2CE8, ctx->r1) = 0;
    // 0x8006BA40: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA44: nop

L_8006BA48:
    // 0x8006BA48: lb          $t5, 0x4C($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X4C);
    // 0x8006BA4C: nop

    // 0x8006BA50: bne         $t5, $zero, L_8006BA80
    if (ctx->r13 != 0) {
        // 0x8006BA54: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BA80;
    }
    // 0x8006BA54: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BA58: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8006BA5C: nop

    // 0x8006BA60: bne         $t3, $zero, L_8006BA80
    if (ctx->r11 != 0) {
        // 0x8006BA64: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BA80;
    }
    // 0x8006BA64: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BA68: jal         0x8000E4C8
    // 0x8006BA6C: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_33;
    // 0x8006BA6C: nop

    after_33:
    // 0x8006BA70: beq         $v0, $zero, L_8006BA7C
    if (ctx->r2 == 0) {
        // 0x8006BA74: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8006BA7C;
    }
    // 0x8006BA74: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006BA78: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006BA7C:
    // 0x8006BA7C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_8006BA80:
    // 0x8006BA80: jal         0x8001E450
    // 0x8006BA84: nop

    cutscene_id_set(rdram, ctx);
        goto after_34;
    // 0x8006BA84: nop

    after_34:
    // 0x8006BA88: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA8C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8006BA90: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8006BA94: lh          $a1, 0x38($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X38);
    // 0x8006BA98: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BA9C: lh          $t6, 0x36($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X36);
    // 0x8006BAA0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8006BAA4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BAA8: lh          $t4, 0xBA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XBA);
    // 0x8006BAAC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BAB0: jal         0x800249F0
    // 0x8006BAB4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    init_track(rdram, ctx);
        goto after_35;
    // 0x8006BAB4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_35:
    // 0x8006BAB8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BABC: nop

    // 0x8006BAC0: lh          $t8, 0x3A($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BAC4: nop

    // 0x8006BAC8: bne         $t8, $zero, L_8006BB34
    if (ctx->r24 != 0) {
        // 0x8006BACC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BB34;
    }
    // 0x8006BACC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BAD0: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BAD4: nop

    // 0x8006BAD8: bne         $t7, $zero, L_8006BB34
    if (ctx->r15 != 0) {
        // 0x8006BADC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BB34;
    }
    // 0x8006BADC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BAE0: lh          $t5, 0x3E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X3E);
    // 0x8006BAE4: nop

    // 0x8006BAE8: bne         $t5, $zero, L_8006BB34
    if (ctx->r13 != 0) {
        // 0x8006BAEC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BB34;
    }
    // 0x8006BAEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BAF0: lh          $t3, 0x40($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X40);
    // 0x8006BAF4: nop

    // 0x8006BAF8: bne         $t3, $zero, L_8006BB34
    if (ctx->r11 != 0) {
        // 0x8006BAFC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BB34;
    }
    // 0x8006BAFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BB00: lh          $t9, 0x42($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X42);
    // 0x8006BB04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BB08: bne         $t9, $zero, L_8006BB30
    if (ctx->r25 != 0) {
        // 0x8006BB0C: nop
    
            goto L_8006BB30;
    }
    // 0x8006BB0C: nop

L_8006BB10:
    // 0x8006BB10: jal         0x800307BC
    // 0x8006BB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    reset_fog(rdram, ctx);
        goto after_36;
    // 0x8006BB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8006BB18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BB1C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BB20: bne         $s0, $at, L_8006BB10
    if (ctx->r16 != ctx->r1) {
        // 0x8006BB24: nop
    
            goto L_8006BB10;
    }
    // 0x8006BB24: nop

    // 0x8006BB28: b           L_8006BB6C
    // 0x8006BB2C: nop

        goto L_8006BB6C;
    // 0x8006BB2C: nop

L_8006BB30:
    // 0x8006BB30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006BB34:
    // 0x8006BB34: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BB38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006BB3C: lh          $t2, 0x40($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X40);
    // 0x8006BB40: lh          $a1, 0x3A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BB44: lh          $a2, 0x3C($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BB48: lbu         $a3, 0x3F($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X3F);
    // 0x8006BB4C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BB50: lh          $t6, 0x42($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X42);
    // 0x8006BB54: jal         0x80030664
    // 0x8006BB58: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    set_fog(rdram, ctx);
        goto after_37;
    // 0x8006BB58: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_37:
    // 0x8006BB5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BB60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BB64: bne         $s0, $at, L_8006BB34
    if (ctx->r16 != ctx->r1) {
        // 0x8006BB68: nop
    
            goto L_8006BB34;
    }
    // 0x8006BB68: nop

L_8006BB6C:
    // 0x8006BB6C: jal         0x8006EA90
    // 0x8006BB70: nop

    get_settings(rdram, ctx);
        goto after_38;
    // 0x8006BB70: nop

    after_38:
    // 0x8006BB74: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006BB78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BB7C: lb          $a0, 0x0($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X0);
    // 0x8006BB80: nop

    // 0x8006BB84: beq         $a0, $at, L_8006BB94
    if (ctx->r4 == ctx->r1) {
        // 0x8006BB88: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8006BB94;
    }
    // 0x8006BB88: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006BB8C: sb          $a0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r4;
    // 0x8006BB90: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8006BB94:
    // 0x8006BB94: nop

    // 0x8006BB98: sb          $t8, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r24;
    // 0x8006BB9C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BBA0: nop

    // 0x8006BBA4: lh          $a1, 0x90($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X90);
    // 0x8006BBA8: nop

    // 0x8006BBAC: blez        $a1, L_8006BC20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006BBB0: nop
    
            goto L_8006BC20;
    }
    // 0x8006BBB0: nop

    // 0x8006BBB4: lh          $t3, 0x9A($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X9A);
    // 0x8006BBB8: lh          $a2, 0x96($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X96);
    // 0x8006BBBC: lh          $a3, 0x98($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X98);
    // 0x8006BBC0: lh          $a0, 0x92($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X92);
    // 0x8006BBC4: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x8006BBC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006BBCC: lbu         $t2, 0x94($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X94);
    // 0x8006BBD0: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x8006BBD4: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BBD8: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8006BBDC: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x8006BBE0: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8006BBE4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8006BBE8: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BBEC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BBF0: lbu         $t4, 0x95($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X95);
    // 0x8006BBF4: nop

    // 0x8006BBF8: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BBFC: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BC00: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006BC04: jal         0x800AB4A8
    // 0x8006BC08: nop

    weather_reset(rdram, ctx);
        goto after_39;
    // 0x8006BC08: nop

    after_39:
    // 0x8006BC0C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006BC10: jal         0x800AB308
    // 0x8006BC14: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_40;
    // 0x8006BC14: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_40:
    // 0x8006BC18: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC1C: nop

L_8006BC20:
    // 0x8006BC20: lb          $t7, 0x49($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X49);
    // 0x8006BC24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BC28: bne         $t7, $at, L_8006BC68
    if (ctx->r15 != ctx->r1) {
        // 0x8006BC2C: nop
    
            goto L_8006BC68;
    }
    // 0x8006BC2C: nop

    // 0x8006BC30: lw          $a0, 0xA4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA4);
    // 0x8006BC34: jal         0x8007AE74
    // 0x8006BC38: nop

    load_texture(rdram, ctx);
        goto after_41;
    // 0x8006BC38: nop

    after_41:
    // 0x8006BC3C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC40: nop

    // 0x8006BC44: sw          $v0, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->r2;
    // 0x8006BC48: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC4C: nop

    // 0x8006BC50: sh          $zero, 0xA8($t3)
    MEM_H(0XA8, ctx->r11) = 0;
    // 0x8006BC54: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC58: nop

    // 0x8006BC5C: sh          $zero, 0xAA($t9)
    MEM_H(0XAA, ctx->r25) = 0;
    // 0x8006BC60: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC64: nop

L_8006BC68:
    // 0x8006BC68: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x8006BC6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BC70: beq         $a0, $at, L_8006BCA8
    if (ctx->r4 == ctx->r1) {
        // 0x8006BC74: nop
    
            goto L_8006BCA8;
    }
    // 0x8006BC74: nop

    // 0x8006BC78: jal         0x8001E29C
    // 0x8006BC7C: nop

    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8006BC7C: nop

    after_42:
    // 0x8006BC80: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC84: nop

    // 0x8006BC88: sw          $v0, 0xAC($t2)
    MEM_W(0XAC, ctx->r10) = ctx->r2;
    // 0x8006BC8C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC90: nop

    // 0x8006BC94: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8006BC98: jal         0x8007F414
    // 0x8006BC9C: nop

    init_pulsating_light_data(rdram, ctx);
        goto after_43;
    // 0x8006BC9C: nop

    after_43:
    // 0x8006BCA0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCA4: nop

L_8006BCA8:
    // 0x8006BCA8: lb          $t4, 0x9C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X9C);
    // 0x8006BCAC: nop

    extern void dkr_apply_gameplay_fov(uint8_t*, recomp_context*); dkr_apply_gameplay_fov(rdram, ctx);
    // 0x8006BCB0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8006BCB4: jal         0x800660EC
    // 0x8006BCB8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    cam_set_fov(rdram, ctx);
        goto after_44;
    // 0x8006BCB8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_44:
    // 0x8006BCBC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCC0: nop

    // 0x8006BCC4: lbu         $a0, 0x9D($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X9D);
    // 0x8006BCC8: lbu         $a1, 0x9E($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X9E);
    // 0x8006BCCC: lbu         $a2, 0x9F($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X9F);
    // 0x8006BCD0: jal         0x80077B34
    // 0x8006BCD4: nop

    bgdraw_primcolour(rdram, ctx);
        goto after_45;
    // 0x8006BCD4: nop

    after_45:
    // 0x8006BCD8: jal         0x8007A974
    // 0x8006BCDC: nop

    video_delta_reset(rdram, ctx);
        goto after_46;
    // 0x8006BCDC: nop

    after_46:
    // 0x8006BCE0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCE4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006BCE8: nop

    // 0x8006BCEC: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x8006BCF0: lbu         $a0, 0x4($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X4);
    // 0x8006BCF4: jal         0x8007AB24
    // 0x8006BCF8: nop

    func_8007AB24(rdram, ctx);
        goto after_47;
    // 0x8006BCF8: nop

    after_47:
    // 0x8006BCFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BD00: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8006BD04: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8006BD08: jr          $ra
    // 0x8006BD0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006BD0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void update_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B26E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B26E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B26E8: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800B26EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800B26F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B26F4: beq         $t6, $zero, L_800B2720
    if (ctx->r14 == 0) {
        // 0x800B26F8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_800B2720;
    }
    // 0x800B26F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800B26FC: lw          $a3, 0x58($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X58);
    // 0x800B2700: nop

    // 0x800B2704: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B2708: nop

    // 0x800B270C: lw          $t9, 0x9C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9C);
    // 0x800B2710: nop

    // 0x800B2714: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B2718: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x800B271C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
L_800B2720:
    // 0x800B2720: lbu         $t0, 0x68($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2724: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2728: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B272C: beq         $at, $zero, L_800B2E68
    if (ctx->r1 == 0) {
        // 0x800B2730: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800B2E68;
    }
    // 0x800B2730: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B2734: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B2738: nop

    // 0x800B273C: beq         $t1, $zero, L_800B2E68
    if (ctx->r9 == 0) {
        // 0x800B2740: nop
    
            goto L_800B2E68;
    }
    // 0x800B2740: nop

    // 0x800B2744: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800B2748: nop

    // 0x800B274C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B2750: nop

    // 0x800B2754: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B2758: beq         $t4, $zero, L_800B27B8
    if (ctx->r12 == 0) {
        // 0x800B275C: nop
    
            goto L_800B27B8;
    }
    // 0x800B275C: nop

    // 0x800B2760: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B2764: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B2768: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B276C: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B2770: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B2774: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2778: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B277C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2780: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B2784: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B2788: jal         0x800C9AD0
    // 0x800B278C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B278C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800B2790: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2794: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2798: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B279C: lwc1        $f4, -0x7410($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7410);
    // 0x800B27A0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B27A4: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B27A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B27AC: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B27B0: b           L_800B27C4
    // 0x800B27B4: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
        goto L_800B27C4;
    // 0x800B27B4: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B27B8:
    // 0x800B27B8: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B27BC: nop

    // 0x800B27C0: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B27C4:
    // 0x800B27C4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800B27C8: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x800B27CC: bne         $t6, $zero, L_800B283C
    if (ctx->r14 != 0) {
        // 0x800B27D0: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800B283C;
    }
    // 0x800B27D0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B27D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B27D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B27DC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800B27E0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800B27E4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800B27E8: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B27EC: nop

    // 0x800B27F0: beq         $v0, $at, L_800B2810
    if (ctx->r2 == ctx->r1) {
        // 0x800B27F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B2810;
    }
    // 0x800B27F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B27F8: beq         $v0, $at, L_800B2808
    if (ctx->r2 == ctx->r1) {
        // 0x800B27FC: nop
    
            goto L_800B2808;
    }
    // 0x800B27FC: nop

    // 0x800B2800: b           L_800B2814
    // 0x800B2804: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
        goto L_800B2814;
    // 0x800B2804: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
L_800B2808:
    // 0x800B2808: b           L_800B2814
    // 0x800B280C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
        goto L_800B2814;
    // 0x800B280C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
L_800B2810:
    // 0x800B2810: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
L_800B2814:
    // 0x800B2814: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B2818: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B281C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2820: jal         0x80070320
    // 0x800B2824: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B2824: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B2828: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B282C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2830: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2834: b           L_800B292C
    // 0x800B2838: nop

        goto L_800B292C;
    // 0x800B2838: nop

L_800B283C:
    // 0x800B283C: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800B2840: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2844: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800B2848: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B284C: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800B2850: nop

    // 0x800B2854: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800B2858: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B285C: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B2860: lwc1        $f8, -0x740C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X740C);
    // 0x800B2864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B2868: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B286C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2870: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800B2874: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B2878: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800B287C: nop

    // 0x800B2880: bc1f        L_800B2894
    if (!c1cs) {
        // 0x800B2884: nop
    
            goto L_800B2894;
    }
    // 0x800B2884: nop

    // 0x800B2888: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B288C: b           L_800B28C0
    // 0x800B2890: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
        goto L_800B28C0;
    // 0x800B2890: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B2894:
    // 0x800B2894: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2898: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B289C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B28A0: jal         0x800C9AD0
    // 0x800B28A4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B28A4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800B28A8: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B28AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B28B0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B28B4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B28B8: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B28BC: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B28C0:
    // 0x800B28C0: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B28C4: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B28C8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B28CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B28D0: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800B28D4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B28D8: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B28DC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B28E0: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B28E4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800B28E8: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B28EC: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B28F0: beq         $v0, $zero, L_800B2908
    if (ctx->r2 == 0) {
        // 0x800B28F4: nop
    
            goto L_800B2908;
    }
    // 0x800B28F4: nop

    // 0x800B28F8: beq         $v0, $at, L_800B2918
    if (ctx->r2 == ctx->r1) {
        // 0x800B28FC: nop
    
            goto L_800B2918;
    }
    // 0x800B28FC: nop

    // 0x800B2900: b           L_800B292C
    // 0x800B2904: nop

        goto L_800B292C;
    // 0x800B2904: nop

L_800B2908:
    // 0x800B2908: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B290C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B2910: b           L_800B292C
    // 0x800B2914: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
        goto L_800B292C;
    // 0x800B2914: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B2918:
    // 0x800B2918: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B291C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2920: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800B2924: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B2928: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B292C:
    // 0x800B292C: beq         $v1, $zero, L_800B2C68
    if (ctx->r3 == 0) {
        // 0x800B2930: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800B2C68;
    }
    // 0x800B2930: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B2934: lbu         $t8, 0x68($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2938: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B293C: bne         $t8, $zero, L_800B2C68
    if (ctx->r24 != 0) {
        // 0x800B2940: nop
    
            goto L_800B2C68;
    }
    // 0x800B2940: nop

    // 0x800B2944: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2948: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B294C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B2950: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2954: nop

    // 0x800B2958: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B295C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2960: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2964: nop

    // 0x800B2968: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B296C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B2970: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2974: sh          $t0, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r8;
    // 0x800B2978: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B297C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2980: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B2984: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B2988: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B298C: nop

    // 0x800B2990: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B2994: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2998: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B299C: nop

    // 0x800B29A0: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B29A4: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800B29A8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B29AC: sh          $t4, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r12;
    // 0x800B29B0: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B29B4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B29B8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B29BC: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B29C0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B29C4: nop

    // 0x800B29C8: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B29CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B29D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B29D4: nop

    // 0x800B29D8: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B29DC: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B29E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B29E4: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x800B29E8: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B29EC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B29F0: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B29F4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B29F8: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    // 0x800B29FC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2A04: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x800B2A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2A0C: sb          $t9, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r25;
    // 0x800B2A10: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A14: nop

    // 0x800B2A18: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x800B2A1C: nop

    // 0x800B2A20: sb          $t0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r8;
    // 0x800B2A24: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A28: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2A2C: nop

    // 0x800B2A30: sb          $t2, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r10;
    // 0x800B2A34: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2A38: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A3C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2A40: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B2A44: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800B2A48: nop

    // 0x800B2A4C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2A50: sh          $t1, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r9;
    // 0x800B2A54: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B2A58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2A5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2A60: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2A64: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A68: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2A6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2A70: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2A74: nop

    // 0x800B2A78: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2A7C: sh          $t7, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r15;
    // 0x800B2A80: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2A84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2A88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2A8C: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2A90: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A94: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2A98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2A9C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B2AA0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2AA4: sh          $t0, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r8;
    // 0x800B2AA8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2AAC: nop

    // 0x800B2AB0: beq         $t3, $at, L_800B2B24
    if (ctx->r11 == ctx->r1) {
        // 0x800B2AB4: nop
    
            goto L_800B2B24;
    }
    // 0x800B2AB4: nop

    // 0x800B2AB8: lh          $t4, 0x1E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1E);
    // 0x800B2ABC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2AC0: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x800B2AC4: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800B2AC8: lbu         $t6, 0x14($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X14);
    // 0x800B2ACC: nop

    // 0x800B2AD0: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800B2AD4: lh          $t9, 0x1E($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1E);
    // 0x800B2AD8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2ADC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B2AE0: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x800B2AE4: lbu         $t4, 0x15($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X15);
    // 0x800B2AE8: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2AEC: nop

    // 0x800B2AF0: sb          $t4, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r12;
    // 0x800B2AF4: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B2AF8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B2AFC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800B2B00: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800B2B04: lbu         $t9, 0x16($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X16);
    // 0x800B2B08: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B0C: nop

    // 0x800B2B10: sb          $t9, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r25;
    // 0x800B2B14: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B18: lbu         $t0, 0x6($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2B1C: b           L_800B2B64
    // 0x800B2B20: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
        goto L_800B2B64;
    // 0x800B2B20: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
L_800B2B24:
    // 0x800B2B24: lbu         $t4, 0x6C($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6C);
    // 0x800B2B28: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B2C: nop

    // 0x800B2B30: sb          $t4, 0x1A($t3)
    MEM_B(0X1A, ctx->r11) = ctx->r12;
    // 0x800B2B34: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B38: lbu         $t5, 0x6D($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6D);
    // 0x800B2B3C: nop

    // 0x800B2B40: sb          $t5, 0x1B($t1)
    MEM_B(0X1B, ctx->r9) = ctx->r13;
    // 0x800B2B44: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B48: lbu         $t6, 0x6E($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6E);
    // 0x800B2B4C: nop

    // 0x800B2B50: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x800B2B54: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B58: lbu         $t9, 0x6($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2B5C: nop

    // 0x800B2B60: sb          $t9, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r25;
L_800B2B64:
    // 0x800B2B64: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2B68: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2B6C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B2B70: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B2B74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B2B78: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800B2B7C: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
    // 0x800B2B80: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800B2B84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2B88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2B8C: nop

    // 0x800B2B90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2B94: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800B2B98: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800B2B9C: sh          $t2, 0x1E($t4)
    MEM_H(0X1E, ctx->r12) = ctx->r10;
    // 0x800B2BA0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2BA4: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2BA8: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B2BAC: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B2BB0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B2BB4: nop

    // 0x800B2BB8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B2BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2BC4: nop

    // 0x800B2BC8: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2BCC: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800B2BD0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B2BD4: sh          $t5, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r13;
    // 0x800B2BD8: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2BDC: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2BE0: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B2BE4: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2BE8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B2BEC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2BF0: nop

    // 0x800B2BF4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B2BF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2BFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2C00: nop

    // 0x800B2C04: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2C08: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800B2C0C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2C10: sh          $t7, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r15;
    // 0x800B2C14: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2C18: nop

    // 0x800B2C1C: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2C20: nop

    // 0x800B2C24: sb          $t8, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r24;
    // 0x800B2C28: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2C2C: nop

    // 0x800B2C30: lbu         $t0, 0x7($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7);
    // 0x800B2C34: nop

    // 0x800B2C38: sb          $t0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r8;
    // 0x800B2C3C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2C40: nop

    // 0x800B2C44: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800B2C48: nop

    // 0x800B2C4C: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x800B2C50: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2C54: lbu         $t4, 0x6($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2C58: nop

    // 0x800B2C5C: sb          $t4, 0x27($t3)
    MEM_B(0X27, ctx->r11) = ctx->r12;
    // 0x800B2C60: b           L_800B2F68
    // 0x800B2C64: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
        goto L_800B2F68;
    // 0x800B2C64: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
L_800B2C68:
    // 0x800B2C68: beq         $v1, $zero, L_800B2E60
    if (ctx->r3 == 0) {
        // 0x800B2C6C: nop
    
            goto L_800B2E60;
    }
    // 0x800B2C6C: nop

    // 0x800B2C70: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2C74: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2C78: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2C7C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B2C80: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B2C84: nop

    // 0x800B2C88: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B2C8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2C90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2C94: nop

    // 0x800B2C98: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2C9C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B2CA0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B2CA4: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    // 0x800B2CA8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2CAC: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2CB0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800B2CB4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B2CB8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2CBC: nop

    // 0x800B2CC0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2CC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2CC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2CCC: nop

    // 0x800B2CD0: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2CD4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800B2CD8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2CDC: sh          $t8, 0x2A($t0)
    MEM_H(0X2A, ctx->r8) = ctx->r24;
    // 0x800B2CE0: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2CE4: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2CE8: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2CEC: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2CF0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B2CF4: nop

    // 0x800B2CF8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B2CFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2D00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2D04: nop

    // 0x800B2D08: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2D0C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800B2D10: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B2D14: sh          $t4, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r12;
    // 0x800B2D18: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2D1C: nop

    // 0x800B2D20: lbu         $t5, 0x1A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B2D24: nop

    // 0x800B2D28: sb          $t5, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r13;
    // 0x800B2D2C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2D30: nop

    // 0x800B2D34: lbu         $t1, 0x1B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B2D38: nop

    // 0x800B2D3C: sb          $t1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r9;
    // 0x800B2D40: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2D44: nop

    // 0x800B2D48: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B2D4C: nop

    // 0x800B2D50: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x800B2D54: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B2D58: lbu         $t7, 0x6($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2D5C: nop

    // 0x800B2D60: sb          $t7, 0x31($t9)
    MEM_B(0X31, ctx->r25) = ctx->r15;
    // 0x800B2D64: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2D68: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2D6C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2D70: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B2D74: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B2D78: nop

    // 0x800B2D7C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B2D80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2D84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2D88: nop

    // 0x800B2D8C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2D90: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B2D94: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B2D98: sh          $t0, 0x32($t2)
    MEM_H(0X32, ctx->r10) = ctx->r8;
    // 0x800B2D9C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2DA0: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2DA4: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B2DA8: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B2DAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B2DB0: nop

    // 0x800B2DB4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B2DB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2DBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2DC0: nop

    // 0x800B2DC4: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2DC8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800B2DCC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B2DD0: sh          $t3, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r11;
    // 0x800B2DD4: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2DD8: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2DDC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2DE0: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B2DE4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800B2DE8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B2DEC: nop

    // 0x800B2DF0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B2DF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2DF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2DFC: nop

    // 0x800B2E00: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2E04: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B2E08: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B2E0C: sh          $t6, 0x36($t7)
    MEM_H(0X36, ctx->r15) = ctx->r14;
    // 0x800B2E10: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2E14: nop

    // 0x800B2E18: lbu         $t9, 0x1A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B2E1C: nop

    // 0x800B2E20: sb          $t9, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r25;
    // 0x800B2E24: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2E28: nop

    // 0x800B2E2C: lbu         $t8, 0x1B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B2E30: nop

    // 0x800B2E34: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x800B2E38: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2E3C: nop

    // 0x800B2E40: lbu         $t0, 0x1C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B2E44: nop

    // 0x800B2E48: sb          $t0, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r8;
    // 0x800B2E4C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B2E50: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2E54: nop

    // 0x800B2E58: sb          $t2, 0x3B($t4)
    MEM_B(0X3B, ctx->r12) = ctx->r10;
    // 0x800B2E5C: sb          $t3, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r11;
L_800B2E60:
    // 0x800B2E60: b           L_800B2F68
    // 0x800B2E64: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
        goto L_800B2F68;
    // 0x800B2E64: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
L_800B2E68:
    // 0x800B2E68: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
    // 0x800B2E6C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B2E70: lh          $t5, 0x3A($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X3A);
    // 0x800B2E74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B2E78: subu        $t6, $t5, $t1
    ctx->r14 = SUB32(ctx->r13, ctx->r9);
    // 0x800B2E7C: sh          $t6, 0x3A($a2)
    MEM_H(0X3A, ctx->r6) = ctx->r14;
    // 0x800B2E80: lh          $t7, 0x3A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X3A);
    // 0x800B2E84: nop

    // 0x800B2E88: bgtz        $t7, L_800B2EB0
    if (SIGNED(ctx->r15) > 0) {
        // 0x800B2E8C: nop
    
            goto L_800B2EB0;
    }
    // 0x800B2E8C: nop

    // 0x800B2E90: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2E94: jal         0x8000FFB8
    // 0x800B2E98: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800B2E98: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_3:
    // 0x800B2E9C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2EA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B2EA4: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2EA8: b           L_800B2F68
    // 0x800B2EAC: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
        goto L_800B2F68;
    // 0x800B2EAC: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
L_800B2EB0:
    // 0x800B2EB0: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B2EB4: nop

    // 0x800B2EB8: bne         $v0, $zero, L_800B2F2C
    if (ctx->r2 != 0) {
        // 0x800B2EBC: nop
    
            goto L_800B2F2C;
    }
    // 0x800B2EBC: nop

    // 0x800B2EC0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B2EC4: lh          $t8, 0x5E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X5E);
    // 0x800B2EC8: lh          $t2, 0x5C($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X5C);
    // 0x800B2ECC: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2ED0: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2ED4: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x800B2ED8: sh          $t4, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r12;
    // 0x800B2EDC: lh          $t3, 0x5C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5C);
    // 0x800B2EE0: nop

    // 0x800B2EE4: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x800B2EE8: beq         $at, $zero, L_800B2F68
    if (ctx->r1 == 0) {
        // 0x800B2EEC: nop
    
            goto L_800B2F68;
    }
    // 0x800B2EEC: nop

    // 0x800B2EF0: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
    // 0x800B2EF4: nop

    // 0x800B2EF8: andi        $t1, $t5, 0x1000
    ctx->r9 = ctx->r13 & 0X1000;
    // 0x800B2EFC: beq         $t1, $zero, L_800B2F18
    if (ctx->r9 == 0) {
        // 0x800B2F00: nop
    
            goto L_800B2F18;
    }
    // 0x800B2F00: nop

    // 0x800B2F04: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x800B2F08: nop

    // 0x800B2F0C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800B2F10: b           L_800B2F68
    // 0x800B2F14: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
        goto L_800B2F68;
    // 0x800B2F14: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_800B2F18:
    // 0x800B2F18: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800B2F1C: nop

    // 0x800B2F20: ori         $t8, $t9, 0x80
    ctx->r24 = ctx->r25 | 0X80;
    // 0x800B2F24: b           L_800B2F68
    // 0x800B2F28: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
        goto L_800B2F68;
    // 0x800B2F28: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
L_800B2F2C:
    // 0x800B2F2C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B2F30: nop

    // 0x800B2F34: subu        $t0, $v0, $t2
    ctx->r8 = SUB32(ctx->r2, ctx->r10);
    // 0x800B2F38: sh          $t0, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r8;
    // 0x800B2F3C: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B2F40: nop

    // 0x800B2F44: bgez        $v0, L_800B2F68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B2F48: nop
    
            goto L_800B2F68;
    }
    // 0x800B2F48: nop

    // 0x800B2F4C: lh          $t3, 0x5E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5E);
    // 0x800B2F50: lh          $t4, 0x5C($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X5C);
    // 0x800B2F54: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F58: sh          $zero, 0x60($a2)
    MEM_H(0X60, ctx->r6) = 0;
    // 0x800B2F5C: mflo        $t5
    ctx->r13 = lo;
    // 0x800B2F60: subu        $t1, $t4, $t5
    ctx->r9 = SUB32(ctx->r12, ctx->r13);
    // 0x800B2F64: sh          $t1, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r9;
L_800B2F68:
    // 0x800B2F68: beq         $v1, $zero, L_800B2FB0
    if (ctx->r3 == 0) {
        // 0x800B2F6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2FB0;
    }
    // 0x800B2F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2F70: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B2F74: nop

    // 0x800B2F78: beq         $t6, $zero, L_800B2FB0
    if (ctx->r14 == 0) {
        // 0x800B2F7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2FB0;
    }
    // 0x800B2F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2F80: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x800B2F84: nop

    // 0x800B2F88: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x800B2F8C: beq         $t9, $zero, L_800B2FB0
    if (ctx->r25 == 0) {
        // 0x800B2F90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2FB0;
    }
    // 0x800B2F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2F94: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B2F98: nop

    // 0x800B2F9C: blez        $t8, L_800B2FB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B2FA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2FB0;
    }
    // 0x800B2FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2FA4: jal         0x800B2FBC
    // 0x800B2FA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    update_particle_texture_frame(rdram, ctx);
        goto after_4;
    // 0x800B2FA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x800B2FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B2FB0:
    // 0x800B2FB0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800B2FB4: jr          $ra
    // 0x800B2FB8: nop

    return;
    // 0x800B2FB8: nop

;}
RECOMP_FUNC void obj_init_butterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800409C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800409CC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800409D0: bne         $a2, $zero, L_80040AC0
    if (ctx->r6 != 0) {
        // 0x800409D4: addiu       $t6, $zero, 0x180
        ctx->r14 = ADD32(0, 0X180);
            goto L_80040AC0;
    }
    // 0x800409D4: addiu       $t6, $zero, 0x180
    ctx->r14 = ADD32(0, 0X180);
    // 0x800409D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800409DC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800409E0: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x800409E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800409E8: sb          $zero, 0xFE($v0)
    MEM_B(0XFE, ctx->r2) = 0;
    // 0x800409EC: sw          $zero, 0x100($v0)
    MEM_W(0X100, ctx->r2) = 0;
    // 0x800409F0: sh          $zero, 0x104($v0)
    MEM_H(0X104, ctx->r2) = 0;
    // 0x800409F4: sb          $zero, 0xFD($v0)
    MEM_B(0XFD, ctx->r2) = 0;
    // 0x800409F8: sh          $t6, 0x106($v0)
    MEM_H(0X106, ctx->r2) = ctx->r14;
    // 0x800409FC: addiu       $v1, $v1, -0x34D8
    ctx->r3 = ADD32(ctx->r3, -0X34D8);
    // 0x80040A00: addiu       $a2, $a2, -0x3558
    ctx->r6 = ADD32(ctx->r6, -0X3558);
    // 0x80040A04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040A08: swc1        $f0, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->f0.u32l;
L_80040A0C:
    // 0x80040A0C: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80040A10: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80040A14: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x80040A18: lbu         $t8, -0xF($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0XF);
    // 0x80040A1C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80040A20: sb          $t8, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r24;
    // 0x80040A24: lbu         $t9, -0xE($a2)
    ctx->r25 = MEM_BU(ctx->r6, -0XE);
    // 0x80040A28: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80040A2C: sb          $t9, -0xE($a1)
    MEM_B(-0XE, ctx->r5) = ctx->r25;
    // 0x80040A30: lbu         $t1, -0xD($a2)
    ctx->r9 = MEM_BU(ctx->r6, -0XD);
    // 0x80040A34: bne         $at, $zero, L_80040A0C
    if (ctx->r1 != 0) {
        // 0x80040A38: sb          $t1, -0xD($a1)
        MEM_B(-0XD, ctx->r5) = ctx->r9;
            goto L_80040A0C;
    }
    // 0x80040A38: sb          $t1, -0xD($a1)
    MEM_B(-0XD, ctx->r5) = ctx->r9;
    // 0x80040A3C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80040A40: addiu       $a2, $a2, -0x34D8
    ctx->r6 = ADD32(ctx->r6, -0X34D8);
    // 0x80040A44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040A48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040A4C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80040A50: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80040A54:
    // 0x80040A54: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x80040A58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040A5C: sh          $t2, 0x80($a1)
    MEM_H(0X80, ctx->r5) = ctx->r10;
    // 0x80040A60: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x80040A64: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80040A68: sh          $t3, 0x78($a1)
    MEM_H(0X78, ctx->r5) = ctx->r11;
    // 0x80040A6C: lh          $t4, 0x4($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X4);
    // 0x80040A70: sb          $a3, 0x7C($a1)
    MEM_B(0X7C, ctx->r5) = ctx->r7;
    // 0x80040A74: sb          $a3, 0x7D($a1)
    MEM_B(0X7D, ctx->r5) = ctx->r7;
    // 0x80040A78: sb          $a3, 0x7E($a1)
    MEM_B(0X7E, ctx->r5) = ctx->r7;
    // 0x80040A7C: sb          $a3, 0x7F($a1)
    MEM_B(0X7F, ctx->r5) = ctx->r7;
    // 0x80040A80: sh          $t4, 0x7A($a1)
    MEM_H(0X7A, ctx->r5) = ctx->r12;
    // 0x80040A84: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x80040A88: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x80040A8C: sh          $t5, 0xB2($a1)
    MEM_H(0XB2, ctx->r5) = ctx->r13;
    // 0x80040A90: lh          $t6, -0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X4);
    // 0x80040A94: nop

    // 0x80040A98: sh          $t6, 0xB4($a1)
    MEM_H(0XB4, ctx->r5) = ctx->r14;
    // 0x80040A9C: lh          $t7, -0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, -0X2);
    // 0x80040AA0: sb          $a3, 0xB8($a1)
    MEM_B(0XB8, ctx->r5) = ctx->r7;
    // 0x80040AA4: sb          $a3, 0xB9($a1)
    MEM_B(0XB9, ctx->r5) = ctx->r7;
    // 0x80040AA8: sb          $a3, 0xBA($a1)
    MEM_B(0XBA, ctx->r5) = ctx->r7;
    // 0x80040AAC: sb          $a3, 0xBB($a1)
    MEM_B(0XBB, ctx->r5) = ctx->r7;
    // 0x80040AB0: bne         $v1, $t0, L_80040A54
    if (ctx->r3 != ctx->r8) {
        // 0x80040AB4: sh          $t7, 0xB6($a1)
        MEM_H(0XB6, ctx->r5) = ctx->r15;
            goto L_80040A54;
    }
    // 0x80040AB4: sh          $t7, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = ctx->r15;
    // 0x80040AB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040ABC: sb          $t8, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r24;
L_80040AC0:
    // 0x80040AC0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80040AC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040AC8: lbu         $t1, 0xB($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0XB);
    // 0x80040ACC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80040AD0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80040AD4: bgez        $t1, L_80040AEC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80040AD8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80040AEC;
    }
    // 0x80040AD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040ADC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040AE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040AE4: nop

    // 0x80040AE8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80040AEC:
    // 0x80040AEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040AF0: lwc1        $f10, 0x6218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6218);
    // 0x80040AF4: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80040AF8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80040AFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80040B00: addiu       $a2, $a2, -0x3558
    ctx->r6 = ADD32(ctx->r6, -0X3558);
    // 0x80040B04: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80040B08: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80040B0C: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80040B10: lbu         $v1, 0xA($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0XA);
    // 0x80040B14: nop

    // 0x80040B18: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80040B1C: beq         $at, $zero, L_80040B3C
    if (ctx->r1 == 0) {
        // 0x80040B20: nop
    
            goto L_80040B3C;
    }
    // 0x80040B20: nop

    // 0x80040B24: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x80040B28: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80040B2C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80040B30: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80040B34: b           L_80040B50
    // 0x80040B38: sw          $t8, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r24;
        goto L_80040B50;
    // 0x80040B38: sw          $t8, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r24;
L_80040B3C:
    // 0x80040B3C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x80040B40: nop

    // 0x80040B44: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80040B48: nop

    // 0x80040B4C: sw          $t1, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r9;
L_80040B50:
    // 0x80040B50: lw          $v1, 0xF8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF8);
    // 0x80040B54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80040B58: beq         $v1, $zero, L_80040B84
    if (ctx->r3 == 0) {
        // 0x80040B5C: addiu       $v0, $v0, -0x34D8
        ctx->r2 = ADD32(ctx->r2, -0X34D8);
            goto L_80040B84;
    }
    // 0x80040B5C: addiu       $v0, $v0, -0x34D8
    ctx->r2 = ADD32(ctx->r2, -0X34D8);
    // 0x80040B60: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x80040B64: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80040B68: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80040B6C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80040B70: sll         $t2, $a3, 5
    ctx->r10 = S32(ctx->r7 << 5);
    // 0x80040B74: sll         $t3, $a0, 5
    ctx->r11 = S32(ctx->r4 << 5);
    // 0x80040B78: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80040B7C: b           L_80040B88
    // 0x80040B80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_80040B88;
    // 0x80040B80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_80040B84:
    // 0x80040B84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80040B88:
    // 0x80040B88: lh          $t4, 0x4($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X4);
    // 0x80040B8C: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80040B90: and         $t5, $t4, $a3
    ctx->r13 = ctx->r12 & ctx->r7;
    // 0x80040B94: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80040B98: lh          $t6, -0x1A($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X1A);
    // 0x80040B9C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80040BA0: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x80040BA4: sh          $t7, -0x1A($a1)
    MEM_H(-0X1A, ctx->r5) = ctx->r15;
    // 0x80040BA8: lh          $t8, -0x18($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X18);
    // 0x80040BAC: nop

    // 0x80040BB0: and         $t9, $t8, $a3
    ctx->r25 = ctx->r24 & ctx->r7;
    // 0x80040BB4: sh          $t9, -0x18($a1)
    MEM_H(-0X18, ctx->r5) = ctx->r25;
    // 0x80040BB8: lh          $t1, -0x16($a2)
    ctx->r9 = MEM_H(ctx->r6, -0X16);
    // 0x80040BBC: nop

    // 0x80040BC0: and         $t2, $t1, $a0
    ctx->r10 = ctx->r9 & ctx->r4;
    // 0x80040BC4: sh          $t2, -0x16($a1)
    MEM_H(-0X16, ctx->r5) = ctx->r10;
    // 0x80040BC8: lh          $t3, -0x14($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X14);
    // 0x80040BCC: nop

    // 0x80040BD0: and         $t4, $t3, $a3
    ctx->r12 = ctx->r11 & ctx->r7;
    // 0x80040BD4: sh          $t4, -0x14($a1)
    MEM_H(-0X14, ctx->r5) = ctx->r12;
    // 0x80040BD8: lh          $t5, -0x12($a2)
    ctx->r13 = MEM_H(ctx->r6, -0X12);
    // 0x80040BDC: nop

    // 0x80040BE0: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x80040BE4: sh          $t6, -0x12($a1)
    MEM_H(-0X12, ctx->r5) = ctx->r14;
    // 0x80040BE8: lh          $t7, -0xC($a2)
    ctx->r15 = MEM_H(ctx->r6, -0XC);
    // 0x80040BEC: nop

    // 0x80040BF0: and         $t8, $t7, $a3
    ctx->r24 = ctx->r15 & ctx->r7;
    // 0x80040BF4: sh          $t8, -0xC($a1)
    MEM_H(-0XC, ctx->r5) = ctx->r24;
    // 0x80040BF8: lh          $t9, -0xA($a2)
    ctx->r25 = MEM_H(ctx->r6, -0XA);
    // 0x80040BFC: nop

    // 0x80040C00: and         $t1, $t9, $a0
    ctx->r9 = ctx->r25 & ctx->r4;
    // 0x80040C04: sh          $t1, -0xA($a1)
    MEM_H(-0XA, ctx->r5) = ctx->r9;
    // 0x80040C08: lh          $t2, -0x8($a2)
    ctx->r10 = MEM_H(ctx->r6, -0X8);
    // 0x80040C0C: nop

    // 0x80040C10: and         $t3, $t2, $a3
    ctx->r11 = ctx->r10 & ctx->r7;
    // 0x80040C14: sh          $t3, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r11;
    // 0x80040C18: lh          $t4, -0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, -0X6);
    // 0x80040C1C: nop

    // 0x80040C20: and         $t5, $t4, $a0
    ctx->r13 = ctx->r12 & ctx->r4;
    // 0x80040C24: sh          $t5, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r13;
    // 0x80040C28: lh          $t6, -0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X4);
    // 0x80040C2C: nop

    // 0x80040C30: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x80040C34: sh          $t7, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r15;
    // 0x80040C38: lh          $t8, -0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X2);
    // 0x80040C3C: nop

    // 0x80040C40: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x80040C44: bne         $a2, $v0, L_80040B88
    if (ctx->r6 != ctx->r2) {
        // 0x80040C48: sh          $t9, -0x2($a1)
        MEM_H(-0X2, ctx->r5) = ctx->r25;
            goto L_80040B88;
    }
    // 0x80040C48: sh          $t9, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r25;
    // 0x80040C4C: jr          $ra
    // 0x80040C50: nop

    return;
    // 0x80040C50: nop

;}
RECOMP_FUNC void rain_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADCBC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800ADCC0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800ADCC4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800ADCC8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800ADCCC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800ADCD0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800ADCD4: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800ADCD8: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800ADCDC: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800ADCE0: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800ADCE4: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800ADCE8: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800ADCEC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800ADCF0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800ADCF4: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800ADCF8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800ADCFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ADD00: beq         $v0, $zero, L_800AE22C
    if (ctx->r2 == 0) {
        // 0x800ADD04: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800AE22C;
    }
    // 0x800ADD04: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800ADD08: lbu         $s1, 0x0($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X0);
    // 0x800ADD0C: lbu         $s2, 0x1($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X1);
    // 0x800ADD10: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x800ADD14: sll         $t7, $s2, 5
    ctx->r15 = S32(ctx->r18 << 5);
    // 0x800ADD18: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
    // 0x800ADD1C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800ADD20: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ADD24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800ADD28: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x800ADD2C: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800ADD30: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x800ADD34: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800ADD38: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADD3C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800ADD40: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800ADD44: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800ADD48: mflo        $a0
    ctx->r4 = lo;
    // 0x800ADD4C: jal         0x8000C8B4
    // 0x800ADD50: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800ADD50: nop

    after_0:
    // 0x800ADD54: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800ADD58: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADD5C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800ADD60: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x800ADD64: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800ADD68: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800ADD6C: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x800ADD70: nop

    // 0x800ADD74: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADD78: mflo        $a0
    ctx->r4 = lo;
    // 0x800ADD7C: jal         0x8000C8B4
    // 0x800ADD80: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x800ADD80: nop

    after_1:
    // 0x800ADD84: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800ADD88: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x800ADD8C: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADD90: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800ADD94: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800ADD98: and         $t5, $t8, $t9
    ctx->r13 = ctx->r24 & ctx->r25;
    // 0x800ADD9C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800ADDA0: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x800ADDA4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800ADDA8: lw          $t5, 0x2C6C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2C6C);
    // 0x800ADDAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800ADDB0: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800ADDB4: mflo        $s1
    ctx->r17 = lo;
    // 0x800ADDB8: sra         $t7, $s1, 8
    ctx->r15 = S32(SIGNED(ctx->r17) >> 8);
    // 0x800ADDBC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800ADDC0: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADDC4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ADDC8: lw          $t7, 0x2C60($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C60);
    // 0x800ADDCC: mflo        $s2
    ctx->r18 = lo;
    // 0x800ADDD0: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x800ADDD4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800ADDD8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADDDC: lbu         $t9, 0x16($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X16);
    // 0x800ADDE0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800ADDE4: mflo        $v1
    ctx->r3 = lo;
    // 0x800ADDE8: sra         $t8, $v1, 14
    ctx->r24 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800ADDEC: nop

    // 0x800ADDF0: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADDF4: mflo        $v1
    ctx->r3 = lo;
    // 0x800ADDF8: sra         $t5, $v1, 16
    ctx->r13 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800ADDFC: blez        $t5, L_800AE228
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800ADE00: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800AE228;
    }
    // 0x800ADE00: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800ADE04: lw          $v0, 0x7C1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C1C);
    // 0x800ADE08: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800ADE0C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800ADE10: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800ADE14: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADE18: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800ADE1C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800ADE20: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800ADE24: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800ADE28: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x800ADE2C: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x800ADE30: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800ADE34: mflo        $t8
    ctx->r24 = lo;
    // 0x800ADE38: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800ADE3C: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x800ADE40: and         $t0, $t6, $t7
    ctx->r8 = ctx->r14 & ctx->r15;
    // 0x800ADE44: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800ADE48: jal         0x800707C4
    // 0x800ADE4C: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800ADE4C: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800ADE50: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800ADE54: lw          $t8, 0x7C1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7C1C);
    // 0x800ADE58: nop

    // 0x800ADE5C: lh          $a0, 0x4($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4);
    // 0x800ADE60: jal         0x800707F8
    // 0x800ADE64: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x800ADE64: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800ADE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADE6C: lwc1        $f12, 0x2A8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X2A8C);
    // 0x800ADE70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADE74: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ADE78: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800ADE7C: lwc1        $f14, 0x2A90($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X2A90);
    // 0x800ADE80: lwc1        $f16, 0x2A94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2A94);
    // 0x800ADE84: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800ADE88: lwc1        $f18, 0x2A98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2A98);
    // 0x800ADE8C: lwc1        $f20, 0x2A9C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X2A9C);
    // 0x800ADE90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADE94: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ADE98: lwc1        $f22, 0x2AA0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X2AA0);
    // 0x800ADE9C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800ADEA0: lwc1        $f24, 0x2AA4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X2AA4);
    // 0x800ADEA4: lwc1        $f26, 0x2AA8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X2AA8);
    // 0x800ADEA8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800ADEAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADEB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADEB4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800ADEB8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADEBC: addiu       $t1, $t1, 0x2C90
    ctx->r9 = ADD32(ctx->r9, 0X2C90);
    // 0x800ADEC0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800ADEC4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800ADEC8: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800ADECC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800ADED0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800ADED4: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800ADED8: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800ADEDC: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800ADEE0: addiu       $t3, $t3, 0x2AAC
    ctx->r11 = ADD32(ctx->r11, 0X2AAC);
    // 0x800ADEE4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800ADEE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ADEEC: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800ADEF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800ADEF4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800ADEF8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800ADEFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADF00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADF04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800ADF08: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADF0C: addiu       $t4, $t4, 0x7C18
    ctx->r12 = ADD32(ctx->r12, 0X7C18);
    // 0x800ADF10: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800ADF14: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800ADF18: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800ADF1C: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800ADF20: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800ADF24: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800ADF28: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800ADF2C: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x800ADF30: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800ADF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ADF38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ADF3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ADF40: nop

    // 0x800ADF44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800ADF48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADF4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADF50: nop

    // 0x800ADF54: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADF58: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ADF5C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800ADF60: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800ADF64: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800ADF68: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800ADF6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ADF70: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800ADF74: nop

    // 0x800ADF78: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800ADF7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADF80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADF84: nop

    // 0x800ADF88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADF8C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800ADF90: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800ADF94: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800ADF98: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x800ADF9C: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800ADFA0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ADFA4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ADFA8: nop

    // 0x800ADFAC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800ADFB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADFB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADFB8: nop

    // 0x800ADFBC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADFC0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ADFC4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800ADFC8: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800ADFCC: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x800ADFD0: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800ADFD4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ADFD8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800ADFDC: nop

    // 0x800ADFE0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800ADFE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ADFE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ADFEC: nop

    // 0x800ADFF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800ADFF4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800ADFF8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800ADFFC: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800AE000: sh          $t7, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r15;
    // 0x800AE004: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AE008: mul.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800AE00C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE010: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AE014: nop

    // 0x800AE018: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AE01C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE020: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE024: nop

    // 0x800AE028: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE02C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AE030: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AE034: mul.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800AE038: sh          $t5, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r13;
    // 0x800AE03C: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800AE040: lui         $t5, 0x4002
    ctx->r13 = S32(0X4002 << 16);
    // 0x800AE044: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800AE048: ori         $t8, $t8, 0x102
    ctx->r24 = ctx->r24 | 0X102;
    // 0x800AE04C: ori         $t5, $t5, 0x300
    ctx->r13 = ctx->r13 | 0X300;
    // 0x800AE050: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE054: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AE058: nop

    // 0x800AE05C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AE060: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE064: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE068: nop

    // 0x800AE06C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE070: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AE074: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AE078: sh          $t6, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r14;
    // 0x800AE07C: lw          $t7, 0x7C0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7C0C);
    // 0x800AE080: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AE084: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE088: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AE08C: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x800AE090: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x800AE094: sh          $s1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r17;
    // 0x800AE098: sh          $t2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r10;
    // 0x800AE09C: sh          $s1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r17;
    // 0x800AE0A0: sh          $s2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r18;
    // 0x800AE0A4: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x800AE0A8: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x800AE0AC: sh          $s2, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r18;
    // 0x800AE0B0: sh          $t0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r8;
    // 0x800AE0B4: sh          $s2, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r18;
    // 0x800AE0B8: sh          $t0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r8;
    // 0x800AE0BC: sh          $t2, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r10;
    // 0x800AE0C0: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x800AE0C4: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800AE0C8: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x800AE0CC: lbu         $t9, 0x12($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X12);
    // 0x800AE0D0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800AE0D4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800AE0D8: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800AE0DC: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x800AE0E0: or          $t6, $t5, $t7
    ctx->r14 = ctx->r13 | ctx->r15;
    // 0x800AE0E4: lbu         $t5, 0x14($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X14);
    // 0x800AE0E8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800AE0EC: lbu         $t8, 0x15($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15);
    // 0x800AE0F0: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800AE0F4: or          $a2, $t6, $v1
    ctx->r6 = ctx->r14 | ctx->r3;
    // 0x800AE0F8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800AE0FC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800AE100: sll         $t5, $t8, 8
    ctx->r13 = S32(ctx->r24 << 8);
    // 0x800AE104: or          $a3, $t6, $t5
    ctx->r7 = ctx->r14 | ctx->r13;
    // 0x800AE108: jal         0x8007F594
    // 0x800AE10C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x800AE10C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_4:
    // 0x800AE110: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800AE114: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AE118: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AE11C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE120: lh          $a0, 0xA($s3)
    ctx->r4 = MEM_H(ctx->r19, 0XA);
    // 0x800AE124: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800AE128: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800AE12C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800AE130: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800AE134: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800AE138: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800AE13C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800AE140: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AE144: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x800AE148: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800AE14C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE150: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x800AE154: addiu       $t1, $t1, 0x2C90
    ctx->r9 = ADD32(ctx->r9, 0X2C90);
    // 0x800AE158: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800AE15C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE160: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800AE164: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE168: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800AE16C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE170: addiu       $t3, $t3, 0x2AAC
    ctx->r11 = ADD32(ctx->r11, 0X2AAC);
    // 0x800AE174: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800AE178: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE17C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AE180: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AE184: addiu       $t4, $t4, 0x7C18
    ctx->r12 = ADD32(ctx->r12, 0X7C18);
    // 0x800AE188: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE18C: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE190: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE194: andi        $t7, $t5, 0x6
    ctx->r15 = ctx->r13 & 0X6;
    // 0x800AE198: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x800AE19C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x800AE1A0: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800AE1A4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800AE1A8: ori         $t7, $t5, 0x50
    ctx->r15 = ctx->r13 | 0X50;
    // 0x800AE1AC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800AE1B0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE1B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AE1B8: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE1BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE1C0: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE1C4: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE1C8: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800AE1CC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE1D0: lui         $t6, 0x511
    ctx->r14 = S32(0X511 << 16);
    // 0x800AE1D4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE1D8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE1DC: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x800AE1E0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE1E4: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800AE1E8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AE1EC: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE1F0: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800AE1F4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE1F8: nop

    // 0x800AE1FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE200: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE204: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AE208: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE20C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AE210: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800AE214: addiu       $t5, $t9, 0x4
    ctx->r13 = ADD32(ctx->r25, 0X4);
    // 0x800AE218: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x800AE21C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AE220: sw          $t8, 0x7C0C($at)
    MEM_W(0X7C0C, ctx->r1) = ctx->r24;
    // 0x800AE224: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_800AE228:
    // 0x800AE228: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800AE22C:
    // 0x800AE22C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800AE230: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE234: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AE238: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AE23C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AE240: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AE244: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AE248: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AE24C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800AE250: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800AE254: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE258: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800AE25C: jr          $ra
    // 0x800AE260: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800AE260: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800B6F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B6F34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6F38: jr          $ra
    // 0x800B6F3C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B6F3C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void update_camera_finish_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80058B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058B8C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058B90: addiu       $s0, $s0, -0x2AF8
    ctx->r16 = ADD32(ctx->r16, -0X2AF8);
    // 0x80058B94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058B98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058B9C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80058BA0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80058BA4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80058BA8: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80058BAC: addiu       $t7, $t6, 0x200
    ctx->r15 = ADD32(ctx->r14, 0X200);
    // 0x80058BB0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80058BB4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058BB8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80058BBC: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x80058BC0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80058BC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058BC8: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x80058BCC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80058BD0: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x80058BD4: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x80058BD8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058BDC: nop

    // 0x80058BE0: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80058BE4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80058BE8: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x80058BEC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80058BF0: jal         0x800707C4
    // 0x80058BF4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80058BF4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_0:
    // 0x80058BF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058BFC: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80058C00: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80058C04: nop

    // 0x80058C08: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80058C0C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80058C10: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80058C14: nop

    // 0x80058C18: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    // 0x80058C1C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80058C20: jal         0x800707F8
    // 0x80058C24: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80058C24: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80058C28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80058C2C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058C30: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058C34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058C38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80058C3C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80058C40: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80058C44: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80058C48: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80058C4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058C50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058C54: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058C58: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058C5C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80058C60: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80058C64: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80058C68: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058C6C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058C70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80058C74: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80058C78: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80058C7C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058C80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80058C84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80058C88: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80058C8C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80058C90: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x80058C94: nop

    // 0x80058C98: bc1f        L_80058CC4
    if (!c1cs) {
        // 0x80058C9C: nop
    
            goto L_80058CC4;
    }
    // 0x80058C9C: nop

    // 0x80058CA0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058CA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058CA8: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80058CAC: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x80058CB0: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80058CB4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80058CB8: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80058CBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058CC0: nop

L_80058CC4:
    // 0x80058CC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058CC8: nop

    // 0x80058CCC: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80058CD0: nop

    // 0x80058CD4: bc1f        L_80058CF4
    if (!c1cs) {
        // 0x80058CD8: nop
    
            goto L_80058CF4;
    }
    // 0x80058CD8: nop

    // 0x80058CDC: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058CE0: nop

    // 0x80058CE4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80058CE8: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80058CEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058CF0: nop

L_80058CF4:
    // 0x80058CF4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80058CF8: nop

    // 0x80058CFC: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80058D00: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80058D04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058D08: nop

    // 0x80058D0C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80058D10: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058D14: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80058D18: jal         0x80029F18
    // 0x80058D1C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_2;
    // 0x80058D1C: nop

    after_2:
    // 0x80058D20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058D24: beq         $v0, $at, L_80058D38
    if (ctx->r2 == ctx->r1) {
        // 0x80058D28: nop
    
            goto L_80058D38;
    }
    // 0x80058D28: nop

    // 0x80058D2C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80058D30: nop

    // 0x80058D34: sh          $v0, 0x34($t1)
    MEM_H(0X34, ctx->r9) = ctx->r2;
L_80058D38:
    // 0x80058D38: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058D3C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80058D40: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80058D44: nop

    // 0x80058D48: sh          $t4, 0x196($t3)
    MEM_H(0X196, ctx->r11) = ctx->r12;
    // 0x80058D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058D50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058D54: jr          $ra
    // 0x80058D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80058D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_free_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071440: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80071444: addiu       $a1, $a1, 0x3DC8
    ctx->r5 = ADD32(ctx->r5, 0X3DC8);
    // 0x80071448: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007144C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071450: addiu       $t7, $t7, 0x35C8
    ctx->r15 = ADD32(ctx->r15, 0X35C8);
    // 0x80071454: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80071458: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8007145C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80071460: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80071464: lw          $t8, 0x3DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3DCC);
    // 0x80071468: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8007146C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80071470: jr          $ra
    // 0x80071474: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80071474: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void enable_pal_viewport_height_adjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066098: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8006609C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800660A0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800660A4: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800660A8: bne         $t8, $zero, L_800660B8
    if (ctx->r24 != 0) {
        // 0x800660AC: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800660B8;
    }
    // 0x800660AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800660B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800660B4: sb          $t7, 0xD15($at)
    MEM_B(0XD15, ctx->r1) = ctx->r15;
L_800660B8:
    // 0x800660B8: jr          $ra
    // 0x800660BC: nop

    return;
    // 0x800660BC: nop

;}
RECOMP_FUNC void mark_to_read_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EB60: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EB64: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EB68: nop

    // 0x8006EB6C: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8006EB70: jr          $ra
    // 0x8006EB74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EB74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
