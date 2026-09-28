#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void credits_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B1E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B1E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009B1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B1F0: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8009B1F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009B1F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009B1FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009B200: bne         $at, $zero, L_8009B210
    if (ctx->r1 != 0) {
        // 0x8009B204: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8009B210;
    }
    // 0x8009B204: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009B208: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009B20C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_8009B210:
    // 0x8009B210: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8009B214: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009B218: bgez        $t2, L_8009B224
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009B21C: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_8009B224;
    }
    // 0x8009B21C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009B220: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8009B224:
    // 0x8009B224: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B228: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009B22C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009B230: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009B234: addiu       $t9, $t9, 0x1780
    ctx->r25 = ADD32(ctx->r25, 0X1780);
    // 0x8009B238: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8009B23C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009B240: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009B244: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B248: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8009B24C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009B250: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8009B254: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8009B258: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B25C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009B260: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B264: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x8009B268: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B26C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B270: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8009B274: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8009B278: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x8009B27C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009B280: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009B284: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8009B288: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8009B28C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B290: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B294: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8009B298: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B29C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B2A0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8009B2A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009B2A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009B2AC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8009B2B0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B2B4: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B2B8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009B2BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B2C0: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x8009B2C4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8009B2C8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B2CC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8009B2D0: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8009B2D4: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x8009B2D8: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8009B2DC: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8009B2E0: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8009B2E4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B2E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B2EC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009B2F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B2F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B2F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009B2FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009B300: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B304: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009B308: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009B30C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009B310: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009B314: jal         0x8007B3D0
    // 0x8009B318: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x8009B318: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_0:
    // 0x8009B31C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B324: jr          $ra
    // 0x8009B328: nop

    return;
    // 0x8009B328: nop

;}
RECOMP_FUNC void find_next_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA1C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8001BA20: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA28: lw          $v0, -0x5134($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5134);
    // 0x8001BA2C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BA30: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x8001BA34: beq         $a1, $zero, L_8001BA5C
    if (ctx->r5 == 0) {
        // 0x8001BA38: nop
    
            goto L_8001BA5C;
    }
    // 0x8001BA38: nop

    // 0x8001BA3C: lb          $a0, 0x3A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X3A);
    // 0x8001BA40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BA44: beq         $a0, $at, L_8001BA5C
    if (ctx->r4 == ctx->r1) {
        // 0x8001BA48: nop
    
            goto L_8001BA5C;
    }
    // 0x8001BA48: nop

    // 0x8001BA4C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA50: mflo        $t7
    ctx->r15 = lo;
    // 0x8001BA54: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8001BA58: nop

L_8001BA5C:
    // 0x8001BA5C: jr          $ra
    // 0x8001BA60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001BA60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void racer_play_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005704C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80057050: lw          $t7, -0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA4);
    // 0x80057054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057058: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005705C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80057060: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80057064: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057068: beq         $t7, $at, L_80057094
    if (ctx->r15 == ctx->r1) {
        // 0x8005706C: or          $t6, $a0, $zero
        ctx->r14 = ctx->r4 | 0;
            goto L_80057094;
    }
    // 0x8005706C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80057070: lw          $t8, 0x108($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X108);
    // 0x80057074: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80057078: bne         $t8, $zero, L_80057098
    if (ctx->r24 != 0) {
        // 0x8005707C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80057098;
    }
    // 0x8005707C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80057080: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x80057084: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80057088: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    { extern unsigned dkr_legacy_character_race_sound(uint8_t*, recomp_context*, uint32_t, unsigned); ctx->r4 = dkr_legacy_character_race_sound(rdram, ctx, (uint32_t)ctx->r2, (unsigned)ctx->r4); }
    // 0x8005708C: jal         0x80001EA8
    // 0x80057090: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_0;
    // 0x80057090: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_80057094:
    // 0x80057094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80057098:
    // 0x80057098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005709C: jr          $ra
    // 0x800570A0: nop

    return;
    // 0x800570A0: nop

;}
RECOMP_FUNC void func_800BA288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA288: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA28C: lw          $v1, -0x5F20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F20);
    // 0x800BA290: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BA294: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BA298: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800BA29C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA2A0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BA2A4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BA2A8: blez        $v1, L_800BA4A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BA2AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BA4A8;
    }
    // 0x800BA2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BA2B0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BA2B4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA2B8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BA2BC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BA2C0: addiu       $t1, $t1, 0x30D8
    ctx->r9 = ADD32(ctx->r9, 0X30D8);
    // 0x800BA2C4: addiu       $t2, $t2, -0x5F18
    ctx->r10 = ADD32(ctx->r10, -0X5F18);
    // 0x800BA2C8: addiu       $t3, $t3, -0x6038
    ctx->r11 = ADD32(ctx->r11, -0X6038);
    // 0x800BA2CC: addiu       $t4, $t4, 0x30D4
    ctx->r12 = ADD32(ctx->r12, 0X30D4);
    // 0x800BA2D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA2D4: addiu       $s1, $zero, 0x80
    ctx->r17 = ADD32(0, 0X80);
    // 0x800BA2D8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_800BA2DC:
    // 0x800BA2DC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA2E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BA2E4: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA2E8: lbu         $t7, 0xA($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0XA);
    // 0x800BA2EC: lbu         $t6, 0xB($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XB);
    // 0x800BA2F0: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x800BA2F4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BA2F8: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x800BA2FC: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800BA300: nop

    // 0x800BA304: and         $t8, $t9, $t6
    ctx->r24 = ctx->r25 & ctx->r14;
    // 0x800BA308: beq         $t8, $zero, L_800BA498
    if (ctx->r24 == 0) {
        // 0x800BA30C: nop
    
            goto L_800BA498;
    }
    // 0x800BA30C: nop

    // 0x800BA310: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    // 0x800BA314: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BA318: beq         $t7, $zero, L_800BA3F0
    if (ctx->r15 == 0) {
        // 0x800BA31C: nop
    
            goto L_800BA3F0;
    }
    // 0x800BA31C: nop

L_800BA320:
    // 0x800BA320: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA324: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800BA328: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA32C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800BA330: nop

    // 0x800BA334: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA338: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800BA33C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BA340: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800BA344: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800BA348: sllv        $t6, $t7, $t9
    ctx->r14 = S32(ctx->r15 << (ctx->r25 & 31));
    // 0x800BA34C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BA350: beq         $t7, $zero, L_800BA398
    if (ctx->r15 == 0) {
        // 0x800BA354: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_800BA398;
    }
    // 0x800BA354: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800BA358: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BA35C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800BA360: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BA364: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BA368: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800BA36C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BA370: addu        $a3, $t7, $v1
    ctx->r7 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA374: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA378: nop

    // 0x800BA37C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA380: beq         $at, $zero, L_800BA390
    if (ctx->r1 == 0) {
        // 0x800BA384: subu        $t9, $t0, $a1
        ctx->r25 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA390;
    }
    // 0x800BA384: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA388: b           L_800BA3D4
    // 0x800BA38C: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
        goto L_800BA3D4;
    // 0x800BA38C: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
L_800BA390:
    // 0x800BA390: b           L_800BA3D4
    // 0x800BA394: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
        goto L_800BA3D4;
    // 0x800BA394: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA398:
    // 0x800BA398: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800BA39C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BA3A0: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x800BA3A4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800BA3A8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800BA3AC: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA3B0: lbu         $t8, 0x14($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA3B4: nop

    // 0x800BA3B8: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA3BC: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA3C0: beq         $at, $zero, L_800BA3D0
    if (ctx->r1 == 0) {
        // 0x800BA3C4: nop
    
            goto L_800BA3D0;
    }
    // 0x800BA3C4: nop

    // 0x800BA3C8: b           L_800BA3D4
    // 0x800BA3CC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
        goto L_800BA3D4;
    // 0x800BA3CC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
L_800BA3D0:
    // 0x800BA3D0: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
L_800BA3D4:
    // 0x800BA3D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BA3D8: bne         $v1, $t5, L_800BA320
    if (ctx->r3 != ctx->r13) {
        // 0x800BA3DC: nop
    
            goto L_800BA320;
    }
    // 0x800BA3DC: nop

    // 0x800BA3E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA3E4: lw          $v1, -0x5F20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F20);
    // 0x800BA3E8: b           L_800BA49C
    // 0x800BA3EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA49C;
    // 0x800BA3EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA3F0:
    // 0x800BA3F0: lw          $t7, 0xC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC);
    // 0x800BA3F4: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800BA3F8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA3FC: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BA400: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA404: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x800BA408: beq         $t7, $zero, L_800BA44C
    if (ctx->r15 == 0) {
        // 0x800BA40C: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800BA44C;
    }
    // 0x800BA40C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800BA410: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800BA414: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BA418: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x800BA41C: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA420: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA424: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA428: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA42C: beq         $at, $zero, L_800BA43C
    if (ctx->r1 == 0) {
        // 0x800BA430: subu        $t8, $t0, $a1
        ctx->r24 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA43C;
    }
    // 0x800BA430: subu        $t8, $t0, $a1
    ctx->r24 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA434: b           L_800BA440
    // 0x800BA438: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
        goto L_800BA440;
    // 0x800BA438: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
L_800BA43C:
    // 0x800BA43C: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA440:
    // 0x800BA440: lw          $v1, -0x5F20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F20);
    // 0x800BA444: b           L_800BA49C
    // 0x800BA448: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA49C;
    // 0x800BA448: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA44C:
    // 0x800BA44C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800BA450: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800BA454: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BA458: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BA45C: addu        $a3, $t6, $v1
    ctx->r7 = ADD32(ctx->r14, ctx->r3);
    // 0x800BA460: lbu         $t9, 0x14($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA464: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA468: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA46C: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA470: beq         $at, $zero, L_800BA48C
    if (ctx->r1 == 0) {
        // 0x800BA474: nop
    
            goto L_800BA48C;
    }
    // 0x800BA474: nop

    // 0x800BA478: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
    // 0x800BA47C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA480: lw          $v1, -0x5F20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F20);
    // 0x800BA484: b           L_800BA49C
    // 0x800BA488: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA49C;
    // 0x800BA488: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA48C:
    // 0x800BA48C: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
    // 0x800BA490: lw          $v1, -0x5F20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F20);
    // 0x800BA494: nop

L_800BA498:
    // 0x800BA498: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA49C:
    // 0x800BA49C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA4A0: bne         $at, $zero, L_800BA2DC
    if (ctx->r1 != 0) {
        // 0x800BA4A4: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_800BA2DC;
    }
    // 0x800BA4A4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_800BA4A8:
    // 0x800BA4A8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BA4AC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BA4B0: jr          $ra
    // 0x800BA4B4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BA4B4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_init_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003522C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035230: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035234: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80035238: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003523C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035240: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80035244: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80035248: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003524C: nop

    // 0x80035250: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80035254: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80035258: jr          $ra
    // 0x8003525C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    return;
    // 0x8003525C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
;}
RECOMP_FUNC void copy_viewport_frame_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C2C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066C30: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066C34: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066C38: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066C3C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066C40: addiu       $t7, $t7, -0x2F9C
    ctx->r15 = ADD32(ctx->r15, -0X2F9C);
    // 0x80066C44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066C48: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066C4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80066C50: nop

    // 0x80066C54: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066C58: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80066C5C: nop

    // 0x80066C60: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80066C64: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80066C68: nop

    // 0x80066C6C: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80066C70: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066C74: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80066C78: jr          $ra
    // 0x80066C7C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    return;
    // 0x80066C7C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
;}
RECOMP_FUNC void obj_init_frog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042218: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8004221C: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x80042220: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042224: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
    // 0x80042228: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004222C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80042230: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80042234: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80042238: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004223C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80042240: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80042244: nop

    // 0x80042248: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8004224C: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x80042250: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80042254: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80042258: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004225C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80042260: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x80042264: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80042268: nop

    // 0x8004226C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80042270: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80042274: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80042278: nop

    // 0x8004227C: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80042280: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80042284: sb          $zero, 0x19($v0)
    MEM_B(0X19, ctx->r2) = 0;
    // 0x80042288: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x8004228C: beq         $t8, $zero, L_800422DC
    if (ctx->r24 == 0) {
        // 0x80042290: swc1        $f6, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
            goto L_800422DC;
    }
    // 0x80042290: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80042294: sb          $t9, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r25;
    // 0x80042298: jal         0x8009ECD0
    // 0x8004229C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_drumstick_unlocked(rdram, ctx);
        goto after_0;
    // 0x8004229C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800422A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800422A4: bne         $v0, $zero, L_800422CC
    if (ctx->r2 != 0) {
        // 0x800422A8: nop
    
            goto L_800422CC;
    }
    // 0x800422A8: nop

    // 0x800422AC: jal         0x8006EA90
    // 0x800422B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x800422B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800422B4: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x800422B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800422BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800422C0: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800422C4: beq         $t1, $at, L_800422E4
    if (ctx->r9 == ctx->r1) {
        // 0x800422C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800422E4;
    }
    // 0x800422C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800422CC:
    // 0x800422CC: jal         0x8000FFB8
    // 0x800422D0: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x800422D0: nop

    after_2:
    // 0x800422D4: b           L_800422E4
    // 0x800422D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800422E4;
    // 0x800422D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800422DC:
    // 0x800422DC: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x800422E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800422E4:
    // 0x800422E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800422E8: jr          $ra
    // 0x800422EC: nop

    return;
    // 0x800422EC: nop

;}
RECOMP_FUNC void reset_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE60: sb          $zero, 0x645C($at)
    MEM_B(0X645C, ctx->r1) = 0;
    // 0x8009BE64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE68: sb          $zero, 0x6464($at)
    MEM_B(0X6464, ctx->r1) = 0;
    // 0x8009BE6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE70: sb          $zero, 0x6454($at)
    MEM_B(0X6454, ctx->r1) = 0;
    // 0x8009BE74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE78: sb          $zero, 0x6458($at)
    MEM_B(0X6458, ctx->r1) = 0;
    // 0x8009BE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE80: sb          $zero, 0x6468($at)
    MEM_B(0X6468, ctx->r1) = 0;
    // 0x8009BE84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE88: sb          $zero, 0x646C($at)
    MEM_B(0X646C, ctx->r1) = 0;
    // 0x8009BE8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE90: sb          $zero, 0x645D($at)
    MEM_B(0X645D, ctx->r1) = 0;
    // 0x8009BE94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BE98: sb          $zero, 0x6465($at)
    MEM_B(0X6465, ctx->r1) = 0;
    // 0x8009BE9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEA0: sb          $zero, 0x6455($at)
    MEM_B(0X6455, ctx->r1) = 0;
    // 0x8009BEA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEA8: sb          $zero, 0x6459($at)
    MEM_B(0X6459, ctx->r1) = 0;
    // 0x8009BEAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEB0: sb          $zero, 0x6469($at)
    MEM_B(0X6469, ctx->r1) = 0;
    // 0x8009BEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEB8: sb          $zero, 0x646D($at)
    MEM_B(0X646D, ctx->r1) = 0;
    // 0x8009BEBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEC0: sb          $zero, 0x645E($at)
    MEM_B(0X645E, ctx->r1) = 0;
    // 0x8009BEC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEC8: sb          $zero, 0x6466($at)
    MEM_B(0X6466, ctx->r1) = 0;
    // 0x8009BECC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BED0: sb          $zero, 0x6456($at)
    MEM_B(0X6456, ctx->r1) = 0;
    // 0x8009BED4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BED8: sb          $zero, 0x645A($at)
    MEM_B(0X645A, ctx->r1) = 0;
    // 0x8009BEDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEE0: sb          $zero, 0x646A($at)
    MEM_B(0X646A, ctx->r1) = 0;
    // 0x8009BEE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEE8: sb          $zero, 0x646E($at)
    MEM_B(0X646E, ctx->r1) = 0;
    // 0x8009BEEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEF0: sb          $zero, 0x645F($at)
    MEM_B(0X645F, ctx->r1) = 0;
    // 0x8009BEF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BEF8: sb          $zero, 0x6467($at)
    MEM_B(0X6467, ctx->r1) = 0;
    // 0x8009BEFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF00: sb          $zero, 0x6457($at)
    MEM_B(0X6457, ctx->r1) = 0;
    // 0x8009BF04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF08: sb          $zero, 0x645B($at)
    MEM_B(0X645B, ctx->r1) = 0;
    // 0x8009BF0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF10: sb          $zero, 0x646B($at)
    MEM_B(0X646B, ctx->r1) = 0;
    // 0x8009BF14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BF18: jr          $ra
    // 0x8009BF1C: sb          $zero, 0x646F($at)
    MEM_B(0X646F, ctx->r1) = 0;
    return;
    // 0x8009BF1C: sb          $zero, 0x646F($at)
    MEM_B(0X646F, ctx->r1) = 0;
;}
RECOMP_FUNC void filename_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097918: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8009791C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097920: lwc1        $f0, 0x6C50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6C50);
    // 0x80097924: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80097928: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009792C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097930: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80097934: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80097938: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009793C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80097940: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80097944: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80097948: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8009794C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097950: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80097954: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80097958: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8009795C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80097960: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80097964: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80097968: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8009796C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80097970: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80097974: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80097978: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8009797C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80097980: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097984: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80097988: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8009798C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80097990: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80097994: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80097998: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8009799C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800979A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800979A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800979A8: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x800979AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800979B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800979B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800979B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800979BC: jal         0x800C43CC
    // 0x800979C0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x800979C0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800979C4: jal         0x800C42EC
    // 0x800979C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x800979C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800979CC: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x800979D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800979D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800979D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800979DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800979E0: jal         0x800C4384
    // 0x800979E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x800979E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x800979E8: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800979EC: addiu       $s1, $s1, -0xB60
    ctx->r17 = ADD32(ctx->r17, -0XB60);
    // 0x800979F0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800979F4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800979F8: addiu       $s0, $s0, 0xF90
    ctx->r16 = ADD32(ctx->r16, 0XF90);
    // 0x800979FC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80097A00: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80097A04: addiu       $s3, $s3, 0x63A0
    ctx->r19 = ADD32(ctx->r19, 0X63A0);
    // 0x80097A08: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80097A0C: lw          $a3, 0x20($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X20);
    // 0x80097A10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80097A14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097A18: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x80097A1C: jal         0x800C4440
    // 0x80097A20: addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x80097A20: addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    after_3:
    // 0x80097A24: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80097A28: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80097A2C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80097A30: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80097A34: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097A38: jal         0x800C4384
    // 0x80097A3C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80097A3C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_4:
    // 0x80097A40: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80097A44: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80097A48: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80097A4C: lw          $a3, 0x20($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X20);
    // 0x80097A50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80097A54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097A58: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80097A5C: jal         0x800C4440
    // 0x80097A60: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80097A60: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    after_5:
    // 0x80097A64: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80097A68: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80097A6C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80097A70: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80097A74: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80097A78: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80097A7C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80097A80: addiu       $s4, $s4, 0xF8C
    ctx->r20 = ADD32(ctx->r20, 0XF8C);
    // 0x80097A84: addiu       $s7, $s7, 0x6C6C
    ctx->r23 = ADD32(ctx->r23, 0X6C6C);
    // 0x80097A88: addiu       $fp, $fp, 0xF6C
    ctx->r30 = ADD32(ctx->r30, 0XF6C);
L_80097A8C:
    // 0x80097A8C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80097A90: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80097A94: beq         $t7, $zero, L_80097AB0
    if (ctx->r15 == 0) {
        // 0x80097A98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80097AB0;
    }
    // 0x80097A98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80097A9C: addiu       $s1, $v1, -0x28
    ctx->r17 = ADD32(ctx->r3, -0X28);
    // 0x80097AA0: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x80097AA4: addiu       $s5, $zero, -0x28
    ctx->r21 = ADD32(0, -0X28);
    // 0x80097AA8: b           L_80097AB8
    // 0x80097AAC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
        goto L_80097AB8;
    // 0x80097AAC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80097AB0:
    // 0x80097AB0: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
    // 0x80097AB4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80097AB8:
    // 0x80097AB8: slti        $at, $s1, -0xF
    ctx->r1 = SIGNED(ctx->r17) < -0XF ? 1 : 0;
    // 0x80097ABC: bne         $at, $zero, L_80097C14
    if (ctx->r1 != 0) {
        // 0x80097AC0: slti        $at, $s1, 0x150
        ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
            goto L_80097C14;
    }
    // 0x80097AC0: slti        $at, $s1, 0x150
    ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
    // 0x80097AC4: beq         $at, $zero, L_80097C18
    if (ctx->r1 == 0) {
        // 0x80097AC8: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_80097C18;
    }
    // 0x80097AC8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_80097ACC:
    // 0x80097ACC: bgez        $s0, L_80097AD8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80097AD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80097AD8;
    }
    // 0x80097AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097AD4: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_80097AD8:
    // 0x80097AD8: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
    // 0x80097ADC: bne         $at, $zero, L_80097AE8
    if (ctx->r1 != 0) {
        // 0x80097AE0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80097AE8;
    }
    // 0x80097AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097AE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80097AE8:
    // 0x80097AE8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80097AEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097AF0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80097AF4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80097AF8: bne         $s0, $t8, L_80097B24
    if (ctx->r16 != ctx->r24) {
        // 0x80097AFC: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80097B24;
    }
    // 0x80097AFC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80097B00: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80097B04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80097B08: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80097B0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097B10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097B14: jal         0x800C4384
    // 0x80097B18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x80097B18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80097B1C: b           L_80097B30
    // 0x80097B20: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
        goto L_80097B30;
    // 0x80097B20: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
L_80097B24:
    // 0x80097B24: jal         0x800C4384
    // 0x80097B28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80097B28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_7:
    // 0x80097B2C: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
L_80097B30:
    // 0x80097B30: beq         $at, $zero, L_80097B70
    if (ctx->r1 == 0) {
        // 0x80097B34: nop
    
            goto L_80097B70;
    }
    // 0x80097B34: nop

    // 0x80097B38: jal         0x800C42EC
    // 0x80097B3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_8;
    // 0x80097B3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80097B40: addu        $t2, $fp, $s0
    ctx->r10 = ADD32(ctx->r30, ctx->r16);
    // 0x80097B44: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80097B48: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80097B4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80097B50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097B54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097B58: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80097B5C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80097B60: jal         0x800C4440
    // 0x80097B64: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
    draw_text(rdram, ctx);
        goto after_9;
    // 0x80097B64: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
    after_9:
    // 0x80097B68: b           L_80097BFC
    // 0x80097B6C: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80097BFC;
    // 0x80097B6C: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80097B70:
    // 0x80097B70: jal         0x800C42EC
    // 0x80097B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_10;
    // 0x80097B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80097B78: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80097B7C: bne         $s0, $at, L_80097BA8
    if (ctx->r16 != ctx->r1) {
        // 0x80097B80: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80097BA8;
    }
    // 0x80097B80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097B84: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80097B88: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80097B8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80097B90: addiu       $a3, $a3, -0x7DBC
    ctx->r7 = ADD32(ctx->r7, -0X7DBC);
    // 0x80097B94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097B98: jal         0x800C4440
    // 0x80097B9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80097B9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x80097BA0: b           L_80097BFC
    // 0x80097BA4: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80097BFC;
    // 0x80097BA4: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80097BA8:
    // 0x80097BA8: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80097BAC: bne         $s0, $at, L_80097BDC
    if (ctx->r16 != ctx->r1) {
        // 0x80097BB0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80097BDC;
    }
    // 0x80097BB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097BB4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80097BB8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80097BBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80097BC0: addiu       $a3, $a3, -0x7DB8
    ctx->r7 = ADD32(ctx->r7, -0X7DB8);
    // 0x80097BC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097BC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097BCC: jal         0x800C4440
    // 0x80097BD0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80097BD0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_12:
    // 0x80097BD4: b           L_80097BFC
    // 0x80097BD8: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80097BFC;
    // 0x80097BD8: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80097BDC:
    // 0x80097BDC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80097BE0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80097BE4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80097BE8: addiu       $a3, $a3, -0x7DB4
    ctx->r7 = ADD32(ctx->r7, -0X7DB4);
    // 0x80097BEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097BF0: jal         0x800C4440
    // 0x80097BF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_13;
    // 0x80097BF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x80097BF8: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80097BFC:
    // 0x80097BFC: slti        $at, $s1, -0xF
    ctx->r1 = SIGNED(ctx->r17) < -0XF ? 1 : 0;
    // 0x80097C00: bne         $at, $zero, L_80097C14
    if (ctx->r1 != 0) {
        // 0x80097C04: addu        $s0, $s0, $s6
        ctx->r16 = ADD32(ctx->r16, ctx->r22);
            goto L_80097C14;
    }
    // 0x80097C04: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80097C08: slti        $at, $s1, 0x150
    ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
    // 0x80097C0C: bne         $at, $zero, L_80097ACC
    if (ctx->r1 != 0) {
        // 0x80097C10: nop
    
            goto L_80097ACC;
    }
    // 0x80097C10: nop

L_80097C14:
    // 0x80097C14: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_80097C18:
    // 0x80097C18: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80097C1C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80097C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097C24: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80097C28: bne         $t8, $at, L_80097A8C
    if (ctx->r24 != ctx->r1) {
        // 0x80097C2C: sw          $t8, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r24;
            goto L_80097A8C;
    }
    // 0x80097C2C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80097C30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80097C34: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80097C38: lw          $a0, 0x6C74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C74);
    // 0x80097C3C: jal         0x800977D0
    // 0x80097C40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    filename_trim(rdram, ctx);
        goto after_14;
    // 0x80097C40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x80097C44: beq         $s0, $zero, L_80097CE0
    if (ctx->r16 == 0) {
        // 0x80097C48: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80097CE0;
    }
    // 0x80097C48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097C4C: lw          $a0, 0xF9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF9C);
    // 0x80097C50: jal         0x800C42EC
    // 0x80097C54: nop

    set_text_font(rdram, ctx);
        goto after_15;
    // 0x80097C54: nop

    after_15:
    // 0x80097C58: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80097C5C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80097C60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097C68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097C6C: jal         0x800C4384
    // 0x80097C70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x80097C70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_16:
    // 0x80097C74: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80097C78: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80097C7C: addiu       $s2, $s2, 0xF98
    ctx->r18 = ADD32(ctx->r18, 0XF98);
    // 0x80097C80: addiu       $s1, $s1, 0xF94
    ctx->r17 = ADD32(ctx->r17, 0XF94);
    // 0x80097C84: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80097C88: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80097C8C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80097C90: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80097C94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097C98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80097C9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80097CA0: jal         0x800C4440
    // 0x80097CA4: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    draw_text(rdram, ctx);
        goto after_17;
    // 0x80097CA4: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    after_17:
    // 0x80097CA8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80097CAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80097CB0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80097CB4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097CB8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097CBC: jal         0x800C4384
    // 0x80097CC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80097CC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80097CC4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80097CC8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80097CCC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80097CD0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80097CD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097CD8: jal         0x800C4440
    // 0x80097CDC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_19;
    // 0x80097CDC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_19:
L_80097CE0:
    // 0x80097CE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80097CE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80097CE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80097CEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80097CF0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80097CF4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80097CF8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80097CFC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80097D00: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80097D04: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80097D08: jr          $ra
    // 0x80097D0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80097D0C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void vec3f_rotate_ypr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800703D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800703DC: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800703E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800703E4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800703E8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800703EC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800703F0: jal         0x800707C4
    // 0x800703F4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800703F4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x800703F8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800703FC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80070400: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070404: jal         0x800707F8
    // 0x80070408: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070408: nop

    after_1:
    // 0x8007040C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070410: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80070414: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070418: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8007041C: jal         0x800707C4
    // 0x80070420: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070420: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80070424: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070428: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007042C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070430: jal         0x800707F8
    // 0x80070434: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x80070434: nop

    after_3:
    // 0x80070438: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007043C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070440: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070444: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80070448: jal         0x800707C4
    // 0x8007044C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x8007044C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x80070450: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070454: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070458: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007045C: jal         0x800707F8
    // 0x80070460: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x80070460: nop

    after_5:
    // 0x80070464: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070468: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8007046C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070470: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80070474: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80070478: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8007047C: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x80070480: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070484: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070488: jr          $ra
    // 0x8007048C: nop

    return;
    // 0x8007048C: nop

;}
RECOMP_FUNC void lensflare_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACA20: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x800ACA24: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800ACA28: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800ACA2C: addiu       $s6, $s6, 0x2A80
    ctx->r22 = ADD32(ctx->r22, 0X2A80);
    // 0x800ACA30: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800ACA34: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800ACA38: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800ACA3C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800ACA40: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800ACA44: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800ACA48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800ACA4C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800ACA50: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800ACA54: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800ACA58: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800ACA5C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800ACA60: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800ACA64: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800ACA68: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800ACA6C: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800ACA70: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800ACA74: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800ACA78: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800ACA7C: beq         $t7, $zero, L_800ACF18
    if (ctx->r15 == 0) {
        // 0x800ACA80: swc1        $f20, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
            goto L_800ACF18;
    }
    // 0x800ACA80: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800ACA84: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ACA88: lw          $t9, 0x2A84($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2A84);
    // 0x800ACA8C: nop

    // 0x800ACA90: bne         $t9, $zero, L_800ACF1C
    if (ctx->r25 != 0) {
        // 0x800ACA94: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800ACF1C;
    }
    // 0x800ACA94: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800ACA98: jal         0x80066210
    // 0x800ACA9C: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800ACA9C: nop

    after_0:
    // 0x800ACAA0: bne         $v0, $zero, L_800ACF18
    if (ctx->r2 != 0) {
        // 0x800ACAA4: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800ACF18;
    }
    // 0x800ACAA4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800ACAA8: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800ACAAC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800ACAB0: lw          $t3, 0x3C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X3C);
    // 0x800ACAB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ACAB8: swc1        $f20, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f20.u32l;
    // 0x800ACABC: swc1        $f20, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f20.u32l;
    // 0x800ACAC0: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x800ACAC4: jal         0x80069DA4
    // 0x800ACAC8: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x800ACAC8: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800ACACC: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x800ACAD0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800ACAD4: jal         0x8006F6EC
    // 0x800ACAD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x800ACAD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800ACADC: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800ACAE0: addiu       $fp, $fp, 0x7C30
    ctx->r30 = ADD32(ctx->r30, 0X7C30);
    // 0x800ACAE4: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800ACAE8: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800ACAEC: lwc1        $f10, 0x4($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800ACAF0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800ACAF4: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800ACAF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ACAFC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800ACB00: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800ACB04: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800ACB08: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800ACB0C: lwc1        $f8, 0x8($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800ACB10: nop

    // 0x800ACB14: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ACB18: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800ACB1C: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800ACB20: nop

    // 0x800ACB24: bc1f        L_800ACF1C
    if (!c1cs) {
        // 0x800ACB28: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800ACF1C;
    }
    // 0x800ACB28: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800ACB2C: jal         0x80066CDC
    // 0x800ACB30: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    viewport_main(rdram, ctx);
        goto after_3;
    // 0x800ACB30: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800ACB34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ACB38: jal         0x80068408
    // 0x800ACB3C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_4;
    // 0x800ACB3C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x800ACB40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800ACB44: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800ACB48: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800ACB4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACB50: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800ACB54: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800ACB58: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800ACB5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACB60: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800ACB64: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800ACB68: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800ACB6C: lwc1        $f18, 0xC8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800ACB70: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800ACB74: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800ACB78: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800ACB7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACB80: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800ACB84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ACB88: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800ACB8C: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x800ACB90: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800ACB94: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800ACB98: mul.s       $f20, $f18, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800ACB9C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800ACBA0: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x800ACBA4: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800ACBA8: mul.s       $f22, $f20, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800ACBAC: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800ACBB0: sh          $zero, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = 0;
    // 0x800ACBB4: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x800ACBB8: mul.s       $f16, $f24, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x800ACBBC: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x800ACBC0: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x800ACBC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ACBC8: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800ACBCC: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800ACBD0: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800ACBD4: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800ACBD8: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800ACBDC: nop

    // 0x800ACBE0: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800ACBE4: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800ACBE8: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800ACBEC: sub.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800ACBF0: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
L_800ACBF4:
    // 0x800ACBF4: bne         $s2, $zero, L_800ACC08
    if (ctx->r18 != 0) {
        // 0x800ACBF8: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800ACC08;
    }
    // 0x800ACBF8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800ACBFC: lw          $s0, 0x7C2C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7C2C);
    // 0x800ACC00: b           L_800ACC28
    // 0x800ACC04: nop

        goto L_800ACC28;
    // 0x800ACC04: nop

L_800ACC08:
    // 0x800ACC08: bne         $s2, $v0, L_800ACC20
    if (ctx->r18 != ctx->r2) {
        // 0x800ACC0C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800ACC20;
    }
    // 0x800ACC0C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800ACC10: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800ACC14: lw          $s0, 0x7C24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7C24);
    // 0x800ACC18: b           L_800ACC28
    // 0x800ACC1C: nop

        goto L_800ACC28;
    // 0x800ACC1C: nop

L_800ACC20:
    // 0x800ACC20: lw          $s0, 0x7C28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7C28);
    // 0x800ACC24: nop

L_800ACC28:
    // 0x800ACC28: beq         $s0, $zero, L_800ACD8C
    if (ctx->r16 == 0) {
        // 0x800ACC2C: nop
    
            goto L_800ACD8C;
    }
    // 0x800ACC2C: nop

    // 0x800ACC30: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800ACC34: nop

    // 0x800ACC38: blez        $t5, L_800ACD8C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800ACC3C: nop
    
            goto L_800ACD8C;
    }
    // 0x800ACC3C: nop

L_800ACC40:
    // 0x800ACC40: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800ACC44: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800ACC48: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800ACC4C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800ACC50: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800ACC54: beq         $s2, $zero, L_800ACCB0
    if (ctx->r18 == 0) {
        // 0x800ACC58: swc1        $f10, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
            goto L_800ACCB0;
    }
    // 0x800ACC58: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800ACC5C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800ACC60: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800ACC64: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800ACC68: nop

    // 0x800ACC6C: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ACC70: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800ACC74: nop

    // 0x800ACC78: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800ACC7C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800ACC80: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800ACC84: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800ACC88: nop

    // 0x800ACC8C: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ACC90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACC94: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800ACC98: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x800ACC9C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800ACCA0: nop

    // 0x800ACCA4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ACCA8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800ACCAC: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
L_800ACCB0:
    // 0x800ACCB0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800ACCB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ACCB8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800ACCBC: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800ACCC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ACCC4: nop

    // 0x800ACCC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800ACCCC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800ACCD0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800ACCD4: lbu         $t3, 0x5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X5);
    // 0x800ACCD8: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x800ACCDC: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x800ACCE0: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800ACCE4: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800ACCE8: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800ACCEC: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x800ACCF0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800ACCF4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800ACCF8: or          $t3, $t8, $t6
    ctx->r11 = ctx->r24 | ctx->r14;
    // 0x800ACCFC: bgez        $t9, L_800ACD10
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800ACD00: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800ACD10;
    }
    // 0x800ACD00: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800ACD04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACD08: nop

    // 0x800ACD0C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800ACD10:
    // 0x800ACD10: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800ACD14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ACD18: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800ACD1C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800ACD20: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800ACD24: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800ACD28: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800ACD2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ACD30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ACD34: nop

    // 0x800ACD38: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ACD3C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800ACD40: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800ACD44: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800ACD48: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800ACD4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800ACD50: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800ACD54: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800ACD58: lw          $t9, 0x68($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X68);
    // 0x800ACD5C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800ACD60: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x800ACD64: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800ACD68: addiu       $t8, $zero, 0x104
    ctx->r24 = ADD32(0, 0X104);
    // 0x800ACD6C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800ACD70: jal         0x80068514
    // 0x800ACD74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x800ACD74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800ACD78: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800ACD7C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ACD80: bgtz        $t6, L_800ACC40
    if (SIGNED(ctx->r14) > 0) {
        // 0x800ACD84: nop
    
            goto L_800ACC40;
    }
    // 0x800ACD84: nop

    // 0x800ACD88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACD8C:
    // 0x800ACD8C: bne         $s2, $v0, L_800ACDF4
    if (ctx->r18 != ctx->r2) {
        // 0x800ACD90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800ACDF4;
    }
    // 0x800ACD90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACD94: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800ACD98: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800ACD9C: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800ACDA0: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800ACDA4: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800ACDA8: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800ACDAC: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800ACDB0: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800ACDB4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800ACDB8: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800ACDBC: nop

    // 0x800ACDC0: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800ACDC4: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800ACDC8: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800ACDCC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800ACDD0: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800ACDD4: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ACDD8: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800ACDDC: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800ACDE0: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800ACDE4: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800ACDE8: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x800ACDEC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800ACDF0: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
L_800ACDF4:
    // 0x800ACDF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ACDF8: bne         $s2, $at, L_800ACBF4
    if (ctx->r18 != ctx->r1) {
        // 0x800ACDFC: nop
    
            goto L_800ACBF4;
    }
    // 0x800ACDFC: nop

    // 0x800ACE00: jal         0x8007A520
    // 0x800ACE04: nop

    fb_size(rdram, ctx);
        goto after_6;
    // 0x800ACE04: nop

    after_6:
    extern void dkr_track_select_lens_flare_tint_begin(uint8_t*, recomp_context*); dkr_track_select_lens_flare_tint_begin(rdram, ctx);
    // 0x800ACE08: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800ACE0C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800ACE10: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800ACE14: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ACE18: addiu       $t4, $t4, 0x2928
    ctx->r12 = ADD32(ctx->r12, 0X2928);
    // 0x800ACE1C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800ACE20: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800ACE24: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800ACE28: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800ACE2C: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800ACE30: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800ACE34: andi        $t5, $t0, 0xFFFF
    ctx->r13 = ctx->r8 & 0XFFFF;
    // 0x800ACE38: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800ACE3C: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x800ACE40: lbu         $t5, 0x11($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X11);
    // 0x800ACE44: lbu         $t7, 0x10($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X10);
    // 0x800ACE48: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800ACE4C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800ACE50: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x800ACE54: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
    // 0x800ACE58: lbu         $t7, 0x12($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X12);
    // 0x800ACE5C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800ACE60: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800ACE64: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800ACE68: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800ACE6C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800ACE70: bgez        $t8, L_800ACE88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800ACE74: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800ACE88;
    }
    // 0x800ACE74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ACE78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ACE7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ACE80: nop

    // 0x800ACE84: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800ACE88:
    // 0x800ACE88: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800ACE8C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800ACE90: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800ACE94: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x800ACE98: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800ACE9C: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x800ACEA0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800ACEA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800ACEA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800ACEAC: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800ACEB0: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800ACEB4: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x800ACEB8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800ACEBC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800ACEC0: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800ACEC4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800ACEC8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800ACECC: andi        $t9, $t1, 0x3FF
    ctx->r25 = ctx->r9 & 0X3FF;
    // 0x800ACED0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800ACED4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800ACED8: sll         $t3, $t9, 14
    ctx->r11 = S32(ctx->r25 << 14);
    // 0x800ACEDC: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x800ACEE0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800ACEE4: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x800ACEE8: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800ACEEC: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x800ACEF0: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x800ACEF4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800ACEF8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800ACEFC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800ACF00: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800ACF04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ACF08: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800ACF0C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    extern void dkr_track_select_lens_flare_tint_end(uint8_t*, recomp_context*); dkr_track_select_lens_flare_tint_end(rdram, ctx);
    // 0x800ACF10: jal         0x8007B3D0
    // 0x800ACF14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x800ACF14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_800ACF18:
    // 0x800ACF18: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800ACF1C:
    // 0x800ACF1C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800ACF20: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800ACF24: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800ACF28: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ACF2C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800ACF30: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800ACF34: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800ACF38: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800ACF3C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800ACF40: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800ACF44: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800ACF48: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800ACF4C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800ACF50: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800ACF54: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800ACF58: jr          $ra
    // 0x800ACF5C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800ACF5C: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void enable_dialogue_box_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C56A8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C56AC: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C56B0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C56B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C56B8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C56BC: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C56C0: nop

    // 0x800C56C4: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x800C56C8: jr          $ra
    // 0x800C56CC: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C56CC: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void mtx_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069A40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069A44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069A48: addiu       $a2, $a2, 0xD1C
    ctx->r6 = ADD32(ctx->r6, 0XD1C);
    // 0x80069A4C: addiu       $a1, $a1, 0xD20
    ctx->r5 = ADD32(ctx->r5, 0XD20);
    // 0x80069A50: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80069A54: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80069A58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80069A5C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80069A60: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80069A64: blez        $t9, L_80069AA8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80069A68: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80069AA8;
    }
    // 0x80069A68: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80069A6C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069A70: lui         $t2, 0x140
    ctx->r10 = S32(0X140 << 16);
    // 0x80069A74: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80069A78: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80069A7C: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x80069A80: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80069A84: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80069A88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80069A8C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80069A90: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80069A94: lw          $t5, 0xD88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD88);
    // 0x80069A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069A9C: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069AA0: jr          $ra
    // 0x80069AA4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    return;
    // 0x80069AA4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80069AA8:
    // 0x80069AA8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069AAC: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80069AB0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80069AB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80069AB8: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80069ABC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80069AC0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80069AC4: jr          $ra
    // 0x80069AC8: nop

    return;
    // 0x80069AC8: nop

;}
RECOMP_FUNC void obj_init_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003818C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038190: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038194: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x80038198: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003819C: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800381A0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800381A4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800381A8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800381AC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800381B0: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800381B4: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800381B8: jr          $ra
    // 0x800381BC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800381BC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void cheatlist_exclusive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8F8: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8008A8FC: beq         $t6, $zero, L_8008A920
    if (ctx->r14 == 0) {
        // 0x8008A900: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008A920;
    }
    // 0x8008A900: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A904: addiu       $v1, $v1, -0x268
    ctx->r3 = ADD32(ctx->r3, -0X268);
    // 0x8008A908: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008A90C: nor         $t8, $a2, $zero
    ctx->r24 = ~(ctx->r6 | 0);
    // 0x8008A910: and         $t7, $a0, $v0
    ctx->r15 = ctx->r4 & ctx->r2;
    // 0x8008A914: beq         $t7, $zero, L_8008A920
    if (ctx->r15 == 0) {
        // 0x8008A918: and         $t9, $v0, $t8
        ctx->r25 = ctx->r2 & ctx->r24;
            goto L_8008A920;
    }
    // 0x8008A918: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x8008A91C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8008A920:
    // 0x8008A920: jr          $ra
    // 0x8008A924: nop

    return;
    // 0x8008A924: nop

;}
RECOMP_FUNC void func_8002C71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C71C: lh          $t6, 0x20($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X20);
    // 0x8002C720: addiu       $t0, $zero, -0x2710
    ctx->r8 = ADD32(0, -0X2710);
    // 0x8002C724: sh          $t0, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r8;
    // 0x8002C728: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002C72C: blez        $t6, L_8002C7BC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002C730: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002C7BC;
    }
    // 0x8002C730: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C738: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8002C73C:
    // 0x8002C73C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C740: nop

    // 0x8002C744: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C748: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8002C74C: nop

    // 0x8002C750: andi        $t2, $t9, 0x2000
    ctx->r10 = ctx->r25 & 0X2000;
    // 0x8002C754: beq         $t2, $zero, L_8002C7A8
    if (ctx->r10 == 0) {
        // 0x8002C758: nop
    
            goto L_8002C7A8;
    }
    // 0x8002C758: nop

    // 0x8002C75C: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8002C760: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8002C764: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002C768: sh          $v1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r3;
    // 0x8002C76C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C770: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C774: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C778: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8002C77C: lh          $a3, 0x38($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X38);
    // 0x8002C780: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002C784: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C788: mflo        $t2
    ctx->r10 = lo;
    // 0x8002C78C: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x8002C790: lh          $a2, 0x2($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X2);
    // 0x8002C794: beq         $t0, $a3, L_8002C7A4
    if (ctx->r8 == ctx->r7) {
        // 0x8002C798: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8002C7A4;
    }
    // 0x8002C798: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002C79C: beq         $at, $zero, L_8002C7A8
    if (ctx->r1 == 0) {
        // 0x8002C7A0: nop
    
            goto L_8002C7A8;
    }
    // 0x8002C7A0: nop

L_8002C7A4:
    // 0x8002C7A4: sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
L_8002C7A8:
    // 0x8002C7A8: lh          $t4, 0x20($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X20);
    // 0x8002C7AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002C7B0: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C7B4: bne         $at, $zero, L_8002C73C
    if (ctx->r1 != 0) {
        // 0x8002C7B8: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002C73C;
    }
    // 0x8002C7B8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002C7BC:
    // 0x8002C7BC: jr          $ra
    // 0x8002C7C0: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
    return;
    // 0x8002C7C0: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void emitter_change_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF134: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF138: lw          $t6, 0x2CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2CE8);
    // 0x800AF13C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF140: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF148: bne         $at, $zero, L_800AF154
    if (ctx->r1 != 0) {
        // 0x800AF14C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800AF154;
    }
    // 0x800AF14C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800AF150: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800AF154:
    // 0x800AF154: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF158: lw          $t7, 0x2CF4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2CF4);
    // 0x800AF15C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF160: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AF164: bne         $at, $zero, L_800AF170
    if (ctx->r1 != 0) {
        // 0x800AF168: nop
    
            goto L_800AF170;
    }
    // 0x800AF168: nop

    // 0x800AF16C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800AF170:
    // 0x800AF170: lw          $t8, 0x2CFC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2CFC);
    // 0x800AF174: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF178: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x800AF17C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF180: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AF184: bne         $a2, $t1, L_800AF19C
    if (ctx->r6 != ctx->r9) {
        // 0x800AF188: nop
    
            goto L_800AF19C;
    }
    // 0x800AF188: nop

    // 0x800AF18C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800AF190: nop

    // 0x800AF194: beq         $v0, $t2, L_800AF1D4
    if (ctx->r2 == ctx->r10) {
        // 0x800AF198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AF1D4;
    }
    // 0x800AF198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF19C:
    // 0x800AF19C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AF1A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AF1A4: jal         0x800B2260
    // 0x800AF1A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    emitter_cleanup(rdram, ctx);
        goto after_0;
    // 0x800AF1A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AF1AC: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x800AF1B0: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x800AF1B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AF1B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AF1BC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF1C0: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800AF1C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800AF1C8: jal         0x800AF29C
    // 0x800AF1CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x800AF1CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x800AF1D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF1D4:
    // 0x800AF1D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF1D8: jr          $ra
    // 0x800AF1DC: nop

    return;
    // 0x800AF1DC: nop

;}
RECOMP_FUNC void gzip_size_uncompressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C61DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C61E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C61E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C61E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C61EC: lw          $a1, 0x3764($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3764);
    // 0x800C61F0: jal         0x80076E68
    // 0x800C61F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x800C61F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x800C61F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C61FC: lw          $a0, 0x3764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3764);
    // 0x800C6200: jal         0x800C61AC
    // 0x800C6204: nop

    byteswap32(rdram, ctx);
        goto after_1;
    // 0x800C6204: nop

    after_1:
    // 0x800C6208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C620C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6210: jr          $ra
    // 0x800C6214: nop

    return;
    // 0x800C6214: nop

;}
RECOMP_FUNC void obj_init_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800387C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800387C4: jr          $ra
    // 0x800387C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800387C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void mempool_locked_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071478: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007147C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80071480: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071484: jal         0x8006F510
    // 0x80071488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8007148C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80071490: jal         0x800715EC
    // 0x80071494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x80071494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80071498: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8007149C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800714A0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800714A4: lw          $a0, 0x3588($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3588);
    // 0x800714A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800714AC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800714B0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800714B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800714B8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800714BC:
    // 0x800714BC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800714C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800714C4: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800714C8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800714CC: nop

    // 0x800714D0: bne         $s0, $t8, L_80071508
    if (ctx->r16 != ctx->r24) {
        // 0x800714D4: nop
    
            goto L_80071508;
    }
    // 0x800714D4: nop

    // 0x800714D8: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x800714DC: nop

    // 0x800714E0: beq         $a3, $v0, L_800714F0
    if (ctx->r7 == ctx->r2) {
        // 0x800714E4: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_800714F0;
    }
    // 0x800714E4: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
    // 0x800714E8: bne         $t0, $v0, L_80071508
    if (ctx->r8 != ctx->r2) {
        // 0x800714EC: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_80071508;
    }
    // 0x800714EC: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
L_800714F0:
    // 0x800714F0: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x800714F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800714F8: jal         0x8006F53C
    // 0x800714FC: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x800714FC: nop

    after_2:
    // 0x80071500: b           L_80071528
    // 0x80071504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80071528;
    // 0x80071504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80071508:
    // 0x80071508: lh          $v1, 0xC($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XC);
    // 0x8007150C: nop

    // 0x80071510: bne         $v1, $t1, L_800714BC
    if (ctx->r3 != ctx->r9) {
        // 0x80071514: nop
    
            goto L_800714BC;
    }
    // 0x80071514: nop

    // 0x80071518: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007151C: jal         0x8006F53C
    // 0x80071520: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071520: nop

    after_3:
    // 0x80071524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071528:
    // 0x80071528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007152C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071530: jr          $ra
    // 0x80071534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80071534: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void cam_set_sprite_anim_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006850C: jr          $ra
    // 0x80068510: sw          $a0, 0xD0C($at)
    MEM_W(0XD0C, ctx->r1) = ctx->r4;
    return;
    // 0x80068510: sw          $a0, 0xD0C($at)
    MEM_W(0XD0C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064950: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80064954: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80064958: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x8006495C: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80064960: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80064964: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80064968: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x8006496C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80064970: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80064974: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80064978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006497C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80064980:
    // 0x80064980: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064984: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80064988: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8006498C: bne         $at, $zero, L_80064980
    if (ctx->r1 != 0) {
        // 0x80064990: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_80064980;
    }
    // 0x80064990: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80064994: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80064998: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x8006499C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800649A0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800649A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800649A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800649AC: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x800649B0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800649B4: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x800649B8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800649BC: beq         $at, $zero, L_80064A00
    if (ctx->r1 == 0) {
        // 0x800649C0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80064A00;
    }
    // 0x800649C0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800649C4:
    // 0x800649C4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800649C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800649CC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800649D0: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x800649D4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800649D8: nop

    // 0x800649DC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800649E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800649E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800649E8: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800649EC: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800649F0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800649F4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800649F8: bne         $at, $zero, L_800649C4
    if (ctx->r1 != 0) {
        // 0x800649FC: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_800649C4;
    }
    // 0x800649FC: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_80064A00:
    // 0x80064A00: jr          $ra
    // 0x80064A04: nop

    return;
    // 0x80064A04: nop

;}
RECOMP_FUNC void obj_init_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004203C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042048: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004204C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x80042050: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x80042054: lbu         $a1, 0x9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X9);
    // 0x80042058: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x8004205C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80042060: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80042064: jal         0x800AF134
    // 0x80042068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    emitter_change_settings(rdram, ctx);
        goto after_0;
    // 0x80042068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8004206C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80042070: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80042074: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x80042078: nop

    // 0x8004207C: sw          $t9, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->r25;
    // 0x80042080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042088: jr          $ra
    // 0x8004208C: nop

    return;
    // 0x8004208C: nop

;}
RECOMP_FUNC void level_properties_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C1B0: addiu       $t0, $t0, -0x2CD8
    ctx->r8 = ADD32(ctx->r8, -0X2CD8);
    // 0x8006C1B4: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C1B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C1BC: addiu       $v1, $v1, 0x11C8
    ctx->r3 = ADD32(ctx->r3, 0X11C8);
    // 0x8006C1C0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C1C4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C1C8: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x8006C1CC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C1D0: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C1D4: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C1D8: nop

    // 0x8006C1DC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8006C1E0: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x8006C1E4: sh          $a1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r5;
    // 0x8006C1E8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8006C1EC: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x8006C1F0: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C1F4: nop

    // 0x8006C1F8: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8006C1FC: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8006C200: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x8006C204: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8006C208: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C20C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C210: nop

    // 0x8006C214: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C218: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C21C: sh          $a3, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r7;
    // 0x8006C220: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C224: jr          $ra
    // 0x8006C228: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    return;
    // 0x8006C228: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
;}
RECOMP_FUNC void thread3_verify_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E30: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80065E34: addiu       $v0, $v0, -0x28A8
    ctx->r2 = ADD32(ctx->r2, -0X28A8);
    // 0x80065E38: lw          $t7, 0x2004($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2004);
    // 0x80065E3C: lw          $t6, 0x2000($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2000);
    // 0x80065E40: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80065E44: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80065E48: sltiu       $at, $t9, 0x1
    ctx->r1 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80065E4C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80065E50: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80065E54: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80065E58: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80065E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E60: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80065E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E68: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x80065E6C: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x80065E70: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80065E74: bne         $t8, $t2, L_80065E80
    if (ctx->r24 != ctx->r10) {
        // 0x80065E78: sw          $t3, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r11;
            goto L_80065E80;
    }
    // 0x80065E78: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80065E7C: beq         $t9, $t3, L_80065E8C
    if (ctx->r25 == ctx->r11) {
        // 0x80065E80: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80065E8C;
    }
L_80065E80:
    // 0x80065E80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065E84: jal         0x800C9D54
    // 0x80065E88: addiu       $a0, $a0, 0x6ED0
    ctx->r4 = ADD32(ctx->r4, 0X6ED0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80065E88: addiu       $a0, $a0, 0x6ED0
    ctx->r4 = ADD32(ctx->r4, 0X6ED0);
    after_0:
L_80065E8C:
    // 0x80065E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065E90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065E94: jr          $ra
    // 0x80065E98: nop

    return;
    // 0x80065E98: nop

;}
RECOMP_FUNC void racer_update_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C278: jal         0x8001BA64
    // 0x8005C27C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x8005C27C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C284: nop

    // 0x8005C288: lb          $t6, 0x192($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X192);
    // 0x8005C28C: nop

    // 0x8005C290: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005C294: sb          $t7, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r15;
    // 0x8005C298: lb          $v1, 0x192($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X192);
    // 0x8005C29C: nop

    // 0x8005C2A0: bgez        $v1, L_8005C2C0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005C2A4: nop
    
            goto L_8005C2C0;
    }
    // 0x8005C2A4: nop

    // 0x8005C2A8: lb          $a1, 0x193($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X193);
    // 0x8005C2AC: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x8005C2B0: blez        $a1, L_8005C2C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005C2B4: sb          $t8, 0x192($a0)
        MEM_B(0X192, ctx->r4) = ctx->r24;
            goto L_8005C2C0;
    }
    // 0x8005C2B4: sb          $t8, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r24;
    // 0x8005C2B8: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x8005C2BC: sb          $t9, 0x193($a0)
    MEM_B(0X193, ctx->r4) = ctx->r25;
L_8005C2C0:
    // 0x8005C2C0: lh          $v0, 0x190($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X190);
    // 0x8005C2C4: nop

    // 0x8005C2C8: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x8005C2CC: bne         $at, $zero, L_8005C2D8
    if (ctx->r1 != 0) {
        // 0x8005C2D0: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8005C2D8;
    }
    // 0x8005C2D0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8005C2D4: sh          $t0, 0x190($a0)
    MEM_H(0X190, ctx->r4) = ctx->r8;
L_8005C2D8:
    // 0x8005C2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C2E0: jr          $ra
    // 0x8005C2E4: nop

    return;
    // 0x8005C2E4: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0B0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800CA0B4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800CA0B8: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800CA0BC: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800CA0C0: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800CA0C4: jr          $ra
    // 0x800CA0C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800CA0C8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void hud_main_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A277C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800A2780: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2784: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2788: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A278C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A2790: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A2794: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800A2798: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800A279C: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x800A27A0: lw          $t7, 0x64($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X64);
    // 0x800A27A4: addiu       $s0, $s0, 0x6CF4
    ctx->r16 = ADD32(ctx->r16, 0X6CF4);
    // 0x800A27A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A27AC: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800A27B0: lw          $t8, 0x50($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X50);
    // 0x800A27B4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A27B8: bne         $t8, $zero, L_800A2834
    if (ctx->r24 != 0) {
        // 0x800A27BC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A2834;
    }
    // 0x800A27BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A27C0: lw          $t9, 0x6CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CF0);
    // 0x800A27C4: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A27C8: lh          $t3, 0x28($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X28);
    // 0x800A27CC: sb          $t4, 0x91($sp)
    MEM_B(0X91, ctx->r29) = ctx->r12;
    // 0x800A27D0: sh          $zero, 0x92($sp)
    MEM_H(0X92, ctx->r29) = 0;
    // 0x800A27D4: sh          $zero, 0x94($sp)
    MEM_H(0X94, ctx->r29) = 0;
    // 0x800A27D8: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x800A27DC: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A27E0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x800A27E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A27E8: jal         0x8000EA54
    // 0x800A27EC: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x800A27EC: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    after_0:
    // 0x800A27F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A27F4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A27F8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A27FC: addiu       $s1, $s1, 0x6CDC
    ctx->r17 = ADD32(ctx->r17, 0X6CDC);
    // 0x800A2800: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800A2804: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2808: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A280C: sh          $t6, 0x340($t7)
    MEM_H(0X340, ctx->r15) = ctx->r14;
    // 0x800A2810: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2814: nop

    // 0x800A2818: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A281C: nop

    // 0x800A2820: beq         $a0, $zero, L_800A2834
    if (ctx->r4 == 0) {
        // 0x800A2824: nop
    
            goto L_800A2834;
    }
    // 0x800A2824: nop

    // 0x800A2828: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800A282C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2830: nop

L_800A2834:
    // 0x800A2834: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x800A2838: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A283C: bne         $t8, $zero, L_800A2898
    if (ctx->r24 != 0) {
        // 0x800A2840: addiu       $s1, $s1, 0x6CDC
        ctx->r17 = ADD32(ctx->r17, 0X6CDC);
            goto L_800A2898;
    }
    // 0x800A2840: addiu       $s1, $s1, 0x6CDC
    ctx->r17 = ADD32(ctx->r17, 0X6CDC);
    // 0x800A2844: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A2848: lw          $t9, 0x6CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CF0);
    // 0x800A284C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A2850: lh          $t3, 0x44($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X44);
    // 0x800A2854: sb          $t4, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r12;
    // 0x800A2858: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x800A285C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800A2860: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800A2864: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2868: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800A286C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2870: jal         0x8000EA54
    // 0x800A2874: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x800A2874: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    after_1:
    // 0x800A2878: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A287C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2880: sw          $v0, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r2;
    // 0x800A2884: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2888: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A288C: sh          $t6, 0x440($t7)
    MEM_H(0X440, ctx->r15) = ctx->r14;
    // 0x800A2890: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2894: nop

L_800A2898:
    // 0x800A2898: lw          $s0, 0x50($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X50);
    // 0x800A289C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A28A0: beq         $s0, $zero, L_800A36B4
    if (ctx->r16 == 0) {
        // 0x800A28A4: addiu       $s2, $s2, 0x6D67
        ctx->r18 = ADD32(ctx->r18, 0X6D67);
            goto L_800A36B4;
    }
    // 0x800A28A4: addiu       $s2, $s2, 0x6D67
    ctx->r18 = ADD32(ctx->r18, 0X6D67);
    // 0x800A28A8: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A28AC: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x800A28B0: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x800A28B4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800A28B8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800A28BC: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A28C0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800A28C4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800A28C8: sh          $t3, 0x52($t5)
    MEM_H(0X52, ctx->r13) = ctx->r11;
    // 0x800A28CC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800A28D0: nop

    // 0x800A28D4: beq         $v0, $at, L_800A2B68
    if (ctx->r2 == ctx->r1) {
        // 0x800A28D8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A2B68;
    }
    // 0x800A28D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A28DC: bne         $v0, $at, L_800A2914
    if (ctx->r2 != ctx->r1) {
        // 0x800A28E0: nop
    
            goto L_800A2914;
    }
    // 0x800A28E0: nop

    // 0x800A28E4: jal         0x8001139C
    // 0x800A28E8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_race_countdown(rdram, ctx);
        goto after_2;
    // 0x800A28E8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A28EC: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A28F0: bne         $v0, $zero, L_800A290C
    if (ctx->r2 != 0) {
        // 0x800A28F4: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A290C;
    }
    // 0x800A28F4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800A28F8: jal         0x800015C8
    // 0x800A28FC: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_is_playing(rdram, ctx);
        goto after_3;
    // 0x800A28FC: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A2900: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2904: bne         $v0, $zero, L_800A2914
    if (ctx->r2 != 0) {
        // 0x800A2908: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A2914;
    }
    // 0x800A2908: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
L_800A290C:
    // 0x800A290C: b           L_800A2B54
    // 0x800A2910: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
        goto L_800A2B54;
    // 0x800A2910: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
L_800A2914:
    // 0x800A2914: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2918: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A291C: bne         $t7, $at, L_800A2A28
    if (ctx->r15 != ctx->r1) {
        // 0x800A2920: nop
    
            goto L_800A2A28;
    }
    // 0x800A2920: nop

    // 0x800A2924: jal         0x800015F8
    // 0x800A2928: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_animation_fraction(rdram, ctx);
        goto after_4;
    // 0x800A2928: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A292C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A2930: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2934: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A2938: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x800A293C: lw          $t2, 0x44($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X44);
    // 0x800A2940: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800A2944: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800A2948: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x800A294C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A2950: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2954: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800A2958: c.eq.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d == ctx->f12.d;
    // 0x800A295C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800A2960: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2964: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A2968: bc1f        L_800A2978
    if (!c1cs) {
        // 0x800A296C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A2978;
    }
    // 0x800A296C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A2970: b           L_800A2B54
    // 0x800A2974: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800A2B54;
    // 0x800A2974: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800A2978:
    // 0x800A2978: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A297C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A2980: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A2984: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2988: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x800A298C: nop

    // 0x800A2990: bc1f        L_800A29E8
    if (!c1cs) {
        // 0x800A2994: nop
    
            goto L_800A29E8;
    }
    // 0x800A2994: nop

    // 0x800A2998: sub.d       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f12.d - ctx->f18.d;
    // 0x800A299C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A29A0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x800A29A4: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x800A29A8: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800A29AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A29B0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800A29B4: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800A29B8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A29BC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A29C0: nop

    // 0x800A29C4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A29C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A29CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A29D0: nop

    // 0x800A29D4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A29D8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A29DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A29E0: b           L_800A2B54
    // 0x800A29E4: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
        goto L_800A2B54;
    // 0x800A29E4: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800A29E8:
    // 0x800A29E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A29EC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A29F0: mul.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A29F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A29F8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A29FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2A00: nop

    // 0x800A2A04: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A2A08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2A0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2A10: nop

    // 0x800A2A14: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2A18: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A2A1C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2A20: b           L_800A2B54
    // 0x800A2A24: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800A2B54;
    // 0x800A2A24: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800A2A28:
    // 0x800A2A28: jal         0x8006EAA0
    // 0x800A2A2C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    is_game_paused(rdram, ctx);
        goto after_5;
    // 0x800A2A2C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A2A30: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2A34: bne         $v0, $zero, L_800A2B54
    if (ctx->r2 != 0) {
        // 0x800A2A38: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A2B54;
    }
    // 0x800A2A38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2A3C: addiu       $a1, $a1, 0x6D69
    ctx->r5 = ADD32(ctx->r5, 0X6D69);
    // 0x800A2A40: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x800A2A44: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2A48: bgez        $v0, L_800A2A94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2A4C: nop
    
            goto L_800A2A94;
    }
    // 0x800A2A4C: nop

    // 0x800A2A50: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2A54: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x800A2A58: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2A5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A2A60: mflo        $v1
    ctx->r3 = lo;
    // 0x800A2A64: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800A2A68: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A2A6C: beq         $at, $zero, L_800A2A7C
    if (ctx->r1 == 0) {
        // 0x800A2A70: addu        $t5, $a0, $v1
        ctx->r13 = ADD32(ctx->r4, ctx->r3);
            goto L_800A2A7C;
    }
    // 0x800A2A70: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x800A2A74: b           L_800A2B54
    // 0x800A2A78: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
        goto L_800A2B54;
    // 0x800A2A78: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
L_800A2A7C:
    // 0x800A2A7C: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800A2A80: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x800A2A84: nop

    // 0x800A2A88: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A2A8C: b           L_800A2B54
    // 0x800A2A90: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
        goto L_800A2B54;
    // 0x800A2A90: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_800A2A94:
    // 0x800A2A94: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2A98: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x800A2A9C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A2AA0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800A2AA4: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x800A2AA8: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800A2AAC: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2AB0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A2AB4: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A2AB8: lw          $t7, 0x44($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X44);
    // 0x800A2ABC: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800A2AC0: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800A2AC4: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x800A2AC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A2ACC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800A2AD0: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x800A2AD4: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A2AD8: bne         $at, $zero, L_800A2B58
    if (ctx->r1 != 0) {
        // 0x800A2ADC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A2B58;
    }
    // 0x800A2ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2AE0: lbu         $t5, 0x6D68($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X6D68);
    // 0x800A2AE4: nop

    // 0x800A2AE8: beq         $t5, $zero, L_800A2B08
    if (ctx->r13 == 0) {
        // 0x800A2AEC: nop
    
            goto L_800A2B08;
    }
    // 0x800A2AEC: nop

    // 0x800A2AF0: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x800A2AF4: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x800A2AF8: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800A2AFC: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x800A2B00: b           L_800A2B54
    // 0x800A2B04: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
        goto L_800A2B54;
    // 0x800A2B04: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
L_800A2B08:
    // 0x800A2B08: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800A2B0C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2B10: nop

    // 0x800A2B14: lbu         $t9, 0x1FC($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X1FC);
    // 0x800A2B18: nop

    // 0x800A2B1C: bne         $t9, $zero, L_800A2B58
    if (ctx->r25 != 0) {
        // 0x800A2B20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A2B58;
    }
    // 0x800A2B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2B24: lb          $t2, 0x1D8($t4)
    ctx->r10 = MEM_B(ctx->r12, 0X1D8);
    // 0x800A2B28: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A2B2C: bne         $t2, $zero, L_800A2B54
    if (ctx->r10 != 0) {
        // 0x800A2B30: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A2B54;
    }
    // 0x800A2B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2B34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A2B38: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A2B3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800A2B40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A2B44: jal         0x800A36CC
    // 0x800A2B48: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    hud_stopwatch_face(rdram, ctx);
        goto after_6;
    // 0x800A2B48: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_6:
    // 0x800A2B4C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2B50: nop

L_800A2B54:
    // 0x800A2B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A2B58:
    // 0x800A2B58: jal         0x80061D30
    // 0x800A2B5C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    obj_animate(rdram, ctx);
        goto after_7;
    // 0x800A2B5C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A2B60: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2B64: nop

L_800A2B68:
    // 0x800A2B68: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A2B6C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A2B70: addiu       $s2, $s2, 0x6CFC
    ctx->r18 = ADD32(ctx->r18, 0X6CFC);
    // 0x800A2B74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2B78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2B7C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2B80: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2B84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A2B88: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2B8C: jal         0x800AA600
    // 0x800A2B90: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A2B90: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    after_8:
    // 0x800A2B94: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2B98: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2B9C: lb          $v1, 0x193($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X193);
    // 0x800A2BA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A2BA4: bltz        $v1, L_800A2BD8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A2BA8: lui         $t8, 0x8000
        ctx->r24 = S32(0X8000 << 16);
            goto L_800A2BD8;
    }
    // 0x800A2BA8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A2BAC: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A2BB0: addu        $s0, $a1, $t5
    ctx->r16 = ADD32(ctx->r5, ctx->r13);
    // 0x800A2BB4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800A2BB8:
    // 0x800A2BB8: lw          $t6, 0x128($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X128);
    // 0x800A2BBC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A2BC0: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800A2BC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A2BC8: bne         $at, $zero, L_800A2BD8
    if (ctx->r1 != 0) {
        // 0x800A2BCC: addu        $t1, $t1, $t6
        ctx->r9 = ADD32(ctx->r9, ctx->r14);
            goto L_800A2BD8;
    }
    // 0x800A2BCC: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800A2BD0: bne         $t0, $v0, L_800A2BB8
    if (ctx->r8 != ctx->r2) {
        // 0x800A2BD4: nop
    
            goto L_800A2BB8;
    }
    // 0x800A2BD4: nop

L_800A2BD8:
    // 0x800A2BD8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A2BDC: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A2BE0: bne         $t8, $zero, L_800A2C2C
    if (ctx->r24 != 0) {
        // 0x800A2BE4: nop
    
            goto L_800A2C2C;
    }
    // 0x800A2BE4: nop

    // 0x800A2BE8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800A2BEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A2BF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2BF4: lwc1        $f11, -0x78C8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X78C8);
    // 0x800A2BF8: lwc1        $f10, -0x78C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800A2BFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A2C00: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A2C04: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A2C08: nop

    // 0x800A2C0C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A2C10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2C14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2C18: nop

    // 0x800A2C1C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A2C20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A2C24: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800A2C28: nop

L_800A2C2C:
    // 0x800A2C2C: jal         0x8000C8B4
    // 0x800A2C30: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_9;
    // 0x800A2C30: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_9:
    // 0x800A2C34: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2C38: nop

    // 0x800A2C3C: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A2C40: beq         $at, $zero, L_800A2C58
    if (ctx->r1 == 0) {
        // 0x800A2C44: addiu       $s0, $zero, 0x444
        ctx->r16 = ADD32(0, 0X444);
            goto L_800A2C58;
    }
    // 0x800A2C44: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
    // 0x800A2C48: jal         0x8000C8B4
    // 0x800A2C4C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x800A2C4C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_10:
    // 0x800A2C50: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A2C54: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
L_800A2C58:
    // 0x800A2C58: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2C5C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A2C60: mflo        $t9
    ctx->r25 = lo;
    // 0x800A2C64: addiu       $t4, $t9, 0x7FF8
    ctx->r12 = ADD32(ctx->r25, 0X7FF8);
    // 0x800A2C68: sh          $t4, 0x444($t2)
    MEM_H(0X444, ctx->r10) = ctx->r12;
    // 0x800A2C6C: jal         0x8000E0B0
    // 0x800A2C70: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_contpak_error(rdram, ctx);
        goto after_11;
    // 0x800A2C70: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_11:
    // 0x800A2C74: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2C78: bgtz        $v0, L_800A2CB0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A2C7C: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_800A2CB0;
    }
    // 0x800A2C7C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A2C80: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A2C84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2C88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2C8C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2C90: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2C94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A2C98: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2C9C: jal         0x800AA600
    // 0x800A2CA0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A2CA0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_12:
    // 0x800A2CA4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2CA8: nop

    // 0x800A2CAC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_800A2CB0:
    // 0x800A2CB0: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800A2CB4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800A2CB8: bne         $v1, $zero, L_800A2CC4
    if (ctx->r3 != 0) {
        // 0x800A2CBC: nop
    
            goto L_800A2CC4;
    }
    // 0x800A2CBC: nop

    // 0x800A2CC0: break       7
    do_break(2148150464);
L_800A2CC4:
    // 0x800A2CC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2CC8: bne         $v1, $at, L_800A2CDC
    if (ctx->r3 != ctx->r1) {
        // 0x800A2CCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A2CDC;
    }
    // 0x800A2CCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2CD0: bne         $t1, $at, L_800A2CDC
    if (ctx->r9 != ctx->r1) {
        // 0x800A2CD4: nop
    
            goto L_800A2CDC;
    }
    // 0x800A2CD4: nop

    // 0x800A2CD8: break       6
    do_break(2148150488);
L_800A2CDC:
    // 0x800A2CDC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A2CE0: addiu       $t5, $t3, 0x1E
    ctx->r13 = ADD32(ctx->r11, 0X1E);
    // 0x800A2CE4: nop

    // 0x800A2CE8: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x800A2CEC: bne         $v1, $zero, L_800A2CF8
    if (ctx->r3 != 0) {
        // 0x800A2CF0: nop
    
            goto L_800A2CF8;
    }
    // 0x800A2CF0: nop

    // 0x800A2CF4: break       7
    do_break(2148150516);
L_800A2CF8:
    // 0x800A2CF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2CFC: bne         $v1, $at, L_800A2D10
    if (ctx->r3 != ctx->r1) {
        // 0x800A2D00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A2D10;
    }
    // 0x800A2D00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2D04: bne         $t5, $at, L_800A2D10
    if (ctx->r13 != ctx->r1) {
        // 0x800A2D08: nop
    
            goto L_800A2D10;
    }
    // 0x800A2D08: nop

    // 0x800A2D0C: break       6
    do_break(2148150540);
L_800A2D10:
    // 0x800A2D10: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A2D14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2D18: mfhi        $t1
    ctx->r9 = hi;
    // 0x800A2D1C: nop

    // 0x800A2D20: nop

    // 0x800A2D24: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2D28: mflo        $t6
    ctx->r14 = lo;
    // 0x800A2D2C: sh          $t6, 0x444($t8)
    MEM_H(0X444, ctx->r24) = ctx->r14;
    // 0x800A2D30: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A2D34: nop

    // 0x800A2D38: lwc1        $f8, 0x350($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X350);
    // 0x800A2D3C: nop

    // 0x800A2D40: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A2D44: jal         0x8000E0B0
    // 0x800A2D48: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    get_contpak_error(rdram, ctx);
        goto after_13;
    // 0x800A2D48: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    after_13:
    // 0x800A2D4C: bgtz        $v0, L_800A2D78
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A2D50: lw          $t7, 0x98($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X98);
            goto L_800A2D78;
    }
    // 0x800A2D50: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800A2D54: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A2D58: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2D5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2D60: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2D64: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2D68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A2D6C: jal         0x800AA600
    // 0x800A2D70: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A2D70: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_14:
    // 0x800A2D74: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
L_800A2D78:
    // 0x800A2D78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2D7C: jal         0x80068508
    // 0x800A2D80: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A2D80: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    after_15:
    // 0x800A2D84: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2D88: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2D8C: jal         0x800A0EB4
    // 0x800A2D90: nop

    hud_course_arrows(rdram, ctx);
        goto after_16;
    // 0x800A2D90: nop

    after_16:
    // 0x800A2D94: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2D98: nop

    // 0x800A2D9C: lb          $t9, 0x1D8($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A2DA0: nop

    // 0x800A2DA4: bne         $t9, $zero, L_800A30D8
    if (ctx->r25 != 0) {
        // 0x800A2DA8: nop
    
            goto L_800A30D8;
    }
    // 0x800A2DA8: nop

    // 0x800A2DAC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A2DB0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800A2DB4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A2DB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2DBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2DC0: lwc1        $f6, 0x2F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X2F0);
    // 0x800A2DC4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A2DC8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A2DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A2DD0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A2DD4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A2DD8: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
    // 0x800A2DDC: lb          $t5, 0x194($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X194);
    // 0x800A2DE0: nop

    // 0x800A2DE4: blez        $t5, L_800A2F84
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A2DE8: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A2F84;
    }
    // 0x800A2DE8: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A2DEC: lw          $t6, 0x6D60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D60);
    // 0x800A2DF0: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x800A2DF4: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A2DF8: addu        $s0, $t1, $v0
    ctx->r16 = ADD32(ctx->r9, ctx->r2);
    // 0x800A2DFC: blez        $t8, L_800A2F80
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800A2E00: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800A2F80;
    }
    // 0x800A2E00: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800A2E04: addiu       $t7, $t7, 0x27AC
    ctx->r15 = ADD32(ctx->r15, 0X27AC);
    // 0x800A2E08: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x800A2E0C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_800A2E10:
    // 0x800A2E10: lw          $a0, 0x128($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X128);
    // 0x800A2E14: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800A2E18: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800A2E1C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800A2E20: jal         0x80059790
    // 0x800A2E24: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    get_timestamp_from_frames(rdram, ctx);
        goto after_17;
    // 0x800A2E24: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    after_17:
    // 0x800A2E28: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2E2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A2E30: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x800A2E34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A2E38: sw          $t2, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r10;
    // 0x800A2E3C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A2E40: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A2E44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2E48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2E4C: lwc1        $f10, 0x2EC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2EC);
    // 0x800A2E50: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800A2E54: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A2E58: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800A2E5C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A2E60: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x800A2E64: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x800A2E68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A2E6C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A2E70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    extern void dkr_hud_timer_select(uint8_t*, recomp_context*, int); dkr_hud_timer_select(rdram, ctx, 1);
    // 0x800A2E74: jal         0x800A7FBC
    // 0x800A2E78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_18;
    // 0x800A2E78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_18:
    // 0x800A2E7C: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x800A2E80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A2E84: sw          $t7, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r15;
    // 0x800A2E88: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A2E8C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800A2E90: addiu       $t4, $t9, 0xC
    ctx->r12 = ADD32(ctx->r25, 0XC);
    // 0x800A2E94: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A2E98: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800A2E9C: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
    // 0x800A2EA0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800A2EA4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A2EA8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A2EAC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A2EB0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A2EB4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800A2EB8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800A2EBC: sh          $t1, 0x338($t6)
    MEM_H(0X338, ctx->r14) = ctx->r9;
    // 0x800A2EC0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A2EC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2EC8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2ECC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2ED0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2ED4: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800A2ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A2EDC: jal         0x800AA600
    // 0x800A2EE0: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    hud_element_render(rdram, ctx);
        goto after_19;
    // 0x800A2EE0: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    after_19:
    // 0x800A2EE4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A2EE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2EEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2EF0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2EF4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2EF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A2EFC: jal         0x800AA600
    // 0x800A2F00: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A2F00: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    after_20:
    // 0x800A2F04: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A2F08: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A2F0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2F10: lwc1        $f6, 0x330($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A2F14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A2F18: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A2F1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A2F20: swc1        $f8, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f8.u32l;
    // 0x800A2F24: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A2F28: nop

    // 0x800A2F2C: lwc1        $f10, 0x310($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A2F30: nop

    // 0x800A2F34: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A2F38: swc1        $f4, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f4.u32l;
    // 0x800A2F3C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2F40: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2F44: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800A2F48: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A2F4C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A2F50: lb          $t4, 0x194($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X194);
    // 0x800A2F54: nop

    // 0x800A2F58: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A2F5C: beq         $at, $zero, L_800A2F84
    if (ctx->r1 == 0) {
        // 0x800A2F60: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A2F84;
    }
    // 0x800A2F60: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A2F64: lw          $t2, 0x6D60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D60);
    // 0x800A2F68: nop

    // 0x800A2F6C: lb          $t3, 0x4B($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X4B);
    // 0x800A2F70: nop

    // 0x800A2F74: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A2F78: bne         $at, $zero, L_800A2E10
    if (ctx->r1 != 0) {
        // 0x800A2F7C: nop
    
            goto L_800A2E10;
    }
    // 0x800A2F7C: nop

L_800A2F80:
    // 0x800A2F80: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
L_800A2F84:
    // 0x800A2F84: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800A2F88: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A2F8C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800A2F90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A2F94: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2F98: lwc1        $f8, 0x330($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A2F9C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2FA0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A2FA4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2FA8: swc1        $f10, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f10.u32l;
    // 0x800A2FAC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A2FB0: addiu       $s0, $s0, 0x6D4C
    ctx->r16 = ADD32(ctx->r16, 0X6D4C);
    // 0x800A2FB4: lwc1        $f4, 0x310($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A2FB8: nop

    // 0x800A2FBC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A2FC0: swc1        $f6, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f6.u32l;
    // 0x800A2FC4: lbu         $t6, 0x1EF($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A2FC8: nop

    // 0x800A2FCC: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x800A2FD0: beq         $t8, $zero, L_800A3014
    if (ctx->r24 == 0) {
        // 0x800A2FD4: nop
    
            goto L_800A3014;
    }
    // 0x800A2FD4: nop

    // 0x800A2FD8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A2FDC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800A2FE0: bgtz        $t7, L_800A3014
    if (SIGNED(ctx->r15) > 0) {
        // 0x800A2FE4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A3014;
    }
    // 0x800A2FE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A2FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A2FEC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A2FF0: jal         0x800A36CC
    // 0x800A2FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_21;
    // 0x800A2FF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_21:
    // 0x800A2FF8: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A2FFC: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x800A3000: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A3004: lbu         $t2, 0x1EF($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A3008: nop

    // 0x800A300C: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x800A3010: sb          $t3, 0x1EF($t1)
    MEM_B(0X1EF, ctx->r9) = ctx->r11;
L_800A3014:
    // 0x800A3014: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3018: addiu       $s0, $s0, 0x6D4C
    ctx->r16 = ADD32(ctx->r16, 0X6D4C);
    // 0x800A301C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A3020: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3024: blez        $v0, L_800A3040
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3028: subu        $t6, $v0, $t5
        ctx->r14 = SUB32(ctx->r2, ctx->r13);
            goto L_800A3040;
    }
    // 0x800A3028: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x800A302C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800A3030: bgez        $t6, L_800A3040
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A3034: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A3040;
    }
    // 0x800A3034: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A3038: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800A303C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3040:
    // 0x800A3040: bne         $v0, $zero, L_800A30D8
    if (ctx->r2 != 0) {
        // 0x800A3044: nop
    
            goto L_800A30D8;
    }
    // 0x800A3044: nop

    // 0x800A3048: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A304C: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x800A3050: bne         $t8, $zero, L_800A30D8
    if (ctx->r24 != 0) {
        // 0x800A3054: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A30D8;
    }
    // 0x800A3054: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3058: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800A305C: lw          $t9, 0x6D40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D40);
    // 0x800A3060: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3064: bne         $t9, $zero, L_800A30D8
    if (ctx->r25 != 0) {
        // 0x800A3068: addiu       $s0, $s0, 0x6D64
        ctx->r16 = ADD32(ctx->r16, 0X6D64);
            goto L_800A30D8;
    }
    // 0x800A3068: addiu       $s0, $s0, 0x6D64
    ctx->r16 = ADD32(ctx->r16, 0X6D64);
    // 0x800A306C: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A3070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3074: jal         0x8006F94C
    // 0x800A3078: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_22;
    // 0x800A3078: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_22:
    // 0x800A307C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A3080: addiu       $s1, $s1, 0x6D48
    ctx->r17 = ADD32(ctx->r17, 0X6D48);
    // 0x800A3084: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A3088: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A308C: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A3090: bne         $t2, $t3, L_800A30BC
    if (ctx->r10 != ctx->r11) {
        // 0x800A3094: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A30BC;
    }
    // 0x800A3094: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A3098:
    // 0x800A3098: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A309C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A30A0: jal         0x8006F94C
    // 0x800A30A4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_23;
    // 0x800A30A4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_23:
    // 0x800A30A8: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x800A30AC: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A30B0: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800A30B4: beq         $t4, $t5, L_800A3098
    if (ctx->r12 == ctx->r13) {
        // 0x800A30B8: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A3098;
    }
    // 0x800A30B8: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A30BC:
    // 0x800A30BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A30C0: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A30C4: jal         0x80001D04
    // 0x800A30C8: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_24;
    // 0x800A30C8: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_24:
    // 0x800A30CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A30D0: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A30D4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A30D8:
    // 0x800A30D8: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A30DC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A30E0: blez        $v1, L_800A31E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A30E4: addiu       $s1, $s1, 0x6D48
        ctx->r17 = ADD32(ctx->r17, 0X6D48);
            goto L_800A31E8;
    }
    // 0x800A30E4: addiu       $s1, $s1, 0x6D48
    ctx->r17 = ADD32(ctx->r17, 0X6D48);
    // 0x800A30E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A30EC: lw          $t8, 0x6D60($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D60);
    // 0x800A30F0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800A30F4: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x800A30F8: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800A30FC: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A3100: beq         $at, $zero, L_800A31E8
    if (ctx->r1 == 0) {
        // 0x800A3104: nop
    
            goto L_800A31E8;
    }
    // 0x800A3104: nop

    // 0x800A3108: lw          $t3, 0x128($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X128);
    // 0x800A310C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A3110: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A3114: beq         $at, $zero, L_800A31E8
    if (ctx->r1 == 0) {
        // 0x800A3118: nop
    
            goto L_800A31E8;
    }
    // 0x800A3118: nop

    // 0x800A311C: lw          $t4, 0x6D40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D40);
    // 0x800A3120: nop

    // 0x800A3124: bne         $t4, $zero, L_800A31E8
    if (ctx->r12 != 0) {
        // 0x800A3128: nop
    
            goto L_800A31E8;
    }
    // 0x800A3128: nop

    // 0x800A312C: lb          $t5, 0x1D6($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X1D6);
    // 0x800A3130: nop

    // 0x800A3134: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A3138: beq         $at, $zero, L_800A31E8
    if (ctx->r1 == 0) {
        // 0x800A313C: nop
    
            goto L_800A31E8;
    }
    // 0x800A313C: nop

    // 0x800A3140: jal         0x8006EA90
    // 0x800A3144: nop

    get_settings(rdram, ctx);
        goto after_25;
    // 0x800A3144: nop

    after_25:
    // 0x800A3148: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A314C: addiu       $s0, $s0, 0x7184
    ctx->r16 = ADD32(ctx->r16, 0X7184);
    // 0x800A3150: jal         0x8006BD88
    // 0x800A3154: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    level_id(rdram, ctx);
        goto after_26;
    // 0x800A3154: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_26:
    // 0x800A3158: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800A315C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3160: lb          $v1, 0x193($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X193);
    // 0x800A3164: lb          $t2, 0x1D6($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X1D6);
    // 0x800A3168: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A316C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A3170: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800A3174: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3178: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x800A317C: lw          $a0, 0x124($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X124);
    // 0x800A3180: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800A3184: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A3188: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800A318C: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x800A3190: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A3194: beq         $at, $zero, L_800A31E8
    if (ctx->r1 == 0) {
        // 0x800A3198: nop
    
            goto L_800A31E8;
    }
    // 0x800A3198: nop

    // 0x800A319C: blez        $a1, L_800A31D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800A31A0: or          $t1, $a0, $zero
        ctx->r9 = ctx->r4 | 0;
            goto L_800A31D4;
    }
    // 0x800A31A0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800A31A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A31A8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800A31AC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800A31B0:
    // 0x800A31B0: lw          $t9, 0x128($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X128);
    // 0x800A31B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A31B8: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A31BC: bne         $at, $zero, L_800A31CC
    if (ctx->r1 != 0) {
        // 0x800A31C0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800A31CC;
    }
    // 0x800A31C0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A31C4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A31C8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800A31CC:
    // 0x800A31CC: bne         $at, $zero, L_800A31B0
    if (ctx->r1 != 0) {
        // 0x800A31D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A31B0;
    }
    // 0x800A31D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A31D4:
    // 0x800A31D4: beq         $t1, $zero, L_800A31E8
    if (ctx->r9 == 0) {
        // 0x800A31D8: addiu       $a0, $zero, 0x144
        ctx->r4 = ADD32(0, 0X144);
            goto L_800A31E8;
    }
    // 0x800A31D8: addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    // 0x800A31DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A31E0: jal         0x80001D04
    // 0x800A31E4: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A31E4: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_27:
L_800A31E8:
    // 0x800A31E8: jal         0x8001B288
    // 0x800A31EC: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_28;
    // 0x800A31EC: nop

    after_28:
    // 0x800A31F0: beq         $v0, $zero, L_800A3330
    if (ctx->r2 == 0) {
        // 0x800A31F4: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3330;
    }
    // 0x800A31F4: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A31F8: jal         0x8001B2E0
    // 0x800A31FC: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_29;
    // 0x800A31FC: nop

    after_29:
    // 0x800A3200: beq         $v0, $zero, L_800A332C
    if (ctx->r2 == 0) {
        // 0x800A3204: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A332C;
    }
    // 0x800A3204: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3208: jal         0x8001139C
    // 0x800A320C: nop

    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A320C: nop

    after_30:
    // 0x800A3210: bne         $v0, $zero, L_800A3330
    if (ctx->r2 != 0) {
        // 0x800A3214: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3330;
    }
    // 0x800A3214: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3218: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x800A321C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3220: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A3224: nop

    // 0x800A3228: bne         $t4, $zero, L_800A3330
    if (ctx->r12 != 0) {
        // 0x800A322C: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3330;
    }
    // 0x800A322C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3230: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A3234: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800A3238: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800A323C: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800A3240: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3244: lwc1        $f10, 0x14($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800A3248: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A324C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800A3250: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3254: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3258: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A325C: nop

    // 0x800A3260: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3264: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A3268: jal         0x800C9AD0
    // 0x800A326C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_31;
    // 0x800A326C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_31:
    // 0x800A3270: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800A3274: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A3278: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A327C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800A3280: nop

    // 0x800A3284: bc1f        L_800A3308
    if (!c1cs) {
        // 0x800A3288: nop
    
            goto L_800A3308;
    }
    // 0x800A3288: nop

    // 0x800A328C: lw          $t8, 0x6D40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D40);
    // 0x800A3290: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3294: bne         $t8, $zero, L_800A3308
    if (ctx->r24 != 0) {
        // 0x800A3298: addiu       $s0, $s0, 0x6D50
        ctx->r16 = ADD32(ctx->r16, 0X6D50);
            goto L_800A3308;
    }
    // 0x800A3298: addiu       $s0, $s0, 0x6D50
    ctx->r16 = ADD32(ctx->r16, 0X6D50);
    // 0x800A329C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A32A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A32A4: bne         $t7, $zero, L_800A3308
    if (ctx->r15 != 0) {
        // 0x800A32A8: nop
    
            goto L_800A3308;
    }
    // 0x800A32A8: nop

    // 0x800A32AC: jal         0x8006F94C
    // 0x800A32B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_32;
    // 0x800A32B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x800A32B4: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A32B8: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A32BC: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800A32C0: bne         $t2, $t6, L_800A32E8
    if (ctx->r10 != ctx->r14) {
        // 0x800A32C4: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A32E8;
    }
    // 0x800A32C4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A32C8:
    // 0x800A32C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A32CC: jal         0x8006F94C
    // 0x800A32D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_33;
    // 0x800A32D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x800A32D4: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800A32D8: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A32DC: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A32E0: beq         $t9, $t3, L_800A32C8
    if (ctx->r25 == ctx->r11) {
        // 0x800A32E4: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A32C8;
    }
    // 0x800A32E4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A32E8:
    // 0x800A32E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A32EC: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A32F0: jal         0x80001D04
    // 0x800A32F4: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_34;
    // 0x800A32F4: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_34:
    // 0x800A32F8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800A32FC: jal         0x8006F94C
    // 0x800A3300: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    rand_range(rdram, ctx);
        goto after_35;
    // 0x800A3300: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_35:
    // 0x800A3304: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800A3308:
    // 0x800A3308: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A330C: addiu       $s0, $s0, 0x6D50
    ctx->r16 = ADD32(ctx->r16, 0X6D50);
    // 0x800A3310: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3314: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3318: nop

    // 0x800A331C: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x800A3320: bgez        $t8, L_800A332C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A3324: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800A332C;
    }
    // 0x800A3324: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A3328: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800A332C:
    // 0x800A332C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
L_800A3330:
    // 0x800A3330: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3334: lb          $v1, 0x193($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X193);
    // 0x800A3338: nop

    // 0x800A333C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800A3340: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x800A3344: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A3348: nop

    // 0x800A334C: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A3350: beq         $at, $zero, L_800A337C
    if (ctx->r1 == 0) {
        // 0x800A3354: nop
    
            goto L_800A337C;
    }
    // 0x800A3354: nop

    // 0x800A3358: beq         $v1, $zero, L_800A337C
    if (ctx->r3 == 0) {
        // 0x800A335C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800A337C;
    }
    // 0x800A335C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A3360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A3364: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A3368: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A336C: jal         0x800A36CC
    // 0x800A3370: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_36;
    // 0x800A3370: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x800A3374: b           L_800A33D0
    // 0x800A3378: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A33D0;
    // 0x800A3378: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A337C:
    // 0x800A337C: lb          $t5, 0x1D3($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D3);
    // 0x800A3380: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3384: blez        $t5, L_800A33A8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A3388: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_800A33A8;
    }
    // 0x800A3388: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A338C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A3390: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800A3394: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A3398: jal         0x800A36CC
    // 0x800A339C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_37;
    // 0x800A339C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_37:
    // 0x800A33A0: b           L_800A33D0
    // 0x800A33A4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A33D0;
    // 0x800A33A4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A33A8:
    // 0x800A33A8: lbu         $t7, 0x1FC($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A33AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A33B0: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x800A33B4: bne         $at, $zero, L_800A33CC
    if (ctx->r1 != 0) {
        // 0x800A33B8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A33CC;
    }
    // 0x800A33B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A33BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A33C0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A33C4: jal         0x800A36CC
    // 0x800A33C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_38;
    // 0x800A33C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
L_800A33CC:
    // 0x800A33CC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A33D0:
    // 0x800A33D0: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A33D4: jal         0x800A4F50
    // 0x800A33D8: nop

    hud_lap_count(rdram, ctx);
        goto after_39;
    // 0x800A33D8: nop

    after_39:
    // 0x800A33DC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A33E0: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A33E4: jal         0x800A7B68
    // 0x800A33E8: nop

    hud_race_time(rdram, ctx);
        goto after_40;
    // 0x800A33E8: nop

    after_40:
    // 0x800A33EC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A33F0: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A33F4: jal         0x800A4154
    // 0x800A33F8: nop

    hud_bananas(rdram, ctx);
        goto after_41;
    // 0x800A33F8: nop

    after_41:
    // 0x800A33FC: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3400: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3404: jal         0x800A5A64
    // 0x800A3408: nop

    hud_wrong_way(rdram, ctx);
        goto after_42;
    // 0x800A3408: nop

    after_42:
    // 0x800A340C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800A3410: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3414: jal         0x800A3CE4
    // 0x800A3418: nop

    hud_race_start(rdram, ctx);
        goto after_43;
    // 0x800A3418: nop

    after_43:
    // 0x800A341C: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3420: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3424: jal         0x800A3884
    // 0x800A3428: nop

    hud_speedometre(rdram, ctx);
        goto after_44;
    // 0x800A3428: nop

    after_44:
    // 0x800A342C: jal         0x8000E0B0
    // 0x800A3430: nop

    get_contpak_error(rdram, ctx);
        goto after_45;
    // 0x800A3430: nop

    after_45:
    // 0x800A3434: blez        $v0, L_800A36AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3438: nop
    
            goto L_800A36AC;
    }
    // 0x800A3438: nop

    // 0x800A343C: jal         0x8000E0B0
    // 0x800A3440: nop

    get_contpak_error(rdram, ctx);
        goto after_46;
    // 0x800A3440: nop

    after_46:
    // 0x800A3444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3448: beq         $v0, $at, L_800A346C
    if (ctx->r2 == ctx->r1) {
        // 0x800A344C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A346C;
    }
    // 0x800A344C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3450: beq         $v0, $at, L_800A3494
    if (ctx->r2 == ctx->r1) {
        // 0x800A3454: lui         $t3, 0x800F
        ctx->r11 = S32(0X800F << 16);
            goto L_800A3494;
    }
    // 0x800A3454: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800A3458: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A345C: beq         $v0, $at, L_800A34B8
    if (ctx->r2 == ctx->r1) {
        // 0x800A3460: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_800A34B8;
    }
    // 0x800A3460: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800A3464: b           L_800A34D8
    // 0x800A3468: nop

        goto L_800A34D8;
    // 0x800A3468: nop

L_800A346C:
    // 0x800A346C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A3470: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800A3474: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800A3478: addiu       $t2, $t2, -0x79C0
    ctx->r10 = ADD32(ctx->r10, -0X79C0);
    // 0x800A347C: addiu       $t6, $t6, -0x79B8
    ctx->r14 = ADD32(ctx->r14, -0X79B8);
    // 0x800A3480: addiu       $t9, $t9, -0x79B0
    ctx->r25 = ADD32(ctx->r25, -0X79B0);
    // 0x800A3484: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800A3488: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800A348C: b           L_800A34D8
    // 0x800A3490: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_800A34D8;
    // 0x800A3490: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_800A3494:
    // 0x800A3494: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800A3498: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800A349C: addiu       $t3, $t3, -0x79A8
    ctx->r11 = ADD32(ctx->r11, -0X79A8);
    // 0x800A34A0: addiu       $t4, $t4, -0x799C
    ctx->r12 = ADD32(ctx->r12, -0X799C);
    // 0x800A34A4: addiu       $t5, $t5, -0x7998
    ctx->r13 = ADD32(ctx->r13, -0X7998);
    // 0x800A34A8: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800A34AC: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800A34B0: b           L_800A34D8
    // 0x800A34B4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
        goto L_800A34D8;
    // 0x800A34B4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_800A34B8:
    // 0x800A34B8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800A34BC: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A34C0: addiu       $t8, $t8, -0x7990
    ctx->r24 = ADD32(ctx->r24, -0X7990);
    // 0x800A34C4: addiu       $t7, $t7, -0x7984
    ctx->r15 = ADD32(ctx->r15, -0X7984);
    // 0x800A34C8: addiu       $t2, $t2, -0x7980
    ctx->r10 = ADD32(ctx->r10, -0X7980);
    // 0x800A34CC: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800A34D0: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800A34D4: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_800A34D8:
    // 0x800A34D8: jal         0x800C4164
    // 0x800A34DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_47;
    // 0x800A34DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_47:
    // 0x800A34E0: jal         0x800C42EC
    // 0x800A34E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_48;
    // 0x800A34E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_48:
    // 0x800A34E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A34EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A34F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A34F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A34F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A34FC: jal         0x800C4384
    // 0x800A3500: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_49;
    // 0x800A3500: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_49:
    // 0x800A3504: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3508: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A350C: addiu       $s1, $s1, 0x6D24
    ctx->r17 = ADD32(ctx->r17, 0X6D24);
    // 0x800A3510: addiu       $s0, $s0, 0x718C
    ctx->r16 = ADD32(ctx->r16, 0X718C);
    // 0x800A3514: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3518: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A351C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3520: lw          $t5, 0x6D28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D28);
    // 0x800A3524: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3528: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A352C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3530: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3534: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A3538: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800A353C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3540: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3544: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3548: jal         0x800C4440
    // 0x800A354C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_50;
    // 0x800A354C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_50:
    // 0x800A3550: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3554: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3558: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A355C: lw          $t9, 0x6D28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D28);
    // 0x800A3560: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3564: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A3568: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A356C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3570: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3574: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x800A3578: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A357C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3580: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3584: jal         0x800C4440
    // 0x800A3588: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    draw_text(rdram, ctx);
        goto after_51;
    // 0x800A3588: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    after_51:
    // 0x800A358C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3590: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3594: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3598: lw          $t7, 0x6D28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D28);
    // 0x800A359C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A35A0: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A35A4: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A35A8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A35AC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A35B0: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    // 0x800A35B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A35B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A35BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A35C0: jal         0x800C4440
    // 0x800A35C4: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    draw_text(rdram, ctx);
        goto after_52;
    // 0x800A35C4: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    after_52:
    // 0x800A35C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A35CC: lw          $v0, 0x7194($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7194);
    // 0x800A35D0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800A35D4: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800A35D8: lbu         $a0, 0x10($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X10);
    // 0x800A35DC: lbu         $a1, 0x11($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X11);
    // 0x800A35E0: lbu         $a2, 0x12($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X12);
    // 0x800A35E4: jal         0x800C4384
    // 0x800A35E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_text_colour(rdram, ctx);
        goto after_53;
    // 0x800A35E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_53:
    // 0x800A35EC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A35F0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A35F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A35F8: lw          $t5, 0x6D28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D28);
    // 0x800A35FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3600: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A3604: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3608: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A360C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3610: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3614: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3618: jal         0x800C4440
    // 0x800A361C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    draw_text(rdram, ctx);
        goto after_54;
    // 0x800A361C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_54:
    // 0x800A3620: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3624: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3628: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A362C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3630: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A3634: lw          $t9, 0x6D28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D28);
    // 0x800A3638: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A363C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3640: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A3644: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3648: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A364C: addiu       $a2, $a2, 0xE
    ctx->r6 = ADD32(ctx->r6, 0XE);
    // 0x800A3650: jal         0x800C4440
    // 0x800A3654: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    draw_text(rdram, ctx);
        goto after_55;
    // 0x800A3654: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_55:
    // 0x800A3658: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A365C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3660: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3664: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3668: lw          $a2, 0x7190($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7190);
    // 0x800A366C: lw          $t7, 0x6D28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D28);
    // 0x800A3670: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A3674: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A3678: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A367C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3680: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3684: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x800A3688: jal         0x800C4440
    // 0x800A368C: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    draw_text(rdram, ctx);
        goto after_56;
    // 0x800A368C: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    after_56:
    // 0x800A3690: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3694: lw          $a0, 0x7194($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7194);
    // 0x800A3698: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A369C: jal         0x8007F24C
    // 0x800A36A0: nop

    update_colour_cycle(rdram, ctx);
        goto after_57;
    // 0x800A36A0: nop

    after_57:
    // 0x800A36A4: jal         0x800C4164
    // 0x800A36A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_58;
    // 0x800A36A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_58:
L_800A36AC:
    // 0x800A36AC: jal         0x80068508
    // 0x800A36B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_59;
    // 0x800A36B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
L_800A36B4:
    // 0x800A36B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A36B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A36BC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A36C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A36C4: jr          $ra
    // 0x800A36C8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800A36C8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8006F20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F20C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F210: lh          $t6, -0x2C6C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2C6C);
    // 0x8006F214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F218: bne         $t6, $zero, L_8006F244
    if (ctx->r14 != 0) {
        // 0x8006F21C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F244;
    }
    // 0x8006F21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F220: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F224: jal         0x800C01D8
    // 0x8006F228: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F228: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    after_0:
    // 0x8006F22C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F230: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F234: sh          $t7, -0x2C6C($at)
    MEM_H(-0X2C6C, ctx->r1) = ctx->r15;
    // 0x8006F238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F23C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006F240: sb          $t8, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = ctx->r24;
L_8006F244:
    // 0x8006F244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F24C: jr          $ra
    // 0x8006F250: nop

    return;
    // 0x8006F250: nop

;}
RECOMP_FUNC void try_free_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C844: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C848: addiu       $a2, $a2, -0x51B4
    ctx->r6 = ADD32(ctx->r6, -0X51B4);
    // 0x8000C84C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C858: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C85C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C860: nop

    // 0x8000C864: beq         $v1, $zero, L_8000C8A4
    if (ctx->r3 == 0) {
        // 0x8000C868: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8000C8A4;
    }
    // 0x8000C868: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8000C86C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8000C870: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8000C874: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000C878: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8000C87C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8000C880: nop

    // 0x8000C884: bne         $t0, $zero, L_8000C8A8
    if (ctx->r8 != 0) {
        // 0x8000C888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000C8A8;
    }
    // 0x8000C888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C88C: lw          $t1, -0x51B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X51B8);
    // 0x8000C890: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8000C894: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000C898: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8000C89C: jal         0x80071140
    // 0x8000C8A0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000C8A0: nop

    after_0:
L_8000C8A4:
    // 0x8000C8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C8A8:
    // 0x8000C8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C8AC: jr          $ra
    // 0x8000C8B0: nop

    return;
    // 0x8000C8B0: nop

;}
RECOMP_FUNC void obj_spawn_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FC44: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003FC48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003FC4C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003FC50: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8003FC54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FC58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FC5C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003FC60: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8003FC64: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003FC68: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003FC6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003FC70: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003FC74: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003FC78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003FC7C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8003FC80: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8003FC84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FC88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FC8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8003FC90: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003FC94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003FC98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8003FC9C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8003FCA0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8003FCA4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003FCA8: addiu       $t2, $t1, 0x24
    ctx->r10 = ADD32(ctx->r9, 0X24);
    // 0x8003FCAC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003FCB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FCB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FCB8: sh          $t2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r10;
    // 0x8003FCBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003FCC0: sb          $t5, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r13;
    // 0x8003FCC4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8003FCC8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003FCCC: sb          $a3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r7;
    // 0x8003FCD0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003FCD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003FCD8: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x8003FCDC: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
    // 0x8003FCE0: jal         0x8000EA54
    // 0x8003FCE4: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8003FCE4: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    after_0:
    // 0x8003FCE8: beq         $v0, $zero, L_8003FD30
    if (ctx->r2 == 0) {
        // 0x8003FCEC: lui         $at, 0x400C
        ctx->r1 = S32(0X400C << 16);
            goto L_8003FD30;
    }
    // 0x8003FCEC: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x8003FCF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003FCF4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003FCF8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003FCFC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003FD00: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003FD04: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003FD08: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003FD0C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD10: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD14: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD18: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003FD1C: nop

    // 0x8003FD20: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003FD24: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8003FD28: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8003FD2C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_8003FD30:
    // 0x8003FD30: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8003FD34: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8003FD38: beq         $v0, $zero, L_8003FD58
    if (ctx->r2 == 0) {
        // 0x8003FD3C: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_8003FD58;
    }
    // 0x8003FD3C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8003FD40: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003FD44: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003FD48: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003FD4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FD50: jal         0x80009558
    // 0x8003FD54: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8003FD54: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
L_8003FD58:
    // 0x8003FD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FD5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003FD60: jr          $ra
    // 0x8003FD64: nop

    return;
    // 0x8003FD64: nop

;}
RECOMP_FUNC void write_time_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007414C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074150: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80074154: jal         0x80073C54
    // 0x80074158: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_time_data_file_size(rdram, ctx);
        goto after_0;
    // 0x80074158: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007415C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80074160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074164: jal         0x80070C9C
    // 0x80074168: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80074168: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x8007416C: lui         $t6, 0x5449
    ctx->r14 = S32(0X5449 << 16);
    // 0x80074170: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80074174: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x80074178: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007417C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80074180: jal         0x800738A4
    // 0x80074184: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800738A4(rdram, ctx);
        goto after_2;
    // 0x80074184: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80074188: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007418C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80074190: jal         0x80073C5C
    // 0x80074194: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x80074194: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80074198: bne         $v0, $zero, L_800741CC
    if (ctx->r2 != 0) {
        // 0x8007419C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800741CC;
    }
    // 0x8007419C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800741A0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800741A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800741A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800741AC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800741B0: addiu       $a2, $a2, 0x76A0
    ctx->r6 = ADD32(ctx->r6, 0X76A0);
    // 0x800741B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800741B8: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x800741BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800741C0: jal         0x800766D4
    // 0x800741C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x800741C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x800741C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800741CC:
    // 0x800741CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800741D0: jal         0x80071140
    // 0x800741D4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800741D4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x800741D8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800741DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800741E0: beq         $v1, $zero, L_800741FC
    if (ctx->r3 == 0) {
        // 0x800741E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800741FC;
    }
    // 0x800741E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800741E8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800741EC: nop

    // 0x800741F0: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x800741F4: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x800741F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800741FC:
    // 0x800741FC: jr          $ra
    // 0x80074200: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80074200: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_pause_lockout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F38C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006F390: jr          $ra
    // 0x8006F394: sb          $a0, -0x2C68($at)
    MEM_B(-0X2C68, ctx->r1) = ctx->r4;
    return;
    // 0x8006F394: sb          $a0, -0x2C68($at)
    MEM_B(-0X2C68, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_unknown94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042154: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80042158: jr          $ra
    // 0x8004215C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8004215C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D80C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8001D810: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001D814: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001D818: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001D81C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001D820: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001D824: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001D828: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001D82C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001D830: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001D834: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D838: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8001D83C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8001D840: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8001D844: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x8001D848: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D84C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8001D850: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D854: beq         $v0, $zero, L_8001DD24
    if (ctx->r2 == 0) {
        // 0x8001D858: or          $s7, $a1, $zero
        ctx->r23 = ctx->r5 | 0;
            goto L_8001DD24;
    }
    // 0x8001D858: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8001D85C: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x8001D860: lw          $fp, 0x44($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X44);
    // 0x8001D864: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8001D868: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x8001D86C: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x8001D870: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D874: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D878: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D87C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D880: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D884: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8001D888: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D88C: nop

    // 0x8001D890: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8001D894: nop

    // 0x8001D898: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D89C: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8A0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8001D8A4: nop

    // 0x8001D8A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D8AC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8001D8B0: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D8B4: nop

    // 0x8001D8B8: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x8001D8BC: nop

    // 0x8001D8C0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8C4: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8C8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001D8CC: nop

    // 0x8001D8D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001D8D4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8001D8D8: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8001D8DC: nop

    // 0x8001D8E0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D8E4: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8001D8E8: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001D8EC: nop

    // 0x8001D8F0: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8F4: sh          $t6, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r14;
    // 0x8001D8F8: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8001D8FC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8001D900: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D904: sh          $t8, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r24;
    // 0x8001D908: jal         0x800703D8
    // 0x8001D90C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    vec3f_rotate_ypr(rdram, ctx);
        goto after_0;
    // 0x8001D90C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_0:
    // 0x8001D910: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D914: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D918: lbu         $t6, 0x3D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3D);
    // 0x8001D91C: nop

    // 0x8001D920: beq         $t6, $zero, L_8001D950
    if (ctx->r14 == 0) {
        // 0x8001D924: nop
    
            goto L_8001D950;
    }
    // 0x8001D924: nop

    // 0x8001D928: beq         $s2, $zero, L_8001D950
    if (ctx->r18 == 0) {
        // 0x8001D92C: nop
    
            goto L_8001D950;
    }
    // 0x8001D92C: nop

    // 0x8001D930: jal         0x80069DA4
    // 0x8001D934: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x8001D934: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D938: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001D93C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D940: jal         0x8006F6EC
    // 0x8001D944: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001D944: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8001D948: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D94C: nop

L_8001D950:
    // 0x8001D950: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001D954: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001D958: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D95C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001D960: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001D964: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001D968: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D96C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D970: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001D974: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001D978: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
    // 0x8001D97C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001D980: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001D984: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8001D988: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D98C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D990: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D994: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D998: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D99C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8001D9A0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001D9A4: lbu         $s6, 0x7($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X7);
    // 0x8001D9A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D9AC: mfc1        $s4, $f18
    ctx->r20 = (int32_t)ctx->f18.u32l;
    // 0x8001D9B0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D9B4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001D9B8: nop

    // 0x8001D9BC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001D9C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9C8: nop

    // 0x8001D9CC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001D9D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001D9D4: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8001D9D8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001D9DC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8001D9E0: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001D9E4: nop

    // 0x8001D9E8: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8001D9EC: nop

    // 0x8001D9F0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001D9F4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001D9F8: nop

    // 0x8001D9FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA00: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001DA04: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA08: nop

    // 0x8001DA0C: lh          $t8, 0x20($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X20);
    // 0x8001DA10: nop

    // 0x8001DA14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DA18: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001DA1C: nop

    // 0x8001DA20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001DA24: beq         $s2, $zero, L_8001DA4C
    if (ctx->r18 == 0) {
        // 0x8001DA28: swc1        $f8, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
            goto L_8001DA4C;
    }
    // 0x8001DA28: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8001DA2C: jal         0x80069DA4
    // 0x8001DA30: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_3;
    // 0x8001DA30: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_3:
    // 0x8001DA34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001DA38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA3C: jal         0x8006F6EC
    // 0x8001DA40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_4;
    // 0x8001DA40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8001DA44: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DA48: nop

L_8001DA4C:
    // 0x8001DA4C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8001DA50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA54: jal         0x800703D8
    // 0x8001DA58: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    vec3f_rotate_ypr(rdram, ctx);
        goto after_5;
    // 0x8001DA58: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_5:
    // 0x8001DA5C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DA60: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001DA64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001DA68: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DA6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DA70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DA74: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001DA78: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001DA7C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001DA80: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001DA84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DA88: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA8C: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8001DA90: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001DA94: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001DA98: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001DA9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DAA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAA4: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8001DAA8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DAAC: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8001DAB0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001DAB4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8001DAB8: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DABC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001DAC0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8001DAC4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001DAC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAD0: nop

    // 0x8001DAD4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001DAD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001DADC: mfc1        $ra, $f8
    ctx->r31 = (int32_t)ctx->f8.u32l;
    // 0x8001DAE0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DAE4: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001DAE8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8001DAEC: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DAF0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001DAF4: nop

    // 0x8001DAF8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001DAFC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001DB00: nop

    // 0x8001DB04: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001DB08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB10: nop

    // 0x8001DB14: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001DB18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001DB1C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001DB20: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001DB24: nop

    // 0x8001DB28: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DB2C: nop

    // 0x8001DB30: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001DB34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DB38: nop

    // 0x8001DB3C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DB40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB48: nop

    // 0x8001DB4C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DB50: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8001DB54: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DB58: blez        $v1, L_8001DD24
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DB5C: nop
    
            goto L_8001DD24;
    }
    // 0x8001DB5C: nop

    // 0x8001DB60: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DB64: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8001DB68:
    // 0x8001DB68: lh          $t3, 0x9A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X9A);
    // 0x8001DB6C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001DB70: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8001DB74: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8001DB78: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8001DB7C: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DB80: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x8001DB84: nop

    // 0x8001DB88: beq         $t8, $at, L_8001DCD8
    if (ctx->r24 == ctx->r1) {
        // 0x8001DB8C: nop
    
            goto L_8001DCD8;
    }
    // 0x8001DB8C: nop

    // 0x8001DB90: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001DB94: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DB98: nop

    // 0x8001DB9C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001DBA0: beq         $at, $zero, L_8001DD08
    if (ctx->r1 == 0) {
        // 0x8001DBA4: lh          $v0, 0x9A($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X9A);
            goto L_8001DD08;
    }
    // 0x8001DBA4: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DBA8:
    // 0x8001DBA8: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBAC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8001DBB0: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DBB4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DBB8: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x8001DBBC: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x8001DBC0: multu       $a2, $s5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBC4: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8001DBC8: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DBCC: nop

    // 0x8001DBD0: nop

    // 0x8001DBD4: multu       $a3, $s3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBD8: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DBDC: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DBE0: nop

    // 0x8001DBE4: multu       $t0, $s4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DBEC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DBF0: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x8001DBF4: blez        $t8, L_8001DC1C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001DBF8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001DC1C;
    }
    // 0x8001DBF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DBFC: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC00: mflo        $a0
    ctx->r4 = lo;
    // 0x8001DC04: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DC08: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x8001DC0C: bne         $at, $zero, L_8001DC1C
    if (ctx->r1 != 0) {
        // 0x8001DC10: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_8001DC1C;
    }
    // 0x8001DC10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001DC14: b           L_8001DC1C
    // 0x8001DC18: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_8001DC1C;
    // 0x8001DC18: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8001DC1C:
    // 0x8001DC1C: multu       $a2, $ra
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC20: mflo        $t6
    ctx->r14 = lo;
    // 0x8001DC24: nop

    // 0x8001DC28: nop

    // 0x8001DC2C: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC30: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DC34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DC38: nop

    // 0x8001DC3C: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC40: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DC44: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DC48: sra         $t6, $v1, 13
    ctx->r14 = S32(SIGNED(ctx->r3) >> 13);
    // 0x8001DC4C: blez        $t6, L_8001DC78
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001DC50: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_8001DC78;
    }
    // 0x8001DC50: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8001DC54: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC58: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DC5C: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001DC60: addu        $v1, $t7, $t2
    ctx->r3 = ADD32(ctx->r15, ctx->r10);
    // 0x8001DC64: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8001DC68: bne         $at, $zero, L_8001DC78
    if (ctx->r1 != 0) {
        // 0x8001DC6C: nop
    
            goto L_8001DC78;
    }
    // 0x8001DC6C: nop

    // 0x8001DC70: b           L_8001DC78
    // 0x8001DC74: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_8001DC78;
    // 0x8001DC74: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001DC78:
    // 0x8001DC78: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC7C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001DC80: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8001DC84: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001DC88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001DC8C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8001DC90: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001DC94: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DC98: addu        $v0, $fp, $t8
    ctx->r2 = ADD32(ctx->r30, ctx->r24);
    // 0x8001DC9C: sb          $a0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r4;
    // 0x8001DCA0: sb          $a0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r4;
    // 0x8001DCA4: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x8001DCA8: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x8001DCAC: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DCB0: nop

    // 0x8001DCB4: addu        $t9, $a2, $t3
    ctx->r25 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DCB8: lh          $t6, 0xE($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XE);
    // 0x8001DCBC: nop

    // 0x8001DCC0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001DCC4: bne         $at, $zero, L_8001DBA8
    if (ctx->r1 != 0) {
        // 0x8001DCC8: nop
    
            goto L_8001DBA8;
    }
    // 0x8001DCC8: nop

    // 0x8001DCCC: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DCD0: b           L_8001DD08
    // 0x8001DCD4: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
        goto L_8001DD08;
    // 0x8001DCD4: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DCD8:
    // 0x8001DCD8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8001DCDC: nop

    // 0x8001DCE0: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001DCE4: beq         $t8, $zero, L_8001DD04
    if (ctx->r24 == 0) {
        // 0x8001DCE8: nop
    
            goto L_8001DD04;
    }
    // 0x8001DCE8: nop

    // 0x8001DCEC: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DCF0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001DCF4: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8001DCF8: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x8001DCFC: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001DD00: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
L_8001DD04:
    // 0x8001DD04: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DD08:
    // 0x8001DD08: nop

    // 0x8001DD0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DD10: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8001DD14: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DD18: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001DD1C: bne         $at, $zero, L_8001DB68
    if (ctx->r1 != 0) {
        // 0x8001DD20: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_8001DB68;
    }
    // 0x8001DD20: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
L_8001DD24:
    // 0x8001DD24: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DD28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DD2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DD30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DD34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD3C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DD40: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001DD44: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001DD48: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001DD4C: jr          $ra
    // 0x8001DD50: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001DD50: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void render_fill_rectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C5AAC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C5AB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C5AB4: jal         0x8007A520
    // 0x800C5AB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C5AB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C5ABC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C5AC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5AC4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C5AC8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C5ACC: bltz        $a3, L_800C5B48
    if (SIGNED(ctx->r7) < 0) {
        // 0x800C5AD0: andi        $t6, $v0, 0xFFFF
        ctx->r14 = ctx->r2 & 0XFFFF;
            goto L_800C5B48;
    }
    // 0x800C5AD0: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800C5AD4: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800C5AD8: beq         $at, $zero, L_800C5B4C
    if (ctx->r1 == 0) {
        // 0x800C5ADC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C5B4C;
    }
    // 0x800C5ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5AE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C5AE4: srl         $t7, $v0, 16
    ctx->r15 = S32(U32(ctx->r2) >> 16);
    // 0x800C5AE8: bltz        $a0, L_800C5B48
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C5AEC: sltu        $at, $a2, $t7
        ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
            goto L_800C5B48;
    }
    // 0x800C5AEC: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x800C5AF0: beq         $at, $zero, L_800C5B48
    if (ctx->r1 == 0) {
        // 0x800C5AF4: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_800C5B48;
    }
    // 0x800C5AF4: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800C5AF8: bgez        $a1, L_800C5B04
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C5AFC: sll         $t1, $t9, 14
        ctx->r9 = S32(ctx->r25 << 14);
            goto L_800C5B04;
    }
    // 0x800C5AFC: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x800C5B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C5B04:
    // 0x800C5B04: bgez        $a2, L_800C5B10
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C5B08: lui         $at, 0xF600
        ctx->r1 = S32(0XF600 << 16);
            goto L_800C5B10;
    }
    // 0x800C5B08: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C5B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C5B10:
    // 0x800C5B10: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800C5B14: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800C5B18: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C5B1C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800C5B20: andi        $t8, $a2, 0x3FF
    ctx->r24 = ctx->r6 & 0X3FF;
    // 0x800C5B24: andi        $t3, $a0, 0x3FF
    ctx->r11 = ctx->r4 & 0X3FF;
    // 0x800C5B28: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x800C5B2C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800C5B30: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C5B34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C5B38: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800C5B3C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800C5B40: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800C5B44: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_800C5B48:
    // 0x800C5B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C5B4C:
    // 0x800C5B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5B50: jr          $ra
    // 0x800C5B54: nop

    return;
    // 0x800C5B54: nop

;}
RECOMP_FUNC void waves_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9C18: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B9C1C: addiu       $t1, $t1, -0x5FE8
    ctx->r9 = ADD32(ctx->r9, -0X5FE8);
    // 0x800B9C20: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9C24: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B9C28: addiu       $t3, $t3, -0x6038
    ctx->r11 = ADD32(ctx->r11, -0X6038);
    // 0x800B9C2C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B9C30: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800B9C34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B9C38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B9C3C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800B9C40: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B9C44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B9C48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B9C4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9C50: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800B9C54: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B9C58: blez        $v0, L_800B9D48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B9C5C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800B9D48;
    }
    // 0x800B9C5C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800B9C60: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9C64: addiu       $a2, $a2, 0x3044
    ctx->r6 = ADD32(ctx->r6, 0X3044);
L_800B9C68:
    // 0x800B9C68: blez        $v0, L_800B9D38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B9C6C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800B9D38;
    }
    // 0x800B9C6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B9C70: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B9C74: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x800B9C78: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
L_800B9C7C:
    // 0x800B9C7C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800B9C80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9C84: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x800B9C88: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800B9C8C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800B9C90: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800B9C94: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x800B9C98: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800B9C9C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800B9CA0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9CA4: bne         $at, $zero, L_800B9CD0
    if (ctx->r1 != 0) {
        // 0x800B9CA8: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800B9CD0;
    }
    // 0x800B9CA8: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800B9CAC:
    // 0x800B9CAC: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x800B9CB0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B9CB4: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800B9CB8: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9CBC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800B9CC0: nop

    // 0x800B9CC4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9CC8: beq         $at, $zero, L_800B9CAC
    if (ctx->r1 == 0) {
        // 0x800B9CCC: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800B9CAC;
    }
    // 0x800B9CCC: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800B9CD0:
    // 0x800B9CD0: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800B9CD4: nop

    // 0x800B9CD8: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x800B9CDC: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x800B9CE0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B9CE4: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800B9CE8: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800B9CEC: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800B9CF0: nop

    // 0x800B9CF4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9CF8: bne         $at, $zero, L_800B9D24
    if (ctx->r1 != 0) {
        // 0x800B9CFC: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800B9D24;
    }
    // 0x800B9CFC: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800B9D00:
    // 0x800B9D00: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x800B9D04: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B9D08: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800B9D0C: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x800B9D10: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800B9D14: nop

    // 0x800B9D18: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9D1C: beq         $at, $zero, L_800B9D00
    if (ctx->r1 == 0) {
        // 0x800B9D20: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800B9D00;
    }
    // 0x800B9D20: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800B9D24:
    // 0x800B9D24: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800B9D28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B9D2C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9D30: bne         $at, $zero, L_800B9C7C
    if (ctx->r1 != 0) {
        // 0x800B9D34: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800B9C7C;
    }
    // 0x800B9D34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800B9D38:
    // 0x800B9D38: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800B9D3C: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B9D40: bne         $at, $zero, L_800B9C68
    if (ctx->r1 != 0) {
        // 0x800B9D44: nop
    
            goto L_800B9C68;
    }
    // 0x800B9D44: nop

L_800B9D48:
    // 0x800B9D48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B9D4C: lw          $a1, 0x30D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30D0);
    // 0x800B9D50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9D54: lhu         $t9, 0x14($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X14);
    // 0x800B9D58: addiu       $a0, $a0, -0x5F64
    ctx->r4 = ADD32(ctx->r4, -0X5F64);
    // 0x800B9D5C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9D60: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B9D64: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9D68: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800B9D6C: addiu       $a3, $a3, -0x5F70
    ctx->r7 = ADD32(ctx->r7, -0X5F70);
    // 0x800B9D70: addiu       $t0, $t0, 0x3048
    ctx->r8 = ADD32(ctx->r8, 0X3048);
    // 0x800B9D74: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800B9D78: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9D7C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9D80: bgez        $v0, L_800B9D90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B9D84: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800B9D90;
    }
    // 0x800B9D84: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B9D88: b           L_800B9DBC
    // 0x800B9D8C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800B9DBC;
    // 0x800B9D8C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800B9D90:
    // 0x800B9D90: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800B9D94: nop

    // 0x800B9D98: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B9D9C: bne         $at, $zero, L_800B9DBC
    if (ctx->r1 != 0) {
        // 0x800B9DA0: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800B9DBC;
    }
    // 0x800B9DA0: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800B9DA4:
    // 0x800B9DA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B9DA8: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800B9DAC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800B9DB0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B9DB4: beq         $at, $zero, L_800B9DA4
    if (ctx->r1 == 0) {
        // 0x800B9DB8: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800B9DA4;
    }
    // 0x800B9DB8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800B9DBC:
    // 0x800B9DBC: lw          $t8, 0x38($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X38);
    // 0x800B9DC0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9DC4: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9DC8: addiu       $t2, $t2, -0x5F7C
    ctx->r10 = ADD32(ctx->r10, -0X5F7C);
    // 0x800B9DCC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800B9DD0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B9DD4: lw          $t8, -0x5F6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F6C);
    // 0x800B9DD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B9DDC: addiu       $v0, $v0, -0x5F78
    ctx->r2 = ADD32(ctx->r2, -0X5F78);
    // 0x800B9DE0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800B9DE4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B9DE8: addiu       $a1, $a1, -0x5F74
    ctx->r5 = ADD32(ctx->r5, -0X5F74);
    // 0x800B9DEC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B9DF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B9DF4: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9DF8: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800B9DFC: lw          $t6, 0x3C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X3C);
    // 0x800B9E00: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800B9E04: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9E08: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B9E0C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800B9E10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B9E14: lw          $t6, -0x5F68($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F68);
    // 0x800B9E18: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9E1C: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800B9E20: and         $a2, $t7, $t6
    ctx->r6 = ctx->r15 & ctx->r14;
    // 0x800B9E24: bltz        $a0, L_800B9E90
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B9E28: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_800B9E90;
    }
    // 0x800B9E28: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800B9E2C:
    // 0x800B9E2C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800B9E30: bltz        $a0, L_800B9E74
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B9E34: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800B9E74;
    }
    // 0x800B9E34: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800B9E38: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_800B9E3C:
    // 0x800B9E3C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B9E40: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800B9E44: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800B9E48: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x800B9E4C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800B9E50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B9E54: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800B9E58: sh          $a2, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r6;
    // 0x800B9E5C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800B9E60: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B9E64: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B9E68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B9E6C: beq         $at, $zero, L_800B9E3C
    if (ctx->r1 == 0) {
        // 0x800B9E70: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_800B9E3C;
    }
    // 0x800B9E70: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_800B9E74:
    // 0x800B9E74: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800B9E78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B9E7C: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800B9E80: beq         $at, $zero, L_800B9E2C
    if (ctx->r1 == 0) {
        // 0x800B9E84: addu        $a2, $a2, $t7
        ctx->r6 = ADD32(ctx->r6, ctx->r15);
            goto L_800B9E2C;
    }
    // 0x800B9E84: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9E88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B9E8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B9E90:
    // 0x800B9E90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B9E94: lw          $t6, -0x5F88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F88);
    // 0x800B9E98: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9E9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B9EA0: beq         $t6, $at, L_800B9EB0
    if (ctx->r14 == ctx->r1) {
        // 0x800B9EA4: addiu       $t0, $t0, 0x3048
        ctx->r8 = ADD32(ctx->r8, 0X3048);
            goto L_800B9EB0;
    }
    // 0x800B9EA4: addiu       $t0, $t0, 0x3048
    ctx->r8 = ADD32(ctx->r8, 0X3048);
    // 0x800B9EA8: b           L_800B9EB4
    // 0x800B9EAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800B9EB4;
    // 0x800B9EAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800B9EB0:
    // 0x800B9EB0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800B9EB4:
    // 0x800B9EB4: addiu       $ra, $a0, 0x1
    ctx->r31 = ADD32(ctx->r4, 0X1);
    // 0x800B9EB8: blez        $a0, L_800BA138
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B9EBC: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_800BA138;
    }
    // 0x800B9EBC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800B9EC0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9EC4: addiu       $a2, $a2, 0x3080
    ctx->r6 = ADD32(ctx->r6, 0X3080);
L_800B9EC8:
    // 0x800B9EC8: blez        $a0, L_800BA11C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B9ECC: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BA11C;
    }
    // 0x800B9ECC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800B9ED0:
    // 0x800B9ED0: blez        $t2, L_800BA104
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B9ED4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BA104;
    }
    // 0x800B9ED4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B9ED8: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x800B9EDC: sll         $a0, $t5, 2
    ctx->r4 = S32(ctx->r13 << 2);
    // 0x800B9EE0: sll         $a1, $ra, 2
    ctx->r5 = S32(ctx->r31 << 2);
L_800B9EE4:
    // 0x800B9EE4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B9EE8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B9EEC: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800B9EF0: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800B9EF4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800B9EF8: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800B9EFC: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x800B9F00: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800B9F04: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B9F08: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9F0C: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800B9F10: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x800B9F14: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B9F18: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B9F1C: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800B9F20: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800B9F24: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B9F28: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800B9F2C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800B9F30: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B9F34: nop

    // 0x800B9F38: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800B9F3C: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x800B9F40: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B9F44: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B9F48: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9F4C: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800B9F50: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B9F54: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9F58: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800B9F5C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800B9F60: nop

    // 0x800B9F64: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800B9F68: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x800B9F6C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B9F70: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B9F74: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800B9F78: lh          $t6, 0x2($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X2);
    // 0x800B9F7C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800B9F80: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800B9F84: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800B9F88: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B9F8C: nop

    // 0x800B9F90: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800B9F94: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x800B9F98: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B9F9C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B9FA0: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800B9FA4: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800B9FA8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B9FAC: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800B9FB0: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800B9FB4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800B9FB8: nop

    // 0x800B9FBC: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800B9FC0: sh          $t6, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r14;
    // 0x800B9FC4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B9FC8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B9FCC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800B9FD0: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800B9FD4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800B9FD8: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9FDC: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800B9FE0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800B9FE4: nop

    // 0x800B9FE8: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800B9FEC: sh          $t6, 0xE($t9)
    MEM_H(0XE, ctx->r25) = ctx->r14;
    // 0x800B9FF0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B9FF4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800B9FF8: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800B9FFC: lh          $t6, 0x4($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X4);
    // 0x800BA000: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA004: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA008: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA00C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA010: nop

    // 0x800BA014: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA018: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800BA01C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA020: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA024: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA028: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800BA02C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA030: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA034: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA038: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA03C: nop

    // 0x800BA040: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA044: sh          $t6, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r14;
    // 0x800BA048: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA04C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA050: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA054: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800BA058: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA05C: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA060: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA064: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA068: nop

    // 0x800BA06C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA070: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x800BA074: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA078: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA07C: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA080: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800BA084: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA088: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA08C: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA090: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA094: nop

    // 0x800BA098: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA09C: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x800BA0A0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA0A4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA0A8: addu        $t8, $t9, $a1
    ctx->r24 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA0AC: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800BA0B0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA0B4: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA0B8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA0BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA0C0: nop

    // 0x800BA0C4: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA0C8: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
    // 0x800BA0CC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA0D0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA0D4: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA0D8: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800BA0DC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA0E0: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA0E4: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA0E8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA0EC: nop

    // 0x800BA0F0: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA0F4: bne         $a3, $t2, L_800B9EE4
    if (ctx->r7 != ctx->r10) {
        // 0x800BA0F8: sh          $t6, 0x1E($t9)
        MEM_H(0X1E, ctx->r25) = ctx->r14;
            goto L_800B9EE4;
    }
    // 0x800BA0F8: sh          $t6, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r14;
    // 0x800BA0FC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA100: nop

L_800BA104:
    // 0x800BA104: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BA108: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA10C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA110: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA114: bne         $at, $zero, L_800B9ED0
    if (ctx->r1 != 0) {
        // 0x800BA118: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800B9ED0;
    }
    // 0x800BA118: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800BA11C:
    // 0x800BA11C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA120: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA124: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA128: bne         $at, $zero, L_800B9EC8
    if (ctx->r1 != 0) {
        // 0x800BA12C: addiu       $ra, $ra, 0x1
        ctx->r31 = ADD32(ctx->r31, 0X1);
            goto L_800B9EC8;
    }
    // 0x800BA12C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA130: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800BA134: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800BA138:
    // 0x800BA138: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BA13C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BA140: addiu       $t8, $t8, 0x3090
    ctx->r24 = ADD32(ctx->r24, 0X3090);
    // 0x800BA144: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x800BA148: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA14C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BA150: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800BA154: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA158: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800BA15C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800BA160: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800BA164: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BA168: addu        $a2, $v1, $t2
    ctx->r6 = ADD32(ctx->r3, ctx->r10);
    // 0x800BA16C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800BA170: mflo        $a3
    ctx->r7 = lo;
    // 0x800BA174: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800BA178: addu        $a1, $v1, $t8
    ctx->r5 = ADD32(ctx->r3, ctx->r24);
    // 0x800BA17C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800BA180: nop

    // 0x800BA184: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x800BA188: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800BA18C: nop

    // 0x800BA190: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800BA194: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BA198: nop

    // 0x800BA19C: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x800BA1A0: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800BA1A4: nop

    // 0x800BA1A8: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800BA1AC: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800BA1B0: nop

    // 0x800BA1B4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x800BA1B8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x800BA1BC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800BA1C0: sh          $t6, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r14;
    // 0x800BA1C4: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800BA1C8: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800BA1CC: sh          $t9, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r25;
    // 0x800BA1D0: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x800BA1D4: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x800BA1D8: sh          $t8, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r24;
    // 0x800BA1DC: lh          $t9, 0x0($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X0);
    // 0x800BA1E0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BA1E4: sh          $t9, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r25;
    // 0x800BA1E8: lh          $t8, 0x2($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X2);
    // 0x800BA1EC: nop

    // 0x800BA1F0: sh          $t8, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r24;
    // 0x800BA1F4: lw          $t7, 0x3188($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3188);
    // 0x800BA1F8: nop

    // 0x800BA1FC: blez        $t7, L_800BA214
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BA200: nop
    
            goto L_800BA214;
    }
    // 0x800BA200: nop

    // 0x800BA204: jal         0x800BFE98
    // 0x800BA208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BFE98(rdram, ctx);
        goto after_0;
    // 0x800BA208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800BA20C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA210: addiu       $t3, $t3, -0x6038
    ctx->r11 = ADD32(ctx->r11, -0X6038);
L_800BA214:
    // 0x800BA214: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA218: addiu       $v1, $v1, -0x58D8
    ctx->r3 = ADD32(ctx->r3, -0X58D8);
    // 0x800BA21C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA220: nop

    // 0x800BA224: blez        $v0, L_800BA270
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA228: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800BA270;
    }
    // 0x800BA228: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA22C: beq         $at, $zero, L_800BA260
    if (ctx->r1 == 0) {
        // 0x800BA230: nop
    
            goto L_800BA260;
    }
    // 0x800BA230: nop

    // 0x800BA234: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BA238: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA23C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA240: lwc1        $f8, -0x58DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X58DC);
    // 0x800BA244: lwc1        $f16, 0x40($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X40);
    // 0x800BA248: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BA24C: subu        $t6, $v0, $s1
    ctx->r14 = SUB32(ctx->r2, ctx->r17);
    // 0x800BA250: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA254: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800BA258: b           L_800BA270
    // 0x800BA25C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
        goto L_800BA270;
    // 0x800BA25C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
L_800BA260:
    // 0x800BA260: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA264: lwc1        $f4, -0x58E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X58E0);
    // 0x800BA268: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800BA26C: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
L_800BA270:
    // 0x800BA270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BA274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA278: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA27C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BA280: jr          $ra
    // 0x800BA284: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BA284: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void waves_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B82B4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B82B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B82BC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B82C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B82C4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B82C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B82CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B82D0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B82D4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B82D8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B82DC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B82E0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B82E4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B82E8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B82EC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B82F0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B82F4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B82F8: sw          $a2, -0x5F88($at)
    MEM_W(-0X5F88, ctx->r1) = ctx->r6;
    // 0x800B82FC: jal         0x800B8134
    // 0x800B8300: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    waves_init_header(rdram, ctx);
        goto after_0;
    // 0x800B8300: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    extern void dkr_maximise_persistent_water_detail(uint8_t*, recomp_context*); dkr_maximise_persistent_water_detail(rdram, ctx);
    // 0x800B8304: jal         0x800B7EB4
    // 0x800B8308: nop

    waves_alloc(rdram, ctx);
        goto after_1;
    // 0x800B8308: nop

    after_1:
    // 0x800B830C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8310: jal         0x800BBDDC
    // 0x800B8314: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BBDDC(rdram, ctx);
        goto after_2;
    // 0x800B8314: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800B8318: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B831C: lw          $t6, -0x5F58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F58);
    // 0x800B8320: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8324: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B8328: addiu       $a1, $a1, -0x5F60
    ctx->r5 = ADD32(ctx->r5, -0X5F60);
    // 0x800B832C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8330: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8334: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B8338: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B833C: lw          $t7, -0x5F54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F54);
    // 0x800B8340: addiu       $s4, $s4, -0x6038
    ctx->r20 = ADD32(ctx->r20, -0X6038);
    // 0x800B8344: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8348: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B834C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B8350: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8354: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B8358: addiu       $a2, $a2, -0x5F5C
    ctx->r6 = ADD32(ctx->r6, -0X5F5C);
    // 0x800B835C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B8360: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800B8364: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B8368: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B836C: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800B8370: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B8374: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B8378: addiu       $s2, $s2, -0x5F44
    ctx->r18 = ADD32(ctx->r18, -0X5F44);
    // 0x800B837C: addiu       $s1, $s1, -0x5F48
    ctx->r17 = ADD32(ctx->r17, -0X5F48);
    // 0x800B8380: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8384: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B8388: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B838C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B8390: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x800B8394: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x800B8398: sw          $zero, -0x5F7C($at)
    MEM_W(-0X5F7C, ctx->r1) = 0;
    // 0x800B839C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B83A0: lw          $v1, -0x5F80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F80);
    // 0x800B83A4: sw          $zero, -0x5F78($at)
    MEM_W(-0X5F78, ctx->r1) = 0;
    // 0x800B83A8: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x800B83AC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B83B0: nop

    // 0x800B83B4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B83B8: mflo        $t2
    ctx->r10 = lo;
    // 0x800B83BC: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B83C0: nop

    // 0x800B83C4: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800B83C8: bne         $v0, $zero, L_800B83D4
    if (ctx->r2 != 0) {
        // 0x800B83CC: nop
    
            goto L_800B83D4;
    }
    // 0x800B83CC: nop

    // 0x800B83D0: break       7
    do_break(2148238288);
L_800B83D4:
    // 0x800B83D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B83D8: bne         $v0, $at, L_800B83EC
    if (ctx->r2 != ctx->r1) {
        // 0x800B83DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B83EC;
    }
    // 0x800B83DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B83E0: bne         $t3, $at, L_800B83EC
    if (ctx->r11 != ctx->r1) {
        // 0x800B83E4: nop
    
            goto L_800B83EC;
    }
    // 0x800B83E4: nop

    // 0x800B83E8: break       6
    do_break(2148238312);
L_800B83EC:
    // 0x800B83EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B83F0: mflo        $t4
    ctx->r12 = lo;
    // 0x800B83F4: sw          $t4, -0x5F74($at)
    MEM_W(-0X5F74, ctx->r1) = ctx->r12;
    // 0x800B83F8: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x800B83FC: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8400: nop

    // 0x800B8404: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8408: mflo        $t7
    ctx->r15 = lo;
    // 0x800B840C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800B8410: nop

    // 0x800B8414: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800B8418: bne         $v0, $zero, L_800B8424
    if (ctx->r2 != 0) {
        // 0x800B841C: nop
    
            goto L_800B8424;
    }
    // 0x800B841C: nop

    // 0x800B8420: break       7
    do_break(2148238368);
L_800B8424:
    // 0x800B8424: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8428: bne         $v0, $at, L_800B843C
    if (ctx->r2 != ctx->r1) {
        // 0x800B842C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B843C;
    }
    // 0x800B842C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8430: bne         $t8, $at, L_800B843C
    if (ctx->r24 != ctx->r1) {
        // 0x800B8434: nop
    
            goto L_800B843C;
    }
    // 0x800B8434: nop

    // 0x800B8438: break       6
    do_break(2148238392);
L_800B843C:
    // 0x800B843C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8440: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8444: sw          $t9, -0x5F70($at)
    MEM_W(-0X5F70, ctx->r1) = ctx->r25;
    // 0x800B8448: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800B844C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8450: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B8454: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800B8458: sw          $t4, -0x5F6C($at)
    MEM_W(-0X5F6C, ctx->r1) = ctx->r12;
    // 0x800B845C: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8460: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8464: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800B8468: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B846C: sw          $t7, -0x5F68($at)
    MEM_W(-0X5F68, ctx->r1) = ctx->r15;
    // 0x800B8470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8474: sw          $zero, -0x5F64($at)
    MEM_W(-0X5F64, ctx->r1) = 0;
    // 0x800B8478: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    // 0x800B847C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    // 0x800B8480: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B8484: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800B8488: lw          $t3, 0x14($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X14);
    // 0x800B848C: lw          $s6, 0x10($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X10);
    // 0x800B8490: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B8494: bne         $a0, $zero, L_800B84A0
    if (ctx->r4 != 0) {
        // 0x800B8498: nop
    
            goto L_800B84A0;
    }
    // 0x800B8498: nop

    // 0x800B849C: break       7
    do_break(2148238492);
L_800B84A0:
    // 0x800B84A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B84A4: bne         $a0, $at, L_800B84B8
    if (ctx->r4 != ctx->r1) {
        // 0x800B84A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B84B8;
    }
    // 0x800B84A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B84AC: bne         $t9, $at, L_800B84B8
    if (ctx->r25 != ctx->r1) {
        // 0x800B84B0: nop
    
            goto L_800B84B8;
    }
    // 0x800B84B0: nop

    // 0x800B84B4: break       6
    do_break(2148238516);
L_800B84B8:
    // 0x800B84B8: lw          $fp, 0x1C($s4)
    ctx->r30 = MEM_W(ctx->r20, 0X1C);
    // 0x800B84BC: mflo        $t2
    ctx->r10 = lo;
    // 0x800B84C0: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800B84C4: nop

    // 0x800B84C8: div         $zero, $t4, $a0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r4)));
    // 0x800B84CC: bne         $a0, $zero, L_800B84D8
    if (ctx->r4 != 0) {
        // 0x800B84D0: nop
    
            goto L_800B84D8;
    }
    // 0x800B84D0: nop

    // 0x800B84D4: break       7
    do_break(2148238548);
L_800B84D8:
    // 0x800B84D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B84DC: bne         $a0, $at, L_800B84F0
    if (ctx->r4 != ctx->r1) {
        // 0x800B84E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B84F0;
    }
    // 0x800B84E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B84E4: bne         $t4, $at, L_800B84F0
    if (ctx->r12 != ctx->r1) {
        // 0x800B84E8: nop
    
            goto L_800B84F0;
    }
    // 0x800B84E8: nop

    // 0x800B84EC: break       6
    do_break(2148238572);
L_800B84F0:
    // 0x800B84F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B84F4: lwc1        $f10, -0x6D60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6D60);
    // 0x800B84F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B84FC: swc1        $f10, -0x5FE4($at)
    MEM_W(-0X5FE4, ctx->r1) = ctx->f10.u32l;
    // 0x800B8500: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8504: lwc1        $f16, -0x6D5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6D5C);
    // 0x800B8508: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B850C: swc1        $f16, -0x5FE0($at)
    MEM_W(-0X5FE0, ctx->r1) = ctx->f16.u32l;
    // 0x800B8510: mflo        $t5
    ctx->r13 = lo;
    // 0x800B8514: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800B8518: blez        $a0, L_800B8618
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B851C: lui         $s5, 0x800E
        ctx->r21 = S32(0X800E << 16);
            goto L_800B8618;
    }
    // 0x800B851C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800B8520: addiu       $s5, $s5, 0x3040
    ctx->r21 = ADD32(ctx->r21, 0X3040);
    // 0x800B8524: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8528:
    // 0x800B8528: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B852C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8530: jal         0x800707C4
    // 0x800B8534: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800B8534: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800B8538: sll         $a0, $fp, 16
    ctx->r4 = S32(ctx->r30 << 16);
    // 0x800B853C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8540: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B8544: jal         0x800707C4
    // 0x800B8548: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x800B8548: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x800B854C: lwc1        $f18, 0x18($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B8550: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B8554: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B8558: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800B855C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B8560: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800B8564: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B8568: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B856C: addiu       $v1, $v1, -0x5FE4
    ctx->r3 = ADD32(ctx->r3, -0X5FE4);
    // 0x800B8570: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B8574: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800B8578: lw          $t2, 0x28($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X28);
    // 0x800B857C: nop

    // 0x800B8580: beq         $t2, $zero, L_800B85A4
    if (ctx->r10 == 0) {
        // 0x800B8584: nop
    
            goto L_800B85A4;
    }
    // 0x800B8584: nop

    // 0x800B8588: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800B858C: nop

    // 0x800B8590: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
    // 0x800B8594: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8598: nop

    // 0x800B859C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B85A0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800B85A4:
    // 0x800B85A4: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x800B85A8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B85AC: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800B85B0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B85B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B85B8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B85BC: nop

    // 0x800B85C0: bc1f        L_800B85D4
    if (!c1cs) {
        // 0x800B85C4: nop
    
            goto L_800B85D4;
    }
    // 0x800B85C4: nop

    // 0x800B85C8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800B85CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B85D0: nop

L_800B85D4:
    // 0x800B85D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B85D8: addiu       $v0, $v0, -0x5FE0
    ctx->r2 = ADD32(ctx->r2, -0X5FE0);
    // 0x800B85DC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B85E0: nop

    // 0x800B85E4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B85E8: nop

    // 0x800B85EC: bc1f        L_800B85F8
    if (!c1cs) {
        // 0x800B85F0: nop
    
            goto L_800B85F8;
    }
    // 0x800B85F0: nop

    // 0x800B85F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800B85F8:
    // 0x800B85F8: lw          $t7, 0x20($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X20);
    // 0x800B85FC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800B8600: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B8604: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B8608: addu        $s6, $s6, $t5
    ctx->r22 = ADD32(ctx->r22, ctx->r13);
    // 0x800B860C: bne         $at, $zero, L_800B8528
    if (ctx->r1 != 0) {
        // 0x800B8610: addu        $fp, $fp, $t6
        ctx->r30 = ADD32(ctx->r30, ctx->r14);
            goto L_800B8528;
    }
    // 0x800B8610: addu        $fp, $fp, $t6
    ctx->r30 = ADD32(ctx->r30, ctx->r14);
    // 0x800B8614: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8618:
    // 0x800B8618: jal         0x8006F918
    // 0x800B861C: nop

    save_rng_seed(rdram, ctx);
        goto after_5;
    // 0x800B861C: nop

    after_5:
    // 0x800B8620: lui         $a0, 0x5741
    ctx->r4 = S32(0X5741 << 16);
    // 0x800B8624: jal         0x8006F90C
    // 0x800B8628: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    set_rng_seed(rdram, ctx);
        goto after_6;
    // 0x800B8628: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    after_6:
    // 0x800B862C: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8630: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8634: blez        $v1, L_800B86B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8638: nop
    
            goto L_800B86B8;
    }
    // 0x800B8638: nop

    // 0x800B863C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800B8640: addiu       $fp, $fp, 0x3044
    ctx->r30 = ADD32(ctx->r30, 0X3044);
L_800B8644:
    // 0x800B8644: blez        $v1, L_800B86A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8648: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B86A0;
    }
    // 0x800B8648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B864C: sll         $s6, $s5, 2
    ctx->r22 = S32(ctx->r21 << 2);
L_800B8650:
    // 0x800B8650: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8658: jal         0x8006F94C
    // 0x800B865C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B865C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_7:
    // 0x800B8660: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B8664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8668: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x800B866C: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x800B8670: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8674: jal         0x8006F94C
    // 0x800B8678: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B8678: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_8:
    // 0x800B867C: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B8680: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8684: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x800B8688: sh          $v0, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r2;
    // 0x800B868C: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8690: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800B8694: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B8698: bne         $at, $zero, L_800B8650
    if (ctx->r1 != 0) {
        // 0x800B869C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B8650;
    }
    // 0x800B869C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B86A0:
    // 0x800B86A0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B86A4: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B86A8: bne         $at, $zero, L_800B8644
    if (ctx->r1 != 0) {
        // 0x800B86AC: nop
    
            goto L_800B8644;
    }
    // 0x800B86AC: nop

    // 0x800B86B0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B86B4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800B86B8:
    // 0x800B86B8: jal         0x8006F92C
    // 0x800B86BC: nop

    load_rng_seed(rdram, ctx);
        goto after_9;
    // 0x800B86BC: nop

    after_9:
    // 0x800B86C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B86C4: beq         $s3, $at, L_800B86D4
    if (ctx->r19 == ctx->r1) {
        // 0x800B86C8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B86D4;
    }
    // 0x800B86C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B86CC: b           L_800B86D8
    // 0x800B86D0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
        goto L_800B86D8;
    // 0x800B86D0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800B86D4:
    // 0x800B86D4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800B86D8:
    // 0x800B86D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B86DC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800B86E0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B86E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B86E8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800B86EC:
    // 0x800B86EC: bltz        $v0, L_800B8860
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B86F0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800B8860;
    }
    // 0x800B86F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800B86F4:
    // 0x800B86F4: bltz        $v0, L_800B884C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B86F8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B884C;
    }
    // 0x800B86F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B86FC:
    // 0x800B86FC: blez        $s3, L_800B883C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8700: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B883C;
    }
    // 0x800B8700: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8704: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x800B8708: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x800B870C: cvt.s.w     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800B8710: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B8714: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B8718: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B871C: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B8720: addiu       $v0, $v0, 0x3070
    ctx->r2 = ADD32(ctx->r2, 0X3070);
    // 0x800B8724: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B8728:
    // 0x800B8728: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B872C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8730: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800B8734: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8738: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B873C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B8740: add.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f18.d + ctx->f0.d;
    // 0x800B8744: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B8748: nop

    // 0x800B874C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B8750: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8754: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8758: nop

    // 0x800B875C: cvt.w.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_D(ctx->f6.d);
    // 0x800B8760: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800B8764: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B8768: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800B876C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800B8770: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8774: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800B8778: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800B877C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B8780: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x800B8784: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B8788: nop

    // 0x800B878C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B8790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8798: nop

    // 0x800B879C: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x800B87A0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B87A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B87A8: sh          $t9, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r25;
    // 0x800B87AC: lw          $t4, 0x4C($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4C);
    // 0x800B87B0: nop

    // 0x800B87B4: bne         $t4, $zero, L_800B87F0
    if (ctx->r12 != 0) {
        // 0x800B87B8: nop
    
            goto L_800B87F0;
    }
    // 0x800B87B8: nop

    // 0x800B87BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B87C0: nop

    // 0x800B87C4: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B87C8: sb          $a1, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r5;
    // 0x800B87CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B87D0: nop

    // 0x800B87D4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B87D8: sb          $a1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r5;
    // 0x800B87DC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B87E0: nop

    // 0x800B87E4: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B87E8: b           L_800B8820
    // 0x800B87EC: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
        goto L_800B8820;
    // 0x800B87EC: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
L_800B87F0:
    // 0x800B87F0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800B87F4: nop

    // 0x800B87F8: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800B87FC: sb          $zero, 0x6($t4)
    MEM_B(0X6, ctx->r12) = 0;
    // 0x800B8800: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8804: nop

    // 0x800B8808: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B880C: sb          $zero, 0x7($t5)
    MEM_B(0X7, ctx->r13) = 0;
    // 0x800B8810: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B8814: nop

    // 0x800B8818: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B881C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
L_800B8820:
    // 0x800B8820: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8824: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B8828: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B882C: bne         $a0, $s3, L_800B8728
    if (ctx->r4 != ctx->r19) {
        // 0x800B8830: sb          $a1, 0x9($t9)
        MEM_B(0X9, ctx->r25) = ctx->r5;
            goto L_800B8728;
    }
    // 0x800B8830: sb          $a1, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r5;
    // 0x800B8834: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8838: nop

L_800B883C:
    // 0x800B883C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8840: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B8844: beq         $at, $zero, L_800B86FC
    if (ctx->r1 == 0) {
        // 0x800B8848: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B86FC;
    }
    // 0x800B8848: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B884C:
    // 0x800B884C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8850: slt         $at, $v0, $s7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800B8854: beq         $at, $zero, L_800B86F4
    if (ctx->r1 == 0) {
        // 0x800B8858: nop
    
            goto L_800B86F4;
    }
    // 0x800B8858: nop

    // 0x800B885C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8860:
    // 0x800B8860: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    // 0x800B8864: bne         $at, $zero, L_800B86EC
    if (ctx->r1 != 0) {
        // 0x800B8868: nop
    
            goto L_800B86EC;
    }
    // 0x800B8868: nop

    // 0x800B886C: blez        $v0, L_800B8960
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8870: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800B8960;
    }
    // 0x800B8870: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8874: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800B8878:
    // 0x800B8878: blez        $v0, L_800B8950
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B887C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8950;
    }
    // 0x800B887C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8880:
    // 0x800B8880: blez        $s3, L_800B8940
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8884: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B8940;
    }
    // 0x800B8884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8888: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B888C: addiu       $v1, $v1, 0x3080
    ctx->r3 = ADD32(ctx->r3, 0X3080);
    // 0x800B8890: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x800B8894: sll         $v0, $s5, 4
    ctx->r2 = S32(ctx->r21 << 4);
L_800B8898:
    // 0x800B8898: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800B889C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B88A0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B88A4: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800B88A8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B88AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B88B0: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B88B4: sb          $s0, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r16;
    // 0x800B88B8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B88BC: lw          $t9, -0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X4);
    // 0x800B88C0: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B88C4: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800B88C8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800B88CC: sb          $t2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r10;
    // 0x800B88D0: lw          $t4, -0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X4);
    // 0x800B88D4: addiu       $s5, $s5, 0x0
    ctx->r21 = ADD32(ctx->r21, 0X0);
    // 0x800B88D8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800B88DC: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800B88E0: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x800B88E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B88E8: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B88EC: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    // 0x800B88F0: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x800B88F4: nop

    // 0x800B88F8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800B88FC: sb          $a1, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r5;
    // 0x800B8900: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800B8904: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x800B8908: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800B890C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B8910: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B8914: sb          $t4, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r12;
    // 0x800B8918: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B891C: lw          $t2, -0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, -0X4);
    // 0x800B8920: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B8924: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800B8928: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B892C: sb          $t9, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r25;
    // 0x800B8930: bne         $a0, $s3, L_800B8898
    if (ctx->r4 != ctx->r19) {
        // 0x800B8934: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800B8898;
    }
    // 0x800B8934: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800B8938: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B893C: nop

L_800B8940:
    // 0x800B8940: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8944: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8948: bne         $at, $zero, L_800B8880
    if (ctx->r1 != 0) {
        // 0x800B894C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_800B8880;
    }
    // 0x800B894C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_800B8950:
    // 0x800B8950: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8954: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8958: bne         $at, $zero, L_800B8878
    if (ctx->r1 != 0) {
        // 0x800B895C: nop
    
            goto L_800B8878;
    }
    // 0x800B895C: nop

L_800B8960:
    // 0x800B8960: jal         0x800BC6C8
    // 0x800B8964: nop

    func_800BC6C8(rdram, ctx);
        goto after_10;
    // 0x800B8964: nop

    after_10:
    // 0x800B8968: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B896C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8970: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800B8974: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8978: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800B897C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B8980: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B8984: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800B8988: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800B898C: addiu       $t1, $t1, 0x3078
    ctx->r9 = ADD32(ctx->r9, 0X3078);
    // 0x800B8990: addiu       $a3, $a3, 0x3070
    ctx->r7 = ADD32(ctx->r7, 0X3070);
    // 0x800B8994: addiu       $a0, $a0, -0x5FD8
    ctx->r4 = ADD32(ctx->r4, -0X5FD8);
    // 0x800B8998: mflo        $s5
    ctx->r21 = lo;
    // 0x800B899C: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B89A0: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B89A4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B89A8:
    // 0x800B89A8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800B89AC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B89B0: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800B89B4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x800B89B8: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x800B89BC: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x800B89C0: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x800B89C4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B89C8: lbu         $t7, 0x6($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X6);
    // 0x800B89CC: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // 0x800B89D0: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x800B89D4: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x800B89D8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800B89DC: sb          $t8, -0x21($a0)
    MEM_B(-0X21, ctx->r4) = ctx->r24;
    // 0x800B89E0: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x800B89E4: nop

    // 0x800B89E8: sb          $t2, -0x20($a0)
    MEM_B(-0X20, ctx->r4) = ctx->r10;
    // 0x800B89EC: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800B89F0: nop

    // 0x800B89F4: sb          $t9, -0x1F($a0)
    MEM_B(-0X1F, ctx->r4) = ctx->r25;
    // 0x800B89F8: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B89FC: sh          $zero, -0x1C($a0)
    MEM_H(-0X1C, ctx->r4) = 0;
    // 0x800B8A00: sh          $t3, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r11;
    // 0x800B8A04: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800B8A08: nop

    // 0x800B8A0C: sh          $t6, -0x1A($a0)
    MEM_H(-0X1A, ctx->r4) = ctx->r14;
    // 0x800B8A10: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8A14: nop

    // 0x800B8A18: sb          $t4, -0x18($a0)
    MEM_B(-0X18, ctx->r4) = ctx->r12;
    // 0x800B8A1C: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8A20: nop

    // 0x800B8A24: sb          $t5, -0x17($a0)
    MEM_B(-0X17, ctx->r4) = ctx->r13;
    // 0x800B8A28: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8A2C: nop

    // 0x800B8A30: sb          $t7, -0x16($a0)
    MEM_B(-0X16, ctx->r4) = ctx->r15;
    // 0x800B8A34: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8A38: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x800B8A3C: sb          $t8, -0x15($a0)
    MEM_B(-0X15, ctx->r4) = ctx->r24;
    // 0x800B8A40: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x800B8A44: sh          $zero, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = 0;
    // 0x800B8A48: sh          $t2, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r10;
    // 0x800B8A4C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B8A50: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x800B8A54: sh          $t9, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r25;
    // 0x800B8A58: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B8A5C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800B8A60: sb          $t3, -0xE($a0)
    MEM_B(-0XE, ctx->r4) = ctx->r11;
    // 0x800B8A64: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    // 0x800B8A68: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800B8A6C: sb          $t6, -0xD($a0)
    MEM_B(-0XD, ctx->r4) = ctx->r14;
    // 0x800B8A70: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x800B8A74: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x800B8A78: sb          $t4, -0xC($a0)
    MEM_B(-0XC, ctx->r4) = ctx->r12;
    // 0x800B8A7C: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x800B8A80: nop

    // 0x800B8A84: sb          $t5, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r13;
    // 0x800B8A88: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800B8A8C: sh          $zero, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = 0;
    // 0x800B8A90: sh          $t2, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r10;
    // 0x800B8A94: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B8A98: nop

    // 0x800B8A9C: sh          $t9, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r25;
    // 0x800B8AA0: lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8AA4: nop

    // 0x800B8AA8: sb          $t3, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r11;
    // 0x800B8AAC: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8AB0: nop

    // 0x800B8AB4: sb          $t6, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r14;
    // 0x800B8AB8: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8ABC: nop

    // 0x800B8AC0: sb          $t4, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r12;
    // 0x800B8AC4: lbu         $t5, 0x9($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8AC8: bne         $a3, $t1, L_800B89A8
    if (ctx->r7 != ctx->r9) {
        // 0x800B8ACC: sb          $t5, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r13;
            goto L_800B89A8;
    }
    // 0x800B8ACC: sb          $t5, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r13;
    // 0x800B8AD0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8AD4: jal         0x800BCC70
    // 0x800B8AD8: nop

    func_800BCC70(rdram, ctx);
        goto after_11;
    // 0x800B8AD8: nop

    after_11:
    // 0x800B8ADC: lw          $t7, 0x24($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X24);
    // 0x800B8AE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B8AE4: bne         $t7, $at, L_800B8B10
    if (ctx->r15 != ctx->r1) {
        // 0x800B8AE8: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_800B8B10;
    }
    // 0x800B8AE8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B8AEC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B8AF0: addiu       $t8, $t8, 0x30E8
    ctx->r24 = ADD32(ctx->r24, 0X30E8);
    // 0x800B8AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8AF8: sw          $t8, 0x30E0($at)
    MEM_W(0X30E0, ctx->r1) = ctx->r24;
    // 0x800B8AFC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B8B00: addiu       $t2, $t2, 0x30FC
    ctx->r10 = ADD32(ctx->r10, 0X30FC);
    // 0x800B8B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B08: b           L_800B8B34
    // 0x800B8B0C: sw          $t2, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r10;
        goto L_800B8B34;
    // 0x800B8B0C: sw          $t2, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r10;
L_800B8B10:
    // 0x800B8B10: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B8B14: sw          $t9, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r25;
    // 0x800B8B18: addiu       $t3, $t3, 0x3110
    ctx->r11 = ADD32(ctx->r11, 0X3110);
    // 0x800B8B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B20: sw          $t3, 0x30E0($at)
    MEM_W(0X30E0, ctx->r1) = ctx->r11;
    // 0x800B8B24: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B8B28: addiu       $t6, $t6, 0x3144
    ctx->r14 = ADD32(ctx->r14, 0X3144);
    // 0x800B8B2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B30: sw          $t6, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r14;
L_800B8B34:
    // 0x800B8B34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B38: sw          $zero, 0x3188($at)
    MEM_W(0X3188, ctx->r1) = 0;
    // 0x800B8B3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8B40: sw          $zero, -0x58D8($at)
    MEM_W(-0X58D8, ctx->r1) = 0;
    // 0x800B8B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8B48: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B8B4C: sw          $zero, 0x3198($at)
    MEM_W(0X3198, ctx->r1) = 0;
    // 0x800B8B50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8B54: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B8B58: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B8B5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B8B60: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B8B64: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B8B68: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8B6C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B8B70: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B8B74: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B8B78: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8B7C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B8B80: sw          $zero, -0x5FE8($at)
    MEM_W(-0X5FE8, ctx->r1) = 0;
    // 0x800B8B84: jr          $ra
    // 0x800B8B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B8B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_init_midichset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042014: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80042018: lhu         $t6, 0x8($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X8);
    // 0x8004201C: nop

    // 0x80042020: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80042024: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80042028: nop

    // 0x8004202C: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x80042030: lbu         $t8, 0xB($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XB);
    // 0x80042034: jr          $ra
    // 0x80042038: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    return;
    // 0x80042038: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void racer_sound_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_enter_vehicle_audio_scope(uint8_t*, recomp_context*); extern void dkr_netplay_presentation_random_begin(uint8_t*, recomp_context*); dkr_enter_vehicle_audio_scope(rdram, ctx); dkr_netplay_presentation_random_begin(rdram, ctx);
    // 0x800050D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800050D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800050D8: lbu         $t6, -0x3930($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3930);
    // 0x800050DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800050E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800050E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800050E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800050EC: beq         $t6, $zero, L_80005244
    if (ctx->r14 == 0) {
        // 0x800050F0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80005244;
    }
    // 0x800050F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800050F4: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x800050F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800050FC: addiu       $v0, $v0, -0x63C4
    ctx->r2 = ADD32(ctx->r2, -0X63C4);
    // 0x80005100: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005104: lw          $t9, 0x118($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X118);
    // 0x80005108: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000510C: addiu       $a1, $a1, -0x63C8
    ctx->r5 = ADD32(ctx->r5, -0X63C8);
    // 0x80005110: beq         $t9, $zero, L_80005244
    if (ctx->r25 == 0) {
        // 0x80005114: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_80005244;
    }
    // 0x80005114: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80005118: jal         0x8001139C
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80005120: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005124: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005128: beq         $v0, $zero, L_8000517C
    if (ctx->r2 == 0) {
        // 0x8000512C: addiu       $a1, $a1, -0x63C8
        ctx->r5 = ADD32(ctx->r5, -0X63C8);
            goto L_8000517C;
    }
    // 0x8000512C: addiu       $a1, $a1, -0x63C8
    ctx->r5 = ADD32(ctx->r5, -0X63C8);
    // 0x80005130: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005134: lw          $t1, -0x63C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X63C4);
    // 0x80005138: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000513C: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80005140: nop

    // 0x80005144: beq         $a0, $at, L_8000517C
    if (ctx->r4 == ctx->r1) {
        // 0x80005148: nop
    
            goto L_8000517C;
    }
    // 0x80005148: nop

    // 0x8000514C: jal         0x8006A528
    // 0x80005150: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x80005150: nop

    after_1:
    // 0x80005154: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80005158: lw          $t2, -0x63C4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X63C4);
    // 0x8000515C: nop

    // 0x80005160: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x80005164: jal         0x8006A554
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000516C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005170: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005174: addiu       $a1, $a1, -0x63C8
    ctx->r5 = ADD32(ctx->r5, -0X63C8);
    // 0x80005178: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8000517C:
    // 0x8000517C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80005180: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x80005184: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x80005188: nop

    // 0x8000518C: bne         $t3, $zero, L_800051B8
    if (ctx->r11 != 0) {
        // 0x80005190: nop
    
            goto L_800051B8;
    }
    // 0x80005190: nop

    // 0x80005194: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80005198: nop

    // 0x8000519C: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x800051A0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800051A4: nop

    // 0x800051A8: swc1        $f0, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f0.u32l;
    // 0x800051AC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800051B0: b           L_80005244
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
        goto L_80005244;
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
L_800051B8:
    // 0x800051B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800051BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800051C0: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x800051C4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800051C8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800051CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800051D0: swc1        $f6, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f6.u32l;
    // 0x800051D4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800051D8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800051DC: nop

    // 0x800051E0: swc1        $f8, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f8.u32l;
    // 0x800051E4: lw          $t8, -0x63C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X63C4);
    // 0x800051E8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800051EC: lb          $v1, 0x1D7($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X1D7);
    // 0x800051F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800051F4: beq         $v1, $at, L_8000520C
    if (ctx->r3 == ctx->r1) {
        // 0x800051F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000520C;
    }
    // 0x800051F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800051FC: beq         $v1, $at, L_80005220
    if (ctx->r3 == ctx->r1) {
        // 0x80005200: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80005220;
    }
    // 0x80005200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80005204: b           L_80005238
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
        goto L_80005238;
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8000520C:
    // 0x8000520C: jal         0x80005D08
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_hovercraft(rdram, ctx);
        goto after_3;
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80005214: b           L_80005248
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000521C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005220:
    // 0x80005220: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80005224: jal         0x800063EC
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_plane(rdram, ctx);
        goto after_4;
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8000522C: b           L_80005248
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005238:
    // 0x80005238: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8000523C: jal         0x80005254
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_car(rdram, ctx);
        goto after_5;
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80005244:
    // 0x80005244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005248:
    // 0x80005248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    extern void dkr_leave_vehicle_audio_scope(uint8_t*, recomp_context*); extern void dkr_netplay_presentation_random_end(uint8_t*, recomp_context*); dkr_netplay_presentation_random_end(rdram, ctx); dkr_leave_vehicle_audio_scope(rdram, ctx);
    // 0x8000524C: jr          $ra
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F940: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006F944: jr          $ra
    // 0x8006F948: lw          $v0, -0x2BCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2BCC);
    return;
    // 0x8006F948: lw          $v0, -0x2BCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2BCC);
;}
RECOMP_FUNC void is_in_two_player_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EC84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EC88: jal         0x8009C2D0
    // 0x8009EC8C: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8009EC8C: nop

    after_0:
    // 0x8009EC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EC94: beq         $v0, $zero, L_8009ECA4
    if (ctx->r2 == 0) {
        // 0x8009EC98: nop
    
            goto L_8009ECA4;
    }
    // 0x8009EC98: nop

    // 0x8009EC9C: b           L_8009ECB0
    // 0x8009ECA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009ECB0;
    // 0x8009ECA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009ECA4:
    // 0x8009ECA4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009ECA8: lw          $v0, -0xB40($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB40);
    // 0x8009ECAC: nop

L_8009ECB0:
    // 0x8009ECB0: jr          $ra
    // 0x8009ECB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009ECB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void begin_trophy_race_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F254: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F258: lh          $t6, -0x2C6C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2C6C);
    // 0x8006F25C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F260: bne         $t6, $zero, L_8006F28C
    if (ctx->r14 != 0) {
        // 0x8006F264: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F28C;
    }
    // 0x8006F264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F268: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F26C: jal         0x800C01D8
    // 0x8006F270: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F270: addiu       $a0, $a0, -0x2BE4
    ctx->r4 = ADD32(ctx->r4, -0X2BE4);
    after_0:
    // 0x8006F274: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F278: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F27C: sh          $t7, -0x2C6C($at)
    MEM_H(-0X2C6C, ctx->r1) = ctx->r15;
    // 0x8006F280: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F284: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006F288: sb          $t8, 0x3524($at)
    MEM_B(0X3524, ctx->r1) = ctx->r24;
L_8006F28C:
    // 0x8006F28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F294: jr          $ra
    // 0x8006F298: nop

    return;
    // 0x8006F298: nop

;}
RECOMP_FUNC void _doModFunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064884: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80064888: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006488C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80064890: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064894: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80064898: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006489C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800648A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800648A4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800648A8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800648AC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800648B0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800648B4: nop

    // 0x800648B8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800648BC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800648C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800648C4: bc1f        L_800648E8
    if (!c1cs) {
        // 0x800648C8: nop
    
            goto L_800648E8;
    }
    // 0x800648C8: nop

    // 0x800648CC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800648D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800648D4: nop

    // 0x800648D8: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800648DC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800648E0: b           L_800648F0
    // 0x800648E4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_800648F0;
    // 0x800648E4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_800648E8:
    // 0x800648E8: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    // 0x800648EC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_800648F0:
    // 0x800648F0: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800648F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800648F8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800648FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80064900: bc1f        L_8006490C
    if (!c1cs) {
        // 0x80064904: nop
    
            goto L_8006490C;
    }
    // 0x80064904: nop

    // 0x80064908: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8006490C:
    // 0x8006490C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80064910: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80064914: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x80064918: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8006491C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80064920: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80064924: jr          $ra
    // 0x80064928: nop

    return;
    // 0x80064928: nop

;}
RECOMP_FUNC void obj_init_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035EF8: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80035EFC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80035F00: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80035F04: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80035F08: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x80035F0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035F10: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035F14: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80035F18: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80035F1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035F20: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80035F24: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80035F28: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035F2C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035F30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035F34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035F38: nop

    // 0x80035F3C: bc1f        L_80035F4C
    if (!c1cs) {
        // 0x80035F40: nop
    
            goto L_80035F4C;
    }
    // 0x80035F40: nop

    // 0x80035F44: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035F48: nop

L_80035F4C:
    // 0x80035F4C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035F50: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035F54: nop

    // 0x80035F58: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80035F5C: nop

    // 0x80035F60: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035F64: jr          $ra
    // 0x80035F68: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80035F68: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80070058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070058: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007005C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070060: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070064: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80070068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007006C: jal         0x80070830
    // 0x80070070: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x80070070: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x80070074: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070078: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8007007C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070080: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80070084: jal         0x8007082C
    // 0x80070088: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x80070088: nop

    after_1:
    // 0x8007008C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80070090: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80070094: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80070098: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8007009C: jal         0x80070830
    // 0x800700A0: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x800700A0: nop

    after_2:
    // 0x800700A4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800700A8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800700AC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800700B0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800700B4: jal         0x8007082C
    // 0x800700B8: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x800700B8: nop

    after_3:
    // 0x800700BC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800700C0: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x800700C4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800700C8: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800700CC: jal         0x80070830
    // 0x800700D0: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x800700D0: nop

    after_4:
    // 0x800700D4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800700D8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x800700DC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800700E0: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800700E4: jal         0x8007082C
    // 0x800700E8: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x800700E8: nop

    after_5:
    // 0x800700EC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800700F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800700F4: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x800700F8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800700FC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x80070100: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x80070104: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070108: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007010C: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070110: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80070114: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007011C: mul.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80070120: nop

    // 0x80070124: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80070128: jr          $ra
    // 0x8007012C: nop

    return;
    // 0x8007012C: nop

;}
RECOMP_FUNC void pakmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800895A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800895AC: jal         0x8009C508
    // 0x800895B0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x800895B0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x800895B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800895B8: lw          $a0, 0x6AA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6AA0);
    // 0x800895BC: jal         0x80071140
    // 0x800895C0: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800895C0: nop

    after_1:
    // 0x800895C4: jal         0x800C422C
    // 0x800895C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x800895C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800895CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800895D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800895D4: jr          $ra
    // 0x800895D8: nop

    return;
    // 0x800895D8: nop

;}
RECOMP_FUNC void __scTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079DE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079DF0: beq         $a0, $zero, L_80079E2C
    if (ctx->r4 == 0) {
        // 0x80079DF4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80079E2C;
    }
    // 0x80079DF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079DF8: jal         0x800D1E70
    // 0x80079DFC: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80079DFC: nop

    after_0:
    // 0x80079E00: jal         0x800D1EB0
    // 0x80079E04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80079E04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80079E08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80079E0C: nop

    // 0x80079E10: beq         $v0, $t7, L_80079E24
    if (ctx->r2 == ctx->r15) {
        // 0x80079E14: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80079E24;
    }
    // 0x80079E14: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80079E18: b           L_80079E30
    // 0x80079E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079E30;
    // 0x80079E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80079E20: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80079E24:
    // 0x80079E24: b           L_80079E34
    // 0x80079E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80079E34;
    // 0x80079E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079E2C:
    // 0x80079E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079E30:
    // 0x80079E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80079E34:
    // 0x80079E34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079E38: jr          $ra
    // 0x80079E3C: nop

    return;
    // 0x80079E3C: nop

;}
RECOMP_FUNC void fileselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E430: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E434: jal         0x8009C4A8
    // 0x8008E438: addiu       $a0, $a0, 0x398
    ctx->r4 = ADD32(ctx->r4, 0X398);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008E438: addiu       $a0, $a0, 0x398
    ctx->r4 = ADD32(ctx->r4, 0X398);
    after_0:
    // 0x8008E43C: jal         0x8007FF88
    // 0x8008E440: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008E440: nop

    after_1:
    // 0x8008E444: jal         0x800C422C
    // 0x8008E448: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008E448: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008E44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E454: jr          $ra
    // 0x8008E458: nop

    return;
    // 0x8008E458: nop

;}
RECOMP_FUNC void gfxtask_run_xbus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_presentation_task_submitted(uint8_t*, recomp_context*); dkr_presentation_task_submitted(rdram, ctx);
    // 0x80077450: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077454: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80077458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007745C: addiu       $v1, $v1, -0x1B2C
    ctx->r3 = ADD32(ctx->r3, -0X1B2C);
    // 0x80077460: sw          $t6, -0x1B24($at)
    MEM_W(-0X1B24, ctx->r1) = ctx->r14;
    // 0x80077464: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077468: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007746C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80077470: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80077474: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077478: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8007747C: addiu       $t8, $t8, 0x5F40
    ctx->r24 = ADD32(ctx->r24, 0X5F40);
    // 0x80077480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077484: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80077488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007748C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077490: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x80077494: bne         $t9, $at, L_800774A0
    if (ctx->r25 != ctx->r1) {
        // 0x80077498: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800774A0;
    }
    // 0x80077498: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007749C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800774A0:
    // 0x800774A0: subu        $t3, $a1, $a0
    ctx->r11 = SUB32(ctx->r5, ctx->r4);
    // 0x800774A4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800774A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800774AC: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800774B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800774B4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800774B8: addiu       $v1, $v1, -0x7B40
    ctx->r3 = ADD32(ctx->r3, -0X7B40);
    // 0x800774BC: addiu       $t2, $t2, 0x5ED8
    ctx->r10 = ADD32(ctx->r10, 0X5ED8);
    // 0x800774C0: sw          $t4, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r12;
    // 0x800774C4: sw          $t5, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r13;
    // 0x800774C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800774CC: addiu       $t7, $t7, -0x7A70
    ctx->r15 = ADD32(ctx->r15, -0X7A70);
    // 0x800774D0: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x800774D4: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x800774D8: sw          $t2, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r10;
    // 0x800774DC: sw          $t6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r14;
    // 0x800774E0: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x800774E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800774E8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800774EC: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x800774F0: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x800774F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800774F8: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800774FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077500: addiu       $t4, $t4, 0x46A0
    ctx->r12 = ADD32(ctx->r12, 0X46A0);
    // 0x80077504: addiu       $t5, $t5, 0x5EA0
    ctx->r13 = ADD32(ctx->r13, 0X5EA0);
    // 0x80077508: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007750C: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x80077510: addiu       $t9, $t9, -0x5690
    ctx->r25 = ADD32(ctx->r25, -0X5690);
    // 0x80077514: addiu       $t0, $t0, -0x5460
    ctx->r8 = ADD32(ctx->r8, -0X5460);
    // 0x80077518: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8007751C: addiu       $t2, $t2, 0x42A0
    ctx->r10 = ADD32(ctx->r10, 0X42A0);
    // 0x80077520: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80077524: sw          $t4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r12;
    // 0x80077528: sw          $t5, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r13;
    // 0x8007752C: addiu       $t6, $t6, 0x71B0
    ctx->r14 = ADD32(ctx->r14, 0X71B0);
    // 0x80077530: addiu       $t7, $zero, 0xA00
    ctx->r15 = ADD32(0, 0XA00);
    // 0x80077534: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077538: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x8007753C: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077540: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
    // 0x80077544: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x80077548: sw          $t0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r8;
    // 0x8007754C: sw          $t1, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r9;
    // 0x80077550: sw          $t2, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r10;
    // 0x80077554: sw          $t3, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r11;
    // 0x80077558: sw          $t6, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r14;
    // 0x8007755C: sw          $t7, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r15;
    // 0x80077560: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80077564: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80077568: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8007756C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80077570: lw          $t8, 0x62D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62D4);
    // 0x80077574: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80077578: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x8007757C: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x80077580: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
    // 0x80077584: jal         0x800D18A0
    // 0x80077588: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077588: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007758C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077590: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80077594: lw          $a0, 0x6100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6100);
    // 0x80077598: jal         0x800C8E30
    // 0x8007759C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007759C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800775A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800775A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800775A8: jr          $ra
    // 0x800775AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800775AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
