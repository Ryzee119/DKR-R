#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_credits_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AF48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009AF4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009AF50: jal         0x8006EA90
    // 0x8009AF54: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009AF54: nop

    after_0:
    // 0x8009AF58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009AF5C: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8009AF60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF64: sw          $zero, 0x6BC4($at)
    MEM_W(0X6BC4, ctx->r1) = 0;
    // 0x8009AF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF6C: sw          $zero, 0x6BCC($at)
    MEM_W(0X6BCC, ctx->r1) = 0;
    // 0x8009AF70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF74: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8009AF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF7C: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009AF80: sw          $t6, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r14;
    // 0x8009AF84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009AF88: sw          $zero, -0xBA0($at)
    MEM_W(-0XBA0, ctx->r1) = 0;
    // 0x8009AF8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF90: sw          $zero, 0x6BD0($at)
    MEM_W(0X6BD0, ctx->r1) = 0;
    // 0x8009AF94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF98: sw          $zero, 0x6BD8($at)
    MEM_W(0X6BD8, ctx->r1) = 0;
    // 0x8009AF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AFA0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009AFA4: sw          $zero, 0x6BE0($at)
    MEM_W(0X6BE0, ctx->r1) = 0;
    // 0x8009AFA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009AFAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AFB0: jal         0x80077B5C
    // 0x8009AFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_fillcolour(rdram, ctx);
        goto after_1;
    // 0x8009AFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8009AFB8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009AFBC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009AFC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009AFC4: bne         $t7, $zero, L_8009B00C
    if (ctx->r15 != 0) {
        // 0x8009AFC8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009B00C;
    }
    // 0x8009AFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AFCC: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x8009AFD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009AFD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009AFD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AFDC: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x8009AFE0: jal         0x80066940
    // 0x8009AFE4: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_2;
    // 0x8009AFE4: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x8009AFE8: addiu       $t9, $zero, 0x11C
    ctx->r25 = ADD32(0, 0X11C);
    // 0x8009AFEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009AFF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009AFF4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009AFF8: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009AFFC: jal         0x80066AA8
    // 0x8009B000: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009B000: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x8009B004: b           L_8009B03C
    // 0x8009B008: nop

        goto L_8009B03C;
    // 0x8009B008: nop

L_8009B00C:
    // 0x8009B00C: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x8009B010: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009B014: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8009B018: jal         0x80066940
    // 0x8009B01C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_4;
    // 0x8009B01C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
    // 0x8009B020: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x8009B024: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009B028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B02C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009B030: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009B034: jal         0x80066AA8
    // 0x8009B038: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_5;
    // 0x8009B038: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_5:
L_8009B03C:
    // 0x8009B03C: jal         0x80066610
    // 0x8009B040: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_6;
    // 0x8009B040: nop

    after_6:
    // 0x8009B044: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B048: jal         0x80066818
    // 0x8009B04C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x8009B04C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8009B050: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B054: jal         0x8009C674
    // 0x8009B058: addiu       $a0, $a0, 0x17D8
    ctx->r4 = ADD32(ctx->r4, 0X17D8);
    menu_assetgroup_load(rdram, ctx);
        goto after_8;
    // 0x8009B058: addiu       $a0, $a0, 0x17D8
    ctx->r4 = ADD32(ctx->r4, 0X17D8);
    after_8:
    // 0x8009B05C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B060: jal         0x8009C8A4
    // 0x8009B064: addiu       $a0, $a0, 0x17F0
    ctx->r4 = ADD32(ctx->r4, 0X17F0);
    menu_imagegroup_load(rdram, ctx);
        goto after_9;
    // 0x8009B064: addiu       $a0, $a0, 0x17F0
    ctx->r4 = ADD32(ctx->r4, 0X17F0);
    after_9:
    // 0x8009B068: jal         0x80094604
    // 0x8009B06C: nop

    menu_racer_portraits(rdram, ctx);
        goto after_10;
    // 0x8009B06C: nop

    after_10:
    // 0x8009B070: jal         0x800C4170
    // 0x8009B074: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_11;
    // 0x8009B074: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8009B078: jal         0x80000BE0
    // 0x8009B07C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x8009B07C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x8009B080: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009B084: lw          $t3, 0x1B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B4C);
    // 0x8009B088: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8009B08C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B090: beq         $t3, $zero, L_8009B0D4
    if (ctx->r11 == 0) {
        // 0x8009B094: sh          $t2, 0x18F8($at)
        MEM_H(0X18F8, ctx->r1) = ctx->r10;
            goto L_8009B0D4;
    }
    // 0x8009B094: sh          $t2, 0x18F8($at)
    MEM_H(0X18F8, ctx->r1) = ctx->r10;
    // 0x8009B098: jal         0x80000B34
    // 0x8009B09C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_13;
    // 0x8009B09C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8009B0A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B0A4: addiu       $v0, $v0, 0x1AE4
    ctx->r2 = ADD32(ctx->r2, 0X1AE4);
    // 0x8009B0A8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B0AC: addiu       $a2, $a2, 0x1938
    ctx->r6 = ADD32(ctx->r6, 0X1938);
    // 0x8009B0B0: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8009B0B4: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8009B0B8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009B0BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B0C0: sw          $t4, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r12;
    // 0x8009B0C4: sw          $t5, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r13;
    // 0x8009B0C8: sw          $t6, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r14;
    // 0x8009B0CC: b           L_8009B1BC
    // 0x8009B0D0: sw          $zero, 0x1B4C($at)
    MEM_W(0X1B4C, ctx->r1) = 0;
        goto L_8009B1BC;
    // 0x8009B0D0: sw          $zero, 0x1B4C($at)
    MEM_W(0X1B4C, ctx->r1) = 0;
L_8009B0D4:
    // 0x8009B0D4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009B0D8: nop

    // 0x8009B0DC: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x8009B0E0: nop

    // 0x8009B0E4: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8009B0E8: beq         $t9, $zero, L_8009B12C
    if (ctx->r25 == 0) {
        // 0x8009B0EC: nop
    
            goto L_8009B12C;
    }
    // 0x8009B0EC: nop

    // 0x8009B0F0: jal         0x80000B34
    // 0x8009B0F4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    music_play(rdram, ctx);
        goto after_14;
    // 0x8009B0F4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_14:
    // 0x8009B0F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B0FC: addiu       $v0, $v0, 0x1AE4
    ctx->r2 = ADD32(ctx->r2, 0X1AE4);
    // 0x8009B100: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8009B104: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B108: addiu       $a2, $a2, 0x1938
    ctx->r6 = ADD32(ctx->r6, 0X1938);
    // 0x8009B10C: addiu       $t1, $zero, 0x61F4
    ctx->r9 = ADD32(0, 0X61F4);
    // 0x8009B110: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B114: sw          $t0, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r8;
    // 0x8009B118: sh          $t1, 0x18F8($at)
    MEM_H(0X18F8, ctx->r1) = ctx->r9;
    // 0x8009B11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B120: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x8009B124: b           L_8009B14C
    // 0x8009B128: sw          $t2, 0x6BCC($at)
    MEM_W(0X6BCC, ctx->r1) = ctx->r10;
        goto L_8009B14C;
    // 0x8009B128: sw          $t2, 0x6BCC($at)
    MEM_W(0X6BCC, ctx->r1) = ctx->r10;
L_8009B12C:
    // 0x8009B12C: jal         0x80000B34
    // 0x8009B130: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    music_play(rdram, ctx);
        goto after_15;
    // 0x8009B130: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_15:
    // 0x8009B134: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B138: addiu       $v0, $v0, 0x1AE4
    ctx->r2 = ADD32(ctx->r2, 0X1AE4);
    // 0x8009B13C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8009B140: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B144: addiu       $a2, $a2, 0x1938
    ctx->r6 = ADD32(ctx->r6, 0X1938);
    // 0x8009B148: sw          $t3, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r11;
L_8009B14C:
    // 0x8009B14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B150: jal         0x8006F94C
    // 0x8009B154: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x8009B154: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_16:
    // 0x8009B158: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8009B15C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B160: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8009B164: lw          $v1, 0x1AF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1AF8);
    // 0x8009B168: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009B16C: addiu       $a2, $a2, 0x1938
    ctx->r6 = ADD32(ctx->r6, 0X1938);
    // 0x8009B170: beq         $v1, $zero, L_8009B188
    if (ctx->r3 == 0) {
        // 0x8009B174: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8009B188;
    }
    // 0x8009B174: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8009B178:
    // 0x8009B178: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8009B17C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8009B180: bne         $t5, $zero, L_8009B178
    if (ctx->r13 != 0) {
        // 0x8009B184: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8009B178;
    }
    // 0x8009B184: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8009B188:
    // 0x8009B188: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009B18C: lw          $v0, 0x6C30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C30);
    // 0x8009B190: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8009B194: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    // 0x8009B198: addu        $v1, $a1, $t7
    ctx->r3 = ADD32(ctx->r5, ctx->r15);
    // 0x8009B19C: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x8009B1A0: nop

    // 0x8009B1A4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009B1A8: sw          $t9, 0x154($a2)
    MEM_W(0X154, ctx->r6) = ctx->r25;
    // 0x8009B1AC: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x8009B1B0: nop

    // 0x8009B1B4: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8009B1B8: sw          $t1, 0x158($a2)
    MEM_W(0X158, ctx->r6) = ctx->r9;
L_8009B1BC:
    // 0x8009B1BC: jal         0x80000B18
    // 0x8009B1C0: nop

    music_change_off(rdram, ctx);
        goto after_17;
    // 0x8009B1C0: nop

    after_17:
    // 0x8009B1C4: jal         0x800C0170
    // 0x8009B1C8: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_18;
    // 0x8009B1C8: nop

    after_18:
    // 0x8009B1CC: jal         0x8006F564
    // 0x8009B1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_gIntDisFlag(rdram, ctx);
        goto after_19;
    // 0x8009B1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009B1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B1D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009B1DC: jr          $ra
    // 0x8009B1E0: nop

    return;
    // 0x8009B1E0: nop

;}
RECOMP_FUNC void fix32_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070780: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80070784: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80070788: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8007078C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070790: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070794: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80070798: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007079C: cvt.w.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800707A0: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800707A4: jr          $ra
    // 0x800707A8: nop

    return;
    // 0x800707A8: nop

;}
RECOMP_FUNC void update_camera_finish_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058D5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80058D60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058D68: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80058D6C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80058D70: lb          $t7, 0x1D0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X1D0);
    // 0x80058D74: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80058D78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80058D7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80058D80: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80058D84: jal         0x8001BDD4
    // 0x80058D88: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    spectate_nearest(rdram, ctx);
        goto after_0;
    // 0x80058D88: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x80058D8C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80058D90: bne         $v0, $zero, L_80058DB0
    if (ctx->r2 != 0) {
        // 0x80058D94: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80058DB0;
    }
    // 0x80058D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80058D98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058D9C: addiu       $s0, $s0, -0x2AF8
    ctx->r16 = ADD32(ctx->r16, -0X2AF8);
    // 0x80058DA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058DA4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80058DA8: b           L_80058F34
    // 0x80058DAC: sh          $t8, 0x36($t9)
    MEM_H(0X36, ctx->r25) = ctx->r24;
        goto L_80058F34;
    // 0x80058DAC: sh          $t8, 0x36($t9)
    MEM_H(0X36, ctx->r25) = ctx->r24;
L_80058DB0:
    // 0x80058DB0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80058DB4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80058DB8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058DBC: sb          $t0, 0x1D0($t1)
    MEM_B(0X1D0, ctx->r9) = ctx->r8;
    // 0x80058DC0: addiu       $s0, $s0, -0x2AF8
    ctx->r16 = ADD32(ctx->r16, -0X2AF8);
    extern void dkr_presentation_finish_camera_node(uint8_t*, recomp_context*); dkr_presentation_finish_camera_node(rdram, ctx);
    // 0x80058DC4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058DC8: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80058DCC: nop

    // 0x80058DD0: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x80058DD4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80058DD8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80058DDC: nop

    // 0x80058DE0: swc1        $f6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f6.u32l;
    // 0x80058DE4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80058DE8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80058DEC: nop

    // 0x80058DF0: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x80058DF4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80058DF8: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80058DFC: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80058E00: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80058E04: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058E08: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80058E0C: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80058E10: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80058E14: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80058E18: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80058E1C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80058E20: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80058E24: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80058E28: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80058E2C: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80058E30: jal         0x800C9AD0
    // 0x80058E34: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80058E34: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_1:
    // 0x80058E38: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80058E3C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80058E40: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80058E44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058E48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058E4C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80058E50: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80058E54: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80058E58: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80058E5C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80058E60: nop

    // 0x80058E64: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80058E68: nop

    // 0x80058E6C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058E70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058E74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058E78: nop

    // 0x80058E7C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80058E80: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80058E84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80058E88: jal         0x8007066C
    // 0x80058E8C: nop

    atan2s(rdram, ctx);
        goto after_2;
    // 0x80058E8C: nop

    after_2:
    // 0x80058E90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80058E94: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058E98: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80058E9C: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80058EA0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80058EA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058EA8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80058EAC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058EB4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058EB8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80058EBC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80058EC0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80058EC4: nop

    // 0x80058EC8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80058ECC: nop

    // 0x80058ED0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80058ED4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058ED8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058EDC: nop

    // 0x80058EE0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80058EE4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80058EE8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80058EEC: jal         0x8007066C
    // 0x80058EF0: nop

    atan2s(rdram, ctx);
        goto after_3;
    // 0x80058EF0: nop

    after_3:
    // 0x80058EF4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058EF8: nop

    // 0x80058EFC: sh          $v0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r2;
    // 0x80058F00: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80058F04: nop

    // 0x80058F08: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x80058F0C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80058F10: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80058F14: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80058F18: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x80058F1C: lwc1        $f14, 0x3C($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x80058F20: jal         0x80029F18
    // 0x80058F24: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x80058F24: nop

    after_4:
    // 0x80058F28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80058F2C: nop

    // 0x80058F30: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_80058F34:
    // 0x80058F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058F38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058F3C: jr          $ra
    // 0x80058F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80058F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void rsp_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A2D0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8007A2D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007A2D8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8007A2DC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8007A2E0: lui         $at, 0xBC00
    ctx->r1 = S32(0XBC00 << 16);
    // 0x8007A2E4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8007A2E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007A2EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8007A2F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007A2F4: addu        $t2, $a2, $at
    ctx->r10 = ADD32(ctx->r6, ctx->r1);
    // 0x8007A2F8: ori         $t1, $t0, 0x6
    ctx->r9 = ctx->r8 | 0X6;
    // 0x8007A2FC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007A300: jr          $ra
    // 0x8007A304: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x8007A304: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D49F8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D49FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4A00: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D4A04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D4A08: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4A10: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D4A14: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D4A18: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4A1C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4A20:
    // 0x800D4A20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4A24: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D4A28:
    // 0x800D4A28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D4A2C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800D4A30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4A34: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800D4A38: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D4A3C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800D4A40: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4A44: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800D4A48: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D4A4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D4A50: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800D4A54: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D4A58: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800D4A5C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800D4A60: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800D4A64: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x800D4A68: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D4A6C: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D4A70: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x800D4A74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4A78: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4A7C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800D4A80: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4A84: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4A88: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800D4A8C: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x800D4A90: bne         $a0, $t3, L_800D4A28
    if (ctx->r4 != ctx->r11) {
        // 0x800D4A94: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_800D4A28;
    }
    // 0x800D4A94: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800D4A98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4A9C: bne         $a2, $t4, L_800D4A20
    if (ctx->r6 != ctx->r12) {
        // 0x800D4AA0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800D4A20;
    }
    // 0x800D4AA0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800D4AA4: jr          $ra
    // 0x800D4AA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D4AA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void rsp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800780DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800780E0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800780E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800780E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800780EC: addiu       $t8, $t8, -0x1B20
    ctx->r24 = ADD32(ctx->r24, -0X1B20);
    // 0x800780F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800780F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800780F8: jr          $ra
    // 0x800780FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800780FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void emitter_cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2268: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B226C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B2270: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x800B2274: beq         $t7, $zero, L_800B22F0
    if (ctx->r15 == 0) {
        // 0x800B2278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B22F0;
    }
    // 0x800B2278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B227C: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800B2280: nop

    // 0x800B2284: beq         $a0, $zero, L_800B22F0
    if (ctx->r4 == 0) {
        // 0x800B2288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B22F0;
    }
    // 0x800B2288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B228C: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x800B2290: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2294: blez        $t8, L_800B22D8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B2298: nop
    
            goto L_800B22D8;
    }
    // 0x800B2298: nop

    // 0x800B229C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B22A0:
    // 0x800B22A0: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800B22A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B22A8: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x800B22AC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800B22B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B22B4: sh          $zero, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = 0;
    // 0x800B22B8: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x800B22BC: lbu         $t1, 0x6($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X6);
    // 0x800B22C0: nop

    // 0x800B22C4: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B22C8: bne         $at, $zero, L_800B22A0
    if (ctx->r1 != 0) {
        // 0x800B22CC: nop
    
            goto L_800B22A0;
    }
    // 0x800B22CC: nop

    // 0x800B22D0: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x800B22D4: nop

L_800B22D8:
    // 0x800B22D8: jal         0x80071140
    // 0x800B22DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800B22DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B22E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B22E4: nop

    // 0x800B22E8: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800B22EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B22F0:
    // 0x800B22F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B22F4: jr          $ra
    // 0x800B22F8: nop

    return;
    // 0x800B22F8: nop

;}
RECOMP_FUNC void set_triangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF0A4: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF0A8: nop

    // 0x800AF0AC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF0B0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF0B4: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF0B8: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF0BC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800AF0C0: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800AF0C4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AF0C8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF0CC: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF0D0: sra         $t2, $t8, 1
    ctx->r10 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AF0D4: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x800AF0D8: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800AF0DC: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800AF0E0: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x800AF0E4: sh          $t8, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r24;
    // 0x800AF0E8: jr          $ra
    // 0x800AF0EC: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
    return;
    // 0x800AF0EC: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void sound_play_spatial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001EB0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001EB8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001EBC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001EC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001EC8: bne         $a1, $zero, L_80001ED8
    if (ctx->r5 != 0) {
        // 0x80001ECC: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80001ED8;
    }
    // 0x80001ECC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80001ED0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80001ED4: addiu       $a1, $a1, 0x5F84
    ctx->r5 = ADD32(ctx->r5, 0X5F84);
L_80001ED8:
    // 0x80001ED8: jal         0x80001D04
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80001EDC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001EE0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80001EE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80001EE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80001EEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80001EF0: beq         $a0, $zero, L_80001F08
    if (ctx->r4 == 0) {
        // 0x80001EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001F08;
    }
    // 0x80001EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001EF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80001EFC: jal         0x80009B7C
    // 0x80001F00: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_1;
    // 0x80001F00: nop

    after_1:
    // 0x80001F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F08:
    // 0x80001F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001F0C: jr          $ra
    // 0x80001F10: nop

    return;
    // 0x80001F10: nop

;}
RECOMP_FUNC void cam_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069ACC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069AD0: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x80069AD4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069AD8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069ADC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069AE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069AE8: addiu       $t8, $t8, 0xAC0
    ctx->r24 = ADD32(ctx->r24, 0XAC0);
    // 0x80069AEC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80069AF0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069AF4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069AF8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80069AFC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80069B00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069B04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80069B08: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069B0C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069B10: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069B14: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80069B18: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80069B1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069B24: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069B28: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80069B2C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80069B30: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80069B34: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069B38: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069B3C: jal         0x80029F18
    // 0x80069B40: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80069B40: nop

    after_0:
    // 0x80069B44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80069B48: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x80069B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069B50: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80069B54: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80069B58: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80069B5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069B60: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80069B64: sh          $v0, 0xAF4($at)
    MEM_H(0XAF4, ctx->r1) = ctx->r2;
    // 0x80069B68: jr          $ra
    // 0x80069B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void check_fadeout_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C018C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0190: lhu         $v0, 0x31B0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X31B0);
    // 0x800C0194: nop

    // 0x800C0198: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C019C: bne         $t6, $zero, L_800C01D0
    if (ctx->r14 != 0) {
        // 0x800C01A0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800C01D0;
    }
    // 0x800C01A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C01A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C01A8: lhu         $v0, 0x31B4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X31B4);
    // 0x800C01AC: nop

    // 0x800C01B0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C01B4: beq         $t7, $zero, L_800C01D0
    if (ctx->r15 == 0) {
        // 0x800C01B8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C01D0;
    }
    // 0x800C01B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800C01BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C01C0: lb          $v0, 0x31BC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X31BC);
    // 0x800C01C4: nop

    // 0x800C01C8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C01CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C01D0:
    // 0x800C01D0: jr          $ra
    // 0x800C01D4: nop

    return;
    // 0x800C01D4: nop

;}
RECOMP_FUNC void music_dynamic_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001078: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000107C: lbu         $t7, -0x39A4($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X39A4);
    // 0x80001080: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001084: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001088: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000108C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001090: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001094: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001098: beq         $t7, $zero, L_800010AC
    if (ctx->r15 == 0) {
        // 0x8000109C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800010AC;
    }
    // 0x8000109C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800010A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800010A4: b           L_800010FC
    // 0x800010A8: sw          $t6, 0x5F7C($at)
    MEM_W(0X5F7C, ctx->r1) = ctx->r14;
        goto L_800010FC;
    // 0x800010A8: sw          $t6, 0x5F7C($at)
    MEM_W(0X5F7C, ctx->r1) = ctx->r14;
L_800010AC:
    // 0x800010AC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800010B0: lw          $t8, -0x39D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39D0);
    // 0x800010B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800010B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800010BC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x800010C0: sh          $a0, 0x30($t8)
    MEM_H(0X30, ctx->r24) = ctx->r4;
    // 0x800010C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010C8:
    // 0x800010C8: sllv        $t0, $t9, $s0
    ctx->r8 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x800010CC: and         $t1, $s1, $t0
    ctx->r9 = ctx->r17 & ctx->r8;
    // 0x800010D0: beq         $t1, $zero, L_800010E8
    if (ctx->r9 == 0) {
        // 0x800010D4: nop
    
            goto L_800010E8;
    }
    // 0x800010D4: nop

    // 0x800010D8: jal         0x80001170
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_0;
    // 0x800010DC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800010E0: b           L_800010F4
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800010F4;
    // 0x800010E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010E8:
    // 0x800010E8: jal         0x80001114
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x800010EC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x800010F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800010F4:
    // 0x800010F4: bne         $s0, $s2, L_800010C8
    if (ctx->r16 != ctx->r18) {
        // 0x800010F8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800010C8;
    }
    // 0x800010F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800010FC:
    // 0x800010FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001104: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000110C: jr          $ra
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sndp_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000463C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004644: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80004648: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8000464C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80004650: jal         0x80004668
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80004654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80004658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000465C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004660: jr          $ra
    // 0x80004664: nop

    return;
    // 0x80004664: nop

;}
RECOMP_FUNC void func_80042D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042D20: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80042D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042D28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042D2C: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80042D30: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80042D34: lb          $t6, 0x1CA($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1CA);
    // 0x80042D38: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80042D3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80042D40: jal         0x8001E29C
    // 0x80042D44: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80042D44: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    after_0:
    // 0x80042D48: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80042D4C: jal         0x8001E29C
    // 0x80042D50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80042D50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80042D54: jal         0x8006BDB0
    // 0x80042D58: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_2;
    // 0x80042D58: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_2:
    // 0x80042D5C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80042D60: jal         0x8001BAAC
    // 0x80042D64: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    get_racer_objects_by_position(rdram, ctx);
        goto after_3;
    // 0x80042D64: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x80042D68: jal         0x8006C18C
    // 0x80042D6C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    aitable_get(rdram, ctx);
        goto after_4;
    // 0x80042D6C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_4:
    // 0x80042D70: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80042D74: lh          $v1, 0x1C6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1C6);
    // 0x80042D78: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042D7C: blez        $v1, L_80042D98
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80042D80: nop
    
            goto L_80042D98;
    }
    // 0x80042D80: nop

    // 0x80042D84: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80042D88: nop

    // 0x80042D8C: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x80042D90: b           L_80042D9C
    // 0x80042D94: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_80042D9C;
    // 0x80042D94: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_80042D98:
    // 0x80042D98: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_80042D9C:
    // 0x80042D9C: jal         0x8001AE44
    // 0x80042DA0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    race_finish_timer(rdram, ctx);
        goto after_5;
    // 0x80042DA0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_5:
    // 0x80042DA4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042DA8: beq         $v0, $zero, L_80042DC8
    if (ctx->r2 == 0) {
        // 0x80042DAC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80042DC8;
    }
    // 0x80042DAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80042DB0: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x80042DB4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80042DB8: nop

    // 0x80042DBC: ori         $t6, $t9, 0x8000
    ctx->r14 = ctx->r25 | 0X8000;
    // 0x80042DC0: b           L_80043EBC
    // 0x80042DC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80043EBC;
    // 0x80042DC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80042DC8:
    // 0x80042DC8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80042DCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80042DD0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80042DD4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80042DD8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80042DDC: blez        $t7, L_80042E70
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80042DE0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80042E70;
    }
    // 0x80042DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80042DE4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042DE8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80042DEC:
    // 0x80042DEC: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80042DF0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80042DF4: nop

    // 0x80042DF8: lw          $t1, 0x64($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X64);
    // 0x80042DFC: nop

    // 0x80042E00: bne         $t1, $s0, L_80042E10
    if (ctx->r9 != ctx->r16) {
        // 0x80042E04: nop
    
            goto L_80042E10;
    }
    // 0x80042E04: nop

    // 0x80042E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042E0C: sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
L_80042E10:
    // 0x80042E10: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80042E14: nop

    // 0x80042E18: bne         $ra, $t7, L_80042E40
    if (ctx->r31 != ctx->r15) {
        // 0x80042E1C: nop
    
            goto L_80042E40;
    }
    // 0x80042E1C: nop

    // 0x80042E20: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80042E24: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80042E28: beq         $v0, $zero, L_80042E54
    if (ctx->r2 == 0) {
        // 0x80042E2C: sra         $t0, $t8, 16
        ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80042E54;
    }
    // 0x80042E2C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80042E30: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80042E34: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80042E38: b           L_80042E54
    // 0x80042E3C: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
        goto L_80042E54;
    // 0x80042E3C: sra         $t5, $t6, 16
    ctx->r13 = S32(SIGNED(ctx->r14) >> 16);
L_80042E40:
    // 0x80042E40: bne         $t4, $ra, L_80042E54
    if (ctx->r12 != ctx->r31) {
        // 0x80042E44: nop
    
            goto L_80042E54;
    }
    // 0x80042E44: nop

    // 0x80042E48: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80042E4C: sra         $t8, $t4, 16
    ctx->r24 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80042E50: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
L_80042E54:
    // 0x80042E54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80042E58: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80042E5C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80042E60: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80042E64: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80042E68: bne         $at, $zero, L_80042DEC
    if (ctx->r1 != 0) {
        // 0x80042E6C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80042DEC;
    }
    // 0x80042E6C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80042E70:
    // 0x80042E70: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042E74: bne         $t4, $ra, L_80042E80
    if (ctx->r12 != ctx->r31) {
        // 0x80042E78: nop
    
            goto L_80042E80;
    }
    // 0x80042E78: nop

    // 0x80042E7C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80042E80:
    // 0x80042E80: beq         $t0, $zero, L_80043EC0
    if (ctx->r8 == 0) {
        // 0x80042E84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043EC0;
    }
    // 0x80042E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042E88: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80042E8C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042E90: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042E94: jal         0x80023568
    // 0x80042E98: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    func_80023568(rdram, ctx);
        goto after_6;
    // 0x80042E98: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_6:
    // 0x80042E9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80042EA0: lw          $t8, -0x2AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC0);
    // 0x80042EA4: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042EA8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042EAC: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042EB0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042EB4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80042EB8: bne         $t8, $zero, L_800430DC
    if (ctx->r24 != 0) {
        // 0x80042EBC: sh          $v0, 0x70($sp)
        MEM_H(0X70, ctx->r29) = ctx->r2;
            goto L_800430DC;
    }
    // 0x80042EBC: sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // 0x80042EC0: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80042EC4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80042EC8: beq         $t9, $at, L_800430E0
    if (ctx->r25 == ctx->r1) {
        // 0x80042ECC: lh          $a3, 0x72($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X72);
            goto L_800430E0;
    }
    // 0x80042ECC: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80042ED0: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80042ED4: lbu         $a0, 0x20B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20B);
    // 0x80042ED8: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x80042EDC: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80042EE0: beq         $at, $zero, L_80042FF0
    if (ctx->r1 == 0) {
        // 0x80042EE4: sll         $t6, $v1, 16
        ctx->r14 = S32(ctx->r3 << 16);
            goto L_80042FF0;
    }
    // 0x80042EE4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80042EE8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80042EEC: bltz        $t7, L_80042FF4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80042EF0: lh          $t6, 0x72($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X72);
            goto L_80042FF4;
    }
    // 0x80042EF0: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x80042EF4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80042EF8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80042EFC: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80042F00: beq         $at, $zero, L_80042FF0
    if (ctx->r1 == 0) {
        // 0x80042F04: addu        $t3, $t2, $t9
        ctx->r11 = ADD32(ctx->r10, ctx->r25);
            goto L_80042FF0;
    }
    // 0x80042F04: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80042F08: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80042F0C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80042F10: lw          $t1, 0x64($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X64);
    // 0x80042F14: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80042F18: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80042F1C: nop

    // 0x80042F20: beq         $ra, $t7, L_80042FF4
    if (ctx->r31 == ctx->r15) {
        // 0x80042F24: lh          $t6, 0x72($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X72);
            goto L_80042FF4;
    }
    // 0x80042F24: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x80042F28: bne         $t9, $zero, L_80042F70
    if (ctx->r25 != 0) {
        // 0x80042F2C: addiu       $a1, $zero, 0x1C2
        ctx->r5 = ADD32(0, 0X1C2);
            goto L_80042F70;
    }
    // 0x80042F2C: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80042F30: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x80042F34: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80042F38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80042F3C: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80042F40: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042F44: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80042F48: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042F4C: jal         0x800570B8
    // 0x80042F50: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    play_random_character_voice(rdram, ctx);
        goto after_7;
    // 0x80042F50: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_7:
    // 0x80042F54: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042F58: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042F5C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80042F60: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042F64: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042F68: b           L_80042FB8
    // 0x80042F6C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
        goto L_80042FB8;
    // 0x80042F6C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
L_80042F70:
    // 0x80042F70: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x80042F74: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80042F78: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80042F7C: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80042F80: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80042F84: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80042F88: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042F8C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80042F90: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042F94: jal         0x8005CA84
    // 0x80042F98: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    racer_boss_sound_spatial(rdram, ctx);
        goto after_8;
    // 0x80042F98: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    after_8:
    // 0x80042F9C: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042FA0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042FA4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80042FA8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042FAC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042FB0: nop

    // 0x80042FB4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
L_80042FB8:
    // 0x80042FB8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80042FBC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80042FC0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80042FC4: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80042FC8: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80042FCC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80042FD0: jal         0x800570B8
    // 0x80042FD4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    play_random_character_voice(rdram, ctx);
        goto after_9;
    // 0x80042FD4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x80042FD8: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80042FDC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80042FE0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80042FE4: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80042FE8: lbu         $a0, 0x20B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20B);
    // 0x80042FEC: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
L_80042FF0:
    // 0x80042FF0: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
L_80042FF4:
    // 0x80042FF4: nop

    // 0x80042FF8: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80042FFC: beq         $at, $zero, L_800430DC
    if (ctx->r1 == 0) {
        // 0x80043000: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_800430DC;
    }
    // 0x80043000: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80043004: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80043008: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004300C: bltz        $t8, L_800430E0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80043010: lh          $a3, 0x72($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X72);
            goto L_800430E0;
    }
    // 0x80043010: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
    // 0x80043014: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80043018: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8004301C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80043020: beq         $at, $zero, L_800430DC
    if (ctx->r1 == 0) {
        // 0x80043024: addu        $t8, $t2, $t7
        ctx->r24 = ADD32(ctx->r10, ctx->r15);
            goto L_800430DC;
    }
    // 0x80043024: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x80043028: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8004302C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80043030: lw          $t1, 0x64($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X64);
    // 0x80043034: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80043038: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x8004303C: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80043040: beq         $ra, $t7, L_800430DC
    if (ctx->r31 == ctx->r15) {
        // 0x80043044: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_800430DC;
    }
    // 0x80043044: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80043048: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8004304C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80043050: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043054: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043058: jal         0x800570B8
    // 0x8004305C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    play_random_character_voice(rdram, ctx);
        goto after_10;
    // 0x8004305C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x80043060: lh          $t7, 0x70($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X70);
    // 0x80043064: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043068: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004306C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043070: bne         $t7, $zero, L_800430A8
    if (ctx->r15 != 0) {
        // 0x80043074: addiu       $a1, $zero, 0x162
        ctx->r5 = ADD32(0, 0X162);
            goto L_800430A8;
    }
    // 0x80043074: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80043078: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x8004307C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80043080: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80043084: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043088: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004308C: jal         0x800570B8
    // 0x80043090: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    play_random_character_voice(rdram, ctx);
        goto after_11;
    // 0x80043090: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_11:
    // 0x80043094: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043098: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004309C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800430A0: b           L_800430E0
    // 0x800430A4: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
        goto L_800430E0;
    // 0x800430A4: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
L_800430A8:
    // 0x800430A8: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x800430AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800430B0: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800430B4: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800430B8: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x800430BC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800430C0: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800430C4: jal         0x8005CA84
    // 0x800430C8: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    racer_boss_sound_spatial(rdram, ctx);
        goto after_12;
    // 0x800430C8: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    after_12:
    // 0x800430CC: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x800430D0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800430D4: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800430D8: nop

L_800430DC:
    // 0x800430DC: lh          $a3, 0x72($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X72);
L_800430E0:
    // 0x800430E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800430E4: sb          $a3, 0x20B($s0)
    MEM_B(0X20B, ctx->r16) = ctx->r7;
    // 0x800430E8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800430EC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800430F0: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800430F4: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x800430F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800430FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80043100: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80043104: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80043108: jal         0x8001B7A8
    // 0x8004310C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_13;
    // 0x8004310C: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80043110: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043114: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043118: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004311C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043120: beq         $v0, $zero, L_80043130
    if (ctx->r2 == 0) {
        // 0x80043124: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043130;
    }
    // 0x80043124: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043128: lw          $t1, 0x64($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X64);
    // 0x8004312C: nop

L_80043130:
    // 0x80043130: or          $a1, $ra, $zero
    ctx->r5 = ctx->r31 | 0;
    // 0x80043134: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80043138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004313C: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x80043140: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x80043144: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043148: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004314C: jal         0x8001B7A8
    // 0x80043150: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_14;
    // 0x80043150: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_14:
    // 0x80043154: lh          $t0, 0x76($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X76);
    // 0x80043158: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004315C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043160: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043164: beq         $v0, $zero, L_80043178
    if (ctx->r2 == 0) {
        // 0x80043168: slti        $at, $t0, 0x7
        ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
            goto L_80043178;
    }
    // 0x80043168: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x8004316C: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x80043170: nop

    // 0x80043174: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_80043178:
    // 0x80043178: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8004317C: beq         $t1, $zero, L_80043190
    if (ctx->r9 == 0) {
        // 0x80043180: sb          $t8, 0x3E($sp)
        MEM_B(0X3E, ctx->r29) = ctx->r24;
            goto L_80043190;
    }
    // 0x80043180: sb          $t8, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r24;
    // 0x80043184: lb          $t9, 0x3($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X3);
    // 0x80043188: nop

    // 0x8004318C: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
L_80043190:
    // 0x80043190: beq         $at, $zero, L_8004323C
    if (ctx->r1 == 0) {
        // 0x80043194: nop
    
            goto L_8004323C;
    }
    // 0x80043194: nop

    // 0x80043198: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8004319C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800431A0: jal         0x8009962C
    // 0x800431A4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_trophy_race_world_id(rdram, ctx);
        goto after_15;
    // 0x800431A4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_15:
    // 0x800431A8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800431AC: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800431B0: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800431B4: bne         $v0, $zero, L_8004323C
    if (ctx->r2 != 0) {
        // 0x800431B8: nop
    
            goto L_8004323C;
    }
    // 0x800431B8: nop

    // 0x800431BC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800431C0: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800431C4: jal         0x80023568
    // 0x800431C8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    func_80023568(rdram, ctx);
        goto after_16;
    // 0x800431C8: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_16:
    // 0x800431CC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800431D0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800431D4: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800431D8: bne         $v0, $zero, L_8004323C
    if (ctx->r2 != 0) {
        // 0x800431DC: nop
    
            goto L_8004323C;
    }
    // 0x800431DC: nop

    // 0x800431E0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800431E4: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800431E8: jal         0x8002341C
    // 0x800431EC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    is_taj_challenge(rdram, ctx);
        goto after_17;
    // 0x800431EC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_17:
    // 0x800431F0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800431F4: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800431F8: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800431FC: bne         $v0, $zero, L_8004323C
    if (ctx->r2 != 0) {
        // 0x80043200: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004323C;
    }
    // 0x80043200: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043204: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x80043208: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004320C: bne         $t7, $at, L_80043298
    if (ctx->r15 != ctx->r1) {
        // 0x80043210: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80043298;
    }
    // 0x80043210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80043214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80043218: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8004321C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043220: jal         0x8006F94C
    // 0x80043224: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    rand_range(rdram, ctx);
        goto after_18;
    // 0x80043224: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_18:
    // 0x80043228: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004322C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043230: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043234: b           L_80043298
    // 0x80043238: sb          $v0, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r2;
        goto L_80043298;
    // 0x80043238: sb          $v0, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r2;
L_8004323C:
    // 0x8004323C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043240: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043244: jal         0x8009962C
    // 0x80043248: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_trophy_race_world_id(rdram, ctx);
        goto after_19;
    // 0x80043248: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_19:
    // 0x8004324C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043250: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043254: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043258: beq         $v0, $zero, L_80043280
    if (ctx->r2 == 0) {
        // 0x8004325C: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80043280;
    }
    // 0x8004325C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80043260: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80043264: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x80043268: nop

    // 0x8004326C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80043270: lbu         $t7, 0x16($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X16);
    // 0x80043274: b           L_80043298
    // 0x80043278: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
        goto L_80043298;
    // 0x80043278: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
    // 0x8004327C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_80043280:
    // 0x80043280: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x80043284: nop

    // 0x80043288: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8004328C: lbu         $t7, 0xC($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC);
    // 0x80043290: nop

    // 0x80043294: sb          $t7, 0x1CC($s0)
    MEM_B(0X1CC, ctx->r16) = ctx->r15;
L_80043298:
    // 0x80043298: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004329C: lwc1        $f0, -0x2ABC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x800432A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800432A4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800432A8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800432AC: nop

    // 0x800432B0: bc1t        L_800432D8
    if (c1cs) {
        // 0x800432B4: nop
    
            goto L_800432D8;
    }
    // 0x800432B4: nop

    // 0x800432B8: lh          $t6, 0x1AE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1AE);
    // 0x800432BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800432C0: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800432C4: lb          $t8, -0x3260($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X3260);
    // 0x800432C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800432CC: sb          $t8, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r24;
    // 0x800432D0: lwc1        $f0, -0x2ABC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x800432D4: nop

L_800432D8:
    // 0x800432D8: lb          $v1, 0x1CC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1CC);
    // 0x800432DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800432E0: addiu       $t6, $v1, -0x2
    ctx->r14 = ADD32(ctx->r3, -0X2);
    // 0x800432E4: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x800432E8: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800432EC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800432F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800432F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800432F8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800432FC: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x80043300: nop

    // 0x80043304: bc1f        L_8004331C
    if (!c1cs) {
        // 0x80043308: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004331C;
    }
    // 0x80043308: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004330C: lw          $t7, -0x2AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AD8);
    // 0x80043310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043314: ori         $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 | 0X8000;
    // 0x80043318: sw          $t6, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r14;
L_8004331C:
    // 0x8004331C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043320: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043324: jal         0x8001E29C
    // 0x80043328: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    get_misc_asset(rdram, ctx);
        goto after_20;
    // 0x80043328: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_20:
    // 0x8004332C: lb          $t0, 0x174($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X174);
    // 0x80043330: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043334: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043338: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x8004333C: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80043340: beq         $at, $zero, L_8004336C
    if (ctx->r1 == 0) {
        // 0x80043344: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_8004336C;
    }
    // 0x80043344: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043348: lb          $t8, 0x172($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X172);
    // 0x8004334C: nop

    // 0x80043350: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80043354: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80043358: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8004335C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x80043360: lb          $t2, 0x0($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X0);
    // 0x80043364: b           L_80043378
    // 0x80043368: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_80043378;
    // 0x80043368: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_8004336C:
    // 0x8004336C: lb          $t2, 0x172($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X172);
    // 0x80043370: nop

    // 0x80043374: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80043378:
    // 0x80043378: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8004337C: lb          $v1, 0xC($t8)
    ctx->r3 = MEM_B(ctx->r24, 0XC);
    // 0x80043380: lb          $t9, 0xD($t8)
    ctx->r25 = MEM_B(ctx->r24, 0XD);
    // 0x80043384: subu        $t3, $v0, $t5
    ctx->r11 = SUB32(ctx->r2, ctx->r13);
    // 0x80043388: subu        $t7, $t9, $v1
    ctx->r15 = SUB32(ctx->r25, ctx->r3);
    // 0x8004338C: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043390: mflo        $t6
    ctx->r14 = lo;
    // 0x80043394: nop

    // 0x80043398: nop

    // 0x8004339C: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800433A0: bne         $v0, $zero, L_800433AC
    if (ctx->r2 != 0) {
        // 0x800433A4: nop
    
            goto L_800433AC;
    }
    // 0x800433A4: nop

    // 0x800433A8: break       7
    do_break(2147759016);
L_800433AC:
    // 0x800433AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800433B0: bne         $v0, $at, L_800433C4
    if (ctx->r2 != ctx->r1) {
        // 0x800433B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800433C4;
    }
    // 0x800433B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800433B8: bne         $t6, $at, L_800433C4
    if (ctx->r14 != ctx->r1) {
        // 0x800433BC: nop
    
            goto L_800433C4;
    }
    // 0x800433BC: nop

    // 0x800433C0: break       6
    do_break(2147759040);
L_800433C4:
    // 0x800433C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800433C8: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800433CC: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x800433D0: lb          $t6, 0x11($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X11);
    // 0x800433D4: lb          $a0, 0x10($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X10);
    // 0x800433D8: nop

    // 0x800433DC: subu        $t9, $t6, $a0
    ctx->r25 = SUB32(ctx->r14, ctx->r4);
    // 0x800433E0: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800433E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800433E8: nop

    // 0x800433EC: nop

    // 0x800433F0: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800433F4: bne         $v0, $zero, L_80043400
    if (ctx->r2 != 0) {
        // 0x800433F8: nop
    
            goto L_80043400;
    }
    // 0x800433F8: nop

    // 0x800433FC: break       7
    do_break(2147759100);
L_80043400:
    // 0x80043400: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80043404: bne         $v0, $at, L_80043418
    if (ctx->r2 != ctx->r1) {
        // 0x80043408: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80043418;
    }
    // 0x80043408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004340C: bne         $t6, $at, L_80043418
    if (ctx->r14 != ctx->r1) {
        // 0x80043410: nop
    
            goto L_80043418;
    }
    // 0x80043410: nop

    // 0x80043414: break       6
    do_break(2147759124);
L_80043418:
    // 0x80043418: mflo        $t9
    ctx->r25 = lo;
    // 0x8004341C: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x80043420: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    // 0x80043424: lb          $t9, 0x9($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X9);
    // 0x80043428: lb          $a1, 0x8($t8)
    ctx->r5 = MEM_B(ctx->r24, 0X8);
    // 0x8004342C: nop

    // 0x80043430: subu        $t6, $t9, $a1
    ctx->r14 = SUB32(ctx->r25, ctx->r5);
    // 0x80043434: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80043438: mflo        $t9
    ctx->r25 = lo;
    // 0x8004343C: nop

    // 0x80043440: nop

    // 0x80043444: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x80043448: bne         $v0, $zero, L_80043454
    if (ctx->r2 != 0) {
        // 0x8004344C: nop
    
            goto L_80043454;
    }
    // 0x8004344C: nop

    // 0x80043450: break       7
    do_break(2147759184);
L_80043454:
    // 0x80043454: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80043458: bne         $v0, $at, L_8004346C
    if (ctx->r2 != ctx->r1) {
        // 0x8004345C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004346C;
    }
    // 0x8004345C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80043460: bne         $t9, $at, L_8004346C
    if (ctx->r25 != ctx->r1) {
        // 0x80043464: nop
    
            goto L_8004346C;
    }
    // 0x80043464: nop

    // 0x80043468: break       6
    do_break(2147759208);
L_8004346C:
    // 0x8004346C: mflo        $t6
    ctx->r14 = lo;
    // 0x80043470: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x80043474: sh          $t9, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r25;
    // 0x80043478: lb          $t6, 0x15($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X15);
    // 0x8004347C: lb          $a2, 0x14($t8)
    ctx->r6 = MEM_B(ctx->r24, 0X14);
    // 0x80043480: nop

    // 0x80043484: subu        $t9, $t6, $a2
    ctx->r25 = SUB32(ctx->r14, ctx->r6);
    // 0x80043488: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004348C: mflo        $t8
    ctx->r24 = lo;
    // 0x80043490: nop

    // 0x80043494: nop

    // 0x80043498: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x8004349C: bne         $v0, $zero, L_800434A8
    if (ctx->r2 != 0) {
        // 0x800434A0: nop
    
            goto L_800434A8;
    }
    // 0x800434A0: nop

    // 0x800434A4: break       7
    do_break(2147759268);
L_800434A8:
    // 0x800434A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800434AC: bne         $v0, $at, L_800434C0
    if (ctx->r2 != ctx->r1) {
        // 0x800434B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800434C0;
    }
    // 0x800434B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800434B4: bne         $t8, $at, L_800434C0
    if (ctx->r24 != ctx->r1) {
        // 0x800434B8: nop
    
            goto L_800434C0;
    }
    // 0x800434B8: nop

    // 0x800434BC: break       6
    do_break(2147759292);
L_800434C0:
    // 0x800434C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800434C4: addu        $t9, $t6, $a2
    ctx->r25 = ADD32(ctx->r14, ctx->r6);
    // 0x800434C8: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
    // 0x800434CC: lbu         $a3, 0x209($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X209);
    // 0x800434D0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800434D4: andi        $t8, $a3, 0x1
    ctx->r24 = ctx->r7 & 0X1;
    // 0x800434D8: beq         $t8, $zero, L_80043798
    if (ctx->r24 == 0) {
        // 0x800434DC: nop
    
            goto L_80043798;
    }
    // 0x800434DC: nop

    // 0x800434E0: lb          $t6, 0x201($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X201);
    // 0x800434E4: nop

    // 0x800434E8: bne         $t6, $zero, L_80043580
    if (ctx->r14 != 0) {
        // 0x800434EC: nop
    
            goto L_80043580;
    }
    // 0x800434EC: nop

    // 0x800434F0: bne         $t0, $zero, L_8004353C
    if (ctx->r8 != 0) {
        // 0x800434F4: sll         $a0, $t7, 16
        ctx->r4 = S32(ctx->r15 << 16);
            goto L_8004353C;
    }
    // 0x800434F4: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x800434F8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800434FC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80043500: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043504: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x80043508: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004350C: jal         0x80044450
    // 0x80043510: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_21;
    // 0x80043510: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_21:
    // 0x80043514: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043518: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x8004351C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043520: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043524: beq         $v0, $zero, L_8004353C
    if (ctx->r2 == 0) {
        // 0x80043528: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_8004353C;
    }
    // 0x80043528: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004352C: lb          $t8, 0x174($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X174);
    // 0x80043530: nop

    // 0x80043534: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80043538: sb          $t6, 0x174($s0)
    MEM_B(0X174, ctx->r16) = ctx->r14;
L_8004353C:
    // 0x8004353C: bne         $t4, $zero, L_80043580
    if (ctx->r12 != 0) {
        // 0x80043540: slti        $at, $t5, 0x3
        ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
            goto L_80043580;
    }
    // 0x80043540: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80043544: beq         $at, $zero, L_80043580
    if (ctx->r1 == 0) {
        // 0x80043548: nop
    
            goto L_80043580;
    }
    // 0x80043548: nop

    // 0x8004354C: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x80043550: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043554: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x80043558: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x8004355C: jal         0x80044450
    // 0x80043560: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_22;
    // 0x80043560: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_22:
    // 0x80043564: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043568: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x8004356C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043570: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043574: beq         $v0, $zero, L_80043580
    if (ctx->r2 == 0) {
        // 0x80043578: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043580;
    }
    // 0x80043578: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004357C: sb          $zero, 0x172($s0)
    MEM_B(0X172, ctx->r16) = 0;
L_80043580:
    // 0x80043580: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x80043584: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80043588: bne         $t7, $zero, L_800435E4
    if (ctx->r15 != 0) {
        // 0x8004358C: addu        $t9, $t9, $t2
        ctx->r25 = ADD32(ctx->r25, ctx->r10);
            goto L_800435E4;
    }
    // 0x8004358C: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80043590: lb          $t9, -0x3270($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3270);
    // 0x80043594: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80043598: bne         $t9, $at, L_800435E4
    if (ctx->r25 != ctx->r1) {
        // 0x8004359C: nop
    
            goto L_800435E4;
    }
    // 0x8004359C: nop

    // 0x800435A0: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x800435A4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800435A8: sb          $t2, 0x4B($sp)
    MEM_B(0X4B, ctx->r29) = ctx->r10;
    // 0x800435AC: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800435B0: jal         0x80044450
    // 0x800435B4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_23;
    // 0x800435B4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_23:
    // 0x800435B8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800435BC: lb          $t2, 0x4B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X4B);
    // 0x800435C0: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800435C4: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800435C8: beq         $v0, $zero, L_800435E4
    if (ctx->r2 == 0) {
        // 0x800435CC: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800435E4;
    }
    // 0x800435CC: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x800435D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800435D4: lw          $t8, -0x2AD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD0);
    // 0x800435D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800435DC: ori         $t6, $t8, 0x2000
    ctx->r14 = ctx->r24 | 0X2000;
    // 0x800435E0: sw          $t6, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = ctx->r14;
L_800435E4:
    // 0x800435E4: lb          $t7, 0x173($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X173);
    // 0x800435E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800435EC: beq         $t7, $zero, L_80043784
    if (ctx->r15 == 0) {
        // 0x800435F0: addiu       $t9, $t9, -0x3270
        ctx->r25 = ADD32(ctx->r25, -0X3270);
            goto L_80043784;
    }
    // 0x800435F0: addiu       $t9, $t9, -0x3270
    ctx->r25 = ADD32(ctx->r25, -0X3270);
    // 0x800435F4: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x800435F8: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x800435FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043600: bne         $t8, $at, L_800436C0
    if (ctx->r24 != ctx->r1) {
        // 0x80043604: nop
    
            goto L_800436C0;
    }
    // 0x80043604: nop

    // 0x80043608: beq         $t1, $zero, L_8004365C
    if (ctx->r9 == 0) {
        // 0x8004360C: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_8004365C;
    }
    // 0x8004360C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80043610: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80043614: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80043618: bne         $ra, $t6, L_8004365C
    if (ctx->r31 != ctx->r14) {
        // 0x8004361C: lh          $a0, 0x36($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X36);
            goto L_8004365C;
    }
    // 0x8004361C: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80043620: beq         $at, $zero, L_800436C0
    if (ctx->r1 == 0) {
        // 0x80043624: nop
    
            goto L_800436C0;
    }
    // 0x80043624: nop

    // 0x80043628: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8004362C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80043630: nop

    // 0x80043634: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80043638: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x8004363C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80043640: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80043644: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80043648: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004364C: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x80043650: b           L_800436C0
    // 0x80043654: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
        goto L_800436C0;
    // 0x80043654: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
    // 0x80043658: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
L_8004365C:
    // 0x8004365C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80043660: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043664: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043668: jal         0x80044450
    // 0x8004366C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_24;
    // 0x8004366C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_24:
    // 0x80043670: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80043674: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043678: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x8004367C: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043680: beq         $v0, $zero, L_800436C0
    if (ctx->r2 == 0) {
        // 0x80043684: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800436C0;
    }
    // 0x80043684: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043688: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8004368C: beq         $at, $zero, L_800436C0
    if (ctx->r1 == 0) {
        // 0x80043690: nop
    
            goto L_800436C0;
    }
    // 0x80043690: nop

    // 0x80043694: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x80043698: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8004369C: nop

    // 0x800436A0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800436A4: lb          $t9, 0x0($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X0);
    // 0x800436A8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800436AC: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800436B0: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x800436B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800436B8: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
    // 0x800436BC: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_800436C0:
    // 0x800436C0: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x800436C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800436C8: bne         $t7, $at, L_80043784
    if (ctx->r15 != ctx->r1) {
        // 0x800436CC: nop
    
            goto L_80043784;
    }
    // 0x800436CC: nop

    // 0x800436D0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800436D4: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x800436D8: beq         $v1, $zero, L_80043728
    if (ctx->r3 == 0) {
        // 0x800436DC: nop
    
            goto L_80043728;
    }
    // 0x800436DC: nop

    // 0x800436E0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800436E4: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800436E8: bne         $ra, $t9, L_80043728
    if (ctx->r31 != ctx->r25) {
        // 0x800436EC: nop
    
            goto L_80043728;
    }
    // 0x800436EC: nop

    // 0x800436F0: beq         $at, $zero, L_80043784
    if (ctx->r1 == 0) {
        // 0x800436F4: nop
    
            goto L_80043784;
    }
    // 0x800436F4: nop

    // 0x800436F8: lb          $t8, 0x3E($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3E);
    // 0x800436FC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80043700: nop

    // 0x80043704: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80043708: lb          $t9, 0x0($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X0);
    // 0x8004370C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80043710: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x80043714: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80043718: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004371C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
    // 0x80043720: b           L_80043784
    // 0x80043724: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
        goto L_80043784;
    // 0x80043724: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_80043728:
    // 0x80043728: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8004372C: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x80043730: jal         0x80044450
    // 0x80043734: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_25;
    // 0x80043734: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_25:
    // 0x80043738: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8004373C: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80043740: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80043744: beq         $v0, $zero, L_80043784
    if (ctx->r2 == 0) {
        // 0x80043748: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_80043784;
    }
    // 0x80043748: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004374C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80043750: beq         $at, $zero, L_80043784
    if (ctx->r1 == 0) {
        // 0x80043754: nop
    
            goto L_80043784;
    }
    // 0x80043754: nop

    // 0x80043758: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8004375C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80043760: nop

    // 0x80043764: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80043768: lb          $t6, 0x0($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X0);
    // 0x8004376C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80043770: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80043774: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80043778: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004377C: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x80043780: sb          $t9, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r25;
L_80043784:
    // 0x80043784: lbu         $t8, 0x209($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X209);
    // 0x80043788: nop

    // 0x8004378C: andi        $t6, $t8, 0xFFFE
    ctx->r14 = ctx->r24 & 0XFFFE;
    // 0x80043790: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
    // 0x80043794: andi        $a3, $t6, 0xFF
    ctx->r7 = ctx->r14 & 0XFF;
L_80043798:
    // 0x80043798: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004379C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800437A0: beq         $t7, $zero, L_80043828
    if (ctx->r15 == 0) {
        // 0x800437A4: andi        $t9, $a3, 0x2
        ctx->r25 = ctx->r7 & 0X2;
            goto L_80043828;
    }
    // 0x800437A4: andi        $t9, $a3, 0x2
    ctx->r25 = ctx->r7 & 0X2;
    // 0x800437A8: bne         $t9, $zero, L_80043804
    if (ctx->r25 != 0) {
        // 0x800437AC: andi        $t8, $a3, 0x4
        ctx->r24 = ctx->r7 & 0X4;
            goto L_80043804;
    }
    // 0x800437AC: andi        $t8, $a3, 0x4
    ctx->r24 = ctx->r7 & 0X4;
    // 0x800437B0: lh          $a0, 0x3A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3A);
    // 0x800437B4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800437B8: sh          $t4, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r12;
    // 0x800437BC: jal         0x80044450
    // 0x800437C0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    roll_percent_chance(rdram, ctx);
        goto after_26;
    // 0x800437C0: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    after_26:
    // 0x800437C4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800437C8: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x800437CC: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x800437D0: beq         $v0, $zero, L_800437E8
    if (ctx->r2 == 0) {
        // 0x800437D4: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_800437E8;
    }
    // 0x800437D4: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x800437D8: lbu         $t8, 0x209($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X209);
    // 0x800437DC: nop

    // 0x800437E0: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x800437E4: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
L_800437E8:
    // 0x800437E8: lbu         $t7, 0x209($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X209);
    // 0x800437EC: nop

    // 0x800437F0: ori         $t9, $t7, 0x2
    ctx->r25 = ctx->r15 | 0X2;
    // 0x800437F4: sb          $t9, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r25;
    // 0x800437F8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800437FC: andi        $a3, $t9, 0xFF
    ctx->r7 = ctx->r25 & 0XFF;
    // 0x80043800: andi        $t8, $a3, 0x4
    ctx->r24 = ctx->r7 & 0X4;
L_80043804:
    // 0x80043804: beq         $t8, $zero, L_80043858
    if (ctx->r24 == 0) {
        // 0x80043808: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80043858;
    }
    // 0x80043808: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004380C: lw          $t6, -0x2AD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AD8);
    // 0x80043810: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80043814: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80043818: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8004381C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043820: b           L_80043858
    // 0x80043824: sw          $t7, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r15;
        goto L_80043858;
    // 0x80043824: sw          $t7, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r15;
L_80043828:
    // 0x80043828: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8004382C: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80043830: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80043834: lui         $at, 0xC028
    ctx->r1 = S32(0XC028 << 16);
    // 0x80043838: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004383C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043840: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80043844: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80043848: sb          $t9, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r25;
    // 0x8004384C: bc1f        L_80043858
    if (!c1cs) {
        // 0x80043850: andi        $t6, $t9, 0xFFFB
        ctx->r14 = ctx->r25 & 0XFFFB;
            goto L_80043858;
    }
    // 0x80043850: andi        $t6, $t9, 0xFFFB
    ctx->r14 = ctx->r25 & 0XFFFB;
    // 0x80043854: sb          $t6, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r14;
L_80043858:
    // 0x80043858: lbu         $t7, 0x209($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X209);
    // 0x8004385C: nop

    // 0x80043860: andi        $t9, $t7, 0x4
    ctx->r25 = ctx->r15 & 0X4;
    // 0x80043864: beq         $t9, $zero, L_80043884
    if (ctx->r25 == 0) {
        // 0x80043868: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80043884;
    }
    // 0x80043868: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004386C: lw          $t8, -0x2AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD8);
    // 0x80043870: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80043874: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80043878: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8004387C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043880: sw          $t6, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = ctx->r14;
L_80043884:
    // 0x80043884: lh          $t7, 0x1C6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1C6);
    // 0x80043888: nop

    // 0x8004388C: bne         $t7, $zero, L_8004399C
    if (ctx->r15 != 0) {
        // 0x80043890: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_8004399C;
    }
    // 0x80043890: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80043894: lbu         $v0, 0x1C9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C9);
    // 0x80043898: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004389C: beq         $v0, $at, L_800438B0
    if (ctx->r2 == ctx->r1) {
        // 0x800438A0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800438B0;
    }
    // 0x800438A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800438A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800438A8: bne         $v0, $at, L_800438C0
    if (ctx->r2 != ctx->r1) {
        // 0x800438AC: nop
    
            goto L_800438C0;
    }
    // 0x800438AC: nop

L_800438B0:
    // 0x800438B0: lw          $t9, -0x2AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AD0);
    // 0x800438B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800438B8: ori         $t8, $t9, 0x2000
    ctx->r24 = ctx->r25 | 0X2000;
    // 0x800438BC: sw          $t8, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = ctx->r24;
L_800438C0:
    // 0x800438C0: beq         $v1, $zero, L_80043938
    if (ctx->r3 == 0) {
        // 0x800438C4: sb          $zero, 0x1C9($s0)
        MEM_B(0X1C9, ctx->r16) = 0;
            goto L_80043938;
    }
    // 0x800438C4: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x800438C8: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800438CC: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800438D0: beq         $ra, $t6, L_80043938
    if (ctx->r31 == ctx->r14) {
        // 0x800438D4: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80043938;
    }
    // 0x800438D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800438D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800438DC: nop

    // 0x800438E0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800438E4: nop

    // 0x800438E8: bc1f        L_80043938
    if (!c1cs) {
        // 0x800438EC: nop
    
            goto L_80043938;
    }
    // 0x800438EC: nop

    // 0x800438F0: beq         $t5, $zero, L_80043938
    if (ctx->r13 == 0) {
        // 0x800438F4: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_80043938;
    }
    // 0x800438F4: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800438F8: beq         $at, $zero, L_80043938
    if (ctx->r1 == 0) {
        // 0x800438FC: nop
    
            goto L_80043938;
    }
    // 0x800438FC: nop

    // 0x80043900: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x80043904: lb          $t8, 0x3F($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3F);
    // 0x80043908: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8004390C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80043910: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80043914: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80043918: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8004391C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80043920: lb          $t8, 0x0($t9)
    ctx->r24 = MEM_B(ctx->r25, 0X0);
    // 0x80043924: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80043928: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8004392C: beq         $at, $zero, L_80043938
    if (ctx->r1 == 0) {
        // 0x80043930: nop
    
            goto L_80043938;
    }
    // 0x80043930: nop

    // 0x80043934: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
L_80043938:
    // 0x80043938: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004393C: lwc1        $f4, -0x2ABC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x80043940: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80043944: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80043948: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x8004394C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80043950: bc1f        L_80043990
    if (!c1cs) {
        // 0x80043954: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_80043990;
    }
    // 0x80043954: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80043958: lb          $t7, -0x3258($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3258);
    // 0x8004395C: nop

    // 0x80043960: sb          $t7, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r15;
    // 0x80043964: lh          $a0, 0x3C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X3C);
    // 0x80043968: jal         0x80044450
    // 0x8004396C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    roll_percent_chance(rdram, ctx);
        goto after_27;
    // 0x8004396C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_27:
    // 0x80043970: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043974: beq         $v0, $zero, L_8004398C
    if (ctx->r2 == 0) {
        // 0x80043978: addiu       $ra, $zero, -0x1
        ctx->r31 = ADD32(0, -0X1);
            goto L_8004398C;
    }
    // 0x80043978: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x8004397C: lb          $t9, 0x1CA($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043980: nop

    // 0x80043984: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80043988: sb          $t8, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r24;
L_8004398C:
    // 0x8004398C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_80043990:
    // 0x80043990: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80043994: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
    // 0x80043998: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_8004399C:
    // 0x8004399C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800439A0: bne         $t7, $at, L_800439E0
    if (ctx->r15 != ctx->r1) {
        // 0x800439A4: nop
    
            goto L_800439E0;
    }
    // 0x800439A4: nop

    // 0x800439A8: beq         $v1, $zero, L_800439E0
    if (ctx->r3 == 0) {
        // 0x800439AC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800439E0;
    }
    // 0x800439AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800439B0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800439B4: lwc1        $f11, 0x62A8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X62A8);
    // 0x800439B8: lwc1        $f10, 0x62AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X62AC);
    // 0x800439BC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800439C0: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x800439C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800439C8: bc1f        L_800439E0
    if (!c1cs) {
        // 0x800439CC: nop
    
            goto L_800439E0;
    }
    // 0x800439CC: nop

    // 0x800439D0: lbu         $t9, 0x209($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X209);
    // 0x800439D4: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
    // 0x800439D8: andi        $t8, $t9, 0xFFFB
    ctx->r24 = ctx->r25 & 0XFFFB;
    // 0x800439DC: sb          $t8, 0x209($s0)
    MEM_B(0X209, ctx->r16) = ctx->r24;
L_800439E0:
    // 0x800439E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800439E4: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x800439E8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800439EC: bne         $t7, $zero, L_80043B30
    if (ctx->r15 != 0) {
        // 0x800439F0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043B30;
    }
    // 0x800439F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800439F4: lwc1        $f14, 0x4($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800439F8: lwc1        $f17, 0x62B0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X62B0);
    // 0x800439FC: lwc1        $f16, 0x62B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62B4);
    // 0x80043A00: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80043A04: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80043A08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A0C: lwc1        $f19, 0x62B8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X62B8);
    // 0x80043A10: lwc1        $f18, 0x62BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X62BC);
    // 0x80043A14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A18: lwc1        $f11, 0x62C0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X62C0);
    // 0x80043A1C: lwc1        $f10, 0x62C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X62C4);
    // 0x80043A20: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x80043A24: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80043A28: div.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80043A2C: jal         0x800C9AD0
    // 0x80043A30: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    sqrtf_recomp(rdram, ctx);
        goto after_28;
    // 0x80043A30: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_28:
    // 0x80043A34: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80043A38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A3C: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80043A40: lwc1        $f5, 0x62C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X62C8);
    // 0x80043A44: lwc1        $f4, 0x62CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X62CC);
    // 0x80043A48: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x80043A4C: mul.d       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80043A50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A54: lwc1        $f7, 0x62D0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X62D0);
    // 0x80043A58: lwc1        $f6, 0x62D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62D4);
    // 0x80043A5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043A60: lwc1        $f9, 0x62D8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X62D8);
    // 0x80043A64: lwc1        $f8, 0x62DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X62DC);
    // 0x80043A68: add.d       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f18.d + ctx->f6.d;
    // 0x80043A6C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x80043A70: div.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x80043A74: jal         0x800C9AD0
    // 0x80043A78: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    sqrtf_recomp(rdram, ctx);
        goto after_29;
    // 0x80043A78: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    after_29:
    // 0x80043A7C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80043A80: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80043A84: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80043A88: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80043A8C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80043A90: lb          $v0, 0x1CA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043A94: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80043A98: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80043A9C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043AA0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80043AA4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80043AA8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80043AAC: addiu       $ra, $zero, -0x1
    ctx->r31 = ADD32(0, -0X1);
    // 0x80043AB0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80043AB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80043AB8: add.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80043ABC: bne         $at, $zero, L_80043AEC
    if (ctx->r1 != 0) {
        // 0x80043AC0: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80043AEC;
    }
    // 0x80043AC0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80043AC4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80043AC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043ACC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80043AD0: lwc1        $f11, 0x62E0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X62E0);
    // 0x80043AD4: lwc1        $f10, 0x62E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X62E4);
    // 0x80043AD8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043ADC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80043AE0: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80043AE4: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x80043AE8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80043AEC:
    // 0x80043AEC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80043AF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043AF4: lwc1        $f11, 0x62E8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X62E8);
    // 0x80043AF8: lwc1        $f10, 0x62EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X62EC);
    // 0x80043AFC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043B00: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80043B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B08: lwc1        $f17, 0x62F0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X62F0);
    // 0x80043B0C: lwc1        $f16, 0x62F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X62F4);
    // 0x80043B10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B14: lwc1        $f7, 0x62F8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X62F8);
    // 0x80043B18: lwc1        $f6, 0x62FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X62FC);
    // 0x80043B1C: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x80043B20: nop

    // 0x80043B24: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80043B28: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80043B2C: swc1        $f2, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f2.u32l;
L_80043B30:
    // 0x80043B30: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x80043B34: beq         $t1, $zero, L_80043B70
    if (ctx->r9 == 0) {
        // 0x80043B38: nop
    
            goto L_80043B70;
    }
    // 0x80043B38: nop

    // 0x80043B3C: lb          $t8, 0x1CA($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043B40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80043B44: bne         $t8, $at, L_80043B70
    if (ctx->r24 != ctx->r1) {
        // 0x80043B48: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043B70;
    }
    // 0x80043B48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043B4C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043B50: lwc1        $f11, 0x6300($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6300);
    // 0x80043B54: lwc1        $f10, 0x6304($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6304);
    // 0x80043B58: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80043B5C: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80043B60: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80043B64: bc1f        L_80043B70
    if (!c1cs) {
        // 0x80043B68: nop
    
            goto L_80043B70;
    }
    // 0x80043B68: nop

    // 0x80043B6C: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
L_80043B70:
    // 0x80043B70: lbu         $v0, 0x1C9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C9);
    // 0x80043B74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80043B78: beq         $v0, $zero, L_80043B98
    if (ctx->r2 == 0) {
        // 0x80043B7C: nop
    
            goto L_80043B98;
    }
    // 0x80043B7C: nop

    // 0x80043B80: beq         $v0, $at, L_80043C10
    if (ctx->r2 == ctx->r1) {
        // 0x80043B84: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80043C10;
    }
    // 0x80043B84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80043B88: beq         $v0, $at, L_80043C24
    if (ctx->r2 == ctx->r1) {
        // 0x80043B8C: nop
    
            goto L_80043C24;
    }
    // 0x80043B8C: nop

    // 0x80043B90: b           L_80043C38
    // 0x80043B94: nop

        goto L_80043C38;
    // 0x80043B94: nop

L_80043B98:
    // 0x80043B98: beq         $t1, $zero, L_80043C38
    if (ctx->r9 == 0) {
        // 0x80043B9C: nop
    
            goto L_80043C38;
    }
    // 0x80043B9C: nop

    // 0x80043BA0: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80043BA4: nop

    // 0x80043BA8: bne         $ra, $t7, L_80043C38
    if (ctx->r31 != ctx->r15) {
        // 0x80043BAC: nop
    
            goto L_80043C38;
    }
    // 0x80043BAC: nop

    // 0x80043BB0: lbu         $t9, 0x1C9($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X1C9);
    // 0x80043BB4: nop

    // 0x80043BB8: bne         $t9, $zero, L_80043C38
    if (ctx->r25 != 0) {
        // 0x80043BBC: nop
    
            goto L_80043C38;
    }
    // 0x80043BBC: nop

    // 0x80043BC0: lb          $v0, 0x1CA($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043BC4: lb          $t8, 0x1CA($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1CA);
    // 0x80043BC8: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043BCC: bne         $v0, $t8, L_80043C38
    if (ctx->r2 != ctx->r24) {
        // 0x80043BD0: lui         $at, 0x4059
        ctx->r1 = S32(0X4059 << 16);
            goto L_80043C38;
    }
    // 0x80043BD0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80043BD4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80043BD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80043BDC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80043BE0: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80043BE4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80043BE8: bc1f        L_80043C38
    if (!c1cs) {
        // 0x80043BEC: nop
    
            goto L_80043C38;
    }
    // 0x80043BEC: nop

    // 0x80043BF0: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
    // 0x80043BF4: lb          $t7, 0x1CA($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1CA);
    // 0x80043BF8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80043BFC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80043C00: bne         $at, $zero, L_80043C38
    if (ctx->r1 != 0) {
        // 0x80043C04: nop
    
            goto L_80043C38;
    }
    // 0x80043C04: nop

    // 0x80043C08: b           L_80043C38
    // 0x80043C0C: sb          $t9, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r25;
        goto L_80043C38;
    // 0x80043C0C: sb          $t9, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r25;
L_80043C10:
    // 0x80043C10: beq         $t1, $zero, L_80043C38
    if (ctx->r9 == 0) {
        // 0x80043C14: nop
    
            goto L_80043C38;
    }
    // 0x80043C14: nop

    // 0x80043C18: lh          $t8, 0x1BA($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X1BA);
    // 0x80043C1C: b           L_80043C38
    // 0x80043C20: sh          $t8, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r24;
        goto L_80043C38;
    // 0x80043C20: sh          $t8, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r24;
L_80043C24:
    // 0x80043C24: beq         $v1, $zero, L_80043C38
    if (ctx->r3 == 0) {
        // 0x80043C28: nop
    
            goto L_80043C38;
    }
    // 0x80043C28: nop

    // 0x80043C2C: lh          $t6, 0x1BA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BA);
    // 0x80043C30: nop

    // 0x80043C34: sh          $t6, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r14;
L_80043C38:
    // 0x80043C38: jal         0x8002341C
    // 0x80043C3C: nop

    is_taj_challenge(rdram, ctx);
        goto after_30;
    // 0x80043C3C: nop

    after_30:
    // 0x80043C40: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80043C44: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80043C48: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80043C4C: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80043C50: bne         $t8, $zero, L_80043C68
    if (ctx->r24 != 0) {
        // 0x80043C54: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80043C68;
    }
    // 0x80043C54: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80043C58: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x80043C5C: nop

    // 0x80043C60: beq         $t6, $zero, L_80043CBC
    if (ctx->r14 == 0) {
        // 0x80043C64: lh          $t6, 0x70($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X70);
            goto L_80043CBC;
    }
    // 0x80043C64: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
L_80043C68:
    // 0x80043C68: sb          $zero, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = 0;
    // 0x80043C6C: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
    // 0x80043C70: lh          $t7, 0x70($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X70);
    // 0x80043C74: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80043C78: beq         $t7, $zero, L_80043C94
    if (ctx->r15 == 0) {
        // 0x80043C7C: nop
    
            goto L_80043C94;
    }
    // 0x80043C7C: nop

    // 0x80043C80: jal         0x8001E29C
    // 0x80043C84: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    get_misc_asset(rdram, ctx);
        goto after_31;
    // 0x80043C84: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_31:
    // 0x80043C88: lh          $v1, 0x70($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X70);
    // 0x80043C8C: b           L_80043CA8
    // 0x80043C90: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
        goto L_80043CA8;
    // 0x80043C90: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80043C94:
    // 0x80043C94: jal         0x8001E29C
    // 0x80043C98: sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_32;
    // 0x80043C98: sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    after_32:
    // 0x80043C9C: lh          $v1, 0x7A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X7A);
    // 0x80043CA0: nop

    // 0x80043CA4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80043CA8:
    // 0x80043CA8: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x80043CAC: lwc1        $f18, -0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, -0X4);
    // 0x80043CB0: nop

    // 0x80043CB4: swc1        $f18, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f18.u32l;
    // 0x80043CB8: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
L_80043CBC:
    // 0x80043CBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043CC0: beq         $t6, $zero, L_80043E48
    if (ctx->r14 == 0) {
        // 0x80043CC4: nop
    
            goto L_80043E48;
    }
    // 0x80043CC4: nop

    // 0x80043CC8: lw          $t7, -0x2AC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC0);
    // 0x80043CCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80043CD0: beq         $t7, $zero, L_80043CEC
    if (ctx->r15 == 0) {
        // 0x80043CD4: addiu       $v1, $v1, -0x2A48
        ctx->r3 = ADD32(ctx->r3, -0X2A48);
            goto L_80043CEC;
    }
    // 0x80043CD4: addiu       $v1, $v1, -0x2A48
    ctx->r3 = ADD32(ctx->r3, -0X2A48);
    // 0x80043CD8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80043CDC: addiu       $v1, $v1, -0x2A48
    ctx->r3 = ADD32(ctx->r3, -0X2A48);
    // 0x80043CE0: addiu       $t9, $zero, 0x384
    ctx->r25 = ADD32(0, 0X384);
    // 0x80043CE4: b           L_80043DE8
    // 0x80043CE8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
        goto L_80043DE8;
    // 0x80043CE8: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_80043CEC:
    // 0x80043CEC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80043CF0: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80043CF4: nop

    // 0x80043CF8: subu        $t7, $t8, $t6
    ctx->r15 = SUB32(ctx->r24, ctx->r14);
    // 0x80043CFC: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80043D00: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80043D04: nop

    // 0x80043D08: bgez        $v0, L_80043D64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80043D0C: slti        $at, $v0, 0x2D1
        ctx->r1 = SIGNED(ctx->r2) < 0X2D1 ? 1 : 0;
            goto L_80043D64;
    }
    // 0x80043D0C: slti        $at, $v0, 0x2D1
    ctx->r1 = SIGNED(ctx->r2) < 0X2D1 ? 1 : 0;
    // 0x80043D10: lh          $t9, 0x72($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X72);
    // 0x80043D14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043D18: bne         $t9, $at, L_80043DE8
    if (ctx->r25 != ctx->r1) {
        // 0x80043D1C: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_80043DE8;
    }
    // 0x80043D1C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80043D20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043D24: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80043D28: lwc1        $f11, 0x6308($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6308);
    // 0x80043D2C: lwc1        $f10, 0x630C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X630C);
    // 0x80043D30: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80043D34: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80043D38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80043D3C: bc1f        L_80043DE8
    if (!c1cs) {
        // 0x80043D40: nop
    
            goto L_80043DE8;
    }
    // 0x80043D40: nop

    // 0x80043D44: lwc1        $f6, 0x124($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80043D48: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80043D4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043D50: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80043D54: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80043D58: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80043D5C: b           L_80043DE8
    // 0x80043D60: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
        goto L_80043DE8;
    // 0x80043D60: swc1        $f10, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f10.u32l;
L_80043D64:
    // 0x80043D64: lwc1        $f0, 0x124($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80043D68: bne         $at, $zero, L_80043D8C
    if (ctx->r1 != 0) {
        // 0x80043D6C: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_80043D8C;
    }
    // 0x80043D6C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80043D70: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80043D74: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043D78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043D7C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80043D80: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80043D84: b           L_80043DD4
    // 0x80043D88: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
        goto L_80043DD4;
    // 0x80043D88: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_80043D8C:
    // 0x80043D8C: lh          $t8, 0x72($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X72);
    // 0x80043D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043D94: beq         $t8, $at, L_80043DC0
    if (ctx->r24 == ctx->r1) {
        // 0x80043D98: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_80043DC0;
    }
    // 0x80043D98: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80043D9C: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80043DA0: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80043DA4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80043DA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80043DAC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80043DB0: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80043DB4: nop

    // 0x80043DB8: bc1f        L_80043DD4
    if (!c1cs) {
        // 0x80043DBC: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_80043DD4;
    }
    // 0x80043DBC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_80043DC0:
    // 0x80043DC0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80043DC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043DC8: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80043DCC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80043DD0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_80043DD4:
    // 0x80043DD4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80043DD8: nop

    // 0x80043DDC: bc1f        L_80043DE8
    if (!c1cs) {
        // 0x80043DE0: nop
    
            goto L_80043DE8;
    }
    // 0x80043DE0: nop

    // 0x80043DE4: swc1        $f14, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f14.u32l;
L_80043DE8:
    // 0x80043DE8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80043DEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80043DF0: beq         $t6, $zero, L_80043E48
    if (ctx->r14 == 0) {
        // 0x80043DF4: addiu       $v0, $v0, -0x2AD8
        ctx->r2 = ADD32(ctx->r2, -0X2AD8);
            goto L_80043E48;
    }
    // 0x80043DF4: addiu       $v0, $v0, -0x2AD8
    ctx->r2 = ADD32(ctx->r2, -0X2AD8);
    // 0x80043DF8: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80043DFC: sb          $zero, 0x213($s0)
    MEM_B(0X213, ctx->r16) = 0;
    // 0x80043E00: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80043E04: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80043E08: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80043E0C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80043E10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80043E14: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x80043E18: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80043E1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043E20: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80043E24: lwc1        $f19, 0x6310($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6310);
    // 0x80043E28: lwc1        $f18, 0x6314($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6314);
    // 0x80043E2C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80043E30: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80043E34: ori         $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 | 0X8000;
    // 0x80043E38: bc1f        L_80043E48
    if (!c1cs) {
        // 0x80043E3C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80043E48;
    }
    // 0x80043E3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043E40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80043E44: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
L_80043E48:
    // 0x80043E48: lb          $t8, 0x214($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X214);
    // 0x80043E4C: lh          $t6, 0x6E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6E);
    // 0x80043E50: beq         $t8, $zero, L_80043E5C
    if (ctx->r24 == 0) {
        // 0x80043E54: addiu       $t9, $zero, 0x40
        ctx->r25 = ADD32(0, 0X40);
            goto L_80043E5C;
    }
    // 0x80043E54: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80043E58: sb          $t6, 0x1CA($s0)
    MEM_B(0X1CA, ctx->r16) = ctx->r14;
L_80043E5C:
    // 0x80043E5C: lh          $t7, 0x1BA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1BA);
    // 0x80043E60: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80043E64: slti        $at, $t7, 0x41
    ctx->r1 = SIGNED(ctx->r15) < 0X41 ? 1 : 0;
    // 0x80043E68: bne         $at, $zero, L_80043E74
    if (ctx->r1 != 0) {
        // 0x80043E6C: nop
    
            goto L_80043E74;
    }
    // 0x80043E6C: nop

    // 0x80043E70: sh          $t9, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r25;
L_80043E74:
    // 0x80043E74: lh          $t8, 0x1BC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1BC);
    // 0x80043E78: addiu       $t9, $zero, -0x40
    ctx->r25 = ADD32(0, -0X40);
    // 0x80043E7C: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x80043E80: bne         $at, $zero, L_80043E8C
    if (ctx->r1 != 0) {
        // 0x80043E84: nop
    
            goto L_80043E8C;
    }
    // 0x80043E84: nop

    // 0x80043E88: sh          $t6, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r14;
L_80043E8C:
    // 0x80043E8C: lh          $t7, 0x1BA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1BA);
    // 0x80043E90: addiu       $t6, $zero, -0x28
    ctx->r14 = ADD32(0, -0X28);
    // 0x80043E94: slti        $at, $t7, -0x40
    ctx->r1 = SIGNED(ctx->r15) < -0X40 ? 1 : 0;
    // 0x80043E98: beq         $at, $zero, L_80043EA4
    if (ctx->r1 == 0) {
        // 0x80043E9C: nop
    
            goto L_80043EA4;
    }
    // 0x80043E9C: nop

    // 0x80043EA0: sh          $t9, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r25;
L_80043EA4:
    // 0x80043EA4: lh          $t8, 0x1BC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1BC);
    // 0x80043EA8: nop

    // 0x80043EAC: slti        $at, $t8, -0x28
    ctx->r1 = SIGNED(ctx->r24) < -0X28 ? 1 : 0;
    // 0x80043EB0: beq         $at, $zero, L_80043EC0
    if (ctx->r1 == 0) {
        // 0x80043EB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043EC0;
    }
    // 0x80043EB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043EB8: sh          $t6, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r14;
L_80043EBC:
    // 0x80043EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043EC0:
    // 0x80043EC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043EC4: jr          $ra
    // 0x80043EC8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80043EC8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void lerp_and_get_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228B0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800228B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800228B8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800228BC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800228C0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800228C4: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800228C8: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800228CC: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800228D0: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x800228D4: jr          $ra
    // 0x800228D8: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
    return;
    // 0x800228D8: add.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f8.fl;
;}
RECOMP_FUNC void set_breakpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void racer_approach_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050754: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005075C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050760: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80050764: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80050768: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x8005076C: lw          $v0, 0x148($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X148);
    // 0x80050770: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80050774: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80050778: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005077C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80050780: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80050784: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80050788: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005078C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80050790: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80050794: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80050798: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005079C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800507A0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800507A4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800507A8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x800507AC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x800507B0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800507B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800507B8: jal         0x80011570
    // 0x800507BC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    move_object(rdram, ctx);
        goto after_0;
    // 0x800507BC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800507C0: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x800507C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800507C8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800507CC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800507D0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800507D4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800507D8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800507DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800507E0: lw          $t9, 0x148($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X148);
    // 0x800507E4: div.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800507E8: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x800507EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800507F0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x800507F4: lw          $t1, 0x148($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X148);
    // 0x800507F8: nop

    // 0x800507FC: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80050800: nop

    // 0x80050804: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x80050808: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x8005080C: nop

    // 0x80050810: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x80050814: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80050818: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8005081C: nop

    // 0x80050820: sh          $t4, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r12;
    // 0x80050824: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80050828: div.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005082C: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80050830: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x80050834: sb          $zero, 0x1F2($s0)
    MEM_B(0X1F2, ctx->r16) = 0;
    // 0x80050838: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005083C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x80050840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80050844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050848: jr          $ra
    // 0x8005084C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005084C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void taj_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D360: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D364: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D368: jal         0x8006EA90
    // 0x8009D36C: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009D36C: nop

    after_0:
    // 0x8009D370: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009D374: lb          $v1, -0xB24($v1)
    ctx->r3 = MEM_B(ctx->r3, -0XB24);
    // 0x8009D378: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009D37C: beq         $v1, $zero, L_8009D39C
    if (ctx->r3 == 0) {
        // 0x8009D380: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009D39C;
    }
    // 0x8009D380: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D384: addiu       $v0, $v0, 0x64E2
    ctx->r2 = ADD32(ctx->r2, 0X64E2);
    // 0x8009D388: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D38C: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x8009D390: bne         $t6, $zero, L_8009D39C
    if (ctx->r14 != 0) {
        // 0x8009D394: nop
    
            goto L_8009D39C;
    }
    // 0x8009D394: nop

    // 0x8009D398: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8009D39C:
    // 0x8009D39C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D3A0: addiu       $v0, $v0, 0x64E2
    ctx->r2 = ADD32(ctx->r2, 0X64E2);
    // 0x8009D3A4: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D3A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009D3AC: bne         $a1, $zero, L_8009D3C0
    if (ctx->r5 != 0) {
        // 0x8009D3B0: nop
    
            goto L_8009D3C0;
    }
    // 0x8009D3B0: nop

    // 0x8009D3B4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8009D3B8: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8009D3BC: nop

L_8009D3C0:
    // 0x8009D3C0: blez        $a1, L_8009D3F4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009D3C4: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_8009D3F4;
    }
    // 0x8009D3C4: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8009D3C8: beq         $at, $zero, L_8009D3F4
    if (ctx->r1 == 0) {
        // 0x8009D3CC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009D3F4;
    }
    // 0x8009D3CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D3D0: addiu       $t9, $zero, 0x7C
    ctx->r25 = ADD32(0, 0X7C);
    // 0x8009D3D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D3D8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009D3DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009D3E0: jal         0x800C4EDC
    // 0x8009D3E4: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x8009D3E4: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_1:
    // 0x8009D3E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D3EC: jal         0x800C4F7C
    // 0x8009D3F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_2;
    // 0x8009D3F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8009D3F4:
    // 0x8009D3F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8009D3F8: jal         0x8006A554
    // 0x8009D3FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x8009D3FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009D400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D404: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D408: lb          $a1, 0x64E2($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X64E2);
    // 0x8009D40C: sb          $zero, 0x6504($at)
    MEM_B(0X6504, ctx->r1) = 0;
    // 0x8009D410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009D414: beq         $a1, $at, L_8009D444
    if (ctx->r5 == ctx->r1) {
        // 0x8009D418: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8009D444;
    }
    // 0x8009D418: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8009D41C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D420: beq         $a1, $at, L_8009D4EC
    if (ctx->r5 == ctx->r1) {
        // 0x8009D424: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009D4EC;
    }
    // 0x8009D424: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D428: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8009D42C: beq         $a1, $at, L_8009D444
    if (ctx->r5 == ctx->r1) {
        // 0x8009D430: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_8009D444;
    }
    // 0x8009D430: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8009D434: beq         $a1, $at, L_8009D4EC
    if (ctx->r5 == ctx->r1) {
        // 0x8009D438: nop
    
            goto L_8009D4EC;
    }
    // 0x8009D438: nop

    // 0x8009D43C: b           L_8009D5F4
    // 0x8009D440: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009D5F4;
    // 0x8009D440: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009D444:
    // 0x8009D444: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009D448: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8009D44C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D450: lw          $a3, 0xA0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XA0);
    // 0x8009D454: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D458: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D45C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009D460: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D464: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D468: jal         0x800C5168
    // 0x8009D46C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009D46C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x8009D470: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D474: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009D478: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8009D47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D480: sb          $t3, 0x650E($at)
    MEM_B(0X650E, ctx->r1) = ctx->r11;
    // 0x8009D484: lw          $a0, 0xA4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XA4);
    // 0x8009D488: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D48C: jal         0x8009D1B8
    // 0x8009D490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009D490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009D494: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D498: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009D49C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D4A0: lw          $a0, 0xA8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XA8);
    // 0x8009D4A4: jal         0x8009D1B8
    // 0x8009D4A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009D4A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009D4AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D4B0: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8009D4B4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D4B8: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8009D4BC: jal         0x8009D1B8
    // 0x8009D4C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_7;
    // 0x8009D4C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x8009D4C4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D4C8: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8009D4CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D4D0: lw          $a0, 0xB0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XB0);
    // 0x8009D4D4: jal         0x8009D1B8
    // 0x8009D4D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009D4D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009D4DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D4E0: lb          $a1, 0x64E2($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X64E2);
    // 0x8009D4E4: b           L_8009D5F4
    // 0x8009D4E8: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
        goto L_8009D5F4;
    // 0x8009D4E8: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009D4EC:
    // 0x8009D4EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D4F0: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009D4F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009D4F8: lw          $a3, 0xB4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XB4);
    // 0x8009D4FC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009D500: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009D504: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009D508: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D50C: jal         0x800C5168
    // 0x8009D510: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_9;
    // 0x8009D510: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_9:
    // 0x8009D514: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8009D518: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8009D51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D520: sb          $t1, 0x650E($at)
    MEM_B(0X650E, ctx->r1) = ctx->r9;
    // 0x8009D524: lhu         $v1, 0x14($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X14);
    // 0x8009D528: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D52C: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x8009D530: beq         $t3, $zero, L_8009D564
    if (ctx->r11 == 0) {
        // 0x8009D534: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_8009D564;
    }
    // 0x8009D534: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x8009D538: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D53C: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009D540: sb          $t4, -0xB14($at)
    MEM_B(-0XB14, ctx->r1) = ctx->r12;
    // 0x8009D544: lw          $a0, 0xB8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XB8);
    // 0x8009D548: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D54C: jal         0x8009D1B8
    // 0x8009D550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_10;
    // 0x8009D550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8009D554: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8009D558: nop

    // 0x8009D55C: lhu         $v1, 0x14($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X14);
    // 0x8009D560: nop

L_8009D564:
    // 0x8009D564: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8009D568: beq         $t7, $zero, L_8009D5A0
    if (ctx->r15 == 0) {
        // 0x8009D56C: andi        $t8, $v1, 0x10
        ctx->r24 = ctx->r3 & 0X10;
            goto L_8009D5A0;
    }
    // 0x8009D56C: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x8009D570: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009D574: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8009D578: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D57C: sb          $t8, -0xB14($at)
    MEM_B(-0XB14, ctx->r1) = ctx->r24;
    // 0x8009D580: lw          $a0, 0xBC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XBC);
    // 0x8009D584: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D588: jal         0x8009D1B8
    // 0x8009D58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009D58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8009D590: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8009D594: nop

    // 0x8009D598: lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X14);
    // 0x8009D59C: nop

L_8009D5A0:
    // 0x8009D5A0: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8009D5A4: beq         $t1, $zero, L_8009D5CC
    if (ctx->r9 == 0) {
        // 0x8009D5A8: andi        $t2, $v1, 0x20
        ctx->r10 = ctx->r3 & 0X20;
            goto L_8009D5CC;
    }
    // 0x8009D5A8: andi        $t2, $v1, 0x20
    ctx->r10 = ctx->r3 & 0X20;
    // 0x8009D5AC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009D5B0: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x8009D5B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D5B8: sb          $t2, -0xB14($at)
    MEM_B(-0XB14, ctx->r1) = ctx->r10;
    // 0x8009D5BC: lw          $a0, 0xC0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC0);
    // 0x8009D5C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D5C4: jal         0x8009D1B8
    // 0x8009D5C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009D5C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
L_8009D5CC:
    // 0x8009D5CC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D5D0: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009D5D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D5D8: lw          $a0, 0xB0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XB0);
    // 0x8009D5DC: jal         0x8009D1B8
    // 0x8009D5E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_13;
    // 0x8009D5E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // 0x8009D5E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D5E8: lb          $a1, 0x64E2($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X64E2);
    // 0x8009D5EC: nop

    // 0x8009D5F0: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
L_8009D5F4:
    // 0x8009D5F4: sltiu       $at, $t5, 0x10
    ctx->r1 = ctx->r13 < 0X10 ? 1 : 0;
    // 0x8009D5F8: beq         $at, $zero, L_8009D9E4
    if (ctx->r1 == 0) {
        // 0x8009D5FC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8009D9E4;
    }
    // 0x8009D5FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8009D600: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009D604: addu        $at, $at, $t5
    gpr jr_addend_8009D610 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009D608: lw          $t5, -0x7A60($at)
    ctx->r13 = ADD32(ctx->r1, -0X7A60);
    // 0x8009D60C: nop

    // 0x8009D610: jr          $t5
    // 0x8009D614: nop

    switch (jr_addend_8009D610 >> 2) {
        case 0: goto L_8009D944; break;
        case 1: goto L_8009D944; break;
        case 2: goto L_8009D944; break;
        case 3: goto L_8009D91C; break;
        case 4: goto L_8009D8F0; break;
        case 5: goto L_8009D8D4; break;
        case 6: goto L_8009D8D4; break;
        case 7: goto L_8009D8D4; break;
        case 8: goto L_8009D618; break;
        case 9: goto L_8009D638; break;
        case 10: goto L_8009D7A0; break;
        case 11: goto L_8009D840; break;
        case 12: goto L_8009D968; break;
        case 13: goto L_8009D998; break;
        case 14: goto L_8009D9B0; break;
        case 15: goto L_8009D9B0; break;
        default: switch_error(__func__, 0x8009D610, 0x800E85A0);
    }
    // 0x8009D614: nop

L_8009D618:
    // 0x8009D618: jal         0x800C31EC
    // 0x8009D61C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    set_current_text(rdram, ctx);
        goto after_14;
    // 0x8009D61C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x8009D620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009D624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D628: sb          $v0, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r2;
    // 0x8009D62C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D630: b           L_8009D9E4
    // 0x8009D634: sb          $v0, -0xB28($at)
    MEM_B(-0XB28, ctx->r1) = ctx->r2;
        goto L_8009D9E4;
    // 0x8009D634: sb          $v0, -0xB28($at)
    MEM_B(-0XB28, ctx->r1) = ctx->r2;
L_8009D638:
    // 0x8009D638: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D63C: lw          $t6, -0xB60($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB60);
    // 0x8009D640: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D644: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009D648: lw          $a3, 0x90($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X90);
    // 0x8009D64C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009D650: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009D654: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009D658: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009D65C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D660: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D664: jal         0x800C5168
    // 0x8009D668: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x8009D668: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_15:
    // 0x8009D66C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009D670: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8009D674: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8009D678: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D67C: sb          $t9, 0x650E($at)
    MEM_B(0X650E, ctx->r1) = ctx->r25;
    // 0x8009D680: lw          $a0, 0x94($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X94);
    // 0x8009D684: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D688: jal         0x8009D1B8
    // 0x8009D68C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_16;
    // 0x8009D68C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8009D690: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8009D694: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D698: lhu         $t2, 0x14($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X14);
    // 0x8009D69C: nop

    // 0x8009D6A0: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8009D6A4: beq         $t3, $zero, L_8009D6C0
    if (ctx->r11 == 0) {
        // 0x8009D6A8: nop
    
            goto L_8009D6C0;
    }
    // 0x8009D6A8: nop

    // 0x8009D6AC: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x8009D6B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D6B4: lw          $a0, 0x9C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X9C);
    // 0x8009D6B8: jal         0x8009D1B8
    // 0x8009D6BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_17;
    // 0x8009D6BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
L_8009D6C0:
    // 0x8009D6C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D6C4: lw          $t5, -0xB60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB60);
    // 0x8009D6C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009D6CC: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x8009D6D0: jal         0x8009D1B8
    // 0x8009D6D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_18;
    // 0x8009D6D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_18:
    // 0x8009D6D8: jal         0x8009D26C
    // 0x8009D6DC: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_19;
    // 0x8009D6DC: nop

    after_19:
    // 0x8009D6E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009D6E4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009D6E8: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009D6EC: beq         $t7, $zero, L_8009D710
    if (ctx->r15 == 0) {
        // 0x8009D6F0: andi        $t0, $t9, 0x8000
        ctx->r8 = ctx->r25 & 0X8000;
            goto L_8009D710;
    }
    // 0x8009D6F0: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8009D6F4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009D6F8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009D6FC: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009D700: jal         0x80001D04
    // 0x8009D704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_20;
    // 0x8009D704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x8009D708: b           L_8009D9E8
    // 0x8009D70C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D70C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D710:
    // 0x8009D710: beq         $t0, $zero, L_8009D9E4
    if (ctx->r8 == 0) {
        // 0x8009D714: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009D9E4;
    }
    // 0x8009D714: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009D718: jal         0x80001D04
    // 0x8009D71C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x8009D71C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8009D720: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D724: lb          $v1, 0x6516($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6516);
    // 0x8009D728: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009D72C: beq         $v1, $zero, L_8009D780
    if (ctx->r3 == 0) {
        // 0x8009D730: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8009D780;
    }
    // 0x8009D730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009D738: beq         $v1, $at, L_8009D754
    if (ctx->r3 == ctx->r1) {
        // 0x8009D73C: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8009D754;
    }
    // 0x8009D73C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009D740: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009D744: beq         $v1, $at, L_8009D778
    if (ctx->r3 == ctx->r1) {
        // 0x8009D748: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009D778;
    }
    // 0x8009D748: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009D74C: b           L_8009D9E8
    // 0x8009D750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D754:
    // 0x8009D754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D758: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
    // 0x8009D75C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D760: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
    // 0x8009D764: addiu       $a0, $zero, 0x239
    ctx->r4 = ADD32(0, 0X239);
    // 0x8009D768: jal         0x8003AC3C
    // 0x8009D76C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_22;
    // 0x8009D76C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8009D770: b           L_8009D9E8
    // 0x8009D774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D778:
    // 0x8009D778: b           L_8009D9E4
    // 0x8009D77C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_8009D9E4;
    // 0x8009D77C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8009D780:
    // 0x8009D780: sb          $t3, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r11;
    // 0x8009D784: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D788: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
    // 0x8009D78C: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x8009D790: jal         0x8003AC3C
    // 0x8009D794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_23;
    // 0x8009D794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8009D798: b           L_8009D9E8
    // 0x8009D79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D7A0:
    // 0x8009D7A0: jal         0x8009D26C
    // 0x8009D7A4: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_24;
    // 0x8009D7A4: nop

    after_24:
    // 0x8009D7A8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8009D7AC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009D7B0: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x8009D7B4: beq         $t5, $zero, L_8009D7EC
    if (ctx->r13 == 0) {
        // 0x8009D7B8: andi        $t8, $t7, 0x8000
        ctx->r24 = ctx->r15 & 0X8000;
            goto L_8009D7EC;
    }
    // 0x8009D7B8: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8009D7BC: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009D7C0: jal         0x80001D04
    // 0x8009D7C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_25;
    // 0x8009D7C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8009D7C8: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009D7CC: jal         0x8003AC3C
    // 0x8009D7D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x8009D7D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8009D7D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009D7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D7DC: sb          $t6, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r14;
    // 0x8009D7E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D7E4: b           L_8009D9E4
    // 0x8009D7E8: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
        goto L_8009D9E4;
    // 0x8009D7E8: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
L_8009D7EC:
    // 0x8009D7EC: beq         $t8, $zero, L_8009D9E4
    if (ctx->r24 == 0) {
        // 0x8009D7F0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009D9E4;
    }
    // 0x8009D7F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D7F4: lb          $v0, 0x6516($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6516);
    // 0x8009D7F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D7FC: beq         $v0, $at, L_8009D81C
    if (ctx->r2 == ctx->r1) {
        // 0x8009D800: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8009D81C;
    }
    // 0x8009D800: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D804: ori         $t9, $v0, 0x80
    ctx->r25 = ctx->r2 | 0X80;
    // 0x8009D808: addiu       $t0, $zero, 0x62
    ctx->r8 = ADD32(0, 0X62);
    // 0x8009D80C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D810: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8009D814: b           L_8009D9E4
    // 0x8009D818: sb          $t0, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r8;
        goto L_8009D9E4;
    // 0x8009D818: sb          $t0, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r8;
L_8009D81C:
    // 0x8009D81C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D820: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
    // 0x8009D824: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D828: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
    // 0x8009D82C: addiu       $a0, $zero, 0x238
    ctx->r4 = ADD32(0, 0X238);
    // 0x8009D830: jal         0x8003AC3C
    // 0x8009D834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_27;
    // 0x8009D834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8009D838: b           L_8009D9E8
    // 0x8009D83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D83C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D840:
    // 0x8009D840: jal         0x8009D26C
    // 0x8009D844: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_28;
    // 0x8009D844: nop

    after_28:
    // 0x8009D848: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009D84C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009D850: andi        $t2, $v1, 0x4000
    ctx->r10 = ctx->r3 & 0X4000;
    // 0x8009D854: bne         $t2, $zero, L_8009D874
    if (ctx->r10 != 0) {
        // 0x8009D858: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8009D874;
    }
    // 0x8009D858: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8009D85C: beq         $v0, $zero, L_8009D8A4
    if (ctx->r2 == 0) {
        // 0x8009D860: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009D8A4;
    }
    // 0x8009D860: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009D864: lb          $t3, 0x6516($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6516);
    // 0x8009D868: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D86C: bne         $t3, $at, L_8009D8A4
    if (ctx->r11 != ctx->r1) {
        // 0x8009D870: nop
    
            goto L_8009D8A4;
    }
    // 0x8009D870: nop

L_8009D874:
    // 0x8009D874: jal         0x80001D04
    // 0x8009D878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_29;
    // 0x8009D878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009D87C: addiu       $a0, $zero, 0x23A
    ctx->r4 = ADD32(0, 0X23A);
    // 0x8009D880: jal         0x8003AC3C
    // 0x8009D884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x8009D884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8009D888: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009D88C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D890: sb          $t4, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r12;
    // 0x8009D894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D898: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8009D89C: b           L_8009D9E4
    // 0x8009D8A0: sb          $t5, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = ctx->r13;
        goto L_8009D9E4;
    // 0x8009D8A0: sb          $t5, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = ctx->r13;
L_8009D8A4:
    // 0x8009D8A4: beq         $v0, $zero, L_8009D9E4
    if (ctx->r2 == 0) {
        // 0x8009D8A8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009D9E4;
    }
    // 0x8009D8A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009D8AC: lb          $t6, 0x6516($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6516);
    // 0x8009D8B0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009D8B4: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8009D8B8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8009D8BC: jal         0x80001D04
    // 0x8009D8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_31;
    // 0x8009D8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x8009D8C4: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x8009D8C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D8CC: b           L_8009D9E4
    // 0x8009D8D0: sb          $t8, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r24;
        goto L_8009D9E4;
    // 0x8009D8D0: sb          $t8, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r24;
L_8009D8D4:
    // 0x8009D8D4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009D8D8: jal         0x800C31EC
    // 0x8009D8DC: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_32;
    // 0x8009D8DC: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    after_32:
    // 0x8009D8E0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8009D8E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D8E8: b           L_8009D9E4
    // 0x8009D8EC: sb          $t0, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r8;
        goto L_8009D9E4;
    // 0x8009D8EC: sb          $t0, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r8;
L_8009D8F0:
    // 0x8009D8F0: jal         0x800C31EC
    // 0x8009D8F4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    set_current_text(rdram, ctx);
        goto after_33;
    // 0x8009D8F4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_33:
    // 0x8009D8F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D8FC: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009D900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D904: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D908: sb          $t1, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r9;
    // 0x8009D90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D910: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009D914: b           L_8009D9E4
    // 0x8009D918: sb          $t2, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = ctx->r10;
        goto L_8009D9E4;
    // 0x8009D918: sb          $t2, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = ctx->r10;
L_8009D91C:
    // 0x8009D91C: jal         0x800C31EC
    // 0x8009D920: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    set_current_text(rdram, ctx);
        goto after_34;
    // 0x8009D920: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_34:
    // 0x8009D924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D928: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009D92C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D930: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8009D934: sb          $t3, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r11;
    // 0x8009D938: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D93C: b           L_8009D9E4
    // 0x8009D940: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
        goto L_8009D9E4;
    // 0x8009D940: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
L_8009D944:
    // 0x8009D944: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8009D948: jal         0x800C31EC
    // 0x8009D94C: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    set_current_text(rdram, ctx);
        goto after_35;
    // 0x8009D94C: subu        $a0, $t4, $a1
    ctx->r4 = SUB32(ctx->r12, ctx->r5);
    after_35:
    // 0x8009D950: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8009D954: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D958: sb          $t5, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r13;
    // 0x8009D95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D960: b           L_8009D9E4
    // 0x8009D964: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
        goto L_8009D9E4;
    // 0x8009D964: sb          $zero, 0x64D8($at)
    MEM_B(0X64D8, ctx->r1) = 0;
L_8009D968:
    // 0x8009D968: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D96C: lb          $t6, -0xB24($t6)
    ctx->r14 = MEM_B(ctx->r14, -0XB24);
    // 0x8009D970: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8009D974: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8009D978: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8009D97C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D980: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8009D984: sb          $t9, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = ctx->r25;
    // 0x8009D988: jal         0x800C5620
    // 0x8009D98C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_36;
    // 0x8009D98C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x8009D990: b           L_8009D9E8
    // 0x8009D994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D998:
    // 0x8009D998: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D99C: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009D9A0: jal         0x800C5620
    // 0x8009D9A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_37;
    // 0x8009D9A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_37:
    // 0x8009D9A8: b           L_8009D9E8
    // 0x8009D9AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D9E8;
    // 0x8009D9AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D9B0:
    // 0x8009D9B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8009D9B4: bne         $a1, $at, L_8009D9C0
    if (ctx->r5 != ctx->r1) {
        // 0x8009D9B8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8009D9C0;
    }
    // 0x8009D9B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009D9BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8009D9C0:
    // 0x8009D9C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D9C4: sb          $zero, -0xB20($at)
    MEM_B(-0XB20, ctx->r1) = 0;
    // 0x8009D9C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D9CC: jal         0x800C5620
    // 0x8009D9D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    dialogue_close(rdram, ctx);
        goto after_38;
    // 0x8009D9D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_38:
    // 0x8009D9D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D9D8: sb          $zero, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = 0;
    // 0x8009D9DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D9E0: sb          $zero, 0x64E2($at)
    MEM_B(0X64E2, ctx->r1) = 0;
L_8009D9E4:
    // 0x8009D9E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D9E8:
    // 0x8009D9E8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8009D9EC: jr          $ra
    // 0x8009D9F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009D9F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA88: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8000AA8C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8000AA90: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x8000AA94: bltz        $v1, L_8000AAA4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000AA98: nop
    
            goto L_8000AAA4;
    }
    // 0x8000AA98: nop

    // 0x8000AA9C: jr          $ra
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000AAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000AAA4:
    // 0x8000AAA4: jr          $ra
    // 0x8000AAA8: nop

    return;
    // 0x8000AAA8: nop

;}
RECOMP_FUNC void particle_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B22FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B2304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B2308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B230C: sw          $a1, 0x7C80($at)
    MEM_W(0X7C80, ctx->r1) = ctx->r5;
    // 0x800B2310: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2314: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B2318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B231C: bne         $v0, $at, L_800B2334
    if (ctx->r2 != ctx->r1) {
        // 0x800B2320: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B2334;
    }
    // 0x800B2320: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2324: jal         0x800B26E0
    // 0x800B2328: nop

    update_line_particle(rdram, ctx);
        goto after_0;
    // 0x800B2328: nop

    after_0:
    // 0x800B232C: b           L_800B2630
    // 0x800B2330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2630;
    // 0x800B2330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2334:
    // 0x800B2334: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800B2338: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800B233C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800B2340: beq         $t7, $zero, L_800B2370
    if (ctx->r15 == 0) {
        // 0x800B2344: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800B2370;
    }
    // 0x800B2344: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800B2348: lw          $t8, 0x7C80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7C80);
    // 0x800B234C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2350: blez        $t8, L_800B236C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B2354: nop
    
            goto L_800B236C;
    }
    // 0x800B2354: nop

    // 0x800B2358: jal         0x800B2FBC
    // 0x800B235C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    update_particle_texture_frame(rdram, ctx);
        goto after_1;
    // 0x800B235C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x800B2360: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800B2364: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B2368: nop

L_800B236C:
    // 0x800B236C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_800B2370:
    // 0x800B2370: bne         $a0, $v0, L_800B238C
    if (ctx->r4 != ctx->r2) {
        // 0x800B2374: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800B238C;
    }
    // 0x800B2374: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B2378: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B237C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800B2380: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B2384: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    // 0x800B2388: sb          $zero, 0x77($s0)
    MEM_B(0X77, ctx->r16) = 0;
L_800B238C:
    // 0x800B238C: beq         $v1, $zero, L_800B23AC
    if (ctx->r3 == 0) {
        // 0x800B2390: nop
    
            goto L_800B23AC;
    }
    // 0x800B2390: nop

    // 0x800B2394: beq         $v1, $zero, L_800B2420
    if (ctx->r3 == 0) {
        // 0x800B2398: nop
    
            goto L_800B2420;
    }
    // 0x800B2398: nop

    // 0x800B239C: lw          $t2, 0x70($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X70);
    // 0x800B23A0: nop

    // 0x800B23A4: beq         $t2, $zero, L_800B2420
    if (ctx->r10 == 0) {
        // 0x800B23A8: nop
    
            goto L_800B2420;
    }
    // 0x800B23A8: nop

L_800B23AC:
    // 0x800B23AC: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B23B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B23B4: bne         $v0, $at, L_800B23D0
    if (ctx->r2 != ctx->r1) {
        // 0x800B23B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B23D0;
    }
    // 0x800B23B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B23BC: jal         0x800B3358
    // 0x800B23C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_with_acceleration(rdram, ctx);
        goto after_2;
    // 0x800B23C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B23C4: b           L_800B2424
    // 0x800B23C8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2424;
    // 0x800B23C8: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x800B23CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800B23D0:
    // 0x800B23D0: bne         $v0, $at, L_800B23E8
    if (ctx->r2 != ctx->r1) {
        // 0x800B23D4: nop
    
            goto L_800B23E8;
    }
    // 0x800B23D4: nop

    // 0x800B23D8: jal         0x800B3240
    // 0x800B23DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_attached_to_parent(rdram, ctx);
        goto after_3;
    // 0x800B23DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B23E0: b           L_800B2424
    // 0x800B23E4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2424;
    // 0x800B23E4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B23E8:
    // 0x800B23E8: bne         $a0, $v0, L_800B2400
    if (ctx->r4 != ctx->r2) {
        // 0x800B23EC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800B2400;
    }
    // 0x800B23EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B23F0: jal         0x800B3140
    // 0x800B23F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic_parent(rdram, ctx);
        goto after_4;
    // 0x800B23F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800B23F8: b           L_800B2424
    // 0x800B23FC: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2424;
    // 0x800B23FC: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2400:
    // 0x800B2400: bne         $v0, $at, L_800B2418
    if (ctx->r2 != ctx->r1) {
        // 0x800B2404: nop
    
            goto L_800B2418;
    }
    // 0x800B2404: nop

    // 0x800B2408: jal         0x800B3564
    // 0x800B240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_forward(rdram, ctx);
        goto after_5;
    // 0x800B240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800B2410: b           L_800B2424
    // 0x800B2414: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
        goto L_800B2424;
    // 0x800B2414: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2418:
    // 0x800B2418: jal         0x800B34B0
    // 0x800B241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_particle_basic(rdram, ctx);
        goto after_6;
    // 0x800B241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B2420:
    // 0x800B2420: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
L_800B2424:
    // 0x800B2424: jal         0x8002A2DC
    // 0x800B2428: nop

    block_boundbox(rdram, ctx);
        goto after_7;
    // 0x800B2428: nop

    after_7:
    // 0x800B242C: beq         $v0, $zero, L_800B2524
    if (ctx->r2 == 0) {
        // 0x800B2430: nop
    
            goto L_800B2524;
    }
    // 0x800B2430: nop

    // 0x800B2434: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B2438: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B243C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B2440: nop

    // 0x800B2444: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2448: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800B244C: nop

    // 0x800B2450: bc1t        L_800B250C
    if (c1cs) {
        // 0x800B2454: nop
    
            goto L_800B250C;
    }
    // 0x800B2454: nop

    // 0x800B2458: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B245C: nop

    // 0x800B2460: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800B2464: nop

    // 0x800B2468: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B246C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800B2470: nop

    // 0x800B2474: bc1t        L_800B250C
    if (c1cs) {
        // 0x800B2478: nop
    
            goto L_800B250C;
    }
    // 0x800B2478: nop

    // 0x800B247C: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x800B2480: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2484: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800B2488: nop

    // 0x800B248C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B2490: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B2494: nop

    // 0x800B2498: bc1t        L_800B250C
    if (c1cs) {
        // 0x800B249C: nop
    
            goto L_800B250C;
    }
    // 0x800B249C: nop

    // 0x800B24A0: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800B24A4: nop

    // 0x800B24A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B24AC: nop

    // 0x800B24B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B24B4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B24B8: nop

    // 0x800B24BC: bc1t        L_800B250C
    if (c1cs) {
        // 0x800B24C0: nop
    
            goto L_800B250C;
    }
    // 0x800B24C0: nop

    // 0x800B24C4: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800B24C8: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B24CC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B24D0: nop

    // 0x800B24D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B24D8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800B24DC: nop

    // 0x800B24E0: bc1t        L_800B250C
    if (c1cs) {
        // 0x800B24E4: nop
    
            goto L_800B250C;
    }
    // 0x800B24E4: nop

    // 0x800B24E8: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800B24EC: nop

    // 0x800B24F0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B24F4: nop

    // 0x800B24F8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B24FC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800B2500: nop

    // 0x800B2504: bc1f        L_800B253C
    if (!c1cs) {
        // 0x800B2508: nop
    
            goto L_800B253C;
    }
    // 0x800B2508: nop

L_800B250C:
    // 0x800B250C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B2510: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2514: jal         0x80029F18
    // 0x800B2518: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_8;
    // 0x800B2518: nop

    after_8:
    // 0x800B251C: b           L_800B253C
    // 0x800B2520: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
        goto L_800B253C;
    // 0x800B2520: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B2524:
    // 0x800B2524: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B2528: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B252C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B2530: jal         0x80029F18
    // 0x800B2534: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x800B2534: nop

    after_9:
    // 0x800B2538: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
L_800B253C:
    // 0x800B253C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800B2540: lw          $t9, 0x7C80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7C80);
    // 0x800B2544: lh          $t0, 0x3A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2548: nop

    // 0x800B254C: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x800B2550: sh          $t1, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r9;
    // 0x800B2554: lh          $t2, 0x3A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X3A);
    // 0x800B2558: nop

    // 0x800B255C: bgtz        $t2, L_800B2574
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B2560: nop
    
            goto L_800B2574;
    }
    // 0x800B2560: nop

    // 0x800B2564: jal         0x8000FFB8
    // 0x800B2568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x800B2568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800B256C: b           L_800B2630
    // 0x800B2570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800B2630;
    // 0x800B2570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2574:
    // 0x800B2574: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2578: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800B257C: bne         $v0, $zero, L_800B25F0
    if (ctx->r2 != 0) {
        // 0x800B2580: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800B25F0;
    }
    // 0x800B2580: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B2584: lw          $t3, 0x7C80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7C80);
    // 0x800B2588: lh          $t4, 0x5E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5E);
    // 0x800B258C: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2590: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2594: mflo        $t5
    ctx->r13 = lo;
    // 0x800B2598: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800B259C: sh          $t7, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r15;
    // 0x800B25A0: lh          $t8, 0x5C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5C);
    // 0x800B25A4: nop

    // 0x800B25A8: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800B25AC: beq         $at, $zero, L_800B2630
    if (ctx->r1 == 0) {
        // 0x800B25B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2630;
    }
    // 0x800B25B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B25B4: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x800B25B8: nop

    // 0x800B25BC: andi        $t9, $t0, 0x1000
    ctx->r25 = ctx->r8 & 0X1000;
    // 0x800B25C0: beq         $t9, $zero, L_800B25DC
    if (ctx->r25 == 0) {
        // 0x800B25C4: nop
    
            goto L_800B25DC;
    }
    // 0x800B25C4: nop

    // 0x800B25C8: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800B25CC: nop

    // 0x800B25D0: ori         $t2, $t1, 0x100
    ctx->r10 = ctx->r9 | 0X100;
    // 0x800B25D4: b           L_800B262C
    // 0x800B25D8: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
        goto L_800B262C;
    // 0x800B25D8: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
L_800B25DC:
    // 0x800B25DC: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x800B25E0: nop

    // 0x800B25E4: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x800B25E8: b           L_800B262C
    // 0x800B25EC: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
        goto L_800B262C;
    // 0x800B25EC: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
L_800B25F0:
    // 0x800B25F0: lw          $t6, 0x7C80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7C80);
    // 0x800B25F4: nop

    // 0x800B25F8: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x800B25FC: sh          $t5, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r13;
    // 0x800B2600: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B2604: nop

    // 0x800B2608: bgez        $v0, L_800B2630
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B260C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2630;
    }
    // 0x800B260C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2610: lh          $t8, 0x5E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5E);
    // 0x800B2614: lh          $t7, 0x5C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5C);
    // 0x800B2618: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B261C: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x800B2620: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2624: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x800B2628: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
L_800B262C:
    // 0x800B262C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2630:
    // 0x800B2630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B2634: jr          $ra
    // 0x800B2638: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B2638: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void collision_objectmodel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017248: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x8001724C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80017250: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80017254: addiu       $s5, $s5, -0x5190
    ctx->r21 = ADD32(ctx->r21, -0X5190);
    // 0x80017258: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8001725C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80017260: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80017264: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80017268: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8001726C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80017270: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80017274: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80017278: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8001727C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80017280: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017284: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x80017288: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x8001728C: sw          $a3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r7;
    // 0x80017290: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
    // 0x80017294: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x80017298: blez        $t6, L_80017488
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001729C: sw          $a2, 0x180($sp)
        MEM_W(0X180, ctx->r29) = ctx->r6;
            goto L_80017488;
    }
    // 0x8001729C: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800172A4: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800172A8: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800172AC: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x800172B0: addiu       $s3, $sp, 0xB4
    ctx->r19 = ADD32(ctx->r29, 0XB4);
    // 0x800172B4: addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
L_800172B8:
    // 0x800172B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800172BC: lw          $t7, -0x5194($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5194);
    // 0x800172C0: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800172C4: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800172C8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800172CC: nop

    // 0x800172D0: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x800172D4: lw          $t9, 0x68($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X68);
    // 0x800172D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800172DC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800172E0: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800172E4: nop

    // 0x800172E8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800172EC: nop

    // 0x800172F0: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800172F4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800172F8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800172FC: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80017300: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80017304: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80017308: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001730C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80017310: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80017314: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80017318: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001731C: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80017320: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x80017324: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80017328: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001732C: jal         0x800C9AD0
    // 0x80017330: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80017330: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80017334: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80017338: lw          $a0, 0x158($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X158);
    // 0x8001733C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80017340: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80017344: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80017348: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8001734C: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80017350: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80017354: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80017358: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001735C: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80017360: beq         $t8, $zero, L_8001736C
    if (ctx->r24 == 0) {
        // 0x80017364: or          $fp, $v0, $zero
        ctx->r30 = ctx->r2 | 0;
            goto L_8001736C;
    }
    // 0x80017364: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80017368: sra         $fp, $v0, 3
    ctx->r30 = S32(SIGNED(ctx->r2) >> 3);
L_8001736C:
    // 0x8001736C: slti        $at, $fp, 0x100
    ctx->r1 = SIGNED(ctx->r30) < 0X100 ? 1 : 0;
    // 0x80017370: bne         $at, $zero, L_8001737C
    if (ctx->r1 != 0) {
        // 0x80017374: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001737C;
    }
    // 0x80017374: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017378: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_8001737C:
    // 0x8001737C: lbu         $t2, 0x13($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X13);
    // 0x80017380: nop

    // 0x80017384: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80017388: beq         $at, $zero, L_800173A8
    if (ctx->r1 == 0) {
        // 0x8001738C: lw          $t4, 0x154($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X154);
            goto L_800173A8;
    }
    // 0x8001738C: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80017390: sb          $fp, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r30;
    // 0x80017394: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x80017398: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x8001739C: nop

    // 0x800173A0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800173A4: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
L_800173A8:
    // 0x800173A8: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800173AC: lwc1        $f6, 0x3C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x800173B0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800173B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800173B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800173BC: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x800173C0: lw          $t5, 0x170($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X170);
    // 0x800173C4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800173C8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800173CC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800173D0: addu        $t6, $s3, $v0
    ctx->r14 = ADD32(ctx->r19, ctx->r2);
    // 0x800173D4: bc1f        L_80017460
    if (!c1cs) {
        // 0x800173D8: addu        $v1, $s4, $v0
        ctx->r3 = ADD32(ctx->r20, ctx->r2);
            goto L_80017460;
    }
    // 0x800173D8: addu        $v1, $s4, $v0
    ctx->r3 = ADD32(ctx->r20, ctx->r2);
    // 0x800173DC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800173E0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800173E4: blez        $a1, L_80017458
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800173E8: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80017458;
    }
    // 0x800173E8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800173EC: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800173F0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800173F4: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x800173F8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800173FC: addu        $v1, $s4, $a0
    ctx->r3 = ADD32(ctx->r20, ctx->r4);
    // 0x80017400: bc1f        L_80017458
    if (!c1cs) {
        // 0x80017404: nop
    
            goto L_80017458;
    }
    // 0x80017404: nop

    // 0x80017408: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8001740C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017410: addu        $v0, $s3, $a0
    ctx->r2 = ADD32(ctx->r19, ctx->r4);
L_80017414:
    // 0x80017414: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80017418: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8001741C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80017420: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80017424: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80017428: swc1        $f2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8001742C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80017430: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80017434: bne         $at, $zero, L_80017458
    if (ctx->r1 != 0) {
        // 0x80017438: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_80017458;
    }
    // 0x80017438: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001743C: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80017440: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80017444: nop

    // 0x80017448: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001744C: nop

    // 0x80017450: bc1t        L_80017414
    if (c1cs) {
        // 0x80017454: nop
    
            goto L_80017414;
    }
    // 0x80017454: nop

L_80017458:
    // 0x80017458: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001745C: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_80017460:
    // 0x80017460: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    // 0x80017464: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80017468: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8001746C: lw          $a1, 0x160($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X160);
    // 0x80017470: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80017474: bne         $at, $zero, L_800172B8
    if (ctx->r1 != 0) {
        // 0x80017478: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800172B8;
    }
    // 0x80017478: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x8001747C: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x80017480: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    // 0x80017484: sw          $a1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r5;
L_80017488:
    // 0x80017488: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x8001748C: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x80017490: blez        $t3, L_80017874
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017494: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80017874;
    }
    // 0x80017494: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80017498: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001749C: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x800174A0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800174A4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800174A8: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x800174AC: sw          $a0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r4;
    // 0x800174B0: sw          $a2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r6;
    // 0x800174B4: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
L_800174B8:
    // 0x800174B8: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800174BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800174C0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800174C4: lw          $t4, -0x5194($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5194);
    // 0x800174C8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800174CC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800174D0: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800174D4: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x800174D8: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x800174DC: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x800174E0: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800174E4: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x800174E8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800174EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800174F0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800174F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800174F8: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800174FC: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017500: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80017504: lbu         $t4, 0x104($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X104);
    // 0x80017508: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x8001750C: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80017510: andi        $t2, $t6, 0x1
    ctx->r10 = ctx->r14 & 0X1;
    // 0x80017514: sll         $t8, $t2, 6
    ctx->r24 = S32(ctx->r10 << 6);
    // 0x80017518: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001751C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x80017520: jal         0x8001790C
    // 0x80017524: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    func_8001790C(rdram, ctx);
        goto after_1;
    // 0x80017524: sw          $a1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r5;
    after_1:
    // 0x80017528: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001752C: beq         $v0, $zero, L_800175E0
    if (ctx->r2 == 0) {
        // 0x80017530: sw          $v0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r2;
            goto L_800175E0;
    }
    // 0x80017530: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
    // 0x80017534: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x80017538: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x8001753C: blez        $t3, L_80017644
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80017540: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80017644;
    }
    // 0x80017540: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80017544: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x80017548: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x8001754C: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
    // 0x80017550: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x80017554: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x80017558: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_8001755C:
    // 0x8001755C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80017560: nop

    // 0x80017564: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x80017568: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001756C: nop

    // 0x80017570: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80017574: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80017578: nop

    // 0x8001757C: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80017580: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80017584: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80017588: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8001758C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80017590: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017594: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80017598: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8001759C: jal         0x8006F64C
    // 0x800175A0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800175A0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_2:
    // 0x800175A4: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800175A8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800175AC: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800175B0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800175B4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800175B8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800175BC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800175C0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800175C4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800175C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800175CC: bne         $fp, $t5, L_8001755C
    if (ctx->r30 != ctx->r13) {
        // 0x800175D0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8001755C;
    }
    // 0x800175D0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800175D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800175D8: b           L_80017644
    // 0x800175DC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
        goto L_80017644;
    // 0x800175DC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_800175E0:
    // 0x800175E0: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x800175E4: addiu       $s2, $sp, 0x13C
    ctx->r18 = ADD32(ctx->r29, 0X13C);
    // 0x800175E8: blez        $t4, L_80017644
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800175EC: addiu       $s3, $sp, 0x12C
        ctx->r19 = ADD32(ctx->r29, 0X12C);
            goto L_80017644;
    }
    // 0x800175EC: addiu       $s3, $sp, 0x12C
    ctx->r19 = ADD32(ctx->r29, 0X12C);
    // 0x800175F0: lw          $s0, 0x184($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X184);
    // 0x800175F4: addiu       $s4, $sp, 0x11C
    ctx->r20 = ADD32(ctx->r29, 0X11C);
L_800175F8:
    // 0x800175F8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800175FC: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80017600: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80017604: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80017608: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x8001760C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80017610: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80017614: jal         0x8006F64C
    // 0x80017618: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80017618: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x8001761C: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x80017620: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017624: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017628: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001762C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80017630: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80017634: bne         $fp, $t6, L_800175F8
    if (ctx->r30 != ctx->r14) {
        // 0x80017638: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800175F8;
    }
    // 0x80017638: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8001763C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80017640: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80017644:
    // 0x80017644: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x80017648: addiu       $s5, $sp, 0x100
    ctx->r21 = ADD32(ctx->r29, 0X100);
    // 0x8001764C: blez        $t7, L_800176A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80017650: addiu       $s6, $sp, 0xF0
        ctx->r22 = ADD32(ctx->r29, 0XF0);
            goto L_800176A4;
    }
    // 0x80017650: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x80017654: lw          $s1, 0x188($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X188);
    // 0x80017658: addiu       $s7, $sp, 0xE0
    ctx->r23 = ADD32(ctx->r29, 0XE0);
L_8001765C:
    // 0x8001765C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80017660: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80017664: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80017668: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x8001766C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017670: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80017674: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80017678: jal         0x8006F64C
    // 0x8001767C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mtxf_transform_point(rdram, ctx);
        goto after_4;
    // 0x8001767C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_4:
    // 0x80017680: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x80017684: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017688: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x8001768C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80017690: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80017694: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80017698: bne         $fp, $t2, L_8001765C
    if (ctx->r30 != ctx->r10) {
        // 0x8001769C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8001765C;
    }
    // 0x8001769C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800176A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800176A4:
    // 0x800176A4: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x800176A8: addiu       $t8, $sp, 0x12C
    ctx->r24 = ADD32(ctx->r29, 0X12C);
    // 0x800176AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800176B0: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800176B4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800176B8: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800176BC: addiu       $t9, $sp, 0x11C
    ctx->r25 = ADD32(ctx->r29, 0X11C);
    // 0x800176C0: addiu       $t3, $sp, 0x100
    ctx->r11 = ADD32(ctx->r29, 0X100);
    // 0x800176C4: addiu       $t5, $sp, 0xF0
    ctx->r13 = ADD32(ctx->r29, 0XF0);
    // 0x800176C8: addiu       $t4, $sp, 0xE0
    ctx->r12 = ADD32(ctx->r29, 0XE0);
    // 0x800176CC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800176D0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800176D4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800176D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800176DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800176E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800176E4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800176E8: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800176EC: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x800176F0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800176F4: nop

    // 0x800176F8: div.d       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f20.d, ctx->f16.d);
    // 0x800176FC: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80017700: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    // 0x80017704: addiu       $a3, $sp, 0x13C
    ctx->r7 = ADD32(ctx->r29, 0X13C);
    // 0x80017708: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8001770C: jal         0x80017A18
    // 0x80017710: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_80017A18(rdram, ctx);
        goto after_5;
    // 0x80017710: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80017714: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017718: beq         $v0, $zero, L_80017734
    if (ctx->r2 == 0) {
        // 0x8001771C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80017734;
    }
    // 0x8001771C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80017720: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017724: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x80017728: lw          $t9, 0x5C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X5C);
    // 0x8001772C: nop

    // 0x80017730: sw          $t8, 0x100($t9)
    MEM_W(0X100, ctx->r25) = ctx->r24;
L_80017734:
    // 0x80017734: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80017738: lb          $t3, -0x52DC($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X52DC);
    // 0x8001773C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x80017740: bne         $t3, $zero, L_80017760
    if (ctx->r11 != 0) {
        // 0x80017744: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80017760;
    }
    // 0x80017744: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80017748: lw          $a0, 0x178($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X178);
    // 0x8001774C: jal         0x80017978
    // 0x80017750: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    func_80017978(rdram, ctx);
        goto after_6;
    // 0x80017750: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_6:
    // 0x80017754: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017758: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x8001775C: sw          $v0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r2;
L_80017760:
    // 0x80017760: lw          $v0, 0x5C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5C);
    // 0x80017764: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x80017768: lbu         $t5, 0x104($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X104);
    // 0x8001776C: nop

    // 0x80017770: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80017774: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80017778: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x8001777C: blez        $t8, L_80017840
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80017780: sw          $t2, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r10;
            goto L_80017840;
    }
    // 0x80017780: sw          $t2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r10;
L_80017784:
    // 0x80017784: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x80017788: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8001778C: beq         $t9, $zero, L_800177C4
    if (ctx->r25 == 0) {
        // 0x80017790: and         $t7, $s2, $t0
        ctx->r15 = ctx->r18 & ctx->r8;
            goto L_800177C4;
    }
    // 0x80017790: and         $t7, $s2, $t0
    ctx->r15 = ctx->r18 & ctx->r8;
    // 0x80017794: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x80017798: addu        $t5, $sp, $v0
    ctx->r13 = ADD32(ctx->r29, ctx->r2);
    // 0x8001779C: lwc1        $f8, 0x100($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X100);
    // 0x800177A0: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x800177A4: addu        $t4, $sp, $v0
    ctx->r12 = ADD32(ctx->r29, ctx->r2);
    // 0x800177A8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800177AC: lwc1        $f4, 0xF0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800177B0: addu        $t6, $sp, $v0
    ctx->r14 = ADD32(ctx->r29, ctx->r2);
    // 0x800177B4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800177B8: lwc1        $f10, 0xE0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XE0);
    // 0x800177BC: nop

    // 0x800177C0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_800177C4:
    // 0x800177C4: beq         $t7, $zero, L_80017828
    if (ctx->r15 == 0) {
        // 0x800177C8: sll         $v0, $fp, 2
        ctx->r2 = S32(ctx->r30 << 2);
            goto L_80017828;
    }
    // 0x800177C8: sll         $v0, $fp, 2
    ctx->r2 = S32(ctx->r30 << 2);
    // 0x800177CC: addu        $t2, $sp, $v0
    ctx->r10 = ADD32(ctx->r29, ctx->r2);
    // 0x800177D0: addu        $t8, $sp, $v0
    ctx->r24 = ADD32(ctx->r29, ctx->r2);
    // 0x800177D4: addu        $t9, $sp, $v0
    ctx->r25 = ADD32(ctx->r29, ctx->r2);
    // 0x800177D8: lw          $v1, 0x188($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X188);
    // 0x800177DC: lw          $a3, 0xE0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XE0);
    // 0x800177E0: lw          $a2, 0xF0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XF0);
    // 0x800177E4: lw          $a1, 0x100($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X100);
    // 0x800177E8: addiu       $t2, $s1, 0x2
    ctx->r10 = ADD32(ctx->r17, 0X2);
    // 0x800177EC: addiu       $t4, $s1, 0x1
    ctx->r12 = ADD32(ctx->r17, 0X1);
    // 0x800177F0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800177F4: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800177F8: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800177FC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80017800: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80017804: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80017808: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8001780C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80017810: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80017814: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80017818: jal         0x8006F64C
    // 0x8001781C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_7;
    // 0x8001781C: sw          $t0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r8;
    after_7:
    // 0x80017820: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x80017824: nop

L_80017828:
    // 0x80017828: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x8001782C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80017830: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80017834: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x80017838: bne         $fp, $t5, L_80017784
    if (ctx->r30 != ctx->r13) {
        // 0x8001783C: addiu       $s1, $s1, 0x3
        ctx->r17 = ADD32(ctx->r17, 0X3);
            goto L_80017784;
    }
    // 0x8001783C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
L_80017840:
    // 0x80017840: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x80017844: lw          $t7, 0x170($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X170);
    // 0x80017848: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8001784C: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x80017850: or          $t6, $t4, $s2
    ctx->r14 = ctx->r12 | ctx->r18;
    // 0x80017854: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x80017858: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8001785C: sw          $t6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r14;
    // 0x80017860: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x80017864: bne         $t2, $t3, L_800174B8
    if (ctx->r10 != ctx->r11) {
        // 0x80017868: sw          $t2, 0x170($sp)
        MEM_W(0X170, ctx->r29) = ctx->r10;
            goto L_800174B8;
    }
    // 0x80017868: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x8001786C: lw          $a2, 0x180($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X180);
    // 0x80017870: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80017874:
    // 0x80017874: andi        $t5, $a3, 0x1
    ctx->r13 = ctx->r7 & 0X1;
    // 0x80017878: beq         $t5, $zero, L_80017888
    if (ctx->r13 == 0) {
        // 0x8001787C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_80017888;
    }
    // 0x8001787C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80017880: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80017884: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80017888:
    // 0x80017888: andi        $t8, $a3, 0x2
    ctx->r24 = ctx->r7 & 0X2;
    // 0x8001788C: beq         $t8, $zero, L_800178A4
    if (ctx->r24 == 0) {
        // 0x80017890: andi        $t3, $a3, 0x4
        ctx->r11 = ctx->r7 & 0X4;
            goto L_800178A4;
    }
    // 0x80017890: andi        $t3, $a3, 0x4
    ctx->r11 = ctx->r7 & 0X4;
    // 0x80017894: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80017898: nop

    // 0x8001789C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800178A0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800178A4:
    // 0x800178A4: beq         $t3, $zero, L_800178BC
    if (ctx->r11 == 0) {
        // 0x800178A8: andi        $t4, $a3, 0x8
        ctx->r12 = ctx->r7 & 0X8;
            goto L_800178BC;
    }
    // 0x800178A8: andi        $t4, $a3, 0x8
    ctx->r12 = ctx->r7 & 0X8;
    // 0x800178AC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800178B0: nop

    // 0x800178B4: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x800178B8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_800178BC:
    // 0x800178BC: beq         $t4, $zero, L_800178D4
    if (ctx->r12 == 0) {
        // 0x800178C0: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800178D4;
    }
    // 0x800178C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800178C4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800178C8: nop

    // 0x800178CC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800178D0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800178D4:
    // 0x800178D4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800178D8: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800178DC: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800178E0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800178E4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800178E8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800178EC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800178F0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800178F4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800178F8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800178FC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80017900: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80017904: jr          $ra
    // 0x80017908: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    return;
    // 0x80017908: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void viewport_scissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067A44: jal         0x8007A520
    // 0x80067A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80067A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80067A4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80067A50: lw          $v1, 0xCE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE0);
    // 0x80067A54: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80067A58: beq         $v1, $zero, L_80067C98
    if (ctx->r3 == 0) {
        // 0x80067A5C: andi        $t7, $v0, 0xFFFF
        ctx->r15 = ctx->r2 & 0XFFFF;
            goto L_80067C98;
    }
    // 0x80067A5C: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80067A60: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80067A64: bne         $v1, $t2, L_80067A70
    if (ctx->r3 != ctx->r10) {
        // 0x80067A68: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80067A70;
    }
    // 0x80067A68: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80067A6C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80067A70:
    // 0x80067A70: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067A74: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80067A78: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80067A7C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80067A80: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80067A84: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80067A88: beq         $v1, $t3, L_80067AAC
    if (ctx->r3 == ctx->r11) {
        // 0x80067A8C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80067AAC;
    }
    // 0x80067A8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80067A90: beq         $v1, $t2, L_80067ADC
    if (ctx->r3 == ctx->r10) {
        // 0x80067A94: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80067ADC;
    }
    // 0x80067A94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067A98: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80067A9C: beq         $v1, $t4, L_80067B08
    if (ctx->r3 == ctx->r12) {
        // 0x80067AA0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80067B08;
    }
    // 0x80067AA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80067AA4: b           L_80067BA4
    // 0x80067AA8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067BA4;
    // 0x80067AA8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067AAC:
    // 0x80067AAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80067AB0: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x80067AB4: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067AB8: bne         $t7, $zero, L_80067AD0
    if (ctx->r15 != 0) {
        // 0x80067ABC: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067AD0;
    }
    // 0x80067ABC: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067AC0: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067AC4: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067AC8: b           L_80067BA0
    // 0x80067ACC: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067BA0;
    // 0x80067ACC: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067AD0:
    // 0x80067AD0: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067AD4: b           L_80067BA0
    // 0x80067AD8: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067BA0;
    // 0x80067AD8: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067ADC:
    // 0x80067ADC: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x80067AE0: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067AE4: bne         $t7, $zero, L_80067AFC
    if (ctx->r15 != 0) {
        // 0x80067AE8: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80067AFC;
    }
    // 0x80067AE8: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067AEC: sra         $t8, $a1, 1
    ctx->r24 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067AF0: sra         $t9, $a1, 8
    ctx->r25 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067AF4: b           L_80067BA0
    // 0x80067AF8: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
        goto L_80067BA0;
    // 0x80067AF8: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
L_80067AFC:
    // 0x80067AFC: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
    // 0x80067B00: b           L_80067BA0
    // 0x80067B04: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
        goto L_80067BA0;
    // 0x80067B04: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067B08:
    // 0x80067B08: lw          $v0, 0xCE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XCE4);
    // 0x80067B0C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067B10: beq         $v0, $zero, L_80067B38
    if (ctx->r2 == 0) {
        // 0x80067B14: sra         $t8, $a1, 8
        ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067B38;
    }
    // 0x80067B14: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067B18: beq         $v0, $t3, L_80067B4C
    if (ctx->r2 == ctx->r11) {
        // 0x80067B1C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067B4C;
    }
    // 0x80067B1C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067B20: beq         $v0, $t2, L_80067B68
    if (ctx->r2 == ctx->r10) {
        // 0x80067B24: sra         $t6, $a0, 1
        ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80067B68;
    }
    // 0x80067B24: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067B28: beq         $v0, $t4, L_80067B84
    if (ctx->r2 == ctx->r12) {
        // 0x80067B2C: sra         $v1, $a1, 8
        ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
            goto L_80067B84;
    }
    // 0x80067B2C: sra         $v1, $a1, 8
    ctx->r3 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067B30: b           L_80067BA4
    // 0x80067B34: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_80067BA4;
    // 0x80067B34: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067B38:
    // 0x80067B38: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067B3C: sra         $t6, $a0, 7
    ctx->r14 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067B40: subu        $a3, $t9, $t6
    ctx->r7 = SUB32(ctx->r25, ctx->r14);
    // 0x80067B44: b           L_80067BA0
    // 0x80067B48: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
        goto L_80067BA0;
    // 0x80067B48: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
L_80067B4C:
    // 0x80067B4C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067B50: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067B54: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067B58: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x80067B5C: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
    // 0x80067B60: b           L_80067BA0
    // 0x80067B64: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
        goto L_80067BA0;
    // 0x80067B64: subu        $a3, $t8, $t9
    ctx->r7 = SUB32(ctx->r24, ctx->r25);
L_80067B68:
    // 0x80067B68: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067B6C: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067B70: sra         $t8, $a1, 8
    ctx->r24 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80067B74: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067B78: subu        $a2, $t7, $t8
    ctx->r6 = SUB32(ctx->r15, ctx->r24);
    // 0x80067B7C: b           L_80067BA0
    // 0x80067B80: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
        goto L_80067BA0;
    // 0x80067B80: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
L_80067B84:
    // 0x80067B84: sra         $v0, $a0, 7
    ctx->r2 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80067B88: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80067B8C: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80067B90: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80067B94: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80067B98: subu        $a3, $a0, $v0
    ctx->r7 = SUB32(ctx->r4, ctx->r2);
    // 0x80067B9C: subu        $a2, $a1, $v1
    ctx->r6 = SUB32(ctx->r5, ctx->r3);
L_80067BA0:
    // 0x80067BA0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80067BA4:
    // 0x80067BA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067BA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067BAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067BB0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80067BB4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067BB8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067BBC: nop

    // 0x80067BC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80067BC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067BC8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80067BCC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067BD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067BD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067BD8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067BDC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067BE0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80067BE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067BE8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80067BEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067BF0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067BF4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067BF8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067BFC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067C00: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067C04: nop

    // 0x80067C08: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067C0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067C10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067C14: nop

    // 0x80067C18: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067C1C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80067C20: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067C24: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067C28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067C2C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067C30: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067C34: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067C38: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067C3C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067C40: nop

    // 0x80067C44: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067C48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067C4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067C50: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067C54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067C58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067C5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067C60: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80067C64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067C68: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067C6C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80067C70: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067C74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067C78: nop

    // 0x80067C7C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067C80: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80067C84: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067C88: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80067C8C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80067C90: b           L_80067D2C
    // 0x80067C94: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
        goto L_80067D2C;
    // 0x80067C94: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80067C98:
    // 0x80067C98: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80067C9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067CA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067CA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067CA8: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80067CAC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067CB0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067CB4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80067CB8: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x80067CBC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067CC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067CC4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067CC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067CCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067CD0: nop

    // 0x80067CD4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067CD8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067CDC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067CE0: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80067CE4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067CE8: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80067CEC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80067CF0: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80067CF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067CF8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067CFC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067D00: nop

    // 0x80067D04: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067D08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067D0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067D10: nop

    // 0x80067D14: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067D18: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80067D1C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067D20: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067D24: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067D28: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80067D2C:
    // 0x80067D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067D34: jr          $ra
    // 0x80067D38: nop

    return;
    // 0x80067D38: nop

;}
RECOMP_FUNC void menu_credits_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B32C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009B330: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8009B334: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8009B338: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8009B33C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8009B340: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8009B344: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8009B348: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8009B34C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8009B350: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8009B354: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8009B358: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8009B35C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009B360: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8009B364: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8009B368: jal         0x8001E29C
    // 0x8009B36C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009B36C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x8009B370: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8009B374: jal         0x8001E29C
    // 0x8009B378: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8009B378: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_1:
    // 0x8009B37C: jal         0x800C73F0
    // 0x8009B380: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    bgload_tick(rdram, ctx);
        goto after_2;
    // 0x8009B380: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_2:
    // 0x8009B384: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009B388: lw          $t6, -0xB84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB84);
    // 0x8009B38C: nop

    // 0x8009B390: bne         $t6, $zero, L_8009B3B0
    if (ctx->r14 != 0) {
        // 0x8009B394: nop
    
            goto L_8009B3B0;
    }
    // 0x8009B394: nop

    // 0x8009B398: jal         0x800C0180
    // 0x8009B39C: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_3;
    // 0x8009B39C: nop

    after_3:
    // 0x8009B3A0: jal         0x800C01D8
    // 0x8009B3A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x8009B3A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8009B3A8: jal         0x800C0170
    // 0x8009B3AC: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_5;
    // 0x8009B3AC: nop

    after_5:
L_8009B3B0:
    // 0x8009B3B0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8009B3B4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8009B3B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B3BC: bne         $t7, $zero, L_8009B3F0
    if (ctx->r15 != 0) {
        // 0x8009B3C0: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_8009B3F0;
    }
    // 0x8009B3C0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009B3C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009B3C8: lw          $t8, 0x63D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63D8);
    // 0x8009B3CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009B3D0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8009B3D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009B3D8: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8009B3DC: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B3E0: jal         0x8009B1E4
    // 0x8009B3E4: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    credits_fade(rdram, ctx);
        goto after_6;
    // 0x8009B3E4: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    after_6:
    // 0x8009B3E8: b           L_8009B40C
    // 0x8009B3EC: nop

        goto L_8009B40C;
    // 0x8009B3EC: nop

L_8009B3F0:
    // 0x8009B3F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009B3F4: lw          $t1, 0x63D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63D8);
    // 0x8009B3F8: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8009B3FC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8009B400: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009B404: jal         0x8009B1E4
    // 0x8009B408: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    credits_fade(rdram, ctx);
        goto after_7;
    // 0x8009B408: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    after_7:
L_8009B40C:
    // 0x8009B40C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B410: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
    // 0x8009B414: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009B418: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B41C: blez        $v0, L_8009B524
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009B420: addiu       $v1, $v1, -0xBA0
        ctx->r3 = ADD32(ctx->r3, -0XBA0);
            goto L_8009B524;
    }
    // 0x8009B420: addiu       $v1, $v1, -0xBA0
    ctx->r3 = ADD32(ctx->r3, -0XBA0);
    // 0x8009B424: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009B428: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8009B42C: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8009B430: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x8009B434: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8009B438: bne         $at, $zero, L_8009B448
    if (ctx->r1 != 0) {
        // 0x8009B43C: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8009B448;
    }
    // 0x8009B43C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009B440: b           L_8009B450
    // 0x8009B444: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_8009B450;
    // 0x8009B444: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8009B448:
    // 0x8009B448: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009B44C: subu        $s4, $t7, $v0
    ctx->r20 = SUB32(ctx->r15, ctx->r2);
L_8009B450:
    // 0x8009B450: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8009B454: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x8009B458: lw          $s5, 0x0($v1)
    ctx->r21 = MEM_W(ctx->r3, 0X0);
    // 0x8009B45C: jal         0x8007A520
    // 0x8009B460: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    fb_size(rdram, ctx);
        goto after_8;
    // 0x8009B460: addiu       $s4, $t8, 0x48
    ctx->r20 = ADD32(ctx->r24, 0X48);
    after_8:
    // 0x8009B464: sra         $s2, $v0, 17
    ctx->r18 = S32(SIGNED(ctx->r2) >> 17);
    // 0x8009B468: andi        $t9, $s2, 0x7FFF
    ctx->r25 = ctx->r18 & 0X7FFF;
    // 0x8009B46C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009B470: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8009B474: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8009B478: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x8009B47C: addiu       $s6, $s6, 0xB18
    ctx->r22 = ADD32(ctx->r22, 0XB18);
    // 0x8009B480: addiu       $s7, $s7, 0x63A0
    ctx->r23 = ADD32(ctx->r23, 0X63A0);
    // 0x8009B484: addiu       $s0, $s0, 0xAF0
    ctx->r16 = ADD32(ctx->r16, 0XAF0);
L_8009B488:
    // 0x8009B488: sll         $s1, $s5, 16
    ctx->r17 = S32(ctx->r21 << 16);
    // 0x8009B48C: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8009B490: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x8009B494: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B498: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8009B49C: jal         0x80070830
    // 0x8009B4A0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    sins_s16(rdram, ctx);
        goto after_9;
    // 0x8009B4A0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    after_9:
    // 0x8009B4A4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8009B4A8: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009B4AC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8009B4B0: jal         0x8007082C
    // 0x8009B4B4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    coss_s16(rdram, ctx);
        goto after_10;
    // 0x8009B4B4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_10:
    // 0x8009B4B8: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009B4BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8009B4C0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009B4C4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009B4C8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009B4CC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009B4D0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009B4D4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009B4D8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009B4DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009B4E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009B4E4: mflo        $a2
    ctx->r6 = lo;
    // 0x8009B4E8: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8009B4EC: addiu       $a2, $t3, 0x8C
    ctx->r6 = ADD32(ctx->r11, 0X8C);
    // 0x8009B4F0: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009B4F4: mflo        $t5
    ctx->r13 = lo;
    // 0x8009B4F8: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009B4FC: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    // 0x8009B500: jal         0x80078AB8
    // 0x8009B504: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x8009B504: addiu       $a3, $a3, -0x14
    ctx->r7 = ADD32(ctx->r7, -0X14);
    after_11:
    // 0x8009B508: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8009B50C: bne         $s0, $s6, L_8009B488
    if (ctx->r16 != ctx->r22) {
        // 0x8009B510: addiu       $s5, $s5, 0x1999
        ctx->r21 = ADD32(ctx->r21, 0X1999);
            goto L_8009B488;
    }
    // 0x8009B510: addiu       $s5, $s5, 0x1999
    ctx->r21 = ADD32(ctx->r21, 0X1999);
    // 0x8009B514: jal         0x8007B3D0
    // 0x8009B518: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x8009B518: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_12:
    // 0x8009B51C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B520: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
L_8009B524:
    // 0x8009B524: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009B528: lw          $t2, 0x6BE0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6BE0);
    // 0x8009B52C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8009B530: beq         $t2, $zero, L_8009B554
    if (ctx->r10 == 0) {
        // 0x8009B534: nop
    
            goto L_8009B554;
    }
    // 0x8009B534: nop

    // 0x8009B538: jal         0x80081F4C
    // 0x8009B53C: nop

    postrace_render(rdram, ctx);
        goto after_13;
    // 0x8009B53C: nop

    after_13:
    // 0x8009B540: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009B544: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B548: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009B54C: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
    // 0x8009B550: sw          $t4, 0x6BE0($at)
    MEM_W(0X6BE0, ctx->r1) = ctx->r12;
L_8009B554:
    // 0x8009B554: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009B558: lw          $t3, 0x6BD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BD8);
    // 0x8009B55C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009B560: bne         $t3, $zero, L_8009BA24
    if (ctx->r11 != 0) {
        // 0x8009B564: nop
    
            goto L_8009BA24;
    }
    // 0x8009B564: nop

    // 0x8009B568: lw          $t5, 0x6BE0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BE0);
    // 0x8009B56C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009B570: bne         $t5, $zero, L_8009BA24
    if (ctx->r13 != 0) {
        // 0x8009B574: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8009BA24;
    }
    // 0x8009B574: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8009B578: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8009B57C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009B580: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009B584: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8009B588: addiu       $t0, $t0, 0x1938
    ctx->r8 = ADD32(ctx->r8, 0X1938);
    // 0x8009B58C: addiu       $fp, $fp, 0x17F4
    ctx->r30 = ADD32(ctx->r30, 0X17F4);
    // 0x8009B590: addiu       $s6, $s6, 0x6BC4
    ctx->r22 = ADD32(ctx->r22, 0X6BC4);
    // 0x8009B594: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009B598:
    // 0x8009B598: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009B59C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8009B5A0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8009B5A4: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009B5A8: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8009B5AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009B5B0: andi        $v0, $a0, 0xF000
    ctx->r2 = ctx->r4 & 0XF000;
    // 0x8009B5B4: xor         $a2, $a3, $v0
    ctx->r6 = ctx->r7 ^ ctx->r2;
    // 0x8009B5B8: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x8009B5BC: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8009B5C0: beq         $v0, $at, L_8009B608
    if (ctx->r2 == ctx->r1) {
        // 0x8009B5C4: sra         $a2, $t8, 24
        ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
            goto L_8009B608;
    }
    // 0x8009B5C4: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8009B5C8: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8009B5CC: beq         $v0, $at, L_8009B61C
    if (ctx->r2 == ctx->r1) {
        // 0x8009B5D0: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_8009B61C;
    }
    // 0x8009B5D0: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009B5D4: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009B5D8: beq         $v0, $at, L_8009B88C
    if (ctx->r2 == ctx->r1) {
        // 0x8009B5DC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8009B88C;
    }
    // 0x8009B5DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009B5E0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8009B5E4: beq         $v0, $at, L_8009B9EC
    if (ctx->r2 == ctx->r1) {
        // 0x8009B5E8: addiu       $t3, $a1, 0x1
        ctx->r11 = ADD32(ctx->r5, 0X1);
            goto L_8009B9EC;
    }
    // 0x8009B5E8: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8009B5EC: addiu       $at, $zero, 0x5000
    ctx->r1 = ADD32(0, 0X5000);
    // 0x8009B5F0: beq         $v0, $at, L_8009BA08
    if (ctx->r2 == ctx->r1) {
        // 0x8009B5F4: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_8009BA08;
    }
    // 0x8009B5F4: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8009B5F8: beq         $v0, $a3, L_8009B620
    if (ctx->r2 == ctx->r7) {
        // 0x8009B5FC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8009B620;
    }
    // 0x8009B5FC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009B600: b           L_8009BA10
    // 0x8009B604: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_8009BA10;
    // 0x8009B604: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009B608:
    // 0x8009B608: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x8009B60C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B610: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8009B614: b           L_8009BA0C
    // 0x8009B618: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
        goto L_8009BA0C;
    // 0x8009B618: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_8009B61C:
    // 0x8009B61C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_8009B620:
    // 0x8009B620: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009B624: and         $t2, $a0, $at
    ctx->r10 = ctx->r4 & ctx->r1;
    // 0x8009B628: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B62C: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8009B630: sw          $t2, 0x6BE8($at)
    MEM_W(0X6BE8, ctx->r1) = ctx->r10;
    // 0x8009B634: addu        $t5, $fp, $t3
    ctx->r13 = ADD32(ctx->r30, ctx->r11);
    // 0x8009B638: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009B63C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009B640: andi        $t6, $v0, 0xF000
    ctx->r14 = ctx->r2 & 0XF000;
    // 0x8009B644: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009B648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009B64C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8009B650: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x8009B654: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8009B658: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x8009B65C: bne         $t6, $zero, L_8009B688
    if (ctx->r14 != 0) {
        // 0x8009B660: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8009B688;
    }
    // 0x8009B660: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8009B664:
    // 0x8009B664: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x8009B668: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009B66C: addu        $t1, $fp, $t9
    ctx->r9 = ADD32(ctx->r30, ctx->r25);
    // 0x8009B670: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009B674: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8009B678: andi        $t2, $v0, 0xF000
    ctx->r10 = ctx->r2 & 0XF000;
    // 0x8009B67C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009B680: beq         $t2, $zero, L_8009B664
    if (ctx->r10 == 0) {
        // 0x8009B684: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8009B664;
    }
    // 0x8009B684: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_8009B688:
    // 0x8009B688: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8009B68C: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8009B690: subu        $v1, $a1, $s0
    ctx->r3 = SUB32(ctx->r5, ctx->r16);
    // 0x8009B694: bne         $t4, $zero, L_8009B6A4
    if (ctx->r12 != 0) {
        // 0x8009B698: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009B6A4;
    }
    // 0x8009B698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009B69C: b           L_8009B6A8
    // 0x8009B6A0: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
        goto L_8009B6A8;
    // 0x8009B6A0: addiu       $s2, $zero, 0x86
    ctx->r18 = ADD32(0, 0X86);
L_8009B6A4:
    // 0x8009B6A4: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_8009B6A8:
    // 0x8009B6A8: bne         $v1, $at, L_8009B6BC
    if (ctx->r3 != ctx->r1) {
        // 0x8009B6AC: addiu       $t6, $zero, 0x1E0
        ctx->r14 = ADD32(0, 0X1E0);
            goto L_8009B6BC;
    }
    // 0x8009B6AC: addiu       $t6, $zero, 0x1E0
    ctx->r14 = ADD32(0, 0X1E0);
    // 0x8009B6B0: addiu       $s2, $s2, -0xE
    ctx->r18 = ADD32(ctx->r18, -0XE);
    // 0x8009B6B4: b           L_8009B6E0
    // 0x8009B6B8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
        goto L_8009B6E0;
    // 0x8009B6B8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_8009B6BC:
    // 0x8009B6BC: beq         $a2, $zero, L_8009B6D8
    if (ctx->r6 == 0) {
        // 0x8009B6C0: sll         $t5, $v1, 4
        ctx->r13 = S32(ctx->r3 << 4);
            goto L_8009B6D8;
    }
    // 0x8009B6C0: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x8009B6C4: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8009B6C8: subu        $s2, $s2, $t3
    ctx->r18 = SUB32(ctx->r18, ctx->r11);
    // 0x8009B6CC: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x8009B6D0: b           L_8009B6E0
    // 0x8009B6D4: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
        goto L_8009B6E0;
    // 0x8009B6D4: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009B6D8:
    // 0x8009B6D8: subu        $s2, $s2, $t5
    ctx->r18 = SUB32(ctx->r18, ctx->r13);
    // 0x8009B6DC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_8009B6E0:
    // 0x8009B6E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B6E4: sh          $t6, 0x1B50($at)
    MEM_H(0X1B50, ctx->r1) = ctx->r14;
    // 0x8009B6E8: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009B6EC: bne         $v0, $at, L_8009B704
    if (ctx->r2 != ctx->r1) {
        // 0x8009B6F0: addiu       $t8, $zero, -0xA0
        ctx->r24 = ADD32(0, -0XA0);
            goto L_8009B704;
    }
    // 0x8009B6F0: addiu       $t8, $zero, -0xA0
    ctx->r24 = ADD32(0, -0XA0);
    // 0x8009B6F4: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8009B6F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B6FC: b           L_8009B70C
    // 0x8009B700: sh          $t7, 0x1B58($at)
    MEM_H(0X1B58, ctx->r1) = ctx->r15;
        goto L_8009B70C;
    // 0x8009B700: sh          $t7, 0x1B58($at)
    MEM_H(0X1B58, ctx->r1) = ctx->r15;
L_8009B704:
    // 0x8009B704: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B708: sh          $t8, 0x1B58($at)
    MEM_H(0X1B58, ctx->r1) = ctx->r24;
L_8009B70C:
    // 0x8009B70C: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009B710: beq         $at, $zero, L_8009B81C
    if (ctx->r1 == 0) {
        // 0x8009B714: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009B81C;
    }
    // 0x8009B714: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009B718: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009B71C: sll         $t9, $s4, 1
    ctx->r25 = S32(ctx->r20 << 1);
    // 0x8009B720: addu        $s1, $fp, $t9
    ctx->r17 = ADD32(ctx->r30, ctx->r25);
    // 0x8009B724: addiu       $s0, $s0, 0x1B50
    ctx->r16 = ADD32(ctx->r16, 0X1B50);
L_8009B728:
    // 0x8009B728: sh          $s2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r18;
    // 0x8009B72C: sh          $s2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r18;
    // 0x8009B730: beq         $a2, $zero, L_8009B7C0
    if (ctx->r6 == 0) {
        // 0x8009B734: sh          $s2, 0xA($s0)
        MEM_H(0XA, ctx->r16) = ctx->r18;
            goto L_8009B7C0;
    }
    // 0x8009B734: sh          $s2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r18;
    // 0x8009B738: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x8009B73C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8009B740: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x8009B744: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x8009B748: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x8009B74C: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
    // 0x8009B750: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8009B754: lb          $a0, 0x0($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X0);
    // 0x8009B758: sb          $a2, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r6;
    // 0x8009B75C: jal         0x8006BDDC
    // 0x8009B760: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    level_name(rdram, ctx);
        goto after_14;
    // 0x8009B760: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    after_14:
    // 0x8009B764: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009B768: addiu       $v1, $s2, 0xE
    ctx->r3 = ADD32(ctx->r18, 0XE);
    // 0x8009B76C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009B770: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009B774: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8009B778: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8009B77C: sh          $v1, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r3;
    // 0x8009B780: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8009B784: sh          $v1, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r3;
    // 0x8009B788: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x8009B78C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009B790: lw          $t7, 0x1A94($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A94);
    // 0x8009B794: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009B798: lb          $a2, 0x5B($sp)
    ctx->r6 = MEM_B(ctx->r29, 0X5B);
    // 0x8009B79C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009B7A0: addiu       $t9, $t9, 0x17F4
    ctx->r25 = ADD32(ctx->r25, 0X17F4);
    // 0x8009B7A4: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8009B7A8: addiu       $t0, $t0, 0x1938
    ctx->r8 = ADD32(ctx->r8, 0X1938);
    // 0x8009B7AC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8009B7B0: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8009B7B4: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8009B7B8: b           L_8009B808
    // 0x8009B7BC: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
        goto L_8009B808;
    // 0x8009B7BC: sw          $t7, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r15;
L_8009B7C0:
    // 0x8009B7C0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009B7C4: addiu       $t2, $t2, 0x17F4
    ctx->r10 = ADD32(ctx->r10, 0X17F4);
    // 0x8009B7C8: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x8009B7CC: andi        $t4, $s3, 0x1
    ctx->r12 = ctx->r19 & 0X1;
    // 0x8009B7D0: beq         $t4, $zero, L_8009B7E4
    if (ctx->r12 == 0) {
        // 0x8009B7D4: addu        $a0, $t1, $t2
        ctx->r4 = ADD32(ctx->r9, ctx->r10);
            goto L_8009B7E4;
    }
    // 0x8009B7D4: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x8009B7D8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009B7DC: sb          $t3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r11;
    // 0x8009B7E0: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
L_8009B7E4:
    // 0x8009B7E4: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8009B7E8: sb          $s5, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r21;
    // 0x8009B7EC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8009B7F0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8009B7F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009B7F8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8009B7FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009B800: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8009B804: sw          $t8, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r24;
L_8009B808:
    // 0x8009B808: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009B80C: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x8009B810: addu        $s2, $s2, $s7
    ctx->r18 = ADD32(ctx->r18, ctx->r23);
    // 0x8009B814: bne         $at, $zero, L_8009B728
    if (ctx->r1 != 0) {
        // 0x8009B818: addiu       $s7, $zero, 0x20
        ctx->r23 = ADD32(0, 0X20);
            goto L_8009B728;
    }
    // 0x8009B818: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8009B81C:
    // 0x8009B81C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B820: addiu       $a0, $a0, 0x1B50
    ctx->r4 = ADD32(ctx->r4, 0X1B50);
    // 0x8009B824: sll         $t9, $s3, 5
    ctx->r25 = S32(ctx->r19 << 5);
    // 0x8009B828: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x8009B82C: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x8009B830: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009B834: lw          $t2, 0x6BE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6BE8);
    // 0x8009B838: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009B83C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8009B840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B844: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009B848: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009B84C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009B850: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B854: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009B858: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009B85C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8009B860: jal         0x80081E54
    // 0x8009B864: nop

    postrace_offsets(rdram, ctx);
        goto after_15;
    // 0x8009B864: nop

    after_15:
    // 0x8009B868: jal         0x80081F4C
    // 0x8009B86C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_16;
    // 0x8009B86C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x8009B870: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009B874: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009B878: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B87C: sw          $t4, 0x6BE0($at)
    MEM_W(0X6BE0, ctx->r1) = ctx->r12;
    // 0x8009B880: addiu       $t0, $t0, 0x1938
    ctx->r8 = ADD32(ctx->r8, 0X1938);
    // 0x8009B884: b           L_8009BA0C
    // 0x8009B888: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BA0C;
    // 0x8009B888: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009B88C:
    // 0x8009B88C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8009B890: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x8009B894: and         $t3, $a0, $at
    ctx->r11 = ctx->r4 & ctx->r1;
    // 0x8009B898: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x8009B89C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B8A0: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8009B8A4: sw          $t3, 0x6BE8($at)
    MEM_W(0X6BE8, ctx->r1) = ctx->r11;
    // 0x8009B8A8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009B8AC: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
    // 0x8009B8B0: sw          $s0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r16;
    // 0x8009B8B4: andi        $t8, $v0, 0xF000
    ctx->r24 = ctx->r2 & 0XF000;
    // 0x8009B8B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009B8BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8009B8C0: bne         $t8, $zero, L_8009B8EC
    if (ctx->r24 != 0) {
        // 0x8009B8C4: sw          $t9, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r25;
            goto L_8009B8EC;
    }
    // 0x8009B8C4: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
L_8009B8C8:
    // 0x8009B8C8: addiu       $t1, $a1, 0x1
    ctx->r9 = ADD32(ctx->r5, 0X1);
    // 0x8009B8CC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8009B8D0: addu        $t4, $fp, $t2
    ctx->r12 = ADD32(ctx->r30, ctx->r10);
    // 0x8009B8D4: lh          $v0, 0x0($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X0);
    // 0x8009B8D8: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x8009B8DC: andi        $t3, $v0, 0xF000
    ctx->r11 = ctx->r2 & 0XF000;
    // 0x8009B8E0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8009B8E4: beq         $t3, $zero, L_8009B8C8
    if (ctx->r11 == 0) {
        // 0x8009B8E8: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8009B8C8;
    }
    // 0x8009B8E8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_8009B8EC:
    // 0x8009B8EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009B8F0: addiu       $v1, $v1, 0x1B50
    ctx->r3 = ADD32(ctx->r3, 0X1B50);
    // 0x8009B8F4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x8009B8F8: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x8009B8FC: bne         $v0, $at, L_8009B90C
    if (ctx->r2 != ctx->r1) {
        // 0x8009B900: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8009B90C;
    }
    // 0x8009B900: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8009B904: b           L_8009B914
    // 0x8009B908: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
        goto L_8009B914;
    // 0x8009B908: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
L_8009B90C:
    // 0x8009B90C: addiu       $t5, $zero, -0xA0
    ctx->r13 = ADD32(0, -0XA0);
    // 0x8009B910: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
L_8009B914:
    // 0x8009B914: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009B918: beq         $at, $zero, L_8009B96C
    if (ctx->r1 == 0) {
        // 0x8009B91C: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8009B96C;
    }
    // 0x8009B91C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8009B920: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8009B924: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8009B928: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    // 0x8009B92C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009B930: addiu       $t2, $t2, 0x1B50
    ctx->r10 = ADD32(ctx->r10, 0X1B50);
    // 0x8009B934: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8009B938: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x8009B93C: addu        $s1, $fp, $t6
    ctx->r17 = ADD32(ctx->r30, ctx->r14);
    // 0x8009B940: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_8009B944:
    // 0x8009B944: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009B948: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8009B94C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009B950: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8009B954: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8009B958: slt         $at, $s4, $a1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009B95C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8009B960: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009B964: bne         $at, $zero, L_8009B944
    if (ctx->r1 != 0) {
        // 0x8009B968: sw          $t6, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r14;
            goto L_8009B944;
    }
    // 0x8009B968: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
L_8009B96C:
    // 0x8009B96C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x8009B970: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009B974: lw          $t2, 0x6BE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6BE8);
    // 0x8009B978: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x8009B97C: sll         $t8, $s4, 5
    ctx->r24 = S32(ctx->r20 << 5);
    // 0x8009B980: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009B984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B988: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8009B98C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009B990: sw          $zero, 0x1B84($at)
    MEM_W(0X1B84, ctx->r1) = 0;
    // 0x8009B994: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009B998: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009B99C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009B9A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B9A4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B9A8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009B9AC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8009B9B0: addiu       $a0, $a0, 0x1B50
    ctx->r4 = ADD32(ctx->r4, 0X1B50);
    // 0x8009B9B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009B9B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009B9BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8009B9C0: jal         0x80081E54
    // 0x8009B9C4: nop

    postrace_offsets(rdram, ctx);
        goto after_17;
    // 0x8009B9C4: nop

    after_17:
    // 0x8009B9C8: jal         0x80081F4C
    // 0x8009B9CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    postrace_render(rdram, ctx);
        goto after_18;
    // 0x8009B9CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x8009B9D0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009B9D4: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8009B9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B9DC: sw          $t4, 0x6BE0($at)
    MEM_W(0X6BE0, ctx->r1) = ctx->r12;
    // 0x8009B9E0: addiu       $t0, $t0, 0x1938
    ctx->r8 = ADD32(ctx->r8, 0X1938);
    // 0x8009B9E4: b           L_8009BA0C
    // 0x8009B9E8: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
        goto L_8009BA0C;
    // 0x8009B9E8: addiu       $a3, $zero, 0x6000
    ctx->r7 = ADD32(0, 0X6000);
L_8009B9EC:
    // 0x8009B9EC: sw          $t3, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r11;
    // 0x8009B9F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009B9F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B9F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009B9FC: sw          $t5, 0x6BD8($at)
    MEM_W(0X6BD8, ctx->r1) = ctx->r13;
    // 0x8009BA00: b           L_8009BA0C
    // 0x8009BA04: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
        goto L_8009BA0C;
    // 0x8009BA04: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_8009BA08:
    // 0x8009BA08: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
L_8009BA0C:
    // 0x8009BA0C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8009BA10:
    // 0x8009BA10: nop

    // 0x8009BA14: beq         $t8, $zero, L_8009B598
    if (ctx->r24 == 0) {
        // 0x8009BA18: nop
    
            goto L_8009B598;
    }
    // 0x8009BA18: nop

    // 0x8009BA1C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA20: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
L_8009BA24:
    // 0x8009BA24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009BA28: lw          $t9, 0x63C4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63C4);
    // 0x8009BA2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8009BA30: bne         $t9, $zero, L_8009BA64
    if (ctx->r25 != 0) {
        // 0x8009BA34: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009BA64;
    }
    // 0x8009BA34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009BA38: lw          $t1, -0xB84($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB84);
    // 0x8009BA3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009BA40: bne         $t1, $zero, L_8009BA64
    if (ctx->r9 != 0) {
        // 0x8009BA44: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8009BA64;
    }
    // 0x8009BA44: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_8009BA48:
    // 0x8009BA48: jal         0x8006A554
    // 0x8009BA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_pressed(rdram, ctx);
        goto after_19;
    // 0x8009BA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8009BA50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009BA54: bne         $s0, $s1, L_8009BA48
    if (ctx->r16 != ctx->r17) {
        // 0x8009BA58: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8009BA48;
    }
    // 0x8009BA58: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8009BA5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009BA60: addiu       $a2, $a2, 0x63D8
    ctx->r6 = ADD32(ctx->r6, 0X63D8);
L_8009BA64:
    // 0x8009BA64: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009BA68: addiu       $s0, $s0, 0x63E0
    ctx->r16 = ADD32(ctx->r16, 0X63E0);
    // 0x8009BA6C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009BA70: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8009BA74: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8009BA78: beq         $at, $zero, L_8009BC04
    if (ctx->r1 == 0) {
        // 0x8009BA7C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8009BC04;
    }
    // 0x8009BA7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8009BA80: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009BA84: addu        $at, $at, $t2
    gpr jr_addend_8009BA90 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009BA88: lw          $t2, -0x7A8C($at)
    ctx->r10 = ADD32(ctx->r1, -0X7A8C);
    // 0x8009BA8C: nop

    // 0x8009BA90: jr          $t2
    // 0x8009BA94: nop

    switch (jr_addend_8009BA90 >> 2) {
        case 0: goto L_8009BA98; break;
        case 1: goto L_8009BAD8; break;
        case 2: goto L_8009BB08; break;
        case 3: goto L_8009BB48; break;
        case 4: goto L_8009BB9C; break;
        default: switch_error(__func__, 0x8009BA90, 0x800E8574);
    }
    // 0x8009BA94: nop

L_8009BA98:
    // 0x8009BA98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BA9C: addiu       $v1, $v1, 0x6BCC
    ctx->r3 = ADD32(ctx->r3, 0X6BCC);
    // 0x8009BAA0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8009BAA4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8009BAA8: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8009BAAC: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8009BAB0: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009BAB4: lb          $a1, 0x2($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2);
    // 0x8009BAB8: jal         0x800C7458
    // 0x8009BABC: nop

    bgload_start(rdram, ctx);
        goto after_20;
    // 0x8009BABC: nop

    after_20:
    // 0x8009BAC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009BAC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009BAC8: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8009BACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BAD0: b           L_8009BC04
    // 0x8009BAD4: sw          $t7, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r15;
        goto L_8009BC04;
    // 0x8009BAD4: sw          $t7, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = ctx->r15;
L_8009BAD8:
    // 0x8009BAD8: jal         0x800C73E0
    // 0x8009BADC: nop

    bgload_active(rdram, ctx);
        goto after_21;
    // 0x8009BADC: nop

    after_21:
    // 0x8009BAE0: bne         $v0, $zero, L_8009BC04
    if (ctx->r2 != 0) {
        // 0x8009BAE4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009BC04;
    }
    // 0x8009BAE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BAE8: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8009BAEC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009BAF0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8009BAF4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009BAF8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009BAFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BB00: b           L_8009BC04
    // 0x8009BB04: sw          $zero, 0x6BD8($at)
    MEM_W(0X6BD8, ctx->r1) = 0;
        goto L_8009BC04;
    // 0x8009BB04: sw          $zero, 0x6BD8($at)
    MEM_W(0X6BD8, ctx->r1) = 0;
L_8009BB08:
    // 0x8009BB08: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BB0C: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8009BB10: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8009BB14: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009BB18: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8009BB1C: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8009BB20: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x8009BB24: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8009BB28: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8009BB2C: bgtz        $t4, L_8009BC04
    if (SIGNED(ctx->r12) > 0) {
        // 0x8009BB30: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_8009BC04;
    }
    // 0x8009BB30: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8009BB34: addiu       $t7, $t4, 0x258
    ctx->r15 = ADD32(ctx->r12, 0X258);
    // 0x8009BB38: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009BB3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009BB40: b           L_8009BC04
    // 0x8009BB44: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_8009BC04;
    // 0x8009BB44: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8009BB48:
    // 0x8009BB48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BB4C: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8009BB50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009BB54: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x8009BB58: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009BB5C: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8009BB60: blez        $v0, L_8009BB7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009BB64: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8009BB7C;
    }
    // 0x8009BB64: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8009BB68: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x8009BB6C: nop

    // 0x8009BB70: subu        $t3, $v0, $t4
    ctx->r11 = SUB32(ctx->r2, ctx->r12);
    // 0x8009BB74: b           L_8009BB80
    // 0x8009BB78: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8009BB80;
    // 0x8009BB78: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8009BB7C:
    // 0x8009BB7C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009BB80:
    // 0x8009BB80: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009BB84: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8009BB88: bgtz        $t5, L_8009BC08
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009BB8C: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009BC08;
    }
    // 0x8009BB8C: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009BB90: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009BB94: b           L_8009BC04
    // 0x8009BB98: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_8009BC04;
    // 0x8009BB98: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_8009BB9C:
    // 0x8009BB9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BBA0: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8009BBA4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009BBA8: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8009BBAC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8009BBB0: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8009BBB4: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8009BBB8: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8009BBBC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009BBC0: bgtz        $t9, L_8009BC04
    if (SIGNED(ctx->r25) > 0) {
        // 0x8009BBC4: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_8009BC04;
    }
    // 0x8009BBC4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8009BBC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009BBCC: addiu       $v1, $v1, 0x6BCC
    ctx->r3 = ADD32(ctx->r3, 0X6BCC);
    // 0x8009BBD0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8009BBD4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009BBD8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8009BBDC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8009BBE0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009BBE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009BBE8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8009BBEC: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8009BBF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009BBF4: bgez        $t2, L_8009BC08
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009BBF8: andi        $t4, $s2, 0x9000
        ctx->r12 = ctx->r18 & 0X9000;
            goto L_8009BC08;
    }
    // 0x8009BBF8: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
    // 0x8009BBFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8009BC00: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_8009BC04:
    // 0x8009BC04: andi        $t4, $s2, 0x9000
    ctx->r12 = ctx->r18 & 0X9000;
L_8009BC08:
    // 0x8009BC08: bne         $t4, $zero, L_8009BC24
    if (ctx->r12 != 0) {
        // 0x8009BC0C: andi        $t3, $s2, 0x4000
        ctx->r11 = ctx->r18 & 0X4000;
            goto L_8009BC24;
    }
    // 0x8009BC0C: andi        $t3, $s2, 0x4000
    ctx->r11 = ctx->r18 & 0X4000;
    // 0x8009BC10: bne         $t3, $zero, L_8009BC28
    if (ctx->r11 != 0) {
        // 0x8009BC14: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009BC28;
    }
    // 0x8009BC14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009BC18: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8009BC1C: nop

    // 0x8009BC20: beq         $t5, $zero, L_8009BC50
    if (ctx->r13 == 0) {
        // 0x8009BC24: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8009BC50;
    }
L_8009BC24:
    // 0x8009BC24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8009BC28:
    // 0x8009BC28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC2C: jal         0x800C0180
    // 0x8009BC30: sw          $t6, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r14;
    disable_new_screen_transitions(rdram, ctx);
        goto after_22;
    // 0x8009BC30: sw          $t6, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r14;
    after_22:
    // 0x8009BC34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009BC38: jal         0x800C01D8
    // 0x8009BC3C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_23;
    // 0x8009BC3C: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_23:
    // 0x8009BC40: jal         0x800C0170
    // 0x8009BC44: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_24;
    // 0x8009BC44: nop

    after_24:
    // 0x8009BC48: jal         0x80000C98
    // 0x8009BC4C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_25;
    // 0x8009BC4C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_25:
L_8009BC50:
    // 0x8009BC50: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009BC54: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009BC58: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x8009BC5C: blez        $v0, L_8009BCB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009BC60: addu        $t8, $v0, $t7
        ctx->r24 = ADD32(ctx->r2, ctx->r15);
            goto L_8009BCB4;
    }
    // 0x8009BC60: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009BC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009BC68: jal         0x800C73E0
    // 0x8009BC6C: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
    bgload_active(rdram, ctx);
        goto after_26;
    // 0x8009BC6C: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
    after_26:
    // 0x8009BC70: bne         $v0, $zero, L_8009BCB4
    if (ctx->r2 != 0) {
        // 0x8009BC74: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8009BCB4;
    }
    // 0x8009BC74: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009BC78: lw          $t9, -0xB84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB84);
    // 0x8009BC7C: nop

    // 0x8009BC80: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x8009BC84: bne         $at, $zero, L_8009BCB8
    if (ctx->r1 != 0) {
        // 0x8009BC88: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8009BCB8;
    }
    // 0x8009BC88: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8009BC8C: jal         0x80000B28
    // 0x8009BC90: nop

    music_change_on(rdram, ctx);
        goto after_27;
    // 0x8009BC90: nop

    after_27:
    // 0x8009BC94: jal         0x8009BCF0
    // 0x8009BC98: nop

    credits_free(rdram, ctx);
        goto after_28;
    // 0x8009BC98: nop

    after_28:
    // 0x8009BC9C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8009BCA0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8009BCA4: jal         0x8006E2E8
    // 0x8009BCA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_29;
    // 0x8009BCA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x8009BCAC: jal         0x800813D0
    // 0x8009BCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_30;
    // 0x8009BCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_30:
L_8009BCB4:
    // 0x8009BCB4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8009BCB8:
    // 0x8009BCB8: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8009BCBC: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009BCC0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009BCC4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8009BCC8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8009BCCC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8009BCD0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8009BCD4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8009BCD8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8009BCDC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8009BCE0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8009BCE4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8009BCE8: jr          $ra
    // 0x8009BCEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009BCEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void menu_character_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008BD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BD2C: jal         0x8008B20C
    // 0x8008BD30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    charselect_render_text(rdram, ctx);
        goto after_0;
    // 0x8008BD30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008BD34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008BD38: jal         0x8008C168
    // 0x8008BD3C: nop

    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008BD3C: nop

    after_1:
    // 0x8008BD40: jal         0x8008E4EC
    // 0x8008BD44: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008BD44: nop

    after_2:
    extern void dkr_netplay_character_select_lock(uint8_t*, recomp_context*); dkr_netplay_character_select_lock(rdram, ctx); { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 1U, dkr_character_menu_fields); }
    // 0x8008BD48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008BD4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BD50: addiu       $a0, $a0, 0x63E0
    ctx->r4 = ADD32(ctx->r4, 0X63E0);
    // 0x8008BD54: addiu       $v0, $v0, 0x63DC
    ctx->r2 = ADD32(ctx->r2, 0X63DC);
    // 0x8008BD58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008BD5C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8008BD60:
    // 0x8008BD60: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008BD64: nop

    // 0x8008BD68: bne         $t2, $t6, L_8008BD74
    if (ctx->r10 != ctx->r14) {
        // 0x8008BD6C: nop
    
            goto L_8008BD74;
    }
    // 0x8008BD6C: nop

    // 0x8008BD70: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8008BD74:
    // 0x8008BD74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BD78: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8008BD7C: bne         $at, $zero, L_8008BD60
    if (ctx->r1 != 0) {
        // 0x8008BD80: nop
    
            goto L_8008BD60;
    }
    // 0x8008BD80: nop

    // 0x8008BD84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008BD88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008BD8C: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x8008BD90: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8008BD94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008BD98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008BD9C: bne         $v0, $zero, L_8008BE0C
    if (ctx->r2 != 0) {
        // 0x8008BDA0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008BE0C;
    }
    // 0x8008BDA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BDA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008BDA8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008BDAC: lb          $t4, 0x63D7($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X63D7);
    // 0x8008BDB0: lb          $t9, 0x63D6($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X63D6);
    // 0x8008BDB4: lb          $t7, 0x63D4($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X63D4);
    // 0x8008BDB8: lb          $t8, 0x63D5($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X63D5);
    // 0x8008BDBC: sb          $t4, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r12;
    // 0x8008BDC0: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    // 0x8008BDC4: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x8008BDC8: jal         0x8008B358
    // 0x8008BDCC: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    charselect_new_player(rdram, ctx);
        goto after_3;
    // 0x8008BDCC: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    after_3:
    // 0x8008BDD0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008BDD4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008BDD8: lw          $t6, -0xB80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB80);
    // 0x8008BDDC: lw          $t5, -0xB44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB44);
    // 0x8008BDE0: nop

    // 0x8008BDE4: bne         $t5, $t6, L_8008BDFC
    if (ctx->r13 != ctx->r14) {
        // 0x8008BDE8: nop
    
            goto L_8008BDFC;
    }
    // 0x8008BDE8: nop

    // 0x8008BDEC: jal         0x8008B4C8
    // 0x8008BDF0: nop

    charselect_pick(rdram, ctx);
        goto after_4;
    // 0x8008BDF0: nop

    after_4:
    // 0x8008BDF4: b           L_8008BFD8
    // 0x8008BDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BFD8;
    // 0x8008BDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BDFC:
    // 0x8008BDFC: jal         0x8008B758
    // 0x8008BE00: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    charselect_input(rdram, ctx);
        goto after_5;
    // 0x8008BE00: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8008BE04: b           L_8008BFD8
    // 0x8008BE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BFD8;
    // 0x8008BE08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BE0C:
    // 0x8008BE0C: blez        $v0, L_8008BF90
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008BE10: nop
    
            goto L_8008BF90;
    }
    // 0x8008BE10: nop

    // 0x8008BE14: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8008BE18: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008BE1C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8008BE20: slti        $at, $t8, 0x1F
    ctx->r1 = SIGNED(ctx->r24) < 0X1F ? 1 : 0;
    // 0x8008BE24: bne         $at, $zero, L_8008BFD4
    if (ctx->r1 != 0) {
        // 0x8008BE28: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008BFD4;
    }
    // 0x8008BE28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008BE2C: lw          $t4, -0x30($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X30);
    // 0x8008BE30: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008BE34: bne         $t4, $zero, L_8008BE54
    if (ctx->r12 != 0) {
        // 0x8008BE38: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008BE54;
    }
    // 0x8008BE38: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008BE3C: lw          $t5, -0x268($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X268);
    // 0x8008BE40: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x8008BE44: sll         $t6, $t5, 7
    ctx->r14 = S32(ctx->r13 << 7);
    // 0x8008BE48: bgez        $t6, L_8008BE54
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008BE4C: nop
    
            goto L_8008BE54;
    }
    // 0x8008BE4C: nop

    // 0x8008BE50: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
L_8008BE54:
    // 0x8008BE54: jal         0x8008C128
    // 0x8008BE58: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_free(rdram, ctx);
        goto after_6;
    // 0x8008BE58: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_6:
    // 0x8008BE5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008BE60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008BE64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008BE68: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008BE6C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008BE70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008BE74: addiu       $a1, $a1, 0x63F0
    ctx->r5 = ADD32(ctx->r5, 0X63F0);
    // 0x8008BE78: addiu       $a2, $a2, 0x63CC
    ctx->r6 = ADD32(ctx->r6, 0X63CC);
    // 0x8008BE7C: addiu       $a3, $a3, 0x63E8
    ctx->r7 = ADD32(ctx->r7, 0X63E8);
    // 0x8008BE80: addiu       $v1, $v1, 0x63D4
    ctx->r3 = ADD32(ctx->r3, 0X63D4);
    // 0x8008BE84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008BE88: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8008BE8C: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
L_8008BE90:
    // 0x8008BE90: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8008BE94: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x8008BE98: beq         $t7, $zero, L_8008BEC8
    if (ctx->r15 == 0) {
        // 0x8008BE9C: nop
    
            goto L_8008BEC8;
    }
    // 0x8008BE9C: nop

    // 0x8008BEA0: lb          $t4, 0x0($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X0);
    // 0x8008BEA4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008BEA8: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BEAC: addu        $t9, $a1, $a0
    ctx->r25 = ADD32(ctx->r5, ctx->r4);
    // 0x8008BEB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008BEB4: mflo        $t5
    ctx->r13 = lo;
    // 0x8008BEB8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8008BEBC: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x8008BEC0: nop

    // 0x8008BEC4: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
L_8008BEC8:
    // 0x8008BEC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BECC: bne         $v0, $t1, L_8008BE90
    if (ctx->r2 != ctx->r9) {
        // 0x8008BED0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008BE90;
    }
    // 0x8008BED0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008BED4: jal         0x8008BB3C
    // 0x8008BED8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    charselect_assign_ai(rdram, ctx);
        goto after_7;
    // 0x8008BED8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_7:
    // 0x8008BEDC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BEE0: jal         0x8006A458
    // 0x8008BEE4: addiu       $a0, $a0, 0x63D4
    ctx->r4 = ADD32(ctx->r4, 0X63D4);
    charselect_assign_players(rdram, ctx);
        goto after_8;
    // 0x8008BEE4: addiu       $a0, $a0, 0x63D4
    ctx->r4 = ADD32(ctx->r4, 0X63D4);
    after_8:
    // 0x8008BEE8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008BEEC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008BEF0: lw          $t4, -0xB44($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB44);
    // 0x8008BEF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008BEF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BEFC: sw          $t2, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = ctx->r10;
    // 0x8008BF00: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008BF04: bne         $at, $zero, L_8008BF68
    if (ctx->r1 != 0) {
        // 0x8008BF08: nop
    
            goto L_8008BF68;
    }
    // 0x8008BF08: nop

    // 0x8008BF0C: jal         0x80000B18
    // 0x8008BF10: nop

    music_change_off(rdram, ctx);
        goto after_9;
    // 0x8008BF10: nop

    after_9:
    // 0x8008BF14: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8008BF18: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008BF1C: jal         0x8006E2E8
    // 0x8008BF20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_10;
    // 0x8008BF20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8008BF24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008BF28: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x8008BF2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008BF30: bne         $t2, $t8, L_8008BF58
    if (ctx->r10 != ctx->r24) {
        // 0x8008BF34: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8008BF58;
    }
    // 0x8008BF34: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008BF38: lw          $t5, -0xB68($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XB68);
    // 0x8008BF3C: nop

    // 0x8008BF40: bne         $t5, $zero, L_8008BF58
    if (ctx->r13 != 0) {
        // 0x8008BF44: nop
    
            goto L_8008BF58;
    }
    // 0x8008BF44: nop

    // 0x8008BF48: jal         0x800813D0
    // 0x8008BF4C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008BF4C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_11:
    // 0x8008BF50: b           L_8008BFD8
    // 0x8008BF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BFD8;
    // 0x8008BF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BF58:
    // 0x8008BF58: jal         0x800813D0
    // 0x8008BF5C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_12;
    // 0x8008BF5C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_12:
    // 0x8008BF60: b           L_8008BFD8
    // 0x8008BF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BFD8;
    // 0x8008BF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BF68:
    // 0x8008BF68: jal         0x80000B28
    // 0x8008BF6C: nop

    music_change_on(rdram, ctx);
        goto after_13;
    // 0x8008BF6C: nop

    after_13:
    // 0x8008BF70: jal         0x800828B8
    // 0x8008BF74: nop

    trackmenu_set_records(rdram, ctx);
        goto after_14;
    // 0x8008BF74: nop

    after_14:
    // 0x8008BF78: jal         0x8006E5BC
    // 0x8008BF7C: nop

    init_racer_headers(rdram, ctx);
        goto after_15;
    // 0x8008BF7C: nop

    after_15:
    // 0x8008BF80: jal         0x800813D0
    // 0x8008BF84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008BF84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_16:
    // 0x8008BF88: b           L_8008BFD8
    // 0x8008BF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008BFD8;
    // 0x8008BF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BF90:
    // 0x8008BF90: bgez        $v0, L_8008BFD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008BF94: nop
    
            goto L_8008BFD4;
    }
    // 0x8008BF94: nop

    // 0x8008BF98: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8008BF9C: nop

    // 0x8008BFA0: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8008BFA4: slti        $at, $t7, -0x1E
    ctx->r1 = SIGNED(ctx->r15) < -0X1E ? 1 : 0;
    // 0x8008BFA8: beq         $at, $zero, L_8008BFD4
    if (ctx->r1 == 0) {
        // 0x8008BFAC: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8008BFD4;
    }
    // 0x8008BFAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008BFB0: jal         0x80000B28
    // 0x8008BFB4: nop

    music_change_on(rdram, ctx);
        goto after_17;
    // 0x8008BFB4: nop

    after_17:
    // 0x8008BFB8: jal         0x8008C128
    // 0x8008BFBC: nop

    charselect_free(rdram, ctx);
        goto after_18;
    // 0x8008BFBC: nop

    after_18:
    // 0x8008BFC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008BFC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BFC8: sw          $t2, -0xB44($at)
    MEM_W(-0XB44, ctx->r1) = ctx->r10;
    // 0x8008BFCC: jal         0x800813D0
    // 0x8008BFD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_19;
    // 0x8008BFD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
L_8008BFD4:
    // 0x8008BFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008BFD8:
    // 0x8008BFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BFDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008BFE0: jr          $ra
    // 0x8008BFE4: nop

    return;
    // 0x8008BFE4: nop

;}
RECOMP_FUNC void ignore_bounds_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011564: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011568: jr          $ra
    // 0x8001156C: sb          $t6, -0x37B8($at)
    MEM_B(-0X37B8, ctx->r1) = ctx->r14;
    return;
    // 0x8001156C: sb          $t6, -0x37B8($at)
    MEM_B(-0X37B8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void sndp_stop_with_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800048DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800048E0: andi        $s2, $a0, 0xFF
    ctx->r18 = ctx->r4 & 0XFF;
    // 0x800048E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800048E8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800048EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800048F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800048F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800048F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800048FC: jal         0x800C9A30
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80004900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004904: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80004908: lw          $s0, -0x3950($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X3950);
    // 0x8000490C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80004910: beq         $s0, $zero, L_8000496C
    if (ctx->r16 == 0) {
        // 0x80004914: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8000496C;
    }
    // 0x80004914: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80004918: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000491C: addiu       $s3, $s3, -0x3944
    ctx->r19 = ADD32(ctx->r19, -0X3944);
    // 0x80004920: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x80004924: addiu       $s2, $zero, -0x11
    ctx->r18 = ADD32(0, -0X11);
    // 0x80004928: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000492C:
    // 0x8000492C: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x80004930: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80004934: lbu         $v0, 0x3E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004938: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000493C: and         $t7, $v0, $s1
    ctx->r15 = ctx->r2 & ctx->r17;
    // 0x80004940: bne         $s1, $t7, L_8000495C
    if (ctx->r17 != ctx->r15) {
        // 0x80004944: and         $t8, $v0, $s2
        ctx->r24 = ctx->r2 & ctx->r18;
            goto L_8000495C;
    }
    // 0x80004944: and         $t8, $v0, $s2
    ctx->r24 = ctx->r2 & ctx->r18;
    // 0x80004948: sb          $t8, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r24;
    // 0x8000494C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80004950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004954: jal         0x800C91AC
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004958: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_8000495C:
    // 0x8000495C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80004960: nop

    // 0x80004964: bne         $s0, $zero, L_8000492C
    if (ctx->r16 != 0) {
        // 0x80004968: addiu       $t6, $zero, 0x400
        ctx->r14 = ADD32(0, 0X400);
            goto L_8000492C;
    }
    // 0x80004968: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
L_8000496C:
    // 0x8000496C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80004970: jal         0x800C9A30
    // 0x80004974: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004974: nop

    after_2:
    // 0x80004978: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000497C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000498C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004990: jr          $ra
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80004994: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void search_level_properties_backwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AE30: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006AE34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006AE38: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006AE3C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006AE40: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006AE44: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AE48: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006AE4C: bne         $at, $zero, L_8006AE58
    if (ctx->r1 != 0) {
        // 0x8006AE50: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006AE58;
    }
    // 0x8006AE50: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006AE54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8006AE58:
    // 0x8006AE58: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006AE5C: beq         $a1, $at, L_8006AF60
    if (ctx->r5 == ctx->r1) {
        // 0x8006AE60: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8006AF60;
    }
    // 0x8006AE60: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006AE64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AE68: bne         $a2, $v0, L_8006AEB8
    if (ctx->r6 != ctx->r2) {
        // 0x8006AE6C: nop
    
            goto L_8006AEB8;
    }
    // 0x8006AE6C: nop

    // 0x8006AE70: bltz        $a0, L_8006B00C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AE74: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B00C;
    }
    // 0x8006AE74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AE78: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AE7C: lw          $t0, 0x117C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X117C);
    // 0x8006AE80: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AE84: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AE88: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006AE8C:
    // 0x8006AE8C: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006AE90: nop

    // 0x8006AE94: bne         $a1, $t2, L_8006AEA4
    if (ctx->r5 != ctx->r10) {
        // 0x8006AE98: nop
    
            goto L_8006AEA4;
    }
    // 0x8006AE98: nop

    // 0x8006AE9C: jr          $ra
    // 0x8006AEA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AEA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AEA4:
    // 0x8006AEA4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006AEA8: bgez        $a0, L_8006AE8C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AEAC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006AE8C;
    }
    // 0x8006AEAC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006AEB0: b           L_8006B010
    // 0x8006AEB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B010;
    // 0x8006AEB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AEB8:
    // 0x8006AEB8: bne         $a1, $v0, L_8006AF08
    if (ctx->r5 != ctx->r2) {
        // 0x8006AEBC: nop
    
            goto L_8006AF08;
    }
    // 0x8006AEBC: nop

    // 0x8006AEC0: bltz        $a0, L_8006B00C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AEC4: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8006B00C;
    }
    // 0x8006AEC4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006AEC8: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006AECC: lw          $t3, 0x117C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X117C);
    // 0x8006AED0: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006AED4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006AED8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_8006AEDC:
    // 0x8006AEDC: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006AEE0: nop

    // 0x8006AEE4: bne         $a2, $t5, L_8006AEF4
    if (ctx->r6 != ctx->r13) {
        // 0x8006AEE8: nop
    
            goto L_8006AEF4;
    }
    // 0x8006AEE8: nop

    // 0x8006AEEC: jr          $ra
    // 0x8006AEF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AEF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AEF4:
    // 0x8006AEF4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006AEF8: bgez        $a0, L_8006AEDC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AEFC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006AEDC;
    }
    // 0x8006AEFC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006AF00: b           L_8006B010
    // 0x8006AF04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B010;
    // 0x8006AF04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF08:
    // 0x8006AF08: bltz        $a0, L_8006B00C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AF0C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B00C;
    }
    // 0x8006AF0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AF10: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006AF14: lw          $t6, 0x117C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X117C);
    // 0x8006AF18: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006AF1C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006AF20: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8006AF24:
    // 0x8006AF24: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006AF28: nop

    // 0x8006AF2C: bne         $a1, $t8, L_8006AF4C
    if (ctx->r5 != ctx->r24) {
        // 0x8006AF30: nop
    
            goto L_8006AF4C;
    }
    // 0x8006AF30: nop

    // 0x8006AF34: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x8006AF38: nop

    // 0x8006AF3C: bne         $a2, $t9, L_8006AF4C
    if (ctx->r6 != ctx->r25) {
        // 0x8006AF40: nop
    
            goto L_8006AF4C;
    }
    // 0x8006AF40: nop

    // 0x8006AF44: jr          $ra
    // 0x8006AF48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AF48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AF4C:
    // 0x8006AF4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006AF50: bgez        $a0, L_8006AF24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AF54: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006AF24;
    }
    // 0x8006AF54: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006AF58: b           L_8006B010
    // 0x8006AF5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B010;
    // 0x8006AF5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF60:
    // 0x8006AF60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AF64: bne         $a2, $v0, L_8006AFB8
    if (ctx->r6 != ctx->r2) {
        // 0x8006AF68: nop
    
            goto L_8006AFB8;
    }
    // 0x8006AF68: nop

    // 0x8006AF6C: bltz        $a0, L_8006B00C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AF70: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006B00C;
    }
    // 0x8006AF70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AF74: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AF78: lw          $t0, 0x117C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X117C);
    // 0x8006AF7C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AF80: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AF84: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8006AF88:
    // 0x8006AF88: lb          $t2, 0x1($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1);
    // 0x8006AF8C: nop

    // 0x8006AF90: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006AF94: beq         $t3, $zero, L_8006AFA4
    if (ctx->r11 == 0) {
        // 0x8006AF98: nop
    
            goto L_8006AFA4;
    }
    // 0x8006AF98: nop

    // 0x8006AF9C: jr          $ra
    // 0x8006AFA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AFA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AFA4:
    // 0x8006AFA4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006AFA8: bgez        $a0, L_8006AF88
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AFAC: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006AF88;
    }
    // 0x8006AFAC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8006AFB0: b           L_8006B010
    // 0x8006AFB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B010;
    // 0x8006AFB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AFB8:
    // 0x8006AFB8: bltz        $a0, L_8006B00C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AFBC: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8006B00C;
    }
    // 0x8006AFBC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006AFC0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006AFC4: lw          $t4, 0x117C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X117C);
    // 0x8006AFC8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006AFCC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006AFD0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_8006AFD4:
    // 0x8006AFD4: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8006AFD8: nop

    // 0x8006AFDC: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006AFE0: beq         $t7, $zero, L_8006B000
    if (ctx->r15 == 0) {
        // 0x8006AFE4: nop
    
            goto L_8006B000;
    }
    // 0x8006AFE4: nop

    // 0x8006AFE8: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8006AFEC: nop

    // 0x8006AFF0: bne         $a2, $t8, L_8006B000
    if (ctx->r6 != ctx->r24) {
        // 0x8006AFF4: nop
    
            goto L_8006B000;
    }
    // 0x8006AFF4: nop

    // 0x8006AFF8: jr          $ra
    // 0x8006AFFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AFFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B000:
    // 0x8006B000: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006B004: bgez        $a0, L_8006AFD4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006B008: addiu       $v0, $v0, -0x6
        ctx->r2 = ADD32(ctx->r2, -0X6);
            goto L_8006AFD4;
    }
    // 0x8006B008: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
L_8006B00C:
    // 0x8006B00C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B010:
    // 0x8006B010: jr          $ra
    // 0x8006B014: nop

    return;
    // 0x8006B014: nop

;}
RECOMP_FUNC void rain_lightning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADAB8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800ADABC: addiu       $a2, $a2, 0x2C80
    ctx->r6 = ADD32(ctx->r6, 0X2C80);
    // 0x800ADAC0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800ADAC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ADAC8: blez        $v0, L_800ADB24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ADACC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800ADB24;
    }
    // 0x800ADACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADAD0: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800ADAD4: bgtz        $t6, L_800ADBB8
    if (SIGNED(ctx->r14) > 0) {
        // 0x800ADAD8: sw          $t6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r14;
            goto L_800ADBB8;
    }
    // 0x800ADAD8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800ADADC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800ADAE0: lw          $t8, 0x2C6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2C6C);
    // 0x800ADAE4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800ADAE8: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800ADAEC: bne         $at, $zero, L_800ADB10
    if (ctx->r1 != 0) {
        // 0x800ADAF0: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_800ADB10;
    }
    // 0x800ADAF0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800ADAF4: jal         0x800C018C
    // 0x800ADAF8: nop

    check_fadeout_transition(rdram, ctx);
        goto after_0;
    // 0x800ADAF8: nop

    after_0:
    // 0x800ADAFC: bne         $v0, $zero, L_800ADB0C
    if (ctx->r2 != 0) {
        // 0x800ADB00: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800ADB0C;
    }
    // 0x800ADB00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADB04: jal         0x800C01D8
    // 0x800ADB08: addiu       $a0, $a0, 0x2C98
    ctx->r4 = ADD32(ctx->r4, 0X2C98);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x800ADB08: addiu       $a0, $a0, 0x2C98
    ctx->r4 = ADD32(ctx->r4, 0X2C98);
    after_1:
L_800ADB0C:
    // 0x800ADB0C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_800ADB10:
    // 0x800ADB10: jal         0x80001D04
    // 0x800ADB14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800ADB14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800ADB18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADB1C: b           L_800ADBB8
    // 0x800ADB20: sw          $zero, 0x2C80($at)
    MEM_W(0X2C80, ctx->r1) = 0;
        goto L_800ADBB8;
    // 0x800ADB20: sw          $zero, 0x2C80($at)
    MEM_W(0X2C80, ctx->r1) = 0;
L_800ADB24:
    // 0x800ADB24: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ADB28: lw          $t9, 0x2C60($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2C60);
    // 0x800ADB2C: ori         $at, $zero, 0xBB80
    ctx->r1 = 0 | 0XBB80;
    // 0x800ADB30: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800ADB34: bne         $at, $zero, L_800ADBB8
    if (ctx->r1 != 0) {
        // 0x800ADB38: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800ADBB8;
    }
    // 0x800ADB38: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ADB3C: addiu       $v1, $v1, 0x2C7C
    ctx->r3 = ADD32(ctx->r3, 0X2C7C);
    // 0x800ADB40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800ADB44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800ADB48: blez        $v0, L_800ADB58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800ADB4C: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800ADB58;
    }
    // 0x800ADB4C: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800ADB50: b           L_800ADBB8
    // 0x800ADB54: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_800ADBB8;
    // 0x800ADB54: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800ADB58:
    // 0x800ADB58: jal         0x80001D04
    // 0x800ADB5C: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800ADB5C: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    after_3:
    // 0x800ADB60: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800ADB64: lw          $t1, 0x2C60($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2C60);
    // 0x800ADB68: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800ADB6C: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800ADB70: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800ADB74: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800ADB78: addiu       $t4, $zero, 0x258
    ctx->r12 = ADD32(0, 0X258);
    // 0x800ADB7C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800ADB80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADB84: sw          $t5, 0x2C80($at)
    MEM_W(0X2C80, ctx->r1) = ctx->r13;
    // 0x800ADB88: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x800ADB8C: jal         0x8006F94C
    // 0x800ADB90: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800ADB90: addiu       $a1, $zero, 0x474
    ctx->r5 = ADD32(0, 0X474);
    after_4:
    // 0x800ADB94: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADB98: lw          $t6, 0x2C60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C60);
    // 0x800ADB9C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800ADBA0: ori         $at, $at, 0x4480
    ctx->r1 = ctx->r1 | 0X4480;
    // 0x800ADBA4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800ADBA8: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800ADBAC: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800ADBB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADBB4: sw          $t9, 0x2C7C($at)
    MEM_W(0X2C7C, ctx->r1) = ctx->r25;
L_800ADBB8:
    // 0x800ADBB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ADBBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ADBC0: jr          $ra
    // 0x800ADBC4: nop

    return;
    // 0x800ADBC4: nop

;}
RECOMP_FUNC void transition_update_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1EE8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C1EEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1EF0: addiu       $v1, $v1, 0x31B0
    ctx->r3 = ADD32(ctx->r3, 0X31B0);
    // 0x800C1EF4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C1EF8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C1EFC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C1F00: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800C1F04: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800C1F08: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800C1F0C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800C1F10: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C1F14: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C1F18: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C1F1C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C1F20: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C1F24: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800C1F28: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800C1F2C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C1F30: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800C1F34: blez        $v0, L_800C2208
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C1F38: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2208;
    }
    // 0x800C1F38: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1F3C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C1F40: beq         $at, $zero, L_800C1F94
    if (ctx->r1 == 0) {
        // 0x800C1F44: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C1F94;
    }
    // 0x800C1F44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C1F48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F4C: lwc1        $f8, -0x58A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X58A0);
    // 0x800C1F50: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C1F54: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C1F58: addiu       $s7, $s7, -0x58A8
    ctx->r23 = ADD32(ctx->r23, -0X58A8);
    // 0x800C1F5C: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C1F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F64: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C1F68: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C1F6C: swc1        $f16, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f16.u32l;
    // 0x800C1F70: lwc1        $f4, -0x589C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X589C);
    // 0x800C1F74: addiu       $fp, $fp, -0x58A4
    ctx->r30 = ADD32(ctx->r30, -0X58A4);
    // 0x800C1F78: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C1F7C: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C1F80: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C1F84: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800C1F88: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C1F8C: b           L_800C1FC0
    // 0x800C1F90: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
        goto L_800C1FC0;
    // 0x800C1F90: swc1        $f6, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f6.u32l;
L_800C1F94:
    // 0x800C1F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F98: lwc1        $f10, -0x5898($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5898);
    // 0x800C1F9C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C1FA0: addiu       $s7, $s7, -0x58A8
    ctx->r23 = ADD32(ctx->r23, -0X58A8);
    // 0x800C1FA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FA8: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
    // 0x800C1FAC: lwc1        $f16, -0x5894($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5894);
    // 0x800C1FB0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800C1FB4: addiu       $fp, $fp, -0x58A4
    ctx->r30 = ADD32(ctx->r30, -0X58A4);
    // 0x800C1FB8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800C1FBC: swc1        $f16, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f16.u32l;
L_800C1FC0:
    // 0x800C1FC0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C1FC4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C1FC8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C1FCC: lwc1        $f22, -0x6CD4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6CD4);
    // 0x800C1FD0: addiu       $s0, $s0, 0x31C0
    ctx->r16 = ADD32(ctx->r16, 0X31C0);
    // 0x800C1FD4: addiu       $s1, $s1, 0x31D0
    ctx->r17 = ADD32(ctx->r17, 0X31D0);
    // 0x800C1FD8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C1FDC: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x800C1FE0: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_800C1FE4:
    // 0x800C1FE4: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x800C1FE8: sra         $t7, $s4, 16
    ctx->r15 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800C1FEC: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x800C1FF0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C1FF4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800C1FF8: jal         0x800707C4
    // 0x800C1FFC: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800C1FFC: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    after_0:
    // 0x800C2000: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800C2004: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x800C2008: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C200C: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C2010: jal         0x800707F8
    // 0x800C2014: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800C2014: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x800C2018: lwc1        $f18, 0x0($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800C201C: sll         $t0, $s2, 1
    ctx->r8 = S32(ctx->r18 << 1);
    // 0x800C2020: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800C2024: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800C2028: multu       $t0, $s5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C202C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C2030: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800C2034: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800C2038: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C203C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C2040: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800C2044: addiu       $s3, $s3, 0x1000
    ctx->r19 = ADD32(ctx->r19, 0X1000);
    // 0x800C2048: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800C204C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2050: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2054: nop

    // 0x800C2058: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C205C: mflo        $v0
    ctx->r2 = lo;
    // 0x800C2060: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800C2064: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800C2068: mul.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800C206C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C2070: sh          $a0, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r4;
    // 0x800C2074: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800C2078: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C207C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C2080: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800C2084: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C2088: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C208C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800C2090: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C2094: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800C2098: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800C209C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C20A0: sh          $v1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r3;
    // 0x800C20A4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C20A8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C20AC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C20B0: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C20B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C20B8: negu        $a3, $a0
    ctx->r7 = SUB32(0, ctx->r4);
    // 0x800C20BC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C20C0: sh          $a3, 0x172($t8)
    MEM_H(0X172, ctx->r24) = ctx->r7;
    // 0x800C20C4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C20C8: nop

    // 0x800C20CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C20D0: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C20D4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C20D8: nop

    // 0x800C20DC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C20E0: sh          $v1, 0x174($t3)
    MEM_H(0X174, ctx->r11) = ctx->r3;
    // 0x800C20E4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C20E8: nop

    // 0x800C20EC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C20F0: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C20F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C20F8: nop

    // 0x800C20FC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2100: sh          $a0, 0xB4($t8)
    MEM_H(0XB4, ctx->r24) = ctx->r4;
    // 0x800C2104: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2108: nop

    // 0x800C210C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2110: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2114: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2118: nop

    // 0x800C211C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2120: sh          $v1, 0xB6($t3)
    MEM_H(0XB6, ctx->r11) = ctx->r3;
    // 0x800C2124: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C2128: nop

    // 0x800C212C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C2130: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C2134: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C2138: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800C213C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2140: sh          $a3, 0x21C($t8)
    MEM_H(0X21C, ctx->r24) = ctx->r7;
    // 0x800C2144: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C2148: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800C214C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C2150: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C2154: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C2158: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C215C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C2160: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C2164: sh          $v1, 0x21E($t3)
    MEM_H(0X21E, ctx->r11) = ctx->r3;
    // 0x800C2168: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800C216C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800C2170: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C2174: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800C2178: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800C217C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C2180: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800C2184: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C2188: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C218C: sh          $a1, 0xBE($t9)
    MEM_H(0XBE, ctx->r25) = ctx->r5;
    // 0x800C2190: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800C2194: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800C2198: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C219C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C21A0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C21A4: cvt.w.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800C21A8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800C21AC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800C21B0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800C21B4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C21B8: sh          $a2, 0xC0($t5)
    MEM_H(0XC0, ctx->r13) = ctx->r6;
    // 0x800C21BC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800C21C0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C21C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800C21C8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800C21CC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800C21D0: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x800C21D4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800C21D8: sh          $t8, 0x226($t3)
    MEM_H(0X226, ctx->r11) = ctx->r24;
    // 0x800C21DC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800C21E0: nop

    // 0x800C21E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C21E8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800C21EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C21F0: nop

    // 0x800C21F4: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C21F8: bne         $s2, $s6, L_800C1FE4
    if (ctx->r18 != ctx->r22) {
        // 0x800C21FC: sh          $a2, 0x228($t9)
        MEM_H(0X228, ctx->r25) = ctx->r6;
            goto L_800C1FE4;
    }
    // 0x800C21FC: sh          $a2, 0x228($t9)
    MEM_H(0X228, ctx->r25) = ctx->r6;
    // 0x800C2200: b           L_800C2238
    // 0x800C2204: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_800C2238;
    // 0x800C2204: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2208:
    // 0x800C2208: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C220C: addiu       $v1, $v1, 0x31B4
    ctx->r3 = ADD32(ctx->r3, 0X31B4);
    // 0x800C2210: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C2214: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C2218: beq         $v0, $at, L_800C2234
    if (ctx->r2 == ctx->r1) {
        // 0x800C221C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C2234;
    }
    // 0x800C221C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2220: beq         $at, $zero, L_800C2230
    if (ctx->r1 == 0) {
        // 0x800C2224: subu        $t0, $v0, $a0
        ctx->r8 = SUB32(ctx->r2, ctx->r4);
            goto L_800C2230;
    }
    // 0x800C2224: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x800C2228: b           L_800C2234
    // 0x800C222C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
        goto L_800C2234;
    // 0x800C222C: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_800C2230:
    // 0x800C2230: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C2234:
    // 0x800C2234: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C2238:
    // 0x800C2238: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C223C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C2240: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C2244: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C2248: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C224C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2250: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C2254: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C2258: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C225C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800C2260: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800C2264: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800C2268: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800C226C: jr          $ra
    // 0x800C2270: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2270: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void savemenu_load_destinations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800867D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800867DC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800867E0: addiu       $s0, $s0, 0x6A00
    ctx->r16 = ADD32(ctx->r16, 0X6A00);
    // 0x800867E4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800867E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800867EC: lw          $t7, 0x6BD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BD4);
    // 0x800867F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800867F4: lw          $t6, 0x6A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A0C);
    // 0x800867F8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800867FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80086800: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80086804: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80086808: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008680C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80086810: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80086814: beq         $at, $zero, L_80086A0C
    if (ctx->r1 == 0) {
        // 0x80086818: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80086A0C;
    }
    // 0x80086818: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8008681C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086820: addu        $at, $at, $t0
    gpr jr_addend_8008682C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80086824: lw          $t0, -0x7C00($at)
    ctx->r8 = ADD32(ctx->r1, -0X7C00);
    // 0x80086828: nop

    // 0x8008682C: jr          $t0
    // 0x80086830: nop

    switch (jr_addend_8008682C >> 2) {
        case 0: goto L_80086834; break;
        case 1: goto L_80086888; break;
        case 2: goto L_800868C0; break;
        case 3: goto L_80086920; break;
        case 4: goto L_80086998; break;
        default: switch_error(__func__, 0x8008682C, 0x800E8400);
    }
    // 0x80086830: nop

L_80086834:
    // 0x80086834: lbu         $a0, 0x6($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X6);
    // 0x80086838: jal         0x8006EB78
    // 0x8008683C: nop

    mark_read_save_file(rdram, ctx);
        goto after_0;
    // 0x8008683C: nop

    after_0:
    // 0x80086840: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086844: lw          $a0, 0x6A04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A04);
    // 0x80086848: jal         0x800861C8
    // 0x8008684C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_1;
    // 0x8008684C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80086850: jal         0x80073C4C
    // 0x80086854: nop

    get_game_data_file_size(rdram, ctx);
        goto after_2;
    // 0x80086854: nop

    after_2:
    // 0x80086858: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008685C: lw          $a2, 0x6A04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A04);
    // 0x80086860: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086864: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80086868: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8008686C: addiu       $a1, $a1, 0x6A18
    ctx->r5 = ADD32(ctx->r5, 0X6A18);
    // 0x80086870: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80086874: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086878: jal         0x800860A8
    // 0x8008687C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_3;
    // 0x8008687C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80086880: b           L_80086A0C
    // 0x80086884: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086A0C;
    // 0x80086884: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086888:
    // 0x80086888: jal         0x80073C54
    // 0x8008688C: nop

    get_time_data_file_size(rdram, ctx);
        goto after_4;
    // 0x8008688C: nop

    after_4:
    // 0x80086890: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086894: lw          $a2, 0x6A04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A04);
    // 0x80086898: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008689C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800868A0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800868A4: addiu       $a1, $a1, 0x6A18
    ctx->r5 = ADD32(ctx->r5, 0X6A18);
    // 0x800868A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800868AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800868B0: jal         0x800860A8
    // 0x800868B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    savemenu_check_space(rdram, ctx);
        goto after_5;
    // 0x800868B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800868B8: b           L_80086A0C
    // 0x800868BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086A0C;
    // 0x800868BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800868C0:
    // 0x800868C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800868C4: lw          $a0, 0x6A04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A04);
    // 0x800868C8: jal         0x800861C8
    // 0x800868CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    savemenu_blank_save_destination(rdram, ctx);
        goto after_6;
    // 0x800868CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800868D0: jal         0x80073C4C
    // 0x800868D4: nop

    get_game_data_file_size(rdram, ctx);
        goto after_7;
    // 0x800868D4: nop

    after_7:
    // 0x800868D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800868DC: lw          $t4, 0x6BD4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BD4);
    // 0x800868E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800868E4: lw          $t3, 0x6A0C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A0C);
    // 0x800868E8: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800868EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800868F0: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800868F4: lbu         $t6, 0x6($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X6);
    // 0x800868F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800868FC: lw          $a2, 0x6A04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A04);
    // 0x80086900: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086904: addiu       $a1, $a1, 0x6A1C
    ctx->r5 = ADD32(ctx->r5, 0X6A1C);
    // 0x80086908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008690C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086910: jal         0x800860A8
    // 0x80086914: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    savemenu_check_space(rdram, ctx);
        goto after_8;
    // 0x80086914: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_8:
    // 0x80086918: b           L_80086A0C
    // 0x8008691C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086A0C;
    // 0x8008691C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086920:
    // 0x80086920: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086924: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086928: lw          $t9, 0x6A04($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A04);
    // 0x8008692C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80086930: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80086934: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80086938: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x8008693C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086940: nop

    // 0x80086944: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80086948: jal         0x80073C54
    // 0x8008694C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    get_time_data_file_size(rdram, ctx);
        goto after_9;
    // 0x8008694C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    after_9:
    // 0x80086950: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086954: lw          $t7, 0x6BD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BD4);
    // 0x80086958: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008695C: lw          $t5, 0x6A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A0C);
    // 0x80086960: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80086964: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80086968: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8008696C: lbu         $t9, 0x6($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X6);
    // 0x80086970: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086974: lw          $a2, 0x6A04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A04);
    // 0x80086978: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008697C: addiu       $a1, $a1, 0x6A1C
    ctx->r5 = ADD32(ctx->r5, 0X6A1C);
    // 0x80086980: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086984: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086988: jal         0x800860A8
    // 0x8008698C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    savemenu_check_space(rdram, ctx);
        goto after_10;
    // 0x8008698C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_10:
    // 0x80086990: b           L_80086A0C
    // 0x80086994: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80086A0C;
    // 0x80086994: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086998:
    // 0x80086998: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8008699C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800869A0: lw          $t8, 0x6A04($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A04);
    // 0x800869A4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x800869A8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800869AC: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x800869B0: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x800869B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800869B8: nop

    // 0x800869BC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x800869C0: jal         0x80074B1C
    // 0x800869C4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    get_ghost_data_file_size(rdram, ctx);
        goto after_11;
    // 0x800869C4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    after_11:
    // 0x800869C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800869CC: lw          $t0, 0x6BD4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BD4);
    // 0x800869D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800869D4: lw          $t6, 0x6A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A0C);
    // 0x800869D8: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800869DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800869E0: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800869E4: lbu         $t8, 0x6($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X6);
    // 0x800869E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800869EC: lw          $a2, 0x6A04($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A04);
    // 0x800869F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800869F4: addiu       $a1, $a1, 0x6A1C
    ctx->r5 = ADD32(ctx->r5, 0X6A1C);
    // 0x800869F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800869FC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80086A00: jal         0x800860A8
    // 0x80086A04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    savemenu_check_space(rdram, ctx);
        goto after_12;
    // 0x80086A04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x80086A08: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80086A0C:
    // 0x80086A0C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80086A10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086A14: lw          $t1, 0x6A04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A04);
    // 0x80086A18: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x80086A1C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80086A20: addu        $t5, $t1, $t7
    ctx->r13 = ADD32(ctx->r9, ctx->r15);
    // 0x80086A24: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80086A28: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80086A30: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80086A34: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80086A38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086A3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80086A40: jr          $ra
    // 0x80086A44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80086A44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void audspat_debug_render_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A414: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000A418: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A420: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A424: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000A428: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8000A42C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000A430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A438: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8000A43C: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8000A440: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A444: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8000A448: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A44C: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8000A450: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000A454: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A458: nop

    // 0x8000A45C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A460: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A464: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A468: nop

    // 0x8000A46C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A470: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8000A474: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A478: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8000A47C: nop

    // 0x8000A480: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000A484: nop

    // 0x8000A488: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000A48C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A490: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A494: nop

    // 0x8000A498: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A49C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8000A4A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000A4A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000A4A8: nop

    // 0x8000A4AC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000A4B0: nop

    // 0x8000A4B4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000A4B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4C0: nop

    // 0x8000A4C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000A4C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000A4CC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8000A4D0: nop

    // 0x8000A4D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000A4D8: nop

    // 0x8000A4DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000A4E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A4E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A4E8: nop

    // 0x8000A4EC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A4F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000A4F4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8000A4F8: nop

    // 0x8000A4FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A500: nop

    // 0x8000A504: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000A508: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A50C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A510: nop

    // 0x8000A514: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A518: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A51C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8000A520: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8000A524: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A528: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000A52C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000A530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000A534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A538: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8000A53C: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    // 0x8000A540: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8000A544: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    // 0x8000A548: sh          $t3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r11;
    // 0x8000A54C: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
    // 0x8000A550: sh          $t5, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r13;
    // 0x8000A554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000A558: jal         0x8007B4C8
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8000A55C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000A560: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8000A564: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8000A568: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000A56C: addu        $a1, $v0, $a3
    ctx->r5 = ADD32(ctx->r2, ctx->r7);
    // 0x8000A570: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x8000A574: ori         $t7, $t6, 0x18
    ctx->r15 = ctx->r14 | 0X18;
    // 0x8000A578: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8000A57C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A580: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000A584: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8000A588: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8000A58C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A590: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8000A594: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8000A598: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8000A59C: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x8000A5A0: lh          $t4, 0x22($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X22);
    // 0x8000A5A4: lh          $t5, 0x20($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X20);
    // 0x8000A5A8: lbu         $ra, 0x4B($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000A5AC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8000A5B0: ori         $t7, $t6, 0x50
    ctx->r15 = ctx->r14 | 0X50;
    // 0x8000A5B4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000A5B8: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8000A5BC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8000A5C0: lui         $t6, 0x510
    ctx->r14 = S32(0X510 << 16);
    // 0x8000A5C4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8000A5C8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000A5CC: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x8000A5D0: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x8000A5D4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8000A5D8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000A5DC: addiu       $t8, $t1, 0x5
    ctx->r24 = ADD32(ctx->r9, 0X5);
    // 0x8000A5E0: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x8000A5E4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8000A5E8: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
    // 0x8000A5EC: sb          $ra, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r31;
    // 0x8000A5F0: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A5F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000A5F8: sb          $t9, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r25;
    // 0x8000A5FC: lbu         $a1, 0x53($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X53);
    // 0x8000A600: addiu       $t6, $t1, -0x5
    ctx->r14 = ADD32(ctx->r9, -0X5);
    // 0x8000A604: sb          $a0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r4;
    // 0x8000A608: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x8000A60C: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8000A610: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x8000A614: sb          $ra, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r31;
    // 0x8000A618: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x8000A61C: lbu         $t7, 0x4F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X4F);
    // 0x8000A620: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x8000A624: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8000A628: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x8000A62C: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x8000A630: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x8000A634: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x8000A638: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x8000A63C: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x8000A640: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x8000A644: addiu       $t8, $t4, 0x5
    ctx->r24 = ADD32(ctx->r12, 0X5);
    // 0x8000A648: addiu       $t9, $t4, -0x5
    ctx->r25 = ADD32(ctx->r12, -0X5);
    // 0x8000A64C: sb          $a1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r5;
    // 0x8000A650: sh          $t8, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r24;
    // 0x8000A654: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x8000A658: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8000A65C: sh          $t3, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r11;
    // 0x8000A660: sh          $t5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r13;
    // 0x8000A664: sh          $t5, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r13;
    // 0x8000A668: sb          $t7, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r15;
    // 0x8000A66C: addiu       $a0, $zero, 0x3E0
    ctx->r4 = ADD32(0, 0X3E0);
    // 0x8000A670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000A674: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8000A67C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8000A680: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000A684: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
    // 0x8000A688: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x8000A68C: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x8000A690: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000A694: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x8000A698: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x8000A69C: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x8000A6A0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8000A6A4: sh          $a1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r5;
    // 0x8000A6A8: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8000A6AC: sb          $a2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r6;
    // 0x8000A6B0: sb          $t6, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r14;
    // 0x8000A6B4: sb          $a3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r7;
    // 0x8000A6B8: sb          $t0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r8;
    // 0x8000A6BC: sh          $a1, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r5;
    // 0x8000A6C0: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x8000A6C4: sh          $a0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r4;
    // 0x8000A6C8: sh          $a0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r4;
    // 0x8000A6CC: sh          $a1, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r5;
    // 0x8000A6D0: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x8000A6D4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8000A6D8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000A6DC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8000A6E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000A6E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A6E8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8000A6EC: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8000A6F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000A6F4: nop

    // 0x8000A6F8: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8000A6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A700: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000A704: jr          $ra
    // 0x8000A708: nop

    return;
    // 0x8000A708: nop

;}
RECOMP_FUNC void enable_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C2C8: jr          $ra
    // 0x8009C2CC: sw          $a0, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = ctx->r4;
    return;
    // 0x8009C2CC: sw          $a0, -0xB48($at)
    MEM_W(-0XB48, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void disable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0180: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0184: jr          $ra
    // 0x800C0188: sw          $zero, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = 0;
    return;
    // 0x800C0188: sw          $zero, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = 0;
;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC4E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC4E4: beq         $a1, $at, L_800CC500
    if (ctx->r5 == ctx->r1) {
        // 0x800CC4E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CC500;
    }
    // 0x800CC4E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CC4EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CC4F0: beql        $a1, $at, L_800CC50C
    if (ctx->r5 == ctx->r1) {
        // 0x800CC4F4: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800CC50C;
    }
    goto skip_0;
    // 0x800CC4F4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800CC4F8: jr          $ra
    // 0x800CC4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CC4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CC500:
    // 0x800CC500: jr          $ra
    // 0x800CC504: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800CC504: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800CC508: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800CC50C:
    // 0x800CC50C: jr          $ra
    // 0x800CC510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CC510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void obj_loop_dooropener(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037D10: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80037D14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80037D18: jal         0x8001F460
    // 0x80037D1C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037D1C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80037D20: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80037D24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80037D28: lh          $t9, 0x2A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2A);
    // 0x80037D2C: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    // 0x80037D30: blez        $t9, L_80037D3C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80037D34: nop
    
            goto L_80037D3C;
    }
    // 0x80037D34: nop

    // 0x80037D38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80037D3C:
    // 0x80037D3C: jal         0x800235D0
    // 0x80037D40: nop

    obj_door_open(rdram, ctx);
        goto after_1;
    // 0x80037D40: nop

    after_1:
    // 0x80037D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037D48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037D4C: jr          $ra
    // 0x80037D50: nop

    return;
    // 0x80037D50: nop

;}
RECOMP_FUNC void alCSPGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A50: jr          $ra
    // 0x800C7A54: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    return;
    // 0x800C7A54: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
;}
RECOMP_FUNC void alCSPSetFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063BA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80063BA8: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80063BAC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063BB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063BBC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063BC0: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x80063BC4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80063BC8: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063BCC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063BD0: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063BD4: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063BD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063BDC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063BE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80063BE4: jal         0x800C91AC
    // 0x80063BE8: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063BE8: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    after_0:
    // 0x80063BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063BF4: jr          $ra
    // 0x80063BF8: nop

    return;
    // 0x80063BF8: nop

;}
RECOMP_FUNC void get_racer_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BA78: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8001BA7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BA84: lw          $v0, -0x511C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X511C);
    // 0x8001BA88: jr          $ra
    // 0x8001BA8C: nop

    return;
    // 0x8001BA8C: nop

;}
RECOMP_FUNC void fileselect_input_copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D8BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008D8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D8C4: jal         0x8006EA90
    // 0x8008D8C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008D8C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008D8CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008D8D0: jal         0x8006A554
    // 0x8008D8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008D8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008D8D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D8DC: lw          $t6, -0xB44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB44);
    // 0x8008D8E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008D8E4: lb          $a1, 0x645C($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X645C);
    // 0x8008D8E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D8EC: bne         $t6, $at, L_8008D91C
    if (ctx->r14 != ctx->r1) {
        // 0x8008D8F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8008D91C;
    }
    // 0x8008D8F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008D8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008D8F8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8008D8FC: jal         0x8006A554
    // 0x8008D900: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8008D900: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8008D904: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008D908: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008D90C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008D910: lb          $t7, 0x645D($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X645D);
    // 0x8008D914: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8008D918: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_8008D91C:
    // 0x8008D91C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D920: lw          $v0, 0x6494($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6494);
    // 0x8008D924: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x8008D928: bne         $v0, $zero, L_8008DA38
    if (ctx->r2 != 0) {
        // 0x8008D92C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008DA38;
    }
    // 0x8008D92C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D930: beq         $t8, $zero, L_8008D950
    if (ctx->r24 == 0) {
        // 0x8008D934: andi        $t9, $v1, 0x9000
        ctx->r25 = ctx->r3 & 0X9000;
            goto L_8008D950;
    }
    // 0x8008D934: andi        $t9, $v1, 0x9000
    ctx->r25 = ctx->r3 & 0X9000;
    // 0x8008D938: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008D93C: jal         0x80001D04
    // 0x8008D940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008D940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008D944: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D948: b           L_8008DC6C
    // 0x8008D94C: sw          $zero, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = 0;
        goto L_8008DC6C;
    // 0x8008D94C: sw          $zero, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = 0;
L_8008D950:
    // 0x8008D950: beq         $t9, $zero, L_8008D9E8
    if (ctx->r25 == 0) {
        // 0x8008D954: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008D9E8;
    }
    // 0x8008D954: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D958: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D95C: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008D960: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008D964: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008D968: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008D96C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008D970: addiu       $t0, $t0, 0x64A0
    ctx->r8 = ADD32(ctx->r8, 0X64A0);
    // 0x8008D974: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008D978: mflo        $t2
    ctx->r10 = lo;
    // 0x8008D97C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8008D980: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8008D984: nop

    // 0x8008D988: beq         $t4, $zero, L_8008D9D4
    if (ctx->r12 == 0) {
        // 0x8008D98C: nop
    
            goto L_8008D9D4;
    }
    // 0x8008D98C: nop

    // 0x8008D990: jal         0x80001D04
    // 0x8008D994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008D994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008D998: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D99C: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008D9A0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8008D9A4: jal         0x8006EB78
    // 0x8008D9A8: nop

    mark_read_save_file(rdram, ctx);
        goto after_5;
    // 0x8008D9A8: nop

    after_5:
    // 0x8008D9AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D9B0: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008D9B4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8008D9B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008D9BC: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008D9C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008D9C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D9C8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008D9CC: b           L_8008DC6C
    // 0x8008D9D0: sw          $t6, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r14;
        goto L_8008DC6C;
    // 0x8008D9D0: sw          $t6, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r14;
L_8008D9D4:
    // 0x8008D9D4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008D9D8: jal         0x80001D04
    // 0x8008D9DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008D9DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8008D9E0: b           L_8008DC70
    // 0x8008D9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DC70;
    // 0x8008D9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008D9E8:
    // 0x8008D9E8: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008D9EC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008D9F0: bgez        $a1, L_8008DA08
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008D9F4: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8008DA08;
    }
    // 0x8008D9F4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8008D9F8: blez        $a2, L_8008DA08
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008D9FC: addiu       $t7, $a2, -0x1
        ctx->r15 = ADD32(ctx->r6, -0X1);
            goto L_8008DA08;
    }
    // 0x8008D9FC: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8008DA00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008DA04: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8008DA08:
    // 0x8008DA08: blez        $a1, L_8008DA20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DA0C: slti        $at, $a2, 0x2
        ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
            goto L_8008DA20;
    }
    // 0x8008DA0C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8008DA10: beq         $at, $zero, L_8008DA20
    if (ctx->r1 == 0) {
        // 0x8008DA14: addiu       $t8, $a2, 0x1
        ctx->r24 = ADD32(ctx->r6, 0X1);
            goto L_8008DA20;
    }
    // 0x8008DA14: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8008DA18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008DA1C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8008DA20:
    // 0x8008DA20: beq         $v1, $a2, L_8008DC6C
    if (ctx->r3 == ctx->r6) {
        // 0x8008DA24: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008DC6C;
    }
    // 0x8008DA24: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DA28: jal         0x80001D04
    // 0x8008DA2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x8008DA2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8008DA30: b           L_8008DC70
    // 0x8008DA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DC70;
    // 0x8008DA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DA38:
    // 0x8008DA38: bne         $v0, $at, L_8008DB38
    if (ctx->r2 != ctx->r1) {
        // 0x8008DA3C: andi        $t1, $v1, 0x9000
        ctx->r9 = ctx->r3 & 0X9000;
            goto L_8008DB38;
    }
    // 0x8008DA3C: andi        $t1, $v1, 0x9000
    ctx->r9 = ctx->r3 & 0X9000;
    // 0x8008DA40: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8008DA44: beq         $t9, $zero, L_8008DA78
    if (ctx->r25 == 0) {
        // 0x8008DA48: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DA78;
    }
    // 0x8008DA48: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DA4C: jal         0x80001D04
    // 0x8008DA50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8008DA50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008DA54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DA58: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008DA5C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8008DA60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DA64: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008DA68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DA6C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8008DA70: b           L_8008DC6C
    // 0x8008DA74: sw          $zero, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = 0;
        goto L_8008DC6C;
    // 0x8008DA74: sw          $zero, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = 0;
L_8008DA78:
    // 0x8008DA78: andi        $t2, $v1, 0x9000
    ctx->r10 = ctx->r3 & 0X9000;
    // 0x8008DA7C: beq         $t2, $zero, L_8008DAE4
    if (ctx->r10 == 0) {
        // 0x8008DA80: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8008DAE4;
    }
    // 0x8008DA80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DA84: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008DA88: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8008DA8C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DA90: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DA94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DA98: addiu       $t0, $t0, 0x64A0
    ctx->r8 = ADD32(ctx->r8, 0X64A0);
    // 0x8008DA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DAA0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DAA4: mflo        $t4
    ctx->r12 = lo;
    // 0x8008DAA8: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x8008DAAC: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8008DAB0: nop

    // 0x8008DAB4: bne         $t6, $zero, L_8008DAD4
    if (ctx->r14 != 0) {
        // 0x8008DAB8: nop
    
            goto L_8008DAD4;
    }
    // 0x8008DAB8: nop

    // 0x8008DABC: jal         0x80001D04
    // 0x8008DAC0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    sound_play(rdram, ctx);
        goto after_9;
    // 0x8008DAC0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    after_9:
    // 0x8008DAC4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008DAC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DACC: b           L_8008DC6C
    // 0x8008DAD0: sw          $t7, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r15;
        goto L_8008DC6C;
    // 0x8008DAD0: sw          $t7, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r15;
L_8008DAD4:
    // 0x8008DAD4: jal         0x80001D04
    // 0x8008DAD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8008DAD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8008DADC: b           L_8008DC70
    // 0x8008DAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DC70;
    // 0x8008DAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DAE4:
    // 0x8008DAE4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DAE8: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008DAEC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008DAF0: bgez        $a1, L_8008DB08
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8008DAF4: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8008DB08;
    }
    // 0x8008DAF4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8008DAF8: blez        $a3, L_8008DB08
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8008DAFC: addiu       $t8, $a3, -0x1
        ctx->r24 = ADD32(ctx->r7, -0X1);
            goto L_8008DB08;
    }
    // 0x8008DAFC: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8008DB00: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8008DB04: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_8008DB08:
    // 0x8008DB08: blez        $a1, L_8008DB20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008DB0C: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_8008DB20;
    }
    // 0x8008DB0C: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x8008DB10: beq         $at, $zero, L_8008DB20
    if (ctx->r1 == 0) {
        // 0x8008DB14: addiu       $t9, $a3, 0x1
        ctx->r25 = ADD32(ctx->r7, 0X1);
            goto L_8008DB20;
    }
    // 0x8008DB14: addiu       $t9, $a3, 0x1
    ctx->r25 = ADD32(ctx->r7, 0X1);
    // 0x8008DB18: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008DB1C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_8008DB20:
    // 0x8008DB20: beq         $v1, $a3, L_8008DC6C
    if (ctx->r3 == ctx->r7) {
        // 0x8008DB24: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008DC6C;
    }
    // 0x8008DB24: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008DB28: jal         0x80001D04
    // 0x8008DB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8008DB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8008DB30: b           L_8008DC70
    // 0x8008DB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008DC70;
    // 0x8008DB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DB38:
    // 0x8008DB38: beq         $t1, $zero, L_8008DC4C
    if (ctx->r9 == 0) {
        // 0x8008DB3C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008DC4C;
    }
    // 0x8008DB3C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008DB40: jal         0x80001D04
    // 0x8008DB44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8008DB44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8008DB48: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DB4C: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008DB50: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8008DB54: jal         0x8006EC18
    // 0x8008DB58: nop

    force_mark_write_save_file(rdram, ctx);
        goto after_13;
    // 0x8008DB58: nop

    after_13:
    // 0x8008DB5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008DB60: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x8008DB64: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8008DB68: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8008DB6C: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DB70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008DB74: addiu       $t0, $t0, 0x64A0
    ctx->r8 = ADD32(ctx->r8, 0X64A0);
    // 0x8008DB78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008DB7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008DB80: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8008DB84: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x8008DB88: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008DB8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008DB90: mflo        $t2
    ctx->r10 = lo;
    // 0x8008DB94: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008DB98: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008DB9C: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x8008DBA0: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8008DBA4: nop

    // 0x8008DBA8: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8008DBAC: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8008DBB0: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8008DBB4: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x8008DBB8: subu        $t3, $t3, $a3
    ctx->r11 = SUB32(ctx->r11, ctx->r7);
    // 0x8008DBBC: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8008DBC0: beq         $t6, $zero, L_8008DBCC
    if (ctx->r14 == 0) {
        // 0x8008DBC4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8008DBCC;
    }
    // 0x8008DBC4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008DBC8: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_8008DBCC:
    // 0x8008DBCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008DBD0: addiu       $v0, $v0, 0x648C
    ctx->r2 = ADD32(ctx->r2, 0X648C);
    // 0x8008DBD4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8008DBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008DBDC: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008DBE0: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8008DBE4: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8008DBE8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008DBEC: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8008DBF0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8008DBF4: mflo        $t7
    ctx->r15 = lo;
    // 0x8008DBF8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8008DBFC: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x8008DC00: nop

    // 0x8008DC04: beq         $t9, $zero, L_8008DC30
    if (ctx->r25 == 0) {
        // 0x8008DC08: addu        $t5, $t4, $a1
        ctx->r13 = ADD32(ctx->r12, ctx->r5);
            goto L_8008DC30;
    }
    // 0x8008DC08: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x8008DC0C: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x8008DC10: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8008DC14:
    // 0x8008DC14: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x8008DC18: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x8008DC1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008DC20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008DC24: bne         $a0, $zero, L_8008DC14
    if (ctx->r4 != 0) {
        // 0x8008DC28: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008DC14;
    }
    // 0x8008DC28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008DC2C: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
L_8008DC30:
    // 0x8008DC30: sb          $zero, 0x4($t5)
    MEM_B(0X4, ctx->r13) = 0;
    // 0x8008DC34: sw          $a3, -0xB34($at)
    MEM_W(-0XB34, ctx->r1) = ctx->r7;
    // 0x8008DC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC3C: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8008DC40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC44: b           L_8008DC6C
    // 0x8008DC48: sw          $zero, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = 0;
        goto L_8008DC6C;
    // 0x8008DC48: sw          $zero, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = 0;
L_8008DC4C:
    // 0x8008DC4C: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x8008DC50: beq         $t6, $zero, L_8008DC6C
    if (ctx->r14 == 0) {
        // 0x8008DC54: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008DC6C;
    }
    // 0x8008DC54: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008DC58: jal         0x80001D04
    // 0x8008DC5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x8008DC5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8008DC60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008DC64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC68: sw          $t7, 0x6494($at)
    MEM_W(0X6494, ctx->r1) = ctx->r15;
L_8008DC6C:
    // 0x8008DC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DC70:
    // 0x8008DC70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008DC74: jr          $ra
    // 0x8008DC78: nop

    return;
    // 0x8008DC78: nop

;}
RECOMP_FUNC void obj_loop_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800345A0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800345A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800345A8: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800345AC: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800345B0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800345B4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800345B8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800345BC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800345C0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800345C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800345C8: lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC);
    // 0x800345CC: nop

    // 0x800345D0: blez        $v0, L_800345E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800345D4: subu        $t6, $v0, $a1
        ctx->r14 = SUB32(ctx->r2, ctx->r5);
            goto L_800345E0;
    }
    // 0x800345D4: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x800345D8: b           L_80034820
    // 0x800345DC: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
        goto L_80034820;
    // 0x800345DC: sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
L_800345E0:
    // 0x800345E0: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x800345E4: lbu         $t7, 0x11($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X11);
    // 0x800345E8: lbu         $t8, 0x13($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13);
    // 0x800345EC: nop

    // 0x800345F0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800345F4: bne         $at, $zero, L_80034824
    if (ctx->r1 != 0) {
        // 0x800345F8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80034824;
    }
    // 0x800345F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800345FC: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x80034600: nop

    // 0x80034604: beq         $t9, $zero, L_800346BC
    if (ctx->r25 == 0) {
        // 0x80034608: nop
    
            goto L_800346BC;
    }
    // 0x80034608: nop

    // 0x8003460C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034610: nop

    // 0x80034614: beq         $v0, $zero, L_800346BC
    if (ctx->r2 == 0) {
        // 0x80034618: nop
    
            goto L_800346BC;
    }
    // 0x80034618: nop

    // 0x8003461C: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x80034620: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80034624: bne         $t0, $at, L_800346BC
    if (ctx->r8 != ctx->r1) {
        // 0x80034628: nop
    
            goto L_800346BC;
    }
    // 0x80034628: nop

    // 0x8003462C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034630: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034634: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034638: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003463C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80034640: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80034644: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034648: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003464C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80034650: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80034654: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80034658: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x8003465C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80034660: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80034664: jal         0x800C9AD0
    // 0x80034668: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80034668: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8003466C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034670: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80034674: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80034678: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8003467C: nop

    // 0x80034680: bc1f        L_800346BC
    if (!c1cs) {
        // 0x80034684: nop
    
            goto L_800346BC;
    }
    // 0x80034684: nop

    // 0x80034688: div.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8003468C: nop

    // 0x80034690: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80034694: jal         0x80070750
    // 0x80034698: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x80034698: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    after_1:
    // 0x8003469C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800346A0: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x800346A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800346A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800346AC: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x800346B0: jal         0x80070750
    // 0x800346B4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x800346B4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x800346B8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800346BC:
    // 0x800346BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800346C0: lb          $t4, 0xF($s1)
    ctx->r12 = MEM_B(ctx->r17, 0XF);
    // 0x800346C4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800346C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800346CC: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
    // 0x800346D0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800346D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800346D8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800346DC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800346E0: addiu       $t2, $zero, 0xC6
    ctx->r10 = ADD32(0, 0XC6);
    // 0x800346E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800346E8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800346EC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800346F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800346F4: sh          $t6, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r14;
    // 0x800346F8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800346FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80034700: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034704: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034708: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    // 0x8003470C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80034710: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034714: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80034718: nop

    // 0x8003471C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80034720: sh          $t8, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r24;
    // 0x80034724: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80034728: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003472C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80034730: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034734: sb          $t1, 0x49($sp)
    MEM_B(0X49, ctx->r29) = ctx->r9;
    // 0x80034738: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003473C: sb          $t2, 0x48($sp)
    MEM_B(0X48, ctx->r29) = ctx->r10;
    // 0x80034740: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80034744: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80034748: sh          $t0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r8;
    // 0x8003474C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034750: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034754: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80034758: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003475C: jal         0x80009558
    // 0x80034760: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x80034760: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x80034764: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80034768: jal         0x8000EA54
    // 0x8003476C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x8003476C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80034770: beq         $v0, $zero, L_80034820
    if (ctx->r2 == 0) {
        // 0x80034774: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80034820;
    }
    // 0x80034774: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034778: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003477C: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80034780: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80034784: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x80034788: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8003478C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034790: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x80034794: lbu         $t6, 0x10($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X10);
    // 0x80034798: sw          $s1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r17;
    // 0x8003479C: sw          $t6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r14;
    // 0x800347A0: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x800347A4: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x800347A8: swc1        $f22, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f22.u32l;
    // 0x800347AC: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
    // 0x800347B0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800347B4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800347B8: sh          $t7, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r15;
    // 0x800347BC: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x800347C0: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x800347C4: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x800347C8: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800347CC: jal         0x8006FC30
    // 0x800347D0: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_5;
    // 0x800347D0: sh          $t8, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r24;
    after_5:
    // 0x800347D4: lb          $t9, 0xE($s1)
    ctx->r25 = MEM_B(ctx->r17, 0XE);
    // 0x800347D8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800347DC: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x800347E0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800347E4: bne         $t9, $zero, L_800347F8
    if (ctx->r25 != 0) {
        // 0x800347E8: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_800347F8;
    }
    // 0x800347E8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800347EC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800347F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800347F4: nop

L_800347F8:
    // 0x800347F8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800347FC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80034800: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80034804: addiu       $t0, $v1, 0x1C
    ctx->r8 = ADD32(ctx->r3, 0X1C);
    // 0x80034808: addiu       $t1, $v1, 0x20
    ctx->r9 = ADD32(ctx->r3, 0X20);
    // 0x8003480C: addiu       $t2, $v1, 0x24
    ctx->r10 = ADD32(ctx->r3, 0X24);
    // 0x80034810: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80034814: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80034818: jal         0x8006F64C
    // 0x8003481C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x8003481C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_6:
L_80034820:
    // 0x80034820: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80034824:
    // 0x80034824: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034828: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003482C: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034830: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034834: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80034838: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8003483C: jr          $ra
    // 0x80034840: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80034840: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void dialogue_ortho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E9B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009E9B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E9BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009E9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E9C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009E9C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009E9CC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009E9D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E9D4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8009E9D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009E9DC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8009E9E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009E9E4: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8009E9E8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8009E9EC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8009E9F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E9F4: jal         0x80067F2C
    // 0x8009E9F8: sw          $t1, 0x63AC($at)
    MEM_W(0X63AC, ctx->r1) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x8009E9F8: sw          $t1, 0x63AC($at)
    MEM_W(0X63AC, ctx->r1) = ctx->r9;
    after_0:
    // 0x8009E9FC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009EA00: lb          $t2, 0x1E28($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X1E28);
    // 0x8009EA04: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009EA08: beq         $t2, $zero, L_8009EA28
    if (ctx->r10 == 0) {
        // 0x8009EA0C: nop
    
            goto L_8009EA28;
    }
    // 0x8009EA0C: nop

    // 0x8009EA10: lb          $t3, 0x64E2($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X64E2);
    // 0x8009EA14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009EA18: bne         $t3, $at, L_8009EA28
    if (ctx->r11 != ctx->r1) {
        // 0x8009EA1C: nop
    
            goto L_8009EA28;
    }
    // 0x8009EA1C: nop

    // 0x8009EA20: jal         0x8009E3D0
    // 0x8009EA24: nop

    dialogue_tt_gamestatus(rdram, ctx);
        goto after_1;
    // 0x8009EA24: nop

    after_1:
L_8009EA28:
    // 0x8009EA28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009EA2C: lw          $t4, 0x63A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63A0);
    // 0x8009EA30: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EA34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009EA38: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8009EA3C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8009EA40: lw          $t6, 0x63A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63A8);
    // 0x8009EA44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009EA48: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009EA4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8009EA50: lw          $t8, 0x63AC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63AC);
    // 0x8009EA54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009EA58: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8009EA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EA60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009EA64: jr          $ra
    // 0x8009EA68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009EA68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void hud_stopwatch_face(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A36CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A36D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A36D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A36D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A36DC: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800A36E0: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x800A36E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A36E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A36EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A36F0: jal         0x8000E4D8
    // 0x800A36F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_0;
    // 0x800A36F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A36F8: beq         $v0, $zero, L_800A385C
    if (ctx->r2 == 0) {
        // 0x800A36FC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A385C;
    }
    // 0x800A36FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3700: lw          $t6, 0x6CF4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6CF4);
    // 0x800A3704: nop

    // 0x800A3708: lw          $v0, 0x50($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X50);
    // 0x800A370C: nop

    // 0x800A3710: beq         $v0, $zero, L_800A3860
    if (ctx->r2 == 0) {
        // 0x800A3714: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A3860;
    }
    // 0x800A3714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3718: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x800A371C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3720: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800A3724: addiu       $ra, $ra, 0x6D65
    ctx->r31 = ADD32(ctx->r31, 0X6D65);
    // 0x800A3728: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A372C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A3730: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3738: blez        $a3, L_800A3820
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A373C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A3820;
    }
    // 0x800A373C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3740: lui         $t4, 0xFF7E
    ctx->r12 = S32(0XFF7E << 16);
    // 0x800A3744: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x800A3748: addiu       $t5, $t5, 0x6D66
    ctx->r13 = ADD32(ctx->r13, 0X6D66);
    // 0x800A374C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A3750: lui         $t2, 0x81
    ctx->r10 = S32(0X81 << 16);
    // 0x800A3754: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800A3758:
    // 0x800A3758: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x800A375C: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x800A3760: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A3764: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800A3768: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A376C: bne         $t9, $a2, L_800A37F0
    if (ctx->r25 != ctx->r6) {
        // 0x800A3770: nop
    
            goto L_800A37F0;
    }
    // 0x800A3770: nop

    // 0x800A3774: bne         $t1, $s0, L_800A37AC
    if (ctx->r9 != ctx->r16) {
        // 0x800A3778: sb          $s0, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r16;
            goto L_800A37AC;
    }
    // 0x800A3778: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x800A377C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A3780: nop

    // 0x800A3784: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800A3788: nop

    // 0x800A378C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800A3790: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800A3794: nop

    // 0x800A3798: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800A379C: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800A37A0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A37A4: b           L_800A37DC
    // 0x800A37A8: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
        goto L_800A37DC;
    // 0x800A37A8: sh          $t3, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r11;
L_800A37AC:
    // 0x800A37AC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A37B0: nop

    // 0x800A37B4: lw          $t8, 0x38($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X38);
    // 0x800A37B8: nop

    // 0x800A37BC: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A37C0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800A37C4: nop

    // 0x800A37C8: and         $t6, $t9, $t4
    ctx->r14 = ctx->r25 & ctx->r12;
    // 0x800A37CC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800A37D0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A37D4: nop

    // 0x800A37D8: sh          $zero, 0x50($t7)
    MEM_H(0X50, ctx->r15) = 0;
L_800A37DC:
    // 0x800A37DC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A37E0: nop

    // 0x800A37E4: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A37E8: b           L_800A3818
    // 0x800A37EC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
        goto L_800A3818;
    // 0x800A37EC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A37F0:
    // 0x800A37F0: lbu         $t8, 0x0($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X0);
    // 0x800A37F4: nop

    // 0x800A37F8: bne         $t8, $a2, L_800A3818
    if (ctx->r24 != ctx->r6) {
        // 0x800A37FC: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800A3818;
    }
    // 0x800A37FC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800A3800: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x800A3804: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A3808: nop

    // 0x800A380C: lh          $a3, 0x28($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X28);
    // 0x800A3810: nop

    // 0x800A3814: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
L_800A3818:
    // 0x800A3818: bne         $at, $zero, L_800A3758
    if (ctx->r1 != 0) {
        // 0x800A381C: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_800A3758;
    }
    // 0x800A381C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
L_800A3820:
    // 0x800A3820: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3824: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x800A3828: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800A382C: addiu       $ra, $ra, 0x6D65
    ctx->r31 = ADD32(ctx->r31, 0X6D65);
    // 0x800A3830: addiu       $t5, $t5, 0x6D66
    ctx->r13 = ADD32(ctx->r13, 0X6D66);
    // 0x800A3834: sb          $s0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r16;
    // 0x800A3838: sb          $s1, 0x0($ra)
    MEM_B(0X0, ctx->r31) = ctx->r17;
    // 0x800A383C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3840: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x800A3844: sb          $t9, 0x6D67($at)
    MEM_B(0X6D67, ctx->r1) = ctx->r25;
    // 0x800A3848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A384C: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x800A3850: sb          $t6, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r14;
    // 0x800A3854: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3858: sb          $t7, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r15;
L_800A385C:
    // 0x800A385C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A3860:
    // 0x800A3860: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A3864: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A3868: jr          $ra
    // 0x800A386C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A386C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void music_voicelimit_change_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C30: jr          $ra
    // 0x80000C34: sb          $zero, -0x3990($at)
    MEM_B(-0X3990, ctx->r1) = 0;
    return;
    // 0x80000C34: sb          $zero, -0x3990($at)
    MEM_B(-0X3990, ctx->r1) = 0;
;}
RECOMP_FUNC void mode_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F43C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F440: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F444: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F44C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F450: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006F454: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006F458: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8006F45C:
    // 0x8006F45C: jal         0x8006A528
    // 0x8006F460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8006F460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006F464: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006F468: bne         $s0, $s2, L_8006F45C
    if (ctx->r16 != ctx->r18) {
        // 0x8006F46C: or          $s1, $s1, $v0
        ctx->r17 = ctx->r17 | ctx->r2;
            goto L_8006F45C;
    }
    // 0x8006F46C: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    // 0x8006F470: andi        $t6, $s1, 0x1000
    ctx->r14 = ctx->r17 & 0X1000;
    // 0x8006F474: beq         $t6, $zero, L_8006F488
    if (ctx->r14 == 0) {
        // 0x8006F478: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006F488;
    }
    // 0x8006F478: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F47C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006F480: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F484: sw          $t7, -0x26C($at)
    MEM_W(-0X26C, ctx->r1) = ctx->r15;
L_8006F488:
    // 0x8006F488: addiu       $v0, $v0, 0x3520
    ctx->r2 = ADD32(ctx->r2, 0X3520);
    // 0x8006F48C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006F490: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8006F494: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006F498: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8006F49C: bne         $at, $zero, L_8006F4B0
    if (ctx->r1 != 0) {
        // 0x8006F4A0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_8006F4B0;
    }
    // 0x8006F4A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006F4A4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x8006F4A8: jal         0x8006DA28
    // 0x8006F4AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    load_menu_with_level_background(rdram, ctx);
        goto after_1;
    // 0x8006F4AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
L_8006F4B0:
    // 0x8006F4B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F4B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F4B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F4BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F4C0: jr          $ra
    // 0x8006F4C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F4C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80026430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026430: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80026434: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026438: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002643C: lh          $t7, -0x2B46($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2B46);
    // 0x80026440: lh          $t6, -0x2B62($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2B62);
    // 0x80026444: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80026448: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002644C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80026450: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80026454: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x80026458: mtc1        $a3, $f28
    ctx->f28.u32l = ctx->r7;
    // 0x8002645C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80026460: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026464: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80026468: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002646C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80026470: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80026474: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80026478: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8002647C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80026480: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80026484: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80026488: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002648C: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80026490: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80026494: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80026498: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002649C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800264A0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800264A4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800264A8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800264AC: beq         $at, $zero, L_80026BB4
    if (ctx->r1 == 0) {
        // 0x800264B0: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_80026BB4;
    }
    // 0x800264B0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800264B4: sh          $zero, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = 0;
    // 0x800264B8: lh          $a0, 0x20($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X20);
    // 0x800264BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800264C0: blez        $a0, L_80026BB4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800264C4: addiu       $fp, $sp, 0xB8
        ctx->r30 = ADD32(ctx->r29, 0XB8);
            goto L_80026BB4;
    }
    // 0x800264C4: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x800264C8: lwc1        $f31, 0x5E78($at)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r1, 0X5E78);
    // 0x800264CC: lwc1        $f30, 0x5E7C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5E7C);
    // 0x800264D0: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x800264D4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800264D8: addiu       $s5, $sp, 0xD0
    ctx->r21 = ADD32(ctx->r29, 0XD0);
    // 0x800264DC: addiu       $s4, $sp, 0xDC
    ctx->r20 = ADD32(ctx->r29, 0XDC);
    // 0x800264E0: addiu       $s3, $sp, 0xE8
    ctx->r19 = ADD32(ctx->r29, 0XE8);
    // 0x800264E4: addiu       $s2, $sp, 0xF8
    ctx->r18 = ADD32(ctx->r29, 0XF8);
    // 0x800264E8: addiu       $s1, $sp, 0xC4
    ctx->r17 = ADD32(ctx->r29, 0XC4);
    // 0x800264EC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800264F0: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x800264F4: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x800264F8: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x800264FC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80026500:
    // 0x80026500: lh          $t9, 0x10E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X10E);
    // 0x80026504: lw          $t8, 0xC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0XC);
    // 0x80026508: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002650C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80026510: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80026514: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80026518: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002651C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80026520: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80026524: sh          $t7, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r15;
    // 0x80026528: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002652C: lh          $t7, 0x108($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X108);
    // 0x80026530: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x80026534: beq         $t8, $zero, L_80026548
    if (ctx->r24 == 0) {
        // 0x80026538: sll         $s7, $v1, 16
        ctx->r23 = S32(ctx->r3 << 16);
            goto L_80026548;
    }
    // 0x80026538: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
    // 0x8002653C: lh          $v1, 0x108($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X108);
    // 0x80026540: nop

    // 0x80026544: sll         $s7, $v1, 16
    ctx->r23 = S32(ctx->r3 << 16);
L_80026548:
    // 0x80026548: sra         $t6, $s7, 16
    ctx->r14 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8002654C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026550: beq         $at, $zero, L_80026B94
    if (ctx->r1 == 0) {
        // 0x80026554: or          $s7, $t6, $zero
        ctx->r23 = ctx->r14 | 0;
            goto L_80026B94;
    }
    // 0x80026554: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
L_80026558:
    // 0x80026558: lw          $t9, 0x4($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X4);
    // 0x8002655C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x80026560: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80026564: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80026568: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002656C: andi        $t9, $t7, 0x40
    ctx->r25 = ctx->r15 & 0X40;
    // 0x80026570: bne         $t9, $zero, L_80026B70
    if (ctx->r25 != 0) {
        // 0x80026574: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80026B70;
    }
    // 0x80026574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80026578:
    // 0x80026578: lw          $t8, 0x4($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X4);
    // 0x8002657C: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x80026580: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80026584: addu        $t9, $t7, $a3
    ctx->r25 = ADD32(ctx->r15, ctx->r7);
    // 0x80026588: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x8002658C: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80026590: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80026594: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80026598: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8002659C: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x800265A0: addu        $a1, $s5, $v0
    ctx->r5 = ADD32(ctx->r21, ctx->r2);
    // 0x800265A4: addu        $a2, $s2, $a3
    ctx->r6 = ADD32(ctx->r18, ctx->r7);
    // 0x800265A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800265AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800265B0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800265B4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800265B8: addu        $t7, $s4, $v0
    ctx->r15 = ADD32(ctx->r20, ctx->r2);
    // 0x800265BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800265C0: addu        $t8, $s1, $v0
    ctx->r24 = ADD32(ctx->r17, ctx->r2);
    // 0x800265C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800265C8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800265CC: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800265D0: nop

    // 0x800265D4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800265D8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800265DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800265E0: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800265E4: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x800265E8: nop

    // 0x800265EC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800265F0: nop

    // 0x800265F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800265F8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800265FC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80026600: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80026604: nop

    // 0x80026608: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8002660C: nop

    // 0x80026610: mul.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80026614: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80026618: add.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x8002661C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80026620: c.le.d      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.d <= ctx->f20.d;
    // 0x80026624: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80026628: bc1f        L_80026634
    if (!c1cs) {
        // 0x8002662C: nop
    
            goto L_80026634;
    }
    // 0x8002662C: nop

    // 0x80026630: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80026634:
    // 0x80026634: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80026638: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x8002663C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80026640: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80026644: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80026648: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002664C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026650: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x80026654: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80026658: nop

    // 0x8002665C: bc1f        L_80026668
    if (!c1cs) {
        // 0x80026660: nop
    
            goto L_80026668;
    }
    // 0x80026660: nop

    // 0x80026664: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80026668:
    // 0x80026668: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002666C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80026670: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026674: bne         $at, $zero, L_80026578
    if (ctx->r1 != 0) {
        // 0x80026678: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_80026578;
    }
    // 0x80026678: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8002667C: beq         $t6, $ra, L_80026688
    if (ctx->r14 == ctx->r31) {
        // 0x80026680: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80026688;
    }
    // 0x80026680: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80026684: bne         $t6, $at, L_80026B70
    if (ctx->r14 != ctx->r1) {
        // 0x80026688: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80026B70;
    }
L_80026688:
    // 0x80026688: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002668C: lwc1        $f8, -0x2B5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x80026690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026694: lwc1        $f4, -0x2B60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x80026698: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002669C: lwc1        $f22, -0x2B58($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x800266A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800266A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800266A8: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x800266AC: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
L_800266B0:
    // 0x800266B0: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    // 0x800266B4: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800266B8: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800266BC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800266C0: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800266C4: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800266C8: bne         $at, $zero, L_800266D4
    if (ctx->r1 != 0) {
        // 0x800266CC: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_800266D4;
    }
    // 0x800266CC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800266D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800266D4:
    // 0x800266D4: addu        $t9, $s2, $a1
    ctx->r25 = ADD32(ctx->r18, ctx->r5);
    // 0x800266D8: addu        $t6, $s2, $a3
    ctx->r14 = ADD32(ctx->r18, ctx->r7);
    // 0x800266DC: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x800266E0: lb          $t8, 0x0($t9)
    ctx->r24 = MEM_B(ctx->r25, 0X0);
    // 0x800266E4: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800266E8: beq         $t8, $t7, L_8002678C
    if (ctx->r24 == ctx->r15) {
        // 0x800266EC: addu        $t6, $s1, $v0
        ctx->r14 = ADD32(ctx->r17, ctx->r2);
            goto L_8002678C;
    }
    // 0x800266EC: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    // 0x800266F0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800266F4: addu        $t8, $s1, $v1
    ctx->r24 = ADD32(ctx->r17, ctx->r3);
    // 0x800266F8: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800266FC: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026700: addu        $t9, $s3, $v1
    ctx->r25 = ADD32(ctx->r19, ctx->r3);
    // 0x80026704: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80026708: addu        $t7, $s3, $v0
    ctx->r15 = ADD32(ctx->r19, ctx->r2);
    // 0x8002670C: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026710: lwc1        $f2, 0x0($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026714: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80026718: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8002671C: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80026720: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x80026724: addu        $t7, $s4, $v1
    ctx->r15 = ADD32(ctx->r20, ctx->r3);
    // 0x80026728: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8002672C: addu        $t9, $fp, $a0
    ctx->r25 = ADD32(ctx->r30, ctx->r4);
    // 0x80026730: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026734: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026738: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8002673C: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80026740: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026744: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026748: addu        $t6, $t4, $a0
    ctx->r14 = ADD32(ctx->r12, ctx->r4);
    // 0x8002674C: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80026750: addu        $t8, $s5, $v0
    ctx->r24 = ADD32(ctx->r21, ctx->r2);
    // 0x80026754: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80026758: addu        $t7, $s5, $v1
    ctx->r15 = ADD32(ctx->r21, ctx->r3);
    // 0x8002675C: add.s       $f14, $f10, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80026760: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x80026764: swc1        $f14, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f14.u32l;
    // 0x80026768: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002676C: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026770: addu        $t9, $t5, $a0
    ctx->r25 = ADD32(ctx->r13, ctx->r4);
    // 0x80026774: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80026778: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8002677C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80026780: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026784: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80026788: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
L_8002678C:
    // 0x8002678C: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x80026790: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026794: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80026798: bne         $at, $zero, L_800266B0
    if (ctx->r1 != 0) {
        // 0x8002679C: or          $a3, $t7, $zero
        ctx->r7 = ctx->r15 | 0;
            goto L_800266B0;
    }
    // 0x8002679C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800267A0: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800267A4: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800267A8: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800267AC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800267B0: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800267B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800267B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800267BC: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800267C0: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800267C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800267C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800267CC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800267D0: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800267D4: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800267D8: add.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800267DC: lwc1        $f9, 0x5E80($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5E80);
    // 0x800267E0: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x800267E4: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800267E8: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800267EC: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800267F0: lwc1        $f8, 0x5E84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E84);
    // 0x800267F4: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800267F8: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x800267FC: add.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80026800: bc1f        L_80026814
    if (!c1cs) {
        // 0x80026804: swc1        $f12, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
            goto L_80026814;
    }
    // 0x80026804: swc1        $f12, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f12.u32l;
    // 0x80026808: sll         $v0, $ra, 24
    ctx->r2 = S32(ctx->r31 << 24);
    // 0x8002680C: sra         $t9, $v0, 24
    ctx->r25 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80026810: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80026814:
    // 0x80026814: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x80026818: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002681C: bc1f        L_80026830
    if (!c1cs) {
        // 0x80026820: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80026830;
    }
    // 0x80026820: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026824: ori         $t6, $v0, 0x2
    ctx->r14 = ctx->r2 | 0X2;
    // 0x80026828: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x8002682C: sra         $v0, $t8, 24
    ctx->r2 = S32(SIGNED(ctx->r24) >> 24);
L_80026830:
    // 0x80026830: lwc1        $f5, 0x5E88($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5E88);
    // 0x80026834: lwc1        $f4, 0x5E8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E8C);
    // 0x80026838: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8002683C: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80026840: nop

    // 0x80026844: bc1f        L_80026858
    if (!c1cs) {
        // 0x80026848: nop
    
            goto L_80026858;
    }
    // 0x80026848: nop

    // 0x8002684C: sll         $v1, $ra, 24
    ctx->r3 = S32(ctx->r31 << 24);
    // 0x80026850: sra         $t9, $v1, 24
    ctx->r25 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80026854: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80026858:
    // 0x80026858: c.lt.d      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.d < ctx->f0.d;
    // 0x8002685C: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x80026860: bc1f        L_8002686C
    if (!c1cs) {
        // 0x80026864: sll         $t8, $t6, 24
        ctx->r24 = S32(ctx->r14 << 24);
            goto L_8002686C;
    }
    // 0x80026864: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x80026868: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
L_8002686C:
    // 0x8002686C: or          $t9, $v1, $v0
    ctx->r25 = ctx->r3 | ctx->r2;
    // 0x80026870: bne         $t9, $zero, L_80026890
    if (ctx->r25 != 0) {
        // 0x80026874: nop
    
            goto L_80026890;
    }
    // 0x80026874: nop

    // 0x80026878: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x8002687C: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026880: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80026884: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x80026888: b           L_800269CC
    // 0x8002688C: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
        goto L_800269CC;
    // 0x8002688C: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
L_80026890:
    // 0x80026890: sb          $v0, 0xF8($sp)
    MEM_B(0XF8, ctx->r29) = ctx->r2;
    // 0x80026894: beq         $v1, $v0, L_800269CC
    if (ctx->r3 == ctx->r2) {
        // 0x80026898: sb          $v1, 0xF9($sp)
        MEM_B(0XF9, ctx->r29) = ctx->r3;
            goto L_800269CC;
    }
    // 0x80026898: sb          $v1, 0xF9($sp)
    MEM_B(0XF9, ctx->r29) = ctx->r3;
    // 0x8002689C: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800268A0: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800268A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800268A8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800268AC: sll         $s0, $ra, 16
    ctx->r16 = S32(ctx->r31 << 16);
    // 0x800268B0: bc1f        L_800268C8
    if (!c1cs) {
        // 0x800268B4: addu        $t9, $s2, $a3
        ctx->r25 = ADD32(ctx->r18, ctx->r7);
            goto L_800268C8;
    }
    // 0x800268B4: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
    // 0x800268B8: sll         $a3, $ra, 16
    ctx->r7 = S32(ctx->r31 << 16);
    // 0x800268BC: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800268C0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800268C4: addu        $t9, $s2, $a3
    ctx->r25 = ADD32(ctx->r18, ctx->r7);
L_800268C8:
    // 0x800268C8: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x800268CC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800268D0: bne         $ra, $t6, L_80026948
    if (ctx->r31 != ctx->r14) {
        // 0x800268D4: subu        $a2, $ra, $a3
        ctx->r6 = SUB32(ctx->r31, ctx->r7);
            goto L_80026948;
    }
    // 0x800268D4: subu        $a2, $ra, $a3
    ctx->r6 = SUB32(ctx->r31, ctx->r7);
    // 0x800268D8: subu        $a1, $ra, $a3
    ctx->r5 = SUB32(ctx->r31, ctx->r7);
    // 0x800268DC: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800268E0: addu        $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x800268E4: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800268E8: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800268EC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800268F0: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x800268F4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x800268F8: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800268FC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026900: sub.d       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = ctx->f4.d - ctx->f30.d;
    // 0x80026904: addu        $t8, $fp, $t9
    ctx->r24 = ADD32(ctx->r30, ctx->r25);
    // 0x80026908: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8002690C: addu        $a0, $fp, $v0
    ctx->r4 = ADD32(ctx->r30, ctx->r2);
    // 0x80026910: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80026914: nop

    // 0x80026918: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8002691C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026920: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80026924: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80026928: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8002692C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80026930: nop

    // 0x80026934: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80026938: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8002693C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80026940: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80026944: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80026948:
    // 0x80026948: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002694C: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026950: addu        $t6, $s2, $t9
    ctx->r14 = ADD32(ctx->r18, ctx->r25);
    // 0x80026954: lb          $t8, 0x0($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X0);
    // 0x80026958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002695C: bne         $t8, $at, L_800269C8
    if (ctx->r24 != ctx->r1) {
        // 0x80026960: sra         $t6, $s0, 16
        ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
            goto L_800269C8;
    }
    // 0x80026960: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026964: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    // 0x80026968: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x8002696C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80026970: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80026974: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
    // 0x80026978: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002697C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80026980: sub.d       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f10.d - ctx->f30.d;
    // 0x80026984: addu        $t9, $fp, $v0
    ctx->r25 = ADD32(ctx->r30, ctx->r2);
    // 0x80026988: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8002698C: addu        $a0, $fp, $a1
    ctx->r4 = ADD32(ctx->r30, ctx->r5);
    // 0x80026990: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80026994: nop

    // 0x80026998: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x8002699C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800269A0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800269A4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800269A8: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800269AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800269B0: nop

    // 0x800269B4: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800269B8: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800269BC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800269C0: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800269C4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_800269C8:
    // 0x800269C8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_800269CC:
    // 0x800269CC: beq         $s0, $zero, L_80026B70
    if (ctx->r16 == 0) {
        // 0x800269D0: sll         $t7, $s7, 3
        ctx->r15 = S32(ctx->r23 << 3);
            goto L_80026B70;
    }
    // 0x800269D0: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x800269D4: lw          $t8, 0x14($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X14);
    // 0x800269D8: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800269DC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800269E0: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800269E4: lw          $t9, 0x18($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X18);
    // 0x800269E8: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x800269EC: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800269F0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800269F4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800269F8: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800269FC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80026A00: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80026A04: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026A08: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80026A0C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80026A10: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80026A14: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80026A18: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026A1C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80026A20: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80026A24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026A28: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80026A2C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80026A30: nop

    // 0x80026A34: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80026A38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026A3C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80026A40: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026A44: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80026A48: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026A4C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80026A50: c.lt.d      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.d < ctx->f4.d;
    // 0x80026A54: nop

    // 0x80026A58: bc1f        L_80026A68
    if (!c1cs) {
        // 0x80026A5C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80026A68;
    }
    // 0x80026A5C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80026A60: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80026A64: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
L_80026A68:
    // 0x80026A68: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80026A6C: sll         $s0, $t8, 16
    ctx->r16 = S32(ctx->r24 << 16);
    // 0x80026A70: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026A74: bc1f        L_80026A8C
    if (!c1cs) {
        // 0x80026A78: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_80026A8C;
    }
    // 0x80026A78: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026A7C: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80026A80: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x80026A84: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80026A88: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
L_80026A8C:
    // 0x80026A8C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80026A90: ori         $t9, $s0, 0x8
    ctx->r25 = ctx->r16 | 0X8;
    // 0x80026A94: bc1f        L_80026AA0
    if (!c1cs) {
        // 0x80026A98: sll         $t6, $t9, 16
        ctx->r14 = S32(ctx->r25 << 16);
            goto L_80026AA0;
    }
    // 0x80026A98: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80026A9C: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
L_80026AA0:
    // 0x80026AA0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80026AA4: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80026AA8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80026AAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026AB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026AB4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80026AB8: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026ABC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026AC0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80026AC4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026AC8: sh          $t1, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r9;
    // 0x80026ACC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80026AD0: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80026AD4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80026AD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026ADC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026AE0: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026AE4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026AE8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026AEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80026AF0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80026AF4: jal         0x80026C14
    // 0x80026AF8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x80026AF8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80026AFC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80026B00: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80026B04: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80026B08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B10: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80026B14: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026B18: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80026B1C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80026B20: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80026B24: nop

    // 0x80026B28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026B2C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80026B30: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80026B34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026B38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026B3C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026B40: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80026B44: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80026B48: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026B4C: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80026B50: jal         0x80026C14
    // 0x80026B54: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026B54: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_1:
    // 0x80026B58: lh          $t1, 0x10A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X10A);
    // 0x80026B5C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80026B60: addiu       $t3, $sp, 0xB0
    ctx->r11 = ADD32(ctx->r29, 0XB0);
    // 0x80026B64: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80026B68: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x80026B6C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_80026B70:
    // 0x80026B70: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80026B74: lh          $t6, 0x108($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X108);
    // 0x80026B78: sll         $t7, $s7, 16
    ctx->r15 = S32(ctx->r23 << 16);
    // 0x80026B7C: sra         $s7, $t7, 16
    ctx->r23 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80026B80: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026B84: bne         $at, $zero, L_80026558
    if (ctx->r1 != 0) {
        // 0x80026B88: nop
    
            goto L_80026558;
    }
    // 0x80026B88: nop

    // 0x80026B8C: lh          $a0, 0x20($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X20);
    // 0x80026B90: nop

L_80026B94:
    // 0x80026B94: lh          $v0, 0x10E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X10E);
    // 0x80026B98: nop

    // 0x80026B9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026BA0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80026BA4: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026BA8: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80026BAC: bne         $at, $zero, L_80026500
    if (ctx->r1 != 0) {
        // 0x80026BB0: sh          $t7, 0x10E($sp)
        MEM_H(0X10E, ctx->r29) = ctx->r15;
            goto L_80026500;
    }
    // 0x80026BB0: sh          $t7, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = ctx->r15;
L_80026BB4:
    // 0x80026BB4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80026BB8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026BBC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80026BC0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026BC4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026BC8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026BCC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80026BD0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026BD4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026BD8: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80026BDC: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80026BE0: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80026BE4: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80026BE8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80026BEC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80026BF0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80026BF4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80026BF8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80026BFC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80026C00: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80026C04: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80026C08: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80026C0C: jr          $ra
    // 0x80026C10: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x80026C10: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void alCSPStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C85D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C85D8: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800C85DC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C85E0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C85E4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C85E8: jal         0x800C91AC
    // 0x800C85EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C85EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C85F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C85F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C85F8: jr          $ra
    // 0x800C85FC: nop

    return;
    // 0x800C85FC: nop

;}
RECOMP_FUNC void func_800B92F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B92F4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800B92F8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B92FC: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800B9300: addiu       $s5, $s5, -0x6038
    ctx->r21 = ADD32(ctx->r21, -0X6038);
    // 0x800B9304: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B9308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B930C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800B9310: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B9318: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B931C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B9320: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B9328: lwc1        $f6, 0x44($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B932C: lw          $t8, 0x30D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30D8);
    // 0x800B9330: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B9334: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9338: lh          $t2, -0x5A18($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X5A18);
    // 0x800B933C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B9340: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B9344: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800B9348: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800B934C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B9350: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9354: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B9358: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B935C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B9360: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B9364: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B9368: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B936C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B9370: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B9374: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B9378: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B937C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B9380: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B9384: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x800B9388: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800B938C: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x800B9390: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800B9394: beq         $t2, $at, L_800B9768
    if (ctx->r10 == ctx->r1) {
        // 0x800B9398: div.s       $f22, $f8, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_800B9768;
    }
    // 0x800B9398: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B939C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B93A0: addiu       $t3, $t3, -0x5A18
    ctx->r11 = ADD32(ctx->r11, -0X5A18);
    // 0x800B93A4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800B93A8: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x800B93AC: addiu       $s6, $s6, -0x5A18
    ctx->r22 = ADD32(ctx->r22, -0X5A18);
    // 0x800B93B0: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
L_800B93B4:
    // 0x800B93B4: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800B93B8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800B93BC: bne         $t4, $v0, L_800B9758
    if (ctx->r12 != ctx->r2) {
        // 0x800B93C0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800B9758;
    }
    // 0x800B93C0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B93C4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B93C8: lw          $t1, -0x5FE8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5FE8);
    // 0x800B93CC: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x800B93D0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B93D4: lw          $t5, 0x30D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30D4);
    // 0x800B93D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B93DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B93E0: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800B93E4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B93E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B93EC: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B93F0: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800B93F4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B93F8: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800B93FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B9400: lw          $a3, 0x30E4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X30E4);
    // 0x800B9404: lw          $a2, 0x3070($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3070);
    // 0x800B9408: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x800B940C: beq         $a1, $zero, L_800B9460
    if (ctx->r5 == 0) {
        // 0x800B9410: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800B9460;
    }
    // 0x800B9410: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B9414: lh          $v0, 0x2($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X2);
    // 0x800B9418: nop

    // 0x800B941C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800B9420: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9424: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x800B9428: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800B942C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B9430: srlv        $t5, $a0, $t7
    ctx->r13 = S32(U32(ctx->r4) >> (ctx->r15 & 31));
    // 0x800B9434: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x800B9438: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B943C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x800B9440: mflo        $t3
    ctx->r11 = lo;
    // 0x800B9444: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x800B9448: nop

    // 0x800B944C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9450: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9454: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x800B9458: b           L_800B9478
    // 0x800B945C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
        goto L_800B9478;
    // 0x800B945C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9460:
    // 0x800B9460: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800B9464: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800B9468: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x800B946C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x800B9470: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x800B9474: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
L_800B9478:
    // 0x800B9478: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x800B947C: lh          $a0, 0x6($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X6);
    // 0x800B9480: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9484: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800B9488: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x800B948C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B9490: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x800B9494: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800B9498: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800B949C: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x800B94A0: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800B94A4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B94A8: bltz        $v1, L_800B9758
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B94AC: sw          $t7, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->r15;
            goto L_800B9758;
    }
    // 0x800B94AC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x800B94B0: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B94B4: nop

L_800B94B8:
    // 0x800B94B8: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B94BC: lh          $s1, 0x4($s6)
    ctx->r17 = MEM_H(ctx->r22, 0X4);
    // 0x800B94C0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B94C4: addiu       $t3, $t3, 0x304C
    ctx->r11 = ADD32(ctx->r11, 0X304C);
    // 0x800B94C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B94CC: sll         $s4, $s7, 2
    ctx->r20 = S32(ctx->r23 << 2);
    // 0x800B94D0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B94D4: addu        $s2, $t5, $s1
    ctx->r18 = ADD32(ctx->r13, ctx->r17);
    // 0x800B94D8: bltz        $v1, L_800B9714
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B94DC: sll         $t5, $s7, 2
        ctx->r13 = S32(ctx->r23 << 2);
            goto L_800B9714;
    }
    // 0x800B94DC: sll         $t5, $s7, 2
    ctx->r13 = S32(ctx->r23 << 2);
    // 0x800B94E0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800B94E4: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800B94E8: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800B94EC: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800B94F0: addu        $t5, $t5, $s7
    ctx->r13 = ADD32(ctx->r13, ctx->r23);
    // 0x800B94F4: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800B94F8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800B94FC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B9500: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800B9504: addu        $a3, $t1, $t3
    ctx->r7 = ADD32(ctx->r9, ctx->r11);
    // 0x800B9508: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    // 0x800B950C: addu        $t0, $t2, $t6
    ctx->r8 = ADD32(ctx->r10, ctx->r14);
    // 0x800B9510: addu        $s0, $t7, $t5
    ctx->r16 = ADD32(ctx->r15, ctx->r13);
L_800B9514:
    // 0x800B9514: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9518: lw          $t8, 0x3044($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3044);
    // 0x800B951C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x800B9520: addu        $v1, $t8, $t1
    ctx->r3 = ADD32(ctx->r24, ctx->r9);
    // 0x800B9524: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B9528: lw          $v0, 0x3040($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3040);
    // 0x800B952C: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800B9530: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800B9534: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800B9538: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800B953C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B9540: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x800B9544: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B9548: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800B954C: lwc1        $f6, 0x40($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X40);
    // 0x800B9550: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B9554: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9558: lw          $t5, 0x3188($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3188);
    // 0x800B955C: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B9560: blez        $t5, L_800B9598
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B9564: nop
    
            goto L_800B9598;
    }
    // 0x800B9564: nop

    // 0x800B9568: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800B956C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9570: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800B9574: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800B9578: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B957C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800B9580: addu        $a1, $s3, $t8
    ctx->r5 = ADD32(ctx->r19, ctx->r24);
    // 0x800B9584: jal         0x800BEFC4
    // 0x800B9588: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800B9588: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    after_0:
    // 0x800B958C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800B9590: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800B9594: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_800B9598:
    // 0x800B9598: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B959C: lw          $t2, 0x3178($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3178);
    // 0x800B95A0: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x800B95A4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800B95A8: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x800B95AC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800B95B0: addu        $t4, $t9, $s4
    ctx->r12 = ADD32(ctx->r25, ctx->r20);
    // 0x800B95B4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800B95B8: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800B95BC: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x800B95C0: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x800B95C4: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B95C8: sw          $t5, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r13;
    // 0x800B95CC: beq         $at, $zero, L_800B95F0
    if (ctx->r1 == 0) {
        // 0x800B95D0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800B95F0;
    }
    // 0x800B95D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800B95D4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B95D8: lwc1        $f10, 0x44($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X44);
    // 0x800B95DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B95E0: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800B95E4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B95E8: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B95EC: nop

L_800B95F0:
    // 0x800B95F0: lwc1        $f8, 0x48($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X48);
    // 0x800B95F4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B95F8: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800B95FC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800B9600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B9604: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B9608: nop

    // 0x800B960C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B9610: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B9614: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9618: nop

    // 0x800B961C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B9620: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800B9624: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B9628: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800B962C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800B9630: bne         $at, $zero, L_800B9640
    if (ctx->r1 != 0) {
        // 0x800B9634: nop
    
            goto L_800B9640;
    }
    // 0x800B9634: nop

    // 0x800B9638: b           L_800B964C
    // 0x800B963C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_800B964C;
    // 0x800B963C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_800B9640:
    // 0x800B9640: bgez        $v0, L_800B964C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B9644: nop
    
            goto L_800B964C;
    }
    // 0x800B9644: nop

    // 0x800B9648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B964C:
    // 0x800B964C: lh          $t9, 0x2($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2);
    // 0x800B9650: subu        $t3, $fp, $v0
    ctx->r11 = SUB32(ctx->r30, ctx->r2);
    // 0x800B9654: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x800B9658: lbu         $t2, 0x14($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X14);
    // 0x800B965C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B9660: multu       $t3, $t2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9664: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B9668: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B966C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B9670: nop

    // 0x800B9674: cvt.w.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = CVT_W_S(ctx->f20.fl);
    // 0x800B9678: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B967C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B9680: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B9684: mflo        $t6
    ctx->r14 = lo;
    // 0x800B9688: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x800B968C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800B9690: slti        $at, $v0, 0xC0
    ctx->r1 = SIGNED(ctx->r2) < 0XC0 ? 1 : 0;
    // 0x800B9694: beq         $at, $zero, L_800B96A4
    if (ctx->r1 == 0) {
        // 0x800B9698: subu        $v1, $fp, $v0
        ctx->r3 = SUB32(ctx->r30, ctx->r2);
            goto L_800B96A4;
    }
    // 0x800B9698: subu        $v1, $fp, $v0
    ctx->r3 = SUB32(ctx->r30, ctx->r2);
    // 0x800B969C: b           L_800B96AC
    // 0x800B96A0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
        goto L_800B96AC;
    // 0x800B96A0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B96A4:
    // 0x800B96A4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B96A8: andi        $v1, $t1, 0xFF
    ctx->r3 = ctx->r9 & 0XFF;
L_800B96AC:
    // 0x800B96AC: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B96B0: sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // 0x800B96B4: sb          $v1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r3;
    // 0x800B96B8: beq         $at, $zero, L_800B96D0
    if (ctx->r1 == 0) {
        // 0x800B96BC: sb          $v1, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r3;
            goto L_800B96D0;
    }
    // 0x800B96BC: sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // 0x800B96C0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B96C4: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x800B96C8: b           L_800B96D4
    // 0x800B96CC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B96D4;
    // 0x800B96CC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B96D0:
    // 0x800B96D0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
L_800B96D4:
    // 0x800B96D4: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    // 0x800B96D8: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800B96DC: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x800B96E0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B96E4: bne         $at, $zero, L_800B96F4
    if (ctx->r1 != 0) {
        // 0x800B96E8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800B96F4;
    }
    // 0x800B96E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B96EC: subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // 0x800B96F0: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
L_800B96F4:
    // 0x800B96F4: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B96F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B96FC: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800B9700: beq         $at, $zero, L_800B9514
    if (ctx->r1 == 0) {
        // 0x800B9704: nop
    
            goto L_800B9514;
    }
    // 0x800B9704: nop

    // 0x800B9708: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x800B970C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800B9710: nop

L_800B9714:
    // 0x800B9714: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B9718: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B971C: bne         $at, $zero, L_800B9728
    if (ctx->r1 != 0) {
        // 0x800B9720: nop
    
            goto L_800B9728;
    }
    // 0x800B9720: nop

    // 0x800B9724: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_800B9728:
    // 0x800B9728: beq         $a1, $zero, L_800B9744
    if (ctx->r5 == 0) {
        // 0x800B972C: lw          $t6, 0xAC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XAC);
            goto L_800B9744;
    }
    // 0x800B972C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800B9730: lw          $t3, 0x8($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X8);
    // 0x800B9734: nop

    // 0x800B9738: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x800B973C: sw          $t2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r10;
    // 0x800B9740: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
L_800B9744:
    // 0x800B9744: nop

    // 0x800B9748: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B974C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9750: beq         $at, $zero, L_800B94B8
    if (ctx->r1 == 0) {
        // 0x800B9754: sw          $t7, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r15;
            goto L_800B94B8;
    }
    // 0x800B9754: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
L_800B9758:
    // 0x800B9758: lh          $v0, 0xC($s6)
    ctx->r2 = MEM_H(ctx->r22, 0XC);
    // 0x800B975C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B9760: bne         $v0, $at, L_800B93B4
    if (ctx->r2 != ctx->r1) {
        // 0x800B9764: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_800B93B4;
    }
    // 0x800B9764: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_800B9768:
    // 0x800B9768: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B976C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9770: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B9774: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B9778: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B977C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B9780: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9784: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B9788: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B978C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B9790: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B9794: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B9798: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B979C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B97A0: jr          $ra
    // 0x800B97A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800B97A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void init_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800249F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800249F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800249F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800249FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80024A00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80024A04: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80024A08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80024A0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80024A10: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80024A14: jal         0x8006BDB0
    // 0x80024A18: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80024A18: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x80024A1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024A20: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024A24: addiu       $a1, $a1, -0x36E4
    ctx->r5 = ADD32(ctx->r5, -0X36E4);
    // 0x80024A28: addiu       $a0, $a0, -0x4F08
    ctx->r4 = ADD32(ctx->r4, -0X4F08);
    // 0x80024A2C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80024A30: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80024A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A38: sw          $zero, -0x4F00($at)
    MEM_W(-0X4F00, ctx->r1) = 0;
    // 0x80024A3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A40: sw          $zero, -0x4EFC($at)
    MEM_W(-0X4EFC, ctx->r1) = 0;
    // 0x80024A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A48: sw          $zero, -0x4EF8($at)
    MEM_W(-0X4EF8, ctx->r1) = 0;
    // 0x80024A4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A50: sw          $zero, -0x4EF4($at)
    MEM_W(-0X4EF4, ctx->r1) = 0;
    // 0x80024A54: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80024A58: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024A5C: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024A60: nop

    // 0x80024A64: beq         $v1, $at, L_80024A70
    if (ctx->r3 == ctx->r1) {
        // 0x80024A68: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80024A70;
    }
    // 0x80024A68: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024A6C: bne         $v1, $at, L_80024A78
    if (ctx->r3 != ctx->r1) {
        // 0x80024A70: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80024A78;
    }
L_80024A70:
    // 0x80024A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80024A74: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80024A78:
    // 0x80024A78: jal         0x8002C0C4
    // 0x80024A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    generate_track(rdram, ctx);
        goto after_1;
    // 0x80024A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80024A80: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80024A84: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024A88: addiu       $s0, $s0, -0x2C7C
    ctx->r16 = ADD32(ctx->r16, -0X2C7C);
    // 0x80024A8C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80024A90: beq         $at, $zero, L_80024B0C
    if (ctx->r1 == 0) {
        // 0x80024A94: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80024B0C;
    }
    // 0x80024A94: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024A98: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024A9C: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x80024AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024AA4: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024AA8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024AAC: blez        $a0, L_80024B0C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024AB0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80024B0C;
    }
    // 0x80024AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024AB4:
    // 0x80024AB4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80024AB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80024ABC: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80024AC0: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x80024AC4: nop

    // 0x80024AC8: beq         $t1, $zero, L_80024B04
    if (ctx->r9 == 0) {
        // 0x80024ACC: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80024B04;
    }
    // 0x80024ACC: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024AD0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80024AD4: nop

    // 0x80024AD8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80024ADC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024AE0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80024AE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024AE8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80024AEC: sb          $a1, 0x2B($t5)
    MEM_B(0X2B, ctx->r13) = ctx->r5;
    // 0x80024AF0: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x80024AF4: nop

    // 0x80024AF8: lh          $a0, 0x1A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X1A);
    // 0x80024AFC: nop

    // 0x80024B00: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_80024B04:
    // 0x80024B04: bne         $at, $zero, L_80024AB4
    if (ctx->r1 != 0) {
        // 0x80024B08: addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
            goto L_80024AB4;
    }
    // 0x80024B08: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
L_80024B0C:
    // 0x80024B0C: jal         0x8009EC80
    // 0x80024B10: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x80024B10: nop

    after_2:
    // 0x80024B14: beq         $v0, $zero, L_80024B44
    if (ctx->r2 == 0) {
        // 0x80024B18: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80024B44;
    }
    // 0x80024B18: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80024B1C: lw          $t6, -0x36E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36E4);
    // 0x80024B20: nop

    // 0x80024B24: lb          $v1, 0x4C($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X4C);
    // 0x80024B28: nop

    // 0x80024B2C: beq         $v1, $zero, L_80024B3C
    if (ctx->r3 == 0) {
        // 0x80024B30: andi        $t7, $v1, 0x40
        ctx->r15 = ctx->r3 & 0X40;
            goto L_80024B3C;
    }
    // 0x80024B30: andi        $t7, $v1, 0x40
    ctx->r15 = ctx->r3 & 0X40;
    // 0x80024B34: beq         $t7, $zero, L_80024B48
    if (ctx->r15 == 0) {
        // 0x80024B38: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80024B48;
    }
    // 0x80024B38: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B3C:
    // 0x80024B3C: b           L_80024B50
    // 0x80024B40: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80024B50;
    // 0x80024B40: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80024B44:
    // 0x80024B44: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80024B48:
    // 0x80024B48: nop

    // 0x80024B4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80024B50:
    // 0x80024B50: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80024B54: nop

    // 0x80024B58: beq         $t8, $zero, L_80024B74
    if (ctx->r24 == 0) {
        // 0x80024B5C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024B74;
    }
    // 0x80024B5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024B60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80024B64: lw          $a1, -0x36E4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36E4);
    // 0x80024B68: lw          $a0, -0x36E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36E8);
    // 0x80024B6C: jal         0x800B82B4
    // 0x80024B70: nop

    waves_init(rdram, ctx);
        goto after_3;
    // 0x80024B70: nop

    after_3:
L_80024B74:
    // 0x80024B74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024B78: jal         0x8006652C
    // 0x80024B7C: nop

    cam_set_layout(rdram, ctx);
        goto after_4;
    // 0x80024B7C: nop

    after_4:
    // 0x80024B80: jal         0x80027FC4
    // 0x80024B84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skydome_spawn(rdram, ctx);
        goto after_5;
    // 0x80024B84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80024B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024B8C: sw          $zero, -0x4EF0($at)
    MEM_W(-0X4EF0, ctx->r1) = 0;
    // 0x80024B90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024B94: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80024B98: jal         0x80011390
    // 0x80024B9C: sw          $t9, -0x4EEC($at)
    MEM_W(-0X4EEC, ctx->r1) = ctx->r25;
    path_enable(rdram, ctx);
        goto after_6;
    // 0x80024B9C: sw          $t9, -0x4EEC($at)
    MEM_W(-0X4EEC, ctx->r1) = ctx->r25;
    after_6:
    // 0x80024BA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80024BA4: jal         0x8000C8F8
    // 0x80024BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    track_spawn_objects(rdram, ctx);
        goto after_7;
    // 0x80024BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80024BAC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80024BB0: jal         0x8000C8F8
    // 0x80024BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    track_spawn_objects(rdram, ctx);
        goto after_8;
    // 0x80024BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80024BB8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80024BBC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80024BC0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80024BC4: addiu       $s3, $s3, -0x2C84
    ctx->r19 = ADD32(ctx->r19, -0X2C84);
    // 0x80024BC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80024BCC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80024BD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80024BD4: jal         0x8000CC7C
    // 0x80024BD8: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    track_setup_racers(rdram, ctx);
        goto after_9;
    // 0x80024BD8: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    after_9:
    // 0x80024BDC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80024BE0: jal         0x8000B020
    // 0x80024BE4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    racerfx_alloc(rdram, ctx);
        goto after_10;
    // 0x80024BE4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x80024BE8: bne         $s1, $zero, L_80024C0C
    if (ctx->r17 != 0) {
        // 0x80024BEC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80024C0C;
    }
    // 0x80024BEC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024BF0: bne         $s0, $zero, L_80024C0C
    if (ctx->r16 != 0) {
        // 0x80024BF4: nop
    
            goto L_80024C0C;
    }
    // 0x80024BF4: nop

    // 0x80024BF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80024BFC: jal         0x800C01D8
    // 0x80024C00: addiu       $a0, $a0, -0x3784
    ctx->r4 = ADD32(ctx->r4, -0X3784);
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x80024C00: addiu       $a0, $a0, -0x3784
    ctx->r4 = ADD32(ctx->r4, -0X3784);
    after_11:
    // 0x80024C04: b           L_80024C18
    // 0x80024C08: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
        goto L_80024C18;
    // 0x80024C08: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C0C:
    // 0x80024C0C: jal         0x800C01D8
    // 0x80024C10: addiu       $a0, $a0, -0x378C
    ctx->r4 = ADD32(ctx->r4, -0X378C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80024C10: addiu       $a0, $a0, -0x378C
    ctx->r4 = ADD32(ctx->r4, -0X378C);
    after_12:
    // 0x80024C14: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80024C18:
    // 0x80024C18: jal         0x8006652C
    // 0x80024C1C: nop

    cam_set_layout(rdram, ctx);
        goto after_13;
    // 0x80024C1C: nop

    after_13:
    // 0x80024C20: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80024C24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024C28: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
    // 0x80024C2C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024C30: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024C34: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024C38: sw          $zero, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = 0;
    // 0x80024C3C: addiu       $s0, $s0, -0x2CC8
    ctx->r16 = ADD32(ctx->r16, -0X2CC8);
    // 0x80024C40: addiu       $s2, $s2, -0x2CE0
    ctx->r18 = ADD32(ctx->r18, -0X2CE0);
    // 0x80024C44: addiu       $s1, $s1, -0x2CB0
    ctx->r17 = ADD32(ctx->r17, -0X2CB0);
    // 0x80024C48: ori         $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 | 0XFF;
    // 0x80024C4C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80024C50:
    // 0x80024C50: addiu       $a0, $zero, 0xC80
    ctx->r4 = ADD32(0, 0XC80);
    // 0x80024C54: jal         0x80070C9C
    // 0x80024C58: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x80024C58: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x80024C5C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80024C60: addiu       $a0, $zero, 0x3200
    ctx->r4 = ADD32(0, 0X3200);
    // 0x80024C64: jal         0x80070C9C
    // 0x80024C68: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x80024C68: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80024C6C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80024C70: addiu       $a0, $zero, 0x4E20
    ctx->r4 = ADD32(0, 0X4E20);
    // 0x80024C74: jal         0x80070C9C
    // 0x80024C78: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80024C78: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_16:
    // 0x80024C7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80024C80: addiu       $t2, $t2, -0x2CB8
    ctx->r10 = ADD32(ctx->r10, -0X2CB8);
    // 0x80024C84: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80024C88: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80024C8C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80024C90: bne         $s0, $t2, L_80024C50
    if (ctx->r16 != ctx->r10) {
        // 0x80024C94: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80024C50;
    }
    // 0x80024C94: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80024C98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80024C9C: addiu       $s0, $s0, -0x4F38
    ctx->r16 = ADD32(ctx->r16, -0X4F38);
    // 0x80024CA0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024CA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024CAC: jal         0x8002D8DC
    // 0x80024CB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_17;
    // 0x80024CB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80024CB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024CB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024CBC: jal         0x8002D8DC
    // 0x80024CC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_18;
    // 0x80024CC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80024CC4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80024CC8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80024CCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024CD4: jal         0x8002D8DC
    // 0x80024CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_19;
    // 0x80024CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80024CDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024CE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80024CE4: jal         0x8002D8DC
    // 0x80024CE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    shadow_update(rdram, ctx);
        goto after_20;
    // 0x80024CE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80024CEC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024CF0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024CF4: lw          $v0, -0x36E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E4);
    // 0x80024CF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024CFC: lbu         $t4, 0xB7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XB7);
    // 0x80024D00: nop

    // 0x80024D04: beq         $t4, $zero, L_80024D3C
    if (ctx->r12 == 0) {
        // 0x80024D08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80024D3C;
    }
    // 0x80024D08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024D0C: lbu         $t5, 0xB4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XB4);
    // 0x80024D10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80024D14: sb          $t5, -0x4F1F($at)
    MEM_B(-0X4F1F, ctx->r1) = ctx->r13;
    // 0x80024D18: lbu         $t6, 0xB5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB5);
    // 0x80024D1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D20: sb          $t6, -0x4F1E($at)
    MEM_B(-0X4F1E, ctx->r1) = ctx->r14;
    // 0x80024D24: lbu         $t7, 0xB6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB6);
    // 0x80024D28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024D2C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024D30: jal         0x80025510
    // 0x80024D34: sb          $t7, -0x4F1D($at)
    MEM_B(-0X4F1D, ctx->r1) = ctx->r15;
    void_init(rdram, ctx);
        goto after_21;
    // 0x80024D34: sb          $t7, -0x4F1D($at)
    MEM_B(-0X4F1D, ctx->r1) = ctx->r15;
    after_21:
    // 0x80024D38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80024D3C:
    // 0x80024D3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80024D40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80024D44: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D48: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80024D4C: jr          $ra
    // 0x80024D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80024D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mtxf_from_inverse_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE74: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006FE78: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8006FE7C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8006FE80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006FE84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FE88: jal         0x80070830
    // 0x8006FE8C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x8006FE8C: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x8006FE90: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006FE94: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8006FE98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006FE9C: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006FEA0: jal         0x8007082C
    // 0x8006FEA4: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8006FEA4: nop

    after_1:
    // 0x8006FEA8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006FEAC: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEB0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8006FEB4: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006FEB8: jal         0x80070830
    // 0x8006FEBC: nop

    sins_s16(rdram, ctx);
        goto after_2;
    // 0x8006FEBC: nop

    after_2:
    // 0x8006FEC0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8006FEC4: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEC8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006FECC: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FED0: jal         0x8007082C
    // 0x8006FED4: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8006FED4: nop

    after_3:
    // 0x8006FED8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8006FEDC: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEE0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006FEE4: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8006FEE8: jal         0x80070830
    // 0x8006FEEC: nop

    sins_s16(rdram, ctx);
        goto after_4;
    // 0x8006FEEC: nop

    after_4:
    // 0x8006FEF0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8006FEF4: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEF8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006FEFC: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8006FF00: jal         0x8007082C
    // 0x8006FF04: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x8006FF04: nop

    after_5:
    // 0x8006FF08: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006FF0C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8006FF10: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x8006FF14: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FF18: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8006FF1C: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x8006FF20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006FF24: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006FF28: nop

    // 0x8006FF2C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006FF30: nop

    // 0x8006FF34: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8006FF38: nop

    // 0x8006FF3C: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FF40: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8006FF44: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF48: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006FF4C: nop

    // 0x8006FF50: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8006FF54: nop

    // 0x8006FF58: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8006FF5C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FF60: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF64: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006FF68: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8006FF6C: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF70: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006FF74: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8006FF78: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF7C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8006FF80: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF84: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006FF88: nop

    // 0x8006FF8C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8006FF90: nop

    // 0x8006FF94: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8006FF98: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FF9C: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFA0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006FFA4: nop

    // 0x8006FFA8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8006FFAC: nop

    // 0x8006FFB0: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006FFB4: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8006FFB8: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8006FFBC: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFC0: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8006FFC4: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFC8: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006FFCC: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8006FFD0: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8006FFD4: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006FFD8: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8006FFDC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8006FFE0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FFE4: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8006FFE8: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006FFEC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FFF0: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8006FFF4: swc1        $f16, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFF8: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006FFFC: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80070000: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070004: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070008: lwc1        $f18, 0x24($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X24);
    // 0x8007000C: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070010: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070014: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80070018: swc1        $f16, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f16.u32l;
    // 0x8007001C: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80070020: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80070024: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80070028: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007002C: lwc1        $f18, 0x28($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80070030: mul.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070034: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070038: swc1        $f16, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f16.u32l;
    // 0x8007003C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80070040: nop

    // 0x80070044: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80070048: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007004C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070050: jr          $ra
    // 0x80070054: nop

    return;
    // 0x80070054: nop

;}
RECOMP_FUNC void track_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC30: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8002CC34: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002CC38: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8002CC3C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8002CC40: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8002CC44: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8002CC48: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8002CC4C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8002CC50: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8002CC54: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8002CC58: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8002CC5C: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002CC60: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002CC64: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002CC68: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002CC6C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002CC70: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002CC74: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002CC78: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002CC7C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002CC80: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002CC84: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002CC88: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002CC8C: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CC90: lh          $a1, 0x20($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X20);
    // 0x8002CC94: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002CC98: blez        $a1, L_8002CF18
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CC9C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002CF18;
    }
    // 0x8002CC9C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002CCA0: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CCA4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_8002CCA8:
    // 0x8002CCA8: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x8002CCAC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8002CCB0: nop

    // 0x8002CCB4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CCB8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CCBC: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8002CCC0: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CCC4: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002CCC8: beq         $at, $zero, L_8002CEF8
    if (ctx->r1 == 0) {
        // 0x8002CCCC: sw          $t8, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r24;
            goto L_8002CEF8;
    }
    // 0x8002CCCC: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x8002CCD0: sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3 << 4);
    // 0x8002CCD4: sll         $s0, $t8, 4
    ctx->r16 = S32(ctx->r24 << 4);
L_8002CCD8:
    // 0x8002CCD8: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8002CCDC: nop

    // 0x8002CCE0: addu        $v1, $t2, $a1
    ctx->r3 = ADD32(ctx->r10, ctx->r5);
    // 0x8002CCE4: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8002CCE8: nop

    // 0x8002CCEC: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x8002CCF0: bne         $t4, $zero, L_8002CEE0
    if (ctx->r12 != 0) {
        // 0x8002CCF4: nop
    
            goto L_8002CEE0;
    }
    // 0x8002CCF4: nop

    // 0x8002CCF8: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x8002CCFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD00: addu        $t6, $t5, $fp
    ctx->r14 = ADD32(ctx->r13, ctx->r30);
    // 0x8002CD04: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD08: mflo        $t7
    ctx->r15 = lo;
    // 0x8002CD0C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x8002CD10: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x8002CD14: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD18: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8002CD1C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CD24: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002CD28: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002CD2C: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x8002CD30: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x8002CD34: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x8002CD38: addu        $t4, $t3, $fp
    ctx->r12 = ADD32(ctx->r11, ctx->r30);
    // 0x8002CD3C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD40: addu        $t2, $t9, $fp
    ctx->r10 = ADD32(ctx->r25, ctx->r30);
    // 0x8002CD44: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CD48: lwc1        $f26, 0xBC($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CD4C: cvt.s.w     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    ctx->f28.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CD50: mflo        $t5
    ctx->r13 = lo;
    // 0x8002CD54: addu        $v0, $t5, $a0
    ctx->r2 = ADD32(ctx->r13, ctx->r4);
    // 0x8002CD58: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD5C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002CD60: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD64: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8002CD68: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002CD6C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002CD70: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8002CD74: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CD78: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002CD7C: mflo        $t3
    ctx->r11 = lo;
    // 0x8002CD80: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8002CD84: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8002CD88: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8002CD8C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002CD90: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002CD94: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002CD98: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8002CD9C: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    // 0x8002CDA0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDA4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8002CDA8: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002CDAC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002CDB0: mul.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8002CDB4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002CDB8: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x8002CDBC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8002CDC0: sub.s       $f4, $f26, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x8002CDC4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002CDC8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002CDCC: sub.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002CDD0: mul.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8002CDD4: add.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002CDD8: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x8002CDDC: sub.s       $f8, $f16, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002CDE0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8002CDE4: sub.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002CDE8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CDEC: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002CDF0: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002CDF4: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8002CDF8: add.s       $f22, $f6, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002CDFC: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
    // 0x8002CE00: sub.s       $f6, $f18, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002CE04: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002CE08: sub.s       $f6, $f30, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002CE0C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8002CE10: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002CE14: nop

    // 0x8002CE18: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002CE1C: add.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CE20: swc1        $f24, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f24.u32l;
    // 0x8002CE24: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002CE28: nop

    // 0x8002CE2C: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002CE30: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002CE34: jal         0x800C9AD0
    // 0x8002CE38: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002CE38: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8002CE3C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CE40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CE44: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002CE48: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002CE4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CE50: bc1f        L_8002CE78
    if (!c1cs) {
        // 0x8002CE54: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8002CE78;
    }
    // 0x8002CE54: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002CE58: nop

    // 0x8002CE5C: div.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002CE60: nop

    // 0x8002CE64: div.s       $f12, $f22, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002CE68: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    // 0x8002CE6C: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8002CE70: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x8002CE74: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
L_8002CE78:
    // 0x8002CE78: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002CE7C: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CE80: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8002CE84: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002CE88: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002CE8C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8002CE90: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x8002CE94: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x8002CE98: mul.s       $f10, $f28, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f14.fl);
    // 0x8002CE9C: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x8002CEA0: swc1        $f12, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f12.u32l;
    // 0x8002CEA4: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEA8: mul.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f12.fl);
    // 0x8002CEAC: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8002CEB0: swc1        $f2, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f2.u32l;
    // 0x8002CEB4: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002CEB8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002CEBC: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x8002CEC0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8002CEC4: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8002CEC8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002CECC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002CED0: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8002CED4: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x8002CED8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8002CEDC: nop

L_8002CEE0:
    // 0x8002CEE0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002CEE4: slt         $at, $a1, $s0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002CEE8: bne         $at, $zero, L_8002CCD8
    if (ctx->r1 != 0) {
        // 0x8002CEEC: nop
    
            goto L_8002CCD8;
    }
    // 0x8002CEEC: nop

    // 0x8002CEF0: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002CEF4: nop

L_8002CEF8:
    // 0x8002CEF8: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x8002CEFC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF00: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002CF04: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002CF08: addiu       $t3, $t2, 0xC
    ctx->r11 = ADD32(ctx->r10, 0XC);
    // 0x8002CF0C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x8002CF10: bne         $at, $zero, L_8002CCA8
    if (ctx->r1 != 0) {
        // 0x8002CF14: sw          $t9, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r25;
            goto L_8002CCA8;
    }
    // 0x8002CF14: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
L_8002CF18:
    // 0x8002CF18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002CF1C: lw          $t4, -0x4F08($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F08);
    // 0x8002CF20: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002CF24: beq         $t4, $zero, L_8002CF34
    if (ctx->r12 == 0) {
        // 0x8002CF28: or          $t1, $s4, $zero
        ctx->r9 = ctx->r20 | 0;
            goto L_8002CF34;
    }
    // 0x8002CF28: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8002CF2C: b           L_8002D2AC
    // 0x8002CF30: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
        goto L_8002D2AC;
    // 0x8002CF30: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002CF34:
    // 0x8002CF34: blez        $a1, L_8002D2A8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002CF38: sw          $zero, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = 0;
            goto L_8002D2A8;
    }
    // 0x8002CF38: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x8002CF3C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8002CF40: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_8002CF44:
    // 0x8002CF44: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x8002CF48: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002CF4C: nop

    // 0x8002CF50: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8002CF54: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002CF58: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8002CF5C: lh          $fp, 0x2($v0)
    ctx->r30 = MEM_H(ctx->r2, 0X2);
    // 0x8002CF60: sw          $t7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r15;
    // 0x8002CF64: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8002CF68: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CF6C: andi        $t2, $t8, 0x200
    ctx->r10 = ctx->r24 & 0X200;
    // 0x8002CF70: beq         $t2, $zero, L_8002CF80
    if (ctx->r10 == 0) {
        // 0x8002CF74: slt         $at, $v1, $t3
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_8002CF80;
    }
    // 0x8002CF74: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002CF78: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002CF7C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
L_8002CF80:
    // 0x8002CF80: beq         $at, $zero, L_8002D288
    if (ctx->r1 == 0) {
        // 0x8002CF84: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_8002D288;
    }
    // 0x8002CF84: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x8002CF88: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
L_8002CF8C:
    // 0x8002CF8C: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002CF90: nop

    // 0x8002CF94: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x8002CF98: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8002CF9C: nop

    // 0x8002CFA0: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x8002CFA4: bne         $t6, $zero, L_8002D274
    if (ctx->r14 != 0) {
        // 0x8002CFA8: lw          $t9, 0xF4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XF4);
            goto L_8002D274;
    }
    // 0x8002CFA8: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x8002CFAC: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002CFB0: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002CFB4: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002CFB8: lhu         $s1, 0x0($t2)
    ctx->r17 = MEM_HU(ctx->r10, 0X0);
    // 0x8002CFBC: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x8002CFC0: sll         $t4, $s1, 4
    ctx->r12 = S32(ctx->r17 << 4);
    // 0x8002CFC4: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8002CFC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002CFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002CFD0: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x8002CFD4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002CFD8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002CFDC: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x8002CFE0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002CFE4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8002CFE8: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
L_8002CFEC:
    // 0x8002CFEC: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002CFF0: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x8002CFF4: addiu       $s6, $v0, 0x1
    ctx->r22 = ADD32(ctx->r2, 0X1);
    // 0x8002CFF8: sll         $t6, $s7, 4
    ctx->r14 = S32(ctx->r23 << 4);
    // 0x8002CFFC: sll         $t8, $s7, 3
    ctx->r24 = S32(ctx->r23 << 3);
    // 0x8002D000: slti        $at, $s6, 0x3
    ctx->r1 = SIGNED(ctx->r22) < 0X3 ? 1 : 0;
    // 0x8002D004: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8002D008: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D00C: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8002D010: addu        $a3, $t2, $s5
    ctx->r7 = ADD32(ctx->r10, ctx->r21);
    // 0x8002D014: bne         $at, $zero, L_8002D020
    if (ctx->r1 != 0) {
        // 0x8002D018: addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
            goto L_8002D020;
    }
    // 0x8002D018: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x8002D01C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002D020:
    // 0x8002D020: addu        $t3, $v1, $s0
    ctx->r11 = ADD32(ctx->r3, ctx->r16);
    // 0x8002D024: lhu         $s0, 0x2($a3)
    ctx->r16 = MEM_HU(ctx->r7, 0X2);
    // 0x8002D028: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002D02C: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8002D030: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002D034: addu        $a1, $t9, $fp
    ctx->r5 = ADD32(ctx->r25, ctx->r30);
    // 0x8002D038: beq         $at, $zero, L_8002D258
    if (ctx->r1 == 0) {
        // 0x8002D03C: addu        $a2, $t4, $fp
        ctx->r6 = ADD32(ctx->r12, ctx->r30);
            goto L_8002D258;
    }
    // 0x8002D03C: addu        $a2, $t4, $fp
    ctx->r6 = ADD32(ctx->r12, ctx->r30);
    // 0x8002D040: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D044: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D048: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002D04C: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x8002D050: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002D054: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002D058: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8002D05C: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D060: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002D064: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002D068: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002D06C: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D070: mflo        $t8
    ctx->r24 = lo;
    // 0x8002D074: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x8002D078: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8002D07C: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D080: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002D084: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002D088: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D08C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8002D090: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x8002D094: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002D098: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8002D09C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002D0A0: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x8002D0A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002D0A8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002D0AC: mflo        $t4
    ctx->r12 = lo;
    // 0x8002D0B0: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x8002D0B4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8002D0B8: cvt.s.w     $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    ctx->f28.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D0BC: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8002D0C0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002D0C4: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D0C8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8002D0CC: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
    // 0x8002D0D0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002D0D4: cvt.s.w     $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    ctx->f30.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D0D8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8002D0DC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D0E0: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D0E4: add.s       $f16, $f4, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8002D0E8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D0EC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002D0F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D0F4: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002D0F8: mul.s       $f6, $f26, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8002D0FC: add.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x8002D100: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D104: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002D108: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8002D10C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002D110: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8002D114: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D118: sub.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8002D11C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8002D120: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002D124: add.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002D128: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002D12C: sub.s       $f10, $f16, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002D130: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002D134: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002D138: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D13C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002D140: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002D144: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8002D148: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002D14C: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002D150: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002D154: sub.s       $f4, $f30, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002D158: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002D15C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8002D160: nop

    // 0x8002D164: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002D168: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D16C: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002D170: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x8002D174: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002D178: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002D17C: jal         0x800C9AD0
    // 0x8002D180: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D180: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8002D184: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002D188: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002D18C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8002D190: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8002D194: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8002D198: bc1f        L_8002D1B8
    if (!c1cs) {
        // 0x8002D19C: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_8002D1B8;
    }
    // 0x8002D19C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8002D1A0: nop

    // 0x8002D1A4: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8002D1A8: nop

    // 0x8002D1AC: div.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002D1B0: nop

    // 0x8002D1B4: div.s       $f26, $f24, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
L_8002D1B8:
    // 0x8002D1B8: beq         $s0, $s1, L_8002D1F0
    if (ctx->r16 == ctx->r17) {
        // 0x8002D1BC: sll         $t5, $s7, 3
        ctx->r13 = S32(ctx->r23 << 3);
            goto L_8002D1F0;
    }
    // 0x8002D1BC: sll         $t5, $s7, 3
    ctx->r13 = S32(ctx->r23 << 3);
    // 0x8002D1C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002D1C4:
    // 0x8002D1C4: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002D1C8: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x8002D1CC: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D1D0: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8002D1D4: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x8002D1D8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002D1DC: bne         $s1, $t3, L_8002D1E8
    if (ctx->r17 != ctx->r11) {
        // 0x8002D1E0: ori         $t4, $s4, 0x8000
        ctx->r12 = ctx->r20 | 0X8000;
            goto L_8002D1E8;
    }
    // 0x8002D1E0: ori         $t4, $s4, 0x8000
    ctx->r12 = ctx->r20 | 0X8000;
    // 0x8002D1E4: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_8002D1E8:
    // 0x8002D1E8: bne         $v0, $s3, L_8002D1C4
    if (ctx->r2 != ctx->r19) {
        // 0x8002D1EC: nop
    
            goto L_8002D1C4;
    }
    // 0x8002D1EC: nop

L_8002D1F0:
    // 0x8002D1F0: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x8002D1F4: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002D1F8: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D1FC: addu        $t8, $t7, $s5
    ctx->r24 = ADD32(ctx->r15, ctx->r21);
    // 0x8002D200: sh          $s4, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r20;
    // 0x8002D204: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x8002D208: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x8002D20C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8002D210: swc1        $f20, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f20.u32l;
    // 0x8002D214: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8002D218: mul.s       $f8, $f28, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8002D21C: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8002D220: swc1        $f22, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f22.u32l;
    // 0x8002D224: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8002D228: mul.s       $f10, $f30, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x8002D22C: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x8002D230: swc1        $f26, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f26.u32l;
    // 0x8002D234: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002D238: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D23C: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x8002D240: mul.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8002D244: addu        $t2, $t8, $t2
    ctx->r10 = ADD32(ctx->r24, ctx->r10);
    // 0x8002D248: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002D24C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002D250: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002D254: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
L_8002D258:
    // 0x8002D258: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002D25C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8002D260: bne         $s6, $at, L_8002CFEC
    if (ctx->r22 != ctx->r1) {
        // 0x8002D264: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8002CFEC;
    }
    // 0x8002D264: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8002D268: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8002D26C: nop

    // 0x8002D270: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
L_8002D274:
    // 0x8002D274: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002D278: bne         $s7, $t9, L_8002CF8C
    if (ctx->r23 != ctx->r25) {
        // 0x8002D27C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002CF8C;
    }
    // 0x8002D27C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002D280: lh          $a1, 0x20($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X20);
    // 0x8002D284: nop

L_8002D288:
    // 0x8002D288: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8002D28C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8002D290: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002D294: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002D298: addiu       $t5, $t6, 0xC
    ctx->r13 = ADD32(ctx->r14, 0XC);
    // 0x8002D29C: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8002D2A0: bne         $at, $zero, L_8002CF44
    if (ctx->r1 != 0) {
        // 0x8002D2A4: sw          $t4, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r12;
            goto L_8002CF44;
    }
    // 0x8002D2A4: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
L_8002D2A8:
    // 0x8002D2A8: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
L_8002D2AC:
    // 0x8002D2AC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002D2B0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002D2B4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2B8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002D2BC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D2C0: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002D2C4: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002D2C8: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002D2CC: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002D2D0: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002D2D4: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002D2D8: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002D2DC: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002D2E0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8002D2E4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D2E8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8002D2EC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8002D2F0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8002D2F4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8002D2F8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8002D2FC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8002D300: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8002D304: jr          $ra
    // 0x8002D308: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8002D308: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
