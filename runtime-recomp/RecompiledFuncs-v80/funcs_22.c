#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void fb_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007A4D0: lw          $v0, 0x62CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X62CC);
    // 0x8007A4D4: jr          $ra
    // 0x8007A4D8: nop

    return;
    // 0x8007A4D8: nop

;}
RECOMP_FUNC void trophy_race_cabinet_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E7E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009E7EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009E7F0: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8009E7F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E7F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E7FC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009E800: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009E804: jal         0x800C4EDC
    // 0x8009E808: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009E808: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009E80C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E810: jal         0x800C4F7C
    // 0x8009E814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009E814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009E818: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009E81C: jal         0x8006A554
    // 0x8009E820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009E820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009E824: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009E828: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8009E82C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009E830: lw          $a3, 0x118($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X118);
    // 0x8009E834: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E838: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009E83C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009E840: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009E844: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E848: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E84C: jal         0x800C5168
    // 0x8009E850: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009E850: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009E854: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E858: lb          $v1, 0x6464($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6464);
    // 0x8009E85C: nop

    // 0x8009E860: bgez        $v1, L_8009E884
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009E864: nop
    
            goto L_8009E884;
    }
    // 0x8009E864: nop

    // 0x8009E868: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E86C: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009E870: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8009E874: nop

    // 0x8009E878: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009E87C: b           L_8009E8A0
    // 0x8009E880: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
        goto L_8009E8A0;
    // 0x8009E880: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_8009E884:
    // 0x8009E884: blez        $v1, L_8009E8A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009E888: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E8A0;
    }
    // 0x8009E888: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E88C: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009E890: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8009E894: nop

    // 0x8009E898: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8009E89C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_8009E8A0:
    // 0x8009E8A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E8A4: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009E8A8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E8AC: nop

    // 0x8009E8B0: bgez        $v0, L_8009E8C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009E8B4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8009E8C8;
    }
    // 0x8009E8B4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8009E8B8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009E8BC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E8C0: nop

    // 0x8009E8C4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8009E8C8:
    // 0x8009E8C8: bne         $at, $zero, L_8009E8DC
    if (ctx->r1 != 0) {
        // 0x8009E8CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009E8DC;
    }
    // 0x8009E8CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009E8D0: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x8009E8D4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009E8D8: nop

L_8009E8DC:
    // 0x8009E8DC: jal         0x8009D118
    // 0x8009E8E0: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_4;
    // 0x8009E8E0: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    after_4:
    // 0x8009E8E4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E8E8: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009E8EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E8F0: lw          $a3, 0x2D0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X2D0);
    // 0x8009E8F4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E8F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E8FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E904: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E908: jal         0x800C5168
    // 0x8009E90C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    render_dialogue_text(rdram, ctx);
        goto after_5;
    // 0x8009E90C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_5:
    // 0x8009E910: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E914: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009E918: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009E91C: nop

    // 0x8009E920: xori        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 ^ 0X1;
    // 0x8009E924: jal         0x8009D118
    // 0x8009E928: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_6;
    // 0x8009E928: sltiu       $a0, $t8, 0x1
    ctx->r4 = ctx->r24 < 0X1 ? 1 : 0;
    after_6:
    // 0x8009E92C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E930: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8009E934: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009E938: lw          $a3, 0xCC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XCC);
    // 0x8009E93C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009E940: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009E944: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009E948: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E94C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E950: jal         0x800C5168
    // 0x8009E954: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009E954: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_7:
    // 0x8009E958: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8009E95C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E960: andi        $t2, $a1, 0x8000
    ctx->r10 = ctx->r5 & 0X8000;
    // 0x8009E964: beq         $t2, $zero, L_8009E97C
    if (ctx->r10 == 0) {
        // 0x8009E968: addiu       $v1, $v1, 0x64D8
        ctx->r3 = ADD32(ctx->r3, 0X64D8);
            goto L_8009E97C;
    }
    // 0x8009E968: addiu       $v1, $v1, 0x64D8
    ctx->r3 = ADD32(ctx->r3, 0X64D8);
    // 0x8009E96C: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8009E970: nop

    // 0x8009E974: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009E978: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
L_8009E97C:
    // 0x8009E97C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8009E980: andi        $t3, $a1, 0x4000
    ctx->r11 = ctx->r5 & 0X4000;
    // 0x8009E984: beq         $t3, $zero, L_8009E994
    if (ctx->r11 == 0) {
        // 0x8009E988: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009E994;
    }
    // 0x8009E988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E98C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009E990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E994:
    // 0x8009E994: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009E998: jr          $ra
    // 0x8009E99C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8009E99C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void menu_character_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_legacy_character_event(uint8_t*, recomp_context*, unsigned, uint32_t); dkr_legacy_character_event(rdram, ctx, 2U, 0x801263f0U);
    // 0x8008AFCC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008AFD0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008AFD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008AFD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008AFDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008AFE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008AFE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AFE8: jal         0x8006A434
    // 0x8008AFEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    input_assign_players(rdram, ctx);
        goto after_0;
    // 0x8008AFEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8008AFF0: jal         0x8009ECD0
    // 0x8008AFF4: nop

    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008AFF4: nop

    after_1:
    // 0x8008AFF8: beq         $v0, $zero, L_8008B03C
    if (ctx->r2 == 0) {
        // 0x8008AFFC: nop
    
            goto L_8008B03C;
    }
    // 0x8008AFFC: nop

    // 0x8008B000: jal         0x8009ECB8
    // 0x8008B004: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x8008B004: nop

    after_2:
    // 0x8008B008: beq         $v0, $zero, L_8008B028
    if (ctx->r2 == 0) {
        // 0x8008B00C: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B028;
    }
    // 0x8008B00C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B010: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B014: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B018: addiu       $a3, $a3, 0x63CC
    ctx->r7 = ADD32(ctx->r7, 0X63CC);
    // 0x8008B01C: addiu       $t6, $t6, -0xC0
    ctx->r14 = ADD32(ctx->r14, -0XC0);
    // 0x8008B020: b           L_8008B074
    // 0x8008B024: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
        goto L_8008B074;
    // 0x8008B024: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_8008B028:
    // 0x8008B028: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B02C: addiu       $a3, $a3, 0x63CC
    ctx->r7 = ADD32(ctx->r7, 0X63CC);
    // 0x8008B030: addiu       $t7, $t7, -0x1C0
    ctx->r15 = ADD32(ctx->r15, -0X1C0);
    // 0x8008B034: b           L_8008B074
    // 0x8008B038: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
        goto L_8008B074;
    // 0x8008B038: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_8008B03C:
    // 0x8008B03C: jal         0x8009ECB8
    // 0x8008B040: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x8008B040: nop

    after_3:
    // 0x8008B044: beq         $v0, $zero, L_8008B060
    if (ctx->r2 == 0) {
        // 0x8008B048: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8008B060;
    }
    // 0x8008B048: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B04C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008B050: addiu       $a3, $a3, 0x63CC
    ctx->r7 = ADD32(ctx->r7, 0X63CC);
    // 0x8008B054: addiu       $t8, $t8, -0x140
    ctx->r24 = ADD32(ctx->r24, -0X140);
    // 0x8008B058: b           L_8008B074
    // 0x8008B05C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_8008B074;
    // 0x8008B05C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8008B060:
    // 0x8008B060: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008B064: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008B068: addiu       $a3, $a3, 0x63CC
    ctx->r7 = ADD32(ctx->r7, 0X63CC);
    // 0x8008B06C: addiu       $t9, $t9, -0x230
    ctx->r25 = ADD32(ctx->r25, -0X230);
    // 0x8008B070: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8008B074:
    // 0x8008B074: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B078: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B07C: addiu       $v1, $v1, 0x63E0
    ctx->r3 = ADD32(ctx->r3, 0X63E0);
    // 0x8008B080: addiu       $v0, $v0, 0x63DC
    ctx->r2 = ADD32(ctx->r2, 0X63DC);
L_8008B084:
    // 0x8008B084: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B088: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008B08C: bne         $at, $zero, L_8008B084
    if (ctx->r1 != 0) {
        // 0x8008B090: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8008B084;
    }
    // 0x8008B090: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8008B094: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B098: sw          $zero, -0xB80($at)
    MEM_W(-0XB80, ctx->r1) = 0;
    // 0x8008B09C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B0A0: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008B0A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B0A8: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x8008B0AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008B0B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B0B4: addiu       $t0, $t0, 0x63D4
    ctx->r8 = ADD32(ctx->r8, 0X63D4);
    // 0x8008B0B8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B0BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B0C0: sw          $zero, -0xB7C($at)
    MEM_W(-0XB7C, ctx->r1) = 0;
    // 0x8008B0C4: addiu       $v1, $v1, 0x63E8
    ctx->r3 = ADD32(ctx->r3, 0X63E8);
    // 0x8008B0C8: addiu       $s2, $s2, 0x63C0
    ctx->r18 = ADD32(ctx->r18, 0X63C0);
    // 0x8008B0CC: addu        $v0, $zero, $t0
    ctx->r2 = ADD32(0, ctx->r8);
    // 0x8008B0D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B0D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B0D8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8008B0DC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
L_8008B0E0:
    // 0x8008B0E0: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x8008B0E4: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8008B0E8: beq         $t1, $zero, L_8008B118
    if (ctx->r9 == 0) {
        // 0x8008B0EC: nop
    
            goto L_8008B118;
    }
    // 0x8008B0EC: nop

    // 0x8008B0F0: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B0F4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8008B0F8: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B0FC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8008B100: mflo        $t5
    ctx->r13 = lo;
    // 0x8008B104: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8008B108: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008B10C: sh          $a1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r5;
    // 0x8008B110: sb          $a2, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r6;
    // 0x8008B114: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_8008B118:
    // 0x8008B118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B11C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B120: beq         $at, $zero, L_8008B130
    if (ctx->r1 == 0) {
        // 0x8008B124: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008B130;
    }
    // 0x8008B124: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B128: beq         $s1, $zero, L_8008B0E0
    if (ctx->r17 == 0) {
        // 0x8008B12C: nop
    
            goto L_8008B0E0;
    }
    // 0x8008B12C: nop

L_8008B130:
    // 0x8008B130: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B134: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B138: addiu       $v1, $v1, 0x63B8
    ctx->r3 = ADD32(ctx->r3, 0X63B8);
    // 0x8008B13C: addiu       $v0, $v0, 0x63B4
    ctx->r2 = ADD32(ctx->r2, 0X63B4);
    // 0x8008B140: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008B144: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B148: addiu       $s2, $s2, 0x63C0
    ctx->r18 = ADD32(ctx->r18, 0X63C0);
    // 0x8008B14C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8008B150: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008B154: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008B158: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // 0x8008B15C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8008B160: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    extern void dkr_netplay_character_select_enter(uint8_t*, recomp_context*); dkr_netplay_character_select_enter(rdram, ctx); extern void dkr_character_select_music_unblock(uint8_t*, recomp_context*); dkr_character_select_music_unblock(rdram, ctx);
    // 0x8008B164: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8008B168: jal         0x80000B34
    // 0x8008B16C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8008B16C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8008B170: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008B174: addiu       $s3, $s3, -0x24C
    ctx->r19 = ADD32(ctx->r19, -0X24C);
    // 0x8008B178: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008B17C:
    // 0x8008B17C: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008B180: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008B184: beq         $s0, $t8, L_8008B1A4
    if (ctx->r16 == ctx->r24) {
        // 0x8008B188: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008B1A4;
    }
    // 0x8008B188: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008B18C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008B190: jal         0x80001114
    // 0x8008B194: nop

    music_channel_off(rdram, ctx);
        goto after_5;
    // 0x8008B194: nop

    after_5:
    // 0x8008B198: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008B19C: jal         0x80001114
    // 0x8008B1A0: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008B1A0: nop

    after_6:
L_8008B1A4:
    // 0x8008B1A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B1A8: bne         $s0, $s4, L_8008B17C
    if (ctx->r16 != ctx->r20) {
        // 0x8008B1AC: nop
    
            goto L_8008B17C;
    }
    // 0x8008B1AC: nop

    // 0x8008B1B0: jal         0x80001114
    // 0x8008B1B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008B1B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    extern void dkr_character_select_music_mask(uint8_t*, recomp_context*); dkr_character_select_music_mask(rdram, ctx);
    // 0x8008B1B8: jal         0x80000B18
    // 0x8008B1BC: nop

    music_change_off(rdram, ctx);
        goto after_8;
    // 0x8008B1BC: nop

    after_8:
    // 0x8008B1C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B1C4: jal         0x8009C674
    // 0x8008B1C8: addiu       $a0, $a0, -0x238
    ctx->r4 = ADD32(ctx->r4, -0X238);
    menu_assetgroup_load(rdram, ctx);
        goto after_9;
    // 0x8008B1C8: addiu       $a0, $a0, -0x238
    ctx->r4 = ADD32(ctx->r4, -0X238);
    after_9:
    // 0x8008B1CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B1D0: jal         0x8009C8A4
    // 0x8008B1D4: addiu       $a0, $a0, -0x234
    ctx->r4 = ADD32(ctx->r4, -0X234);
    menu_imagegroup_load(rdram, ctx);
        goto after_10;
    // 0x8008B1D4: addiu       $a0, $a0, -0x234
    ctx->r4 = ADD32(ctx->r4, -0X234);
    after_10:
    // 0x8008B1D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008B1DC: jal         0x800C01D8
    // 0x8008B1E0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x8008B1E0: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_11:
    // 0x8008B1E4: jal         0x800C4170
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_12;
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x8008B1EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B1F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B1F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B1FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B200: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 0U, dkr_character_menu_fields); }
    // 0x8008B204: jr          $ra
    // 0x8008B208: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008B208: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void roll_percent_chance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004445C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80044460: jal         0x8006F94C
    // 0x80044464: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80044464: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_0:
    // 0x80044468: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8004446C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044474: jr          $ra
    // 0x80044478: slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    return;
    // 0x80044478: slt         $v0, $v0, $t6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
;}
RECOMP_FUNC void check_if_showing_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066510: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066514: lb          $v0, 0xD14($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XD14);
    // 0x80066518: jr          $ra
    // 0x8006651C: nop

    return;
    // 0x8006651C: nop

;}
RECOMP_FUNC void sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FDC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80000FE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000FE4: addiu       $a2, $a2, -0x39A8
    ctx->r6 = ADD32(ctx->r6, -0X39A8);
    // 0x80000FE8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80000FEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80000FF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80000FF4: beq         $at, $zero, L_80001048
    if (ctx->r1 == 0) {
        // 0x80000FF8: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_80001048;
    }
    // 0x80000FF8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80000FFC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80001000: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001004: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001008: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8000100C: addiu       $t8, $t8, 0x5D48
    ctx->r24 = ADD32(ctx->r24, 0X5D48);
    // 0x80001010: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80001014: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80001018: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000101C: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80001020: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80001024: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001028: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000102C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80001030: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80001034: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80001038: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8000103C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80001040: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80001044: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
L_80001048:
    // 0x80001048: jr          $ra
    // 0x8000104C: nop

    return;
    // 0x8000104C: nop

;}
RECOMP_FUNC void sound_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000208C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80002098: beq         $a0, $zero, L_800020AC
    if (ctx->r4 == 0) {
        // 0x8000209C: andi        $a3, $a1, 0xFF
        ctx->r7 = ctx->r5 & 0XFF;
            goto L_800020AC;
    }
    // 0x8000209C: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x800020A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800020A4: jal         0x800049F8
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020A8: sll         $a2, $a3, 8
    ctx->r6 = S32(ctx->r7 << 8);
    after_0:
L_800020AC:
    // 0x800020AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020B4: jr          $ra
    // 0x800020B8: nop

    return;
    // 0x800020B8: nop

;}
RECOMP_FUNC void font_codes_to_string(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007698C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80076990: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80076994: beq         $v0, $zero, L_800769E8
    if (ctx->r2 == 0) {
        // 0x80076998: nop
    
            goto L_800769E8;
    }
    // 0x80076998: nop

    // 0x8007699C: beq         $a2, $zero, L_800769E8
    if (ctx->r6 == 0) {
        // 0x800769A0: addiu       $t0, $zero, 0x2D
        ctx->r8 = ADD32(0, 0X2D);
            goto L_800769E8;
    }
    // 0x800769A0: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x800769A4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800769A8: addiu       $a3, $a3, -0x1BBC
    ctx->r7 = ADD32(ctx->r7, -0X1BBC);
    // 0x800769AC: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_800769B0:
    // 0x800769B0: beq         $at, $zero, L_800769C8
    if (ctx->r1 == 0) {
        // 0x800769B4: addu        $t6, $a3, $v0
        ctx->r14 = ADD32(ctx->r7, ctx->r2);
            goto L_800769C8;
    }
    // 0x800769B4: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x800769B8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800769BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800769C0: b           L_800769D0
    // 0x800769C4: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
        goto L_800769D0;
    // 0x800769C4: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
L_800769C8:
    // 0x800769C8: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x800769CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800769D0:
    // 0x800769D0: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800769D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800769D8: beq         $v0, $zero, L_800769E8
    if (ctx->r2 == 0) {
        // 0x800769DC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800769E8;
    }
    // 0x800769DC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800769E0: bne         $a2, $zero, L_800769B0
    if (ctx->r6 != 0) {
        // 0x800769E4: slti        $at, $v0, 0x42
        ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
            goto L_800769B0;
    }
    // 0x800769E4: slti        $at, $v0, 0x42
    ctx->r1 = SIGNED(ctx->r2) < 0X42 ? 1 : 0;
L_800769E8:
    // 0x800769E8: beq         $a2, $zero, L_80076A2C
    if (ctx->r6 == 0) {
        // 0x800769EC: andi        $a0, $a2, 0x3
        ctx->r4 = ctx->r6 & 0X3;
            goto L_80076A2C;
    }
    // 0x800769EC: andi        $a0, $a2, 0x3
    ctx->r4 = ctx->r6 & 0X3;
    // 0x800769F0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800769F4: beq         $a0, $zero, L_80076A10
    if (ctx->r4 == 0) {
        // 0x800769F8: addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
            goto L_80076A10;
    }
    // 0x800769F8: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
L_800769FC:
    // 0x800769FC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80076A00: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076A04: bne         $v0, $a2, L_800769FC
    if (ctx->r2 != ctx->r6) {
        // 0x80076A08: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800769FC;
    }
    // 0x80076A08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80076A0C: beq         $a2, $zero, L_80076A2C
    if (ctx->r6 == 0) {
        // 0x80076A10: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80076A2C;
    }
L_80076A10:
    // 0x80076A10: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80076A14: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076A18: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80076A1C: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80076A20: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80076A24: bne         $a2, $zero, L_80076A10
    if (ctx->r6 != 0) {
        // 0x80076A28: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80076A10;
    }
    // 0x80076A28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80076A2C:
    // 0x80076A2C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80076A30: jr          $ra
    // 0x80076A34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80076A34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001E6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E6EC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E6F0: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E6F8: lb          $v1, -0x5200($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5200);
    // 0x8001E6FC: sll         $s0, $a0, 24
    ctx->r16 = S32(ctx->r4 << 24);
    // 0x8001E700: sra         $t6, $s0, 24
    ctx->r14 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8001E704: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E708: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8001E70C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x8001E710: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E714: blez        $v1, L_8001E880
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E718: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E880;
    }
    // 0x8001E718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E71C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E720: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8001E724: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001E728: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E72C: addiu       $t4, $t4, -0x5186
    ctx->r12 = ADD32(ctx->r12, -0X5186);
    // 0x8001E730: addiu       $s1, $s1, -0x5188
    ctx->r17 = ADD32(ctx->r17, -0X5188);
    // 0x8001E734: addiu       $s2, $s2, -0x518C
    ctx->r18 = ADD32(ctx->r18, -0X518C);
    // 0x8001E738: addiu       $a1, $a1, -0x5228
    ctx->r5 = ADD32(ctx->r5, -0X5228);
    // 0x8001E73C: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
L_8001E740:
    // 0x8001E740: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E744: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x8001E748: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x8001E74C: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x8001E750: lb          $t0, 0x9($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X9);
    // 0x8001E754: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E758: beq         $t7, $t0, L_8001E768
    if (ctx->r15 == ctx->r8) {
        // 0x8001E75C: nop
    
            goto L_8001E768;
    }
    // 0x8001E75C: nop

    // 0x8001E760: bne         $t5, $t0, L_8001E878
    if (ctx->r13 != ctx->r8) {
        // 0x8001E764: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E878;
    }
    // 0x8001E764: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E768:
    // 0x8001E768: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8001E76C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E770: blez        $t1, L_8001E7C4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001E774: nop
    
            goto L_8001E7C4;
    }
    // 0x8001E774: nop

    // 0x8001E778: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8001E77C: lb          $t2, 0x8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X8);
    // 0x8001E780: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8001E784: nop

    // 0x8001E788: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E78C: nop

    // 0x8001E790: beq         $t2, $t9, L_8001E7C4
    if (ctx->r10 == ctx->r25) {
        // 0x8001E794: nop
    
            goto L_8001E7C4;
    }
    // 0x8001E794: nop

L_8001E798:
    // 0x8001E798: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001E79C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E7A0: beq         $at, $zero, L_8001E7C4
    if (ctx->r1 == 0) {
        // 0x8001E7A4: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_8001E7C4;
    }
    // 0x8001E7A4: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8001E7A8: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8001E7AC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001E7B0: nop

    // 0x8001E7B4: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8001E7B8: nop

    // 0x8001E7BC: bne         $t2, $t9, L_8001E798
    if (ctx->r10 != ctx->r25) {
        // 0x8001E7C0: nop
    
            goto L_8001E798;
    }
    // 0x8001E7C0: nop

L_8001E7C4:
    // 0x8001E7C4: beq         $t0, $t1, L_8001E864
    if (ctx->r8 == ctx->r9) {
        // 0x8001E7C8: nop
    
            goto L_8001E864;
    }
    // 0x8001E7C8: nop

    // 0x8001E7CC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001E7D0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001E7D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E7D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E7DC: nop

    // 0x8001E7E0: lw          $a2, 0x64($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X64);
    // 0x8001E7E4: nop

    // 0x8001E7E8: beq         $a2, $zero, L_8001E864
    if (ctx->r6 == 0) {
        // 0x8001E7EC: nop
    
            goto L_8001E864;
    }
    // 0x8001E7EC: nop

    // 0x8001E7F0: lw          $t6, 0x5C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X5C);
    // 0x8001E7F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001E7F8: beq         $t6, $zero, L_8001E808
    if (ctx->r14 == 0) {
        // 0x8001E7FC: nop
    
            goto L_8001E808;
    }
    // 0x8001E7FC: nop

    // 0x8001E800: b           L_8001E808
    // 0x8001E804: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8001E808;
    // 0x8001E804: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001E808:
    // 0x8001E808: beq         $s0, $t0, L_8001E878
    if (ctx->r16 == ctx->r8) {
        // 0x8001E80C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E878;
    }
    // 0x8001E80C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E810: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8001E814: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E818: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8001E81C: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8001E820: nop

    // 0x8001E824: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x8001E828: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8001E82C: sw          $a2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r6;
    // 0x8001E830: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8001E834: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E838: nop

    // 0x8001E83C: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x8001E840: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E844: nop

    // 0x8001E848: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x8001E84C: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E850: nop

    // 0x8001E854: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x8001E858: lb          $v1, -0x5200($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5200);
    // 0x8001E85C: b           L_8001E878
    // 0x8001E860: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8001E878;
    // 0x8001E860: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E864:
    // 0x8001E864: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8001E868: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E86C: lb          $v1, -0x5200($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5200);
    // 0x8001E870: nop

    // 0x8001E874: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E878:
    // 0x8001E878: bne         $at, $zero, L_8001E740
    if (ctx->r1 != 0) {
        // 0x8001E87C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E740;
    }
    // 0x8001E87C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E880:
    // 0x8001E880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E884: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E888: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8001E88C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x8001E890: sb          $zero, -0x51FF($at)
    MEM_B(-0X51FF, ctx->r1) = 0;
    // 0x8001E894: jr          $ra
    // 0x8001E898: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E898: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void load_fonts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3C08: jal         0x80076C58
    // 0x800C3C0C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x800C3C0C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x800C3C10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C3C14: addiu       $v1, $v1, -0x581C
    ctx->r3 = ADD32(ctx->r3, -0X581C);
    // 0x800C3C18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C3C1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C3C20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3C24: addiu       $a0, $a0, -0x5820
    ctx->r4 = ADD32(ctx->r4, -0X5820);
    // 0x800C3C28: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x800C3C2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C3C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3C34: blez        $t6, L_800C3C64
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C3C38: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_800C3C64;
    }
    // 0x800C3C38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C3C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3C40:
    // 0x800C3C40: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C3C44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C3C48: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3C4C: sb          $zero, 0x28($t3)
    MEM_B(0X28, ctx->r11) = 0;
    // 0x800C3C50: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800C3C54: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800C3C58: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800C3C5C: bne         $at, $zero, L_800C3C40
    if (ctx->r1 != 0) {
        // 0x800C3C60: nop
    
            goto L_800C3C40;
    }
    // 0x800C3C60: nop

L_800C3C64:
    // 0x800C3C64: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C3C68: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C3C6C: jal         0x80070C9C
    // 0x800C3C70: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C3C70: addiu       $a0, $zero, 0x940
    ctx->r4 = ADD32(0, 0X940);
    after_1:
    // 0x800C3C74: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C3C78: addiu       $a2, $a2, -0x5818
    ctx->r6 = ADD32(ctx->r6, -0X5818);
    // 0x800C3C7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C3C80: addiu       $t6, $v0, 0x140
    ctx->r14 = ADD32(ctx->r2, 0X140);
    // 0x800C3C84: addiu       $v1, $v1, -0x5814
    ctx->r3 = ADD32(ctx->r3, -0X5814);
    // 0x800C3C88: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800C3C8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C3C90: addiu       $v0, $zero, 0x13F
    ctx->r2 = ADD32(0, 0X13F);
    // 0x800C3C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3C98: addiu       $t2, $zero, 0x4000
    ctx->r10 = ADD32(0, 0X4000);
    // 0x800C3C9C: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x800C3CA0: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x800C3CA4: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    // 0x800C3CA8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800C3CAC:
    // 0x800C3CAC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C3CB0: nop

    // 0x800C3CB4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C3CB8: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x800C3CBC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C3CC0: nop

    // 0x800C3CC4: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C3CC8: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x800C3CCC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C3CD0: nop

    // 0x800C3CD4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C3CD8: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800C3CDC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C3CE0: nop

    // 0x800C3CE4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C3CE8: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x800C3CEC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C3CF0: nop

    // 0x800C3CF4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C3CF8: sh          $v0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r2;
    // 0x800C3CFC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D00: nop

    // 0x800C3D04: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C3D08: sh          $a3, 0xA($t4)
    MEM_H(0XA, ctx->r12) = ctx->r7;
    // 0x800C3D0C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D10: nop

    // 0x800C3D14: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C3D18: sh          $t0, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r8;
    // 0x800C3D1C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D20: nop

    // 0x800C3D24: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C3D28: sh          $t1, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r9;
    // 0x800C3D2C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D30: nop

    // 0x800C3D34: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C3D38: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C3D3C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D40: nop

    // 0x800C3D44: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C3D48: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C3D4C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D50: nop

    // 0x800C3D54: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C3D58: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C3D5C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D60: nop

    // 0x800C3D64: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C3D68: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C3D6C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D70: nop

    // 0x800C3D74: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C3D78: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C3D7C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D80: nop

    // 0x800C3D84: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C3D88: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C3D8C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C3D90: nop

    // 0x800C3D94: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C3D98: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C3D9C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DA0: nop

    // 0x800C3DA4: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C3DA8: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C3DAC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DB0: nop

    // 0x800C3DB4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C3DB8: sb          $a0, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r4;
    // 0x800C3DBC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DC0: nop

    // 0x800C3DC4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C3DC8: sb          $a0, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r4;
    // 0x800C3DCC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DD0: nop

    // 0x800C3DD4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C3DD8: sb          $a0, 0x1A($t9)
    MEM_B(0X1A, ctx->r25) = ctx->r4;
    // 0x800C3DDC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DE0: nop

    // 0x800C3DE4: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C3DE8: sb          $zero, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = 0;
    // 0x800C3DEC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C3DF0: nop

    // 0x800C3DF4: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x800C3DF8: sb          $a0, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r4;
    // 0x800C3DFC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E00: nop

    // 0x800C3E04: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C3E08: beq         $a1, $zero, L_800C3E24
    if (ctx->r5 == 0) {
        // 0x800C3E0C: sb          $a0, 0x1D($t8)
        MEM_B(0X1D, ctx->r24) = ctx->r4;
            goto L_800C3E24;
    }
    // 0x800C3E0C: sb          $a0, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r4;
    // 0x800C3E10: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E14: nop

    // 0x800C3E18: addu        $t3, $t9, $a1
    ctx->r11 = ADD32(ctx->r25, ctx->r5);
    // 0x800C3E1C: b           L_800C3E34
    // 0x800C3E20: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
        goto L_800C3E34;
    // 0x800C3E20: sh          $t2, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r10;
L_800C3E24:
    // 0x800C3E24: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E28: nop

    // 0x800C3E2C: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x800C3E30: sh          $zero, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = 0;
L_800C3E34:
    // 0x800C3E34: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E38: nop

    // 0x800C3E3C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C3E40: sh          $zero, 0x20($t7)
    MEM_H(0X20, ctx->r15) = 0;
    // 0x800C3E44: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E48: nop

    // 0x800C3E4C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C3E50: sh          $zero, 0x22($t9)
    MEM_H(0X22, ctx->r25) = 0;
    // 0x800C3E54: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800C3E58: nop

    // 0x800C3E5C: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x800C3E60: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x800C3E64: slti        $at, $a1, 0x140
    ctx->r1 = SIGNED(ctx->r5) < 0X140 ? 1 : 0;
    // 0x800C3E68: bne         $at, $zero, L_800C3CAC
    if (ctx->r1 != 0) {
        // 0x800C3E6C: sw          $zero, 0x24($t4)
        MEM_W(0X24, ctx->r12) = 0;
            goto L_800C3CAC;
    }
    // 0x800C3E6C: sw          $zero, 0x24($t4)
    MEM_W(0X24, ctx->r12) = 0;
    // 0x800C3E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C3E74: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
L_800C3E78:
    // 0x800C3E78: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C3E7C: nop

    // 0x800C3E80: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3E84: sb          $a0, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r4;
    // 0x800C3E88: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C3E8C: nop

    // 0x800C3E90: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3E94: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800C3E98: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C3E9C: nop

    // 0x800C3EA0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3EA4: sb          $a0, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r4;
    // 0x800C3EA8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C3EAC: nop

    // 0x800C3EB0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C3EB4: sb          $a0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r4;
    // 0x800C3EB8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C3EBC: nop

    // 0x800C3EC0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C3EC4: sb          $a0, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r4;
    // 0x800C3EC8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C3ECC: nop

    // 0x800C3ED0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C3ED4: sb          $zero, 0x13($t9)
    MEM_B(0X13, ctx->r25) = 0;
    // 0x800C3ED8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C3EDC: nop

    // 0x800C3EE0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C3EE4: sb          $a0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r4;
    // 0x800C3EE8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C3EEC: nop

    // 0x800C3EF0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3EF4: sb          $a0, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r4;
    // 0x800C3EF8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C3EFC: nop

    // 0x800C3F00: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3F04: sb          $a0, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r4;
    // 0x800C3F08: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F0C: nop

    // 0x800C3F10: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3F14: sb          $zero, 0x17($t3)
    MEM_B(0X17, ctx->r11) = 0;
    // 0x800C3F18: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F1C: nop

    // 0x800C3F20: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C3F24: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x800C3F28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F2C: nop

    // 0x800C3F30: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C3F34: sb          $a0, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r4;
    // 0x800C3F38: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F3C: nop

    // 0x800C3F40: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C3F44: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x800C3F48: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F4C: nop

    // 0x800C3F50: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C3F54: sb          $a0, 0x30($t4)
    MEM_B(0X30, ctx->r12) = ctx->r4;
    // 0x800C3F58: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F5C: nop

    // 0x800C3F60: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3F64: sb          $a0, 0x31($t6)
    MEM_B(0X31, ctx->r14) = ctx->r4;
    // 0x800C3F68: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F6C: nop

    // 0x800C3F70: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3F74: sb          $a0, 0x32($t8)
    MEM_B(0X32, ctx->r24) = ctx->r4;
    // 0x800C3F78: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F7C: nop

    // 0x800C3F80: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3F84: sb          $zero, 0x33($t3)
    MEM_B(0X33, ctx->r11) = 0;
    // 0x800C3F88: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F8C: nop

    // 0x800C3F90: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C3F94: sb          $a0, 0x34($t5)
    MEM_B(0X34, ctx->r13) = ctx->r4;
    // 0x800C3F98: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C3F9C: nop

    // 0x800C3FA0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C3FA4: sb          $a0, 0x35($t7)
    MEM_B(0X35, ctx->r15) = ctx->r4;
    // 0x800C3FA8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FAC: nop

    // 0x800C3FB0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C3FB4: sb          $a0, 0x36($t9)
    MEM_B(0X36, ctx->r25) = ctx->r4;
    // 0x800C3FB8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FBC: nop

    // 0x800C3FC0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C3FC4: sb          $zero, 0x37($t4)
    MEM_B(0X37, ctx->r12) = 0;
    // 0x800C3FC8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FCC: nop

    // 0x800C3FD0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C3FD4: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x800C3FD8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FDC: nop

    // 0x800C3FE0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3FE4: sb          $a0, 0x41($t8)
    MEM_B(0X41, ctx->r24) = ctx->r4;
    // 0x800C3FE8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FEC: nop

    // 0x800C3FF0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C3FF4: sw          $zero, 0x44($t3)
    MEM_W(0X44, ctx->r11) = 0;
    // 0x800C3FF8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C3FFC: nop

    // 0x800C4000: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4004: sb          $a0, 0x50($t5)
    MEM_B(0X50, ctx->r13) = ctx->r4;
    // 0x800C4008: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C400C: nop

    // 0x800C4010: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4014: sb          $a0, 0x51($t7)
    MEM_B(0X51, ctx->r15) = ctx->r4;
    // 0x800C4018: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C401C: nop

    // 0x800C4020: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4024: sb          $a0, 0x52($t9)
    MEM_B(0X52, ctx->r25) = ctx->r4;
    // 0x800C4028: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C402C: nop

    // 0x800C4030: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4034: sb          $zero, 0x53($t4)
    MEM_B(0X53, ctx->r12) = 0;
    // 0x800C4038: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C403C: nop

    // 0x800C4040: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4044: sb          $a0, 0x54($t6)
    MEM_B(0X54, ctx->r14) = ctx->r4;
    // 0x800C4048: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C404C: nop

    // 0x800C4050: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4054: sb          $a0, 0x55($t8)
    MEM_B(0X55, ctx->r24) = ctx->r4;
    // 0x800C4058: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C405C: nop

    // 0x800C4060: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C4064: sb          $a0, 0x56($t3)
    MEM_B(0X56, ctx->r11) = ctx->r4;
    // 0x800C4068: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C406C: nop

    // 0x800C4070: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C4074: sb          $zero, 0x57($t5)
    MEM_B(0X57, ctx->r13) = 0;
    // 0x800C4078: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C407C: nop

    // 0x800C4080: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C4084: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
    // 0x800C4088: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C408C: nop

    // 0x800C4090: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4094: sb          $a0, 0x61($t9)
    MEM_B(0X61, ctx->r25) = ctx->r4;
    // 0x800C4098: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C409C: nop

    // 0x800C40A0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C40A4: sw          $zero, 0x64($t4)
    MEM_W(0X64, ctx->r12) = 0;
    // 0x800C40A8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C40AC: nop

    // 0x800C40B0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C40B4: sb          $a0, 0x70($t6)
    MEM_B(0X70, ctx->r14) = ctx->r4;
    // 0x800C40B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C40BC: nop

    // 0x800C40C0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C40C4: sb          $a0, 0x71($t8)
    MEM_B(0X71, ctx->r24) = ctx->r4;
    // 0x800C40C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C40CC: nop

    // 0x800C40D0: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C40D4: sb          $a0, 0x72($t3)
    MEM_B(0X72, ctx->r11) = ctx->r4;
    // 0x800C40D8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C40DC: nop

    // 0x800C40E0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C40E4: sb          $zero, 0x73($t5)
    MEM_B(0X73, ctx->r13) = 0;
    // 0x800C40E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C40EC: nop

    // 0x800C40F0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C40F4: sb          $a0, 0x74($t7)
    MEM_B(0X74, ctx->r15) = ctx->r4;
    // 0x800C40F8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C40FC: nop

    // 0x800C4100: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C4104: sb          $a0, 0x75($t9)
    MEM_B(0X75, ctx->r25) = ctx->r4;
    // 0x800C4108: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800C410C: nop

    // 0x800C4110: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C4114: sb          $a0, 0x76($t4)
    MEM_B(0X76, ctx->r12) = ctx->r4;
    // 0x800C4118: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C411C: nop

    // 0x800C4120: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C4124: sb          $zero, 0x77($t6)
    MEM_B(0X77, ctx->r14) = 0;
    // 0x800C4128: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C412C: nop

    // 0x800C4130: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C4134: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x800C4138: bne         $v0, $a1, L_800C3E78
    if (ctx->r2 != ctx->r5) {
        // 0x800C413C: sw          $zero, 0x7C($t8)
        MEM_W(0X7C, ctx->r24) = 0;
            goto L_800C3E78;
    }
    // 0x800C413C: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x800C4140: jal         0x800C4170
    // 0x800C4144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_font(rdram, ctx);
        goto after_2;
    // 0x800C4144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800C4148: jal         0x800C4170
    // 0x800C414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_font(rdram, ctx);
        goto after_3;
    // 0x800C414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800C4150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4154: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C4158: sw          $zero, -0x5810($at)
    MEM_W(-0X5810, ctx->r1) = 0;
    // 0x800C415C: jr          $ra
    // 0x800C4160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C4160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void menu_track_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 0U, dkr_legacy_fields, 0U); }
    // 0x8008E7A0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008E7A4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008E7A8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008E7AC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008E7B0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008E7B4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008E7B8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008E7BC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008E7C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008E7C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008E7C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008E7CC: jal         0x800C4170
    // 0x8008E7D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008E7D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008E7D4: jal         0x8006EA90
    // 0x8008E7D8: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8008E7D8: nop

    after_1:
    // 0x8008E7DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8008E7E0: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8008E7E4: jal         0x8006B224
    // 0x8008E7E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8008E7E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_2:
    // 0x8008E7EC: jal         0x8001E29C
    // 0x8008E7F0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8008E7F0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_3:
    // 0x8008E7F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008E7F8: addiu       $v1, $v1, -0xB78
    ctx->r3 = ADD32(ctx->r3, -0XB78);
    // 0x8008E7FC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008E800: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8008E804: beq         $t6, $zero, L_8008E82C
    if (ctx->r14 == 0) {
        // 0x8008E808: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008E82C;
    }
    // 0x8008E808: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E80C: sw          $zero, 0x69C8($at)
    MEM_W(0X69C8, ctx->r1) = 0;
    // 0x8008E810: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E814: sw          $zero, 0x69CC($at)
    MEM_W(0X69CC, ctx->r1) = 0;
    // 0x8008E818: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E81C: sw          $zero, 0x414($at)
    MEM_W(0X414, ctx->r1) = 0;
    // 0x8008E820: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E824: sw          $zero, 0x418($at)
    MEM_W(0X418, ctx->r1) = 0;
    // 0x8008E828: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8008E82C:
    // 0x8008E82C: jal         0x8007A520
    // 0x8008E830: nop

    fb_size(rdram, ctx);
        goto after_4;
    // 0x8008E830: nop

    after_4:
    // 0x8008E834: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008E838: addiu       $a2, $a2, 0x647C
    ctx->r6 = ADD32(ctx->r6, 0X647C);
    // 0x8008E83C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008E840: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8008E844: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8008E848: addiu       $a3, $a3, 0x6480
    ctx->r7 = ADD32(ctx->r7, 0X6480);
    // 0x8008E84C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8008E850: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8008E854: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8008E858: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008E85C: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8008E860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E864: sw          $t2, 0x6474($at)
    MEM_W(0X6474, ctx->r1) = ctx->r10;
    // 0x8008E868: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8008E86C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008E870: addiu       $fp, $fp, 0x6478
    ctx->r30 = ADD32(ctx->r30, 0X6478);
    // 0x8008E874: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8008E878: sw          $t3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r11;
    // 0x8008E87C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008E880: lw          $t4, 0x69C8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X69C8);
    // 0x8008E884: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008E888: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8008E88C: lw          $t5, 0x69CC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X69CC);
    // 0x8008E890: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008E894: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008E898: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008E89C: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8008E8A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8008E8A4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8008E8A8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008E8AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8B0: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8008E8B4: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8008E8B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008E8BC: swc1        $f10, 0x69DC($at)
    MEM_W(0X69DC, ctx->r1) = ctx->f10.u32l;
    // 0x8008E8C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008E8C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008E8CC: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8008E8D0: swc1        $f8, 0x69E4($at)
    MEM_W(0X69E4, ctx->r1) = ctx->f8.u32l;
    // 0x8008E8D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8D8: sw          $s5, 0x69F4($at)
    MEM_W(0X69F4, ctx->r1) = ctx->r21;
    // 0x8008E8DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8E0: sw          $s5, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = ctx->r21;
    // 0x8008E8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8E8: sw          $s5, 0x63D0($at)
    MEM_W(0X63D0, ctx->r1) = ctx->r21;
    // 0x8008E8EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8F0: sw          $t7, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r15;
    // 0x8008E8F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E8F8: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x8008E8FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E900: jal         0x8008F00C
    // 0x8008E904: sw          $s5, 0x67D0($at)
    MEM_W(0X67D0, ctx->r1) = ctx->r21;
    trackmenu_assets(rdram, ctx);
        goto after_5;
    // 0x8008E904: sw          $s5, 0x67D0($at)
    MEM_W(0X67D0, ctx->r1) = ctx->r21;
    after_5:
    // 0x8008E908: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E90C: jal         0x800C01D8
    // 0x8008E910: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_6;
    // 0x8008E910: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_6:
    // 0x8008E914: jal         0x800C0170
    // 0x8008E918: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_7;
    // 0x8008E918: nop

    after_7:
    // 0x8008E91C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8008E920: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8008E924: jal         0x80077B5C
    // 0x8008E928: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    bgdraw_fillcolour(rdram, ctx);
        goto after_8;
    // 0x8008E928: addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    after_8:
    // 0x8008E92C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8008E930: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008E934: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008E938: addiu       $s2, $s2, 0x730
    ctx->r18 = ADD32(ctx->r18, 0X730);
    // 0x8008E93C: addiu       $s6, $s6, 0x6550
    ctx->r22 = ADD32(ctx->r22, 0X6550);
    // 0x8008E940: addiu       $s1, $s1, 0x710
    ctx->r17 = ADD32(ctx->r17, 0X710);
    // 0x8008E944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008E948:
    // 0x8008E948: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8008E94C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8008E950: beq         $s5, $a0, L_8008E984
    if (ctx->r21 == ctx->r4) {
        // 0x8008E954: addu        $s0, $s2, $t6
        ctx->r16 = ADD32(ctx->r18, ctx->r14);
            goto L_8008E984;
    }
    // 0x8008E954: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8008E958: jal         0x8009C6D4
    // 0x8008E95C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_9;
    // 0x8008E95C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_9:
    // 0x8008E960: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8008E964: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008E968: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008E96C: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x8008E970: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8008E974: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8008E978: addu        $s0, $s2, $t9
    ctx->r16 = ADD32(ctx->r18, ctx->r25);
    // 0x8008E97C: b           L_8008E988
    // 0x8008E980: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_8008E988;
    // 0x8008E980: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_8008E984:
    // 0x8008E984: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8008E988:
    // 0x8008E988: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x8008E98C: nop

    // 0x8008E990: beq         $s5, $a0, L_8008E9BC
    if (ctx->r21 == ctx->r4) {
        // 0x8008E994: nop
    
            goto L_8008E9BC;
    }
    // 0x8008E994: nop

    // 0x8008E998: jal         0x8009C6D4
    // 0x8008E99C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    menu_asset_load(rdram, ctx);
        goto after_10;
    // 0x8008E99C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_10:
    // 0x8008E9A0: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8008E9A4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8008E9A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008E9AC: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x8008E9B0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8008E9B4: b           L_8008E9C0
    // 0x8008E9B8: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_8008E9C0;
    // 0x8008E9B8: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_8008E9BC:
    // 0x8008E9BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8008E9C0:
    // 0x8008E9C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008E9C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008E9C8: bne         $a1, $at, L_8008E948
    if (ctx->r5 != ctx->r1) {
        // 0x8008E9CC: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_8008E948;
    }
    // 0x8008E9CC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8008E9D0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8008E9D4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8008E9D8: jal         0x80070C9C
    // 0x8008E9DC: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8008E9DC: addiu       $a0, $zero, 0xB40
    ctx->r4 = ADD32(0, 0XB40);
    after_11:
    // 0x8008E9E0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E9E4: addiu       $a1, $a1, 0x970
    ctx->r5 = ADD32(ctx->r5, 0X970);
    // 0x8008E9E8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008E9EC: addiu       $t3, $v0, 0x280
    ctx->r11 = ADD32(ctx->r2, 0X280);
    // 0x8008E9F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E9F4: sw          $t3, 0x974($at)
    MEM_W(0X974, ctx->r1) = ctx->r11;
    // 0x8008E9F8: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x8008E9FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EA00: addiu       $t5, $t4, 0x280
    ctx->r13 = ADD32(ctx->r12, 0X280);
    // 0x8008EA04: sw          $t5, 0x968($at)
    MEM_W(0X968, ctx->r1) = ctx->r13;
    // 0x8008EA08: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008EA0C: lw          $t6, 0x968($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X968);
    // 0x8008EA10: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008EA14: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008EA18: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8008EA1C: sw          $t7, 0x96C($at)
    MEM_W(0X96C, ctx->r1) = ctx->r15;
    // 0x8008EA20: addiu       $a0, $zero, -0xA0
    ctx->r4 = ADD32(0, -0XA0);
    // 0x8008EA24: addiu       $t0, $t0, 0x970
    ctx->r8 = ADD32(ctx->r8, 0X970);
    // 0x8008EA28: addiu       $v1, $v1, 0x968
    ctx->r3 = ADD32(ctx->r3, 0X968);
    // 0x8008EA2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008EA30: addiu       $a3, $zero, 0x320
    ctx->r7 = ADD32(0, 0X320);
    // 0x8008EA34: addiu       $a2, $zero, -0x400
    ctx->r6 = ADD32(0, -0X400);
    // 0x8008EA38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008EA3C:
    // 0x8008EA3C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA40: nop

    // 0x8008EA44: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EA48: sh          $a0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r4;
    // 0x8008EA4C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA50: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EA54: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EA58: sh          $a2, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r6;
    // 0x8008EA5C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA60: nop

    // 0x8008EA64: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EA68: sb          $a1, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r5;
    // 0x8008EA6C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA70: nop

    // 0x8008EA74: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EA78: sb          $a1, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r5;
    // 0x8008EA7C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA80: nop

    // 0x8008EA84: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EA88: sb          $a1, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r5;
    // 0x8008EA8C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EA90: nop

    // 0x8008EA94: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EA98: sh          $a0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r4;
    // 0x8008EA9C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAA0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EAA4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EAA8: sh          $a2, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r6;
    // 0x8008EAAC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAB0: nop

    // 0x8008EAB4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008EAB8: sb          $a1, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r5;
    // 0x8008EABC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAC0: nop

    // 0x8008EAC4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008EAC8: sb          $a1, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r5;
    // 0x8008EACC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAD0: nop

    // 0x8008EAD4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EAD8: sb          $a1, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r5;
    // 0x8008EADC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAE0: nop

    // 0x8008EAE4: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EAE8: sh          $a0, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r4;
    // 0x8008EAEC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EAF0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EAF4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EAF8: sh          $a2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r6;
    // 0x8008EAFC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB00: nop

    // 0x8008EB04: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EB08: sb          $a1, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r5;
    // 0x8008EB0C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB10: nop

    // 0x8008EB14: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EB18: sb          $a1, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r5;
    // 0x8008EB1C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB20: nop

    // 0x8008EB24: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EB28: sb          $a1, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r5;
    // 0x8008EB2C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB30: nop

    // 0x8008EB34: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EB38: sh          $a0, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r4;
    // 0x8008EB3C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB40: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8008EB44: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008EB48: sh          $a2, 0x22($t5)
    MEM_H(0X22, ctx->r13) = ctx->r6;
    // 0x8008EB4C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB50: nop

    // 0x8008EB54: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008EB58: sb          $a1, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r5;
    // 0x8008EB5C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB60: nop

    // 0x8008EB64: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EB68: sb          $a1, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r5;
    // 0x8008EB6C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8008EB70: nop

    // 0x8008EB74: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8008EB78: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8008EB7C: bne         $v0, $a3, L_8008EA3C
    if (ctx->r2 != ctx->r7) {
        // 0x8008EB80: sb          $a1, 0x26($t2)
        MEM_B(0X26, ctx->r10) = ctx->r5;
            goto L_8008EA3C;
    }
    // 0x8008EB80: sb          $a1, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r5;
    // 0x8008EB84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EB88: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008EB8C: bne         $at, $zero, L_8008EA3C
    if (ctx->r1 != 0) {
        // 0x8008EB90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008EA3C;
    }
    // 0x8008EB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008EB94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008EB98: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008EB9C: addiu       $t0, $t0, 0x978
    ctx->r8 = ADD32(ctx->r8, 0X978);
    // 0x8008EBA0: addiu       $v1, $v1, 0x970
    ctx->r3 = ADD32(ctx->r3, 0X970);
    // 0x8008EBA4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8008EBA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008EBAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008EBB0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8008EBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008EBB8:
    // 0x8008EBB8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8008EBBC: nop

    // 0x8008EBC0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8008EBC4: sb          $a0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r4;
    // 0x8008EBC8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8008EBCC: nop

    // 0x8008EBD0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8008EBD4: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x8008EBD8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8008EBDC: nop

    // 0x8008EBE0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8008EBE4: sb          $a1, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r5;
    // 0x8008EBE8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008EBEC: nop

    // 0x8008EBF0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8008EBF4: sb          $a2, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r6;
    // 0x8008EBF8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8008EBFC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008EC00: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8008EC04: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x8008EC08: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008EC0C: nop

    // 0x8008EC10: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8008EC14: sb          $a2, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r6;
    // 0x8008EC18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008EC1C: nop

    // 0x8008EC20: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008EC24: sb          $a1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r5;
    // 0x8008EC28: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008EC2C: nop

    // 0x8008EC30: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008EC34: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008EC38: slti        $at, $v0, 0x280
    ctx->r1 = SIGNED(ctx->r2) < 0X280 ? 1 : 0;
    // 0x8008EC3C: bne         $at, $zero, L_8008EBB8
    if (ctx->r1 != 0) {
        // 0x8008EC40: sb          $a3, 0x3($t9)
        MEM_B(0X3, ctx->r25) = ctx->r7;
            goto L_8008EBB8;
    }
    // 0x8008EC40: sb          $a3, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r7;
    // 0x8008EC44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8008EC48: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8008EC4C: bne         $at, $zero, L_8008EBB8
    if (ctx->r1 != 0) {
        // 0x8008EC50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008EBB8;
    }
    // 0x8008EC50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008EC54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EC58: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8008EC5C: sw          $zero, 0x6924($at)
    MEM_W(0X6924, ctx->r1) = 0;
    // 0x8008EC60: jal         0x80078AAC
    // 0x8008EC64: addiu       $a0, $a0, -0x9E8
    ctx->r4 = ADD32(ctx->r4, -0X9E8);
    bgdraw_set_func(rdram, ctx);
        goto after_12;
    // 0x8008EC64: addiu       $a0, $a0, -0x9E8
    ctx->r4 = ADD32(ctx->r4, -0X9E8);
    after_12:
    // 0x8008EC68: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8008EC6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008EC70: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8008EC74: addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // 0x8008EC78: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008EC7C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8008EC80: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8008EC84: jal         0x80066940
    // 0x8008EC88: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    viewport_menu_set(rdram, ctx);
        goto after_13;
    // 0x8008EC88: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    after_13:
    // 0x8008EC8C: jal         0x80066610
    // 0x8008EC90: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_14;
    // 0x8008EC90: nop

    after_14:
    // 0x8008EC94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008EC98: jal         0x80066818
    // 0x8008EC9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_15;
    // 0x8008EC9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008ECA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008ECA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ECA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008ECAC: sw          $t2, 0x97C($at)
    MEM_W(0X97C, ctx->r1) = ctx->r10;
    // 0x8008ECB0: jal         0x8009C674
    // 0x8008ECB4: addiu       $a0, $a0, 0x7C4
    ctx->r4 = ADD32(ctx->r4, 0X7C4);
    menu_assetgroup_load(rdram, ctx);
        goto after_16;
    // 0x8008ECB4: addiu       $a0, $a0, 0x7C4
    ctx->r4 = ADD32(ctx->r4, 0X7C4);
    after_16:
    // 0x8008ECB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008ECBC: jal         0x8009C8A4
    // 0x8008ECC0: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    menu_imagegroup_load(rdram, ctx);
        goto after_17;
    // 0x8008ECC0: addiu       $a0, $a0, 0x7E0
    ctx->r4 = ADD32(ctx->r4, 0X7E0);
    after_17:
    // 0x8008ECC4: jal         0x8008E4B0
    // 0x8008ECC8: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_18;
    // 0x8008ECC8: nop

    after_18:
    // 0x8008ECCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008ECD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008ECD4: addiu       $v1, $v1, 0x5F4
    ctx->r3 = ADD32(ctx->r3, 0X5F4);
    // 0x8008ECD8: addiu       $v0, $v0, 0x5D4
    ctx->r2 = ADD32(ctx->r2, 0X5D4);
    // 0x8008ECDC: lw          $t3, 0x20($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X20);
    // 0x8008ECE0: lw          $t4, 0x24($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X24);
    // 0x8008ECE4: lw          $t5, 0x28($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X28);
    // 0x8008ECE8: lw          $t6, 0x2C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X2C);
    // 0x8008ECEC: lw          $t7, 0x30($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X30);
    // 0x8008ECF0: lw          $t8, 0x34($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X34);
    // 0x8008ECF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008ECF8: addiu       $t9, $t9, 0x68E8
    ctx->r25 = ADD32(ctx->r25, 0X68E8);
    // 0x8008ECFC: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8008ED00: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8008ED04: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008ED08: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8008ED0C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8008ED10: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8008ED14: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8008ED18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008ED1C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8008ED20: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
L_8008ED24:
    // 0x8008ED24: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8008ED28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008ED2C: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_8008ED30:
    // 0x8008ED30: bne         $s1, $zero, L_8008ED60
    if (ctx->r17 != 0) {
        // 0x8008ED34: sh          $s5, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r21;
            goto L_8008ED60;
    }
    // 0x8008ED34: sh          $s5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r21;
    // 0x8008ED38: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008ED3C: beq         $at, $zero, L_8008ED64
    if (ctx->r1 == 0) {
        // 0x8008ED40: slti        $at, $s1, 0x4
        ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
            goto L_8008ED64;
    }
    // 0x8008ED40: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8008ED44: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008ED48: mflo        $t1
    ctx->r9 = lo;
    // 0x8008ED4C: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008ED50: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008ED54: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008ED58: b           L_8008EE84
    // 0x8008ED5C: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
        goto L_8008EE84;
    // 0x8008ED5C: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008ED60:
    // 0x8008ED60: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
L_8008ED64:
    // 0x8008ED64: beq         $at, $zero, L_8008EDB4
    if (ctx->r1 == 0) {
        // 0x8008ED68: nop
    
            goto L_8008EDB4;
    }
    // 0x8008ED68: nop

    // 0x8008ED6C: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008ED70: mflo        $t5
    ctx->r13 = lo;
    // 0x8008ED74: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8008ED78: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x8008ED7C: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x8008ED80: nop

    // 0x8008ED84: beq         $s5, $v0, L_8008EE84
    if (ctx->r21 == ctx->r2) {
        // 0x8008ED88: nop
    
            goto L_8008EE84;
    }
    // 0x8008ED88: nop

    // 0x8008ED8C: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x8008ED90: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8008ED94: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8008ED98: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008ED9C: nop

    // 0x8008EDA0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8008EDA4: beq         $t3, $zero, L_8008EE84
    if (ctx->r11 == 0) {
        // 0x8008EDA8: nop
    
            goto L_8008EE84;
    }
    // 0x8008EDA8: nop

    // 0x8008EDAC: b           L_8008EE84
    // 0x8008EDB0: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
        goto L_8008EE84;
    // 0x8008EDB0: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8008EDB4:
    // 0x8008EDB4: bne         $s1, $s6, L_8008EE4C
    if (ctx->r17 != ctx->r22) {
        // 0x8008EDB8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8008EE4C;
    }
    // 0x8008EDB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008EDBC: sll         $a2, $s3, 2
    ctx->r6 = S32(ctx->r19 << 2);
    // 0x8008EDC0: subu        $a2, $a2, $s3
    ctx->r6 = SUB32(ctx->r6, ctx->r19);
    // 0x8008EDC4: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8008EDC8: addu        $v0, $a2, $s7
    ctx->r2 = ADD32(ctx->r6, ctx->r23);
    // 0x8008EDCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008EDD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008EDD4:
    // 0x8008EDD4: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8008EDD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008EDDC: beq         $s5, $v1, L_8008EE08
    if (ctx->r21 == ctx->r3) {
        // 0x8008EDE0: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8008EE08;
    }
    // 0x8008EDE0: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008EDE4: lw          $t4, 0x4($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4);
    // 0x8008EDE8: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8008EDEC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8008EDF0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008EDF4: nop

    // 0x8008EDF8: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x8008EDFC: bne         $s0, $t8, L_8008EE08
    if (ctx->r16 != ctx->r24) {
        // 0x8008EE00: nop
    
            goto L_8008EE08;
    }
    // 0x8008EE00: nop

    // 0x8008EE04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8008EE08:
    // 0x8008EE08: bne         $at, $zero, L_8008EDD4
    if (ctx->r1 != 0) {
        // 0x8008EE0C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008EDD4;
    }
    // 0x8008EE0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008EE10: bne         $a1, $s6, L_8008EE38
    if (ctx->r5 != ctx->r22) {
        // 0x8008EE14: addu        $t3, $a2, $s1
        ctx->r11 = ADD32(ctx->r6, ctx->r17);
            goto L_8008EE38;
    }
    // 0x8008EE14: addu        $t3, $a2, $s1
    ctx->r11 = ADD32(ctx->r6, ctx->r17);
    // 0x8008EE18: beq         $s3, $s6, L_8008EE38
    if (ctx->r19 == ctx->r22) {
        // 0x8008EE1C: addiu       $t9, $zero, 0x82
        ctx->r25 = ADD32(0, 0X82);
            goto L_8008EE38;
    }
    // 0x8008EE1C: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x8008EE20: lhu         $t1, 0xC($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0XC);
    // 0x8008EE24: sllv        $v0, $t9, $s3
    ctx->r2 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x8008EE28: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x8008EE2C: beq         $v0, $t2, L_8008EE38
    if (ctx->r2 == ctx->r10) {
        // 0x8008EE30: nop
    
            goto L_8008EE38;
    }
    // 0x8008EE30: nop

    // 0x8008EE34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008EE38:
    // 0x8008EE38: bne         $a1, $s6, L_8008EE84
    if (ctx->r5 != ctx->r22) {
        // 0x8008EE3C: addu        $t4, $t3, $s7
        ctx->r12 = ADD32(ctx->r11, ctx->r23);
            goto L_8008EE84;
    }
    // 0x8008EE3C: addu        $t4, $t3, $s7
    ctx->r12 = ADD32(ctx->r11, ctx->r23);
    // 0x8008EE40: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x8008EE44: b           L_8008EE84
    // 0x8008EE48: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
        goto L_8008EE84;
    // 0x8008EE48: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
L_8008EE4C:
    // 0x8008EE4C: bne         $s1, $at, L_8008EE84
    if (ctx->r17 != ctx->r1) {
        // 0x8008EE50: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008EE84;
    }
    // 0x8008EE50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008EE54: lhu         $t6, 0x8($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X8);
    // 0x8008EE58: sllv        $t8, $t7, $fp
    ctx->r24 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x8008EE5C: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x8008EE60: beq         $t9, $zero, L_8008EE84
    if (ctx->r25 == 0) {
        // 0x8008EE64: nop
    
            goto L_8008EE84;
    }
    // 0x8008EE64: nop

    // 0x8008EE68: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EE6C: mflo        $t1
    ctx->r9 = lo;
    // 0x8008EE70: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008EE74: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x8008EE78: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008EE7C: nop

    // 0x8008EE80: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
L_8008EE84:
    // 0x8008EE84: jal         0x8009EC60
    // 0x8008EE88: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_19;
    // 0x8008EE88: nop

    after_19:
    // 0x8008EE8C: beq         $v0, $zero, L_8008EEB0
    if (ctx->r2 == 0) {
        // 0x8008EE90: nop
    
            goto L_8008EEB0;
    }
    // 0x8008EE90: nop

    // 0x8008EE94: multu       $s3, $s0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008EE98: mflo        $t5
    ctx->r13 = lo;
    // 0x8008EE9C: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8008EEA0: addu        $t6, $t7, $s7
    ctx->r14 = ADD32(ctx->r15, ctx->r23);
    // 0x8008EEA4: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x8008EEA8: nop

    // 0x8008EEAC: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
L_8008EEB0:
    // 0x8008EEB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008EEB4: bne         $s1, $s0, L_8008ED30
    if (ctx->r17 != ctx->r16) {
        // 0x8008EEB8: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8008ED30;
    }
    // 0x8008EEB8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008EEBC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8008EEC0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008EEC4: addiu       $t1, $t9, 0xC
    ctx->r9 = ADD32(ctx->r25, 0XC);
    // 0x8008EEC8: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8008EECC: bne         $fp, $at, L_8008ED24
    if (ctx->r30 != ctx->r1) {
        // 0x8008EED0: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_8008ED24;
    }
    // 0x8008EED0: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8008EED4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008EED8: lw          $v0, 0x69CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69CC);
    // 0x8008EEDC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008EEE0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8008EEE4: lw          $t4, 0x69C8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X69C8);
    // 0x8008EEE8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008EEEC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008EEF0: addiu       $a3, $a3, 0x68E8
    ctx->r7 = ADD32(ctx->r7, 0X68E8);
    // 0x8008EEF4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008EEF8: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8008EEFC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008EF00: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8008EF04: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x8008EF08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008EF0C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008EF10: addiu       $s0, $s0, -0xB38
    ctx->r16 = ADD32(ctx->r16, -0XB38);
    // 0x8008EF14: addiu       $v1, $v1, -0xB3C
    ctx->r3 = ADD32(ctx->r3, -0XB3C);
    // 0x8008EF18: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008EF1C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8008EF20: bne         $s5, $t6, L_8008EF5C
    if (ctx->r21 != ctx->r14) {
        // 0x8008EF24: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8008EF5C;
    }
    // 0x8008EF24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008EF28: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x8008EF2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008EF30: addiu       $v0, $v0, 0x63D0
    ctx->r2 = ADD32(ctx->r2, 0X63D0);
    // 0x8008EF34: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008EF38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008EF3C: jal         0x8006E2E8
    // 0x8008EF40: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    load_level_for_menu(rdram, ctx);
        goto after_20;
    // 0x8008EF40: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_20:
    // 0x8008EF44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008EF48: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8008EF4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EF50: sw          $zero, 0x69F4($at)
    MEM_W(0X69F4, ctx->r1) = 0;
    // 0x8008EF54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EF58: sw          $zero, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = 0;
L_8008EF5C:
    // 0x8008EF5C: jal         0x800C5494
    // 0x8008EF60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_21;
    // 0x8008EF60: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_21:
    // 0x8008EF64: jal         0x8007FFEC
    // 0x8008EF68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_22;
    // 0x8008EF68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x8008EF6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EF70: sw          $zero, 0x6840($at)
    MEM_W(0X6840, ctx->r1) = 0;
    // 0x8008EF74: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008EF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EF7C: addiu       $s0, $s0, -0x8A0
    ctx->r16 = ADD32(ctx->r16, -0X8A0);
    // 0x8008EF80: sw          $zero, 0x6848($at)
    MEM_W(0X6848, ctx->r1) = 0;
    // 0x8008EF84: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8008EF88: jal         0x80000BE0
    // 0x8008EF8C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_23;
    // 0x8008EF8C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_23:
    // 0x8008EF90: jal         0x80000C1C
    // 0x8008EF94: nop

    music_voicelimit_change_off(rdram, ctx);
        goto after_24;
    // 0x8008EF94: nop

    after_24:
    // 0x8008EF98: jal         0x80000B34
    // 0x8008EF9C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_25;
    // 0x8008EF9C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_25:
    // 0x8008EFA0: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x8008EFA4: jal         0x80001990
    // 0x8008EFA8: nop

    music_volume_set(rdram, ctx);
        goto after_26;
    // 0x8008EFA8: nop

    after_26:
    // 0x8008EFAC: jal         0x80000B18
    // 0x8008EFB0: nop

    music_change_off(rdram, ctx);
        goto after_27;
    // 0x8008EFB0: nop

    after_27:
    // 0x8008EFB4: jal         0x8006F564
    // 0x8008EFB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_28;
    // 0x8008EFB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x8008EFBC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008EFC0: lw          $t4, 0x418($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X418);
    // 0x8008EFC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008EFC8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008EFCC: lw          $t3, 0x410($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X410);
    // 0x8008EFD0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008EFD4: sw          $t4, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r12;
    // 0x8008EFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008EFDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008EFE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008EFE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008EFE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EFEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008EFF0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008EFF4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008EFF8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008EFFC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008F000: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 1U, dkr_legacy_fields, 0U); }
    // 0x8008F004: jr          $ra
    // 0x8008F008: sw          $t3, 0x6548($at)
    MEM_W(0X6548, ctx->r1) = ctx->r11;
    return;
    // 0x8008F008: sw          $t3, 0x6548($at)
    MEM_W(0X6548, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void debug_text_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B695C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800B6960: xor         $t6, $a1, $a3
    ctx->r14 = ctx->r5 ^ ctx->r7;
    // 0x800B6964: xor         $t8, $a2, $t7
    ctx->r24 = ctx->r6 ^ ctx->r15;
    // 0x800B6968: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B696C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800B6970: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B6974: bne         $t9, $zero, L_800B69F4
    if (ctx->r25 != 0) {
        // 0x800B6978: sltiu       $at, $a1, 0x2
        ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
            goto L_800B69F4;
    }
    // 0x800B6978: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x800B697C: bne         $at, $zero, L_800B6988
    if (ctx->r1 != 0) {
        // 0x800B6980: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_800B6988;
    }
    // 0x800B6980: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800B6984: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
L_800B6988:
    // 0x800B6988: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B698C: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x800B6990: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800B6994: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800B6998: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x800B699C: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x800B69A0: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x800B69A4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B69A8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800B69AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B69B0: andi        $t5, $a3, 0x3FF
    ctx->r13 = ctx->r7 & 0X3FF;
    // 0x800B69B4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800B69B8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B69BC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800B69C0: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800B69C4: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800B69C8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800B69CC: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x800B69D0: andi        $t3, $a1, 0x3FF
    ctx->r11 = ctx->r5 & 0X3FF;
    // 0x800B69D4: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800B69D8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800B69DC: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B69E0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800B69E4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B69E8: or          $t2, $t6, $t1
    ctx->r10 = ctx->r14 | ctx->r9;
    // 0x800B69EC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B69F0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_800B69F4:
    // 0x800B69F4: jr          $ra
    // 0x800B69F8: nop

    return;
    // 0x800B69F8: nop

;}
RECOMP_FUNC void menu_title_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800839E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800839EC: jal         0x80069D20
    // 0x800839F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800839F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800839F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800839F8: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x800839FC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80083A00: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80083A04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80083A08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80083A0C: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x80083A10: jal         0x8008E4EC
    // 0x80083A14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    menu_input(rdram, ctx);
        goto after_1;
    // 0x80083A14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x80083A18: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80083A1C: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80083A20: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80083A24: bne         $t1, $zero, L_80083A50
    if (ctx->r9 != 0) {
        // 0x80083A28: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083A50;
    }
    // 0x80083A28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083A2C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083A30: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80083A34: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80083A38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083A40: nop

    // 0x80083A44: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80083A48: b           L_80083A6C
    // 0x80083A4C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_80083A6C;
    // 0x80083A4C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
L_80083A50:
    // 0x80083A50: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80083A54: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80083A58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80083A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80083A60: nop

    // 0x80083A64: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80083A68: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80083A6C:
    // 0x80083A6C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80083A70: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80083A74: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80083A78: beq         $at, $zero, L_80083A98
    if (ctx->r1 == 0) {
        // 0x80083A7C: nop
    
            goto L_80083A98;
    }
    // 0x80083A7C: nop

    // 0x80083A80: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80083A84: jal         0x8008377C
    // 0x80083A88: nop

    render_title_screen(rdram, ctx);
        goto after_2;
    // 0x80083A88: nop

    after_2:
    // 0x80083A8C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083A90: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80083A94: nop

L_80083A98:
    // 0x80083A98: beq         $v0, $zero, L_80083AB0
    if (ctx->r2 == 0) {
        // 0x80083A9C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80083AB0;
    }
    // 0x80083A9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083AA0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083AA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083AA8: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80083AAC: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
L_80083AB0:
    // 0x80083AB0: addiu       $t0, $t0, 0x6864
    ctx->r8 = ADD32(ctx->r8, 0X6864);
    // 0x80083AB4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083AB8: lw          $v0, 0x6874($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6874);
    // 0x80083ABC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80083AC0: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x80083AC4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80083AC8: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80083ACC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083AD0: bne         $t8, $t9, L_80083AF0
    if (ctx->r24 != ctx->r25) {
        // 0x80083AD4: addiu       $a3, $a3, 0x6868
        ctx->r7 = ADD32(ctx->r7, 0X6868);
            goto L_80083AF0;
    }
    // 0x80083AD4: addiu       $a3, $a3, 0x6868
    ctx->r7 = ADD32(ctx->r7, 0X6868);
    // 0x80083AD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083ADC: lw          $t1, 0x63D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63D8);
    // 0x80083AE0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083AE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80083AEC: sw          $t3, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r11;
L_80083AF0:
    // 0x80083AF0: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083AF8: blez        $v1, L_80083B70
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80083AFC: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80083B70;
    }
    // 0x80083AFC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083B00: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80083B04: nop

    // 0x80083B08: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x80083B0C: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x80083B10: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083B14: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80083B18: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x80083B1C: beq         $at, $zero, L_80083B58
    if (ctx->r1 == 0) {
        // 0x80083B20: addu        $t7, $v1, $t6
        ctx->r15 = ADD32(ctx->r3, ctx->r14);
            goto L_80083B58;
    }
    // 0x80083B20: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80083B24: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80083B28: bne         $at, $zero, L_80083B58
    if (ctx->r1 != 0) {
        // 0x80083B2C: addiu       $a0, $zero, -0x300
        ctx->r4 = ADD32(0, -0X300);
            goto L_80083B58;
    }
    // 0x80083B2C: addiu       $a0, $zero, -0x300
    ctx->r4 = ADD32(0, -0X300);
    // 0x80083B30: jal         0x80000C98
    // 0x80083B34: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80083B34: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_3:
    // 0x80083B38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083B3C: jal         0x800C01D8
    // 0x80083B40: addiu       $a0, $a0, 0x1E08
    ctx->r4 = ADD32(ctx->r4, 0X1E08);
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x80083B40: addiu       $a0, $a0, 0x1E08
    ctx->r4 = ADD32(ctx->r4, 0X1E08);
    after_4:
    // 0x80083B44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083B48: addiu       $a3, $a3, 0x6868
    ctx->r7 = ADD32(ctx->r7, 0X6868);
    // 0x80083B4C: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x80083B50: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083B54: nop

L_80083B58:
    // 0x80083B58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083B5C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80083B60: bgtz        $v1, L_80083B7C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80083B64: nop
    
            goto L_80083B7C;
    }
    // 0x80083B64: nop

    // 0x80083B68: b           L_80083B7C
    // 0x80083B6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80083B7C;
    // 0x80083B6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80083B70:
    // 0x80083B70: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80083B74: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80083B78: nop

L_80083B7C:
    // 0x80083B7C: bne         $v0, $zero, L_80083C7C
    if (ctx->r2 != 0) {
        // 0x80083B80: nop
    
            goto L_80083C7C;
    }
    // 0x80083B80: nop

    // 0x80083B84: jal         0x800214C4
    // 0x80083B88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800214C4(rdram, ctx);
        goto after_5;
    // 0x80083B88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    extern void dkr_title_intro_audio_tail(uint8_t*, recomp_context*); dkr_title_intro_audio_tail(rdram, ctx);
    // 0x80083B8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083B90: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80083B94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083B98: addiu       $t0, $t0, 0x6864
    ctx->r8 = ADD32(ctx->r8, 0X6864);
    // 0x80083B9C: bne         $v0, $zero, L_80083BAC
    if (ctx->r2 != 0) {
        // 0x80083BA0: addiu       $a3, $a3, 0x6868
        ctx->r7 = ADD32(ctx->r7, 0X6868);
            goto L_80083BAC;
    }
    // 0x80083BA0: addiu       $a3, $a3, 0x6868
    ctx->r7 = ADD32(ctx->r7, 0X6868);
    // 0x80083BA4: beq         $a2, $zero, L_80083C7C
    if (ctx->r6 == 0) {
        // 0x80083BA8: nop
    
            goto L_80083C7C;
    }
    // 0x80083BA8: nop

L_80083BAC:
    // 0x80083BAC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80083BB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083BB4: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80083BB8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80083BBC: lw          $v0, 0x6874($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6874);
    // 0x80083BC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083BC4: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80083BC8: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x80083BCC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80083BD0: bne         $t2, $at, L_80083BE0
    if (ctx->r10 != ctx->r1) {
        // 0x80083BD4: addiu       $t6, $zero, 0x5DC
        ctx->r14 = ADD32(0, 0X5DC);
            goto L_80083BE0;
    }
    // 0x80083BD4: addiu       $t6, $zero, 0x5DC
    ctx->r14 = ADD32(0, 0X5DC);
    // 0x80083BD8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80083BDC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80083BE0:
    // 0x80083BE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083BE4: addiu       $v0, $v0, 0x686C
    ctx->r2 = ADD32(ctx->r2, 0X686C);
    // 0x80083BE8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80083BEC: nop

    // 0x80083BF0: bne         $t4, $zero, L_80083BFC
    if (ctx->r12 != 0) {
        // 0x80083BF4: nop
    
            goto L_80083BFC;
    }
    // 0x80083BF4: nop

    // 0x80083BF8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80083BFC:
    // 0x80083BFC: lb          $a1, 0x1($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X1);
    // 0x80083C00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083C04: bne         $a1, $at, L_80083C14
    if (ctx->r5 != ctx->r1) {
        // 0x80083C08: sh          $zero, 0x0($a3)
        MEM_H(0X0, ctx->r7) = 0;
            goto L_80083C14;
    }
    // 0x80083C08: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80083C0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083C10: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
L_80083C14:
    // 0x80083C14: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80083C18: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80083C1C: jal         0x8006E2E8
    // 0x80083C20: nop

    load_level_for_menu(rdram, ctx);
        goto after_6;
    // 0x80083C20: nop

    after_6:
    // 0x80083C24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083C28: addiu       $t0, $t0, 0x6864
    ctx->r8 = ADD32(ctx->r8, 0X6864);
    // 0x80083C2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083C30: lw          $v0, 0x6874($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6874);
    // 0x80083C34: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80083C38: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x80083C3C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80083C40: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80083C44: nop

    // 0x80083C48: bne         $t9, $t1, L_80083C7C
    if (ctx->r25 != ctx->r9) {
        // 0x80083C4C: nop
    
            goto L_80083C7C;
    }
    // 0x80083C4C: nop

    // 0x80083C50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80083C54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083C58: swc1        $f8, 0x68D8($at)
    MEM_W(0X68D8, ctx->r1) = ctx->f8.u32l;
    // 0x80083C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083C60: sw          $zero, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = 0;
    // 0x80083C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083C68: sw          $zero, 0x68DC($at)
    MEM_W(0X68DC, ctx->r1) = 0;
    // 0x80083C6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083C70: sw          $zero, -0x60C($at)
    MEM_W(-0X60C, ctx->r1) = 0;
    // 0x80083C74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083C78: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
L_80083C7C:
    // 0x80083C7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083C80: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
    // 0x80083C84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80083C88: nop

    // 0x80083C8C: beq         $v0, $zero, L_80083DC4
    if (ctx->r2 == 0) {
        // 0x80083C90: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_80083DC4;
    }
    // 0x80083C90: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80083C94: beq         $at, $zero, L_80083D00
    if (ctx->r1 == 0) {
        // 0x80083C98: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80083D00;
    }
    // 0x80083C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80083C9C: bne         $v0, $at, L_80083CBC
    if (ctx->r2 != ctx->r1) {
        // 0x80083CA0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_80083CBC;
    }
    // 0x80083CA0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80083CA4: jal         0x80001D04
    // 0x80083CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x80083CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80083CAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083CB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083CB4: lw          $v0, 0x686C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X686C);
    // 0x80083CB8: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083CBC:
    // 0x80083CBC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80083CC0: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80083CC4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80083CC8: slti        $at, $t3, 0x20
    ctx->r1 = SIGNED(ctx->r11) < 0X20 ? 1 : 0;
    // 0x80083CCC: bne         $at, $zero, L_80083DC4
    if (ctx->r1 != 0) {
        // 0x80083CD0: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_80083DC4;
    }
    // 0x80083CD0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80083CD4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80083CD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083CDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80083CE0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80083CE4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80083CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083CEC: jal         0x80001D04
    // 0x80083CF0: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x80083CF0: swc1        $f10, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f10.u32l;
    after_8:
    // 0x80083CF4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083CF8: b           L_80083DC4
    // 0x80083CFC: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
        goto L_80083DC4;
    // 0x80083CFC: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083D00:
    // 0x80083D00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083D04: addiu       $v0, $v0, 0x6870
    ctx->r2 = ADD32(ctx->r2, 0X6870);
    // 0x80083D08: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80083D0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80083D10: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80083D14: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80083D18: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80083D1C: nop

    // 0x80083D20: bc1f        L_80083DC4
    if (!c1cs) {
        // 0x80083D24: nop
    
            goto L_80083DC4;
    }
    // 0x80083D24: nop

    // 0x80083D28: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80083D2C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083D30: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80083D34: lwc1        $f6, -0x7C50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C50);
    // 0x80083D38: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80083D3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083D40: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80083D44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083D48: bc1f        L_80083D80
    if (!c1cs) {
        // 0x80083D4C: nop
    
            goto L_80083D80;
    }
    // 0x80083D4C: nop

    // 0x80083D50: lw          $t7, 0x63E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63E0);
    // 0x80083D54: addiu       $a0, $zero, 0x105
    ctx->r4 = ADD32(0, 0X105);
    // 0x80083D58: bne         $t7, $zero, L_80083D80
    if (ctx->r15 != 0) {
        // 0x80083D5C: nop
    
            goto L_80083D80;
    }
    // 0x80083D5C: nop

    // 0x80083D60: jal         0x80001D04
    // 0x80083D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x80083D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80083D68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80083D6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083D70: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083D74: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
    // 0x80083D78: b           L_80083DC4
    // 0x80083D7C: sw          $t8, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r24;
        goto L_80083DC4;
    // 0x80083D7C: sw          $t8, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r24;
L_80083D80:
    // 0x80083D80: lwc1        $f8, -0x7C4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7C4C);
    // 0x80083D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80083D88: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80083D8C: nop

    // 0x80083D90: bc1f        L_80083DC4
    if (!c1cs) {
        // 0x80083D94: nop
    
            goto L_80083DC4;
    }
    // 0x80083D94: nop

    // 0x80083D98: lw          $t9, 0x63E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63E0);
    // 0x80083D9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80083DA0: bne         $t9, $at, L_80083DC4
    if (ctx->r25 != ctx->r1) {
        // 0x80083DA4: addiu       $a0, $zero, 0x106
        ctx->r4 = ADD32(0, 0X106);
            goto L_80083DC4;
    }
    // 0x80083DA4: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x80083DA8: jal         0x80001D04
    // 0x80083DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80083DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80083DB0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80083DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083DB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083DBC: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
    // 0x80083DC0: sw          $t1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r9;
L_80083DC4:
    // 0x80083DC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083DC8: lwc1        $f0, 0x6870($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6870);
    // 0x80083DCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80083DD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80083DD4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80083DD8: nop

    // 0x80083DDC: bc1f        L_80083F0C
    if (!c1cs) {
        // 0x80083DE0: nop
    
            goto L_80083F0C;
    }
    // 0x80083DE0: nop

    // 0x80083DE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80083DE8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80083DEC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80083DF0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80083DF4: bc1f        L_80083E54
    if (!c1cs) {
        // 0x80083DF8: nop
    
            goto L_80083E54;
    }
    // 0x80083DF8: nop

    // 0x80083DFC: lw          $t2, -0x8A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X8A0);
    // 0x80083E00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80083E04: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80083E08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083E0C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80083E10: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80083E14: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80083E18: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80083E1C: nop

    // 0x80083E20: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80083E24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083E28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083E2C: nop

    // 0x80083E30: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80083E34: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80083E38: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80083E3C: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x80083E40: jal         0x80001990
    // 0x80083E44: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    music_volume_set(rdram, ctx);
        goto after_11;
    // 0x80083E44: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_11:
    // 0x80083E48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083E4C: b           L_80083F0C
    // 0x80083E50: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
        goto L_80083F0C;
    // 0x80083E50: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083E54:
    // 0x80083E54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80083E58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083E5C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80083E60: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80083E64: bc1f        L_80083E8C
    if (!c1cs) {
        // 0x80083E68: nop
    
            goto L_80083E8C;
    }
    // 0x80083E68: nop

    // 0x80083E6C: lw          $a0, -0x8A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X8A0);
    // 0x80083E70: nop

    // 0x80083E74: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80083E78: jal         0x80001990
    // 0x80083E7C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_12;
    // 0x80083E7C: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    after_12:
    // 0x80083E80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083E84: b           L_80083F0C
    // 0x80083E88: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
        goto L_80083F0C;
    // 0x80083E88: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083E8C:
    // 0x80083E8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083E90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80083E94: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80083E98: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80083E9C: bc1f        L_80083EF8
    if (!c1cs) {
        // 0x80083EA0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80083EF8;
    }
    // 0x80083EA0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083EA4: lw          $t7, -0x8A0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X8A0);
    // 0x80083EA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083EAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80083EB0: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80083EB4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80083EB8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80083EBC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80083EC0: nop

    // 0x80083EC4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80083EC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083ECC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083ED0: nop

    // 0x80083ED4: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80083ED8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80083EDC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80083EE0: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80083EE4: jal         0x80001990
    // 0x80083EE8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    music_volume_set(rdram, ctx);
        goto after_13;
    // 0x80083EE8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_13:
    // 0x80083EEC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083EF0: b           L_80083F0C
    // 0x80083EF4: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
        goto L_80083F0C;
    // 0x80083EF4: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083EF8:
    // 0x80083EF8: lbu         $a0, -0x89D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X89D);
    // 0x80083EFC: jal         0x80001990
    // 0x80083F00: nop

    music_volume_set(rdram, ctx);
        goto after_14;
    // 0x80083F00: nop

    after_14:
    // 0x80083F04: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083F08: addiu       $v1, $v1, 0x686C
    ctx->r3 = ADD32(ctx->r3, 0X686C);
L_80083F0C:
    // 0x80083F0C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80083F10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083F14: bne         $t1, $zero, L_80083F3C
    if (ctx->r9 != 0) {
        // 0x80083F18: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80083F3C;
    }
    // 0x80083F18: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80083F1C: addiu       $v0, $v0, 0x67D8
    ctx->r2 = ADD32(ctx->r2, 0X67D8);
    // 0x80083F20: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80083F24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80083F28: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80083F2C: beq         $t3, $zero, L_8008404C
    if (ctx->r11 == 0) {
        // 0x80083F30: nop
    
            goto L_8008404C;
    }
    // 0x80083F30: nop

    // 0x80083F34: b           L_8008404C
    // 0x80083F38: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_8008404C;
    // 0x80083F38: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80083F3C:
    // 0x80083F3C: lw          $t5, -0xB84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB84);
    // 0x80083F40: nop

    // 0x80083F44: bne         $t5, $zero, L_8008404C
    if (ctx->r13 != 0) {
        // 0x80083F48: nop
    
            goto L_8008404C;
    }
    // 0x80083F48: nop

    // 0x80083F4C: jal         0x8006F4C8
    // 0x80083F50: nop

    is_controller_missing(rdram, ctx);
        goto after_15;
    // 0x80083F50: nop

    after_15:
    // 0x80083F54: bne         $v0, $zero, L_8008404C
    if (ctx->r2 != 0) {
        // 0x80083F58: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008404C;
    }
    // 0x80083F58: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083F5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F60: lw          $v0, -0xBA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XBA4);
    // 0x80083F64: lh          $v1, 0x6838($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6838);
    // 0x80083F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083F6C: bgez        $v1, L_80083F90
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80083F70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80083F90;
    }
    // 0x80083F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80083F74: bgtz        $v0, L_80083F90
    if (SIGNED(ctx->r2) > 0) {
        // 0x80083F78: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80083F90;
    }
    // 0x80083F78: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80083F7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083F80: sw          $t6, -0xBA4($at)
    MEM_W(-0XBA4, ctx->r1) = ctx->r14;
    // 0x80083F84: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F88: lw          $v0, -0xBA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XBA4);
    // 0x80083F8C: nop

L_80083F90:
    // 0x80083F90: blez        $v1, L_80083FB4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80083F94: nop
    
            goto L_80083FB4;
    }
    // 0x80083F94: nop

    // 0x80083F98: blez        $v0, L_80083FB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80083F9C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80083FB4;
    }
    // 0x80083F9C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80083FA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083FA4: sw          $t7, -0xBA4($at)
    MEM_W(-0XBA4, ctx->r1) = ctx->r15;
    // 0x80083FA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083FAC: lw          $v0, -0xBA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XBA4);
    // 0x80083FB0: nop

L_80083FB4:
    // 0x80083FB4: beq         $a0, $v0, L_80083FC4
    if (ctx->r4 == ctx->r2) {
        // 0x80083FB8: nop
    
            goto L_80083FC4;
    }
    // 0x80083FB8: nop

    // 0x80083FBC: jal         0x80001D04
    // 0x80083FC0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x80083FC0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_16:
L_80083FC4:
    // 0x80083FC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083FC8: addiu       $v0, $v0, 0x67D8
    ctx->r2 = ADD32(ctx->r2, 0X67D8);
    // 0x80083FCC: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80083FD0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083FD4: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x80083FD8: beq         $t9, $zero, L_8008404C
    if (ctx->r25 == 0) {
        // 0x80083FDC: nop
    
            goto L_8008404C;
    }
    // 0x80083FDC: nop

    // 0x80083FE0: lw          $t1, 0x67E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X67E4);
    // 0x80083FE4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80083FE8: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x80083FEC: bne         $t2, $zero, L_80084018
    if (ctx->r10 != 0) {
        // 0x80083FF0: nop
    
            goto L_80084018;
    }
    // 0x80083FF0: nop

L_80083FF4:
    // 0x80083FF4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80083FF8: blez        $a2, L_80084018
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80083FFC: sll         $t3, $a2, 2
        ctx->r11 = S32(ctx->r6 << 2);
            goto L_80084018;
    }
    // 0x80083FFC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80084000: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80084004: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80084008: nop

    // 0x8008400C: andi        $t6, $t5, 0x9000
    ctx->r14 = ctx->r13 & 0X9000;
    // 0x80084010: beq         $t6, $zero, L_80083FF4
    if (ctx->r14 == 0) {
        // 0x80084014: nop
    
            goto L_80083FF4;
    }
    // 0x80084014: nop

L_80084018:
    // 0x80084018: jal         0x8008AF00
    // 0x8008401C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    titlescreen_controller_assign(rdram, ctx);
        goto after_17;
    // 0x8008401C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x80084020: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80084024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084028: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008402C: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
    // 0x80084030: jal         0x800C01D8
    // 0x80084034: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_18;
    // 0x80084034: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_18:
    // 0x80084038: jal         0x800C0170
    // 0x8008403C: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_19;
    // 0x8008403C: nop

    after_19:
    // 0x80084040: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80084044: jal         0x80001D04
    // 0x80084048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x80084048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
L_8008404C:
    // 0x8008404C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80084050: lw          $t8, -0xB84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB84);
    // 0x80084054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084058: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x8008405C: bne         $at, $zero, L_80084100
    if (ctx->r1 != 0) {
        // 0x80084060: nop
    
            goto L_80084100;
    }
    // 0x80084060: nop

    // 0x80084064: jal         0x80084118
    // 0x80084068: nop

    titlescreen_free(rdram, ctx);
        goto after_21;
    // 0x80084068: nop

    after_21:
    // 0x8008406C: jal         0x800C0180
    // 0x80084070: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x80084070: nop

    after_22:
    // 0x80084074: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80084078: lw          $t9, -0xBA4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XBA4);
    // 0x8008407C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084080: bne         $t9, $zero, L_800840E0
    if (ctx->r25 != 0) {
        // 0x80084084: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_800840E0;
    }
    // 0x80084084: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80084088: jal         0x8009ECD0
    // 0x8008408C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_23;
    // 0x8008408C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_23:
    // 0x80084090: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80084094: beq         $v0, $zero, L_800840A0
    if (ctx->r2 == 0) {
        // 0x80084098: nop
    
            goto L_800840A0;
    }
    // 0x80084098: nop

    // 0x8008409C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800840A0:
    // 0x800840A0: jal         0x8009ECB8
    // 0x800840A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_24;
    // 0x800840A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_24:
    // 0x800840A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800840AC: beq         $v0, $zero, L_800840BC
    if (ctx->r2 == 0) {
        // 0x800840B0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800840BC;
    }
    // 0x800840B0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800840B4: xori        $t1, $a2, 0x3
    ctx->r9 = ctx->r6 ^ 0X3;
    // 0x800840B8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
L_800840BC:
    // 0x800840BC: jal         0x8006E2E8
    // 0x800840C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_25;
    // 0x800840C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_25:
    // 0x800840C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800840C8: jal         0x8008AEB4
    // 0x800840CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_26;
    // 0x800840CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x800840D0: jal         0x800813D0
    // 0x800840D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_27;
    // 0x800840D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_27:
    // 0x800840D8: b           L_80084108
    // 0x800840DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084108;
    // 0x800840DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800840E0:
    // 0x800840E0: sw          $zero, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = 0;
    // 0x800840E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800840E8: jal         0x8006E2E8
    // 0x800840EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_28;
    // 0x800840EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x800840F0: jal         0x800813D0
    // 0x800840F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_29;
    // 0x800840F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_29:
    // 0x800840F8: b           L_80084108
    // 0x800840FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084108;
    // 0x800840FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084100:
    // 0x80084100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084104: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_80084108:
    // 0x80084108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008410C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80084110: jr          $ra
    // 0x80084114: nop

    return;
    // 0x80084114: nop

;}
RECOMP_FUNC void get_current_level_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002C7C8: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x8002C7CC: jr          $ra
    // 0x8002C7D0: nop

    return;
    // 0x8002C7D0: nop

;}
RECOMP_FUNC void racer_sound_doppler_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006BFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80006C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006C04: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80006C08: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80006C0C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80006C10: lw          $t6, 0x118($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X118);
    // 0x80006C14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80006C18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80006C1C: sw          $t6, -0x63C8($at)
    MEM_W(-0X63C8, ctx->r1) = ctx->r14;
    // 0x80006C20: lw          $t7, -0x63C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63C8);
    // 0x80006C24: nop

    // 0x80006C28: beq         $t7, $zero, L_80006FBC
    if (ctx->r15 == 0) {
        // 0x80006C2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006FBC;
    }
    // 0x80006C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006C30: beq         $a1, $zero, L_80006C6C
    if (ctx->r5 == 0) {
        // 0x80006C34: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80006C6C;
    }
    // 0x80006C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006C38: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80006C3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006C40: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80006C44: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80006C48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80006C4C: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80006C50: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80006C54: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80006C58: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80006C5C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80006C60: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80006C64: b           L_80006D84
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
        goto L_80006D84;
    // 0x80006C68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_80006C6C:
    // 0x80006C6C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80006C70: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80006C74: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80006C78: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80006C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006C80: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80006C84: lb          $v0, 0x1D6($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1D6);
    // 0x80006C88: nop

    // 0x80006C8C: beq         $v0, $zero, L_80006CA4
    if (ctx->r2 == 0) {
        // 0x80006C90: nop
    
            goto L_80006CA4;
    }
    // 0x80006C90: nop

    // 0x80006C94: beq         $v0, $at, L_80006CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80006C98: nop
    
            goto L_80006CD0;
    }
    // 0x80006C98: nop

    // 0x80006C9C: b           L_80006D0C
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
        goto L_80006D0C;
    // 0x80006CA0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006CA4:
    // 0x80006CA4: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80006CA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006CAC: nop

    // 0x80006CB0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80006CB4: nop

    // 0x80006CB8: bc1f        L_80006CC8
    if (!c1cs) {
        // 0x80006CBC: nop
    
            goto L_80006CC8;
    }
    // 0x80006CBC: nop

    // 0x80006CC0: b           L_80006D48
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CC4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006CC8:
    // 0x80006CC8: b           L_80006D48
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80006D48;
    // 0x80006CCC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80006CD0:
    // 0x80006CD0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80006CD4: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006CD8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006CDC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006CE0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006CE4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006CE8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006CEC: jal         0x800C9AD0
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80006CF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80006CF4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006CF8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006CFC: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D00: b           L_80006D48
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80006D48;
    // 0x80006D04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80006D08: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80006D0C:
    // 0x80006D0C: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006D10: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006D14: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80006D18: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80006D1C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80006D20: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006D24: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006D28: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006D2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006D30: jal         0x800C9AD0
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80006D34: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006D38: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006D3C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80006D40: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80006D44: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006D48:
    // 0x80006D48: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006D4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006D50: nop

    // 0x80006D54: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006D58: nop

    // 0x80006D5C: bc1f        L_80006D6C
    if (!c1cs) {
        // 0x80006D60: nop
    
            goto L_80006D6C;
    }
    // 0x80006D60: nop

    // 0x80006D64: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80006D68: nop

L_80006D6C:
    // 0x80006D6C: div.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80006D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006D74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006D78: nop

    // 0x80006D7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D80: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_80006D84:
    // 0x80006D84: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80006D88: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80006D8C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80006D90: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80006D94: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80006D98: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006D9C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80006DA0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006DA4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006DA8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80006DAC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80006DB0: nop

    // 0x80006DB4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006DB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006DBC: jal         0x800C9AD0
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80006DC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80006DC4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006DC8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80006DCC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80006DD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006DD4: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006DD8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80006DDC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80006DE0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80006DE4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80006DE8: lwc1        $f4, 0x6C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x80006DEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006DF0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80006DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006DF8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80006DFC: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80006E00: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80006E04: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80006E08: nop

    // 0x80006E0C: bc1f        L_80006E1C
    if (!c1cs) {
        // 0x80006E10: nop
    
            goto L_80006E1C;
    }
    // 0x80006E10: nop

    // 0x80006E14: b           L_80006E38
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_80006E38;
    // 0x80006E18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_80006E1C:
    // 0x80006E1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006E20: nop

    // 0x80006E24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006E28: nop

    // 0x80006E2C: bc1f        L_80006E38
    if (!c1cs) {
        // 0x80006E30: nop
    
            goto L_80006E38;
    }
    // 0x80006E30: nop

    // 0x80006E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80006E38:
    // 0x80006E38: lwc1        $f12, 0x5C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006E3C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80006E40: jal         0x80007FA4
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    log_recomp(rdram, ctx);
        goto after_3;
    // 0x80006E44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80006E48: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80006E4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80006E50: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80006E54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006E58: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80006E5C: lwc1        $f5, 0x4CA0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4CA0);
    // 0x80006E60: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80006E64: nop

    // 0x80006E68: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80006E6C: lwc1        $f4, 0x4CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4CA4);
    // 0x80006E70: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80006E74: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80006E78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80006E7C: nop

    // 0x80006E80: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80006E84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006E88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006E8C: nop

    // 0x80006E90: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80006E94: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80006E98: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80006E9C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80006EA0: nop

    // 0x80006EA4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006EA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80006EAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80006EB0: nop

    // 0x80006EB4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80006EB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80006EBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80006EC0: nop

    // 0x80006EC4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006EC8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80006ECC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80006ED0: jal         0x800C99E0
    // 0x80006ED4: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x80006ED4: nop

    after_4:
    // 0x80006ED8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006EDC: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006EE0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006EE4: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80006EE8: lwc1        $f2, 0x68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006EEC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80006EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006EF4: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80006EF8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80006EFC: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F04: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80006F08: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F10: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006F14: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80006F18: lwc1        $f10, 0x68($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F1C: nop

    // 0x80006F20: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80006F24: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    // 0x80006F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F2C: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006F30: lwc1        $f10, 0x4CAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4CAC);
    // 0x80006F34: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80006F38: lwc1        $f11, 0x4CA8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X4CA8);
    // 0x80006F3C: cvt.d.s     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f12.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F40: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80006F44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F48: bc1f        L_80006F70
    if (!c1cs) {
        // 0x80006F4C: nop
    
            goto L_80006F70;
    }
    // 0x80006F4C: nop

    // 0x80006F50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F54: lwc1        $f4, 0x4CB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4CB0);
    // 0x80006F58: nop

    // 0x80006F5C: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x80006F60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F64: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006F68: b           L_80006FA8
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
        goto L_80006FA8;
    // 0x80006F6C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006F70:
    // 0x80006F70: lwc1        $f7, 0x4CB8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X4CB8);
    // 0x80006F74: lwc1        $f6, 0x4CBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4CBC);
    // 0x80006F78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006F7C: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x80006F80: nop

    // 0x80006F84: bc1f        L_80006FA4
    if (!c1cs) {
        // 0x80006F88: nop
    
            goto L_80006FA4;
    }
    // 0x80006F88: nop

    // 0x80006F8C: lwc1        $f8, 0x4CC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4CC0);
    // 0x80006F90: nop

    // 0x80006F94: swc1        $f8, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f8.u32l;
    // 0x80006F98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006F9C: lw          $v0, -0x63C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C8);
    // 0x80006FA0: nop

L_80006FA4:
    // 0x80006FA4: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80006FA8:
    // 0x80006FA8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80006FAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80006FB0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80006FB4: swc1        $f10, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f10.u32l;
    // 0x80006FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006FBC:
    // 0x80006FBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006FC0: jr          $ra
    // 0x80006FC4: nop

    return;
    // 0x80006FC4: nop

;}
RECOMP_FUNC void spectate_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BDD8: lw          $v0, -0x5120($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5120);
    // 0x8001BDDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001BDE0: bne         $v0, $zero, L_8001BDF0
    if (ctx->r2 != 0) {
        // 0x8001BDE4: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8001BDF0;
    }
    // 0x8001BDE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001BDE8: b           L_8001BF18
    // 0x8001BDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001BF18;
    // 0x8001BDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BDF0:
    // 0x8001BDF0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001BDF4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001BDF8: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8001BDFC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BE00: bne         $at, $zero, L_8001BE0C
    if (ctx->r1 != 0) {
        // 0x8001BE04: addiu       $a2, $a0, -0x1
        ctx->r6 = ADD32(ctx->r4, -0X1);
            goto L_8001BE0C;
    }
    // 0x8001BE04: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8001BE08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001BE0C:
    // 0x8001BE0C: bgez        $a2, L_8001BE18
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8001BE10: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001BE18;
    }
    // 0x8001BE10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001BE14: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
L_8001BE18:
    // 0x8001BE18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BE1C: lw          $v0, -0x5124($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5124);
    // 0x8001BE20: lwc1        $f2, 0xC($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8001BE24: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8001BE28: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8001BE2C: lwc1        $f14, 0x10($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001BE30: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001BE34: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001BE38: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BE3C: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8001BE40: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BE44: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BE48: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001BE4C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001BE50: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BE54: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BE58: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8001BE5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001BE60: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BE64: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BE68: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001BE6C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001BE70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001BE74: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8001BE78: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8001BE7C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8001BE80: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8001BE84: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8001BE88: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001BE8C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BE90: sub.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8001BE94: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BE98: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BE9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001BEA0: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BEA4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001BEA8: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8001BEAC: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8001BEB0: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001BEB4: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001BEB8: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8001BEBC: lwc1        $f8, 0x14($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8001BEC0: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8001BEC4: bc1f        L_8001BEDC
    if (!c1cs) {
        // 0x8001BEC8: sub.s       $f16, $f8, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_8001BEDC;
    }
    // 0x8001BEC8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001BECC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8001BED0: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001BED4: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8001BED8: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8001BEDC:
    // 0x8001BEDC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001BEE0: nop

    // 0x8001BEE4: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001BEE8: nop

    // 0x8001BEEC: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001BEF0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001BEF4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001BEF8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001BEFC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001BF00: nop

    // 0x8001BF04: bc1f        L_8001BF14
    if (!c1cs) {
        // 0x8001BF08: nop
    
            goto L_8001BF14;
    }
    // 0x8001BF08: nop

    // 0x8001BF0C: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8001BF10: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_8001BF14:
    // 0x8001BF14: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8001BF18:
    // 0x8001BF18: jr          $ra
    // 0x8001BF1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001BF1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void audspat_line_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099EC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800099F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800099F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800099F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800099FC: addiu       $t8, $t8, -0x63A8
    ctx->r24 = ADD32(ctx->r24, -0X63A8);
    // 0x80009A00: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x80009A04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009A08: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009A0C: lb          $a3, 0x17C($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009A14: bgtz        $a3, L_80009A24
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009A18: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009A24;
    }
    // 0x80009A18: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009A1C: jr          $ra
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A24:
    // 0x80009A24: blez        $a3, L_80009AA8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009A28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009AA8;
    }
    // 0x80009A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009A2C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009A30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009A40: lwc1        $f3, 0x4F18($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X4F18);
    // 0x80009A44: lwc1        $f2, 0x4F1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4F1C);
    // 0x80009A48: lb          $a1, 0x17C($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17C);
    // 0x80009A4C: nop

L_80009A50:
    // 0x80009A50: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009A54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009A58: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009A5C: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009A60: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009A64: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A68: nop
    
            goto L_80009A9C;
    }
    // 0x80009A68: nop

    // 0x80009A6C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009A70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009A74: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009A78: nop

    // 0x80009A7C: bc1t        L_80009A9C
    if (c1cs) {
        // 0x80009A80: nop
    
            goto L_80009A9C;
    }
    // 0x80009A80: nop

    // 0x80009A84: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009A88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009A8C: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009A90: nop

    // 0x80009A94: bc1f        L_80009AA0
    if (!c1cs) {
        // 0x80009A98: nop
    
            goto L_80009AA0;
    }
    // 0x80009A98: nop

L_80009A9C:
    // 0x80009A9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009AA0:
    // 0x80009AA0: bne         $at, $zero, L_80009A50
    if (ctx->r1 != 0) {
        // 0x80009AA4: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009A50;
    }
    // 0x80009AA4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009AA8:
    // 0x80009AA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009AAC: jr          $ra
    // 0x80009AB0: nop

    return;
    // 0x80009AB0: nop

;}
RECOMP_FUNC void update_camera_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C2B0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004C2B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004C2B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004C2BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004C2C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C2C4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8004C2C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C2CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C2D0: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x8004C2D4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8004C2D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004C2DC: lwc1        $f4, -0x2B10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B10);
    // 0x8004C2E0: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004C2E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004C2E8: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C2EC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8004C2F0: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004C2F4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004C2F8: nop

    // 0x8004C2FC: bc1f        L_8004C308
    if (!c1cs) {
        // 0x8004C300: nop
    
            goto L_8004C308;
    }
    // 0x8004C300: nop

    // 0x8004C304: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_8004C308:
    // 0x8004C308: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8004C30C: nop

    // 0x8004C310: bc1f        L_8004C31C
    if (!c1cs) {
        // 0x8004C314: nop
    
            goto L_8004C31C;
    }
    // 0x8004C314: nop

    // 0x8004C318: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_8004C31C:
    // 0x8004C31C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C320: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8004C324: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8004C328: jal         0x80066210
    // 0x8004C32C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004C32C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8004C330: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C334: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004C338: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C33C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C344: bne         $v0, $at, L_8004C364
    if (ctx->r2 != ctx->r1) {
        // 0x8004C348: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004C364;
    }
    // 0x8004C348: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004C34C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004C350: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C354: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004C358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C35C: b           L_8004C380
    // 0x8004C360: nop

        goto L_8004C380;
    // 0x8004C360: nop

L_8004C364:
    // 0x8004C364: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004C368: bne         $at, $zero, L_8004C380
    if (ctx->r1 != 0) {
        // 0x8004C36C: lui         $at, 0x42DC
        ctx->r1 = S32(0X42DC << 16);
            goto L_8004C380;
    }
    // 0x8004C36C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8004C370: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C374: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8004C378: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004C37C: nop

L_8004C380:
    // 0x8004C380: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x8004C384: nop

    // 0x8004C388: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004C38C: beq         $t8, $zero, L_8004C3A8
    if (ctx->r24 == 0) {
        // 0x8004C390: nop
    
            goto L_8004C3A8;
    }
    // 0x8004C390: nop

    // 0x8004C394: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
    // 0x8004C398: nop

    // 0x8004C39C: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8004C3A0: beq         $at, $zero, L_8004C508
    if (ctx->r1 == 0) {
        // 0x8004C3A4: nop
    
            goto L_8004C508;
    }
    // 0x8004C3A4: nop

L_8004C3A8:
    // 0x8004C3A8: lbu         $t2, 0x1F5($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X1F5);
    // 0x8004C3AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8004C3B0: bne         $t2, $zero, L_8004C508
    if (ctx->r10 != 0) {
        // 0x8004C3B4: nop
    
            goto L_8004C508;
    }
    // 0x8004C3B4: nop

    // 0x8004C3B8: lh          $t3, 0x1A0($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A0);
    // 0x8004C3BC: lh          $t5, 0x196($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X196);
    // 0x8004C3C0: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8004C3C4: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8004C3C8: subu        $a0, $t4, $t6
    ctx->r4 = SUB32(ctx->r12, ctx->r14);
    // 0x8004C3CC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8004C3D0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004C3D4: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004C3D8: bne         $at, $zero, L_8004C3E8
    if (ctx->r1 != 0) {
        // 0x8004C3DC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004C3E8;
    }
    // 0x8004C3DC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004C3E0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004C3E4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8004C3E8:
    // 0x8004C3E8: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004C3EC: beq         $at, $zero, L_8004C3F8
    if (ctx->r1 == 0) {
        // 0x8004C3F0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004C3F8;
    }
    // 0x8004C3F0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C3F4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8004C3F8:
    // 0x8004C3F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C3FC: lwc1        $f8, 0x94($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X94);
    // 0x8004C400: lwc1        $f11, 0x6558($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6558);
    // 0x8004C404: lwc1        $f10, 0x655C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X655C);
    // 0x8004C408: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8004C40C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004C410: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C414: bc1f        L_8004C43C
    if (!c1cs) {
        // 0x8004C418: nop
    
            goto L_8004C43C;
    }
    // 0x8004C418: nop

    // 0x8004C41C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C420: lwc1        $f5, 0x6560($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6560);
    // 0x8004C424: lwc1        $f4, 0x6564($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6564);
    // 0x8004C428: nop

    // 0x8004C42C: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x8004C430: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8004C434: b           L_8004C448
    // 0x8004C438: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
        goto L_8004C448;
    // 0x8004C438: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
L_8004C43C:
    // 0x8004C43C: lwc1        $f10, 0x6568($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6568);
    // 0x8004C440: nop

    // 0x8004C444: swc1        $f10, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f10.u32l;
L_8004C448:
    // 0x8004C448: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004C44C: lwc1        $f8, 0x94($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X94);
    // 0x8004C450: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004C454: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004C458: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8004C45C: nop

    // 0x8004C460: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8004C464: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C468: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C46C: nop

    // 0x8004C470: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8004C474: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8004C478: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8004C47C: slti        $at, $v1, 0x201
    ctx->r1 = SIGNED(ctx->r3) < 0X201 ? 1 : 0;
    // 0x8004C480: bne         $at, $zero, L_8004C490
    if (ctx->r1 != 0) {
        // 0x8004C484: slti        $at, $v1, -0x200
        ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
            goto L_8004C490;
    }
    // 0x8004C484: slti        $at, $v1, -0x200
    ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
    // 0x8004C488: addiu       $v1, $zero, 0x200
    ctx->r3 = ADD32(0, 0X200);
    // 0x8004C48C: slti        $at, $v1, -0x200
    ctx->r1 = SIGNED(ctx->r3) < -0X200 ? 1 : 0;
L_8004C490:
    // 0x8004C490: beq         $at, $zero, L_8004C49C
    if (ctx->r1 == 0) {
        // 0x8004C494: nop
    
            goto L_8004C49C;
    }
    // 0x8004C494: nop

    // 0x8004C498: addiu       $v1, $zero, -0x200
    ctx->r3 = ADD32(0, -0X200);
L_8004C49C:
    // 0x8004C49C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8004C4A0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C4A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8004C4A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C4AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C4B0: nop

    // 0x8004C4B4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8004C4B8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8004C4BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8004C4C0: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C4C4: mflo        $v1
    ctx->r3 = lo;
    // 0x8004C4C8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004C4CC: bgez        $a0, L_8004C4E0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004C4D0: nop
    
            goto L_8004C4E0;
    }
    // 0x8004C4D0: nop

    // 0x8004C4D4: beq         $at, $zero, L_8004C4E0
    if (ctx->r1 == 0) {
        // 0x8004C4D8: nop
    
            goto L_8004C4E0;
    }
    // 0x8004C4D8: nop

    // 0x8004C4DC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8004C4E0:
    // 0x8004C4E0: blez        $a0, L_8004C4F4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004C4E4: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8004C4F4;
    }
    // 0x8004C4E4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C4E8: beq         $at, $zero, L_8004C4F4
    if (ctx->r1 == 0) {
        // 0x8004C4EC: nop
    
            goto L_8004C4F4;
    }
    // 0x8004C4EC: nop

    // 0x8004C4F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8004C4F4:
    // 0x8004C4F4: lh          $t9, 0x196($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X196);
    // 0x8004C4F8: nop

    // 0x8004C4FC: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8004C500: b           L_8004C538
    // 0x8004C504: sh          $t2, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r10;
        goto L_8004C538;
    // 0x8004C504: sh          $t2, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r10;
L_8004C508:
    // 0x8004C508: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8004C50C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004C510: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8004C514: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C518: swc1        $f10, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f10.u32l;
    // 0x8004C51C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004C520: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C524: nop

    // 0x8004C528: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8004C52C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8004C530: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8004C534: nop

L_8004C538:
    // 0x8004C538: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004C53C: lh          $t5, -0x2A7A($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2A7A);
    // 0x8004C540: nop

    // 0x8004C544: beq         $t5, $zero, L_8004C55C
    if (ctx->r13 == 0) {
        // 0x8004C548: nop
    
            goto L_8004C55C;
    }
    // 0x8004C548: nop

    // 0x8004C54C: lh          $t4, 0x1A0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A0);
    // 0x8004C550: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8004C554: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x8004C558: sh          $t7, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r15;
L_8004C55C:
    // 0x8004C55C: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C564: beq         $v1, $at, L_8004C574
    if (ctx->r3 == ctx->r1) {
        // 0x8004C568: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8004C574;
    }
    // 0x8004C568: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004C56C: bne         $v1, $at, L_8004C580
    if (ctx->r3 != ctx->r1) {
        // 0x8004C570: lw          $t8, 0x54($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X54);
            goto L_8004C580;
    }
    // 0x8004C570: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8004C574:
    // 0x8004C574: b           L_8004C5AC
    // 0x8004C578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8004C5AC;
    // 0x8004C578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004C57C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8004C580:
    // 0x8004C580: nop

    // 0x8004C584: lh          $a0, 0x2($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X2);
    // 0x8004C588: nop

    // 0x8004C58C: slti        $at, $a0, 0x3001
    ctx->r1 = SIGNED(ctx->r4) < 0X3001 ? 1 : 0;
    // 0x8004C590: bne         $at, $zero, L_8004C5A0
    if (ctx->r1 != 0) {
        // 0x8004C594: slti        $at, $a0, -0x3000
        ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
            goto L_8004C5A0;
    }
    // 0x8004C594: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
    // 0x8004C598: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8004C59C: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
L_8004C5A0:
    // 0x8004C5A0: beq         $at, $zero, L_8004C5B0
    if (ctx->r1 == 0) {
        // 0x8004C5A4: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8004C5B0;
    }
    // 0x8004C5A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004C5A8: addiu       $a0, $zero, -0x3000
    ctx->r4 = ADD32(0, -0X3000);
L_8004C5AC:
    // 0x8004C5AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8004C5B0:
    // 0x8004C5B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004C5B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C5B8: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004C5BC: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004C5C0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C5C4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004C5C8: lh          $a2, 0x2($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X2);
    // 0x8004C5CC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004C5D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004C5D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004C5D8: andi        $t3, $a2, 0xFFFF
    ctx->r11 = ctx->r6 & 0XFFFF;
    // 0x8004C5DC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004C5E0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004C5E4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8004C5E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004C5EC: subu        $a0, $a0, $t2
    ctx->r4 = SUB32(ctx->r4, ctx->r10);
    // 0x8004C5F0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004C5F4: subu        $v1, $a0, $t3
    ctx->r3 = SUB32(ctx->r4, ctx->r11);
    // 0x8004C5F8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004C5FC: bne         $at, $zero, L_8004C610
    if (ctx->r1 != 0) {
        // 0x8004C600: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8004C610;
    }
    // 0x8004C600: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004C604: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004C608: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004C60C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004C610:
    // 0x8004C610: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004C614: beq         $at, $zero, L_8004C620
    if (ctx->r1 == 0) {
        // 0x8004C618: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004C620;
    }
    // 0x8004C618: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C61C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004C620:
    // 0x8004C620: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004C624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C628: mflo        $t5
    ctx->r13 = lo;
    // 0x8004C62C: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004C630: addu        $t4, $a2, $t6
    ctx->r12 = ADD32(ctx->r6, ctx->r14);
    // 0x8004C634: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8004C638: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8004C63C: lwc1        $f2, 0xB8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x8004C640: lbu         $a0, 0x3B($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3B);
    // 0x8004C644: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8004C648: beq         $a0, $at, L_8004C668
    if (ctx->r4 == ctx->r1) {
        // 0x8004C64C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004C668;
    }
    // 0x8004C64C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C650: beq         $a0, $at, L_8004C678
    if (ctx->r4 == ctx->r1) {
        // 0x8004C654: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004C678;
    }
    // 0x8004C654: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C658: beq         $a0, $at, L_8004C690
    if (ctx->r4 == ctx->r1) {
        // 0x8004C65C: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_8004C690;
    }
    // 0x8004C65C: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8004C660: b           L_8004C6C4
    // 0x8004C664: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
        goto L_8004C6C4;
    // 0x8004C664: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004C668:
    // 0x8004C668: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004C66C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004C670: b           L_8004C6C0
    // 0x8004C674: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_8004C6C0;
    // 0x8004C674: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8004C678:
    // 0x8004C678: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004C67C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C680: sub.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8004C684: b           L_8004C6C0
    // 0x8004C688: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
        goto L_8004C6C0;
    // 0x8004C688: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8004C68C: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_8004C690:
    // 0x8004C690: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C694: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004C698: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C69C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004C6A0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004C6A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004C6A8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004C6AC: sub.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8004C6B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004C6B4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004C6B8: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8004C6BC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8004C6C0:
    // 0x8004C6C0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004C6C4:
    // 0x8004C6C4: beq         $at, $zero, L_8004C6E0
    if (ctx->r1 == 0) {
        // 0x8004C6C8: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8004C6E0;
    }
    // 0x8004C6C8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8004C6CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C6D0: nop

    // 0x8004C6D4: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004C6D8: b           L_8004C6F4
    // 0x8004C6DC: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_8004C6F4;
    // 0x8004C6DC: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8004C6E0:
    // 0x8004C6E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004C6E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C6E8: nop

    // 0x8004C6EC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C6F0: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_8004C6F4:
    // 0x8004C6F4: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8004C6F8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004C6FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004C700: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8004C704: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004C708: nop

    // 0x8004C70C: bc1f        L_8004C768
    if (!c1cs) {
        // 0x8004C710: nop
    
            goto L_8004C768;
    }
    // 0x8004C710: nop

    // 0x8004C714: lb          $t8, 0x1E2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E2);
    // 0x8004C718: nop

    // 0x8004C71C: bne         $t8, $zero, L_8004C768
    if (ctx->r24 != 0) {
        // 0x8004C720: nop
    
            goto L_8004C768;
    }
    // 0x8004C720: nop

    // 0x8004C724: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004C728: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004C72C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004C730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C734: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8004C738: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004C73C: lwc1        $f5, 0x6570($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6570);
    // 0x8004C740: lwc1        $f4, 0x6574($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6574);
    // 0x8004C744: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8004C748: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8004C74C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8004C750: nop

    // 0x8004C754: bc1f        L_8004C764
    if (!c1cs) {
        // 0x8004C758: nop
    
            goto L_8004C764;
    }
    // 0x8004C758: nop

    // 0x8004C75C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004C760: nop

L_8004C764:
    // 0x8004C764: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
L_8004C768:
    // 0x8004C768: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x8004C76C: nop

    // 0x8004C770: bne         $t9, $zero, L_8004C7C8
    if (ctx->r25 != 0) {
        // 0x8004C774: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_8004C7C8;
    }
    // 0x8004C774: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8004C778: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C77C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8004C780: jal         0x8000C8B4
    // 0x8004C784: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_1;
    // 0x8004C784: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8004C788: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C78C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C790: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x8004C794: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004C798: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C79C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C7A0: beq         $at, $zero, L_8004C7B8
    if (ctx->r1 == 0) {
        // 0x8004C7A4: addiu       $t0, $t0, -0x2AF8
        ctx->r8 = ADD32(ctx->r8, -0X2AF8);
            goto L_8004C7B8;
    }
    // 0x8004C7A4: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004C7A8: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8004C7AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C7B0: b           L_8004C7C8
    // 0x8004C7B4: nop

        goto L_8004C7C8;
    // 0x8004C7B4: nop

L_8004C7B8:
    // 0x8004C7B8: blez        $v1, L_8004C7C8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004C7BC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004C7C8;
    }
    // 0x8004C7BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004C7C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004C7C4: nop

L_8004C7C8:
    // 0x8004C7C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8004C7CC: lw          $t2, -0x2AC0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC0);
    // 0x8004C7D0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C7D4: slti        $at, $t2, 0x51
    ctx->r1 = SIGNED(ctx->r10) < 0X51 ? 1 : 0;
    // 0x8004C7D8: bne         $at, $zero, L_8004C7F8
    if (ctx->r1 != 0) {
        // 0x8004C7DC: nop
    
            goto L_8004C7F8;
    }
    // 0x8004C7DC: nop

    // 0x8004C7E0: swc1        $f14, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f14.u32l;
    // 0x8004C7E4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8004C7E8: nop

    // 0x8004C7EC: swc1        $f18, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f18.u32l;
    // 0x8004C7F0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C7F4: nop

L_8004C7F8:
    // 0x8004C7F8: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8004C7FC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004C800: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8004C804: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004C808: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004C80C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004C810: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8004C814: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8004C818: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8004C81C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004C820: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x8004C824: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C828: nop

    // 0x8004C82C: lwc1        $f12, 0x20($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004C830: nop

    // 0x8004C834: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8004C838: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8004C83C: mul.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8004C840: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8004C844: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8004C848: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004C84C: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
    // 0x8004C850: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004C854: nop

    // 0x8004C858: lh          $a0, 0x2($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X2);
    // 0x8004C85C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004C860: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x8004C864: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004C868: jal         0x800707C4
    // 0x8004C86C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x8004C86C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_2:
    // 0x8004C870: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C874: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004C878: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8004C87C: nop

    // 0x8004C880: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    // 0x8004C884: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8004C888: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x8004C88C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8004C890: jal         0x800707F8
    // 0x8004C894: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x8004C894: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_3:
    // 0x8004C898: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C89C: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004C8A0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004C8A4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8004C8A8: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8004C8AC: lwc1        $f12, 0x20($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004C8B0: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8004C8B4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C8B8: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x8004C8BC: lh          $t2, 0x196($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X196);
    // 0x8004C8C0: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8004C8C4: subu        $a0, $t3, $t2
    ctx->r4 = SUB32(ctx->r11, ctx->r10);
    // 0x8004C8C8: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004C8CC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004C8D0: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8004C8D4: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004C8D8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8004C8DC: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004C8E0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8004C8E4: jal         0x800707C4
    // 0x8004C8E8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x8004C8E8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8004C8EC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C8F0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C8F4: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8004C8F8: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8004C8FC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8004C900: lh          $t4, 0x196($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X196);
    // 0x8004C904: nop

    // 0x8004C908: subu        $a0, $t7, $t4
    ctx->r4 = SUB32(ctx->r15, ctx->r12);
    // 0x8004C90C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8004C910: jal         0x800707F8
    // 0x8004C914: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_5;
    // 0x8004C914: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_5:
    // 0x8004C918: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004C91C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C920: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8004C924: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8004C928: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004C92C: nop

    // 0x8004C930: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004C934: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8004C938: jal         0x800707C4
    // 0x8004C93C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    sins_f(rdram, ctx);
        goto after_6;
    // 0x8004C93C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x8004C940: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004C944: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C948: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004C94C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004C950: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8004C954: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8004C958: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004C95C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004C960: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004C964: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004C968: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004C96C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004C970: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004C974: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004C978: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004C97C: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x8004C980: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004C984: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004C988: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8004C98C: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8004C990: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C994: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004C998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C99C: beq         $v1, $at, L_8004C9AC
    if (ctx->r3 == ctx->r1) {
        // 0x8004C9A0: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_8004C9AC;
    }
    // 0x8004C9A0: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8004C9A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C9A8: bne         $v1, $at, L_8004C9BC
    if (ctx->r3 != ctx->r1) {
        // 0x8004C9AC: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8004C9BC;
    }
L_8004C9AC:
    // 0x8004C9AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004C9B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004C9B4: lb          $v1, 0x1E0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004C9B8: swc1        $f8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f8.u32l;
L_8004C9BC:
    // 0x8004C9BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C9C0: beq         $v1, $at, L_8004C9CC
    if (ctx->r3 == ctx->r1) {
        // 0x8004C9C4: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8004C9CC;
    }
    // 0x8004C9C4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004C9C8: bne         $v1, $at, L_8004C9DC
    if (ctx->r3 != ctx->r1) {
        // 0x8004C9CC: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8004C9DC;
    }
L_8004C9CC:
    // 0x8004C9CC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004C9D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004C9D4: nop

    // 0x8004C9D8: swc1        $f6, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f6.u32l;
L_8004C9DC:
    // 0x8004C9DC: lwc1        $f4, 0x74($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8004C9E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004C9E4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004C9E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004C9EC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8004C9F0: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8004C9F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004C9F8: bc1f        L_8004CA20
    if (!c1cs) {
        // 0x8004C9FC: nop
    
            goto L_8004CA20;
    }
    // 0x8004C9FC: nop

    // 0x8004CA00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004CA04: lwc1        $f9, 0x6578($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6578);
    // 0x8004CA08: lwc1        $f8, 0x657C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X657C);
    // 0x8004CA0C: nop

    // 0x8004CA10: sub.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d - ctx->f8.d;
    // 0x8004CA14: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8004CA18: b           L_8004CA2C
    // 0x8004CA1C: swc1        $f4, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f4.u32l;
        goto L_8004CA2C;
    // 0x8004CA1C: swc1        $f4, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f4.u32l;
L_8004CA20:
    // 0x8004CA20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004CA24: nop

    // 0x8004CA28: swc1        $f10, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f10.u32l;
L_8004CA2C:
    // 0x8004CA2C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8004CA30: lwc1        $f4, 0x74($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8004CA34: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004CA38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CA3C: div.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8004CA40: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8004CA44: nop

    // 0x8004CA48: bc1f        L_8004CA64
    if (!c1cs) {
        // 0x8004CA4C: nop
    
            goto L_8004CA64;
    }
    // 0x8004CA4C: nop

    // 0x8004CA50: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004CA54: nop

    // 0x8004CA58: bc1f        L_8004CA64
    if (!c1cs) {
        // 0x8004CA5C: nop
    
            goto L_8004CA64;
    }
    // 0x8004CA5C: nop

    // 0x8004CA60: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8004CA64:
    // 0x8004CA64: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8004CA68: nop

    // 0x8004CA6C: bc1f        L_8004CA88
    if (!c1cs) {
        // 0x8004CA70: nop
    
            goto L_8004CA88;
    }
    // 0x8004CA70: nop

    // 0x8004CA74: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8004CA78: nop

    // 0x8004CA7C: bc1f        L_8004CA88
    if (!c1cs) {
        // 0x8004CA80: nop
    
            goto L_8004CA88;
    }
    // 0x8004CA80: nop

    // 0x8004CA84: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8004CA88:
    // 0x8004CA88: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CA8C: nop

    // 0x8004CA90: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CA94: nop

    // 0x8004CA98: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8004CA9C: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x8004CAA0: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004CAA4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x8004CAA8: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004CAAC: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8004CAB0: jal         0x800707F8
    // 0x8004CAB4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_7;
    // 0x8004CAB4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_7:
    // 0x8004CAB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004CABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004CAC0: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8004CAC4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8004CAC8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004CACC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8004CAD0: lwc1        $f8, 0x30($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8004CAD4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004CAD8: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004CADC: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8004CAE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004CAE4: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004CAE8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004CAEC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8004CAF0: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004CAF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004CAF8: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
    // 0x8004CAFC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB00: lh          $t3, 0x196($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X196);
    // 0x8004CB04: nop

    // 0x8004CB08: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x8004CB0C: lb          $t5, 0x1E0($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1E0);
    // 0x8004CB10: nop

    // 0x8004CB14: bne         $t5, $zero, L_8004CB2C
    if (ctx->r13 != 0) {
        // 0x8004CB18: nop
    
            goto L_8004CB2C;
    }
    // 0x8004CB18: nop

    // 0x8004CB1C: lh          $t6, -0x2A7A($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2A7A);
    // 0x8004CB20: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004CB24: beq         $t6, $zero, L_8004CB78
    if (ctx->r14 == 0) {
        // 0x8004CB28: nop
    
            goto L_8004CB78;
    }
    // 0x8004CB28: nop

L_8004CB2C:
    // 0x8004CB2C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB30: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004CB34: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x8004CB38: nop

    // 0x8004CB3C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8004CB40: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8004CB44: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004CB48: bne         $at, $zero, L_8004CB58
    if (ctx->r1 != 0) {
        // 0x8004CB4C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004CB58;
    }
    // 0x8004CB4C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004CB50: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004CB54: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CB58:
    // 0x8004CB58: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004CB5C: beq         $at, $zero, L_8004CB68
    if (ctx->r1 == 0) {
        // 0x8004CB60: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004CB68;
    }
    // 0x8004CB60: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CB64: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CB68:
    // 0x8004CB68: sra         $t7, $v1, 2
    ctx->r15 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8004CB6C: addu        $t4, $v0, $t7
    ctx->r12 = ADD32(ctx->r2, ctx->r15);
    // 0x8004CB70: b           L_8004CBC0
    // 0x8004CB74: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
        goto L_8004CBC0;
    // 0x8004CB74: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
L_8004CB78:
    // 0x8004CB78: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CB7C: lh          $a0, 0x1A4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X1A4);
    // 0x8004CB80: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x8004CB84: sra         $t8, $a0, 4
    ctx->r24 = S32(SIGNED(ctx->r4) >> 4);
    // 0x8004CB88: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x8004CB8C: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8004CB90: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004CB94: bne         $at, $zero, L_8004CBA4
    if (ctx->r1 != 0) {
        // 0x8004CB98: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004CBA4;
    }
    // 0x8004CB98: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004CB9C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004CBA0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CBA4:
    // 0x8004CBA4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004CBA8: beq         $at, $zero, L_8004CBB4
    if (ctx->r1 == 0) {
        // 0x8004CBAC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004CBB4;
    }
    // 0x8004CBAC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CBB0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004CBB4:
    // 0x8004CBB4: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004CBB8: addu        $t2, $v0, $t3
    ctx->r10 = ADD32(ctx->r2, ctx->r11);
    // 0x8004CBBC: sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
L_8004CBC0:
    // 0x8004CBC0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8004CBC4: nop

    // 0x8004CBC8: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CBCC: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CBD0: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x8004CBD4: jal         0x80029F18
    // 0x8004CBD8: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_8;
    // 0x8004CBD8: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_8:
    // 0x8004CBDC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8004CBE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004CBE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004CBE8: beq         $v0, $at, L_8004CBFC
    if (ctx->r2 == ctx->r1) {
        // 0x8004CBEC: addiu       $t0, $t0, -0x2AF8
        ctx->r8 = ADD32(ctx->r8, -0X2AF8);
            goto L_8004CBFC;
    }
    // 0x8004CBEC: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8004CBF0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8004CBF4: nop

    // 0x8004CBF8: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_8004CBFC:
    // 0x8004CBFC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8004CC00: nop

    // 0x8004CC04: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8004CC08: nop

    // 0x8004CC0C: sh          $t7, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r15;
    // 0x8004CC10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CC14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004CC18: jr          $ra
    // 0x8004CC1C: nop

    return;
    // 0x8004CC1C: nop

;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C935C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9360: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C9364: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9368: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C936C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9370: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9374: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9378: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C937C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C9380: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800C9384: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C9388: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C938C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C9390: blez        $a2, L_800C93B4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C9394: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800C93B4;
    }
    // 0x800C9394: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C9398: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800C939C:
    // 0x800C939C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C93A0: jal         0x800C8790
    // 0x800C93A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800C93A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C93A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C93AC: bne         $s0, $s3, L_800C939C
    if (ctx->r16 != ctx->r19) {
        // 0x800C93B0: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800C939C;
    }
    // 0x800C93B0: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800C93B4:
    // 0x800C93B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C93B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C93BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C93C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C93C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C93C8: jr          $ra
    // 0x800C93CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C93CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alSeqpGetChlFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C79C4: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C79C8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C79CC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C79D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C79D4: jr          $ra
    // 0x800C79D8: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
    return;
    // 0x800C79D8: lbu         $v0, 0xA($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XA);
;}
RECOMP_FUNC void func_800B97A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B97A8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800B97AC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800B97B0: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B97B4: addiu       $s5, $s5, -0x6038
    ctx->r21 = ADD32(ctx->r21, -0X6038);
    // 0x800B97B8: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800B97BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B97C0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800B97C4: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B97C8: lwc1        $f0, -0x5FE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5FE0);
    // 0x800B97CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B97D0: lwc1        $f2, -0x5FE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5FE4);
    // 0x800B97D4: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B97D8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800B97DC: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800B97E0: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800B97E4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B97E8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B97EC: sub.s       $f26, $f4, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800B97F0: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800B97F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B97F8: lw          $t9, 0x30D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30D8);
    // 0x800B97FC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800B9800: c.le.s      $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f26.fl <= ctx->f22.fl;
    // 0x800B9804: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B9808: mflo        $t6
    ctx->r14 = lo;
    // 0x800B980C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800B9810: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800B9814: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800B9818: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800B981C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800B9820: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800B9824: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800B9828: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800B982C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800B9830: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B9834: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800B9838: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800B983C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800B9840: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800B9844: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9848: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B984C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B9850: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800B9854: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800B9858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B985C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x800B9860: bc1f        L_800B9878
    if (!c1cs) {
        // 0x800B9864: sw          $t1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r9;
            goto L_800B9878;
    }
    // 0x800B9864: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x800B9868: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B986C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9870: b           L_800B9888
    // 0x800B9874: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
        goto L_800B9888;
    // 0x800B9874: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
L_800B9878:
    // 0x800B9878: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B987C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800B9880: nop

    // 0x800B9884: div.s       $f28, $f24, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = DIV_S(ctx->f24.fl, ctx->f26.fl);
L_800B9888:
    // 0x800B9888: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B988C: lh          $t2, -0x5A18($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5A18);
    // 0x800B9890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9894: beq         $t2, $at, L_800B9BC0
    if (ctx->r10 == ctx->r1) {
        // 0x800B9898: mov.s       $f26, $f12
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
            goto L_800B9BC0;
    }
    // 0x800B9898: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800B989C: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x800B98A0: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x800B98A4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B98A8: addiu       $t4, $t4, -0x5A18
    ctx->r12 = ADD32(ctx->r12, -0X5A18);
    // 0x800B98AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B98B0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800B98B4: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800B98B8: nop

L_800B98BC:
    // 0x800B98BC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800B98C0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800B98C4: bne         $t5, $v1, L_800B9BB0
    if (ctx->r13 != ctx->r3) {
        // 0x800B98C8: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800B9BB0;
    }
    // 0x800B98C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B98CC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B98D0: lw          $t2, -0x5FE8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5FE8);
    // 0x800B98D4: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x800B98D8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800B98DC: lw          $t6, 0x30D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30D4);
    // 0x800B98E0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B98E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B98E8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800B98EC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B98F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B98F4: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B98F8: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800B98FC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9900: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x800B9904: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800B9908: lw          $t0, 0x30E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30E4);
    // 0x800B990C: lw          $a3, 0x3070($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3070);
    // 0x800B9910: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B9914: beq         $a1, $zero, L_800B9968
    if (ctx->r5 == 0) {
        // 0x800B9918: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B9968;
    }
    // 0x800B9918: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B991C: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x800B9920: nop

    // 0x800B9924: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x800B9928: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B992C: andi        $t3, $v1, 0x2
    ctx->r11 = ctx->r3 & 0X2;
    // 0x800B9930: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800B9934: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800B9938: srlv        $t6, $a0, $t8
    ctx->r14 = S32(U32(ctx->r4) >> (ctx->r24 & 31));
    // 0x800B993C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800B9940: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800B9944: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800B9948: mflo        $t4
    ctx->r12 = lo;
    // 0x800B994C: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x800B9950: nop

    // 0x800B9954: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9958: mflo        $t7
    ctx->r15 = lo;
    // 0x800B995C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B9960: b           L_800B9980
    // 0x800B9964: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
        goto L_800B9980;
    // 0x800B9964: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9968:
    // 0x800B9968: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800B996C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800B9970: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800B9974: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x800B9978: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800B997C: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
L_800B9980:
    // 0x800B9980: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800B9984: lh          $a0, 0x6($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X6);
    // 0x800B9988: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B998C: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x800B9990: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x800B9994: mflo        $t2
    ctx->r10 = lo;
    // 0x800B9998: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B999C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800B99A0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B99A4: addu        $t3, $a3, $t4
    ctx->r11 = ADD32(ctx->r7, ctx->r12);
    // 0x800B99A8: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800B99AC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800B99B0: bltz        $v0, L_800B9BB0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B99B4: sw          $t8, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r24;
            goto L_800B9BB0;
    }
    // 0x800B99B4: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x800B99B8: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800B99BC: nop

L_800B99C0:
    // 0x800B99C0: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B99C4: lh          $s1, 0x4($a2)
    ctx->r17 = MEM_H(ctx->r6, 0X4);
    // 0x800B99C8: sll         $t1, $s6, 2
    ctx->r9 = S32(ctx->r22 << 2);
    // 0x800B99CC: addu        $t1, $t1, $s6
    ctx->r9 = ADD32(ctx->r9, ctx->r22);
    // 0x800B99D0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B99D4: addiu       $t4, $t4, 0x304C
    ctx->r12 = ADD32(ctx->r12, 0X304C);
    // 0x800B99D8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800B99DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B99E0: sll         $s4, $s6, 2
    ctx->r20 = S32(ctx->r22 << 2);
    // 0x800B99E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B99E8: addu        $s2, $t6, $s1
    ctx->r18 = ADD32(ctx->r14, ctx->r17);
    // 0x800B99EC: bltz        $v0, L_800B9B7C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B99F0: nop
    
            goto L_800B9B7C;
    }
    // 0x800B99F0: nop

    // 0x800B99F4: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800B99F8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800B99FC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B9A00: addu        $s7, $t2, $t4
    ctx->r23 = ADD32(ctx->r10, ctx->r12);
    // 0x800B9A04: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x800B9A08: sw          $a0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r4;
    // 0x800B9A0C: addu        $s0, $t3, $t1
    ctx->r16 = ADD32(ctx->r11, ctx->r9);
L_800B9A10:
    // 0x800B9A10: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9A14: lw          $t5, 0x3044($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3044);
    // 0x800B9A18: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800B9A1C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x800B9A20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9A24: lw          $v0, 0x3040($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3040);
    // 0x800B9A28: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800B9A2C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9A30: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800B9A34: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800B9A38: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800B9A3C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9A40: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800B9A44: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800B9A48: lwc1        $f16, 0x40($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9A4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B9A50: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B9A54: lw          $t1, 0x3188($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3188);
    // 0x800B9A58: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B9A5C: blez        $t1, L_800B9A80
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B9A60: nop
    
            goto L_800B9A80;
    }
    // 0x800B9A60: nop

    // 0x800B9A64: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800B9A68: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800B9A6C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x800B9A70: addu        $a1, $s3, $t5
    ctx->r5 = ADD32(ctx->r19, ctx->r13);
    // 0x800B9A74: jal         0x800BEFC4
    // 0x800B9A78: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9A78: addu        $a2, $fp, $t7
    ctx->r6 = ADD32(ctx->r30, ctx->r15);
    after_0:
    // 0x800B9A7C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9A80:
    // 0x800B9A80: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800B9A84: nop

    // 0x800B9A88: addu        $t6, $t8, $s4
    ctx->r14 = ADD32(ctx->r24, ctx->r20);
    // 0x800B9A8C: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800B9A90: nop

    // 0x800B9A94: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800B9A98: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B9A9C: nop

    // 0x800B9AA0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B9AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9AAC: nop

    // 0x800B9AB0: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9AB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B9AB8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800B9ABC: sub.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x800B9AC0: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B9AC4: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x800B9AC8: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x800B9ACC: nop

    // 0x800B9AD0: bc1f        L_800B9AE0
    if (!c1cs) {
        // 0x800B9AD4: nop
    
            goto L_800B9AE0;
    }
    // 0x800B9AD4: nop

    // 0x800B9AD8: b           L_800B9AF4
    // 0x800B9ADC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_800B9AF4;
    // 0x800B9ADC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_800B9AE0:
    // 0x800B9AE0: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800B9AE4: nop

    // 0x800B9AE8: bc1f        L_800B9AF4
    if (!c1cs) {
        // 0x800B9AEC: nop
    
            goto L_800B9AF4;
    }
    // 0x800B9AEC: nop

    // 0x800B9AF0: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
L_800B9AF4:
    // 0x800B9AF4: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x800B9AF8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800B9AFC: sb          $t3, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r11;
    // 0x800B9B00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9B04: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B9B08: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B9B0C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B9B10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9B14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9B18: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800B9B1C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B9B20: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800B9B24: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B9B28: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B9B2C: addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
    // 0x800B9B30: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // 0x800B9B34: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x800B9B38: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x800B9B3C: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800B9B40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B9B44: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B9B48: bne         $at, $zero, L_800B9B58
    if (ctx->r1 != 0) {
        // 0x800B9B4C: nop
    
            goto L_800B9B58;
    }
    // 0x800B9B4C: nop

    // 0x800B9B50: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800B9B54: subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
L_800B9B58:
    // 0x800B9B58: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800B9B5C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9B60: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800B9B64: beq         $at, $zero, L_800B9A10
    if (ctx->r1 == 0) {
        // 0x800B9B68: nop
    
            goto L_800B9A10;
    }
    // 0x800B9B68: nop

    // 0x800B9B6C: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B9B70: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800B9B74: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800B9B78: nop

L_800B9B7C:
    // 0x800B9B7C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B9B80: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B9B84: bne         $at, $zero, L_800B9B90
    if (ctx->r1 != 0) {
        // 0x800B9B88: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_800B9B90;
    }
    // 0x800B9B88: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800B9B8C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
L_800B9B90:
    // 0x800B9B90: beq         $a1, $zero, L_800B9BA8
    if (ctx->r5 == 0) {
        // 0x800B9B94: slt         $at, $v0, $fp
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
            goto L_800B9BA8;
    }
    // 0x800B9B94: slt         $at, $v0, $fp
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800B9B98: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x800B9B9C: nop

    // 0x800B9BA0: addu        $t5, $t1, $v0
    ctx->r13 = ADD32(ctx->r9, ctx->r2);
    // 0x800B9BA4: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
L_800B9BA8:
    // 0x800B9BA8: beq         $at, $zero, L_800B99C0
    if (ctx->r1 == 0) {
        // 0x800B9BAC: nop
    
            goto L_800B99C0;
    }
    // 0x800B9BAC: nop

L_800B9BB0:
    // 0x800B9BB0: lh          $v1, 0xC($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XC);
    // 0x800B9BB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9BB8: bne         $v1, $at, L_800B98BC
    if (ctx->r3 != ctx->r1) {
        // 0x800B9BBC: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800B98BC;
    }
    // 0x800B9BBC: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_800B9BC0:
    // 0x800B9BC0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800B9BC4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9BC8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B9BCC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B9BD0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B9BD4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800B9BD8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B9BDC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800B9BE0: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B9BE4: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800B9BE8: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B9BEC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800B9BF0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800B9BF4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800B9BF8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B9BFC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800B9C00: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800B9C04: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800B9C08: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800B9C0C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800B9C10: jr          $ra
    // 0x800B9C14: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800B9C14: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void set_ghost_none(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B790: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001B794: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001B798: sh          $t6, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r14;
    // 0x8001B79C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B7A0: jr          $ra
    // 0x8001B7A4: sb          $zero, -0x38D0($at)
    MEM_B(-0X38D0, ctx->r1) = 0;
    return;
    // 0x8001B7A4: sb          $zero, -0x38D0($at)
    MEM_B(-0X38D0, ctx->r1) = 0;
;}
RECOMP_FUNC void sndp_apply_pitch_slide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000418C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80004190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004194: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80004198: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000419C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800041A0: nop

    // 0x800041A4: lb          $a0, 0x5($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X5);
    // 0x800041A8: jal         0x800C99E0
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    alCents2Ratio(rdram, ctx);
        goto after_0;
    // 0x800041AC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800041B0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800041B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800041B8: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800041BC: lw          $a0, -0x3944($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3944);
    // 0x800041C0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800041C4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800041C8: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x800041CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800041D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800041D4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800041D8: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    // 0x800041DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800041E0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800041E4: jal         0x800C91AC
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x800041E8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_1:
    // 0x800041EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800041F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800041F4: jr          $ra
    // 0x800041F8: nop

    return;
    // 0x800041F8: nop

;}
RECOMP_FUNC void func_80092188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 13U, dkr_legacy_fields, 0U); }
    // 0x80092188: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009218C: lw          $t6, -0xB84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB84);
    // 0x80092190: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80092194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092198: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8009219C: jal         0x8006EA90
    // 0x800921A0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800921A0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x800921A4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800921A8: addiu       $a2, $a2, 0x980
    ctx->r6 = ADD32(ctx->r6, 0X980);
    // 0x800921AC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800921B0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800921B4: beq         $v1, $zero, L_800921CC
    if (ctx->r3 == 0) {
        // 0x800921B8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800921CC;
    }
    // 0x800921B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800921BC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800921C0: nop

    // 0x800921C4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800921C8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800921CC:
    // 0x800921CC: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x800921D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800921D4: bne         $v0, $at, L_8009221C
    if (ctx->r2 != ctx->r1) {
        // 0x800921D8: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8009221C;
    }
    // 0x800921D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800921DC: addiu       $t4, $t4, 0x63E0
    ctx->r12 = ADD32(ctx->r12, 0X63E0);
    // 0x800921E0: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800921E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800921E8: beq         $t9, $at, L_8009221C
    if (ctx->r25 == ctx->r1) {
        // 0x800921EC: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8009221C;
    }
    // 0x800921EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800921F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800921F4: bne         $v0, $at, L_8009221C
    if (ctx->r2 != ctx->r1) {
        // 0x800921F8: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_8009221C;
    }
    // 0x800921F8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800921FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092200: lw          $a0, 0x69CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X69CC);
    // 0x80092204: jal         0x800C31EC
    // 0x80092208: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x80092208: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_1:
    // 0x8009220C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092210: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80092214: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x80092218: addiu       $a2, $a2, 0x980
    ctx->r6 = ADD32(ctx->r6, 0X980);
L_8009221C:
    // 0x8009221C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092220: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80092224: bne         $v0, $at, L_80092248
    if (ctx->r2 != ctx->r1) {
        // 0x80092228: addiu       $t4, $t4, 0x63E0
        ctx->r12 = ADD32(ctx->r12, 0X63E0);
            goto L_80092248;
    }
    // 0x80092228: addiu       $t4, $t4, 0x63E0
    ctx->r12 = ADD32(ctx->r12, 0X63E0);
    // 0x8009222C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80092230: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092234: beq         $t5, $v1, L_80092248
    if (ctx->r13 == ctx->r3) {
        // 0x80092238: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80092248;
    }
    // 0x80092238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009223C: beq         $v1, $at, L_80092248
    if (ctx->r3 == ctx->r1) {
        // 0x80092240: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80092248;
    }
    // 0x80092240: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80092244: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_80092248:
    // 0x80092248: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009224C: lw          $t8, -0xB3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB3C);
    // 0x80092250: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092254: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80092258: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8009225C: lh          $v0, 0x758($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X758);
    // 0x80092260: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092264: beq         $t5, $v0, L_80092294
    if (ctx->r13 == ctx->r2) {
        // 0x80092268: nop
    
            goto L_80092294;
    }
    // 0x80092268: nop

    // 0x8009226C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80092270: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80092274: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80092278: bne         $at, $zero, L_80092294
    if (ctx->r1 != 0) {
        // 0x8009227C: nop
    
            goto L_80092294;
    }
    // 0x8009227C: nop

    // 0x80092280: jal         0x80001D04
    // 0x80092284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80092284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80092288: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009228C: addiu       $a2, $a2, 0x980
    ctx->r6 = ADD32(ctx->r6, 0X980);
    // 0x80092290: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80092294:
    // 0x80092294: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092298: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009229C: nop

    // 0x800922A0: bgez        $v0, L_80092380
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800922A4: addiu       $t1, $v0, 0x19
        ctx->r9 = ADD32(ctx->r2, 0X19);
            goto L_80092380;
    }
    // 0x800922A4: addiu       $t1, $v0, 0x19
    ctx->r9 = ADD32(ctx->r2, 0X19);
    // 0x800922A8: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x800922AC: bne         $at, $zero, L_800922B8
    if (ctx->r1 != 0) {
        // 0x800922B0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800922B8;
    }
    // 0x800922B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800922B4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_800922B8:
    // 0x800922B8: bgez        $t1, L_800922C4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800922BC: nop
    
            goto L_800922C4;
    }
    // 0x800922BC: nop

    // 0x800922C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800922C4:
    // 0x800922C4: lw          $v0, 0x6478($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6478);
    // 0x800922C8: addiu       $t7, $t1, 0x14
    ctx->r15 = ADD32(ctx->r9, 0X14);
    // 0x800922CC: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800922D0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800922D4: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800922D8: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x800922DC: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x800922E0: addiu       $a3, $t0, 0xF0
    ctx->r7 = ADD32(ctx->r8, 0XF0);
    // 0x800922E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800922E8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800922EC: mflo        $v1
    ctx->r3 = lo;
    // 0x800922F0: nop

    // 0x800922F4: nop

    // 0x800922F8: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800922FC: mflo        $t8
    ctx->r24 = lo;
    // 0x80092300: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80092304: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80092308: jal         0x80066940
    // 0x8009230C: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x8009230C: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    after_3:
    extern void dkr_track_select_fullscreen_preview(uint8_t*, recomp_context*); dkr_track_select_fullscreen_preview(rdram, ctx);
    // 0x80092310: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80092314: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80092318: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8009231C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80092320: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80092324: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80092328: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009232C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80092330: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092334: addiu       $a0, $a0, -0xAF0
    ctx->r4 = ADD32(ctx->r4, -0XAF0);
    // 0x80092338: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8009233C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80092340: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x80092344: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80092348: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009234C: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80092350: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80092354: swc1        $f4, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f4.u32l;
    // 0x80092358: lwc1        $f6, 0xA8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8009235C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80092360: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80092364: swc1        $f8, 0xA8($t7)
    MEM_W(0XA8, ctx->r15) = ctx->f8.u32l;
    // 0x80092368: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8009236C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80092370: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80092374: swc1        $f10, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->f10.u32l;
    // 0x80092378: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009237C: nop

L_80092380:
    // 0x80092380: blez        $v0, L_800923A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80092384: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_800923A4;
    }
    // 0x80092384: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x80092388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009238C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80092390: addiu       $v1, $v1, -0x8A0
    ctx->r3 = ADD32(ctx->r3, -0X8A0);
    // 0x80092394: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80092398: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009239C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800923A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800923A4:
    // 0x800923A4: bne         $at, $zero, L_800923C0
    if (ctx->r1 != 0) {
        // 0x800923A8: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800923C0;
    }
    // 0x800923A8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800923AC: jal         0x8008F00C
    // 0x800923B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    trackmenu_assets(rdram, ctx);
        goto after_4;
    // 0x800923B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x800923B4: b           L_80092400
    // 0x800923B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80092400;
    // 0x800923B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800923BC: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_800923C0:
    // 0x800923C0: beq         $at, $zero, L_800923FC
    if (ctx->r1 == 0) {
        // 0x800923C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800923FC;
    }
    // 0x800923C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800923C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800923CC: jal         0x8008F00C
    // 0x800923D0: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    trackmenu_assets(rdram, ctx);
        goto after_5;
    // 0x800923D0: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    after_5:
    // 0x800923D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800923D8: lw          $v0, 0x6478($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6478);
    // 0x800923DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800923E0: sra         $v1, $v0, 1
    ctx->r3 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800923E4: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800923E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800923EC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800923F0: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x800923F4: jal         0x80066940
    // 0x800923F8: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    viewport_menu_set(rdram, ctx);
        goto after_6;
    // 0x800923F8: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    after_6:
L_800923FC:
    // 0x800923FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80092400:
    // 0x80092400: jal         0x80066818
    // 0x80092404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x80092404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80092408: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8009240C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092410: bne         $t9, $zero, L_80092BD4
    if (ctx->r25 != 0) {
        // 0x80092414: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80092BD4;
    }
    // 0x80092414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80092418: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x8009241C: jal         0x8006B0F8
    // 0x80092420: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_8;
    // 0x80092420: nop

    after_8:
    // 0x80092424: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092428: addiu       $t4, $t4, 0x63E0
    ctx->r12 = ADD32(ctx->r12, 0X63E0);
    // 0x8009242C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80092430: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092434: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80092438: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8009243C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80092440: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80092444: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80092448: beq         $at, $zero, L_80092B18
    if (ctx->r1 == 0) {
        // 0x8009244C: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_80092B18;
    }
    // 0x8009244C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80092450: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80092454: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80092458: addu        $at, $at, $t7
    gpr jr_addend_80092464 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009245C: lw          $t7, -0x7B0C($at)
    ctx->r15 = ADD32(ctx->r1, -0X7B0C);
    // 0x80092460: nop

    // 0x80092464: jr          $t7
    // 0x80092468: nop

    switch (jr_addend_80092464 >> 2) {
        case 0: goto L_8009246C; break;
        case 1: goto L_8009251C; break;
        case 2: goto L_80092740; break;
        case 3: goto L_8009287C; break;
        case 4: goto L_8009287C; break;
        default: switch_error(__func__, 0x80092464, 0x800E84F4);
    }
    // 0x80092468: nop

L_8009246C:
    // 0x8009246C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092470: addiu       $a0, $a0, 0x67D8
    ctx->r4 = ADD32(ctx->r4, 0X67D8);
    // 0x80092474: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092478: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009247C: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x80092480: beq         $t8, $zero, L_800924AC
    if (ctx->r24 == 0) {
        // 0x80092484: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800924AC;
    }
    // 0x80092484: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092488: lw          $t6, 0x69C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69C8);
    // 0x8009248C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80092490: bne         $t6, $at, L_800924A0
    if (ctx->r14 != ctx->r1) {
        // 0x80092494: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800924A0;
    }
    // 0x80092494: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80092498: b           L_800924A4
    // 0x8009249C: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
        goto L_800924A4;
    // 0x8009249C: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
L_800924A0:
    // 0x800924A0: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_800924A4:
    // 0x800924A4: b           L_80092B18
    // 0x800924A8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_80092B18;
    // 0x800924A8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_800924AC:
    // 0x800924AC: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x800924B0: beq         $t8, $zero, L_800924CC
    if (ctx->r24 == 0) {
        // 0x800924B4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800924CC;
    }
    // 0x800924B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800924B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800924BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800924C0: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
    // 0x800924C4: b           L_80092B18
    // 0x800924C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_80092B18;
    // 0x800924C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_800924CC:
    // 0x800924CC: lh          $v0, 0x6838($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6838);
    // 0x800924D0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800924D4: blez        $v0, L_800924F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800924D8: nop
    
            goto L_800924F8;
    }
    // 0x800924D8: nop

    // 0x800924DC: lw          $t9, 0x418($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X418);
    // 0x800924E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800924E4: beq         $t9, $zero, L_800924F8
    if (ctx->r25 == 0) {
        // 0x800924E8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800924F8;
    }
    // 0x800924E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800924EC: sw          $zero, 0x418($at)
    MEM_W(0X418, ctx->r1) = 0;
    // 0x800924F0: b           L_80092B18
    // 0x800924F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_80092B18;
    // 0x800924F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_800924F8:
    // 0x800924F8: bgez        $v0, L_80092B18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800924FC: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80092B18;
    }
    // 0x800924FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80092500: lw          $t8, 0x418($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X418);
    // 0x80092504: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092508: bne         $t8, $zero, L_80092B18
    if (ctx->r24 != 0) {
        // 0x8009250C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80092B18;
    }
    // 0x8009250C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092510: sw          $ra, 0x418($at)
    MEM_W(0X418, ctx->r1) = ctx->r31;
    // 0x80092514: b           L_80092B18
    // 0x80092518: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
        goto L_80092B18;
    // 0x80092518: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_8009251C:
    // 0x8009251C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80092520: lw          $t2, -0xB44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB44);
    // 0x80092524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092528: blez        $t2, L_800926F4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009252C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800926F4;
    }
    // 0x8009252C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80092530: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092534: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092538: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x8009253C: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x80092540: addiu       $t0, $t0, 0x67D8
    ctx->r8 = ADD32(ctx->r8, 0X67D8);
    // 0x80092544: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_80092548:
    // 0x80092548: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8009254C: nop

    // 0x80092550: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80092554: beq         $t6, $zero, L_800925E8
    if (ctx->r14 == 0) {
        // 0x80092558: andi        $t8, $v1, 0x9000
        ctx->r24 = ctx->r3 & 0X9000;
            goto L_800925E8;
    }
    // 0x80092558: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x8009255C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80092560: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80092564: bne         $v1, $zero, L_800925CC
    if (ctx->r3 != 0) {
        // 0x80092568: addu        $v0, $t3, $a1
        ctx->r2 = ADD32(ctx->r11, ctx->r5);
            goto L_800925CC;
    }
    // 0x80092568: addu        $v0, $t3, $a1
    ctx->r2 = ADD32(ctx->r11, ctx->r5);
    // 0x8009256C: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80092570: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80092574: jal         0x8009EC60
    // 0x80092578: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    is_adventure_two_unlocked(rdram, ctx);
        goto after_9;
    // 0x80092578: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_9:
    // 0x8009257C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80092580: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80092584: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80092588: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009258C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092590: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092594: addiu       $t4, $t4, 0x63E0
    ctx->r12 = ADD32(ctx->r12, 0X63E0);
    // 0x80092598: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x8009259C: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x800925A0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800925A4: beq         $v0, $zero, L_800925B4
    if (ctx->r2 == 0) {
        // 0x800925A8: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_800925B4;
    }
    // 0x800925A8: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800925AC: b           L_800925BC
    // 0x800925B0: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
        goto L_800925BC;
    // 0x800925B0: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
L_800925B4:
    // 0x800925B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800925B8: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
L_800925BC:
    // 0x800925BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800925C0: lw          $t2, -0xB44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB44);
    // 0x800925C4: b           L_800926E8
    // 0x800925C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800926E8;
    // 0x800925C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800925CC:
    // 0x800925CC: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x800925D0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800925D4: beq         $t9, $zero, L_800926E4
    if (ctx->r25 == 0) {
        // 0x800925D8: nop
    
            goto L_800926E4;
    }
    // 0x800925D8: nop

    // 0x800925DC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800925E0: b           L_800926E4
    // 0x800925E4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_800926E4;
    // 0x800925E4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800925E8:
    // 0x800925E8: beq         $t8, $zero, L_80092618
    if (ctx->r24 == 0) {
        // 0x800925EC: addu        $v0, $t3, $a1
        ctx->r2 = ADD32(ctx->r11, ctx->r5);
            goto L_80092618;
    }
    // 0x800925EC: addu        $v0, $t3, $a1
    ctx->r2 = ADD32(ctx->r11, ctx->r5);
    // 0x800925F0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x800925F4: nop

    // 0x800925F8: bne         $t6, $zero, L_800926E4
    if (ctx->r14 != 0) {
        // 0x800925FC: nop
    
            goto L_800926E4;
    }
    // 0x800925FC: nop

    // 0x80092600: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80092604: sb          $ra, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r31;
    // 0x80092608: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8009260C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80092610: b           L_800926E4
    // 0x80092614: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
        goto L_800926E4;
    // 0x80092614: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
L_80092618:
    // 0x80092618: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8009261C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80092620: bne         $t8, $zero, L_800926E4
    if (ctx->r24 != 0) {
        // 0x80092624: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800926E4;
    }
    // 0x80092624: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80092628: lw          $t7, -0xB3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB3C);
    // 0x8009262C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80092630: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80092634: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80092638: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009263C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80092640: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80092644: beq         $t9, $zero, L_800926E4
    if (ctx->r25 == 0) {
        // 0x80092648: addiu       $t8, $t8, 0x69C0
        ctx->r24 = ADD32(ctx->r24, 0X69C0);
            goto L_800926E4;
    }
    // 0x80092648: addiu       $t8, $t8, 0x69C0
    ctx->r24 = ADD32(ctx->r24, 0X69C0);
    // 0x8009264C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80092650: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80092654: addu        $v1, $a1, $t8
    ctx->r3 = ADD32(ctx->r5, ctx->r24);
    // 0x80092658: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8009265C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80092660: lh          $a2, 0x6830($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X6830);
    // 0x80092664: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80092668: blez        $a2, L_80092694
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009266C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80092694;
    }
    // 0x8009266C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80092670:
    // 0x80092670: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80092674: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80092678: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009267C: sllv        $t8, $t9, $v0
    ctx->r24 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x80092680: and         $t6, $t8, $a0
    ctx->r14 = ctx->r24 & ctx->r4;
    // 0x80092684: bne         $t6, $zero, L_80092694
    if (ctx->r14 != 0) {
        // 0x80092688: nop
    
            goto L_80092694;
    }
    // 0x80092688: nop

    // 0x8009268C: bgez        $v0, L_80092670
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80092690: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80092670;
    }
    // 0x80092690: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80092694:
    // 0x80092694: bgez        $a2, L_800926C0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80092698: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_800926C0;
    }
    // 0x80092698: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
L_8009269C:
    // 0x8009269C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800926A0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800926A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800926A8: sllv        $t8, $t9, $v0
    ctx->r24 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x800926AC: and         $t6, $t8, $a0
    ctx->r14 = ctx->r24 & ctx->r4;
    // 0x800926B0: bne         $t6, $zero, L_800926C0
    if (ctx->r14 != 0) {
        // 0x800926B4: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_800926C0;
    }
    // 0x800926B4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800926B8: bne         $at, $zero, L_8009269C
    if (ctx->r1 != 0) {
        // 0x800926BC: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8009269C;
    }
    // 0x800926BC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
L_800926C0:
    // 0x800926C0: beq         $a3, $v0, L_800926E4
    if (ctx->r7 == ctx->r2) {
        // 0x800926C4: nop
    
            goto L_800926E4;
    }
    // 0x800926C4: nop

    // 0x800926C8: bltz        $v0, L_800926D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800926CC: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_800926D8;
    }
    // 0x800926CC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800926D0: bne         $at, $zero, L_800926E0
    if (ctx->r1 != 0) {
        // 0x800926D4: nop
    
            goto L_800926E0;
    }
    // 0x800926D4: nop

L_800926D8:
    // 0x800926D8: b           L_800926E4
    // 0x800926DC: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
        goto L_800926E4;
    // 0x800926DC: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
L_800926E0:
    // 0x800926E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_800926E4:
    // 0x800926E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800926E8:
    // 0x800926E8: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800926EC: bne         $at, $zero, L_80092548
    if (ctx->r1 != 0) {
        // 0x800926F0: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80092548;
    }
    // 0x800926F0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_800926F4:
    // 0x800926F4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800926F8: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x800926FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80092700: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092704: bne         $t2, $t7, L_80092B18
    if (ctx->r10 != ctx->r15) {
        // 0x80092708: slti        $at, $t2, 0x2
        ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
            goto L_80092B18;
    }
    // 0x80092708: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8009270C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80092710: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80092714: bne         $at, $zero, L_80092728
    if (ctx->r1 != 0) {
        // 0x80092718: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_80092728;
    }
    // 0x80092718: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8009271C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80092720: b           L_8009272C
    // 0x80092724: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
        goto L_8009272C;
    // 0x80092724: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
L_80092728:
    // 0x80092728: sw          $ra, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r31;
L_8009272C:
    // 0x8009272C: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80092730: jal         0x80001D04
    // 0x80092734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80092734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80092738: b           L_80092B1C
    // 0x8009273C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
        goto L_80092B1C;
    // 0x8009273C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80092740:
    // 0x80092740: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092744: addiu       $a0, $a0, 0x67D8
    ctx->r4 = ADD32(ctx->r4, 0X67D8);
    // 0x80092748: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009274C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80092750: andi        $t8, $v0, 0x9000
    ctx->r24 = ctx->r2 & 0X9000;
    // 0x80092754: beq         $t8, $zero, L_80092770
    if (ctx->r24 == 0) {
        // 0x80092758: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_80092770;
    }
    // 0x80092758: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8009275C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80092760: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092764: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80092768: b           L_80092798
    // 0x8009276C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
        goto L_80092798;
    // 0x8009276C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_80092770:
    // 0x80092770: beq         $t9, $zero, L_80092798
    if (ctx->r25 == 0) {
        // 0x80092774: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80092798;
    }
    // 0x80092774: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092778: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009277C: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x80092780: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x80092784: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092788: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8009278C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80092790: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80092794: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_80092798:
    // 0x80092798: lh          $v1, 0x6830($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6830);
    // 0x8009279C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800927A0: blez        $v1, L_800927F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800927A4: nop
    
            goto L_800927F8;
    }
    // 0x800927A4: nop

    // 0x800927A8: lw          $v0, 0x414($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X414);
    // 0x800927AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800927B0: blez        $v0, L_800927F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800927B4: nop
    
            goto L_800927F8;
    }
    // 0x800927B4: nop

    // 0x800927B8: lw          $a0, 0x6848($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6848);
    // 0x800927BC: nop

    // 0x800927C0: beq         $a0, $zero, L_800927E8
    if (ctx->r4 == 0) {
        // 0x800927C4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800927E8;
    }
    // 0x800927C4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800927C8: jal         0x8000488C
    // 0x800927CC: nop

    sndp_stop(rdram, ctx);
        goto after_11;
    // 0x800927CC: nop

    after_11:
    // 0x800927D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800927D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800927D8: lw          $v0, 0x414($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X414);
    // 0x800927DC: lh          $v1, 0x6830($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6830);
    // 0x800927E0: nop

    // 0x800927E4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
L_800927E8:
    // 0x800927E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800927EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800927F0: sw          $t6, 0x414($at)
    MEM_W(0X414, ctx->r1) = ctx->r14;
    // 0x800927F4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_800927F8:
    // 0x800927F8: bgez        $v1, L_80092B18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800927FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80092B18;
    }
    // 0x800927FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80092800: lw          $t9, 0x414($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X414);
    // 0x80092804: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092808: bgtz        $t9, L_80092B1C
    if (SIGNED(ctx->r25) > 0) {
        // 0x8009280C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80092B1C;
    }
    // 0x8009280C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80092810: lw          $a0, 0x6840($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6840);
    // 0x80092814: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092818: beq         $a0, $zero, L_80092828
    if (ctx->r4 == 0) {
        // 0x8009281C: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80092828;
    }
    // 0x8009281C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80092820: jal         0x8000488C
    // 0x80092824: nop

    sndp_stop(rdram, ctx);
        goto after_12;
    // 0x80092824: nop

    after_12:
L_80092828:
    // 0x80092828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009282C: jal         0x8006F94C
    // 0x80092830: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_13;
    // 0x80092830: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_13:
    // 0x80092834: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80092838: bne         $at, $zero, L_80092858
    if (ctx->r1 != 0) {
        // 0x8009283C: addiu       $a0, $zero, 0x147
        ctx->r4 = ADD32(0, 0X147);
            goto L_80092858;
    }
    // 0x8009283C: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    // 0x80092840: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80092844: addiu       $a1, $a1, 0x6848
    ctx->r5 = ADD32(ctx->r5, 0X6848);
    // 0x80092848: jal         0x80001D04
    // 0x8009284C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8009284C: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    after_14:
    // 0x80092850: b           L_80092864
    // 0x80092854: nop

        goto L_80092864;
    // 0x80092854: nop

L_80092858:
    // 0x80092858: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009285C: jal         0x80001D04
    // 0x80092860: addiu       $a1, $a1, 0x6848
    ctx->r5 = ADD32(ctx->r5, 0X6848);
    sound_play(rdram, ctx);
        goto after_15;
    // 0x80092860: addiu       $a1, $a1, 0x6848
    ctx->r5 = ADD32(ctx->r5, 0X6848);
    after_15:
L_80092864:
    // 0x80092864: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80092868: lw          $t6, 0x414($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X414);
    // 0x8009286C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092870: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80092874: b           L_80092B18
    // 0x80092878: sw          $t7, 0x414($at)
    MEM_W(0X414, ctx->r1) = ctx->r15;
        goto L_80092B18;
    // 0x80092878: sw          $t7, 0x414($at)
    MEM_W(0X414, ctx->r1) = ctx->r15;
L_8009287C:
    // 0x8009287C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092880: bne         $v1, $at, L_8009297C
    if (ctx->r3 != ctx->r1) {
        // 0x80092884: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8009297C;
    }
    // 0x80092884: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80092888: lw          $t9, -0xB44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB44);
    // 0x8009288C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092890: bne         $t9, $at, L_8009297C
    if (ctx->r25 != ctx->r1) {
        // 0x80092894: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8009297C;
    }
    // 0x80092894: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80092898: lw          $t8, 0x69C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69C8);
    // 0x8009289C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800928A0: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800928A4: beq         $at, $zero, L_8009297C
    if (ctx->r1 == 0) {
        // 0x800928A8: addiu       $a0, $a0, 0x67D8
        ctx->r4 = ADD32(ctx->r4, 0X67D8);
            goto L_8009297C;
    }
    // 0x800928A8: addiu       $a0, $a0, 0x67D8
    ctx->r4 = ADD32(ctx->r4, 0X67D8);
    // 0x800928AC: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800928B0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800928B4: andi        $t6, $v1, 0x9000
    ctx->r14 = ctx->r3 & 0X9000;
    // 0x800928B8: beq         $t6, $zero, L_800928D0
    if (ctx->r14 == 0) {
        // 0x800928BC: andi        $t8, $v1, 0x4000
        ctx->r24 = ctx->r3 & 0X4000;
            goto L_800928D0;
    }
    // 0x800928BC: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x800928C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800928C4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800928C8: b           L_80092B18
    // 0x800928CC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_80092B18;
    // 0x800928CC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800928D0:
    // 0x800928D0: beq         $t8, $zero, L_80092924
    if (ctx->r24 == 0) {
        // 0x800928D4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80092924;
    }
    // 0x800928D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800928D8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800928DC: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x800928E0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800928E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800928E8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800928EC: andi        $t8, $t9, 0x4000
    ctx->r24 = ctx->r25 & 0X4000;
    // 0x800928F0: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x800928F4: beq         $t8, $zero, L_8009290C
    if (ctx->r24 == 0) {
        // 0x800928F8: sw          $t7, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r15;
            goto L_8009290C;
    }
    // 0x800928F8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800928FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092900: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x80092904: b           L_80092918
    // 0x80092908: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
        goto L_80092918;
    // 0x80092908: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
L_8009290C:
    // 0x8009290C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092910: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x80092914: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
L_80092918:
    // 0x80092918: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009291C: b           L_80092B18
    // 0x80092920: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_80092B18;
    // 0x80092920: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80092924:
    // 0x80092924: lh          $v1, 0x6820($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6820);
    // 0x80092928: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009292C: bgez        $v1, L_80092950
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80092930: addiu       $a0, $a0, 0x410
        ctx->r4 = ADD32(ctx->r4, 0X410);
            goto L_80092950;
    }
    // 0x80092930: addiu       $a0, $a0, 0x410
    ctx->r4 = ADD32(ctx->r4, 0X410);
    // 0x80092934: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80092938: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009293C: blez        $v0, L_80092950
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80092940: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80092950;
    }
    // 0x80092940: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80092944: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80092948: b           L_80092B18
    // 0x8009294C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_80092B18;
    // 0x8009294C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80092950:
    // 0x80092950: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092954: blez        $v1, L_80092B18
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80092958: addiu       $a0, $a0, 0x410
        ctx->r4 = ADD32(ctx->r4, 0X410);
            goto L_80092B18;
    }
    // 0x80092958: addiu       $a0, $a0, 0x410
    ctx->r4 = ADD32(ctx->r4, 0X410);
    // 0x8009295C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80092960: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80092964: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80092968: beq         $at, $zero, L_80092B18
    if (ctx->r1 == 0) {
        // 0x8009296C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80092B18;
    }
    // 0x8009296C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80092970: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80092974: b           L_80092B18
    // 0x80092978: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_80092B18;
    // 0x80092978: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8009297C:
    // 0x8009297C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092980: addiu       $a0, $a0, 0x67D8
    ctx->r4 = ADD32(ctx->r4, 0X67D8);
    // 0x80092984: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80092988: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x8009298C: andi        $t7, $v1, 0x9000
    ctx->r15 = ctx->r3 & 0X9000;
    // 0x80092990: beq         $t7, $zero, L_800929E8
    if (ctx->r15 == 0) {
        // 0x80092994: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800929E8;
    }
    // 0x80092994: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092998: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009299C: sw          $ra, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r31;
    // 0x800929A0: jal         0x80078AAC
    // 0x800929A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    bgdraw_set_func(rdram, ctx);
        goto after_16;
    // 0x800929A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x800929A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800929AC: jal         0x800C0180
    // 0x800929B0: sw          $zero, 0x97C($at)
    MEM_W(0X97C, ctx->r1) = 0;
    disable_new_screen_transitions(rdram, ctx);
        goto after_17;
    // 0x800929B0: sw          $zero, 0x97C($at)
    MEM_W(0X97C, ctx->r1) = 0;
    after_17:
    // 0x800929B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800929B8: jal         0x800C01D8
    // 0x800929BC: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_18;
    // 0x800929BC: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_18:
    // 0x800929C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800929C4: lw          $t9, 0x69C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69C8);
    // 0x800929C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800929CC: bne         $t9, $at, L_800929E0
    if (ctx->r25 != ctx->r1) {
        // 0x800929D0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800929E0;
    }
    // 0x800929D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800929D4: jal         0x800C31EC
    // 0x800929D8: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_19;
    // 0x800929D8: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_19:
    // 0x800929DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800929E0:
    // 0x800929E0: b           L_80092B18
    // 0x800929E4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
        goto L_80092B18;
    // 0x800929E4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_800929E8:
    // 0x800929E8: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x800929EC: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x800929F0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800929F4: bne         $at, $zero, L_80092A68
    if (ctx->r1 != 0) {
        // 0x800929F8: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80092A68;
    }
    // 0x800929F8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800929FC: beq         $t6, $zero, L_80092B18
    if (ctx->r14 == 0) {
        // 0x80092A00: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80092B18;
    }
    // 0x80092A00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092A04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80092A08: bne         $v0, $at, L_80092A3C
    if (ctx->r2 != ctx->r1) {
        // 0x80092A0C: sw          $t7, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r15;
            goto L_80092A3C;
    }
    // 0x80092A0C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80092A10: jal         0x8009EC60
    // 0x80092A14: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_20;
    // 0x80092A14: nop

    after_20:
    // 0x80092A18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092A1C: addiu       $t4, $t4, 0x63E0
    ctx->r12 = ADD32(ctx->r12, 0X63E0);
    // 0x80092A20: beq         $v0, $zero, L_80092A3C
    if (ctx->r2 == 0) {
        // 0x80092A24: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80092A3C;
    }
    // 0x80092A24: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092A28: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80092A2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092A30: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x80092A34: b           L_80092A50
    // 0x80092A38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
        goto L_80092A50;
    // 0x80092A38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80092A3C:
    // 0x80092A3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092A40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092A44: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x80092A48: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
    // 0x80092A4C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80092A50:
    // 0x80092A50: bne         $v0, $at, L_80092B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80092A54: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80092B1C;
    }
    // 0x80092A54: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80092A58: jal         0x800C31EC
    // 0x80092A5C: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_21;
    // 0x80092A5C: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_21:
    // 0x80092A60: b           L_80092B1C
    // 0x80092A64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
        goto L_80092B1C;
    // 0x80092A64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80092A68:
    // 0x80092A68: lw          $t2, -0xB44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB44);
    // 0x80092A6C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80092A70: bne         $ra, $t2, L_80092A98
    if (ctx->r31 != ctx->r10) {
        // 0x80092A74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80092A98;
    }
    // 0x80092A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092A78: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80092A7C: nop

    // 0x80092A80: andi        $t8, $t9, 0x4000
    ctx->r24 = ctx->r25 & 0X4000;
    // 0x80092A84: beq         $t8, $zero, L_80092B1C
    if (ctx->r24 == 0) {
        // 0x80092A88: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80092B1C;
    }
    // 0x80092A88: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80092A8C: sw          $ra, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r31;
    // 0x80092A90: b           L_80092B18
    // 0x80092A94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
        goto L_80092B18;
    // 0x80092A94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
L_80092A98:
    // 0x80092A98: bne         $t2, $at, L_80092AB8
    if (ctx->r10 != ctx->r1) {
        // 0x80092A9C: andi        $t6, $v1, 0x4000
        ctx->r14 = ctx->r3 & 0X4000;
            goto L_80092AB8;
    }
    // 0x80092A9C: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80092AA0: beq         $t6, $zero, L_80092B18
    if (ctx->r14 == 0) {
        // 0x80092AA4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80092B18;
    }
    // 0x80092AA4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80092AA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80092AAC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80092AB0: b           L_80092B18
    // 0x80092AB4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_80092B18;
    // 0x80092AB4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80092AB8:
    // 0x80092AB8: blez        $t2, L_80092B18
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80092ABC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80092B18;
    }
    // 0x80092ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092AC0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80092AC4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092AC8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80092ACC: addiu       $t1, $t1, -0xB80
    ctx->r9 = ADD32(ctx->r9, -0XB80);
    // 0x80092AD0: addiu       $t3, $t3, 0x69C4
    ctx->r11 = ADD32(ctx->r11, 0X69C4);
    // 0x80092AD4: addiu       $t0, $t0, 0x67D8
    ctx->r8 = ADD32(ctx->r8, 0X67D8);
L_80092AD8:
    // 0x80092AD8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80092ADC: nop

    // 0x80092AE0: andi        $t6, $t8, 0x4000
    ctx->r14 = ctx->r24 & 0X4000;
    // 0x80092AE4: beq         $t6, $zero, L_80092B08
    if (ctx->r14 == 0) {
        // 0x80092AE8: addu        $t8, $t3, $a1
        ctx->r24 = ADD32(ctx->r11, ctx->r5);
            goto L_80092B08;
    }
    // 0x80092AE8: addu        $t8, $t3, $a1
    ctx->r24 = ADD32(ctx->r11, ctx->r5);
    // 0x80092AEC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80092AF0: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80092AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092AF8: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80092AFC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80092B00: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80092B04: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80092B08:
    // 0x80092B08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80092B0C: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80092B10: bne         $at, $zero, L_80092AD8
    if (ctx->r1 != 0) {
        // 0x80092B14: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80092AD8;
    }
    // 0x80092B14: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80092B18:
    // 0x80092B18: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80092B1C:
    // 0x80092B1C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80092B20: beq         $t7, $zero, L_80092B38
    if (ctx->r15 == 0) {
        // 0x80092B24: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80092B38;
    }
    // 0x80092B24: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80092B28: jal         0x80001D04
    // 0x80092B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x80092B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80092B30: b           L_80092B68
    // 0x80092B34: nop

        goto L_80092B68;
    // 0x80092B34: nop

L_80092B38:
    // 0x80092B38: beq         $t9, $zero, L_80092B50
    if (ctx->r25 == 0) {
        // 0x80092B3C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80092B50;
    }
    // 0x80092B3C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80092B40: jal         0x80001D04
    // 0x80092B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x80092B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80092B48: b           L_80092B68
    // 0x80092B4C: nop

        goto L_80092B68;
    // 0x80092B4C: nop

L_80092B50:
    // 0x80092B50: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80092B54: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80092B58: beq         $t8, $zero, L_80092B68
    if (ctx->r24 == 0) {
        // 0x80092B5C: nop
    
            goto L_80092B68;
    }
    // 0x80092B5C: nop

    // 0x80092B60: jal         0x80001D04
    // 0x80092B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_24;
    // 0x80092B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
L_80092B68:
    // 0x80092B68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092B6C: lb          $a0, 0x69C0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X69C0);
    // 0x80092B70: jal         0x8006DB14
    // 0x80092B74: nop

    set_level_default_vehicle(rdram, ctx);
        goto after_25;
    // 0x80092B74: nop

    after_25:
    // 0x80092B78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80092B7C: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x80092B80: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80092B84: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80092B88: beq         $at, $zero, L_80092BA4
    if (ctx->r1 == 0) {
        // 0x80092B8C: nop
    
            goto L_80092BA4;
    }
    // 0x80092B8C: nop

    // 0x80092B90: lw          $t7, 0x69C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69C8);
    // 0x80092B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092B98: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80092B9C: bne         $at, $zero, L_80092BB4
    if (ctx->r1 != 0) {
        // 0x80092BA0: nop
    
            goto L_80092BB4;
    }
    // 0x80092BA0: nop

L_80092BA4:
    // 0x80092BA4: jal         0x8000E4BC
    // 0x80092BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_26;
    // 0x80092BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x80092BAC: b           L_80092BC0
    // 0x80092BB0: nop

        goto L_80092BC0;
    // 0x80092BB0: nop

L_80092BB4:
    // 0x80092BB4: lw          $a0, 0x414($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X414);
    // 0x80092BB8: jal         0x8000E4BC
    // 0x80092BBC: nop

    set_time_trial_enabled(rdram, ctx);
        goto after_27;
    // 0x80092BBC: nop

    after_27:
L_80092BC0:
    // 0x80092BC0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80092BC4: lw          $t9, 0x418($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X418);
    // 0x80092BC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092BCC: sw          $t9, -0xB6C($at)
    MEM_W(-0XB6C, ctx->r1) = ctx->r25;
    // 0x80092BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80092BD4:
    // 0x80092BD4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80092BD8: jr          $ra
    // 0x80092BDC: nop

    return;
    // 0x80092BDC: nop

;}
RECOMP_FUNC void mtxf_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5E0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006F5E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006F5E8: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F5EC:
    // 0x8006F5EC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F5F0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F5F4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F5F8: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F5FC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F600: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F604: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F608: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F60C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F610: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006F614: nop

    // 0x8006F618: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006F61C: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006F620: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006F624: swc1        $f4, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f4.u32l;
    // 0x8006F628: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006F62C: swc1        $f6, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
    // 0x8006F630: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006F634: swc1        $f8, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8006F638: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8006F63C: bnel        $t0, $zero, L_8006F5EC
    if (ctx->r8 != 0) {
        // 0x8006F640: nop
    
            goto L_8006F5EC;
    }
    goto skip_0;
    // 0x8006F640: nop

    skip_0:
    // 0x8006F644: jr          $ra
    // 0x8006F648: nop

    return;
    // 0x8006F648: nop

;}
RECOMP_FUNC void mark_to_read_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EB28: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EB2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EB30: nop

    // 0x8006EB34: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8006EB38: jr          $ra
    // 0x8006EB3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EB3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void arctan2_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8007066C:
    // 0x80070750: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80070754: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80070758: nop

    // 0x8007075C: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80070760: nop

    // 0x80070764: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80070768: cvt.w.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8007076C: cvt.w.s     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80070770: mfc1        $a0, $f12
    ctx->r4 = (int32_t)ctx->f12.u32l;
    // 0x80070774: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80070778: j           L_8007066C
    // 0x8007077C: nop

    atan2s(rdram, ctx);
    return;
    // 0x8007077C: nop

;}
RECOMP_FUNC void func_80079760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079768: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007976C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079770: lw          $t6, 0x264($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X264);
    // 0x80079774: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80079778: beq         $t6, $zero, L_80079784
    if (ctx->r14 == 0) {
        // 0x8007977C: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_80079784;
    }
    // 0x8007977C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80079780: sw          $t7, 0x284($a0)
    MEM_W(0X284, ctx->r4) = ctx->r15;
L_80079784:
    // 0x80079784: lw          $t8, 0x284($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X284);
    // 0x80079788: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8007978C: beq         $t8, $zero, L_800797B4
    if (ctx->r24 == 0) {
        // 0x80079790: nop
    
            goto L_800797B4;
    }
    // 0x80079790: nop

    // 0x80079794: lw          $t9, 0x274($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X274);
    // 0x80079798: nop

    // 0x8007979C: beq         $t9, $zero, L_800797B4
    if (ctx->r25 == 0) {
        // 0x800797A0: nop
    
            goto L_800797B4;
    }
    // 0x800797A0: nop

    // 0x800797A4: jal         0x8007A080
    // 0x800797A8: nop

    static_3_8007A080(rdram, ctx);
        goto after_0;
    // 0x800797A8: nop

    after_0:
    // 0x800797AC: b           L_800797FC
    // 0x800797B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800797FC;
    // 0x800797B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800797B4:
    // 0x800797B4: lw          $t0, 0x274($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X274);
    // 0x800797B8: lw          $t3, 0x278($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X278);
    // 0x800797BC: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800797C0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800797C4: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800797C8: or          $a3, $t2, $t4
    ctx->r7 = ctx->r10 | ctx->r12;
    // 0x800797CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800797D0: jal         0x8007A0D4
    // 0x800797D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    static_3_8007A0D4(rdram, ctx);
        goto after_1;
    // 0x800797D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800797D8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800797DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800797E0: beq         $v0, $a3, L_800797FC
    if (ctx->r2 == ctx->r7) {
        // 0x800797E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800797FC;
    }
    // 0x800797E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800797E8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800797EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800797F0: jal         0x80079FA8
    // 0x800797F4: nop

    static_3_80079FA8(rdram, ctx);
        goto after_2;
    // 0x800797F4: nop

    after_2:
    // 0x800797F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800797FC:
    // 0x800797FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079800: jr          $ra
    // 0x80079804: nop

    return;
    // 0x80079804: nop

;}
RECOMP_FUNC void func_8001D248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D248: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D24C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001D250: jr          $ra
    // 0x8001D254: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8001D254: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_loop_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F58: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80038F5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80038F60: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80038F64: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80038F68: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80038F6C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80038F70: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80038F74: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80038F78: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80038F7C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80038F80: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80038F84: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80038F88: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80038F8C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80038F90: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80038F94: lw          $s5, 0x64($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X64);
    // 0x80038F98: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80038F9C: jal         0x8006EA90
    // 0x80038FA0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038FA0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_0:
    // 0x80038FA4: lb          $v1, 0x14($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X14);
    // 0x80038FA8: nop

    // 0x80038FAC: bne         $v1, $zero, L_80038FDC
    if (ctx->r3 != 0) {
        // 0x80038FB0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80038FDC;
    }
    // 0x80038FB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038FB4: lbu         $t7, 0x48($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X48);
    // 0x80038FB8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80038FBC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80038FC0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80038FC4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80038FC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80038FCC: bne         $t0, $at, L_80038FDC
    if (ctx->r8 != ctx->r1) {
        // 0x80038FD0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80038FDC;
    }
    // 0x80038FD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038FD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038FD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80038FDC:
    // 0x80038FDC: bne         $v1, $at, L_8003900C
    if (ctx->r3 != ctx->r1) {
        // 0x80038FE0: nop
    
            goto L_8003900C;
    }
    // 0x80038FE0: nop

    // 0x80038FE4: lbu         $t2, 0x48($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X48);
    // 0x80038FE8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80038FEC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80038FF0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80038FF4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80038FF8: nop

    // 0x80038FFC: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x80039000: beq         $at, $zero, L_8003900C
    if (ctx->r1 == 0) {
        // 0x80039004: nop
    
            goto L_8003900C;
    }
    // 0x80039004: nop

    // 0x80039008: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003900C:
    // 0x8003900C: beq         $s0, $zero, L_80039128
    if (ctx->r16 == 0) {
        // 0x80039010: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039128;
    }
    // 0x80039010: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039014: lw          $t7, 0x4C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4C);
    // 0x80039018: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x8003901C: lbu         $t6, 0x13($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X13);
    // 0x80039020: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80039024: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039028: beq         $at, $zero, L_80039128
    if (ctx->r1 == 0) {
        // 0x8003902C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80039128;
    }
    // 0x8003902C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80039030: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80039034: jal         0x8001BA74
    // 0x80039038: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80039038: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_1:
    // 0x8003903C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80039040: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80039044: blez        $t8, L_80039124
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80039048: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80039124;
    }
    // 0x80039048: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003904C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80039050: addiu       $s7, $zero, -0x78
    ctx->r23 = ADD32(0, -0X78);
    // 0x80039054: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80039058:
    // 0x80039058: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003905C: nop

    // 0x80039060: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80039064: nop

    // 0x80039068: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8003906C: nop

    // 0x80039070: beq         $s6, $t9, L_80039114
    if (ctx->r22 == ctx->r25) {
        // 0x80039074: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039114;
    }
    // 0x80039074: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039078: lw          $t0, 0x108($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X108);
    // 0x8003907C: nop

    // 0x80039080: bne         $t0, $zero, L_80039114
    if (ctx->r8 != 0) {
        // 0x80039084: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039114;
    }
    // 0x80039084: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039088: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003908C: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80039090: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80039094: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80039098: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8003909C: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800390A0: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800390A4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800390A8: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800390AC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800390B0: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800390B4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800390B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800390BC: jal         0x800C9AD0
    // 0x800390C0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800390C0: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_2:
    // 0x800390C4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800390C8: nop

    // 0x800390CC: bc1f        L_80039114
    if (!c1cs) {
        // 0x800390D0: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039114;
    }
    // 0x800390D0: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800390D4: lwc1        $f18, 0x0($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800390D8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800390DC: lwc1        $f8, 0x8($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800390E0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800390E4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800390E8: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x800390EC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800390F0: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800390F4: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800390F8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800390FC: nop

    // 0x80039100: bc1f        L_80039114
    if (!c1cs) {
        // 0x80039104: lw          $t2, 0x74($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X74);
            goto L_80039114;
    }
    // 0x80039104: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80039108: sw          $s4, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->r20;
    // 0x8003910C: sb          $s7, 0x200($s1)
    MEM_B(0X200, ctx->r17) = ctx->r23;
    // 0x80039110: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80039114:
    // 0x80039114: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80039118: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003911C: bne         $at, $zero, L_80039058
    if (ctx->r1 != 0) {
        // 0x80039120: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80039058;
    }
    // 0x80039120: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80039124:
    // 0x80039124: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80039128:
    // 0x80039128: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8003912C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80039130: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80039134: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80039138: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003913C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80039140: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80039144: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80039148: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8003914C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80039150: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80039154: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80039158: jr          $ra
    // 0x8003915C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8003915C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void set_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA7C: addiu       $v0, $v0, 0x6448
    ctx->r2 = ADD32(ctx->r2, 0X6448);
    // 0x8009EA80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009EA84: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009EA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EA90: or          $t0, $t6, $a0
    ctx->r8 = ctx->r14 | ctx->r4;
    // 0x8009EA94: or          $t1, $t7, $a1
    ctx->r9 = ctx->r15 | ctx->r5;
    // 0x8009EA98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EA9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009EAA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009EAA4: jal         0x8006ECE0
    // 0x8009EAA8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009EAA8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_0:
    // 0x8009EAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EAB4: jr          $ra
    // 0x8009EAB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009EAB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void get_timestamp_from_frames(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059790: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059794: lw          $t6, 0x6170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6170);
    // 0x80059798: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8005979C: bne         $t6, $at, L_800597E8
    if (ctx->r14 != ctx->r1) {
        // 0x800597A0: addiu       $t0, $zero, 0xE10
        ctx->r8 = ADD32(0, 0XE10);
            goto L_800597E8;
    }
    // 0x800597A0: addiu       $t0, $zero, 0xE10
    ctx->r8 = ADD32(0, 0XE10);
    // 0x800597A4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800597A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800597AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800597B0: lwc1        $f11, 0x6928($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6928);
    // 0x800597B4: lwc1        $f10, 0x692C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X692C);
    // 0x800597B8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800597BC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800597C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800597C4: nop

    // 0x800597C8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800597CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800597D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800597D4: nop

    // 0x800597D8: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800597DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800597E0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800597E4: nop

L_800597E8:
    // 0x800597E8: div         $zero, $a0, $t0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r8)));
    // 0x800597EC: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x800597F0: bne         $t0, $zero, L_800597FC
    if (ctx->r8 != 0) {
        // 0x800597F4: nop
    
            goto L_800597FC;
    }
    // 0x800597F4: nop

    // 0x800597F8: break       7
    do_break(2147850232);
L_800597FC:
    // 0x800597FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059800: bne         $t0, $at, L_80059814
    if (ctx->r8 != ctx->r1) {
        // 0x80059804: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059814;
    }
    // 0x80059804: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80059808: bne         $a0, $at, L_80059814
    if (ctx->r4 != ctx->r1) {
        // 0x8005980C: nop
    
            goto L_80059814;
    }
    // 0x8005980C: nop

    // 0x80059810: break       6
    do_break(2147850256);
L_80059814:
    // 0x80059814: mflo        $v0
    ctx->r2 = lo;
    // 0x80059818: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005981C: nop

    // 0x80059820: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059824: mflo        $t8
    ctx->r24 = lo;
    // 0x80059828: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x8005982C: nop

    // 0x80059830: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x80059834: bne         $t1, $zero, L_80059840
    if (ctx->r9 != 0) {
        // 0x80059838: nop
    
            goto L_80059840;
    }
    // 0x80059838: nop

    // 0x8005983C: break       7
    do_break(2147850300);
L_80059840:
    // 0x80059840: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059844: bne         $t1, $at, L_80059858
    if (ctx->r9 != ctx->r1) {
        // 0x80059848: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80059858;
    }
    // 0x80059848: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005984C: bne         $t9, $at, L_80059858
    if (ctx->r25 != ctx->r1) {
        // 0x80059850: nop
    
            goto L_80059858;
    }
    // 0x80059850: nop

    // 0x80059854: break       6
    do_break(2147850324);
L_80059858:
    // 0x80059858: mflo        $v1
    ctx->r3 = lo;
    // 0x8005985C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80059860: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80059864: nop

    // 0x80059868: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005986C: mflo        $t3
    ctx->r11 = lo;
    // 0x80059870: subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // 0x80059874: nop

    // 0x80059878: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005987C: mflo        $t5
    ctx->r13 = lo;
    // 0x80059880: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80059884: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80059888: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005988C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80059890: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80059894: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059898: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x8005989C: bne         $t1, $zero, L_800598A8
    if (ctx->r9 != 0) {
        // 0x800598A0: nop
    
            goto L_800598A8;
    }
    // 0x800598A0: nop

    // 0x800598A4: break       7
    do_break(2147850404);
L_800598A8:
    // 0x800598A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800598AC: bne         $t1, $at, L_800598C0
    if (ctx->r9 != ctx->r1) {
        // 0x800598B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800598C0;
    }
    // 0x800598B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800598B4: bne         $t7, $at, L_800598C0
    if (ctx->r15 != ctx->r1) {
        // 0x800598B8: nop
    
            goto L_800598C0;
    }
    // 0x800598B8: nop

    // 0x800598BC: break       6
    do_break(2147850428);
L_800598C0:
    // 0x800598C0: mflo        $t8
    ctx->r24 = lo;
    // 0x800598C4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800598C8: jr          $ra
    // 0x800598CC: nop

    return;
    // 0x800598CC: nop

;}
RECOMP_FUNC void level_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BDB4: lw          $v0, 0x1168($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1168);
    // 0x8006BDB8: jr          $ra
    // 0x8006BDBC: nop

    return;
    // 0x8006BDBC: nop

;}
RECOMP_FUNC void func_80098774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098774: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80098778: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8009877C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80098780: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80098784: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80098788: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009878C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80098790: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80098794: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80098798: jal         0x8006EA90
    // 0x8009879C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009879C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800987A0: beq         $s6, $zero, L_800987C0
    if (ctx->r22 == 0) {
        // 0x800987A4: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800987C0;
    }
    // 0x800987A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800987A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800987AC: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x800987B0: nop

    // 0x800987B4: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x800987B8: b           L_800987D4
    // 0x800987BC: nop

        goto L_800987D4;
    // 0x800987BC: nop

L_800987C0:
    // 0x800987C0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800987C4: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x800987C8: nop

    // 0x800987CC: lw          $v1, 0x7C($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X7C);
    // 0x800987D0: nop

L_800987D4:
    // 0x800987D4: addiu       $a1, $a1, 0x1048
    ctx->r5 = ADD32(ctx->r5, 0X1048);
    // 0x800987D8: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
    // 0x800987DC: sw          $v1, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r3;
    // 0x800987E0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800987E4: lw          $t1, 0xFE4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFE4);
    // 0x800987E8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800987EC: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800987F0: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x800987F4: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800987F8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800987FC: bne         $t9, $zero, L_8009880C
    if (ctx->r25 != 0) {
        // 0x80098800: addiu       $a3, $zero, 0xF0
        ctx->r7 = ADD32(0, 0XF0);
            goto L_8009880C;
    }
    // 0x80098800: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x80098804: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x80098808: addiu       $a3, $zero, 0x108
    ctx->r7 = ADD32(0, 0X108);
L_8009880C:
    // 0x8009880C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098810: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80098814: addiu       $v1, $v1, 0x14BC
    ctx->r3 = ADD32(ctx->r3, 0X14BC);
    // 0x80098818: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8009881C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80098820: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80098824: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80098828: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8009882C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80098830: beq         $a2, $zero, L_800989F0
    if (ctx->r6 == 0) {
        // 0x80098834: addiu       $s0, $zero, 0x2
        ctx->r16 = ADD32(0, 0X2);
            goto L_800989F0;
    }
    // 0x80098834: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80098838: beq         $a0, $zero, L_800989F4
    if (ctx->r4 == 0) {
        // 0x8009883C: sll         $t6, $s0, 5
        ctx->r14 = S32(ctx->r16 << 5);
            goto L_800989F4;
    }
    // 0x8009883C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x80098840: blez        $t1, L_800989F0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80098844: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800989F0;
    }
    // 0x80098844: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80098848: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x8009884C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80098850: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80098854: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80098858: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009885C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80098860: addiu       $t5, $t5, 0xAF0
    ctx->r13 = ADD32(ctx->r13, 0XAF0);
    // 0x80098864: addiu       $s3, $s3, 0x6430
    ctx->r19 = ADD32(ctx->r19, 0X6430);
    // 0x80098868: addiu       $s4, $s4, 0x6428
    ctx->r20 = ADD32(ctx->r20, 0X6428);
    // 0x8009886C: addiu       $s5, $s5, 0x1004
    ctx->r21 = ADD32(ctx->r21, 0X1004);
    // 0x80098870: addu        $t3, $a1, $t7
    ctx->r11 = ADD32(ctx->r5, ctx->r15);
    // 0x80098874: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x80098878: andi        $s1, $t1, 0x3
    ctx->r17 = ctx->r9 & 0X3;
    // 0x8009887C: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x80098880: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
L_80098884:
    // 0x80098884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098888: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_8009888C:
    // 0x8009888C: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x80098890: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80098894: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80098898: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8009889C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800988A0: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
    // 0x800988A4: lh          $t6, -0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X2);
    // 0x800988A8: bne         $at, $zero, L_800988F0
    if (ctx->r1 != 0) {
        // 0x800988AC: sh          $t6, 0x8($v1)
        MEM_H(0X8, ctx->r3) = ctx->r14;
            goto L_800988F0;
    }
    // 0x800988AC: sh          $t6, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r14;
    // 0x800988B0: sra         $t7, $t1, 1
    ctx->r15 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800988B4: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800988B8: bne         $at, $zero, L_800988F0
    if (ctx->r1 != 0) {
        // 0x800988BC: nop
    
            goto L_800988F0;
    }
    // 0x800988BC: nop

    // 0x800988C0: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800988C4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800988C8: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800988CC: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x800988D0: lh          $t6, -0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, -0X2);
    // 0x800988D4: nop

    // 0x800988D8: sh          $t6, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r14;
    // 0x800988DC: lh          $t7, -0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, -0X2);
    // 0x800988E0: nop

    // 0x800988E4: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800988E8: b           L_8009891C
    // 0x800988EC: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
        goto L_8009891C;
    // 0x800988EC: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
L_800988F0:
    // 0x800988F0: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800988F4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800988F8: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x800988FC: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80098900: lh          $t7, -0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, -0X2);
    // 0x80098904: nop

    // 0x80098908: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x8009890C: lh          $t8, -0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, -0X2);
    // 0x80098910: nop

    // 0x80098914: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x80098918: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
L_8009891C:
    // 0x8009891C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80098920: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x80098924: bne         $at, $zero, L_8009888C
    if (ctx->r1 != 0) {
        // 0x80098928: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_8009888C;
    }
    // 0x80098928: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009892C: beq         $s1, $zero, L_80098948
    if (ctx->r17 == 0) {
        // 0x80098930: addiu       $s0, $s0, 0x3
        ctx->r16 = ADD32(ctx->r16, 0X3);
            goto L_80098948;
    }
    // 0x80098930: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x80098934: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80098938: bne         $at, $zero, L_8009894C
    if (ctx->r1 != 0) {
        // 0x8009893C: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_8009894C;
    }
    // 0x8009893C: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x80098940: b           L_8009894C
    // 0x80098944: addiu       $t2, $t0, -0x3
    ctx->r10 = ADD32(ctx->r8, -0X3);
        goto L_8009894C;
    // 0x80098944: addiu       $t2, $t0, -0x3
    ctx->r10 = ADD32(ctx->r8, -0X3);
L_80098948:
    // 0x80098948: andi        $t2, $t0, 0x3
    ctx->r10 = ctx->r8 & 0X3;
L_8009894C:
    // 0x8009894C: sll         $t6, $t2, 6
    ctx->r14 = S32(ctx->r10 << 6);
    // 0x80098950: subu        $t7, $s2, $t6
    ctx->r15 = SUB32(ctx->r18, ctx->r14);
    // 0x80098954: beq         $s6, $zero, L_80098998
    if (ctx->r22 == 0) {
        // 0x80098958: sb          $t7, 0x4D($t3)
        MEM_B(0X4D, ctx->r11) = ctx->r15;
            goto L_80098998;
    }
    // 0x80098958: sb          $t7, 0x4D($t3)
    MEM_B(0X4D, ctx->r11) = ctx->r15;
    // 0x8009895C: addu        $t8, $s3, $t0
    ctx->r24 = ADD32(ctx->r19, ctx->r8);
    // 0x80098960: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80098964: nop

    // 0x80098968: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009896C: mflo        $t6
    ctx->r14 = lo;
    // 0x80098970: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80098974: lb          $t7, 0x59($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X59);
    // 0x80098978: nop

    // 0x8009897C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80098980: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    { extern uint32_t dkr_legacy_character_portrait_lookup(uint8_t*, recomp_context*, uint32_t); uint32_t cell = dkr_legacy_character_portrait_lookup(rdram, ctx, (uint32_t)ctx->r3); if (cell) ctx->r25 = (int32_t)cell; }
    // 0x80098984: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80098988: addiu       $t7, $v1, 0x54
    ctx->r15 = ADD32(ctx->r3, 0X54);
    // 0x8009898C: sw          $t7, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r15;
    // 0x80098990: b           L_800989D4
    // 0x80098994: sw          $t6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r14;
        goto L_800989D4;
    // 0x80098994: sw          $t6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r14;
L_80098998:
    // 0x80098998: addu        $t8, $s4, $t0
    ctx->r24 = ADD32(ctx->r20, ctx->r8);
    // 0x8009899C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800989A0: nop

    // 0x800989A4: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800989A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800989AC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800989B0: lb          $t8, 0x59($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X59);
    // 0x800989B4: nop

    // 0x800989B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800989BC: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    { extern uint32_t dkr_legacy_character_portrait_lookup(uint8_t*, recomp_context*, uint32_t); uint32_t cell = dkr_legacy_character_portrait_lookup(rdram, ctx, (uint32_t)ctx->r15); if (cell) ctx->r14 = (int32_t)cell; }
    // 0x800989C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800989C4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800989C8: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x800989CC: sw          $t9, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r25;
    // 0x800989D0: sw          $t7, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r15;
L_800989D4:
    // 0x800989D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800989D8: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800989DC: addiu       $t4, $t4, 0x60
    ctx->r12 = ADD32(ctx->r12, 0X60);
    // 0x800989E0: bne         $at, $zero, L_80098884
    if (ctx->r1 != 0) {
        // 0x800989E4: addiu       $t3, $t3, 0x60
        ctx->r11 = ADD32(ctx->r11, 0X60);
            goto L_80098884;
    }
    // 0x800989E4: addiu       $t3, $t3, 0x60
    ctx->r11 = ADD32(ctx->r11, 0X60);
    // 0x800989E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800989EC: addiu       $a1, $a1, 0x1048
    ctx->r5 = ADD32(ctx->r5, 0X1048);
L_800989F0:
    // 0x800989F0: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
L_800989F4:
    // 0x800989F4: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800989F8: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x800989FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80098A00: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80098A04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80098A08: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80098A0C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80098A10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80098A14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80098A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80098A1C: jr          $ra
    // 0x80098A20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80098A20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_init_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80034B6C: jr          $ra
    // 0x80034B70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80034B70: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void level_is_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B240: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B244: lw          $v0, -0x2CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2CE4);
    // 0x8006B248: jr          $ra
    // 0x8006B24C: nop

    return;
    // 0x8006B24C: nop

;}
RECOMP_FUNC void func_80072C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C54: bgtz        $a0, L_80072C64
    if (SIGNED(ctx->r4) > 0) {
        // 0x80072C58: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80072C64;
    }
    // 0x80072C58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80072C5C: jr          $ra
    // 0x80072C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80072C60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072C64:
    // 0x80072C64: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x80072C68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80072C6C: beq         $a0, $zero, L_80072E1C
    if (ctx->r4 == 0) {
        // 0x80072C70: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_80072E1C;
    }
    // 0x80072C70: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80072C74: andi        $a1, $a0, 0x3
    ctx->r5 = ctx->r4 & 0X3;
    // 0x80072C78: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80072C7C: beq         $a1, $zero, L_80072CF4
    if (ctx->r5 == 0) {
        // 0x80072C80: addu        $t0, $a1, $a0
        ctx->r8 = ADD32(ctx->r5, ctx->r4);
            goto L_80072CF4;
    }
    // 0x80072C80: addu        $t0, $a1, $a0
    ctx->r8 = ADD32(ctx->r5, ctx->r4);
    // 0x80072C84: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072C88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072C8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072C90: addiu       $t1, $t1, 0x41F4
    ctx->r9 = ADD32(ctx->r9, 0X41F4);
    // 0x80072C94: addiu       $t2, $t2, 0x41F0
    ctx->r10 = ADD32(ctx->r10, 0X41F0);
    // 0x80072C98: addiu       $t3, $t3, 0x41EC
    ctx->r11 = ADD32(ctx->r11, 0X41EC);
    // 0x80072C9C: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072CA0:
    // 0x80072CA0: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072CA4: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80072CA8: bne         $a2, $zero, L_80072CCC
    if (ctx->r6 != 0) {
        // 0x80072CAC: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072CCC;
    }
    // 0x80072CAC: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072CB0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072CB4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072CB8: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x80072CBC: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x80072CC0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80072CC4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072CC8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80072CCC:
    // 0x80072CCC: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80072CD0: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072CD4: and         $t7, $t5, $a2
    ctx->r15 = ctx->r13 & ctx->r6;
    // 0x80072CD8: beq         $t7, $zero, L_80072CE4
    if (ctx->r15 == 0) {
        // 0x80072CDC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80072CE4;
    }
    // 0x80072CDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80072CE0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072CE4:
    // 0x80072CE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072CE8: bne         $t0, $a1, L_80072CA0
    if (ctx->r8 != ctx->r5) {
        // 0x80072CEC: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072CA0;
    }
    // 0x80072CEC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072CF0: beq         $a1, $zero, L_80072E1C
    if (ctx->r5 == 0) {
        // 0x80072CF4: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80072E1C;
    }
L_80072CF4:
    // 0x80072CF4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072CF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80072CFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072D00: addiu       $t3, $t3, 0x41EC
    ctx->r11 = ADD32(ctx->r11, 0X41EC);
    // 0x80072D04: addiu       $t2, $t2, 0x41F0
    ctx->r10 = ADD32(ctx->r10, 0X41F0);
    // 0x80072D08: addiu       $t1, $t1, 0x41F4
    ctx->r9 = ADD32(ctx->r9, 0X41F4);
    // 0x80072D0C: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
L_80072D10:
    // 0x80072D10: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80072D14: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072D18: bne         $a2, $zero, L_80072D3C
    if (ctx->r6 != 0) {
        // 0x80072D1C: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80072D3C;
    }
    // 0x80072D1C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80072D20: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072D24: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072D28: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80072D2C: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072D30: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072D34: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072D38: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_80072D3C:
    // 0x80072D3C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80072D40: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072D44: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072D48: beq         $t7, $zero, L_80072D54
    if (ctx->r15 == 0) {
        // 0x80072D4C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80072D54;
    }
    // 0x80072D4C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072D50: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072D54:
    // 0x80072D54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072D58: bne         $t8, $zero, L_80072D7C
    if (ctx->r24 != 0) {
        // 0x80072D5C: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80072D7C;
    }
    // 0x80072D5C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072D60: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072D64: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072D68: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80072D6C: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072D70: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072D74: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072D78: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80072D7C:
    // 0x80072D7C: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072D80: beq         $t7, $zero, L_80072D8C
    if (ctx->r15 == 0) {
        // 0x80072D84: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072D8C;
    }
    // 0x80072D84: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072D88: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072D8C:
    // 0x80072D8C: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072D90: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072D94: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072D98: bne         $t8, $zero, L_80072DBC
    if (ctx->r24 != 0) {
        // 0x80072D9C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80072DBC;
    }
    // 0x80072D9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072DA0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072DA4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072DA8: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80072DAC: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072DB0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072DB4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072DB8: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80072DBC:
    // 0x80072DBC: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072DC0: beq         $t7, $zero, L_80072DCC
    if (ctx->r15 == 0) {
        // 0x80072DC4: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072DCC;
    }
    // 0x80072DC4: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072DC8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072DCC:
    // 0x80072DCC: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072DD0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072DD4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80072DD8: bne         $t8, $zero, L_80072DFC
    if (ctx->r24 != 0) {
        // 0x80072DDC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80072DFC;
    }
    // 0x80072DDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072DE0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80072DE4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80072DE8: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x80072DEC: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x80072DF0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80072DF4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80072DF8: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
L_80072DFC:
    // 0x80072DFC: and         $t7, $a1, $a2
    ctx->r15 = ctx->r5 & ctx->r6;
    // 0x80072E00: beq         $t7, $zero, L_80072E0C
    if (ctx->r15 == 0) {
        // 0x80072E04: srl         $t6, $v0, 1
        ctx->r14 = S32(U32(ctx->r2) >> 1);
            goto L_80072E0C;
    }
    // 0x80072E04: srl         $t6, $v0, 1
    ctx->r14 = S32(U32(ctx->r2) >> 1);
    // 0x80072E08: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_80072E0C:
    // 0x80072E0C: srl         $t8, $a2, 1
    ctx->r24 = S32(U32(ctx->r6) >> 1);
    // 0x80072E10: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80072E14: bne         $a0, $zero, L_80072D10
    if (ctx->r4 != 0) {
        // 0x80072E18: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80072D10;
    }
    // 0x80072E18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80072E1C:
    // 0x80072E1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80072E20: jr          $ra
    // 0x80072E24: nop

    return;
    // 0x80072E24: nop

;}
RECOMP_FUNC void set_current_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5000: blez        $a0, L_800C5048
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5004: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5048;
    }
    // 0x800C5004: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5008: beq         $at, $zero, L_800C5048
    if (ctx->r1 == 0) {
        // 0x800C500C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5048;
    }
    // 0x800C500C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5010: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5014: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C5018: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C501C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5020: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5024: sb          $a1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r5;
    // 0x800C5028: sb          $a2, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r6;
    // 0x800C502C: sb          $a3, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r7;
    // 0x800C5030: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5034: nop

    // 0x800C5038: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
    // 0x800C503C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C5040: nop

    // 0x800C5044: sb          $t9, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r25;
L_800C5048:
    // 0x800C5048: jr          $ra
    // 0x800C504C: nop

    return;
    // 0x800C504C: nop

;}
RECOMP_FUNC void func_800230D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800230D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800230D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800230D8: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x800230DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800230E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800230E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800230E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800230EC: bne         $v0, $zero, L_800231B8
    if (ctx->r2 != 0) {
        // 0x800230F0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800231B8;
    }
    // 0x800230F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800230F4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800230F8: addiu       $a3, $a3, -0x51A4
    ctx->r7 = ADD32(ctx->r7, -0X51A4);
    // 0x800230FC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80023100: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80023104: blez        $a0, L_800231B0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80023108: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800231B0;
    }
    // 0x80023108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002310C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80023110: addiu       $a1, $a1, -0x51A8
    ctx->r5 = ADD32(ctx->r5, -0X51A8);
    // 0x80023114: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_80023118:
    // 0x80023118: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8002311C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023120: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80023124: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x80023128: nop

    // 0x8002312C: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80023130: nop

    // 0x80023134: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x80023138: bne         $t1, $zero, L_8002319C
    if (ctx->r9 != 0) {
        // 0x8002313C: nop
    
            goto L_8002319C;
    }
    // 0x8002313C: nop

    // 0x80023140: lh          $t2, 0x48($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X48);
    // 0x80023144: nop

    // 0x80023148: bne         $a2, $t2, L_8002319C
    if (ctx->r6 != ctx->r10) {
        // 0x8002314C: nop
    
            goto L_8002319C;
    }
    // 0x8002314C: nop

    // 0x80023150: lw          $t3, 0x78($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X78);
    // 0x80023154: nop

    // 0x80023158: bne         $t3, $zero, L_800231A0
    if (ctx->r11 != 0) {
        // 0x8002315C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800231A0;
    }
    // 0x8002315C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023160: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80023164: nop

    // 0x80023168: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8002316C: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80023170: nop

    // 0x80023174: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80023178: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8002317C: nop

    // 0x80023180: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80023184: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
    // 0x80023188: nop

    // 0x8002318C: sh          $t4, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r12;
    // 0x80023190: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80023194: nop

    // 0x80023198: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8002319C:
    // 0x8002319C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800231A0:
    // 0x800231A0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800231A4: bne         $at, $zero, L_80023118
    if (ctx->r1 != 0) {
        // 0x800231A8: nop
    
            goto L_80023118;
    }
    // 0x800231A8: nop

    // 0x800231AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
L_800231B0:
    // 0x800231B0: b           L_8002322C
    // 0x800231B4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_8002322C;
    // 0x800231B4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800231B8:
    // 0x800231B8: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x800231BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800231C0: lw          $t6, -0x5134($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5134);
    // 0x800231C4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800231C8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800231CC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800231D0: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800231D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800231D8: lwc1        $f16, -0x34($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X34);
    // 0x800231DC: lwc1        $f10, -0x2C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, -0X2C);
    // 0x800231E0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800231E4: addiu       $t0, $t0, -0x3C
    ctx->r8 = ADD32(ctx->r8, -0X3C);
    // 0x800231E8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800231EC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800231F0: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800231F4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800231F8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800231FC: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80023200: lwc1        $f8, 0x18($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80023204: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80023208: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002320C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023210: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80023214: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80023218: jal         0x80029F18
    // 0x8002321C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x8002321C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80023220: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80023224: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x80023228: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_8002322C:
    // 0x8002322C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80023230: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80023234: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x80023238: jal         0x8002BAB0
    // 0x8002323C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    collision_get_y(rdram, ctx);
        goto after_1;
    // 0x8002323C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80023240: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80023244: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80023248: beq         $v0, $zero, L_80023260
    if (ctx->r2 == 0) {
        // 0x8002324C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80023260;
    }
    // 0x8002324C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80023250: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80023254: lwc1        $f4, 0x2C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x80023258: nop

    // 0x8002325C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_80023260:
    // 0x80023260: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023264: nop

    // 0x80023268: swc1        $f6, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f6.u32l;
    // 0x8002326C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023270: nop

    // 0x80023274: swc1        $f16, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f16.u32l;
    // 0x80023278: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002327C: beq         $t0, $zero, L_800232A0
    if (ctx->r8 == 0) {
        // 0x80023280: swc1        $f8, 0x64($s1)
        MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
            goto L_800232A0;
    }
    // 0x80023280: swc1        $f8, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f8.u32l;
    // 0x80023284: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80023288: lwc1        $f14, 0x8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8002328C: jal         0x80070750
    // 0x80023290: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x80023290: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80023294: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80023298: b           L_800232AC
    // 0x8002329C: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
        goto L_800232AC;
    // 0x8002329C: sh          $v0, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r2;
L_800232A0:
    // 0x800232A0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800232A4: nop

    // 0x800232A8: sh          $t9, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r25;
L_800232AC:
    // 0x800232AC: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x800232B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800232B4: lw          $t2, -0x5130($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5130);
    // 0x800232B8: lb          $t1, 0x193($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X193);
    // 0x800232BC: lh          $t4, 0x1A0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1A0);
    // 0x800232C0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800232C4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800232C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800232CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800232D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800232D4: sh          $t3, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r11;
    // 0x800232D8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800232DC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x800232E0: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x800232E4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800232E8: nop

    // 0x800232EC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800232F0: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x800232F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800232F8: nop

    // 0x800232FC: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x80023300: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023304: nop

    // 0x80023308: swc1        $f16, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f16.u32l;
    // 0x8002330C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023310: nop

    // 0x80023314: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80023318: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x8002331C: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023320: nop

    // 0x80023324: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x80023328: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002332C: nop

    // 0x80023330: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x80023334: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023338: nop

    // 0x8002333C: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80023340: swc1        $f16, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f16.u32l;
    // 0x80023344: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023348: nop

    // 0x8002334C: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x80023350: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023354: nop

    // 0x80023358: swc1        $f10, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f10.u32l;
    // 0x8002335C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023360: nop

    // 0x80023364: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80023368: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002336C: swc1        $f4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f4.u32l;
    // 0x80023370: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80023374: nop

    // 0x80023378: swc1        $f6, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f6.u32l;
    // 0x8002337C: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x80023380: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80023384: nop

    // 0x80023388: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x8002338C: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x80023390: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80023394: nop

    // 0x80023398: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x8002339C: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x800233A0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233A4: nop

    // 0x800233A8: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x800233AC: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800233B0: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    // 0x800233B4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800233B8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800233BC: lb          $t8, 0x1D7($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1D7);
    // 0x800233C0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x800233C4: sb          $t8, 0x1D6($s1)
    MEM_B(0X1D6, ctx->r17) = ctx->r24;
    // 0x800233C8: beq         $a0, $at, L_80023408
    if (ctx->r4 == ctx->r1) {
        // 0x800233CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80023408;
    }
    // 0x800233CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800233D0: jal         0x800665E8
    // 0x800233D4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    set_active_camera(rdram, ctx);
        goto after_3;
    // 0x800233D4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_3:
    // 0x800233D8: jal         0x80069CFC
    // 0x800233DC: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_4;
    // 0x800233DC: nop

    after_4:
    // 0x800233E0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800233E4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800233E8: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x800233EC: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800233F0: nop

    // 0x800233F4: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800233F8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800233FC: nop

    // 0x80023400: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80023404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80023408:
    // 0x80023408: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002340C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023410: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80023414: jr          $ra
    // 0x80023418: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80023418: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void alCSPGetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C00: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80063C04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80063C08: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80063C0C: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80063C10: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80063C14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80063C18: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80063C1C: lbu         $v0, 0x10($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X10);
    // 0x80063C20: jr          $ra
    // 0x80063C24: nop

    return;
    // 0x80063C24: nop

;}
RECOMP_FUNC void sound_volume_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000096C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000974: beq         $a0, $at, L_8000099C
    if (ctx->r4 == ctx->r1) {
        // 0x80000978: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000099C;
    }
    // 0x80000978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000980: beq         $a0, $at, L_80000A14
    if (ctx->r4 == ctx->r1) {
        // 0x80000984: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A14;
    }
    // 0x80000984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000098C: beq         $a0, $at, L_80000A48
    if (ctx->r4 == ctx->r1) {
        // 0x80000990: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80000A48;
    }
    // 0x80000990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000994: b           L_80000A7C
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80000A7C;
    // 0x80000998: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000099C:
    // 0x8000099C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800009A0: jal         0x80004A60
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x800009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800009A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800009AC: jal         0x80004A60
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800009B0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x800009B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800009B8: jal         0x80004A60
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800009C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800009C4: jal         0x80004A60
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x800009C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800009CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800009D0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800009D4: lw          $t8, -0x39AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39AC);
    // 0x800009D8: lbu         $t7, -0x39C8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X39C8);
    // 0x800009DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800009E0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800009E4: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800009E8: mflo        $a1
    ctx->r5 = lo;
    // 0x800009EC: sra         $t9, $a1, 2
    ctx->r25 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800009F0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800009F4: jal         0x800C7850
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_4;
    // 0x800009F8: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x800009FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000A00: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80000A04: jal         0x800C7850
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alCSPSetVol(rdram, ctx);
        goto after_5;
    // 0x80000A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80000A0C: b           L_80000B04
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A10: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A14:
    // 0x80000A14: jal         0x80004A60
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_6;
    // 0x80000A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80000A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A20: jal         0x80004A60
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_7;
    // 0x80000A24: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_7:
    // 0x80000A28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A2C: jal         0x80004A60
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_8;
    // 0x80000A30: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_8:
    // 0x80000A34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A38: jal         0x80004A60
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_9;
    // 0x80000A3C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_9:
    // 0x80000A40: b           L_80000B04
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A44: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A48:
    // 0x80000A48: jal         0x80004A60
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_10;
    // 0x80000A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80000A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A54: jal         0x80004A60
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_11;
    // 0x80000A58: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_11:
    // 0x80000A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A60: jal         0x80004A60
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_12;
    // 0x80000A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80000A68: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000A6C: jal         0x80004A60
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_13;
    // 0x80000A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80000A74: b           L_80000B04
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
        goto L_80000B04;
    // 0x80000A78: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000A7C:
    // 0x80000A7C: jal         0x80004A60
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x80000A80: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x80000A84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000A88: jal         0x80004A60
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x80000A8C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x80000A90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000A94: jal         0x80004A60
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_16;
    // 0x80000A98: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_16:
    // 0x80000A9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000AA0: jal         0x80004A60
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_17;
    // 0x80000AA4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_17:
    // 0x80000AA8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80000AAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80000AB0: lw          $t3, -0x39AC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X39AC);
    // 0x80000AB4: lbu         $t2, -0x39C8($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X39C8);
    // 0x80000AB8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000ABC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AC0: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80000AC4: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AC8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80000ACC: jal         0x800C7850
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_18;
    // 0x80000AD0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_18:
    // 0x80000AD4: jal         0x8000317C
    // 0x80000AD8: nop

    sndp_get_global_volume(rdram, ctx);
        goto after_19;
    // 0x80000AD8: nop

    after_19:
    // 0x80000ADC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000AE0: lbu         $t6, -0x39C4($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X39C4);
    // 0x80000AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000AE8: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80000AEC: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80000AF0: mflo        $a1
    ctx->r5 = lo;
    // 0x80000AF4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80000AF8: jal         0x800C7850
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_20;
    // 0x80000AFC: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_20:
    // 0x80000B00: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80000B04:
    // 0x80000B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000B08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000B10: jr          $ra
    // 0x80000B14: sb          $t9, 0x5F79($at)
    MEM_B(0X5F79, ctx->r1) = ctx->r25;
    return;
    // 0x80000B14: sb          $t9, 0x5F79($at)
    MEM_B(0X5F79, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 1U)) return; extern void dkr_custom_tracks_asset_load_begin(uint8_t*, recomp_context*); dkr_custom_tracks_asset_load_begin(rdram, ctx);
    // 0x80076E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80076E74: beq         $a3, $zero, L_80076E9C
    if (ctx->r7 == 0) {
        // 0x80076E78: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80076E9C;
    }
    // 0x80076E78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80076E7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80076E80: lw          $t0, 0x4290($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4290);
    // 0x80076E84: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80076E88: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80076E8C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80076E90: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076E94: beq         $at, $zero, L_80076EA4
    if (ctx->r1 == 0) {
        // 0x80076E98: sll         $t1, $t9, 2
        ctx->r9 = S32(ctx->r25 << 2);
            goto L_80076EA4;
    }
    // 0x80076E98: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
L_80076E9C:
    // 0x80076E9C: b           L_80076ED8
    // 0x80076EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076ED8;
    // 0x80076EA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076EA4:
    // 0x80076EA4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80076EA8: addu        $v0, $t1, $t0
    ctx->r2 = ADD32(ctx->r9, ctx->r8);
    // 0x80076EAC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80076EB0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80076EB4: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x80076EB8: addiu       $t4, $t4, -0x33D0
    ctx->r12 = ADD32(ctx->r12, -0X33D0);
    // 0x80076EBC: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80076EC0: addu        $a0, $v1, $t4
    ctx->r4 = ADD32(ctx->r3, ctx->r12);
    // 0x80076EC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80076EC8: jal         0x80076F78
    // 0x80076ECC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    dmacopy(rdram, ctx);
        goto after_0;
    // 0x80076ECC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    extern void dkr_custom_tracks_asset_load_end(uint8_t*, recomp_context*); dkr_custom_tracks_asset_load_end(rdram, ctx);
    // 0x80076ED0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80076ED4: nop

L_80076ED8:
    // 0x80076ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076EE0: jr          $ra
    // 0x80076EE4: nop

    return;
    // 0x80076EE4: nop

;}
RECOMP_FUNC void racerfx_get_boost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BF48: bne         $a0, $at, L_8000BF5C
    if (ctx->r4 != ctx->r1) {
        // 0x8000BF4C: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BF4C: nop

    // 0x8000BF50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF54: lw          $a0, -0x38A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X38A0);
    // 0x8000BF58: nop

L_8000BF5C:
    // 0x8000BF5C: bltz        $a0, L_8000BF6C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000BF60: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_8000BF6C;
    }
    // 0x8000BF60: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8000BF64: bne         $at, $zero, L_8000BF74
    if (ctx->r1 != 0) {
        // 0x8000BF68: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8000BF74;
    }
    // 0x8000BF68: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_8000BF6C:
    // 0x8000BF6C: jr          $ra
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BF74:
    // 0x8000BF74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BF78: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BF7C: lw          $v0, -0x4FE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4FE0);
    // 0x8000BF80: nop

    // 0x8000BF84: jr          $ra
    // 0x8000BF88: nop

    return;
    // 0x8000BF88: nop

;}
RECOMP_FUNC void sound_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002128: beq         $a0, $zero, L_8000213C
    if (ctx->r4 == 0) {
        // 0x8000212C: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_8000213C;
    }
    // 0x8000212C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002130: lw          $t6, 0x5D18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D18);
    // 0x80002134: nop

    // 0x80002138: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8000213C:
    // 0x8000213C: beq         $a1, $zero, L_80002150
    if (ctx->r5 == 0) {
        // 0x80002140: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002150;
    }
    // 0x80002140: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002144: lw          $t7, 0x5D28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D28);
    // 0x80002148: nop

    // 0x8000214C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002150:
    // 0x80002150: beq         $a2, $zero, L_80002164
    if (ctx->r6 == 0) {
        // 0x80002154: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_80002164;
    }
    // 0x80002154: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80002158: lw          $t8, 0x5D20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5D20);
    // 0x8000215C: nop

    // 0x80002160: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80002164:
    // 0x80002164: jr          $ra
    // 0x80002168: nop

    return;
    // 0x80002168: nop

;}
RECOMP_FUNC void hud_main_hub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A26CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A26D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A26D4: jal         0x80066210
    // 0x800A26D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800A26D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A26DC: bne         $v0, $zero, L_800A2770
    if (ctx->r2 != 0) {
        // 0x800A26E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A2770;
    }
    // 0x800A26E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A26E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A26E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A26EC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800A26F0: jal         0x80068508
    // 0x800A26F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A26F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x800A26F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A26FC: jal         0x800A718C
    // 0x800A2700: nop

    hud_balloons(rdram, ctx);
        goto after_2;
    // 0x800A2700: nop

    after_2:
    // 0x800A2704: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2708: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A270C: jal         0x800A3884
    // 0x800A2710: nop

    hud_speedometre(rdram, ctx);
        goto after_3;
    // 0x800A2710: nop

    after_3:
    // 0x800A2714: jal         0x8009EC80
    // 0x800A2718: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x800A2718: nop

    after_4:
    // 0x800A271C: beq         $v0, $zero, L_800A2764
    if (ctx->r2 == 0) {
        // 0x800A2720: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800A2764;
    }
    // 0x800A2720: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A2724: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A2728: nop

    // 0x800A272C: addiu       $a3, $a3, 0x720
    ctx->r7 = ADD32(ctx->r7, 0X720);
    // 0x800A2730: jal         0x8006EA90
    // 0x800A2734: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x800A2734: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A2738: lb          $t8, 0x71($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X71);
    // 0x800A273C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A2740: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2744: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2748: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A274C: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A2750: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A2754: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A2758: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    { extern void dkr_legacy_character_hud_bind(uint8_t*, recomp_context*, uint32_t, uint32_t); dkr_legacy_character_hud_bind(rdram, ctx, (uint32_t)ctx->r7 + 0U, (uint32_t)(1U)); }
    // 0x800A275C: jal         0x800AA600
    // 0x800A2760: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A2760: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    after_6:
L_800A2764:
    { extern void dkr_legacy_character_hud_unbind(uint8_t*, recomp_context*); dkr_legacy_character_hud_unbind(rdram, ctx); }
    // 0x800A2764: jal         0x80068508
    // 0x800A2768: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A2768: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A276C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2770:
    // 0x800A2770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A2774: jr          $ra
    // 0x800A2778: nop

    return;
    // 0x800A2778: nop

;}
RECOMP_FUNC void obj_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800101AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800101B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800101B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800101B8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800101BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800101C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800101C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800101C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800101CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800101D0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800101D4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x800101D8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800101DC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800101E0: beq         $t7, $zero, L_8001020C
    if (ctx->r15 == 0) {
        // 0x800101E4: nop
    
            goto L_8001020C;
    }
    // 0x800101E4: nop

    // 0x800101E8: jal         0x800B2040
    // 0x800101EC: nop

    particle_deallocate(rdram, ctx);
        goto after_0;
    // 0x800101EC: nop

    after_0:
    // 0x800101F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800101F4: addiu       $v0, $v0, -0x519C
    ctx->r2 = ADD32(ctx->r2, -0X519C);
    // 0x800101F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800101FC: nop

    // 0x80010200: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80010204: b           L_8001096C
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8001096C;
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001020C:
    // 0x8001020C: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x80010210: nop

    // 0x80010214: beq         $v1, $zero, L_800102E4
    if (ctx->r3 == 0) {
        // 0x80010218: nop
    
            goto L_800102E4;
    }
    // 0x80010218: nop

    // 0x8001021C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010220: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010224: blez        $t0, L_800102E4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010228: nop
    
            goto L_800102E4;
    }
    // 0x80010228: nop

    // 0x8001022C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010230: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_80010234:
    // 0x80010234: lw          $s1, 0x4($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X4);
    // 0x80010238: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001023C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80010240: nop

    // 0x80010244: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x80010248: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x8001024C: bne         $a0, $zero, L_80010288
    if (ctx->r4 != 0) {
        // 0x80010250: nop
    
            goto L_80010288;
    }
    // 0x80010250: nop

    // 0x80010254: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80010258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x80010258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001025C:
    // 0x8001025C: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80010260: nop

    // 0x80010264: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80010268: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8001026C: jal         0x8005FF40
    // 0x80010270: nop

    free_3d_model(rdram, ctx);
        goto after_1;
    // 0x80010270: nop

    after_1:
    // 0x80010274: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010278: bne         $s3, $s2, L_8001025C
    if (ctx->r19 != ctx->r18) {
        // 0x8001027C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001025C;
    }
    // 0x8001027C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010280: b           L_800102B8
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
        goto L_800102B8;
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_80010288:
    // 0x80010288: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001028C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x8001028C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010290:
    // 0x80010290: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80010294: nop

    // 0x80010298: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8001029C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800102A0: jal         0x8007CCB0
    // 0x800102A4: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800102A4: nop

    after_2:
    // 0x800102A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800102AC: bne         $s3, $s2, L_80010290
    if (ctx->r19 != ctx->r18) {
        // 0x800102B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010290;
    }
    // 0x800102B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800102B4:
    // 0x800102B4: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_800102B8:
    // 0x800102B8: jal         0x8000C844
    // 0x800102BC: nop

    try_free_object_header(rdram, ctx);
        goto after_3;
    // 0x800102BC: nop

    after_3:
    // 0x800102C0: jal         0x80071140
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800102C8: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x800102CC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800102D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800102D4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800102D8: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800102DC: bne         $at, $zero, L_80010234
    if (ctx->r1 != 0) {
        // 0x800102E0: addu        $t1, $v1, $s4
        ctx->r9 = ADD32(ctx->r3, ctx->r20);
            goto L_80010234;
    }
    // 0x800102E0: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_800102E4:
    // 0x800102E4: lw          $t7, 0x70($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X70);
    // 0x800102E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800102EC: beq         $t7, $zero, L_80010344
    if (ctx->r15 == 0) {
        // 0x800102F0: nop
    
            goto L_80010344;
    }
    // 0x800102F0: nop

    // 0x800102F4: lw          $t8, 0x40($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X40);
    // 0x800102F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800102FC: lb          $t9, 0x5A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X5A);
    // 0x80010300: nop

    // 0x80010304: blez        $t9, L_80010344
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80010308: nop
    
            goto L_80010344;
    }
    // 0x80010308: nop

    // 0x8001030C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80010310:
    // 0x80010310: lw          $t0, 0x70($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X70);
    // 0x80010314: nop

    // 0x80010318: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8001031C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010320: jal         0x80032BAC
    // 0x80010324: nop

    light_remove(rdram, ctx);
        goto after_5;
    // 0x80010324: nop

    after_5:
    // 0x80010328: lw          $t2, 0x40($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X40);
    // 0x8001032C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80010330: lb          $t3, 0x5A($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X5A);
    // 0x80010334: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80010338: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001033C: bne         $at, $zero, L_80010310
    if (ctx->r1 != 0) {
        // 0x80010340: nop
    
            goto L_80010310;
    }
    // 0x80010340: nop

L_80010344:
    // 0x80010344: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010348: nop

    // 0x8001034C: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x80010350: sltiu       $at, $t4, 0x74
    ctx->r1 = ctx->r12 < 0X74 ? 1 : 0;
    // 0x80010354: beq         $at, $zero, L_800105F8
    if (ctx->r1 == 0) {
        // 0x80010358: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800105F8;
    }
    // 0x80010358: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001035C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80010360: addu        $at, $at, $t4
    gpr jr_addend_8001036C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80010364: lw          $t4, 0x5250($at)
    ctx->r12 = ADD32(ctx->r1, 0X5250);
    // 0x80010368: nop

    // 0x8001036C: jr          $t4
    // 0x80010370: nop

    switch (jr_addend_8001036C >> 2) {
        case 0: goto L_80010374; break;
        case 1: goto L_800105F8; break;
        case 2: goto L_800105F8; break;
        case 3: goto L_800105F8; break;
        case 4: goto L_80010400; break;
        case 5: goto L_800105F8; break;
        case 6: goto L_800105F8; break;
        case 7: goto L_800105F8; break;
        case 8: goto L_800105F8; break;
        case 9: goto L_800105F8; break;
        case 10: goto L_800105F8; break;
        case 11: goto L_800105F8; break;
        case 12: goto L_800105F8; break;
        case 13: goto L_800105F8; break;
        case 14: goto L_800105F8; break;
        case 15: goto L_800105F8; break;
        case 16: goto L_800105F8; break;
        case 17: goto L_80010400; break;
        case 18: goto L_800105F8; break;
        case 19: goto L_800105F8; break;
        case 20: goto L_800105F8; break;
        case 21: goto L_800105F8; break;
        case 22: goto L_800105F8; break;
        case 23: goto L_800105F8; break;
        case 24: goto L_800105F8; break;
        case 25: goto L_800105F8; break;
        case 26: goto L_800105F8; break;
        case 27: goto L_800105F8; break;
        case 28: goto L_800105F8; break;
        case 29: goto L_800105F8; break;
        case 30: goto L_800105F8; break;
        case 31: goto L_800105F8; break;
        case 32: goto L_800104C0; break;
        case 33: goto L_800105F8; break;
        case 34: goto L_800105F8; break;
        case 35: goto L_800105A8; break;
        case 36: goto L_800105F8; break;
        case 37: goto L_800105F8; break;
        case 38: goto L_800105F8; break;
        case 39: goto L_800105F8; break;
        case 40: goto L_800105F8; break;
        case 41: goto L_800105F8; break;
        case 42: goto L_800105D0; break;
        case 43: goto L_800105E4; break;
        case 44: goto L_800105F8; break;
        case 45: goto L_800105F8; break;
        case 46: goto L_800105F8; break;
        case 47: goto L_800105F8; break;
        case 48: goto L_800104D8; break;
        case 49: goto L_800105F8; break;
        case 50: goto L_800105F8; break;
        case 51: goto L_800105F8; break;
        case 52: goto L_800105F8; break;
        case 53: goto L_800105F8; break;
        case 54: goto L_800105F8; break;
        case 55: goto L_800105F8; break;
        case 56: goto L_800105F8; break;
        case 57: goto L_800105F8; break;
        case 58: goto L_800104AC; break;
        case 59: goto L_800105F8; break;
        case 60: goto L_800105F8; break;
        case 61: goto L_800105F8; break;
        case 62: goto L_800105F8; break;
        case 63: goto L_800105F8; break;
        case 64: goto L_800105F8; break;
        case 65: goto L_800105F8; break;
        case 66: goto L_800105A8; break;
        case 67: goto L_800105F8; break;
        case 68: goto L_800105F8; break;
        case 69: goto L_800105F8; break;
        case 70: goto L_800105F8; break;
        case 71: goto L_800105F8; break;
        case 72: goto L_800105F8; break;
        case 73: goto L_800105F8; break;
        case 74: goto L_800105F8; break;
        case 75: goto L_800105F8; break;
        case 76: goto L_800105F8; break;
        case 77: goto L_800105F8; break;
        case 78: goto L_800105F8; break;
        case 79: goto L_800105F8; break;
        case 80: goto L_800105F8; break;
        case 81: goto L_800105F8; break;
        case 82: goto L_80010508; break;
        case 83: goto L_800105F8; break;
        case 84: goto L_80010374; break;
        case 85: goto L_800105F8; break;
        case 86: goto L_800105F8; break;
        case 87: goto L_800105F8; break;
        case 88: goto L_800105F8; break;
        case 89: goto L_800105F8; break;
        case 90: goto L_800105F8; break;
        case 91: goto L_800105F8; break;
        case 92: goto L_800105F8; break;
        case 93: goto L_800105F8; break;
        case 94: goto L_800105F8; break;
        case 95: goto L_8001047C; break;
        case 96: goto L_8001047C; break;
        case 97: goto L_800105F8; break;
        case 98: goto L_800105F8; break;
        case 99: goto L_800105F8; break;
        case 100: goto L_8001047C; break;
        case 101: goto L_8001047C; break;
        case 102: goto L_800105F8; break;
        case 103: goto L_800105F8; break;
        case 104: goto L_800105F8; break;
        case 105: goto L_800105F8; break;
        case 106: goto L_800105F8; break;
        case 107: goto L_800105F8; break;
        case 108: goto L_800105F8; break;
        case 109: goto L_800105F8; break;
        case 110: goto L_800105F8; break;
        case 111: goto L_800105F8; break;
        case 112: goto L_800105F8; break;
        case 113: goto L_800105F8; break;
        case 114: goto L_800105F8; break;
        case 115: goto L_8001044C; break;
        default: switch_error(__func__, 0x8001036C, 0x800E5250);
    }
    // 0x80010370: nop

L_80010374:
    // 0x80010374: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010378: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x8001037C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010380: blez        $v1, L_800103F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010384: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800103F8;
    }
    // 0x80010384: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001038C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
L_80010390:
    // 0x80010390: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80010394: lw          $t5, -0x51A8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X51A8);
    // 0x80010398: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001039C: addu        $t6, $t5, $s4
    ctx->r14 = ADD32(ctx->r13, ctx->r20);
    // 0x800103A0: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800103A4: nop

    // 0x800103A8: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x800103AC: nop

    // 0x800103B0: bne         $a0, $t7, L_800103E8
    if (ctx->r4 != ctx->r15) {
        // 0x800103B4: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103B4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103B8: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x800103BC: nop

    // 0x800103C0: lw          $t8, 0x100($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X100);
    // 0x800103C4: nop

    // 0x800103C8: bne         $s6, $t8, L_800103E8
    if (ctx->r22 != ctx->r24) {
        // 0x800103CC: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103CC: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103D0: sw          $zero, 0x100($v0)
    MEM_W(0X100, ctx->r2) = 0;
    // 0x800103D4: sb          $a1, 0xFD($v0)
    MEM_B(0XFD, ctx->r2) = ctx->r5;
    // 0x800103D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800103DC: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x800103E0: nop

    // 0x800103E4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
L_800103E8:
    // 0x800103E8: bne         $at, $zero, L_80010390
    if (ctx->r1 != 0) {
        // 0x800103EC: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80010390;
    }
    // 0x800103EC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800103F0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800103F4: nop

L_800103F8:
    // 0x800103F8: b           L_800105FC
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010400:
    // 0x80010400: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010404: nop

    // 0x80010408: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8001040C: nop

    // 0x80010410: beq         $a0, $zero, L_80010444
    if (ctx->r4 == 0) {
        // 0x80010414: nop
    
            goto L_80010444;
    }
    // 0x80010414: nop

    // 0x80010418: jal         0x800096F8
    // 0x8001041C: nop

    audspat_point_stop(rdram, ctx);
        goto after_6;
    // 0x8001041C: nop

    after_6:
    // 0x80010420: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80010424: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010428: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x8001042C: bne         $s4, $a1, L_80010444
    if (ctx->r20 != ctx->r5) {
        // 0x80010430: nop
    
            goto L_80010444;
    }
    // 0x80010430: nop

    // 0x80010434: jal         0x8003F0DC
    // 0x80010438: nop

    decrease_rocket_sound_timer(rdram, ctx);
        goto after_7;
    // 0x80010438: nop

    after_7:
    // 0x8001043C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010440: nop

L_80010444:
    // 0x80010444: b           L_800105FC
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001044C:
    // 0x8001044C: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010450: nop

    // 0x80010454: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80010458: nop

    // 0x8001045C: beq         $a0, $zero, L_80010474
    if (ctx->r4 == 0) {
        // 0x80010460: nop
    
            goto L_80010474;
    }
    // 0x80010460: nop

    // 0x80010464: jal         0x800096F8
    // 0x80010468: nop

    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x80010468: nop

    after_8:
    // 0x8001046C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010470: nop

L_80010474:
    // 0x80010474: b           L_800105FC
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001047C:
    // 0x8001047C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010480: nop

    // 0x80010484: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x80010488: nop

    // 0x8001048C: beq         $v1, $zero, L_800104A4
    if (ctx->r3 == 0) {
        // 0x80010490: nop
    
            goto L_800104A4;
    }
    // 0x80010490: nop

    // 0x80010494: jal         0x800096F8
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_9;
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_9:
    // 0x8001049C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104A0: nop

L_800104A4:
    // 0x800104A4: b           L_800105FC
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104AC:
    // 0x800104AC: jal         0x800BF3E4
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    wavegen_destroy(rdram, ctx);
        goto after_10;
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_10:
    // 0x800104B4: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104B8: b           L_800105FC
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104C0:
    // 0x800104C0: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104C4: jal         0x80032BAC
    // 0x800104C8: nop

    light_remove(rdram, ctx);
        goto after_11;
    // 0x800104C8: nop

    after_11:
    // 0x800104CC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104D0: b           L_800105FC
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104D8:
    // 0x800104D8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800104E0: beq         $a0, $zero, L_80010500
    if (ctx->r4 == 0) {
        // 0x800104E4: nop
    
            goto L_80010500;
    }
    // 0x800104E4: nop

    // 0x800104E8: bne         $t9, $zero, L_80010500
    if (ctx->r25 != 0) {
        // 0x800104EC: nop
    
            goto L_80010500;
    }
    // 0x800104EC: nop

    // 0x800104F0: jal         0x8000FFB8
    // 0x800104F4: nop

    free_object(rdram, ctx);
        goto after_12;
    // 0x800104F4: nop

    after_12:
    // 0x800104F8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104FC: nop

L_80010500:
    // 0x80010500: b           L_800105FC
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010508:
    // 0x80010508: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001050C: addiu       $a0, $a0, -0x5200
    ctx->r4 = ADD32(ctx->r4, -0X5200);
    // 0x80010510: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010514: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010518: blez        $v1, L_80010554
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001051C: addiu       $s4, $zero, 0x12
        ctx->r20 = ADD32(0, 0X12);
            goto L_80010554;
    }
    // 0x8001051C: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x80010520: lw          $t0, -0x5228($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5228);
    // 0x80010524: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010528: beq         $s6, $t0, L_80010554
    if (ctx->r22 == ctx->r8) {
        // 0x8001052C: addiu       $v0, $v0, -0x5228
        ctx->r2 = ADD32(ctx->r2, -0X5228);
            goto L_80010554;
    }
    // 0x8001052C: addiu       $v0, $v0, -0x5228
    ctx->r2 = ADD32(ctx->r2, -0X5228);
L_80010530:
    // 0x80010530: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010534: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010538: beq         $at, $zero, L_80010554
    if (ctx->r1 == 0) {
        // 0x8001053C: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_80010554;
    }
    // 0x8001053C: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80010540: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80010544: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80010548: nop

    // 0x8001054C: bne         $s6, $t3, L_80010530
    if (ctx->r22 != ctx->r11) {
        // 0x80010550: nop
    
            goto L_80010530;
    }
    // 0x80010550: nop

L_80010554:
    // 0x80010554: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010558: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x8001055C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8001059C;
    }
    // 0x8001055C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80010560: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80010564: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010568: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8001056C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010570: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x80010574: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001059C;
    }
    // 0x80010574: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80010578: addiu       $t6, $t6, -0x5228
    ctx->r14 = ADD32(ctx->r14, -0X5228);
    // 0x8001057C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80010580: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    // 0x80010584: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_80010588:
    // 0x80010588: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8001058C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010590: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80010594: bne         $at, $zero, L_80010588
    if (ctx->r1 != 0) {
        // 0x80010598: sw          $t8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r24;
            goto L_80010588;
    }
    // 0x80010598: sw          $t8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r24;
L_8001059C:
    // 0x8001059C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105A0: b           L_800105FC
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800105FC;
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800105A8:
    // 0x800105A8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800105AC: nop

    // 0x800105B0: beq         $a0, $zero, L_800105C8
    if (ctx->r4 == 0) {
        // 0x800105B4: nop
    
            goto L_800105C8;
    }
    // 0x800105B4: nop

    // 0x800105B8: jal         0x80071140
    // 0x800105BC: nop

    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800105BC: nop

    after_13:
    // 0x800105C0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105C4: nop

L_800105C8:
    // 0x800105C8: b           L_800105FC
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105D0:
    // 0x800105D0: jal         0x800AC880
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_remove(rdram, ctx);
        goto after_14;
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_14:
    // 0x800105D8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105DC: b           L_800105FC
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105E4:
    // 0x800105E4: jal         0x800ACF98
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_override_remove(rdram, ctx);
        goto after_15;
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_15:
    // 0x800105EC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105F0: b           L_800105FC
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105F8:
    // 0x800105F8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105FC:
    // 0x800105FC: slti        $at, $a1, 0xD
    ctx->r1 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // 0x80010600: bne         $at, $zero, L_80010630
    if (ctx->r1 != 0) {
        // 0x80010604: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80010630;
    }
    // 0x80010604: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80010608: addiu       $t9, $v0, -0x32
    ctx->r25 = ADD32(ctx->r2, -0X32);
    // 0x8001060C: sltiu       $at, $t9, 0x46
    ctx->r1 = ctx->r25 < 0X46 ? 1 : 0;
    // 0x80010610: beq         $at, $zero, L_80010664
    if (ctx->r1 == 0) {
        // 0x80010614: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80010664;
    }
    // 0x80010614: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80010618: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001061C: addu        $at, $at, $t9
    gpr jr_addend_80010628 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80010620: lw          $t9, 0x5420($at)
    ctx->r25 = ADD32(ctx->r1, 0X5420);
    // 0x80010624: nop

    // 0x80010628: jr          $t9
    // 0x8001062C: nop

    switch (jr_addend_80010628 >> 2) {
        case 0: goto L_8001063C; break;
        case 1: goto L_8001063C; break;
        case 2: goto L_80010664; break;
        case 3: goto L_8001063C; break;
        case 4: goto L_8001063C; break;
        case 5: goto L_80010664; break;
        case 6: goto L_8001063C; break;
        case 7: goto L_80010664; break;
        case 8: goto L_80010664; break;
        case 9: goto L_80010664; break;
        case 10: goto L_80010664; break;
        case 11: goto L_80010664; break;
        case 12: goto L_80010664; break;
        case 13: goto L_80010664; break;
        case 14: goto L_80010664; break;
        case 15: goto L_80010664; break;
        case 16: goto L_80010664; break;
        case 17: goto L_80010664; break;
        case 18: goto L_80010664; break;
        case 19: goto L_80010664; break;
        case 20: goto L_8001063C; break;
        case 21: goto L_80010664; break;
        case 22: goto L_8001063C; break;
        case 23: goto L_80010664; break;
        case 24: goto L_80010664; break;
        case 25: goto L_80010664; break;
        case 26: goto L_80010664; break;
        case 27: goto L_80010664; break;
        case 28: goto L_80010664; break;
        case 29: goto L_80010664; break;
        case 30: goto L_8001063C; break;
        case 31: goto L_8001063C; break;
        case 32: goto L_80010664; break;
        case 33: goto L_80010664; break;
        case 34: goto L_8001063C; break;
        case 35: goto L_8001063C; break;
        case 36: goto L_8001063C; break;
        case 37: goto L_80010664; break;
        case 38: goto L_80010664; break;
        case 39: goto L_80010664; break;
        case 40: goto L_80010664; break;
        case 41: goto L_80010664; break;
        case 42: goto L_80010664; break;
        case 43: goto L_80010664; break;
        case 44: goto L_80010664; break;
        case 45: goto L_80010664; break;
        case 46: goto L_8001063C; break;
        case 47: goto L_8001063C; break;
        case 48: goto L_80010664; break;
        case 49: goto L_80010664; break;
        case 50: goto L_80010664; break;
        case 51: goto L_8001063C; break;
        case 52: goto L_8001063C; break;
        case 53: goto L_8001063C; break;
        case 54: goto L_8001063C; break;
        case 55: goto L_80010664; break;
        case 56: goto L_80010664; break;
        case 57: goto L_80010664; break;
        case 58: goto L_80010664; break;
        case 59: goto L_80010664; break;
        case 60: goto L_80010664; break;
        case 61: goto L_80010664; break;
        case 62: goto L_80010664; break;
        case 63: goto L_8001063C; break;
        case 64: goto L_80010664; break;
        case 65: goto L_8001063C; break;
        case 66: goto L_80010664; break;
        case 67: goto L_80010664; break;
        case 68: goto L_80010664; break;
        case 69: goto L_8001063C; break;
        default: switch_error(__func__, 0x80010628, 0x800E5420);
    }
    // 0x8001062C: nop

L_80010630:
    // 0x80010630: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80010634: bne         $v0, $at, L_80010668
    if (ctx->r2 != ctx->r1) {
        // 0x80010638: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8001063C:
    // 0x8001063C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010640: nop

    // 0x80010644: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80010648: nop

    // 0x8001064C: beq         $a0, $zero, L_80010668
    if (ctx->r4 == 0) {
        // 0x80010650: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010650: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010654: jal         0x8000488C
    // 0x80010658: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x80010658: nop

    after_16:
    // 0x8001065C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010660: nop

L_80010664:
    // 0x80010664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80010668:
    // 0x80010668: bne         $a1, $at, L_800107F0
    if (ctx->r5 != ctx->r1) {
        // 0x8001066C: nop
    
            goto L_800107F0;
    }
    // 0x8001066C: nop

    // 0x80010670: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010674: nop

    // 0x80010678: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8001067C: nop

    // 0x80010680: beq         $v0, $zero, L_80010690
    if (ctx->r2 == 0) {
        // 0x80010684: nop
    
            goto L_80010690;
    }
    // 0x80010684: nop

    // 0x80010688: jal         0x8000488C
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_17;
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
L_80010690:
    // 0x80010690: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80010694: nop

    // 0x80010698: beq         $v0, $zero, L_800106A8
    if (ctx->r2 == 0) {
        // 0x8001069C: nop
    
            goto L_800106A8;
    }
    // 0x8001069C: nop

    // 0x800106A0: jal         0x8000488C
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_18;
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
L_800106A8:
    // 0x800106A8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800106AC: nop

    // 0x800106B0: beq         $v0, $zero, L_800106C0
    if (ctx->r2 == 0) {
        // 0x800106B4: nop
    
            goto L_800106C0;
    }
    // 0x800106B4: nop

    // 0x800106B8: jal         0x8000488C
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_19;
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
L_800106C0:
    // 0x800106C0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800106C4: nop

    // 0x800106C8: beq         $v0, $zero, L_800106D8
    if (ctx->r2 == 0) {
        // 0x800106CC: nop
    
            goto L_800106D8;
    }
    // 0x800106CC: nop

    // 0x800106D0: jal         0x8000488C
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
L_800106D8:
    // 0x800106D8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800106DC: nop

    // 0x800106E0: beq         $v0, $zero, L_800106F0
    if (ctx->r2 == 0) {
        // 0x800106E4: nop
    
            goto L_800106F0;
    }
    // 0x800106E4: nop

    // 0x800106E8: jal         0x8000488C
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
L_800106F0:
    // 0x800106F0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800106F4: nop

    // 0x800106F8: beq         $a0, $zero, L_80010708
    if (ctx->r4 == 0) {
        // 0x800106FC: nop
    
            goto L_80010708;
    }
    // 0x800106FC: nop

    // 0x80010700: jal         0x800096F8
    // 0x80010704: nop

    audspat_point_stop(rdram, ctx);
        goto after_22;
    // 0x80010704: nop

    after_22:
L_80010708:
    // 0x80010708: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8001070C: nop

    // 0x80010710: beq         $a0, $zero, L_80010720
    if (ctx->r4 == 0) {
        // 0x80010714: nop
    
            goto L_80010720;
    }
    // 0x80010714: nop

    // 0x80010718: jal         0x800096F8
    // 0x8001071C: nop

    audspat_point_stop(rdram, ctx);
        goto after_23;
    // 0x8001071C: nop

    after_23:
L_80010720:
    // 0x80010720: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x80010724: nop

    // 0x80010728: beq         $a0, $zero, L_80010738
    if (ctx->r4 == 0) {
        // 0x8001072C: nop
    
            goto L_80010738;
    }
    // 0x8001072C: nop

    // 0x80010730: jal         0x8000488C
    // 0x80010734: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80010734: nop

    after_24:
L_80010738:
    // 0x80010738: jal         0x80006AC8
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    racer_sound_free(rdram, ctx);
        goto after_25;
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_25:
    // 0x80010740: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010744: addiu       $s5, $s5, -0x51A4
    ctx->r21 = ADD32(ctx->r21, -0X51A4);
    // 0x80010748: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8001074C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010750: blez        $t0, L_800107F0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010754: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_800107F0;
    }
    // 0x80010754: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80010758: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_8001075C:
    // 0x8001075C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010760: lw          $t1, -0x51A8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X51A8);
    // 0x80010764: nop

    // 0x80010768: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8001076C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80010770: nop

    // 0x80010774: lh          $t3, 0x6($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X6);
    // 0x80010778: nop

    // 0x8001077C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80010780: beq         $t4, $zero, L_800107B0
    if (ctx->r12 == 0) {
        // 0x80010784: nop
    
            goto L_800107B0;
    }
    // 0x80010784: nop

    // 0x80010788: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8001078C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010790: bne         $s6, $t5, L_800107B0
    if (ctx->r22 != ctx->r13) {
        // 0x80010794: nop
    
            goto L_800107B0;
    }
    // 0x80010794: nop

    // 0x80010798: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8001079C: lw          $t7, -0x51A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X51A8);
    // 0x800107A0: nop

    // 0x800107A4: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x800107A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800107AC: nop

L_800107B0:
    // 0x800107B0: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x800107B4: nop

    // 0x800107B8: beq         $s4, $v0, L_800107D0
    if (ctx->r20 == ctx->r2) {
        // 0x800107BC: nop
    
            goto L_800107D0;
    }
    // 0x800107BC: nop

    // 0x800107C0: beq         $s1, $v0, L_800107D0
    if (ctx->r17 == ctx->r2) {
        // 0x800107C4: nop
    
            goto L_800107D0;
    }
    // 0x800107C4: nop

    // 0x800107C8: bne         $s2, $v0, L_800107D8
    if (ctx->r18 != ctx->r2) {
        // 0x800107CC: nop
    
            goto L_800107D8;
    }
    // 0x800107CC: nop

L_800107D0:
    // 0x800107D0: jal         0x8000FFB8
    // 0x800107D4: nop

    free_object(rdram, ctx);
        goto after_26;
    // 0x800107D4: nop

    after_26:
L_800107D8:
    // 0x800107D8: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800107DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800107E0: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800107E4: bne         $at, $zero, L_8001075C
    if (ctx->r1 != 0) {
        // 0x800107E8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001075C;
    }
    // 0x800107E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800107EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800107F0:
    // 0x800107F0: lw          $v0, 0x50($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X50);
    // 0x800107F4: nop

    // 0x800107F8: beq         $v0, $zero, L_80010818
    if (ctx->r2 == 0) {
        // 0x800107FC: nop
    
            goto L_80010818;
    }
    // 0x800107FC: nop

    // 0x80010800: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80010804: nop

    // 0x80010808: beq         $a0, $zero, L_80010818
    if (ctx->r4 == 0) {
        // 0x8001080C: nop
    
            goto L_80010818;
    }
    // 0x8001080C: nop

    // 0x80010810: jal         0x8007B2BC
    // 0x80010814: nop

    tex_free(rdram, ctx);
        goto after_27;
    // 0x80010814: nop

    after_27:
L_80010818:
    // 0x80010818: lw          $v0, 0x58($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X58);
    // 0x8001081C: nop

    // 0x80010820: beq         $v0, $zero, L_80010840
    if (ctx->r2 == 0) {
        // 0x80010824: nop
    
            goto L_80010840;
    }
    // 0x80010824: nop

    // 0x80010828: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8001082C: nop

    // 0x80010830: beq         $a0, $zero, L_80010840
    if (ctx->r4 == 0) {
        // 0x80010834: nop
    
            goto L_80010840;
    }
    // 0x80010834: nop

    // 0x80010838: jal         0x8007B2BC
    // 0x8001083C: nop

    tex_free(rdram, ctx);
        goto after_28;
    // 0x8001083C: nop

    after_28:
L_80010840:
    // 0x80010840: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010844: nop

    // 0x80010848: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x8001084C: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x80010850: bne         $a0, $zero, L_800108A0
    if (ctx->r4 != 0) {
        // 0x80010854: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800108A0;
    }
    // 0x80010854: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80010858: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001085C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x8001085C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010860:
    // 0x80010860: lw          $t9, 0x68($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X68);
    // 0x80010864: nop

    // 0x80010868: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8001086C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80010870: nop

    // 0x80010874: beq         $v0, $zero, L_80010884
    if (ctx->r2 == 0) {
        // 0x80010878: nop
    
            goto L_80010884;
    }
    // 0x80010878: nop

    // 0x8001087C: jal         0x8005FF40
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_29;
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
L_80010884:
    // 0x80010884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010888: bne         $s3, $s2, L_80010860
    if (ctx->r19 != ctx->r18) {
        // 0x8001088C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010860;
    }
    // 0x8001088C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010890: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010894: b           L_80010918
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8001089C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800108A0:
    // 0x800108A0: bne         $a0, $at, L_800108E0
    if (ctx->r4 != ctx->r1) {
        // 0x800108A4: nop
    
            goto L_800108E0;
    }
    // 0x800108A4: nop

    // 0x800108A8: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108AC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108B0:
    // 0x800108B0: lw          $t1, 0x68($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X68);
    // 0x800108B4: nop

    // 0x800108B8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800108BC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800108C0: jal         0x8007B2BC
    // 0x800108C4: nop

    tex_free(rdram, ctx);
        goto after_30;
    // 0x800108C4: nop

    after_30:
    // 0x800108C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800108CC: bne         $s3, $s2, L_800108B0
    if (ctx->r19 != ctx->r18) {
        // 0x800108D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108B0;
    }
    // 0x800108D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800108D4: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x800108D8: b           L_80010918
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_800108E0:
    // 0x800108E0: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108E4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108E8:
    // 0x800108E8: lw          $t3, 0x68($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X68);
    // 0x800108EC: nop

    // 0x800108F0: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800108F4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800108F8: jal         0x8007CCB0
    // 0x800108FC: nop

    sprite_free(rdram, ctx);
        goto after_31;
    // 0x800108FC: nop

    after_31:
    // 0x80010900: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010904: bne         $s3, $s2, L_800108E8
    if (ctx->r19 != ctx->r18) {
        // 0x80010908: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108E8;
    }
    // 0x80010908: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001090C: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010910: nop

L_80010914:
    // 0x80010914: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_80010918:
    // 0x80010918: nop

    // 0x8001091C: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010920: nop
    
            goto L_80010958;
    }
    // 0x80010920: nop

    // 0x80010924: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010928: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80010958;
    }
    // 0x80010928: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8001092C:
    // 0x8001092C: lw          $t5, 0x6C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X6C);
    // 0x80010930: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x80010934: jal         0x800B2260
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    emitter_cleanup(rdram, ctx);
        goto after_32;
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    after_32:
    // 0x8001093C: lw          $t6, 0x40($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X40);
    // 0x80010940: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010944: lb          $t8, 0x57($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X57);
    // 0x80010948: nop

    // 0x8001094C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80010950: bne         $at, $zero, L_8001092C
    if (ctx->r1 != 0) {
        // 0x80010954: nop
    
            goto L_8001092C;
    }
    // 0x80010954: nop

L_80010958:
    // 0x80010958: lh          $a0, 0x2C($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X2C);
    // 0x8001095C: jal         0x8000C844
    // 0x80010960: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x80010960: nop

    after_33:
    // 0x80010964: jal         0x80071140
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_34;
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_34:
L_8001096C:
    // 0x8001096C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010974: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80010978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001097C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80010980: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80010984: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80010988: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001098C: jr          $ra
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void free_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_presentation_object_freed(uint8_t*, recomp_context*); dkr_presentation_object_freed(rdram, ctx);
    // 0x8000FFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FFBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FFC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000FFC4: lh          $a0, 0x4A($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4A);
    // 0x8000FFC8: nop

    // 0x8000FFCC: ori         $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 | 0X8000;
    // 0x8000FFD0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000FFD4: jal         0x800245B4
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_0:
    // 0x8000FFDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000FFE0: addiu       $v0, $v0, -0x5138
    ctx->r2 = ADD32(ctx->r2, -0X5138);
    // 0x8000FFE4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000FFE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000FFEC: lw          $t1, -0x513C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X513C);
    // 0x8000FFF0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000FFF8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000FFFC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x80010000: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80010004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010008: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001000C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80010010: jr          $ra
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void set_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017E78: sh          $a0, -0x5128($at)
    MEM_H(-0X5128, ctx->r1) = ctx->r4;
    // 0x80017E7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017E80: jr          $ra
    // 0x80017E84: sw          $zero, -0x5254($at)
    MEM_W(-0X5254, ctx->r1) = 0;
    return;
    // 0x80017E84: sw          $zero, -0x5254($at)
    MEM_W(-0X5254, ctx->r1) = 0;
;}
RECOMP_FUNC void alFxParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80063F98: bne         $a1, $at, L_80063FA4
    if (ctx->r5 != ctx->r1) {
        // 0x80063F9C: nop
    
            goto L_80063FA4;
    }
    // 0x80063F9C: nop

    // 0x80063FA0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_80063FA4:
    // 0x80063FA4: jr          $ra
    // 0x80063FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80063FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void get_loaded_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4318: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C431C: lw          $t7, -0x5820($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5820);
    // 0x800C4320: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C4324: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C4328: beq         $at, $zero, L_800C437C
    if (ctx->r1 == 0) {
        // 0x800C432C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800C437C;
    }
    // 0x800C432C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C4330: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4334: lw          $t9, -0x581C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X581C);
    // 0x800C4338: sll         $t8, $a0, 10
    ctx->r24 = S32(ctx->r4 << 10);
    // 0x800C433C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C4340: lbu         $t0, 0x28($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X28);
    // 0x800C4344: addiu       $a1, $t6, -0x20
    ctx->r5 = ADD32(ctx->r14, -0X20);
    // 0x800C4348: beq         $t0, $zero, L_800C437C
    if (ctx->r8 == 0) {
        // 0x800C434C: andi        $t1, $a1, 0xFF
        ctx->r9 = ctx->r5 & 0XFF;
            goto L_800C437C;
    }
    // 0x800C434C: andi        $t1, $a1, 0xFF
    ctx->r9 = ctx->r5 & 0XFF;
    // 0x800C4350: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800C4354: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800C4358: lbu         $a0, 0x100($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X100);
    // 0x800C435C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C4360: beq         $a0, $at, L_800C437C
    if (ctx->r4 == ctx->r1) {
        // 0x800C4364: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C437C;
    }
    // 0x800C4364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C4368: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800C436C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800C4370: lw          $v0, 0x80($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X80);
    // 0x800C4374: jr          $ra
    // 0x800C4378: nop

    return;
    // 0x800C4378: nop

L_800C437C:
    // 0x800C437C: jr          $ra
    // 0x800C4380: nop

    return;
    // 0x800C4380: nop

;}
