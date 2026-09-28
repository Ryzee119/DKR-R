#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void init_object_water_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FC74: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC78: sw          $a1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r5;
    // 0x8000FC7C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8000FC80: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x8000FC84: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000FC88: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8000FC8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000FC90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000FC94: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8000FC98: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8000FC9C: sh          $t9, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r25;
    // 0x8000FCA0: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8000FCA4: nop

    // 0x8000FCA8: lh          $t0, 0x36($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X36);
    // 0x8000FCAC: nop

    // 0x8000FCB0: beq         $t0, $zero, L_8000FCD4
    if (ctx->r8 == 0) {
        // 0x8000FCB4: nop
    
            goto L_8000FCD4;
    }
    // 0x8000FCB4: nop

    // 0x8000FCB8: lh          $a0, 0x38($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X38);
    // 0x8000FCBC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000FCC0: jal         0x8007AE74
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x8000FCC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000FCC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FCCC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000FCD0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8000FCD4:
    // 0x8000FCD4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8000FCD8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000FCDC: sh          $t1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r9;
    // 0x8000FCE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000FCE4: sw          $t2, -0x51AC($at)
    MEM_W(-0X51AC, ctx->r1) = ctx->r10;
    // 0x8000FCE8: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
    // 0x8000FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FCF0: lh          $t4, 0x36($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X36);
    // 0x8000FCF4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8000FCF8: beq         $t4, $zero, L_8000FD18
    if (ctx->r12 == 0) {
        // 0x8000FCFC: nop
    
            goto L_8000FD18;
    }
    // 0x8000FCFC: nop

    // 0x8000FD00: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x8000FD04: nop

    // 0x8000FD08: bne         $t5, $zero, L_8000FD18
    if (ctx->r13 != 0) {
        // 0x8000FD0C: nop
    
            goto L_8000FD18;
    }
    // 0x8000FD0C: nop

    // 0x8000FD10: b           L_8000FD18
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FD18;
    // 0x8000FD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD18:
    // 0x8000FD18: jr          $ra
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000FD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void rumble_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007267C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072680: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072684: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072688: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007268C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072690: bltz        $t7, L_800726F8
    if (SIGNED(ctx->r15) < 0) {
        // 0x80072694: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800726F8;
    }
    // 0x80072694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072698: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8007269C: beq         $at, $zero, L_800726FC
    if (ctx->r1 == 0) {
        // 0x800726A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800726FC;
    }
    // 0x800726A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800726A4: jal         0x80072250
    // 0x800726A8: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800726A8: nop

    after_0:
    // 0x800726AC: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800726B0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800726B4: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800726B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800726BC: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x800726C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800726C4: addiu       $a1, $a1, 0x41E7
    ctx->r5 = ADD32(ctx->r5, 0X41E7);
    // 0x800726C8: addiu       $t4, $t4, 0x41B8
    ctx->r12 = ADD32(ctx->r12, 0X41B8);
    // 0x800726CC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800726D0: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800726D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800726D8: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800726DC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800726E0: sllv        $t1, $t0, $t8
    ctx->r9 = S32(ctx->r8 << (ctx->r24 & 31));
    // 0x800726E4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x800726E8: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
    // 0x800726EC: sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    // 0x800726F0: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x800726F4: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_800726F8:
    // 0x800726F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800726FC:
    // 0x800726FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072700: jr          $ra
    // 0x80072704: nop

    return;
    // 0x80072704: nop

;}
RECOMP_FUNC void racer_boss_sound_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CA84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005CA88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CA8C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8005CA90: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8005CA94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005CA98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8005CA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CAA0: jal         0x8006F94C
    // 0x8005CAA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CAA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CAA8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CAAC: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CAB0: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CAB4: bne         $t0, $zero, L_8005CAC0
    if (ctx->r8 != 0) {
        // 0x8005CAB8: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CAC0;
    }
    // 0x8005CAB8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CABC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CAC0:
    // 0x8005CAC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CAC4: lw          $t7, -0x2A38($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A38);
    // 0x8005CAC8: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8005CACC: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8005CAD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CAD4: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CAD8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005CADC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005CAE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8005CAE4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005CAE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005CAEC: jal         0x80009558
    // 0x8005CAF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8005CAF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8005CAF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005CAF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005CAFC: jr          $ra
    // 0x8005CB00: nop

    return;
    // 0x8005CB00: nop

;}
RECOMP_FUNC void menu_magic_codes_list_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A928: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008A92C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A930: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008A934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008A938: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8008A93C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008A940: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008A944: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008A948: beq         $v0, $zero, L_8008A988
    if (ctx->r2 == 0) {
        // 0x8008A94C: sw          $zero, 0x48($sp)
        MEM_W(0X48, ctx->r29) = 0;
            goto L_8008A988;
    }
    // 0x8008A94C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008A950: blez        $v0, L_8008A974
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A954: subu        $t7, $v0, $a0
        ctx->r15 = SUB32(ctx->r2, ctx->r4);
            goto L_8008A974;
    }
    // 0x8008A954: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008A958: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x8008A95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A960: sw          $t6, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r14;
    // 0x8008A964: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A968: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008A96C: b           L_8008A988
    // 0x8008A970: nop

        goto L_8008A988;
    // 0x8008A970: nop

L_8008A974:
    // 0x8008A974: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A978: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
    // 0x8008A97C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A980: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008A984: nop

L_8008A988:
    // 0x8008A988: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A98C: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8008A990: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A994: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8008A998: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8008A99C: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x8008A9A0: bne         $at, $zero, L_8008A9BC
    if (ctx->r1 != 0) {
        // 0x8008A9A4: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8008A9BC;
    }
    // 0x8008A9A4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008A9A8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008A9AC: beq         $at, $zero, L_8008A9BC
    if (ctx->r1 == 0) {
        // 0x8008A9B0: nop
    
            goto L_8008A9BC;
    }
    // 0x8008A9B0: nop

    // 0x8008A9B4: jal         0x8008A56C
    // 0x8008A9B8: nop

    cheatlist_render(rdram, ctx);
        goto after_0;
    // 0x8008A9B8: nop

    after_0:
L_8008A9BC:
    // 0x8008A9BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008A9C0: lw          $t2, 0x63C4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X63C4);
    // 0x8008A9C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008A9C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A9CC: bne         $t2, $zero, L_8008AA3C
    if (ctx->r10 != 0) {
        // 0x8008A9D0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8008AA3C;
    }
    // 0x8008A9D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008A9D4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008A9D8: lw          $t3, -0xB84($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB84);
    // 0x8008A9DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008A9E0: bne         $t3, $zero, L_8008AA3C
    if (ctx->r11 != 0) {
        // 0x8008A9E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008AA3C;
    }
    // 0x8008A9E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A9E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A9EC: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x8008A9F0: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
    // 0x8008A9F4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8008A9F8:
    // 0x8008A9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008A9FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8008AA00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008AA04: jal         0x8006A554
    // 0x8008AA08: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008AA08: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x8008AA0C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8008AA10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AA14: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8008AA18: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008AA1C: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8008AA20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AA24: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x8008AA28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AA2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008AA30: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8008AA34: bne         $s0, $s1, L_8008A9F8
    if (ctx->r16 != ctx->r17) {
        // 0x8008AA38: addu        $s2, $s2, $t5
        ctx->r18 = ADD32(ctx->r18, ctx->r13);
            goto L_8008A9F8;
    }
    // 0x8008AA38: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
L_8008AA3C:
    // 0x8008AA3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AA40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AA44: lw          $v0, -0x264($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X264);
    // 0x8008AA48: addiu       $t0, $t0, 0x6C80
    ctx->r8 = ADD32(ctx->r8, 0X6C80);
    // 0x8008AA4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AA50: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8008AA54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008AA58: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8008AA5C:
    // 0x8008AA5C: and         $t6, $s1, $v0
    ctx->r14 = ctx->r17 & ctx->r2;
    // 0x8008AA60: beq         $t6, $zero, L_8008AA78
    if (ctx->r14 == 0) {
        // 0x8008AA64: sll         $t9, $s1, 1
        ctx->r25 = S32(ctx->r17 << 1);
            goto L_8008AA78;
    }
    // 0x8008AA64: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x8008AA68: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8008AA6C: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008AA70: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x8008AA74: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8008AA78:
    // 0x8008AA78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AA7C: bne         $s0, $v1, L_8008AA5C
    if (ctx->r16 != ctx->r3) {
        // 0x8008AA80: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008AA5C;
    }
    // 0x8008AA80: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008AA84: bltz        $a2, L_8008AA90
    if (SIGNED(ctx->r6) < 0) {
        // 0x8008AA88: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8008AA90;
    }
    // 0x8008AA88: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008AA8C: blez        $a2, L_8008ABB0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008AA90: addiu       $s0, $s0, 0x6C46
        ctx->r16 = ADD32(ctx->r16, 0X6C46);
            goto L_8008ABB0;
    }
L_8008AA90:
    // 0x8008AA90: addiu       $s0, $s0, 0x6C46
    ctx->r16 = ADD32(ctx->r16, 0X6C46);
    // 0x8008AA94: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008AA98: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008AA9C: beq         $a3, $t1, L_8008ABB0
    if (ctx->r7 == ctx->r9) {
        // 0x8008AAA0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008ABB0;
    }
    // 0x8008AAA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AAA4: jal         0x80001D04
    // 0x8008AAA8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008AAA8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008AAAC: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8008AAB0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008AAB4: addiu       $t0, $t0, 0x6C80
    ctx->r8 = ADD32(ctx->r8, 0X6C80);
    // 0x8008AAB8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008AABC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008AAC0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008AAC4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008AAC8: addiu       $v0, $v0, -0x268
    ctx->r2 = ADD32(ctx->r2, -0X268);
    // 0x8008AACC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8008AAD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008AAD4: sllv        $s1, $t6, $t5
    ctx->r17 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8008AAD8: xor         $t8, $t7, $s1
    ctx->r24 = ctx->r15 ^ ctx->r17;
    // 0x8008AADC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008AAE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AAE4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8008AAE8: jal         0x8008A8F8
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    cheatlist_exclusive(rdram, ctx);
        goto after_3;
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_3:
    // 0x8008AAF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AAF4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8008AAF8: jal         0x8008A8F8
    // 0x8008AAFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    cheatlist_exclusive(rdram, ctx);
        goto after_4;
    // 0x8008AAFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x8008AB00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB04: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // 0x8008AB08: jal         0x8008A8F8
    // 0x8008AB0C: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    cheatlist_exclusive(rdram, ctx);
        goto after_5;
    // 0x8008AB0C: addiu       $a2, $zero, 0x6080
    ctx->r6 = ADD32(0, 0X6080);
    after_5:
    // 0x8008AB10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB14: addiu       $a1, $zero, 0x6080
    ctx->r5 = ADD32(0, 0X6080);
    // 0x8008AB18: jal         0x8008A8F8
    // 0x8008AB1C: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    cheatlist_exclusive(rdram, ctx);
        goto after_6;
    // 0x8008AB1C: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_6:
    // 0x8008AB20: lui         $a2, 0x1F
    ctx->r6 = S32(0X1F << 16);
    // 0x8008AB24: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB2C: jal         0x8008A8F8
    // 0x8008AB30: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_7;
    // 0x8008AB30: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_7:
    // 0x8008AB34: lui         $a1, 0x1F
    ctx->r5 = S32(0X1F << 16);
    // 0x8008AB38: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8008AB3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB40: jal         0x8008A8F8
    // 0x8008AB44: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    cheatlist_exclusive(rdram, ctx);
        goto after_8;
    // 0x8008AB44: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_8:
    // 0x8008AB48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB4C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8008AB50: jal         0x8008A8F8
    // 0x8008AB54: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_9;
    // 0x8008AB54: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    after_9:
    // 0x8008AB58: lui         $a2, 0xE
    ctx->r6 = S32(0XE << 16);
    // 0x8008AB5C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AB60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB64: jal         0x8008A8F8
    // 0x8008AB68: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_10;
    // 0x8008AB68: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_10:
    // 0x8008AB6C: lui         $a2, 0xD
    ctx->r6 = S32(0XD << 16);
    // 0x8008AB70: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AB74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB78: jal         0x8008A8F8
    // 0x8008AB7C: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_11;
    // 0x8008AB7C: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_11:
    // 0x8008AB80: lui         $a2, 0xB
    ctx->r6 = S32(0XB << 16);
    // 0x8008AB84: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AB88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008AB8C: jal         0x8008A8F8
    // 0x8008AB90: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_12;
    // 0x8008AB90: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_12:
    // 0x8008AB94: lui         $a2, 0x7
    ctx->r6 = S32(0X7 << 16);
    // 0x8008AB98: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8008AB9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008ABA0: jal         0x8008A8F8
    // 0x8008ABA4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    cheatlist_exclusive(rdram, ctx);
        goto after_13;
    // 0x8008ABA4: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_13:
    // 0x8008ABA8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008ABAC: nop

L_8008ABB0:
    // 0x8008ABB0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008ABB4: addiu       $s0, $s0, 0x6C46
    ctx->r16 = ADD32(ctx->r16, 0X6C46);
    // 0x8008ABB8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008ABBC: bgez        $s2, L_8008ABEC
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8008ABC0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008ABEC;
    }
    // 0x8008ABC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008ABC4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8008ABC8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8008ABCC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008ABD0: nop

    // 0x8008ABD4: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ABD8: beq         $at, $zero, L_8008ABEC
    if (ctx->r1 == 0) {
        // 0x8008ABDC: nop
    
            goto L_8008ABEC;
    }
    // 0x8008ABDC: nop

    // 0x8008ABE0: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x8008ABE4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008ABE8: nop

L_8008ABEC:
    // 0x8008ABEC: blez        $s2, L_8008AC18
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008ABF0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008AC18;
    }
    // 0x8008ABF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008ABF4: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8008ABF8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8008ABFC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008AC00: nop

    // 0x8008AC04: bgez        $v0, L_8008AC18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008AC08: nop
    
            goto L_8008AC18;
    }
    // 0x8008AC08: nop

    // 0x8008AC0C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008AC10: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8008AC14: nop

L_8008AC18:
    // 0x8008AC18: addiu       $a1, $a1, 0x63E0
    ctx->r5 = ADD32(ctx->r5, 0X63E0);
    // 0x8008AC1C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008AC20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008AC24: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8008AC28: beq         $at, $zero, L_8008AC38
    if (ctx->r1 == 0) {
        // 0x8008AC2C: nop
    
            goto L_8008AC38;
    }
    // 0x8008AC2C: nop

    // 0x8008AC30: b           L_8008AC58
    // 0x8008AC34: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008AC58;
    // 0x8008AC34: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8008AC38:
    // 0x8008AC38: lw          $a0, 0x6C70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C70);
    // 0x8008AC3C: nop

    // 0x8008AC40: addu        $t2, $v1, $a0
    ctx->r10 = ADD32(ctx->r3, ctx->r4);
    // 0x8008AC44: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008AC48: bne         $at, $zero, L_8008AC58
    if (ctx->r1 != 0) {
        // 0x8008AC4C: subu        $t3, $v0, $a0
        ctx->r11 = SUB32(ctx->r2, ctx->r4);
            goto L_8008AC58;
    }
    // 0x8008AC4C: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x8008AC50: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008AC54: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_8008AC58:
    // 0x8008AC58: beq         $a2, $v0, L_8008AC74
    if (ctx->r6 == ctx->r2) {
        // 0x8008AC5C: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008AC74;
    }
    // 0x8008AC5C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008AC60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AC64: jal         0x80001D04
    // 0x8008AC68: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008AC68: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_14:
    // 0x8008AC6C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AC70: nop

L_8008AC74:
    // 0x8008AC74: andi        $t6, $s3, 0x9000
    ctx->r14 = ctx->r19 & 0X9000;
    // 0x8008AC78: beq         $t6, $zero, L_8008AC94
    if (ctx->r14 == 0) {
        // 0x8008AC7C: andi        $t8, $s3, 0x4000
        ctx->r24 = ctx->r19 & 0X4000;
            goto L_8008AC94;
    }
    // 0x8008AC7C: andi        $t8, $s3, 0x4000
    ctx->r24 = ctx->r19 & 0X4000;
    // 0x8008AC80: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8008AC84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008AC88: bne         $a3, $t5, L_8008AC94
    if (ctx->r7 != ctx->r13) {
        // 0x8008AC8C: nop
    
            goto L_8008AC94;
    }
    // 0x8008AC8C: nop

    // 0x8008AC90: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8008AC94:
    // 0x8008AC94: beq         $t8, $zero, L_8008ACA0
    if (ctx->r24 == 0) {
        // 0x8008AC98: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8008ACA0;
    }
    // 0x8008AC98: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008AC9C: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
L_8008ACA0:
    // 0x8008ACA0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008ACA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ACA8: beq         $t1, $zero, L_8008ACC8
    if (ctx->r9 == 0) {
        // 0x8008ACAC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008ACC8;
    }
    // 0x8008ACAC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008ACB0: sw          $t1, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r9;
    // 0x8008ACB4: jal         0x800C01D8
    // 0x8008ACB8: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8008ACB8: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_15:
    // 0x8008ACBC: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008ACC0: jal         0x80001D04
    // 0x8008ACC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x8008ACC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_8008ACC8:
    // 0x8008ACC8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008ACCC: lw          $t2, -0xB84($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB84);
    // 0x8008ACD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008ACD4: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x8008ACD8: beq         $at, $zero, L_8008ACF8
    if (ctx->r1 == 0) {
        // 0x8008ACDC: nop
    
            goto L_8008ACF8;
    }
    // 0x8008ACDC: nop

    // 0x8008ACE0: jal         0x8008AD1C
    // 0x8008ACE4: nop

    cheatlist_free(rdram, ctx);
        goto after_17;
    // 0x8008ACE4: nop

    after_17:
    // 0x8008ACE8: jal         0x800813D0
    // 0x8008ACEC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008ACEC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_18:
    // 0x8008ACF0: b           L_8008AD00
    // 0x8008ACF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008AD00;
    // 0x8008ACF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008ACF8:
    // 0x8008ACF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008ACFC: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_8008AD00:
    // 0x8008AD00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008AD04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8008AD08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008AD0C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AD10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8008AD14: jr          $ra
    // 0x8008AD18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8008AD18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void hud_bananas(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4154: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A4158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A415C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4160: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A4164: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A4168: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800A416C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4170: beq         $v0, $at, L_800A4220
    if (ctx->r2 == ctx->r1) {
        // 0x800A4174: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A4220;
    }
    // 0x800A4174: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A4178: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x800A417C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A4180: blez        $v1, L_800A41C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A4184: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800A41C0;
    }
    // 0x800A4184: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A4188: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800A418C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A4190: lbu         $t9, 0x2794($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2794);
    // 0x800A4194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A4198: beq         $t9, $at, L_800A41C0
    if (ctx->r25 == ctx->r1) {
        // 0x800A419C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A41C0;
    }
    // 0x800A419C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A41A0: lw          $t2, 0x6D60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D60);
    // 0x800A41A4: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A41A8: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A41AC: nop

    // 0x800A41B0: beq         $v0, $at, L_800A41C0
    if (ctx->r2 == ctx->r1) {
        // 0x800A41B4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A41C0;
    }
    // 0x800A41B4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A41B8: bne         $v0, $at, L_800A45E4
    if (ctx->r2 != ctx->r1) {
        // 0x800A41BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A45E4;
    }
    // 0x800A41BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A41C0:
    // 0x800A41C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A41C4: nop

    // 0x800A41C8: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A41CC: nop

    // 0x800A41D0: bne         $t4, $zero, L_800A45E4
    if (ctx->r12 != 0) {
        // 0x800A41D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A45E4;
    }
    // 0x800A41D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A41D8: blez        $v1, L_800A4220
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A41DC: nop
    
            goto L_800A4220;
    }
    // 0x800A41DC: nop

    // 0x800A41E0: lb          $v0, 0x193($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X193);
    // 0x800A41E4: nop

    // 0x800A41E8: blez        $v0, L_800A4220
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A41EC: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_800A4220;
    }
    // 0x800A41EC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A41F0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800A41F4: lw          $t7, 0x128($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X128);
    // 0x800A41F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A41FC: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A4200: beq         $at, $zero, L_800A4220
    if (ctx->r1 == 0) {
        // 0x800A4204: nop
    
            goto L_800A4220;
    }
    // 0x800A4204: nop

    // 0x800A4208: lw          $t8, 0x6D60($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D60);
    // 0x800A420C: nop

    // 0x800A4210: lb          $t9, 0x4C($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4C);
    // 0x800A4214: nop

    // 0x800A4218: andi        $t2, $t9, 0x40
    ctx->r10 = ctx->r25 & 0X40;
    // 0x800A421C: beq         $t2, $zero, L_800A45E0
    if (ctx->r10 == 0) {
        // 0x800A4220: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A45E0;
    }
L_800A4220:
    // 0x800A4220: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A4224: addiu       $s0, $s0, 0x6CDC
    ctx->r16 = ADD32(ctx->r16, 0X6CDC);
    // 0x800A4228: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A422C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4230: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4234: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4238: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A423C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4240: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4244: jal         0x800AA600
    // 0x800A4248: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4248: addiu       $a3, $a3, 0x240
    ctx->r7 = ADD32(ctx->r7, 0X240);
    after_0:
    // 0x800A424C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A4250: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4254: lb          $a0, 0x185($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X185);
    // 0x800A4258: nop

    // 0x800A425C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x800A4260: lb          $a1, 0xFA($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XFA);
    // 0x800A4264: lbu         $v1, 0xF9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XF9);
    // 0x800A4268: bne         $a1, $zero, L_800A4294
    if (ctx->r5 != 0) {
        // 0x800A426C: nop
    
            goto L_800A4294;
    }
    // 0x800A426C: nop

    // 0x800A4270: lb          $t4, 0xFB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0XFB);
    // 0x800A4274: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A4278: beq         $a0, $t4, L_800A4294
    if (ctx->r4 == ctx->r12) {
        // 0x800A427C: nop
    
            goto L_800A4294;
    }
    // 0x800A427C: nop

    // 0x800A4280: sb          $t3, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r11;
    // 0x800A4284: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A4288: lb          $t5, 0x185($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X185);
    // 0x800A428C: b           L_800A4320
    // 0x800A4290: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
        goto L_800A4320;
    // 0x800A4290: sb          $t5, 0xFB($t6)
    MEM_B(0XFB, ctx->r14) = ctx->r13;
L_800A4294:
    // 0x800A4294: beq         $a1, $zero, L_800A4320
    if (ctx->r5 == 0) {
        // 0x800A4298: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800A4320;
    }
    // 0x800A4298: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A429C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A42A0: nop

    // 0x800A42A4: swc1        $f4, 0x388($v0)
    MEM_W(0X388, ctx->r2) = ctx->f4.u32l;
    // 0x800A42A8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A42AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A42B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A42B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A42B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A42BC: lh          $t2, 0xF8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XF8);
    // 0x800A42C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800A42C4: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800A42C8: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x800A42CC: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800A42D0: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A42D4: beq         $at, $zero, L_800A4320
    if (ctx->r1 == 0) {
        // 0x800A42D8: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800A4320;
    }
    // 0x800A42D8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800A42DC: lb          $t3, 0xFA($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XFA);
    // 0x800A42E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A42E4: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800A42E8: sb          $t5, 0xFA($v0)
    MEM_B(0XFA, ctx->r2) = ctx->r13;
    // 0x800A42EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A42F0: nop

    // 0x800A42F4: lb          $t6, 0xFA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XFA);
    // 0x800A42F8: nop

    // 0x800A42FC: bne         $t6, $zero, L_800A4320
    if (ctx->r14 != 0) {
        // 0x800A4300: nop
    
            goto L_800A4320;
    }
    // 0x800A4300: nop

    // 0x800A4304: sb          $a0, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r4;
    // 0x800A4308: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A430C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800A4310: sb          $t7, 0x39A($t8)
    MEM_B(0X39A, ctx->r24) = ctx->r15;
    // 0x800A4314: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A4318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A431C: sh          $a0, 0x398($t9)
    MEM_H(0X398, ctx->r25) = ctx->r4;
L_800A4320:
    // 0x800A4320: bne         $v1, $zero, L_800A4444
    if (ctx->r3 != 0) {
        // 0x800A4324: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A4444;
    }
    // 0x800A4324: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A4328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A432C: jal         0x8007BF1C
    // 0x800A4330: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A4330: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A4334: jal         0x80066098
    // 0x800A4338: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_2;
    // 0x800A4338: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A433C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4340: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4344: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4348: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A434C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4350: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4354: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4358: jal         0x800AA600
    // 0x800A435C: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A435C: addiu       $a3, $a3, 0x360
    ctx->r7 = ADD32(ctx->r7, 0X360);
    after_3:
    // 0x800A4360: jal         0x80066098
    // 0x800A4364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_4;
    // 0x800A4364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A4368: jal         0x8007BF1C
    // 0x800A436C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A436C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A4370: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800A4374: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A4378: nop

    // 0x800A437C: sh          $t2, 0xF8($t4)
    MEM_H(0XF8, ctx->r12) = ctx->r10;
    // 0x800A4380: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A4384: nop

    // 0x800A4388: lb          $t3, 0x39B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X39B);
    // 0x800A438C: nop

    // 0x800A4390: beq         $t3, $zero, L_800A44C8
    if (ctx->r11 == 0) {
        // 0x800A4394: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_800A44C8;
    }
    // 0x800A4394: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4398: lb          $t5, 0x39A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X39A);
    // 0x800A439C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A43A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A43A4: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A43A8: sb          $t7, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r15;
    // 0x800A43AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A43B0: nop

    // 0x800A43B4: lb          $t8, 0x39A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X39A);
    // 0x800A43B8: nop

    // 0x800A43BC: bgez        $t8, L_800A4404
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A43C0: nop
    
            goto L_800A4404;
    }
    // 0x800A43C0: nop

    // 0x800A43C4: sb          $a0, 0x39A($v0)
    MEM_B(0X39A, ctx->r2) = ctx->r4;
    // 0x800A43C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A43CC: nop

    // 0x800A43D0: lh          $v1, 0x398($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X398);
    // 0x800A43D4: nop

    // 0x800A43D8: bne         $a0, $v1, L_800A4400
    if (ctx->r4 != ctx->r3) {
        // 0x800A43DC: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_800A4400;
    }
    // 0x800A43DC: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x800A43E0: sh          $zero, 0x398($v0)
    MEM_H(0X398, ctx->r2) = 0;
    // 0x800A43E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A43E8: nop

    // 0x800A43EC: lb          $t9, 0x39B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X39B);
    // 0x800A43F0: nop

    // 0x800A43F4: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800A43F8: b           L_800A4404
    // 0x800A43FC: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
        goto L_800A4404;
    // 0x800A43FC: sb          $t2, 0x39B($v0)
    MEM_B(0X39B, ctx->r2) = ctx->r10;
L_800A4400:
    // 0x800A4400: sh          $t4, 0x398($v0)
    MEM_H(0X398, ctx->r2) = ctx->r12;
L_800A4404:
    // 0x800A4404: jal         0x80066098
    // 0x800A4408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_6;
    // 0x800A4408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A440C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4410: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4414: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4418: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A441C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4420: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4424: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4428: jal         0x800AA600
    // 0x800A442C: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A442C: addiu       $a3, $a3, 0x380
    ctx->r7 = ADD32(ctx->r7, 0X380);
    after_7:
    // 0x800A4430: jal         0x80066098
    // 0x800A4434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A4434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A4438: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A443C: b           L_800A44C8
    // 0x800A4440: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
        goto L_800A44C8;
    // 0x800A4440: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A4444:
    // 0x800A4444: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A4448: addiu       $t3, $v0, 0x80
    ctx->r11 = ADD32(ctx->r2, 0X80);
    // 0x800A444C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A4450: jal         0x80068508
    // 0x800A4454: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A4454: sh          $t3, 0xF8($t5)
    MEM_H(0XF8, ctx->r13) = ctx->r11;
    after_9:
    // 0x800A4458: jal         0x8007BF1C
    // 0x800A445C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_10;
    // 0x800A445C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A4460: jal         0x80066098
    // 0x800A4464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_11;
    // 0x800A4464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x800A4468: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A446C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4470: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4474: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4478: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A447C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4480: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4484: jal         0x800AA600
    // 0x800A4488: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A4488: addiu       $a3, $a3, 0xE0
    ctx->r7 = ADD32(ctx->r7, 0XE0);
    after_12:
    // 0x800A448C: jal         0x8007BF1C
    // 0x800A4490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x800A4490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A4494: jal         0x80066098
    // 0x800A4498: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_14;
    // 0x800A4498: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A449C: jal         0x80068508
    // 0x800A44A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A44A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x800A44A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A44A8: nop

    // 0x800A44AC: lh          $t6, 0xF8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XF8);
    // 0x800A44B0: nop

    // 0x800A44B4: addiu       $t7, $t6, -0x80
    ctx->r15 = ADD32(ctx->r14, -0X80);
    // 0x800A44B8: sh          $t7, 0xF8($v0)
    MEM_H(0XF8, ctx->r2) = ctx->r15;
    // 0x800A44BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A44C0: nop

    // 0x800A44C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_800A44C8:
    // 0x800A44C8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800A44CC: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A44D0: bne         $t0, $zero, L_800A44DC
    if (ctx->r8 != 0) {
        // 0x800A44D4: nop
    
            goto L_800A44DC;
    }
    // 0x800A44D4: nop

    // 0x800A44D8: break       7
    do_break(2148156632);
L_800A44DC:
    // 0x800A44DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A44E0: bne         $t0, $at, L_800A44F4
    if (ctx->r8 != ctx->r1) {
        // 0x800A44E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A44F4;
    }
    // 0x800A44E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A44E8: bne         $t1, $at, L_800A44F4
    if (ctx->r9 != ctx->r1) {
        // 0x800A44EC: nop
    
            goto L_800A44F4;
    }
    // 0x800A44EC: nop

    // 0x800A44F0: break       6
    do_break(2148156656);
L_800A44F4:
    // 0x800A44F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800A44F8: beq         $v1, $zero, L_800A4564
    if (ctx->r3 == 0) {
        // 0x800A44FC: nop
    
            goto L_800A4564;
    }
    // 0x800A44FC: nop

    // 0x800A4500: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4504: sh          $v1, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r3;
    // 0x800A4508: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A450C: bne         $t0, $zero, L_800A4518
    if (ctx->r8 != 0) {
        // 0x800A4510: nop
    
            goto L_800A4518;
    }
    // 0x800A4510: nop

    // 0x800A4514: break       7
    do_break(2148156692);
L_800A4518:
    // 0x800A4518: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A451C: bne         $t0, $at, L_800A4530
    if (ctx->r8 != ctx->r1) {
        // 0x800A4520: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A4530;
    }
    // 0x800A4520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4524: bne         $t1, $at, L_800A4530
    if (ctx->r9 != ctx->r1) {
        // 0x800A4528: nop
    
            goto L_800A4530;
    }
    // 0x800A4528: nop

    // 0x800A452C: break       6
    do_break(2148156716);
L_800A4530:
    // 0x800A4530: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4534: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4538: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A453C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4540: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4544: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4548: mfhi        $t8
    ctx->r24 = hi;
    // 0x800A454C: sh          $t8, 0x138($t9)
    MEM_H(0X138, ctx->r25) = ctx->r24;
    // 0x800A4550: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A4554: jal         0x800AA600
    // 0x800A4558: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A4558: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
    after_16:
    // 0x800A455C: b           L_800A459C
    // 0x800A4560: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_800A459C;
    // 0x800A4560: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A4564:
    // 0x800A4564: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800A4568: bne         $t0, $zero, L_800A4574
    if (ctx->r8 != 0) {
        // 0x800A456C: nop
    
            goto L_800A4574;
    }
    // 0x800A456C: nop

    // 0x800A4570: break       7
    do_break(2148156784);
L_800A4574:
    // 0x800A4574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4578: bne         $t0, $at, L_800A458C
    if (ctx->r8 != ctx->r1) {
        // 0x800A457C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A458C;
    }
    // 0x800A457C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A4580: bne         $t1, $at, L_800A458C
    if (ctx->r9 != ctx->r1) {
        // 0x800A4584: nop
    
            goto L_800A458C;
    }
    // 0x800A4584: nop

    // 0x800A4588: break       6
    do_break(2148156808);
L_800A458C:
    // 0x800A458C: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A4590: sh          $t2, 0x118($v0)
    MEM_H(0X118, ctx->r2) = ctx->r10;
    // 0x800A4594: nop

    // 0x800A4598: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800A459C:
    // 0x800A459C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A45A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A45A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A45A8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A45AC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A45B0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A45B4: jal         0x800AA600
    // 0x800A45B8: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    hud_element_render(rdram, ctx);
        goto after_17;
    // 0x800A45B8: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
    after_17:
    // 0x800A45BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A45C0: lw          $v1, 0x6CFC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CFC);
    // 0x800A45C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A45C8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800A45CC: sw          $t4, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r12;
    // 0x800A45D0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A45D4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A45D8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A45DC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800A45E0:
    // 0x800A45E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A45E4:
    // 0x800A45E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A45E8: jr          $ra
    // 0x800A45EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800A45EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_current_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5050: blez        $a0, L_800C508C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5054: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C508C;
    }
    // 0x800C5054: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5058: beq         $at, $zero, L_800C508C
    if (ctx->r1 == 0) {
        // 0x800C505C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C508C;
    }
    // 0x800C505C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5060: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5064: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C5068: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C506C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5070: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5074: sb          $a1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r5;
    // 0x800C5078: sb          $a2, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r6;
    // 0x800C507C: sb          $a3, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r7;
    // 0x800C5080: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5084: nop

    // 0x800C5088: sb          $t8, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r24;
L_800C508C:
    // 0x800C508C: jr          $ra
    // 0x800C5090: nop

    return;
    // 0x800C5090: nop

;}
RECOMP_FUNC void obj_init_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037D58: jr          $ra
    // 0x80037D5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037D5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80014090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014098: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001409C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800140A0: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800140A4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800140A8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800140AC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800140B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800140B4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800140B8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800140BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800140C0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800140C4: lb          $t6, 0x74($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X74);
    // 0x800140C8: lb          $t9, 0x75($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X75);
    // 0x800140CC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140D0: lbu         $v1, 0x73($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X73);
    // 0x800140D4: lbu         $s5, 0x72($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X72);
    // 0x800140D8: or          $ra, $a0, $zero
    ctx->r31 = ctx->r4 | 0;
    // 0x800140DC: mflo        $s0
    ctx->r16 = lo;
    // 0x800140E0: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x800140E4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800140E8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800140EC: mflo        $s1
    ctx->r17 = lo;
    // 0x800140F0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x800140F4: beq         $v1, $a2, L_80014110
    if (ctx->r3 == ctx->r6) {
        // 0x800140F8: sra         $s1, $t6, 16
        ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80014110;
    }
    // 0x800140F8: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800140FC: lb          $t8, 0x55($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X55);
    // 0x80014100: nop

    // 0x80014104: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80014108: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001410C: nop
    
            goto L_80014288;
    }
    // 0x8001410C: nop

L_80014110:
    // 0x80014110: bne         $v1, $a2, L_80014124
    if (ctx->r3 != ctx->r6) {
        // 0x80014114: addiu       $fp, $v1, 0x1
        ctx->r30 = ADD32(ctx->r3, 0X1);
            goto L_80014124;
    }
    // 0x80014114: addiu       $fp, $v1, 0x1
    ctx->r30 = ADD32(ctx->r3, 0X1);
    // 0x80014118: lb          $fp, 0x55($v0)
    ctx->r30 = MEM_B(ctx->r2, 0X55);
    // 0x8001411C: b           L_80014124
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80014124;
    // 0x80014120: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80014124:
    // 0x80014124: slt         $at, $v1, $fp
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80014128: beq         $at, $zero, L_80014288
    if (ctx->r1 == 0) {
        // 0x8001412C: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_80014288;
    }
    // 0x8001412C: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x80014130: sll         $s6, $v1, 2
    ctx->r22 = S32(ctx->r3 << 2);
L_80014134:
    // 0x80014134: lw          $t9, 0x68($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X68);
    // 0x80014138: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001413C: addu        $t6, $t9, $s6
    ctx->r14 = ADD32(ctx->r25, ctx->r22);
    // 0x80014140: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014144: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x80014148: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001414C: nop

    // 0x80014150: lh          $t7, 0x22($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X22);
    // 0x80014154: nop

    // 0x80014158: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001415C: beq         $at, $zero, L_80014280
    if (ctx->r1 == 0) {
        // 0x80014160: nop
    
            goto L_80014280;
    }
    // 0x80014160: nop

    // 0x80014164: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80014168: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001416C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80014170: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80014174: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80014178: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8001417C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80014180: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80014184: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80014188: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001418C: blez        $v1, L_80014280
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80014190: sra         $s4, $t7, 16
        ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80014280;
    }
    // 0x80014190: sra         $s4, $t7, 16
    ctx->r20 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80014194: lw          $t1, 0x38($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X38);
    // 0x80014198: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001419C:
    // 0x8001419C: lbu         $t9, 0x0($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X0);
    // 0x800141A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800141A4: bne         $s5, $t9, L_80014274
    if (ctx->r21 != ctx->r25) {
        // 0x800141A8: slt         $at, $s2, $v1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014274;
    }
    // 0x800141A8: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800141AC: lh          $a1, 0x4($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X4);
    // 0x800141B0: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x800141B4: addiu       $t2, $s3, -0x1
    ctx->r10 = ADD32(ctx->r19, -0X1);
    // 0x800141B8: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800141BC: beq         $at, $zero, L_80014270
    if (ctx->r1 == 0) {
        // 0x800141C0: sll         $t7, $t2, 16
        ctx->r15 = S32(ctx->r10 << 16);
            goto L_80014270;
    }
    // 0x800141C0: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x800141C4: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x800141C8: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800141CC: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800141D0: sra         $t2, $t7, 16
    ctx->r10 = S32(SIGNED(ctx->r15) >> 16);
L_800141D4:
    // 0x800141D4: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x800141D8: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x800141DC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800141E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800141E4: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x800141E8: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800141EC: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800141F0: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800141F4: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x800141F8: subu        $t1, $t9, $v1
    ctx->r9 = SUB32(ctx->r25, ctx->r3);
    // 0x800141FC: subu        $a3, $t7, $v1
    ctx->r7 = SUB32(ctx->r15, ctx->r3);
    // 0x80014200: addu        $t9, $v1, $s0
    ctx->r25 = ADD32(ctx->r3, ctx->r16);
    // 0x80014204: addu        $t7, $a0, $s1
    ctx->r15 = ADD32(ctx->r4, ctx->r17);
    // 0x80014208: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    // 0x8001420C: subu        $t0, $t6, $a0
    ctx->r8 = SUB32(ctx->r14, ctx->r4);
    // 0x80014210: and         $t6, $t9, $t2
    ctx->r14 = ctx->r25 & ctx->r10;
    // 0x80014214: and         $t8, $t7, $t3
    ctx->r24 = ctx->r15 & ctx->r11;
    // 0x80014218: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8001421C: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80014220: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80014224: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x80014228: addu        $t9, $v1, $t1
    ctx->r25 = ADD32(ctx->r3, ctx->r9);
    // 0x8001422C: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x80014230: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x80014234: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x80014238: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x8001423C: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x80014240: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x80014244: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x80014248: lw          $t9, 0x38($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X38);
    // 0x8001424C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014250: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80014254: lh          $t6, 0x10($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X10);
    // 0x80014258: nop

    // 0x8001425C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80014260: bne         $at, $zero, L_800141D4
    if (ctx->r1 != 0) {
        // 0x80014264: nop
    
            goto L_800141D4;
    }
    // 0x80014264: nop

    // 0x80014268: lh          $v1, 0x28($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X28);
    // 0x8001426C: nop

L_80014270:
    // 0x80014270: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
L_80014274:
    // 0x80014274: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80014278: bne         $at, $zero, L_8001419C
    if (ctx->r1 != 0) {
        // 0x8001427C: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_8001419C;
    }
    // 0x8001427C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_80014280:
    // 0x80014280: bne         $s7, $fp, L_80014134
    if (ctx->r23 != ctx->r30) {
        // 0x80014284: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80014134;
    }
    // 0x80014284: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80014288:
    // 0x80014288: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001428C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80014290: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80014294: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80014298: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001429C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800142A0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800142A4: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800142A8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800142AC: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800142B0: jr          $ra
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800142B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_kerning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4164: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C4168: jr          $ra
    // 0x800C416C: sw          $a0, -0x5810($at)
    MEM_W(-0X5810, ctx->r1) = ctx->r4;
    return;
    // 0x800C416C: sw          $a0, -0x5810($at)
    MEM_W(-0X5810, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_text_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C45A4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C45A8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C45AC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C45B0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C45B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C45B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C45BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C45C0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C45C4: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C45C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C45CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C45D0: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x800C45D4: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800C45D8: beq         $a2, $zero, L_800C4D7C
    if (ctx->r6 == 0) {
        // 0x800C45DC: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_800C4D7C;
    }
    // 0x800C45DC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800C45E0: lbu         $t7, 0x1D($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1D);
    // 0x800C45E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C45E8: lw          $t9, -0x581C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X581C);
    // 0x800C45EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C45F0: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x800C45F4: lh          $s0, 0x0($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X0);
    // 0x800C45F8: lh          $ra, 0x2($a1)
    ctx->r31 = MEM_H(ctx->r5, 0X2);
    // 0x800C45FC: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4600: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4604: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C4608: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C460C: addiu       $t8, $t8, 0x3690
    ctx->r24 = ADD32(ctx->r24, 0X3690);
    // 0x800C4610: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C4614: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4618: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C461C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4620: lw          $t9, -0x5818($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5818);
    // 0x800C4624: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C4628: beq         $a1, $t9, L_800C4798
    if (ctx->r5 == ctx->r25) {
        // 0x800C462C: andi        $t6, $s3, 0x5
        ctx->r14 = ctx->r19 & 0X5;
            goto L_800C4798;
    }
    // 0x800C462C: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
    // 0x800C4630: lh          $a0, 0xA($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XA);
    // 0x800C4634: lh          $a1, 0x6($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X6);
    // 0x800C4638: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C463C: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x800C4640: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C4644: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C4648: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C464C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4650: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4654: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800C4658: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C465C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C4660: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x800C4664: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800C4668: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C466C: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800C4670: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800C4674: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C4678: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C467C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4680: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C4684: nop

    // 0x800C4688: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C468C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4690: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4694: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4698: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C469C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C46A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C46A4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C46A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C46AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C46B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C46B4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800C46B8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C46BC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x800C46C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C46C4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C46C8: subu        $t9, $a2, $v0
    ctx->r25 = SUB32(ctx->r6, ctx->r2);
    // 0x800C46CC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C46D0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C46D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C46D8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800C46DC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C46E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C46E4: nop

    // 0x800C46E8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800C46EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C46F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C46F4: nop

    // 0x800C46F8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C46FC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C4700: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C4704: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800C4708: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800C470C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800C4710: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800C4714: nop

    // 0x800C4718: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C471C: nop

    // 0x800C4720: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C4724: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C4728: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C472C: nop

    // 0x800C4730: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800C4734: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4738: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C473C: nop

    // 0x800C4740: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C4744: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C4748: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x800C474C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C4750: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800C4754: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4758: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800C475C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800C4760: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4764: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C4768: nop

    // 0x800C476C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C4770: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C4774: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C4778: nop

    // 0x800C477C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C4780: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800C4784: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C4788: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800C478C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C4790: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800C4794: andi        $t6, $s3, 0x5
    ctx->r14 = ctx->r19 & 0X5;
L_800C4798:
    // 0x800C4798: beq         $t6, $zero, L_800C47DC
    if (ctx->r14 == 0) {
        // 0x800C479C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C47DC;
    }
    // 0x800C479C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C47A0: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C47A4: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C47A8: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C47AC: jal         0x800C4DA0
    // 0x800C47B0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_0;
    // 0x800C47B0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_0:
    // 0x800C47B4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C47B8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C47BC: andi        $t7, $s3, 0x1
    ctx->r15 = ctx->r19 & 0X1;
    // 0x800C47C0: beq         $t7, $zero, L_800C47D4
    if (ctx->r15 == 0) {
        // 0x800C47C4: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800C47D4;
    }
    // 0x800C47C4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800C47C8: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C47CC: b           L_800C47DC
    // 0x800C47D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C47DC;
    // 0x800C47D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C47D4:
    // 0x800C47D4: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C47D8: subu        $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
L_800C47DC:
    // 0x800C47DC: andi        $t9, $s3, 0x2
    ctx->r25 = ctx->r19 & 0X2;
    // 0x800C47E0: beq         $t9, $zero, L_800C47F8
    if (ctx->r25 == 0) {
        // 0x800C47E4: andi        $t7, $s3, 0x8
        ctx->r15 = ctx->r19 & 0X8;
            goto L_800C47F8;
    }
    // 0x800C47E4: andi        $t7, $s3, 0x8
    ctx->r15 = ctx->r19 & 0X8;
    // 0x800C47E8: lhu         $t6, 0x22($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X22);
    // 0x800C47EC: nop

    // 0x800C47F0: subu        $ra, $ra, $t6
    ctx->r31 = SUB32(ctx->r31, ctx->r14);
    // 0x800C47F4: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
L_800C47F8:
    // 0x800C47F8: beq         $t7, $zero, L_800C4810
    if (ctx->r15 == 0) {
        // 0x800C47FC: nop
    
            goto L_800C4810;
    }
    // 0x800C47FC: nop

    // 0x800C4800: lhu         $t8, 0x22($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4804: nop

    // 0x800C4808: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C480C: subu        $ra, $ra, $t9
    ctx->r31 = SUB32(ctx->r31, ctx->r25);
L_800C4810:
    // 0x800C4810: lbu         $t6, 0x1B($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C4814: nop

    // 0x800C4818: beq         $t6, $zero, L_800C4944
    if (ctx->r14 == 0) {
        // 0x800C481C: nop
    
            goto L_800C4944;
    }
    // 0x800C481C: nop

    // 0x800C4820: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4824: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800C4828: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C482C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4830: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4834: lbu         $t6, 0x18($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X18);
    // 0x800C4838: lbu         $t9, 0x19($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X19);
    // 0x800C483C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800C4840: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800C4844: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800C4848: lbu         $t7, 0x1A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1A);
    // 0x800C484C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C4850: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800C4854: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800C4858: lbu         $t8, 0x1B($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X1B);
    // 0x800C485C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4860: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4864: bne         $s5, $at, L_800C488C
    if (ctx->r21 != ctx->r1) {
        // 0x800C4868: sw          $t6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r14;
            goto L_800C488C;
    }
    // 0x800C4868: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C486C: lbu         $a2, 0x1D($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1D);
    // 0x800C4870: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800C4874: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800C4878: jal         0x800C4DA0
    // 0x800C487C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C487C: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_1:
    // 0x800C4880: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800C4884: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4888: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_800C488C:
    // 0x800C488C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4890: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4894: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C4898: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C489C: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x800C48A0: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800C48A4: addiu       $t6, $t6, 0x36D8
    ctx->r14 = ADD32(ctx->r14, 0X36D8);
    // 0x800C48A8: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800C48AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C48B0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C48B4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C48B8: addu        $t1, $t7, $ra
    ctx->r9 = ADD32(ctx->r15, ctx->r31);
    // 0x800C48BC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C48C0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C48C4: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x800C48C8: addu        $t8, $s0, $s5
    ctx->r24 = ADD32(ctx->r16, ctx->r21);
    // 0x800C48CC: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800C48D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C48D4: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C48D8: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x800C48DC: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800C48E0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C48E4: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C48E8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C48EC: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800C48F0: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800C48F4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800C48F8: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800C48FC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C4900: lh          $t8, 0x4($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4);
    // 0x800C4904: nop

    // 0x800C4908: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800C490C: lh          $t8, 0x6($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X6);
    // 0x800C4910: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4914: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x800C4918: addu        $t6, $ra, $t8
    ctx->r14 = ADD32(ctx->r31, ctx->r24);
    // 0x800C491C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800C4920: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C4924: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800C4928: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C492C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4930: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C4934: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4938: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C493C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4940: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800C4944:
    // 0x800C4944: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4948: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800C494C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4950: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4954: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4958: lbu         $t9, 0x1C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1C);
    // 0x800C495C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800C4960: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800C4964: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C4968: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C496C: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800C4970: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C4974: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C4978: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C497C: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x800C4980: lbu         $t9, 0x15($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X15);
    // 0x800C4984: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800C4988: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800C498C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800C4990: lbu         $t6, 0x16($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X16);
    // 0x800C4994: nop

    // 0x800C4998: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C499C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C49A0: lbu         $t7, 0x17($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X17);
    // 0x800C49A4: nop

    // 0x800C49A8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C49AC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C49B0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C49B4: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x800C49B8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C49BC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C49C0: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x800C49C4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800C49C8: addiu       $t7, $t7, 0x36C8
    ctx->r15 = ADD32(ctx->r15, 0X36C8);
    // 0x800C49CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C49D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C49D4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C49D8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800C49DC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C49E0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C49E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C49E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C49EC: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800C49F0: lh          $t9, 0x20($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X20);
    // 0x800C49F4: lh          $t7, 0x22($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X22);
    // 0x800C49F8: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800C49FC: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C4A00: beq         $t6, $zero, L_800C4D10
    if (ctx->r14 == 0) {
        // 0x800C4A04: addu        $ra, $ra, $t7
        ctx->r31 = ADD32(ctx->r31, ctx->r15);
            goto L_800C4D10;
    }
    // 0x800C4A04: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
    // 0x800C4A08: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C4A0C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800C4A10: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C4A14: bne         $at, $zero, L_800C4D10
    if (ctx->r1 != 0) {
        // 0x800C4A18: addu        $s3, $t8, $zero
        ctx->r19 = ADD32(ctx->r24, 0);
            goto L_800C4D10;
    }
    // 0x800C4A18: addu        $s3, $t8, $zero
    ctx->r19 = ADD32(ctx->r24, 0);
    // 0x800C4A1C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800C4A20: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800C4A24: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_800C4A28:
    // 0x800C4A28: slti        $at, $a0, 0x21
    ctx->r1 = SIGNED(ctx->r4) < 0X21 ? 1 : 0;
    // 0x800C4A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C4A30: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C4A34: bne         $at, $zero, L_800C4A44
    if (ctx->r1 != 0) {
        // 0x800C4A38: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800C4A44;
    }
    // 0x800C4A38: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C4A3C: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800C4A40: bne         $at, $zero, L_800C4AF4
    if (ctx->r1 != 0) {
        // 0x800C4A44: addiu       $t7, $v1, -0x9
        ctx->r15 = ADD32(ctx->r3, -0X9);
            goto L_800C4AF4;
    }
L_800C4A44:
    // 0x800C4A44: addiu       $t7, $v1, -0x9
    ctx->r15 = ADD32(ctx->r3, -0X9);
    // 0x800C4A48: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C4A4C: beq         $at, $zero, L_800C4AE8
    if (ctx->r1 == 0) {
        // 0x800C4A50: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C4AE8;
    }
    // 0x800C4A50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C4A54: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4A58: addu        $at, $at, $t7
    gpr jr_addend_800C4A64 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C4A5C: lw          $t7, -0x6CA0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6CA0);
    // 0x800C4A60: nop

    // 0x800C4A64: jr          $t7
    // 0x800C4A68: nop

    switch (jr_addend_800C4A64 >> 2) {
        case 0: goto L_800C4A88; break;
        case 1: goto L_800C4A78; break;
        case 2: goto L_800C4AD0; break;
        case 3: goto L_800C4AE8; break;
        case 4: goto L_800C4ADC; break;
        case 5: goto L_800C4AE8; break;
        case 6: goto L_800C4AE8; break;
        case 7: goto L_800C4AE8; break;
        case 8: goto L_800C4AE8; break;
        case 9: goto L_800C4AE8; break;
        case 10: goto L_800C4AE8; break;
        case 11: goto L_800C4AE8; break;
        case 12: goto L_800C4AE8; break;
        case 13: goto L_800C4AE8; break;
        case 14: goto L_800C4AE8; break;
        case 15: goto L_800C4AE8; break;
        case 16: goto L_800C4AE8; break;
        case 17: goto L_800C4AE8; break;
        case 18: goto L_800C4AE8; break;
        case 19: goto L_800C4AE8; break;
        case 20: goto L_800C4AE8; break;
        case 21: goto L_800C4AE8; break;
        case 22: goto L_800C4AE8; break;
        case 23: goto L_800C4A6C; break;
        default: switch_error(__func__, 0x800C4A64, 0x800E9360);
    }
    // 0x800C4A68: nop

L_800C4A6C:
    // 0x800C4A6C: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C4A70: b           L_800C4BB4
    // 0x800C4A74: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C4BB4;
    // 0x800C4A74: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C4A78:
    // 0x800C4A78: lhu         $t9, 0x22($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4A7C: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C4A80: b           L_800C4BB4
    // 0x800C4A84: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
        goto L_800C4BB4;
    // 0x800C4A84: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_800C4A88:
    // 0x800C4A88: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C4A8C: lhu         $v0, 0x26($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X26);
    // 0x800C4A90: subu        $t6, $s0, $t7
    ctx->r14 = SUB32(ctx->r16, ctx->r15);
    // 0x800C4A94: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C4A98: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x800C4A9C: bne         $v0, $zero, L_800C4AA8
    if (ctx->r2 != 0) {
        // 0x800C4AA0: nop
    
            goto L_800C4AA8;
    }
    // 0x800C4AA0: nop

    // 0x800C4AA4: break       7
    do_break(2148289188);
L_800C4AA8:
    // 0x800C4AA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C4AAC: bne         $v0, $at, L_800C4AC0
    if (ctx->r2 != ctx->r1) {
        // 0x800C4AB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C4AC0;
    }
    // 0x800C4AB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C4AB4: bne         $t6, $at, L_800C4AC0
    if (ctx->r14 != ctx->r1) {
        // 0x800C4AB8: nop
    
            goto L_800C4AC0;
    }
    // 0x800C4AB8: nop

    // 0x800C4ABC: break       6
    do_break(2148289212);
L_800C4AC0:
    // 0x800C4AC0: mfhi        $t9
    ctx->r25 = hi;
    // 0x800C4AC4: subu        $s0, $t8, $t9
    ctx->r16 = SUB32(ctx->r24, ctx->r25);
    // 0x800C4AC8: b           L_800C4BB4
    // 0x800C4ACC: nop

        goto L_800C4BB4;
    // 0x800C4ACC: nop

L_800C4AD0:
    // 0x800C4AD0: lhu         $t7, 0x22($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X22);
    // 0x800C4AD4: b           L_800C4BB4
    // 0x800C4AD8: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
        goto L_800C4BB4;
    // 0x800C4AD8: addu        $ra, $ra, $t7
    ctx->r31 = ADD32(ctx->r31, ctx->r15);
L_800C4ADC:
    // 0x800C4ADC: lh          $s0, 0x20($s2)
    ctx->r16 = MEM_H(ctx->r18, 0X20);
    // 0x800C4AE0: b           L_800C4BB4
    // 0x800C4AE4: nop

        goto L_800C4BB4;
    // 0x800C4AE4: nop

L_800C4AE8:
    // 0x800C4AE8: lhu         $t6, 0x24($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X24);
    // 0x800C4AEC: b           L_800C4BB4
    // 0x800C4AF0: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800C4BB4;
    // 0x800C4AF0: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800C4AF4:
    // 0x800C4AF4: addiu       $a0, $v1, -0x20
    ctx->r4 = ADD32(ctx->r3, -0X20);
    // 0x800C4AF8: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800C4AFC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C4B00: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800C4B04: lbu         $a3, 0x100($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X100);
    // 0x800C4B08: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C4B0C: beq         $a3, $at, L_800C4BB4
    if (ctx->r7 == ctx->r1) {
        // 0x800C4B10: nop
    
            goto L_800C4BB4;
    }
    // 0x800C4B10: nop

    // 0x800C4B14: beq         $s4, $a3, L_800C4B6C
    if (ctx->r20 == ctx->r7) {
        // 0x800C4B18: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800C4B6C;
    }
    // 0x800C4B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C4B1C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800C4B20: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4B24: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800C4B28: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    // 0x800C4B2C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4B30: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4B34: lh          $a2, 0xA($a0)
    ctx->r6 = MEM_H(ctx->r4, 0XA);
    // 0x800C4B38: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800C4B3C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800C4B40: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800C4B44: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800C4B48: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800C4B4C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800C4B50: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C4B54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4B58: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x800C4B5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C4B60: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x800C4B64: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C4B68: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800C4B6C:
    // 0x800C4B6C: lbu         $t9, 0x102($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X102);
    // 0x800C4B70: nop

    // 0x800C4B74: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800C4B78: lbu         $t7, 0x103($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X103);
    // 0x800C4B7C: nop

    // 0x800C4B80: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800C4B84: lbu         $t8, 0x107($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X107);
    // 0x800C4B88: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x800C4B8C: lbu         $t5, 0x105($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X105);
    // 0x800C4B90: lbu         $s5, 0x106($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X106);
    // 0x800C4B94: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C4B98: lhu         $v1, 0x20($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0X20);
    // 0x800C4B9C: nop

    // 0x800C4BA0: bne         $v1, $zero, L_800C4BB4
    if (ctx->r3 != 0) {
        // 0x800C4BA4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800C4BB4;
    }
    // 0x800C4BA4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800C4BA8: lbu         $t0, 0x101($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X101);
    // 0x800C4BAC: b           L_800C4BB4
    // 0x800C4BB0: nop

        goto L_800C4BB4;
    // 0x800C4BB0: nop

L_800C4BB4:
    // 0x800C4BB4: beq         $a1, $zero, L_800C4CC4
    if (ctx->r5 == 0) {
        // 0x800C4BB8: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_800C4CC4;
    }
    // 0x800C4BB8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800C4BBC: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800C4BC0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800C4BC4: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x800C4BC8: lh          $t6, 0x6($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X6);
    // 0x800C4BCC: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x800C4BD0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C4BD4: addu        $t9, $t6, $ra
    ctx->r25 = ADD32(ctx->r14, ctx->r31);
    // 0x800C4BD8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800C4BDC: addu        $a2, $t9, $t7
    ctx->r6 = ADD32(ctx->r25, ctx->r15);
    // 0x800C4BE0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C4BE4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800C4BE8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C4BEC: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x800C4BF0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800C4BF4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C4BF8: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x800C4BFC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4C00: sll         $t8, $t4, 5
    ctx->r24 = S32(ctx->r12 << 5);
    // 0x800C4C04: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800C4C08: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800C4C0C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800C4C10: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x800C4C14: bgez        $a1, L_800C4C30
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C4C18: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_800C4C30;
    }
    // 0x800C4C18: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x800C4C1C: blez        $v0, L_800C4C30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C4C20: negu        $t9, $a1
        ctx->r25 = SUB32(0, ctx->r5);
            goto L_800C4C30;
    }
    // 0x800C4C20: negu        $t9, $a1
    ctx->r25 = SUB32(0, ctx->r5);
    // 0x800C4C24: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800C4C28: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x800C4C2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C4C30:
    // 0x800C4C30: bgez        $a2, L_800C4C4C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C4C34: andi        $t7, $t2, 0xFFF
        ctx->r15 = ctx->r10 & 0XFFF;
            goto L_800C4C4C;
    }
    // 0x800C4C34: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x800C4C38: blez        $v1, L_800C4C4C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C4C3C: negu        $t8, $a2
        ctx->r24 = SUB32(0, ctx->r6);
            goto L_800C4C4C;
    }
    // 0x800C4C3C: negu        $t8, $a2
    ctx->r24 = SUB32(0, ctx->r6);
    // 0x800C4C40: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800C4C44: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800C4C48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C4C4C:
    // 0x800C4C4C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4C50: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C4C54: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C4C58: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C4C5C: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800C4C60: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800C4C64: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C4C68: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x800C4C6C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800C4C70: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x800C4C74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C4C78: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800C4C7C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C4C80: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4C84: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x800C4C88: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C4C8C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800C4C90: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800C4C94: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x800C4C98: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C4C9C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800C4CA0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800C4CA4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800C4CA8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800C4CAC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800C4CB0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C4CB4: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800C4CB8: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800C4CBC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800C4CC0: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800C4CC4:
    // 0x800C4CC4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4CC8: lw          $t6, -0x5810($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5810);
    // 0x800C4CCC: nop

    // 0x800C4CD0: beq         $t6, $zero, L_800C4CE4
    if (ctx->r14 == 0) {
        // 0x800C4CD4: nop
    
            goto L_800C4CE4;
    }
    // 0x800C4CD4: nop

    // 0x800C4CD8: beq         $t0, $zero, L_800C4CE4
    if (ctx->r8 == 0) {
        // 0x800C4CDC: nop
    
            goto L_800C4CE4;
    }
    // 0x800C4CDC: nop

    // 0x800C4CE0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800C4CE4:
    // 0x800C4CE4: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    // 0x800C4CE8: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800C4CEC: beq         $v0, $zero, L_800C4D10
    if (ctx->r2 == 0) {
        // 0x800C4CF0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800C4D10;
    }
    // 0x800C4CF0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C4CF4: lh          $t9, 0xA($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XA);
    // 0x800C4CF8: nop

    // 0x800C4CFC: slt         $at, $t9, $ra
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800C4D00: beq         $at, $zero, L_800C4A28
    if (ctx->r1 == 0) {
        // 0x800C4D04: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800C4A28;
    }
    // 0x800C4D04: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800C4D08: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800C4D0C: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
L_800C4D10:
    // 0x800C4D10: lh          $t7, 0x20($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X20);
    // 0x800C4D14: lh          $t6, 0x22($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X22);
    // 0x800C4D18: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800C4D1C: subu        $t9, $ra, $t6
    ctx->r25 = SUB32(ctx->r31, ctx->r14);
    // 0x800C4D20: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x800C4D24: sh          $t9, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r25;
    // 0x800C4D28: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4D2C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800C4D30: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C4D34: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C4D38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4D3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4D40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C4D44: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C4D48: nop

    // 0x800C4D4C: beq         $s2, $t6, L_800C4D5C
    if (ctx->r18 == ctx->r14) {
        // 0x800C4D50: nop
    
            goto L_800C4D5C;
    }
    // 0x800C4D50: nop

    // 0x800C4D54: jal         0x80067A3C
    // 0x800C4D58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x800C4D58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800C4D5C:
    // 0x800C4D5C: jal         0x8007B3D0
    // 0x800C4D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_3;
    // 0x800C4D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800C4D64: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800C4D68: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800C4D6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C4D70: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C4D74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800C4D78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800C4D7C:
    // 0x800C4D7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C4D80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4D84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C4D88: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4D8C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4D90: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C4D94: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C4D98: jr          $ra
    // 0x800C4D9C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800C4D9C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void gameselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C698: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C69C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008C6A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C6A4: slti        $at, $v0, -0x15
    ctx->r1 = SIGNED(ctx->r2) < -0X15 ? 1 : 0;
    // 0x8008C6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C6AC: bne         $at, $zero, L_8008C7AC
    if (ctx->r1 != 0) {
        // 0x8008C6B0: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8008C7AC;
    }
    // 0x8008C6B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008C6B4: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x8008C6B8: beq         $at, $zero, L_8008C7AC
    if (ctx->r1 == 0) {
        // 0x8008C6BC: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008C7AC;
    }
    // 0x8008C6BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008C6C0: lw          $a2, 0x63BC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X63BC);
    // 0x8008C6C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C6C8: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8008C6CC: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008C6D0: bne         $at, $zero, L_8008C6E0
    if (ctx->r1 != 0) {
        // 0x8008C6D4: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8008C6E0;
    }
    // 0x8008C6D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8008C6D8: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008C6DC: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_8008C6E0:
    // 0x8008C6E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C6E4: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8008C6E8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8008C6EC: jal         0x80067F2C
    // 0x8008C6F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8008C6F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8008C6F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C6F8: addiu       $a0, $a0, 0x63E0
    ctx->r4 = ADD32(ctx->r4, 0X63E0);
    // 0x8008C6FC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8008C700: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C704: bltz        $t8, L_8008C754
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008C708: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008C754;
    }
    // 0x8008C708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008C70C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008C710: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C714: addiu       $a1, $a1, -0xBA0
    ctx->r5 = ADD32(ctx->r5, -0XBA0);
    // 0x8008C718: addiu       $a3, $a3, 0x6460
    ctx->r7 = ADD32(ctx->r7, 0X6460);
L_8008C71C:
    // 0x8008C71C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8008C720: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008C724: bne         $v0, $t9, L_8008C730
    if (ctx->r2 != ctx->r25) {
        // 0x8008C728: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8008C730;
    }
    // 0x8008C728: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8008C72C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8008C730:
    // 0x8008C730: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8008C734: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8008C738: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008C73C: sb          $v1, 0x6F($t3)
    MEM_B(0X6F, ctx->r11) = ctx->r3;
    // 0x8008C740: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8008C744: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C748: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008C74C: beq         $at, $zero, L_8008C71C
    if (ctx->r1 == 0) {
        // 0x8008C750: nop
    
            goto L_8008C71C;
    }
    // 0x8008C750: nop

L_8008C754:
    // 0x8008C754: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x8008C758: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x8008C75C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008C760: bne         $t5, $zero, L_8008C780
    if (ctx->r13 != 0) {
        // 0x8008C764: addiu       $a3, $a3, 0x6460
        ctx->r7 = ADD32(ctx->r7, 0X6460);
            goto L_8008C780;
    }
    // 0x8008C764: addiu       $a3, $a3, 0x6460
    ctx->r7 = ADD32(ctx->r7, 0X6460);
    // 0x8008C768: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008C76C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C770: sw          $t6, -0x864($at)
    MEM_W(-0X864, ctx->r1) = ctx->r14;
    // 0x8008C774: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C778: b           L_8008C790
    // 0x8008C77C: sw          $zero, -0x860($at)
    MEM_W(-0X860, ctx->r1) = 0;
        goto L_8008C790;
    // 0x8008C77C: sw          $zero, -0x860($at)
    MEM_W(-0X860, ctx->r1) = 0;
L_8008C780:
    // 0x8008C780: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C784: sw          $zero, -0x864($at)
    MEM_W(-0X864, ctx->r1) = 0;
    // 0x8008C788: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C78C: sw          $zero, -0x860($at)
    MEM_W(-0X860, ctx->r1) = 0;
L_8008C790:
    // 0x8008C790: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008C794: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C798: jal         0x800821EC
    // 0x8008C79C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x8008C79C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x8008C7A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008C7A4: jal         0x80080BC8
    // 0x8008C7A8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    func_80080BC8(rdram, ctx);
        goto after_2;
    // 0x8008C7A8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_2:
L_8008C7AC:
    // 0x8008C7AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C7B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C7B4: jr          $ra
    // 0x8008C7B8: nop

    return;
    // 0x8008C7B8: nop

;}
RECOMP_FUNC void tt_ghost_beaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B3C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B3CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B3D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B3D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B3D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B3DC: jal         0x80059B4C
    // 0x8001B3E0: sw          $zero, -0x38E8($at)
    MEM_W(-0X38E8, ctx->r1) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8001B3E0: sw          $zero, -0x38E8($at)
    MEM_W(-0X38E8, ctx->r1) = 0;
    after_0:
    // 0x8001B3E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B3E8: sb          $zero, -0x38CC($at)
    MEM_B(-0X38CC, ctx->r1) = 0;
    // 0x8001B3EC: jal         0x8001E29C
    // 0x8001B3F0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8001B3F0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x8001B3F4: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001B3F8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B3FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B400: beq         $a3, $t6, L_8001B43C
    if (ctx->r7 == ctx->r14) {
        // 0x8001B404: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B43C;
    }
    // 0x8001B404: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B408: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8001B40C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001B410: beq         $s0, $t7, L_8001B43C
    if (ctx->r16 == ctx->r15) {
        // 0x8001B414: nop
    
            goto L_8001B43C;
    }
    // 0x8001B414: nop

L_8001B418:
    // 0x8001B418: lb          $t8, 0x1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X1);
    // 0x8001B41C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B420: beq         $a3, $t8, L_8001B43C
    if (ctx->r7 == ctx->r24) {
        // 0x8001B424: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B43C;
    }
    // 0x8001B424: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B428: addu        $t9, $a1, $a2
    ctx->r25 = ADD32(ctx->r5, ctx->r6);
    // 0x8001B42C: lb          $t0, 0x0($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X0);
    // 0x8001B430: nop

    // 0x8001B434: bne         $s0, $t0, L_8001B418
    if (ctx->r16 != ctx->r8) {
        // 0x8001B438: nop
    
            goto L_8001B418;
    }
    // 0x8001B438: nop

L_8001B43C:
    // 0x8001B43C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8001B440: addiu       $s0, $s0, -0x38C8
    ctx->r16 = ADD32(ctx->r16, -0X38C8);
    // 0x8001B444: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x8001B448: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8001B44C: beq         $t1, $zero, L_8001B4E0
    if (ctx->r9 == 0) {
        // 0x8001B450: sllv        $a1, $t2, $a2
        ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
            goto L_8001B4E0;
    }
    // 0x8001B450: sllv        $a1, $t2, $a2
    ctx->r5 = S32(ctx->r10 << (ctx->r6 & 31));
    // 0x8001B454: jal         0x8009EA78
    // 0x8001B458: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    set_eeprom_settings_value(rdram, ctx);
        goto after_2;
    // 0x8001B458: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_2:
    // 0x8001B45C: jal         0x8009EB08
    // 0x8001B460: nop

    get_eeprom_settings(rdram, ctx);
        goto after_3;
    // 0x8001B460: nop

    after_3:
    // 0x8001B464: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B468: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B46C: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001B470: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001B474: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x8001B478: bne         $t5, $at, L_8001B4B8
    if (ctx->r13 != ctx->r1) {
        // 0x8001B47C: addiu       $a0, $zero, 0x24C
        ctx->r4 = ADD32(0, 0X24C);
            goto L_8001B4B8;
    }
    // 0x8001B47C: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
    // 0x8001B480: jal         0x8009C2E0
    // 0x8001B484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_4;
    // 0x8001B484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8001B488: addiu       $a0, $zero, 0x24E
    ctx->r4 = ADD32(0, 0X24E);
    // 0x8001B48C: jal         0x80001D04
    // 0x8001B490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8001B490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001B494: addiu       $a0, $zero, 0x24F
    ctx->r4 = ADD32(0, 0X24F);
    // 0x8001B498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B49C: jal         0x80000FDC
    // 0x8001B4A0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_6;
    // 0x8001B4A0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_6:
    // 0x8001B4A4: jal         0x800C31EC
    // 0x8001B4A8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8001B4A8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_7:
    // 0x8001B4AC: b           L_8001B4D8
    // 0x8001B4B0: nop

        goto L_8001B4D8;
    // 0x8001B4B0: nop

    // 0x8001B4B4: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
L_8001B4B8:
    // 0x8001B4B8: jal         0x80001D04
    // 0x8001B4BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8001B4BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8001B4C0: addiu       $a0, $zero, 0x24D
    ctx->r4 = ADD32(0, 0X24D);
    // 0x8001B4C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B4C8: jal         0x80000FDC
    // 0x8001B4CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_9;
    // 0x8001B4CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x8001B4D0: jal         0x800C31EC
    // 0x8001B4D4: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    set_current_text(rdram, ctx);
        goto after_10;
    // 0x8001B4D4: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_10:
L_8001B4D8:
    // 0x8001B4D8: b           L_8001B4EC
    // 0x8001B4DC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_8001B4EC;
    // 0x8001B4DC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8001B4E0:
    // 0x8001B4E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B4E4: jal         0x800A6DB4
    // 0x8001B4E8: nop

    hud_time_trial_message(rdram, ctx);
        goto after_11;
    // 0x8001B4E8: nop

    after_11:
L_8001B4EC:
    // 0x8001B4EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B4F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B4F4: jr          $ra
    // 0x8001B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void init_object_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F7EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F7F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F7F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F7F8: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x8000F7FC: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
    // 0x8000F800: lb          $v0, 0x53($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X53);
    // 0x8000F804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000F808: bne         $v0, $zero, L_8000F948
    if (ctx->r2 != 0) {
        // 0x8000F80C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F948;
    }
    // 0x8000F80C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F810: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x8000F814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F818: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000F81C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000F820: bne         $t6, $zero, L_8000F83C
    if (ctx->r14 != 0) {
        // 0x8000F824: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8000F83C;
    }
    // 0x8000F824: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F828:
    // 0x8000F828: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000F82C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F830: beq         $t7, $zero, L_8000F828
    if (ctx->r15 == 0) {
        // 0x8000F834: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8000F828;
    }
    // 0x8000F834: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000F838: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_8000F83C:
    // 0x8000F83C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8000F840: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000F844: nop

    // 0x8000F848: beq         $v0, $zero, L_8000F978
    if (ctx->r2 == 0) {
        // 0x8000F84C: nop
    
            goto L_8000F978;
    }
    // 0x8000F84C: nop

    // 0x8000F850: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000F854: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000F858: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8000F85C: nop

    // 0x8000F860: beq         $t2, $zero, L_8000F978
    if (ctx->r10 == 0) {
        // 0x8000F864: nop
    
            goto L_8000F978;
    }
    // 0x8000F864: nop

    // 0x8000F868: lh          $t3, 0x3E($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X3E);
    // 0x8000F86C: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8000F870: lw          $a1, 0x28($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X28);
    // 0x8000F874: lw          $a2, 0x2C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X2C);
    // 0x8000F878: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000F87C: lh          $t4, 0x40($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X40);
    // 0x8000F880: jal         0x8001D4B4
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8000F884: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x8000F888: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8000F88C: nop

    // 0x8000F890: lbu         $t5, 0x3D($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3D);
    // 0x8000F894: nop

    // 0x8000F898: beq         $t5, $zero, L_8000F940
    if (ctx->r13 == 0) {
        // 0x8000F89C: nop
    
            goto L_8000F940;
    }
    // 0x8000F89C: nop

    // 0x8000F8A0: lbu         $t6, 0x3A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3A);
    // 0x8000F8A4: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8A8: nop

    // 0x8000F8AC: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8000F8B0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8B4: lw          $t1, 0x54($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8B8: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x8000F8BC: nop

    // 0x8000F8C0: sb          $t9, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r25;
    // 0x8000F8C4: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8C8: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8CC: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8000F8D0: nop

    // 0x8000F8D4: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8000F8D8: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x8000F8DC: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8E0: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8000F8E4: nop

    // 0x8000F8E8: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8000F8EC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F8F0: nop

    // 0x8000F8F4: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x8000F8F8: nop

    // 0x8000F8FC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8000F900: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8000F904: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x8000F908: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F90C: nop

    // 0x8000F910: lh          $t2, 0x1E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1E);
    // 0x8000F914: nop

    // 0x8000F918: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8000F91C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8000F920: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x8000F924: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8000F928: nop

    // 0x8000F92C: lh          $t5, 0x20($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X20);
    // 0x8000F930: nop

    // 0x8000F934: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8000F938: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8000F93C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_8000F940:
    // 0x8000F940: b           L_8000F978
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
        goto L_8000F978;
    // 0x8000F944: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
L_8000F948:
    // 0x8000F948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F94C: bne         $v0, $at, L_8000F978
    if (ctx->r2 != ctx->r1) {
        // 0x8000F950: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000F978;
    }
    // 0x8000F950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000F958: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x8000F95C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8000F960: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8000F964: sb          $v0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r2;
    // 0x8000F968: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x8000F96C: sb          $v0, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r2;
    // 0x8000F970: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8000F974: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_8000F978:
    // 0x8000F978: bne         $a2, $zero, L_8000F984
    if (ctx->r6 != 0) {
        // 0x8000F97C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8000F984;
    }
    // 0x8000F97C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8000F980: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
L_8000F984:
    // 0x8000F984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F988: and         $v0, $a2, $at
    ctx->r2 = ctx->r6 & ctx->r1;
    // 0x8000F98C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000F990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000F994: jr          $ra
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8000F998: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void fileselect_input_root(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D5F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D5FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D600: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008D604: jal         0x8006A554
    // 0x8008D608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008D608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008D60C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D610: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x8008D614: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008D618: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008D61C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008D620: lb          $a2, 0x645C($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X645C);
    // 0x8008D624: lb          $a3, 0x6464($a3)
    ctx->r7 = MEM_B(ctx->r7, 0X6464);
    // 0x8008D628: bne         $t0, $t6, L_8008D670
    if (ctx->r8 != ctx->r14) {
        // 0x8008D62C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008D670;
    }
    // 0x8008D62C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008D630: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008D634: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008D638: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008D63C: jal         0x8006A554
    // 0x8008D640: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008D640: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8008D644: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008D648: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D64C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8008D650: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008D654: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D658: lb          $t7, 0x645D($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X645D);
    // 0x8008D65C: lb          $t8, 0x6465($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6465);
    // 0x8008D660: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008D664: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008D668: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8008D66C: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
L_8008D670:
    // 0x8008D670: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008D674: beq         $t9, $zero, L_8008D790
    if (ctx->r25 == 0) {
        // 0x8008D678: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008D790;
    }
    // 0x8008D678: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D67C: addiu       $t1, $t1, 0x63E0
    ctx->r9 = ADD32(ctx->r9, 0X63E0);
    // 0x8008D680: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008D684: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D688: beq         $v0, $zero, L_8008D6AC
    if (ctx->r2 == 0) {
        // 0x8008D68C: addiu       $t3, $t3, -0xB34
        ctx->r11 = ADD32(ctx->r11, -0XB34);
            goto L_8008D6AC;
    }
    // 0x8008D68C: addiu       $t3, $t3, -0xB34
    ctx->r11 = ADD32(ctx->r11, -0XB34);
    // 0x8008D690: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008D694: beq         $v0, $t2, L_8008D71C
    if (ctx->r2 == ctx->r10) {
        // 0x8008D698: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008D71C;
    }
    // 0x8008D698: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008D69C: beq         $v0, $t0, L_8008D758
    if (ctx->r2 == ctx->r8) {
        // 0x8008D6A0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008D758;
    }
    // 0x8008D6A0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008D6A4: b           L_8008D7A4
    // 0x8008D6A8: nop

        goto L_8008D7A4;
    // 0x8008D6A8: nop

L_8008D6AC:
    // 0x8008D6AC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008D6B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008D6B4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008D6B8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008D6BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008D6C0: addiu       $t6, $t6, 0x64A0
    ctx->r14 = ADD32(ctx->r14, 0X64A0);
    // 0x8008D6C4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008D6C8: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8008D6CC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008D6D0: beq         $t7, $zero, L_8008D70C
    if (ctx->r15 == 0) {
        // 0x8008D6D4: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008D70C;
    }
    // 0x8008D6D4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008D6D8: lw          $t8, -0xB6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB6C);
    // 0x8008D6DC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008D6E0: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    // 0x8008D6E4: beq         $t8, $t9, L_8008D708
    if (ctx->r24 == ctx->r25) {
        // 0x8008D6E8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008D708;
    }
    // 0x8008D6E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D6EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008D6F0: jal         0x80001D04
    // 0x8008D6F4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008D6F4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008D6F8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8008D6FC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D700: b           L_8008D7A4
    // 0x8008D704: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_8008D7A4;
    // 0x8008D704: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8008D708:
    // 0x8008D708: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008D70C:
    // 0x8008D70C: jal         0x80001D04
    // 0x8008D710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008D710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008D714: b           L_8008D8AC
    // 0x8008D718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D8AC;
    // 0x8008D718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D71C:
    // 0x8008D71C: jal         0x80001D04
    // 0x8008D720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008D720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008D724: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D728: addiu       $t3, $t3, -0xB34
    ctx->r11 = ADD32(ctx->r11, -0XB34);
    // 0x8008D72C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008D730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D734: sw          $t4, 0x648C($at)
    MEM_W(0X648C, ctx->r1) = ctx->r12;
    // 0x8008D738: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008D73C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D740: sw          $t2, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = ctx->r10;
    // 0x8008D744: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D748: sw          $zero, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = 0;
    // 0x8008D74C: b           L_8008D8AC
    // 0x8008D750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D8AC;
    // 0x8008D750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D754: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8008D758:
    // 0x8008D758: jal         0x80001D04
    // 0x8008D75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008D75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008D760: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D764: addiu       $t3, $t3, -0xB34
    ctx->r11 = ADD32(ctx->r11, -0XB34);
    // 0x8008D768: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8008D76C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D770: sw          $t5, 0x648C($at)
    MEM_W(0X648C, ctx->r1) = ctx->r13;
    // 0x8008D774: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008D778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D77C: sw          $t2, 0x6488($at)
    MEM_W(0X6488, ctx->r1) = ctx->r10;
    // 0x8008D780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D784: sw          $zero, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = 0;
    // 0x8008D788: b           L_8008D8AC
    // 0x8008D78C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D8AC;
    // 0x8008D78C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D790:
    // 0x8008D790: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008D794: beq         $t6, $zero, L_8008D7A4
    if (ctx->r14 == 0) {
        // 0x8008D798: nop
    
            goto L_8008D7A4;
    }
    // 0x8008D798: nop

    // 0x8008D79C: b           L_8008D8AC
    // 0x8008D7A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008D8AC;
    // 0x8008D7A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008D7A4:
    // 0x8008D7A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D7A8: addiu       $t1, $t1, 0x63E0
    ctx->r9 = ADD32(ctx->r9, 0X63E0);
    // 0x8008D7AC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D7B0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8008D7B4: addiu       $t3, $t3, -0xB34
    ctx->r11 = ADD32(ctx->r11, -0XB34);
    // 0x8008D7B8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8008D7BC: sll         $t7, $v0, 8
    ctx->r15 = S32(ctx->r2 << 8);
    // 0x8008D7C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008D7C4: bne         $v0, $zero, L_8008D820
    if (ctx->r2 != 0) {
        // 0x8008D7C8: or          $a0, $t7, $v1
        ctx->r4 = ctx->r15 | ctx->r3;
            goto L_8008D820;
    }
    // 0x8008D7C8: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    // 0x8008D7CC: bgez        $a2, L_8008D7E4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008D7D0: nop
    
            goto L_8008D7E4;
    }
    // 0x8008D7D0: nop

    // 0x8008D7D4: blez        $v1, L_8008D7E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008D7D8: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8008D7E4;
    }
    // 0x8008D7D8: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8008D7DC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8008D7E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8008D7E4:
    // 0x8008D7E4: blez        $a2, L_8008D7FC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008D7E8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008D7FC;
    }
    // 0x8008D7E8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008D7EC: beq         $at, $zero, L_8008D7FC
    if (ctx->r1 == 0) {
        // 0x8008D7F0: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8008D7FC;
    }
    // 0x8008D7F0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8008D7F4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8008D7F8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_8008D7FC:
    // 0x8008D7FC: bgez        $a3, L_8008D890
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8008D800: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008D890;
    }
    // 0x8008D800: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008D804: bne         $at, $zero, L_8008D818
    if (ctx->r1 != 0) {
        // 0x8008D808: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8008D818;
    }
    // 0x8008D808: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8008D80C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008D810: b           L_8008D890
    // 0x8008D814: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8008D890;
    // 0x8008D814: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008D818:
    // 0x8008D818: b           L_8008D890
    // 0x8008D81C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
        goto L_8008D890;
    // 0x8008D81C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8008D820:
    // 0x8008D820: bgez        $a2, L_8008D838
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008D824: nop
    
            goto L_8008D838;
    }
    // 0x8008D824: nop

    // 0x8008D828: bne         $t0, $v0, L_8008D838
    if (ctx->r8 != ctx->r2) {
        // 0x8008D82C: nop
    
            goto L_8008D838;
    }
    // 0x8008D82C: nop

    // 0x8008D830: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8008D834: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8008D838:
    // 0x8008D838: blez        $a2, L_8008D850
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008D83C: nop
    
            goto L_8008D850;
    }
    // 0x8008D83C: nop

    // 0x8008D840: bne         $t2, $v0, L_8008D850
    if (ctx->r10 != ctx->r2) {
        // 0x8008D844: nop
    
            goto L_8008D850;
    }
    // 0x8008D844: nop

    // 0x8008D848: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8008D84C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8008D850:
    // 0x8008D850: blez        $a3, L_8008D894
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008D854: sll         $t4, $v0, 8
        ctx->r12 = S32(ctx->r2 << 8);
            goto L_8008D894;
    }
    // 0x8008D854: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
    // 0x8008D858: bne         $t2, $v0, L_8008D870
    if (ctx->r10 != ctx->r2) {
        // 0x8008D85C: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8008D870;
    }
    // 0x8008D85C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008D860: bne         $at, $zero, L_8008D870
    if (ctx->r1 != 0) {
        // 0x8008D864: nop
    
            goto L_8008D870;
    }
    // 0x8008D864: nop

    // 0x8008D868: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008D86C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008D870:
    // 0x8008D870: bne         $t0, $v0, L_8008D888
    if (ctx->r8 != ctx->r2) {
        // 0x8008D874: nop
    
            goto L_8008D888;
    }
    // 0x8008D874: nop

    // 0x8008D878: bgtz        $v1, L_8008D888
    if (SIGNED(ctx->r3) > 0) {
        // 0x8008D87C: nop
    
            goto L_8008D888;
    }
    // 0x8008D87C: nop

    // 0x8008D880: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x8008D884: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_8008D888:
    // 0x8008D888: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8008D88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D890:
    // 0x8008D890: sll         $t4, $v0, 8
    ctx->r12 = S32(ctx->r2 << 8);
L_8008D894:
    // 0x8008D894: or          $t5, $t4, $v1
    ctx->r13 = ctx->r12 | ctx->r3;
    // 0x8008D898: beq         $a0, $t5, L_8008D8A8
    if (ctx->r4 == ctx->r13) {
        // 0x8008D89C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008D8A8;
    }
    // 0x8008D89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D8A0: jal         0x80001D04
    // 0x8008D8A4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008D8A4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_6:
L_8008D8A8:
    // 0x8008D8A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D8AC:
    // 0x8008D8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D8B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008D8B4: jr          $ra
    // 0x8008D8B8: nop

    return;
    // 0x8008D8B8: nop

;}
RECOMP_FUNC void init_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C3E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C3E8: jal         0x80070B30
    // 0x8006C3EC: nop

    mempool_init_main(rdram, ctx);
        goto after_0;
    // 0x8006C3EC: nop

    after_0:
    // 0x8006C3F0: jal         0x800C6170
    // 0x8006C3F4: nop

    gzip_init(rdram, ctx);
        goto after_1;
    // 0x8006C3F4: nop

    after_1:
    // 0x8006C3F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C3FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C400: jal         0x8006F4EC
    // 0x8006C404: sb          $t6, -0x2C8C($at)
    MEM_B(-0X2C8C, ctx->r1) = ctx->r14;
    drm_validate_imem(rdram, ctx);
        goto after_2;
    // 0x8006C404: sb          $t6, -0x2C8C($at)
    MEM_B(-0X2C8C, ctx->r1) = ctx->r14;
    after_2:
    // 0x8006C408: beq         $v0, $zero, L_8006C418
    if (ctx->r2 == 0) {
        // 0x8006C40C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006C418;
    }
    // 0x8006C40C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C410: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C414: sb          $zero, -0x2C8C($at)
    MEM_B(-0X2C8C, ctx->r1) = 0;
L_8006C418:
    // 0x8006C418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C41C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006C420: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8006C424: sb          $zero, 0x3514($at)
    MEM_B(0X3514, ctx->r1) = 0;
    // 0x8006C428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C42C: bne         $v0, $zero, L_8006C440
    if (ctx->r2 != 0) {
        // 0x8006C430: sw          $zero, 0x3518($at)
        MEM_W(0X3518, ctx->r1) = 0;
            goto L_8006C440;
    }
    // 0x8006C430: sw          $zero, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = 0;
    // 0x8006C434: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8006C438: b           L_8006C464
    // 0x8006C43C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_8006C464;
    // 0x8006C43C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8006C440:
    // 0x8006C440: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C444: bne         $v0, $at, L_8006C458
    if (ctx->r2 != ctx->r1) {
        // 0x8006C448: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006C458;
    }
    // 0x8006C448: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C44C: b           L_8006C464
    // 0x8006C450: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_8006C464;
    // 0x8006C450: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8006C454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8006C458:
    // 0x8006C458: bne         $v0, $at, L_8006C464
    if (ctx->r2 != ctx->r1) {
        // 0x8006C45C: addiu       $t8, $zero, 0x1C
        ctx->r24 = ADD32(0, 0X1C);
            goto L_8006C464;
    }
    // 0x8006C45C: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x8006C460: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8006C464:
    // 0x8006C464: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C468: lbu         $a3, 0x27($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X27);
    // 0x8006C46C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006C470: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006C474: addiu       $a1, $a1, 0x34E8
    ctx->r5 = ADD32(ctx->r5, 0X34E8);
    // 0x8006C478: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    // 0x8006C47C: jal         0x80079350
    // 0x8006C480: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    osCreateScheduler(rdram, ctx);
        goto after_3;
    // 0x8006C480: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x8006C484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C488: jal         0x8006EFB8
    // 0x8006C48C: sb          $zero, -0x2C60($at)
    MEM_B(-0X2C60, ctx->r1) = 0;
    drm_validate_dmem(rdram, ctx);
        goto after_4;
    // 0x8006C48C: sb          $zero, -0x2C60($at)
    MEM_B(-0X2C60, ctx->r1) = 0;
    after_4:
    // 0x8006C490: bne         $v0, $zero, L_8006C4A4
    if (ctx->r2 != 0) {
        // 0x8006C494: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8006C4A4;
    }
    // 0x8006C494: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006C498: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006C49C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C4A0: sb          $t1, -0x2C60($at)
    MEM_B(-0X2C60, ctx->r1) = ctx->r9;
L_8006C4A4:
    // 0x8006C4A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C4A8: jal         0x8007A310
    // 0x8006C4AC: addiu       $a1, $a1, 0x1260
    ctx->r5 = ADD32(ctx->r5, 0X1260);
    video_init(rdram, ctx);
        goto after_5;
    // 0x8006C4AC: addiu       $a1, $a1, 0x1260
    ctx->r5 = ADD32(ctx->r5, 0X1260);
    after_5:
    // 0x8006C4B0: jal         0x80076BA0
    // 0x8006C4B4: nop

    pi_init(rdram, ctx);
        goto after_6;
    // 0x8006C4B4: nop

    after_6:
    // 0x8006C4B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C4BC: jal         0x80078100
    // 0x8006C4C0: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    gfxtask_init(rdram, ctx);
        goto after_7;
    // 0x8006C4C0: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    after_7:
    // 0x8006C4C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C4C8: jal         0x80000450
    // 0x8006C4CC: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    audio_init(rdram, ctx);
        goto after_8;
    // 0x8006C4CC: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    after_8:
    // 0x8006C4D0: jal         0x80008040
    // 0x8006C4D4: nop

    audspat_init(rdram, ctx);
        goto after_9;
    // 0x8006C4D4: nop

    after_9:
    // 0x8006C4D8: jal         0x8006A10C
    // 0x8006C4DC: nop

    input_init(rdram, ctx);
        goto after_10;
    // 0x8006C4DC: nop

    after_10:
    // 0x8006C4E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C4E4: jal         0x8007AC70
    // 0x8006C4E8: sw          $v0, -0x2C7C($at)
    MEM_W(-0X2C7C, ctx->r1) = ctx->r2;
    tex_init_textures(rdram, ctx);
        goto after_11;
    // 0x8006C4E8: sw          $v0, -0x2C7C($at)
    MEM_W(-0X2C7C, ctx->r1) = ctx->r2;
    after_11:
    // 0x8006C4EC: jal         0x8005F850
    // 0x8006C4F0: nop

    allocate_object_model_pools(rdram, ctx);
        goto after_12;
    // 0x8006C4F0: nop

    after_12:
    // 0x8006C4F4: jal         0x8000BF8C
    // 0x8006C4F8: nop

    allocate_object_pools(rdram, ctx);
        goto after_13;
    // 0x8006C4F8: nop

    after_13:
    // 0x8006C4FC: jal         0x800B5E88
    // 0x8006C500: nop

    debug_text_init(rdram, ctx);
        goto after_14;
    // 0x8006C500: nop

    after_14:
    // 0x8006C504: jal         0x800598D0
    // 0x8006C508: nop

    allocate_ghost_data(rdram, ctx);
        goto after_15;
    // 0x8006C508: nop

    after_15:
    // 0x8006C50C: jal         0x800AE530
    // 0x8006C510: nop

    init_particle_assets(rdram, ctx);
        goto after_16;
    // 0x8006C510: nop

    after_16:
    // 0x8006C514: jal         0x800AB1F0
    // 0x8006C518: nop

    weather_init(rdram, ctx);
        goto after_17;
    // 0x8006C518: nop

    after_17:
    // 0x8006C51C: jal         0x8006E3BC
    // 0x8006C520: nop

    calc_and_alloc_heap_for_settings(rdram, ctx);
        goto after_18;
    // 0x8006C520: nop

    after_18:
    // 0x8006C524: jal         0x8006EFDC
    // 0x8006C528: nop

    default_alloc_displaylist_heap(rdram, ctx);
        goto after_19;
    // 0x8006C528: nop

    after_19:
    // 0x8006C52C: jal         0x800C3C00
    // 0x8006C530: nop

    load_fonts(rdram, ctx);
        goto after_20;
    // 0x8006C530: nop

    after_20:
    // 0x8006C534: jal         0x80075B18
    // 0x8006C538: nop

    init_controller_paks(rdram, ctx);
        goto after_21;
    // 0x8006C538: nop

    after_21:
    // 0x8006C53C: jal         0x80081218
    // 0x8006C540: nop

    init_save_data(rdram, ctx);
        goto after_22;
    // 0x8006C540: nop

    after_22:
    // 0x8006C544: jal         0x800C7350
    // 0x8006C548: nop

    bgload_init(rdram, ctx);
        goto after_23;
    // 0x8006C548: nop

    after_23:
    // 0x8006C54C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C550: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C554: addiu       $a1, $a1, 0x3544
    ctx->r5 = ADD32(ctx->r5, 0X3544);
    // 0x8006C558: addiu       $a0, $a0, 0x3548
    ctx->r4 = ADD32(ctx->r4, 0X3548);
    // 0x8006C55C: jal         0x800C8820
    // 0x8006C560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_24;
    // 0x8006C560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x8006C564: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C568: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C56C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C570: addiu       $a2, $a2, 0x3548
    ctx->r6 = ADD32(ctx->r6, 0X3548);
    // 0x8006C574: addiu       $a1, $a1, 0x3538
    ctx->r5 = ADD32(ctx->r5, 0X3538);
    // 0x8006C578: addiu       $a0, $a0, 0x1260
    ctx->r4 = ADD32(ctx->r4, 0X1260);
    // 0x8006C57C: jal         0x80079480
    // 0x8006C580: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    osScAddClient(rdram, ctx);
        goto after_25;
    // 0x8006C580: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_25:
    // 0x8006C584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C588: sw          $zero, 0x3560($at)
    MEM_W(0X3560, ctx->r1) = 0;
    // 0x8006C58C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C590: sw          $zero, 0x3504($at)
    MEM_W(0X3504, ctx->r1) = 0;
    // 0x8006C594: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C59C: addiu       $t0, $t0, 0x34E8
    ctx->r8 = ADD32(ctx->r8, 0X34E8);
    // 0x8006C5A0: sw          $zero, 0x3508($at)
    MEM_W(0X3508, ctx->r1) = 0;
    // 0x8006C5A4: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x8006C5A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006C5AC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8006C5B0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006C5B4: lw          $t4, 0x11F0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11F0);
    // 0x8006C5B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C5BC: addiu       $v1, $v1, 0x11F8
    ctx->r3 = ADD32(ctx->r3, 0X11F8);
    // 0x8006C5C0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006C5C4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8006C5C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8006C5CC: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006C5D0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006C5D4: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8006C5D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006C5DC: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006C5E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006C5E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006C5E8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C5EC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8006C5F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006C5F4: jal         0x800CD260
    // 0x8006C5F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    osSetTime_recomp(rdram, ctx);
        goto after_26;
    // 0x8006C5F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_26:
    // 0x8006C5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006C604: jr          $ra
    // 0x8006C608: nop

    return;
    // 0x8006C608: nop

;}
RECOMP_FUNC void menu_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 15U, dkr_legacy_fields, 0U); }
    // 0x800813D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800813D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800813D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800813DC: jal         0x8009BE5C
    // 0x800813E0: sw          $a0, -0xB90($at)
    MEM_W(-0XB90, ctx->r1) = ctx->r4;
    reset_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x800813E0: sw          $a0, -0xB90($at)
    MEM_W(-0XB90, ctx->r1) = ctx->r4;
    after_0:
    // 0x800813E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800813E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800813EC: sw          $t6, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r14;
    // 0x800813F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800813F4: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x800813F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800813FC: sw          $zero, 0x63C8($at)
    MEM_W(0X63C8, ctx->r1) = 0;
    // 0x80081400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081404: sb          $zero, 0x6828($at)
    MEM_B(0X6828, ctx->r1) = 0;
    // 0x80081408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008140C: sw          $zero, 0x6808($at)
    MEM_W(0X6808, ctx->r1) = 0;
    // 0x80081410: sw          $zero, 0x680C($at)
    MEM_W(0X680C, ctx->r1) = 0;
    // 0x80081414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081418: sw          $zero, 0x6810($at)
    MEM_W(0X6810, ctx->r1) = 0;
    // 0x8008141C: jal         0x80001844
    // 0x80081420: sw          $zero, 0x6814($at)
    MEM_W(0X6814, ctx->r1) = 0;
    music_stop(rdram, ctx);
        goto after_1;
    // 0x80081420: sw          $zero, 0x6814($at)
    MEM_W(0X6814, ctx->r1) = 0;
    after_1:
    // 0x80081424: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80081428: lw          $t7, -0xB90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB90);
    // 0x8008142C: nop

    // 0x80081430: sltiu       $at, $t7, 0x1D
    ctx->r1 = ctx->r15 < 0X1D ? 1 : 0;
    // 0x80081434: beq         $at, $zero, L_8008158C
    if (ctx->r1 == 0) {
        // 0x80081438: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8008158C;
    }
    // 0x80081438: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008143C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081440: addu        $at, $at, $t7
    gpr jr_addend_8008144C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80081444: lw          $t7, -0x7D7C($at)
    ctx->r15 = ADD32(ctx->r1, -0X7D7C);
    // 0x80081448: nop

    // 0x8008144C: jr          $t7
    // 0x80081450: nop

    switch (jr_addend_8008144C >> 2) {
        case 0: goto L_80081464; break;
        case 1: goto L_80081454; break;
        case 2: goto L_8008158C; break;
        case 3: goto L_800814C4; break;
        case 4: goto L_8008158C; break;
        case 5: goto L_80081504; break;
        case 6: goto L_800814E4; break;
        case 7: goto L_8008158C; break;
        case 8: goto L_8008158C; break;
        case 9: goto L_8008158C; break;
        case 10: goto L_800814A4; break;
        case 11: goto L_800814B4; break;
        case 12: goto L_80081474; break;
        case 13: goto L_80081484; break;
        case 14: goto L_80081494; break;
        case 15: goto L_800814F4; break;
        case 16: goto L_8008158C; break;
        case 17: goto L_80081514; break;
        case 18: goto L_8008158C; break;
        case 19: goto L_800814D4; break;
        case 20: goto L_80081524; break;
        case 21: goto L_80081534; break;
        case 22: goto L_8008158C; break;
        case 23: goto L_80081544; break;
        case 24: goto L_80081554; break;
        case 25: goto L_80081564; break;
        case 26: goto L_80081574; break;
        case 27: goto L_8008158C; break;
        case 28: goto L_80081584; break;
        default: switch_error(__func__, 0x8008144C, 0x800E8284);
    }
    // 0x80081450: nop

L_80081454:
    // 0x80081454: jal         0x80082AAC
    // 0x80081458: nop

    menu_logos_screen_init(rdram, ctx);
        goto after_2;
    // 0x80081458: nop

    after_2:
    // 0x8008145C: b           L_80081590
    // 0x80081460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081464:
    // 0x80081464: jal         0x8008353C
    // 0x80081468: nop

    menu_title_screen_init(rdram, ctx);
        goto after_3;
    // 0x80081468: nop

    after_3:
    // 0x8008146C: b           L_80081590
    // 0x80081470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081474:
    // 0x80081474: jal         0x8008415C
    // 0x80081478: nop

    menu_options_init(rdram, ctx);
        goto after_4;
    // 0x80081478: nop

    after_4:
    // 0x8008147C: b           L_80081590
    // 0x80081480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081484:
    // 0x80081484: jal         0x80084754
    // 0x80081488: nop

    menu_audio_options_init(rdram, ctx);
        goto after_5;
    // 0x80081488: nop

    after_5:
    // 0x8008148C: b           L_80081590
    // 0x80081490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081494:
    // 0x80081494: jal         0x80085270
    // 0x80081498: nop

    menu_save_options_init(rdram, ctx);
        goto after_6;
    // 0x80081498: nop

    after_6:
    // 0x8008149C: b           L_80081590
    // 0x800814A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814A4:
    // 0x800814A4: jal         0x800895DC
    // 0x800814A8: nop

    menu_magic_codes_init(rdram, ctx);
        goto after_7;
    // 0x800814A8: nop

    after_7:
    // 0x800814AC: b           L_80081590
    // 0x800814B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814B4:
    // 0x800814B4: jal         0x8008A4E8
    // 0x800814B8: nop

    menu_magic_codes_list_init(rdram, ctx);
        goto after_8;
    // 0x800814B8: nop

    after_8:
    // 0x800814BC: b           L_80081590
    // 0x800814C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814C4:
    // 0x800814C4: jal         0x8008AFCC
    // 0x800814C8: nop

    menu_character_select_init(rdram, ctx);
        goto after_9;
    // 0x800814C8: nop

    after_9:
    // 0x800814CC: b           L_80081590
    // 0x800814D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814D4:
    // 0x800814D4: jal         0x8008C508
    // 0x800814D8: nop

    menu_game_select_init(rdram, ctx);
        goto after_10;
    // 0x800814D8: nop

    after_10:
    // 0x800814DC: b           L_80081590
    // 0x800814E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814E4:
    // 0x800814E4: jal         0x8008CAFC
    // 0x800814E8: nop

    menu_file_select_init(rdram, ctx);
        goto after_11;
    // 0x800814E8: nop

    after_11:
    // 0x800814EC: b           L_80081590
    // 0x800814F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x800814F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800814F4:
    // 0x800814F4: jal         0x8008E7A0
    // 0x800814F8: nop

    menu_track_select_init(rdram, ctx);
        goto after_12;
    // 0x800814F8: nop

    after_12:
    // 0x800814FC: b           L_80081590
    // 0x80081500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081504:
    // 0x80081504: jal         0x80092C84
    // 0x80081508: nop

    menu_adventure_track_init(rdram, ctx);
        goto after_13;
    // 0x80081508: nop

    after_13:
    // 0x8008150C: b           L_80081590
    // 0x80081510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081514:
    // 0x80081514: jal         0x80096848
    // 0x80081518: nop

    menu_results_init(rdram, ctx);
        goto after_14;
    // 0x80081518: nop

    after_14:
    // 0x8008151C: b           L_80081590
    // 0x80081520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081524:
    // 0x80081524: jal         0x8009826C
    // 0x80081528: nop

    menu_trophy_race_round_init(rdram, ctx);
        goto after_15;
    // 0x80081528: nop

    after_15:
    // 0x8008152C: b           L_80081590
    // 0x80081530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081534:
    // 0x80081534: jal         0x80098A24
    // 0x80081538: nop

    menu_trophy_race_rankings_init(rdram, ctx);
        goto after_16;
    // 0x80081538: nop

    after_16:
    // 0x8008153C: b           L_80081590
    // 0x80081540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081544:
    // 0x80081544: jal         0x8009AC98
    // 0x80081548: nop

    menu_cinematic_init(rdram, ctx);
        goto after_17;
    // 0x80081548: nop

    after_17:
    // 0x8008154C: b           L_80081590
    // 0x80081550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081554:
    // 0x80081554: jal         0x80099A5C
    // 0x80081558: nop

    menu_ghost_data_init(rdram, ctx);
        goto after_18;
    // 0x80081558: nop

    after_18:
    // 0x8008155C: b           L_80081590
    // 0x80081560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081564:
    // 0x80081564: jal         0x8009AF48
    // 0x80081568: nop

    menu_credits_init(rdram, ctx);
        goto after_19;
    // 0x80081568: nop

    after_19:
    // 0x8008156C: b           L_80081590
    // 0x80081570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081574:
    // 0x80081574: jal         0x800884F4
    // 0x80081578: nop

    menu_boot_init(rdram, ctx);
        goto after_20;
    // 0x80081578: nop

    after_20:
    // 0x8008157C: b           L_80081590
    // 0x80081580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80081590;
    // 0x80081580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081584:
    // 0x80081584: jal         0x8008C3B4
    // 0x80081588: nop

    menu_caution_init(rdram, ctx);
        goto after_21;
    // 0x80081588: nop

    after_21:
L_8008158C:
    // 0x8008158C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081590:
    // 0x80081590: ori         $t8, $zero, 0xD000
    ctx->r24 = 0 | 0XD000;
    // 0x80081594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081598: sw          $t8, 0x6470($at)
    MEM_W(0X6470, ctx->r1) = ctx->r24;
    // 0x8008159C: jr          $ra
    // 0x800815A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800815A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_projection_matrix_f32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069DA8: jr          $ra
    // 0x80069DAC: addiu       $v0, $v0, 0xFA0
    ctx->r2 = ADD32(ctx->r2, 0XFA0);
    return;
    // 0x80069DAC: addiu       $v0, $v0, 0xFA0
    ctx->r2 = ADD32(ctx->r2, 0XFA0);
;}
RECOMP_FUNC void get_racer_object_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB1C: lw          $v0, -0x5110($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5110);
    // 0x8001BB20: nop

    // 0x8001BB24: bne         $v0, $zero, L_8001BB34
    if (ctx->r2 != 0) {
        // 0x8001BB28: nop
    
            goto L_8001BB34;
    }
    // 0x8001BB28: nop

    // 0x8001BB2C: jr          $ra
    // 0x8001BB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB34:
    // 0x8001BB34: bltz        $a0, L_8001BB44
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BB38: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BB44;
    }
    // 0x8001BB38: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BB3C: bne         $at, $zero, L_8001BB4C
    if (ctx->r1 != 0) {
        // 0x8001BB40: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BB4C;
    }
    // 0x8001BB40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BB44:
    // 0x8001BB44: jr          $ra
    // 0x8001BB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB4C:
    // 0x8001BB4C: lw          $t6, -0x5114($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5114);
    // 0x8001BB50: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB54: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB58: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB5C: nop

    // 0x8001BB60: jr          $ra
    // 0x8001BB64: nop

    return;
    // 0x8001BB64: nop

;}
RECOMP_FUNC void block_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A5F8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002A5FC: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8002A600: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8002A604: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002A608: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002A60C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002A610: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8002A614: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8002A618: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A61C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A620: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A624: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8002A628: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A62C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A630: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A634: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002A638: addiu       $s3, $s3, -0x2F08
    ctx->r19 = ADD32(ctx->r19, -0X2F08);
L_8002A63C:
    // 0x8002A63C: lwc1        $f20, 0x0($s3)
    ctx->f20.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8002A640: lwc1        $f22, 0x4($s3)
    ctx->f22.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8002A644: lwc1        $f24, 0x8($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8002A648: lwc1        $f26, 0xC($s3)
    ctx->f26.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8002A64C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002A650: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002A654: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
L_8002A658:
    // 0x8002A658: beq         $t6, $zero, L_8002A68C
    if (ctx->r14 == 0) {
        // 0x8002A65C: nop
    
            goto L_8002A68C;
    }
    // 0x8002A65C: nop

    // 0x8002A660: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8002A664: nop

    // 0x8002A668: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8002A66C: nop

    // 0x8002A670: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A674: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8002A678: jal         0x800C9B4C
    // 0x8002A67C: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_0;
    // 0x8002A67C: nop

    after_0:
    // 0x8002A680: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A684: b           L_8002A6B4
    // 0x8002A688: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A6B4;
    // 0x8002A688: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A68C:
    // 0x8002A68C: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A690: nop

    // 0x8002A694: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002A698: nop

    // 0x8002A69C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002A6A0: mul.s       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8002A6A4: jal         0x800C9B4C
    // 0x8002A6A8: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_1;
    // 0x8002A6A8: nop

    after_1:
    // 0x8002A6AC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6B0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A6B4:
    // 0x8002A6B4: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    // 0x8002A6B8: beq         $t9, $zero, L_8002A700
    if (ctx->r25 == 0) {
        // 0x8002A6BC: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A700;
    }
    // 0x8002A6BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A6C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A6C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A6C8: jal         0x800C9CBC
    // 0x8002A6CC: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_2;
    // 0x8002A6CC: nop

    after_2:
    // 0x8002A6D0: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x8002A6D4: nop

    // 0x8002A6D8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8002A6DC: nop

    // 0x8002A6E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A6E4: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8002A6E8: jal         0x800C9B4C
    // 0x8002A6EC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A6EC: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x8002A6F0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A6F4: b           L_8002A734
    // 0x8002A6F8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A734;
    // 0x8002A6F8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A6FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A700:
    // 0x8002A700: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A704: jal         0x800C9CBC
    // 0x8002A708: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A708: nop

    after_4:
    // 0x8002A70C: lh          $t1, 0x8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X8);
    // 0x8002A710: nop

    // 0x8002A714: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8002A718: nop

    // 0x8002A71C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A720: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8002A724: jal         0x800C9B4C
    // 0x8002A728: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_5;
    // 0x8002A728: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_5:
    // 0x8002A72C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A730: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A734:
    // 0x8002A734: andi        $t2, $s0, 0x4
    ctx->r10 = ctx->r16 & 0X4;
    // 0x8002A738: beq         $t2, $zero, L_8002A780
    if (ctx->r10 == 0) {
        // 0x8002A73C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8002A780;
    }
    // 0x8002A73C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A740: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A744: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A748: jal         0x800C9CBC
    // 0x8002A74C: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_6;
    // 0x8002A74C: nop

    after_6:
    // 0x8002A750: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x8002A754: nop

    // 0x8002A758: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8002A75C: nop

    // 0x8002A760: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A764: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8002A768: jal         0x800C9B4C
    // 0x8002A76C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_7;
    // 0x8002A76C: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_7:
    // 0x8002A770: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A774: b           L_8002A7B4
    // 0x8002A778: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
        goto L_8002A7B4;
    // 0x8002A778: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A77C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8002A780:
    // 0x8002A780: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A784: jal         0x800C9CBC
    // 0x8002A788: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_8;
    // 0x8002A788: nop

    after_8:
    // 0x8002A78C: lh          $t4, 0xA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA);
    // 0x8002A790: nop

    // 0x8002A794: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002A798: nop

    // 0x8002A79C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A7A0: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002A7A4: jal         0x800C9B4C
    // 0x8002A7A8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_9;
    // 0x8002A7A8: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_9:
    // 0x8002A7AC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7B0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
L_8002A7B4:
    // 0x8002A7B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8002A7B8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8002A7BC: jal         0x800C9CBC
    // 0x8002A7C0: nop

    __ll_to_f_recomp(rdram, ctx);
        goto after_10;
    // 0x8002A7C0: nop

    after_10:
    // 0x8002A7C4: jal         0x800C9B4C
    // 0x8002A7C8: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    __f_to_ll_recomp(rdram, ctx);
        goto after_11;
    // 0x8002A7C8: add.s       $f12, $f0, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f26.fl;
    after_11:
    // 0x8002A7CC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002A7D0: bltz        $v0, L_8002A7EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002A7D4: sw          $v1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r3;
            goto L_8002A7EC;
    }
    // 0x8002A7D4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8002A7D8: bgtz        $v0, L_8002A7E8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002A7DC: nop
    
            goto L_8002A7E8;
    }
    // 0x8002A7DC: nop

    // 0x8002A7E0: beq         $v1, $zero, L_8002A7EC
    if (ctx->r3 == 0) {
        // 0x8002A7E4: nop
    
            goto L_8002A7EC;
    }
    // 0x8002A7E4: nop

L_8002A7E8:
    // 0x8002A7E8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8002A7EC:
    // 0x8002A7EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002A7F0: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8002A7F4: beq         $at, $zero, L_8002A808
    if (ctx->r1 == 0) {
        // 0x8002A7F8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8002A808;
    }
    // 0x8002A7F8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002A7FC: beq         $s2, $zero, L_8002A658
    if (ctx->r18 == 0) {
        // 0x8002A800: andi        $t6, $s0, 0x1
        ctx->r14 = ctx->r16 & 0X1;
            goto L_8002A658;
    }
    // 0x8002A800: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x8002A804: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_8002A808:
    // 0x8002A808: bne         $s0, $at, L_8002A820
    if (ctx->r16 != ctx->r1) {
        // 0x8002A80C: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_8002A820;
    }
    // 0x8002A80C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8002A810: bne         $s2, $zero, L_8002A820
    if (ctx->r18 != 0) {
        // 0x8002A814: nop
    
            goto L_8002A820;
    }
    // 0x8002A814: nop

    // 0x8002A818: b           L_8002A8C4
    // 0x8002A81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A8C4;
    // 0x8002A81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A820:
    // 0x8002A820: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002A824: addiu       $t5, $t5, -0x2ED8
    ctx->r13 = ADD32(ctx->r13, -0X2ED8);
    // 0x8002A828: bne         $s3, $t5, L_8002A63C
    if (ctx->r19 != ctx->r13) {
        // 0x8002A82C: nop
    
            goto L_8002A63C;
    }
    // 0x8002A82C: nop

    // 0x8002A830: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8002A834: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8002A838: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x8002A83C: lh          $t5, 0x4($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4);
    // 0x8002A840: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002A844: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8002A848: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8002A84C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x8002A850: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x8002A854: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002A858: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002A85C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002A860: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002A864: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8002A868: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8002A86C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002A870: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A874: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002A878: jal         0x80066348
    // 0x8002A87C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    get_distance_to_active_camera(rdram, ctx);
        goto after_12;
    // 0x8002A87C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_12:
    // 0x8002A880: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002A884: addiu       $v0, $v0, -0x2C80
    ctx->r2 = ADD32(ctx->r2, -0X2C80);
    // 0x8002A888: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8002A88C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002A890: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002A894: lwc1        $f11, 0x5EA8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X5EA8);
    // 0x8002A898: lwc1        $f10, 0x5EAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5EAC);
    // 0x8002A89C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002A8A0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002A8A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8A8: bc1f        L_8002A8C0
    if (!c1cs) {
        // 0x8002A8AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A8C0;
    }
    // 0x8002A8AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A8B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002A8B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002A8B8: b           L_8002A8C4
    // 0x8002A8BC: sw          $t0, -0x4F44($at)
    MEM_W(-0X4F44, ctx->r1) = ctx->r8;
        goto L_8002A8C4;
    // 0x8002A8BC: sw          $t0, -0x4F44($at)
    MEM_W(-0X4F44, ctx->r1) = ctx->r8;
L_8002A8C0:
    // 0x8002A8C0: sw          $zero, -0x4F44($at)
    MEM_W(-0X4F44, ctx->r1) = 0;
L_8002A8C4:
    // 0x8002A8C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002A8C8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8002A8CC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8002A8D0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002A8D4: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002A8D8: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002A8DC: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002A8E0: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A8E4: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A8E8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8002A8EC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8002A8F0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A8F4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8002A8F8: jr          $ra
    // 0x8002A8FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8002A8FC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void obj_init_buoy_pirateship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800403DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800403E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800403E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800403E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800403EC: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x800403F0: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x800403F4: lh          $a0, 0x2E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2E);
    // 0x800403F8: jal         0x800BE654
    // 0x800403FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    obj_wave_init(rdram, ctx);
        goto after_0;
    // 0x800403FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80040400: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80040404: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040408: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x8004040C: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x80040410: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80040414: lw          $t8, 0x4C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4C);
    // 0x80040418: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8004041C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80040420: lw          $t0, 0x4C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4C);
    // 0x80040424: nop

    // 0x80040428: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8004042C: lw          $t1, 0x4C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4C);
    // 0x80040430: nop

    // 0x80040434: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80040438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004043C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040440: jr          $ra
    // 0x80040444: nop

    return;
    // 0x80040444: nop

;}
RECOMP_FUNC void alFxPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C30: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80063C34: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063C38: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80063C3C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80063C40: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80063C44: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80063C48: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80063C4C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80063C50: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063C54: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063C58: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80063C5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063C60: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063C64: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80063C68: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80063C6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80063C70: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80063C74: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80063C78: jalr        $t9
    // 0x80063C7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80063C7C: nop

    after_0:
    // 0x80063C80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80063C84: lbu         $t7, -0x3150($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3150);
    // 0x80063C88: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063C8C: bne         $t7, $zero, L_80063C9C
    if (ctx->r15 != 0) {
        // 0x80063C90: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80063C9C;
    }
    // 0x80063C90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063C94: b           L_80063F68
    // 0x80063C98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80063F68;
    // 0x80063C98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80063C9C:
    // 0x80063C9C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80063CA0: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x80063CA4: andi        $t3, $s1, 0xFFFF
    ctx->r11 = ctx->r17 & 0XFFFF;
    // 0x80063CA8: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x80063CAC: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x80063CB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80063CB4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80063CB8: lui         $t4, 0xC00
    ctx->r12 = S32(0XC00 << 16);
    // 0x80063CBC: lui         $t5, 0x6C0
    ctx->r13 = S32(0X6C0 << 16);
    // 0x80063CC0: ori         $t5, $t5, 0x6C0
    ctx->r13 = ctx->r13 | 0X6C0;
    // 0x80063CC4: ori         $t4, $t4, 0xDA83
    ctx->r12 = ctx->r12 | 0XDA83;
    // 0x80063CC8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80063CCC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80063CD0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80063CD4: lui         $t6, 0xC00
    ctx->r14 = S32(0XC00 << 16);
    // 0x80063CD8: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80063CDC: ori         $t9, $t9, 0x6C0
    ctx->r25 = ctx->r25 | 0X6C0;
    // 0x80063CE0: ori         $t6, $t6, 0x5A82
    ctx->r14 = ctx->r14 | 0X5A82;
    // 0x80063CE4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80063CE8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80063CEC: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x80063CF0: addiu       $s0, $t1, 0x8
    ctx->r16 = ADD32(ctx->r9, 0X8);
    // 0x80063CF4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80063CF8: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80063CFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063D00: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80063D04: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80063D08: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x80063D0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063D10: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x80063D14: jal         0x80064638
    // 0x80063D18: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_1;
    // 0x80063D18: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x80063D1C: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x80063D20: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80063D24: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80063D28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80063D2C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80063D30: lbu         $t8, 0x24($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X24);
    // 0x80063D34: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80063D38: blez        $t8, L_80063F14
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80063D3C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80063F14;
    }
    // 0x80063D3C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80063D40: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80063D44: nop

L_80063D48:
    // 0x80063D48: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x80063D4C: lw          $t4, 0x20($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X20);
    // 0x80063D50: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x80063D54: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80063D58: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x80063D5C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80063D60: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80063D64: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x80063D68: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80063D6C: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x80063D70: addu        $s4, $v0, $t7
    ctx->r20 = ADD32(ctx->r2, ctx->r15);
    // 0x80063D74: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80063D78: bne         $s4, $v1, L_80063DA0
    if (ctx->r20 != ctx->r3) {
        // 0x80063D7C: addu        $fp, $v0, $t5
        ctx->r30 = ADD32(ctx->r2, ctx->r13);
            goto L_80063DA0;
    }
    // 0x80063D7C: addu        $fp, $v0, $t5
    ctx->r30 = ADD32(ctx->r2, ctx->r13);
    // 0x80063D80: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x80063D84: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x80063D88: sll         $s5, $t6, 16
    ctx->r21 = S32(ctx->r14 << 16);
    // 0x80063D8C: sra         $t7, $s5, 16
    ctx->r15 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80063D90: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80063D94: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80063D98: b           L_80063DBC
    // 0x80063D9C: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
        goto L_80063DBC;
    // 0x80063D9C: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
L_80063DA0:
    // 0x80063DA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063DA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80063DA8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80063DAC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063DB0: jal         0x800644A0
    // 0x80063DB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadBuffer(rdram, ctx);
        goto after_2;
    // 0x80063DB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80063DB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063DBC:
    // 0x80063DBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063DC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80063DC4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80063DC8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063DCC: jal         0x80064224
    // 0x80063DD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadOutputBuffer(rdram, ctx);
        goto after_3;
    // 0x80063DD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80063DD4: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x80063DD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80063DDC: beq         $a0, $zero, L_80063E34
    if (ctx->r4 == 0) {
        // 0x80063DE0: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_80063E34;
    }
    // 0x80063DE0: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80063DE4: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80063DE8: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x80063DEC: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x80063DF0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80063DF4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80063DF8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80063DFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80063E00: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80063E04: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80063E08: bne         $t4, $zero, L_80063E34
    if (ctx->r12 != 0) {
        // 0x80063E0C: nop
    
            goto L_80063E34;
    }
    // 0x80063E0C: nop

    // 0x80063E10: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
    // 0x80063E14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063E18: bne         $t5, $zero, L_80063E34
    if (ctx->r13 != 0) {
        // 0x80063E1C: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80063E34;
    }
    // 0x80063E1C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80063E20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80063E24: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063E28: jal         0x80064638
    // 0x80063E2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_4;
    // 0x80063E2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x80063E30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063E34:
    // 0x80063E34: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    // 0x80063E38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80063E3C: beq         $v1, $zero, L_80063E80
    if (ctx->r3 == 0) {
        // 0x80063E40: andi        $t9, $v1, 0xFFFF
        ctx->r25 = ctx->r3 & 0XFFFF;
            goto L_80063E80;
    }
    // 0x80063E40: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x80063E44: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80063E48: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x80063E4C: andi        $t5, $s5, 0xFFFF
    ctx->r13 = ctx->r21 & 0XFFFF;
    // 0x80063E50: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80063E54: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80063E58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80063E5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80063E60: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80063E64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80063E68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063E6C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80063E70: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80063E74: jal         0x80064638
    // 0x80063E78: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer(rdram, ctx);
        goto after_5;
    // 0x80063E78: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x80063E7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063E80:
    // 0x80063E80: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80063E84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80063E88: beq         $a0, $zero, L_80063E9C
    if (ctx->r4 == 0) {
        // 0x80063E8C: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_80063E9C;
    }
    // 0x80063E8C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80063E90: jal         0x800647D0
    // 0x80063E94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _filterBuffer(rdram, ctx);
        goto after_6;
    // 0x80063E94: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x80063E98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063E9C:
    // 0x80063E9C: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80063EA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80063EA4: bne         $t9, $zero, L_80063EC0
    if (ctx->r25 != 0) {
        // 0x80063EA8: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80063EC0;
    }
    // 0x80063EA8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80063EAC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80063EB0: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80063EB4: jal         0x80064638
    // 0x80063EB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer(rdram, ctx);
        goto after_7;
    // 0x80063EB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x80063EBC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80063EC0:
    // 0x80063EC0: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x80063EC4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80063EC8: beq         $v1, $zero, L_80063EF0
    if (ctx->r3 == 0) {
        // 0x80063ECC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80063EF0;
    }
    // 0x80063ECC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80063ED0: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80063ED4: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80063ED8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80063EDC: ori         $t9, $t6, 0x800
    ctx->r25 = ctx->r14 | 0X800;
    // 0x80063EE0: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80063EE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80063EE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80063EEC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80063EF0:
    // 0x80063EF0: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x80063EF4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80063EF8: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x80063EFC: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80063F00: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80063F04: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80063F08: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80063F0C: bne         $at, $zero, L_80063D48
    if (ctx->r1 != 0) {
        // 0x80063F10: addu        $v1, $v0, $t8
        ctx->r3 = ADD32(ctx->r2, ctx->r24);
            goto L_80063D48;
    }
    // 0x80063F10: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
L_80063F14:
    // 0x80063F14: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x80063F18: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x80063F1C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80063F20: lw          $t5, 0x14($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X14);
    // 0x80063F24: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80063F28: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80063F2C: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80063F30: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x80063F34: beq         $at, $zero, L_80063F44
    if (ctx->r1 == 0) {
        // 0x80063F38: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_80063F44;
    }
    // 0x80063F38: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x80063F3C: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x80063F40: sw          $t9, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r25;
L_80063F44:
    // 0x80063F44: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x80063F48: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80063F4C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80063F50: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80063F54: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x80063F58: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80063F5C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80063F60: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x80063F64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80063F68:
    // 0x80063F68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80063F6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80063F70: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80063F74: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80063F78: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80063F7C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80063F80: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80063F84: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80063F88: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80063F8C: jr          $ra
    // 0x80063F90: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80063F90: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void weapon_projectile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E694: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8003E698: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003E69C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003E6A0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8003E6A4: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8003E6A8: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E6AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E6B0: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x8003E6B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003E6B8: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8003E6BC: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x8003E6C0: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003E6C4: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x8003E6C8: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8003E6CC: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003E6D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E6D4: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8003E6D8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003E6DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003E6E0: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x8003E6E4: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8003E6E8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8003E6EC: sh          $t8, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r24;
    // 0x8003E6F0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8003E6F4: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x8003E6F8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8003E6FC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8003E700: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8003E704: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8003E708: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8003E70C: jal         0x8006FC30
    // 0x8003E710: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8003E710: sh          $t9, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r25;
    after_0:
    // 0x8003E714: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E718: lw          $a3, 0x10($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X10);
    // 0x8003E71C: addiu       $t0, $s0, 0x1C
    ctx->r8 = ADD32(ctx->r16, 0X1C);
    // 0x8003E720: addiu       $t1, $s0, 0x20
    ctx->r9 = ADD32(ctx->r16, 0X20);
    // 0x8003E724: addiu       $t2, $s0, 0x24
    ctx->r10 = ADD32(ctx->r16, 0X24);
    // 0x8003E728: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E72C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003E730: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8003E734: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8003E738: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003E73C: jal         0x8006F64C
    // 0x8003E740: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8003E740: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x8003E744: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E748: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8003E74C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8003E750: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8003E754: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003E758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E75C: bne         $t4, $zero, L_8003E778
    if (ctx->r12 != 0) {
        // 0x8003E760: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003E778;
    }
    // 0x8003E760: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003E764: lwc1        $f5, 0x61F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X61F0);
    // 0x8003E768: lwc1        $f4, 0x61F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61F4);
    // 0x8003E76C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003E770: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8003E774: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_8003E778:
    // 0x8003E778: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003E77C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003E780: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003E784: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E788: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E78C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003E790: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003E794: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    // 0x8003E798: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E79C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003E7A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003E7A4: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003E7A8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003E7AC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003E7B0: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x8003E7B4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003E7B8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003E7BC: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003E7C0: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8003E7C4: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x8003E7C8: lbu         $t5, 0x18($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E7CC: nop

    // 0x8003E7D0: beq         $t5, $at, L_8003E84C
    if (ctx->r13 == ctx->r1) {
        // 0x8003E7D4: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003E84C;
    }
    // 0x8003E7D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003E7D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E7DC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8003E7E0: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    // 0x8003E7E4: jal         0x80031130
    // 0x8003E7E8: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003E7E8: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8003E7EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8003E7F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8003E7F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003E7F8: addiu       $t8, $sp, 0xA4
    ctx->r24 = ADD32(ctx->r29, 0XA4);
    // 0x8003E7FC: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x8003E800: sb          $t6, 0x97($sp)
    MEM_B(0X97, ctx->r29) = ctx->r14;
    // 0x8003E804: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003E808: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003E80C: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x8003E810: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    // 0x8003E814: jal         0x80031600
    // 0x8003E818: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003E818: addiu       $a3, $sp, 0x97
    ctx->r7 = ADD32(ctx->r29, 0X97);
    after_3:
    // 0x8003E81C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8003E820: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E824: blez        $t9, L_8003E84C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003E828: addiu       $a0, $sp, 0xB0
        ctx->r4 = ADD32(ctx->r29, 0XB0);
            goto L_8003E84C;
    }
    // 0x8003E828: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x8003E82C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8003E830: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8003E834: jal         0x8002ACD4
    // 0x8003E838: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    get_collision_normal(rdram, ctx);
        goto after_4;
    // 0x8003E838: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8003E83C: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E840: beq         $v0, $zero, L_8003E84C
    if (ctx->r2 == 0) {
        // 0x8003E844: nop
    
            goto L_8003E84C;
    }
    // 0x8003E844: nop

    // 0x8003E848: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E84C:
    // 0x8003E84C: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8003E850: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003E854: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8003E858: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8003E85C: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8003E860: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E864: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003E868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E86C: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003E870: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E874: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003E878: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8003E87C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8003E880: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    // 0x8003E884: swc1        $f12, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f12.u32l;
    // 0x8003E888: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8003E88C: jal         0x80011570
    // 0x8003E890: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    move_object(rdram, ctx);
        goto after_5;
    // 0x8003E890: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8003E894: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003E898: beq         $v0, $zero, L_8003E8A4
    if (ctx->r2 == 0) {
        // 0x8003E89C: nop
    
            goto L_8003E8A4;
    }
    // 0x8003E89C: nop

    // 0x8003E8A0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E8A4:
    // 0x8003E8A4: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E8A8: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003E8AC: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8003E8B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003E8B4: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8003E8B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E8BC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003E8C0: nop

    // 0x8003E8C4: div.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8003E8C8: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x8003E8CC: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003E8D0: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003E8D4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003E8D8: nop

    // 0x8003E8DC: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8003E8E0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003E8E4: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8003E8E8: bc1f        L_8003E8F4
    if (!c1cs) {
        // 0x8003E8EC: nop
    
            goto L_8003E8F4;
    }
    // 0x8003E8EC: nop

    // 0x8003E8F0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003E8F4:
    // 0x8003E8F4: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E8F8: nop

    // 0x8003E8FC: bne         $v0, $zero, L_8003E98C
    if (ctx->r2 != 0) {
        // 0x8003E900: nop
    
            goto L_8003E98C;
    }
    // 0x8003E900: nop

    // 0x8003E904: jal         0x8001BA64
    // 0x8003E908: nop

    get_checkpoint_count(rdram, ctx);
        goto after_6;
    // 0x8003E908: nop

    after_6:
    // 0x8003E90C: blez        $v0, L_8003E984
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E910: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_8003E984;
    }
    // 0x8003E910: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8003E914: lb          $a0, 0x19($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X19);
    // 0x8003E918: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8003E91C: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x8003E920: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x8003E924: addiu       $t0, $s1, 0xC
    ctx->r8 = ADD32(ctx->r17, 0XC);
    // 0x8003E928: addiu       $t1, $sp, 0x97
    ctx->r9 = ADD32(ctx->r29, 0X97);
    // 0x8003E92C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003E930: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003E934: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x8003E938: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003E93C: jal         0x800185E4
    // 0x8003E940: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    checkpoint_is_passed(rdram, ctx);
        goto after_7;
    // 0x8003E940: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8003E944: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x8003E948: bne         $v0, $zero, L_8003E978
    if (ctx->r2 != 0) {
        // 0x8003E94C: nop
    
            goto L_8003E978;
    }
    // 0x8003E94C: nop

    // 0x8003E950: lb          $t2, 0x19($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X19);
    // 0x8003E954: nop

    // 0x8003E958: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8003E95C: sb          $t3, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r11;
    // 0x8003E960: lb          $t4, 0x19($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X19);
    // 0x8003E964: nop

    // 0x8003E968: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003E96C: bne         $at, $zero, L_8003E978
    if (ctx->r1 != 0) {
        // 0x8003E970: nop
    
            goto L_8003E978;
    }
    // 0x8003E970: nop

    // 0x8003E974: sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
L_8003E978:
    // 0x8003E978: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E97C: b           L_8003E98C
    // 0x8003E980: nop

        goto L_8003E98C;
    // 0x8003E980: nop

L_8003E984:
    // 0x8003E984: lbu         $v0, 0x18($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X18);
    // 0x8003E988: sb          $t5, 0x19($s1)
    MEM_B(0X19, ctx->r17) = ctx->r13;
L_8003E98C:
    // 0x8003E98C: bne         $v0, $zero, L_8003E9AC
    if (ctx->r2 != 0) {
        // 0x8003E990: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003E9AC;
    }
    // 0x8003E990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E994: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E99C: jal         0x8003EDD8
    // 0x8003E9A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    homing_rocket_prevent_overshoot(rdram, ctx);
        goto after_8;
    // 0x8003E9A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x8003E9A4: b           L_8003E9BC
    // 0x8003E9A8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
        goto L_8003E9BC;
    // 0x8003E9A8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9AC:
    // 0x8003E9AC: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x8003E9B0: jal         0x8003EC14
    // 0x8003E9B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rocket_prevent_overshoot(rdram, ctx);
        goto after_9;
    // 0x8003E9B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x8003E9B8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
L_8003E9BC:
    // 0x8003E9BC: nop

    // 0x8003E9C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003E9C4: nop

    // 0x8003E9C8: beq         $v0, $zero, L_8003EB04
    if (ctx->r2 == 0) {
        // 0x8003E9CC: nop
    
            goto L_8003EB04;
    }
    // 0x8003E9CC: nop

    // 0x8003E9D0: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8003E9D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003E9D8: bne         $v0, $t6, L_8003EA0C
    if (ctx->r2 != ctx->r14) {
        // 0x8003E9DC: addiu       $a0, $zero, 0x1C2
        ctx->r4 = ADD32(0, 0X1C2);
            goto L_8003EA0C;
    }
    // 0x8003E9DC: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x8003E9E0: jal         0x8000C8B4
    // 0x8003E9E4: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x8003E9E4: sw          $v0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r2;
    after_10:
    // 0x8003E9E8: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x8003E9EC: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8003E9F0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003E9F4: beq         $at, $zero, L_8003EB04
    if (ctx->r1 == 0) {
        // 0x8003E9F8: nop
    
            goto L_8003EB04;
    }
    // 0x8003E9F8: nop

    // 0x8003E9FC: beq         $v1, $zero, L_8003EB04
    if (ctx->r3 == 0) {
        // 0x8003EA00: nop
    
            goto L_8003EB04;
    }
    // 0x8003EA00: nop

    // 0x8003EA04: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x8003EA08: nop

L_8003EA0C:
    // 0x8003EA0C: lbu         $t7, 0x18($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X18);
    // 0x8003EA10: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8003EA14: bne         $t7, $zero, L_8003EA3C
    if (ctx->r15 != 0) {
        // 0x8003EA18: nop
    
            goto L_8003EA3C;
    }
    // 0x8003EA18: nop

    // 0x8003EA1C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8003EA20: nop

    // 0x8003EA24: bne         $a1, $t8, L_8003EA34
    if (ctx->r5 != ctx->r24) {
        // 0x8003EA28: nop
    
            goto L_8003EA34;
    }
    // 0x8003EA28: nop

    // 0x8003EA2C: b           L_8003EA3C
    // 0x8003EA30: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_8003EA3C;
    // 0x8003EA30: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_8003EA34:
    // 0x8003EA34: b           L_8003EA3C
    // 0x8003EA38: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8003EA3C;
    // 0x8003EA38: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8003EA3C:
    // 0x8003EA3C: lbu         $t9, 0x13($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13);
    // 0x8003EA40: nop

    // 0x8003EA44: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EA48: beq         $at, $zero, L_8003EB04
    if (ctx->r1 == 0) {
        // 0x8003EA4C: nop
    
            goto L_8003EB04;
    }
    // 0x8003EA4C: nop

    // 0x8003EA50: lw          $t0, 0x40($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X40);
    // 0x8003EA54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003EA58: lb          $t1, 0x54($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X54);
    // 0x8003EA5C: nop

    // 0x8003EA60: bne         $a0, $t1, L_8003EAC4
    if (ctx->r4 != ctx->r9) {
        // 0x8003EA64: nop
    
            goto L_8003EAC4;
    }
    // 0x8003EA64: nop

    // 0x8003EA68: lw          $v1, 0x64($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X64);
    // 0x8003EA6C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8003EA70: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
    // 0x8003EA74: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x8003EA78: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8003EA7C: lw          $v0, 0x64($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X64);
    // 0x8003EA80: bne         $a2, $t3, L_8003EA98
    if (ctx->r6 != ctx->r11) {
        // 0x8003EA84: nop
    
            goto L_8003EA98;
    }
    // 0x8003EA84: nop

    // 0x8003EA88: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8003EA8C: nop

    // 0x8003EA90: beq         $a2, $t4, L_8003EAA8
    if (ctx->r6 == ctx->r12) {
        // 0x8003EA94: nop
    
            goto L_8003EAA8;
    }
    // 0x8003EA94: nop

L_8003EA98:
    // 0x8003EA98: lbu         $t5, 0x1EF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1EF);
    // 0x8003EA9C: nop

    // 0x8003EAA0: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x8003EAA4: sb          $t6, 0x1EF($v0)
    MEM_B(0X1EF, ctx->r2) = ctx->r14;
L_8003EAA8:
    // 0x8003EAA8: lb          $t7, 0x1D8($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D8);
    // 0x8003EAAC: nop

    // 0x8003EAB0: bne         $t7, $zero, L_8003EAC4
    if (ctx->r15 != 0) {
        // 0x8003EAB4: nop
    
            goto L_8003EAC4;
    }
    // 0x8003EAB4: nop

    // 0x8003EAB8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8003EABC: jal         0x80072348
    // 0x8003EAC0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rumble_set(rdram, ctx);
        goto after_11;
    // 0x8003EAC0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_11:
L_8003EAC4:
    // 0x8003EAC4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EAC8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EACC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EAD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EAD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EAD8: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003EADC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003EAE0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8003EAE4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003EAE8: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EAEC: jal         0x8003FC44
    // 0x8003EAF0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_12;
    // 0x8003EAF0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8003EAF4: jal         0x8000FFB8
    // 0x8003EAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_13;
    // 0x8003EAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8003EAFC: b           L_8003EC04
    // 0x8003EB00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003EC04;
    // 0x8003EB00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EB04:
    // 0x8003EB04: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x8003EB08: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EB0C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x8003EB10: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8003EB14: beq         $v1, $zero, L_8003EBB4
    if (ctx->r3 == 0) {
        // 0x8003EB18: sw          $t2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r10;
            goto L_8003EBB4;
    }
    // 0x8003EB18: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x8003EB1C: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
    // 0x8003EB20: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8003EB24: beq         $at, $zero, L_8003EB4C
    if (ctx->r1 == 0) {
        // 0x8003EB28: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8003EB4C;
    }
    // 0x8003EB28: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8003EB2C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8003EB30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003EB34: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EB38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EB3C: nop

    // 0x8003EB40: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8003EB44: b           L_8003EBB4
    // 0x8003EB48: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBB4;
    // 0x8003EB48: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EB4C:
    // 0x8003EB4C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8003EB50: beq         $at, $zero, L_8003EB88
    if (ctx->r1 == 0) {
        // 0x8003EB54: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003EB88;
    }
    // 0x8003EB54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003EB58: addiu       $t3, $v0, -0x8
    ctx->r11 = ADD32(ctx->r2, -0X8);
    // 0x8003EB5C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8003EB60: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EB64: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003EB68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EB6C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003EB70: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003EB74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EB78: nop

    // 0x8003EB7C: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003EB80: b           L_8003EBB4
    // 0x8003EB84: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
        goto L_8003EBB4;
    // 0x8003EB84: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8003EB88:
    // 0x8003EB88: sll         $t4, $a0, 28
    ctx->r12 = S32(ctx->r4 << 28);
    // 0x8003EB8C: jal         0x800707C4
    // 0x8003EB90: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_14;
    // 0x8003EB90: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_14:
    // 0x8003EB94: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003EB98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EB9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003EBA0: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003EBA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EBA8: nop

    // 0x8003EBAC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003EBB0: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8003EBB4:
    // 0x8003EBB4: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8003EBB8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8003EBBC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003EBC0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003EBC4: bgez        $t8, L_8003EC00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003EBC8: sw          $t8, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r24;
            goto L_8003EC00;
    }
    // 0x8003EBC8: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003EBCC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003EBD0: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003EBD4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003EBD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EBDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003EBE0: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x8003EBE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003EBE8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003EBEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003EBF0: jal         0x8003FC44
    // 0x8003EBF4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_15;
    // 0x8003EBF4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x8003EBF8: jal         0x8000FFB8
    // 0x8003EBFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_16;
    // 0x8003EBFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_8003EC00:
    // 0x8003EC00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003EC04:
    // 0x8003EC04: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003EC08: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003EC0C: jr          $ra
    // 0x8003EC10: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8003EC10: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void sprite_init_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CDC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CDC4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007CDC8: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007CDCC: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007CDD0: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007CDD4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007CDD8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007CDDC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007CDE0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007CDE4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007CDE8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007CDEC: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007CDF0: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x8007CDF4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8007CDF8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8007CDFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8007CE00: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007CE04: lbu         $s2, 0xC($a3)
    ctx->r18 = MEM_BU(ctx->r7, 0XC);
    // 0x8007CE08: lbu         $fp, 0xD($a3)
    ctx->r30 = MEM_BU(ctx->r7, 0XD);
    // 0x8007CE0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007CE10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007CE14: lw          $t1, 0x6364($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6364);
    // 0x8007CE18: lw          $v0, 0x6360($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6360);
    // 0x8007CE1C: lw          $v1, 0x6368($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6368);
    // 0x8007CE20: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007CE24: beq         $at, $zero, L_8007CE50
    if (ctx->r1 == 0) {
        // 0x8007CE28: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8007CE50;
    }
    // 0x8007CE28: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007CE2C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8007CE30: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8007CE34: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8007CE38: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8007CE3C: nop

    // 0x8007CE40: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8007CE44: nop

    // 0x8007CE48: andi        $t9, $t8, 0x3B
    ctx->r25 = ctx->r24 & 0X3B;
    // 0x8007CE4C: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
L_8007CE50:
    // 0x8007CE50: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007CE54: beq         $at, $zero, L_8007D088
    if (ctx->r1 == 0) {
        // 0x8007CE58: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8007D088;
    }
    // 0x8007CE58: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007CE5C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8007CE60: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007CE64: sll         $s3, $s2, 2
    ctx->r19 = S32(ctx->r18 << 2);
    // 0x8007CE68: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8007CE6C: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x8007CE70: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8007CE74: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x8007CE78: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007CE7C:
    // 0x8007CE7C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007CE80: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8007CE84: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8007CE88: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8007CE8C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8007CE90: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8007CE94: lbu         $s0, 0x0($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X0);
    // 0x8007CE98: lbu         $s1, 0x1($a0)
    ctx->r17 = MEM_BU(ctx->r4, 0X1);
    // 0x8007CE9C: lb          $t9, 0x3($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X3);
    // 0x8007CEA0: lb          $t8, 0x4($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X4);
    // 0x8007CEA4: subu        $t0, $t9, $t6
    ctx->r8 = SUB32(ctx->r25, ctx->r14);
    // 0x8007CEA8: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x8007CEAC: addu        $t3, $t0, $s0
    ctx->r11 = ADD32(ctx->r8, ctx->r16);
    // 0x8007CEB0: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x8007CEB4: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8007CEB8: subu        $t4, $a2, $s1
    ctx->r12 = SUB32(ctx->r6, ctx->r17);
    // 0x8007CEBC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8007CEC0: sh          $a3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r7;
    // 0x8007CEC4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8007CEC8: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x8007CECC: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x8007CED0: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8007CED4: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x8007CED8: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x8007CEDC: sh          $a3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r7;
    // 0x8007CEE0: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8007CEE4: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x8007CEE8: sb          $a1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r5;
    // 0x8007CEEC: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8007CEF0: sb          $a1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r5;
    // 0x8007CEF4: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8007CEF8: sh          $t4, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r12;
    // 0x8007CEFC: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8007CF00: sb          $a1, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r5;
    // 0x8007CF04: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x8007CF08: sb          $a1, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r5;
    // 0x8007CF0C: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
    // 0x8007CF10: sh          $t0, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r8;
    // 0x8007CF14: sh          $t4, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r12;
    // 0x8007CF18: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
    // 0x8007CF1C: sb          $a1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r5;
    // 0x8007CF20: sb          $a1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r5;
    // 0x8007CF24: sb          $a1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r5;
    // 0x8007CF28: sb          $a1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r5;
    // 0x8007CF2C: lh          $a3, 0xA($a0)
    ctx->r7 = MEM_H(ctx->r4, 0XA);
    // 0x8007CF30: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007CF34: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x8007CF38: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8007CF3C: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007CF40: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8007CF44: or          $t7, $t6, $ra
    ctx->r15 = ctx->r14 | ctx->r31;
    // 0x8007CF48: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007CF4C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007CF50: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8007CF54: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8007CF58: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x8007CF5C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007CF60: bne         $t5, $zero, L_8007CFCC
    if (ctx->r13 != 0) {
        // 0x8007CF64: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_8007CFCC;
    }
    // 0x8007CF64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007CF68: subu        $t0, $fp, $s2
    ctx->r8 = SUB32(ctx->r30, ctx->r18);
    // 0x8007CF6C: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8007CF70: bne         $at, $zero, L_8007CF7C
    if (ctx->r1 != 0) {
        // 0x8007CF74: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_8007CF7C;
    }
    // 0x8007CF74: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8007CF78: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8007CF7C:
    // 0x8007CF7C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8007CF80: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8007CF84: addu        $a3, $s6, $s4
    ctx->r7 = ADD32(ctx->r22, ctx->r20);
    // 0x8007CF88: andi        $t8, $a3, 0x6
    ctx->r24 = ctx->r7 & 0X6;
    // 0x8007CF8C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8007CF90: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007CF94: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x8007CF98: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8007CF9C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8007CFA0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007CFA4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8007CFA8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007CFAC: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x8007CFB0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8007CFB4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8007CFB8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007CFBC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007CFC0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007CFC4: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x8007CFC8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8007CFCC:
    // 0x8007CFCC: lui         $t9, 0x511
    ctx->r25 = S32(0X511 << 16);
    // 0x8007CFD0: ori         $t9, $t9, 0x20
    ctx->r25 = ctx->r25 | 0X20;
    // 0x8007CFD4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007CFD8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007CFDC: addu        $t7, $v1, $s4
    ctx->r15 = ADD32(ctx->r3, ctx->r20);
    // 0x8007CFE0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007CFE4: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    // 0x8007CFE8: addiu       $a3, $s1, -0x1
    ctx->r7 = ADD32(ctx->r17, -0X1);
    // 0x8007CFEC: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007CFF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007CFF4: sll         $t8, $a2, 5
    ctx->r24 = S32(ctx->r6 << 5);
    // 0x8007CFF8: sll         $t9, $a3, 5
    ctx->r25 = S32(ctx->r7 << 5);
    // 0x8007CFFC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8007D000: addiu       $t6, $t2, 0x2
    ctx->r14 = ADD32(ctx->r10, 0X2);
    // 0x8007D004: addiu       $a0, $t2, 0x4
    ctx->r4 = ADD32(ctx->r10, 0X4);
    // 0x8007D008: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8007D00C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8007D010: sb          $s7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r23;
    // 0x8007D014: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x8007D018: sb          $t6, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r14;
    // 0x8007D01C: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x8007D020: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8007D024: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x8007D028: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8007D02C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8007D030: sh          $s5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r21;
    // 0x8007D034: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8007D038: sb          $s7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r23;
    // 0x8007D03C: sb          $a0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r4;
    // 0x8007D040: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8007D044: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8007D048: sh          $s5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r21;
    // 0x8007D04C: sh          $t9, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r25;
    // 0x8007D050: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x8007D054: sh          $t9, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r25;
    // 0x8007D058: sh          $s5, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r21;
    // 0x8007D05C: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8007D060: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8007D064: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8007D068: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D06C: bne         $at, $zero, L_8007D07C
    if (ctx->r1 != 0) {
        // 0x8007D070: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8007D07C;
    }
    // 0x8007D070: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8007D074: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8007D078: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D07C:
    // 0x8007D07C: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8007D080: bne         $at, $zero, L_8007CE7C
    if (ctx->r1 != 0) {
        // 0x8007D084: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8007CE7C;
    }
    // 0x8007D084: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8007D088:
    // 0x8007D088: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D08C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D090: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D094: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007D098: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x8007D09C: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x8007D0A0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007D0A4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007D0A8: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8007D0AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D0B0: sw          $t1, 0x6364($at)
    MEM_W(0X6364, ctx->r1) = ctx->r9;
    // 0x8007D0B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D0B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0BC: sw          $v0, 0x6360($at)
    MEM_W(0X6360, ctx->r1) = ctx->r2;
    // 0x8007D0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007D0C4: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007D0C8: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007D0CC: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007D0D0: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D0D4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007D0D8: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007D0DC: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007D0E0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007D0E4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007D0E8: sw          $v1, 0x6368($at)
    MEM_W(0X6368, ctx->r1) = ctx->r3;
    // 0x8007D0EC: jr          $ra
    // 0x8007D0F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007D0F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_file_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076AF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80076AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076AFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80076B00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80076B04: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80076B08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80076B0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80076B10: jal         0x80070C9C
    // 0x80076B14: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80076B14: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x80076B18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076B1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80076B20: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80076B24: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076B28: jal         0x80076610
    // 0x80076B2C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80076B2C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // 0x80076B30: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80076B34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80076B38: bne         $v0, $zero, L_80076B84
    if (ctx->r2 != 0) {
        // 0x80076B3C: lui         $at, 0x4741
        ctx->r1 = S32(0X4741 << 16);
            goto L_80076B84;
    }
    // 0x80076B3C: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x80076B40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076B44: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076B48: beq         $v0, $at, L_80076B70
    if (ctx->r2 == ctx->r1) {
        // 0x80076B4C: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_80076B70;
    }
    // 0x80076B4C: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80076B50: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80076B54: beq         $v0, $at, L_80076B80
    if (ctx->r2 == ctx->r1) {
        // 0x80076B58: lui         $at, 0x5449
        ctx->r1 = S32(0X5449 << 16);
            goto L_80076B80;
    }
    // 0x80076B58: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x80076B5C: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80076B60: beq         $v0, $at, L_80076B78
    if (ctx->r2 == ctx->r1) {
        // 0x80076B64: nop
    
            goto L_80076B78;
    }
    // 0x80076B64: nop

    // 0x80076B68: b           L_80076B84
    // 0x80076B6C: nop

        goto L_80076B84;
    // 0x80076B6C: nop

L_80076B70:
    // 0x80076B70: b           L_80076B84
    // 0x80076B74: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076B84;
    // 0x80076B74: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076B78:
    // 0x80076B78: b           L_80076B84
    // 0x80076B7C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076B84;
    // 0x80076B7C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076B80:
    // 0x80076B80: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80076B84:
    // 0x80076B84: jal         0x80071140
    // 0x80076B88: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80076B88: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80076B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076B90: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80076B94: jr          $ra
    // 0x80076B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80076B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSPNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062290: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80062294: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80062298: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8006229C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800622A0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x800622A4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800622A8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800622AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800622B0: lw          $t6, 0x3780($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3780);
    // 0x800622B4: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800622B8: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800622BC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800622C0: addiu       $t0, $zero, 0x3E80
    ctx->r8 = ADD32(0, 0X3E80);
    // 0x800622C4: sh          $t7, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r15;
    // 0x800622C8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800622CC: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x800622D0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800622D4: sh          $t9, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r25;
    // 0x800622D8: sw          $t0, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r8;
    // 0x800622DC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800622E0: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800622E4: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x800622E8: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800622EC: sw          $t1, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r9;
    // 0x800622F0: lw          $t2, 0x18($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X18);
    // 0x800622F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800622F8: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x800622FC: lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X1C);
    // 0x80062300: sb          $zero, 0x71($a0)
    MEM_B(0X71, ctx->r4) = 0;
    // 0x80062304: sw          $t3, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r11;
    // 0x80062308: lbu         $t4, 0x10($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X10);
    // 0x8006230C: sh          $t5, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r13;
    // 0x80062310: sb          $t4, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r12;
    // 0x80062314: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80062318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006231C: sb          $t6, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r14;
    // 0x80062320: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x80062324: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80062328: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006232C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062334: jal         0x800C77F0
    // 0x80062338: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80062338: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006233C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80062340: jal         0x8000AE90
    // 0x80062344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __initChanState(rdram, ctx);
        goto after_1;
    // 0x80062344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80062348: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006234C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80062350: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x80062354: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80062358: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006235C: jal         0x800C77F0
    // 0x80062360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80062360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80062364: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80062368: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006236C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80062370: blez        $t9, L_800623A0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80062374: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800623A0;
    }
    // 0x80062374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80062378: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006237C:
    // 0x8006237C: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x80062380: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80062384: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80062388: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
    // 0x8006238C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80062390: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x80062394: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80062398: bne         $at, $zero, L_8006237C
    if (ctx->r1 != 0) {
        // 0x8006239C: nop
    
            goto L_8006237C;
    }
    // 0x8006239C: nop

L_800623A0:
    // 0x800623A0: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800623A4: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x800623A8: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x800623AC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800623B0: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800623B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800623B8: jal         0x800C77F0
    // 0x800623BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800623BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800623C0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800623C4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800623C8: jal         0x800C935C
    // 0x800623CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x800623CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x800623D0: lui         $t3, 0x8006
    ctx->r11 = S32(0X8006 << 16);
    // 0x800623D4: addiu       $t3, $t3, 0x2408
    ctx->r11 = ADD32(ctx->r11, 0X2408);
    // 0x800623D8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800623DC: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800623E0: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800623E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800623E8: lw          $a0, 0x3780($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3780);
    // 0x800623EC: jal         0x800C93D0
    // 0x800623F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x800623F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800623F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800623F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800623FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80062400: jr          $ra
    // 0x80062404: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80062404: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void transition_render_barndoor_diag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C254C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2550: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2554: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C2558: jal         0x8007B3D0
    // 0x800C255C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C255C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2560: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2564: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2568: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C256C: addiu       $t8, $t8, 0x3648
    ctx->r24 = ADD32(ctx->r24, 0X3648);
    // 0x800C2570: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C2574: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2578: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C257C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C2580: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C2584: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C2588: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C258C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C2590: addiu       $a3, $a3, 0x31D0
    ctx->r7 = ADD32(ctx->r7, 0X31D0);
    // 0x800C2594: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2598: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C259C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C25A0: addiu       $t1, $t1, 0x31C0
    ctx->r9 = ADD32(ctx->r9, 0X31C0);
    // 0x800C25A4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C25A8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C25AC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C25B0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C25B4: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C25B8: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C25BC: ori         $t8, $t7, 0x48
    ctx->r24 = ctx->r15 | 0X48;
    // 0x800C25C0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C25C4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C25C8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C25CC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C25D0: ori         $t4, $t3, 0xBC
    ctx->r12 = ctx->r11 | 0XBC;
    // 0x800C25D4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C25D8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C25DC: lui         $t3, 0x550
    ctx->r11 = S32(0X550 << 16);
    // 0x800C25E0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C25E4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C25E8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C25EC: ori         $t3, $t3, 0x60
    ctx->r11 = ctx->r11 | 0X60;
    // 0x800C25F0: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C25F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C25F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C25FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C2600: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C2604: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C2608: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C260C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C2610: nop

    // 0x800C2614: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2618: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C261C: lw          $t6, 0x31C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31C8);
    // 0x800C2620: nop

    // 0x800C2624: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C2628: jal         0x8007B3D0
    // 0x800C262C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C262C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C2630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2638: jr          $ra
    // 0x800C263C: nop

    return;
    // 0x800C263C: nop

;}
RECOMP_FUNC void trackMakeAbsolute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D30C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D310: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002D314: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002D318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D31C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002D320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D324: beq         $s0, $zero, L_8002D374
    if (ctx->r16 == 0) {
        // 0x8002D328: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002D374;
    }
    // 0x8002D328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D32C:
    // 0x8002D32C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8002D330: nop

    // 0x8002D334: beq         $v0, $zero, L_8002D340
    if (ctx->r2 == 0) {
        // 0x8002D338: addu        $t6, $v0, $s1
        ctx->r14 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D340;
    }
    // 0x8002D338: addu        $t6, $v0, $s1
    ctx->r14 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D33C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_8002D340:
    // 0x8002D340: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8002D344: nop

    // 0x8002D348: beq         $v0, $zero, L_8002D354
    if (ctx->r2 == 0) {
        // 0x8002D34C: addu        $t7, $v0, $s1
        ctx->r15 = ADD32(ctx->r2, ctx->r17);
            goto L_8002D354;
    }
    // 0x8002D34C: addu        $t7, $v0, $s1
    ctx->r15 = ADD32(ctx->r2, ctx->r17);
    // 0x8002D350: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
L_8002D354:
    // 0x8002D354: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8002D358: jal         0x8002D30C
    // 0x8002D35C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    trackMakeAbsolute(rdram, ctx);
        goto after_0;
    // 0x8002D35C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8002D360: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8002D364: nop

    // 0x8002D368: bne         $s0, $zero, L_8002D32C
    if (ctx->r16 != 0) {
        // 0x8002D36C: nop
    
            goto L_8002D32C;
    }
    // 0x8002D36C: nop

    // 0x8002D370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D374:
    // 0x8002D374: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002D378: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002D37C: jr          $ra
    // 0x8002D380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002D380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void timetrial_init_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B668: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B66C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B670: jal         0x800599A8
    // 0x8001B674: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B674: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B678: jal         0x8006BD88
    // 0x8001B67C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B67C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B680: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001B684: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B688: bne         $v0, $t6, L_8001B6A4
    if (ctx->r2 != ctx->r14) {
        // 0x8001B68C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8001B6A4;
    }
    // 0x8001B68C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B690: lh          $t7, -0x517E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X517E);
    // 0x8001B694: lh          $t8, -0x38D8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X38D8);
    // 0x8001B698: nop

    // 0x8001B69C: beq         $t7, $t8, L_8001B704
    if (ctx->r15 == ctx->r24) {
        // 0x8001B6A0: nop
    
            goto L_8001B704;
    }
    // 0x8001B6A0: nop

L_8001B6A4:
    // 0x8001B6A4: jal         0x8006BD88
    // 0x8001B6A8: nop

    level_id(rdram, ctx);
        goto after_2;
    // 0x8001B6A8: nop

    after_2:
    // 0x8001B6AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B6B0: lh          $a2, -0x517E($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X517E);
    // 0x8001B6B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B6B8: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x8001B6BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001B6C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B6C4: jal         0x800599B8
    // 0x8001B6C8: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    timetrial_load_player_ghost(rdram, ctx);
        goto after_3;
    // 0x8001B6C8: addiu       $a3, $sp, 0x2E
    ctx->r7 = ADD32(ctx->r29, 0X2E);
    after_3:
    // 0x8001B6CC: bne         $v0, $zero, L_8001B6FC
    if (ctx->r2 != 0) {
        // 0x8001B6D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001B6FC;
    }
    // 0x8001B6D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B6D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001B6D8: lh          $t0, -0x517E($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X517E);
    // 0x8001B6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B6E0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001B6E4: sh          $t0, -0x38D8($at)
    MEM_H(-0X38D8, ctx->r1) = ctx->r8;
    // 0x8001B6E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B6EC: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x8001B6F0: sh          $t1, -0x38D4($at)
    MEM_H(-0X38D4, ctx->r1) = ctx->r9;
    // 0x8001B6F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B6F8: sh          $t2, -0x38DC($at)
    MEM_H(-0X38DC, ctx->r1) = ctx->r10;
L_8001B6FC:
    // 0x8001B6FC: b           L_8001B728
    // 0x8001B700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8001B728;
    // 0x8001B700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001B704:
    // 0x8001B704: jal         0x8006BD88
    // 0x8001B708: nop

    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B708: nop

    after_4:
    // 0x8001B70C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B710: lh          $a2, -0x517E($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X517E);
    // 0x8001B714: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B71C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001B720: jal         0x800599B8
    // 0x8001B724: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    timetrial_load_player_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B724: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_8001B728:
    // 0x8001B728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B72C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001B730: jr          $ra
    // 0x8001B734: nop

    return;
    // 0x8001B734: nop

;}
RECOMP_FUNC void mempool_slot_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007178C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80071790: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071794: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071798: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x8007179C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800717A0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800717A4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800717A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800717AC: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x800717B0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800717B4: sh          $a3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r7;
    // 0x800717B8: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x800717BC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800717C0: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800717C4: beq         $at, $zero, L_80071844
    if (ctx->r1 == 0) {
        // 0x800717C8: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_80071844;
    }
    // 0x800717C8: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800717CC: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x800717D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800717D4: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800717D8: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800717DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800717E0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800717E4: lh          $a0, 0xE($t5)
    ctx->r4 = MEM_H(ctx->r13, 0XE);
    // 0x800717E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800717EC: multu       $a0, $t3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800717F0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800717F4: subu        $t4, $t1, $a2
    ctx->r12 = SUB32(ctx->r9, ctx->r6);
    // 0x800717F8: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800717FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80071800: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x80071804: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80071808: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8007180C: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x80071810: nop

    // 0x80071814: sh          $t5, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r13;
    // 0x80071818: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8007181C: sh          $a1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r5;
    // 0x80071820: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
    // 0x80071824: beq         $t1, $at, L_8007183C
    if (ctx->r9 == ctx->r1) {
        // 0x80071828: sh          $a0, 0xC($t0)
        MEM_H(0XC, ctx->r8) = ctx->r4;
            goto L_8007183C;
    }
    // 0x80071828: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x8007182C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071830: mflo        $t6
    ctx->r14 = lo;
    // 0x80071834: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80071838: sh          $a0, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r4;
L_8007183C:
    // 0x8007183C: jr          $ra
    // 0x80071840: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071840: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80071844:
    // 0x80071844: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80071848: jr          $ra
    // 0x8007184C: nop

    return;
    // 0x8007184C: nop

;}
RECOMP_FUNC void menu_init_arrow_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E4B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E4B4: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x8008E4B8: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x8008E4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E4C0: sw          $t6, 0x41C($at)
    MEM_W(0X41C, ctx->r1) = ctx->r14;
    // 0x8008E4C4: lw          $t7, 0xF0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF0);
    // 0x8008E4C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E4CC: sw          $t7, 0x42C($at)
    MEM_W(0X42C, ctx->r1) = ctx->r15;
    // 0x8008E4D0: lw          $t8, 0xFC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XFC);
    // 0x8008E4D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E4D8: sw          $t8, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r24;
    // 0x8008E4DC: lw          $t9, 0xF8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF8);
    // 0x8008E4E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E4E4: jr          $ra
    // 0x8008E4E8: sw          $t9, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r25;
    return;
    // 0x8008E4E8: sw          $t9, 0x44C($at)
    MEM_W(0X44C, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void hud_reset_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB1C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1CC: jr          $ra
    // 0x800AB1D0: sb          $zero, 0x6CD4($at)
    MEM_B(0X6CD4, ctx->r1) = 0;
    return;
    // 0x800AB1D0: sb          $zero, 0x6CD4($at)
    MEM_B(0X6CD4, ctx->r1) = 0;
;}
RECOMP_FUNC void set_frame_blackout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F42C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8006F430: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F434: jr          $ra
    // 0x8006F438: sb          $t6, -0x2C10($at)
    MEM_B(-0X2C10, ctx->r1) = ctx->r14;
    return;
    // 0x8006F438: sb          $t6, -0x2C10($at)
    MEM_B(-0X2C10, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void draw_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_hud_text_begin(uint8_t*, recomp_context*); dkr_hud_text_begin(rdram, ctx);
    // 0x800C4440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4444: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C4448: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C444C: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C4450: lw          $s0, -0x5818($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X5818);
    // 0x800C4454: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4458: bne         $a1, $v0, L_800C4474
    if (ctx->r5 != ctx->r2) {
        // 0x800C445C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800C4474;
    }
    // 0x800C445C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C4460: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x800C4464: nop

    // 0x800C4468: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C446C: b           L_800C4478
    // 0x800C4470: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C4478;
    // 0x800C4470: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C4474:
    // 0x800C4474: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
L_800C4478:
    // 0x800C4478: bne         $a2, $v0, L_800C4494
    if (ctx->r6 != ctx->r2) {
        // 0x800C447C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800C4494;
    }
    // 0x800C447C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C4480: lh          $t8, 0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XE);
    // 0x800C4484: nop

    // 0x800C4488: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C448C: b           L_800C4498
    // 0x800C4490: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
        goto L_800C4498;
    // 0x800C4490: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
L_800C4494:
    // 0x800C4494: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
L_800C4498:
    // 0x800C4498: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C449C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C44A0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C44A4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C44A8: jal         0x800C45A4
    // 0x800C44AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C44AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800C44B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C44B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    extern void dkr_hud_text_end(uint8_t*, recomp_context*); dkr_hud_text_end(rdram, ctx);
    // 0x800C44B8: jr          $ra
    // 0x800C44BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C44BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void calculate_ghost_header_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074A4C: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80074A50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074A54: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80074A58: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80074A5C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80074A60: addiu       $v0, $t8, 0x8
    ctx->r2 = ADD32(ctx->r24, 0X8);
    // 0x80074A64: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80074A68: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80074A6C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80074A70: bne         $at, $zero, L_80074AA0
    if (ctx->r1 != 0) {
        // 0x80074A74: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80074AA0;
    }
    // 0x80074A74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80074A78:
    // 0x80074A78: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80074A7C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80074A80: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80074A84: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80074A88: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80074A8C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80074A90: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074A94: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80074A98: bne         $at, $zero, L_80074A78
    if (ctx->r1 != 0) {
        // 0x80074A9C: sra         $v1, $t3, 16
        ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
            goto L_80074A78;
    }
    // 0x80074A9C: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
L_80074AA0:
    // 0x80074AA0: jr          $ra
    // 0x80074AA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80074AA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void increase_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4668: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B466C: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B4670: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B4674: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B4678: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B467C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B4680: addu        $v0, $t9, $a2
    ctx->r2 = ADD32(ctx->r25, ctx->r6);
    // 0x800B4684: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4688: beq         $at, $zero, L_800B4698
    if (ctx->r1 == 0) {
        // 0x800B468C: nop
    
            goto L_800B4698;
    }
    // 0x800B468C: nop

    // 0x800B4690: b           L_800B469C
    // 0x800B4694: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B469C;
    // 0x800B4694: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B4698:
    // 0x800B4698: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B469C:
    // 0x800B469C: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B46A0: nop

    // 0x800B46A4: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B46A8: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B46AC: nop

    // 0x800B46B0: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B46B4: jr          $ra
    // 0x800B46B8: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B46B8: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void render_title_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008377C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80083780: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80083784: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083788: addiu       $s0, $s0, 0x686C
    ctx->r16 = ADD32(ctx->r16, 0X686C);
    // 0x8008378C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083790: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80083794: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80083798: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8008379C: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800837A0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800837A4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800837A8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800837AC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800837B0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800837B4: beq         $t6, $zero, L_80083984
    if (ctx->r14 == 0) {
        // 0x800837B8: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_80083984;
    }
    // 0x800837B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800837BC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800837C0: addiu       $s6, $s6, 0x63A0
    ctx->r22 = ADD32(ctx->r22, 0X63A0);
    // 0x800837C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800837C8: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x800837CC: jal         0x80067F2C
    // 0x800837D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x800837D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x800837D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800837D8: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x800837DC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800837E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800837E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800837E8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800837EC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800837F0: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800837F4: addiu       $s7, $s7, -0x89C
    ctx->r23 = ADD32(ctx->r23, -0X89C);
    // 0x800837F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800837FC: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80083800: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80083804: jal         0x80068508
    // 0x80083808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80083808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008380C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80083810: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80083814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083818: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008381C: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80083820: addiu       $a1, $a1, -0x824
    ctx->r5 = ADD32(ctx->r5, -0X824);
    // 0x80083824: bc1t        L_80083864
    if (c1cs) {
        // 0x80083828: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80083864;
    }
    // 0x80083828: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008382C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083830: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x80083834: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80083838: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008383C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80083840: addiu       $a1, $a1, -0x824
    ctx->r5 = ADD32(ctx->r5, -0X824);
    // 0x80083844: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80083848: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x8008384C: lui         $a3, 0x4250
    ctx->r7 = S32(0X4250 << 16);
    // 0x80083850: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80083854: jal         0x80078D00
    // 0x80083858: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_2;
    // 0x80083858: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8008385C: b           L_80083890
    // 0x80083860: nop

        goto L_80083890;
    // 0x80083860: nop

L_80083864:
    // 0x80083864: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80083868: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008386C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80083870: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80083874: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80083878: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008387C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80083880: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80083884: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80083888: jal         0x80078AB8
    // 0x8008388C: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_3;
    // 0x8008388C: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_3:
L_80083890:
    // 0x80083890: jal         0x8006F4C8
    // 0x80083894: nop

    is_controller_missing(rdram, ctx);
        goto after_4;
    // 0x80083894: nop

    after_4:
    // 0x80083898: bne         $v0, $zero, L_800839B8
    if (ctx->r2 != 0) {
        // 0x8008389C: lui         $t5, 0x8000
        ctx->r13 = S32(0X8000 << 16);
            goto L_800839B8;
    }
    // 0x8008389C: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800838A0: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x800838A4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800838A8: bne         $t5, $zero, L_800838B8
    if (ctx->r13 != 0) {
        // 0x800838AC: addiu       $s2, $zero, 0xC0
        ctx->r18 = ADD32(0, 0XC0);
            goto L_800838B8;
    }
    // 0x800838AC: addiu       $s2, $zero, 0xC0
    ctx->r18 = ADD32(0, 0XC0);
    // 0x800838B0: b           L_800838B8
    // 0x800838B4: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
        goto L_800838B8;
    // 0x800838B4: addiu       $s2, $zero, 0xDA
    ctx->r18 = ADD32(0, 0XDA);
L_800838B8:
    // 0x800838B8: jal         0x800C42EC
    // 0x800838BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x800838BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800838C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800838C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800838C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800838CC: jal         0x800C43CC
    // 0x800838D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_6;
    // 0x800838D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800838D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800838D8: lw          $t6, -0x85C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X85C);
    // 0x800838DC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800838E0: beq         $t6, $zero, L_800839B8
    if (ctx->r14 == 0) {
        // 0x800838E4: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800839B8;
    }
    // 0x800838E4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800838E8: addiu       $t8, $t8, -0x85C
    ctx->r24 = ADD32(ctx->r24, -0X85C);
    // 0x800838EC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800838F0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800838F4: addiu       $s3, $s3, -0xBA4
    ctx->r19 = ADD32(ctx->r19, -0XBA4);
    // 0x800838F8: addiu       $s4, $s4, 0x63BC
    ctx->r20 = ADD32(ctx->r20, 0X63BC);
    // 0x800838FC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80083900: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_80083904:
    // 0x80083904: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80083908: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008390C: bne         $s1, $t9, L_80083938
    if (ctx->r17 != ctx->r25) {
        // 0x80083910: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80083938;
    }
    // 0x80083910: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083914: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x80083918: nop

    // 0x8008391C: andi        $t0, $a3, 0x1F
    ctx->r8 = ctx->r7 & 0X1F;
    // 0x80083920: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80083924: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80083928: bne         $at, $zero, L_8008393C
    if (ctx->r1 != 0) {
        // 0x8008392C: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8008393C;
    }
    // 0x8008392C: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80083930: b           L_8008393C
    // 0x80083934: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
        goto L_8008393C;
    // 0x80083934: subu        $a3, $s5, $t1
    ctx->r7 = SUB32(ctx->r21, ctx->r9);
L_80083938:
    // 0x80083938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008393C:
    // 0x8008393C: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80083940: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80083944: jal         0x800C4384
    // 0x80083948: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80083948: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_7:
    // 0x8008394C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80083950: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80083954: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80083958: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008395C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80083960: jal         0x800C4440
    // 0x80083964: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80083964: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80083968: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8008396C: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80083970: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083974: bne         $t4, $zero, L_80083904
    if (ctx->r12 != 0) {
        // 0x80083978: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80083904;
    }
    // 0x80083978: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008397C: b           L_800839BC
    // 0x80083980: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800839BC;
    // 0x80083980: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80083984:
    // 0x80083984: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083988: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008398C: lw          $t5, 0x6864($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6864);
    // 0x80083990: lw          $v0, 0x6874($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6874);
    // 0x80083994: nop

    // 0x80083998: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8008399C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x800839A0: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x800839A4: nop

    // 0x800839A8: bne         $t7, $t8, L_800839BC
    if (ctx->r15 != ctx->r24) {
        // 0x800839AC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800839BC;
    }
    // 0x800839AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800839B0: jal         0x80083098
    // 0x800839B4: nop

    func_80083098(rdram, ctx);
        goto after_9;
    // 0x800839B4: nop

    after_9:
L_800839B8:
    // 0x800839B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800839BC:
    // 0x800839BC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800839C0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800839C4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800839C8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800839CC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800839D0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800839D4: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800839D8: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800839DC: jr          $ra
    // 0x800839E0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800839E0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void lensflare_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC8A8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AC8AC: addiu       $a1, $a1, 0x2A80
    ctx->r5 = ADD32(ctx->r5, 0X2A80);
    // 0x800AC8B0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x800AC8B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC8B8: sw          $zero, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = 0;
    // 0x800AC8BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AC8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AC8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC8C8: lw          $v1, 0x3C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X3C);
    // 0x800AC8CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC8D0: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    // 0x800AC8D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AC8D8: beq         $v0, $a2, L_800AC904
    if (ctx->r2 == ctx->r6) {
        // 0x800AC8DC: addiu       $a1, $a1, 0x7C30
        ctx->r5 = ADD32(ctx->r5, 0X7C30);
            goto L_800AC904;
    }
    // 0x800AC8DC: addiu       $a1, $a1, 0x7C30
    ctx->r5 = ADD32(ctx->r5, 0X7C30);
    // 0x800AC8E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AC8E4: beq         $v0, $at, L_800AC918
    if (ctx->r2 == ctx->r1) {
        // 0x800AC8E8: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800AC918;
    }
    // 0x800AC8E8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AC8EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AC8F0: beq         $v0, $at, L_800AC928
    if (ctx->r2 == ctx->r1) {
        // 0x800AC8F4: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800AC928;
    }
    // 0x800AC8F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AC8F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC8FC: b           L_800AC934
    // 0x800AC900: sw          $zero, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = 0;
        goto L_800AC934;
    // 0x800AC900: sw          $zero, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = 0;
L_800AC904:
    // 0x800AC904: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AC908: addiu       $t7, $t7, 0x29A0
    ctx->r15 = ADD32(ctx->r15, 0X29A0);
    // 0x800AC90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC910: b           L_800AC934
    // 0x800AC914: sw          $t7, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = ctx->r15;
        goto L_800AC934;
    // 0x800AC914: sw          $t7, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = ctx->r15;
L_800AC918:
    // 0x800AC918: addiu       $t8, $t8, 0x29E0
    ctx->r24 = ADD32(ctx->r24, 0X29E0);
    // 0x800AC91C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC920: b           L_800AC934
    // 0x800AC924: sw          $t8, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = ctx->r24;
        goto L_800AC934;
    // 0x800AC924: sw          $t8, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = ctx->r24;
L_800AC928:
    // 0x800AC928: addiu       $t9, $t9, 0x2A30
    ctx->r25 = ADD32(ctx->r25, 0X2A30);
    // 0x800AC92C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC930: sw          $t9, 0x7C24($at)
    MEM_W(0X7C24, ctx->r1) = ctx->r25;
L_800AC934:
    // 0x800AC934: lbu         $v0, 0xD($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD);
    // 0x800AC938: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AC93C: beq         $v0, $a2, L_800AC968
    if (ctx->r2 == ctx->r6) {
        // 0x800AC940: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_800AC968;
    }
    // 0x800AC940: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800AC944: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AC948: beq         $v0, $at, L_800AC97C
    if (ctx->r2 == ctx->r1) {
        // 0x800AC94C: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800AC97C;
    }
    // 0x800AC94C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AC950: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AC954: beq         $v0, $at, L_800AC98C
    if (ctx->r2 == ctx->r1) {
        // 0x800AC958: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800AC98C;
    }
    // 0x800AC958: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AC95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC960: b           L_800AC998
    // 0x800AC964: sw          $zero, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = 0;
        goto L_800AC998;
    // 0x800AC964: sw          $zero, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = 0;
L_800AC968:
    // 0x800AC968: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AC96C: addiu       $t0, $t0, 0x29A0
    ctx->r8 = ADD32(ctx->r8, 0X29A0);
    // 0x800AC970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC974: b           L_800AC998
    // 0x800AC978: sw          $t0, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = ctx->r8;
        goto L_800AC998;
    // 0x800AC978: sw          $t0, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = ctx->r8;
L_800AC97C:
    // 0x800AC97C: addiu       $t1, $t1, 0x29E0
    ctx->r9 = ADD32(ctx->r9, 0X29E0);
    // 0x800AC980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC984: b           L_800AC998
    // 0x800AC988: sw          $t1, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = ctx->r9;
        goto L_800AC998;
    // 0x800AC988: sw          $t1, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = ctx->r9;
L_800AC98C:
    // 0x800AC98C: addiu       $t2, $t2, 0x2A30
    ctx->r10 = ADD32(ctx->r10, 0X2A30);
    // 0x800AC990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC994: sw          $t2, 0x7C28($at)
    MEM_W(0X7C28, ctx->r1) = ctx->r10;
L_800AC998:
    // 0x800AC998: lbu         $t3, 0xE($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XE);
    // 0x800AC99C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC9A0: bne         $a2, $t3, L_800AC9B8
    if (ctx->r6 != ctx->r11) {
        // 0x800AC9A4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800AC9B8;
    }
    // 0x800AC9A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC9A8: addiu       $t4, $t4, 0x2980
    ctx->r12 = ADD32(ctx->r12, 0X2980);
    // 0x800AC9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AC9B0: b           L_800AC9BC
    // 0x800AC9B4: sw          $t4, 0x7C2C($at)
    MEM_W(0X7C2C, ctx->r1) = ctx->r12;
        goto L_800AC9BC;
    // 0x800AC9B4: sw          $t4, 0x7C2C($at)
    MEM_W(0X7C2C, ctx->r1) = ctx->r12;
L_800AC9B8:
    // 0x800AC9B8: sw          $zero, 0x7C2C($at)
    MEM_W(0X7C2C, ctx->r1) = 0;
L_800AC9BC:
    // 0x800AC9BC: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800AC9C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AC9C4: sh          $t5, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r13;
    // 0x800AC9C8: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x800AC9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC9D0: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800AC9D4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800AC9D8: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800AC9DC: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x800AC9E0: jal         0x80070490
    // 0x800AC9E4: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x800AC9E4: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x800AC9E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AC9EC: addiu       $a1, $a1, 0x7C30
    ctx->r5 = ADD32(ctx->r5, 0X7C30);
    // 0x800AC9F0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800AC9F4: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800AC9F8: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800AC9FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACA00: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800ACA04: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800ACA08: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800ACA0C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800ACA10: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x800ACA14: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800ACA18: jr          $ra
    // 0x800ACA1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ACA1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80074B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B34: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074B38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074B3C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80074B40: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80074B44: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80074B48: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80074B4C: jal         0x800758DC
    // 0x80074B50: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074B50: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_0:
    // 0x80074B54: beq         $v0, $zero, L_80074B74
    if (ctx->r2 == 0) {
        // 0x80074B58: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80074B74;
    }
    // 0x80074B58: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80074B5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074B60: jal         0x80075AEC
    // 0x80074B64: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80074B64: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80074B68: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80074B6C: b           L_80074EAC
    // 0x80074B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80074EAC;
    // 0x80074B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80074B74:
    // 0x80074B74: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80074B78: addiu       $a1, $a1, 0x773C
    ctx->r5 = ADD32(ctx->r5, 0X773C);
    // 0x80074B7C: beq         $v0, $zero, L_80074B98
    if (ctx->r2 == 0) {
        // 0x80074B80: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80074B98;
    }
    // 0x80074B80: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074B84: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80074B88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80074B8C: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80074B90: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80074B94: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_80074B98:
    // 0x80074B98: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074B9C: addiu       $a2, $a2, 0x774C
    ctx->r6 = ADD32(ctx->r6, 0X774C);
    // 0x80074BA0: jal         0x800764E8
    // 0x80074BA4: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80074BA4: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80074BA8: bne         $v0, $zero, L_80074E30
    if (ctx->r2 != 0) {
        // 0x80074BAC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80074E30;
    }
    // 0x80074BAC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074BB0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80074BB4: jal         0x80070C9C
    // 0x80074BB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80074BB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80074BBC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80074BC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80074BC4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80074BC8: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80074BCC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80074BD0: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80074BD4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80074BD8: addiu       $t3, $t3, 0x4018
    ctx->r11 = ADD32(ctx->r11, 0X4018);
    // 0x80074BDC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80074BE0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074BE4: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80074BE8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80074BEC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80074BF0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80074BF4: bne         $t6, $zero, L_80074C08
    if (ctx->r14 != 0) {
        // 0x80074BF8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80074C08;
    }
    // 0x80074BF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80074BFC: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x80074C00: jal         0x800CED20
    // 0x80074C04: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80074C04: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_4:
L_80074C08:
    // 0x80074C08: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074C0C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074C10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074C14: jal         0x80076610
    // 0x80074C18: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074C18: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_5:
    // 0x80074C1C: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x80074C20: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x80074C24: bne         $v0, $zero, L_80074D24
    if (ctx->r2 != 0) {
        // 0x80074C28: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80074D24;
    }
    // 0x80074C28: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80074C2C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80074C30: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x80074C34: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80074C38: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x80074C3C: bne         $t7, $at, L_80074D20
    if (ctx->r15 != ctx->r1) {
        // 0x80074C40: addiu       $a1, $a2, 0x4
        ctx->r5 = ADD32(ctx->r6, 0X4);
            goto L_80074D20;
    }
    // 0x80074C40: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80074C44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80074C48: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80074C4C:
    // 0x80074C4C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80074C50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80074C54: bne         $t0, $t8, L_80074C8C
    if (ctx->r8 != ctx->r24) {
        // 0x80074C58: slti        $at, $v1, 0x18
        ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
            goto L_80074C8C;
    }
    // 0x80074C58: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x80074C5C: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80074C60: nop

    // 0x80074C64: bne         $t1, $t2, L_80074C8C
    if (ctx->r9 != ctx->r10) {
        // 0x80074C68: nop
    
            goto L_80074C8C;
    }
    // 0x80074C68: nop

    // 0x80074C6C: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80074C70: nop

    // 0x80074C74: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80074C78: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x80074C7C: nop

    // 0x80074C80: subu        $t4, $t5, $t3
    ctx->r12 = SUB32(ctx->r13, ctx->r11);
    // 0x80074C84: b           L_80074C94
    // 0x80074C88: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
        goto L_80074C94;
    // 0x80074C88: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
L_80074C8C:
    // 0x80074C8C: bne         $at, $zero, L_80074C4C
    if (ctx->r1 != 0) {
        // 0x80074C90: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80074C4C;
    }
    // 0x80074C90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80074C94:
    // 0x80074C94: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074C98: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80074C9C: bne         $t9, $zero, L_80074D24
    if (ctx->r25 != 0) {
        // 0x80074CA0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80074D24;
    }
    // 0x80074CA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80074CA4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80074CA8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80074CAC: bne         $v1, $t7, L_80074CB8
    if (ctx->r3 != ctx->r15) {
        // 0x80074CB0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80074CB8;
    }
    // 0x80074CB0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80074CB4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074CB8:
    // 0x80074CB8: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80074CBC: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80074CC0: bne         $v1, $t8, L_80074CCC
    if (ctx->r3 != ctx->r24) {
        // 0x80074CC4: addu        $v0, $a1, $t2
        ctx->r2 = ADD32(ctx->r5, ctx->r10);
            goto L_80074CCC;
    }
    // 0x80074CC4: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80074CC8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074CCC:
    // 0x80074CCC: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80074CD0: nop

    // 0x80074CD4: bne         $v1, $t3, L_80074CE0
    if (ctx->r3 != ctx->r11) {
        // 0x80074CD8: nop
    
            goto L_80074CE0;
    }
    // 0x80074CD8: nop

    // 0x80074CDC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074CE0:
    // 0x80074CE0: lbu         $t5, 0x4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4);
    // 0x80074CE4: nop

    // 0x80074CE8: bne         $v1, $t5, L_80074CF4
    if (ctx->r3 != ctx->r13) {
        // 0x80074CEC: nop
    
            goto L_80074CF4;
    }
    // 0x80074CEC: nop

    // 0x80074CF0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074CF4:
    // 0x80074CF4: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80074CF8: nop

    // 0x80074CFC: bne         $v1, $t6, L_80074D08
    if (ctx->r3 != ctx->r14) {
        // 0x80074D00: nop
    
            goto L_80074D08;
    }
    // 0x80074D00: nop

    // 0x80074D04: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074D08:
    // 0x80074D08: lbu         $t4, 0xC($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XC);
    // 0x80074D0C: nop

    // 0x80074D10: bne         $v1, $t4, L_80074D28
    if (ctx->r3 != ctx->r12) {
        // 0x80074D14: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80074D28;
    }
    // 0x80074D14: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074D18: b           L_80074D24
    // 0x80074D1C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
        goto L_80074D24;
    // 0x80074D1C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
L_80074D20:
    // 0x80074D20: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80074D24:
    // 0x80074D24: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80074D28:
    // 0x80074D28: jal         0x80071140
    // 0x80074D2C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80074D2C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80074D30: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80074D34: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074D38: beq         $t9, $zero, L_80074E18
    if (ctx->r25 == 0) {
        // 0x80074D3C: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80074E18;
    }
    // 0x80074D3C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074D40: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80074D44: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80074D48: beq         $t7, $zero, L_80074E14
    if (ctx->r15 == 0) {
        // 0x80074D4C: addiu       $a0, $a0, 0x100
        ctx->r4 = ADD32(ctx->r4, 0X100);
            goto L_80074E14;
    }
    // 0x80074D4C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x80074D50: jal         0x80070C9C
    // 0x80074D54: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x80074D54: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_7:
    // 0x80074D58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80074D5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074D60: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80074D64: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80074D68: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074D6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80074D70: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80074D74: jal         0x800CEFDC
    // 0x80074D78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_8;
    // 0x80074D78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_8:
    // 0x80074D7C: bne         $v0, $zero, L_80074E00
    if (ctx->r2 != 0) {
        // 0x80074D80: addiu       $a3, $zero, 0x9
        ctx->r7 = ADD32(0, 0X9);
            goto L_80074E00;
    }
    // 0x80074D80: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80074D84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074D88: jal         0x80074A4C
    // 0x80074D8C: nop

    calculate_ghost_header_checksum(rdram, ctx);
        goto after_9;
    // 0x80074D8C: nop

    after_9:
    // 0x80074D90: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80074D94: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80074D98: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80074D9C: nop

    // 0x80074DA0: bne         $v0, $t3, L_80074DF8
    if (ctx->r2 != ctx->r11) {
        // 0x80074DA4: nop
    
            goto L_80074DF8;
    }
    // 0x80074DA4: nop

    // 0x80074DA8: lbu         $t5, 0x2($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X2);
    // 0x80074DAC: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80074DB0: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80074DB4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80074DB8: lh          $t4, 0x4($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X4);
    // 0x80074DBC: nop

    // 0x80074DC0: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x80074DC4: lh          $t7, 0x6($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X6);
    // 0x80074DC8: nop

    // 0x80074DCC: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80074DD0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x80074DD4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074DD8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80074DDC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80074DE0: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80074DE4: sll         $a2, $t8, 2
    ctx->r6 = S32(ctx->r24 << 2);
    // 0x80074DE8: jal         0x800C9DA0
    // 0x80074DEC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    _bcopy(rdram, ctx);
        goto after_10;
    // 0x80074DEC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_10:
    // 0x80074DF0: b           L_80074E00
    // 0x80074DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80074E00;
    // 0x80074DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80074DF8:
    // 0x80074DF8: b           L_80074E00
    // 0x80074DFC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
        goto L_80074E00;
    // 0x80074DFC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
L_80074E00:
    // 0x80074E00: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074E04: jal         0x80071140
    // 0x80074E08: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80074E08: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_11:
    // 0x80074E0C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074E10: nop

L_80074E14:
    // 0x80074E14: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80074E18:
    // 0x80074E18: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80074E1C: beq         $t3, $zero, L_80074E34
    if (ctx->r11 == 0) {
        // 0x80074E20: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80074E34;
    }
    // 0x80074E20: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074E24: bne         $t5, $zero, L_80074E34
    if (ctx->r13 != 0) {
        // 0x80074E28: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80074E34;
    }
    // 0x80074E28: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074E2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80074E30:
    // 0x80074E30: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_80074E34:
    // 0x80074E34: jal         0x80075AEC
    // 0x80074E38: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    start_reading_controller_data(rdram, ctx);
        goto after_12;
    // 0x80074E38: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80074E3C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074E40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80074E44: bne         $a3, $at, L_80074EA4
    if (ctx->r7 != ctx->r1) {
        // 0x80074E48: addiu       $a1, $sp, 0x38
        ctx->r5 = ADD32(ctx->r29, 0X38);
            goto L_80074EA4;
    }
    // 0x80074E48: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80074E4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80074E50: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80074E54: jal         0x80076194
    // 0x80074E58: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_free_space(rdram, ctx);
        goto after_13;
    // 0x80074E58: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_13:
    // 0x80074E5C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074E60: bne         $v0, $zero, L_80074E9C
    if (ctx->r2 != 0) {
        // 0x80074E64: nop
    
            goto L_80074E9C;
    }
    // 0x80074E64: nop

    // 0x80074E68: jal         0x80074B1C
    // 0x80074E6C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    get_ghost_data_file_size(rdram, ctx);
        goto after_14;
    // 0x80074E6C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_14:
    // 0x80074E70: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80074E74: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80074E78: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80074E7C: bne         $at, $zero, L_80074E94
    if (ctx->r1 != 0) {
        // 0x80074E80: nop
    
            goto L_80074E94;
    }
    // 0x80074E80: nop

    // 0x80074E84: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80074E88: nop

    // 0x80074E8C: bne         $t4, $zero, L_80074EA8
    if (ctx->r12 != 0) {
        // 0x80074E90: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80074EA8;
    }
    // 0x80074E90: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80074E94:
    // 0x80074E94: b           L_80074EA8
    // 0x80074E98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80074EA8;
    // 0x80074E98: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80074E9C:
    // 0x80074E9C: b           L_80074EA8
    // 0x80074EA0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80074EA8;
    // 0x80074EA0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80074EA4:
    // 0x80074EA4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80074EA8:
    // 0x80074EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80074EAC:
    // 0x80074EAC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80074EB0: jr          $ra
    // 0x80074EB4: nop

    return;
    // 0x80074EB4: nop

;}
RECOMP_FUNC void dump_memory_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7460: addiu       $sp, $sp, -0x9F0
    ctx->r29 = ADD32(ctx->r29, -0X9F0);
    // 0x800B7464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7468: sw          $a0, 0x9F0($sp)
    MEM_W(0X9F0, ctx->r29) = ctx->r4;
    // 0x800B746C: sw          $a1, 0x9F4($sp)
    MEM_W(0X9F4, ctx->r29) = ctx->r5;
    // 0x800B7470: jal         0x8009C30C
    // 0x800B7474: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800B7474: sw          $a2, 0x9F8($sp)
    MEM_W(0X9F8, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B7478: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800B747C: bgez        $t6, L_800B76A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B7480: addiu       $a0, $sp, 0x840
        ctx->r4 = ADD32(ctx->r29, 0X840);
            goto L_800B76A8;
    }
    // 0x800B7480: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B7484: jal         0x800D04E0
    // 0x800B7488: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x800B7488: addiu       $a1, $zero, 0x1B0
    ctx->r5 = ADD32(0, 0X1B0);
    after_1:
    // 0x800B748C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7490: addiu       $v0, $v0, -0x6050
    ctx->r2 = ADD32(ctx->r2, -0X6050);
    // 0x800B7494: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B7498: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800B749C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800B74A0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B74A4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800B74A8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800B74AC: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B74B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B74B4: lw          $t7, 0x9F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9F0);
    // 0x800B74B8: lw          $t4, 0x9F8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F8);
    // 0x800B74BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B74C0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B74C4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B74C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B74CC: sra         $t2, $t1, 31
    ctx->r10 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B74D0: sw          $t2, 0x878($sp)
    MEM_W(0X878, ctx->r29) = ctx->r10;
    // 0x800B74D4: sw          $t6, 0x880($sp)
    MEM_W(0X880, ctx->r29) = ctx->r14;
    // 0x800B74D8: sw          $t5, 0x960($sp)
    MEM_W(0X960, ctx->r29) = ctx->r13;
    // 0x800B74DC: swc1        $f6, 0x970($sp)
    MEM_W(0X970, ctx->r29) = ctx->f6.u32l;
    // 0x800B74E0: swc1        $f10, 0x974($sp)
    MEM_W(0X974, ctx->r29) = ctx->f10.u32l;
    // 0x800B74E4: swc1        $f18, 0x978($sp)
    MEM_W(0X978, ctx->r29) = ctx->f18.u32l;
    // 0x800B74E8: addiu       $a0, $sp, 0x840
    ctx->r4 = ADD32(ctx->r29, 0X840);
    // 0x800B74EC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800B74F0: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B74F4: sw          $t1, 0x87C($sp)
    MEM_W(0X87C, ctx->r29) = ctx->r9;
    // 0x800B74F8: sw          $t7, 0x95C($sp)
    MEM_W(0X95C, ctx->r29) = ctx->r15;
    // 0x800B74FC: jal         0x800C9DA0
    // 0x800B7500: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    _bcopy(rdram, ctx);
        goto after_2;
    // 0x800B7500: sw          $t4, 0x884($sp)
    MEM_W(0X884, ctx->r29) = ctx->r12;
    after_2:
    // 0x800B7504: addiu       $a0, $sp, 0x240
    ctx->r4 = ADD32(ctx->r29, 0X240);
    // 0x800B7508: jal         0x800D04E0
    // 0x800B750C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _bzero(rdram, ctx);
        goto after_3;
    // 0x800B750C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_3:
    // 0x800B7510: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B7514: jal         0x80024594
    // 0x800B7518: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    func_80024594(rdram, ctx);
        goto after_4;
    // 0x800B7518: addiu       $a1, $sp, 0x9F4
    ctx->r5 = ADD32(ctx->r29, 0X9F4);
    after_4:
    // 0x800B751C: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B7524: blez        $t1, L_800B7678
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B7528: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7678;
    }
    // 0x800B7528: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B752C: andi        $a2, $t1, 0x3
    ctx->r6 = ctx->r9 & 0X3;
    // 0x800B7530: beq         $a2, $zero, L_800B7594
    if (ctx->r6 == 0) {
        // 0x800B7534: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B7594;
    }
    // 0x800B7534: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B7538: sll         $t2, $zero, 1
    ctx->r10 = S32(0 << 1);
    // 0x800B753C: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B7540: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B7544:
    // 0x800B7544: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B7548: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B754C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B7550: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B7554: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800B7558: nop

    // 0x800B755C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x800B7560: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7564: lw          $t0, 0x9F4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7568: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B756C: bgez        $t9, L_800B757C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B7570: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_800B757C;
    }
    // 0x800B7570: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800B7574: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800B7578: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B757C:
    // 0x800B757C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B7580: bne         $v1, $a1, L_800B7544
    if (ctx->r3 != ctx->r5) {
        // 0x800B7584: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B7544;
    }
    // 0x800B7584: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7588: lw          $t1, 0x9F4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B758C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B7590: beq         $a1, $t1, L_800B7678
    if (ctx->r5 == ctx->r9) {
        // 0x800B7594: sll         $t2, $a1, 1
        ctx->r10 = S32(ctx->r5 << 1);
            goto L_800B7678;
    }
L_800B7594:
    // 0x800B7594: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x800B7598: addiu       $t3, $sp, 0x440
    ctx->r11 = ADD32(ctx->r29, 0X440);
    // 0x800B759C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
L_800B75A0:
    // 0x800B75A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800B75A4: nop

    // 0x800B75A8: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800B75AC: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B75B0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B75B4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B75B8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B75BC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B75C0: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B75C4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B75C8: bgez        $t8, L_800B75E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B75CC: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B75E0;
    }
    // 0x800B75CC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B75D0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B75D4: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B75D8: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B75DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B75E0:
    // 0x800B75E0: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B75E4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B75E8: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B75EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B75F0: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B75F4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B75F8: bgez        $t3, L_800B7610
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B75FC: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7610;
    }
    // 0x800B75FC: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7600: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7604: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800B7608: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800B760C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7610:
    // 0x800B7610: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B7614: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7618: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x800B761C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B7620: lw          $t9, 0x9F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7624: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x800B7628: bgez        $t8, L_800B7640
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B762C: sw          $t8, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r24;
            goto L_800B7640;
    }
    // 0x800B762C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800B7630: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800B7634: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800B7638: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x800B763C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7640:
    // 0x800B7640: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800B7644: nop

    // 0x800B7648: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800B764C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B7650: lw          $t4, 0x9F4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B7654: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B7658: bgez        $t3, L_800B7668
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B765C: sw          $t3, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r11;
            goto L_800B7668;
    }
    // 0x800B765C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800B7660: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B7664: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7668:
    // 0x800B7668: lw          $t6, 0x9F4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9F4);
    // 0x800B766C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7670: bne         $a1, $t6, L_800B75A0
    if (ctx->r5 != ctx->r14) {
        // 0x800B7674: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B75A0;
    }
    // 0x800B7674: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7678:
    // 0x800B7678: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B767C: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800B7680: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x800B7684: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800B7688: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B768C: addiu       $a2, $a2, -0x7118
    ctx->r6 = ADD32(ctx->r6, -0X7118);
    // 0x800B7690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7694: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7698: jal         0x800766D4
    // 0x800B769C: addiu       $a3, $a3, -0x7110
    ctx->r7 = ADD32(ctx->r7, -0X7110);
    write_controller_pak_file(rdram, ctx);
        goto after_5;
    // 0x800B769C: addiu       $a3, $a3, -0x7110
    ctx->r7 = ADD32(ctx->r7, -0X7110);
    after_5:
L_800B76A0:
    // 0x800B76A0: b           L_800B76A0
    pause_self(rdram);
    // 0x800B76A4: nop

L_800B76A8:
    // 0x800B76A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B76AC: addiu       $sp, $sp, 0x9F0
    ctx->r29 = ADD32(ctx->r29, 0X9F0);
    // 0x800B76B0: jr          $ra
    // 0x800B76B4: nop

    return;
    // 0x800B76B4: nop

;}
RECOMP_FUNC void get_multiplayer_racer_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C440: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C444: lw          $t6, -0xB48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB48);
    // 0x8009C448: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C44C: bne         $t6, $zero, L_8009C45C
    if (ctx->r14 != 0) {
        // 0x8009C450: nop
    
            goto L_8009C45C;
    }
    // 0x8009C450: nop

    // 0x8009C454: jr          $ra
    // 0x8009C458: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C458: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C45C:
    // 0x8009C45C: lw          $t7, 0xFE8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XFE8);
    // 0x8009C460: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C464: beq         $t7, $zero, L_8009C474
    if (ctx->r15 == 0) {
        // 0x8009C468: nop
    
            goto L_8009C474;
    }
    // 0x8009C468: nop

    // 0x8009C46C: jr          $ra
    // 0x8009C470: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x8009C470: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8009C474:
    // 0x8009C474: lw          $v0, 0x410($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X410);
    // 0x8009C478: nop

    // 0x8009C47C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009C480: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x8009C484: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009C488: jr          $ra
    // 0x8009C48C: nop

    return;
    // 0x8009C48C: nop

;}
RECOMP_FUNC void func_8002C954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C954: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C958: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C95C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8002C960: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8002C964: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8002C968: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8002C96C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8002C970: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002C974: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002C978: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002C97C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002C980: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002C984: lh          $v0, 0x20($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X20);
    // 0x8002C988: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002C98C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8002C990: blez        $v0, L_8002CC00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C994: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002CC00;
    }
    // 0x8002C994: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002C998: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002C99C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8002C9A0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_8002C9A4:
    // 0x8002C9A4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x8002C9A8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002C9AC: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x8002C9B0: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002C9B4: lh          $s6, 0x10($a0)
    ctx->r22 = MEM_H(ctx->r4, 0X10);
    // 0x8002C9B8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8002C9BC: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002C9C0: beq         $at, $zero, L_8002CBF4
    if (ctx->r1 == 0) {
        // 0x8002C9C4: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_8002CBF4;
    }
    // 0x8002C9C4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8002C9C8: sll         $s5, $v1, 4
    ctx->r21 = S32(ctx->r3 << 4);
    // 0x8002C9CC: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
L_8002C9D0:
    // 0x8002C9D0: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8002C9D4: addiu       $a3, $zero, -0x7D00
    ctx->r7 = ADD32(0, -0X7D00);
    // 0x8002C9D8: addu        $t7, $v0, $s5
    ctx->r15 = ADD32(ctx->r2, ctx->r21);
    // 0x8002C9DC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8002C9E0: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8002C9E4: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8002C9E8: beq         $t9, $zero, L_8002CA04
    if (ctx->r25 == 0) {
        // 0x8002C9EC: addiu       $t2, $zero, -0x7D00
        ctx->r10 = ADD32(0, -0X7D00);
            goto L_8002CA04;
    }
    // 0x8002C9EC: addiu       $t2, $zero, -0x7D00
    ctx->r10 = ADD32(0, -0X7D00);
    // 0x8002C9F0: lw          $t6, 0x10($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X10);
    // 0x8002C9F4: nop

    // 0x8002C9F8: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8002C9FC: b           L_8002CBDC
    // 0x8002CA00: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
        goto L_8002CBDC;
    // 0x8002CA00: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
L_8002CA04:
    // 0x8002CA04: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x8002CA08: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8002CA0C: addiu       $t3, $zero, 0x7D00
    ctx->r11 = ADD32(0, 0X7D00);
    // 0x8002CA10: addiu       $t0, $zero, 0x7D00
    ctx->r8 = ADD32(0, 0X7D00);
    // 0x8002CA14: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8002CA18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002CA1C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8002CA20:
    // 0x8002CA20: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002CA24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002CA28: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8002CA2C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CA30: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CA34: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002CA38: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8002CA3C: lh          $ra, 0x4($a2)
    ctx->r31 = MEM_H(ctx->r6, 0X4);
    // 0x8002CA40: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CA44: beq         $at, $zero, L_8002CA5C
    if (ctx->r1 == 0) {
        // 0x8002CA48: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8002CA5C;
    }
    // 0x8002CA48: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CA4C: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8002CA50: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002CA54: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8002CA58: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
L_8002CA5C:
    // 0x8002CA5C: beq         $at, $zero, L_8002CA74
    if (ctx->r1 == 0) {
        // 0x8002CA60: slt         $at, $t2, $ra
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
            goto L_8002CA74;
    }
    // 0x8002CA60: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x8002CA64: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8002CA68: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002CA6C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8002CA70: slt         $at, $t2, $ra
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r31) ? 1 : 0;
L_8002CA74:
    // 0x8002CA74: beq         $at, $zero, L_8002CA8C
    if (ctx->r1 == 0) {
        // 0x8002CA78: slt         $at, $ra, $t3
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CA8C;
    }
    // 0x8002CA78: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CA7C: sll         $t2, $ra, 16
    ctx->r10 = S32(ctx->r31 << 16);
    // 0x8002CA80: sra         $t6, $t2, 16
    ctx->r14 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002CA84: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8002CA88: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CA8C:
    // 0x8002CA8C: beq         $at, $zero, L_8002CAA0
    if (ctx->r1 == 0) {
        // 0x8002CA90: nop
    
            goto L_8002CAA0;
    }
    // 0x8002CA90: nop

    // 0x8002CA94: sll         $t3, $ra, 16
    ctx->r11 = S32(ctx->r31 << 16);
    // 0x8002CA98: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002CA9C: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
L_8002CAA0:
    // 0x8002CAA0: bne         $v1, $s0, L_8002CA20
    if (ctx->r3 != ctx->r16) {
        // 0x8002CAA4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002CA20;
    }
    // 0x8002CAA4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002CAA8: lh          $ra, 0x0($s4)
    ctx->r31 = MEM_H(ctx->r20, 0X0);
    // 0x8002CAAC: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x8002CAB0: sll         $a0, $ra, 16
    ctx->r4 = S32(ctx->r31 << 16);
    // 0x8002CAB4: subu        $a2, $t8, $ra
    ctx->r6 = SUB32(ctx->r24, ctx->r31);
    // 0x8002CAB8: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CABC: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002CAC0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002CAC4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CAC8: addu        $v1, $a2, $ra
    ctx->r3 = ADD32(ctx->r6, ctx->r31);
    // 0x8002CACC: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002CAD0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CAD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002CAD8: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CADC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002CAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CAE4:
    // 0x8002CAE4: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002CAE8: bne         $at, $zero, L_8002CB08
    if (ctx->r1 != 0) {
        // 0x8002CAEC: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CB08;
    }
    // 0x8002CAEC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CAF0: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CAF4: bne         $at, $zero, L_8002CB08
    if (ctx->r1 != 0) {
        // 0x8002CAF8: nop
    
            goto L_8002CB08;
    }
    // 0x8002CAF8: nop

    // 0x8002CAFC: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CB00: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002CB04: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
L_8002CB08:
    // 0x8002CB08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CB0C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002CB10: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8002CB14: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CB18: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB1C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CB20: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002CB24: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CB28: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002CB2C: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002CB30: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CB34: bne         $at, $zero, L_8002CAE4
    if (ctx->r1 != 0) {
        // 0x8002CB38: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002CAE4;
    }
    // 0x8002CB38: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB3C: lh          $a3, 0x4($s4)
    ctx->r7 = MEM_H(ctx->r20, 0X4);
    // 0x8002CB40: lh          $t6, 0xA($s4)
    ctx->r14 = MEM_H(ctx->r20, 0XA);
    // 0x8002CB44: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8002CB48: subu        $a2, $t6, $a3
    ctx->r6 = SUB32(ctx->r14, ctx->r7);
    // 0x8002CB4C: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002CB50: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002CB54: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002CB58: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CB5C: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
    // 0x8002CB60: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002CB64: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002CB68: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CB6C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002CB70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002CB74:
    // 0x8002CB74: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CB78: bne         $at, $zero, L_8002CB98
    if (ctx->r1 != 0) {
        // 0x8002CB7C: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002CB98;
    }
    // 0x8002CB7C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002CB80: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002CB84: bne         $at, $zero, L_8002CB98
    if (ctx->r1 != 0) {
        // 0x8002CB88: nop
    
            goto L_8002CB98;
    }
    // 0x8002CB88: nop

    // 0x8002CB8C: or          $t1, $t1, $a1
    ctx->r9 = ctx->r9 | ctx->r5;
    // 0x8002CB90: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002CB94: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_8002CB98:
    // 0x8002CB98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CB9C: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002CBA0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8002CBA4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002CBA8: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002CBAC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002CBB0: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002CBB4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002CBB8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002CBBC: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002CBC0: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002CBC4: bne         $at, $zero, L_8002CB74
    if (ctx->r1 != 0) {
        // 0x8002CBC8: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002CB74;
    }
    // 0x8002CBC8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002CBCC: lw          $t8, 0x10($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X10);
    // 0x8002CBD0: nop

    // 0x8002CBD4: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002CBD8: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8002CBDC:
    // 0x8002CBDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CBE0: slt         $at, $s1, $s6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002CBE4: bne         $at, $zero, L_8002C9D0
    if (ctx->r1 != 0) {
        // 0x8002CBE8: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8002C9D0;
    }
    // 0x8002CBE8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8002CBEC: lh          $v0, 0x20($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X20);
    // 0x8002CBF0: nop

L_8002CBF4:
    // 0x8002CBF4: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002CBF8: bne         $at, $zero, L_8002C9A4
    if (ctx->r1 != 0) {
        // 0x8002CBFC: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_8002C9A4;
    }
    // 0x8002CBFC: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_8002CC00:
    // 0x8002CC00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CC04: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002CC08: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002CC0C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002CC10: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002CC14: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8002CC18: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CC1C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8002CC20: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8002CC24: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8002CC28: jr          $ra
    // 0x8002CC2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002CC2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bootscreen_init_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800887EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800887F0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x800887F4: jal         0x80070C9C
    // 0x800887F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800887F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x800887FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088800: addiu       $a1, $a1, 0x6AA0
    ctx->r5 = ADD32(ctx->r5, 0X6AA0);
    // 0x80088804: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088808: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008880C: addiu       $a0, $a0, 0x6AA4
    ctx->r4 = ADD32(ctx->r4, 0X6AA4);
    // 0x80088810: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_80088814:
    // 0x80088814: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088818: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008881C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80088820: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80088824: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x80088828: bne         $at, $zero, L_80088814
    if (ctx->r1 != 0) {
        // 0x8008882C: sw          $t7, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r15;
            goto L_80088814;
    }
    // 0x8008882C: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x80088830: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088834: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088838: addiu       $v1, $v1, 0x6A61
    ctx->r3 = ADD32(ctx->r3, 0X6A61);
    // 0x8008883C: addiu       $v0, $v0, 0x6A60
    ctx->r2 = ADD32(ctx->r2, 0X6A60);
L_80088840:
    // 0x80088840: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80088844: bne         $v0, $v1, L_80088840
    if (ctx->r2 != ctx->r3) {
        // 0x80088848: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80088840;
    }
    // 0x80088848: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8008884C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088850: sw          $zero, 0x6C10($at)
    MEM_W(0X6C10, ctx->r1) = 0;
    // 0x80088854: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088858: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8008885C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088860: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80088864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088868: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008886C: jal         0x8009EB20
    // 0x80088870: sw          $t8, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = ctx->r24;
    get_language(rdram, ctx);
        goto after_1;
    // 0x80088870: sw          $t8, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = ctx->r24;
    after_1:
    // 0x80088874: jal         0x8007F900
    // 0x80088878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_2;
    // 0x80088878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8008887C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088880: addiu       $a0, $a0, 0x6A68
    ctx->r4 = ADD32(ctx->r4, 0X6A68);
    // 0x80088884: jal         0x80087F14
    // 0x80088888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x80088888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008888C: bne         $v0, $zero, L_8008889C
    if (ctx->r2 != 0) {
        // 0x80088890: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008889C;
    }
    // 0x80088890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088894: b           L_800888B4
    // 0x80088898: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
        goto L_800888B4;
    // 0x80088898: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
L_8008889C:
    // 0x8008889C: jal         0x8008832C
    // 0x800888A0: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x800888A0: nop

    after_4:
    // 0x800888A4: bne         $v0, $zero, L_800888B4
    if (ctx->r2 != 0) {
        // 0x800888A8: addiu       $t9, $zero, 0x14
        ctx->r25 = ADD32(0, 0X14);
            goto L_800888B4;
    }
    // 0x800888A8: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x800888AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800888B0: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
L_800888B4:
    // 0x800888B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800888B8: lw          $t0, 0x6BC8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BC8);
    // 0x800888BC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800888C0: bne         $t0, $zero, L_800888DC
    if (ctx->r8 != 0) {
        // 0x800888C4: addiu       $a0, $zero, 0x3F
        ctx->r4 = ADD32(0, 0X3F);
            goto L_800888DC;
    }
    // 0x800888C4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x800888C8: lw          $t1, -0x26C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X26C);
    // 0x800888CC: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x800888D0: bne         $t1, $zero, L_800888DC
    if (ctx->r9 != 0) {
        // 0x800888D4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800888DC;
    }
    // 0x800888D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800888D8: sw          $t2, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r10;
L_800888DC:
    // 0x800888DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800888E0: sw          $zero, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = 0;
    // 0x800888E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800888E8: jal         0x8009C6D4
    // 0x800888EC: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    menu_asset_load(rdram, ctx);
        goto after_5;
    // 0x800888EC: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    after_5:
    // 0x800888F0: jal         0x8008E4B0
    // 0x800888F4: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x800888F4: nop

    after_6:
    // 0x800888F8: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800888FC: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x80088900: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80088904: bne         $t3, $zero, L_8008891C
    if (ctx->r11 != 0) {
        // 0x80088908: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008891C;
    }
    // 0x80088908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008890C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80088910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088914: b           L_80088920
    // 0x80088918: sw          $t4, 0x6BB4($at)
    MEM_W(0X6BB4, ctx->r1) = ctx->r12;
        goto L_80088920;
    // 0x80088918: sw          $t4, 0x6BB4($at)
    MEM_W(0X6BB4, ctx->r1) = ctx->r12;
L_8008891C:
    // 0x8008891C: sw          $t5, 0x6BB4($at)
    MEM_W(0X6BB4, ctx->r1) = ctx->r13;
L_80088920:
    // 0x80088920: jal         0x800C4170
    // 0x80088924: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_7;
    // 0x80088924: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80088928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008892C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088930: jr          $ra
    // 0x80088934: nop

    return;
    // 0x80088934: nop

;}
RECOMP_FUNC void cam_set_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800660F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800660F4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800660F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800660FC: bc1f        L_80066184
    if (!c1cs) {
        // 0x80066100: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80066184;
    }
    // 0x80066100: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80066104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066108: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006610C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80066110: addiu       $v0, $v0, 0xD10
    ctx->r2 = ADD32(ctx->r2, 0XD10);
    // 0x80066114: bc1f        L_80066188
    if (!c1cs) {
        // 0x80066118: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80066188;
    }
    // 0x80066118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006611C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066120: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066124: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x80066128: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    // 0x8006612C: bc1t        L_80066184
    if (c1cs) {
        // 0x80066130: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80066184;
    }
    // 0x80066130: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066134: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80066138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006613C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80066140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066144: lwc1        $f16, 0x70A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X70A0);
    // 0x80066148: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006614C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80066150: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80066154: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066158: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006615C: addiu       $a1, $a1, 0xD6C
    ctx->r5 = ADD32(ctx->r5, 0XD6C);
    // 0x80066160: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80066164: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80066168: jal         0x800CC920
    // 0x8006616C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x8006616C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80066170: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066174: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066178: addiu       $a1, $a1, 0xFE0
    ctx->r5 = ADD32(ctx->r5, 0XFE0);
    // 0x8006617C: jal         0x8006F870
    // 0x80066180: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x80066180: addiu       $a0, $a0, 0xEE0
    ctx->r4 = ADD32(ctx->r4, 0XEE0);
    after_1:
L_80066184:
    // 0x80066184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80066188:
    // 0x80066188: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006618C: jr          $ra
    // 0x80066190: nop

    return;
    // 0x80066190: nop

;}
RECOMP_FUNC void update_carpet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D95C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004D960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004D964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004D968: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004D96C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004D970: lw          $t6, 0x118($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X118);
    // 0x8004D974: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004D978: beq         $t6, $zero, L_8004D990
    if (ctx->r14 == 0) {
        // 0x8004D97C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8004D990;
    }
    // 0x8004D97C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004D980: jal         0x80006AC8
    // 0x8004D984: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    racer_sound_free(rdram, ctx);
        goto after_0;
    // 0x8004D984: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004D988: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004D98C: nop

L_8004D990:
    // 0x8004D990: jal         0x8002341C
    // 0x8004D994: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    is_taj_challenge(rdram, ctx);
        goto after_1;
    // 0x8004D994: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004D998: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004D99C: beq         $v0, $zero, L_8004D9C0
    if (ctx->r2 == 0) {
        // 0x8004D9A0: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8004D9C0;
    }
    // 0x8004D9A0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8004D9A4: lb          $t7, 0x1D6($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X1D6);
    // 0x8004D9A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004D9AC: bne         $t7, $at, L_8004D9C0
    if (ctx->r15 != ctx->r1) {
        // 0x8004D9B0: nop
    
            goto L_8004D9C0;
    }
    // 0x8004D9B0: nop

    // 0x8004D9B4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8004D9B8: nop

    // 0x8004D9BC: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
L_8004D9C0:
    // 0x8004D9C0: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8004D9C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004D9C8: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x8004D9CC: sb          $t0, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r8;
    // 0x8004D9D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D9D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004D9D8: jal         0x80049794
    // 0x8004D9DC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80049794(rdram, ctx);
        goto after_2;
    // 0x8004D9DC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x8004D9E0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004D9E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004D9E8: lb          $t1, 0x1D7($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1D7);
    // 0x8004D9EC: nop

    // 0x8004D9F0: sb          $t1, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r9;
    // 0x8004D9F4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8004D9F8: lb          $t2, 0x1D6($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1D6);
    // 0x8004D9FC: nop

    // 0x8004DA00: bne         $t2, $at, L_8004DAA4
    if (ctx->r10 != ctx->r1) {
        // 0x8004DA04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DAA4;
    }
    // 0x8004DA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DA08: lw          $v0, 0x154($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA0C: nop

    // 0x8004DA10: beq         $v0, $zero, L_8004DAA4
    if (ctx->r2 == 0) {
        // 0x8004DA14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DAA4;
    }
    // 0x8004DA14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DA18: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004DA1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004DA20: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8004DA24: lw          $t3, 0x154($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA28: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004DA2C: nop

    // 0x8004DA30: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x8004DA34: lw          $t4, 0x154($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA38: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004DA3C: nop

    // 0x8004DA40: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x8004DA44: lw          $t6, 0x154($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA48: lh          $t5, 0x2E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2E);
    // 0x8004DA4C: nop

    // 0x8004DA50: sh          $t5, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r13;
    // 0x8004DA54: lw          $t8, 0x154($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA58: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004DA5C: nop

    // 0x8004DA60: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8004DA64: lw          $t0, 0x154($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA68: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8004DA6C: nop

    // 0x8004DA70: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x8004DA74: lw          $t2, 0x154($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X154);
    // 0x8004DA78: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x8004DA7C: nop

    // 0x8004DA80: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x8004DA84: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8004DA88: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8004DA8C: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8004DA90: nop

    // 0x8004DA94: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004DA98: jal         0x80061C0C
    // 0x8004DA9C: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    func_80061C0C(rdram, ctx);
        goto after_3;
    // 0x8004DA9C: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    after_3:
    // 0x8004DAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004DAA4:
    // 0x8004DAA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004DAA8: jr          $ra
    // 0x8004DAAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004DAAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B060: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B064: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003B068: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003B06C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B070: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B074: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003B078: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B07C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B080: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003B084: bc1f        L_8003B094
    if (!c1cs) {
        // 0x8003B088: nop
    
            goto L_8003B094;
    }
    // 0x8003B088: nop

    // 0x8003B08C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B090: nop

L_8003B094:
    // 0x8003B094: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B098: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003B09C: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003B0A0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003B0A4: nop

    // 0x8003B0A8: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003B0AC: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003B0B0: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B0B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003B0B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003B0BC: jal         0x800707C4
    // 0x8003B0C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003B0C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003B0C4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B0C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B0CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B0D0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003B0D4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003B0D8: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003B0DC: jal         0x800707F8
    // 0x8003B0E0: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003B0E0: nop

    after_1:
    // 0x8003B0E4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003B0E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003B0EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003B0F0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003B0F4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003B0F8: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003B0FC: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003B100: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B104: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003B108: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003B10C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B110: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003B114: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003B118: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B11C: nop

    // 0x8003B120: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003B124: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003B128: nop

    // 0x8003B12C: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003B130: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B134: nop

    // 0x8003B138: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003B13C: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B140: nop

    // 0x8003B144: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003B148: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B14C: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003B150: nop

    // 0x8003B154: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003B158: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003B15C: nop

    // 0x8003B160: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003B164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003B16C: jr          $ra
    // 0x8003B170: nop

    return;
    // 0x8003B170: nop

;}
RECOMP_FUNC void fade_when_near_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D04C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005D054: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005D058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8005D05C: jal         0x8001BAC8
    // 0x8005D060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8005D060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8005D064: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005D068: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8005D06C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8005D070: jal         0x8001139C
    // 0x8005D074: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_1;
    // 0x8005D074: sb          $t6, 0x1F7($t7)
    MEM_B(0X1F7, ctx->r15) = ctx->r14;
    after_1:
    // 0x8005D078: bne         $v0, $zero, L_8005D0BC
    if (ctx->r2 != 0) {
        // 0x8005D07C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D0BC;
    }
    // 0x8005D07C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D080: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005D084: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005D088: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005D08C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D090: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D094: lwc1        $f4, 0x30($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X30);
    // 0x8005D098: lwc1        $f16, 0x30($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8005D09C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005D0A0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8005D0A4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005D0A8: nop

    // 0x8005D0AC: bc1f        L_8005D0B8
    if (!c1cs) {
        // 0x8005D0B0: addiu       $t1, $zero, 0x40
        ctx->r9 = ADD32(0, 0X40);
            goto L_8005D0B8;
    }
    // 0x8005D0B0: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8005D0B4: sb          $t1, 0x1F7($t2)
    MEM_B(0X1F7, ctx->r10) = ctx->r9;
L_8005D0B8:
    // 0x8005D0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D0BC:
    // 0x8005D0BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D0C0: jr          $ra
    // 0x8005D0C4: nop

    return;
    // 0x8005D0C4: nop

;}
RECOMP_FUNC void racer_find_nearest_opponent_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B7AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B7B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001B7B4: lh          $t6, 0x1AA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1AA);
    // 0x8001B7B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B7BC: subu        $a1, $t6, $a1
    ctx->r5 = SUB32(ctx->r14, ctx->r5);
    // 0x8001B7C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001B7C4: bltz        $a1, L_8001B7E0
    if (SIGNED(ctx->r5) < 0) {
        // 0x8001B7C8: nop
    
            goto L_8001B7E0;
    }
    // 0x8001B7C8: nop

    // 0x8001B7CC: lw          $t7, -0x5110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5110);
    // 0x8001B7D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B7D4: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001B7D8: bne         $at, $zero, L_8001B7E8
    if (ctx->r1 != 0) {
        // 0x8001B7DC: nop
    
            goto L_8001B7E8;
    }
    // 0x8001B7DC: nop

L_8001B7E0:
    // 0x8001B7E0: b           L_8001B824
    // 0x8001B7E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B824;
    // 0x8001B7E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B7E8:
    // 0x8001B7E8: lw          $t8, -0x5118($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5118);
    // 0x8001B7EC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001B7F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B7F4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001B7F8: nop

    // 0x8001B7FC: bne         $v1, $zero, L_8001B80C
    if (ctx->r3 != 0) {
        // 0x8001B800: nop
    
            goto L_8001B80C;
    }
    // 0x8001B800: nop

    // 0x8001B804: b           L_8001B824
    // 0x8001B808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B824;
    // 0x8001B808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B80C:
    // 0x8001B80C: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001B810: jal         0x8001B834
    // 0x8001B814: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    racer_calc_distance_to_opponent(rdram, ctx);
        goto after_0;
    // 0x8001B814: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B818: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001B81C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8001B820: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
L_8001B824:
    // 0x8001B824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B82C: jr          $ra
    // 0x8001B830: nop

    return;
    // 0x8001B830: nop

;}
RECOMP_FUNC void music_channel_reset_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800012EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800012F0: lw          $t6, -0x39B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39B8);
    // 0x800012F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800012F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800012FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001300: bne         $t6, $zero, L_80001340
    if (ctx->r14 != 0) {
        // 0x80001304: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80001340;
    }
    // 0x80001304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001308: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000130C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80001310: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001314:
    // 0x80001314: jal         0x80001170
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x80001318: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_0:
    // 0x8000131C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80001320: jal         0x80001268
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_1;
    // 0x80001324: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_1:
    // 0x80001328: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x8000132C: jal         0x800011E8
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_volume_set(rdram, ctx);
        goto after_2;
    // 0x80001330: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_2:
    // 0x80001334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001338: bne         $s0, $s2, L_80001314
    if (ctx->r16 != ctx->r18) {
        // 0x8000133C: andi        $s1, $s0, 0xFF
        ctx->r17 = ctx->r16 & 0XFF;
            goto L_80001314;
    }
    // 0x8000133C: andi        $s1, $s0, 0xFF
    ctx->r17 = ctx->r16 & 0XFF;
L_80001340:
    // 0x80001340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000134C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001350: jr          $ra
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_audioline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FEF4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003FEF8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003FEFC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8003FF00: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003FF04: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003FF08: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003FF0C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003FF10: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8003FF14: lhu         $t8, 0xA($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XA);
    // 0x8003FF18: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x8003FF1C: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x8003FF20: lbu         $t9, 0xC($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XC);
    // 0x8003FF24: nop

    // 0x8003FF28: sb          $t9, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r25;
    // 0x8003FF2C: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x8003FF30: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8003FF34: sb          $t0, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r8;
    // 0x8003FF38: lhu         $t1, 0xE($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XE);
    // 0x8003FF3C: nop

    // 0x8003FF40: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8003FF44: lbu         $t2, 0x12($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X12);
    // 0x8003FF48: nop

    // 0x8003FF4C: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x8003FF50: lbu         $t3, 0x11($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X11);
    // 0x8003FF54: nop

    // 0x8003FF58: sb          $t3, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r11;
    // 0x8003FF5C: lbu         $t4, 0x9($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X9);
    // 0x8003FF60: nop

    // 0x8003FF64: sb          $t4, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r12;
    // 0x8003FF68: lbu         $t5, 0x10($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X10);
    // 0x8003FF6C: nop

    // 0x8003FF70: sb          $t5, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r13;
    // 0x8003FF74: lbu         $t6, 0x13($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X13);
    // 0x8003FF78: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x8003FF7C: sb          $t6, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r14;
    // 0x8003FF80: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003FF84: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x8003FF88: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003FF8C: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8003FF90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003FF94: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8003FF98: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003FF9C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003FFA0: lbu         $t0, 0xF($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF);
    // 0x8003FFA4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003FFA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003FFAC: lbu         $t1, 0xE($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XE);
    // 0x8003FFB0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003FFB4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8003FFB8: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x8003FFBC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003FFC0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8003FFC4: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x8003FFC8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8003FFCC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8003FFD0: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x8003FFD4: nop

    // 0x8003FFD8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8003FFDC: lbu         $t5, 0x11($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X11);
    // 0x8003FFE0: nop

    // 0x8003FFE4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8003FFE8: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x8003FFEC: nop

    // 0x8003FFF0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8003FFF4: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
    // 0x8003FFF8: jal         0x800098A4
    // 0x8003FFFC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    audspat_line_add_vertex(rdram, ctx);
        goto after_0;
    // 0x8003FFFC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_0:
    // 0x80040000: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80040004: jal         0x8000FFB8
    // 0x80040008: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80040008: nop

    after_1:
    // 0x8004000C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80040010: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80040014: jr          $ra
    // 0x80040018: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80040018: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void calc_dyn_lighting_for_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800708D0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800708D4: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x800708D8: lw          $t3, 0x8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X8);
    // 0x800708DC: lhu         $t0, 0x20($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X20);
    // 0x800708E0: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x800708E4: lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2C);
    // 0x800708E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800708EC: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_800708F0:
    // 0x800708F0: lbu         $t4, 0x6($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6);
    // 0x800708F4: addiu       $t4, $t4, -0xFF
    ctx->r12 = ADD32(ctx->r12, -0XFF);
    // 0x800708F8: beql        $t4, $zero, L_80070A08
    if (ctx->r12 == 0) {
        // 0x800708FC: lhu         $t4, 0x2($a2)
        ctx->r12 = MEM_HU(ctx->r6, 0X2);
            goto L_80070A08;
    }
    goto skip_0;
    // 0x800708FC: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80070900: beql        $v0, $zero, L_80070934
    if (ctx->r2 == 0) {
        // 0x80070904: nop
    
            goto L_80070934;
    }
    goto skip_1;
    // 0x80070904: nop

    skip_1:
    // 0x80070908: ori         $t4, $zero, 0xA
    ctx->r12 = 0 | 0XA;
    // 0x8007090C: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070910: ori         $t5, $zero, 0xA
    ctx->r13 = 0 | 0XA;
    // 0x80070914: mflo        $t4
    ctx->r12 = lo;
    // 0x80070918: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8007091C: nop

    // 0x80070920: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070924: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    // 0x80070928: mflo        $t5
    ctx->r13 = lo;
    // 0x8007092C: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80070930: nop

L_80070934:
    // 0x80070934: lhu         $t5, 0x2($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X2);
    // 0x80070938: lhu         $t4, 0xE($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0XE);
    // 0x8007093C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070940: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
L_80070944:
    // 0x80070944: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80070948: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8007094C: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x80070950: mult        $t5, $t1
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070954: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x80070958: lbu         $a3, 0x6($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X6);
    // 0x8007095C: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80070960: sll         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24 << 16);
    // 0x80070964: lbu         $v1, 0x9($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X9);
    // 0x80070968: or          $t8, $a3, $t8
    ctx->r24 = ctx->r7 | ctx->r24;
    // 0x8007096C: mflo        $t5
    ctx->r13 = lo;
    // 0x80070970: nop

    // 0x80070974: nop

    // 0x80070978: mult        $t6, $t2
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007097C: mflo        $t6
    ctx->r14 = lo;
    // 0x80070980: add         $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80070984: nop

    // 0x80070988: mult        $t7, $t3
    result = S64(S32(ctx->r15)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007098C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070990: add         $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80070994: blez        $t5, L_800709B4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80070998: nop
    
            goto L_800709B4;
    }
    // 0x80070998: nop

    // 0x8007099C: srl         $t5, $t5, 22
    ctx->r13 = S32(U32(ctx->r13) >> 22);
    // 0x800709A0: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x800709A4: sltiu       $t5, $v1, 0x81
    ctx->r13 = ctx->r3 < 0X81 ? 1 : 0;
    // 0x800709A8: bne         $t5, $zero, L_800709B4
    if (ctx->r13 != 0) {
        // 0x800709AC: nop
    
            goto L_800709B4;
    }
    // 0x800709AC: nop

    // 0x800709B0: ori         $v1, $zero, 0x80
    ctx->r3 = 0 | 0X80;
L_800709B4:
    // 0x800709B4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800709B8: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800709BC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800709C0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800709C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800709C8: srl         $t8, $t8, 7
    ctx->r24 = S32(U32(ctx->r24) >> 7);
    // 0x800709CC: sb          $t8, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r24;
    // 0x800709D0: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800709D4: srl         $t8, $t8, 16
    ctx->r24 = S32(U32(ctx->r24) >> 16);
    // 0x800709D8: sb          $t8, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r24;
    // 0x800709DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800709E0: srl         $t9, $t9, 7
    ctx->r25 = S32(U32(ctx->r25) >> 7);
    // 0x800709E4: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x800709E8: bnel        $t4, $zero, L_80070944
    if (ctx->r12 != 0) {
        // 0x800709EC: nop
    
            goto L_80070944;
    }
    goto skip_2;
    // 0x800709EC: nop

    skip_2:
    // 0x800709F0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800709F4: bnel        $t0, $zero, L_800708F0
    if (ctx->r8 != 0) {
        // 0x800709F8: nop
    
            goto L_800708F0;
    }
    goto skip_3;
    // 0x800709F8: nop

    skip_3:
    // 0x800709FC: jr          $ra
    // 0x80070A00: nop

    return;
    // 0x80070A00: nop

    // 0x80070A04: lhu         $t4, 0x2($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X2);
L_80070A08:
    // 0x80070A08: lhu         $t5, 0xE($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0XE);
    // 0x80070A0C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80070A10: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80070A14: subu        $t4, $t5, $t4
    ctx->r12 = SUB32(ctx->r13, ctx->r12);
    // 0x80070A18: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80070A1C: bnel        $t0, $zero, L_800708F0
    if (ctx->r8 != 0) {
        // 0x80070A20: nop
    
            goto L_800708F0;
    }
    goto skip_4;
    // 0x80070A20: nop

    skip_4:
    // 0x80070A24: jr          $ra
    // 0x80070A28: nop

    return;
    // 0x80070A28: nop

;}
